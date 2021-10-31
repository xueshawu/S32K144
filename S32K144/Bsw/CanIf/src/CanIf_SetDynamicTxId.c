

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
/* Function name    : CanIf_SetDynamicTxId                                                                      */
/* Syntax           : FUNC(void, CANIF_CODE) CanIf_setDynamicTxId(
                                                                    VAR(PduIdType,AUTOMATIC) CanTxPduId,
                                                                    VAR(Can_IdType,AUTOMATIC) CanId
                                                                  )                                             */
/* Description      : This service reconfigures the corresponding CAN identifier of the requested CAN L-PDU.    */
/* Parameter        : CanTxPduId, CanId                                                                         */
/* Return value     : None                                                                                      */
/****************************************************************************************************************/

/* FC_DeviationPoint_START */
#if ((CANIF_SETDYNAMICTXID_API != STD_OFF) && (CANIF_DYNAMIC_ID != STD_OFF))
/* FC_DeviationPoint_END */

/* FC_CODE_START */
 //#if ((CANIF_SETDYNAMICTXID_API != STD_OFF) )
/* FC_CODE_END */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_SetDynamicTxId: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(void, CANIF_CODE) CanIf_SetDynamicTxId(
                                             VAR(PduIdType,AUTOMATIC) CanTxPduId,
                                             VAR(Can_IdType,AUTOMATIC) CanId
                                           )
{
     /* Pointer to Tx Pdu configuration */
    P2CONST(CanIf_TxPduInfo, AUTOMATIC, CANIF_CFG_CONST) TxPduConfig_Temp;

    VAR (uint16_least, AUTOMATIC) CanIf_TotalTxPduId;

    P2VAR(uint32,AUTOMATIC,AUTOMATIC) DynIdPtr_Temp;
    /* Local pointer to cust id look up table */
#if(CANIF_VARIANT_INFO == 2) || (CANIF_VARIANT_INFO == 3)
    const PduIdType (*TxPduId_CustId_LUT_Temp)[CANIF_TOTAL_CFG_SETS];
#endif

    /* Local variable to store two MSB's */
      VAR(uint8, AUTOMATIC)canifMSBbits_u8;

    /* If CAN Interface is uninitialized, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR((FALSE == CanIf_Init_Flag), CANIF_SET_DYNAMIC_TXID_SID,CANIF_E_UNINIT)

    #if(CANIF_VARIANT_INFO == 1)
    CanIf_TotalTxPduId = (uint16_least)CANIF_NUM_STATIC_CANTXPDUIDS + (uint16_least)CANIF_NUM_DYNAMIC_CANTXPDUIDS;
    TxPduConfig_Temp = CanIf_TxPduConfig;
    DynIdPtr_Temp = CanIf_Dynamic_CanTxPdu_CanId;
    #else
    CanIf_TotalTxPduId = CanIf_ConfigSetPtr->NumCanTxPduId + CanIf_ConfigSetPtr->NumDynamicCanTxPduId;
    TxPduConfig_Temp = CanIf_ConfigSetPtr->TxPduConfig;
    DynIdPtr_Temp = CanIf_ConfigSetPtr->DynTxIdPtr;
    TxPduId_CustId_LUT_Temp = CanIf_ConfigSetPtr->CanIf_TxPduId_CustId_LUT_ptr ;

    /* First check if the parametre passed ie the Tx-PduId is a valid one or not. This check is required to avoid "Fencepost error"
     * in CanIf_TxPduId_CustId_LUT[][]*/
    if(CanTxPduId < CanIf_ConfigSetPtr->Num_custid_entries)
    {
        /* If valid, get the Cust Id and put it in 'CanTxPduId'.
         * Cust Id is required since the CanIf_TxPduConfig[] is arranged as per CustId*/
        CanTxPduId = TxPduId_CustId_LUT_Temp[CanTxPduId][CanIf_ActiveCfgSet];

        /*Return if the CustId  == CANIF_TOTAL_TXPDUS, since it means the Tx-Pdu is
         * not present in the active configset*/
        if(CanTxPduId == CanIf_TotalTxPduId)
        {
            return;
        }
    }
    else
    {
        /*Else return*/
        return;
    }
    #endif

    /* If CanTxPduId is invalid, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR((CanTxPduId >= CanIf_TotalTxPduId), CANIF_SET_DYNAMIC_TXID_SID,CANIF_E_INVALID_TXPDUID)

    /* Initialize pointer to Tx L-PDU structure
     * Get the pointer from base address*/
    #if(CANIF_VARIANT_INFO == 1)
    TxPduConfig_Temp = CanIf_TxPduConfig + CanTxPduId;
    #else
    TxPduConfig_Temp = (CanIf_ConfigSetPtr->TxPduConfig) + CanTxPduId;
    #endif
    /*shifting the canid bits to access two MSB's */
    /* MR12 RULE 12.2, VIOLATION Warning is "Not Critical" :The left operand of shift operator is lower in size compared to right operand, as the left operand is only used to store two bits for which unit8 is sufficient  */
        canifMSBbits_u8= (uint8)(CanId>>CANIF_CANID_BIT_SHIFT);

    /* If CanTxPduId is invalid, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR((CANIF_STATIC == TxPduConfig_Temp->CanTxPduIdType),
                                                         CANIF_SET_DYNAMIC_TXID_SID,CANIF_E_INVALID_TXPDUID)

    /* If CanId is invalid, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR((((canifMSBbits_u8 == CANIF_ZERO)||(canifMSBbits_u8 == CANIF_ONE)) && ((CanId & CANIF_MSB_BIT_RESET) > CANIF_CAN_STD_VAL)),
                                CANIF_SET_DYNAMIC_TXID_SID, CANIF_E_PARAM_CANID)

    CANIF_DET_REPORT_ERROR((((canifMSBbits_u8 == CANIF_TWO)||(canifMSBbits_u8 == CANIF_THREE)) && ((CanId & CANIF_MSB_BIT_RESET)  > CANIF_CAN_XTD_VAL)),
                                CANIF_SET_DYNAMIC_TXID_SID, CANIF_E_PARAM_CANID)


    /* Check if the CanTxPduId is configured as Dynamic */
    if((TxPduConfig_Temp->CanTxPduIdType != CANIF_STATIC) && (DynIdPtr_Temp != NULL_PTR))
    {
        /* Enter Critical Section */
        SchM_Enter_CanIf_DynIdNoNest();

        /* Update the new CanId in the global array */
        *(DynIdPtr_Temp + (TxPduConfig_Temp->CanTxPduIdType)) = CanId;

        /* Leave Critical Section */
        SchM_Exit_CanIf_DynIdNoNest();
    }
} /* End of CanIf_SetDynamicTxId() */

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif

/* FC_VariationPoint_START */

/* FC_VariationPoint_END */
