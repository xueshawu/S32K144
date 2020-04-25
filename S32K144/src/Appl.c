/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Archie
 * @Date: 2020-04-11 15:43:56
 * @LastEditors: Archie
 * @LastEditTime: 2020-04-25 11:14:50
 */

#include "S32K144.h"    /* include peripheral declarations S32K144 */
#include "Mcu.h"
#include "Port.h"
#include "Os.h"
void ErrorHook(StatusType Error)
{
  return;
} 


void idle_hook (void)
{

}

void StartupHook(void)
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
