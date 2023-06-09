#include "STD_TYPES.h"

#include <util/delay.h>
#include "BIT_MATH.h"
#include "Err_Type.h"

#include "DIO_interface.h"

#include "SW_interface.h"


uint8 SW_u8GetState(const SW_Config_t* copy_SW_pData,uint8 *copy_u8pSWState){
	uint8 Local_u8ErrorState = OK;
	uint8 Local_u8State;
	if(copy_SW_pData!=NULL){
		if(copy_SW_pData->SW_u8PullType==PULL_UP){
			DIO_u8GetPinValue(copy_SW_pData->SW_tPort, copy_SW_pData->SW_tPin, &Local_u8State);
			_delay_ms(100);
			if(Local_u8State==1){
				*copy_u8pSWState=0;
			}
			else if(Local_u8State==0){
				*copy_u8pSWState=1;
			}
		}
		else if(copy_SW_pData->SW_u8PullType==PULL_DOWN){
			DIO_u8GetPinValue(copy_SW_pData->SW_tPort, copy_SW_pData->SW_tPin, &Local_u8State);
			_delay_ms(100);
			if(Local_u8State==1){
				*copy_u8pSWState=1;
			}
			else if(Local_u8State==0){
				*copy_u8pSWState=0;
			}
		}
	}
	else{
		Local_u8ErrorState=NULL_PTR;
	}
	return Local_u8ErrorState;
}
