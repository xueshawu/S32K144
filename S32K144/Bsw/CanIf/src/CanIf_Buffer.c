

/****************************************************************************************************/
/*                                  Include Section                                                 */
/****************************************************************************************************/

#include "CanIf_Priv.h"

/*
 ***************************************************************************************************
 * used functions
 ***************************************************************************************************
 */

/*****************************************************************************************************************/
/* Function name    : CanIf_ClearBuffer                                                                          */
/* Syntax           : FUNC(void, CANIF_CODE) CanIf_ClearBuffer(
                                                                VAR(uint8, AUTOMATIC) Controller,
                                                                VAR(CanIf_BufferType, AUTOMATIC) BufferType)     */
/* Description      : Service called by CanIf to clear the transmit/ receive buffer                              */
/* Parameter        : Controller, BufferType                                                                     */
/* Return value     : None                                                                                       */
/*****************************************************************************************************************/
/* FC_DeviationPoint_START */
#if ((CANIF_TRANSMIT_BUFFER != STD_OFF) || (CANIF_RECEIVE_BUFFER != STD_OFF))
/* FC_DeviationPoint_END */

/* FC_CODE_START */
//#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF) || (CANIF_READRXPDU_DATA_API != STD_OFF)
/* FC_CODE_END */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
 /* HIS METRIC v(G),LEVEL VIOLATION IN CanIf_ClearBuffer: Function contains very simple "else if" statements and "switch-cases". HIS metric compliance would decrease readability and maintainability. */
FUNC(void, CANIF_CODE) CanIf_ClearBuffer(
                                            VAR(uint8, AUTOMATIC) Controller,
                                            VAR(CanIf_BufferType, AUTOMATIC) BufferType
                                        )
{
    /* FC_DeviationPoint_START */
    #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
    /*  FC_CODE_END */
    /* Pointer to Tx Pdu configuration */
    P2CONST(CanIf_TxPduInfo, AUTOMATIC, AUTOMATIC) TxPduCfg_pcs;

    /*Tx-buffer pointer*/
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)TxBuffPtr_Temp;

    VAR (uint16_least, AUTOMATIC) CanIf_TotalTxPduId;

    /*Temp variable to hold the status of CanIf_HTHBusyStatusFlag_a_b[]*/
    P2VAR(boolean, AUTOMATIC, AUTOMATIC) HTHStatusPtr_Temp;

    P2VAR(boolean, AUTOMATIC, AUTOMATIC) TxBuffAllocPtr_Temp;
    #endif

    /* FC_DeviationPoint_START */
    #if (CANIF_RECEIVE_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if (CANIF_READRXPDU_DATA_API != STD_OFF)
    /* FC_CODE_END */
    /* Pointer to Rx Pdu configuration */
    P2CONST(CanIf_RxPduConfigType, AUTOMATIC, AUTOMATIC) RxPduCfg_pcs;

    /* Pointer to HRH configuration */
    P2CONST(CanIf_HrhConfigType, AUTOMATIC, AUTOMATIC) HrhCfg_pcs;

    /*Tx-buffer pointer*/
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)RxBuffPtr_Temp;

    VAR (uint16_least, AUTOMATIC) CanIf_Num_CanRxPduId;
    #endif

    /* Store the offset of Buffer */
    VAR(uint16_least, AUTOMATIC) BufferIdx_u16;

    /* Byte position in the buffer */
    VAR(uint16_least, AUTOMATIC) Index_u16;

    /* Variable used as index inside for loop */
    VAR(PduIdType, AUTOMATIC) PduIdIndex_u;


    /*For PRE-COMPILE*/
