/*! @file C8051F930_defs_add.h
 * @brief This file contains additional bit and bit-field definitions of registers for the C8051F93x/2x family.
 *
 * <b> AUTOMATICALLY GENERATED FILE. MAY CONTAIN MISTMATCH TO DATASHEET! </b>
 *
 * @b COPYRIGHT
 * @n Copyright 2012 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 *
 */
#ifndef C8051F930_DEFS_ADD_H_
#define C8051F930_DEFS_ADD_H_

// SFR Definition   5.1.   ADC0CN: ADC0 Control
#define   B_AD0EN        7         // ADC0 Enable.
#define   M_AD0EN        0x80      // ADC0 Enable.
#define   B_BURSTEN      6         // ADC0 Burst Mode Enable.
#define   M_BURSTEN      0x40      // ADC0 Burst Mode Enable.
#define   B_AD0INT       5         // ADC0 Conversion Complete Interrupt Flag.
#define   M_AD0INT       0x20      // ADC0 Conversion Complete Interrupt Flag.
#define   B_AD0BUSY      4         // ADC0 Busy.
#define   M_AD0BUSY      0x10      // ADC0 Busy.
#define   B_AD0WINT      3         // ADC0 Window Compare Interrupt Flag.
#define   M_AD0WINT      0x08      // ADC0 Window Compare Interrupt Flag.
#define   BF_ADC0CM      0         // ADC0 Start of Conversion Mode Select.
#define   BF_ADC0CM_0    0         // ADC0 Start of Conversion Mode Select.
#define   BF_ADC0CM_1    1         // ADC0 Start of Conversion Mode Select.
#define   BF_ADC0CM_2    2         // ADC0 Start of Conversion Mode Select.
#define   M_ADC0CM       0x07      // ADC0 Start of Conversion Mode Select.

// SFR Definition   5.2.   ADC0CF: ADC0 Configuration
#define   BF_AD0SC       3         // ADC0 SAR Conversion Clock Divider.
#define   BF_AD0SC_0     3         // ADC0 SAR Conversion Clock Divider.
#define   BF_AD0SC_1     4         // ADC0 SAR Conversion Clock Divider.
#define   BF_AD0SC_2     5         // ADC0 SAR Conversion Clock Divider.
#define   BF_AD0SC_3     6         // ADC0 SAR Conversion Clock Divider.
#define   BF_AD0SC_4     7         // ADC0 SAR Conversion Clock Divider.
#define   M_AD0SC        0xF8      // ADC0 SAR Conversion Clock Divider.
#define   B_AD08BE       2         // ADC0 8-Bit Mode Enable.
#define   M_AD08BE       0x04      // ADC0 8-Bit Mode Enable.
#define   B_AD0TM        1         // ADC0 Track Mode.
#define   M_AD0TM        0x02      // ADC0 Track Mode.
#define   B_AMP0GN       0         // ADC0 Gain Control.
#define   M_AMP0GN       0x01      // ADC0 Gain Control.

// SFR Definition   5.3.   ADC0AC: ADC0 Accumulator Configuration
#define   B_AD0AE        6         // ADC0 Accumulate Enable.
#define   M_AD0AE        0x40      // ADC0 Accumulate Enable.
#define   BF_AD0SJST     3         // ADC0 Accumulator Shift and Justify.
#define   BF_AD0SJST_0   3         // ADC0 Accumulator Shift and Justify.
#define   BF_AD0SJST_1   4         // ADC0 Accumulator Shift and Justify.
#define   BF_AD0SJST_2   5         // ADC0 Accumulator Shift and Justify.
#define   M_AD0SJST      0x38      // ADC0 Accumulator Shift and Justify.
#define   BF_AD0RPT      0         // ADC0 Repeat Count.
#define   BF_AD0RPT_0    0         // ADC0 Repeat Count.
#define   BF_AD0RPT_1    1         // ADC0 Repeat Count.
#define   BF_AD0RPT_2    2         // ADC0 Repeat Count.
#define   M_AD0RPT       0x07      // ADC0 Repeat Count.

// SFR Definition   5.4.   ADC0PWR: ADC0 Burst Mode Power-Up Time
#define   BF_AD0PWR      0         // ADC0 Burst Mode Power-Up Time.
#define   BF_AD0PWR_0    0         // ADC0 Burst Mode Power-Up Time.
#define   BF_AD0PWR_1    1         // ADC0 Burst Mode Power-Up Time.
#define   BF_AD0PWR_2    2         // ADC0 Burst Mode Power-Up Time.
#define   BF_AD0PWR_3    3         // ADC0 Burst Mode Power-Up Time.
#define   M_AD0PWR       0x0F      // ADC0 Burst Mode Power-Up Time.

// SFR Definition   5.5.   ADC0TK: ADC0 Burst Mode Track Time
#define   BF_AD0TK       0         // ADC0 Burst Mode Track Time.
#define   BF_AD0TK_0     0         // ADC0 Burst Mode Track Time.
#define   BF_AD0TK_1     1         // ADC0 Burst Mode Track Time.
#define   BF_AD0TK_2     2         // ADC0 Burst Mode Track Time.
#define   BF_AD0TK_3     3         // ADC0 Burst Mode Track Time.
#define   BF_AD0TK_4     4         // ADC0 Burst Mode Track Time.
#define   BF_AD0TK_5     5         // ADC0 Burst Mode Track Time.
#define   M_AD0TK        0x3F      // ADC0 Burst Mode Track Time.

// SFR Definition   5.12.  ADC0MX: ADC0 Input Channel Select
#define   BF_AD0MX       0         // AMUX0 Positive Input Selection.
#define   BF_AD0MX_0     0         // AMUX0 Positive Input Selection.
#define   BF_AD0MX_1     1         // AMUX0 Positive Input Selection.
#define   BF_AD0MX_2     2         // AMUX0 Positive Input Selection.
#define   BF_AD0MX_3     3         // AMUX0 Positive Input Selection.
#define   BF_AD0MX_4     4         // AMUX0 Positive Input Selection.
#define   M_AD0MX        0x1F      // AMUX0 Positive Input Selection.

// SFR Definition   5.14.  TOFFL: ADC0 Data Word Low Byte
#define   BF_TOFF        6         // Temperature Sensor Offset Low Bits.
#define   BF_TOFF_0      6         // Temperature Sensor Offset Low Bits.
#define   BF_TOFF_1      7         // Temperature Sensor Offset Low Bits.
#define   M_TOFF         0xC0      // Temperature Sensor Offset Low Bits.

// SFR Definition   5.15.  REF0CN: Voltage Reference Control
#define   B_REFGND       5         // Analog Ground Reference.
#define   M_REFGND       0x20      // Analog Ground Reference.
#define   BF_REFSL       3         // Voltage Reference Select.
#define   BF_REFSL_0     3         // Voltage Reference Select.
#define   BF_REFSL_1     4         // Voltage Reference Select.
#define   M_REFSL        0x18      // Voltage Reference Select.
#define   B_TEMPE        2         // Temperature Sensor Enable.
#define   M_TEMPE        0x04      // Temperature Sensor Enable.
#define   B_REFOE        0         // Internal Voltage Refe rence Output Enable.
#define   M_REFOE        0x01      // Internal Voltage Refe rence Output Enable.

// SFR Definition   6.1.   IREF0CN: Current Reference Control
#define   B_SINK         7         // IREF0 Current Sink Enable.
#define   M_SINK         0x80      // IREF0 Current Sink Enable.
#define   B_MDSEL        6         // IREF0 Output Mode Select.
#define   M_MDSEL        0x40      // IREF0 Output Mode Select.
#define   BF_IREF0DAT    0         // IREF0 Data Word.
#define   BF_IREF0DAT_0  0         // IREF0 Data Word.
#define   BF_IREF0DAT_1  1         // IREF0 Data Word.
#define   BF_IREF0DAT_2  2         // IREF0 Data Word.
#define   BF_IREF0DAT_3  3         // IREF0 Data Word.
#define   BF_IREF0DAT_4  4         // IREF0 Data Word.
#define   BF_IREF0DAT_5  5         // IREF0 Data Word.
#define   M_IREF0DAT     0x3F      // IREF0 Data Word.

// SFR Definition   7.1.   CPT0CN: Comparator  0 Control
#define   B_CP0EN        7         // Comparator0 Enable Bit.
#define   M_CP0EN        0x80      // Comparator0 Enable Bit.
#define   B_CP0OUT       6         // Comparator0 Output State Flag.
#define   M_CP0OUT       0x40      // Comparator0 Output State Flag.
#define   B_CP0RIF       5         // Comparator0 Rising-Edge Flag. Must be cleared by software.
#define   M_CP0RIF       0x20      // Comparator0 Rising-Edge Flag. Must be cleared by software.
#define   B_CP0FIF       4         // Comparator0 Falling-Edge Flag. Must be cleared by software.
#define   M_CP0FIF       0x10      // Comparator0 Falling-Edge Flag. Must be cleared by software.

