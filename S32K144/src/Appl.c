/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Archie
 * @Date: 2020-04-11 15:43:56
 * @LastEditors: Archie
 * @LastEditTime: 2020-04-19 14:01:02
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
//#include "ee_cortex_m_irq.h" /*因为MCAL的compiler.h头文件的问题，因此如果要包含os相关的，必须放在MCAL的头文件之后 */

void ErrorHook(StatusType Error)
{
  return;
} 


void idle_hook (void)
{

}



int main(void) 
{
  Dio_LevelType led_blue = STD_LOW;
  Mcu_Init(&McuModuleConfiguration);
  Mcu_InitClock(0);
  Port_Init(&PortConfigSet);
  
  Dio_WriteChannel(DioConf_DioChannel_Dio_Rgb_Green,led_blue);
  for(;;) 
  {
  }
}
