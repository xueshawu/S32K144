

/**
\defgroup CANIF_H    CANIF - AUTOSAR interfaces Upper Layer
*/

#ifndef CANIF_H
#define CANIF_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/* Type definitions of CAN Interface */
/* CanIf configuration header file */
#include "CanIf_Cfg.h"

/* CanIf Type Definitions header file */
#include "CanIf_Types.h"

/*Can header file */
#include "Can.h"

//#include "rba_Can.h"

#if(CANIF_VARIANT_INFO == 2)
#include "CanIf_PBcfg.h"
#endif


#define CANIF_CS_UNINIT   ((CanIf_ControllerModeType)0)
#define CANIF_CS_SLEEP    ((CanIf_ControllerModeType)1)
#define CANIF_CS_STARTED  ((CanIf_ControllerModeType)2)
#define CANIF_CS_STOPPED  ((CanIf_ControllerModeType)3)


/****************************************************************************************************************
**                                   Global Function Prototypes                                                **
****************************************************************************************************************/

/**
 * @ingroup CANIF_H
 *
 * This service Initializes internal and external interfaces of the CAN Interface for the further processing. \n
 *
 * @param  In: ConfigPtr           -   Pointer to configuration parameter set.\n
 *
 * @return None \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(void, CANIF_CODE) CanIf_Init(P2CONST (CanIf_ConfigType, AUTOMATIC, CANIF_APPL_CONST) ConfigPtr);

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

/* FC_VariationPoint_START */
/* Has been removed from CanIf SWS 4.0.2. Shall be enabled if required */
/* FC_VariationPoint_END */

#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(void, CANIF_CODE) CanIf_DeInit(P2CONST (CanIf_ConfigType, AUTOMATIC, CANIF_APPL_CONST) ConfigPtr);

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


/**
 * @ingroup CANIF_H
 *
 * This service calls the corresponding CAN driver service for changing of the CAN controller mode.  \n
 *
 * @param  In: Controller       -   Abstracted CanIf ControllerId which is assigned to a CAN controller \n
 * @param  In: ControllerMode   -   Requested mode transition \n
 *
 * @return     E_OK             -   Controller mode request has been accepted. \n
 *             E_NOT_OK         -   Controller mode request has not been accepted \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode(
                                                               VAR (uint8,AUTOMATIC) Controller,
                                                               VAR(CanIf_ControllerModeType,AUTOMATIC) ControllerMode
                                                              );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

/**
 * @ingroup CANIF_H
 *
 * Service reports about the current status of the requested CAN Controller.  \n
 *
 * @param  In: Controller       -   Abstracted CanIf ControllerId which is assigned to a CAN controller \n
 * @param  In: ControllerModePtr   -   Pointer to a memory location, where the current mode of the CAN controller will be stored. \n
 *
 * @return     E_OK             -   Controller mode request has been accepted. \n
 *             E_NOT_OK         -   Controller mode request has not been accepted \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode(
                                                                VAR(uint8,AUTOMATIC) Controller,
                                                                P2VAR(CanIf_ControllerModeType, AUTOMATIC, CANIF_APPL_DATA) ControllerModePtr
                                                               );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
/**
 * @ingroup CANIF_H
 *
 * This service initiates a request for transmission of the CAN L-PDU specified by the CanTxPduId and CAN related data in the L-PDU structure \n
 *
 * @param  In: CanTxPduId       -   L-PDU handle of CAN L-PDU to be transmitted.\n
 * @param  In: PduInfoPtr       -   Pointer to a structure with CAN L-PDU related data: DLC and pointer to CAN L-SDU buffer \n
 *
 * @return     E_OK             -   Transmit request has been accepted \n
 *             E_NOT_OK         -   Transmit request has not been accepted \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit(
                                                       VAR(PduIdType,AUTOMATIC) CanTxPduId,
                                                       P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr
                                                      );

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

/* FC_Variationpoint_START */
/**
 * @ingroup CANIF_H
 *
 * This service initiates a request to get info for direct HW write for CAN L-PDU specified by the CanTxPduId \n
 *
 * @param  In : CanTxPduId         -  L-PDU handle of CAN L-PDU to be transmitted \n
 * @param  Out: hw_info_po        -  Pointer to the rba_CanDirectHWInfo_o structure
 * @return     E_OK                -  Request to get direct HW info has been accepted \n
 *             E_NOT_OK            -  Request to get direct HW info has not been accepted \n
 */
