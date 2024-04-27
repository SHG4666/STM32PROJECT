#ifndef __MYI2C__H__
#include "stm32f10x.h"                  // Device header
#define __MYI2C__H__

void MyI2C_Init(void);
uint8_t MyI2C_R_SDA(void);
void My_I2C_Start(void);
void My_I2C_WriteData(uint8_t Data);
uint8_t My_I2C_ReadData(void);
void MyI2C_Stop(void);
void MyI2C_Write_ACK(uint8_t ACK);
uint8_t MyI2C_Read_ACK(void);
#endif