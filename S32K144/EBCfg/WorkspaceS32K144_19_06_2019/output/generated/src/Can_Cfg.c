/**
*   @file    Can_Cfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface
*   @details Configuration Structures for PreCompile.
*
*   @addtogroup CAN_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : FLEXCAN
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
* The used compilers use more than 31 chars for identifiers.
*
* @section Can_Cfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,#include preceded by non preproc directives.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Can_Cfg_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section Can_Cfg_c_REF_5
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
* This macro compute the address of any register by using the hardware ofsset of the controller. The address calculated as an unsigned int
* is passed to  a macro for initializing the pointer with that address. (ex: see REG_WRITE32 macro).
*
* @section Can_Cfg_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can.h"
#include "Can_IPW.h"

/**
* @file           Can_Cfg.c
*/



/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_VENDOR_ID_PCCFG_C                    43
#define CAN_MODULE_ID_PCCFG_C                    80
#define CAN_AR_RELEASE_MAJOR_VERSION_PCCFG_C     4
#define CAN_AR_RELEASE_MINOR_VERSION_PCCFG_C     3
#define CAN_AR_RELEASE_REVISION_VERSION_PCCFG_C  1
#define CAN_SW_MAJOR_VERSION_PCCFG_C             1
#define CAN_SW_MINOR_VERSION_PCCFG_C             0
#define CAN_SW_PATCH_VERSION_PCCFG_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Can.h are of the same vendor */
#if (CAN_VENDOR_ID_PCCFG_C != CAN_VENDOR_ID)
#error "Can.h and Can_Cfg.c have different vendor ids"
#endif
/* Check if current file and Can.h file are of the same module */
#if (CAN_MODULE_ID_PCCFG_C != CAN_MODULE_ID)
#error "Can.h and Can_Cfg.c have different module ids"
#endif
/* Check if current file and Can.h are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_PCCFG_C != CAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_AR_RELEASE_MINOR_VERSION_PCCFG_C != CAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_AR_RELEASE_REVISION_VERSION_PCCFG_C != CAN_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Can_Cfg.c and Can.h are different"
#endif
/* Check if current file and Can.h are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PCCFG_C != CAN_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_PCCFG_C != CAN_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_PCCFG_C != CAN_SW_PATCH_VERSION))
       #error "Software Version Numbers of Can_Cfg.c and Can.h are different"
#endif

/* Check if current file and Can_IPW.h file are of the same vendor */
#if (CAN_VENDOR_ID_PCCFG_C  != CAN_IPW_VENDOR_ID_H)
#error "Can_IPW.h and Can_Cfg.c have different vendor ids"
#endif
/* Check if current file and Can_IPW.h file are of the same module */
#if (CAN_MODULE_ID_PCCFG_C != CAN_IPW_MODULE_ID_H)
#error "Can_IPW.h and Can_Cfg.c have different module ids"
#endif
/* Check if current file and Can_IPW.h file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_PCCFG_C != CAN_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_AR_RELEASE_MINOR_VERSION_PCCFG_C != CAN_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_AR_RELEASE_REVISION_VERSION_PCCFG_C != CAN_IPW_AR_RELEASE_REVISION_VERSION_H))
  #error "AutoSar Version Numbers of Can_Cfg.c and Can_IPW.h are different"
#endif
/* Check if current file and Can_IPW.h file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PCCFG_C != CAN_IPW_SW_MAJOR_VERSION_H) || \
     (CAN_SW_MINOR_VERSION_PCCFG_C != CAN_IPW_SW_MINOR_VERSION_H) || \
     (CAN_SW_PATCH_VERSION_PCCFG_C != CAN_IPW_SW_PATCH_VERSION_H))
       #error "Software Version Numbers of Can_Cfg.c and Can_IPW.h are different"
#endif


/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_Cfg_c_REF_2 MISRA 2004 Rule 19.15, Repeated include file MemMap.h  */
#include "Can_MemMap.h"
/* Check if current file and Can_MemMap.h header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CAN_AR_RELEASE_MAJOR_VERSION_PCCFG_C != CAN_MEMMAP_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_AR_RELEASE_MINOR_VERSION_PCCFG_C != CAN_MEMMAP_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Can_Cfg.c and Can_MemMap.h are different"
    #endif
#endif
/**
* @brief    Prototype of User Notifications
*/

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


