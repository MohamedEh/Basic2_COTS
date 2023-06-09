#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#define ACTIVE_HIGH		1u
#define ACTIVE_LOW		2u

typedef struct{
	DIO_Port_t	LED_tPort;
	DIO_Pin_t	LED_tPin;
	uint8	LED_u8ActivityType;
}LED_Config_t;

uint8 LED_u8SetOn(const LED_Config_t *copy_LED_pData);
uint8 LED_u8SetOff(const LED_Config_t *copy_LED_pData);
uint8 LED_u8SetToggle(const LED_Config_t *copy_LED_pData);


#endif
