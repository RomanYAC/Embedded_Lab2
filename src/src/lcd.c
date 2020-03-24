#include "lcd.h"

void initializeLCDPins(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOE,GPIO_Pin_10);
}

void sendData(uint8_t data) 
{
    Delay(1);

    if(((data >> 7) & 1)==1) 
			GPIO_SetBits(GPIOE,GPIO_Pin_15);
		else 
			GPIO_ResetBits(GPIOE,GPIO_Pin_15);
		
    if(((data >> 6) & 1)==1) 
			GPIO_SetBits(GPIOE,GPIO_Pin_14);
		else 
			GPIO_ResetBits(GPIOE,GPIO_Pin_14);
		
    if(((data >> 5) & 1)==1) 
			GPIO_SetBits(GPIOE,GPIO_Pin_13);
		else 
			GPIO_ResetBits(GPIOE,GPIO_Pin_13);
		
    if(((data >> 4) & 1)==1) 
			GPIO_SetBits(GPIOE,GPIO_Pin_12); 
		else 
			GPIO_ResetBits(GPIOE,GPIO_Pin_12);

    GPIO_SetBits(GPIOE,GPIO_Pin_11);
    Delay(1);
		GPIO_ResetBits(GPIOE,GPIO_Pin_11);

		if(((data >> 3) & 1)==1) 
			GPIO_SetBits(GPIOE,GPIO_Pin_15);
		else 
			GPIO_ResetBits(GPIOE,GPIO_Pin_15);
		
    if(((data >> 2) & 1)==1) 
			GPIO_SetBits(GPIOE,GPIO_Pin_14);
		else 
			GPIO_ResetBits(GPIOE,GPIO_Pin_14);
		
    if(((data >> 1) & 1)==1) 
			GPIO_SetBits(GPIOE,GPIO_Pin_13);
		else 
			GPIO_ResetBits(GPIOE,GPIO_Pin_13);
		
    if(((data >> 0) & 1)==1) 
			GPIO_SetBits(GPIOE,GPIO_Pin_12); 
		else 
			GPIO_ResetBits(GPIOE,GPIO_Pin_12);

    GPIO_SetBits(GPIOE,GPIO_Pin_11);
    Delay(1);
		GPIO_ResetBits(GPIOE,GPIO_Pin_11);
}

void InitializeLCD(void)
{
	initializeLCDPins();
	Delay(40);
	SendCommand(0x20); 
	Delay(5);
	SendCommand(0x28); 
	Delay(5);
	SendCommand(0x28); 
	Delay(5);
	SendCommand(0x0f);
	Delay(5);
	SendCommand(0x01);
	Delay(5);
	SendCommand(0x06);
	ClearDisplay();
}

void SendCommand(uint8_t cmd) 
{
	  GPIO_SetBits(GPIOE,GPIO_Pin_7); 
    sendData(cmd);
}

void WriteChar(const char chr) 
{
	  GPIO_ResetBits(GPIOE,GPIO_Pin_7); 
    sendData((uint8_t)chr);
}

void WriteString(char* str)
{
	for(uint8_t i=0;str[i]!='\0';i++)
	{
		WriteChar(str[i]);
	}
}

void SetCursor(uint8_t col, uint8_t row)
{
	SendCommand(0x80 | (col | row*0x40));
}

void ClearDisplay(void)
{
	SendCommand(0x01);
	Delay(2);
}
