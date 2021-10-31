

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "CanIf_Priv.h"

#if CANIF_TRCV_DRV_CFG!=STD_OFF
#include "CanTrcv.h"
#endif


/*
 ***************************************************************************************************
 * used functions
 ***************************************************************************************************
 */

/************************************************************************************************************/
/* Function name    :  CanIf_SetTrcvMode                                                             */
/* Syntax           :  FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvMode(
                                                 VAR(uint8, AUTOMATIC) TransceiverId,
                                                 VAR(CanTrcv_TrcvModeType, AUTOMATIC) TransceiverMode
                                                                         )
                                                                                                            */
/* Description      :  This service changes the operation mode of the transceiver, via calling the corresponding CAN Transceiver Driver service.                            */
/* Parameter        :  TransceiverId, TransceiverMode                                                          */
/* Return value     :  E_OK, E_NOT_OK                                                                       */
/************************************************************************************************************/

//This is mandatory function to be provided as per Autosar
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_SetTrcvMode: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvMode(
                                                 VAR(uint8, AUTOMATIC) TransceiverId,
                                                 VAR(CanTrcv_TrcvModeType, AUTOMATIC) TransceiverMode
                                                   )
{
    /*Return value*/
    VAR(Std_ReturnType, AUTOMATIC) RetValOfFuncs_ui;

#if CANIF_TRCV_DRV_CFG!=STD_OFF
    /*Flag to check invalidity of TransceiverId*/
    VAR(boolean, AUTOMATIC) TrcvId_Found;

    /*Loop variable*/
    VAR(uint8_least, AUTOMATIC) Loop_Var_ui;
#endif

    /* Initialize the return value to E_OK. This is to comply with autosar. CanIf_SetTrcvMode() is a mandatory API
    * So if no transceivers are configured, then return E_OK always*/
    RetValOfFuncs_ui = E_OK;

#if CANIF_TRCV_DRV_CFG!=STD_OFF
    /* Initialize the TransceiverId flag to FALSE, to indicate valid TransceiverId not found yet*/
    TrcvId_Found = FALSE;

    /* Initialize the loop variable*/
    Loop_Var_ui = 0;
#endif

    /*This is comply to autosar. CanIf_SetTrcvMode() is a mandatory API, so only functionality is disabled
     * when no transceivers are configured*/
    #if CANIF_TRCV_DRV_CFG!=STD_OFF

    /*Report to DET if CanIF was not initialized and exit the function*/
    CANIF_DET_REPORT_ERROR_NOK((FALSE == CanIf_Init_Flag), CANIF_SET_TRCV_MODE_SID, CANIF_E_UNINIT)

    /*Check if the TransceiverId indicates 'default TransceiverId'*/
    if(TransceiverId == 255)
    {
        /*Return E_OK, since this is a default Trcv Id for the CanSM networks
         * (with no transceiver mapped to it), calling of CanTrcv APIs is not applicable*/
        return E_OK;

    }

    /*The following part of the code is required to be executed only if the DET is enabled.
     * This is only required if the caller of this function is other than CanSM, required for the
     * DET check to ensure correct TransceiverId.*/

    #if (CANIF_DEV_ERROR_DETECT != STD_OFF)

    /*Search through the Trcv LUT if TransceiverId is other than 255*/
    else
    {
        /*Loop through each entry in the Trcv LUT*/
        for(Loop_Var_ui = 0; Loop_Var_ui < (uint8_least)CANIF_NUM_TRANSCEIVERS; Loop_Var_ui++)
        {
            /*If a match for TransceiverId is found...*/
            if(CanIf_Trcv_LUT[Loop_Var_ui] == TransceiverId)
            {
                /*Set TransceiverId flag to TRUE*/
                TrcvId_Found = TRUE;

                /*Stop searching*/
                break;
            }

        }

    }

    #endif


    /*Report to DET if Transceiver Id is invalid and exit the function*/
    CANIF_DET_REPORT_ERROR_NOK((TrcvId_Found == FALSE), CANIF_SET_TRCV_MODE_SID, CANIF_E_PARAM_TRCV)

    /*Report to DET if invalid TransceiverMode ie other than STANDBY, NORMAL, SLEEP 0,1,2*/
    CANIF_DET_REPORT_ERROR_NOK(((TransceiverMode!=CANTRCV_TRCVMODE_NORMAL)&&(TransceiverMode!=CANTRCV_TRCVMODE_SLEEP)&&(TransceiverMode!=CANTRCV_TRCVMODE_STANDBY)), CANIF_SET_TRCV_MODE_SID, CANIF_E_PARAM_TRCVMODE)

    /*Call the Transceiver driver function CanTrcv_SetOpMode() */
    RetValOfFuncs_ui = CanTrcv_SetOpMode(TransceiverId,TransceiverMode);

    #else
    (void)TransceiverId;
    (void)TransceiverMode;
    #endif

    return (RetValOfFuncs_ui);

}/*End of CanIf_SetTrcvMode()*/


