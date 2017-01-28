#pragma once

void delayMicros(u16 us)
{
    // Must be inlined and optimized for accuracy.

    byte cpus = rounddiv(F_CPU, 1000000); // cycles per microsecond
    
    while(--us) {
        if (isOdd(cpus)) {
            NOP();
            cpus--;
        }
        switch (cpus) {
            case 24: NOP2();
            case 22: NOP2();
            case 20: NOP2();
            case 18: NOP2();
            case 16: NOP2();
            case 14: NOP2();
            case 12: NOP2();
            case 10: NOP2();
            case  8: NOP2();
            case  6: NOP2();
        }
    }
}

void delayExact(u16 us)
{
    // Must be inlined and optimized for accuracy.
    // Depending on F_CPU, if the parameter [us] is no compile-time constant,
    // it will take significantly longer than expected.
    // F_CPUs that are a 2^n multiple of 4MHz are recommended in that case.
    // e.g. 4 MHz, 8 MHz, 16 MHz, 32 MHz ...

    u16 repeats = rounddiv(F_CPU, 4000000UL) * us;
    
    s8 cycles = 0;

    //cycles -= 2; // to possibly? push the 2 registers taken by cycles
    cycles -= 2;   // to initialize the 2 registers taken by cycles
    cycles += 1;   // because when last branch exits, it takes 1 cycle not 2
    //cycles -= 2; // to possibly? pop  the 2 registers taken by cycles

    if (cycles < 0) {
        cycles = -cycles;

        repeats -= upperdiv(cycles, 4);

        cycles = -uppermod(cycles, 4);
    }

    switch (cycles) {
        case 3: NOP2();NOP(); break;
        case 2: NOP2();       break;
        case 1: NOP();        break;
    }

    __asm__ __volatile__ (
        "1: sbiw %0,1" "\n\t"                         // 2 cycles
        "brne 1b" : "=w" (repeats) : "0" (repeats)    // 2 cycles - 1 in the last loop
    );
}

void delay4C(u16 repeats)
{
    // Must be inlined for perfect accuracy.
    // Will take 2 cycles to init repeats - 1 in the end = 1 more cycle than expected.

    __asm__ __volatile__ (
        "1: sbiw %0,1" "\n\t"                         // 2 cycles
        "brne 1b" : "=w" (repeats) : "0" (repeats)    // 2 cycles - 1 in the last loop
    );
}
