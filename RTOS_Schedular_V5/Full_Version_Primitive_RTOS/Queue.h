/*
 * FIFO.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Mustafa Hafez
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdint.h>
#include <stdio.h>

/*This is a Generic FIFO that give you the ability to make your own queue.
 * you have to choose your datatype between the different configuration
 * this will affect on how you access your elements, 1 , 2 ,4 ,... bytes*/

#include "STD_TYPES.h"


//choose your data type to control how to access your queue: uint8_t , uint16_t , uint32_t.....

#define DataType	u8
typedef struct{

	DataType*		base;
	DataType* 		tail;
	DataType* 		head;
	uint32_t		length;
	uint32_t		count;

}FIFO_t;

typedef enum {
	FIFO_NoError,
	FIFO_NULL,
	FIFO_Empty,
	FIFO_Full
}FIFO_Statues;


/*APIs*/



/*Make sure that your created buffer is from the same "DataType" either was static(DataType array[]) or Dynamic (DataType*)ptr = (DataType*)malloc   */
FIFO_Statues FIFO_Init(FIFO_t* Fifo,DataType* buffer,uint32_t length);


/*Don't worry the API check for: Null and Full*/
FIFO_Statues FIFO_Enqueue(FIFO_t* Fifo, DataType Item);

/*Don't worry the API check for: Null and Empty*/
FIFO_Statues FIFO_Dequeue(FIFO_t* Fifo,DataType* Item);

FIFO_Statues FIFO_PrintAll(FIFO_t* Fifo);







#endif /* QUEUE_H_ */
