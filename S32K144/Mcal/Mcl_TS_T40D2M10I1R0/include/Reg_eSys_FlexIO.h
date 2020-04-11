/**
*   @file    Reg_eSys_FlexIO.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - Flexio driver header file.
*   @details Flexio module register description.
*
*   @addtogroup FLEXIO_MODULE
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

#ifndef REG_ESYS_FLEXIO_H
#define REG_ESYS_FLEXIO_H

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
* @section Reg_eSys_FlexIO_REF_1
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*          This violation is due to function like macros defined for register operations.
*          Function like macros are used to reduce code complexity.
**/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Reg_eSys_FlexIO.h
* @brief          Source file version information    
*/
#define REG_ESYS_FLEXIO_VENDOR_ID                       43
#define REG_ESYS_FLEXIO_MODULE_ID                       255
#define REG_ESYS_FLEXIO_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_FLEXIO_AR_RELEASE_MINOR_VERSION        3
#define REG_ESYS_FLEXIO_AR_RELEASE_REVISION_VERSION     1
#define REG_ESYS_FLEXIO_SW_MAJOR_VERSION                1
#define REG_ESYS_FLEXIO_SW_MINOR_VERSION                0
#define REG_ESYS_FLEXIO_SW_PATCH_VERSION                1
/** @} */
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if the header file and Reg_eSys.h file are of the same Autosar version */
    #if ((REG_ESYS_FLEXIO_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_FLEXIO_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Reg_eSys_FLEXIO.h and Reg_eSys.h are different"
    #endif 
#endif

/* Check if the eader file and Mcal header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_FLEXIO_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_FLEXIO_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_FLEXIO.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL DEFINES & DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifndef FLEXIO_BASEADDR
    #define FLEXIO_BASEADDR (0x01UL)
#endif

/**
* @brief FLEXIO control register
*/

/**
* @details  FLEXIO macro to access register Version ID Register (VERID).
*/
#define FLEXIO_VERID_ADDR32                  ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000000U))

/**
* @details  FLEXIO macro to access register Parameter Register (PARAM).
*/
#define FLEXIO_PARAM_ADDR32                  ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000004U))

/**
* @details  FLEXIO macro to access register FlexIO Control Register (CTRL).
*/
#define FLEXIO_CTRL_ADDR32                   ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000008U))

/**
* @details  FLEXIO macro to access register Pin State Register (PIN).
*/
#define FLEXIO_PIN_ADDR32                    ((uint32)(FLEXIO_BASEADDR + (uint32)0x0000000CU))

/**
* @details  FLEXIO macro to access register Shifter Status Register (SHIFTSTAT).
*/
#define FLEXIO_SHIFTSTAT_ADDR32              ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000010U))

/**
* @details  FLEXIO macro to access register Shifter Error Register (SHIFTERR).
*/
#define FLEXIO_SHIFTERR_ADDR32               ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000014U))

/**
* @details  FLEXIO macro to access register Timer Status Register (TIMSTAT).
*/
#define FLEXIO_TIMSTAT_ADDR32                ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000018U))

/**
* @details  FLEXIO macro to access register Shifter Status Interrupt Enable (SHIFTSIEN).
*/
#define FLEXIO_SHIFTSIEN_ADDR32              ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000020U))

/**
* @details  FLEXIO macro to access register Shifter Error Interrupt Enable (SHIFTEIEN).
*/
#define FLEXIO_SHIFTEIEN_ADDR32              ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000024U))

/**
* @details  FLEXIO macro to access register Timer Interrupt Enable Register (TIMIEN).
*/
#define FLEXIO_TIMIEN_ADDR32                 ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000028U))

/**
* @details  FLEXIO macro to access register Shifter Status DMA Enable (SHIFTSDEN).
*/
#define FLEXIO_SHIFTSDEN_ADDR32              ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000030U))

