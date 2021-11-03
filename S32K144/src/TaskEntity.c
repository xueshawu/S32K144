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
#include "CanTp.h"
#include "Dcm.h"
#include "Dem.h"
#include "Fls.h"
#include "NvM.h"
#include "TaskEntity.h"


static uint32 g_task1RunngingCnt = 0;
static uint32 g_task2RunnnigCnt = 0;
static uint32 g_task_Bsw_5Ms_RunningCnt = 0;
static uint32 g_task_Bsw_10MS_RnningCnt = 0;
TASK(SystemInitTask)
{
    g_task1RunngingCnt++;
    TerminateTask();
}


/* This Task run per 5ms */
TASK(Task2)
{
    EventMaskType eventMask;
    (void)WaitEvent(TASK2_ScheduledEvent_10Ms);
    (void)GetEvent(Task2, &eventMask);
    (void)ClearEvent(eventMask&(TASK2_ScheduledEvent_10Ms));
    for(;;)
    {
        g_task2RunnnigCnt++;
        CanTp_MainFunction();
        Dcm_MainFunction();
        Dem_MainFunction();
        TerminateTask();
    }

}

TASK(Task_Bsw_5Ms)
{
    CanTp_MainFunction();
    Fls_MainFunction();
    Fee_MainFunction();
    NvM_MainFunction();
    g_task_Bsw_5Ms_RunningCnt++;
    TerminateTask();
}


TASK(Task_Bsw_10Ms)
{

	g_task_Bsw_10MS_RnningCnt++;
    TerminateTask();
}

