/**
*   @file           Pwm_FlexIO.c
*   @version        1.0.1
*
*   @brief          AUTOSAR Pwm - PWM FlexIO API.
*   @details        PWM FlexIO API.
*
*   @addtogroup     PWM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : Ftm
*   Dependencies         : none
*
*   AUTOSAR Version      : 4.3.1
*   AUTOSAR Revision     : ASR_REL_4_3_REV_0001
*   AUTOSAR Conf.Variant :
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
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_FlexIO_C_REF_1
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Pwm_FlexIO_C_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
* that 31 character significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Pwm_FlexIO_C_REF_3
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
* 
* @section Pwm_FlexIO_C_REF_4
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before 'include'
* MemMap.h included after each section define in order to set the current memory section
* 
* @section Pwm_FlexIO_C_REF_5
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned int to pointer
* This rule can not be avoided because it appears when addressing memory mapped registers or other hardware specific feature
*
* @section Pwm_FlexIO_C_REF_6
* Violates MISRA 2004 Required Rule 10.3, The value of a complex expression of integer type may only be cast to type that is narrower and of the same
* signedness as the underlying type of the expression.
* This is not a violation since the expression is used to access a 32bit register using a 8 bit channel value.
*
* @section Pwm_FlexIO_C_REF_7
* Violates MISRA 2004 Advisory Rule 11.3, cast from unsigned int to pointer
* This rule can not be avoided because it appears when addressing memory mapped registers or other hardware specific feature
*
* @section Pwm_FlexIO_C_REF_8
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Pwm_FlexIO_C_REF_9
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not
* be implicitly converted to a different underlying type.
*
*/




/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Std_Types.h"

#include "Reg_eSys_FlexIO.h"

#include "Pwm_FlexIO.h"

#include "Pwm_Ipw_Types.h"
#include "Pwm_Ipw_Notif.h"

#include "CDD_Mcl.h"

#ifndef USER_MODE_REG_PROT_ENABLED
#define USER_MODE_REG_PROT_ENABLED  (PWM_REGISTER_PROTECTION)
#endif
#include "SilRegMacros.h"
#include "SchM_Pwm.h"



/*==================================================================================================
*                            SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @{
* @file         Pwm_FlexIO.c
*/
#define PWM_FLEXIO_VENDOR_ID_C                          43
/** @violates @ref Pwm_FlexIO_C_REF_2 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Pwm_FlexIO_C_REF_1 Identifier exceeds 31 chars. */
#define PWM_FLEXIO_AR_RELEASE_MAJOR_VERSION_C           4
/** @violates @ref Pwm_FlexIO_C_REF_2 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Pwm_FlexIO_C_REF_1 Identifier exceeds 31 chars. */
#define PWM_FLEXIO_AR_RELEASE_MINOR_VERSION_C           3
/** @violates @ref Pwm_FlexIO_C_REF_2 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Pwm_FlexIO_C_REF_1 Identifier exceeds 31 chars. */
#define PWM_FLEXIO_AR_RELEASE_REVISION_VERSION_C        1
#define PWM_FLEXIO_SW_MAJOR_VERSION_C                   1
#define PWM_FLEXIO_SW_MINOR_VERSION_C                   0
#define PWM_FLEXIO_SW_PATCH_VERSION_C                   1
/**@}*/



/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h are of the same AUTOSAR version */
    #if ((PWM_FLEXIO_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_FLEXIO_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Pwm_FlexIO.c and Std_Types.h are different."
    #endif
    
    /* Check if source file and SilRegMacros.h are of the same AUTOSAR version */
    #if ((PWM_FLEXIO_AR_RELEASE_MAJOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_FLEXIO_AR_RELEASE_MINOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Pwm_FlexIO.c and SilRegMacros.h are different."
    #endif
    
    /* Check if source file and Reg_eSys_FlexIO.h are of the same AUTOSAR version */
    #if ((PWM_FLEXIO_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_FLEXIO_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_FLEXIO_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Pwm_FlexIO.c and Reg_eSys_FlexIO.h are different."
    #endif
#endif

/* Check if source file and Pwm_FlexIO.h header file are of the same vendor */
#if (PWM_FLEXIO_VENDOR_ID_C != PWM_FLEXIO_VENDOR_ID)
    #error "Verdor IDs of Pwm_FlexIO.c and Pwm_FlexIO.h are different."
#endif

