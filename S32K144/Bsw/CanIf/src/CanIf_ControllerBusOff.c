

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
/* Function name    : CanIf_ControllerBusOff                                                            */
/* Syntax           : FUNC(void, CANIF_CODE) CanIf_ControllerBusOff(
                                                                    VAR(uint8,AUTOMATIC) Controller
                                                                    )                                   */
/* Description      : Service indicates a CAN controller BusOff event referring to the corresponding
                      CAN controller. This service is called by the CAN driver.                         */
/* Parameter        : Controller                                                                        */
/* Return value     : None                                                                              */
/********************************************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_ControllerBusOff: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(void, CANIF_CODE) CanIf_ControllerBusOff(
                                                VAR(uint8,AUTOMATIC) Controller
                                             )

{
    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    VAR (uint8, AUTOMATIC) CanIf_Num_Controllers;
    #endif

    #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
    P2VAR(CanIf_NotifStatusType, AUTOMATIC, AUTOMATIC) TxConfStatus_Temp;
    #endif
    P2CONST(CanIf_CallbackFuncType, AUTOMATIC, AUTOMATIC) CallBackPtr_Temp;
    /* If CAN Interface is uninitialised, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR((FALSE == CanIf_Init_Flag), CANIF_CONTROLLER_BUSOFF_SID, CANIF_E_UNINIT)

    #if(CANIF_VARIANT_INFO == 1)
    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    CanIf_Num_Controllers = CANIF_NUM_CONTROLLERS;
    #endif
    #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
    TxConfStatus_Temp = CanIf_TxConf_State;
    #endif
    CallBackPtr_Temp = &CanIf_Callback;

    #else
    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    CanIf_Num_Controllers = CanIf_ConfigSetPtr->NumControllers;
    #endif
    #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
    TxConfStatus_Temp = CanIf_ConfigSetPtr->TxConfStatusPtr;
    #endif
    CallBackPtr_Temp = CanIf_ConfigSetPtr->CallbackPtr;

    #endif

    /* If Controller is invalid, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR((Controller >= CanIf_Num_Controllers), CANIF_CONTROLLER_BUSOFF_SID,CANIF_E_PARAM_CONTROLLER)


 /* FC_DeviationPoint_START */
    #if (CANIF_TRANSMIT_BUFFER != STD_OFF)
     /* FC_DeviationPoint_END */

    /* FC_CODE_START */
 //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
  /*  FC_CODE_END */

    CanIf_ClearBuffer(Controller, CANIF_TRANSMIT);

    #endif


    #if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)

    /* Enter Critical Section */
    SchM_Enter_CanIf_TxRxNotifNoNest();

    /* Reset Tx Confirmation state for each controller*/
    *(TxConfStatus_Temp + Controller) = CANIF_NO_NOTIFICATION;

    /* Leave Critical Section */
    SchM_Exit_CanIf_TxRxNotifNoNest();

    #endif

    /* Indicate application about bus off condition */
    if(NULL_PTR != CallBackPtr_Temp->User_ControllerBusOff)
    {
        CallBackPtr_Temp->User_ControllerBusOff(Controller);
    }

    Diag_BusOff_Notification(Controller);
} /* End of CanIf_ControllerBusOff() */
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
 /* FC_VariationPoint_START */

 /* FC_VariationPoint_END */
