/*************************************************************************************************/
/*************************************************************************************************/
/***********************             Author: abdelhady khater             ************************/
/***********************             Layer:  ECUAL                        ************************/
/***********************             HWC :   TIMER                        ************************/
/*************************************************************************************************/
/*************************************************************************************************/

#include "Timer_interface.h"

void TIMER_init()
{
	TCCR0 = 0x00;
}

EN_TIMERSError_t delayTimeInSec(f32 delay_time, u32 prescaler)
{
EN_TIMERSError_t Local_Timer_ErrorState = TIMERS_OK;

	TCCR0 = 0x00;
	u32 overflow_counter = 0; 
	u32 overflows = 0, Timer_ini_value = 0;
	f32 tick_time = ((f32)prescaler / 1000000.0);
	f32 Time_MAX_delay;
	Time_MAX_delay= tick_time * 256;
	
	if(delay_time<Time_MAX_delay)
	{
		Timer_ini_value = (Time_MAX_delay-delay_time)/tick_time;
		overflows = 1;
		
	}
	else if(delay_time == (u32)Time_MAX_delay)
	{
		Timer_ini_value=0;
		overflows=1;
	}

	else if  (delay_time>Time_MAX_delay)
	{
		overflows = ceil((f64)delay_time/Time_MAX_delay);
		Timer_ini_value = ceil(256 - ((((f32)delay_time / tick_time)) / overflows));
		
		
	}
	else
	Local_Timer_ErrorState = TIMERS_ERROR;

	TCNT0 = Timer_ini_value;
	
	switch(prescaler)
	{
		case 8:
		TCCR0 |= (1<<1);
		break;
		case 64:
		TCCR0 |= (1<<1) | (1<<0);
		break;
		case 256:
		TCCR0 |= (1<<2);
		break;
		case  1024:
		TCCR0 |= (1<<2) | (1<<0);
		break;
		default:
		TCCR0 |= (1<<0);
		break;
	}
	while(overflow_counter < overflows)
	{
		
		while((TIFR & (1<<0)) == 0);
		TIFR |= (1<<0);
		TCNT0 = Timer_ini_value;
		overflow_counter++;
	}

	return Local_Timer_ErrorState;
}


