#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include "RTOS_TIMER_reg.h"

//typedef enum {
//	TIMER0=0U,
//	TIMER1,
//	TIMER2
//}TIMER_TimerNum_t;
//
//typedef enum {
//	NO_CLCK=0U,
//	CLCK_1,
//	CLCK_8,
//	CLCK_64,
//	CLCK_256,
//	CLCK_1024,
//	EXT_FALLING,
//	EXT_RISING
//}TMR_PRESCALER_t;
//
//typedef enum{
//	TMR0_OC_INT=0U,
//	TMR0_OVF_INT,
//	TMR1_ICU_INT,
//	TMR1_OC_A_INT,
//	TMR1_OC_B_INT,
//	TMR1_OVF_INT,
//	TMR2_OC_INT,
//	TMR2_OVF_INT
//}TMR_INT_t;
//
//typedef enum {
//	NORMAL=0U,
//	CTC,
//	FAST_PWM,
//	PH_CORR
//}TMR0_2_WFGMODE_t;
//
//typedef enum {
//	OPTION0=0U,									/*Timer0_2:	  Normal & CTC :	Normal
//															  Fast PWM :		Normal
//															  Phase correct:	Normal
//												  Timer1:	  Normal & CTC :	Normal
//												              Fast PWM :		Normal
//												              Phase correct:	Normal
//												  		  */
//	OPTION1,									/*Timer0_2:   Normal & CTC :	Toggle
//												  			  Fast PWM :		Reserved
//												  			  Phase correct:	Reserved
//												  Timer1:	  Normal & CTC :	Toggle
//												  	  	  	  Fast PWM :		Toggle OC1A only in Mode 15,Normal for other Modes
//												  	  	  	  Phase correct:	Toggle OC1A only in Mode 9,14,Normal for other Modes*/
//
//	OPTION2,									/*Timer0_2:   Normal & CTC :	Clear
//												  			  Fast PWM :		clear on compare set on top
//												  			  Phase correct:	clear on compare on upcounting,set on compare on downcounting
//												  Timer1:	  Normal & CTC :	Clear
//												  	  	  	  Fast PWM :		clear on compare set on top
//												  	  	  	  Phase correct:	clear on compare on upcounting,set on compare on downcounting*/
//
//	OPTION3 									/*Timer0_2:   Normal & CTC :	Set
//												  			  Fast PWM :		set on compare compare on top
//												  			  Phase correct:	set on compare on upcounting,clear on compare on downcounting
//												  Timer1:	  Normal & CTC :	Set
//												  	  	  	  Fast PWM :		set on compare compare on top
//												  	  	  	  Phase correct:	set on compare on upcounting,clear on compare on downcounting*/
//
//}TMR_OCMODE_t;
//
//typedef struct {
//	TMR0_2_WFGMODE_t WFG_MODE;
//
//	TMR_OCMODE_t OC_MODE;
//
//	TMR_PRESCALER_t PRESCALER;
//
//}TMR0_2_CFG_t;
//
//typedef enum {
//	NORM=0U,
//	PH_CORR_8_BIT,
//	PH_CORR_9_BIT,
//	PH_CORR_10_BIT,
//	CTC_OCR1A,
//	FAST_PWM_8_BIT,
//	FAST_PWM_9_BIT,
//	FAST_PWM_10_BIT,
//	PH_FREQ_CORR_ICR1,
//	PH_FREQ_CORR_OCR1A,
//	PH_CORR_ICR1,
//	PH_CORR_OCR1A,
//	CTC_ICR1,
//	FAST_PWM_ICR1=14U,
//	FAST_PWM_OCR1A,
//}TMR1_WFGMODE_t;
//
//
//typedef struct {
//	TMR1_WFGMODE_t WFG_MODE;
//
//	TMR_OCMODE_t OC_MODE;
//
//	TMR_PRESCALER_t PRESCALER;
//
//}TMR1_CFG_t;


//#define TIMER0_OVR_REG			TCNT0
//
//#define TIMER0_CMP_REG			OCR0
//
//#define TIMER1_TOP_VALUE		ICR1
//
//#define TIMER1_OVR_REG			TCNT1
//
//#define TIMER1A_CMP_REG			OCR1A
//
//#define TIMER1B_CMP_REG			OCR1B
//
//#define TIMER2_OVR_REG			TCNT2
//
//#define TIMER2_CMP_REG			OCR2



uint8 RTOS_TIMER1_u8Init(void(*copy_pvFunctionPtr)(void));




void RTOS_TIMER1_voidSetCompVal(uint8 copy_u8CompVal);



//uint8 TIMER_voidIntEnable(TMR_INT_t copy_u8IntType,void(*copy_pvFunctionPtr)(void));

//uint8 TIMER_voidIntDisable(TMR_INT_t copy_u8IntType);
#endif
