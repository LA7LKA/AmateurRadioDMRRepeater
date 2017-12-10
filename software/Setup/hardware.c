/*Hardware setup for the DMR repeater*/



#include "hardware.h"



int InitHardware(void)
{
	
	//Setup GPIO pins

	wiringPiSetup(); //Init library 

	pinMode(SDN_TX, OUTPUT);
	pinMode(nSEL_TX, OUTPUT);
	//pinMode(IRQ_TX, INPUT);


	//SPI setup

	if(wiringPiSPISetup (0, 100000)  < 0) //SPI channel 0 and 500Khz bus clock speed
	{		
		printf("SPI init fail!\n\r");
		return 1;
	}

	wiringPiISR(IRQ_TX, INT_EDGE_FALLING, &Irq_tx_module);


	return 0;
}

