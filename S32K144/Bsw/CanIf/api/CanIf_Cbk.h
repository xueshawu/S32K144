

/**
\defgroup CANIF_CBK_H    CANIF - AUTOSAR interfaces CANIF callback functions
*/
#ifndef CANIF_CBK_H
#define CANIF_CBK_H

/***************************************************************************************************
**                      Include Section                                                           **
***************************************************************************************************/
/*File included here to avoid this being included by CanDrv in Can.c and Can_Cfg.c*/
#include "CanIf_Cfg.h"
#include "CanIf_RxIndication_Integration.h"


/***************************************************************************************************
**                                   Global Callback Function Prototypes                          **
***************************************************************************************************/

/**
 * @ingroup CANIF_CBK_H
 *
 * This service is called by the CAN driver after the CAN L-PDU has been transmitted on the CAN network.\n                                                                          \n
 *
 * @param  In:  CanTxPduId      -   L-PDU handle of CAN L-PDU successfully transmitted. \n
 *
 * @return None \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_TxConfirmation(
                                                    VAR(PduIdType,AUTOMATIC) CanTxPduId
                                                   );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
/**
 * @ingroup CANIF_CBK_H
 *
 * This service is called by the CAN driver after a CAN L-PDU has been received. Within this
 *                     service, the CAN Interface translates the CanId into the configured target PDU ID and routes
 *                     this indication to the configured upper layer target \n
 *
 * @param  In:  Hrh         -   ID of the corresponding Hardware Object Range: 0..(total number of HRH -1). \n
 * @param  In:  CanId       -   Standard/Extended CAN ID of CAN L-PDU that has been successfully received \n
 * @param  In:  CanDlc      -   Data Length Code (length of CAN L-PDU payload).
 * @param  In:  CanSduPtr   -   Pointer to received L-SDU (payload).
 *
 * @return None \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_RxIndication_Internal(
                                                          VAR(Can_HwHandleType, AUTOMATIC) Hrh,
                                                          VAR(Can_IdType, AUTOMATIC) CanId,
                                                          VAR(uint8, AUTOMATIC) CanDlc,
                                                          P2CONST (uint8, AUTOMATIC, CANIF_APPL_DATA) CanSduPtr
                                                         );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
/**
 * @ingroup CANIF_CBK_H
 *
 * This service indicates a Controller BusOff event referring to the corresponding CAN Controller. \n
 * This service is called by the CAN driver.\n
 * @param  In:  Controller      -   CAN controller, where a BusOff occured. \n
 *
 * @return None \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_ControllerBusOff(
                                                        VAR(uint8,AUTOMATIC) Controller
                                                    );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
/**
 * @ingroup CANIF_CBK_H
 *
 *  Service indicates a mode change is successful for the particular CAN controller. This service is called by the CAN driver. \n
 *
 * @param  In:  Controller      -   CAN controller, which state has been transitioned. \n
 * @param  In:  ControllerMode  -   Mode to which the CAN controller transitioned. \n
 *
 * @return None \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication(
                                                        VAR(uint8,AUTOMATIC) Controller,
                                                        VAR(CanIf_ControllerModeType, AUTOMATIC) ControllerMode
                                                    );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#if CANIF_TRCV_DRV_CFG!=STD_OFF
/**
 * @ingroup CANIF_CBK_H
 *
 * This service indicates a transceiver state transition referring to the corresponding CAN transceiver.\n
 *
 * @param  In:  Transceiver     -   CAN controller, which state has been transitioned. \n
 * @param  In:  TransceiverMode -   Mode to which the CAN transceiver transitioned. \n
 *
 * @return None \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_TrcvModeIndication( VAR(uint8,AUTOMATIC) Transceiver, VAR(CanTrcv_TrcvModeType,AUTOMATIC) TransceiverMode);
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif
/* FC_VariationPoint_START */
/**
 * @ingroup CANIF_CBK_H
 *
 * This service indicates a CAN controller Error Passive event referring to the corresponding CAN controller. This service is called by the CAN driver. \n
 *
 * @param  In:  Controller      -   Id of the CAN controller. \n
 *
 * @return None \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_ControllerErrorPassive(
                                                            VAR(uint8, AUTOMATIC) Controller
                                                           );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
/* FC_VariationPoint_END */

#if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)
/**
 * @ingroup CANIF_CBK_H
 *
 * This service indicates that the transceiver has cleared the WufFlag.\n
 *
 * @param  In:  TransceiverId       -   CAN transceiver ID. \n
 *
 * @return None \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication(
                                              VAR(uint8,AUTOMATIC) TransceiverId
                                                        );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
/**
 * @ingroup CANIF_CBK_H
 *
 * This service indicates the reason for the wake up that CAN Tranceiver has detected.\n
 *
 * @param  In:  TransceiverId       -   CAN transceiver ID. \n
 *
 * @return None \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication(
                                              VAR(uint8,AUTOMATIC) TransceiverId
                                                        );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
/**
 * @ingroup CANIF_CBK_H
 *
 * This service indicates that tranceiver is running in PN communication mode.\n
 *
 * @param  In:  TransceiverId       -   CAN transceiver ID. \n
 *
 * @return None \n
 */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability(
                                              VAR(uint8,AUTOMATIC) TransceiverId
                                                        );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif

#endif   /* CANIF_CBK_H */