// SFR Definition   7.2.   CPT0MD: Comparator 0 Mode Selection
#define   B_CP0RIE       5         // Comparator0 Rising-Edge Interrupt Enable.
#define   M_CP0RIE       0x20      // Comparator0 Rising-Edge Interrupt Enable.
#define   B_CP0FIE       4         // Comparator0 Falling-Edge Interrupt Enable.
#define   M_CP0FIE       0x10      // Comparator0 Falling-Edge Interrupt Enable.
#define   BF_CP0MD       0         // Comparator0 Mode Select
#define   BF_CP0MD_0     0         // Comparator0 Mode Select
#define   BF_CP0MD_1     1         // Comparator0 Mode Select
#define   M_CP0MD        0x03      // Comparator0 Mode Select

// SFR Definition   7.3.   CPT1CN: Comparator  1 Control
#define   B_CP1EN        7         // Comparator1 Enable Bit.
#define   M_CP1EN        0x80      // Comparator1 Enable Bit.
#define   B_CP1OUT       6         // Comparator1 Output State Flag.
#define   M_CP1OUT       0x40      // Comparator1 Output State Flag.
#define   B_CP1RIF       5         // Comparator1 Rising-Edge Flag. Must be cleared by software.
#define   M_CP1RIF       0x20      // Comparator1 Rising-Edge Flag. Must be cleared by software.
#define   B_CP1FIF       4         // Comparator1 Falling-Edge Flag. Must be cleared by software.
#define   M_CP1FIF       0x10      // Comparator1 Falling-Edge Flag. Must be cleared by software.
#define   BF_CP1HYP      2         // Comparator1 Positive Hysteresis Control Bits.
#define   BF_CP1HYP_0    2         // Comparator1 Positive Hysteresis Control Bits.
#define   BF_CP1HYP_1    3         // Comparator1 Positive Hysteresis Control Bits.
#define   M_CP1HYP       0x0C      // Comparator1 Positive Hysteresis Control Bits.
#define   BF_CP1HYN      0         // Comparator1 Negative Hysteresis Control Bits.
#define   BF_CP1HYN_0    0         // Comparator1 Negative Hysteresis Control Bits.
#define   BF_CP1HYN_1    1         // Comparator1 Negative Hysteresis Control Bits.
#define   M_CP1HYN       0x03      // Comparator1 Negative Hysteresis Control Bits.

// SFR Definition   7.4.   CPT1MD: Comparator 1 Mode Selection
#define   B_CP1RIE       5         // Comparator1 Rising-Edge Interrupt Enable.
#define   M_CP1RIE       0x20      // Comparator1 Rising-Edge Interrupt Enable.
#define   B_CP1FIE       4         // Comparator1 Falling-Edge Interrupt Enable.
#define   M_CP1FIE       0x10      // Comparator1 Falling-Edge Interrupt Enable.
#define   BF_CP1MD       0         // Comparator1 Mode Select
#define   BF_CP1MD_0     0         // Comparator1 Mode Select
#define   BF_CP1MD_1     1         // Comparator1 Mode Select
#define   M_CP1MD        0x03      // Comparator1 Mode Select

// SFR Definition   7.5.   CPT0MX: Comparator0 Input Channel Select
#define   BF_CMX0N       4         // Comparator0 Negative Input Selection.
#define   BF_CMX0N_0     4         // Comparator0 Negative Input Selection.
#define   BF_CMX0N_1     5         // Comparator0 Negative Input Selection.
#define   BF_CMX0N_2     6         // Comparator0 Negative Input Selection.
#define   BF_CMX0N_3     7         // Comparator0 Negative Input Selection.
#define   M_CMX0N        0xF0      // Comparator0 Negative Input Selection.
#define   BF_CMX0P       0         // Comparator0 Positive Input Selection.
#define   BF_CMX0P_0     0         // Comparator0 Positive Input Selection.
#define   BF_CMX0P_1     1         // Comparator0 Positive Input Selection.
#define   BF_CMX0P_2     2         // Comparator0 Positive Input Selection.
#define   BF_CMX0P_3     3         // Comparator0 Positive Input Selection.
#define   M_CMX0P        0x0F      // Comparator0 Positive Input Selection.

// SFR Definition   7.6.   CPT1MX: Comparator1 Input Channel Select
#define   BF_CMX1N       4         // Comparator1 Negative Input Selection.
#define   BF_CMX1N_0     4         // Comparator1 Negative Input Selection.
#define   BF_CMX1N_1     5         // Comparator1 Negative Input Selection.
#define   BF_CMX1N_2     6         // Comparator1 Negative Input Selection.
#define   BF_CMX1N_3     7         // Comparator1 Negative Input Selection.
#define   M_CMX1N        0xF0      // Comparator1 Negative Input Selection.
#define   BF_CMX1P       0         // Comparator1 Positive Input Selection.
#define   BF_CMX1P_0     0         // Comparator1 Positive Input Selection.
#define   BF_CMX1P_1     1         // Comparator1 Positive Input Selection.
#define   BF_CMX1P_2     2         // Comparator1 Positive Input Selection.
#define   BF_CMX1P_3     3         // Comparator1 Positive Input Selection.
#define   M_CMX1P        0x0F      // Comparator1 Positive Input Selection.

// SFR Definition   8.6.   PSW: Program Status Word
#define   B_CY           7         // Carry Flag.
#define   M_CY           0x80      // Carry Flag.
#define   B_AC           6         // Auxiliary Carry Flag.
#define   M_AC           0x40      // Auxiliary Carry Flag.
#define   B_F0           5         // User Flag 0.
#define   M_F0           0x20      // User Flag 0.
#define   BF_RS          3         // Register Bank Select.
#define   BF_RS_0        3         // Register Bank Select.
#define   BF_RS_1        4         // Register Bank Select.
#define   M_RS           0x18      // Register Bank Select.
#define   B_OV           2         // Overflow Flag.
#define   M_OV           0x04      // Overflow Flag.
#define   B_F1           1         // User Flag 1.
#define   M_F1           0x02      // User Flag 1.
#define   B_PARITY       0         // Parity Flag.
#define   M_PARITY       0x01      // Parity Flag.

// SFR Definition   10.1.  EMI0CN: External Memory Interface Control
#define   BF_PGSEL       0         // XRAM Page Select.
#define   BF_PGSEL_0     0         // XRAM Page Select.
#define   BF_PGSEL_1     1         // XRAM Page Select.
#define   BF_PGSEL_2     2         // XRAM Page Select.
#define   BF_PGSEL_3     3         // XRAM Page Select.
#define   BF_PGSEL_4     4         // XRAM Page Select.
#define   M_PGSEL        0x1F      // XRAM Page Select.

// SFR Definition   10.2.  EMI0CF: External Me mory Configuration
#define   BF_EMD         2         // EMIF Operating Mode Select.
#define   BF_EMD_0       2         // EMIF Operating Mode Select.
#define   BF_EMD_1       3         // EMIF Operating Mode Select.
#define   M_EMD          0x0C      // EMIF Operating Mode Select.
#define   BF_EALE        0         // ALE Pulse Width Select Bits.
#define   BF_EALE_0      0         // ALE Pulse Width Select Bits.
#define   BF_EALE_1      1         // ALE Pulse Width Select Bits.
#define   M_EALE         0x03      // ALE Pulse Width Select Bits.

// SFR Definition   10.3.  EMI0TC: External Me mory Timing Control
#define   BF_EAS         4         // Address Setup Time Select Bits.
#define   BF_EAS_0       4         // Address Setup Time Select Bits.
#define   BF_EAS_1       5         // Address Setup Time Select Bits.
#define   BF_EAS_2       6         // Address Setup Time Select Bits.
#define   BF_EAS_3       7         // Address Setup Time Select Bits.
#define   M_EAS          0xF0      // Address Setup Time Select Bits.
#define   BF_EWR         2         // RD and  WR Pulse Width Select.
#define   BF_EWR_0       2         // RD and  WR Pulse Width Select.
#define   BF_EWR_1       3         // RD and  WR Pulse Width Select.
#define   M_EWR          0x0C      // RD and  WR Pulse Width Select.
#define   BF_EAH         0         // Address Hold Time Select Bits.
#define   BF_EAH_0       0         // Address Hold Time Select Bits.
#define   BF_EAH_1       1         // Address Hold Time Select Bits.
#define   M_EAH          0x03      // Address Hold Time Select Bits.

// SFR Definition   12.1.  IE: Interrupt Enable
#define   B_EA           7         // Enable All Interrupts.
#define   M_EA           0x80      // Enable All Interrupts.
#define   B_ESPI0        6         // Enable Serial Peripheral Interface (SPI0) Interrupt.
#define   M_ESPI0        0x40      // Enable Serial Peripheral Interface (SPI0) Interrupt.
#define   B_ET2          5         // Enable Timer  2 Interrupt.
#define   M_ET2          0x20      // Enable Timer  2 Interrupt.
#define   B_ES0          4         // Enable UART0 Interrupt.
#define   M_ES0          0x10      // Enable UART0 Interrupt.
#define   B_ET1          3         // Enable Timer  1 Interrupt.
#define   M_ET1          0x08      // Enable Timer  1 Interrupt.
#define   B_EX1          2         // Enable External Interrupt 1.
#define   M_EX1          0x04      // Enable External Interrupt 1.
#define   B_ET0          1         // Enable Timer  0 Interrupt.
#define   M_ET0          0x02      // Enable Timer  0 Interrupt.
#define   B_EX0          0         // Enable External Interrupt 0.
#define   M_EX0          0x01      // Enable External Interrupt 0.

