#ifndef _SPI_INTERFACE_H
#define _SPI_INTERFACE_H

typedef enum
{
    MASTER,
    SLAVE
}SPI_NodeType_t;

void SPI_voidInit(uint8 copy_u8Type);
uint8 SPI_u8Transceive (uint8 copy_u8Data);
#endif // _SPI_CFG_H
