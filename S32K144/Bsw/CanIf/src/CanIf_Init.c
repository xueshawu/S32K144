

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

/********************************************************************************************************************/
/* Function name    : CanIf_Init                                                                                    */
/* Syntax           : FUNC(void, CANIF_CODE) CanIf_Init(P2CONST(CanIf_ConfigType, AUTOMATIC, CANIF_APPL_CONST)ConfigPtr)   */
/* Description      : This service initializes internal and external interfaces of the CAN Interface for the
                      further processing and initiates the setup of all underlying CAN drivers and CAN controllers.
                      All underlying CAN controllers still remain non operational.                                  */
/* Parameter        : ConfigPtr                                                                                     */
/* Return value     : None                                                                                          */
/********************************************************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC PATH,v(G) VIOLATION IN CanIf_Init: Function contains very simple "else if" statements and "switch-cases". HIS metric compliance would decrease readability and maintainability. */
FUNC(void, CANIF_CODE) CanIf_Init(P2CONST (CanIf_ConfigType, AUTOMATIC, CANIF_APPL_CONST) ConfigPtr)
{

    /* Pointer to Controller State configuration */
    P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) ControllerState_Temp;

    #if (CANIF_DYNAMIC_ID != STD_OFF)
    VAR(CanIf_CanIdType, AUTOMATIC) LdCanIdType;
    #endif
    /* FC_DeviationPoint_START */
    #if ((CANIF_DYNAMIC_ID != STD_OFF) || (CANIF_TRANSMIT_BUFFER != STD_OFF) || (CANIF_RECEIVE_BUFFER != STD_OFF))
    /* Index variable to loop through the Tx and Rx buffers */
    VAR(uint16_least, AUTOMATIC) index_u16;
    #endif
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)||(CANIF_SETDYNAMICTXID_API != STD_OFF) || (CANIF_READRXPDU_DATA_API != STD_OFF)
    //VAR(uint16_least, AUTOMATIC) index_u16;
    //#endif
    /* FC_CODE_END */
 #if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
    /* Index variable to loop through the Tx pdus */
    VAR(uint16_least, AUTOMATIC) TxPduindex;

    /* variable to store total no of txpdu's */
    VAR (uint16_least, AUTOMATIC) TotalTxPdus;
    #if (CANIF_DYNAMIC_ID == STD_OFF)
    /* variable to store total no of txpdu's */
    VAR (uint16_least, AUTOMATIC) TotalTxPduId;
    #endif
 #endif
    /*Index variable to loop through the Controllers*/
    VAR(uint8_least,AUTOMATIC) i;

    #if ((CANIF_DYNAMIC_ID != STD_OFF) || (CANIF_PUBLIC_PN_SUPPORT == STD_ON))
    /* Pointer to Tx Pdu configuration */
    P2CONST(CanIf_TxPduInfo, AUTOMATIC, AUTOMATIC) TxPduConfig_Temp;
    #endif

    /* FC_DeviationPoint_START */
    #if (CANIF_DYNAMIC_ID != STD_OFF)
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
    /* FC_CODE_END */

    /*Pointer to Dynamic Id array*/
    P2VAR(uint32, AUTOMATIC, AUTOMATIC) DynamicTxPduPtr_Temp;
    VAR (uint16_least, AUTOMATIC) CanIf_TotalTxPduId;
    #endif

    #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
    /*Pointer to hold the Tx-Confirmation state for each controller*/
    P2VAR(CanIf_NotifStatusType, AUTOMATIC,AUTOMATIC) TxConfStatePtr_Temp;
    #endif


    #if (CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
    /*Pointer to hold the wakeup event of each controller*/
    P2VAR(uint8, AUTOMATIC,AUTOMATIC) WkpEventPtr_Temp;

    /*Pointer to hold the new Rx-msg status for each controller*/
    P2VAR(uint8, AUTOMATIC,AUTOMATIC) NewRxMsgPtr_Temp;
    #endif

    /* FC_DeviationPoint_START */
    #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
    /*  FC_CODE_END */
    /*Pointer to the Tx-buffer*/
    P2VAR(uint8, AUTOMATIC,AUTOMATIC) TxBuffPtr_Temp;
    VAR (uint16_least, AUTOMATIC) CanIf_TxBuffer_Size;
    #endif

    /* FC_DeviationPoint_START */
    #if (CANIF_RECEIVE_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if (CANIF_READRXPDU_DATA_API != STD_OFF)
    /* FC_CODE_END */
    /*Pointer to Rx-buffer*/
    P2VAR(uint8, AUTOMATIC,AUTOMATIC) RxBuffPtr_Temp;
    VAR (uint16_least, AUTOMATIC) CanIf_RxBuffer_Size;
    #endif


    VAR (uint8, AUTOMATIC) CanIf_Num_Controllers;

    /*For PRE-COMPILE*/
    #if(CANIF_VARIANT_INFO == 1)

    /*initialise 'CanIf_Num_Controllers'*/
    CanIf_Num_Controllers = CANIF_NUM_CONTROLLERS;

    /*Initiliase 'ControllerState_Temp'*/
    ControllerState_Temp = CanIf_ControllerState;

    /*Initialise 'TxPduConfig_Temp' and 'DynamicTxPduPtr_Temp'*/
    /* FC_DeviationPoint_START */
    #if (CANIF_DYNAMIC_ID != STD_OFF)
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
    /* FC_CODE_END */
    /*Initialise 'CanIf_TotalTxPduId'*/
    CanIf_TotalTxPduId = (uint16_least)CANIF_NUM_STATIC_CANTXPDUIDS + (uint16_least)CANIF_NUM_DYNAMIC_CANTXPDUIDS;
    DynamicTxPduPtr_Temp = CanIf_Dynamic_CanTxPdu_CanId;
    #endif
