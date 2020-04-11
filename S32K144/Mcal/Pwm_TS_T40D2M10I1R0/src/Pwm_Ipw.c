/**
*   @file           Pwm_Ipw.c
*   @version        1.0.1
*
*   @brief          AUTOSAR Pwm - PWM IPW API implementation.
*   @details        PWM IWP API implementation.
*
*   @addtogroup     PWM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : Ftm
*   Dependencies         : none
*
*   Autosar Version      : 4.3.1
*   Autosar Revision     : ASR_REL_4_3_REV_0001
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_3_REV_0001_20190621
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2019 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/



#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_IPW_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include'
* MemMap.h included after each section define in order to set the current memory section
*
* @section Pwm_IPW_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Pwm_IPW_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
* that 31 character significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Pwm_IPW_C_REF_5
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*/


/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
/*
* @file           Pwm_Ipw.c
*/

#include "Pwm_Ipw.h"
#include "Pwm_Ftm.h"
#include "Pwm_FlexIO.h"
#include "Pwm_Ipw_Notif.h"

/*===============================================================================================
*                                        SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Pwm_Ipw.c
*/
#define PWM_IPW_VENDOR_ID_C                     43
/** @violates @ref Pwm_IPW_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Pwm_IPW_C_REF_5 Identifier exceeds 31 chars. */
#define PWM_IPW_AR_RELEASE_MAJOR_VERSION_C      4
/** @violates @ref Pwm_IPW_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Pwm_IPW_C_REF_5 Identifier exceeds 31 chars. */
#define PWM_IPW_AR_RELEASE_MINOR_VERSION_C      3
/** @violates @ref Pwm_IPW_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Pwm_IPW_C_REF_5 Identifier exceeds 31 chars. */
#define PWM_IPW_AR_RELEASE_REVISION_VERSION_C   1
#define PWM_IPW_SW_MAJOR_VERSION_C              1
#define PWM_IPW_SW_MINOR_VERSION_C              0
#define PWM_IPW_SW_PATCH_VERSION_C              1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
#if (PWM_IPW_VENDOR_ID_C != PWM_IPW_VENDOR_ID)
    #error "Pwm_Ipw.c and Pwm_Ipw.h have different vendor ids"
#endif

#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION_C    != PWM_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION_C    != PWM_IPW_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION_C != PWM_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ipw.c and Pwm_Ipw.h are different"
#endif

#if ((PWM_IPW_SW_MAJOR_VERSION_C != PWM_IPW_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION_C != PWM_IPW_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION_C != PWM_IPW_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ipw.c and Pwm_Ipw.h are different"
#endif


#if (PWM_IPW_VENDOR_ID_C != PWM_FTM_VENDOR_ID)
    #error "Pwm_Ipw.c and Pwm_Ftm.h have different vendor ids"
#endif

#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION_C    != PWM_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION_C    != PWM_FTM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION_C != PWM_FTM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ipw.c and Pwm_Ftm.h are different"
#endif

#if ((PWM_IPW_SW_MAJOR_VERSION_C != PWM_FTM_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION_C != PWM_FTM_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION_C != PWM_FTM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ipw.c and Pwm_Ftm.h are different"
#endif


#if (PWM_IPW_VENDOR_ID_C != PWM_FLEXIO_VENDOR_ID)
    #error "Pwm_Ipw.c and Pwm_FlexIO.h have different vendor ids"
#endif

#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION_C    != PWM_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION_C    != PWM_FLEXIO_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION_C != PWM_FLEXIO_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ipw.c and Pwm_FlexIO.h are different"
#endif

#if ((PWM_IPW_SW_MAJOR_VERSION_C != PWM_FLEXIO_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION_C != PWM_FLEXIO_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION_C != PWM_FLEXIO_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ipw.c and Pwm_FlexIO.h are different"
#endif

#if (PWM_IPW_VENDOR_ID_C != PWM_IPW_NOTIF_VENDOR_ID)
    #error "Pwm_Ipw.c and Pwm_Ipw_Notif.h have different vendor ids"
#endif

#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION_C    != PWM_IPW_NOTIF_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION_C    != PWM_IPW_NOTIF_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION_C != PWM_IPW_NOTIF_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ipw.c and Pwm_Ipw_Notif.h are different"
#endif

#if ((PWM_IPW_SW_MAJOR_VERSION_C != PWM_IPW_NOTIF_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION_C != PWM_IPW_NOTIF_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION_C != PWM_IPW_NOTIF_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ipw.c and Pwm_Ipw_Notif.h are different"
#endif

/*===============================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
===============================================================================================*/
 
/*===============================================================================================
*                                       CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       LOCAL VARIABLES
===============================================================================================*/

/*===============================================================================================
*                                       GLOBAL CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       GLOBAL VARIABLES
===============================================================================================*/

/*===============================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
===============================================================================================*/

/*===============================================================================================
*                                       LOCAL FUNCTIONS
===============================================================================================*/

/*===============================================================================================
*                                       GLOBAL FUNCTIONS
===============================================================================================*/
#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm_IPW_C_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"