#if (CANIF_DIRECT_HW_WRITE == STD_ON)
#define CANIF_START_SEC_CODE_FAST
#include "CanIf_MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_Get_DirectHw_Info (VAR(PduIdType, AUTOMATIC) CanTxPduId,
                                                                 P2VAR(rba_CanDirectHWInfo_o, AUTOMATIC, CANIF_APPL_DATA) hw_info_po
                                                      );

#define CANIF_STOP_SEC_CODE_FAST
#include "CanIf_MemMap.h"
#endif
/**
 * @ingroup CANIF_H
 *
 * This service initiates a request for direct HW write for CAN L-PDU specified by the CanTxPduId \n
 *
 * @param  In: p_tx_data_buff_u32 -  Pointer to the transmit data buffer \n
 * @param  In: data_len_u32       -  Data length \n
 * @param  In: hw_info_po        -  Pointer to the rba_CanDirectHWInfo_o structure
 * @return     E_OK               -  Direct Hw write request has been accepted \n
 *             E_NOT_OK           -  Direct Hw write request has not been accepted \n
 */
#if (CANIF_DIRECT_HW_WRITE == STD_ON)
#define CANIF_START_SEC_CODE_FAST
#include "CanIf_MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_DirectHw_Write (P2CONST(uint32, AUTOMATIC, CANIF_APPL_DATA) p_tx_data_buff_u32,
                                                              VAR(uint32, AUTOMATIC) data_len_u32,
                                                              P2CONST(rba_CanDirectHWInfo_o, AUTOMATIC, CANIF_APPL_DATA) hw_info_po
                                                      );

#define CANIF_STOP_SEC_CODE_FAST
#include "CanIf_MemMap.h"
#endif
/* FC_Variationpoint_END */
/**
 * @ingroup CANIF_H
 *
 * This is a dummy API introduced for interface compatibility. This is called by PduR to achieve bus agnostic behavior
 *
 * @param  In: CanTxPduId       -   L-PDU handle of CAN L-PDU to be transmitted.\n
 * @return     E_OK             -   Always returns E_OK
 *
 */
#if (STD_ON == CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CancelTransmit(
                                                             VAR(PduIdType,AUTOMATIC) CanTxPduId
                                                            );

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif

