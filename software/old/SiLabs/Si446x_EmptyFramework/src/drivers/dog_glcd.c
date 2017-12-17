/*! @file dog_glcd.c
 * @brief This file contains functions to control the DOG LCD.
 *
 * @b COPYRIGHT
 * @n Silicon Laboratories Confidential
 * @n Copyright 2012 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 */

#include "..\bsp.h"


#ifdef SILABS_LCD_DOG_GLCD

/*------------------------------------------------------------------------*/
/*  Local Macros & Definitions                                            */
/*------------------------------------------------------------------------*/
#define LCD_BACKLIGHT_IS_USED

/*------------------------------------------------------------------------*/
/*                          Global variables                              */
/*------------------------------------------------------------------------*/
SEGMENT_VARIABLE(fUnderline,          BIT, SEG_DATA) = FALSE;
SEGMENT_VARIABLE(fInvert,             BIT, SEG_DATA) = FALSE;

SEGMENT_VARIABLE(bLcd_CurrentLine,    U8, SEG_IDATA);
SEGMENT_VARIABLE(bLcd_CurrentChPos,   U8, SEG_IDATA);
SEGMENT_VARIABLE(bLcd_CurrentPage,    U8, SEG_IDATA);
SEGMENT_VARIABLE(bLcd_CurrentColumn,  U8, SEG_IDATA);

#ifdef LCD_DRIVER_EXTENDED_SUPPORT
SEGMENT_VARIABLE(LCDBuffer[bLcd_NumOfColumnsMax_c * 3u],  U8, SEG_XDATA);
#endif

/*------------------------------------------------------------------------*/
/*                          Function implementations                      */
/*------------------------------------------------------------------------*/

#if !(defined SOFTTIMER_H_)
/*!
 * This function is used to wait about 2ms.
 *
 * @return  None.
 *
 * @note The delay depends on the clock of the MCU.
 */
void vLcd_Delay2ms(void)
{
	volatile SEGMENT_VARIABLE(Delay, U32, SEG_DATA);

	for (Delay = 0u; Delay < 0x9FFF; Delay++) ;
}

#define LcdDelay(ms) { vLcd_Delay2ms(); vLcd_Delay2ms(); vLcd_Delay2ms(); vLcd_Delay2ms(); vLcd_Delay2ms(); }

#else

/**
 *  Wait about ms x 10ms.
 *
 *  @param[in]  ms Delay (x 10ms).
 *
 *  @note       Blocks code execution until elapses.
 *
 *****************************************************************************/
void LcdDelay(U8 ms)
{
  /* Add Software Timer Channel no. 2 for LCD delay purposes */
  SoftTimer_Add(ms, SOFTTIMER_CH2);
  while (SoftTimer_Elapsed(SOFTTIMER_CH2) == FALSE) ;
}

#endif
/*!
 * This function is used to initialize the LCD for 3.3V operation voltage and SPI comm.
 *
 * @return  None.
 *
 * @note It can be called only 40ms after the VDD is stabilized.
 */
BIT vLcd_InitLcd(void)
{
  vSpi_SetNsel(eSpi_Nsel_LCD);
  LCD_A0    = FALSE;

#ifdef SPI_DRIVER_EXTENDED_SUPPORT
  if (gSpi_SpiLcdDisabled == TRUE)
  {
#if !(defined SPI_PERIPHERALS_ALWAYS_ENABLED)
    mSpi_EnableSpiLcd();
#endif
  }
#endif

  LCD_A0    = FALSE;

  /* perform reset ~10ms */
  LcdDelay(1u);

	vSpi_ClearNsel(eSpi_Nsel_LCD);

	mSpi_ReadWriteSpiLcd(0x40);			// display start line 0
	mSpi_ReadWriteSpiLcd(0xA1);			// ADC reverse
	mSpi_ReadWriteSpiLcd(0xC0);			// normal COM0~COM63
	mSpi_ReadWriteSpiLcd(0xA6);			// display normal
	mSpi_ReadWriteSpiLcd(0xA2);			// set bias 1/9 (Duty 1/65)
	mSpi_ReadWriteSpiLcd(0x2F);			// booster, regulator and follower on
	mSpi_ReadWriteSpiLcd(0xF8);			// set internal booster to 4x
	mSpi_ReadWriteSpiLcd(0x00);


	mSpi_ReadWriteSpiLcd(0x23);			// contrast set
	mSpi_ReadWriteSpiLcd(0x81);
	mSpi_ReadWriteSpiLcd(0x1F);

	mSpi_ReadWriteSpiLcd(0xAC);			// no indicator
	mSpi_ReadWriteSpiLcd(0x00);
	vSpi_SetNsel(eSpi_Nsel_LCD);

	vLcd_LcdOff();
	vLcd_LcdClearDisplay();
	vLcd_LcdOn();

  return TRUE;
}

