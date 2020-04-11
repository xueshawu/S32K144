/**
*   @file    Spi_FlexIO.c
*   @implements Spi_FlexIO.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - FlexIO low-level driver implementations.
*   @details FlexIO low-level driver implementations.
*
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

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, Names of new objects shall be checked in order to
* not cause confusion with standard object names.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters.
*
* @section Spi_FlexIO_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Spi_FlexIO_c_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_FlexIO_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type other than an integral type.
*
* @section Spi_FlexIO_c_REF_4
* Violates MISRA 2004 Advisory Rule 11.4,
* A cast should not be performed between a pointer to object type and a different pointer to object type.
* Casts between (uint8*) and (uint32*) are used for optimizing the memory accesses.
*
* @section Spi_FlexIO_c_REF_5
* Violates MISRA 2004 Required Rule 8.10,
* All declarations and definitions of objects or functions at file scope shall have
* internal linkage unless external linkage is required.
* Structure shall be public as it is used by Reg_eSys_FlexIO.h which may be sed outside FlexIO module.
*
* @section Spi_FlexIO_c_REF_6
* Violates MISRA 2004 Required Rule 17.4,
* Array indexing shall be the only allowed form of pointer arithmetic.
* Gain in generated code speed
*
* @section Spi_FlexIO_c_REF_8
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are
* supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Spi_FlexIO_c_REF_11
* Violates MISRA 2004 Required Rule 8.7,
* Objects shall be defined at block scope if they are only accessed from within a single function.
* The variables are defined globally for performance reasons.
*
* @section Spi_FlexIO_c_REF_12
* Violates MISRA 2004 Advisory Rule 11.3,
* A cast should not be performed between a pointer type and an integral type.
*
* @section Spi_FlexIO_c_REF_13
* Violates MISRA 2004 Required Rule 10.1 , The value of an expression of integer type shall not be implicitly
* converted to a different underlying type if: 
*    a) it is not aconversion to a wider integer type of the same signedness, 
*    b) the expression is complex,
*    c) the expression is not constant and is a function argument,
*    d) the expression is not constant and is a return expression.
*
* @section Spi_FlexIO_c_REF_14
* Violates MISRA 2004 Required Rule 11.5, A cast shall not be performed that removes any const or volatile
* qualification from the type addressed by a pointer.
*
* @section Spi_FlexIO_c_REF_15 
* Violates MISRA 2004 Advisory Rule 16.7, A pointer parameter in a function prototype should be declared
* as pointer to const if the pointer is not used to modify the addressed object.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Spi.h"
#include "Spi_IPW.h"
#include "Spi_FlexIO.h"
#include "StdRegMacros.h"
#include "Reg_eSys_FlexIOSPI.h"
#if (SPI_ENABLE_FLEXIO == STD_ON)
#include "Reg_eSys_FlexIO.h"
#include "CDD_Mcl.h"
#endif

#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/*
* @violates @ref Spi_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Dem.h"
#endif

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_FLEXIO_VENDOR_ID_C                        43
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/

#define SPI_FLEXIO_AR_RELEASE_MAJOR_VERSION_C         4
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers.
*/
#define SPI_FLEXIO_AR_RELEASE_MINOR_VERSION_C         3
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers.
*/
#define SPI_FLEXIO_AR_RELEASE_REVISION_VERSION_C      1

#define SPI_FLEXIO_SW_MAJOR_VERSION_C                 1
#define SPI_FLEXIO_SW_MINOR_VERSION_C                 0
#define SPI_FLEXIO_SW_PATCH_VERSION_C                 1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Spi.h are of the same vendor */
#if (SPI_FLEXIO_VENDOR_ID_C != SPI_VENDOR_ID)
    #error "Spi.h and Spi_FlexIO.c have different vendor ids"
#endif
/* Check if Spi_FlexIO.c file and Spi.h file are of the same Autosar version */
#if ((SPI_FLEXIO_AR_RELEASE_MAJOR_VERSION_C    != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_FLEXIO_AR_RELEASE_MINOR_VERSION_C    != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_FLEXIO_AR_RELEASE_REVISION_VERSION_C != SPI_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_FlexIO.c and Spi.h are different"
#endif
#if ((SPI_FLEXIO_SW_MAJOR_VERSION_C  != SPI_SW_MAJOR_VERSION) || \
     (SPI_FLEXIO_SW_MINOR_VERSION_C  != SPI_SW_MINOR_VERSION) || \
     (SPI_FLEXIO_SW_PATCH_VERSION_C  != SPI_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_FlexIO.c and Spi.h are different"
#endif

/* Check if this header file and Spi_Cfg.h are of the same vendor */
#if (SPI_FLEXIO_VENDOR_ID_C != SPI_FLEXIO_VENDOR_ID)
    #error "Spi_FlexIO.c and Spi_FlexIO.h have different vendor ids"
#endif
/* Check if Spi_FlexIO.c file and Spi_FlexIO.h file are of the same Autosar version */
#if ((SPI_FLEXIO_AR_RELEASE_MAJOR_VERSION_C    != SPI_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_FLEXIO_AR_RELEASE_MINOR_VERSION_C    != SPI_FLEXIO_AR_RELEASE_MINOR_VERSION) || \
     (SPI_FLEXIO_AR_RELEASE_REVISION_VERSION_C != SPI_FLEXIO_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_FlexIO.c and Spi_FlexIO.h are different"
#endif
#if ((SPI_FLEXIO_SW_MAJOR_VERSION_C  != SPI_FLEXIO_SW_MAJOR_VERSION) || \
     (SPI_FLEXIO_SW_MINOR_VERSION_C  != SPI_FLEXIO_SW_MINOR_VERSION) || \
     (SPI_FLEXIO_SW_PATCH_VERSION_C  != SPI_FLEXIO_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_FlexIO.c and Spi_FlexIO.h are different"
#endif

/* Check if this header file and Reg_eSys_FLEXIOSPI.h are of the same vendor */
#if (SPI_FLEXIO_VENDOR_ID_C != REG_ESYS_FLEXIOSPI_VENDOR_ID_REGFLEX)
    #error "Spi_FlexIO.c and Reg_eSys_FLEXIOSPI.h have different vendor ids"
#endif
/* Check if Spi_FlexIO.c file and Reg_eSys_FlexIOSPI.h file are of the same Autosar version */
#if ((SPI_FLEXIO_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_FLEXIOSPI_AR_RELEASE_MAJOR_VERSION_REGFLEX) || \
     (SPI_FLEXIO_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_FLEXIOSPI_AR_RELEASE_MINOR_VERSION_REGFLEX) || \
     (SPI_FLEXIO_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_FLEXIOSPI_AR_RELEASE_REVISION_VERSION_REGFLEX))
#error "AutoSar Version Numbers of Spi_FlexIO.c and Reg_eSys_FLEXIOSPI.h are different"
#endif
#if ((SPI_FLEXIO_SW_MAJOR_VERSION_C  != REG_ESYS_FLEXIOSPI_SW_MAJOR_VERSION_REGFLEX) || \
     (SPI_FLEXIO_SW_MINOR_VERSION_C  != REG_ESYS_FLEXIOSPI_SW_MINOR_VERSION_REGFLEX) || \
     (SPI_FLEXIO_SW_PATCH_VERSION_C  != REG_ESYS_FLEXIOSPI_SW_PATCH_VERSION_REGFLEX))
#error "Software Version Numbers of Spi_FlexIO.c and Reg_eSys_FLEXIOSPI.h are different"
#endif

#if (SPI_ENABLE_FLEXIO == STD_ON)
/* Check if this header file and Reg_eSys_FLEXIO.h are of the same vendor */
#if (SPI_FLEXIO_VENDOR_ID_C != REG_ESYS_FLEXIO_VENDOR_ID)
    #error "Spi_FlexIO.c and Reg_eSys_FLEXIO.h have different vendor ids"
#endif
/* Check if Spi_FlexIO.c file and Reg_eSys_FlexIOSPI.h file are of the same Autosar version */
#if ((SPI_FLEXIO_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_FLEXIO_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_FLEXIO_AR_RELEASE_MINOR_VERSION) || \
     (SPI_FLEXIO_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_FLEXIO_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_FlexIO.c and Reg_eSys_FLEXIO.h are different"
#endif
#if ((SPI_FLEXIO_SW_MAJOR_VERSION_C  != REG_ESYS_FLEXIO_SW_MAJOR_VERSION) || \
     (SPI_FLEXIO_SW_MINOR_VERSION_C  != REG_ESYS_FLEXIO_SW_MINOR_VERSION) || \
     (SPI_FLEXIO_SW_PATCH_VERSION_C  != REG_ESYS_FLEXIO_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_FlexIO.c and Reg_eSys_FLEXIO.h are different"
#endif

#endif

/* Check if this header file and Spi_IPW.h are of the same vendor */
#if (SPI_FLEXIO_VENDOR_ID_C != SPI_IPW_VENDOR_ID)
    #error "Spi_FlexIO.c and Spi_IPW.h have different vendor ids"
#endif
#if ((SPI_FLEXIO_AR_RELEASE_MAJOR_VERSION_C    != SPI_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_FLEXIO_AR_RELEASE_MINOR_VERSION_C    != SPI_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SPI_FLEXIO_AR_RELEASE_REVISION_VERSION_C != SPI_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_FlexIO.c and Spi_IPW.h are different"
#endif
/* Check if current file and Spi_IPW.h header file are of the same Autosar version */
#if ((SPI_FLEXIO_SW_MAJOR_VERSION_C != SPI_IPW_SW_MAJOR_VERSION) || \
     (SPI_FLEXIO_SW_MINOR_VERSION_C != SPI_IPW_SW_MINOR_VERSION) || \
     (SPI_FLEXIO_SW_PATCH_VERSION_C != SPI_IPW_SW_PATCH_VERSION))
#error "AutoSar Version Numbers of Spi_FlexIO.c and Spi_IPW.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((SPI_FLEXIO_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SPI_FLEXIO_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_FlexIO.c and Mcal.h are different"
    #endif

#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    #if ((SPI_FLEXIO_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
        (SPI_FLEXIO_AR_RELEASE_MINOR_VERSION_C  != DEM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_FlexIO.c and Dem.h are different"
    #endif
#endif

#if (SPI_ENABLE_FLEXIO == STD_ON)
    #if ((SPI_FLEXIO_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
        (SPI_FLEXIO_AR_RELEASE_MINOR_VERSION_C  != MCL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_FlexIO.c and CDD_Mcl.h are different"
    #endif
#endif

  /* Check if the source file and StdRegMacros header file are of the same version */
  #if ((SPI_FLEXIO_AR_RELEASE_MAJOR_VERSION_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
       (SPI_FLEXIO_AR_RELEASE_MINOR_VERSION_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION))
      #error "AutoSar Version Numbers of Spi_FlexIO.c and StdRegMacros.h are different"
  #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/



/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (SPI_ENABLE_FLEXIO == STD_ON)
    
#define SPI_FLEXIO_DMA_MAX_LINKED_ITER_CNT  (0x7FFFu)

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
#define SPI_FLEXIO_SYNCTRANSMIT 0u
#define SPI_FLEXIO_SYNCTRANSMIT_FAST 1u
#endif

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((SPI_LEVEL_DELIVERED != LEVEL1) && (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON))
/**
* @brief Pool of cached information for sequences having only one job.
*/
/*
* @violates @ref Spi_FlexIO_c_REF_11 the variables are defined globally for
* performance reasons.
*/
static VAR(Spi_FlexIO_SequenceCacheAttrsType, SPI_VAR) Spi_FlexIO_aSeqsAttributes[SPI_OPTIMIZED_SEQ_BUFFER_SIZE];

/**
* @brief Pool of cached information for sequences having only one job.
*/
/*
* @violates @ref Spi_FlexIO_c_REF_11 the variables are defined globally for
* performance reasons.
*/
static VAR(Spi_FlexIO_ChannelCacheAttrsType, SPI_VAR) Spi_FlexIO_aChannelsAttributes[SPI_OPTIMIZED_CHANNEL_BUFFER_SIZE];
#endif /* (SPI_LEVEL_DELIVERED != LEVEL1) && (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON) */
/*
* @violates @ref Spi_FlexIO_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 #if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*
* @violates @ref Spi_FlexIO_c_REF_11 the variables are defined globally for
* performance reasons.
*/
static VAR(Mcl_DmaTcdAttributesType, SPI_VAR) Spi_FlexIO_DmaCfgDesc;
#endif
/*
* @violates @ref Spi_FlexIO_c_REF_11 the variables are defined globally for
* performance reasons.
*/
static VAR(Spi_FlexIO_SyncStateType, SPI_VAR) Spi_FlexIO_SyncTransmitState[SPI_MAX_HWUNIT];

#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_FlexIO_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#define SPI_START_SEC_VAR_NO_INIT_32
/*
* @violates @ref Spi_FlexIO_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 /*
* @violates @ref Spi_FlexIO_c_REF_11 the variables are defined globally for
* performance reasons.
*/
static VAR(volatile uint32, SPI_VAR) Spi_FlexIO_u32ReadDiscard;

#define SPI_STOP_SEC_VAR_NO_INIT_32
/*
* @violates @ref Spi_FlexIO_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_FlexIO_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/*Global variables*/
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
VAR(Spi_DualClockModeType, SPI_VAR) Spi_FlexIO_ClockMode = SPI_NORMAL;
#endif
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/**
* @brief         Pointer table to the cached information structure, for one job
*             sequences, or NULL, for unoptimized sequences.
* @details    Internal structure keeping a set of cached sequences attributes
*               used by the optimized implementation of Spi_SyncTransmit() for the
*              sequences having only one job.
*
*/
/*
* @violates @ref Spi_LPspi_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
P2VAR(Spi_FlexIO_SequenceCacheAttrsType, SPI_VAR, SPI_APPL_DATA) Spi_FlexIO_apOneJobSeqsOptimized[SPI_MAX_SEQUENCE] = {NULL_PTR};
#endif
#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_FlexIO_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))) 
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
    #define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */
 
/*
* @violates @ref Spi_FlexIO_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/**
* @brief Keep the HWUnit internal fields.
*
*/
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
VAR(Spi_FlexIO_DeviceStateType, SPI_VAR) Spi_FlexIO_aDeviceState[SPI_MAX_HWUNIT];
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))    
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/    
    #define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */

/*
* @violates @ref Spi_FlexIO_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 /*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
/*
* @violates @ref Spi_FlexIO_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_FlexIO_SyncTransmitTX
(
    P2VAR(Spi_FlexIO_SyncStateType, AUTOMATIC,SPI_APPL_DATA) Spi_FlexIO_pSyncTransmitState
);

FUNC(Std_ReturnType, SPI_CODE) Spi_FlexIO_SyncTransmitRX
(
    P2VAR(Spi_FlexIO_SyncStateType, AUTOMATIC,SPI_APPL_DATA) Spi_FlexIO_pSyncTransmitState,
    VAR(uint8, AUTOMATIC) FlexIO_u8Sync
);
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_InitDma \
( 
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev \
);
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_DmaIrqConfig 
( 
        P2CONST(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_CONST) FlexIO_pDev, 
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode 
);
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_JobTransferDmaContinueTX \
    ( \
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev \
    );
#endif   
     

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_JobTransferDmaContinueRX \
    ( \
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev \
    );
#endif    



#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_ChannelTransferDmaInitTX_MclDmaSetup \
    ( \
        P2VAR(Mcl_DmaTcdType, AUTOMATIC, SPI_APPL_DATA) Spi_FlexIO_pTxTcdAddr, \
        P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelConfig, \
        P2CONST(Spi_Ipw_FlexIOChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelAttributesConfig, \
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev \
    );
#endif    
     
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_FlexIO_TransferStatus
(
    P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev,
    VAR(uint32, AUTOMATIC) FlexIO_u32IsrStatusTX,
    VAR(uint32, AUTOMATIC) FlexIO_u32IsrStatusRX
);
#endif  
     

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
FUNC(void, SPI_CODE) Spi_FlexIO_JobTransferFifoDrain \
( 
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev \
);
#endif 
     
     
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_FlexIO_JobTransferFifoFill \
( 
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev \
);
#endif  
    
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_FlexIO_WriteTxFifo 
(
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev, 
        VAR(uint8, AUTOMATIC) FlexIO_u8EndOfJob 
);
#endif     


#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_ChannelTransferFifoInitTX \
( 
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev, \
        VAR(Spi_ChannelType, AUTOMATIC) Channel \
);
#endif 

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_ChannelTransferFifoInitRX \
( 
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev, \
        VAR(Spi_ChannelType, AUTOMATIC) Channel \
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
);
#endif

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, SPI_CODE) Spi_FlexIO_SyncTransmitFast_CheckTimeOut
    (
        VAR(sint32, AUTOMATIC) FlexIO_s32Timeout
    ); 
#endif
#endif 

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_ChannelTransferDmaInitRX \
    ( \
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev, \
        VAR(Spi_ChannelType, AUTOMATIC) Channel \
    );
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_JobTransferDmaContinueTX \
    ( \
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev \
    );
#endif

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief   Initialize DMA related fields for a FlexIO unit.
* @details Initialize DMA TCD descriptors static fields.
*
* @param[in]     HWUnit      Specifies which FlexIO peripheral is used.
* @param[in]     FlexIO_pDev     LLD instance of the given FlexIO peripheral.
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_InitDma \
( 
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev \
) 
{
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) FlexIO_pcHWUnitConfig;
    FlexIO_pcHWUnitConfig = FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig;
    /* Get the adress of the TCD for the channels Tx and Rx */
    FlexIO_pDev->Spi_FlexIO_pu32TxDmaTcd = Mcl_DmaGetChannelTcdAddress(FlexIO_pcHWUnitConfig->u8TxDmaChannel);
    FlexIO_pDev->Spi_FlexIO_pu32RxDmaTcd = Mcl_DmaGetChannelTcdAddress(FlexIO_pcHWUnitConfig->u8RxDmaChannel);
    
     /* configure TX Channel 1 to write u32TxDmaBuffer (32bits) to FlexIO TDR */
    /* Compiler_Warning: It is intended for the address of the element to be stored
                          in another non pointer element*/
    Spi_FlexIO_DmaCfgDesc.u32saddr = 0u; /* src address read - will be updated later*/

    Spi_FlexIO_DmaCfgDesc.u32daddr = FlexIO_pDev->Spi_FlexIO_u32TDRAddress;/* dest address */ 
    
    Spi_FlexIO_DmaCfgDesc.u32dsize = (uint32)DMA_SIZE_4BYTES; /* 4bytes dest transfer size */
    Spi_FlexIO_DmaCfgDesc.u32ssize = (uint32)DMA_SIZE_4BYTES; /* 4bytes src transfer size */
    Spi_FlexIO_DmaCfgDesc.u32num_bytes = 4u; /* bytes to transfer */  
    
    Spi_FlexIO_DmaCfgDesc.u32soff  = 0u;     /* no src offset */
    Spi_FlexIO_DmaCfgDesc.u32doff  = 0u;     /* no dest offset */ 
    
    Spi_FlexIO_DmaCfgDesc.u32smod  = 0u;     /* no source address modulo */
    Spi_FlexIO_DmaCfgDesc.u32dmod  = 0u;     /* no dest address modulo   */ 
    Mcl_DmaConfigTcd(FlexIO_pDev->Spi_FlexIO_pu32TxDmaTcd, &Spi_FlexIO_DmaCfgDesc);  
          
    Spi_FlexIO_DmaCfgDesc.u32iter  = 1u;     /* iteration count - will be updated later */

    Mcl_DmaTcdSetFlags(FlexIO_pDev->Spi_FlexIO_pu32TxDmaTcd, (uint8)DMA_TCD_DISABLE_REQ_U32 );       
    
    /* setup RX DMA channel */
    Spi_FlexIO_DmaCfgDesc.u32saddr = FlexIO_pDev->Spi_FlexIO_u32RDRAddress; /* data only read */
    Spi_FlexIO_DmaCfgDesc.u32daddr = 0u;  /* dest address => will be updated later */ 
    
    Spi_FlexIO_DmaCfgDesc.u32soff  = 0u;  /* src offset */
    Spi_FlexIO_DmaCfgDesc.u32doff  = 0u;     /* no dest offset */ 
    
    Spi_FlexIO_DmaCfgDesc.u32dsize = (uint32)DMA_SIZE_4BYTES; /* 4bytes dest transfer size */
    Spi_FlexIO_DmaCfgDesc.u32ssize = (uint32)DMA_SIZE_4BYTES; /* 4bytes src transfer size */
    Spi_FlexIO_DmaCfgDesc.u32num_bytes = 4u; /* bytes to transfer */ 
    
    Spi_FlexIO_DmaCfgDesc.u32smod  = 0u;  /* no source address modulo */
    Spi_FlexIO_DmaCfgDesc.u32dmod  = 0u;  /* no dest address modulo   */
    
    Spi_FlexIO_DmaCfgDesc.u32iter  = 1u;  /* beg maj iter cnt => will be updated later */

    /* !!!! Not able to set the e-link */
    Mcl_DmaConfigTcd(FlexIO_pDev->Spi_FlexIO_pu32RxDmaTcd, &Spi_FlexIO_DmaCfgDesc);
    Mcl_DmaTcdSetFlags(FlexIO_pDev->Spi_FlexIO_pu32RxDmaTcd,  (uint8)DMA_TCD_DISABLE_REQ_U32); 
    

}
#endif 


