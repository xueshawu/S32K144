/**
*   @file    Can_GeneralTypes.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - General Types.
*   @details API header for all types and constants that are shared among the AUTOSAR CAN
*            modules Can, CanIf and CanTrcv.
*            This file contains sample code only. It is not part of the production code deliverables
*
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : S32K14X
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


#ifndef CAN_GENERAL_TYPES_H
#define CAN_GENERAL_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Can_GeneralTypes_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

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
*                                             ENUMS
==================================================================================================*/
/**
* @brief          CAN Controller State Modes of operation.
* @details        States that are used by the several ControllerMode functions
* @implements     Can_Can_ControllerStateType_enumeration
*/
typedef enum
    {
        CAN_CS_UNINIT  = 0U,    /**< @brief CAN controller state UNINIT */
        CAN_CS_STARTED,         /**< @brief CAN controller state STARTED */
        CAN_CS_STOPPED,         /**< @brief CAN controller state STOPPED */
        CAN_CS_SLEEP            /**< @brief CAN controller state SLEEP */
    } Can_ControllerStateType;

/**
* @brief          CAN Controller State Modes of operation.
* @details        Error states of a CAN controller
* @implements     Can_Can_ControllerStateType_enumeration
*/
typedef enum
    {
        CAN_ERRORSTATE_ACTIVE = 0U,     /**< @brief The CAN controller takes fully part in communication. */
        CAN_ERRORSTATE_PASSIVE,         /**< @brief The CAN controller takes part in communication, but does not send active error frames. */
        CAN_ERRORSTATE_BUSOFF           /**< @brief The CAN controller does not take part in communication. */
    } Can_ErrorStateType;



/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef CAN_EXTENDEDID
    #if (CAN_EXTENDEDID == STD_ON)
/**
* @{
* @brief          Can_IdType
* @details        Type for storing the Identifier Length Type: Normal or Extended.
*                   - used by "Can_MessageBufferConfigObjectType" structure.
*                 The driver does not distinguish between Extended and Mixed transmission modes.
*                 Extended transmission mode of operation behaves the same as Mixed mode.
* @implements     Can_IdType_type
*/
    typedef  uint32 Can_IdType;
    #else /* (CAN_EXTENDEDID == STD_OFF) */
    typedef  uint16 Can_IdType;
    #endif /* (CAN_EXTENDEDID == STD_ON/STD_OFF) */
#else
    typedef  uint16 Can_IdType;
#endif
/**@}*/

/**
* @brief          Can_PduType
* @details        Type used to provide ID, DLC, SDU from CAN interface to CAN driver.
*                 HTH or HRH = ID+DLC+SDU.
* @implements     Can_PduType_structure
*/
typedef struct
    {
        VAR(Can_IdType, CAN_VAR) id; /**< @brief CAN L-PDU = Data Link Layer Protocol Data Unit.
                                                 Consists of Identifier, DLC and Data(SDU)  It is
                                                 uint32 for CAN_EXTENDEDID=STD_ON, else is uint16.
                                                 */
        VAR(PduIdType, CAN_VAR) swPduHandle; /**< @brief The L-PDU Handle = defined and placed
                                                         inside the CanIf module layer. Each handle
                                                         represents an L-PDU, which is a constant
                                                         structure with information for Tx/Rx
                                                         processing. */
        VAR(uint8, CAN_VAR) length; /**< @brief DLC = Data Length Code (part of L-PDU that describes
                                                the SDU length). */
        P2VAR(uint8, CAN_VAR, CAN_APPL_DATA) sdu; /**< @brief CAN L-SDU = Link Layer Service Data
                                                              Unit. Data that is transported inside
                                                              the L-PDU. */
    } Can_PduType;

#ifdef CAN_MBCOUNTEXTENSION
    #if (CAN_MBCOUNTEXTENSION == STD_ON)
/**
* @{
* @brief          Can_HwHandleType
* @details        Represents the hardware object handles of a CAN hardware unit.
                  For CAN hardware units with more than 255 HW objects use extended range.
*                   - used by "Can_Write" function.
*                 The driver does not distinguish between Extended and Mixed transmission modes.
*                 Extended transmission mode of operation behaves the same as Mixed mode.
* @implements     Can_HwHandleType_type
*/
    typedef uint16 Can_HwHandleType;
    #else /* (CAN_MBCOUNTEXTENSION==STD_OFF) */
    typedef uint8 Can_HwHandleType;
    #endif /* (CAN_MBCOUNTEXTENSION==STD_ON/STD_OFF) */
#else
    typedef uint8 Can_HwHandleType;
#endif
/**@}*/

/**
* @brief          Can_HwType
* @details        This type defines a data structure which clearly provides an Hardware Object 
                    Handle including its corresponding CAN Controller and therefore CanDrv as well 
                    as the specific CanId.
* @implements     Can_HwType_structure
*/

typedef struct
{
    VAR(Can_IdType, CAN_VAR) CanId ; /**< @brief Standard/Extended CAN ID of CAN L-PDU. */
                                                 
    VAR(Can_HwHandleType, CAN_VAR)  Hoh; /**< @brief ID of the corresponding Hardware Object Range */
        
    VAR(uint8, CAN_VAR) ControllerId  ; /**< @brief ControllerId provided by CanIf clearly 
                                                identify the corresponding controller */
                                                
} Can_HwType;


/* Operating modes of the CAN Transceiver Driver. */
typedef enum
{
  CANTRCV_TRCVMODE_NORMAL,        /* Transceiver mode NORMAL */
  CANTRCV_TRCVMODE_SLEEP,    /* Transceiver mode SLEEP */
  CANTRCV_TRCVMODE_STANDBY       /*Transceiver mode STANDBY */
} CanTrcv_TrcvModeType;


/* CAN state transition type */
typedef enum
{
  CAN_T_START,    /* CAN controller transition value to request state STARTED */
  CAN_T_STOP,     /* CAN controller transition value to request state STOPPED */
  CAN_T_SLEEP,    /* CAN controller transition value to request state SLEEP */
  CAN_T_WAKEUP    /* CAN controller transition value to request state STOPPED
                     from state SLEEP  */
} Can_StateTransitionType;


/* Type for return values of few of the CAN Driver APIs */
typedef enum
{
  CAN_OK,        /* success */
  CAN_NOT_OK,    /* error occurred or wakeup occurred during sleep transition */
  CAN_BUSY       /* transmit request could not be processed because no transmit 
                    object was available */
} Can_ReturnType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*CAN_GENERAL_TYPES_H*/

/** @} */