/**
 * @ingroup CANIF_H
 *
 * This service sets the requested mode at all L-PDUs of the predefined CAN controller. \n
 *
 * @param  In:  Controller      -   Abstracted CanIf ControllerId which is assigned to a CAN controller \n
 * @param  In:  PduModeRequest  -   Requested PDU mode change. \n
 *
 * @return      E_OK            -   Request for mode transition has been accepted. \n
 *              E_NOT_OK        -   Request for mode transition has not been accepted.\n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode(
                                                         VAR(uint8,AUTOMATIC) Controller,
                                                         VAR(CanIf_PduSetModeType,AUTOMATIC) PduModeRequest
                                                        );

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


/**
 * @ingroup CANIF_H
 *
 * This service reports the current mode of the requested Controller.. \n
 *
 * @param  In:  Controller      -   Abstracted CanIf ControllerId which is assigned to a CAN controller \n
 * @param  In:  PduModePtr      -   Pointer to a memory location, where the current mode of the logical PDU channel will be stored. \n
 *
 * @return      E_OK            -   PDU mode request has been accepted. \n
 *              E_NOT_OK        -   PDU mode request has not been accepted. \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetPduMode(
                                                         VAR(uint8,AUTOMATIC) Controller,
                                                         P2VAR(CanIf_PduGetModeType, AUTOMATIC,CANIF_APPL_DATA) PduModePtr
                                                        );

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


/**
 * @ingroup CANIF_H
 *
 * This service provides the CAN DLC and the received data of the requested CanRxPduId to the calling upper layer. \n
 *
 * @param  In:  CanRxPduId      -   Receive L-PDU handle of CAN L-PDU. \n
 * @param  In:  PduInfoPtr      -   Pointer to a structure with CAN L-PDU related data: DLC and pointer to CAN L-SDU buffer. \n
 *
 * @return      E_OK            -   Request for L-PDU data has been accepted. \n
 *              E_NOT_OK        -   No valid data has been received. \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReadRxPduData(
                                                            VAR(PduIdType, AUTOMATIC) CanRxPduId,
                                                            P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr
                                                           );

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


/**
 * @ingroup CANIF_H
 *
 * This service returns the confirmation status (confirmation occured of not) of a specific static or dynamic CAN Tx L-PDU, requested by the CanTxPduId. \n
 *
 * @param  In:  CanTxPduId                  -   L-PDU handle of CAN L-PDU to be transmitted. \n
 *
 * @return      CANIF_NO_NOTIFICATION       -   No transmit event occurred for the requested L-PDU. \n
 *              CANIF_TX_RX_NOTIFICATION    -   The requested Rx/Tx CAN L-PDU was successfully transmitted or received. \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadTxNotifStatus(
                                                                      VAR(PduIdType,AUTOMATIC) CanTxPduId
                                                                      );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
/**
 * @ingroup CANIF_H
 *
 * This service provides the status of the CAN Rx L-PDU requested by CanRxPduId. This API
 *                     service notifies the upper layer about any receive indication event to the corresponding
 *                     requested CAN LPDU.\n
 *
 * @param  In:  CanTxPduId                  -   L-PDU handle of CAN L-PDU to be transmitted. \n
 *
 * @return      CANIF_NO_NOTIFICATION       -   No recieve event occurred for the requested L-PDU. \n
 *              CANIF_TX_RX_NOTIFICATION    -   The requested Rx/Tx CAN L-PDU was successfully transmitted or received. \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadRxNotifStatus(VAR(PduIdType, AUTOMATIC) CanRxPduId);

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


/**
 * @ingroup CANIF_H
 *
 * This service returns the version information of the called CAN Interface module. \n
 *
 * @param  In:  VersionInfo     -   Pointer to where to store the version information of this module.\n
 *
 * @return None \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(void, CANIF_CODE) CanIf_GetVersionInfo (P2VAR(Std_VersionInfoType, AUTOMATIC, CANIF_APPL_DATA) VersionInfo);

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

/**
 * @ingroup CANIF_H
 *
 * This service reconfigures the corresponding CAN identifier of the requested CAN L-PDU. \n
 *
 * @param  In:  CanTxPduId      -   L-PDU handle of CAN L-PDU for transmission. \n
 * @param  In:  CanId           -   Standard/Extended CAN ID of CAN L-PDU that shall be transmitted. \n
 *
 * @return None \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(void, CANIF_CODE) CanIf_SetDynamicTxId(
                                                  VAR(PduIdType,AUTOMATIC) CanTxPduId,
                                                  VAR(Can_IdType,AUTOMATIC) CanId
                                                   );

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


/* FC_VariationPoint_START */
/**
 * @ingroup CANIF_H
 * This service reconfigures the corresponding Static CanId of the requested CAN L-PDU  \n
 * @param  In:  CanTxPduId      -   L-PDU handle of CAN L-PDU for transmission. \n
 *
 * @return None \n
 */
/* FC_VariationPoint_END */
/* FC_VariationPoint_START */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(void, CANIF_CODE) CanIf_ResetDynamicTxId(VAR(PduIdType, AUTOMATIC) CanTxPduId);

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
/* FC_VariationPoint_END */


