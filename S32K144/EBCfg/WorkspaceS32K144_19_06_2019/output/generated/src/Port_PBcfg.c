/**
* @file    Port_PBcfg.c
* @implements Port_PBcfg.c_Artifact
*
* @version 1.0.1
* @brief   AUTOSAR Port - PORT driver configuration.
* @details This file contains the PORT driver postbuild configuration.
*
* @addtogroup  Port
* @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : PORT_CI
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
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_PBCFG_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*
* @section PORT_PBCFG_REF_2
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or 
* functions at file scope shall have internal linkage unless external linkage is required. 
* The functions/variables are part of PORT API.
*
* @section PORT_PBCFG_REF_3
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section PORT_PBCFG_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character signifiance and case sensitivity are supported for external identifiers.
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
* @details The integration of incompatible files shall be avoided.
*
*/
#define PORT_VENDOR_ID_PBCFG_C                       43
/** @violates @ref PORT_PBCFG_REF_4 The used compilers use more than 31 chars for identifiers. */
#define PORT_AR_RELEASE_MAJOR_VERSION_PBCFG_C        4
/** @violates @ref PORT_PBCFG_REF_4 The used compilers use more than 31 chars for identifiers. */
#define PORT_AR_RELEASE_MINOR_VERSION_PBCFG_C        3

/** @violates @ref PORT_PBCFG_REF_4 The used compilers use more than 31 chars for identifiers. */
#define PORT_AR_RELEASE_REVISION_VERSION_PBCFG_C     1
#define PORT_SW_MAJOR_VERSION_PBCFG_C                1
#define PORT_SW_MINOR_VERSION_PBCFG_C                0
#define PORT_SW_PATCH_VERSION_PBCFG_C                1

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/* Check if Port_PBcfg.c and Port.h are of the same vendor */
#if (PORT_VENDOR_ID_PBCFG_C != PORT_VENDOR_ID)
    #error "Port_PBcfg.c and Port.h have different vendor ids"
#endif
/* Check if Port_PBcfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_PBCFG_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_PBCFG_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Port_PBcfg.c and Port.h are different"
#endif

/* Check if Port_PBcfg.c and Port.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_PBCFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_PBCFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_PBCFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_PBcfg.c and Port.h are different"
#endif

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/
/**
* @brief The number of configured Digital Filter Ports
*/
/** @violates @ref PORT_PBCFG_REF_4 The used compilers use more than 31 chars for identifiers. */
#define PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS_U8         (0U)

/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/

#define PORT_START_SEC_CONFIG_DATA_16
/** @violates @ref PORT_PBCFG_REF_1 only preprocessor statements and comments before "#include". */
/** @violates @ref PORT_PBCFG_REF_3 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"

#if (0UL != PORT_MAX_UNUSED_PADS_U16)
/**
* @brief NoDefaultPadsArray is an array containing Unimplemented pads and User pads
* @violates @ref PORT_PBCFG_REF_4 The used compilers use more than 31 chars for identifiers.
*/
static CONST(uint16, PORT_CONST) Port_au16NoUnUsedPadsArrayDefault[PORT_MAX_UNUSED_PADS_U16]=
{

};
#endif

#define PORT_STOP_SEC_CONFIG_DATA_16
/** @violates @ref PORT_PBCFG_REF_1 only preprocessor statements and comments before "#include". */
/** @violates @ref PORT_PBCFG_REF_3 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref PORT_PBCFG_REF_1 only preprocessor statements and comments before "#include". */
/** @violates @ref PORT_PBCFG_REF_3 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"
/**
 * @brief Default Configuration for Pins not initialized
 */
static CONST(Port_Port_Ci_UnUsedPinConfigType, PORT_CONST) Port_UnUsedPin =
{
    /* @note: Configuration of Default pin */
    (uint32)0x00000100, (Port_PinDirectionType)1, (uint8)0
};

/**
* @brief Pin default configuration data for configPB
*/
static CONST(Port_Port_Ci_PinConfigType, PORT_CONST) Port_aPinConfigDefault[PORT_MAX_CONFIGURED_PADS_U16]=
{
    {(Port_InternalPinIdType)0, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)2, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)1, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)2, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)2, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)3, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)4, (uint32)0x00000700, (uint8)0, (Port_PinDirectionType)1, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)5, (uint32)0x00000700, (uint8)0, (Port_PinDirectionType)1, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)6, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)7, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)8, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)9, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)10, (uint32)0x00000700, (uint8)0, (Port_PinDirectionType)2, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)11, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)12, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)13, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)14, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)15, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)16, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)17, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)32, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)33, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)34, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)35, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)36, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)37, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)38, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)39, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)40, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)41, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)42, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)43, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)44, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)45, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)46, (uint32)0x00000300, (uint8)0, (Port_PinDirectionType)2, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)47, (uint32)0x00000300, (uint8)0, (Port_PinDirectionType)1, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)48, (uint32)0x00000300, (uint8)0, (Port_PinDirectionType)2, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)49, (uint32)0x00000300, (uint8)1, (Port_PinDirectionType)2, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)64, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)65, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)66, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)67, (uint32)0x00000000, (uint8)2, (Port_PinDirectionType)0, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)68, (uint32)0x00000700, (uint8)0, (Port_PinDirectionType)1, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)69, (uint32)0x00000700, (uint8)0, (Port_PinDirectionType)1, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)70, (uint32)0x00000200, (uint8)0, (Port_PinDirectionType)1, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)71, (uint32)0x00000200, (uint8)0, (Port_PinDirectionType)1, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)72, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)73, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)74, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)75, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)76, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)77, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)78, (uint32)0x00000000, (uint8)2, (Port_PinDirectionType)0, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)79, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)80, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)81, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)96, (uint32)0x00000200, (uint8)0, (Port_PinDirectionType)1, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)97, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)98, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)99, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)100, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)101, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)102, (uint32)0x00000200, (uint8)0, (Port_PinDirectionType)1, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)103, (uint32)0x00000200, (uint8)0, (Port_PinDirectionType)1, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)104, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)105, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)106, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)107, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)108, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)109, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)110, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)111, (uint32)0x00000200, (uint8)0, (Port_PinDirectionType)1, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)112, (uint32)0x00000200, (uint8)0, (Port_PinDirectionType)1, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)113, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)128, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)129, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)130, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)131, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)132, (uint32)0x00000500, (uint8)0, (Port_PinDirectionType)1, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)133, (uint32)0x00000500, (uint8)0, (Port_PinDirectionType)1, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)134, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)135, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)136, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)137, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)138, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)139, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)140, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)141, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)142, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)143, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)144, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE}

};

#if (0UL != PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS_U8)
static CONST(Port_DigitalFilter_ConfigType, PORT_CONST) Port_aDigitalFilter[PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS_U8]=
{

};
#endif /* (0UL != PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS_U8) */

/**
* @brief This table contains all the Configured Port Pin parameters and the
*        number of Port Pins configured by the tool for the post-build mode
* @violates @ref PORT_PBCFG_REF_2 This warning appears when defining functions or objects 
* that will be used by the upper layers.
*/

CONST(Port_ConfigType, PORT_CONST) PortConfigSet =

{
    PORT_MAX_CONFIGURED_PADS_U16,
    PORT_MAX_UNUSED_PADS_U16,
#if (0UL != PORT_MAX_UNUSED_PADS_U16)
    Port_au16NoUnUsedPadsArrayDefault,
#else
    NULL_PTR,
#endif
    &Port_UnUsedPin,
    Port_aPinConfigDefault,
    PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS_U8,
#if (0UL != PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS_U8)
    Port_aDigitalFilter
#else
    NULL_PTR
#endif
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref PORT_PBCFG_REF_1 only preprocessor statements and comments before "#include". */
/** @violates @ref PORT_PBCFG_REF_3 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"
/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/


#ifdef __cplusplus
}
#endif
/** @} */

/* End of File */