/*!
 * This function is used to turn on the LCD screen.
 *
 * @return  None.
 */
void vLcd_LcdOn(void)
{
  /* disable global interrupts */
  ENTER_CRITICAL_SECTION;
    
  vSpi_ClearNsel(eSpi_Nsel_LCD);
  mSpi_ReadWriteSpiLcd(0xAF);
  vSpi_SetNsel(eSpi_Nsel_LCD);
    
  /* enable global interrupts  */
  EXIT_CRITICAL_SECTION;
}

/*!
 * This function is used to turn off the LCD
 * screen (the DDRAM content will be kept).
 *
 * @return  None.
 */
void vLcd_LcdOff(void)
{
  /* disable global interrupts */
  ENTER_CRITICAL_SECTION;
    
  vSpi_ClearNsel(eSpi_Nsel_LCD);
  mSpi_ReadWriteSpiLcd(0xAE);
  vSpi_SetNsel(eSpi_Nsel_LCD);

  /* enable global interrupts  */
  EXIT_CRITICAL_SECTION;
}

/*!
 * This function is used to set the page address (0...7).
 *
 * @param[in] bi_DataIn  Page address: the LCD is separated to 8x8 rows
 * and 8 row is called as a page, page0 is the top 8 rows.
 *
 * @return  None.
 */
void vLcd_LcdSetPage(U8 bi_DataIn)
{
  /* disable global interrupts */
  ENTER_CRITICAL_SECTION;
    
  vSpi_ClearNsel(eSpi_Nsel_LCD);
  mSpi_ReadWriteSpiLcd(0xB0 | bi_DataIn);
  vSpi_SetNsel(eSpi_Nsel_LCD);
    
  /* enable global interrupts  */
  EXIT_CRITICAL_SECTION;
}

/*!
 * This function is used to set the column address (0...131).
 *
 * @param[in] bi_DataIn  Column address.
 *
 * @return  None.
 */
void vLcd_LcdSetColumn(U8 bi_DataIn)
{
  /* disable global interrupts */
  ENTER_CRITICAL_SECTION;

  vSpi_ClearNsel(eSpi_Nsel_LCD);
  mSpi_ReadWriteSpiLcd(0x10 | ((bi_DataIn & 0xF0) >> 4));
  mSpi_ReadWriteSpiLcd(0x00 |  (bi_DataIn & 0x0F));
  vSpi_SetNsel(eSpi_Nsel_LCD);

  /* enable global interrupts  */
  EXIT_CRITICAL_SECTION;
}

/*!
 * This function is used to clear the display (the content of the DDRAM).
 *
 * @return  None.
 */
void vLcd_LcdClearDisplay(void)
{
  SEGMENT_VARIABLE(lPage, U8, SEG_DATA);

	for(lPage = 1u; lPage <= bLcd_NumOfLinesMax_c; lPage++) {
	  vLcd_LcdClearLine(lPage);
	}
}

/**
 *  Fills the display (the content of the DDRAM!)
 *
 *  @note
 *
 *****************************************************************************/
