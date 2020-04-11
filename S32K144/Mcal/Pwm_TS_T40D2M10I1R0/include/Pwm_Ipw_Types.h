/**
*   @file           Pwm_Ipw_Types.h
*   @version        1.0.1
*
*   @brief          AUTOSAR Pwm - PWM driver IPW header file.
*   @details        IPW defines, types used by PWM driver.
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



#ifndef PWM_IPW_TYPES_H
#define PWM_IPW_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_IPW_Types_H_REF_1
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*/
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pwm_Types.h"
#include "Pwm_Ftm_Types.h"
#include "Pwm_FlexIO_Types.h"


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Pwm_Ipw_Types.h
*/
#define PWM_IPW_TYPES_VENDOR_ID                         43
#define PWM_IPW_TYPES_MODULE_ID                         121
/* @violates @ref Pwm_IPW_Types_H_REF_1 Identifier exceeds 31 chars. */
#define PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION          4
/* @violates @ref Pwm_IPW_Types_H_REF_1 Identifier exceeds 31 chars. */
#define PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION          3
/* @violates @ref Pwm_IPW_Types_H_REF_1 Identifier exceeds 31 chars. */
#define PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION       1
#define PWM_IPW_TYPES_SW_MAJOR_VERSION                  1
#define PWM_IPW_TYPES_SW_MINOR_VERSION                  0
#define PWM_IPW_TYPES_SW_PATCH_VERSION                  1
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if included Pwm_Types.h header file has same vendor */
#if (PWM_IPW_TYPES_VENDOR_ID != PWM_TYPES_VENDOR_ID)
    #error "Pwm_Ipw_Types.h and Pwm_Types.h have different vendor ids"
#endif

/* Check if included Pwm_Types.h header file has same AUTOSAR version */
#if ((PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    !=  PWM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION    !=  PWM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION !=  PWM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw_Types.h and Pwm_Types.h are different"
#endif

/* Check if included Pwm_Types.h header file has same software version */
#if ((PWM_IPW_TYPES_SW_MAJOR_VERSION !=  PWM_TYPES_SW_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_SW_MINOR_VERSION !=  PWM_TYPES_SW_MINOR_VERSION) || \
     (PWM_IPW_TYPES_SW_PATCH_VERSION !=  PWM_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw_Types.h and Pwm_Types.h are different"
#endif

/* Check if included Pwm_Ftm_Types.h header file has same vendor */
#if (PWM_IPW_TYPES_VENDOR_ID != PWM_FTM_TYPES_VENDOR_ID)
    #error "Pwm_Ipw_Types.h and Pwm_Ftm_Types.h have different vendor ids"
#endif

/* Check if included Pwm_Ftm_Types.h header file has same AUTOSAR version */
#if ((PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    !=  PWM_FTM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION    !=  PWM_FTM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION !=  PWM_FTM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ipw_Types.h and Pwm_Ftm_Types.h are different"
#endif

/* Check if included Pwm_Ftm_Types.h header file has same software version */
#if ((PWM_IPW_TYPES_SW_MAJOR_VERSION !=  PWM_FTM_TYPES_SW_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_SW_MINOR_VERSION !=  PWM_FTM_TYPES_SW_MINOR_VERSION) || \
     (PWM_IPW_TYPES_SW_PATCH_VERSION !=  PWM_FTM_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ipw_Types.h and Pwm_Ftm_Types.h are different"
#endif

/* Check if included Pwm_FlexIO_Types.h header file has same vendor */
#if (PWM_IPW_TYPES_VENDOR_ID != PWM_FLEXIO_TYPES_VENDOR_ID)
    #error "Pwm_Ipw_Types.h and Pwm_FlexIO_Types.h have different vendor ids"
#endif

/* Check if included Pwm_FlexIO_Types.h header file has same AUTOSAR version */
#if ((PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    !=  PWM_FLEXIO_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION    !=  PWM_FLEXIO_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION !=  PWM_FLEXIO_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw_Types.h and Pwm_FlexIO_Types.h are different"
#endif

/* Check if included Pwm_FlexIO_Types.h header file has same software version */
#if ((PWM_IPW_TYPES_SW_MAJOR_VERSION !=  PWM_FLEXIO_TYPES_SW_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_SW_MINOR_VERSION !=  PWM_FLEXIO_TYPES_SW_MINOR_VERSION) || \
     (PWM_IPW_TYPES_SW_PATCH_VERSION !=  PWM_FLEXIO_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw_Types.h and Pwm_FlexIO_Types.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       PLATFORM SPECIFIC DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief Symbolic name for Ftm channels */
#define PWM_FTM_CHANNEL         ((Pwm_ChannelIpType)0)

/** @brief Symbolic name for FlexIO channels */
#define PWM_FLEXIO_CHANNEL      ((Pwm_ChannelIpType)1)

/** @brief Duty cycle 50%*/
#define PWM_HALF_PERIOD_DUTY    ((uint16)0x4000U)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief      IP type used to implement a Pwm channel
*/
typedef uint8 Pwm_ChannelIpType;

/**
* @brief        PWM channel high level configuration structure
*
*/
typedef struct 
{
    /** @brief  IP used to indicate which platform does PWM channel belong to (FlexIO, FTM) */
    CONST       (Pwm_ChannelIpType,             PWM_CONST)                      nChannelIp;
    /** @brief  Index in the IP specific configuration table */
    CONST       (uint8,                         PWM_CONST)                      u8IdxChannelConfig;    
} Pwm_IpChannelConfigType;

/**
* @brief      Combined IP specific configuration structure
*/
typedef struct 
{
#if (PWM_FLEXIO_USED == STD_ON)
    /** @brief  Pointer to the structure containing FlexIO configuration */
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       PWM_CONST,  PWM_APPL_CONST)     pFlexIOIpConfig;
#endif
#if (PWM_FTM_USED == STD_ON)
    /** @brief Pointer to the structure containing FTM configuration */
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  PWM_CONST, PWM_APPL_CONST)  pFtmIpConfig;
#endif
    /** @brief  Pointer to array containing IP type and index in the configuration table for each PWM channel */
    CONST       (Pwm_IpChannelConfigType,  PWM_CONST)                 (*pIpChannelsConfig)[];
} Pwm_IpConfigType;


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
      

#ifdef __cplusplus
}
#endif

#endif    /* PWM_IPW_TYPES_H */

/** @} */

