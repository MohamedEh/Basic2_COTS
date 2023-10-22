#ifndef KERNEL_INTERFACE_H
#define	KERNEL_INTERFACE_H

void RTOS_voidStart(void);
uint8 RTOS_u8CreateTask(uint8 copy_u8Priority, uint16 copy_u16Periodicity, void(*copy_pvFunc)(void),uint16 copy_u8FirstDelay);
uint8 RTOS_u8SuspendTask(uint8 copy_u8Priority);
void RTOS_u8ResumeTask(uint8 copy_u8Priority);
uint8 RTOS_u8DeleteTask(uint8 copy_u8Priority);

#endif
