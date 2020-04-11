/**
*   @file    I2c_FlexIO.c
*   @version 1.0.1
*
*   @brief   AUTOSAR I2c - FLEXIO.
*   @details File containing the low level driver of the FLEXIO IP.
*
*   @addtogroup I2C
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : LPI2C,FlexIO
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
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*
* @section I2c_FlexIO_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents of a header 
* file being included twice. This comes from the order of includes in the .c file and from include dependencies. 
* As a safe approach, any file must include all its dependencies. Header files are already protected against double
* inclusions.
*
* @section I2c_FlexIO_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by other preprocessor 
* directives or comments. AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section I2c_FlexIO_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, This violation is due to the casting pointers to other types used in macros for 
* reading or writing data from address location of controller register.
*
* @section I2c_FlexIO_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, Not required from Autosar specification.
*
* @section I2c_FlexIO_c_REF_5
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 character significance and
* case sensitivity are supported for external identifiers. This violation is due to the requirement that requests to have
* a file version check.
*
* @section I2c_FlexIO_c_REF_6
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer arithmetic. This violation 
* is due to the use of pointer arithmetic, to access the channel parameters, the indexing of the pointer is taken care and 
* hence the unintended memory location will not be accessed
*
* @section I2c_FlexIO_c_REF_7
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and an integral type
* The cast is used to access memory mapped registers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_I2c.h"

#if (STD_ON == I2C_FLEXIO_USED)
#include "I2c_FlexIO.h"
#include "Reg_eSys_FlexIO.h"
#include "SchM_I2c.h"
#include "CDD_Mcl.h"
#include "StdRegMacros.h"

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           I2c_FlexIO.c
*/
#define I2C_FLEXIO_VENDOR_ID_C                      43
#define I2C_FLEXIO_MODULE_ID_C                      255
/**
* @violates @ref I2c_FlexIO_c_REF_5 The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_FLEXIO_AR_RELEASE_MAJOR_VERSION_C       4
/**
* @violates @ref I2c_FlexIO_c_REF_5 The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_FLEXIO_AR_RELEASE_MINOR_VERSION_C       3
/**
* @violates @ref I2c_FlexIO_c_REF_5 The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_FLEXIO_AR_RELEASE_REVISION_VERSION_C    1
#define I2C_FLEXIO_SW_MAJOR_VERSION_C               1
#define I2C_FLEXIO_SW_MINOR_VERSION_C               0
#define I2C_FLEXIO_SW_PATCH_VERSION_C               1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2C header file are of the same vendor */
#if (I2C_FLEXIO_VENDOR_ID_C != I2C_VENDOR_ID)
    #error "I2c_FlexIO.c and CDD_I2c.h have different vendor ids"
#endif
/* Check if current file and I2C header file are of the same module */
#if (I2C_FLEXIO_MODULE_ID_C != I2C_MODULE_ID)
    #error "I2c_FlexIO.c and CDD_I2c.h have different module ids"
#endif
/* Check if current file and I2c_FlexIO header file are of the same vendor */
#if (I2C_FLEXIO_VENDOR_ID_C != I2C_FLEXIO_VENDOR_ID)
    #error "I2c_FlexIO.c and I2c_FlexIO.h have different vendor ids"
#endif
/* Check if current file and I2c_FlexIO header file are of the same module */
#if (I2C_FLEXIO_MODULE_ID_C != I2C_FLEXIO_MODULE_ID)
    #error "I2c_FlexIO.c and I2c_FlexIO.h have different module ids"
#endif
/* Check if current file and CDD_I2c.h header file are of the same Autosar version */
#if ((I2C_FLEXIO_AR_RELEASE_MAJOR_VERSION_C    != I2C_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_FLEXIO_AR_RELEASE_MINOR_VERSION_C    != I2C_AR_RELEASE_MINOR_VERSION) || \
     (I2C_FLEXIO_AR_RELEASE_REVISION_VERSION_C != I2C_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of I2c_FlexIO.c and CDD_I2c.h are different"
#endif
/* Check if current file and CDD_I2c.h header file are of the same Software version */
#if ((I2C_FLEXIO_SW_MAJOR_VERSION_C != I2C_SW_MAJOR_VERSION) || \
     (I2C_FLEXIO_SW_MINOR_VERSION_C != I2C_SW_MINOR_VERSION) || \
     (I2C_FLEXIO_SW_PATCH_VERSION_C != I2C_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of I2c_FlexIO.c and CDD_I2c.h are different"
#endif

/* Check if current file and I2c_FlexIO.h header file are of the same Autosar version */
#if ((I2C_FLEXIO_AR_RELEASE_MAJOR_VERSION_C    != I2C_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_FLEXIO_AR_RELEASE_MINOR_VERSION_C    != I2C_FLEXIO_AR_RELEASE_MINOR_VERSION) || \
     (I2C_FLEXIO_AR_RELEASE_REVISION_VERSION_C != I2C_FLEXIO_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of I2c_FlexIO.c and I2c_FlexIO.h are different"
#endif
/* Check if current file and I2c_FlexIO.h header file are of the same Software version */
#if ((I2C_FLEXIO_SW_MAJOR_VERSION_C != I2C_FLEXIO_SW_MAJOR_VERSION) || \
     (I2C_FLEXIO_SW_MINOR_VERSION_C != I2C_FLEXIO_SW_MINOR_VERSION) || \
     (I2C_FLEXIO_SW_PATCH_VERSION_C != I2C_FLEXIO_SW_PATCH_VERSION)     \
    )
    #error "Software Version Numbers of I2c_FlexIO.c and I2c_FlexIO.h are different"
#endif
/* Check if current file and DEM header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the source file and StdRegMacros header file are of the same version */
    #if ((I2C_FLEXIO_AR_RELEASE_MAJOR_VERSION_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (I2C_FLEXIO_AR_RELEASE_MINOR_VERSION_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of I2c_FlexIO.c and StdRegMacros.h are different"
    #endif
  
    #if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* Check if the source file and Dem header file are of the same version */
      #if ((I2C_FLEXIO_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
           (I2C_FLEXIO_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION)    \
          )
          #error "AutoSar Version Numbers of I2c_FlexIO.c and Dem.h are different"
      #endif
    #endif

    #if ((I2C_FLEXIO_AR_RELEASE_MAJOR_VERSION_C  != MCL_AR_RELEASE_MAJOR_VERSION) || \
         (I2C_FLEXIO_AR_RELEASE_MINOR_VERSION_C  != MCL_AR_RELEASE_MINOR_VERSION)   \
        )
        #error "AutoSar Version Numbers of I2c_FlexIO.c and CDD_Mcl.h are different"
    #endif
    /* Check if current file and Reg_eSys_FlexIO.h header file are of the same Autosar version */
    #if ((I2C_FLEXIO_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
        (I2C_FLEXIO_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_FLEXIO_AR_RELEASE_MINOR_VERSION)     \
        )
        #error "AutoSar Version Numbers of I2c_FlexIO.c and Reg_eSys_FlexIO.h are different"
    #endif
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

#define I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref I2c_FlexIO_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref I2c_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

#if (STD_ON == I2C_DMA_USED)
/**
* @brief    The TCD descriptor used for the TX DMA channel for sending or receiving data.
*/
static VAR(Mcl_DmaTcdAttributesType, I2C_VAR) I2c_FlexIO_aTxDmaCfgDesc[I2C_FLEXIO_MAX_CHANNELS];
/**
* @brief    The TCD descriptor used for the RX DMA channel for sending or receiving data.
*/
static VAR(Mcl_DmaTcdAttributesType, I2C_VAR) I2c_FlexIO_aRxDmaCfgDesc[I2C_FLEXIO_MAX_CHANNELS];
#endif

#define I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref I2c_FlexIO_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref I2c_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"


#define I2C_START_SEC_VAR_NO_INIT_8

/**
* @violates @ref I2c_FlexIO_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref I2c_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

#if (STD_ON == I2C_DMA_USED)
/**
* @brief    The array contains for each FlexIO sub channel the ID of the DMA channel used for the TX shifter. 
*/
static VAR(uint8, I2C_VAR) I2c_FlexIO_au8TxDmaChannel[I2C_FLEXIO_MAX_CHANNELS];
/**
* @brief    The array contains for each FlexIO sub channel the ID of the DMA channel used for the RX shifter.
*/
static VAR(uint8, I2C_VAR) I2c_FlexIO_au8RxDmaChannel[I2C_FLEXIO_MAX_CHANNELS];
#endif

/**
* @brief    Buffer used by master channels to send and receive data.
*/
static volatile P2VAR(uint8, I2C_VAR, I2C_APPL_DATA) I2c_FlexIO_aup8DataBuffer[I2C_FLEXIO_MAX_CHANNELS];

/**
* @brief    Indexes used by master channels for sending and receiving.
*/
static volatile VAR(uint8,I2C_VAR) I2c_FlexIO_au8CurrentIndex[I2C_FLEXIO_MAX_CHANNELS];

/**
* @brief    Total number of bytes used by master channels for sending and receiving.
*/
static VAR(uint8,I2C_VAR) I2c_FlexIO_au8NumberOfBytes[I2C_FLEXIO_MAX_CHANNELS];

/**
* @brief    SCL Timer IDs used by the FLEXIO channels.
*/
static VAR(uint8,I2C_VAR) I2c_FlexIO_au8SclTimerId[I2C_FLEXIO_MAX_CHANNELS];

/**
* @brief    TX Shifter IDs used by the FLEXIO channels.
*/
static VAR(uint8,I2C_VAR) I2c_FlexIO_au8TxShifterId[I2C_FLEXIO_MAX_CHANNELS];

/**
* @brief    RX Shifter IDs used by the FLEXIO channels.
*/
static VAR(uint8,I2C_VAR) I2c_FlexIO_au8RxShifterId[I2C_FLEXIO_MAX_CHANNELS];

