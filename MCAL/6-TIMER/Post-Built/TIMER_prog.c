#include "STD_TYPES.h"
#include "Err_Type.h"
#include "BIT_MATH.h"

#include "TIMER_reg.h"
#include "TIMER_interface.h"
#include "TIMER_prv.h"
#include "TIMER_cfg.h"

static void (*TIMER_pvFunctionPtr[8])(void)={NULL};

uint8 TIMER0_u8Init(TMR0_2_CFG_t* copy_psCFG){
	uint8 Local_u8Error_State = OK;
	
	if(copy_psCFG!=NULL){
		switch(copy_psCFG->WFG_MODE){
			case NORMAL:
					CLR_BIT(TCCR0,WGN01);
					CLR_BIT(TCCR0,WGN00);
					break;
			case CTC:
					SET_BIT(TCCR0,WGN01);
					CLR_BIT(TCCR0,WGN00);
					break;
			case FAST_PWM:
					SET_BIT(TCCR0,WGN01);
					SET_BIT(TCCR0,WGN00);
					break;
			case PH_CORR:
					CLR_BIT(TCCR0,WGN01);
					SET_BIT(TCCR0,WGN00);
					break;
			default:
					Local_u8Error_State=NOK;
					break;
		}
		switch(copy_psCFG->OC_MODE){
			case OPTION0:
					CLR_BIT(TCCR0,COM00);
					CLR_BIT(TCCR0,COM01);
					break;
			case OPTION1:
					SET_BIT(TCCR0,COM00);
					CLR_BIT(TCCR0,COM01);
					break;
			case OPTION2:
					CLR_BIT(TCCR0,COM00);
					SET_BIT(TCCR0,COM01);
					break;
			case OPTION3:
					SET_BIT(TCCR0,COM00);
					SET_BIT(TCCR0,COM01);
					break;
			default:
					Local_u8Error_State=NOK;
					break;
		}
		
		switch(copy_psCFG->PRESCALER){
			case NO_CLCK:
					TCCR0 &= Prescaler_Mask;
					TCCR0 |= 0U;
					break;
			case CLCK_1:
					TCCR0 &= Prescaler_Mask;
					TCCR0 |= 1U;
					break;
			case CLCK_8:
					TCCR0 &= Prescaler_Mask;
					TCCR0 |= 2U;
					break;
			case CLCK_64:
					TCCR0 &= Prescaler_Mask;
					TCCR0 |= 3U;
					break;
			case CLCK_256:
					TCCR0 &= Prescaler_Mask;
					TCCR0 |= 4U;
					break;
			case CLCK_1024:
					TCCR0 &= Prescaler_Mask;
					TCCR0 |= 5U;
					break;
			case EXT_FALLING:
					TCCR0 &= Prescaler_Mask;
					TCCR0 |= 6U;
					break;
			case EXT_RISING:
					TCCR0 &= Prescaler_Mask;
					TCCR0 |= 7U;
					break;
			default:
					Local_u8Error_State=NOK;
					break;
		}
	}
	else{
		Local_u8Error_State = NULL_PTR;
	}
	
	return Local_u8Error_State;
	
}

uint8 TIMER0_u8SetCompOpMode(TMR_OCMODE_t copy_u8CompOpMode){
	
	uint8 Local_u8Error_State=OK;
	
	switch(copy_u8CompOpMode){
		
			case OPTION0:
					CLR_BIT(TCCR0,COM00);
					CLR_BIT(TCCR0,COM01);
					break;
			case OPTION1:
					SET_BIT(TCCR0,COM00);
					CLR_BIT(TCCR0,COM01);
					break;
			case OPTION2:
					CLR_BIT(TCCR0,COM00);
					SET_BIT(TCCR0,COM01);
					break;
			case OPTION3:
					SET_BIT(TCCR0,COM00);
					SET_BIT(TCCR0,COM01);
					break;
			default:
					Local_u8Error_State=NOK;
					break; 
	}
	
	return Local_u8Error_State;
}

uint8 TIMER0_u8SetCallBack(void(*copy_pvFunctionPtr)(void)){
	
	uint8 Local_u8Error_State=OK;
	if(copy_pvFunctionPtr!=NULL){
			TIMER_pvFunctionPtr[0]=copy_pvFunctionPtr;
			TIMER_pvFunctionPtr[1]=copy_pvFunctionPtr;
		}

	else{
		Local_u8Error_State=NULL_PTR;
	}
	return Local_u8Error_State;
}

