#ifndef ICU_INTERFACE_H
#define ICU_INTERFACE_H

typedef enum {
	Falling=0U,
	Rising
}Sense_Ctrl_t;

typedef enum {
	Enabled=0U,
	Disabled
}Interrupt_State_t;

typedef struct{
	Sense_Ctrl_t SenseCtrl;
	Interrupt_State_t Int_State;
}ICU_CFG_t;

uint8 ICU_u8Init(ICU_CFG_t* copy_pConfig);
uint8 ICU_u8SenseControl(Sense_Ctrl_t copy_u8SenseCtrl);
void ICU_voidEnableInt();
void ICU_voidDisableInt();
uint8 ICU_u8Get(uint32* copy_u8PeriodTime,uint32* copy_u8OnTime);

#endif