#if(CANIF_VARIANT_INFO == 1)
    /* FC_DeviationPoint_START */
    #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
    /*  FC_CODE_END */
    TxPduCfg_pcs = CanIf_TxPduConfig;
    TxBuffPtr_Temp = CanIf_TxBuffer;

    /*Initialise 'CanIf_TotalTxPduId'*/
    CanIf_TotalTxPduId = (uint16_least)CANIF_NUM_STATIC_CANTXPDUIDS + (uint16_least)CANIF_NUM_DYNAMIC_CANTXPDUIDS;

    /*Initialise HTHStatusPtr_Temp with the appropriate HTH Flag array*/
    HTHStatusPtr_Temp = CanIf_HTHBusyStatusFlag_a_b;

    TxBuffAllocPtr_Temp = CanIf_TxBufferAllocated;
    #endif

    /* FC_DeviationPoint_START */
    #if (CANIF_RECEIVE_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if (CANIF_READRXPDU_DATA_API != STD_OFF)
    /* FC_CODE_END */
    RxPduCfg_pcs = CanIf_RxPduConfig;
    HrhCfg_pcs = CanIf_HrhConfig;
    RxBuffPtr_Temp = CanIf_RxBuffer;

    /*Initialise 'CanIf_Num_CanRxPduId'*/
    CanIf_Num_CanRxPduId = CANIF_NUM_CANRXPDUIDS;
    #endif



    /*For POST-BUILD*/
#else
    /* FC_DeviationPoint_START */
    #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
    /*  FC_CODE_END */
    TxPduCfg_pcs = CanIf_ConfigSetPtr->TxPduConfig;
    TxBuffPtr_Temp =CanIf_ConfigSetPtr->TxBufferPtr;

    /*Initialise 'CanIf_TotalTxPduId'*/
    CanIf_TotalTxPduId = CanIf_ConfigSetPtr->NumCanTxPduId + CanIf_ConfigSetPtr->NumDynamicCanTxPduId;

    /*Initialise HTHStatusPtr_Temp with the appropriate HTH Flag array*/
    HTHStatusPtr_Temp = CanIf_ConfigSetPtr->HTHStatusFlagPtr;
    TxBuffAllocPtr_Temp = CanIf_ConfigSetPtr->TxBufferAllocPtr;
    #endif

    /* FC_DeviationPoint_START */
    #if (CANIF_RECEIVE_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if (CANIF_READRXPDU_DATA_API != STD_OFF)
    /* FC_CODE_END */
    RxPduCfg_pcs = CanIf_ConfigSetPtr->RxPduConfig;
    HrhCfg_pcs = CanIf_ConfigSetPtr->HrhConfig;
    RxBuffPtr_Temp = CanIf_ConfigSetPtr->RxBufferPtr;

    /*Initialise 'CanIf_Num_CanRxPduId'*/
    CanIf_Num_CanRxPduId = CanIf_ConfigSetPtr->NumCanRxPduId;
    #endif

