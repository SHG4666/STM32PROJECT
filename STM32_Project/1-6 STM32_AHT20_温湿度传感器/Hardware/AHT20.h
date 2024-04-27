#ifndef __AHT20_H__
#define __AHT20_H__
#include "stm32f10x.h"                  // Device header

float AHT20_Function(float* tempature,float* humi);
void AHT20_Init();
#endif