#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

/********************************************************************************************************************/
/* Function name    :  CanIf_GetTrcvMode                                                                     */
/* Syntax           :  FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvMode(
                                       P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_APPL_DATA) TransceiverModePtr,
                                       VAR(uint8, AUTOMATIC) TransceiverId
                                                                         )
                                                                                                                    */
/* Description      :  This API returns actual state of CAN Transceiver Driver.                                     */
/* Parameter        :  TransceiverModePtr, TransceiverId                                                               */
/* Return value     :  E_OK, E_NOT_OK                                                                               */
/********************************************************************************************************************/

//This is mandatory function to be provided as per Autosar

#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_GetTrcvMode: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvMode(
                                       P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_APPL_DATA) TransceiverModePtr,
                                       VAR(uint8, AUTOMATIC) TransceiverId
                                                  )

{
    /*Return value*/
    VAR(Std_ReturnType, AUTOMATIC) RetValOfFuncs_ui;

#if CANIF_TRCV_DRV_CFG!=STD_OFF
    /*Flag to check invalidity of TransceiverId*/
    VAR(boolean, AUTOMATIC) TrcvId_Found;

    /*Loop variable*/
    VAR(uint8_least, AUTOMATIC) Loop_Var_ui;
#endif

    /* Initialize the return value to E_OK. This is to comply with autosar. CanIf_GetTrcvMode() is a mandatory API
     * So if no transceivers are configured, then return E_OK always*/
    RetValOfFuncs_ui = E_OK;

#if CANIF_TRCV_DRV_CFG!=STD_OFF
    /* Initialize the TransceiverId flag to FALSE, to indicate valid TransceiverId not found yet*/
    TrcvId_Found = FALSE;

    /* Initialize the loop variable*/
    Loop_Var_ui = 0;
#endif

    /*This is comply to autosar. CanIf_GetTrcvMode() is a mandatory API, so only functionality is disabled
    * when no transceivers are configured*/
    #if CANIF_TRCV_DRV_CFG!=STD_OFF

    /*Report to DET if CanIF was not initialized and exit the function*/
    CANIF_DET_REPORT_ERROR_NOK((FALSE == CanIf_Init_Flag), CANIF_GET_TRCV_MODE_SID, CANIF_E_UNINIT)

    /*Check if the TransceiverId indicates 'default TransceiverId'*/
    if(TransceiverId == 255)
    {
        /*Return E_OK, since this is a default Trcv Id for the CanSM networks
         * (with no transceiver mapped to it), calling of CanTrcv APIs is not applicable*/
        return E_OK;

    }


    /*The following part of the code is required to be executed only if the DET is enabled.
     * This is only required if the caller of this function is other than CanSM, required for the
     * DET check to ensure correct TransceiverId.*/

    #if (CANIF_DEV_ERROR_DETECT != STD_OFF)

    /*Search through the Trcv LUT if TransceiverId is other than 255*/
    else
    {
        /*Loop through each entry in the Trcv LUT*/
        for(Loop_Var_ui = 0; Loop_Var_ui < (uint8_least)CANIF_NUM_TRANSCEIVERS; Loop_Var_ui++)
        {
            /*If a match for TransceiverId is found...*/
            if(CanIf_Trcv_LUT[Loop_Var_ui] == TransceiverId)
            {
                /*Set TransceiverId flag to TRUE*/
                TrcvId_Found = TRUE;

                /*Stop searching*/
                break;
            }

        }

    }
    #endif


    /*Report to DET if Transceiver Id is invalid and exit the function*/
    CANIF_DET_REPORT_ERROR_NOK((TrcvId_Found == FALSE), CANIF_GET_TRCV_MODE_SID, CANIF_E_PARAM_TRCV)

    /*Report to DET if invalid TransceiverModePtr ie if a NULL pointer*/
    CANIF_DET_REPORT_ERROR_NOK((TransceiverModePtr== NULL_PTR), CANIF_GET_TRCV_MODE_SID, CANIF_E_PARAM_POINTER)

    /*Get the mode of the Transceiver */
    RetValOfFuncs_ui =CanTrcv_GetOpMode(TransceiverId, TransceiverModePtr);
    #else
    (void)TransceiverModePtr;
    (void)TransceiverId;
    #endif
    return (RetValOfFuncs_ui);

}/*CanIf_GetTrcvMode() ends*/

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


