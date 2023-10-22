#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H


typedef enum{
	DISABLE=0U,
	EVEN=2U,
	ODD
}USART_ParityCfg_t;

typedef enum{
	ONE_BIT=0U,
	TWO_BIT
}USART_StopBitCfg_t;

typedef enum{
	FIVE_BIT=0U,
	SIX_BIT,
	SEVEN_BIT,
	EIGHT_BIT,
	NINE_BIT
}USART_CharacterSizeCfg_t;

typedef enum{
	ASYNCHRONOUS=0U,
	SYNCHRONOUS
}USART_ClockModeCfg_t;

typedef enum{
	RISE_TX_FALL_RX=0U,
	FALL_TX_RISE_RX
}USART_ClockPolarityCfg_t;

typedef enum{
	DISABLED=0U,
	ENABLED
}USART_IntCfg_t;

typedef enum{
	_2400_bps=0U,
	_4800_bps,
	_9600_bps,
	_14_4k_bps,
	_19_2k_bps,
	_28_8k_bps,
	_38_4k_bps,
	_57_6k_bps,
	_76_8k_bps,
	_115_2k_bps,
	_230_4k_bps,
	_250k_bps,
	_0_5M_bps,
	_1M_bps,
}USART_BaudRateCfg_t;

typedef struct{
	USART_ParityCfg_t	Parity;
	USART_StopBitCfg_t	StopBit;
	USART_CharacterSizeCfg_t	Charactersize;
	USART_ClockModeCfg_t	ClockMode;
	USART_ClockPolarityCfg_t ClockPolarity;
	USART_IntCfg_t	Int;
	USART_BaudRateCfg_t	BaudRate;
}USART_InitCfg_t;

uint8 USART_u8Init(const USART_InitCfg_t* copy_pInitCfg);
uint8 USART_voidSendByte(uint8 copy_u8Data);
uint8 USART_u8ReceiveByte(uint8* copy_u8Data);
void USART_voidEnableInt(void);
void USART_voidDisableInt(void);
uint8 USART_u8SendBufferSynch(uint8* copy_pu8Buffer, uint8 copy_u8Length);
uint8 USART_u8ReceiveBufferSynch(uint8* copy_pu8Buffer, uint8 copy_u8Length);
uint8 USART_u8SendBufferASynch(uint8* copy_pu8Buffer, uint8 copy_u8Length,void (*copy_pvNotificationFunc)(void));
uint8 USART_u8ReceiveBufferASynch(uint8* copy_pu8Buffer, uint8 copy_u8Length,void (*copy_pvNotificationFunc)(void));

#endif
