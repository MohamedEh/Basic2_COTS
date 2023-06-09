#include "STD_TYPES.h"
#include "BIT_MATh.h"
#include "Err_Type.h"

#include "TIMER_reg.h"
#include "TIMER_interface.h"
#include "TIMER_prv.h"
#include "TIMER_cfg.h"


static void (*TIMER_pvFunctionPtr[3])(void)={NULL,NULL,NULL};

void TIMER_voidTnit(void){
	/*Intiate Timer 0*/
	/*Make Waveform Generation Mode to be Normal*/
#if TIMER_u8OPERATION_MODE==NORMAL
	CLR_BIT(TCCR0,WGN01);
	CLR_BIT(TCCR0,WGN00);
#elif TIMER_u8OPERATION_MODE==PWM_PHASE_CORRECTION
	CLR_BIT(TCCR0,WGN01);
	SET_BIT(TCCR0,WGN00);
#elif TIMER_u8OPERATION_MODE==CTC
	SET_BIT(TCCR0,WGN01);
	CLR_BIT(TCCR0,WGN00);
#elif TIMER_u8OPERATION_MODE==FAST_PWM
	SET_BIT(TCCR0,WGN01);
	SET_BIT(TCCR0,WGN00);
#else
#error wrong TIMER_u8OPERATION_MODE Configuration value
#endif

	/*Select Clock Type*/
	TCCR0 &= Prescaler_Mask;
	TCCR0 |= TIMER_u8PRESCALER;

	/*Enable Interrupt*/
	SET_BIT(TIMSK,TOIE0);

}

uint8 TIMER_u8SetCallBack(TIMER_TimerNum_t copy_TimerNum,void(*copy_pvFunctionPtr)(void)){
	uint8 Local_u8Error_State=OK;
	if(copy_pvFunctionPtr!=NULL){
		if ((copy_TimerNum>=TIMER0)&&(copy_TimerNum<=TIMER2)){
			TIMER_pvFunctionPtr[copy_TimerNum]=copy_pvFunctionPtr;
		}
		else{
			Local_u8Error_State=NOK;
		}
	}
	else{
		Local_u8Error_State=NULL_PTR;
	}
	return Local_u8Error_State;
}


void __vector_11 (void) __attribute__((signal));
void __vector_11 (void){
	if(TIMER_pvFunctionPtr[TIMER0]!=NULL){
		TIMER_pvFunctionPtr[TIMER0]();
	}
	else{
		//Do nothing
	}
}

void __vector_9 (void) __attribute__((signal));
void __vector_9 (void){
	if(TIMER_pvFunctionPtr[TIMER1]!=NULL){
		TIMER_pvFunctionPtr[TIMER1]();
	}
	else{
		//Do nothing
	}
}

void __vector_5 (void) __attribute__((signal));
void __vector_5 (void){
	if(TIMER_pvFunctionPtr[TIMER2]!=NULL){
		TIMER_pvFunctionPtr[TIMER2]();
	}
	else{
		//Do nothing
	}
}
