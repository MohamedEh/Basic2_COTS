#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define FALLING_EDGE			1U
#define RISING_EDGE				2U
#define ON_CHANGE				3U
#define LOW_LEVEL				4U

typedef enum{
	INT0=0,
	INT1,
	INT2
}EXTI_IntNum_t;

void EXTI_voidInit(void);

uint8 EXTI_u8SetSenseCtrl(EXTI_IntNum_t copy_IntNum, uint8 copy_SenseCtrl);

uint8 EXTI_u8IntEnable(EXTI_IntNum_t copy_IntNum);

uint8 EXTI_u8IntDisable(EXTI_IntNum_t copy_IntNum);

uint8 EXTI_u8SetCallBack(EXTI_IntNum_t copy_IntNum,void(*copy_pfFuncPtr)(void));

#endif
