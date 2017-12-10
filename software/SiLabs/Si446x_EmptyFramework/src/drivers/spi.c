/*! @file spi.c
 * @brief This file contains functions for controlling SPI0 and SPI1 interfaces.
 *
 * @b COPYRIGHT
 * @n Silicon Laboratories Confidential
 * @n Copyright 2012 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 */

#include "..\bsp.h"

/*------------------------------------------------------------------------*/
/*                          Global variables                              */
/*------------------------------------------------------------------------*/
#if ((defined SILABS_MCU_DC_MLCD) || (defined SILABS_LCD_DOG_GLCD))
/**< Current state of the NSEL of SPI0 */
SEGMENT_VARIABLE(bSpi_SelectStateSpi0, U8 , SEG_DATA);
/**< Current state of SPI0 */
BIT gSpi_Spi0Disabled;
#endif

/**< Current state of the NSEL of SPI1 */
SEGMENT_VARIABLE(bSpi_SelectStateSpi1, U8 , SEG_DATA);
/**< Current state of SPI1 */
BIT gSpi_Spi1Disabled;

/*------------------------------------------------------------------------*/
/*                          Function implementations                      */
/*------------------------------------------------------------------------*/

#if ((defined SILABS_MCU_DC_MLCD) || (defined SILABS_LCD_DOG_GLCD))
  /*!
   * This function is used to read/write one byte from/to SPI0.
   *
   * @param[in] biDataIn    Data to be sent.
   * @return  Read value of the SPI port after writing on it.
   */
  #if !(defined SILABS_PLATFORM_WMB912)
  U8 bSpi_ReadWriteSpi0(U8 biDataIn)
  {
    SEGMENT_VARIABLE(bValue, U8, SEG_DATA);
    BIT gRestoreEA;

  #ifdef SILABS_MCU_F960
    SEGMENT_VARIABLE(bRestoreSfrPage, U8, SEG_DATA);
  #endif

    // disable interrupts during SPI transfer
    gRestoreEA = EA;
    EA = 0;

  #ifdef SILABS_MCU_F960
    // save SFR page and switch to SPI1 page
    bRestoreSfrPage = SFRPAGE;
    SFRPAGE = LEGACY_PAGE ;
  #endif

    // Send SPI data using double buffered write
    SPIF0 = 0;                                    // clear SPIF
    SPI0DAT = ( biDataIn );                       // write data register
    while (!TXBMT0);                              // wait on TXBMT
    while ((SPI0CFG & M_SPIBSY0) == M_SPIBSY0);   // wait on SPIBSY
    bValue = SPI0DAT;                             // read value
    SPIF0 = 0;                                    // leave SPIF cleared

  #ifdef SILABS_MCU_F960
    // Restore SFR page after SPI transfer
    SFRPAGE = bRestoreSfrPage;
  #endif

    // Restore interrupts after SPI transfer
    EA = gRestoreEA;

    return bValue;
  }
  #endif //#if !(defined SILABS_PLATFORM_WMB912)

#endif //#if ((defined SILABS_MCU_DC_MLCD) || (defined SILABS_LCD_DOG_GLCD))

/*!
 * This function is used to read/write one byte from/to SPI1.
 *
 * @param[in] biDataIn    Data to be sent.
 * @return  Read value of the SPI port after writing on it.
 */
U8 bSpi_ReadWriteSpi1(U8 biDataIn)
{  
  SEGMENT_VARIABLE(bValue, U8, SEG_DATA);
  BIT gRestoreEA;

#ifdef SILABS_MCU_F960
  SEGMENT_VARIABLE(bRestoreSfrPage, U8, SEG_DATA);
#endif

  /* disable interrupts during SPI transfer */
  gRestoreEA = EA;
  ENTER_CRITICAL_SECTION;

#ifdef SILABS_MCU_F960
  // save SFR page and switch to SPI1 page
  bRestoreSfrPage = SFRPAGE;
  SFRPAGE = LEGACY_PAGE ;
#endif

  // Send SPI data using double buffered write
  SPIF1 = 0;                                    // clear SPIF
  SPI1DAT = ( biDataIn );                       // write data register
  while (!TXBMT1);                              // wait on TXBMT
  while ((SPI1CFG & M_SPIBSY1) == M_SPIBSY1);   // wait on SPIBSY
  bValue = SPI1DAT;                             // read value
  SPIF1 = 0;                                    // leave SPIF cleared

  // Restore interrupts after SPI transfer
  EA = gRestoreEA;

  return bValue;
}



