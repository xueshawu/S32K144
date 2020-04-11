/**
*   @file    Spi_Ipw.c
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
* @section Spi_IPW_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Spi_IPW_c_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_IPW_c_REF_3
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are
* supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Spi_IPW_c_REF_4
* Violates MISRA 2004 Required Rule 17.4,
* Array indexing shall be the only allowed form of pointer arithmetic.
* Gain in generated code speed
*
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Spi.h"
#include "Spi_IPW.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SPI_IPW_MODULE_ID_C                     83
#define SPI_IPW_VENDOR_ID_C                     43
/*
* @violates @ref Spi_IPW_c_REF_3 The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are
* supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*/
#define SPI_IPW_AR_RELEASE_MAJOR_VERSION_C      4
/*
* @violates @ref Spi_IPW_c_REF_3 The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are
* supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*/
#define SPI_IPW_AR_RELEASE_MINOR_VERSION_C      3
/*
* @violates @ref Spi_IPW_c_REF_3 The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are
* supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*/
#define SPI_IPW_AR_RELEASE_REVISION_VERSION_C   1
/*
* @violates @ref Spi_IPW_c_REF_3 The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are
* supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*/
#define SPI_IPW_SW_MAJOR_VERSION_C              1
#define SPI_IPW_SW_MINOR_VERSION_C              0
#define SPI_IPW_SW_PATCH_VERSION_C              1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if this file and Spi.h are of the same vendor */
#if (SPI_IPW_VENDOR_ID_C != SPI_VENDOR_ID)
    #error "Spi_IPW.c and Spi.h have different vendor ids"
#endif

/* Check if this header file and Spi_IPW.h are of the same vendor */
#if (SPI_IPW_VENDOR_ID_C != SPI_IPW_VENDOR_ID)
    #error "Spi_IPW.c and Spi_IPW.h have different vendor ids"
#endif

/* Check if current file and Spi.h header file are of the same Autosar version */
#if ((SPI_IPW_AR_RELEASE_MAJOR_VERSION_C != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_IPW_AR_RELEASE_MINOR_VERSION_C != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_IPW_AR_RELEASE_REVISION_VERSION_C != SPI_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_IPW.c and Spi.h are different"
#endif

  /* Check if current file and Spi header file are of the same Software version */
