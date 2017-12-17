/*************************************************

This is the main file for the project...

73 & 88 de LA7LKA

*************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "radio.h"
//int main( int argc, char * argv [] ) {
int main(void)
{
	radio_setup();

	radio_test();



	return 0;
}