/*================================================================================================*/
/**
* @brief   Low-level initialize function.
* @details Initialize the specific Spi unit with all configuration
*          parameters like Baud Rate, CS, Clock polarity, etc.
*          Also this function initializes all structure parameters
*          from the specific FlexIO unit.
*
* @param[in]      HWUnit      Specifies which FlexIO peripheral is used
*/
/*================================================================================================*/
FUNC(void, SPI_CODE) Spi_FlexIO_Init
(
     VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
     P2VAR(Spi_StatusType, AUTOMATIC, SPI_APPL_DATA) pStatus
)
{
     P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev;
     P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) FlexIO_pcHWUnitConfig;
     VAR(uint8, AUTOMATIC) Spi_FlexIO_u8TX = 0U;
     VAR(uint8, AUTOMATIC) Spi_FlexIO_u8RX = 0U;

    /* Get physical device instances and link them */
    FlexIO_pDev = &Spi_FlexIO_aDeviceState[HWUnit];
    /*
    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */    
    FlexIO_pcHWUnitConfig = &Spi_pcSpiConfigPtr->pcHWUnitConfig[HWUnit];
    FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig = FlexIO_pcHWUnitConfig;
    FlexIO_pDev->Spi_FlexIO_pStatus = pStatus;
    /* Reset poll flag */
    FlexIO_pDev->Spi_FlexIO_u8IsPollRequest = 0u;
    /* Get TX, RX offset */
    Spi_FlexIO_u8TX = FlexIO_pcHWUnitConfig->u8spiFlexIO_TX;
    Spi_FlexIO_u8RX = FlexIO_pcHWUnitConfig->u8spiFlexIO_RX;
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
    *  between a pointer type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */    
    FlexIO_pDev->Spi_FlexIO_u32TDRAddress = FLEXIO_SHIFTBUFn_ADDR32((uint32)Spi_FlexIO_u8TX);
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
    *  between a pointer type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */    
    FlexIO_pDev->Spi_FlexIO_u32RDRAddress = FLEXIO_SHIFTBUFBYSn_ADDR32((uint32)Spi_FlexIO_u8RX);
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))

    if (0u != FlexIO_pcHWUnitConfig->u16UseDma)
    {
       Spi_FlexIO_InitDma(FlexIO_pDev);
    }
    
#endif
    /* FlexIO Enable */
    Mcl_Flexio_Enable();           
}

/*================================================================================================*/
/**
* @brief   This function performs the de-initialization of a specific peripheral unit.
* @details This function de-initializes all configured values
*          in the MCR register and CTAR registers.
*
* @param[in]     HWUnit      Specifies which FLEXIO peripheral is used
*
*/
/*================================================================================================*/
FUNC(void, SPI_CODE) Spi_FlexIO_DeInit
(
     VAR(Spi_HWUnitType, AUTOMATIC) HWUnit
)
{
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) FlexIO_pcHWUnitConfig;
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_TX = 0u;
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_RX = 0u;    
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CLK = 0u;    
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CS = 0u;
    
    /*
     * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
     *       the only allowed form of pointer arithmetic.
    */      
    FlexIO_pcHWUnitConfig = &Spi_pcSpiConfigPtr->pcHWUnitConfig[HWUnit];
    
    /* Get address of Shifter TX/RX */
    Spi_FlexIO_u8Shifter_TX = FlexIO_pcHWUnitConfig->u8spiFlexIO_TX;
    Spi_FlexIO_u8Shifter_RX =  FlexIO_pcHWUnitConfig->u8spiFlexIO_RX; 
    Spi_FlexIO_u8Timer_CLK = FlexIO_pcHWUnitConfig->u8spiFlexIO_CLK;
    Spi_FlexIO_u8Timer_CS = FlexIO_pcHWUnitConfig->u8spiFlexIO_CS;
    
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed 
    *  between a pointer type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(FLEXIO_SHIFTCFGn_ADDR32((uint32)Spi_FlexIO_u8Shifter_TX),SPI_FLEXIO_CLEAR_REGISTER_U32);
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
    *  between a pointer type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(FLEXIO_SHIFTCTLn_ADDR32((uint32)Spi_FlexIO_u8Shifter_TX),SPI_FLEXIO_CLEAR_REGISTER_U32);
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
    *  between a pointer type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(FLEXIO_SHIFTCFGn_ADDR32((uint32)Spi_FlexIO_u8Shifter_RX),SPI_FLEXIO_CLEAR_REGISTER_U32);
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
    *  between a pointer type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(FLEXIO_SHIFTCTLn_ADDR32((uint32)Spi_FlexIO_u8Shifter_RX),SPI_FLEXIO_CLEAR_REGISTER_U32);
    if(SPI_MASTER == FlexIO_pcHWUnitConfig->eSpiPhyUnitMode)
    {
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32) Spi_FlexIO_u8Timer_CLK),SPI_FLEXIO_CLEAR_REGISTER_U32);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */       
        REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32) Spi_FlexIO_u8Timer_CLK),SPI_FLEXIO_CLEAR_REGISTER_U32);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32) Spi_FlexIO_u8Timer_CLK),SPI_FLEXIO_CLEAR_REGISTER_U32);
        
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32) Spi_FlexIO_u8Timer_CS),SPI_FLEXIO_CLEAR_REGISTER_U32);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32) Spi_FlexIO_u8Timer_CS),SPI_FLEXIO_CLEAR_REGISTER_U32);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32) Spi_FlexIO_u8Timer_CS),SPI_FLEXIO_CLEAR_REGISTER_U32);        
    }
    else
    {
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32) Spi_FlexIO_u8Timer_CLK),SPI_FLEXIO_CLEAR_REGISTER_U32);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32) Spi_FlexIO_u8Timer_CLK),SPI_FLEXIO_CLEAR_REGISTER_U32);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */       
        REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32) Spi_FlexIO_u8Timer_CLK),SPI_FLEXIO_CLEAR_REGISTER_U32);        
    }
    /* Reset all flag status */
    Mcl_Flexio_ClearShiftStat(((uint8)(1U << Spi_FlexIO_u8Shifter_TX)) | ((uint8)(1U << Spi_FlexIO_u8Shifter_RX)));
    Mcl_Flexio_ClearShiftErr(((uint8)(1U << Spi_FlexIO_u8Shifter_TX)) | ((uint8)(1U << Spi_FlexIO_u8Shifter_RX)));
    Mcl_Flexio_ClearTimStat(((uint8)(1U << Spi_FlexIO_u8Shifter_TX)) | ((uint8)(1U << Spi_FlexIO_u8Shifter_RX)));
}

/*================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
/**
* @brief   This function performs the synchronous transmission for a sequence.
* @details This function is pre compile time selectable by the
*          configuration parameter: SPI_LEVEL_DELIVERED. This function is only
*          relevant for LEVEL 0 and LEVEL 2.
*
* @param[in]     Sequence      Specifies the sequence for which we will have
*                              the synchronous transmission
*
* @return Std_ReturnType
* @retval E_OK            Transmission command has been completed
* @retval E_NOT_OK        Transmission command has not been accepted
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL0 or LEVEL2
*
* @implements Spi_FlexIO_SyncTransmit_Activity
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_FlexIO_SyncTransmit
    (
        VAR(Spi_SequenceType, AUTOMATIC) Sequence
    )
{
    P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcSequenceConfig;
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcJobConfig;
    P2CONST(Spi_JobType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcJobIndexList;
    P2CONST(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pDev;
    P2VAR(Spi_FlexIO_SyncStateType, AUTOMATIC, SPI_APPL_DATA) Spi_FlexIO_pSyncTransmitState;
    P2VAR(Spi_JobStateType, AUTOMATIC, SPI_APPL_DATA) Spi_FlexIO_pJobState;    
    VAR(Spi_JobType, AUTOMATIC) Spi_FlexIO_JobsCount;
    VAR(Spi_JobType, AUTOMATIC) Spi_FlexIO_Job;
    VAR(Std_ReturnType, AUTOMATIC) Spi_FlexIO_Status = (Std_ReturnType)E_OK;
    VAR(Std_ReturnType, AUTOMATIC) Spi_FlexIO_SyncJobStatus = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_TX = 0u;
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_RX = 0u;    
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CLK = 0u;    
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CS = 0u;
    
    /* Get sequence configuration */
    /*
     * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
     *       the only allowed form of pointer arithmetic.
    */
    Spi_FlexIO_pcSequenceConfig = &Spi_pcSpiConfigPtr->pcSequenceConfig[Sequence];
    /* Get the number of jobs in the sequence */
    Spi_FlexIO_JobsCount = Spi_FlexIO_pcSequenceConfig->NumJobs;
    Spi_FlexIO_pcJobIndexList = Spi_FlexIO_pcSequenceConfig->pcJobIndexList;
    while (0u < Spi_FlexIO_JobsCount)
    {
        /* Get the job id */
        Spi_FlexIO_Job = *Spi_FlexIO_pcJobIndexList;

        /* Set the job status as pending */
        Spi_FlexIO_pJobState = &Spi_aSpiJobState[Spi_FlexIO_Job];
        Spi_FlexIO_pJobState->Result = SPI_JOB_PENDING;
        /*
         * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
         *       the only allowed form of pointer arithmetic.
        */
        Spi_FlexIO_pcJobConfig = &Spi_pcSpiConfigPtr->pcJobConfig[Spi_FlexIO_Job];
        
        /* start job notification to assert the non-cs pin,
            when non-cs pin is used as chipselect*/
        if (NULL_PTR != Spi_FlexIO_pcJobConfig->pfStartNotification)
        {
            Spi_FlexIO_pcJobConfig->pfStartNotification();
        }
        else
        {
            /* Do nothing */
        }
        Spi_FlexIO_pDev = &Spi_FlexIO_aDeviceState[Spi_FlexIO_pcJobConfig->HWUnit];
        /* mark HW unit as busy */
        *(Spi_FlexIO_pDev->Spi_FlexIO_pStatus) = SPI_BUSY;
        /* Update Synchronous transmission state  */         
        Spi_FlexIO_pSyncTransmitState = &Spi_FlexIO_SyncTransmitState[Spi_FlexIO_pcJobConfig->HWUnit];        
        /* Get address of Shifter TX/RX used in Spi_FlexIO_SyncTransmitJob() */
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8Shifter_TX = Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_TX;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8Shifter_RX = Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_RX;     
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8Timer_CLK = Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_CLK; 
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8Timer_CS = Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_CS;
        /* Get address of Shifter TX/RX */
        Spi_FlexIO_u8Shifter_TX = Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_TX;
        Spi_FlexIO_u8Shifter_RX =  Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_RX; 
        Spi_FlexIO_u8Timer_CLK = Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_CLK;
        Spi_FlexIO_u8Timer_CS = Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_CS;
        /* Get Shifter, Timer config data */
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] = \
            (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32ShifterCFGConfigTX;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_RX] = \
            (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32ShifterCFGConfigRX;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX] = \
            (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32ShifterCTLConfigTX;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX] = \
            (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32ShifterCTLConfigRX;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]   = \
            (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCMPConfigCLK;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CS]   = \
            (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCMPConfigCS;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK]   = \
            (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCTLConfigCLK;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CS]   = \
            (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCTLConfigCS;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]   = \
            (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCFGConfigCLK;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_MASTER = Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->eSpiPhyUnitMode;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32BaseAddress = (uint32)FLEXIO_BASEADDR;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8EndOfJobFlag =(uint8)FALSE;
        /* Get CPOL, CPHA, PSC for each job */
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8CPOL = (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u8CPOL;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8CPHA = (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u8CPHA;
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32PSC[0] = (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32PSC[0];    
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32PSC[1] = (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32PSC[1];
#else
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32PSC = (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32PSC;    
#endif    
        /* iterate on all channels in job */
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_ChannelsCountTX = Spi_FlexIO_pcJobConfig->NumChannels;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_ChannelsCountRX = Spi_FlexIO_pcJobConfig->NumChannels;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pcChannelIndexListTX = Spi_FlexIO_pcJobConfig->pcChannelIndexList;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pcChannelIndexListRX = Spi_FlexIO_pcJobConfig->pcChannelIndexList; 
        /* Synchronous transmission for a Job*/
        Spi_FlexIO_SyncJobStatus = Spi_FlexIO_SyncTransmitJob(Spi_FlexIO_pSyncTransmitState);
        /* release the HW unit */
        *(Spi_FlexIO_pDev->Spi_FlexIO_pStatus) = SPI_IDLE;
        if ((Std_ReturnType)E_OK == Spi_FlexIO_SyncJobStatus)
        {
            /* Job is done set the status as OK */
            Spi_FlexIO_pJobState->Result = SPI_JOB_OK;
            /* Perform job EndNotification (if there is one) */
            if (NULL_PTR != Spi_FlexIO_pcJobConfig->pfEndNotification)
            {
                Spi_FlexIO_pcJobConfig->pfEndNotification();
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* u32Timeout expired => transmission failed */
            /* set the remaining job status (including the current one) as FAILED */
            do
            {
                /* Set the job status as FAILED */
                Spi_aSpiJobState[*Spi_FlexIO_pcJobIndexList].Result = SPI_JOB_FAILED;
                /* Update pointer position for pcJobConfig */
                /*
                 * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                 *       the only allowed form of pointer arithmetic.
                */                
                Spi_FlexIO_pcJobConfig = &Spi_pcSpiConfigPtr->pcJobConfig[*Spi_FlexIO_pcJobIndexList];
                /* Perform job EndNotification (if there is one) */
                if (NULL_PTR != Spi_FlexIO_pcJobConfig->pfEndNotification)
                {
                    Spi_FlexIO_pcJobConfig->pfEndNotification();
                }
                else
                {
                    /* Do nothing */
                }
                /*
                 * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                 *       the only allowed form of pointer arithmetic.
                */
                Spi_FlexIO_pcJobIndexList++;
                Spi_FlexIO_JobsCount--;
            } while (0u < Spi_FlexIO_JobsCount);
            Spi_FlexIO_JobsCount = 1u;  /* needed to end correctly the outer loop */
            Spi_FlexIO_Status = (Std_ReturnType)E_NOT_OK;
        }
        /* iterate to next job in sequence */ 
        /*
         * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
         *       the only allowed form of pointer arithmetic.
        */
        Spi_FlexIO_pcJobIndexList++;
        Spi_FlexIO_JobsCount--;
    } /* while (JobsCount > 0u) */

    if ((Std_ReturnType)E_OK != Spi_FlexIO_Status)
    {
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)        
        /* Call Dem_ReportErrorStatus. */
        if ((uint32)STD_ON == Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.state)
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.id, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            /* Do nothing */
        }
#endif
    }
    else
    {
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)        
        /* Call Dem_ReportErrorStatus. */
        if ((uint32)STD_ON == Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.state)
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.id, DEM_EVENT_STATUS_PASSED);
        }
        else
        {
            /* Do nothing */
        }
#endif 
    }
    return Spi_FlexIO_Status;
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) ) */
/*================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
/**
* @brief   This function performs the synchronous transmission for a job.
* @details This function is pre compile time selectable by the
*          configuration parameter: SPI_LEVEL_DELIVERED. This function is only
*          relevant for LEVEL 0 and LEVEL 2.
*
* @param[in]     Spi_FlexIO_pSyncTransmitState   Specifies which state transmission data of job and channel
*
* @return Std_ReturnType
* @retval E_OK            Transmission command has been completed
* @retval E_NOT_OK        Transmission command has not been accepted
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL0 or LEVEL2
*/
/*================================================================================================*/
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_FlexIO_SyncTransmitJob
(
   P2VAR(Spi_FlexIO_SyncStateType, AUTOMATIC,SPI_APPL_DATA) Spi_FlexIO_pSyncTransmitState
)
{
    VAR(Spi_ChannelType, AUTOMATIC) Spi_FlexIO_ChannelTX=0u;
    VAR(Spi_ChannelType, AUTOMATIC) Spi_FlexIO_ChannelRX=0u;
    P2CONST(Spi_Ipw_FlexIOChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelAttributesCfgTX = NULL_PTR;
    /*
    * @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
    * significance and case sensitivity are supported for external identifiers.
    */
    P2CONST(Spi_Ipw_FlexIOChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelAttributesCfgRX = NULL_PTR;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelConfigTX;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelConfigRX;
    P2CONST(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pChannelState;
    VAR(uint8, AUTOMATIC) Spi_FlexIO_u8FirstChannelOfJobFlag = (uint8)TRUE;
    VAR(sint32, AUTOMATIC) Spi_FlexIO_s32Timeout = SPI_TIMEOUT_COUNTER; 
    VAR(Std_ReturnType, AUTOMATIC) Spi_FlexIO_SyncJobStatus = (Std_ReturnType)E_OK;
    VAR(Std_ReturnType, AUTOMATIC) SPI_FlexIO_TransStatus = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_TX = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8Shifter_TX;
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_RX = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8Shifter_RX;    
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CLK = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8Timer_CLK;    
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CS = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8Timer_CS;   
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8TRGSEL = (4u*Spi_FlexIO_u8Shifter_TX) + 1u;
    
    while((Spi_ChannelType)0 < Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_ChannelsCountTX)
    {
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_ChannelsCountTX--;
        /* Get the channel ID & configuration */
        Spi_FlexIO_ChannelTX = *Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pcChannelIndexListTX;
        /* Get Channel Attributes */
        /*
        * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        Spi_FlexIO_pcChannelAttributesCfgTX = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcFlexIOChannelAttributesConfig[Spi_FlexIO_ChannelTX];
        /* Update the channel attributions */        
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32FSIZE  = Spi_FlexIO_pcChannelAttributesCfgTX->u32NumBitsInFrame;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8LBF    = Spi_FlexIO_pcChannelAttributesCfgTX->u8LBF;
        /*
        * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        Spi_FlexIO_pcChannelConfigTX = &Spi_pcSpiConfigPtr->pcChannelConfig[Spi_FlexIO_ChannelTX];
        Spi_FlexIO_pChannelState = Spi_FlexIO_pcChannelConfigTX->pChannelState;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32DefaultTransmitValue = Spi_FlexIO_pcChannelConfigTX->u32DefaultTransmitValue;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32DataWidthTX = Spi_FlexIO_pcChannelAttributesCfgTX->u32DataWidth;
        /* retrieve TX buffers and the transmitted length */
        if (1u == (Spi_FlexIO_pChannelState->u8Flags & ((uint8)SPI_CHANNEL_FLAG_TX_DEFAULT_U8)))
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pBufferTX = NULL_PTR;
        }
        else
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pBufferTX = Spi_FlexIO_pcChannelConfigTX->pcBufferDescriptor->pBufferTX;
        }
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthTX = Spi_FlexIO_pChannelState->Length;
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesCfgTX->u32DataWidth)
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthTX /= 2u;
        }
        else if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesCfgTX->u32DataWidth)
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthTX /= 4u;
        }
        else
        {
            /* Do nothing */
        }
        #else
        if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesCfgTX->u32DataWidth)
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthTX /= 2u;
        }
        else
        {
            /* Do nothing */
        }
        #endif
        /* if the channel is the first of Job then retrieve RX buffers and the received length */
        if((uint8)TRUE == Spi_FlexIO_u8FirstChannelOfJobFlag)
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_ChannelsCountRX--;
            /* Get the channel ID & configuration */
            Spi_FlexIO_ChannelRX = *Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pcChannelIndexListRX;
            /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            Spi_FlexIO_pcChannelAttributesCfgRX = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcFlexIOChannelAttributesConfig[Spi_FlexIO_ChannelRX];
            /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            Spi_FlexIO_pcChannelConfigRX = &Spi_pcSpiConfigPtr->pcChannelConfig[Spi_FlexIO_ChannelRX];
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pBufferRX = Spi_FlexIO_pcChannelConfigRX->pcBufferDescriptor->pBufferRX;
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32DataWidthRX = Spi_FlexIO_pcChannelAttributesCfgRX->u32DataWidth;
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthRX = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthTX;
        }
        else
        {
            /* Do nothing */
        }
        Spi_FlexIO_s32Timeout = SPI_TIMEOUT_COUNTER;
        if(SPI_FLEXIO_CPHA_TRAILING_U8 == Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8CPHA)
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCFG_CPHA0_U32; 
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCTL_TIMPOL_U32;
        }
        else if (SPI_FLEXIO_CPHA_LEADING_U8 == Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8CPHA)
        {                
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCFG_CPHA1_U32; 
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX] |= SPI_FLEXIO_SHIFTCTL_TIMPOL_U32; 
        }
        else
        {
            /*Do notthing*/
        }
        if(SPI_FLEXIO_CPOL_HIGH_U8 == Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8CPOL)
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK] |= SPI_FLEXIO_SHIFTCTL_PINPOL_HIGH_U32;
        }
        else
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK] |= SPI_FLEXIO_SHIFTCTL_PINPOL_LOW_U32;
        }
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]  |= Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32PSC[Spi_FlexIO_ClockMode];
#else
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]  |= Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32PSC;
#endif    
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]  |= (Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32FSIZE) << 8;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]  |= SPI_FLEXIO_TIMCFG_CLK_MASTER_U32;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CS]  |= SPI_FLEXIO_TIMCFG_CS_MASTER_U32;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CS]  |= SPI_FLEXIO_TIMCMP_RWBITS_U32;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK]  |= (uint32)Spi_FlexIO_u8TRGSEL << 24;
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */            
        REG_WRITE32(FLEXIO_SHIFTCFGn_ADDR32((uint32)Spi_FlexIO_u8Shifter_TX),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */           
        REG_WRITE32(FLEXIO_SHIFTCTLn_ADDR32((uint32)Spi_FlexIO_u8Shifter_TX),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_SHIFTCFGn_ADDR32((uint32)Spi_FlexIO_u8Shifter_RX),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_RX]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_SHIFTCTLn_ADDR32((uint32)Spi_FlexIO_u8Shifter_RX),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]); 
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)Spi_FlexIO_u8Timer_CS),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CS]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32)Spi_FlexIO_u8Timer_CS),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CS]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */                
        REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32)Spi_FlexIO_u8Timer_CS),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CS]);
        while
        (
           ((Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthTX>0u) && (Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8EndOfJobFlag==(uint8)FALSE)) ||
            ((Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8EndOfJobFlag==(uint8)TRUE) && ((Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthTX>0u) || (Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthRX>0u)))
        )
        {
            /* --------- Transmit ---------- */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
            *  between a pointer type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */            
            if(0u != Mcl_Flexio_ReadShiftStat((uint8)(1u<<Spi_FlexIO_u8Shifter_TX)))
            {  
                SPI_FlexIO_TransStatus = Spi_FlexIO_SyncTransmitTX(Spi_FlexIO_pSyncTransmitState);
                if((Std_ReturnType)E_OK == SPI_FlexIO_TransStatus)
                {
                    /* reset the timeout */
                    Spi_FlexIO_s32Timeout = SPI_TIMEOUT_COUNTER;
                }
                else
                {
                    /* Do nothing */
                }
            }
           /* --------- Receive ---------- */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
            *  between a pointer type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            if(0u != Mcl_Flexio_ReadShiftStat((uint8)(1u<<Spi_FlexIO_u8Shifter_RX)))
            {
                SPI_FlexIO_TransStatus = Spi_FlexIO_SyncTransmitRX(Spi_FlexIO_pSyncTransmitState,SPI_FLEXIO_SYNCTRANSMIT);
            
                if((Std_ReturnType)E_OK == SPI_FlexIO_TransStatus)
                {
                    /* reset the timeout */
                    Spi_FlexIO_s32Timeout = SPI_TIMEOUT_COUNTER;
                }
                else
                {
                    /* Do nothing */
                }
            }
            Spi_FlexIO_s32Timeout--;
            /* end the loop if timeout expired */
            if ((sint32)0u == Spi_FlexIO_s32Timeout)
            {
                /* force the end of the outer loop too */
                Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_ChannelsCountTX = 0U;
                Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_ChannelsCountRX = 0U;
                Spi_FlexIO_SyncJobStatus = (Std_ReturnType)E_NOT_OK;
                break; 
            }
            else
            {
                /* Do nothing */
            }
        } /* while ((LengthTX > 0) || (LengthRX > 0)) */       
        /*
        * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pcChannelIndexListTX++;
        Spi_FlexIO_u8FirstChannelOfJobFlag=(uint8)FALSE;

    }/* while (ChannelsCountTX) */
  return Spi_FlexIO_SyncJobStatus;
}
#endif 
    