/**
* @details  FLEXIO macro to access register Shifter Control N (SHIFTCTL0 - SHIFTCTL3).
*/
/* @violates @ref Reg_eSys_FlexIO_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTCTLn_ADDR32(shifter)     ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000080U + (uint32)((shifter) << 2U)))

/**
* @details  FLEXIO macro to access register Shifter Configuration N (SHIFTCFG0 - SHIFTCFG3).
*/
/* @violates @ref Reg_eSys_FlexIO_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTCFGn_ADDR32(shifter)     ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000100U + (uint32)((shifter) << 2U)))

/**
* @details  FLEXIO macro to access register Shifter Buffer N (SHIFTBUF0 - SHIFTBUF3).
*/
/* @violates @ref Reg_eSys_FlexIO_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTBUFn_ADDR32(shifter)     ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000200U + (uint32)((shifter) << 2U)))

/**
* @details  FLEXIO macro to access register Shifter Buffer N Bit Swapped (SHIFTBUFBIS0 - SHIFTBUFBIS3).
*/
/* @violates @ref Reg_eSys_FlexIO_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTBUFBISn_ADDR32(shifter)  ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000280U + (uint32)((shifter) << 2U)))

/**
* @details  FLEXIO macro to access register Shifter Buffer N Byte Swapped (SHIFTBUFBYS0 - SHIFTBUFBYS3).
*/
/* @violates @ref Reg_eSys_FlexIO_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTBUFBYSn_ADDR32(shifter)  ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000300U + (uint32)((shifter) << 2U)))

/**
* @details  FLEXIO macro to access register Shifter Buffer N Bit Byte Swapped (SHIFTBUFBBS0 - SHIFTBUFBBS3).
*/
/* @violates @ref Reg_eSys_FlexIO_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTBUFBBSn_ADDR32(shifter)  ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000380U + (uint32)((shifter) << 2U)))

/**
* @details  FLEXIO macro to access register Timer Control N (TIMCTL0 - TIMCTL3).
*/
/* @violates @ref Reg_eSys_FlexIO_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_TIMCTLn_ADDR32(timer)         ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000400U + (uint32)((timer) << 2U)))

/**
* @details  FLEXIO macro to access register Timer Configuration N (TIMCFG0 - TIMCFG3).
*/
/* @violates @ref Reg_eSys_FlexIO_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_TIMCFGn_ADDR32(timer)         ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000480U + (uint32)((timer) << 2U)))

/**
* @details  FLEXIO macro to access register Timer Compare N (TIMCMP0 - TIMCMP3).
*/
/* @violates @ref Reg_eSys_FlexIO_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_TIMCMPn_ADDR32(timer)         ((uint32)(FLEXIO_BASEADDR + (uint32)0x00000500U + (uint32)((timer) << 2U)))

/**
* @brief    FLEXIO Registers bits.
* @details  CTRL register bit masks.
*/
#define FLEXIO_CTRL_RWBITS_MASK_U32                   ((uint32)0x80000007U)
#define FLEXIO_CTRL_INIT_BITS_MASK_U32                ((uint32)0xC0000004U)

#define FLEXIO_CTRL_DOZEN_MASK_U32                    ((uint32)0x80000000U)
#define FLEXIO_CTRL_DBGE_MASK_U32                     ((uint32)0x40000000U)
#define FLEXIO_CTRL_SWRST_MASK_U32                    ((uint32)0x00000002U)
#define FLEXIO_CTRL_FLEXEN_MASK_U32                   ((uint32)0x00000001U)

#define FLEXIO_ENABLED_IN_DBG_U32                     (FLEXIO_CTRL_DBGE_MASK_U32)
#define FLEXIO_DISABLED_IN_DBG_U32                    ((uint32)0x00000000U)

#define FLEXIO_ENABLED_IN_DOZE_U32                    (FLEXIO_CTRL_DOZEN_MASK_U32)
#define FLEXIO_DISABLED_IN_DOZE_U32                   ((uint32)0x00000000U)

#define FLEXIO_SW_RESET_ENABLED_U32                   (FLEXIO_CTRL_SWRST_MASK_U32)
#define FLEXIO_SW_RESET_DISABLED_U32                  ((uint32)0x00000000U)

