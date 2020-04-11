/**
*   @file    Ftm_Common.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - Ftm driver header file.
*   @details Ftm driver interface.
*
*   @addtogroup FTM_MODULE
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

#ifndef FTM_COMMON_H
#define FTM_COMMON_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
* @section Ftm_Common_h_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Ftm_Common_h_2  
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
* the contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include   "CDD_Mcl_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Ftm_Common.h  
*/
#define FTM_COMMON_VENDOR_ID                       43
#define FTM_COMMON_AR_RELEASE_MAJOR_VERSION        4
#define FTM_COMMON_AR_RELEASE_MINOR_VERSION        3
#define FTM_COMMON_AR_RELEASE_REVISION_VERSION     1
#define FTM_COMMON_SW_MAJOR_VERSION                1
#define FTM_COMMON_SW_MINOR_VERSION                0
#define FTM_COMMON_SW_PATCH_VERSION                1
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define MCL_START_SEC_CODE
/** @violates @ref Ftm_Common_h_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Ftm_Common_h_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"

#if (MCL_SELECT_COMMON_TIMEBASE_API == STD_ON)
FUNC(void, MCL_CODE) Mcl_Ftm_SelectCommonTimebase
(
    VAR (uint8, AUTOMATIC) u8FtmModule,
    VAR (uint16, AUTOMATIC) u16ElementSyncList
);
#endif /* MCL_SELECT_COMMON_TIMEBASE_API */

#define MCL_STOP_SEC_CODE
/** @violates @ref Ftm_Common_h_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Ftm_Common_h_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* FTM_COMMON_H*/

/** @} */

