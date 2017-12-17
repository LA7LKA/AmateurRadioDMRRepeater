/**
 *  Copyright 2008 Silicon Laboratories, Inc.
 *  http://www.silabs.com
 *
 *  @file uart.c
 *  
 *  Source File Description:
 *  @brief TODO
 *
 *  Project Name: EZRADIO SI4X55 EXAMPLES
 * 
 * 
 *  @author Sz. Papp
 *
 *  @date 2012.08.10.
 *
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 *  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *  This software must be used in accordance with the End User License Agreement.
 */

/*****************************************************************************
 *  Includes
 *****************************************************************************/
#include "..\bsp.h"

/*****************************************************************************
 *  Local variable Declarations
 *****************************************************************************/
#ifdef UART_DRIVER_EXTENDED_SUPPORT
  volatile SEGMENT_VARIABLE(lUartInternal, tUartData, SEG_XDATA);
#endif

/*****************************************************************************
 *  Local Functions Definition
 *****************************************************************************/

/**
 *  Simple UART receive function.
 *
 * @param[out] byte
 *
 * @return
 *
 ******************************************************************************/
U8 Comm_IF_RecvUART(U8 * byte)
{
#ifdef UART_DRIVER_EXTENDED_SUPPORT
  if (lUartInternal.RXReadPosition != lUartInternal.RXWritePosition)
  {
    *byte = lUartInternal.RXBuffer[lUartInternal.RXReadPosition++];

    if (lUartInternal.RXReadPosition >= COMM_IF_UART_RX_BUFFER)
    {
      lUartInternal.RXReadPosition = 0u;
    }

    return TRUE;
  }

  return FALSE;
#else
  while (!RI0)  ;  /* Wait for RX */
  RI0 = 0;
  *byte = SBUF0;

  return TRUE;
#endif
}

/**
 *  Simple UART send function.
 *
 * @param byte
 *
 * @return
 *
 ******************************************************************************/
U8 Comm_IF_SendUART(U8 byte)
{
#ifdef UART_DRIVER_EXTENDED_SUPPORT
  /* Check if buffer is full */
  if ((lUartInternal.TXReadPosition == lUartInternal.TXWritePosition) && (FALSE == lUartInternal.TXBufferEmpty))
  {
    return FALSE;
  }

  /* Write input data byte into buffer */
  lUartInternal.TXBuffer[lUartInternal.TXWritePosition++] = byte;

  /* Increment pointer */
  if (lUartInternal.TXWritePosition >= COMM_IF_UART_TX_BUFFER)
  {
    lUartInternal.TXWritePosition = 0u;
  }

  if (TRUE == lUartInternal.TXBufferEmpty)
  {
    SBUF0 = byte;
  }

  lUartInternal.TXBufferEmpty = FALSE;
#else
  SBUF0 = byte;
  while (!TI0)  ; /* Wait until TX */
  TI0 = 0;
#endif

  return TRUE;
}

/**
 *  Enable and set the UART0 peripheral.
 *
 *  @author Sz. Papp
 *
 *  @note
 *
 ******************************************************************************/
void Comm_IF_EnableUART()
{
  /* Enable UART0 in Crossbar */
  XBR0 |= 0x01;

  /* Timer1 Init for UART baud rate */
  /* the default baud rate is 115200bps */
  Set115200bps_24MHZ5;
  TR1   = 1;                /* START Timer1 */
  TI0   = 1;                /* Transciever ready */

  /* UART init */
  SCON0 = 0x10;

#ifdef UART_DRIVER_EXTENDED_SUPPORT
  /* Enable UART0 IT */
  ES0   = TRUE;

  lUartInternal.TXBufferEmpty = TRUE;
#endif
}

#ifdef UART_DRIVER_EXTENDED_SUPPORT
/**
 *  Interrupt handler for UART0 peripheral.
 *
 *  @author Sz. Papp
 *
 *  @note   Receive Overrun may occur as it not protected against it yet.
 *
 *****************************************************************************/
INTERRUPT(UART_ISR, INTERRUPT_UART0)
{
  if (TI0)
  {
    /* Transmit Interrupt */
    TI0 = FALSE;

    lUartInternal.TXReadPosition++;
    if (lUartInternal.TXReadPosition >= COMM_IF_UART_TX_BUFFER)
    {
      lUartInternal.TXReadPosition = 0u;
    }

    if (lUartInternal.TXReadPosition == lUartInternal.TXWritePosition)
    {
      lUartInternal.TXBufferEmpty = TRUE;
    }
    else
    {
      SBUF0 = lUartInternal.TXBuffer[lUartInternal.TXReadPosition];
    }
  }

  if (RI0)
  {
    /* Receive Interrupt */
    RI0 = FALSE;

    lUartInternal.RXBuffer[lUartInternal.RXWritePosition++] = SBUF0;

    if (lUartInternal.RXWritePosition >= COMM_IF_UART_RX_BUFFER)
    {
      lUartInternal.RXWritePosition = 0u;
    }
  }
}
#endif
