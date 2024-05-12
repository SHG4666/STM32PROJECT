#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Encoder.h"
#include "Delay.h"
int main(void)
{
    OLED_Init();
		Encoder_Init();
		OLED_Clear();
    while(1)
    {
       OLED_ShowSignedNum(1,2,Encoder_GetCounter(),5);
			 Delay_ms(100);
    }  
}
