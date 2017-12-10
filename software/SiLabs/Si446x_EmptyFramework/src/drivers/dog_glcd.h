/*! @file dog_glcd.h
 * @brief This file is the interface file for LCD routines.
 *
 * @b COPYRIGHT
 * @n Silicon Laboratories Confidential
 * @n Copyright 2012 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 */

#ifndef DOG_GLCD_H
#define DOG_GLCD_H

/*------------------------------------------------------------------------*/
/*                          Global definitions                            */
/*------------------------------------------------------------------------*/

#define bLcd_NumOfLinesMin_c  (1u)
#define bLcd_NumOfLinesMax_c  (4u)
#define bLcd_NumOfCharsMin_c  (1u)
#define bLcd_NumOfCharsMax_c  (22u)
#define bLcd_NumOfColumnsMin_c  (1u)
#define bLcd_NumOfColumnsMax_c  (132u)
#define bLcd_PicturePageNum_c   (0u)
#define bLcd_PictureColumnNum_c (1u)
#define bLcd_PictureAddressOffset_c   (2u)

#define bLcd_Line1_c  (1u)
#define bLcd_Line2_c  (2u)
#define bLcd_Line3_c  (3u)
#define bLcd_Line4_c  (4u)

#define bLcd_Ascii5x7Min_c  (0x20)
#define bLcd_Ascii5x7Max_c  (0x82)

#ifdef LCD_DRIVER_EXTENDED_SUPPORT
#define LCD_INVOKE_COUNT  (1u)
#endif

#if (defined SILABS_MCU_DC_EMIF_F930) || (defined SILABS_PLATFORM_WMB)
  #define mSpi_ReadWriteSpiLcd(biDataIn) bSpi_ReadWriteSpi0(biDataIn)
  #define mSpi_EnableSpiLcd(biDataIn)    vSpi_EnableSpi0()
  #define gSpi_SpiLcdDisabled            gSpi_Spi0Disabled
#else
  #define mSpi_ReadWriteSpiLcd(biDataIn) bSpi_ReadWriteSpi1(biDataIn)
  #define mSpi_EnableSpiLcd(biDataIn)    vSpi_EnableSpi1()
  #define gSpi_SpiLcdDisabled            gSpi_Spi1Disabled
#endif

/*------------------------------------------------------------------------*/
/*                          External variables                            */
/*------------------------------------------------------------------------*/

extern SEGMENT_VARIABLE(abLcd_LcdData[bLcd_NumOfCharsMax_c + 1], U8, SEG_XDATA);

/*------------------------------------------------------------------------*/
/*                           Function prototypes                          */
/*------------------------------------------------------------------------*/

BIT  vLcd_InitLcd(void);
void vLcd_LcdOn(void);
void vLcd_LcdOff(void);
void vLcd_LcdSetPage(U8 bi_DataIn);
void vLcd_LcdSetColumn(U8 bi_DataIn);
void vLcd_LcdClearDisplay(void);
void LcdFillDisplay(void);
void vLcd_LcdClearLine(U8 bi_Line);
void vLcd_LcdWriteLine(U8 bi_Line, U8 * pbi_Text);
U8 bLcd_LcdSetPictureCursor(U8 page, U8 bi_Column);
void vLcd_LcdDrawPicture(const U8 * pi_Picture);

BIT gLcd_LcdSetCharCursor(U8 biLine, U8 biChPos);
void vLcd_LcdWrite(U8 * pbi_pText);
void vLcd_LcdWriteLineCenter(U8 bi_line, U8 * pbi_Text);
void vLcd_LcdSetUnderline();
void vLcd_LcdClearUnderline();
void vLcd_LcdSetInvert();
void vLcd_LcdClearInvert();

#ifdef LCD_DRIVER_EXTENDED_SUPPORT
  void vLcd_LcdDrawVerticalLine(U8 Y1, U8 Y2, U8 X, U8 clr);
  void vLcd_DrawClearLine(U8 line, U8 column);
  void vLcd_DrawText(U8 line, U8 col, U8 * pStr);
  void vLcd_DrawTextCenter(U8 line, U8 * pStr);
  BIT gLcd_DrawMoveArea(U8 columnStart, U8 columnEnd, U8 dir);
  BIT gLcd_DrawInsertLine(U8 column, U8 dir, U8 * pStr);
  void vLcd_DrawBuffer(void);
  U8 *pLcd_DrawGetBuffer(void);
#else
  #define vLcd_DrawClearLine(line, column)    do \
                      { vLcd_LcdClearLine((line) + 1u); } while (0)
  #define vLcd_DrawText(line, col, pStr)      do \
                      { gLcd_LcdSetCharCursor(line, (col) / 6u); \
                        vLcd_LcdWrite(pStr); } while(0)
  #define vLcd_DrawTextCenter(line, pStr)     do \
                      { vLcd_LcdWriteLineCenter((line) + 1u, pStr); } while(0)
  #define gLcd_DrawInsertLine(column, dir, pStr)         TRUE // TODO
  #define gLcd_DrawMoveArea(columnStart, columnEnd, dir) TRUE // TODO
  #define vLcd_DrawBuffer()                         // TODO
#endif

#ifdef SI4313
#define LCD_MIN_LINE				(1)
#define LCD_MAX_LINE				(4)
#define LCD_MIN_CHAR				(1)
#define LCD_MAX_CHAR				(22)
#endif

#endif
