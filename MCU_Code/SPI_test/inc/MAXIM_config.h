/*
 * MAXIM_Config.h
 *
 *  Created on: Dec 7, 2016
 *      Author: Ha
 */

#ifndef MAXIM_CONFIG_H_
#define MAXIM_CONFIG_H_



#endif /* MAXIM_CONFIG_H_ */

#define ADCA 0x00 // ADC channel Aresult register
#define ADCB 0x01 // ADCchannel B result register
#define ADCC 0x02 // ADCchannel C result register
#define ADCD 0x03 // ADC channel Dresult register
#define ADCAB 0x04 // ADC channels A and B results register
#define ADCCD 0x05 // ADC channels C and D results register
#define ADCABCD 0x06 // ADC channels A,B, C, and D results register
#define STATUS 0x07 // Status register
#define CONFIG 0x08 // Configures the device
#define CONFIG_A 0x0C // ADC channel A configuration
#define CONFIG_B 0x0D // ADC channel B configuration
#define CONFIG_C 0x0E // ADC channel C configuration
#define CONFIG_D 0x0F // ADC channel D configuration
#define REFERENCE 0x10 // Sets the operation state of the reference and buffers
#define A_GAIN 0x11 // Channel A fine gain
#define B_GAIN 0x12 // Channel B fine gain
#define C_GAIN 0x13 // Channel C fine gain
#define D_GAIN 0x14 // Channel D fine gain
// Device Configuration register constants
#define EXTCLK_CLOCK_IN 0x8000
#define EXTCLK_OSC_IN 0x0000
#define CLK_DIV_2 0x0000
#define CLK_DIV_3 0x2000
#define CLK_DIV_4 0x4000
#define CLK_DIV_6 0x6000
#define PD_LOW_POWER 0x1000
#define PD_NORMAL_POWER 0x0000
#define PDA_POWER_DOWN 0x0800
#define PDA_NORMAL 0x0000
#define PDB_POWER_DOWN 0x0400
#define PDB_NORMAL 0x0000
#define PDC_POWER_DOWN 0x0200
#define PDC_NORMAL 0x0000
#define PDD_POWER_DOWN 0x0100
#define PDD_NORMAL 0x0000
#define PDDAC_POWER_DOWN 0x0080
#define PDDAC_NORMAL 0x0000
#define PDOSC_POWER_DOWN 0x0040
#define PDOSC_NORMAL 0x0000
#define BITS_24 0x0020
#define BITS_16 0x0000
#define SCHANA_ON 0x0010
#define SCHANA_OFF 0x0000
#define SCHANB_ON 0x0008
#define SCHANB_OFF 0x0000
#define SCHANC_ON 0x0004
#define SCHANC_OFF 0x0000
#define SCHAND_ON 0x0002
#define SCHAND_OFF 0x0000
#define DECSEL_12 0x0001
#define DECSEL_24 0x0000
// Channel Configuration register constants
#define BDAC_HALF_AVDD 0x1000
#define DIFF_DIFF_MODE 0x0100
#define DIFF_SINGLE 0x0000
#define EQ_ENABLED 0x0080
#define EQ_DISABLED 0x0000
#define MODG_GAIN_1 0x0000
#define MODG_GAIN_2 0x0020
#define MODG_GAIN_4 0x0040
#define PDPGA_POWER_DOWN 0x0010
#define PDPGA_NORMAL 0x0000
#define FILT_ENABLED 0x0008
#define FILT_DISABLED 0x0000
#define PGAG_GAIN_16 0x0004
#define PGAG_GAIN_8 0x0000
#define ENBIASP_ENABLED 0x0002
#define ENBIASP_DISABLED 0x0000
#define ENBIASN_ENABLED 0x0001
#define ENBIASB_DISABLED 0x0000
// Reference register constants
#define EXTREF_EXT 0x0080
#define EXTREF_INT 0x0000
#define EXBUFA_EXT 0x0040
#define EXBUFA_INT 0x0000
#define EXBUFB_EXT 0x0020
#define EXBUFB_INT 0x0000
#define EXBUFC_EXT 0x0010
#define EXBUFC_INT 0x0000
#define EXBUFD_EXT 0x0008
#define EXBUFD_INT 0x0000
#define EXBUFDAC_EXT 0x0004
#define EXBUFDAC_INT 0x0000
#define EXBUFDACH_EXT 0x0002
#define EXBUFDACH_INT 0x0000
#define EXBUFDACL_EXT 0x0001
#define EXBUFDACL_INT 0x0000
