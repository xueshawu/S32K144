/*
 * @Description: Can Interface File
 * @Version: 1.0
 * @Autor: Archie
 * @Date: 2020-05-23 09:23:01
 * @LastEditors: Archie
 * @LastEditTime: 2020-06-07 11:39:09
 */ 

/* ============================ [ INCLUDES  ] ====================================================== */
#include "CanIf.h"
#include "Can.h"
#include "CanIf_Cbk.h"
#include <string.h>
#if defined(USE_DET)
#include "Det.h"
#endif

#ifdef USE_PDUR
#include "PduR.h"
#endif

#if defined(USE_CANTP)
#include "CanTp_Cbk.h"
#endif

#if defined(USE_J1939TP)
#include "J1939Tp_Cbk.h"
#endif

#if defined(USE_CANNM)
#include "CanNm.h"
#endif
#if defined(USE_XCP)
#include "Xcp.h"
#include "XcpOnCan_Cbk.h"
#endif

#include "ringbuffer.h"
/* ============================ [ MACROS    ] ====================================================== */
#define AS_LOG_CANIF  0
#define AS_LOG_CANIFE 1

#if  ( CANIF_DEV_ERROR_DETECT == STD_ON )
#define VALIDATE(_exp,_api,_err ) \
        if( !(_exp) ) { \
          Det_ReportError(MODULE_ID_CANIF, 0, _api, _err); \
          return E_NOT_OK; \
        }

#define VALIDATE_NO_RV(_exp,_api,_err ) \
  if( !(_exp) ) { \
          Det_ReportError(MODULE_ID_CANIF, 0, _api, _err); \
          return; \
        }

#define DET_REPORTERROR(_x,_y,_z,_q) Det_ReportError(_x, _y, _z, _q)

#else
#define VALIDATE(_exp,_api,_err )
#define VALIDATE_NO_RV(_exp,_api,_err )
#define DET_REPORTERROR(_x,_y,_z,_q)
#endif


// Helper to get the Can Controller refered to by a CanIf Channel
#define ARC_GET_CHANNEL_CONTROLLER(_channel) \
	CanIf_ConfigPtr->Arc_ChannelToControllerMap[_channel]

/* ============================ [ TYPES     ] ====================================================== */
/* Global configure */
static const CanIf_ConfigType *CanIf_ConfigPtr;

/* Struct of controller private data. */
typedef struct
{
  CanIf_ControllerModeType  ControllerMode;
  CanIf_ChannelGetModeType  PduMode;
} CanIf_ChannelPrivateType;

typedef struct {
    uint32_t 			canid;
    uint16_t      hrh;
    uint8_t 			data[CAN_LL_DL];
    uint8_t				dlc;
} CanIf_PduType;

typedef struct 
{
  boolean initRun;
  CanIf_ChannelPrivateType channelData[CANIF_CHANNEL_CNT];
} CanIf_GlobalType;

/* ============================ [ DECLARES  ] ====================================================== */
void CanIf_PreInit_InitController(uint8 Controller, uint8 ConfigurationIndex);
/* ============================ [ DATAS     ] ====================================================== */
static CanIf_GlobalType CanIf_Global;


/* ============================ [ LOCALS    ] ====================================================== */
static CanIf_Arc_ChannelIdType CanIf_Arc_FindHrhChannel( Can_Arc_HRHType hrh )
{
  const CanIf_InitHohConfigType *hohConfig;
  const CanIf_HrhConfigType *hrhConfig;

  /* foreach(hoh){ foreach(hrh in hoh) {} } */
  hohConfig = CanIf_ConfigPtr->InitConfig->CanIfHohConfigPtr;
  hohConfig--;
  do
  {
    hohConfig++;

    hrhConfig = hohConfig->CanIfHrhConfig;
    hrhConfig--;
    do
    {
      hrhConfig++;
      if (hrhConfig->CanIfHrhIdSymRef == hrh){
        return hrhConfig->CanIfCanControllerHrhIdRef;
      }
    } while(!hrhConfig->CanIf_Arc_EOL);
  } while(!hohConfig->CanIf_Arc_EOL);

  DET_REPORTERROR(MODULE_ID_CANIF, 0, CANIF_RXINDICATION_ID, CANIF_E_PARAM_HRH);

  return (CanIf_Arc_ChannelIdType) -1;
}

static void scheduleTxConfirmation(PduIdType canTxPduId)
{
	const CanIf_TxPduConfigType* entry;
	if(canTxPduId < CanIf_ConfigPtr->InitConfig->CanIfNumberOfCanTXPduIds)
	{
		entry = &CanIf_ConfigPtr->InitConfig->CanIfTxPduConfigPtr[canTxPduId];

		if (entry->CanIfUserTxConfirmation != NULL)
		{
			CanIf_ChannelGetModeType mode;
			CanIf_GetPduMode(entry->CanIfCanTxPduHthRef->CanIfCanControllerIdRef, &mode);
			if ( (mode == CANIF_GET_TX_ONLINE) ||
				 (mode == CANIF_GET_ONLINE) ||
				 (mode == CANIF_GET_OFFLINE_ACTIVE) ||
				 (mode == CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE) )
			{
				entry->CanIfUserTxConfirmation(entry->CanIfTxPduId);  /* CANIF053 */
			}
		}
	}
	else
	{
		asAssert(0); /* impossible case */
	}
}

