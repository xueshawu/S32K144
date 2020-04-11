/**
*   @file    Can_FlexCan.h
*   @implements Can_FlexCan.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - LLD module interface.
*   @details Low Level Driver header file for IPV = FlexCan.
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


#ifndef CAN_FLEXCAN_H
#define CAN_FLEXCAN_H


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
* @section Can_Flexcan_h_REF_1
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* This violation is due to the structure of the types used.
*
* @section Can_Flexcan_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section Can_Flexcan_h_REF_4
* Violates MISRA 2004 Required Rule 8.7, Global variables containing the generated configuration
* shall be defined in a separate source file and can't be defined inside a function although it is accessed
* by a single function
*
* @section Can_Flexcan_h_REF_5
* Violates MISRA 2004 Required Rule 19.4 , The C macro expand to an Interrupt Service Routine.
* This C macros is needed in order to have a better mentenability of the code and to offer 
* flexiblity for ISR definition for different hardware platforms.
*
* @section Can_Flexcan_h_REF_6
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* This violation is because many controllers have defined Interrupt handlers with only 1 macro.
*
* @section Can_Flexcan_h_REF_7
* Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition.
* This violation is due to the use of multiple #/## in a macro because some interrupts can process both Tx/Rx
* in the same interrupt routine and have use twice this parameter. the parameter obtained with #/## is the same for
* all functions called in the interrupt routine.
*
* @section Can_Flexcan_h_REF_8
* Violates MISRA 2004 Advisory Rule 19.13,'#/##' operator used.
* This violation is due to the use of ## used to concatenate the Controller Index (A, B, ..) in ISR function name.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*  (CAN222) Imported types: Dem_Types.h, CanIf_Types.h, Std_Types.h, ComStack_Types.h */
/*
* @file           Can_FlexCan.h
*/
#include "StdRegMacros.h"
#include "Reg_eSys_FlexCan.h"
#include "Can_GeneralTypes.h"
#include "ComStack_Types.h"
#include "CanIf_Cbk.h"
#include "Mcal.h"
#include "Can.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Can_FlexCan.h
*/
#define CAN_FLEXCAN_VENDOR_ID_H                    43
#define CAN_FLEXCAN_MODULE_ID_H                    80
#define CAN_FLEXCAN_AR_RELEASE_MAJOR_VERSION_H     4
#define CAN_FLEXCAN_AR_RELEASE_MINOR_VERSION_H     3
#define CAN_FLEXCAN_AR_RELEASE_REVISION_VERSION_H  1
#define CAN_FLEXCAN_SW_MAJOR_VERSION_H             1
#define CAN_FLEXCAN_SW_MINOR_VERSION_H             0
#define CAN_FLEXCAN_SW_PATCH_VERSION_H             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys_FlexCan.h file are of the same vendor */
#if (CAN_FLEXCAN_VENDOR_ID_H != CAN_VENDOR_ID_REGFLEX)
#error "Can_Flexcan.h and Reg_eSys_FlexCan.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_FlexCan.h file are of the same module */
#if (CAN_FLEXCAN_MODULE_ID_H != CAN_MODULE_ID_REGFLEX)
#error "Can_Flexcan.h and Reg_eSys_FlexCan.h have different module ids"
#endif
/* Check if current file and Reg_eSys_FlexCan.h file are of the same Autosar version */
#if ((CAN_FLEXCAN_AR_RELEASE_MAJOR_VERSION_H != CAN_AR_RELEASE_MAJOR_VERSION_REGFLEX) || \
     (CAN_FLEXCAN_AR_RELEASE_MINOR_VERSION_H != CAN_AR_RELEASE_MINOR_VERSION_REGFLEX) || \
     (CAN_FLEXCAN_AR_RELEASE_REVISION_VERSION_H != CAN_AR_RELEASE_REVISION_VERSION_REGFLEX))
  #error "AutoSar Version Numbers of Can_Flexcan.h and Reg_eSys_FlexCan.h are different"
#endif
/* Check if current file and Reg_eSys_FlexCan.h file are of the same Software version */
#if ((CAN_FLEXCAN_SW_MAJOR_VERSION_H != CAN_SW_MAJOR_VERSION_REGFLEX) || \
     (CAN_FLEXCAN_SW_MINOR_VERSION_H != CAN_SW_MINOR_VERSION_REGFLEX) || \
     (CAN_FLEXCAN_SW_PATCH_VERSION_H != CAN_SW_PATCH_VERSION_REGFLEX))
       #error "Software Version Numbers of Can_Flexcan.h and Reg_eSys_FlexCan.h are different"
#endif

