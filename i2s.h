//*****************************************************************************
// 	i2s.h
//
//	Provides a Library to use I2S with TI PCM5122 and a Tiva C uController
//
// 	Requirements:
//	-Tiva C Driverlib
//	-Union 'Word' (word.h)
//
//*****************************************************************************
#ifndef __I2S__H__
#define __I2S__H__

// TypeDef Includes
#include <stdint.h>
#include <stdbool.h>

// Hardware Map Includes
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"

// Driverlib Includes
#include "driverlib/udma.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/ssi.h"
#include "driverlib/sysctl.h"

// Union Word Inclues
#include "word.h"

// Prototype
extern void I2S_Init(void);

#endif