static void scheduleRxIndication(uint16 Hrh, Can_IdType CanId, uint8 CanDlc,
		const uint8 *CanSduPtr) {
	/* Check PDU mode before continue processing */
	CanIf_ChannelGetModeType mode;
	CanIf_Arc_ChannelIdType channel = CanIf_Arc_FindHrhChannel((Can_Arc_HRHType) Hrh);
	const CanIf_RxPduConfigType *entry = CanIf_ConfigPtr->InitConfig->CanIfRxPduConfigPtr;
	uint16 i;
	if (channel == -1)  // Invalid HRH
	{
		return;
	}

	if (CanIf_GetPduMode(channel, &mode) == E_OK) {
		if ((mode == CANIF_GET_OFFLINE) || (mode == CANIF_GET_TX_ONLINE)
				|| (mode == CANIF_GET_OFFLINE_ACTIVE)) {
// Receiver path is disabled so just drop it
			return;
		}
	} else {
		return;  // No mode so just return
	}

	/* Find the CAN id in the RxPduList */
	for (i = 0;
			i < CanIf_ConfigPtr->InitConfig->CanIfNumberOfCanRxPduIds; i++) {
		if (entry->CanIfCanRxPduHrhRef->CanIfHrhIdSymRef == Hrh) {
			// Software filtering
			if (entry->CanIfCanRxPduHrhRef->CanIfHrhType
					== CAN_ARC_HANDLE_TYPE_BASIC) {
				if (entry->CanIfCanRxPduHrhRef->CanIfSoftwareFilterHrh) {
					if (entry->CanIfSoftwareFilterType
							== CANIF_SOFTFILTER_TYPE_MASK) {
						if ((CanId & entry->CanIfCanRxPduCanIdMask)
								== (entry->CanIfCanRxPduCanId
										& entry->CanIfCanRxPduCanIdMask)) {
								// We found a pdu so call higher layers
						} else {
							entry++;
							continue; // Go to next entry
						}
					} else {
						DET_REPORTERROR(MODULE_ID_CAN, 0, CANIF_RXINDICATION_ID,
								CANIF_E_PARAM_HRH);
						continue; // Not a supported filter type, so just drop the frame
					}
				}
			}

#if (CANIF_DLC_CHECK == STD_ON)
			if (CanDlc < entry->CanIfCanRxPduDlc) {
				VALIDATE_NO_RV(FALSE, CANIF_RXINDICATION_ID, CANIF_E_PARAM_DLC);
				return;
			}
#endif

			switch (entry->CanIfRxUserType) {
			case CANIF_USER_TYPE_CAN_SPECIAL:
			{
				((CanIf_FuncTypeCanSpecial) (entry->CanIfUserRxIndication))(
						entry->CanIfCanRxPduHrhRef->CanIfCanControllerHrhIdRef,
						entry->CanIfCanRxPduId, CanSduPtr, CanDlc, CanId);
				return;
			}
			break;

			case CANIF_USER_TYPE_CAN_NM:
#if defined(USE_CANNM)
				CanNm_RxIndication(entry->CanIfCanRxPduId,CanSduPtr);
				return;
#endif
			break;

			case CANIF_USER_TYPE_CAN_PDUR:
#if defined(USE_PDUR) && (PDUR_CANIF_SUPPORT == STD_ON)
			{
				PduInfoType pduInfo;
				pduInfo.SduLength = CanDlc;
				pduInfo.SduDataPtr = (uint8 *)CanSduPtr;
				PduR_CanIfRxIndication(entry->CanIfCanRxPduId,&pduInfo);
				return;
			}
#endif
			break;

			case CANIF_USER_TYPE_CAN_TP:
#if defined(USE_CANTP)
			{
				PduInfoType CanTpRxPdu;
				CanTpRxPdu.SduLength = CanDlc;
				CanTpRxPdu.SduDataPtr = (uint8 *) CanSduPtr;
				CanTp_RxIndication(entry->CanIfCanRxPduId, &CanTpRxPdu);
				return;
			}
#endif
			break;
			case CANIF_USER_TYPE_XCP:
#if defined(USE_XCP)
			{
				PduInfoType CanTpRxPdu;
				CanTpRxPdu.SduLength = CanDlc;
				CanTpRxPdu.SduDataPtr = (uint8 *) CanSduPtr;
				Xcp_CanIfRxIndication(entry->CanIfCanRxPduId, &CanTpRxPdu);
				return;
			}
#endif
			break;
			case CANIF_USER_TYPE_J1939TP:
#if defined(USE_J1939TP)
			{
				PduInfoType J1939TpRxPdu;
				J1939TpRxPdu.SduLength = CanDlc;
				J1939TpRxPdu.SduDataPtr = (uint8 *)CanSduPtr;
				J1939Tp_RxIndication(entry->CanIfCanRxPduId, &J1939TpRxPdu);
				return;
			}
#endif
			break;
			}
		}
		entry++;
	}
}


/* ============================ [ FUNCTIONS ] ====================================================== */
void CanIf_Init(const CanIf_ConfigType *ConfigPtr)
{
  uint8 i;
  VALIDATE_NO_RV(ConfigPtr != 0, CANIF_INIT_ID, CANIF_E_PARAM_POINTER); /* Only PostBuild case supported */

  CanIf_ConfigPtr = ConfigPtr;

  for (i = 0; i < CANIF_CHANNEL_CNT; i++)
  {
    CanIf_Global.channelData[i].ControllerMode = CANIF_CS_STOPPED;
    CanIf_Global.channelData[i].PduMode = CANIF_GET_OFFLINE;
    CanIf_PreInit_InitController(i, CanIf_ConfigPtr->Arc_ChannelDefaultConfIndex[i]);
  }


  CanIf_Global.initRun = TRUE;

#if defined(USE_SHELL) && !defined(USE_SHELL_SYMTAB)
	SHELL_AddCmd(&canIfCmd);
#endif

	RB_INIT(canifRx);
	RB_INIT(canifTx);
}