/**
* @brief    This is used when receiving data to indicate that the address byte was sent and 
            successfully received by the slave.
*/
static volatile VAR( uint8, I2C_VAR) I2c_FlexIO_au8AddrReceived[I2C_FLEXIO_MAX_CHANNELS];

/**
* @brief    This is used when receiving data to count the number of times the TX shifter was filled with
            0xFF to leave the SDA line free.
*/
static volatile VAR( uint8, I2C_VAR) I2c_FlexIO_au8TxShifterBytes[I2C_FLEXIO_MAX_CHANNELS];

/**
* @brief    This is used to log errors during a transmission. If this is 1 then an error occurred during
            the current transmission.
*/
static volatile VAR( uint8, I2C_VAR) I2c_FlexIO_au8ErrorsFound[I2C_FLEXIO_MAX_CHANNELS];

#define I2C_STOP_SEC_VAR_NO_INIT_8

/**
* @violates @ref I2c_FlexIO_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref I2c_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"


#define I2C_START_SEC_VAR_NO_INIT_BOOLEAN
/**
* @violates @ref I2c_FlexIO_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref I2c_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"


/**
* @brief    Used to indicate if a Repeated Start (Sr) should be generated instead of a STOP.
*/
static VAR(boolean, I2C_VAR) I2c_FlexIO_abRepeatedStart[I2C_FLEXIO_MAX_CHANNELS];


#define I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN
/**
* @violates @ref I2c_FlexIO_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref I2c_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define I2C_START_SEC_CODE
/**
* @violates @ref I2c_FlexIO_c_REF_1 #include statements in a file should only be preceded by other preprocessor directives or comments.
* @violates @ref I2c_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents of a header file being included twice.
* internal linkage unless external linkage is required.
*/
#include "I2c_MemMap.h"

#if (STD_ON == I2C_DMA_USED)
static FUNC (void, I2C_CODE) I2c_FlexIO_DmaTxShifterProcessing(CONST(uint8, AUTOMATIC) u8HwChannel);
static FUNC (void, I2C_CODE) I2c_FlexIO_DmaRxShifterProcessing(CONST(uint8, AUTOMATIC) u8HwChannel);
static FUNC (Std_ReturnType, I2C_CODE) I2c_FlexIO_DmaSend(
                                                           CONST(uint8, AUTOMATIC) u8HwChannel,
                                                           P2CONST(I2c_RequestType, AUTOMATIC, I2C_APPL_CONST) pRequestPtr
                                                         );
static FUNC (Std_ReturnType, I2C_CODE) I2c_FlexIO_DmaReceive(
                                                           CONST(uint8, AUTOMATIC) u8HwChannel,
                                                           P2CONST(I2c_RequestType, AUTOMATIC, I2C_APPL_CONST) pRequestPtr
                                                         );
#endif

static FUNC (void, I2C_CODE) I2c_FlexIO_EnableInterrupts(CONST(uint8, AUTOMATIC) u8FlexIOChannel);
static FUNC (void, I2C_CODE) I2c_FlexIO_DisableInterrupts(CONST(uint8, AUTOMATIC) u8FlexIOChannel);

static FUNC (void, I2C_CODE) I2c_FlexIO_AsyncErrorHandler(VAR(uint8, AUTOMATIC) u8HwChannel, VAR(uint8, AUTOMATIC) u8ErrorStatus);
static FUNC (Std_ReturnType, I2C_CODE) I2c_FlexIO_SyncErrorHandler(VAR(uint8, AUTOMATIC) u8FlexIOChannel);

static FUNC (void, I2C_CODE) I2c_FlexIO_AsyncProcessShifters(CONST(uint8, AUTOMATIC) u8HwChannel, CONST(uint8, AUTOMATIC) u8ShifterStatus);
static FUNC (void, I2C_CODE) I2c_FlexIO_AsyncProcessTimers(CONST(uint8, AUTOMATIC) u8HwChannel, CONST(uint8, AUTOMATIC) u8TimerStatus);

static FUNC (void, I2C_CODE) I2c_FlexIO_ProcessTxShifter(CONST(uint8, AUTOMATIC) u8HwChannel);
static FUNC (void, I2C_CODE) I2c_FlexIO_ProcessRxShifter(CONST(uint8, AUTOMATIC) u8HwChannel);

static FUNC (void, I2C_CODE) I2c_FlexIO_SendAddress(CONST(uint8, AUTOMATIC) u8HwChannel, P2CONST(I2c_RequestType, AUTOMATIC, I2C_APPL_CONST) pRequestPtr);
static FUNC (Std_ReturnType, I2C_CODE) I2c_FlexIO_SyncTransfer(CONST(uint8, AUTOMATIC) u8HwChannel);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#if (STD_ON == I2C_DMA_USED)

/**
* @brief   Used to process TX shifter data when sending/receiving data using a DMA channel.
* @details This function is used for the TX Shifter of a FlexIO channel when using a DMA channel to send/receive data.
*
* @param[in]    u8HwChannel     FLEXIO channel to be addressed.
*
* @return       void
*
*/
static FUNC (void, I2C_CODE) I2c_FlexIO_DmaTxShifterProcessing(CONST(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8FlexIOChannel       = u8HwChannel - I2C_FLEXIO_FIRST_CHANNEL_U8;

    /* Disable the Hw Request */
    Mcl_DmaDisableHwRequest(I2c_FlexIO_au8TxDmaChannel[u8FlexIOChannel]);
    
    /* Disable the TX DMA requests in the FlexIO hardware unit */
    Mcl_Flexio_WriteShiftSden((uint8)(1U << I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]), 0U);
}

/**
* @brief   Used to process RX shifter data after sending/receiving data using a DMA channel.
* @details This function is used for the RX Shifter of a FlexIO channel when using a DMA channel to send/receive data.
*
* @param[in]    u8HwChannel     FLEXIO channel to be addressed.
*
* @return       void
*
*/
static FUNC (void, I2C_CODE) I2c_FlexIO_DmaRxShifterProcessing(CONST(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8FlexIOChannel   = u8HwChannel - I2C_FLEXIO_FIRST_CHANNEL_U8;
    VAR( sint8, AUTOMATIC) s8LogicalChannel = -1;
    VAR( uint8, AUTOMATIC) u8ShifterStatus  = 0x0U;
    VAR( uint32, AUTOMATIC) u32Timeout      = I2C_TIMEOUT_LOOPS;


    /* Disable the Hw Request */
    Mcl_DmaDisableHwRequest(I2c_FlexIO_au8RxDmaChannel[u8FlexIOChannel]);
    /* Disable the RX DMA requests in the FlexIO hardware unit */
    Mcl_Flexio_WriteShiftSden((uint8)(1U << I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]), 0U);

    s8LogicalChannel = I2c_as8ChannelHardwareMap[u8HwChannel];
    
    if ( I2C_CH_RECEIVE == I2c_aeChannelStatus[s8LogicalChannel] )
    {
        /* Send NACK for last byte */
        /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32(FLEXIO_SHIFTCFGn_ADDR32((uint32)I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]), FLEXIO_SHIFTCFG_SSTOP_MASK_U32, FLEXIO_STOP_BIT_VALUE_1_U32);

        /* Configure RX shifter to expect NACK */
        /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32(FLEXIO_SHIFTCFGn_ADDR32((uint32)I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]), FLEXIO_SHIFTCFG_SSTOP_MASK_U32, FLEXIO_STOP_BIT_VALUE_1_U32);

        if ((boolean)FALSE == I2c_FlexIO_abRepeatedStart[u8FlexIOChannel])
        {
            /* Send the STOP byte */
            /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE32(FLEXIO_SHIFTBUFBBSn_ADDR32((uint32)I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]), FLEXIO_STOP_BYTE_VALUE_U32);
        }
        else
        {
            /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE32(FLEXIO_SHIFTBUFBBSn_ADDR32((uint32)I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]), FLEXIO_LEAVE_SDA_FREE_U32);
        }

        /* Wait until the RX shifter receives the last byte */
        u32Timeout = I2C_TIMEOUT_LOOPS;
        do
        {
            /* Check if the RX Shifter received data */
            /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
            u8ShifterStatus = Mcl_Flexio_ReadShiftStat((uint8)FLEXIO_SHIFTSTAT_SSF_MASK_U32);
            u32Timeout--;
        }while (
                    (u32Timeout > (uint32)0x0U) && 
                    (
                        (uint8)FLEXIO_SHIFTSTAT_SSF_U32(I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]) != 
                        (u8ShifterStatus & (uint8)FLEXIO_SHIFTSTAT_SSF_U32(I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]))
                    )
               );
        
        if ( (uint32)0x0U == u32Timeout)
        {
            /* Change the state of the channel to indicate that an error is present */
            I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_ERROR_PRESENT;
#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if ((uint32)STD_ON == I2c_pDemCfg->I2c_E_TimeoutFailureCfg.state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)I2c_pDemCfg->I2c_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif
        }
        else
        {
            /* If the last byte was received save it in the data buffer */
            /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2c_FlexIO_c_REF_6 MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer */
            /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
            I2c_FlexIO_aup8DataBuffer[u8FlexIOChannel][I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel] - 1U] = (uint8)REG_READ32(FLEXIO_SHIFTBUFBISn_ADDR32((uint32)I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]));
        }

    }
}