#if (CANIF_PUBLIC_PN_SUPPORT == STD_ON) && (CANIF_DYNAMIC_ID == STD_OFF)
    TotalTxPduId= (uint16_least)CANIF_NUM_STATIC_CANTXPDUIDS;
#endif

 #if ((CANIF_DYNAMIC_ID != STD_OFF) || (CANIF_PUBLIC_PN_SUPPORT == STD_ON))
    TxPduConfig_Temp = CanIf_TxPduConfig;
#endif

    /*Initialise 'TxConfStatePtr_Temp'*/
    #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
    TxConfStatePtr_Temp = CanIf_TxConf_State;
    #endif

    /*Initialise 'WkpEventPtr_Temp' and 'NewRxMsgPtr_Temp'*/
    #if (CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
    WkpEventPtr_Temp = CanIf_WakeUp_Event;
    NewRxMsgPtr_Temp = CanIf_NewMsg_Rx;
    #endif

    /*Intialise 'TxBuffPtr_Temp'*/
    /* FC_DeviationPoint_START */
    #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
    /* FC_CODE_END */
    TxBuffPtr_Temp = CanIf_TxBuffer;

    /*Initialise 'CanIf_TxBuffer_Size'*/
    CanIf_TxBuffer_Size = CANIF_TXBUFFER_SIZE;
    #endif

    /*initialise 'RxBuffPtr_Temp'*/
    /* FC_DeviationPoint_START */
    #if (CANIF_RECEIVE_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if (CANIF_READRXPDU_DATA_API != STD_OFF)
    /* FC_CODE_END */
    RxBuffPtr_Temp = CanIf_RxBuffer;
    /*Initialise 'CanIf_RxBuffer_Size'*/
    CanIf_RxBuffer_Size = CANIF_RXBUFFER_SIZE;
    #endif

    /* The parameter ConfigPtr is not used */
    (void)ConfigPtr;

    /*For POST-BUILD*/
    #else

    /* If ConfigPtr is NULL, report to DET and return E_NOT_OK */
    CANIF_DET_REPORT_ERROR((ConfigPtr == NULL_PTR), CANIF_INIT_SID, CANIF_E_PARAM_POINTER)

    #if(CANIF_VARIANT_INFO == 3)
    {
        /* variable to read version info from CanIf_GetVersionInfo */
        VAR(Std_VersionInfoType, AUTOMATIC) versionInfo_s;

        /* Read the pre-compile version info */
        CanIf_GetVersionInfo(&versionInfo_s);

        /* Compare pre-compile & post-build version info */
        if(CanIf_CompareVersionInfo(&versionInfo_s, ConfigPtr->CanIf_VersionInfo))
        {
           /* versionInfo doesnt match .. Inform application */
           CanIfAppl_IncompatibleGenerator();

           /* Abort further initialisation ..CanIf will remain in UNINIT state */
           return;
        }
    }
    #endif

    /*Store the current config set pointer*/
    CanIf_ConfigSetPtr = ConfigPtr;

    /*Store the active config set*/
    CanIf_ActiveCfgSet = CanIf_ConfigSetPtr->CfgSetIndex;

    CanIf_Num_Controllers = CanIf_ConfigSetPtr->NumControllers;


    /*Initialise 'ControllerState_Temp'*/
    ControllerState_Temp = CanIf_ConfigSetPtr->CtrlStatePtr;

    /*Initialise 'TxPduConfig_Temp' and 'DynamicTxPduPtr_Temp'*/
    /* FC_DeviationPoint_START */
    #if (CANIF_DYNAMIC_ID != STD_OFF)
    /* FC_DeviationPoint_END */

            /* FC_CODE_START */
    //#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
     /* FC_CODE_END */
    CanIf_TotalTxPduId = CanIf_ConfigSetPtr->NumCanTxPduId + CanIf_ConfigSetPtr->NumDynamicCanTxPduId;
    DynamicTxPduPtr_Temp = CanIf_ConfigSetPtr->DynTxIdPtr;
    #endif
