

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "CanIf_Priv.h"

/*Can.h included for Can_Write()*/
/*Version check done in CanIf_SetController.c*/
#include "Can.h"

/*
 ***************************************************************************************************
 * used functions
 ***************************************************************************************************
 */

/************************************************************************************************************/
/* Function name    : CanIf_Transmit                                                                        */
/* Syntax           : FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit(
                                                                        VAR(PduIdType,AUTOMATIC) CanTxPduId,
                                                                        P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr
                                                                      )   */
/* Description      : This service initiates a request for transmission of the CAN L-PDU specified by the
                      CanTxPduId and CAN related data in the L-PDU structure.                               */
/* Parameter        : CanTxPduId, PduInfoPtr                                                                */
/* Return value     : E_OK / E_NOT_OK                                                                       */
/************************************************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC PATH,v(G),CALLS,STMT,LEVEL,RETURN VIOLATION IN CanIf_Transmit: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit(
                                                    VAR(PduIdType,AUTOMATIC) CanTxPduId,
                                                    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr
                                               )
{
    /* Pointer to Tx Pdu configuration */
    P2CONST(CanIf_TxPduInfo, AUTOMATIC, CANIF_CFG_CONST) TxPduConfig_Temp;

    /* Pointer to Controller State configuration */
    P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) ControllerState_Temp;

    /* Local pointer to cust id look up table */
    #if(CANIF_VARIANT_INFO == 2) || (CANIF_VARIANT_INFO == 3)
    const PduIdType (*TxPduId_CustId_LUT_Temp)[CANIF_TOTAL_CFG_SETS];
    #endif

    VAR(Can_PduType,AUTOMATIC) PduInfo_Write;
    VAR(Can_ReturnType,AUTOMATIC) CanStatus;
    VAR(Std_ReturnType, AUTOMATIC ) Status;

    /* FC_DeviationPoint_START */
    #if (CANIF_DEV_ERROR_DETECT == STD_ON)
    /* local variable for DLC flag */
    VAR (boolean, AUTOMATIC) Dlcflag_b =TRUE;
    VAR(uint8,AUTOMATIC) CanifMSBbits_u8;
    #endif
    /* FC_DeviationPoint_END */
    #if(CANIF_VARIANT_INFO == 1)
    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    VAR (uint16_least, AUTOMATIC) CanIf_TotalTxPduId;
    #endif
    #else
    VAR (uint16_least, AUTOMATIC) CanIf_TotalTxPduId;
    #endif

    /*To store the controller state (Device mode)*/
    VAR (CanIf_ControllerModeType, AUTOMATIC) DeviceMode_Temp;

    #if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)
    /* local variable to store the PnTxFilter */
    VAR (boolean, AUTOMATIC) LblPnTxFilter;
    #endif

    /*To store the controller state (Channel mode)*/
    VAR (CanIf_PduGetModeType, AUTOMATIC) ChannelMode_Temp;

    /*Flag to decide whether the call for Can_Write()*/
    VAR(boolean, AUTOMATIC ) TxReq = FALSE;
    /* FC_DeviationPoint_START */
    #if (CANIF_DYNAMIC_ID != STD_OFF)
    /* FC_DeviationPoint_END */
    /* FC_CODE_START */
    //#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
    /* FC_CODE_END */
    P2VAR(uint32,AUTOMATIC,AUTOMATIC) DynIdPtr_Temp;
    #endif

    /* FC_VariationPoint_START */
    #if(CANIF_METADATA_SUPPORT == STD_ON)
    /*Variable to store CanId calculated using metadata*/
    VAR (uint32, AUTOMATIC) CanId_u32 = 0;
    /*Variable to store CanId used for calculating metadata*/
    VAR (uint32, AUTOMATIC) StoredCanId_u32 = 0;
    /*Variable to store CanId bytes of metadata*/
    VAR (uint32, AUTOMATIC) Metadata_CanId_u32 = 0;
    /*Index variable for loop through*/
    VAR (uint8_least, AUTOMATIC) Index_uo = 0;
    /*Pointer to sdudata containing metadata*/
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) BufPtr_u8;
    #if (CANIF_DEV_ERROR_DETECT == STD_ON)
    VAR(uint8,AUTOMATIC) MaxDLC_u8;
    #endif
    #endif /*#if(CANIF_METADATA_SUPPORT == STD_ON) */
    /* FC_VariationPoint_END */

    /* FC_DeviationPoint_START */
    #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */
    /* FC_CODE_START */
    //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
    /* FC_CODE_END */
    /*Temp variable to hold the status of CanIf_TxBufferAllocated[]*/
    P2VAR(boolean, AUTOMATIC, AUTOMATIC) TxBuffAllocPtr_Temp;

    /*Temp variable to hold the status of CanIf_HTHBusyStatusFlag_a_b[]*/
    P2VAR(boolean, AUTOMATIC, AUTOMATIC) HTHStatusPtr_Temp;

    /*Temp variable to hold the HTH status*/
    VAR(boolean, AUTOMATIC ) HTHBusyStatus_Temp = FALSE;

    /*Temp variable to hold the TxBuffer status*/
    VAR(boolean, AUTOMATIC ) TxBuffAllocStatus_Temp =FALSE;
    #endif

    #if (CANIF_USER_CDD_TX_ENABLED != STD_OFF)
    P2CONST(CanIf_TxCbk_Prototype, AUTOMATIC, AUTOMATIC) TxCbkPtr_Temp;
    #endif

    /*Initialise the return value*/
    Status = E_NOT_OK;
    CanStatus = CAN_NOT_OK;


    /* If CAN Interface is uninitialized, report to DET and return E_NOT_OK */
    CANIF_DET_REPORT_ERROR_NOK((FALSE == CanIf_Init_Flag), CANIF_TRANSMIT_SID, CANIF_E_UNINIT)

    #if(CANIF_VARIANT_INFO == 1)
    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    CanIf_TotalTxPduId = (uint16_least)CANIF_NUM_STATIC_CANTXPDUIDS + (uint16_least)CANIF_NUM_DYNAMIC_CANTXPDUIDS;
    #endif
    /* TxPduConfig_Temp = CanIf_TxPduConfig;
    ControllerState_Temp = CanIf_ControllerState; */
    TxPduConfig_Temp = (CanIf_TxPduConfig + CanTxPduId);
    ControllerState_Temp = CanIf_ControllerState + (TxPduConfig_Temp->ControllerRefId);
    /* FC_DeviationPoint_START */
    #if (CANIF_DYNAMIC_ID != STD_OFF)
    /* FC_DeviationPoint_END */
    /* FC_CODE_START */
    //#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
    /* FC_CODE_END */
    DynIdPtr_Temp = CanIf_Dynamic_CanTxPdu_CanId;
    #endif
    /* FC_DeviationPoint_START */
    #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */
    /* FC_CODE_START */
    //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
    /* FC_CODE_END */
    TxBuffAllocPtr_Temp = CanIf_TxBufferAllocated;

    HTHStatusPtr_Temp = CanIf_HTHBusyStatusFlag_a_b;
    #endif

    #if (CANIF_USER_CDD_TX_ENABLED != STD_OFF)
    TxCbkPtr_Temp = CanIf_TxCbk;
    #endif

    #else
    TxPduId_CustId_LUT_Temp = CanIf_ConfigSetPtr->CanIf_TxPduId_CustId_LUT_ptr ;

    CanIf_TotalTxPduId = (CanIf_ConfigSetPtr->NumCanTxPduId) + (CanIf_ConfigSetPtr->NumDynamicCanTxPduId);

    /* First check if the parametre passed ie the Tx-PduId is a valid one or not. This check is required to avoid "Fencepost error"
     * in CanIf_TxPduId_CustId_LUT[][]*/
    if(CanTxPduId < CANIF_TOTAL_TXPDUS)
    {
        /* If valid, get the Cust Id and put it in 'CanTxPduId'.
         * Cust Id is required since the CanIf_TxPduConfig[] is arranged as per CustId*/
        CanTxPduId = TxPduId_CustId_LUT_Temp[CanTxPduId][CanIf_ActiveCfgSet];

        /*Return E_NOT_OK if the CustId  = CANIF_TOTAL_TXPDUS, since it means the Tx-Pdu is
         * not present in the active configset*/
        if(CanTxPduId == CANIF_TOTAL_TXPDUS)
        {
            return (Status);
        }
    }
    else
    {
        /*Else return E_NOT_OK*/
        return (Status);
    }
    /*TxPduConfig_Temp = CanIf_ConfigSetPtr->TxPduConfig;
    ControllerState_Temp = CanIf_ConfigSetPtr->CtrlStatePtr; */
    TxPduConfig_Temp =((CanIf_ConfigSetPtr->TxPduConfig) + CanTxPduId);
    ControllerState_Temp = (CanIf_ConfigSetPtr->CtrlStatePtr) + (TxPduConfig_Temp->ControllerRefId);
    /* FC_DeviationPoint_START */
    #if (CANIF_DYNAMIC_ID != STD_OFF)
    /* FC_DeviationPoint_END */
    /* FC_CODE_START */
    //#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
    /* FC_CODE_END */
    DynIdPtr_Temp = CanIf_ConfigSetPtr->DynTxIdPtr;
    #endif
    /* FC_DeviationPoint_START */
    #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */
    /* FC_CODE_START */
    //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
    /*  FC_CODE_END */
    TxBuffAllocPtr_Temp = CanIf_ConfigSetPtr->TxBufferAllocPtr;
    HTHStatusPtr_Temp = CanIf_ConfigSetPtr->HTHStatusFlagPtr;
    #endif

    #if (CANIF_USER_CDD_TX_ENABLED != STD_OFF)
    TxCbkPtr_Temp = CanIf_ConfigSetPtr->TxUSER_CDDCbkPtr;
    #endif

    #endif

    /* If CanTxPduId is invalid, report to DET and return E_NOT_OK */
    CANIF_DET_REPORT_ERROR_NOK((CanTxPduId >= CanIf_TotalTxPduId), CANIF_TRANSMIT_SID, CANIF_E_INVALID_TXPDUID)

    /* If PduInfoPtr is null, report to DET and return E_NOT_OK */
    CANIF_DET_REPORT_ERROR_NOK((NULL_PTR == PduInfoPtr), CANIF_TRANSMIT_SID,CANIF_E_PARAM_POINTER)


    /* Find the controller to which CanTxPduId belongs to and check for the controller Mode Type
     * Get the pointer from base address*/

    /*Enter critical section*/
    SchM_Enter_CanIf_ControllerState();
    /* #if(CANIF_VARIANT_INFO == 1)
    TxPduConfig_Temp = (CanIf_TxPduConfig + CanTxPduId);
    ControllerState_Temp = CanIf_ControllerState + (TxPduConfig_Temp->ControllerRefId);
    #else
    TxPduConfig_Temp = ((CanIf_ConfigSetPtr->TxPduConfig) + CanTxPduId);
    ControllerState_Temp = (CanIf_ConfigSetPtr->CtrlStatePtr) + (TxPduConfig_Temp->ControllerRefId);
    #endif */

    /*Make a local copy of Device Mode and Channel mode*/
    DeviceMode_Temp = ControllerState_Temp->DeviceMode;
    ChannelMode_Temp = ControllerState_Temp->ChannelMode;

    /*Exit critical section*/
    SchM_Exit_CanIf_ControllerState();

    /* Make a local copy of PnTxFilter */
    #if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
    LblPnTxFilter = ControllerState_Temp->BlPnTxFilter;
    #endif
    /*Exit critical section*/



    /* updated as per requirement [SWS_CANIF_00750] */
    #if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
    if((LblPnTxFilter == TRUE)&&((TxPduConfig_Temp->PnSupport)==FALSE))
    {
        return(E_NOT_OK);
    }
    #endif

    if(
    #if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
    ((LblPnTxFilter == TRUE)&&((TxPduConfig_Temp->PnSupport)==TRUE))||((LblPnTxFilter == FALSE)&&
    #endif
    /* Check the Controller mode and the Channel mode */
    (
    (CANIF_CS_STARTED == DeviceMode_Temp)   &&
        ((ChannelMode_Temp == CANIF_GET_ONLINE)
        || (ChannelMode_Temp == CANIF_GET_TX_ONLINE)))
        /* FC_VariationPoint_START */
        #if (CANIF_USER_TP_TX_OFFLINE_MODE != STD_OFF)
        || (((ChannelMode_Temp == CANIF_GET_TX_TP_ONLINE) && (TxPduConfig_Temp->TxUser == CANTP)) ||
        ((ChannelMode_Temp == CANIF_GET_TX_USER_TP_ONLINE) &&
            ((TxPduConfig_Temp->TxUser == USER) || (TxPduConfig_Temp->TxUser == CANTP))))
        #endif
            /* FC_VariationPoint_END */
        )
        #if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
        )
        #endif
    {
        /* FC_DeviationPoint_START */
        #if (CANIF_DYNAMIC_ID != STD_OFF)
        /* FC_DeviationPoint_END */
        /* FC_CODE_START */
        //#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
        /* FC_CODE_END */
        /* Check if the CanTxPduId is configured as Dynamic */
        if((TxPduConfig_Temp->CanTxPduIdType != CANIF_STATIC) && (DynIdPtr_Temp != NULL_PTR))
        {
            /* Enter Critical Section */
            SchM_Enter_CanIf_DynIdNoNest();

            /* Copy the CanId from the array */
            PduInfo_Write.id = (Can_IdType)*(DynIdPtr_Temp + (TxPduConfig_Temp->CanTxPduIdType));

            /* Leave Critical Section */
            SchM_Exit_CanIf_DynIdNoNest();

            /* FC_VariationPoint_START */
            #if (CANIF_DEV_ERROR_DETECT == STD_ON)

            #if (CANIF_METADATA_SUPPORT == STD_ON)
            if( TxPduConfig_Temp->MetaDataLength_u32 >= 1u )
            {
                /* Check if classical CAN Frame */
                if( (TxPduConfig_Temp->CanIdType == (uint8)CANIF_STD) || (TxPduConfig_Temp->CanIdType == (uint8)CANIF_XTD) )
                {
                    /* Classical CAN */
                    MaxDLC_u8 = DLC_8;
                }
                else
                {
                    /* FD CAN */
                    MaxDLC_u8 = DLC_64;
                }

                /* Report to DET, if SduLength is greater than Max Dlc + Metadalength */
                CANIF_DET_REPORT_ERROR_NOK( ((uint8)PduInfoPtr->SduLength > (MaxDLC_u8 + (uint8)TxPduConfig_Temp->MetaDataLength_u32)), \
                        CANIF_TRANSMIT_SID, CANIF_E_DATA_LENGTH_MISMATCH )

            } /* end if( TxPduConfig_Temp->MetaDataLength_u32 > 0u ) */
            else
            #endif /* #if (CANIF_METADATA_SUPPORT == STD_ON) */
            {
                /*shifting the canid bits to access two MSB's */
                /* MR12 RULE 12.2, VIOLATION Warning is "Not Critical" :The left operand of shift operator is lower in
                 * size compared to right operand, as the left operand is only used to store two bits for which unit8 is sufficient
                 */
                CanifMSBbits_u8 = (uint8)((PduInfo_Write.id)>>CANIF_CANID_BIT_SHIFT);
                if((CanifMSBbits_u8 == CANIF_ONE) ||(CanifMSBbits_u8 == CANIF_THREE))
                {
                    if(PduInfoPtr->SduLength > (PduLengthType)64)
                    {
                        Dlcflag_b = FALSE;
                    }
                }
                else
                {
                    if(PduInfoPtr->SduLength > (PduLengthType)8)
                    {
                        Dlcflag_b = FALSE;
                    }
                }

                /* If SduLength exceeding the maximum length of the PDU referenced by Can_IdType is invalid, report to DET */
                CANIF_DET_REPORT_ERROR_NOK((FALSE == Dlcflag_b), CANIF_TRANSMIT_SID, CANIF_E_DATA_LENGTH_MISMATCH)
            }
            #endif /* #if (CANIF_DEV_ERROR_DETECT == STD_ON) */
            /* FC_VariationPoint_END */
        } /* end if((TxPduConfig_Temp->CanTxPduIdType != CANIF_STATIC) && (DynIdPtr_Temp != NULL_PTR)) */
        else
        #endif //#if (CANIF_DYNAMIC_ID != STD_OFF)
        {
            /* Get the CAN ID from Can Tx pdu info to outgoing CAN Message structure */
            /* FC_VariationPoint_START */
            #if (CANIF_CALIBRATION == STD_ON)
            PduInfo_Write.id = (Can_IdType)((TxPduConfig_Temp->getCanId()));
            #else
            /* FC_VariationPoint_END */
            PduInfo_Write.id = (Can_IdType)((TxPduConfig_Temp->CanId));
            /* FC_VariationPoint_START */
            #endif
            /* FC_VariationPoint_END */
        }

        /* FC_VariationPoint_START */
        #if (CANIF_METADATA_SUPPORT == STD_ON)
        if( TxPduConfig_Temp->MetaDataLength_u32 >= 1u )
        {
            /* Get TxPduCanId used in calculation of CanId to be transmitted */
            StoredCanId_u32 = (uint32)PduInfo_Write.id;

            /*buffer pointer to data buffer containing metadata*/
            BufPtr_u8=(uint8 *)(PduInfoPtr->SduDataPtr);

            /* Increment bufptr to point to end of data buffer to extract canid bytes from
             * meta data which is stored with LSB byte first after payload data
             */
            BufPtr_u8 = BufPtr_u8 + (PduInfoPtr->SduLength-1u);

            /* Extract Canid bytes from the meta data in data buffer */
            for(Index_uo = 0; Index_uo < (TxPduConfig_Temp->MetaDataLength_u32);Index_uo++)
            {
                if(TxPduConfig_Temp->MetaDataLength_u32 == 1u)
                {
                    Metadata_CanId_u32 = (uint8)(*BufPtr_u8);
                    break;
                }

                Metadata_CanId_u32 = (Metadata_CanId_u32<<SHIFT_8) |(*BufPtr_u8);
                BufPtr_u8--;

            }

            /* Compare the MetaDataLength against CanId size and find the CanId used for transmission accordingly
             * If MetaDataLength_u32 >= CanId size, then MetaData is used as CanId
             * If MetaDataLength_u32 < CanId size, then CanId is calculated from TxPduCanId, TxPduCanIdMask and MetaData
             */
            if( (TxPduConfig_Temp->CanIdType == (uint8)CANIF_STD) || (TxPduConfig_Temp->CanIdType == (uint8)CANIF_STD_FD) )
            {
                if (TxPduConfig_Temp->MetaDataLength_u32 < CANID_SIZE_STD)
                {
                    /*Metadata length is less than canid size*/
                    CanId_u32 = (StoredCanId_u32 & TxPduConfig_Temp->TxPduCanIdMask_u32)|( Metadata_CanId_u32 & (~(TxPduConfig_Temp->TxPduCanIdMask_u32)));
                }
                else
                {
                    /*Metadata length >= CanId size, CanId is directly taken from MetaData bytes */
                    CanId_u32 = Metadata_CanId_u32 & CANIF_CANID_MASK;
                }
            }
            else
            {
                if (TxPduConfig_Temp->MetaDataLength_u32 < CANID_SIZE_XTD)
                {
                    /*Metadata length is less than canid size*/
                    CanId_u32 = (StoredCanId_u32 & TxPduConfig_Temp->TxPduCanIdMask_u32)|( Metadata_CanId_u32 & (~(TxPduConfig_Temp->TxPduCanIdMask_u32)));
                }
                else
                {
                    /*Metadata length >= CanId size, CanId is directly taken from MetaData bytes */
                    CanId_u32 = Metadata_CanId_u32;
                }
            }

            PduInfo_Write.id = (Can_IdType)CanId_u32;

		} /* end if( TxPduConfig_Temp->MetaDataLength_u32 >= 1u ) */
        #endif
        /* FC_VariationPoint_END */

        /* FC_CODE_START */
        /* MR12 RULE 3.1, VIOLATION: Warning is "Not Critical". The comment is needed during Code stripping for COMMASSO release*/
        ///* Code required to set the MSB bits of extended CAN ID */
        //if(TxPduConfig_Temp->CanIdType == CANIF_XTD)
        //{
        //    PduInfo_Write.id = PduInfo_Write.id | 0x80000000;
        //}
        /* FC_CODE_END */

        /* FC_VariationPoint_START */
        #if (CANIF_DEV_ERROR_DETECT == STD_ON)
        /* Set DLC flag if there is any mismatch in lenght and CanIdType  */
        if(TxPduConfig_Temp->CanTxPduIdType == CANIF_STATIC)
        {
            if(((TxPduConfig_Temp->CanIdType)== (uint8)CANIF_STD_FD)||(TxPduConfig_Temp->CanIdType== (uint8)CANIF_XTD_FD))
            {
                #if (CANIF_METADATA_SUPPORT == STD_ON)
                if( (PduInfoPtr->SduLength-TxPduConfig_Temp->MetaDataLength_u32) > (PduLengthType)DLC_64)
                #else
                if(PduInfoPtr->SduLength > (PduLengthType)DLC_64)
                #endif
                {
                    Dlcflag_b = FALSE;
                }
            }
            else
            {
                #if (CANIF_METADATA_SUPPORT == STD_ON)
                if( (PduInfoPtr->SduLength-TxPduConfig_Temp->MetaDataLength_u32) > (PduLengthType)DLC_8)
                #else
                if(PduInfoPtr->SduLength > (PduLengthType)DLC_8)
                #endif
                {
                    Dlcflag_b = FALSE;
                }
            }
        }

        /* If SduLength exceeding the maximum length of the PDU referenced by Can_IdType is invalid, report to DET */
        CANIF_DET_REPORT_ERROR_NOK((FALSE == Dlcflag_b), CANIF_TRANSMIT_SID, CANIF_E_DATA_LENGTH_MISMATCH)

        #endif /* #if (CANIF_DEV_ERROR_DETECT == STD_ON) */
        /* FC_VariationPoint_END */

        /*Get the sdu length*/
        /* FC_VariationPoint_START */
        #if (CANIF_CALIBRATION == STD_ON)
        if(TxPduConfig_Temp->isComULforPDUR == TRUE)
        {
            #if (CANIF_METADATA_SUPPORT == STD_ON)
            if(TxPduConfig_Temp->MetaDataLength_u32 >= 1u)
            {
                PduInfo_Write.length = (uint8)(PduInfoPtr->SduLength - TxPduConfig_Temp->MetaDataLength_u32);
            }
            else
            #endif
            {
                PduInfo_Write.length = TxPduConfig_Temp->getDlc();
            }
        }
        else
        #endif
        /* FC_VariationPoint_END */
        {
            /* FC_VariationPoint_START */
            #if (CANIF_METADATA_SUPPORT == STD_ON)
            if(TxPduConfig_Temp->MetaDataLength_u32 >= 1u)
            {
                PduInfo_Write.length = (uint8)(PduInfoPtr->SduLength - TxPduConfig_Temp->MetaDataLength_u32);
            }
            else
            #endif
            /* FC_VariationPoint_END */
            {
                PduInfo_Write.length = (uint8)PduInfoPtr->SduLength;
            }
        }

        PduInfo_Write.sdu = PduInfoPtr->SduDataPtr;
        PduInfo_Write.swPduHandle = TxPduConfig_Temp->CanTxPduId;

        /* FC_VariationPoint_START */
        if(TxPduConfig_Temp->CanTxPduIdType == CANIF_STATIC)
        {
            PduInfo_Write.id &= CANIF_MSB_BIT_RESET;

            /* setting two most significant bit based on CanIdType */
            /* MR12 RULE 12.2, VIOLATION Warning is "Not Critical" :Right operand of shift operator is greater than or equal to the width of the essential type of the left operand.  */
            PduInfo_Write.id |= ( ((Can_IdType)TxPduConfig_Temp->CanIdType) << CANIF_CANID_BIT_SHIFT );
        }
        else
        {
            #if (CANIF_METADATA_SUPPORT == STD_ON)
            if(TxPduConfig_Temp->MetaDataLength_u32 >= 1u)
            {
                /* setting two most significant bit based on CanIdType */
                /* MR12 RULE 12.2, VIOLATION Warning is "Not Critical" :Right operand of shift operator is greater than or equal to the width of the essential
                 *  type of the left operand.  */
                PduInfo_Write.id &= CANIF_MSB_BIT_RESET;
                PduInfo_Write.id |= ( ((Can_IdType)TxPduConfig_Temp->CanIdType) << CANIF_CANID_BIT_SHIFT );
            } // end if(TxPduConfig_Temp->MetaDataLength_u32 >= 1u)
            #endif //#if (CANIF_METADATA_SUPPORT == STD_ON)
        }
        /* FC_VariationPoint_END*/
        /*If TX-multiplexing is enabled*/
        /* FC_DeviationPoint_START */
        #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
        /* FC_DeviationPoint_END */
        /* FC_CODE_START */
        //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
        /* FC_CODE_END */

        /* Enter Critical Section */
        SchM_Enter_CanIf_TxMuxing();

        /*If the given Pdu belongs to BASIC CAN HTH*/
        if((CANIF_MAX_BUFFER_OFFSET != TxPduConfig_Temp->TxBufferOffset) && (NULL_PTR != TxBuffAllocPtr_Temp) && (NULL_PTR != HTHStatusPtr_Temp))
        {
            /* Get the BUSY status of the required HTH
             * TRUE = Busy / Occupied
             * FALSE = Free*/
            HTHBusyStatus_Temp = HTHStatusPtr_Temp[TxPduConfig_Temp->HTHStatusFlagIdx];

            /*Enter Critical Section */
            SchM_Enter_CanIf_TxBufAccessNoNest();

            /* Get the TxBuffer status for the given Pdu*/
            TxBuffAllocStatus_Temp = TxBuffAllocPtr_Temp[CanTxPduId];

            /* Leave Critical Section */
            SchM_Exit_CanIf_TxBufAccessNoNest();

            if((FALSE == HTHBusyStatus_Temp)  && (FALSE == TxBuffAllocStatus_Temp))
            /*Call Can_Write() since the required HTH is free*/
            {
                /*Update the HTH status to indicate it is BUSY now*/
                HTHStatusPtr_Temp[TxPduConfig_Temp->HTHStatusFlagIdx] = TRUE;

                /*Call to Can_Write()*/
                TxReq = TRUE;

            }

            else if((FALSE == HTHBusyStatus_Temp) && (TRUE == TxBuffAllocStatus_Temp))
            {
                /*This is a weird state! since the HTH is available, but the message is not yet transmitted.
                This condition does not occur in CanIf_Transmit() but is kept here for safety.

                Clear the Tx-buffer for safety*/
                TxBuffAllocPtr_Temp[CanTxPduId] = FALSE;

            }

            else if(TRUE == HTHBusyStatus_Temp)
            /*Don't call the Can_Write() since the HTH is busy. Irrespective of the Tx-Buffer flag status, copy the newer data into the Txbuffer*/
            {
                /* If Passed length is greater then configured length then , report to DET and return E_NOT_OK */
                /* FC_VariationPoint_START */
                #if (CANIF_CALIBRATION == STD_ON)

                #if (CANIF_METADATA_SUPPORT == STD_OFF)
                CANIF_DET_REPORT_ERROR_SCHM_EXIT_NOK(((uint8)PduInfoPtr->SduLength > TxPduConfig_Temp->getDlc()), CANIF_TRANSMIT_SID,CANIF_E_DATA_LENGTH_MISMATCH, SchM_Exit_CanIf_TxMuxing)
                #else
                CANIF_DET_REPORT_ERROR_SCHM_EXIT_NOK(((uint8)PduInfoPtr->SduLength > (TxPduConfig_Temp->getDlc()+TxPduConfig_Temp->MetaDataLength_u32)), CANIF_TRANSMIT_SID,CANIF_E_DATA_LENGTH_MISMATCH, SchM_Exit_CanIf_TxMuxing)
                #endif

                #else

                #if (CANIF_METADATA_SUPPORT == STD_OFF)
                /* FC_VariationPoint_END */
                CANIF_DET_REPORT_ERROR_SCHM_EXIT_NOK(((uint8)PduInfoPtr->SduLength > TxPduConfig_Temp->Dlc), CANIF_TRANSMIT_SID,CANIF_E_DATA_LENGTH_MISMATCH, SchM_Exit_CanIf_TxMuxing)
                /* FC_VariationPoint_START */
                #else
                CANIF_DET_REPORT_ERROR_SCHM_EXIT_NOK(((uint8)PduInfoPtr->SduLength > (TxPduConfig_Temp->Dlc+TxPduConfig_Temp->MetaDataLength_u32)), CANIF_TRANSMIT_SID,CANIF_E_DATA_LENGTH_MISMATCH, SchM_Exit_CanIf_TxMuxing)
                #endif //#if (CANIF_METADATA_SUPPORT == STD_OFF)

                #endif // #if (CANIF_CALIBRATION == STD_ON)
                /* FC_VariationPoint_END */

                /* Copy the data into the Tx buffer */
                CanIf_WriteTxBuffer(CanTxPduId, PduInfoPtr);
                Status = E_OK;
            }

            else
            {
                /* Dummy else to avoid MISRA violation MR12 RULE 15.7 */
                ;
            }

        }
        /*If the given Pdu belongs to FULL CAN HTH*/
        else
        {
            /*Call Can_Write() always*/
            TxReq = TRUE;
        }

        /* Exit Critical Section */
        SchM_Exit_CanIf_TxMuxing();

        /*If TX-multiplexing is NOT enabled*/
        #else
        /*Call to Can_Write()*/
        TxReq = TRUE;
        #endif
        /*If its allowed to call Can_Write()...*/
        if(TRUE == TxReq)
        {
            /*Call Can_Write()*/
            CanStatus = Can_Write(TxPduConfig_Temp->HthRefId, &PduInfo_Write);

            /* If transmission request accepted successful */
            if(CAN_OK == CanStatus)
            {
                /*Return E_OK*/
                Status = E_OK;

                /* FC_DeviationPoint_START */
                #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
                /* FC_DeviationPoint_END */
                /* FC_CODE_START */
                //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
                /*  FC_CODE_END */

                if (NULL_PTR != TxBuffAllocPtr_Temp)
                {
                    /*Enter Critical Section */
                    SchM_Enter_CanIf_TxBufAccessNoNest();

                    /*Clear the Tx-buffer flag*/
                    TxBuffAllocPtr_Temp[CanTxPduId] = FALSE;

                    /*Exit Critical Section */
                    SchM_Exit_CanIf_TxBufAccessNoNest();
                }
                #endif
            }
            else
            {
                /* CAN_NOT_OK or CAN_BUSY will not be returned since the HTH was free.
                 * If CAN_NOT_OK or CAN_BUSY i.e Transmission failure then E_NOT_OK is returned. This condition is reached
                   in case of an abnormal behaviour (Eg: Busoff) */

                #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
                if (NULL_PTR != TxBuffAllocPtr_Temp)
                {
                    /* Enter Critical Section */
                    SchM_Enter_CanIf_TxBufAccessNoNest();

                    /*Clear the Tx-buffer flag*/
                    TxBuffAllocPtr_Temp[CanTxPduId] = FALSE;

                    HTHStatusPtr_Temp[TxPduConfig_Temp->HTHStatusFlagIdx] = FALSE;

                    /* Leave Critical Section */
                    SchM_Exit_CanIf_TxBufAccessNoNest();
                }
                #endif
            }

        }//end of if(TRUE == TxReq)

    }/*end of "Check the Controller mode and the Channel mode" */

    /*Check if the Pdu mode is OFFLINE-ACTIVE*/
    else if((CANIF_CS_STARTED == DeviceMode_Temp)&&
            ((ChannelMode_Temp == CANIF_GET_OFFLINE_ACTIVE)||(ChannelMode_Temp == CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE)))
    {
        /* Simulate Tx-confirmation for the UL */
        switch(TxPduConfig_Temp->TxUser)
        {
            #if (CANIF_PDUR_ENABLED != STD_OFF)
            case PDUR:
                /* Notify Tx-Confirmation to PDUR */
                PduR_CanIfTxConfirmation(TxPduConfig_Temp->TargetTxPduId);
            break;
            #endif

            #if (CANIF_CANNM_ENABLED != STD_OFF)
            case CANNM:
                /* Notify Tx-Confirmation to CANNM */
                CanNm_TxConfirmation(TxPduConfig_Temp->TargetTxPduId);
            break;
            #endif

            #if (CANIF_CANTP_ENABLED != STD_OFF)
            case CANTP:
                /* Notify Tx-Confirmation to CANTP */
                CanTp_TxConfirmation(TxPduConfig_Temp->TargetTxPduId);
            break;
            #endif

            /* FC_VariationPoint_START */
            #if (CANIF_CANTSYN_ENABLED != STD_OFF)
            case CAN_TSYN:
            /* Notify Tx-Confirmation to CAN_TSYN */
            CanTSyn_TxConfirmation(TxPduConfig_Temp->TargetTxPduId);
            break;
            #endif
            /* FC_VariationPoint_END */

            #if (CANIF_XCP_ENABLED != STD_OFF)
            case XCP:
                /* Notify Tx-Confirmation to XCP */
                Xcp_CanIfTxConfirmation(TxPduConfig_Temp->TargetTxPduId);
            break;
            #endif

            #if (CANIF_J1939TP_ENABLED != STD_OFF)
            case J1939TP:
                /* Notify Tx-Confirmation to J1939TP */
                J1939Tp_TxConfirmation(TxPduConfig_Temp->TargetTxPduId);
            break;
            #endif

            #if (CANIF_USER_CDD_TX_ENABLED != STD_OFF)
            case CDD:
            case USER:
                if((TxCbkPtr_Temp != NULL_PTR) && (NULL_PTR != (TxCbkPtr_Temp +(TxPduConfig_Temp->CbkIdx))->UserTxConfirmation))
                {
                    /* Notify Tx-Confirmation to CDD/USER */
                    (TxCbkPtr_Temp +(TxPduConfig_Temp->CbkIdx))->UserTxConfirmation(TxPduConfig_Temp->TargetTxPduId);
                }
            break;
            #endif

            /* FC_VariationPoint_START */
            #if (CANIF_J1939NM_ENABLED != STD_OFF)
            case J1939NM:
            #if (CANIF_METADATA_SUPPORT == STD_ON)
                /* Notify Tx-Confirmation to J1939NM */
                J1939Nm_TxConfirmation(TxPduConfig_Temp->TargetTxPduId);
            #endif
            break;
            #endif
            /* FC_VariationPoint_END */

            default:
                /* Nothing to do in default case */
            break;
        }

        /*Return E_OK*/
        Status = E_OK;

    }/*end of check for OFFLINE-ACTIVE mode*/

    else
    {
        /* If Pdu mode is OFFLINE, report to DET and return E_NOT_OK */
        /* MR12 RULE 14.3, VIOLATION: Warning is "Not Critical". DET condition is intentionally made as True to
         * report DET error as the transmit CAN frame is requested when the Controller state is CANIF_CS_STOPPED
         */
        CANIF_DET_REPORT_ERROR_NOK(TRUE, CANIF_TRANSMIT_SID, CANIF_E_CTRL_STOPPED);
    }

    return(Status);
} /* End of CanIf_Transmit() */

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"




