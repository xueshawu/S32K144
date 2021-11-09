/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Archie
 * @Date: 2020-04-19 14:17:07
 * @LastEditors: Archie
 * @LastEditTime: 2020-05-10 11:56:37
 */
#include "InterruptServices.h"
#include "Std_Types.h"

static uint8 g_Wdog_InterruptCnt=0;
void WDOG_EWM_IRQHandler(void)
{
    g_Wdog_InterruptCnt++;
}


void TestISR(void)
{

}


ISR2(ButtonsISR)
{
    
}

ISR2(TimerISR)
{
    
}