#define FLEXIO_MODULE_ENABLED_U32                     (FLEXIO_CTRL_FLEXEN_MASK_U32)
#define FLEXIO_MODULE_DISABLED_U32                    ((uint32)0x00000000U)

/**
* @brief    FLEXIO Registers bits.
* @details  PIN register bit masks.
*/
#define FLEXIO_PIN_PDI_MASK_U32                       ((uint32)0x000000FFU)

/**
* @brief    FLEXIO Registers bits.
* @details  SHIFTSTAT register bit masks.
*/
#define FLEXIO_SHIFTSTAT_RWBITS_MASK_U32              ((uint32)0x0000000FU)
#define FLEXIO_SHIFTSTAT_SSF_MASK_U32                 ((uint32)0x0000000FU)
/* @violates @ref Reg_eSys_FlexIO_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTSTAT_SSF_U32(shifter)             ((uint32)((uint32)1U << (shifter)))

/**
* @brief    FLEXIO Registers bits.
* @details  SHIFTERR register bit masks.
*/
#define FLEXIO_SHIFTERR_RWBITS_MASK_U32               ((uint32)0x0000000FU)
#define FLEXIO_SHIFTERR_SEF_MASK_U32                  ((uint32)0x0000000FU)
/* @violates @ref Reg_eSys_FlexIO_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTERR_SEF_U32(shifter)              ((uint32)((uint32)1U << (shifter)))

/**
* @brief    FLEXIO Registers bits.
* @details  TIMSTAT register bit masks.
*/
#define FLEXIO_TIMSTAT_RWBITS_MASK_U32                ((uint32)0x0000000FU)
#define FLEXIO_TIMSTAT_TSF_MASK_U32                   ((uint32)0x0000000FU)
/* @violates @ref Reg_eSys_FlexIO_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_TIMSTAT_TSF_U32(timer)                 ((uint32)((uint32)1U << (timer)))

/**
* @brief    FLEXIO Registers bits.
* @details  SHIFTSIEN register bit masks.
*/
#define FLEXIO_SHIFTSIEN_RWBITS_MASK_U32              ((uint32)0x0000000FU)

#define FLEXIO_SHIFTSIEN_SSIE_MASK_U32                ((uint32)0x0000000FU)
#define FLEXIO_SHIFTSIEN_SSIE_DISABLE_U32             ((uint32)0x00000000U)
/* @violates @ref Reg_eSys_FlexIO_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTSIEN_SSIE_U32(shifter)            ((uint32)((uint32)1U << (shifter)))
/**
* @brief    FLEXIO Registers bits.
* @details  SHIFTEIEN register bit masks.
*/
#define FLEXIO_SHIFTEIEN_RWBITS_MASK_U32              ((uint32)0x0000000FU)

#define FLEXIO_SHIFTEIEN_SEIE_MASK_U32                ((uint32)0x0000000FU)
/* @violates @ref Reg_eSys_FlexIO_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_SHIFTEIEN_SEIE_U32(shifter)            ((uint32)((uint32)1U << (shifter)))

/**
* @brief    FLEXIO Registers bits.
* @details  TIMIEN register bit masks.
*/
#define FLEXIO_TIMIEN_RWBITS_MASK_U32                 ((uint32)0x0000000FU)

#define FLEXIO_TIMIEN_TEIE_MASK_U32                   ((uint32)0x0000000FU)
/* @violates @ref Reg_eSys_FlexIO_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define FLEXIO_TIMIEN_TEIE_U32(shifter)               ((uint32)((uint32)1U << (shifter)))

/**
* @brief    FLEXIO Registers bits.
* @details  SHIFTSDEN register bit masks.
*/
#define FLEXIO_SHIFTSDEN_RWBITS_MASK_U32              ((uint32)0x0000000FU)

#define FLEXIO_SHIFTSDEN_SSDE_MASK_U32                ((uint32)0x0000000FU)

/**
* @brief    FLEXIO Registers bits.
* @details  SHIFTCTL register bit masks.
*/
#define FLEXIO_SHIFTCTL_RWBITS_MASK_U32               ((uint32)0x03830787U)

