/**
*   @file    Lin_FlexIO.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - FLEXIO.
*   @details File containing the low level driver of the FLEXIO IP.
*
*   @addtogroup LIN
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : LPUART,FLEXIO
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
* @section Lin_FlexIO_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_FlexIO_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a
* file should only be preceded by other preprocessor directives or
* comments. AUTOSAR imposes the specification of the sections in which
* certain parts of the driver must be placed.
*
* @section Lin_FlexIO_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, This violation is due to
* the casting pointers to other types used in macros for reading or
* writing data from address location of controller register.
*
* @section Lin_FlexIO_c_REF_4
* Violates MISRA 2004 Required Rule 17.4, This violation is due to
* the structure of the types used. The application should ensure that the
* SDU pointer is pointing to an array.
*
* @section Lin_FlexIO_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, Not required from Autosar
* specification.
*
* @section Lin_FlexIO_c_REF_6
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character significance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Lin_FlexIO_c_REF_7
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function
*
* @section Lin_FlexIO_c_REF_8
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between
* a pointer type and an integral type
*
* @section Lin_FlexIO_c_REF_9
* Violates MISRA 2004 Required Rule 12.4, The right-hand operand of a logical && 
* or || operator shall not contain side effects.
*
* @section Lin_FlexIO_c_REF_10
* Violates MISRA 2004 Required Rule 10.3, The value of a complex expression of integer
* type shall only be cast to a type of the same signedness that is no wider than the
* underlying type of the expression.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Lin.h"
#if (LIN_FLEXIO_USED == STD_ON)
#include "Lin_FlexIO.h"
#include "SchM_Lin.h"
#include "StdRegMacros.h"
#include "Reg_eSys_FlexIO.h"
#include "CDD_Mcl.h"

#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Lin_FlexIO.c
*/
#define LIN_FLEXIO_VENDOR_ID_C                      43
/**
* @violates @ref Lin_FlexIO_c_REF_6 The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_FLEXIO_AR_RELEASE_MAJOR_VERSION_C       4
/**
* @violates @ref Lin_FlexIO_c_REF_6 The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_FLEXIO_AR_RELEASE_MINOR_VERSION_C       3
/**
* @violates @ref Lin_FlexIO_c_REF_6 The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_FLEXIO_AR_RELEASE_REVISION_VERSION_C    1
#define LIN_FLEXIO_SW_MAJOR_VERSION_C               1
#define LIN_FLEXIO_SW_MINOR_VERSION_C               0
#define LIN_FLEXIO_SW_PATCH_VERSION_C               1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin header file are of the same vendor */
#if (LIN_FLEXIO_VENDOR_ID_C != LIN_VENDOR_ID)
    #error "Lin_FlexIO.c and Lin.h have different vendor ids"
#endif
/* Check if current file and Lin_FlexIO header file are of the same vendor */
#if (LIN_FLEXIO_VENDOR_ID_C != LIN_FLEXIO_VENDOR_ID)
    #error "Lin_FlexIO.c and Lin_FlexIO.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_FlexIO header file are of the same vendor */
#if (LIN_FLEXIO_VENDOR_ID_C != REG_ESYS_FLEXIO_VENDOR_ID)
    #error "Lin_FlexIO.c and Reg_eSys_FlexIO.h have different vendor ids"
