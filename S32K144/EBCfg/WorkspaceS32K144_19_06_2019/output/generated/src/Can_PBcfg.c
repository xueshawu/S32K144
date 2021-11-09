/**
*   @file    Can_PBcfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface
*   @details Configuration Structures for PostBuild.
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
*
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and 
* external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
* The used compilers use more than 31 chars for identifiers.
*
* @section Can_PBcfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,#include preceded by non preproc directives.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Can_PBcfg_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section Can_PBcfg_c_REF_5
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
* This macro compute the address of any register by using the hardware ofsset of the controller. The address calculated as an unsigned int
* is passed to  a macro for initializing the pointer with that address. (ex: see REG_WRITE32 macro).
*
* @section Can_PBcfg_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Can_PBcfg_c_REF_6
* Violates MISRA 2004 Required Rule 8.8, external object should be declared in one and only one file
*
*/

/*
   (CAN078) The code file structure shall not be defined within this specification completely.
            At this point it shall be pointed out that the code-file structure shall include the following file named: Can_PBcfg.c.
            This file shall contain all post-build time configurable parameters.
   (CAN221) VariantPB: (Mix of precompile and Post Build multiple selectable configurable configurations.
*/
/**
* @file           Can_PBcfg.c
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can.h"
#include "Can_IPW.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           Can_PBcfg.c
*/
#define CAN_VENDOR_ID_PBCFG_C                    43
#define CAN_MODULE_ID_PBCFG_C                    80
#define CAN_AR_RELEASE_MAJOR_VERSION_PBCFG_C     4
#define CAN_AR_RELEASE_MINOR_VERSION_PBCFG_C     3
#define CAN_AR_RELEASE_REVISION_VERSION_PBCFG_C  1
#define CAN_SW_MAJOR_VERSION_PBCFG_C             1
#define CAN_SW_MINOR_VERSION_PBCFG_C             0
#define CAN_SW_PATCH_VERSION_PBCFG_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Can.h header file are of the same vendor */
#if (CAN_VENDOR_ID_PBCFG_C != CAN_VENDOR_ID)
#error "Can_PBcfg.c and Can.h have different vendor ids"
#endif
/* Check if current file and Can.h header file are of the same module */
#if (CAN_MODULE_ID_PBCFG_C != CAN_MODULE_ID)
#error "Can_PBcfg.c and Can.h have different module ids"
#endif
/* Check if current file and Can.h header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_PBCFG_C != CAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_AR_RELEASE_MINOR_VERSION_PBCFG_C != CAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_AR_RELEASE_REVISION_VERSION_PBCFG_C != CAN_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Can_PBcfg.c and Can.h are different"
#endif
/* Check if current file and Can.h header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PBCFG_C != CAN_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_PBCFG_C != CAN_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_PBCFG_C != CAN_SW_PATCH_VERSION))
       #error "Software Version Numbers of Can_PBcfg.c and Can.h are different"
#endif

/* Check if current file and Can_IPW header file are of the same vendor */
#if (CAN_VENDOR_ID_PBCFG_C  != CAN_IPW_VENDOR_ID_H)
#error "Can_IPW.h and Can_PBcfg.c have different vendor ids"
#endif
/* Check if current file and Can_IPW.h header file are of the same module */
#if (CAN_MODULE_ID_PBCFG_C != CAN_IPW_MODULE_ID_H)
#error "Can_IPW.h and Can_PBcfg.c have different module ids"
#endif
/* Check if current file and CAN_IPW header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_PBCFG_C != CAN_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_AR_RELEASE_MINOR_VERSION_PBCFG_C != CAN_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_AR_RELEASE_REVISION_VERSION_PBCFG_C != CAN_IPW_AR_RELEASE_REVISION_VERSION_H))
  #error "AutoSar Version Numbers of Can_PBcfg.c and Can_IPW.h are different"
#endif
/* Check if current file and CAN_IPW header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PBCFG_C != CAN_IPW_SW_MAJOR_VERSION_H) || \
     (CAN_SW_MINOR_VERSION_PBCFG_C != CAN_IPW_SW_MINOR_VERSION_H) || \
     (CAN_SW_PATCH_VERSION_PBCFG_C != CAN_IPW_SW_PATCH_VERSION_H))
       #error "Software Version Numbers of Can_PBcfg.c and Can_IPW.h are different"
#endif

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_PBcfg_c_REF_2 MISRA 2004 Rule 19.15, Repeated include file MemMap.h  */
#include "Can_MemMap.h"
/* Check if current file and Can_MemMap.h header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CAN_AR_RELEASE_MAJOR_VERSION_PBCFG_C != CAN_MEMMAP_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_AR_RELEASE_MINOR_VERSION_PBCFG_C != CAN_MEMMAP_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Can_PBcfg.c and Can_MemMap.h are different"
    #endif
#endif
/**
@brief    Prototype of User Notifications
*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/* This macro defines the total of HOH configured */
#define CAN_MAXMBCOUNT_PB   8U

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#if (CAN_RXFIFO_ENABLE == STD_ON)
/**
* @brief        Can_RxFiFoTableIdConfigType
* @details      Identifier FormatA:
*                   - StandardID: bits [29:19]
*                   - ExtendedID: bits [29:1]
*               Identifier FormatB:
*                   - StandardID: bits [29:19] & [13:3]
*                   - ExtendedID: bits [29:16] & [13:0] (only 14 MSB)
*               Identifier FormatC:
*                   - StandardID: bits [31::24] & [23:16] & [15:8] & [7:0] (only 8 MSB)
*                   - ExtendedID: bits [31::24] & [23:16] & [15:8] & [7:0] (only 8 MSB)
*
*/
static CONST(Can_RxFiFoTableIdConfigType, CAN_CONST) RxFifoTableID_PBConfig0[CAN_MAXTABLEID_0] =
{
    {
        (uint32)0x07f80000U, /* CanRxFifoTable_0 of type Standard and formatA for FlexCAN_A */
        (uint32)0xfff80000U  /* Filter Mask (correspond to RXIMR register) */
    },
    {
        (uint32)0x07f80000U, /* CanRxFifoTable_1 of type Standard and formatA for FlexCAN_A */
        (uint32)0xfff80000U  /* Filter Mask (correspond to RXIMR register) */
    },
    {
        (uint32)0x07f80000U, /* CanRxFifoTable_2 of type Standard and formatA for FlexCAN_A */
        (uint32)0xfff80000U  /* Filter Mask (correspond to RXIMR register) */
    },
    {
        (uint32)0x07f80000U, /* CanRxFifoTable_3 of type Standard and formatA for FlexCAN_A */
        (uint32)0xfff80000U  /* Filter Mask (correspond to RXIMR register) */
    },
    {
        (uint32)0x07f80000U, /* CanRxFifoTable_4 of type Standard and formatA for FlexCAN_A */
        (uint32)0xfff80000U  /* Filter Mask (correspond to RXIMR register) */
    },
    {
        (uint32)0x07f80000U, /* CanRxFifoTable_5 of type Standard and formatA for FlexCAN_A */
        (uint32)0xfff80000U  /* Filter Mask (correspond to RXIMR register) */
    },
    {
        (uint32)0x07f80000U, /* CanRxFifoTable_6 of type Standard and formatA for FlexCAN_A */
        (uint32)0xfff80000U  /* Filter Mask (correspond to RXIMR register) */
    },
    {
        (uint32)0x07f80000U, /* CanRxFifoTable_7 of type Standard and formatA for FlexCAN_A */
        (uint32)0xfff80000U  /* Filter Mask (correspond to RXIMR register) */
    }
};
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
/*==================================================================================================*/
/**
* @brief          Filter Masks
* @details        Filter Masks
*
*/
/*==================================================================================================*/
static CONST(Can_IdType, CAN_CONST) Can_FilterMasks0_PB[CAN_MAXFILTERCOUNT_0] =
{
    (Can_IdType)0x7ffU, /* FilterMasks0[0], "CanHwFilter" */
    (Can_IdType)0x7ffU, /* FilterMasks0[1], "CanHwFilter" */
    (Can_IdType)0x7ffU, /* FilterMasks0[2], "CanHwFilter" */
    (Can_IdType)0x7ffU, /* FilterMasks0[3], "CanHwFilter" */
    (Can_IdType)0x7ffU, /* FilterMasks0[4], "CanHwFilter" */
    (Can_IdType)0x7ffU  /* FilterMasks0[5], "CanHwFilter" */
};

