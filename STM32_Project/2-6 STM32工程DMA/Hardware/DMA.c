#include "DMA.h"

uint16_t MyDMASzie;
void DMA1_Init(uint32_t addr1,uint32_t addr2,uint8_t size)
{
	MyDMASzie =size;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	DMA_InitTypeDef DMA_InitStructure;
	DMA_InitStructure.DMA_PeripheralBaseAddr =addr1;
	DMA_InitStructure.DMA_PeripheralDataSize =DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_PeripheralInc =DMA_PeripheralInc_Enable;
	
	DMA_InitStructure.DMA_MemoryBaseAddr =addr2;
	DMA_InitStructure.DMA_MemoryDataSize =DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_MemoryInc= DMA_MemoryInc_Enable;
	
	DMA_InitStructure.DMA_BufferSize =size;
	DMA_InitStructure.DMA_DIR =DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_M2M =DMA_M2M_Enable;
	DMA_InitStructure.DMA_Mode =DMA_Mode_Normal;
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
	DMA_Init(DMA1_Channel1,&DMA_InitStructure);
}

void MyDMA_Transfer()
{
	DMA_Cmd(DMA1_Channel1, DISABLE);
	DMA_SetCurrDataCounter(DMA1_Channel1,4);
	DMA_Cmd(DMA1_Channel1,ENABLE);
	while(DMA_GetFlagStatus(DMA1_IT_TC1)==RESET);
	DMA_ClearFlag(DMA1_IT_TC1);
}