#include "STD_TYPES.h"
#include <util/delay.h>
#include "BIT_MATH.h"
#include "Err_Type.h"

#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_prv.h"
#include "CLCD_cfg.h"
#if CLCD_u8CONNECTION_MODE == FOUR_BIT
static void voidSetHALFDataPort(uint8 copy_u8FourBitData){
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D4_PIN,GET_BIT(copy_u8FourBitData,0));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D5_PIN,GET_BIT(copy_u8FourBitData,1));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D6_PIN,GET_BIT(copy_u8FourBitData,2));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D7_PIN,GET_BIT(copy_u8FourBitData,3));

}
#endif
static void voidSendEnablePulse(){
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_PIN_LOW);

}

void CLCD_voidSendCommand(uint8 copy_u8Command){
	/*set Rs pin to low for command*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_PIN_LOW);
	/*set Rw pin to low for write*/
#if CLCD_u8READ_OPERATION_ENABLE == ENABLED
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_PIN_LOW);
#endif
	/*send the command*/
#if CLCD_u8CONNECTION_MODE == EIGHT_BIT
	DIO_u8SetPortValue(CLCD_u8DATA_PORT,copy_u8Command);
	/*send enable Pulse*/
	voidSendEnablePulse();
#elif CLCD_u8CONNECTION_MODE == FOUR_BIT
	/*send the higher 4 bits of the command*/
	voidSetHALFDataPort(copy_u8Command>>4u);
	/*send enable Pulse*/
	voidSendEnablePulse();
	/*send the lower 4 bits of the command*/
	voidSetHALFDataPort(copy_u8Command);
	/*send enable Pulse*/
	voidSendEnablePulse();

#endif
}
void CLCD_voidSendData(uint8 copy_u8Data){
	/*set Rs pin to high for Data*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_PIN_HIGH);
	/*set Rw pin to low for write*/
#if CLCD_u8READ_OPERATION_ENABLE == ENABLED
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_PIN_LOW);
#endif
	/*send the Data*/
#if CLCD_u8CONNECTION_MODE == EIGHT_BIT
	DIO_u8SetPortValue(CLCD_u8DATA_PORT,copy_u8Data);
	/*send enable Pulse*/
	voidSendEnablePulse();
#elif CLCD_u8CONNECTION_MODE == FOUR_BIT
	/*send the higher 4 bits of the Data*/
	voidSetHALFDataPort(copy_u8Data>>4u);
	/*send enable Pulse*/
	voidSendEnablePulse();
	/*send the lower 4 bits of the Data*/
	voidSetHALFDataPort(copy_u8Data);
	/*send enable Pulse*/
	voidSendEnablePulse();
#endif
}
void CLCD_voidInit(void){
	/*wait for more than 30 ms after power on*/
	_delay_ms(40);
	/*Function Set Command: 2 Lines, font size 5x7 */
#if CLCD_u8CONNECTION_MODE == EIGHT_BIT
	CLCD_voidSendCommand(0b00111000);
#elif CLCD_u8CONNECTION_MODE == FOUR_BIT
	voidSetHALFDataPort(0b0010);
	voidSendEnablePulse();
	voidSetHALFDataPort(0b0010);
	voidSendEnablePulse();
	voidSetHALFDataPort(0b1000);
	voidSendEnablePulse();
#endif
	/*Display On/Off Control Command: Display :on, Cursor:off, blink cursor:off */
	CLCD_voidSendCommand(0b00001100);
	/*Display Clear Command*/
	CLCD_voidSendCommand(1);
}