/**
* @brief   Starts sending an I2C message from the master use DMA.
* @details Generate (repeated) START and send the address of the slave to initiate a transmission.
*          Fills the TX FIFO and start transmitting data.
*
* @param[in]   u8HwChannel      I2C channel to be addressed.
* @param[in]   pRequestPtr      Pointer to the structure that contains the information necessary to begin the
*                               transmission: the address of the slave, high speed mode, expect NACK, number of bytes
*                               and the data buffer
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*
*/
static FUNC (Std_ReturnType, I2C_CODE) I2c_FlexIO_DmaSend(
                                                           CONST(uint8, AUTOMATIC) u8HwChannel,
                                                           P2CONST(I2c_RequestType, AUTOMATIC, I2C_APPL_CONST) pRequestPtr
                                                         )
{
    static VAR(uint8, I2C_VAR) I2c_FlexIO_au8AuxiliaryTxBuffer[I2C_FLEXIO_MAX_CHANNELS][FLEXIO_MAX_NUMBER_OF_BYTES_U32 + 2U];
    static VAR(uint32, I2C_VAR) I2c_FlexIO_u32DiscardData;

    VAR(uint8, AUTOMATIC) u8FlexIOChannel       = u8HwChannel - I2C_FLEXIO_FIRST_CHANNEL_U8;
    VAR(uint8, AUTOMATIC) u8TempIndex           = 0x0U;
    VAR(uint32, AUTOMATIC) u32TimerCompareValue = 0x0U;

    /* Initialize the current index to 0 */
    I2c_FlexIO_au8CurrentIndex[u8FlexIOChannel] = 0x00U;
    /* Initialize the number of bytes to send */
    I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel] = pRequestPtr->u8BufferSize;

    I2c_FlexIO_aup8DataBuffer[u8FlexIOChannel] = pRequestPtr->pDataBuffer;

    /* Compute number of SCL ticks including address and set them in the CMP register of the timer */
    /* ((The number of bytes + 1 byte for the address) * the number of edges (2 for each bit)) + 1 (the stop bit) */
    u32TimerCompareValue = ((uint32)((uint32)((((uint32)pRequestPtr->u8BufferSize + 1U) * 18U) + 1U) & 0xFFU) << 8U);
    
    /* Write the number of ticks calculated before keeping the baud bits unchanged */
    /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(FLEXIO_TIMCMPn_ADDR32((uint32)I2c_FlexIO_au8SclTimerId[u8FlexIOChannel]), FLEXIO_TIMCMP_BITS_NUMBER_MASK_U32, u32TimerCompareValue);
    I2c_FlexIO_au8AuxiliaryTxBuffer[u8FlexIOChannel][0U] = (uint8)(pRequestPtr->SlaveAddress & (uint16)(~(uint16)FLEXIO_READ_BIT_U8));
    
    /* Shift all the data bytes and copy them in the auxiliary buffer */
    for (u8TempIndex = 0U; u8TempIndex < (I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel]); u8TempIndex++)
    {
        /** @violates @ref I2c_FlexIO_c_REF_6 MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer */
        /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
        I2c_FlexIO_au8AuxiliaryTxBuffer[u8FlexIOChannel][u8TempIndex + 1U] = (uint8)I2c_FlexIO_aup8DataBuffer[u8FlexIOChannel][u8TempIndex];
    }
    /* Add the stop byte */
    I2c_FlexIO_au8AuxiliaryTxBuffer[u8FlexIOChannel][u8TempIndex + 1U] = 0x00U;

    /* Set the destination for the DMA channel the I2c_FlexIO_u32DiscardData variable */
    /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    I2c_FlexIO_aRxDmaCfgDesc[u8FlexIOChannel].u32daddr = (uint32)(&I2c_FlexIO_u32DiscardData);
    /* Set the number of iterations. This is the number of data bytes + the number of address bytes. */
    I2c_FlexIO_aRxDmaCfgDesc[u8FlexIOChannel].u32iter  = (uint32)I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel] + 1U;
    /* The offset for the destination buffer is 0, because we want to discard all the bytes */
    I2c_FlexIO_aRxDmaCfgDesc[u8FlexIOChannel].u32doff  = 0U;
    
    /* Configure the DMA channel with the configured settings */
    Mcl_DmaConfigChannel(I2c_FlexIO_au8RxDmaChannel[u8FlexIOChannel], &I2c_FlexIO_aRxDmaCfgDesc[u8FlexIOChannel]);

    /* Set the source for the DMA channel as the pointer to the auxiliary buffer */
    /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    I2c_FlexIO_aTxDmaCfgDesc[u8FlexIOChannel].u32saddr = (uint32)(&(I2c_FlexIO_au8AuxiliaryTxBuffer[u8FlexIOChannel]));
    /* Set the number of iterations equal to the number of data bytes + the number of address bytes + the stop byte */
    I2c_FlexIO_aTxDmaCfgDesc[u8FlexIOChannel].u32iter  = (uint32)I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel] + 2U;
    /* The offset for the data buffer is 8 bits */
    I2c_FlexIO_aTxDmaCfgDesc[u8FlexIOChannel].u32soff  = DMA_OFFSET_8_BITS;
    
    /* Configure the DMA channel with the configured settings */
    Mcl_DmaConfigChannel(I2c_FlexIO_au8TxDmaChannel[u8FlexIOChannel], &I2c_FlexIO_aTxDmaCfgDesc[u8FlexIOChannel]);
    
    /* Enable the notification at the end of the transfer */
    Mcl_DmaEnableNotification(I2c_FlexIO_au8TxDmaChannel[u8FlexIOChannel], MCL_DMA_TRANSFER_COMPLETE);
    
    /* Enable the notification at the end of the transfer */
    Mcl_DmaEnableNotification(I2c_FlexIO_au8RxDmaChannel[u8FlexIOChannel], MCL_DMA_TRANSFER_COMPLETE);
    
    /* Enable the Hw Request to start the DMA transfer */
    Mcl_DmaEnableHwRequest(I2c_FlexIO_au8RxDmaChannel[u8FlexIOChannel]);
    
    /* Enable the Hw Request to start the DMA transfer */
    Mcl_DmaEnableHwRequest(I2c_FlexIO_au8TxDmaChannel[u8FlexIOChannel]);

    /* Enable the TX and RX DMA requests in the FlexIO hardware unit */
    Mcl_Flexio_WriteShiftSden(
                (uint8)(1U << I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]) | (uint8)(1U << I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]), 
                (uint8)(1U << I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]) | (uint8)(1U << I2c_FlexIO_au8RxShifterId[u8FlexIOChannel])
                             );

    /* Enable the error and timer interrupts */
    I2c_FlexIO_EnableInterrupts(u8FlexIOChannel);

    return (Std_ReturnType)E_OK;
}

/**
* @brief   Sends a command to the slave for receiving a number of bytes use DMA.
* @details Depending on the transmitMode it either receives the bytes synchronous or asynchronous.
*
* @param[in]   u8HwChannel      I2C channel to be addressed.
* @param[in]   pRequestPtr      Pointer to the structure that contains the information necessary to begin the
*                               transmission: the address of the slave, high speed mode, expect NACK, number of bytes
*                               and the data buffer
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*
*/
static FUNC (Std_ReturnType, I2C_CODE) I2c_FlexIO_DmaReceive(
                                                                CONST(uint8, AUTOMATIC) u8HwChannel,
                                                                P2CONST(I2c_RequestType, AUTOMATIC, I2C_APPL_CONST) pRequestPtr
                                                            )
{
    static VAR(uint32, I2C_VAR) I2c_FlexIO_u32LeaveSdaFree;

    VAR(uint8, AUTOMATIC) u8FlexIOChannel  = u8HwChannel - I2C_FLEXIO_FIRST_CHANNEL_U8;
    VAR(uint8, AUTOMATIC) u8ShifterStatus  = 0x0U;
    VAR(uint32, AUTOMATIC) u32Timeout      = I2C_TIMEOUT_LOOPS;
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn  = (Std_ReturnType)E_NOT_OK;

    /* Initialize the current index to 0 */
    I2c_FlexIO_au8CurrentIndex[u8FlexIOChannel] = 0x00U;
    /* Initialize the number of bytes to send */
    I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel] = pRequestPtr->u8BufferSize;

    if (1U == I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel])
    {
        /* Send the slave address */
        I2c_FlexIO_SendAddress(u8HwChannel, pRequestPtr);
        /* Receive the bytes synchronous */
        u8TmpReturn = I2c_FlexIO_SyncTransfer(u8HwChannel);
    }
    else
    {
        I2c_FlexIO_aup8DataBuffer[u8FlexIOChannel] = pRequestPtr->pDataBuffer;

        I2c_FlexIO_u32LeaveSdaFree = FLEXIO_LEAVE_SDA_FREE_U32;

        /* Set the destination for the DMA channel the auxiliary buffer */
        /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
        I2c_FlexIO_aRxDmaCfgDesc[u8FlexIOChannel].u32daddr = (uint32)I2c_FlexIO_aup8DataBuffer[u8FlexIOChannel];
        /* Set the number of iterations equal to the number of bytes - 1 because the address is sent before and the RX event will be discarded, and the last byte will be received in the DMA TX notification */
        I2c_FlexIO_aRxDmaCfgDesc[u8FlexIOChannel].u32iter  = (uint32)I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel] - 1U;
        /* The offset for the destination buffer is 32 bits, because we want to save all the bytes */
        I2c_FlexIO_aRxDmaCfgDesc[u8FlexIOChannel].u32doff  = DMA_OFFSET_8_BITS;

        /* Configure the DMA channel with the configured settings */
        Mcl_DmaConfigChannel(I2c_FlexIO_au8RxDmaChannel[u8FlexIOChannel], &I2c_FlexIO_aRxDmaCfgDesc[u8FlexIOChannel]);

        /* Set the source for the DMA channel as the pointer to the address of I2c_FlexIO_u32LeaveSdaFree to leave the SDA line free */
        /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
        I2c_FlexIO_aTxDmaCfgDesc[u8FlexIOChannel].u32saddr = (uint32)(&I2c_FlexIO_u32LeaveSdaFree);
        /* Set the number of iterations equal to the number of bytes + 1 to leave the line free for all bytes, including the response after the address is sent */
        I2c_FlexIO_aTxDmaCfgDesc[u8FlexIOChannel].u32iter  = (uint32)I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel];
        /* The offset for the data buffer is 0, because we always want to send 0xFF. The stop byte will be sent from the TX DMA notification */
        I2c_FlexIO_aTxDmaCfgDesc[u8FlexIOChannel].u32soff  = 0U;

        /* Configure the DMA channel with the configured settings */
        Mcl_DmaConfigChannel(I2c_FlexIO_au8TxDmaChannel[u8FlexIOChannel], &I2c_FlexIO_aTxDmaCfgDesc[u8FlexIOChannel]);

        /* Enable the notification at the end of the transfer */
        Mcl_DmaEnableNotification(I2c_FlexIO_au8TxDmaChannel[u8FlexIOChannel], MCL_DMA_TRANSFER_COMPLETE);

        /* Enable the notification at the end of the transfer */
        Mcl_DmaEnableNotification(I2c_FlexIO_au8RxDmaChannel[u8FlexIOChannel], MCL_DMA_TRANSFER_COMPLETE);

        /* Enable the Hw Request to start the DMA transfer */
        Mcl_DmaEnableHwRequest(I2c_FlexIO_au8RxDmaChannel[u8FlexIOChannel]);

        /* Enable the Hw Request to start the DMA transfer */
        Mcl_DmaEnableHwRequest(I2c_FlexIO_au8TxDmaChannel[u8FlexIOChannel]);

        SuspendAllInterrupts();
        /* Send the address as usual */
        I2c_FlexIO_SendAddress(u8HwChannel, pRequestPtr);

        /* Enable the TX DMA requests in the FlexIO hardware unit */
        Mcl_Flexio_WriteShiftSden((uint8)(1U << I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]), (uint8)(1U << I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]));

        /* Wait until the RX shifter receives the response after the address is sent */
        u32Timeout = I2C_TIMEOUT_LOOPS;
        do
        {
            /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
            u8ShifterStatus = Mcl_Flexio_ReadShiftStat((uint8)FLEXIO_SHIFTSTAT_SSF_MASK_U32);
            u32Timeout--;
        } while (
                    (u32Timeout > (uint32)0x0U) && 
                    (
                        FLEXIO_SHIFTSTAT_SSF_U32(I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]) !=
                        (u8ShifterStatus & FLEXIO_SHIFTSTAT_SSF_U32(I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]))
                    )
                );

        /* If the RX shifter doesn't receive anything and a timeout occurs, change the status of the channel and stop the transfer */
        if ( (uint32)0x0U == u32Timeout)
        {
            u8TmpReturn = (Std_ReturnType)E_NOT_OK;
            /* Change the state of the channel to indicate that an error is present */
            I2c_aeChannelStatus[I2c_as8ChannelHardwareMap[u8HwChannel]] = I2C_CH_ERROR_PRESENT;
        #if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if ((uint32)STD_ON == I2c_pDemCfg->I2c_E_TimeoutFailureCfg.state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)I2c_pDemCfg->I2c_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
            }
        #endif
        }
        else
        {
            /* If the RX shifter receives data discard it and configure the shifter for receiving data bytes */
            /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
            (void)REG_READ32(FLEXIO_SHIFTBUFBISn_ADDR32((uint32)I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]));

            /* Configure TX shifter to send ACK */
            /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_RMW32(FLEXIO_SHIFTCFGn_ADDR32((uint32)I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]), FLEXIO_SHIFTCFG_SSTOP_MASK_U32, FLEXIO_STOP_BIT_VALUE_0_U32);

            /* Enable the TX and RX DMA requests in the FlexIO hardware unit */
            Mcl_Flexio_WriteShiftSden(
                        (uint8)(1U << I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]) | (uint8)(1U << I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]), 
                        (uint8)(1U << I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]) | (uint8)(1U << I2c_FlexIO_au8RxShifterId[u8FlexIOChannel])
                                     );

            /* Enable the error and timer interrupts */
            I2c_FlexIO_EnableInterrupts(u8FlexIOChannel);

            u8TmpReturn = (Std_ReturnType)E_OK;
        }
        ResumeAllInterrupts();
    }

    return u8TmpReturn;
}
#endif


