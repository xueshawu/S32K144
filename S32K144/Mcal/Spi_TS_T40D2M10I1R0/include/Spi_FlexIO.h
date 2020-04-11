/**
*   @file    Spi_FlexIO.h
*   @implements Spi_FlexIO.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - FlexIO LLD header file.
*   @details FlexIO peripheral LLD header file.

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

#ifndef SPI_FlexIO_H
#define SPI_FlexIO_H

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
* @section Spi_FlexIO_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions.
*
* @section Spi_FlexIO_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character significance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Spi_FlexIO_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.7,
* A function should be used in preference to a function-like macro.
* Compiler abstraction need to implement function-like macros to hide
* compiler specifics from the implementation.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys.h"
#include "Spi_Cfg.h"
#include "Reg_eSys_FlexIOSPI.h"
#if (SPI_ENABLE_FLEXIO == STD_ON)
#include "Reg_eSys_FlexIO.h"
#include "CDD_Mcl.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Spi_FLexIO.h
*/
#define SPI_FLEXIO_VENDOR_ID                    43
/**
* @violates @ref Spi_FlexIO_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define SPI_FLEXIO_AR_RELEASE_MAJOR_VERSION     4
/**
* @violates @ref Spi_FlexIO_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define SPI_FLEXIO_AR_RELEASE_MINOR_VERSION     3
/**
* @violates @ref Spi_FlexIO_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define SPI_FLEXIO_AR_RELEASE_REVISION_VERSION  1
#define SPI_FLEXIO_SW_MAJOR_VERSION             1
#define SPI_FLEXIO_SW_MINOR_VERSION             0
#define SPI_FLEXIO_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Spi_Cfg.h are of the same vendor */
#if (SPI_FLEXIO_VENDOR_ID != SPI_VENDOR_ID_CFG)
    #error "Spi_FlexIO.h and Spi_Cfg.h have different vendor ids"
