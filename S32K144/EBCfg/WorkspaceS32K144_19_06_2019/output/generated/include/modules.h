/**
*   @file    modules.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - Project configuration.
*   @details Header file describing all Autosar MCAL modules present in the current project.
*
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : S32K14X
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
/**
* @file        modules.h
*/
/** 
* @page misra_violations MISRA-C:2004 violations
*
* @section modules_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars for
*          identifiers.
*/

#ifndef MODULES_H
#define MODULES_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** 
* @file        modules.h
* @brief Include Standard types & defines
*/
/* @violates @ref modules_h_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
#include "Std_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/** 
@{
* @brief Parameters that shall be published within the modules header file.
*       The integration of incompatible files shall be avoided.
*/
#define MODULES_VENDOR_ID                       43
#define MODULES_MODULE_ID                       0
#define MODULES_AR_RELEASE_MAJOR_VERSION_H      4
#define MODULES_AR_RELEASE_MINOR_VERSION_H      3
#define MODULES_AR_RELEASE_REVISION_VERSION_H   1
#define MODULES_SW_MAJOR_VERSION_H              1
#define MODULES_SW_MINOR_VERSION_H              0
#define MODULES_SW_PATCH_VERSION_H              1
/**@}*/
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h header file are of the same Autosar version */
    #if ((MODULES_AR_RELEASE_MAJOR_VERSION_H != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MODULES_AR_RELEASE_MINOR_VERSION_H != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of modules.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** 
* @brief This constant used for other modules to check if ADC is present in the project.  
*/
#define USE_ADC_MODULE              (STD_ON)

/** 
* @brief This constant used for other modules to check if CAN is present in the project.  
*/
#define USE_CAN_MODULE              (STD_ON)

/** 
* @brief This constant used for other modules to check if CRCU is present in the project.  
*/
#define USE_CRCU_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if CSEC is present in the project.  
*/
#define USE_CSEC_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if DIO is present in the project.  
*/
#define USE_DIO_MODULE              (STD_ON)

/** 
* @brief This constant used for other modules to check if ETH is present in the project.
*/
#define USE_ETH_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if EEP is present in the project.
*/
#define USE_EEP_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if FEE is present in the project.  
*/
#define USE_FEE_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if FLS is present in the project.  
*/
#define USE_FLS_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if Fr is present in the project.  
*/
#define USE_FR_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if GPT is present in the project.  
*/
#define USE_GPT_MODULE              (STD_ON)

/** 
* @brief This constant used for other modules to check if ICU is present in the project.  
*/
#define USE_ICU_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if I2C is present in the project.  
*/
#define USE_I2C_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if LIN is present in the project.  
*/
#define USE_LIN_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if MCEM is present in the project.  
*/
#define USE_MCEM_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if MCEM is present in the project.  
*/
#define USE_MCL_MODULE              (STD_ON)

/** 
* @brief This constant used for other modules to check if MCU is present in the project.  
*/
#define USE_MCU_MODULE              (STD_ON)

/** 
* @brief This constant used for other modules to check if OCU is present in the project.
*/
#define USE_OCU_MODULE             (STD_OFF)

/**
* @brief This constant used for other modules to check if PORT is present in the project.  
*/
#define USE_PORT_MODULE             (STD_ON)

/** 
* @brief This constant used for other modules to check if PWM is present in the project.  
*/
#define USE_PWM_MODULE              (STD_ON)

/** 
* @brief This constant used for other modules to check if SPI is present in the project.  
*/
#define USE_SPI_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if WDG is present in the project.  
*/
#define USE_WDG_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if ISELED is present in the project.  
*/
#define USE_ISELED_MODULE              (STD_OFF)


#define MODULE_ID_OS       (1) // Os

#define MODULE_ID_ECUM    (10) // ECU state manager
#define MODULE_ID_FIM     (11) // Function Inhibition Manager
#define MODULE_ID_COMM    (12) // Communication manager
#define MODULE_ID_WDGM    (13) // Watchdog manager

#define MODULE_ID_DET     (15) // Development Error Tracer

#define MODULE_ID_NVM     (20) // NVRAM Manager
#define MODULE_ID_FEE     (21) // Flash EEPROM Emulation
#define MODULE_ID_MEMIF   (22) // Memory Abstraction Interface
#define MODULE_ID_NM      (29) // Generic networw management

#define MODULE_ID_CANNM   (31) // Can network management
#define MODULE_ID_FRNM    (32) // Flexray network management
#define MODULE_ID_CANTP   (35) // Can transport layer
#define MODULE_ID_FRTP    (36) // Flexray transport protocol
#define MODULE_ID_J1939TP (37) // J1939 Transport protocol (Autosar 4)
#define MODULE_ID_EA      (40) // EEPROM Abstraction

#define MODULE_ID_WDGIF   (43) // Watchdog interface

#define MODULE_ID_COM     (50) // Autosar COM
#define MODULE_ID_PDUR    (51) // PDU router
#define MODULE_ID_IPDUM   (52) // IPDU Multiplexer
#define MODULE_ID_DCM     (53) // Diagnostic Communication Manager
#define MODULE_ID_DEM     (54) // Diagnostic Event Manager
#define MODULE_ID_SOAD    (56) // Socket Adaptor

#define MODULE_ID_CANIF   (60) // CAN Interface
#define MODULE_ID_FRIF    (61) // Flexray interface
#define MODULE_ID_LINIF   (62) // LIN interface
#define MODULE_ID_LINNM   (63) // LIN network management

#define MODULE_ID_CANTRCV (70) // Can tranceiver driver
#define MODULE_ID_FRTRCV  (71) // Flexray tranceiver driver

#define MODULE_ID_CAN     (80) // Can Driver
#define MODULE_ID_FR      (81) // Flexray driver
#define MODULE_ID_LIN     (82) // LIN Driver
#define MODULE_ID_SPI     (83) // SPI Handler Driver

#define MODULE_ID_EEP     (90) // EEPROM Driver
#define MODULE_ID_FLS     (92) // Flash driver
#define MODULE_ID_RAMTST  (93) // RAM test

#define MODULE_ID_GPT    (100) // GPT driver
#define MODULE_ID_MCU    (101) // MCU driver
#define MODULE_ID_WDG    (102) // Watchdog driver

#define MODULE_ID_DIO    (120) // Dio driver
#define MODULE_ID_PWM    (121) // PWM driver
#define MODULE_ID_ICU    (122) // ICU Driver
#define MODULE_ID_ADC    (123) // ADC driver
#define MODULE_ID_PORT   (124) // Port driver

#define MODULE_ID_SCHM   (130) // BSW Scheduler Module

#define MODULE_ID_CANSM  (140) // Can state manager
#define MODULE_ID_LINSM  (141) // LIN state manager
#define MODULE_ID_FRSM   (142) // Flexray state manager

#define MODULE_ID_CRC    (201) // CRC Routines

#define MODULE_ID_CANXCP (210u) // Can specific XCP module

#define MODULE_ID_C2CAN  (220) // CAN
#define MODULE_ID_C2COM  (221) // COM Services
#define MODULE_ID_C2DIAG (222) // Diagnostic
#define MODULE_ID_C2FW   (223) // ECU Firmware
#define MODULE_ID_C2FR   (224) // FlexRay
#define MODULE_ID_C2LIN  (225) // LIN
#define MODULE_ID_C2MMGT (226) // Mode Management

#define MODULE_ID_IO     (254) // IO Hardware Abstraction
#define MODULE_ID_CPLX   (255) // Complex drivers

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MODULES_H */

/** @} */