/**
* @brief   Used to process both sub-channels' shifter statuses of a FlexIO module in an asynchronous transfer configured to use interrupts.
* @details This function is called by "I2c_FlexIO_InterruptProcessing" to process the shifter events of both sub-channels.
*
* @param[in]   u8HwChannel          I2C channel to be addressed.
* @param[in]   u8ShifterStatus      The status of the shifters.
*
* @return      void
*
*/
static FUNC (void, I2C_CODE) I2c_FlexIO_AsyncProcessShifters(CONST(uint8, AUTOMATIC) u8HwChannel, CONST(uint8, AUTOMATIC) u8ShifterStatus)
{
    VAR(uint8, AUTOMATIC) u8FlexIOChannel  = u8HwChannel - I2C_FLEXIO_FIRST_CHANNEL_U8;
    VAR(sint8, AUTOMATIC) s8LogicalChannel = I2c_as8ChannelHardwareMap[u8HwChannel];

#if (STD_ON == I2C_DMA_USED)
    if (I2C_INTERRUPT_MODE == (*I2c_pConfig->I2c_pHwConfig)[s8LogicalChannel].eAsyncMethod)
    {
#endif
        if (I2C_CH_ERROR_PRESENT != I2c_aeChannelStatus[s8LogicalChannel])
        {
            /* If the RX shifter flag is set process the RX shifter event */
            if (
                  (uint8)FLEXIO_SHIFTSTAT_SSF_U32(I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]) == 
                  (u8ShifterStatus & (uint8)FLEXIO_SHIFTSTAT_SSF_U32(I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]))
               )
            {
               I2c_FlexIO_ProcessRxShifter(u8HwChannel);
            }

            /* If the TX shifter flag is set process the RX shifter event */
            if (
                  (uint8)FLEXIO_SHIFTSTAT_SSF_U32(I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]) == 
                  (u8ShifterStatus & (uint8)FLEXIO_SHIFTSTAT_SSF_U32(I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]))
               )
            {
               I2c_FlexIO_ProcessTxShifter(u8HwChannel);
            }
        }
#if (STD_ON == I2C_DMA_USED)
    }
#endif
}


/**
* @brief   Used to process the timer event triggered by a FlexIO sub-channel of a FlexIO module in an asynchronous transfer (configured to use either DMA or interrupts).
* @details This function is called by "I2c_FlexIO_InterruptHandler" to process the timer event of a sub-channel.
*
* @param[in]   u8HwChannel         The hardware channel that triggered the timer event.
*
* @return      void
*
*/
static FUNC (void, I2C_CODE) I2c_FlexIO_AsyncProcessTimers(CONST(uint8, AUTOMATIC) u8HwChannel, CONST(uint8, AUTOMATIC) u8TimerStatus)
{
    VAR(uint8, AUTOMATIC) u8FlexIOChannel  = u8HwChannel - I2C_FLEXIO_FIRST_CHANNEL_U8;
    VAR(sint8, AUTOMATIC) s8LogicalChannel = I2c_as8ChannelHardwareMap[u8HwChannel];
#if (defined(I2C_MASTER_RECEIVE_COMPLETE_NOTIFICATION) || defined(I2C_MASTER_TRANSMIT_COMPLETE_NOTIFICATION))
    VAR(I2c_StatusType, AUTOMATIC) ePreviousChannelStatus;
#endif

    /* Check if the timer expired and the transmission did not have errors */
    if (
            (uint8)FLEXIO_TIMSTAT_TSF_U32(I2c_FlexIO_au8SclTimerId[u8FlexIOChannel]) == 
            (u8TimerStatus & (uint8)FLEXIO_TIMSTAT_TSF_U32(I2c_FlexIO_au8SclTimerId[u8FlexIOChannel]))
       )
    {
        /* Disable the interrupts to end the transfer */
        I2c_FlexIO_DisableInterrupts(u8FlexIOChannel);

        /* Restore the shifter configuration */
        /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32(FLEXIO_SHIFTCFGn_ADDR32((uint32)I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]), FLEXIO_SHIFTCFG_SSTOP_MASK_U32, FLEXIO_STOP_BIT_VALUE_0_U32);

        if (0x1U == I2c_FlexIO_au8ErrorsFound[u8FlexIOChannel])
        {
            I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_ERROR_PRESENT;
            I2c_FlexIO_au8ErrorsFound[u8FlexIOChannel] = 0x0U;
        }
        else
        {
#if (defined(I2C_MASTER_TRANSMIT_COMPLETE_NOTIFICATION) || defined(I2C_MASTER_RECEIVE_COMPLETE_NOTIFICATION))
            ePreviousChannelStatus = I2c_aeChannelStatus[s8LogicalChannel];
#endif
            I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_FINISHED;

#ifdef I2C_MASTER_TRANSMIT_COMPLETE_NOTIFICATION
            if (I2C_CH_SEND == ePreviousChannelStatus)
            {
#if (STD_ON == I2C_DMA_USED)
                if (I2C_INTERRUPT_MODE == (*I2c_pConfig->I2c_pHwConfig)[s8LogicalChannel].eAsyncMethod)
                {
#endif
                    I2C_MASTER_TRANSMIT_COMPLETE_NOTIFICATION((uint8)s8LogicalChannel, (uint8)(I2c_FlexIO_au8CurrentIndex[u8FlexIOChannel] - (uint8)0x01U));
#if (STD_ON == I2C_DMA_USED)
                }
                else
                {
                    I2C_MASTER_TRANSMIT_COMPLETE_NOTIFICATION((uint8)s8LogicalChannel, I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel]); 
                }
#endif
            }
#endif

#ifdef I2C_MASTER_RECEIVE_COMPLETE_NOTIFICATION
            if (I2C_CH_RECEIVE == ePreviousChannelStatus)
            {
#if (STD_ON == I2C_DMA_USED)
                if (I2C_INTERRUPT_MODE == (*I2c_pConfig->I2c_pHwConfig)[s8LogicalChannel].eAsyncMethod)
                {
#endif
                    I2C_MASTER_RECEIVE_COMPLETE_NOTIFICATION((uint8)s8LogicalChannel, I2c_FlexIO_au8CurrentIndex[u8FlexIOChannel]);
#if (STD_ON == I2C_DMA_USED)
                }
                else
                {
                    I2C_MASTER_RECEIVE_COMPLETE_NOTIFICATION((uint8)s8LogicalChannel, I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel]);
                }
#endif
            }
