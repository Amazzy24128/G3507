/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "my_uwtick.h"
#include "ti_msp_dl_config.h"

#include "my_scheduler.h"
#include "my_uart.h"
// 串口的中断服务函数

int main(void) {
  SYSCFG_DL_init();
  // 清除串口中断标志
  NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
  // 使能串口中断
  NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
  while (1) {
    uart0_printf("now time is %d\n",get_tick());
    scheduler_run();
  }
}

void UART_0_INST_IRQHandler(void) {
  // 如果产生了串口中断
  switch (DL_UART_getPendingInterrupt(UART_0_INST)) {
  case DL_UART_IIDX_RX: // 如果是接收中断
    // 将发送过来的数据保存在变量中
    uart_data = DL_UART_Main_receiveData(UART_0_INST);
    // 将保存的数据再发送出去
    uart0_send_char(uart_data);
    break;

  default: // 其他的串口中断
    break;
  }
}