void LcdFillDisplay(void)
{
  SEGMENT_VARIABLE(lPage,    U8, SEG_XDATA);
  SEGMENT_VARIABLE(col,    U8, SEG_XDATA);

  ENTER_CRITICAL_SECTION;

  for (lPage = 1u; lPage <= bLcd_NumOfLinesMax_c; lPage++)
  {
    /* select the page */
    vLcd_LcdSetPage(lPage - 1u);
    /* set to the first column */
    vLcd_LcdSetColumn(0u);

    /* set A0 to 1 -> access to the DDRAM */
    LCD_A0    = TRUE;
    vSpi_ClearNsel(eSpi_Nsel_LCD);

    for (col = 0u; col < bLcd_NumOfColumnsMax_c; col++)
    {
      /* clear the selected column */
      mSpi_ReadWriteSpiLcd(0xFF);
    }

    LCD_A0    = FALSE;
    vSpi_SetNsel(eSpi_Nsel_LCD);
  }

  EXIT_CRITICAL_SECTION;
}

/*!
 * This function is used to clear one line on the LCD.
 *
 * @param[in] bi_DataIn  Line address.
 *
 * @return  None.
 */
void vLcd_LcdClearLine(U8 bi_Line)
{
  SEGMENT_VARIABLE(lColumn, U8, SEG_DATA);

  if ((bi_Line < bLcd_NumOfLinesMin_c) || (bi_Line > bLcd_NumOfLinesMax_c)) {
    return;
  }

  //select the page
  vLcd_LcdSetPage(bi_Line - 1);

  //set to the first column
  vLcd_LcdSetColumn(0);

  /* disable global interrupts */
  ENTER_CRITICAL_SECTION;

  //set A0 to 1 -> access to the DDRAM
  LCD_A0 = 1;
  vSpi_ClearNsel(eSpi_Nsel_LCD);
  for (lColumn = 0u; lColumn < bLcd_NumOfColumnsMax_c; lColumn++) {
    //clear the selected column
    mSpi_ReadWriteSpiLcd(0x00);
  }
  LCD_A0 = 0;
  vSpi_SetNsel(eSpi_Nsel_LCD);

  /* enable global interrupts  */
  EXIT_CRITICAL_SECTION;
}

/*!
 * This function is used to write one complete line on the LCD.
 *
 * @param[in] bi_Line  Line address.
 * @param[in] pbi_Text  Pointer to the text (char array).
 *
 * @return  None.
 *
 * @note If the line is invalid, the function returns without any changes.
 * @note The function doesn't set the bLcd_CurrentLine,
 * bLcd_CurrentChPos variables.
 */
void vLcd_LcdWriteLine(U8 biLine, U8 * pbiText)
{
  if ((biLine < bLcd_NumOfLinesMin_c) || (biLine > bLcd_NumOfLinesMax_c)) {
    return;
  }

  vLcd_LcdClearLine(biLine);

  bLcd_CurrentLine = biLine - 1u;
  bLcd_CurrentColumn = 0u;

  vLcd_LcdWrite(pbiText);
}

/**
 *  Sets the LCD text position.
 *
 *  @param[in]  line Line number.
 *
 *  @param[in]  ch_pos Character horizontal position.
 *
 *  @return     \b TRUE - operation was successful <br>
 *              \b FALSE - operation was ignored.
 *
 *  @note
 *
 *****************************************************************************/
BIT gLcd_LcdSetCharCursor(U8 biLine, U8 biChPos)
{
  /* set page address */
  bLcd_CurrentLine = biLine;
  vLcd_LcdSetPage(biLine);

  /* set column address */
  bLcd_CurrentColumn = biChPos * 6u;
  vLcd_LcdSetColumn(bLcd_CurrentColumn);

  return TRUE;
}

/**
 *  Write string to LCD at actual position.
 *
 *  @param[in]  pText String to be written.
 *
 *  @note
 *
 *****************************************************************************/
