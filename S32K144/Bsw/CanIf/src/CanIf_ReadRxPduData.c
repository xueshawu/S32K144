

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "CanIf_Priv.h"

/*
 ***************************************************************************************************
 * used functions
 ***************************************************************************************************
 */
/****************************************************************************************************************/
/* Function name    : CanIf_ReadRxPduData                                                                       */
/* Syntax           : FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReadRxPduData(VAR(PduIdType, AUTOMATIC) CanRxPduId,
                                                  P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr)   */
/* Description      : This service provides the CAN DLC and the received data of the requested CanRxPduId
                      to the calling upper layer.                                                               */
/* Parameter        : CanRxPduId, PduInfoPtr                                                                    */
/* Return value     : E_OK / E_NOT_OK                                                                           */
/****************************************************************************************************************/
#if (CANIF_READRXPDU_DATA_API != STD_OFF)

#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_ReadRxPduData: Function contains very simple "else if" statements and "switch-cases". HIS metric compliance would decrease readability and maintainability. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReadRxPduData(
                                                        VAR(PduIdType, AUTOMATIC) CanRxPduId,
                                                        P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr
                                                    )
{
    /* Pointer to HRH configuration */
    P2CONST(CanIf_HrhConfigType, AUTOMATIC, CANIF_CFG_CONST) HrhCfg_pcs;

    /* Pointer to Rx Pdu configuration */
    P2CONST(CanIf_RxPduConfigType, AUTOMATIC, CANIF_CFG_CONST) RxPduCfg_pcs;

    /* Pointer to Controller State configuration */
    P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) ControllerState_ps;

    /* Return Value of the API */
    VAR(uint8_least, AUTOMATIC) Status;
    #if(CANIF_VARIANT_INFO == 1)
    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    VAR (uint16_least, CANIF_CONST) CanIf_Num_CanRxPduId;
	#endif
	#else
	#ifdef CANIF_MULTIPLE_VARIANTS_ENABLED
	VAR (uint16_least, CANIF_CONST) CanIf_Num_CanRxPduId;
	#endif
	#endif
    /*To store the controller state (Device mode)*/
    VAR (CanIf_ControllerModeType, AUTOMATIC) DeviceMode_Temp;

    /*To store the controller state (Channel mode)*/
    VAR (CanIf_PduGetModeType, AUTOMATIC) ChannelMode_Temp;

    #ifdef CANIF_MULTIPLE_VARIANTS_ENABLED
    VAR(uint8, AUTOMATIC) SearchStatus;

    VAR(PduIdType, AUTOMATIC) CanRxPduId_Temp;
    #endif

    /* If CAN Interface is uninitialized, report to DET and return E_NOT_OK */
    CANIF_DET_REPORT_ERROR_NOK((FALSE == CanIf_Init_Flag), CANIF_READ_RX_PDU_DATA_SID, CANIF_E_UNINIT)

    #if(CANIF_VARIANT_INFO == 1)
    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    CanIf_Num_CanRxPduId = CANIF_NUM_CANRXPDUIDS;
    #endif
    RxPduCfg_pcs = CanIf_RxPduConfig;
    HrhCfg_pcs = CanIf_HrhConfig;
    ControllerState_ps = CanIf_ControllerState;
    #else
	#ifdef CANIF_MULTIPLE_VARIANTS_ENABLED
    CanIf_Num_CanRxPduId = CanIf_ConfigSetPtr->NumCanRxPduId;
    #endif
	RxPduCfg_pcs = CanIf_ConfigSetPtr->RxPduConfig;
    HrhCfg_pcs = CanIf_ConfigSetPtr->HrhConfig;
    ControllerState_ps = CanIf_ConfigSetPtr->CtrlStatePtr;
    #endif

    #ifndef CANIF_MULTIPLE_VARIANTS_ENABLED
    /* If CanRxPduId is invalid, report to DET and return E_NOT_OK */
    CANIF_DET_REPORT_ERROR_NOK((CanRxPduId >= CanIf_Num_CanRxPduId), CANIF_READ_RX_PDU_DATA_SID,
                                                                                 CANIF_E_INVALID_RXPDUID)
    #endif

    /* If the PduInfoPtr is null, report to DET and return E_NOT_OK */
    CANIF_DET_REPORT_ERROR_NOK((NULL_PTR == PduInfoPtr), CANIF_READ_RX_PDU_DATA_SID, CANIF_E_PARAM_POINTER)

    #ifdef CANIF_MULTIPLE_VARIANTS_ENABLED
    /* MR12 RULE 10.3, VIOLATION: Warning is "Not Critical". CanIf_Num_CanRxPduId datatype is uint16_least,
     * Hence no data loss, even if it is coverted to uint16.
     */
    CanRxPduId_Temp = CanIf_SearchRxPduId(CanIf_ConfigSetPtr->RxPduConfig, CanIf_Num_CanRxPduId, CanRxPduId, &SearchStatus);

    CANIF_DET_REPORT_ERROR_NOK((SearchStatus == 0xFF), CANIF_READ_RX_PDU_DATA_SID,
                                                                                 CANIF_E_INVALID_RXPDUID)

    CanRxPduId = CanRxPduId_Temp;
    #endif


    /* Find the controller to which this CanRxPduId is mapped */
    /* Initialize pointer to Rx L-PDU structure
     * Get the location by using the Base address of the Rx-Pdu structure*/
    #if(CANIF_VARIANT_INFO == 1)
    RxPduCfg_pcs = CanIf_RxPduConfig + CanRxPduId;
    #else
    RxPduCfg_pcs = (CanIf_ConfigSetPtr->RxPduConfig) + CanRxPduId;
    #endif


    /* Initialize pointer to HRH configuration structure
     * Get the location by using the Base address of the HRH structure*/
    #if(CANIF_VARIANT_INFO == 1)
    HrhCfg_pcs = CanIf_HrhConfig + RxPduCfg_pcs->HrhRef;
    #else
    HrhCfg_pcs = (CanIf_ConfigSetPtr->HrhConfig) + RxPduCfg_pcs->HrhRef;
    #endif

    /*Enter critical section*/
    SchM_Enter_CanIf_ControllerState();

    /* Initialize pointer to Controller State */
    ControllerState_ps = ControllerState_ps + (HrhCfg_pcs->ControllerId);

    /*Make a local copy of Device mode and Channel mode*/
    DeviceMode_Temp = ControllerState_ps->DeviceMode;
    ChannelMode_Temp = ControllerState_ps->ChannelMode;

    /*Leave critical section*/
    SchM_Exit_CanIf_ControllerState();


    /* Initialization */
    Status = E_NOT_OK;

    /* Check whether the data can be read, the controller mode and the channel mode */
    if(((HrhCfg_pcs->ReadRxPdu == CANIF_READ_NOTIFSTATUS_DATA) || (HrhCfg_pcs->ReadRxPdu == CANIF_READ_DATA))
        && (CANIF_CS_STARTED            == DeviceMode_Temp)
        && (CANIF_GET_OFFLINE           != ChannelMode_Temp)
        && (CANIF_GET_TX_ONLINE         != ChannelMode_Temp))
    {
        /* Read the data from the Rx buffer */
        CanIf_ReadRxBuffer(PduInfoPtr, RxPduCfg_pcs);

        Status = E_OK;
    }

    return((Std_ReturnType)Status);
}  /* End of CanIf_ReadRxPduData() */

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#endif