/* Check if current file and Can.h file are of the same vendor */
#if (CAN_FLEXCAN_VENDOR_ID_H != CAN_VENDOR_ID)
#error "Can_Flexcan.h and Can.h have different vendor ids"
#endif
/* Check if current file and Can.h file are of the same module */
#if (CAN_FLEXCAN_MODULE_ID_H != CAN_MODULE_ID)
#error "Can_Flexcan.h and Can.h have different module ids"
#endif
/* Check if current file and Can.h file are of the same Autosar version */
#if ((CAN_FLEXCAN_AR_RELEASE_MAJOR_VERSION_H != CAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_FLEXCAN_AR_RELEASE_MINOR_VERSION_H != CAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_FLEXCAN_AR_RELEASE_REVISION_VERSION_H != CAN_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Can_Flexcan.h Can.h are different"
#endif
/* Check if current file and Can.h file are of the same Software version */
#if ((CAN_FLEXCAN_SW_MAJOR_VERSION_H != CAN_SW_MAJOR_VERSION) || \
     (CAN_FLEXCAN_SW_MINOR_VERSION_H != CAN_SW_MINOR_VERSION) || \
     (CAN_FLEXCAN_SW_PATCH_VERSION_H != CAN_SW_PATCH_VERSION))
       #error "Software Version Numbers of Can_Flexcan.h and Can.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h file are of the same Software version */
    #if ((CAN_FLEXCAN_AR_RELEASE_MAJOR_VERSION_H != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (CAN_FLEXCAN_AR_RELEASE_MINOR_VERSION_H != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of FlexCan.h and Mcal.h are different"
    #endif

    /* Check if current file and StdRegMacros.h file are of the same Software version */
    #if ((CAN_FLEXCAN_AR_RELEASE_MAJOR_VERSION_H != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
        (CAN_FLEXCAN_AR_RELEASE_MINOR_VERSION_H != STDREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of FlexCan.h and StdRegMacros.h are different"
    #endif
    
    /* Check if current file and ComStack_Types.h file are of the same Software version */
    #if ((CAN_FLEXCAN_AR_RELEASE_MAJOR_VERSION_H != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
        (CAN_FLEXCAN_AR_RELEASE_MINOR_VERSION_H != COMTYPE_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of FlexCan.h and ComStack_Types.h are different"
    #endif
    
    /* Check if current file and CanIf_Cbk.h file are of the same Software version */
    #if ((CAN_FLEXCAN_AR_RELEASE_MAJOR_VERSION_H != CANIF_CBK_AR_RELEASE_MAJOR_VERSION) || \
        (CAN_FLEXCAN_AR_RELEASE_MINOR_VERSION_H != CANIF_CBK_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of FlexCan.h and CanIf_Cbk.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* The size of register space of FlexCan is 4KB */
#define CAN_FLEXCAN_PROT_MEM_U32 ((uint32)0x04U)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/**
* @brief          Can_HandleType
* @details        Used for value received by Tressos interface configuration.
*                 Controller does not provide any bit field to differentiate BASIC-CAN & FULL-CAN.
*
*/
typedef enum
    {
        CAN_BASIC = 0U,    /*< @brief Basic-CAN device functions */
        CAN_FULL           /*< @brief Full-CAN device functions */
    } Can_HandleType;


/**
* @brief          CAN Interrupts state.
* @details        CAN Interrupts state.
*
*/
typedef enum
    {
        CAN_INTERRUPT_DISABLED = 0U,  /*< @brief Interrupts disabled */
        CAN_INTERRUPT_ENABLED         /*< @brief Interrupts enabled */

    } Can_InterruptStateType;

/**
* @brief          CAN Pretended Networking state.
* @details        CAN Pretended Networking state.
*
*/
 typedef enum
    {
        CAN_ICOM_DEACTIVATED = 0U,     /*< @brief Pretended  Networking  is deactivated   */
        CAN_ICOM_ACTIVATED             /*< @brief Pretended  Networking  is  activated */
    } Can_IcomStateType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Records the status of a CAN Controller during runtime.
* @details        Records the status of a CAN Controller during runtime.
*
* @note           This structure is not configured by Tresos.
*/
typedef struct
    {
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_96_U8)
        VAR(uint32, CAN_VAR) u32TxGuard[3]; /*< @brief Guard bits for EXCLUSIVE ACCESS to Tx MBs */

        VAR(uint32, CAN_VAR) u32MBInterruptMask[3]; /*< @brief Pre-calculated MB INT masks (used in Can_EnableControllerInterrupts) */

        VAR(PduIdType, CAN_VAR) u32TxPduId[96]; /*< @brief Storage space for PDU_ID (supplied in call to Can_Write and needed after Tx in CanIf_TxConfirmation) */
        
        VAR(uint32, CAN_VAR) u32MBInterruptTxMask[3]; /*< @brief Pre-calculated TX MB INT masks  used to optimize ISR */
        
        VAR(uint32, CAN_VAR) u32MBInterruptRxMask[3]; /*< @brief Pre-calculated RX MB INT masks  used to optimize ISR */
#elif (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64_U8)
        VAR(uint32, CAN_VAR) u32TxGuard[2]; /*< @brief Guard bits for EXCLUSIVE ACCESS to Tx MBs */

        VAR(uint32, CAN_VAR) u32MBInterruptMask[2]; /*< @brief Pre-calculated MB INT masks (used in Can_EnableControllerInterrupts) */

        VAR(PduIdType, CAN_VAR) u32TxPduId[64]; /*< @brief Storage space for PDU_ID (supplied in call to Can_Write and needed after Tx in CanIf_TxConfirmation) */
        
        VAR(uint32, CAN_VAR) u32MBInterruptTxMask[2]; /*< @brief Pre-calculated TX MB INT masks  used to optimize ISR */
        
        VAR(uint32, CAN_VAR) u32MBInterruptRxMask[2]; /*< @brief Pre-calculated RX MB INT masks  used to optimize ISR */
#else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32_U8) */
        VAR(uint32, CAN_VAR) u32TxGuard[1]; /*< @brief Guard bits for EXCLUSIVE ACCESS to Tx MBs */

        VAR(uint32, CAN_VAR) u32MBInterruptMask[1]; /*< @brief Pre-calculated MB INT masks (used in Can_EnableControllerInterrupts) */

        VAR(PduIdType, CAN_VAR) u32TxPduId[32]; /*< @brief Storage space for PDU_ID (supplied in call to Can_Write and needed after Tx in CanIf_TxConfirmation) */
        
        VAR(uint32, CAN_VAR) u32MBInterruptTxMask[1]; /*< @brief Pre-calculated TX MB INT masks  used to optimize ISR */
        
        VAR(uint32, CAN_VAR) u32MBInterruptRxMask[1]; /*< @brief Pre-calculated RX MB INT masks  used to optimize ISR */
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32_U8) */

        volatile VAR(sint8, CAN_VAR) s8IntDisableLevel; /*< @brief Storage space for Can_DisableControllerInterrupts nesting level */

        volatile VAR(Can_HwHandleType, CAN_VAR) u32CancelMBIndex; /*< @brief Index of MB buffer being cancelled. */

        volatile VAR(uint8, CAN_VAR) u8FirstTxMBIndex; /*< @brief Index of the first MB used for Tx for a specific controller. This value is relative to 0 (which is first MB). */
        VAR(Can_InterruptStateType, CAN_VAR) eInterruptMode; /*< @brief Global interrupt autorization state */

        VAR(Can_ControllerStateType, CAN_VAR) ControllerState; /*< @brief FlexCAN controller power state */

        VAR(uint16, CAN_VAR) u16MBMapping[CAN_MAXMB_CONFIGURED]; /*< @brief Map for every MB the HOH assigned according to configuration. */
       
        VAR(uint8, CAN_VAR) u8CurrentBaudRateIndex; /*< @brief Current controller baudrate */

    #if (CAN_DUAL_CLOCK_MODE == STD_ON)
        VAR(Can_ClockModeType, AUTOMATIC)CanClockMode;
    #endif /* (CAN_DUAL_CLOCK_MODE == STD_ON) */

    #if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
        VAR(Can_IcomStateType, CAN_VAR) eCanIcomState;
    #endif /* (CAN_PUBLIC_ICOM_SUPPORT == STD_ON) */
    
#ifdef ERR_IPV_FLEXCAN_0015
    #if(ERR_IPV_FLEXCAN_0015==STD_ON)
      #if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_96_U8)
        VAR(uint32, CAN_VAR) u32TxCancelFlag[3]; /*< @brief Guard bits for EXCLUSIVE ACCESS to Tx MBs */
      #elif (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64_U8)
        VAR(PduIdType, CAN_VAR) u32TxCancelFlag[2]; /*< @brief Storage space for PDU_ID (supplied in call to Can_Write and needed after Tx in CanIf_TxConfirmation) */
      #else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32_U8) */
        VAR(uint32, CAN_VAR) u32TxCancelFlag[1]; /*< @brief Guard bits for EXCLUSIVE ACCESS to Tx MBs */
      #endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32_U8) */
    #else
        #error : the define  ERR_IPV_FLEXCAN_0015 must not be STD_OFF
    #endif
#endif
    } Can_ControllerStatusType;
    
/**
* @brief          Records the addresses for an IFLAG and an IMASK register
* @details        Records the addresses for an IFLAG and an IMASK register
*
* @note           This structure is not configured by Tresos.
*/
    typedef struct
    {
        CONST(uint32, CAN_CONST) u32CanIflag;
        CONST(uint32, CAN_CONST) u32CanImask;
    } Can_MaskFlagType;
    


typedef P2CONST( Can_MBConfigContainerType, CAN_CONST, CAN_APPL_CONST)   Can_PtrMBConfigContainerType;
typedef P2CONST( Can_ControlerDescriptorType, CAN_CONST, CAN_APPL_CONST) Can_PtrControlerDescriptorType;

#ifdef CPU_TYPE
    #if (CPU_TYPE == CPU_TYPE_64)
    /** 
    * @brief size of pointer type. on CPU_TYPE_64, the size is 64bits.
    */
    typedef uint64 pointerSizeType;
    #elif (CPU_TYPE == CPU_TYPE_32)
    /** 
    * @brief size of pointer type. on CPU_TYPE_32, the size is 32bits.
    */
    typedef uint32 pointerSizeType;
    #elif (CPU_TYPE == CPU_TYPE_16)
    /** 
    * @brief size of pointer type. on CPU_TYPE_16, the size is 16bits.
    */
    typedef uint16 pointerSizeType;
    #endif
#endif
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"

/**
* @brief          Array holding current status/run-time configuration of individual FlexCAN controllers
* @details        Array holding current status/run-time configuration of individual FlexCAN controllers:
*                 - information like Guard bits, Pre-calculated MB INT masks, Storage space for PDU_ID, INT nesting level,
*                 Index of MB buffer being cancelled, Index of the first MB used for Tx
*                 - declared as global variable in "can_IPW.c" file.
*                 See Can_FlexCan.c for declaration.
*
*/

extern VAR(Can_ControllerStatusType, CAN_VAR) Can_ControllerStatuses[CAN_MAXCTRL_CONFIGURED];

/**
* @brief          Matrix  holding the addresses of IFLAG and IMASK registers for all controllers 
* @details        Matrix  holding the addresses of IFLAG and IMASK registers for all controllers 
*
*
*/



#define CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"


#define CAN_START_SEC_CONST_UNSPECIFIED
/* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */

#include "Can_MemMap.h"

extern CONST(Can_MaskFlagType, CAN_CONST) Can_IflagImask[(uint8)((uint8)CAN_MAXMB_SUPPORTED >> FLEXCAN_MB_SHIFT5BIT_U8)][FLEXCAN_CONTROLLERS_NO];

#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*
* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/

#include "Can_MemMap.h"
/*==================================================================================================
*                                           MACROS
=====================================================================================================*/
/*==================================================================================================*/

/*ISR's for PPC*/
#if (CAN_MULTIPLE_INTERRUPTS_SUPPORT==STD_ON)  
#if (CAN_RXFIFO_ENABLE == STD_ON)
    #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
        /**
        * @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
        * @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
        * @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
        * @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
        */
        /**
        * @brief          Interrupt routine for Rx fifo Suppport.
        * @details        Interrupt routine for Rx fifo Suppport.  Defined as macro.
        *                 The controller ID is transmitted with the ## operator for the interrupt handler.
        * @remarks        FC - Can hardware channel: A, B, C, D, E, F, G, H
        * @implements     Can_Isr_X_Activity
        *
        */
        #define CAN_RXFIFO_EVENTS(FC) \
            ISR(Can_IsrFC##FC##_RxFifoEvents) { \
                    VAR(uint32, AUTOMATIC)   can_status = 0U; \
                    VAR(uint32, AUTOMATIC)   can_mask = 0U; \
                    if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
                    { \
                        REG_WRITE32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET), (uint32)((FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32 | FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32 | FLEXCAN_FIFO_WARNING_INT_MASK_U32) & FLEXCAN_IFLAG1_CONFIG_MASK_U32)); \
                    } \
                    else \
                    { \
                        can_status = (uint32)REG_READ32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET)) ; \
                        can_mask = (uint32)REG_READ32( FLEXCAN_IMASK1(FLEXCAN_##FC##_OFFSET)) ; \
                        if (FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32 == (can_status & FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32)) \
                        { \
                            if (FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32 == (can_mask & FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32)){ \
                                Can_IPW_RxFifoFrameAvNotif(CAN_FC##FC##_INDEX); \
                            } \
                            else {\
                                REG_WRITE32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET), (uint32)((can_status & FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32) & FLEXCAN_IFLAG1_CONFIG_MASK_U32)); \
                          } \
                        } \
                        if (FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32 == (can_status  & FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32)) \
                        { \
                            REG_WRITE32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET), (uint32)((can_status & FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32) & FLEXCAN_IFLAG1_CONFIG_MASK_U32));\
                            if ((NULL_PTR != Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoOverflowNotification) && (FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32 == (can_mask  & FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32))){ \
                                Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoOverflowNotification(); \
                            } \
                        }\
                        if ( FLEXCAN_FIFO_WARNING_INT_MASK_U32== (can_status & FLEXCAN_FIFO_WARNING_INT_MASK_U32)) \
                        { \
                            REG_WRITE32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET), (uint32)((can_status & FLEXCAN_FIFO_WARNING_INT_MASK_U32) & FLEXCAN_IFLAG1_CONFIG_MASK_U32));\
                            if ((NULL_PTR != Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoWarningNotification) && (FLEXCAN_FIFO_WARNING_INT_MASK_U32 == (can_mask  & FLEXCAN_FIFO_WARNING_INT_MASK_U32))){ \
                                    Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoWarningNotification(); \
                            } \
                        } \
                    } \
                    EXIT_INTERRUPT(); \
            }
    #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_ON) */
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

