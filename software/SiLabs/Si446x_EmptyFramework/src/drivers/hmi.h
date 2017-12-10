/*! @file hmi.h
 * @brief This file is the interface file for basic HMI functions.
 *
 * @b COPYRIGHT
 * @n Silicon Laboratories Confidential
 * @n Copyright 2012 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 */

#ifndef HMI_H_
#define HMI_H_


/*------------------------------------------------------------------------*/
/*                          Global definitions                            */
/*------------------------------------------------------------------------*/

#ifdef SILABS_PLATFORM_COMPONENT_LED
/*!
 * @brief This definition holds the maximum number of Leds.
 */
#define bHmi_NumOfLeds_c SILABS_PLATFORM_COMPONENT_LED

/*!
 * @brief This definition holds the maximum of the main counter of the Leds.
 */
#define wHmi_LedMainCntMax_c wTim_HalfHzCntMax_c
#endif

#ifdef SILABS_PLATFORM_COMPONENT_PB
/*!
 * @brief This definition holds the maximum number of switches.
 */
#define bHmi_NumOfPbs_c SILABS_PLATFORM_COMPONENT_PB

/*!
 * @brief This definition holds steady-state wait time of push-buttons.
 */
#define bHmi_PbDebounceWaitTime_c 10

/*
 * #define bHmi_PbMaxPushTrackFifo_c 10
 */
#endif


#ifdef SILABS_PLATFORM_COMPONENT_SWITCH
/*!
 * @brief This definition holds the maximum number of switches.
 */
#define bHmi_NumOfSwitches_c SILABS_PLATFORM_COMPONENT_SWITCH
#endif


/*------------------------------------------------------------------------*/
/*          Global structure & enumeration definitions                    */
/*------------------------------------------------------------------------*/

#ifdef SILABS_PLATFORM_COMPONENT_LED
/*!
 * @brief This enumeration contains constant definitions for Leds.
 */
typedef enum _eHmi_Leds
{
  eHmi_NoLed_c          = 0x00, /**< No Led */
  eHmi_Led1_c           = 0x01, /**< Led1 */
  eHmi_Led2_c           = 0x02, /**< Led2 */
  eHmi_Led3_c           = 0x03, /**< Led3 */
  eHmi_Led4_c           = 0x04, /**< Led4 */
} eHmi_Leds;

/*!
 * @brief This enumeration contains Led state definitions.
 */
typedef enum {
  eHmi_LedOff_c           = 0x00, /**< Led is in off state */
  eHmi_LedStdBy_c         = 0x01, /**< Led waits for state change */
  eHmi_LedOn_c            = 0x10, /**< Led is in on state */
  eHmi_LedToggle_c              ,
  eHmi_LedBlink2Hz_c      = 0x20, /**< Led blinks with 2Hz */
  eHmi_LedBlink1Hz_c      = 0x30, /**< Led blinks with 1Hz */
  eHmi_LedBlinkHalfHz_c   = 0x40, /**< Led blinks with 0.5Hz */
  eHmi_LedBlinkOnce_c     = 0x50, /**< Blinks led once */
  eHmi_LedBlinkWait_c     = 0x55, /**< Blinks led once */
} eHmi_LedStates;

/*!
 * @brief This structure contains required data of a specific Led.
 */
typedef struct _tHmi_LedData
{
  eHmi_LedStates qLedState; /**< Led state (on, off, blink) */
  U16 wLedBlinkCnt;         /**< Led blink counter */
  U8 gLedIsOn;             /**< Actual state of Led (lid or not) */
} tHmi_LedData;
#endif

#ifdef SILABS_PLATFORM_COMPONENT_PB
/*!
 * @brief This enumeration contains states of push-button handler.
 */
typedef enum _eHmi_PbHandlerStates
{
  eHmi_PbNoRun_c                  = 0x00, /**< Push-button handler not runs */
  eHmi_PbStandBy_c                = 0x10, /**< No button is pushed */
  eHmi_PbStandByWaitAllReleased_c = 0x11, /**< Wait for release all buttons (if more were pushed) */
  eHmi_PbStateChanged_c           = 0x20, /**< Push-button state changed */
  eHmi_PbDebounceWait_c           = 0x25, /**< Push-button debounce state (push)*/
  eHmi_PbPushed_c                 = 0x30, /**< Push-button pushed */
  eHmi_PbReleaseWait_c            = 0x40, /**< Push-button debounce state (release) */
} eHmi_PbHandlerStates;

/*!
 * @brief This enumeration contains definitions of push-button push states.
 */
typedef enum {
  eHmi_PbNo_c = 0x00,
  eHmi_Pb1_c  = 0x01,
  eHmi_Pb2_c  = 0x02,
  eHmi_Pb3_c  = 0x04,
  eHmi_Pb4_c  = 0x08,
} eHmi_PbStates;

