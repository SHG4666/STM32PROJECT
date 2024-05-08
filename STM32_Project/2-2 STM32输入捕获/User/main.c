#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "IC.h"
#include "PWM.h"
int main(void)
{
		OLED_Init();
    PWM_Init();
		IC_Init();
//		OLED_ShowNum(0,0,getFreq(),5,8);
		PWM_SetPrescaler(720 - 1);			//Freq = 72M / (PSC + 1) / 100
		PWM_SetCompare1(50);				//Duty = CCR / 100
    while(1)
    {
      OLED_ShowNum(0,0,getFreq(),5,8);
			OLED_ShowNum(0,30,getDuty(),5,8);
			OLED_Update();
    }  
}