#endif/*CANIF_VARIANT_INFO*/


    if( BufferType == CANIF_TRANSMIT )
    {
        /* FC_DeviationPoint_START */
        #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
        /* FC_DeviationPoint_END */

        /* FC_CODE_START */
        //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
        /*  FC_CODE_END */
        if( TxBuffPtr_Temp != NULL_PTR )
        {
            for( PduIdIndex_u = 0; (PduIdIndex_u < CanIf_TotalTxPduId); PduIdIndex_u++ )
            {
                /* Initialize pointer to Tx L-PDU structure */
                //TxPduCfg_pcs = CanIf_TxPduConfig + PduIdIndex_u;

                /* Check whether the Controller matches */
                if( (TxPduCfg_pcs +PduIdIndex_u)->ControllerRefId == Controller )
                {
                    /* using the id get the index from the LUT */
                    BufferIdx_u16 = (TxPduCfg_pcs +PduIdIndex_u)->TxBufferOffset;

                    /* If the Tx Buffer Offset is valid */
                    if(BufferIdx_u16 != CANIF_MAX_BUFFER_OFFSET)
                    {
                        /*Enter Critical Section */
                        SchM_Enter_CanIf_TxBufAccessNoNest();

                        /*Clear the HTH Status flags of the BASIC CAN HTHs "belonging to this controller", else the communication may not resume for those HTHs*/
                        /*Clear the corresponding HTH Status flag and the Tx-buffer flag*/
                        if(HTHStatusPtr_Temp != NULL_PTR)
                        {
                            HTHStatusPtr_Temp[(TxPduCfg_pcs +PduIdIndex_u)->HTHStatusFlagIdx] = FALSE;
                        }

                        if(TxBuffAllocPtr_Temp != NULL_PTR)
                        {
                            TxBuffAllocPtr_Temp[PduIdIndex_u] = FALSE;
                        }

                        /* FC_VariationPoint_START */
                        #if (CANIF_CALIBRATION == STD_ON)
                        #if (CANIF_METADATA_SUPPORT == STD_ON)
                        for(Index_u16 = BufferIdx_u16; Index_u16 <= (BufferIdx_u16 + ((TxPduCfg_pcs +PduIdIndex_u)->getDlc() + (TxPduCfg_pcs + PduIdIndex_u)->MetaDataLength_u32)  ); Index_u16++)
                        #else
                        for(Index_u16 = BufferIdx_u16; Index_u16 <= (BufferIdx_u16 + ((TxPduCfg_pcs +PduIdIndex_u)->getDlc())); Index_u16++)
                        #endif /* (CANIF_METADATA_SUPPORT == STD_ON) */
                        #else
                        #if (CANIF_METADATA_SUPPORT == STD_ON)
                        for(Index_u16 = BufferIdx_u16; Index_u16 <= (BufferIdx_u16 + ((TxPduCfg_pcs +PduIdIndex_u)->Dlc + (TxPduCfg_pcs + PduIdIndex_u)->MetaDataLength_u32)); Index_u16++)
                        #else
                        /* FC_VariationPoint_END */
                        for(Index_u16 = BufferIdx_u16; Index_u16 <= (BufferIdx_u16 + ((TxPduCfg_pcs +PduIdIndex_u)->Dlc)); Index_u16++)
                        /* FC_VariationPoint_START */
                        #endif /* #if (CANIF_METADATA_SUPPORT == STD_ON) */
                        #endif /* #if (CANIF_CALIBRATION == STD_ON) */
                        /* FC_VariationPoint_END */
                        {
                            *(TxBuffPtr_Temp + Index_u16) = 0;
                        }

                        /* Leave Critical Section */
                        SchM_Exit_CanIf_TxBufAccessNoNest();

                    } /* end if(BufferIdx_u16 != CANIF_MAX_BUFFER_OFFSET) */

                } /* end if((TxPduCfg_pcs +PduIdIndex_u)->ControllerRefId == Controller) */

            } /* end for(PduIdIndex_u = 0; (PduIdIndex_u < CanIf_TotalTxPduId); PduIdIndex_u++) */

        } /* end if( TxBuffPtr_Temp != NULL_PTR ) */

        #endif /* end #if (CANIF_TRANSMIT_BUFFER != STD_OFF) */

    } /* end if( BufferType == CANIF_TRANSMIT ) */
    else
    {
        /* FC_DeviationPoint_START */
        #if (CANIF_RECEIVE_BUFFER != STD_OFF)
        /* FC_DeviationPoint_END */

        /* FC_CODE_START */
        //#if (CANIF_READRXPDU_DATA_API != STD_OFF)
        /* FC_CODE_END */

        /*First ensure that the pointer to Rx-buffer is not null*/
        if(RxBuffPtr_Temp != NULL_PTR)
        {
            for(PduIdIndex_u = 0; PduIdIndex_u < CanIf_Num_CanRxPduId; PduIdIndex_u++)
            {
                /* Check whether the controller matches */
                if(((HrhCfg_pcs +((RxPduCfg_pcs + PduIdIndex_u)->HrhRef))->ControllerId) == Controller)
                {
                    /* Get the Rx Buffer Offset */
                    BufferIdx_u16 = (RxPduCfg_pcs + PduIdIndex_u)->RxBufferOffset;

                    /* If the Rx Buffer Offset is valid */
                    if(BufferIdx_u16 != CANIF_MAX_BUFFER_OFFSET)
                    {
                        /*Enter Critical Section */
                        SchM_Enter_CanIf_RxBufAccessNoNest();

                        /* FC_VariationPoint_START */
                        #if (CANIF_CALIBRATION == STD_ON)
                        #if (CANIF_METADATA_SUPPORT == STD_ON)
                        for(Index_u16 = BufferIdx_u16; Index_u16 <= (BufferIdx_u16 + ((RxPduCfg_pcs + PduIdIndex_u)->getDlc()+(RxPduCfg_pcs + PduIdIndex_u)->MetaDataLength_u32)); Index_u16++)
                        #else
                        for(Index_u16 = BufferIdx_u16; Index_u16 <= (BufferIdx_u16 + ((RxPduCfg_pcs + PduIdIndex_u)->getDlc())); Index_u16++)
                        #endif /* #if (CANIF_METADATA_SUPPORT == STD_ON) */
                        #else
                        #if (CANIF_METADATA_SUPPORT == STD_ON)
                        for(Index_u16 = BufferIdx_u16; Index_u16 <= (BufferIdx_u16 + ((RxPduCfg_pcs + PduIdIndex_u)->Dlc+ (RxPduCfg_pcs + PduIdIndex_u)->MetaDataLength_u32)); Index_u16++)
                        #else
                        /* FC_VariationPoint_END */
                        for(Index_u16 = BufferIdx_u16; Index_u16 <= (BufferIdx_u16 + ((RxPduCfg_pcs + PduIdIndex_u)->Dlc)); Index_u16++)
                        /* FC_VariationPoint_START */
                        #endif /* #if (CANIF_METADATA_SUPPORT == STD_ON) */
                        #endif /* #if (CANIF_CALIBRATION == STD_ON) */
                        /* FC_VariationPoint_END */
                        {
                            *(RxBuffPtr_Temp + Index_u16) = 0;
                        }

                        /* Leave Critical Section */
                        SchM_Exit_CanIf_RxBufAccessNoNest();
                    }

                } /* end if(((HrhCfg_pcs +((RxPduCfg_pcs + PduIdIndex_u)->HrhRef))->ControllerId) == Controller) */

            } /* end for(PduIdIndex_u = 0; PduIdIndex_u < CanIf_Num_CanRxPduId; PduIdIndex_u++) */

        } /* end if(RxBuffPtr_Temp != NULL_PTR) */

        #endif /* end #if (CANIF_RECEIVE_BUFFER != STD_OFF) */

    } /* end else of if( BufferType == CANIF_TRANSMIT ) */

} /* end CanIf_ClearBuffer() */
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif

 /* FC_DeviationPoint_START */