// SFR Definition   12.2.  IP: Interrupt Priority
#define   B_PSPI0        6         // Serial Peripheral Interface (SPI0) Interrupt Priority Control.
#define   M_PSPI0        0x40      // Serial Peripheral Interface (SPI0) Interrupt Priority Control.
#define   B_PT2          5         // Timer 2 Interrupt Priority Control.
#define   M_PT2          0x20      // Timer 2 Interrupt Priority Control.
#define   B_PS0          4         // UART0 Interrupt Priority Control.
#define   M_PS0          0x10      // UART0 Interrupt Priority Control.
#define   B_PT1          3         // Timer 1 Interrupt Priority Control.
#define   M_PT1          0x08      // Timer 1 Interrupt Priority Control.
#define   B_PX1          2         // External Interrupt 1 Priority Control.
#define   M_PX1          0x04      // External Interrupt 1 Priority Control.
#define   B_PT0          1         // Timer 0 Interrupt Priority Control.
#define   M_PT0          0x02      // Timer 0 Interrupt Priority Control.
#define   B_PX0          0         // External Interrupt 0 Priority Control.
#define   M_PX0          0x01      // External Interrupt 0 Priority Control.

// SFR Definition   12.3.  EIE1: Extended Interrupt Enable 1
#define   B_ET3          7         // Enable Timer 3 Interrupt.
#define   M_ET3          0x80      // Enable Timer 3 Interrupt.
#define   B_ECP1         6         // Enable Comparator1 (CP1) Interrupt.
#define   M_ECP1         0x40      // Enable Comparator1 (CP1) Interrupt.
#define   B_ECP0         5         // Enable Comparator0 (CP0) Interrupt.
#define   M_ECP0         0x20      // Enable Comparator0 (CP0) Interrupt.
#define   B_EPCA0        4         // Enable Programmable Counter Array (PCA0) Interrupt.
#define   M_EPCA0        0x10      // Enable Programmable Counter Array (PCA0) Interrupt.
#define   B_EADC0        3         // Enable ADC0 Conversion Complete Interrupt.
#define   M_EADC0        0x08      // Enable ADC0 Conversion Complete Interrupt.
#define   B_EWADC0       2         // Enable Window Comparison ADC0 Interrupt.
#define   M_EWADC0       0x04      // Enable Window Comparison ADC0 Interrupt.
#define   B_ERTC0A       1         // Enable SmaRTClock Alarm Interrupts.
#define   M_ERTC0A       0x02      // Enable SmaRTClock Alarm Interrupts.
#define   B_ESMB0        0         // Enable SMBus (SMB0) Interrupt.
#define   M_ESMB0        0x01      // Enable SMBus (SMB0) Interrupt.

// SFR Definition   12.4.  EIP1: Extended Interrupt Priority 1
#define   B_PT3          7         // Timer  3 Interrupt Priority Control.
#define   M_PT3          0x80      // Timer  3 Interrupt Priority Control.
#define   B_PCP1         6         // Comparator1 (CP1) Interrupt Priority Control.
#define   M_PCP1         0x40      // Comparator1 (CP1) Interrupt Priority Control.
#define   B_PCP0         5         // Comparator0 (CP0) Interrupt Priority Control.
#define   M_PCP0         0x20      // Comparator0 (CP0) Interrupt Priority Control.
#define   B_PPCA0        4         // Programmable Counter Array (PCA0) Interrupt Priority Control.
#define   M_PPCA0        0x10      // Programmable Counter Array (PCA0) Interrupt Priority Control.
#define   B_PADC0        3         // ADC0 Conversion Complete Interrupt Priority Control.
#define   M_PADC0        0x08      // ADC0 Conversion Complete Interrupt Priority Control.
#define   B_PWADC0       2         // ADC0 Window Comparator Interrupt Priority Control.
#define   M_PWADC0       0x04      // ADC0 Window Comparator Interrupt Priority Control.
#define   B_PRTC0A       1         // SmaRTClock Alarm Interrupt Priority Control.
#define   M_PRTC0A       0x02      // SmaRTClock Alarm Interrupt Priority Control.
#define   B_PSMB0        0         // SMBus (SMB0) Interrupt Priority Control.
#define   M_PSMB0        0x01      // SMBus (SMB0) Interrupt Priority Control.

// SFR Definition   12.5.  EIE2: Extended Interrupt Enable 2
#define   B_ESPI1        3         // Enable Serial Peripheral Interface (SPI1) Interrupt.
#define   M_ESPI1        0x08      // Enable Serial Peripheral Interface (SPI1) Interrupt.
#define   B_ERTC0F       2         // Enable SmaRTClock Oscillator Fail Interrupt.
#define   M_ERTC0F       0x04      // Enable SmaRTClock Oscillator Fail Interrupt.
#define   B_EMAT         1         // Enable Port Match Interrupts.
#define   M_EMAT         0x02      // Enable Port Match Interrupts.
#define   B_EWARN        0         // Enable VDD/DC+ Supply Monitor Early Warning Interrupt.
#define   M_EWARN        0x01      // Enable VDD/DC+ Supply Monitor Early Warning Interrupt.

// SFR Definition   12.6.  EIP2: Extended Interrupt Priority 2
#define   B_PSPI1        3         // Serial Peripheral Interface (SPI1) Interrupt Pr iority Control.
#define   M_PSPI1        0x08      // Serial Peripheral Interface (SPI1) Interrupt Pr iority Control.
#define   B_PRTC0F       2         // SmaRTClock Oscillator Fail Interrupt Priority Control.
#define   M_PRTC0F       0x04      // SmaRTClock Oscillator Fail Interrupt Priority Control.
#define   B_PMAT         1         // Port Match Interrupt  Priority Control.
#define   M_PMAT         0x02      // Port Match Interrupt  Priority Control.
#define   B_PWARN        0         // VDD/DC+ Supply Monitor Early Warning Interrupt Priority Control.
#define   M_PWARN        0x01      // VDD/DC+ Supply Monitor Early Warning Interrupt Priority Control.

// SFR Definition   12.7.  IT01CF:  INT0/ INT1 Configuration
#define   B_IN1PL        7         // INT1 Polarity.
#define   M_IN1PL        0x80      // INT1 Polarity.
#define   BF_IN1SL       4         // INT1 Port Pin Se lection Bits.
#define   BF_IN1SL_0     4         // INT1 Port Pin Se lection Bits.
#define   BF_IN1SL_1     5         // INT1 Port Pin Se lection Bits.
#define   BF_IN1SL_2     6         // INT1 Port Pin Se lection Bits.
#define   M_IN1SL        0x70      // INT1 Port Pin Se lection Bits.
#define   B_IN0PL        3         // INT0 Polarity.
#define   M_IN0PL        0x08      // INT0 Polarity.
#define   BF_IN0SL       0         // INT0 Port Pin Se lection Bits.
#define   BF_IN0SL_0     0         // INT0 Port Pin Se lection Bits.
#define   BF_IN0SL_1     1         // INT0 Port Pin Se lection Bits.
#define   BF_IN0SL_2     2         // INT0 Port Pin Se lection Bits.
#define   M_IN0SL        0x07      // INT0 Port Pin Se lection Bits.

// SFR Definition   13.1.  PSCTL: Program Store R/W Control
#define   B_SFLE         2         // Scratchpad Flash Memory Access Enable.
#define   M_SFLE         0x04      // Scratchpad Flash Memory Access Enable.
#define   B_PSEE         1         // Program Store Erase Enable.
#define   M_PSEE         0x02      // Program Store Erase Enable.
#define   B_PSWE         0         // Program Store Write Enable.
#define   M_PSWE         0x01      // Program Store Write Enable.

// SFR Definition   13.3.  FLSCL: Flash Scale
#define   B_BYPASS       6         // Flash Read Timing One-Shot Bypass.
#define   M_BYPASS       0x40      // Flash Read Timing One-Shot Bypass.

// SFR Definition   14.1.  PMU0CF: Power Management Unit Configuration
#define   B_SLEEP        7         // Sleep Mode Select Writing 1 places the
#define   M_SLEEP        0x80      // Sleep Mode Select Writing 1 places the
#define   B_SUSPEND      6         // Suspend Mode Select Writing 1 places the
#define   M_SUSPEND      0x40      // Suspend Mode Select Writing 1 places the
#define   B_CLEAR        5         // Wake-up Flag Clear Writing 1 clears all wake-up flags.
#define   M_CLEAR        0x20      // Wake-up Flag Clear Writing 1 clears all wake-up flags.
#define   B_RSTWK        4         // Reset Pin Wake-up Flag N/A Set to 1 if a glitch has
#define   M_RSTWK        0x10      // Reset Pin Wake-up Flag N/A Set to 1 if a glitch has
#define   B_RTCFWK       3         // SmaRTClock Oscillator
#define   M_RTCFWK       0x08      // SmaRTClock Oscillator
#define   B_RTCAWK       2         // SmaRTClock Alarm
#define   M_RTCAWK       0x04      // SmaRTClock Alarm
#define   B_PMATWK       1         // Port Match Wake-up
#define   M_PMATWK       0x02      // Port Match Wake-up
#define   B_CPT0WK       0         // Comparator0 Wake-up
#define   M_CPT0WK       0x01      // Comparator0 Wake-up

