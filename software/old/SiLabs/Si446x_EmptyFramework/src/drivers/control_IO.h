/*! @file control_IO.h
 * @brief This file is the interface file for IO control routines.
 *
 * @b COPYRIGHT
 * @n Silicon Laboratories Confidential
 * @n Copyright 2012 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 */

#ifndef CONTROL_IO_H
#define CONTROL_IO_H

/*------------------------------------------------------------------------*/
/*                           Function prototypes                          */
/*------------------------------------------------------------------------*/

#if (defined SILABS_IO_WITH_EXTENDER)
/* Address length of extended IOs in IO extender */
#define bCio_IoExtAddrLength_c      0x02

/* Data length of extended IOs in IO extender */
#define bCio_IoExtCmdLength_c       0x01
#define bCio_IoExtRespLength_c      0x01

/* SMBus address of the IO extender */
#define IOEXT_SMBUS_ADDR            0x50
/* Address of extended IOs in IO extender */

typedef enum
{
   IOEXT_ADDR_REQUEST_GPIO_STATE       = (0x8000 | 0x00),
   IOEXT_ADDR_CONTROL_SET_LED_STATE    = (0x8000 | 0x01),
   IOEXT_ADDR_CONTROL_CLEAR_LED_STATE  = (0x8000 | 0x02),
   IOEXT_ADDR_CONTROL_TOGGLE_LED_STATE = (0x8000 | 0x03),
} eUDPBaseboardAddressSpace;

/*!
 * @brief This enumeration contains definitions of push-buttons for IO extender.
 */
typedef enum _eHmi_PbStates
{
  eCio_PbNo_c = 0x00,
  eCio_Pb1_c  = 0x01,
  eCio_Pb2_c  = 0x02,
  eCio_Pb3_c  = 0x04,
  eCio_Pb4_c  = 0x08,
} eCio_PbStates;

/*!
 * @brief This enumeration contains definitions of LEDs for IO extender.
 */
typedef enum _eHmi_LedStates
{
  eCio_LedNo_c = 0x00,
  eCio_Led1_c  = 0x01,
  eCio_Led2_c  = 0x02,
  eCio_Led3_c  = 0x04,
  eCio_Led4_c  = 0x08,
} eCio_LedStates;
#endif /* #if (defined SILABS_IO_WITH_EXTENDER) */

void vCio_InitIO(void);
void vCio_SetLed(U8 biLedNum);
void vCio_ClearLed(U8 biLedNum);
void vCio_ToggleLed(U8 biLedNum);
BIT gCio_GetPB(U8 biPbNum);

#endif
