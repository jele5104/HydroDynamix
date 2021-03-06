#include "max11043.h"
#include "defines.h"
#include "tm_stm32f4_spi.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_mco_output.h"
#include "tm_stm32f4_gpio.h"

#define false 0
#define true 1
/* Private variables */
static uint8_t dataWrite[3] = {0,0,0};
// Array for data output to the device
// dataWrite[0] ­ command byte
// dataWrite[1­2] ­ data to be written
static uint8_t dataRead[9] = {0,0,0,0,0,0,0,0,0};
// Array for data input from the device
// dataRead[0] ­ read data when sending command byte
// dataRead[1­8] ­ data read from the device
/* Private functions */
//bool
int checkWritten( uint8_t* dataOut, uint8_t* dataIn, uint32_t count );
/* Public functions */
void MAX11043_writeReg( SPI_TypeDef* SPIx, GPIO_TypeDef* GPIOx, uint16_t CS_Pin, uint8_t addr, uint8_t* dataOut, uint32_t count ){
    uint32_t i;
    dataWrite[0] = ( addr << 2 ) | 0x00;
    // Writing to address addr
    for(i = 1; i < count; i++){
        dataWrite[i] = dataOut[i-1];
    }
    TM_GPIO_SetPinLow(GPIOx, CS_Pin );
    TM_SPI_WriteMulti( SPIx, dataWrite, count);
    TM_GPIO_SetPinHigh(GPIOx, CS_Pin);
}
void MAX11043_readReg( SPI_TypeDef* SPIx, GPIO_TypeDef* GPIOx, uint16_t CS_Pin, uint8_t addr, uint8_t* dataIn, uint32_t count ){
    uint32_t i;
    dataWrite[0] = ( addr << 2 ) | 0x02; // Reading from address addr
    TM_GPIO_SetPinLow(GPIOx, CS_Pin );
    TM_SPI_SendMulti( SPIx, dataWrite, dataRead, count);
    TM_GPIO_SetPinHigh(GPIOx, CS_Pin);
    for(i = 1; i < count; i++){
        dataIn[i-1] = dataRead[i];
    }
}