// SFR Definition   14.2.  PCON: Power Manageme nt Control Register
#define   BF_GF          2         // General Purpose Flags Sets the logic value. Returns the logic value.
#define   BF_GF_0        2         // General Purpose Flags Sets the logic value. Returns the logic value.
#define   BF_GF_1        3         // General Purpose Flags Sets the logic value. Returns the logic value.
#define   BF_GF_2        4         // General Purpose Flags Sets the logic value. Returns the logic value.
#define   BF_GF_3        5         // General Purpose Flags Sets the logic value. Returns the logic value.
#define   BF_GF_4        6         // General Purpose Flags Sets the logic value. Returns the logic value.
#define   BF_GF_5        7         // General Purpose Flags Sets the logic value. Returns the logic value.
#define   M_GF           0xFC      // General Purpose Flags Sets the logic value. Returns the logic value.
#define   B_STOP         1         // Stop Mode Select Writing 1 places the
#define   M_STOP         0x02      // Stop Mode Select Writing 1 places the
#define   B_IDLE         0         // Idle Mode Select Writing 1 places the
#define   M_IDLE         0x01      // Idle Mode Select Writing 1 places the

// SFR Definition   15.1.  CRC0CN: CRC0 Control
#define   B_CRC0SEL      4         // CRC0 Polynomial Select Bit.
#define   M_CRC0SEL      0x10      // CRC0 Polynomial Select Bit.
#define   B_CRC0INIT     3         // CRC0 Result Init ialization Bit.
#define   M_CRC0INIT     0x08      // CRC0 Result Init ialization Bit.
#define   B_CRC0VAL      2         // CRC0 Set Value Initialization Bit.
#define   M_CRC0VAL      0x04      // CRC0 Set Value Initialization Bit.
#define   BF_CRC0PNT     0         // CRC0 Result Pointer.
#define   BF_CRC0PNT_0   0         // CRC0 Result Pointer.
#define   BF_CRC0PNT_1   1         // CRC0 Result Pointer.
#define   M_CRC0PNT      0x03      // CRC0 Result Pointer.

// SFR Definition   15.4.  CRC0AUTO: CRC0 Automatic Control
#define   B_AUTOEN       7         // Automatic CRC Calc ulation Enable.
#define   M_AUTOEN       0x80      // Automatic CRC Calc ulation Enable.
#define   B_CRCDONE      6         // CRCDONE Automatic CRC Calculation Complete.
#define   M_CRCDONE      0x40      // CRCDONE Automatic CRC Calculation Complete.
#define   BF_CRC0ST      0         // Automatic CRC Calculation Starting Flash Sector.
#define   BF_CRC0ST_0    0         // Automatic CRC Calculation Starting Flash Sector.
#define   BF_CRC0ST_1    1         // Automatic CRC Calculation Starting Flash Sector.
#define   BF_CRC0ST_2    2         // Automatic CRC Calculation Starting Flash Sector.
#define   BF_CRC0ST_3    3         // Automatic CRC Calculation Starting Flash Sector.
#define   BF_CRC0ST_4    4         // Automatic CRC Calculation Starting Flash Sector.
#define   BF_CRC0ST_5    5         // Automatic CRC Calculation Starting Flash Sector.
#define   M_CRC0ST       0x3F      // Automatic CRC Calculation Starting Flash Sector.

// SFR Definition   15.5.  CRC0CNT: CRC0 Automatic Flash Sector Count
#define   BF_CRC0CNT     0         // Automatic CRC Calculation Flash Sector Count.
#define   BF_CRC0CNT_0   0         // Automatic CRC Calculation Flash Sector Count.
#define   BF_CRC0CNT_1   1         // Automatic CRC Calculation Flash Sector Count.
#define   BF_CRC0CNT_2   2         // Automatic CRC Calculation Flash Sector Count.
#define   BF_CRC0CNT_3   3         // Automatic CRC Calculation Flash Sector Count.
#define   BF_CRC0CNT_4   4         // Automatic CRC Calculation Flash Sector Count.
#define   BF_CRC0CNT_5   5         // Automatic CRC Calculation Flash Sector Count.
#define   M_CRC0CNT      0x3F      // Automatic CRC Calculation Flash Sector Count.

// SFR Definition   16.1.  DC0CN: DC-DC Converter Control
#define   BF_MINPW       6         // DC- DC Converter Minimum Pulse Width.
#define   BF_MINPW_0     6         // DC- DC Converter Minimum Pulse Width.
#define   BF_MINPW_1     7         // DC- DC Converter Minimum Pulse Width.
#define   M_MINPW        0xC0      // DC- DC Converter Minimum Pulse Width.
#define   B_SWSEL        5         // DC-DC Converter Switch Select.
#define   M_SWSEL        0x20      // DC-DC Converter Switch Select.
#define   B_SYNC         3         // ADC0 Synchronization Enable.
#define   M_SYNC         0x08      // ADC0 Synchronization Enable.
#define   BF_VSEL        0         // DC- DC Converter Output Voltage Select.
#define   BF_VSEL_0      0         // DC- DC Converter Output Voltage Select.
#define   BF_VSEL_1      1         // DC- DC Converter Output Voltage Select.
#define   BF_VSEL_2      2         // DC- DC Converter Output Voltage Select.
#define   M_VSEL         0x07      // DC- DC Converter Output Voltage Select.

// SFR Definition   16.2.  DC0CF: DC-DC Conver ter Configuration
#define   BF_DC0CF_CLKDIV      5         // DC- DC Clock Divider.
#define   BF_DC0CF_CLKDIV_0    5         // DC- DC Clock Divider.
#define   BF_DC0CF_CLKDIV_1    6         // DC- DC Clock Divider.
#define   M_DC0CF_CLKDIV       0x60      // DC- DC Clock Divider.
#define   B_CLKINV       3         // DC- DC Converter Clock Invert.
#define   M_CLKINV       0x08      // DC- DC Converter Clock Invert.
#define   B_ILIMIT       2         // Peak Current Limit Threshold.
#define   M_ILIMIT       0x04      // Peak Current Limit Threshold.
#define   B_VDDSLP       1         // VDD-DC+ Sleep Mode Connection.
#define   M_VDDSLP       0x02      // VDD-DC+ Sleep Mode Connection.
#define   B_DC0CF_CLKSEL       0         // DC- DC Converter Clock Source Select.
#define   M_DC0CF_CLKSEL       0x01      // DC- DC Converter Clock Source Select.

// SFR Definition   17.1.  REG0CN: Voltage Regulator Control
#define   B_OSCBIAS      4         // Precision Oscillator Bias.
#define   M_OSCBIAS      0x10      // Precision Oscillator Bias.

// SFR Definition   18.1.  VDM0CN: VDD/DC+ Supply Monitor Control
#define   B_VDMEN        7         // VDD/DC+ Supply Monitor Enable.
#define   M_VDMEN        0x80      // VDD/DC+ Supply Monitor Enable.
#define   B_VDDSTAT      6         // VDD/DC+ Supply Status.
#define   M_VDDSTAT      0x40      // VDD/DC+ Supply Status.
#define   B_VDDOK        5         // VDD/DC+ Supply Status (Early Warning).
#define   M_VDDOK        0x20      // VDD/DC+ Supply Status (Early Warning).

// SFR Definition   18.2.  RSTSRC: Reset Source
#define   B_RTC0RE       7         // SmaRTClock Reset Enable
#define   M_RTC0RE       0x80      // SmaRTClock Reset Enable
#define   B_FERROR       6         // Flash Error Reset Flag. N/A Set to 1 if Flash
#define   M_FERROR       0x40      // Flash Error Reset Flag. N/A Set to 1 if Flash
#define   B_C0RSEF       5         // Comparator0 Reset Enable
#define   M_C0RSEF       0x20      // Comparator0 Reset Enable
#define   B_SWRSF        4         // Software Reset Force and
#define   M_SWRSF        0x10      // Software Reset Force and
#define   B_WDTRSF       3         // Watchdog Timer Reset Flag. N/A Set to 1 if Watchdog Timer
#define   M_WDTRSF       0x08      // Watchdog Timer Reset Flag. N/A Set to 1 if Watchdog Timer
#define   B_MCDRSF       2         // Missing Clock Detector
#define   M_MCDRSF       0x04      // Missing Clock Detector
#define   B_PORSF        1         // Power-On / Power-Fail
#define   M_PORSF        0x02      // Power-On / Power-Fail
#define   B_PINRSF       0         // HW Pin Reset Flag. N/A Set to 1 if RST pin caused
#define   M_PINRSF       0x01      // HW Pin Reset Flag. N/A Set to 1 if RST pin caused