#if ((SPI_IPW_SW_MAJOR_VERSION_C != SPI_SW_MAJOR_VERSION) || \
     (SPI_IPW_SW_MINOR_VERSION_C != SPI_SW_MINOR_VERSION) || \
     (SPI_IPW_SW_PATCH_VERSION_C != SPI_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_IPW.c and Spi.h are different"
#endif

/* Check if current file and Spi_IPW header file are of the same Autosar version */
#if ((SPI_IPW_AR_RELEASE_MAJOR_VERSION_C != SPI_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_IPW_AR_RELEASE_MINOR_VERSION_C != SPI_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SPI_IPW_AR_RELEASE_REVISION_VERSION_C != SPI_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_IPW.c and Spi_IPW.h are different"
#endif

  /* Check if current file and Spi_IPW header file are of the same Software version */
#if ((SPI_IPW_SW_MAJOR_VERSION_C != SPI_IPW_SW_MAJOR_VERSION) || \
     (SPI_IPW_SW_MINOR_VERSION_C != SPI_IPW_SW_MINOR_VERSION) || \
     (SPI_IPW_SW_PATCH_VERSION_C != SPI_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_IPW.c and Spi_IPW.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
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

#define SPI_START_SEC_CODE
/*
* @violates @ref Spi_IPW_c_REF_1 #include directives should only be preceded by preprocessor directives or comments.
* <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*/
/*
* @violates @ref Spi_IPW_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/*================================================================================================*/
/**
* Initialize function.
* Initialize the specific Spi unit with all configuration
*          parameters like Baud Rate, CS, Clock polarity, etc.
*          Also this function initializes all structure parameters
*          from the specific FlexIO unit.
*/
/*================================================================================================*/
FUNC(void, SPI_CODE) Spi_Ipw_Init(VAR(Spi_HWUnitType, AUTOMATIC) HWUnit, P2VAR(Spi_StatusType, AUTOMATIC, SPI_APPL_DATA) pStatus)
{
/*
* @violates @ref Spi_IPW_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic.
* Gain in generated code speed
*/
if (Spi_pcSpiConfigPtr->pcHWUnitConfig[HWUnit].u8HWtype == LPSPI)
    {
        Spi_LPspi_Init(HWUnit, pStatus);
    }
else
#if (SPI_ENABLE_FLEXIO == STD_ON)
    {
        Spi_FlexIO_Init(HWUnit,pStatus);
    }
#else
    {
        /* Do notthing */
    }
#endif
}
/*================================================================================================*/
/**
* This function performs the de-initialization of a specific peripheral unit.
* This function de-initializes all configured values
*
*/
/*================================================================================================*/
FUNC(void, SPI_CODE) Spi_Ipw_DeInit(VAR(Spi_HWUnitType, AUTOMATIC) HWUnit)
{
/*
* @violates @ref Spi_IPW_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic.
* Gain in generated code speed
*/
if (Spi_pcSpiConfigPtr->pcHWUnitConfig[HWUnit].u8HWtype == LPSPI)
    {
        Spi_LPspi_DeInit(HWUnit);
    }
else
#if (SPI_ENABLE_FLEXIO == STD_ON)
    {
        Spi_FlexIO_DeInit(HWUnit);
    } 
#else
    {
        /* Do notthing */
    }
#endif
}

/*================================================================================================*/
/**
*  Initialize PrepareCacheInformation function.
*  Computes sequence / job configuration parameters like
*          parameters like Baud Rate, CS, Clock polarity, etc.
*          This cached values will be used in sync transmissions in
*          order to optimize the time.
*/
/*================================================================================================*/
#if (((SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0)) && \
    (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON))
FUNC(void, SPI_CODE) Spi_Ipw_PrepareCacheInformation(void)
{
#if (defined LPSPI_0_ENABLED) || (defined LPSPI_1_ENABLED) || (defined LPSPI_2_ENABLED)
    #if (LPSPI_0_ENABLED == STD_ON) || (LPSPI_1_ENABLED == STD_ON) || (LPSPI_2_ENABLED == STD_ON)
        Spi_LPspi_PrepareCacheInformation();
    #endif
#endif
#if (SPI_ENABLE_FLEXIO == STD_ON)
    #if (defined FLEXIOSPI_0_USED) || (defined FLEXIOSPI_1_USED)
        #if (FLEXIOSPI_0_USED == STD_ON) || (FLEXIOSPI_1_USED == STD_ON)
            Spi_FlexIO_PrepareCacheInformation();
        #endif
    #endif
#endif
}
#endif  /* #if (((SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0)) && \
    (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON))*/
