/***********************************************************************************************////////////
/***********************************************************************************************//////////
/**********************************    Author:  Mustafa Hafez    *******************************////////
/**********************************    Layer:   MCAL             *******************************//////
/**********************************    SWC:     PORT              *******************************////
/**********************************    Version: 1.0              *******************************///

#ifndef PORT_CONFIG_H_
#define	PORT_CONFIG_H_

#define INPUT				   0
#define OUTPUT				   1



#define PORTA_PIN0_DIR         OUTPUT
#define PORTA_PIN1_DIR         OUTPUT
#define PORTA_PIN2_DIR         OUTPUT
#define PORTA_PIN3_DIR         OUTPUT
#define PORTA_PIN4_DIR         OUTPUT
#define PORTA_PIN5_DIR         OUTPUT
#define PORTA_PIN6_DIR         OUTPUT
#define PORTA_PIN7_DIR         OUTPUT

/*CLCD*/
#define PORTB_PIN0_DIR         OUTPUT
#define PORTB_PIN1_DIR         OUTPUT
#define PORTB_PIN2_DIR         OUTPUT
#define PORTB_PIN3_DIR         OUTPUT
#define PORTB_PIN4_DIR         OUTPUT
#define PORTB_PIN5_DIR         OUTPUT
#define PORTB_PIN6_DIR         OUTPUT
#define PORTB_PIN7_DIR         OUTPUT


#define PORTC_PIN0_DIR         OUTPUT
#define PORTC_PIN1_DIR         OUTPUT
#define PORTC_PIN2_DIR         OUTPUT
#define PORTC_PIN3_DIR         OUTPUT
#define PORTC_PIN4_DIR         OUTPUT
#define PORTC_PIN5_DIR         OUTPUT
#define PORTC_PIN6_DIR         OUTPUT
#define PORTC_PIN7_DIR         OUTPUT

/*RX --> PD0 --> Input
 *TX --> PD1 --> Output */


#define PORTD_PIN0_DIR         OUTPUT
#define PORTD_PIN1_DIR         OUTPUT
#define PORTD_PIN2_DIR         OUTPUT
#define PORTD_PIN3_DIR         OUTPUT
#define PORTD_PIN4_DIR         OUTPUT
#define PORTD_PIN5_DIR         OUTPUT
#define PORTD_PIN6_DIR         OUTPUT
#define PORTD_PIN7_DIR         OUTPUT

/* If DDR is input Then, 0 for floating But 1 for pulled-up*/
/* If DDR is output Then, 0 for Low But 1 for High        */

#define PORTA_PIN0_INIT_VALUE    0
#define PORTA_PIN1_INIT_VALUE    0
#define PORTA_PIN2_INIT_VALUE    0
#define PORTA_PIN3_INIT_VALUE    0
#define PORTA_PIN4_INIT_VALUE    0
#define PORTA_PIN5_INIT_VALUE    0
#define PORTA_PIN6_INIT_VALUE    0
#define PORTA_PIN7_INIT_VALUE    0


#define PORTB_PIN0_INIT_VALUE    0
#define PORTB_PIN1_INIT_VALUE    0
#define PORTB_PIN2_INIT_VALUE    0
#define PORTB_PIN3_INIT_VALUE    0
#define PORTB_PIN4_INIT_VALUE    0
#define PORTB_PIN5_INIT_VALUE    0
#define PORTB_PIN6_INIT_VALUE    0
#define PORTB_PIN7_INIT_VALUE    0


#define PORTC_PIN0_INIT_VALUE    0
#define PORTC_PIN1_INIT_VALUE    1
#define PORTC_PIN2_INIT_VALUE    1
#define PORTC_PIN3_INIT_VALUE    0
#define PORTC_PIN4_INIT_VALUE    0
#define PORTC_PIN5_INIT_VALUE    0
#define PORTC_PIN6_INIT_VALUE    0
#define PORTC_PIN7_INIT_VALUE    0


#define PORTD_PIN0_INIT_VALUE    0
#define PORTD_PIN1_INIT_VALUE    0
#define PORTD_PIN2_INIT_VALUE    0
#define PORTD_PIN3_INIT_VALUE    0
#define PORTD_PIN4_INIT_VALUE    0
#define PORTD_PIN5_INIT_VALUE    0
#define PORTD_PIN6_INIT_VALUE    0
#define PORTD_PIN7_INIT_VALUE    0


#endif
