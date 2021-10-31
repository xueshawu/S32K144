


#ifndef CANIF_PRIV_H
#define CANIF_PRIV_H

/**
 * \defgroup CANIF_PRIV_H    CanIf_Priv - Private Function of CanIf.
 * \n
 */

/**************************************************************************************************
**                                    Include Section                                            **
**************************************************************************************************/

/* CanIf module header file */
#include "CanIf.h"

#if (CANIF_J1939NM_ENABLED != STD_OFF)
#include "J1939Nm.h"
#include "J1939Nm_Cbk.h"
#if (!defined(J1939NM_AR_RELEASE_MAJOR_VERSION) || (J1939NM_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION))
#error "AUTOSAR major version undefined or mismatched"
#endif
#if (!defined(J1939NM_AR_RELEASE_MINOR_VERSION) || (J1939NM_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION))
#error "AUTOSAR minor version undefined or mismatched"
#endif
#endif

#if (CANIF_PDUR_ENABLED != STD_OFF)
#include "PduR_CanIf.h"
#if (!defined(PDUR_AR_RELEASE_MAJOR_VERSION) || (PDUR_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION))
#error "AUTOSAR major version undefined or mismatched"
#endif
#if (!defined(PDUR_AR_RELEASE_MINOR_VERSION) || (PDUR_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION))
#error "AUTOSAR minor version undefined or mismatched"
#endif
#endif

#if (CANIF_CANNM_ENABLED != STD_OFF)
#include "CanNm_Cbk.h"
#if (!defined(CANNM_AR_RELEASE_MAJOR_VERSION) || (CANNM_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION))
#error "AUTOSAR major version undefined or mismatched"
#endif
#if (!defined(CANNM_AR_RELEASE_MINOR_VERSION) || (CANNM_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION))
#error "AUTOSAR minor version undefined or mismatched"
#endif
#endif

#if (CANIF_CANTP_ENABLED != STD_OFF)
#include "CanTp.h"
#include "CanTp_Cbk.h"
#if (!defined(CANTP_AR_RELEASE_MAJOR_VERSION) || (CANTP_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION))
//#error "AUTOSAR major version undefined or mismatched"
#endif
#if (!defined(CANTP_AR_RELEASE_MINOR_VERSION) || (CANTP_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION))
//#error "AUTOSAR minor version undefined or mismatched"
#endif
#endif

#if (CANIF_CANTSYN_ENABLED != STD_OFF)
#include "CanTSyn.h"
#include "CanTSyn_Cbk.h"
#if ( !defined(CANTSYN_AR_RELEASE_MAJOR_VERSION) || (CANTSYN_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION) )
#error "AUTOSAR major version undefined or mismatched"
#endif
#if ( !defined(CANTSYN_AR_RELEASE_MINOR_VERSION) || (CANTSYN_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION) )
#error "AUTOSAR minor version undefined or mismatched"
#endif
#endif

#if (CANIF_J1939TP_ENABLED != STD_OFF)
#include "J1939Tp.h"
#include "J1939Tp_Cbk.h"
#if (!defined(J1939TP_AR_RELEASE_MAJOR_VERSION) || (J1939TP_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION))
#error "AUTOSAR major version undefined or mismatched"
#endif
#if (!defined(J1939TP_AR_RELEASE_MINOR_VERSION) || (J1939TP_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION))
#error "AUTOSAR minor version undefined or mismatched"
#endif
#endif

#if (CANIF_XCP_ENABLED != STD_OFF)
#include "Xcp.h"
#include "XcpOnCan_Cbk.h"
#if (!defined(XCP_AR_RELEASE_MAJOR_VERSION) || (XCP_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION))
#error "AUTOSAR major version undefined or mismatched"
#endif
#if (!defined(XCP_AR_RELEASE_MINOR_VERSION) || (XCP_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION))
#error "AUTOSAR minor version undefined or mismatched"
#endif
#endif

#ifdef CANIF_ECUM_INTEGRATION
#if (CANIF_ECUM_INTEGRATION == STD_ON)
#include "EcuM.h"
#include "EcuM_Cbk.h"
#if (!defined(ECUM_AR_RELEASE_MAJOR_VERSION) || (ECUM_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION))
#error "AUTOSAR major version undefined or mismatched"
#endif
#if (!defined(ECUM_AR_RELEASE_MINOR_VERSION) || (ECUM_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION))
#error "AUTOSAR minor version undefined or mismatched"
#endif
#elif (CANIF_ECUM_INTEGRATION == STD_OFF)

#endif
#else
#include "EcuM.h"
#include "EcuM_Cbk.h"

#endif

/* Callback functions from Can Driver */
#include "CanIf_Cbk.h"

/* Errors during development will be reported to DET module */
#if (CANIF_DEV_ERROR_DETECT != STD_OFF)
#include "Det.h"
#if (!defined(DET_AR_RELEASE_MAJOR_VERSION) || (DET_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION))
#error "AUTOSAR major version undefined or mismatched"
#endif
#if (!defined(DET_AR_RELEASE_MINOR_VERSION) || (DET_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION))
#error "AUTOSAR minor version undefined or mismatched"
#endif
#endif
/* BSW Scheduler for CanIf */
#include "CanIf_Cfg_SchM.h"


