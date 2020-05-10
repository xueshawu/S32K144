/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Archie
 * @Date: 2020-04-11 15:43:56
 * @LastEditors: Archie
 * @LastEditTime: 2020-05-10 16:26:35
 */

#include "Mcu.h"
#include "Port.h"
#include "Gpt.h"
#include "Os.h"

#define	IDLE_CNT_MAX	100000U

OsEE_bool volatile stk_wrong = OSEE_FALSE;
OsEE_addr volatile old_sp;
uint32_t volatile idle_cnt;
void ErrorHook(StatusType Error)
{
  return;
} 


void idle_hook(void)
{
	++idle_cnt;
	if (idle_cnt >= IDLE_CNT_MAX) {
		idle_cnt = 0;
		ActivateTask(Task1);
	}
}

void StartupHook(void)
{
  
}


int main(void) 
{
  Mcu_Init(&McuModuleConfiguration);
  Mcu_InitClock(0);
  Port_Init(&PortConfigSet);
 // Gpt_Init(&GptChannelConfigSet);
  //Gpt_StartTimer(GptChannelConfiguration_FTM0_CH0, 500);
 #if (defined(OSEE_API_DYNAMIC))
  InitOS();
  
  CreateTask( &Task1, OSEE_TASK_TYPE_EXTENDED, TASK_FUNC(Task1),
      1U, 1U, 1U, 512U );
  CreateTask( &Task2, OSEE_TASK_TYPE_BASIC, TASK_FUNC(Task2),
      2U, 2U, 1U, 512U );
  CreateTask( &IsrTimerId, OSEE_TASK_TYPE_ISR2, TimerISR,
      1U, 1U, 1U, OSEE_SYSTEM_STACK );
  CreateTask( &IsrButtonsId, OSEE_TASK_TYPE_ISR2, ButtonsISR,
      1U, 1U, 1U, OSEE_SYSTEM_STACK );

  /* Prio settate a 1 dalla BSP all'avvio */
  SetISR2Source(IsrTimerId, TIMER_ISR_ID);
  SetISR2Source(IsrButtonsId, BUTTONS_ISR_ID);

  SetIdleHook(idle_hook);
#endif /* OSEE_API_DYNAMIC */ 
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}
