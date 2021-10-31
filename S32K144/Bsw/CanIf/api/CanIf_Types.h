

/**
\defgroup CANIF_TYPES_H    CANIF - AUTOSAR interfaces CANIF callback functions
*/
#ifndef CANIF_TYPES_H
#define CANIF_TYPES_H

/**************************************************************************************************/
/*              Include Section                                                                   */
/**************************************************************************************************/
/* Include the ComStack definitions */
/*Version check for ComStack_types and CanIf done in CanIf.h*/
#include "ComStack_Types.h"

/* Include the ComStack definitions */
/*Version check for CanIf and CanDrv done in CanIf_SetControllerMode.c file*/
#include "Can_GeneralTypes.h"

/*EcuM_Cbk.h required to get the EcuM_WakeupSourceType*/
/*Version check for EcuM and CanIf done in CanIf_Priv.h*/
#include "EcuM_Cbk.h"

/*CanIf_Cfg.h is required for the generated macros which is used in this file*/
#include "CanIf_Cfg.h"

/*
 ***************************************************************************************************
 * Type definitions
 ***************************************************************************************************
 */

/**
 * @ingroup CANIF_TYPES_H
 *
 * Types of Controller modes                                                                        \n
 * typedef enum                                                                                     \n
 *{                                                                                                 \n
 *   CANIF_SET_OFFLINE = 0,             No transmission and reception in channel                    \n
 *   CANIF_SET_RX_OFFLINE,              Receive path of the channel disabled                        \n
 *   CANIF_SET_RX_ONLINE,               Receive path of the corresponding channel shall be enabled  \n
 *   CANIF_SET_TX_OFFLINE,              Transmit path of channel disabled                           \n
 *   CANIF_SET_TX_ONLINE,               Transmit path of channel enabled                            \n
 *   CANIF_SET_ONLINE,                  Set to full operation mode                                  \n
 *   FC_VariationPoint_START                                                                          \n
 *  #if (CANIF_USER_TP_TX_OFFLINE_MODE != STD_OFF)                                                    \n
 *  CANIF_SET_TX_TP_ONLINE,             Set the Transmission TP Online                              \n
 *  CANIF_SET_TX_USER_TP_ONLINE,        Set the Tx User TP Online                                   \n
 *  #endif                                                                                          \n
 *    FC_VariationPoint_END                                                                             \n
 *    CANIF_SET_TX_OFFLINE_ACTIVE,        Notifications are processed but transmit requests are blocked\n
 *  FC_VariationPoint_START                                                                         \n
 *  CANIF_SET_MAXREQUEST                Max number of requests                                      \n
 *    FC_VariationPoint_END                                                                             \n
 *}CanIf_PduSetModeType;                                                                            \n
 */
typedef enum
{


/* Channel request modes */
    CANIF_SET_OFFLINE = 0,
    CANIF_SET_RX_OFFLINE,
    CANIF_SET_RX_ONLINE,
    CANIF_SET_TX_OFFLINE,
    CANIF_SET_TX_ONLINE,
    CANIF_SET_ONLINE,
    /* FC_VariationPoint_START */
    #if (CANIF_USER_TP_TX_OFFLINE_MODE != STD_OFF)
    CANIF_SET_TX_TP_ONLINE,
    CANIF_SET_TX_USER_TP_ONLINE,
    #endif
    /* FC_VariationPoint_END */
    CANIF_SET_TX_OFFLINE_ACTIVE,
    CANIF_SET_MAXREQUEST
}CanIf_PduSetModeType;

/**
 * @ingroup CANIF_TYPES_H
 * Channel Modes
 * Status of the PDU channel group \n
 *
 * typedef enum
 *{
 *   CANIF_GET_OFFLINE = 0,             no transmission and reception \n
 *   CANIF_GET_RX_ONLINE,               Receive path of the channel is enabled and transmit path is disabled. \n
 *   CANIF_GET_TX_ONLINE,               Transmit path of the channel is enabled and receive path is disabled. \n
 *   CANIF_GET_ONLINE,                  Full operation mode \n
 *   FC_VariationPoint_START                                \n
  *   #if (CANIF_USER_TP_TX_OFFLINE_MODE != STD_OFF)         \n
 *  CANIF_GET_TX_TP_ONLINE,             Set the Transmission TP Online  \n
 *  CANIF_GET_TX_USER_TP_ONLINE,        Set the Tx User TP Online       \n
 *  #endif                                                  \n
 *    FC_VariationPoint_END                                     \n
 *  CANIF_GET_OFFLINE_ACTIVE,               Transmit path is simulated and Receive path is disabled\n
 *  CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE      Transmit path is simulated and Receive path is enabled\n
 *}CanIf_PduGetModeType;                                    \n
 */
typedef enum
{
    CANIF_GET_OFFLINE = 0,
    CANIF_GET_RX_ONLINE,
    CANIF_GET_TX_ONLINE,
    CANIF_GET_ONLINE,
    /* FC_VariationPoint_START */
    #if (CANIF_USER_TP_TX_OFFLINE_MODE != STD_OFF)
    CANIF_GET_TX_TP_ONLINE,
    CANIF_GET_TX_USER_TP_ONLINE,
    #endif
    /* FC_VariationPoint_END */
    CANIF_GET_OFFLINE_ACTIVE,
    CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE

}CanIf_PduGetModeType;


/**
 * @ingroup CANIF_TYPES_H
 *
 * Return value of CAN LPDU notification status \n
 *
 * typedef enum                                 \n
 *{                                             \n
 *   CANIF_NO_NOTIFICATION = 0,             No transmit or receive event occurred for the requested L-PDU. \n
 *   CANIF_TX_RX_NOTIFICATION               The requested Rx/Tx CAN L-PDU was successfully transmitted or received \n
 *}CanIf_NotifStatusType;                       \n
 */
