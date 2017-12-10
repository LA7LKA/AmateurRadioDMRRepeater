/*! @file control_IO.h
 * @brief This file contains the common constants and interfaces used by the 
 *        CDD drivers.
 *
 * @b COPYRIGHT
 * @n Silicon Laboratories Confidential
 * @n Copyright 2012 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 */

#ifndef CDD_COMMON_H
#define CDD_COMMON_H

/*****************************************************************************
 *  Global Definitions & Macros
 *****************************************************************************/

/*! Critical Section Macros */
#define ENTER_CRITICAL_SECTION    (EA = 0)
#define EXIT_CRITICAL_SECTION     (EA = 1)

/**
 * @description Useful macro for avoiding compiler warnings related to unused
 * function arguments or unused variables.
 */
 #define UNUSED_VAR(x) do { if (x) {} } while(0) 

/*****************************************************************************
 *  Global Enums & Typedefs
 *****************************************************************************/

 
/*****************************************************************************
 *  Global Function Declarations
 *****************************************************************************/


/*****************************************************************************
 *  Global Variables Declarations
 *****************************************************************************/


#endif /* CDD_COMMON_H */
