#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "USART.H"
extern uint8_t Receive_Data;
int main(void)
{
		uint8_t ReceiveData;
		usart_init();
		OLED_Init();
		OLED_Clear();
    while(1)
    {
       if(USART_GetFlag()== 1)
			 {
					OLED_ShowHexNum(0,0,Receive_Data,3,8);
					OLED_Update();
			 }
    }  
}