#if (CANIF_TRANSMIT_BUFFER != STD_OFF)
     /* FC_DeviationPoint_END */

        /* FC_CODE_START */
//#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
  /*  FC_CODE_END */
/********************************************************************************************************************/
/* Function name  : CanIf_WriteTxBuffer                                                                             */
/* Syntax         : FUNC(void, CANIF_CODE) CanIf_WriteTxBuffer(
                                                      VAR(PduIdType, AUTOMATIC) CanTxPduId,
                                                      P2CONST (PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr
                                                    )                                                               */
/* Description    : Service called by CanIf function - CanIf_Transmit() to write into the transmit buffer           */
/* Parameter      : CanTxPduId, PduInfoPtr                                                                          */
/* Return value   : None                                                                                            */
/********************************************************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE) CanIf_WriteTxBuffer(
                                            VAR(PduIdType, AUTOMATIC) CanTxPduId,
                                            P2CONST (PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr
                                          )
{
    /* Pointer to Tx Pdu configuration */
    P2CONST(CanIf_TxPduInfo, AUTOMATIC, AUTOMATIC ) TxPduCfg_pcs;

    /* Pointer to data */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) PduData_p;

    /* Pointer to Tx Buffer */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) TxBuffer_p;

    /* Byte position in the buffer */
    VAR(uint16_least, AUTOMATIC) Index_u16;

    /* To store the offset of Tx Buffer */
    VAR(uint16_least, AUTOMATIC ) BufferIdx_u16;

    /* To store the offset of Tx Buffer */
    VAR(uint16_least, AUTOMATIC) BufferEndIdx_u16;

    P2VAR(boolean, AUTOMATIC, AUTOMATIC) TxBuffAllocPtr_Temp;

    /*For PRE-COMPILE*/
