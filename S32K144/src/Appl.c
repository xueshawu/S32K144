/*
 * hello.c              Copyright NXP 2016
 * Description:  Simple program to exercise GPIO
 * 2015 Mar 31 S Mihalik/ O Romero - initial version
 *
 */

#include "S32K144.h"    /* include peripheral declarations S32K144 */

#define PTD0  0         /* Port PTD0, bit 0: FRDM EVB output to blue LED */
#define PTC12 12        /* Port PTC12, bit 12: FRDM EVB input from BTN0 [SW2] */

void WDOG_disable (void){
  WDOG->CNT=0xD928C520;    /*Unlock watchdog*/
  WDOG->TOVAL=0x0000FFFF;  /*Maximum timeout value*/
  WDOG->CS = 0x00002100;   /*Disable watchdog*/
}

int main(void) {
  int counter = 0;
  WDOG_disable();             /* Disable Watchdog in case it is not done in startup code */
                              /* Enable clocks to peripherals (PORT modules) */
  PCC-> PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock to PORT C */
  PCC-> PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock to PORT D */
                               /* Configure port C12 as GPIO input (BTN 0 [SW2] on EVB) */
  PTC->PDDR &= ~(1<<PTC12);    /* Port C12: Data Direction= input (default) */
  PORTC->PCR[12] = 0x00000110; /* Port C12: MUX = GPIO, input filter enabled */
                               /* Configure port D0 as GPIO output (LED on EVB) */
  PTD->PDDR |= 1<<PTD0;        /* Port D0: Data Direction= output */
  PORTD->PCR[0] = 0x00000100;  /* Port D0: MUX = GPIO */

  for(;;) {
    if (PTC->PDIR & (1<<PTC12)) {   /* If Pad Data Input = 1 (BTN0 [SW2] pushed) */
      PTD-> PCOR |= 1<<PTD0;        /* Clear Output on port D0 (LED on) */
    }
    else {                          /* If BTN0 was not pushed */
      PTD-> PSOR |= 1<<PTD0;        /* Set Output on port D0 (LED off) */
    }
    counter++;
  }
}