/*================================================================================================*/
/**
* @brief            Pwm_Ipw_Init
* @details          This function call the supported IP initialization functions.
*
* @param[in]        pIpConfig - Pointer to PWM top configuration structure
*
* @return           void
*
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_Init
(   
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
#if (PWM_FTM_USED == STD_ON)
    if (NULL_PTR != pIpConfig->pFtmIpConfig)
    {
        /* Call FTM IP init function */
        Pwm_Ftm_Init(pIpConfig->pFtmIpConfig);
    }
#endif

#if (PWM_FLEXIO_USED == STD_ON)
    if (NULL_PTR != pIpConfig->pFlexIOIpConfig)
    {
        /* Call FlexIO IP init function */
        Pwm_FlexIO_Init(pIpConfig->pFlexIOIpConfig);
    }
#endif
}


/*===============================================================================================*/
#if (PWM_DE_INIT_API == STD_ON)
/**
* @brief            Pwm_Ipw_DeInit
* @details          This function call the supported IP deinitialization functions.
*
* @param[in]        pIpConfig - Pointer to PWM top configuration structure
*
* @return           void
*
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_DeInit
(
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
#if (PWM_FTM_USED == STD_ON)
    if (NULL_PTR != pIpConfig->pFtmIpConfig)
    {
        /* Call FlexPwm IP init function */
        Pwm_Ftm_DeInit(pIpConfig->pFtmIpConfig);
    }
#endif

#if (PWM_FLEXIO_USED == STD_ON)
    if (NULL_PTR != pIpConfig->pFlexIOIpConfig)
    {
        /* Call FlexIO IP init function */
        Pwm_FlexIO_DeInit(pIpConfig->pFlexIOIpConfig);
    }
#endif

}
#endif /* PWM_DE_INIT_API */


/*===============================================================================================*/
#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
/**
* @brief            Pwm_Ipw_SetDutyCycle
* @details          This function will call SetDutyCycle function for the corresponding IP of PwmChannel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        u16DutyCycle    Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
* @return           void
*
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_SetDutyCycle
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (uint16,           AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    if (PWM_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp )
    {
#if (PWM_FTM_USED == STD_ON)
     /* Call Ftm IP function */
        Pwm_Ftm_SetDutyCycle(
                            (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig, 
                            u16DutyCycle,
        #if ((PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
                            PWM_UPDATE_ASYNCHRONOUS,
        #endif
                            pIpConfig->pFtmIpConfig
                         );
#endif
    }
    else if(PWM_FLEXIO_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
#if (PWM_FLEXIO_USED == STD_ON)
    /* Call FlexIO IP function */
        Pwm_FlexIO_SetDutyCycle( (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig,
                                 u16DutyCycle,
                                 pIpConfig->pFlexIOIpConfig
       
                              );
        
    
#endif  
    }
    else
    {
        /* Do nothing */
        /* This parameter is not used */
        (void)u16DutyCycle;
    }

}
#endif /* PWM_SET_DUTY_CYCLE_API */


/*===============================================================================================*/
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/**
* @brief            Pwm_Ipw_SetPeriodAndDuty
* @details          This function will call SetPeriodAndDuty function for the corresponding IP of PwmChannel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        nPeriod         Pwm signal period value
* @param[in]        u16DutyCycle    Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
* @return           void
*
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_SetPeriodAndDuty
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (Pwm_PeriodType,   AUTOMATIC)                 nPeriod,
    VAR         (uint16,           AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    if (PWM_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp )
    {
#if (PWM_FTM_USED == STD_ON)    
        /* Call Ftm IP function */
        Pwm_Ftm_SetPeriodAndDuty(
                                (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig, 
                                nPeriod, 
                                u16DutyCycle,  
        #if ((PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
                                PWM_UPDATE_ASYNCHRONOUS,
        #endif
                                pIpConfig->pFtmIpConfig
                              );
#endif
    }
    else if(PWM_FLEXIO_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
#if (PWM_FLEXIO_USED == STD_ON) 
        /* Call FlexIO IP function */
        Pwm_FlexIO_SetPeriodAndDuty (
                                      (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig,
                                      nPeriod,
                                      u16DutyCycle,
                                      pIpConfig->pFlexIOIpConfig
                                    );
        
#endif  
    }
    else
    {
        /* Do nothing */
        /* This parameter is not used */
        (void)nPeriod;
        (void)u16DutyCycle;
    }
    
    
}
#endif /* PWM_SET_PERIOD_AND_DUTY_API */


/*===============================================================================================*/
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/**
* @brief            Pwm_Ipw_SetOutputToIdle
* @details          This function will call SetOutputToIdle function for the corresponding IP of PwmChannel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
* @return           void
*
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_SetOutputToIdle
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    if (PWM_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
#if (PWM_FTM_USED == STD_ON)        
        /* Call Ftm IP function */
        Pwm_Ftm_SetOutputToIdle((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig, pIpConfig->pFtmIpConfig);
#endif
    }
    else
    {
        /* Do nothing */
    }
}
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */


/*===============================================================================================*/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief            Pwm_Ipw_GetOutputState
* @details          This function will call GetOutputState function for the corresponding IP of PwmChannel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
*
*/
FUNC(Pwm_OutputStateType,PWM_CODE) Pwm_Ipw_GetOutputState
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    VAR(Pwm_OutputStateType, AUTOMATIC) retVal = (Pwm_OutputStateType)PWM_LOW;
    
    if (PWM_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
#if (PWM_FTM_USED == STD_ON)        
        /* Call Ftm IP function */
        retVal = Pwm_Ftm_GetOutputState((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig, pIpConfig->pFtmIpConfig);
#endif
    }
    else if (PWM_FLEXIO_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
#if (PWM_FLEXIO_USED == STD_ON)
        /* Call FlexIO IP function*/
        retVal = Pwm_FlexIO_GetOutputState((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig, pIpConfig->pFlexIOIpConfig);
#endif
    }
    else
    {
        /* Do nothing */
    }       
    return retVal;
}
#endif /* PWM_GET_OUTPUT_STATE_API */


/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief            Pwm_Ipw_DisableNotification
* @details          This function will call DisableNotification function for the corresponding IP of PwmChannel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
*
*/
FUNC(void,PWM_CODE) Pwm_Ipw_DisableNotification
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    if (PWM_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
#if (PWM_FTM_USED == STD_ON)   
        /* Call Ftm IP function */
        Pwm_Ftm_DisableNotification((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig, pIpConfig->pFtmIpConfig);
#endif
    }
    else if (PWM_FLEXIO_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
#if (PWM_FLEXIO_USED == STD_ON) 
        Pwm_FlexIO_DisableNotification((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig, pIpConfig->pFlexIOIpConfig);
#endif 
    }
    else
    {
        /* Do nothing */
    }
}


/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_EnableNotification
* @details          This function will call EnableNotification function for the corresponding IP of PwmChannel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        eNotification   Notification type to be enabled
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_EnableNotification
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 nChannelNumber,
    VAR         (Pwm_EdgeNotificationType,  AUTOMATIC)                 eNotification,
    CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    if (PWM_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
#if (PWM_FTM_USED == STD_ON)   
        /* Call Ftm IP function */
        Pwm_Ftm_EnableNotification((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig, eNotification, pIpConfig->pFtmIpConfig);
#endif
    }
    else if (PWM_FLEXIO_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
#if (PWM_FLEXIO_USED == STD_ON) 
        /* Call FlexIO IP function */
        Pwm_FlexIO_EnableNotification((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig, eNotification, pIpConfig->pFlexIOIpConfig);
#endif
    }
    else
    {
        /* Do nothing */
        /* This parameter is not used */
        (void)eNotification;
    }
}

#endif /* PWM_NOTIFICATION_SUPPORTED */


/*===============================================================================================*/
#if ((PWM_FAULT_SUPPORTED == STD_ON) && (PWM_FTM_USED == STD_ON))
/**
* @brief         Pwm_Ipw_GetFtmIpConfigPtr
* @details       This function is called from Pwm_Ftm.c file in order to get the pointer
*                to the Ftm IP configuration. This function is required only by Ftm
*                Fault functionality
*
* @param         None
*
* @return        Pwm_FlexPwm_IpConfigType* - Pointer to the FlexPwm IP configuration structure
*
*/
FUNC (P2CONST(Pwm_Ftm_IpConfigType, AUTOMATIC, PWM_APPL_CONST), PWM_CODE) Pwm_Ipw_GetFtmIpConfigPtr
(
    void
)
{
    P2CONST(Pwm_IpConfigType,         AUTOMATIC, PWM_APPL_CONST) pIpConfig;
    P2CONST(Pwm_Ftm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pFtmIpConfigRet;
        
    pIpConfig = Pwm_GetIpConfigPtr();
    /* If returned value was NULL, return NULL pointer */
    if(NULL_PTR == pIpConfig)
    {
        pFtmIpConfigRet = NULL_PTR;   
    }
    else
    {
        pFtmIpConfigRet =  pIpConfig->pFtmIpConfig;   
    }
    return pFtmIpConfigRet;
}
#endif /* (PWM_FAULT_SUPPORTED == STD_ON) */


#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_GetChannelState
* @details          This function will call GetChannelState function for the corresponding IP of PwmChannel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
* @return           uint16
*/
FUNC (uint16, PWM_CODE) Pwm_Ipw_GetChannelState
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    VAR(uint16, AUTOMATIC) dutyCycle = (uint16)0x00;    
    if (PWM_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
#if (PWM_FTM_USED == STD_ON)  
        /* Call Ftm IP function */
        dutyCycle = Pwm_Ftm_GetChannelState((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig, pIpConfig->pFtmIpConfig);   
#endif
    }
    else if (PWM_FLEXIO_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp )
    {
#if (PWM_FLEXIO_USED == STD_ON) 
        /* Call FlexIO IP function */
        dutyCycle = Pwm_FlexIO_GetChannelState((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig, pIpConfig->pFlexIOIpConfig);
#endif
    }
    else
    {
        /* Do nothing */
    }
    return dutyCycle;
}

#endif /* PWM_GET_CHANNEL_STATE_API */


#if (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON)
/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_ForceOutputToZero
* @details          This function will call ForceOutputToZero function only if then channel is a
*                   FlexPwm channel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        bForce          Flag to state if force to zero should be applied or not
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_ForceOutputToZero
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 nChannelNumber,
    VAR         (boolean,                   AUTOMATIC)                 bForce,
    CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    if (PWM_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
#if (PWM_FTM_USED == STD_ON)        
        /* Call Ftm IP function */
        Pwm_Ftm_ForceOutputToZero((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig,  bForce, pIpConfig->pFtmIpConfig);        
#endif
    }
    else
    {
        /* Do nothing */
        /* This parameter is not used */
        (void)bForce;
    }
}
#endif


/*===============================================================================================*/
#if (PWM_SET_CLOCK_MODE_API == STD_ON)
/**
* @brief            Pwm_Ipw_SetClockMode
* @details          This function will call SetClockMode function of all configured Hw IPs
*
* @param[in]        ePrescaler      Prescaler - prescaler type 
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*/
FUNC (void, PWM_CODE) Pwm_Ipw_SetClockMode
(
    VAR         (Pwm_PrescalerType,         AUTOMATIC)                 ePrescaler,
    CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
#if (PWM_FTM_USED == STD_ON)        
    if (NULL_PTR != pIpConfig->pFtmIpConfig)
    {
        /* Call GTM IP function */
        Pwm_Ftm_SetClockMode(ePrescaler, pIpConfig->pFtmIpConfig);
    }
    else
    {
        /* This parameter is not used */
        (void)ePrescaler;
    }
#else
    /* This parameter is not used */
    (void)ePrescaler;
    (void)pIpConfig;
#endif

}
#endif


/*===============================================================================================*/
#if (PWM_UPDATE_DUTY_SYNCHRONOUS == STD_ON)
#if (PWM_SYNC_UPDATE_API == STD_ON)
/**
* @brief            Pwm_Ipw_SyncUpdate
* @details          This function will call Pwm_Ftm_SyncUpdate to allow synchronized loading
*                   of the duty registers for all the channels of a given Ftm module 
*
* @param[in]        u8ModuleId          Pwm module id of the given FlexPwm module
*
* @return           void
*/
FUNC (void, PWM_CODE) Pwm_Ipw_SyncUpdate
(
    VAR(uint8, AUTOMATIC)  u8ModuleId
)
{
#if (PWM_FTM_USED == STD_ON)        
    Pwm_Ftm_SyncUpdate(u8ModuleId);
#else
    /* Do nothing */
    /* This parameter is not used */
    (void)u8ModuleId;   
#endif 
  
}
#endif /*PWM_SYNC_UPDATE_API*/


/*===============================================================================================*/
#if (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON)
/**
* @brief            Pwm_Ipw_SetPeriodAndDuty_NoUpdate
* @details          This function will call SetPeriodAndDuty (synchronous mode) function for the corresponding IP of PwmChannel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        nPeriod         Pwm signal period value
* @param[in]        u16DutyCycle    Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
* @return           void
*
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_SetPeriodAndDuty_NoUpdate
/* @violates @ref Pwm_IPW_C_REF_5 Identifier exceeds 31 chars. */
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (Pwm_PeriodType,   AUTOMATIC)                 nPeriod,
    VAR         (uint16,           AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    if (PWM_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
#if (PWM_FTM_USED == STD_ON)        
        /* Call Ftm IP function */
        Pwm_Ftm_SetPeriodAndDuty(
                                 (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig, 
                                  nPeriod, 
                                  u16DutyCycle,  
                                  PWM_UPDATE_SYNCHRONOUS,
                                  pIpConfig->pFtmIpConfig
                                );
#endif
    }
    else
    {
        /* Do nothing */
        /* This parameter is not used */
        (void)nPeriod;
        (void)u16DutyCycle;
    }
   
    
}
#endif /* PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API */

/*===============================================================================================*/
#if (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON)
/**
* @brief            Pwm_Ipw_SetDutyCycle_NoUpdate
* @details          This function will call SetDutyCycle (synchronous mode) function for the corresponding IP of PwmChannel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        u16DutyCycle    Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
* @return           void
*
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_SetDutyCycle_NoUpdate
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (uint16,           AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    if (PWM_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
#if (PWM_FTM_USED == STD_ON)        
        /* Call Ftm IP function */
        Pwm_Ftm_SetDutyCycle(
                               (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig, 
                               u16DutyCycle,
                               PWM_UPDATE_SYNCHRONOUS,
                               pIpConfig->pFtmIpConfig
                            );  
#endif
    }
    else
    {
        /* Do nothing */
        /* This parameter is not used */
        (void)u16DutyCycle;
    }
    
    
}
#endif /* PWM_SET_DUTY_CYCLE_NO_UPDATE_API */
#endif /*PWM_UPDATE_DUTY_SYNCHRONOUS*/

#if (PWM_SET_PHASE_SHIFT_API == STD_ON)
/**
* @brief        This function set phase shift value and also force duty cycle to 50%
*
* @details      In order to have Phase-Shifted Full-Bridge controller, Pwm_SetPhaseShift is introduced.
*               This function bases on FTM Combine mode with Cn and C(n+1) combine to generate leading 
*               edge and trailing edge. Pwm_SetPhaseShift allows to set both phase shift value and period,
*               the duty value is fixed to 50%.
* @param[in]    nChannelNumber -        Pwm Channel Id in the configuration
* @param[in]    nPeriod                 Pwm signal period value
* @param[in]    u16PhaseShift           Phase shift value
* @param[in]    pIpConfig               Pointer to Ipw configuration structure
*
* @return       void
*/
FUNC (void, PWM_CODE) Pwm_Ipw_SetPhaseShift
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (uint16,           AUTOMATIC)                 nPeriod,
    VAR         (uint16,           AUTOMATIC)                 u16PhaseShift,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    if (PWM_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
#if (PWM_FTM_USED == STD_ON)        
        /* Call Ftm IP function */
        Pwm_Ftm_SetPhaseShift((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig, nPeriod, u16PhaseShift,  pIpConfig->pFtmIpConfig, (boolean)TRUE);
#endif
    }
    else
    {
        /* Do nothing */
        /* This parameter is not used */
        (void)nPeriod;
        (void)u16PhaseShift;
    }
    
}
#endif
#if (PWM_SET_PHASE_SHIFT_NO_UPDATE_API == STD_ON)
/*============================================================================================================*/
/**
* @brief        This function set phase shift value and also force duty cycle to 50%. The output will take 
*               effect after Pwm_SyncUpdate be called.
*
* @details      In order to have Phase-Shifted Full-Bridge controller, Pwm_SetPhaseShift is introduced.
*               This function bases on FTM Combine mode with Cn and C(n+1) combine to generate leading 
*               edge and trailing edge. Pwm_SetPhaseShift allows to set both phase shift value and period,
*               the duty value is fixed to 50%.
* @param[in]    nChannelNumber -        Pwm Channel Id in the configuration
* @param[in]    nPeriod                 Pwm signal period value
* @param[in]    u16PhaseShift           Phase shift value
* @param[in]    pIpConfig               Pointer to Ipw configuration structure
*
* @return       void
*/
FUNC (void, PWM_CODE) Pwm_Ipw_SetPhaseShift_NoUpdate
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (uint16,           AUTOMATIC)                 nPeriod,
    VAR         (uint16,           AUTOMATIC)                 u16PhaseShift,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    if (PWM_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
#if (PWM_FTM_USED == STD_ON)        
        /* Call Ftm IP function */
        Pwm_Ftm_SetPhaseShift((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig, nPeriod, u16PhaseShift,  pIpConfig->pFtmIpConfig, (boolean)FALSE);
#endif
    }
    else
    {
        /* Do nothing */
        /* This parameter is not used */
        (void)nPeriod;
        (void)u16PhaseShift;
    }
     
    
}
#endif /* PWM_SET_PHASE_SHIFT_NO_UPDATE_API */


/*===============================================================================================*/
#if (PWM_ENABLE_TRIGEER_API == STD_ON)
/**
* @brief        This function enable trigger generation for specific source
* @details      Corresponding bits with trigger source as bellow:
*       Bit 0   Channel 2 Trigger Enable
*       Bit 1   Channel 3 Trigger Enable
*       Bit 2   Channel 4 Trigger Enable
*       Bit 3   Channel 5 Trigger Enable
*       Bit 4   Channel 0 Trigger Enable
*       Bit 5   Channel 1 Trigger Enable
*       Bit 6   Initialization Trigger Enable
*       Bit 8   Channel 6 Trigger Enable
*       Bit 9   Channel 7 Trigger Enable
*
* @param[in]    u8TriggerHostId - FTM module
* @param[in]    u16TriggerMask - bit mask will be clear for FTM_EXTTRIG. 
*
* @return       void
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_EnableTrigger
(
    VAR(uint8, AUTOMATIC) u8TriggerHostId,
    VAR(uint16,AUTOMATIC) u16TriggerMask
)
{

#if (PWM_FTM_USED == STD_ON)        
    Pwm_Ftm_EnableTrigger(u8TriggerHostId, u16TriggerMask);
#else
    /* Do nothing */
    /* This parameter is not used */
    (void)u8TriggerHostId;
    (void)u16TriggerMask;
    
#endif   

}
#endif /*#if (PWM_ENABLE_TRIGEER_API == STD_ON)*/

#if (PWM_DISABLE_TRIGEER_API == STD_ON)
/*===============================================================================================*/
/**
* @brief        This function disable trigger generation for specific source
* @details      Corresponding bits with trigger source as bellow:
*       Bit 0   Channel 2 Trigger Enable
*       Bit 1   Channel 3 Trigger Enable
*       Bit 2   Channel 4 Trigger Enable
*       Bit 3   Channel 5 Trigger Enable
*       Bit 4   Channel 0 Trigger Enable
*       Bit 5   Channel 1 Trigger Enable
*       Bit 6   Initialization Trigger Enable
*       Bit 8   Channel 6 Trigger Enable
*       Bit 9   Channel 7 Trigger Enable
*
* @param[in]    u8TriggerHostId - FTM module
* @param[in]    u16TriggerMask - bit mask will be cleared for FTM_EXTTRIG. 
*
* @return       void
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_DisableTrigger
(
    VAR(uint8, AUTOMATIC) u8TriggerHostId,
    VAR(uint16,AUTOMATIC) u16TriggerMask
)
{

#if (PWM_FTM_USED == STD_ON)        
    Pwm_Ftm_DisableTrigger(u8TriggerHostId,u16TriggerMask);
#else   
    /* Do nothing */
    /* This parameter is not used */
    (void)u8TriggerHostId;
    (void)u16TriggerMask;
    
#endif  

}
#endif /*PWM_DISABLE_TRIGEER_API*/

/*===============================================================================================*/
#if (PWM_RESET_COUNTER_API == STD_ON)
/**
* @brief        This function enables counter reset by Pwm_SyncUpdate() call
* @details
*
*
* @param[in]    u8ModuleId - FTM module
*
* @return       void
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_ResetCounterEnable
(
    VAR(uint8, AUTOMATIC) u8ModuleId
)
{
    
#if (PWM_FTM_USED == STD_ON)        
    Pwm_Ftm_ResetCounterEnable(u8ModuleId);
#else
    /* Do nothing */
    /* This parameter is not used */
    (void)u8ModuleId;
#endif  
    
}

/**
* @brief        This function disabled counter reset by Pwm_SyncUpdate() call
* @details
*
*
* @param[in]    u8ModuleId - FTM module
*
* @return       void
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_ResetCounterDisable
(
    VAR(uint8, AUTOMATIC) u8ModuleId
)
{
    
#if (PWM_FTM_USED == STD_ON)        
    Pwm_Ftm_ResetCounterDisable(u8ModuleId);
#else  
    /* Do nothing */
    /* This parameter is not used */
    (void)u8ModuleId;
#endif
   
}
#endif /*PWM_SW_RESET_COUNTER_API*/

/*===============================================================================================*/
#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
/**
* @brief        This function force channels output to their inactive state
* @details      Corresponding bits with channel will be masked:
*       Bit 0   Channel 0 Output Mask
*       Bit 1   Channel 1 Output Mask
*       Bit 2   Channel 2 Output Mask
*       Bit 3   Channel 3 Output Mask
*       Bit 4   Channel 4 Output Mask
*       Bit 5   Channel 5 Output Mask
*       Bit 6   Channel 6 Output Mask
*       Bit 7   Channel 7 Output Mask
*
* @param[in]    u8ModuleId - FTM module
* @param[in]    u8ChannelMask - bit mask will be set for FTM_OUTMASK. 
*
* @return       void
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_MaskOutputs
(
    VAR(uint8 , AUTOMATIC)          u8ModuleId,
    VAR(uint8 , AUTOMATIC)          u8ChannelMask
)
{

#if (PWM_FTM_USED == STD_ON)        
    Pwm_Ftm_MaskOutputs(u8ModuleId, u8ChannelMask);
#else
    /* Do nothing */
    /* This parameter is not used */
    (void)u8ModuleId;
    (void)u8ChannelMask;
#endif 
 
}


