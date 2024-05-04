#include "stm32f10x.h"
#include "OLED.H"
#include "MyI2C.h"
#include "Delay.h"
#include "AHT20.h"
// Device header
int main(void)
{
    float temp=0.0;
    float humi=0.0;
    uint32_t testData=0;
  
    MyI2C_Init();
    OLED_Init();
    OLED_Clear();
   
    OLED_ShowString(0,0,"TEMP:",8);
    OLED_ShowString(0,43,"HUMI:",8);
    OLED_ShowString(90,0,"C",8);
    OLED_ShowString(90,43,"%",8);
    while(1)
    {  
        AHT20_Init();
       AHT20_Function(&temp,&humi);
       OLED_ShowFloatNum(40, 0, temp, 2,2, 8);
       OLED_ShowFloatNum(40,43,humi , 2,2, 8);
       OLED_Update();
    }  
}
