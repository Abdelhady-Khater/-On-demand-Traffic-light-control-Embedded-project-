#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_types.h"
#include "DIO_register.h"
#include "DIO_interface.h"


EN_DIOError_t DIO_u8SetPinDirection(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Direction)
{

EN_DIOError_t Local_DIO_ErrorState=DIO_OK;

    if( copy_u8Pin<=7 )
    {
        if(copy_u8Direction==DIO_u8PIN_INPUT)
        {
            switch (copy_u8Port)
            {
            case DIO_u8PORTA :   CLR_BIT(DDRA , copy_u8Pin);     break;
            case DIO_u8PORTB :   CLR_BIT(DDRB , copy_u8Pin);     break;
            case DIO_u8PORTC :   CLR_BIT(DDRC , copy_u8Pin);     break;
            case DIO_u8PORTD :   CLR_BIT(DDRD , copy_u8Pin);     break;
            default          :   Local_DIO_ErrorState=DIO_ERROR; break;
            }
        }
        else if (copy_u8Direction==DIO_u8PIN_OUTPUT)
        {
            switch (copy_u8Port)
            {
            case DIO_u8PORTA :   SET_BIT(DDRA , copy_u8Pin);     break;
            case DIO_u8PORTB :   SET_BIT(DDRB , copy_u8Pin);     break;
            case DIO_u8PORTC :   SET_BIT(DDRC , copy_u8Pin);     break;
            case DIO_u8PORTD :   SET_BIT(DDRD , copy_u8Pin);     break;
            default          :   Local_DIO_ErrorState=DIO_ERROR; break;
            }     
        }
        else
        Local_DIO_ErrorState=1;
    }
    else
    Local_DIO_ErrorState=DIO_ERROR;

return Local_DIO_ErrorState;
}


EN_DIOError_t DIO_u8SetPortDirection(u8 copy_u8Port,u8 copy_u8Direction)
{   
EN_DIOError_t Local_DIO_ErrorState=DIO_OK;

    switch (copy_u8Port)
    {
    case DIO_u8PORTA :   DDRA =copy_u8Direction;         break; 
    case DIO_u8PORTB :   DDRB =copy_u8Direction;         break;
    case DIO_u8PORTC :   DDRC =copy_u8Direction;         break;
    case DIO_u8PORTD :   DDRD =copy_u8Direction;         break;
    default          :   Local_DIO_ErrorState=DIO_ERROR; break;
    }
return Local_DIO_ErrorState;
}


EN_DIOError_t DIO_u8SetPinValue(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Value)
{
EN_DIOError_t Local_DIO_ErrorState=DIO_OK;
    if( copy_u8Pin<=7 )
    {
        if(copy_u8Value==DIO_u8PIN_LOW)
        {
            switch (copy_u8Port)
            {
            case DIO_u8PORTA :   CLR_BIT(PORTA , copy_u8Pin);    break;
            case DIO_u8PORTB :   CLR_BIT(PORTB , copy_u8Pin);    break;
            case DIO_u8PORTC :   CLR_BIT(PORTC , copy_u8Pin);    break;
            case DIO_u8PORTD :   CLR_BIT(PORTD , copy_u8Pin);    break;
            default          :   Local_DIO_ErrorState=DIO_ERROR; break;
            }
        }
        else if (copy_u8Value==DIO_u8PIN_HIGH)
        {  
            switch (copy_u8Port)
            {
            case DIO_u8PORTA :   SET_BIT(PORTA , copy_u8Pin);    break;
            case DIO_u8PORTB :   SET_BIT(PORTB , copy_u8Pin);    break;
            case DIO_u8PORTC :   SET_BIT(PORTC , copy_u8Pin);    break;
            case DIO_u8PORTD :   SET_BIT(PORTD , copy_u8Pin);    break;
            default          :   Local_DIO_ErrorState=DIO_ERROR; break;
            }     
        }
        else
        Local_DIO_ErrorState=DIO_ERROR;
    }
    else
    Local_DIO_ErrorState=DIO_ERROR;

return Local_DIO_ErrorState;
}


EN_DIOError_t DIO_u8SetPortValue(u8 copy_u8Port,u8 copy_u8Value)
{   
EN_DIOError_t Local_DIO_ErrorState=DIO_OK;

    switch (copy_u8Port)
    {
    case DIO_u8PORTA :   PORTA =copy_u8Value;             break; 
    case DIO_u8PORTB :   PORTB =copy_u8Value;             break;
    case DIO_u8PORTC :   PORTC =copy_u8Value;             break;
    case DIO_u8PORTD :   PORTD =copy_u8Value;             break;
    default          :   Local_DIO_ErrorState=DIO_ERROR;  break;
    }
return Local_DIO_ErrorState;
}  


EN_DIOError_t DIO_u8GetPinValue(u8 copy_u8Port,u8 copy_u8Pin,u8* Copy_pu8Value)
{
EN_DIOError_t Local_DIO_ErrorState=DIO_OK;

    if ((Copy_pu8Value!=NULL) && (copy_u8Pin<=7))
    {
        switch (copy_u8Port)
        {
        case DIO_u8PORTA :   *Copy_pu8Value=GET_BIT(PINA , copy_u8Pin); break;
        case DIO_u8PORTB :   *Copy_pu8Value=GET_BIT(PINB , copy_u8Pin); break;
        case DIO_u8PORTC :   *Copy_pu8Value=GET_BIT(PINC , copy_u8Pin); break;
        case DIO_u8PORTD :   *Copy_pu8Value=GET_BIT(PIND , copy_u8Pin); break;
        default          :   Local_DIO_ErrorState=DIO_ERROR;            break;
        }
    }
    else
    Local_DIO_ErrorState=DIO_ERROR;
return Local_DIO_ErrorState;
}


EN_DIOError_t DIO_u8TogglePinValue(u8 copy_u8Port,u8 copy_u8Pin)
{
EN_DIOError_t Local_DIO_ErrorState=DIO_OK;
    if( copy_u8Pin<=7 )
    {
        switch (copy_u8Port)
        {
        case DIO_u8PORTA :   TOGGLE_BIT(PORTA , copy_u8Pin); break;
        case DIO_u8PORTB :   TOGGLE_BIT(PORTB , copy_u8Pin); break;
        case DIO_u8PORTC :   TOGGLE_BIT(PORTC , copy_u8Pin); break;
        case DIO_u8PORTD :   TOGGLE_BIT(PORTD , copy_u8Pin); break;
        default          :   Local_DIO_ErrorState=DIO_ERROR; break;
        }
    }
    else
    Local_DIO_ErrorState=DIO_ERROR;

return Local_DIO_ErrorState;
}