void TIMER0_voidSetCompVal(uint8 copy_u8CompVal){
	
	OCR0=copy_u8CompVal;
}

uint8 TIMER0_u8GetTimerVal(void){
	
	return TCNT0;
}

void TIMER0_voidSetTimerVal(uint8 copy_u8Val){
	
	TCNT0=copy_u8Val;
}

uint8 TIMER1_u8Init(TMR1_CFG_t* copy_psCFG){
	uint8 Local_u8Error_State = OK;
	
	if(copy_psCFG!=NULL){
		switch(copy_psCFG->WFG_MODE){
			case NORM:
					CLR_BIT(TCCR1A,WGM10);
					CLR_BIT(TCCR1A,WGM11);
					CLR_BIT(TCCR1B,WGM12);
					CLR_BIT(TCCR1B,WGM13);
					break;
			case PH_CORR_8_BIT:
					SET_BIT(TCCR1A,WGM10);
					CLR_BIT(TCCR1A,WGM11);
					CLR_BIT(TCCR1B,WGM12);
					CLR_BIT(TCCR1B,WGM13);
					break;
			case PH_CORR_9_BIT:
					CLR_BIT(TCCR1A,WGM10);
					SET_BIT(TCCR1A,WGM11);
					CLR_BIT(TCCR1B,WGM12);
					CLR_BIT(TCCR1B,WGM13);
					break;
			case PH_CORR_10_BIT:
					SET_BIT(TCCR1A,WGM10);
					SET_BIT(TCCR1A,WGM11);
					CLR_BIT(TCCR1B,WGM12);
					CLR_BIT(TCCR1B,WGM13);
					break;
			case CTC_OCR1A:
					CLR_BIT(TCCR1A,WGM10);
					CLR_BIT(TCCR1A,WGM11);
					SET_BIT(TCCR1B,WGM12);
					CLR_BIT(TCCR1B,WGM13);
					break;
			case FAST_PWM_8_BIT:
					SET_BIT(TCCR1A,WGM10);
					CLR_BIT(TCCR1A,WGM11);
					SET_BIT(TCCR1B,WGM12);
					CLR_BIT(TCCR1B,WGM13);
					break;
			case FAST_PWM_9_BIT:
					CLR_BIT(TCCR1A,WGM10);
					SET_BIT(TCCR1A,WGM11);
					SET_BIT(TCCR1B,WGM12);
					CLR_BIT(TCCR1B,WGM13);
					break;
			case FAST_PWM_10_BIT:
					SET_BIT(TCCR1A,WGM10);
					SET_BIT(TCCR1A,WGM11);
					SET_BIT(TCCR1B,WGM12);
					CLR_BIT(TCCR1B,WGM13);
					break;
			case PH_FREQ_CORR_ICR1:
					CLR_BIT(TCCR1A,WGM10);
					CLR_BIT(TCCR1A,WGM11);
					CLR_BIT(TCCR1B,WGM12);
					SET_BIT(TCCR1B,WGM13);
					break;
			case PH_FREQ_CORR_OCR1A:
					SET_BIT(TCCR1A,WGM10);
					CLR_BIT(TCCR1A,WGM11);
					CLR_BIT(TCCR1B,WGM12);
					SET_BIT(TCCR1B,WGM13);
					break;
			case PH_CORR_ICR1:
					CLR_BIT(TCCR1A,WGM10);
					SET_BIT(TCCR1A,WGM11);
					CLR_BIT(TCCR1B,WGM12);
					SET_BIT(TCCR1B,WGM13);
					break;
			case PH_CORR_OCR1A:
					SET_BIT(TCCR1A,WGM10);
					SET_BIT(TCCR1A,WGM11);
					CLR_BIT(TCCR1B,WGM12);
					SET_BIT(TCCR1B,WGM13);
					break;
			case CTC_ICR1:
					CLR_BIT(TCCR1A,WGM10);
					CLR_BIT(TCCR1A,WGM11);
					SET_BIT(TCCR1B,WGM12);
					SET_BIT(TCCR1B,WGM13);
					break;
			case FAST_PWM_ICR1:
					CLR_BIT(TCCR1A,WGM10);
					SET_BIT(TCCR1A,WGM11);
					SET_BIT(TCCR1B,WGM12);
					SET_BIT(TCCR1B,WGM13);
					break;
			case FAST_PWM_OCR1A:
					SET_BIT(TCCR1A,WGM10);
					SET_BIT(TCCR1A,WGM11);
					SET_BIT(TCCR1B,WGM12);
					SET_BIT(TCCR1B,WGM13);
					break;
			default:
					Local_u8Error_State=NOK;
					break;
		}
		switch(copy_psCFG->OC_MODE){
			case OPTION0:
					TCCR1A &= 0b00001111;
					TCCR1A |= 0U;
					break;
			case OPTION1:
					TCCR1A &= 0b00001111;
					TCCR1A |= 80U;
					break;
			case OPTION2:
					TCCR1A &= 0b00001111;
					TCCR1A |= 160U;
					break;
			case OPTION3:
					TCCR1A &= 0b00001111;
					TCCR1A |= 240U;
					break;
			default:
					Local_u8Error_State=NOK;
					break;
		}
		
		switch(copy_psCFG->PRESCALER){
			case NO_CLCK:
					TCCR1B &= Prescaler_Mask;
					TCCR1B |= 0U;
					break;
			case CLCK_1:
					TCCR1B &= Prescaler_Mask;
					TCCR1B |= 1U;
					break;
			case CLCK_8:
					TCCR1B &= Prescaler_Mask;
					TCCR1B |= 2U;
					break;
			case CLCK_64:
					TCCR1B &= Prescaler_Mask;
					TCCR1B |= 3U;
					break;
			case CLCK_256:
					TCCR1B &= Prescaler_Mask;
					TCCR1B |= 4U;
					break;
			case CLCK_1024:
					TCCR1B &= Prescaler_Mask;
					TCCR1B |= 5U;
					break;
			case EXT_FALLING:
					TCCR1B &= Prescaler_Mask;
					TCCR1B |= 6U;
					break;
			case EXT_RISING:
					TCCR1B &= Prescaler_Mask;
					TCCR1B |= 7U;
					break;
			default:
					Local_u8Error_State=NOK;
					break;
		}
	}
	else{
		Local_u8Error_State = NULL_PTR;
	}
	return Local_u8Error_State;
}

