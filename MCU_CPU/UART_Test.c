#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_usart.h"
#include "stdio.h"

volatile uint16_t test;
volatile uint16_t command[20];
volatile uint16_t i;

// Receive character from Termite
uint16_t USART_GetChar()
{
	uint16_t ch;

	while(!USART_GetFlagStatus(USART1, USART_FLAG_RXNE));
	ch = USART_ReceiveData(USART1);

	return ch;
}

// Receive character as string
uint16_t receiveString()
{
	i = 0;
	
	while(1)
	{
		while(!USART_GetFlagStatus(USART1, USART_FLAG_RXNE));
		ch = USART_GetChar();
		
		if (ch != 0)
		{
			if (ch == '\n')
			{
				i = 0;
				command[0] = 0;
				break;
			else
			{
				command[i] = ch;
				i++;
			}
				
			ch = 0;
		}
	}
	
	return command;
}


// Send message to Termite
void sendMessage(char *message)
{
	while(*message)
	{
		sendChar(*message++);
	}
}

int main(void)
{
	GPIO_InitTypeDef	GPIO_InitStruct;
	USART_InitTypeDef	USART_InitStruct;

	// Enable clock for GPIOA
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	// TX (pin 9) and RX (pin 10) pins connected to alternate functions
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);

	// Initialize pins 9 and 10 as alternating function
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);

	// Enable clock for USART1
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	// Initialize, configure and enable USART
	USART_InitStruct.USART_BaudRate = 9600;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1, &USART_InitStruct);
	USART_Cmd(USART1, ENABLE);

	while(1){
		test = USART_GetChar();
		command = receiveString();
		
		if (test == 't')
		{
			sendMessage(“transmission and reception successful\n”);
		}
		if (command = "get data")
		{
			sendMessage(“data received\n”);
		}
	}
}