#if ((defined SILABS_MCU_DC_MLCD) || (defined SILABS_LCD_DOG_GLCD))
/*!
 * This function is used to send data over SPI0 no response expected.
 *
 *  @param[in] biDataInLength  The length of the data.
 *  @param[in] *pabiDataIn     Pointer to the first element of the data.
 *
 *  @return None
 */
void vSpi_WriteDataSpi0(U8 biDataInLength, U8 *pabiDataIn)
{
  while (biDataInLength--) {
    bSpi_ReadWriteSpi0(*pabiDataIn++);
  }
}
#endif

/*!
 * This function is used to send data over SPI1 no response expected.
 *
 *  @param[in] biDataInLength  The length of the data.
 *  @param[in] *pabiDataIn     Pointer to the first element of the data.
 *
 *  @return None
 */
void vSpi_WriteDataSpi1(U8 biDataInLength, U8 *pabiDataIn)
{
#ifdef SILABS_MCU_F960
  #warning Check if implemenations of DMA makes sense for SPI on F960!
#endif

  while (biDataInLength--) {
    bSpi_ReadWriteSpi1(*pabiDataIn++);
  }
}

#if ( ((defined SILABS_MCU_DC_MLCD) || (defined SILABS_LCD_DOG_GLCD)) && !(defined SILABS_PLATFORM_WMB912) )
/*!
 * This function is used to read data from SPI0.
 *
 *  \param[in] biDataOutLength  The length of the data.
 *  \param[out] *paboDataOut    Pointer to the first element of the response.
 *
 *  \return None
 */
void vSpi_ReadDataSpi0(U8 biDataOutLength, U8 *paboDataOut)
{
  while (biDataOutLength--) {
    *paboDataOut++ = bSpi_ReadWriteSpi0(0xFF);
  }
}
#endif

/*!
 * This function is used to read data from SPI1.
 *
 *  \param[in] biDataOutLength  The length of the data.
 *  \param[out] *paboDataOut    Pointer to the first element of the response.
 *
 *  \return None
 */
void vSpi_ReadDataSpi1(U8 biDataOutLength, U8 *paboDataOut)
{
#ifdef SILABS_MCU_F960
  #warning Check if implemenations of DMA makes a sense for SPI on F960!
#endif

  // send command and get response from the radio IC
  while (biDataOutLength--) {
    *paboDataOut++ = bSpi_ReadWriteSpi1(0xFF);
  }
}


  /**
 *  Pull down nSEL of the selected device.
 *
 *  @param[in] qiSelect Device select.
 *
 *  @note Input: qiSelect <br> 0 - \b DUT <br> 1 - \b LCD <br>
 *
 ******************************************************************************/
void vSpi_ClearNsel(eSpi_Nsel qiSelect)
{
  switch (qiSelect)
  {
      case eSpi_Nsel_RF:
        RF_NSEL = FALSE;
        break;

#if ((defined SILABS_MCU_DC_MLCD) || (defined SILABS_LCD_DOG_GLCD))
      case eSpi_Nsel_LCD:
        LCD_NSEL = FALSE;
        break;
#endif

      default:
        break;
  }
}


/**
 *  Pull-up nSEL of the selected device.
 *
 *  @param[in] qiSelect Device select.
 *
 *  @note Input: qiSelect <br> 0 - \b DUT <br> 1 - \b LCD <br>
 *
 ******************************************************************************/
void vSpi_SetNsel(eSpi_Nsel qiSelect)
{
  switch (qiSelect)
  {
      case eSpi_Nsel_RF:
        RF_NSEL = TRUE;
        break;

#if ((defined SILABS_MCU_DC_MLCD) || (defined SILABS_LCD_DOG_GLCD))
      case eSpi_Nsel_LCD:
        LCD_NSEL = TRUE;
        break;
#endif

      default:
        break;
  }
}

#ifdef SPI_DRIVER_EXTENDED_SUPPORT
/**
 *  Writes one byte to the SPI1 peripheral and reads one byte at the same time.
 *
 *  @param[in] biDataIn Data to be written.
 *
 *  @return    Data read from SPI1.
 *
 *  @note
 ******************************************************************************/
U8 bSpi_ReadWriteByteSpi1(U8 biDataIn)
{
  SEGMENT_VARIABLE(bReadValue, U8, SEG_DATA);

  /* disable global interrupts */
  ENTER_CRITICAL_SECTION;

  /* select device */
  vSpi_ClearNsel( eSpi_Nsel_RF );
  bReadValue = bSpi_ReadWriteSpi1(biDataIn);
  vSpi_SetNsel( eSpi_Nsel_RF );

  /* enable global interrupts */
  EXIT_CRITICAL_SECTION;

  return bReadValue;
}