#if (CAN_RXFIFO_ENABLE == STD_ON)
    #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
        /**
        * @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
        * @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
        * @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
        * @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
        */
        /**
        * @brief          Interrupt routine for Rx fifo Suppport.
        * @details        Interrupt routine for Rx fifo Suppport.  Defined as macro.
        *                 The controller ID is transmitted with the ## operator for the interrupt handler.
        * @remarks        FC - Can hardware channel: A, B, C, D, E, F, G, H
        * @implements     Can_Isr_X_Activity
        *
        */
        #define CAN_RXFIFO_EVENTS_MB_MIX(FC,IdMax) \
            ISR(Can_IsrFC##FC##_RxFifoEventsMbMix) { \
                    VAR(uint32, AUTOMATIC)   can_status = 0U; \
                    VAR(uint8, AUTOMATIC)  u8RegCount = 0U; \
                    if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
                    { \
                        do \
                        { \
                            can_status = REG_READ32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag); \
                            REG_WRITE32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag, can_status); \
                            u8RegCount++; \
                        } \
                        while(u8RegCount < (uint8)((uint8)CAN_MAXMB_SUPPORTED >> FLEXCAN_MB_SHIFT5BIT_U8)); \
                    } \
                    else \
                    { \
                        if (((uint32)0U != (CAN_CONTROLLERCONFIG_TXINT_EN_U32 & (Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u32Options)))) \
                        { \
                            if ( (Can_ControllerStatuses[CAN_FC##FC##_INDEX].u8FirstTxMBIndex ) <= (uint8)(IdMax) ) \
                            { \
                                Can_IPW_ProcessTx( CAN_FC##FC##_INDEX, \
                                   Can_ControllerStatuses[CAN_FC##FC##_INDEX].u8FirstTxMBIndex, \
                                   ((Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u8MaxMBCount - (uint8)1U) < ((uint8)(IdMax))) ? (Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u8MaxMBCount - (uint8)1U) : (IdMax)); \
                            } \
                        } \
                        if (((uint32)0U != (CAN_CONTROLLERCONFIG_RXINT_EN_U32 & (Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u32Options)))) \
                        { \
                            Can_IPW_ProcessRx( CAN_FC##FC##_INDEX, \
                                               FLEXCAN_FIFOFRAME_INT_INDEX_U8, \
                                            ((Can_ControllerStatuses[CAN_FC##FC##_INDEX].u8FirstTxMBIndex - (uint8)1U) < ((uint8)(IdMax)) ) ? (Can_ControllerStatuses[CAN_FC##FC##_INDEX].u8FirstTxMBIndex - (uint8)1U) : (IdMax)); \
                        } \
                    } \
                    EXIT_INTERRUPT(); \
                  }
    #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_ON) */
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

/*==================================================================================================*/

#if (CAN_RXFIFO_ENABLE == STD_ON)
    #if (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF)

        /**
        * @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
        * @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
        * @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
        * @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
        */
        /**
        * @brief          Interrupt routine for Rx fifo Overflow.
        * @details        Interrupt routine for Rx fifo Overflow.  Defined as macro.
        *                 The controller ID is transmitted with the ## operator for the interrupt handler.
        * @remarks        FC - Can hardware channel: A, B, C, D, E, F, G, H
        * @implements     Can_Isr_X_Activity
        */
        #define CAN_MB_RXOVER(FC) \
            ISR(Can_IsrFC##FC##_Overf) { \
                VAR(uint32, AUTOMATIC)   can_status = 0U; \
                VAR(uint32, AUTOMATIC)   can_mask = 0U; \
                if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
                { \
                    REG_WRITE32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET), (uint32)(FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32 & FLEXCAN_IFLAG1_CONFIG_MASK_U32)); \
                } \
                else \
                { \
                    can_status = ((uint32)REG_READ32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32); \
                    if (FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32 == (can_status & FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32)) \
                    { \
                        REG_WRITE32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET), (uint32)((can_status & FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32) & FLEXCAN_IFLAG1_CONFIG_MASK_U32)); \
                        can_mask   = ((uint32)REG_READ32( FLEXCAN_IMASK1(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32); \
                        if ((NULL_PTR != Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoOverflowNotification) && (FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32 == (can_mask & FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32))) { \
                            Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoOverflowNotification(); \
                        } \
                    } \
                } \
                EXIT_INTERRUPT(); \
            }
    #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

#if (CAN_RXFIFO_ENABLE == STD_ON)
    #if (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF)
        /**
        * @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
        * @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
        * @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
        * @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
        */
        /**
        * @brief          Interrupt routine for Rx fifo Overflow.
        * @details        Interrupt routine for Rx fifo Overflow.  Defined as macro.
        *                 The controller ID is transmitted with the ## operator for the interrupt handler.
        * @remarks        FC - Can hardware channel: A, B, C, D, E, F, G, H
        * @implements     Can_Isr_X_Activity
        */
        #define CAN_MB_RXOVER_MB_MIX(FC) \
            ISR(Can_IsrFC##FC##_OverfMbMix) { \
                VAR(uint32, AUTOMATIC)   can_status = 0U; \
                VAR(uint32, AUTOMATIC)   can_mask = 0U; \
                if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
                { \
                    REG_WRITE32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET), (uint32)(FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32 & FLEXCAN_IFLAG1_CONFIG_MASK_U32));\
                } \
                else \
                { \
                    can_status = ((uint32)REG_READ32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32); \
                    if (FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32 == (can_status & FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32)) \
                    { \
                        REG_WRITE32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET), (uint32)((can_status & FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32) & FLEXCAN_IFLAG1_CONFIG_MASK_U32));\
                        can_mask   = ((uint32)REG_READ32( FLEXCAN_IMASK1(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32); \
                        if ((NULL_PTR != Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoOverflowNotification) && (FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32 == (can_mask & FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32))) { \
                            Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoOverflowNotification(); \
                        } \
                    } \
                    else\
                    { \
                        if (0U < Can_ControllerStatuses[CAN_FC##FC##_INDEX].u8FirstTxMBIndex) \
                        { \
                            /* Rx: process from 0 to (FirstTx-1) */ \
                            Can_IPW_ProcessRx( CAN_FC##FC##_INDEX, (uint8)8U, (uint8)15U) ; \
                        } \
                        /* Tx: process from FirstTx to (MaxMB-1) */ \
                        Can_IPW_ProcessTx( CAN_FC##FC##_INDEX, (uint8)8U, (uint8)15U); \
                    } \
                } \
                EXIT_INTERRUPT(); \
            }
    #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */


/*==================================================================================================*/


#if (CAN_RXFIFO_ENABLE == STD_ON)
    #if (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF)
        /**
        * @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
        * @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
        * @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
        * @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
        */
        /**
        * @brief          Interrupt routine for Rx fifo Warning.
        * @details        Interrupt routine for Rx fifo Warning.  Defined as macro.
        *                 The controller ID is transmitted with the ## operator for the interrupt handler.
        * @remarks        FC - Can hardware channel: A, B, C, D, E, F, G, H
        * @implements     Can_Isr_X_Activity
        */
        #define CAN_MB_RXWARN(FC) \
            ISR(Can_IsrFC##FC##_Warn) { \
                VAR(uint32, AUTOMATIC)   can_status = 0U; \
                VAR(uint32, AUTOMATIC)   can_mask = 0U; \
                if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
                { \
                    REG_WRITE32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET), (uint32)(FLEXCAN_FIFO_WARNING_INT_MASK_U32 & FLEXCAN_IFLAG1_CONFIG_MASK_U32));\
                } \
                else \
                { \
                    can_status = ((uint32)REG_READ32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_FIFO_WARNING_INT_MASK_U32); \
                    if ( FLEXCAN_FIFO_WARNING_INT_MASK_U32== (can_status & FLEXCAN_FIFO_WARNING_INT_MASK_U32)) \
                    { \
                        REG_WRITE32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET), (uint32)((can_status & FLEXCAN_FIFO_WARNING_INT_MASK_U32) & FLEXCAN_IFLAG1_CONFIG_MASK_U32));\
                        can_mask   = ((uint32)REG_READ32( FLEXCAN_IMASK1(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_FIFO_WARNING_INT_MASK_U32); \
                        if ((NULL_PTR != Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoWarningNotification) && (FLEXCAN_FIFO_WARNING_INT_MASK_U32 == (can_mask  & FLEXCAN_FIFO_WARNING_INT_MASK_U32))){ \
                            Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoWarningNotification(); \
                        } \
                    } \
                } \
                EXIT_INTERRUPT(); \
            }
    #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */


#if (CAN_RXFIFO_ENABLE == STD_ON)
    #if (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF)
        /**
        * @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
        * @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
        * @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
        * @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
        */
        /**
        * @brief          Interrupt routine for Rx fifo Warning.
        * @details        Interrupt routine for Rx fifo Warning.  Defined as macro.
        *                 The controller ID is transmitted with the ## operator for the interrupt handler.
        * @remarks        FC - Can hardware channel: A, B, C, D, E, F, G, H
        * @implements     Can_Isr_X_Activity
        */
        #define CAN_MB_RXWARN_MB_MIX(FC) \
            ISR(Can_IsrFC##FC##_WarnMbMix) { \
                VAR(uint32, AUTOMATIC)   can_status = 0U; \
                VAR(uint32, AUTOMATIC)   can_mask = 0U; \
                if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
                { \
                    REG_WRITE32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET), (uint32)(FLEXCAN_FIFO_WARNING_INT_MASK_U32 & FLEXCAN_IFLAG1_CONFIG_MASK_U32));\
                } \
                else \
                { \
                    can_status = ((uint32)REG_READ32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_FIFO_WARNING_INT_MASK_U32); \
                    if ( FLEXCAN_FIFO_WARNING_INT_MASK_U32== (can_status & FLEXCAN_FIFO_WARNING_INT_MASK_U32)) \
                    { \
                        REG_WRITE32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET), (uint32)((can_status & FLEXCAN_FIFO_WARNING_INT_MASK_U32) & FLEXCAN_IFLAG1_CONFIG_MASK_U32));\
                        can_mask   = ((uint32)REG_READ32( FLEXCAN_IMASK1(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_FIFO_WARNING_INT_MASK_U32); \
                        if ((NULL_PTR != Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoWarningNotification) && (FLEXCAN_FIFO_WARNING_INT_MASK_U32 == (can_mask  & FLEXCAN_FIFO_WARNING_INT_MASK_U32))){ \
                            Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoWarningNotification(); \
                        } \
                    } \
                    else\
                    { \
                        if (0U < Can_ControllerStatuses[CAN_FC##FC##_INDEX].u8FirstTxMBIndex) \
                        { \
                            Can_IPW_ProcessRx( CAN_FC##FC##_INDEX, (uint8)8U, (uint8)15U) ; \
                        } \
                        Can_IPW_ProcessTx( CAN_FC##FC##_INDEX, (uint8)8U, (uint8)15U); \
                    } \
                } \
                EXIT_INTERRUPT(); \
            }
    #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
/*==================================================================================================*/

#if (CAN_RXFIFO_ENABLE == STD_ON)
    #if (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF)
        /**
        * @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
        * @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
        * @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
        * @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
        */
        /**
        * @brief          Interrupt routine for Rx fifo Frame Available.
        * @details        Interrupt routine for Rx fifo Frame Available.  Defined as macro.
        *                 The controller ID is transmitted with the ## operator for the interrupt handler.
        * @remarks        FC - Can hardware channel: A, B, C, D, E, F, G ,H
        * @implements     Can_Isr_X_Activity
        */
        #define CAN_MB_FRAV(FC) \
            ISR(Can_IsrFC##FC##_FrameAv) { \
                VAR(uint32, AUTOMATIC)   can_status = 0U; \
                VAR(uint32, AUTOMATIC)   can_mask = 0U; \
                if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
                { \
                    REG_WRITE32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET), (uint32)(FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32 & FLEXCAN_IFLAG1_CONFIG_MASK_U32));\
                } \
                else \
                { \
                    can_status = ((uint32)REG_READ32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32); \
                    if (FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32 == (can_status & FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32)) \
                    { \
                        can_mask = ((uint32)REG_READ32( FLEXCAN_IMASK1(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32); \
                        if (FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32 == (can_mask & FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32)){ \
                            Can_IPW_RxFifoFrameAvNotif( CAN_FC##FC##_INDEX); \
                        } \
                    else {\
                            REG_WRITE32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET), (uint32)((can_status & FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32) & FLEXCAN_IFLAG1_CONFIG_MASK_U32));\
                         } \
                    } \
                } \
                EXIT_INTERRUPT(); \
            }
    #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

#if (CAN_RXFIFO_ENABLE == STD_ON)
    #if (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF)
        /**
        * @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
        * @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
        * @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
        * @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
        */
        /**
        * @brief          Interrupt routine for Rx fifo Frame Available.
        * @details        Interrupt routine for Rx fifo Frame Available.  Defined as macro.
        *                 The controller ID is transmitted with the ## operator for the interrupt handler.
        * @remarks        FC - Can hardware channel: A, B, C, D, E, F, G ,H
        * @implements     Can_Isr_X_Activity
        */
        #define CAN_MB_FRAV_MB_MIX(FC) \
            ISR(Can_IsrFC##FC##_FrameAvMbMix) { \
                VAR(uint32, AUTOMATIC)   can_status = 0U; \
                VAR(uint32, AUTOMATIC)   can_mask = 0U; \
                if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
                { \
                    REG_WRITE32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET), (uint32)(FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32 & FLEXCAN_IFLAG1_CONFIG_MASK_U32));\
                } \
                else \
                { \
                    can_status = ((uint32)REG_READ32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32); \
                    if (FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32 == (can_status & FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32)) \
                    { \
                        can_mask = ((uint32)REG_READ32( FLEXCAN_IMASK1(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32); \
                        if (FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32 == (can_mask & FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32)){ \
                            Can_IPW_RxFifoFrameAvNotif( CAN_FC##FC##_INDEX); \
                        } \
                        else {\
                            REG_WRITE32( FLEXCAN_IFLAG1(FLEXCAN_##FC##_OFFSET), (uint32)((can_status & FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32) & FLEXCAN_IFLAG1_CONFIG_MASK_U32));\
                         } \
                    } \
                     else\
                    { \
                        if (0U < Can_ControllerStatuses[CAN_FC##FC##_INDEX].u8FirstTxMBIndex) \
                        { \
                            /* Rx: process from 0 to (FirstTx-1) */ \
                            Can_IPW_ProcessRx( CAN_FC##FC##_INDEX, (uint8)8U, (uint8)15U) ; \
                        } \
                        /* Tx: process from FirstTx to (MaxMB-1) */ \
                        Can_IPW_ProcessTx( CAN_FC##FC##_INDEX, (uint8)8U, (uint8)15U); \
                    } \
                } \
                EXIT_INTERRUPT(); \
            }
    #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

/*==================================================================================================*/

#if (CAN_ISROPTCODESIZE == STD_ON)
    /**
    * @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
    * @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
    * @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
    * @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
    */
    /**
    * @brief          Interrupt routine for all MBs  - optimization code size.
    * @details        Process all MBs defined for current controller. MBs are grouped: HRHs first, the HTHs.
    *                 The controller ID is transmitted with the ## operator for the interrupt handler.
    * @remarks        FC - Can hardware channel: A, B, C, D, E, F, G, H
    * @implements     Can_Isr_X_Activity
    */
    #define CAN_MB_UNIISRS(FC) \
        ISR(Can_IsrFC##FC##_UNI) { \
            VAR(uint8, AUTOMATIC)  u8RegCount = 0U; \
            VAR(uint32, AUTOMATIC)   can_status = 0U; \
            if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
            { \
                do \
                { \
                    can_status = REG_READ32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag); \
                    REG_WRITE32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag, can_status); \
                    u8RegCount++; \
                } \
                while(u8RegCount < (uint8)((uint8)CAN_MAXMB_SUPPORTED >> FLEXCAN_MB_SHIFT5BIT_U8)); \
            } \
            else \
            { \
                if (((uint32)0U != (CAN_CONTROLLERCONFIG_TXINT_EN_U32 & (Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u32Options)))) \
                { \
                    Can_IPW_ProcessTx(CAN_FC##FC##_INDEX, (uint8)0U, (uint8)(Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u8MaxMBCount - (uint8)1U)); \
                } \
                if (((uint32)0U != (CAN_CONTROLLERCONFIG_RXINT_EN_U32 & (Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u32Options)))) \
                { \
                    Can_IPW_ProcessRx(CAN_FC##FC##_INDEX, (uint8)0U, (uint8)(Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u8MaxMBCount - (uint8)1U)); \
                } \
            } \
            EXIT_INTERRUPT(); \
        }
#endif /* (CAN_ISROPTCODESIZE == STD_ON) */


/*==================================================================================================*/

#if (CAN_ISROPTCODESIZE == STD_ON)
    /**
    * @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
    * @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
    * @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
    * @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
    */
    /**
    * @brief          Interrupt routine for all MBs  - optimization code size, TX only.
    * @details        Process all MBs that are configured for Tx.
    *                 The controller ID is transmitted with the ## operator for the interrupt handler.
    * @remarks        FC - Can hardware channel: A, B, C, D, E, F, G, H
    * @implements     Can_Isr_X_Activity
    */
    #define CAN_MB_UNITXISRS(FC) \
        ISR(Can_IsrFC##FC##_UNI) { \
            VAR(uint8, CAN_VAR)  u8RegCount = 0U; \
            VAR(uint32, CAN_VAR) can_status = 0U; \
            if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
            { \
                do \
                { \
                    can_status = REG_READ32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag); \
                    REG_WRITE32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag, can_status); \
                    u8RegCount++; \
                } \
                while(u8RegCount < (uint8)((uint8)CAN_MAXMB_SUPPORTED >> FLEXCAN_MB_SHIFT5BIT_U8)); \
            } \
            else \
            { \
                /* Tx: process all Tx MBs */ \
                Can_IPW_ProcessTx( CAN_FC##FC##_INDEX, (uint8)0U, (uint8)(Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u8MaxMBCount - (uint8)1U) ); \
            } \
            EXIT_INTERRUPT(); \
        }
#endif /* (CAN_ISROPTCODESIZE == STD_ON) */


/*==================================================================================================*/

#if (CAN_ISROPTCODESIZE == STD_ON)
    /**
    * @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
    * @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
    * @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
    * @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
    */
    /**
    * @brief          Interrupt routine for all MBs  - optimization code size, RX only.
    * @details        Process all MBs that are configured for Rx.
    *                 The controller ID is transmitted with the ## operator for the interrupt handler.
    * @remarks        FC - Can hardware channel: A, B, C, D, E, F, G, H
    * @implements     Can_Isr_X_Activity
    */
    #define CAN_MB_UNIRXISRS(FC) \
        ISR(Can_IsrFC##FC##_UNI) { \
            VAR(uint8, CAN_VAR)  u8RegCount = 0U; \
            VAR(uint32, CAN_VAR) can_status = 0U; \
            if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
            { \
                do \
                { \
                    can_status = REG_READ32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag); \
                    REG_WRITE32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag, can_status); \
                    u8RegCount++; \
                } \
                while(u8RegCount < (uint8)((uint8)CAN_MAXMB_SUPPORTED >> FLEXCAN_MB_SHIFT5BIT_U8)); \
            } \
            else \
            { \
                Can_IPW_ProcessRx( CAN_FC##FC##_INDEX, (uint8)0U, (uint8)(Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u8MaxMBCount - (uint8)1U) ); \
            } \
            EXIT_INTERRUPT(); \
        }
#endif /* (CAN_ISROPTCODESIZE == STD_ON) */


/*==================================================================================================*/


#if (CAN_ISROPTCODESIZE == STD_OFF)
    /**
    * @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
    * @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
    * @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
    * @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
    */
    /**
    @brief      Interrupt routine for a range of MBs. ( for MBs from 0 to 63).
    * @details        Process all MBs defined for current controller, but between a definite range.
    *                 MBs are grouped: HRHs first, the HTHs.
    * @remarks        FC - Can hardware channel: A, B, C, D, E, F, G, H
    *                 Name - Suggestive name for the Int purpose.
    *                 IdMin, IdMax - minimum/maximum MB id that interrupt is related for.
    * @implements     Can_Isr_X_Activity
    */
    #define CAN_MB_ISRS(FC, Name, IdMin, IdMax) \
        ISR(Can_IsrFC##FC##_##Name) { \
            VAR(uint8, CAN_VAR)  u8RegCount = 0U; \
            VAR(uint32, CAN_VAR) can_status = 0U; \
            if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
            { \
                do \
                { \
                    can_status = REG_READ32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag); \
                    REG_WRITE32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag, can_status); \
                    u8RegCount++; \
                } \
                while(u8RegCount < (uint8)((uint8)CAN_MAXMB_SUPPORTED >> FLEXCAN_MB_SHIFT5BIT_U8)); \
            } \
            else \
            { \
                if ( (Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u8MaxMBCount - (uint8)1U) < (IdMax) ) { \
                    if (((uint32)0U != (CAN_CONTROLLERCONFIG_TXINT_EN_U32 & (Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u32Options)))) \
                    { \
                        Can_IPW_ProcessTx(CAN_FC##FC##_INDEX, (IdMin), (uint8)(Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u8MaxMBCount - (uint8)1U)); \
                    } \
                    if (((uint32)0U != (CAN_CONTROLLERCONFIG_RXINT_EN_U32 & (Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u32Options)))) \
                    { \
                        Can_IPW_ProcessRx(CAN_FC##FC##_INDEX, (IdMin), (uint8)(Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u8MaxMBCount - (uint8)1U)); \
                    } \
                } else { \
                    if (((uint32)0U != (CAN_CONTROLLERCONFIG_TXINT_EN_U32 & (Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u32Options)))) \
                    { \
                        Can_IPW_ProcessTx(CAN_FC##FC##_INDEX, (IdMin), (IdMax)); \
                    } \
                    if (((uint32)0U != (CAN_CONTROLLERCONFIG_RXINT_EN_U32 & (Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u32Options)))) \
                    { \
                        Can_IPW_ProcessRx(CAN_FC##FC##_INDEX, (IdMin), (IdMax)); \
                    } \
                } \
            } \
            EXIT_INTERRUPT(); \
        }
#endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

/*==================================================================================================*/

#if (CAN_ISROPTCODESIZE == STD_OFF)
    /**
    * @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
    * @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
    * @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
    * @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
    */
    /**
    @brief      Interrupt routine for a range of MBs - TX only ( for MBs from 0 to 63).
    * @details        Process all MBs that are configured for Tx, but between a definite range.
    * @remarks        FC - Can hardware channel: A, B, C, D, E, F, G, H
    *                 Name - Suggestive name for the Int purpose.
    *                 IdMin, IdMax - minimum/maximum MB id that interrupt is related for.
    * @implements     Can_Isr_X_Activity
    */
    #define CAN_MB_TXISRS(FC, Name, IdMin, IdMax) \
        ISR(Can_IsrFC##FC##_##Name) { \
            VAR(uint8, CAN_VAR)  u8RegCount = 0U; \
            VAR(uint32, CAN_VAR) can_status = 0U; \
            if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
            { \
                do \
                { \
                    can_status = REG_READ32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag); \
                    REG_WRITE32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag, can_status); \
                    u8RegCount++; \
                } \
                while(u8RegCount < (uint8)((uint8)CAN_MAXMB_SUPPORTED >> FLEXCAN_MB_SHIFT5BIT_U8)); \
            } \
            else \
            { \
                if ( (Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u8MaxMBCount - (uint8)1U) < (IdMax) ) { \
                    Can_IPW_ProcessTx(CAN_FC##FC##_INDEX, (IdMin), (Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u8MaxMBCount - (uint8)1U)); \
                } else { \
                    Can_IPW_ProcessTx(CAN_FC##FC##_INDEX, (IdMin), (IdMax)); \
                } \
            } \
            EXIT_INTERRUPT(); \
        }
#endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

/*==================================================================================================*/

#if (CAN_ISROPTCODESIZE == STD_OFF)
    /**
    * @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
    * @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
    * @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
    * @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
    */
    /**
    * @brief          Interrupt routine for a range of MBs - RX only ( for MBs from 8 to 31).
    * @details        Process all MBs that are configured for Tx, but between a definite range.
    * @remarks        FC - Can hardware channel: A, B, C, D, E, F, G, H
    *                 Name - Suggestive name for the Int purpose.
    *                 IdMin, IdMax - minimum/maximum MB id that interrupt is related for.
    * @implements     Can_Isr_X_Activity
    */
    #define CAN_MB_RXISRS(FC, Name, IdMin, IdMax) \
        ISR(Can_IsrFC##FC##_##Name) { \
            VAR(uint8, CAN_VAR)  u8RegCount = 0U; \
            VAR(uint32, CAN_VAR) can_status = 0U; \
            if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
            { \
                do \
                { \
                    can_status = REG_READ32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag); \
                    REG_WRITE32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag, can_status); \
                    u8RegCount++; \
                } \
                while(u8RegCount < (uint8)((uint8)CAN_MAXMB_SUPPORTED >> FLEXCAN_MB_SHIFT5BIT_U8)); \
            } \
            else \
            { \
                if ( (Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u8MaxMBCount - (uint8)1U) < (IdMax) ) { \
                    Can_IPW_ProcessRx(CAN_FC##FC##_INDEX, (IdMin), (Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u8MaxMBCount - (uint8)1U)); \
                } else { \
                    Can_IPW_ProcessRx(CAN_FC##FC##_INDEX, (IdMin), (IdMax)); \
                } \
            } \
            EXIT_INTERRUPT(); \
        }
#endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

/*==================================================================================================*/

/**
* @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
* @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
* @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
* @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
*/
/**
* @brief          Interrupt routine for BusOff and Error.
* @details        Interrupt routine for BusOff and Error.
* @remarks        FC - Can hardware channel: A, B, C, D, E, F, G, H
* @implements     Can_Isr_X_Activity
*/
#define CAN_BOERRISR(FC) \
    ISR(Can_IsrFC##FC##_BOERR) \
    { \
        if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
        { \
            REG_WRITE32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET), (uint32)(FLEXCAN_ESR_BOFFINT_U32 & FLEXCAN_ESR_CONFIG_MASK_U32));\
            REG_WRITE32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET), (uint32)(FLEXCAN_ESR_ERRINT_U32 & FLEXCAN_ESR_CONFIG_MASK_U32));\
        } \
        else \
        { \
            if (0U != ((uint32)REG_READ32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_ESR_BOFFINT_U32)) \
            { \
                if ( 0U != ((uint32)REG_READ32( FLEXCAN_CTRL(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_CTRL_BOFFMSK_U32) ) \
                { \
                    /* Process BusOff condition for controller ID of FlexCAN FC */ \
                    if ( E_OK == (Std_ReturnType)Can_IPW_SetControllerMode( CAN_FC##FC##_INDEX,  &(Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX]), CAN_CS_STOPPED,(boolean)FALSE) ) \
                    { \
                        Can_IPW_ProcessBusOff(CAN_FC##FC##_INDEX); \
                        CanIf_ControllerBusOff(CAN_FC##FC##_INDEX); \
                    } \
                } \
                else \
                { \
                    /* Clear the ESR[BOFF_INT] bus off interrupt flag (w1c). */ \
                    REG_WRITE32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET), (FLEXCAN_ESR_BOFFINT_U32 & FLEXCAN_ESR_CONFIG_MASK_U32));\
                } \
            } \
            if (0U != ((uint32)REG_READ32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_ESR_ERRINT_U32)) \
            { \
                if (0U != ((uint32)REG_READ32( FLEXCAN_CTRL(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_CTRL_ERRMSK_U32)) \
                { \
                    if ( NULL_PTR != CanStatic_pCurrentConfig->StaticControlerDescriptors[CAN_FC##FC##_INDEX].Can_ErrorNotification) \
                    { \
                        CanStatic_pCurrentConfig->StaticControlerDescriptors[CAN_FC##FC##_INDEX].Can_ErrorNotification(); \
                    } \
                } \
            } \
            REG_WRITE32( FLEXCAN_ESR(CanStatic_pCurrentConfig->StaticControlerDescriptors[CAN_FC##FC##_INDEX].u8ControllerOffset), (FLEXCAN_ESR_ERRINT_U32 & FLEXCAN_ESR_CONFIG_MASK_U32));\
        } \
        EXIT_INTERRUPT(); \
    }

/*==================================================================================================*/

/**
* @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
* @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
* @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
* @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
*/
/**
* @brief          Interrupt routine for BusOff.
* @details        Interrupt routine for BusOff.
* @remarks        FC - Can hardware channel: A, B, C, D, E, F, G, H
* @implements     Can_Isr_X_Activity
*/
#define CAN_BOISR(FC) \
    ISR(Can_IsrFC##FC##_BO) { \
        VAR(uint32, AUTOMATIC) can_status = 0U; \
        VAR(uint32, AUTOMATIC) can_mask = 0U; \
        if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
        { \
            REG_WRITE32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET), (uint32)(FLEXCAN_ESR_BOFFINT_U32 & FLEXCAN_ESR_CONFIG_MASK_U32));\
        } \
        else \
        { \
            can_mask = (uint32)REG_READ32( FLEXCAN_CTRL(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_CTRL_BOFFMSK_U32; \
            can_status = ((uint32)REG_READ32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_ESR_BOFFINT_U32); \
            if (0U != can_status) \
            { \
                if(0U != can_mask) \
                { \
                    /* Process BusOff condition for controller ID of FlexCAN FC */ \
                    if ( E_OK == (Std_ReturnType)Can_IPW_SetControllerMode( CAN_FC##FC##_INDEX,  &(Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX]), CAN_CS_STOPPED,(boolean)FALSE) ) \
                                { \
                                Can_IPW_ProcessBusOff(CAN_FC##FC##_INDEX); \
                                CanIf_ControllerBusOff(CAN_FC##FC##_INDEX); \
                                } \
                } \
                else { \
                    /* Clear the ESR[BOFF_INT] bus off interrupt flag (w1c). */ \
                    REG_WRITE32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET), (FLEXCAN_ESR_BOFFINT_U32 & FLEXCAN_ESR_CONFIG_MASK_U32));\
                } \
            } \
        } \
        EXIT_INTERRUPT(); \
    }

/*==================================================================================================*/

#if (CAN_PUBLIC_ICOM_SUPPORT==STD_ON)
    /**
    * @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
    * @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
    * @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
    * @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
    */
    /**
    * @brief          Interrupt routine for WakeUp by PNET.
    * @details        Interrupt routine for WakeUp by PNET.
    * @remarks        FC - Can hardware channel: A
    * @implements     Can_Isr_X_Activity
    *
    */
    #define CAN_WKPPNISR(FC) \
        ISR(Can_IsrFC##FC##_PN) \
            { \
                Can_IPW_ProcessWakeupPN(CAN_FC##FC##_INDEX); \
                EXIT_INTERRUPT(); \
            }
#endif/* (CAN_PUBLIC_ICOM_SUPPORT==STD_ON) */
/*==================================================================================================*/

#if (CAN_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /**
    * @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
    * @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
    * @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
    * @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
    */
    /**
    * @brief          Interrupt routine for Error.
    * @details        Interrupt routine for Error.
    * @remarks        FC - Can hardware channel: A, B, C, D, E, F, G, H
    * @implements     Can_Isr_X_Activity
    */
    #define CAN_ERRISR(FC) \
        ISR(Can_IsrFC##FC##_ERR) { /* Error Isr */ \
        VAR(uint32, AUTOMATIC) can_status = 0U; \
        if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
        { \
            REG_WRITE32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET), (FLEXCAN_ESR_ERRINT_U32 & FLEXCAN_ESR_CONFIG_MASK_U32));\
        } \
        else \
        { \
            can_status = (uint32)REG_READ32( FLEXCAN_CTRL(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_CTRL_ERRMSK_U32; \
            can_status = can_status >> (13U); \
            can_status &= ((uint32)REG_READ32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET)) & FLEXCAN_ESR_ERRINT_U32); \
            if (0U != can_status) \
            { \
               if ( NULL_PTR != CanStatic_pCurrentConfig->StaticControlerDescriptors[CAN_FC##FC##_INDEX].Can_ErrorNotification) { \
                    CanStatic_pCurrentConfig->StaticControlerDescriptors[CAN_FC##FC##_INDEX].Can_ErrorNotification(); \
                } \
            } \
            REG_WRITE32( FLEXCAN_ESR(CanStatic_pCurrentConfig->StaticControlerDescriptors[CAN_FC##FC##_INDEX].u8ControllerOffset), (FLEXCAN_ESR_ERRINT_U32 & FLEXCAN_ESR_CONFIG_MASK_U32));\
        } \
        EXIT_INTERRUPT(); \
        }
#endif

/*ISR for ARM*/
#elif (CAN_MULTIPLE_INTERRUPTS_SUPPORT==STD_OFF)
/*==================================================================================================*/
#if (CAN_UNIFIED_INTERRUPTS == STD_ON) /*  Support interrupt for  derivatives which support UNIFIED_INTERRUPTS */
#if ((CAN_A_ERROR_NOTIFICATION_ENABLE == STD_ON) || (CAN_A_BUSOFFINT_SUPPORTED == STD_ON) || (CAN_PUBLIC_ICOM_SUPPORT == STD_ON))
/**
* @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
* @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
* @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
* @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
*/
/**
* @brief          Interrupt routine for Error.
* @details        Interrupt routine for Error.
* @remarks        FC - Can hardware channel: A
* @implements     Can_Isr_X_Activity
*/
#define Can_Isr_ID_10(FC) \
    ISR(Can_ISR_NVIC_ID_10_FC##FC##_SP)\
{ \
    VAR(uint32, CAN_VAR) can_status = 0U; \
    VAR(uint32, CAN_VAR) can_temp = 0U; \
    VAR(uint8, CAN_VAR)  u8RegCount = 0U; \
    if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)\
    { \
        Can_IPW_ProcessWakeupPN(CAN_FC##FC##_INDEX); \
    } \
    if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
    { \
        REG_WRITE32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET), FLEXCAN_ESR_BOFFINT_U32) ; \
        REG_WRITE32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET), FLEXCAN_ESR_ERRINT_U32) ; \
        for (u8RegCount=(uint8)0; u8RegCount < (uint8)((uint8)CAN_MAXMB_SUPPORTED >> FLEXCAN_MB_SHIFT5BIT_U8); u8RegCount++) \
        { \
            /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
            can_status = REG_READ32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag); \
            /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
            REG_WRITE32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag,can_status); \
        } \
        if (CAN_MEMORY_ECC_SUPPORT == STD_ON) \
        { \
            /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
            can_temp = REG_READ32( FLEXCAN_ERRSR(FLEXCAN_##FC##_OFFSET)); \
            /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
            REG_WRITE32( FLEXCAN_ERRSR(FLEXCAN_##FC##_OFFSET), can_temp); \
        } \
    } \
    else \
    { \
        /*Check for bus-off interrupt*/ \
        /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
        can_temp = (uint32)(REG_READ32( FLEXCAN_CTRL(FLEXCAN_##FC##_OFFSET))) & FLEXCAN_CTRL_BOFFMSK_U32;  \
        can_temp = can_temp >> (13U); \
        /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
        can_status = ((uint32)(REG_READ32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET))) & FLEXCAN_ESR_BOFFINT_U32); \
        can_temp &= can_status; \
        /* @violates @ref Can_Flexcan_h_REF_1 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */ \
        if ( (uint32)CAN_CONTROLLERCONFIG_BOPOL_EN_U32 != (CAN_CONTROLLERCONFIG_BOPOL_EN_U32 & (CanStatic_pControlerDescriptors[CAN_FC##FC##_INDEX].u32Options)) ) \
        { \
            if ( (uint32)0U != can_temp ) \
            { \
                /* @violates @ref Can_Flexcan_h_REF_1 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */ \
                if ( E_OK == (Std_ReturnType)Can_IPW_SetControllerMode( CAN_FC##FC##_INDEX,  &(Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX]), CAN_CS_STOPPED,(boolean)FALSE) ) \
                { \
                    /* Process BusOff condition for controller ID of FlexCAN FC */ \
                    Can_IPW_ProcessBusOff( CAN_FC##FC##_INDEX); \
                    CanIf_ControllerBusOff(CAN_FC##FC##_INDEX); \
                } \
            } \
            /* Clear the ESR[BOFF_INT] bus off interrupt flag (w1c). */ \
            /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
            /* @violates @ref Can_Flexcan_h_REF_1 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */ \
            REG_WRITE32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET), FLEXCAN_ESR_BOFFINT_U32) ; \
        } \
        /*Check for error interrupt*/ \
        /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
        can_temp = (uint32)REG_READ32(  ( (uint32)( CAN_GET_BASE_ADDRESS(FLEXCAN_##FC##_OFFSET) + 0x04U ) )) & FLEXCAN_CTRL_ERRMSK_U32; \
        can_temp = can_temp >> (13U); \
        /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
        can_status  = ((uint32)(REG_READ32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET))) & FLEXCAN_ESR_ERRINT_U32);\
        can_temp&=can_status; \
        /* @violates @ref Can_Flexcan_h_REF_1 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */ \
        if ( (uint32)CAN_CONTROLLERCONFIG_ERR_EN_U32 == (CAN_CONTROLLERCONFIG_ERR_EN_U32 & (Can_pControlerDescriptors[CAN_FC##FC##_INDEX].u32Options)) ) \
        { \
            if ( (uint32)0U != can_temp ) \
            { \
                /* @violates @ref Can_Flexcan_h_REF_1 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */ \
                if ( NULL_PTR != CanStatic_pCurrentConfig->StaticControlerDescriptors[CAN_FC##FC##_INDEX].Can_ErrorNotification) \
                { \
                    /* @violates @ref Can_Flexcan_h_REF_1 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */ \
                    CanStatic_pCurrentConfig->StaticControlerDescriptors[CAN_FC##FC##_INDEX].Can_ErrorNotification(); \
                } \
            } \
            /* Clear the ESR[ERR_INT] bus off interrupt flag (w1c). */ \
            /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
            /* @violates @ref Can_Flexcan_h_REF_1 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */ \
            REG_WRITE32( FLEXCAN_ESR(CanStatic_pCurrentConfig->StaticControlerDescriptors[CAN_FC##FC##_INDEX].u8ControllerOffset), FLEXCAN_ESR_ERRINT_U32) ; \
        } \
        /*Clear interrupt flags related to memory ECC*/ \
        if (CAN_MEMORY_ECC_SUPPORT == STD_ON) \
        { \
            /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
            can_temp = REG_READ32( FLEXCAN_ERRSR(FLEXCAN_##FC##_OFFSET)); \
            /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
            REG_WRITE32( FLEXCAN_ERRSR(FLEXCAN_##FC##_OFFSET), can_temp); \
        } \
    } \
    EXIT_INTERRUPT(); \
}
#endif
/*==================================================================================================*/
#if (((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_ON)) ||\
    ((CAN_A_TXINT_SUPPORTED == STD_OFF) && (CAN_A_RXINT_SUPPORTED == STD_ON)) ||\
    ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_OFF)))
/**
* @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
* @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
* @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
* @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
*/
/**
* @brief          Interrupt routine for MBs.
* @details        Interrupt routine for MBs.
* @remarks        FC - Can hardware channel: A
* @implements     Can_Isr_X_Activity
*/
#define Can_Isr_ID_11(FC) \
    ISR(Can_ISR_NVIC_ID_11_FC##FC##_SP) \
{ \
    VAR(uint32, AUTOMATIC)   can_status = 0U; \
    VAR(uint8, AUTOMATIC)  u8RegCount = 0U; \
    if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
    { \
        for (u8RegCount=(uint8)0; u8RegCount < (uint8)((uint8)CAN_MAXMB_SUPPORTED >> FLEXCAN_MB_SHIFT5BIT_U8); u8RegCount++) \
        { \
            can_status = REG_READ32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag); \
            REG_WRITE32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag,can_status); \
        } \
    } \
    else \
    { \
        if (((uint32)0U != (CAN_CONTROLLERCONFIG_TXINT_EN_U32 & (Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u32Options)))) \
        { \
            Can_IPW_ProcessTx( CAN_FC##FC##_INDEX, Can_ControllerStatuses[CAN_FC##FC##_INDEX].u8FirstTxMBIndex, (Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u8MaxMBCount - (uint8)1U)); \
        } \
        if (((uint32)0U != (CAN_CONTROLLERCONFIG_RXINT_EN_U32 & (Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u32Options)))) \
        { \
            Can_IPW_ProcessRx( CAN_FC##FC##_INDEX, 0U, (Can_ControllerStatuses[CAN_FC##FC##_INDEX].u8FirstTxMBIndex - (uint8)1U)); \
        } \
    } \
    EXIT_INTERRUPT(); \
}
#endif
/*==================================================================================================*/
#else
/**
* @violates @ref Can_Flexcan_h_REF_6 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
* @violates @ref Can_Flexcan_h_REF_7 Violates MISRA 2004 Required Rule 19.12, Multiple use of '# #' operators in macro definition. 
* @violates @ref Can_Flexcan_h_REF_8 Violates MISRA 2004 Advisory Rule 19.13, '# ##' operator used. 
* @violates @ref Can_Flexcan_h_REF_5 Violates MISRA 2004 Required  Rule 19.4 , The C macro expand to an Interrupt Service Routine.
*/
/**
* @brief          Interrupt routine for Error.
* @details        Interrupt routine for Error.
* @remarks        FC - Can hardware channel: A, B, C, D, E, F, G, H
* @implements     Can_Isr_X_Activity
*/
#define Can_Isr(FC) \
    ISR(Can_ISR_##FC) \
    { \
        VAR(uint32, CAN_VAR) can_status = 0U; \
        VAR(uint32, CAN_VAR) can_temp = 0U; \
        VAR(uint8, CAN_VAR)  u8RegCount = 0U; \
        if ( CAN_CS_STARTED != Can_ControllerStatuses[CAN_FC##FC##_INDEX].ControllerState ) \
        { \
            REG_WRITE32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET), FLEXCAN_ESR_BOFFINT_U32) ; \
            REG_WRITE32( FLEXCAN_ESR(CanStatic_pCurrentConfig->StaticControlerDescriptors[CAN_FC##FC##_INDEX].u8ControllerOffset), FLEXCAN_ESR_ERRINT_U32) ; \
            for (u8RegCount=(uint8)0; u8RegCount < (uint8)((uint8)CAN_MAXMB_SUPPORTED >> FLEXCAN_MB_SHIFT5BIT_U8); u8RegCount++) \
            { \
                /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
                can_status = REG_READ32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag); \
                /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
                REG_WRITE32(Can_IflagImask[u8RegCount][FLEXCAN_##FC##_OFFSET].u32CanIflag,can_status); \
            } \
            if (CAN_MEMORY_ECC_SUPPORT == STD_ON) \
            { \
                /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
                can_temp = REG_READ32( FLEXCAN_ERRSR(FLEXCAN_##FC##_OFFSET)); \
                /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
                REG_WRITE32( FLEXCAN_ERRSR(FLEXCAN_##FC##_OFFSET), can_temp); \
            } \
        } \
        else \
        { \
            /*Check for bus-off interrupt*/ \
            /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
            can_temp = (uint32)(REG_READ32( FLEXCAN_CTRL(FLEXCAN_##FC##_OFFSET))) & FLEXCAN_CTRL_BOFFMSK_U32;  \
            can_temp = can_temp >> (13U); \
            /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
            can_status = ((uint32)(REG_READ32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET))) & FLEXCAN_ESR_BOFFINT_U32); \
            can_temp &= can_status; \
            /* @violates @ref Can_Flexcan_h_REF_1 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */ \
            if ( (uint32)CAN_CONTROLLERCONFIG_BOPOL_EN_U32 != (CAN_CONTROLLERCONFIG_BOPOL_EN_U32 & (CanStatic_pControlerDescriptors[CAN_FC##FC##_INDEX].u32Options)) ) \
            { \
                if ( (uint32)0U != can_temp ) \
                { \
                    /* @violates @ref Can_Flexcan_h_REF_1 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */ \
                    if ( E_OK == (Std_ReturnType)Can_IPW_SetControllerMode( CAN_FC##FC##_INDEX,  &(Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX]), CAN_T_STOP,(boolean)FALSE) ) \
                    { \
                        /* Process BusOff condition for controller ID of FlexCAN FC */ \
                        Can_IPW_ProcessBusOff( CAN_FC##FC##_INDEX); \
                        CanIf_ControllerBusOff(CAN_FC##FC##_INDEX); \
                    } \
                } \
                /* Clear the ESR[BOFF_INT] bus off interrupt flag (w1c). */ \
                /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
                /* @violates @ref Can_Flexcan_h_REF_1 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */ \
                REG_WRITE32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET), FLEXCAN_ESR_BOFFINT_U32) ; \
            } \
            /*Check for error interrupt*/ \
            /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
            can_temp = (uint32)REG_READ32(  ( (uint32)( CAN_GET_BASE_ADDRESS(FLEXCAN_##FC##_OFFSET) + 0x04U ) )) & FLEXCAN_CTRL_ERRMSK_U32; \
            can_temp = can_temp >> (13U); \
            /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
            can_status  = ((uint32)(REG_READ32( FLEXCAN_ESR(FLEXCAN_##FC##_OFFSET))) & FLEXCAN_ESR_ERRINT_U32);\
            can_temp&=can_status; \
            /* @violates @ref Can_Flexcan_h_REF_1 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */ \
            if ( (uint32)CAN_CONTROLLERCONFIG_ERR_EN_U32 == (CAN_CONTROLLERCONFIG_ERR_EN_U32 & (Can_pControlerDescriptors[CAN_FC##FC##_INDEX].u32Options)) ) \
            { \
                if ( (uint32)0U != can_temp ) \
                { \
                    /* @violates @ref Can_Flexcan_h_REF_1 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */ \
                    if ( NULL_PTR != CanStatic_pCurrentConfig->StaticControlerDescriptors[CAN_FC##FC##_INDEX].Can_ErrorNotification) \
                    { \
                        /* @violates @ref Can_Flexcan_h_REF_1 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */ \
                        CanStatic_pCurrentConfig->StaticControlerDescriptors[CAN_FC##FC##_INDEX].Can_ErrorNotification(); \
                    } \
                } \
                /* Clear the ESR[ERR_INT] bus off interrupt flag (w1c). */ \
                /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
                /* @violates @ref Can_Flexcan_h_REF_1 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */ \
                REG_WRITE32( FLEXCAN_ESR(CanStatic_pCurrentConfig->StaticControlerDescriptors[CAN_FC##FC##_INDEX].u8ControllerOffset), FLEXCAN_ESR_ERRINT_U32) ; \
            } \
            /*Check for interrupts generated by MB or Rxfifo*/ \
            /* Tx: process from FirstTx to (MaxMB-1) */ \
            /* @violates @ref Can_Flexcan_h_REF_1 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */ \
                /* @violates @ref Can_Flexcan_h_REF_1 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */ \
                Can_IPW_ProcessTx( CAN_FC##FC##_INDEX, (uint8)0U, (uint8)(Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u8MaxMBCount - (uint8)1U) ); \
            /* Rx: process from 0 to (FirstTx-1) */ \
            /* @violates @ref Can_Flexcan_h_REF_1 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */ \
                Can_IPW_ProcessRx( CAN_FC##FC##_INDEX, (uint8)0U, (uint8)(Can_pCurrentConfig->ControlerDescriptors[CAN_FC##FC##_INDEX].u8MaxMBCount - (uint8)1U) ); \
            /*Clear interrupt flags related to memory ECC*/ \
            if (CAN_MEMORY_ECC_SUPPORT == STD_ON) \
            { \
                /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
                can_temp = REG_READ32( FLEXCAN_ERRSR(FLEXCAN_##FC##_OFFSET)); \
                /* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ \
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */ \
                REG_WRITE32( FLEXCAN_ERRSR(FLEXCAN_##FC##_OFFSET), can_temp); \
            } \
        } \
        EXIT_INTERRUPT(); \
    }
#endif
#endif
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_START_SEC_CODE
/*
* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == CAN_ENABLE_USER_MODE_SUPPORT)
    #ifdef CAN_FLEXCAN_REG_PROT_AVAILABLE
        FUNC(void, CAN_CODE) Can_FlexCan_SetUserAccessAllowed(void);
    #endif
#endif
#endif

FUNC (void, CAN_CODE) Can_FlexCan_InitVariables( void);

FUNC (Std_ReturnType, CAN_CODE) Can_FlexCan_InitController( VAR(uint8, AUTOMATIC) Controller);

FUNC (void, CAN_CODE) Can_FlexCan_DeInitController( VAR(uint8, AUTOMATIC) Controller);

FUNC (Can_ErrorStateType, CAN_CODE) Can_FlexCan_GetControllerErrorState( VAR(uint8, AUTOMATIC) Controller);
FUNC (Std_ReturnType, CAN_CODE) Can_FlexCan_SetControllerMode( VAR(uint8, AUTOMATIC) Controller,
                                                           P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanControlerDescriptor,
                                                           Can_ControllerStateType Transition,
                                                           VAR(boolean, AUTOMATIC) canif_notification_required);


FUNC (void, CAN_CODE) Can_FlexCan_DisableControllerInterrupts( VAR(uint8, AUTOMATIC) Controller);


FUNC (void, CAN_CODE) Can_FlexCan_EnableControllerInterrupts( VAR(uint8, AUTOMATIC) Controller,
                                                          P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanControlerDescriptor);

#if (CAN_API_ENABLE_ABORT_MB == STD_ON)
FUNC (void, CAN_CODE) Can_FlexCan_Cancel( VAR(uint8, AUTOMATIC) controller,
                                          VAR(uint16, AUTOMATIC) u16MBGlobalIndex );
#endif /* (CAN_API_ENABLE_ABORT_MB == STD_ON) */

#if (CAN_API_ENABLE_ABORT_MB == STD_ON)
FUNC(void, CAN_CODE) Can_FlexCan_AbortMb( VAR(Can_HwHandleType, AUTOMATIC) Hth );

#endif

FUNC (Std_ReturnType, CAN_CODE) Can_FlexCan_Write( Can_HwHandleType Hth,
                                               P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo);

#if (CAN_TX_RX_INTR_SUPPORTED == STD_ON)
FUNC (void, CAN_CODE) Can_FlexCan_ProcessTx( CONST(uint8, AUTOMATIC) controller,
                                          CONST(uint8, AUTOMATIC) mbindex_start,
                                          CONST(uint8, AUTOMATIC) mbindex_end );


FUNC (void, CAN_CODE) Can_FlexCan_ProcessRx( CONST(uint8, AUTOMATIC) controller,
                                          CONST(uint8, AUTOMATIC) mbindex_start,
                                          CONST(uint8, AUTOMATIC) mbindex_end);
#endif /* (CAN_TX_RX_INTR_SUPPORTED == STD_ON) */

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
FUNC(Std_ReturnType, CAN_CODE) Can_FlexCan_SetIcomConfig( VAR(uint8, AUTOMATIC) u8Controller, VAR(uint8, AUTOMATIC) u8ConfigIcomIndex );
FUNC(Std_ReturnType, CAN_CODE) Can_FlexCan_DeactivateIcom( VAR(uint8, AUTOMATIC) u8Controller);
FUNC(void, CAN_CODE) Can_FlexCan_ProcessWakeupPN( CONST(uint8, AUTOMATIC) u8controller);
#endif

#if (CAN_TXPOLL_SUPPORTED == STD_ON)

FUNC (void, CAN_CODE) Can_FlexCan_MainFunctionWrite( void);

FUNC (void, CAN_CODE) Can_FlexCan_MainFunctionMultipleWritePoll( VAR(uint8, AUTOMATIC) writepoll);

#endif /* (CAN_TXPOLL_SUPPORTED == STD_ON) */

#if (CAN_RXPOLL_SUPPORTED == STD_ON)

FUNC (void, CAN_CODE) Can_FlexCan_MainFunctionRead( void);

FUNC (void, CAN_CODE) Can_FlexCan_MainFunctionMultipleReadPoll( VAR(uint8, AUTOMATIC) readpoll);

#endif /* (CAN_RXPOLL_SUPPORTED == STD_ON) */


FUNC (void, CAN_CODE) Can_FlexCan_ProcessBusOff( CONST(uint8, AUTOMATIC) controller);


FUNC (Std_ReturnType, CAN_CODE) Can_FlexCan_CheckBusOff( VAR(uint8, AUTOMATIC) controller);


FUNC (void, CAN_CODE) Can_FlexCan_MainFunctionMode( void);



#if (CAN_RXFIFO_ENABLE == STD_ON)
#if (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF)
FUNC(void, CAN_CODE) Can_FlexCan_RxFifoFrameAvNotif( CONST(uint8, AUTOMATIC) controller);
#endif
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */



#if (CAN_DUAL_CLOCK_MODE == STD_ON)

FUNC(Std_ReturnType, CAN_CODE) Can_FlexCan_SetClockMode( VAR(uint8, AUTOMATIC) u8Controller, VAR(Can_ClockModeType, AUTOMATIC) can_clk_mode);

#endif /* CAN_DUAL_CLOCK_MODE == STD_ON */

#define CAN_STOP_SEC_CODE
/*
* @violates @ref Can_Flexcan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* CAN_FLEXCAN_H */

/** @} */
