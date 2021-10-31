

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
/****************************************************************************************************************************************/
/* Function name    : CanIf_Get_DirectHw_Info                                                                        */
/* Syntax           : FUNC(Std_ReturnType, CANIF_CODE) CanIf_Get_DirectHw_Info (VAR(PduIdType, AUTOMATIC) CanTxPduId,
                                                                 P2VAR(rba_CanDirectHWInfo_o, AUTOMATIC, CANIF_APPL_DATA) hw_info_po
                                                                )   */
/* Description      : This function returns the needed info for the HW direct access to CAN.
                      Extract the PDU handle from CanIf configuration structure (variant dependent)
                      Then call rba_Can_Get_DirectHw_Info() to fill further information in the info structure.   */
/* Parameter        : CanTxPduId, hw_info_pco                                                                */
/* Return value     : E_OK / E_NOT_OK                                                                       */
/****************************************************************************************************************************************/

#if (CANIF_DIRECT_HW_WRITE == STD_ON)

#define CANIF_START_SEC_CODE_FAST
#include "CanIf_MemMap.h"
/* HIS METRIC COMF VIOLATION IN CanIf_Get_DirectHw_Info: Function contains very simple "else if" statements and "switch-cases". HIS metric compliance would decrease readability and maintainability. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_Get_DirectHw_Info (VAR(PduIdType, AUTOMATIC) CanTxPduId,
                                                          P2VAR(rba_CanDirectHWInfo_o, AUTOMATIC, CANIF_APPL_DATA) hw_info_po

                                                                )
{
    /* Pointer to Tx Pdu configuration */
    P2CONST(CanIf_TxPduInfo, AUTOMATIC, CANIF_CFG_CONST) TxPduConfig_Temp;
    /* Local pointer to cust id look up table */
#if(CANIF_VARIANT_INFO == 2) || (CANIF_VARIANT_INFO == 3)
    const PduIdType (*TxPduId_CustId_LUT_Temp)[CANIF_TOTAL_CFG_SETS];
    VAR (uint16_least, AUTOMATIC) CanIf_TotalTxPduId;
#endif

    VAR(Can_PduType,AUTOMATIC) PduInfo_Write;
    VAR(Std_ReturnType,AUTOMATIC) Status;
    /* FC_VariationPoint_START */
   #if (CANIF_DYNAMIC_ID != STD_OFF)
    /* FC_VariationPoint_END */
    P2VAR(uint32,AUTOMATIC,AUTOMATIC) DynIdPtr_Temp;
   #endif

    /*Initialise the return value*/
    Status = E_NOT_OK;

   #if(CANIF_VARIANT_INFO == 1)
    TxPduConfig_Temp = CanIf_TxPduConfig;
    /* FC_VariationPoint_START */
        #if (CANIF_DYNAMIC_ID != STD_OFF)
        /* FC_VariationPoint_END */
        DynIdPtr_Temp = CanIf_Dynamic_CanTxPdu_CanId;
        #endif

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

        /*Return E_NOT_OK if the CustId  = CANIF_TOTAL_TXPDUS, since it means the Tx-Pdu is
         * not present in the active configset*/
        if(CanTxPduId == CanIf_TotalTxPduId)
        {
            return (Status);
        }
    }
    else
    {
        /*Else return E_NOT_OK*/
        return (Status);
    }
    TxPduConfig_Temp = CanIf_ConfigSetPtr->TxPduConfig;
    /* FC_VariationPoint_START */
    #if (CANIF_DYNAMIC_ID != STD_OFF)
     /* FC_VariationPoint_END */
    DynIdPtr_Temp = CanIf_ConfigSetPtr->DynTxIdPtr;
    #endif

   #endif

   #if(CANIF_VARIANT_INFO == 1)
    TxPduConfig_Temp = (CanIf_TxPduConfig + CanTxPduId);
    #else
    TxPduConfig_Temp = ((CanIf_ConfigSetPtr->TxPduConfig) + CanTxPduId);
   #endif

   /*Get the L-PDU handle info from TxPduInfo*/
    hw_info_po->swPduHandle = TxPduConfig_Temp->CanTxPduId;
    hw_info_po->Handle_uo = TxPduConfig_Temp->HthRefId;

    /* Get the Sdu Handle*/
    PduInfo_Write.swPduHandle = hw_info_po->swPduHandle;

    #if (CANIF_DYNAMIC_ID != STD_OFF)
    /* Check if the CanTxPduId is configured as Dynamic */
    if((TxPduConfig_Temp->CanTxPduIdType != CANIF_STATIC) && (DynIdPtr_Temp != NULL_PTR))
    {
        PduInfo_Write.id = (Can_IdType)*(DynIdPtr_Temp + (TxPduConfig_Temp->CanTxPduIdType));
    }
    else
    #endif
    {
        /* Get the CAN ID from Can Tx pdu info to outgoing CAN Message structure */
        #if (CANIF_CALIBRATION == STD_ON)
            PduInfo_Write.id = (Can_IdType)((TxPduConfig_Temp->getCanId()));
        #else
            PduInfo_Write.id = (Can_IdType)((TxPduConfig_Temp->CanId));
        #endif

        /* FC_VariationPoint_START */
        /* setting two most significant bit based on CanIdType */
            PduInfo_Write.id &= CANIF_MSB_BIT_RESET;
            PduInfo_Write.id |= (((Can_IdType)(TxPduConfig_Temp->CanIdType))<<CANIF_CANID_BIT_SHIFT);
        /* FC_VariationPoint_END*/
    }

    /*Call rba_Can_Get_DirectHw_Info()*/
    Status = rba_Can_Get_DirectHw_Info(TxPduConfig_Temp->HthRefId, &PduInfo_Write, hw_info_po);

    return (Status);
}
#define CANIF_STOP_SEC_CODE_FAST
#include "CanIf_MemMap.h"

#endif

/* FC_FileVariationPoint_END */


