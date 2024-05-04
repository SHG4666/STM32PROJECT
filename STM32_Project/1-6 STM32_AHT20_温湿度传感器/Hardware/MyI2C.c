#include "stm32f10x.h"                  // Device header
#include "Delay.h"
void MyI2C_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_OD;
    GPIO_InitStructure.GPIO_Pin =GPIO_Pin_3 |GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
    GPIO_Init(GPIOF, &GPIO_InitStructure);
}

void MyI2C_W_SCL(uint8_t BitValue)
{
    GPIO_WriteBit(GPIOF, GPIO_Pin_5, (BitAction) BitValue);
}

void MyI2C_W_SDA(uint8_t BitValue)
{
    GPIO_WriteBit(GPIOF, GPIO_Pin_3, (BitAction) BitValue);
}

uint8_t MyI2C_R_SDA()
{
    uint8_t bitValue;
    bitValue=GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3);
    return bitValue;
}

void My_I2C_Start()
{
    MyI2C_W_SDA(1);
    MyI2C_W_SCL(1);
    MyI2C_W_SDA(0);
    MyI2C_W_SCL(0);
}

void My_I2C_WriteData(uint8_t Data)
{
    for(uint8_t i=0;i<8;i++)
    {
        MyI2C_W_SDA(Data&(0x80>>i));
        MyI2C_W_SCL(1);
        MyI2C_W_SCL(0);
    }
    
}

uint8_t My_I2C_ReadData()
{
    uint8_t readData=0x00;
    MyI2C_W_SDA(1);
    for(uint8_t i=0;i<8;i++)
    {
        MyI2C_W_SCL(1);
        if(MyI2C_R_SDA()==1)
        {
            readData|=(0x80>>i);
        }
        MyI2C_W_SCL(0);
    }
    return readData;
}

void MyI2C_Stop()
{
     MyI2C_W_SDA(0);
     MyI2C_W_SCL(1);
     MyI2C_W_SDA(1);
}

void MyI2C_Write_ACK(uint8_t ACK)
{
    MyI2C_W_SDA(ACK);
    MyI2C_W_SCL(1);
    MyI2C_W_SCL(0);
}

uint8_t MyI2C_Read_ACK()
{
    uint8_t ACK;
    MyI2C_W_SDA(1);
    MyI2C_W_SCL(1);
    ACK = MyI2C_R_SDA();
    MyI2C_W_SCL(0);
    return ACK;
}