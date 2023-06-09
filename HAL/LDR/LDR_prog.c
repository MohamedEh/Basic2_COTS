#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MAP.h"

#include "LDR_interface.h"
#include "LDR_prv.h"

uint8 LDR_u8GetLightLevel(uint16 copy_u16DigitalReading){
	
	uint8 Local_OutputReading;
	
	Local_OutputReading=(uint8)MAP(InputMin, InputMax, OutputMin, OutputMax, copy_u16DigitalReading);
	
	return Local_OutputReading;
	
}