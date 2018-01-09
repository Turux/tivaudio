//*****************************************************************************
// 	pcm5122.h
//
//	Provides a Library to use the TI PCM5122 Low-Latency DAC Audio-Processor
//
// 	Requirements:
//	-Tiva C Driverlib
//	-I2C PCM5122 Library (i2c.h, i2c.c)
//	-I2S Library (i2s.h, i2s.c)
//
//*****************************************************************************
#ifndef __PCM5122__H__
#define __PCM5122__H__

// I2C Includes
#include "i2c.h"
// I2S Includes
#include "i2s.h"

// Define I2C Module to be used
#define I2CBase 				I2C0_BASE
// Define I2C Address (7bit) for the PCM5122 Device
#define I2CSlaveAdress 	0x4C
// Use I2C Fast Mode?
#define I2CFastMode 		false

// Prototypes
extern void PCM5122_Init(void);

#endif
