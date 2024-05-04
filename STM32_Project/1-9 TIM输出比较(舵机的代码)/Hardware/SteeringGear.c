#include "stm32f10x.h"                  // Device header
#include "PWM.h"
void StreeringGear_Init()
{
    PWM_Init();
}

void StreeringGear(float Angle)
{
    PWM_SetCompare1(Angle/180*2000+500);
}