/*================================================================================================*/
/*================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)

LOCAL_INLINE FUNC(Std_ReturnType, SPI_CODE) Spi_FlexIO_SyncTransmitFast_CheckTimeOut
    (
        VAR(sint32, AUTOMATIC) FlexIO_s32Timeout
    )
    {
        VAR(Std_ReturnType, AUTOMATIC) FlexIO_Status;
        
        if ((sint32)0 < FlexIO_s32Timeout)
        {
            /* Job is done set the status as OK */
            FlexIO_Status = (Std_ReturnType)E_OK;
        #if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)        
            /* Call Dem_ReportErrorStatus. */
            if ((uint32)STD_ON == Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.id, DEM_EVENT_STATUS_PASSED);
            }
            else
            {
                /* Do nothing */
            }
    #endif 
            }
        else
        {
            /* u32Timeout expired => transmission failed */
            /* set the Job status as FAILED */
            FlexIO_Status = (Std_ReturnType)E_NOT_OK;
    #if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)        
            /* Call Dem_ReportErrorStatus. */
            if ((uint32)STD_ON == Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.state)
            {
                    (void)Dem_SetEventStatus((Dem_EventIdType)Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.id, DEM_EVENT_STATUS_FAILED);
                }
            else
            {
                /* Do nothing */
            }
    #endif
        }
        
        return FlexIO_Status;
    
    }
#endif /* (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON) */
#endif /* ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) ) */
/*================================================================================================*/
/*================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/**
* @brief   This function starts the synchronous transmission for optimized sequences having only one job.
* @details This function is pre compile time selectable by the
*          configuration parameter: SPI_LEVEL_DELIVERED. This function is only
*          relevant for LEVEL 0 and LEVEL 2.
*          Same behavior as Spi_SyncTransmit(), but the initialization time and
*          data preparation time are optimized.
*
* @param[in]     pcSequence     Keep the cached information for "one job sequence"
*
* @return Std_ReturnType
* @retval E_OK            Transmission command has been completed
* @retval E_NOT_OK        Transmission command has not been accepted
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL0 or LEVEL2
* @pre  Pre-compile parameter SPI_OPTIMIZE_ONE_JOB_SEQUENCES shall be STD_ON
*
* @implements Spi_FlexIO_SyncTransmit_Fast_Activity
*/
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_FlexIO_SyncTransmit_Fast
    (
        P2CONST(Spi_FlexIO_SequenceCacheAttrsType, AUTOMATIC, SPI_APPL_CONST) pcSequence
    )
{
    P2CONST(Spi_FlexIO_ChannelCacheAttrsType, AUTOMATIC, SPI_APPL_CONST) FlexIO_pChannelTX;    
    P2VAR(Spi_JobStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pJobState = pcSequence->FlexIO_pJobState;
    VAR(sint32, AUTOMATIC) FlexIO_s32Timeout = SPI_TIMEOUT_COUNTER;
    VAR(Std_ReturnType, AUTOMATIC) FlexIO_Status;
    VAR(uint8, AUTOMATIC) FlexIO_FirstChannelOfJobFlag=(uint8)TRUE;
    VAR(Std_ReturnType, AUTOMATIC) FlexIO_TransStatus = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) FlexIO_u32BaseAddress = pcSequence->Spi_FlexIO_u32BaseAddress;
    P2VAR(Spi_FlexIO_SyncStateType, AUTOMATIC, SPI_APPL_DATA) Spi_FlexIO_pSyncTransmitState = &Spi_FlexIO_SyncTransmitState[pcSequence->FlexIO_HWUnit];
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_TX = pcSequence->Spi_FlexIO_u8Shifter_TX;
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_RX = pcSequence->Spi_FlexIO_u8Shifter_RX;    
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CLK = pcSequence->Spi_FlexIO_u8Timer_CLK;    
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CS = pcSequence->Spi_FlexIO_u8Timer_CS;   
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8TRGSEL = (4u*Spi_FlexIO_u8Shifter_TX) + 1u;
    
    /* Get address of Shifter TX/RX used in Spi_FlexIO_SyncTransmitJob() */
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8Shifter_TX = Spi_FlexIO_u8Shifter_TX;
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8Shifter_RX = Spi_FlexIO_u8Shifter_RX;     
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8Timer_CLK = Spi_FlexIO_u8Timer_CLK; 
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8Timer_CS = Spi_FlexIO_u8Timer_CS;
    /* Get Shifter, Timer config data */
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] = \
        pcSequence->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX];
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_RX] = \
        pcSequence->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_RX];
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX] = \
        pcSequence->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX];
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX] = \
        pcSequence->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX];
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]   = \
        pcSequence->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK];
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CS]   = \
        pcSequence->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CS];
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK]   = \
        pcSequence->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK];
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CS]   = \
        pcSequence->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CS];
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]   = \
        pcSequence->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK];
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_MASTER = pcSequence->Spi_FlexIO_MASTER;
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32BaseAddress = FlexIO_u32BaseAddress;
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8EndOfJobFlag =(uint8)FALSE;
    /* Get CPOL, CPHA, PSC for each job */
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8CPOL = pcSequence->Spi_FlexIO_u8CPOL;
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8CPHA = pcSequence->Spi_FlexIO_u8CPHA;
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32PSC[0] = pcSequence->Spi_FlexIO_u32PSC[0];
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32PSC[1] = pcSequence->Spi_FlexIO_u32PSC[1];
#else
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32PSC = pcSequence->Spi_FlexIO_u32PSC;
#endif
    /* Set the job status as pending and mark HW Unit as busy */
    FlexIO_pJobState->Result = SPI_JOB_PENDING;
    *(pcSequence->FlexIO_pJobStatus) = SPI_BUSY;
    /* iterate on all channels in job */
    FlexIO_pChannelTX = pcSequence->FlexIO_pChannels;
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pChannelRX = pcSequence->FlexIO_pChannels;
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_ChannelsCountTX = pcSequence->FlexIO_NumChannels;
    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_ChannelsCountRX = pcSequence->FlexIO_NumChannels;
    while ((Spi_ChannelType)0 < Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_ChannelsCountTX)
    {
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_ChannelsCountTX--;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32DefaultTransmitValue = FlexIO_pChannelTX->FlexIO_u32DefaultTransmitValue;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32DataWidthTX = FlexIO_pChannelTX->u32DataWidth;
        /* Update the channel attributions */        
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32FSIZE  = FlexIO_pChannelTX->u32NumBitsInFrame;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8LBF    = FlexIO_pChannelTX->u8LBF;
        /* retrieve TX buffers and the transmitted length */
        if (1u == (FlexIO_pChannelTX->FlexIO_pState->u8Flags & ((uint8)SPI_CHANNEL_FLAG_TX_DEFAULT_U8)))
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pBufferTX = NULL_PTR;
        }
        else
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pBufferTX = FlexIO_pChannelTX->FlexIO_pcBufferDescriptor->pBufferTX;
        }
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthTX = FlexIO_pChannelTX->FlexIO_pState->Length;
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_FLEXIO_DATA_WIDTH_16 == FlexIO_pChannelTX->u32DataWidth)
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthTX /= 2u;
        }
        else if (SPI_FLEXIO_DATA_WIDTH_32 == FlexIO_pChannelTX->u32DataWidth)
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthTX /= 4u;
        }
        else
        {
            /* Do nothing */
        }
        #else
        if (SPI_FLEXIO_DATA_WIDTH_32 == FlexIO_pChannelTX->u32DataWidth)
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthTX /= 2u;
        }
        else
        {
            /* Do nothing */
        }
        #endif
        /* if the channel is the first of Job then retrieve RX buffers and the received length */
        if((uint8)TRUE == FlexIO_FirstChannelOfJobFlag)
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_ChannelsCountRX--;
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pBufferRX = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pChannelRX->FlexIO_pcBufferDescriptor->pBufferRX;
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthRX = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthTX;
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32DataWidthRX = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pChannelRX->u32DataWidth;
        }
        if(SPI_FLEXIO_CPHA_TRAILING_U8 == Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8CPHA)
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCFG_CPHA0_U32; 
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCTL_TIMPOL_U32;
        }
        else if (SPI_FLEXIO_CPHA_LEADING_U8 == Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8CPHA)
        {                
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCFG_CPHA1_U32; 
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX] |= SPI_FLEXIO_SHIFTCTL_TIMPOL_U32; 
        }
        else
        {
            /*Do notthing*/
        }
        if(SPI_FLEXIO_CPOL_HIGH_U8 == Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8CPOL)
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK] |= SPI_FLEXIO_SHIFTCTL_PINPOL_HIGH_U32;
        }
        else
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK] |= SPI_FLEXIO_SHIFTCTL_PINPOL_LOW_U32;
        }
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]  |= Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32PSC[Spi_FlexIO_ClockMode];
#else
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]  |= Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32PSC;
#endif
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]  |= (Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32FSIZE) << 8;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]  |= SPI_FLEXIO_TIMCFG_CLK_MASTER_U32;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CS]  |= SPI_FLEXIO_TIMCFG_CS_MASTER_U32;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CS]  |= SPI_FLEXIO_TIMCMP_RWBITS_U32;
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK]  |= (uint32)Spi_FlexIO_u8TRGSEL << 24;
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */            
        REG_WRITE32(FLEXIO_SHIFTCFGn_ADDR32((uint32)Spi_FlexIO_u8Shifter_TX),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */           
        REG_WRITE32(FLEXIO_SHIFTCTLn_ADDR32((uint32)Spi_FlexIO_u8Shifter_TX),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_SHIFTCFGn_ADDR32((uint32)Spi_FlexIO_u8Shifter_RX),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_RX]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_SHIFTCTLn_ADDR32((uint32)Spi_FlexIO_u8Shifter_RX),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]); 
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)Spi_FlexIO_u8Timer_CS),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CS]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32)Spi_FlexIO_u8Timer_CS),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CS]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */                
        REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32)Spi_FlexIO_u8Timer_CS),Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CS]);
        /*Get time out value*/
        FlexIO_s32Timeout = SPI_TIMEOUT_COUNTER;
        /* while there is still something to read or to write */
        /* a kind of: while ((FlexIO_LengthTX > 0) || (FlexIO_LengthRX > 0)) */
        while(
                ((Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthTX>0u) && (Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8EndOfJobFlag==(uint8)FALSE)) ||
                ((Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8EndOfJobFlag==(uint8)TRUE) && ((Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthTX>0u) || (Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthRX>0u)))
             )
        {
                /* --------- Transmit ---------- */
            if(0u != Mcl_Flexio_ReadShiftStat((uint8)(1u<<Spi_FlexIO_u8Shifter_TX)))
            {
                FlexIO_TransStatus = Spi_FlexIO_SyncTransmitTX(Spi_FlexIO_pSyncTransmitState);
                if((Std_ReturnType)E_OK == FlexIO_TransStatus)
                {
                    /* reset the timeout */
                    FlexIO_s32Timeout = SPI_TIMEOUT_COUNTER;
                }
                else
                {
                    /* Do nothing */
                }
            }
            if(0u != Mcl_Flexio_ReadShiftStat((uint8)(1u<<Spi_FlexIO_u8Shifter_RX)))
            {
               /* --------- Receive ---------- */
                FlexIO_TransStatus = Spi_FlexIO_SyncTransmitRX(Spi_FlexIO_pSyncTransmitState, SPI_FLEXIO_SYNCTRANSMIT_FAST);
                if((Std_ReturnType)E_OK == FlexIO_TransStatus)
                {
                    /* reset the timeout */
                    FlexIO_s32Timeout = SPI_TIMEOUT_COUNTER;
                }
                else
                {
                    /* Do nothing */
                }
            }
           
           FlexIO_s32Timeout--;
            /* end the loop if timeout expired */
            if ((sint32)0 >= FlexIO_s32Timeout)
            {
                /* force the end of the outer loop too */
                Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_ChannelsCountTX = 0U;
                Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_ChannelsCountRX = 0U;
                break; 
            }
            else
            {
                /* Do nothing */
            }
        } /* while ((LengthTX > 0) || (LengthRX > 0)) */
        /*
        * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        FlexIO_pChannelTX++;
        FlexIO_FirstChannelOfJobFlag=(uint8)FALSE;
    } /* while (ChannelsCount) */
    /* release the HW Unit */
    *(pcSequence->FlexIO_pJobStatus) = SPI_IDLE;
    FlexIO_Status = Spi_FlexIO_SyncTransmitFast_CheckTimeOut(FlexIO_s32Timeout);
    
    return FlexIO_Status;
}
#endif /* (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON) */
#endif /* ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) ) */
/*================================================================================================*/
/*================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
/**
* @brief   This function fills the FlexIO TX FIFO.
* @details This function fills the FlexIO FIFO Transmit buffer with
*          data assigned or transmit the default buffer values.   
*          This function is pre compile time selectable by the
*          configuration parameter: SPI_LEVEL_DELIVERED. This function is only
*          relevant for LEVEL 0 and LEVEL 2.
*
* @param[in]     Spi_FlexIO_pSyncTransmitState   Specifies which state transmission data of job and channel
* 
*
* @return Std_ReturnType
* @retval E_OK            Transmission command has been completed
* @retval E_NOT_OK        Transmission command has not been accepted
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL0 or LEVEL2
*
*/
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_FlexIO_SyncTransmitTX
(
    P2VAR(Spi_FlexIO_SyncStateType, AUTOMATIC,SPI_APPL_DATA) Spi_FlexIO_pSyncTransmitState
)
{
    VAR(Std_ReturnType, AUTOMATIC) Spi_FlexIO_Status = (Std_ReturnType)E_NOT_OK;
     P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA)Spi_FlexIO_pBufferTX = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pBufferTX;
     VAR(uint32, AUTOMATIC) Spi_FlexIO_u32TempXferData;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2CONST(uint16, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pu16BufferFullTX;
    P2CONST(uint32, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pu32BufferFullTX;
#endif
    VAR(uint32, AUTOMATIC) Spi_FlexIO_u32DataWidthTX = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32DataWidthTX;
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_TX = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8Shifter_TX;
    /* @violates @ref Spi_FlexIO_c_REF_13 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32TDRAddress = 0;
    /* Get TX address */
    if (SPI_FLEXIO_LSB_U8 == Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8LBF)
    {
        Spi_FlexIO_u32TDRAddress = FLEXIO_SHIFTBUFn_ADDR32((uint32)Spi_FlexIO_u8Shifter_TX);        
    }
    else if (SPI_FLEXIO_MSB_U8 == Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8LBF)
    {
        Spi_FlexIO_u32TDRAddress = FLEXIO_SHIFTBUFBISn_ADDR32((uint32)Spi_FlexIO_u8Shifter_TX);        
    }
    else 
    {
        /* Do notthing */
    }
     if (Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthTX > 0u)
     {
        if (NULL_PTR == Spi_FlexIO_pBufferTX)
        {
            /* Get default data if TX buffer is NULL_PTR */
            Spi_FlexIO_u32TempXferData = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32DefaultTransmitValue;
        }
        else
        {
            /* Read transmit data */
           #if (SPI_FORCE_DATA_TYPE == STD_ON)
            if (SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_u32DataWidthTX)
            {
                /*
                 * @violates @ref Spi_FlexIO_c_REF_4 A cast should not be performed
                 * between a pointer to object type and a different pointer to object
                 * type.
                 */
                Spi_FlexIO_pu16BufferFullTX = (uint16 *)Spi_FlexIO_pBufferTX;
                Spi_FlexIO_u32TempXferData = (*Spi_FlexIO_pu16BufferFullTX);
                /*
                * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                Spi_FlexIO_pBufferTX += 2u;
            }
            else if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_u32DataWidthTX)
            {
                /*
                * @violates @ref Spi_FlexIO_c_REF_4 A cast should not be performed between a 
                *       pointer to object type and a different pointer to object type.
                */
                Spi_FlexIO_pu32BufferFullTX = (uint32 *)Spi_FlexIO_pBufferTX;
                Spi_FlexIO_u32TempXferData = (*Spi_FlexIO_pu32BufferFullTX);
                /*
                * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */                
                Spi_FlexIO_pBufferTX += 4u;
            }
            else
            {
                /*
                 * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
                 *  between a pointer type and an integral type.
                 */
                /*
                * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */                 
                Spi_FlexIO_u32TempXferData = (*Spi_FlexIO_pBufferTX);
                /*
                * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                */
                Spi_FlexIO_pBufferTX++;
            }
            #else
            if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_u32DataWidthTX)
            {
                #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    * @violates @ref Spi_FlexIO_c_REF_4 A cast should not be performed between a
                    *  pointer to object type and a different pointer to object type.
                    */
                    Spi_FlexIO_u32TempXferData = (uint32)(*Spi_FlexIO_pBufferTX) | ((uint32)(*(Spi_FlexIO_pBufferTX+1u)) << 16u);
                #else
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    * @violates @ref Spi_FlexIO_c_REF_4 A cast should not be performed between a
                    *  pointer to object type and a different pointer to object type.
                    */                   
                    Spi_FlexIO_u32TempXferData = ((uint32)(*Spi_FlexIO_pBufferTX) << 16u) | (uint32)(*(Spi_FlexIO_pBufferTX+1u));
                #endif
                /*
                 * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                 *       the only allowed form of pointer arithmetic.
                */
                Spi_FlexIO_pBufferTX += 4u;
            }
            else
            {
                /*
                 * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
                 * between a pointer type and an integral type.
                 */
                /*
                * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                Spi_FlexIO_u32TempXferData = (*Spi_FlexIO_pBufferTX);
                /*
                 * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                 *       the only allowed form of pointer arithmetic.
                */
                Spi_FlexIO_pBufferTX++;
            }
            #endif
        }
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pBufferTX = Spi_FlexIO_pBufferTX;      
        Spi_FlexIO_Status = (Std_ReturnType)E_NOT_OK; 
        /* Write to TX register to transmit */
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        * between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        /* Re-update data to get LSB/MSB tranfer */
        if (SPI_FLEXIO_MSB_U8 == Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8LBF)
        {
            if (SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_u32DataWidthTX)
            {
                Spi_FlexIO_u32TempXferData = Spi_FlexIO_u32TempXferData << 16u;
            }
            else if (SPI_FLEXIO_DATA_WIDTH_8 == Spi_FlexIO_u32DataWidthTX)
            {
                Spi_FlexIO_u32TempXferData = Spi_FlexIO_u32TempXferData << 24u;
            }
            else
            {
                /* Do notthing */
            }
        }
        else 
        {
            /* Do notthing */
        }
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(Spi_FlexIO_u32TDRAddress, Spi_FlexIO_u32TempXferData);
        Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthTX--;

        if (0u == (Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthTX | Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_ChannelsCountTX))
        {
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8EndOfJobFlag=(uint8)TRUE;
        }
        else
        {
            /* Do nothing */
        }
        Spi_FlexIO_Status = (Std_ReturnType)E_OK;
     }
     else
     {
         /* Do nothing */
     }
    return Spi_FlexIO_Status;   
}

/*================================================================================================*/
/**
* @brief   This function drains the FlexIO RX FIFO.
* @details This function retrieves the received data from FlexIO FIFO.
*          This function is pre compile time selectable by the
*          configuration parameter: SPI_LEVEL_DELIVERED. This function is only
*          relevant for LEVEL 0 and LEVEL 2.
*
* @param[in]     Spi_FlexIO_pSyncTransmitState   Specifies which state transmission data of job and channel
*                FlexIO_u8Sync   Specifies which this function has called by
*                               Spi_FlexIO_SyncTransmit()            : SPI_FLEXIO_SYNCTRANSMIT
*                               or Spi_FlexIO_SyncTransmit_Fast()    : SPI_FLEXIO_SYNCTRANSMIT_FAST
*
* @return Std_ReturnType
* @retval E_OK            Transmission command has been completed
* @retval E_NOT_OK        Transmission command has not been accepted
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL0 or LEVEL2
*
*/
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_FlexIO_SyncTransmitRX
(
    P2VAR(Spi_FlexIO_SyncStateType, AUTOMATIC,SPI_APPL_DATA) Spi_FlexIO_pSyncTransmitState,
    VAR(uint8, AUTOMATIC) FlexIO_u8Sync
)
{
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_RX = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8Shifter_RX;
    VAR(Std_ReturnType, AUTOMATIC) Spi_FlexIO_Status = (Std_ReturnType)E_OK;
     P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) Spi_FlexIO_pBufferRX = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pBufferRX;
     P2CONST(Spi_Ipw_FlexIOChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelAttributesCfgRX = NULL_PTR;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelConfigRX;
    P2CONST(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pChannelState;
    VAR(Spi_ChannelType, AUTOMATIC) Spi_FlexIO_ChannelRX=0u;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) Spi_FlexIO_pu16BufferFullRX;
    P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) Spi_FlexIO_pu32BufferFullRX;
#else
    VAR(uint32, AUTOMATIC) Spi_FlexIO_u32BufferFullRX;