/*==================================================================================================*/
/**
* @brief          Information about message buffers
* @details        (CAN100)Several TX hardware objects with unique HTHs may be configured. The CanIf module provides the HTH as parameter of the TX request. See Figure 7-2 for a possible configuration.
*
*/
/*==================================================================================================*/
static CONST(Can_MBConfigObjectType, CAN_CONST) MessageBufferConfigs0_PB[CAN_MAXMBCOUNT_PB] =
{
    /* CanHardwareObject_NODE0_Rx_Std_MailBox_1 Message Buffer of Can Controller ID = 0U*/
    {
        (Can_HwHandleType)CAN_MAXMASKCOUNT, /* uIdMaskIndex */
        (uint8)0U, /* ControllerId  - based on the order from CanController list */
        CAN_STANDARD, /* ID type: EXTENDED, STANDARD, MIXED */
        CAN_RECEIVE, /* Receive/Transmit MB configuration */
        (Can_IdType)0x7c0U, /* MessageId */
        (uint8)0x0U, /* Local priority bits used for arbitration */
        (Can_HwHandleType)0x0U, /* Hardware Object ID */
        #if (CAN_FD_MODE_ENABLE == STD_ON)
        (uint8)0U,
        #endif
        /* Read/Write period reference used when POLLING mode is selected for the controller */
        (uint8)0U, /* HOH configured for INTERRUPT mode, reference not used */
        
        (uint16)0x0080U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)0U    /* The index of MB in message buffer memory */
        #if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
        /* The parameter is used to detect the MB which run with trigger transmit feature */
        ,(boolean)FALSE
        #endif
        /* The parameter is used to detect the MB which is use Polling or Interrupt */
        ,(boolean)FALSE /* CanHardwareObject_NODE0_Rx_Std_MailBox_1 uses Interrupt */
    },

    /* CanHardwareObject_NODE0_Rx_Std_MailBox_2 Message Buffer of Can Controller ID = 0U*/
    {
        (Can_HwHandleType)CAN_MAXMASKCOUNT, /* uIdMaskIndex */
        (uint8)0U, /* ControllerId  - based on the order from CanController list */
        CAN_STANDARD, /* ID type: EXTENDED, STANDARD, MIXED */
        CAN_RECEIVE, /* Receive/Transmit MB configuration */
        (Can_IdType)0x7dfU, /* MessageId */
        (uint8)0x0U, /* Local priority bits used for arbitration */
        (Can_HwHandleType)0x1U, /* Hardware Object ID */
        #if (CAN_FD_MODE_ENABLE == STD_ON)
        (uint8)0U,
        #endif
        /* Read/Write period reference used when POLLING mode is selected for the controller */
        (uint8)0U, /* HOH configured for INTERRUPT mode, reference not used */
        
        (uint16)0x0100U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)8U    /* The index of MB in message buffer memory */
        #if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
        /* The parameter is used to detect the MB which run with trigger transmit feature */
        ,(boolean)FALSE
        #endif
        /* The parameter is used to detect the MB which is use Polling or Interrupt */
        ,(boolean)FALSE /* CanHardwareObject_NODE0_Rx_Std_MailBox_2 uses Interrupt */
    },

    /* CanHardwareObject_NODE0_Rx_Std_MailBox_3 Message Buffer of Can Controller ID = 0U*/
    {
        (Can_HwHandleType)CAN_MAXMASKCOUNT, /* uIdMaskIndex */
        (uint8)0U, /* ControllerId  - based on the order from CanController list */
        CAN_STANDARD, /* ID type: EXTENDED, STANDARD, MIXED */
        CAN_RECEIVE, /* Receive/Transmit MB configuration */
        (Can_IdType)0x650U, /* MessageId */
        (uint8)0x0U, /* Local priority bits used for arbitration */
        (Can_HwHandleType)0x2U, /* Hardware Object ID */
        #if (CAN_FD_MODE_ENABLE == STD_ON)
        (uint8)0U,
        #endif
        /* Read/Write period reference used when POLLING mode is selected for the controller */
        (uint8)0U, /* HOH configured for INTERRUPT mode, reference not used */
        
        (uint16)0x0110U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)9U    /* The index of MB in message buffer memory */
        #if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
        /* The parameter is used to detect the MB which run with trigger transmit feature */
        ,(boolean)FALSE
        #endif
        /* The parameter is used to detect the MB which is use Polling or Interrupt */
        ,(boolean)FALSE /* CanHardwareObject_NODE0_Rx_Std_MailBox_3 uses Interrupt */
    },

    /* CanHardwareObject_NODE0_Tx_Std_MailBox_1 Message Buffer of Can Controller ID = 0U*/
    {
        (Can_HwHandleType)CAN_MAXMASKCOUNT, /* uIdMaskIndex */
        (uint8)0U, /* ControllerId  - based on the order from CanController list */
        CAN_STANDARD, /* ID type: EXTENDED, STANDARD, MIXED */
        CAN_TRANSMIT, /* Receive/Transmit MB configuration */
        (Can_IdType)0x0U, /* MessageId */
        (uint8)0x0U, /* Local priority bits used for arbitration */
        (Can_HwHandleType)0x3U, /* Hardware Object ID */
        #if (CAN_FD_MODE_ENABLE == STD_ON)
        (uint8)0U,
        #endif
        /* Read/Write period reference used when POLLING mode is selected for the controller */
        (uint8)0U,   /* HOH configured for INTERRUPT mode, reference not used */
        
        (uint16)0x0120U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)10U    /* The index of MB in message buffer memory */
        #if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
        /* The parameter is used to detect the MB which run with trigger transmit feature */
        ,(boolean)FALSE
        #endif
        /* The parameter is used to detect the MB which is use Polling or Interrupt */
        ,(boolean)FALSE /* CanHardwareObject_NODE0_Tx_Std_MailBox_1 uses Interrupt */
    },

    /* CanHardwareObject_NODE0_Tx_Std_MailBox_2 Message Buffer of Can Controller ID = 0U*/
    {
        (Can_HwHandleType)CAN_MAXMASKCOUNT, /* uIdMaskIndex */
        (uint8)0U, /* ControllerId  - based on the order from CanController list */
        CAN_STANDARD, /* ID type: EXTENDED, STANDARD, MIXED */
        CAN_TRANSMIT, /* Receive/Transmit MB configuration */
        (Can_IdType)0x0U, /* MessageId */
        (uint8)0x0U, /* Local priority bits used for arbitration */
        (Can_HwHandleType)0x4U, /* Hardware Object ID */
        #if (CAN_FD_MODE_ENABLE == STD_ON)
        (uint8)0U,
        #endif
        /* Read/Write period reference used when POLLING mode is selected for the controller */
        (uint8)0U,   /* HOH configured for INTERRUPT mode, reference not used */
        
        (uint16)0x0130U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)11U    /* The index of MB in message buffer memory */
        #if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
        /* The parameter is used to detect the MB which run with trigger transmit feature */
        ,(boolean)FALSE
        #endif
        /* The parameter is used to detect the MB which is use Polling or Interrupt */
        ,(boolean)FALSE /* CanHardwareObject_NODE0_Tx_Std_MailBox_2 uses Interrupt */
    },

    /* CanHardwareObject_NODE0_Tx_Std_MailBox_3 Message Buffer of Can Controller ID = 0U*/
    {
        (Can_HwHandleType)CAN_MAXMASKCOUNT, /* uIdMaskIndex */
        (uint8)0U, /* ControllerId  - based on the order from CanController list */
        CAN_STANDARD, /* ID type: EXTENDED, STANDARD, MIXED */
        CAN_TRANSMIT, /* Receive/Transmit MB configuration */
        (Can_IdType)0x301U, /* MessageId */
        (uint8)0x0U, /* Local priority bits used for arbitration */
        (Can_HwHandleType)0x5U, /* Hardware Object ID */
        #if (CAN_FD_MODE_ENABLE == STD_ON)
        (uint8)0U,
        #endif
        /* Read/Write period reference used when POLLING mode is selected for the controller */
        (uint8)0U,   /* HOH configured for INTERRUPT mode, reference not used */
        
        (uint16)0x0140U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)12U    /* The index of MB in message buffer memory */
        #if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
        /* The parameter is used to detect the MB which run with trigger transmit feature */
        ,(boolean)FALSE
        #endif
        /* The parameter is used to detect the MB which is use Polling or Interrupt */
        ,(boolean)FALSE /* CanHardwareObject_NODE0_Tx_Std_MailBox_3 uses Interrupt */
    },

    /* CanHardwareObject_NODE0_Tx_Std_MailBox_4 Message Buffer of Can Controller ID = 0U*/
    {
        (Can_HwHandleType)CAN_MAXMASKCOUNT, /* uIdMaskIndex */
        (uint8)0U, /* ControllerId  - based on the order from CanController list */
        CAN_STANDARD, /* ID type: EXTENDED, STANDARD, MIXED */
        CAN_TRANSMIT, /* Receive/Transmit MB configuration */
        (Can_IdType)0x302U, /* MessageId */
        (uint8)0x0U, /* Local priority bits used for arbitration */
        (Can_HwHandleType)0x6U, /* Hardware Object ID */
        #if (CAN_FD_MODE_ENABLE == STD_ON)
        (uint8)0U,
        #endif
        /* Read/Write period reference used when POLLING mode is selected for the controller */
        (uint8)0U,   /* HOH configured for INTERRUPT mode, reference not used */
        
        (uint16)0x0150U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)13U    /* The index of MB in message buffer memory */
        #if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
        /* The parameter is used to detect the MB which run with trigger transmit feature */
        ,(boolean)FALSE
        #endif
        /* The parameter is used to detect the MB which is use Polling or Interrupt */
        ,(boolean)FALSE /* CanHardwareObject_NODE0_Tx_Std_MailBox_4 uses Interrupt */
    },

    /* CanHardwareObject_NODE0_Tx_Std_MailBox_5 Message Buffer of Can Controller ID = 0U*/
    {
        (Can_HwHandleType)CAN_MAXMASKCOUNT, /* uIdMaskIndex */
        (uint8)0U, /* ControllerId  - based on the order from CanController list */
        CAN_STANDARD, /* ID type: EXTENDED, STANDARD, MIXED */
        CAN_TRANSMIT, /* Receive/Transmit MB configuration */
        (Can_IdType)0x303U, /* MessageId */
        (uint8)0x0U, /* Local priority bits used for arbitration */
        (Can_HwHandleType)0x7U, /* Hardware Object ID */
        #if (CAN_FD_MODE_ENABLE == STD_ON)
        (uint8)0U,
        #endif
        /* Read/Write period reference used when POLLING mode is selected for the controller */
        (uint8)0U,   /* HOH configured for INTERRUPT mode, reference not used */
        
        (uint16)0x0160U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)14U    /* The index of MB in message buffer memory */
        #if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
        /* The parameter is used to detect the MB which run with trigger transmit feature */
        ,(boolean)FALSE
        #endif
        /* The parameter is used to detect the MB which is use Polling or Interrupt */
        ,(boolean)FALSE /* CanHardwareObject_NODE0_Tx_Std_MailBox_5 uses Interrupt */
    }
};
/*==================================================================================================*/
/**
* @brief          Configuration of FlexCan controller
* @details        Configuration of FlexCan controller
*
*/
/* Compiler_Warning: this warning due to behavior of compiler depend on configs. */
static CONST(Can_ControllerBaudrateConfigType, CAN_CONST) ControllerBaudrateCfgSet0_PB_0[CAN_CFGSET0_MAX_BAUDRATE_FC_A_0] =
{
    /*
    =================================================
    Clock Size = 1.12E8 Hz  - Clock from MCU.

    Clock Prescaler = 25 (1..256)

    CanBitRate = 500 Kbps (1bps..1Mbps)
    Number CANTimeQuantas per bit = 9 (8..25)

    CTRL Register Fields:
    PSEG1 =0(0..7)
    PSEG2 =1(1..7)
    PROPSEG =4(0..7)
    RJW =0(0..3)
    =================================================
    */
    /* Configuration for CanController ID0 == FlexCAN_A */
    {
        /* ===== Control Register - CTRL ===== */
        (uint32)( 
                    ((uint32)24 << FLEXCAN_CTRL_PRESDIV_SHIFT_U8) |    /* CTRL[PRESDIV] - Clock Prescaler */
                    ((uint32)0 << FLEXCAN_CTRL_RJW_SHIFT_U8) |      /* CTRL[RJW] - Resynchronization Jump Width */
                    ((uint32)0 << FLEXCAN_CTRL_PSEG1_SHIFT_U8) |     /* CTRL[PSEG1] - Segment 1 */
                    ((uint32)1 << FLEXCAN_CTRL_PSEG2_SHIFT_U8) |   /* CTRL[PSEG2] - Segment 2 */
                    ((uint32)1 << FLEXCAN_CTRL_CLKSRC_SHIFT_U8) |
                    4U    /* CTRL[PROPSEG] - Propagation segment */
                ),
        (uint8)12U, /* CTRL2[TASD] Tx Arbitration Start Delay */
        
        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
        0U,
        #endif /* CAN_DUAL_CLOCK_MODE == STD_ON */
        
        (uint16)500   /* 500kbps baud rate */
        
        #if (CAN_FD_MODE_ENABLE == STD_ON)
        ,{
            (uint32)((uint32)0U << FLEXCAN_FD_OFFSET_U8), /*CAN FD Deactivated*/
            (uint32)0U,
            (uint32)(
                        (uint32)((uint32)0U<<FLEXCAN_FD_PRESDIV_OFFSET_U8) |
                        (uint32)((uint32)0U<<FLEXCAN_FD_PROPSEG_OFFSET_U8) |
                        (uint32)((uint32)0U<< FLEXCAN_FD_PSEG1_OFFSET_U8) |
                        (uint32)((uint32)0U<<FLEXCAN_FD_PSEG2_OFFSET_U8) |
                        (uint32)((uint32)0U<<FLEXCAN_FD_SJW_OFFSET_U8)  /*Sync jump width*/
                    ),
            (uint32)0U, /*TRCV DELAY*/
            (uint32)((uint32)0U<<FLEXCAN_FD_BRS_OFFSET_U8) /*false -> the node dos not exist, BRS deactivated*/
            #if ( (CAN_CONTROLLER_FD_ISO_CANFD == STD_ON) || (CAN_CONTROLLER_FD_PREXCEN == STD_ON) || (CAN_CONTROLLER_FD_EDFLTDIS == STD_ON) )
            ,(uint32)(0U)
            #endif /* ( (CAN_CONTROLLER_FD_ISO_CANFD == STD_ON) || (CAN_CONTROLLER_FD_PREXCEN == STD_ON) || (CAN_CONTROLLER_FD_EDFLTDIS == STD_ON)) */
        }
        #endif /* (CAN_FD_MODE_ENABLE == STD_ON) */
        
        #if (CAN_CBT_ENABLE == STD_ON)
        ,{
            (uint32)((uint32)0U<<FLEXCAN_CBT_OFFSET_U8),
            (uint32)0U,
            (uint32) (
                        (uint32)((uint32)0U<<FLEXCAN_FD_PRESDIV_OFFSET_U8) |
                        (uint32)((uint32)0U<<FLEXCAN_CBT_OFFSET_U8) |
                        (uint32)((uint32)0U<<FLEXCAN_FD_PROPSEG_OFFSET_U8) |
                        (uint32)((uint32)0U<< FLEXCAN_FD_PSEG1_OFFSET_U8) |
                        (uint32)((uint32)0U<<FLEXCAN_FD_PSEG2_OFFSET_U8) |
                        (uint32)((uint32)0U<<FLEXCAN_FD_SJW_OFFSET_U8) /*Sync jump width*/
                    )
        }
        #endif /* (CAN_CBT_ENABLE == STD_ON) */
        
        #if (CAN_SET_BAUDRATE_API == STD_ON)
        ,(uint16)0
        #endif
    }
};
/*==================================================================================================*/
/**
* @brief          Description of individual FlexCan controllers on chip
* @details        Description of individual FlexCan controllers on chip
*
*/

