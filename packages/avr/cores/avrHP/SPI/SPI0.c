
#ifdef SPCR0

#include "SPI0.h"

void SPI0_Init()
{
    OUT(SS0);    // Needed to become Master
    IN(MISO0);
    OUT(MOSI0);
    OUT(SCK0);

    SPCR0 = _SPIE | _SPE | _DORD | _MSTR | _CPOL | _CPHA | _SPR;
    SPSR0 = _SPI2X;
}

byte SPI0_Transfer(byte Data)
{
    SPDR0 = Data;
    while(!VAL(SPSR0,SPIF));
    return SPDR0;
}

byte SPI0_Access(byte Reg, byte Data)
{
    SPI0_Transfer(Reg);
    return SPI0_Transfer(Data);
}

void SPI0_Access_Burst(byte Reg, byte *DataWritePTR, byte *DataReadPTR, byte Size)
{
    SPI0_Transfer(Reg);
    while(Size--) *DataReadPTR++ = SPI0_Transfer(*DataWritePTR++);
}

#else
#warning No SPI0 support
#endif
