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
#include "TaskEntity.h"


static uint32 g_task1RunngingCnt = 0;
TASK(SystemInitTask)
{
    g_task1RunngingCnt++;
    TerminateTask();
}

static uint32 g_taks2RunnnigCnt = 0;

TASK(Task2)
{
    EventMaskType eventMask;
    for(;;)
    {
        (void)WaitEvent(TASK2_ScheduledEvent_10Ms);
        (void)GetEvent(Task2, &eventMask);
        (void)ClearEvent(eventMask&(TASK2_ScheduledEvent_10Ms)); 
        g_taks2RunnnigCnt++;
    }
    TerminateTask();
}
