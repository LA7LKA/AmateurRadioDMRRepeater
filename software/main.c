/*************************************************

This is the main file for the project...

73 & 88 de LA7LKA

*************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "Setup/hardware.h"
#include "radio.h"
//int main( int argc, char * argv [] ) {
int main(void)
{



/*
System for taking in arguments from commandline

Arguemnts:

--help lists all options

-CW <xxx.xxxxxx> Sets the module for TX to send continues and which frequency

-RXf <xxx.xxxxxx> Sets the RX frequency for the RX module

-TXf <xxx.xxxxxx> Sets the TX frequency for the TX module

-v verbos mode

-D makes the program run as a Daemon

*/ 

/*
	if(strcmp("--help",argv[1]) == 0)
	{
		printf("Help:\n\r");
		printf("--help lists all options\n\r");
		printf("--help lists all options\n\r");
		printf("--help lists all options\n\r");
		printf("--help lists all options\n\r");
		printf("--help lists all options\n\r");
	}
	
	if(strcmp("-CW",argv[1]) == 0)
	{
		printf("CW...");
		goto done;
	}
	
	if(strcmp("-RXf",argv[1]) == 0)
	{
		printf("RX freq: %s Mhz\n\r", argv[2]);
		//goto done;
	}
	
	if(strcmp("-TXf",argv[3]) == 0)
	{
		printf("TX freq: %s Mhz\n\r", argv[4]);
		goto done;
	}

	done:
*/

	//Setup hardware...

	if(InitHardware())
		printf("Hardware init failed!\n\r");
	else
		printf("Hardware init ok!\n\r");

 // Initialize the Radio
  vRadio_Init();
	printf("Program started!\n\r");

	while(1)
	{
		vRadio_StartTx(0, (uint8_t *)0xff);
		sleep(1);
	}



	return 0;
}
