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
#include "LED_interface.h"


void LED1();
void LED2();
void LED3();


void main(void)
{
	PORT_voidInit();
	RTOS_voidStart();
	//Periodicitiy  = 10ms
	RTOS_voidNewTask(10,0,&LED1);
	//Periodicitiy  = 20ms
	RTOS_voidNewTask(20,1,&LED2);
	//Periodicitiy  = 30ms
	RTOS_voidNewTask(30,2,&LED3);

	while(1){


	}



}


void LED1()
{
	static u8 Local_u8PinStat=1;
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN5,Local_u8PinStat);
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