typedef enum
{
    CANIF_NO_NOTIFICATION = 0,
    CANIF_TX_RX_NOTIFICATION

}CanIf_NotifStatusType;

/**
 * @ingroup CANIF_TYPES_H
 *
 * CanId Type \n
 *
 * typedef enum                                         \n
 *{                                                     \n
 *   CANIF_STD = 0,                     Standard Can ID \n
 *   CANIF_XTD                          Extended Can ID \n
 *}CanIf_PduCanIdType;                                  \n
 */
typedef enum
{
    CANIF_STD = 0,
    CANIF_STD_FD,
    CANIF_XTD
    /* FC_VariationPoint_START */,
    CANIF_XTD_FD,
    CANIF_STD_NO_FD,
    CANIF_XTD_NO_FD
    /* FC_VariationPoint_END */
}CanIf_PduCanIdType;

/**
 * @ingroup CANIF_TYPES_H
 *
 * Structure for Controller State   \n
 *
 * typedef struct                   \n
 *{                                 \n
 *   CanIf_ControllerModeType    DeviceMode;    Device Mode  \n
 *  CanIf_PduGetModeType        ChannelMode;    Channel Mode \n
 *}CanIf_ControllerStateType;       \n
 */
typedef struct
{
    CanIf_ControllerModeType    DeviceMode;
    CanIf_PduGetModeType        ChannelMode;
	/* this element indicates if partial networking is enabled or disabled per controller [SWS_CANIF_00747]*/
	#if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
	boolean BlPnTxFilter;
	boolean BlPnCntr;
	#endif
}CanIf_ControllerStateType;

/**
 * @ingroup CANIF_TYPES_H
 *
 * User Types    \n
 *
 *typedef enum                      \n
 *{                                 \n
 *  PDUR = 0,       PDUR Module     \n
 *  CANNM,          CANNM Module    \n
 *  CANTP,          CANTP Module    \n
 *  ECUM,           ECUM Module     \n
 *  CDD,            CDD Module      \n
 *  XCP,            XCP Module      \n
 *  J1939TP,        J1939TP Module  \n
 *  USER            USER            \n
}CanIf_UserType;                    \n
 */
typedef enum
{
    PDUR = 0,
    CANNM,
    CANTP,
    /* FC_VariationPoint_START */
    #if(CANIF_CANTSYN_ENABLED != STD_OFF )
    CAN_TSYN,
    #endif
    /* FC_VariationPoint_END */
    ECUM,
	CDD,
	XCP,
	J1939TP,
    /* FC_VariationPoint_START */
    #if(CANIF_J1939NM_ENABLED != STD_OFF )
    J1939NM,
    #endif
    /* FC_VariationPoint_END */
    #if (CANIF_READBUFFERID != STD_OFF)
	USER,
    J1939
	#else
	USER
    #endif

}CanIf_UserType;

/**
 * @ingroup CANIF_TYPES_H
 *
 * Return value of the DLC error notification. \n
 *
 * typedef enum                 \n
 * {                            \n
 *   CANIF_DLC_OK = 0,      DLC Check Passed \n
 *   CANIF_DLC_E_FAILED     DLC check failed \n
 * }CanIf_DlcErrorReturnType;   \n
 */
typedef enum
{
    CANIF_DLC_OK = 0,
    CANIF_DLC_E_FAILED

}CanIf_DlcErrorReturnType;

/**
 * @ingroup CANIF_TYPES_H
 *
 * Type of Buffer in CanIf \n
 * typedef enum         \n
 *{                     \n
 *   CANIF_TRANSMIT = 0,        Transmit buffer \n
 *   CANIF_RECEIVE              Receive Buffer  \n
 *}CanIf_BufferType;    \n
 */
typedef enum
{
    CANIF_TRANSMIT = 0,
    CANIF_RECEIVE

}CanIf_BufferType;


/**
 * @ingroup CANIF_TYPES_H
 *
 * Structure for Callback functions
 *
 * typedef struct
 *{
 *   P2FUNC(void, TYPEDEF, User_ControllerBusOff) (VAR(uint8,AUTOMATIC));                     Pointer to function name of Target indication services for BusOff notification to target upper layers(CanSM) \n
 *   FC_VariationPoint_START                                                     \n
 *   P2FUNC(void, TYPEDEF, CanSM_ControllerErrorPassive) (VAR(uint8,AUTOMATIC));              Pointer to function name of Target indication services for Error passive notification to target upper layers(CanSM) \n
 *   FC_VariationPoint_END \n
 *   P2FUNC(void, TYPEDEF, CanSM_ControllerModeIndication) (VAR(uint8,AUTOMATIC), VAR(CanIf_ControllerModeType,AUTOMATIC));                   Pointer to function name of Target indication services for mode indication to target upper layers(CanSM) \n
 *   P2FUNC(void, TYPEDEF, User_SetWakeupEvent) (VAR(EcuM_WakeupSourceType,AUTOMATIC));                  Pointer to function name of Target indication services for WakeUp notification to target upper layers(EcuM) \n
 *   P2FUNC(void, TYPEDEF, User_ValidateWakeupEvent) (VAR(EcuM_WakeupSourceType,AUTOMATIC));             Pointer to function name of Target indication services for WakeUp Validation notification to target upper layers(EcuM) \n
 *   #if CANIF_TRCV_DRV_CFG!=STD_OFF  \n
 *   P2FUNC(void, TYPEDEF, User_TransceiverModeIndication) (VAR(uint8,AUTOMATIC) ,VAR(CanTrcv_TrcvModeType,AUTOMATIC)); Pointer to function name of Target indication services for transceiver mode  \n
 *   #endif   \n
 *  #if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)  \n
 *    P2FUNC(void, TYPEDEF, User_ClearTrcvWufFlagIndication) (VAR(uint8,AUTOMATIC) TransceiverId);  Pointer to function name of Clear-WUF flag indication service to indicate the WUF flag has been cleared in CanTrcv \n
 *    P2FUNC(void, TYPEDEF, User_CheckTrcvWakeFlagIndication) (VAR(uint8,AUTOMATIC) TransceiverId); Pointer to function name of Check-WUF flag indication service to indicate the WUF flag is set \n
 *    P2FUNC(void, TYPEDEF, User_ConfirmPnAvailability) (VAR(uint8,AUTOMATIC) TransceiverId);  Pointer to function name of PN-confirmation indication service to indicate to the CanNm via CanIf and CanSM that the network is in PN \n
 *  #endif    \n
 *  FC_VariationPoint_START \n
 *   P2FUNC(CanIf_DlcErrorReturnType, TYPEDEF, Dlc_Error_Notification) (VAR(PduIdType,AUTOMATIC) ,VAR(uint8,AUTOMATIC));  Pointer to function name of Target indication services for Dlc Error notification to monitoring module \n
 *    FC_VariationPoint_END  \n
 *}CanIf_CallbackFuncType; \n
 */

