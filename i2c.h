//*****************************************************************************
// 	i2c.h
//
//	Provides a Library to use I2C for TI PCM5122 configuration driven by 
//	a TI Tiva C uController
//
// 	Requirements:
//	-Tiva C Driverlib
//
//*****************************************************************************
#ifndef __I2C__H__
#define __I2C__H__

// TypeDef Includes
#include <stdint.h>
#include <stdbool.h>

// Hardware Map Includes
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"

// Driverlib Includes
#include "driverlib/i2c.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"

// Prototypes
extern void I2CSetup(unsigned long ulI2CBase, bool ulI2CSpeed);
extern void I2CRegWrite(unsigned long ulI2CBase, unsigned char ucSlaveAdress, unsigned char ucReg, unsigned char ucValue);

#endif
