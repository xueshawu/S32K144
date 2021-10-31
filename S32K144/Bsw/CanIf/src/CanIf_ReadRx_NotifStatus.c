

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
/* Function name    : CanIf_ReadRx_NotifStatus                                                                  */
/* Syntax           : FUNC(CanIf_NotifStatusType, CANIF_CODE)
                                                CanIf_ReadRxNotifStatus(VAR(PduIdType, AUTOMATIC) CanRxPduId)   */
/* Description      : This service provides the status of the CAN Rx L-PDU requested by CanRxPduId. This API
                      service notifies the upper layer about any receive indication event to the corresponding
                      requested CAN LPDU.                                                                       */
/* Parameter        : CanRxPduId                                                                                */
/* Return value     : CANIF_TX_RX_NOTIFICATION / CANIF_NO_NOTIFICATION                                          */
/****************************************************************************************************************/

#if (CANIF_READRXPDU_NOTIFY_STATUS_API != STD_OFF)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_ReadRxNotifStatus: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadRxNotifStatus(VAR(PduIdType, AUTOMATIC) CanRxPduId)
{
    /* Pointer to HRH configuration */
    P2CONST(CanIf_HrhConfigType, AUTOMATIC, CANIF_CFG_CONST) HrhCfg_pcs;

    /* Pointer to Rx Pdu configuration */
    P2CONST(CanIf_RxPduConfigType, AUTOMATIC, CANIF_CFG_CONST) RxPduCfg_pcs;

    /* Return Value of the API */
    VAR(CanIf_NotifStatusType, AUTOMATIC) NotifStatus;


    VAR (uint16_least, CANIF_CONST) CanIf_Num_CanRxPduId;

    P2VAR(CanIf_NotifStatusType, AUTOMATIC,AUTOMATIC) RxNotifPtr_Temp;

    #ifdef CANIF_MULTIPLE_VARIANTS_ENABLED
    VAR(uint8,     AUTOMATIC) SearchStatus_u8;

    VAR(PduIdType, AUTOMATIC) CanRxPduId_Temp;
    #endif


    /* If CAN Interface is uninitialized, report to DET and return CANIF_NO_NOTIFICATION */
    CANIF_DET_REPORT_ERROR_NO_NOTIF((FALSE == CanIf_Init_Flag), CANIF_READ_RX_NOTIF_STATUS_SID,CANIF_E_UNINIT)


    #if(CANIF_VARIANT_INFO == 1)
    CanIf_Num_CanRxPduId = CANIF_NUM_CANRXPDUIDS;
    RxPduCfg_pcs = CanIf_RxPduConfig;
    HrhCfg_pcs = CanIf_HrhConfig;
    RxNotifPtr_Temp = CanIf_RxNotification;

    #else
    CanIf_Num_CanRxPduId = CanIf_ConfigSetPtr->NumCanRxPduId;
    RxPduCfg_pcs = CanIf_ConfigSetPtr->RxPduConfig;
    HrhCfg_pcs = CanIf_ConfigSetPtr->HrhConfig;
    RxNotifPtr_Temp = CanIf_ConfigSetPtr->RxNotifPtr;
    #endif

    #ifndef CANIF_MULTIPLE_VARIANTS_ENABLED
    /* If CanRxPduId is invalid, report to DET and return CANIF_NO_NOTIFICATION */
    CANIF_DET_REPORT_ERROR_NO_NOTIF((CanRxPduId >= CanIf_Num_CanRxPduId), CANIF_READ_RX_NOTIF_STATUS_SID,
                                                                                            CANIF_E_INVALID_RXPDUID)
    #endif

    #ifdef CANIF_MULTIPLE_VARIANTS_ENABLED
    /* MR12 RULE 10.3, VIOLATION: Warning is "Not Critical". CanIf_Num_CanRxPduId datatype is uint16_least,
     * Hence no data loss, even if it is coverted to uint16.
     */
    CanRxPduId_Temp = CanIf_SearchRxPduId(CanIf_ConfigSetPtr->RxPduConfig, CanIf_Num_CanRxPduId, CanRxPduId, &SearchStatus_u8);

    CANIF_DET_REPORT_ERROR_NO_NOTIF((SearchStatus_u8 == 0xFF), CANIF_READ_RX_NOTIF_STATUS_SID,
                                                                                        CANIF_E_INVALID_RXPDUID)

    CanRxPduId = CanRxPduId_Temp;
    #endif

    /* Initialize pointer to Rx L-PDU structure
     * Get the location by using the Base address of Rx-Pdu structure*/
    #if(CANIF_VARIANT_INFO == 1)
    RxPduCfg_pcs = CanIf_RxPduConfig + CanRxPduId;
    #else
    RxPduCfg_pcs = CanIf_ConfigSetPtr->RxPduConfig + CanRxPduId;
    #endif


    /* Initialize pointer to HRH configuration structure
     * Get the location by using the Base address of the HRH structure*/
    #if(CANIF_VARIANT_INFO == 1)
    HrhCfg_pcs = CanIf_HrhConfig + (RxPduCfg_pcs)->HrhRef;
    #else
    HrhCfg_pcs = (CanIf_ConfigSetPtr->HrhConfig) + ((RxPduCfg_pcs)->HrhRef);
    #endif


    /* Initialisation of the return value*/
    NotifStatus = CANIF_NO_NOTIFICATION;

    /* Check if the Notification status can be read */
    if((HrhCfg_pcs->ReadRxPdu == CANIF_READ_NOTIFSTATUS_DATA) || (HrhCfg_pcs->ReadRxPdu == CANIF_READ_NOTIFSTATUS))
    {
        /* Enter Critical Section */
        SchM_Enter_CanIf_TxRxNotifNoNest();

        /* Copy the notification status */
        NotifStatus = *(RxNotifPtr_Temp + CanRxPduId);

        /* Reset the global variable holding the notification status */
        *(RxNotifPtr_Temp + CanRxPduId) = CANIF_NO_NOTIFICATION;

        /* Leave Critical Section */
        SchM_Exit_CanIf_TxRxNotifNoNest();

    }

    return (NotifStatus);
}/* End of CanIf_ReadRx_NotifStatus() */

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#endif


