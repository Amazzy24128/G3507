#ifndef __MY_UWTICK_H__
#define __MY_UWTICK_H__

#include "ti_msp_dl_config.h"


extern volatile uint64_t uwtick; 

uint32_t get_tick(void);
void SysTick_Handler(void);


#endif