typedef struct
{
    P2FUNC(void, TYPEDEF, User_ControllerBusOff) (VAR(uint8,AUTOMATIC));
       /* FC_VariationPoint_START */
    P2FUNC(void, TYPEDEF, CanSM_ControllerErrorPassive) (VAR(uint8,AUTOMATIC));
       /* FC_VariationPoint_END */
    P2FUNC(void, TYPEDEF, CanSM_ControllerModeIndication) (VAR(uint8,AUTOMATIC), VAR(CanIf_ControllerModeType,AUTOMATIC));
    P2FUNC(void, TYPEDEF, User_SetWakeupEvent) (VAR(EcuM_WakeupSourceType,AUTOMATIC));
    P2FUNC(void, TYPEDEF, User_ValidateWakeupEvent) (VAR(EcuM_WakeupSourceType,AUTOMATIC));
    #if CANIF_TRCV_DRV_CFG!=STD_OFF
    P2FUNC(void, TYPEDEF, User_TransceiverModeIndication) (VAR(uint8,AUTOMATIC) ,VAR(CanTrcv_TrcvModeType,AUTOMATIC));
    #endif

    #if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)
    P2FUNC(void, TYPEDEF, User_ClearTrcvWufFlagIndication) (VAR(uint8,AUTOMATIC) Transceiver);
    P2FUNC(void, TYPEDEF, User_CheckTrcvWakeFlagIndication) (VAR(uint8,AUTOMATIC) Transceiver);
    P2FUNC(void, TYPEDEF, User_ConfirmPnAvailability) (VAR(uint8,AUTOMATIC) TransceiverId);
    #endif
    /* FC_VariationPoint_START */
    P2FUNC(CanIf_DlcErrorReturnType, TYPEDEF, Dlc_Error_Notification) (VAR(PduIdType,AUTOMATIC) ,VAR(uint8,AUTOMATIC));
    /* FC_VariationPoint_END */

}CanIf_CallbackFuncType;

/**
 * @ingroup CANIF_H
 *
 * Structure for Wakeup LUT \n
 * typedef struct
 *  {\n
 *   EcuM_WakeupSourceType WakeupSourceId;\n
 *   uint8 TransceiverId;\n
 *   }CanIf_WakeupLUT_Type; \n
 */
typedef struct
{
    EcuM_WakeupSourceType WakeupSourceId;
    uint8 TransceiverId;
}CanIf_WakeupLUT_Type;

/**
 * @ingroup CANIF_H
 *
 * CAN information about a PDU              \n
 * typedef struct                           \n
 * {                                        \n
 *   P2VAR(uint8,TYPEDEF,CANIF_APPL_DATA) SduDataPtr;   Pointer to the Sdu \n
 *   PduLengthType       SduLength;                     Length of the Sdu
 *   CanIf_CanIdType     SduCanId;                      Sdu Can Id \n
 * }CanIf_PduInfoType;
 */

/*
 ***************************************************************************************************
 * Type definitions
 ***************************************************************************************************
 */

 /**
 * @ingroup CANIF_H
 * #if (CANIF_EXTENDED_ID != STD_OFF)   \n
 * Defines the CanId type as a 32 bit . \n
 * #else                                \n
 * Defines the CanId type as a 16 bit.  \n
 * #endif                               \n
 */
#if((CANIF_EXTENDED_ID == STD_ON)||(CANIF_SETDYNAMICTXID_API == STD_ON))
typedef uint32 CanIf_CanIdType;
#else
typedef uint16 CanIf_CanIdType;
#endif


/* FC_VariationPoint_START */
 /**
 * @ingroup CANIF_H
 * #if (CANIF_EXTENDED_ID != STD_OFF)           \n
 * Defines the CANIF_FDBIT_MASK 0x1FFFFFFFUL    \n
 * to remove the FD bit passed from Can Driver  \n
 * #else                                        \n
 * Defines the CANIF_FDBIT_MASK 0x07FFFUL       \n
 * to remove the FD bit passed from Can Driver  \n
 * #endif                                       \n
 */
 #if((CANIF_EXTENDED_ID == STD_ON)||(CANIF_SETDYNAMICTXID_API == STD_ON))
#define CANIF_FDBIT_MASK   0x1FFFFFFFUL
#else
#define CANIF_FDBIT_MASK   0x07FFUL
#endif
/* FC_VariationPoint_END */

typedef struct
{
    P2VAR(uint8,TYPEDEF,CANIF_APPL_DATA) SduDataPtr;
    PduLengthType       SduLength;
    CanIf_CanIdType     SduCanId;


}CanIf_PduInfoType;

/**
 * @ingroup CANIF_H
 *
 * To configure group of discrete CanIds                \n
 * #if (CANIF_RXPDU_CANID_RANGE != STD_OFF)             \n
 * typedef struct                                       \n
 * {                                                    \n
 *   CanIf_CanIdType LowerCanId;    LowerCanId of a HRH Range \n
 *   CanIf_CanIdType UpperCanId;    UpperCanId of a HRH Range \n
 *   PduIdType       PduIdx;        Holds the position of the CaIds in the Rx PDU Table \n
 * }CanIf_RxPduCanIdRangeConfigType; \n
 * #endif
 */