#if(CANIF_VARIANT_INFO == 1)
    TxPduCfg_pcs = CanIf_TxPduConfig;
    TxBuffer_p = CanIf_TxBuffer;
    TxBuffAllocPtr_Temp = CanIf_TxBufferAllocated;

    /*For POST-BUILD*/
#else
    TxPduCfg_pcs = CanIf_ConfigSetPtr->TxPduConfig;
    TxBuffer_p = CanIf_ConfigSetPtr->TxBufferPtr;
    TxBuffAllocPtr_Temp = CanIf_ConfigSetPtr->TxBufferAllocPtr;
#endif/*CANIF_VARIANT_INFO*/


    /*First ensure that the pointer to Tx-buffer is NOT null*/
    if(TxBuffer_p != NULL_PTR)
    {
        /* Get the data pointer */
        PduData_p = PduInfoPtr->SduDataPtr;

        /* Get the Tx Buffer Offset */
        BufferIdx_u16 = (TxPduCfg_pcs +CanTxPduId)->TxBufferOffset;


        /*Enter Critical Section */
        SchM_Enter_CanIf_TxBufAccessNoNest();

        /* Copy the Dlc */
        *(TxBuffer_p + BufferIdx_u16) = (uint8) PduInfoPtr->SduLength;


        /* Calculate the end of the buffer */
        BufferEndIdx_u16 = BufferIdx_u16 + (PduInfoPtr->SduLength);

        /* Copy the Data */
        for(Index_u16 = (BufferIdx_u16 + (uint16_least)1); Index_u16 <= BufferEndIdx_u16; Index_u16++)
        {
            *(TxBuffer_p +Index_u16) = *PduData_p;
            PduData_p++;
        }

        /* Set the buffer allocation status */
        *(TxBuffAllocPtr_Temp +CanTxPduId) = TRUE;

        /* Leave Critical Section */
        SchM_Exit_CanIf_TxBufAccessNoNest();

    } /* end if(TxBuffer_p != NULL_PTR) */

} /* end CanIf_WriteTxBuffer() */
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

/****************************************************************************************************************/
/* Function name    : CanIf_ClearTxChannelBuffer                                                                */
/* Syntax           : FUNC(void, CANIF_CODE) CanIf_ClearTxChannelBuffer(VAR(uint8, AUTOMATIC) Controller)          */
/* Description      : Service called by CanIf function - CanIf_SetChannelMode() to clear the transmit buffer.   */
/* Parameter        : Controller                                                                                   */
/* Return value     : None                                                                                      */
/****************************************************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC LEVEL VIOLATION IN CanIf_ClearTxChannelBuffer: Function contains very simple "else if" statements. HIS metric compliance would decrease readability and maintainability. */
FUNC(void, CANIF_CODE) CanIf_ClearTxChannelBuffer(VAR(uint8, AUTOMATIC) Controller)
{
    /* Pointer to Tx Pdu configuration */
    P2CONST(CanIf_TxPduInfo, AUTOMATIC,AUTOMATIC) TxPduCfg_pcs;

    /* Byte position in the buffer */
    VAR(uint16_least, AUTOMATIC) Index_u16;

    /* Store the offset of Buffer */
    VAR(uint16_least, AUTOMATIC) BufferIdx_u16;

    /* Variable used as index inside for loop */
    VAR(PduIdType, AUTOMATIC) PduIdIndex_u;

    VAR (uint16_least, AUTOMATIC) CanIf_TotalTxPduId;

    /* Pointer to Tx Buffer */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) TxBuffer_p;


    /*For PRE-COMPILE*/
