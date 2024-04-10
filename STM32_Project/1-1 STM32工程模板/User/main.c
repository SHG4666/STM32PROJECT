#include "stm32f10x.h"                  // Device header
#include "MH_Sensor.h"
#include "RED_LED.h"
int main(void)
{
    Sensor_Init();
    RED_LED_Init();
    while(1)
    {
       if(Led_Status_Flag)
       {
           GPIO_SetBits(GPIOE,GPIO_Pin_5);
       }
       else
       {
           GPIO_ResetBits(GPIOE,GPIO_Pin_5);
       } 
    }  
}
