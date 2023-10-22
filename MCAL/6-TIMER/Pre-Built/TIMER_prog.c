#include "STD_TYPES.h"
#include "BIT_MATh.h"
#include "Err_Type.h"

#include "TIMER_reg.h"
#include "TIMER_interface.h"
#include "TIMER_prv.h"
#include "TIMER_cfg.h"


static void (*TIMER_pvFunctionPtr[2])(void)={NULL};

void TIMER0_voidTnit(void){
	/*Intiate Timer 0*/
	/*Make Waveform Generation Mode to be Normal*/
#if TIMER0_u8OPERATION_MODE==NORMAL
	CLR_BIT(TCCR0,WGN01);
	CLR_BIT(TCCR0,WGN00);

	/*Select Clock Type*/
	TCCR0 &= Prescaler_Mask;
	TCCR0 |= TIMER0_u8PRESCALER;

	/*Enable Interrupt*/
	SET_BIT(TIMSK,TOIE0);
	/*Make Waveform Generation Mode to be PWM_PHASE_CORRECTION*/
#elif TIMER0_u8OPERATION_MODE==PWM_PHASE_CORRECTION
	CLR_BIT(TCCR0,WGN01);
	SET_BIT(TCCR0,WGN00);

	/*Select Clock Type*/
	TCCR0 &= Prescaler_Mask;
	TCCR0 |= TIMER0_u8PRESCALER;

	/*Enable Interrupt*/
	SET_BIT(TIMSK,TOIE0);
	/*Make Waveform Generation Mode to be CTC*/
#elif TIMER0_u8OPERATION_MODE==CTC
	SET_BIT(TCCR0,WGN01);
	CLR_BIT(TCCR0,WGN00);
#if Timer0_u8OUTPUT_MODE==NORMAL
	CLR_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
#elif Timer0_u8OUTPUT_MODE==TOGGLE
	SET_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
#elif Timer0_u8OUTPUT_MODE==CLEAR
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#elif Timer0_u8OUTPUT_MODE==SET
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#else
#error wrong Timer0_u8OUTPUT_MODE Configuration value
#endif

	/*Output Compare Value*/
	OCR0=TIMER0_u8COMPAREVALUE;

	/*Select Clock Type*/
	TCCR0 &= Prescaler_Mask;
	TCCR0 |= TIMER0_u8PRESCALER;

	/*Enable Interrupt*/
	SET_BIT(TIMSK,OCIE0);
	/*Make Waveform Generation Mode to be FAST_PWM*/
#elif TIMER0_u8OPERATION_MODE==FAST_PWM
	SET_BIT(TCCR0,WGN01);
	SET_BIT(TCCR0,WGN00);

#if Timer0_u8OUTPUT_MODE==NORMAL
	CLR_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
#elif Timer0_u8OUTPUT_MODE==CLEAR
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#elif Timer0_u8OUTPUT_MODE==SET
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#else
#error wrong Timer0_u8OUTPUT_MODE Configuration value
#endif

	/*Output Compare Value*/
	OCR0=TIMER0_u8COMPAREVALUE;

	/*Select Clock Type*/
	TCCR0 &= Prescaler_Mask;
	TCCR0 |= TIMER0_u8PRESCALER;

#else
#error wrong TIMER0_u8OPERATION_MODE Configuration value
#endif



}

uint8 TIMER0_u8SetCallBack(void(*copy_pvFunctionPtr)(void)){
	uint8 Local_u8Error_State=OK;
	if(copy_pvFunctionPtr!=NULL){
			TIMER_pvFunctionPtr[0]=copy_pvFunctionPtr;
		}

	else{
		Local_u8Error_State=NULL_PTR;
	}
	return Local_u8Error_State;
}


void TIMER0_voidSetCompVal(uint8 copy_u8CompVal){
	OCR0=copy_u8CompVal;
}


void TIMER1_voidTnit(void){

	/*Normal Mode*/
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);

	/*Select Clock Type*/
	TCCR1B &= 0b11111000;
	TCCR1B |= DIVISION_BY_64;

}