#define FLEXIO_SHIFTCTL_TIMSEL_MASK_U32               ((uint32)0x03000000U)
#define FLEXIO_SHIFTCTL_TIMPOL_MASK_U32               ((uint32)0x00800000U)
#define FLEXIO_SHIFTCTL_PINCFG_MASK_U32               ((uint32)0x00030000U)
#define FLEXIO_SHIFTCTL_PINSEL_MASK_U32               ((uint32)0x00000700U)
#define FLEXIO_SHIFTCTL_PINPOL_MASK_U32               ((uint32)0x00000080U)
#define FLEXIO_SHIFTCTL_SMOD_MASK_U32                 ((uint32)0x00000007U)

#define FLEXIO0_TIM_SDO_MASTER_U32                    ((uint32)0x00830002u)
#define FLEXIO1_TIM_SDO_MASTER_U32                    ((uint32)0x02830402u)
#define FLEXIO0_TIM_SDO_SLAVE_U32                     ((uint32)0x00830002u)
#define FLEXIO1_TIM_SDO_SLAVE_U32                     ((uint32)0x02830402u)

#define FLEXIO0_TIM_SDI_MASTER_U32                    ((uint32)0x00000101u)
#define FLEXIO1_TIM_SDI_MASTER_U32                    ((uint32)0x02000501u)
#define FLEXIO0_TIM_SDI_SLAVE_U32                     ((uint32)0x00000101u)
#define FLEXIO1_TIM_SDI_SLAVE_U32                     ((uint32)0x02000501u)

#define FLEXIO0_TIM_CLK_MASTER_U32                    ((uint32)0x01C30201u)  
#define FLEXIO1_TIM_CLK_MASTER_U32                    ((uint32)0x09C30601u)
#define FLEXIO0_TIM_CLK_SLAVE_U32                     ((uint32)0x06C00203u)  
#define FLEXIO1_TIM_CLK_SLAVE_U32                     ((uint32)0x0EC00603u)

#define FLEXIO0_TIM_CS_MASTER_U32                     ((uint32)0x00030383u)
#define FLEXIO1_TIM_CS_MASTER_U32                     ((uint32)0x00030783u)

#define FLEXIO_TIM_CFG0_MASTER_U32                    ((uint32)0x01002222u)
#define FLEXIO_TIM_CFG1_MASTER_U32                    ((uint32)0x00001100u)
#define FLEXIO_TIM_CFG0_SLAVE_U32                     ((uint32)0x01200600u)
#define FLEXIO_TIM_CFG0_SLAVE_CPHA_U32                ((uint32)0x01206602u)

#define FLEXIO_CPOL_BIT_U32                           ((uint32)0x80000000u)
#define FLEXIO_CPHA_BIT_U32                           ((uint32)0x40000000u)
#define FLEXIO_FSIZE_BIT_U32                          ((uint32)0x000000FFu)
#define FLEXIO_LBF_BIT_U32                            ((uint32)0x00800000u)
#define FLEXIO_PSC_BIT_U32                            ((uint32)0x03800000u)
#define FLEXIO_SCK_DIVIDER                            ((uint32)0x000000FFu)
#define FLEXIO_CLK_CPOL_U32                           ((uint32)0x00000080u)
#define FLEXIO_CFG_CPHA1_MASTER_U32                   ((uint32)0x00000021u)
#define FLEXIO_CFG_CPHA1_SLAVE_U32                    ((uint32)0x00000001u)
#define FLEXIO0_TIM_SDO_MASTER_CPHA_U32               ((uint32)0x00030002u)
#define FLEXIO1_TIM_SDO_MASTER_CPHA_U32               ((uint32)0x02030402u)
#define FLEXIO0_TIM_SDO_SLAVE_CPHA_U32                ((uint32)0x00030002u)
#define FLEXIO1_TIM_SDO_SLAVE_CPHA_U32                ((uint32)0x02030402u)

