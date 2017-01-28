
#ifdef SPCR

#include "SPI.h"

void SPI_Init()
{
    OUT(SS);    // Needed to become Master
    OUT(SCK);
    OUT(MOSI);
    IN(MISO);

    SPCR = _SPIE | _SPE | _DORD | _MSTR | _CPOL | _CPHA | _SPR;
    SPSR = _SPI2X;
}

byte SPI_Transfer(byte Data)
{
    SPDR = Data;
    while(!VAL(SPSR,SPIF));
    return SPDR;
}

byte SPI_Access(byte Reg, byte Data)
{
    SPI_Transfer(Reg);
    return SPI_Transfer(Data);
}

void SPI_Access_Burst(byte Reg, byte *DataWritePTR, byte *DataReadPTR, byte Size)
{
    SPI_Transfer(Reg);
    while(Size--) *DataReadPTR++ = SPI_Transfer(*DataWritePTR++);
}

#else
#warning No SPI support
#endif
