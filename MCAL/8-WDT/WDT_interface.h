#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

typedef enum {
	SLEEP_16ms=0U,
	SLEEP_32ms,
	SLEEP_65ms,
	SLEEP_130ms,
	SLEEP_260ms,
	SLEEP_520ms,
	SLEEP_1000ms,
	SLEEP_2100ms
}WDT_PrescalerCfg_t;

void WDT_voidSET(uint8 copy_u8SleepTime);

void WDT_voidDisable();

void WDT_voidReset();

#endif
