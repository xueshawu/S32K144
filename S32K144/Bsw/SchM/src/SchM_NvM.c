/*
 * SchM_NvM.c
 *
 *  Created on: 2020-12-16
 *      Author: nieqi
 */
#include "SchM_NvM.h"
#include "Os.h"

void Irq_Save(void)
{
	DisableAllInterrupts();
}
void Irq_Restore(void)
{
	EnableAllInterrupts();
}