uint8 TIMER1_u8SetCompOpMode(TMR_OCMODE_t copy_u8CompOpMode){
	
	uint8 Local_u8Error_State=OK;
	
	switch(copy_u8CompOpMode){
			case OPTION0:
					TCCR1A &= 0b00001111;
					TCCR1A |= 0U;
					break;
			case OPTION1:
					TCCR1A &= 0b00001111;
					TCCR1A |= 80U;
					break;
			case OPTION2:
					TCCR1A &= 0b00001111;
					TCCR1A |= 160U;
					break;
			case OPTION3:
					TCCR1A &= 0b00001111;
					TCCR1A |= 240U;
					break;
			default:
					Local_u8Error_State=NOK;
					break;

	}
	
	return Local_u8Error_State;
}

uint8 TIMER1_u8SetCallBack(void(*copy_pvFunctionPtr)(void)){
	
	uint8 Local_u8Error_State=OK;
	if(copy_pvFunctionPtr!=NULL){
			TIMER_pvFunctionPtr[2]=copy_pvFunctionPtr;
			TIMER_pvFunctionPtr[3]=copy_pvFunctionPtr;
			TIMER_pvFunctionPtr[4]=copy_pvFunctionPtr;
			TIMER_pvFunctionPtr[5]=copy_pvFunctionPtr;

	}

	else{
		Local_u8Error_State=NULL_PTR;
	}
	return Local_u8Error_State;
	
}

void TIMER1_voidSetCompVal(uint8 copy_u8CompVal){
	
	OCR1A=copy_u8CompVal;
	OCR1B=copy_u8CompVal;
}

uint16 TIMER1_u16GetTimerVal(void){
	
		return TCNT1;
}

void TIMER1_voidSetTimerVal(uint16 copy_u16Val){
	
	TCNT1=copy_u16Val;
}

void TIMER1_voidSetTopVal(uint16 copy_u16Val){

	ICR1=copy_u16Val;
}