void CLCD_voidGoToXY(uint8 copy_u8XPos, uint8 copy_u8YPos){
	uint8 Local_u8DDRamAdd = (copy_u8YPos*0x40)+copy_u8XPos;
	/*if (copy_u8XPos)==0u{
	 * 		Local_u8DDRamAdd = copy_u8XPos;
	 * }
	 * else{
	 * 		Local_u8DDRamAdd = copy_YPos*0x40;
	 * }*/

	/*Set bit 7 for setting DDRAM Add command*/
	SET_BIT(Local_u8DDRamAdd,7u);
	/*Send setting DDRAM Add command*/
	CLCD_voidSendCommand(Local_u8DDRamAdd);
}
uint8 CLCD_u8WriteSpecialCharacter(uint8 copy_u8PatternNumber,uint8 copy_pu8PatternArr[],uint8 copy_u8XPos,uint8 copy_u8YPos){
	uint8 Local_u8ErrorStatus = OK;
	if(copy_pu8PatternArr != NULL){
		uint8 Local_u8CGRAMAdd = copy_u8PatternNumber * 8u;
		uint8 Local_u8Iterator;

		/*Set Bit 6 clear bit 7 for setting CGRAM address command*/
		SET_BIT(Local_u8CGRAMAdd,6u);

		/*Set CGRAM address */
		CLCD_voidSendCommand(Local_u8CGRAMAdd);

		/*Write the pattern inside CGRAM*/
		for(Local_u8Iterator=0;Local_u8Iterator<8u;Local_u8Iterator++){
			CLCD_voidSendData(copy_pu8PatternArr[Local_u8Iterator]);
		}

		/*Set DDRAM address*/
		CLCD_voidGoToXY(copy_u8XPos,copy_u8YPos);

		/*write the corresponding pattern number to display from CGRAM*/
		CLCD_voidSendData(copy_u8PatternNumber);
	}
	else{
		Local_u8ErrorStatus = NULL_PTR;
	}
	return Local_u8ErrorStatus;
}



uint8 CLCD_u8SendString(uint8 const copy_u8String[]){
	uint8 Local_u8ErrorStatus = OK ;
	if(copy_u8String != NULL){
		uint8 Local_u8Iterator=0;
		while(copy_u8String[Local_u8Iterator]!=NULL){
			CLCD_voidSendData(copy_u8String[Local_u8Iterator]);
			Local_u8Iterator ++;
		}
	}
	else{
		Local_u8ErrorStatus = NULL_PTR;
	}
	return Local_u8ErrorStatus;
}
void CLCD_voidSendNumber(sint32 copy_s32Number ){
	sint32 Local_s32Left,Local_s32Right=copy_s32Number;
	uint8 Local_u8Iterator,Local_u8Counter=0;
	sint8 Local_u8Iterator2;
	uint32 Local_u8Arr[40]={};
	if(copy_s32Number>0){
		Local_s32Left=Local_s32Right;
		while(Local_s32Right!=0){
			while((Local_s32Left / 10)!=0){
				Local_s32Left /= 10;
				Local_u8Counter ++;

			}
			for(Local_u8Iterator2=0;Local_u8Iterator2<Local_u8Counter+1;Local_u8Iterator2++){

				Local_u8Arr[Local_u8Iterator2]=(Local_s32Right%10);
				Local_s32Right /=10;
			}
			for(Local_u8Iterator2=Local_u8Counter;Local_u8Iterator2>=0;Local_u8Iterator2--){
				CLCD_voidSendData(Local_u8Arr[Local_u8Iterator2]+48);
			}

			Local_u8Counter=0;


		}
	}
	else if(copy_s32Number<0){
		Local_s32Right*= -1;
		CLCD_voidSendData('-');
		Local_s32Left=Local_s32Right;
		while(Local_s32Right!=0){
			while((Local_s32Left / 10)!=0){
				Local_s32Left /= 10;
				Local_u8Counter ++;

			}
			for(Local_u8Iterator2=0;Local_u8Iterator2<Local_u8Counter+1;Local_u8Iterator2++){

				Local_u8Arr[Local_u8Iterator2]=(Local_s32Right%10);
				Local_s32Right /=10;
			}
			for(Local_u8Iterator2=Local_u8Counter;Local_u8Iterator2>=0;Local_u8Iterator2--){
				CLCD_voidSendData(Local_u8Arr[Local_u8Iterator2]+48);
			}

			Local_u8Counter=0;


		}
	}
	else{
		CLCD_voidSendData(48);
	}

}