void vLcd_LcdWrite(U8 * pbi_pText)
{
  SEGMENT_VARIABLE(lTemp  , U8, SEG_DATA);
  SEGMENT_VARIABLE(lColumn, U8, SEG_DATA);
  SEGMENT_VARIABLE(lChar  , U8, SEG_DATA);

  while (*pbi_pText)
  {
    /* Check Position */
    if ((bLcd_CurrentColumn >= bLcd_NumOfColumnsMax_c) || \
        (bLcd_CurrentLine >= bLcd_NumOfLinesMax_c))    {
      bLcd_CurrentColumn = 0u;
      if (++bLcd_CurrentLine >= bLcd_NumOfLinesMax_c) {
        bLcd_CurrentLine = 0u;
      }
    }

    gLcd_LcdSetCharCursor(bLcd_CurrentLine, bLcd_CurrentColumn / 6u);

    if ((*pbi_pText > bLcd_Ascii5x7Max_c) || \
        (*pbi_pText < bLcd_Ascii5x7Min_c)) {
      lTemp = ' ' - bLcd_Ascii5x7Min_c;
    } else {
      lTemp = *pbi_pText - bLcd_Ascii5x7Min_c;
    }
    pbi_pText++;

    /* write character */
    LCD_A0 = TRUE;        /* set A0 to 1 -> access to the DDRAM */
    vSpi_ClearNsel(eSpi_Nsel_LCD);

    for (lColumn = 0u; lColumn < 5u; lColumn++)
    {
      lChar = ascii_table5x7[lTemp][lColumn];

      if (TRUE == fUnderline)  { lChar |= 0x80;  }
      if (TRUE == fInvert)     { lChar = ~lChar; }

      mSpi_ReadWriteSpiLcd(lChar);
    }

    /* space between the characters */
    lChar = 0x00;
    if (TRUE == fUnderline) { lChar |= 0x80;  }
    if (TRUE == fInvert)    { lChar = ~lChar; }
    mSpi_ReadWriteSpiLcd(lChar);

    LCD_A0   = FALSE;
    vSpi_SetNsel(eSpi_Nsel_LCD);

    /* Increment LCD Column position */
    bLcd_CurrentColumn += 6u;
  }
}

/**
 *  Write string to the center of the given line.
 *
 *  @param[in]  line Line number.
 *
 *  @param[in]  pText String to be written.
 *
 *  @note
 *
 *****************************************************************************/
void vLcd_LcdWriteLineCenter(U8 bi_line, U8 * pbi_Text)
{
  SEGMENT_VARIABLE(lIdx, U8, SEG_DATA) = 0u;

  if ((bi_line < bLcd_NumOfLinesMin_c) || (bi_line > bLcd_NumOfLinesMax_c))
  {
    return;
  }

  /* Clear actual line */
  vLcd_LcdClearLine(bi_line);

  /* Count characters */
  while (*(pbi_Text + lIdx))
  {
    lIdx++;
  }

  if (lIdx < bLcd_NumOfCharsMax_c)
  {
    //bLcd_CurrentColumn = ((bLcd_NumOfCharsMax_c - lIdx) / 2u) * 6u;
    bLcd_CurrentColumn = ((bLcd_NumOfCharsMax_c - lIdx) * 6u) / 2u;
  }
  else
  {
    bLcd_CurrentColumn = 0u;
  }
  bLcd_CurrentLine = bi_line - 1u;

  vLcd_LcdWrite(pbi_Text);
}


/**
 *  Turns on Underline during text write on LCD.
 *
 *  @note
 *
 *****************************************************************************/
void vLcd_LcdSetUnderline()
{
  fUnderline = TRUE;
}

/**
 *  Turns off Underline during text write on LCD.
 *
 *  @note
 *
 *****************************************************************************/
void vLcd_LcdClearUnderline()
{
  fUnderline = FALSE;
}

/**
 *  Sets invert attribute when writing text to LCD.
 *
 *  @note
 *
 *****************************************************************************/