#if (CANIF_WAKEUP_SUPPORT != STD_OFF)
/**
 * @ingroup CANIF_H
 *
 * This service checks, whether an underlying CAN driver or a CAN transceiver driver already signals a wakeup event. \n
 *
 * @param  In:  WakeupSource    -   Source device, which initiated the wake up event: CAN controller or CAN transceiver \n
 *
 * @return   :  E_OK            -   Will be returned, if the check wake up request has been accepted \n
 *              E_NOT_OK        -   Will be returned, if the check wake up request has not been accepted \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup (VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource);

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif

#if (CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
/**
 * @ingroup CANIF_H
 *
 * Service is performed to validate a previous wakeup event. This service is called by the EcuM. \n
 *
 * @param  In:  WakeupSource    -   Source device which initiated the wake-up event and which has to be validated: CAN controller or CAN transceiver \n
 *
 * @return   :  E_OK            -   Will be returned, if the check validation request has been accepted. \n
 *              E_NOT_OK        -   Will be returned, if the check validation request has not been accepted. \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckValidation (VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource);

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif

/* Functions for CanIf Transceiver Support */
/**
 * @ingroup CANIF_H
 *
 * This service changes the operation mode of the tansceiver TransceiverId, via calling the corresponding CAN Transceiver Driver service. \n
 *
 * @param  In:  TransceiverId   -   Abstracted CanIf TransceiverId, which is assigned to a CAN transceiver. \n
 * @param  In:  TransceiverMode -   Requested mode transition. \n
 *
 * @return      E_OK            -   Transceiver state has been changed to the requested mode. \n
 *              E_NOT_OK        -   Transceiver state change has failed or the parameter is out of the allowed range. \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvMode(
                                            VAR(uint8, AUTOMATIC) TransceiverId,
                                            VAR(CanTrcv_TrcvModeType, AUTOMATIC) TransceiverMode
                                                          );

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

/**
 * @ingroup CANIF_H
 *
 *This API returns actual state of CAN Transceiver Driver.  \n
 *
 * @param  In:  TransceiverId   -   Abstracted CanIf TransceiverId, which is assigned to a CAN transceiver. \n
 * @param  In:  TransceiverModePtr  -   Requested mode of requested network the Transceiver is connected to.. \n
 * @return      E_OK            -   Transceiver state has been changed to the requested mode. \n
 *              E_NOT_OK        -   Transceiver mode request has not been accepted. \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvMode(
                                            P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_APPL_DATA) TransceiverModePtr,
                                            VAR(uint8, AUTOMATIC) TransceiverId
                                                           );

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


#if CANIF_TRCV_DRV_CFG!=STD_OFF
/**
 * @ingroup CANIF_H
 *
 * This API returns the reason for the wake up that the CAN transceiver has detected. \n
 *
 * @param  In:  TransceiverId   -   Abstracted CanIf TransceiverId, which is assigned to a CAN transceiver. \n
 *
 * @param Out:  TrcvWuReasonPtr -   Provided pointer to where the requested transceiver wake up reason shall be returned. \n
 *
 * @return      E_OK            -   Transceiver wake up reason request has been accepted. \n
 *              E_NOT_OK        -   Transceiver wake up reason request has not been accepted. \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason(
                                            VAR(uint8, AUTOMATIC) TransceiverId,
                                            P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_APPL_DATA) TrcvWuReasonPtr
                                                                 );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
/**
 * @ingroup CANIF_H
 *
 * This API enables, disables and clears the notification for wakeup events
 *                      on the addressed network. \n
 *
 * @param  In:  TransceiverId   -   Abstracted CanIf TransceiverId, which is assigned to a CAN transceiver. \n
 * @param  In:  TrcvWakeupMode  -   Requested transceiver wake up notification mode. \n
 *
 * @return      E_OK            -   Wake up notifications state has been changed to the requested mode. \n
 *              E_NOT_OK        -   Wake up notifications state change has failed or the parameter is out of the allowed range. \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvWakeupMode(
                                                VAR(uint8, AUTOMATIC) TransceiverId,
                                                VAR(CanTrcv_TrcvWakeupModeType, AUTOMATIC) TrcvWakeupMode
);
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif

/* FC_VariationPoint_START */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReturnRxPduId(
                                                     VAR(PduIdType, AUTOMATIC) CanIfRxTargetPduId,
                                                    P2VAR(PduIdType, AUTOMATIC, CANIF_APPL_CONST) CanIfRxPduIdPtr
                                                    );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReturnTxPduId(
                                                     VAR(PduIdType, AUTOMATIC) CanIfTxTargetPduId,
                                                    P2VAR(PduIdType, AUTOMATIC, CANIF_APPL_CONST) CanIfTxPduIdPtr
                                                    );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
/* FC_VariationPoint_END */

#if (CANIF_PUBLIC_CHANGE_BAUDRATE_SUPPORT == STD_ON)
/**
 * @ingroup CANIF_H
 *
 * This service checks whether the CAN controller supports the requested baud rate. \n
 *
 * @param  In:  Controller      -   Can controller to check the support of certain baud rate. \n
 * @param  In:  dBaudRate_u32   -   Baud rate check in Kbps. \n
 *
 * @return      E_OK            -   Baud rate supported by CAN controller. \n
 *              E_NOT_OK        -   Baud rate not supported / Invalid CAN controller. \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckBaudrate(
                                                VAR (uint8,AUTOMATIC) Controller,
                                                CONST(uint32,AUTOMATIC) dBaudRate_u32
                                                );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

/**
 * @ingroup CANIF_H
 *
 * This service changes the baud rate of the CAN controller. \n
 *
 * @param  In:  Controller      -   Can controller to check the support of certain baud rate. \n
 * @param  In:  dBaudRate_u32   -   Baud rate check in Kbps. \n
 *
 * @return      E_OK            -   Service request accpeted, baud rate change started. \n
 *              E_NOT_OK        -   Service request not accepted. \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ChangeBaudrate(
                                                VAR (uint8,AUTOMATIC) Controller,
                                                CONST(uint32,AUTOMATIC) dBaudRate_u32
                                                );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif
/* FC_VariationPoint_START */
#if (CANIF_PUBLIC_SET_BAUDRATE_SUPPORT == STD_ON)
/**
 * @ingroup CANIF_H
 *
 * This service changes the baud rate for the configured CAN controllers of a certain CAN network. \n
 *
 * @param  In:  Controller          -   CAN controller, whose baud rate shall be set. \n
 * @param  In:  BaudRateConfigID    -   references a baud rate configuration by ID. \n
 *
 * @return      E_OK            -   Service request accepted, setting of (new) baud rate started. \n
 *              E_NOT_OK        -   Service request not accepted. \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetBaudrate(
                                                VAR (uint8,AUTOMATIC) Controller,
                                                CONST(uint16,AUTOMATIC) BaudRateConfigID
                                                );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif
/* FC_VariationPoint_END */

