/*! @file hmi.c
 * @brief This file contains functions to manage behavior of basic human module interfaces (push-buttons, switches, LEDs).
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

#ifdef SILABS_PLATFORM_COMPONENT_PB
SEGMENT_VARIABLE(rHmi_PbData, tHmi_PbData, SEG_XDATA) = { eHmi_PbStandBy_c, }; /**< Instance of push-button data structure */
SEGMENT_VARIABLE(aqHmi_PbStates[], eHmi_PbStates, SEG_XDATA)= {eHmi_PbNo_c, eHmi_Pb1_c, eHmi_Pb2_c, eHmi_Pb3_c, eHmi_Pb4_c}; /**< Array of instances of push-button definitions */
#endif

#ifdef SILABS_PLATFORM_COMPONENT_LED
SEGMENT_VARIABLE(arHmi_LedData[bHmi_NumOfLeds_c], tHmi_LedData, SEG_XDATA) = {{0,},};  /**< Array of instances of Led data structure */

  #ifdef HMI_DRIVER_EXTENDED_SUPPORT
  SEGMENT_VARIABLE(wHmi_LedMainCnt, U16, SEG_XDATA) = 0; /**< Main time counter of Led handler */
  #endif
SEGMENT_VARIABLE(aqHmi_Leds[], eHmi_Leds, SEG_XDATA)= {eHmi_NoLed_c, eHmi_Led1_c, eHmi_Led2_c, eHmi_Led3_c, eHmi_Led4_c}; /**< Array of instances of Led definitions */
#endif

#ifdef SILABS_PLATFORM_COMPONENT_BUZZER
SEGMENT_VARIABLE(rHmi_BuzzData, tHmi_BuzzData, SEG_XDATA); /**< Instance of Buzzer data structure */
  #ifdef HMI_DRIVER_EXTENDED_SUPPORT
  SEGMENT_VARIABLE(wHmi_BuzzMainCnt, U16, SEG_XDATA) = 0;     /**< Main time counter of Buzzer handler */
  #endif
#endif

#ifdef SILABS_PLATFORM_COMPONENT_SWITCH
SEGMENT_VARIABLE(bHmi_SwStateHolder, U8, SEG_XDATA) = 0; /**< Holds the actual state of the switches */
#endif


/*------------------------------------------------------------------------*/
/*                          Function implementations                      */
/*------------------------------------------------------------------------*/

#ifdef SILABS_PLATFORM_COMPONENT_LED
/*!
 * This function is used to initialize the Led handler.
 *
 * @return  None.
 *
 * @note It has to be called from the initialization section.
 */
void vHmi_InitLedHandler(void)
{
  /*! NOTE: Re-initialization of LED Handler supported by the extended HMI driver */

#ifdef HMI_DRIVER_EXTENDED_SUPPORT
  SEGMENT_VARIABLE(bLedCnt, U8 , SEG_DATA);

  for (bLedCnt = 1; bLedCnt <= bHmi_NumOfLeds_c; bLedCnt++)
  {
    arHmi_LedData[bLedCnt-1].gLedIsOn = FALSE;
    arHmi_LedData[bLedCnt-1].qLedState = eHmi_LedOff_c;
    arHmi_LedData[bLedCnt-1].wLedBlinkCnt = 0;
  }
#endif
}

/*!
 * This function is used to change state of selected Led.
 *
 * @param[in] qiLed Led to change its state.
 * @param[in] qiLedState New state of qiLed.
 *
 * @return  None.
 */
void vHmi_ChangeLedState(eHmi_Leds qiLed, eHmi_LedStates qiLedState)
{
  arHmi_LedData[qiLed-1].qLedState = qiLedState;
}

#ifdef HMI_DRIVER_EXTENDED_SUPPORT
/*!
 * This function is used to change state of all Leds.
 *
 * @param[in] qiLedState New state of all the Leds.
 *
 * @return  None.
 */
void vHmi_ChangeAllLedState(eHmi_LedStates qiLedState)
{
  SEGMENT_VARIABLE(bLedCnt, U8 , SEG_DATA);

  for (bLedCnt = 1; bLedCnt <= bHmi_NumOfLeds_c; bLedCnt++)
  {
    arHmi_LedData[bLedCnt-1].qLedState = qiLedState;
  }
}