#define FLEXIO0_TIM_SDI_MASTER_CPHA_U32               ((uint32)0x00800101u)
#define FLEXIO1_TIM_SDI_MASTER_CPHA_U32               ((uint32)0x02800501u)
#define FLEXIO0_TIM_SDI_SLAVE_CPHA_U32                ((uint32)0x00800101u)
#define FLEXIO1_TIM_SDI_SLAVE_CPHA_U32                ((uint32)0x02800501u)

#define FLEXIO0_ENABLE_REQUEST_DMA                    ((uint32)0x00000003u)
#define FLEXIO1_ENABLE_REQUEST_DMA                    ((uint32)0x0000000Cu)

#define FLEXIO_SHIFTCTL_TIMSEL_SHIFT_U32              ((uint32)24U)
#define FLEXIO_SHIFTCTL_PINSEL_SHIFT_U32              ((uint32)8U)

#define FLEXIO_SHIFT_ON_POSEDGE_OF_SHIFT_CLK_U32      ((uint32)0x00000000U)
#define FLEXIO_SHIFT_ON_NEGEDGE_OF_SHIFT_CLK_U32      (FLEXIO_SHIFTCTL_TIMPOL_MASK_U32)

#define FLEXIO_SHIFTER_PIN_OUTPUT_DISABLED_U32        ((uint32)0x00000000U)
#define FLEXIO_SHIFTER_PIN_OPEN_DRAIN_U32             ((uint32)0x00010000U)
#define FLEXIO_SHIFTER_PIN_BIDIRECTIONAL_OUTPUT_U32   ((uint32)0x00020000U)
#define FLEXIO_SHIFTER_PIN_OUTPUT_U32                 ((uint32)0x00030000U)
#define FLEXIO_SHIFTER_PIN_ACTIVE_HIGH_U32            ((uint32)0x00000000U)
#define FLEXIO_SHIFTER_PIN_ACTIVE_LOW_U32             (FLEXIO_SHIFTCTL_PINPOL_MASK_U32)

#define FLEXIO_SHIFTER_DISABLED_U32                   ((uint32)0x00000000U)
#define FLEXIO_SHIFTER_RECEIVE_MODE_U32               ((uint32)0x00000001U)
#define FLEXIO_SHIFTER_TRANSMIT_MODE_U32              ((uint32)0x00000002U)
#define FLEXIO_SHIFTER_MATCH_STORE_MODE_U32           ((uint32)0x00000004U)
#define FLEXIO_SHIFTER_MATCH_CONTINUOUS_MODE_U32      ((uint32)0x00000005U)

/**
* @brief    FLEXIO Registers bits.
* @details  SHIFTCFG register bit masks.
*/
#define FLEXIO_SHIFTCFG_RWBITS_MASK_U32               ((uint32)0x00000133U)

#define FLEXIO_SHIFTCFG_PWIDTH_MASK_U32               ((uint32)0x001F0000U)
#define FLEXIO_SHIFTCFG_LATST_MASK_U32                ((uint32)0x00000200U)
#define FLEXIO_SHIFTCFG_INSRC_MASK_U32                ((uint32)0x00000100U)
#define FLEXIO_SHIFTCFG_SSTOP_MASK_U32                ((uint32)0x00000030U)
#define FLEXIO_SHIFTCFG_SSTART_MASK_U32               ((uint32)0x00000003U)

#define FLEXIO_SHIFTER_INPUT_IS_PIN_U32               ((uint32)0x00000000U)
#define FLEXIO_SHIFTER_INPUT_IS_NEXT_SHIFTER_U32      (FLEXIO_SHIFTCFG_INSRC_MASK_U32)

#define FLEXIO_STOP_BIT_DIS_U32                       ((uint32)0x00000000U)
#define FLEXIO_STOP_BIT_RESERVED_U32                  ((uint32)0x00000010U)
#define FLEXIO_STOP_BIT_VALUE_0_U32                   ((uint32)0x00000020U)
#define FLEXIO_STOP_BIT_VALUE_1_U32                   ((uint32)0x00000030U)