uint16 TIMER1_u16GetTimerVal(void){

	return TCNT1;
}

void TIMER1_SetTimerVal(uint16 copy_u16Val){

	TCNT1=copy_u16Val;
}


void TIMER2_voidTnit(void){
	/*Intiate Timer 2*/
	/*Make Waveform Generation Mode to be Normal*/
#if TIMER2_u8OPERATION_MODE==NORMAL
	CLR_BIT(TCCR2,WGN21);
	CLR_BIT(TCCR2,WGN20);

	/*Select Clock Type*/
	TCCR2 &= Prescaler_Mask;
	TCCR2 |= TIMER2_u8PRESCALER;

	/*Enable Interrupt*/
	SET_BIT(TIMSK,TOIE2);
	/*Make Waveform Generation Mode to be PWM_PHASE_CORRECTION*/
#elif TIMER2_u8OPERATION_MODE==PWM_PHASE_CORRECTION
	CLR_BIT(TCCR2,WGN21);
	SET_BIT(TCCR2,WGN20);

	/*Select Clock Type*/
	TCCR2 &= Prescaler_Mask;
	TCCR2 |= TIMER2_u8PRESCALER;

	/*Enable Interrupt*/
	SET_BIT(TIMSK,TOIE2);
	/*Make Waveform Generation Mode to be CTC*/
#elif TIMER2_u8OPERATION_MODE==CTC
	SET_BIT(TCCR2,WGN21);
	CLR_BIT(TCCR2,WGN20);
#if Timer2_u8CTC_OUTPUT_MODE==NORMAL
	CLR_BIT(TCCR2,COM20);
	CLR_BIT(TCCR2,COM21);
#elif Timer2_u8CTC_OUTPUT_MODE==TOGGLE
	SET_BIT(TCCR2,COM20);
	CLR_BIT(TCCR2,COM21);
#elif Timer2_u8CTC_OUTPUT_MODE==CLEAR
	CLR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
#elif Timer2_u8CTC_OUTPUT_MODE==SET
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
#else
#error wrong Timer2_u8CTC_OUTPUT_MODE Configuration value
#endif

	/*Output Compare Value*/
	OCR2=TIMER2_u8COMPAREVALUE;

	/*Select Clock Type*/
	TCCR2 &= Prescaler_Mask;
	TCCR2 |= TIMER2_u8PRESCALER;

	/*Enable Interrupt*/
	SET_BIT(TIMSK,OCIE2);
	/*Make Waveform Generation Mode to be FAST_PWM*/
#elif TIMER2_u8OPERATION_MODE==FAST_PWM
	SET_BIT(TCCR2,WGN21);
	SET_BIT(TCCR2,WGN20);
#else
#error wrong TIMER2_u8OPERATION_MODE Configuration value
#endif



}

uint8 TIMER2_u8SetCallBack(void(*copy_pvFunctionPtr)(void)){
	uint8 Local_u8Error_State=OK;
	if(copy_pvFunctionPtr!=NULL){
			TIMER_pvFunctionPtr[1]=copy_pvFunctionPtr;
		}

	else{
		Local_u8Error_State=NULL_PTR;
	}
	return Local_u8Error_State;
}




void __vector_5 (void) __attribute__((signal));
void __vector_5 (void){
	if(TIMER_pvFunctionPtr[1]!=NULL){
		TIMER_pvFunctionPtr[1]();
	}
	else{
		//Do nothing
	}
}

void __vector_4 (void) __attribute__((signal));
void __vector_4 (void){
	if(TIMER_pvFunctionPtr[1]!=NULL){
		TIMER_pvFunctionPtr[1]();
	}
	else{
		//Do nothing
	}
}




void __vector_11 (void) __attribute__((signal));
void __vector_11 (void){
	if(TIMER_pvFunctionPtr[0]!=NULL){
		TIMER_pvFunctionPtr[0]();
	}
	else{
		//Do nothing
	}
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void){
	if(TIMER_pvFunctionPtr[0]!=NULL){
		TIMER_pvFunctionPtr[0]();
	}
	else{
		//Do nothing
	}
}
