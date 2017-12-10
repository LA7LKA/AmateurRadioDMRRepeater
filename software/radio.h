/*! @file radio.h
 * @brief This file contains the public functions controlling the radio chip.
 *
 * @b COPYRIGHT
 * @n Silicon Laboratories Confidential
 * @n Copyright 2012 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 */


#include <stdint.h>
#include "radio/si446x_api_lib.h"

#define U8 uint8_t
#define U16 uint16_t
/*****************************************************************************
 *  Global Macros & Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Global Typedefs & Enums
 *****************************************************************************/
typedef struct
{
    U8   *Radio_ConfigurationArray;

    U8   Radio_ChannelNumber;
    U8   Radio_PacketLength;
    U8   Radio_State_After_Power_Up;

    U16  Radio_Delay_Cnt_After_Reset;
} tRadioConfiguration;

/*****************************************************************************
 *  Global Variable Declarations
 *****************************************************************************/
//extern const SEGMENT_VARIABLE_SEGMENT_POINTER(pRadioConfiguration, tRadioConfiguration, SEG_CODE, SEG_CODE);

/*! Si446x configuration array */
//extern const SEGMENT_VARIABLE(Radio_Configuration_Data_Array[], U8, SEG_CODE);

/*****************************************************************************
 *  Global Function Declarations
 *****************************************************************************/
void  vRadio_Init(void);
void  vRadio_StartTx(U8, U8 *);
void  vRadio_StartRX(U8);
U8    bRadio_Check_Ezconfig(U16);


