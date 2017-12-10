/*! @file main.c
 * @brief The main.c file of the Empty Project example for Si446x devices.
 *
 * Contains the initialization of the MCU & the radio.
 * @n The main loop controls the program flow & the radio.
 *
 * @b CREATED
 * @n Silicon Laboratories Hungary Ltd.
 *
 * @b COPYRIGHT
 * @n Silicon Laboratories Confidential
 * @n Copyright 2012 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 *
 */

#include "..\bsp.h"


/*------------------------------------------------------------------------*/
/*                            Local Macros                                */
/*------------------------------------------------------------------------*/

/*------------------------------------------------------------------------*/
/*                          Local variables                               */
/*------------------------------------------------------------------------*/

/*------------------------------------------------------------------------*/
/*                      Local function prototypes                         */
/*------------------------------------------------------------------------*/
void vPlf_McuInit  (void);
void vInitializeHW (void);

/*------------------------------------------------------------------------*/
/*                          Function implementations                      */
/*------------------------------------------------------------------------*/

/** \fn void main(void)
 * \brief The main function of the demo.
 *
 * \todo Create description
 */
void main(void)
{
  // Initialize the Hardware and Radio
  vInitializeHW();

#ifdef SILABS_LCD_DOG_GLCD
  /* Initialize graphic LCD */
  vLcd_InitLcd();

  /* Set logo location to center */
  bLcd_LcdSetPictureCursor(bLcd_Line1_c, 35u);

  /* Draw SiLabs logo */
  vLcd_LcdDrawPicture(silabs66x30);
#endif

#ifdef SILABS_PLATFORM_WMB912
  /* Switch on LED1 */
  vCio_SetLed(0x01);
#else
  /* Switch on LED2 */
  LED1 = ILLUMINATE;
#endif

  while (TRUE)
  {
    // Place your code here.
  }
}

/**
 *  Calls the init functions for the used peripherals/modules
 *
 *  @note Should be called at the beginning of the main().
 *
 */
void vInitializeHW(void)
{
  // Initialize the MCU peripherals
  vPlf_McuInit();

  // Initialize the Radio
  vRadio_Init();
}

/** \fn void MCU_Init(void)
 *  \brief Initializes ports of the MCU.
 *
 *  \return None
 *
 *  \note It has to be called from the Initialization section.
 *  \todo Create description
 */
