#include "stm32f4xx.h"
#include "stm32f4xx_spi.h"
#include "MAXIM_Config.h"
#include <stdio.h>

//Array for data output to device
//dataWrite[0] - command byte
//dataWrite[1-2] - data to be written
static uint8_t dataWrite[3] = {0,0,0};

//Array for data input from device
//dataRead[0] - command byte
//dataRead[1-8] -data read from the device
static uint8_t dataRead[9] = {0,0,0,0,0,0,0,0,0};

void writeReg(uint8_t addr, uint8_t* dataOut, uint32_t count){
	int i;
	dataWrite[0] = (addr <<2) | 0x00;
	for(i =1; i< count; i++){
		dataWrite[i] = dataOut[i-1];
	}
	for(i=0; i < count; i++){
		while(!(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE)));
		SPI2->DR = dataOut[i];
	}
}

void readReg(uint8_t addr, uint8_t* dataIn, uint32_t count){
	int i;
	dataWrite[0] = (addr << 2)| 0x02 ;
	while(!(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE)));
	for(i = 0; i < count; i++){
		SPI2->DR = dataWrite[i];
		while(!SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE));
		dataRead[i] = SPI2->DR;
	}
	for(i = 1; i < count; i++){
		dataIn[i-1] = dataRead[i];
	}

}

void SPIInit(){
	SPI_InitTypeDef SPI_InitType;

	SPI_InitType.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
	SPI_InitType.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitType.SPI_Mode = SPI_Mode_Master;
	SPI_InitType.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitType.SPI_NSS = SPI_NSS_Soft;
	SPI_InitType.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitType.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitType.SPI_CPHA = SPI_CPHA_1Edge;

	SPI_Init(SPI2, &SPI_InitType);

	GPIO_InitTypeDef GPIO_InitStruct;


	/*-------- Configuring SCK, MISO, MOSI --------*/
	//PB13 -> SCK, PB14 -> MISO, PB15 -> MOSI
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOB, &GPIO_InitStruct);


	/*-------- Configuring ChipSelect-Pin PB12 --------*/

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;

	GPIO_Init(GPIOB, &GPIO_InitStruct);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource13, GPIO_AF_SPI2);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_SPI2);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_SPI2);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	SPI_Cmd(SPI2, ENABLE);

}

int main(void)
{

	uint8_t addr;
//	uint8_t regDataWrite[2];
	uint8_t regDataRead[2];
//	uint16_t regData16;
	uint32_t count;
	count = 3;

	SPIInit();

	GPIOB->BSRRH = GPIO_Pin_12;
	printf("helloworldbitches");
	addr = CONFIG_A;
	readReg(addr,regDataRead,count);
	printf("%s", regDataRead);
	return 0;
}
