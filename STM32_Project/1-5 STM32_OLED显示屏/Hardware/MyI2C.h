#ifndef __MYI2C_H__
#include "stm32f10x.h"                  // Device header
#define __MYI2C_H__

void MyI2C_SCL_W(uint8_t BitVal);
void MyI2C_SDA_W(uint8_t BitVal);
uint8_t MyI2C_SDA_R(void);
void MyI2C_Stop(void);
void MyI2C_I2C_Start(void);
void MyI2C_SendData(uint8_t Data);
uint8_t MyI2C_ReceiveData(void);
uint8_t MyI2C_ReceiveACK(void);
void MyI2C_SendACK(uint8_t SendBit);
void MyI2C_init(void);
#endif
