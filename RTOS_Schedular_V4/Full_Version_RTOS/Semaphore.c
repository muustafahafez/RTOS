/*
 * Semaphore.c
 *
 *  Created on: Nov 22, 2023
 *      Author: Mustafa Hafez
 */
#include "STD_TYPES.h"
#include "Semaphore.h"


/*======================================================================
 * 							Binary Semaphore
 * =====================================================================*/

Semaphore_ErrorState_enum Semaphore_voidBinaryCreate(Semaphore_Binary_t* semaphore,u8 Copy_u8InitialState)
{

	//check if semaphore exist
	if(semaphore!=NULL)
	{
		switch(Copy_u8InitialState)
		{
		case Available:
			semaphore->Value=1;
			semaphore->State=Available;
			break;
		case Not_Available:
			semaphore->Value=0;
			semaphore->State=Not_Available;
			break;
		}

		return Pdpass;
	}

	else {
		return Pdfail;
	}
}



Semaphore_ErrorState_enum Semaphore_Binary_enuTake(Semaphore_Binary_t* semaphore)
{
	//check if semaphore available or not
	if(semaphore->State ==Available)
	{
		semaphore->Value = 0;
		semaphore->State = Not_Available;
		return Pdpass;
	}

	return Pdfail;
}
Semaphore_ErrorState_enum Semaphore_Binary_enuGive(Semaphore_Binary_t* semaphore)
{
	semaphore->Value = 1;
	semaphore->State = Available;
	return Pdpass;

}



/*======================================================================
 * 							Counter Semaphore
 * =====================================================================*/

Semaphore_ErrorState_enum Semaphore_voidCounnterCreate(Semaphore_Counter_t*semaphore,u8 Copy_u8InitialValue)
{
	if(semaphore!=NULL)
	{
		semaphore->Value = Copy_u8InitialValue;
		if(Copy_u8InitialValue==0)
		{
			semaphore->State =Not_Available;
		}
		else {
			semaphore->State =Available;
		}

		return Pdpass;
	}
	else
	{
		return Pdfail;

	}
}

Semaphore_ErrorState_enum Semaphore_Counter_enuTake(Semaphore_Counter_t* semaphore)
{
	return Pdfail;
}
Semaphore_ErrorState_enum Semaphore_Counter_enuGive(Semaphore_Counter_t* semaphore)
{

	return Pdfail;
}
