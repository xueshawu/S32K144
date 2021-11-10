/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Archie
 * @Date: 2020-04-11 15:43:56
 * @LastEditors: Archie
 * @LastEditTime: 2020-05-16 09:53:53
 */

#include "Mcu.h"
#include "Port.h"
#include "Gpt.h"
#include "Can.h"
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
}

void StartupHook(void)
{
    Can_Init(&CanConfigSet);
}

void ShutdownHook(StatusType Error)
{

}


int main(void) 
{
  Mcu_Init(&McuModuleConfiguration);
  Mcu_InitClock(0);
  Port_Init(&PortConfigSet);
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}