#if ((CANIF_DYNAMIC_ID != STD_OFF) || (CANIF_PUBLIC_PN_SUPPORT == STD_ON))
    TxPduConfig_Temp = CanIf_ConfigSetPtr->TxPduConfig;
#endif
#if (CANIF_PUBLIC_PN_SUPPORT == STD_ON) && (CANIF_DYNAMIC_ID == STD_OFF)
    TotalTxPduId = CanIf_ConfigSetPtr->NumCanTxPduId;
#endif
    /*Initialise 'TxConfStatePtr_Temp'*/
    #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
    TxConfStatePtr_Temp = CanIf_ConfigSetPtr->TxConfStatusPtr;
    #endif

    /*Initialise 'WkpEventPtr_Temp' and 'NewRxMsgPtr_Temp'*/
    #if (CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
    WkpEventPtr_Temp = CanIf_ConfigSetPtr->WkpEventPtr;
    NewRxMsgPtr_Temp = CanIf_ConfigSetPtr->NewRxMsgPtr;
    #endif

    /*Intialise 'TxBuffPtr_Temp'*/
    /* FC_DeviationPoint_START */
    #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
    /*  FC_CODE_END */
    TxBuffPtr_Temp = CanIf_ConfigSetPtr->TxBufferPtr;
    CanIf_TxBuffer_Size = CanIf_ConfigSetPtr->TxBufferSize;
    #endif

    /*initialise 'RxBuffPtr_Temp'*/
    /* FC_DeviationPoint_START */
    #if (CANIF_RECEIVE_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if (CANIF_READRXPDU_DATA_API != STD_OFF)
    /* FC_CODE_END */
    RxBuffPtr_Temp = CanIf_ConfigSetPtr->RxBufferPtr;
    CanIf_RxBuffer_Size = CanIf_ConfigSetPtr->RxBufferSize;
    #endif

    #endif/*CANIF_VARIANT_INFO*/

#if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
    #if (CANIF_DYNAMIC_ID != STD_OFF)
    TotalTxPdus= CanIf_TotalTxPduId;
    #else
    TotalTxPdus= TotalTxPduId;
    #endif
    /* Reset all the global variables and flags */
    for(i=0; i < CanIf_Num_Controllers; i++)
    {
        for(TxPduindex = 0; TxPduindex < TotalTxPdus; TxPduindex++)
        {
            if((((TxPduConfig_Temp +TxPduindex)->ControllerRefId) == i)&&(((TxPduConfig_Temp +TxPduindex)->PnSupport) == TRUE))
            {
                (ControllerState_Temp+i)->BlPnCntr =TRUE;
                break;
            }
        }
    }
