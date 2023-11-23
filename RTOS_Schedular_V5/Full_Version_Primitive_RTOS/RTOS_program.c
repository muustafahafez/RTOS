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

u8 Global_u8Flag =0;
u8 Global_u8Task1 =0;
u8 Global_u8Task2 =0;
u8 Global_u8Task3 =0;
u8 Global_u8TaskFlags[TASKNUM];

STask_t System_Tasks[TASKNUM] = {{NULL}};
static void void_ISR(void);
void RTOS_voidStart() {

	/*send ISR */
	TIMER0_voidSetCallBackFun(&void_schedular);
	/*Initial Timer 0*/
	TIMER0_voidInit();
	/*Enable GIE*/
	GIE_voidEnable();

}

RTOS_ErrorStatus RTOS_voidNewTask(u16 copy_u16Periodicity, u8 copy_u8Priorty,
		void (*Pfunc)(void), u16 copy_u16FirstDelay) {

	/*check if priority is exist or not*/

	if (System_Tasks[copy_u8Priorty].PFunc == NULL) {
		System_Tasks[copy_u8Priorty].periodicity = copy_u16Periodicity;
		System_Tasks[copy_u8Priorty].FirstDelay = copy_u16FirstDelay;
		System_Tasks[copy_u8Priorty].PFunc = Pfunc;
		System_Tasks[copy_u8Priorty].state = RESUME_TASK;
		return RTOS_NoError;
	}

	else {
		return RTOS_ErrorPririotyExist;
	}

}

/*=======================================================
 * ======================================================*/

/*=======================================================
 * =====================================================*/

void void_schedular(void) {

	u8 Local_u8Ittirate = 0;

	{
		/*check which task achieve the desired tick number*/
			for(Local_u8Ittirate =0 ; Local_u8Ittirate <TASKNUM ; Local_u8Ittirate++)
			{
				/*check if task suspended or not*/
				if(System_Tasks[Local_u8Ittirate].state==RESUME_TASK)
				{

					if(System_Tasks[Local_u8Ittirate].FirstDelay==0)
					{
						if(System_Tasks[Local_u8Ittirate].PFunc!=NULL)
						{
							System_Tasks[Local_u8Ittirate].FirstDelay = System_Tasks[Local_u8Ittirate].periodicity-1;

							Global_u8TaskFlags[Local_u8Ittirate]=1;

							//							System_Tasks[Local_u8Ittirate].PFunc();
						}

					}
					else
					{
						System_Tasks[Local_u8Ittirate].FirstDelay--;
					}
				}
				else
				{
					/*Do nothing*/
				}
			}


	}

}


//////////////////////////////////////





//
//void void_schedular(void) {
//
//	u8 Local_u8Ittirate = 0;
//
//	Global_u8Flag=0;
//	{
//		/*check which task achieve the desired tick number*/
//			for(Local_u8Ittirate =0 ; Local_u8Ittirate <TASKNUM ; Local_u8Ittirate++)
//			{
//				/*check if task suspended or not*/
//				if(System_Tasks[Local_u8Ittirate].state==RESUME_TASK)
//				{
//
//					if(System_Tasks[Local_u8Ittirate].FirstDelay==0)
//					{
//						if(System_Tasks[Local_u8Ittirate].PFunc!=NULL)
//						{
//							System_Tasks[Local_u8Ittirate].FirstDelay = System_Tasks[Local_u8Ittirate].periodicity-1;
//							System_Tasks[Local_u8Ittirate].PFunc();
//						}
//
//					}
//					else
//					{
//						System_Tasks[Local_u8Ittirate].FirstDelay--;
//					}
//				}
//				else
//				{
//					/*Do nothing*/
//				}
//			}
//
//
//	}
//
//}






////////////////////////////////////



//
//RTOS_ErrorStatus RTOS_voidDeleteTask(void (*Pfunc)(void)) {
//
//	u8 Local_u8IttirateT, Local_u8IttirateP, Local_u8State;
//	/*check if the user pass a correct priority*/
//	if (Pfunc != NULL) {
//		for (Local_u8IttirateT = 0; Local_u8IttirateT < TASKNUM;
//				Local_u8IttirateT++) {
//			for (Local_u8IttirateP = 0; Local_u8IttirateP < PRIORITY;
//					Local_u8IttirateP++) {
//				if (System_Tasks[Local_u8IttirateT][Local_u8IttirateP].PFunc
//						== Pfunc) {
//					System_Tasks[Local_u8IttirateT][Local_u8IttirateP].PFunc =
//							NULL;
//					Local_u8State = RTOS_TaskDeleted;
//				}
//
//			}
//
//		}
//
//	} else {
//		Local_u8State = RTOS_TaskNotDeleted;
//
//	}
//	return Local_u8State;
//
//}
//
//RTOS_ErrorStatus RTOS_voidResumeTask(void (*Pfunc)(void)) {
//
//	u8 Local_u8IttirateT, Local_u8IttirateP, Local_u8State;
//	if (Pfunc != NULL) {
//		for (Local_u8IttirateT = 0; Local_u8IttirateT < TASKNUM;
//				Local_u8IttirateT++) {
//			for (Local_u8IttirateP = 0; Local_u8IttirateP < PRIORITY;
//					Local_u8IttirateP++) {
//				if (System_Tasks[Local_u8IttirateT][Local_u8IttirateP].PFunc
//						== Pfunc) {
//					System_Tasks[Local_u8IttirateT][Local_u8IttirateP].state =
//							RESUME_TASK;
//					Local_u8State = RTOS_TaskResumed;
//				}
//
//			}
//
//		}
//
//	} else {
//		Local_u8State = RTOS_TaskResumedFailed;
//
//	}
//	return Local_u8State;
//
//}
//
//RTOS_ErrorStatus RTOS_voidSuspendTask(void (*Pfunc)(void)) {
//	u8 Local_u8IttirateT, Local_u8IttirateP, Local_u8State;
//	if (Pfunc != NULL) {
//		for (Local_u8IttirateT = 0; Local_u8IttirateT < TASKNUM;
//				Local_u8IttirateT++) {
//			for (Local_u8IttirateP = 0; Local_u8IttirateP < PRIORITY;
//					Local_u8IttirateP++) {
//				if (System_Tasks[Local_u8IttirateT][Local_u8IttirateP].PFunc
//						== Pfunc) {
//					System_Tasks[Local_u8IttirateT][Local_u8IttirateP].state =
//							SUSPEND_TASK;
//					Local_u8State = RTOS_TaskSuspended;
//				}
//
//			}
//
//		}
//
//	} else {
//		Local_u8State = RTOS_TaskSuspendedFailed;
//
//	}
//	return Local_u8State;
//}
