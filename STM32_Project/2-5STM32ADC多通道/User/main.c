#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "ADC.h"
uint16_t voltage;
int main(void)
{
		
    OLED_Init();
		OLED_Clear();
		adc_Init();
		OLED_ShowString(0,0,"adcValue:",6);
		OLED_ShowString(0,15,"ADC2:",6);
		OLED_ShowString(0,30,"ADC3:",6);
		OLED_ShowString(0,45,"ADC4:",6);
    while(1)
    {  
       OLED_ShowNum(70,0,ADC_GetValue(14),5,6);
			 OLED_ShowNum(70,15,ADC_GetValue(10),5,6);
			 OLED_ShowNum(70,30,ADC_GetValue(11),5,6);
			 OLED_ShowNum(70,45,ADC_GetValue(12),5,6);
			 OLED_Update();
    }  
}
