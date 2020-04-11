/**
*   @file           Mcl_FlexIO_Irq.c
*   @version        1.0.1
*
*   @brief          AUTOSAR Mcl - FlexIO interrupt handler driver source file.
*   @details        FlexIO interrupt handling routines.
*
*   @addtogroup     MCL_MODULE
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

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
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
* @section Mcl_FlexIO_Irq_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Mcl_FlexIO_Irq_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
* the contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Mcl_FlexIO_Irq_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integral type.
* This violation is due to the pointer arithmetic used to write/ read
* the data to/from the registers.

* @section Mcl_FlexIO_Irq_c_REF_4
* Violates MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between
* a pointer type and an integral type
* This violation is due to the pointer arithmetic used to write/ read
* the data to/from the registers.
*
 * @section Mcl_FlexIO_Irq_c_REF_5
 * Violates MISRA 2004 Required Rule 8.10, could be made static
 * The respective code could not be made static because of layers architecture design of the
 * driver.
**/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mcl_IPW_Notif.h"
#include "Reg_eSys_Dma.h"
#include "StdRegMacros.h"
#include "modules.h"
#if ((USE_LIN_MODULE==STD_ON) || (USE_SPI_MODULE==STD_ON) || (USE_I2C_MODULE==STD_ON) || (USE_PWM_MODULE==STD_ON))

#include "Std_Types.h"

#if (USE_LIN_MODULE==STD_ON)
    #include "Lin.h"
    #include "Lin_FlexIO.h"
    #include "Lin_Cfg.h"
#endif

#if (USE_SPI_MODULE==STD_ON)
    #include "Spi.h"
    #include "Spi_FlexIO.h"
    #include "Spi_Cfg.h"
#endif

#if (USE_I2C_MODULE==STD_ON)
    #include "CDD_I2c.h"
    #include "I2c_FlexIO.h"
    #include "CDD_I2c_Cfg.h"
#endif

#if (USE_PWM_MODULE==STD_ON)
    #include "Pwm.h"
    #include "Pwm_FlexIO.h"
    #include "Pwm_Cfg.h"
#endif
#include "Mcal.h"
#include "Mcl_IPW.h"
#include "CDD_Mcl_Cfg.h"
#include "Reg_eSys_FlexIO.h"
#include "Mcl_FlexIO_Common_Types.h"
#include "Mcl_FlexIO_Common.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Mcl_FlexIO_Irq.c
* @brief          Source file version information  
*/
#define FLEXIO_IRQ_VENDOR_ID_C                       43
#define FLEXIO_IRQ_AR_RELEASE_MAJOR_VERSION_C        4
#define FLEXIO_IRQ_AR_RELEASE_MINOR_VERSION_C        3
#define FLEXIO_IRQ_AR_RELEASE_REVISION_VERSION_C     1
#define FLEXIO_IRQ_SW_MAJOR_VERSION_C                1
#define FLEXIO_IRQ_SW_MINOR_VERSION_C                0
#define FLEXIO_IRQ_SW_PATCH_VERSION_C                1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and Mcl_FlexIO_Common.h header file are of the same vendor */
#if (FLEXIO_IRQ_VENDOR_ID_C != FLEXIO_COMMON_VENDOR_ID)
    #error "Mcl_FlexIO_Common.c and Mcl_FlexIO_Common.h have different vendor ids"
