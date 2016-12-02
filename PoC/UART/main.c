/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

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

int sendMessage(char* message){
	int i = 0;
	while(message[i] != '\0'){
		while(!(USART1->SR & USART_FLAG_TXE));
		USART1->DR = (uint16_t) message[i] & 0x01FF;
		i++;
	}
	return 0;
}

int sendChar(uint16_t message){
	//while(!(USART1->SR & USART_FLAG_TXE));
	USART1->DR = (message & (uint16_t)0x01FF);
	return 0;
}

int main(void)
{
	//Initialization
		GPIO_InitTypeDef GPIO_InitDef;

		RCC->AHB1ENR |= RCC_AHB1Periph_GPIOD; //enable GPIOD clock
		GPIO_InitDef.GPIO_Pin = LED_GREEN| LED_ORANGE | LED_RED | LED_BLUE;
		GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
		GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
		GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_InitDef.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_Init(GPIOD, &GPIO_InitDef);

//		//Initialization for user button
//		RCC->AHB1ENR |= RCC_AHB1Periph_GPIOA; //enable GPIOA clock
//		GPIO_InitDef.GPIO_Pin = BUTTON_pin;
//		GPIO_InitDef.GPIO_Mode = GPIO_Mode_IN;
//		GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
//		GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_DOWN;
//		GPIO_InitDef.GPIO_Speed = GPIO_Speed_2MHz;
//		GPIO_Init(GPIOA, &GPIO_InitDef);

		//GPIO Initialization for USART1
		RCC-> AHB1ENR |= RCC_AHB1Periph_GPIOA;
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
		GPIO_InitDef.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
		GPIO_InitDef.GPIO_Mode = GPIO_Mode_AF;
		GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
		GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_UP;
		GPIO_InitDef.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_Init(GPIOA, &GPIO_InitDef);

		//USART1 Initialization
		USART_InitTypeDef USART_InitStruct;
		RCC-> APB2ENR |= RCC_APB2Periph_USART1;	//enable clock for USART1
		USART1->CR1 |= USART_CR1_UE;
		USART_InitStruct.USART_BaudRate = 9600;
		USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
		USART_InitStruct.USART_Parity = USART_Parity_No;
		USART_InitStruct.USART_StopBits = USART_StopBits_1;
		USART_InitStruct.USART_WordLength = USART_WordLength_8b;
		USART_Init(USART1, &USART_InitStruct);


		char color;
		char message[20] = "hello world\n";
		//char test = 'g';
		uint16_t num = 3;

		while(1){
			if(USART1->SR & USART_FLAG_RXNE){
				color = (char)USART1->DR & (char)0x01FF;
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
					sendMessage(message);
				}
			}
		}

//	while(1){
//		if(GPIOA->IDR & BUTTON_pin){
//			GPIOD->BSRRL = LED_GREEN| LED_ORANGE | LED_RED | LED_BLUE;
//			//GPIO_SetBits(GPIOD, LED_GREEN| LED_ORANGE | LED_RED | LED_BLUE);
//		}
//		else{
//			GPIOD->BSRRH = LED_GREEN| LED_ORANGE | LED_RED | LED_BLUE;
//			//GPIO_ResetBits(GPIOD, LED_GREEN| LED_ORANGE | LED_RED | LED_BLUE);
//		}
//	}
}
