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
#include "Queue.h"
#include "Semaphore.h"



void LED1();
void LED2();
void LED3();

FIFO_t Task_FIFO;
DataType Task_Buffer[5];
Semaphore_Binary_t SemBinary;
Semaphore_Counter_t SemCounter;

void main(void)
{
	PORT_voidInit();
	FIFO_Init(&Task_FIFO,Task_Buffer,5);

	Semaphore_voidBinaryCreate(&SemBinary,Available);
	Semaphore_voidCounnterCreate(&SemCounter,10);

	RTOS_voidNewTask(10,0,&LED1,0);
	RTOS_voidNewTask(5,1,&LED2,0);
	RTOS_voidNewTask(30,0,&LED3,0);
	RTOS_voidStart();


	while(1){

	}


}

void LED1()
{

	if(Pdpass==Semaphore_Binary_enuTake(&SemBinary))
	{
		FIFO_Enqueue(&Task_FIFO,1);
		FIFO_Enqueue(&Task_FIFO,2);

		Semaphore_Binary_enuGive(&SemBinary);
	}

}

void LED2()
{

	static u8 Read1,Read2;
	static u8 Local_u8PinStat=1;

	if(Pdpass==Semaphore_Binary_enuTake(&SemBinary))
	{
		FIFO_Dequeue(&Task_FIFO,&Read1);
		FIFO_Dequeue(&Task_FIFO,&Read2);
		Semaphore_Binary_enuGive(&SemBinary);
	}
	if(Read1 ==1)
	{
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN7,Local_u8PinStat);
		Local_u8PinStat^=1;
	}

}
void LED3()
{

	static u8 Local_u8PinStat=1;
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN7,Local_u8PinStat);
	Local_u8PinStat^=1;

}