#if (CANIF_RXPDU_CANID_RANGE != STD_OFF)


typedef struct
{
    CanIf_CanIdType LowerCanId;
    CanIf_CanIdType UpperCanId;
    PduIdType       PduIdx;

}CanIf_RxPduCanIdRangeConfigType;
#endif


/**
 * @ingroup CANIF_H
 *
 * To configure group of discrete CanIds                                                    \n
 * typedef struct                                                                           \n
 * {                                                                                        \n
 *   CanIf_CanIdType CanId;    CanId of receive L-PDUs used by the CAN driver for reception \n
 *   PduIdType       PduIdx;   Holds the position of the CanIds in the Rx PDU Table         \n
 * }CanIf_CanIdListConfigType;
    */
typedef struct
{
    CanIf_CanIdType CanId;
    PduIdType       PduIdx;

}CanIf_CanIdListConfigType;

/**
 * @ingroup CANIF_H
 *
 * Defines the type of HRH.                                          \n
 * typedef enum                                                      \n
 * {                                                                 \n
 *   CANIF_FULL = 0,                        Support FULL CAN feature \n
 *   CANIF_BASIC_RANGE_SFON_SINTGT,         Filtering of range of CAN ID's for a single target ID \n
 *   CANIF_BASIC_RANGE_SFON_MULTGT,         Filtering of range of CAN ID's for multiple target ID \n
 *   CANIF_BASIC_LIST_SFON                  Filtering the list of CAN ID's \n
 * }CanIf_HrhType;
 */
typedef enum
{
    CANIF_FULL = 0,
    CANIF_BASIC_RANGE_SFON_SINTGT,
    CANIF_BASIC_RANGE_SFON_MULTGT,
    CANIF_BASIC_LIST_SFON

}CanIf_HrhType;


/**
 * @ingroup CANIF_H
 *
 * Structure type for Rx Callback function.                                                     \n
 * typedef struct                                                                               \n
 * {                                                                                            \n
 *   Name of Receive Indication services to target upper layers - User specific modules  \n
 *   P2FUNC(void, TYPEDEF, UserRxIndication)(VAR(PduIdType,AUTOMATIC), P2CONST(CanIf_PduInfoType,AUTOMATIC,CANIF_APPL_CONST));  \n
 * } CanIf_RxCbk_Prototype;
 */
typedef struct
{
    P2FUNC(void, TYPEDEF, UserRxIndication)(VAR(PduIdType,AUTOMATIC), P2CONST(CanIf_PduInfoType,AUTOMATIC,CANIF_APPL_CONST));

} CanIf_RxCbk_Prototype;

/**
 * @ingroup CANIF_H
 *
 * Structure type for CDD Rx Callback function          \n
 * typedef struct                                       \n
 * {                                                    \n
 *   Name of Receive Indication services to Complex Device Drivers -User specific modules  \n
 *   P2FUNC(void, TYPEDEF, CddRxIndication)(VAR(PduIdType, AUTOMATIC),P2CONST(PduInfoType, AUTOMATIC,CANIF_APPL_CONST));
 *
 * } CanIf_CddRxCbk_Prototype;
 */
typedef struct
{

    P2FUNC(void, TYPEDEF, CddRxIndication)(VAR(PduIdType, AUTOMATIC),P2CONST(PduInfoType, AUTOMATIC,CANIF_APPL_CONST));

} CanIf_CddRxCbk_Prototype;

/**
 * @ingroup CANIF_H
 *
 * Structure type for J1939 Callback function  \n
 * typedef struct                           \n
 * {                                        \n
 *   Name of Transmit confirmation services to target upper layers - User specific modules \n
 *   P2FUNC(void, TYPEDEF, J1939RxIndication)(PduIdType);
 * } CanIf_TxCbk_Prototype;                 \n
 * typedef struct
 * {
 *
 *   Name of J1939 Rx Indication service \n
 *   P2FUNC(void, TYPEDEF, J1939RxIndication)(
 *           VAR(Can_HwHandleType, AUTOMATIC) Hrh,
 *           VAR(Can_IdType, AUTOMATIC) CanId,
 *           VAR(uint8, AUTOMATIC) CanDlc,
 *           P2CONST (uint8, AUTOMATIC, CANIF_APPL_DATA) CanSduPtr
 *           );
 *
 * } CanIf_J1939RxCbk_Prototype;
 *
 */
typedef struct
{

    P2FUNC(void, TYPEDEF, J1939RxIndication)(
            VAR(Can_HwHandleType, AUTOMATIC) Hrh,
            VAR(Can_IdType, AUTOMATIC) CanId,
            VAR(uint8, AUTOMATIC) CanDlc,
            P2CONST (uint8, AUTOMATIC, CANIF_APPL_DATA) CanSduPtr
            );

} CanIf_J1939RxCbk_Prototype;


/**
 * @ingroup CANIF_H
 *
 * Structure type for Tx Callback function  \n
 * typedef struct                           \n
 * {                                        \n
 *   Name of Transmit confirmation services to target upper layers - User specific modules \n
 *   P2FUNC(void, CANIF_APPL_CODE, UserTxConfirmation)(PduIdType);
 * } CanIf_TxCbk_Prototype;                 \n
 */
typedef struct
{
    P2FUNC(void, CANIF_APPL_CODE, UserTxConfirmation)(PduIdType);
} CanIf_TxCbk_Prototype;

