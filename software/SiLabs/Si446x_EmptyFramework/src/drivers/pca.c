/*! @file pca.c
 * @brief This file contains the interface functions of the programmable counter array (PCA).
 *
 * @b COPYRIGHT
 * @n Silicon Laboratories Confidential
 * @n Copyright 2012 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 */

#include "..\bsp.h"

#if !( (defined SILABS_MCU_F930) || (defined SILABS_MCU_F912) )
  #error Check implementation for given MCU!
#endif

/*------------------------------------------------------------------------*/
/*                          Global variables                              */
/*------------------------------------------------------------------------*/


/*------------------------------------------------------------------------*/
/*                          Function implementations                      */
/*------------------------------------------------------------------------*/

/*!
 * This function is used to start Timer 2 in the specified mode.
 *
 * @param[in] biPulseSelect       Selects time-base source of PCA counter (use predefined constants: bPca_PcaCps_000_c etc.)
 * @param[in] biPcaTmrItEnable    Enables PCA timer IT if TRUE, disables it if FALSE
 * @param[in] biCycleLengthSelect PWM-mode cycle length select (use predefined constants: bPca_PwmClsel_00_c etc.)
 *
 * @return  None.
 */
void vPca_InitPcaTmr(U8 biPulseSelect, U8 biPcaTmrItEnable, U8 biCycleLengthSelect)
{
  //setup timer
  PCA0MD = M_CIDL | (biPulseSelect & M_CPS);
  PCA0PWM = M_ARSEL | (biCycleLengthSelect & M_CLSEL);

  //enable IT if needed
  if(biPcaTmrItEnable)
  {
    mPca_EnablePcaTmrIt();
  }
  else
  {
    mPca_DisablePcaTmrIt();
  }
}
