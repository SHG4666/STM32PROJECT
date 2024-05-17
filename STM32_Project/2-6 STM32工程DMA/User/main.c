#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "DMA.h"
int main(void)
{
		uint8_t DataA[] = {0x01,0x02,0x03,0x04};
		uint8_t DataB[] = {0,0,0,0};
    OLED_Init();
		OLED_Clear();
		DMA1_Init((uint32_t)&DataA,(uint32_t)&DataB,4);
    while(1)
    {
				MyDMA_Transfer();
			 OLED_ShowHexNum(0,0,DataA[0],2,8);
			 OLED_ShowHexNum(20,0,DataA[1],2,8);
			 OLED_ShowHexNum(40,0,DataA[2],2,8);
			 OLED_ShowHexNum(60,0,DataA[3],2,8);
			
				OLED_ShowHexNum(0,20,DataB[0],2,8);
			 OLED_ShowHexNum(20,20,DataB[1],2,8);
			 OLED_ShowHexNum(40,20,DataB[2],2,8);
			 OLED_ShowHexNum(60,20,DataB[3],2,8);
       OLED_Update();
    }  
}
