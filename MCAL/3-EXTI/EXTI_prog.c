#include "STD_TYPES.h"
#include "Err_Type.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_prv.h"
#include "EXTI_reg.h"
#include "EXTI_cfg.h"

static void (*EXTI_pfFuncPtr[3])(void)={NULL,NULL,NULL};



void EXTI_voidInit(void){
#if EXTI_u8INT0_TRIG==LOW_LEVEL
	CLR_BIT(EXTI_u8MCUCR,MCUCR_ISC01);
	CLR_BIT(EXTI_u8MCUCR,MCUCR_ISC00);
#elif EXTI_u8INT0_TRIG==ON_CHANGE
	CLR_BIT(EXTI_u8MCUCR,MCUCR_ISC01);
	SET_BIT(EXTI_u8MCUCR,MCUCR_ISC00);
#elif EXTI_u8INT0_TRIG==FALLING_EDGE
	SET_BIT(EXTI_u8MCUCR,MCUCR_ISC01);
	CLR_BIT(EXTI_u8MCUCR,MCUCR_ISC00);
#elif EXTI_u8INT0_TRIG==RISING_EDGE
	SET_BIT(EXTI_u8MCUCR,MCUCR_ISC01);
	SET_BIT(EXTI_u8MCUCR,MCUCR_ISC00);
#else
#error "Wrong EXTI_u8INT0_TRIG configuration option"
#endif


#if EXTI_u8INT1_TRIG==LOW_LEVEL
	CLR_BIT(EXTI_u8MCUCR,MCUCR_ISC11);
	CLR_BIT(EXTI_u8MCUCR,MCUCR_ISC10);
#elif EXTI_u8INT1_TRIG==ON_CHANGE
	CLR_BIT(EXTI_u8MCUCR,MCUCR_ISC11);
	SET_BIT(EXTI_u8MCUCR,MCUCR_ISC10);
#elif EXTI_u8INT1_TRIG==FALLING_EDGE
	SET_BIT(EXTI_u8MCUCR,MCUCR_ISC11);
	CLR_BIT(EXTI_u8MCUCR,MCUCR_ISC10);
#elif EXTI_u8INT1_TRIG==RISING_EDGE
	SET_BIT(EXTI_u8MCUCR,MCUCR_ISC11);
	SET_BIT(EXTI_u8MCUCR,MCUCR_ISC10);
#else
#error "Wrong EXTI_u8INT1_TRIG configuration option"
#endif


#if EXTI_u8INT2_TRIG==FALLING_EDGE
	CLR_BIT(EXTI_u8MCUCSR,MCUCSR_ISC2);
#elif EXTI_u8INT2_TRIG==RISING_EDGE
	SET_BIT(EXTI_u8MCUCSR,MCUCSR_ISC2);
#else
#error "Wrong EXTI_u8INT2_TRIG configuration option"
#endif

#if EXTI_u8INT0_INIT_STATE==ENABLED
	SET_BIT(EXTI_u8GICR,GICR_INIT0);
#elif EXTI_u8INT0_INIT_STATE==DISABLED
	CLR_BIT(EXTI_u8GICR,GICR_INIT0);
#else
#error "Wrong EXTI_u8INT0_INIT_STATE configuration option"
#endif

#if EXTI_u8INT1_INIT_STATE==ENABLED
	SET_BIT(EXTI_u8GICR,GICR_INIT1);
#elif EXTI_u8INT1_INIT_STATE==DISABLED
	CLR_BIT(EXTI_u8GICR,GICR_INIT1);
#else
#error "Wrong EXTI_u8INT0_INIT_STATE configuration option"
#endif

#if EXTI_u8INT2_INIT_STATE==ENABLED
	SET_BIT(EXTI_u8GICR,GICR_INIT2);
#elif EXTI_u8INT2_INIT_STATE==DISABLED
	CLR_BIT(EXTI_u8GICR,GICR_INIT2);
#else
#error "Wrong EXTI_u8INT0_INIT_STATE configuration option"
#endif
}

