#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DAC_interface.h"
#include "DIO_interface.h"
#include "DAC_cfg.h"

void DAC_voidSetAnalogVolt (uint16 copy_u16Volt){
	uint16 Local_u16Step = DAC_u16RefVolt/DAC_u16Resolution;
	uint8 Local_u8Digital = (uint8)(copy_u16Volt/Local_u16Step);
	DIO_u8SetPortValue(DAC_u8Port,Local_u8Digital);
	
}
