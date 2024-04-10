#include "stm32f10x.h"                  // Device header

uint8_t Led_Status_Flag =0;
void Sensor_Init()
{ 
    /**RCC使能**/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
    /**GPIO口配置**/
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin =GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
    GPIO_Init(GPIOC,&GPIO_InitStructure);
    
    /**将GPIO的线和AFIO相连**/
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource3);
    
    EXTI_InitTypeDef EXTI_InitStructure;
    EXTI_InitStructure.EXTI_Line =EXTI_Line3;
    EXTI_InitStructure.EXTI_LineCmd =ENABLE;
    EXTI_InitStructure.EXTI_Mode =EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger =EXTI_Trigger_Falling;
    EXTI_Init(&EXTI_InitStructure);
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel =EXTI3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority =1;
    NVIC_Init(&NVIC_InitStructure);}

    void EXTI3_IRQHandler()
    {
        if(EXTI_GetITStatus(EXTI_Line3) == SET)
        {
            Led_Status_Flag =~Led_Status_Flag;
            EXTI_ClearITPendingBit(EXTI_Line3);
       }
    }
