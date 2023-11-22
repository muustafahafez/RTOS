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

	if (System_Tasks[copy_u8Priorty][0].PFunc == NULL) {
		System_Tasks[copy_u8Priorty][0].periodicity = copy_u16Periodicity;
		System_Tasks[copy_u8Priorty][0].FirstDelay = copy_u16FirstDelay;
		System_Tasks[copy_u8Priorty][0].PFunc = Pfunc;
		System_Tasks[copy_u8Priorty][0].state = RESUME_TASK;
		return RTOS_NoError;
	}

	else if (System_Tasks[copy_u8Priorty][1].PFunc == NULL) {
		System_Tasks[copy_u8Priorty][1].periodicity = copy_u16Periodicity;
		System_Tasks[copy_u8Priorty][1].FirstDelay = copy_u16FirstDelay;
		System_Tasks[copy_u8Priorty][1].PFunc = Pfunc;
		System_Tasks[copy_u8Priorty][1].state = RESUME_TASK;
		return RTOS_NoError;

	} else {
		return RTOS_ErrorPririotyExist;
	}

}

/*=======================================================
 * ======================================================*/

/*=======================================================
 * =====================================================*/
static void void_schedular(void) {

	//	u8 Local_u8Ittirate = 0;
	u8 Local_u8IttirateT = 0;
	u8 Local_u8IttirateP = 0;
	/*check which task achieve the desired tick number*/

	for (Local_u8IttirateT = 0; Local_u8IttirateT < TASKNUM;
			Local_u8IttirateT++) {
		for (Local_u8IttirateP = 0; Local_u8IttirateP < PRIORITY;
				Local_u8IttirateP++) {
			if (System_Tasks[Local_u8IttirateT][Local_u8IttirateP].state
					== RESUME_TASK) {
				if (System_Tasks[Local_u8IttirateT][Local_u8IttirateP].FirstDelay
						== 0) {
					if (System_Tasks[Local_u8IttirateT][Local_u8IttirateP].PFunc
							!= NULL) {
						System_Tasks[Local_u8IttirateT][Local_u8IttirateP].FirstDelay =
								System_Tasks[Local_u8IttirateT][Local_u8IttirateP].periodicity
										- 1;

						System_Tasks[Local_u8IttirateT][Local_u8IttirateP].PFunc();
					}

				} else {
					System_Tasks[Local_u8IttirateT][Local_u8IttirateP].FirstDelay--;

				}
			} else {
				/*Do nothing*/
			}

		}

	}

}

RTOS_ErrorStatus RTOS_voidDeleteTask(void (*Pfunc)(void)) {

	u8 Local_u8IttirateT, Local_u8IttirateP, Local_u8State;
	/*check if the user pass a correct priority*/
	if (Pfunc != NULL) {
		for (Local_u8IttirateT = 0; Local_u8IttirateT < TASKNUM;
				Local_u8IttirateT++) {
			for (Local_u8IttirateP = 0; Local_u8IttirateP < PRIORITY;
					Local_u8IttirateP++) {
				if (System_Tasks[Local_u8IttirateT][Local_u8IttirateP].PFunc
						== Pfunc) {
					System_Tasks[Local_u8IttirateT][Local_u8IttirateP].PFunc =
							NULL;
					Local_u8State = RTOS_TaskDeleted;
				}

			}

		}

	} else {
		Local_u8State = RTOS_TaskNotDeleted;

	}
	return Local_u8State;

}

RTOS_ErrorStatus RTOS_voidResumeTask(void (*Pfunc)(void)) {

	u8 Local_u8IttirateT, Local_u8IttirateP, Local_u8State;
	if (Pfunc != NULL) {
		for (Local_u8IttirateT = 0; Local_u8IttirateT < TASKNUM;
				Local_u8IttirateT++) {
			for (Local_u8IttirateP = 0; Local_u8IttirateP < PRIORITY;
					Local_u8IttirateP++) {
				if (System_Tasks[Local_u8IttirateT][Local_u8IttirateP].PFunc
						== Pfunc) {
					System_Tasks[Local_u8IttirateT][Local_u8IttirateP].state =
							RESUME_TASK;
					Local_u8State = RTOS_TaskResumed;
				}

			}

		}

	} else {
		Local_u8State = RTOS_TaskResumedFailed;

	}
	return Local_u8State;

}

RTOS_ErrorStatus RTOS_voidSuspendTask(void (*Pfunc)(void)) {
	u8 Local_u8IttirateT, Local_u8IttirateP, Local_u8State;
	if (Pfunc != NULL) {
		for (Local_u8IttirateT = 0; Local_u8IttirateT < TASKNUM;
				Local_u8IttirateT++) {
			for (Local_u8IttirateP = 0; Local_u8IttirateP < PRIORITY;
					Local_u8IttirateP++) {
				if (System_Tasks[Local_u8IttirateT][Local_u8IttirateP].PFunc
						== Pfunc) {
					System_Tasks[Local_u8IttirateT][Local_u8IttirateP].state =
							SUSPEND_TASK;
					Local_u8State = RTOS_TaskSuspended;
				}

			}

		}

	} else {
		Local_u8State = RTOS_TaskSuspendedFailed;

	}
	return Local_u8State;
}
