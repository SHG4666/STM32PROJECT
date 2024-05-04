#ifndef __PWM_H__
#define __PWM_H__
#include "stm32f10x.h"                  // Device header
void PWM_Init();
void PWM_SetCompare1(float Angle);
#endif
