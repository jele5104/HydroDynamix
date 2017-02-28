/*
 * main.c
 *
 *  Created on: Jan 24, 2017
 *      Author: Matt
 */
/*
 *    Keil project for SPI
 *
 *    Before you start, select your target, on the right of the "Load" button
 *
 *    @author        Tilen Majerle
 *    @email        tilen@majerle.eu
 *    @website    http://stm32f4-discovery.com
 *    @ide        Keil uVision 5
 *    @packs        STM32F4xx Keil packs version 2.2.0 or greater required
 *    @stdperiph    STM32F4xx Standard peripheral drivers version 1.4.0 or greater required
 */



#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"
#include "stdio.h"

// discovery board pin12 is green led
// digital board pin PD13
#define LED1	GPIO_Pin_13
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
	GPIO_InitDef.GPIO_Pin = LED1;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitDef);

	toggleLED(LED1);

}







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

/*
// Include core modules
#include "stm32f4xx.h"
// Include my libraries here
#include "defines.h"
#include "tm_stm32f4_spi.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_mco_output.h"
#include "max11043.h"
#define CS_Pin GPIO_Pin_0
int main(void) {
	uint8_t ADC_data[2];
	ADC_data[0] = 0xAA;
	ADC_data[1] = 0xBB;
	// Initialize system
	SystemInit();
	// Initialize delay
	TM_DELAY_Init();
	// Initialize MCO2 output, pin PC9
	TM_MCOOUTPUT_InitMCO2();
	// Set MCO2 output = SYSCLK / 4
	TM_MCOOUTPUT_SetOutput2(TM_MCOOUTPUT2_Source_SYSCLK, TM_MCOOUTPUT_Prescaler_4);
	// Initialize SPI
	// SCK = PC10, MOSI = PC12, MISO = PC11
	// SCK = PA5, MOSI = PA7, MISO = PA6
	//TM_SPI_InitFull( SPI1, TM_SPI_PinsPack_1, 2, TM_SPI_Mode_0, SPI_Mode_Master, SPI_FirstBit_MSB );
	TM_SPI_InitFull( SPI1, TM_SPI_PinsPack_1, SPI_BaudRatePrescaler_2, TM_SPI_Mode_0, SPI_Mode_Master, SPI_FirstBit_MSB );
	TM_SPI_SetDataSize( SPI1, TM_SPI_DataSize_8b );
	TM_GPIO_Init(GPIOD, CS_Pin, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High);
	// set gpio pin high to start
	TM_GPIO_SetPinHigh(GPIOD, CS_Pin );
	SPI_WAIT(SPI1);


	// read 2 bytes from 0x08 config register
	//TM_GPIO_SetPinLow(GPIOD, CS_Pin );
	//cmd byte   start, addr4, addr3, addr2, addr1, addr0, r/w, 0
	//TM_SPI_Send(SPI1, 0x20);
	//TM_SPI_Send(SPI1, 0xAA);
	//TM_SPI_Send(SPI1, 0xAA);
	//TM_GPIO_SetPinHigh(GPIOD, CS_Pin );

	// Do a read of the config register
	TM_GPIO_SetPinLow(GPIOD, CS_Pin );
	//0001 1110
	TM_SPI_Send(SPI1, 0x22);
	TM_SPI_ReadMulti(SPI1, ADC_data,0xFF,2);
	TM_GPIO_SetPinHigh(GPIOD, CS_Pin );
	//MAX11043_init( SPI1, GPIOD, CS_Pin );
	//TM_SPI_Send(SPI1, 0x22);
	//SPI_WAIT(SPI1)

	while(1) {}
}
*/
