#include "STD_TYPES.h"

#include "MAP.h"

sint32 MAP(sint32 InputRangeMin, sint32 InputRangeMax, sint32 OutputRangeMin, sint32 OutputRangeMax, sint32 InputValue){
	
	sint32 OutputValue;
	
	OutputValue = ((((OutputRangeMax-OutputRangeMin)*(InputValue-InputRangeMin))/(InputRangeMax-InputRangeMin))+OutputRangeMin);
	
	return OutputValue;
}