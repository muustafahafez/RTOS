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

STask_t System_Tasks[TASKNUM][PRIORITY] = {{NULL}};


void RTOS_voidStart(){

	/*send ISR */
	TIMER0_voidSetCallBackFun(&void_schedular);
	/*Initial Timer 0*/
	TIMER0_voidInit();
	/*Enable GIE*/
	GIE_voidEnable();


}


RTOS_ErrorStatus RTOS_voidNewTask(u16 copy_u16Periodicity , u8 copy_u8Priorty, void (*Pfunc)(void),u16 copy_u16FirstDelay){

	/*check if priority is exist or not*/


	if(System_Tasks[copy_u8Priorty][0].PFunc==NULL)
	{
		System_Tasks[copy_u8Priorty][0].periodicity = copy_u16Periodicity;
		System_Tasks[copy_u8Priorty][0].PFunc = Pfunc;
		System_Tasks[copy_u8Priorty][0].state = RESUME_TASK;
		return RTOS_NoError;
	}

	else if(System_Tasks[copy_u8Priorty][1].PFunc==NULL)
	{
		System_Tasks[copy_u8Priorty][1].periodicity = copy_u16Periodicity;
		System_Tasks[copy_u8Priorty][1].PFunc = Pfunc;
		System_Tasks[copy_u8Priorty][1].state = RESUME_TASK;
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


//	u8 Local_u8Ittirate = 0;
	u8 Local_u8IttirateT = 0;
	u8 Local_u8IttirateP = 0;
	/*check which task achieve the desired tick number*/

	for(Local_u8IttirateT =0 ; Local_u8IttirateT <TASKNUM ; Local_u8IttirateT++)
	{
		for(Local_u8IttirateP =0 ; Local_u8IttirateP <PRIORITY ; Local_u8IttirateP++)
		{
			if(System_Tasks[Local_u8IttirateT][Local_u8IttirateP].state==RESUME_TASK)
			{
				if(System_Tasks[Local_u8IttirateT][Local_u8IttirateP].FirstDelay==0)
				{
					if(System_Tasks[Local_u8IttirateT][Local_u8IttirateP].PFunc!=NULL)
					{
						System_Tasks[Local_u8IttirateT][Local_u8IttirateP].FirstDelay = System_Tasks[Local_u8IttirateT][Local_u8IttirateP].periodicity-1;

						System_Tasks[Local_u8IttirateT][Local_u8IttirateP].PFunc();
					}

				}
				else
				{
					System_Tasks[Local_u8IttirateT][Local_u8IttirateP].FirstDelay--;

				}
			}
			else
			{
				/*Do nothing*/
			}

		}

	}
//	for(Local_u8Ittirate =0 ; Local_u8Ittirate <TASKNUM ; Local_u8Ittirate++)
//	{
//		/*check if task suspended or not*/
//		if(System_Tasks[Local_u8Ittirate].state==RESUME_TASK)
//		{
//
//			if(System_Tasks[Local_u8Ittirate].FirstDelay==0)
//			{
//				if(System_Tasks[Local_u8Ittirate].PFunc!=NULL)
//				{
//					System_Tasks[Local_u8Ittirate].FirstDelay = System_Tasks[Local_u8Ittirate].periodicity-1;
//
//					System_Tasks[Local_u8Ittirate].PFunc();
//				}
//
//			}
//			else
//			{
//				System_Tasks[Local_u8Ittirate].FirstDelay--;
//			}
//		}
//		else
//		{
//			/*Do nothing*/
//		}
//	}

}


//
//RTOS_ErrorStatus RTOS_voidDeleteTask(u8 copy_u8Priority){
//
//	/*check if the user pass a correct priority*/
//	if(copy_u8Priority<TASKNUM)
//	{
//		System_Tasks[copy_u8Priority].PFunc=NULL;
//		return RTOS_TaskDeleted;
//
//	}
//	else
//	{
//		return RTOS_TaskNotDeleted;
//
//	}
//
//}


//
//RTOS_ErrorStatus RTOS_voidResumeTask(u8 copy_u8Priority){
//
//	/*check if task exist*/
//	if(System_Tasks[copy_u8Priority].PFunc!=NULL)
//	{
//		System_Tasks[copy_u8Priority].state = RESUME_TASK;
//		return RTOS_TaskResumed;
//
//	}
//	else {
//		return RTOS_TaskResumedFailed;
//
//	}
//
//
//}


//
//RTOS_ErrorStatus RTOS_voidSuspendTask(u8 copy_u8Priority){
//	/*check if task exist*/
//
//	if(System_Tasks[copy_u8Priority].PFunc!=NULL)
//	{
//		System_Tasks[copy_u8Priority].state = SUSPEND_TASK;
//		return RTOS_TaskSuspended;
//
//	}
//	else {
//		return RTOS_TaskSuspendedFailed;
//
//	}
//
//
//}