// Dout MISO
int MAX11043_init( SPI_TypeDef* SPIx, GPIO_TypeDef* GPIOx, uint16_t CS_Pin ){
    uint8_t addr;
    uint8_t registerDataWrite[2];
    uint8_t registerDataRead[2];
    uint16_t registerData16;
    uint32_t count;
    count = 3;


    registerData16 = (EXTCLK_OSC_IN | CLK_DIV_4 | PD_NORMAL_POWER | PDA_NORMAL | PDB_NORMAL | PDC_NORMAL | PDD_NORMAL | PDDAC_NORMAL | PDOSC_NORMAL | BITS_16 | SCHANA_OFF | SCHANB_OFF | SCHANC_OFF | SCHAND_OFF | DECSEL_24 );
    // Disassemble data into one byte segments
    registerDataWrite[0] = (registerData16 & 0xFF00) >> 8;
    registerDataWrite[1] = registerData16 & 0x00FF;
    addr = CONFIG; // Write data to configuration register
    MAX11043_writeReg( SPIx, GPIOx, CS_Pin, addr, registerDataWrite, count );
    // Read to verify data was correctly written
    MAX11043_readReg( SPIx, GPIOx, CS_Pin, addr, registerDataRead, count );
    // Check if written
    if( !checkWritten(registerDataWrite, registerDataRead, count))
        return false;


    registerData16 = ( BDAC_HALF_AVDD | DIFF_SINGLE | EQ_DISABLED | MODG_GAIN_1 | PDPGA_POWER_DOWN | FILT_DISABLED | PGAG_GAIN_8 | ENBIASP_DISABLED | ENBIASN_DISABLED );
    // Disassemble data into one byte segments
    registerDataWrite[0] = (registerData16 & 0xFF00) >> 8;
    registerDataWrite[1] = registerData16 & 0x00FF;

    addr = CONFIG_A;
    // Write data to configuration register
    MAX11043_writeReg( SPIx, GPIOx, CS_Pin, addr, registerDataWrite, count );
    // Read to verify data was correctly written
    MAX11043_readReg( SPIx, GPIOx, CS_Pin, addr, registerDataRead, count );
    // Check if written
    if( !checkWritten(registerDataWrite, registerDataRead, count)) return false;


    addr = CONFIG_B;
    // Write data to configuration register
    MAX11043_writeReg( SPIx, GPIOx, CS_Pin, addr, registerDataWrite, count );
    // Read to verify data was correctly written
    MAX11043_readReg( SPIx, GPIOx, CS_Pin, addr, registerDataRead, count );
    // Check if written
    if( !checkWritten(registerDataWrite, registerDataRead, count)) return false;


    addr = CONFIG_C;
    // Write data to configuration register
    MAX11043_writeReg( SPIx, GPIOx, CS_Pin, addr, registerDataWrite, count );
    // Read to verify data was correctly written
    MAX11043_readReg( SPIx, GPIOx, CS_Pin, addr, registerDataRead, count );
    // Check if written
    if( !checkWritten(registerDataWrite, registerDataRead, count)) return false;


    addr = CONFIG_D;
    // Write data to configuration register
    MAX11043_writeReg( SPIx, GPIOx, CS_Pin, addr, registerDataWrite, count );
    // Read to verify data was correctly written
    MAX11043_readReg( SPIx, GPIOx, CS_Pin, addr, registerDataRead, count );
    // Check if written
    if( !checkWritten(registerDataWrite, registerDataRead, count)) return false;


    registerData16 = ( EXTREF_INT | EXBUFA_INT | EXBUFB_INT | EXBUFC_INT | EXBUFD_INT | EXBUFDAC_INT | EXBUFDACH_INT | EXBUFDACL_INT );
    // Disassemble data into one byte segments
    registerDataWrite[0] = (registerData16 & 0xFF00) >> 8;
    registerDataWrite[1] = registerData16 & 0x00FF;
    addr = REFERENCE;
    // Write data to configuration register
    MAX11043_writeReg( SPIx, GPIOx, CS_Pin, addr, registerDataWrite, count );
    // Read to verify data was correctly written
    MAX11043_readReg( SPIx, GPIOx, CS_Pin, addr, registerDataRead, count );
    // Check if written
    if( !checkWritten(registerDataWrite, registerDataRead, count)) return false;


    registerData16 = 0x2000;
    // Disassemble data into one byte segments
    registerDataWrite[0] = (registerData16 & 0xFF00) >> 8;
    registerDataWrite[1] = registerData16 & 0x00FF;
    addr = REFERENCE;
    // Write data to configuration register
    MAX11043_writeReg( SPIx, GPIOx, CS_Pin, addr, registerDataWrite, count );
    // Read to verify data was correctly written
    MAX11043_readReg( SPIx, GPIOx, CS_Pin, addr, registerDataRead, count );
    // Check if written
    if( !checkWritten(registerDataWrite, registerDataRead, count)) return false;

    // If all registers were written to successfuly then return true
    return true;
}

// bool
int MAX11043_readAllChannels( SPI_TypeDef* SPIx, GPIO_TypeDef* GPIOx, uint16_t CS_Pin ){
  uint8_t addr;
  uint8_t registerDataWrite[2];
  uint8_t registerDataRead[6];
  uint16_t registerData16;
  uint32_t count;
  count = 3;
  registerData16 = (EXTCLK_CLOCK_IN | CLK_DIV_4 | PD_NORMAL_POWER | PDA_NORMAL | PDB_NORMAL | PDC_NORMAL | PDD_NORMAL | PDDAC_POWER_DOWN | PDOSC_NORMAL | BITS_16 | SCHANA_OFF | SCHANB_OFF | SCHANC_OFF | SCHAND_OFF | DECSEL_24 );
  // Disassemble data into one byte segments
  registerDataWrite[0] = (registerData16 & 0xFF00) >> 8;
  registerDataWrite[1] = registerData16 & 0x00FF;
  addr = CONFIG;
  // Write data to configuration register
  MAX11043_writeReg( SPIx, GPIOx, CS_Pin, addr, registerDataWrite, count );
  // Read to verify data was correctly written
  MAX11043_readReg( SPIx, GPIOx, CS_Pin, addr, registerDataRead, count );
  // Check if written
  if( !checkWritten(registerDataWrite, registerDataRead, count)) return false;
  // If all registers were written to successfuly then return true
  return true;
}
/* Private functions */
//bool
int checkWritten( uint8_t* dataOut, uint8_t* dataIn, uint32_t count ){
    uint32_t i;
    for( i = 0 ; i < count-1 ; i++ ) {
        if( dataOut[i] != dataIn[i] ) return false;
    }
    return true;
}