/*
 * Controller :: CanIf_Arc_ChannelIdType (CanIf-specific id to abstract from Can driver/controllers)
 * ConfigurationIndex :: CanIf_Arc_ConfigurationIndexType
 */
void CanIf_InitController(uint8 Controller, uint8 ConfigurationIndex)
{
  /* We call this a CanIf channel. Hopefully makes it easier to follow. */
  CanIf_Arc_ChannelIdType channel = (CanIf_Arc_ChannelIdType) Controller;
  CanIf_ControllerModeType mode;
  const Can_ControllerConfigType *canConfig;
  const CanControllerIdType canControllerId = ARC_GET_CHANNEL_CONTROLLER(channel);

  VALIDATE_NO_RV(CanIf_Global.initRun, CANIF_INIT_CONTROLLER_ID, CANIF_E_UNINIT );
  VALIDATE_NO_RV(channel < CANIF_CHANNEL_CNT, CANIF_INIT_CONTROLLER_ID, CANIF_E_PARAM_CONTROLLER);
  VALIDATE_NO_RV(ConfigurationIndex < CANIF_CHANNEL_CONFIGURATION_CNT, CANIF_INIT_CONTROLLER_ID, CANIF_E_PARAM_POINTER);

  if (CanIf_GetControllerMode(channel, &mode) == E_OK)
  {
    if (mode == CANIF_CS_STARTED)
    {
      CanIf_SetControllerMode(channel, CANIF_CS_STOPPED); /* CANIF092 */
    }
    else if (mode != CANIF_CS_STOPPED)
    {
      VALIDATE_NO_RV(FALSE, CANIF_INIT_CONTROLLER_ID, CANIF_E_PARAM_CONTROLLER_MODE); /* CANIF092 */
    }
  }
  else
  {
    VALIDATE_NO_RV(FALSE, CANIF_INIT_CONTROLLER_ID, CANIF_E_PARAM_CONTROLLER_MODE);
  }

  /* CANIF293: ..Subsequently the CAN Interface calls the corresponding
   *             CAN Driver initialization services.
   *
   * CANIF066: The CAN Interface has access to the CAN Driver configuration data. All
   * public CAN Driver configuration data are described in [8] Specification of CAN Driver.
   *
   * Grab the configuration from the Can Controller
   */
  /* Validate that the configuration at the index match the right channel */
  VALIDATE_NO_RV(CanIf_ConfigPtr->ControllerConfig[ConfigurationIndex].CanIfControllerIdRef == channel, CANIF_INIT_CONTROLLER_ID, CANIF_E_PARAM_CONTROLLER);

  canConfig = CanIf_ConfigPtr->ControllerConfig[ConfigurationIndex].CanIfInitControllerRef;
#ifndef USE_ANYCAN /*not arccore CAN driver */
  /* Validate that the CanIfControllerConfig points to configuration for the right Can Controller */
  VALIDATE_NO_RV(canConfig->CanControllerId == canControllerId, CANIF_INIT_CONTROLLER_ID, CANIF_E_PARAM_CONTROLLER);
#endif
  Can_InitController(canControllerId, canConfig)

  /* Set mode to stopped */
  CanIf_SetControllerMode(channel, CANIF_CS_STOPPED);
}

void CanIf_PreInit_InitController(uint8 Controller, uint8 ConfigurationIndex){
	// We call this a CanIf channel. Hopefully makes it easier to follow.
	CanIf_Arc_ChannelIdType channel = (CanIf_Arc_ChannelIdType) Controller;
	const CanControllerIdType canControllerId = ARC_GET_CHANNEL_CONTROLLER(channel);
	const Can_ControllerConfigType *canConfig = CanIf_ConfigPtr->ControllerConfig[ConfigurationIndex].CanIfInitControllerRef;

	VALIDATE_NO_RV(channel < CANIF_CHANNEL_CNT, CANIF_INIT_ID, CANIF_E_PARAM_CONTROLLER);
	VALIDATE_NO_RV(ConfigurationIndex < CANIF_CHANNEL_CONFIGURATION_CNT, CANIF_INIT_ID, CANIF_E_PARAM_POINTER);


	// Validate that the configuration at the index match the right channel
	VALIDATE_NO_RV(CanIf_ConfigPtr->ControllerConfig[ConfigurationIndex].CanIfControllerIdRef == channel, CANIF_INIT_CONTROLLER_ID, CANIF_E_PARAM_CONTROLLER);
#ifndef USE_ANYCAN /*not arccore CAN driver */
	// Validate that the CanIfControllerConfig points to configuration for the right Can Controller
	VALIDATE_NO_RV(canConfig->CanControllerId == canControllerId, CANIF_INIT_CONTROLLER_ID, CANIF_E_PARAM_CONTROLLER);
#endif
	Can_InitController(canControllerId, canConfig);
}

//-------------------------------------------------------------------

