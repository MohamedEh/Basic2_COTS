#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include <util/delay.h>

#include "PWM_interface.h"
#include "TIMER_interface.h"
#include "ICU_interface.h"
#include "DIO_interface.h"

void schedule_Func(void);

void (*PWM_FuncPtr)(void)=NULL;

void PWM_voidSet(uint8 copy_u8PeriodTime,uint8 copy_u8OnTime){

	TMR1_CFG_t CFG={.WFG_MODE=FAST_PWM_ICR1,.OC_MODE=OPTION2,.PRESCALER=CLCK_8};

	TIMER1_TOP_VALUE = (uint16)((uint32)copy_u8PeriodTime*1000UL)*(16/8);		//period time(us)/prescaler/system frequency(MHZ)

	TIMER1A_CMP_REG = (uint16)((uint32)copy_u8OnTime*1000UL)*(16/8);			//On time(us)/prescaler/system frequency(MHZ)

	TIMER1_u8Init(&CFG);
}

uint8 PWM_u8Get(uint32* copy_pu8PeriodTime,uint32* copy_pu8OnTime){

	uint8 Local_u8Error_State=OK;
	if((copy_pu8PeriodTime!=NULL)&&(copy_pu8OnTime!=NULL)){

		ICU_CFG_t CFG={.SenseCtrl=Rising,.Int_State=Enabled};

		ICU_u8Init(&CFG);

		ICU_u8Get(copy_pu8PeriodTime,copy_pu8OnTime);
	}
	else{
		Local_u8Error_State=NULL_PTR;
	}
	return Local_u8Error_State;
}

uint8 Schedule_us(uint32 copy_u32Timer_us,uint8 copy_u8PeriodType,void (* copy_pvFuncPtr)(void)){
	uint8 Local_u8Error_State=OK;
	if(copy_pvFuncPtr!=NULL){
		PWM_FuncPtr=copy_pvFuncPtr;
		TMR1_CFG_t CFG={.WFG_MODE=CTC_ICR1,.OC_MODE=OPTION0,.PRESCALER=CLCK_64};
		TIMER1_voidSetTopVal((uint16)((copy_u32Timer_us*16UL)/64UL));
		TIMER_voidIntEnable(TMR1_ICU_INT,copy_pvFuncPtr);
		TIMER1_u8Init(&CFG);
		if(copy_u8PeriodType==Once){

			TIMER1_u8SetCallBack(schedule_Func);

		}

	}
	else{
		Local_u8Error_State=NULL_PTR;
	}
	return Local_u8Error_State;
}

void schedule_Func(void){
	PWM_FuncPtr();
	TIMER_voidIntDisable(TMR1_ICU_INT);

}