/*
 ***************************************************************************************************
 * Defines
 ***************************************************************************************************
 */

/* API Service IDs */

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError.
 */
#define CANIF_INIT_SID                          0x01

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_InitController
 */
#define CANIF_INIT_CONTROLLER_SID               0x02

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_SetControllerMode
 */
#define CANIF_SET_CONTROLLER_SID                0x03

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_GetControllerMode
 */
#define CANIF_GET_CONTROLLER_SID                0x04

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_Transmit
 */

#define CANIF_TRANSMIT_SID                      0x05

#if (CANIF_READRXPDU_DATA_API != STD_OFF)
/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_ReadRxPduData
 */
#define CANIF_READ_RX_PDU_DATA_SID              0x06
#endif

#if (CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF)
/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_ReadTxNotifStatus
 */
#define CANIF_READ_TX_NOTIF_STATUS_SID          0x07
#endif

#if (CANIF_READRXPDU_NOTIFY_STATUS_API != STD_OFF)
/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_ReadRxNotifStatus
 */
#define CANIF_READ_RX_NOTIF_STATUS_SID          0x08
#endif

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_SetPduMode
 */
#define CANIF_SET_PDU_MODE_SID                  0x09

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_GetPduMode
 */
#define CANIF_GET_PDU_MODE_SID                  0x0A

#if (CANIF_VERSION_INFO_API != STD_OFF)
/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_GetVersionInfo
 */
#define CANIF_GET_VERSION_INFO_SID              0x0B
#endif

#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_SetDynamicTxId
 */
#define CANIF_SET_DYNAMIC_TXID_SID              0x0C
#endif

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_SetTrcvMode
 */
#define CANIF_SET_TRCV_MODE_SID                 0x0D

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_GetTrcvMode
 */
#define CANIF_GET_TRCV_MODE_SID                 0x0E

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_GetTrcvWakeupReason
 */
#define CANIF_GET_TRCV_WUMODE_REASON_SID        0x0F

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_SetTrcvWakeupMode
 */
#define CANIF_SET_TRCV_WAKEUPMODE_SID           0x10

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_CheckValidation
 */
#define CANIF_CHECKWAKEUP_SID                   0x11

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_CheckValidation
 */
#define CANIF_CHECKVALIDATION_SID               0x12

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_TxConfirmation
 */
#define CANIF_TX_CONFIRMATION_SID               0x13

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_RxIndication
 */
#define CANIF_RX_INDICATION_SID                 0x14

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_ControllerBusOff
 */
#define CANIF_CONTROLLER_BUSOFF_SID             0x16

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_ControllerModeIndication
 */
#define CANIF_CONTROLLER_MODE_IND_SID            0x17

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_TrcvModeIndication
 */
#define CANIF_TRCVMODEINDICATION_SID            0x18


#if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_GetTxConfirmationState
 */
#define CANIF_GET_TX_CONFIRMATION_STATE_SID     0x19
#endif

/* FC_VariationPoint_START */
/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_ControllerErrorPassive
 */
#define CANIF_CONTROLLER_ERRORPASSIVE_SID       0x22
/* FC_VariationPoint_END */

/* FC_VariationPoint_START */
/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_ResetDynamicTxId
 */
#define CANIF_RESET_DYNAMIC_TXID_SID            0x23
/* FC_VariationPoint_END */

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_CheckBaudrate
 */
#define CANIF_CHECKBAUDRATE_SID                    0x1A

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_ChangeBaudrate
 */
#define CANIF_CHANGEBAUDRATE_SID                0x1B
/* FC_VariationPoint_START */
/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_SetBaudrate
 */
#define CANIF_SETBAUDRATE_SID                   0x27
/* FC_VariationPoint_END */
/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_ClearTrcvWufFlag
 */
#define CANIF_CLEARTRCVWUFFLAG_SID                0x1E

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_CheckTrcvWakeFlag
 */
#define CANIF_CHECKTRCVWAKEFLAG_SID                0x1F

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_ClearTrcvWufFlagIndication
 */
#define CANIF_CLEARTRCVWAKEFLAGIND_SID            0x20

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CANIF_CHECKTRCVWAKEFLAGIND_SID
 */
#define CANIF_CHECKTRCVWAKEFLAGIND_SID            0x21

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_ConfirmPnAvailability
 */
#define CANIF_CONFIRMPNAVAILABILITY_SID            0x1a

/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_CancelTransmit
 */
#define CANIF_CANCELTRANSMIT_SID                0x25
/* FC_VariationPoint_START */
/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_ReturnTxPduId
 */
#define CANIF_RETURN_TX_PDU_ID_SID                0x1C
/**
 * @ingroup CANIF_PRIV_H
 *
 * Indicates that Api Id passed in the call of Det_ReportError corresponds to @see CanIf_ReturnRxPduId
 */
