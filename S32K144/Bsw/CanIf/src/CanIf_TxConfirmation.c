

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
/********************************************************************************************************************/
/* Function name    : CanIf_TxConfirmation                                                                          */
/* Syntax           : FUNC(void, CANIF_CODE) CanIf_TxConfirmation(
                                                                    VAR(PduIdType,AUTOMATIC) CanTxPduId
                                                                 )                                                  */
/* Description      : This service is called by the CAN driver after the CAN L-PDU has been transmitted on the CAN
                      network.                                                                                      */
/* Parameter        : CanTxPduId                                                                                    */
/* Return value     : None                                                                                          */
/********************************************************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC PATH,v(G),CALLS,STMT,LEVEL,RETURN VIOLATION IN CanIf_TxConfirmation: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(void, CANIF_CODE) CanIf_TxConfirmation(
                                            VAR(PduIdType,AUTOMATIC) CanTxPduId
                                           )
{


    /* Pointer to Tx Pdu configuration */
    P2CONST(CanIf_TxPduInfo, AUTOMATIC, CANIF_CFG_CONST) TxPduConfig_Temp;
#if(CANIF_VARIANT_INFO == 2) || (CANIF_VARIANT_INFO == 3)
    /* Local pointer to cust id look up table */
    const PduIdType (*TxPduId_CustId_LUT_Temp)[CANIF_TOTAL_CFG_SETS];
#endif

	#if (CANIF_VARIANT_INFO != 1 || CANIF_DEV_ERROR_DETECT != STD_OFF)
    VAR (uint16_least, AUTOMATIC) CanIf_TotalTxPduId;
	#endif



 /* FC_DeviationPoint_START */
#if (CANIF_TRANSMIT_BUFFER != STD_OFF)
     /* FC_DeviationPoint_END */
        /* FC_CODE_START */
 //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
  /*  FC_CODE_END */
    /* Pointer to Tx Pdu configuration */
    P2CONST(CanIf_TxPduInfo, AUTOMATIC, CANIF_CFG_CONST) TxPduConfig_pcs;
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) LocalBufferPtr;
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) TxBufferPtr;
    VAR(uint16_least,AUTOMATIC) LoopIdx;
    VAR(uint16,AUTOMATIC) BufferIdx;
    VAR(uint16,AUTOMATIC) BufferEndIdx;
    VAR(Can_PduType,AUTOMATIC) PduInfo;
    VAR(Can_ReturnType,AUTOMATIC) Status;
    /* FC_VariationPoint_START */
#if(CANIF_FD_SUPPORT == STD_OFF)
    /* FC_VariationPoint_END */
    /* Local Copy of the transmit buffer */
    VAR(uint8,AUTOMATIC) PduLocalBuffer[9];
    /* FC_VariationPoint_START */
#else
    /* Local Copy of the transmit buffer */
    VAR(uint8,AUTOMATIC) PduLocalBuffer[65];
#endif
    /* FC_VariationPoint_END */
    VAR(PduIdType,AUTOMATIC) StartIdx;
    VAR(PduIdType,AUTOMATIC) EndIdx;
    VAR(PduIdType,AUTOMATIC) PduIdx;

    /*To hold the local copy of pointer to CanIf_TxBufferAllocated[]*/
    P2VAR(boolean, AUTOMATIC, AUTOMATIC) TxBuffAllocPtr_Temp;

    /*To hold the local copy of CanIf_TxBufferAllocated*/
    VAR(boolean,AUTOMATIC) TxBuffStatus_Temp;

    /*Temp variable to hold the status of CanIf_HTHBusyStatusFlag_a_b[]*/
    P2VAR(boolean, AUTOMATIC, AUTOMATIC) HTHStatusPtr_Temp;

    /*Flag to decide whether the call for Can_Write()*/
    VAR(boolean, AUTOMATIC ) TxReq;


    /* FC_DeviationPoint_START */
    #if (CANIF_DYNAMIC_ID != STD_OFF)
    /* FC_DeviationPoint_END */
    /* FC_CODE_START */
    //#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
    /* FC_CODE_END */
    P2VAR(uint32,AUTOMATIC,AUTOMATIC) DynIdPtr_Temp;
    #endif
    #endif

    /* FC_CODE_START */
    #if(CANIF_METADATA_SUPPORT == STD_ON)
    /*Variable to store calculated Dlc*/
    VAR (uint8_least, AUTOMATIC) Dlc_uo = 0;
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
    #endif
    /* FC_CODE_END */

    /* Pointer to Controller State configuration */
	#if ((CANIF_PUBLIC_PN_SUPPORT != STD_OFF) || (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF))
    P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) ControllerState_Temp;
	#endif