#endif
        }
    }
}

/**
* @brief   Used to enable all interrupts of a FlexIO channel.
* @details This function is called when starting an asynchronous transfer that uses interrupts as the asynchronous method.
*
* @param[in]   u8FlexIOChannel   FLEXIO channel to be addressed.
*
* @return      void
*
*/
static FUNC (void, I2C_CODE) I2c_FlexIO_EnableInterrupts(CONST(uint8, AUTOMATIC) u8FlexIOChannel)
{
#if (STD_ON == I2C_DMA_USED)
    VAR(uint8, AUTOMATIC) u8HwChannel = u8FlexIOChannel + I2C_FLEXIO_FIRST_CHANNEL_U8;
#endif

#if (STD_ON == I2C_DMA_USED)
    if (I2C_DMA_MODE == (*I2c_pConfig->I2c_pHwConfig)[I2c_as8ChannelHardwareMap[u8HwChannel]].eAsyncMethod)
    {
        Mcl_Flexio_EnableInterrupts(
            ((uint8)0U),
            ((uint8)(1U << I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]) | (uint8)(1U << I2c_FlexIO_au8RxShifterId[u8FlexIOChannel])),
            ((uint8)(1U << I2c_FlexIO_au8SclTimerId[u8FlexIOChannel]))
        );
    }
    else
    {
#endif
        Mcl_Flexio_EnableInterrupts(
            ((uint8)(1U << I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]) | (uint8)(1U << I2c_FlexIO_au8RxShifterId[u8FlexIOChannel])),
            ((uint8)(1U << I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]) | (uint8)(1U << I2c_FlexIO_au8RxShifterId[u8FlexIOChannel])),
            ((uint8)(1U << I2c_FlexIO_au8SclTimerId[u8FlexIOChannel]))
        );
#if (STD_ON == I2C_DMA_USED)
    }
#endif
}

/**
* @brief   Used to disable all interrupts of a FlexIO channel.
* @details This function is called when an asynchronous transfer ends either with error or successfully.
*
* @param[in]   u8FlexIOChannel   FLEXIO channel to be addressed.
*
* @return      void
*
*/
static FUNC (void, I2C_CODE) I2c_FlexIO_DisableInterrupts(CONST(uint8, AUTOMATIC) u8FlexIOChannel)
{
#if (STD_ON == I2C_DMA_USED)
    VAR(uint8, AUTOMATIC) u8HwChannel = u8FlexIOChannel + I2C_FLEXIO_FIRST_CHANNEL_U8;
#endif

#if (STD_ON == I2C_DMA_USED)
    if (I2C_DMA_MODE == (*I2c_pConfig->I2c_pHwConfig)[I2c_as8ChannelHardwareMap[u8HwChannel]].eAsyncMethod)
    {
        Mcl_Flexio_DisableInterrupts(
            ((uint8)0U),
            ((uint8)(1U << I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]) | (uint8)(1U << I2c_FlexIO_au8RxShifterId[u8FlexIOChannel])),
            ((uint8)(1U << I2c_FlexIO_au8SclTimerId[u8FlexIOChannel]))
        );
    }
    else
    {
#endif
        Mcl_Flexio_DisableInterrupts(
            ((uint8)(1U << I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]) | (uint8)(1U << I2c_FlexIO_au8RxShifterId[u8FlexIOChannel])),
            ((uint8)(1U << I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]) | (uint8)(1U << I2c_FlexIO_au8RxShifterId[u8FlexIOChannel])),
            ((uint8)(1U << I2c_FlexIO_au8SclTimerId[u8FlexIOChannel]))
        );
#if (STD_ON == I2C_DMA_USED)
    }
#endif
}

/**
* @brief   Error handler for FlexIO.
* @details This function shall manage all the errors of a FlexIO channel
*
* @param[in]   u8HwChannel     FlexIO channel to be addressed.
* @param[in]   u8ErrorStatus   Error flags of the FlexIO Channel
*
* @return       void.
*
*/
static FUNC (void, I2C_CODE) I2c_FlexIO_AsyncErrorHandler(VAR(uint8, AUTOMATIC) u8HwChannel, VAR(uint8, AUTOMATIC) u8ErrorStatus)
{
    VAR(uint8, AUTOMATIC) u8FlexIOChannel  = u8HwChannel - I2C_FLEXIO_FIRST_CHANNEL_U8;
#ifdef I2C_ERROR_NOTIFICATION
    VAR(sint8, AUTOMATIC) s8LogicalChannel = I2c_as8ChannelHardwareMap[u8HwChannel];
#endif

    /* Check for errors of the shifters and signal the application that an error occurred */
    if (0x0U != u8ErrorStatus)
    {
        I2c_FlexIO_au8ErrorsFound[u8FlexIOChannel] = 0x1U;
        
        /* Check for TX Shifter errors */
#ifdef I2C_ERROR_NOTIFICATION
        if ((uint8)FLEXIO_SHIFTERR_SEF_U32(I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]) == (u8ErrorStatus & (uint8)FLEXIO_SHIFTERR_SEF_U32(I2c_FlexIO_au8TxShifterId[u8FlexIOChannel])))
        {
            I2C_ERROR_NOTIFICATION((uint8)s8LogicalChannel, I2C_E_TX_UNDERFLOW);
        }
        
        /* Check for RX shifter errors */
        if ((uint8)FLEXIO_SHIFTERR_SEF_U32(I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]) == (u8ErrorStatus & (uint8)FLEXIO_SHIFTERR_SEF_U32(I2c_FlexIO_au8RxShifterId[u8FlexIOChannel])))
        {
            I2C_ERROR_NOTIFICATION((uint8)s8LogicalChannel, I2C_E_RX_OVERFLOW);
        }
#endif
    }
}

/**
* @brief   Error handler for synchronous communication.
* @details This function shall manage all the errors of a FlexIO channel
*
* @param[in]   u8FlexIOChannel     FlexIO channel to be addressed.
*
* @return      Std_ReturnType.
*
*/
static FUNC (Std_ReturnType, I2C_CODE) I2c_FlexIO_SyncErrorHandler(VAR(uint8, AUTOMATIC) u8FlexIOChannel)
{
    VAR(uint32, AUTOMATIC) u32ErrorStatus  = 0x0U;
    VAR(Std_ReturnType, AUTOMATIC) eReturnCode = (Std_ReturnType)E_NOT_OK;
#ifdef I2C_ERROR_NOTIFICATION
    VAR(uint8, AUTOMATIC) u8HwChannel  = u8FlexIOChannel + I2C_FLEXIO_FIRST_CHANNEL_U8;
    VAR( sint8, AUTOMATIC) s8LogicalChannel     = -1;

    s8LogicalChannel = I2c_as8ChannelHardwareMap[u8HwChannel];
#endif
    /** @violates @ref I2C_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    u32ErrorStatus = (uint32)Mcl_Flexio_ReadShiftErr((uint8)(1U << I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]) | (uint8)(1U << I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]));

    /* Clear shifter error flags */
    /** @violates @ref I2C_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    Mcl_Flexio_ClearShiftErr((uint8)u32ErrorStatus);

    if(0U != u32ErrorStatus)
    {
        /* Check for TX Shifter errors */
#ifdef I2C_ERROR_NOTIFICATION
        if (FLEXIO_SHIFTERR_SEF_U32(I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]) == (u32ErrorStatus  & FLEXIO_SHIFTERR_SEF_U32(I2c_FlexIO_au8TxShifterId[u8FlexIOChannel])))
        {
            I2C_ERROR_NOTIFICATION((uint8)s8LogicalChannel, I2C_E_TX_UNDERFLOW);
        }
        
        /* Check for RX shifter errors */
        if (FLEXIO_SHIFTERR_SEF_U32(I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]) == (u32ErrorStatus  & FLEXIO_SHIFTERR_SEF_U32(I2c_FlexIO_au8RxShifterId[u8FlexIOChannel])))
        {
            I2C_ERROR_NOTIFICATION((uint8)s8LogicalChannel, I2C_E_RX_OVERFLOW);
        }
#endif
        eReturnCode = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        eReturnCode = (Std_ReturnType)E_OK;
    }

    return eReturnCode;
}

/**
* @brief   Used to process the FlexIO RX shifter.
* @details This function is called when sending or receiving to read out the data from the RX shifter
*          when data is present and also to configure the shifters when receiving data from a slave to detect
*          and send ACK/NACK.
*
* @param[in]   u8HwChannel     FLEXIO channel to be addressed.
*
* @return      void
*
*/
static FUNC (void, I2C_CODE) I2c_FlexIO_ProcessRxShifter(CONST(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8FlexIOChannel   = u8HwChannel - I2C_FLEXIO_FIRST_CHANNEL_U8;
    VAR( sint8, AUTOMATIC) s8LogicalChannel = I2c_as8ChannelHardwareMap[u8HwChannel];
    /* Received data. */
    VAR( uint32, AUTOMATIC) u32ReceiveData = 0x0U;

    /* Read the data from SHIFTBUFBIS regardless of its significance to avoid an RX overflow error */
    /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    u32ReceiveData = (uint8)REG_READ32(FLEXIO_SHIFTBUFBISn_ADDR32((uint32)I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]));

    /* If the master is receiving data from the slave the data must be saved and the shifters must be configured
       to detect and send ACK/NACK according to the I2C protocol */
    if ( I2C_CH_RECEIVE == I2c_aeChannelStatus[s8LogicalChannel] )
    {
        /* If this is the first received byte after the address was sent it must be discarded */
        if (0x0U == I2c_FlexIO_au8AddrReceived[u8FlexIOChannel])
        {
            I2c_FlexIO_au8AddrReceived[u8FlexIOChannel] = 0x1U;
            
            /* Configure TX shifter to send ACK */
            /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_RMW32(FLEXIO_SHIFTCFGn_ADDR32((uint32)I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]), FLEXIO_SHIFTCFG_SSTOP_MASK_U32, FLEXIO_STOP_BIT_VALUE_0_U32);
        }
        /* If this is not the address byte the data must be saved in the buffer */
        else
        {
            /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2c_FlexIO_c_REF_6 MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer */
            I2c_FlexIO_aup8DataBuffer[u8FlexIOChannel][I2c_FlexIO_au8CurrentIndex[u8FlexIOChannel]] = (uint8)(u32ReceiveData & 0xFFU);
            I2c_FlexIO_au8CurrentIndex[u8FlexIOChannel]++;
        }
        /* For the last byte configure the stop bit and ACK/NACK detection for the shifters */
        if (I2c_FlexIO_au8CurrentIndex[u8FlexIOChannel] == (I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel] - 1U))
        {
            /* Send NACK for last byte */
            /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_RMW32(FLEXIO_SHIFTCFGn_ADDR32((uint32)I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]), FLEXIO_SHIFTCFG_SSTOP_MASK_U32, FLEXIO_STOP_BIT_VALUE_1_U32);
            
            /* Configure RX shifter to expect NACK */
            /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_RMW32(FLEXIO_SHIFTCFGn_ADDR32((uint32)I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]), FLEXIO_SHIFTCFG_SSTOP_MASK_U32, FLEXIO_STOP_BIT_VALUE_1_U32);
        }
    }
}

