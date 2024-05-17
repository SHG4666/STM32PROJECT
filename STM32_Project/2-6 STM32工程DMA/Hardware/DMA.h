#ifndef __DMA_H__
#define __DMA_H__
#include "stm32f10x.h"                  // Device header

void DMA1_Init(uint32_t addr1,uint32_t addr2,uint8_t size);
void MyDMA_Transfer();
#endif