/*
 * FIFO.c
 *
 *  Created on: Nov 22, 2023
 *      Author: Mustafa Hafez
 */

#include "Queue.h"

#include <stdint.h>
#include <stdio.h>







FIFO_Statues FIFO_Init(FIFO_t* Fifo,DataType* buffer,uint32_t length){

	//check if FIFO exist
//	if((buffer==NULL)||(Fifo->base==NULL)||(Fifo->head==NULL)||(Fifo->tail==NULL))
//		return FIFO_NULL;
	Fifo->base = buffer;
	Fifo->head = buffer;
	Fifo->tail = buffer;
	Fifo->length = length;
	Fifo->count = 0;
	return FIFO_NoError;

}

FIFO_Statues FIFO_Enqueue(FIFO_t* Fifo, DataType Item){

	//Check if exist
	if((Fifo->base==NULL)||(Fifo->head==NULL)||(Fifo->tail==NULL))
		return FIFO_NULL;

	//check if FUll
	if(Fifo->count == (Fifo->length * sizeof(DataType)))        //Ex: datatype size is 1 byte , Length  is 5 so if count ==  5 this mean we reach top.
		return FIFO_Full;
	//Add Item
	*(Fifo->head) = Item;
	Fifo->head++;
	Fifo->count++;

	return FIFO_NoError;

}

FIFO_Statues FIFO_Dequeue(FIFO_t* Fifo,DataType* Item){

	//Check if exist
	if((Fifo->base==NULL)||(Fifo->head==NULL)||(Fifo->tail==NULL))
		return FIFO_NULL;
	//check is empty or not
	if(Fifo->count==0)
		return FIFO_Empty;

	*Item = *(Fifo->tail);
	Fifo->count--;
	Fifo->tail++;
	return FIFO_NoError;

}

FIFO_Statues FIFO_PrintAll(FIFO_t* Fifo)
{

	DataType Temp;
	DataType* ptrtemp;  //temp pointer to the Fifo->tail as if we used the tail to navigate  to print that will damage our Fifo
	ptrtemp = Fifo->tail;
	//Check if exist
	if((Fifo->base==NULL)||(Fifo->head==NULL)||(Fifo->tail==NULL))
		return FIFO_NULL;
	//check is empty or not
	if(Fifo->count==0){
		printf("\t\tFifo is Empty\n");
		printf("================================================\n\n");

		return FIFO_Empty;}
	printf("=================FIFO Data======================\n\n");
	for(int j =0; j <Fifo->count;j++) //the condition is limited to the counts as it's an indicate to how many elements in the Fifo.
	{
		printf(" \t\t%d\n",*(ptrtemp)); // using temp pointer instead of Fifo->tail
		ptrtemp++;

	}
	printf("================================================\n\n");

	return FIFO_NoError;

}
