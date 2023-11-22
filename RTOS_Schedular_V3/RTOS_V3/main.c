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
#include "util/delay.h"

#define Mode	NON_PREMITIVE

#define PREMITIVE		1
#define NON_PREMITIVE	2


void LED1();
void LED2();
void LED3();

extern u8 Golbal_flag;
void main(void)
{
	PORT_voidInit();
	RTOS_voidStart();
	//Periodicitiy  = 10ms
	RTOS_voidNewTask(10,0,&LED1,0);
	//Periodicitiy  = 20ms , FD = 1ms
	RTOS_voidNewTask(20,0,&LED2,0);
	//Periodicitiy  = 30ms , FD = 3ms
	RTOS_voidNewTask(30,1,&LED3,0);

	while(1){

	}



}

void LED1()
{

//#if(Mode==NON_PREMITIVE)
//	GIE_voidDisable();
//#endif

	static u8 Local_u8PinStat=1;
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN5,Local_u8PinStat);
	Local_u8PinStat^=1;


//	GIE_voidEnable();


}

void LED2()
{
//#if(Mode==NON_PREMITIVE)
//	GIE_voidDisable();
//#endif

	static u8 Local_u8PinStat=1;
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN6,Local_u8PinStat);
	Local_u8PinStat^=1;
//	GIE_voidEnable();

}
void LED3()
{
//#if(Mode==NON_PREMITIVE)
//	GIE_voidDisable();
//#endif

	static u8 Local_u8PinStat=1;
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN7,Local_u8PinStat);
	Local_u8PinStat^=1;
//	GIE_voidEnable();

}