#endif
/* Check if source file and Mcl_FlexIO_Common.h header file are of the same Autosar version */
#if ((FLEXIO_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_COMMON_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_IRQ_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_COMMON_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXIO_COMMON_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_FlexIO_Common.h and Mcl_FlexIO_Common.h are different"
#endif
/* Check if source file and Mcl_FlexIO_Common.h header file are of the same software version */
#if ((FLEXIO_IRQ_SW_MAJOR_VERSION_C != FLEXIO_COMMON_SW_MAJOR_VERSION) || \
     (FLEXIO_IRQ_SW_MINOR_VERSION_C != FLEXIO_COMMON_SW_MINOR_VERSION) || \
     (FLEXIO_IRQ_SW_PATCH_VERSION_C != FLEXIO_COMMON_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_FlexIO_Common.h and Mcl_FlexIO_Common.h are different"
#endif
/* Check if source file and StdRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FLEXIO_IRQ_AR_RELEASE_MAJOR_VERSION_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_IRQ_AR_RELEASE_MINOR_VERSION_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Mcl_Dma_Irq.cand StdRegMacros.h are different"
    #endif
#endif


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (MCL_ENABLE_FLEXIO == STD_ON)
#define MCL_START_SEC_CODE
/** @violates @ref Mcl_FlexIO_Irq_c_REF_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_FlexIO_Irq_c_REF_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"

ISR(MCL_FLEXIO_ISR);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if  ((defined PWM_FLEXIO_0_CH_0_1_USED) && (defined I2C_FLEXIO_0_CH_0_1_USED))
#error "PWM and I2C resource conflict for FLEXIO channels 0 and 1"
#endif

#if  ((defined PWM_FLEXIO_0_CH_0_1_USED) && (defined LIN_FLEXIO_0_CH_0_1_USED))
#error "PWM and LIN resource conflict for FLEXIO channels 0 and 1"
#endif

#if  ((defined PWM_FLEXIO_0_CH_0_1_USED) && (defined SPI_FLEXIO_0_CH_0_1_USED))
#error "PWM and SPI resource conflict for FLEXIO channels 0 and 1"
#endif

#if  ((defined I2C_FLEXIO_0_CH_0_1_USED) && (defined LIN_FLEXIO_0_CH_0_1_USED))
#error "I2C and LIN resource conflict for FLEXIO channels 0 and 1"
#endif

#if  ((defined I2C_FLEXIO_0_CH_0_1_USED) && (defined SPI_FLEXIO_0_CH_0_1_USED))
#error "I2C and SPI resource conflict for FLEXIO channels 0 and 1"
#endif

#if  ((defined LIN_FLEXIO_0_CH_0_1_USED) && (defined SPI_FLEXIO_0_CH_0_1_USED))
#error "LIN and SPI resource conflict for FLEXIO channels 0 and 1"
#endif


#if  ((defined PWM_FLEXIO_0_CH_2_3_USED) && (defined I2C_FLEXIO_0_CH_2_3_USED))
#error "PWM and I2C resource conflict for FLEXIO channels 2 and 3"
#endif

#if  ((defined PWM_FLEXIO_0_CH_2_3_USED) && (defined LIN_FLEXIO_0_CH_2_3_USED))
#error "PWM and LIN resource conflict for FLEXIO channels 2 and 3"
#endif

#if  ((defined PWM_FLEXIO_0_CH_2_3_USED) && (defined SPI_FLEXIO_0_CH_2_3_USED))
#error "PWM and SPI resource conflict for FLEXIO channels 2 and 3"
#endif

#if  ((defined I2C_FLEXIO_0_CH_2_3_USED) && (defined LIN_FLEXIO_0_CH_2_3_USED))
#error "I2C and LIN resource conflict for FLEXIO channels 2 and 3"
#endif

#if  ((defined I2C_FLEXIO_0_CH_2_3_USED) && (defined SPI_FLEXIO_0_CH_2_3_USED))
#error "I2C and SPI resource conflict for FLEXIO channels 2 and 3"
#endif

#if  ((defined LIN_FLEXIO_0_CH_2_3_USED) && (defined SPI_FLEXIO_0_CH_2_3_USED))
#error "LIN and SPI resource conflict for FLEXIO channels 2 and 3"
#endif

#if  (((defined PWM_FLEXIO_0_PIN_0_USED) && (defined I2C_FLEXIO_0_PIN_0_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_1_USED) && (defined I2C_FLEXIO_0_PIN_1_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_2_USED) && (defined I2C_FLEXIO_0_PIN_2_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_3_USED) && (defined I2C_FLEXIO_0_PIN_3_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_4_USED) && (defined I2C_FLEXIO_0_PIN_4_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_5_USED) && (defined I2C_FLEXIO_0_PIN_5_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_6_USED) && (defined I2C_FLEXIO_0_PIN_6_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_7_USED) && (defined I2C_FLEXIO_0_PIN_7_USED)))
#error "PWM and I2C resource conflict for FLEXIO pins"
#endif
#if  (((defined PWM_FLEXIO_0_PIN_0_USED) && (defined LIN_FLEXIO_0_PIN_0_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_1_USED) && (defined LIN_FLEXIO_0_PIN_1_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_2_USED) && (defined LIN_FLEXIO_0_PIN_2_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_3_USED) && (defined LIN_FLEXIO_0_PIN_3_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_4_USED) && (defined LIN_FLEXIO_0_PIN_4_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_5_USED) && (defined LIN_FLEXIO_0_PIN_5_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_6_USED) && (defined LIN_FLEXIO_0_PIN_6_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_7_USED) && (defined LIN_FLEXIO_0_PIN_7_USED)))
#error "PWM and LIN resource conflict for FLEXIO pins"
#endif
#if  (((defined PWM_FLEXIO_0_PIN_0_USED) && (defined SPI_FLEXIO_0_PIN_0_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_1_USED) && (defined SPI_FLEXIO_0_PIN_1_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_2_USED) && (defined SPI_FLEXIO_0_PIN_2_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_3_USED) && (defined SPI_FLEXIO_0_PIN_3_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_4_USED) && (defined SPI_FLEXIO_0_PIN_4_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_5_USED) && (defined SPI_FLEXIO_0_PIN_5_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_6_USED) && (defined SPI_FLEXIO_0_PIN_6_USED)) || \
     ((defined PWM_FLEXIO_0_PIN_7_USED) && (defined SPI_FLEXIO_0_PIN_7_USED)))
#error "PWM and SPI resource conflict for FLEXIO pins"
#endif
#if  (((defined I2C_FLEXIO_0_PIN_0_USED) && (defined LIN_FLEXIO_0_PIN_0_USED)) || \
     ((defined I2C_FLEXIO_0_PIN_1_USED) && (defined LIN_FLEXIO_0_PIN_1_USED)) || \
     ((defined I2C_FLEXIO_0_PIN_2_USED) && (defined LIN_FLEXIO_0_PIN_2_USED)) || \
     ((defined I2C_FLEXIO_0_PIN_3_USED) && (defined LIN_FLEXIO_0_PIN_3_USED)) || \
     ((defined I2C_FLEXIO_0_PIN_4_USED) && (defined LIN_FLEXIO_0_PIN_4_USED)) || \
     ((defined I2C_FLEXIO_0_PIN_5_USED) && (defined LIN_FLEXIO_0_PIN_5_USED)) || \
     ((defined I2C_FLEXIO_0_PIN_6_USED) && (defined LIN_FLEXIO_0_PIN_6_USED)) || \
     ((defined I2C_FLEXIO_0_PIN_7_USED) && (defined LIN_FLEXIO_0_PIN_7_USED)))
#error "I2C and LIN resource conflict for FLEXIO pins"
#endif
#if  (((defined I2C_FLEXIO_0_PIN_0_USED) && (defined SPI_FLEXIO_0_PIN_0_USED)) || \
     ((defined I2C_FLEXIO_0_PIN_1_USED) && (defined SPI_FLEXIO_0_PIN_1_USED)) || \
     ((defined I2C_FLEXIO_0_PIN_2_USED) && (defined SPI_FLEXIO_0_PIN_2_USED)) || \
     ((defined I2C_FLEXIO_0_PIN_3_USED) && (defined SPI_FLEXIO_0_PIN_3_USED)) || \
     ((defined I2C_FLEXIO_0_PIN_4_USED) && (defined SPI_FLEXIO_0_PIN_4_USED)) || \
     ((defined I2C_FLEXIO_0_PIN_5_USED) && (defined SPI_FLEXIO_0_PIN_5_USED)) || \
     ((defined I2C_FLEXIO_0_PIN_6_USED) && (defined SPI_FLEXIO_0_PIN_6_USED)) || \
     ((defined I2C_FLEXIO_0_PIN_7_USED) && (defined SPI_FLEXIO_0_PIN_7_USED)))
#error "I2C and SPI resource conflict for FLEXIO pins"
#endif
#if  (((defined LIN_FLEXIO_0_PIN_0_USED) && (defined SPI_FLEXIO_0_PIN_0_USED)) || \
     ((defined LIN_FLEXIO_0_PIN_1_USED) && (defined SPI_FLEXIO_0_PIN_1_USED)) || \
     ((defined LIN_FLEXIO_0_PIN_2_USED) && (defined SPI_FLEXIO_0_PIN_2_USED)) || \
     ((defined LIN_FLEXIO_0_PIN_3_USED) && (defined SPI_FLEXIO_0_PIN_3_USED)) || \
     ((defined LIN_FLEXIO_0_PIN_4_USED) && (defined SPI_FLEXIO_0_PIN_4_USED)) || \
     ((defined LIN_FLEXIO_0_PIN_5_USED) && (defined SPI_FLEXIO_0_PIN_5_USED)) || \
     ((defined LIN_FLEXIO_0_PIN_6_USED) && (defined SPI_FLEXIO_0_PIN_6_USED)) || \
     ((defined LIN_FLEXIO_0_PIN_7_USED) && (defined SPI_FLEXIO_0_PIN_7_USED)))
#error "LIN and SPI resource conflict for FLEXIO pins"
#endif

#if (((defined PWM_FLEXIO_0_CH_0_1_USED) && (!defined PWM_FLEXIO_0_CH_0_1_ISR_USED)) || \
    ((defined I2C_FLEXIO_0_CH_0_1_USED) && (!defined I2C_FLEXIO_0_CH_0_1_ISR_USED)) || \
    ((defined LIN_FLEXIO_0_CH_0_1_USED) && (!defined LIN_FLEXIO_0_CH_0_1_ISR_USED)) || \
    ((defined SPI_FLEXIO_0_CH_0_1_USED) && (!defined SPI_FLEXIO_0_CH_0_1_ISR_USED)) || \
    \
    ((defined PWM_FLEXIO_0_CH_2_3_USED) && (!defined PWM_FLEXIO_0_CH_2_3_ISR_USED)) || \
    ((defined I2C_FLEXIO_0_CH_2_3_USED) && (!defined I2C_FLEXIO_0_CH_2_3_ISR_USED)) || \
    ((defined LIN_FLEXIO_0_CH_2_3_USED) && (!defined LIN_FLEXIO_0_CH_2_3_ISR_USED)) || \
    ((defined SPI_FLEXIO_0_CH_2_3_USED) && (!defined SPI_FLEXIO_0_CH_2_3_ISR_USED)))

#endif


LOCAL_INLINE FUNC(void, MCL_CODE) Mcl_FlexioProcessCombinedInterrupt (void)
{
    VAR(uint8, AUTOMATIC) u8ShifterMaskFlag   = (uint8)0U;
    VAR(uint8, AUTOMATIC) u8ErrMaskFlag       = (uint8)0U;
    VAR(uint8, AUTOMATIC) u8TimerMaskFlag     = (uint8)0U;
    
    VAR(uint8, AUTOMATIC) u8ShifterValidIsrMask = (uint8)0U;
    VAR(uint8, AUTOMATIC) u8ErrValidIsrMask     = (uint8)0U;
    VAR(uint8, AUTOMATIC) u8TimerValidIsrMask   = (uint8)0U;


    /* Check if driver is init */
    if (FLEXIO_MCL_INITIALIZED == Mcl_FlexIO_InitStatus)
    {
        /*Check both Interrupt flags and Interrupt Enable flags are set*/
        /* shifter status flags are cleared after a read */
        /*@violates @ref Mcl_FlexIO_Irq_c_REF_3 Violates MISRA 2004 Rule 11.1*/
        /*@violates @ref Mcl_FlexIO_Irq_c_REF_4 Violates MISRA 2004 Rule 11.3*/
        u8ShifterMaskFlag = (uint8)((REG_READ32(FLEXIO_SHIFTSTAT_ADDR32) & FLEXIO_SHIFTSTAT_SSF_MASK_U32));
        /*@violates @ref Mcl_FlexIO_Irq_c_REF_3 Violates MISRA 2004 Rule 11.1*/
        /*@violates @ref Mcl_FlexIO_Irq_c_REF_4 Violates MISRA 2004 Rule 11.3*/
        u8ShifterValidIsrMask = (uint8)(u8ShifterMaskFlag & (uint8)((REG_READ32(FLEXIO_SHIFTSIEN_ADDR32) & FLEXIO_SHIFTSIEN_SSIE_MASK_U32)));
        /*@violates @ref Mcl_FlexIO_Irq_c_REF_3 Violates MISRA 2004 Rule 11.1*/
        /*@violates @ref Mcl_FlexIO_Irq_c_REF_4 Violates MISRA 2004 Rule 11.3*/
        u8ErrMaskFlag = (uint8)((REG_READ32(FLEXIO_SHIFTERR_ADDR32) & FLEXIO_SHIFTERR_SEF_MASK_U32));
        /*@violates @ref Mcl_FlexIO_Irq_c_REF_3 Violates MISRA 2004 Rule 11.1*/
        /*@violates @ref Mcl_FlexIO_Irq_c_REF_4 Violates MISRA 2004 Rule 11.3*/
        u8ErrValidIsrMask = (uint8)(u8ErrMaskFlag & (uint8)((REG_READ32(FLEXIO_SHIFTEIEN_ADDR32) & FLEXIO_SHIFTEIEN_SEIE_MASK_U32)));
        /*@violates @ref Mcl_FlexIO_Irq_c_REF_3 Violates MISRA 2004 Rule 11.1*/
        /*@violates @ref Mcl_FlexIO_Irq_c_REF_4 Violates MISRA 2004 Rule 11.3*/
        u8TimerMaskFlag = (uint8)((REG_READ32(FLEXIO_TIMSTAT_ADDR32) & FLEXIO_TIMSTAT_TSF_MASK_U32));
        /*@violates @ref Mcl_FlexIO_Irq_c_REF_3 Violates MISRA 2004 Rule 11.1*/
        /*@violates @ref Mcl_FlexIO_Irq_c_REF_4 Violates MISRA 2004 Rule 11.3*/
        u8TimerValidIsrMask = (uint8)(u8TimerMaskFlag & (uint8)((REG_READ32(FLEXIO_TIMIEN_ADDR32) & FLEXIO_TIMIEN_TEIE_MASK_U32)));
    
        /* If there is no IEN set, the ISR was invoked spuriously */
        if (0U == (u8ShifterValidIsrMask | u8ErrValidIsrMask | u8TimerValidIsrMask))
        {
            Mcl_Flexio_ClrShiftErr(u8ErrMaskFlag);
            Mcl_Flexio_ClrTimStat(u8TimerMaskFlag);
        }
        
#if (defined PWM_FLEXIO_0_CH_0_1_ISR_USED) || (defined I2C_FLEXIO_0_CH_0_1_ISR_USED) || \
    (defined LIN_FLEXIO_0_CH_0_1_ISR_USED) || (defined SPI_FLEXIO_0_CH_0_1_ISR_USED)
        /* FLEXIO_0_CH_0_1 is an asynchronous channel */
        if (( 0U != (u8ShifterValidIsrMask & ((uint8)FLEXIO_SEL_0_1_MASK_U32))) || \
            ( 0U != (u8ErrValidIsrMask     & ((uint8)FLEXIO_SEL_0_1_MASK_U32))) || \
            ( 0U != (u8TimerValidIsrMask   & ((uint8)FLEXIO_SEL_0_1_MASK_U32))))
        {
            /* Clear the currently enabled flags and the flags for which the driver doesn't wait, but are actually set */
            if (0U != (u8ErrMaskFlag & FLEXIO_SEL_0_1_MASK_U32))
            {
                Mcl_Flexio_ClrShiftErr(u8ErrMaskFlag & ((uint8)FLEXIO_SEL_0_1_MASK_U32));
            }
            if (0U != (u8TimerMaskFlag & FLEXIO_SEL_0_1_MASK_U32))
            {
                Mcl_Flexio_ClrTimStat(u8TimerMaskFlag & ((uint8)FLEXIO_SEL_0_1_MASK_U32));
            }

#if (defined PWM_FLEXIO_0_CH_0_1_ISR_USED) 
            Pwm_FlexIO_InterruptHandler((uint8)FLEXIO_0_CH_0, u8TimerValidIsrMask & ((uint8)FLEXIO_SEL_0_1_MASK_U32));
#endif
#if (defined I2C_FLEXIO_0_CH_0_1_ISR_USED) 
            I2c_FlexIO_InterruptHandler((uint8)FLEXIO_0_CH_0, u8ShifterValidIsrMask & ((uint8)FLEXIO_SEL_0_1_MASK_U32), u8ErrValidIsrMask & ((uint8)FLEXIO_SEL_0_1_MASK_U32), u8TimerValidIsrMask & ((uint8)FLEXIO_SEL_0_1_MASK_U32));
#endif
#if (defined LIN_FLEXIO_0_CH_0_1_ISR_USED) 
            Lin_FlexIO_InterruptHandler((uint8)FLEXIO_0_CH_0, u8ShifterValidIsrMask & ((uint8)FLEXIO_SEL_0_1_MASK_U32), u8ErrValidIsrMask & ((uint8)FLEXIO_SEL_0_1_MASK_U32), u8TimerValidIsrMask & ((uint8)FLEXIO_SEL_0_1_MASK_U32));
#endif
#if (defined SPI_FLEXIO_0_CH_0_1_ISR_USED) 
            Spi_FlexIO_InterruptHandler((uint8)FLEXIO_0_CH_0, u8ShifterValidIsrMask & ((uint8)FLEXIO_SEL_0_1_MASK_U32), u8ErrValidIsrMask & ((uint8)FLEXIO_SEL_0_1_MASK_U32), u8TimerValidIsrMask & ((uint8)FLEXIO_SEL_0_1_MASK_U32));
#endif
        }
#endif

#if (defined PWM_FLEXIO_0_CH_2_3_ISR_USED) || (defined I2C_FLEXIO_0_CH_2_3_ISR_USED) || \
    (defined LIN_FLEXIO_0_CH_2_3_ISR_USED) || (defined SPI_FLEXIO_0_CH_2_3_ISR_USED)
        /* FLEXIO_0_CH_2_3 is an asynchronous channel */
        if (( 0U != (u8ShifterValidIsrMask & ((uint8)FLEXIO_SEL_2_3_MASK_U32))) || \
            ( 0U != (u8ErrValidIsrMask     & ((uint8)FLEXIO_SEL_2_3_MASK_U32))) || \
            ( 0U != (u8TimerValidIsrMask   & ((uint8)FLEXIO_SEL_2_3_MASK_U32))))
        {
            /* Clear the currently enabled flags and the flags for which the driver doesn't wait, but are actually set */
            if (0U != (u8ErrMaskFlag & FLEXIO_SEL_2_3_MASK_U32))
            {
                Mcl_Flexio_ClrShiftErr(u8ErrMaskFlag & ((uint8)FLEXIO_SEL_2_3_MASK_U32));
            }
            if (0U != (u8TimerMaskFlag & FLEXIO_SEL_2_3_MASK_U32))
            {
                Mcl_Flexio_ClrTimStat(u8TimerMaskFlag & ((uint8)FLEXIO_SEL_2_3_MASK_U32));
            }

#if (defined PWM_FLEXIO_0_CH_2_3_ISR_USED)
            Pwm_FlexIO_InterruptHandler((uint8)FLEXIO_0_CH_2, u8TimerValidIsrMask & ((uint8)FLEXIO_SEL_2_3_MASK_U32));
#endif
#if (defined I2C_FLEXIO_0_CH_2_3_ISR_USED)
            I2c_FlexIO_InterruptHandler((uint8)FLEXIO_0_CH_2, u8ShifterValidIsrMask & ((uint8)FLEXIO_SEL_2_3_MASK_U32), u8ErrValidIsrMask & ((uint8)FLEXIO_SEL_2_3_MASK_U32), u8TimerValidIsrMask & ((uint8)FLEXIO_SEL_2_3_MASK_U32));
#endif
#if (defined LIN_FLEXIO_0_CH_2_3_ISR_USED)
            Lin_FlexIO_InterruptHandler((uint8)FLEXIO_0_CH_2, u8ShifterValidIsrMask & ((uint8)FLEXIO_SEL_2_3_MASK_U32), u8ErrValidIsrMask & ((uint8)FLEXIO_SEL_2_3_MASK_U32), u8TimerValidIsrMask & ((uint8)FLEXIO_SEL_2_3_MASK_U32));
#endif
#if (defined SPI_FLEXIO_0_CH_2_3_ISR_USED)
            Spi_FlexIO_InterruptHandler((uint8)FLEXIO_0_CH_2, u8ShifterValidIsrMask & ((uint8)FLEXIO_SEL_2_3_MASK_U32), u8ErrValidIsrMask & ((uint8)FLEXIO_SEL_2_3_MASK_U32), u8TimerValidIsrMask & ((uint8)FLEXIO_SEL_2_3_MASK_U32));
#endif
        }
#endif

#if (!defined PWM_FLEXIO_0_CH_0_1_USED) && (!defined I2C_FLEXIO_0_CH_0_1_USED) && \
    (!defined LIN_FLEXIO_0_CH_0_1_USED) && (!defined SPI_FLEXIO_0_CH_0_1_USED)
    
        /* Check if the interrupt is spurious or not */
        if (0U != (u8ErrMaskFlag & FLEXIO_SEL_0_1_MASK_U32))
        {
            Mcl_Flexio_ClrShiftErr(u8ErrMaskFlag & ((uint8)FLEXIO_SEL_0_1_MASK_U32));
        }
        if (0U != (u8TimerMaskFlag & FLEXIO_SEL_0_1_MASK_U32))
        {
            Mcl_Flexio_ClrTimStat(u8TimerMaskFlag & ((uint8)FLEXIO_SEL_0_1_MASK_U32)); 
        }
#endif

#if (!defined PWM_FLEXIO_0_CH_2_3_USED) && (!defined I2C_FLEXIO_0_CH_2_3_USED) && \
    (!defined LIN_FLEXIO_0_CH_2_3_USED) && (!defined SPI_FLEXIO_0_CH_2_3_USED)
    
        /* Check if the interrupt is spurious or not */
        if (0U != (u8ErrMaskFlag & FLEXIO_SEL_2_3_MASK_U32))
        {
            Mcl_Flexio_ClrShiftErr(u8ErrMaskFlag & ((uint8)FLEXIO_SEL_2_3_MASK_U32));
        }
        if (0U != (u8TimerMaskFlag & FLEXIO_SEL_2_3_MASK_U32))
        {
            Mcl_Flexio_ClrTimStat(u8TimerMaskFlag & ((uint8)FLEXIO_SEL_2_3_MASK_U32)); 
        }
#endif
    }
    
else
    {
        /* Clear all interrupt before Init */
        Mcl_Flexio_ClrShiftErr((uint8)FLEXIO_SEL_0_3_MASK_U32);
        
        Mcl_Flexio_ClrTimStat((uint8)FLEXIO_SEL_0_3_MASK_U32); 
    }

}


#define MCL_STOP_SEC_CODE
/** @violates @ref Mcl_FlexIO_Irq_c_REF_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_FlexIO_Irq_c_REF_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
/** @violates @ref Mcl_FlexIO_Irq_c_REF_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_FlexIO_Irq_c_REF_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"

/** @violates @ref Mcl_FlexIO_Irq_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
ISR(MCL_FLEXIO_ISR)
{
    Mcl_FlexioProcessCombinedInterrupt();
    EXIT_INTERRUPT();
}

#define MCL_STOP_SEC_CODE
/** @violates @ref Mcl_FlexIO_Irq_c_REF_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_FlexIO_Irq_c_REF_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"

#endif /*(MCL_ENABLE_FLEXIO == STD_ON)*/
#ifdef __cplusplus
}
#endif
#endif

/** @} */
