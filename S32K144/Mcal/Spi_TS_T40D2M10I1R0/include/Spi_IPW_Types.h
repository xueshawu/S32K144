/**
*   @file    Spi_IPW_Types.h
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

#ifndef SPI_IPW_TYPES_H
#define SPI_IPW_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IPW_TYPES_VENDOR_ID                       43
#define SPI_IPW_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define SPI_IPW_TYPES_AR_RELEASE_MINOR_VERSION        3
#define SPI_IPW_TYPES_AR_RELEASE_REVISION_VERSION     1
#define SPI_IPW_TYPES_SW_MAJOR_VERSION                1
#define SPI_IPW_TYPES_SW_MINOR_VERSION                0
#define SPI_IPW_TYPES_SW_PATCH_VERSION                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief Internal structure used to manage the channel attributes for LPSPI IPV.
*/
typedef struct
{
    VAR(uint32, SPI_VAR) u32CMD; /**< @brief Channel attributes for CMD in TCR register. */
    VAR(uint32, SPI_VAR) u32FCR; /**< @brief Channel attributes for FIFO control in FCR register. */
    VAR(uint8, SPI_VAR)  u8DataWidth;       /**< @brief Channel attributes for data width. */
} Spi_Ipw_LPspiChannelAttributesConfigType;

/**
* @brief Internal structure used to manage the channel attributes for FLEXIO IPV.
*/
typedef struct
{
    VAR(uint8, SPI_VAR) u8LBF; /**< @brief Channel attributes for CMD in TCR register. */
    VAR(uint32, SPI_VAR) u32NumBitsInFrame;     /**< @brief The number of bits data in a frame tranfer  */
    VAR(uint32, SPI_VAR) u32DataWidth;       /**< @brief Channel attributes for data width. */
} Spi_Ipw_FlexIOChannelAttributesConfigType;

/**
* @brief Internal structure used to manage the LPSPI unit attributes.
*/
typedef struct
{
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    VAR(uint32, SPI_VAR) u32TCR[2];     /**< @brief Device attributes for TCRs. */
    VAR(uint32, SPI_VAR) u32CCR[2];     /**< @brief Device configuration for timing in CCR. */
    VAR(uint8, SPI_VAR)  u8DualClk;     /**< @brief Device attributes for Dual Clock Mode. */
#else
    VAR(uint32, SPI_VAR) u32TCR;        /**< @brief Device attributes for TCRs. */
    VAR(uint32, SPI_VAR) u32CCR;        /**< @brief Device configuration for timing in CCR. */
#endif /* #if (SPI_DUAL_CLOCK_MODE == STD_ON) */
    VAR(uint32, SPI_VAR) u32CFGR1;      /**< @brief Device CS idle setting. */
} Spi_Ipw_LPspiDeviceAttributesConfigType;

/**
* @brief Internal structure used to manage the DSPI unit attributes.
*/

/**
* @brief Internal structure used to manage the FLEXIO unit attributes.
*/
typedef struct
{
    VAR(uint8, SPI_VAR) u8CPOL; 
    VAR(uint8, SPI_VAR) u8CPHA;
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    VAR(uint32, SPI_VAR) u32PSC[2];
#else
    VAR(uint32, SPI_VAR) u32PSC;
#endif
    VAR(uint32, SPI_VAR) u32ShifterCFGConfigTX;     /**< @brief SHIFCFG config for TX. */
    VAR(uint32, SPI_VAR) u32ShifterCTLConfigTX;     /**< @brief SHIFCTL config for TX. */
    VAR(uint32, SPI_VAR) u32ShifterCFGConfigRX;     /**< @brief SHIFCFG config for RX. */
    VAR(uint32, SPI_VAR) u32ShifterCTLConfigRX;     /**< @brief SHIFCTL config for RX. */
    VAR(uint32, SPI_VAR) u32TimerCMPConfigCLK;      /**< @brief TIMCMP config for CLK. */
    VAR(uint32, SPI_VAR) u32TimerCFGConfigCLK;      /**< @brief TIMCFG config for CLK. */
    VAR(uint32, SPI_VAR) u32TimerCTLConfigCLK;      /**< @brief TIMCTL config for CLK. */
    VAR(uint32, SPI_VAR) u32TimerCMPConfigCS;       /**< @brief TIMCMP config for chip slect. */
    VAR(uint32, SPI_VAR) u32TimerCFGConfigCS;       /**< @brief TIMCFG config for chip slect. */
    VAR(uint32, SPI_VAR) u32TimerCTLConfigCS;       /**< @brief TIMCTL config for chip slect. */
} Spi_Ipw_FlexIODeviceAttributesConfigType;

/**
* @brief Internal structure used to manage LLD attributes.
*/
typedef struct
{
    /**< @brief Array of configuration channel attributes. */
    P2CONST(Spi_Ipw_LPspiChannelAttributesConfigType, SPI_VAR, SPI_APPL_CONST) pcLPspiChannelAttributesConfig;
    /**< @brief Array of configuration channel attributes. */
    P2CONST(Spi_Ipw_FlexIOChannelAttributesConfigType, SPI_VAR, SPI_APPL_CONST) pcFlexIOChannelAttributesConfig;
    /**< @brief Array of LPSPI units attributes. */
    P2CONST(Spi_Ipw_LPspiDeviceAttributesConfigType, SPI_VAR, SPI_APPL_CONST) *pcLPspiDeviceAttributesConfig;
    /**< @brief Array of FLEXIO units attributes. */
    P2CONST(Spi_Ipw_FlexIODeviceAttributesConfigType, SPI_VAR, SPI_APPL_CONST) *pcFlexIODeviceAttributesConfig;
} Spi_AttributesConfigType;

/**
* @brief Internal structure used to manage LLD attributes.
*/
typedef struct
{
    P2CONST(Spi_Ipw_LPspiDeviceAttributesConfigType, SPI_VAR, SPI_APPL_CONST) *pcLPspiExternalDeviceAttrs;
    P2CONST(Spi_Ipw_FlexIODeviceAttributesConfigType, SPI_VAR, SPI_APPL_CONST) *pcFlexIOExternalDeviceAttrs;
} Spi_Ipw_DeviceAttributesConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*SPI_IPW_TYPES_H*/

/** @} */
