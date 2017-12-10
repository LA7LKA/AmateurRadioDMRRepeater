/*! @file control_IO.c
 * @brief This file contains functions for controlling LEDs and PBs.
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


/*------------------------------------------------------------------------*/
/*                           Local variables                              */
/*------------------------------------------------------------------------*/
#if (!(defined SILABS_PLATFORM_RFSTICK) && !(defined SILABS_PLATFORM_LCDBB))
volatile SEGMENT_VARIABLE(bDelay, U8, SEG_XDATA);
#endif

#if (defined SILABS_IO_WITH_EXTENDER)
typedef union {
  U8 bCio_IoExtCommArrayCmd[bCio_IoExtAddrLength_c + bCio_IoExtCmdLength_c];
  U8 bCio_IoExtCommArrayResp[bCio_IoExtAddrLength_c + bCio_IoExtRespLength_c];
} uIoExtCommArray;

/**< Data array for IO extender communication */
SEGMENT_VARIABLE(bCio_IoExtCommArray, uIoExtCommArray, SEG_DATA);
#else
/**< State holder of IO port*/
SEGMENT_VARIABLE(bCio_IoPortState, U8, SEG_DATA);
#endif

/*------------------------------------------------------------------------*/
/*                             Local macros                               */
/*------------------------------------------------------------------------*/
#if (!(defined SILABS_PLATFORM_RFSTICK) && !(defined SILABS_PLATFORM_LCDBB))
  #define mCio_WaitIOSteadyState  \
                              for (bDelay = 0u; bDelay < 0x01; bDelay++)  ;

  #if (defined SILABS_MCU_DC_EMIF_F930)
    #define mCio_WaitIOSteadyState_long \
                              for (bDelay = 0u; bDelay < 0x3F; bDelay++)  ;
  #endif
#endif

/*------------------------------------------------------------------------*/
/*                          Function implementations                      */
/*------------------------------------------------------------------------*/

/*!
 * This function is used to initialize specific IO port for LED & PB.
 *
 *  @return None
 *
 *  @note It has to be called from the initialization section.
 */
void vCio_InitIO(void)
{
#ifndef SILABS_IO_WITH_EXTENDER
  #if ((defined SILABS_PLATFORM_RFSTICK) || (defined SILABS_PLATFORM_LCDBB))
    bCio_IoPortState = (~M_BZ1); //Config all to '1', but buzzer
    P2 = bCio_IoPortState;
  #elif  (defined SILABS_MCU_DC_EMIF_F930)
    bCio_IoPortState = eHmi_NoLed_c;
    P0 = (P0 & ~M_P0_IO);
  #elif (defined SILABS_PLATFORM_WMB930)
    bCio_IoPortState = (M_LED1) | (M_LED2) | (M_LED3) | (M_LED4);
  #elif (defined SILABS_PLATFORM_WMB912)
    bCio_IoPortState = (M_LED1);
  #else
    #error TO BE WRITTEN FOR OTHER PLARFORMS!
  #endif
#endif
}

/*!
 * This function is used to switch the selected LED on.
 *
 * @param[in] biLedNum  Number of the LED to be switched on (1 ... 4).
 *
 * @return None
 */
void vCio_SetLed(U8 biLedNum)
{
#ifdef SILABS_IO_WITH_EXTENDER
  *((U16*) bCio_IoExtCommArray.bCio_IoExtCommArrayCmd) = \
                                      IOEXT_ADDR_CONTROL_SET_LED_STATE;
#endif

  switch(biLedNum)
  {
    case 1:
    #if (defined SILABS_IO_WITH_EXTENDER)
      *(bCio_IoExtCommArray.bCio_IoExtCommArrayCmd + 2u) = eCio_Led1_c;
    #else
      LED1 = ILLUMINATE;
      bCio_IoPortState &= (~M_LED1);
    #endif
      break;

    case 2:
    #if (defined SILABS_IO_WITH_EXTENDER)
      *(bCio_IoExtCommArray.bCio_IoExtCommArrayCmd + 2u) = eCio_Led2_c;
    #elif !(defined SILABS_PLATFORM_WMB912)
      bCio_IoPortState &= (~M_LED2);
      LED2 = ILLUMINATE;
    #endif
      break;

    case 3:
    #if (defined SILABS_IO_WITH_EXTENDER)
      *(bCio_IoExtCommArray.bCio_IoExtCommArrayCmd + 2u) = eCio_Led3_c;
    #elif !(defined SILABS_PLATFORM_WMB912)
      bCio_IoPortState &= (~M_LED3);
      LED3 = ILLUMINATE;
    #endif
      break;

    case 4:
    #if (defined SILABS_IO_WITH_EXTENDER)
      *(bCio_IoExtCommArray.bCio_IoExtCommArrayCmd + 2u) = eCio_Led4_c;
    #elif !(defined SILABS_PLATFORM_WMB912)
      bCio_IoPortState &= (~M_LED4);
      LED4 = ILLUMINATE;
    #endif
      break;

    default:
      break;
  }

#ifdef SILABS_IO_WITH_EXTENDER
  /* Request LED state change */
  qSmbus_SMBusWrite(IOEXT_SMBUS_ADDR, \
                    bCio_IoExtAddrLength_c + bCio_IoExtCmdLength_c, \
                    bCio_IoExtCommArray.bCio_IoExtCommArrayCmd);
#endif
}

