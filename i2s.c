//*****************************************************************************
// 	i2s.c
//
//	Provides a Library to use I2S with TI PCM5122 and a Tiva C uController
//
//	--------------------------------------------------------------------
// 	Requirements:
//	-Tiva C Driverlib
//	-Union 'Word' (word.h)
//	--------------------------------------------------------------------
//	Module Used:
//	-Left Channel: SS1
//	-Right Channel: SS0
//	-LRClock _
//						|_ Left Channel: 	GPIO A3
//						|_ Right Channel:	GPIO D1
//
//*****************************************************************************
#include "i2s.h"

// Declare Output waveform
extern Word Output_Waveform;


// 	Interrupt Handler for Left Channel
// 	@brief		Sends 16 bit of data to Left Channel
void I2S_Send_Left()
{
	//Clear Interrupt Flag
	GPIOIntClear(GPIO_PORTD_BASE, GPIO_PIN_1);
	
	//Send 16 bit of data
	SSIDataPut(SSI1_BASE, Output_Waveform.bit16[0]);
}

// 	Interrupt Handler for Right Channel
// 	@brief		Sends 16 bit of data to Right Channel
void I2S_Send_Right()
{
	//Clear Interrupt Flag
	GPIOIntClear(GPIO_PORTA_BASE, GPIO_PIN_3);
	
	//Send 16 bit of data
	SSIDataPut(SSI0_BASE, Output_Waveform.bit16[1]);
}

void I2S_Init()
{
	// Enable the Peripheral and Reset it
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);
	ROM_SysCtlPeripheralReset(SYSCTL_PERIPH_SSI0);
	// Ensure the Module is Disables while sending configuration
	SSIDisable(SSI0_BASE);
	// Set Speed, Mode, 16 bit Data lenght
	SSIConfigSetExpClk(SSI0_BASE, SysCtlClockGet(), SSI_FRF_MOTO_MODE_0, SSI_MODE_SLAVE, 10000, 16);
	// Enable the Module
	SSIEnable(SSI0_BASE);
	
	// Enable the Peripheral and Reset it
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI1);
	ROM_SysCtlPeripheralReset(SYSCTL_PERIPH_SSI1);
	// Ensure the Module is Disables while sending configuration
	SSIDisable(SSI1_BASE);
	// Set Speed, Mode, 16 bit Data lenght
	SSIConfigSetExpClk(SSI1_BASE, SysCtlClockGet(), SSI_FRF_MOTO_MODE_0, SSI_MODE_SLAVE, 10000, 16);
	// Enable the Module
	SSIEnable(SSI1_BASE);
	
	// Set Interrupt Handler on LRCLK (WCLK) Rising Edge for Right Channel
	GPIOIntDisable(GPIO_PORTA_BASE, GPIO_PIN_3);
  GPIOIntClear(GPIO_PORTA_BASE, GPIO_PIN_3);
  GPIOIntRegister(GPIO_PORTA_BASE, I2S_Send_Right);
  GPIOIntTypeSet(GPIO_PORTA_BASE, GPIO_PIN_3, GPIO_RISING_EDGE);
  GPIOIntEnable(GPIO_PORTA_BASE, GPIO_PIN_3);
	
	// Set Interrupt Handler on LRCLK (WCLK) Rising Edge for Left Channel
	GPIOIntDisable(GPIO_PORTD_BASE, GPIO_PIN_1);
  GPIOIntClear(GPIO_PORTD_BASE, GPIO_PIN_1);
  GPIOIntRegister(GPIO_PORTD_BASE, I2S_Send_Left);
  GPIOIntTypeSet(GPIO_PORTD_BASE, GPIO_PIN_1, GPIO_RISING_EDGE);
  GPIOIntEnable(GPIO_PORTD_BASE, GPIO_PIN_1);
}
