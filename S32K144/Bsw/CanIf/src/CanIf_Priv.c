

/****************************************************************************************************/
/*                                  Include Section                                                 */
/****************************************************************************************************/

#include "CanIf_Priv.h"

/***************************************************************************************************
 * Variables
 ***************************************************************************************************
 */

/* Flag to check if CANIF is Initialized(TRUE) or Not Initialized (FALSE)*/
#define CANIF_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanIf_MemMap.h"
VAR(boolean, CANIF_VAR) CanIf_Init_Flag = FALSE;
#define CANIF_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanIf_MemMap.h"

/*The below part of the code shall be enabled only for Pre-Compile.
 * For Post-build, the extern declarations are available in CanIf_Cfg.h*/
/*-----------------------------------------------------------------------------*/
#if(CANIF_VARIANT_INFO == 1)
/* Store the CanIds set by the function CanIf_SetDynamicTxPduId() */
/* FC_DeviationPoint_START */

#if (CANIF_DYNAMIC_ID != STD_OFF)
 /* FC_DeviationPoint_END */

   /* FC_CODE_START */
 //#if (CANIF_SETDYNAMICTXID_API != STD_OFF)
 /* FC_CODE_END */
#define CANIF_START_SEC_VAR_CLEARED_32
#include "CanIf_MemMap.h"
VAR(uint32, CANIF_VAR) CanIf_Dynamic_CanTxPdu_CanId[CANIF_NUM_DYNAMIC_CANTXPDUIDS];
#define CANIF_STOP_SEC_VAR_CLEARED_32
#include "CanIf_MemMap.h"
#endif

/* Store the Device Mode and Channel Mode of each controller*/
#define CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"
VAR(CanIf_ControllerStateType, CANIF_VAR) CanIf_ControllerState[CANIF_NUM_CONTROLLERS];
#define CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"

/* TxBuffer Array */
 /* FC_DeviationPoint_START */
#if (CANIF_TRANSMIT_BUFFER != STD_OFF)
     /* FC_DeviationPoint_END */

        /* FC_CODE_START */
//#if (CANIF_PUBLIC_TX_BUFFERING != STD_OFF)
  /*  FC_CODE_END */
#define CANIF_START_SEC_VAR_CLEARED_8
#include "CanIf_MemMap.h"
VAR(uint8, CANIF_VAR) CanIf_TxBuffer[CANIF_TXBUFFER_SIZE];
#define CANIF_STOP_SEC_VAR_CLEARED_8
#include "CanIf_MemMap.h"


/* Array to hold the transmit buffer allocation status */
#define CANIF_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanIf_MemMap.h"
VAR(boolean, CANIF_VAR) CanIf_TxBufferAllocated[CANIF_NUM_STATIC_CANTXPDUIDS + CANIF_NUM_DYNAMIC_CANTXPDUIDS];
#define CANIF_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanIf_MemMap.h"
/*Array to hold the BASIC HTH status*/
VAR(boolean, CANIF_VAR) CanIf_HTHBusyStatusFlag_a_b[CANIF_NUM_BASIC_HTH];
#define CANIF_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanIf_MemMap.h"
#endif

/* RxBuffer Array */
/* FC_DeviationPoint_START */
#if (CANIF_RECEIVE_BUFFER != STD_OFF)
 /* FC_DeviationPoint_END */

  /* FC_CODE_START */
 //#if (CANIF_READRXPDU_DATA_API != STD_OFF)
  /* FC_CODE_END */
#define CANIF_START_SEC_VAR_CLEARED_8
#include "CanIf_MemMap.h"
VAR(uint8, CANIF_VAR) CanIf_RxBuffer[CANIF_RXBUFFER_SIZE];
#define CANIF_STOP_SEC_VAR_CLEARED_8
#include "CanIf_MemMap.h"
#endif

/* Store the Notification Status of each CanTxPduId  */
#define CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"
VAR(CanIf_NotifStatusType, CANIF_VAR) CanIf_TxNotification[CANIF_NUM_STATIC_CANTXPDUIDS + CANIF_NUM_DYNAMIC_CANTXPDUIDS];
#define CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"


#if (CANIF_READRXPDU_NOTIFY_STATUS_API != STD_OFF)
/* Store the Notification Status of each CanRxPduId  */
#define CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"
VAR(CanIf_NotifStatusType, CANIF_VAR) CanIf_RxNotification[CANIF_NUM_CANRXPDUIDS];
#define CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"
#endif

#if (CANIF_PUBLIC_TXCONFIRM_SUPPORT != STD_OFF)
/* Array to hold the transmit confirmation status */
#define CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"
VAR(CanIf_NotifStatusType, CANIF_VAR) CanIf_TxConf_State[CANIF_NUM_CONTROLLERS];
#define CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"
#endif

#if (CANIF_WAKEUP_SUPPORT != STD_OFF || CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API != STD_OFF)
/* To store the wakeup events */
#define CANIF_START_SEC_VAR_CLEARED_8
#include "CanIf_MemMap.h"
VAR(uint8, CANIF_VAR) CanIf_WakeUp_Event[CANIF_NUM_CONTROLLERS];
#define CANIF_STOP_SEC_VAR_CLEARED_8
#include "CanIf_MemMap.h"

/* To store the status of a new Rx message */
#define CANIF_START_SEC_VAR_CLEARED_8
#include "CanIf_MemMap.h"
VAR(uint8, CANIF_VAR) CanIf_NewMsg_Rx[CANIF_NUM_CONTROLLERS];
#define CANIF_STOP_SEC_VAR_CLEARED_8
#include "CanIf_MemMap.h"


#endif

#endif
/*-----------------------------------------------------------------------------*/


/*Trcv LUT*/
#if (CANIF_TRCV_DRV_CFG != STD_OFF)
#define CANIF_START_SEC_CONST_8
#include "CanIf_MemMap.h"
CONST (uint8, CANIF_CONST) CanIf_Trcv_LUT[CANIF_NUM_TRANSCEIVERS] = {CANIF_TRCV_LUT};
#define CANIF_STOP_SEC_CONST_8
#include "CanIf_MemMap.h"
#endif


#if (CANIF_VARIANT_INFO > 1)
/*This hold the current config set details*/
#define CANIF_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"
P2CONST(CanIf_ConfigType, AUTOMATIC, AUTOMATIC) CanIf_ConfigSetPtr;
#define CANIF_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"


/*To hold the index of the active config set*/
#define CANIF_START_SEC_VAR_FAST_CLEARED_8
#include "CanIf_MemMap.h"
VAR(uint8, AUTOMATIC) CanIf_ActiveCfgSet;
#define CANIF_STOP_SEC_VAR_FAST_CLEARED_8
#include "CanIf_MemMap.h"
#endif



