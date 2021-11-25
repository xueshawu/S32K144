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
#include "CanIf.h"
#include "Os.h"
#include "Fls.h"
#include "Fee.h"
#include "NvM.h"

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
#define READALL_TIMEOUT_MAX       500
    static uint16 NvM_ReadAll_WaitCnt = 0;
    NvM_RequestResultType eReadAllRequestResult = NVM_REQ_PENDING;
#if 0    
    NvM_ReadAll();
    do
    {
      Fls_MainFunction();
      Fee_MainFunction();
      NvM_MainFunction();
      NvM_GetErrorStatus(NVM_BLOCK_ID_Admin, &eReadAllRequestResult);
      NvM_ReadAll_WaitCnt++;
    } while ((eReadAllRequestResult == NVM_REQ_PENDING) && (NvM_ReadAll_WaitCnt < READALL_TIMEOUT_MAX));
#endif    

}

void ShutdownHook(StatusType Error)
{
#define WRITEALL_TIMEOUT_MAX       1000
    static uint16 NvM_WriteAll_WaitCnt = 0;
    NvM_RequestResultType eWriteAllRequestResult = NVM_REQ_PENDING;
    NvM_WriteAll();
    do
    {
      Fls_MainFunction();
      Fee_MainFunction();
      NvM_MainFunction();
      NvM_GetErrorStatus(NVM_BLOCK_ID_Admin, &eWriteAllRequestResult);
      NvM_WriteAll_WaitCnt++;
    } while ((eWriteAllRequestResult == NVM_REQ_PENDING) && (NvM_WriteAll_WaitCnt < WRITEALL_TIMEOUT_MAX));
}


volatile uint8 *pMCR_RegisterPtr = (uint8 *)(0x40024000);
volatile uint32 MCR_RegisterVal = 0;

int main(void) 
{
  #if 0
  SOSC_init_8MHz();       /* Initialize system oscillator for 8 MHz xtal */
  SPLL_init_160MHz();     /* Initialize SPLL to 160 MHz with 8 MHz SOSC */
  NormalRUNmode_80MHz();  /* Init clocks: 80 MHz sysclk & core, 40 MHz bus, 20 MHz flash */
#endif
  
  Mcu_Init(&McuModuleConfiguration);
  Mcu_InitClock(McuClockSettingConfig_0);
  while (MCU_PLL_LOCKED != Mcu_GetPllStatus())
  {

  }
  Mcu_DistributePllClock();
  Port_Init(&PortConfigSet);
  Can_Init(&CanConfigSet);
  Fls_Init(&FlsConfigSet);
  CanIf_Init(NULL_PTR);
  Fee_Init(NULL_PTR);
  NvM_Init();
  MCR_RegisterVal = *pMCR_RegisterPtr;
  Can_SetControllerMode(CanConf_CanController_CanController_0, CAN_CS_STARTED);
  CanIf_SetPduMode(CanConf_CanController_CanController_0, CANIF_SET_ONLINE);
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}
