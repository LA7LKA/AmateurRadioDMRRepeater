/*************************************************

This is the main file for the project...

73 & 88 de LA7LKA

*************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "src/Si446x.h"

#define DMR_LENGHT 33

uint8_t buffer[DMR_LENGHT];
char data[DMR_LENGHT] = {0};
si446x_info_t* ICinfo;
int main(void)
{

	
	// Start up
	Si446x_init();
	//Si446x_setTxPower(SI446X_MAX_TX_POWER);

	//Si446x_setTxPower(0);


	Si446x_getInfo(ICinfo);

	//printf("IC info: %d %d %d %d %d %d\n\r", ICinfo -> chipRev, ICinfo->part, ICinfo->partBuild, ICinfo->id, ICinfo->customer, ICinfo->romId);
	

	for(int i=0; i < DMR_LENGHT;i++)
	{
		data[i] = rand() % 255;

		printf("%x", data[i]);
	}
	
	printf("\n\r");
	
	//delay(5*1000); // wait 5 seconds

/*
	Si446x_RX(63); //RX on 433,575 Mhz
	while(1);
*/
/*
	while(1)
	{
		
		
		if(Si446x_getRSSI() > -60)
		{
			printf("RSSI: %d\n\r", Si446x_getRSSI());
			Si446x_read((uint8_t*)buffer, DMR_LENGHT);

			for(int i=0; i < DMR_LENGHT;i++)
				printf("%x",buffer[i]);

			printf("\n\r");
		}
		
	}

*/


	while(1)
	{

		Si446x_TX(data, sizeof(data), 63, SI446X_STATE_RX); //TX on 433,575 Mhz => ch 63
		delay(64); //Wait for 500ms

	}


	return 0;
}