Std_ReturnType CanIf_SetControllerMode(uint8 Controller,
    CanIf_ControllerModeType ControllerMode)
{
  // We call this a CanIf channel. Hopefully makes it easier to follow.
  CanIf_Arc_ChannelIdType channel = (CanIf_Arc_ChannelIdType) Controller;
  CanControllerIdType canControllerId = ARC_GET_CHANNEL_CONTROLLER(Controller);
  CanIf_ControllerModeType oldMode;

  VALIDATE( CanIf_Global.initRun, CANIF_SET_CONTROLLER_MODE_ID, CANIF_E_UNINIT );
  VALIDATE( channel < CANIF_CHANNEL_CNT, CANIF_SET_CONTROLLER_MODE_ID, CANIF_E_PARAM_CONTROLLER );

  oldMode = CanIf_Global.channelData[channel].ControllerMode;

  if (oldMode == CANIF_CS_UNINIT)
  {
    VALIDATE(FALSE, CANIF_SET_CONTROLLER_MODE_ID, CANIF_E_UNINIT); // See figure 32, 33
    return E_NOT_OK;
  }

  switch (ControllerMode)
  {
  case CANIF_CS_STARTED:   // Figure 32
  {
    switch (oldMode)
    {
      case CANIF_CS_SLEEP:
        if (Can_SetControllerMode(canControllerId, CAN_T_STOP) == CAN_NOT_OK){
          return E_NOT_OK;
        }
        CanIf_Global.channelData[channel].ControllerMode = CANIF_CS_STOPPED;
        break;
      default:
        // Just fall through
        break;
    }

    CanIf_SetPduMode(channel, CANIF_SET_ONLINE);
    if (Can_SetControllerMode(canControllerId, CAN_T_START) == CAN_NOT_OK){
      return E_NOT_OK;
    }
    CanIf_Global.channelData[channel].ControllerMode = CANIF_CS_STARTED;
  }
  break;

  case CANIF_CS_SLEEP: // Figure 33
  {
    switch (oldMode) {
      case CANIF_CS_STARTED:
        if (Can_SetControllerMode(canControllerId, CAN_T_STOP) == CAN_NOT_OK){
          return E_NOT_OK;
        }
        CanIf_Global.channelData[channel].ControllerMode = CANIF_CS_STOPPED;
        break;
      default:
        // Just fall through for other cases
        break;
    }

    if (Can_SetControllerMode(canControllerId, CAN_T_SLEEP) == CAN_NOT_OK){
      return E_NOT_OK;
    }
    CanIf_Global.channelData[channel].ControllerMode = CANIF_CS_SLEEP;
    break;
  }

  case CANIF_CS_STOPPED:
  {
    switch (oldMode)
    {
      case CANIF_CS_SLEEP:
        if (Can_SetControllerMode(canControllerId, CAN_T_WAKEUP) == CAN_NOT_OK){
          return E_NOT_OK;
        }
        break;
      default:
        // Just fall through for other cases
        break;
    }

    CanIf_SetPduMode(channel, CANIF_SET_OFFLINE);
    if (Can_SetControllerMode(canControllerId, CAN_T_STOP) == CAN_NOT_OK){
      return E_NOT_OK;
    }
    CanIf_Global.channelData[channel].ControllerMode = CANIF_CS_STOPPED;
    break;
  }

  case CANIF_CS_UNINIT:
    // Just fall through
    break;
  }
  return E_OK;
}

//-------------------------------------------------------------------

Std_ReturnType CanIf_GetControllerMode(uint8 Controller,
    CanIf_ControllerModeType *ControllerModePtr)
{
  // We call this a CanIf channel. Hopefully makes it easier to follow.
  CanIf_Arc_ChannelIdType channel = (CanIf_Arc_ChannelIdType) Controller;

  VALIDATE(CanIf_Global.initRun, CANIF_GET_CONTROLLER_MODE_ID, CANIF_E_UNINIT );
  VALIDATE(channel < CANIF_CHANNEL_CNT, CANIF_GET_CONTROLLER_MODE_ID, CANIF_E_PARAM_CONTROLLER );
  VALIDATE(ControllerModePtr != NULL, CANIF_GET_CONTROLLER_MODE_ID, CANIF_E_PARAM_POINTER );

  *ControllerModePtr = CanIf_Global.channelData[channel].ControllerMode;

  return E_OK;
}

//-------------------------------------------------------------------
/**
 * Matches a Tx PDU id agaist the ones that are in the database.
 *
 * @returns Ptr a TxPdu
 */
#if ( CANIF_ARC_RUNTIME_PDU_CONFIGURATION == STD_ON )
CanIf_TxPduConfigType * CanIf_FindTxPduEntry(PduIdType id)
#else
static const CanIf_TxPduConfigType * CanIf_FindTxPduEntry(PduIdType id)
#endif
{
	if (id >= CanIf_ConfigPtr->InitConfig->CanIfNumberOfCanTXPduIds) {
		return NULL;
	} else {
		return &CanIf_ConfigPtr->InitConfig->CanIfTxPduConfigPtr[id];
	}
}


#if ( CANIF_ARC_RUNTIME_PDU_CONFIGURATION == STD_ON )
CanIf_RxPduConfigType * CanIf_FindRxPduEntry(PduIdType id) {
	if (id >= CanIf_ConfigPtr->InitConfig->CanIfNumberOfCanRxPduIds) {
		return NULL;
	} else {
		return &CanIf_ConfigPtr->InitConfig->CanIfRxPduConfigPtr[id];
	}
}