/*!
 * This function is used to switch the selected LED off.
 *
 * @param[in] biLedNum Number of the LED to be switched off (1 ... 4).
 *
 * @return None
 */
void vCio_ClearLed(U8 biLedNum)
{
#ifdef SILABS_IO_WITH_EXTENDER
  *((U16*) bCio_IoExtCommArray.bCio_IoExtCommArrayCmd) = \
                                      IOEXT_ADDR_CONTROL_CLEAR_LED_STATE;
#endif

  switch(biLedNum)
  {
    case 1:
    #if (defined SILABS_IO_WITH_EXTENDER)
      *(bCio_IoExtCommArray.bCio_IoExtCommArrayCmd + 2u) = eCio_Led1_c;
    #else
      LED1 = EXTINGUISH;
      bCio_IoPortState |= M_LED1;
    #endif
      break;

    case 2:
    #if (defined SILABS_IO_WITH_EXTENDER)
      *(bCio_IoExtCommArray.bCio_IoExtCommArrayCmd + 2u) = eCio_Led2_c;
    #elif !(defined SILABS_PLATFORM_WMB912)
      bCio_IoPortState |= M_LED2;
      LED2 = EXTINGUISH;
    #endif
      break;

    case 3:
    #if (defined SILABS_IO_WITH_EXTENDER)
      *(bCio_IoExtCommArray.bCio_IoExtCommArrayCmd + 2u) = eCio_Led3_c;
    #elif !(defined SILABS_PLATFORM_WMB912)
      bCio_IoPortState |= M_LED3;
      LED3 = EXTINGUISH;
    #endif
      break;

    case 4:
    #if (defined SILABS_IO_WITH_EXTENDER)
      *(bCio_IoExtCommArray.bCio_IoExtCommArrayCmd + 2u) = eCio_Led4_c;
    #elif !(defined SILABS_PLATFORM_WMB912)
      bCio_IoPortState |= M_LED4;
      LED4 = EXTINGUISH;
    #endif
      break;

    default:
      break;
  }

#ifdef SILABS_IO_WITH_EXTENDER
  /* Request LED state change */
  qSmbus_SMBusWrite(IOEXT_SMBUS_ADDR, \
                    bCio_IoExtAddrLength_c + bCio_IoExtCmdLength_c, \
                    bCio_IoExtCommArray.bCio_IoExtCommArrayCmd);
#endif
}

/**
 * Function to toggle the given LED state.
 *
 * @param[in] biLedNum Number of the LED to be toggled off (1 ... 4).
 *
 * @return None.
 */
