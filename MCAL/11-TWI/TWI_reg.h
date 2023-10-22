#ifndef _TWI_REG_H
#define _TWI_REG_H

#define TWBR		*((volatile uint8*)0x20)
#define TWBR0		0U
#define TWBR1		1U
#define TWBR2		2U
#define TWBR3		3U
#define TWBR4		4U
#define TWBR5		5U
#define TWBR6		6U
#define TWBR7		7U

#define TWCR		*((volatile uint8*)0x56)
#define TWIE		0U
#define TWEN		2U
#define TWWC		3U
#define TWSTO		4U
#define TWSTA		5U
#define TWEA		6U
#define TWINT		7U

#define TWSR		*((volatile uint8*)0x21)
#define TWPS0		0U
#define TWPS1		1U
#define TWS3		3U
#define TWS4		4U
#define TWS5		5U
#define TWS6		6U
#define TWS7		7U

#define TWDR		*((volatile uint8*)0x23)
#define TWD0		0U
#define TWD1		1U
#define TWD2		2U
#define TWD3		3U
#define TWD4		4U
#define TWD5		5U
#define TWD6		6U
#define TWD7		7U

#define TWAR		*((volatile uint8*)0x22)
#define TWGCE		0U
#define TWA0		1U
#define TWA1		2U
#define TWA2		3U
#define TWA3		4U
#define TWA4		5U
#define TWA5		6U
#define TWA6		7U


#endif