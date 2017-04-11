/*
 * main.c
 *
 *  Created on: Jan 24, 2017
 *      Author: Matt
 */

/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
/*
#include "stm32f4xx.h"
// Include my libraries here
#include "defines.h"
#include "tm_stm32f4_spi.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_mco_output.h"
#include<stdio.h>
#include "stm32f4xx_usart.h"
#include "stm32f4xx_rcc.h"


#define LED1	GPIO_Pin_13		//PD13
#define LED2	GPIO_Pin_14		//PD14
#define LED3	GPIO_Pin_15		//PD15
#define LED4	GPIO_Pin_0		//PE0
#define LED5	GPIO_Pin_1		//PE1

void toggleGPIOD(uint16_t led){
	GPIOD->ODR ^= led;
}

void toggleGPIOE(uint16_t led){
	GPIOE->ODR ^= led;
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


uint16_t getChar(){
	while(!USART_GetFlagStatus(USART2, USART_FLAG_RXNE));
	return USART_ReceiveData(USART2);
}



void getMessage(char message[],int size){
	int i;

	for(i=0; i<size; i++){
		message[i] = getChar();
	}
}


//15 -- PC0
//16 -- PC1
#define Foff GPIO_Pin_0
#define Fon  GPIO_Pin_1
int main(void){

	// Start of initialization sequence
	// on start up MCU will initialize itself and ADC

	GPIO_InitTypeDef GPIO_InitDef;
	USART_InitTypeDef USART_InitStruct;

	RCC->AHB1ENR |= RCC_AHB1Periph_GPIOD; //enable GPIOD clock
	RCC->AHB1ENR |= RCC_AHB1Periph_GPIOE;  //enable GPIOE clock

	//Initialization for LEDs
	GPIO_InitDef.GPIO_Pin = LED1 | LED2| LED3;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitDef);

	GPIO_InitDef.GPIO_Pin = LED4 | LED5;
	GPIO_Init(GPIOE, &GPIO_InitDef);


	//GPIO Initialization for USART2
	//Enable GPIO clock
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	//Enable UART clock
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

	// setting force on and force off for the rs232
	TM_GPIO_Init(GPIOC, Foff, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High);
	TM_GPIO_Init(GPIOC, Fon, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High);
	// set gpio pin high to start
	TM_GPIO_SetPinHigh(GPIOC, Foff );
	TM_GPIO_SetPinHigh(GPIOC, Fon );



	sendMessage("Ready\n");
	// once complete MCU will send ready command
	while(1){
		char cIn[5] = {0};
		getMessage(cIn,sizeof(cIn));

		if(cIn[0] == 't' && cIn[1] == 'e' && cIn[2] == 's' && cIn[3] == 't' ){
			sendMessage("Transmission and reception successful\n");
		}
		if(cIn[0] == 'g' && cIn[1] == 'e' && cIn[2] == 't' && cIn[3] == 'D' ){
			sendMessage("Data Received\n");
		}
	}
}
*/


/*
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"
#include "stdio.h"

// discovery board pin12 is green led
// digital board pin PD13
#define LED1	GPIO_Pin_13
#define LED2	GPIO_Pin_14
#define LED3	GPIO_Pin_15
//#define LED4	GPIO_Pin_0
//#define LED5	GPIO_Pin_1
//#define LED_ORANGE	GPIO_Pin_13
//#define LED_RED		GPIO_Pin_14
//#define LED_BLUE	GPIO_Pin_15
//#define BUTTON_pin 	0x01

int toggleLED(uint16_t led){
	GPIOD->ODR ^= led;
	return 0;
}

int main(void)
{
    // Initialize system
    SystemInit();
	GPIO_InitTypeDef GPIO_InitDef;
	//USART_InitTypeDef USART_InitStruct;

	//Initialization for LEDs
	RCC->AHB1ENR |= RCC_AHB1Periph_GPIOD; //enable GPIOD clock
	GPIO_InitDef.GPIO_Pin = LED1 | LED2 | LED3;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitDef);


	while(1){
		toggleLED(LED1);
		toggleLED(LED2);
		toggleLED(LED3);
		//toggleLED(LED4);
		//toggleLED(LED5);
	}

}
*/






/*
// Include core modules

#include "stm32f4xx.h"
// Include my libraries here
#include "defines.h"
#include "tm_stm32f4_spi.h"

int main(void) {
    // Initialize system
    SystemInit();

    // Initialize SPI1
    	// SCK = PA5, MOSI = PA7, MISO = PA6
	// Initialize SPI2
	    // SCK = PB13, MOSI = PB14, MISO = PB15
    TM_SPI_Init(SPI1, TM_SPI_PinsPack_1);

    // Send 0x15 over SPI2

    while(1) {
    	TM_SPI_Send(SPI1, 0x15);

    }
}
*/






/* Most of this code was written by: Author: Tilen Majerle
 * Website: ​http://stm32f4­discovery.com Note: Code edited by Aram Garibyan */


// Include core modules
#include "stm32f4xx.h"
// Include my libraries here
#include "defines.h"
#include "tm_stm32f4_spi.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_mco_output.h"
#include "max11043.h"

#define CS_Pin1 GPIO_Pin_0
#define CS_Pin2 GPIO_Pin_1
#define CONVRUN GPIO_Pin_15
#define EOC GPIO_Pin_12
#define SHDN1 GPIO_Pin_0
#define SHDN2 GPIO_Pin_10
#define DACSTEP GPIO_Pin_12
#define READSIZE 2