#define FLEXIO_START_BIT_DIS_LOAD_ON_EN_U32           ((uint32)0x00000000U)
#define FLEXIO_START_BIT_DIS_LOAD_ON_SHIFT_U32        ((uint32)0x00000001U)
#define FLEXIO_START_BIT_VALUE_0_U32                  ((uint32)0x00000002U)
#define FLEXIO_START_BIT_VALUE_1_U32                  ((uint32)0x00000003U)

/**
* @brief    FLEXIO Registers bits.
* @details  TIMCTL register bit masks.
*/
#define FLEXIO_TIMCTL_RWBITS_MASK_U32                 ((uint32)0x0FC30783U)

#define FLEXIO_TIMCTL_TRGSEL_MASK_U32                 ((uint32)0x0F000000U)
#define FLEXIO_TIMCTL_TRGPOL_MASK_U32                 ((uint32)0x00800000U)
#define FLEXIO_TIMCTL_TRGSRC_MASK_U32                 ((uint32)0x00400000U)
#define FLEXIO_TIMCTL_PINCFG_MASK_U32                 ((uint32)0x00030000U)
#define FLEXIO_TIMCTL_PINSEL_MASK_U32                 ((uint32)0x00000700U)
#define FLEXIO_TIMCTL_PINPOL_MASK_U32                 ((uint32)0x00000080U)
#define FLEXIO_TIMCTL_PININS_MASK_U32                 ((uint32)0x00000040U)
#define FLEXIO_TIMCTL_ONETIM_MASK_U32                 ((uint32)0x00000020U)
#define FLEXIO_TIMCTL_TIMOD_MASK_U32                  ((uint32)0x00000003U)

#define FLEXIO_TIMCTL_TRGSEL_SHIFT_U32                ((uint32)24U)
#define FLEXIO_TIMCTL_PINSEL_SHIFT_U32                ((uint32)8U)

#define FLEXIO_TMR_TRIGGER_ACTIVE_HIGH_U32            ((uint32)0x00000000U)
#define FLEXIO_TMR_TRIGGER_ACTIVE_LOW_U32             (FLEXIO_TIMCTL_TRGPOL_MASK_U32)

#define FLEXIO_TMR_EXTERNAL_TRIGGER_U32               ((uint32)0x00000000U)
#define FLEXIO_TMR_INTERNAL_TRIGGER_U32               (FLEXIO_TIMCTL_TRGSRC_MASK_U32)

#define FLEXIO_TMR_PIN_OUTPUT_DISABLED_U32            ((uint32)0x00000000U)
#define FLEXIO_TMR_PIN_OPEN_DRAIN_U32                 ((uint32)0x00010000U)
#define FLEXIO_TMR_PIN_BIDIRECTIONAL_OUTPUT_U32       ((uint32)0x00020000U)
#define FLEXIO_TMR_PIN_OUTPUT_U32                     ((uint32)0x00030000U)

#define FLEXIO_TMR_SELECT_PIN0_U32                    ((uint32)0x00000000U)
#define FLEXIO_TMR_SELECT_PIN1_U32                    ((uint32)0x00000100U)
#define FLEXIO_TMR_SELECT_PIN2_U32                    ((uint32)0x00000200U)
#define FLEXIO_TMR_SELECT_PIN3_U32                    ((uint32)0x00000300U)

#define FLEXIO_TMR_PIN_ACTIVE_HIGH_U32                ((uint32)0x00000000U)
#define FLEXIO_TMR_PIN_ACTIVE_LOW_U32                 (FLEXIO_TIMCTL_PINPOL_MASK_U32)

#define FLEXIO_TMR_DISABLED_U32                       ((uint32)0x00000000U)
#define FLEXIO_TMR_DUAL_8BIT_BAUD_U32                 ((uint32)0x00000001U)
#define FLEXIO_TMR_DUAL_8BIT_PWM_U32                  ((uint32)0x00000002U)
#define FLEXIO_TMR_SINGLE_16BIT_COUNTER_U32           ((uint32)0x00000003U)

