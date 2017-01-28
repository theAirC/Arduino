
#ifdef SPCR1

#include "SPI1.h"

void SPI1_Init()
{
    OUT(SS1);    // Needed to become Master
    IN(MISO1);
    OUT(MOSI1);
    OUT(SCK1);

    SPCR1 = _SPIE | _SPE | _DORD | _MSTR | _CPOL | _CPHA | _SPR;
    SPSR1 = _SPI2X;
}

byte SPI1_Transfer(byte Data)
{
    SPDR1 = Data;
    while(!VAL(SPSR1,SPIF));
    return SPDR1;
}

byte SPI1_Access(byte Reg, byte Data)
{
    SPI1_Transfer(Reg);
    return SPI1_Transfer(Data);
}

void SPI1_Access_Burst(byte Reg, byte *DataWritePTR, byte *DataReadPTR, byte Size)
{
    SPI1_Transfer(Reg);
    while(Size--) *DataReadPTR++ = SPI1_Transfer(*DataWritePTR++);
}

#else
#warning No SPI1 support
#endif