#endif
    VAR(uint32, AUTOMATIC) Spi_FlexIO_u32DataWidthRX = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32DataWidthRX;
    /* @violates @ref Spi_FlexIO_c_REF_13 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32RDRAddress = 0;
    
    /* Get RX address */
    if(SPI_FLEXIO_LSB_U8 == Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8LBF)
    {
        Spi_FlexIO_u32RDRAddress = FLEXIO_SHIFTBUFn_ADDR32((uint32)Spi_FlexIO_u8Shifter_RX);
    }
    else if(SPI_FLEXIO_MSB_U8 == Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u8LBF)
    {
        Spi_FlexIO_u32RDRAddress = FLEXIO_SHIFTBUFBISn_ADDR32( (uint32)Spi_FlexIO_u8Shifter_RX);
    }
    else
    {
        /* Do notthing */
    }
    /* --------- Receive ---------- */
    /* there is still something to read and Receive FIFO has data */
    if (0u < Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthRX)
    {

           Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthRX--;      
           if (NULL_PTR == Spi_FlexIO_pBufferRX)
            {
                /* discard data if RX buffer is NULL_PTR */
                /*
                *  @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */                 
                Spi_FlexIO_u32ReadDiscard = (uint32)REG_READ32(Spi_FlexIO_u32RDRAddress);              
            }
            else
            {
                #if (SPI_FORCE_DATA_TYPE == STD_ON)
                if (SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_u32DataWidthRX)
                {
                     /*
                     * @violates @ref Spi_FlexIO_c_REF_4 A cast should not be
                     * performed between a pointer
                     *       to object type and a different pointer to object type.
                     */
                     Spi_FlexIO_pu16BufferFullRX = (uint16 *) Spi_FlexIO_pBufferRX;
               
                     /*
                     * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
                     *     type and an integral type.
                     */
                     /*
                     * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                     */
                     *Spi_FlexIO_pu16BufferFullRX = (uint16)REG_READ16(Spi_FlexIO_u32RDRAddress);
                     /*
                     * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                     *       the only allowed form of pointer arithmetic.
                     */                    
                     Spi_FlexIO_pBufferRX += 2u;
                }
                else if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_u32DataWidthRX)
                {
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_4 A cast should not be
                    * performed between a pointer
                    *       to object type and a different pointer to object type.
                    */
                    Spi_FlexIO_pu32BufferFullRX = (uint32 *) Spi_FlexIO_pBufferRX;
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
                    *  between a pointer type and an integral type.
                    */
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    *Spi_FlexIO_pu32BufferFullRX = (uint32)REG_READ32(Spi_FlexIO_u32RDRAddress);                 
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */                   
                    Spi_FlexIO_pBufferRX += 4u;       
                }
                else
                {
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    */
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */                        
                    *Spi_FlexIO_pBufferRX = (uint8)REG_READ8(Spi_FlexIO_u32RDRAddress);
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    Spi_FlexIO_pBufferRX++; 
                }
                #else
                if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_u32DataWidthRX)
                {
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    */
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    Spi_FlexIO_u32BufferFullRX = (uint32)REG_READ32(Spi_FlexIO_u32RDRAddress);
                    #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
                        *Spi_FlexIO_pBufferRX = (uint16)(Spi_FlexIO_u32BufferFullRX & (uint32)0x0000FFFFu);
                        /*
                        * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                        *(Spi_FlexIO_pBufferRX+1u) = (uint16)(Spi_FlexIO_u32BufferFullRX >> 16u);
                    #else
                        *Spi_FlexIO_pBufferRX = (uint16)(Spi_FlexIO_u32BufferFullRX >> 16u);
                        /*
                        * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                        *(Spi_FlexIO_pBufferRX+1u) = (uint16)(Spi_FlexIO_u32BufferFullRX & (uint32)0x0000FFFFu);
                    #endif 
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */                     
                    Spi_FlexIO_pBufferRX += 2u;
                }
                else
                {
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    */
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                      *Spi_FlexIO_pBufferRX = (Spi_DataBufferType)REG_READ16(Spi_FlexIO_u32RDRAddress);
                      /*
                    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                     Spi_FlexIO_pBufferRX++;  
                }                        
                #endif
            }
            /* update Spi_FlexIO_pBufferRX */
            Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pBufferRX = Spi_FlexIO_pBufferRX;
            
            if((0u == Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthRX) && (0u < Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_ChannelsCountRX))
            {
                /* Update channel count RX */
                Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_ChannelsCountRX--;
                if(SPI_FLEXIO_SYNCTRANSMIT == FlexIO_u8Sync)
                {
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pcChannelIndexListRX++;
                    /* Get the channel ID & configuration */
                    Spi_FlexIO_ChannelRX = *Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pcChannelIndexListRX;
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                    */
                    Spi_FlexIO_pcChannelAttributesCfgRX = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcFlexIOChannelAttributesConfig[Spi_FlexIO_ChannelRX];
                    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32DataWidthRX = Spi_FlexIO_pcChannelAttributesCfgRX->u32DataWidth;
                    Spi_FlexIO_u32DataWidthRX = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32DataWidthRX;
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                    */
                    Spi_FlexIO_pcChannelConfigRX = &Spi_pcSpiConfigPtr->pcChannelConfig[Spi_FlexIO_ChannelRX];
                    Spi_FlexIO_pChannelState = Spi_FlexIO_pcChannelConfigRX->pChannelState;
                    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthRX = Spi_FlexIO_pChannelState->Length;
                    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pBufferRX = Spi_FlexIO_pcChannelConfigRX->pcBufferDescriptor->pBufferRX;
                }
                else
                {
                    #if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pChannelRX++;
                    /* retrieve RX buffers and the received length */
                    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthRX = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pChannelRX->FlexIO_pState->Length;
                    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pBufferRX = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pChannelRX->FlexIO_pcBufferDescriptor->pBufferRX; 
                    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32DataWidthRX = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_pChannelRX->u32DataWidth;
                    Spi_FlexIO_u32DataWidthRX = Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_u32DataWidthRX;
                    #endif
                }
                #if (SPI_FORCE_DATA_TYPE == STD_ON)
                if (SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_u32DataWidthRX)
                {
                    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthRX /= 2u;
                }
                else if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_u32DataWidthRX)
                {
                    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthRX /= 4u;
                }
                else
                {
                    /* Do nothing */
                }
                #else
                if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_u32DataWidthRX)
                {
                    Spi_FlexIO_pSyncTransmitState->Spi_FlexIO_LengthRX /= 2u;
                }
                else
                {
                    /* Do nothing */
                }
                #endif
            }
        Spi_FlexIO_Status = (Std_ReturnType)E_OK;
    }
    else
    {
        /* Do nothing */
    }
    return Spi_FlexIO_Status; 
     
}
#endif
/*================================================================================================*/
/*================================================================================================*/

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_ChannelTransferDmaInitTX_MclDmaSetup
    (
        P2VAR(Mcl_DmaTcdType, AUTOMATIC, SPI_APPL_DATA) Spi_FlexIO_pTxTcdAddr,
        P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelConfig,
        P2CONST(Spi_Ipw_FlexIOChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelAttributesConfig,
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev
    )
    
{
     P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) Spi_FlexIO_pBufferTX;
 
    P2CONST(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pChannelState = Spi_FlexIO_pcChannelConfig->pChannelState;
    
    if (0u != (Spi_FlexIO_pChannelState->u8Flags & ((uint8)SPI_CHANNEL_FLAG_TX_DEFAULT_U8)))
    {
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            /* overwrite the default src next offset */
            /* 2 bytes src transfer size, 2 bytes dest transfer size */
            Mcl_DmaTcdSetSModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            Mcl_DmaTcdSetDModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            /* dest address */
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
            *  between a pointer type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */            
            Mcl_DmaTcdSetSaddr(Spi_FlexIO_pTxTcdAddr, (uint32)(&Spi_FlexIO_pcChannelConfig->u32DefaultTransmitValue));
            /* dest address */
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                to the function as an unsigned integer*/
            if (SPI_FLEXIO_LSB_U8 == Spi_FlexIO_pcChannelAttributesConfig->u8LBF)
            {
                Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress);
            }
            else
            {
                Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress+2u);
            }            
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(Spi_FlexIO_pTxTcdAddr, (uint32)(&Spi_FlexIO_pcChannelConfig->u32DefaultTransmitValue)+2u);
            /* dest address */
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                to the function as an unsigned integer*/
            if (SPI_FLEXIO_LSB_U8 == Spi_FlexIO_pcChannelAttributesConfig->u8LBF)
            {
                Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress+2u);
            }
            else
            {
                Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress);
            }
            #endif
            /* 2 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(Spi_FlexIO_pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x02u));
        }
        else if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            /* overwrite the default src next offset */
            /* 4 bytes src transfer size, 4 bytes dest transfer size */
            Mcl_DmaTcdSetSModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_4BYTES);
            Mcl_DmaTcdSetDModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_4BYTES);
            /* dest address */
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
            *  between a pointer type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */            
            Mcl_DmaTcdSetSaddr(Spi_FlexIO_pTxTcdAddr, (uint32)(&Spi_FlexIO_pcChannelConfig->u32DefaultTransmitValue));
            /* dest address */
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress);
            /* 4 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(Spi_FlexIO_pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x04u));
        }
        else
        {
            /* overwrite the default src next offset */
            /* 1 bytes src transfer size, 1 bytes dest transfer size */
            Mcl_DmaTcdSetSModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);
            Mcl_DmaTcdSetDModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);
            /* dest address */
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
            *  between a pointer type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetSaddr(Spi_FlexIO_pTxTcdAddr, (uint32)(&Spi_FlexIO_pcChannelConfig->u32DefaultTransmitValue));
            /* dest address */
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress);
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(Spi_FlexIO_pTxTcdAddr, (uint32)(&Spi_FlexIO_pcChannelConfig->u32DefaultTransmitValue)+3u);
            /* dest address */
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress+3u);
            #endif
            /* 1 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(Spi_FlexIO_pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x01u));
        }
    #else
        if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            /* overwrite the default src next offset */
            /* 4 bytes src transfer size, 4 bytes dest transfer size */
            Mcl_DmaTcdSetSModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_4BYTES);
            Mcl_DmaTcdSetDModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_4BYTES);
            /* dest address */
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
            *  between a pointer type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */ 
            Mcl_DmaTcdSetSaddr(Spi_FlexIO_pTxTcdAddr, (uint32)(&Spi_FlexIO_pcChannelConfig->u32DefaultTransmitValue));
            /* dest address */
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress);            
            /* 4 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(Spi_FlexIO_pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x04u));
        }
        else
        {
            /* overwrite the default src next offset */
            /* 2 bytes src transfer size, 2 bytes dest transfer size */
            Mcl_DmaTcdSetSModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            Mcl_DmaTcdSetDModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            /* dest address */
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
            *  between a pointer type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */ 
            Mcl_DmaTcdSetSaddr(Spi_FlexIO_pTxTcdAddr, (uint32)(&Spi_FlexIO_pcChannelConfig->u32DefaultTransmitValue));
            /* dest address */
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress);
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(Spi_FlexIO_pTxTcdAddr, (uint32)(&Spi_FlexIO_pcChannelConfig->u32DefaultTransmitValue)+2u);
            /* dest address */
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress+2);
            #endif
            /* 2 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(Spi_FlexIO_pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x02u));
        }
    #endif

        /* overwrite the default src next offset */
        /* 1 bytes src offset */
        Mcl_DmaTcdSetSoff(Spi_FlexIO_pTxTcdAddr, (sint16)0u);
        Mcl_DmaTcdSetDoff(Spi_FlexIO_pTxTcdAddr, (sint16)0u);
    }
    else
    {
        Spi_FlexIO_pBufferTX = Spi_FlexIO_pcChannelConfig->pcBufferDescriptor->pBufferTX;

        /* configure TX Channel 1 to write data frames (8 or 16bits - depending on Spy_DataType) to
           u32TxDmaBuffer */
        /* Compiler_Warning: It is intended for the address of the element to be passed
                              to the function as an unsigned integer*/
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetSaddr(Spi_FlexIO_pTxTcdAddr, (uint32)Spi_FlexIO_pBufferTX);
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            /* overwrite the default src next offset */
            /* 2 bytes src transfer size, 2 bytes dest transfer size */
            /* 2 bytes src offset */
            Mcl_DmaTcdSetSoff(Spi_FlexIO_pTxTcdAddr, (sint16)2u);
            Mcl_DmaTcdSetSModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            Mcl_DmaTcdSetDModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            /* dest address */
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            if (SPI_FLEXIO_LSB_U8 == Spi_FlexIO_pcChannelAttributesConfig->u8LBF)
            {
                Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress);
            }
            else
            {
                Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress+2u);
            }
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            if (SPI_FLEXIO_LSB_U8 == Spi_FlexIO_pcChannelAttributesConfig->u8LBF)
            {
                Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress+2u);
            }
            else
            {
                Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress);
            }
            #endif
            /* 2 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(Spi_FlexIO_pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x02u));
        }
        else if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            /* overwrite the default src next offset */
            /* 4 bytes src transfer size, 4 bytes dest transfer size */
            /* 4 bytes src offset */
            Mcl_DmaTcdSetSoff(Spi_FlexIO_pTxTcdAddr, (sint16)4u);
            Mcl_DmaTcdSetSModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_4BYTES);
            Mcl_DmaTcdSetDModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_4BYTES);
            /* dest address */
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress);
            /* 4 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(Spi_FlexIO_pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x04u));
        }
        else
        {
            /* overwrite the default src next offset */
            /* 1 bytes src transfer size, 1 bytes dest transfer size */
            /* 1 bytes src offset */
            Mcl_DmaTcdSetSoff(Spi_FlexIO_pTxTcdAddr, (sint16)1u);
            Mcl_DmaTcdSetSModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);
            Mcl_DmaTcdSetDModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);
            /* dest address */
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress);
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress+3u);
            #endif
            /* 1 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(Spi_FlexIO_pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x01u));
        }
    #else
        if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            /* overwrite the default src next offset */
            /* 4 bytes src transfer size, 4 bytes dest transfer size */
            /* 4 bytes src offset */
            Mcl_DmaTcdSetSoff(Spi_FlexIO_pTxTcdAddr, (sint16)2u);
            Mcl_DmaTcdSetSModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            Mcl_DmaTcdSetDModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            /* dest address */
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress);
            /* 4 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(Spi_FlexIO_pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x02u));
        }
        else
        {
            /* overwrite the default src next offset */
            /* 1 bytes src transfer size, 1 bytes dest transfer size */
            /* 1 bytes src offset */
            Mcl_DmaTcdSetSoff(Spi_FlexIO_pTxTcdAddr, (sint16)2u);
            Mcl_DmaTcdSetSModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            Mcl_DmaTcdSetDModuloAndSize(Spi_FlexIO_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            /* dest address */
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress);
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(Spi_FlexIO_pTxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32TDRAddress+2u);
            #endif
            /* 1 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(Spi_FlexIO_pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x02u));
        }
    #endif
        Mcl_DmaTcdSetDoff(Spi_FlexIO_pTxTcdAddr, (sint16)0u);
    }
/*
* @violates @ref Spi_FlexIO_c_REF_15 A pointer parameter in a function prototype should be declared
* as pointer to const if the pointer is not used to modify the addressed object.
*/        
}
#endif

/*================================================================================================*/
/**
* @param[in]     FlexIO_pDev     Specifies device involved in transmission
* @param[in]     Channel     ID of the channel to be transmited.
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_ChannelTransferDmaInitTX 
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
( \
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev, \
        VAR(Spi_ChannelType, AUTOMATIC) Channel \
) \
{
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcHWUnitConfig;
    P2CONST(Spi_Ipw_FlexIOChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelAttributesConfig;
    /*
    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelConfig = &Spi_pcSpiConfigPtr->pcChannelConfig[Channel];
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcJobConfig = FlexIO_pDev->Spi_FlexIO_pcCurrentJob;
    P2CONST(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pChannelState = Spi_FlexIO_pcChannelConfig->pChannelState;
    P2VAR(Spi_FlexIO_SyncStateType, AUTOMATIC,SPI_APPL_DATA) Spi_FlexIO_pAsyncTransmitState;
    VAR(Spi_NumberOfDataType, AUTOMATIC) Spi_FlexIO_FramesCount;
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, SPI_APPL_DATA) Spi_FlexIO_pTxTcdAddr = FlexIO_pDev->Spi_FlexIO_pu32TxDmaTcd;
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_TX = 0u;
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_RX = 0u;    
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CLK = 0u;    
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CS = 0u;
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8TRGSEL = 0u;    
    
    Spi_FlexIO_pcHWUnitConfig = FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig;
    /* External device attributes */
    /*
    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    Spi_FlexIO_pcChannelAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcFlexIOChannelAttributesConfig[Channel];
    Spi_FlexIO_pAsyncTransmitState = &Spi_FlexIO_SyncTransmitState[FlexIO_pDev->Spi_HWUnit];
    /* Get TX, RX, CLK, CS channel offset */
    Spi_FlexIO_u8Shifter_TX = Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_TX;
    Spi_FlexIO_u8Shifter_RX = Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_RX;
    Spi_FlexIO_u8Timer_CLK = Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_CLK;
    Spi_FlexIO_u8Timer_CS = Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_CS;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32BaseAddress = (uint32)FLEXIO_BASEADDR;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8CPOL   = FlexIO_pDev->Spi_FlexIO_u8DeviceStateCPOL;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8CPHA   = FlexIO_pDev->Spi_FlexIO_u8DeviceStateCPHA;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32FSIZE  = Spi_FlexIO_pcChannelAttributesConfig->u32NumBitsInFrame;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8LBF    = Spi_FlexIO_pcChannelAttributesConfig->u8LBF;
#if (SPI_DUAL_CLOCK_MODE == STD_ON)    
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32PSC[0]    = FlexIO_pDev->Spi_FlexIO_u32DeviceStatePSC[0];
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32PSC[1]    = FlexIO_pDev->Spi_FlexIO_u32DeviceStatePSC[1];
#else
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32PSC    = FlexIO_pDev->Spi_FlexIO_u32DeviceStatePSC;    
#endif
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_MASTER =  Spi_FlexIO_pcHWUnitConfig->eSpiPhyUnitMode;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] = 0x0u;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_RX] = 0x0u;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX] = 0x0u;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX] = 0x0u;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]   = 0x0u;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CS]   = 0x0u;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK]   = 0x0u;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CS]   = 0x0u;
    /* Trigger select for timer clock */
    Spi_FlexIO_u8TRGSEL = (4u*Spi_FlexIO_u8Shifter_TX) + 1u;
    /* Get Shifter, Timer config data */
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32ShifterCFGConfigTX;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_RX] |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32ShifterCFGConfigRX;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX] |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32ShifterCTLConfigTX;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX] |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32ShifterCTLConfigRX;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]   |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCMPConfigCLK;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CS]   |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCMPConfigCS;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK]   |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCTLConfigCLK;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CS]   |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCTLConfigCS;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]   |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCFGConfigCLK;   
    /* Check Master mode */    
    if(SPI_MASTER == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_MASTER)
    {
        /* CPHA config */
        if(SPI_FLEXIO_CPHA_TRAILING_U8 == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8CPHA)
        {
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCFG_CPHA0_U32; 
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCTL_TIMPOL_U32;
        }
        else if(SPI_FLEXIO_CPHA_LEADING_U8 == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8CPHA)
        {                
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCFG_CPHA1_U32; 
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX] |= SPI_FLEXIO_SHIFTCTL_TIMPOL_U32; 
        }
        else
        {
            /*Do notthing*/
        }
        /* CLK Polarity */
        if(SPI_FLEXIO_CPOL_HIGH_U8 == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8CPOL)
        {
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK] |= SPI_FLEXIO_SHIFTCTL_PINPOL_HIGH_U32;
        }
        else
        {
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK] |= SPI_FLEXIO_SHIFTCTL_PINPOL_LOW_U32;
        }
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]  |= Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32PSC[Spi_FlexIO_ClockMode];
#else
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]  |= Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32PSC;
#endif
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]  |= (Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32FSIZE) << 8;
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]  |= SPI_FLEXIO_TIMCFG_CLK_MASTER_U32;
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CS]  |= SPI_FLEXIO_TIMCFG_CS_MASTER_U32;
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CS]  |= SPI_FLEXIO_TIMCMP_RWBITS_U32;
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK]  |= (uint32)Spi_FlexIO_u8TRGSEL << 24;
    }
    else
    {
        if(SPI_FLEXIO_CPHA_TRAILING_U8 == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8CPHA)
        {
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCFG_CPHA0_U32; 
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCTL_TIMPOL_U32;
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]    |= SPI_FLEXIO_TIMCFG_CLK_CS_SLAVE_U32; 
        }
        else if(SPI_FLEXIO_CPHA_LEADING_U8 == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8CPHA)
        {
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCFG_CPHA1_U32; 
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX] |= SPI_FLEXIO_SHIFTCTL_TIMPOL_U32; 
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]    |= SPI_FLEXIO_TIMCFG_CLK_CS_SLAVE_CPHA1_U32; 
        }
        else
        {
            /*Do notthing*/
        }
        /* CLK Polarity */
        if(SPI_FLEXIO_CPOL_HIGH_U8 == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8CPOL)
        {
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK] |= SPI_FLEXIO_SHIFTCTL_PINPOL_HIGH_U32;
        }
        else
        {
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK] |= SPI_FLEXIO_SHIFTCTL_PINPOL_LOW_U32;
        }
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]  |= (Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32FSIZE);
    }
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(FLEXIO_SHIFTCFGn_ADDR32((uint32)Spi_FlexIO_u8Shifter_TX),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX]);
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(FLEXIO_SHIFTCTLn_ADDR32((uint32)Spi_FlexIO_u8Shifter_TX),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX]);
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */    
    REG_WRITE32(FLEXIO_SHIFTCFGn_ADDR32((uint32)Spi_FlexIO_u8Shifter_RX),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_RX]);
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */   
    REG_WRITE32(FLEXIO_SHIFTCTLn_ADDR32((uint32)Spi_FlexIO_u8Shifter_RX),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX]);  
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */    
    if(SPI_MASTER == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_MASTER)
    {
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]); 
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)Spi_FlexIO_u8Timer_CS),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CS]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32)Spi_FlexIO_u8Timer_CS),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CS]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32)Spi_FlexIO_u8Timer_CS),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CS]);                
    }
    else
    {
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]); 
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */        
        REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK]);
    }     
    if(SPI_FLEXIO_LSB_U8 == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8LBF)
    {
        FlexIO_pDev->Spi_FlexIO_u32TDRAddress = FLEXIO_SHIFTBUFn_ADDR32((uint32)Spi_FlexIO_u8Shifter_TX);
        FlexIO_pDev->Spi_FlexIO_u32RDRAddress = FLEXIO_SHIFTBUFn_ADDR32((uint32)Spi_FlexIO_u8Shifter_RX);
    }
    else if(SPI_FLEXIO_MSB_U8 == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8LBF)
    {
        if (SPI_FLEXIO_DATA_WIDTH_8 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            FlexIO_pDev->Spi_FlexIO_u32TDRAddress = FLEXIO_SHIFTBUFBBSn_ADDR32((uint32)Spi_FlexIO_u8Shifter_TX);
            FlexIO_pDev->Spi_FlexIO_u32RDRAddress = FLEXIO_SHIFTBUFBBSn_ADDR32((uint32)Spi_FlexIO_u8Shifter_RX);
        }
        else
        {
            FlexIO_pDev->Spi_FlexIO_u32TDRAddress = FLEXIO_SHIFTBUFBISn_ADDR32((uint32)Spi_FlexIO_u8Shifter_TX);
            FlexIO_pDev->Spi_FlexIO_u32RDRAddress = FLEXIO_SHIFTBUFBISn_ADDR32((uint32)Spi_FlexIO_u8Shifter_RX);
        }
    }
    else
    {
        /* Do nothting */
    }
    Spi_FlexIO_FramesCount = Spi_FlexIO_pChannelState->Length;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    if (SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        Spi_FlexIO_FramesCount /= 2u;
    }
    else if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        Spi_FlexIO_FramesCount /= 4u;
    }
    else
    {
        /* Do nothing */
    }
