#pragma once

/* Settings */
#ifndef SPI_Settings
#define SPI_Settings
    #define SPI_MASTER      1   // Master/Slave mode | Format: (0|1) -> {Slave|Master}
    #define SPI_ORDER       0   // Data order        | Format: (0|1) -> (send) {MSB|LSB} (first)

    // Clock
    #define SPI_POLARITY    0   // Clock Polarity    | Format: (0|1) -> (SCK is) {Low|High} (when idle)
    #define SPI_PHASE       0   // Clock Phase       | Format: (0|1) -> (sample at) {Leading|Trailing} (edge)
    #define SPI_DIVIDER    64   // SPI Speed = F_CPU / Divider | Format: (2|4|8|16|32|64|128)
#endif

/* Config */

    #undef SPIx_MASTER
    #undef SPIx_ORDER
    #undef SPIx_POLARITY
    #undef SPIx_PHASE
    #undef SPIx_DIVIDER

    #define SPIx_MASTER     SPI_MASTER
    #define SPIx_ORDER      SPI_ORDER
    #define SPIx_POLARITY   SPI_POLARITY
    #define SPIx_PHASE      SPI_PHASE
    #define SPIx_DIVIDER    SPI_DIVIDER

    #include "SPIx_Config.h"
