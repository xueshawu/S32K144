/**
*   @file    Lin_FlexIO.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - Low level driver header file.
*   @details This file includes the function prototypes defined in the LIN low level driver for FlexIO.
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

#ifndef LIN_FLEXIO_H
#define LIN_FLEXIO_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Lin_FlexIO_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_FlexIO_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character significance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Lin_FlexIO_h_REF_3
* Violates MISRA 2004 Required Rule 8.8, Precautions shall be taken
* in order to prevent external objects or functions to be declared
* in more than one file.
*
* @section Lin_FlexIO_h_REF_4
* Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to a function-
* like macro. This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Lin_FlexIO.h
*/
#define LIN_FLEXIO_VENDOR_ID                    43
/**
* @violates @ref Lin_FlexIO_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_FLEXIO_AR_RELEASE_MAJOR_VERSION     4
/**
* @violates @ref Lin_FlexIO_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_FLEXIO_AR_RELEASE_MINOR_VERSION     3
/**
* @violates @ref Lin_FlexIO_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_FLEXIO_AR_RELEASE_REVISION_VERSION  1
#define LIN_FLEXIO_SW_MAJOR_VERSION             1
#define LIN_FLEXIO_SW_MINOR_VERSION             0
#define LIN_FLEXIO_SW_PATCH_VERSION             1

#if (LIN_FLEXIO_USED == STD_ON)
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and LIN_Types header file are of the same vendor */

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief        Maximum Length of Data.
*
*/
#define FLEXIO_MAX_DATA_LENGTH_U8                  ((uint8)LIN_MAX_DATA_LENGTH)
/**
* @brief        Maximum Length of Buffer (Break(1), Sync(1), Pid(1), Data bytes and Checksum(1)).
*
*/
#define FLEXIO_MAX_BUFFER_LENGTH_U8                ((uint8)LIN_MAX_DATA_LENGTH+(uint8)4U)

/**
* @brief        Master Request Diagnostic Frame ID 0x3C.
*
*/
/**
* @violates @ref Lin_FlexIO_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define FLEXIO_MASTER_REQUEST_DIAGNOSTIC_ID_U8     ((uint8)0x3CU)

/**
* @brief        Slave Response Diagnostic Frame ID 0x3D.
*
*/
/**
* @violates @ref Lin_FlexIO_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define FLEXIO_SLAVE_RESPONSE_DIAGNOSTIC_ID_U8     ((uint8)0x3DU)

/**
* @brief        Master Request Diagnostic Frame PID 0x3C.
*
*/
/**
* @violates @ref Lin_FlexIO_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define FLEXIO_MASTER_REQUEST_DIAGNOSTIC_PID_U8     ((uint8)0x3CU)

/**
* @brief        Slave Response Diagnostic Frame PID 0x7D.
*
*/
/**
* @violates @ref Lin_FlexIO_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define FLEXIO_SLAVE_RESPONSE_DIAGNOSTIC_PID_U8     ((uint8)0x7DU)

/**
* @brief        13 Bit break value.
*
*/
#define FLEXIO_13_BREAK_BYTE_VALUE_U16                       ((uint16)0x7U)

/**
* @brief        14 Bit break value.
*
*/
#define FLEXIO_14_BREAK_BYTE_VALUE_U16                       ((uint16)0x3U)

/**
* @brief        15 Bit break value.
*
*/
#define FLEXIO_15_BREAK_BYTE_VALUE_U16                       ((uint16)0x1U)

/**
* @brief        14 Bit break.
*
*/
#define FLEXIO_14_BREAK_BYTE_U8                              ((uint8)14U)

/**
* @brief        15 Bit break.
*
*/
#define FLEXIO_15_BREAK_BYTE_U8                              ((uint8)15U)

/**
* @brief        Synch byte.
*
*/
#define FLEXIO_SYNC_BYTE_U8                        ((uint8)0x55U)

/**
* @brief        The position of Break byte in Lin_FLEXIO_au8BytesToSend buffer.
*
*/
#define FLEXIO_BREAK_BYTE_OFFSET_U8                ((uint8)0U)
/**
* @brief        The position of Synch byte in Lin_FLEXIO_au8BytesToSend buffer.
*
*/
#define FLEXIO_SYNCH_BYTE_OFFSET_U8                ((uint8)1U)

/**
* @brief        The position of PID byte in Lin_FLEXIO_au8BytesToSend buffer.
*
*/
#define FLEXIO_PID_BYTE_OFFSET_U8                  ((uint8)2U)

/**
* @brief        The position of PID byte in Lin_FLEXIO_au8BytesToSend buffer.
*
*/
#define FLEXIO_FRAME_ID_MASK_U32                   ((uint32)0x3FU)

/**
* @brief        The position of PID byte in Lin_FLEXIO_au8BytesToSend buffer.
*
*/
#define FLEXIO_DATA_OFFSET_U8                      ((uint8)3U)

/**
* @brief        Sleep command length frame.
*
*/
#define FLEXIO_DATA_LENGTH_8_U32                   ((uint32)8U)

/**
* @brief        Sleep command frame: 0xFF data.
*
*/
#define FLEXIO_DATA_255_U8                         ((uint8)255U)

/**
* @brief        Sleep command frame: 0x00 data.
*
*/
#define FLEXIO_DATA_0_U8                           ((uint8)0U)

