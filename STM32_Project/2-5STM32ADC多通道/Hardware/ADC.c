#include "ADC.h"


void adc_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	GPIO_InitTypeDef	GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_AIN;
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	ADC_InitTypeDef ADC_InitStructure;

	ADC_InitStructure.ADC_ContinuousConvMode =DISABLE;
	ADC_InitStructure.ADC_DataAlign =ADC_DataAlign_Right;
	ADC_InitStructure.ADC_ExternalTrigConv =ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_Mode =ADC_Mode_Independent;
	ADC_InitStructure.ADC_NbrOfChannel =1;
	ADC_InitStructure.ADC_ScanConvMode =DISABLE;
	ADC_Init(ADC1, &ADC_InitStructure);
	
	ADC_Cmd(ADC1, ENABLE);
	
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1));
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1));
}

uint16_t ADC_GetValue(uint8_t ADC_Channel)
{
	ADC_RegularChannelConfig(ADC1, ADC_Channel, 1, ADC_SampleTime_55Cycles5);
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);//单次转换放这里
	while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));//单词转换放这里
	return ADC_GetConversionValue(ADC1);
}