/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Archie
 * @Date: 2020-04-11 15:43:56
 * @LastEditors: Archie
 * @LastEditTime: 2020-04-22 22:10:09
 */
/*
 * hello.c              Copyright NXP 2016
 * Description:  Simple program to exercise GPIO
 * 2015 Mar 31 S Mihalik/ O Romero - initial version
 *
 */

#include "S32K144.h"    /* include peripheral declarations S32K144 */
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
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
