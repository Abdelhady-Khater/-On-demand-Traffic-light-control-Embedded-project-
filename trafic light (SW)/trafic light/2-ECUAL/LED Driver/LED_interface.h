/*************************************************************************************************/
/*************************************************************************************************/
/***********************             Author: abdelhady khater             ************************/
/***********************             Layer:  ECUAL                        ************************/
/***********************             SWC :   LED                          ************************/
/*************************************************************************************************/
/*************************************************************************************************/


#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H
#include "../../4-LIB/STD_types.h"
#include "../../1-MCAL/DIO Driver/DIO_interface.h"


/***                   Car port and pins               ***/

#define LED_CAR_PORT     DIO_u8PORTA
#define R_LED_CAR_PIN    DIO_u8PIN0
#define Y_LED_CAR_PIN    DIO_u8PIN1
#define G_LED_CAR_PIN    DIO_u8PIN2


/***              Pedestrian port and pins             ***/

#define LED_PED_PORT     DIO_u8PORTC
#define R_LED_PED_PIN    DIO_u8PIN0
#define Y_LED_PED_PIN    DIO_u8PIN1
#define G_LED_PED_PIN    DIO_u8PIN2

typedef enum EN_LEDError_t
{
    LED_OK, LED_ERROR
}EN_LEDError_t;

EN_LEDError_t LED_init(u8 copy_ledPort,u8 copy_ledPin);
EN_LEDError_t LED_on(u8 copy_ledPort,u8 copy_ledPin);
EN_LEDError_t LED_off(u8 copy_ledPort,u8 copy_ledPin);
EN_LEDError_t LED_toggle(u8 copy_ledPort,u8 copy_ledPin);

#endif 