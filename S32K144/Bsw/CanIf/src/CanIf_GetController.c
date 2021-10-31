

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
/**************************************************************************************************************/
/* Function name    : CanIf_GetControllerMode                                                                 */
/* Syntax           : FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode(
                                                                                VAR(uint8,AUTOMATIC) Controller,
                                                                                P2VAR(CanIf_ControllerModeType, AUTOMATIC, CANIF_APPL_DATA) ControllerModePtr
                                                                              )
*/
/* Description      : Service reports about the current status of the requested CAN Controller.               */
/* Parameter        : Controller, ControllerModePtr                                                           */
/* Return value     : E_OK / E_NOT_OK                                                                         */
/**************************************************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_GetControllerMode: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode(
                                                            VAR(uint8,AUTOMATIC) Controller,
                                                            P2VAR(CanIf_ControllerModeType, AUTOMATIC, CANIF_APPL_DATA) ControllerModePtr
                                                        )
{
    /* Pointer to Controller State configuration */
    P2VAR(CanIf_ControllerStateType, AUTOMATIC, AUTOMATIC) ControllerState_Temp;

    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    VAR (uint8, AUTOMATIC) CanIf_Num_Controllers;
    #endif

    /* If CAN Interface is uninitialized, report to DET and return E_NOT_OK */
    CANIF_DET_REPORT_ERROR_NOK((FALSE == CanIf_Init_Flag), CANIF_GET_CONTROLLER_SID,CANIF_E_UNINIT)

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

    /* If Controller is invalid, report to DET and return E_NOT_OK */
    CANIF_DET_REPORT_ERROR_NOK((Controller >= CanIf_Num_Controllers), CANIF_GET_CONTROLLER_SID,CANIF_E_PARAM_CONTROLLERID)

    /* If ControllerModePtr is null, report to DET and return E_NOT_OK*/
    CANIF_DET_REPORT_ERROR_NOK((NULL_PTR == ControllerModePtr), CANIF_GET_CONTROLLER_SID,CANIF_E_PARAM_POINTER)


    /*Enter critical section*/
    SchM_Enter_CanIf_ControllerState();

    /* Copy the status of the controller */
    *ControllerModePtr = (ControllerState_Temp + Controller)->DeviceMode;

    /*Leave critical section*/
    SchM_Exit_CanIf_ControllerState();


    return E_OK;
}/* End of CanIf_GetControllerMode() */

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

