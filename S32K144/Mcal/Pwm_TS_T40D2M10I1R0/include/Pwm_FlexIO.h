/**
*   @file           Pwm_FlexIO.h
*   @version        1.0.1
*
*   @brief          AUTOSAR Pwm - PWM FlexIO API header file.
*   @details        PWM FlexIO API header file.
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
*   AUTOSAR Version      : 4.3.1
*   AUTOSAR Revision     : ASR_REL_4_3_REV_0001
*   AUTOSAR Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_3_REV_0001_20190621
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2019 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef PWM_FLEXIO_H
#define PWM_FLEXIO_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_FlexIO_H_REF_1
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Pwm_FlexIO_H_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
* that 31 character significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
* 
* @section Pwm_FlexIO_H_REF_3
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
*/



/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

#include "Std_Types.h"
#include "Pwm_Ipw_Types.h"


/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/

/**
* @{
* @file           Pwm_FlexIO.h
*/
#define PWM_FLEXIO_VENDOR_ID                            43
/** @violates @ref Pwm_FlexIO_H_REF_2 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Pwm_FlexIO_H_REF_1 Identifier exceeds 31 chars. */
#define PWM_FLEXIO_AR_RELEASE_MAJOR_VERSION             4
/** @violates @ref Pwm_FlexIO_H_REF_2 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Pwm_FlexIO_H_REF_1 Identifier exceeds 31 chars. */
#define PWM_FLEXIO_AR_RELEASE_MINOR_VERSION             3
/** @violates @ref Pwm_FlexIO_H_REF_2 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Pwm_FlexIO_H_REF_1 Identifier exceeds 31 chars. */
#define PWM_FLEXIO_AR_RELEASE_REVISION_VERSION          1
#define PWM_FLEXIO_SW_MAJOR_VERSION                     1
#define PWM_FLEXIO_SW_MINOR_VERSION                     0
#define PWM_FLEXIO_SW_PATCH_VERSION                     1
/**@}*/



/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PWM_FLEXIO_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_FLEXIO_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Pwm_FlexIO.h and Std_Types.h are different."
    #endif
#endif

/* Check if header file and PWM header file are of the same vendor */
#if (PWM_FLEXIO_VENDOR_ID != PWM_IPW_TYPES_VENDOR_ID)
    #error "Pwm_FlexIO.h and Pwm_Ipw_Types.h have different vendor ids."
#endif

/* Check if header file and PWM header file are of the same AUTOSAR version */
#if ((PWM_FLEXIO_AR_RELEASE_MAJOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_FLEXIO_AR_RELEASE_MINOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_FLEXIO_AR_RELEASE_REVISION_VERSION != PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_FlexIO.h and Pwm_Ipw_Types.h are different."
#endif

/* Check if header file and PWM header file are of the same software version */
#if ((PWM_FLEXIO_SW_MAJOR_VERSION != PWM_IPW_TYPES_SW_MAJOR_VERSION) || \
     (PWM_FLEXIO_SW_MINOR_VERSION != PWM_IPW_TYPES_SW_MINOR_VERSION) || \
     (PWM_FLEXIO_SW_PATCH_VERSION != PWM_IPW_TYPES_SW_PATCH_VERSION))
#error "Software version numbers of Pwm_FlexIO.h and Pwm_Ipw_Types.h are different."
#endif


#if (PWM_FLEXIO_USED == STD_ON)
    


/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/**
* @brief          Defines the value for 0% duty cycle.
*
*/
#define PWM_FLEXIO_DUTY_0                       ((uint16)0x0000U)

/**
* @brief          Defines the value for 100% duty cycle.
*
*/
#define PWM_FLEXIO_DUTY_100                     ((uint16)0x8000U)



/*===============================================================================================
*                                     FUNCTION PROTOTYPES
===============================================================================================*/

#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm_FlexIO_H_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"


/*=============================================================================================*/
FUNC(void, PWM_CODE) Pwm_FlexIO_Init
(   
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
);


/*=============================================================================================*/
#if (PWM_DE_INIT_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_FlexIO_DeInit
(   
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
);
#endif /* PWM_DE_INIT_API */


/*=============================================================================================*/
#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_FlexIO_SetDutyCycle
(
    VAR         (uint8,                         AUTOMATIC)                      u8LgChannelIdx,
    VAR         (uint16,                        AUTOMATIC)                      u16DutyCycle,
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
);
#endif /* PWM_SET_DUTY_CYCLE_API */


/*=============================================================================================*/
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_FlexIO_SetPeriodAndDuty
(
    VAR         (uint8,                         AUTOMATIC)                      u8LgChannelIdx,
    VAR         (Pwm_PeriodType,                AUTOMATIC)                      nPeriod,
    VAR         (uint16,                        AUTOMATIC)                      u16DutyCycle,
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
);
#endif /* PWM_SET_PERIOD_AND_DUTY_API */


/*=============================================================================================*/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
FUNC(Pwm_OutputStateType, PWM_CODE) Pwm_FlexIO_GetOutputState
(
    VAR         (uint8,                         AUTOMATIC)                      u8LgChannelIdx,
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
);
#endif /* PWM_GET_OUTPUT_STATE_API */


/*=============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
FUNC(void, PWM_CODE) Pwm_FlexIO_DisableNotification
(
    VAR         (uint8,                         AUTOMATIC)                      u8LgChannelIdx,
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
);
#endif /* PWM_NOTIFICATION_SUPPORTED */


/*=============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
FUNC(void, PWM_CODE) Pwm_FlexIO_EnableNotification
(
    VAR         (uint8,                         AUTOMATIC)                      u8LgChannelIdx,
    VAR         (Pwm_EdgeNotificationType,      AUTOMATIC)                      eNotification,
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
);
#endif /* PWM_NOTIFICATION_SUPPORTED */


/*=============================================================================================*/
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
FUNC(uint16, PWM_CODE)  Pwm_FlexIO_GetChannelState
(
    VAR         (uint8,                         AUTOMATIC)                      u8LgChannelIdx,
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
);
#endif /* PWM_GET_CHANNEL_STATE_API */


/*=============================================================================================*/
#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_NOTIFICATION_SUPPORTED == STD_ON))
FUNC(Std_ReturnType, PWM_CODE) Pwm_FlexIO_ValidateNotification
(
    VAR         (uint8,                         AUTOMATIC)                      u8LgChannelIdx,
    VAR         (Pwm_EdgeNotificationType,      AUTOMATIC)                      eNotification,
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
);
#endif


/*=============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
FUNC(Std_ReturnType, PWM_CODE) Pwm_FlexIO_ValidateIdleState
(
    P2CONST     (Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
);
#endif /* PWM_POWER_STATE_SUPPORTED */


/*=============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
FUNC(void, PWM_CODE) Pwm_FlexIO_SetPowerState
(
    P2CONST     (Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig,
    VAR         (Pwm_PowerStateType,            AUTOMATIC)                      nPowerState
);
#endif /* PWM_POWER_STATE_SUPPORTED */

/*=============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
FUNC(void, PWM_CODE) Pwm_FlexIO_InterruptHandler
(
    VAR         (uint8,                         AUTOMATIC)                      ChannelId,
    VAR         (uint8,                         AUTOMATIC)                      u8TimerMaskFlag
);
#endif /* PWM_NOTIFICATION_SUPPORTED */


#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_FlexIO_H_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"



#endif  /* PWM_FLEXIO_USED */

#ifdef __cplusplus
}
#endif

#endif  /* PWM_FLEXIO_H */

/** @} */
