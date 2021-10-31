

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "CanIf_Priv.h"


/************************************************************************************************************/
/* Function name    : CanIf_CancelTransmit                                                                        */
/* Syntax           : FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit(VAR(PduIdType,AUTOMATIC) CanTxPduId)   */
/* Description      : This is a dummy API introduced for interface compatibility. This is
 *                    called by PduR to achieve bus agnostic behavior                               */
/* Parameter        : CanTxPduId                                                          */
/* Return value     : Always E_OK                                                                   */
/************************************************************************************************************/
#if (STD_ON == CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT)

#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC COMF VIOLATION IN CanIf_CancelTransmit: Function contains very simple "else if" statements and "switch-cases". HIS metric compliance would decrease readability and maintainability. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CancelTransmit(
                                                    VAR(PduIdType,AUTOMATIC) CanTxPduId

                                               )
{
#if (1 != CANIF_VARIANT_INFO)
    /* Local pointer to cust id look up table */
    const PduIdType (*TxPduId_CustId_LUT_Temp)[CANIF_TOTAL_CFG_SETS];
    VAR (uint16_least, AUTOMATIC) CanIf_TotalTxPduId;

#endif

#if (1 == CANIF_VARIANT_INFO)

     /* If CanTxPduId is invalid, report to DET and return E_OK*/
    if(CanTxPduId >= (CANIF_NUM_STATIC_CANTXPDUIDS + CANIF_NUM_DYNAMIC_CANTXPDUIDS))
    {
      #if (CANIF_DEV_ERROR_DETECT != STD_OFF)
        (void)Det_ReportError((CANIF_MODULE_ID), (CANIF_INSTANCE_ID), (CANIF_CANCELTRANSMIT_SID), (CANIF_E_INVALID_TXPDUID));
      #endif
    }


#else

    TxPduId_CustId_LUT_Temp = CanIf_ConfigSetPtr->CanIf_TxPduId_CustId_LUT_ptr;
    CanIf_TotalTxPduId = CanIf_ConfigSetPtr->NumCanTxPduId + CanIf_ConfigSetPtr->NumDynamicCanTxPduId;
   /* First check if the parametre passed ie the Tx-PduId is a valid one or not. This check is required to avoid "Fencepost error"
     * in CanIf_TxPduId_CustId_LUT[][]*/
    if(CanTxPduId < CanIf_ConfigSetPtr->Num_custid_entries)
    {
        /* If valid, get the Cust Id and put it in 'CanTxPduId'.
         * Cust Id is required since the CanIf_TxPduConfig[] is arranged as per CustId*/
        CanTxPduId = TxPduId_CustId_LUT_Temp[CanTxPduId][CanIf_ActiveCfgSet];

        /*Report DET if the CustId  = CANIF_TOTAL_TXPDUS, since it means the Tx-Pdu is
         * not present in the active configset*/
        if(CanTxPduId == CanIf_TotalTxPduId)
        {
#if (CANIF_DEV_ERROR_DETECT != STD_OFF)
             /* If CanTxPduId is invalid, report to DET and return E_OK*/
            Det_ReportError((CANIF_MODULE_ID), (CANIF_INSTANCE_ID), (CANIF_CANCELTRANSMIT_SID), (CANIF_E_INVALID_TXPDUID));
#endif
        }

    }
    else
    {
#if (CANIF_DEV_ERROR_DETECT != STD_OFF)
        /* If CanTxPduId is invalid, report to DET and return E_OK*/
        Det_ReportError((CANIF_MODULE_ID), (CANIF_INSTANCE_ID), (CANIF_CANCELTRANSMIT_SID), (CANIF_E_INVALID_TXPDUID));
#endif

    }
#endif

    /*Always return E_OK*/
    return E_OK;
}

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#endif


