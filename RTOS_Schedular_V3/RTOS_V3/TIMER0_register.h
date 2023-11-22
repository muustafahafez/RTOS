
#ifndef TIMER_REGISTER_H
#define TIMER_REGISTER_H



#define TCCR0				*((volatile u8*)0x53)

#define TCCR0_WGM00			6			/*Waveform Generation Mode*/
#define TCCR0_WGM01			3

#define TCCR0_COM01			5			/*what happen on OC0 pin , toggle , SET , CLR at CTC interrupt*/
#define TCCR0_COM00			4

#define TCCR0_CS02			2			/*pre-scaler bits*/
#define TCCR0_CS01			1
#define TCCR0_CS00			0


#define OCR0				*((volatile u8*)0x5c) /*Output Compare Register*/



#define TIMSK				*((volatile u8*)0x59)  /*Timer/Counter Interrupt Mask*/


#define TIMSK_OCIE0			1	/*Timer/Counter0 Output Compare Match Interrupt Enable*/
#define TIMSK_TOIE0			0	/*Timer/Counter0 Overflow Interrupt EnablE*/

#endif
