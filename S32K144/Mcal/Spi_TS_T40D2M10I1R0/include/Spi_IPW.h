/**
*   @file    Spi_IPW.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - Spi middle level driver header file.
*   @details This file is the header containing all the necessary information for SPI
*            LLD.
*   @addtogroup [SPI_MODULE]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : LPSPI,FLEXIO
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

#ifndef SPI_IPW_H
#define SPI_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters.
*
* @section Spi_IPW_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7,
* A function should be used in preference to a function-like macro.
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Spi_IPW_h_REF_2
* Violates MISRA 2004 Required Rule 19.4,
* C macros shall only expand to a braced initialiser, a constant, a string literal, a parenthesised expression,
* a type qualifier, a storage class specifier, or a do-while-zero construct.
*
* @section Spi_IPW_h_REF_3
* Violates MISRA 2004 Required Rule 8.8,
* Precautions shall be taken in order to prevent the redeclaration of external objects.
* An external object shall be declared in only one file.
*
* @section Spi_IPW_h_REF_4
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character signifiance and case sensitivity are
* supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#if (SPI_ENABLE_FLEXIO == STD_ON)
#include "Spi_FlexIO.h"
#endif
#include "Spi_LPspi.h"
#include "Spi_Cfg.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IPW_VENDOR_ID                       43
/*
* @violates @ref Spi_IPW_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_IPW_AR_RELEASE_MAJOR_VERSION        4
/*
* @violates @ref Spi_IPW_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_IPW_AR_RELEASE_MINOR_VERSION        3
/*
* @violates @ref Spi_IPW_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_IPW_AR_RELEASE_REVISION_VERSION     1
#define SPI_IPW_SW_MAJOR_VERSION                1
#define SPI_IPW_SW_MINOR_VERSION                0
#define SPI_IPW_SW_PATCH_VERSION                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Spi_Cfg.h are of the same vendor */
#if (SPI_IPW_VENDOR_ID != SPI_VENDOR_ID_LPSPI)
    #error "Spi_IPW.h and Spi_LPspi.h have different vendor ids"
#endif

#if (( SPI_IPW_AR_RELEASE_MAJOR_VERSION    != SPI_AR_RELEASE_MAJOR_VERSION_LPSPI) || \
     ( SPI_IPW_AR_RELEASE_MINOR_VERSION    != SPI_AR_RELEASE_MINOR_VERSION_LPSPI) || \
     ( SPI_IPW_AR_RELEASE_REVISION_VERSION != SPI_AR_RELEASE_REVISION_VERSION_LPSPI))
#error "AutoSar Version Numbers of Spi_LPspi.h and Spi_IPW.h are different"
#endif

#if (( SPI_IPW_SW_MAJOR_VERSION != SPI_SW_MAJOR_VERSION_LPSPI) || \
     ( SPI_IPW_SW_MINOR_VERSION != SPI_SW_MINOR_VERSION_LPSPI) || \
     ( SPI_IPW_SW_PATCH_VERSION != SPI_SW_PATCH_VERSION_LPSPI))
#error "Software Version Numbers of Spi_IPW.h and Spi_LPspi.h are different"
#endif

#if (SPI_ENABLE_FLEXIO == STD_ON)
/* Check if this header file and Spi_Cfg.h are of the same vendor */
#if (SPI_IPW_VENDOR_ID != SPI_FLEXIO_VENDOR_ID)
    #error "Spi_IPW.h and Spi_FlexIO.h have different vendor ids"
#endif

#if (( SPI_IPW_AR_RELEASE_MAJOR_VERSION    != SPI_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
     ( SPI_IPW_AR_RELEASE_MINOR_VERSION    != SPI_FLEXIO_AR_RELEASE_MINOR_VERSION) || \
     ( SPI_IPW_AR_RELEASE_REVISION_VERSION != SPI_FLEXIO_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_FlexIO.h and Spi_IPW.h are different"
#endif

#if (( SPI_IPW_SW_MAJOR_VERSION != SPI_FLEXIO_SW_MAJOR_VERSION) || \
     ( SPI_IPW_SW_MINOR_VERSION != SPI_FLEXIO_SW_MINOR_VERSION) || \
     ( SPI_IPW_SW_PATCH_VERSION != SPI_FLEXIO_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_IPW.h and Spi_FlexIO.h are different"
#endif
#endif

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
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
FUNC(void, SPI_CODE) Spi_Ipw_Init(VAR(Spi_HWUnitType, AUTOMATIC) HWUnit, P2VAR(Spi_StatusType, AUTOMATIC, SPI_APPL_DATA) pStatus);
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
FUNC(void, SPI_CODE) Spi_Ipw_DeInit(VAR(Spi_HWUnitType, AUTOMATIC) HWUnit);

#if (((SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0)) && \
    (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON))
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
FUNC(void, SPI_CODE) Spi_Ipw_PrepareCacheInformation(void);
#endif  /* #if (((SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0)) && \
    (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON))*/

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_Ipw_SyncTransmit(VAR(Spi_SequenceType, AUTOMATIC) Sequence);
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) ) */

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
FUNC(void, SPI_CODE) Spi_Ipw_JobTransfer(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
FUNC(void, SPI_CODE) Spi_Ipw_IrqConfig(VAR(Spi_HWUnitType, AUTOMATIC) HWUnit, VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
FUNC(void, SPI_CODE) Spi_Ipw_IrqPoll(VAR(Spi_HWUnitType, AUTOMATIC) HWUnit);
#endif

#if ((SPI_CANCEL_API == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON))
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
FUNC(void, SPI_CODE) Spi_Ipw_SlaveCancel(VAR(Spi_SequenceType, AUTOMATIC) Sequence);
#endif /* #if ((SPI_CANCEL_API == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON)) */
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
FUNC(void, SPI_CODE) SPI_IPW_SET_CLOCK_MODE(VAR(Spi_DualClockModeType,AUTOMATIC) ClockMode);
#endif /* #if (SPI_DUAL_CLOCK_MODE == STD_ON) */

#ifdef __cplusplus
}
#endif

#endif /*SPI_IPW_H*/

/** @} */
