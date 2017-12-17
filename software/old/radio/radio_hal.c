/*!
 * File:
 *  radio_hal.c
 *
 * Description:
 *  This file contains RADIO HAL.
 *
 * Silicon Laboratories Confidential
 * Copyright 2011 Silicon Laboratories, Inc.
 */

                /* ======================================= *
                 *              I N C L U D E              *
                 * ======================================= */

#include "radio_hal.h"

                /* ======================================= *
                 *          D E F I N I T I O N S          *
                 * ======================================= */

                /* ======================================= *
                 *     G L O B A L   V A R I A B L E S     *
                 * ======================================= */

                /* ======================================= *
                 *      L O C A L   F U N C T I O N S      *
                 * ======================================= */

                /* ======================================= *
                 *     P U B L I C   F U N C T I O N S     *
                 * ======================================= */

void radio_hal_AssertShutdown(void)
{

  //PWRDN = 1;
	digitalWrite(SDN_TX, HIGH);

}

void radio_hal_DeassertShutdown(void)
{

  //PWRDN = 0;

	digitalWrite(SDN_TX, LOW);
}

void radio_hal_ClearNsel(void)
{
    //RF_NSEL = 0;
	bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);
}

void radio_hal_SetNsel(void)
{
    //RF_NSEL = 1;
	bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, HIGH);
}

BIT radio_hal_NirqLevel(void)
{
    return RF_NIRQ;
}

void radio_hal_SpiWriteByte(uint8_t byteToWrite)
{
	//printf("radio_hal_SpiWriteByte: %x", byteToWrite);

	if (bcm2835_spi_transfer(byteToWrite) == -1)
	{
	  printf("radio_hal_SpiWriteByte SPI failure: %s\n", strerror (errno));
	 
	}
	
}

uint8_t radio_hal_SpiReadByte(void)
{



	uint8_t result = bcm2835_spi_transfer(0xFF);

	if(result == -1)
	{
	  printf("radio_hal_SpiReadByte SPI failure: %s\n", strerror (errno));
	  return -1;
	}

	return result;
}

void radio_hal_SpiWriteData(uint8_t byteCount, uint8_t* pData)
{
	/*	
	for(uint8_t i = 0; sizeof(pData) > 0;i++)
		printf("radio_hal_SpiWriteData: %x", pData[i]);
	*/
	bcm2835_spi_writenb((char *)pData,(uint32_t)byteCount);

}

void radio_hal_SpiReadData(uint8_t byteCount, uint8_t* pData)
{

	bcm2835_spi_writenb((char *)pData,(uint32_t)byteCount);



}

#ifdef RADIO_DRIVER_EXTENDED_SUPPORT
BIT radio_hal_Gpio0Level(void)
{
  BIT retVal = FALSE;

#ifdef SILABS_PLATFORM_DKMB
  retVal = FALSE;
#endif
#ifdef SILABS_PLATFORM_UDP
  retVal = EZRP_RX_DOUT;
#endif
#if (defined SILABS_PLATFORM_RFSTICK) || (defined SILABS_PLATFORM_LCDBB)
  retVal = RF_GPIO0;
#endif
#if (defined SILABS_PLATFORM_WMB930)
  retVal = FALSE;
#endif
#if defined (SILABS_PLATFORM_WMB912)
  #ifdef SILABS_IO_WITH_EXTENDER
    //TODO
    retVal = FALSE;
  #endif
#endif

  return retVal;
}

BIT radio_hal_Gpio1Level(void)
{
  BIT retVal = FALSE;

#ifdef SILABS_PLATFORM_DKMB
  retVal = FSK_CLK_OUT;
#endif
#ifdef SILABS_PLATFORM_UDP
  retVal = FALSE; //No Pop
#endif
#if (defined SILABS_PLATFORM_RFSTICK) || (defined SILABS_PLATFORM_LCDBB) || (defined SILABS_PLATFORM_WMB930)
  retVal = RF_GPIO1;
#endif
#if defined (SILABS_PLATFORM_WMB912)
  #ifdef SILABS_IO_WITH_EXTENDER
    //TODO
    retVal = FALSE;
  #endif
#endif

  return retVal;
}

BIT radio_hal_Gpio2Level(void)
{
  BIT retVal = FALSE;

#ifdef SILABS_PLATFORM_DKMB
  retVal = DATA_NFFS;
#endif
#ifdef SILABS_PLATFORM_UDP
  retVal = FALSE; //No Pop
#endif
#if (defined SILABS_PLATFORM_RFSTICK) || (defined SILABS_PLATFORM_LCDBB) || (defined SILABS_PLATFORM_WMB930)
  retVal = RF_GPIO2;
#endif
#if defined (SILABS_PLATFORM_WMB912)
  #ifdef SILABS_IO_WITH_EXTENDER
    //TODO
    retVal = FALSE;
  #endif
#endif

  return retVal;
}

BIT radio_hal_Gpio3Level(void)
{
  BIT retVal = FALSE;

#if (defined SILABS_PLATFORM_RFSTICK) || (defined SILABS_PLATFORM_LCDBB) || (defined SILABS_PLATFORM_WMB930)
  retVal = RF_GPIO3;
#elif defined (SILABS_PLATFORM_WMB912)
  #ifdef SILABS_IO_WITH_EXTENDER
    //TODO
    retVal = FALSE;
  #endif
#endif

  return retVal;
}

#endif
