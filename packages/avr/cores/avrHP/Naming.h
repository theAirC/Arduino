#pragma once

// General #includes, typedefs, consts and macros

    #include <stdint.h>

    #define _JOIN(x,y)   x##y
    #define _JOIN3(x,y)  x##y##z
    #define JOIN(x,y)    _JOIN(x,y)
    #define JOIN3(x,y,z) _JOIN3(x,y,z)

    typedef int8_t  s8;
    typedef int16_t s16;
    typedef int32_t s32;
    typedef int64_t s64;

    typedef uint8_t  u8;
    typedef uint16_t u16;
    typedef uint32_t u32;
    typedef uint64_t u64;

    typedef u8 byte;

    #define SBI(r,b)    (r |=  (1 << (b)))
    #define CBI(r,b)    (r &= ~(1 << (b)))
    #define VAL(r,b)    (r &   (1 << (b)))

    #define asize(x)    (sizeof(x)/sizeof(x[0]))

// AVR specific

    #include <avr/io.h>

    #ifndef F_CPU
    #warning "Using default F_CPU (16MHz)"
    #define F_CPU    16000000UL
    #endif

    #define NOP()  asm volatile ("nop"::);      // delays by 1 cycle
    #define NOP2() asm volatile ("rjmp .+0"::); // delays by 2 cycles
    #define LPM(x) pgm_read_byte(&(x))