#else
    if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        Spi_FlexIO_FramesCount /=2u;
    }
    else
    {
        /* Do nothing */
    }
#endif

    Spi_FlexIO_ChannelTransferDmaInitTX_MclDmaSetup
    (
        Spi_FlexIO_pTxTcdAddr, Spi_FlexIO_pcChannelConfig, Spi_FlexIO_pcChannelAttributesConfig, FlexIO_pDev
    );

    /* get the number of frames to be sent through DMA */
    if ( SPI_FLEXIO_DMA_MAX_LINKED_ITER_CNT < Spi_FlexIO_FramesCount)
    {
        /* DMA iteration count is on 9 bits, if e_link field is used */
        FlexIO_pDev->Spi_FlexIO_RemainingData = Spi_FlexIO_FramesCount - SPI_FLEXIO_DMA_MAX_LINKED_ITER_CNT;
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            FlexIO_pDev->Spi_FlexIO_RemainingData *= 2u;
        }
        else if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            FlexIO_pDev->Spi_FlexIO_RemainingData *= 4u;
        }
        else
        {
            /* Do nothing */
        }
    #else
        if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            FlexIO_pDev->Spi_FlexIO_RemainingData *= 2u;
        }
        else
        {
            /* Do nothing */
        }
    #endif
        Spi_FlexIO_FramesCount = SPI_FLEXIO_DMA_MAX_LINKED_ITER_CNT;
        Mcl_DmaTcdSetIterCount(Spi_FlexIO_pTxTcdAddr, (uint16)(Spi_FlexIO_FramesCount)); 
    }
    else
    {
        Mcl_DmaTcdSetIterCount(Spi_FlexIO_pTxTcdAddr, (uint16)(Spi_FlexIO_FramesCount)); 
        FlexIO_pDev->Spi_FlexIO_RemainingData = 0u;
    }
    /* Shifter Status Interrupt Enable */
    Mcl_Flexio_WriteShiftSden((uint8)(1U << Spi_FlexIO_u8Shifter_TX), (uint8)(1U << Spi_FlexIO_u8Shifter_TX));
    Mcl_Flexio_WriteShiftSden((uint8)(1U << Spi_FlexIO_u8Shifter_RX), (uint8)(1U << Spi_FlexIO_u8Shifter_RX));
}
#endif

/*================================================================================================*/
/**
* @param[in]     FlexIO_pDev     Specifies device involved in transmission
* @param[in]     Channel     ID of the channel to be transmited.
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/ 
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_ChannelTransferDmaInitRX
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
(
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev, 
        VAR(Spi_ChannelType, AUTOMATIC) Channel 
)
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/ 
{
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcHWUnitConfig;
    P2CONST(Spi_Ipw_FlexIOChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelAttributesConfig;
    /*
    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelConfig = &Spi_pcSpiConfigPtr->pcChannelConfig[Channel];
    P2CONST(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pChannelState = Spi_FlexIO_pcChannelConfig->pChannelState;
     P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) Spi_FlexIO_pBufferRX;
     VAR(Spi_NumberOfDataType, AUTOMATIC) Spi_FlexIO_FramesCount;
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, SPI_APPL_DATA) Spi_FlexIO_pRxTcdAddr = FlexIO_pDev->Spi_FlexIO_pu32RxDmaTcd;
    
    /* Set the TCR parameters for this channel */
    /*
    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    Spi_FlexIO_pcChannelAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcFlexIOChannelAttributesConfig[Channel];
    Spi_FlexIO_pcHWUnitConfig = FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig;
    
    Spi_FlexIO_FramesCount = Spi_FlexIO_pChannelState->Length ;
    
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    if (SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        Spi_FlexIO_FramesCount /= 2u;
    }
    else if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        Spi_FlexIO_FramesCount /= 4u;
    }
    else
    {
        /* Do nothing */
    }
#else
    if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        Spi_FlexIO_FramesCount /= 2u;
    }
    else
    {
        /* Do nothing */
    }
#endif
    /* get the number of frames to be sent through DMA */
    if ( SPI_FLEXIO_DMA_MAX_LINKED_ITER_CNT < Spi_FlexIO_FramesCount)
    {
        /* DMA iteration count is on 9 bits, if e_link field is used */
        FlexIO_pDev->Spi_FlexIO_ReceivedData = Spi_FlexIO_FramesCount - SPI_FLEXIO_DMA_MAX_LINKED_ITER_CNT;
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            FlexIO_pDev->Spi_FlexIO_ReceivedData *= 2u;
        }
        else if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            FlexIO_pDev->Spi_FlexIO_ReceivedData *= 4u;
        }
        else
        {
            /* Do nothing */
        }
    #else
        if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            FlexIO_pDev->Spi_FlexIO_ReceivedData *= 2u;
        }
        else
        {
            /* Do nothing */
        }
    #endif
        Spi_FlexIO_FramesCount = SPI_FLEXIO_DMA_MAX_LINKED_ITER_CNT;
    }
    else
    {
        FlexIO_pDev->Spi_FlexIO_ReceivedData = 0u;
    }
    /* Configure RX DMA descriptor */
    /* Rx buffer will be NULL if discarding read values */
    Spi_FlexIO_pBufferRX = Spi_FlexIO_pcChannelConfig->pcBufferDescriptor->pBufferRX;
    if (NULL_PTR == Spi_FlexIO_pBufferRX)
    {
        /* dest address - discard read */
        /* Compiler_Warning: It is intended for the address of the element to be passed
                              to the function as an unsigned integer*/
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetDaddr(Spi_FlexIO_pRxTcdAddr, (uint32) &Spi_FlexIO_u32ReadDiscard);
        /* update RX transfer size; 1bytes offset for destination address */
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */        
        Mcl_DmaTcdSetIterCount(Spi_FlexIO_pRxTcdAddr, (uint16)(Spi_FlexIO_FramesCount));
        Mcl_DmaTcdSetDoff(Spi_FlexIO_pRxTcdAddr, (sint16)0u);
    #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
        /* Compiler_Warning: It is intended for the address of the element to be passed
                          to the function as an unsigned integer*/
        Mcl_DmaTcdSetSaddr(Spi_FlexIO_pRxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32RDRAddress+3u);
    #else
        /* Compiler_Warning: It is intended for the address of the element to be passed
                            to the function as an unsigned integer*/
        Mcl_DmaTcdSetSaddr(Spi_FlexIO_pRxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32RDRAddress);
    #endif
        /* overwrite the default src next offset */
        /* 1 bytes src transfer size, 1 bytes dest transfer size */
        /* no src offset */
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */       
        Mcl_DmaTcdSetSoff(Spi_FlexIO_pRxTcdAddr, (sint16)0u);
        Mcl_DmaTcdSetSModuloAndSize(Spi_FlexIO_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE );
        Mcl_DmaTcdSetDModuloAndSize(Spi_FlexIO_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);
        /* 1 bytes to transfer */
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetMinorLoop(Spi_FlexIO_pRxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x01u));
    }
    else
    {
        /* dest address - RX buffer */
        /* Compiler_Warning: It is intended for the address of the element to be passed
                              to the function as an unsigned integer*/
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */

        Mcl_DmaTcdSetDaddr(Spi_FlexIO_pRxTcdAddr, (uint32)Spi_FlexIO_pBufferRX);
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            /* update RX transfer size; 2bytes offset for destination address */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetIterCount(Spi_FlexIO_pRxTcdAddr, (uint16)(Spi_FlexIO_FramesCount));
            Mcl_DmaTcdSetDoff(Spi_FlexIO_pRxTcdAddr, (sint16)2u);
        #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            if (SPI_FLEXIO_LSB_U8 == Spi_FlexIO_pcChannelAttributesConfig->u8LBF)
            {
                Mcl_DmaTcdSetSaddr(Spi_FlexIO_pRxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32RDRAddress+2u);
            }
            else
            {
                Mcl_DmaTcdSetSaddr(Spi_FlexIO_pRxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32RDRAddress);
            }
        #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            if (SPI_FLEXIO_LSB_U8 == Spi_FlexIO_pcChannelAttributesConfig->u8LBF)
            {
                Mcl_DmaTcdSetSaddr(Spi_FlexIO_pRxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32RDRAddress);
            }
            else
            {
                Mcl_DmaTcdSetSaddr(Spi_FlexIO_pRxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32RDRAddress+2u);
            }
        #endif
            /* overwrite the default src next offset */
            /* 2 bytes src transfer size, 2 bytes dest transfer size */
            /* no src offset */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */           
            Mcl_DmaTcdSetSoff(Spi_FlexIO_pRxTcdAddr, (sint16)0u);
            Mcl_DmaTcdSetSModuloAndSize(Spi_FlexIO_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            Mcl_DmaTcdSetDModuloAndSize(Spi_FlexIO_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            /* 2 bytes to transfer */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetMinorLoop(Spi_FlexIO_pRxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x02u));
        }
        else if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            /* update RX transfer size; 4bytes offset for destination address */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetIterCount(Spi_FlexIO_pRxTcdAddr, (uint16)(Spi_FlexIO_FramesCount));
            Mcl_DmaTcdSetDoff(Spi_FlexIO_pRxTcdAddr, (sint16)4u);
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(Spi_FlexIO_pRxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32RDRAddress);
            /* overwrite the default src next offset */
            /* 4 bytes src transfer size, 4 bytes dest transfer size */
            /* no src offset */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetSoff(Spi_FlexIO_pRxTcdAddr, (sint16)0u);
            Mcl_DmaTcdSetSModuloAndSize(Spi_FlexIO_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_4BYTES);
            Mcl_DmaTcdSetDModuloAndSize(Spi_FlexIO_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_4BYTES);
            /* 4 bytes to transfer */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */           
            Mcl_DmaTcdSetMinorLoop(Spi_FlexIO_pRxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x04u));
        }
        else
        {
            /* update RX transfer size; 1bytes offset for destination address */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetIterCount(Spi_FlexIO_pRxTcdAddr, (uint16)(Spi_FlexIO_FramesCount));
            Mcl_DmaTcdSetDoff(Spi_FlexIO_pRxTcdAddr, (sint16)1u);
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(Spi_FlexIO_pRxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32RDRAddress+3u);
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(Spi_FlexIO_pRxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32RDRAddress);
            #endif
            /* overwrite the default src next offset */
            /* 1 bytes src transfer size, 1 bytes dest transfer size */
            /* no src offset */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetSoff(Spi_FlexIO_pRxTcdAddr, (sint16)0u);
            Mcl_DmaTcdSetSModuloAndSize(Spi_FlexIO_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE );
            Mcl_DmaTcdSetDModuloAndSize(Spi_FlexIO_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);
            /* 1 bytes to transfer */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetMinorLoop(Spi_FlexIO_pRxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x01u));
        }
    #else
        if (SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            /* update RX transfer size; 4bytes offset for destination address */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */            
            Mcl_DmaTcdSetIterCount(Spi_FlexIO_pRxTcdAddr, (uint16)(Spi_FlexIO_FramesCount));
            Mcl_DmaTcdSetDoff(Spi_FlexIO_pRxTcdAddr, (sint16)4u);
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(Spi_FlexIO_pRxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32RDRAddress);
            /* overwrite the default src next offset */
            /* 4 bytes src transfer size, 4 bytes dest transfer size */
            /* no src offset */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetSoff(Spi_FlexIO_pRxTcdAddr, (sint16)0u);
            Mcl_DmaTcdSetSModuloAndSize(Spi_FlexIO_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_4BYTES);
            Mcl_DmaTcdSetDModuloAndSize(Spi_FlexIO_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_4BYTES);
            /* 4 bytes to transfer */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */            
            Mcl_DmaTcdSetMinorLoop(Spi_FlexIO_pRxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x04u));
        }
        else
        {
            /* update RX transfer size; 1bytes offset for destination address */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetIterCount(Spi_FlexIO_pRxTcdAddr, (uint16)(Spi_FlexIO_FramesCount));
            Mcl_DmaTcdSetDoff(Spi_FlexIO_pRxTcdAddr, (sint16)2u);
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(Spi_FlexIO_pRxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32RDRAddress+2u);
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(Spi_FlexIO_pRxTcdAddr, FlexIO_pDev->Spi_FlexIO_u32RDRAddress);
            #endif
            /* overwrite the default src next offset */
            /* 1 bytes src transfer size, 1 bytes dest transfer size */
            /* no src offset */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetSoff(Spi_FlexIO_pRxTcdAddr, (sint16)0u);
            Mcl_DmaTcdSetSModuloAndSize(Spi_FlexIO_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES );
            Mcl_DmaTcdSetDModuloAndSize(Spi_FlexIO_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            /* 1 bytes to transfer */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetMinorLoop(Spi_FlexIO_pRxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x02u));
        }            
    #endif
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetIterCount(Spi_FlexIO_pRxTcdAddr, (uint16)(Spi_FlexIO_FramesCount));        
    }
  
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Mcl_DmaEnableHwRequest(Spi_FlexIO_pcHWUnitConfig->u8RxDmaChannel);
    Mcl_DmaEnableHwRequest(Spi_FlexIO_pcHWUnitConfig->u8TxDmaChannel);
    
}
#endif

/*================================================================================================*/
/**
* @brief   This function sets the Job's attributes and send all the data through the SPI bus.
* @details This function is in charge to setup the Job attribute,
*          and to send all data though the SPI Bus.
*
* @param[in]     pcJobConfig    Specifies the Job for which we will set the
*                            register values
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_FlexIO_JobTransfer
(
     P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig
)
{
    
    P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev = &Spi_FlexIO_aDeviceState[pcJobConfig->HWUnit];
    P2CONST(Spi_ChannelType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelList = pcJobConfig->pcChannelIndexList;
    
    FlexIO_pDev->Spi_HWUnit = pcJobConfig->HWUnit;
    /* start job notification to assert the non-cs pin,
        when non-cs pin is used as chipselect*/
    if (NULL_PTR != pcJobConfig->pfStartNotification)
    {
        pcJobConfig->pfStartNotification();
    }
    else
    {
        /* Do nothing */
    }
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type. */
    FlexIO_pDev->Spi_FlexIO_u8FirstChannelOfJobFlag=(uint8)TRUE;
    /* initialize starting channel index */
    FlexIO_pDev->Spi_FlexIO_pcCurrentChannelIndexPointerTX = Spi_FlexIO_pcChannelList;
    FlexIO_pDev->Spi_FlexIO_pcCurrentChannelIndexPointerRX = Spi_FlexIO_pcChannelList;
    FlexIO_pDev->Spi_FlexIO_RemainingChannelsTX = pcJobConfig->NumChannels - (Spi_ChannelType) 1u;
    FlexIO_pDev->Spi_FlexIO_RemainingChannelsRX = pcJobConfig->NumChannels - (Spi_ChannelType) 1u;
    /* Get CPOL, CPHA, PSC for each job */
    FlexIO_pDev->Spi_FlexIO_u8DeviceStateCPOL = (*pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u8CPOL;
    FlexIO_pDev->Spi_FlexIO_u8DeviceStateCPHA = (*pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u8CPHA;
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    FlexIO_pDev->Spi_FlexIO_u32DeviceStatePSC[0] = (*pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32PSC[0];
    FlexIO_pDev->Spi_FlexIO_u32DeviceStatePSC[1] = (*pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32PSC[1];
#else
    FlexIO_pDev->Spi_FlexIO_u32DeviceStatePSC = (*pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32PSC;
#endif
    /* memorize the current job */
    FlexIO_pDev->Spi_FlexIO_pcCurrentJob = pcJobConfig;
 #if (SPI_DMA_USED == STD_ON)   
    if (0u != FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u16UseDma)
    {
        FlexIO_pDev->Spi_FlexIO_bIsEndOfJob = (boolean)FALSE;
        /* initialize the transfer parameters for the first channel */
        Spi_FlexIO_ChannelTransferDmaInitTX(FlexIO_pDev, *Spi_FlexIO_pcChannelList);
        Spi_FlexIO_ChannelTransferDmaInitRX(FlexIO_pDev, *Spi_FlexIO_pcChannelList);
    }
    else
    {
 #endif       
        FlexIO_pDev->Spi_FlexIO_bIsEndOfJob = (boolean)FALSE;
        /* initialize the transfer parameters for the first channel */
        Spi_FlexIO_ChannelTransferFifoInitRX(FlexIO_pDev, *Spi_FlexIO_pcChannelList);
        Spi_FlexIO_ChannelTransferFifoInitTX(FlexIO_pDev, *Spi_FlexIO_pcChannelList);
#if (SPI_DMA_USED == STD_ON)  
    }
#endif  


 
}
#endif
 
/*================================================================================================*/
/**
* @brief   Configures DMA interrupts for the Rx channel.
* @details Activate RX channel interrupt in interrupt mode or disable then
*          in polling mode.
*
* @param[in]     FlexIO_pDev     LLD instance of the given FlexIO peripheral.
* @param[in]     AsyncMode   Operation mode (SPI_INTERRUPT_MODE | SPI_POLLING_MODE).
*
*/
/*================================================================================================*/ 
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_DmaIrqConfig \
    ( \
        P2CONST(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_CONST) FlexIO_pDev, \
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode \
    ) \
{
    /* start RX before TX! */
    if (SPI_INTERRUPT_MODE == AsyncMode)
    {
        Mcl_DmaTcdSetIntMaj(FlexIO_pDev->Spi_FlexIO_pu32RxDmaTcd);
        Mcl_DmaTcdSetIntMaj(FlexIO_pDev->Spi_FlexIO_pu32TxDmaTcd);
    }
    else
    {
        Mcl_DmaTcdClearIntMaj(FlexIO_pDev->Spi_FlexIO_pu32TxDmaTcd);
        Mcl_DmaTcdClearIntMaj(FlexIO_pDev->Spi_FlexIO_pu32RxDmaTcd);
    }
}
#endif /* (SPI_DMA_USED == STD_ON) */  
  
  
/*================================================================================================*/
/**
* @brief   IRQ configure functions.
* @details Activate/deactivate TDF, RDF interrupts for async HWUnit according to
*          the driver operation mode (polling or interrupt).
*
* @param[in]     HWUnit      Specifies which FlexIO peripheral is used
* @param[in]     AsyncMode   Specifies the operation mode
*                             (SPI_INTERRUPT_MODE | SPI_POLLING_MODE)
*
*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*================================================================================================*/
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, SPI_CODE) Spi_FlexIO_IrqConfig
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode
    )
{
    P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev = &Spi_FlexIO_aDeviceState[HWUnit];
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) FlexIO_pcHWUnitConfig = FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig;
    
    /* set the async mode for the HWUnit */
    FlexIO_pDev->Spi_FlexIO_AsyncMode = AsyncMode;

    /* activate/deactivate TDF, RDF interrupts for Async HWUnits */
    if (SPI_PHYUNIT_ASYNC_U32 == FlexIO_pcHWUnitConfig->u32IsSync)
    {
      
#if (SPI_DMA_USED == STD_ON)
        if (0u != FlexIO_pcHWUnitConfig->u16UseDma)
        {
            Spi_FlexIO_DmaIrqConfig(FlexIO_pDev, AsyncMode);
        }
        else
        {
            /* Do nothing */
        }
#endif /* SPI_DMA_USED == STD_ON */

    }
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */
  
/*================================================================================================*/   
  /**
* @brief   Restart the DMA transmission, refreshing the size.
* @details Source and destination addresses are already set into the active TCDs.
*
* @param[in]     FlexIO_pDev      Specifies which FlexIO module is used
*
* @pre The function can be called only if Spi_FlexIO_JobTransferDmaStart() was
*      previously called to initialize the DMA configuration.
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_JobTransferDmaContinueRX \
    ( \
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev \
    ) \
{
    VAR(Spi_NumberOfDataType, AUTOMATIC) Spi_FlexIO_FramesCount;
    P2CONST(Spi_Ipw_FlexIOChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST)
    /*
    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    Spi_FlexIO_pcChannelAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcFlexIOChannelAttributesConfig[*(FlexIO_pDev->Spi_FlexIO_pcCurrentChannelIndexPointerRX)];
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcHWUnitConfig;
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, SPI_APPL_DATA) Spi_FlexIO_pRxTcdAddr = FlexIO_pDev->Spi_FlexIO_pu32RxDmaTcd;
    
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    if(SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        Spi_FlexIO_FramesCount = FlexIO_pDev->Spi_FlexIO_ReceivedData / 2u;
    }
    else if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        Spi_FlexIO_FramesCount = FlexIO_pDev->Spi_FlexIO_ReceivedData / 4u;
    }
    else
    {
        Spi_FlexIO_FramesCount = FlexIO_pDev->Spi_FlexIO_ReceivedData;
    }
#else
    if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        Spi_FlexIO_FramesCount = FlexIO_pDev->Spi_FlexIO_ReceivedData / 2u;
    }
    {
        Spi_FlexIO_FramesCount = FlexIO_pDev->Spi_FlexIO_ReceivedData;
    }    
#endif
    /* get the number of frames to be sent through DMA */
    if ( SPI_FLEXIO_DMA_MAX_LINKED_ITER_CNT < Spi_FlexIO_FramesCount)
    {
        /* DMA iteration count is on 9 bits, if e_link field is used */
        FlexIO_pDev->Spi_FlexIO_ReceivedData = Spi_FlexIO_FramesCount - SPI_FLEXIO_DMA_MAX_LINKED_ITER_CNT;
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if(SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            FlexIO_pDev->Spi_FlexIO_ReceivedData *= 2u;
        }
        else if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            FlexIO_pDev->Spi_FlexIO_ReceivedData *= 4u;
        }
        else
        {
            /* Do nothing */
        }
    #else
        if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            FlexIO_pDev->Spi_FlexIO_ReceivedData *= 2u;
        }
        else
        {
            /* Do nothing */
        }
    #endif
        Spi_FlexIO_FramesCount = SPI_FLEXIO_DMA_MAX_LINKED_ITER_CNT;
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        /* update RX transfer size */
        Mcl_DmaTcdSetIterCount(Spi_FlexIO_pRxTcdAddr, (uint16)(Spi_FlexIO_FramesCount)); 
    }
    else
    {
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        /* update RX transfer size */
        Mcl_DmaTcdSetIterCount(Spi_FlexIO_pRxTcdAddr, (uint16)(Spi_FlexIO_FramesCount)); 
        FlexIO_pDev->Spi_FlexIO_ReceivedData = 0u;
    }
    /* start RX */
    Spi_FlexIO_pcHWUnitConfig = FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig;
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */    
     Mcl_DmaEnableHwRequest(Spi_FlexIO_pcHWUnitConfig->u8RxDmaChannel);
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Mcl_DmaEnableHwRequest(Spi_FlexIO_pcHWUnitConfig->u8TxDmaChannel);
}
#endif
  