/*================================================================================================*/
/**
*    This function performs the synchronous transmission for a sequence.
*/
/*================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
FUNC(Std_ReturnType, SPI_CODE) Spi_Ipw_SyncTransmit(VAR(Spi_SequenceType, AUTOMATIC) Sequence)
{
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
    P2CONST(Spi_LPspi_SequenceCacheAttrsType, AUTOMATIC, SPI_APPL_CONST) pLPspiSequenceCache;
#if (SPI_ENABLE_FLEXIO == STD_ON)
    P2CONST(Spi_FlexIO_SequenceCacheAttrsType, AUTOMATIC, SPI_APPL_CONST) pFlexIOSequenceCache;
#endif
    VAR(Spi_JobType, AUTOMATIC) Ipw_Job;
    P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_APPL_CONST) Ipw_pcSequenceConfig;
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) Ipw_pcJobConfig;
#endif  
VAR(Std_ReturnType, AUTOMATIC) Ipw_Status = (Std_ReturnType)E_NOT_OK;
/*
* @violates @ref Spi_IPW_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic.
* Gain in generated code speed
*/
if (Spi_pcSpiConfigPtr->pcSequenceConfig[Sequence].u8HWtypeOfSequence == LPSPI)
    {
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)        
    pLPspiSequenceCache = Spi_LPspi_apOneJobSeqsOptimized[Sequence];
    if (NULL_PTR != pLPspiSequenceCache)
    {
        /*
        * @violates @ref Spi_IPW_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic.
        * Gain in generated code speed
        */
        Ipw_pcSequenceConfig = &Spi_pcSpiConfigPtr->pcSequenceConfig[Sequence];
        /* Get the job id */
        /*
        * @violates @ref Spi_IPW_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic.
        * Gain in generated code speed
        */
        Ipw_Job = Ipw_pcSequenceConfig->pcJobIndexList[0];
        /*
        * @violates @ref Spi_IPW_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic.
        * Gain in generated code speed
        */
        Ipw_pcJobConfig = &Spi_pcSpiConfigPtr->pcJobConfig[Ipw_Job];
        /* start job notification to assert the non-cs pin,
                when non-cs pin is used as chipselect*/
        if (NULL_PTR != Ipw_pcJobConfig->pfStartNotification)
        {
            Ipw_pcJobConfig->pfStartNotification();
        }
        else
        {
            /* Do nothing */
        }
        Ipw_Status = Spi_LPspi_SyncTransmit_Fast(pLPspiSequenceCache);
        /* end job notification to assert the non-cs pin,
        when non-cs pin is used as chipselect*/
        if (NULL_PTR != Ipw_pcJobConfig->pfEndNotification)
        {
            Ipw_pcJobConfig->pfEndNotification();
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        Ipw_Status = Spi_LPspi_SyncTransmit(Sequence);
    }
#else
    Ipw_Status = Spi_LPspi_SyncTransmit(Sequence);
#endif
    }
else
#if (SPI_ENABLE_FLEXIO == STD_ON)
    {
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)        
    pFlexIOSequenceCache = Spi_FlexIO_apOneJobSeqsOptimized[Sequence];
    if (NULL_PTR != pFlexIOSequenceCache)
    {
        /*
        * @violates @ref Spi_IPW_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic.
        * Gain in generated code speed
        */
        Ipw_pcSequenceConfig = &Spi_pcSpiConfigPtr->pcSequenceConfig[Sequence];
        /* Get the job id */
        /*
        * @violates @ref Spi_IPW_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic.
        * Gain in generated code speed
        */
        Ipw_Job = Ipw_pcSequenceConfig->pcJobIndexList[0];
        /*
        * @violates @ref Spi_IPW_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic.
        * Gain in generated code speed
        */
        Ipw_pcJobConfig = &Spi_pcSpiConfigPtr->pcJobConfig[Ipw_Job];
        /* start job notification to assert the non-cs pin,
                when non-cs pin is used as chipselect*/
        if (NULL_PTR != Ipw_pcJobConfig->pfStartNotification)
        {
            Ipw_pcJobConfig->pfStartNotification();
        }
        else
        {
            /* Do nothing */
        }
        Ipw_Status = Spi_FlexIO_SyncTransmit_Fast(pFlexIOSequenceCache);
        /* end job notification to assert the non-cs pin,
        when non-cs pin is used as chipselect*/
        if (NULL_PTR != Ipw_pcJobConfig->pfEndNotification)
        {
            Ipw_pcJobConfig->pfEndNotification();
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        Ipw_Status = Spi_FlexIO_SyncTransmit(Sequence);
    }
#else
    Ipw_Status = Spi_FlexIO_SyncTransmit(Sequence);
#endif
    }
#else /* #if (SPI_ENABLE_FLEXIO == STD_ON) */
    {
        /* Do notthing */
    }