// SFR Definition   19.1.  CLKSEL: Clock Select
#define   B_CLKRDY       7         // System Clock Divider Clock Ready Flag.
#define   M_CLKRDY       0x80      // System Clock Divider Clock Ready Flag.
#define   BF_CLKDIV      4         // System Clock Divider Bits.
#define   BF_CLKDIV_0    4         // System Clock Divider Bits.
#define   BF_CLKDIV_1    5         // System Clock Divider Bits.
#define   BF_CLKDIV_2    6         // System Clock Divider Bits.
#define   M_CLKDIV       0x70      // System Clock Divider Bits.
#define   BF_CLKSEL      0         // System Clock Select.
#define   BF_CLKSEL_0    0         // System Clock Select.
#define   BF_CLKSEL_1    1         // System Clock Select.
#define   BF_CLKSEL_2    2         // System Clock Select.
#define   M_CLKSEL       0x07      // System Clock Select.

// SFR Definition   19.2.  OSCICN: Internal Oscillator Control
#define   B_IOSCEN       7         // Internal Oscill ator Enable.
#define   M_IOSCEN       0x80      // Internal Oscill ator Enable.
#define   B_IFRDY        6         // Internal Oscillator Frequency Ready Flag.
#define   M_IFRDY        0x40      // Internal Oscillator Frequency Ready Flag.

// SFR Definition   19.3.  OSCICL: Internal Oscillator Calibration
#define   B_SSE          7         // Spread Spectrum Enable.
#define   M_SSE          0x80      // Spread Spectrum Enable.
#define   BF_OSCICL      0         // Internal Oscillator Calibration.
#define   BF_OSCICL_0    0         // Internal Oscillator Calibration.
#define   BF_OSCICL_1    1         // Internal Oscillator Calibration.
#define   BF_OSCICL_2    2         // Internal Oscillator Calibration.
#define   BF_OSCICL_3    3         // Internal Oscillator Calibration.
#define   BF_OSCICL_4    4         // Internal Oscillator Calibration.
#define   BF_OSCICL_5    5         // Internal Oscillator Calibration.
#define   BF_OSCICL_6    6         // Internal Oscillator Calibration.
#define   M_OSCICL       0x7F      // Internal Oscillator Calibration.

// SFR Definition   19.4.  OSCXCN: External Oscillator Control
#define   B_XCLKVLD      7         // External Oscillator Valid Flag.
#define   M_XCLKVLD      0x80      // External Oscillator Valid Flag.
#define   BF_XOSCMD      4         // External Oscillator Mode Bits.
#define   BF_XOSCMD_0    4         // External Oscillator Mode Bits.
#define   BF_XOSCMD_1    5         // External Oscillator Mode Bits.
#define   BF_XOSCMD_2    6         // External Oscillator Mode Bits.
#define   M_XOSCMD       0x70      // External Oscillator Mode Bits.
#define   BF_XFCN        0         // External Oscillator Frequency Control Bits.
#define   BF_XFCN_0      0         // External Oscillator Frequency Control Bits.
#define   BF_XFCN_1      1         // External Oscillator Frequency Control Bits.
#define   BF_XFCN_2      2         // External Oscillator Frequency Control Bits.
#define   M_XFCN         0x07      // External Oscillator Frequency Control Bits.

// SFR Definition   20.2.  RTC0ADR: SmaRTClock Address
#define   B_RTC0ADR_BUSY         7         // SmaRTClock Interface Busy Indicator.
#define   M_RTC0ADR_BUSY         0x80      // SmaRTClock Interface Busy Indicator.
#define   B_AUTORD       6         // SmaRTClock Interface Autoread Enable.
#define   M_AUTORD       0x40      // SmaRTClock Interface Autoread Enable.
#define   B_SHORT        4         // Short Strobe Enable.
#define   M_SHORT        0x10      // Short Strobe Enable.
#define   BF_ADDR        0         // SmaRTClock Indirect Register Address.
#define   BF_ADDR_0      0         // SmaRTClock Indirect Register Address.
#define   BF_ADDR_1      1         // SmaRTClock Indirect Register Address.
#define   BF_ADDR_2      2         // SmaRTClock Indirect Register Address.
#define   BF_ADDR_3      3         // SmaRTClock Indirect Register Address.
#define   M_ADDR         0x0F      // SmaRTClock Indirect Register Address.

// Internal Register Definition  20.4. RTC0CN: SmaRTClock Control
#define   B_RTC0EN       7         // SmaRTClock Enable.
#define   M_RTC0EN       0x80      // SmaRTClock Enable.
#define   B_MCLKEN       6         // Missing SmaRTClock Detector Enable.
#define   M_MCLKEN       0x40      // Missing SmaRTClock Detector Enable.
#define   B_OSCFAIL      5         // SmaRTClock Oscillator Fail Event Flag.
#define   M_OSCFAIL      0x20      // SmaRTClock Oscillator Fail Event Flag.
#define   B_RTC0TR       4         // SmaRTClock Timer Run Control.
#define   M_RTC0TR       0x10      // SmaRTClock Timer Run Control.
#define   B_RTC0AEN      3         // SmaRTClock Alarm Enable.
#define   M_RTC0AEN      0x08      // SmaRTClock Alarm Enable.
#define   B_ALRM         2         // SmaRTClock Alarm Event
#define   M_ALRM         0x04      // SmaRTClock Alarm Event
#define   B_RTC0SET      1         // SmaRTClock Timer Set.
#define   M_RTC0SET      0x02      // SmaRTClock Timer Set.
#define   B_RTC0CAP      0         // SmaRTClock Timer Capture.
#define   M_RTC0CAP      0x01      // SmaRTClock Timer Capture.

// Internal Register Definition  20.5. RTC0XCN: SmaRTClock Oscillator Control
#define   B_AGCEN        7         // SmaRTClock Oscillator Automatic Gain Control (AGC) Enable.
#define   M_AGCEN        0x80      // SmaRTClock Oscillator Automatic Gain Control (AGC) Enable.
#define   B_BIASX2       5         // SmaRTClock Oscillator Bias Double Enable.
#define   M_BIASX2       0x20      // SmaRTClock Oscillator Bias Double Enable.
#define   B_CLKVLD       4         // SmaRTClock Oscillator Crystal Valid Indicator.
#define   M_CLKVLD       0x10      // SmaRTClock Oscillator Crystal Valid Indicator.

// Internal Register Definition  20.6. RTC0XCF: SmaRTClock Oscillator Configuration
#define   B_AUTOSTP      7         // Automatic Load Capacitance Stepping Enable.
#define   M_AUTOSTP      0x80      // Automatic Load Capacitance Stepping Enable.
#define   B_LOADRDY      6         // Load Capacitance Ready Indicator.
#define   M_LOADRDY      0x40      // Load Capacitance Ready Indicator.
#define   BF_LOADCAP     0         // Load Capacitance Programmed Value.
#define   BF_LOADCAP_0   0         // Load Capacitance Programmed Value.
#define   BF_LOADCAP_1   1         // Load Capacitance Programmed Value.
#define   BF_LOADCAP_2   2         // Load Capacitance Programmed Value.
#define   BF_LOADCAP_3   3         // Load Capacitance Programmed Value.
#define   M_LOADCAP      0x0F      // Load Capacitance Programmed Value.

// SFR Definition   21.1.  XBR0: Port I/O Crossbar Register 0
#define   B_CP1AE        7         // Comparator1 Asynchronous Output Enable.
#define   M_CP1AE        0x80      // Comparator1 Asynchronous Output Enable.
#define   B_CP1E         6         // Comparator1 Output Enable.
#define   M_CP1E         0x40      // Comparator1 Output Enable.
#define   B_CP0AE        5         // Comparator0 Asynchronous Output Enable.
#define   M_CP0AE        0x20      // Comparator0 Asynchronous Output Enable.
#define   B_CP0E         4         // Comparator0 Output Enable.
#define   M_CP0E         0x10      // Comparator0 Output Enable.
#define   B_SYSCKE       3         // SYSCLK Output Enable.
#define   M_SYSCKE       0x08      // SYSCLK Output Enable.
#define   B_SMB0E        2         // SMBus I/O Enable.
#define   M_SMB0E        0x04      // SMBus I/O Enable.
#define   B_SPI0E        1         // SPI0 I/O Enable
#define   M_SPI0E        0x02      // SPI0 I/O Enable
#define   B_URT0E        0         // UART0 Output Enable.
#define   M_URT0E        0x01      // UART0 Output Enable.