#define CANIF_RETURN_RX_PDU_ID_SID                0x1D
/* FC_VariationPoint_END */
/* Error IDs */
#if (CANIF_DEV_ERROR_DETECT != STD_OFF)

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * CANIF_E_PARAM_CANID: API service called with invalid parameter
 * */
#define CANIF_E_PARAM_CANID                     10

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * CANIF_E_PARAM_DLC: API service called with invalid parameter
 * */
#define CANIF_E_PARAM_DLC                       11

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * CANIF_E_PARAM_HRH: API service called with invalid parameter
 * */
#define CANIF_E_PARAM_HRH                       12

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * CANIF_E_PARAM_LPDU: API service called with invalid parameter
 * */
#define CANIF_E_PARAM_LPDU                      13

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * CANIF_E_PARAM_CONTROLLER: API service called with invalid parameter
 * */
#define CANIF_E_PARAM_CONTROLLER                14

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * CANIF_E_PARAM_CONTROLLERID: API service called with invalid parameter
 * */
#define CANIF_E_PARAM_CONTROLLERID              15

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * CANIF_E_PARAM_WAKEUPSOURCE: API service called with invalid parameter
 * */
#define CANIF_E_PARAM_WAKEUPSOURCE              16

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * CANIF_E_PARAM_TRCV: API service called with invalid parameter
 * */
#define CANIF_E_PARAM_TRCV                      17

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * CANIF_E_PARAM_TRCVMODE: API service called with invalid parameter
 * */
#define CANIF_E_PARAM_TRCVMODE                  18

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * CANIF_E_PARAM_TRCVWAKEUPMODE: API service called with invalid parameter
 * */
#define CANIF_E_PARAM_TRCVWAKEUPMODE            19

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * CANIF_E_PARAM_POINTER: API service called with invalid pointer
 * */
#define CANIF_E_PARAM_POINTER                   20

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * CANIF_E_UNINIT: API service used without module initialization
 * */
#define CANIF_E_UNINIT                          30

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * CANIF_E_NOK_NOSUPPORT: Requested API operation is not supported
 * */
#define CANIF_E_NOK_NOSUPPORT                   40

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * CANIF_E_INVALID_RXPDUID: Receive PDU ID invalid
 * */
#define CANIF_E_INVALID_RXPDUID                 60

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * CANIF_E_INVALID_TXPDUID: Transmit PDU ID invalid
 * */
#define CANIF_E_INVALID_TXPDUID                 50


/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * Not specified in CANIF 4.0, used in CanIf_SetControllerMode()
 * */
#define CANIF_E_PARAM_CONTROLLERMODE            61

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * Not specified in CANIF 4.0, used in CanIf_Transmit(), Invalid Lenght passed by Upper Layer
 * */
#define CANIF_E_DATA_LENGTH_MISMATCH                      62

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * If (cfg_dlc != 0 && rx_dlc < cfg_dlc), then report invalid dlc error
 * */
#define CANIF_E_INVALID_DLC                     63

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * If Pdu mode is OFFLINE, then report controller stopped error
 * */
#define CANIF_E_CTRL_STOPPED                    64

/**
 * @ingroup CANIF_PRIV_H
 * CANIF: DET Error ID'd*
 * During wakeup check if device is not in sleep mode then report not sleep error
 * */
#define CANIF_E_CTRL_NOT_SLEEP                  65

#endif


/**
 * @ingroup CANIF_PRIV_H
 *
 * Invokes the SchM_Enter function to enter a module local exclusive area.
 */


/**
 * @ingroup CANIF_PRIV_H
 *
 * Invokes the SchM_Exit function to exit an exclusive area.
 */

/**
 * @ingroup CANIF_PRIV_H
 *
 * Return value in case wakeup event / validation was not available
 */
#define CANIF_WAKEUP_SOURCE_CLEAR               0


/**
 * @ingroup CANIF_PRIV_H
 *
 *  Maximum value a STANDARD CAN ID can have
 */
#define CANIF_CAN_STD_VAL                       0x7FFu


/**
 * @ingroup CANIF_PRIV_H
 *
 *  Maximum value a EXTENDED CAN ID can have
 */
#define CANIF_CAN_XTD_VAL                       0x1FFFFFFFu


/**
 * @ingroup CANIF_PRIV_H
 *
 *  Values used to come out of the function
 */
#define CANIF_RESET                             0
/**
 * @ingroup CANIF_PRIV_H
 *
 * Values used to come out of the function
 */
#define CANIF_SET                               1


/**
 * @ingroup CANIF_PRIV_H
 *
 * Maximum length of DLC
 */
/* FC_VariationPoint_START */
#if(CANIF_FD_SUPPORT == STD_ON)
#define CANIF_MAX_DLC                           64
#else
/* FC_VariationPoint_END */
#define CANIF_MAX_DLC                           8
/* FC_VariationPoint_START */
#endif
/* FC_VariationPoint_END */


/**
 * @ingroup CANIF_PRIV_H
 *
 * Configuration for reading Rx Notification status only
 */