static CONST(Can_ControlerDescriptorType, CAN_CONST) ControlerDescriptors0_PB[CAN_MAXCONTROLLERCOUNT_0] =
{
    /* ControlerDescriptor of CanController_0*/
    {
        /* No. of Message Buffers for current controller - u8MaxMBCount */
        (uint8)15U, /* No. of Message Buffers for current controller - u8MaxMBCount */
        
        /* No. of BaudRate configured for current controller - u8MaxBaudRateCount */
        (uint8)1U,
        
        /* Default BaudRate configured for current controller - u8DefaultBaudRateIndex */
        (uint8)0U,
        
        /* pControllerBaudrateConfigsPtr - pControllerBaudrateConfigsPtr*/
        ControllerBaudrateCfgSet0_PB_0,
        
        #if (CAN_RXFIFO_ENABLE == STD_ON)
        /*Rx Fifo Global mask value - u32RxFifoGlobalMask*/
        (uint32)0x7ffU,
        /* Number of MBs used by Rx Fifo - u8RxFiFoUsedMb */
        (uint8)8U,
        /* Pointer to RxFifo Overflow notification function. - Can_RxFifoOverflowNotification */
        NULL_PTR,
        /* Pointer to RxFifo Warning notification function. - Can_RxFifoWarningNotification */
        NULL_PTR,

        #endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
        
        #if (CAN_FD_MODE_ENABLE == STD_ON)
        /* Message Buffer Data Size for three RAM regions */
        (uint32)(
                  0U
                ),
        #endif
        /* ===== Controller Options ===== -  u32Options*/
        (uint32)(
                    CAN_CONTROLLERCONFIG_RXFIFO_U32 | /* RX Fifo Enabled */
                    /* Error Notification disable */ 
                    #if (CAN_RXFIFO_ENABLE == STD_ON)
                    /* Rx Fifo Overflow handling disabled */ 
                    /* Rx Fifo Warning handling disabled */ 
                    CAN_CONTROLLERCONFIG_IDAM_A_U32 | /* ID Acceptance Mode A */
                    #endif
                    CAN_CONTROLLERCONFIG_RXINT_EN_U32 | /* There is At least one interrupt HRH */
                    CAN_CONTROLLERCONFIG_TXINT_EN_U32 | /* There is At least one interrupt HTH */
                    0U
                )
    }
};