/*===============================================================================================*/
/**
* @brief        This function puts channels output to normal operation state
* @details      Corresponding bits with channel will be masked:
*       Bit 0   Channel 0 Output Mask
*       Bit 1   Channel 1 Output Mask
*       Bit 2   Channel 2 Output Mask
*       Bit 3   Channel 3 Output Mask
*       Bit 4   Channel 4 Output Mask
*       Bit 5   Channel 5 Output Mask
*       Bit 6   Channel 6 Output Mask
*       Bit 7   Channel 7 Output Mask
*
* @param[in]    u8ModuleId - FTM module
* @param[in]    u8ChannelMask - bit mask will be cleared for FTM_OUTMASK. 
*
* @return       void
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_UnMaskOutputs
(
    VAR(uint8 , AUTOMATIC)     u8ModuleId,
    VAR(uint8 , AUTOMATIC)     u8ChannelMask
)
{

#if (PWM_FTM_USED == STD_ON)        
    Pwm_Ftm_UnMaskOutputs(u8ModuleId,u8ChannelMask);
#else
    
    /* Do nothing */
    /* This parameter is not used */
    (void)u8ModuleId;
    (void)u8ChannelMask;

#endif
   

}

#endif /*PWM_ENABLE_MASKING_OPERATIONS*/