/****************************************************************************************************************/
/* Function name    :  CanIf_GetTrcvWakeupReason                                                                */
/* Syntax           :  FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason(
                                 VAR(uint8, AUTOMATIC) TransceiverId,
                                 P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_APPL_DATA) TrcvWuReasonPtr)
                                                                                                                */
/* Description      :  This API returns the reason for the wake up that the CAN transceiver has detected.       */
/* Parameter        :  TransceiverId, TrcvWuReasonPtr                                                              */
/* Return value     :  E_OK, E_NOT_OK                                                                           */
/****************************************************************************************************************/



#if CANIF_TRCV_DRV_CFG!=STD_OFF
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_GetTrcvWakeupReason: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason(
                                 VAR(uint8, AUTOMATIC) TransceiverId,
                                 P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_APPL_DATA) TrcvWuReasonPtr
                                                          )
{
        /*Return value*/
        VAR(Std_ReturnType, AUTOMATIC) RetValOfFuncs_ui;

        /*Flag to check invalidity of TransceiverId*/
        VAR(boolean, AUTOMATIC) TrcvId_Found;

        /*Loop variable*/
        VAR(uint8_least, AUTOMATIC) Loop_Var_ui;

        /* Initialize the return value */
        RetValOfFuncs_ui = E_NOT_OK;

        /* Initialize the TransceiverId flag to FALSE, to indicate valid TransceiverId not found yet*/
        TrcvId_Found = FALSE;

        /* Initialize the loop variable*/
        Loop_Var_ui = 0;

        /*Report to DET if CanIF was not initialised and exit the function*/
        CANIF_DET_REPORT_ERROR_NOK((FALSE == CanIf_Init_Flag), CANIF_GET_TRCV_WUMODE_REASON_SID, CANIF_E_UNINIT)


        /*Check if the TransceiverId indicates 'default TransceiverId'*/
        if(TransceiverId == 255)
        {
            /*Return E_OK, since this is a default Trcv Id for the CanSM networks
             * (with no transceiver mapped to it), calling of CanTrcv APIs is not applicable*/
            return E_OK;

        }

        /*The following part of the code is required to be executed only if the DET is enabled.
         * This is only required if the caller of this function is other than CanSM, required for the
         * DET check to ensure correct TransceiverId.*/

        #if (CANIF_DEV_ERROR_DETECT != STD_OFF)

        /*Search through the Trcv LUT if TransceiverId is other than 255*/
        else
        {
            /*Loop through each entry in the Trcv LUT*/
            for(Loop_Var_ui = 0; Loop_Var_ui < (uint8_least)CANIF_NUM_TRANSCEIVERS; Loop_Var_ui++)
            {
                /*If a match for TransceiverId is found...*/
                if(CanIf_Trcv_LUT[Loop_Var_ui] == TransceiverId)
                {
                    /*Set TransceiverId flag to TRUE*/
                    TrcvId_Found = TRUE;

                    /*Stop searching*/
                    break;
                }

            }

        }

        #endif


        /*Report to DET if Transceiver Id is invalid and exit the function*/
        CANIF_DET_REPORT_ERROR_NOK((TrcvId_Found == FALSE), CANIF_GET_TRCV_WUMODE_REASON_SID, CANIF_E_PARAM_TRCV)

        /*Report to DET if invalid TransceiverModePtr ie if a NULL pointer*/
        CANIF_DET_REPORT_ERROR_NOK((TrcvWuReasonPtr== NULL_PTR), CANIF_GET_TRCV_WUMODE_REASON_SID, CANIF_E_PARAM_POINTER)

        /*Get the wakeup reason for the Transceiver */
        RetValOfFuncs_ui =CanTrcv_GetBusWuReason(TransceiverId, TrcvWuReasonPtr);

    return (RetValOfFuncs_ui);

}/*CanIf_GetTrcvWakeupReason() ends*/
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif


/****************************************************************************************************************/
/* Function name    :  CanIf_SetTrcvWakeupMode                                                           */
/* Syntax           :  FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvWakeupMode(
                                                        VAR(uint8, AUTOMATIC) TransceiverId,
                                                        VAR(CanTrcv_TrcvWakeupModeType, AUTOMATIC) TrcvWakeupMode)
                                                                                                                */
/* Description      :  This API enables, disables and clears the notification for wakeup events
                       on the addressed network.                                                                */
/* Parameter        :  TransceiverId, TrcvWakeupMode                                                               */
/* Return value     :  E_OK, E_NOT_OK                                                                           */
/****************************************************************************************************************/

