#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"

#include "TWI_reg.h"
#include "TWI_cfg.h"
#include "TWI_prv.h"
#include "TWI_interface.h"



//void TWI_voidMasterInit(uint8 copy_u8Address)
//{
//	if (copy_u8Address!=0u)
//	{
//		TWAR=copy_u8Address<<1u;
//	}
//
//	CLR_BIT(TWSR,TWPS0);
//	CLR_BIT(TWSR,TWPS1);
//
//	TWBR=12U;
//
//	SET_BIT(TWCR,TWEA);
//	SET_BIT(TWCR,TWEN);
//}

// if the master is not addressed in the network , pass address 0
void TWI_voidMasterInit(uint8 copy_u8Address)
{
	//Assigning Address to the Master
	if(copy_u8Address!=0)
	{
		TWAR = copy_u8Address<<1;
	}
	else
	{
		//Do Nothing
	}

	//Assigning the bit rate value to 400kbps
	switch(TWI_TWPSVal)
	{
	case 0U:
		CLR_BIT(TWSR,TWPS0);
		CLR_BIT(TWSR,TWPS1);
		break;
	case 1U:
		SET_BIT(TWSR,TWPS0);
		CLR_BIT(TWSR,TWPS1);
		break;
	case 2U:
		CLR_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);
		break;
	case 3U:
		SET_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);
		break;
	}

	TWBR = TWI_TWBRVal;

	//Enabling Acknowledge bit
	SET_BIT(TWCR,TWEA);
	//Enabling TWI bit
	SET_BIT(TWCR,TWEN);

}
void TWI_voidSlaveInit(uint8 copy_u8Address)
{
	//Assigning Address to the Master
	TWAR = copy_u8Address<<1;

	//Enabling Acknowledge bit
	SET_BIT(TWCR,TWEA);
	//Enabling TWI bit
	SET_BIT(TWCR,TWEN);
}


TWI_ErrorStatus_t TWI_voidSendStartCond(void)
{
	TWI_ErrorStatus_t Local_Error = NoError;

	uint8 Local_u8TWCRVal;
	//Set Start Bit
	SET_BIT(Local_u8TWCRVal,TWSTA);

	//Clear interrupt flag to enable start action to happen
	SET_BIT(Local_u8TWCRVal,TWINT);

	TWCR = Local_u8TWCRVal;

	//Check if flag is set(action is done) condition is done
	while(!(GET_BIT(TWCR,TWINT)));

	//check status of the bus
	if ((TWSR & STATUS_BITS_MASK)!=START_ACK)
	{
		Local_Error = StartCondErr;
	}
	else
	{
		//Do Nothing
	}




	return Local_Error;
}
TWI_ErrorStatus_t TWI_voidSendRepeatedStart(void)
{
	TWI_ErrorStatus_t Local_Error = NoError;

	uint8 Local_u8TWCRVal;
	//Set Start Bit
	SET_BIT(Local_u8TWCRVal,TWSTA);

	//Clear interrupt flag to enable start action to happen
	SET_BIT(Local_u8TWCRVal,TWINT);

	TWCR = Local_u8TWCRVal;

	//Check if flag is set(action is done) condition is done
	while(!(GET_BIT(TWCR,TWINT)));

	//check status of the bus
	if ((TWSR & STATUS_BITS_MASK)!=REP_START_ACK)
	{
		Local_Error = RepStartErr;
	}
	else
	{
		//Do Nothing
	}




	return Local_Error;
}
TWI_ErrorStatus_t TWI_voidSendSlaveAddWithWrite(uint8 copy_u8Address)
{
	TWI_ErrorStatus_t Local_Error = NoError;

	//Set slave address into data register
	TWDR=copy_u8Address<<1U;

	//clear bit 0 for write request
	CLR_BIT(TWDR,0U);


	//Clear Start Bit
	CLR_BIT(TWCR,TWSTA);

	//Clear interrupt flag to enable start action to happen
	SET_BIT(TWCR,TWINT);



	//Check if flag is set(action is done) condition is done
	while(!(GET_BIT(TWCR,TWINT)));

	//check status of the bus
	if ((TWSR & STATUS_BITS_MASK)!=SLAVE_ADD_AND_WR_ACK)
	{
		Local_Error = SlaveAddressWithWriteErr;
	}
	else
	{
		//Do Nothing
	}



	return Local_Error;
}
TWI_ErrorStatus_t TWI_voidSendSlaveAddWithRead(uint8 copy_u8Address)
{
	TWI_ErrorStatus_t Local_Error = NoError;

	//Set slave address into data register
	TWDR=copy_u8Address<<1U;

	//Set bit 0 for read request
	SET_BIT(TWDR,0U);


	//Clear Start Bit
	CLR_BIT(TWCR,TWSTA);

	//Clear interrupt flag to enable start action to happen
	SET_BIT(TWCR,TWINT);



	//Check if flag is set(action is done) condition is done
	while(!(GET_BIT(TWCR,TWINT)));

	//check status of the bus
	if ((TWSR & STATUS_BITS_MASK)!=SLAVE_ADD_AND_RD_ACK)
	{
		Local_Error = SlaveAddressWithReadErr;
	}
	else
	{
		//Do Nothing
	}



	return Local_Error;
}
TWI_ErrorStatus_t TWI_voidMasterWriteDataByte(uint8 copy_u8DataByte)
{
	TWI_ErrorStatus_t Local_Error = NoError;

	//Put the data byte on the bus
	TWDR = copy_u8DataByte;

	//Clear interrupt flag to enable start action to happen
	SET_BIT(TWCR,TWINT);



	//Check if flag is set(action is done) condition is done
	while(!(GET_BIT(TWCR,TWINT)));

	//check status of the bus
	if ((TWSR & STATUS_BITS_MASK)!=MSTR_WR_BYTE_ACK)
	{
		Local_Error = 	MstrWriteByteWithAck;
	}
	else
	{
		//Do Nothing
	}

	return Local_Error;

}
TWI_ErrorStatus_t TWI_voidMasterReadDataByte(uint8* copy_u8DataByte)
{
	TWI_ErrorStatus_t Local_Error = NoError;

	if(copy_u8DataByte!=NULL){



		//Clear interrupt flag to enable start action to happen
		SET_BIT(TWCR,TWINT);



		//Check if flag is set(action is done) condition is done
		while(!(GET_BIT(TWCR,TWINT)));

		//check status of the bus
		if ((TWSR & STATUS_BITS_MASK)!=MSTR_RD_BYTE_WITH_ACK)
		{
			Local_Error = 	MstrReadByteWithAck;
		}
		else
		{
			//Put the data byte on the bus
			*copy_u8DataByte = TWDR;
		}
	}
	else
	{
		Local_Error= NULL_PTR;
	}

	return Local_Error;
}
void TWI_voidSendStopCond(void)
{
	//Set Stop cond bit
	SET_BIT(TWCR,TWSTO);

	//Clear interrupt flag to enable start action to happen
	SET_BIT(TWCR,TWINT);

}
