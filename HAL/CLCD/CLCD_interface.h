# ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

void CLCD_voidSendCommand(uint8 copy_u8Command);
void CLCD_voidSendData(uint8 copy_u8Data);
void CLCD_voidInit(void);

void CLCD_voidGoToXY(uint8 copy_u8XPos, uint8 copy_YPos);
uint8 CLCD_u8WriteSpecialCharacter(uint8 copy_u8PatternNumber,uint8 copy_pu8PatternArr[],uint8 copy_u8XPos,uint8 copy_u8YPos);
void CLCD_voidSendNumber(sint32 copy_s32Number );
uint8 CLCD_u8SendString(uint8 const copy_u8String[]);
#endif
