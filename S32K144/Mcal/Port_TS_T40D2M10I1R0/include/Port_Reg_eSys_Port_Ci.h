/**
*   @file Port_Reg_eSys_Port_Ci.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Port - PORT low level driver register defines.
*   @details The description of the registers of the PORT module.
*
*   @addtogroup PORT
*   @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : PORT_CI
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
=================================================================================================*/
/*=================================================================================================
==================================================================================================*/

#ifndef PORT_REG_ESYS_PORT_CI_H
#define PORT_REG_ESYS_PORT_CI_H
#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Port_Reg_eSys_Port_Ci_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Port_Reg_eSys_Port_Ci_H_REF_2
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers(internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars
* for identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define PORT_REGESYS_PORT_CI_VENDOR_ID                    43
/* @violates @ref Port_Reg_eSys_Port_Ci_H_REF_2 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_REGESYS_PORT_CI_AR_RELEASE_MAJOR_VERSION     4
/* @violates @ref Port_Reg_eSys_Port_Ci_H_REF_2 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_REGESYS_PORT_CI_AR_RELEASE_MINOR_VERSION     3
/* @violates @ref Port_Reg_eSys_Port_Ci_H_REF_2 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_REGESYS_PORT_CI_AR_RELEASE_REVISION_VERSION  1
#define PORT_REGESYS_PORT_CI_SW_MAJOR_VERSION             1
#define PORT_REGESYS_PORT_CI_SW_MINOR_VERSION             0
#define PORT_REGESYS_PORT_CI_SW_PATCH_VERSION             1

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/* Reg_eSys.h version check start */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PORT_REGESYS_PORT_CI_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (PORT_REGESYS_PORT_CI_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Port_Reg_eSys_Port_Ci.h and Reg_eSys.h are different"
    #endif
#endif
/* Reg_eSys.h version check end */

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/
#define PORT_CI_CHANNEL_MASK_U8                    ((uint8)0x1F)      
#define PORT_CI_PORTID_SHIFT_U8                    ((uint8)5UL)
/* Offset between the same registers of two consecutive ports */
#define PORT_CI_REGISTERS_OFFSET_U32               ((uint32)(0x1000))
/* Offset of DFER register related to the start address of a port */
#define PORT_CI_DFER_OFFSET_U32                    ((uint32)(0xC0))
/* Offset of DFCR register related to the start address of a port */
#define PORT_CI_DFCR_OFFSET_U32                    ((uint32)(0xC4))
/* Offset of DFWR register related to the start address of a port */
#define PORT_CI_DFWR_OFFSET_U32                    ((uint32)(0xC8))

/*=================================================================================================
*                                       DEFINES AND MACROS
=================================================================================================*/
/* Compute Port for a given channel as being Port/32, because there are 32 pins in a port */
/* @violates @ref Port_Reg_eSys_Port_Ci_H_REF_1 Function-like macro defined */
#define PORT_CI_PORT_U32(channel)              ((uint32)((uint32)(channel)>>PORT_CI_PORTID_SHIFT_U8))

/* Compute Port channel for a given channel as being Port%32, because there are 32 pins in a port */
/* @violates @ref Port_Reg_eSys_Port_Ci_H_REF_1 Function-like macro defined */
#define PORT_CI_CHANNEL_U32(channel)           ((uint32)((uint32)(channel)&PORT_CI_CHANNEL_MASK_U8))

/*
* @brief Pin Control Register address for a specific pin.
* @violates @ref Port_Reg_eSys_Port_Ci_H_REF_1 Function-like macro defined.
*/
#define PORT_PORT_CI_PCR_ADDR32(PIN)            ((uint32)PORT_BASEADDR + ((uint32)(PORT_CI_PORT_U32(PIN)) * (uint32)PORT_CI_REGISTERS_OFFSET_U32) + ((uint32)PORT_CI_CHANNEL_U32(PIN)<<2))

/* @brief Pad Configuration Register bits and masks */
#define PORT_CI_PCR_ALT_MODE_U32                (0x00000700UL)

/* @brief PCR bit offset */
#define PORT_CI_PCR_ALT_MODE_OFFSET_U32         ((uint32)8)

/* @brief Mode bit offset mask */
#define PORT_CI_BIT_OFFSET_MASK_U8              ((uint8)0x0F)

/*
* @brief Digital Filter Enable Register address for a specific port.
* @violates @ref Port_Reg_eSys_Port_Ci_H_REF_1 Function-like macro defined.
*/
#define PORT_PORT_CI_DFER_ADDR32(port)          ((uint32)PORT_BASEADDR + ((uint32)(port) * (uint32)PORT_CI_REGISTERS_OFFSET_U32) + (uint32)PORT_CI_DFER_OFFSET_U32)

/*
* @brief Digital Filter Clock Register address for a specific port.
* @violates @ref Port_Reg_eSys_Port_Ci_H_REF_1 Function-like macro defined.
*/
#define PORT_PORT_CI_DFCR_ADDR32(port)          ((uint32)PORT_BASEADDR + ((uint32)(port) * (uint32)PORT_CI_REGISTERS_OFFSET_U32) + (uint32)PORT_CI_DFCR_OFFSET_U32)

/*
* @brief Digital Filter Width Register address for a specific port.
* @violates @ref Port_Reg_eSys_Port_Ci_H_REF_1 Function-like macro defined.
*/
#define PORT_PORT_CI_DFWR_ADDR32(port)          ((uint32)PORT_BASEADDR + ((uint32)(port) * (uint32)PORT_CI_REGISTERS_OFFSET_U32) + (uint32)PORT_CI_DFWR_OFFSET_U32)


/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/


/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/


/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#ifdef __cplusplus
}
#endif
/* PORT_REG_ESYS_PORT_H */
#endif
/** @} */
