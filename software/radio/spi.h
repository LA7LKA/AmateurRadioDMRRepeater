/*header file for SPI functions*/

#include "../Setup/hardware.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>



unsigned int *SpiDataTrans(uint8_t reg);

unsigned int *SpiConfigTrans(uint8_t reg);