/**
 * @ingroup CANIF_H
 *
 * Transmit L-Pdu configuration structure.  \n
 * typedef struct                           \n
 * {
 *   PduIdType               CanTxPduId;            Symbolic Handle for transmit CAN L-PDU \n
 *   PduIdType               TargetTxPduId;         Symbolic handle for transmit CAN L-PDU derived from upper layer to be called.\n
 *                                                  TargetTxPduId is configurable at pre-compile and Post built time \n
 *   PduIdType               CanTxPduIdType;        Type of PDU ID - Static/ Dynamic  \n
 *   uint8                   HthRefId;               Handle, that defines the hardware object or the pool of hardware objects configured for transmission \n
 *   uint8                   ControllerRefId;        Logical handle of the Underlying CAN controller to be served by the CAN Interface \n
 *   uint8                   CanIdType;              CAN-ID type of transmit CAN L-PDUs used by the CAN driver for CAN L-PDU transmission \n
 *   uint8                   TxUser;                 CanIf_User_Type - Defines the type of the transmit confirmation call-out called to the
 *                                                    corresponding upper layer the used TargetTxPduId belongs to \n
 *   boolean                 ReadTxPduNotifyStatus;  Enables/disables reading the notification status for each transmit CAN L-PDU \n
 *   uint8                   CbkIdx;                 Index to the callback function \n
 *  #if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)  \n
 *   boolean                PnSupport;               Indicates if the Tx-Pdu is a PN-pdu \n
 *  #endif
 *  FC_DeviationPoint_START                 \n
 *   #if(CANIF_TRANSMIT_BUFFER != STD_OFF)  \n
 *  FC_DeviationPoint_END                    \n
 *      FC_CODE_START
 *     #if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
 *   FC_CODE_END   \n
 *   uint16                  TxBufferOffset;         Stores the Offset of the L-PDU buffer in RAM \n
 *   uint8                   StartIdx;               Start Index of the list of Pdus assigned to the HTH \n
 *   uint8                   EndIdx;                 End Index of the list of Pdus assigned to the HTH \n

 *   #endif                                 \n
 *  FC_VariationPoint_START                 \n
 *  #if (CANIF_CALIBRATION == STD_ON)       \n
 *  P2FUNC(CanIf_CanIdType, TYPEDEF,  getCanId)(void);                  CAN-ID of transmit CAN L-PDUs used by the CAN driver for CAN L-PDU transmission \n
 *  #else                                   \n
 *  FC_VariationPoint_END                  \n
 *  CanIf_CanIdType         CanId;          \n
 *  FC_VariationPoint_START                 \n
 *    #endif                                    \n
 *  #if (CANIF_CALIBRATION == STD_ON)       \n
 *   P2FUNC(uint8, TYPEDEF,  getDlc)(void);       Data Length Code of transmit CAN L-PDUs used by the CAN driver for CAN L-PDU transmission \n
 *  #else                                   \n
 *  FC_VariationPoint_END                 \n
 *  uint8                   Dlc;                    Data Length Code of transmit CAN L-PDUs used by the CAN driver for CAN L-PDU transmission \n
 *  FC_VariationPoint_START                \n
 *    #endif                                    \n
 *  FC_VariationPoint_END                \n
 *  FC_VariationPoint_START			    \n
 *	 #if(CANIF_METADATA_SUPPORT == STD_ON)	\n
 *   PduLengthType   MetaDataLength_u32;    Metadata length for Tx L-PDU \n
 *   uint32          TxPduCanIdMask_u32;    CanIdMask for Tx L-PDU \n
 *   #endif									\n
 *  FC_VariationPoint_END					\n
 * }CanIf_TxPduInfo;
 */

typedef struct
{
    PduIdType                       CanTxPduId;
    PduIdType                       TargetTxPduId;
    PduIdType                       CanTxPduIdType;
    uint8                           HthRefId;
    uint8                           ControllerRefId;
    uint8                           CanIdType;
    CanIf_UserType                  TxUser;
    boolean                         ReadTxPduNotifyStatus;
    uint8                           CbkIdx;
#if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)
	/* boolean element indicates PN availability in pdu level */
    boolean                         PnSupport;
    #endif
    /* FC_DeviationPoint_START */
#if(CANIF_TRANSMIT_BUFFER != STD_OFF)
    /* FC_DeviationPoint_END */
    /* FC_CODE_START */
 //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
  /*  FC_CODE_END */
    uint16                            TxBufferOffset;
    PduIdType                         StartIdx;
    PduIdType                         EndIdx;
    uint8                             HTHStatusFlagIdx;
    #endif
    /* FC_VariationPoint_START */
    #if (CANIF_CALIBRATION == STD_ON)
    P2FUNC(CanIf_CanIdType, TYPEDEF,  getCanId)(void);
    #else
    /* FC_VariationPoint_END */
    CanIf_CanIdType                  CanId;
    /* FC_VariationPoint_START */
    #endif
    #if (CANIF_CALIBRATION == STD_ON)
    P2FUNC(uint8, TYPEDEF,  getDlc)(void);                      /* Data Length Code of transmit CAN L-PDUs used by the CAN driver for CAN L-PDU transmission */
    #else
    /* FC_VariationPoint_END */
    uint8                            Dlc;
    /* FC_VariationPoint_START */
    #endif
    /* FC_VariationPoint_END */

    /* FC_VariationPoint_START */
    #if (CANIF_CALIBRATION == STD_ON)
    boolean                          isComULforPDUR;
    #endif
    /* FC_VariationPoint_END */

	/* FC_VariationPoint_START */
	#if(CANIF_METADATA_SUPPORT == STD_ON)
    PduLengthType   MetaDataLength_u32;		    /* Metadata length for Tx L-PDU */
	uint32          TxPduCanIdMask_u32;         /* CanIdMask for Tx L-PDU       */
	#endif
	/* FC_VariationPoint_END */
}CanIf_TxPduInfo;


