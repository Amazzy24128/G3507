#include "my_led.h"

void toggle_led_proc()
{

    DL_GPIO_togglePins(LED1_PORT, LED1_PIN_22_PIN);

}