#endif

    /* Reset all the global variables and flags */
    for(i=0; i < CanIf_Num_Controllers; i++)
    {
        /* Update the DeviceMode to CANIF_CS_UNINIT & ChannelMode to CANIF_GET_OFFLINE of each Controller */
        //ControllerState_Temp = CanIf_ControllerState + i;
        (ControllerState_Temp+i)->DeviceMode = CANIF_CS_UNINIT;
        (ControllerState_Temp+i)->ChannelMode = CANIF_GET_OFFLINE;
        /* as per requirement [SWS_CANIF_00863] PnTxFilter is enabled  */
        #if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
            if((ControllerState_Temp+i)->BlPnCntr == TRUE)
            {
                (ControllerState_Temp+i)->BlPnTxFilter = TRUE;
            }
            else
            {
                (ControllerState_Temp+i)->BlPnTxFilter = FALSE;
            }
        #endif

        #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
        /* Reset Tx Confirmation state for each controller*/
        *(TxConfStatePtr_Temp + i) = CANIF_NO_NOTIFICATION;
        #endif

        #if (CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
        /* Reset the WakeUp Event for each Controller */
        *(WkpEventPtr_Temp + i) = CANIF_RESET;

        /* Reset the 'new message received' status */
        *(NewRxMsgPtr_Temp + i) = CANIF_RESET;
        #endif
    }


    /* Copy the CanIds of dynamic TxPduIds from the configuration to the global array */
    /* FC_DeviationPoint_START */
    #if (CANIF_DYNAMIC_ID != STD_OFF)
    /* FC_DeviationPoint_END */
    /* FC_CODE_START */
    //#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
    /* FC_CODE_END */

    /*First check if Dynamic Tx-Ids are configured for this configset*/
    if(DynamicTxPduPtr_Temp != NULL_PTR)
    {
        for(index_u16 = 0; index_u16 < CanIf_TotalTxPduId; index_u16++)
        {
            //TxPduConfig_Temp = CanIf_TxPduConfig + index_u16;
            if((TxPduConfig_Temp +index_u16)->CanTxPduIdType != CANIF_STATIC)
            {
                 /* FC_VariationPoint_START */
                #if (CANIF_CALIBRATION == STD_ON)
                LdCanIdType = ((TxPduConfig_Temp +index_u16)->getCanId());
                #else
                LdCanIdType = ((TxPduConfig_Temp +index_u16)->CanId);
                #endif
                LdCanIdType &= CANIF_MSB_BIT_RESET;
                LdCanIdType |= (((Can_IdType)((TxPduConfig_Temp +index_u16)->CanIdType))<<CANIF_CANID_BIT_SHIFT);
                *(DynamicTxPduPtr_Temp + ((TxPduConfig_Temp +index_u16)->CanTxPduIdType)) = LdCanIdType;
                /* FC_VariationPoint_END */
            }
        }
    }

    #endif

    /* Reset TxBuffer */
    /* FC_DeviationPoint_START */
    #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
    /*  FC_CODE_END */
    /*First ensure that the pointer to Tx-buffer is not null*/
    if(TxBuffPtr_Temp != NULL_PTR)
    {
        for(index_u16 = 0; index_u16 < CanIf_TxBuffer_Size; index_u16++)
        {

            *(TxBuffPtr_Temp +index_u16) = 0x00;

        }
    }
    #endif

    /* Reset RxBuffer */
    /* FC_DeviationPoint_START */
    #if (CANIF_RECEIVE_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if (CANIF_READRXPDU_DATA_API != STD_OFF)
    /* FC_CODE_END */

    /*First ensure that the pointer to the Rx-buffer is not null*/
    if(RxBuffPtr_Temp != NULL_PTR)
    {
        for(index_u16 = 0; index_u16 < CanIf_RxBuffer_Size; index_u16++)
        {
            *(RxBuffPtr_Temp +index_u16) = 0x00;
        }
    }
    #endif

    /* Update the DeviceMode to CANIF_CS_STOPPED
     * IMPORTANT: Update the device mode to STOPPED only after all the variables / flags are initialised.
     *            Hence this has been done in a separate loop*/
    for(i=0; i < CanIf_Num_Controllers; i++)
    {
        //ControllerState_Temp = CanIf_ControllerState + i;
        (ControllerState_Temp +i)->DeviceMode = CANIF_CS_STOPPED;
    }



    /* TRUE implies CAN Interface is Initialised */
    CanIf_Init_Flag = TRUE;
}/* End of CanIf_Init() */

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"