#define CANIF_READ_NOTIFSTATUS                  0x10


/**
 * @ingroup CANIF_PRIV_H
 *
 * Configuration for reading received data only
 */
#define CANIF_READ_DATA                         0x01


/**
 * @ingroup CANIF_PRIV_H
 *
 * Configuration for reading both notification status and data
 */
#define CANIF_READ_NOTIFSTATUS_DATA             0x11


/**
 * @ingroup CANIF_PRIV_H
 *
 *  Configuration for reading neither notification status nor data
 */
#define CANIF_READ_NONE                         0x00


/**
 * @ingroup CANIF_PRIV_H
 *
 * Currently since the PduIdtype is uint8, the value is 255u.
 *  If the PduIdType changes to uint16, the value has to be changed to 65535u
 */
#define CANIF_STATIC                            255u


/**
 * @ingroup CANIF_PRIV_H
 *
 * Buffer offset when buffer is not allocated to the Pdu
 */
#define CANIF_MAX_BUFFER_OFFSET                 0xFFFFu

/* FC_VariationPoint_START */
/**
 * @ingroup CANIF_PRIV_H
 *
 * Resetting two most significant bit for Extended or standard type
 */
#if ((CANIF_EXTENDED_ID == STD_ON)||(CANIF_SETDYNAMICTXID_API == STD_ON))
#define CANIF_MSB_BIT_RESET                 0x3FFFFFFFu
#else
#define CANIF_MSB_BIT_RESET                 0x3FFFu
#endif

#if ((CANIF_EXTENDED_ID == STD_ON)||(CANIF_SETDYNAMICTXID_API == STD_ON))
#define CANIF_CANID_BIT_SHIFT                           30u
#else
/* FC_VariationPoint_END */
#define CANIF_CANID_BIT_SHIFT                           14u
/* FC_VariationPoint_START */
#endif

#define CANIF_CANID_TYPE_MASK                           0x0fu

/**
 * @ingroup CANIF_PRIV_H
 *
 * Macro for value zero
 */
#define CANIF_ZERO                 0u

/**
 * @ingroup CANIF_PRIV_H
 *
 * Macro for value one
 */
#define CANIF_ONE                 1u

/**
 * @ingroup CANIF_PRIV_H
 *
 * Macro for value two
 */
#define CANIF_TWO                 2u

/**
 * @ingroup CANIF_PRIV_H
 *
 * Macro for value three
 */
#define CANIF_THREE                 3u

/**
 * @ingroup CANIF_PRIV_H
 *
 * Macro for value four
 */
#define CANIF_FOUR                  4u

/**
 * @ingroup CANIF_PRIV_H
 *
 * Macro for DLC 8
 */
#define DLC_8                       8u

/**
 * @ingroup CANIF_PRIV_H
 *
 * Macro for DLC 64
 */
#define DLC_64                      64u

#if (CANIF_METADATA_SUPPORT != STD_OFF)
/**
 * @ingroup CANIF_PRIV_H
 *
 * Macro for SHIFT 8 times
 */
#define SHIFT_8                     8u

/**
 * @ingroup CANIF_PRIV_H
 *
 * Macro for Standard CanId size
 */
#define CANID_SIZE_STD              2u

/**
 * @ingroup CANIF_PRIV_H
 *
 * Macro for Extended CanId size
 */
#define CANID_SIZE_XTD              4u

/**
 * @ingroup CANIF_PRIV_H
 *
 * Macro for MetaData Mask
 */
#define CANIF_CANID_MASK         0x0000FFFFU

/**
 * @ingroup CANIF_PRIV_H
 *
 * Macro for SDU Data buffer size
 */
#define SDU_DATA_BUFF_SIZE       68u

#endif /* (CANIF_METADATA_SUPPORT != STD_OFF) */
/* FC_VariationPoint_END */

/**
 * @ingroup CANIF_PRIV_H
 *
 * Macro for Default CanId mask value
 */
#define CANID_MASK_DEFAULT       0x1FFFFFFFU


/*
 ***************************************************************************************************
 * Variables
 ***************************************************************************************************
 */

/**
 * @ingroup CANIF_PRIV_H
 *
 *  Flag to check if the CAN Interface is Initialized(TRUE) or Not Initialized (FALSE)
 */
#define CANIF_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanIf_MemMap.h"
extern VAR(boolean, CANIF_VAR) CanIf_Init_Flag;
#define CANIF_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanIf_MemMap.h"

/**
 * @ingroup CANIF_PRIV_H
 *
 * Callback function Array
 */
#if(CANIF_VARIANT_INFO != 2) && (CANIF_VARIANT_INFO != 3)
#define CANIF_START_SEC_CONST_UNSPECIFIED
#else
#define CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#endif
#include "CanIf_MemMap.h"
extern CONST(CanIf_CallbackFuncType, CANIF_CONST) CanIf_Callback;
#if(CANIF_VARIANT_INFO != 2) && (CANIF_VARIANT_INFO != 3)
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#else
#define CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#endif
#include "CanIf_MemMap.h"

