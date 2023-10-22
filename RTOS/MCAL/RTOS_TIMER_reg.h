#ifndef TIMER_REG_H
#define TIMER_REG_H

#define TCCR0				*((volatile uint8*) 0x53)			//Timer/Counter Control Register for timer 0
#define WGN00				6U									//This bit control the counting sequence of the counter 0
#define WGN01				3U									//This bit control the counting sequence of the counter 0
#define CS00				0U									//This bit select the clock source for the timer 0
#define CS01				1U									//This bit select the clock source for the timer 0
#define CS02				2U									//This bit select the clock source for the timer 0
#define COM00				4U									//This bit used for output mode in ctc mode
#define COM01				5U									//This bit used for output mode in ctc mode

#define TCNT0				*((volatile uint8*) 0x52)			//Timer/Counter Register for controlling the Preload value for timer 0

#define OCR0				*((volatile uint8*) 0x5C)			//Output Compare Register for control compare value in case of ctc mode

#define	TIMSK				*((volatile uint8*) 0x59)			//Timer/Counter Interrupt Mask Register for enabling Interrupt
#define TOIE0				0U									//This bit control the Timer/Counter0 Overflow Interrupt Enable
#define OCIE0				1U									//This bit control the Timer/Counter0 CTC Interrupt Enable

#define	TIFR				*((volatile uint8*) 0x59)			//Timer/Counter Interrupt Flag Register for Flag controlling
#define TOV0				0U									//This bit control the Timer/Counter0 Overflow Flag
#define ICF1				5U

#define TCCR1A				*((volatile uint8*) 0x4F)
#define COM1A1				7U
#define COM1A0				6U
#define WGM10				0U
#define WGM11				1U

#define TCCR1B				*((volatile uint8*) 0x4E)
#define WGM12				3U
#define WGM13				4U
#define CS12				2U									//This bit select the clock source for the timer 1
#define CS11				1U									//This bit select the clock source for the timer 1
#define CS10				0U
#define ICNC1				7U									//This bit is used for input capture noise canceler for timer1
#define ICES1				6U									//This bit is used for  Input Capture Edge Select for timer1

#define OCR1A				*((volatile uint16*) 0x4A)

#define OCR1B				*((volatile uint16*) 0x48)

#define ICR1				*((volatile uint16*) 0x46)

#define TCNT1				*((volatile uint16*) 0x4C)

#define TOIE1				2U									//This bit control the Timer/Counter1 Overflow Interrupt Enable
#define OCIE1A				4U									//This bit control the Timer/Counter1 Interrupt Enable
#define OCIE1B				3U									//This bit control the Timer/Counter1 Interrupt Enable
#define TOV1				2U									//This bit control the Timer/Counte1 Overflow Flag
#define TICIE1				5U									//This bit control the Timer/Counte1 Input Capture Interrupt Enable

#define TCCR2				*((volatile uint8*) 0x45)			//Timer/Counter Control Register for timer 2
#define WGN20				6U									//This bit control the counting sequence of the counter 2
#define WGN21				3U									//This bit control the counting sequence of the counter 2
#define CS20				0U									//This bit select the clock source for the timer 2
#define CS21				1U									//This bit select the clock source for the timer 2
#define CS22				2U									//This bit select the clock source for the timer 2
#define COM20				4U									//This bit used for output mode in ctc mode
#define COM21				5U									//This bit used for output mode in ctc mode

#define TCNT2				*((volatile uint8*) 0x44)			//Timer/Counter Register for controlling the Preload value for timer 2

#define OCR2				*((volatile uint8*) 0x43)			//Output Compare Register for control compare value in case of ctc mode

#define ASSR				*((volatile uint8*) 0x42)			//Asynchronous Operation Register

#define TOIE2				6U									//This bit control the Timer/Counter0 Overflow Interrupt Enable
#define OCIE2				7U									//This bit control the Timer/Counter0 CTC Interrupt Enable

#define TOV2				6U									//This bit control the Timer/Counter0 Overflow Flag


#endif
