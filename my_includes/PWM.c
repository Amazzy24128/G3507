#include "PWM.h"
uint16_t now_cmp = 1;
void PWM0_setcmp(uint16_t cmp) // 设置比较寄存器 
{
    DL_TimerG_setCaptureCompareValue(PWM_0_INST, cmp,GPIO_PWM_0_C0_IDX ); // 定时器 比较值 PWM通道
}

void PWM_proc(void)
{
    now_cmp ++ ;
    if(now_cmp > 1000)
    {
        now_cmp = 0;
    }
    PWM0_setcmp(now_cmp);
}