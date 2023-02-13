/*************************************************************************************************/
/*************************************************************************************************/
/***********************             Author: abdelhady khater             ************************/
/***********************             Layer:  ECUAL                        ************************/
/***********************             HWC :   LED                          ************************/
/*************************************************************************************************/
/*************************************************************************************************/


#include "LED_interface.h"


EN_LEDError_t LED_init(u8 copy_ledPort,u8 copy_ledPin)
{
EN_DIOError_t Local_LED_ErrorState=LED_OK;

DIO_u8SetPinDirection(copy_ledPort,copy_ledPin,DIO_u8PIN_OUTPUT);

if(TRUE)
	{
	Local_LED_ErrorState = LED_OK;
	}

return Local_LED_ErrorState;
}

EN_LEDError_t LED_on(u8 copy_ledPort,u8 copy_ledPin)
{
EN_DIOError_t Local_LED_ErrorState=LED_OK;

	DIO_u8SetPinValue(copy_ledPort,copy_ledPin,DIO_u8PIN_HIGH);

if(TRUE)
	{
	Local_LED_ErrorState = LED_OK;
	}

return Local_LED_ErrorState;
}

EN_LEDError_t LED_off(u8 copy_ledPort,u8 copy_ledPin)
{
EN_DIOError_t Local_LED_ErrorState=LED_OK;

	DIO_u8SetPinValue(copy_ledPort,copy_ledPin,DIO_u8PIN_LOW);

if(TRUE)
	{
	Local_LED_ErrorState = LED_OK;
	}

return Local_LED_ErrorState;
}

EN_LEDError_t LED_toggle(u8 copy_ledPort,u8 copy_ledPin)
{  
EN_DIOError_t Local_LED_ErrorState=LED_OK;
	DIO_u8TogglePinValue(copy_ledPort,copy_ledPin);

if(TRUE)
	{
	Local_LED_ErrorState = LED_OK;
	}

return Local_LED_ErrorState;
}