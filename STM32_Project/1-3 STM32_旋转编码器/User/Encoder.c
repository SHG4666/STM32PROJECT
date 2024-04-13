#include "stm32f10x.h"                  // Device header


void Encoder_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
    
    GPIO_InitTypeDef  GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin =GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
    GPIO_Init(GPIOC,&GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin =GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&GPIO_InitStructure);
    
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource3);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource13);
    
    EXTI_InitTypeDef EXTI_InitStructure;
    EXTI_InitStructure.EXTI_Line =EXTI_Line3;
    EXTI_InitStructure.EXTI_LineCmd =ENABLE;
    EXTI_InitStructure.EXTI_Mode =EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger =EXTI_Trigger_Falling;
    EXTI_Init(&EXTI_InitStructure);
    
    EXTI_InitStructure.EXTI_Line =EXTI_Line13;
    EXTI_InitStructure.EXTI_LineCmd =ENABLE;
    EXTI_InitStructure.EXTI_Mode =EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger =EXTI_Trigger_Falling;
    EXTI_Init(&EXTI_InitStructure);
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    NVIC_InitTypeDef  NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel =EXTI3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority =1;
    NVIC_Init(&NVIC_InitStructure);  
    
    NVIC_InitStructure.NVIC_IRQChannel =EXTI15_10_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority =1;
    NVIC_Init(&NVIC_InitStructure);  
}

void EXTI3_IRQHandler()
{
    if(EXTI_GetITStatus(EXTI_Line3) == SET)
    {
        if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)==RESET)
        {
            GPIO_SetBits(GPIOB,GPIO_Pin_5);
            GPIO_ResetBits(GPIOE,GPIO_Pin_5);
        }
        EXTI_ClearITPendingBit(EXTI_Line3);
    }
}

void EXTI15_10_IRQHandler()
{
    if(EXTI_GetITStatus(EXTI_Line13) == SET)
    {
        if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3)==RESET)
        {
            GPIO_SetBits(GPIOE,GPIO_Pin_5);
            GPIO_ResetBits(GPIOB,GPIO_Pin_5);
        }
        EXTI_ClearITPendingBit(EXTI_Line13);
    }
}
