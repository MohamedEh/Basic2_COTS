#include "STD_TYPES.h"

#include <util/delay.h>
#include "BIT_MATH.h"
#include "Err_Type.h"

#include "DIO_interface.h"
#include "LED_interface.h"

uint8 LED_u8SetOn(const LED_Config_t *copy_LED_pData){
	uint8 Local_u8ErrorState=OK;
	if(copy_LED_pData!=NULL){
		if(copy_LED_pData->LED_u8ActivityType==ACTIVE_HIGH){
			DIO_u8SetPinValue(copy_LED_pData->LED_tPort,copy_LED_pData->LED_tPin,DIO_PIN_HIGH);
		}
		else if(copy_LED_pData->LED_u8ActivityType==ACTIVE_LOW){
			DIO_u8SetPinValue(copy_LED_pData->LED_tPort,copy_LED_pData->LED_tPin,DIO_PIN_LOW);
		}
	}
	else{
		Local_u8ErrorState=NULL_PTR;
	}
	return Local_u8ErrorState;
}
uint8 LED_u8SetOff(const LED_Config_t *copy_LED_pData){
	uint8 Local_u8ErrorState=OK;
	if(copy_LED_pData!=NULL){
		if(copy_LED_pData->LED_u8ActivityType==ACTIVE_HIGH){
			DIO_u8SetPinValue(copy_LED_pData->LED_tPort,copy_LED_pData->LED_tPin,DIO_PIN_LOW);
		}
		else if(copy_LED_pData->LED_u8ActivityType==ACTIVE_LOW){
			DIO_u8SetPinValue(copy_LED_pData->LED_tPort,copy_LED_pData->LED_tPin,DIO_PIN_HIGH);
		}
	}
	else{
		Local_u8ErrorState=NULL_PTR;
	}
	return Local_u8ErrorState;

}
uint8 LED_u8SetToggle(const LED_Config_t *copy_LED_pData){
	uint8 Local_u8ErrorState=OK;
	if(copy_LED_pData!=NULL){
			DIO_u8TogglePinValue(copy_LED_pData->LED_tPort,copy_LED_pData->LED_tPin);
	}
	else{
		Local_u8ErrorState=NULL_PTR;
	}
	return Local_u8ErrorState;

}
