#include "stm32f10x.h"                  // Device header
#include "MyI2C.h"
#include "Delay.h"
 uint8_t AHT_ADDRESS_Write =0X70;
 uint8_t AHT_ADDRESS_Read =0X71;
void AHT20_SendData(uint8_t* Data,uint8_t count)
{
    for(uint8_t i=0;i<count;i++)
    {
         My_I2C_WriteData(Data[i]);
         MyI2C_Read_ACK();
    }
}

void AHT20_SendAddress(uint8_t Address)
{
    
}
uint8_t AHT20_ReadData(uint8_t ACK)
{
    uint8_t readData=0x00;
    readData=My_I2C_ReadData(); 
    MyI2C_Write_ACK(ACK);    
    return readData;
}
void AHT20_Init()
{
    uint8_t Status=0x00;
    uint8_t SendBuffer[3] ={0xBE,0x08,0x00};
    Delay_ms(40);
    My_I2C_Start();
    AHT20_SendData(&AHT_ADDRESS_Read,1);
    Status=AHT20_ReadData(1);
    if((Status&0x08)==0x00)
    {
        AHT20_SendData(SendBuffer,3);
    }
    MyI2C_Stop();
    Delay_ms(10);  
}
void AHT20_Function(float* tempature,float* humi)
{
    uint8_t readData[6]={0};
    uint8_t testData[3] ={0xAC,0x33,0x00};
    uint32_t middle;
    My_I2C_Start();
    AHT20_SendData(&AHT_ADDRESS_Write,1);
    AHT20_SendData(testData,3);
    MyI2C_Stop();
    Delay_ms(80);
     My_I2C_Start();
    AHT20_SendData(&AHT_ADDRESS_Read,1);
    for(uint8_t i=0;i<6;i++)
    {
        readData[i] =AHT20_ReadData(0);
    }
    MyI2C_Stop();
    if((readData[0]&0x80)==0x00)
    {
         middle = (((uint32_t)readData[3]&0x0f)<<16)+((uint32_t)readData[4]<<8)+((uint32_t)readData[5]);
         *tempature = middle*200.0f/(1<<20)-50;
         middle = ((uint32_t)readData[1]<<12)+((uint32_t)readData[2]<<4)+((uint32_t)readData[3]>>4);
        *humi = middle*100.0f/(1<<20);
    }
    
}