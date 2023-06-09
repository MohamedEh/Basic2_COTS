#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

#define ANODE		1u
#define CATHODE		2u
#define ETA_KIT		3u


typedef struct{
	uint8 SSD_u8Type;
	DIO_Port_t SSD_tPort;
	DIO_Pin_t SSD_tPin;
	DIO_Port_t SSD_tEPort;
	DIO_Pin_t SSD_tEPin;
}SSD_Config_t;

uint8 SSD_u8SetNumber(const SSD_Config_t* copy_SSD_pData,uint8 copy_u8Number);
uint8 SSD_u8Enable(const SSD_Config_t* copy_SSD_pData);
uint8 SSD_u8Disable(const SSD_Config_t* copy_SSD_pData);
#endif
