//*****************************************************************************
// 	pcm5122.c
//
//	Provides a Library to use the TI PCM5122 Low-Latency DAC Audio-Processor
//
// 	Requirements:
//	-Tiva C Driverlib
//	-I2C PCM5122 Library (i2c.h, i2c.c)
//	-I2S Library (i2s.h, i2s.c)
//
//*****************************************************************************
#include "pcm5122.h"


// 	Initialize the PCM5122 Device
//	@brief		Initialize HW Pins, Initialize Device using I2C, 
//						Initialize I2S on uController
//
//	NB: 			uses Master Mode Audio Rated Clock on PCM5122
void PCM5122_Init()
{
	//Set MODE1 (GPIO_PF2) to Low
	ROM_GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
	//Set MODE2 (GPIO_PF3) to Hi
	ROM_GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
	//Set ADR1 (GPIO_PD2) to Low
	ROM_GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0);
	//Set ADR2 (GPIO_PE4) to Low
	ROM_GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0);
	//Set XSMT (GPIO_PB5) to Low
	ROM_GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0);
	
	//Setup I2C Interface
	I2CSetup(I2CBase,I2CFastMode);
		
	// Set to Page 0
	I2CRegWrite(I2CBase,I2CSlaveAdress,0,0x00);
	// Put the device in Reset Mode
	I2CRegWrite(I2CBase,I2CSlaveAdress,1,0x11);
	
	// Set I2S in Master Mode
	I2CRegWrite(I2CBase,I2CSlaveAdress,9,0x11);	
	// Reset Divider for BCK and LRCK
	I2CRegWrite(I2CBase,I2CSlaveAdress,12,0x00);
	
	// Put the device in Normal Operation Mode
	I2CRegWrite(I2CBase,I2CSlaveAdress,1,0x00);
	
	// Change to Page 253
	I2CRegWrite(I2CBase,I2CSlaveAdress,0,253);
	// Enable advanced clock tree function
	I2CRegWrite(I2CBase,I2CSlaveAdress,63,0x11);
	I2CRegWrite(I2CBase,I2CSlaveAdress,64,0xFF);
	
	// Set to Page 0
	I2CRegWrite(I2CBase,I2CSlaveAdress,0,0x00); 
	// Set the Clock Source for DAC
	I2CRegWrite(I2CBase,I2CSlaveAdress,14,0x30);
	// Set the Clock Devider to 16 (-1)
	I2CRegWrite(I2CBase,I2CSlaveAdress,28,0x0F);
	
	// Set Register 37 (Clock auto mode)
	I2CRegWrite(I2CBase,I2CSlaveAdress,37,0x00);

	// Set GPIO6 as Output
	I2CRegWrite(I2CBase,I2CSlaveAdress,8,0x20);
	// Set GPIO6 as flag for clock errors
	I2CRegWrite(I2CBase,I2CSlaveAdress,85,0x06);
		
	//Initialize I2S
	I2S_Init();
}
