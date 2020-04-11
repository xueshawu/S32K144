/**
*   @file           Eth_GeneralTypes.h
*   @implements     Eth_GeneralTypes.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - Eth General Types.
*   @details Definitions of types for the Ethernet driver
*            This file contains sample code only. It is not part of the production code deliverables
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

#ifndef ETH_GENERALTYPES_H
#define ETH_GENERALTYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Eth_GeneralTypes_h_REF_1
*      Violates MISRA 2004 Required Rule 1.4, A compiler/linker shall be checked to ensure that 31
*      character significance and case sensitivity are supported for external identifiers.
*      The used compilers use more than 31 chars for identifiers
* @section Eth_GeneralTypes_h_REF_2
*     Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
*     contents of a header file being included twice. 
*     This is not a violation since all header files are protected against multiple inclusions
* @section [global]
*     Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*     on the significance of more than 31 characters. The used compilers use more than 31 chars for
*     identifiers.
* @section [global]
*     Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and 
*     functions shall not be reused. The driver needs to use defines starting with letter E.

*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
 * @violates @ref Eth_GeneralTypes_h_REF_2 precautions to prevent the
 * contents of a header file being included twice  */
#include "ComStack_Types.h" /* Mandatory include - see the SWS */

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
* @brief          The Ethernet driver state.
* @details        A variable of this type holds the state of the Ethernet driver
*                 module. The driver is at the ETH_STATE_UNINIT at the beginning
*                 until the Eth_Init() function is called. The state remains
*                 equal to the ETH_STATE_INIT until the Eth_ControllerInit()
*                 function is called. Then the state is ETH_STATE_ACTIVE.
* @implements     Eth_StateType_enumeration
*/
typedef enum
{
    ETH_STATE_UNINIT = 0, /**< The driver has not been initialized yet */
     ETH_STATE_INIT        /**< The driver has not been configured and
                               the controller was configured */
 } Eth_StateType;

/**
* @brief          The Ethernet controller mode.
* @details        This type is used to store the information whether the
*                 Ethernet controller is stopped or running.
* @implements     Eth_ModeType_enumeration
*/
typedef enum
{
    ETH_MODE_DOWN = 0,    /**< Controller is shut down */
    ETH_MODE_ACTIVE       /**< Controller is active */
}  Eth_ModeType;

/**
* @brief          The Ethernet reception status
* @details        This status is returned by the @c Eth_Receive() function to indicate
*                 whether any frame has been received and if yes, whether there is any
*                 frame still waiting in the queue (for another @c Eth_Receive() call).
* @implements     Eth_RxStatusType_enumeration
*/
 typedef enum
{
    ETH_RECEIVED = 0,   /**< A frame has been received and there are no more frames in the queue */
    ETH_NOT_RECEIVED,   /**< No frames received */
    ETH_RECEIVED_MORE_DATA_AVAILABLE /**< A frame received and at least another one in the queue detected */
} Eth_RxStatusType;
 /**
* @brief          Action type for PHY address filtering
* @details        The Enumeration type describes the action to be taken
*                 for the MAC address given in *PhysAddrPtr
* @implements     Eth_FilterActionType_enumeration
*/
typedef enum
{
    ETH_ADD_TO_FILTER = 0,    /**< Add address to the filter */
    ETH_REMOVE_FROM_FILTER    /**< Remove address */
} Eth_FilterActionType;

 /**
* @brief          This type defines the transceiver modes
* @details        The Enumeration type describes the transceiver modes
* @implements     EthTrcv_ModeType_enumeration
*/
typedef enum
{
    ETHTRCV_MODE_DOWN = 0,    /**<  Transceiver disabled */
    ETHTRCV_MODE_ACTIVE       /**<  Transceiver enable */
} EthTrcv_ModeType;
 
/**
* @brief          The Ethernet specific return type
* @details        This return type informs about the function success or failure status.
* @implements     Eth_ReturnType_enumeration
*/
typedef enum
{
    ETH_OK = 0,         /**< Success */
    ETH_E_NOT_OK,       /**< General failure */
    ETH_E_NO_ACCESS     /**< Ethernet hardware access failure */
}  Eth_ReturnType;