/**
 * @ingroup CANIF_H
 *
 * HRH Configuration structure  \n
 * typedef struct               \n
 * {                            \n
 *   CanIf_HrhType          HrhInfo;                  Holds information about BASIC/FULL and the S/w filter \n
 *   PduIdType              PduIdx;                   Holds the starting position of the CAN IDs in the Rx PDU Table \n
 *   uint32                  NumCanId;                 Holds the number of CanIds supported by the HRH \n
 *   uint8                  ControllerId;             Holds the controller to which the HRH belongs   \n
 *   #if ((CANIF_READRXPDU_DATA_API != STD_OFF) || (CANIF_READRXPDU_NOTIFY_STATUS_API != STD_OFF))    \n
 *   uint8                  ReadRxPdu;                Lower nibble  = Read Data, Upper nibble  = Read Notification status \n
 *   #endif                             \n
 *  FC_VariationPoint_START     \n
 *  #if (CANIF_CALIBRATION == STD_ON)   \n
 *  P2FUNC(CanIf_CanIdType, TYPEDEF,  getCanId)(void);                 CanId of receive L-PDUs used by the CAN driver for reception \n
 *  #else                               \n
 *  FC_VariationPoint_END               \n
 *  CanIf_CanIdType        CanId;                     CanId of receive L-PDUs used by the CAN driver for reception \n
 *  FC_VariationPoint_START               \n
 *  #endif                              \n
 *  FC_VariationPoint_END               \n
 *  uint32                 HrhRangeMask;
 * }CanIf_HrhConfigType;
 */
typedef struct
{
    CanIf_HrhType           HrhInfo;
    PduIdType               PduIdx;
    uint32                  NumCanId;
    uint8                   ControllerId;
    #if ((CANIF_READRXPDU_DATA_API != STD_OFF) || (CANIF_READRXPDU_NOTIFY_STATUS_API != STD_OFF))
    uint8                   ReadRxPdu;
    #endif
    #if(CANIF_READMSGID_API != STD_OFF)
    uint8                   CanHardwareObjectHandle;
    #endif
    /* FC_VariationPoint_START */
    #if (CANIF_CALIBRATION == STD_ON)
    P2FUNC(CanIf_CanIdType, TYPEDEF,  getCanId)(void);
    P2FUNC(uint32, TYPEDEF,  getCanIdMask)(void);
    #else
    /* FC_VariationPoint_END */
    CanIf_CanIdType         CanId;
    uint32                  HrhRangeMask; /* CanIfHrhRangeMask */
    /* FC_VariationPoint_START */
    #endif
    /* FC_VariationPoint_END */

}CanIf_HrhConfigType;

/**
 * @ingroup CANIF_H
 *
 * Receive L-Pdu configuration structure    \n
 * typedef struct                           \n
 * {                                        \n
 *   #if(CANIF_RECEIVE_BUFFER != STD_OFF)   \n
 *   uint16          RxBufferOffset;        Stores the Offset of the L-PDU buffer in RAM \n
 *   #endif                                 \n
 *   PduIdType       TargetRxPduId;         Symbolic handle for Rx L-PDU derived from upper layer \n
 *   PduIdType       RxPduId;               Name of the Rx L-PdU Id \n
 *   uint8           HrhRef;                Receive Handle that defines the hardware object configured for reception \n
 *   uint8           CbkIdx;                Index to the callback function \n
 *   uint8           User;                  Pdu Owner \n
 *   FC_VariationPoint_START                \n
 *  #if (CANIF_CALIBRATION == STD_ON)       \n
 *   P2FUNC(uint8, TYPEDEF,  getDlc)(void);                    Data Length Code of Rx L-PDUs \n
 *  #else                                   \n
 *   FC_VariationPoint_END                    \n
 *   uint8           Dlc;                   Data Length Code of Rx L-PDUs \n
 *   FC_VariationPoint_START                \n
 *    #endif                                    \n
 *   FC_VariationPoint_END                    \n
 *   FC_VariationPoint_START                \n
 *	 #if(CANIF_METADATA_SUPPORT == STD_ON)	\n
 *	 PduLengthType    MetaDataLength_u32;   Metadata length for Rx L-PDU \n
 *	 #endif                                 \n
 *   FC_VariationPoint_END                  \n
 *   CanIf_CanIdType  RxPduCanId_u32;       Configured Canid in RxPducfg \n
 * }CanIf_RxPduConfigType;
 */
typedef struct
{
    /* FC_DeviationPoint_START */
#if(CANIF_RECEIVE_BUFFER != STD_OFF)
   /* FC_DeviationPoint_END */
       /* FC_CODE_START */
     //#if(CANIF_READRXPDU_DATA_API != STD_OFF)
     /* FC_CODE_END */
   uint16          RxBufferOffset; /* Stores the Offset of the L-PDU buffer in RAM */
   #endif
   PduIdType       TargetRxPduId;  /* Symbolic handle for Rx L-PDU derived from upper layer */
   PduIdType       RxPduId;        /* name of the Rx L-PdU Id */
   uint8           HrhRef;         /* Receive Handle that defines the hardware object configured for reception */
   uint8           CbkIdx;         /* Index to the callback function */
   CanIf_UserType  User;           /* Pdu Owner */
  /* FC_VariationPoint_START */
   uint8                   CanIdType; /* Type of CanId STD or EXTD or STD_FD or EXTD_FD or STD_NO_FD or EXT_NO_FD*/
  /* FC_VariationPoint_END */
    /* FC_VariationPoint_START */
    #if (CANIF_CALIBRATION == STD_ON)
    P2FUNC(uint8, TYPEDEF,  getDlc)(void);             /* Data Length Code of Rx L-PDUs */
    #else
    /* FC_VariationPoint_END */
    uint8           Dlc;
    /* FC_VariationPoint_START */
    #endif
    /* FC_VariationPoint_END */
	/* FC_VariationPoint_START */
	#if(CANIF_METADATA_SUPPORT == STD_ON)
	PduLengthType       MetaDataLength_u32;	    /* Metadata length for Rx L-PDU */
	#endif
	/* FC_VariationPoint_END */
    CanIf_CanIdType     RxPduCanId_u32;         /* Configured Canid in RxPducfg */
}CanIf_RxPduConfigType;