/**
 *  Read/Write 16 bits to the selected device.
 *
 *  @param[in] biAddress Address of the register.
 *
 *  @param[in] biDataIn Data to be written.
 *
 *  @return    Data read from SPI1.
 *
 *  @note
 ******************************************************************************/
U16 bSpi_ReadWriteWordSpi1(U8 biAddress, U8 biDataIn)
{
  SEGMENT_VARIABLE(rwReadValue, UU16, SEG_DATA);

  /* disable global interrupts */
  ENTER_CRITICAL_SECTION;

  /* select device */
  vSpi_ClearNsel( eSpi_Nsel_RF );
  rwReadValue.U8[MSB] = bSpi_ReadWriteSpi1(biAddress);
  rwReadValue.U8[LSB] = bSpi_ReadWriteSpi1(biDataIn);
  vSpi_SetNsel( eSpi_Nsel_RF );

  /* enable global interrupts */
  EXIT_CRITICAL_SECTION;

  return rwReadValue.U16;
}

/**
 *  Read/Write several number of bytes into the selected device.
 *
 *  @param[in]  biAddress Starting address; MSB defines whether it is read or write!
 *  @param[in]  biLength Number of registers have to be written.
 *  @param[in]  pbiData Pointer to the source of the registers.
 *  @param[out] pboData Bytes read during transaction.
 *
 *  @note       Read or write bit has to be set!
 ******************************************************************************/
void bSpi_ReadWriteBurstSpi1(U8 biAddress, U8 biLength, U8 *pbiData, U8 *pboData)
{
  SEGMENT_VARIABLE(ii, U8, SEG_DATA);

  /* disable global interrupts */
  ENTER_CRITICAL_SECTION;

  /* select device */
  vSpi_ClearNsel( eSpi_Nsel_RF );
  /* send the register address */
  bSpi_ReadWriteSpi1(biAddress);
  /* send register content */
  for (ii = 0u; ii < biLength; ++ii) {
    *pboData++ = bSpi_ReadWriteSpi1(*pbiData++);
  }
  vSpi_SetNsel( eSpi_Nsel_RF );

  /* enable global interrupts */
  EXIT_CRITICAL_SECTION;

}

