#include "stm32f10x.h"                  // Device header
#include "RED_GREEN_LED.h"
#include "Encoder.h"
int main(void)
{
    RED_LED_Init();
    Encoder_Init();
    while(1)
    {
       
    }  
}
