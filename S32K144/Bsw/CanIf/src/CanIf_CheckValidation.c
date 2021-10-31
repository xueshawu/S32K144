

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
/**********************************************************************************************************************/
/* Function name    : CanIf_CheckValidation                                                                           */
/* Syntax           : FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckValidation(
                                                                VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource)   */
/* Description      : Service is performed to validate a previous wakeup event. This service is called by the EcuM.   */
/* Parameter        : WakeupSource                                                                                    */
/* Return value     : E_OK / E_NOT_OK                                                                                 */
/**********************************************************************************************************************/

#if (CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_CheckValidation: Function contains very simple "else if" statements and "switch-cases". HIS metric compliance would decrease readability and maintainability. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckValidation (VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource)
{
    /* Pointer to Controller State configuration */
    P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) ControllerState_ps;

    /* Return value */
    VAR(Std_ReturnType, AUTOMATIC) RetValOfFuncs_ui;

    /* Loop variable to check the LUT*/
    VAR(uint8_least, AUTOMATIC) LoopVar_ui;

    /* Flag to know whether a wakeup device was found*/
    VAR(boolean, AUTOMATIC) WkpDeviceFound;

    VAR (uint8, AUTOMATIC) CanIf_Num_Controllers;

    /*To store the controller state (Device mode)*/
    VAR (CanIf_ControllerModeType, AUTOMATIC) DeviceMode_Temp;

    /*To store the controller state (Device mode)*/
    VAR (uint8, AUTOMATIC) NewMsgStatus_Temp;

    P2CONST(CanIf_WakeupLUT_Type,AUTOMATIC,AUTOMATIC) WkpLUTPtr_Temp;
    P2CONST(CanIf_CallbackFuncType, AUTOMATIC, AUTOMATIC) CallBackPtr_Temp;
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) NewRxMsgPtr_Temp;
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) WkpEventPtr_Temp;

    /* Initialize the return value */
    RetValOfFuncs_ui = E_NOT_OK;

    /*Initialise the flag*/
    WkpDeviceFound = FALSE;

    /* If CAN Interface is uninitialized, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR_NOK((FALSE == CanIf_Init_Flag), CANIF_CHECKVALIDATION_SID, CANIF_E_UNINIT)

    #if(CANIF_VARIANT_INFO == 1)
    CanIf_Num_Controllers = CANIF_NUM_CONTROLLERS;
    WkpLUTPtr_Temp = CanIf_Wakeup_LUT;
    ControllerState_ps = CanIf_ControllerState;
    NewRxMsgPtr_Temp = CanIf_NewMsg_Rx;
    WkpEventPtr_Temp = CanIf_WakeUp_Event;
    CallBackPtr_Temp = &CanIf_Callback;
    #else
    CanIf_Num_Controllers = CanIf_ConfigSetPtr->NumControllers;
    WkpLUTPtr_Temp = CanIf_ConfigSetPtr->WakeupLutPtr;
    ControllerState_ps = CanIf_ConfigSetPtr->CtrlStatePtr;
    NewRxMsgPtr_Temp = CanIf_ConfigSetPtr->NewRxMsgPtr;
    WkpEventPtr_Temp = CanIf_ConfigSetPtr->WkpEventPtr;
    CallBackPtr_Temp = CanIf_ConfigSetPtr->CallbackPtr;
    #endif


    /*Loop through the Wakeup LUT to know the device*/
    /*Currently CANIF_NUM_CTRL_WAKEUP_DEVICES is hardcoded to 0. Re-analyse the code section when Ctrl wakeup is to be supported.*/
    for(LoopVar_ui = 0; LoopVar_ui < CanIf_Num_Controllers; LoopVar_ui++)
    {
        /*If the WakeupSource is a valid one...*/
        if((WkpLUTPtr_Temp +LoopVar_ui)->WakeupSourceId == WakeupSource)
        {

            /*LoopVar_ui will contain the location of the entry in the table*/

            /*Update the Flag*/
            WkpDeviceFound = TRUE;

            /*Stop searching the LUT*/
            break;
        }
    }


    /*Report DET if no wakeup devices were found*/
    CANIF_DET_REPORT_ERROR_NOK((WkpDeviceFound == FALSE), CANIF_CHECKWAKEUP_SID, CANIF_E_PARAM_WAKEUPSOURCE)



    /*Enter critical section*/
    SchM_Enter_CanIf_ControllerState();

    /*Make a local copy of (ControllerState_ps +LoopVar_ui)->DeviceMode*/
    DeviceMode_Temp = (ControllerState_ps +LoopVar_ui)->DeviceMode;

    /*Leave critical section*/
    SchM_Exit_CanIf_ControllerState();



    /*Enter critical section*/
    SchM_Enter_CanIf_NewMsgRxWkpEvtNoNest();

    /*Make a local copy of *(NewRxMsgPtr_Temp + LoopVar_ui)*/
    NewMsgStatus_Temp = *(NewRxMsgPtr_Temp + LoopVar_ui);

    /*Leave critical section*/
    SchM_Exit_CanIf_NewMsgRxWkpEvtNoNest();


    /* Wakeup validation is supported only in CANIF_CS_STARTED Mode and a wakeup was detected*/
    if(((DeviceMode_Temp) == CANIF_CS_STARTED) && (WkpDeviceFound != FALSE))
    {
        /* Whether a new L-PDU was successful received */
        if(NewMsgStatus_Temp == CANIF_SET)
        {

            /*Enter critical section*/
            SchM_Enter_CanIf_NewMsgRxWkpEvtNoNest();

            /* Reset the wakeup event */
            *(WkpEventPtr_Temp + LoopVar_ui) = CANIF_RESET;

            /* Reset the new message received flag */
            *(NewRxMsgPtr_Temp + LoopVar_ui) = CANIF_RESET;

            /*Leave critical section*/
            SchM_Exit_CanIf_NewMsgRxWkpEvtNoNest();


            /* Indicate application about Wakeup condition */
            if(NULL_PTR != CallBackPtr_Temp->User_ValidateWakeupEvent)
            {
                CallBackPtr_Temp->User_ValidateWakeupEvent(WakeupSource);
            }

            /* Return E_OK */
            RetValOfFuncs_ui = E_OK;
        }
        else
        {
            /* New message is not received */
            if(NULL_PTR != CallBackPtr_Temp->User_ValidateWakeupEvent)
            {
                CallBackPtr_Temp->User_ValidateWakeupEvent((EcuM_WakeupSourceType)CANIF_WAKEUP_SOURCE_CLEAR);
            }

            /* Return E_NOT_OK */
            RetValOfFuncs_ui = E_NOT_OK;

        }

    }
    else
    {
        /* Wakeup validation is not supported in modes other than CANIF_CS_STARTED */
    }


    return (RetValOfFuncs_ui);
}/* End of CanIf_CheckValidation() */

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif


