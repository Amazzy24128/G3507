#include "key.h"

uint8_t key_val = 0;
uint8_t key_old = 0;
uint8_t key_down = 0;
uint8_t key_up = 0;
uint8_t key_read(void)
{
    uint8_t temp = 0;

    if (DL_GPIO_readPins(KEY1_PORT,KEY1_PIN_18_PIN) > 0)
    {
        temp = 1;
    }

    return temp;
}






void key1_return(void)
{
    DL_GPIO_togglePins(LED1_PORT,LED1_PIN_22_PIN);
}

void key_proc(void)
{
    key_val = key_read();
    key_down = key_val & (key_old ^ key_val);
    key_up = ~key_val & (key_old ^ key_val);
    key_old = key_val;


    if (key_up == 1)
    {
        key1_return();
    }
}