// SFR Definition   21.2.  XBR1: Port I/O Crossbar Register 1
#define   B_SPI1E        6         // SPI1 I/O Enable.
#define   M_SPI1E        0x40      // SPI1 I/O Enable.
#define   B_T1E          5         // Timer1 Input Enable.
#define   M_T1E          0x20      // Timer1 Input Enable.
#define   B_T0E          4         // Timer0 Input Enable.
#define   M_T0E          0x10      // Timer0 Input Enable.
#define   B_ECIE         3         // PCA0 External Counter Input (ECI) Enable.
#define   M_ECIE         0x08      // PCA0 External Counter Input (ECI) Enable.
#define   BF_PCA0ME      0         // PCA0 Module I/O Enable.
#define   BF_PCA0ME_0    0         // PCA0 Module I/O Enable.
#define   BF_PCA0ME_1    1         // PCA0 Module I/O Enable.
#define   BF_PCA0ME_2    2         // PCA0 Module I/O Enable.
#define   M_PCA0ME       0x07      // PCA0 Module I/O Enable.

// SFR Definition   21.3.  XBR2: Port I/O Crossbar Register 2
#define   B_WEAKPUD      7         // Port I/O Weak Pullup Disable.
#define   M_WEAKPUD      0x80      // Port I/O Weak Pullup Disable.
#define   B_XBARE        6         // Crossbar Enable.
#define   M_XBARE        0x40      // Crossbar Enable.

// SFR Definition   22.1.  SMB0CF: SMBus Clock/Configuration
#define   B_ENSMB        7         // SMBus Enable.
#define   M_ENSMB        0x80      // SMBus Enable.
#define   B_INH          6         // SMBus Slave Inhibit.
#define   M_INH          0x40      // SMBus Slave Inhibit.
#define   B_BUSY         5         // SMBus Busy Indicator.
#define   M_BUSY         0x20      // SMBus Busy Indicator.
#define   B_EXTHOLD      4         // SMBus Setup and Hold Time Extension Enable.
#define   M_EXTHOLD      0x10      // SMBus Setup and Hold Time Extension Enable.
#define   B_SMBTOE       3         // SMBus SCL Timeout Detection Enable.
#define   M_SMBTOE       0x08      // SMBus SCL Timeout Detection Enable.
#define   B_SMBFTE       2         // SMBus Free Timeout Detection Enable.
#define   M_SMBFTE       0x04      // SMBus Free Timeout Detection Enable.
#define   BF_SMBCS       0         // SMBus Clock Source Selection.
#define   BF_SMBCS_0     0         // SMBus Clock Source Selection.
#define   BF_SMBCS_1     1         // SMBus Clock Source Selection.
#define   M_SMBCS        0x03      // SMBus Clock Source Selection.

// SFR Definition   22.2.  SMB0CN: SMBus Control
#define   B_MASTER       7         // SMBus Master/Slave
#define   M_MASTER       0x80      // SMBus Master/Slave
#define   B_TXMODE       6         // SMBus Transmit Mode
#define   M_TXMODE       0x40      // SMBus Transmit Mode
#define   B_STA          5         // SMBus Start Flag. 0: No Start or repeated
#define   M_STA          0x20      // SMBus Start Flag. 0: No Start or repeated
#define   B_STO          4         // SMBus Stop Flag. 0: No Stop condition
#define   M_STO          0x10      // SMBus Stop Flag. 0: No Stop condition
#define   B_ACKRQ        3         // SMBus Acknowledge
#define   M_ACKRQ        0x08      // SMBus Acknowledge
#define   B_ARBLOST      2         // SMBus Arbitration Lost
#define   M_ARBLOST      0x04      // SMBus Arbitration Lost
#define   B_ACK          1         // SMBus Acknowledge. 0: NACK received.
#define   M_ACK          0x02      // SMBus Acknowledge. 0: NACK received.
#define   B_SI           0         // SMBus Interrupt Flag.
#define   M_SI           0x01      // SMBus Interrupt Flag.

// SFR Definition   22.3.  SMB0ADR: SMBus Slave Address
#define   BF_SLV         1         // SMBus Hardware Slave Address.
#define   BF_SLV_0       1         // SMBus Hardware Slave Address.
#define   BF_SLV_1       2         // SMBus Hardware Slave Address.
#define   BF_SLV_2       3         // SMBus Hardware Slave Address.
#define   BF_SLV_3       4         // SMBus Hardware Slave Address.
#define   BF_SLV_4       5         // SMBus Hardware Slave Address.
#define   BF_SLV_5       6         // SMBus Hardware Slave Address.
#define   BF_SLV_6       7         // SMBus Hardware Slave Address.
#define   M_SLV          0xFE      // SMBus Hardware Slave Address.
#define   B_GC           0         // General Call Address Enable.
#define   M_GC           0x01      // General Call Address Enable.

// SFR Definition   22.4.  SMB0ADM: SMBus Slave Address Mask
#define   BF_SLVM        1         // SMBus Slave Address Mask.
#define   BF_SLVM_0      1         // SMBus Slave Address Mask.
#define   BF_SLVM_1      2         // SMBus Slave Address Mask.
#define   BF_SLVM_2      3         // SMBus Slave Address Mask.
#define   BF_SLVM_3      4         // SMBus Slave Address Mask.
#define   BF_SLVM_4      5         // SMBus Slave Address Mask.
#define   BF_SLVM_5      6         // SMBus Slave Address Mask.
#define   BF_SLVM_6      7         // SMBus Slave Address Mask.
#define   M_SLVM         0xFE      // SMBus Slave Address Mask.
#define   B_EHACK        0         // Hardware Acknowledge Enable.
#define   M_EHACK        0x01      // Hardware Acknowledge Enable.

// SFR Definition   23.1.  SCON0: Serial Port 0 Control
#define   B_S0MODE       7         // Serial Port 0 Operation Mode.
#define   M_S0MODE       0x80      // Serial Port 0 Operation Mode.
#define   B_MCE0         5         // Multiprocessor Communication Enable.
#define   M_MCE0         0x20      // Multiprocessor Communication Enable.
#define   B_REN0         4         // Serial Port 0 Operation Mode.
#define   M_REN0         0x10      // Serial Port 0 Operation Mode.
#define   B_TB80         3         // Ninth Transmission Bit.
#define   M_TB80         0x08      // Ninth Transmission Bit.
#define   B_RB80         2         // Ninth Receive Bit.
#define   M_RB80         0x04      // Ninth Receive Bit.
#define   B_TI0          1         // Transmit Interrupt Flag.
#define   M_TI0          0x02      // Transmit Interrupt Flag.
#define   B_RI0          0         // Receive Interrupt Flag.
#define   M_RI0          0x01      // Receive Interrupt Flag.

// SFR Definition   24.1.  SPI0CFG: SPI Configuration
#define   B_SPIBSY0       7         // SPI Busy.
#define   M_SPIBSY0       0x80      // SPI Busy.
#define   B_MSTEN0        6         // Master Mode Enable.
#define   M_MSTEN0        0x40      // Master Mode Enable.
#define   B_CKPHA0        5         // SPI Clock Phase.
#define   M_CKPHA0        0x20      // SPI Clock Phase.
#define   B_CKPOL0        4         // SPI Clock Polarity.
#define   M_CKPOL0        0x10      // SPI Clock Polarity.
#define   B_SLVSEL0       3         // Slave Selected Flag.
#define   M_SLVSEL0       0x08      // Slave Selected Flag.
#define   B_NSSIN0        2         // NSS Instantaneous Pin Input.
#define   M_NSSIN0        0x04      // NSS Instantaneous Pin Input.
#define   B_SRMT0         1         // Shift Register Empty (valid in slave mode only).
#define   M_SRMT0         0x02      // Shift Register Empty (valid in slave mode only).
#define   B_RXBMT0        0         // Receive Buffer Empty (valid in slave mode only).
#define   M_RXBMT0        0x01      // Receive Buffer Empty (valid in slave mode only).

// SFR Definition   24.1.  SPI1CFG: SPI Configuration
#define   B_SPIBSY1       7         // SPI Busy.
#define   M_SPIBSY1       0x80      // SPI Busy.
#define   B_MSTEN1        6         // Master Mode Enable.
#define   M_MSTEN1        0x40      // Master Mode Enable.
#define   B_CKPHA1        5         // SPI Clock Phase.
#define   M_CKPHA1        0x20      // SPI Clock Phase.
#define   B_CKPOL1        4         // SPI Clock Polarity.
#define   M_CKPOL1        0x10      // SPI Clock Polarity.
#define   B_SLVSEL1       3         // Slave Selected Flag.
#define   M_SLVSEL1       0x08      // Slave Selected Flag.
#define   B_NSSIN1        2         // NSS Instantaneous Pin Input.
#define   M_NSSIN1        0x04      // NSS Instantaneous Pin Input.
#define   B_SRMT1         1         // Shift Register Empty (valid in slave mode only).
#define   M_SRMT1         0x02      // Shift Register Empty (valid in slave mode only).
#define   B_RXBMT1        0         // Receive Buffer Empty (valid in slave mode only).
#define   M_RXBMT1        0x01      // Receive Buffer Empty (valid in slave mode only).

