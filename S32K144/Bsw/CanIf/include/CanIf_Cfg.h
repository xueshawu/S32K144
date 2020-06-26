/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Archie
 * @Date: 2020-06-08 20:58:06
 * @LastEditors: Archie
 * @LastEditTime: 2020-06-08 21:48:35
 */ 

#ifndef CANIF_CFG_H_
#define CANIF_CFG_H_
/* ============================ [ INCLUDES  ] ====================================================== */
#include "Can.h"
/* ============================ [ MACROS    ] ====================================================== */
#define CANIF_VERSION_INFO_API   STD_OFF
#define CANIF_DEV_ERROR_DETECT   STD_OFF
#define CANIF_DLC_CHECK          STD_OFF

#ifndef CANIF_TASK_FIFO_MODE
#define CANIF_TASK_FIFO_MODE     STD_%s
#endif
#define CANIF_RX_FIFO_SIZE       %s
#define CANIF_TX_FIFO_SIZE       %s

#define CANIF_MULITPLE_DRIVER_SUPPORT       STD_OFF   /*  Not supported */
#define CANIF_READRXPDU_DATA_API            STD_OFF   /*  Not supported */
#define CANIF_READRXPDU_NOTIFY_STATUS_API   STD_OFF   /*  Not supported */
#define CANIF_READTXPDU_NOTIFY_STATUS_API   STD_OFF   /*  Not supported */
#define CANIF_SETDYNAMICTXID_API            STD_OFF   /*  Not supported */
#define CANIF_WAKEUP_EVENT_API              STD_OFF   /*  Not supported */
#define CANIF_TRANSCEIVER_API               STD_OFF   /*  Not supported */
#define CANIF_TRANSMIT_CANCELLATION         STD_OFF   /*  Not supported */
#define CANIF_ARC_RUNTIME_PDU_CONFIGURATION STD_OFF   /*  Not supported */
#define CANIF_CANPDUID_READDATA_API         STD_OFF   /*  Not supported */
#define CANIF_READRXPDU_NOTIF_STATUS_API    STD_OFF   /*  Not supported */

/* ============================ [ TYPES     ] ====================================================== */
/* Identifiers for the elements in CanIfControllerConfig[]
 * This is the ConfigurationIndex in CanIf_InitController() */
typedef enum 
{

    CANIF_CHANNEL_CONFIGURATION_CNT
}CanIf_Arc_ConfigurationIndexType;

typedef enum 
{
    CANIF_CHANNEL_CNT
}CanIf_Arc_ChannelIdType;

#include "CanIf_ConfigTypes.h"

extern const CanIf_ConfigType CanIf_Config; 
/* ============================ [ INCLUDES  ] ====================================================== */
#include "CanIf.h"
#if defined(USE_CANTP)
#include "CanTp.h"
#include "CanTp_Cbk.h"
#endif
#if defined(USE_J1939TP)
#include "J1939Tp.h"
#include "J1939Tp_Cbk.h"
#endif
#if defined(USE_PDUR)
#include "PduR.h"
#endif
#if defined(USE_CANNM)
#include "CanNm_Cbk.h"
#endif
#if defined(USE_OSEKNM)
#include "OsekNm.h"
#endif
#if defined(USE_XCP)
#include "Xcp.h"
#include "XcpOnCan_Cbk.h"
#endif
/* ============================ [ MACROS    ] ====================================================== */
#define PDUR_ID2_STDOUT 0
#define PDUR_ID_STDIN 0
/* ============================ [ DECLARES  ] ====================================================== */
/* Imported structs from Can_PBcfg.c */
extern const Can_ControllerConfigType Can_ControllerCfgData[];
extern const Can_ConfigSetType Can_ConfigSetData;
/* ============================ [ DATAS     ] ====================================================== */
/* Contains the mapping from CanIf-specific Channels to Can Controllers */
const CanControllerIdType CanIf_Arc_ChannelToControllerMap[CANIF_CHANNEL_CNT] = 
{

};

const uint8 CanIf_Arc_ChannelDefaultConfIndex[CANIF_CHANNEL_CNT] = 
{

};

/* Container that gets slamed into CanIf_InitController()
 * Inits ALL controllers
 * Multiplicity 1..* */
const CanIf_ControllerConfigType CanIfControllerConfig[CANIF_CHANNEL_CNT] = 
{

};
/* Function callbacks for higher layers */
const CanIf_DispatchConfigType CanIfDispatchConfig =
{
    /*.CanIfBusOffNotification =*/ %s,
    /*.CanIfWakeUpNotification =*/ NULL,        /* Not used */
    /*.CanIfWakeupValidNotification =*/ NULL,   /* Not used */
    /*.CanIfErrorNotificaton =*/ %s,
};