#if (PWM_PARAM_CHECK == STD_ON)
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/*===============================================================================================*/
/**
* @brief            Pwm_Ftm_ValidateNotification
* @details          This function will check given channel with notification supported
*
* @param[in]        u8ChannelNumber  Pwm Channel Id in the configuration
* @param[in]        eNotification    Notification type
* @param[out]       u8RetVal          E_NOT_OK -> Notification handler is not valid
*/

FUNC (Std_ReturnType, PWM_CODE) Pwm_Ipw_ValidateNotification
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 u8ChannelNumber,
    VAR         (Pwm_EdgeNotificationType,  AUTOMATIC)                 eNotification,
    CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) nRetVal = (Std_ReturnType)E_OK;

    if (PWM_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[u8ChannelNumber].nChannelIp)
    {
#if (PWM_FTM_USED == STD_ON)     
        nRetVal = Pwm_Ftm_ValidateNotification
                 (
                       (*pIpConfig->pIpChannelsConfig)[u8ChannelNumber].u8IdxChannelConfig,
                        pIpConfig->pFtmIpConfig
                  );
#endif
    }
    else if (PWM_FLEXIO_CHANNEL == (*pIpConfig->pIpChannelsConfig)[u8ChannelNumber].nChannelIp)
    {
#if (PWM_FLEXIO_USED == STD_ON)
        nRetVal = Pwm_FlexIO_ValidateNotification
                  (
                     (*pIpConfig->pIpChannelsConfig)[u8ChannelNumber].u8IdxChannelConfig,
                      eNotification,
                      pIpConfig->pFlexIOIpConfig
                  );
#endif  
    }
    else
    {
        /* Do nothing */
        /* This parameter is not used */
        (void)eNotification; 
    }
    
    return nRetVal;
}