/**
* @brief   Used to process the FlexIO TX shifter.
* @details This function is called when sending data to the slave to feed the TX shifter buffer with needed data,
*          when receiving data to free the SDA line, and in both cases to send the stop condition at the end of a transfer.
*
* @param[in]   u8HwChannel     FLEXIO channel to be addressed.
*
* @return      void
*
*/
static FUNC (void, I2C_CODE) I2c_FlexIO_ProcessTxShifter(CONST(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8FlexIOChannel   = u8HwChannel - I2C_FLEXIO_FIRST_CHANNEL_U8;
    VAR( sint8, AUTOMATIC) s8LogicalChannel = I2c_as8ChannelHardwareMap[u8HwChannel];
    
    if ( I2C_CH_SEND == I2c_aeChannelStatus[s8LogicalChannel] )
    {
        /* If the previous byte sent was the last one (and not the stop byte) */
        if (I2c_FlexIO_au8CurrentIndex[u8FlexIOChannel] == I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel])
        {
            if ((boolean)FALSE == I2c_FlexIO_abRepeatedStart[u8FlexIOChannel])
            {
                /* Send the stop byte without calling the SendDataByte function */
                /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
                /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE32(FLEXIO_SHIFTBUFBBSn_ADDR32((uint32)I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]), FLEXIO_STOP_BYTE_VALUE_U32);
            }
            else
            {
                /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
                /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE32(FLEXIO_SHIFTBUFBBSn_ADDR32((uint32)I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]), FLEXIO_LEAVE_SDA_FREE_U32);
            }
            /* Increment the index to send the stop byte only once */
            I2c_FlexIO_au8CurrentIndex[u8FlexIOChannel]++;
        }
        /* If there are any more bytes to be sent to the slave feed the TX Shifter buffer */
        if (I2c_FlexIO_au8CurrentIndex[u8FlexIOChannel] < I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel])
        {
            /* Send next data byte */
            /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2c_FlexIO_c_REF_6 MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer */
            /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE32(FLEXIO_SHIFTBUFBBSn_ADDR32((uint32)I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]), (uint32)(I2c_FlexIO_aup8DataBuffer[u8FlexIOChannel][I2c_FlexIO_au8CurrentIndex[u8FlexIOChannel]]));
            I2c_FlexIO_au8CurrentIndex[u8FlexIOChannel]++;
        }
    }
    
    /* If the master is receiving bytes from the slave */
    if ( I2C_CH_RECEIVE == I2c_aeChannelStatus[s8LogicalChannel] )
    {
        /* If the last byte was received send the stop command and send it only once */
        if (I2c_FlexIO_au8TxShifterBytes[u8FlexIOChannel] == I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel])
        {
            if ((boolean)FALSE == I2c_FlexIO_abRepeatedStart[u8FlexIOChannel])
            {
                /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
                /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE32(FLEXIO_SHIFTBUFBBSn_ADDR32((uint32)I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]), FLEXIO_STOP_BYTE_VALUE_U32);
            }
            else
            {
                /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
                /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE32(FLEXIO_SHIFTBUFBBSn_ADDR32((uint32)I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]), FLEXIO_LEAVE_SDA_FREE_U32); 
            }

            /* Increment the index to send the stop byte only once */
            I2c_FlexIO_au8TxShifterBytes[u8FlexIOChannel]++;
        }
        /* If there are some more bytes to be received send 0xFF to leave the SDA line free */
        if (I2c_FlexIO_au8TxShifterBytes[u8FlexIOChannel] < I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel])
        {
            /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE32(FLEXIO_SHIFTBUFBBSn_ADDR32((uint32)I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]), FLEXIO_LEAVE_SDA_FREE_U32);
            /* Increment the index to detect the moment when stop is needed */
            I2c_FlexIO_au8TxShifterBytes[u8FlexIOChannel]++;
        }
    }
}

/**
* @brief   Sends the address of the slave.
* @details Generate (repeated) START and send the address of the slave to initiate a transmission.
*
* @param[in]   u8HwChannel I2C channel to be addressed.
* @param[in]   pRequestPtr Pointer to the structure that contains the information necessary to begin the
*                          transmission: the address of the slave, high speed mode, expect NACK, number of bytes
*                          and the data buffer
*
* @return            void
*
*/
static FUNC (void, I2C_CODE) I2c_FlexIO_SendAddress(CONST(uint8, AUTOMATIC) u8HwChannel, P2CONST(I2c_RequestType, AUTOMATIC, I2C_APPL_CONST) pRequestPtr)
{
    VAR(uint8, AUTOMATIC) u8FlexIOChannel        = u8HwChannel - I2C_FLEXIO_FIRST_CHANNEL_U8;
    VAR(uint32, AUTOMATIC) u32TimerCompareValue  = 0x0U;
    VAR(I2c_AddressType, AUTOMATIC) u16SlaveAddress;

    /* What condition to generate at the end of a transfer */
    I2c_FlexIO_abRepeatedStart[u8FlexIOChannel] = pRequestPtr->bRepeatedStart;

    /* Initialize the current index to 0 */
    I2c_FlexIO_au8CurrentIndex[u8FlexIOChannel] = 0x00U;
    /* Initialize the number of bytes to send */
    I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel] = pRequestPtr->u8BufferSize;
    
    I2c_FlexIO_aup8DataBuffer[u8FlexIOChannel] = pRequestPtr->pDataBuffer;
    
    /* Compute number of SCL ticks including address and set them in the CMP register of the timer */
    /* ((The number of bytes + 1 byte for the address) * the number of edges (2 for each bit)) + 1 (the stop bit) */
    u32TimerCompareValue = ((uint32)((uint32)((((uint32)pRequestPtr->u8BufferSize + 1U) * 18U) + 1U) & 0xFFU) << 8U);
    
    /* Write the number of ticks calculated before keeping the baud bits unchanged */
    /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(FLEXIO_TIMCMPn_ADDR32((uint32)I2c_FlexIO_au8SclTimerId[u8FlexIOChannel]), FLEXIO_TIMCMP_BITS_NUMBER_MASK_U32, u32TimerCompareValue);
    
    /* Send slave address */
    if (I2C_SEND_DATA == pRequestPtr->eDataDirection)
    {
        /* Write the Read/Write bit with 0 to indicate a write operation is needed */
        u16SlaveAddress = pRequestPtr->SlaveAddress & (uint16)(~(uint16)FLEXIO_READ_BIT_U8);
    }
    else
    {
        /* Write the Read/Write bit with 1 to indicate a read operation is needed */
        u16SlaveAddress = pRequestPtr->SlaveAddress | (uint16)(FLEXIO_READ_BIT_U8);
    }
    
    if ((boolean)TRUE == (boolean)(pRequestPtr->b10BitsSlaveAddressSize))
    {
        /* TBD */
    }
    else
    {
        /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(FLEXIO_SHIFTBUFBBSn_ADDR32((uint32)I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]), (uint32)(u16SlaveAddress));
    }
}

/**
* @brief   Sends and Receives data synchronously.
* @details Sends and Receives data blocking.
*
* @param[in]   u8HwChannel   I2C channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*/
static FUNC (Std_ReturnType, I2C_CODE) I2c_FlexIO_SyncTransfer(CONST(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATIC) u8FlexIOChannel      = u8HwChannel - I2C_FLEXIO_FIRST_CHANNEL_U8;
    VAR( sint8, AUTOMATIC) s8LogicalChannel    = -1;
    VAR( uint8, AUTOMATIC) u8ShifterStatus     = 0x0U;
    VAR( uint8, AUTOMATIC) u8TimerStatus       = 0x0U;
    /* Time out value for specific wait operations. */
    VAR( uint32, AUTOMATIC) u32Timeout         = I2C_TIMEOUT_LOOPS; 

    s8LogicalChannel = I2c_as8ChannelHardwareMap[u8HwChannel];

    
    /* While the SCL timer flag is not set process the shifters */
    u32Timeout = I2C_TIMEOUT_LOOPS;
    do
    {
        /* Process shifter events */
        /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
        u8ShifterStatus = Mcl_Flexio_ReadShiftStat((uint8)FLEXIO_SHIFTSTAT_SSF_MASK_U32);
    
        /* If the RX shifter flag is set process the RX shifter event */
        if ( (uint8)FLEXIO_SHIFTSTAT_SSF_U32(I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]) == (u8ShifterStatus & (uint8)FLEXIO_SHIFTSTAT_SSF_U32(I2c_FlexIO_au8RxShifterId[u8FlexIOChannel])))
        {
            I2c_FlexIO_ProcessRxShifter(u8HwChannel);
        }
    
        /* If the TX shifter flag is set process the TX shifter event */
        if ((uint8)FLEXIO_SHIFTSTAT_SSF_U32(I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]) == (u8ShifterStatus & (uint8)FLEXIO_SHIFTSTAT_SSF_U32(I2c_FlexIO_au8TxShifterId[u8FlexIOChannel])))
        {
            I2c_FlexIO_ProcessTxShifter(u8HwChannel);
        }
        /* Check if the timer expired (the transmission is over) */
        /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
        u8TimerStatus = Mcl_Flexio_ReadTimStat((uint8)(1U << I2c_FlexIO_au8SclTimerId[u8FlexIOChannel]) | (uint8)(1U << (I2c_FlexIO_au8SclTimerId[u8FlexIOChannel] + 1U)));
        u32Timeout--;
    }while (
                (u32Timeout > (uint32)0x0U) &&
                (
                    (uint8)FLEXIO_TIMSTAT_TSF_U32(I2c_FlexIO_au8SclTimerId[u8FlexIOChannel]) != 
                    (u8TimerStatus & (uint8)FLEXIO_TIMSTAT_TSF_U32(I2c_FlexIO_au8SclTimerId[u8FlexIOChannel]))
                )
           );

    /* Clear the timer flag */
    Mcl_Flexio_ClearTimStat(u8TimerStatus);
    
    /* Restore the configuration of the STOP bit for the RX Shifter in case a receive operation changed it */
    /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(FLEXIO_SHIFTCFGn_ADDR32((uint32)I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]), FLEXIO_SHIFTCFG_SSTOP_MASK_U32, FLEXIO_STOP_BIT_VALUE_0_U32);
    
    /* If the timer did not trigger an event report a time out error */
    if ( (uint32)0x0U == u32Timeout)
    {
        /* Change the state of the channel to indicate that an error is present */
        I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_ERROR_PRESENT;
#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if ((uint32)STD_ON == I2c_pDemCfg->I2c_E_TimeoutFailureCfg.state)
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)I2c_pDemCfg->I2c_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
        }