/*!
 * This function is used to force all Leds to off immediately.
 *
 * @return  None.
 */
void vHmi_ClearAllLeds(void)
{
  SEGMENT_VARIABLE(bLedCnt, U8 , SEG_DATA);

  for (bLedCnt = 1; bLedCnt <= bHmi_NumOfLeds_c; bLedCnt++)
  {
    vCio_ClearLed(bLedCnt);
    arHmi_LedData[bLedCnt-1].gLedIsOn = FALSE;
    arHmi_LedData[bLedCnt-1].qLedState = eHmi_LedStdBy_c;
  }
}
#endif

/*!
 * This function is used to handle Led management.
 *
 * @return  None.
 */
void vHmi_LedHandler(void)
{
#ifdef HMI_DRIVER_EXTENDED_SUPPORT
  BIT bLedChngReq = FALSE;
#else
  static
#endif
  SEGMENT_VARIABLE(bLedCnt, U8 , SEG_DATA) = 0u;

#ifdef HMI_DRIVER_EXTENDED_SUPPORT
  wHmi_LedMainCnt++;

  for (bLedCnt = 1; bLedCnt <= bHmi_NumOfLeds_c; bLedCnt++)
#else
  if (++bLedCnt > bHmi_NumOfLeds_c) bLedCnt = 1u;
#endif
  {
    switch (arHmi_LedData[bLedCnt-1].qLedState)
    {
      case eHmi_LedOff_c:
        vCio_ClearLed(bLedCnt);
        arHmi_LedData[bLedCnt-1].gLedIsOn = FALSE;
        arHmi_LedData[bLedCnt-1].qLedState = eHmi_LedStdBy_c;
        break;

      case eHmi_LedOn_c:
        vCio_SetLed(bLedCnt);
        arHmi_LedData[bLedCnt-1].gLedIsOn = TRUE;
        arHmi_LedData[bLedCnt-1].qLedState = eHmi_LedStdBy_c;
        break;

      case eHmi_LedStdBy_c:
        break;

#ifdef HMI_DRIVER_EXTENDED_SUPPORT
      case eHmi_LedToggle_c:
          vCio_ToggleLed(bLedCnt);
          arHmi_LedData[bLedCnt-1].gLedIsOn = \
                !arHmi_LedData[bLedCnt-1].gLedIsOn;
          arHmi_LedData[bLedCnt-1].qLedState = eHmi_LedStdBy_c;
        break;

      case eHmi_LedBlink2Hz_c:
        if ((wHmi_LedMainCnt == wTmr_2HzCntMax_c) ||
            (wHmi_LedMainCnt == wTmr_2HzCntMax_c + wTmr_1HzCntMax_c)
        )
        {
          bLedChngReq = TRUE;
        }
      case eHmi_LedBlink1Hz_c:
        if (wHmi_LedMainCnt == wTmr_1HzCntMax_c)
        {
          bLedChngReq = TRUE;
        }
      case eHmi_LedBlinkHalfHz_c:
        if (wHmi_LedMainCnt == wTmr_0Hz5CntMax_c)
        {
          bLedChngReq = TRUE;
        }
        break;
#endif

      case eHmi_LedBlinkOnce_c:
        vCio_SetLed(bLedCnt);
        arHmi_LedData[bLedCnt-1].gLedIsOn = TRUE;
        arHmi_LedData[bLedCnt-1].wLedBlinkCnt = 0;
        arHmi_LedData[bLedCnt-1].qLedState = eHmi_LedBlinkWait_c;
      case eHmi_LedBlinkWait_c:
        if ( arHmi_LedData[bLedCnt-1].wLedBlinkCnt++ > (wTmr_2HzCntMax_c / (2.0
#ifndef HMI_DRIVER_EXTENDED_SUPPORT
            * 4u
#endif
        )) )
        {
          arHmi_LedData[bLedCnt-1].qLedState = eHmi_LedOff_c;
        }
        break;

      default:
        break;
    }

  #ifdef HMI_DRIVER_EXTENDED_SUPPORT
    if (bLedChngReq)
    {
      if (arHmi_LedData[bLedCnt-1].gLedIsOn)
      {
        vCio_ClearLed(bLedCnt);
        arHmi_LedData[bLedCnt-1].gLedIsOn = FALSE;
      }
      else
      {
        vCio_SetLed(bLedCnt);
        arHmi_LedData[bLedCnt-1].gLedIsOn = TRUE;
      }
      bLedChngReq = FALSE;
    }
  #endif
  }
  #ifdef HMI_DRIVER_EXTENDED_SUPPORT
  if (wHmi_LedMainCnt == wTmr_0Hz5CntMax_c)
  {
    wHmi_LedMainCnt = 0;
  }
  #endif
}
#endif