/*The below part of the code shall be enabled only for Pre-Compile.
 * For Post-build, the extern declarations are available in CanIf_PBCfg.h*/
/*-----------------------------------------------------------------------------*/
#if(CANIF_VARIANT_INFO == 1)

/**
 * @ingroup CANIF_PRIV_H
 *
 *  TX handle configuration array
 */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
extern CONST(CanIf_TxPduInfo, CANIF_CONST) CanIf_TxPduConfig[CANIF_NUM_STATIC_CANTXPDUIDS + CANIF_NUM_DYNAMIC_CANTXPDUIDS];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"


#if(CANIF_CANNM_TXID_FILTER != STD_OFF)
/**
 * @ingroup CANIF_PRIV_H
 *
 * List of CanNm Tx-Pdus
 */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
extern CONST(CanIf_CanIdType, CANIF_CONST) CanIf_CanNmTxId[];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
#endif



/**
 * @ingroup CANIF_PRIV_H
 *
 * RX handle configuration array
 */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
extern CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[CANIF_NUM_CANRXPDUIDS];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"

#if (CANIF_BASIC_CAN_SUPPORT_LIST != 0)
/**
 * @ingroup CANIF_PRIV_H
 *
 * CanIds configured to be received as a  'list'
 */

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
extern CONST(CanIf_CanIdListConfigType, CANIF_CONST) CanIf_CanIdListConfig[];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
#endif

#if (CANIF_RXPDU_CANID_RANGE != STD_OFF)
/**
 * @ingroup CANIF_PRIV_H
 *
 * CanIds configured to be received as a 'range'
 */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
extern CONST(CanIf_RxPduCanIdRangeConfigType, CANIF_CONST) CanIf_RxPduCanIdRangeConfig[];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
#endif

/**
 * @ingroup CANIF_PRIV_H
 *
 * List of HRHs configured
 */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
extern CONST(CanIf_HrhConfigType, CANIF_CONST) CanIf_HrhConfig[CANIF_NUM_HRH_HANDLES];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"


/**
 * @ingroup CANIF_PRIV_H
 *
 * Rx Callback functions with the parameters - PduIdType, const CanIf_PduInfoType*
 */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
extern CONST(CanIf_RxCbk_Prototype, CANIF_CONST) CanIf_RxCbk[];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
/**
 * @ingroup CANIF_PRIV_H
 *
 * Rx Callback functions with the parameters - PduIdType, const CanIf_PduInfoType*
 */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
extern CONST(CanIf_CddRxCbk_Prototype, CANIF_CONST) CanIf_CddRxCbk[];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
/**
 * @ingroup CANIF_PRIV_H
 *
 * Rx Callback functions with the parameters - Can_HwHandleType, CanId, CanDlc, CanSduPtr*
 */
#if (CANIF_READBUFFERID != STD_OFF)
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
extern CONST(CanIf_J1939RxCbk_Prototype,CANIF_CONST) CanIf_J1939RxCbk;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
#endif
/**
 * @ingroup CANIF_PRIV_H
 *
 * Tx Callback functions with the parameters - PduIdType
 */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
extern CONST(CanIf_TxCbk_Prototype, CANIF_CONST) CanIf_TxCbk[];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"

/* FC_DeviationPoint_START */
#if (CANIF_DYNAMIC_ID != STD_OFF)
/* FC_DeviationPoint_END */

/* FC_CODE_START */
//#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
 /* FC_CODE_END */
/**
 * @ingroup CANIF_PRIV_H
 *
 *  Store the CanId's which was set by the CanIf_SetDynamicTxPduId( )
 */
#define CANIF_START_SEC_VAR_CLEARED_32
#include "CanIf_MemMap.h"
extern VAR(uint32, CANIF_VAR) CanIf_Dynamic_CanTxPdu_CanId[CANIF_NUM_DYNAMIC_CANTXPDUIDS];
#define CANIF_STOP_SEC_VAR_CLEARED_32
#include "CanIf_MemMap.h"
#endif


/**
 * @ingroup CANIF_PRIV_H
 *
 * Store the Device Mode and Channel Mode of each controller
 */
#define CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"
extern VAR(CanIf_ControllerStateType, CANIF_VAR) CanIf_ControllerState[CANIF_NUM_CONTROLLERS];
#define CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"

/**
 * @ingroup CANIF_PRIV_H
 *
 * Store the Notification Status of each CanTxPduId
 */
#define CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"
extern VAR(CanIf_NotifStatusType, CANIF_VAR) CanIf_TxNotification[CANIF_NUM_STATIC_CANTXPDUIDS + CANIF_NUM_DYNAMIC_CANTXPDUIDS];
#define CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"

#if (CANIF_READRXPDU_NOTIFY_STATUS_API != STD_OFF)

/**
 * @ingroup CANIF_PRIV_H
 *
 * Store the Notification Status of each CanRxPduId
 */
#define CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"
extern VAR(CanIf_NotifStatusType, CANIF_VAR) CanIf_RxNotification[CANIF_NUM_CANRXPDUIDS];
#define CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"
#endif

 /* FC_DeviationPoint_START */
