/*************************************************************************************************/
/*************************************************************************************************/
/***********************             Author: abdelhady khater             ************************/
/***********************             Layer:  ECUAL                        ************************/
/***********************             SWC :   BUTTON                       ************************/
/*************************************************************************************************/
/*************************************************************************************************/

#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H
#include "../../1-MCAL/DIO Driver/DIO_interface.h"

#define BUTTON_PORT DIO_u8PORTD 
#define BUTTON_PIN  DIO_u8PIN0
typedef enum EN_BUTTONError_t
{
    BUTTON_OK, BUTTON_ERROR
}EN_BUTTONError_t;


EN_BUTTONError_t BUTTON_init(u8 copy_buttonPort,u8 copy_buttonPin);
EN_BUTTONError_t BUTTON_read(u8 copy_buttonPort,u8 copy_buttonPin,u8 *value);


#endif 