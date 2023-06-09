#include "STD_TYPES.h"

#include <util/delay.h>
#include "BIT_MATH.h"
#include "Err_Type.h"

#include "DIO_interface.h"

#include "SSD_interface.h"



uint8 SSD_u8SetNumber(const SSD_Config_t* copy_SSD_pData,uint8 copy_u8Number){
	uint8 Local_u8ErrorState = OK;
	if(copy_SSD_pData!=NULL){
		if(copy_SSD_pData->SSD_u8Type == ANODE){
			if(copy_SSD_pData->SSD_tPin==DIO_PIN0){
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN0,~(GET_BIT(copy_u8Number,0)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN1,~(GET_BIT(copy_u8Number,1)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN2,~(GET_BIT(copy_u8Number,2)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN3,~(GET_BIT(copy_u8Number,3)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN4,~(GET_BIT(copy_u8Number,4)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN5,~(GET_BIT(copy_u8Number,5)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN6,~(GET_BIT(copy_u8Number,6)));


			}
			else if (copy_SSD_pData->SSD_tPin==DIO_PIN1){
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN1,~(GET_BIT(copy_u8Number,0)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN2,~(GET_BIT(copy_u8Number,1)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN3,~(GET_BIT(copy_u8Number,2)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN4,~(GET_BIT(copy_u8Number,3)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN5,~(GET_BIT(copy_u8Number,4)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN6,~(GET_BIT(copy_u8Number,5)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN7,~(GET_BIT(copy_u8Number,6)));
			}
		}
		else if((copy_SSD_pData->SSD_u8Type == CATHODE)||(copy_SSD_pData->SSD_u8Type == ETA_KIT)){
			if(copy_SSD_pData->SSD_tPin==DIO_PIN0){
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN0,(GET_BIT(copy_u8Number,0)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN1,(GET_BIT(copy_u8Number,1)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN2,(GET_BIT(copy_u8Number,2)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN3,(GET_BIT(copy_u8Number,3)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN4,(GET_BIT(copy_u8Number,4)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN5,(GET_BIT(copy_u8Number,5)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN6,(GET_BIT(copy_u8Number,6)));


			}
			else if (copy_SSD_pData->SSD_tPin==DIO_PIN1){
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN1,(GET_BIT(copy_u8Number,0)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN2,(GET_BIT(copy_u8Number,1)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN3,(GET_BIT(copy_u8Number,2)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN4,(GET_BIT(copy_u8Number,3)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN5,(GET_BIT(copy_u8Number,4)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN6,(GET_BIT(copy_u8Number,5)));
				DIO_u8SetPinValue(copy_SSD_pData->SSD_tPort,DIO_PIN7,(GET_BIT(copy_u8Number,6)));
			}
		}

	}
	else{
		Local_u8ErrorState = NULL_PTR;
	}
	return Local_u8ErrorState;
}
uint8 SSD_u8Enable(const SSD_Config_t* copy_SSD_pData){
	uint8 Local_u8ErrorState = OK;
	if(copy_SSD_pData!=NULL){
		if((copy_SSD_pData->SSD_u8Type == ANODE)||(copy_SSD_pData->SSD_u8Type == ETA_KIT)){
			DIO_u8SetPinValue(copy_SSD_pData->SSD_tEPort,copy_SSD_pData->SSD_tEPin,DIO_PIN_HIGH);

		}
		else if(copy_SSD_pData->SSD_u8Type == CATHODE){
			DIO_u8SetPinValue(copy_SSD_pData->SSD_tEPort,copy_SSD_pData->SSD_tEPin,DIO_PIN_LOW);

		}
	}
	else{
		Local_u8ErrorState = NULL_PTR;
	}
	return Local_u8ErrorState;

}
uint8 SSD_u8Disable(const SSD_Config_t* copy_SSD_pData){
	uint8 Local_u8ErrorState = OK;
	if(copy_SSD_pData!=NULL){
		if((copy_SSD_pData->SSD_u8Type == ANODE)||(copy_SSD_pData->SSD_u8Type == ETA_KIT)){
			DIO_u8SetPinValue(copy_SSD_pData->SSD_tEPort,copy_SSD_pData->SSD_tEPin,DIO_PIN_LOW);

		}
		else if(copy_SSD_pData->SSD_u8Type == CATHODE){
			DIO_u8SetPinValue(copy_SSD_pData->SSD_tEPort,copy_SSD_pData->SSD_tEPin,DIO_PIN_HIGH);

		}
	}
	else{
		Local_u8ErrorState = NULL_PTR;
	}
	return Local_u8ErrorState;

}