#endif
/* Check if current file and Lin.h header file are of the same Autosar version */
#if ((LIN_FLEXIO_AR_RELEASE_MAJOR_VERSION_C    != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_FLEXIO_AR_RELEASE_MINOR_VERSION_C    != LIN_AR_RELEASE_MINOR_VERSION) || \
     (LIN_FLEXIO_AR_RELEASE_REVISION_VERSION_C != LIN_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_FlexIO.c and Lin.h are different"
#endif
/* Check if current file and Lin.h header file are of the same Software version */
#if ((LIN_FLEXIO_SW_MAJOR_VERSION_C != LIN_SW_MAJOR_VERSION) || \
     (LIN_FLEXIO_SW_MINOR_VERSION_C != LIN_SW_MINOR_VERSION) || \
     (LIN_FLEXIO_SW_PATCH_VERSION_C != LIN_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_FlexIO.c and Lin.h are different"
#endif

/* Check if current file and Lin_FlexIO.h header file are of the same Autosar version */
#if ((LIN_FLEXIO_AR_RELEASE_MAJOR_VERSION_C    != LIN_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_FLEXIO_AR_RELEASE_MINOR_VERSION_C    != LIN_FLEXIO_AR_RELEASE_MINOR_VERSION) || \
     (LIN_FLEXIO_AR_RELEASE_REVISION_VERSION_C != LIN_FLEXIO_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_FlexIO.c and Lin_FlexIO.h are different"
#endif
/* Check if current file and Lin_FlexIO.h header file are of the same Software version */
#if ((LIN_FLEXIO_SW_MAJOR_VERSION_C != LIN_FLEXIO_SW_MAJOR_VERSION) || \
     (LIN_FLEXIO_SW_MINOR_VERSION_C != LIN_FLEXIO_SW_MINOR_VERSION) || \
     (LIN_FLEXIO_SW_PATCH_VERSION_C != LIN_FLEXIO_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_FlexIO.c and Lin_FlexIO.h are different"
#endif

/* Check if current file and Reg_eSys_FlexIO.h header file are of the same Autosar version */
#if ((LIN_FLEXIO_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_FLEXIO_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_FLEXIO_AR_RELEASE_MINOR_VERSION) || \
     (LIN_FLEXIO_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_FLEXIO_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_FlexIO.c and Reg_eSys_FlexIO.h are different"
#endif
/* Check if current file and Reg_eSys_FlexIO.h header file are of the same Software version */
#if ((LIN_FLEXIO_SW_MAJOR_VERSION_C != REG_ESYS_FLEXIO_SW_MAJOR_VERSION) || \
     (LIN_FLEXIO_SW_MINOR_VERSION_C != REG_ESYS_FLEXIO_SW_MINOR_VERSION) || \
     (LIN_FLEXIO_SW_PATCH_VERSION_C != REG_ESYS_FLEXIO_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_FlexIO.c and Reg_eSys_FlexIO.h are different"
#endif
/* Check if current file and CDD_Mcl.h header file are of the same Autosar version */
#if ((LIN_FLEXIO_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_FLEXIO_AR_RELEASE_MINOR_VERSION_C  != MCL_AR_RELEASE_MINOR_VERSION)  || \
     (LIN_FLEXIO_AR_RELEASE_REVISION_VERSION_C != MCL_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_FlexIO.c and CDD_Mcl.h are different"
#endif
/* Check if current file and CDD_Mcl.h header file are of the same Software version */
#if ((LIN_FLEXIO_SW_MAJOR_VERSION_C != MCL_SW_MAJOR_VERSION) || \
     (LIN_FLEXIO_SW_MINOR_VERSION_C != MCL_SW_MINOR_VERSION) || \
     (LIN_FLEXIO_SW_PATCH_VERSION_C != MCL_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_FlexIO.c and CDD_Mcl.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the source file and StdRegMacros header file are of the same version */
    #if ((LIN_FLEXIO_AR_RELEASE_MAJOR_VERSION_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_FLEXIO_AR_RELEASE_MINOR_VERSION_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lin_FlexIO.c and StdRegMacros.h are different"
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
#define LIN_START_SEC_VAR_NO_INIT_BOOLEAN 
/**
* @violates @ref Lin_FlexIO_c_REF_1 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
* @violates @ref Lin_FlexIO_c_REF_2 Precautions shall be taken in
* order to prevent the contents of a header file being
* included twice.
*/
 #include "Lin_MemMap.h"
 /**
* @brief        Store FlexIO Checksum type
*/
static volatile VAR(boolean, LIN_VAR) bFlexIO_ChecksumType;
#define LIN_STOP_SEC_VAR_NO_INIT_BOOLEAN 
/**
* @violates @ref Lin_FlexIO_c_REF_1 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
* @violates @ref Lin_FlexIO_c_REF_2 Precautions shall be taken in
* order to prevent the contents of a header file being
* included twice.
*/
 #include "Lin_MemMap.h"
 
#define LIN_START_SEC_VAR_NO_INIT_8

/**
* @violates @ref Lin_FlexIO_c_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*
* @violates @ref Lin_FlexIO_c_REF_2 #include statements in a
* file should only be preceded by other preprocessor directives or comments.
*/
 #include "Lin_MemMap.h"
  /**
* @brief        Store FlexIO data to send or receive
*/
static volatile VAR(uint8, LIN_VAR) Lin_FlexIO_au8Buffer[LIN_HW_MAX_MODULES][FLEXIO_MAX_BUFFER_LENGTH_U8];

/**
* @brief        Point to the next byte to send or receive in FlexIO Buffers
*/
static volatile VAR(uint8, LIN_VAR) Lin_FlexIO_au8BufferPtr[LIN_HW_MAX_MODULES];

/**
* @brief        Real sizes of FlexIO Buffers
*/
static volatile VAR(uint8, LIN_VAR) Lin_FlexIO_au8BufferLength[LIN_HW_MAX_MODULES];

static volatile VAR(uint8, LIN_VAR) Lin_FlexIO_au8WakeupFlag[LIN_HW_MAX_MODULES];

static volatile VAR(uint8, LIN_VAR) Lin_FlexIO_au8FrameOnGoing[LIN_HW_MAX_MODULES];

#define LIN_STOP_SEC_VAR_NO_INIT_8

/**
* @violates @ref Lin_FlexIO_c_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*
* @violates @ref Lin_FlexIO_c_REF_2 #include statements in a
* file should only be preceded by other preprocessor directives or comments.
*/
 #include "Lin_MemMap.h"
 /*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_START_SEC_CODE

/**
* @violates @ref Lin_FlexIO_c_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*
* @violates @ref Lin_FlexIO_c_REF_2 #include statements in a
* file should only be preceded by other preprocessor directives or comments.
*/
 #include "Lin_MemMap.h"
 static FUNC (void, LIN_CODE) Lin_FlexIO_CopyData(CONST(uint8, AUTOMATIC) u8Channel, P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) pu8LinSduPtr);
static FUNC (void, LIN_CODE) Lin_FlexIO_PIDCalc(VAR(uint8, AUTOMATIC) u8Channel, VAR(uint8, AUTOMATIC) u8FrameID);
static FUNC (uint32, LIN_CODE) Lin_FlexIO_ChecksumCalc(VAR(uint8, AUTOMATIC) u8Channel, VAR(Lin_FrameCsModelType, AUTOMATIC) checksumModel);
static FUNC (void, LIN_CODE) Lin_FlexIO_TxRxInterruptHandler(VAR(uint8, AUTOMATIC) u8LogicalChannel,VAR(uint8, AUTOMATIC) u8ShifterStatus);
static FUNC (void, LIN_CODE) Lin_FlexIO_WakeupInterruptHandler(VAR(uint8, AUTOMATIC) u8LogicalChannel);
static FUNC (void, LIN_CODE) Lin_FlexIO_ErrorInterruptHandler(VAR(uint8, AUTOMATIC) u8LogicalChannel,VAR(uint8, AUTOMATIC) u8ShifterErrStatus);
static FUNC (void, LIN_CODE) Lin_FlexIO_RxInterruptHandler(VAR(uint8, AUTOMATIC) u8LogicalChannel);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief   Copy the data received from the FLEXIO data registers to pu8LinSduPtr.
* @details This function shall copy the received data in the provided buffer
*          addressed by the pu8LinSduPtr pointer parameter.
*
* @param[in]   FLEXIO Channel to be addressed.
* @param[out]  pu8LinSduPtr pointer to pointer to a shadow buffer or memory
*              mapped FLEXIO Hardware receive buffer where the current SDU is stored
*
* @return      void.
*
*
* @note        Internal driver function.
*
* @violates @ref Lin_FlexIO_c_REF_5 All declarations and definitions
*                of objects or functions at file scope shall have
*                internal linkage unless external linkage is required.
*/
static FUNC (void, LIN_CODE) Lin_FlexIO_CopyData(CONST(uint8, AUTOMATIC) u8Channel, P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) pu8LinSduPtr)
{
    uint8 u8Index;
    uint8 u8BufferLength;

    u8BufferLength = (uint8)(Lin_FlexIO_au8BufferLength[u8Channel] - (uint8)4U);

    for(u8Index = (uint8)0U; u8Index < u8BufferLength; u8Index++)
    {
        /**
        * @violates @ref Lin_FlexIO_c_REF_4 pointer arithmetic other
        *                than array indexing used
        */
        pu8LinSduPtr[u8Index] = Lin_FlexIO_au8Buffer[u8Channel][FLEXIO_DATA_OFFSET_U8 + u8Index];
    }
}

/**
* @brief   Calculate Protected Identifier from the Frame ID.
* @details Calculate Protected Identifier from the Frame ID.
*
* @param[in]   u8Channel, u8FrameID - Frame ID.
* @param[out]  void.
*
* @return      void.
*
*
* @note        Internal driver function.
*
*/
static FUNC (void, LIN_CODE) Lin_FlexIO_PIDCalc(VAR(uint8, AUTOMATIC) u8Channel, VAR(uint8, AUTOMATIC) u8FrameID)
{
    uint32 u32Temp1;
    uint32 u32Temp2;

    u32Temp1 = ((uint32)u8FrameID) & FLEXIO_FRAME_ID_MASK_U32;
    u32Temp2 = u8FrameID;

    /* Calculate parity bit P1 = !(ID1 ^ ID3 ^ ID4 ^ ID5) */
    u32Temp1 |= ((((u32Temp2 >> 1) ^ \
                   (u32Temp2 >> 3) ^ \
                   (u32Temp2 >> 4) ^ \
                   (u32Temp2 >> 5) \
                  )& ((uint32)1U) \
                 ) ^ ((uint32)1U) \
                ) << (uint32)7U;

    /* Calculate parity bit P0 = (ID0 ^ ID1 ^ ID2 ^ ID4) */
    u32Temp1 |= (((u32Temp2) ^ \
                  (u32Temp2 >> 1U) ^ \
                  (u32Temp2 >> 2U) ^ \
                  (u32Temp2 >> 4U) \
                 ) & ((uint32)1U) \
                ) << (uint32)6U;

    Lin_FlexIO_au8Buffer[u8Channel][FLEXIO_PID_BYTE_OFFSET_U8] = (uint8)u32Temp1;
}

/**
* @brief   Calculate LIN Checksum.
* @details Calculate LIN Checksum.
*
* @param[in]   u8Channel, checksumModel.
* @param[out]  u32Checksum.
*
* @return      uint32.
*
* @note        Internal driver function.
*
*/
static FUNC (uint32, LIN_CODE) Lin_FlexIO_ChecksumCalc(VAR(uint8, AUTOMATIC) u8Channel, VAR(Lin_FrameCsModelType, AUTOMATIC) checksumModel)
{
    uint32 u32Checksum = (uint32)0U;
    uint32 u32Carry = (uint32)0U;
    uint32 u32DataLen = (uint32)0U;
    uint32 u32Index = (uint32)0U;

    u32DataLen = ((uint32)Lin_FlexIO_au8BufferLength[u8Channel]) - ((uint32)4U);

    /* Enhanced Model */
    if(LIN_ENHANCED_CS == checksumModel)
    {
        u32Checksum = (uint32)Lin_FlexIO_au8Buffer[u8Channel][FLEXIO_PID_BYTE_OFFSET_U8];
    }

    for(u32Index = (uint32)0U; u32Index < u32DataLen; u32Index++)
    {
        u32Checksum += (uint32)Lin_FlexIO_au8Buffer[u8Channel][FLEXIO_DATA_OFFSET_U8 + u32Index];
        u32Carry = u32Checksum >> (uint32)8U;
        u32Checksum = (u32Checksum & ((uint32)0xFFU)) + u32Carry;
    }

    u32Checksum = (~(u32Checksum)) & ((uint32)0xFFU);
    return u32Checksum;
}

/**
* @brief   Check if a LIN channel has been waked-up.
* @details This function identifies if the addressed LIN channel
*          has been woken up by the LIN bus transceiver. This API
*          is used when the LIN channel wake up functionality is
*          disabled (wake up interrupt is disabled). It checks
*          the wake up flag from the addressed LIN channel which
*          must be in sleep mode and have the wake up
*          functionality disabled.
*
* @param[in] Channel LIN channel to be waked-up.
*
* @return            Std_ReturnType.
* @retval E_OK       If the LIN Channel has the wake
*                    up flag set and the wake up ISR disabled
* @retval E_NOT_OK   Otherwise.
*
*/
FUNC (Std_ReturnType, LIN_CODE) Lin_FlexIO_CheckWakeup(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TempReturn;

    u8TempReturn = Lin_FlexIO_au8WakeupFlag[u8Channel];

    if((uint8)TRUE == u8TempReturn)
    {
        /* Reset Wakeup Flag */
        Lin_FlexIO_au8WakeupFlag[u8Channel] = (uint8)FALSE;
    }
    else
    {
        /* Do nothing */
    }

    return u8TempReturn;
}

/**
* @brief   Initialize a LIN channel.
* @details This function initializes all hardware registers needed to
*          start the LIN functionality on the selected channel.
*
* @param[in]   Channel LIN channel to be initialized.
*
* @return      void.
*
*/
FUNC(void, LIN_CODE) Lin_FlexIO_InitChannel(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint32, AUTOMATIC) u32TxTRGSEL;
    VAR(uint32, AUTOMATIC) u32RxTRGSEL;
    VAR(uint32, AUTOMATIC) u32WriteValue = 0U;
    VAR(uint8, AUTOMATIC) u8TimerStatus = 0x0U;
    VAR(uint32, AUTOMATIC) u32NumOfBits;

    /* Calculate number of bit to wrire to FLEXIO_TIMCMPn register to detect wakeup pluse */
    u32NumOfBits = (uint32)((FLEXIO_MIN_WAKEUP_PULSE_LENGTH_U32/FLEXIO_BIT_LENGTH32(Lin_pcConfigPtr->pLin_Channel[u8Channel]->u32Baudrate)) + (uint8)1U);
    u32NumOfBits = (uint32)((uint32)((uint32)((uint32)u32NumOfBits * 2U) - 1U) << 8U);

    /* Calculate TRGSEL - Trigger Select for Timer control */
    /* Select Shifter for Transmit */
    u32TxTRGSEL = ((uint32)4U*Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId) + (uint32)1U;
    /* Select Pin input for Receive */
    u32RxTRGSEL = ((uint32)4U*((Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxPin - (uint32)1U)/(uint32)2U)) + (uint32)2U;

    /* Check whether wake up detection is enabled */
     if ( (uint8) STD_ON == Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinChannelWakeupSupport)
     {
        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxTimerId);
        /* Check Wakeup event */
        u8TimerStatus = Mcl_Flexio_ReadTimStat((uint8)(1U << u32WriteValue));
        if (0U != u8TimerStatus)
        {
            /* The wake-up shall directly be reported to the EcuM */
            /* via EcuM_SetWakeupEvent call-back function. */
             EcuM_SetWakeupEvent(Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->LinChannelEcuMWakeupSource);
         }
    }

    /* Clear Wakeup Flag */
    Lin_FlexIO_au8WakeupFlag[u8Channel] = (uint8)FALSE;

    /* Configure for Transmit */
    /* Configure start bit of 0 and stop bit of 1 */
    /**
    *
    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
    */
    REG_WRITE32(FLEXIO_SHIFTCFGn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId)), \
                                       (FLEXIO_STOP_BIT_VALUE_1_U32 | FLEXIO_START_BIT_VALUE_0_U32) \
               );

    /* Select timer, pin */
    /**
    *
    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
    */
    REG_WRITE32(FLEXIO_SHIFTCTLn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId)), \
                                       ((uint32)((Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxTimerId) << FLEXIO_SHIFTCTL_TIMSEL_SHIFT_U32) \
                                       |(uint32)((Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxPin) << FLEXIO_SHIFTCTL_PINSEL_SHIFT_U32) \
                                       | FLEXIO_SHIFTER_PIN_OUTPUT_U32 \
                                       | FLEXIO_SHIFTER_TRANSMIT_MODE_U32) \
               );
    /* Configure timer */
    /* Configure N-bit transfer with baud rate of divide by 4 of the FlexIO clock */
    /**
    *
    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
    */
    REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxTimerId)), \
                                     ((uint32)(Lin_pChannelConfigPtr[u8Channel]->u32Lin_BaudRate_RegValue) | u32NumOfBits) \
               );
    /*  Configure start bit, stop bit, enable on trigger asserted and disable on compare. */
    /**
    *
    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
    */
    REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxTimerId)), \
                                     (FLEXIO_TMR_DIS_ON_TMR_COMP_U32 \
                                     | FLEXIO_TMR_EN_ON_TRG_HIGH_U32 \
                                     | FLEXIO_TMR_STOP_BIT_ON_TMR_DIS_U32 \
                                     | FLEXIO_TMR_START_BIT_ENABLED_U32) \
               );

    /* Configure dual 8-bit counter using Shifter 0 status flag as inverted internal trigger source */
    /**
    *
    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
    */
    REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxTimerId)), \
                         ((u32TxTRGSEL << FLEXIO_TIMCTL_TRGSEL_SHIFT_U32) \
                         | FLEXIO_TMR_TRIGGER_ACTIVE_LOW_U32 \
                         | FLEXIO_TMR_INTERNAL_TRIGGER_U32 \
                         | ((Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxPin) << FLEXIO_TIMCTL_PINSEL_SHIFT_U32) \
                         | FLEXIO_TMR_DUAL_8BIT_BAUD_U32) \
    );

    /* Configure for Receive */
    /* Configure start bit of 0 and stop bit of 1. */
    /**
    *
    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
    */
    REG_WRITE32(FLEXIO_SHIFTCFGn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId)), \
                                       (FLEXIO_STOP_BIT_VALUE_1_U32|FLEXIO_START_BIT_VALUE_0_U32) \
               );

    /* Select timer, pin */
    /**
    *
    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
    */
    REG_WRITE32(FLEXIO_SHIFTCTLn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId)), \
                                       (((Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxTimerId) << FLEXIO_SHIFTCTL_TIMSEL_SHIFT_U32) \
                                       | ((Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxPin) << FLEXIO_SHIFTCTL_PINSEL_SHIFT_U32) \
                                       | FLEXIO_SHIFT_ON_NEGEDGE_OF_SHIFT_CLK_U32 \
                                       | FLEXIO_SHIFTER_PIN_OUTPUT_DISABLED_U32 \
                                       | FLEXIO_SHIFTER_RECEIVE_MODE_U32) \
               );
    /* Configure timer */
    /* Configure N-bit transfer with baud rate of divide by 4 of the FlexIO clock */
    /**
    *
    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
    */
    REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxTimerId)), \
                                     ((uint32)(Lin_pChannelConfigPtr[u8Channel]->u32Lin_BaudRate_RegValue) \
                                     | u32NumOfBits) \
                );
    /*  Configure start bit, stop bit, enable on trigger asserted and disable on compare. */
    /**
    *
    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
    */

    REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxTimerId)), \
                                     (FLEXIO_TMR_OUT_ONE_ON_ENABLE_AND_RST_U32 \
                                     | FLEXIO_TMR_DECREMENT_ON_FLEXIO_CLK_U32 \
                                     | FLEXIO_TMR_RST_ON_PIN_RISING_EDGE_U32 \
                                     | FLEXIO_TMR_DIS_ON_TMR_COMP_U32 \
                                     | FLEXIO_TMR_EN_ON_PIN_RISING_U32 \
                                     | FLEXIO_TMR_STOP_BIT_ON_TMR_DIS_U32 \
                                     | FLEXIO_TMR_START_BIT_ENABLED_U32) \
                );
    /* Configure dual 8-bit counter using Shifter status flag as inverted internal trigger source */
    /**
    *
    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
    */
    REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxTimerId)), \
                                     ((u32RxTRGSEL << FLEXIO_TIMCTL_TRGSEL_SHIFT_U32) \
                                     | FLEXIO_TMR_TRIGGER_ACTIVE_HIGH_U32 \
                                     | FLEXIO_TMR_EXTERNAL_TRIGGER_U32 \
                                     | ((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxPin) << FLEXIO_TIMCTL_PINSEL_SHIFT_U32) \
                                     | FLEXIO_TMR_PIN_ACTIVE_LOW_U32 \
                                     | FLEXIO_TMR_DUAL_8BIT_BAUD_U32) \
               );
    /* Disable all interrupt */
    u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId);
    Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue), 0U);

    u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId);
    Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue), 0U);

    /* Discard FLEXIO Rx Buffer */
    /**
    *
    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
    */
    REG_READ32(FLEXIO_SHIFTBUFBYSn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId)));

     if ((uint8) STD_ON == Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinChannelWakeupSupport)
    {
        /* Enable Rx Timer Interrupt to wake up detection */
        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxTimerId);
        Mcl_Flexio_WriteTimIen((uint8)(1U << u32WriteValue), (uint8)(1U << u32WriteValue));
    }
     Lin_FlexIO_au8FrameOnGoing[u8Channel] = (uint8)FALSE;
}

