#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "TIMER0_config.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_register.h"


//Global Pointer to Function

void (*GlobalPFunc)(void) = NULL;


/*Compare Match Value Handling by Interrupt*/
void TIMER0_voidInit(){


	/*select mode to Compare Match Value*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	/*Select Pre-Scaler dev by 64*/
	//	Local_u8PrescalerMask |= PRE_SCALER_64;
	//	TCCR0|=Local_u8PrescalerMask;
	/*What happen on OCR0 --> Toggle*/
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);
	/*Set the Compare Match Value*/
	OCR0 =Compare_Match_Value;
	/*Enable Compare Match value Interrupt*/
	SET_BIT(TIMSK,TIMSK_OCIE0);
	//	u8 Local_u8PrescalerMask = 0;
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);


}

/**/
void TIMER0_voidSetCallBackFun(void(*pFun)(void)){


	GlobalPFunc = pFun;

}



void __vector_10(void) __attribute__((signal)); /*attribute is a message from complier to the optimizer of linker to tell it that  its an interrupt signal*/
void __vector_10(void)
{
	GlobalPFunc();
}


