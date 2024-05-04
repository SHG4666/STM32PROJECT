#include "stm32f10x.h"                  // Device header

void MyI2C_SCL_W(uint8_t BitVal)
{
    GPIO_WriteBit(GPIOC, GPIO_Pin_5, (BitAction) BitVal);
}

void MyI2C_SDA_W(uint8_t BitVal)
{
    GPIO_WriteBit(GPIOC, GPIO_Pin_7, (BitAction) BitVal);
}

uint8_t MyI2C_SDA_R()
{
    uint8_t MyI2C_Data_R;
    MyI2C_Data_R=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7);
    return MyI2C_Data_R;
}

void MyI2C_I2C_Start()
{
    MyI2C_SDA_W(1);
    MyI2C_SCL_W(1);
    MyI2C_SDA_W(0);
    MyI2C_SCL_W(0);
}

void MyI2C_Stop()
{
    MyI2C_SDA_W(0);
    MyI2C_SCL_W(1);
    MyI2C_SDA_W(1);
}

void MyI2C_SendData(uint8_t Data)
{
    int i;
    for(i=0;i<8;i++)
    {
        MyI2C_SDA_W(Data&(0x80>>i));
        MyI2C_SCL_W(1);
        MyI2C_SCL_W(0);
    }
}

uint8_t MyI2C_ReceiveData()
{
    int i;
    uint8_t ReceiveData =0x00;
    MyI2C_SDA_W(1);//释放SDA的控制权给从机
    for(i=0;i<8;i++)
    {
        MyI2C_SCL_W(1);
        if(MyI2C_SDA_R()==1)
        {
            ReceiveData|=(0x80>>i);
        }
        MyI2C_SCL_W(0);
    }
    return ReceiveData;
}

uint8_t MyI2C_ReceiveACK()
{
    uint8_t ReceiveBit;
    MyI2C_SDA_W(1);//释放SDA的控制权给从机
    MyI2C_SCL_W(1);
    ReceiveBit =MyI2C_SDA_R(); 
    MyI2C_SCL_W(0);
    return ReceiveBit;
}
void MyI2C_SendACK(uint8_t SendBit)
{
    MyI2C_SDA_W(SendBit);
    MyI2C_SCL_W(1);
    MyI2C_SCL_W(0);
}

void MyI2C_init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_OD;
    GPIO_InitStructure.GPIO_Pin =GPIO_Pin_5 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
    GPIO_Init(GPIOC,&GPIO_InitStructure);
}



