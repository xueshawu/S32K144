

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "CanIf_Priv.h"

#if (CANIF_PUBLIC_CHANGE_BAUDRATE_SUPPORT == STD_ON)
/*Can.h included for Can_CheckBaudrate()*/
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
/* Syntax           : FUNC(void, CANIF_CODE) CanIf_CheckBaudrate(
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
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckBaudrate(
                                                VAR (uint8,AUTOMATIC) Controller,
                                                CONST(uint32,AUTOMATIC) dBaudRate_u32
                                                )
{
    /* Variable to store the CanStatus returned by CanIf_CheckBaudrate() */
    VAR(Std_ReturnType,AUTOMATIC) CanStatus;

    #if CANIF_DEV_ERROR_DETECT != STD_OFF
    VAR (uint8, AUTOMATIC) CanIf_Num_Controllers;

    /* If CAN Interface is uninitialized, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR_NOK((FALSE == CanIf_Init_Flag),
                               CANIF_CHECKBAUDRATE_SID,
                               CANIF_E_UNINIT
                              )

    #if(CANIF_VARIANT_INFO == 1)
    CanIf_Num_Controllers = CANIF_NUM_CONTROLLERS;
    #else
    CanIf_Num_Controllers = CanIf_ConfigSetPtr->NumControllers;
    #endif

    /* If Controller is invalid, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR_NOK((Controller >= CanIf_Num_Controllers),
                                (CANIF_CHECKBAUDRATE_SID),
                                (CANIF_E_PARAM_CONTROLLERID)
                               )
    #endif

    CanStatus = Can_CheckBaudrate(Controller,dBaudRate_u32);

    return (CanStatus);
}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif




