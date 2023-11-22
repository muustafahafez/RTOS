/*************************************************************************************/
/*************************************************************************************/
/*********************   Author: Mustafa Hafez ***************************************/
/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_interface.h"
#include "TIMER0_interface.h"
#include "RTOS_config.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_register.h"


STask_t System_Tasks[TASKNUM] = {{NULL}};


void RTOS_voidStart(){

	/*send ISR */
	TIMER0_voidSetCallBackFun(&void_schedular);
	/*Initial Timer 0*/
	TIMER0_voidInit();
	/*Enable GIE*/
	GIE_voidEnable();


}


RTOS_ErrorStatus RTOS_voidNewTask(u16 copy_u16Periodicity , u8 copy_u8Priorty, void (*Pfunc)(void)){

	/*check if priority is exist or not*/
	if(System_Tasks[copy_u8Priorty].PFunc==NULL)
	{
		System_Tasks[copy_u8Priorty].periodicity = copy_u16Periodicity;
		System_Tasks[copy_u8Priorty].PFunc = Pfunc;
		System_Tasks[copy_u8Priorty].state = RESUME_TASK;
		return RTOS_NoError;
	}
	else
	{
		return RTOS_ErrorPririotyExist;
	}


}


/*=======================================================
 * ======================================================*/




/*=======================================================
 * =====================================================*/
static void void_schedular(void){


	u8 Local_u8Ittirate = 0;
	static u16 Local_u16CounterTick=0;

	/*check which task achieve the desired tick number*/
	for(Local_u8Ittirate =0 ; Local_u8Ittirate <TASKNUM ; Local_u8Ittirate++)
	{
		/*check if task suspended or not*/
		if(System_Tasks[Local_u8Ittirate].state==RESUME_TASK)
		{

			if((Local_u16CounterTick % System_Tasks[Local_u8Ittirate].periodicity)==0)
			{
				if(System_Tasks[Local_u8Ittirate].PFunc!=NULL)
				{

					System_Tasks[Local_u8Ittirate].PFunc();
				}

			}
			else
			{

			}
		}
		else
		{
			/*Do nothing*/
		}
	}
	Local_u16CounterTick++;

}

RTOS_ErrorStatus RTOS_voidDeleteTask(u8 copy_u8Priority){

	/*check if the user pass a correct priority*/
	if(copy_u8Priority<TASKNUM)
	{
		System_Tasks[copy_u8Priority].PFunc=NULL;
		return RTOS_TaskDeleted;

	}
	else
	{
		return RTOS_TaskNotDeleted;

	}

}
RTOS_ErrorStatus RTOS_voidResumeTask(u8 copy_u8Priority){

	/*check if task exist*/
	if(System_Tasks[copy_u8Priority].PFunc!=NULL)
	{
		System_Tasks[copy_u8Priority].state = RESUME_TASK;
		return RTOS_TaskResumed;

	}
	else {
		return RTOS_TaskResumedFailed;

	}


}
RTOS_ErrorStatus RTOS_voidSuspendTask(u8 copy_u8Priority){
	/*check if task exist*/

	if(System_Tasks[copy_u8Priority].PFunc!=NULL)
	{
		System_Tasks[copy_u8Priority].state = SUSPEND_TASK;
		return RTOS_TaskSuspended;

	}
	else {
		return RTOS_TaskSuspendedFailed;

	}


}