/**
* @brief    FLEXIO Registers bits.
* @details  TIMCFG register bit masks.
*/
#define FLEXIO_TIMCFG_RWBITS_MASK_U32                 ((uint32)0x03377732U)

#define FLEXIO_TIMCFG_TIMOUT_MASK_U32                 ((uint32)0x03000000U)
#define FLEXIO_TIMCFG_TIMDEC_MASK_U32                 ((uint32)0x00300000U)
#define FLEXIO_TIMCFG_TIMRST_MASK_U32                 ((uint32)0x00070000U)
#define FLEXIO_TIMCFG_TIMDIS_MASK_U32                 ((uint32)0x00007000U)
#define FLEXIO_TIMCFG_TIMENA_MASK_U32                 ((uint32)0x00000700U)
#define FLEXIO_TIMCFG_TSTOP_MASK_U32                  ((uint32)0x00000030U)
#define FLEXIO_TIMCFG_TRSTART_MASK_U32                ((uint32)0x00000002U)
#define FLEXIO_TIMCFG_TIMDEC_SHIFT_U32                ((uint32)20U)

#define FLEXIO_TMR_OUT_ONE_ONLY_ON_ENABLE_U32         ((uint32)0x00000000U)
#define FLEXIO_TMR_OUT_ZERO_ONLY_ON_ENABLE_U32        ((uint32)0x01000000U)
#define FLEXIO_TMR_OUT_ONE_ON_ENABLE_AND_RST_U32      ((uint32)0x02000000U)
#define FLEXIO_TMR_OUT_ZERO_ON_ENABLE_AND_RST_U32     ((uint32)0x03000000U)

#define FLEXIO_TMR_DECREMENT_ON_FLEXIO_CLK_U32          ((uint32)0x00000000U)   /* Kept for compatibility with other drivers */
#define FLEXIO_TMR_DECREMENT_ON_FLEXIO_CLK_DIV_1_U32    ((uint32)0x00000000U)
#define FLEXIO_TMR_DECREMENT_ON_FLEXIO_CLK_DIV_16_U32   ((uint32)0x00400000U)
#define FLEXIO_TMR_DECREMENT_ON_FLEXIO_CLK_DIV_256_U32  ((uint32)0x00500000U)
#define FLEXIO_TMR_DECREMENT_ON_TRG_INPUT_U32           ((uint32)0x00100000U)
#define FLEXIO_TMR_DECREMENT_ON_PIN_INPUT_U32           ((uint32)0x00200000U)
#define FLEXIO_TMR_DECREMENT_ON_TRG_INPUT_INV_U32       ((uint32)0x00300000U)

#define FLEXIO_TMR_NEVER_RST_U32                      ((uint32)0x00000000U)
#define FLEXIO_TMR_RST_ON_PIN_EQ_OUT_U32              ((uint32)0x00020000U)
#define FLEXIO_TMR_RST_ON_TRG_EQ_OUT_U32              ((uint32)0x00030000U)
#define FLEXIO_TMR_RST_ON_PIN_RISING_EDGE_U32         ((uint32)0x00040000U)
#define FLEXIO_TMR_RST_ON_TRG_RISING_EDGE_U32         ((uint32)0x00060000U)
#define FLEXIO_TMR_RST_ON_TRG_BOTH_EDGES_U32          ((uint32)0x00070000U)

#define FLEXIO_TMR_NEVER_DIS_U32                      ((uint32)0x00000000U)
#define FLEXIO_TMR_DIS_ON_PREV_TMR_DIS_U32            ((uint32)0x00001000U)
#define FLEXIO_TMR_DIS_ON_TMR_COMP_U32                ((uint32)0x00002000U)
#define FLEXIO_TMR_DIS_ON_TMR_COMP_AND_TRG_LOW_U32    ((uint32)0x00003000U)
#define FLEXIO_TMR_DIS_ON_PIN_EDGES_U32               ((uint32)0x00004000U)
#define FLEXIO_TMR_DIS_ON_PIN_EDGES_AND_TRG_HIGH_U32  ((uint32)0x00005000U)
#define FLEXIO_TMR_DIS_ON_TRG_FALLING_EDGE_U32        ((uint32)0x00006000U)