/**
* @brief   Sends the header part of the LIN frame.
* @details Initiates the transmission of the header
*          part of the LIN frame on Channel using information
*          stored on pPduInfoPtr pointer.
*          If response type is MASTER_RESPONSE then nothing is sent over the bus
*          the entire frame (including header) is sent with the Lin_FlexIO_SendReponse
*
* @param[in]   Channel LIN channel to be addressed.
* @param[in]   pPduInfoPtr pointer to PDU containing the PID, Checksum model,
*              Response type, Dl and SDU data pointer.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*
*/
FUNC (Std_ReturnType, LIN_CODE) Lin_FlexIO_SendHeader(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) pPduInfoPtr)
{
    VAR(uint32, AUTOMATIC) volatile u32Counter = 0U;
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (uint8)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32WriteValue = 0U;
    VAR(uint8, AUTOMATIC) volatile u8FlagStatus = (uint8)0U;
    VAR(uint8, AUTOMATIC) u8BreakLength;
    VAR(uint16, AUTOMATIC) u16BreakLength_value;

    /* Get the Break Length chose for the hardware Lin channel from logical channel */
    u8BreakLength = Lin_pChannelConfigPtr[u8Channel]->u8LinChannelBreakLength;

    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_32();
    {
        /* Disable all interrupt */
        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId);
        Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue), 0U);

        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId);
        Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue), 0U);

        /* Wait till Cancellation of current frame */
        while(u32Counter <= (LIN_TIMEOUT_LOOPS + (uint32)1U))
        {
            if((uint8)FALSE != (uint8)Lin_FlexIO_au8FrameOnGoing[u8Channel])
            {
                /**
                *
                * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
                * 
                * @violates @ref Lin_FlexIO_c_REF_9 The right-hand operand shall not contain side effects
                * 
                * @violates @ref Lin_FlexIO_c_REF_10 cast to a type of the same signedness
                */
                u8FlagStatus = (uint8)((FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId) == \
                                        Mcl_Flexio_ReadShiftStat((uint8)FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId))) && \
                                       (FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId) == \
                                        Mcl_Flexio_ReadShiftStat((uint8)FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId))));
            }
            else
            {
                /**
                *
                * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
                * 
                * @violates @ref Lin_FlexIO_c_REF_10 cast to a type of the same signedness
                */
                u8FlagStatus = (uint8)(FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId) == \
                                       Mcl_Flexio_ReadShiftStat((uint8)FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId)));
            }
            if(u8FlagStatus)
            {
                u8TmpReturn = (uint8)E_OK;
                break;
            }
            else
            {
                u32Counter++;
            }
        }
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_32();

    /* Clear TX Error flags */
    u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId);
    Mcl_Flexio_ClearShiftErr((uint8)(1U << u32WriteValue));
    /* Clear RX Error flags */
    u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId);
    Mcl_Flexio_ClearShiftErr((uint8)(1U << u32WriteValue));

    /* Discard FLEXIO Rx Buffer */
    /**
    *
    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
    */
    REG_READ32(FLEXIO_SHIFTBUFBYSn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId)));

    if((uint8)E_OK == u8TmpReturn)
    {
        Lin_FlexIO_au8FrameOnGoing[u8Channel] = (uint8)TRUE;

        /* Reset error status global flag */
        Lin_au8LinChFrameErrorStatus[u8Channel] = LIN_NO_ERROR;

        /* Configure break length */
        switch(u8BreakLength)
        {
            case FLEXIO_14_BREAK_BYTE_U8:
                u16BreakLength_value = FLEXIO_14_BREAK_BYTE_VALUE_U16;
            break;
            case FLEXIO_15_BREAK_BYTE_U8:
                u16BreakLength_value = FLEXIO_15_BREAK_BYTE_VALUE_U16;
            break;
            default:
                u16BreakLength_value = FLEXIO_13_BREAK_BYTE_VALUE_U16;
            break;
        }

        if (LIN_ENHANCED_CS == pPduInfoPtr->Cs)
        {
            /* Update LIN Checksum type to LIN_ENHANCED_CS */
            bFlexIO_ChecksumType = (boolean)TRUE;
        }
        else
        {
            /* Update LIN Checksum type to LIN_CLASSIC_CS */
            bFlexIO_ChecksumType = (boolean)FALSE;
        }

        /* Set header status to TRUE if master wants to send the response frame */
        if (LIN_MASTER_RESPONSE == pPduInfoPtr->Drc)
        {
            Lin_au8TransmitHeaderCommand[u8Channel] = LIN_TX_MASTER_RES_COMMAND;
            /* Update LIN channel frame operation status to LIN_CH_READY_STATE */
            Lin_au8LinChFrameStatus[u8Channel] = LIN_CH_READY_STATE;
        }
        else if(LIN_SLAVE_RESPONSE == pPduInfoPtr->Drc)
        {
            Lin_au8TransmitHeaderCommand[u8Channel] = LIN_TX_SLAVE_RES_COMMAND;
            Lin_au8LinChFrameStatus[u8Channel] = LIN_CH_RECEIVE_NOTHING_STATE;
        }
        else
        {
            Lin_au8TransmitHeaderCommand[u8Channel] = LIN_TX_SLAVE_TO_SLAVE_COMMAND;
            Lin_au8LinChFrameStatus[u8Channel] = LIN_CH_RECEIVE_NOTHING_STATE;
        }

        /* The buffer contains [break byte, sync byte, pid, data, checksum] */
        Lin_FlexIO_au8BufferLength[u8Channel] = (uint8)4U + ((pPduInfoPtr->Dl > FLEXIO_MAX_DATA_LENGTH_U8) ? FLEXIO_MAX_DATA_LENGTH_U8 : pPduInfoPtr->Dl);

        /* Store Sync byte data to buffer */
        Lin_FlexIO_au8Buffer[u8Channel][FLEXIO_SYNCH_BYTE_OFFSET_U8] = FLEXIO_SYNC_BYTE_U8;

        /* Store PID byte data to buffer */
        Lin_FlexIO_PIDCalc(u8Channel, pPduInfoPtr->Pid);

        /* Set Data Direction */
        if (LIN_MASTER_RESPONSE == pPduInfoPtr->Drc)
        {
            /* Do not transmit header here because it's a master->slave frame
            the header will be transmitted together with the response when calling SendResponse function */
        }
        else
        {
            /* Transmit Header */
            /* Set next byte to send the sync byte. This will be used in the transmission complete interrupt */
            Lin_FlexIO_au8BufferPtr[u8Channel] = FLEXIO_BREAK_BYTE_OFFSET_U8;

            SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_33();
            {
                /* Enable Tx, Rx Error Interrupts */
                u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId);
                Mcl_Flexio_WriteShiftEien((uint8)(1U << u32WriteValue),(uint8)(1U << u32WriteValue));

                u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId);
                Mcl_Flexio_WriteShiftEien((uint8)(1U << u32WriteValue),(uint8)(1U << u32WriteValue));

                /* Configure 16-bit transfer */
                u32WriteValue = (uint32)(FLEXIO_TIMCMPn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxTimerId)));
                /**
                *
                * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
                */
                REG_RMW32((uint32)u32WriteValue, (uint32)FLEXIO_TIMCMP_BITS_NUMBER_MASK_U32, (uint32)FLEXIO_TIMCMP_BITS_NUMBER_16_U32);
                /* Configure 16-bit transfer */
                /**
                *
                * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
                */
                REG_RMW32(FLEXIO_TIMCMPn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxTimerId)), \
                                                (uint32)FLEXIO_TIMCMP_BITS_NUMBER_MASK_U32, \
                                                (uint32)FLEXIO_TIMCMP_BITS_NUMBER_16_U32 \
                         );
                /* Enable Receive Complete Interrupt */
                u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId);
                Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue),(uint8)(1U << u32WriteValue));

                /* Send break byte first */
                /**
                *
                * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
                */
                REG_WRITE32(FLEXIO_SHIFTBUFn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId)), \
                                                    u16BreakLength_value \
                           );
            }
            SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_33();
        }
    }
    return u8TmpReturn;
}

