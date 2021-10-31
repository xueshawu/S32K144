

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


/************************************************************************************************************/
/* Function name    : CanIf_ControllerErrorPassive                                                          */
/* Syntax           : FUNC(void, CANIF_CODE) CanIf_ControllerErrorPassive(VAR(uint8, AUTOMATIC) Controller) */
/* Description      : Service indicates a CAN controller Error Passive event referring to the
                      corresponding CAN controller. This service is called by the CAN driver.               */
/* Parameter        : Controller                                                                            */
/* Return value     : None                                                                                  */
/************************************************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE) CanIf_ControllerErrorPassive(VAR(uint8, AUTOMATIC) Controller)
{
#if (CANIF_ERROR_PASSIVE_SUPPORT != STD_OFF)
    #if (CANIF_DEV_ERROR_DETECT != STD_OFF)
    VAR (uint8, AUTOMATIC) CanIf_Num_Controllers;
    #endif
    P2CONST(CanIf_CallbackFuncType, AUTOMATIC, AUTOMATIC) CallBackPtr_Temp;

    /* If CAN Interface is uninitialized, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR((FALSE == CanIf_Init_Flag), CANIF_CONTROLLER_ERRORPASSIVE_SID, CANIF_E_UNINIT)

    #if (CANIF_DEV_ERROR_DETECT != STD_OFF)
    #if(CANIF_VARIANT_INFO == 1)
    CanIf_Num_Controllers = CANIF_NUM_CONTROLLERS;
    #else
    CanIf_Num_Controllers = CanIf_ConfigSetPtr->NumControllers;
    #endif
    #endif

    #if(CANIF_VARIANT_INFO == 1)
    CallBackPtr_Temp = &CanIf_Callback;
    #else
    CallBackPtr_Temp = CanIf_ConfigSetPtr->CallbackPtr;
    #endif

    /* If Controller is invalid, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR((Controller >= CanIf_Num_Controllers), CANIF_CONTROLLER_ERRORPASSIVE_SID,
                                                                                    CANIF_E_PARAM_CONTROLLER)

    #if (CANIF_TRANSMIT_BUFFER != STD_OFF)

    CanIf_ClearBuffer(Controller, CANIF_TRANSMIT);

    #endif

    /* Indicate application about error passive condition */
    if(NULL_PTR != CallBackPtr_Temp->CanSM_ControllerErrorPassive)
    {
        CallBackPtr_Temp->CanSM_ControllerErrorPassive(Controller);
    }
#else
    /*To avoid compiler warnings*/
    (void)Controller;
#endif
}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

/* FC_FileVariationPoint_END */


