/*Hardware setup for the DMR repeater*/



#include "hardware.h"

#include "../radio/si446x_nirq.h"

int InitHardware(void)
{
	
	//Setup GPIO pins

	wiringPiSetup(); //Init library 

	pinMode(SDN_TX, OUTPUT);
	pinMode(nSEL_TX, OUTPUT);
	//pinMode(IRQ_TX, INPUT);


	//SPI setup
      if (!bcm2835_init())
	{		
		printf("SPI init fail!\n\r");
		return 1;
	}

    bcm2835_spi_begin();
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   // The default
    //bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_65536); // The default
	bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_2048);
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // The default
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // the default



	wiringPiISR(IRQ_TX, INT_EDGE_FALLING, &si446x_nirq_process);

/*
	while(1)
	{

		uint8_t SendData=0x55;
		uint8_t ReadData;
		ReadData = bcm2835_spi_transfer(SendData);
	}
*/
	return 0;
}

