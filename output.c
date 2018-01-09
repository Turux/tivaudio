//*****************************************************************************
// 	output.c
//
//	Provides a Library to Generate a Waveform in form a 32bit data
//
//	---------------------------------------------------------------
//	Requirements:
//	-word.h
//
//*****************************************************************************
#include "output.h"

// 	Generate Waveform
//	@brief			Generate the desired waveform
//	@return			Word			Waveform
Word GenerateWaveform()
{
	float32_t frequency = 1000.0;
	float32_t amplitude = 10000.0;
	float32_t theta_increment;
	float32_t theta = 0.0;
	 
	Word Output;
	theta_increment = 2*PI*frequency/8000;
	theta += theta_increment;
	if (theta > 2*PI) theta -= 2*PI;
	Output.bit32 = amplitude*sinf(theta);

	return Output;
}
