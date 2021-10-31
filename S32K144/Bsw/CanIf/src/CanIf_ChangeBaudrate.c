

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "CanIf_Priv.h"


#if (CANIF_PUBLIC_CHANGE_BAUDRATE_SUPPORT == STD_ON)
/*Can.h included for Can_ChangeBaudrate()*/
/*Version check done in CanIf_SetController.c*/
#include "Can.h"
#endif
/*
 ***************************************************************************************************
 * used functions
 ***************************************************************************************************
 */
/**************************************************************************************************/
/* Function name    : CanIf_CheckBaudrate                                                   */
/* Syntax           : FUNC(void, CANIF_CODE) CanIf_ChangeBaudrate(
                                                                        VAR (uint8,AUTOMATIC) Controller,
                                VAR(uint32,AUTOMATIC) dBaudRate_u32 VAR(uint32,AUTOMATIC) dBaudRate_u32
                                                                       )                          */
/* Description      : This service returns E_OK if the baud rate(dBaudRate_u32) is configured for the
                      particular Controller, else returns E_NOT_OK.                               */
/* Parameter        : Controller ,  dBaudRate_u32                                                 */
/* Return value     : Std_ReturnType                                                              */
/**************************************************************************************************/
#if (CANIF_PUBLIC_CHANGE_BAUDRATE_SUPPORT == STD_ON)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_ChangeBaudrate: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ChangeBaudrate(
                                                VAR (uint8,AUTOMATIC) Controller,
                                                CONST(uint32,AUTOMATIC) dBaudRate_u32
                                                )
{

    /* Variable to store the CanStatus returned by Can_ChangeBaudrate() */
    VAR(Std_ReturnType,AUTOMATIC) CanStatus;

    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    VAR (uint8, AUTOMATIC) CanIf_Num_Controllers;

    #if(CANIF_VARIANT_INFO == 1)
    CanIf_Num_Controllers = CANIF_NUM_CONTROLLERS;
    #else
    CanIf_Num_Controllers = CanIf_ConfigSetPtr->NumControllers;
    #endif

    /* If Controller is invalid, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR_NOK((Controller >= CanIf_Num_Controllers),
                                (CANIF_CHANGEBAUDRATE_SID),
                                (CANIF_E_PARAM_CONTROLLERID)
                               )

    #endif
    CanStatus = Can_ChangeBaudrate(Controller,dBaudRate_u32);

    return(CanStatus);


}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif


 /* FC_VariationPoint_START */

/* FC_VariationPoint_END */
