/**
*   @file    Mcl_FlexIO_Common.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - FLEXIO driver source file.
*   @details Common FlexIO routines.
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
* @section Mcl_FlexIO_Common_c_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Mcl_FlexIO_Common_c_2  
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
* the contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Mcl_FlexIO_Common_c_3
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integral type.
* This violation is due to the pointer arithmetic used to write/ read
* the data to/from the registers.

* @section Mcl_FlexIO_Common_c_4
* Violates MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between
* a pointer type and an integral type
* This violation is due to the pointer arithmetic used to write/ read
* the data to/from the registers.
*
* @section Mcl_FlexIO_Common_c_5
* Violates MISRA 2004 Required Rule 8.10, could be made static
* The code could not be made static because is intern only for a certain compiler switch definition.
**/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Mcl_FlexIO_Common.c
* 
*/
#include "Std_Types.h"
#include "SchM_Mcl.h"
#include "StdRegMacros.h"
#include "CDD_Mcl_Cfg.h"
#include "Mcl_FlexIO_Common_Types.h"
#include "Mcl_FlexIO_Common.h"
#include "Reg_eSys_FlexIO.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Mcl_FlexIO_Common.c
* @brief          Source file version information  
*/
#define FLEXIO_COMMON_VENDOR_ID_C                       43
#define FLEXIO_COMMON_AR_RELEASE_MAJOR_VERSION_C        4
#define FLEXIO_COMMON_AR_RELEASE_MINOR_VERSION_C        3
#define FLEXIO_COMMON_AR_RELEASE_REVISION_VERSION_C     1
#define FLEXIO_COMMON_SW_MAJOR_VERSION_C                1
#define FLEXIO_COMMON_SW_MINOR_VERSION_C                0
#define FLEXIO_COMMON_SW_PATCH_VERSION_C                1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcl_FlexIO_Common.h header file are of the same vendor */
#if (FLEXIO_COMMON_VENDOR_ID_C != FLEXIO_COMMON_VENDOR_ID)
    #error "Mcl_FlexIO_Common.c and Mcl_FlexIO_Common.h have different vendor ids"
#endif
/* Check if source file and Mcl_FlexIO_Common.h header file are of the same Autosar version */
#if ((FLEXIO_COMMON_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_COMMON_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_COMMON_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_COMMON_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_COMMON_AR_RELEASE_REVISION_VERSION_C != FLEXIO_COMMON_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_FlexIO_Common.h and Mcl_FlexIO_Common.h are different"
#endif
/* Check if source file and Mcl_FlexIO_Common.h header file are of the same software version */
#if ((FLEXIO_COMMON_SW_MAJOR_VERSION_C != FLEXIO_COMMON_SW_MAJOR_VERSION) || \
     (FLEXIO_COMMON_SW_MINOR_VERSION_C != FLEXIO_COMMON_SW_MINOR_VERSION) || \
     (FLEXIO_COMMON_SW_PATCH_VERSION_C != FLEXIO_COMMON_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_FlexIO_Common.h and Mcl_FlexIO_Common.h are different"
#endif

/* Check if source file and Mcl_FlexIO_Common.h header file are of the same vendor */
#if (FLEXIO_COMMON_VENDOR_ID_C != FLEXIO_COMMON_TYPES_VENDOR_ID)
    #error "Mcl_FlexIO_Common.c and Mcl_FlexIO_Common.h have different vendor ids"
#endif
/* Check if source file and Mcl_FlexIO_Common.h header file are of the same Autosar version */
#if ((FLEXIO_COMMON_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_COMMON_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_COMMON_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_COMMON_AR_RELEASE_REVISION_VERSION_C != FLEXIO_COMMON_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_FlexIO_Common.h and Mcl_FlexIO_Common.h are different"
#endif
/* Check if source file and Mcl_FlexIO_Common.h header file are of the same software version */
#if ((FLEXIO_COMMON_SW_MAJOR_VERSION_C != FLEXIO_COMMON_TYPES_SW_MAJOR_VERSION) || \
     (FLEXIO_COMMON_SW_MINOR_VERSION_C != FLEXIO_COMMON_TYPES_SW_MINOR_VERSION) || \
     (FLEXIO_COMMON_SW_PATCH_VERSION_C != FLEXIO_COMMON_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_FlexIO_Common.h and Mcl_FlexIO_Common.h are different"
#endif

/* Check if source file and StdRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FLEXIO_COMMON_AR_RELEASE_MAJOR_VERSION_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_COMMON_AR_RELEASE_MINOR_VERSION_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Mcl_Dma_Irq.cand StdRegMacros.h are different"
    #endif
#endif
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
#define MCL_START_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Mcl_FlexIO_Common_c_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_FlexIO_Common_c_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"

#if (MCL_ENABLE_FLEXIO == STD_ON)
/** @violates @ref Mcl_FlexIO_Common_c_5 MISRA 2004 Required Rule 8.10, could be made static */
VAR(Mcl_FlexIOInitType, MCL_VAR) Mcl_FlexIO_InitStatus;
#endif /* MCL_ENABLE_FLEXIO == STD_ON */

#define MCL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Mcl_FlexIO_Common_c_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_FlexIO_Common_c_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"

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
#ifdef MCL_ENABLE_FLEXIO
#if (MCL_ENABLE_FLEXIO == STD_ON)
#define MCL_START_SEC_CODE
/** @violates @ref Mcl_FlexIO_Common_c_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_FlexIO_Common_c_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"

FUNC (void, MCL_CODE) Mcl_Flexio_Init(VAR(uint32, AUTOMATIC) u32FlexIOConfig)
{
    Mcl_FlexIO_InitStatus = FLEXIO_MCL_INITIALIZED;
    
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_44();
    /* Reset all registers */
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    REG_BIT_SET32(FLEXIO_CTRL_ADDR32,(FLEXIO_CTRL_SWRST_MASK_U32));
    /* Configure  */
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(FLEXIO_CTRL_ADDR32,(u32FlexIOConfig & FLEXIO_CTRL_INIT_BITS_MASK_U32));
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    REG_RMW32(FLEXIO_CTRL_ADDR32, FLEXIO_CTRL_FLEXEN_MASK_U32, FLEXIO_MODULE_ENABLED_U32);
    
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_44();
}
/** @violates @ref Mcl_FlexIO_Common_c_5 MISRA 2004 Required Rule 8.10, could be made static */
FUNC (void, MCL_CODE) Mcl_Flexio_DeInit()
{
    Mcl_FlexIO_InitStatus = FLEXIO_MCL_UNINITIALIZED;
    
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_46();
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    REG_BIT_SET32(FLEXIO_CTRL_ADDR32,(FLEXIO_CTRL_SWRST_MASK_U32));
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(FLEXIO_CTRL_ADDR32, (uint32)0x0);
    
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_46();
}

FUNC (void, MCL_CODE) Mcl_Flexio_ModuleEnable(void)
{
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_35();
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    REG_RMW32(FLEXIO_CTRL_ADDR32, FLEXIO_CTRL_FLEXEN_MASK_U32, FLEXIO_MODULE_ENABLED_U32);
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_35();
}

FUNC (void, MCL_CODE) Mcl_Flexio_ModuleDisable(void)
{
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_36();
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    REG_RMW32(FLEXIO_CTRL_ADDR32, FLEXIO_CTRL_FLEXEN_MASK_U32, FLEXIO_MODULE_DISABLED_U32);
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_36();
}

FUNC (void, MCL_CODE) Mcl_Flexio_ClrShiftStat(VAR(uint8, AUTOMATIC) u8mask)
{
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_37();
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    FLEXIO_SHIFTSTAT_CLEAR(u8mask);
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_37();
}

FUNC (uint8, MCL_CODE) Mcl_Flexio_RdShiftStat(VAR(uint8, AUTOMATIC) u8mask)
{
    VAR(uint8, AUTOMATIC) u8StatValue;
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    u8StatValue = FLEXIO_SHIFTSTAT_READ(u8mask);
    
   return u8StatValue;
}

FUNC (void, MCL_CODE) Mcl_Flexio_ClrShiftErr(VAR(uint8, AUTOMATIC) u8mask)
{
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_38();
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    FLEXIO_SHIFTERR_CLEAR(u8mask);
    
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_38();
}

FUNC (uint8, MCL_CODE) Mcl_Flexio_RdShiftErr(VAR(uint8, AUTOMATIC) u8mask)
{
    VAR(uint8, AUTOMATIC) u8ShiftErrValue;
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    u8ShiftErrValue = FLEXIO_SHIFTERR_READ (u8mask);
    return u8ShiftErrValue;
}

FUNC (void, MCL_CODE) Mcl_Flexio_ClrTimStat(VAR(uint8, AUTOMATIC) u8mask)
{
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_39();
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    FLEXIO_TIMSTAT_CLEAR(u8mask);
    
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_39();
}

FUNC (uint8, MCL_CODE) Mcl_Flexio_RdTimStat(VAR(uint8, AUTOMATIC) u8mask)
{
    VAR(uint8, AUTOMATIC) u8StartValue;
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    u8StartValue = FLEXIO_TIMSTAT_READ(u8mask);
    return u8StartValue;
}

FUNC (void, MCL_CODE) Mcl_Flexio_WrShiftSien(VAR(uint8, AUTOMATIC) u8ShifterMask, VAR(uint8, AUTOMATIC) u8ShifterEnableMask)
{
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_40();
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    FLEXIO_SHIFTSIEN_SET((uint32)u8ShifterMask, (uint32)u8ShifterEnableMask);
    
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_40();
}

FUNC (uint8, MCL_CODE) Mcl_Flexio_RdShiftSien(VAR(uint8, AUTOMATIC) u8ShifterMask)
{
    VAR(uint8, AUTOMATIC) u8ShifterValue;
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    u8ShifterValue = FLEXIO_SHIFTSIEN_READ(u8ShifterMask);
    return u8ShifterValue;
}

FUNC (void, MCL_CODE) Mcl_Flexio_WrShiftEien(VAR(uint8, AUTOMATIC) u8ShifterMask, VAR(uint8, AUTOMATIC) u8ShifterEnableMask)
{
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_41();
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    FLEXIO_SHIFTEIEN_SET((uint32)u8ShifterMask, (uint32)u8ShifterEnableMask);
    
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_41();
}

FUNC (uint8, MCL_CODE) Mcl_Flexio_RdShiftEien(VAR(uint8, AUTOMATIC) u8ShifterMask)
{
    VAR(uint8, AUTOMATIC) u8ShifterValue;
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    u8ShifterValue = FLEXIO_SHIFTEIEN_READ(u8ShifterMask);
    return u8ShifterValue;
}

FUNC (void, MCL_CODE) Mcl_Flexio_WrTimIen(VAR(uint8, AUTOMATIC) u8TimerMask, VAR(uint8, AUTOMATIC) u8TimerEnableMask)
{
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_42();
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    FLEXIO_TIMIEN_SET((uint32)u8TimerMask, (uint32)u8TimerEnableMask);
    
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_42();
}

FUNC (uint8, MCL_CODE) Mcl_Flexio_RdTimIen(VAR(uint8, AUTOMATIC) u8TimerMask)
{
    VAR(uint8, AUTOMATIC) u8TimerValue;
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    u8TimerValue = FLEXIO_TIMIEN_READ(u8TimerMask);
    return u8TimerValue;
}

FUNC (void, MCL_CODE) Mcl_Flexio_WrShiftSden(VAR(uint8, AUTOMATIC) u8ShifterMask, VAR(uint8, AUTOMATIC) u8ShifterEnableMask)
{
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_43();
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    FLEXIO_SHIFTSDEN_SET((uint32)u8ShifterMask, (uint32)u8ShifterEnableMask);
    
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_43();
}

FUNC (uint8, MCL_CODE) Mcl_Flexio_RdShiftSden(VAR(uint8, AUTOMATIC) u8ShifterMask)
{
    VAR(uint8, AUTOMATIC) u8ShifterValue;
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    u8ShifterValue = FLEXIO_SHIFTSDEN_READ(u8ShifterMask);
    return u8ShifterValue;
}

FUNC (void, MCL_CODE) Mcl_Flexio_SetInterrupts(VAR(uint8, AUTOMATIC) u8ShifterMask, VAR(uint8, AUTOMATIC) u8ErrMask, VAR(uint8, AUTOMATIC) u8TimerMask)
{
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_47();
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    FLEXIO_SHIFTSIEN_SET((uint32)u8ShifterMask, (uint32)u8ShifterMask);
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    FLEXIO_SHIFTEIEN_SET((uint32)u8ErrMask, (uint32)u8ErrMask);
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    FLEXIO_TIMIEN_SET((uint32)u8TimerMask, (uint32)u8TimerMask);
    
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_47();
}

FUNC (void, MCL_CODE) Mcl_Flexio_ClrInterrupts(VAR(uint8, AUTOMATIC) u8ShifterMask, VAR(uint8, AUTOMATIC) u8ErrMask, VAR(uint8, AUTOMATIC) u8TimerMask)
{
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_48();
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    FLEXIO_SHIFTSIEN_SET((uint32)u8ShifterMask, 0U);
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    FLEXIO_SHIFTEIEN_SET((uint32)u8ErrMask, 0U);
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    FLEXIO_TIMIEN_SET((uint32)u8TimerMask, 0U);
    
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_48();
}

FUNC (void, MCL_CODE) Mcl_Flexio_SwReset(void)
{
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_45();
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    REG_BIT_SET32(FLEXIO_CTRL_ADDR32,(FLEXIO_CTRL_SWRST_MASK_U32));
    /*@violates @ref Mcl_FlexIO_Common_c_3 Violates MISRA 2004 Rule 11.1*/
    /* @violates @ref Mcl_FlexIO_Common_c_4 Violates MISRA 2004 Rule 11.3*/
    REG_BIT_CLEAR32(FLEXIO_CTRL_ADDR32,FLEXIO_CTRL_SWRST_MASK_U32);
    
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_45();
}
#define MCL_STOP_SEC_CODE
/** @violates @ref Mcl_FlexIO_Common_c_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_FlexIO_Common_c_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"

#endif /*(MCL_ENABLE_FLEXIO == STD_ON)*/
#endif
#ifdef __cplusplus
}
#endif
/** @} */
