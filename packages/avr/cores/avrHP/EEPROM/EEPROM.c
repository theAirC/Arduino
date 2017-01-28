
#ifdef EEAR

byte EEPROM_Read(u16 addr)
{
    while (VAL(EECR, EEPE));
    EEAR = addr;
    EECR = (1 << EERE);
    return EEDR;
}

void EEPROM_Write(u16 addr, byte data)
{
    while (VAL(EECR, EEPE));
    
    // The following must not be interrupted,
    // so we keep the SREG, disable interrupts,
    // and then restore it.
    byte t = SREG;
    SREG = 0; // cli()
    EEAR = addr;
    EEDR = data;
    EECR = (1 << EEMPE);
    SBI(EECR, EEPE);
    SREG = t;
}

void EEPROM_ReadMany(u16 addr, void *data, u8 size)
{
    byte *array = data;
    for (byte i = 0; i < size; i++) array[i] = EEPROM_Read(addr++);
}

void EEPROM_WriteMany(u16 addr, const void *data, u8 size)
{
    const byte *array = data;
    for (byte i = 0; i < size; i++) EEPROM_Write(addr++, array[i]);
}

#else
#warning No EEPROM support
#endif
