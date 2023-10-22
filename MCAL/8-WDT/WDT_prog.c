#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "WDT_reg.h"
#include "WDT_interface.h"
#include "WDT_prv.h"

void WDT_voidSET(uint8 copy_u8SleepTime){
	
	//Enable WatchDog
	SET_BIT(WDTCR,WDE);
	
	//Set Sleep time
	WDTCR &= PRESCALER_MASK;
	WDTCR |= copy_u8SleepTime;
}

void WDT_voidDisable(){
	
	WDTCR = (1<<WDE)|(1<<WDTOE);
	WDTCR = 0;
}

void WDT_voidReset(){
	
	__asm volatile ("WDR");


}
