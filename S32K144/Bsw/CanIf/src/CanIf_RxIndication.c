

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "CanIf_Priv.h"


/*
 ***************************************************************************************************
 * Variables
 ***************************************************************************************************
 */


/*
 ***************************************************************************************************
 * used functions
 ***************************************************************************************************
 */

/*******************************************************************************************************************
*/
/* Function name    :
CanIf_RxIndication                                                                            */
/* Syntax           : FUNC(void, CANIF_CODE) CanIf_RxIndication(
                                                                VAR(uint8, AUTOMATIC) Hrh,
                                                                VAR(Can_IdType, AUTOMATIC) CanId,
                                                                VAR(uint8, AUTOMATIC) CanDlc,
                                                                P2CONST (uint8, AUTOMATIC, CANIF_APPL_DATA)
CanSduPtr

)                                                   */
/* Description      : This service is called by the CAN driver after a CAN L-PDU has been received. Within this
                      service, the CAN Interface translates the CanId into the configured target PDU ID and routes
                      this indication to the configured upper layer target
service(s).                              */
/* Parameter        : Hrh, CanId, CanDlc,
CanSduPtr                                                                 */
/* Return value     :
None                                                                                          */
/*******************************************************************************************************************
*/

#define CANIF_START_SEC_VAR_CLEARED_32
#include "CanIf_MemMap.h"
#if (CANIF_XCP_ENABLED != STD_OFF)
/* FC_VariationPoint_START */
#if(CANIF_FD_SUPPORT == STD_OFF)
/* CanSduDataBuffer[(length+3)/4] */
#if(CANIF_METADATA_SUPPORT == STD_OFF)
/* CanSduDataBuffer[(8+3)/4] */
static VAR(uint32,AUTOMATIC) CanSduDataBuffer[2];
#else
/* CanSduDataBuffer[(12+3)/4] */
static VAR(uint32,AUTOMATIC) CanSduDataBuffer[3];
#endif

#else
#if(CANIF_METADATA_SUPPORT == STD_OFF)
/* CanSduDataBuffer[(64+3)/4] */
static VAR(uint32,AUTOMATIC) CanSduDataBuffer[16];
#else
/* CanSduDataBuffer[(68+3)/4] */
static VAR(uint32,AUTOMATIC) CanSduDataBuffer[17];
#endif
#endif
/* FC_VariationPoint_END */

#endif /* #if (CANIF_XCP_ENABLED != STD_OFF) */
#define CANIF_STOP_SEC_VAR_CLEARED_32
#include "CanIf_MemMap.h"


#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC PATH,v(G),CALLS,STMT,LEVEL,RETURN VIOLATION IN CanIf_RxIndication: Function contains very simple "else if" statements and "switch-cases". HIS metric compliance would decrease readability and maintainability. Also Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(void, CANIF_CODE) CanIf_RxIndication_Internal(
                                                   VAR(Can_HwHandleType, AUTOMATIC) Hrh,
                                                   VAR(Can_IdType, AUTOMATIC) CanId,
                                                   VAR(uint8, AUTOMATIC) CanDlc,
                                                   P2CONST (uint8, AUTOMATIC, CANIF_APPL_DATA) CanSduPtr
                                                  )
{
    /* Pointer to Rx Pdu configuration */
    P2CONST(CanIf_RxPduConfigType, AUTOMATIC, CANIF_CFG_CONST) RxPduCfg_pcs;
    #if (CANIF_DLC_CHECK != STD_OFF)
    P2CONST(CanIf_CallbackFuncType, AUTOMATIC, AUTOMATIC) CallBackPtr_Temp;
    #endif
    /* Pointer to HRH configuration */
    P2CONST(CanIf_HrhConfigType, AUTOMATIC, CANIF_CFG_CONST) HrhCfg_pcs;

    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    VAR(uint16,AUTOMATIC) Num_Hrh_Handles_Temp;
    #endif
    VAR(uint32,AUTOMATIC)NoOfCanId_u32;
    VAR(uint8,AUTOMATIC)Index_u8;

    /* Pointer to Controller State configuration */
    P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) ControllerState_ps;

    #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF && CANIF_PUBLIC_BUSOFF_RECOVERY_FROM_RXINDICATION != STD_OFF )
    P2VAR(CanIf_NotifStatusType, AUTOMATIC, AUTOMATIC) TxConfStatus_Temp;
    #endif

    #if(CANIF_CANNM_TXID_FILTER != STD_OFF)
    P2CONST(CanIf_CanIdType, AUTOMATIC, AUTOMATIC) CanNmTxIdPtr_Temp;
    #endif

    #if (CANIF_READRXPDU_NOTIFY_STATUS_API != STD_OFF)
    P2VAR(CanIf_NotifStatusType,AUTOMATIC, AUTOMATIC) RxNotifPtr_Temp;
    #endif

    #if (CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
    P2VAR(uint8,AUTOMATIC, AUTOMATIC) NewRxMsgPtr_Temp;
    #endif

    #if (CANIF_CDD_RX_ENABLED != STD_OFF)
    P2CONST(CanIf_CddRxCbk_Prototype,AUTOMATIC, AUTOMATIC) CddRxCbkPtr_Temp;
    #endif

    #if (CANIF_READBUFFERID != STD_OFF)
    P2CONST(CanIf_J1939RxCbk_Prototype,AUTOMATIC, AUTOMATIC) J1939RxCbkPtr_Temp;
    #endif

    #if (CANIF_USER_RX_ENABLED != STD_OFF)
    P2CONST(CanIf_RxCbk_Prototype,AUTOMATIC, AUTOMATIC) RxCbkPtr_Temp;
    #endif


    /* To store the status of the DLC Check */

    /* To store the status of function execution */
    VAR(boolean, AUTOMATIC) StopExe;

    /* To store the Rx L-PDU Id after search */
    VAR(PduIdType, AUTOMATIC) PduId;

    #if (CANIF_BASIC_CAN_SUPPORT != STD_OFF || CANIF_CANNM_TXID_FILTER != STD_OFF)
    Can_IdType CanFDMask;
    #endif

    #if (CANIF_XCP_ENABLED != STD_OFF)
    VAR(PduLengthType,AUTOMATIC) i = 0;

    /* FC_VariationPoint_START */
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) CanSduDataBuffer_Ptr = NULL_PTR;
    /* FC_VariationPoint_END */
    #endif

    /* FC_VariationPoint_START */
    #if(CANIF_METADATA_SUPPORT == STD_ON)
    /*Variable to store sdulength which is sum of Dlc and MetadataLength*/
    VAR(uint32,AUTOMATIC) SduLength_u32 = 0;
    /*Data buffer to store payload data and metadata canid bytes*/
    VAR(uint8,AUTOMATIC) SduDataBuffer_au8[SDU_DATA_BUFF_SIZE] = {0};
    /*Index variable for payload data*/
    VAR (uint8_least, AUTOMATIC) Payload_Index_uo = 0;
    /*Index variable for metadata*/
    VAR (uint8_least, AUTOMATIC) Metadata_Index_uo = 0;
    /*vriable to hold received canid*/
    VAR (uint32, AUTOMATIC) CanId_Temp_u32 = 0;
    #endif
    /* FC_VariationPoint_END */

    /* Variables used for Binary search */
    #if (CANIF_BASIC_CAN_SUPPORT_LIST != STD_OFF)
    VAR(uint32, AUTOMATIC) LowVal;
    VAR(uint32, AUTOMATIC) HighVal;

    /* Pointer to Rx Pdu configuration supporting list of CanIds */
    P2CONST(CanIf_CanIdListConfigType, AUTOMATIC, AUTOMATIC) CanIdListCfg_pcs;

    #endif

    /* To store the status of search algorithm */
    VAR(boolean, AUTOMATIC) IdFound;

    #if (CANIF_RXPDU_CANID_RANGE != STD_OFF)

    /* Lower Limit of PDU ID*/
    VAR(uint32, AUTOMATIC) LowerLimit;

    /* Upper Limit of PDU ID*/
    VAR(uint32, AUTOMATIC) UpperLimit;

    P2CONST(CanIf_RxPduCanIdRangeConfigType, AUTOMATIC, AUTOMATIC) CanIdRangeCfg_pcs;

    #endif

    /* Variables to hold the contents for Upl(CanTp, CanNm or PduR) */
    #if ((CANIF_CANTP_ENABLED != STD_OFF) || (CANIF_CANNM_ENABLED != STD_OFF) || (CANIF_PDUR_ENABLED != STD_OFF) || (CANIF_CDD_RX_ENABLED != STD_OFF) || (CANIF_XCP_ENABLED != STD_OFF)|| (CANIF_J1939TP_ENABLED != STD_OFF))
    VAR(PduInfoType, AUTOMATIC) UplRxPduPtr;
    VAR(PduIdType, AUTOMATIC) UplRxPduId;
    #endif

    /* Variable to hold the Pdu structure for USER */
    #if (CANIF_USER_RX_ENABLED != STD_OFF)
    VAR(CanIf_PduInfoType, CANIF_VAR) UserRxPduInfo;
    #endif

    /*To store the controller state (Device mode)*/
    VAR (CanIf_ControllerModeType, AUTOMATIC) DeviceMode_Temp;

    /* Local variable to store two MSB's */
    VAR(uint8, AUTOMATIC)CanifMSBbits_u8;

    /*To store the controller state (Channel mode)*/
    VAR (CanIf_PduGetModeType, AUTOMATIC) ChannelMode_Temp;

    /* To store the status CanId found or not */
    VAR(boolean, AUTOMATIC) CanIdMatchFound_b;

    /* If CAN Interface is uninitialized, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR((FALSE == CanIf_Init_Flag), CANIF_RX_INDICATION_SID, CANIF_E_UNINIT)

    #if ((CANIF_DLC_CHECK == STD_OFF) && (CANIF_DEV_ERROR_DETECT == STD_OFF))
    (void)CanDlc;
    #endif

    #if((CANIF_DEV_ERROR_DETECT == STD_OFF)&&(CANIF_BASIC_CAN_SUPPORT == STD_OFF)&&(CANIF_CANNM_TXID_FILTER == STD_OFF))
    (void)CanId;
    /* #else */
    /* Remove the FD bit passed from the below layer */
    /*  CanId = CanId & CANIF_FDBIT_MASK; */

    #endif