const CanIf_HrhConfigType* CanIf_Arc_GetReceiveHandler(CanIf_Arc_ChannelIdType Channel) {
  const CanIf_InitHohConfigType *hohConfig;
  const CanIf_HrhConfigType *hrhConfig;

  // foreach(hoh){ foreach(hrh in hoh) {} }
  hohConfig = CanIf_ConfigPtr->InitConfig->CanIfHohConfigPtr;
  hohConfig--;
  do
  {
	hohConfig++;

	hrhConfig = hohConfig->CanIfHrhConfig;
    hrhConfig--;
    do
    {
      hrhConfig++;
      if (hrhConfig->CanIfCanControllerHrhIdRef == Channel)
        return hrhConfig;
	} while(!hrhConfig->CanIf_Arc_EOL);

  } while(!hohConfig->CanIf_Arc_EOL);

  DET_REPORTERROR(MODULE_ID_CANIF, 0, 0xFF, CANIF_E_PARAM_HRH);

  return NULL;
}

const CanIf_HthConfigType* CanIf_Arc_GetTransmitHandler(CanIf_Arc_ChannelIdType Channel) {
  const CanIf_InitHohConfigType *hohConfig;
  const CanIf_HthConfigType *hthConfig;

  // foreach(hoh){ foreach(hrh in hoh) {} }
  hohConfig = CanIf_ConfigPtr->InitConfig->CanIfHohConfigPtr;
  hohConfig--;
  do
  {
	hohConfig++;

	hthConfig = hohConfig->CanIfHthConfig;
	hthConfig--;
    do
    {
    	hthConfig++;
      if (hthConfig->CanIfCanControllerIdRef == Channel)
        return hthConfig;
	} while(!hthConfig->CanIf_Arc_EOL);

  } while(!hohConfig->CanIf_Arc_EOL);

  DET_REPORTERROR(MODULE_ID_CANIF, 0, 0xFF, CANIF_E_PARAM_HTH);

  return NULL;
}
#endif

//-------------------------------------------------------------------

Std_ReturnType CanIf_Transmit(PduIdType CanTxPduId,
    const PduInfoType *PduInfoPtr)
{
  Can_PduType canPdu;
  const CanIf_TxPduConfigType *txEntry;
  CanIf_ControllerModeType csMode;
  CanIf_ChannelGetModeType pduMode;
  CanIf_Arc_ChannelIdType channel;
  Can_ReturnType rVal;

  VALIDATE(CanIf_Global.initRun, CANIF_TRANSMIT_ID, CANIF_E_UNINIT );
  VALIDATE((PduInfoPtr != 0), CANIF_TRANSMIT_ID, CANIF_E_PARAM_POINTER );

  // Get the controller from L-PDU handle
  txEntry = CanIf_FindTxPduEntry(CanTxPduId);

  if (txEntry == 0)
  {
    VALIDATE(FALSE, CANIF_TRANSMIT_ID, CANIF_E_INVALID_TXPDUID);
    return E_NOT_OK;
  }

  channel = txEntry->CanIfCanTxPduHthRef->CanIfCanControllerIdRef;

  // Get and verify the controller mode
  if (CanIf_GetControllerMode(channel, &csMode) == E_NOT_OK){
    return E_NOT_OK;
  }

  if (csMode != CANIF_CS_STARTED){  // CANIF_161
    return E_NOT_OK;
  }

  // Get and verify the PDU channel mode control
  if (CanIf_GetPduMode(channel, &pduMode) == E_NOT_OK){
    return E_NOT_OK;
  }

  if ((pduMode != CANIF_GET_TX_ONLINE) && (pduMode != CANIF_GET_ONLINE)){
    return E_NOT_OK;
  }

  canPdu.id = txEntry->CanIfCanTxPduIdCanId;

  canPdu.length = PduInfoPtr->SduLength;
  canPdu.sdu = PduInfoPtr->SduDataPtr;
  canPdu.swPduHandle = CanTxPduId;

  rVal = Can_Write(txEntry->CanIfCanTxPduHthRef->CanIfHthIdSymRef, &canPdu);

  if (rVal == CAN_NOT_OK){
    return E_NOT_OK;
  }

  if (rVal == CAN_BUSY)  // CANIF 082, CANIF 161
  {
    // Tx buffering not supported so just return.
    return E_NOT_OK;
  }

  return E_OK;
}

//-------------------------------------------------------------------

#if ( CANIF_READRXPDU_DATA_API == STD_ON )
Std_ReturnType CanIf_ReadRxPduData(PduIdType CanRxPduId,
    PduInfoType *PduInfoPtr)
{
  VALIDATE(FALSE, CANIF_READTXPDUDATA_ID, CANIF_E_NOK_NOSUPPORT);
  VALIDATE(CanIf_Global.initRun == STD_ON, CANIF_READTXPDUDATA_ID, CANIF_E_UNINIT );
  VALIDATE(PduInfoPtr != 0, CANIF_READTXPDUDATA_ID, CANIF_E_PARAM_POINTER );

  // This function is not supported

  return E_NOT_OK;
}
#endif

//-------------------------------------------------------------------

