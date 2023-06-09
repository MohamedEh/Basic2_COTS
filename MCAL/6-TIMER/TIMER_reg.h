#ifndef TIMER_REG_H
#define TIMER_REG_H

#define TCCR0				*((volatile uint8*) 0x53)			//Timer/Counter Control Register for timer 0
#define WGN00				6U									//This bit control the counting sequence of the counter 0
#define WGN01				3U									//This bit control the counting sequence of the counter 0
#define CS00				0U									//This bit select the clock source for the timer 0
#define CS01				1U									//This bit select the clock source for the timer 0
#define CS02				2U									//This bit select the clock source for the timer 0


#define TCNT0				*((volatile uint8*) 0x52)			//Timer/Counter Register for controlling the Preload value for timer 0

#define	TIMSK				*((volatile uint8*) 0x59)			//Timer/Counter Interrupt Mask Register for enabling Interrupt
#define TOIE0				0U									//This bit control the Timer/Counter0 Overflow Interrupt Enable

#define	TIFR				*((volatile uint8*) 0x59)			//Timer/Counter Interrupt Flag Register for Flag controlling
#define TOV0				0U									//This bit control the Timer/Counter0 Overflow Flag


#endif
