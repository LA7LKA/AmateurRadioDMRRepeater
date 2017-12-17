/*************************************************

This is the main file for the project...

73 & 88 de LA7LKA

*************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "src/Si446x.h"


char data[128] = {0};
si446x_info_t* ICinfo;
int main(void)
{

	
	// Start up
	Si446x_init();
	Si446x_setTxPower(SI446X_MAX_TX_POWER);


	Si446x_getInfo(ICinfo);

	//printf("IC info: %d %d %d %d %d %d\n\r", ICinfo -> chipRev, ICinfo->part, ICinfo->partBuild, ICinfo->id, ICinfo->customer, ICinfo->romId);
	

	for(int i=0; i < 128;i++)
	{
		data[i] = rand() % 255;

		printf("%x", data[i]);
	}
	
	printf("\n\r");
	
	delay(5*1000); // wait 5 seconds

	while(1)
	{

		Si446x_TX(data, sizeof(data), 40, SI446X_STATE_RX);
		delay(500); //Wait for 500ms

	}


	return 0;
}
