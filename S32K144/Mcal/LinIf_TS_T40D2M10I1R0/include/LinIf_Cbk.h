/**
*   @file    LinIf_Cbk.h
*   @version 1.0.1
*
*   @brief   AUTOSAR LinIf - AUTOSAR LinIf_Cbk module interface.
*   @details AUTOSAR LinIf_Cbk module interface.
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : 
*   Dependencies         : 
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

#ifndef LINIF_CBK_H
#define LINIF_CBK_H

#ifdef __cplusplus
extern "C"
{
#endif

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
* @file           LinIf_Cbk.h
* @requirements   LINIF_CBK383
*/
#define LINIF_CBK_VENDOR_ID                      43
#define LINIF_CBK_MODULE_ID                      62
#define LINIF_CBK_AR_RELEASE_MAJOR_VERSION       4
#define LINIF_CBK_AR_RELEASE_MINOR_VERSION       3
#define LINIF_CBK_AR_RELEASE_REVISION_VERSION    1
#define LINIF_CBK_SW_MAJOR_VERSION               1
#define LINIF_CBK_SW_MINOR_VERSION               0
#define LINIF_CBK_SW_PATCH_VERSION               1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/           

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
FUNC(void, LINIF_CODE) LinIf_WakeupConfirmation(VAR(EcuM_WakeupSourceType, LINIF_VAR) WakeupSource);

#ifdef __cplusplus
}
#endif

#endif /* LINIF_CBK_H */

/** @} */