/**
* @brief        Catastrophic Errors Recovery (CER) Codes returned by the LIN driver.
*
* @details      Unexpected frame status CER code.
*
*/
/**
* @violates @ref Lin_FlexIO_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define FLEXIO_CER_UNEXPECTED_FRAME_STATUS_INTERRUPT_U8 ((uint8)0x01U)

/**
* @brief        Catastrophic Errors Recovery (CER) Codes returned by the LIN driver.
*
* @details      Unexpected frame error status CER code.
*
*/
/**
* @violates @ref Lin_FlexIO_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define FLEXIO_CER_UNEXPECTED_FRAME_ERROR_STATUS_INTERRUPT_U8 ((uint8)0x02U)

/**
* @brief        Minimum length in us of wakeup pulse.
*
*/
/**
* @violates @ref Lin_FlexIO_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define FLEXIO_MIN_WAKEUP_PULSE_LENGTH_U32         ((uint32)250U)

/**
* @brief        LIN bit length in us.
*/
/**
* @violates @ref Lin_FlexIO_h_REF_4 A function should be used in preference to a function-like macro.
*/
#define FLEXIO_BIT_LENGTH32(baudrate)              (((uint32)(1000000U))/((uint32)(baudrate)))
/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define LIN_START_SEC_VAR_NO_INIT_8
/**
* @violates @ref Lin_FlexIO_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
/**
* @violates @ref Lin_FlexIO_h_REF_3 Precautions shall be taken in order to prevent variables being
* declared as external in more than one file.
*/
extern volatile VAR(uint8,LIN_VAR)Lin_au8LinChStatus[LIN_HW_MAX_MODULES];

/**
* @violates @ref Lin_FlexIO_h_REF_3 Precautions shall be taken in order to prevent variables being
* declared as external in more than one file.
*/
extern volatile VAR(uint8,LIN_VAR)Lin_au8LinChFrameStatus[LIN_HW_MAX_MODULES];

/**
* @violates @ref Lin_FlexIO_h_REF_3 Precautions shall be taken in order to prevent variables being
* declared as external in more than one file.
*/
extern VAR(uint8, LIN_VAR)Lin_au8TransmitHeaderCommand[LIN_HW_MAX_MODULES];

/**
* @violates @ref Lin_FlexIO_h_REF_3 Precautions shall be taken in order to prevent variables being
* declared as external in more than one file.
*/
extern volatile VAR(uint8,LIN_VAR)Lin_au8LinChFrameErrorStatus[LIN_HW_MAX_MODULES];

/**
* @violates @ref Lin_FlexIO_h_REF_3 Precautions shall be taken in order to prevent variables being
* declared as external in more than one file.
*/
extern VAR(sint8,LIN_VAR)Lin_as8ChannelHardwareMap[LIN_HW_MAX_AVAILABLE_MODULES];

#define LIN_STOP_SEC_VAR_NO_INIT_8
/**
* @violates @ref Lin_FlexIO_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 #define LIN_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Lin_FlexIO_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
extern P2CONST(Lin_ConfigType,LIN_VAR,LIN_APPL_CONST) Lin_pcConfigPtr;
#define LIN_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Lin_FlexIO_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 #define LIN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref Lin_FlexIO_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
  
/**
* @violates @ref Lin_FlexIO_h_REF_3 Precautions shall be taken in order to prevent variables being
* declared as external in more than one file.
*/
extern P2CONST(Lin_ChannelConfigType,LIN_VAR,LIN_APPL_CONST)Lin_pChannelConfigPtr[LIN_HW_MAX_MODULES];

#define LIN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref Lin_FlexIO_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_START_SEC_CODE
/**
* @violates @ref Lin_FlexIO_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
/*****************************************************************************
**                          Non-AUTOSAR LIN Low Level Driver API's          **
*****************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_FlexIO_CheckWakeup(CONST(uint8, AUTOMATIC) u8Channel);
FUNC(void, LIN_CODE) Lin_FlexIO_InitChannel(CONST(uint8, AUTOMATIC) u8Channel);
FUNC(Std_ReturnType, LIN_CODE) Lin_FlexIO_SendHeader(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) pPduInfoPtr);
FUNC(void, LIN_CODE) Lin_FlexIO_SendResponse(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) pPduInfoPtr);
FUNC(Std_ReturnType, LIN_CODE) Lin_FlexIO_GoToSleep(CONST(uint8, AUTOMATIC) u8Channel);
FUNC(Std_ReturnType, LIN_CODE) Lin_FlexIO_GoToSleepInternal(CONST(uint8, AUTOMATIC) u8Channel);
FUNC(void, LIN_CODE) Lin_FlexIO_WakeUp(CONST(uint8, AUTOMATIC) u8Channel);
 FUNC(void, LIN_CODE) Lin_FlexIO_WakeupInternal(CONST(uint8, AUTOMATIC) u8Channel);
 FUNC(Lin_StatusType, LIN_CODE) Lin_FlexIO_HardwareGetStatus(CONST(uint8, AUTOMATIC) u8Channel, P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) pu8LinSduPtr);
FUNC(void, LIN_CODE) Lin_FlexIO_InterruptHandler(VAR(uint8, AUTOMATIC) u8FlexIO_Channel, \
                                                 VAR(uint8, AUTOMATIC) u8ShifterStatus, \
                                                 VAR(uint8, AUTOMATIC) u8ShifterErrStatus, \
                                                 VAR(uint8, AUTOMATIC) u8TimerStatus \
                                                );
#define LIN_STOP_SEC_CODE

/**
* @violates @ref Lin_FlexIO_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
#endif
#ifdef __cplusplus
}
#endif

#endif /* LIN_FLEXIO_H */

/** @} */
