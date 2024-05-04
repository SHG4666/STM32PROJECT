#include "stm32f10x.h"                  // Device header
#include "MyI2C.h"
#include "OLED.h"

extern uint8_t OLED_F8x16[][16];
extern uint8_t OLEDDispalyBuffer[8][128]; 
int main(void)
{
    OLED_Init();
    OLED_Clear();
    OLED_ShowString(0,0,"fseffe",6);
    OLED_Update();
    while(1)
    {
       
    }  
}
