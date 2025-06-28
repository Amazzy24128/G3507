#ifndef __MYT_SCHDULER_H__
#define __MYT_SCHDULER_H__

#include "ti_msp_dl_config.h"
#include "my_led.h"
#include "key.h"
typedef struct {
  void (*task_func)(void);
  uint32_t rate_ms;
  uint32_t last_run;
} scheduler_task_t;

void scheduler_run(void);




#endif
