/**
*   @file    Reg_eSys_FlexIO.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - FlexIO LLD header file.
*   @details Header file for FlexIO Registers and Macros Definitions.
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

#ifndef REG_ESYS_FLEXIOSPI_H
#define REG_ESYS_FLEXIOSPI_H

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
* @section Reg_eSys_FlexIO_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, This violation is due to function
* like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Reg_eSys_FlexIO_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character significance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Reg_eSys_FlexIO_h_REF_3
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @violates @ref Reg_eSys_FlexIO_h_REF_3 Precautions shall be taken in
*                order to prevent the contents of a header file being
*                included twice.
*/
#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_FlexIO.h
*/
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define REG_ESYS_FLEXIOSPI_VENDOR_ID_REGFLEX                    43  
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/               
#define REG_ESYS_FLEXIOSPI_AR_RELEASE_MAJOR_VERSION_REGFLEX     4
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define REG_ESYS_FLEXIOSPI_AR_RELEASE_MINOR_VERSION_REGFLEX     3
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define REG_ESYS_FLEXIOSPI_AR_RELEASE_REVISION_VERSION_REGFLEX  1
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define REG_ESYS_FLEXIOSPI_SW_MAJOR_VERSION_REGFLEX             1
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define REG_ESYS_FLEXIOSPI_SW_MINOR_VERSION_REGFLEX             0
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define REG_ESYS_FLEXIOSPI_SW_PATCH_VERSION_REGFLEX             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_FLEXIOSPI_AR_RELEASE_MAJOR_VERSION_REGFLEX != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_FLEXIOSPI_AR_RELEASE_MINOR_VERSION_REGFLEX != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_FlexIO.h and Reg_eSys.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*********************************FLEXIO REGISTERS*********************************/
/**
* @brief    SPI FLEXIO Registers bits.
* @details  Use for SPI FLEXIO.
*/
/* Shifter registers */
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_SHIFTCLT_TIMSEL_U32                ((uint32)0x00000000u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_SHIFTCLT_TIMSEL0_U32                ((uint32)0x00000000u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_SHIFTCLT_TIMSEL1_U32                ((uint32)0x01000000u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_SHIFTCLT_TIMSEL2_U32                ((uint32)0x02000000u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_SHIFTCLT_TIMSEL3_U32                ((uint32)0x03000000u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_SHIFTCLT_TIMSEL4_U32                ((uint32)0x04000000u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_SHIFTCLT_TIMSEL5_U32                ((uint32)0x05000000u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_SHIFTCLT_TIMSEL6_U32                ((uint32)0x06000000u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_SHIFTCLT_TIMSEL7_U32                ((uint32)0x07000000u)

/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_SHIFTCLT_SMOD_TX_U32             ((uint32)0x00000002u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_SHIFTCLT_SMOD_RX_U32             ((uint32)0x00000001u)

/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_SHIFTCFG_CPHA1_U32               ((uint32)0x00000021u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_SHIFTCFG_CPHA0_U32               ((uint32)0x00000000u)

/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_SHIFTCTL_TIMPOL_U32              ((uint32)0x00800000U)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_SHIFTCTL_PINPOL_HIGH_U32              ((uint32)0x00000080U)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_SHIFTCTL_PINPOL_LOW_U32              ((uint32)0x00000000U)

/* Timer registers */
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_TIMCTL_TMOD_16_COUNTER_U32           ((uint32)0x00000003u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_TIMCTL_TMOD_8_COUNTER_BAUD_U32       ((uint32)0x00000001u)

/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_TIMCTL_TRGSRC_U32                ((uint32)0x00400000u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_TIMCTL_PINPOL_LOW_U32            ((uint32)0x00000080u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_TIMCTL_TRGPOL_LOW_U32            ((uint32)0x00800000u)

/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_TIMCFG_CLK_MASTER_U32            ((uint32)0x01000222u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_TIMCFG_CS_MASTER_U32             ((uint32)0x00001100u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_TIMCFG_CLK_CS_SLAVE_U32          ((uint32)0x01200700u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_TIMCFG_CLK_CS_SLAVE_CPHA1_U32    ((uint32)0x01206602u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_TIMCFG_CS_CONTINUOS_U32          ((uint32)0x00003000u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_TIMCFG_CS_NON_CONTINUOS_U32      ((uint32)0x00002000u)

/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_TIMCMP_RWBITS_U32                ((uint32)0x0000FFFFU)

/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL_U32                         ((uint32)0x00000000u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL0_U32                         ((uint32)0x00000000u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL1_U32                         ((uint32)0x00000100u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL2_U32                         ((uint32)0x00000200u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL3_U32                         ((uint32)0x00000300u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL4_U32                         ((uint32)0x00000400u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL5_U32                         ((uint32)0x00000500u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL6_U32                         ((uint32)0x00000600u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL7_U32                         ((uint32)0x00000700u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL8_U32                         ((uint32)0x00000800u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL9_U32                         ((uint32)0x00000900u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL10_U32                        ((uint32)0x00000A00u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL11_U32                        ((uint32)0x00000B00u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL12_U32                        ((uint32)0x00000C00u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL13_U32                        ((uint32)0x00000D00u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL14_U32                        ((uint32)0x00000E00u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL15_U32                        ((uint32)0x00000F00u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL16_U32                        ((uint32)0x00001000u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL17_U32                        ((uint32)0x00001100u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL18_U32                        ((uint32)0x00001200u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL19_U32                        ((uint32)0x00001300u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL20_U32                        ((uint32)0x00001400u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL21_U32                        ((uint32)0x00001500u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL22_U32                        ((uint32)0x00001600u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL23_U32                        ((uint32)0x00001700u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL24_U32                        ((uint32)0x00001800u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL25_U32                        ((uint32)0x00001900u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL26_U32                        ((uint32)0x00001A00u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL27_U32                        ((uint32)0x00001B00u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL28_U32                        ((uint32)0x00001C00u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL29_U32                        ((uint32)0x00001D00u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL30_U32                        ((uint32)0x00001E00u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINSEL31_U32                        ((uint32)0x00001F00u)

/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINCFG_OUT_U32                       ((uint32)0x00030000u)
/*
* @violates @ref Reg_eSys_FlexIO_h_REF_2 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration.
*/
#define SPI_FLEXIO_PINCFG_IN_U32                        ((uint32)0x00000000u)

/*
* @violates @ref Spi_Cfg_h_REF_1 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration. 
*/
#define SPI_FLEXIO_DATA_WIDTH_8     ((uint32)15u) /* DataWidth = (15+1)/2 = 8  */
/*
* @violates @ref Spi_Cfg_h_REF_1 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration. 
*/
#define SPI_FLEXIO_DATA_WIDTH_16    ((uint32)31u) /* DataWidth = (31+1)/2 = 16 */
/*
* @violates @ref Spi_Cfg_h_REF_1 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration. 
*/
#define SPI_FLEXIO_DATA_WIDTH_32    ((uint32)63u) /* DataWidth = (63+1)/2 = 32 */

/* LSB first or MSB first define*/
#define SPI_FLEXIO_LSB_U8  ((uint8)1u)
#define SPI_FLEXIO_MSB_U8  ((uint8)0u)

/* CPOL and CPHA */
#define SPI_FLEXIO_CPOL_LOW_U8         ((uint8)0u)
#define SPI_FLEXIO_CPOL_HIGH_U8        ((uint8)1u)

#define SPI_FLEXIO_CPHA_LEADING_U8     ((uint8)1u)
#define SPI_FLEXIO_CPHA_TRAILING_U8    ((uint8)0u)

/* Reset value */
#define SPI_FLEXIO_CLEAR_REGISTER_U32   ((uint32)0u)

/* Reset flags value */
#define SPI_FLEXIO_CLEAR_FLAG_U8   ((uint8)0u)


/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_FLEXIO_H */

/** @} */