#if CANIF_TRCV_DRV_CFG!=STD_OFF
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_SetTrcvWakeupMode: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvWakeupMode(
                                            VAR(uint8, AUTOMATIC) TransceiverId,
                                            VAR(CanTrcv_TrcvWakeupModeType, AUTOMATIC) TrcvWakeupMode
                                            )
{
    /*Return value*/
    VAR(Std_ReturnType, AUTOMATIC) RetValOfFuncs_ui;

    /*Flag to check invalidity of TransceiverId*/
    VAR(boolean, AUTOMATIC) TrcvId_Found;

    /*Loop variable*/
    VAR(uint8_least, AUTOMATIC) Loop_Var_ui;

    /* Initialize the return value */
    RetValOfFuncs_ui = E_NOT_OK;

    /* Initialize the TransceiverId flag to FALSE, to indicate valid TransceiverId not found yet*/
    TrcvId_Found = FALSE;

    /* Initialize the loop variable*/
    Loop_Var_ui = 0;

    /*Report to DET if CanIF was not initialised and exit the function*/
    CANIF_DET_REPORT_ERROR_NOK((FALSE == CanIf_Init_Flag), CANIF_SET_TRCV_WAKEUPMODE_SID, CANIF_E_UNINIT)

    /*Check if the TransceiverId indicates 'default TransceiverId'*/
    if(TransceiverId == 255)
    {
        /*Return E_OK, since this is a default Trcv Id for the CanSM networks
         * (with no transceiver mapped to it), calling of CanTrcv APIs is not applicable*/
        return E_OK;

    }

    /*The following part of the code is required to be executed only if the DET is enabled.
     * This is only required if the caller of this function is other than CanSM, required for the
     * DET check to ensure correct TransceiverId.*/

    #if (CANIF_DEV_ERROR_DETECT != STD_OFF)

    /*Search through the Trcv LUT if TransceiverId is other than 255*/
    else
    {
        /*Loop through each entry in the Trcv LUT*/
        for(Loop_Var_ui = 0; Loop_Var_ui < (uint8_least)CANIF_NUM_TRANSCEIVERS; Loop_Var_ui++)
        {
            /*If a match for TransceiverId is found...*/
            if(CanIf_Trcv_LUT[Loop_Var_ui] == TransceiverId)
            {
                /*Set TransceiverId flag to TRUE*/
                TrcvId_Found = TRUE;

                /*Stop searching*/
                break;
            }

        }

    }
    #endif

    /*Report to DET if Transceiver Id is invalid and exit the function*/
    CANIF_DET_REPORT_ERROR_NOK((TrcvId_Found == FALSE), CANIF_SET_TRCV_WAKEUPMODE_SID, CANIF_E_PARAM_TRCV)

    /*Report to DET if invalid TrcvWakeupMode ie other than ENABLE, DISABLE, CLEAR*/
    CANIF_DET_REPORT_ERROR_NOK(((TrcvWakeupMode!=CANTRCV_WUMODE_ENABLE)&&(TrcvWakeupMode!=CANTRCV_WUMODE_DISABLE)&&(TrcvWakeupMode!=CANTRCV_WUMODE_CLEAR)), CANIF_SET_TRCV_WAKEUPMODE_SID, CANIF_E_PARAM_TRCVWAKEUPMODE)



    /* Enables, disables or clears wake-up events of the Transceiver according to TrcvWakeupMode*/
    RetValOfFuncs_ui =CanTrcv_SetWakeupMode(TransceiverId, TrcvWakeupMode);

    return (RetValOfFuncs_ui);

}/*CanIf_SetTrcvWakeupMode() ends*/
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif



/****************************************************************************************************************/
/* Function name    :  CanIf_TrcvModeIndication                                                                 */
/* Syntax           :  FUNC(void, CANIF_CODE) CanIf_TrcvModeIndication(
                                              VAR(uint8,AUTOMATIC) Transceiver,
                                              VAR(CanTrcv_TrcvModeType,AUTOMATIC) TransceiverMode
                                                                       )

                                                                                                                */
/* Description      :  This service indicates a transceiver state transition referring to the corresponding CAN transceiver.
                       This is callback function.                                                                                         */
/* Parameter        :  Transceiver, TransceiverMode                                                               */
/* Return value     :  void                                                                           */
/****************************************************************************************************************/

