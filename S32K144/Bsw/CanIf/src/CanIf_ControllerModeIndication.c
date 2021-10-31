

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
/********************************************************************************************************/
/* Function name    : CanIf_ControllerModeIndication                                                            */
/* Syntax           : FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication(
                                                                    VAR(uint8,AUTOMATIC) Controller,
                                                                    CanIf_ControllerModeType ControllerMode
                                                                    )                                   */
/* Description      : Service indicates a mode change is successful for the particular
                      CAN controller. This service is called by the CAN driver.                         */
/* Parameter        : Controller                                                                        */
/* Return value     : None                                                                              */
/********************************************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_ControllerModeIndication: Function contains very simple "else if" statements and "switch-cases". HIS metric compliance would decrease readability and maintainability. */
FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication(     VAR(uint8,AUTOMATIC) Controller,
                                                        VAR(CanIf_ControllerModeType,AUTOMATIC) ControllerMode
                                                    )
{

    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    VAR (uint8, AUTOMATIC) CanIf_Num_Controllers;
    #endif

    /* Pointer to Controller State configuration */
    P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) ControllerState_Temp;
    P2CONST(CanIf_CallbackFuncType, AUTOMATIC, AUTOMATIC) CallBackPtr_Temp;

    /* If CAN Interface is uninitialized, report to DET and return E_NOT_OK */
    CANIF_DET_REPORT_ERROR((FALSE == CanIf_Init_Flag), CANIF_CONTROLLER_MODE_IND_SID,CANIF_E_UNINIT)

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

    #if(CANIF_VARIANT_INFO == 1)
    CallBackPtr_Temp = &CanIf_Callback;
    #else
    CallBackPtr_Temp = CanIf_ConfigSetPtr->CallbackPtr;
    #endif

    /* If Controller is invalid, report to DET and return E_NOT_OK */
    CANIF_DET_REPORT_ERROR((Controller >= CanIf_Num_Controllers), CANIF_CONTROLLER_MODE_IND_SID,CANIF_E_PARAM_CONTROLLER)

    /*Enter critical section*/
    SchM_Enter_CanIf_ControllerState();

    (ControllerState_Temp +Controller)->DeviceMode = ControllerMode;

    /*Leave critical section*/
    SchM_Exit_CanIf_ControllerState();

    /* Inform CanSM */
    if(NULL_PTR != CallBackPtr_Temp->CanSM_ControllerModeIndication)
    {
        CallBackPtr_Temp->CanSM_ControllerModeIndication(Controller, ControllerMode);
    }
}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

