/**
*   @file    Mcl_FlexIO_Common_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - FLEXIO driver header file.
*   @details FLEXIO defines.
*
*   @addtogroup FLEXIO_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : eDMA
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

#ifndef FLEXIO_COMMON_TYPES_H
#define FLEXIO_COMMON_TYPES_H
/**
*   @file    Mcl_FlexIO_Common_Types.h
*/
#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
**/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Mcl_FlexIO_Common_Types.h
* @brief          Source file version information
* 
*/
#define FLEXIO_COMMON_TYPES_VENDOR_ID                       43
#define FLEXIO_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define FLEXIO_COMMON_TYPES_AR_RELEASE_MINOR_VERSION        3
#define FLEXIO_COMMON_TYPES_AR_RELEASE_REVISION_VERSION     1
#define FLEXIO_COMMON_TYPES_SW_MAJOR_VERSION                1
#define FLEXIO_COMMON_TYPES_SW_MINOR_VERSION                0
#define FLEXIO_COMMON_TYPES_SW_PATCH_VERSION                1
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef MCL_ENABLE_FLEXIO
#if (MCL_ENABLE_FLEXIO == STD_ON)

#define FLEXIO_CTRL_DOZEN_EN_U32            ((uint32)(0x00000000UL))

#define FLEXIO_CTRL_DOZEN_DIS_U32           ((uint32)(0x80000000UL))

#define FLEXIO_CTRL_DBGE_EN_U32             ((uint32)(0x40000000UL))

#define FLEXIO_CTRL_DBGE_DIS_U32            ((uint32)(0x00000000UL))

#define FLEXIO_CTRL_SWRST_EN_U32            ((uint32)(0x00000002UL))

#define FLEXIO_CTRL_SWRST_DIS_U32           ((uint32)(0x00000000UL))

#define FLEXIO_CTRL_FLEXEN_EN_U32           ((uint32)(0x00000001UL))

#define FLEXIO_CTRL_FLEXEN_DIS_U32          ((uint32)(0x00000000UL))

#define FLEXIO_ENABLE_SEL_U8                ((uint8)(0x01UL))

#define FLEXIO_DISABLE_SEL_U8               ((uint8)(0x00UL))

#define FLEXIO_SHIFTER_NONE_U8              ((uint8)(0x00U))
#define FLEXIO_SHIFTER_0_U8                 ((uint8)(0x01U))
#define FLEXIO_SHIFTER_1_U8                 ((uint8)(0x02U))
#define FLEXIO_SHIFTER_2_U8                 ((uint8)(0x04U))
#define FLEXIO_SHIFTER_3_U8                 ((uint8)(0x08U))
#define FLEXIO_SHIFTER_4_U8                 ((uint8)(0x10U))
#define FLEXIO_SHIFTER_5_U8                 ((uint8)(0x20U))
#define FLEXIO_SHIFTER_6_U8                 ((uint8)(0x40U))
#define FLEXIO_SHIFTER_7_U8                 ((uint8)(0x80U))

#define FLEXIO_TIMER_NONE_U8                ((uint8)(0x00U))
#define FLEXIO_TIMER_0_U8                   ((uint8)(0x01U))
#define FLEXIO_TIMER_1_U8                   ((uint8)(0x02U))
#define FLEXIO_TIMER_2_U8                   ((uint8)(0x04U))
#define FLEXIO_TIMER_3_U8                   ((uint8)(0x08U))
#define FLEXIO_TIMER_4_U8                   ((uint8)(0x10U))
#define FLEXIO_TIMER_5_U8                   ((uint8)(0x20U))
#define FLEXIO_TIMER_6_U8                   ((uint8)(0x40U))
#define FLEXIO_TIMER_7_U8                   ((uint8)(0x80U))


/*==================================================================================================
*                                            ENUMS
==================================================================================================*/
typedef enum
{
    FLEXIO_MCL_INITIALIZED   = 0U,
    FLEXIO_MCL_UNINITIALIZED = 1U,
} Mcl_FlexIOInitType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef uint8  Mcl_ShifterType;
typedef uint8  Mcl_TimerType;
typedef void  (*Mcl_FlexioNotifyType)(VAR(uint8, AUTOMATIC) ChannelId,VAR(uint8, AUTOMATIC) ShiftersStatus,VAR(uint8, AUTOMATIC) ErrorsStatus,VAR(uint8, AUTOMATIC) TimersStatus);


typedef struct
{
    VAR(uint32, AUTOMATIC)                          u32CtrConfig;
    VAR(uint8, AUTOMATIC)                           u8ChannelNo;
} Mcl_FlexioConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#endif /*(MCL_ENABLE_FLEXIO == STD_ON)*/
#endif
#ifdef __cplusplus
}
#endif

#endif 

/** @} */