/**
 * @ingroup CANIF_H
 *
 * Initialization structure for CANIF   \n
 * typedef struct                       \n
 * {
 *   P2CONST(CanIf_TxPduInfo,TYPEDEF,CANIF_CFG_CONST) TxPduConfig;           Pointer to the Tx Pdu Configuration. \n
 *   P2CONST(CanIf_RxPduConfigType,TYPEDEF,CANIF_CFG_CONST) RxPduConfig;     Pointer to the Rx Pdu Configuration. \n
 *   P2CONST(CanIf_HrhConfigType,TYPEDEF,CANIF_CFG_CONST)     HrhConfig
 *   uint8 NumCanTxPduId;                                                    Number of CAN Tx Pdu Id.             \n
 *   uint8 NumCanRxPduId;                                                    Number of CAN Rx Pdu Id.             \n
 *   uint8 NumDynamicCanTxPduId;                                             Number of Dynamic Can Tx Pdu Id.     \n
 *   uint8 NumControllers;                                                   Number of Controllers.               \n
 *      P2VAR(uint8,TYPEDEF,CANIF_CFG_CONST)                    TxBufferPtr
 *      P2VAR(boolean,TYPEDEF,CANIF_CFG_CONST)                    TxBufferAllocPtr
 *   P2VAR(uint8,TYPEDEF,CANIF_CFG_CONST)                    RxBufferPtr
 *   P2VAR(CanIf_NotifStatusType,TYPEDEF,CANIF_CFG_CONST)    TxNotifPtr
 *   P2VAR(CanIf_NotifStatusType,TYPEDEF,CANIF_CFG_CONST)    RxNotifPtr
 *   P2CONST(CanIf_CanIdListConfigType, TYPEDEF,CANIF_CFG_CONST) ListCfgPtr
 *   P2CONST(CanIf_RxPduCanIdRangeConfigType,TYPEDEF,CANIF_CFG_CONST)RangeCfgPtr
 *   P2CONST(CanIf_RxCbk_Prototype,TYPEDEF,CANIF_CFG_CONST)     RxUSERCbkPtr
 *   P2CONST(CanIf_CddRxCbk_Prototype,TYPEDEF,CANIF_CFG_CONST) RxCDDCbkPtr
 *   P2CONST(CanIf_TxCbk_Prototype,TYPEDEF,CANIF_CFG_CONST)     TxUSER_CDDCbkPtr
 *   P2CONST (boolean,TYPEDEF,CANIF_CFG_CONST)                 PNCtrlsInCfgPtr
 *   P2VAR(boolean,TYPEDEF,CANIF_CFG_CONST)                    PNCtrlsStatusPtr
 *   P2CONST (CanIf_WakeupLUT_Type,TYPEDEF,CANIF_CFG_CONST)  WakeupLutPtr
 *   P2VAR(uint8,TYPEDEF,CANIF_CFG_CONST)                    NewRxMsgPtr
 *   P2VAR(uint8,TYPEDEF,CANIF_CFG_CONST)                     WkpEventPtr
 *   P2VAR(CanIf_ControllerStateType,TYPEDEF,CANIF_CFG_CONST)CtrlStatePtr
 *   P2VAR(CanIf_NotifStatusType,TYPEDEF,CANIF_CFG_CONST)    TxConfStatusPtr
 *   P2VAR(uint32,TYPEDEF,CANIF_CFG_CONST)                    DynTxIdPtr
 *     P2CONST(CanIf_CanIdType,TYPEDEF,CANIF_CFG_CONST)         NmtxIdPtr
 *   uint16 TxBufferSize                                                  Total Tx-buffer size             \n
 *   uint16 RxBufferSize                                                     Total Rx-buffer size             \n
 *   uint16 NumHrhHandles                                                    Number of HRHs             \n
 *     VAR(uint8,TYPEDEF)                                        CfgSetIndex
 * }CanIf_ConfigType;
 */