void vCio_ToggleLed(U8 biLedNum)
{
#ifdef SILABS_IO_WITH_EXTENDER
  *((U16*) bCio_IoExtCommArray.bCio_IoExtCommArrayCmd) = \
                                      IOEXT_ADDR_CONTROL_TOGGLE_LED_STATE;
#endif

  switch(biLedNum)
  {
    case 1:
    #if (defined SILABS_IO_WITH_EXTENDER)
      *(bCio_IoExtCommArray.bCio_IoExtCommArrayCmd + 2u) = eCio_Led1_c;
    #else
      if (bCio_IoPortState & M_LED1)
        vCio_SetLed(biLedNum);
      else
        vCio_ClearLed(biLedNum);
    #endif
      break;

    case 2:
    #if (defined SILABS_IO_WITH_EXTENDER)
      *(bCio_IoExtCommArray.bCio_IoExtCommArrayCmd + 2u) = eCio_Led2_c;
    #elif !(defined SILABS_PLATFORM_WMB912)
      if (bCio_IoPortState & M_LED2)
        vCio_SetLed(biLedNum);
      else
        vCio_ClearLed(biLedNum);
    #endif
      break;

    case 3:
    #if (defined SILABS_IO_WITH_EXTENDER)
      *(bCio_IoExtCommArray.bCio_IoExtCommArrayCmd + 2u) = eCio_Led3_c;
    #elif !(defined SILABS_PLATFORM_WMB912)
      if (bCio_IoPortState & M_LED3)
        vCio_SetLed(biLedNum);
      else
        vCio_ClearLed(biLedNum);
    #endif
      break;

    case 4:
    #if (defined SILABS_IO_WITH_EXTENDER)
      *(bCio_IoExtCommArray.bCio_IoExtCommArrayCmd + 2u) = eCio_Led4_c;
    #elif !(defined SILABS_PLATFORM_WMB912)
      if (bCio_IoPortState & M_LED4)
        vCio_SetLed(biLedNum);
      else
        vCio_ClearLed(biLedNum);
    #endif
      break;

    default:
      break;
  }

#ifdef SILABS_IO_WITH_EXTENDER
  /* Request LED state change */
  qSmbus_SMBusWrite(IOEXT_SMBUS_ADDR, \
                    bCio_IoExtAddrLength_c + bCio_IoExtCmdLength_c, \
                    bCio_IoExtCommArray.bCio_IoExtCommArrayCmd);
#endif
}

/*!
 * This function is used to read the status of the selected push-button.
 *
 * @param[in] biPbNum Number of the push-button to be switched on (1 ... 4).
 *
 * @return State of the selected PB.
 *
 * @note If SILABS_IO_WITH_EXTENDER defined the function implements a "cache"
 * algorithm to eliminate the SMBus communication overhead. As the IOExt returns
 * all PB states in one byte queries for each PB state is unnecessary. The SMBus
 * fetch takes place only in case the PB state has been already read.
 */
