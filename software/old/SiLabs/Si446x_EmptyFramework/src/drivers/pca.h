/*! @file pca.h
 * @brief Header file of PCA routines and definitions.
 *
 * @b COPYRIGHT
 * @n Silicon Laboratories Confidential
 * @n Copyright 2012 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 */


#ifndef PCA_H_
#define PCA_H_


/*------------------------------------------------------------------------*/
/*                          Global definitions                            */
/*------------------------------------------------------------------------*/

/** @name Time-base source
 *
 * Time-base source selection of PCA counter.
 */
//@{
#define bPca_PcaCps_000_c  0x00
#define bPca_PcaCps_001_c  0x01
#define bPca_PcaCps_010_c  0x02
#define bPca_PcaCps_011_c  0x03
#define bPca_PcaCps_100_c  0x04
#define bPca_PcaCps_101_c  0x05
//@}


/** @name Cycle length select
 *
 * Cycle length select definitions of PCA timer PWM configuration.
 */
//@{
#define bPca_PwmClsel_00_c  0x00
#define bPca_PwmClsel_01_c  0x01
#define bPca_PwmClsel_10_c  0x02
#define bPca_PwmClsel_11_c  0x03
//@}


/*------------------------------------------------------------------------*/
/*                            Global macros                               */
/*------------------------------------------------------------------------*/

/** @name PCA Timer macros
 *
 * Macro interfaces of PCA timer operations.
 */
//@{
#define mPca_EnablePcaTmr()      CR = 1; CF = 0
#define mPca_StopPcaTmr()        CR = 0; CF = 0
#define mPca_EnablePcaTmrIt()    PCA0MD |= M_ECF; CF = 0
#define mPca_DisablePcaTmrIt()   PCA0MD &= (~M_ECF); CF = 0
#define mPca_ClearPcaTmrIt()     CF = 0
//@}

/** @name PCA Timer PWM macros
 *
 * Macro interfaces of PCA timer PWM configuration.
 */
//@{
#define mPca_EnablePcaTmrCofIt()    PCA0PWM |= M_ECOV; PCA0PWM &= (~M_COVF)
#define mPca_DisablePcaTmrCofIt()   PCA0PWM &= (~(M_ECOV | M_COVF))
#define mPca_ClearPcaTmrCofIt()     PCA0PWM &= (~M_COVF)
#define mPca_SelectAutoReloadReg()  PCA0PWM |= M_ARSEL
//@}

#define mPca_EnablePwm16N(biCpmNum)   PCA0CPM ## biCpmNum |=    (M_PWM16 ## biCpmNum)
#define mPca_DisablePwm16N(biCpmNum)  PCA0CPM ## biCpmNum &=  (~(M_PWM16 ## biCpmNum))

#define mPca_EnableEcomN(biCpmNum)    PCA0CPM ## biCpmNum |=    (M_ECOM ## biCpmNum)
#define mPca_DisableEcomN(biCpmNum)   PCA0CPM ## biCpmNum &=  (~(M_ECOM ## biCpmNum))

#define mPca_EnableCappN(biCpmNum)    PCA0CPM ## biCpmNum |=    (M_CAPP ## biCpmNum)
#define mPca_DisableCappN(biCpmNum)   PCA0CPM ## biCpmNum &=  (~(M_CAPP ## biCpmNum))

#define mPca_EnableCapnN(biCpmNum)    PCA0CPM ## biCpmNum |=    (M_CAPN ## biCpmNum)
#define mPca_DisableCapnN(biCpmNum)   PCA0CPM ## biCpmNum &=  (~(M_CAPN ## biCpmNum))

#define mPca_EnableMatN(biCpmNum)     PCA0CPM ## biCpmNum |=    (M_MAT ## biCpmNum)
#define mPca_DisableMatN(biCpmNum)    PCA0CPM ## biCpmNum &=  (~(M_MAT ## biCpmNum))

#define mPca_EnableTogN(biCpmNum)     PCA0CPM ## biCpmNum |=    (M_TOG ## biCpmNum)
#define mPca_DisableTogN(biCpmNum)    PCA0CPM ## biCpmNum &=  (~(M_TOG ## biCpmNum))

#define mPca_EnablePwmN(biCpmNum)     PCA0CPM ## biCpmNum |=    (M_PWM ## biCpmNum)
#define mPca_DisablePwmN(biCpmNum)    PCA0CPM ## biCpmNum &=  (~(M_PWM ## biCpmNum))

#define mPca_EnableEccfN(biCpmNum)    PCA0CPM ## biCpmNum |=    (M_ECCF ## biCpmNum)
#define mPca_DisableEccfN(biCpmNum)   PCA0CPM ## biCpmNum &=  (~(M_ECCF ## biCpmNum))

#define mPca_DisableAllInCpmN(biCpmNum) PCA0CPM ## biCpmNum = 0x00

#define mPca_SetAutoReloadRegN(biCpmNum, wiPca0Cp) PCA0CPL ## biCpmNum = (wiPca0Cp & 0x00FF); PCA0CPH ## biCpmNum = ((wiPca0Cp >> 8) & 0x00FF)

/*------------------------------------------------------------------------*/
/*          Global structure & enumeration definitions                    */
/*------------------------------------------------------------------------*/


/*------------------------------------------------------------------------*/
/*                           Function prototypes                          */
/*------------------------------------------------------------------------*/

void vPca_InitPcaTmr(U8 biPulseSelect, U8 biPcaTmrItEnable, U8 biCycleLengthSelect);


#endif /* PCA_H_ */