#if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )
CanIf_NotifStatusType CanIf_ReadTxNotifStatus(PduIdType CanTxPduId)
{
  const CanIf_TxPduConfigType *txEntry;
  VALIDATE(FALSE, CANIF_READTXNOTIFSTATUS_ID, CANIF_E_NOK_NOSUPPORT);
  VALIDATE(CanIf_Global.initRun, CANIF_READTXNOTIFSTATUS_ID, CANIF_E_UNINIT );

  // Get the controller from L-PDU handle
  txEntry = CanIf_FindTxPduEntry(CanTxPduId);

  if (txEntry == 0)
  {
    VALIDATE(FALSE, CANIF_READTXNOTIFSTATUS_ID, CANIF_E_INVALID_TXPDUID);
    return CANIF_NO_NOTIFICATION;
  }

  if (txEntry->CanIfReadTxPduNotifyStatus == FALSE)
  {
    VALIDATE(FALSE, CANIF_READTXNOTIFSTATUS_ID, CANIF_E_INVALID_TXPDUID);
    return CANIF_NO_NOTIFICATION;
  }

  // This function is not supported

  return CANIF_NO_NOTIFICATION;
}
#endif

//-------------------------------------------------------------------

#if ( CANIF_READRXPDU_NOTIFY_STATUS_API == STD_ON )
CanIf_NotifStatusType CanIf_ReadRxNotifStatus(PduIdType CanRxPduId)
{
  VALIDATE(FALSE, CANIF_READRXNOTIFSTATUS_ID, CANIF_E_NOK_NOSUPPORT);
  VALIDATE(CanIf_Global.initRun, CANIF_READRXNOTIFSTATUS_ID, CANIF_E_UNINIT );

  return CANIF_NO_NOTIFICATION;
}
#endif

//-------------------------------------------------------------------

Std_ReturnType CanIf_SetPduMode(uint8 Controller,
    CanIf_ChannelSetModeType PduModeRequest)
{
  // We call this a CanIf channel. Hopefully makes it easier to follow.
  CanIf_Arc_ChannelIdType channel = (CanIf_Arc_ChannelIdType) Controller;
  CanIf_ChannelGetModeType oldMode = CanIf_Global.channelData[channel].PduMode;

  VALIDATE( CanIf_Global.initRun, CANIF_SETPDUMODE_ID, CANIF_E_UNINIT );
  VALIDATE( channel < CANIF_CHANNEL_CNT, CANIF_SETPDUMODE_ID, CANIF_E_PARAM_CONTROLLER );


  switch(PduModeRequest)
  {
  case CANIF_SET_OFFLINE:
    CanIf_Global.channelData[channel].PduMode = CANIF_GET_OFFLINE;
    break;
  case CANIF_SET_RX_OFFLINE:
    if (oldMode == CANIF_GET_RX_ONLINE){
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_OFFLINE;
    } else if (oldMode == CANIF_GET_ONLINE){
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_TX_ONLINE;
    } else if (oldMode == CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE){
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_OFFLINE_ACTIVE;
    }

    // Other oldmodes don't care
    break;
  case CANIF_SET_RX_ONLINE:
    if (oldMode == CANIF_GET_OFFLINE){
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_RX_ONLINE;
    } else if (oldMode == CANIF_GET_TX_ONLINE) {
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_ONLINE;
    } else if (oldMode == CANIF_GET_OFFLINE_ACTIVE){
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE;
    }

    // Other oldmodes don't care
    break;
  case CANIF_SET_TX_OFFLINE:
    if (oldMode == CANIF_GET_TX_ONLINE){
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_OFFLINE;
    } else if (oldMode == CANIF_GET_ONLINE) {
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_RX_ONLINE;
    } else if (oldMode == CANIF_GET_OFFLINE_ACTIVE) {
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_OFFLINE;
    } else if (oldMode == CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE) {
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_RX_ONLINE;
    }

    // Other oldmodes don't care
    break;
  case CANIF_SET_TX_ONLINE:
    if (oldMode == CANIF_GET_OFFLINE){
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_TX_ONLINE;
    } else if (oldMode == CANIF_GET_RX_ONLINE) {
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_ONLINE;
    } else if (oldMode == CANIF_GET_OFFLINE_ACTIVE) {
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_TX_ONLINE;
    } else if (oldMode == CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE) {
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_ONLINE;
    }

    // Other oldmodes don't care
    break;
  case CANIF_SET_ONLINE:
    CanIf_Global.channelData[channel].PduMode = CANIF_GET_ONLINE;
    break;

  case CANIF_SET_TX_OFFLINE_ACTIVE:
    if (oldMode == CANIF_GET_OFFLINE) {
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_OFFLINE_ACTIVE;
    } else if (oldMode == CANIF_GET_RX_ONLINE) {
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE;
    } else if (oldMode == CANIF_GET_TX_ONLINE) {
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_OFFLINE_ACTIVE;
    } else if (oldMode == CANIF_GET_ONLINE) {
      CanIf_Global.channelData[channel].PduMode = CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE;
    }

    // Other oldmodes don't care
    break;
  }

  return E_OK;
}

//-------------------------------------------------------------------

Std_ReturnType CanIf_GetPduMode(uint8 Controller,
    CanIf_ChannelGetModeType *PduModePtr)
{
  // We call this a CanIf channel. Hopefully makes it easier to follow.
  CanIf_Arc_ChannelIdType channel = (CanIf_Arc_ChannelIdType) Controller;

  VALIDATE( CanIf_Global.initRun, CANIF_GETPDUMODE_ID, CANIF_E_UNINIT );
  VALIDATE( channel < CANIF_CHANNEL_CNT, CANIF_GETPDUMODE_ID, CANIF_E_PARAM_CONTROLLER );

  *PduModePtr = CanIf_Global.channelData[channel].PduMode;

  return E_OK;
}

