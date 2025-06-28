#include "my_uwtick.h"

volatile uint64_t uwtick = 0;

uint32_t get_tick(void)
{
    return uwtick;
}

// SysTick 每 1ms 中断一次
void SysTick_Handler(void)
{
    uwtick++;
}

// 毫秒延迟函数
void delay_ms(uint32_t ms)
{
    //工程中的主频默认是32MHz，如果有修改请使用修改后的主频
    while (ms--)
    {
        delay_cycles(32000);
    }
}

// 延时函数，延时 us 微秒
void delay_us(uint32_t us)
{

    //工程中的主频默认是32MHz，如果有修改请使用修改后的主频
    while (us--)
    {
        delay_cycles(32);
    }
}