#if (CANIF_TRANSMIT_BUFFER != STD_OFF)
 	/* FC_DeviationPoint_END */

/* FC_CODE_START */
//#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
/*  FC_CODE_END */


/**
 * @ingroup CANIF_PRIV_H
 *
 * Array to hold the transmit buffer allocation status
 */
#define CANIF_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanIf_MemMap.h"
extern VAR(boolean, CANIF_VAR) CanIf_TxBufferAllocated[CANIF_NUM_STATIC_CANTXPDUIDS + CANIF_NUM_DYNAMIC_CANTXPDUIDS];
#define CANIF_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanIf_MemMap.h"


#define CANIF_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanIf_MemMap.h"
/**
 * @ingroup CANIF_PRIV_H
 *
 * BASIC HTH busy status Array
 */
extern VAR(boolean, CANIF_VAR) CanIf_HTHBusyStatusFlag_a_b[CANIF_NUM_BASIC_HTH];
#define CANIF_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanIf_MemMap.h"
/**
 * @ingroup CANIF_PRIV_H
 *
 * TxBuffer Array
 */
#define CANIF_START_SEC_VAR_CLEARED_8
#include "CanIf_MemMap.h"
extern VAR(uint8, CANIF_VAR) CanIf_TxBuffer[CANIF_TXBUFFER_SIZE];
#define CANIF_STOP_SEC_VAR_CLEARED_8
#include "CanIf_MemMap.h"
#endif
/* FC_DeviationPoint_START */
#if (CANIF_RECEIVE_BUFFER != STD_OFF)
/* FC_DeviationPoint_END */

/* FC_CODE_START */
 //#if (CANIF_READRXPDU_DATA_API != STD_OFF)
/* FC_CODE_END */
/**
 * @ingroup CANIF_PRIV_H
 *
 *  RxBuffer Array
 */
#define CANIF_START_SEC_VAR_CLEARED_8
#include "CanIf_MemMap.h"
extern VAR(uint8, CANIF_VAR) CanIf_RxBuffer[CANIF_RXBUFFER_SIZE];
#define CANIF_STOP_SEC_VAR_CLEARED_8
#include "CanIf_MemMap.h"
#endif

#if (CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)

/**
 * @ingroup CANIF_PRIV_H
 *
 * To store the wakeup events
 */
#define CANIF_START_SEC_VAR_CLEARED_8
#include "CanIf_MemMap.h"
extern VAR(uint8, CANIF_VAR) CanIf_WakeUp_Event[CANIF_NUM_CONTROLLERS];
#define CANIF_STOP_SEC_VAR_CLEARED_8
#include "CanIf_MemMap.h"

/**
 * @ingroup CANIF_PRIV_H
 *
 *  To store the status of a new Rx message
 */
#define CANIF_START_SEC_VAR_CLEARED_8
#include "CanIf_MemMap.h"
extern VAR(uint8, CANIF_VAR) CanIf_NewMsg_Rx[CANIF_NUM_CONTROLLERS];
#define CANIF_STOP_SEC_VAR_CLEARED_8
#include "CanIf_MemMap.h"
#endif


#if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)

/**
 * @ingroup CANIF_PRIV_H
 *
 * Array to hold the transmit confirmation status
 */
#define CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"
extern VAR(CanIf_NotifStatusType, CANIF_VAR) CanIf_TxConf_State[CANIF_NUM_CONTROLLERS];
#define CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"
#endif

/*Wakeup LUT*/
#if(CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
/**
 * @ingroup CANIF_PRIV_H
 *
 * WakeupSourceId - Transceiver Id Look up table
 */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
extern CONST (CanIf_WakeupLUT_Type, CANIF_CONST) CanIf_Wakeup_LUT[CANIF_NUM_CONTROLLERS];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
#endif

#endif
/*-----------------------------------------------------------------------------*/

#if (CANIF_VARIANT_INFO ==2) || (CANIF_VARIANT_INFO ==3)
/*This hold the current config set details*/
#define CANIF_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"
extern P2CONST(CanIf_ConfigType, AUTOMATIC, AUTOMATIC) CanIf_ConfigSetPtr;
#define CANIF_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_FAST_CLEARED_8
#include "CanIf_MemMap.h"
extern VAR(uint8, AUTOMATIC) CanIf_ActiveCfgSet;
#define CANIF_STOP_SEC_VAR_FAST_CLEARED_8
#include "CanIf_MemMap.h"
#endif

/* Check whether given condition is satisfied, call Det_ReportError() */
#if CANIF_DEV_ERROR_DETECT != STD_OFF

     /**
       * @ingroup CANIF_PRIV_H
       *
       * Macro For functions with return type as 'void'
       */

    #define CANIF_DET_REPORT_ERROR(CONDITION, API, ERROR)                                                       \
                                   if(CONDITION)                                                                \
                                   {                                                                            \
                                        (void)Det_ReportError((CANIF_MODULE_ID), (CANIF_INSTANCE_ID), (API), (ERROR));\
                                        return;                                                                 \
                                   }


     /**
       * @ingroup CANIF_PRIV_H
       *
       * Macro For functions with return type as  'Std_ReturnType'
       */
    #define CANIF_DET_REPORT_ERROR_NOK(CONDITION, API, ERROR)                                                   \
                                   if(CONDITION)                                                                \
                                   {                                                                            \
                                       (void)Det_ReportError((CANIF_MODULE_ID), (CANIF_INSTANCE_ID), (API), (ERROR));\
                                        return E_NOT_OK;                                                        \
                                   }

     /**
       * @ingroup CANIF_PRIV_H
       *
       * Macro For functions with return type as 'CanIf_NotifStatusType'
       */

    #if (CANIF_READRXPDU_NOTIFY_STATUS_API != STD_OFF || CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF || CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
        #define CANIF_DET_REPORT_ERROR_NO_NOTIF(CONDITION, API, ERROR)                                          \
                                   if(CONDITION)                                                                \
                                   {                                                                            \
                                       (void)Det_ReportError((CANIF_MODULE_ID), (CANIF_INSTANCE_ID), (API), (ERROR));\
                                        return CANIF_NO_NOTIFICATION;                                           \
                                   }
    #endif

	/* FC_VariationPoint_START */
		/*det macro is added to check invalid dlc  */
	 /**
       * @ingroup CANIF_PRIV_H
       *
       * Macro For functions with no return element
       */

	   #define CANIF_DET_REPORT_ERROR_NOR(CONDITION, API, ERROR)                                                   \
                                   if(CONDITION)                                                                \
                                   {                                                                            \
                                       (void)Det_ReportError((CANIF_MODULE_ID), (CANIF_INSTANCE_ID), (API), (ERROR));\
								   }
    /**
     * @ingroup CANIF_PRIV_H
     *
     * Macro For functions with return type as 'Std_ReturnType'. Unlocks the interrupts before return.
     */
    #define CANIF_DET_REPORT_ERROR_SCHM_EXIT_NOK(CONDITION, API, ERROR, SCHM_EXIT_FUNC)                               \
                                    if(CONDITION)                                                                     \
                                    {                                                                                 \
                                        (void)Det_ReportError((CANIF_MODULE_ID), (CANIF_INSTANCE_ID), (API), (ERROR));\
                                        /* MR12 RULE 20.7, VIOLATION: This Warning is "Not Critical". The parameter SCHM_EXIT_FUNC is used to function call. */ \
                                        SCHM_EXIT_FUNC();                                                             \
                                        return E_NOT_OK;                                                              \
                                    }
	/* FC_VariationPoint_END */
#else
    #define CANIF_DET_REPORT_ERROR(CONDITION, API, ERROR)

    #define CANIF_DET_REPORT_ERROR_NOK(CONDITION, API, ERROR)

    #if (CANIF_READRXPDU_NOTIFY_STATUS_API != STD_OFF || CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF || CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
        #define CANIF_DET_REPORT_ERROR_NO_NOTIF(CONDITION, API, ERROR)
    #endif

    #define CANIF_DET_REPORT_ERROR_SCHM_EXIT_NOK(CONDITION, API, ERROR, SCHM_EXIT_FUNC)

#endif

/*Trcv LUT*/
#if (CANIF_TRCV_DRV_CFG != STD_OFF)
/**
 * @ingroup CANIF_PRIV_H
 *
 * Transceiver Look up table
 */
#define CANIF_START_SEC_CONST_8
#include "CanIf_MemMap.h"
extern CONST (uint8, CANIF_CONST) CanIf_Trcv_LUT[CANIF_NUM_TRANSCEIVERS];
#define CANIF_STOP_SEC_CONST_8
#include "CanIf_MemMap.h"
#endif

/*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
 */
 /* FC_DeviationPoint_START */
#if ((CANIF_TRANSMIT_BUFFER != STD_OFF) || (CANIF_RECEIVE_BUFFER != STD_OFF))
 /* FC_DeviationPoint_END */

 /* FC_CODE_START */
  //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF) || (CANIF_READRXPDU_DATA_API != STD_OFF)
/* FC_CODE_END */
/**
 * @ingroup CANIF_PRIV_H
 *
 *  Service called by CanIf to clear the transmit/ receive buffer .       \n
 *
 *  @param       Controller -  controller ID                      \n
 *  @param       BufferType   - Transmit or Receive Buffer   \n
 *
 *  @return None \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_ClearBuffer(
                                                    VAR(uint8, AUTOMATIC) Controller,
                                                    VAR(CanIf_BufferType, AUTOMATIC) BufferType
                                               );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif

 /* FC_DeviationPoint_START */
#if (CANIF_TRANSMIT_BUFFER != STD_OFF)
     /* FC_DeviationPoint_END */

        /* FC_CODE_START */
 //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
  /*  FC_CODE_END */