#define FLEXIO_TMR_ALWAYS_ENABLED_U32                 ((uint32)0x00000000U)
#define FLEXIO_TMR_EN_ON_PREV_TMR_EN_U32              ((uint32)0x00000100U)
#define FLEXIO_TMR_EN_ON_TRG_HIGH_U32                 ((uint32)0x00000200U)
#define FLEXIO_TMR_EN_ON_TRG_HIGH_AND_PIN_HIGH_U32    ((uint32)0x00000300U)
#define FLEXIO_TMR_EN_ON_PIN_RISING_U32               ((uint32)0x00000400U)
#define FLEXIO_TMR_EN_ON_PIN_RISING_AND_TRG_HIGH_U32  ((uint32)0x00000500U)
#define FLEXIO_TMR_EN_ON_TRG_RISING_EDGE_U32          ((uint32)0x00000600U)
#define FLEXIO_TMR_EN_ON_TRG_BOTH_EDGES_U32           ((uint32)0x00000700U)

#define FLEXIO_TMR_STOP_BIT_DISABLED_U32              ((uint32)0x00000000U)
#define FLEXIO_TMR_STOP_BIT_ON_TMR_COMP_U32           ((uint32)0x00000010U)
#define FLEXIO_TMR_STOP_BIT_ON_TMR_DIS_U32            ((uint32)0x00000020U)
#define FLEXIO_TMR_STOP_BIT_ON_TMR_COMP_AND_DIS_U32   ((uint32)0x00000030U)

#define FLEXIO_TMR_START_BIT_DISABLED_U32             ((uint32)0x00000000U)
#define FLEXIO_TMR_START_BIT_ENABLED_U32              (FLEXIO_TIMCFG_TRSTART_MASK_U32)

/**
* @brief    FLEXIO Registers bits.
* @details  TIMCMP register bit masks.
*/
#define FLEXIO_SEL_0_3_MASK_U32                          ((uint32)0x0FU)

#define FLEXIO_SEL_0_1_MASK_U32                          ((uint32)0x03U)
#define FLEXIO_SEL_2_3_MASK_U32                          ((uint32)0x0CU)
#define FLEXIO_0_CH_0                                    ((uint32)0U)
#define FLEXIO_0_CH_2                                    ((uint32)1U)

#define FLEXIO_TIMCMP_RWBITS_MASK_U32                 ((uint32)0x0000FFFFU)
#define FLEXIO_TIMCMP_BAUD_MASK_U32                   ((uint32)0x000000FFU)
#define FLEXIO_TIMCMP_BITS_NUMBER_MASK_U32            ((uint32)0x0000FF00U)
#define FLEXIO_TIMCMP_BITS_NUMBER_8_U32               ((uint32)0x00000F00U)
#define FLEXIO_TIMCMP_BITS_NUMBER_16_U32              ((uint32)0x00001F00U)

#define FLEXIO_READ_BIT_U8                            ((uint8)0x01U)

#define FLEXIO_SHIFTBUFBIS_SHIFT_VALUE_U32            ((uint32)24U)

#define FLEXIO_STOP_BYTE_VALUE_U32                    ((uint32)0x0U)

#define FLEXIO_LEAVE_SDA_FREE_U32                     ((uint32)0xFFU)

#define FLEXIO_SUBCHANNELS_PER_MODULE_U8              ((uint8)2U)

#define FLEXIO_FIRST_SUBCHANNEL_FLAGS_U32             ((uint32)0x3U)
#define FLEXIO_SECOND_SUBCHANNEL_FLAGS_U32            ((uint32)0xCU)

#define FLEXIO_GENERIC_IEN_RWBITS_MASK_U32            ((uint32)0x0000000FU)

#define FLEXIO_INVALID_HW_CHANNEL_U8                  ((uint8)0xFFU)

#define FLEXIO_DATA_8BITS_MASK_U32                    ((uint32)0x000000FFU)

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

#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_FLEXIO_H */

/** @} */
