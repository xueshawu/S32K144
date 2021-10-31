

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
/*******************************************************************************************************************************************************************/
/* Function name    : CanIf_SearchRxPduId
   Syntax           : FUNC(PduIdType, CANIF_CODE) CanIf_SearchRxPduId(P2CONST(CanIf_RxPduConfigType, AUTOMATIC, CANIF_CONST) CanIf_RxPduConfigPtr,
                                                                      VAR(PduIdType, AUTOMATIC) CanRxPduId,
                                                                      P2VAR(uint8, AUTOMATIC, CANIF_APPL_CONST) SearchStatusPtr)
 Description      : This function searches for CanRxPduId in the CanIf_RxPduConfigPtr table and returns the index of the searched element.Also, updates the SearchStatusPtr
                    as 0 if search is successful else updates it as 0xFF
 Parameter        : CanIf_RxPduConfigPtr, CanRxPduId, SearchStatusPtr
 Return value     : Index of the searched element in the CanIf_RxPduConfig table

 Notes:
 - This is a Non-AUTOSAR function.
********************************************************************************************************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

FUNC(PduIdType, CANIF_CODE) CanIf_SearchRxPduId(P2CONST(CanIf_RxPduConfigType, AUTOMATIC, CANIF_CONST) CanIf_RxPduConfigPtr,
                                                VAR(uint16, AUTOMATIC) CanIf_Num_Elements,
                                                VAR(PduIdType, AUTOMATIC) CanRxPduId,
                                                P2VAR(uint8, AUTOMATIC, CANIF_APPL_CONST) SearchStatusPtr)
{
    /* Pointer to Rx Pdu configuration */
    P2CONST(CanIf_RxPduConfigType, AUTOMATIC, CANIF_CFG_CONST) RxPduCfg_pcs;

    VAR(PduIdType, AUTOMATIC) index;

    /* Initialize as search failed */
    *SearchStatusPtr = 0xFF;

    for(index = 0; index < CanIf_Num_Elements; index++)
    {
        RxPduCfg_pcs = CanIf_RxPduConfigPtr + index;
        if(RxPduCfg_pcs->RxPduId == CanRxPduId)
        {
            *SearchStatusPtr = 0;
            break;
        }
    }

    return index;

}

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


/************************************************************************************************************/
/* Function name    : CanIf_ReadTxMsgId                                                                     */
/* Syntax           : FUNC(uint32, CANIF_CODE) CanIf_ReadTxMsgId( VAR(uint16,AUTOMATIC) msgHandleTx_u16 )   */
/* Description      : This function is used to get the message identifier configured in message             */
/*                    configuration table (HOH table of CanDriver).                                         */
/* Parameter        : msgHandleTx_u16                                                                       */
/* Return value     : Configured CanID for the given HOH handle                                             */
/************************************************************************************************************/
#if (CANIF_READMSGID_API != STD_OFF)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

FUNC(uint32, CANIF_CODE) CanIf_ReadTxMsgId( VAR(uint16, AUTOMATIC) msgHandleTx_u16 )
{
    /* Pointer to Tx Pdu configuration */
    P2CONST(CanIf_TxPduInfo, AUTOMATIC, CANIF_CFG_CONST) TxPduConfigTable_Temp;

    /* Pointer to Tx Pdu configuration */
    P2CONST(CanIf_TxPduInfo, AUTOMATIC, CANIF_CFG_CONST) TxPduConfig_pcs;

    VAR(CanIf_CanIdType, AUTOMATIC) CanId;

    VAR(PduIdType, AUTOMATIC) index;

    VAR (uint16_least, AUTOMATIC) CanIf_TotalTxPdus;


    CanId = 0;

    #if(CANIF_VARIANT_INFO == 1)
    TxPduConfigTable_Temp = CanIf_TxPduConfig;
    CanIf_TotalTxPdus = CANIF_NUM_STATIC_CANTXPDUIDS + CANIF_NUM_DYNAMIC_CANTXPDUIDS;
    #else
    TxPduConfigTable_Temp = CanIf_ConfigSetPtr->TxPduConfig;
    CanIf_TotalTxPdus = (CanIf_ConfigSetPtr->NumCanTxPduId) + (CanIf_ConfigSetPtr->NumDynamicCanTxPduId);
    #endif

    for(index = 0; index < CanIf_TotalTxPdus; index++)
    {
        TxPduConfig_pcs = TxPduConfigTable_Temp + index;
        if( (uint16)(TxPduConfig_pcs->HthRefId) == msgHandleTx_u16 )
        {
            #if (CANIF_CALIBRATION == STD_ON)
            CanId = TxPduConfig_pcs->getCanId();
            #else
            CanId = TxPduConfig_pcs->CanId;
            #endif

            break;
        }
    }

    /* CanIf_CanIdType will be 32-bits if Extended CanID is supported, else it will be 16-bits.
     * But, the caller always wants the MsgId to be returned as 32-bits.
     * So, typecasting to 32-bits before returning. */
    return ( (uint32)CanId );

}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif



/************************************************************************************************************/
/* Function name    : CanIf_ReadRxMsgId                                                                     */
/* Syntax           : FUNC(uint32, CANIF_CODE) CanIf_ReadRxMsgId( VAR(uint16,AUTOMATIC) msgHandleRx_u16 )   */
/* Description      : This function is used to get the message identifier configured in message             */
/*                    configuration table (HOH table of CanDriver).                                         */
/* Parameter        : msgHandleRx_u16                                                                       */
/* Return value     : Configured CanID for the given HOH handle                                             */
/************************************************************************************************************/
#if (CANIF_READMSGID_API != STD_OFF)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

FUNC(uint32, CANIF_CODE) CanIf_ReadRxMsgId( VAR(uint16, AUTOMATIC) msgHandleRx_u16 )
{
    /* Pointer to HRH table */
    P2CONST(CanIf_HrhConfigType, AUTOMATIC, CANIF_CFG_CONST) HrhCfgTable_Temp;

    /* Pointer to HRH configuration */
    P2CONST(CanIf_HrhConfigType, AUTOMATIC, CANIF_CFG_CONST) HrhCfg_pcs;

    VAR(CanIf_CanIdType, AUTOMATIC) CanId;

    VAR(uint16, AUTOMATIC) index;

    VAR(uint16,AUTOMATIC) Num_Hrh_Handles_Temp;


    CanId = 0;

    #if(CANIF_VARIANT_INFO == 1)
    HrhCfgTable_Temp = CanIf_HrhConfig;
    Num_Hrh_Handles_Temp = CANIF_NUM_HRH_HANDLES;
    #else
    HrhCfgTable_Temp = CanIf_ConfigSetPtr->HrhConfig;
    Num_Hrh_Handles_Temp = CanIf_ConfigSetPtr->NumHrhHandles;
    #endif

    for(index = 0; index < Num_Hrh_Handles_Temp; index++)
    {
        HrhCfg_pcs = HrhCfgTable_Temp + index;
        if( (uint16)(HrhCfg_pcs->CanHardwareObjectHandle) == msgHandleRx_u16 )
        {
            #if (CANIF_CALIBRATION == STD_ON)
            CanId = HrhCfg_pcs->getCanId();
            #else
            CanId = HrhCfg_pcs->CanId;
            #endif
            break;
        }
    }

    /* CanIf_CanIdType will be 32-bits if Extended CanID is supported, else it will be 16-bits.
     * But, the caller always wants the MsgId to be returned as 32-bits.
     * So, typecasting to 32-bits before returning. */
    return ( (uint32)CanId );

}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif



