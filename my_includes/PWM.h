#ifndef __PWN_C__
#define __PWN_C__

#include "ti_msp_dl_config.h"
void PWM0_setcmp(uint16_t cmp) ;
void PWM_proc(void);
extern uint16_t now_cmp;
#endif 