#ifdef SILABS_PLATFORM_COMPONENT_PB
/*!
 * This function is used to initialize push-button handler.
 *
 * @return  None.
 *
 * @note It has to be called from the initialization section.
 */
void vHmi_InitPbHandler(void)
{
  /*! NOTE: Re-initialization of LED Handler supported by the extended HMI driver */

#ifdef HMI_DRIVER_EXTENDED_SUPPORT
  rHmi_PbData.qPbHandlerState = eHmi_PbStandBy_c;
  rHmi_PbData.wPbPushTime     = 0;
  rHmi_PbData.bPbPushTrack    = eHmi_PbNo_c;
  rHmi_PbData.bPbPushTrackAct = eHmi_PbNo_c;
  rHmi_PbData.bPbWaitTime     = 0;
#endif
}

/*!
 * This function is used to check if any of the push-buttons is pushed.
 *
 * @param[out] *boPbPushTrack Read value of pushed button.
 * @param[out] *woPbPushTime Push time of pushed button.
 *
 * @return  Pushed state of push-buttons.
 */
BIT gHmi_PbIsPushed(U8 *boPbPushTrack, U16 *woPbPushTime)
{
  if (rHmi_PbData.qPbHandlerState == eHmi_PbPushed_c)
  {
    *boPbPushTrack  = rHmi_PbData.bPbPushTrack;
    *woPbPushTime   = rHmi_PbData.wPbPushTime;
    return TRUE;
  }
  else
  {
    *boPbPushTrack  = eHmi_PbNo_c;
    *woPbPushTime   = 0;
    return FALSE;
  }
}

#ifdef HMI_DRIVER_EXTENDED_SUPPORT
/*!
 * This function is used to check if there is unhandled push-buttons event.
 *
 * @return  True if there is unhandled push-button event.
 */