#if(CANIF_VARIANT_INFO == 1)
    RxPduCfg_pcs = CanIf_RxPduConfig;
    HrhCfg_pcs = CanIf_HrhConfig;
    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    Num_Hrh_Handles_Temp = CANIF_NUM_HRH_HANDLES;
    #endif
    ControllerState_ps = CanIf_ControllerState;
    #if (CANIF_BASIC_CAN_SUPPORT_LIST != STD_OFF)
    CanIdListCfg_pcs = CanIf_CanIdListConfig;
    #endif
    #if (CANIF_RXPDU_CANID_RANGE != STD_OFF)
    CanIdRangeCfg_pcs = CanIf_RxPduCanIdRangeConfig;
    #endif
    #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF && CANIF_PUBLIC_BUSOFF_RECOVERY_FROM_RXINDICATION != STD_OFF )
    TxConfStatus_Temp = CanIf_TxConf_State;
    #endif
    #if(CANIF_CANNM_TXID_FILTER != STD_OFF)
    CanNmTxIdPtr_Temp = CanIf_CanNmTxId;
    #endif
    #if (CANIF_READRXPDU_NOTIFY_STATUS_API != STD_OFF)
    RxNotifPtr_Temp = CanIf_RxNotification;
    #endif
    #if (CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
    NewRxMsgPtr_Temp = CanIf_NewMsg_Rx;
    #endif
    #if (CANIF_CDD_RX_ENABLED != STD_OFF)
    CddRxCbkPtr_Temp = CanIf_CddRxCbk;
    #endif
    #if (CANIF_READBUFFERID != STD_OFF)
    J1939RxCbkPtr_Temp = &CanIf_J1939RxCbk;
    #endif
    #if (CANIF_USER_RX_ENABLED != STD_OFF)
    RxCbkPtr_Temp = CanIf_RxCbk;
    #endif