BIT gCio_GetPB(U8 biPbNum)
{
#if (defined SILABS_IO_WITH_EXTENDER)
  SEGMENT_VARIABLE(lutPB[SILABS_PLATFORM_COMPONENT_PB + 1u], U8, SEG_CODE) = \
                                              { 0x00, 0x01, 0x02, 0x04, 0x08, };
  /* Store the fetched, not yet queried PB states */
  static SEGMENT_VARIABLE(lPBState, U8, SEG_DATA) = 0x00;

  if (!(lPBState & lutPB[biPbNum])) {
    /* Fill SMBus data array: address */
    *((U16*) bCio_IoExtCommArray.bCio_IoExtCommArrayCmd) = \
                                      IOEXT_ADDR_REQUEST_GPIO_STATE;

    /* Request PB state */
    if (qSmbus_SMBusWrite(IOEXT_SMBUS_ADDR, \
            bCio_IoExtAddrLength_c, \
            bCio_IoExtCommArray.bCio_IoExtCommArrayCmd) == \
                                                    SMBUS_TRANSMISSION_OK) {
      /* Read PB state */
      if (qSmbus_SMBusRead(IOEXT_SMBUS_ADDR, \
              bCio_IoExtRespLength_c, \
              bCio_IoExtCommArray.bCio_IoExtCommArrayResp) == \
                                                      SMBUS_RX_FINISHED) {
        lPBState = \
                (bCio_IoExtCommArray.bCio_IoExtCommArrayResp[0u] << 4u) | 0x0F;
      }
    }
  }

  /* Check requested PB state */
  if ((biPbNum) && (SILABS_PLATFORM_COMPONENT_PB >= biPbNum)) {
    lPBState &= ~(lutPB[biPbNum]);
    if ((lPBState >> 4u) & lutPB[biPbNum]) {
      return TRUE;
    }
  }

  return FALSE;
#elif ((defined SILABS_PLATFORM_RFSTICK) || (defined SILABS_PLATFORM_LCDBB))
  BIT s;

  //Disable Global interrupt
  EA = 0;

  switch(biPbNum)
  {
    case 1:
      s = PB1;
      break;
    case 2:
      s = PB2;
      break;
    case 3:
      s = PB3;
      break;
    case 4:
      s = PB4;
      break;
    default:
      s = 1;
      break;
  }

  //Enable Global interrupt
  EA = 1;

  //return with the value of the button
  return s;

#else
  BIT s;

  //check whether the selected button was pressed or not
  switch (biPbNum)
  {
    case 1:
      //Disable Global interrupt
      EA = 0;
      //latch P2.0 to '1'
      LED1 = 1;
#if (defined SILABS_MCU_DC_EMIF_F930)
      //Discharge capacitor on Vref pin
      mCio_WaitIOSteadyState_long;
#endif
      //set Px.x to input
#if ((defined SILABS_MCU_DC_EMIF_F930) || (defined SILABS_PLATFORM_WMB))
      P0MDOUT &= (~M_LED1);
#else
      P2MDOUT &= (~M_LED1);
#endif
#if (defined SILABS_MCU_DC_EMIF_F930)
      //Wait pin to be stabilized on EMIF F930
      //HW contains delay due to capacitor on Vref pin
      //(~10k pull-up resistor required)
      mCio_WaitIOSteadyState_long;
#else
      //Wait pin to be stabilized
      mCio_WaitIOSteadyState;
#endif
      //Store input value
      s = LED1;
//      if (P0 & M_LED1)
//        s = 1;
//      else
//        s = 0;
      //set P2.0 to output
#if ((defined SILABS_MCU_DC_EMIF_F930) || (defined SILABS_PLATFORM_WMB))
      P0MDOUT |= M_LED1;
#else
      P2MDOUT |= M_LED1;
#endif

      //restore LED1
      if ((bCio_IoPortState & M_LED1) == 0)
        vCio_SetLed(1);
      else
        vCio_ClearLed(1);

      //Enable Global interrupt
      EA = 1;
      //return with the value of the button
    break;

#if !(defined SILABS_PLATFORM_WMB912)
    case 2:
      //Disable Global interrupt
      EA = 0;
      //latch P2.0 to '1'
      LED2 = 1;
      //set P2.0 to input
#if ((defined SILABS_MCU_DC_EMIF_F930) || (defined SILABS_PLATFORM_WMB))
      P0MDOUT &= (~M_LED2);
#else
      P2MDOUT &= (~M_LED2);
#endif
      //Wait pin to be stabilized
      mCio_WaitIOSteadyState;
      //Store input value
      s = LED2;
      //set P2.0 to output
#if ((defined SILABS_MCU_DC_EMIF_F930) || (defined SILABS_PLATFORM_WMB))
      P0MDOUT |= M_LED2;
#else
      P2MDOUT |= M_LED2;
#endif

      //restore LED2
      if((bCio_IoPortState & M_LED2) == 0)
        vCio_SetLed(2);
      else
        vCio_ClearLed(2);

      //Enable Global interrupt
      EA = 1;
      //return with the value of the button
    break;

    case 3:
      //Disable Global interrupt
      EA = 0;
      //latch P2.0 to '1'
      LED3 = 1;
      //set P2.0 to input
#if ((defined SILABS_MCU_DC_EMIF_F930) || (defined SILABS_PLATFORM_WMB))
      P0MDOUT &= (~M_LED3);
#else
      P2MDOUT &= (~M_LED3);
#endif
      //Wait pin to be stabilized
      mCio_WaitIOSteadyState;
      //Store input value
      s = LED3;
      //set P2.0 to output
#if ((defined SILABS_MCU_DC_EMIF_F930) || (defined SILABS_PLATFORM_WMB))
      P0MDOUT |= M_LED3;
#else
      P2MDOUT |= M_LED3;
#endif
      //restore LED3
      if((bCio_IoPortState & M_LED3) == 0)
        vCio_SetLed(3);
      else
        vCio_ClearLed(3);
      //Enable Global interrupt
      EA = 1;
      //return with the value of the button
    break;

    case 4:
      //Disable Global interrupt
      EA = 0;
      //latch P2.0 to '1'
      LED4 = 1;
      //set P2.0 to input
#if ((defined SILABS_MCU_DC_EMIF_F930) || (defined SILABS_PLATFORM_WMB))
      P0MDOUT &= (~M_LED4);
#else
      P2MDOUT &= (~M_LED4);
#endif
      //Wait pin to be stabilized
      mCio_WaitIOSteadyState;
      //Store input value
      s = LED4;
      //set P2.0 to output
#if ((defined SILABS_MCU_DC_EMIF_F930) || (defined SILABS_PLATFORM_WMB))
      P0MDOUT |= M_LED4;
#else
      P2MDOUT |= M_LED4;
#endif
      //restore LED4
      if((bCio_IoPortState & M_LED4) == 0)
        vCio_SetLed(4);
      else
        vCio_ClearLed(4);
      //Enable Global interrupt
      EA = 1;
      //return with the value of the button
    break;
#endif //#if !(defined SILABS_PLATFORM_WMB912)


    default:
      s = 1;
    break;
  }

  return s;
#endif
}