/**
* @brief   Sends the response part of the LIN frame.
* @details Initiates the transmission of the data
*          part of the LIN frame on Channel using information
*          stored on pPduInfoPtr pointer.
*
* @param[in]   Channel LIN channel to be addressed.
* @param[in]   pPduInfoPtr pointer to PDU containing the PID, Checksum model,
*              Response type, Dl and SDU data pointer.
*
* @return      void.
*
*/
FUNC (void, LIN_CODE) Lin_FlexIO_SendResponse(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) pPduInfoPtr)
{
    VAR(uint8, AUTOMATIC) u8Loop = (uint8)0U;
    VAR(uint8, AUTOMATIC) u8Lin_FrameID;
    VAR(uint32, AUTOMATIC) u32WriteValue = 0U;
    VAR(uint8, AUTOMATIC) u8BreakLength;
    VAR(uint16, AUTOMATIC) u16BreakLength_value;

    /* Get the Break Length chose for the hardware Lin channel from logical channel */
    u8BreakLength = Lin_pChannelConfigPtr[u8Channel]->u8LinChannelBreakLength;

    /* Configure break length */
    switch(u8BreakLength)
    {
        case FLEXIO_14_BREAK_BYTE_U8:
            u16BreakLength_value = FLEXIO_14_BREAK_BYTE_VALUE_U16;
        break;
        case FLEXIO_15_BREAK_BYTE_U8:
            u16BreakLength_value = FLEXIO_15_BREAK_BYTE_VALUE_U16;
        break;
        default:
            u16BreakLength_value = FLEXIO_13_BREAK_BYTE_VALUE_U16;
        break;
    }

    /* Tx Buffer Preparation */
    for(u8Loop = (uint8)0U; u8Loop < ((pPduInfoPtr->Dl > FLEXIO_MAX_DATA_LENGTH_U8) ? FLEXIO_MAX_DATA_LENGTH_U8 : pPduInfoPtr->Dl); u8Loop++)
    {
        /**
        * @violates @ref Lin_FlexIO_c_REF_4 pointer arithmetic other
        *                than array indexing used
        */
        Lin_FlexIO_au8Buffer[u8Channel][FLEXIO_DATA_OFFSET_U8 + u8Loop] = pPduInfoPtr->SduPtr[u8Loop];
    }

    /* Checksum Calculate */
    u8Lin_FrameID = pPduInfoPtr->Pid;
    switch(u8Lin_FrameID)
    {
        case FLEXIO_MASTER_REQUEST_DIAGNOSTIC_ID_U8:
        case FLEXIO_SLAVE_RESPONSE_DIAGNOSTIC_ID_U8:
            Lin_FlexIO_au8Buffer[u8Channel][Lin_FlexIO_au8BufferLength[u8Channel] - ((uint8)1U)] = (uint8)Lin_FlexIO_ChecksumCalc(u8Channel, LIN_CLASSIC_CS);
        break;
        default:
            if((boolean)TRUE == bFlexIO_ChecksumType)
            {
                /* Enhance checksum */
                Lin_FlexIO_au8Buffer[u8Channel][Lin_FlexIO_au8BufferLength[u8Channel] - ((uint8)1U)] = (uint8)Lin_FlexIO_ChecksumCalc(u8Channel, LIN_ENHANCED_CS);
            }
            else
            {
                /* Classic checksum */
                Lin_FlexIO_au8Buffer[u8Channel][Lin_FlexIO_au8BufferLength[u8Channel] - ((uint8)1U)] = (uint8)Lin_FlexIO_ChecksumCalc(u8Channel, LIN_CLASSIC_CS);
            }
        break;
    }
    /* Transmit Header */
    /* Set next byte to send the sync byte. This will be used in the transmission complete interrupt */
    Lin_FlexIO_au8BufferPtr[u8Channel] = FLEXIO_BREAK_BYTE_OFFSET_U8;

    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_34();
    {
        /* Enable Error Interrupts */
        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId);
        Mcl_Flexio_WriteShiftEien((uint8)(1U << u32WriteValue),(uint8)(1U << u32WriteValue));

        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId);
        Mcl_Flexio_WriteShiftEien((uint8)(1U << u32WriteValue),(uint8)(1U << u32WriteValue));

        /* Configure 16-bit transfer */
        /**
        *
        * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
        */
        REG_RMW32(FLEXIO_TIMCMPn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxTimerId)), \
                                        (uint32)FLEXIO_TIMCMP_BITS_NUMBER_MASK_U32, \
                                        (uint32)FLEXIO_TIMCMP_BITS_NUMBER_16_U32 \
                 );
        /* Configure 16-bit transfer */
        /**
        *
        * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
        */
        REG_RMW32(FLEXIO_TIMCMPn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxTimerId)), \
                                        (uint32)FLEXIO_TIMCMP_BITS_NUMBER_MASK_U32, \
                                        (uint32)FLEXIO_TIMCMP_BITS_NUMBER_16_U32 \
                 );
        /* Enable Receive Complete Interrupt */
        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId);
        Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue),(uint8)(1U << u32WriteValue));
        /* Send break byte first */
        /**
        *
        * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
        */
        REG_WRITE32(FLEXIO_SHIFTBUFn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId)), \
                                            u16BreakLength_value \
                   );
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_34();
}

