#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>

int main(void) {

 bcm2835_init();
 bcm2835_spi_begin();


 bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);
 bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);
 bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_65536);
 bcm2835_spi_chipSelect(BCM2835_SPI_CS0);
 bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);

 uint8_t read_data = bcm2835_spi_transfer(0xAA);

 if( read_data== 0xAA) printf("data received correctly");

 bcm2835_spi_end();
 bcm2835_close();
 return (EXIT_SUCCESS);
}