/**
* @brief          The Ethernet quality of timestamp type
* @details        Depending on the HW, quality information regarding the evaluated time stamp 
*                 might be supported. If not supported, the value shall be always Valid. For 
*                 Uncertain and Invalid values, the upper layer shall discard the time stamp.
* @implements     Eth_TimeStampQualType_enumeration
*/
typedef enum
{
    ETH_VALID = 0,         /**< Success */
    ETH_INVALID,       /**< General failure */
    ETH_UNCERTAIN     /**< Ethernet hardware access failure */
}  Eth_TimeStampQualType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief         Frame type.
* @details       This type is used to pass the value of type or length field in the
*                Ethernet frame header. It is 16 bits long unsigned integer.
*                - Values less than or equal to 1500 represent the length.
*                - Values grater than 1500 represent the type (i.e. 0x800 = IP).
* @implements     Eth_FrameType_type
*/
typedef uint16 Eth_FrameType;

/**
* @brief         Type used to pass transmit or receive data to or from the driver.
* @details       This type was defined as 8 bit wide unsigned integer because
*                this definition is available on all CPU types.
* @implements     Eth_DataType_type
*/
typedef uint8 Eth_DataType;

/**
* @brief         Type used to identify the ethernet buffer. 
* @details       This type was defined for index of buffer used in transmitted and received data.
* @implements     Eth_BufIdxType_type
*/
typedef uint32 Eth_BufIdxType;

/**
* @brief         Type used to express the timestamp value.
* @details       Variables of this type are used for expressing time stamps including relative time
*                and absolute calendar time. The absolute time starts acc. to "[5], Annex C/C1"
*                specification at 1970-01-01.
*                0 to 281474976710655s
*                == 3257812230d
*                [0xFFFF FFFF FFFF]
*                0 to 999999999ns
*                [0x3B9A C9FF]
*                invalid value in nanoseconds: [0x3B9A CA00] to [0x3FFF FFFF]
*                Bit 30 and 31 reserved, default: 0
* @implements    Eth_TimeStampType_type
*/
typedef struct
{
    VAR(uint32, ETH_VAR) nanoseconds;   /**< @brief Nanoseconds part of the time */
    VAR(uint32, ETH_VAR) seconds;       /**< @brief 32 bit LSB of the 48 bits Seconds part of the time */
    VAR(uint16, ETH_VAR) secondsHi;     /**< @brief 16 bit MSB of the 48 bits Seconds part of the time */
} Eth_TimeStampType;
/**
* @brief         Type used to express the diff between timestamp values.
* @details       Variables of this type are used to express time differences in a usual way. The
*                described "TimeInterval" type referenced in ", chapter 6.3.3.3" will not be used
*                and hereby slightly simplified.
* @implements    Eth_TimeIntDiffType_type
*/
typedef struct
{
    VAR(Eth_TimeStampType, ETH_VAR) diff;   /**< @brief diff time difference */
    VAR(boolean, ETH_VAR) sign;       /**< @brief Positive (True) Or negative (False) time */
} Eth_TimeIntDiffType;
/**
* @brief         Type used to express frequency ratio.
* @details       Variables of this type are used to express frequency ratios.
* @implements    Eth_RateRatioType_type
*/
typedef struct
{
    VAR(Eth_TimeIntDiffType, ETH_VAR) IngressTimeStampDelta;   /**< @brief   IngressTimeStampSync2 -IngressTimeStampSync1 */
    VAR(Eth_TimeIntDiffType, ETH_VAR) OriginTimeStampDelta;       /**< @brief OriginTimeStampSync2[FUP2]-OriginTimeStampSync1[FUP1] */
} Eth_RateRatioType;

