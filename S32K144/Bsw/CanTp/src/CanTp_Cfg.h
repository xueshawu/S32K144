#ifndef CANTP_CFG_H_
#define CANTP_CFG_H_

#include "CanTp_Types.h"


#define CANTP_NSDU_CONFIG_LIST_SIZE		4
#define CANTP_NSDU_RUNTIME_LIST_SIZE	4

#define CANTP_RXID_LIST_SIZE			2

#define CANTP_MAIN_FUNCTION_PERIOD_TIME_MS		5

#define CANTP_CONVERT_MS_TO_MAIN_CYCLES(x)		((x)/CANTP_MAIN_FUNCTION_PERIOD_TIME_MS)


#define CANTP_ID_UdsPhyReq_Rx				(0U)
#define CANTP_ID_UdsFunReq_Rx				(1U)

#define CanTpConf_CanTpTxNPdu_CanTpTxNPdu_udstx					(0U)


extern const CanTp_ConfigType CanTpConfig;
extern const CanTp_NSduType CanTpNSduConfigList[];
extern const CanTp_RxIdType CanTp_RxIdList[];






#endif