#if (!(defined SILABS_PLATFORM_DISABLE_SPI0) && ((defined SILABS_MCU_DC_MLCD) || (defined SILABS_LCD_DOG_GLCD)))
  /*!
   * This function is used to enable SPI0 and associate to XBAR.
   *
   * @return  None.
   */
  void vSpi_EnableSpi0(void)
  {
  #ifdef SILABS_MCU_F960
    SEGMENT_VARIABLE(bRestoreSfrPage, U8, SEG_DATA);
  #endif

  #ifdef SILABS_MCU_F960
    // save SFR page and switch to SPI1 page
    bRestoreSfrPage= SFRPAGE;
    SFRPAGE = LEGACY_PAGE;
  #endif

    //enable SPI port
    SPI0CN |= M_SPI0EN;

    //associate to the XBAR
    XBR0 |= M_SPI0E;
    //configure IO pins
#if (defined SILABS_PLATFORM_RFSTICK)
    P0SKIP  &= (~M_P0_SPI0_SCK) & (~M_P0_SPI0_MISO) & (~M_P0_SPI0_MOSI);
#else
    PXSKIP_SPI0_MOSI &= (~MASK_SPI0_MOSI);
#if !(defined SILABS_PLATFORM_WMB912)
    PXSKIP_SPI0_MISO &= (~MASK_SPI0_MISO);
#endif
    PXSKIP_SPI0_SCK  &= (~MASK_SPI0_SCK);
#endif
    //set default state for pins
    SPI0_SCK = 1;
    SPI0_MOSI = 1;
    gSpi_Spi0Disabled = 0;

  #ifdef SILABS_MCU_F960
    // Restore SFR page after SPI transfer
    SFRPAGE = bRestoreSfrPage;
  #endif
  }
  #endif

  /*!
   * This function is used to enable SPI1 and associate to XBAR.
   *
   * @return  None.
   */
  void vSpi_EnableSpi1(void)
  {
  #ifdef SILABS_MCU_F960
    SEGMENT_VARIABLE(bRestoreSfrPage, U8, SEG_DATA);
  #endif

  #ifdef SILABS_MCU_F960
    // save SFR page and switch to SPI1 page
    bRestoreSfrPage= SFRPAGE;
    SFRPAGE = SPI1_PAGE;
  #endif

    //enable SPI port
    SPI1CN |= M_SPI1EN;

  #ifdef SILABS_MCU_F960
    SFRPAGE = LEGACY_PAGE;
  #endif

    //associate to the XBAR
    XBR1 |= M_SPI1E;
    //configure IO pins
#if (defined SILABS_PLATFORM_RFSTICK)
    P1SKIP  &= (~M_P1_SPI1_SCK) & (~M_P1_SPI1_MISO) & (~M_P1_SPI1_MOSI);
#else
    PXSKIP_SPI1_MOSI &= (~MASK_SPI1_MOSI);
    PXSKIP_SPI1_MISO &= (~MASK_SPI1_MISO);
    PXSKIP_SPI1_SCK  &= (~MASK_SPI1_SCK);
#endif
    //set default state for pins
    SPI1_SCK = 1;
    SPI1_MOSI = 1;
    gSpi_Spi1Disabled = 0;

  #ifdef SILABS_MCU_F960
    // Restore SFR page after SPI transfer
    SFRPAGE = bRestoreSfrPage;
  #endif
  }

  #if (!(defined SILABS_PLATFORM_DISABLE_SPI0) && ((defined SILABS_MCU_DC_MLCD) || (defined SILABS_LCD_DOG_GLCD)))
  /*!
   * This function is used to disable SPI0 and disconnect from XBAR.
   *
   * @return  None.
   */
  void vSpi_DisableSpi0(void)
  {
  #ifdef SILABS_MCU_F960
    SEGMENT_VARIABLE(bRestoreSfrPage, U8, SEG_DATA);
  #endif

  #ifdef SILABS_MCU_F960
    // save SFR page and switch to SPI1 page
    bRestoreSfrPage= SFRPAGE;
    SFRPAGE = LEGACY_PAGE;
  #endif

    //disable SPI port
    SPI0CN &= (~M_SPI0EN);

    //disconnect from XBAR
    XBR0 &= (~M_SPI0E);
    //configure IO port directions
#if (defined SILABS_PLATFORM_RFSTICK)
    P0SKIP  |= M_P0_SPI0_SCK | M_P0_SPI0_MISO | M_P0_SPI0_MOSI;
#else
    PXSKIP_SPI0_MOSI |= (MASK_SPI0_MOSI);
#if !(defined SILABS_PLATFORM_WMB912)
    PXSKIP_SPI0_MISO |= (MASK_SPI0_MISO);
#endif
    PXSKIP_SPI0_SCK  |= (MASK_SPI0_SCK);
#endif    //set default state for the pins
    SPI0_SCK = FALSE;
    SPI0_MOSI = TRUE;
    gSpi_Spi0Disabled = FALSE;

  #ifdef SILABS_MCU_F960
    // Restore SFR page after SPI transfer
    SFRPAGE = bRestoreSfrPage;
  #endif
  }
  #endif

  /*!
   * This function is used to disable SPI1 and disconnect from XBAR.
   *
   * @return  None.
   */
  void vSpi_DisableSpi1(void)
  {

  #ifndef SPI_PERIPHERALS_ALWAYS_ENABLED
  
  #ifdef SILABS_MCU_F960
    SEGMENT_VARIABLE(bRestoreSfrPage, U8, SEG_DATA);
  #endif

  #ifdef SILABS_MCU_F960
    // save SFR page and switch to SPI1 page
    bRestoreSfrPage= SFRPAGE;
    SFRPAGE = SPI1_PAGE;
  #endif

    //disable SPI port
    SPI1CN &= (~M_SPI1EN);

  #ifdef SILABS_MCU_F960
    SFRPAGE = LEGACY_PAGE;
  #endif

    //disconnect from XBAR
    XBR1 &= (~M_SPI1E);
    
    //configure IO port directions
#if (defined SILABS_PLATFORM_RFSTICK)
    P1SKIP  |= M_P1_SPI1_SCK | M_P1_SPI1_MISO | M_P1_SPI1_MOSI;
#else
    PXSKIP_SPI1_MOSI |= (MASK_SPI1_MOSI);
    PXSKIP_SPI1_MISO |= (MASK_SPI1_MISO);
    PXSKIP_SPI1_SCK  |= (MASK_SPI1_SCK);
#endif    //set default state for the pins
    
    //set default state for the pins
    SPI1_SCK = FALSE;
    SPI1_MOSI = TRUE;
    gSpi_Spi1Disabled = TRUE;

  #ifdef SILABS_MCU_F960
    // Restore SFR page after SPI transfer
    SFRPAGE = bRestoreSfrPage;
  #endif
  
  #endif
  }
  