void vPlf_McuInit(void)
{
  U16 wDelay = 0xFFFF;

  /* disable watchdog */
  PCA0MD &= (~M_WDTE);

  /* Init Internal Precision Oscillator (24.5MHz) */
  SFRPAGE = LEGACY_PAGE;
  FLSCL   = M_BYPASS;

  OSCICN |= M_IOSCEN; // p7: Internal Prec. Osc. enabled
  CLKSEL  = 0x00;     // Int. Prec. Osc. selected (24.5MHz)

#if ((defined SILABS_PLATFORM_RFSTICK) || (defined SILABS_PLATFORM_LCDBB))
  P0MDOUT = M_P0_UART_TX; //PBs: P0.0-P0.3 (same as RF_GPIO0-3) used as input
  P1MDOUT = M_P1_SPI1_SCK | M_P1_SPI1_MOSI | M_P1_RF_NSEL | M_P1_RF_PWRDN;
  P2MDOUT = M_P2_LED1 | M_P2_LED2 | M_P2_LED3 | M_P2_LED4 | M_P2_BZ1;
#if (defined SILABS_PLATFORM_LCDBB)
  P1MDOUT |= M_P1_LCD_NSEL | M_P1_LCD_A0;
#endif

  P0SKIP  = (~M_P0_UART_TX) & (~M_P0_UART_RX) & (~M_P0_I2C_SCL) & (~M_P0_I2C_SDA); //skip all on port, but UART & SMBus
  P1SKIP  = (~M_P1_SPI1_SCK) & (~M_P1_SPI1_MISO) & (~M_P1_SPI1_MOSI); //skip all on port, but SPI1
  P2SKIP  = (~M_P2_BZ1); //skip all on port, but buzzer with PCA CEX0
#elif ((defined SILABS_MCU_DC_EMIF_F930) || (SILABS_MCU_DC_EMIF_F930_STANDALONE))

#if (defined SILABS_MCU_DC_EMIF_F930)
  // Init master hw SPI interface (SCK clock: 2.45MHz)
  // Init SPI0 (LCD)
  SPI0CFG = M_MSTEN0; //p6: SPI0 enable master mode
  SPI0CN  = M_SPI0EN; //p1: SPI0 enable
  SPI0CKR = 0x04;     //fSCK = SYSCLK / 10
#endif

  P0MDOUT = M_P0_UART_TX | M_P0_LED1 | M_P0_LED2 | M_P0_LED3 | M_P0_LED4;
  P1MDOUT = M_P1_SPI1_SCK | M_P1_SPI1_MOSI | M_P1_RF_NSEL;
  P2MDOUT = M_P2_RF_PWRDN;
#if (defined SILABS_MCU_DC_EMIF_F930)
  P1MDOUT |= M_P1_SPI0_SCK | M_P1_SPI0_MOSI;
  P2MDOUT |=  M_P2_LCD_NSEL | M_P2_LCD_A0;
#endif

  P0SKIP  = (~M_P0_UART_TX) & (~M_P0_UART_RX) ; //skip all on port, but UART
  P1SKIP  = (~M_P1_SPI1_SCK) & (~M_P1_SPI1_MISO) & (~M_P1_SPI1_MOSI); //skip all on port, but SPI1
  P2SKIP  = (~M_P2_I2C_SCL) & (~M_P2_I2C_SDA); //skip all on port, but SMBus
#if (defined SILABS_MCU_DC_EMIF_F930)
  P1SKIP  &= (~M_P1_SPI0_SCK) & (~M_P1_SPI0_MISO) & (~M_P1_SPI0_MOSI); //do not skip SPI0 for LCD
#endif

#elif (defined SILABS_PLATFORM_WMB930)
  /* Port IN/OUT init */
  P0MDOUT = 0x80;
  P1MDOUT = 0xF5;
  P2MDOUT = 0x49;

  P0SKIP  = 0xCF;
  P1SKIP  = 0x18;
  P2SKIP  = 0xB9;
#elif (defined SILABS_PLATFORM_WMB912)
  /* Port IN/OUT init */
  /* P0: 2,3,4,6,7 push-pull */
  /* P1: 0,2,3,6 push-pull */
  /* P2: no push-pull */
  P0MDOUT   = 0xDC;
  P1MDOUT   = 0x4D;

  /* P0: 0,1,2,3,6,7 skipped */
  /* P1: 3,6 skipped */
  /* P2: 7 skipped */
  P0SKIP    = 0xCF;
  P1SKIP    = 0x48;

  /* Set SMBUS clock speed */
  Set115200bps_24MHZ5;
  /* Start Timer1 */
  TR1 = 1;
  /* Initialize SMBus */
  vSmbus_InitSMBusInterface();
#else
#error TO BE WRITTEN FOR OTHER PLARFORMS!
#endif

  P0MDIN  = 0xFF; // All pin configured as digital port
  P1MDIN  = 0xFF; // All pin configured as digital port
#if !(defined SILABS_PLATFORM_WMB912)
  P2MDIN  = 0xFF; // All pin configured as digital port
#endif

  /* Set Drive Strenght */
  SFRPAGE = CONFIG_PAGE;
  P0DRV   = 0x00;
  P1DRV   = 0x00;
#if !(defined SILABS_PLATFORM_WMB912)
  P2DRV   = 0x00;
#endif

  SFRPAGE = LEGACY_PAGE;

  /* Crossbar configuration */
  XBR0    = M_URT0E | M_SMB0E; //p0: UART enabled on XBAR
  XBR1    = M_SPI1E ; //p6: SPI1 enabled on XBAR
#if ((defined SILABS_PLATFORM_RFSTICK) || (defined SILABS_PLATFORM_LCDBB))
  XBR1    |= (1 << BF_PCA0ME_0); //p0: PCA CEX0 enabled on XBAR
#elif(defined SILABS_MCU_DC_EMIF_F930)
  XBR0    |= M_SPI0E ; //p6: SPI1 enabled on XBAR
#elif (defined SILABS_MCU_DC_EMIF_F930_STANDALONE)

#elif (defined SILABS_PLATFORM_WMB930)
  XBR1    |= (1 << BF_PCA0ME_0); //p0: PCA CEX0 enabled on XBAR
  XBR0    |= M_SPI0E;
#elif (defined SILABS_PLATFORM_WMB912)

#else
#error TO BE WRITTEN FOR OTHER PLARFORMS!
#endif
  XBR2    = M_XBARE; //p6: XBAR enable

  /* latch all inputs to '1' */
  P0      = ~P0MDOUT;
  P1      = ~P1MDOUT;
#if !(defined SILABS_PLATFORM_WMB912)
  P2      = ~P2MDOUT;
#endif

  /* set all output to its default state */
  LED1      = EXTINGUISH;
#if !(defined SILABS_PLATFORM_WMB912)
  LED2      = EXTINGUISH;
  LED3      = EXTINGUISH;
  LED4      = EXTINGUISH;
#endif
  RF_NSEL   = TRUE;
  RF_PWRDN  = FALSE;

  /* SPI1 & SPI0 Config & Enable */
  SPI0CFG   = 0x40;
  SPI1CFG   = 0x40;
#if !(defined SILABS_PLATFORM_WMB912)
  SPI0CN    = 0x01;
#else
  SPI0CN    = 0x00;
#endif
  SPI1CN    = 0x01;
  SPI0CKR   = 0x0B;
  SPI1CKR   = 0x0B;

  /* De-select radio SPI */
  vSpi_SetNsel(eSpi_Nsel_RF);

#if ((defined SILABS_LCD_DOG_GLCD) || (defined SILABS_MCU_DC_EMIF_F930) || (defined SILABS_PLATFORM_WMB))
  /* De-select LCD SPI */
  vSpi_SetNsel(eSpi_Nsel_LCD);

  LCD_A0    = FALSE;
#endif

  /* Startup delay */
  for (; wDelay; wDelay--)  ;

}

#ifdef SDCC
/**
 * \brief External startup function of SDCC.
 *
 * It performs operations
 * prior static and global variable initialization.
 * Watchdog timer should be disabled this way, otherwise it
 * can expire before variable initialization is carried out,
 * and may prevent program execution jumping into main().
 *
 * \param None
 * \return None
 */
void _sdcc_external_startup(void)
{
  PCA0MD &= ~0x40;      // Disable Watchdog timer
}
#endif
