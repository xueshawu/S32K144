/**
*   @file    Gpt_Cfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt -  GPT driver configuration source file..
*   @details GPT driver source file, containing C and XPath constructs for generating Gpt
*            configuration source file for the Precompile configuration variant.
*
*   @addtogroup GPT_MODULE
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
* @section [global]
*     Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*     on the significance of more than 31 characters. The used compilers use more than 31 chars for
*     identifiers.
*
* @section GPT_CFG_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
* and comments before '#include'. This is an Autosar requirement about
* the memory management.
*
* @section GPT_CFG_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. This is an Autosar requirement
* about the memory management.
*
* @section GPT_CFG_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Gpt.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_VENDOR_ID_CFG_C                    43
/** @violates @ref GPT_CFG_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_AR_RELEASE_MAJOR_VERSION_CFG_C     4
/** @violates @ref GPT_CFG_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_AR_RELEASE_MINOR_VERSION_CFG_C     3
/** @violates @ref GPT_CFG_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_AR_RELEASE_REVISION_VERSION_CFG_C  1
#define GPT_SW_MAJOR_VERSION_CFG_C             1
#define GPT_SW_MINOR_VERSION_CFG_C             0
#define GPT_SW_PATCH_VERSION_CFG_C             1
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((GPT_AR_RELEASE_MAJOR_VERSION_CFG_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_AR_RELEASE_MINOR_VERSION_CFG_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Gpt_Cfg.c and Mcal.h are different"
    #endif
#endif

/* Check if Gpt_Cfg.c file and Gpt.h header file are of the same vendor */
#if (GPT_VENDOR_ID_CFG_C != GPT_VENDOR_ID)
    #error "Gpt_Cfg.c and Gpt.h have different vendor ids"
#endif
/* Check if Gpt_Cfg.c file and Gpt.h header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_CFG_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_CFG_C != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_CFG_C != GPT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Cfg.c and Gpt.h are different"
#endif
/* Check if Gpt_Cfg.c file and Gpt.h header file are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION_CFG_C != GPT_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_CFG_C != GPT_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_CFG_C != GPT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Cfg.c and Gpt.h are different"
#endif

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
