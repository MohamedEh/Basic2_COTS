#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"

#include "TIMER_interface.h"
#include "ICU_interface.h"

static volatile uint32 Record[3]={0};
static volatile uint32* Period_Time;
static volatile uint32* On_Time;
static volatile uint32 OVF_Counter=0;
static volatile uint8 counter=0;

void vector6 (void);
void vector9 (void);

uint8 ICU_u8Init(ICU_CFG_t* copy_pConfig){
	uint8 Local_u8Error_State=OK;
	if(copy_pConfig!=NULL){
		//Configuration of Timer 1
		TMR1_CFG_t CFG={.WFG_MODE=NORM,.OC_MODE=OPTION0,.PRESCALER=CLCK_8};
		//Select Sense Control
		switch (copy_pConfig->SenseCtrl){
		case Falling:
			CLR_BIT(TCCR1B,ICES1);
			break;
		case Rising:
			SET_BIT(TCCR1B,ICES1);
			break;
		default:
			Local_u8Error_State=NOK;
			break;
		}
		//Select Interrupt State
		switch (copy_pConfig->Int_State){
		case Enabled:
			SET_BIT(TIMSK,TICIE1);
			break;
		case Disabled:
			CLR_BIT(TIMSK,TICIE1);
			break;
		default:
			Local_u8Error_State=NOK;
			break;
		}
		//start Timer 1
		TIMER1_u8Init(&CFG);

	}
	else{
		Local_u8Error_State=NULL_PTR;
	}
	return Local_u8Error_State;

}
uint8 ICU_u8SenseControl(Sense_Ctrl_t copy_u8SenseCtrl){

	uint8 Local_u8Error_State = OK;
	//Select Sense Control
	switch (copy_u8SenseCtrl){
	case Falling:
		CLR_BIT(TCCR1B,ICES1);
		break;
	case Rising:
		SET_BIT(TCCR1B,ICES1);
		break;
	default:
		Local_u8Error_State=NOK;
		break;
	}
	return Local_u8Error_State;
}

void ICU_voidEnableInt(){

	SET_BIT(TIMSK,TICIE1);

}
void ICU_voidDisableInt(){

	CLR_BIT(TIMSK,TICIE1);


}

uint8 ICU_u8Get(uint32* copy_u8PeriodTime,uint32* copy_u8OnTime){

	uint8 Local_u8Error_State=OK;

	if((copy_u8PeriodTime!=NULL)&&(copy_u8OnTime!=NULL)){

		Period_Time=copy_u8PeriodTime;

		On_Time=copy_u8OnTime;

		SET_BIT(TCCR1B,ICNC1);					//Noise Canceler

		TIMER1_u8SetCallBack(&vector6);			//ICU Function

		TIMER_voidIntEnable(TMR1_OVF_INT,&vector9);


	}
	else{
		Local_u8Error_State=NULL_PTR;
	}

	return Local_u8Error_State;
}


void vector6 (void){

	counter++;
	if(counter==1){
		Record[0]=ICR1+(OVF_Counter*65536UL);
	}
	else if(counter==2){
		Record[1]=ICR1+(OVF_Counter*65536UL);
		*Period_Time=(((Record[1]-Record[0])/2UL));	//multiply by 2 for clock= prescaler/system freq.
		CLR_BIT(TCCR1B,ICES1);
	}
	else if(counter==3){
		Record[2]=ICR1+(OVF_Counter*65536UL);
		*On_Time=(((Record[2]-Record[1])/2UL));		//multiply by 2 for clock= prescaler/system freq.
	}
	else{
		counter=4;
	}

}

void vector9 (void){

	OVF_Counter++;
}