BIT gHmi_IsPbUnHandled(void)
{
  if (rHmi_PbData.bPbPushTrackLast > eHmi_PbNo_c)
  {
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

/*!
 * This function is used to read last pushed button(s), push track holder is erased if button(s) was already released.
 *
 * @param[out] *woPbPushTime Push time of pushed button.

 * @return  Push track holder of last pushed button(s).
 */
U8 bHmi_PbGetLastButton(U16 *woPbPushTime)
{
  SEGMENT_VARIABLE(bPbPushTrackTemp, U8 , SEG_DATA) = rHmi_PbData.bPbPushTrackLast;

  *woPbPushTime = rHmi_PbData.wPbPushTimeLast;

  if (rHmi_PbData.bPbPushTrackLast > eHmi_PbNo_c)
  {
    rHmi_PbData.bPbPushTrackLast = eHmi_PbNo_c;
    rHmi_PbData.wPbPushTimeLast = 0;
  }

  return bPbPushTrackTemp;
}
#endif

/*!
 * This function is used to handle push-button management.
 *
 * @return  None.
 */
void vHmi_PbHandler(void)
{
#ifdef HMI_DRIVER_EXTENDED_SUPPORT
  static
#endif
  SEGMENT_VARIABLE(bButtonCnt, U8 , SEG_DATA) = 0u;
  SEGMENT_VARIABLE(bTemp, U8 , SEG_DATA);

#ifdef SILABS_PLATFORM_WMB
  static SEGMENT_VARIABLE(lInvokeCnt, U8, SEG_XDATA)  = 0u;
#endif

#ifdef HMI_DRIVER_EXTENDED_SUPPORT
  if (rHmi_PbData.qPbHandlerState > eHmi_PbNoRun_c)
#endif
  {

#ifdef SILABS_PLATFORM_WMB
    if (++lInvokeCnt == 0u)
#endif
    {
      rHmi_PbData.bPbPushTrackAct = eHmi_PbNo_c;

      for (bButtonCnt = 1; bButtonCnt <= bHmi_NumOfPbs_c; bButtonCnt++)       // Store state of the buttons
      {
        bTemp = !gCio_GetPB(bButtonCnt);
        rHmi_PbData.bPbPushTrackAct += bTemp<<(bButtonCnt-1);
      }
    }

    switch (rHmi_PbData.qPbHandlerState)
    {
      case eHmi_PbStandByWaitAllReleased_c:
        if (rHmi_PbData.bPbPushTrackAct == eHmi_PbNo_c)
        {
          rHmi_PbData.qPbHandlerState = eHmi_PbStandBy_c;
        }
        break;

      case eHmi_PbStandBy_c:
        if (rHmi_PbData.bPbPushTrackAct > eHmi_PbNo_c)
        {
          rHmi_PbData.qPbHandlerState = eHmi_PbStateChanged_c;
        }
        break;

      case eHmi_PbStateChanged_c:
        rHmi_PbData.wPbPushTime = 0;
        rHmi_PbData.bPbPushTrack = rHmi_PbData.bPbPushTrackAct;

        if (rHmi_PbData.bPbPushTrackAct == eHmi_PbNo_c)
        {
          rHmi_PbData.qPbHandlerState = eHmi_PbStandBy_c;
        }
        else
        {
          rHmi_PbData.qPbHandlerState = eHmi_PbDebounceWait_c;
        }
        break;

      case eHmi_PbDebounceWait_c:
        if (rHmi_PbData.bPbWaitTime++ > bHmi_PbDebounceWaitTime_c)
        {
          rHmi_PbData.bPbWaitTime = 0;
          rHmi_PbData.wPbPushTime = 0;
          rHmi_PbData.qPbHandlerState = eHmi_PbPushed_c;
        }
        break;

      case eHmi_PbPushed_c:
        /* If button released, or one released but more were pushed store the state*/
        if (rHmi_PbData.bPbPushTrackAct < rHmi_PbData.bPbPushTrack)
        {
          rHmi_PbData.qPbHandlerState = eHmi_PbReleaseWait_c;
        }
        /* If one more button is pushed goto change state */
        else if (rHmi_PbData.bPbPushTrackAct > rHmi_PbData.bPbPushTrack)
        {
          rHmi_PbData.qPbHandlerState = eHmi_PbStateChanged_c;
        }
        /* Increase counter if no change in button states */
        else
        {
          rHmi_PbData.wPbPushTime++;
        }
        break;

      case eHmi_PbReleaseWait_c:
        if (rHmi_PbData.bPbWaitTime++ > bHmi_PbDebounceWaitTime_c)
        {
          rHmi_PbData.bPbWaitTime = 0;
          rHmi_PbData.qPbHandlerState   = eHmi_PbStandByWaitAllReleased_c;
          rHmi_PbData.bPbPushTrackLast  = rHmi_PbData.bPbPushTrack;
          rHmi_PbData.wPbPushTimeLast   = rHmi_PbData.wPbPushTime;
        }
        break;
    }
  }
}
#endif

#if ((defined SILABS_PLATFORM_COMPONENT_LED) && (defined SILABS_PLATFORM_COMPONENT_PB))
  #ifdef HMI_DRIVER_EXTENDED_SUPPORT
  /*!
   * This function is used to show the actual state of the push-buttons on the Leds.
   *
   * @return  None.
   */
  void vHmi_ShowPbOnLeds(void)
  {
    SEGMENT_VARIABLE(boPbPushTrack, U8 , SEG_DATA);
    SEGMENT_VARIABLE(woPbPushTime, U16 , SEG_DATA);
    SEGMENT_VARIABLE(bPbLedCnt, U8 , SEG_DATA);

    gHmi_PbIsPushed(&boPbPushTrack, &woPbPushTime);

    for (bPbLedCnt = 1; bPbLedCnt <= 4; bPbLedCnt++)
    {
      if (boPbPushTrack & aqHmi_PbStates[bPbLedCnt])
      {
        vHmi_ChangeLedState(aqHmi_Leds[bPbLedCnt], eHmi_LedOn_c);
      }
      else
      {
        vHmi_ChangeLedState(aqHmi_Leds[bPbLedCnt], eHmi_LedOff_c);
      }
    }
  }
  #endif
#endif

#ifdef SILABS_PLATFORM_COMPONENT_SWITCH
/*!
 * This function is used to handle switch state change.
 *
 * @return  True if state of switches has changed.
 */
BIT gHmi_SwStateHandler(void)
{
  SEGMENT_VARIABLE(bSwStateHolderAct, U8, SEG_DATA) = 0; /**< Holds the actual state of the switches */

  bSwStateHolderAct |= (SW1_A) ? (eHmi_NoSw_c) : (eHmi_Sw1_A_c);
  bSwStateHolderAct |= (SW1_B) ? (eHmi_NoSw_c) : (eHmi_Sw1_B_c);
  bSwStateHolderAct |= (SW1_C) ? (eHmi_NoSw_c) : (eHmi_Sw1_C_c);
  bSwStateHolderAct |= (SW1_D) ? (eHmi_NoSw_c) : (eHmi_Sw1_D_c);

  if (bSwStateHolderAct == bHmi_SwStateHolder)
  {
    return FALSE;
  }
  else
  {
    bHmi_SwStateHolder = bSwStateHolderAct;
    return TRUE;
  }

}

U8 bHmi_GetSwState(void)
{
  return bHmi_SwStateHolder;
}
#endif

#ifdef SILABS_PLATFORM_COMPONENT_BUZZER
/*!
 * This function is used to initialize the buzzer operation.
 *
 * @return  None.
 *
 * @note It has to be called from the initialization section.
 */
void vHmi_InitBuzzer(void)
{

  //  vPca_InitPcaTmr(bPca_PcaCps_000_c, FALSE, bPca_PwmClsel_01_c);  //4kHz
  //  vPca_InitPcaTmr(bPca_PcaCps_000_c, FALSE, bPca_PwmClsel_00_c);  //8kHz
  //  vPca_InitPcaTmr(bPca_PcaCps_000_c, FALSE, bPca_PwmClsel_10_c);  //2kHz
  vPca_InitPcaTmr(bPca_PcaCps_000_c, FALSE, bPca_PwmClsel_11_c);  //1kHz
  //  mPca_EnablePcaTmrCofIt();

  mPca_DisableAllInCpmN(0);
  //  mPca_EnablePwmN(0);

  mPca_SelectAutoReloadReg();
  //  mPca_SetAutoReloadRegN(0, 0x0040); //90% @ 4kHz
  //  mPca_SetAutoReloadRegN(0, 0x0100); //50% @ 4kHz
  mPca_SetAutoReloadRegN(0, 0x0400); //50% @ 1kHz
  //  mPca_SetAutoReloadRegN(0, 0x01BF);  //10% @ 4kHz

  mPca_EnablePcaTmr();

  rHmi_BuzzData.gBuzzIsOn = FALSE;
  rHmi_BuzzData.qBuzzState = eHmi_BuzzOff_c;
  rHmi_BuzzData.wBuzzCnt = 0;

}

/*!
 * This function is used to change the state the buzzer.
 *
 * @param[in] qiBuzzState New state of the buzzer.
 *
 * @return  None.
 */
void vHmi_ChangeBuzzState(eHmi_BuzzStates qiBuzzState)
{
#ifdef HMI_DRIVER_EXTENDED_SUPPORT
  if (rHmi_BuzzData.qBuzzNextState != qiBuzzState)
#endif
  {
    rHmi_BuzzData.qBuzzState = rHmi_BuzzData.qBuzzNextState = qiBuzzState;
  }
}

/*!
 * This function is used to handle buzzer management.
 *
 * @return  None.
 */
void vHmi_BuzzHandler(void)
{
  BIT bBuzzChngReq = FALSE;

#ifdef HMI_DRIVER_EXTENDED_SUPPORT
  wHmi_BuzzMainCnt++;
#endif

  switch (rHmi_BuzzData.qBuzzState)
  {
    case eHmi_BuzzOff_c:
      mPca_DisablePwmN(0);
      rHmi_BuzzData.gBuzzIsOn = FALSE;
      rHmi_BuzzData.qBuzzState = eHmi_BuzzStdBy_c;
      break;

#ifdef HMI_DRIVER_EXTENDED_SUPPORT
    case eHmi_BuzzOn_c:
      mPca_EnablePwmN(0);
      rHmi_BuzzData.gBuzzIsOn = TRUE;
      rHmi_BuzzData.qBuzzState = eHmi_BuzzStdBy_c;
      break;

    case eHmi_BuzzStdBy_c:
      break;

    case eHmi_Buzz2Hz_c:
      if ((wHmi_BuzzMainCnt == wTmr_2HzCntMax_c) ||
          (wHmi_BuzzMainCnt == wTmr_2HzCntMax_c + wTmr_1HzCntMax_c) ||
          (wHmi_BuzzMainCnt == wTmr_2HzCntMax_c + wTmr_0Hz5CntMax_c) ||
          (wHmi_BuzzMainCnt == wTmr_2HzCntMax_c + wTmr_0Hz5CntMax_c + wTmr_1HzCntMax_c)
      )
      {
        rHmi_BuzzData.qBuzzState = eHmi_BuzzOnceAndCont_c;
      }
    case eHmi_Buzz1Hz_c:
      if ((wHmi_BuzzMainCnt == wTmr_1HzCntMax_c) ||
          (wHmi_BuzzMainCnt == wTmr_1HzCntMax_c + wTmr_0Hz5CntMax_c)
      )
      {
        rHmi_BuzzData.qBuzzState = eHmi_BuzzOnceAndCont_c;
      }
    case eHmi_Buzz0Hz5_c:
      if (wHmi_BuzzMainCnt == wTmr_0Hz5CntMax_c)
      {
        rHmi_BuzzData.qBuzzState = eHmi_BuzzOnceAndCont_c;
      }
    case eHmi_Buzz0Hz25_c:
      if (wHmi_BuzzMainCnt == wTmr_0Hz25CntMax_c)
      {
        rHmi_BuzzData.qBuzzState = eHmi_BuzzOnceAndCont_c;
      }
      break;

    case eHmi_BuzzOnceAndCont_c:
      mPca_EnablePwmN(0);
      mPca_SetAutoReloadRegN(0, 0x0100); //50% @ 4kHz
      rHmi_BuzzData.gBuzzIsOn = TRUE;
      rHmi_BuzzData.wBuzzCnt = 0;
      rHmi_BuzzData.qBuzzState = eHmi_BuzzWait_c;
      break;
#endif
    case eHmi_BuzzOnce_c:
      mPca_EnablePwmN(0);
      //mPca_SetAutoReloadRegN(0, 0x0100); //50% @ 2kHz
      mPca_SetAutoReloadRegN(0, 0x0400); //50% @ 1kHz
      rHmi_BuzzData.gBuzzIsOn = TRUE;
      rHmi_BuzzData.wBuzzCnt = 0;
      rHmi_BuzzData.qBuzzNextState = eHmi_BuzzOff_c;
      rHmi_BuzzData.qBuzzState = eHmi_BuzzWait_c;
    case eHmi_BuzzWait_c:
      if (rHmi_BuzzData.wBuzzCnt++ > (wTmr_8HzCntMax_c))
      {
        mPca_DisablePwmN(0);
        rHmi_BuzzData.gBuzzIsOn = FALSE;
        rHmi_BuzzData.qBuzzState = rHmi_BuzzData.qBuzzNextState;
      }
      break;

    default:
      break;
  }

#ifdef HMI_DRIVER_EXTENDED_SUPPORT
  if (wHmi_BuzzMainCnt == wTmr_0Hz25CntMax_c)
  {
    wHmi_BuzzMainCnt = 0;
  }
#endif
}
#endif



