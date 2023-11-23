/*************************************************************************************/
/*************************************************************************************/
/*********************   Author: Mustafa Hafez ***************************************/
/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/
#ifndef  _RTOS_PRIVATE
#define  _RTOS_PRIVATE


/* the periodicity in ms unit
 * FirstDelay is to handle the CPU load
 * state used for suspend and Resume tasks
 * PFunc is a pointer to the function of desired task that take nothing and return nothig
 * */
typedef struct {

	u16 periodicity;
	u16 FirstDelay;
	u8 	state;
	void (*PFunc)(void);


}STask_t;


/*Tasks Statues*/
#define RESUME_TASK		1
#define SUSPEND_TASK	2





#endif



