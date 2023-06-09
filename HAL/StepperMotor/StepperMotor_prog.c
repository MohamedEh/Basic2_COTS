#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "StepperMotor_interface.h"

uint8 StepperMotor_u8Rotate(const StepperMotor_Config_t* copy_pStepperConfig,uint16 copy_u16Angle,uint8 copy_u8Dir){
	uint8 Local_u8ErrorState = OK;
	if(copy_pStepperConfig!=NULL){
		uint16 Local_u16Step = (uint16)(((uint32)copy_u16Angle*2048UL)/360UL);
		if(copy_u8Dir==StepperMotor_CW){
			uint16 Local_u16Iterator;
			for(Local_u16Iterator = 0;Local_u16Iterator<Local_u16Step;Local_u16Iterator++){
				if(Local_u16Iterator%4==0){
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_BPIN,DIO_PIN_LOW);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_PPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_YPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_OPIN,DIO_PIN_HIGH);

				}

				else if(Local_u16Iterator%4==1){
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_BPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_PPIN,DIO_PIN_LOW);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_YPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_OPIN,DIO_PIN_HIGH);

				}
				else if(Local_u16Iterator%4==2){
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_BPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_PPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_YPIN,DIO_PIN_LOW);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_OPIN,DIO_PIN_HIGH);
				}
				else if(Local_u16Iterator%4==3){
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_BPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_PPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_YPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_OPIN,DIO_PIN_LOW);
				}
				_delay_ms(2);
			}
		}
		else if(copy_u8Dir==StepperMotor_CCW){
			uint16 Local_u16Iterator;
			for(Local_u16Iterator = 0;Local_u16Iterator<Local_u16Step;Local_u16Iterator++){
				if(Local_u16Iterator%4==0){
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_OPIN,DIO_PIN_LOW);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_YPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_PPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_BPIN,DIO_PIN_HIGH);
				}
				else if(Local_u16Iterator%4==1){
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_OPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_YPIN,DIO_PIN_LOW);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_PPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_BPIN,DIO_PIN_HIGH);
				}
				else if(Local_u16Iterator%4==2){
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_OPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_YPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_PPIN,DIO_PIN_LOW);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_BPIN,DIO_PIN_HIGH);
				}
				else if(Local_u16Iterator%4==3){
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_OPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_YPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_PPIN,DIO_PIN_HIGH);
					DIO_u8SetPinValue(copy_pStepperConfig->StepperMotor_PORT,copy_pStepperConfig->StepperMotor_BPIN,DIO_PIN_LOW);
				}
				_delay_ms(2);
			}
		}
	}
	else{
		Local_u8ErrorState=NULL_PTR;
	}
	
	
	return Local_u8ErrorState;
}