#if(CANIF_TRCV_DRV_CFG!=STD_OFF)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_TrcvModeIndication: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(void, CANIF_CODE) CanIf_TrcvModeIndication(
                                            VAR(uint8,AUTOMATIC) Transceiver,
                                            VAR(CanTrcv_TrcvModeType,AUTOMATIC) TransceiverMode
                                               )
{
    /*Flag to check invalidity of TransceiverId*/
    VAR(boolean, AUTOMATIC) TrcvId_Found;

    /*Loop variable*/
    VAR(uint8_least, AUTOMATIC) Loop_Var_ui;
    P2CONST(CanIf_CallbackFuncType, AUTOMATIC, AUTOMATIC) CallBackPtr_Temp;

    #if(CANIF_VARIANT_INFO == 1)
    CallBackPtr_Temp = &CanIf_Callback;
    #else
    CallBackPtr_Temp = CanIf_ConfigSetPtr->CallbackPtr;
    #endif
    /* Initialize the TransceiverId flag to FALSE, to indicate valid TransceiverId not found yet*/
    TrcvId_Found = FALSE;

    /* Initialize the loop variable*/
    Loop_Var_ui = 0;

    /* If CAN Interface is uninitialized, report to DET and exit the function */
    CANIF_DET_REPORT_ERROR((FALSE == CanIf_Init_Flag), CANIF_TRCVMODEINDICATION_SID, CANIF_E_UNINIT)

    /*Check if the TransceiverId indicates 'default TransceiverId'*/
    if(Transceiver == 255)
    {
        /*Return, since this is a default Trcv Id for the CanSM networks
         * (with no transceiver mapped to it), calling of <User_TransceiverModeIndication> is not applicable*/
        return;

    }

    /*The following part of the code is required to be executed only if the DET is enabled.
     * This is only required if the caller of this function is other than CanSM, required for the
     * DET check to ensure correct TransceiverId.*/

    #if (CANIF_DEV_ERROR_DETECT != STD_OFF)

    /*Search through the Trcv LUT if TransceiverId is other than 255*/
    else
    {
        /*Loop through each entry in the Trcv LUT*/
        for(Loop_Var_ui = 0; Loop_Var_ui < (uint8_least)CANIF_NUM_TRANSCEIVERS; Loop_Var_ui++)
        {
            /*If a match for TransceiverId is found...*/
            if(CanIf_Trcv_LUT[Loop_Var_ui] == Transceiver)
            {
                /*Set TransceiverId flag to TRUE*/
                TrcvId_Found = TRUE;

                /*Stop searching*/
                break;
            }

        }

    }
    #endif


    /*Report to DET if Transceiver Id is invalid and exit the function*/
    CANIF_DET_REPORT_ERROR((TrcvId_Found == FALSE), CANIF_TRCVMODEINDICATION_SID, CANIF_E_PARAM_TRCV)


    /* Indicate upper layer*/
    if(NULL_PTR != CallBackPtr_Temp->User_TransceiverModeIndication)
    {
        CallBackPtr_Temp->User_TransceiverModeIndication(Transceiver, TransceiverMode);
    }


}/*end of CanIf_TrcvModeIndication()*/
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif

/****************************************************************************************************************/
/* Function name    :  CanIf_ClearTrcvWufFlag                                                                 */
/* Syntax           :  FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag(
                                              VAR(uint8,AUTOMATIC) TransceiverId,
                                                                    )

                                                                                                                */
/* Description      :  This service requests the CanIf module to check the Wake flag of the designated CAN transceiver.
 *                     This API in turn calls CanTrcv_ClearTrcvWufFlag().                                                                                    */
/* Parameter        :  TransceiverId                                                               */
/* Return value     :  Std_ReturnType,
 *                        E_OK if Request is accepted
 *                        E_NOT_OK if request is not accepted                                                                    */
/****************************************************************************************************************/
#if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_ClearTrcvWufFlag: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag(
                                              VAR(uint8,AUTOMATIC) TransceiverId
                                                        )
{

    /*Return value*/
    VAR(Std_ReturnType, AUTOMATIC) RetValOfFuncs_ui;

    /*Flag to check invalidity of TransceiverId*/
    VAR(boolean, AUTOMATIC) TrcvId_Found;

    /*Loop variable*/
    VAR(uint8_least, AUTOMATIC) Loop_Var_ui;

    /*Initialse the return value*/
    RetValOfFuncs_ui = E_NOT_OK;

    /* Initialize the TransceiverId flag to FALSE, to indicate valid TransceiverId not found yet*/
    TrcvId_Found = FALSE;

    /* Initialize the loop variable*/
    Loop_Var_ui = 0;

    /*Check if the TransceiverId indicates 'default TransceiverId'*/
    if(TransceiverId == 255)
    {
        /*Return E_OK, since this is a default Trcv Id for the CanSM networks
         * (with no transceiver mapped to it), calling of CanTrcv APIs is not applicable*/
        return E_OK;

    }

    /*The following part of the code is required to be executed only if the DET is enabled.
     * This is only required if the caller of this function is other than CanSM, required for the
     * DET check to ensure correct TransceiverId.*/

    #if (CANIF_DEV_ERROR_DETECT != STD_OFF)

    /*Search through the Trcv LUT if TransceiverId is other than 255*/
    else
    {
        /*Loop through each entry in the Trcv LUT*/
        for(Loop_Var_ui = 0; Loop_Var_ui < (uint8_least)CANIF_NUM_TRANSCEIVERS; Loop_Var_ui++)
        {
            /*If a match for TransceiverId is found...*/
            if(CanIf_Trcv_LUT[Loop_Var_ui] == TransceiverId)
            {
                /*Set TransceiverId flag to TRUE*/
                TrcvId_Found = TRUE;

                /*Stop searching*/
                break;
            }

        }

    }
    #endif

    /*Report to DET if TransceiverId is invalid*/
    CANIF_DET_REPORT_ERROR_NOK((TrcvId_Found == FALSE), CANIF_CLEARTRCVWUFFLAG_SID, CANIF_E_PARAM_TRCV)


    /*Call the CanTrcv function*/
    RetValOfFuncs_ui = CanTrcv_ClearTrcvWufFlag(TransceiverId);

    return(RetValOfFuncs_ui);
}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif

