#include "USART.H"
uint8_t Receive_Data_Flag;
uint8_t Receive_Data;
void usart_init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	
	GPIO_InitTypeDef	GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate =115200;
	USART_InitStructure.USART_HardwareFlowControl =USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode =USART_Mode_Tx|USART_Mode_Rx;
	USART_InitStructure.USART_Parity =USART_Parity_No;
	USART_InitStructure.USART_StopBits =USART_StopBits_1;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART2, &USART_InitStructure);
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel =USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =1;
	NVIC_Init(&NVIC_InitStructure);
	
	USART_Cmd(USART2, ENABLE);
}

uint8_t USART_GetFlag()
{
	if(Receive_Data_Flag==1)
	{
		Receive_Data_Flag =0;
		return 1;
	}
	return 0;
}


void USART2_IRQHandler()
{
	if(USART_GetITStatus(USART2, USART_IT_RXNE)==SET)
	{
		Receive_Data=USART_ReceiveData(USART2);
		Receive_Data_Flag = 1;
		USART_ClearITPendingBit(USART2,USART_IT_RXNE);
	}
}
void usart_SendByte(uint16_t Data)
{
	USART_SendData(USART2,Data);
	while(USART_GetFlagStatus(USART2, USART_FLAG_TXE)==RESET);
}


void SendArray(uint8_t *Array,uint8_t Length)
{
	uint8_t i;
	for(i=0;i<Length;i++)
	{
		usart_SendByte(Array[i]);
	}
}

void SendString(char* string)
{
	uint8_t i;
	for(i=0;string[i]!='\0';i++)
	{
		usart_SendByte(string[i]);
	}
}