/*CanIf_DeInit() function is required to de-initialise all the RAM areas of the previously active configset
 * This function is used only when Post-build is enabled. This function shall be exported via CanIf.h since
 * this needs to be used in the Integration code of EcuM*/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

FUNC(void, CANIF_CODE) CanIf_DeInit(P2CONST (CanIf_ConfigType, AUTOMATIC, CANIF_APPL_CONST) ConfigPtr)
{
#if (CANIF_VARIANT_INFO == 2) || (CANIF_VARIANT_INFO == 3)
    /* Index variable to loop through the Tx and Rx buffers */
    VAR(uint16_least, AUTOMATIC) index_u16;

    /* FC_DeviationPoint_START */
    #if ((CANIF_TRANSMIT_BUFFER != STD_OFF) || (CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF) || (CANIF_DYNAMIC_ID != STD_OFF))
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if ((CANIF_PUBLIC_TX_BUFFERING != STD_OFF) || (CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF) || (CANIF_SETDYNAMICTXID_API != STD_OFF))
    /*  FC_CODE_END */
    VAR (uint16_least, AUTOMATIC) CanIf_TotalTxPduId;
    #endif

    VAR (uint8, AUTOMATIC) CanIf_Num_Controllers;

    /*-------------------------------------------------------------------------------*/
    /*Pointers to the variable (Arrays) to be cleared during configset switch-over   */
    /*-------------------------------------------------------------------------------*/

 /* FC_DeviationPoint_START */
#if (CANIF_TRANSMIT_BUFFER != STD_OFF)
 /* FC_DeviationPoint_END */

        /* FC_CODE_START */
 //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
  /*  FC_CODE_END */
    /*Pointer to the Tx-buffer*/
    P2VAR(uint8, AUTOMATIC,AUTOMATIC) TxBuffPtr_Temp;
    P2VAR(boolean, AUTOMATIC, AUTOMATIC) TxBuffAllocPtr_Temp;
    VAR (uint16_least, AUTOMATIC) CanIf_TxBuffer_Size;
    #endif

    /* FC_DeviationPoint_START */
#if (CANIF_RECEIVE_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */

        /* FC_CODE_START */
     //#if (CANIF_READRXPDU_DATA_API != STD_OFF)
     /* FC_CODE_END */
    /*Pointer to Rx-buffer*/
    P2VAR(uint8, AUTOMATIC,AUTOMATIC) RxBuffPtr_Temp;
    VAR (uint16_least, AUTOMATIC) CanIf_RxBuffer_Size;
    #endif

#if (CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF)
    /*Pointer to read Tx-Notif status of the Tx-Pdu*/
    P2VAR(CanIf_NotifStatusType, AUTOMATIC,AUTOMATIC) TxNotifPtr_Temp;
    #endif

#if (CANIF_READRXPDU_NOTIFY_STATUS_API != STD_OFF)
    /*Pointer to read Rx-Notif status of the Rx-Pdu*/
    P2VAR(CanIf_NotifStatusType,TYPEDEF,CANIF_CFG_CONST)    RxNotifPtr_Temp;

    VAR (uint16_least, CANIF_CONST) CanIf_Num_CanRxPduId;
    #endif

#if (CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
    /*Pointer to hold the wakeup event of each controller*/
    P2VAR(uint8, AUTOMATIC,AUTOMATIC) WkpEventPtr_Temp;

    /*Pointer to hold the new Rx-msg status for each controller*/
    P2VAR(uint8, AUTOMATIC,AUTOMATIC) NewRxMsgPtr_Temp;
    #endif

    /* Pointer to Controller State configuration */
    P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) ControllerState_Temp;

#if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
    /*Pointer to hold the Tx-Confirmation state for each controller*/
    P2VAR(CanIf_NotifStatusType, AUTOMATIC,AUTOMATIC) TxConfStatePtr_Temp;
    #endif

    /* FC_DeviationPoint_START */