#endif
/* Check if current file and Spi_Cfg header file are of the same Autosar version */
#if ((SPI_FLEXIO_AR_RELEASE_MAJOR_VERSION    != SPI_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (SPI_FLEXIO_AR_RELEASE_MINOR_VERSION    != SPI_AR_RELEASE_MINOR_VERSION_CFG) || \
     (SPI_FLEXIO_AR_RELEASE_REVISION_VERSION != SPI_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Spi_FlexIO.h and Spi_Cfg.h are different"
#endif
/* Check if current file and Spi_Cfg header file are of the same Software version */
#if ((SPI_FLEXIO_SW_MAJOR_VERSION != SPI_SW_MAJOR_VERSION_CFG) || \
     (SPI_FLEXIO_SW_MINOR_VERSION != SPI_SW_MINOR_VERSION_CFG) || \
     (SPI_FLEXIO_SW_PATCH_VERSION != SPI_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Spi_FlexIO.h and Spi_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  /* Check if the source file and Reg_eSys header file are of the same version */
  #if ((SPI_FLEXIO_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
       (SPI_FLEXIO_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
      #error "AutoSar Version Numbers of Spi_FLexIO.h and Reg_eSys.h are different"
  #endif
#endif

#if (SPI_ENABLE_FLEXIO == STD_ON)
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief  Map HWUnit to FLEXIO device structure.
*/
/*
* @violates @ref Spi_FlexIO_h_REF_3 A function should be used in preference
* to a function-like macro.
*/
#define Spi_FlexIO_HWUNIT2FlexIO(HWUnit)    (&Spi_FlexIO_aDeviceState[(HWUnit)])
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/**
* @brief   Internal structure keeping a set of cached channel attributes.
* @details Internal structure keeping a set of cached channel attributes
*          used by the optimized implementation of Spi_SyncTransmit() for
*          the sequences having only one job.
*/
typedef struct
{
    /**< @brief Channel attributes for CMD in TCR register. */
    VAR(uint8, SPI_VAR) u8LBF;
    /**< @brief Channel attributes for data width. */    
    VAR(uint32, SPI_VAR) u32DataWidth;
    /**< @brief The number of bits data in a frame tranfer  */       
    VAR(uint32, SPI_VAR) u32NumBitsInFrame;
    /**< @brief Cached pointer to the buffer descriptor. */
    P2CONST(Spi_BufferDescriptorType, SPI_VAR, SPI_APPL_CONST) FlexIO_pcBufferDescriptor;
    /**< @brief Cached pointer to the channel states. */
    P2VAR(Spi_ChannelStateType, SPI_VAR, SPI_APPL_DATA) FlexIO_pState;
    /**< @brief Cached default transmit value. */
    VAR(uint32, SPI_VAR) FlexIO_u32DefaultTransmitValue;
} Spi_FlexIO_ChannelCacheAttrsType;

/**
* @brief    Internal structure keeping a set of cached sequences attributes.
* @details  Internal structure keeping a set of cached sequences attributes
*           used by the optimized implementation of Spi_SyncTransmit() for
*           the sequences having only one job.
*/
typedef struct
{
    /**< @brief HW type */
    VAR(uint8, SPI_VAR) u8HWtypeOptimized;
    /**< @brief HWUnit. */
    VAR(Spi_HWUnitType, SPI_VAR) FlexIO_HWUnit;
    /**< @brief Number of channels in sequence. */
    VAR(Spi_ChannelType, SPI_VAR) FlexIO_NumChannels;
    /**< @brief Cached pointer to the sequence job state. */
    P2VAR(Spi_JobStateType, SPI_VAR, SPI_APPL_DATA) FlexIO_pJobState;
    /**< @brief Cached pointer to the sequence FlexIO state. */
    P2VAR(Spi_StatusType, SPI_VAR, SPI_APPL_DATA) FlexIO_pJobStatus;
    /**< @brief Table of channel cached attributes. */
    P2VAR(Spi_FlexIO_ChannelCacheAttrsType, SPI_VAR, SPI_APPL_DATA) FlexIO_pChannels;
    /**< @brief Cached value of the FlexIO HW Unit memory mapped registers base address. */
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32BaseAddress;
    /**< @brief The shifter for TX. */
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_TX;
    /**< @brief The shifter for RX. */
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_RX;
    /**< @brief The Timer for Clk. */
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CLK;
    /**< @brief The Timer for CS. */
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CS;
    
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8EndOfJobFlag;    
    VAR(Spi_ModeType, AUTOMATIC) Spi_FlexIO_MASTER;
    VAR(uint8, AUTOMATIC) Spi_FlexIO_u8CPOL;
    VAR(uint8, AUTOMATIC) Spi_FlexIO_u8CPHA;
    VAR(uint32, AUTOMATIC) Spi_FlexIO_u32FSIZE;
    VAR(uint8, AUTOMATIC)  Spi_FlexIO_u8LBF;
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    VAR(uint32, AUTOMATIC) Spi_FlexIO_u32PSC[2];
#else
    VAR(uint32, AUTOMATIC) Spi_FlexIO_u32PSC;
#endif
    VAR(uint32, AUTOMATIC) Spi_FlexIO_u32SHIFTSIEN;
    VAR(uint32, AUTOMATIC) Spi_FlexIO_au32SHIFTCFG[NUM_SHIFTR_TIMR_SUPPORT];
    VAR(uint32, AUTOMATIC) Spi_FlexIO_au32SHIFTCTL[NUM_SHIFTR_TIMR_SUPPORT];
    
    VAR(uint32, AUTOMATIC) Spi_FlexIO_au32TIMCMP[NUM_SHIFTR_TIMR_SUPPORT];
    VAR(uint32, AUTOMATIC) Spi_FlexIO_au32TIMCFG[NUM_SHIFTR_TIMR_SUPPORT];
    VAR(uint32, AUTOMATIC) Spi_FlexIO_au32TIMCTL[NUM_SHIFTR_TIMR_SUPPORT];
} Spi_FlexIO_SequenceCacheAttrsType;
#endif /* (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON) */


/**
* @brief Internal structure keeping a state of transfer process.
* @details  Internal structure keeping a state of transfer process
*           used by Spi_FlexIO_SyncTransmit() & Spi_FlexIO_SyncTransmit_fast().
*/
typedef struct
{
    /**< @brief Memory mapped register base address. */
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32BaseAddress;
     /**< @brief Pointer to the Tx buffer of the channel currently in transmission. */
     P2VAR(Spi_DataBufferType, SPI_VAR, SPI_APPL_DATA) Spi_FlexIO_pBufferTX;
     /**< @brief Pointer to the Rx buffer of the channel currently in transmission. */
     P2VAR(Spi_DataBufferType, SPI_VAR, SPI_APPL_DATA) Spi_FlexIO_pBufferRX;
     /**< @brief The frame default data value to be used for the channel in transmission. */    
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32DefaultTransmitValue;
     /**< @brief The data width value to be used for the transmission. */
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32DataWidthTX;
    /**< @brief The data width value to be used for the data receive.*/
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32DataWidthRX;
    /**< @brief Number of channels in a pending job, not yet transmitted. */
    VAR(Spi_ChannelType, SPI_VAR) Spi_FlexIO_ChannelsCountTX;
    /**< @brief Number of channels in a pending job, not yet receive. */
    VAR(Spi_ChannelType, SPI_VAR) Spi_FlexIO_ChannelsCountRX;
    /**< @brief Number of frames in a pending channel, not yet transmitted. */
    VAR(Spi_NumberOfDataType, SPI_VAR) Spi_FlexIO_LengthTX;
    /**< @brief Number of frames in a pending channel, not yet receive. */
    VAR(Spi_NumberOfDataType, SPI_VAR) Spi_FlexIO_LengthRX;
    /**< @brief Position in ChannelIndexList of TX channel*/
    P2CONST(Spi_ChannelType, SPI_VAR, SPI_APPL_CONST) Spi_FlexIO_pcChannelIndexListTX;
    /**< @brief Position in ChannelIndexList of RX channel*/
    P2CONST(Spi_ChannelType, SPI_VAR, SPI_APPL_CONST) Spi_FlexIO_pcChannelIndexListRX;
    /**< @brief Indicates if this is the last chunk of data in the job. */
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8EndOfJobFlag;
    /**< @brief The shifter for TX. */
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_TX;
    /**< @brief The shifter for RX. */
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Shifter_RX;
    /**< @brief The Timer for Clk. */
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CLK;
    /**< @brief The Timer for CS. */
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8Timer_CS;
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
    /**< @brief Position in table of channel cached attributes. */
    P2VAR(Spi_FlexIO_ChannelCacheAttrsType, SPI_VAR, SPI_APPL_DATA) Spi_FlexIO_pChannelRX;
#endif

    VAR(Spi_ModeType, AUTOMATIC) Spi_FlexIO_MASTER;
    VAR(uint8, AUTOMATIC) Spi_FlexIO_u8CPOL;
    VAR(uint8, AUTOMATIC) Spi_FlexIO_u8CPHA;
    VAR(uint32, AUTOMATIC) Spi_FlexIO_u32FSIZE;
    VAR(uint8, AUTOMATIC)  Spi_FlexIO_u8LBF;
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    VAR(uint32, AUTOMATIC) Spi_FlexIO_u32PSC[2];
#else
    VAR(uint32, AUTOMATIC) Spi_FlexIO_u32PSC;
#endif
    VAR(uint32, AUTOMATIC) Spi_FlexIO_u32SHIFTSIEN;
    VAR(uint32, AUTOMATIC) Spi_FlexIO_au32SHIFTCFG[NUM_SHIFTR_TIMR_SUPPORT];
    VAR(uint32, AUTOMATIC) Spi_FlexIO_au32SHIFTCTL[NUM_SHIFTR_TIMR_SUPPORT];
    
    VAR(uint32, AUTOMATIC) Spi_FlexIO_au32TIMCMP[NUM_SHIFTR_TIMR_SUPPORT];
    VAR(uint32, AUTOMATIC) Spi_FlexIO_au32TIMCFG[NUM_SHIFTR_TIMR_SUPPORT];
    VAR(uint32, AUTOMATIC) Spi_FlexIO_au32TIMCTL[NUM_SHIFTR_TIMR_SUPPORT];
}Spi_FlexIO_SyncStateType;

/**
* @brief This structure holds runtime configuration parameters for Spi handler.
*/
typedef struct
{
    /**< @brief Reference to the corresponding HWUnit config instance. */
    P2CONST(Spi_HWUnitConfigType, SPI_VAR, SPI_APPL_CONST) Spi_FlexIO_pcHWUnitConfig;
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (SPI_DMA_USED == STD_ON)
    /**< @brief Address of the master TX MMIO DMA descriptor. */
    P2VAR(uint32, SPI_VAR, SPI_APPL_DATA) Spi_FlexIO_pu32TxDmaTcd;
    /**< @brief Address of the master RX MMIO DMA descriptor. */
    P2VAR(uint32, SPI_VAR, SPI_APPL_DATA) Spi_FlexIO_pu32RxDmaTcd;
#endif    
    /**< @brief TCR register used to define different transfer attributes for external device. */
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32ExternalDeviceTCR;
    /**< @brief CCR register used to define different transfer attributes for external device. */
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32ExternalDeviceCCR;
    /**< @brief Pointer to the Tx buffer of the channel currently in transmission. */
     P2VAR(Spi_DataBufferType, SPI_VAR, SPI_APPL_DATA) Spi_FlexIO_pCurrentTxBuffer;
     /**< @brief Pointer to the Rx buffer of the channel currently in transmission. */
     P2VAR(Spi_DataBufferType, SPI_VAR, SPI_APPL_DATA) Spi_FlexIO_pCurrentRxBuffer;
      /**< @brief The frame default data value to be used for the channel in transmission. */
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32TransmitDefaultData;
    /**< @brief Position in ChannelIndexList to the channel in transmission. */
    /**
    * @violates @ref Spi_FlexIO_h_REF_2 The compiler/linker shall be checked to
    * ensure that 31 character significance and case sensitivity are supported for
    * external identifiers.
    */
    P2CONST(Spi_ChannelType, SPI_VAR, SPI_APPL_CONST) Spi_FlexIO_pcCurrentChannelIndexPointerTX;
    /**< @brief Position in ChannelIndexList to the channel in transmission. */
    /**
    * @violates @ref Spi_FlexIO_h_REF_2 The compiler/linker shall be checked to
    * ensure that 31 character significance and case sensitivity are supported for
    * external identifiers.
    */
    P2CONST(Spi_ChannelType, SPI_VAR, SPI_APPL_CONST) Spi_FlexIO_pcCurrentChannelIndexPointerRX;
    /**< @brief Number of channels in a pending async job, not yet transmitted. */
    VAR(Spi_ChannelType, SPI_VAR) Spi_FlexIO_RemainingChannelsTX;
    /**< @brief Number of channels in a pending async job, not yet transmitted. */
    VAR(Spi_ChannelType, SPI_VAR) Spi_FlexIO_RemainingChannelsRX;
    /**< @brief Number of frames in a pending channel, not yet transmitted. */
    VAR(Spi_NumberOfDataType, SPI_VAR) Spi_FlexIO_RemainingData;
    /**< @brief Number of sent frames, which must be read back in the next ISR call. */
    VAR(Spi_NumberOfDataType, SPI_VAR) Spi_FlexIO_SentFrames;
    /**< @brief Reference to the current job. */
    P2CONST(Spi_JobConfigType, SPI_VAR, SPI_APPL_CONST) Spi_FlexIO_pcCurrentJob;
    /**< @brief Indicates if this is the last chunk of data in the job. */
    VAR(boolean, SPI_VAR) Spi_FlexIO_bIsEndOfJob;
#endif
    /**< @brief Memory mapped registers base address. */
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32BaseAddress;    
    /**< @brief FlexIO Transmit command register address. */
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32TCRAddress;
    /**< @brief FlexIO Transmit data register address. */
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32TDRAddress;    
    /**< @brief FlexIO Receive data register address. */
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32RDRAddress;    
    /**< @brief FlexIO Status register address. */
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32SRAddress;
    /**< @brief FlexIO Clock Configuration Register address. */
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32CCRAddress;
    /**< @brief The frame command value to be used for the transmission. */
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32CurrentCmd;
    /**< @brief Asynchronous operating mode of the FlexIO unit. */
    VAR(Spi_AsyncModeType, SPI_VAR) Spi_FlexIO_AsyncMode;
    /**< @brief Pointer to the Autosar HW unit SPI state. */
    P2VAR(Spi_StatusType, SPI_VAR, SPI_APPL_DATA) Spi_FlexIO_pStatus;
    VAR(Spi_NumberOfDataType, SPI_VAR) Spi_FlexIO_ReceivedData;
    /**< @brief Flag that indicates a poll request enable*/
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8IsPollRequest;
    /**< @brief Flag that indicates a poll request TX */
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32IsPollRequestTX;
    /**< @brief Flag that indicates a poll request RX*/
    VAR(uint32, SPI_VAR) Spi_FlexIO_u32IsPollRequestRX;
    /**< @brief Flag that indicates the first channel of job*/
    VAR(uint8, SPI_VAR) Spi_FlexIO_u8FirstChannelOfJobFlag;
    
    VAR(Spi_HWUnitType, SPI_VAR) Spi_HWUnit;
    VAR(uint8, AUTOMATIC) Spi_FlexIO_u8DeviceStateCPOL;
    VAR(uint8, AUTOMATIC) Spi_FlexIO_u8DeviceStateCPHA;
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    VAR(uint32, AUTOMATIC) Spi_FlexIO_u32DeviceStatePSC[2];
#else
    VAR(uint32, AUTOMATIC) Spi_FlexIO_u32DeviceStatePSC;
#endif
    VAR(uint8, AUTOMATIC)  Spi_FlexIO_u8LBF;

}Spi_FlexIO_DeviceStateType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))    
    /**
    * @violates @ref Spi_FlexIO_h_REF_2 The compiler/linker shall be checked to
    * ensure that 31 character significance and case sensitivity are supported for
    * external identifiers.
    */
    #define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    /**
    * @violates @ref Spi_FlexIO_h_REF_2 The compiler/linker shall be checked to
    * ensure that 31 character significance and case sensitivity are supported for
    * external identifiers.
    */
    #define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */
/**
* @violates @ref Spi_FlexIO_h_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 /**
* @brief Keep the HWUnit internal fields.
*/
extern VAR(Spi_FlexIO_DeviceStateType, SPI_VAR) Spi_FlexIO_aDeviceState[SPI_MAX_HWUNIT];

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))   
    /**
    * @violates @ref Spi_FlexIO_h_REF_2 The compiler/linker shall be checked to
    * ensure that 31 character significance and case sensitivity are supported for
    * external identifiers.
    */
    #define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    /**
    * @violates @ref Spi_FlexIO_h_REF_2 The compiler/linker shall be checked to
    * ensure that 31 character significance and case sensitivity are supported for
    * external identifiers.
    */
    #define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */
/**
* @violates @ref Spi_FlexIO_h_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Spi_FlexIO_h_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 #if (SPI_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief Holds the mode of the Dual Clock.
*/
extern VAR(Spi_DualClockModeType, AUTOMATIC) Spi_FlexIO_ClockMode;

#endif /* #if (SPI_DUAL_CLOCK_MODE == STD_ON) */

#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/**
* @brief    Pointer table to the cached information structure
* @details  Pointer table to the cached information structure, for one job sequences,
*           or NULL, for unoptimized sequences.
*/
extern P2VAR(Spi_FlexIO_SequenceCacheAttrsType, AUTOMATIC, SPI_VAR) Spi_FlexIO_apOneJobSeqsOptimized[SPI_MAX_SEQUENCE];
#endif 
#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Spi_FlexIO_h_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 /*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
/**
* @violates @ref Spi_FlexIO_h_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
FUNC(void, SPI_CODE) Spi_FlexIO_Init
(
     VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
     P2VAR(Spi_StatusType, AUTOMATIC, SPI_APPL_DATA) pStatus
);

FUNC(void, SPI_CODE) Spi_FlexIO_DeInit
(
     VAR(Spi_HWUnitType, AUTOMATIC) HWUnit
);
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
FUNC(Std_ReturnType, SPI_CODE) Spi_FlexIO_SyncTransmit
(
   VAR(Spi_SequenceType, AUTOMATIC) Sequence
);
#endif
#if (((SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0)) && \
    (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON))
FUNC(void, SPI_CODE) Spi_FlexIO_PrepareCacheInformation(void);
#endif
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
FUNC(Std_ReturnType, SPI_CODE) Spi_FlexIO_SyncTransmit_Fast
    (
        P2CONST(Spi_FlexIO_SequenceCacheAttrsType, AUTOMATIC, SPI_APPL_CONST) pcSequence
    );
#endif
#endif
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
FUNC(Std_ReturnType, SPI_CODE) Spi_FlexIO_SyncTransmitJob
(
   P2VAR(Spi_FlexIO_SyncStateType, AUTOMATIC,SPI_APPL_DATA) Spi_FlexIO_pSyncTransmitState
);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_FlexIO_JobTransfer
(
   P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig
);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_FlexIO_IrqConfig
(
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode
);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_FlexIO_IrqPoll
(
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit
);
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
FUNC(void, SPI_CODE) Spi_FlexIO_IsrDmaTx
(
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev
);
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
FUNC(void, SPI_CODE) Spi_FlexIO_IsrDmaRx
(
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev
);
#endif  

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_FlexIO_IsrFifoRx
(
        P2VAR(Spi_FlexIO_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) FlexIO_pDev,
        VAR(uint8, AUTOMATIC) u8SpiFlexIO_ShifterTX,
        VAR(uint8, AUTOMATIC) u8SpiFlexIO_ShifterRX
);
#endif
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_FlexIO_InterruptHandler
(
        VAR(uint8, AUTOMATIC) Spi_FlexIO_u8Offset,
        VAR(uint8, AUTOMATIC) Spi_FlexIO_u8ShifterMask,
        VAR(uint8, AUTOMATIC) Spi_FlexIO_u8ErrMask,
        VAR(uint8, AUTOMATIC) Spi_FlexIO_u8TimerMask
);
#endif
 
#if ((SPI_CANCEL_API == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON))
FUNC(void, SPI_CODE) Spi_FlexIO_SlaveCancel(VAR(Spi_SequenceType, AUTOMATIC) Sequence);
#endif

#define SPI_STOP_SEC_CODE
/**
* @violates @ref Spi_FlexIO_h_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 #endif /*SPI_ENABLE_FLEXIO == STD_ON*/

#ifdef __cplusplus 
}
#endif

#endif /* SPI_FlexIO_H */

/** @} */