#endif
#if( (PWM_SET_PHASE_SHIFT_API == STD_ON) || (PWM_SET_PHASE_SHIFT_NO_UPDATE_API == STD_ON))
/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_ValidateParamsSetPhaseShift
* @details          This function will check phase shift value, has to be lower or equal duty 50% 
*
* @param[in]        u16PhaseShift    Phase shift value
*
* @RetVal           Std_ReturnType           
*/
FUNC (Std_ReturnType, PWM_CODE) Pwm_Ipw_ValidateParamsPhaseShift
/* @violates @ref Pwm_IPW_C_REF_5 Identifier exceeds 31 chars. */
(
    VAR(uint16,                                     AUTOMATIC) u16PhaseShift
)
{
    /* Variable to store the value returned by the function */
    VAR(Std_ReturnType, AUTOMATIC) RetVal = (Std_ReturnType)E_OK;
#if (PWM_FTM_USED == STD_ON) 
    if (PWM_HALF_PERIOD_DUTY < u16PhaseShift)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#else
    (void)u16PhaseShift;

#endif
    return RetVal;
}
/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_ValidateChannelSetPhaseShift
* @details          This function will check phase shift value, has to be lower or equal duty 50% 
*
* @param[in]        u8ChannelNumber    Pwm Channel Id in the configuration
* @param[in]        pIpConfig          Pointer Ipw configuration structure
*
* @RetVal           Std_ReturnType           
*/
FUNC (Std_ReturnType, PWM_CODE) Pwm_Ipw_ValidateChannelSetPhaseShift
/* @violates @ref Pwm_IPW_C_REF_5 Identifier exceeds 31 chars. */
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 u8ChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{   
    /* Variable to store the value returned by the function */
    VAR(Std_ReturnType, AUTOMATIC) RetVal = (Std_ReturnType)E_OK;

    if (PWM_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[u8ChannelNumber].nChannelIp)
    {
#if (PWM_FTM_USED == STD_ON)        
        RetVal = Pwm_Ftm_ValidateChannelSetPhaseShift
                (
                    (*pIpConfig->pIpChannelsConfig)[u8ChannelNumber].u8IdxChannelConfig,
                    pIpConfig->pFtmIpConfig
                );
    
#endif
    }
    else
    {
        /*Do nothing*/
    }

    return RetVal;
}
#endif
/*===============================================================================================*/
#if ((PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON))
/**
* @brief            Pwm_Ftm_ValidateParamsFtmSynchronous
* @details          This function will check given channel with FTM Synchronization supported
*                   DutyCycle always updates immediately 
* @param[in]        u8ChannelNumber     Ftm Channel Id in the configuration
* @param[in]        pIpConfig           Pointer Ipw configuration structure
* @param[out]       RetVal          E_NOT_OK  FTM Synchronization is not supported this channel
*/
FUNC (uint8, PWM_CODE) Pwm_Ipw_ValidateChannelSync
/* @violates @ref Pwm_IPW_C_REF_5 Identifier exceeds 31 chars. */
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 u8ChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    /* Variable to store the value returned by the function */
    VAR(Std_ReturnType, AUTOMATIC) RetVal = (Std_ReturnType)E_OK;
    
    if (PWM_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[u8ChannelNumber].nChannelIp)
    {
#if (PWM_FTM_USED == STD_ON)        
        RetVal = Pwm_Ftm_ValidateChannelSync
                (
                    (*pIpConfig->pIpChannelsConfig)[u8ChannelNumber].u8IdxChannelConfig,
                    pIpConfig->pFtmIpConfig
                );
    
#endif
    }
    else
    {
        /*Do nothing*/
    }
    
    return RetVal;
}
#endif