// SFR Definition   24.2.  SPI0CN: SPI Control
#define   B_SPIF0        7         // SPIn Interrupt Flag.
#define   M_SPIF0        0x80      // SPIn Interrupt Flag.
#define   B_WCOL0        6         // Write Collision Flag.
#define   M_WCOL0        0x40      // Write Collision Flag.
#define   B_MODF0        5         // Mode Fault Flag.
#define   M_MODF0        0x20      // Mode Fault Flag.
#define   B_RXOVRN0      4         // Receive Overrun Flag (valid in slave mode only).
#define   M_RXOVRN0      0x10      // Receive Overrun Flag (valid in slave mode only).
#define   BF_NSS0MD      2         // Slave Select Mode.
#define   BF_NSS0MD_0    2         // Slave Select Mode.
#define   BF_NSS0MD_1    3         // Slave Select Mode.
#define   M_NSS0MD       0x0C      // Slave Select Mode.
#define   B_TXBMT0       1         // Transmit Buffer Empty.
#define   M_TXBMT0       0x02      // Transmit Buffer Empty.
#define   B_SPI0EN       0         // SPIn Enable.
#define   M_SPI0EN       0x01      // SPIn Enable.

// SFR Definition   24.2.  SPI1CN: SPI Control
#define   B_SPIF1        7         // SPIn Interrupt Flag.
#define   M_SPIF1        0x80      // SPIn Interrupt Flag.
#define   B_WCOL1        6         // Write Collision Flag.
#define   M_WCOL1        0x40      // Write Collision Flag.
#define   B_MODF1        5         // Mode Fault Flag.
#define   M_MODF1        0x20      // Mode Fault Flag.
#define   B_RXOVRN1      4         // Receive Overrun Flag (valid in slave mode only).
#define   M_RXOVRN1      0x10      // Receive Overrun Flag (valid in slave mode only).
#define   BF_NSS1MD      2         // Slave Select Mode.
#define   BF_NSS1MD_0    2         // Slave Select Mode.
#define   BF_NSS1MD_1    3         // Slave Select Mode.
#define   M_NSS1MD       0x0C      // Slave Select Mode.
#define   B_TXBMT1       1         // Transmit Buffer Empty.
#define   M_TXBMT1       0x02      // Transmit Buffer Empty.
#define   B_SPI1EN       0         // SPIn Enable.
#define   M_SPI1EN       0x01      // SPIn Enable.

// SFR Definition   25.1.  CKCON: Clock Control
#define   B_T3MH         7         // Timer  3 High Byte Clock Select.
#define   M_T3MH         0x80      // Timer  3 High Byte Clock Select.
#define   B_T3ML         6         // Timer  3 Low Byte Clock Select.
#define   M_T3ML         0x40      // Timer  3 Low Byte Clock Select.
#define   B_T2MH         5         // Timer  2 High Byte Clock Select.
#define   M_T2MH         0x20      // Timer  2 High Byte Clock Select.
#define   B_T2ML         4         // Timer  2 Low Byte Clock Select.
#define   M_T2ML         0x10      // Timer  2 Low Byte Clock Select.
#define   B_T1M          3         // Timer  1 Clock Select.
#define   M_T1M          0x08      // Timer  1 Clock Select.
#define   B_T0M          2         // Timer  0 Clock Select.
#define   M_T0M          0x04      // Timer  0 Clock Select.
#define   BF_SCA         0         // Timer  0/1 Prescale Bits.
#define   BF_SCA_0       0         // Timer  0/1 Prescale Bits.
#define   BF_SCA_1       1         // Timer  0/1 Prescale Bits.
#define   M_SCA          0x03      // Timer  0/1 Prescale Bits.

// SFR Definition   25.2.  TCON: Timer Control
#define   B_TF1          7         // Timer  1 Overflow Flag.
#define   M_TF1          0x80      // Timer  1 Overflow Flag.
#define   B_TR1          6         // Timer  1 Run Control.
#define   M_TR1          0x40      // Timer  1 Run Control.
#define   B_TF0          5         // Timer  0 Overflow Flag.
#define   M_TF0          0x20      // Timer  0 Overflow Flag.
#define   B_TR0          4         // Timer  0 Run Control.
#define   M_TR0          0x10      // Timer  0 Run Control.
#define   B_IE1          3         // External Interrupt 1.
#define   M_IE1          0x08      // External Interrupt 1.
#define   B_IT1          2         // Interrupt 1 Type Select.
#define   M_IT1          0x04      // Interrupt 1 Type Select.
#define   B_IE0          1         // External Interrupt 0.
#define   M_IE0          0x02      // External Interrupt 0.
#define   B_IT0          0         // Interrupt 0 Type Select.
#define   M_IT0          0x01      // Interrupt 0 Type Select.

// SFR Definition   25.3.  TMOD: Timer Mode
#define   B_GATE1        7         // Timer  1 Gate Control.
#define   M_GATE1        0x80      // Timer  1 Gate Control.
#define   BF_TMOD_T1M         4         // Timer  1 Mode Select.
#define   BF_TMOD_T1M_0       4         // Timer  1 Mode Select.
#define   BF_TMOD_T1M_1       5         // Timer  1 Mode Select.
#define   M_TMOD_T1M          0x30      // Timer  1 Mode Select.
#define   B_GATE0        3         // Timer  0 Gate Control.
#define   M_GATE0        0x08      // Timer  0 Gate Control.
#define   BF_TMOD_T0M         0         // Timer  0 Mode Select.
#define   BF_TMOD_T0M_0       0         // Timer  0 Mode Select.
#define   BF_TMOD_T0M_1       1         // Timer  0 Mode Select.
#define   M_TMOD_T0M          0x03      // Timer  0 Mode Select.

// SFR Definition   25.8.  TMR2CN: Timer 2 Control
#define   B_TF2H         7         // Timer  2 High Byte Overflow Flag.
#define   M_TF2H         0x80      // Timer  2 High Byte Overflow Flag.
#define   B_TF2L         6         // Timer  2 Low Byte Overflow Flag.
#define   M_TF2L         0x40      // Timer  2 Low Byte Overflow Flag.
#define   B_TF2LEN       5         // Timer  2 Low Byte Interrupt Enable.
#define   M_TF2LEN       0x20      // Timer  2 Low Byte Interrupt Enable.
#define   B_TF2CEN       4         // Timer  2 Capture Enable.
#define   M_TF2CEN       0x10      // Timer  2 Capture Enable.
#define   B_T2SPLIT      3         // Timer  2 Split Mode Enable.
#define   M_T2SPLIT      0x08      // Timer  2 Split Mode Enable.
#define   B_TR2          2         // Timer  2 Run Control.
#define   M_TR2          0x04      // Timer  2 Run Control.
#define   BF_T2XCLK      0         // Timer  2 External Clock Select.
#define   BF_T2XCLK_0    0         // Timer  2 External Clock Select.
#define   BF_T2XCLK_1    1         // Timer  2 External Clock Select.
#define   M_T2XCLK       0x03      // Timer  2 External Clock Select.

// SFR Definition   25.13.   TMR3CN: Timer 3 Control
#define   B_TF3H         7         // Timer  3 High Byte Overflow Flag.
#define   M_TF3H         0x80      // Timer  3 High Byte Overflow Flag.
#define   B_TF3L         6         // Timer  3 Low Byte Overflow Flag.
#define   M_TF3L         0x40      // Timer  3 Low Byte Overflow Flag.
#define   B_TF3LEN       5         // Timer  3 Low Byte Interrupt Enable.
#define   M_TF3LEN       0x20      // Timer  3 Low Byte Interrupt Enable.
#define   B_TF3CEN       4         // Timer  3 Comparator  1/External Oscillator Capture Enable.
#define   M_TF3CEN       0x10      // Timer  3 Comparator  1/External Oscillator Capture Enable.
#define   B_T3SPLIT      3         // Timer  3 Split Mode Enable.
#define   M_T3SPLIT      0x08      // Timer  3 Split Mode Enable.
#define   B_TR3          2         // Timer  3 Run Control.
#define   M_TR3          0x04      // Timer  3 Run Control.
#define   BF_T3XCLK      0         // Timer  3 External Clock Select.
#define   BF_T3XCLK_0    0         // Timer  3 External Clock Select.
#define   BF_T3XCLK_1    1         // Timer  3 External Clock Select.
#define   M_T3XCLK       0x03      // Timer  3 External Clock Select.

// SFR Definition   26.1.  PCA0CN: PCA Control
#define   B_CF           7         // PCA Counter/Timer Overflow Flag.
#define   M_CF           0x80      // PCA Counter/Timer Overflow Flag.
#define   B_CR           6         // PCA Counter/Timer Run Control.
#define   M_CR           0x40      // PCA Counter/Timer Run Control.
#define   BF_CCF         0         // PCA Module n Capture/Compare Flag.
#define   BF_CCF_0       0         // PCA Module n Capture/Compare Flag.
#define   BF_CCF_1       1         // PCA Module n Capture/Compare Flag.
#define   BF_CCF_2       2         // PCA Module n Capture/Compare Flag.
#define   BF_CCF_3       3         // PCA Module n Capture/Compare Flag.
#define   BF_CCF_4       4         // PCA Module n Capture/Compare Flag.
#define   BF_CCF_5       5         // PCA Module n Capture/Compare Flag.
#define   M_CCF          0x3F      // PCA Module n Capture/Compare Flag.

