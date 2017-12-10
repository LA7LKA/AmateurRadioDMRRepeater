/*! @file timer.c
 * @brief This file contains the interface functions of the timers.
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

SEGMENT_VARIABLE(wwTmr_Tmr2Periode , UU16, SEG_DATA) = {lTmr_Tmr2CntMax_c}; /**< Timer 2 period (1ms) */


/*------------------------------------------------------------------------*/
/*                          Function implementations                      */
/*------------------------------------------------------------------------*/

/*!
 * This function is used to start Timer 2 in the specified mode.
 *
 * @param[in] biPrescaler Prescaler value of timer (use predefined constants: bTmr_Tmr2One_c, bTmr_Tmr2Both_c)
 * @param[in] wwiPeriod   The duration of the timing
 * @param[in] biItEnable  Enables timer IT if TRUE, disables it if FALSE
 * @param[in] biExtClkSel External clock select (use predefined constants: bTmr_TxXCLK_00_c etc.)
 *
 * @return  None.
 */
void vTmr_StartTmr2(U8 biPrescaler, U16 wiPeriod, U8 biItEnable, U8 biExtClkSel)
{

  //setup timer
  if (biPrescaler == eTmr_SysClk_c)
  {
    CKCON |= (M_T2MH | M_T2ML);
  }
  else
  {
    CKCON &= ~(M_T2MH | M_T2ML);
  }
  TMR2CN = biExtClkSel & M_T2XCLK;

  //set time period
  wiPeriod = 65535u - wiPeriod;
  TMR2 = wiPeriod;
  TMR2RL = wiPeriod;

  //enable IT if needed
  if (biItEnable)
  {
    mTmr_EnableTmr2It();
  }
  else
  {
    mTmr_DisableTmr2It();
  }
  mTmr_EnableTmr2();
}

#ifdef TIMER_DRIVER_EXTENDED_SUPPORT

/*!
 * This function is used to check if Timer 2 is expired.
 *
 * @return  True if timer is expired (also stops the timer).
 * @note Function clears the IT status flag as well.
 */
BIT gTmr_Tmr2Expired(void)
{
  if( TF2H == 0)
  {
    return FALSE;
  }
  else
  {
    mTmr_StopTmr2();
    return TRUE;
  }

}

/*!
 * This function is used to start Timer 3 in the specified mode.
 *
 * @param[in] biPrescaler Prescaler value of timer (use predefined constants: bTmr_Tmr3One_c, bTmr_Tmr3Both_c)
 * @param[in] wiPeriod    The duration of the timing
 * @param[in] biItEnable  Enables timer IT if TRUE, disables it if FALSE
 * @param[in] biExtClkSel External clock select (use predefined constants: bTmr_TxXCLK_00_c etc.)
 *
 * @return  None.
 */
void vTmr_StartTmr3(U8 biPrescaler, U16 wiPeriod, U8 biItEnable, U8 biExtClkSel)
{

#ifdef SILABS_MCU_F960
  SEGMENT_VARIABLE(bRestoreSfrPage, U8, SEG_DATA);

  bRestoreSfrPage = SFRPAGE;
  SFRPAGE = LEGACY_PAGE;
#endif //#ifdef SILABS_MCU_F960

  /* Configure the timer3 operation */
  vTmr_StartTmr3_phaseConfigure(biPrescaler, wiPeriod, biItEnable, biExtClkSel, FALSE );

  vTmr_StartTmr3_phaseStart(wiPeriod);

#ifdef SILABS_MCU_F960
  // Restore SFR page after SPI transfer
  SFRPAGE = bRestoreSfrPage;
#endif //#ifdef SILABS_MCU_F960
}


/*!
 * This function is used to configure Timer 3 in the specified mode without starting it.
 *
 * @param[in] biPrescaler Prescaler value of timer (use predefined constants: bTmr_Tmr3One_c, bTmr_Tmr3Both_c)
 * @param[in] wiPeriod    The duration of the timing
 * @param[in] biItEnable  Enables timer IT if TRUE, disables it if FALSE
 * @param[in] biExtClkSel External clock select (use predefined constants: bTmr_TxXCLK_00_c etc.)
 * @param[in] biSetItPriorityHigh If TRUE sets the Timer3 IT priority to High
 *
 * @return  None.
 */
void vTmr_StartTmr3_phaseConfigure(U8 biPrescaler, U16 wiPeriod, U8 biItEnable, U8 biExtClkSel, U8 biSetItPriorityHigh)
{

  if (biPrescaler == eTmr_SysClk_c)
  {
    CKCON |= (M_T3MH | M_T3ML);
  }
  else
  {
    CKCON &= ~(M_T3MH | M_T3ML);
  }

#if 0 //TODO: Left here for debug purposes, remove if released
  /* Set T3 to run from SYSCLK */
  CKCON &= 0x3F;
  CKCON |= 0x40;
#endif

  TMR3CN = biExtClkSel & M_T3XCLK;

#if 0 //TODO: Left here for debug purposes, remove if released
  /* Reset Timer3 flags, Stop mode, AutoReload */
  TMR3CN = 0u;
#endif


  wiPeriod = 65535u - wiPeriod;
  TMR3 = wiPeriod;
  TMR3RL = wiPeriod;

#if 0 //TODO: Left here for debug purposes, remove if released
  /* Set Initial Value */
  TMR3 = Reload;

  /* Set Reload value */
  TMR3RL = Reload;
#endif

  if ( biSetItPriorityHigh )
  {
    /* Set Timer3 IT priority to High */
    EIP1 |= 0x80;
  }

  //enable IT if needed
  if( biItEnable == 1 )
  {
    mTmr_EnableTmr3It();
  }
  else
  {
    mTmr_DisableTmr3It();
  }

#if 0 //TODO: Left here for debug purposes, remove if released
  /* Enable Timer3 IT */
  EIE1 |= 0x80;
#endif

}


/**
 *  Starts Timer3 HW peripheral
 *
 *  @param Reload Timer Reload Value
 *
 *  @author Sz. Papp
 *
 *  @note
 *
 *****************************************************************************/
void vTmr_StartTmr3_phaseStart(U16 wiPeriod)
{
  /* Set Reload value */
  wiPeriod = 65535u - wiPeriod;
  TMR3RL = wiPeriod;

  mTmr_EnableTmr3();

#if 0 //TODO: Left here for debug purposes, remove if released
  /* Start Timer3 */
  TMR3CN |= 0x04;
#endif
}



/*!
 * This function is used to check if Timer 3 is expired.
 *
 * @return  True if timer is expired (also stops the timer).
 * @note Function clears the IT status flag as well.
 */

BIT gTmr_Tmr3Expired(void)
{
#ifdef SILABS_MCU_F960
  SEGMENT_VARIABLE(bRestoreSfrPage, U8, SEG_DATA);

  bRestoreSfrPage = SFRPAGE;
  SFRPAGE = LEGACY_PAGE;
#endif //#ifdef SILABS_MCU_F960

  if( (TMR3CN & M_TF3H) == 0)
  {
    return 0;
  }
  else
  {
    mTmr_StopTmr3();
    return 1;
  }

#ifdef SILABS_MCU_F960
  // Restore SFR page after SPI transfer
  SFRPAGE = bRestoreSfrPage;
#endif //#ifdef SILABS_MCU_F960
}

#endif //#ifdef TIMER_DRIVER_EXTENDED_SUPPORT

