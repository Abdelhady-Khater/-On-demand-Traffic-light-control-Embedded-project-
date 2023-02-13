/*************************************************************************************************/
/*************************************************************************************************/
/***********************             Author: abdelhady khater             ************************/
/***********************             Layer:  ECUAL                        ************************/
/***********************             SWC :   BUTTON                       ************************/
/*************************************************************************************************/
/*************************************************************************************************/

#include "../../4-LIB/STD_types.h"
#include "BUTTON_interface.h"


EN_BUTTONError_t BUTTON_init(u8 copy_buttonPort,u8 copy_buttonPin)
{
EN_BUTTONError_t Local_BUTTON_ErrorState=BUTTON_OK;

DIO_u8SetPinDirection(copy_buttonPort,copy_buttonPin,DIO_u8PIN_INPUT);
if(TRUE)
	{
	Local_BUTTON_ErrorState = BUTTON_OK;
	}

return Local_BUTTON_ErrorState;
}


EN_BUTTONError_t BUTTON_read(u8 copy_buttonPort,u8 copy_buttonPin,u8 *value)
{
EN_BUTTONError_t Local_BUTTON_ErrorState=BUTTON_OK;

	DIO_u8GetPinValue(copy_buttonPort,copy_buttonPin,value);
if(TRUE)
	{
	Local_BUTTON_ErrorState = BUTTON_OK;
	}

return Local_BUTTON_ErrorState;
}