/* Check if source file and Pwm_FlexIO.h header file are of the same AUTOSAR version */
#if ((PWM_FLEXIO_AR_RELEASE_MAJOR_VERSION_C != PWM_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_FLEXIO_AR_RELEASE_MINOR_VERSION_C != PWM_FLEXIO_AR_RELEASE_MINOR_VERSION) || \
     (PWM_FLEXIO_AR_RELEASE_REVISION_VERSION_C != PWM_FLEXIO_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_FlexIO.c and Pwm_FlexIO.h are different."
#endif

/* Check if source file and Pwm_FlexIO.h header file are of the same software version */
#if ((PWM_FLEXIO_SW_MAJOR_VERSION_C != PWM_FLEXIO_SW_MAJOR_VERSION) || \
     (PWM_FLEXIO_SW_MINOR_VERSION_C != PWM_FLEXIO_SW_MINOR_VERSION) || \
     (PWM_FLEXIO_SW_PATCH_VERSION_C != PWM_FLEXIO_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_FlexIO.c and Pwm_FlexIO.h are different."
#endif

/* Check if source file and Pwm_Ipw_Types.h are of the same vendor */
#if (PWM_FLEXIO_VENDOR_ID_C != PWM_IPW_TYPES_VENDOR_ID)
    #error "Verdor IDs of Pwm_FlexIO.c and Pwm_Ipw_Types.h are different."
#endif

/* Check if source file and Pwm_Ipw_Types.h are of the same AUTOSAR version */
#if ((PWM_FLEXIO_AR_RELEASE_MAJOR_VERSION_C != PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_FLEXIO_AR_RELEASE_MINOR_VERSION_C != PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_FLEXIO_AR_RELEASE_REVISION_VERSION_C != PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_FlexIO.c and Pwm_Ipw_Types.h are different."
#endif

/* Check if source file and Pwm_Ipw_Types.h are of the same software version */
#if ((PWM_FLEXIO_SW_MAJOR_VERSION_C != PWM_IPW_TYPES_SW_MAJOR_VERSION) || \
     (PWM_FLEXIO_SW_MINOR_VERSION_C != PWM_IPW_TYPES_SW_MINOR_VERSION)  || \
     (PWM_FLEXIO_SW_PATCH_VERSION_C != PWM_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_FlexIO.c and Pwm_Ipw_Types.h are different."
#endif

/* Check if source file and Pwm_Ipw_Notif.h are of the same vendor */
#if (PWM_FLEXIO_VENDOR_ID_C != PWM_IPW_NOTIF_VENDOR_ID)
    #error "Verdor IDs of Pwm_FlexIO.c  and Pwm_Ipw_Notif.h are different."
#endif

/* Check if source file and Pwm_Ipw_Notif.h are of the same AUTOSAR version */
#if ((PWM_FLEXIO_AR_RELEASE_MAJOR_VERSION_C != PWM_IPW_NOTIF_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_FLEXIO_AR_RELEASE_MINOR_VERSION_C != PWM_IPW_NOTIF_AR_RELEASE_MINOR_VERSION) || \
     (PWM_FLEXIO_AR_RELEASE_REVISION_VERSION_C != PWM_IPW_NOTIF_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_FlexIO.c  and Pwm_Ipw_Notif.h are different."
#endif

/* Check if source file and Pwm_Ipw_Notif.h are of the same software version */
#if ((PWM_FLEXIO_SW_MAJOR_VERSION_C != PWM_IPW_NOTIF_SW_MAJOR_VERSION) || \
     (PWM_FLEXIO_SW_MINOR_VERSION_C != PWM_IPW_NOTIF_SW_MINOR_VERSION)  || \
     (PWM_FLEXIO_SW_PATCH_VERSION_C != PWM_IPW_NOTIF_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_FlexIO.c and Pwm_Ipw_Notif.h are different."
#endif


#if (PWM_FLEXIO_USED == STD_ON)
    


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define PWM_FLEXIO_TIMERS_PER_MODULE                ((uint8)4U)

#define FLEXIO_TIMCMP_CMP_LOW_U32                   ((uint32)0x0000FF00)

#define FLEXIO_TIMCMP_CMP_HIGH_U32                  ((uint32)0x000000FF)

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

#define PWM_START_SEC_VAR_NO_INIT_16

/*
* @violates @ref Pwm_FlexIO_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
/*
* @violates @ref Pwm_FlexIO_C_REF_4 Only preprocessor statements and comments before 'include'
*/
#include "Pwm_MemMap.h"

/**
* @brief        Array of duty cycle values of each channel
*
*/
static VAR(uint16, PWM_VAR) Pwm_FlexIO_au16DutyCycle[PWM_FLEXIO_CHANNEL_NO];

#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
static VAR(uint16, PWM_VAR) Pwm_FlexIO_au16NextDutyCycle[PWM_FLEXIO_CHANNEL_NO];
#endif

#define PWM_STOP_SEC_VAR_NO_INIT_16

/*
* @violates @ref Pwm_FlexIO_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
/*
* @violates @ref Pwm_FlexIO_C_REF_4 Only preprocessor statements and comments before 'include'
*/
#include "Pwm_MemMap.h"


#define PWM_START_SEC_VAR_NO_INIT_8

/*
* @violates @ref Pwm_FlexIO_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
/*
* @violates @ref Pwm_FlexIO_C_REF_4 Only preprocessor statements and comments before 'include'
*/
#include "Pwm_MemMap.h"

/**
* @brief        Array of channel status: NO_INIT, RUNNING, IDLE
*
*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
static VAR(uint8, PWM_VAR) Pwm_FlexIO_au8ChannelStatus[PWM_FLEXIO_CHANNEL_NO];
#endif

#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
static volatile VAR(uint8, PWM_VAR) Pwm_FlexIO_au8NextChannelStatus[PWM_FLEXIO_CHANNEL_NO];
#endif

/**
* @brief        Array of timer compare register (TIMCMP) high nibble value of each channel
*
*/
static VAR(uint8, PWM_VAR) Pwm_FlexIO_au8HighNib[PWM_FLEXIO_CHANNEL_NO];

/**
* @brief        Array of timer compare register (TIMCMP) low nibble value of each channel
*
*/
static VAR(uint8, PWM_VAR) Pwm_FlexIO_au8LowNib[PWM_FLEXIO_CHANNEL_NO];


#define PWM_STOP_SEC_VAR_NO_INIT_8

/*
* @violates @ref Pwm_FlexIO_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
/*
* @violates @ref Pwm_FlexIO_C_REF_4 Only preprocessor statements and comments before 'include'
*/
#include "Pwm_MemMap.h"


#define PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED

/*
* @violates @ref Pwm_FlexIO_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
/*
* @violates @ref Pwm_FlexIO_C_REF_4 Only preprocessor statements and comments before 'include'
*/
#include "Pwm_MemMap.h"

/**
* @brief        Array of period values for each channel
*
*/
static VAR(Pwm_PeriodType, PWM_VAR) Pwm_FlexIO_aPeriod[PWM_FLEXIO_CHANNEL_NO];
#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
static VAR(Pwm_PeriodType, PWM_VAR) Pwm_FlexIO_aNextPeriod[PWM_FLEXIO_CHANNEL_NO];
#endif

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Array of values used to store channel notification types.
*               The value 0 will be interpreted as NO EDGE; value of 1 will be considered match on 
*/
static volatile VAR(Pwm_FlexIO_EdgeStateType, PWM_VAR) Pwm_FlexIO_aNotification[PWM_FLEXIO_CHANNEL_NO];


/**
* @brief        Array of polarity for each channel
*
*/
static VAR(Pwm_OutputStateType, PWM_VAR) Pwm_FlexIO_aPolarity[PWM_FLEXIO_CHANNEL_NO];
#endif

#define PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

/*
* @violates @ref Pwm_FlexIO_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
/*
* @violates @ref Pwm_FlexIO_C_REF_4 Only preprocessor statements and comments before 'include'
*/
#include "Pwm_MemMap.h"



/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define PWM_START_SEC_CODE

/*
* @violates @ref Pwm_FlexIO_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
/*
* @violates @ref Pwm_FlexIO_C_REF_4 Only preprocessor statements and comments before 'include'
*/
#include "Pwm_MemMap.h"

static FUNC(void, PWM_CODE) Pwm_FlexIO_CalculateTIMCMPRegVal
(
    VAR         (uint8,                         AUTOMATIC)                      u8ArrayIdx
);

#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
static FUNC(void, PWM_CODE) Pwm_FlexIO_UpdateRegister
(
    VAR         (uint8,                         AUTOMATIC)                      nHwTimerId
);
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/**
* @brief        This function calculate timer compare register (TIMCMP) value.
* @details      This function will use period and duty cycle values contain in internal variable
*               to calculate the register TIMCMP, the result will be stored and written.
*
* @param        u8ArrayIdx          Array index to access in internal variable
*               
*
* @return       void
*
*/
static FUNC(void, PWM_CODE) Pwm_FlexIO_CalculateTIMCMPRegVal
(
    VAR         (uint8,                         AUTOMATIC)                      u8ArrayIdx
)
{
    
    /** @brief  Variable stores period value */
    VAR         (Pwm_PeriodType,                AUTOMATIC)                      nPeriod; 
    /** @brief  Variable stores duty cycle value */
    VAR         (uint16,                        AUTOMATIC)                      u16DutyCycle;
    
    
    /* Get channel period */
    nPeriod = Pwm_FlexIO_aPeriod[u8ArrayIdx];
    
    /* Get channel duty cycle */
    u16DutyCycle = Pwm_FlexIO_au16DutyCycle[u8ArrayIdx];
    
    
    /* Calculate 8-bit low TIMCMP value */
    Pwm_FlexIO_au8LowNib[u8ArrayIdx] = (uint8)(((uint32)nPeriod * u16DutyCycle) >> 15U);
    
    /* Calculate 8-bit high TIMCMP value */
    Pwm_FlexIO_au8HighNib[u8ArrayIdx] = (uint8)nPeriod - Pwm_FlexIO_au8LowNib[u8ArrayIdx];
    
}




/*=============================================================================================*/
#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
/**
* @brief        This function update registers for the specified FlexIO channel
* @details      This function update registers for the specified FlexIO channel
*
* @param        nHwChannelId      - PWM hardware channel id
*               nHwTimerId        - PWM hardware timer id
*
* @return       void
*
*/
/* @violates @ref Pwm_FlexIO_C_REF_8 This is not dead code */
static FUNC(void, PWM_CODE) Pwm_FlexIO_UpdateRegister
(
    VAR         (uint8,                         AUTOMATIC)                      nHwTimerId
)
{
    /** @brief  Array index value to access element of internal variable */
    VAR         (uint8,                         AUTOMATIC)                      u8ArrayIdx;
    /** @brief  Variable store TIMCMP register value */
    VAR         (uint32,                        AUTOMATIC)                      u32TIMCMPRegVal;


    /* Reset register temporary variable */
    u32TIMCMPRegVal = (uint32)0U;
    
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_47();
    
    /* Get array index of this channel to access to internal variable */
    u8ArrayIdx = (uint8)nHwTimerId;
    
    /* If next channel status is running, set it into running status */
    if ((uint8)0U != (Pwm_FlexIO_au8NextChannelStatus[u8ArrayIdx] & PWM_FLEXIO_CHANNEL_CHANGE_RUNNING))
    {
        /* Store new period into internal variable */
        if ((uint8)0U != (Pwm_FlexIO_au8NextChannelStatus[u8ArrayIdx] & PWM_FLEXIO_CHANNEL_CHANGE_PERIOD))
        {
            Pwm_FlexIO_aPeriod[u8ArrayIdx] = Pwm_FlexIO_aNextPeriod[u8ArrayIdx];
            Pwm_FlexIO_aNextPeriod[u8ArrayIdx] = (Pwm_PeriodType)0U;
        }

        /* Store new duty cycle into internal variable */
        if ((uint8)0U != (Pwm_FlexIO_au8NextChannelStatus[u8ArrayIdx] & PWM_FLEXIO_CHANNEL_CHANGE_DUTY))
        {
            Pwm_FlexIO_au16DutyCycle[u8ArrayIdx] = Pwm_FlexIO_au16NextDutyCycle[u8ArrayIdx];
            Pwm_FlexIO_au16NextDutyCycle[u8ArrayIdx] = (uint16)0U;
        }

        /* Calculate the value intended to write to TIMCMP register */
        Pwm_FlexIO_CalculateTIMCMPRegVal(u8ArrayIdx);


        /* If period is 0 then it will be treated as 0% duty cycle, the output state will be
           the inversion of polarity, the same case for period not 0 and 0% duty cycle */
        if (
            ((Pwm_PeriodType)0U == Pwm_FlexIO_aPeriod[u8ArrayIdx]) || \
            (((Pwm_PeriodType)0U != Pwm_FlexIO_aPeriod[u8ArrayIdx]) && ((PWM_FLEXIO_DUTY_0 == Pwm_FlexIO_au16DutyCycle[u8ArrayIdx]) || ((uint8)0U == Pwm_FlexIO_au8LowNib[u8ArrayIdx])))
           )
        {
            /* Timer pin output disabled */
            /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
            /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_CLEAR32(FLEXIO_TIMCTLn_ADDR32((uint32)nHwTimerId), FLEXIO_TIMCTL_PINCFG_MASK_U32);
            
            /* Disable timer mode */
            /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
            /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_CLEAR32(FLEXIO_TIMCTLn_ADDR32((uint32)nHwTimerId), FLEXIO_TIMCTL_TIMOD_MASK_U32);

            /* Set TIMCMP register value from high nibble and low nibble */
            u32TIMCMPRegVal = (uint32)(FLEXIO_TIMCMP_CMP_LOW_U32);
            
            /* Write TIMCMP register */
            /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
            /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)nHwTimerId), u32TIMCMPRegVal);
            
            /* Enable timer mode */
            /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
            /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_SET32(FLEXIO_TIMCTLn_ADDR32((uint32)nHwTimerId), FLEXIO_TMR_DUAL_8BIT_PWM_U32);

            /* Timer pin output enable */
            /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
            /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_SET32(FLEXIO_TIMCTLn_ADDR32((uint32)nHwTimerId), FLEXIO_TMR_PIN_OUTPUT_U32);
            
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
            /* Because of no pulse, notification status will be stacked temporarily until set pulse back */
            if (PWM_FLEXIO_CHF_IRQ_EDGE == Pwm_FlexIO_aNotification[u8ArrayIdx])
            {
                Pwm_FlexIO_aNotification[u8ArrayIdx] = PWM_FLEXIO_CHF_IRQ_IDLE;
            }
            
            /* Clear interrupt enable in TIMIEN register */
            Mcl_Flexio_WriteTimIen((uint8)(1U << nHwTimerId), (uint8)0U);
                
            /* Clear interrupt flag in TIMSTAT register */
            Mcl_Flexio_ClearTimStat((uint8)(1U << nHwTimerId));
#endif
        }
        /* If period is not 0 and 100% duty cycle the output state will be the equal of polarity */
        else if (((uint8)0U != Pwm_FlexIO_aPeriod[u8ArrayIdx]) && (PWM_FLEXIO_DUTY_100 == Pwm_FlexIO_au16DutyCycle[u8ArrayIdx]))
        {
            /* Timer pin output disabled */
            /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
            /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_CLEAR32(FLEXIO_TIMCTLn_ADDR32((uint32)nHwTimerId), FLEXIO_TIMCTL_PINCFG_MASK_U32);
           
            /* Disable timer mode */
            /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
            /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_CLEAR32(FLEXIO_TIMCTLn_ADDR32((uint32)nHwTimerId), FLEXIO_TIMCTL_TIMOD_MASK_U32);
            
            /* Set TIMCMP register value from high nibble and low nibble */
            u32TIMCMPRegVal = (uint32)(FLEXIO_TIMCMP_CMP_HIGH_U32);
            
            /* Write TIMCMP register */
            /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
            /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)nHwTimerId), u32TIMCMPRegVal);
            
            /* Enable timer mode */
            /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
            /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_SET32(FLEXIO_TIMCTLn_ADDR32((uint32)nHwTimerId), FLEXIO_TMR_DUAL_8BIT_PWM_U32);
            
            /* Timer pin output enable */
            /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
            /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_SET32(FLEXIO_TIMCTLn_ADDR32((uint32)nHwTimerId), FLEXIO_TMR_PIN_OUTPUT_U32);
            
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
            /* Because of no pulse, notification status will be stacked temporarily until set pulse back */
            if (PWM_FLEXIO_CHF_IRQ_EDGE == Pwm_FlexIO_aNotification[u8ArrayIdx])
            {
                Pwm_FlexIO_aNotification[u8ArrayIdx] = PWM_FLEXIO_CHF_IRQ_IDLE;
            }
            
            /* Clear interrupt enable in TIMIEN register */
            Mcl_Flexio_WriteTimIen((uint8)(1U << nHwTimerId), (uint8)0U);
                
            /* Clear interrupt flag in TIMSTAT register */
            Mcl_Flexio_ClearTimStat((uint8)(1U << nHwTimerId));
#endif
        }
        /* If period is not 0 and neither 0% nor 100% duty cycle */
        else if (((uint8)0U != Pwm_FlexIO_aPeriod[u8ArrayIdx]) && (PWM_FLEXIO_DUTY_100 != Pwm_FlexIO_au16DutyCycle[u8ArrayIdx]) && (PWM_FLEXIO_DUTY_0 != Pwm_FlexIO_au16DutyCycle[u8ArrayIdx]))
        {
            /* Timer pin output enabled */
            /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
            /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_SET32(FLEXIO_TIMCTLn_ADDR32((uint32)nHwTimerId), FLEXIO_TMR_PIN_OUTPUT_U32);
            
            /* Disable timer mode */
            /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
            /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_CLEAR32(FLEXIO_TIMCTLn_ADDR32((uint32)nHwTimerId), FLEXIO_TIMCTL_TIMOD_MASK_U32);
            
            /* Set TIMCFG register value from high nibble and low nibble */
            u32TIMCMPRegVal = (uint32)(((uint32)(Pwm_FlexIO_au8HighNib[u8ArrayIdx])) << (uint32)8U);
            u32TIMCMPRegVal |= (uint32)(Pwm_FlexIO_au8LowNib[u8ArrayIdx]);
            
            /* Write TIMCMP register */
            /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
            /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)nHwTimerId), u32TIMCMPRegVal);
            
            /* Enable timer mode */
            /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
            /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_SET32(FLEXIO_TIMCTLn_ADDR32((uint32)nHwTimerId), FLEXIO_TMR_DUAL_8BIT_PWM_U32);

            /* Timer pin output enable */
            /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
            /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
            /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_SET32(FLEXIO_TIMCTLn_ADDR32((uint32)nHwTimerId), FLEXIO_TMR_PIN_OUTPUT_U32);
            
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
            /* If notification status is stacked before, then set it back */
            if (PWM_FLEXIO_NO_EDGE != Pwm_FlexIO_aNotification[u8ArrayIdx])
            {
                Pwm_FlexIO_aNotification[u8ArrayIdx] = PWM_FLEXIO_CHF_IRQ_EDGE;
                
                /* Clear interrupt flag in TIMSTAT register */
                Mcl_Flexio_ClearTimStat((uint8)(1U << nHwTimerId));
                
                /* Set interrupt enable in TIMIEN register */
                Mcl_Flexio_WriteTimIen((uint8)(1U << nHwTimerId), (uint8)(1U << nHwTimerId));
            }
            else
            {
                /* Clear interrupt enable in TIMIEN register */
                Mcl_Flexio_WriteTimIen((uint8)(1U << nHwTimerId), (uint8)0U);
                    
                /* Clear interrupt flag in TIMSTAT register */
                Mcl_Flexio_ClearTimStat((uint8)(1U << nHwTimerId));
            }
