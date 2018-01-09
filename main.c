//*****************************************************************************
// 	main.c
//
// 	This code will Initialize the DAC PCM5122 and send an output
//	waveform to the device using interrupts 
//
//	-------------------------------------------------------------
//	Requirments:
//	-pinout.h, pinout.c
//	-pcm5122.h, pcm5122.c
//	-output.h, output.c
//	-------------------------------------------------------------
//	Hardare:
//	-TI TM4C123GH6PM
//	-TI PCM5122
//	-------------------------------------------------------------
//	Busses:
//	-I2C
//	-I2S
//	-------------------------------------------------------------
//	Wiring:
//	(to be filled...)
//	-I2C
//	-I2S
//	-
//
//*****************************************************************************

//Include TI Pinmux Pinout
#include "pinout.h"
//Include PCM5122 Library
#include "pcm5122.h"
//Include Waveform Generator Library
#include "output.h"

//Initialize a 'Word' object to store the output waveform
Word Output_Waveform;

int main()
{
	//Call Pin Initialization
	PinoutSet();
	
	//Generate the desired output waveform
	Output_Waveform = GenerateWaveform();
	
	//Initialize the DAC
	PCM5122_Init();
	
	//Wait forever for Interrrupts
	while(1);
}