/**
* @brief   Prepares and send a go-to-sleep-command
*          frame on Channel.
* @details This function stops any ongoing transmission and initiates
*          the transmission of the sleep command (master command frame with
*          ID = 0x3C and data = (0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time-out situation only.
* @retval E_OK       Otherwise.
*
*/
FUNC (Std_ReturnType, LIN_CODE) Lin_FlexIO_GoToSleep(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint32, AUTOMATIC) volatile u32Counter = 0U;
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (uint8)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32WriteValue = 0U;
    VAR(uint8, AUTOMATIC) volatile u8FlagStatus = (uint8)0U;
    VAR(uint8, AUTOMATIC) u8BreakLength;
    VAR(uint16, AUTOMATIC) u16BreakLength_value;
 
    /* Get the Break Length chose for the hardware Lin channel from logical channel */
    u8BreakLength = Lin_pChannelConfigPtr[u8Channel]->u8LinChannelBreakLength;
 
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_35();
    {
        /* Disable all interrupt */
        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId);
        Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue), 0U);

        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId);
        Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue), 0U);

        /* Wait till Cancellation of current frame */
        while(u32Counter <= (LIN_TIMEOUT_LOOPS + (uint32)1))
        {
            if((uint8)FALSE != (uint8)Lin_FlexIO_au8FrameOnGoing[u8Channel])
            {
                /**
                *
                * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
                * 
                * @violates @ref Lin_FlexIO_c_REF_9 The right-hand operand shall not contain side effects
                * 
                * @violates @ref Lin_FlexIO_c_REF_10 cast to a type of the same signedness
                */
                u8FlagStatus = (uint8)((FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId) == \
                                        Mcl_Flexio_ReadShiftStat((uint8)FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId))) && \
                                       (FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId) == \
                                        Mcl_Flexio_ReadShiftStat((uint8)FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId))));
            }
            else
            {
                /**
                *
                * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
                * 
                * @violates @ref Lin_FlexIO_c_REF_10 cast to a type of the same signedness
                */
                u8FlagStatus = (uint8)(FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId) == \
                                       Mcl_Flexio_ReadShiftStat((uint8)FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId)));
            }
            if(u8FlagStatus)
            {
                u8TmpReturn = (uint8)E_OK;
                break;
            }
            else
            {
                u32Counter++;
            }
        }
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_35();

    /* Clear TX Error flags */
    u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId);
    Mcl_Flexio_ClearShiftErr((uint8)(1U << u32WriteValue));
    /* Clear RX Error flags */
    u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId);
    Mcl_Flexio_ClearShiftErr((uint8)(1U << u32WriteValue));

    /* Discard FlexIO Rx Buffer */
    /**
    *
    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
    */
    REG_READ32(FLEXIO_SHIFTBUFBYSn_ADDR32( (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId)));

    if((uint8)E_OK == u8TmpReturn)
    {
        /* Configure break length */
        switch(u8BreakLength)
        {
            case FLEXIO_14_BREAK_BYTE_U8:
                u16BreakLength_value = FLEXIO_14_BREAK_BYTE_VALUE_U16;
            break;
            case FLEXIO_15_BREAK_BYTE_U8:
                u16BreakLength_value = FLEXIO_15_BREAK_BYTE_VALUE_U16;
            break;
            default:
                u16BreakLength_value = FLEXIO_13_BREAK_BYTE_VALUE_U16;
            break;
        }

        Lin_FlexIO_au8BufferLength[u8Channel] = FLEXIO_MAX_BUFFER_LENGTH_U8;
        Lin_FlexIO_au8FrameOnGoing[u8Channel] = (uint8)TRUE;

        /* Prepare header */
        /* Store Sync byte data to buffer */
        Lin_FlexIO_au8Buffer[u8Channel][FLEXIO_SYNCH_BYTE_OFFSET_U8] = FLEXIO_SYNC_BYTE_U8;
        /* Store PID byte data to buffer */
        Lin_FlexIO_PIDCalc(u8Channel, FLEXIO_MASTER_REQUEST_DIAGNOSTIC_ID_U8);

        /* The Go to sleep command is (0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF) */
        Lin_FlexIO_au8Buffer[u8Channel][FLEXIO_DATA_OFFSET_U8] = FLEXIO_DATA_0_U8;
        Lin_FlexIO_au8Buffer[u8Channel][FLEXIO_DATA_OFFSET_U8+(uint8)1U] = FLEXIO_DATA_255_U8;
        Lin_FlexIO_au8Buffer[u8Channel][FLEXIO_DATA_OFFSET_U8+(uint8)2U] = FLEXIO_DATA_255_U8;
        Lin_FlexIO_au8Buffer[u8Channel][FLEXIO_DATA_OFFSET_U8+(uint8)3U] = FLEXIO_DATA_255_U8;
        Lin_FlexIO_au8Buffer[u8Channel][FLEXIO_DATA_OFFSET_U8+(uint8)4U] = FLEXIO_DATA_255_U8;
        Lin_FlexIO_au8Buffer[u8Channel][FLEXIO_DATA_OFFSET_U8+(uint8)5U] = FLEXIO_DATA_255_U8;
        Lin_FlexIO_au8Buffer[u8Channel][FLEXIO_DATA_OFFSET_U8+(uint8)6U] = FLEXIO_DATA_255_U8;
        Lin_FlexIO_au8Buffer[u8Channel][FLEXIO_DATA_OFFSET_U8+(uint8)7U] = FLEXIO_DATA_255_U8;

        /* The Classic checksum for the go to sleep frame is 0x00 */
        Lin_FlexIO_au8Buffer[u8Channel][Lin_FlexIO_au8BufferLength[u8Channel] - ((uint8)1U)] = (uint8)Lin_FlexIO_ChecksumCalc(u8Channel, LIN_CLASSIC_CS);

        /* Set next byte to send the sync byte. This will be used in the transmission complete interrupt */
        Lin_FlexIO_au8BufferPtr[u8Channel] = FLEXIO_BREAK_BYTE_OFFSET_U8;

        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_36();
        {
            /* Enable Error Interrupts */
            u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId);
            Mcl_Flexio_WriteShiftEien((uint8)(1U << u32WriteValue),(uint8)(1U << u32WriteValue));

            u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId);
            Mcl_Flexio_WriteShiftEien((uint8)(1U << u32WriteValue),(uint8)(1U << u32WriteValue));

            /* Set header command type is sleep*/
            Lin_au8TransmitHeaderCommand[u8Channel] = LIN_TX_SLEEP_COMMAND;

            /* Configure 16-bit transfer */
            /**
            *
            * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
            */
            REG_RMW32(FLEXIO_TIMCMPn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxTimerId)), \
                                            (uint32)FLEXIO_TIMCMP_BITS_NUMBER_MASK_U32, \
                                            (uint32)FLEXIO_TIMCMP_BITS_NUMBER_16_U32 \
                     );
            /* Configure 16-bit transfer */
            /**
            *
            * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
            */
            REG_RMW32(FLEXIO_TIMCMPn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxTimerId)), \
                                            (uint32)FLEXIO_TIMCMP_BITS_NUMBER_MASK_U32, \
                                            (uint32)FLEXIO_TIMCMP_BITS_NUMBER_16_U32 \
                     );
            /* Enable Receive Complete Interrupt */
            u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId);
            Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue),(uint8)(1U << u32WriteValue));
            /* Send break byte first */
            /**
            *
            * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
            */
            REG_WRITE32(FLEXIO_SHIFTBUFn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId)), \
                                                u16BreakLength_value \
                       );
        }
        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_36();
    }
    return u8TmpReturn;
}

/**
* @brief   Same function as Lin_FlexIO_GoToSleep() but
*          without sending a go-to-sleep-command on the bus.
* @details This function stops any ongoing transmission and put the
*          Channel in sleep mode (then LIN hardware enters a
*          reduced power operation mode).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time-out situation only.
* @retval E_OK       Otherwise.
*
*/
FUNC (Std_ReturnType, LIN_CODE) Lin_FlexIO_GoToSleepInternal(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint32, AUTOMATIC) volatile u32Counter = 0U;
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (uint8)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32WriteValue = 0U;
    VAR(uint8, AUTOMATIC) volatile u8FlagStatus = (uint8)0U;
    VAR(uint32, AUTOMATIC) u32NumOfBits;

    /* Calculate number of bit to wrire to FLEXIO_TIMCMPn register to detect wakeup pluse */
    u32NumOfBits = (uint32)((FLEXIO_MIN_WAKEUP_PULSE_LENGTH_U32/FLEXIO_BIT_LENGTH32(Lin_pcConfigPtr->pLin_Channel[u8Channel]->u32Baudrate)) + (uint8)1U);
    u32NumOfBits = (uint32)((uint32)((uint32)((uint32)u32NumOfBits * 2U) - 1U) << 8U);

    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_37();
    {
        /** Stop any ongoing transmission */
        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId);
        Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue), 0U);

        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId);
        Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue), 0U);

        /* Wait till Cancellation of current frame */
        while(u32Counter <= (LIN_TIMEOUT_LOOPS + (uint32)1))
        {
            if((uint8)FALSE != (uint8)Lin_FlexIO_au8FrameOnGoing[u8Channel])
            {
                /**
                *
                * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
                * 
                * @violates @ref Lin_FlexIO_c_REF_9 The right-hand operand shall not contain side effects
                * 
                * @violates @ref Lin_FlexIO_c_REF_10 cast to a type of the same signedness
                */
                u8FlagStatus = (uint8)((FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId) == \
                                        Mcl_Flexio_ReadShiftStat((uint8)FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId))) && \
                                       (FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId) == \
                                        Mcl_Flexio_ReadShiftStat((uint8)FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId))));
            }
            else
            {
                /**
                *
                * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
                * 
                * @violates @ref Lin_FlexIO_c_REF_10 cast to a type of the same signedness
                */
                u8FlagStatus = (uint8)(FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId) == \
                                       Mcl_Flexio_ReadShiftStat((uint8)FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId)));
            }
            if(u8FlagStatus)
            {
                u8TmpReturn = (uint8)E_OK;
                break;
            }
            else
            {
                u32Counter++;
            }
        }
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_37();

    /* Discard FLEXIO Rx Buffer */
    /**
    *
    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
    */
    REG_READ32(FLEXIO_SHIFTBUFBYSn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId)));

    /* Sleep Command */
    /* Set Channel State to Sleep */
    Lin_au8LinChStatus[u8Channel] = LIN_CH_SLEEP_STATE;

    /* Reset buffer length */
    Lin_FlexIO_au8BufferLength[u8Channel] = (uint8)0U;

    /* Update Lin_au8TransmitHeaderCommand value to LIN_TX_NO_COMMAND */
    Lin_au8TransmitHeaderCommand[u8Channel] = LIN_TX_NO_COMMAND;

    if((uint8)E_OK == u8TmpReturn)
    {
        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_38();
        {
            /**
            *
            * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
            */
            REG_RMW32(FLEXIO_TIMCMPn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxTimerId)), \
                                            FLEXIO_TIMCMP_BITS_NUMBER_MASK_U32, \
                                            u32NumOfBits \
                    );

            /* Enable Rx Timer Interrupt to wake up detection */
            u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxTimerId);
            Mcl_Flexio_ClearTimStat((uint8)(1U << u32WriteValue));
            Mcl_Flexio_WriteTimIen((uint8)(1U << u32WriteValue), (uint8)(1U << u32WriteValue));
        }
        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_38();
    }
    return u8TmpReturn;
}

/**
* @brief   Sends a wake up signal to the LIN bus.
* @details This function shall sent a wake up signal to the LIN bus
*          and put the LIN channel in LIN_CH_OPERATIONAL state.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return            void.
*
*/
FUNC (void, LIN_CODE) Lin_FlexIO_WakeUp(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint32, AUTOMATIC) u32Counter = (uint32)0U;
    VAR(uint8, AUTOMATIC) u8WakeupByte;
    VAR(uint32, AUTOMATIC) u32WriteValue = 0U;
    VAR(uint8, AUTOMATIC) volatile u8FlagStatus = (uint8)0U;

    u8WakeupByte = (uint8)((FLEXIO_MIN_WAKEUP_PULSE_LENGTH_U32/FLEXIO_BIT_LENGTH32(Lin_pcConfigPtr->pLin_Channel[u8Channel]->u32Baudrate)) + (uint8)1U);
    u8WakeupByte = (uint8)(~((uint8)((uint8)((uint32)1U << u8WakeupByte) - (uint8)1U)));

    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_39();
    {
        /* Disable all interrupt */
        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId);
        Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue), 0U);

        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId);
        Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue), 0U);

        /* Wait till Cancellation of current frame */
        while(u32Counter <= (LIN_TIMEOUT_LOOPS + (uint32)1))
        {
            if((uint8)FALSE != (uint8)Lin_FlexIO_au8FrameOnGoing[u8Channel])
            {
                /**
                *
                * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
                * 
                * @violates @ref Lin_FlexIO_c_REF_9 The right-hand operand shall not contain side effects
                * 
                * @violates @ref Lin_FlexIO_c_REF_10 cast to a type of the same signedness
                */
                u8FlagStatus = (uint8)((FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId) == \
                                        Mcl_Flexio_ReadShiftStat((uint8)FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId))) && \
                                       (FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId) == \
                                        Mcl_Flexio_ReadShiftStat((uint8)FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId))));
            }
            else
            {
                /**
                *
                * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
                * 
                * @violates @ref Lin_FlexIO_c_REF_10 cast to a type of the same signedness
                */
                u8FlagStatus = (uint8)(FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId) == \
                                       Mcl_Flexio_ReadShiftStat((uint8)FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId)));
            }
            if(u8FlagStatus)
            {
                break;
            }
            else
            {
                u32Counter++;
            }
        }
        /* Reset Buffer Length if Lin channel already sleep but fame slave not finished */
        /**
        * @violates @ref Lin_FlexIO_c_REF_9 The right-hand operand shall not contain side effects
        */
        if((LIN_CH_SLEEP_STATE == Lin_au8LinChStatus[u8Channel]) && (0U != Lin_FlexIO_au8BufferLength[u8Channel]))
        {
            Lin_FlexIO_au8BufferLength[u8Channel] = (uint8)0U;
        }
        /* Clear TX Error flags */
        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId);
        Mcl_Flexio_ClearShiftErr((uint8)(1U << u32WriteValue));
        /* Clear RX Error flags */
        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId);
        Mcl_Flexio_ClearShiftErr((uint8)(1U << u32WriteValue));

        /* Disable wake up detection */
        /* Clear Timer Status Flags */
        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxTimerId);
        Mcl_Flexio_ClearTimStat((uint8)(1U << u32WriteValue));

        /* Disable Timer Interrupt */
        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxTimerId);
        Mcl_Flexio_WriteTimIen((uint8)(1U << u32WriteValue), 0U);

        /* Disable Shifter Interrupt */
        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId);
        Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue), 0U);
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_39();

    /* Send Wake up request */
    /**
    *
    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
    */
    REG_WRITE32(FLEXIO_SHIFTBUFn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId)), u8WakeupByte);
}

 /**
* @brief   Wake up the LIN channel.
* @details This function shall put the LIN channel in LIN_CH_OPERATIONAL state without
*          sending a wake up signal to the LIN bus
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return      void.
*
*/
FUNC(void, LIN_CODE) Lin_FlexIO_WakeupInternal(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint8, AUTOMATIC) u8WriteValue = 0U;

    /* Reset Buffer Length if Lin channel already sleep but fame slave not finished */
    /**
    * @violates @ref Lin_FlexIO_c_REF_9 The right-hand operand shall not contain side effects
    */
    if((LIN_CH_SLEEP_STATE == Lin_au8LinChStatus[u8Channel]) && (0U != Lin_FlexIO_au8BufferLength[u8Channel]))
    {
        Lin_FlexIO_au8BufferLength[u8Channel] = (uint8)0U;
    }

    /* Disable Transmit Interrupt */
    u8WriteValue = (uint8)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32TxShifterId);
    Mcl_Flexio_WriteShiftSien((uint8)(1U << u8WriteValue), 0U);
    /* Disable wake up detection */
    /* Clear Timer Status Flags */
    u8WriteValue = (uint8)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxTimerId);
    Mcl_Flexio_ClearTimStat((uint8)(1U << u8WriteValue));

    /* Disable Timer Status Interrupt */
    u8WriteValue = (uint8)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxTimerId);
    Mcl_Flexio_WriteTimIen((uint8)(1U << u8WriteValue), 0U);

    /* Disable Shifter Status Interrupt */
    u8WriteValue = (uint8)(Lin_pChannelConfigPtr[u8Channel]->pFlexIOConfigPC->u32RxShifterId);
    Mcl_Flexio_WriteShiftSien((uint8)(1U << u8WriteValue), 0U);
}
 