void readReg(uint8_t addr, uint8_t* dataIn, uint32_t datasize){
    uint8_t commandByte = 0;
    TM_GPIO_SetPinLow(GPIOD, CS_Pin2);

    commandByte = (addr << 2)| 0x02 ;
    TM_SPI_Send(SPI1, commandByte);
    TM_SPI_ReadMulti(SPI1, dataIn, 0x00, datasize);

    TM_GPIO_SetPinLow(GPIOD, CS_Pin2);
}

int main(void) {
	uint8_t ADC_data[8];
	uint8_t dataFromADC[2];
	ADC_data[0] = 0x00;
	ADC_data[1] = 0x00;
	ADC_data[2] = 0x00;
	ADC_data[3] = 0x00;
	// Initialize system
	SystemInit();
	// Initialize delay
	TM_DELAY_Init();
	// Initialize MCO2 output, pin PC9
	TM_MCOOUTPUT_InitMCO2();
	// Set MCO2 output = SYSCLK / 4
	TM_MCOOUTPUT_SetOutput2(TM_MCOOUTPUT2_Source_SYSCLK, TM_MCOOUTPUT_Prescaler_5);
	// Initialize SPI
	// SCK = PC10, MOSI = PC12, MISO = PC11
	// SCK = PA5, MOSI = PA7, MISO = PA6
	//TM_SPI_InitFull( SPI1, TM_SPI_PinsPack_1, 2, TM_SPI_Mode_0, SPI_Mode_Master, SPI_FirstBit_MSB );
	TM_SPI_InitFull( SPI1, TM_SPI_PinsPack_1, SPI_BaudRatePrescaler_4, TM_SPI_Mode_0, SPI_Mode_Master, SPI_FirstBit_MSB );
	TM_SPI_SetDataSize( SPI1, TM_SPI_DataSize_8b );


	TM_GPIO_Init(GPIOD, SHDN2, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_DOWN, TM_GPIO_Speed_High);
	TM_GPIO_Init(GPIOD, SHDN1 , TM_GPIO_Mode_IN, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High);
	TM_GPIO_Init(GPIOD, DACSTEP, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_DOWN, TM_GPIO_Speed_High);
	TM_GPIO_Init(GPIOD, CS_Pin2, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High);
	TM_GPIO_Init(GPIOD, CS_Pin1, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High);
	TM_GPIO_Init(GPIOE, CONVRUN , TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High);
	TM_GPIO_Init(GPIOB, EOC , TM_GPIO_Mode_IN, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High);


	// set gpio pin high to start
	TM_GPIO_SetPinHigh(GPIOD, CS_Pin1 );
	TM_GPIO_SetPinHigh(GPIOD, CS_Pin2 );
	TM_GPIO_SetPinLow(GPIOD, DACSTEP );
	TM_GPIO_SetPinLow(GPIOE, CONVRUN );
	TM_GPIO_SetPinHigh(GPIOD, SHDN1 );
	TM_GPIO_SetPinLow(GPIOD, SHDN2 );
	TM_GPIO_SetPinHigh(GPIOD, SHDN2 );
	TM_GPIO_SetPinLow(GPIOD, SHDN2 );

	SPI_WAIT(SPI1);
int i = 0;
while(i<3){
	TM_GPIO_SetPinLow(GPIOD, CS_Pin2 );
	TM_SPI_Send(SPI1, 0x22);
	TM_SPI_ReadMulti(SPI1, ADC_data,0x00,2);
	TM_GPIO_SetPinHigh(GPIOD, CS_Pin2 );
	SPI_WAIT(SPI1);


	// Do a read of the config register
	TM_GPIO_SetPinLow(GPIOD, CS_Pin2 );
	TM_SPI_Send(SPI1, 0x20);
	TM_SPI_Send(SPI1, 0x60);
	TM_SPI_Send(SPI1, 0x80);
	TM_GPIO_SetPinHigh(GPIOD, CS_Pin2 );


	SPI_WAIT(SPI1);
	TM_GPIO_SetPinLow(GPIOD, CS_Pin2 );
	TM_SPI_Send(SPI1, 0x1E);
	TM_SPI_ReadMulti(SPI1, ADC_data,0x00,2);
	TM_GPIO_SetPinHigh(GPIOD, CS_Pin2 );
	SPI_WAIT(SPI1);
	i++;
}


int ret = MAX11043_init( SPI1, GPIOD, CS_Pin2 );

TM_GPIO_SetPinLow(GPIOD, CS_Pin2 );
TM_SPI_Send(SPI1, 0x22);
TM_SPI_ReadMulti(SPI1, ADC_data,0x00,2);
TM_GPIO_SetPinHigh(GPIOD, CS_Pin2 );
SPI_WAIT(SPI1);

TM_GPIO_SetPinLow(GPIOD, CS_Pin2 );
TM_SPI_Send(SPI1, 0x32);
TM_SPI_ReadMulti(SPI1, ADC_data,0x00,2);
TM_GPIO_SetPinHigh(GPIOD, CS_Pin2 );
SPI_WAIT(SPI1);

if(ret == 0)return 0;

int EOC_val = 0;
TM_GPIO_SetPinHigh(GPIOE, CONVRUN);
while(1){
	if(!GPIO_ReadInputDataBit(GPIOB, EOC)){
		TM_GPIO_SetPinLow(GPIOD, CS_Pin2 );
		TM_SPI_Send(SPI1, 0x1A);
		TM_SPI_ReadMulti(SPI1, ADC_data,0x00,8);
		TM_GPIO_SetPinLow(GPIOE, CONVRUN);
		TM_GPIO_SetPinHigh(GPIOD, CS_Pin2 );
		EOC_val = 0;
		SPI_WAIT(SPI1);
		break;
		//TM_GPIO_SetPinHigh(GPIOE, CONVRUN);
	} else EOC_val = 1;

}
SPI_WAIT(SPI1);

while(1);
}

