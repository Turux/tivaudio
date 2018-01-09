//*****************************************************************************
// 	word.h
//
//	Provides a Union 'Word' to handle 32bit data in two 16bit form
//
//*****************************************************************************

#ifndef __WORD__H__
#define __WORD__H__

// TypeDef Includes
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "arm_math.h"

// Word Union definition
typedef union
{
  uint32_t 	bit32;
  uint16_t 	bit16[2];
} Word;

#endif
