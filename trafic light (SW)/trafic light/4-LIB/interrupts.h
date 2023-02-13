/*************************************************************************************************/
/*************************************************************************************************/
/***********************             Author: abdelhady khater             ************************/
/***********************             Layer:  LIB                          ************************/
/***********************             INTERRUPTS                           ************************/
/*************************************************************************************************/
/*************************************************************************************************/



#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#include "../1-MCAL/Interrupt Dirver/Interrupt Register.h"


/***                     Interrupt vectors                      ***/

#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2

/***                     Interrupt initialization                      ***/

#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")
/***                    Rising edge initialization                      ***/

#define RISING_EDGE_SETUP() MCUCR|= (1<<1) | (1<<0)

#define SETUP_INT0() GICR|=(1<<6)

/***                     ISR macro initialization                      ***/

#define ISR(INT_VECT) \
	void INT_VECT(void) __attribute__ ((signal,used)); \
	void INT_VECT(void)

#endif 