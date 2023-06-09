#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"


#include "ADC_interface.h"
#include "ADC_cfg.h"
#include "ADC_prv.h"
#include "ADC_reg.h"

static uint16* ADC_pu16DigResult = NULL;
static void (*ADC_pvNotificationFunc)(void) = NULL;

static uint8 ADC_u8BusyFlag = IDLE ;

void ADC_voidInit(void){

	/*Reference Selection AVCC pin*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

	/*Activate Left Adjust Result or 8-Bit Resolution*/
#if ADC_u8RESOLUTION == EIGHT_BITS
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif ADC_u8RESOLUTION ==TEN_BITS
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error wrong ADC_u8RESOLUTION Configuration value
#endif

	/*Check on Prescaler Config. Setting*/
	ADCSRA &= PRESCALER_MASK; 	// Clear Prescaler Bits

	ADCSRA |= ADC_u8PRESCALER;

	/*ADC Enable*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

uint8 ADC_u8StartConversionSynch(ADC_Channel_t copy_u8Channel,uint16* copy_pu16DigResult){

	uint8 Local_u8ErrorState=OK;

	if(copy_pu16DigResult!=NULL){
		if(ADC_u8BusyFlag==IDLE){

			uint32 Local_u32Counter=0;

			/*ADC is now busy*/
			ADC_u8BusyFlag=BUSY;

			/*Set The Req. Channel*/
			ADMUX &= CHANNEL_SELECTION_MASK; /*Clear The Channel Selection Bits*/
			ADMUX |= copy_u8Channel;

			/*Start Conversion*/
			SET_BIT(ADCSRA, ADCSRA_ADSC);

			/*Wait (with blocking) till conversion is Completed or the timeout hasn't passed yet*/
			while(((GET_BIT(ADCSRA, ADCSRA_ADIF))==0)&&(Local_u32Counter<ADC_u32TIMEOUT_COUNT)){
				Local_u32Counter++;
			}
			/*Check whether Conversion is done or Timeout happened*/
			if(Local_u32Counter==ADC_u32TIMEOUT_COUNT){
				Local_u8ErrorState = TIMEOUT_ERR; 	//Loop is broken as timeout happened
			}
			else{									//Loop is broken as conversion is done
				/*Clear Conversion Flag(only it is auto cleared while interrupt is enabled)*/
				SET_BIT(ADCSRA, ADCSRA_ADIF);

				/*Returning the Value*/
#if ADC_u8RESOLUTION == EIGHT_BITS
				*copy_pu16DigResult=(uint16)ADCH;
#elif ADC_u8RESOLUTION ==TEN_BITS
				*copy_pu16DigResult=ADC;
#endif
				/*ADC is now IDLE*/
				ADC_u8BusyFlag=IDLE;
			}
		}
		else{
			Local_u8ErrorState = BUSY_ERR;
		}


	}
	else{
		Local_u8ErrorState=NULL_PTR;
	}

	return Local_u8ErrorState;
}

uint8 ADC_u8StartConversionAsynch(ADC_Channel_t copy_u8Channel,uint16* copy_pu16DigResult,void (*copy_pvNotificationFunc)(void)){
	uint8 Local_u8ErrorState=OK;



	if((copy_pu16DigResult!=NULL)&&(copy_pvNotificationFunc!=NULL)){
		if(ADC_u8BusyFlag==IDLE){

			/*ADC is now busy*/
			ADC_u8BusyFlag=BUSY;


			/*convert digital result and notification func to global variables*/
			ADC_pu16DigResult = copy_pu16DigResult;

			ADC_pvNotificationFunc = copy_pvNotificationFunc;

			/*Set The Req. Channel*/
			ADMUX &= CHANNEL_SELECTION_MASK; /*Clear The Channel Selection Bits*/
			ADMUX |= copy_u8Channel;

			/*Start Conversion*/
			SET_BIT(ADCSRA, ADCSRA_ADSC);

			/*Enable ADC Conversion Complete Interrupt*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);



		}
		else{
			Local_u8ErrorState = BUSY_ERR;
		}
	}
	else{
		Local_u8ErrorState=NULL_PTR;
	}
	return Local_u8ErrorState;
}

void __vector_16 (void)  __attribute__((signal));
void __vector_16 (void){
#if ADC_u8RESOLUTION == EIGHT_BITS
	*ADC_pu16DigResult=(uint16)ADCH;
#elif ADC_u8RESOLUTION ==TEN_BITS
	*ADC_pu16DigResult=ADC;
#endif
	/*ADC interrupt disable*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);

	/*ADC is now IDLE*/
	ADC_u8BusyFlag=IDLE;

	/*Invoke the callback notification function*/
	if(ADC_pvNotificationFunc!=NULL){
		ADC_pvNotificationFunc();
	}
	else{
		//Do nothing
	}
}
