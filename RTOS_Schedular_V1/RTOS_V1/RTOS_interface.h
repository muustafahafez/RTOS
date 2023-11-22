/*************************************************************************************/
/*************************************************************************************/
/*********************   Author: Mustafa Hafez ***************************************/
/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/
#ifndef		_RTOS_INTERFACE
#define 	_RTOS_INTERFACE

#include "STD_TYPES.h"



/*RTOS statues*/
typedef enum{

	RTOS_ErrorPririotyExist,
	RTOS_NoError,
	RTOS_TaskDeleted,
	RTOS_TaskNotDeleted,
	RTOS_TaskSuspended,
	RTOS_TaskSuspendedFailed,
	RTOS_TaskResumed,
	RTOS_TaskResumedFailed
}RTOS_ErrorStatus;




void RTOS_voidStart();

/* the periodicity in ms unit as system tick is 1 ms
 * FirstDelay is to handle the CPU load
 * state used for suspend and Resume tasks
 * PFunc is a pointer to the function of desired task that take nothing and return nothing
 * Priority is used as an ID and as a priority task as the priority 0 is the most.
 * */
RTOS_ErrorStatus RTOS_voidNewTask(u16 copy_u16Periodicity , u8 copy_u8Priorty, void (*Pfunc)(void));

RTOS_ErrorStatus RTOS_voidDeleteTask(u8 copy_u8Priority);

RTOS_ErrorStatus RTOS_voidResumeTask(u8 copy_u8Priority);

RTOS_ErrorStatus RTOS_voidSuspendTask(u8 copy_u8Priority);




#endif
