/**
*   @file    Mcem.h
*   
*
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcem - MCEM Module API header.
*   @details Main API definition for the MCEM module
*
*
*   @addtogroup MCEM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : Eim Erm
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

#ifndef MCEM_H
#define MCEM_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 */

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "CDD_Mcem.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCEM_VENDOR_ID                    43
#define MCEM_MODULE_ID                    0U
/* @violates @ref CDD_Mcem_h_REF_2 Exceeds 31 characters */
#define MCEM_AR_RELEASE_MAJOR_VERSION     4
/* @violates @ref CDD_Mcem_h_REF_2 Exceeds 31 characters */
#define MCEM_AR_RELEASE_MINOR_VERSION     3
/* @violates @ref CDD_Mcem_h_REF_2 Exceeds 31 characters */
#define MCEM_AR_RELEASE_REVISION_VERSION  1
#define MCEM_SW_MAJOR_VERSION             1
#define MCEM_SW_MINOR_VERSION             0
#define MCEM_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check for CDD_Mcem.h versions */
/* Check if current file and CDD MCEM header file are of the same vendor */
#if (MCEM_VENDOR_ID != CDD_MCEM_VENDOR_ID)
    #error "Mcem.h and CDD_Mcem.h have different vendor ids"
#endif

/* Check if current file and MCEM configuration header file are of the same Autosar version */
#if ((MCEM_AR_RELEASE_MAJOR_VERSION    != CDD_MCEM_AR_RELEASE_MAJOR_VERSION) || \
     (MCEM_AR_RELEASE_MINOR_VERSION    != CDD_MCEM_AR_RELEASE_MINOR_VERSION) || \
     (MCEM_AR_RELEASE_REVISION_VERSION != CDD_MCEM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcem.h and CDD_Mcem.h are different"
#endif
/* Check if current file and MCEM configuration header file are of the same software version */
#if ((MCEM_SW_MAJOR_VERSION != CDD_MCEM_SW_MAJOR_VERSION) || \
     (MCEM_SW_MINOR_VERSION != CDD_MCEM_SW_MINOR_VERSION) || \
     (MCEM_SW_PATCH_VERSION != CDD_MCEM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcem.h and CDD_Mcem.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCEM_H */

/** @} */
