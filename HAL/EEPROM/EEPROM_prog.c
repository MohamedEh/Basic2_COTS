#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include <util/delay.h>

#include "TWI_interface.h"

#include "EEPROM_cfg.h"
#include "EEPROM_prv.h"
#include "EEPROM_interface.h"



uint8 EEPROM_u8Init(void)
{
	uint8 Local_u8Error_State=OK;
	//Set frequency to 400KHZ using bitrate = 12, prescaler = 1
	TWI_CFG_t Local_Config={PRESCALER_1,12};

	TWI_Init(&Local_Config);

	return Local_u8Error_State;
}

uint8 EEPROM_u8WriteByte(uint16 copy_u16Address,uint8 copy_u8Data)
{
	uint8 Local_u8Error_State=OK;

	//send start
	TWI_sendStart();
	//check status
	TWI_getStatus(&Local_u8Error_State);
	if(Local_u8Error_State==START_ACK)
	{
		uint8 address=0b10100000;
		address|=(0<<3);
		address|=(copy_u16Address>>7);
		address|=0;
		TWI_sendByte(address);
		//check status
		TWI_getStatus(&Local_u8Error_State);
		if(Local_u8Error_State==SLAVE_ADD_AND_WR_ACK)
		{
			TWI_sendByte((uint8)copy_u16Address);
			//check status
			TWI_getStatus(&Local_u8Error_State);
			if(Local_u8Error_State==MSTR_WR_BYTE_ACK)
			{
				TWI_sendByte(copy_u8Data);
				//check status
				TWI_getStatus(&Local_u8Error_State);
				if(Local_u8Error_State==MSTR_WR_BYTE_ACK)
				{
					TWI_sendStop();


				}
				else
				{
					Local_u8Error_State=NOK;
				}

			}
			else
			{
				Local_u8Error_State=NOK;
			}
		}
		else
		{
			Local_u8Error_State=NOK;
		}
	}
	else
	{
		Local_u8Error_State=NOK;
	}

	_delay_us(9501);
	return Local_u8Error_State;
}

uint8 EEPROM_u8ReadByte(uint16 copy_u16Address,uint8* copy_u8pdata)
{
	uint8 Local_u8Error_State=OK;

	//send start
	TWI_sendStart();
	//check status
	TWI_getStatus(&Local_u8Error_State);
	if(Local_u8Error_State==START_ACK)
	{
		uint8 address=0b10100000;
		address|=(0<<3);
		address|=(copy_u16Address>>7);
		address|=0;
		TWI_sendByte(address);
		//check status
		TWI_getStatus(&Local_u8Error_State);
		if(Local_u8Error_State==SLAVE_ADD_AND_WR_ACK)
		{
			TWI_sendByte((uint8)copy_u16Address);
			//check status
			TWI_getStatus(&Local_u8Error_State);
			if(Local_u8Error_State==MSTR_WR_BYTE_ACK)
			{
				TWI_sendStart();
				//check status
				TWI_getStatus(&Local_u8Error_State);
				if(Local_u8Error_State==REP_START_ACK)
				{
					uint8 addr=0b10100000;
					addr|=0;
					addr|=1;
					TWI_sendByte(addr);
					//check status
					TWI_getStatus(&Local_u8Error_State);
					if(Local_u8Error_State==SLAVE_ADD_AND_RD_ACK)
					{

						TWI_receiveByte_ACK(copy_u8pdata);
						//check status
						TWI_getStatus(&Local_u8Error_State);
						if(Local_u8Error_State==MSTR_RD_BYTE_WITH_ACK)
						{
							TWI_sendStop();

						}
						else
						{
							Local_u8Error_State=NOK;
						}
					}
					else
					{
						Local_u8Error_State=NOK;
					}

				}
				else
				{
					Local_u8Error_State=NOK;
				}

			}
			else
			{
				Local_u8Error_State=NOK;
			}
		}
		else
		{
			Local_u8Error_State=NOK;
		}
	}
	else
	{
		Local_u8Error_State=NOK;
	}


	return Local_u8Error_State;
}
