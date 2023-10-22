#include "STD_TYPES.h"
#include "Err_Type.h"
#include "BIT_MATH.h"

#include "SPI_reg.h"
#include "SPI_interface.h"

void SPI_voidInit(uint8 copy_u8Type)
{
    if(copy_u8Type==MASTER)
    {
        //Set Master Bit
        SET_BIT(SPCR,MSTR);

        //Set Clock to fosc/4
        CLR_BIT(SPCR,SPR0);
        CLR_BIT(SPCR,SPR1);
        CLR_BIT(SPSR,SPI2X);

    }
    else if(copy_u8Type==SLAVE)
    {
        //CLR Master Bit
        CLR_BIT(SPCR,MSTR);
    }

    else
    {
        //Error
    }
    //Enable SPI
    SET_BIT(SPCR,SPE);
}
uint8 SPI_u8Transceive (uint8 copy_u8Data)
{
    SPDR=copy_u8Data;
    while(!(GET_BIT(SPSR,SPIF)));
    return SPDR;
}
