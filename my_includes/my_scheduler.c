#include "my_scheduler.h"

static scheduler_task_t tasks[] = {
    {key_proc, 50, 0},
    {toggle_led_proc, 200, 0},
    {PWM_proc, 10, 0}
};

uint16_t task_count = sizeof(tasks) / sizeof(tasks[0]);

void scheduler_run(void) {
    uint32_t now = get_tick();
    for (uint16_t i = 0; i < task_count; i++) {
        if (now >= tasks[i].rate_ms + tasks[i].last_run) {
            tasks[i].last_run = now; 
            tasks[i].task_func();
        }
    }
}