#if (CANIF_DYNAMIC_ID != STD_OFF)
     /* FC_DeviationPoint_END */

           /* FC_CODE_START */
         //#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
         /* FC_CODE_END */
    /*Pointer to Dynamic Id array*/
    P2VAR(uint32, AUTOMATIC, AUTOMATIC) DynamicTxPduPtr_Temp;
    /* Pointer to Tx Pdu configuration */
    P2CONST(CanIf_TxPduInfo, AUTOMATIC, AUTOMATIC) TxPduConfig_Temp;
    #endif

    /*-------------------------------------------------------------------------------*/
    /*Initialising the pointers with - the location to be cleared   */
    /*-------------------------------------------------------------------------------*/

    /* Set CanIf as Un-Initialised. This will be set to TRUE in the subsequent call of CanIf_Init() */
    CanIf_Init_Flag = FALSE;

    /* FC_DeviationPoint_START */
    #if ((CANIF_TRANSMIT_BUFFER != STD_OFF) || (CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF) || (CANIF_DYNAMIC_ID != STD_OFF))
    /* FC_DeviationPoint_END */

    /* FC_CODE_START */
    //#if ((CANIF_PUBLIC_TX_BUFFERING != STD_OFF) || (CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF) || (CANIF_SETDYNAMICTXID_API != STD_OFF))
    /*  FC_CODE_END */
    /*Get the total number of Tx-Pdus in the given configset*/
    CanIf_TotalTxPduId = (ConfigPtr->NumCanTxPduId) + (ConfigPtr->NumDynamicCanTxPduId);
    #endif

    /*Get the total number of Ctrls in the given configset*/
    CanIf_Num_Controllers = ConfigPtr->NumControllers;

 /* FC_DeviationPoint_START */
#if (CANIF_TRANSMIT_BUFFER != STD_OFF)
     /* FC_DeviationPoint_END */

        /* FC_CODE_START */
 //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
  /*  FC_CODE_END */
    /*Get the Tx-buffer pointer of the required configset*/
    TxBuffPtr_Temp = ConfigPtr->TxBufferPtr;

    /*Get the Tx-buffer flag array's pointer of the required configset*/
    TxBuffAllocPtr_Temp = ConfigPtr->TxBufferAllocPtr;

    /*Get the buffer size*/
    CanIf_TxBuffer_Size = ConfigPtr->TxBufferSize;
    #endif

    /* FC_DeviationPoint_START */
#if (CANIF_RECEIVE_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */

        /* FC_CODE_START */
     //#if (CANIF_READRXPDU_DATA_API != STD_OFF)
     /* FC_CODE_END */
    /*Get the Tx-buffer pointer of the required configset*/
    RxBuffPtr_Temp = ConfigPtr->RxBufferPtr;
    CanIf_RxBuffer_Size = ConfigPtr->RxBufferSize;
    #endif


#if (CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF)
    /*Pointer to read Tx-Notif status of the Tx-Pdus*/
    TxNotifPtr_Temp = ConfigPtr->TxNotifPtr;
    #endif

#if (CANIF_READRXPDU_NOTIFY_STATUS_API != STD_OFF)
    /*Pointer to read Rx-Notif status of the Rx-Pdus*/
    RxNotifPtr_Temp = ConfigPtr->RxNotifPtr;

    /*Get the total number of Rx-Pdus in the given configset*/
    CanIf_Num_CanRxPduId = ConfigPtr->NumCanRxPduId;
    #endif

#if (CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
    /*Pointer to hold the wakeup event of each controller*/
    WkpEventPtr_Temp = ConfigPtr->WkpEventPtr;

    /*Pointer to hold the new Rx-msg status for each controller*/
    NewRxMsgPtr_Temp = ConfigPtr->NewRxMsgPtr;
    #endif


    /* Pointer to Controller State configuration */
    ControllerState_Temp = ConfigPtr->CtrlStatePtr;

#if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
    /*Pointer to hold the Tx-Confirmation state for each controller*/
    TxConfStatePtr_Temp = ConfigPtr->TxConfStatusPtr;
    #endif


    /* FC_DeviationPoint_START */
#if (CANIF_DYNAMIC_ID != STD_OFF)
     /* FC_DeviationPoint_END */

           /* FC_CODE_START */
         //#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
         /* FC_CODE_END */
    /*Pointer to Dynamic Id array*/
    DynamicTxPduPtr_Temp = CanIf_ConfigSetPtr->DynTxIdPtr;

    /* Pointer to Tx Pdu configuration */
    TxPduConfig_Temp = ConfigPtr->TxPduConfig;
    #endif




 /* FC_DeviationPoint_START */