#endif
    }
    else
    {
        if ( (Std_ReturnType)E_NOT_OK == I2c_FlexIO_SyncErrorHandler(u8FlexIOChannel) )
        {
            I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_ERROR_PRESENT;
        }
        else
        {
            if ( I2c_FlexIO_au8CurrentIndex[u8FlexIOChannel] >= I2c_FlexIO_au8NumberOfBytes[u8FlexIOChannel])
            {
                u8TmpReturn = (Std_ReturnType)E_OK;
                I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_FINISHED;
                
            }
        }
    }
    
    return u8TmpReturn;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (STD_ON == I2C_DMA_USED)

/**
* @brief   Used to process data when sending/receiving data using a DMA channel.
* @details This function is called from the DMA transfer processing function of the TX Shifter of FLEXIO_0_CH_0_1.
*
* @param[in]    void
*
* @return       void
*
*/
/**
* @violates @ref I2c_FlexIO_c_REF_5 The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
/** @violates @ref I2c_FlexIO_c_REF_4 All declarations and definitions of objects or functions at file scope shall have internal Linkage unless external Linkage is required. */
FUNC (void, I2C_CODE) I2c_FlexIO0_DmaTransferCompleteNotificationShifter0(VAR( void, AUTOMATIC))
{
    I2c_FlexIO_DmaTxShifterProcessing(FLEXIO_0_CH_0_1);
}

/**
* @brief   Used to process data when sending/receiving data using a DMA channel.
* @details This function is called from the DMA transfer processing function of the RX Shifter of FLEXIO_0_CH_0_1.
*
* @param[in]    void
*
* @return       void
*
*/
/**
* @violates @ref I2c_FlexIO_c_REF_5 The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
/** @violates @ref I2c_FlexIO_c_REF_4 All declarations and definitions of objects or functions at file scope shall have internal Linkage unless external Linkage is required. */
FUNC (void, I2C_CODE) I2c_FlexIO0_DmaTransferCompleteNotificationShifter1(VAR( void, AUTOMATIC))
{
    I2c_FlexIO_DmaRxShifterProcessing(FLEXIO_0_CH_0_1);
}

/**
* @brief   Used to process data when sending/receiving data using a DMA channel.
* @details This function is called from the DMA transfer processing function of the TX Shifter of FLEXIO_0_CH_2_3.
*
* @param[in]    void
*
* @return       void
*
*/
/**
* @violates @ref I2c_FlexIO_c_REF_5 The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
/** @violates @ref I2c_FlexIO_c_REF_4 All declarations and definitions of objects or functions at file scope shall have internal Linkage unless external Linkage is required. */
FUNC (void, I2C_CODE) I2c_FlexIO0_DmaTransferCompleteNotificationShifter2(VAR( void, AUTOMATIC))
{
    I2c_FlexIO_DmaTxShifterProcessing(FLEXIO_0_CH_2_3);
}

/**
* @brief   Used to process data when sending/receiving data using a DMA channel.
* @details This function is called from the DMA transfer processing function of the RX Shifter of FLEXIO_0_CH_2_3.
*
* @param[in]    void
*
* @return       void
*
*/
/**
* @violates @ref I2c_FlexIO_c_REF_5 The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
/** @violates @ref I2c_FlexIO_c_REF_4 All declarations and definitions of objects or functions at file scope shall have internal Linkage unless external Linkage is required. */
FUNC (void, I2C_CODE) I2c_FlexIO0_DmaTransferCompleteNotificationShifter3(VAR( void, AUTOMATIC))
{
    I2c_FlexIO_DmaRxShifterProcessing(FLEXIO_0_CH_2_3);
}

#endif

/**
* @brief   Initialize a I2C channel.
* @details This function initializes all hardware registers needed to
*          start the I2C functionality on the selected channel.
*
* @param[in] u8HwChannel  I2C channel to be initialized.
*            pConfigPtr Configuration pointer containing hardware specific settings.
*
* @return            void.
*
*/
FUNC (void, I2C_CODE) I2c_FlexIO_InitChannel(CONST(uint8, AUTOMATIC) u8HwChannel, P2CONST(I2c_FlexIO_HwChannelConfigType, AUTOMATIC, I2C_APPL_CONST) pConfigPtr)
{
    VAR(uint8, AUTOMATIC) u8FlexIOChannel = u8HwChannel - I2C_FLEXIO_FIRST_CHANNEL_U8;

    /* Config the timers */
    /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32)((pConfigPtr->u32SclTimerConfig).u32TimerId)), (pConfigPtr->u32SclTimerConfig).u32TimerConfig);
    /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32)((pConfigPtr->u32SclTimerConfig).u32TimerId)), (pConfigPtr->u32SclTimerConfig).u32TimerControl);
    /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)((pConfigPtr->u32SclTimerConfig).u32TimerId)), (pConfigPtr->u32SclTimerConfig).u32TimerCompare);
    /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32)((pConfigPtr->u32ShifterControlTimerConfig).u32TimerId)), (pConfigPtr->u32ShifterControlTimerConfig).u32TimerConfig);
    /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32)((pConfigPtr->u32ShifterControlTimerConfig).u32TimerId)), (pConfigPtr->u32ShifterControlTimerConfig).u32TimerControl);
    /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)((pConfigPtr->u32ShifterControlTimerConfig).u32TimerId)), (pConfigPtr->u32ShifterControlTimerConfig).u32TimerCompare);

    I2c_FlexIO_au8SclTimerId[u8FlexIOChannel] = (uint8)((pConfigPtr->u32SclTimerConfig).u32TimerId & 0xFFU);

    /* Config the shifters */
    /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLEXIO_SHIFTCFGn_ADDR32((uint32)((pConfigPtr->u32TxShifterConfig).u32ShifterId)), (pConfigPtr->u32TxShifterConfig).u32ShifterConfig);
    /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLEXIO_SHIFTCTLn_ADDR32((uint32)((pConfigPtr->u32TxShifterConfig).u32ShifterId)), (pConfigPtr->u32TxShifterConfig).u32ShifterControl);
    /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLEXIO_SHIFTCFGn_ADDR32((uint32)((pConfigPtr->u32RxShifterConfig).u32ShifterId)), (pConfigPtr->u32RxShifterConfig).u32ShifterConfig);
    /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLEXIO_SHIFTCTLn_ADDR32((uint32)((pConfigPtr->u32RxShifterConfig).u32ShifterId)), (pConfigPtr->u32RxShifterConfig).u32ShifterControl);

    I2c_FlexIO_au8TxShifterId[u8FlexIOChannel] = (uint8)((pConfigPtr->u32TxShifterConfig).u32ShifterId & 0xFFU);
    I2c_FlexIO_au8RxShifterId[u8FlexIOChannel] = (uint8)((pConfigPtr->u32RxShifterConfig).u32ShifterId & 0xFFU);

#if (STD_ON == I2C_DMA_USED)
    I2c_FlexIO_au8TxDmaChannel[u8FlexIOChannel] = pConfigPtr->u8TxDmaChannel;
    I2c_FlexIO_au8RxDmaChannel[u8FlexIOChannel] = pConfigPtr->u8RxDmaChannel;

    /* Set the source for the DMA channel as the address of the SHIFTBUFBIS register of the RX Shifter */
    /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
    I2c_FlexIO_aRxDmaCfgDesc[u8FlexIOChannel].u32saddr = FLEXIO_SHIFTBUFBISn_ADDR32((uint32)I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]);
    /* Set the number of bytes 4, because the DMA will check for the TX shifter flag only after one iteration of 32 bits is finished */
    I2c_FlexIO_aRxDmaCfgDesc[u8FlexIOChannel].u32num_bytes = 1U;
    /* The offset for the source buffer is 0, because we want to read the data from the SHIFTBUFBIS register */
    I2c_FlexIO_aRxDmaCfgDesc[u8FlexIOChannel].u32soff  = 0U;
    I2c_FlexIO_aRxDmaCfgDesc[u8FlexIOChannel].u32dsize = (uint8)DMA_SIZE_1BYTE; 
    I2c_FlexIO_aRxDmaCfgDesc[u8FlexIOChannel].u32ssize = (uint8)DMA_SIZE_1BYTE;
    
    /* Set the destination for the DMA channel the SHIFTBUFBIS register of the TX Shifter */
    I2c_FlexIO_aTxDmaCfgDesc[u8FlexIOChannel].u32daddr = FLEXIO_SHIFTBUFBBSn_ADDR32((uint32)I2c_FlexIO_au8TxShifterId[u8FlexIOChannel]);
    /* Set the number of bytes 4, because the DMA will check for the TX shifter flag only after one iteration of 32 bits is finished */
    I2c_FlexIO_aTxDmaCfgDesc[u8FlexIOChannel].u32num_bytes = 1U;
    /* The offset for the destination buffer is 0, because we want all the bytes to be written to SHIFTBUFBIS */
    I2c_FlexIO_aTxDmaCfgDesc[u8FlexIOChannel].u32doff  = 0U;
    I2c_FlexIO_aTxDmaCfgDesc[u8FlexIOChannel].u32dsize = (uint8)DMA_SIZE_1BYTE; 
    I2c_FlexIO_aTxDmaCfgDesc[u8FlexIOChannel].u32ssize = (uint8)DMA_SIZE_1BYTE;
