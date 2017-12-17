/**
 *  Copyright 2008 Silicon Laboratories, Inc.
 *  http://www.silabs.com
 *
 *  @file smbus.h
 *  
 *  C File Description:
 *  @brief SMBus interface functions
 *
 *  Project Name: sRange 
 * 
 * 
 *  @author Sz. Papp
 *  @author V. Huszár
 *
 *  @date 2013.05.27.
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

#ifndef SMBUS_H_
#define SMBUS_H_

/*****************************************************************************
 *  Global Macros & Definitions
 *****************************************************************************/
/*! Macro to set the SMBUS clock 400kHz (with 24.5MHz internal precision clock) */
#if !(defined SILABS_MCU_F912)
  #define SetSMBUSClk400kHz_24MHZ5     CKCON &= 0xFB; CKCON |= 0x04; \
                                       TH0    = 0xEC; TMOD  &= 0xF0; \
                                       TMOD  |= 0x02
#else
  #define SetSMBUSClk400kHz_24MHZ5     CKCON &= 0xFB; CKCON |= 0x04; \
                                       TH0    = 0xEA; TMOD  &= 0xF0; \
                                       TMOD  |= 0x02
#endif
/* SMBus function map for DCPModule */
//todo: Move it to DCP specific header file
#define Comm_IF_InitSMBusInterface()    vSmbus_InitSMBusInterface()
#define Comm_IF_DisableSMBusInterface() vSmbus_DisableSMBusInterface()
#define Comm_IF_SMBusStart()            vSmbus_SMBusStart()
#define Comm_IF_SMBusStop()             vSmbus_SMBusStop()
#define Comm_IF_SMBusWriteByte(biData)  qSmbus_SMBusWriteByte(biData)
#define Comm_IF_SMBusReadByte(giAckReq) bSmbus_SMBusReadByte(giAckReq)

#define Comm_IF_SMBusWrite(biAddress, biLength, pbiData)    \
                            qSmbus_SMBusWrite(biAddress, biLength, pbiData)
#define Comm_IF_SMBusRead(biAddress, biLength, pboData)     \
                            qSmbus_SMBusRead(biAddress, biLength, pboData)
#define Comm_IF_SMBusWaitForItWithTimeout()                 \
                            gSmbus_SMBusWaitForItWithTimeout()
 

/*****************************************************************************
 *  Global Enums & Typedefs
 *****************************************************************************/

typedef enum
{
  SMBUS_TRANSMISSION_OK,
  SMBUS_RX_FINISHED,
  SMBUS_ARBITRATION_LOST,
  SMBUS_TIMEOUT_ERROR,
  SMBUS_BUSY,
  SMBUS_WRONG_SLAVE_ADDRESS,
  SMBUS_NACK_RECEIVED,
  SMBUS_ACK_RECEIVED,
  SMBUS_GENERAL_ERROR
} eSMBusReturnStates;

/*****************************************************************************
 *  Global Function Declarations
 *****************************************************************************/

void vSmbus_InitSMBusInterface(void);
void vSmbus_DisableSMBusInterface(void);
BIT  gSmbus_SMBusWaitForItWithTimeout(void);

eSMBusReturnStates qSmbus_SMBusWrite(U8 biAddress, U8 biLength, U8 * pbiData);
eSMBusReturnStates qSmbus_SMBusRead(U8 biAddress, U8 biLength, U8 * pboData);


#endif /* SMBUS_H_ */
