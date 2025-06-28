#ifndef __MY_UART__
#define __MY_UART__

#include "ti_msp_dl_config.h"
#include "string.h"
#include "stdarg.h"
#include "stdio.h"
void uart0_send_char(char ch);
void uart0_send_string(char *str);
void uart0_printf(char* format, ...);
extern volatile unsigned char uart_data;



#endif
