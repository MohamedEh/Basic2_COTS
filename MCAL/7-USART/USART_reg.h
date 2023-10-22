#ifndef USART_REG_H
#define USART_REG_H

#define UDR				*((volatile uint8*)0x2C)
		
#define UCSRA			*((volatile uint8*)0x2B)
#define RXC				7U							//Receive complete flag
#define TXC				6U							//Transmit
#define UDRE			5U
#define FE				4U
#define DOR				3U
#define PE				2U
#define U2X				1U
#define MPCM			0U

#define UCSRB			*((volatile uint8*)0x2A)
#define RXCIE			7U
#define TXCIE			6U
#define UDRIE			5U
#define RXEN			4U
#define TXEN			3U
#define UCSZ2			2U
#define RXB8			1U
#define TXB8			0U

#define UCSRC			*((volatile uint8*)0x40)
#define URSEL			7U 							/*Register select*/
#define UMSEL			6U                          /*Mode select*/
#define UPM1			5U                          /*Parity mode select bit 1*/
#define UPM0			4U                          /*Parity mode select bit 0*/
#define USBS			3U                          /*Stop bit select*/
#define UCSZ1			2U                          /*Character size bit 1*/
#define UCSZ0			1U                          /*Character size bit 0*/
#define UCPOL			0U                          /*Clock polarity*/

#define UBRRH			*((volatile uint8*)0x40)
#define UBRRL			*((volatile uint8*)0x29)

#endif
