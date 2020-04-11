/**
*   @file           Pwm_FlexIO_Types.h
*   @version        1.0.1
*
*   @brief          AUTOSAR Pwm - PWM FlexIO data types header file.
*   @details        PWM FlexIO defines, types.
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

#ifndef PWM_FLEXIO_TYPES_H
#define PWM_FLEXIO_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif



/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

#include "Pwm_Cfg.h"


/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/

/**
* @{
* @file           Pwm_FlexIO_Types.h
*/
#define PWM_FLEXIO_TYPES_VENDOR_ID                          43
#define PWM_FLEXIO_TYPES_AR_RELEASE_MAJOR_VERSION           4
#define PWM_FLEXIO_TYPES_AR_RELEASE_MINOR_VERSION           3
#define PWM_FLEXIO_TYPES_AR_RELEASE_REVISION_VERSION        1
#define PWM_FLEXIO_TYPES_SW_MAJOR_VERSION                   1
#define PWM_FLEXIO_TYPES_SW_MINOR_VERSION                   0
#define PWM_FLEXIO_TYPES_SW_PATCH_VERSION                   1
/**@}*/



/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

/* Check if header file and Pwm_Cfg.h header file are of the same vendor */
#if (PWM_FLEXIO_TYPES_VENDOR_ID != PWM_CFG_VENDOR_ID)
    #error "Vendor IDs of Pwm_FlexIO_Types.h and Pwm_Cfg.h are different."
#endif

/* Check if header file and Pwm_Cfg.h header file are of the same AUTOSAR version */
#if ((PWM_FLEXIO_TYPES_AR_RELEASE_MAJOR_VERSION    != PWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_FLEXIO_TYPES_AR_RELEASE_MINOR_VERSION    != PWM_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_FLEXIO_TYPES_AR_RELEASE_REVISION_VERSION != PWM_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_FlexIO_Types.h and Pwm_Cfg.h are different."
#endif

/* Check if header file and Pwm_Cfg.h header file are of the same software version */
#if ((PWM_FLEXIO_TYPES_SW_MAJOR_VERSION != PWM_CFG_SW_MAJOR_VERSION) || \
     (PWM_FLEXIO_TYPES_SW_MINOR_VERSION != PWM_CFG_SW_MINOR_VERSION) || \
     (PWM_FLEXIO_TYPES_SW_PATCH_VERSION != PWM_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_FlexIO_Types.h and Pwm_Cfg.h are different."
#endif


#if (PWM_FLEXIO_USED == STD_ON)

/*===============================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/**
* @brief        FlexIO hardware channel type
*
*/
typedef uint8 Pwm_FlexIO_ChannelType;

/**
* @brief        FlexIO hardware timer type
*
*/
typedef uint8 Pwm_FlexIO_TimerType;


/**
* @brief        FlexIO interrupt edge type
*
*/
typedef uint8 Pwm_FlexIO_EdgeStateType;



/**
* @brief        FlexIO IP specific channel configuration structure type
*
*/
typedef struct
{
    /** @brief  Default period: [0-0xFF] */
    CONST       (Pwm_PeriodType,            PWM_CONST)                      nPwmDefaultPeriod; 
    /** @brief  Default duty cycle: [0-0x8000] */
    CONST       (uint16,                    PWM_CONST)                      u16PwmDefaultDutyCycle;
    /** @brief  FlexIO hardware channel ID */
    CONST       (Pwm_FlexIO_ChannelType,    PWM_CONST)                      nHwChannelId;
    /** @brief  FlexIO hardware timer ID */
    CONST       (Pwm_FlexIO_TimerType,      PWM_CONST)                      nHwTimerId; 
} Pwm_FlexIO_ChannelConfigType;


/**
* @brief        FlexIO IP configuration structure type
*/
typedef struct
{
    /** @brief  Number of FlexIO channels in the configuration */
    CONST       (uint8,                         PWM_CONST)                  u8ChannelNumber;
    /** @brief  Pointer to the configured channels for FlexIO */
    CONST       (Pwm_FlexIO_ChannelConfigType,  PWM_CONST)                  (*pChannelsConfig)[]; 
 
} Pwm_FlexIO_IpConfigType;



/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/** 
* @brief        Defines that specifies the channel notification types in FlexIO modules
*
*/

#define PWM_FLEXIO_NO_EDGE                      ((Pwm_FlexIO_EdgeStateType)0U)

#define PWM_FLEXIO_CHF_IRQ_EDGE                 ((Pwm_FlexIO_EdgeStateType)1U)

#define PWM_FLEXIO_CHF_IRQ_IDLE                 ((Pwm_FlexIO_EdgeStateType)2U)

/** 
* @brief        Defines that specifies the channel status in FlexIO modules
*
*/

#define PWM_FLEXIO_CHANNEL_NO_INIT              ((uint8)0U)

#define PWM_FLEXIO_CHANNEL_RUNNING              ((uint8)1U)

#define PWM_FLEXIO_CHANNEL_IDLE                 ((uint8)2U)

/**
* @brief        Defines that specifies the next channel status handler
*
*/

#define PWM_FLEXIO_CHANNEL_NO_CHANGE            ((uint8)0U)

#define PWM_FLEXIO_CHANNEL_CHANGE_DUTY          ((uint8)1U)

#define PWM_FLEXIO_CHANNEL_CHANGE_PERIOD        ((uint8)2U)

#define PWM_FLEXIO_CHANNEL_CHANGE_RUNNING       ((uint8)3U)

#define PWM_FLEXIO_CHANNEL_CHANGE_IDLE          ((uint8)4U)


#endif  /* PWM_FLEXIO_USED */

#ifdef __cplusplus
}
#endif

#endif /* PWM_FLEXIO_TYPES_H */

/** @} */
