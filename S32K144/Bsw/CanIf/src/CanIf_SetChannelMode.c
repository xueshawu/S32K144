

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
/* Function name    : CanIf_SetPduMode                                                                          */
/* Syntax           : FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode(
                                                                        VAR(uint8,AUTOMATIC)Controller,
                                                                        VAR(CanIf_PduSetModeType,AUTOMATIC)PduModeRequest
                                                                        )                                       */
/* Description      : This service sets the requested mode at all L-PDUs of the predefined CAN controller.      */
/* Parameter        : Controller, PduModeRequest                                                                */
/* Return value     : E_OK / E_NOT_OK                                                                           */
/****************************************************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC PATH,v(G),STMT,RETURN VIOLATION IN CanIf_SetPduMode: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode(
                                                    VAR(uint8,AUTOMATIC) Controller,
                                                    VAR(CanIf_PduSetModeType,AUTOMATIC) PduModeRequest
                                                 )
{
    /* Pointer to Controller State configuration */
    P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) ControllerState_Temp;

    VAR(Std_ReturnType, AUTOMATIC ) Status;

    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    VAR (uint8, AUTOMATIC) CanIf_Num_Controllers;
    #endif

    /* If the CAN Interface is uninitialized, report to DET and return E_NOT_OK */
    CANIF_DET_REPORT_ERROR_NOK((FALSE == CanIf_Init_Flag), CANIF_SET_PDU_MODE_SID,CANIF_E_UNINIT)

    #if(CANIF_VARIANT_INFO == 1)
    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    CanIf_Num_Controllers = CANIF_NUM_CONTROLLERS;
    #endif
    ControllerState_Temp = CanIf_ControllerState;
    #else
    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    CanIf_Num_Controllers = CanIf_ConfigSetPtr->NumControllers;
    #endif
    ControllerState_Temp = CanIf_ConfigSetPtr->CtrlStatePtr;
    #endif

    Status = E_OK;

    /* If the Channel is invalid, report to DET and return E_NOT_OK */
    CANIF_DET_REPORT_ERROR_NOK((Controller >= CanIf_Num_Controllers),
                                                CANIF_SET_PDU_MODE_SID, CANIF_E_PARAM_CONTROLLER)


    /* Set the Channel mode in a global variable
     * Get the base address from the controller state structure*/

    /*Enter critical section*/
    SchM_Enter_CanIf_ControllerState();

#if(CANIF_VARIANT_INFO == 1)
    ControllerState_Temp = CanIf_ControllerState + Controller;
#else
    ControllerState_Temp = (CanIf_ConfigSetPtr->CtrlStatePtr) + Controller;