/****************************************************************************************************************/
/* Function name    :  CanIf_CheckTrcvWakeFlag                                                                 */
/* Syntax           :  FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTrcvWakeFlag(
                                              VAR(uint8,AUTOMATIC) TransceiverId,
                                                                    )

                                                                                                                */
/* Description      :  TRequests the CanIf module to check the Wake flag of the designated CAN transceiver
 *                     This API in turn calls CanTrcv_ClearTrcvWufFlag().                                                                                    */
/* Parameter        :  TransceiverId                                                               */
/* Return value     :  Std_ReturnType,
 *                        E_OK if Request is accepted
 *                        E_NOT_OK if request is not accepted                                                                    */
/****************************************************************************************************************/
#if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_CheckTrcvWakeFlag: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTrcvWakeFlag(
                                              VAR(uint8,AUTOMATIC) TransceiverId
                                                        )
{
    /*Return value*/
    VAR(Std_ReturnType, AUTOMATIC) RetValOfFuncs_ui;

    /*Flag to check invalidity of TransceiverId*/
    VAR(boolean, AUTOMATIC) TrcvId_Found;

    /*Loop variable*/
    VAR(uint8_least, AUTOMATIC) Loop_Var_ui;

    /*Initialse the return value*/
    RetValOfFuncs_ui = E_NOT_OK;

    /* Initialize the TransceiverId flag to FALSE, to indicate valid TransceiverId not found yet*/
    TrcvId_Found = FALSE;

    /* Initialize the loop variable*/
    Loop_Var_ui = 0;

    /*Check if the TransceiverId indicates 'default TransceiverId'*/
    if(TransceiverId == 255)
    {
        /*Return E_OK, since this is a default Trcv Id for the CanSM networks
         * (with no transceiver mapped to it), calling of CanTrcv APIs is not applicable*/
        return E_OK;

    }

    /*The following part of the code is required to be executed only if the DET is enabled.
     * This is only required if the caller of this function is other than CanSM, required for the
     * DET check to ensure correct TransceiverId.*/

    #if (CANIF_DEV_ERROR_DETECT != STD_OFF)

    /*Search through the Trcv LUT if TransceiverId is other than 255*/
    else
    {
        /*Loop through each entry in the Trcv LUT*/
        for(Loop_Var_ui = 0; Loop_Var_ui < (uint8_least)CANIF_NUM_TRANSCEIVERS; Loop_Var_ui++)
        {
            /*If a match for TransceiverId is found...*/
            if(CanIf_Trcv_LUT[Loop_Var_ui] == TransceiverId)
            {
                /*Set TransceiverId flag to TRUE*/
                TrcvId_Found = TRUE;

                /*Stop searching*/
                break;
            }

        }

    }
    #endif


    /*Report to DET if TransceiverId is invalid*/
    CANIF_DET_REPORT_ERROR_NOK((TrcvId_Found == FALSE), CANIF_CHECKTRCVWAKEFLAG_SID, CANIF_E_PARAM_TRCV)

    /*Call the CanTrcv function*/
    RetValOfFuncs_ui = CanTrcv_CheckWakeFlag(TransceiverId);

    return(RetValOfFuncs_ui);

}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif


/****************************************************************************************************************/
/* Function name    :  CanIf_ClearTrcvWufFlagIndication                                                                 */
/* Syntax           :  FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication(
                                              VAR(uint8,AUTOMATIC) TransceiverId
                                                        )

                                                                                                                */
/* Description      :  This service indicates that the transceiver has cleared the WufFlag.
 *                     This API in turn calls <User_ClearTrcvWufFlagIndication>().                                                                                    */
/* Parameter        :  TransceiverId                                                               */
/* Return value     :  void,
                                                                  */
