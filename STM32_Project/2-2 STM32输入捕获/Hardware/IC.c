#include "IC.h"

uint32_t 	CaptureNum;
void IC_Init()
{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
		
		GPIO_InitTypeDef	GPIO_InitStructure;
		GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Pin =GPIO_Pin_7;
		GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
		TIM_InternalClockConfig(TIM4);
		
		TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
		TIM_TimeBaseInitStructure.TIM_ClockDivision =TIM_CKD_DIV1;
		TIM_TimeBaseInitStructure.TIM_CounterMode =TIM_CounterMode_Up;
		TIM_TimeBaseInitStructure.TIM_Period =65536-1;
		TIM_TimeBaseInitStructure.TIM_Prescaler =72 -1;
		TIM_TimeBaseInitStructure.TIM_RepetitionCounter =0;
		TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStructure);
		
		TIM_ICInitTypeDef	TIM_ICInitStructure;
		TIM_ICInitStructure.TIM_Channel =TIM_Channel_2;
		TIM_ICInitStructure.TIM_ICFilter =0xF;
		TIM_ICInitStructure.TIM_ICPolarity =TIM_ICPolarity_Rising;
		TIM_ICInitStructure.TIM_ICPrescaler =TIM_ICPSC_DIV1;
		TIM_ICInitStructure.TIM_ICSelection=TIM_ICSelection_DirectTI;
		TIM_ICInit(TIM4,&TIM_ICInitStructure);
		
		/*这是一种写法*/
//		TIM_ICInitStructure.TIM_Channel =TIM_Channel_1;
//		TIM_ICInitStructure.TIM_ICFilter =0xF;
//		TIM_ICInitStructure.TIM_ICPolarity =TIM_ICPolarity_BothEdge;
//		TIM_ICInitStructure.TIM_ICPrescaler =TIM_ICPSC_DIV1;
//		TIM_ICInitStructure.TIM_ICSelection=TIM_ICSelection_IndirectTI;
//		TIM_ICInit(TIM4,&TIM_ICInitStructure);
		TIM_PWMIConfig(TIM4,&TIM_ICInitStructure);
		TIM_SelectInputTrigger(TIM4,TIM_TS_TI2FP2);
		TIM_SelectSlaveMode(TIM4,TIM_SlaveMode_Reset);
		
		TIM_Cmd(TIM4,ENABLE);
}

uint32_t getFreq()
{
	CaptureNum =TIM_GetCapture2(TIM4);
	return 1000000/CaptureNum;
}

uint32_t getDuty()
{
	return TIM_GetCapture1(TIM4)*100/TIM_GetCapture2(TIM4);
}