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



#ifndef  CANIF_CFG_H
#define  CANIF_CFG_H
/**************************************************************************/
/*                            Include Section                             */
/**************************************************************************/
#include "CanIf_Cfg_SymbolicNames.h"
/*
 **************************************************************************
 * Defines
 **************************************************************************
 */
/**************************************************************************/
/*  Common Published Information                                          */
/**************************************************************************/
 /**
 * @ingroup CANIF_H
 *
 * Vendor Id
 */
#define CANIF_VENDOR_ID                          6u

/**
 * @ingroup CANIF_H
 *
 * Module Id
 */
#define CANIF_MODULE_ID                          60u

/**
 * @ingroup CANIF_H
 *
 * Autosar Release Major Version
 */
#define CANIF_AR_RELEASE_MAJOR_VERSION           4u
/**
 * @ingroup CANIF_H
 *
 * Autosar Release Minor Version
 */
#define CANIF_AR_RELEASE_MINOR_VERSION           2u
/**
 * @ingroup CANIF_H
 *
 * Autosar Release revised version
 */
#define CANIF_AR_RELEASE_REVISION_VERSION        2u

/**
 * @ingroup CANIF_H
 *
 * Software Release Major Version
 */
#define CANIF_SW_MAJOR_VERSION                   4u
/**
 * @ingroup CANIF_H
 *
 * Software Release Minor Version
 */
#define CANIF_SW_MINOR_VERSION                   0u
/**
 * @ingroup CANIF_H
 *
 * Software Release Patch Version
 */
#define CANIF_SW_PATCH_VERSION                   1u


#define CANIF_CONFIGURATION_VARIANT MODULE_VARIANT_PRE_COMPILE




/*Number of variants configured in CanIf*/
#define CANIF_TOTAL_CFG_SETS                1

/**************************************************************************/
/* Description :  Enables or disables the development error detection &   */
/*                notification mechanism                                  */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/
#define CANIF_DEV_ERROR_DETECT                     STD_OFF
/**************************************************************************/
/* Description :  Enables or disables BaudRateChange in the CanDriver     */
/*                                                                         */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/
#define CANIF_PUBLIC_CHANGE_BAUDRATE_SUPPORT             STD_OFF

/**************************************************************************/

/* Description :  Enables or disables CanIf_SetBaudrate API               */
/*                                                                        */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/
#define CANIF_PUBLIC_SET_BAUDRATE_SUPPORT             STD_OFF

/**************************************************************************/

/* Description :  Enables or disables the API CanIf_CancelTransmit()      */
/*                                                                        */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/
#define CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT        STD_OFF

/**************************************************************************/
/* Description :  Enables or disables Rx indication for busoff recovery   */
/*                                                                        */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/
#define CANIF_PUBLIC_BUSOFF_RECOVERY_FROM_RXINDICATION        STD_OFF

/*******************************************************************************************************/
/* Description :  Enables or disables the API CanIf_DirectHw_Write() &  CanIf_Get_DirectHw_Info()      */
/*                                                                                                     */
/* Range       :  STD_ON/STD_OFF                                                                       */
/*******************************************************************************************************/
#define CANIF_DIRECT_HW_WRITE               STD_OFF





/***************************************************************************/
/* Description :  Enables/disables API for reading received L-PDU data     */
/* Range       : STD_OFFD_ON/STD_OFF                                       */
/***************************************************************************/
#define CANIF_READRXPDU_DATA_API                 STD_OFF

/**************************************************************************/
/* Description :  Enables/disables API for reading the notification status*/
/*                of transmit and receive L-PDU                           */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/
#define CANIF_READRXPDU_NOTIFY_STATUS_API         STD_ON

/**************************************************************************/
/* Description :  Enables/disables API for reading the notification status*/
/*                of transmit and receive L-PDU                           */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/
#define CANIF_READTXPDU_NOTIFY_STATUS_API         STD_ON

/***************************************************************************/
/* Description :  Enables / Disables the APIs CanIf_ReadTxmsgId() and      */
/*                CanIf_ReadRxmsgId() for reading configured CanId for     */
/*                configured hardware object (HOH).                        */
/* Range       :  STD_ON/STD_OFF                                           */
/**************************************************************************/
#define CANIF_READMSGID_API                STD_OFF

/***************************************************************************/
/* Description :  Enables / Disables the call back for reading received    */
/*                CanId for configured hardware object (HOH).              */
/* Range       :  STD_ON/STD_OFF                                           */
/**************************************************************************/
#define CANIF_READBUFFERID                STD_OFF