#if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
    /*To store the controller state (Device mode)*/
       VAR (CanIf_ControllerModeType, AUTOMATIC) DeviceMode_Temp;

    P2VAR(CanIf_NotifStatusType, AUTOMATIC, AUTOMATIC) TxConfStatus_Temp;

    #endif

#if (CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF)
    P2VAR(CanIf_NotifStatusType, AUTOMATIC, AUTOMATIC) TxNotifPtr_Temp;
    #endif

#if (CANIF_USER_CDD_TX_ENABLED != STD_OFF)
    P2CONST(CanIf_TxCbk_Prototype, AUTOMATIC, AUTOMATIC) TxCbkPtr_Temp;
    #endif

    /* If CAN Interface is uninitialized, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR((CanIf_Init_Flag == FALSE), CANIF_TX_CONFIRMATION_SID, CANIF_E_UNINIT)

#if(CANIF_VARIANT_INFO == 1)
    TxPduConfig_Temp = CanIf_TxPduConfig;
    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    CanIf_TotalTxPduId = (uint16_least)CANIF_NUM_STATIC_CANTXPDUIDS + (uint16_least)CANIF_NUM_DYNAMIC_CANTXPDUIDS;
    #endif

 /* FC_DeviationPoint_START */
#if (CANIF_TRANSMIT_BUFFER != STD_OFF)
     /* FC_DeviationPoint_END */
        /* FC_CODE_START */
 //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
  /*  FC_CODE_END */
    TxBuffAllocPtr_Temp = CanIf_TxBufferAllocated;

    HTHStatusPtr_Temp = CanIf_HTHBusyStatusFlag_a_b;

    TxBuffStatus_Temp = FALSE;

    TxReq = FALSE;

    /* FC_DeviationPoint_START */
    #if (CANIF_DYNAMIC_ID != STD_OFF)
    /* FC_DeviationPoint_END */
    /* FC_CODE_START */
    //#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
    /* FC_CODE_END */
    DynIdPtr_Temp = CanIf_Dynamic_CanTxPdu_CanId;
    #endif

    #endif

#if ((CANIF_PUBLIC_PN_SUPPORT != STD_OFF) || (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF))
    ControllerState_Temp = CanIf_ControllerState;
	#endif

#if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
    TxConfStatus_Temp = CanIf_TxConf_State;
    #endif

#if (CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF)
    TxNotifPtr_Temp = CanIf_TxNotification;
    #endif

#if (CANIF_USER_CDD_TX_ENABLED != STD_OFF)
    TxCbkPtr_Temp = CanIf_TxCbk;
    #endif
#else

    /*No need to find the CustId, since CanDrv would be passing the CustId itself.*/
    TxPduConfig_Temp = CanIf_ConfigSetPtr->TxPduConfig;
    TxPduId_CustId_LUT_Temp = CanIf_ConfigSetPtr->CanIf_TxPduId_CustId_LUT_ptr ;
    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    CanIf_TotalTxPduId = CanIf_ConfigSetPtr->NumCanTxPduId + CanIf_ConfigSetPtr->NumDynamicCanTxPduId;
    #else
    CanIf_TotalTxPduId = CanIf_ConfigSetPtr->NumCanTxPduId + CanIf_ConfigSetPtr->NumDynamicCanTxPduId;
    #endif

 /* FC_DeviationPoint_START */