#endif

    /* Clear the corresponding SERR and TIM flags */
    Mcl_Flexio_ClearShiftErr((uint8)(1U << ((pConfigPtr->u32TxShifterConfig).u32ShifterId & 0xFFU)) | (uint8)(1U << ((pConfigPtr->u32RxShifterConfig).u32ShifterId & 0xFFU)));
    Mcl_Flexio_ClearTimStat((uint8)(1U << ((pConfigPtr->u32SclTimerConfig).u32TimerId & 0xFFU)) | (uint8)(1U << ((pConfigPtr->u32ShifterControlTimerConfig).u32TimerId & 0xFFU))); 
}

/**
* @brief   Sends or receives an I2C message to/from the slave.
* @details Send the address of the slave and then send or receive blocking all data bytes.
*
* @param[in]   u8HwChannel   I2C channel to be addressed.
* @param[in]   pRequestPtr Pointer to the structure that contains the information necessary to begin the
*                          transmission: the address of the slave, high speed mode, expect NACK, number of bytes
*                          and the data buffer
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*
*/
FUNC(Std_ReturnType, I2C_CODE)  I2c_FlexIO_SyncTransmit(VAR(uint8, AUTOMATIC) u8HwChannel, P2CONST(I2c_RequestType, AUTOMATIC, I2C_APPL_CONST) pRequest)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn  = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATIC) u8FlexIOChannel       = u8HwChannel - I2C_FLEXIO_FIRST_CHANNEL_U8;
    VAR(uint8, AUTOMATIC) u8ShifterStatus       = 0x0U;

    if (I2C_SEND_DATA != pRequest->eDataDirection)
    {
        I2c_FlexIO_au8AddrReceived[u8FlexIOChannel]   = 0x0U;
        I2c_FlexIO_au8TxShifterBytes[u8FlexIOChannel] = 0x0U;
    }

    /* Discard any unhandled byte if present */
    u8ShifterStatus = Mcl_Flexio_ReadShiftStat((uint8)FLEXIO_SHIFTSTAT_SSF_MASK_U32);
    if (
            (uint8)FLEXIO_SHIFTSTAT_SSF_U32(I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]) == 
            (u8ShifterStatus & (uint8)FLEXIO_SHIFTSTAT_SSF_U32(I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]))
       )
    {
        /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
        (void)REG_READ32(FLEXIO_SHIFTBUFBISn_ADDR32((uint32)I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]));
    }

    /* If I2c_SyncTransmit was called send the data blocking */
    /* Send the slave address */
    I2c_FlexIO_SendAddress(u8HwChannel, pRequest);
    /* Send the data bytes synchronously */
    u8TmpReturn = I2c_FlexIO_SyncTransfer(u8HwChannel);

    return u8TmpReturn;
}


/**
* @brief   Starts sending an I2C message from the slave.
* @details Send the address of the slave to initiate a transmission and prepare the transfer.
*
* @param[in]   u8HwChannel   I2C channel to be addressed.
* @param[in]   pRequestPtr Pointer to the structure that contains the information necessary to begin the
*                          transmission: the address of the slave, high speed mode, expect NACK, number of bytes
*                          and the data buffer
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*
*/
FUNC(Std_ReturnType, I2C_CODE)  I2c_FlexIO_AsyncTransmit(VAR(uint8, AUTOMATIC) u8HwChannel, P2CONST(I2c_RequestType, AUTOMATIC, I2C_APPL_CONST) pRequest)
{   
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATIC) u8FlexIOChannel      = u8HwChannel - I2C_FLEXIO_FIRST_CHANNEL_U8;
    VAR( uint8, AUTOMATIC) u8ShifterStatus     = 0x0U;

    if (I2C_SEND_DATA != pRequest->eDataDirection)
    {
        I2c_FlexIO_au8AddrReceived[u8FlexIOChannel]   = 0x0U;
        I2c_FlexIO_au8TxShifterBytes[u8FlexIOChannel] = 0x0U;
    }

    /* Discard any unhandled byte if present */
    u8ShifterStatus = Mcl_Flexio_ReadShiftStat((uint8)FLEXIO_SHIFTSTAT_SSF_MASK_U32);
    if ((uint8)FLEXIO_SHIFTSTAT_SSF_U32(I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]) == 
                (u8ShifterStatus & (uint8)FLEXIO_SHIFTSTAT_SSF_U32(I2c_FlexIO_au8RxShifterId[u8FlexIOChannel])))
    {
        /** @violates @ref I2c_FlexIO_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2c_FlexIO_c_REF_7 The cast is used to access memory mapped registers.*/
        (void)REG_READ32(FLEXIO_SHIFTBUFBISn_ADDR32((uint32)I2c_FlexIO_au8RxShifterId[u8FlexIOChannel]));
    }

#if (STD_ON == I2C_DMA_USED)
    if (I2C_DMA_MODE == (*I2c_pConfig->I2c_pHwConfig)[I2c_as8ChannelHardwareMap[u8HwChannel]].eAsyncMethod)
    {
        if (I2C_SEND_DATA == pRequest->eDataDirection)
        {
            u8TmpReturn = I2c_FlexIO_DmaSend(u8HwChannel, pRequest);
        }
        else
        {
            u8TmpReturn = I2c_FlexIO_DmaReceive(u8HwChannel, pRequest);
        }
    }
    else
    {
#endif
        SuspendAllInterrupts();
        /* Send the slave address */
        I2c_FlexIO_SendAddress(u8HwChannel, pRequest);
        /* Enable the interrupts */
        I2c_FlexIO_EnableInterrupts(u8FlexIOChannel);
        ResumeAllInterrupts();

        u8TmpReturn = (Std_ReturnType)E_OK;
#if (STD_ON == I2C_DMA_USED)
    }
#endif

    return u8TmpReturn;
}


/**
* @brief   Interrupt handler for FlexIO.
* @details This function shall manage all the interrupts of a FlexIO module
*
* @param[in]    u8FlexIOModule FlexIO module to be addressed.
*
* @return       void.
*
*
* @note         Internal driver function.
*/
/** @violates @ref I2c_FlexIO_c_REF_4 All declarations and definitions of objects or functions at file scope shall have internal Linkage unless external Linkage is required. */
FUNC (void, I2C_CODE) I2c_FlexIO_InterruptHandler(CONST(uint8, AUTOMATIC) u8FlexIOChannel,   \
                                                  VAR(uint8, AUTOMATIC) u8ShifterStatus,     \
                                                  VAR(uint8, AUTOMATIC) u8ErrStatus,         \
                                                  VAR(uint8, AUTOMATIC) u8TimerStatus        \
                                                 )
{
    VAR(uint8, AUTOMATIC) u8HwChannel;

    /* Check if the driver is initialized */
    if (NULL_PTR != I2c_pConfig)
    {
        u8HwChannel = u8FlexIOChannel + I2C_FLEXIO_FIRST_CHANNEL_U8;

        /* Check if shifters need processing */
        if(0U != u8ShifterStatus)
        {
            I2c_FlexIO_AsyncProcessShifters(u8HwChannel, u8ShifterStatus);
        }
        /* Check for errors */
        if(0U != u8ErrStatus)
        {
            I2c_FlexIO_AsyncErrorHandler(u8HwChannel, u8ErrStatus);
        }
        /* Check the hardware channel that triggered a timer event */
        if(0U != u8TimerStatus)
        {
            I2c_FlexIO_AsyncProcessTimers(u8HwChannel, u8TimerStatus);
        }
    }
}
/**
* @brief   Gets the status of a FlexIO channel.
* @details The function will check for error flags and return the status of a channel.
*
* @param[in]   u8HwChannel I2C channel to be addressed.
*
* @return   I2c_StatusType.
* @retval I2C_CH_IDLE           In case the channel was just initialized and not request is pending.
* @retval I2C_CH_SEND           In case the channel is busy sending data.
* @retval I2C_CH_RECEIVE        In case the channel is busy receiving data.
* @retval I2C_CH_FINISHED       In case a transmission or reception of bytes has finished.
* @retval I2C_CH_ERROR_PRESENT  In case an error is present.
*
*/
FUNC (I2c_StatusType, I2C_CODE) I2c_FlexIO_GetStatus(CONST(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(I2c_StatusType, AUTOMATIC) eChannelStatus = I2C_CH_IDLE;
    
    eChannelStatus = I2c_aeChannelStatus[I2c_as8ChannelHardwareMap[u8HwChannel]];
    
    return eChannelStatus;
}


#define I2C_STOP_SEC_CODE
/**
* @violates @ref I2c_FlexIO_c_REF_1 #include statements in a file should only be preceded by other preprocessor directives or comments.
* @violates @ref I2c_FlexIO_c_REF_2 Precautions shall be taken in order to prevent the contents of a header file being included twice.
*/
#include "I2c_MemMap.h"

#endif
#ifdef __cplusplus
}
#endif
/** @} */
