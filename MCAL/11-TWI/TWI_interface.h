#ifndef _TWI_INTERFACE_H
#define _TWI_INTERFACE_H

typedef enum
{
	NoError,
	NULL_PTR_ERR,
	StartCondErr,
	RepStartErr,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MstrWriteByteWithAck,
	MstrReadByteWithAck
}TWI_ErrorStatus_t;

void TWI_voidMasterInit(uint8 copy_u8Address);
void TWI_voidSlaveInit(uint8 copy_u8Address);
TWI_ErrorStatus_t TWI_voidSendStartCond(void);
TWI_ErrorStatus_t TWI_voidSendRepeatedStart(void);
TWI_ErrorStatus_t TWI_voidSendSlaveAddWithWrite(uint8 copy_u8Address);
TWI_ErrorStatus_t TWI_voidSendSlaveAddWithRead(uint8 copy_u8Address);
TWI_ErrorStatus_t TWI_voidMasterWriteDataByte(uint8 copy_u8DataByte);
TWI_ErrorStatus_t TWI_voidMasterReadDataByte(uint8* copy_u8DataByte);
void TWI_voidSendStopCond(void);


#endif
