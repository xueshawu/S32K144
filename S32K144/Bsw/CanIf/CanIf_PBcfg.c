/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.1
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/





/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: CanIf / AR42.4.0.1                Module Package Version
 * $Editor_____: 9.0                Tool Version
 * $Model______: 2.0.2.1                ECU Parameter Definition Version
 *

 </VersionHead>*/


/******************************************************************************/
/*                                  Include Section                                */
/******************************************************************************/

/* CanIf Private header */
#include "CanIf_Priv.h"
/* CanIf post build header */
#include "CanIf_PBcfg.h"
/* CanIf post build header */
#include "CanIf_Cfg_Internal.h"
#include "Can.h"
#include "CanTp.h"





















/*
 ******************************************************************************
 * Variables
 ******************************************************************************
 */








/* CANIF callback configuration */

#if(CANIF_VARIANT_INFO != 2) && (CANIF_VARIANT_INFO != 3)
#define CANIF_START_SEC_CONST_UNSPECIFIED
#else
#define CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#endif
#include "CanIf_MemMap.h"
CONST(CanIf_CallbackFuncType, CANIF_CONST) CanIf_Callback =
{

    NULL_PTR,














    NULL_PTR,
    
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    
    NULL_PTR
    

};

#if(CANIF_VARIANT_INFO != 2) && (CANIF_VARIANT_INFO != 3)
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#else
#define CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#endif
#include "CanIf_MemMap.h"
















/* Tx PDUs Configuration */
#if(CANIF_VARIANT_INFO != 2) && (CANIF_VARIANT_INFO != 3)
#define CANIF_START_SEC_CONST_UNSPECIFIED
#else
#define CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#endif
#include "CanIf_MemMap.h"
CONST(CanIf_TxPduInfo, CANIF_CONST) CanIf_TxPduConfig[]=
{
/*
    CanTxPduId, TargetTxPduId, CanTxPduId, Hth_Ref_Id, Controller, CanIdType,  User,  ReadTxPdu,  CbkIdx ,Tx_Buffer Offset , Start Indx , End Indx, HTHIndex, CanId,  DLC,                                     Type                                                 Notify
                                                                                        Status
*/
{   CanIfConf_CanIfTxPduCfg_CanIfTxPduCfg_uds_tx,     CanTpConf_CanTpTxNPdu_CanTpTxNPdu_udstx,   CANIF_STATIC,   (uint8)CanHardwareObject_NODE0_Tx_Std_MailBox_1,    (uint8)CANIF_Can_Network_CANNODE_0,   0x00,   CANTP,   TRUE    ,   0 ,   0x7C8,   8 },
};
#if(CANIF_VARIANT_INFO != 2) && (CANIF_VARIANT_INFO != 3)
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#else
#define CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#endif
#include "CanIf_MemMap.h"










/* Rx Handle configuration */

#define CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"

CONST(CanIf_HrhConfigType, CANIF_CONST) CanIf_HrhConfig[] =
{
/*   HRHInfo ,    Pdu/ListIdx,   NumCanIds/NumRanges,     Controller,  ReadRxPduInfo,    CanId,  HrhRangeMask */

{ CANIF_FULL,       0    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x7C0,       0x1FFFFFFFU }/*Can_Network_CANNODE_0_Rx_Std_MailBox_1*/,
{ CANIF_FULL,       1    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x7DF,       0x1FFFFFFFU }/*Can_Network_CANNODE_0_Rx_Std_MailBox_2*/,
{ CANIF_FULL,       1    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x650,       0x1FFFFFFFU }/*Can_Network_CANNODE_0_Rx_Std_MailBox_3*/,
};

#define CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"















/* Rx PDUs Configuration */

#define CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[]=
{
/*     RxBufferOffset,  target ID,  RxPduId , HRH , CbkIdx, User, CanIdType, DLC,  RxPduCanId      */
{     0,   CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_uds_rx_fuc,       1,  0,   CANTP,   0x20u,   8,   0x7DF },
{     1,   CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_uds_rx_phy,       0,  1,   CANTP,   0x20u,   8,   0x7C0 },

};

#define CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"












/* Tx CanIds of CANNM */

#define CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_CanIdType, CANIF_CONST) CanIf_CanNmTxId[] =
{
    0x586
};

#define CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"



















   








/* Rx Callback functions with the parameters - PduIdType, const CanIf_PduInfoType* */

#if(CANIF_VARIANT_INFO != 2) && (CANIF_VARIANT_INFO != 3)
#define CANIF_START_SEC_CONST_UNSPECIFIED
#else
#define CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#endif
#include "CanIf_MemMap.h"
CONST(CanIf_CddRxCbk_Prototype, CANIF_CONST) CanIf_CddRxCbk[] =
{
    {NULL_PTR}
};

#if(CANIF_VARIANT_INFO != 2) && (CANIF_VARIANT_INFO != 3)
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#else
#define CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#endif
#include "CanIf_MemMap.h"








/* Tx Callback functions with the parameters - PduIdType */

#if(CANIF_VARIANT_INFO != 2) && (CANIF_VARIANT_INFO != 3)
#define CANIF_START_SEC_CONST_UNSPECIFIED
#else
#define CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#endif
#include "CanIf_MemMap.h"
CONST(CanIf_TxCbk_Prototype, CANIF_CONST) CanIf_TxCbk[] =
{
    {NULL_PTR}
};

#if(CANIF_VARIANT_INFO != 2) && (CANIF_VARIANT_INFO != 3)
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#else
#define CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#endif
#include "CanIf_MemMap.h"
























#if(CANIF_VARIANT_INFO == 3)
/* Generate an instance of structure Std_VersionInfoType in CanIf_PBcfg_c.xpt*/
#define CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(Std_VersionInfoType, CANIF_CONST)  CanIf_VersionInfo =
{
    6,    /* Vendor Id */
    60,    /* Module Id */
    4,    /* Sw Major Version */
    0,    /* Sw Minor Version */
    1     /* Sw Patch Version */
};
#define CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"
#endif



/* Global configuration structure */


#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_ConfigType, CANIF_CONST) CanIf_Config =
{
    CanIf_TxPduConfig,
    /* MR12 RULE 1.1 VIOLATION:This is a known defect in CChecker 2.1.0 tool.No fix required in the component.*/
    CanIf_RxPduConfig,
    CanIf_HrhConfig,
    CANIF_NUM_STATIC_CANTXPDUIDS,
    CANIF_NUM_CANRXPDUIDS,
    CANIF_NUM_DYNAMIC_CANTXPDUIDS,
    CANIF_NUM_CONTROLLERS
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"