#else
    RxPduCfg_pcs = CanIf_ConfigSetPtr->RxPduConfig;
    HrhCfg_pcs = CanIf_ConfigSetPtr->HrhConfig;
    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    Num_Hrh_Handles_Temp = CanIf_ConfigSetPtr->NumHrhHandles;
    #endif
    ControllerState_ps = CanIf_ConfigSetPtr->CtrlStatePtr;
    #if (CANIF_BASIC_CAN_SUPPORT_LIST != STD_OFF)
    CanIdListCfg_pcs = CanIf_ConfigSetPtr->ListCfgPtr;
    #endif
    #if (CANIF_RXPDU_CANID_RANGE != STD_OFF)
    CanIdRangeCfg_pcs = CanIf_ConfigSetPtr->RangeCfgPtr;
    #endif
    #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF && CANIF_PUBLIC_BUSOFF_RECOVERY_FROM_RXINDICATION != STD_OFF )
    TxConfStatus_Temp = CanIf_ConfigSetPtr->TxConfStatusPtr;
    #endif
    #if(CANIF_CANNM_TXID_FILTER != STD_OFF)
    CanNmTxIdPtr_Temp = CanIf_ConfigSetPtr->NmtxIdPtr;
    #endif
    #if (CANIF_READRXPDU_NOTIFY_STATUS_API != STD_OFF)
    RxNotifPtr_Temp = CanIf_ConfigSetPtr->RxNotifPtr;
    #endif
    #if (CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
    NewRxMsgPtr_Temp = CanIf_ConfigSetPtr->NewRxMsgPtr;
    #endif
    #if (CANIF_CDD_RX_ENABLED != STD_OFF)
    CddRxCbkPtr_Temp = CanIf_ConfigSetPtr->RxCDDCbkPtr;
    #endif
    #if (CANIF_READBUFFERID != STD_OFF)
    J1939RxCbkPtr_Temp = CanIf_ConfigSetPtr->RxJ1939CbkPtr;
    #endif
    #if (CANIF_USER_RX_ENABLED != STD_OFF)
    RxCbkPtr_Temp = CanIf_ConfigSetPtr->RxUSERCbkPtr;
    #endif
