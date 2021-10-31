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




{ CANIF_FULL,       7    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0xE0,       0x1FFFFFFFU }/*Can_Network_CANNODE_0_Rx_Std_MailBox_1*/,
{ CANIF_FULL,       11    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0xE2,       0x1FFFFFFFU }/*Can_Network_CANNODE_0_Rx_Std_MailBox_2*/,
{ CANIF_FULL,       12    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x200,       0x1FFFFFFFU }/*Can_Network_CANNODE_0_Rx_Std_MailBox_3*/,
{ CANIF_FULL,       13    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0xF8,       0x1FFFFFFFU }/*Can_Network_CANNODE_0_Rx_Std_MailBox_4*/,
{ CANIF_FULL,       14    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x2B0,       0x1FFFFFFFU }/*Can_Network_CANNODE_0_Rx_Std_MailBox_5*/,
{ CANIF_FULL,       15    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x2A6,       0x1FFFFFFFU }/*Can_Network_CANNODE_0_Rx_Std_MailBox_6*/,
{ CANIF_FULL,       16    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x222,       0x1FFFFFFFU }/*Can_Network_CANNODE_0_Rx_Std_MailBox_7*/,
{ CANIF_FULL,       17    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x290,       0x1FFFFFFFU }/*Can_Network_CANNODE_0_Rx_Std_MailBox_8*/,
{ CANIF_FULL,       18    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0xC0,       0x1FFFFFFFU }/*Can_Network_CANNODE_0_Rx_Std_MailBox_9*/,
{ CANIF_FULL,       8    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x6B4,       0x1FFFFFFFU }/*Can_Network_CANNODE_0_Rx_Std_MailBox_10*/,
{ CANIF_FULL,       9    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0xFA,       0x1FFFFFFFU }/*Can_Network_CANNODE_0_Rx_Std_MailBox_11*/,
{ CANIF_FULL,       10    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x2C4,       0x1FFFFFFFU }/*Can_Network_CANNODE_0_Rx_Std_MailBox_12*/,
{ CANIF_FULL,       5    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x7C0,       0x1FFFFFFFU }/*CanIfHrhCfg_uds_rx_phy*/,
{ CANIF_FULL,       4    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x7DF,       0x1FFFFFFFU }/*CanIfHrhCfg_uds_rx_fuc*/,
{ CANIF_FULL,       2    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NONE,   0x583,       0x1FFFFFFFU }/*CanIfHrhCfg_CanNm_Rx_MCU*/,
{ CANIF_FULL,       1    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NONE,   0x580,       0x1FFFFFFFU }/*CanIfHrhCfg_CanNm_Rx_HCU*/,
{ CANIF_FULL,       0    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NONE,   0x581,       0x1FFFFFFFU }/*CanIfHrhCfg_CanNm_Rx_GW*/,
{ CANIF_BASIC_RANGE_SFON_SINTGT,       3    ,       0x7F    ,   (uint8)CANIF_Can_Network_CANNODE_0,       CANIF_READ_NONE,   0x584,       0x1FFFFF80U }/*CanIfHrhCfg_CanNm_Rx_Res*/,
{ CANIF_FULL,       6    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_1,       CANIF_READ_NOTIFSTATUS,   0x650,       0x1FFFFFFFU }/*CanIfHrhCfg_xcp_rx_req*/,
{ CANIF_FULL,       19    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_3,       CANIF_READ_NOTIFSTATUS,   0x186CF4A2,       0x1FFFFFFFU }/*Can_Network_CANNODE_1_Rx_Ext_MailBox_1*/,
{ CANIF_FULL,       20    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_3,       CANIF_READ_NOTIFSTATUS,   0x1869F4A2,       0x1FFFFFFFU }/*Can_Network_CANNODE_1_Rx_Ext_MailBox_2*/,
{ CANIF_FULL,       21    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_3,       CANIF_READ_NOTIFSTATUS,   0x1868F4A2,       0x1FFFFFFFU }/*Can_Network_CANNODE_1_Rx_Ext_MailBox_3*/,
{ CANIF_FULL,       22    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_3,       CANIF_READ_NOTIFSTATUS,   0x186AF4A2,       0x1FFFFFFFU }/*Can_Network_CANNODE_1_Rx_Ext_MailBox_4*/,
{ CANIF_FULL,       23    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_3,       CANIF_READ_NOTIFSTATUS,   0x186BF4A2,       0x1FFFFFFFU }/*Can_Network_CANNODE_1_Rx_Ext_MailBox_5*/,
{ CANIF_FULL,       24    ,       1    ,   (uint8)CANIF_Can_Network_CANNODE_3,       CANIF_READ_NOTIFSTATUS,   0x3C2,       0x1FFFFFFFU }/*Can_Network_CANNODE_1_Rx_Std_MailBox_6*/
};

#define CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"















/* Rx PDUs Configuration */

#define CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[]=
{
/*     RxBufferOffset,  target ID,  RxPduId , HRH , CbkIdx, User, CanIdType, DLC,  RxPduCanId      */

{    0 ,   CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_CanNm_Rx_GW,       5,  0,   CANNM,   0x20u,   8,   0x581 },
{    0 ,   CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_CanNm_Rx_HCU,       4,  0,   CANNM,   0x20u,   8,   0x580 },
{    0 ,   CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_CanNm_Rx_MCU,       3,  0,   CANNM,   0x20u,   8,   0x583 },
{    0 ,   CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_CanNm_Rx_Res,       6,  0,   CANNM,   0x20u,   8,   0x584 },
{     4,   CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_uds_rx_fuc,       1,  0,   CDD,   0x20u,   8,   0x7DF },
{     5,   CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_uds_rx_phy,       0,  1,   CDD,   0x20u,   8,   0x7C0 },
{     6,   CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_xcp_rx_req,       2,  2,   CDD,   0x20u,   8,   0x650 },

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