#if (CANIF_TRANSMIT_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */
    /* FC_CODE_START */
    //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
    /*  FC_CODE_END */
    TxBuffAllocPtr_Temp = CanIf_ConfigSetPtr->TxBufferAllocPtr;
    HTHStatusPtr_Temp = CanIf_ConfigSetPtr->HTHStatusFlagPtr;
    TxBuffStatus_Temp = FALSE;
    TxReq = FALSE;

    /* FC_DeviationPoint_START */
    #if (CANIF_DYNAMIC_ID != STD_OFF)
    /* FC_DeviationPoint_END */
    /* FC_CODE_START */
    //#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
    /* FC_CODE_END */
    DynIdPtr_Temp = CanIf_ConfigSetPtr->DynTxIdPtr;
    #endif

    #endif

#if ((CANIF_PUBLIC_PN_SUPPORT != STD_OFF) || (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF))
    ControllerState_Temp = CanIf_ConfigSetPtr->CtrlStatePtr;
	#endif

#if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
    TxConfStatus_Temp = CanIf_ConfigSetPtr->TxConfStatusPtr;
    #endif

#if (CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF)
    TxNotifPtr_Temp = CanIf_ConfigSetPtr->TxNotifPtr;
    #endif

#if (CANIF_USER_CDD_TX_ENABLED != STD_OFF)
    TxCbkPtr_Temp = CanIf_ConfigSetPtr->TxUSER_CDDCbkPtr;
    #endif

    /*Get the CustId of the Tx-Pdu since in CanIf_Transmit() the Can_Write() is passed with the TxPduId itself
     * This neutralises the effect*/
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
            return;
        }
    }
    else
    {
        /*Else return E_NOT_OK*/
        return;
    }

#endif

    /* If CanTxPduId is invalid, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR((CanTxPduId >= CanIf_TotalTxPduId), CANIF_TX_CONFIRMATION_SID, CANIF_E_INVALID_TXPDUID)


    /* Initialise pointer to Tx PDU configuration
     * Get the pointer frmo base address*/
    #if(CANIF_VARIANT_INFO == 1)
    TxPduConfig_Temp = CanIf_TxPduConfig + CanTxPduId;
    #else
    TxPduConfig_Temp = (CanIf_ConfigSetPtr->TxPduConfig) + CanTxPduId;
    #endif

    /*Initialise pointer to Controller State configuration
     *Get the pointer from base address */
#if ((CANIF_PUBLIC_PN_SUPPORT != STD_OFF) || (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF))
#if(CANIF_VARIANT_INFO == 1)
    ControllerState_Temp = CanIf_ControllerState + (TxPduConfig_Temp->ControllerRefId);
#else
    ControllerState_Temp = CanIf_ConfigSetPtr->CtrlStatePtr + (TxPduConfig_Temp->ControllerRefId);