/*==================================================================================================*/
/**
* @brief          Configuration of FlexCan controller
* @details        Configuration of FlexCan controller
*
*/
/* Compiler_Warning: this warning due to behavior of compiler depend on configs. */
static CONST(CanStatic_ControllerBaudrateConfigType, CAN_CONST) ControllerBaudrateCfgSet0_PC_0[CAN_CFGSET0_MAX_BAUDRATE_FC_A_0] = 
{
    /* Configuration for CanController ID0 == FlexCAN_A */
    {
        /* ===== Control Register - CTRL ===== */
        (uint32)(
                    /* CTRL[LPB] - Loop-back mode */
                    ((uint32)0<< FLEXCAN_CTRL_LPB_SHIFT_U8) |
                    /* CTRL[SMP] - Sampling mode */
                    ((uint32)0<< FLEXCAN_CTRL_SMP_SHIFT_U8) |
                    /* CTRL[BOFF_REC] - Bus off recovery */
                    ((uint32)0<< FLEXCAN_CTRL_BOFFREC_SHIFT_U8) |
                    /* CTRL[LBUF] - Lowest Buffer Transmitted First */
                    ((uint32)1<< FLEXCAN_CTRL_LBUF_SHIFT_U8) |
                    /* CTRL[LOM] - Listen only mode */
                    ((uint32)0<< FLEXCAN_CTRL_LOM_SHIFT_U8)
                 ) 
        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
        ,0U
        #endif /* CAN_DUAL_CLOCK_MODE == STD_ON */
    }
};


/*==================================================================================================*/
/**
* @brief          Description of individual FlexCan controllers on chip
* @details        Description of individual FlexCan controllers on chip
*
*/
static CONST(CanStatic_ControlerDescriptorType, CAN_CONST) ControlerDescriptors0_PC[CAN_MAXCONTROLLERCOUNT_0] =
{
    /* ControlerDescriptor of CanController_0 */
    {
        /* Can Controller Offset on chip: Can_A=offset 0, Can_B=offset 1, .. -u8ControllerOffset */
        (uint8)FLEXCAN_A_OFFSET,
        
        /* pControllerBaudrateConfigsPtr - pControllerBaudrateConfigsPtr */
        ControllerBaudrateCfgSet0_PC_0,
        
        #if ((CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) && (CPU_BYTE_ORDER==HIGH_BYTE_FIRST))
        /* Pointer to Error INTERRUPT notification function (ESR[ERR_INT]). - Can_ErrorNotification */
        NULL_PTR,
        #elif(CPU_BYTE_ORDER==LOW_BYTE_FIRST) /* (CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) */
        
        /* Pointer to Error INTERRUPT notification function (ESR[ERR_INT]). */
        NULL_PTR,
        #endif
        
        /* Maximum MBs supported for this controller. - u8NumberOfMB */
        (uint8)32U,
        
        /* ===== Controller Options ===== */
        (uint32)(
                    /* BusOff select by INTERRUPT */
                    0U
                 )
    }
};
/*==================================================================================================*/
/**
* @brief          Top level structure containing all Can driver configurations
* @details        Top level structure containing all Can driver configurations
*
*/
/* @violates @ref Can_PBcfg_c_REF_4 Violates MISRA 2004 Required Rule 8.10*/
CONST(CanStatic_ConfigType, CAN_CONST) CanStatic_ConfigSet =
{
    /* Number of CAN controllers configured -u8ControllersConfigured*/
    (uint8) 1U,
    /* FlexCAN controller description - ControlerDescriptors*/
    ControlerDescriptors0_PC,
    /*Maximum Object IDs configured - u32CanMaxObjectId*/
    (uint32)8U
};

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
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

/*
@file  Can_PBcfg.c
@note  Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. - See @ref Can_Cfg_c_REF_1
@note  Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h - See @ref Can_Cfg_c_REF_2
*/
#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_Cfg_c_REF_1 MISRA 2004  Rule 19.1, #include preceded by non preproc directives.*/
/* @violates @ref Can_Cfg_c_REF_2 MISRA 2004 Rule 19.15, Repeated include file MemMap.h  */
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
