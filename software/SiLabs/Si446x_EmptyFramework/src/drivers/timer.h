/*! @file isr.c
 * @brief Header file of timer routines and definitions.
 *
 * @b COPYRIGHT
 * @n Silicon Laboratories Confidential
 * @n Copyright 2012 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 */


#ifndef TIMER_H_
#define TIMER_H_


/*------------------------------------------------------------------------*/
/*                          Global definitions                            */
/*------------------------------------------------------------------------*/

/*!
 * @brief Definition of divider of Tmr2 in decimal, fixed point format.
 * @note Definition is only for calculation
 */
#define wTmr_Tmr2Divider_c (12.0)

/*!
 * @brief Definition of desired frequency of Tmr2 in Hz and decimal, fixed point format.
 */
#ifndef wTmr_Tmr2DesiredFreq_c
#define wTmr_Tmr2DesiredFreq_c (12000.0)
#endif

/*!
 * @brief Definition of max count value of Tmr2 in decimal format. Value is calculated from Sys Clk, Tmr2 freq divider and Tmr2 desired freq.
 */
#define lTmr_Tmr2CntMax_c (lSys_SysClockFreq_c / wTmr_Tmr2Divider_c / wTmr_Tmr2DesiredFreq_c)

/** @name Constant timer frequency definitions
 *
 * Definition of 8/4/2/1/0.5 Hz frequencies in decimal, fixed point format.
 */
//@{
#define bTmr_8HzFreq_c    (8.0)
#define bTmr_4HzFreq_c    (4.0)
#define bTmr_2HzFreq_c    (2.0)
#define bTmr_1HzFreq_c    (1.0)
#define bTmr_0Hz5Freq_c   (0.5)
#define bTmr_0Hz25Freq_c  (0.25)
//@}

/** @name Constant timer count definitions
 *
 * Definition of counter values of 8/4/2/1/0.5/0.25 Hz frequencies in decimal, fixed point format. Values are calculated from Tmr2 desired freq and constant freq definitions.
 */
//@{
#define wTmr_8HzCntMax_c    (wTmr_Tmr2DesiredFreq_c / bTmr_8HzFreq_c)
#define wTmr_4HzCntMax_c    (wTmr_Tmr2DesiredFreq_c / bTmr_4HzFreq_c)
#define wTmr_2HzCntMax_c    (wTmr_Tmr2DesiredFreq_c / bTmr_2HzFreq_c)
#define wTmr_1HzCntMax_c    (wTmr_Tmr2DesiredFreq_c / bTmr_1HzFreq_c)
#define wTmr_0Hz5CntMax_c   (wTmr_Tmr2DesiredFreq_c / bTmr_0Hz5Freq_c)
#define wTmr_0Hz25CntMax_c  (wTmr_Tmr2DesiredFreq_c / bTmr_0Hz25Freq_c)
//@}

/** @name External clk select
 *
 * External clk select definitions of timers.
 */
//@{
#define bTmr_TxXCLK_00_c  0x00
#define bTmr_TxXCLK_01_c  0x01
#define bTmr_TxXCLK_10_c  0x02
#define bTmr_TxXCLK_11_c  0x03
//@}

/** @name Prescaler of timers
 *
 * Prescaler definitions of TMR2/3.
 */
//@{
#define bTmr_Tmr2One_c    M_T2ML
#define bTmr_Tmr2Both_c   0x00
#define bTmr_Tmr3One_c    M_T3ML
#define bTmr_Tmr3Both_c   0x00
//@}
/*------------------------------------------------------------------------*/
/*          Global structure & enumeration definitions                    */
/*------------------------------------------------------------------------*/

/*!
 * @brief This enumeration contains elements of frequency settings table definitions.
 */
typedef enum _eTmr_ClockSelect
{
  eTmr_SysClk_c          = 0x00, /**< Timer clock is SysClk (Supported by: Timer 0/1/2/3) */
  eTmr_SysClkDiv4_c      = 0x10, /**< Timer clock is SysClk/4 (Supported by: Timer 0/1) */
  eTmr_SysClkDiv12_c     = 0x20, /**< Timer clock is SysClk/12 (Supported by: Timer 0/1/2/3) */
  eTmr_SysClkDiv48_c     = 0x30, /**< Timer clock is SysClk/48 (Supported by: Timer 0/1) */
} eTmr_ClockSelect;


/*------------------------------------------------------------------------*/
/*                            Global macros                               */
/*------------------------------------------------------------------------*/



/** @name Timer 1 macros
 *
 * Macro interfaces of timer 1 operations.
 */
//@{
#if !(defined SILABS_MCU_F912)
#define mTmr_StartTmr1_7kHz2_24MHz5()   CKCON &= 0xF4; CKCON |=  0x08; \
                                        TH1    = 0x96; TMOD  &= ~0xF0; \
                                        TMOD  |= 0x20; TR1   = 1
#else
// On F912 TH1 needs to set to 0x90. The osc freq seems to be 25.85MHz. Bad parts???
#define mTmr_StartTmr1_7kHz2_24MHz5()   CKCON &= 0xF4; CKCON |=  0x08; \
                                        TH1    = 0x90; TMOD  &= ~0xF0; \
                                        TMOD  |= 0x20; TR1   = 1
#endif
//@}


/** @name Timer 2 macros
 *
 * Macro interfaces of timer 2 operations.
 */
//@{
#define mTmr_EnableTmr2It()    ET2 = 1; TF2H = 0
#define mTmr_DisableTmr2It()   ET2 = 0; TF2H = 0
#define mTmr_ClearTmr2It()     TF2H = 0
#define mTmr_StopTmr2()        TR2 = 0; TF2H = 0
#define mTmr_EnableTmr2()      TR2 = 1; TF2H = 0

#define mTmr_StopAndClearTmr2() mTmr_DisableTmr2It(); mTmr_StopTmr2(); TMR2CN = 0u
//@}

/** @name Timer 3 macros
 *
 * Macro interfaces of timer 3 operations.
 */
//@{
#define mTmr_EnableTmr3It()    EIE1 |= 0x80; TMR3CN &= 0x3F
#define mTmr_DisableTmr3It()   EIE1 &= (~0x80); TMR3CN &= 0x3F
#define mTmr_ClearTmr3It()     TMR3CN &= (~(M_TF3H | M_TF3L))
#define mTmr_StopTmr3()        TMR3CN &= (~(M_TF3H | M_TF3L | M_TR3))
#define mTmr_EnableTmr3()      TMR3CN |= M_TR3; mTmr_ClearTmr3It()
//@}


/*------------------------------------------------------------------------*/
/*                          External variables                            */
/*------------------------------------------------------------------------*/

extern SEGMENT_VARIABLE(wwTmr_Tmr2Periode, UU16, SEG_DATA);


/*------------------------------------------------------------------------*/
/*                           Function prototypes                          */
/*------------------------------------------------------------------------*/

void  vTmr_StartTmr2(U8 biPrescaler, U16 wiPeriod, U8 biItEnable, U8 biExtClkSel);

#ifdef TIMER_DRIVER_EXTENDED_SUPPORT
  BIT  gTmr_Tmr2Expired(void);
  void vTmr_StartTmr3(U8 biPrescaler, U16 wiPeriod, U8 biItEnable, U8 biExtClkSel);
  void vTmr_StartTmr3_phaseConfigure(U8 biPrescaler, U16 wiPeriod, U8 biItEnable, U8 biExtClkSel, U8 biSetItPriorityHigh);
  void vTmr_StartTmr3_phaseStart(U16 wiPeriod);
  BIT  gTmr_Tmr3Expired(void);
#endif

#endif /* TIMER_H_ */
