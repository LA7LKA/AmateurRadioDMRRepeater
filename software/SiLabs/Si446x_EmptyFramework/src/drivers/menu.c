/*! @file menu.c
 * @brief This file contains functions of the menu handler driver.
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

/**< This instance of the structure holds information of menu states */
SEGMENT_VARIABLE(rMnu_MenuStateInfo, tMnu_MenuStateInfo, SEG_XDATA);

/*!
 * @brief Pointer to an instance of the tMnu_MenuState structure, which is
 * stored on the code space.
 * @note It have to be implemented in the application menu files.
 */
SEGMENT_VARIABLE_SEGMENT_POINTER(parMnu_AppMenuState, tMnu_MenuState, \
                                 SEG_CODE, SEG_XDATA);

/*------------------------------------------------------------------------*/
/*                          Function implementations                      */
/*------------------------------------------------------------------------*/

/*!
 * This function is used to handle switch state change.
 *
 * @param[in] pariAppMenuState Pointer to the instance
 * of the tMnu_MenuState structure.
 *
 * @return  True if state of switches has changed.
 *
 * @note It has to be called from the initialization section.
 */
void vMnu_InitMenu(tMnu_MenuState *pariAppMenuState)
{
  parMnu_AppMenuState                 = pariAppMenuState;

  rMnu_MenuStateInfo.bMenuState       =   parMnu_AppMenuState[0].bMenuState;
  rMnu_MenuStateInfo.bMenuNextState   =   parMnu_AppMenuState[0].bMenuState;
  rMnu_MenuStateInfo.pMenuFunction    = &(parMnu_AppMenuState[0].menuFunction);
}

/*!
 * This function is used to manage menu states and
 * the transitions from one state to an other.
 *
 * @return None.
 */
menuFuncRet_t vMnu_MenuHandler()
{
  SEGMENT_VARIABLE(lFuncRet, menuFuncRet_t, SEG_DATA) = \
      { MENUCHANGE_NOCHANGE, FALSE };

  if (rMnu_MenuStateInfo.pMenuFunction->pStateFunction) {
    lFuncRet = rMnu_MenuStateInfo.pMenuFunction->pStateFunction();
  }

  return lFuncRet;
}

/*!
 * This function is used to change the menu state.
 *
 * @param[in] biNewMenuState New menu state.
 *
 * @return None.
 */
void vMnu_MenuChangeState(U8 reqDir)
{
  switch (reqDir) {
    case MENUCHANGE_NEXT:
      if (!sMenuIsLastElement(rMnu_MenuStateInfo.bMenuState)) {
        rMnu_MenuStateInfo.bMenuState = \
            sMenuNext(rMnu_MenuStateInfo.bMenuState);
        rMnu_MenuStateInfo.pMenuFunction = \
            sMenuGetStateFunction(rMnu_MenuStateInfo.bMenuState);
      }
      break;

    case MENUCHANGE_BACK:
      if (!sMenuIsFirstElement(rMnu_MenuStateInfo.bMenuState)) {
        rMnu_MenuStateInfo.bMenuState = \
            sMenuBack(rMnu_MenuStateInfo.bMenuState);
        rMnu_MenuStateInfo.pMenuFunction = \
            sMenuGetStateFunction(rMnu_MenuStateInfo.bMenuState);
      }
      break;

    default:
      break;
  }
}

/*!
 * This function is used to clear handler function of a menu state.
 * It can be used if handler required only for first time and all the
 * transitions can be managed by the menu handler.
 *
 * @return None.
 */
void vMnu_DeleteMenuFunction(void)
{
  rMnu_MenuStateInfo.pMenuFunction->pStateFunction = NULL;
}