void vLcd_LcdSetInvert()
{
  fInvert = TRUE;
}

/**
 *  Clears invert attribute when writing text to LCD.
 *
 *  @note
 *
 *****************************************************************************/
void vLcd_LcdClearInvert()
{
  fInvert = FALSE;
}


/*!
 * This function is used to set the character position.
 *
 * @param[in] bi_Page  Number of the pages (1...8) the LCD is divided to
 * 8 pages. Page1 is the top page.
 * @param[in] bi_Column  Number of start column. Column1 is the left one.
 *
 * @return  True if operation is successfull.
 *
 * @note If the position is invalid, the function returns without changing the
 * registers.
 * @note The function sets the bLcd_CurrentLine, bLcd_CurrentChPos variables.
 */
U8 bLcd_LcdSetPictureCursor(U8 bi_Page, U8 bi_Column)
{
	//check whether the input parameters are correct
	if ( ((bi_Page < bLcd_NumOfLinesMin_c)     || \
	      (bi_Page > bLcd_NumOfLinesMax_c))    || \
	     ((bi_Column < bLcd_NumOfColumnsMin_c) || \
	      (bi_Column > bLcd_NumOfColumnsMax_c)) ) {
	  return FALSE;
	}

	//set page address
	vLcd_LcdSetPage(bi_Page-1);
	//set column address
	vLcd_LcdSetColumn( bi_Column-1 );
	bLcd_CurrentPage = bi_Page;
	bLcd_CurrentColumn = bi_Column;

	return TRUE;
}

/*!
 * This function is used to draw a picture on the LCD screen.
 *
 * @param[in] pi_Picture  The address of the picture, the picture must be stored
 * in the FLASH.
 *
 * @return  None.
 *
 * @note bLcd_LcdSetPictureCursor(uint8 page, uint8 column) function has to be
 * called before calling this function.
 * @note The function sets the bLcd_CurrentPage and bLcd_CurrentColumn variable.
 */
void vLcd_LcdDrawPicture(const U8 * pi_Picture)
{
  SEGMENT_VARIABLE(pages, U8,   SEG_DATA);
  SEGMENT_VARIABLE(page,  U8,   SEG_DATA);
  SEGMENT_VARIABLE(col,   U8,   SEG_DATA);
  SEGMENT_VARIABLE(ii,    U8,   SEG_DATA);
  SEGMENT_VARIABLE(jj,    U16,  SEG_DATA);

  // checks whether there are enough column for the picture or not
  col = ((bLcd_NumOfColumnsMax_c - bLcd_CurrentColumn + 1) <      \
          pi_Picture[bLcd_PictureColumnNum_c]) ?                  \
              (bLcd_NumOfColumnsMax_c - bLcd_CurrentColumn + 1) : \
              pi_Picture[bLcd_PictureColumnNum_c];

  // check whether there are enough pages for the picture or not
  page = ((bLcd_NumOfLinesMax_c - bLcd_CurrentPage + 1) <         \
           pi_Picture[bLcd_PicturePageNum_c]) ?                   \
               (bLcd_NumOfLinesMax_c - bLcd_CurrentPage + 1) :    \
               pi_Picture[bLcd_PicturePageNum_c];

  // draw the picture
  for (pages = 0u; pages < page; pages++) {
    ENTER_CRITICAL_SECTION;                             // disable global interrupts
        
    LCD_A0 = 1;			//set A0 to 1 -> access to the DDRAM
    vSpi_ClearNsel(eSpi_Nsel_LCD);
    jj = bLcd_PictureAddressOffset_c + pages;
    for (ii = 0u; ii < col; ii++) {
      // write column data
      mSpi_ReadWriteSpiLcd(pi_Picture[jj]);
      jj += pi_Picture[bLcd_PicturePageNum_c];
    }
    LCD_A0 = 0;
    vSpi_SetNsel(eSpi_Nsel_LCD);

    EXIT_CRITICAL_SECTION;                             // enable global interrupts
    //set next page
    bLcd_LcdSetPictureCursor(++bLcd_CurrentPage, bLcd_CurrentColumn);
  }
}

