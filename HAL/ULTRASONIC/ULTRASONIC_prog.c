#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include <util/delay.h>

#include "TIMER_interface.h"
#include "DIO_interface.h"

#include "ULTRASONIC_interface.h"
#include "ULTRASONIC_cfg.h"
#include "ULTRASONIC_prv.h"

#include "CLCD_interface.h"

static volatile uint16 Read1,Read2;

void FUNC (void);

void ULTRASONIC_voidInit()
{
	//Initialize Timer1
	TIMER_CFG_t timer1_cfg={NORMAL,OPTION0,CLCK_1024,INT_OVF};
	TIMER1_u8Init(&timer1_cfg);

	//Enable the ICU
	TIMER1_ICU_IntEnable();

	//Set edge trigger of the echo pin to rising initially
	TIMER1_ICU_void_setTrigg(TIMER_ICU_RISING);
	//Set the callback function
	TIMER1_ICU_setCallBack(FUNC);
	//Start timer1
	TIMER1_u8start(&timer1_cfg);

	//Set the trig pin to high for at least 10us to order it to start sending waves
	DIO_u8SetPinValue(ULTRASONIC_TRIG_PORT,ULTRASONIC_TRIG_PIN,DIO_PIN_HIGH);
	//set delay to at least 10 us
	_delay_us(15);
	//set the pin to low
	DIO_u8SetPinValue(ULTRASONIC_TRIG_PORT,ULTRASONIC_TRIG_PIN,DIO_PIN_LOW);



}

uint8 ULTRASONIC_u8GetRead(uint16* copy_u8pReading)
{
	uint8 Local_u8Error_State=OK;
	if(copy_u8pReading!=NULL)
	{


		while((Read1==0)||(Read2==0));


		//Get the reading in cm
		*copy_u8pReading=((((uint32)(Read2-Read1)*512UL)*34UL)/(16000UL));			//((((uint32)(Read2-Read1)*1024UL)*34000UL)/(2*16000000UL))



	}
	else
	{
		Local_u8Error_State=NOK;
	}
	return Local_u8Error_State;
}

void FUNC (void)
{
	static uint16 Local_u16Counter=0;
	Local_u16Counter++;

	if(Local_u16Counter==1)
	{
		TIMER1_ICU_takeReading(&Read1);
		TIMER1_ICU_void_setTrigg(TIMER_ICU_FALLING);
	}
	else if(Local_u16Counter==2)
	{
		TIMER1_ICU_takeReading(&Read2);
		Local_u16Counter=0;
		TIMER1_ICU_IntDisable();

	}
}