/**
 * @brief   Gets the status of the LIN driver when Channel is operating.
 * @details This function returns the state of the current
 *          transmission, reception or operation status.
 *          If the reception of a Slave response was successful then
 *          this service provides a pointer to the buffer where the
 *          data is stored.
 *
 * @param[in]   Channel LIN channel to be addressed
 * @param[out]  pu8LinSduPtr pointer to pointer to a shadow buffer or memory
 *              mapped LIN Hardware receive buffer where the current SDU is
 *              stored
 * @return                  Lin_StatusType.
 * @retval LIN_NOT_OK       Development or production error raised
 *                          none of the below conditions.
 * @retval LIN_TX_OK        Successful transmission.
 * @retval LIN_TX_BUSY      Ongoing transmission of header or response.
 * @retval LIN_TX_HEADER_ERROR Error occurred during header
 *                          transmission.
 * @retval LIN_TX_ERROR     Error occurred during response
 *                          transmission.
 * @retval LIN_RX_OK        Reception of correct response.
 * @retval LIN_RX_BUSY      Ongoing reception where at least one byte
 *                          has been received.
 * @retval LIN_RX_ERROR     Error occurred during reception.
 * @retval LIN_RX_NO_REPONSE No data byte has been received yet.
 * @retval LIN_OPERATIONAL  Channel is ready for next header.
 *                          transmission and no data are available.
 * @retval LIN_CH_SLEEP     Channel is in sleep mode.
 *
 *
 */
FUNC(Lin_StatusType, LIN_CODE) Lin_FlexIO_HardwareGetStatus(CONST(uint8, AUTOMATIC) u8Channel, P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) pu8LinSduPtr)
{
    VAR(uint8, AUTOMATIC) u8Temp1;
    VAR(uint8, AUTOMATIC) u8Temp2;
    VAR(uint8, AUTOMATIC) u8TransmitHeaderCommand;
    VAR(uint8, AUTOMATIC) u8ChannelFrameError;
    VAR(uint8, AUTOMATIC) u8ChannelFrameStatus;
    VAR(Lin_StatusType,AUTOMATIC) u8TempReturn = LIN_NOT_OK;

    u8Temp1 = Lin_FlexIO_au8BufferPtr[u8Channel];
    u8Temp2 = Lin_FlexIO_au8BufferLength[u8Channel];
    u8TransmitHeaderCommand = Lin_au8TransmitHeaderCommand[u8Channel];
    u8ChannelFrameStatus = Lin_au8LinChFrameStatus[u8Channel];

    /* Frame transmission */
    if(((uint8)0U) != u8Temp2)
    {
        u8ChannelFrameError = Lin_au8LinChFrameErrorStatus[u8Channel];
        /* Header transmission */
        if((FLEXIO_PID_BYTE_OFFSET_U8 + ((uint8)1U)) >= u8Temp1)
        {
            switch(u8ChannelFrameError)
            {
                /* No error has occurred */
                case LIN_NO_ERROR:
                    if((LIN_TX_SLAVE_TO_SLAVE_COMMAND == u8TransmitHeaderCommand) && (LIN_TX_HEADER_COMPLETE_STATE == u8ChannelFrameStatus))
                    {
                        u8TempReturn = LIN_TX_OK;
                    }
                    else if((LIN_TX_SLAVE_RES_COMMAND == u8TransmitHeaderCommand) && (LIN_TX_HEADER_COMPLETE_STATE == u8ChannelFrameStatus))
                    {
                        u8TempReturn = LIN_RX_NO_RESPONSE;
                    }
                    else
                    {
                        u8TempReturn = LIN_TX_BUSY;
                    }
                    break;
                /* Errors occurred */
                case LIN_BIT_ERROR:
                    u8TempReturn = LIN_TX_HEADER_ERROR;
                    break;
                default:
                    u8TempReturn = LIN_NOT_OK;
                    break;
            }
        }
        /* Data transmission */
        else if(u8Temp2 > u8Temp1)
        {
            switch(u8ChannelFrameError)
            {
                /* No error has occurred */
                case LIN_NO_ERROR:
                    if(LIN_TX_SLAVE_RES_COMMAND == u8TransmitHeaderCommand)
                    {
                        if (LIN_RX_ONGOING_STATE == u8ChannelFrameStatus)
                        {
                            u8TempReturn = LIN_RX_BUSY;
                        }
                    }
                    else if ((LIN_TX_SLAVE_TO_SLAVE_COMMAND == u8TransmitHeaderCommand) && (LIN_TX_COMPLETE_STATE == u8ChannelFrameStatus))
                    {
                        u8TempReturn = LIN_TX_OK;
                    }
                    else
                    {
                        u8TempReturn = LIN_TX_BUSY;
                    }
                    break;
                /* Errors occurred */
                case LIN_BIT_ERROR:
                    u8TempReturn = LIN_TX_ERROR;
                    break;
                case LIN_BUFFER_OVER_RUN_ERROR:
                case LIN_BUFFER_UNDER_RUN_ERROR:
                    u8TempReturn = LIN_TX_ERROR;
                    break;
                default:
                    u8TempReturn = LIN_NOT_OK;
                    break;
            }
        }
        /* The last byte has been transmitted/received */
        else if(u8Temp2 == u8Temp1)
        {
            switch(u8ChannelFrameError)
            {
                /* No error has occurred */
                case LIN_NO_ERROR:
                    if(LIN_TX_COMPLETE_STATE == u8ChannelFrameStatus)
                    {
                        u8TempReturn = LIN_TX_OK;
                        Lin_FlexIO_au8BufferLength[u8Channel] = (uint8)0U;
                    }
                    else if(LIN_RX_COMPLETE_STATE == u8ChannelFrameStatus)
                    {
                        /* Copy the data from hardware buffer */
                        Lin_FlexIO_CopyData(u8Channel, pu8LinSduPtr);
                        Lin_FlexIO_au8BufferLength[u8Channel] = (uint8)0U;
                        u8TempReturn = LIN_RX_OK;
                    }
                    else
                    {
                        /* Code Flow Error */
                        u8TempReturn = LIN_NOT_OK;
                    }
                    break;

                case LIN_CHECKSUM_ERROR:
                case LIN_BUFFER_OVER_RUN_ERROR:
                case LIN_BUFFER_UNDER_RUN_ERROR:
                    u8TempReturn = LIN_RX_ERROR;
                    break;
                default:
                    break;
            }
        }
        else
        {
            /* Code Flow Error */
            u8TempReturn = LIN_NOT_OK;
        }
    }
    else
    {
        u8TempReturn = LIN_OPERATIONAL;
    }
    return u8TempReturn;
}

/**
* @brief   Interrupt handler for Shifter on FLEXIO.
* @details This function shall manage all the Shifter ISRs on the
*          addressed channel.
*
* @param[in]    void.
*
* @return       void.
*
* @implements   Lin_FlexIO_InterruptHandler_Activity
*
* @note         Internal driver function.
*/
/**
* @violates @ref Lin_FlexIO_c_REF_5 Not required from Autosar specification.
*/
FUNC(void, LIN_CODE) Lin_FlexIO_InterruptHandler(VAR(uint8, AUTOMATIC) u8FlexIO_Channel, \
                                                 VAR(uint8, AUTOMATIC) u8ShifterStatus, \
                                                 VAR(uint8, AUTOMATIC) u8ShifterErrStatus, \
                                                 VAR(uint8, AUTOMATIC) u8TimerStatus \
                                                )
{
    VAR(sint8, AUTOMATIC) s8HwChannel;
    VAR(uint8, AUTOMATIC) u8LogicalChannel = (uint8)0U;

    /* Check if driver is initialized and get Lin logical channel */
    if(NULL_PTR != Lin_pcConfigPtr)
    {
        /**
        *
        * @violates @ref Lin_FlexIO_c_REF_10 cast to a type of the same signedness
        */
        s8HwChannel = (sint8)(u8FlexIO_Channel + LIN_LPUART_MAX_MODULES);

        while(LIN_HW_MAX_AVAILABLE_MODULES > u8LogicalChannel)
        {
             if((sint8)s8HwChannel == Lin_as8ChannelHardwareMap[Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->u8LinChannelID])
             {
                break;
            }
            else
            {
                u8LogicalChannel++;
            }
        }

        if(LIN_HW_MAX_AVAILABLE_MODULES > u8LogicalChannel)
        {
            /* Get the logical channel index from physical channel */
             u8LogicalChannel = Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->u8LinChannelID;
 
            if(0U != u8ShifterStatus)
            {
                Lin_FlexIO_TxRxInterruptHandler(u8LogicalChannel,u8ShifterStatus);
            }
            if(0U != u8ShifterErrStatus)
            {
                Lin_FlexIO_ErrorInterruptHandler(u8LogicalChannel,u8ShifterErrStatus);
            }
            if(0U != (u8TimerStatus & (uint8)(1U << (uint8)Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32RxTimerId)))
            {
                Lin_FlexIO_WakeupInterruptHandler(u8LogicalChannel);
            }
        }
        else
        {
            /* Spurious interrupt */
        }
    }
    else
    {
        /* Spurious interrupt */
    }
}

