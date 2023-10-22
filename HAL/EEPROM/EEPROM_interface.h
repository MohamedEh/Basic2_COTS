#ifndef _EEPROM_INTERFACE_H
#define _EEPROM_INTERFACE_H


uint8 EEPROM_u8Init(void);

uint8 EEPROM_u8WriteByte(uint16 copy_u16Address,uint8 copy_u8Data);

uint8 EEPROM_u8ReadByte(uint16 copy_u16Address,uint8* copy_u8pdata);
#endif
