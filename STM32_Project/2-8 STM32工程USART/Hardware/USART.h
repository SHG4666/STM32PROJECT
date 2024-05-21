#ifndef __USART_H__
#define __USART_H__
#include "stm32f10x.h"                  // Device header
void usart_init();
void usart_SendByte(uint16_t Data);
void SendArray(uint8_t *Array,uint8_t Length);
void SendString(char* string);
uint8_t USART_GetFlag();
#endif