/**
* @brief         counter values according to IETF RFC 1757, RFC 1643 and RFC 2233
* @details       counter values according to IETF RFC 1757, RFC 1643 and RFC 2233
* @implements    Eth_CounterType_type
*/
typedef struct
{
    VAR(uint32, ETH_VAR) DropPktBufOverrun;    /**< @brief  dropped packets due to buffer overrun */
    VAR(uint32, ETH_VAR) DropPktCrc;           /**< @brief  dropped packets due to CRC errors */
    VAR(uint32, ETH_VAR) UndersizePkt;         /**< @brief  number of undersize packets which were less than 64 octets long (excluding \
                                                            framing bits, but including FCS octets) and were otherwise well formed. */
    VAR(uint32, ETH_VAR) OversizePkt;          /**< @brief  number of oversize packets which are longer than 1518 octets (excluding \
                                                            framing bits, but including FCS octets) and were otherwise well formed. */
    VAR(uint32, ETH_VAR) AlgnmtErr;            /**< @brief  number of alignment errors, i.e. packets which are received and are not an \
                                                            integral number of octets in length and do not pass the CRC. */
    VAR(uint32, ETH_VAR) SqeTestErr;           /**< @brief  SQE test error according to IETF RFC1643 dot3StatsSQETestErrors */
    VAR(uint32, ETH_VAR) DiscInbdPkt;          /**< @brief  The number of inbound packets which were chosen to be discarded \
                                                            even though no errors had been detected to prevent their being deliverable \
                                                            to a higher-layer protocol. One possible reason for discarding such a packet \
                                                            could be to free up buffer space. */
    VAR(uint32, ETH_VAR) ErrInbdPkt;           /**< @brief  total number of erroneous inbound packets */
    VAR(uint32, ETH_VAR) DiscOtbdPkt;          /**< @brief  The number of outbound packets which were chosen to be \
                                                            discarded even though no errors had been detected to prevent their being transmitted. \
                                                            One possible reason for discarding such a packet could be to free up buffer space. */
    VAR(uint32, ETH_VAR) ErrOtbdPkt;           /**< @brief  total number of erroneous outbound packets */
    VAR(uint32, ETH_VAR) SnglCollPkt;          /**< @brief  Single collision frames: A count of successfully transmitted frames \
                                                            on a particular interface for which transmission is inhibited by exactly one */
    VAR(uint32, ETH_VAR) MultCollPkt;          /**< @brief  Multiple collision frames: A count of successfully transmitted frames on a \
                                                            particular interface for which transmission is inhibited by more than one collision. */
    VAR(uint32, ETH_VAR) DfrdPkt;              /**< @brief  Number of deferred transmission: A count of frames for which the first \
                                                            transmission attempt on a particular interface is delayed because the medium is busy. */
    VAR(uint32, ETH_VAR) LatCollPkt;           /**< @brief  Number of late collisions: The number of times that a collision is detected on a \
                                                            particular interface later than 512 bittimes into the transmission of a packet. */
    VAR(uint32, ETH_VAR) HwDepCtr0;            /**< @brief  hardware dependent counter value */
    VAR(uint32, ETH_VAR) HwDepCtr1;            /**< @brief  hardware dependent counter value */
    VAR(uint32, ETH_VAR) HwDepCtr2;            /**< @brief  hardware dependent counter value */
    VAR(uint32, ETH_VAR) HwDepCtr3;            /**< @brief  hardware dependent counter value */
} Eth_CounterType;

