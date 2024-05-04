#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "DC.h"
int main(void)
{
    OLED_Init();
    DC_Init();
    OLED_ShowString(0,0,"kkdas",8);
    OLED_Update();
    while(1)
    {
       
    }  
}