// SFR Definition   26.2.  PCA0MD: PCA Mode
#define   B_CIDL         7         // PCA Counter/Timer Idle Control.
#define   M_CIDL         0x80      // PCA Counter/Timer Idle Control.
#define   B_WDTE         6         // Watchdog Timer Enable.
#define   M_WDTE         0x40      // Watchdog Timer Enable.
#define   B_WDLCK        5         // Watchdog Timer Lock.
#define   M_WDLCK        0x20      // Watchdog Timer Lock.
#define   BF_CPS         1         // PCA Counter/Timer Pulse Select.
#define   BF_CPS_0       1         // PCA Counter/Timer Pulse Select.
#define   BF_CPS_1       2         // PCA Counter/Timer Pulse Select.
#define   BF_CPS_2       3         // PCA Counter/Timer Pulse Select.
#define   M_CPS          0x0E      // PCA Counter/Timer Pulse Select.
#define   B_ECF          0         // PCA Counter/Timer Overflow Interrupt Enable.
#define   M_ECF          0x01      // PCA Counter/Timer Overflow Interrupt Enable.

// SFR Definition   26.3.  PCA0PWM: PCA PWM Configuration
#define   B_ARSEL        7         // Auto-Reload Register Select.
#define   M_ARSEL        0x80      // Auto-Reload Register Select.
#define   B_ECOV         6         // Cycle Overflow Interrupt Enable.
#define   M_ECOV         0x40      // Cycle Overflow Interrupt Enable.
#define   B_COVF         5         // Cycle Overflow Flag.
#define   M_COVF         0x20      // Cycle Overflow Flag.
#define   BF_CLSEL       0         // Cycle Length Select.
#define   BF_CLSEL_0     0         // Cycle Length Select.
#define   BF_CLSEL_1     1         // Cycle Length Select.
#define   M_CLSEL        0x03      // Cycle Length Select.

// SFR Definition   26.4.  PCA0CPM0: PCA Capture/Compare Mode
#define   B_ECOM0        6         // Comparator Function Enable.
#define   M_ECOM0        0x40      // Comparator Function Enable.
#define   B_CAPP0        5         // Capture Positive Function Enable.
#define   M_CAPP0        0x20      // Capture Positive Function Enable.
#define   B_CAPN0        4         // Capture Negative Function Enable.
#define   M_CAPN0        0x10      // Capture Negative Function Enable.
#define   B_MAT0         3         // Match Function Enable.
#define   M_MAT0         0x08      // Match Function Enable.
#define   B_TOG0         2         // Toggle Function Enable.
#define   M_TOG0         0x04      // Toggle Function Enable.
#define   B_PWM0         1         // Pulse Width Modulation Mode Enable.
#define   M_PWM0         0x02      // Pulse Width Modulation Mode Enable.
#define   B_ECCF0        0         // Capture/Compare Flag Interrupt Enable.
#define   M_ECCF0        0x01      // Capture/Compare Flag Interrupt Enable.

// SFR Definition   26.4.  PCA0CPM1: PCA Capture/Compare Mode
#define   B_PWM161       7         // 16-bit Pulse Width Modulation Enable.
#define   M_PWM161       0x80      // 16-bit Pulse Width Modulation Enable.
#define   B_ECOM1        6         // Comparator Function Enable.
#define   M_ECOM1        0x40      // Comparator Function Enable.
#define   B_CAPP1        5         // Capture Positive Function Enable.
#define   M_CAPP1        0x20      // Capture Positive Function Enable.
#define   B_CAPN1        4         // Capture Negative Function Enable.
#define   M_CAPN1        0x10      // Capture Negative Function Enable.
#define   B_MAT1         3         // Match Function Enable.
#define   M_MAT1         0x08      // Match Function Enable.
#define   B_TOG1         2         // Toggle Function Enable.
#define   M_TOG1         0x04      // Toggle Function Enable.
#define   B_PWM1         1         // Pulse Width Modulation Mode Enable.
#define   M_PWM1         0x02      // Pulse Width Modulation Mode Enable.
#define   B_ECCF1        0         // Capture/Compare Flag Interrupt Enable.
#define   M_ECCF1        0x01      // Capture/Compare Flag Interrupt Enable.

// SFR Definition   26.4.  PCA0CPM2: PCA Capture/Compare Mode
#define   B_PWM162       7         // 16-bit Pulse Width Modulation Enable.
#define   M_PWM162       0x80      // 16-bit Pulse Width Modulation Enable.
#define   B_ECOM2        6         // Comparator Function Enable.
#define   M_ECOM2        0x40      // Comparator Function Enable.
#define   B_CAPP2        5         // Capture Positive Function Enable.
#define   M_CAPP2        0x20      // Capture Positive Function Enable.
#define   B_CAPN2        4         // Capture Negative Function Enable.
#define   M_CAPN2        0x10      // Capture Negative Function Enable.
#define   B_MAT2         3         // Match Function Enable.
#define   M_MAT2         0x08      // Match Function Enable.
#define   B_TOG2         2         // Toggle Function Enable.
#define   M_TOG2         0x04      // Toggle Function Enable.
#define   B_PWM2         1         // Pulse Width Modulation Mode Enable.
#define   M_PWM2         0x02      // Pulse Width Modulation Mode Enable.
#define   B_ECCF2        0         // Capture/Compare Flag Interrupt Enable.
#define   M_ECCF2        0x01      // Capture/Compare Flag Interrupt Enable.

// SFR Definition   26.4.  PCA0CPM3: PCA Capture/Compare Mode
#define   B_PWM163       7         // 16-bit Pulse Width Modulation Enable.
#define   M_PWM163       0x80      // 16-bit Pulse Width Modulation Enable.
#define   B_ECOM3        6         // Comparator Function Enable.
#define   M_ECOM3        0x40      // Comparator Function Enable.
#define   B_CAPP3        5         // Capture Positive Function Enable.
#define   M_CAPP3        0x20      // Capture Positive Function Enable.
#define   B_CAPN3        4         // Capture Negative Function Enable.
#define   M_CAPN3        0x10      // Capture Negative Function Enable.
#define   B_MAT3         3         // Match Function Enable.
#define   M_MAT3         0x08      // Match Function Enable.
#define   B_TOG3         2         // Toggle Function Enable.
#define   M_TOG3         0x04      // Toggle Function Enable.
#define   B_PWM3         1         // Pulse Width Modulation Mode Enable.
#define   M_PWM3         0x02      // Pulse Width Modulation Mode Enable.
#define   B_ECCF3        0         // Capture/Compare Flag Interrupt Enable.
#define   M_ECCF3        0x01      // Capture/Compare Flag Interrupt Enable.

// SFR Definition   26.4.  PCA0CPM4: PCA Capture/Compare Mode
#define   B_PWM164       7         // 16-bit Pulse Width Modulation Enable.
#define   M_PWM164       0x80      // 16-bit Pulse Width Modulation Enable.
#define   B_ECOM4        6         // Comparator Function Enable.
#define   M_ECOM4        0x40      // Comparator Function Enable.
#define   B_CAPP4        5         // Capture Positive Function Enable.
#define   M_CAPP4        0x20      // Capture Positive Function Enable.
#define   B_CAPN4        4         // Capture Negative Function Enable.
#define   M_CAPN4        0x10      // Capture Negative Function Enable.
#define   B_MAT4         3         // Match Function Enable.
#define   M_MAT4         0x08      // Match Function Enable.
#define   B_TOG4         2         // Toggle Function Enable.
#define   M_TOG4         0x04      // Toggle Function Enable.
#define   B_PWM4         1         // Pulse Width Modulation Mode Enable.
#define   M_PWM4         0x02      // Pulse Width Modulation Mode Enable.
#define   B_ECCF4        0         // Capture/Compare Flag Interrupt Enable.
#define   M_ECCF4        0x01      // Capture/Compare Flag Interrupt Enable.

// SFR Definition   26.4.  PCA0CPM5: PCA Capture/Compare Mode
#define   B_PWM165       7         // 16-bit Pulse Width Modulation Enable.
#define   M_PWM165       0x80      // 16-bit Pulse Width Modulation Enable.
#define   B_ECOM5        6         // Comparator Function Enable.
#define   M_ECOM5        0x40      // Comparator Function Enable.
#define   B_CAPP5        5         // Capture Positive Function Enable.
#define   M_CAPP5        0x20      // Capture Positive Function Enable.
#define   B_CAPN5        4         // Capture Negative Function Enable.
#define   M_CAPN5        0x10      // Capture Negative Function Enable.
#define   B_MAT5         3         // Match Function Enable.
#define   M_MAT5         0x08      // Match Function Enable.
#define   B_TOG5         2         // Toggle Function Enable.
#define   M_TOG5         0x04      // Toggle Function Enable.
#define   B_PWM5         1         // Pulse Width Modulation Mode Enable.
#define   M_PWM5         0x02      // Pulse Width Modulation Mode Enable.
#define   B_ECCF5        0         // Capture/Compare Flag Interrupt Enable.
#define   M_ECCF5        0x01      // Capture/Compare Flag Interrupt Enable.

#endif /* C8051F930_DEFS_ADD_H_ */
