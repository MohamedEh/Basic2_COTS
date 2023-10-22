#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"

#include "KERNEL_prv.h"
#include "KERNEL_interface.h"
#include "KERNEL_cfg.h"
#include "RTOS_TIMER_interface.h"

static Task_t SystemTasks[TASK_NUM]={{0}};

void RTOS_voidStart(void)
{
	RTOS_TIMER1_u8Init(Scheduler);
	RTOS_TIMER1_voidSetCompVal(250);

}

uint8 RTOS_u8CreateTask(uint8 copy_u8Priority, uint16 copy_u16Periodicity, void(*copy_pvFunc)(void),uint16 copy_u8FirstDelay)
{
	uint8 Local_u8Error_State=OK;
	if(copy_pvFunc!=NULL)
	{	if(SystemTasks[copy_u8Priority].Periodicity==0)
	{
		SystemTasks[copy_u8Priority].Periodicity=copy_u16Periodicity;
		SystemTasks[copy_u8Priority].TaskFunc=copy_pvFunc;
		SystemTasks[copy_u8Priority].Suspend=0;
		SystemTasks[copy_u8Priority].First_Delay=copy_u8FirstDelay
	}
	else
	{
		Local_u8Error_State=NOK;
	}
	}
	else
	{
		Local_u8Error_State=NULL_PTR;
	}
	return Local_u8Error_State;
}

uint8 RTOS_u8SuspendTask(uint8 copy_u8Priority)
{
	uint8 Local_u8Error_State=OK;
	if((copy_u8Priority<TASK_NUM)&&(SystemTasks[copy_u8Priority].Periodicity!=0))
	{
		SystemTasks[copy_u8Priority].Suspend=1;
	}
	else
	{
		Local_u8Error_State=NOK;
	}

	return Local_u8Error_State;
}
void RTOS_u8ResumeTask(uint8 copy_u8Priority)
{

	if(SystemTasks[copy_u8Priority].Suspend==1)
	{
		SystemTasks[copy_u8Priority].Suspend=0;
	}

}
uint8 RTOS_u8DeleteTask(uint8 copy_u8Priority)
{
	uint8 Local_u8Error_State=OK;


	if(SystemTasks[copy_u8Priority].Periodicity!=0)
	{
		SystemTasks[copy_u8Priority].Periodicity=0;
		SystemTasks[copy_u8Priority].TaskFunc=0;
	}
	else
	{
		Local_u8Error_State=NOK;
	}

	return Local_u8Error_State;

}


static void Scheduler (void)
{

	for(uint8 Local_u8Iterator=0; Local_u8Iterator<TASK_NUM; Local_u8Iterator++ )
	{
		if((SystemTasks[Local_u8Iterator].First_Delay==0)&&(SystemTasks[Local_u8Iterator].Suspend==0)&&(SystemTasks[Local_u8Iterator].Periodicity!=0))
		{
			//Invoke the task function
			SystemTasks[Local_u8Iterator].TaskFunc();
			//make first delay = periodicity
			SystemTasks[Local_u8Iterator].First_Delay=SystemTasks[Local_u8Iterator].Periodicity-1;
		}
		else
		{
			SystemTasks[Local_u8Iterator].First_Delay--;
		}
	}

}
