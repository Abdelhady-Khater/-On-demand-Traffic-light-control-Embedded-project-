/*************************************************************************************************/
/*************************************************************************************************/
/***********************             Author: abdelhady khater             ************************/
/***********************             Layer:  ECUAL                        ************************/
/***********************             HWC :   TIMER                        ************************/
/*************************************************************************************************/
/*************************************************************************************************/


#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include <math.h>
#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_types.h"
#include "../../1-MCAL/DIO Driver/DIO_interface.h"
#include "../../1-MCAL/Timer Driver/Timer_register.h"
#include "../../4-LIB/STD_types.h"

typedef enum EN_TIMERSError_t
{
    TIMERS_OK, TIMERS_ERROR
}EN_TIMERSError_t;

/***                   initialize Timer with 0               ***/

void TIMER_init();                 

/***                 delay useing 256 prescalar              ***/

EN_TIMERSError_t TIMER_delay(u16 millisec);         


#endif 