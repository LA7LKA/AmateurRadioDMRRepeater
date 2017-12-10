/*C file for SPI functions*/


#include "spi.h"
#include "Si446x.h"

unsigned int *SpiDataTrans(uint8_t reg)
{
	unsigned int data[SI446X_MAX_PACKET_LEN] ={0};

	wiringPiSPIDataRW(0, (unsigned char *)reg, 1) ;


	return (unsigned int *)data;
}

unsigned int *SpiConfigTrans(uint8_t reg)
{
	unsigned int data[SI446X_MAX_PACKET_LEN] ={0};



	return (unsigned int *)data;
}