#endif

    /* Check the requested channel mode */
    switch(PduModeRequest)
    {

        case CANIF_SET_ONLINE     :
            ControllerState_Temp->ChannelMode  = CANIF_GET_ONLINE;
            break;
      /* FC_VariationPoint_START */
        #if(CANIF_LITE_CONFIGURATION == STD_OFF)
      /* FC_VariationPoint_END */
            /* Check current channel mode and set receive path to offline */
        case CANIF_SET_RX_OFFLINE :

            /* if receive path of the corresponding channel is disabled */
            switch(ControllerState_Temp->ChannelMode)
            {
                case CANIF_GET_RX_ONLINE:
                    /* FC_VariationPoint_START */
                #if (CANIF_USER_TP_TX_OFFLINE_MODE != STD_OFF)
                case CANIF_GET_TX_TP_ONLINE:
                case CANIF_GET_TX_USER_TP_ONLINE:
                #endif
                    /* FC_VariationPoint_END */
                ControllerState_Temp->ChannelMode = CANIF_GET_OFFLINE;
                break;

                case CANIF_GET_ONLINE:
                ControllerState_Temp->ChannelMode = CANIF_GET_TX_ONLINE;
                break;

                case CANIF_GET_OFFLINE :
                case CANIF_GET_TX_ONLINE:
                break;

                case CANIF_GET_OFFLINE_ACTIVE:
                {
                    /*No change, since RX was already disabled*/
                }
                break;

                case CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE:
                {
                    /*With this, RX will be disabled but TX is still simulated*/
                    ControllerState_Temp->ChannelMode = CANIF_GET_OFFLINE_ACTIVE;
                }
                break;

                default:
                    /* Nothing to do in default case */
                break;
            }

            break;

        case CANIF_SET_TX_ONLINE  :

            /* Check the current Channel mode and set it accordingly */
            switch(ControllerState_Temp->ChannelMode)
            {
                case CANIF_GET_RX_ONLINE:
                   /* FC_VariationPoint_START */
                #if (CANIF_USER_TP_TX_OFFLINE_MODE != STD_OFF)
                case CANIF_GET_TX_TP_ONLINE:
                case CANIF_GET_TX_USER_TP_ONLINE:
                #endif
                    /* FC_VariationPoint_END */
                ControllerState_Temp->ChannelMode = CANIF_GET_ONLINE;
                break;

                case CANIF_GET_OFFLINE :
                ControllerState_Temp->ChannelMode = CANIF_GET_TX_ONLINE;
                break;

                case CANIF_GET_ONLINE:
                case CANIF_GET_TX_ONLINE:
                break;

                case CANIF_GET_OFFLINE_ACTIVE:
                {
                    /*Only TX is enabled here, since RX was already disabled*/
                    ControllerState_Temp->ChannelMode = CANIF_GET_TX_ONLINE;
                }
                break;

                case CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE:
                {
                    /*With this, both TX and RX are enabled.*/
                    ControllerState_Temp->ChannelMode = CANIF_GET_ONLINE;
                }
                break;

                default:
                    /* Nothing to do in default case */
                break;
            }

            break;
         /* FC_VariationPoint_START */
        /* End of #if(CANIF_LITE_CONFIGURATION == STD_OFF) */
        #endif
         /* FC_VariationPoint_END */
        case CANIF_SET_OFFLINE    :
            ControllerState_Temp->ChannelMode  = CANIF_GET_OFFLINE;

 /* FC_DeviationPoint_START */
            #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
     /* FC_DeviationPoint_END */

        /* FC_CODE_START */
 //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
  /*  FC_CODE_END */
            CanIf_ClearTxChannelBuffer(Controller);
            #endif

            break;
          /* FC_VariationPoint_START */
        #if(CANIF_LITE_CONFIGURATION == STD_OFF)
          /* FC_VariationPoint_END */
        case CANIF_SET_RX_ONLINE  :

            /* Check the current Channel mode and set it accordingly */
            switch(ControllerState_Temp->ChannelMode)
            {
                case CANIF_GET_TX_ONLINE:
                case CANIF_GET_ONLINE:
                ControllerState_Temp->ChannelMode  = CANIF_GET_ONLINE;
                break;

                case CANIF_GET_OFFLINE :
                ControllerState_Temp->ChannelMode = CANIF_GET_RX_ONLINE;
                break;

                case CANIF_GET_RX_ONLINE:
                /* FC_VariationPoint_START */
                #if (CANIF_USER_TP_TX_OFFLINE_MODE != STD_OFF)
                case CANIF_GET_TX_TP_ONLINE:
                case CANIF_GET_TX_USER_TP_ONLINE:
                #endif
                /* FC_VariationPoint_END */
                break;

                case CANIF_GET_OFFLINE_ACTIVE:
                {
                    /*Only RX is enabled here, since TX is still Simulated */
                    ControllerState_Temp->ChannelMode = CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE;
                }
                break;

                case CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE:
                {
                    /*No change, since RX is already enabled.*/

                }
                break;

                default:
                    /* Nothing to do in default case */
                break;
            }

            break;

        case CANIF_SET_TX_OFFLINE :

            /* Check the current Channel mode and set it accordingly */
            switch(ControllerState_Temp->ChannelMode)
            {
                case CANIF_GET_TX_ONLINE:
                    /* Disable the channel  */
                ControllerState_Temp->ChannelMode  = CANIF_GET_OFFLINE;
                break;

                case CANIF_GET_ONLINE:
                    /* FC_VariationPoint_START */
                #if (CANIF_USER_TP_TX_OFFLINE_MODE != STD_OFF)
                case CANIF_GET_TX_TP_ONLINE:
                case CANIF_GET_TX_USER_TP_ONLINE:
                #endif
                    /* FC_VariationPoint_END */
                    /* Enable the reception and disable the transmit path of channel */
                ControllerState_Temp->ChannelMode = CANIF_GET_RX_ONLINE;
                break;

                case CANIF_GET_OFFLINE_ACTIVE:
                {
                    ControllerState_Temp->ChannelMode = CANIF_GET_OFFLINE;
                }
                break;

                case CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE:
                {
                    ControllerState_Temp->ChannelMode = CANIF_GET_RX_ONLINE;
                }
                break;

                case CANIF_GET_OFFLINE :
                case CANIF_GET_RX_ONLINE:

                default:
                    /* Nothing to do in default case */
                break;
            }
            /* updated as per requirement [SWS_CANIF_00878]  */
            #if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
            if(ControllerState_Temp->BlPnCntr == TRUE)
            {
                ControllerState_Temp->BlPnTxFilter = TRUE;
            }
            #endif
            break;
            /* FC_VariationPoint_START */
        #if (CANIF_USER_TP_TX_OFFLINE_MODE != STD_OFF)
        case CANIF_SET_TX_TP_ONLINE :

            /* Check the current Channel mode and set it accordingly */
            switch(ControllerState_Temp->ChannelMode)
            {
                case CANIF_GET_TX_ONLINE:
                case CANIF_GET_ONLINE:
                case CANIF_GET_OFFLINE :
                case CANIF_GET_RX_ONLINE:
                case CANIF_GET_TX_USER_TP_ONLINE:
                case CANIF_GET_OFFLINE_ACTIVE:
                case CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE:
                ControllerState_Temp->ChannelMode = CANIF_GET_TX_TP_ONLINE;
                break;

                default:
                    /* Nothing to do in default case */
                break;
            }

            break;

        case CANIF_SET_TX_USER_TP_ONLINE :

            /* Check the current Channel mode and set it accordingly */
            switch(ControllerState_Temp->ChannelMode)
            {
                case CANIF_GET_TX_ONLINE:
                case CANIF_GET_ONLINE:
                case CANIF_GET_OFFLINE :
                case CANIF_GET_RX_ONLINE:
                case CANIF_GET_TX_TP_ONLINE:
                case CANIF_GET_OFFLINE_ACTIVE:
                case CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE:
                ControllerState_Temp->ChannelMode = CANIF_GET_TX_USER_TP_ONLINE;
                break;

                default:
                    /* Nothing to do in default case */
                break;
            }

            break;
        /* End of #if(CANIF_USER_TP_TX_OFFLINE_MODE != STD_OFF) */
        #endif
            /* FC_VariationPoint_END */

        case CANIF_SET_TX_OFFLINE_ACTIVE  :
        {
            /* Check the current Channel mode and set it accordingly */
            switch(ControllerState_Temp->ChannelMode)
            {
                case CANIF_GET_OFFLINE:
                {
                    ControllerState_Temp->ChannelMode = CANIF_GET_OFFLINE_ACTIVE;
                }
                break;

                case CANIF_GET_OFFLINE_ACTIVE:
                {
                    /*No change in Pdu mode*/
                }
                break;

                case CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE:
                {
                    /*No change in Pdu mode*/
                }
                break;

                case CANIF_GET_ONLINE:
                {
                    ControllerState_Temp->ChannelMode = CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE;
                }
                break;

                case CANIF_GET_RX_ONLINE:
                {
                    ControllerState_Temp->ChannelMode = CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE;
                }
                break;

                case CANIF_GET_TX_ONLINE:
                {
                    ControllerState_Temp->ChannelMode = CANIF_GET_OFFLINE_ACTIVE;
                }
                break;

                default:
                    /* Nothing to do in default case */
                break;

            }

        }
        break;

            /* FC_VariationPoint_START */
        /* End of #if(CANIF_LITE_CONFIGURATION == STD_OFF) */
        #endif
            /* FC_VariationPoint_END */
        default :
            Status = E_NOT_OK;
            break;
    }

    /*Exit critical section*/
    SchM_Exit_CanIf_ControllerState();

    return (Status);
} /* End of CanIf_SetChannelMode() */

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