/**
* @brief   Interrupt handler for Timer on FLEXIO.
* @details This function shall manage all the Timer ISRs on the
*          addressed channel.
*
* @param[in]    Channel LIN channel to be addressed.
*
* @return       void.
*
*
*
* @note         Internal driver function.
*/
static FUNC(void, LIN_CODE) Lin_FlexIO_WakeupInterruptHandler(VAR(uint8, AUTOMATIC) u8LogicalChannel)
{
    VAR(uint8, AUTOMATIC) u8Temp1;
    VAR(uint32, AUTOMATIC) u32WriteValue = 0U;

    /* Disable Wakeup Interrupt */
    u32WriteValue = (uint8)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32RxTimerId);
    Mcl_Flexio_WriteTimIen((uint8)(1U << u32WriteValue), 0U);

    u8Temp1 = Lin_au8LinChStatus[u8LogicalChannel];

    /* Check whether the Lin channel status is in LIN_CH_SLEEP_STATE */
    if (LIN_CH_SLEEP_STATE == u8Temp1)
    {
        /* Discard data from Rx buffer */
        /**
        *
        * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
        */
        (void)REG_READ32(FLEXIO_SHIFTBUFBYSn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32RxShifterId)));

        /* Check whether wake up detection is enabled */
         if ((uint8)STD_ON == Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->u8LinChannelWakeupSupport)
         {
            /* Indicates a valid timer wakeup event to ECU State Manager */
             EcuM_CheckWakeup(Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->LinChannelEcuMWakeupSource);
             /* Update Wakeup Flag */
            Lin_FlexIO_au8WakeupFlag[u8LogicalChannel] = (uint8)FALSE;
            /* Set Channel state Operational */
            Lin_au8LinChStatus[u8LogicalChannel] = LIN_CH_OPERATIONAL;
            /* Update LIN channel frame operation status to LIN_CH_READY_STATE */
            Lin_au8LinChFrameStatus[u8LogicalChannel] = LIN_CH_READY_STATE;
        }
        else
        {
            /* Update Wakeup Flag */
            Lin_FlexIO_au8WakeupFlag[u8LogicalChannel] = (uint8)TRUE;
        }
    }
    else
    {
        /* Do nothing */
    }

    return; /* Exit function with no return */
}

/**
* @brief   Interrupt handler for TX and RX on FLEXIO.
* @details This function shall manage all the RX and TX ISRs on the
*          addressed channel.
*
* @param[in]    Channel LIN channel to be addressed.
*
* @return       void.
*
*
*
* @note         Internal driver function.
*/
static FUNC(void, LIN_CODE) Lin_FlexIO_TxRxInterruptHandler(VAR(uint8, AUTOMATIC) u8LogicalChannel,VAR(uint8, AUTOMATIC) u8ShifterStatus)
{
    VAR(uint8, AUTOMATIC) u8BufferPtr;
    VAR(uint32, AUTOMATIC) u32WriteValue = 0U;

    /* Transmit Interrupt - Unused*/
    /* Transmit Data Register Empty Flag is set */
    if (0U != (u8ShifterStatus & (uint8)FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32TxShifterId)))
    {
        /* Disable Transmit Interrupt */
        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32TxShifterId);
        Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue), 0U);

        /* Enable Receiver Interrupt */
        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32RxShifterId);
        Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue), (uint8)(1U << u32WriteValue));

        /* Transmit the next byte */
        u8BufferPtr = Lin_FlexIO_au8BufferPtr[u8LogicalChannel];

        /**
        *
        * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
        */
        REG_WRITE32(FLEXIO_SHIFTBUFn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32TxShifterId)), \
                                            Lin_FlexIO_au8Buffer[u8LogicalChannel][u8BufferPtr] \
                   );
    }
    /* Receiver Interrupt */
    /* Receive Data Register Full Flag is set */
    else if (0U != (u8ShifterStatus & (uint8)FLEXIO_SHIFTSTAT_SSF_U32(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32RxShifterId)))
    {
        Lin_FlexIO_RxInterruptHandler(u8LogicalChannel);
    }
    else
    {
        /* Do nothing */
        /* Clear all interrupt flags will trigger for timer count so we do not clear at here */
    }

    return; /* Exit function with no return */
}

