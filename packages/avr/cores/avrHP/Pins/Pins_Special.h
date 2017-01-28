// Extension of "Pins.h"

#pragma once

#if defined(__AVR_ATmega328PB__)

#define MISO0 B4
#define MOSI0 B3
#define SCK0  B5
#define SS0   B2

#define MISO1 C0
#define MOSI1 E3
#define SCK1  C1
#define SS1   E2


#define SDA0  C4
#define SCL0  C5

#define SDA1  E0
#define SCL1  E1

#elif defined(__AVR_ATmega328P__)

#define MISO  B4
#define MOSI  B3
#define SCK   B5
#define SS    B2

#define SDA   C4
#define SCL   C5

#endif
