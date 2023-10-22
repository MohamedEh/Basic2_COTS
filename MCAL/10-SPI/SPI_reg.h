#ifndef _SPI_REG_H
#define _SPI_REG_H

#define SPCR            *((volatile uint8*)0x2D)
#define SPIE            7U
#define SPE             6U
#define DORD            5U
#define MSTR            4U
#define CPOL            3U
#define CPHA            2U
#define SPR1            1U
#define SPR0            0U

#define SPSR            *((volatile uint8*)0x2E)
#define SPIF            7U
#define WCOL            6U
#define SPI2X           0U

#define SPDR            *((volatile uint8*)0x2F)

#endif // _SPI_CFG_H