/*================================================================================================*/       
/**
* @brief   This function is called by DMA ISR for Rx DMA channels.
* @details Non-AutoSar support function used by interrupt service
*          routine. The function is used as a pseudo ISR for all the FlexIO
*          peripherals
*
* @param[in]     FlexIO_pDev     Specifies which FlexIO peripheral is used
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*       and SPI_DMA_USED must be STD_ON
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, SPI_CODE) Spi_FlexIO_IsrDmaRx
    (
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev
    )
{
    VAR(Spi_AsyncModeType, AUTOMATIC) Spi_FlexIO_AsyncMode = FlexIO_pDev->Spi_FlexIO_AsyncMode;
    VAR(uint32, AUTOMATIC) FlexIO_u32IsrStatus  = (uint8)FALSE; 

    if (NULL_PTR != Spi_pcSpiConfigPtr)
    {
        if (SPI_POLLING_MODE == Spi_FlexIO_AsyncMode)
        {
            /* Operation mode is SPI_POLLING_MODE: set u8IsrStatus to poll RX request flag*/
            FlexIO_u32IsrStatus = (uint8)FlexIO_pDev->Spi_FlexIO_u32IsPollRequestRX;
            /* Clear poll RX request flag */
            FlexIO_pDev->Spi_FlexIO_u32IsPollRequestRX = (uint8)FALSE;
        }
        else
        {
            /* Operation mode is SPI_INTERRUPT_MODE: set u8IsrStatus to enabled*/
            FlexIO_u32IsrStatus = (uint8)TRUE;
        }
        /* Check if a poll request was made or if the operation mode is SPI_INTERRUPT_MODE */
        if (0u != FlexIO_u32IsrStatus)
        {
            if ( 0u != FlexIO_pDev->Spi_FlexIO_ReceivedData )
            {
                /* Channel not finished => update TX pointers */
                Spi_FlexIO_JobTransferDmaContinueRX(FlexIO_pDev); 
            }
            else
            {
                /* reached the end of channel => move to the next channel */
                if (0u != FlexIO_pDev->Spi_FlexIO_RemainingChannelsRX)
                {
                    /* Increase Channel indexes */
                    FlexIO_pDev->Spi_FlexIO_RemainingChannelsRX--;
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    FlexIO_pDev->Spi_FlexIO_pcCurrentChannelIndexPointerRX++;
                    /* prepare next channel transmission */
                    Spi_FlexIO_ChannelTransferDmaInitRX(FlexIO_pDev,*(FlexIO_pDev->Spi_FlexIO_pcCurrentChannelIndexPointerRX));
                }
                else
                {
                    Spi_JobTransferFinished(FlexIO_pDev->Spi_FlexIO_pcCurrentJob);
                }
            }
        }
        else
        {
            /* Driver is initialized but there was no poll request*/
            /* Do nothing */
        }
    }
    else
    {
        /* Driver is not initialized, do nothing */
    }
}
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */
  

   
/*================================================================================================*/ 
/**
* @brief   Restart the DMA transmission, refreshing the size.
* @details Source and destination addresses are already set into the active TCDs.
*
* @param[in]     FlexIO_pDev      Specifies which FlexIO module is used
*
* @pre The function can be called only if Spi_FlexIO_JobTransferDmaStart() was
*      previously called to initialize the DMA configuration.
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_JobTransferDmaContinueTX \
    ( \
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev \
    ) \
{
    VAR(Spi_NumberOfDataType, AUTOMATIC) Spi_FlexIO_FramesCount;
    P2CONST(Spi_Ipw_FlexIOChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST)
       /*
       * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
       */
    Spi_FlexIO_pcChannelAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcFlexIOChannelAttributesConfig[*(FlexIO_pDev->Spi_FlexIO_pcCurrentChannelIndexPointerTX)];
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pTxTcdAddr = FlexIO_pDev->Spi_FlexIO_pu32TxDmaTcd;
    
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    if(SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        Spi_FlexIO_FramesCount = FlexIO_pDev->Spi_FlexIO_RemainingData / 2u;
    }
    else if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        Spi_FlexIO_FramesCount = FlexIO_pDev->Spi_FlexIO_RemainingData / 4u;
    }
    else
    {
        Spi_FlexIO_FramesCount = FlexIO_pDev->Spi_FlexIO_RemainingData;
    }
#else
    if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        Spi_FlexIO_FramesCount = FlexIO_pDev->Spi_FlexIO_RemainingData / 2u;
    }
    else
    {
        Spi_FlexIO_FramesCount = FlexIO_pDev->Spi_FlexIO_RemainingData;
    }    
#endif

    /* get the number of frames to be sent through DMA */
    if ( SPI_FLEXIO_DMA_MAX_LINKED_ITER_CNT < Spi_FlexIO_FramesCount)
    {
        /* DMA iteration count is on 9 bits, if e_link field is used */
        FlexIO_pDev->Spi_FlexIO_RemainingData = Spi_FlexIO_FramesCount - SPI_FLEXIO_DMA_MAX_LINKED_ITER_CNT;
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if(SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            FlexIO_pDev->Spi_FlexIO_RemainingData *= 2u;
        }
        else if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            FlexIO_pDev->Spi_FlexIO_RemainingData *= 4u;
        }
        else
        {
            /* Do nothing */
        }
    #else
        if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            FlexIO_pDev->Spi_FlexIO_RemainingData *= 2u;
        }
        else
        {
            /* Do nothing */
        }
    #endif
        Spi_FlexIO_FramesCount = SPI_FLEXIO_DMA_MAX_LINKED_ITER_CNT;        
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetIterCount(FlexIO_pTxTcdAddr, (uint16)(Spi_FlexIO_FramesCount)); 
    }
    else
    {
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        /* update TX transfer size */ 
        Mcl_DmaTcdSetIterCount(FlexIO_pTxTcdAddr, (uint16)(Spi_FlexIO_FramesCount)); 
        FlexIO_pDev->Spi_FlexIO_RemainingData = 0u;
    }
}
#endif
  
/*================================================================================================*/
/**
* @brief   This function is called by DMA ISR for Rx DMA channels.
* @details Non-AutoSar support function used by interrupt service
*          routine. The function is used as a pseudo ISR for all the FlexIO
*          peripherals
*
* @param[in]     FlexIO_pDev     Specifies which FlexIO peripheral is used
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*       and SPI_DMA_USED must be STD_ON
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, SPI_CODE) Spi_FlexIO_IsrDmaTx
    (
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev
    )
{
    VAR(Spi_AsyncModeType, AUTOMATIC) Spi_FlexIO_AsyncMode = FlexIO_pDev->Spi_FlexIO_AsyncMode;
    VAR(uint32, AUTOMATIC) FlexIO_u32IsrStatus  = (uint32)FALSE; 

    if (NULL_PTR != Spi_pcSpiConfigPtr)
    {
        if (SPI_POLLING_MODE == Spi_FlexIO_AsyncMode)
        {
            /* Operation mode is SPI_POLLING_MODE: set u8IsrStatus to poll TX request flag*/
            FlexIO_u32IsrStatus = (uint8)FlexIO_pDev->Spi_FlexIO_u32IsPollRequestTX;
            /* Clear poll TX request flag */
            FlexIO_pDev->Spi_FlexIO_u32IsPollRequestTX = (uint8)FALSE;
        }
        else
        {
            /* Operation mode is SPI_INTERRUPT_MODE: set u8IsrStatus to enabled*/
            FlexIO_u32IsrStatus = (uint8)TRUE;
        }
        /* Check if a poll request was made or if the operation mode is SPI_INTERRUPT_MODE */
        if (0u != FlexIO_u32IsrStatus)
        {
            if ( 0u != FlexIO_pDev->Spi_FlexIO_RemainingData )
            {
                /* Channel not finished => update TX pointers */
                Spi_FlexIO_JobTransferDmaContinueTX(FlexIO_pDev); 
            }
            else
            {
                /* reached the end of channel => move to the next channel */
                if (0u != FlexIO_pDev->Spi_FlexIO_RemainingChannelsTX)
                {
                    /* Increase Channel indexes */
                    FlexIO_pDev->Spi_FlexIO_RemainingChannelsTX--;
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    FlexIO_pDev->Spi_FlexIO_pcCurrentChannelIndexPointerTX++;
                    /* prepare next channel transmission */
                    Spi_FlexIO_ChannelTransferDmaInitTX(FlexIO_pDev,*(FlexIO_pDev->Spi_FlexIO_pcCurrentChannelIndexPointerTX)); 
                }
                else
                {
                    /* Do nothing */
                }
            }
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        /* Driver is not initialized, do nothing */
    }
}
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */
  
  
  
  
  
  /*================================================================================================*/
/**
* @brief   This function drains the FlexIO FIFO.
* @details This function retrieves the received data from FlexIO FIFO.
*
* @param[in]     FlexIO_pDev     Specifies which FlexIO module is used.
*
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, SPI_CODE) Spi_FlexIO_JobTransferFifoDrain \
    ( \
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev \
    ) \
{
      P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) Spi_FlexIO_pBufferRx;
      VAR(Spi_NumberOfDataType, AUTOMATIC) Spi_FlexIO_nFramesCount = 0U;
    VAR(uint32, AUTOMATIC) Spi_FlexIO_u32RDRAddress = FlexIO_pDev->Spi_FlexIO_u32RDRAddress;
    P2CONST(Spi_Ipw_FlexIOChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) \
    /*
    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    Spi_FlexIO_pcChannelAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcFlexIOChannelAttributesConfig[*(FlexIO_pDev->Spi_FlexIO_pcCurrentChannelIndexPointerRX)];
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) Spi_FlexIO_pu16BufferFullRX;
    P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) Spi_FlexIO_pu32BufferFullRX;
    #else
    VAR(uint32, AUTOMATIC) Spi_FlexIO_u32BufferFullRX;
    #endif
    
    Spi_FlexIO_nFramesCount = FlexIO_pDev->Spi_FlexIO_SentFrames;
    FlexIO_pDev->Spi_FlexIO_ReceivedData -= Spi_FlexIO_nFramesCount;
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
    if(SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        FlexIO_pDev->Spi_FlexIO_ReceivedData -= Spi_FlexIO_nFramesCount;
    }
    else if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        FlexIO_pDev->Spi_FlexIO_ReceivedData -= 3u*Spi_FlexIO_nFramesCount;
    }
    else
    {
        /* Do nothing */
    }
    #else
    if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        FlexIO_pDev->Spi_FlexIO_ReceivedData -= Spi_FlexIO_nFramesCount;
    }
    else
    {
        /* Do nothing */
    }
    #endif

    Spi_FlexIO_pBufferRx = FlexIO_pDev->Spi_FlexIO_pCurrentRxBuffer;

    if (NULL_PTR != Spi_FlexIO_pBufferRx)
    {
        /* read the deserialized information */
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if(SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            /*
            * @violates @ref Spi_FlexIO_c_REF_4 A cast should not be performed between a
            * pointer to object type and a different pointer to object type.
            */
            Spi_FlexIO_pu16BufferFullRX = (uint16 *) Spi_FlexIO_pBufferRx;
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            *Spi_FlexIO_pu16BufferFullRX = (uint16)REG_READ16(Spi_FlexIO_u32RDRAddress);  
                                /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */                   
            Spi_FlexIO_pBufferRx += 2u;
        }
        else if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            /*
            * @violates @ref Spi_FlexIO_c_REF_4 A cast should not be performed between a
            * pointer to object type and a different pointer to object type.
            */
            Spi_FlexIO_pu32BufferFullRX = (uint32 *) Spi_FlexIO_pBufferRx;
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */                    
            *Spi_FlexIO_pu32BufferFullRX = (uint32)REG_READ32(Spi_FlexIO_u32RDRAddress);           
            /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */                    
            Spi_FlexIO_pBufferRx += 4u;                    
        }
        else
        {
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
              *Spi_FlexIO_pBufferRx = (Spi_DataBufferType)REG_READ8(Spi_FlexIO_u32RDRAddress);
              /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */                    
            Spi_FlexIO_pBufferRx++;
        }
        #else
        if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {                   
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */                   
            Spi_FlexIO_u32BufferFullRX = (uint32)REG_READ32(Spi_FlexIO_u32RDRAddress);           
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
                *Spi_FlexIO_pBufferRx = (uint16)(Spi_FlexIO_u32BufferFullRX & (uint32)0x0000FFFFu);
                 /*
                 * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                 *       the only allowed form of pointer arithmetic.
                 */
                *(Spi_FlexIO_pBufferRx+1u) = (uint16)(Spi_FlexIO_u32BufferFullRX >> 16u);
            #else
                *Spi_FlexIO_pBufferRx = (uint16)(Spi_FlexIO_u32BufferFullRX >> 16u);
                 /*
                 * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                 *       the only allowed form of pointer arithmetic.
                 */
                *(Spi_FlexIO_pBufferRx+1u) = (uint16)(Spi_FlexIO_u32BufferFullRX & (uint32)0x0000FFFFu);
            #endif       
            /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            Spi_FlexIO_pBufferRx += 2u;                    
        }
        else
        {
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
              *Spi_FlexIO_pBufferRx = (Spi_DataBufferType)REG_READ16(Spi_FlexIO_u32RDRAddress);
             /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            Spi_FlexIO_pBufferRx++; 
        }
        #endif
        /* update current RX buffer pointer */
        FlexIO_pDev->Spi_FlexIO_pCurrentRxBuffer = Spi_FlexIO_pBufferRx;
    }
    else
    {
        /* discard the information read */
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */           
        Spi_FlexIO_u32ReadDiscard = REG_READ32(Spi_FlexIO_u32RDRAddress);
    }