/**********************************************************************************************/
/* Description : Enables/disables the user notification when a PDU in the TxBuffer is cleared */
/*  	due to CAN driver couldn't accept the transmission request                            */
/* Range       :  STD_ON/STD_OFF										                      */
/**********************************************************************************************/
#define CANIF_USER_TXBUFCLEARNOTIFY_API 		STD_OFF
/**************************************************************************/

/* Description :  Configure Error Passive support                         */
/* Range STD_OFF   :  STD_ON/STD_OFF                                      */
/**************************************************************************/
#define CANIF_ERROR_PASSIVE_SUPPORT             STD_OFF
 

/**************************************************************************/
/* Description :  Configure Wakeup support                                */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/
#define CANIF_WAKEUP_SUPPORT                         STD_OFF

/**************************************************************************/
/* Description :  Configure Controller Wakeup support                     */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/
#define CANIF_CTRL_WAKEUP_SUPPORT                   STD_OFF

/**************************************************************************/
/* Description :  Configure  Transceiver Wakeup support                   */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/
#define CANIF_TRCV_WAKEUP_SUPPORT                     STD_OFF

/**************************************************************************/
/* Description :  Configure Wakeup support                                */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/
#define CANIF_TRCV_DRV_CFG                             STD_OFF

/**************************************************************************/
/* Description :  Configure Wakeup Validation                             */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/
#define CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API       STD_OFF

/**************************************************************************/
/* Description :  Configure Wakeup Validation                             */
/* Range       :  0....Num of transceivers                                */
/**************************************************************************/
#define CANIF_NUM_TRANSCEIVERS                        0


/**************************************************************************/
/* Description :  Enables/disables API for reading the version information*/
/*           .     about the CAN interface                                */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/
#define CANIF_VERSION_INFO_API                     STD_OFF

/**************************************************************************/

/* Description :  Enables/disables usage of dynamic IDs                   */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/
#define CANIF_DYNAMIC_ID                         STD_OFF

/**************************************************************************/
/* Description :  Enables/disables API for reconfiguration of the CAN     */
/*                Identifier for each transmit L-PDU                      */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/
#define CANIF_SETDYNAMICTXID_API                 STD_OFF

/**************************************************************************/
/* Description :  Enables/disables Metadata Support                       */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/
#define CANIF_METADATA_SUPPORT                 STD_OFF


/**************************************************************************/
/* Description :  Enables/disables use of transmit buffers                */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/

#define CANIF_TRANSMIT_BUFFER                     STD_OFF






/**************************************************************************/

/* Description :  Enables/disables use of receive buffers                 */
/* Range       :  STD_ON/STD_OFF                                          */
/**************************************************************************/
#define CANIF_RECEIVE_BUFFER                      STD_OFF



/**********************************************************************************************************/
/* Description :  Max Pdu Index for FULL CAN Pdus based on ecuC.ecucPduCollection.pduIdTypeEnum selection */
/* Range       :  0xFFu/ 0xFFFFu                                                                          */
/**********************************************************************************************************/
#define CANIF_MAX_PDU_INDEX  0xFFFFu


 




/**************************************************************************/
/* Description :  Total Number of Dynamic CanTxPduIds to be handled       */
/* Range       :  1..Max Number of defined CanTxPduIds                    */
/**************************************************************************/
#define CANIF_NUM_DYNAMIC_CANTXPDUIDS             0


/**************************************************************************/
/* Description :  Total Number of CanRxPduIds to be handled               */
/* Range       :  1..Max Number of defined CanRxPduIds                    */
/**************************************************************************/

#define CANIF_NUM_CANRXPDUIDS                     25


/**************************************************************************/
/* Description :  Total Number of Static CanTxPduIds to be handled               */
/* Range       :  1..Max Number of defined CanTxPduIds                    */
/**************************************************************************/

#define CANIF_NUM_STATIC_CANTXPDUIDS                    60


/**************************************************************************/
/* Description :  Define Number of transmit buffers.                      */
/*                The L-PDU buffers shall store DLC and max of 8bytes     */
/*                of data.                                                */
/* Range       :  0..Max Number of Tx buffers                             */
/**************************************************************************/
#define CANIF_NUM_TXBUFFERS                     0


/**************************************************************************/
/* Description :  Gives the Number of BASIC CAN HTHs.                     */
/* Range       :  0..Max Number of BASIC CAN HTHs                         */
/**************************************************************************/
#define CANIF_NUM_BASIC_HTH                     0


/******************** Parameters Newly Introduced *************************/


/*Total number of Tx-Pdus configured in CanIf*/
#define CANIF_TOTAL_TXPDUS                  60


