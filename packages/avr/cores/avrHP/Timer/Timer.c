
#include "Timer.h"

/* Consult the Datasheet before using. */

byte Timer_TCCRA(Timer_OutCompMatch outputA, Timer_OutCompMatch outputB, Timer_Mode mode) {
    return (outputA << 6) | (outputB << 4) | (mode & 0x03);
}

byte Timer_TCCRB(Timer_Mode mode, Timer_Clock clock) {
    return ((mode & 0x0C) << 1) | (clock);
}

byte Timer_TIMSK(byte Interrupt_CompMatch_B, byte Interrupt_CompMatch_A, byte Interrupt_Overflow) {
    return (Interrupt_CompMatch_B << 2) | (Interrupt_CompMatch_A << 1) | (Interrupt_Overflow);
}