#if (SPI_SLAVE_SUPPORT == STD_ON)
    if( SPI_SLAVE == FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->eSpiPhyUnitMode)
    {
        if((Spi_NumberOfDataType)0u == FlexIO_pDev->Spi_FlexIO_ReceivedData)
        {
            FlexIO_pDev->Spi_FlexIO_bIsEndOfJob = (boolean)TRUE;
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        /* Do nothing */
    }
#endif
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

#if ((SPI_LEVEL_DELIVERED != LEVEL1) && (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON))  
/*================================================================================================*/
/**
* @brief   Low-level initialize function.
* @details Computes sequence / job configuration parameters like
*          parameters like Baud Rate, CS, Clock polarity, etc.
*          This cached values will be used in sync transmissions in
*          order to optimize the time.
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall not be LEVEL1.
* @pre  Pre-compile parameter SPI_OPTIMIZE_ONE_JOB_SEQUENCES shall be STD_ON.
*
*/
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, SPI_CODE) Spi_FlexIO_PrepareCacheInformation(void)
{
    VAR(Spi_ChannelType, AUTOMATIC) FlexIO_Channel;
    VAR(Spi_ChannelType, AUTOMATIC) FlexIO_ChannelId;
    VAR(Spi_JobType, AUTOMATIC) FlexIO_Job;
    VAR(uint32, AUTOMATIC) FlexIO_u32Sequence;
    VAR(uint8, SPI_VAR) u8HWtypeOptimized;
    P2VAR(Spi_FlexIO_ChannelCacheAttrsType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pChannelAttrs;
    P2VAR(Spi_FlexIO_SequenceCacheAttrsType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pSeqAttrs;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) FlexIO_pcChannelConfig;
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) FlexIO_pcJobConfig;
    P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_APPL_CONST) FlexIO_pcSequenceConfig;
    P2CONST(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pDev;
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_TX = 0u;
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_RX = 0u;    
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CLK = 0u;    
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CS = 0u;
    /* index to the first free entry in 'Spi_FlexIO_aSeqsAttributes' table. */
    VAR(Spi_SequenceType, AUTOMATIC) FlexIO_SeqsAttrCurrentIndex = 0u;
    /* index to the first free entry in 'Spi_FlexIO_aChannelsAttributes' table. */
    VAR(Spi_ChannelType, AUTOMATIC) FlexIO_ChannelsAttrCurrentIndex = 0u;

    /* reset all sequences as not optimized */
    for (FlexIO_u32Sequence = 0u; FlexIO_u32Sequence <= (uint32)(Spi_pcSpiConfigPtr->Spi_Max_Sequence); FlexIO_u32Sequence++)
    {
        Spi_FlexIO_apOneJobSeqsOptimized[FlexIO_u32Sequence] = NULL_PTR;
    }
    for (FlexIO_u32Sequence = 0u; FlexIO_u32Sequence <= (uint32)(Spi_pcSpiConfigPtr->Spi_Max_Sequence); FlexIO_u32Sequence++)
    {
        /*
        * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        FlexIO_pcSequenceConfig = &Spi_pcSpiConfigPtr->pcSequenceConfig[FlexIO_u32Sequence];
        /* only one job sequences can be optimized */
        if (1u == FlexIO_pcSequenceConfig->NumJobs)
        {
            /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            FlexIO_Job = FlexIO_pcSequenceConfig->pcJobIndexList[0];
            /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            FlexIO_pcJobConfig = &Spi_pcSpiConfigPtr->pcJobConfig[FlexIO_Job];
            Spi_FlexIO_pDev = &Spi_FlexIO_aDeviceState[FlexIO_pcJobConfig->HWUnit];
            /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            u8HWtypeOptimized = Spi_pcSpiConfigPtr->pcHWUnitConfig[FlexIO_pcJobConfig->HWUnit].u8HWtype;

            /* check if enough place in the cached data channel pool */
            if (FlexIO_pcJobConfig->NumChannels <= (SPI_OPTIMIZED_CHANNEL_BUFFER_SIZE-FlexIO_ChannelsAttrCurrentIndex))
            {
                /* get the first empty entry in the sequence pool and
                link it to the sequence */
                FlexIO_pSeqAttrs = &Spi_FlexIO_aSeqsAttributes[FlexIO_SeqsAttrCurrentIndex];                      
                /* Get the Shifters, Timers number used to setup TX, RX, CS, CLK channel */
                FlexIO_pSeqAttrs->Spi_FlexIO_u8Shifter_TX = Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_TX;
                FlexIO_pSeqAttrs->Spi_FlexIO_u8Shifter_RX = Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_RX;     
                FlexIO_pSeqAttrs->Spi_FlexIO_u8Timer_CLK = Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_CLK; 
                FlexIO_pSeqAttrs->Spi_FlexIO_u8Timer_CS = Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_CS;
                /* Get address of Shifter TX/RX */
                Spi_FlexIO_u8Shifter_TX = Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_TX;
                Spi_FlexIO_u8Shifter_RX =  Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_RX; 
                Spi_FlexIO_u8Timer_CLK = Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_CLK;
                Spi_FlexIO_u8Timer_CS = Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_CS;
                /* Get Shifter, Timer config data */
                FlexIO_pSeqAttrs->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] = \
                    (*FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32ShifterCFGConfigTX;
                FlexIO_pSeqAttrs->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_RX] = \
                    (*FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32ShifterCFGConfigRX;
                FlexIO_pSeqAttrs->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX] = \
                    (*FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32ShifterCTLConfigTX;
                FlexIO_pSeqAttrs->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX] = \
                    (*FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32ShifterCTLConfigRX;
                FlexIO_pSeqAttrs->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]   = \
                    (*FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCMPConfigCLK;
                FlexIO_pSeqAttrs->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CS]   = \
                    (*FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCMPConfigCS;
                FlexIO_pSeqAttrs->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK]   = \
                    (*FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCTLConfigCLK;
                FlexIO_pSeqAttrs->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CS]   = \
                    (*FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCTLConfigCS;
                FlexIO_pSeqAttrs->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]   = \
                    (*FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCFGConfigCLK;
                FlexIO_pSeqAttrs->Spi_FlexIO_MASTER = Spi_FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->eSpiPhyUnitMode;
                FlexIO_pSeqAttrs->Spi_FlexIO_u32BaseAddress = (uint32)FLEXIO_BASEADDR;
                FlexIO_pSeqAttrs->Spi_FlexIO_u8EndOfJobFlag =(uint8)FALSE;
                /* Get CPOL, CPHA, PSC for each job */
                FlexIO_pSeqAttrs->Spi_FlexIO_u8CPOL = (*FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u8CPOL;
                FlexIO_pSeqAttrs->Spi_FlexIO_u8CPHA = (*FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u8CPHA;
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
                FlexIO_pSeqAttrs->Spi_FlexIO_u32PSC[0] = (*FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32PSC[0];
                FlexIO_pSeqAttrs->Spi_FlexIO_u32PSC[1] = (*FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32PSC[1];
#else
                FlexIO_pSeqAttrs->Spi_FlexIO_u32PSC = (*FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32PSC;
#endif
                Spi_FlexIO_apOneJobSeqsOptimized[FlexIO_u32Sequence] = FlexIO_pSeqAttrs;
                /* retrieve the device configuration for the sequence */
                /* prepare sequence cache information */
                FlexIO_pSeqAttrs->u8HWtypeOptimized = u8HWtypeOptimized;
                FlexIO_pSeqAttrs->FlexIO_HWUnit = FlexIO_pcJobConfig->HWUnit;
                FlexIO_pSeqAttrs->FlexIO_NumChannels = FlexIO_pcJobConfig->NumChannels;
                FlexIO_pSeqAttrs->FlexIO_pJobState = &Spi_aSpiJobState[FlexIO_Job];
                FlexIO_pSeqAttrs->FlexIO_pJobStatus = Spi_FlexIO_aDeviceState[FlexIO_pcJobConfig->HWUnit].Spi_FlexIO_pStatus;
                /* set the link to the first cached channel entry */
                FlexIO_pSeqAttrs->FlexIO_pChannels = &Spi_FlexIO_aChannelsAttributes[FlexIO_ChannelsAttrCurrentIndex];
                /* prepare channel cache information */
                for (FlexIO_Channel = 0u; FlexIO_Channel < FlexIO_pcJobConfig->NumChannels; FlexIO_Channel++)
                {
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                    */
                    FlexIO_ChannelId = FlexIO_pcJobConfig->pcChannelIndexList[FlexIO_Channel];
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                    */
                    FlexIO_pcChannelConfig = &Spi_pcSpiConfigPtr->pcChannelConfig[FlexIO_ChannelId];
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    FlexIO_pChannelAttrs = &FlexIO_pSeqAttrs->FlexIO_pChannels[FlexIO_Channel];
                    FlexIO_pChannelAttrs->FlexIO_u32DefaultTransmitValue = FlexIO_pcChannelConfig->u32DefaultTransmitValue;
                    FlexIO_pChannelAttrs->FlexIO_pState = FlexIO_pcChannelConfig->pChannelState;
                    FlexIO_pChannelAttrs->FlexIO_pcBufferDescriptor = FlexIO_pcChannelConfig->pcBufferDescriptor;
                    FlexIO_pChannelAttrs->u32NumBitsInFrame =
                        /*
                        * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                        */
                        Spi_pcSpiConfigPtr->pcAttributesConfig->pcFlexIOChannelAttributesConfig[FlexIO_ChannelId].u32NumBitsInFrame; 
                    FlexIO_pChannelAttrs->u32DataWidth =
                        /*
                        * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                        */
                        Spi_pcSpiConfigPtr->pcAttributesConfig->pcFlexIOChannelAttributesConfig[FlexIO_ChannelId].u32DataWidth;
                    FlexIO_pChannelAttrs->u8LBF = 
                        /*
                        * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                        */
                        Spi_pcSpiConfigPtr->pcAttributesConfig->pcFlexIOChannelAttributesConfig[FlexIO_ChannelId].u8LBF;
                } /* for (channels) */
                /* set the pool indexes to the new empty entries */
                FlexIO_SeqsAttrCurrentIndex++;
                FlexIO_ChannelsAttrCurrentIndex += FlexIO_pcJobConfig->NumChannels;

                /* end the loop if caches are full */
                if(
                    (FlexIO_SeqsAttrCurrentIndex >= SPI_OPTIMIZED_SEQ_BUFFER_SIZE)||
                    (FlexIO_ChannelsAttrCurrentIndex >= SPI_OPTIMIZED_CHANNEL_BUFFER_SIZE)
                  )
                {
                    break; /* end the loop */
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }
    } /* for (sequences) */
}
#endif /* (SPI_LEVEL_DELIVERED != LEVEL1) && (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON) */
/*================================================================================================*/
/**
* @brief   This function fills the FlexIO FIFO.
* @details This function fills FlexIO FIFO Transmit buffer with
*          data assigned or transmit the default
*          buffer values in case of the lack of transmit
*          data buffer.
*
* @param[in]     FlexIO_pDev             Specifies which FlexIO module is used
*                FlexIO_u8EndOfJob       End of job flag
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, SPI_CODE) Spi_FlexIO_WriteTxFifo \
    ( \
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev, \
        VAR(uint8, AUTOMATIC) FlexIO_u8EndOfJob \
    ) \
{
     P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pBufferTX = FlexIO_pDev->Spi_FlexIO_pCurrentTxBuffer;
     VAR(Spi_NumberOfDataType, AUTOMATIC) Spi_FlexIO_nFramesCount = FlexIO_pDev->Spi_FlexIO_SentFrames;
    P2CONST(Spi_Ipw_FlexIOChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) 
    /*
    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    Spi_FlexIO_pcChannelAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcFlexIOChannelAttributesConfig[*(FlexIO_pDev->Spi_FlexIO_pcCurrentChannelIndexPointerTX)];
        
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2CONST(uint16, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pu16BufferFullTX;
    P2CONST(uint32, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pu32BufferFullTX;
#endif
    VAR(uint32, AUTOMATIC) Spi_FlexIO_u32BufferFullTX = 0U;
    /* Get physical device handler */
    VAR(uint32, AUTOMATIC) Spi_FlexIO_u32TDRAddress = FlexIO_pDev->Spi_FlexIO_u32TDRAddress;
    
    if (NULL_PTR != Spi_FlexIO_pBufferTX)
    {
        /* set the new TX buffer pointer */
        /*
        * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */       
        FlexIO_pDev->Spi_FlexIO_pCurrentTxBuffer += Spi_FlexIO_nFramesCount;
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if(SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            FlexIO_pDev->Spi_FlexIO_pCurrentTxBuffer += Spi_FlexIO_nFramesCount;
        }
        else if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */           
            FlexIO_pDev->Spi_FlexIO_pCurrentTxBuffer += 3u * Spi_FlexIO_nFramesCount;
        }
        else
        {
            /* Do nothing */
        }
        #else
        if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */             
            FlexIO_pDev->Spi_FlexIO_pCurrentTxBuffer += Spi_FlexIO_nFramesCount;           
        }
        else
        {
            /* Do nothing */
        }
        #endif
        
        /* write the information from the buffer */
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if( SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            /*
            * @violates @ref Spi_FlexIO_c_REF_4 A cast should not be performed between a
            * pointer to object type and a different pointer to object type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_14 A cast shall not be performed that removes any const or volatile
            * qualification from the type addressed by a pointer.
            */
            Spi_FlexIO_pu16BufferFullTX = (uint16 *) Spi_FlexIO_pBufferTX;
            /* Setup data for MSB mode */
            if (SPI_FLEXIO_MSB_U8 == FlexIO_pDev->Spi_FlexIO_u8LBF)
            {
                Spi_FlexIO_u32BufferFullTX = (uint32)(*Spi_FlexIO_pu16BufferFullTX) << 16;
            }
            else 
            {
                Spi_FlexIO_u32BufferFullTX = (*Spi_FlexIO_pu16BufferFullTX);
            }
            /* write to shifterbuffer to tranfer */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(Spi_FlexIO_u32TDRAddress, Spi_FlexIO_u32BufferFullTX);
            /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */                
            Spi_FlexIO_pBufferTX+= 2u;
        }
        else if( SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            /*
            * @violates @ref Spi_FlexIO_c_REF_4 A cast should not be performed between a pointer
            *       to object type and a different pointer to object type.
            */   
            /*
            * @violates @ref Spi_FlexIO_c_REF_14 A cast shall not be performed that removes any const or volatile
            * qualification from the type addressed by a pointer.
            */            
            Spi_FlexIO_pu32BufferFullTX = (uint32 *) Spi_FlexIO_pBufferTX;
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */                
            REG_WRITE32(Spi_FlexIO_u32TDRAddress, (*Spi_FlexIO_pu32BufferFullTX));
                     
            /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            Spi_FlexIO_pBufferTX += 4u;
        }
        else
        {
            /* Setup data for MSB mode */
            if (SPI_FLEXIO_MSB_U8 == FlexIO_pDev->Spi_FlexIO_u8LBF)
            {
                Spi_FlexIO_u32BufferFullTX = (uint32)(*Spi_FlexIO_pBufferTX) << 24;
            }
            else 
            {
                Spi_FlexIO_u32BufferFullTX = (*Spi_FlexIO_pBufferTX);
            }
            /* write to shifterbuffer to tranfer */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(Spi_FlexIO_u32TDRAddress, Spi_FlexIO_u32BufferFullTX);
            /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            Spi_FlexIO_pBufferTX++;
                          
        }
        #else
            
        if( SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
        {
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
                /*
                * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                * @violates @ref Spi_FlexIO_c_REF_4 A cast should not be performed between a
                *  pointer to object type and a different pointer to object type.
                */
                Spi_FlexIO_u32BufferFullTX = (uint32)(*Spi_FlexIO_pBufferTX) | ((uint32)(*(Spi_FlexIO_pBufferTX+1u)) << 16u);
            #else
                /*
                * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                * @violates @ref Spi_FlexIO_c_REF_4 A cast should not be performed between a
                *  pointer to object type and a different pointer to object type.
                */
                Spi_FlexIO_u32BufferFullTX = ((uint32)(*Spi_FlexIO_pBufferTX) << 16u) | (uint32)(*(Spi_FlexIO_pBufferTX+1u));
            #endif
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
             REG_WRITE32(Spi_FlexIO_u32TDRAddress, Spi_FlexIO_u32BufferFullTX);
            /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            Spi_FlexIO_pBufferTX += 2u;
        }
        else
        {
            /* Setup data for MSB mode */
            if (SPI_FLEXIO_MSB_U8 == FlexIO_pDev->Spi_FlexIO_u8LBF)
            {
                if( SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
                {
                    Spi_FlexIO_u32BufferFullTX = (uint32)(*Spi_FlexIO_pBufferTX) << 16;
                }
                else if ( SPI_FLEXIO_DATA_WIDTH_8 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
                {
                    Spi_FlexIO_u32BufferFullTX = (uint32)(*Spi_FlexIO_pBufferTX) << 24;
                }
                else
                {
                    /* do nothing */
                }
            }
            else 
            {
                Spi_FlexIO_u32BufferFullTX = (*Spi_FlexIO_pBufferTX);
            }
            /* write to shifterbuffer to tranfer */
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(Spi_FlexIO_u32TDRAddress, Spi_FlexIO_u32BufferFullTX);
            /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */               
            Spi_FlexIO_pBufferTX++;               
        }            
        #endif
        if(SPI_MASTER == FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->eSpiPhyUnitMode)
        {
            if ((boolean)TRUE == FlexIO_u8EndOfJob)
            {
                /* signal the end of job for the current FlexIO Unit */
                FlexIO_pDev->Spi_FlexIO_bIsEndOfJob = (boolean)TRUE;
            }
            else
            {
                /* Do nothing */
            }
        }
        /*
        * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
    }
    else
    {   /* write the default value */
        /* default transmit value already integrated in FlexIO_pDev->Spi_u32CurrentCmd */
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(Spi_FlexIO_u32TDRAddress, FlexIO_pDev->Spi_FlexIO_u32TransmitDefaultData);
        if(SPI_MASTER == FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->eSpiPhyUnitMode)
        {
            if ((boolean)TRUE == FlexIO_u8EndOfJob)
            {
                /* signal the end of job for the current FlexIO Unit */
                FlexIO_pDev->Spi_FlexIO_bIsEndOfJob = (boolean)TRUE;
            }
            else
            {
                /* Do nothing */
            }
        }
    }
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */
 
/*================================================================================================*/
/**
* @brief   This function fills the FlexIO FIFO.
* @details This function fills FlexIO FIFO Transmit buffer with the
*          predefined data assigned or transmit the default
*          buffer values in case of the lack of transmit
*          data buffer.
*
* @param[in]     FlexIO_pDev     Specifies which FlexIO module is used
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, SPI_CODE) Spi_FlexIO_JobTransferFifoFill \
( \
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev \
) \
{
    VAR(Spi_NumberOfDataType, AUTOMATIC) Spi_FlexIO_nFramesCount;
    VAR(uint8, AUTOMATIC) Spi_FlexIO_u8EndOfJob = (uint8)FALSE; /* end of job */
    P2CONST(Spi_Ipw_FlexIOChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) 
        /*
        * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        Spi_FlexIO_pcChannelAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcFlexIOChannelAttributesConfig[*(FlexIO_pDev->Spi_FlexIO_pcCurrentChannelIndexPointerTX)];

    /* calculate the number of frames to be sent and the 'end of job' state */
    Spi_FlexIO_nFramesCount = FlexIO_pDev->Spi_FlexIO_RemainingData;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    if(SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        Spi_FlexIO_nFramesCount/=2u;
    }
    else if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        Spi_FlexIO_nFramesCount/=4u;
    }
    else
    {
        /* Do nothing */
    }
#else
    if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        Spi_FlexIO_nFramesCount/=2u;
    }
    else
    {
        /* Do nothing */
    }
#endif
    if(SPI_MASTER == FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->eSpiPhyUnitMode)
    {
        if((0u == (uint32)(FlexIO_pDev->Spi_FlexIO_RemainingChannelsTX)) && (1U == Spi_FlexIO_nFramesCount))
        {
            Spi_FlexIO_u8EndOfJob = (uint8)TRUE;
        }
        else
        {
            Spi_FlexIO_u8EndOfJob = (uint8)FALSE;
        }
    }
#if (SPI_SLAVE_SUPPORT == STD_ON)
    if(SPI_SLAVE == FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->eSpiPhyUnitMode)
    {
         Spi_FlexIO_nFramesCount = 1u;  
    }
    else
    {
#endif     
    if(0u < Spi_FlexIO_nFramesCount)
    {
        Spi_FlexIO_nFramesCount = 1u;
    }
    else
    {
        /*do nothing*/
    }
#if (SPI_SLAVE_SUPPORT == STD_ON)
    }
#endif

    #if (SPI_FORCE_DATA_TYPE == STD_ON)
    if(SPI_FLEXIO_DATA_WIDTH_16 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        FlexIO_pDev->Spi_FlexIO_RemainingData -= 2u*Spi_FlexIO_nFramesCount;
    }
    else if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        FlexIO_pDev->Spi_FlexIO_RemainingData -= 4u*Spi_FlexIO_nFramesCount;
    }
    else
    {
        FlexIO_pDev->Spi_FlexIO_RemainingData -=  Spi_FlexIO_nFramesCount;
    }
    #else
    if(SPI_FLEXIO_DATA_WIDTH_32 == Spi_FlexIO_pcChannelAttributesConfig->u32DataWidth)
    {
        FlexIO_pDev->Spi_FlexIO_RemainingData -= 2u*Spi_FlexIO_nFramesCount;
    }
    else
    {
        FlexIO_pDev->Spi_FlexIO_RemainingData -=  Spi_FlexIO_nFramesCount;
    }
    #endif
    /* Get LSB/MSB */
    FlexIO_pDev->Spi_FlexIO_u8LBF = Spi_FlexIO_pcChannelAttributesConfig->u8LBF;
    FlexIO_pDev->Spi_FlexIO_SentFrames = Spi_FlexIO_nFramesCount;
    Spi_FlexIO_WriteTxFifo(FlexIO_pDev, Spi_FlexIO_u8EndOfJob);

}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */
  
/*================================================================================================*/
/**
* @brief   This function initializes channel related informations in FlexIO HW Unit structure.
* @details The function must be called before starting the async transfer of a
*          channel.
*
* @param[in]     FlexIO_pDev     Specifies device involved in transmission
* @param[in]     Channel     ID of the channel to be transmitted.
*/
/*================================================================================================*/  
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*
* @violates @ref Spi_FlexIO_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_ChannelTransferFifoInitRX \
    ( \
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev, \
        VAR(Spi_ChannelType, AUTOMATIC) Channel \
    ) \
{
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelConfig;
    P2CONST(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pChannelState;
    
    /*
    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    Spi_FlexIO_pcChannelConfig = &Spi_pcSpiConfigPtr->pcChannelConfig[Channel];
    Spi_FlexIO_pChannelState = Spi_FlexIO_pcChannelConfig->pChannelState;
    FlexIO_pDev->Spi_FlexIO_ReceivedData = Spi_FlexIO_pChannelState->Length;
    /* identify the RX buffers */
    /* Rx buffer will be NULL if discarding read values */
    FlexIO_pDev->Spi_FlexIO_pCurrentRxBuffer = Spi_FlexIO_pcChannelConfig->pcBufferDescriptor->pBufferRX;
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*================================================================================================*/
/**
* @brief   This function initializes channel related informations in FlexIO HW Unit structure.
* @details The function must be called before starting the async transfer of a
*          channel.
*
* @param[in]     FlexIO_pDev     Specifies device involved in transmission
* @param[in]     Channel     ID of the channel to be transmitted.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_FlexIO_ChannelTransferFifoInitTX \
    ( \
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev, \
        VAR(Spi_ChannelType, AUTOMATIC) Channel \
    ) \
{
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcHWUnitConfig;
    P2CONST(Spi_Ipw_FlexIOChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelAttributesConfig;
    /*
    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcChannelConfig = &Spi_pcSpiConfigPtr->pcChannelConfig[Channel];
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pcJobConfig = FlexIO_pDev->Spi_FlexIO_pcCurrentJob;
    P2CONST(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_CONST) Spi_FlexIO_pChannelState = Spi_FlexIO_pcChannelConfig->pChannelState;
    P2VAR(Spi_FlexIO_SyncStateType, AUTOMATIC,SPI_APPL_DATA) Spi_FlexIO_pAsyncTransmitState = NULL_PTR;
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_TX = 0u;
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_RX = 0u;    
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CLK = 0u;    
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CS = 0u;  
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8TRGSEL = 0u;
    
    Spi_FlexIO_pcHWUnitConfig = FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig;
    /* External device attributes */
    /*
    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    Spi_FlexIO_pcChannelAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcFlexIOChannelAttributesConfig[Channel];
    /* Get TX, RX, CLK, CS offset */
    Spi_FlexIO_u8Shifter_TX = Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_TX;
    Spi_FlexIO_u8Shifter_RX = Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_RX;
    Spi_FlexIO_u8Timer_CLK = Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_CLK;
    Spi_FlexIO_u8Timer_CS = Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_CS;
    Spi_FlexIO_pAsyncTransmitState = &Spi_FlexIO_SyncTransmitState[FlexIO_pDev->Spi_HWUnit];
    /* Clean the registers */
    /* Shifter CFG */
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] = 0x0u;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_RX] = 0x0u;
    /* Shifter CLT */    
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX] = 0x0u;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX] = 0x0u;
    /* Timer CMP */
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]   = 0x0u;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CS]   = 0x0u;
    /* Timer CTL */    
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK]   = 0x0u;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CS]   = 0x0u;
    /* Trigger select for timer clock */
    Spi_FlexIO_u8TRGSEL = (4u*Spi_FlexIO_u8Shifter_TX) + 1u;
    /* Get Shifter, Timer config data */
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32ShifterCFGConfigTX;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_RX] |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32ShifterCFGConfigRX;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX] |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32ShifterCTLConfigTX;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX] |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32ShifterCTLConfigRX;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]   |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCMPConfigCLK;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CS]   |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCMPConfigCS;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK]   |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCTLConfigCLK;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CS]   |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCTLConfigCS;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]   |= \
        (*Spi_FlexIO_pcJobConfig->ExternalDeviceAttrs->pcFlexIOExternalDeviceAttrs)->u32TimerCFGConfigCLK;       
    /* Get TX buffer*/
    FlexIO_pDev->Spi_FlexIO_pCurrentTxBuffer = Spi_FlexIO_pcChannelConfig->pcBufferDescriptor->pBufferTX;
    FlexIO_pDev->Spi_FlexIO_RemainingData = Spi_FlexIO_pChannelState->Length;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32BaseAddress = (uint32)FLEXIO_BASEADDR;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8CPOL   = FlexIO_pDev->Spi_FlexIO_u8DeviceStateCPOL;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8CPHA   = FlexIO_pDev->Spi_FlexIO_u8DeviceStateCPHA;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32FSIZE  = Spi_FlexIO_pcChannelAttributesConfig->u32NumBitsInFrame;
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8LBF    = Spi_FlexIO_pcChannelAttributesConfig->u8LBF;
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32PSC[0]    = FlexIO_pDev->Spi_FlexIO_u32DeviceStatePSC[0];
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32PSC[1]    = FlexIO_pDev->Spi_FlexIO_u32DeviceStatePSC[1];
#else
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32PSC    = FlexIO_pDev->Spi_FlexIO_u32DeviceStatePSC;
#endif
    Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_MASTER =  Spi_FlexIO_pcHWUnitConfig->eSpiPhyUnitMode;
    
    if(SPI_POLLING_MODE == FlexIO_pDev->Spi_FlexIO_AsyncMode)
    {
       Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32SHIFTSIEN &=  ~((uint32)1U << (uint32)Spi_FlexIO_u8Shifter_RX);     
       Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32SHIFTSIEN &=  ~((uint32)1U << (uint32)Spi_FlexIO_u8Shifter_TX);     
    }
    else
    {
       Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32SHIFTSIEN |=  (uint32)1U << (uint32)Spi_FlexIO_u8Shifter_RX;
       Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32SHIFTSIEN |=  (uint32)1U << (uint32)Spi_FlexIO_u8Shifter_TX;
    }
    
    if(SPI_MASTER == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_MASTER)
    {
        if(SPI_FLEXIO_CPHA_TRAILING_U8 == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8CPHA)
        {
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCFG_CPHA0_U32; 
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCTL_TIMPOL_U32;
        }
        else if(SPI_FLEXIO_CPHA_LEADING_U8 == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8CPHA)
        {                
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCFG_CPHA1_U32; 
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX] |= SPI_FLEXIO_SHIFTCTL_TIMPOL_U32; 
        }
        else
        {
            /* Do notthing */
        }
        /* CLK Polarity */
        if(SPI_FLEXIO_CPOL_HIGH_U8 == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8CPOL)
        {
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK] |= SPI_FLEXIO_SHIFTCTL_PINPOL_HIGH_U32;
        }
        else
        {
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK] |= SPI_FLEXIO_SHIFTCTL_PINPOL_LOW_U32;
        }
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]  |= Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32PSC[Spi_FlexIO_ClockMode];
#else
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]  |= Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32PSC;    
#endif
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]  |= (Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32FSIZE) << 8;
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]  |= SPI_FLEXIO_TIMCFG_CLK_MASTER_U32;
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CS]  |= SPI_FLEXIO_TIMCFG_CS_MASTER_U32;
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CS]  |= SPI_FLEXIO_TIMCMP_RWBITS_U32;
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK]  |= (uint32)Spi_FlexIO_u8TRGSEL << 24;
    }
    else
    {
        if(SPI_FLEXIO_CPHA_TRAILING_U8 == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8CPHA)
        {
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCFG_CPHA0_U32; 
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCTL_TIMPOL_U32;
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]    |= SPI_FLEXIO_TIMCFG_CLK_CS_SLAVE_U32; 
        }
        else if(SPI_FLEXIO_CPHA_LEADING_U8 == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8CPHA)
        {
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX] |= SPI_FLEXIO_SHIFTCFG_CPHA1_U32; 
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX] |= SPI_FLEXIO_SHIFTCTL_TIMPOL_U32; 
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]    |= SPI_FLEXIO_TIMCFG_CLK_CS_SLAVE_CPHA1_U32; 
        }
        else
        {
            /* Do notthing */
        }
        /* CLK Polarity */
        if(SPI_FLEXIO_CPOL_HIGH_U8 == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8CPOL)
        {
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK] |= SPI_FLEXIO_SHIFTCTL_PINPOL_HIGH_U32;
        }
        else
        {
            Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK] |= SPI_FLEXIO_SHIFTCTL_PINPOL_LOW_U32;
        }
        
        Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]  |= (Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u32FSIZE);
    }
        
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */   
    REG_WRITE32(FLEXIO_SHIFTCFGn_ADDR32((uint32)Spi_FlexIO_u8Shifter_TX),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_TX]);
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */ 
    REG_WRITE32(FLEXIO_SHIFTCTLn_ADDR32((uint32)Spi_FlexIO_u8Shifter_TX),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_TX]);
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(FLEXIO_SHIFTCFGn_ADDR32((uint32)Spi_FlexIO_u8Shifter_RX),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCFG[Spi_FlexIO_u8Shifter_RX]);
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(FLEXIO_SHIFTCTLn_ADDR32((uint32)Spi_FlexIO_u8Shifter_RX),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32SHIFTCTL[Spi_FlexIO_u8Shifter_RX]);
        
    if(SPI_MASTER == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_MASTER)
    {
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */ 
        REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]); 
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */       
        REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)Spi_FlexIO_u8Timer_CS),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CS]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32)Spi_FlexIO_u8Timer_CS),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CS]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32)Spi_FlexIO_u8Timer_CS),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CS]);                
    }
    else
    {
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCMP[Spi_FlexIO_u8Timer_CLK]); 
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCFG[Spi_FlexIO_u8Timer_CLK]);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed
        *  between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32)Spi_FlexIO_u8Timer_CLK),Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_au32TIMCTL[Spi_FlexIO_u8Timer_CLK]);
    }
    
    /*
    * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    if(SPI_FLEXIO_LSB_U8 == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8LBF)
    {
        FlexIO_pDev->Spi_FlexIO_u32TDRAddress = FLEXIO_SHIFTBUFn_ADDR32((uint32)Spi_FlexIO_u8Shifter_TX);
        FlexIO_pDev->Spi_FlexIO_u32RDRAddress = FLEXIO_SHIFTBUFn_ADDR32((uint32)Spi_FlexIO_u8Shifter_RX);
    }
    else if(SPI_FLEXIO_MSB_U8 == Spi_FlexIO_pAsyncTransmitState->Spi_FlexIO_u8LBF)
    {
        FlexIO_pDev->Spi_FlexIO_u32RDRAddress = FLEXIO_SHIFTBUFBISn_ADDR32( (uint32)Spi_FlexIO_u8Shifter_RX);
        FlexIO_pDev->Spi_FlexIO_u32TDRAddress = FLEXIO_SHIFTBUFBISn_ADDR32( (uint32)Spi_FlexIO_u8Shifter_TX);     
    }
    else
    {
        /* Do notthing */
    }
    Mcl_Flexio_WriteShiftSien((uint8)(1u << Spi_FlexIO_u8Shifter_TX),(uint8)(1u << Spi_FlexIO_u8Shifter_TX));
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */
 
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
* @brief   This function is called by TDF or RDF ISRs for the FlexIO units working in PIO_FIFO mode.
* @details Non-AutoSar support function used by interrupt service
*          routine. The function is used as a pseudo ISR for all the FlexIO
*          peripherals.
*
* @param[in]     FlexIO_pDev               Specifies which FlexIO peripheral is used
*                FlexIO_u32IsrStatusTX     Status of TDF flag
*                FlexIO_u32IsrStatusRX     Status of RDF flag
*/
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, SPI_CODE) Spi_FlexIO_TransferStatus
(
    P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev,
    VAR(uint32, AUTOMATIC) FlexIO_u32IsrStatusTX,
    VAR(uint32, AUTOMATIC) FlexIO_u32IsrStatusRX
)
{  
    if(0u != FlexIO_u32IsrStatusRX)
    {
        /* Copy data from FlexIO FIFOD to channels */
        
        Spi_FlexIO_JobTransferFifoDrain(FlexIO_pDev);    
        
        /* check for the channel switch */
        if ((0u == FlexIO_pDev->Spi_FlexIO_ReceivedData) && (0u != FlexIO_pDev->Spi_FlexIO_RemainingChannelsRX))
        {
            /* reached the end of channel => move to the next channel */
            /* Increase Channel indexes */
            FlexIO_pDev->Spi_FlexIO_RemainingChannelsRX--;
            /*
            * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            FlexIO_pDev->Spi_FlexIO_pcCurrentChannelIndexPointerRX++;
        
            if(SPI_MASTER == FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->eSpiPhyUnitMode )
            {
                /* prepare next channel transmission */
                Spi_FlexIO_ChannelTransferFifoInitRX(FlexIO_pDev, *(FlexIO_pDev->Spi_FlexIO_pcCurrentChannelIndexPointerRX));
            }
            else
            {
                /*Do notthing*/
            }
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        /* Do nothing */
    }

    if(0u != FlexIO_u32IsrStatusTX)
    {
        if ((boolean)FALSE == FlexIO_pDev->Spi_FlexIO_bIsEndOfJob)
        {
            /* check for the channel switch */
            if ((0u == FlexIO_pDev->Spi_FlexIO_RemainingData) && (0u != FlexIO_pDev->Spi_FlexIO_RemainingChannelsTX))
            {
                /* reached the end of channel => move to the next channel */
                /* Increase Channel indexes */
                FlexIO_pDev->Spi_FlexIO_RemainingChannelsTX--;
                /*
                * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                FlexIO_pDev->Spi_FlexIO_pcCurrentChannelIndexPointerTX++;
            
                if(SPI_MASTER == FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->eSpiPhyUnitMode )
                {
                    /* prepare next channel transmission */
                    Spi_FlexIO_ChannelTransferFifoInitTX(FlexIO_pDev, *(FlexIO_pDev->Spi_FlexIO_pcCurrentChannelIndexPointerTX));
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                /* Do nothing */
            }
            /* perform the next chunk transmission */
            Spi_FlexIO_JobTransferFifoFill(FlexIO_pDev);
        }
        else
        {
           /* Do nothing */
        }
    }
    else
    {
        /* Do nothing */
    }
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */
  
  
  
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
* @brief   This function is called by TDF or RDF ISRs for the FlexIO units working in PIO_FIFO mode.
* @details Non-AutoSar support function used by interrupt service
*          routine. The function is used as a pseudo ISR for all the FlexIO
*          peripherals.
*
* @param[in]     FlexIO_pDev     Specifies which FlexIO peripheral is used
*
* @implements Spi_FlexIO_IsrFifoRx_Activity
*/
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, SPI_CODE) Spi_FlexIO_IsrFifoRx
    (
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev,
        VAR(uint8, AUTOMATIC) u8SpiFlexIO_ShifterTX,
        VAR(uint8, AUTOMATIC) u8SpiFlexIO_ShifterRX
    )
{
    VAR(uint32, AUTOMATIC) FlexIO_u32IsrStatusTX = 0u;
    VAR(uint32, AUTOMATIC) FlexIO_u32IsrStatusRX = 0u;
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_TX = 0u;
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_RX = 0u;    
    VAR(uint32, SPI_VAR) Spi_FlexIO_Clear_TXRX = 0u;    
    
    /* Get address of Shifter TX/RX */
    Spi_FlexIO_u8Shifter_TX = u8SpiFlexIO_ShifterTX;
    Spi_FlexIO_u8Shifter_RX = u8SpiFlexIO_ShifterRX;
    /* Check if the driver has been initialized */
    if (NULL_PTR != Spi_pcSpiConfigPtr)
    {
        if (SPI_POLLING_MODE != FlexIO_pDev->Spi_FlexIO_AsyncMode)
        {
            if(SPI_MASTER == FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->eSpiPhyUnitMode)
            {
                /*
                * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                FlexIO_u32IsrStatusTX = Mcl_Flexio_ReadShiftStat((uint8)(1u << Spi_FlexIO_u8Shifter_TX));
                /*
                * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                FlexIO_u32IsrStatusRX = (uint32)Mcl_Flexio_ReadShiftStat((uint8)(1u << Spi_FlexIO_u8Shifter_RX));
                /*
                * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                FlexIO_u32IsrStatusTX &= (uint32)Mcl_Flexio_ReadShiftSien((uint8)(1u << Spi_FlexIO_u8Shifter_TX));
            }
            else
            {
                #if (SPI_SLAVE_SUPPORT == STD_ON)
                    FlexIO_u32IsrStatusRX = (uint32)Mcl_Flexio_ReadShiftStat((uint8)(1u << Spi_FlexIO_u8Shifter_RX)); 
                    FlexIO_u32IsrStatusTX = (uint32)Mcl_Flexio_ReadShiftStat((uint8)(1u << Spi_FlexIO_u8Shifter_TX)); 
                #else
                    /* Do nothing */
                #endif
            }
        }
        else
        {
            /* Operation mode is SPI_POLLING_MODE: set u32IsrStatus to poll request flag */
            if(1u == FlexIO_pDev->Spi_FlexIO_u8IsPollRequest)
            {
                FlexIO_u32IsrStatusTX = FlexIO_pDev->Spi_FlexIO_u32IsPollRequestTX;
                FlexIO_u32IsrStatusRX = FlexIO_pDev->Spi_FlexIO_u32IsPollRequestRX;
                /* Clear poll request flag */
                FlexIO_pDev->Spi_FlexIO_u8IsPollRequest = 0u;
            }
        }

        /* check if any enabled isr had been triggered */
        if ((0u != FlexIO_u32IsrStatusTX) || (0u != FlexIO_u32IsrStatusRX))
        {
            /* 
            * check if any enabled isr had been triggered, copy data from FIFO 
            * and prepare next channel transmission, perform the next chunk transmission
            */ 
            Spi_FlexIO_TransferStatus(FlexIO_pDev, FlexIO_u32IsrStatusTX, FlexIO_u32IsrStatusRX);
            
            if ((boolean)TRUE == FlexIO_pDev->Spi_FlexIO_bIsEndOfJob)
            {
                if((0u == FlexIO_pDev->Spi_FlexIO_ReceivedData) && (0u == FlexIO_pDev->Spi_FlexIO_RemainingChannelsRX))
                {
                    if(SPI_JOB_OK != FlexIO_pDev->Spi_FlexIO_pcCurrentJob->pJobState->Result)
                    {
                        /* finish job transfer */
                        if(NULL_PTR != FlexIO_pDev->Spi_FlexIO_pcCurrentJob->pJobState->pAsyncCrtSequenceState)
                        {
                           /* Clear interrupt flag */
                           Mcl_Flexio_WriteShiftSien((uint8)(1u << Spi_FlexIO_u8Shifter_TX), SPI_FLEXIO_CLEAR_FLAG_U8);                            
                           Spi_JobTransferFinished(FlexIO_pDev->Spi_FlexIO_pcCurrentJob);
                        }
                    }
                    else
                    {
                        /* Driver has been initialized and received an unconfigured interrupt, clear RX status flags */
                        Mcl_Flexio_WriteShiftSien((uint8)(1u << Spi_FlexIO_u8Shifter_TX), SPI_FLEXIO_CLEAR_FLAG_U8); 
                        Mcl_Flexio_ClearShiftStat((uint8)(1u << Spi_FlexIO_u8Shifter_RX));
                    }  
                } 
            }
        }
        else
        {
            /* Driver has been initialized and received an unconfigured interrupt, clear status flags */
            /* Disable transmit interrupt */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_Flexio_WriteShiftSien((uint8)(1u << Spi_FlexIO_u8Shifter_TX), SPI_FLEXIO_CLEAR_FLAG_U8);
        }
    }
    else
    {
        /* Driver has not been initialized, clear status flags and Reset the FLEXIO Regs*/
        Mcl_Flexio_ClearShiftStat((uint8)(1u<<Spi_FlexIO_u8Shifter_RX));
        Mcl_Flexio_ClearShiftStat((uint8)(1u<<Spi_FlexIO_u8Shifter_TX));
        /* Clear RX, TX */
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_SHIFTBUFn_ADDR32((uint32) Spi_FlexIO_u8Shifter_TX), Spi_FlexIO_Clear_TXRX);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_SHIFTBUFn_ADDR32((uint32) Spi_FlexIO_u8Shifter_RX), Spi_FlexIO_Clear_TXRX);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_SHIFTBUFBBSn_ADDR32((uint32) Spi_FlexIO_u8Shifter_TX), Spi_FlexIO_Clear_TXRX);
        /*
        * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(FLEXIO_SHIFTBUFBBSn_ADDR32((uint32) Spi_FlexIO_u8Shifter_RX), Spi_FlexIO_Clear_TXRX);
    }
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */  
 
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    /**
* @brief   This function is called by Mcl_FlexioProcessCombinedInterrupt for the FlexIO units working in PIO_FIFO mode.
* @details Non-AutoSar support function used by interrupt service
*          routine. The function is used as a pseudo ISR for all the FlexIO
*          peripherals.
*
* @param[in]     u8ID               ID of Channel
* @param[in]     u8ShifterMask      Shifter flag
* @param[in]     u8ErrMask          Timer error flag
* @param[in]     u8TimerMask        Timer flag
*
* @implements Spi_FlexIO_InterruptHandler_Activity
*/
/*
* @violates @ref Spi_FlexIO_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_FlexIO_InterruptHandler
     (
      VAR(uint8, AUTOMATIC) Spi_FlexIO_u8Offset,
      VAR(uint8, AUTOMATIC) Spi_FlexIO_u8ShifterMask,
      VAR(uint8, AUTOMATIC) Spi_FlexIO_u8ErrMask,
      VAR(uint8, AUTOMATIC) Spi_FlexIO_u8TimerMask
     )
{   
    if (0u != Spi_FlexIO_u8ShifterMask)
    {
        if(0u == Spi_FlexIO_u8Offset)
        {
#ifdef FLEXIOSPI_0_USED
    #if (FLEXIOSPI_0_USED == STD_ON)
            Spi_FlexIO_IsrFifoRx(Spi_FlexIO_HWUNIT2FlexIO(FLEXIOSPI_0_HWUNIT),(uint8)Spi_FlexIO_Physical_Shifter_0,(uint8)Spi_FlexIO_Physical_Shifter_1); 
    #endif       
#endif
        }
        else
        {
            /*Do notthing*/
        }       
        if(1u == Spi_FlexIO_u8Offset)
        {
#ifdef FLEXIOSPI_1_USED
    #if (FLEXIOSPI_1_USED == STD_ON)
            Spi_FlexIO_IsrFifoRx(Spi_FlexIO_HWUNIT2FlexIO(FLEXIOSPI_1_HWUNIT),(uint8)Spi_FlexIO_Physical_Shifter_2,(uint8)Spi_FlexIO_Physical_Shifter_3); 
    #endif       
#endif
        }
        else
        {
            /*Do notthing*/
        }        
    }
    else if (0u != Spi_FlexIO_u8ErrMask)
    {
        /*Do notthing*/
    }
    else if (0u != Spi_FlexIO_u8TimerMask)
    {
        /*Do notthing*/
    }
    else
    {
        /*Do notthitng*/
    }
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */  
/*================================================================================================*/
/**
* @brief   IRQ polling functions.
* @details Configures DMA unit to detect received data via
*          interrupt or by polling a bit in the IER register.
*
* @param[in]     HWUnit     Specifies which FlexIO peripheral is used
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*
*/
/*================================================================================================*/  
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_FlexIO_IrqPoll
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit
    )
{
    P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev;
    VAR(uint32, AUTOMATIC) FlexIO_u32IsrStatusTX = 0u;
    VAR(uint32, AUTOMATIC) FlexIO_u32IsrStatusRX = 0u;
#if (SPI_DMA_USED == STD_ON)
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) FlexIO_pcHWUnitConfig;
#endif

    FlexIO_pDev = Spi_FlexIO_HWUNIT2FlexIO(HWUnit);
    if ((SPI_POLLING_MODE == FlexIO_pDev->Spi_FlexIO_AsyncMode) && (SPI_PHYUNIT_ASYNC_U32 == FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u32IsSync))
    {
#if (SPI_DMA_USED == STD_ON)
        FlexIO_pcHWUnitConfig = FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig;
#endif
        /* Set pool request flag */
        FlexIO_pDev->Spi_FlexIO_u8IsPollRequest = 1u;
#if (SPI_DMA_USED == STD_ON)
        if (0u != FlexIO_pcHWUnitConfig->u16UseDma)
        {
            if (0u != Mcl_DmaIsTransferCompleted(FlexIO_pcHWUnitConfig->u8RxDmaChannel))
            {
                /* Set pool RX request flag */
                FlexIO_pDev->Spi_FlexIO_u32IsPollRequestRX = 1u;
                if(1u == FlexIO_pDev->Spi_FlexIO_u8IsPollRequest)
                {
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_3 Conversions shall not be performed between
                    * a pointer to a function and any type other than an integral type.
                    */
                    /*
                    * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    Mcl_DmaTcdClearDone(FlexIO_pcHWUnitConfig->u8RxDmaChannel) ;
                    Spi_FlexIO_IsrDmaRx(FlexIO_pDev);
                    /* Clear pool request flag */
                    FlexIO_pDev->Spi_FlexIO_u8IsPollRequest = 0u;
                }
            }
            else
            {
                /* Do nothing */
            }
            /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */           
            if (0u != Mcl_DmaIsTransferCompleted(FlexIO_pcHWUnitConfig->u8TxDmaChannel))
            {
                /* Set pool TX request flag */
                FlexIO_pDev->Spi_FlexIO_u32IsPollRequestTX = 1u;
                if(1u == FlexIO_pDev->Spi_FlexIO_u8IsPollRequest)
                {
                     /*
                     * @violates @ref Spi_FlexIO_c_REF_3 Conversions shall not be performed between
                     * a pointer to a function and any type other than an integral type.
                     */
                     /*
                     * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                     */
                     Mcl_DmaTcdClearDone(FlexIO_pcHWUnitConfig->u8TxDmaChannel) ;
                     Spi_FlexIO_IsrDmaTx(FlexIO_pDev);
                     /* Clear pool request flag */
                     FlexIO_pDev->Spi_FlexIO_u8IsPollRequest = 0u;
                }
            }
            else
            {
                /* Do nothing */
            }
        }
        else
#endif /* (SPI_DMA_USED == STD_ON) */
        {
             /*
            * @violates @ref Spi_FlexIO_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_FlexIO_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            FlexIO_u32IsrStatusTX  =  Mcl_Flexio_ReadShiftStat((uint8)(1u<<FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_TX));
            FlexIO_u32IsrStatusRX  =  Mcl_Flexio_ReadShiftStat((uint8)(1u<<FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_RX));
            FlexIO_pDev->Spi_FlexIO_u32IsPollRequestTX = (uint32)FlexIO_u32IsrStatusTX;
            FlexIO_pDev->Spi_FlexIO_u32IsPollRequestRX = (uint32)FlexIO_u32IsrStatusRX; 
            
            if(1u == FlexIO_pDev->Spi_FlexIO_u8IsPollRequest)
            {
                if ((0u != FlexIO_pDev->Spi_FlexIO_u32IsPollRequestTX) || (0u != FlexIO_pDev->Spi_FlexIO_u32IsPollRequestRX))
                {
                    /* Emulate IRQ in PIO_FIFO mode */
                     Spi_FlexIO_IsrFifoRx(FlexIO_pDev, FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_TX, FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u8spiFlexIO_RX);
                }
                else
                {
                    /* Do nothing */
                }
                /* Clear pool request flag */
                FlexIO_pDev->Spi_FlexIO_u8IsPollRequest = 0u; 
            }
        }
    }
    else
    {
        /* Do nothing */
    }
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */
/*================================================================================================*/
#if ((SPI_CANCEL_API == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON))
/**
* @brief   This function is used to request the cancelation of the given sequence for Slave and stop sequence immediately.
* @details This function is used to request the cancelation of the given sequence for Slave and stop sequence immediately.
*          - Sync or Async:       Asynchronous
*
* @param[in]      Sequence            Sequence ID
*
* @pre  parameters: (SPI_CANCEL_API == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON)
*                             
*/
FUNC(void, SPI_CODE) Spi_FlexIO_SlaveCancel(VAR(Spi_SequenceType, AUTOMATIC) Sequence)
{
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) FlexIO_pcJobConfig;
    VAR(Spi_JobType, AUTOMATIC) FlexIO_Job;
    P2CONST(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_CONST) FlexIO_pDev;
    P2CONST(Spi_SequenceStateType, AUTOMATIC, SPI_APPL_CONST) FlexIO_pSequenceState;
    P2CONST(Spi_JobType, AUTOMATIC, SPI_APPL_CONST) FlexIO_pcJob;
