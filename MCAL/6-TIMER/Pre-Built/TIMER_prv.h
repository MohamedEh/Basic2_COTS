#ifndef TIMER_PRV_H
#define TIMER_PRV_H

#define NO_CLOCK					0U
#define SYSTEM_CLOCK				1U
#define DIVISION_BY_8				2U
#define DIVISION_BY_64				3U
#define DIVISION_BY_256				4U
#define DIVISION_BY_1024			5U
#define EXT_CLCK_FALLING			6U
#define EXT_CLCK_RISING				7U

#define Prescaler_Mask				0b11111000

#define	NORMAL                      0U
#define	PWM_PHASE_CORRECTION        1U
#define	CTC                         2U
#define	FAST_PWM                    3U

#define	NORMAL                      0U
#define	TOGGLE				        1U
#define	CLEAR                       2U
#define	SET		                    3U

#endif