#endif
        }
        else
        {
            /* Do nothing */
        }
        
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
        Pwm_FlexIO_au8ChannelStatus[u8ArrayIdx] = PWM_FLEXIO_CHANNEL_RUNNING;
#endif
    }
    else
    {
        /* Do nothing */
    }

    Pwm_FlexIO_au8NextChannelStatus[u8ArrayIdx] = PWM_FLEXIO_CHANNEL_NO_CHANGE;
    
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_47();

}
#endif


/*===============================================================================================
*                                       GLOBAL FUNCTIONS
===============================================================================================*/

/**
* @brief        This function initializes all internals variables of the driver.
* @details      This function will initialize with default values all FlexIO module registers.
*               Will loop through all FlexIO channels in the configuration structure and will
*               setup required registers for each channel
*
* @param        pFlexIOIpConfig     Pointer to FlexIO configuration structure
*
* @return       void
*
*/
FUNC(void, PWM_CODE) Pwm_FlexIO_Init
(   
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
)
{
    
    /** @brief  Pointer to FlexIO channel configuration */
    P2CONST     (Pwm_FlexIO_ChannelConfigType,  AUTOMATIC,  PWM_APPL_CONST)     pFlexIOChannelConfig;
    /** @brief  Variable store hardware channel index */
    VAR         (Pwm_FlexIO_ChannelType,        AUTOMATIC)                      nHwChannelId;
    /** @brief  Variable store hardware timer index */
    VAR         (Pwm_FlexIO_TimerType,          AUTOMATIC)                      nHwTimerId;
    /** @brief  Counter value used in loops */
    VAR         (uint8,                         AUTOMATIC)                      u8Counter;
    /** @brief  Array index value to access element of internal variable */
    VAR         (uint8,                         AUTOMATIC)                      u8ArrayIdx; 
    /** @brief  Variable store TIMCFG register value */
    VAR         (uint32,                        AUTOMATIC)                      u32TIMCFGRegVal;
    /** @brief  Variable store TIMCTL register value */
    VAR         (uint32,                        AUTOMATIC)                      u32TIMCTLRegVal; 
    /** @brief  Variable store TIMCMP register value */
    VAR         (uint32,                        AUTOMATIC)                      u32TIMCMPRegVal;
    

#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
    /* Set initial value for channel status */
    for (u8Counter = (uint8)0U; u8Counter < (uint8)PWM_FLEXIO_CHANNEL_NO; u8Counter++)
    {
        Pwm_FlexIO_au8ChannelStatus[u8Counter] = PWM_FLEXIO_CHANNEL_NO_INIT;
    }
#endif

#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
    /* Set initial value for next channel status */
    for (u8Counter = (uint8)0U; u8Counter < (uint8)PWM_FLEXIO_CHANNEL_NO; u8Counter++)
    {
        Pwm_FlexIO_au8NextChannelStatus[u8Counter] = PWM_FLEXIO_CHANNEL_NO_CHANGE;
    }
#endif
    
    /* Set initial value for internal variable store duty cycle */
    for (u8Counter = (uint8)0U; u8Counter < (uint8)PWM_FLEXIO_CHANNEL_NO; u8Counter++)
    {
        Pwm_FlexIO_au16DutyCycle[u8Counter] = (uint16)0U;
#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_API == STD_ON))     
        Pwm_FlexIO_au16NextDutyCycle[u8Counter] = (uint16)0U;
#endif
    }
    
    /* Set initial value for internal variable store period */
    for (u8Counter = (uint8)0U; u8Counter < (uint8)PWM_FLEXIO_CHANNEL_NO; u8Counter++)
    {
        Pwm_FlexIO_aPeriod[u8Counter] = (Pwm_PeriodType)0U;
#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)) 
        Pwm_FlexIO_aNextPeriod[u8Counter] = (Pwm_PeriodType)0U;
#endif
    }
    
    /* Set initial value for internal variable store TIMCMP register value */
    for (u8Counter = (uint8)0U; u8Counter < (uint8)PWM_FLEXIO_CHANNEL_NO; u8Counter++)
    {
        Pwm_FlexIO_au8HighNib[u8Counter] = (uint8)0U;
        Pwm_FlexIO_au8LowNib[u8Counter] = (uint8)0U;
    }
       
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /* Set initial value for internal variable store notification types */
    for (u8Counter = (uint8)0U; u8Counter < (uint8)PWM_FLEXIO_CHANNEL_NO; u8Counter++)
    {
        Pwm_FlexIO_aNotification[u8Counter] = PWM_FLEXIO_NO_EDGE;
        Pwm_FlexIO_aPolarity[u8Counter] = PWM_HIGH;
    }
#endif
  
    /* Loop all FlexIO channels and perform initializing actions */
    for (u8Counter = (uint8)0U; u8Counter < pFlexIOIpConfig->u8ChannelNumber; u8Counter++)
    {
        /* Reset register temporary variable */
        u32TIMCFGRegVal = (uint32)0U;
        u32TIMCTLRegVal = (uint32)0U;
        u32TIMCMPRegVal = (uint32)0U;
        
        /* Get pointer to configuration of FlexIO channel */
        pFlexIOChannelConfig = &(*pFlexIOIpConfig->pChannelsConfig)[u8Counter];
        
        /* Get hardware channel index */
        nHwChannelId         = pFlexIOChannelConfig->nHwChannelId;
        
        /* Get hardware timer index */
        nHwTimerId           = pFlexIOChannelConfig->nHwTimerId; 
          
        /* Get array index of this channel to access to internal variable */
        u8ArrayIdx           = (uint8)nHwTimerId;
        
        /* Store default period into internal variable */
        Pwm_FlexIO_aPeriod[u8ArrayIdx] = pFlexIOChannelConfig->nPwmDefaultPeriod;
        
        /* Store default duty cycle into internal variable */
        Pwm_FlexIO_au16DutyCycle[u8ArrayIdx] = pFlexIOChannelConfig->u16PwmDefaultDutyCycle;
              
        /* Calculate the value intended to write to TIMCMP register */
        Pwm_FlexIO_CalculateTIMCMPRegVal(u8ArrayIdx);
      
        u32TIMCTLRegVal |= FLEXIO_TMR_DUAL_8BIT_PWM_U32;
        u32TIMCTLRegVal |= FLEXIO_TMR_PIN_ACTIVE_HIGH_U32;
  
        u32TIMCTLRegVal |= FLEXIO_TMR_PIN_OUTPUT_U32;
        u32TIMCTLRegVal |= ((uint32)nHwChannelId << FLEXIO_TIMCTL_PINSEL_SHIFT_U32);
            
        u32TIMCMPRegVal = (uint32)(((uint32)(Pwm_FlexIO_au8HighNib[u8ArrayIdx])) << (uint32)8U);
        u32TIMCMPRegVal |= (uint32)(Pwm_FlexIO_au8LowNib[u8ArrayIdx]);
                
        /* Write TIMCMP register */
        /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
        /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
        /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
        /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)nHwTimerId), u32TIMCMPRegVal);
        
        /* Write TIMCFG register */
        /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
        /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
        /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
        /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_WRITE32(FLEXIO_TIMCFGn_ADDR32((uint32)nHwTimerId), u32TIMCFGRegVal);
            
        /* Write TIMCTL register */
        /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
        /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
        /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
        /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32)nHwTimerId), u32TIMCTLRegVal);

        /* Clear interrupt enable in TIMIEN register */
        Mcl_Flexio_WriteTimIen((uint8)(1U << nHwTimerId), (uint8)0U);
            
        /* Clear interrupt flag in TIMSTAT register */
        Mcl_Flexio_ClearTimStat((uint8)(1U << nHwTimerId));

