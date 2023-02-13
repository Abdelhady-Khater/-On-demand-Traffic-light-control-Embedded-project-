/*************************************************************************************************/
/*************************************************************************************************/
/***********************             Author: abdelhady khater             ************************/
/***********************             Layer:  Application                  ************************/
/***********************             Ver:    1.00                         ************************/
/*************************************************************************************************/
/*************************************************************************************************/

#include "application.h"
#define PRESCALER 1024

u8 carLED=2;        		/** red:0    yellow:1    green:2 **/
u8 prevcarLED=1;
u8 No_PED_Mode = 1; 	   /**   pedestrian:0    normal:1   **/

void APP_init(void){
	
/***                     Car LED initialization                      ***/

	LED_init(LED_CAR_PORT,R_LED_CAR_PIN);
	LED_init(LED_CAR_PORT,Y_LED_CAR_PIN);
	LED_init(LED_CAR_PORT,G_LED_CAR_PIN);

/***                  Pedestrian LED initialization                  ***/	

	LED_init(LED_PED_PORT,R_LED_PED_PIN);
	LED_init(LED_PED_PORT,Y_LED_PED_PIN);
	LED_init(LED_PED_PORT,G_LED_PED_PIN);

/***                     Button initialization                       ***/	

	BUTTON_init(BUTTON_PORT,BUTTON_PIN);

/***                      Timer initialization                       ***/	

	TIMER_init();

/***Enable Global interrupts & setup rising edge detection for button***/	

	sei();
	RISING_EDGE_SETUP();
	SETUP_INT0();
}


void APP_start(void)
{
	u8 Counter;
	
/***                              car mode                           ***/

if(No_PED_Mode || carLED==1 || carLED==2){
		if(!No_PED_Mode)
		{ 									
			carLED=1;
		}

/***   Configuring Pedestrian LEDs in car mode so No_PED_Mode==1     ***/     

		LED_off(LED_PED_PORT,Y_LED_PED_PIN);
		LED_off(LED_PED_PORT,G_LED_PED_PIN);
		LED_on(LED_PED_PORT,R_LED_PED_PIN);
		switch(carLED){
/***                      car mode - red led case                    ***/
			case 0:
				LED_off(LED_CAR_PORT,G_LED_CAR_PIN);
				LED_off(LED_CAR_PORT,Y_LED_CAR_PIN);
				LED_on (LED_CAR_PORT,R_LED_CAR_PIN);

				for(Counter=0;Counter<50;Counter++)
				{
					delayTimeInSec(.1,PRESCALER);
					if(!No_PED_Mode)
					break;
				}
				carLED=1;
				prevcarLED=0;
				break;

			case 1:
/***                  Pedestrian mode - yellow led case               ***/
				
				if(!No_PED_Mode)
				{
					if(prevcarLED!=0)
					{
						LED_on(LED_PED_PORT,R_LED_PED_PIN);
						for(Counter=0;Counter<5;Counter++)
						{
							LED_on(LED_CAR_PORT,Y_LED_CAR_PIN);
							LED_on(LED_PED_PORT,Y_LED_PED_PIN);
							delayTimeInSec(.5, PRESCALER);
							LED_off(LED_CAR_PORT,Y_LED_CAR_PIN);
							LED_off(LED_PED_PORT,Y_LED_PED_PIN);
							delayTimeInSec(.5, PRESCALER);
						}
					}
					
					prevcarLED=1;
					carLED=0;
					LED_on(LED_CAR_PORT,R_LED_CAR_PIN);
				}
/***                      car mode - Yellow led case                  ***/				
				else
					{
					for(Counter=0;Counter<5;Counter++){
						LED_on(LED_CAR_PORT,Y_LED_CAR_PIN);
						delayTimeInSec(.5, PRESCALER);
						LED_off(LED_CAR_PORT,Y_LED_CAR_PIN);
						delayTimeInSec(.5, PRESCALER);
						if(!No_PED_Mode)
						{
							prevcarLED=1;
							break;
						}
					}
				}
				LED_off(LED_CAR_PORT,Y_LED_CAR_PIN);
				LED_off(LED_PED_PORT,Y_LED_PED_PIN);				
				if(prevcarLED==2){
					carLED=0;
					prevcarLED=1;
				}
				else if(prevcarLED==0){
					carLED=2;
					prevcarLED=1;
				LED_on(LED_PED_PORT,DIO_u8PIN4);

				}
				break;
/***                  car mode - green led case               ***/
			case 2:
				LED_on(LED_CAR_PORT,G_LED_CAR_PIN);
				LED_off(LED_CAR_PORT,Y_LED_CAR_PIN);
				LED_off(LED_CAR_PORT,R_LED_CAR_PIN);

				for(Counter=0;Counter<50;Counter++)
				{
					delayTimeInSec(.1, PRESCALER);
					if(!No_PED_Mode)
					break;
				}
				carLED=1;
				prevcarLED=2;   
				break;
			default:
				carLED=2;
				prevcarLED=0;
				break;
		}
		
	}else 
	{
/***   Configuring Pedestrian LEDs in PED mode so No_PED_Mode==0     ***/  

		LED_on (LED_PED_PORT,G_LED_PED_PIN);
		LED_off(LED_PED_PORT,Y_LED_PED_PIN);
		LED_off(LED_PED_PORT,R_LED_PED_PIN);

/***      Configuring car LEDs in PED mode so No_PED_Mode==0        ***/ 
for(Counter=0;Counter<10;Counter++)
{
		LED_off(LED_CAR_PORT,G_LED_CAR_PIN);
		LED_off(LED_CAR_PORT,Y_LED_CAR_PIN);
		LED_on (LED_CAR_PORT,R_LED_CAR_PIN);
		delayTimeInSec(.5, PRESCALER);
}
Counter=0;
/***                      PED mode - yellow led case                  ***/				

		for(Counter=0;Counter<5;Counter++)
		{
			LED_on(LED_CAR_PORT,Y_LED_CAR_PIN);
			LED_on(LED_PED_PORT,Y_LED_PED_PIN);
			delayTimeInSec(.5, PRESCALER);
			LED_off(LED_CAR_PORT,Y_LED_CAR_PIN);
			LED_off(LED_PED_PORT,Y_LED_PED_PIN);
			delayTimeInSec(.5, PRESCALER);
		}
/***                   PED mode - Y-led off & R-led on               ***/
		LED_off(LED_CAR_PORT,Y_LED_CAR_PIN);
		LED_off(LED_PED_PORT,Y_LED_PED_PIN);
		LED_on(LED_PED_PORT,R_LED_PED_PIN);
		No_PED_Mode=1;
		carLED=2;
		prevcarLED=1;
	}
	
}

ISR(EXT_INT_0){
	No_PED_Mode=0;
}