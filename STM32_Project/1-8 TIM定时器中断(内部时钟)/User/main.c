#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "TIMInterrupt.h"
uint16_t num;
int main(void)
{
     
    OLED_Init();
    TIM_Init();
    OLED_Clear();
    OLED_ShowString(0,0,"NUM:",8);
    OLED_ShowString(0,30,"CNT:",8);
//    OLED_Update();
    while(1)
    {
       OLED_ShowNum(40,0,num,5,8);
       OLED_ShowNum(40,30,TIM_GetTimNum(),5,8);
       OLED_Update();
    }  
}

void TIM3_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM3,TIM_IT_Update)!=RESET)
    {
        num++;
        TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
    }
}