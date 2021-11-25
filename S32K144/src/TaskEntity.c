/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Archie
 * @Date: 2020-04-19 14:28:17
 * @LastEditors: Archie
 * @LastEditTime: 2020-05-19 10:53:37
 */
/*因为数据类型定义的问题，MCAL相关的头文件必须在OS的头文件之前包含 */
#include "Dio.h"
#include "Can.h"
#include "CanTp.h"
#include "Dcm.h"
#include "Dem.h"
#include "Fls.h"
#include "NvM.h"
#include "CanIf.h"
#include "IoHwAb_Dio.h"
#include "TaskEntity.h"


static uint32 g_task1RunngingCnt = 0;
static uint32 g_task_Asw_5Ms_RunningCnt = 0;
static uint32 g_task_Bsw_5Ms_RunningCnt = 0;
static uint32 g_task_Bsw_10MS_RnningCnt = 0;
static uint32 g_task_Bsw_100Ms_RunningCnt = 0;
TASK(SystemInitTask)
{
    g_task1RunngingCnt++;
    TerminateTask();
}


extern void NvM_TestMainFunction(void);

TASK(Task_Bsw_100Ms)
{
	g_task_Bsw_100Ms_RunningCnt++;
    IoHwAb_Dio_MainFunction();
   // NvM_TestMainFunction();
    TerminateTask();
}

/* This Task run per 5ms */
TASK(Task_Asw_5Ms)
{
	g_task_Asw_5Ms_RunningCnt++;
    CanTp_MainFunction();
    Dcm_MainFunction();
    Dem_MainFunction();
    TerminateTask();

}

uint8 txMessageBuff[8] = {1,2,3,4,5,6,7,8};
PduInfoType txPduInfo = 
{
    .SduDataPtr = txMessageBuff,
    .SduLength = 0x8
};

TASK(Task_Bsw_5Ms)
{
    CanTp_MainFunction();
    Fls_MainFunction();
    CanIf_Transmit(CanIfConf_CanIfTxPduCfg_CanIfTxPduCfg_uds_tx, &txPduInfo);
   // Fee_MainFunction();
   // NvM_MainFunction();
    g_task_Bsw_5Ms_RunningCnt++;
    TerminateTask();
}


TASK(Task_Bsw_10Ms)
{

	g_task_Bsw_10MS_RnningCnt++;
    TerminateTask();
}