#if(CANIF_VARIANT_INFO == 1)
    CanIf_TotalTxPduId = (uint16_least)CANIF_NUM_STATIC_CANTXPDUIDS + (uint16_least)CANIF_NUM_DYNAMIC_CANTXPDUIDS;
    TxPduCfg_pcs = CanIf_TxPduConfig;
    TxBuffer_p = CanIf_TxBuffer;

    /*For POST-BUILD*/
#else
    /*Initialise 'CanIf_TotalTxPduId'*/
    CanIf_TotalTxPduId = CanIf_ConfigSetPtr->NumCanTxPduId + CanIf_ConfigSetPtr->NumDynamicCanTxPduId;
    TxPduCfg_pcs = CanIf_ConfigSetPtr->TxPduConfig;
    TxBuffer_p = CanIf_ConfigSetPtr->TxBufferPtr;
#endif/*CANIF_VARIANT_INFO*/

    /*First ensure that the pointer to Tx-buffer is not null*/
    if(TxBuffer_p != NULL_PTR)
    {
        /* Reset the buffers of the Pdus belonging to this channel */
        for(PduIdIndex_u = 0; PduIdIndex_u < CanIf_TotalTxPduId; PduIdIndex_u++)
        {

            /* One Controller corresponds to one Channel */
            if((TxPduCfg_pcs +PduIdIndex_u)->ControllerRefId == Controller)
            {
                /* Get the index from the index table */
                BufferIdx_u16 = (TxPduCfg_pcs+ PduIdIndex_u)->TxBufferOffset;

                /* If the Tx Buffer Offset is valid */
                if(BufferIdx_u16 != CANIF_MAX_BUFFER_OFFSET)
                {
                    /*Enter Critical Section */
                    SchM_Enter_CanIf_TxBufAccessNoNest();

                    /* Reset the buffer */
                    /* FC_VariationPoint_START */
                    #if (CANIF_CALIBRATION == STD_ON)
                    #if (CANIF_METADATA_SUPPORT == STD_ON)
                    for(Index_u16 = BufferIdx_u16 ; Index_u16 <= (BufferIdx_u16 + ((TxPduCfg_pcs+ PduIdIndex_u)->getDlc() + (TxPduCfg_pcs+ PduIdIndex_u)->MetaDataLength_u32)); Index_u16++)
                    #else
                    for(Index_u16 = BufferIdx_u16 ; Index_u16 <= (BufferIdx_u16 + ((TxPduCfg_pcs+ PduIdIndex_u)->getDlc())); Index_u16++)
                    #endif /* #if (CANIF_METADATA_SUPPORT == STD_ON) */
                    #else
                    #if (CANIF_METADATA_SUPPORT == STD_ON)
                    for(Index_u16 = BufferIdx_u16 ; Index_u16 <= (BufferIdx_u16 + ((TxPduCfg_pcs+ PduIdIndex_u)->Dlc + (TxPduCfg_pcs+ PduIdIndex_u)->MetaDataLength_u32)); Index_u16++)
                    #else
                    /* FC_VariationPoint_END */
                    for(Index_u16 = BufferIdx_u16 ; Index_u16 <= (BufferIdx_u16 + ((TxPduCfg_pcs+ PduIdIndex_u)->Dlc)); Index_u16++)
                    /* FC_VariationPoint_START */
                    #endif /* #if (CANIF_METADATA_SUPPORT == STD_ON) */
                    #endif /* #if (CANIF_CALIBRATION == STD_ON) */
                    /* FC_VariationPoint_END */
                    {
                        *(TxBuffer_p + Index_u16) = 0;
                    }

                    /* Leave Critical Section */
                    SchM_Exit_CanIf_TxBufAccessNoNest();
                }

            } /* end if((TxPduCfg_pcs +PduIdIndex_u)->ControllerRefId == Controller) */

        }/* End for(PduIdIndex_u = 0; PduIdIndex_u < CanIf_TotalTxPduId; PduIdIndex_u++) */

    } /* end if(TxBuffer_p != NULL_PTR) */

} /* end CanIf_ClearTxChannelBuffer() */
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif

/* FC_DeviationPoint_START */
#if (CANIF_RECEIVE_BUFFER != STD_OFF)
 /* FC_DeviationPoint_END */

  /* FC_CODE_START */
 //#if (CANIF_READRXPDU_DATA_API != STD_OFF)
 /* FC_CODE_END */
/**********************************************************************************************************************/
/* Function name    : CanIf_WriteRxBuffer                                                                             */
/* Syntax           : FUNC(void, CANIF_CODE) CanIf_WriteRxBuffer(
                                                    P2CONST (uint8, AUTOMATIC, CANIF_APPL_CONST) CanSduPtr,
                                                    P2CONST(CanIf_RxPduConfigType, AUTOMATIC, AUTOMATIC) RxPduCfgPtr
                                                  )                                                                   */
/* Description      : Service called by CanIf function - CanIf_RxIndication() to write data into the receive buffer   */
/* Parameter        : CanSduPtr, RxPduCfgPtr                                                                          */
/* Return value     : None                                                                                            */
/**********************************************************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE) CanIf_WriteRxBuffer(
                                            P2CONST (uint8, AUTOMATIC, CANIF_APPL_CONST) CanSduPtr,
                                            P2CONST(CanIf_RxPduConfigType, AUTOMATIC, CANIF_CFG_CONST) RxPduCfgPtr
                                          )
{
    /* To store the offset of Rx Buffer in RAM */
    VAR(uint16_least, AUTOMATIC) BufferIdx_u16;

    /* Byte position in the Rx buffer */
    VAR(uint16_least, AUTOMATIC) Index_u16;

    /*Tx-buffer pointer*/
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)RxBuffPtr_Temp;

    /*varaiable to hold Sdu length*/
    VAR(uint8, AUTOMATIC) SduLength_u8 = 0;


    /*For PRE-COMPILE*/
#if(CANIF_VARIANT_INFO ==1)
    RxBuffPtr_Temp = CanIf_RxBuffer;

    /*For POST-BUILD*/
#else
    RxBuffPtr_Temp = CanIf_ConfigSetPtr->RxBufferPtr;