/*===============================================================================================*/
#if ((PWM_DISABLE_TRIGEER_API == STD_ON) || (PWM_ENABLE_TRIGEER_API == STD_ON))
/**
* @brief            This function will check bit mask.
* @details          Bis mask will be process at lower layer has to be compatible with  hardware register 
*
* @param[in]        u32TriggerMask    Trigger mask value
*
* @retVal           retVal          E_NOT_OK  Bit mask is not compatible.
*/
FUNC (uint8, PWM_CODE) Pwm_Ipw_ValidateTriggerMask
(
    VAR(uint32,                         AUTOMATIC) u32TriggerMask
)
{
    /* Variable to store the value returned by the function */
    VAR(Std_ReturnType, AUTOMATIC) RetVal = (Std_ReturnType)E_OK;
    
#if (PWM_FTM_USED == STD_ON)      
    RetVal = Pwm_Ftm_ValidateTriggerMask(u32TriggerMask);
#else
    (void)u32TriggerMask;
#endif
    return RetVal;
}
#endif


/*===============================================================================================*/
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
FUNC (Std_ReturnType, PWM_CODE) Pwm_Ipw_ValidateSetOutPutToIdle
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 u8ChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    /* Variable to store the value returned by the function */
    VAR(Std_ReturnType, AUTOMATIC) nRetVal = (Std_ReturnType)E_OK;

    if (PWM_FLEXIO_CHANNEL == (*pIpConfig->pIpChannelsConfig)[u8ChannelNumber].nChannelIp)
    {
#if (PWM_FLEXIO_USED == STD_ON) 
        nRetVal = (Std_ReturnType)E_NOT_OK;
#endif
    }
    else
    {
        /* Do nothing*/
    }
    
    return nRetVal;
}
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */


/*===============================================================================================*/
#if ((PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
FUNC (uint32, PWM_CODE) Pwm_Ipw_GetMaxPeriodValue
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 u8ChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
     /** @brief  Store return value */
    VAR         (uint32,                        AUTOMATIC)                      u32RetVal = (uint32)0xFFFFU;
    
    if (PWM_FLEXIO_CHANNEL == (*pIpConfig->pIpChannelsConfig)[u8ChannelNumber].nChannelIp)
    {
#if (PWM_FLEXIO_USED == STD_ON)
        /* Maximum period for FlexIO channel is 255 */
        u32RetVal = (uint32)0xFFU;
#endif
    }
    else if (PWM_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[u8ChannelNumber].nChannelIp)
    {
#if (PWM_FTM_USED == STD_ON)
        /* Maximum period for FTM channel is 65534 */
        u32RetVal = (uint32)0xFFFEU;
#endif
    }
    else
    {
        /* Do nothing */
    }

    return u32RetVal;
    
    
}
#endif


#endif /*(PWM_PARAM_CHECK == STD_ON)*/

#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief            Pwm_Ipw_ValidateIdleState
* @details          This function will call ValidateIdleState function of all configured Hw IPs
*
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*/
FUNC(Std_ReturnType, PWM_CODE) Pwm_Ipw_ValidateIdleState
(
    P2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{   
    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) nRetVal = (Std_ReturnType)E_OK;
    
#if (PWM_FTM_USED == STD_ON)
    if (NULL_PTR != pIpConfig->pFtmIpConfig)    
    {
        /* Call FlexIO FTM function */
        nRetVal = Pwm_Ftm_ValidateIdleState(pIpConfig->pFtmIpConfig);
    }   
#endif  

#if (PWM_FLEXIO_USED == STD_ON)
    if (NULL_PTR != pIpConfig->pFlexIOIpConfig)
    {
        /* Call FlexIO IP function */
        nRetVal = Pwm_FlexIO_ValidateIdleState(pIpConfig->pFlexIOIpConfig);
    }
#endif

    return nRetVal;
}


/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_SetPowerState
* @details          This function will call SetPowerState function of all configured Hw IPs
*
* @param[in]        nPowerState     target power mode
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*/
FUNC(void, PWM_CODE) Pwm_Ipw_SetPowerState
(
    P2CONST     (Pwm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pIpConfig,
    VAR         (Pwm_PowerStateType,AUTOMATIC)                 nPowerState
)
{
    
#if (PWM_FTM_USED == STD_ON)
    if (NULL_PTR != pIpConfig->pFtmIpConfig)    
    {
        /* Call FTM IP function */
        Pwm_Ftm_SetPowerState(pIpConfig->pFtmIpConfig, nPowerState);
    }   
#endif

#if (PWM_FLEXIO_USED == STD_ON)
    if (NULL_PTR != pIpConfig->pFlexIOIpConfig)
    {
        /* Call FlexIO IP function */
       Pwm_FlexIO_SetPowerState(pIpConfig->pFlexIOIpConfig, nPowerState);
    }
#endif
    
}
#endif


#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_IPW_C_REF_1 Only preprocessor statements and comments before "#include"
*/
/*
* @violates @ref Pwm_IPW_C_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