#if ( CANIF_ARC_RUNTIME_PDU_CONFIGURATION == STD_ON )
void CanIf_SetDynamicTxId(PduIdType CanTxPduId, Can_IdType CanId)
{
  CanIf_TxPduConfigType *txEntry;
  VALIDATE_NO_RV(CanIf_Global.initRun, CANIF_SETDYNAMICTX_ID, CANIF_E_UNINIT );

  // Get the controller from L-PDU handle
  txEntry = CanIf_FindTxPduEntry(CanTxPduId);

  if (txEntry == 0)
  {
    VALIDATE_NO_RV(FALSE, CANIF_SETDYNAMICTX_ID, CANIF_E_INVALID_TXPDUID);
    return;
  }

  // Check that this is a dymanic PDU
  if (txEntry->CanIfCanTxPduType != CANIF_PDU_TYPE_DYNAMIC)
  {
    VALIDATE_NO_RV(FALSE, CANIF_SETDYNAMICTX_ID, CANIF_E_INVALID_TXPDUID);
    return;
  }

  // Check that this is an extended or standard id
  if (((CanId & 0x80000000U) && (txEntry->CanIfTxPduIdCanIdType == CANIF_CAN_ID_TYPE_29)) ||
      (((CanId & 0x80000000U) == 0) && (txEntry->CanIfTxPduIdCanIdType == CANIF_CAN_ID_TYPE_11)))
  {
    // Update the CanID
    txEntry->CanIfCanTxPduIdCanId = CanId & 0x7FFFFFFFU;
  }
  else
  {
    // Inavlid Canid to configuration
    VALIDATE_NO_RV(FALSE, CANIF_SETDYNAMICTX_ID, CANIF_E_PARAM_CANID);
  }
}
#endif

#if ( CANIF_TRANSCEIVER_API == STD_ON )
Std_ReturnType CanIf_SetTransceiverMode(uint8 Transceiver,
    CanIf_TransceiverModeType TransceiverMode)
{
  VALIDATE(FALSE, CANIF_SET_TRANSCEIVERMODE_ID, CANIF_E_NOK_NOSUPPORT);
// Not supported

  return E_NOT_OK;
}

Std_ReturnType CanIf_GetTransceiverMode(uint8 Transceiver,
    CanIf_TransceiverModeType *TransceiverModePtr)
{
  VALIDATE(FALSE, CANIF_GET_TRANSCEIVERMODE_ID, CANIF_E_NOK_NOSUPPORT);
  // Not supported

  return E_NOT_OK;
}

Std_ReturnType CanIf_GetTrcvWakeupReason(uint8 Transceiver,
    CanIf_TrcvWakeupReasonType *TrcvWuReasonPtr)
{
  VALIDATE(FALSE, CANIF_GET_TRCVMODEREASON_ID, CANIF_E_NOK_NOSUPPORT);
  // Not supported

  return E_NOT_OK;
}

Std_ReturnType CanIf_SetTransceiverWakeupMode(uint8 Transceiver,
    CanIf_TrcvWakeupModeType *TrcvWakeupMode)
{
  VALIDATE(FALSE, CANIF_SET_TRANSCEIVERWAKEMODE_ID, CANIF_E_NOK_NOSUPPORT);
  // Not supported

  return E_NOT_OK;
}
#endif

#if ( CANIF_WAKEUP_EVENT_API == STD_ON )
Std_ReturnType CanIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
  VALIDATE(FALSE, CANIF_CHECKWAKEUP_ID, CANIF_E_NOK_NOSUPPORT);
  // Not supported

  return E_NOT_OK;
}

Std_ReturnType CanIf_CheckValidation(EcuM_WakeupSourceType WakeupSource)
{
  VALIDATE(FALSE, CANIF_CHECKVALIDATION_ID, CANIF_E_NOK_NOSUPPORT);
  // Not supported

  return E_NOT_OK;
}
#endif

/*
 * Callback interface from driver
 */
void CanIf_TxConfirmation(PduIdType CanTxPduId)
{
	VALIDATE_NO_RV(CanIf_Global.initRun, CANIF_TXCONFIRMATION_ID, CANIF_E_UNINIT)
	VALIDATE_NO_RV(CanTxPduId < CanIf_ConfigPtr->InitConfig->CanIfNumberOfCanTXPduIds, CANIF_TXCONFIRMATION_ID,
			CANIF_E_PARAM_LPDU);
  if(CanIf_Global.initRun != TRUE)
  {
    return;
  }
  if(CanTxPduId < )
  
	scheduleTxConfirmation(CanTxPduId);

	return;
}

/**
 * @Description: CAN报文接收回调
 * @Name: CanIf_RxIndication
 * @Param: 
 * @Return: 
 * @Author: Archie
 */
void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType *PduInfoPtr)
{
  if(Mailbox == NULL_PTR)
  {
    return;
  }
  if(PduInfoType == NULL_PTR)
  {
    return;
  }
  if(CanIf_Global.initRun != TRUE)
  {
    return;
  }
  scheduleRxIndication(Mailbox->ControllerId, Mailbox->CanId, 
                       PduInfoPtr->SduLength, PduInfoPtr->SduDataPtr);
}