/**
* @brief         List of values according to IETF RFC 2819 (Remote Network Monitoring Management Information Base)
* @details       List of values according to IETF RFC 2819 (Remote Network Monitoring Management Information Base)
* @implements    Eth_RxStatsType_type
*/
typedef struct
{
    VAR(uint32, ETH_VAR) RxStatsDropEvents;              /**< @brief  The total number of events in which packets were dropped by the probe
                                                                      due to lack of resources. */
    VAR(uint32, ETH_VAR) RxStatsOctets;                  /**< @brief  The total number of octets of data (including those in bad packets)
                                                                      received on the network (excluding framing bits but including FCS octets). */
    VAR(uint32, ETH_VAR) RxStatsPkts;                    /**< @brief  The total number of packets (including bad packets, broadcast packets,
                                                                      and multicast packets) received. */
    VAR(uint32, ETH_VAR) RxStatsBroadcastPkts;           /**< @brief  The total number of good packets received that were directed to the
                                                                      broadcast address. */
    VAR(uint32, ETH_VAR) RxStatsMulticastPkts;           /**< @brief  The total number of good packets received that were directed to a
                                                                      multicast address. */
    VAR(uint32, ETH_VAR) RxStatsCrcAlignErrors;          /**< @brief  The total number of packets received that had a length of bertween 64 and 1518 octets
                                                                      that had either a bad Frame Check Sequence (FCS) with an integral number of octets (FCS Error) or a bad FCS with a non-integral number of octets (Alignment Error). */
    VAR(uint32, ETH_VAR) RxStatsUndersizePkts;           /**< @brief  The total number of packets received that were less than 64 octets long
                                                                      (excluding framing bits, but including FCS octets) and were otherwise well formed. */
    VAR(uint32, ETH_VAR) RxStatsOversizePkts;            /**< @brief  The total number of packets received that were longer than 1518 octets
                                                                      (excluding framing bits, but including FCS octets) and were otherwise well formed. */
    VAR(uint32, ETH_VAR) RxStatsFragments;               /**< @brief  The total number of packets received that were less than 64 octets in length
                                                                      (excluding framing bits but including FCS octets) and had either a bad Frame Check Sequence (FCS) with an integral number of octets (FCS Error) or a bad FCS
                                                                      with a non-integralnumber of octets (Alignment Error). */
    VAR(uint32, ETH_VAR) RxStatsJabbers;                 /**< @brief  The total number of packets received that were longer than 1518 octets,
                                                                      and had either a bad Frame Check Sequence (FCS) with an integral number of octets (FCS Error) or a bad FCS with a nonintegral number of octets (Alignment Error). */
    VAR(uint32, ETH_VAR) RxStatsCollisions;              /**< @brief  The best estimate of the total number of collisions on this Ethernet segment. */
    VAR(uint32, ETH_VAR) RxStatsPkts64Octets;            /**< @brief  The total number of packets (including bad packets) received
                                                                      that were 64 octets in length. */
    VAR(uint32, ETH_VAR) RxStatsPkts65to127Octets;       /**< @brief  The total number of packets (including bad packets) received
                                                                      that were between 65 and 127 octets in length. */
    VAR(uint32, ETH_VAR) RxStatsPkts128to255Octets;      /**< @brief  The total number of packets (including bad packets) received
                                                                      that were between 128 and 255 octets in length. */
    VAR(uint32, ETH_VAR) RxStatsPkts256to511Octets;      /**< @brief  The total number of packets (including bad packets) received
                                                                      that were between 256 and 511 octets in length. */
    VAR(uint32, ETH_VAR) RxStatsPkts512to1023Octets;     /**< @brief  The total number of packets (including bad packets) received
                                                                      that were between 512 and 1023 octets in length. */
    VAR(uint32, ETH_VAR) RxStatsPkts1024to1518Octets;    /**< @brief  The total number of packets (including bad packets) received
                                                                      that were between 1024 and 1518 octets in length. */
    VAR(uint32, ETH_VAR) RxUnicastFrames;                /**< @brief  The number of subnetwork-unicast packets delivered to a higher-layer protocol. */
} Eth_RxStatsType;


/**
* @brief         List of values to read statistic values for transmission.
* @details       List of values to read statistic values for transmission.
* @implements    Eth_TxStatsType_type
*/
typedef struct
{
    VAR(uint32, ETH_VAR) TxNumberOfOctets;    /**< @brief  The total number of octets transmitted out of the interface, \
                                                                  including framing characters */
    VAR(uint32, ETH_VAR) TxNUcastPkts;        /**< @brief  The total number of packets that higherlevel protocols requested be transmitted \
                                                                  to a non-unicast (i.e., a subnetworkbroadcast or subnetwork-multicast) \
                                                                  address, including those that were discarded or not sent */
    VAR(uint32, ETH_VAR) TxUniCastPkts;       /**< @brief  The total number of packets that higherlevel protocols requested be transmitted \
                                                                  to a subnetwork-unicast address, including those that were discarded or not sent */
} Eth_TxStatsType;

