/**
 *  Copyright 2008 Silicon Laboratories, Inc.
 *  http://www.silabs.com
 *
 *  @file smbus.c
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
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 *  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *  This software must be used in accordance with the End User License Agreement.
 */

#include "..\bsp.h"

/** Local functions */
void vSmbus_SMBusStart(void);
void vSmbus_SMBusStop(void);

/**
 *  Initialize and enable the SMBus interface.
 *
 *  @note Uses T0 timer to generate the appropriate clock source.
 *        It gives approx. 400 kHz SMBus speed
 ******************************************************************************/
void vSmbus_InitSMBusInterface()
{
  /* Set SMBUS clock speed */
  SetSMBUSClk400kHz_24MHZ5;
  TR0   = 1;                /* START Timer0 */
  /* SMBus Slave Inhibit, Clock from T0 overflow */
  SMB0CF = 0x40;

  /* set auto ACK bit */
  SMB0ADM |= 0x01;

  /* Enable SMBUS0 in CrossBar */
#ifdef SMBUS_TOGGLE_XBAR_ENABLED
  XBR0 |= 0x04;
#endif
  
  /* Disable SMBus interrupt */
  EIE1 &= 0xFE;

  /* Clear flags */
  STA = FALSE;
  STO = FALSE;
  ACK = FALSE;
  SI = FALSE;

  /* Enable SMBus peripheral */
  SMB0CF |= 0x80;
}

/**
 *  Disable the SMBus interface.
 *
 *  @note This function doesn't stop/reset T1 timer.
 ******************************************************************************/
void vSmbus_DisableSMBusInterface()
{
  /* Disable SMBus */
  STA = FALSE;
  STO = FALSE;
  ACK = FALSE;
  SMB0CF &= 0x7F;

  /* Clear IT flag */
  SI = FALSE;

  TR0   = 0;

  /* Disconnect SMBUS0 from CrossBar */
#ifdef SMBUS_TOGGLE_XBAR_ENABLED
  XBR0 &= ~(0x04);
#endif
}

/**
 *  Generate start condition on SMBus.
 *
 *  @note
 ******************************************************************************/
void vSmbus_SMBusStart()
{
  /* Set START bit */
  STA = TRUE;

  /* wait for the start condition */
  while (SI == FALSE);

  /* clear interrupt flag */
  SI = FALSE;
}

/**
 *  Generate stop condition on SMBus.
 *
 *  @note
 ******************************************************************************/
void vSmbus_SMBusStop()
{
  /* Stop SMBus transaction */
  STO = TRUE;
  SI = FALSE;
  while (STO == TRUE);
}

/**
 *  Wait for the SMBus interrupt with timeout.
 *
 *  @return  \b FALSE - Timeout occurred without IT. <br>
 *           \b TRUE - IT occurred within Timeout.
 *
 *  @note
 *
 ******************************************************************************/
BIT gSmbus_SMBusWaitForItWithTimeout()
{
  SEGMENT_VARIABLE(busTimeOut, U16, SEG_DATA);

  /* reset timeout */
  busTimeOut = 0u;

  /* wait for the IT */
  while ((busTimeOut++ < 0xFFFE) && (SI == FALSE))  ;

  if (SI == TRUE) {
    return TRUE;
  }

  /* timeout occured, disable SMBus */
  vSmbus_DisableSMBusInterface();

  return FALSE;
}

/**
 *  Read from the SMBus.
 *
 *  @param[in]  Address 7bit slave address (7 MSB bit is used)
 *  @param[in]  Length Number of bytes to be read.
 *  @param[out] pData Array of data bytes read from the slave.
 *  @return     Result of the transaction, refer to CommIF.h.
 *  @note       The function blocks the code until completion.
 ******************************************************************************/
eSMBusReturnStates qSmbus_SMBusRead(U8 biAddress, U8 biLength, U8 * pboData)
{
  /* enable SMBus */
  vSmbus_InitSMBusInterface();

  /* START condition */
  STO = FALSE;
  ACK = FALSE;
  STA = TRUE;

  /* wait for START to be completed */
  if (!gSmbus_SMBusWaitForItWithTimeout()) {
    return SMBUS_TIMEOUT_ERROR;
  }

  /* send address byte */
  SMB0DAT = (U8) (biAddress << 1u) | 0x01;

  /* clear IT flag */
  SI = FALSE;
  /* delete start bit */
  STA = FALSE;

  /* wait address byte to be sent */
  if (!gSmbus_SMBusWaitForItWithTimeout()) {
    return SMBUS_TIMEOUT_ERROR;
  }

  if (FALSE == ACK) {
    /* Slave address is not acknowledged */
    vSmbus_DisableSMBusInterface();

    return SMBUS_WRONG_SLAVE_ADDRESS;
  }

  /* read data bytes */
  while (biLength--) {
    if (biLength > 0u) {
      /* More bytes to read */
      ACK = TRUE;
    } else {
      /* Last byte */
      ACK = FALSE;
    }

    /* clear IT flag */
    SI = FALSE;
    /* wait for receiving the next byte */
    if (!gSmbus_SMBusWaitForItWithTimeout()) {
      /* timeout occured */
      return SMBUS_TIMEOUT_ERROR;
    }

    *pboData++ = SMB0DAT;
  }

  /* all data byte read */
  vSmbus_SMBusStop();
  vSmbus_DisableSMBusInterface();

  return SMBUS_RX_FINISHED;
}

/**
 *  Send a given number of bytes on SMBus to the given address.
 *
 *  @param[in] Address 7bit slave address (7 MSB bit is used).
 *  @param[in] Length Number of bytes to be sent.
 *  @param[in] pData Pointer to data bytes to be sent.
 *  @return    Result of the transaction, refer to CommIF.h
 *  @note      The function blocks the flow until completion.
 ******************************************************************************/
eSMBusReturnStates qSmbus_SMBusWrite(U8 biAddress, U8 biLength, U8 * pbiData)
{
  /* enable SMBus */
  vSmbus_InitSMBusInterface();

  /* START condition */
  STO = FALSE;
  ACK = FALSE;
  STA = TRUE;

  /* wait for START to be completed */
  if (!gSmbus_SMBusWaitForItWithTimeout()) {
    return SMBUS_TIMEOUT_ERROR;
  }

  /* send address byte */
  SMB0DAT = (U8) (biAddress << 1u) & 0xFE;

  /* clear IT flag */
  SI = FALSE;
  /* delete start bit */
  STA = FALSE;
  /* wait address byte to be sent */
  if (!gSmbus_SMBusWaitForItWithTimeout()) {
    return SMBUS_TIMEOUT_ERROR;
  }

  if (FALSE == ACK) {
    /* Slave address is not acknowledged */
    vSmbus_DisableSMBusInterface();

    return SMBUS_WRONG_SLAVE_ADDRESS;
  }

  /* send data bytes */
  while (biLength--) {
    /* send next data bytes */
    SMB0DAT = *pbiData++;

    /* clear IT flag */
    SI = FALSE;
    /* wait data to be sent */
    if (!gSmbus_SMBusWaitForItWithTimeout()) {
      return SMBUS_TIMEOUT_ERROR;
    }

    if (TRUE == ARBLOST) {
      /* arbritation lost */
      vSmbus_DisableSMBusInterface();

      return SMBUS_ARBITRATION_LOST;
    }
  }

  /* all data byte sent */
  vSmbus_SMBusStop();
  vSmbus_DisableSMBusInterface();

  return SMBUS_TRANSMISSION_OK;
}