typedef struct
{
    P2CONST(CanIf_TxPduInfo,TYPEDEF,CANIF_CFG_CONST)         TxPduConfig;
    P2CONST(CanIf_RxPduConfigType,TYPEDEF,CANIF_CFG_CONST)     RxPduConfig;
    P2CONST(CanIf_HrhConfigType,TYPEDEF,CANIF_CFG_CONST)     HrhConfig;
    VAR(PduIdType,TYPEDEF)                                     NumCanTxPduId;
    VAR(PduIdType,TYPEDEF)                                     NumCanRxPduId;
    VAR(PduIdType,TYPEDEF)                                     NumDynamicCanTxPduId;
    VAR(uint8,TYPEDEF)                                         NumControllers;
#if ((CANIF_VARIANT_INFO == 2) || (CANIF_VARIANT_INFO == 3))

   /* FC_DeviationPoint_START */
#if (CANIF_TRANSMIT_BUFFER != STD_OFF)
   /* FC_DeviationPoint_END */
       /* FC_CODE_START */
 //#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
  /*  FC_CODE_END */
    P2VAR(uint8,TYPEDEF,CANIF_CFG_CONST)                    TxBufferPtr;
    P2VAR(boolean,TYPEDEF,CANIF_CFG_CONST)                    TxBufferAllocPtr;
    P2VAR(boolean,TYPEDEF,CANIF_CFG_CONST)                  HTHStatusFlagPtr;
    #endif
    //This shall be enabled ONLY if Rx-buffering is enabled. and is applicable for all config sets. This is a variable
   /* FC_DeviationPoint_START */
#if (CANIF_RECEIVE_BUFFER != STD_OFF)
  /* FC_DeviationPoint_END */
    /* FC_CODE_START */
     //#if(CANIF_READRXPDU_DATA_API != STD_OFF)
/* FC_CODE_END */
    P2VAR(uint8,TYPEDEF,CANIF_CFG_CONST)                    RxBufferPtr;
    #endif
    //This shall be enabled ONLY if Read Tx-Notif status is enabled and is applicable for all config sets. This is a variable
#if (CANIF_READTXPDU_NOTIFY_STATUS_API != STD_OFF)
    P2VAR(CanIf_NotifStatusType,TYPEDEF,CANIF_CFG_CONST)    TxNotifPtr;
    #endif
    //This shall be enabled ONLY if Read Rx-Notif status OR Read Rx-Data is enabled.and is applicable for all config sets. This is a variable
#if (CANIF_READRXPDU_NOTIFY_STATUS_API != STD_OFF)
    P2VAR(CanIf_NotifStatusType,TYPEDEF,CANIF_CFG_CONST)    RxNotifPtr;
    #endif
    //This shall be enabled if ATLEAST one configset has a HRH List
#if (CANIF_BASIC_CAN_SUPPORT_LIST != STD_OFF)
    P2CONST(CanIf_CanIdListConfigType, TYPEDEF,CANIF_CFG_CONST) ListCfgPtr;
    #endif
    //This shall be enabled if ATLEAST one configset has a HRH range
#if (CANIF_RXPDU_CANID_RANGE != STD_OFF)
    P2CONST(CanIf_RxPduCanIdRangeConfigType,TYPEDEF,CANIF_CFG_CONST)RangeCfgPtr;
    #endif
    //This shall be enabled if ATLEAST one configset has a USER Rx-Pdu
#if (CANIF_USER_RX_ENABLED != STD_OFF)
    P2CONST(CanIf_RxCbk_Prototype,TYPEDEF,CANIF_CFG_CONST)     RxUSERCbkPtr;
    #endif
    //This shall be enabled if ATLEAST one configset has a CDD Rx-Pdu
#if (CANIF_CDD_RX_ENABLED != STD_OFF)
    P2CONST(CanIf_CddRxCbk_Prototype,TYPEDEF,CANIF_CFG_CONST) RxCDDCbkPtr;
    #endif
#if (CANIF_READBUFFERID != STD_OFF)
    P2CONST(CanIf_J1939RxCbk_Prototype,TYPEDEF,CANIF_CFG_CONST) RxJ1939CbkPtr;
    #endif
    //This shall be enabled if ATLEAST one configset has a USER or CDD Tx-Pdu
#if (CANIF_USER_CDD_TX_ENABLED != STD_OFF)
    P2CONST(CanIf_TxCbk_Prototype,TYPEDEF,CANIF_CFG_CONST)     TxUSER_CDDCbkPtr;
    #endif
    // This shall be enabled if atleast one Trcv supports wakeup or Wakeup validation is TRUE
#if(CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
    P2CONST (CanIf_WakeupLUT_Type,TYPEDEF,CANIF_CFG_CONST)  WakeupLutPtr;
    P2VAR(uint8,TYPEDEF,CANIF_CFG_CONST)                    NewRxMsgPtr;          //To store the new Rx-message info
    P2VAR(uint8,TYPEDEF,CANIF_CFG_CONST)                     WkpEventPtr;          //To store the wakeup event info
    #endif

    P2VAR(CanIf_ControllerStateType,TYPEDEF,CANIF_CFG_CONST)CtrlStatePtr;

    //This shall be enabled for ALL configsets if Tx-confirmation support is enabled
#if(CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
    P2VAR(CanIf_NotifStatusType,TYPEDEF,CANIF_CFG_CONST)    TxConfStatusPtr;
    #endif

    //This shall be enabled if canIfPublicDynamicTxIdSupport is TRUE
   /* FC_DeviationPoint_START */
#if(CANIF_DYNAMIC_ID != STD_OFF)
   /* FC_DeviationPoint_END */
   /* FC_CODE_START */
    /* MR12 RULE 3.1, VIOLATION: Warning is "Not Critical". The comment is needed during Code stripping for COMMASSO release */
///* This shall be enabled if canIfSetDynamicTxIdSupport is TRUE */
//#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
/* FC_CODE_END */
    P2VAR(uint32,TYPEDEF,CANIF_CFG_CONST)                    DynTxIdPtr;
    #endif

    //This shall be enabled if ATLEAST one configset receives its own CanNm Tx-Pdu
#if(CANIF_CANNM_TXID_FILTER != STD_OFF)
    P2CONST(CanIf_CanIdType,TYPEDEF,CANIF_CFG_CONST)         NmtxIdPtr;
    #endif
    VAR(uint16,TYPEDEF)                                   TxBufferSize;
    VAR(uint16,TYPEDEF)                                     RxBufferSize;
    VAR(uint16,TYPEDEF)                                     NumHrhHandles;
    //This shall be enabled ONLY if Tx-buffering is enabled,and is applicable for all ConfigSets. This is a variable
    CONST(uint8,TYPEDEF)                                    CfgSetIndex;
    const PduIdType (*CanIf_TxPduId_CustId_LUT_ptr)[CANIF_TOTAL_CFG_SETS];
#if (CANIF_VARIANT_INFO == 3)
    P2CONST(Std_VersionInfoType,TYPEDEF,CANIF_CFG_CONST)  CanIf_VersionInfo;
#endif

    P2CONST(CanIf_CallbackFuncType,TYPEDEF,CANIF_CFG_CONST) CallbackPtr;
    VAR(PduIdType,TYPEDEF)                                  Num_custid_entries;

    #endif
}CanIf_ConfigType;

#if (CANIF_USER_TXBUFCLEARNOTIFY_API != STD_OFF)

extern P2FUNC(void, CANIF_APPL_CODE, CanIf_UserTxBufClearCallback) (VAR(PduIdType,AUTOMATIC));  /* Pointer to function name for the notification to application about the lost data */

#endif

#endif   /* CANIF_TYPES_H */
/* FC_VariationPoint_START */

/* FC_VariationPoint_END */