/*!
 * @brief This structure contains required data of the push-button handler.
 */
typedef struct _tHmi_PbData
{
    eHmi_PbHandlerStates qPbHandlerState;  /**< Push-button handler state */
    U8  bPbPushTrack;     /**< Push-button state */
    U8  bPbPushTrackLast; /**< Push-button state of last pushed-released button*/
    U8  bPbPushTrackAct;  /**< Actual state of push-buttons */
    U16 wPbPushTime;      /**< Push-button state time holder  */
    U16 wPbPushTimeLast;  /**< Push-button state time holder of last pushed-released button */
    U8  bPbWaitTime;      /**< Steady-state wait time holder  */
} tHmi_PbData;
#endif

#ifdef SILABS_PLATFORM_COMPONENT_SWITCH
/*!
 * @brief This enumeration contains constant definitions for switches.
 */
typedef enum _eHmi_Switches
{
  eHmi_NoSw_c          = 0x00, /**< No switch is set */
  eHmi_Sw1_A_c         = 0x01, /**< switch 1-A is set */
  eHmi_Sw1_B_c         = 0x02, /**< switch 1-B is set */
  eHmi_Sw1_C_c         = 0x04, /**< switch 1-C is set */
  eHmi_Sw1_D_c         = 0x08, /**< switch 1-D is set */
} eHmi_Switches;
#endif

#ifdef SILABS_PLATFORM_COMPONENT_BUZZER
/*!
 * @brief This enumeration contains state definitions of the buzzer.
 */
typedef enum _eHmi_BuzzStates
{
  eHmi_BuzzOff_c      = 0x00, /**< Buzz is in off state */
  eHmi_BuzzStdBy_c    = 0x01, /**< Buzz waits for state change */
  eHmi_BuzzOn_c       = 0x10, /**< Buzz is in on state */
  eHmi_Buzz2Hz_c      = 0x20, /**< Buzz 2Hz */
  eHmi_Buzz1Hz_c      = 0x30, /**< Buzz 1Hz */
  eHmi_Buzz0Hz5_c     = 0x40, /**< Buzz 0.5Hz */
  eHmi_Buzz0Hz25_c    = 0x41, /**< Buzz 0.25Hz */
  eHmi_BuzzOnce_c     = 0x50, /**< Buzz once */
  eHmi_BuzzOnceAndCont_c = 0x51, /**< Buzz once and continue buzzing*/
  eHmi_BuzzWait_c     = 0x55, /**< Waits for buzz once */
} eHmi_BuzzStates;


/*!
 * @brief This structure contains required data of the Buzzer.
 */
typedef struct _tHmi_BuzzData
{
  eHmi_BuzzStates qBuzzState; /**< Buzzer state (on, off, blink) */
  eHmi_BuzzStates qBuzzNextState; /**< Buzzer next state (on, off, blink) */
  U16 wBuzzCnt;               /**< Buzzer counter */
  U8 gBuzzIsOn;               /**< Actual state of the buzzer (buzz or not) */
} tHmi_BuzzData;
#endif

/*------------------------------------------------------------------------*/
/*                           Function prototypes                          */
/*------------------------------------------------------------------------*/

#ifdef SILABS_PLATFORM_COMPONENT_LED
void vHmi_InitLedHandler(void);
void vHmi_ChangeLedState(eHmi_Leds qiLed, eHmi_LedStates qiLedState);
void vHmi_LedHandler(void);
#endif

#ifdef SILABS_PLATFORM_COMPONENT_PB
void vHmi_InitPbHandler(void);
BIT gHmi_PbIsPushed(U8 *boPbPushTrack, U16 *woPbPushTime);
U8  bHmi_PbGetLastButton(U16 *woPbPushTime);
void vHmi_PbHandler(void);
#endif

#ifdef SILABS_PLATFORM_COMPONENT_SWITCH
BIT gHmi_SwStateHandler(void);
U8 bHmi_GetSwState(void);
#endif

#ifdef SILABS_PLATFORM_COMPONENT_BUZZER
void vHmi_InitBuzzer(void);
void vHmi_ChangeBuzzState(eHmi_BuzzStates qiBuzzState);
void vHmi_BuzzHandler(void);
#endif

#ifdef HMI_DRIVER_EXTENDED_SUPPORT
  #ifdef SILABS_PLATFORM_COMPONENT_LED
    void vHmi_ChangeAllLedState(eHmi_LedStates qiLedState);
    void vHmi_ClearAllLeds(void);
  #endif

  #ifdef SILABS_PLATFORM_COMPONENT_PB
    BIT gHmi_IsPbUnHandled(void);
  #endif

  #if ((defined SILABS_PLATFORM_COMPONENT_LED) && (defined SILABS_PLATFORM_COMPONENT_PB))
    void vHmi_ShowPbOnLeds(void);
  #endif

#endif

#endif /* HMI_H_ */
