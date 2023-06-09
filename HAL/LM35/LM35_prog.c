#include "STD_TYPES.h"
#include "BIT_MATH.h"


sint16 LM35_s16GetTemp(uint16 copy_u16DigitalReading){
	
	sint16 Local_s16TempVal;
	
	Local_s16TempVal = (sint16)((copy_u16DigitalReading*LM35_RefVolt)/(LM35_Resolution*Conversion));
	
	return Local_s16TempVal;
}
