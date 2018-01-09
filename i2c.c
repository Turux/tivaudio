//*****************************************************************************
// 	i2c.c
//
//	Provides a Library to use I2C for TI PCM5122 configuration driven by 
//	a TI Tiva C uController
//
// 	Requirements:
//	-Tiva C Driverlib
//
//*****************************************************************************
#include "i2c.h"

//	I2C Initalization
//	@brief		Initialize the I2C Peripheral, Sets up Speed
//	@param		unsigned long ulI2CBase				I2C Module to be used
//	@param		bool					I2CFastMode			Fast Mode flag
//
//	NB: Requires a fully Pinout Initialization (Ti PinMux)
void I2CSetup(unsigned long ulI2CBase, bool I2CFastMode)
{
	// Periferal Module
	uint32_t ui32Peripheral;
	// Select the right Peripheral
	switch (ulI2CBase)
	{
		case I2C0_BASE: ui32Peripheral = SYSCTL_PERIPH_I2C0;
		case I2C1_BASE: ui32Peripheral = SYSCTL_PERIPH_I2C1;
		case I2C2_BASE: ui32Peripheral = SYSCTL_PERIPH_I2C2;
		case I2C3_BASE: ui32Peripheral = SYSCTL_PERIPH_I2C3;
		case I2C4_BASE: ui32Peripheral = SYSCTL_PERIPH_I2C4;
		case I2C5_BASE: ui32Peripheral = SYSCTL_PERIPH_I2C5;
		case I2C6_BASE: ui32Peripheral = SYSCTL_PERIPH_I2C6;
		case I2C7_BASE: ui32Peripheral = SYSCTL_PERIPH_I2C7;
		case I2C8_BASE: ui32Peripheral = SYSCTL_PERIPH_I2C8;
		case I2C9_BASE: ui32Peripheral = SYSCTL_PERIPH_I2C9;
		default: ui32Peripheral = SYSCTL_PERIPH_I2C0;
		
	}
  //Enables the peripheral
	ROM_SysCtlPeripheralEnable(ui32Peripheral);
	//Reset the peripheral status 
	ROM_SysCtlPeripheralReset(ui32Peripheral);
	//Initialize I2C interface according to Speed
  ROM_I2CMasterInitExpClk(ulI2CBase, SysCtlClockGet(), I2CFastMode);
}

//	I2C Write to a Register
//	@brief			Write a value to a register in the DAC module
//	@param			unsigned long ulI2CBase				I2C module to be used
//	@param			unsigned char ucSlaveAdress		Address of the DAC 	(7 bit)
//	@param			unsigned char ucReg						Register to write		(8 bit)
//	@param			unsigned char ucValue					Value to write			(8 bit)
void I2CRegWrite(unsigned long ulI2CBase, unsigned char ucSlaveAdress, unsigned char ucReg, unsigned char ucValue)
{
	//Wait until the BUS is free
	while(ROM_I2CMasterBusy(ulI2CBase));
	
	//Send Slave Address
	ROM_I2CMasterSlaveAddrSet(ulI2CBase, ucSlaveAdress, 0);
	
	//Send Register Number
	ROM_I2CMasterDataPut(ulI2CBase, ucReg);
	ROM_I2CMasterControl(ulI2CBase, I2C_MASTER_CMD_BURST_SEND_START);
	
	//Wait until the BUS is free
	while(ROM_I2CMasterBusy(ulI2CBase));
	
	//Send Value to Register
	ROM_I2CMasterDataPut(ulI2CBase, ucValue);
	ROM_I2CMasterControl(ulI2CBase, I2C_MASTER_CMD_BURST_SEND_FINISH);
	
	//Wait until the BUS is free
	while(ROM_I2CMasterBusy(ulI2CBase));
}