/****************************************************************************************************************/
#if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_ClearTrcvWufFlagIndication: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication(
                                              VAR(uint8,AUTOMATIC) TransceiverId
                                                        )
{

    /*Flag to check invalidity of TransceiverId*/
    VAR(boolean, AUTOMATIC) TrcvId_Found;

    /*Loop variable*/
    VAR(uint8_least, AUTOMATIC) Loop_Var_ui;
    P2CONST(CanIf_CallbackFuncType, AUTOMATIC, AUTOMATIC) CallBackPtr_Temp;

    #if(CANIF_VARIANT_INFO == 1)
    CallBackPtr_Temp = &CanIf_Callback;
    #else
    CallBackPtr_Temp = CanIf_ConfigSetPtr->CallbackPtr;
    #endif

    /* Initialize the TransceiverId flag to FALSE, to indicate valid TransceiverId not found yet*/
    TrcvId_Found = FALSE;

    /* Initialize the loop variable*/
    Loop_Var_ui = 0;

    /*Proceed further only if CanIf is initialised*/
    if(TRUE == CanIf_Init_Flag)
    {
        /*Check if the TransceiverId indicates 'default TransceiverId'*/
        if(TransceiverId == 255)
        {
            /*Return, since this is a default Trcv Id for the CanSM networks
             * (with no transceiver mapped to it), calling of <User_ClearTrcvWufFlagIndication> APIs is not applicable*/
            return;

        }

        /*The following part of the code is required to be executed only if the DET is enabled.
         * This is only required if the caller of this function is other than CanSM, required for the
         * DET check to ensure correct TransceiverId.*/

        #if (CANIF_DEV_ERROR_DETECT != STD_OFF)

        /*Search through the Trcv LUT if TransceiverId is other than 255*/
        else
        {
            /*Loop through each entry in the Trcv LUT*/
            for(Loop_Var_ui = 0; Loop_Var_ui < (uint8_least)CANIF_NUM_TRANSCEIVERS; Loop_Var_ui++)
            {
                /*If a match for TransceiverId is found...*/
                if(CanIf_Trcv_LUT[Loop_Var_ui] == TransceiverId)
                {
                    /*Set TransceiverId flag to TRUE*/
                    TrcvId_Found = TRUE;

                    /*Stop searching*/
                    break;
                }

            }

        }
        #endif

        /*Report to DET if invalid TransceiverId is invalid*/
        CANIF_DET_REPORT_ERROR((TrcvId_Found == FALSE), CANIF_CLEARTRCVWAKEFLAGIND_SID, CANIF_E_PARAM_TRCV)

        /*Notify to the upper layer*/
        if(CallBackPtr_Temp->User_ClearTrcvWufFlagIndication != NULL_PTR)
        {
            CallBackPtr_Temp->User_ClearTrcvWufFlagIndication(TransceiverId);
        }

    }

}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif

/****************************************************************************************************************/
/* Function name    :  CanIf_CheckTrcvWakeFlagIndication                                                                 */
/* Syntax           :  FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication(
                                              VAR(uint8,AUTOMATIC) TransceiverId
                                                        )

                                                                                                                */
/* Description      :  This service indicates the reason  for the wakeup  that the CAN transceiver has detected.
 *                     This API in turn calls <User_CheckTrcvWakeFlagIndication>().                                                                                    */
/* Parameter        :  TransceiverId                                                               */
/* Return value     :  void,
                                                                  */
/****************************************************************************************************************/
#if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_CheckTrcvWakeFlagIndication: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication(
                                              VAR(uint8,AUTOMATIC) TransceiverId
                                                        )
{
    /*Flag to check invalidity of TransceiverId*/
    VAR(boolean, AUTOMATIC) TrcvId_Found;

    /*Loop variable*/
    VAR(uint8_least, AUTOMATIC) Loop_Var_ui;

    P2CONST(CanIf_CallbackFuncType, AUTOMATIC, AUTOMATIC) CallBackPtr_Temp;

    #if(CANIF_VARIANT_INFO == 1)
    CallBackPtr_Temp = &CanIf_Callback;
    #else
    CallBackPtr_Temp = CanIf_ConfigSetPtr->CallbackPtr;
    #endif
    /* Initialize the TransceiverId flag to FALSE, to indicate valid TransceiverId not found yet*/
    TrcvId_Found = FALSE;

    /* Initialize the loop variable*/
    Loop_Var_ui = 0;

    /*Proceed further only if CanIf is initialised*/
    if(TRUE == CanIf_Init_Flag)
    {
        /*Check if the TransceiverId indicates 'default TransceiverId'*/
        if(TransceiverId == 255)
        {
            /*Return, since this is a default Trcv Id for the CanSM networks
             * (with no transceiver mapped to it), calling of <User_CheckTrcvWakeFlagIndication> APIs is not applicable*/
            return;

        }

        /*The following part of the code is required to be executed only if the DET is enabled.
         * This is only required if the caller of this function is other than CanSM, required for the
         * DET check to ensure correct TransceiverId.*/

        #if (CANIF_DEV_ERROR_DETECT != STD_OFF)

        /*Search through the Trcv LUT if TransceiverId is other than 255*/
        else
        {
            /*Loop through each entry in the Trcv LUT*/
            for(Loop_Var_ui = 0; Loop_Var_ui < (uint8_least)CANIF_NUM_TRANSCEIVERS; Loop_Var_ui++)
            {
                /*If a match for TransceiverId is found...*/
                if(CanIf_Trcv_LUT[Loop_Var_ui] == TransceiverId)
                {
                    /*Set TransceiverId flag to TRUE*/
                    TrcvId_Found = TRUE;

                    /*Stop searching*/
                    break;
                }

            }

        }
        #endif

        /*Report to DET if invalid TransceiverId is invalid*/
        CANIF_DET_REPORT_ERROR((TrcvId_Found == FALSE), CANIF_CHECKTRCVWAKEFLAGIND_SID, CANIF_E_PARAM_TRCV)

        if(CallBackPtr_Temp->User_CheckTrcvWakeFlagIndication != NULL_PTR)
        {
            CallBackPtr_Temp->User_CheckTrcvWakeFlagIndication(TransceiverId);
        }

    }

}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif

/****************************************************************************************************************/
/* Function name    :  CanIf_ConfirmPnAvailability                                                                 */
/* Syntax           :  FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability(
                                              VAR(uint8,AUTOMATIC) TransceiverId
                                                        )

                                                                                                                */
/* Description      :  This service indicates that the transceiver is running in PN communication.
 *                     This API in turn calls <User_ConfirmPnAvailability>().                                                                                    */
/* Parameter        :  TransceiverId                                                               */
/* Return value     :  void,
                                                                  */
/****************************************************************************************************************/
#if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC RETURN VIOLATION IN CanIf_ConfirmPnAvailability: Function contains more than one return statement.This is needed mainly because of DET. */
FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability(
                                              VAR(uint8,AUTOMATIC) TransceiverId
                                                        )
{
    /*Flag to check invalidity of TransceiverId*/
    VAR(boolean, AUTOMATIC) TrcvId_Found;

    /*Loop variable*/
    VAR(uint8_least, AUTOMATIC) Loop_Var_ui;

    P2CONST(CanIf_CallbackFuncType, AUTOMATIC, AUTOMATIC) CallBackPtr_Temp;

    #if(CANIF_VARIANT_INFO == 1)
    CallBackPtr_Temp = &CanIf_Callback;
    #else
    CallBackPtr_Temp = CanIf_ConfigSetPtr->CallbackPtr;
    #endif

    /* Initialize the TransceiverId flag to FALSE, to indicate valid TransceiverId not found yet*/
    TrcvId_Found = FALSE;

    /* Initialize the loop variable*/
    Loop_Var_ui = 0;

    /*Proceed further only if CanIf is initialised*/
    if(TRUE == CanIf_Init_Flag)
    {
        /*Check if the TransceiverId indicates 'default TransceiverId'*/
        if(TransceiverId == 255)
        {
            /*Return, since this is a default Trcv Id for the CanSM networks
             * (with no transceiver mapped to it), calling of <User_ConfirmPnAvailability> APIs is not applicable*/
            return;

        }

        /*The following part of the code is required to be executed only if the DET is enabled.
         * This is only required if the caller of this function is other than CanSM, required for the
         * DET check to ensure correct TransceiverId.*/

        #if (CANIF_DEV_ERROR_DETECT != STD_OFF)
        /*Search through the Trcv LUT if TransceiverId is other than 255*/
        else
        {
            /*Loop through each entry in the Trcv LUT*/
            for(Loop_Var_ui = 0; Loop_Var_ui < (uint8_least)CANIF_NUM_TRANSCEIVERS; Loop_Var_ui++)
            {
                /*If a match for TransceiverId is found...*/
                if(CanIf_Trcv_LUT[Loop_Var_ui] == TransceiverId)
                {
                    /*Set TransceiverId flag to TRUE*/
                    TrcvId_Found = TRUE;

                    /*Stop searching*/
                    break;
                }

            }

        }
        #endif

        /*Report to DET if invalid TransceiverId is invalid*/
        CANIF_DET_REPORT_ERROR((TrcvId_Found == FALSE), CANIF_CONFIRMPNAVAILABILITY_SID, CANIF_E_PARAM_TRCV)

        if(CallBackPtr_Temp->User_ConfirmPnAvailability != NULL_PTR)
        {
            CallBackPtr_Temp->User_ConfirmPnAvailability(TransceiverId);
        }

    }

}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif


