/**
*   @file    Mcl_FlexIO_Common.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - FLEXIO driver header file.
*   @details FLEXIO driver interface.
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

#ifndef FLEXIO_COMMON_H
#define FLEXIO_COMMON_H

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
* @section Mcl_FlexIO_Common_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Mcl_FlexIO_Common_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Mcl_FlexIO_Common_h_REF_3
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
#include "Reg_eSys_FlexIO.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Mcl_FlexIO_Common.h  
*/
#define FLEXIO_COMMON_VENDOR_ID                       43
#define FLEXIO_COMMON_AR_RELEASE_MAJOR_VERSION        4
#define FLEXIO_COMMON_AR_RELEASE_MINOR_VERSION        3
#define FLEXIO_COMMON_AR_RELEASE_REVISION_VERSION     1
#define FLEXIO_COMMON_SW_MAJOR_VERSION                1
#define FLEXIO_COMMON_SW_MINOR_VERSION                0
#define FLEXIO_COMMON_SW_PATCH_VERSION                1
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Reg_eSys_FlexIO.h header file are of the same vendor */
#if (FLEXIO_COMMON_VENDOR_ID != REG_ESYS_FLEXIO_VENDOR_ID)
    #error "Mcl_FlexIO_Common.h and Reg_eSys_FlexIO.h have different vendor ids"
#endif
/* Check if header file and Reg_eSys_FlexIO.h header file are of the same Autosar version */
#if ((FLEXIO_COMMON_AR_RELEASE_MAJOR_VERSION    != REG_ESYS_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_COMMON_AR_RELEASE_MINOR_VERSION    != REG_ESYS_FLEXIO_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_COMMON_AR_RELEASE_REVISION_VERSION != REG_ESYS_FLEXIO_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_FlexIO_Common.h and Reg_eSys_FlexIO.h are different"
#endif
/* Check if header file and Reg_eSys_FlexIO.h header file are of the same software version */
#if ((FLEXIO_COMMON_SW_MAJOR_VERSION != REG_ESYS_FLEXIO_SW_MAJOR_VERSION) || \
     (FLEXIO_COMMON_SW_MINOR_VERSION != REG_ESYS_FLEXIO_SW_MINOR_VERSION) || \
     (FLEXIO_COMMON_SW_PATCH_VERSION != REG_ESYS_FLEXIO_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_FlexIO_Common.h and Reg_eSys_FlexIO.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* @violates @ref Mcl_FlexIO_Common_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTSTAT_READ(u8mask)        (((uint8)(REG_READ32(FLEXIO_SHIFTSTAT_ADDR32))) & (u8mask))
/* @violates @ref Mcl_FlexIO_Common_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTSTAT_CLEAR(u8mask)       (REG_WRITE32(FLEXIO_SHIFTSTAT_ADDR32, (u8mask)))
/* @violates @ref Mcl_FlexIO_Common_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTERR_READ(u8mask)         (((uint8)(REG_READ32(FLEXIO_SHIFTERR_ADDR32))) & (u8mask))
/* @violates @ref Mcl_FlexIO_Common_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTERR_CLEAR(u8mask)        (REG_WRITE32(FLEXIO_SHIFTERR_ADDR32, (u8mask)))
/* @violates @ref Mcl_FlexIO_Common_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_TIMSTAT_READ(u8mask)          (((uint8)(REG_READ32(FLEXIO_TIMSTAT_ADDR32))) & (u8mask))
/* @violates @ref Mcl_FlexIO_Common_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_TIMSTAT_CLEAR(u8mask)         (REG_WRITE32(FLEXIO_TIMSTAT_ADDR32, (u8mask)))


/* @violates @ref Mcl_FlexIO_Common_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTSIEN_READ(u8mask)              (((uint8)(REG_READ32(FLEXIO_SHIFTSIEN_ADDR32))) & (u8mask))
/* @violates @ref Mcl_FlexIO_Common_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTSIEN_SET(u8mask,u8enableMask)  (REG_RMW32(FLEXIO_SHIFTSIEN_ADDR32, (u8mask), (u8enableMask)))
/* @violates @ref Mcl_FlexIO_Common_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTEIEN_READ(u8mask)              (((uint8)(REG_READ32(FLEXIO_SHIFTEIEN_ADDR32))) & (u8mask)) 
/* @violates @ref Mcl_FlexIO_Common_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTEIEN_SET(u8mask,u8enableMask)  (REG_RMW32(FLEXIO_SHIFTEIEN_ADDR32, (u8mask), (u8enableMask)))
/* @violates @ref Mcl_FlexIO_Common_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_TIMIEN_READ(u8mask)                 (((uint8)(REG_READ32(FLEXIO_TIMIEN_ADDR32))) & (u8mask))
/* @violates @ref Mcl_FlexIO_Common_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_TIMIEN_SET(u8mask,u8enableMask)     (REG_RMW32(FLEXIO_TIMIEN_ADDR32, (u8mask), (u8enableMask)))
 /* @violates @ref Mcl_FlexIO_Common_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTSDEN_READ(u8mask)              (((uint8)(REG_READ32(FLEXIO_SHIFTSDEN_ADDR32))) & (u8mask))
/* @violates @ref Mcl_FlexIO_Common_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTSDEN_SET(u8mask,u8enableMask)  (REG_RMW32(FLEXIO_SHIFTSDEN_ADDR32, (u8mask), (u8enableMask)))

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define MCL_START_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Mcl_FlexIO_Common_h_REF_2 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_FlexIO_Common_h_REF_3 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"

#if (MCL_ENABLE_FLEXIO == STD_ON)
extern VAR(Mcl_FlexIOInitType, MCL_VAR) Mcl_FlexIO_InitStatus;
#endif /* MCL_ENABLE_FLEXIO == STD_ON */

#define MCL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Mcl_FlexIO_Common_h_REF_2 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_FlexIO_Common_h_REF_3 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#if (MCL_ENABLE_FLEXIO == STD_ON)
#define MCL_START_SEC_CODE
/** @violates @ref Mcl_FlexIO_Common_h_REF_2 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_FlexIO_Common_h_REF_3 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"
FUNC (void, MCL_CODE) Mcl_Flexio_Init(VAR(uint32, AUTOMATIC) u32FlexIOConfig);
FUNC (void, MCL_CODE) Mcl_Flexio_DeInit(void);
FUNC (void, MCL_CODE) Mcl_Flexio_ModuleEnable(void);
FUNC (void, MCL_CODE) Mcl_Flexio_ModuleDisable(void);
FUNC (void, MCL_CODE) Mcl_Flexio_ClrShiftStat(VAR(uint8, AUTOMATIC) u8mask);
FUNC (uint8, MCL_CODE) Mcl_Flexio_RdShiftStat(VAR(uint8, AUTOMATIC) u8mask);
FUNC (void, MCL_CODE) Mcl_Flexio_ClrShiftErr(VAR(uint8, AUTOMATIC) u8mask);
FUNC (uint8, MCL_CODE) Mcl_Flexio_RdShiftErr(VAR(uint8, AUTOMATIC) u8mask);
FUNC (void, MCL_CODE) Mcl_Flexio_ClrTimStat(VAR(uint8, AUTOMATIC) u8mask);
FUNC (uint8, MCL_CODE) Mcl_Flexio_RdTimStat(VAR(uint8, AUTOMATIC) u8mask);
FUNC (void, MCL_CODE) Mcl_Flexio_WrShiftSien(VAR(uint8, AUTOMATIC) u8ShifterMask, VAR(uint8, AUTOMATIC) u8ShifterEnableMask);
FUNC (uint8, MCL_CODE) Mcl_Flexio_RdShiftSien(VAR(uint8, AUTOMATIC) u8ShifterMask);
FUNC (void, MCL_CODE) Mcl_Flexio_WrShiftEien(VAR(uint8, AUTOMATIC) u8ShifterMask, VAR(uint8, AUTOMATIC) u8ShifterEnableMask);
FUNC (uint8, MCL_CODE) Mcl_Flexio_RdShiftEien(VAR(uint8, AUTOMATIC) u8ShifterMask);
FUNC (void, MCL_CODE) Mcl_Flexio_WrTimIen(VAR(uint8, AUTOMATIC) u8TimerMask, VAR(uint8, AUTOMATIC) u8TimerEnableMask);
FUNC (uint8, MCL_CODE) Mcl_Flexio_RdTimIen(VAR(uint8, AUTOMATIC) u8TimerMask);
FUNC (void, MCL_CODE) Mcl_Flexio_WrShiftSden(VAR(uint8, AUTOMATIC) u8ShifterMask, VAR(uint8, AUTOMATIC) u8ShifterEnableMask);
FUNC (uint8, MCL_CODE) Mcl_Flexio_RdShiftSden(VAR(uint8, AUTOMATIC) u8ShifterMask);
FUNC (void, MCL_CODE) Mcl_Flexio_SetInterrupts(VAR(uint8, AUTOMATIC) u8ShifterMask, VAR(uint8, AUTOMATIC) u8ErrMask, VAR(uint8, AUTOMATIC) u8TimerMask);
FUNC (void, MCL_CODE) Mcl_Flexio_ClrInterrupts(VAR(uint8, AUTOMATIC) u8ShifterMask, VAR(uint8, AUTOMATIC) u8ErrMask, VAR(uint8, AUTOMATIC) u8TimerMask);
FUNC (void, MCL_CODE) Mcl_Flexio_SwReset(void);
#define MCL_STOP_SEC_CODE
/** @violates @ref Mcl_FlexIO_Common_h_REF_2 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_FlexIO_Common_h_REF_3 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"
#endif /*(MCL_ENABLE_FLEXIO == STD_ON)*/

#ifdef __cplusplus
}
#endif

#endif /*FLEXIO_COMMON_H*/

/** @} */