#if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)

/**
 * @ingroup CANIF_H
 *
 *   This service reports, if any TX confirmation has been done for the whole CAN controller
 *                     since the last CAN controller start. \n
 *
 * @param  In:  ControllerId        -   Can controller to check the support of certain baud rate. \n
 *
 * @return      CANIF_NO_NOTIFICATION       -   No transmit or receive event occurred for the requested L-PDU. \n
 *              CANIF_TX_RX_NOTIFICATION    -   The requested Rx/Tx CAN L-PDU was successfully transmitted or received. \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_GetTxConfirmationState(
                                       VAR(uint8,AUTOMATIC) ControllerId
                                               );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif


#if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)

/**
 * @ingroup CANIF_H
 *
 * Requests the CanIf module to clear the WUF flag of the designated CAN transceiver. \n
 *
 * @param  In:  TransceiverId   -   Designated CAN transceiver. \n
 *
 * @return      E_OK            -   Request has been accepted. \n
 *              E_NOT_OK        -   Request has not been accepted. \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag(
                                              VAR(uint8,AUTOMATIC) TransceiverId
                                                               );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
/**
 * @ingroup CANIF_H
 *
 * Requests the CanIf module to check the Wake flag of the designated CAN transceiver. \n
 *
 * @param  In:  TransceiverId   -   Designated CAN transceiver. \n
 *
 * @return      E_OK            -   Request has been accepted. \n
 *              E_NOT_OK        -   Request has not been accepted. \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTrcvWakeFlag(
                                              VAR(uint8,AUTOMATIC) TransceiverId
                                                               );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#endif


#if (CANIF_READMSGID_API != STD_OFF)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/**
 * @ingroup CANIF_H
 *
 * This function is used to get the message identifier configured in message configuration table (HOH table of CanDriver). \n
 *
 * @param  In:  msgHandleTx_u16  - HOH handle ID. \n
 *
 * @return      uint32           -   Configured CanID for the given HOH handle  \n
 */
extern FUNC(uint32, CANIF_CODE) CanIf_ReadTxMsgId(
                                                  VAR(uint16, AUTOMATIC) msgHandleTx_u16
                                                 );

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/**
 * @ingroup CANIF_H
 *
 * This function is used to get the message identifier configured in message configuration table (HOH table of CanDriver). \n
 *
 * @param  In:  msgHandleRx_u16  - HOH handle ID. \n
 *
 * @return      uint32           -   Configured CanID for the given HOH handle  \n
 */
extern FUNC(uint32, CANIF_CODE) CanIf_ReadRxMsgId(
                                                  VAR(uint16, AUTOMATIC) msgHandleRx_u16
                                                 );

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#endif


/* Global structures */

/**
 * @ingroup CANIF_H
 *
 * extern CONST(CanIf_ConfigType, CANIF_CONST) CanIf_Config; ConfigParams for CanIf_Init(). \n
 */
#if(CANIF_VARIANT_INFO != 2) && (CANIF_VARIANT_INFO != 3)
#define CANIF_START_SEC_CONST_UNSPECIFIED
#else
#define CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#endif
#include "CanIf_MemMap.h"
extern CONST(CanIf_ConfigType, CANIF_CONST) CanIf_Config;
#if(CANIF_VARIANT_INFO != 2) && (CANIF_VARIANT_INFO != 3)
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#else
#define CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#endif
#include "CanIf_MemMap.h"

#if(CANIF_VARIANT_INFO == 2) || (CANIF_VARIANT_INFO == 3)
#define CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"
extern CONST(PduIdType, CANIF_CONST) CanIf_TxPduId_CustId_LUT[][CANIF_TOTAL_CFG_SETS];
#define CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"
#endif


#endif   /* CANIF_H */
/* FC_VariationPoint_START */


/* FC_VariationPoint_END */