#ifdef LCD_DRIVER_EXTENDED_SUPPORT
void vLcd_LcdDrawVerticalLine(U8 Y1, U8 Y2, U8 X, U8 clr)
{
  SEGMENT_VARIABLE(lTmp, U8, SEG_DATA) = 0u;

  if (Y1 > Y2) {
    return;
  }

  while (((Y1/8u) >= lTmp) && (clr)) {
    bLcd_LcdSetPictureCursor(++lTmp, X + 1u);

    /* Draw line within the same Page */
    LCD_A0   = 1;     //set A0 to 1 -> access to the DDRAM
    LCD_NSEL = 0;
    mSpi_ReadWriteSpiLcd(0x00);
    LCD_A0   = 0;     //set A0 to 1 -> access to the DDRAM
    LCD_NSEL = 1;
  }

  do {
    if ((Y2/8u) > (Y1/8u)) {
      lTmp = (Y1/8u + 1u) * 8u - 1u;
    } else {
      lTmp = Y2;
    }
    bLcd_LcdSetPictureCursor((Y1/8u) + 1u, X + 1u);

    /* Draw line within the same Page */
    LCD_A0   = 1;     //set A0 to 1 -> access to the DDRAM
    LCD_NSEL = 0;
    mSpi_ReadWriteSpiLcd((0xFF << (Y1%8u)) & (0xFF >> (7u - (lTmp%8u))));
    LCD_A0   = 0;     //set A0 to 1 -> access to the DDRAM
    LCD_NSEL = 1;

    if ((Y2/8u) == (Y1/8u)) {
      return;
    }

    Y1 = (Y1/8u + 1u) * 8u;
  } while(TRUE);
}

void vLcd_DrawClearLine(U8 line, U8 column)
{
  SEGMENT_VARIABLE(ii, U16, SEG_DATA);

  if (line >= (sizeof(LCDBuffer) / bLcd_NumOfColumnsMax_c)) {
    return;
  }

  for (ii = (line * bLcd_NumOfColumnsMax_c) + column; \
       ii < ((line + 1) * bLcd_NumOfColumnsMax_c); ii++) {
    LCDBuffer[ii] = 0x00;
  }
}

void vLcd_DrawText(U8 line, U8 col, U8 * pStr)
{
  SEGMENT_VARIABLE(ii, U8, SEG_DATA);
  SEGMENT_VARIABLE(lTemp, U8, SEG_DATA);

  while (*pStr) {
    /* Check Position */
    if ((col >= bLcd_NumOfColumnsMax_c) || \
        (line >= (sizeof(LCDBuffer) / bLcd_NumOfColumnsMax_c)))    {
      bLcd_CurrentColumn = 0u;
      if (++line >= (sizeof(LCDBuffer) / bLcd_NumOfColumnsMax_c)) {
        line = 0u;
      }
    }

    if ((*pStr > bLcd_Ascii5x7Max_c) || \
        (*pStr < bLcd_Ascii5x7Min_c)) {
      lTemp = ' ' - bLcd_Ascii5x7Min_c;
    } else {
      lTemp = *pStr - bLcd_Ascii5x7Min_c;
    }
    pStr++;

    for (ii = 0u; ii < 5u; ii++) {
      LCDBuffer[(line * bLcd_NumOfColumnsMax_c) + col++] = \
              ascii_table5x7[lTemp][ii];
    }
    col++;
  }
}

void vLcd_DrawTextCenter(U8 line, U8 * pStr)
{
  SEGMENT_VARIABLE(lCnt, U8, SEG_DATA) = 0u;

  while (*(pStr + lCnt))  lCnt++;

  if (lCnt > 22u)
    return;

  vLcd_DrawText(line, (bLcd_NumOfColumnsMax_c - (lCnt * 6u)) / 2u, pStr);
}

