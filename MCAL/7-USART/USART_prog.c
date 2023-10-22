#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"

#include "USART_reg.h"
#include "USART_cfg.h"
#include "USART_prv.h"
#include "USART_interface.h"

uint8* USART_pu8Buffer;
uint8 USART_u8Length;
void (*USART_pvNotificationFunc[2])(void)={NULL};

uint8 USART_u8Init(const USART_InitCfg_t* copy_pInitCfg){
	uint8 Local_u8Error_State=OK;
	uint16 Local_u16UBRRValue;
	if(copy_pInitCfg!=NULL){
		uint8 Local_UCSRCValue = 0;
		//Select UCSRC by setting URSEL
		SET_BIT(Local_UCSRCValue,URSEL);
		//Set Character Size
		switch (copy_pInitCfg->Charactersize){
		case FIVE_BIT:
			CLR_BIT(Local_UCSRCValue,UCSZ0);
			CLR_BIT(Local_UCSRCValue,UCSZ1);
			UCSRC=Local_UCSRCValue;
			break;
		case SIX_BIT:
			SET_BIT(Local_UCSRCValue,UCSZ0);
			CLR_BIT(Local_UCSRCValue,UCSZ1);
			UCSRC=Local_UCSRCValue;
			break;
		case SEVEN_BIT:
			CLR_BIT(Local_UCSRCValue,UCSZ0);
			SET_BIT(Local_UCSRCValue,UCSZ1);
			UCSRC=Local_UCSRCValue;
			break;
		case EIGHT_BIT:
			SET_BIT(Local_UCSRCValue,UCSZ0);
			SET_BIT(Local_UCSRCValue,UCSZ1);
			UCSRC=Local_UCSRCValue;
			break;
		case NINE_BIT:
			SET_BIT(Local_UCSRCValue,UCSZ0);
			SET_BIT(Local_UCSRCValue,UCSZ1);
			UCSRC=Local_UCSRCValue;
			SET_BIT(UCSRB,UCSZ2);
			break;
		default:
			Local_u8Error_State=NOK;
			break;
		}
		//Set Parity Mode
		switch (copy_pInitCfg->Parity){
		case DISABLE:
			CLR_BIT(Local_UCSRCValue,UPM0);
			CLR_BIT(Local_UCSRCValue,UPM1);
			UCSRC=Local_UCSRCValue;
			break;
		case EVEN:
			CLR_BIT(Local_UCSRCValue,UPM0);
			SET_BIT(Local_UCSRCValue,UPM1);
			UCSRC=Local_UCSRCValue;
			break;
		case ODD:
			SET_BIT(Local_UCSRCValue,UPM0);
			SET_BIT(Local_UCSRCValue,UPM1);
			UCSRC=Local_UCSRCValue;
			break;
		default:
			Local_u8Error_State=NOK;
			break;
		}
		//Set no of stop bits
		switch (copy_pInitCfg->StopBit){
		case ONE_BIT:
			CLR_BIT(Local_UCSRCValue,USBS);
			UCSRC=Local_UCSRCValue;
			break;
		case TWO_BIT:
			SET_BIT(Local_UCSRCValue,USBS);
			UCSRC=Local_UCSRCValue;
			break;

		default:
			Local_u8Error_State=NOK;
			break;
		}
		//Set Clock Mode
		switch (copy_pInitCfg->ClockMode){
		case ASYNCHRONOUS:
			CLR_BIT(Local_UCSRCValue,UMSEL);
			UCSRC=Local_UCSRCValue;
			break;
		case SYNCHRONOUS:
			SET_BIT(Local_UCSRCValue,UMSEL);
			UCSRC=Local_UCSRCValue;
			break;

		default:
			Local_u8Error_State=NOK;
			break;
		}
		//Set Clock Polarity
		switch (copy_pInitCfg->ClockPolarity){
		case RISE_TX_FALL_RX:
			CLR_BIT(Local_UCSRCValue,UCPOL);
			UCSRC=Local_UCSRCValue;
			break;
		case FALL_TX_RISE_RX:
			SET_BIT(Local_UCSRCValue,UCPOL);
			UCSRC=Local_UCSRCValue;
			break;

		default:
			Local_u8Error_State=NOK;
			break;
		}
		//Set Interrupt Mode
		switch (copy_pInitCfg->Int){
		case DISABLED:
			CLR_BIT(UCSRB,TXCIE);
			CLR_BIT(UCSRB,RXCIE);
			break;
		case ENABLED:
			SET_BIT(UCSRB,TXCIE);
			SET_BIT(UCSRB,RXCIE);
			break;

		default:
			Local_u8Error_State=NOK;
			break;
		}
		//Set baud rate
		switch(copy_pInitCfg->BaudRate){
		case _2400_bps:
			Local_u16UBRRValue=416;
			UBRRL=(uint8) Local_u16UBRRValue;
			UBRRH = (uint8)(Local_u16UBRRValue>>8u);
			break;

		case _4800_bps:
			Local_u16UBRRValue=207;
			UBRRL=(uint8) Local_u16UBRRValue;
			UBRRH = (uint8)(Local_u16UBRRValue>>8u);
			break;

		case _9600_bps:
			Local_u16UBRRValue=103;
			UBRRL=(uint8) Local_u16UBRRValue;
			UBRRH = (uint8)(Local_u16UBRRValue>>8u);
			break;

		case _14_4k_bps:
			Local_u16UBRRValue=68;
			UBRRL=(uint8) Local_u16UBRRValue;
			UBRRH = (uint8)(Local_u16UBRRValue>>8u);
			break;
		case _19_2k_bps:
			Local_u16UBRRValue=51;
			UBRRL=(uint8) Local_u16UBRRValue;
			UBRRH = (uint8)(Local_u16UBRRValue>>8u);
			break;
		case _28_8k_bps:
			Local_u16UBRRValue=34;
			UBRRL=(uint8) Local_u16UBRRValue;
			UBRRH = (uint8)(Local_u16UBRRValue>>8u);
			break;
		case _38_4k_bps:
			Local_u16UBRRValue=25;
			UBRRL=(uint8) Local_u16UBRRValue;
			UBRRH = (uint8)(Local_u16UBRRValue>>8u);
			break;
		case _57_6k_bps:
			Local_u16UBRRValue=16;
			UBRRL=(uint8) Local_u16UBRRValue;
			UBRRH = (uint8)(Local_u16UBRRValue>>8u);
			break;
		case _76_8k_bps:
			Local_u16UBRRValue=12;
			UBRRL=(uint8) Local_u16UBRRValue;
			UBRRH = (uint8)(Local_u16UBRRValue>>8u);
			break;
		case _115_2k_bps:
			Local_u16UBRRValue=8;
			UBRRL=(uint8) Local_u16UBRRValue;
			UBRRH = (uint8)(Local_u16UBRRValue>>8u);
			break;
		case _230_4k_bps:
			Local_u16UBRRValue=3;
			UBRRL=(uint8) Local_u16UBRRValue;
			UBRRH = (uint8)(Local_u16UBRRValue>>8u);
			break;
		case _250k_bps:
			Local_u16UBRRValue=3;
			UBRRL=(uint8) Local_u16UBRRValue;
			UBRRH = (uint8)(Local_u16UBRRValue>>8u);
			break;
		case _0_5M_bps:
			Local_u16UBRRValue=1;
			UBRRL=(uint8) Local_u16UBRRValue;
			UBRRH = (uint8)(Local_u16UBRRValue>>8u);
			break;
		case _1M_bps:
			Local_u16UBRRValue=1;
			UBRRL=(uint8) Local_u16UBRRValue;
			UBRRH = (uint8)(Local_u16UBRRValue>>8u);
			break;
		default:
			Local_u8Error_State=NOK;
			break;
		}
		//Receiver Enable
		SET_BIT(UCSRB,RXEN);
		//Transmitter Enable
		SET_BIT(UCSRB,TXEN);
	}
	else{
		Local_u8Error_State=NULL_PTR;
	}
	return Local_u8Error_State;
}
uint8 USART_voidSendByte(uint8 copy_u8Data){
	uint8 Local_u8Error_state=OK;
	uint32 Local_u32Counter=0;

	//wait till transmit buffer is empty and ready
	while((GET_BIT(UCSRA,UDRE)==0)&&(Local_u32Counter<USART_u32TIMEOUT_COUNT))
	{
		Local_u32Counter++;
	}
	if(Local_u32Counter==USART_u32TIMEOUT_COUNT)
	{
		Local_u8Error_state=TIMEOUT_ERR;
	}
	else
	{
		UDR = copy_u8Data;
	}

	return Local_u8Error_state;



}
uint8 USART_u8ReceiveByte(uint8* copy_u8Data){

	uint8 Local_u8Error_state=OK;
	uint32 Local_u32Counter=0;

	//wait till data is recieved
	while((GET_BIT(UCSRA,RXC)==0)&&(Local_u32Counter<USART_u32TIMEOUT_COUNT))
	{
		Local_u32Counter++;
	}
	if(Local_u32Counter==USART_u32TIMEOUT_COUNT)
	{
		Local_u8Error_state=TIMEOUT_ERR;
	}
	else
	{
		*copy_u8Data =UDR ;
	}

	return Local_u8Error_state;
}
void USART_voidEnableInt(void){

	SET_BIT(UCSRB,TXCIE);
	SET_BIT(UCSRB,RXCIE);
}
void USART_voidDisableInt(void){
	CLR_BIT(UCSRB,TXCIE);
	CLR_BIT(UCSRB,RXCIE);
}

