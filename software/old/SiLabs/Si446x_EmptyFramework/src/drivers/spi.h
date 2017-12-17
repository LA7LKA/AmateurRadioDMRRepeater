/*! @file spi.h
 * @brief This file is the interface file for SPI0 and SPI1 routines.
 *
 * @b COPYRIGHT
 * @n Silicon Laboratories Confidential
 * @n Copyright 2012 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 */

#ifndef SPI_H
#define SPI_H

/*------------------------------------------------------------------------*/
/*                          Global typedefs & definitions                 */
/*------------------------------------------------------------------------*/

/*! SPI device select enum */

typedef enum
{
  eSpi_Nsel_RF,
  eSpi_Nsel_LCD
} eSpi_Nsel;

/*------------------------------------------------------------------------*/
/*                          External variables                            */
/*------------------------------------------------------------------------*/

#if ((defined SILABS_MCU_DC_MLCD) || (defined SILABS_LCD_DOG_GLCD))
extern SEGMENT_VARIABLE(bSpi_SelectStateSpi0, U8 , SEG_DATA);
extern BIT gSpi_Spi0Disabled;
#endif

extern SEGMENT_VARIABLE(bSpi_SelectStateSpi1, U8 , SEG_DATA);
extern BIT gSpi_Spi1Disabled;


/*------------------------------------------------------------------------*/
/*                           Function prototypes                          */
/*------------------------------------------------------------------------*/

#ifdef SPI_DRIVER_EXTENDED_SUPPORT
  #if ((defined SILABS_MCU_DC_MLCD) || (defined SILABS_LCD_DOG_GLCD))
    void vSpi_EnableSpi0(void);
    void vSpi_DisableSpi0(void);
    U8 bSpi_ReadByteBitbangSpi0(void);
    void vSpi_WriteBitsBitbangSpi0(U8 biDataIn, U8 biNumOfBits);
  #endif

  void vSpi_EnableSpi1(void);
  void vSpi_DisableSpi1(void);
  U8 bSpi_ReadByteBitbangSpi1(void);
  void vSpi_WriteBitsBitbangSpi1(U8 biDataIn, U8 biNumOfBits);

  U8 bSpi_ReadWriteByteSpi1(U8 biDataIn);
  U16 bSpi_ReadWriteWordSpi1(U8 biAddress, U8 biDataIn);
  void bSpi_ReadWriteBurstSpi1(U8 biAddress, U8 biLength, U8 *pbiData, U8 *pboData);

#endif

#if ((defined SPI_DRIVER_EXTENDED_SUPPORT) || (defined SILABS_PLATFORM_WMB912))
  #if ((defined SILABS_MCU_DC_MLCD) || (defined SILABS_LCD_DOG_GLCD))
    void vSpi_WriteBitsBitbangSpi0(U8 biDataIn, U8 biNumOfBits);
  #endif
#endif

#if ((defined SILABS_MCU_DC_MLCD) || (defined SILABS_LCD_DOG_GLCD))
  void vSpi_WriteDataSpi0(U8 biDataInLength, U8 *pabiDataIn);

#if !(defined SILABS_PLATFORM_WMB912)
  void vSpi_ReadDataSpi0(U8 biDataOutLength, U8 *paboDataOut);
  U8 bSpi_ReadWriteSpi0(U8 biDataIn);
#else //#if !(defined SILABS_PLATFORM_WMB912)
  #define bSpi_ReadWriteSpi0(biDataIn) vSpi_WriteBitsBitbangSpi0(biDataIn, 8u)
#endif  //#if !(defined SILABS_PLATFORM_WMB912)

#endif //#if ((defined SILABS_MCU_DC_MLCD) || (defined SILABS_LCD_DOG_GLCD))

void vSpi_WriteDataSpi1(U8 biDataInLength, U8 *pabiDataIn);
void vSpi_ReadDataSpi1(U8 biDataOutLength, U8 *paboDataOut);
U8 bSpi_ReadWriteSpi1(U8 biDataIn);

void vSpi_ClearNsel(eSpi_Nsel qiSelect);
void vSpi_SetNsel(eSpi_Nsel qiSelect);

#endif