/**
* @brief   Interrupt handler for RX Data Register Full on FlexIO.
* @details This function shall manage the RX ISRs on the
*          addressed channel.
*
* @param[in]    Channel LIN channel to be addressed.
*
* @return       void.
*
* @note         Internal driver function.
*/
static FUNC (void, LIN_CODE) Lin_FlexIO_RxInterruptHandler(VAR(uint8, AUTOMATIC) u8LogicalChannel)
{
    VAR(uint8, AUTOMATIC) u8Temp1;
    VAR(uint32, AUTOMATIC) u32Lin_DataReg;
    VAR(uint8, AUTOMATIC) u8BufferPtr;
    VAR(uint8, AUTOMATIC) u8BufferLength;
    VAR(uint8, AUTOMATIC) au8Lin_Command;
    VAR(uint8, AUTOMATIC) u8Lin_FrameID;
    VAR(uint32, AUTOMATIC) u32Lin_Checksum;
    VAR(uint32, AUTOMATIC) u32WriteValue = 0U;
    VAR(uint32, AUTOMATIC) u32NumOfBits;
    VAR(boolean, AUTOMATIC) bIsSleepFrame = (boolean)FALSE;

    /* Disable Receiver Interrupt */
    u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32RxShifterId);
    Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue), 0U);

    /* Read the data register */
    /**
    *
    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
    */
    u32Lin_DataReg = REG_READ32(FLEXIO_SHIFTBUFBYSn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32RxShifterId)));
    u8BufferPtr = Lin_FlexIO_au8BufferPtr[u8LogicalChannel];
    u8BufferLength = Lin_FlexIO_au8BufferLength[u8LogicalChannel];
    /* Get Lin Frame Command */
    au8Lin_Command = Lin_au8TransmitHeaderCommand[u8LogicalChannel];
    /* Get the last transmitted byte */
    u8Temp1 = Lin_FlexIO_au8Buffer[u8LogicalChannel][u8BufferPtr];

    /* Code Flow Error */
    if(u8BufferPtr >= u8BufferLength)
    {
        /* Disable Receiver Interrupt */
        u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32RxShifterId);
        Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue), 0U);
    }
    /* The next byte has been received */
    else
    {
        switch(u8BufferPtr)
        {
            case FLEXIO_BREAK_BYTE_OFFSET_U8:
                SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_41();
                {
                    /* Configure 8-bit transfer */
                    /**
                    *
                    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
                    */
                    REG_RMW32(FLEXIO_TIMCMPn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32TxTimerId)), \
                                                    (uint32)FLEXIO_TIMCMP_BITS_NUMBER_MASK_U32, \
                                                    (uint32)FLEXIO_TIMCMP_BITS_NUMBER_8_U32 \
                             );
                    /* Configure 8-bit transfer */
                    /**
                    *
                    * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
                    */
                    REG_RMW32(FLEXIO_TIMCMPn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32RxTimerId)), \
                                                    (uint32)FLEXIO_TIMCMP_BITS_NUMBER_MASK_U32, \
                                                    (uint32)FLEXIO_TIMCMP_BITS_NUMBER_8_U32 \
                             );
                    /* Enable Transmit Interrupt */
                    u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32TxShifterId);
                    Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue),(uint8)(1U << u32WriteValue));
                }
                SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_41();
                break;
            case FLEXIO_SYNCH_BYTE_OFFSET_U8:
                if((uint8)(u32Lin_DataReg & FLEXIO_DATA_8BITS_MASK_U32) != u8Temp1)
                {
                    /* Bit error detected */
                    Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_BIT_ERROR;
                    Lin_FlexIO_au8FrameOnGoing[u8LogicalChannel] = (uint8)FALSE;
                    if(LIN_TX_SLEEP_COMMAND == au8Lin_Command)
                    {
                        bIsSleepFrame = (boolean)TRUE;
                    }
                }
                else
                {
                    /* Enable Transmit Interrupt */
                    u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32TxShifterId);
                    Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue),(uint8)(1U << u32WriteValue));
                }
                break;
            default:
                switch(au8Lin_Command)
                {
                    case LIN_TX_MASTER_RES_COMMAND:
                        /* Verify received data */
                        if((uint8)(u32Lin_DataReg & FLEXIO_DATA_8BITS_MASK_U32) != u8Temp1)
                        {
                            /* Bit error detected */
                            Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_BIT_ERROR;
                            Lin_FlexIO_au8FrameOnGoing[u8LogicalChannel] = (uint8)FALSE;
                        }
                        else
                        {
                            /* The last byte has been received */
                            if(u8BufferPtr == (u8BufferLength - (uint8)1U))
                            {
                                Lin_au8LinChFrameStatus[u8LogicalChannel] = LIN_TX_COMPLETE_STATE;
                                Lin_FlexIO_au8FrameOnGoing[u8LogicalChannel] = (uint8)FALSE;
                            }
                            else
                            {
                                /* Enable Transmit Interrupt */
                                u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32TxShifterId);
                                Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue),(uint8)(1U << u32WriteValue));
                            }
                        }
                        break;
                    case LIN_TX_SLEEP_COMMAND:
                        /* Calculate number of bit to wrire to FLEXIO_TIMCMPn register to detect wakeup pluse */
                        u32NumOfBits = (uint32)((FLEXIO_MIN_WAKEUP_PULSE_LENGTH_U32/FLEXIO_BIT_LENGTH32(Lin_pcConfigPtr->pLin_Channel[u8LogicalChannel]->u32Baudrate)) + (uint8)1U);
                        u32NumOfBits = (uint32)((uint32)((uint32)((uint32)u32NumOfBits * 2U) - 1U) << 8U);
                        /* Verify received data */
                        if((uint8)(u32Lin_DataReg & FLEXIO_DATA_8BITS_MASK_U32) != u8Temp1)
                        {
                            /* Bit error detected */
                            Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_BIT_ERROR;
                            Lin_FlexIO_au8FrameOnGoing[u8LogicalChannel] = (uint8)FALSE;
                            bIsSleepFrame = (boolean)TRUE;
                        }
                        else
                        {
                            /* The last byte has been received */
                            if(u8BufferPtr == (u8BufferLength - (uint8)1U))
                            {
                                /* Sleep Command */
                                Lin_FlexIO_au8FrameOnGoing[u8LogicalChannel] = (uint8)FALSE;
                                /* Update Lin_au8TransmitHeaderCommand value to LIN_TX_NO_COMMAND */
                                Lin_au8TransmitHeaderCommand[u8LogicalChannel] = LIN_TX_NO_COMMAND;

                                /* Reset buffer length */
                                Lin_FlexIO_au8BufferLength[u8LogicalChannel] = (uint8)0U;
                                /**
                                *
                                * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
                                *
                                * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
                                */
                                REG_RMW32(FLEXIO_TIMCMPn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32RxTimerId)), \
                                                                FLEXIO_TIMCMP_BITS_NUMBER_MASK_U32, \
                                                                u32NumOfBits \
                                         );
                                 if ((uint8) STD_ON == Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->u8LinChannelWakeupSupport)
                                {
                                    /* Enable Rx Timer Interrupt to wake up detection */
                                    u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32RxTimerId);
                                    Mcl_Flexio_WriteTimIen((uint8)(1U << u32WriteValue), (uint8)(1U << u32WriteValue));
                                }
                             }
                            else
                            {
                                /* Enable Transmit Interrupt */
                                u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32TxShifterId);
                                Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue),(uint8)(1U << u32WriteValue));
                            }
                        }
                        break;
                    case LIN_TX_SLAVE_RES_COMMAND:
                        if(((uint8)(u32Lin_DataReg & FLEXIO_DATA_8BITS_MASK_U32) != u8Temp1) && (FLEXIO_PID_BYTE_OFFSET_U8 == u8BufferPtr))
                        {
                            /* Bit error detected */
                            Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_BIT_ERROR;
                            Lin_FlexIO_au8FrameOnGoing[u8LogicalChannel] = (uint8)FALSE;
                        }
                        else if(FLEXIO_PID_BYTE_OFFSET_U8 < u8BufferPtr)
                        {
                            /* Store received data */
                            Lin_FlexIO_au8Buffer[u8LogicalChannel][u8BufferPtr] = (uint8)(u32Lin_DataReg & FLEXIO_DATA_8BITS_MASK_U32);

                            /* The last byte has been received */
                            if(u8BufferPtr == (u8BufferLength - (uint8)1U))
                            {
                                Lin_FlexIO_au8FrameOnGoing[u8LogicalChannel] = (uint8)FALSE;
                                u8Lin_FrameID = Lin_FlexIO_au8Buffer[u8LogicalChannel][FLEXIO_PID_BYTE_OFFSET_U8];
                                /* Checksum Error */
                                switch(u8Lin_FrameID)
                                {
                                    case FLEXIO_MASTER_REQUEST_DIAGNOSTIC_PID_U8:
                                    case FLEXIO_SLAVE_RESPONSE_DIAGNOSTIC_PID_U8:
                                        u32Lin_Checksum = Lin_FlexIO_ChecksumCalc(u8LogicalChannel, LIN_CLASSIC_CS);
                                    break;
                                    default:
                                        if((boolean)TRUE == bFlexIO_ChecksumType)
                                        {
                                            /* Enhance checksum */
                                            u32Lin_Checksum = Lin_FlexIO_ChecksumCalc(u8LogicalChannel, LIN_ENHANCED_CS);
                                        }
                                        else
                                        {
                                            /* Classic checksum */
                                            u32Lin_Checksum = Lin_FlexIO_ChecksumCalc(u8LogicalChannel, LIN_CLASSIC_CS);
                                        }
                                    break;
                                }
                                
                                if((uint32)(u32Lin_DataReg & FLEXIO_DATA_8BITS_MASK_U32) != u32Lin_Checksum)
                                {
                                    /* Set LIN channel frame error status to LIN_CHECKSUM_ERROR */
                                    Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_CHECKSUM_ERROR;
                                }
                                else
                                {
                                    /* Update LIN channel frame operation status to LIN_RX_COMPLETE_STATE */
                                    Lin_au8LinChFrameStatus[u8LogicalChannel] = LIN_RX_COMPLETE_STATE;
                                }
                            }
                            else
                            {
                                /* Enable Receiver Interrupt */
                                u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32RxShifterId);
                                Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue),(uint8)(1U << u32WriteValue));
                                /* Set LIN channel frame status to LIN_RX_ONGOING_STATE */
                                Lin_au8LinChFrameStatus[u8LogicalChannel] = LIN_RX_ONGOING_STATE;
                            }
                        }
                        else
                        {
                            /* Update LIN channel frame operation status to LIN_TX_HEADER_COMPLETE_STATE */
                            Lin_au8LinChFrameStatus[u8LogicalChannel] = LIN_TX_HEADER_COMPLETE_STATE;
                            Lin_FlexIO_au8FrameOnGoing[u8LogicalChannel] = (uint8)FALSE;
                            /* Enable Receiver Interrupt */
                            u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32RxShifterId);
                            Mcl_Flexio_WriteShiftSien((uint8)(1U << u32WriteValue),(uint8)(1U << u32WriteValue));
                        }
                        break;
                    case LIN_TX_SLAVE_TO_SLAVE_COMMAND:
                        /* Verify received data */
                        if((u32Lin_DataReg & FLEXIO_DATA_8BITS_MASK_U32) != u8Temp1)
                        {
                            /* Bit error detected */
                            Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_BIT_ERROR;
                        }
                        else
                        {
                            Lin_au8LinChFrameStatus[u8LogicalChannel] = LIN_TX_HEADER_COMPLETE_STATE;
                        }
                        Lin_FlexIO_au8FrameOnGoing[u8LogicalChannel] = (uint8)FALSE;
                        break;
                    default:
                        /* Code Flow Error */
                        break;
                }
                break;
        }
        if((boolean)TRUE == bIsSleepFrame)
        {
            /* Update Lin_au8TransmitHeaderCommand value to LIN_TX_NO_COMMAND */
            Lin_au8TransmitHeaderCommand[u8LogicalChannel] = LIN_TX_NO_COMMAND;
            /* Calculate number of bit to wrire to FLEXIO_TIMCMPn register to detect wakeup pluse */
            u32NumOfBits = (uint32)((FLEXIO_MIN_WAKEUP_PULSE_LENGTH_U32/FLEXIO_BIT_LENGTH32(Lin_pcConfigPtr->pLin_Channel[u8LogicalChannel]->u32Baudrate)) + (uint8)1U);
            u32NumOfBits = (uint32)((uint32)((uint32)((uint32)u32NumOfBits * 2U) - 1U) << 8U);
            /**
            *
            * @violates @ref Lin_FlexIO_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_FlexIO_c_REF_8 cast should not be performed
            */
            REG_RMW32(FLEXIO_TIMCMPn_ADDR32((uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32RxTimerId)), \
                                            FLEXIO_TIMCMP_BITS_NUMBER_MASK_U32, \
                                            u32NumOfBits \
                     );
             if ((uint8) STD_ON == Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->u8LinChannelWakeupSupport)
            {
                /* Enable Rx Timer Interrupt to wake up detection */
                u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32RxTimerId);
                Mcl_Flexio_WriteTimIen((uint8)(1U << u32WriteValue), (uint8)(1U << u32WriteValue));
            }
         }
        /* Increase Buffer Pointer */
        Lin_FlexIO_au8BufferPtr[u8LogicalChannel]++;
    }
}

/**
* @brief   Interrupt handler for Error on FLEXIO.
* @details This function shall manage all the Error ISRs on the
*          addressed channel.
*
* @param[in]    Channel LIN channel to be addressed.
*
* @return       void.
*
*
* @note         Internal driver function.
*/
static FUNC (void, LIN_CODE) Lin_FlexIO_ErrorInterruptHandler(VAR(uint8, AUTOMATIC) u8LogicalChannel,VAR(uint8, AUTOMATIC) u8ShifterErrStatus)
{
    VAR(uint32, AUTOMATIC) u32WriteValue = 0U;
    VAR(uint32, AUTOMATIC) u32WriteValue2 = 0U;

    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_42();
    {
        if(0U != u8ShifterErrStatus)
        {
            u32WriteValue = (uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32TxShifterId);
            u32WriteValue2 = (uint32)(Lin_pChannelConfigPtr[u8LogicalChannel]->pFlexIOConfigPC->u32RxShifterId);

            if(0U != (u8ShifterErrStatus & (uint8)(1U << u32WriteValue)))
            {
                /* Set LIN channel frame error status to LIN_BUFFER_OVER_RUN_ERROR */
                Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_BUFFER_OVER_RUN_ERROR;
                Lin_FlexIO_au8FrameOnGoing[u8LogicalChannel] = (uint8)FALSE;
            }
            else if (0U != (u8ShifterErrStatus & (uint8)(1U << u32WriteValue2)))
            {
                /* Set LIN channel frame error status to LIN_BUFFER_OVER_RUN_ERROR */
                Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_BUFFER_UNDER_RUN_ERROR;
                Lin_FlexIO_au8FrameOnGoing[u8LogicalChannel] = (uint8)FALSE;
            }
            /* Unknown Error Interrupts */
            else
            {
                /* Reset all error interrupt flags by MCL */
            }
        }
        /* Unknown Error Interrupts */
        else
        {
            /* Reset all error interrupt flags by MCL */
        }
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_42();

    return; /* Exit function with no return */
}

#define LIN_STOP_SEC_CODE

/**
* @violates @ref Lin_FlexIO_c_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*
* @violates @ref Lin_FlexIO_c_REF_2 #include statements in a
* file should only be preceded by other preprocessor directives or comments.
*/
 #include "Lin_MemMap.h"
 
#ifdef __cplusplus
}
#endif

#endif /* LIN_FLEXIO_C */

/** @} */