uint8 USART_u8SendBufferSynch(uint8* copy_pu8Buffer, uint8 copy_u8Length)
{
	uint8 Local_u8ErrorState=OK;
	if(copy_pu8Buffer!=NULL)
	{
		uint8 Local_u8counter;
		for(Local_u8counter=0U;Local_u8counter<copy_u8Length;Local_u8counter++)
		{
			USART_voidSendByte(copy_pu8Buffer[Local_u8counter]);
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR;
	}
	return Local_u8ErrorState;
}
uint8 USART_u8ReceiveBufferSynch(uint8* copy_pu8Buffer, uint8 copy_u8Length)
{
	uint8 Local_u8ErrorState=OK;
	if(copy_pu8Buffer!=NULL)
	{
		uint8 Local_u8counter;
		for(Local_u8counter=0U;Local_u8counter<copy_u8Length;Local_u8counter++)
		{
			USART_u8ReceiveByte(&copy_pu8Buffer[Local_u8counter]);
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR;
	}
	return Local_u8ErrorState;
}

uint8 USART_u8SendBufferASynch(uint8* copy_pu8Buffer, uint8 copy_u8Length,void (*copy_pvNotificationFunc)(void))
{
	uint8 Local_u8ErrorState=OK;
	if((copy_pu8Buffer!=NULL)&&(copy_pvNotificationFunc!=NULL))
	{
		//Put Data buffer inside global pointer
		USART_pu8Buffer=copy_pu8Buffer;
		//Put Data length inside global integer
		USART_u8Length=copy_u8Length;
		//Put notification function inside global pointer to function
		USART_pvNotificationFunc[0]=copy_pvNotificationFunc;

		//Set Data Register Empty interrupt
		SET_BIT(UCSRB,UDRIE);

	}
	else
	{
		Local_u8ErrorState=NULL_PTR;
	}
	return Local_u8ErrorState;
}
uint8 USART_u8ReceiveBufferASynch(uint8* copy_pu8Buffer, uint8 copy_u8Length,void (*copy_pvNotificationFunc)(void))
{
	uint8 Local_u8ErrorState=OK;
	if((copy_pu8Buffer!=NULL)&&(copy_pvNotificationFunc!=NULL))
	{
		//Put Data buffer inside global pointer
		USART_pu8Buffer=copy_pu8Buffer;
		//Put Data length inside global integer
		USART_u8Length=copy_u8Length;
		//Put notification function inside global pointer to function
		USART_pvNotificationFunc[1]=copy_pvNotificationFunc;

		//Set Receive interrupt
		SET_BIT(UCSRB,RXCIE);
	}
	else
	{
		Local_u8ErrorState=NULL_PTR;
	}
	return Local_u8ErrorState;
}



//Data register Empty ISR
void __vector_14 (void)	__attribute__((signal));
void __vector_14 (void)
		{
	static uint8 Local_u8Counter=0;

	if(Local_u8Counter<USART_u8Length)
	{
		USART_voidSendByte(USART_pu8Buffer[Local_u8Counter]);
		Local_u8Counter++;
	}
	else
	{
		USART_pvNotificationFunc[0]();
		Local_u8Counter=0;
		CLR_BIT(UCSRB,UDRIE);
	}
		}

//Receive ISR
void __vector_13 (void)	__attribute__((signal));
void __vector_13 (void)
		{
	static uint8 Local_u8Counter=0;
	if(Local_u8Counter<USART_u8Length)
	{
		USART_u8ReceiveByte(&USART_pu8Buffer[Local_u8Counter]);
		Local_u8Counter++;
	}
	else
	{
		USART_pvNotificationFunc[1]();
		Local_u8Counter=0;
		CLR_BIT(UCSRB,RXCIE);
	}
		}

