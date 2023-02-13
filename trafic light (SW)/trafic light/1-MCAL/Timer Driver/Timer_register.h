/*************************************************************************************************/
/*************************************************************************************************/
/***********************             Author: abdelhady khater             ************************/
/***********************             Layer:  MCAL                         ************************/
/***********************             SWC :   TIMER                        ************************/
/*************************************************************************************************/
/*************************************************************************************************/

#ifndef TIMER_REGISTER_H
#define TIMER_REGISTER_H



#define TCCR0       *((volatile u8*)0x53)
#define TCNT0       *((volatile u8*)0x52)
#define TIFR        *((volatile u8*)0x58)
#define TIMSK       *((volatile u8*)0x59)



#endif