#endif

    #if (CANIF_DLC_CHECK != STD_OFF)
    #if(CANIF_VARIANT_INFO == 1)
    CallBackPtr_Temp = &CanIf_Callback;
    #else
    CallBackPtr_Temp = CanIf_ConfigSetPtr->CallbackPtr;
    #endif
    #endif

    /* If HRH is invalid, report to DET and exit the function*/
    CANIF_DET_REPORT_ERROR((Hrh >= Num_Hrh_Handles_Temp), CANIF_RX_INDICATION_SID, CANIF_E_PARAM_HRH)

    /* If Dlc is invalid, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR((CanDlc > CANIF_MAX_DLC), CANIF_RX_INDICATION_SID, CANIF_E_PARAM_DLC)

    /* If CanSduPtr is null, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR((NULL_PTR == CanSduPtr), CANIF_RX_INDICATION_SID, CANIF_E_PARAM_POINTER)

    /* Initialize pointer to HRH configuration structure
     * Get the location by using the Base address of the HRH structure*/
    #if(CANIF_VARIANT_INFO == 1)
    HrhCfg_pcs = CanIf_HrhConfig + Hrh;
    #else
    HrhCfg_pcs = (CanIf_ConfigSetPtr->HrhConfig) + Hrh;
    #endif


    /*The calling of CanIf_RxIndication() also indicates that the controller has recovered from bus-off */
    #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF && CANIF_PUBLIC_BUSOFF_RECOVERY_FROM_RXINDICATION != STD_OFF )

    /* Enter Critical Section */
    SchM_Enter_CanIf_TxRxNotifNoNest();

    if( *(TxConfStatus_Temp + (HrhCfg_pcs->ControllerId)) != CANIF_TX_RX_NOTIFICATION)
    {
        /* Reset Rx Confirmation state for each controller*/
        *(TxConfStatus_Temp + (HrhCfg_pcs->ControllerId)) = CANIF_TX_RX_NOTIFICATION;

    }

    /* Leave Critical Section */
    SchM_Exit_CanIf_TxRxNotifNoNest();

    #endif

    /* Initialization */
    StopExe = FALSE;
    PduId = 0;

    /* Initialize the pointer to ControllerState
     * Get the location by using the Base address of the Controller state structure*/

    /*Enter critical section*/
    SchM_Enter_CanIf_ControllerState();

    #if(CANIF_VARIANT_INFO == 1)
    ControllerState_ps =  CanIf_ControllerState + (HrhCfg_pcs->ControllerId);
    #else
    ControllerState_ps = (CanIf_ConfigSetPtr->CtrlStatePtr) + (HrhCfg_pcs->ControllerId);
    #endif

    /*Make a local copy of Device mode and Channel mode*/
    DeviceMode_Temp = ControllerState_ps->DeviceMode;
    ChannelMode_Temp = ControllerState_ps->ChannelMode;

    /*Leave critical section*/
    SchM_Exit_CanIf_ControllerState();

    /* FC_VariationPoint_START */
    #if ((CANIF_BASIC_CAN_SUPPORT != STD_OFF) || (CANIF_CANNM_TXID_FILTER != STD_OFF))
    #if((CANIF_EXTENDED_ID == STD_ON)||(CANIF_SETDYNAMICTXID_API == STD_ON))
    /* mask values to consider two MSB */
    CanFDMask = 0xC0000000UL;
    #else
    CanFDMask = 0xC000U;
    #endif
	#endif

    /*shifting the canid bits to access two MSB's */
    /* MR12 RULE 12.2, VIOLATION Warning is "Not Critical" :The left operand of shift operator is lower in size compared to right operand, as the left operand is only used to store two bits for which unit8 is sufficient  */
    CanifMSBbits_u8= (uint8)(CanId>>CANIF_CANID_BIT_SHIFT);
    /* FC_VariationPoint_END */

    PduId = HrhCfg_pcs->PduIdx;
    /* FC_VariationPoint_START */
    /* Initialize pointer to Rx L-PDU structure
     * Get the location by using the Base address of the Rx-Pdu structure*/
    #if(CANIF_VARIANT_INFO == 1)
    RxPduCfg_pcs = CanIf_RxPduConfig + PduId;
    #else
    RxPduCfg_pcs = (CanIf_ConfigSetPtr->RxPduConfig) + PduId;
    #endif
    /* FC_VariationPoint_END */

    /* If CanId is invalid, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR((((CanifMSBbits_u8 == CANIF_ZERO)||(CanifMSBbits_u8 == CANIF_ONE)) && ((CanId & CANIF_MSB_BIT_RESET) > CANIF_CAN_STD_VAL)),
                                  CANIF_RX_INDICATION_SID, CANIF_E_PARAM_CANID)

    CANIF_DET_REPORT_ERROR((((CanifMSBbits_u8 == CANIF_TWO)||(CanifMSBbits_u8 == CANIF_THREE)) && ((CanId & CANIF_MSB_BIT_RESET)  > CANIF_CAN_XTD_VAL)),
                                  CANIF_RX_INDICATION_SID, CANIF_E_PARAM_CANID)


    #if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
    if((ControllerState_ps->BlPnCntr == TRUE)&&(ControllerState_ps->BlPnTxFilter == TRUE))
    {
        ControllerState_ps->BlPnTxFilter = FALSE;
    }
    #endif

    /* Check the controller mode is started and Channel mode is offline */
    if(    ( CANIF_CS_STARTED                   == DeviceMode_Temp  ) &&
           ( CANIF_GET_RX_ONLINE                != ChannelMode_Temp ) &&
           ( CANIF_GET_ONLINE                   != ChannelMode_Temp ) &&
           ( CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE != ChannelMode_Temp )
      )
    {
        /*Check if the validation is to be stored for the controller*/
        #if (CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)

        /*If CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM is STD_ON, update CanIf_NewMsg_Rx[] only if the
        * Rx-Pdu belongs to CANNM. If STD_OFF, update for any Rx-Pdu.*/
        #if(STD_OFF != CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM)
        if(CANNM == RxPduCfg_pcs->User)
        #endif
        {
           /*Enter critical section*/
           SchM_Enter_CanIf_NewMsgRxWkpEvtNoNest();

           /*Update the validation status for the controller only if it was reset*/
           if(*(NewRxMsgPtr_Temp + (HrhCfg_pcs->ControllerId)) == CANIF_RESET)
           {
               /* Store the reception of a new CAN message after wakeup */
               *(NewRxMsgPtr_Temp + (HrhCfg_pcs->ControllerId)) = CANIF_SET;
           }

           /*Leave critical section*/
           SchM_Exit_CanIf_NewMsgRxWkpEvtNoNest();
        }
        #endif
    }

    IdFound = FALSE;

    /* Check the controller mode and the channel mode of the Rx path */
    if(    (CANIF_CS_STARTED == DeviceMode_Temp)
        && (CANIF_GET_OFFLINE != ChannelMode_Temp)
        && (CANIF_GET_TX_ONLINE != ChannelMode_Temp)
        && (CANIF_GET_OFFLINE_ACTIVE != ChannelMode_Temp)
      )
    {
        switch(HrhCfg_pcs->HrhInfo)
        {
            /* FULL CAN Support */
            case CANIF_FULL:
                /* Get the Rx L-Pdu Id from the HRH configuration as there is one to one mapping
                between HRH and Rx L-Pdu */
                PduId = HrhCfg_pcs->PduIdx;
                Index_u8 =0;
                NoOfCanId_u32 = HrhCfg_pcs->NumCanId;
                /* FC_VariationPoint_START */
                /* Initialize pointer to Rx L-PDU structure
                * Get the location by using the Base address of the Rx-Pdu structure*/
                while((NoOfCanId_u32 != CANIF_ZERO)&&(Index_u8 <NoOfCanId_u32)&&(IdFound ==FALSE))
                {
                    #if(CANIF_VARIANT_INFO == 1)
                    RxPduCfg_pcs = CanIf_RxPduConfig + PduId;
                    #else
                    RxPduCfg_pcs = (CanIf_ConfigSetPtr->RxPduConfig) + PduId;
                    #endif


                    #if (CANIF_CALIBRATION == STD_ON)
                    if((((RxPduCfg_pcs->CanIdType) & CANIF_CANID_TYPE_MASK) ==(((RxPduCfg_pcs->CanIdType)>> CANIF_FOUR) & CanifMSBbits_u8))&&((CanId & CANIF_FDBIT_MASK) == (HrhCfg_pcs->getCanId())))
                    #else
                    if((((RxPduCfg_pcs->CanIdType) & CANIF_CANID_TYPE_MASK) ==(((RxPduCfg_pcs->CanIdType)>> CANIF_FOUR) & CanifMSBbits_u8))&&((CanId & CANIF_FDBIT_MASK) == (HrhCfg_pcs->CanId)))
                    #endif
                    {
                        /* The Rx L-Pdu is found */
                        IdFound = TRUE;
                        break;
                    }
                    else
                    {
                        /* The Rx L-Pdu is not found */
                        IdFound = FALSE;
                    }
                    /* FC_VariationPoint_END */
                    Index_u8++;
                    PduId++;
                }
            break;

            #if (CANIF_BASIC_CAN_SUPPORT != STD_OFF)

            /* Only if configuration of list of CanIds is supported */
            #if (CANIF_BASIC_CAN_SUPPORT_LIST != STD_OFF)

            /* List of CanIds with S/w filter True */
            case CANIF_BASIC_LIST_SFON:
                /*Proceed to check in the List-CanIds only if the current config set supports CanId List*/
                if(CanIdListCfg_pcs != NULL_PTR)
                {
                    /* Initialize the start and end index of the list for searching */
                    LowVal  = HrhCfg_pcs->PduIdx;
                    HighVal = (LowVal + HrhCfg_pcs->NumCanId) - (uint32)1;

                    /* Search among all the configured CanIds using Linear search algorithm till the Rx L-Pdu Id is found */
                    while((LowVal <= HighVal) && (IdFound == FALSE))
                    {
                        /*Point to the next location
                        * Get the location by using the Base address of the CanIf List structure*/
                        #if(CANIF_VARIANT_INFO == 1)
                        CanIdListCfg_pcs = CanIf_CanIdListConfig + LowVal;
                        #else
                        CanIdListCfg_pcs = (CanIf_ConfigSetPtr->ListCfgPtr) + LowVal;
                        #endif

                        /* Check whether the CanId lies in the upper half of the list */
                        if( (CanId & (~CanFDMask)) == CanIdListCfg_pcs->CanId )
                        {
                            PduId = CanIdListCfg_pcs->PduIdx;
                            /* Initialize pointer to Rx L-PDU structure
                             * Get the location by using the Base address of the Rx-Pdu structure*/
                            #if(CANIF_VARIANT_INFO == 1)
                            RxPduCfg_pcs = CanIf_RxPduConfig + PduId;
                            #else
                            RxPduCfg_pcs = (CanIf_ConfigSetPtr->RxPduConfig) + PduId;
                            #endif


                            /* validate if the canId type of recievied id is same as configured */

                            if(((RxPduCfg_pcs->CanIdType) & CANIF_CANID_TYPE_MASK) == (((RxPduCfg_pcs->CanIdType)>> CANIF_FOUR) & CanifMSBbits_u8))
                            {
                               /* The Rx L-Pdu is found */
                               IdFound = TRUE;
                            }
                            else
                            {
                                  LowVal++;
                            }

                        }
                        else
                        {
                          LowVal++;
                        }
                    }
                }
            break;
            #endif

            /* Only if configuration of Multiple Range of CanIds is supported */
            #if (CANIF_RXPDU_CANID_RANGE != STD_OFF)

            /* Range of CanIds with S/w filter True and supporting multiple target Id */
            case CANIF_BASIC_RANGE_SFON_MULTGT:

                if(CanIdRangeCfg_pcs != NULL_PTR)
                {
                    CanIdMatchFound_b = FALSE;

                    /* Initialize the index of the list for searching */
                    LowerLimit  = HrhCfg_pcs->PduIdx;
                    UpperLimit = (LowerLimit + HrhCfg_pcs->NumCanId) - (uint32)1;

                    /* Search among all the configured CanIds till the Rx L-Pdu Id is found */
                    while((LowerLimit <= UpperLimit) && (IdFound == FALSE))
                    {
                        /*Point the CanId-Range location
                         * Get the location by using the Base address of the CanIf List structure*/
                        #if(CANIF_VARIANT_INFO == 1)
                        CanIdRangeCfg_pcs = CanIf_RxPduCanIdRangeConfig + LowerLimit;
                        #else
                        CanIdRangeCfg_pcs = (CanIf_ConfigSetPtr->RangeCfgPtr) + LowerLimit;
                        #endif

                        /* Check if CanId range is not configured with HRHRangeMask */
                        #if (CANIF_CALIBRATION == STD_ON)
                        if( HrhCfg_pcs->getCanIdMask == NULL_PTR )
                        #else
                        if( HrhCfg_pcs->HrhRangeMask == CANID_MASK_DEFAULT )
                        #endif
                        {
                            /* check if CanId found in the RxPdu */
                            if( ((CanId & (~CanFDMask)) >= CanIdRangeCfg_pcs->LowerCanId) && ((CanId & (~CanFDMask)) <= CanIdRangeCfg_pcs->UpperCanId))
                            {
                                /* CanId found */
                                CanIdMatchFound_b = TRUE;
                            }
                        }
                        else
                        {
                            /* check if CanId found in the RxPdu
                             * Here CanIdRangeCfg_pcs->UpperCanId is RxPduCanIdMask and
                             *      CanIdRangeCfg_pcs->LowerCanId is RxPduCanId
                             */
                            if( ((CanId & (~CanFDMask)) & CanIdRangeCfg_pcs->UpperCanId) == (CanIdRangeCfg_pcs->LowerCanId & CanIdRangeCfg_pcs->UpperCanId) )
                            {
                                /* CanId found */
                                CanIdMatchFound_b = TRUE;
                            }
                        }

                        if( TRUE == CanIdMatchFound_b )
                        {
                            /* Get the Rx L-Pdu Id from the CanId Range configuration */
                            PduId = CanIdRangeCfg_pcs->PduIdx;

                            /* FC_VariationPoint_START */
                            /* Initialize pointer to Rx L-PDU structure
                            * Get the location by using the Base address of the Rx-Pdu structure*/
                            #if(CANIF_VARIANT_INFO == 1)
                            RxPduCfg_pcs = CanIf_RxPduConfig + PduId;
                            #else
                            RxPduCfg_pcs = (CanIf_ConfigSetPtr->RxPduConfig) + PduId;
                            #endif

                            if(((RxPduCfg_pcs->CanIdType) & CANIF_CANID_TYPE_MASK) == (((RxPduCfg_pcs->CanIdType)>> CANIF_FOUR) & CanifMSBbits_u8))
                            {
                                /* CanId type matched */
                                IdFound = TRUE;
                            }
                            else
                            {
                                LowerLimit = LowerLimit + (uint32)1;
                            }
                            /* FC_VariationPoint_END */

                        } /* end if TRUE == CanIdMatchFound_b ) */
                        else
                        {
                            LowerLimit = LowerLimit + (uint32)1;
                            if(LowerLimit > UpperLimit)
                            {
                                /* The Rx L-Pdu is not found */
                                IdFound = FALSE;
                            }
                        }

                    }/*End-of while loop */

                } /* end if(CanIdRangeCfg_pcs != NULL_PTR) */

            break;
            #endif

            /* Range of CanIds with S/w filter True and supporting single target Id */
            case CANIF_BASIC_RANGE_SFON_SINTGT:
            {
                CanIdMatchFound_b = FALSE;

                /* Check if CanId range is not configured with HRHRangeMask */
                #if (CANIF_CALIBRATION == STD_ON)
                if( HrhCfg_pcs->getCanIdMask == NULL_PTR )
                #else
                if( HrhCfg_pcs->HrhRangeMask == CANID_MASK_DEFAULT )
                #endif
                {
                    /* Check whether the CanId is present within the range */
                    /* FC_VariationPoint_START */
                    #if (CANIF_CALIBRATION == STD_ON)
                        if(((CanId & (~CanFDMask)) >= (HrhCfg_pcs->getCanId())) && ((CanId & (~CanFDMask)) <= (((HrhCfg_pcs->getCanId()) + (HrhCfg_pcs->NumCanId)) - 1u)))
                    #else
                    /* FC_VariationPoint_END */
                    /* FC_VariationPoint_START */

                    if(((CanId & (~CanFDMask)) >= (HrhCfg_pcs->CanId)) && ((CanId & (~CanFDMask)) <= (((HrhCfg_pcs->CanId) + (HrhCfg_pcs->NumCanId)) - 1u)))
                    /* FC_VariationPoint_END */
                    /* FC_VariationPoint_START */
                    #endif
                    /* FC_VariationPoint_END */
                    {
                        /* CanId found */
                        CanIdMatchFound_b = TRUE;
                    }
                }
                else
                {
                    /* Check whether the CanId is present within the range */
                    /* FC_VariationPoint_START */
                    #if (CANIF_CALIBRATION == STD_ON)
                    if( ((CanId & (~CanFDMask)) & HrhCfg_pcs->getCanIdMask()) == (HrhCfg_pcs->getCanId() & HrhCfg_pcs->getCanIdMask()) )
                    #else
                    /* FC_VariationPoint_END */
                    if( ((CanId & (~CanFDMask)) & HrhCfg_pcs->HrhRangeMask) == (HrhCfg_pcs->CanId & HrhCfg_pcs->HrhRangeMask) )
                    /* FC_VariationPoint_START */
                    #endif
                    /* FC_VariationPoint_END */
                    {
                        /* CanId found */
                        CanIdMatchFound_b = TRUE;
                    }
                }

                if ( TRUE == CanIdMatchFound_b )
                {
                    /* Get the Rx L-Pdu Id from the HRH configuration as there is one to one mapping
                       between HRH and Rx L-Pdu */
                    PduId = HrhCfg_pcs->PduIdx;

                    /* Initialize pointer to Rx L-PDU structure
                           * Get the location by using the Base address of the Rx-Pdu structure*/
                    #if(CANIF_VARIANT_INFO == 1)
                    RxPduCfg_pcs = CanIf_RxPduConfig + PduId;
                    #else
                    RxPduCfg_pcs = (CanIf_ConfigSetPtr->RxPduConfig) + PduId;
                    #endif

                    if(((RxPduCfg_pcs->CanIdType) & CANIF_CANID_TYPE_MASK) == (((RxPduCfg_pcs->CanIdType)>> CANIF_FOUR) & CanifMSBbits_u8))
                    {
                        /* CanId type matched */
                        IdFound = TRUE;
                    }
                    else
                    {
                        /* CanId type mismatch */
                        IdFound = FALSE;
                    }
                }
            }
            break;

#endif /* end of #if (CANIF_BASIC_CAN_SUPPORT != STD_OFF) */

            default:
                /* The Rx L-Pdu is not found */
                IdFound = FALSE;
            break;
        } /* end of switch(HrhCfg_pcs->HrhInfo) */

        /* If the Rx L-Pdu Id is not found, stop the execution of the function */
        if(IdFound == FALSE)
        {
            StopExe = TRUE;
        }
        else
        {
            /* FC_VariationPoint_START */
            #if(CANIF_METADATA_SUPPORT == STD_ON)
            if(RxPduCfg_pcs->MetaDataLength_u32 >= 1u)
            {
                /*copy received canid to local variable, discard two MSB bits*/
                CanId_Temp_u32 = (uint32)(CanId & CANIF_MSB_BIT_RESET);

                /*Calculate SduLength which is sum of DLC and metadatalength*/
                SduLength_u32 = CanDlc + RxPduCfg_pcs->MetaDataLength_u32;

                /*copy the payload data to SduDataBuffer as per DLC*/
                for(Payload_Index_uo=0; Payload_Index_uo < CanDlc; Payload_Index_uo++)
                {
                    SduDataBuffer_au8[Payload_Index_uo] = CanSduPtr[Payload_Index_uo];
                }

                /*copy the received canid bytes into SduDataBuffer with LSB byte first after the payload data*/
                for(Metadata_Index_uo = CanDlc; Metadata_Index_uo < SduLength_u32; Metadata_Index_uo++)
                {
                    SduDataBuffer_au8[Metadata_Index_uo]=(uint8)CanId_Temp_u32;
                    CanId_Temp_u32 = (CanId_Temp_u32>>SHIFT_8);
                }
            }
            #endif
            /* FC_VariationPoint_END */
        }

        /* Filtering of CanId if it belongs to CANNM */
        #if(CANIF_CANNM_TXID_FILTER != STD_OFF)

        /* MR12 RULE 1.3 VIOLATION: The pointer will never be dereferenced when it is NULL       */
        /* Check if the received CanId is among the CanNm transmit CanIds */
        if(    (FALSE == StopExe)
            && (RxPduCfg_pcs->User == CANNM)
            && (CanNmTxIdPtr_Temp != NULL_PTR)
            && (*(CanNmTxIdPtr_Temp + (RxPduCfg_pcs->TargetRxPduId)) == (CanId & (~CanFDMask))))
        {
            StopExe = TRUE;
        }
        #endif

        /* DLC check */
        #if (CANIF_DLC_CHECK != STD_OFF)

        /* MR12 RULE 1.3 VIOLATION: The pointer will never be dereferenced when it is NULL       */
        /* Check whether a non zero DLC is configured and if the received DLC is less than the configured DLC */
        /* FC_VariationPoint_START */
        #if (CANIF_CALIBRATION == STD_ON)
        if((FALSE == StopExe) && ((RxPduCfg_pcs->getDlc()) != 0) && (CanDlc < (RxPduCfg_pcs->getDlc())))
        #else
        /* FC_VariationPoint_END */
        if((FALSE == StopExe) && ((RxPduCfg_pcs->Dlc) != 0) && (CanDlc < (RxPduCfg_pcs->Dlc)))
        /* FC_VariationPoint_START */
        #endif
        /* FC_VariationPoint_END */
        {
            /* Invalid Dlc */

            StopExe = TRUE;
            /* FC_VariationPoint_START */
            /* Check whether the Dlc error function has been configured */
            if(NULL_PTR != CallBackPtr_Temp->Dlc_Error_Notification)
            {
                /* Report DLC error */
                (void)CallBackPtr_Temp->Dlc_Error_Notification(RxPduCfg_pcs->RxPduId, CanDlc);
            }
            /* FC_VariationPoint_END */

            /* Indicate DET about error in Dlc */
            /* TRUE is passed since the check (CanDlc < RxPduCfg_pcs->Dlc) is already satisfied above */
            /* MR12 RULE 14.3, VIOLATION: Warning is "Not Critical". DET condition is intentionally made as True to
             * report DET error as it is invalid DLC case */
            CANIF_DET_REPORT_ERROR(TRUE, CANIF_RX_INDICATION_SID, CANIF_E_INVALID_DLC);
        }
        #endif

        if(FALSE == StopExe)
        {
            #if (CANIF_READRXPDU_NOTIFY_STATUS_API != STD_OFF)
            /* Check whether the notification can be read */
            if((HrhCfg_pcs->ReadRxPdu == CANIF_READ_NOTIFSTATUS_DATA) ||
               (HrhCfg_pcs->ReadRxPdu == CANIF_READ_NOTIFSTATUS))
            {
                /* Enter Critical Section */
                SchM_Enter_CanIf_TxRxNotifNoNest();

                /* Update the notification status */
                *(RxNotifPtr_Temp + PduId) = CANIF_TX_RX_NOTIFICATION;

                /* Leave Critical Section */
                SchM_Exit_CanIf_TxRxNotifNoNest();

            }
            #endif

            #if (CANIF_READRXPDU_DATA_API != STD_OFF)
            /* Check whether the data can be read */
            if((HrhCfg_pcs->ReadRxPdu == CANIF_READ_NOTIFSTATUS_DATA) || (HrhCfg_pcs->ReadRxPdu == CANIF_READ_DATA))
            {
                /* FC_VariationPoint_START */
                #if(CANIF_METADATA_SUPPORT == STD_ON)
                if(RxPduCfg_pcs->MetaDataLength_u32 >= 1u)
                {
                    /* Update the Rx buffer */
                    CanIf_WriteRxBuffer(SduDataBuffer_au8, RxPduCfg_pcs);
                }
                else
                #endif
                /* FC_VariationPoint_END */
                {
                    /* Update the Rx buffer */
                    CanIf_WriteRxBuffer(CanSduPtr, RxPduCfg_pcs);
                }
            }
            #endif



            /* Indicate application about reception of a message */
            /* MR12 RULE 1.3 VIOLATION: The pointer will never be dereferenced when it is NULL       */
            switch(RxPduCfg_pcs->User)
            {
                #if (CANIF_PDUR_ENABLED != STD_OFF)
                case (PDUR):
                    UplRxPduId = RxPduCfg_pcs->TargetRxPduId;
                    /* FC_VariationPoint_START */
                    #if(CANIF_METADATA_SUPPORT == STD_ON)
                    if(RxPduCfg_pcs->MetaDataLength_u32 >= 1u)
                    {
                        UplRxPduPtr.SduLength = (PduLengthType)SduLength_u32;
                        UplRxPduPtr.SduDataPtr = (uint8*)(&SduDataBuffer_au8[0]);
                    }
                    else
                    #endif
                    /* FC_VariationPoint_END */
                    {
                        UplRxPduPtr.SduLength = (PduLengthType)CanDlc;
                        /* MR12 RULE 11.8 VIOLATION: This Warning is "Not Critical". The pointer cast is required.*/
                        UplRxPduPtr.SduDataPtr = (uint8*)CanSduPtr;
                    }

                    PduR_CanIfRxIndication(UplRxPduId, &UplRxPduPtr);
                break;
                #endif

                #if (CANIF_CANNM_ENABLED != STD_OFF)
                case (CANNM):
                    //UplRxPduId = RxPduCfg_pcs->TargetRxPduId;
                    UplRxPduId = 0;/*bug multi nm frames may cause data overflow*/
                    /* FC_VariationPoint_START */
                    #if(CANIF_METADATA_SUPPORT == STD_ON)
                    if(RxPduCfg_pcs->MetaDataLength_u32 >= 1u)
                    {
                        UplRxPduPtr.SduLength = (PduLengthType)SduLength_u32;
                        UplRxPduPtr.SduDataPtr = (uint8*)(&SduDataBuffer_au8[0]);
                    }
                    else
                    #endif
                    /* FC_VariationPoint_END */
                    {
                        UplRxPduPtr.SduLength = (PduLengthType)CanDlc;
                        /* MR12 RULE 11.8 VIOLATION: This Warning is "Not Critical". The pointer cast is required.*/
                        UplRxPduPtr.SduDataPtr = (uint8*)CanSduPtr;
                    }

                    CanNm_RxIndication(UplRxPduId, &UplRxPduPtr);
                break;
                #endif

                /* FC_VariationPoint_START */
                #if(CANIF_J1939NM_ENABLED != STD_OFF )
                case (J1939NM):
                #if(CANIF_METADATA_SUPPORT == STD_ON)
                {
                    UplRxPduId = RxPduCfg_pcs->TargetRxPduId;

                    if(RxPduCfg_pcs->MetaDataLength_u32 >= 1u)
                    {
                        UplRxPduPtr.SduLength = (PduLengthType)SduLength_u32;
                        UplRxPduPtr.SduDataPtr = (uint8*)(&SduDataBuffer_au8[0]);

                        J1939Nm_RxIndication(UplRxPduId, &UplRxPduPtr);
                    }
                }
                #endif
                break;
                #endif
                /* FC_VariationPoint_END */

                #if (CANIF_CANTP_ENABLED != STD_OFF)
                case CANTP:
                    UplRxPduId = RxPduCfg_pcs->TargetRxPduId;
                    /* FC_VariationPoint_START */
                    #if(CANIF_METADATA_SUPPORT == STD_ON)
                    if(RxPduCfg_pcs->MetaDataLength_u32 >= 1u)
                    {
                        UplRxPduPtr.SduLength = (PduLengthType)SduLength_u32;
                        UplRxPduPtr.SduDataPtr = (uint8*)(&SduDataBuffer_au8[0]);
                    }
                    else
                    #endif
                    /* FC_VariationPoint_END */
                    {
                        UplRxPduPtr.SduLength = (PduLengthType)CanDlc;
                        /* MR12 RULE 11.8 VIOLATION: This Warning is "Not Critical". The pointer cast is required.*/
                        UplRxPduPtr.SduDataPtr = (uint8*)(CanSduPtr);
                    }

                    CanTp_RxIndication(UplRxPduId, &UplRxPduPtr);
                break;
                #endif

                /* FC_VariationPoint_START */
                #if (CANIF_CANTSYN_ENABLED != STD_OFF)
                case CAN_TSYN:
                UplRxPduId = RxPduCfg_pcs->TargetRxPduId;

                #if(CANIF_METADATA_SUPPORT == STD_ON)
                if(RxPduCfg_pcs->MetaDataLength_u32 >= 1u)
                {
                    UplRxPduPtr.SduLength = (PduLengthType)SduLength_u32;
                    UplRxPduPtr.SduDataPtr = (uint8*)(&SduDataBuffer_au8[0]);
                }
                else
                #endif
                {
                    UplRxPduPtr.SduLength = (PduLengthType)CanDlc;
                    /* MR12 RULE 11.8 VIOLATION: This Warning is "Not Critical". The pointer cast is required.*/
                    UplRxPduPtr.SduDataPtr = (uint8*)CanSduPtr;
                }
                CanTSyn_RxIndication(UplRxPduId, &UplRxPduPtr);
                break;
                #endif
                /* FC_VariationPoint_END */

                #if (CANIF_XCP_ENABLED != STD_OFF)
                case XCP:
                    UplRxPduId = RxPduCfg_pcs->TargetRxPduId;
                    /* FC_VariationPoint_START */
                    #if(CANIF_METADATA_SUPPORT == STD_ON)
                    if(RxPduCfg_pcs->MetaDataLength_u32 >= 1u)
                    {
                        UplRxPduPtr.SduLength = (PduLengthType)SduLength_u32;
                    }
                    else
                    #endif
                    /* FC_VariationPoint_END */
                    {
                        UplRxPduPtr.SduLength = (PduLengthType)CanDlc;
                    }

                    /* FC_DeviationPoint_START */
                    /*Enter Critical Section */
                    SchM_Enter_CanIf_RxBufAccessNoNest();
                    /* FC_VariationPoint_START */
                    #if(CANIF_METADATA_SUPPORT == STD_ON)
                    if(RxPduCfg_pcs->MetaDataLength_u32 >= 1u)
                    {
                        /* MR12 RULE 11.3 VIOLATION: This Warning is "Not Critical". The pointer cast is required.*/
                        CanSduDataBuffer_Ptr = (uint8*)CanSduDataBuffer;
                        for(i = 0; i < SduLength_u32; i++)
                        {
                            CanSduDataBuffer_Ptr[i] = SduDataBuffer_au8[i];
                        }

                        UplRxPduPtr.SduDataPtr = (uint8*)CanSduDataBuffer_Ptr;
                    }
                    else
                    #endif
                    /* FC_VariationPoint_END */
                    {
                        /* MR12 RULE 11.3 VIOLATION: This Warning is "Not Critical". The pointer cast is required.*/
                        CanSduDataBuffer_Ptr = (uint8*)CanSduDataBuffer;
                        for(i = 0; i < CanDlc; i++)
                        {
                            CanSduDataBuffer_Ptr[i] = CanSduPtr[i];
                        }

                        UplRxPduPtr.SduDataPtr = (uint8*)CanSduDataBuffer_Ptr;
                    }
                    /* Leave Critical Section */
                    SchM_Exit_CanIf_RxBufAccessNoNest();
                    /* FC_DeviationPoint_END */

                    /* FC_CODE_START */
                    /* MR12 RULE 3.1, VIOLATION Warning is "Not Critical": The comment is needed during Code stripping for COMMASSO release*/
                    ///* MR12 RULE 11.8 VIOLATION: This Warning is "Not Critical". The pointer cast is required.*/
                    //UplRxPduPtr.SduDataPtr = (uint8*)CanSduPtr;
                    /* FC_CODE_END */

                    Xcp_CanIfRxIndication(UplRxPduId, &UplRxPduPtr);
                break;
                #endif

                #if (CANIF_J1939TP_ENABLED != STD_OFF)
                case J1939TP:
                    UplRxPduId = RxPduCfg_pcs->TargetRxPduId;
                    /* FC_VariationPoint_START */
                    #if(CANIF_METADATA_SUPPORT == STD_ON)
                    if(RxPduCfg_pcs->MetaDataLength_u32 >= 1u)
                    {
                        UplRxPduPtr.SduLength = (PduLengthType)SduLength_u32;
                        UplRxPduPtr.SduDataPtr = (uint8*)(&SduDataBuffer_au8[0]);
                    }
                    else
                    #endif
                    /* FC_VariationPoint_END */
                    {
                        UplRxPduPtr.SduLength = (PduLengthType)CanDlc;
                        /* MR12 RULE 11.8 VIOLATION: This Warning is "Not Critical". The pointer cast is required.*/
                        UplRxPduPtr.SduDataPtr = (uint8*)CanSduPtr;
                    }
                    J1939Tp_RxIndication(UplRxPduId, &UplRxPduPtr);
                break;
                #endif

                #if (CANIF_CDD_RX_ENABLED != STD_OFF)
                case CDD:
                    if((CddRxCbkPtr_Temp != NULL_PTR) && (NULL_PTR != ((CddRxCbkPtr_Temp +(RxPduCfg_pcs->CbkIdx))->CddRxIndication)))
                    {
                        UplRxPduId = RxPduCfg_pcs->TargetRxPduId;
                        /* FC_VariationPoint_START */
                        #if(CANIF_METADATA_SUPPORT == STD_ON)
                        if(RxPduCfg_pcs->MetaDataLength_u32 >= 1u)
                        {
                            UplRxPduPtr.SduLength = (PduLengthType)SduLength_u32;
                            UplRxPduPtr.SduDataPtr = (uint8*)(&SduDataBuffer_au8[0]);
                        }
                        else
                        #endif
                        /* FC_VariationPoint_END */
                        {
                            UplRxPduPtr.SduLength = (PduLengthType)CanDlc;
                            /* MR12 RULE 11.8 VIOLATION: This Warning is "Not Critical". The pointer cast is required.*/
                            UplRxPduPtr.SduDataPtr = (uint8*)CanSduPtr;
                        }

                        (CddRxCbkPtr_Temp +(RxPduCfg_pcs->CbkIdx))->CddRxIndication(UplRxPduId, &UplRxPduPtr);
                    }
                break;
                #endif

                #if (CANIF_USER_RX_ENABLED != STD_OFF)
                case USER:
                    if((RxCbkPtr_Temp != NULL_PTR) && (NULL_PTR != ((RxCbkPtr_Temp +(RxPduCfg_pcs->CbkIdx))->UserRxIndication)))
                    {
                        /* FC_VariationPoint_START */
                        #if(CANIF_METADATA_SUPPORT == STD_ON)
                        if(RxPduCfg_pcs->MetaDataLength_u32 >= 1u)
                        {
                            UserRxPduInfo.SduLength = (PduLengthType)SduLength_u32;
                            UserRxPduInfo.SduDataPtr = (uint8*)(&SduDataBuffer_au8[0]);
                        }
                        else
                        #endif
                        /* FC_VariationPoint_END */
                        {
                            UserRxPduInfo.SduLength = (PduLengthType)CanDlc;
                            /* MR12 RULE 11.8 VIOLATION: This Warning is "Not Critical". The pointer cast is required.*/
                            UserRxPduInfo.SduDataPtr = (uint8*)CanSduPtr;
                        }

                        CanId = CanId & CANIF_MSB_BIT_RESET;
                        UserRxPduInfo.SduCanId = CanId;

                        (RxCbkPtr_Temp +(RxPduCfg_pcs->CbkIdx))->UserRxIndication(RxPduCfg_pcs->TargetRxPduId, &UserRxPduInfo);
                    }
                break;
                #endif

                #if (CANIF_READBUFFERID != STD_OFF)
                case J1939:
                    if(J1939RxCbkPtr_Temp != NULL_PTR)
                    {
                        J1939RxCbkPtr_Temp->J1939RxIndication(Hrh, CanId, CanDlc, CanSduPtr);
                    }
                break;
                #endif

                default:
                    /* Nothing to do in default case */
                break;
            }

        }/* End of if(FALSE == StopExe) condition */

    } /* end of check the controller mode and the channel mode of the Rx path */
}/* End of CanIf_RxIndication() */
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"




