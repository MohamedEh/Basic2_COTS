#ifndef KERNEL_PRIVATE_H
#define	KERNEL_PRIVATE_H


typedef struct
{
	uint16 Periodicity;
	uint16 First_Delay;
	void (*TaskFunc)(void);
	uint8 Suspend;

}Task_t;

static void Scheduler (void);

#endif
