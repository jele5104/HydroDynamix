#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"
#include "stdio.h"

#define LED_GREEN	GPIO_Pin_12
#define LED_ORANGE	GPIO_Pin_13
#define LED_RED		GPIO_Pin_14
#define LED_BLUE	GPIO_Pin_15
#define BUTTON_pin 	0x01

int toggleLED(uint16_t led){
	GPIOD->ODR ^= led;
	return 0;
}

void sendChar(uint16_t c){
	//while(!(USART1->SR & USART_FLAG_TXE));
	while (!USART_GetFlagStatus(USART2, USART_FLAG_TXE));
	USART_SendData(USART2, c);
	//USART1->DR = (message & (uint16_t)0x01FF);
}

void sendMessage(char* message){
	while(*message){
		sendChar(*message++);
	}
}

uint16_t USART_GetChar(){
	while(!USART_GetFlagStatus(USART2, USART_FLAG_RXNE));
	return USART_ReceiveData(USART2);
}

int main(void)
{
	GPIO_InitTypeDef GPIO_InitDef;
	USART_InitTypeDef USART_InitStruct;

	//Initialization for LEDs
	RCC->AHB1ENR |= RCC_AHB1Periph_GPIOD; //enable GPIOD clock
	GPIO_InitDef.GPIO_Pin = LED_GREEN| LED_ORANGE | LED_RED | LED_BLUE;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitDef);

	//GPIO Initialization for USART1
	/* Enable GPIO clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	/* Enable UART clock */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

	//Connect PA2 to USART2 Tx
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
	//Connect PA3 to USART2 Rx
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);

	//Configure USART2 Tx as alternate function
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitDef);

	//Configure USART2 Rx as alternate function
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init(GPIOA, &GPIO_InitDef);

	USART_InitStruct.USART_BaudRate = 9600;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART2, &USART_InitStruct);

	USART_Cmd(USART2, ENABLE);

	uint16_t color;
	while(1){
		color = USART_GetChar();
		//color = (char)USART1->DR & (char)0x01FF;
		if(color == 'o'){
			toggleLED(LED_ORANGE);

		}
		if(color == 'g'){
			toggleLED(LED_GREEN);
		}
		if(color == 'r'){
			toggleLED(LED_RED);
		}
		if(color == 'b'){
			toggleLED(LED_BLUE);
		}
		if(color == 't'){
			//sendChar(num);
			sendMessage("hello world!\n");
		}
	}
}

