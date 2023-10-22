#ifndef TIMER_CFG_H
#define TIMER_CFG_H

/*Configure TIMER0 Prescaler Division Factor 1- NO_CLOCK
 * 										  2- SYSTEM_CLOCK
 * 										  3- DIVISION_BY_8
 * 										  4- DIVISION_BY_64
 * 										  5- DIVISION_BY_256
 * 										  6- DIVISION_BY_1024
 * 										  7- EXT_CLCK_FALLING
 * 										  8- EXT_CLCK_RISING*/

#define TIMER0_u8PRESCALER					DIVISION_BY_64

#define TIMER0_u8COMPAREVALUE				64


/*Configure TIMER0 MODE of OPERATION		  1- NORMAL
 * 										  2- PWM_PHASE_CORRECTION
 * 										  3- CTC
 * 										  4- FAST_PWM
 */
#define TIMER0_u8OPERATION_MODE					FAST_PWM

/*Configure TIMER0 MODE of OPERATION	  1- NORMAL
 * 										  2- TOGGLE(Reserved in Fast PWM)
 * 										  3- CLEAR(clear on compare set on top in Fast PWM)
 * 										  4- SET(Set on compare Clear on top in Fast PWM)
 */
#define Timer0_u8OUTPUT_MODE					CLEAR



/*Configure TIMER2 Prescaler Division Factor 1- NO_CLOCK
 * 										  2- SYSTEM_CLOCK
 * 										  3- DIVISION_BY_8
 * 										  4- DIVISION_BY_64
 * 										  5- DIVISION_BY_256
 * 										  6- DIVISION_BY_1024
 * 										  7- EXT_CLCK_FALLING
 * 										  8- EXT_CLCK_RISING*/

#define TIMER2_u8PRESCALER					DIVISION_BY_64

#define TIMER2_u8COMPAREVALUE				250


/*Configure TIMER2 MODE of OPERATION		  1- NORMAL
 * 										  2- PWM_PHASE_CORRECTION
 * 										  3- CTC
 * 										  4- FAST_PWM
 */
#define TIMER2_u8OPERATION_MODE					CTC

/*Configure TIMER2 MODE of OPERATION		  1- NORMAL
 * 										  2- TOGGLE
 * 										  3- CLEAR
 * 										  4- SET
 */
#define Timer2_u8CTC_OUTPUT_MODE					NORMAL



#endif
