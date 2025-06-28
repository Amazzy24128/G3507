#include "my_uwtick.h"
volatile uint64_t uwtick = 0;
uint32_t get_tick(void)
{
    return uwtick;
}

uint8_t tick_proc(void)
{
    uwtick++;
    return 0;
}



void SysTick_Handler(void) // 1ms
{
    tick_proc();
}

