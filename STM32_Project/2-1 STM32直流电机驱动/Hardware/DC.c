#include "DC.h"                  // Device header

void DC_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin =GPIO_Pin_5 |GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
    GPIO_Init(GPIOF, &GPIO_InitStructure);
    GPIO_SetBits(GPIOF,GPIO_Pin_7);
    
    GPIO_InitStructure.GPIO_Mode =GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin =GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    TIM_InternalClockConfig(TIM4);
    
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_ClockDivision =TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode =TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_Period =100-1;
    TIM_TimeBaseInitStructure.TIM_Prescaler =36 -1;
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter =0;
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStructure);
    
    TIM_OCInitTypeDef TIM_OCInitStructure;
    TIM_OCStructInit(&TIM_OCInitStructure);
    TIM_OCInitStructure.TIM_OCMode =TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OCPolarity =TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_OutputState =TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse=15;
    TIM_OC2Init(TIM4, &TIM_OCInitStructure);
       
    TIM_Cmd(TIM4, ENABLE);
}


