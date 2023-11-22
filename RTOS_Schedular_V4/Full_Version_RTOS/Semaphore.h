/*
 * Semaphore.h
 *
 *  Created on: Nov 22, 2023
 *      Author: Mustafa Hafez
 */

#ifndef SEMAPHORE_H_
#define SEMAPHORE_H_

typedef struct {

	u8 State;
	u8 Value;

}Semaphore_Binary_t;



typedef struct {

	u8 State;
	u8 Value;

}Semaphore_Counter_t;


typedef enum
{
	Pdpass,
	Pdfail

}Semaphore_ErrorState_enum;

#define Available	1
#define Not_Available	2

Semaphore_ErrorState_enum Semaphore_voidBinaryCreate(Semaphore_Binary_t*,u8 Copy_u8InitialState);
Semaphore_ErrorState_enum Semaphore_Binary_enuTake(Semaphore_Binary_t* semaphore);
Semaphore_ErrorState_enum Semaphore_Binary_enuGive(Semaphore_Binary_t* semaphore);

Semaphore_ErrorState_enum Semaphore_voidCounnterCreate(Semaphore_Counter_t*,u8 Copy_u8InitialValue);
Semaphore_ErrorState_enum Semaphore_Counter_enuTake(Semaphore_Counter_t* semaphore);
Semaphore_ErrorState_enum Semaphore_Counter_enuGive(Semaphore_Counter_t* semaphore);


#endif /* SEMAPHORE_H_ */
