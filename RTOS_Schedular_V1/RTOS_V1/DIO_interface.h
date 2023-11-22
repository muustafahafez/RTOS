/***********************************************************************************************////////////
/***********************************************************************************************//////////
/**********************************    Author:  Mustafa Hafez    *******************************////////
/**********************************    Layer:   MCAL             *******************************//////
/**********************************    SWC:     DIO              *******************************////
/**********************************    Version: 1.0              *******************************///

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"
/*set pin direction*/
#define DIO_u8PIN_OUTPUT 1
#define DIO_u8PIN_INPUT  0


/*set port as input or output*/
#define DIO_u8PORT_OUTPUT 0xFF
#define DIO_u8PORT_INPUT  0x00



/*set pin value*/
#define DIO_u8PIN_HIGH  1
#define DIO_u8PIN_LOW   0

/*set port as high or low*/

#define DIO_u8PORT_HIGH  0xFF
#define DIO_u8PORT_LOW   0x00

/*SET PORT*/

#define DIO_u8PORTA     0
#define DIO_u8PORTB     1
#define DIO_u8PORTC     2
#define DIO_u8PORTD     3

#define DIO_u8PIN0      0
#define DIO_u8PIN1      1
#define DIO_u8PIN2      2
#define DIO_u8PIN3      3
#define DIO_u8PIN4      4
#define DIO_u8PIN5      5
#define DIO_u8PIN6      6
#define DIO_u8PIN7      7


u8 DIO_u8SetPinDirecton(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Direction);
u8 DIO_u8SetPortDirecton(u8 copy_u8Port,u8 copy_u8Direction);


u8 DIO_u8SetPinValue(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Value);
u8 DIO_u8SetPortValue(u8 copy_u8Port,u8 copy_u8Value);

u8 DIO_u8GetPinValue(u8 copy_u8Port,u8 copy_u8Pin,u8* copy_pu8Value);











#endif