#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
        /* Indicate that this channel is in running status */
        Pwm_FlexIO_au8ChannelStatus[u8ArrayIdx] = PWM_FLEXIO_CHANNEL_RUNNING;
#endif
    }    
}



/*=============================================================================================*/
#if (PWM_DE_INIT_API == STD_ON)
/**
* @brief        This function de-initializes the driver.
* @details      This function will set to idle state all FlexIO channels. Will stop all
*               FLEXIO modules and disable all interrupts.
*
* @param        pFlexIOIpConfig     Pointer to FlexIO channels configuration structure
*
* @return       void
*
*/
FUNC(void, PWM_CODE) Pwm_FlexIO_DeInit
(   
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
)
{
    
    /** @brief  Pointer to FlexIO channel configuration */
    P2CONST     (Pwm_FlexIO_ChannelConfigType,  AUTOMATIC,  PWM_APPL_CONST)     pFlexIOChannelConfig;
    /** @brief  Variable store hardware timer index */
    VAR         (Pwm_FlexIO_TimerType,          AUTOMATIC)                      nHwTimerId;
    /** @brief  Counter value used in loops */
    VAR         (uint8,                         AUTOMATIC)                      u8Counter;
    /** @brief  Array index value to access element of internal variable */
    VAR         (uint8,                         AUTOMATIC)                      u8ArrayIdx;
    

    /* Loop all FlexIO channels and perform initializing actions */
    for (u8Counter = (uint8)0U; u8Counter < pFlexIOIpConfig->u8ChannelNumber; u8Counter++)
    {     
        /* Get pointer to configuration of FlexIO channel */
        pFlexIOChannelConfig = &(*pFlexIOIpConfig->pChannelsConfig)[u8Counter];
             
        /* Get hardware timer index */
        nHwTimerId           = pFlexIOChannelConfig->nHwTimerId; 
        
        /* Get array index of this channel to access to internal variable */
        u8ArrayIdx           = (uint8)nHwTimerId;
       
        /* Timer pin output disabled */
        /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
        /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
        /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
        /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_BIT_CLEAR32(FLEXIO_TIMCTLn_ADDR32((uint32)nHwTimerId), FLEXIO_TIMCTL_PINCFG_MASK_U32);
        
        /* Disable timer mode */
        /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
        /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
        /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
        /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_BIT_CLEAR32(FLEXIO_TIMCTLn_ADDR32((uint32)nHwTimerId), FLEXIO_TIMCTL_TIMOD_MASK_U32);
        
        /* Clear TIMCMP register */
        /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
        /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
        /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
        /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_WRITE32(FLEXIO_TIMCMPn_ADDR32((uint32)nHwTimerId), (uint32)0U);
        
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        /* Clear value for internal variable store notification types */
        Pwm_FlexIO_aNotification[u8ArrayIdx] = PWM_FLEXIO_NO_EDGE;
        
        /* Clear interrupt enable in TIMIEN register */
        Mcl_Flexio_WriteTimIen((uint8)(1U << nHwTimerId), (uint8)0U);
            
        /* Clear interrupt flag in TIMSTAT register */
        Mcl_Flexio_ClearTimStat((uint8)(1U << nHwTimerId));
#endif

#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
        /* Set channel status into idle */
        Pwm_FlexIO_au8ChannelStatus[u8ArrayIdx] = PWM_FLEXIO_CHANNEL_IDLE;
#endif

#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
        /* Clear next channel status */
        Pwm_FlexIO_au8NextChannelStatus[u8ArrayIdx] = PWM_FLEXIO_CHANNEL_NO_CHANGE;
#endif
        
        /* Clear value for internal variable store duty cycle */
        Pwm_FlexIO_au16DutyCycle[u8ArrayIdx] = (uint16)0U;
#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
        Pwm_FlexIO_au16NextDutyCycle[u8ArrayIdx] = (uint16)0U;
#endif
    
        /* Clear value for internal variable store period */
        Pwm_FlexIO_aPeriod[u8ArrayIdx] = (Pwm_PeriodType)0U;
#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
        Pwm_FlexIO_aNextPeriod[u8ArrayIdx] = (Pwm_PeriodType)0U;
#endif    
        /* Clear value for internal variable store TIMCMP register value */
        Pwm_FlexIO_au8HighNib[u8ArrayIdx] = (uint8)0U;
        Pwm_FlexIO_au8LowNib[u8ArrayIdx] = (uint8)0U;
    }
    
}
#endif /* PWM_DE_INIT_API */



