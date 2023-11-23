/*
 * main.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Mustafa Hafez
 */


#include "TIMER0_interface.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_interface.h"
#include "RTOS_interface.h"
#include "util/delay.h"

void LED1();
void LED2();
void LED3();

extern u8 Global_u8Flag;
extern u8 Global_u8TaskFlags[3];
void (*Pfunc[3])(void) = {LED1,LED2,LED3};



void main(void)
{
	u8 Local_u8Itter;
	PORT_voidInit();
	RTOS_voidNewTask(10,0,&LED1,0);
	RTOS_voidNewTask(5,1,&LED2,0);
	RTOS_voidNewTask(30,2,&LED3,0);
	RTOS_voidStart();


	while(1){


		for(Local_u8Itter=0;Local_u8Itter<3;Local_u8Itter++)
		{
			if (Global_u8TaskFlags[Local_u8Itter]==1)
			{
				Global_u8TaskFlags[Local_u8Itter]=0;
				Pfunc[Local_u8Itter]();

			}
		}


	}


}

void LED1()
{

	static u8 Local_u8PinStat=1;
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN5,Local_u8PinStat);
	_delay_ms(4000);
	Local_u8PinStat^=1;
}

void LED2()
{
	static u8 Local_u8PinStat=1;
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN6,Local_u8PinStat);
	Local_u8PinStat^=1;

}
void LED3()
{
	static u8 Local_u8PinStat=1;
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN7,Local_u8PinStat);
	Local_u8PinStat^=1;
}