static const CanIf_HthConfigType CanIfHthConfigData[]=
{
    /*.CanIfHthType =*/ CAN_ARC_HANDLE_TYPE_BASIC, /* TODO */
    /*.CanIfCanControllerIdRef =*/ %s,
    /*.CanIfHthIdSymRef =*/ %s,
    /*.CanIf_Arc_EOL =*/ %s
}
static const CanIf_HrhConfigType CanIfHrhConfigData_%s[]=
{
    /*.CanIfHrhType =*/ CAN_ARC_HANDLE_TYPE_BASIC, /* TODO: not used by CanIf now. */
    /*.CanIfSoftwareFilterHrh =*/ TRUE, /* Must Be True */
    /*.CanIfCanControllerHrhIdRef =*/ %s,
    /*.CanIfHrhIdSymRef =*/ %s,
    /*.CanIfHrhRangeConfig =*/ NULL,
    /*.CanIf_Arc_EOL =*/ %s
};
const CanIf_InitHohConfigType CanIfHohConfigData[] =
{
    /*.CanIfHrhConfig =*/ CanIfHrhConfigData_%s,
    /*.CanIfHthConfig =*/ CanIfHthConfigData_%s,
    /*.CanIf_Arc_EOL =*/ %s
};

    {
        /*.CanIfTxPduId =*/ %s_%s,
        /*.CanIfCanTxPduIdCanId =*/ %s, 
        /*.CanIfCanTxPduIdDlc =*/ %s,
        /*.CanIfCanTxPduType =*/ CANIF_PDU_TYPE_STATIC,
    #if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )
        /*.CanIfReadTxPduNotifyStatus =*/ TRUE,
    #endif
        /*.CanIfTxPduIdCanIdType =*/ %s,
        /*.CanIfUserTxConfirmation =*/ %s,
        /*.CanIfCanTxPduHthRef =*/ &CanIfHthConfigData_%s[%s],
        /*.PduIdRef =*/ NULL
    }

const CanIf_TxPduConfigType CanIfTxPduConfigData[] = 
{
    
};
    





{
    /*.CanIfCanRxPduId =*/ %s_ID_%s,
    /*.CanIfCanRxPduCanId =*/ %s,
    /*.CanIfCanRxPduDlc =*/ %s,
#if ( CANIF_CANPDUID_READDATA_API == STD_ON )
    /*.CanIfReadRxPduData =*/ TRUE,
#endif
#if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )
    /*.CanIfReadRxPduNotifyStatus =*/ TRUE,
#endif
    /*.CanIfRxPduIdCanIdType =*/ %s,
    /*.CanIfRxUserType =*/ %s,
    /*.CanIfUserRxIndication =*/ %s,
    /*.CanIfCanRxPduHrhRef =*/ &CanIfHrhConfigData_%s[%s],
    /*.PduIdRef =*/ NULL,
    /*.CanIfSoftwareFilterType =*/ CANIF_SOFTFILTER_TYPE_MASK,
    /*.CanIfCanRxPduCanIdMask =*/ %s
};

static const CanIf_RxPduConfigType CanIfRxPduConfigData[] = 
{
    
};

/* This container contains the init parameters of the CAN
 * Multiplicity 1..* */
const CanIf_InitConfigType CanIfInitConfig =
{
    /*.CanIfConfigSet =*/ 0, /* Not used */
    /*.CanIfNumberOfCanRxPduIds =*/ sizeof(CanIfRxPduConfigData)/sizeof(CanIf_RxPduConfigType),
    /*.CanIfNumberOfCanTXPduIds =*/ sizeof(CanIfTxPduConfigData)/sizeof(CanIf_TxPduConfigType),
    /*.CanIfNumberOfDynamicCanTXPduIds =*/ 0, /* Not used */
    /* Containers */
    /*.CanIfHohConfigPtr =*/ CanIfHohConfigData,
    /*.CanIfRxPduConfigPtr =*/ CanIfRxPduConfigData,
   /*.CanIfTxPduConfigPtr =*/ CanIfTxPduConfigData,
};
/* This container includes all necessary configuration sub-containers
 * according the CAN Interface configuration structure */
const CanIf_ConfigType CanIf_Config =
{
    /*.ControllerConfig =*/ CanIfControllerConfig,
    /*.DispatchConfig =*/ &CanIfDispatchConfig,
    /*.InitConfig =*/ &CanIfInitConfig,
    /*.TransceiverConfig =*/ NULL, /* Not used */
    /*.Arc_ChannelToControllerMap =*/ CanIf_Arc_ChannelToControllerMap,
    /*.Arc_ChannelDefaultConfIndex =*/ CanIf_Arc_ChannelDefaultConfIndex,
};