uint8 TIMER2_u8Init(TMR0_2_CFG_t* copy_psCFG){
	uint8 Local_u8Error_State = OK;
	
	if(copy_psCFG!=NULL){
		switch(copy_psCFG->WFG_MODE){
			case NORMAL:
					CLR_BIT(TCCR2,WGN21);
					CLR_BIT(TCCR2,WGN20);
					break;
			case CTC:
					SET_BIT(TCCR2,WGN21);
					CLR_BIT(TCCR2,WGN20);
					break;
			case FAST_PWM:
					SET_BIT(TCCR2,WGN21);
					SET_BIT(TCCR2,WGN20);
					break;
			case PH_CORR:
					CLR_BIT(TCCR2,WGN21);
					SET_BIT(TCCR2,WGN20);
					break;
			default:
					Local_u8Error_State=NOK;
					break;
		}
		switch(copy_psCFG->OC_MODE){
			case OPTION0:
					CLR_BIT(TCCR2,COM20);
					CLR_BIT(TCCR2,COM21);
					break;
			case OPTION1:
					SET_BIT(TCCR2,COM20);
					CLR_BIT(TCCR2,COM21);
					break;
			case OPTION2:
					CLR_BIT(TCCR2,COM20);
					SET_BIT(TCCR2,COM21);
					break;
			case OPTION3:
					SET_BIT(TCCR2,COM20);
					SET_BIT(TCCR2,COM21);
					break;
			default:
					Local_u8Error_State=NOK;
					break;
		}
		
		switch(copy_psCFG->PRESCALER){
			case NO_CLCK:
					TCCR2 &= Prescaler_Mask;
					TCCR2 |= 0U;
					break;
			case CLCK_1:
					TCCR2 &= Prescaler_Mask;
					TCCR2 |= 1U;
					break;
			case CLCK_8:
					TCCR2 &= Prescaler_Mask;
					TCCR2 |= 2U;
					break;
			case CLCK_64:
					TCCR2 &= Prescaler_Mask;
					TCCR2 |= 3U;
					break;
			case CLCK_256:
					TCCR2 &= Prescaler_Mask;
					TCCR2 |= 4U;
					break;
			case CLCK_1024:
					TCCR2 &= Prescaler_Mask;
					TCCR2 |= 5U;
					break;
			case EXT_FALLING:
					TCCR2 &= Prescaler_Mask;
					TCCR2 |= 6U;
					break;
			case EXT_RISING:
					TCCR2 &= Prescaler_Mask;
					TCCR2 |= 7U;
					break;
			default:
					Local_u8Error_State=NOK;
					break;
		}
	}
	else{
		Local_u8Error_State = NULL_PTR;
	}
}

uint8 TIMER2_u8SetCompOpMode(TMR_OCMODE_t copy_u8CompOpMode){
	
	uint8 Local_u8Error_State=OK;
	
	switch(copy_u8CompOpMode){
		
			case OPTION0:
					CLR_BIT(TCCR2,COM20);
					CLR_BIT(TCCR2,COM21);
					break;
			case OPTION1:
					SET_BIT(TCCR2,COM20);
					CLR_BIT(TCCR2,COM21);
					break;
			case OPTION2:
					CLR_BIT(TCCR2,COM20);
					SET_BIT(TCCR2,COM21);
					break;
			case OPTION3:
					SET_BIT(TCCR2,COM20);
					SET_BIT(TCCR2,COM21);
					break;
			default:
					Local_u8Error_State=NOK;
					break; 
	}
	
	return Local_u8Error_State;
}

uint8 TIMER2_u8SetCallBack(void(*copy_pvFunctionPtr)(void)){
	
	uint8 Local_u8Error_State=OK;
	if(copy_pvFunctionPtr!=NULL){
			TIMER_pvFunctionPtr[6]=copy_pvFunctionPtr;
			TIMER_pvFunctionPtr[7]=copy_pvFunctionPtr;

		}

	else{
		Local_u8Error_State=NULL_PTR;
	}
	return Local_u8Error_State;
}

void TIMER2_voidSetCompVal(uint8 copy_u8CompVal){
	
	OCR2=copy_u8CompVal;
}

uint8 TIMER2_u8GetTimerVal(void){
	
		return TCNT2;
}

void TIMER2_voidSetTimerVal(uint8 copy_u8Val){
	
	TCNT2=copy_u8Val;
}