#if (!(defined SILABS_PLATFORM_DISABLE_SPI0) && ((defined SILABS_MCU_DC_MLCD) || (defined SILABS_LCD_DOG_GLCD)))
  /*!
   * This function is used to read one byte from SPI0 using bitbang method.
   *
   * @return Read byte
   */
  U8 bSpi_ReadByteBitbangSpi0(void)
  {
      SEGMENT_VARIABLE(bReadByte, U8, SEG_DATA);
      SEGMENT_VARIABLE(bCnt, U8, SEG_DATA);

      bReadByte = FALSE;
      SPI0_SCK = TRUE;
      NOP();
      NOP();
      SPI0_SCK = FALSE;
      NOP();
      for(bCnt = 0; bCnt < 8; bCnt++)
      {
          SPI0_SCK = TRUE;
          bReadByte <<= 1;
          //take sample
#if !(defined SILABS_PLATFORM_WMB912)
          if(TRUE == SPI0_MISO)
          {
            bReadByte |= 0x01;
          }
#endif
          SPI0_SCK = FALSE;
      }

      return bReadByte;
  }
  #endif

  /*!
   * This function is used to read one byte from SPI1 using bitbang method.
   *
   * @return Read byte
   */
  U8 bSpi_ReadByteBitbangSpi1(void)
  {
      SEGMENT_VARIABLE(bReadByte, U8, SEG_DATA);
      SEGMENT_VARIABLE(bCnt, U8, SEG_DATA);

      bReadByte = FALSE;
      SPI1_SCK = TRUE;
      NOP();
      NOP();
      SPI1_SCK = FALSE;
      NOP();
      for(bCnt = 0; bCnt < 8; bCnt++)
      {
          SPI1_SCK = TRUE;
          bReadByte <<= 1;
          //take sample
          if(TRUE == SPI1_MISO)
          {
            bReadByte |= 0x01;
          }
          SPI1_SCK = FALSE;
      }

      return bReadByte;
  }

  /*!
   * This function is used to write specified number of bits to SPI1 using bitbang method.
   *
   * @param[in] biDataIn Input byte of data bits
   * @param[out] biNumOfBits Number of bits to be written to SPI
   *
   * @return None
   */
  void vSpi_WriteBitsBitbangSpi1(U8 biDataIn, U8 biNumOfBits)
  {
      SEGMENT_VARIABLE(bCnt, U8, SEG_DATA);
      SEGMENT_VARIABLE(bMask, U8, SEG_DATA);

      bMask = (0x01 << (biNumOfBits-1));
      for(bCnt = 0; bCnt < biNumOfBits; bCnt++)
      {
          SPI1_SCK = FALSE;
          if((biDataIn & bMask) != 0u)
          {
              SPI1_MOSI = TRUE;
          }
          else
          {
              SPI1_MOSI = FALSE;
          }
          //clock pulse to sample
          SPI1_SCK = TRUE;
          bMask >>= 1;
      }
      SPI1_SCK = FALSE;
  }

#endif


#if ((defined SPI_DRIVER_EXTENDED_SUPPORT) || (defined SILABS_PLATFORM_WMB912))
#if (!(defined SILABS_PLATFORM_DISABLE_SPI0) && ((defined SILABS_MCU_DC_MLCD) || (defined SILABS_LCD_DOG_GLCD)))
  /*!
   * This function is used to write specified number of bits to SPI0 using bitbang method.
   *
   * @param[in] biDataIn Input byte of data bits
   * @param[out] biNumOfBits Number of bits to be written to SPI
   *
   * @return None
   */
  void vSpi_WriteBitsBitbangSpi0(U8 biDataIn, U8 biNumOfBits)
  {
      SEGMENT_VARIABLE(bCnt, U8, SEG_DATA);
      SEGMENT_VARIABLE(bMask, U8, SEG_DATA);

      bMask = (0x01 << (biNumOfBits-1));
      for(bCnt = 0; bCnt < biNumOfBits; bCnt++)
      {
          SPI0_SCK = FALSE;
          if((biDataIn & bMask) != 0u)
          {
              SPI0_MOSI = TRUE;
          }
          else
          {
              SPI0_MOSI = FALSE;
          }
          //clock pulse to sample
          SPI0_SCK = TRUE;
          bMask >>= 1;
      }
      SPI0_SCK = FALSE;
  }
#endif //#if (!(defined SILABS_PLATFORM_DISABLE_SPI0) && ((defined SILABS_MCU_DC_MLCD) || (defined SILABS_LCD_DOG_GLCD)))
#endif //#if ((defined SPI_DRIVER_EXTENDED_SUPPORT) || (defined SILABS_PLATFORM_WMB912))