BIT gLcd_DrawMoveArea(U8 columnStart, U8 columnEnd, U8 dir)
{
  SEGMENT_VARIABLE(lCnt, U16, SEG_DATA);
  static SEGMENT_VARIABLE(lRow, U8, SEG_DATA) = 0u;
  static SEGMENT_VARIABLE(lInvoke, U8, SEG_DATA) = 0u;

  if (++lInvoke > LCD_INVOKE_COUNT) {
    lInvoke = 0u;

    if (dir) {
      for (lCnt = columnStart; lCnt < sizeof(LCDBuffer); lCnt++) {
        if (((lCnt % bLcd_NumOfColumnsMax_c) < columnStart) || \
            ((lCnt % bLcd_NumOfColumnsMax_c) > columnEnd)) {
          continue;
        }

        if ((lCnt >= bLcd_NumOfColumnsMax_c) && (LCDBuffer[lCnt] & 0x01)) {
          LCDBuffer[lCnt - bLcd_NumOfColumnsMax_c] |= 0x80;
        }
        LCDBuffer[lCnt] >>= 1u;
      }
    } else {
      for (lCnt = sizeof(LCDBuffer); lCnt > columnStart; lCnt--) {
        if ((((lCnt - 1u) % bLcd_NumOfColumnsMax_c) < columnStart) || \
            (((lCnt - 1u) % bLcd_NumOfColumnsMax_c) > columnEnd)) {
          continue;
        }

        if (((lCnt - 1u) < (sizeof(LCDBuffer) - bLcd_NumOfColumnsMax_c)) && \
            (LCDBuffer[(lCnt - 1u)] & 0x80)) {
          LCDBuffer[(lCnt - 1u) + bLcd_NumOfColumnsMax_c] |= 0x01;
        }
        LCDBuffer[(lCnt - 1u)] <<= 1u;
      }
    }

    if (++lRow >= 8u) {
      lRow = 0u;
      return TRUE;
    }
  }

  return FALSE;
}

BIT gLcd_DrawInsertLine(U8 column, U8 dir, U8 * pStr)
{
  SEGMENT_VARIABLE(lCnt, U8, SEG_DATA) = 0u;
  static SEGMENT_VARIABLE(lState, U8, SEG_DATA) = 0u;

  switch (lState) {
  case 0u:
    while (*(pStr + lCnt))  lCnt++;

    if (lCnt > (bLcd_NumOfColumnsMax_c - column) / 6u) {
      lState = 0u;

      return TRUE;
    }

    lState++;
    break;

  case 1u:
    if (gLcd_DrawMoveArea(column, bLcd_NumOfColumnsMax_c, dir) == TRUE) {
      lState++;
    }
    break;

  case 2u:
    vLcd_DrawText((dir) ? \
        ((sizeof(LCDBuffer) / bLcd_NumOfColumnsMax_c) - 1u) : 0u, column, pStr);
    lState = 0u;
    return TRUE;
    break;

  default:
    lState = 0u;
    break;
  }

  return FALSE;
}

void vLcd_DrawBuffer(void)
{
  SEGMENT_VARIABLE(ii, U16, SEG_DATA);

  for (ii = 0u; ii < sizeof(LCDBuffer); ii++) {
    if ((ii % bLcd_NumOfColumnsMax_c) == 0u) {
      LCD_A0   = 0;
      LCD_NSEL = 1;
      bLcd_LcdSetPictureCursor(bLcd_NumOfLinesMin_c + \
            (ii / bLcd_NumOfColumnsMax_c), bLcd_NumOfColumnsMin_c);
      LCD_A0   = 1;     //set A0 to 1 -> access to the DDRAM
      LCD_NSEL = 0;
    }
    mSpi_ReadWriteSpiLcd(LCDBuffer[ii]);
  }

  LCD_A0   = 0;
  LCD_NSEL = 1;
}

U8 *pLcd_DrawGetBuffer()
{
  return LCDBuffer;
}

#endif

#endif
