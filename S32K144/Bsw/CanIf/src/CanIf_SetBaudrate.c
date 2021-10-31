

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "CanIf_Priv.h"

/* FC_FileVariationPoint_START */
#if (CANIF_PUBLIC_SET_BAUDRATE_SUPPORT == STD_ON)
/*Version check done in CanIf_SetController.c*/
#include "Can.h"
#endif
/*
 ***************************************************************************************************
 * used functions
 ***************************************************************************************************
 */
/**************************************************************************************************/
/* Function name    : CanIf_SetBaudrate                                                     */
/* Syntax           : FUNC(void, CANIF_CODE) CanIf_SetBaudrate(
                                                       VAR (uint8,AUTOMATIC) Controller,
                                                       CONST(uint16,AUTOMATIC) BaudRateConfigID
                                                    )                                        */
/* Description      : This service returns E_OK if the baudrate is changed successfully for
                      all Can controllers else returns E_NOT_OK                                */
/* Parameter        : Controller ,  BaudRateConfigID                                           */
/* Return value     : Std_ReturnType                                                           */
/**************************************************************************************************/
#if (CANIF_PUBLIC_SET_BAUDRATE_SUPPORT == STD_ON)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC COMF VIOLATION IN CanIf_SetBaudrate: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetBaudrate(
                                         VAR(uint8,AUTOMATIC) Controller,
                                         CONST(uint16,AUTOMATIC) BaudRateConfigID
                                         )
{

    /* Variable to store the CanStatus returned by Can_SetBaudrate() */
    VAR(Std_ReturnType,AUTOMATIC) CanStatus;
    #if (CANIF_DEV_ERROR_DETECT != STD_OFF)
    VAR (uint8, AUTOMATIC) CanIf_Num_Controllers;
    #endif

#if(CANIF_VARIANT_INFO == 1)
    #if (CANIF_DEV_ERROR_DETECT != STD_OFF)
    CanIf_Num_Controllers = CANIF_NUM_CONTROLLERS;
    #endif
#else
    #if (CANIF_DEV_ERROR_DETECT != STD_OFF)
    CanIf_Num_Controllers = CanIf_ConfigSetPtr->NumControllers;
    #endif
#endif

    /* If Controller is invalid, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR_NOK((Controller >= CanIf_Num_Controllers),
                                (CANIF_SETBAUDRATE_SID),
                                (CANIF_E_PARAM_CONTROLLERID)
                               )


    CanStatus = Can_SetBaudrate(Controller,BaudRateConfigID);

    return(CanStatus);


}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif
/* FC_FileVariationPoint_END */

 /* FC_VariationPoint_START */

/* FC_VariationPoint_END */
