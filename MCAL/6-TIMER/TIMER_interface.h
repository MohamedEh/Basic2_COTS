#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include "TIMER_reg.h"

typedef enum {
	TIMER0=0U,
	TIMER1,
	TIMER2
}TIMER_TimerNum_t;

#define TIMER_REG			TCNT0

void TIMER_voidTnit(void);

uint8 TIMER_u8SetCallBack(TIMER_TimerNum_t copy_TimerNum,void(*copy_pfFunctionPtr)(void));


#endif
