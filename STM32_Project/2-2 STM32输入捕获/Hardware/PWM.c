#include "PWM.h"


void PWM_Init()
{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	  
		GPIO_InitTypeDef	GPIO_InitStructure;
	  GPIO_InitStructure.GPIO_Mode =GPIO_Mode_AF_PP;
	  GPIO_InitStructure.GPIO_Pin =GPIO_Pin_6;
	  GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	  
	  TIM_InternalClockConfig(TIM3);
	
		TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
		TIM_TimeBaseInitStructure.TIM_ClockDivision =TIM_CKD_DIV1;
		TIM_TimeBaseInitStructure.TIM_CounterMode =TIM_CounterMode_Up;
		TIM_TimeBaseInitStructure.TIM_Period =100;
		TIM_TimeBaseInitStructure.TIM_Prescaler =72 -1;
		TIM_TimeBaseInitStructure.TIM_RepetitionCounter =0;
		TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
		
		TIM_OCInitTypeDef	TIM_OCInitStructure;
		TIM_OCStructInit(&TIM_OCInitStructure);
		TIM_OCInitStructure.TIM_OCMode =TIM_OCMode_PWM1;
		TIM_OCInitStructure.TIM_OCPolarity =TIM_OCPolarity_High;
		TIM_OCInitStructure.TIM_OutputState =TIM_OutputState_Enable;
		TIM_OCInitStructure.TIM_Pulse =0;
	  TIM_OC1Init(TIM3, &TIM_OCInitStructure);
		
	  TIM_Cmd(TIM3, ENABLE);
}

void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(TIM3, Compare);
}

void PWM_SetPrescaler(uint16_t Prescaler)
{
	TIM_PrescalerConfig(TIM3, Prescaler, TIM_PSCReloadMode_Immediate);
}