/*=============================================================================================*/
#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
/**
* @brief        This function sets the duty cycle for the specified FlexIO channel
* @details      This function sets the duty cycle for the specified FlexIO channel
*
* @param        u8LgChannelIdx      - PWM channel id
*               u16DutyCycle        - PWM duty cycle value 0x0000 for 0% ... 0x8000 for 100%
*               pFlexIOIpConfig     - pointer to FlexIO IP configuration
*
* @return       void
*
*/
FUNC(void, PWM_CODE) Pwm_FlexIO_SetDutyCycle
(
    VAR         (uint8,                         AUTOMATIC)                      u8LgChannelIdx,
    VAR         (uint16,                        AUTOMATIC)                      u16DutyCycle,
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
)
{
    
    /** @brief  Pointer to FlexIO channel configuration */
    P2CONST     (Pwm_FlexIO_ChannelConfigType,  AUTOMATIC,  PWM_APPL_CONST)     pFlexIOChannelConfig;
    /** @brief  Variable store hardware timer index */
    VAR         (Pwm_FlexIO_TimerType,          AUTOMATIC)                      nHwTimerId;
    /** @brief  Array index value to access element of internal variable */
    VAR         (uint8,                         AUTOMATIC)                      u8ArrayIdx;
    
    
    /* Get pointer to configuration of FlexIO channel */
    pFlexIOChannelConfig = &(*pFlexIOIpConfig->pChannelsConfig)[u8LgChannelIdx];
    
    /* Get hardware timer index */
    nHwTimerId           = pFlexIOChannelConfig->nHwTimerId; 
    
    /* Get array index of this channel to access to internal variable */
    u8ArrayIdx           = (uint8)nHwTimerId;
    
    
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_48();
    
    /* Store new duty cycle in internal variable */
    Pwm_FlexIO_au16NextDutyCycle[u8ArrayIdx] = u16DutyCycle;

    /* Set next channel state to update */
    Pwm_FlexIO_au8NextChannelStatus[u8ArrayIdx] = PWM_FLEXIO_CHANNEL_CHANGE_DUTY;
    
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_48();

    Pwm_FlexIO_UpdateRegister(nHwTimerId);
}
#endif /* PWM_SET_DUTY_CYCLE_API */



/*=============================================================================================*/
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/**
* @brief        This function sets the period and the duty cycle for the specified FlexIO channel
* @details      This function sets the period and the duty cycle for the specified FlexIO channel
*
* @param        u8LgChannelIdx      - PWM channel id
*               nPeriod             - PWM signal period value
*               u16DutyCycle        - PWM duty cycle value 0x0000 for 0% ... 0x8000 for 100%
*               pFlexIOIpConfig     - pointer to FlexIO IP configuration
*
* @return       void
*
*/
FUNC(void, PWM_CODE) Pwm_FlexIO_SetPeriodAndDuty
(
    VAR         (uint8,                         AUTOMATIC)                      u8LgChannelIdx,
    VAR         (Pwm_PeriodType,                AUTOMATIC)                      nPeriod,
    VAR         (uint16,                        AUTOMATIC)                      u16DutyCycle,
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
)
{
    
   /** @brief  Pointer to FlexIO channel configuration */
    P2CONST     (Pwm_FlexIO_ChannelConfigType,  AUTOMATIC,  PWM_APPL_CONST)     pFlexIOChannelConfig;
    /** @brief  Variable store hardware timer index */
    VAR         (Pwm_FlexIO_TimerType,          AUTOMATIC)                      nHwTimerId;
    /** @brief  Array index value to access element of internal variable */
    VAR         (uint8,                         AUTOMATIC)                      u8ArrayIdx;
    
    
    /* Get pointer to configuration of FlexIO channel */
    pFlexIOChannelConfig = &(*pFlexIOIpConfig->pChannelsConfig)[u8LgChannelIdx];
    
    /* Get hardware timer index */
    nHwTimerId           = pFlexIOChannelConfig->nHwTimerId; 
      
    /* Get array index of this channel to access to internal variable */
    u8ArrayIdx           =(uint8)nHwTimerId;
    
    
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_49();
    
    /* Store new duty cycle in internal variable */
    Pwm_FlexIO_au16NextDutyCycle[u8ArrayIdx] = u16DutyCycle;

    /* Store new duty cycle in internal variable */
    Pwm_FlexIO_aNextPeriod[u8ArrayIdx] = nPeriod;

    /* Set next channel state to update */
    Pwm_FlexIO_au8NextChannelStatus[u8ArrayIdx] = PWM_FLEXIO_CHANNEL_CHANGE_RUNNING;
    
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_49();

    Pwm_FlexIO_UpdateRegister(nHwTimerId);
    
}
#endif /* PWM_SET_PERIOD_AND_DUTY_API */


/*=============================================================================================*/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief        This function returns the PWM signal output state
* @details      This function returns the PWM Channel state as High or Low
*
* @param        u8IdxChannelConfig - PWM channel id
*               pFlexIOIpConfig    - pointer to FlexIO IP Configuration
*
* @return       Pwm_OutputStateType - PWM signal output logic value
*               PWM_LOW - The output state of PWM channel is low
*               PWM_HIGH - The output state of PWM channel is high
*
*/
FUNC(Pwm_OutputStateType, PWM_CODE) Pwm_FlexIO_GetOutputState
(
    VAR         (uint8,                         AUTOMATIC)                      u8LgChannelIdx,
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
)
{
    /* Avoid compiler warning */
    (void)u8LgChannelIdx;
    (void)pFlexIOIpConfig;
    
    return PWM_LOW;
    
}
#endif /* PWM_GET_OUTPUT_STATE_API */



/*=============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        This function disables the user notifications
* @details      This function disables the user notifications
*
* @param        u8LgChannelIdx      - PWM channel id
*               pFlexIOIpConfig     - pointer to FlexIO IP Configuration
*
* @return       void
*
*/
FUNC(void, PWM_CODE) Pwm_FlexIO_DisableNotification
(
    VAR         (uint8,                         AUTOMATIC)                      u8LgChannelIdx,
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
)
{
    
     /** @brief  Pointer to FlexIO channel configuration */
    P2CONST     (Pwm_FlexIO_ChannelConfigType,  AUTOMATIC,  PWM_APPL_CONST)     pFlexIOChannelConfig;
    /** @brief  Variable store hardware timer index */
    VAR         (Pwm_FlexIO_TimerType,          AUTOMATIC)                      nHwTimerId;
    /** @brief  Array index value to access element of internal variable */
    VAR         (uint8,                         AUTOMATIC)                      u8ArrayIdx;
    
    
    /* Get pointer to configuration of FlexIO channel */
    pFlexIOChannelConfig = &(*pFlexIOIpConfig->pChannelsConfig)[u8LgChannelIdx];
    
    /* Get hardware timer index */
    nHwTimerId           = pFlexIOChannelConfig->nHwTimerId; 
    
    /* Get array index of this channel to access to internal variable */
    u8ArrayIdx           = (uint8)nHwTimerId;
    
    
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_50();
    
    /* Clear notification types for this channel */
    Pwm_FlexIO_aNotification[u8ArrayIdx] = PWM_FLEXIO_NO_EDGE;
    
    /* Clear interrupt enable in TIMIEN register */
    Mcl_Flexio_WriteTimIen((uint8)(1U << nHwTimerId), (uint8)0U);
        
    /* Clear interrupt flag in TIMSTAT register */
    Mcl_Flexio_ClearTimStat((uint8)(1U << nHwTimerId));
    
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_50();
    
}
#endif /* PWM_NOTIFICATION_SUPPORTED */



