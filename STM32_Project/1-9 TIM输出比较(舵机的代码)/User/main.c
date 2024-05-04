#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "StreeringGear.h"
#include "Key.h"
uint8_t KeyNum;
float Angle;
int main(void)
{
    uint8_t KeyNum =0;
    OLED_Init();
    Key_Init();
    StreeringGear_Init();
    OLED_Clear(); 
    OLED_ShowString(0,0,"Angle:",8);
    while(1)
    {
       
      KeyNum =Key_Num();
      if(KeyNum==1)
      {
          Angle+=30;
          if(Angle>180)
          {
              Angle =0;
          }
          KeyNum =0;
          StreeringGear(Angle);
      }
     
      OLED_ShowNum(50,0,Angle,5,8);
      OLED_Update();
    }  
}

