
/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "CanIf_Priv.h"

#if CANIF_TRCV_DRV_CFG!=STD_OFF
#include "CanTrcv.h"
#if (!defined(CANTRCV_AR_RELEASE_MAJOR_VERSION) || (CANTRCV_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION))
#error "AUTOSAR major version undefined or mismatched"
#endif
#if (!defined(CANTRCV_AR_RELEASE_MINOR_VERSION) || (CANTRCV_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION))
#error "AUTOSAR minor version undefined or mismatched"
#endif
#endif

#if (CANIF_CTRL_WAKEUP_SUPPORT!=STD_OFF)
/*Can.h included for Can_CheckWakeup()*/
/*Version check done in CanIf_SetController.c*/
#include "Can.h"
#endif

/*
 ***************************************************************************************************
 * used functions
 ***************************************************************************************************
 */
/**************************************************************************************************************/
/* Function name    : CanIf_CheckWakeup                                                                       */
/* Syntax           : FUNC(Std_ReturnType, CANIF_CODE)
                                        CanIf_CheckWakeup (VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource)*/
/* Description      : Service checks whether an underlying CAN driver/CAN Transceiver driver already signals
                      an wakeup event by the CAN network.                                                     */
/* Parameter        : WakeupSource                                                                            */
/* Return value     : E_OK / E_NOT_OK                                                                         */
/**************************************************************************************************************/

#if (CANIF_WAKEUP_SUPPORT != STD_OFF)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC COMF VIOLATION IN CanIf_CheckWakeup: Function contains very simple "else if" statements and "switch-cases". HIS metric compliance would decrease readability and maintainability. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup (VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource)
{

    /* Pointer to Controller State configuration */
    P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) ControllerState_ps;

    /* Return value */
    VAR(Std_ReturnType, AUTOMATIC) Ret_controller_ui;

    /* Return value of Can_CheckWakeup()*/
    VAR(Std_ReturnType, AUTOMATIC) Ret_transceiver_ui;

    /* Return value of CanTrcv_CheckWakeup()*/
    VAR(Std_ReturnType, AUTOMATIC) RetValOfFuncs_ui;

    /* Loop variable to check the LUT*/
    VAR(uint8_least, AUTOMATIC) LoopVar_ui;

    /* Flag to know whether a wakeup device was found*/
    VAR(boolean, AUTOMATIC) WkpDeviceFound;

    VAR (uint8, AUTOMATIC) CanIf_Num_Controllers;

    P2CONST(CanIf_WakeupLUT_Type,AUTOMATIC,AUTOMATIC) WkpLUTPtr_Temp;
    P2CONST(CanIf_CallbackFuncType, AUTOMATIC, AUTOMATIC) CallBackPtr_Temp;
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) WkpEventPtr_Temp;

    /*To store the controller state (Device mode)*/
    VAR (CanIf_ControllerModeType, AUTOMATIC) DeviceMode_Temp;

    /* If CAN Interface is uninitialized, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR_NOK((FALSE == CanIf_Init_Flag), CANIF_CHECKWAKEUP_SID, CANIF_E_UNINIT)

    #if(CANIF_VARIANT_INFO == 1)
    ControllerState_ps = CanIf_ControllerState;
    CanIf_Num_Controllers = CANIF_NUM_CONTROLLERS;
    WkpLUTPtr_Temp = CanIf_Wakeup_LUT;
    WkpEventPtr_Temp = CanIf_WakeUp_Event;
    CallBackPtr_Temp = &CanIf_Callback;
    #else
    ControllerState_ps = CanIf_ConfigSetPtr->CtrlStatePtr;
    CanIf_Num_Controllers = CanIf_ConfigSetPtr->NumControllers;
    WkpLUTPtr_Temp = CanIf_ConfigSetPtr->WakeupLutPtr;
    WkpEventPtr_Temp = CanIf_ConfigSetPtr->WkpEventPtr;
    CallBackPtr_Temp = CanIf_ConfigSetPtr->CallbackPtr;
    #endif

    /* Initialize the return value */
    Ret_controller_ui = E_NOT_OK;

    /* Initialize the return value */
    Ret_transceiver_ui = E_NOT_OK;

    /* Initialize the return value */
    RetValOfFuncs_ui = E_NOT_OK;

    /*Initialise the flag*/
    WkpDeviceFound = FALSE;

    /*Loop through the Wakeup LUT to know the wakeup device*/
    /*Currently CANIF_NUM_CTRL_WAKEUP_DEVICES is hardcoded to 0. Re-analyse the code section when Ctrl wakeup is to be supported.*/
    for(LoopVar_ui = 0; LoopVar_ui < (CanIf_Num_Controllers); LoopVar_ui++)
    {
        /*If the WakeupSource is one of the Transceivers...*/
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

    /*Check if the controller is in SLEEP*/
    /*Call the Ctrl or Trcv functions only if a wakeup device has been found*/
    if(((DeviceMode_Temp == CANIF_CS_SLEEP) && (WkpDeviceFound == TRUE)))
    {
        #if (CANIF_TRCV_WAKEUP_SUPPORT!=STD_OFF)
        /*Call the CanTrcv API if the wakeup device was a Trcv*/
        Ret_transceiver_ui = CanTrcv_CheckWakeup((WkpLUTPtr_Temp +LoopVar_ui)->TransceiverId);
        #endif

        /* Check whether wakeup has been detected on the controller */
        #if (CANIF_CTRL_WAKEUP_SUPPORT!=STD_OFF)
        /*Call the CanTrcv API if the wakeup device was a Ctrl*/
        Ret_controller_ui = Can_CheckWakeup(LoopVar_ui);
        #endif


        if((Ret_transceiver_ui == E_OK)||(Ret_controller_ui == E_OK))
        {
            RetValOfFuncs_ui = E_OK;
        }
        else
        {
            /*Do nothing*/
        }


        /* Wakeup is detected */
        if((RetValOfFuncs_ui != E_NOT_OK) && (WkpDeviceFound == TRUE))
        {
            /*Enter critical section*/
            SchM_Enter_CanIf_NewMsgRxWkpEvtNoNest();

            /* Store the wakeup event */
            *(WkpEventPtr_Temp + LoopVar_ui) = CANIF_SET;

            /*Leave critical section*/
            SchM_Exit_CanIf_NewMsgRxWkpEvtNoNest();


            /* Indicate EcuM about Wakeup event */
            if(NULL_PTR != CallBackPtr_Temp->User_SetWakeupEvent)
            {
                CallBackPtr_Temp->User_SetWakeupEvent(WakeupSource);
            }

            /* Return E_OK */
            RetValOfFuncs_ui = E_OK;
        }
        else
        {
            /*Return E_NOT_OK if wakeup was not detected*/
            RetValOfFuncs_ui = E_NOT_OK;
        }

    }
    else
    {
        /* Wakeup is not supported in modes other than CANIF_CS_SLEEP */
        /*If the device is not in SLEEP mode, then inform DET
         The condition for the DET macro is TRUE since, if the control reaches here,then it implies
         that the controller is not in SLEEP*/
        CANIF_DET_REPORT_ERROR_NOK(TRUE, CANIF_CHECKWAKEUP_SID, CANIF_E_CTRL_NOT_SLEEP);
    }


    return (RetValOfFuncs_ui);
}/* End of CanIf_CheckWakeup() */

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif


