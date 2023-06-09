#ifndef SW_INTERFACE_H
#define SW_INTERFACE_H

#define PULL_UP			1u
#define PULL_DOWN		2u


typedef struct{
	uint8 SW_u8PullType;
	DIO_Port_t SW_tPort;
	DIO_Pin_t SW_tPin;

}SW_Config_t;

uint8 SW_u8GetState(const SW_Config_t* copy_SW_pData,uint8 *copy_u8pSWState); // If Return Value is 1 -> Pressed ,0 -> Released

#endif
