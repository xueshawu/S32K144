/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Archie
 * @Date: 2020-04-11 15:43:56
 * @LastEditors: Archie
 * @LastEditTime: 2020-04-11 20:11:46
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

#define PTD0  0         /* Port PTD0, bit 0: FRDM EVB output to blue LED */
#define PTC12 12        /* Port PTC12, bit 12: FRDM EVB input from BTN0 [SW2] */

static void WDOG_disable (void)
{
  WDOG->CNT=0xD928C520;    /*Unlock watchdog*/
  WDOG->TOVAL=0x0000FFFF;  /*Maximum timeout value*/
  WDOG->CS = 0x00002100;   /*Disable watchdog*/
}

int main(void) {
  int counter = 0;
  WDOG_disable();             /* Disable Watchdog in case it is not done in startup code */
                              /* Enable clocks to peripherals (PORT modules) */
  Mcu_Init(&McuModuleConfiguration);
  Mcu_InitClock(0);
  Port_Init(&PortConfigSet);

  for(;;) {
    if (Dio_ReadChannel(DioConf_DioChannel_Dio_Key1) == STD_HIGH) {   /* If Pad Data Input = 1 (BTN0 [SW2] pushed) */
      Dio_WriteChannel(DioConf_DioChannel_Dio_Rgb_Green, STD_LOW); 
    }
    else {                          /* If BTN0 was not pushed */
        Dio_WriteChannel(DioConf_DioChannel_Dio_Rgb_Green, STD_HIGH); 
    }
    counter++;
  }
}
