#ifndef EXTI_REG_H
#define EXTI_REG_H

#define EXTI_u8GICR				(*((volatile uint8*)0x5B))	

#define EXTI_u8MCUCR			(*((volatile uint8*)0x55))

#define EXTI_u8MCUCSR			(*((volatile uint8*)0x54))

#define MCUCR_ISC00				0u	//Int. Sense Ctrl 0 bit 0
#define MCUCR_ISC01				1u	//Int. Sense Ctrl 0 bit 1
#define MCUCR_ISC10				2u	//Int. Sense Ctrl 1 bit 0
#define MCUCR_ISC11				3u	//Int. Sense Ctrl 1 bit 1

#define GICR_INIT1				7u	//Int. 1
#define GICR_INIT0				6u	//Int. 0
#define GICR_INIT2				5u	//Int. 2

#define MCUCSR_ISC2				6U	//Int. Sense Ctrl 2


#endif