#if (SPI_DMA_USED == STD_ON)
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) FlexIO_pcHWUnitConfig;
#endif
    
    /* Set sequence state to Cancel */
    Spi_aSpiSequenceState[Sequence].Result = SPI_SEQ_CANCELLED;
    FlexIO_pSequenceState = &Spi_aSpiSequenceState[Sequence];
    FlexIO_pcJob = FlexIO_pSequenceState->pcCurrentJobIndexPointer;
    FlexIO_Job = *FlexIO_pcJob;
    /*
    * @violates @ref Spi_FlexIO_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */ 
    FlexIO_pcJobConfig = &Spi_pcSpiConfigPtr->pcJobConfig[FlexIO_Job];
    FlexIO_pDev = &Spi_FlexIO_aDeviceState[FlexIO_pcJobConfig->HWUnit];
    if(SPI_SLAVE == FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->eSpiPhyUnitMode)
    {
        /* Stop DMA transfer */
    #if (SPI_DMA_USED == STD_ON)
        if (0u != FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig->u16UseDma)
        {
            /* Disable TX before RX */
            FlexIO_pcHWUnitConfig = FlexIO_pDev->Spi_FlexIO_pcHWUnitConfig;
            Mcl_DmaDisableHwRequest(FlexIO_pcHWUnitConfig->u8TxDmaChannel);
            Mcl_DmaDisableHwRequest(FlexIO_pcHWUnitConfig->u8RxDmaChannel);
        }
        else
        {
            /* Do nothing */
        }
    #endif
          Spi_JobTransferFinished(FlexIO_pcJobConfig);
    }
}
#endif  /* ((SPI_CANCEL_API == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON)) */

/*================================================================================================*/
#define SPI_STOP_SEC_CODE
/*
* @violates @ref Spi_FlexIO_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 #endif /* SPI_ENABLE_FLEXIO == STD_ON */

#ifdef __cplusplus
}
#endif
/** @} */