#if (CANIF_TRANSMIT_BUFFER != STD_OFF)
     /* FC_DeviationPoint_END */

        /* FC_CODE_START */
 //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
  /*  FC_CODE_END */
    /*First ensure that the pointer to Tx-buffer is not null*/
    if(TxBuffPtr_Temp != NULL_PTR)
    {
        /* Reset TxBuffer */
        for(index_u16 = 0; index_u16 < CanIf_TxBuffer_Size; index_u16++)
        {

               *(TxBuffPtr_Temp +index_u16) = 0x00;

        }
    }

    /*First ensure that the pointer to Tx-buffer flag is not null*/
    if(TxBuffAllocPtr_Temp != NULL_PTR)
    {
        /*Reset the TxBuffer flag*/
        for(index_u16 = 0; index_u16 < CanIf_TotalTxPduId; index_u16++)
        {

            *(TxBuffAllocPtr_Temp +index_u16) = FALSE;

        }
    }

    #endif


    /* FC_DeviationPoint_START */
#if (CANIF_RECEIVE_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */

        /* FC_CODE_START */
     //#if (CANIF_READRXPDU_DATA_API != STD_OFF)
     /* FC_CODE_END */
    /* Reset RxBuffer */

    /*First ensure that the pointer to Rx-buffer is not null*/
    if(RxBuffPtr_Temp != NULL_PTR)
    {
        for(index_u16 = 0; index_u16 < CanIf_RxBuffer_Size; index_u16++)
        {
            *(RxBuffPtr_Temp +index_u16) = 0x00;
        }
    }
    #endif


#if (CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF)
    /* Reset Tx-Notif buffer */
    for(index_u16 = 0; index_u16 < CanIf_TotalTxPduId; index_u16++)
    {
        *(TxNotifPtr_Temp +index_u16) = CANIF_NO_NOTIFICATION;
    }
    #endif

#if (CANIF_READRXPDU_NOTIFY_STATUS_API != STD_OFF)
    /* Reset Rx-Notif buffer */
    for(index_u16 = 0; index_u16 < CanIf_Num_CanRxPduId; index_u16++)
    {
        *(RxNotifPtr_Temp +index_u16) = CANIF_NO_NOTIFICATION;
    }
    #endif

    for(index_u16 = 0; index_u16 < CanIf_Num_Controllers; index_u16++)
    {
        #if (CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
        /* Reset the WakeUp Event for each Controller */
        *(WkpEventPtr_Temp + index_u16) = CANIF_RESET;

        /* Reset the 'new message received' status */
        *(NewRxMsgPtr_Temp + index_u16) = CANIF_RESET;

        #endif

        /* Reset the DeviceMode to CANIF_CS_STOPPED & ChannelMode to CANIF_GET_OFFLINE of each Controller */
        (ControllerState_Temp +index_u16)->ChannelMode = CANIF_GET_OFFLINE;

        #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
        *(TxConfStatePtr_Temp + index_u16) = CANIF_NO_NOTIFICATION;
        #endif

    }


    /* FC_DeviationPoint_START */
    #if (CANIF_DYNAMIC_ID != STD_OFF)
     /* FC_DeviationPoint_END */

           /* FC_CODE_START */
         //#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
         /* FC_CODE_END */
    /*First check if Dynamic Tx-Ids are configured for this configset*/
    if(DynamicTxPduPtr_Temp != NULL_PTR)
    {
        for(index_u16 = 0; index_u16 < CanIf_TotalTxPduId; index_u16++)
        {
            if((TxPduConfig_Temp +index_u16)->CanTxPduIdType != CANIF_STATIC)
            {
                /* FC_VariationPoint_START */
                #if (CANIF_CALIBRATION == STD_ON)
                *(DynamicTxPduPtr_Temp + ((TxPduConfig_Temp +index_u16)->CanTxPduIdType)) = ((TxPduConfig_Temp +index_u16)->getCanId());
                #else
                /* FC_VariationPoint_END */
                *(DynamicTxPduPtr_Temp + ((TxPduConfig_Temp +index_u16)->CanTxPduIdType)) = ((TxPduConfig_Temp +index_u16)->CanId);
                /* FC_VariationPoint_START */
                #endif
                /* FC_VariationPoint_END */
            }
        }
    }
    #endif

#else
    /*To avoid compiler warning*/
    (void)ConfigPtr;
#endif
}

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