/*Total number of Rx-Pdus configured in CanIf*/
#define CANIF_TOTAL_RXPDUS                  25


/*Number of entries in CanIf_TxPduId_CustId_LUT[][]*/
#define CANIF_NUM_CUSTID_ENTRIES            60





/**************************************************************************/
/* Description :  Selects whether the DLC check is supported              */
/* Range       :  STD_ON/STD_STD_OFF                                                  */
/**************************************************************************/
#define CANIF_DLC_CHECK                         STD_OFF







/* Total number of Controllers present in one or more drivers */




#define CANIF_NUM_CONTROLLERS                   4





/* Configuration for the Tx and Rx buffer size */

 
#define CANIF_TXBUFFER_SIZE                     0








#define CANIF_RXBUFFER_SIZE                     0






/* Configuration for retransmission of PDU */
#define CANIF_MAX_RETRY_TIMES                     1





/* Configure the number of HRH handles */
#define CANIF_NUM_HRH_HANDLES                   25


/* Configure total number of CanIds to be received in the list */
#define CANIF_NUM_LIST_CANID                 0









/**************************************************************************/
/* Description :  Number of served CAN hardware units                     */
/* Range       :  1..Max Number of underlying supportted CAN HW units     */
/**************************************************************************/
#define CANIF_NUM_CAN_DRIVERS                   1


/* Configuration for use of extended CAN identifiers */
#define CANIF_EXTENDED_ID                         STD_ON




/* Configuration for use of extended CAN identifiers */
#define CANIF_FD_SUPPORT                       STD_OFF



/* Instance ID */

#define CANIF_INSTANCE_ID                         1







/* Configure CanIf Lite */
#define CANIF_LITE_CONFIGURATION                STD_OFF




/* Configure transmission of CANTP/USER Pdus when the Tx Pdu mode is OFFLINE */
#define CANIF_USER_TP_TX_OFFLINE_MODE            STD_OFF


/* Configuration for enabling/disabling the API CanIf_GetTxConfirmationState() */
#define CANIF_PUBLIC_TXCONFIRM_SUPPORT          STD_OFF


/*PN support*/
#define CANIF_PUBLIC_PN_SUPPORT            STD_OFF



/* CanIf variant info */
#define CANIF_VARIANT_INFO				1   /* PRE-COMPILE */
    




/* Configure support of filtering of CanNm transmit CanIds during reception */
#define CANIF_CANNM_TXID_FILTER                 STD_ON






/* Enable/Disable CanNm Support */
#define CANIF_CANNM_ENABLED                     STD_OFF



/* Enable/Disable J1939Nm Support */
#define CANIF_J1939NM_ENABLED                     STD_OFF


/* Enable/Disable CanTp Support */
#define CANIF_CANTP_ENABLED                     STD_ON



/* Enable/Disable CAN_TSYN Support */
#define CANIF_CANTSYN_ENABLED                    STD_OFF




/* Enable/Disable PduR Support */
#define CANIF_PDUR_ENABLED                     STD_OFF







/* Enable/Disable CDD Support */
#define CANIF_CDD_RX_ENABLED                    STD_ON



/* Enable/Disable USER Support */
#define CANIF_USER_RX_ENABLED                    STD_OFF




/* Enable/Disable USER or CDD Support */
#define CANIF_USER_CDD_TX_ENABLED                STD_ON







/* Enable/Disable XCP Support */
#define CANIF_XCP_ENABLED                       STD_OFF







/* Enable/Disable XCP Support */
#define CANIF_J1939TP_ENABLED                       STD_OFF






/*Wakeup Validation by NM-Pdu*/
#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM         STD_OFF


/* Configure support of BASIC CAN Reception */


#define CANIF_BASIC_CAN_SUPPORT                   STD_ON


/* Configure support of CanId List for reception */
#define CANIF_BASIC_CAN_SUPPORT_LIST            STD_OFF

/* Macro generated via scripts when multiple Ranges of CanIds are configured under a HRH */
#define CANIF_RXPDU_CANID_RANGE                    STD_OFF




/* Calibration Enabled/Disabled */

#define CANIF_CALIBRATION                STD_OFF









 




 

/* Include the Controller name */
typedef enum
{
    CANIF_Can_Network_CANNODE_0 = 0,
    CANIF_Can_Network_CANNODE_1 = 1,
    CANIF_Can_Network_CANNODE_2 = 2,
    CANIF_Can_Network_CANNODE_3 = 3

}CanIf_ControllerName;











#endif /* CANIF_CFG_H */