/*=============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        This function enables the user notifications
* @details      This function enables the user notifications
*
* @param        u8LgChannelIdx      - PWM channel id
*               eNotification       - notification type to be enabled
*               pFlexIOIpConfig     - pointer to FlexIO IP Configuration
*
* @return       void
*
*/
FUNC(void, PWM_CODE) Pwm_FlexIO_EnableNotification
(
    VAR         (uint8,                         AUTOMATIC)                      u8LgChannelIdx,
    VAR         (Pwm_EdgeNotificationType,      AUTOMATIC)                      eNotification,
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
)
{
    
    /** @brief  Pointer to FlexIO channel configuration */
    P2CONST     (Pwm_FlexIO_ChannelConfigType,  AUTOMATIC,  PWM_APPL_CONST)     pFlexIOChannelConfig;
    /** @brief  Variable store hardware timer index */
    VAR         (Pwm_FlexIO_TimerType,          AUTOMATIC)                      nHwTimerId;
    /** @brief  Array index value to access element of internal variable */
    VAR         (uint8,                         AUTOMATIC)                      u8ArrayIdx;
    
    
    /* Get pointer to configuration of FlexIO channel */
    pFlexIOChannelConfig = &(*pFlexIOIpConfig->pChannelsConfig)[u8LgChannelIdx];
    
    /* Get hardware timer index */
    nHwTimerId           = pFlexIOChannelConfig->nHwTimerId; 
 
    /* Get array index of this channel to access to internal variable */
    u8ArrayIdx           = (uint8)nHwTimerId;
    
    
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_51();
    
    if ((PWM_HIGH == Pwm_FlexIO_aPolarity[u8ArrayIdx]) && (PWM_RISING_EDGE == eNotification))
    {
        if (
            ((Pwm_PeriodType)0U == Pwm_FlexIO_aPeriod[u8ArrayIdx]) ||
            (((Pwm_PeriodType)0U != Pwm_FlexIO_aPeriod[u8ArrayIdx]) && ((PWM_FLEXIO_DUTY_0 == Pwm_FlexIO_au16DutyCycle[u8ArrayIdx]) || (PWM_FLEXIO_DUTY_100 == Pwm_FlexIO_au16DutyCycle[u8ArrayIdx]) || ((uint8)0U == Pwm_FlexIO_au8LowNib[u8ArrayIdx])))
           )
        {
            /* Because of no pulse, notification status will be stacked temporarily */
            Pwm_FlexIO_aNotification[u8ArrayIdx] = PWM_FLEXIO_CHF_IRQ_IDLE;
            
            /* Clear interrupt enable in TIMIEN register */
            Mcl_Flexio_WriteTimIen((uint8)(1U << nHwTimerId), (uint8)0U);
                
            /* Clear interrupt flag in TIMSTAT register */
            Mcl_Flexio_ClearTimStat((uint8)(1U << nHwTimerId));
        }
        else
        {
            Pwm_FlexIO_aNotification[u8ArrayIdx] = PWM_FLEXIO_CHF_IRQ_EDGE;
            
            /* Clear interrupt flag in TIMSTAT register */
            Mcl_Flexio_ClearTimStat((uint8)(1U << nHwTimerId));
            
            /* Set interrupt enable in TIMIEN register */
            Mcl_Flexio_WriteTimIen((uint8)(1U << nHwTimerId), (uint8)(1U << nHwTimerId));
        }
    }
    
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_51();
}
#endif /* PWM_NOTIFICATION_SUPPORTED */



/*=============================================================================================*/
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
/**
* @brief        Implementation specific function to get the Duty cycle of the given PWM channel
*
* @param        u8LgChannelIdx - PWM channel id
*
* @return       uint16 
*
*/
/* @violates @ref Pwm_FlexIO_C_REF_8 This is not dead code */
FUNC(uint16, PWM_CODE) Pwm_FlexIO_GetChannelState
(
    VAR         (uint8,                         AUTOMATIC)                      u8LgChannelIdx,
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
)
{
    
    /** @brief  Pointer to FlexIO channel configuration */
    P2CONST     (Pwm_FlexIO_ChannelConfigType,  AUTOMATIC,  PWM_APPL_CONST)     pFlexIOChannelConfig;
    /** @brief  Variable store hardware timer index */
    VAR         (Pwm_FlexIO_TimerType,          AUTOMATIC)                      nHwTimerId;
    /** @brief  Array index value to access element of internal variable */
    VAR         (uint8,                         AUTOMATIC)                      u8ArrayIdx;
    
    
    /* Get pointer to configuration of FlexIO channel */
    pFlexIOChannelConfig = &(*pFlexIOIpConfig->pChannelsConfig)[u8LgChannelIdx];
    
    /* Get hardware timer index */
    nHwTimerId           = pFlexIOChannelConfig->nHwTimerId; 
 
    /* Get array index of this channel to access to internal variable */
    u8ArrayIdx           = (uint8)nHwTimerId;
    
    
    return Pwm_FlexIO_au16DutyCycle[u8ArrayIdx];
    
}
#endif /* PWM_GET_CHANNEL_STATE_API */



/*=============================================================================================*/
#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_NOTIFICATION_SUPPORTED == STD_ON))
/**
* @brief        Pwm_FlexIO_ValidateNotification
* @details      This function will check validate of Edge type with polarity
*
* @param        u8LgChannelIdx    - PWM channel id in top configuration structure
*               eNotification     - Notification edge type
*               pFlexIOIpConfig   - Pointer to configuration structure of FlexIO channels
*
* @return       E_NOT_OK          - Notification handler is not valid
*
*/
/* @violates @ref Pwm_FlexIO_C_REF_8 cast from unsigned int to pointer */
FUNC(Std_ReturnType, PWM_CODE) Pwm_FlexIO_ValidateNotification
(
    VAR         (uint8,                         AUTOMATIC)                      u8LgChannelIdx,
    VAR         (Pwm_EdgeNotificationType,      AUTOMATIC)                      eNotification,
    CONSTP2CONST(Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
)
{
    
    /** @brief  Pointer to FlexIO channel configuration */
    P2CONST     (Pwm_FlexIO_ChannelConfigType,  AUTOMATIC,  PWM_APPL_CONST)     pFlexIOChannelConfig;
    /** @brief  Variable store hardware timer index */
    VAR         (Pwm_FlexIO_TimerType,          AUTOMATIC)                      nHwTimerId;
    /** @brief  Array index value to access element of internal variable */
    VAR         (uint8,                         AUTOMATIC)                      u8ArrayIdx;
    /** @brief  Return value */
    VAR         (Std_ReturnType,                AUTOMATIC)                      nRetVal;
    
    
    /* Get pointer to configuration of FlexIO channel */
    pFlexIOChannelConfig = &(*pFlexIOIpConfig->pChannelsConfig)[u8LgChannelIdx];
    
    /* Get hardware timer index */
    nHwTimerId           = pFlexIOChannelConfig->nHwTimerId; 

    /* Get array index of this channel to access to internal variable */
    u8ArrayIdx           =  (uint8)nHwTimerId;
    
    if (
        (PWM_BOTH_EDGES == eNotification) || \
        ((PWM_LOW == Pwm_FlexIO_aPolarity[u8ArrayIdx]) && (PWM_RISING_EDGE == eNotification)) || \
        ((PWM_HIGH == Pwm_FlexIO_aPolarity[u8ArrayIdx]) && (PWM_FALLING_EDGE == eNotification))
       )
    {
        nRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        nRetVal = (Std_ReturnType)E_OK;
    }
    
    return nRetVal;
    
}
#endif


/*=============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
FUNC(Std_ReturnType, PWM_CODE) Pwm_FlexIO_ValidateIdleState
(
    P2CONST     (Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig
)
{
    
    /** @brief  Variable used in loop index */
    VAR         (uint8,                         AUTOMATIC)                      u8Counter;
    /** @brief  Return value */
    VAR         (Std_ReturnType,                AUTOMATIC)                      nRetVal = (Std_ReturnType)E_OK;
    
    
    /* Avoid compiler warning */
    (void)pFlexIOIpConfig;

    /* Loop all FlexIO channels, make sure there are no channels in the different states than IDLE state */
    for (u8Counter = (uint8)0U; u8Counter < PWM_FLEXIO_CHANNEL_NO; u8Counter++)
    {
        if (PWM_FLEXIO_CHANNEL_RUNNING == Pwm_FlexIO_au8ChannelStatus[u8Counter])
        {
            nRetVal = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }
    
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /* Loop all FlexIO channels, make sure there are no channels which have notification enabled */
    for (u8Counter = (uint8)0U; u8Counter < PWM_FLEXIO_CHANNEL_NO; u8Counter++)
    {
        if (PWM_FLEXIO_NO_EDGE != Pwm_FlexIO_aNotification[u8Counter])            
        {
            nRetVal = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }
#endif

    return nRetVal;
    
}
#endif /* PWM_POWER_STATE_SUPPORTED */



/*=============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
FUNC(void, PWM_CODE) Pwm_FlexIO_SetPowerState
(
    P2CONST     (Pwm_FlexIO_IpConfigType,       AUTOMATIC,  PWM_APPL_CONST)     pFlexIOIpConfig,
    VAR         (Pwm_PowerStateType,            AUTOMATIC)                      nPowerState
)
{
    
    /** @brief  Pointer to FlexIO channel configuration */
    P2CONST     (Pwm_FlexIO_ChannelConfigType,  AUTOMATIC,  PWM_APPL_CONST)     pFlexIOChannelConfig;
    /** @brief  Variable store hardware timer index */
    VAR         (Pwm_FlexIO_TimerType,          AUTOMATIC)                      nHwTimerId;
    /** @brief  Counter value used in loops */
    VAR         (uint8,                         AUTOMATIC)                      u8Counter;
    /** @brief  Array index value to access element of internal variable */
    VAR         (uint8,                         AUTOMATIC)                      u8ArrayIdx;
    /** @brief  Variable store TIMCTL register value */
    VAR         (uint32,                        AUTOMATIC)                      u32TIMCTLRegVal;
    

    /* Loop all FlexIO channels and perform initializing actions */
    for (u8Counter = (uint8)0U; u8Counter < pFlexIOIpConfig->u8ChannelNumber; u8Counter++)
    {
        /* Get pointer to configuration of FlexIO channel */
        pFlexIOChannelConfig = &(*pFlexIOIpConfig->pChannelsConfig)[u8Counter];
        
        /* Get hardware timer index */
        nHwTimerId           = pFlexIOChannelConfig->nHwTimerId; 
        
        /* Get array index of this channel to access to internal variable */
        u8ArrayIdx           = (uint8)nHwTimerId;
        
        
        /* Read TIMCTL register value */
        
        u32TIMCTLRegVal = REG_READ32(FLEXIO_TIMCTLn_ADDR32((uint32)u8ArrayIdx));
        
        /* Clear TIMOD bit field */
        u32TIMCTLRegVal &= (uint32)(~(FLEXIO_TIMCTL_TIMOD_MASK_U32));
        
        /* In low power mode, turn off timer mode for all channels */
        if (PWM_LOW_POWER == nPowerState)
        {
            u32TIMCTLRegVal |= (uint32)0U;
        }
        /* In other mode, start timer with proper mode rely on channel polarity */
        else
        {
            u32TIMCTLRegVal |= FLEXIO_TMR_DUAL_8BIT_PWM_U32;
        }
        
        /* Write TIMCTL register */
        /* @violates @ref Pwm_FlexIO_C_REF_5 cast from unsigned int to pointer */
        /* @violates @ref Pwm_FlexIO_C_REF_6 access to 32 bit register using 8 bit channel */
        /* @violates @ref Pwm_FlexIO_C_REF_7 cast from unsigned int to pointer */
        /* @violates @ref Pwm_FlexIO_C_REF_9 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_WRITE32(FLEXIO_TIMCTLn_ADDR32((uint32)nHwTimerId), u32TIMCTLRegVal);
    }
    
}
#endif /* PWM_POWER_STATE_SUPPORTED */



/*=============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Interrupt service routine to process the FlexIO interrupt
* @details      This function will check interrupt flag then execute notification
*
* @param        ChannelId         FlexIO module ID that triggered the interrupt
* @param        u8TimerMaskFlag   Mask to cover bit filed in TIMSTAT Register
* 
* @return       void
*
*
*
*/
/* @violates @ref Pwm_FlexIO_C_REF_8 cast from unsigned int to pointer */
FUNC(void, PWM_CODE) Pwm_FlexIO_InterruptHandler
(
    VAR         (uint8,                         AUTOMATIC)                      ChannelId,
    VAR         (uint8,                         AUTOMATIC)                      u8TimerMaskFlag
)
{   
#if ((defined PWM_FLEXIO_0_CH_0_1_ISR_USED) || (defined PWM_FLEXIO_0_CH_2_3_ISR_USED))
    /** @brief  Counter value used in loops */
    VAR         (uint8,                         AUTOMATIC)                      u8Counter = (uint8)0U;
#endif

#if (defined PWM_FLEXIO_0_CH_0_1_ISR_USED) 
    if (FLEXIO_0_CH_0 == ChannelId)
    {       
        /* Loop all FlexIO timers in current module and perform interrupt handler */
        for (u8Counter = (uint8)0U; u8Counter < 2U; u8Counter++)
        {
            if ((uint32)0U != (u8TimerMaskFlag & ((uint32)1U << u8Counter)))
            {
                /* If user notification is enabled, execute it */
                if (PWM_FLEXIO_NO_EDGE != Pwm_FlexIO_aNotification[u8Counter])
                {
                    Pwm_Ipw_FlexIOChannelNotification(u8Counter);
                }
            }
        }
    }
#endif
   
#if (defined PWM_FLEXIO_0_CH_2_3_ISR_USED) 
    if (FLEXIO_0_CH_2 == ChannelId)
    {       
        /* Loop all FlexIO timers in current module and perform interrupt handler */
        for (u8Counter = (uint8)0U; u8Counter < 2U; u8Counter++)
        {
            if ((uint32)0U != (u8TimerMaskFlag & ((uint32)1U << (u8Counter + 2U))))
            {
                /* If user notification is enabled, execute it */
                if (PWM_FLEXIO_NO_EDGE != Pwm_FlexIO_aNotification[u8Counter + 2U])
                {
                    Pwm_Ipw_FlexIOChannelNotification(u8Counter + 2U);
                }
            }
        }
    }
#else
    (void)ChannelId;
    (void)u8TimerMaskFlag;
#endif
}
#endif

#define PWM_STOP_SEC_CODE

/*
* @violates @ref Pwm_FlexIO_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
/*
* @violates @ref Pwm_FlexIO_C_REF_4 Only preprocessor statements and comments before 'include'
*/
#include "Pwm_MemMap.h"



#endif  /* PWM_FLEXIO_USED */

#ifdef __cplusplus
}
#endif

/** @} */