/**
 * @ingroup CANIF_PRIV_H
 *
 *  Service called by CanIf function - CanIf_Transmit() to write into the transmit buffer .       \n
 *
 *  @param       CanTxPduId -  pdu id  for Tx msg                      \n
 *  @param       PduInfoPtr   -  Tx message   \n
 *
 *  @return None \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_WriteTxBuffer(
                                                    VAR(PduIdType, AUTOMATIC) CanTxPduId,
                                                    P2CONST (PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr
                                                 );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

/**
 * @ingroup CANIF_PRIV_H
 *
 *  Service called by CanIf function - CanIf_SetChannelMode() to clear the transmit buffer.       \n
 *
 *  @param       Controller -     controller ID                    \n
 *
 *  @return None \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_ClearTxChannelBuffer(VAR(uint8, AUTOMATIC) Controller);
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif
/* FC_DeviationPoint_START */
#if (CANIF_RECEIVE_BUFFER != STD_OFF)
/* FC_DeviationPoint_END */

/* FC_CODE_START */
 //#if (CANIF_READRXPDU_DATA_API != STD_OFF)
/* FC_CODE_END */
/**
 * @ingroup CANIF_PRIV_H
 *
 *  Service called by CanIf function - CanIf_RxIndication() to write data into the receive buffer.       \n
 *
 *  @param       CanSduPtr -     Rx message                    \n
 *  @param      RxPduCfgPtr   -  Reference to  Canif_RxPduConfig[]\n
 *
 *  @return None \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_WriteRxBuffer(
                                                    P2CONST (uint8, AUTOMATIC, CANIF_APPL_CONST) CanSduPtr,
                                                    P2CONST(CanIf_RxPduConfigType, AUTOMATIC, AUTOMATIC) RxPduCfgPtr
                                                 );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
/**
 * @ingroup CANIF_PRIV_H
 *
 * Service called by CanIf function CanIf_ReadRxPduData() to read data from the receive buffer.       \n
 *
 *  @param       PduInfoPtr -    Rx message           \n
 *  @param       RxPduCfgPtr   -  Reference to  Canif_RxPduConfig[]  \n
 *
 *  @return None \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_ReadRxBuffer(
                                                    P2VAR (PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr,
                                                    P2CONST(CanIf_RxPduConfigType, AUTOMATIC, AUTOMATIC) RxPduCfgPtr
                                                );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif

#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
FUNC(PduIdType, CANIF_CODE) CanIf_SearchRxPduId(P2CONST(CanIf_RxPduConfigType, AUTOMATIC, CANIF_CONST) CanIf_RxPduConfigPtr,
                                                VAR(uint16, AUTOMATIC) CanIf_Num_Elements,
                                                VAR(PduIdType, AUTOMATIC) CanRxPduId,
                                                P2VAR(uint8, AUTOMATIC, CANIF_APPL_CONST) SearchStatusPtr);
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#if (CANIF_VARIANT_INFO ==3) /* CanIf_CompareVersionInfo */


LOCAL_INLINE VAR(boolean, AUTOMATIC) CanIf_CompareVersionInfo(
                                                               P2CONST(Std_VersionInfoType, AUTOMATIC, CANIF_APPL_CONST) srcVersionInfo,
                                                               P2CONST(Std_VersionInfoType, AUTOMATIC, CANIF_APPL_CONST) destVersionInfo
                                                              );
/**
 ***************************************************************************************************
 * CanIf_CompareVersionInfo - compare version info structures ie of type Std_VersionInfoType
 *
 * compare version info structures ie of type Std_VersionInfoType.
 *
 * \param   srcVersionInfo      pointer to first Std_VersionInfoType structure
 * \param   destVersionInfo     pointer to second Std_VersionInfoType structure
 * \return  stEqual_b           result of comparison
 * \retval  FALSE               memory area contents are equal
 * \retval  TRUE                memory area contents differ
  ***************************************************************************************************
 */

LOCAL_INLINE VAR(boolean, AUTOMATIC) CanIf_CompareVersionInfo(
                                                                P2CONST(Std_VersionInfoType, AUTOMATIC, CANIF_APPL_CONST) srcVersionInfo,
                                                                P2CONST(Std_VersionInfoType, AUTOMATIC, CANIF_APPL_CONST) destVersionInfo
                                                              )
{
    VAR(boolean, AUTOMATIC)   stEqual_b;
    stEqual_b = TRUE;
    if ((srcVersionInfo->vendorID == destVersionInfo->vendorID) &&
        (srcVersionInfo->moduleID == destVersionInfo->moduleID) &&
        (srcVersionInfo->sw_major_version == destVersionInfo->sw_major_version) &&
        (srcVersionInfo->sw_minor_version == destVersionInfo->sw_minor_version) &&
        (srcVersionInfo->sw_patch_version == destVersionInfo->sw_patch_version)
    )
    {
        stEqual_b = FALSE;
    }
    return stEqual_b;
}



#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(void, CANIF_CODE)  CanIfAppl_IncompatibleGenerator(void);


#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif /* CanIf_CompareVersionInfo */
#endif  /* CANIF_PRIV_H */

/* FC_VariationPoint_START */

/* FC_VariationPoint_END */