/**
* @brief         List of values to read statistic error counter values for transmission
* @details       List of values to read statistic error counter values for transmission
* @implements    Eth_TxErrorCounterValuesType_type
*/
typedef struct
{
    VAR(uint32, ETH_VAR) TxDroppedNoErrorPkts;    /**< @brief  The number of outbound packets which were chosen to be discarded \
                                                               even though no errors had been detected to prevent their being \
                                                               transmitted. One possible reason for discarding such a packet could be to \
                                                               free up buffer space. */
    VAR(uint32, ETH_VAR) TxDroppedErrorPkts;      /**< @brief  transmitted because of errors */
    VAR(uint32, ETH_VAR) TxDeferredTrans;         /**< @brief  A count of frames for which the first transmission attempt on a particular \
                                                               interface is delayed because the medium is busy. The count represented \
                                                               by an instance of this object does not include frames involved in collisions */
    VAR(uint32, ETH_VAR) TxSingleCollision;       /**< @brief  A count of successfully transmitted frames on a particular interface for \
                                                               which transmission is inhibited by exactly one collision. A frame that is \
                                                               counted by an instance of this object is also counted by the corresponding \
                                                               instance of either the TxUniCastPkts and TxNUcastPkts and is not counted \
                                                               by the corresponding instance of the TxMultipleCollision object. */
    VAR(uint32, ETH_VAR) TxMultipleCollision;     /**< @brief  A count of successfully transmitted frames on a particular interface for \
                                                               which transmission is inhibited by more than one collision. A frame that \
                                                               is counted by an instance of this object is also counted by the corresponding \
                                                               instance of either the TxUniCastPkts and TxNUcastPkts and is not counted \
                                                               by the corresponding instance of the TxSingleCollision object. */
    VAR(uint32, ETH_VAR) TxLateCollision;         /**< @brief  The number of times that a collision is detected on a particular interface \
                                                               later than 512 bit-times into the transmission of a packet. Five hundred \
                                                               and twelve bit-times corresponds to 51.2 microseconds on a 10 Mbit/s \
                                                               system. A (late) collision included in a count represented by an instance of \
                                                               this object is also considered as a (generic) collision for purposes of \
                                                               other collision-related statistics. */
    VAR(uint32, ETH_VAR) TxExcessiveCollison;     /**< @brief  A count of frames for which transmission on a particular interface \
                                                               fails due to excessive collisions. */
} Eth_TxErrorCounterValuesType;

/**
* @brief        Eth_MacVlanType type definition
* @details      The interpretation of this value is not specified, i.e. whether it is number of used
*               bytes or number of used memory cells, etc.
* @implements   Eth_MacVlanType_type
*/
typedef struct
{
    VAR(uint8, ETH_VAR) MacAddr[6];        /** @brief Specifies the MAC address [0..255,0..255,0..255,0..255,0..255,0..255] */
    VAR(uint16, ETH_VAR) VlanId;           /** @brief Specifies the VLAN address 0..65535 */
    VAR(uint8, ETH_VAR) SwitchPort;        /** @brief Port of the switch 0..255 */
    VAR(uint16, ETH_VAR) HashValue;        /** @brief Hash value that is generated by the Ethernet switch according the given
                                             * MacAddr. If the HashValue is not available the value shall be set to
                                             * 0b1111xxxxxxxxxxxx == 0xFxxx (invalid value). If the HashValue is available the
                                             * value shall be set to 0b0000xxxxxxxxxxxx == 0x0xxx (valid value) */
} Eth_MacVlanType;

/**
* @brief        EthSwt_MgmtInfoType type definition
* @details      Type for holding the management information received/transmitted on Switches (ports)
* @implements   EthSwt_MgmtInfo_type
*/
typedef struct
{
    VAR(uint8, ETH_VAR) SwitchIdx;        /** @brief Specifies Switch index */
    VAR(uint16, ETH_VAR) SwitchPortIdx;   /** @brief Specifies Port index of the switch */
} EthSwt_MgmtInfoType;





 
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* ETH_GENERALTYPES_H */
/** @} */
