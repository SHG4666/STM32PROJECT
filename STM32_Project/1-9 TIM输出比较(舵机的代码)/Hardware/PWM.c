#include "stm32f10x.h"                  // Device header

void PWM_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode =GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin =GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);
    
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_OCInitStructure.TIM_OCIdleState =TIM_OCIdleState_Set;
    TIM_OCInitStructure.TIM_OCMode =TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OCNIdleState =TIM_OCIdleState_Set;
    TIM_OCInitStructure.TIM_OCNPolarity =TIM_OCNPolarity_High;
    TIM_OCInitStructure.TIM_OutputNState =TIM_OutputNState_Enable;
    TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse=0;
    TIM_OC2Init(TIM3,&TIM_OCInitStructure);
    
    TIM_InternalClockConfig(TIM3);
    
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStructuer;
    TIM_TimeBaseInitStructuer.TIM_ClockDivision =TIM_CKD_DIV1;
    TIM_TimeBaseInitStructuer.TIM_CounterMode=TIM_CounterMode_Up;
    TIM_TimeBaseInitStructuer.TIM_Period=20000-1;
    TIM_TimeBaseInitStructuer.TIM_Prescaler = 72-1;
    TIM_TimeBaseInitStructuer.TIM_RepetitionCounter =0;
    TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructuer);
    
    NVIC_InitTypeDef  NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel =TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority =1;
    NVIC_Init(&NVIC_InitStructure);
    
    TIM_Cmd(TIM3, ENABLE);
}

void PWM_SetCompare1(float Angle)
{
    TIM_SetCompare2(TIM3,Angle);
}