#if ( CANIF_TRANSMIT_CANCELLATION == STD_ON )
void CanIf_CancelTxConfirmation(const Can_PduType *PduInfoPtr)
{
  VALIDATE(FALSE, CANIF_CANCELTXCONFIRMATION_ID, CANIF_E_NOK_NOSUPPORT);
  VALIDATE_NO_RV(CanIf_Global.initRun, CANIF_CANCELTXCONFIRMATION_ID, CANIF_E_UNINIT);
  VALIDATE_NO_RV(PduInfoPtr != NULL, CANIF_RXINDICATION_ID, CANIF_E_PARAM_POINTER);

  const CanIf_TxPduConfigType *entry =
    CanIf_ConfigPtr->InitConfig->CanIfTxPduConfigPtr;

  // Not supported

  // Did not find the PDU, something is wrong
  VALIDATE_NO_RV(FALSE, CANIF_TXCONFIRMATION_ID, CANIF_E_PARAM_LPDU);
}
#endif

void CanIf_ControllerBusOff(uint8 Controller)
{
  CanIf_Arc_ChannelIdType channel = 0xff;

  int i;
  VALIDATE_NO_RV( CanIf_Global.initRun, CANIF_CONTROLLER_BUSOFF_ID, CANIF_E_UNINIT );

  for(i = 0; i < CANIF_CHANNEL_CNT; i++)
  {
	  if(CanIf_ConfigPtr->Arc_ChannelToControllerMap[i] == Controller)
	  {
		  channel = i;
	  }
  }

  VALIDATE_NO_RV( Controller < CANIF_CHANNEL_CNT, CANIF_CONTROLLER_BUSOFF_ID, CANIF_E_PARAM_CONTROLLER );

  // According to figure 35 in canif spec this should be done in
  // Can driver but it is better to do it here
  CanIf_SetControllerMode(channel, CANIF_CS_STOPPED);

  if (CanIf_ConfigPtr->DispatchConfig->CanIfBusOffNotification != NULL)
  {
    CanIf_ConfigPtr->DispatchConfig->CanIfBusOffNotification(channel);
  }
}

void CanIf_SetWakeupEvent(uint8 Controller)
{
	int i;
	CanIf_Arc_ChannelIdType channel = 0xff;

	VALIDATE_NO_RV( CanIf_Global.initRun, CANIF_SETWAKEUPEVENT_ID, CANIF_E_UNINIT );

	for(i = 0; i < CANIF_CHANNEL_CNT; i++)
	{
	  if(CanIf_ConfigPtr->Arc_ChannelToControllerMap[i] == Controller)
	  {
		  channel = i;
	  }
	}

	VALIDATE_NO_RV(FALSE, CANIF_SETWAKEUPEVENT_ID, CANIF_E_NOK_NOSUPPORT);
	VALIDATE_NO_RV( channel < CANIF_CHANNEL_CNT, CANIF_SETWAKEUPEVENT_ID, CANIF_E_PARAM_CONTROLLER );

	// Not supported
}

void CanIf_Arc_Error(uint8 Controller, Can_Arc_ErrorType Error)
{
  int i;
  CanIf_Arc_ChannelIdType channel = 0xff;

  VALIDATE_NO_RV( CanIf_Global.initRun, CANIF_ARCERROR_ID, CANIF_E_UNINIT );

  for(i = 0; i < CANIF_CHANNEL_CNT; i++)
  {
	  if(CanIf_ConfigPtr->Arc_ChannelToControllerMap[i] == Controller)
	  {
		  channel = i;
	  }
  }

  VALIDATE_NO_RV( channel < CANIF_CHANNEL_CNT, CANIF_ARCERROR_ID, CANIF_E_PARAM_CONTROLLER );

  if (CanIf_ConfigPtr->DispatchConfig->CanIfErrorNotificaton != NULL)
  {
    CanIf_ConfigPtr->DispatchConfig->CanIfErrorNotificaton(Controller, Error);
  }

  // Special fix for restart of bus incase of general can error i.e. connection to CanSM
  if (CanIf_ConfigPtr->DispatchConfig->CanIfBusOffNotification != NULL)
  {
    CanIf_ConfigPtr->DispatchConfig->CanIfBusOffNotification(channel);
  }
}

uint8 CanIf_Arc_GetChannelDefaultConfIndex(CanIf_Arc_ChannelIdType Channel)
{
	return CanIf_Config.Arc_ChannelDefaultConfIndex[Channel];
}

KSM(CANIdle,Init)
{
	KGS(CANIdle,Running);
}
KSM(CANIdle,Start)
{
}
KSM(CANIdle,Stop)
{

}
KSM(CANIdle,Running)
{
	Can_MainFunction_Write();
	Can_MainFunction_Read();
}
#if (CANIF_TASK_FIFO_MODE==STD_ON)
TASK(TaskCanIf)
{
	scheduleTxFifo();
	scheduldRxFifo();
	OsTerminateTask(TaskCanIf);
}

void CanIf_MainFunction(void)
{
	scheduleTxFifo();
	scheduldRxFifo();
}
#else
TASK(TaskCanIf)
{
	OsTerminateTask(TaskCanIf);
}
#endif
#else
#include "Os.h"
KSM(CANIdle,Init)
{
	KGS(CANIdle,Running);
}
KSM(CANIdle,Start)
{
}
KSM(CANIdle,Stop)
{

}
KSM(CANIdle,Running)
{
}
TASK(TaskCanIf)
{
	OsTerminateTask(TaskCanIf);
}

#endif /* USE_CANIF */