uint8 TIMER_voidIntEnable(TMR_INT_t copy_u8IntType,void(*copy_pvFunctionPtr)(void)){
	
	uint8 Local_u8Error_State=OK;
	
	switch(copy_u8IntType){
		case TMR0_OC_INT:
			SET_BIT(TIMSK,OCIE0);
			TIMER_pvFunctionPtr[0]=copy_pvFunctionPtr;
			break;
		case TMR0_OVF_INT:
			SET_BIT(TIMSK,TOIE0);
			TIMER_pvFunctionPtr[1]=copy_pvFunctionPtr;
			break;
		case TMR1_ICU_INT:
			SET_BIT(TIMSK,TICIE1);
			TIMER_pvFunctionPtr[2]=copy_pvFunctionPtr;
			break;
		case TMR1_OC_A_INT:
			SET_BIT(TIMSK,OCIE1A);
			TIMER_pvFunctionPtr[3]=copy_pvFunctionPtr;
			break;
		case TMR1_OC_B_INT:
			SET_BIT(TIMSK,OCIE1B);
			TIMER_pvFunctionPtr[4]=copy_pvFunctionPtr;
			break;
		case TMR1_OVF_INT:
			SET_BIT(TIMSK,TOIE1);
			TIMER_pvFunctionPtr[5]=copy_pvFunctionPtr;
			break;
		case TMR2_OC_INT:
			SET_BIT(TIMSK,OCIE2);
			TIMER_pvFunctionPtr[6]=copy_pvFunctionPtr;
			break;
		case TMR2_OVF_INT:
			SET_BIT(TIMSK,TOIE2);
			TIMER_pvFunctionPtr[7]=copy_pvFunctionPtr;
			break;
		default:
			Local_u8Error_State=NOK;
			break;
	}
	
	return Local_u8Error_State;
}

uint8 TIMER_voidIntDisable(TMR_INT_t copy_u8IntType){
	
	uint8 Local_u8Error_State=OK;
	
	switch(copy_u8IntType){
		case TMR0_OC_INT:
			CLR_BIT(TIMSK,OCIE0);
			break;
		case TMR0_OVF_INT:
			CLR_BIT(TIMSK,TOIE0);
			break;
		case TMR1_ICU_INT:
			CLR_BIT(TIMSK,TICIE1);
			break;
		case TMR1_OC_A_INT:
			CLR_BIT(TIMSK,OCIE1A);
			break;
		case TMR1_OC_B_INT:
			CLR_BIT(TIMSK,OCIE1B);
			break;
		case TMR1_OVF_INT:
			CLR_BIT(TIMSK,TOIE1);
			break;
		case TMR2_OC_INT:
			CLR_BIT(TIMSK,OCIE2);
			break;
		case TMR2_OVF_INT:
			CLR_BIT(TIMSK,TOIE2);
			break;
		default:
			Local_u8Error_State=NOK;
			break;
	}
	
	return Local_u8Error_State;
}

void __vector_11 (void)  __attribute__((signal));
void __vector_11 (void){
	if(TIMER_pvFunctionPtr[1]!=NULL){
		TIMER_pvFunctionPtr[1]();
	}
	else{
		//Do nothing
	}	
}

void __vector_10 (void)  __attribute__((signal));
void __vector_10 (void){
	if(TIMER_pvFunctionPtr[0]!=NULL){
		TIMER_pvFunctionPtr[0]();
	}
	else{
		//Do nothing
	}	
}

void __vector_9 (void)  __attribute__((signal));
void __vector_9 (void){
	if(TIMER_pvFunctionPtr[5]!=NULL){
		TIMER_pvFunctionPtr[5]();
	}
	else {
		//Do nothing
	}
}

void __vector_8 (void)  __attribute__((signal));
void __vector_8 (void){
	if(TIMER_pvFunctionPtr[4]!=NULL){
		TIMER_pvFunctionPtr[4]();
	}
	else{
		//Do nothing
	}
}

void __vector_7 (void)  __attribute__((signal));
void __vector_7 (void){
	if(TIMER_pvFunctionPtr[3]!=NULL){
		TIMER_pvFunctionPtr[3]();
	}
	else{
		//Do nothing
	}
}

void __vector_6 (void)  __attribute__((signal));
void __vector_6 (void){
	if(TIMER_pvFunctionPtr[2]!=NULL){
		TIMER_pvFunctionPtr[2]();
	}
	else{
		//Do nothing
	}
}

void __vector_5 (void)  __attribute__((signal));
void __vector_5 (void){
	if(TIMER_pvFunctionPtr[7]!=NULL){
		TIMER_pvFunctionPtr[7]();
	}
	else{
		//Do nothing
	}
}

void __vector_4 (void)  __attribute__((signal));
void __vector_4 (void){
	if(TIMER_pvFunctionPtr[6]!=NULL){
		TIMER_pvFunctionPtr[6]();
	}
	else{
		//Do nothing
	}
}
