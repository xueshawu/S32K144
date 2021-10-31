

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
/**************************************************************************************************************/
/* Function name    : CanIf_ReadTx_NotifStatus                                                                */
/* Syntax           : FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadTx_NotifStatus(
                                                                                        VAR(PduIdType,AUTOMATIC) CanTxPduId
                                                                                      )                       */
/* Description      : This service provides the status of the CAN Tx L-PDU requested by CanTxPduId. This API
                      service notifies the upper layer about any transmit confirmation or receive indication
                      event to the corresponding requested CAN LPDU.                                          */
/* Parameter        : CanTxPduId                                                                              */
/* Return value     : CANIF_TX_RX_NOTIFICATION / CANIF_NO_NOTIFICATION                                        */
/**************************************************************************************************************/

#if (CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF)

#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_ReadTxNotifStatus: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadTxNotifStatus(
                                                                  VAR(PduIdType,AUTOMATIC) CanTxPduId
                                                               )
{
    /* Pointer to Tx Pdu configuration */
    P2CONST(CanIf_TxPduInfo, AUTOMATIC, CANIF_CFG_CONST) TxPduConfig_Temp;
    /* Local pointer to cust id look up table */
#if(CANIF_VARIANT_INFO == 2) || (CANIF_VARIANT_INFO == 3)
    const PduIdType (*TxPduId_CustId_LUT_Temp)[CANIF_TOTAL_CFG_SETS];
#endif


    /* Store the Notification Status of each CanTxPduId  */
    VAR(CanIf_NotifStatusType, AUTOMATIC) NotifStatus;

    VAR (uint16_least, AUTOMATIC) CanIf_TotalTxPduId;

    P2VAR(CanIf_NotifStatusType, AUTOMATIC,AUTOMATIC) TxNotifPtr_Temp;

    /*Initialise the return value*/
    NotifStatus = CANIF_NO_NOTIFICATION;

    /* If CAN Interface is uinitialized, report to DET and return CANIF_NO_NOTIFICATION */
    CANIF_DET_REPORT_ERROR_NO_NOTIF((FALSE == CanIf_Init_Flag), CANIF_READ_TX_NOTIF_STATUS_SID,CANIF_E_UNINIT)

    #if(CANIF_VARIANT_INFO == 1)
    CanIf_TotalTxPduId = (uint16_least)CANIF_NUM_STATIC_CANTXPDUIDS + (uint16_least)CANIF_NUM_DYNAMIC_CANTXPDUIDS;
    TxPduConfig_Temp = CanIf_TxPduConfig;
    TxNotifPtr_Temp = CanIf_TxNotification;

    #else
    CanIf_TotalTxPduId = CanIf_ConfigSetPtr->NumCanTxPduId + CanIf_ConfigSetPtr->NumDynamicCanTxPduId;
    TxPduId_CustId_LUT_Temp = CanIf_ConfigSetPtr->CanIf_TxPduId_CustId_LUT_ptr ;

    /* First check if the parametre passed ie the Tx-PduId is a valid one or not. This check is required to avoid "Fencepost error"
     * in CanIf_TxPduId_CustId_LUT[][]*/
    if(CanTxPduId < CanIf_ConfigSetPtr->Num_custid_entries)
    {
        /* If valid, get the Cust Id and put it in 'CanTxPduId'.
         * Cust Id is required since the CanIf_TxPduConfig[] is arranged as per CustId*/
        CanTxPduId = TxPduId_CustId_LUT_Temp[CanTxPduId][CanIf_ActiveCfgSet];

        /*Return CANIF_NO_NOTIFICATION if the CustId  = CANIF_TOTAL_TXPDUS, since it means the Tx-Pdu is
         * not present in the active configset*/
        if(CanTxPduId == CanIf_TotalTxPduId)
        {
            return ((CanIf_NotifStatusType)NotifStatus);
        }
    }
    else
    {
        /*Else return CANIF_NO_NOTIFICATION*/
        return ((CanIf_NotifStatusType)NotifStatus);
    }


    TxPduConfig_Temp = CanIf_ConfigSetPtr->TxPduConfig;
    TxNotifPtr_Temp = CanIf_ConfigSetPtr->TxNotifPtr;
    #endif

    /* If CanTxPduId is invalid, report to DET and return CANIF_NO_NOTIFICATION */
    CANIF_DET_REPORT_ERROR_NO_NOTIF((CanTxPduId >= CanIf_TotalTxPduId),
                                        CANIF_READ_TX_NOTIF_STATUS_SID, CANIF_E_INVALID_TXPDUID)


    /* Initialise the Tx PDU configuration pointer to corresponding L-PDU
     * Get the location by using the Base address of the Tx-Pdu structure*/
    #if(CANIF_VARIANT_INFO == 1)
    TxPduConfig_Temp = CanIf_TxPduConfig + CanTxPduId;
    #else
    TxPduConfig_Temp = (CanIf_ConfigSetPtr->TxPduConfig) +CanTxPduId;
    #endif



    /* Check if the Notification status can be read */
    if( FALSE != TxPduConfig_Temp->ReadTxPduNotifyStatus )
    {
        /* Enter Critical Section */
        SchM_Enter_CanIf_TxRxNotifNoNest();

        /* Copy the status from the global variable into a local variable */
        NotifStatus = (CanIf_NotifStatusType)(*(TxNotifPtr_Temp +CanTxPduId));

        /* Reset the global variable */
        *(TxNotifPtr_Temp +CanTxPduId) = CANIF_NO_NOTIFICATION;

        /* Leave Critical Section */
        SchM_Exit_CanIf_TxRxNotifNoNest();

    }

    return(NotifStatus);
}

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#endif  /* End of API */


