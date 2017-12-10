/*Hardware defenitions....*/

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>

/*
Connections for one module on vero board

RPI3 pin	| Si4463 module
-----------------------------
11			| 2, SDN
24, CE0_N	| 4, nSEL
21, MISO	| 6, MOSI
19, MOSI	| 7, MISO
23, CLK		| 8, SCK
15, GPIO22	| 9, IRQ


Wiring pi:

http://wiringpi.com/pins/

*/

//			Module pin | Wiring pi
#define		SDN_TX		0
#define 	nSEL_TX		10
#define		IRQ_TX		3



#define SPI_CHAN 0

int InitHardware(void);
