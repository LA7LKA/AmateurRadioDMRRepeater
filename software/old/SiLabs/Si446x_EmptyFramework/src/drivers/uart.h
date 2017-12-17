/**
 *  Copyright 2008 Silicon Laboratories, Inc.
 *  http://www.silabs.com
 *
 *  @file uart.h
 *  
 *  Header File Description:
 *  @brief TODO
 *
 *  Project Name: EZRADIO SI4x55 EXAMPLES
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

#ifndef UART_H_
#define UART_H_

/*****************************************************************************
 *  Global Macros & Definitions
 *****************************************************************************/

/*! UART RX Buffer size */
#ifndef COMM_IF_UART_RX_BUFFER
#define COMM_IF_UART_RX_BUFFER  64u
#endif

/*! UART TX Buffer size */
#ifndef COMM_IF_UART_TX_BUFFER
#define COMM_IF_UART_TX_BUFFER  64u
#endif

/*! Macro to set the UART baud rate to 115200bps (with 30MHz XTAL) */
#if !(defined SILABS_MCU_F912)
#define Set115200bps_24MHZ5     CKCON &= 0xF4; CKCON |=  0x08; \
                                TH1    = 0x96; TMOD  &= ~0xF0; \
                                TMOD  |= 0x20
#else
// On F912 TH1 needs to set to 0x90. The osc freq seems to be 25.85MHz. Bad parts???
#define Set115200bps_24MHZ5     CKCON &= 0xF4; CKCON |=  0x08; \
                                TH1    = 0x90; TMOD  &= ~0xF0; \
                                TMOD  |= 0x20
#endif

/*****************************************************************************
 *  Global Enums & Typedefs
 *****************************************************************************/
typedef struct
{
  U8  TXWritePosition;
  U8  TXReadPosition;
  U8  TXBufferEmpty;
  U8  RXWritePosition;
  U8  RXReadPosition;
  U8  RXBuffer[COMM_IF_UART_RX_BUFFER];
  U8  TXBuffer[COMM_IF_UART_TX_BUFFER];
} tUartData;

/*****************************************************************************
 *  Global Function Declarations
 *****************************************************************************/
U8 Comm_IF_RecvUART(U8 *);
U8 Comm_IF_SendUART(U8);

void Comm_IF_EnableUART(void);

/*****************************************************************************
 *  Interrupt function prototype
 *****************************************************************************/
#ifdef UART_DRIVER_EXTENDED_SUPPORT
  INTERRUPT_PROTO(UART_ISR,  INTERRUPT_UART0);
#endif

#endif /* UART_H_ */
