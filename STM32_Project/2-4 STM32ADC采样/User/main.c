#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "ADC.h"
uint16_t voltage;
int main(void)
{
		
    OLED_Init();
		OLED_Clear();
		adc_Init();
		OLED_ShowString(0,0,"adcValue:",8);
		OLED_ShowString(0,20,"voltage:",8);
		OLED_ShowString(65,20,"0.00V",8);
    while(1)
    {
			 voltage = (uint16_t)((float)ADC_GetValue()*100/4095*3.3)/100;
       OLED_ShowNum(70,0,ADC_GetValue(),5,8);
			 OLED_ShowNum(65,20,voltage,1,8);
			voltage = (uint16_t)((float)ADC_GetValue()*100/4095*3.3)%100;
			 OLED_ShowNum(81,20,voltage,2,8);
			 OLED_Update();
    }  
}
