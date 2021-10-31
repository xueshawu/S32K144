

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
/* Function name    : CanIf_ReturnTxPduId                                                                       */
/* Syntax           :FUNC(Std_ReturnType, CANIF_CODE)CanIf_ReturnTxPduId(
                                                     VAR(PduIdType, AUTOMATIC) CanIfTxTargetPduId,
                                                    P2VAR(PduIdType, AUTOMATIC, CANIF_APPL_CONST) CanIfTxPduIdPtr
                                                    ) */
/* Description      :  Service that retutrns the PduId when the Target PduId is given.                                                             */
/* Parameter        : CanIfTxTargetPduId, CanIfTxPduIdPtr                                                                   */
/* Return value     : E_OK / E_NOT_OK                                                                           */
/****************************************************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_ReturnTxPduId: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(Std_ReturnType, CANIF_CODE)CanIf_ReturnTxPduId(
                                                     VAR(PduIdType, AUTOMATIC) CanIfTxTargetPduId,
                                                    P2VAR(PduIdType, AUTOMATIC, CANIF_APPL_CONST) CanIfTxPduIdPtr
                                                    )

{
    VAR (uint16_least, AUTOMATIC) CanIf_TotalTxPduId;
    VAR (PduIdType,AUTOMATIC) PduIdx_Temp;
    VAR (Std_ReturnType,AUTOMATIC) Ret_Val = E_NOT_OK;
    /* Pointer to Tx Pdu configuration */
    P2CONST(CanIf_TxPduInfo, AUTOMATIC, AUTOMATIC)TxPduConfigptr_Temp;

    /* If CanIfTxPduIdPtr is null, report to DET and return E_NOT_OK */
    CANIF_DET_REPORT_ERROR_NOK((NULL_PTR == CanIfTxPduIdPtr), CANIF_RETURN_TX_PDU_ID_SID,CANIF_E_PARAM_POINTER)

    #if(CANIF_VARIANT_INFO == 1)
    CanIf_TotalTxPduId = (uint16_least)CANIF_NUM_STATIC_CANTXPDUIDS + (uint16_least)CANIF_NUM_DYNAMIC_CANTXPDUIDS;
    TxPduConfigptr_Temp = CanIf_TxPduConfig;
    #else
    CanIf_TotalTxPduId = (CanIf_ConfigSetPtr->NumCanTxPduId) + (CanIf_ConfigSetPtr->NumDynamicCanTxPduId);
    TxPduConfigptr_Temp = CanIf_ConfigSetPtr->TxPduConfig;
    #endif

    for(PduIdx_Temp=0; PduIdx_Temp<CanIf_TotalTxPduId; PduIdx_Temp++)
    {
        if((TxPduConfigptr_Temp[PduIdx_Temp].TargetTxPduId==CanIfTxTargetPduId) && (TxPduConfigptr_Temp[PduIdx_Temp].TxUser==USER))
        {
            *CanIfTxPduIdPtr = TxPduConfigptr_Temp[PduIdx_Temp].CanTxPduId;
            Ret_Val = E_OK;
            break;
        }

    }
    return Ret_Val;
}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

/*
 ***************************************************************************************************
 * used functions
 ***************************************************************************************************
 */
/****************************************************************************************************************/
/* Function name    : CanIf_ReturnRxPduId                                                                       */
/* Syntax           : FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReturnRxPduId(
                                                     VAR(PduIdType, AUTOMATIC) CanIfRxTargetPduId,
                                                    P2VAR(PduIdType, AUTOMATIC, AUTOMATIC) CanIfRxPduIdPtr
                                                    )   */
/* Description      : Service that retutrns the PduId when the Target PduId is given.                                                             */
/* Parameter        : CanIfRxTargetPduId, CanIfRxPduIdPtr                                                                   */
/* Return value     : E_OK / E_NOT_OK                                                                           */
/****************************************************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_ReturnRxPduId: Function contains very simple "else if" statements and "switch-cases". HIS metric compliance would decrease readability and maintainability. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReturnRxPduId(
                                                     VAR(PduIdType, AUTOMATIC) CanIfRxTargetPduId,
                                                    P2VAR(PduIdType, AUTOMATIC, AUTOMATIC) CanIfRxPduIdPtr
                                                    )

{
    VAR (uint16_least, CANIF_CONST) CanIf_Num_CanRxPduId;
    VAR (PduIdType,AUTOMATIC) PduIdx_Temp;
    VAR (Std_ReturnType,AUTOMATIC) Ret_Val = E_NOT_OK;
    /* Pointer to Rx Pdu configuration */
    P2CONST(CanIf_RxPduConfigType, AUTOMATIC, CANIF_CFG_CONST) RxPduCfgptr_pcs;

    /* If CanIfRxPduIdPtr is null, report to DET and return E_NOT_OK */
     CANIF_DET_REPORT_ERROR_NOK((NULL_PTR == CanIfRxPduIdPtr), CANIF_RETURN_RX_PDU_ID_SID,CANIF_E_PARAM_POINTER)

    #if(CANIF_VARIANT_INFO == 1)
    CanIf_Num_CanRxPduId = CANIF_NUM_CANRXPDUIDS;
    RxPduCfgptr_pcs = CanIf_RxPduConfig;
    #else
    CanIf_Num_CanRxPduId = CanIf_ConfigSetPtr->NumCanRxPduId;
    RxPduCfgptr_pcs = CanIf_ConfigSetPtr->RxPduConfig;
    #endif

    for( PduIdx_Temp=0;  PduIdx_Temp<CanIf_Num_CanRxPduId;  PduIdx_Temp++)
    {
        if((RxPduCfgptr_pcs[PduIdx_Temp].TargetRxPduId==CanIfRxTargetPduId) && (RxPduCfgptr_pcs[PduIdx_Temp].User==USER))
        {
            *CanIfRxPduIdPtr = RxPduCfgptr_pcs[PduIdx_Temp].RxPduId;
            Ret_Val = E_OK;
            break;
        }

    }
    return Ret_Val;
}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

/* FC_FileVariationPoint_END */


