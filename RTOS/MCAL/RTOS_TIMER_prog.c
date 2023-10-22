#include "STD_TYPES.h"
#include "Err_Type.h"
#include "BIT_MATH.h"

#include "RTOS_TIMER_reg.h"
#include "RTOS_TIMER_interface.h"
#include "RTOS_TIMER_prv.h"
#include "RTOS_TIMER_cfg.h"

static void (*TIMER_pvFunctionPtr[8])(void)={NULL};


uint8 RTOS_TIMER1_u8Init(void(*copy_pvFunctionPtr)(void)){
uint8 Local_u8Error_State=OK;
	if(copy_pvFunctionPtr!=NULL){
			//set CTC_OCR1A
					CLR_BIT(TCCR1A,WGM10);
					CLR_BIT(TCCR1A,WGM11);
					SET_BIT(TCCR1B,WGM12);
					CLR_BIT(TCCR1B,WGM13);

			// SET MODE 0
					TCCR1A &= 0b00001111;
					TCCR1A |= 0U;

			//SET Prescaler 64
					TCCR1B &= Prescaler_Mask;
					TCCR1B |= 3U;
					
			//Set Interrupt
					SET_BIT(TIMSK,OCIE1A);
					TIMER_pvFunctionPtr[3]=copy_pvFunctionPtr;
	}
		else{
		Local_u8Error_State=NULL_PTR;
	}
	return Local_u8Error_State;

}





void RTOS_TIMER1_voidSetCompVal(uint8 copy_u8CompVal){
	
	OCR1A=copy_u8CompVal;
	
}


/*uint8 TIMER_voidIntEnable(TMR_INT_t copy_u8IntType,void(*copy_pvFunctionPtr)(void)){
	
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
}*/

/*uint8 TIMER_voidIntDisable(TMR_INT_t copy_u8IntType){
	
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
}*/



void __vector_7 (void)  __attribute__((signal));
void __vector_7 (void){
	if(TIMER_pvFunctionPtr[3]!=NULL){
		TIMER_pvFunctionPtr[3]();
	}
	else{
		//Do nothing
	}
}
