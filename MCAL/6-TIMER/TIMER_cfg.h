#ifndef TIMER_CFG_H
#define TIMER_CFG_H

/*Configure TIMER Prescaler Division Factor 1- NO_CLOCK
 * 										  2- SYSTEM_CLOCK
 * 										  3- DIVISION_BY_8
 * 										  4- DIVISION_BY_64
 * 										  5- DIVISION_BY_256
 * 										  6- DIVISION_BY_1024
 * 										  7- EXT_CLCK_FALLING
 * 										  8- EXT_CLCK_RISING*/

#define TIMER_u8PRESCALER					DIVISION_BY_64

/*Configure TIMER MODE of OPERATION		  1- NORMAL
 * 										  2- PWM_PHASE_CORRECTION
 * 										  3- CTC
 * 										  4- FAST_PWM
 */
#define TIMER_u8OPERATION_MODE					NORMAL

#endif
