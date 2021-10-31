

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "CanIf_Priv.h"

/*Can.h included for Can_SetControllerMode()*/
#include "Can.h"

/*
 ***************************************************************************************************
 * used functions
 ***************************************************************************************************
 */

/*********************************************************************************************************************/
/* Function name : CanIf_SetControllerMode                                                                           */
/* Syntax        : FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode(
                                                                              VAR (uint8,AUTOMATIC)Controller,
                                                                              VAR(CanIf_ControllerModeType,AUTOMATIC) ControllerMode                                                                            )                                        */
/* Description   : This service calls the corresponding CAN driver service for changing of the CAN controller mode.  */
/* Parameter     : Controller, ControllerMode                                                                        */
/* Return value  : E_OK / E_NOT_OK                                                                                   */
/*********************************************************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC PATH,v(G),RETURN VIOLATION IN CanIf_SetControllerMode: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode(
                                                            VAR (uint8,AUTOMATIC) Controller,
                                                            VAR(CanIf_ControllerModeType,AUTOMATIC) ControllerMode
                                                        )
{
    /* Pointer to Controller State configuration */
    P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) ControllerState_Temp;

    /* Transition mode of the can driver */
    VAR(Can_StateTransitionType,AUTOMATIC) Mode;
    /* FC_VariationPoint_START */
    #if(CANIF_LITE_CONFIGURATION == STD_OFF)
    /* FC_VariationPoint_END */
    VAR(Can_StateTransitionType,AUTOMATIC) Int_Mode;
    /* FC_VariationPoint_START */
    #endif
    /* FC_VariationPoint_END */
    /* Return value of a Can_SetControllerMode() of CAN driver*/
    VAR(Can_ReturnType,AUTOMATIC) CanStatus;

    /* Return value indicating the status of operation */
    VAR(Std_ReturnType, AUTOMATIC ) Status;

    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    VAR (uint8, AUTOMATIC) CanIf_Num_Controllers;
    #endif

    /*To store the controller state (Device mode)*/
    VAR (CanIf_ControllerModeType, AUTOMATIC) DeviceMode_Temp;

    #if (CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
    P2VAR(uint8,AUTOMATIC, AUTOMATIC) NewRxMsgPtr_Temp;
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) WkpEventPtr_Temp;
    #endif

    #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
    P2VAR(CanIf_NotifStatusType,AUTOMATIC,AUTOMATIC) TxConfPtr_Temp;
    #endif

    /* If CAN Interface is uninitialized, report to DET and return E_NOT_OK */
    CANIF_DET_REPORT_ERROR_NOK((FALSE == CanIf_Init_Flag), CANIF_SET_CONTROLLER_SID,CANIF_E_UNINIT)

    #if(CANIF_VARIANT_INFO == 1)
    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    CanIf_Num_Controllers = CANIF_NUM_CONTROLLERS;
    #endif
    /* ControllerState_Temp = CanIf_ControllerState; */
    ControllerState_Temp = CanIf_ControllerState + Controller;

    #if (CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
    NewRxMsgPtr_Temp = CanIf_NewMsg_Rx;
    WkpEventPtr_Temp = CanIf_WakeUp_Event;
    #endif

    #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
    TxConfPtr_Temp = CanIf_TxConf_State;
    #endif

    #else
    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    CanIf_Num_Controllers = CanIf_ConfigSetPtr->NumControllers;
    #endif
   /* ControllerState_Temp = CanIf_ConfigSetPtr->CtrlStatePtr; */
     ControllerState_Temp = (CanIf_ConfigSetPtr->CtrlStatePtr) + Controller;

    #if (CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
    NewRxMsgPtr_Temp = CanIf_ConfigSetPtr->NewRxMsgPtr;
    WkpEventPtr_Temp = CanIf_ConfigSetPtr->WkpEventPtr;
    #endif

    #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
    TxConfPtr_Temp = CanIf_ConfigSetPtr->TxConfStatusPtr;
    #endif
    #endif

    /* Initialization */
    Status = E_OK;
    Mode = CAN_T_SLEEP;

    /* If Controller is invalid, report to DET and return E_NOT_OK */
    CANIF_DET_REPORT_ERROR_NOK((Controller >= CanIf_Num_Controllers), CANIF_SET_CONTROLLER_SID,CANIF_E_PARAM_CONTROLLERID)

    /* Set the transition mode for the Can Driver */
    if(CANIF_CS_STARTED == ControllerMode)
    {
        Mode = CAN_T_START;
    }
    else if(CANIF_CS_STOPPED == ControllerMode)
    {
        Mode = CAN_T_STOP;
    }
    else if(CANIF_CS_SLEEP == ControllerMode)
    {
        Mode = CAN_T_SLEEP;

        /*Reset the wakeup / validation status of the controller */
        #if (CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)

        /*Enter critical section*/
        SchM_Enter_CanIf_NewMsgRxWkpEvtNoNest();

        *(NewRxMsgPtr_Temp + Controller) = CANIF_RESET;
        *(WkpEventPtr_Temp + Controller) = CANIF_RESET;

        /*Leave critical section*/
        SchM_Exit_CanIf_NewMsgRxWkpEvtNoNest();
        #endif
        /*as per requirement [SWS_CANIF_00749] PnTxFilter shall be enabled */
        #if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
        if(ControllerState_Temp->BlPnCntr == TRUE)
        {
            ControllerState_Temp->BlPnTxFilter = TRUE;
        }
        #endif
    }
    else
    {
        /* Executed when ControllerMode is different */
        Status = E_NOT_OK;
    }
    if(Status == E_OK)
    {
        /* FC_VariationPoint_START */
        #if(CANIF_LITE_CONFIGURATION == STD_OFF)
        /* FC_VariationPoint_END */
        /* Initialize the pointer to ControllerState
         * Get the ppinter from base address*/

        /*Enter critical section*/
        SchM_Enter_CanIf_ControllerState();

        /* #if(CANIF_VARIANT_INFO ==1)
        ControllerState_Temp = CanIf_ControllerState + Controller;
        #else
        ControllerState_Temp = (CanIf_ConfigSetPtr->CtrlStatePtr)  + Controller;
        #endif */

        /*Make a local copy of ControllerState_Temp->DeviceMode*/
        DeviceMode_Temp = ControllerState_Temp->DeviceMode;

        /*Exit critical section*/
        SchM_Exit_CanIf_ControllerState();

        /* If Controller is not initialised, report to Det, return E_NOT_OK and exit the function*/
        CANIF_DET_REPORT_ERROR_NOK((CANIF_CS_UNINIT == DeviceMode_Temp),
                                    CANIF_SET_CONTROLLER_SID, CANIF_E_PARAM_CONTROLLERMODE)

        /* Started --> Sleep */
        if((CANIF_CS_STARTED == DeviceMode_Temp) && (CANIF_CS_SLEEP == ControllerMode))
        {
            Int_Mode = CAN_T_STOP;

            /* Stop the can controller */
            CanStatus = Can_SetControllerMode(Controller, Int_Mode);

            if(CanStatus == CAN_NOT_OK)
            {
                Status = E_NOT_OK;
            }
        }

        /* Sleep --> Started */
        if ((CANIF_CS_SLEEP == DeviceMode_Temp) && (CANIF_CS_STARTED == ControllerMode))
        {
            Int_Mode = CAN_T_WAKEUP;

            CanStatus = Can_SetControllerMode(Controller, Int_Mode);

            if(CanStatus == CAN_NOT_OK)
            {
                Status = E_NOT_OK;
            }
        }
		else if ((CANIF_CS_SLEEP == DeviceMode_Temp) && (CANIF_CS_STOPPED == ControllerMode)) 
		{
			Mode = CAN_T_WAKEUP;
		}
        else
        {
        }

        /* FC_VariationPoint_START */
        /* End of #if(CANIF_LITE_CONFIGURATION == STD_OFF) */
        #endif
        /* FC_VariationPoint_END */
        if(Status == E_OK)
        {
       /* FC_DeviationPoint_START */
            #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
     /* FC_DeviationPoint_END */

        /* FC_CODE_START */
  //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
  /*  FC_CODE_END */

            /*  check whether can driver is started */
            if(Mode == CAN_T_START)
            {
                /* Clear the Tx buffer */
                CanIf_ClearBuffer(Controller, CANIF_TRANSMIT);
            }
            #endif
            /* Set the CAN controller mode */
            CanStatus = Can_SetControllerMode(Controller, Mode);

            if(CanStatus == CAN_NOT_OK)
            {
                Status = E_NOT_OK;
            }
            else
            {

                /*Enter critical section*/
                SchM_Enter_CanIf_ControllerState();

                /* Update the current controller mode in CanIf_ControllerStateType structure*/
                ControllerState_Temp->DeviceMode = ControllerMode;

                /*Update the local copy of Device mode before using it*/
                DeviceMode_Temp = ControllerState_Temp->DeviceMode;

                /*Exit critical section*/
                SchM_Exit_CanIf_ControllerState();

                #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
                if (CANIF_CS_STARTED == DeviceMode_Temp)
                {
                    /* Enter Critical Section */
                    SchM_Enter_CanIf_TxRxNotifNoNest();

                    /* Reset Tx Confirmation state for each controller*/
                    *(TxConfPtr_Temp + Controller) = CANIF_NO_NOTIFICATION;

                    /* Leave Critical Section */
                    SchM_Exit_CanIf_TxRxNotifNoNest();

                }
                #endif


            }
        }
    } /* End of if(Status == E_OK) condition */
    return(Status);
} /* End of CanIf_SetControllerMode() */

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


