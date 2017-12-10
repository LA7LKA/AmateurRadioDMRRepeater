/*! @file menu.h
 * @brief Header file of menu handler driver.
 *
 * @b COPYRIGHT
 * @n Silicon Laboratories Confidential
 * @n Copyright 2012 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 */

#ifndef MENU_H_
#define MENU_H_


/*------------------------------------------------------------------------*/
/*                          Global definitions                            */
/*------------------------------------------------------------------------*/


/*------------------------------------------------------------------------*/
/*          Global structure & enumeration definitions                    */
/*------------------------------------------------------------------------*/

typedef enum {
  MENUCHANGE_NOCHANGE,
  MENUCHANGE_NEXT,
  MENUCHANGE_BACK,
} menuChgReq_e;

typedef struct {
  U8 chgReq;
  U8 rfsReq;
  U8 btnType;
} menuFuncRet_t;

typedef struct {
  menuFuncRet_t  (*pStateFunction)(void); /**< Handler function of the menu state */
  U8 *(*pOutputFunction)(void); /**< Display function of the menu state */
} menuFunction_t;

/*!
 * @brief This structure contains information of the menu state.
 */
typedef struct _tMnu_MenuState
{
  U8 bMenuState; /**< Actual menu state */
  U8 bMenuNextState;  /**< Next menu state */
  menuFunction_t menuFunction;
  U8 menuHidden;
} tMnu_MenuState;

/*!
 * @brief This structure contains operation
 * information of the current and next menu state.
 */
typedef struct _tMnu_MenuStateInfo
{
  U8 bMenuState;      /**< Actual menu state */
  U8 bMenuNextState;  /**< Next menu state caused by input */
  menuFunction_t *pMenuFunction; /**< Pointer to handler functions */
} tMnu_MenuStateInfo;

/*------------------------------------------------------------------------*/
/*                            Public variables                            */
/*------------------------------------------------------------------------*/
extern SEGMENT_VARIABLE(rMnu_MenuStateInfo, tMnu_MenuStateInfo, SEG_XDATA);

/*------------------------------------------------------------------------*/
/*                           Function prototypes                          */
/*------------------------------------------------------------------------*/

void  vMnu_InitMenu(tMnu_MenuState *pariAppMenuState);
void  vMnu_MenuChangeState(U8 biNewMenuState);
void  vMnu_DeleteMenuFunction(void);
U8    bMnu_GetMenuState(void);
menuFuncRet_t vMnu_MenuHandler();


#endif /* MENU_H_ */