#endif
#endif


    /*Enter critical section*/
    SchM_Enter_CanIf_ControllerState();


    /* updated as per requirement [SWS_CANIF_00751] */

    #if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
    if(ControllerState_Temp->BlPnCntr == TRUE)
    {
        ControllerState_Temp->BlPnTxFilter = FALSE;
    }
    #endif

    /*Exit critical section*/
    SchM_Exit_CanIf_ControllerState();

    #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)

    /*Make local copy of Device mode*/
    DeviceMode_Temp = ControllerState_Temp->DeviceMode;

    /* Enter Critical Section */
    SchM_Enter_CanIf_TxRxNotifNoNest();

    /*Update the CanIf_TxConf_State[] if controller is in STARTED mode*/
    if( (*(TxConfStatus_Temp + (TxPduConfig_Temp->ControllerRefId)) != CANIF_TX_RX_NOTIFICATION) && (DeviceMode_Temp == CANIF_CS_STARTED))
    {
        /* Reset Tx Confirmation state for each controller*/
        *(TxConfStatus_Temp + (TxPduConfig_Temp->ControllerRefId)) = CANIF_TX_RX_NOTIFICATION;

    }

    /* Leave Critical Section */
    SchM_Exit_CanIf_TxRxNotifNoNest();

    #endif


    /* Check if Tx buffering is configured */
    /* FC_DeviationPoint_START */
    #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */
    /* FC_CODE_START */
    //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
    /*  FC_CODE_END */
    /* Enter Critical Section */
    SchM_Enter_CanIf_TxMuxing();

    /* Initialize the pointers */
    LocalBufferPtr = NULL_PTR;
    TxBufferPtr = NULL_PTR;

    /* Check if the Pdu belongs to a BASIC CAN HTH */
    if((TxPduConfig_Temp->StartIdx != CANIF_MAX_PDU_INDEX) &&
       (TxBuffAllocPtr_Temp != NULL_PTR) && (NULL_PTR != HTHStatusPtr_Temp)
        #if ((CANIF_VARIANT_INFO == 2) || (CANIF_VARIANT_INFO == 3))
       &&
       ((CanIf_ConfigSetPtr->TxBufferPtr) != NULL_PTR)
        #endif
      )
    {
        /*If the given Pdu belongs to BASIC CAN HTH and the configset has BASIC HTHs...*/
        if((CANIF_MAX_BUFFER_OFFSET != TxPduConfig_Temp->TxBufferOffset) && (NULL_PTR != HTHStatusPtr_Temp))
        {
            /*First clear the Tx-buffer status and HTH status of the corresponding HTH i.e its free now*/
            HTHStatusPtr_Temp[TxPduConfig_Temp->HTHStatusFlagIdx] = FALSE;

        }


        /* Get the list of Pdus whose buffers has to be checked */
        StartIdx = TxPduConfig_Temp->StartIdx;
        EndIdx = TxPduConfig_Temp->EndIdx;


        /* Search for pending transmission in all Pdus allocated to the corresponding Hth */
        for(PduIdx = StartIdx; PduIdx <= EndIdx; PduIdx++)
        {

            /* Check if the Tx-Buffer is allocated */
            if(*(TxBuffAllocPtr_Temp +PduIdx) != FALSE)
            {

                /*Enter Critical Section */
                SchM_Enter_CanIf_TxBufAccessNoNest();

                /*Store the Tx-buffer status of the pending message*/
                TxBuffStatus_Temp = *(TxBuffAllocPtr_Temp +PduIdx) ;

                /* Leave Critical Section */
                SchM_Exit_CanIf_TxBufAccessNoNest();

                break;
            }

        }

        if(TRUE == TxBuffStatus_Temp)
        /*Some messages are pending...*/
        {

            /* Initialise pointer to pending Tx PDU configuration */
            #if(CANIF_VARIANT_INFO == 1)
            TxPduConfig_pcs = CanIf_TxPduConfig + PduIdx;
            #else
            TxPduConfig_pcs = (CanIf_ConfigSetPtr->TxPduConfig) + PduIdx;
            #endif

            /*Update the HTH status as busy*/
            HTHStatusPtr_Temp[TxPduConfig_pcs->HTHStatusFlagIdx] =  TRUE;

            /* Get the Tx-buffer index */
            BufferIdx = TxPduConfig_pcs->TxBufferOffset;

            /* Initialize pointers to data and TxBuffer */
            LocalBufferPtr = &(PduLocalBuffer[0]);

            #if(CANIF_VARIANT_INFO == 1)
            TxBufferPtr = CanIf_TxBuffer + BufferIdx;
            #else
            TxBufferPtr = (CanIf_ConfigSetPtr->TxBufferPtr) + BufferIdx;
            #endif

            /*Enter Critical Section */
            SchM_Enter_CanIf_TxBufAccessNoNest();

            /* Copy the DLC into the local buffer */
            *(LocalBufferPtr) = *(TxBufferPtr);


            /* Increment the buffer pointer to copy data */
            TxBufferPtr++;
            LocalBufferPtr++;

            /* Calculate the end of the buffer */
            BufferEndIdx = BufferIdx + PduLocalBuffer[0];

            /* Copy L-Pdu data into a local buffer */
            for(LoopIdx = (BufferIdx + 1); LoopIdx <= BufferEndIdx; LoopIdx++)
            {
                /* Copy data */
                *(LocalBufferPtr) = *(TxBufferPtr);


                /* Jump to next byte of data */
                LocalBufferPtr++;
                TxBufferPtr++;
            }


            /* Leave Critical Section */
            SchM_Exit_CanIf_TxBufAccessNoNest();
            /* FC_VariationPoint_START */
            #if (CANIF_METADATA_SUPPORT == STD_ON)
            if(TxPduConfig_pcs->MetaDataLength_u32 >= 1u)
            {
                /*calculate the Dlc as sdulength is sum of Dlc and metadata length*/
                Dlc_uo = PduLocalBuffer[0] - TxPduConfig_pcs->MetaDataLength_u32;
                /*copy the Dlc*/
                PduInfo.length = (uint8)Dlc_uo;
            }
            else
            #endif
            /* FC_VariationPoint_END */
            {
                /* Copy the length */
                PduInfo.length = PduLocalBuffer[0];
            }

            /* Copy the data pointer */
            PduInfo.sdu = &(PduLocalBuffer[1]);

            /* Copy the CanIfTxPduId */
            PduInfo.swPduHandle = TxPduConfig_pcs->CanTxPduId;


            /* FC_DeviationPoint_START */
            #if (CANIF_DYNAMIC_ID != STD_OFF)
            /* FC_DeviationPoint_END */
            /* FC_CODE_START */
            //#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
            /* FC_CODE_END */
            /* Check if the CanTxPduId is configured as Dynamic */
            if((TxPduConfig_pcs->CanTxPduIdType != CANIF_STATIC) && (DynIdPtr_Temp != NULL_PTR))
            {
                /* Enter Critical Section */
                SchM_Enter_CanIf_DynIdNoNest();

                /* Copy the CanId from the array */
                PduInfo.id = (Can_IdType)*(DynIdPtr_Temp + (TxPduConfig_pcs->CanTxPduIdType));

                /* Leave Critical Section */
                SchM_Exit_CanIf_DynIdNoNest();
            }
            else
            #endif /* #if (CANIF_DYNAMIC_ID != STD_OFF) */
            {
                /* Copy the CanId */
                /* FC_VariationPoint_START */
                #if (CANIF_CALIBRATION == STD_ON)
                PduInfo.id = (Can_IdType)((TxPduConfig_pcs->getCanId()));
                #else
                /* FC_VariationPoint_END */
                PduInfo.id = (Can_IdType)(TxPduConfig_pcs->CanId);
                /* FC_VariationPoint_START */
                #endif
                /* FC_VariationPoint_END */
            }

            /* FC_VariationPoint_START */
            #if (CANIF_METADATA_SUPPORT == STD_ON)
            if( TxPduConfig_pcs->MetaDataLength_u32 > 0u )
            {
                /* Get TxPduCanId used in calculation of CanId to be transmitted */
                StoredCanId_u32 = (uint32)PduInfo.id;

                /*buffer pointer to data buffer containing metadata*/
                BufPtr_u8=(uint8 *)(&PduLocalBuffer[0]);

                /* Increment bufptr to point to end of data buffer to extract canid bytes from
                 * meta data which is stored with LSB byte first after payload data
                 */
                BufPtr_u8 = BufPtr_u8 + (PduLocalBuffer[0]);

                /* Extract Canid bytes from the meta data of data buffer */
                for(Index_uo = 0; Index_uo < (TxPduConfig_pcs->MetaDataLength_u32);Index_uo++)
                {
                    if(TxPduConfig_pcs->MetaDataLength_u32 == 1u)
                    {
                        Metadata_CanId_u32 = (uint8)(*BufPtr_u8);
                        break;
                    }

                    Metadata_CanId_u32 = (Metadata_CanId_u32<<SHIFT_8) |(*BufPtr_u8);
                    BufPtr_u8--;

                }

                /* Compare the MetaDataLength_u32 against CanId size and find the CanId used for transmission accordingly
                 * If MetaDataLength_u32 >= CanId size, then MetaData is used as CanId
                 * If MetaDataLength_u32 < CanId size, then CanId is calculated from TxPduCanId, TxPduCanIdMask and MetaData
                 */
                if( (TxPduConfig_pcs->CanIdType == (uint8)CANIF_STD) || (TxPduConfig_pcs->CanIdType == (uint8)CANIF_STD_FD) )
                {
                    if (TxPduConfig_pcs->MetaDataLength_u32 < CANID_SIZE_STD)
                    {
                        /*Metadata length is less than canid size*/
                        CanId_u32 = (StoredCanId_u32 & TxPduConfig_pcs->TxPduCanIdMask_u32)|( Metadata_CanId_u32 & (~(TxPduConfig_pcs->TxPduCanIdMask_u32)));
                    }
                    else
                    {
                        /*Metadata length >= CanId size, CanId is directly taken from MetaData bytes */
                        CanId_u32 = Metadata_CanId_u32 & CANIF_CANID_MASK;
                    }
                }
                else
                {
                    if (TxPduConfig_pcs->MetaDataLength_u32 < CANID_SIZE_XTD)
                    {
                        /*Metadata length is less than canid size*/
                        CanId_u32 = (StoredCanId_u32 & TxPduConfig_pcs->TxPduCanIdMask_u32)|( Metadata_CanId_u32 & (~(TxPduConfig_pcs->TxPduCanIdMask_u32)));
                    }
                    else
                    {
                        /*Metadata length >= CanId size, CanId is directly taken from MetaData bytes */
                        CanId_u32 = Metadata_CanId_u32;
                    }
                }

                PduInfo.id = (Can_IdType)CanId_u32;
            } /* end if( TxPduConfig_Temp->MetaDataLength_u32 > 0u ) */
            #endif /* #if (CANIF_METADATA_SUPPORT == STD_ON) */
            /* FC_VariationPoint_END */

            /* FC_CODE_START */
            /* MR12 RULE 3.1, VIOLATION: Warning is "Not Critical". The comment is needed during Code stripping for COMMASSO release*/
            // /* Code required to set the MSB bits of extended CAN ID */
            //if(TxPduConfig_pcs->CanIdType == CANIF_XTD)
            //{
            //    PduInfo.id = PduInfo.id | 0x80000000;
            //}
            /* FC_CODE_END */

            /* Transmit the data */
            TxReq = TRUE;

        } /* end if(TRUE == TxBuffStatus_Temp) */

        else
        {
            /*No pending messages left*/
        }

    }/* End of if(TxPduConfig_Temp->StartIdx != CANIF_MAX_PDU_INDEX) */

    /* Exit Critical Section */
    SchM_Exit_CanIf_TxMuxing();
    if(TRUE == TxReq)
    {
        /* FC_VariationPoint_START */
        if(TxPduConfig_pcs->CanTxPduIdType == CANIF_STATIC)
        {
            /* clearing 2 MSB's for Extended type */
            PduInfo.id &= CANIF_MSB_BIT_RESET;

            /* setting two most significant bit based on CanIdType */
            /* MR12 RULE 12.2, VIOLATION Warning is "Not Critical" :Right operand of shift operator is greater than or equal to the width of the essential type of the left operand.  */
            PduInfo.id |= (((Can_IdType)(TxPduConfig_pcs->CanIdType))<<CANIF_CANID_BIT_SHIFT);
        }
        else
        {
            #if (CANIF_METADATA_SUPPORT == STD_ON)
            if(TxPduConfig_Temp->MetaDataLength_u32 >= 1u)
            {
                /* Fetching two MSB based on CanIdType to reset it */
                    PduInfo.id &= CANIF_MSB_BIT_RESET;

                /* setting two most significant bit based on CanIdType */
                    /* MR12 RULE 12.2, VIOLATION Warning is "Not Critical" :Right operand of shift operator is greater than or equal to the width of the essential type of the left operand.  */
                    PduInfo.id |= (((Can_IdType)(TxPduConfig_pcs->CanIdType))<<CANIF_CANID_BIT_SHIFT);
            } // end if(TxPduConfig_Temp->MetaDataLength_u32 >= 1u)
            #endif //#if (CANIF_METADATA_SUPPORT == STD_ON)
        }
        /* FC_VariationPoint_END*/

    /*If its allowed to call Can_Write()...*/

        /*Call Can_Write()*/
        Status = Can_Write(TxPduConfig_pcs->HthRefId, &PduInfo);

        /* Reset flag only if CAN_OK was returned else it shall remain as TRUE.*/
        if(Status == CAN_OK)
        {
            /*Enter Critical Section */
            SchM_Enter_CanIf_TxBufAccessNoNest();

            /* Reset the Tx-buffer allocation status as free */
            *(TxBuffAllocPtr_Temp +PduIdx) = FALSE;

            /* Leave Critical Section */
            SchM_Exit_CanIf_TxBufAccessNoNest();
        }
        else
        {
            /*Enter Critical Section */
            SchM_Enter_CanIf_TxBufAccessNoNest();

            /* Reset the Tx-buffer allocation status as free */
            *(TxBuffAllocPtr_Temp +PduIdx) = FALSE;

            HTHStatusPtr_Temp[TxPduConfig_Temp->HTHStatusFlagIdx] = FALSE;

            #if (CANIF_USER_TXBUFCLEARNOTIFY_API != STD_OFF)
            CanIf_UserTxBufClearCallback(TxPduConfig_Temp->TargetTxPduId);
            #endif

            /* Leave Critical Section */
            SchM_Exit_CanIf_TxBufAccessNoNest();
        }
    }
    #endif

    #if (CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF)

    /* Enter Critical Section */
    SchM_Enter_CanIf_TxRxNotifNoNest();

    /* Update the notification status */
    *(TxNotifPtr_Temp + CanTxPduId) = CANIF_TX_RX_NOTIFICATION;

    /* Leave Critical Section */
    SchM_Exit_CanIf_TxRxNotifNoNest();
    #endif

    /* Indicate application about confirmation of data transmission */
    switch(TxPduConfig_Temp->TxUser)
    {
        #if (CANIF_PDUR_ENABLED != STD_OFF)
        case PDUR:
            /* Callback function to indicate the transmit confirmation to CANIF */
        PduR_CanIfTxConfirmation(TxPduConfig_Temp->TargetTxPduId);
        break;
        #endif

        #if (CANIF_CANNM_ENABLED != STD_OFF)
        case CANNM:
            /* notify confirmation of a tranmsitted NM message over CAN */
        CanNm_TxConfirmation(TxPduConfig_Temp->TargetTxPduId);
        break;
        #endif

        #if (CANIF_CANTP_ENABLED != STD_OFF)
        case CANTP:
            /* notify confirmation of a tranmsitted CANTP message over CAN */
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
            /* notify confirmation of a tranmsitted XCP message over CAN */
        Xcp_CanIfTxConfirmation(TxPduConfig_Temp->TargetTxPduId);
        break;
        #endif

        #if (CANIF_J1939TP_ENABLED != STD_OFF)
        case J1939TP:
           /* notify confirmation of a tranmsitted J1939TP message over CAN */
        J1939Tp_TxConfirmation(TxPduConfig_Temp->TargetTxPduId);
        break;
        #endif

        #if (CANIF_USER_CDD_TX_ENABLED != STD_OFF)
        case CDD:
        case USER:
        if((TxCbkPtr_Temp != NULL_PTR) && (NULL_PTR != (TxCbkPtr_Temp +(TxPduConfig_Temp->CbkIdx))->UserTxConfirmation))
        {
            /* notify confirmation of a tranmsitted CDD/USER message over CAN */
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
} /* End of CanIf_TxConfirmation() */
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


