#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H


#define Periodic			0U
#define Once				1U

void PWM_voidSet(uint8 copy_u8PeriodTime,uint8 copy_u8OnTime);

uint8 PWM_u8Get(uint32* copy_pu8PeriodTime,uint32* copy_pu8OnTime);

uint8 Schedule_us(uint32 copy_u32Timer_us,uint8 copy_u8PeriodType,void (* copy_pvFuncPtr)(void));

#endif
