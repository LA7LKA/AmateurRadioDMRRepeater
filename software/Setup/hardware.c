/*Hardware setup for the DMR repeater*/



#include "hardware.h"

#include "../radio/Si446x/si446x_nirq.h"

int InitHardware(void)
{
	
	//Setup GPIO pins

	wiringPiSetup(); //Init library 

	pinMode(SDN_TX, OUTPUT);
	pinMode(nSEL_TX, OUTPUT);
	//pinMode(IRQ_TX, INPUT);


	//SPI setup

	if(wiringPiSPISetup (SPI_CHAN, 500000)  < 0) //SPI channel 0 and 500Khz bus clock speed
	{		
		printf("SPI init fail!\n\r");
		return 1;
	}

	wiringPiISR(IRQ_TX, INT_EDGE_FALLING, &si446x_nirq_process);


	return 0;
}

