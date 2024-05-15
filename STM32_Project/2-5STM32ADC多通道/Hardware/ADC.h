#ifndef __ADC_H__
#define __ADC_H__
#include "stm32f10x.h"                  // Device header
uint16_t ADC_GetValue(uint8_t ADC_Channel);
void adc_Init(void);
#endif