#endif/*CANIF_VARIANT_INFO*/


    /* Get the Rx Buffer Offset */
    BufferIdx_u16 = RxPduCfgPtr->RxBufferOffset;

    /* Check if the buffer is allocated */
    if((BufferIdx_u16 != CANIF_MAX_BUFFER_OFFSET) && (RxBuffPtr_Temp != NULL_PTR))
    {
        /* Get the SduLength */

        /* FC_VariationPoint_START */
#if (CANIF_CALIBRATION == STD_ON)
    #if(CANIF_METADATA_SUPPORT == STD_ON)
        SduLength_u8 = (uint8)(RxPduCfgPtr->getDlc()+RxPduCfgPtr->MetaDataLength_u32);
    #else
        SduLength_u8 = (uint8)(RxPduCfgPtr->getDlc());
    #endif /* #if(CANIF_METADATA_SUPPORT == STD_ON) */
#else
    #if(CANIF_METADATA_SUPPORT == STD_ON)
        SduLength_u8 = (uint8)(RxPduCfgPtr->Dlc+RxPduCfgPtr->MetaDataLength_u32);
    #else
        /* FC_VariationPoint_END */
        SduLength_u8 = (uint8)(RxPduCfgPtr->Dlc);
        /* FC_VariationPoint_START */
    #endif /* #if(CANIF_METADATA_SUPPORT == STD_ON) */
#endif /* #if (CANIF_CALIBRATION == STD_ON) */
        /* FC_VariationPoint_END */

        /*Enter Critical Section */
        SchM_Enter_CanIf_RxBufAccessNoNest();

        /* Copy the SduLength */
        *(RxBuffPtr_Temp + BufferIdx_u16) = SduLength_u8;

        /* Copy the Data */
        for(Index_u16 = (BufferIdx_u16 + (uint16_least)1); Index_u16 <= (BufferIdx_u16+SduLength_u8); Index_u16++)
        {
            *(RxBuffPtr_Temp + Index_u16) = *CanSduPtr;
            CanSduPtr++;
        }

        /* Leave Critical Section */
        SchM_Exit_CanIf_RxBufAccessNoNest();
    }
}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

/**********************************************************************************************************************/
/* Function name    : CanIf_ReadRxBuffer                                                                              */
/* Syntax           : FUNC(void, CANIF_CODE) CanIf_ReadRxBuffer(
                                                    P2VAR (PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr,
                                                    P2CONST(CanIf_RxPduConfigType, AUTOMATIC, AUTOMATIC) RxPduCfgPtr
                                                    )                                                                 */
/* Description      : Service called by CanIf function CanIf_ReadRxPduData() to read data from the receive buffer.    */
/* Parameter        : PduInfoPtr, RxPduCfgPtr                                                                         */
/* Return value     : None                                                                                            */
/**********************************************************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE) CanIf_ReadRxBuffer(
                                            P2VAR (PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr,
                                            P2CONST(CanIf_RxPduConfigType, AUTOMATIC, CANIF_CFG_CONST) RxPduCfgPtr
                                         )
{
    /* Pointer to data */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) PduData_p;

    /* To store the offset of Rx Buffer in RAM */
    VAR(uint16_least, AUTOMATIC) BufferIdx_u16;

    /* Byte position in the Rx buffer */
    VAR(uint16_least, AUTOMATIC) Index_u16;

    /*Rx-buffer pointer*/
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)RxBuffPtr_Temp;


    /*For PRE-COMPILE*/
#if(CANIF_VARIANT_INFO ==1)
    RxBuffPtr_Temp = CanIf_RxBuffer;

    /*For POST-BUILD*/
#else
    RxBuffPtr_Temp = CanIf_ConfigSetPtr->RxBufferPtr;
#endif/*CANIF_VARIANT_INFO*/


    /* Get the Rx Buffer Offset */
    BufferIdx_u16 = RxPduCfgPtr->RxBufferOffset;

    /* Get the Data Pointer */
    PduData_p = PduInfoPtr->SduDataPtr;

    /* Check if the buffer is allocated */
    if((BufferIdx_u16 != CANIF_MAX_BUFFER_OFFSET) && (RxBuffPtr_Temp != NULL_PTR))
    {
           /*Enter Critical Section */
           SchM_Enter_CanIf_RxBufAccessNoNest();

        /* Copy the Dlc */
        PduInfoPtr->SduLength = *(RxBuffPtr_Temp + BufferIdx_u16);

        /* Copy the data */
        for(Index_u16 = (BufferIdx_u16 + (uint16_least)1); Index_u16 <= (BufferIdx_u16 + PduInfoPtr->SduLength); Index_u16++ )
        {
            *PduData_p = *(RxBuffPtr_Temp + Index_u16);
            PduData_p++;
        }

        /* Leave Critical Section */
        SchM_Exit_CanIf_RxBufAccessNoNest();
    }
}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif


