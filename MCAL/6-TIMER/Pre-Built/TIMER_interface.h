#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include "TIMER_reg.h"

typedef enum {
	TIMER0=0U,
	TIMER1,
	TIMER2
}TIMER_TimerNum_t;

#define TIMER0_OVR_REG			TCNT0

#define TIMER0_CMP_REG			OCR0

#define TIMER2_OVR_REG			TCNT2

#define TIMER2_CMP_REG			OCR2

void TIMER0_voidTnit(void);

uint8 TIMER0_u8SetCallBack(void(*copy_pfFunctionPtr)(void));

void TIMER0_voidSetCompVal(uint8 copy_u8CompVal);

void TIMER1_voidTnit(void);

uint16 TIMER1_u16GetTimerVal(void);

void TIMER1_SetTimerVal(uint16 copy_u16Val);

void TIMER2_voidTnit(void);

uint8 TIMER2_u8SetCallBack(void(*copy_pfFunctionPtr)(void));
#endif
