

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
/* Function name    : CanIf_ResetDynamicTxId                                                                    */
/* Syntax           : FUNC(void, CANIF_CODE) CanIf_ResetDynamicTxId(VAR(PduIdType, AUTOMATIC) CanTxPduId        */
/* Description      : This service reconfigures the corresponding Static CanId of the requested CAN L-PDU.      */
/* Parameter        : CanTxPduId                                                                                */
/* Return value     : None                                                                                      */
/****************************************************************************************************************/


#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_ResetDynamicTxId: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(void, CANIF_CODE) CanIf_ResetDynamicTxId(VAR(PduIdType, AUTOMATIC) CanTxPduId)
{
#if ((CANIF_SETDYNAMICTXID_API != STD_OFF) && (CANIF_DYNAMIC_ID != STD_OFF))
    P2CONST(CanIf_TxPduInfo, AUTOMATIC, CANIF_CFG_CONST) TxPduConfig_Temp;

    VAR(CanIf_CanIdType, AUTOMATIC) LdCanIdType;

    VAR (uint16_least, AUTOMATIC) CanIf_TotalTxPduId;

    P2VAR(uint32,AUTOMATIC,AUTOMATIC) DynIdPtr_Temp;
    /* Local pointer to cust id look up table */
#if(CANIF_VARIANT_INFO == 2) || (CANIF_VARIANT_INFO == 3)
    const PduIdType (*TxPduId_CustId_LUT_Temp)[CANIF_TOTAL_CFG_SETS];
#endif

    /* If CAN Interface is uninitialized, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR((FALSE == CanIf_Init_Flag), CANIF_RESET_DYNAMIC_TXID_SID,CANIF_E_UNINIT)

#if(CANIF_VARIANT_INFO == 1)
    TxPduConfig_Temp = CanIf_TxPduConfig;
    CanIf_TotalTxPduId = (uint16_least)CANIF_NUM_STATIC_CANTXPDUIDS + (uint16_least)CANIF_NUM_DYNAMIC_CANTXPDUIDS;
    DynIdPtr_Temp = CanIf_Dynamic_CanTxPdu_CanId;

#else
    TxPduId_CustId_LUT_Temp = CanIf_ConfigSetPtr->CanIf_TxPduId_CustId_LUT_ptr ;
    CanIf_TotalTxPduId = CanIf_ConfigSetPtr->NumCanTxPduId + CanIf_ConfigSetPtr->NumDynamicCanTxPduId;
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

    CanTxPduId = TxPduId_CustId_LUT_Temp[CanTxPduId][CanIf_ActiveCfgSet];
    TxPduConfig_Temp = CanIf_ConfigSetPtr->TxPduConfig;
    CanIf_TotalTxPduId = CanIf_ConfigSetPtr->NumCanTxPduId + CanIf_ConfigSetPtr->NumDynamicCanTxPduId;
    DynIdPtr_Temp = CanIf_ConfigSetPtr->DynTxIdPtr;
#endif

    /* Initialize pointer to Tx L-PDU structure
     * Get the location by using the Base address of the Tx-Pdu structure*/
    #if(CANIF_VARIANT_INFO == 1)
    TxPduConfig_Temp = CanIf_TxPduConfig + CanTxPduId;
    #else
    TxPduConfig_Temp = (CanIf_ConfigSetPtr->TxPduConfig) +CanTxPduId;
    #endif

    /* If CanTxPduId is invalid, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR(((CanTxPduId >= CanIf_TotalTxPduId) || (CANIF_STATIC == TxPduConfig_Temp->CanTxPduIdType)),
                                                                    CANIF_RESET_DYNAMIC_TXID_SID,CANIF_E_PARAM_LPDU)

    /* Check if the CanTxPduId is configured as Dynamic.
     * Esnure that the config set has dynamic Ids configured and hence 'DynIdPtr_Temp' is not NULL_PTR*/
    if((TxPduConfig_Temp->CanTxPduIdType != CANIF_STATIC)&&(DynIdPtr_Temp != NULL_PTR))
    {
        /* Enter Critical Section */
        SchM_Enter_CanIf_DynIdNoNest();

        /* Update the new CanId in the global array */
        /* FC_VariationPoint_START */
        #if (CANIF_CALIBRATION == STD_ON)
        LdCanIdType = (TxPduConfig_Temp->getCanId());
        #else
        LdCanIdType = (TxPduConfig_Temp->CanId);
        #endif
        LdCanIdType &= CANIF_MSB_BIT_RESET;
        LdCanIdType |= (((Can_IdType)(TxPduConfig_Temp->CanIdType))<<CANIF_CANID_BIT_SHIFT);
        *(DynIdPtr_Temp + (TxPduConfig_Temp->CanTxPduIdType)) = LdCanIdType;
        /* FC_VariationPoint_END */

        /* Leave Critical Section */
        SchM_Exit_CanIf_DynIdNoNest();
    }
#else
    (void)CanTxPduId;
#endif
} /* End of CanIf_ResetDynamicTxId() */

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

/* FC_FileVariationPoint_END */