uint8 EXTI_u8SetSenseCtrl(EXTI_IntNum_t copy_IntNum, uint8 copy_SenseCtrl){
	uint8 Local_u8ErrorState = OK;

	if(copy_IntNum==INT0){
		switch(copy_SenseCtrl){
		case LOW_LEVEL:
			CLR_BIT(EXTI_u8MCUCR,MCUCR_ISC01);
			CLR_BIT(EXTI_u8MCUCR,MCUCR_ISC00);
			break;
		case ON_CHANGE:
			CLR_BIT(EXTI_u8MCUCR,MCUCR_ISC01);
			SET_BIT(EXTI_u8MCUCR,MCUCR_ISC00);
			break;
		case FALLING_EDGE:
			SET_BIT(EXTI_u8MCUCR,MCUCR_ISC01);
			CLR_BIT(EXTI_u8MCUCR,MCUCR_ISC00);
			break;
		case RISING_EDGE:
			SET_BIT(EXTI_u8MCUCR,MCUCR_ISC01);
			SET_BIT(EXTI_u8MCUCR,MCUCR_ISC00);
			break;
		default :
			Local_u8ErrorState = NOK;
			break;
		}

	}
	else if (copy_IntNum==INT1){
		switch(copy_SenseCtrl){
		case LOW_LEVEL:
			CLR_BIT(EXTI_u8MCUCR,MCUCR_ISC11);
			CLR_BIT(EXTI_u8MCUCR,MCUCR_ISC10);
			break;
		case ON_CHANGE:
			CLR_BIT(EXTI_u8MCUCR,MCUCR_ISC11);
			SET_BIT(EXTI_u8MCUCR,MCUCR_ISC10);
			break;
		case FALLING_EDGE:
			SET_BIT(EXTI_u8MCUCR,MCUCR_ISC11);
			CLR_BIT(EXTI_u8MCUCR,MCUCR_ISC10);
			break;
		case RISING_EDGE:
			SET_BIT(EXTI_u8MCUCR,MCUCR_ISC11);
			SET_BIT(EXTI_u8MCUCR,MCUCR_ISC10);
			break;
		default :
			Local_u8ErrorState = NOK;
			break;
		}
	}
	else if (copy_IntNum==INT2){
		switch(copy_SenseCtrl){
		case FALLING_EDGE:
			CLR_BIT(EXTI_u8MCUCSR,MCUCSR_ISC2);
			break;
		case RISING_EDGE:
			SET_BIT(EXTI_u8MCUCSR,MCUCSR_ISC2);
			break;
		default :
			Local_u8ErrorState = NOK;
			break;
		}
	}

	return Local_u8ErrorState;
}

uint8 EXTI_u8IntEnable(EXTI_IntNum_t copy_IntNum){
	uint8 Local_u8ErrorState = OK;

	switch(copy_IntNum){
	case INT0:
		SET_BIT(EXTI_u8GICR,GICR_INIT0);
		break;
	case INT1:
		SET_BIT(EXTI_u8GICR,GICR_INIT1);
		break;
	case INT2:
		SET_BIT(EXTI_u8GICR,GICR_INIT2);
		break;
	default:
		Local_u8ErrorState=NOK;
		break;
	}

	return Local_u8ErrorState;
}

uint8 EXTI_u8IntDisable(EXTI_IntNum_t copy_IntNum){
	uint8 Local_u8ErrorState = OK;

	switch(copy_IntNum){
	case INT0:
		CLR_BIT(EXTI_u8GICR,GICR_INIT0);
		break;
	case INT1:
		CLR_BIT(EXTI_u8GICR,GICR_INIT1);
		break;
	case INT2:
		CLR_BIT(EXTI_u8GICR,GICR_INIT2);
		break;
	default:
		Local_u8ErrorState=NOK;
		break;
	}


	return Local_u8ErrorState;
}

uint8 EXTI_u8SetCallBack(EXTI_IntNum_t copy_IntNum,void(*copy_pfFuncPtr)(void)){
	uint8 Local_u8ErrorState = OK;
	if(copy_pfFuncPtr!=NULL){
		if ((copy_IntNum >=INT0) && (copy_IntNum <=INT2)){
			EXTI_pfFuncPtr[copy_IntNum]=copy_pfFuncPtr;
		}
		else{
			Local_u8ErrorState = NOK;
		}
	}
	else{
		Local_u8ErrorState=NULL_PTR;
	}
	return Local_u8ErrorState;
}
//INT0 ISR
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void){
	if(EXTI_pfFuncPtr[INT0]!=NULL){
		EXTI_pfFuncPtr[INT0]();
	}
	else{
		//Do nothing
	}

}
//INT1 ISR
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void){
	if(EXTI_pfFuncPtr[INT1]!=NULL){
		EXTI_pfFuncPtr[INT1]();
	}
	else{
		//Do nothing
	}
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void){
	if(EXTI_pfFuncPtr[INT2]!=NULL){
		EXTI_pfFuncPtr[INT2]();
	}
	else{
		//Do nothing
	}
}
