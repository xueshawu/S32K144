

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
/* Function name    : CanIf_GetTxConfirmationState                                                                        */
/* Syntax           : FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_GetTxConfirmationState(
                                                                        VAR(uint8,AUTOMATIC) ControllerId
                                                                                    )   */
/* Description      : This service reports, if any TX confirmation has been done for the whole CAN controller
                      since the last CAN controller start.                              */
/* Parameter        : ControllerId                                                               */
/* Return value     : CANIF_NO_NOTIFICATION / CANIF_TX_RX_NOTIFICATION                                                                       */
/************************************************************************************************************/
#if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC COMF VIOLATION IN CanIf_GetTxConfirmationState: Function contains very simple "else if" statements and "switch-cases". HIS metric compliance would decrease readability and maintainability. */
FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_GetTxConfirmationState(
                                       VAR(uint8,AUTOMATIC) ControllerId
                                               )
{
    #if (CANIF_DEV_ERROR_DETECT != STD_OFF)
    VAR (uint8, AUTOMATIC) CanIf_Num_Controllers;
    #endif

    VAR (CanIf_NotifStatusType, AUTOMATIC) RetVal;

    P2VAR(CanIf_NotifStatusType, AUTOMATIC, AUTOMATIC) TxConfStatus_Temp;

    /* If CAN Interface is uninitialized, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR_NO_NOTIF((FALSE == CanIf_Init_Flag), CANIF_GET_TX_CONFIRMATION_STATE_SID, CANIF_E_UNINIT)

    #if(CANIF_VARIANT_INFO == 1)
    #if (CANIF_DEV_ERROR_DETECT != STD_OFF)
    CanIf_Num_Controllers = CANIF_NUM_CONTROLLERS;
    #endif
    TxConfStatus_Temp = CanIf_TxConf_State;
    #else
    #if (CANIF_DEV_ERROR_DETECT != STD_OFF)
    CanIf_Num_Controllers = CanIf_ConfigSetPtr->NumControllers;
    #endif
    TxConfStatus_Temp = CanIf_ConfigSetPtr->TxConfStatusPtr;
    #endif

    /* If Controller is invalid, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR_NO_NOTIF((ControllerId >= CanIf_Num_Controllers), CANIF_GET_TX_CONFIRMATION_STATE_SID,CANIF_E_PARAM_CONTROLLERID)

    /* Return CANIF_NO_NOTIFICATION / CANIF_TX_RX_NOTIFICATION for the requested Controller */


    /* Enter Critical Section */
    SchM_Enter_CanIf_TxRxNotifNoNest();

    /*Make local copy of *(TxConfStatus_Temp +ControllerId)*/
    RetVal = *(TxConfStatus_Temp +ControllerId);

    /* Leave Critical Section */
    SchM_Exit_CanIf_TxRxNotifNoNest();

    return(RetVal);

}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif


