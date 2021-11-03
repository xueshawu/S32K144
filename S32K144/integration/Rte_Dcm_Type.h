/*-------------------------------- Arctic Core ------------------------------
 * Copyright (C) 2013, ArcCore AB, Sweden, www.arccore.com.
 * Contact: <contact@arccore.com>
 * 
 * You may ONLY use this file:
 * 1)if you have a valid commercial ArcCore license and then in accordance with  
 * the terms contained in the written license agreement between you and ArcCore, 
 * or alternatively
 * 2)if you follow the terms found in GNU General Public License version 2 as 
 * published by the Free Software Foundation and appearing in the file 
 * LICENSE.GPL included in the packaging of this file or here 
 * <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>
 *-------------------------------- Arctic Core -----------------------------*/

#ifndef RTE_DCM_TYPE_H_
#define RTE_DCM_TYPE_H_

#if !defined(DCM_UNIT_TEST) || (DCM_UNIT_TEST == STD_OFF)
#define DCM_NOT_SERVICE_COMPONENT
#endif

#ifdef USE_RTE
#warning This file should only be used when not using an RTE with Dcm service component.
#include "Rte_Type.h"
#define DCM_RES_POS_OK                          ((Dcm_ConfirmationStatusType)0x00)
#define DCM_RES_POS_NOT_OK                      ((Dcm_ConfirmationStatusType)0x01)
#define DCM_RES_NEG_OK                          ((Dcm_ConfirmationStatusType)0x02)
#define DCM_RES_NEG_NOT_OK                      ((Dcm_ConfirmationStatusType)0x03)

/*
 * Dcm_SesCtrlType
 */
#ifndef DCM_DEFAULT_SESSION
#define DCM_DEFAULT_SESSION                     ((Dcm_SesCtrlType)0x01)
#endif
#ifndef DCM_PROGRAMMING_SESSION
#define DCM_PROGRAMMING_SESSION                 ((Dcm_SesCtrlType)0x02)
#endif
#ifndef DCM_EXTENDED_DIAGNOSTIC_SESSION
#define DCM_EXTENDED_DIAGNOSTIC_SESSION         ((Dcm_SesCtrlType)0x03)
#endif
#ifndef DCM_SAFTEY_SYSTEM_DIAGNOSTIC_SESSION
#define DCM_SAFTEY_SYSTEM_DIAGNOSTIC_SESSION    ((Dcm_SesCtrlType)0x04)
#endif
#ifndef DCM_OBD_SESSION
#define DCM_OBD_SESSION                         ((Dcm_SesCtrlType)0x05)//only used for OBD diagnostic
#endif
#ifndef DCM_ALL_SESSION_LEVEL
#define DCM_ALL_SESSION_LEVEL                   ((Dcm_SesCtrlType)0xFF)
#endif

#else
typedef uint8 Dcm_ConfirmationStatusType;
#define DCM_RES_POS_OK                          ((Dcm_ConfirmationStatusType)0x00)
#define DCM_RES_POS_NOT_OK                      ((Dcm_ConfirmationStatusType)0x01)
#define DCM_RES_NEG_OK                          ((Dcm_ConfirmationStatusType)0x02)
#define DCM_RES_NEG_NOT_OK                      ((Dcm_ConfirmationStatusType)0x03)

typedef uint8 Dcm_NegativeResponseCodeType;

typedef uint8 Dcm_OpStatusType;

typedef uint8 Dcm_ProtocolType;

typedef uint8 Dcm_SesCtrlType;

/*
 * Dcm_SesCtrlType
 */
#ifndef DCM_DEFAULT_SESSION
#define DCM_DEFAULT_SESSION                     ((Dcm_SesCtrlType)0x01)
#endif
#ifndef DCM_PROGRAMMING_SESSION
#define DCM_PROGRAMMING_SESSION                 ((Dcm_SesCtrlType)0x02)
#endif
#ifndef DCM_EXTENDED_DIAGNOSTIC_SESSION
#define DCM_EXTENDED_DIAGNOSTIC_SESSION         ((Dcm_SesCtrlType)0x03)
#endif
#ifndef DCM_SAFTEY_SYSTEM_DIAGNOSTIC_SESSION
#define DCM_SAFTEY_SYSTEM_DIAGNOSTIC_SESSION    ((Dcm_SesCtrlType)0x04)
#endif
#ifndef DCM_OBD_SESSION
#define DCM_OBD_SESSION                         ((Dcm_SesCtrlType)0x05)//only used for OBD diagnostic
#endif
#ifndef DCM_ALL_SESSION_LEVEL
#define DCM_ALL_SESSION_LEVEL                   ((Dcm_SesCtrlType)0xFF)
#endif


#define E_NO_DTC_AVAILABLE		(Std_ReturnType)2u
#define E_SESSION_NOT_ALLOWED	(Std_ReturnType)4u
#define E_PROTOCOL_NOT_ALLOWED	(Std_ReturnType)5u
#define E_REQUEST_NOT_ACCEPTED	(Std_ReturnType)8u
#define E_REQUEST_ENV_NOK		(Std_ReturnType)9u
#define E_PENDING				(Std_ReturnType)10u
#define E_COMPARE_KEY_FAILED	(Std_ReturnType)11u
#define E_FORCE_RCRRP			(Std_ReturnType)12u


typedef uint8 Dcm_SecLevelType;

typedef uint8 Dcm_RoeStateType;

typedef uint8 DTRStatusType;



#endif
#endif /*RTE_DCM_TYPE_H_*/