/*==================================================================================================*/
/**
* @brief          Top level structure containing all Can driver configurations
* @details        Top level structure containing all Can driver configurations
*
*/
/* @violates @ref Can_PBcfg_c_REF_4 Violates MISRA 2004 Required Rule 8.10*/
CONST(Can_ConfigType, CAN_CONST) CanConfigSet=
{
    Can_FilterMasks0_PB, /*  - pFilterMasks */
    /* MessageBufferConfigContainer - MBConfigContainer */
    {
        MessageBufferConfigs0_PB, /* pMessageBufferConfigsPtr */
        (Can_HwHandleType)CAN_MAXMBCOUNT_PB, /* uMessageBufferConfigCount */
    },
    
    ControlerDescriptors0_PB, /* FlexCAN controller description - ControlerDescriptors*/
    
    #if (CAN_RXFIFO_ENABLE == STD_ON)
    /* Can_RxFiFoTableIdConfigType - pRxFiFoTableIdConfig */
    RxFifoTableID_PBConfig0,
    #endif  /* (CAN_RXFIFO_ENABLE == STD_ON) */
    
    /* The index of the first HTH configured */
    (Can_HwHandleType)3U
};
 
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

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_PBcfg_c_REF_1 MISRA 2004  Rule 19.1, #include preceded by non preproc directives.*/
/* @violates @ref Can_PBcfg_c_REF_2 MISRA 2004 Rule 19.15, Repeated include file MemMap.h  */
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
