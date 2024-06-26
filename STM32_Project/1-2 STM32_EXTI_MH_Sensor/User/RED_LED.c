#include "stm32f10x.h"                  // Device header


void RED_LED_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin =GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
    GPIO_Init(GPIOE,&GPIO_InitStructure);
    GPIO_SetBits(GPIOE,GPIO_Pin_5);
}