#endif
return Ipw_Status;    
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) ) */

                    /* Spi_Ipw_JobTransfer */
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_Ipw_JobTransfer(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig)
{
/*
* @violates @ref Spi_IPW_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic.
* Gain in generated code speed
*/
if (Spi_pcSpiConfigPtr->pcHWUnitConfig[pcJobConfig->HWUnit].u8HWtype == LPSPI)
    {
        Spi_LPspi_JobTransfer(pcJobConfig);
    }
else
#if (SPI_ENABLE_FLEXIO == STD_ON)
    {
        Spi_FlexIO_JobTransfer(pcJobConfig); 
    }
#else
    {
        /* Do notthing */
    }
#endif
} 
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))  
/*================================================================================================*/
/**
* @brief   IRQ configure functions.
*/
/*================================================================================================*/
FUNC(void, SPI_CODE) Spi_Ipw_IrqConfig(VAR(Spi_HWUnitType, AUTOMATIC) HWUnit, VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode)
{
/*
* @violates @ref Spi_IPW_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic.
* Gain in generated code speed
*/
if (Spi_pcSpiConfigPtr->pcHWUnitConfig[HWUnit].u8HWtype == LPSPI)
    {
        Spi_LPspi_IrqConfig(HWUnit, AsyncMode);
    }
else
#if (SPI_ENABLE_FLEXIO == STD_ON)
    {
        Spi_FlexIO_IrqConfig(HWUnit,AsyncMode);
    }
#else
    {
        /* Do notthing */
    }
#endif
}
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*================================================================================================*/
/**
* IRQ polling functions.
* Configures DMA unit to detect received data via
*          interrupt or by polling a bit in the IER register.
*/
/*================================================================================================*/  
FUNC(void, SPI_CODE) Spi_Ipw_IrqPoll(VAR(Spi_HWUnitType, AUTOMATIC) HWUnit)
{
/*
* @violates @ref Spi_IPW_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic.
* Gain in generated code speed
*/
if (Spi_pcSpiConfigPtr->pcHWUnitConfig[HWUnit].u8HWtype == LPSPI)
    {
        Spi_LPspi_IrqPoll(HWUnit);
    }
else
#if (SPI_ENABLE_FLEXIO == STD_ON)
    {
        Spi_FlexIO_IrqPoll(HWUnit);
    }
#else
    {
        /* Do notthing */
    }
#endif    
}
#endif
/*================================================================================================*/
/**
*  This function is used to request the cancelation of the given sequence for Slave and stop sequence immediately.
*  This function is used to request the cancelation of the given sequence for Slave and stop sequence immediately.                            
*/
/*================================================================================================*/
#if ((SPI_CANCEL_API == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON))
FUNC(void, SPI_CODE) Spi_Ipw_SlaveCancel(VAR(Spi_SequenceType, AUTOMATIC) Sequence)
{
/*
* @violates @ref Spi_IPW_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic.
* Gain in generated code speed
*/
if (Spi_pcSpiConfigPtr->pcSequenceConfig[Sequence].u8HWtypeOfSequence == LPSPI)
    {
        Spi_LPspi_SlaveCancel(Sequence);
    }
else
#if (SPI_ENABLE_FLEXIO == STD_ON)
    {
        Spi_FlexIO_SlaveCancel(Sequence);
    }
#else
    {
        /* Do notthing */
    }
#endif    
}
#endif /* #if ((SPI_CANCEL_API == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON)) */
/*================================================================================================*/
/**
*  This function is used to set mode clock for tranfer .                           
*/
/*================================================================================================*/
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
FUNC(void, SPI_CODE) SPI_IPW_SET_CLOCK_MODE(VAR(Spi_DualClockModeType,AUTOMATIC) ClockMode)
{
    Spi_LPspi_ClockMode = ClockMode;
#if (SPI_ENABLE_FLEXIO == STD_ON)
    Spi_FlexIO_ClockMode = ClockMode;
#endif
}
#endif
 
#define SPI_STOP_SEC_CODE
/*
* @violates @ref Spi_IPW_c_REF_1 #include directives should only be preceded by preprocessor directives or comments.
* <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*/
/*
* @violates @ref Spi_IPW_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#ifdef __cplusplus
}
#endif
/** @} */
