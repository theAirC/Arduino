#pragma once

#include "USART_Common.h"

/* Settings */
#ifndef USART0_Settings
#define USART0_Settings
    #define USART0_BAUD   9600           // Baudrate in bits per second

    #define USART0_RX_EN     1           // Receive pin state        Format: (0|1) -> {Disabled|Enabled}
    #define USART0_TX_EN     1           // Transmit pin state       Format: (0|1) -> {Disabled|Enabled}

    #define USART0_SYNC      0           // Synchronization          Format: (0|1) -> {Asynchronous|Synchronous}
    // Specify polarity when in Synchronous mode.
    #define USART0_POLARITY  0           // Polarity                 Format: (0|1) -> {Normal|Inverted}

    // Change the following under conditions, it doubles the speed and halves the sampling rate.
    // When used remember to halve the baudrate. See datasheet for details.
    #define USART0_DOUBLE    0           // double speed             Format: (0|1) -> {Normal|Double Speed}

    #define USART0_DATABITS  8           // number of Data Bits      Format: (5~9)
    #define USART0_STOPBITS  1           // number of Stop Bits      Format: (1|2)
    #define USART0_PARITY    0           // Parity                   Format: (0|1|2) -> {none|odd|even}
#endif

/* Config */

    #undef USARTx_BAUD
    #undef USARTx_RX_EN
    #undef USARTx_TX_EN
    #undef USARTx_SYNC
    #undef USARTx_POLARITY
    #undef USARTx_DOUBLE
    #undef USARTx_DATABITS
    #undef USARTx_STOPBITS
    #undef USARTx_PARITY

    #define USARTx_BAUD        USART0_BAUD
    #define USARTx_RX_EN       USART0_RX_EN
    #define USARTx_TX_EN       USART0_TX_EN
    #define USARTx_SYNC        USART0_SYNC
    #define USARTx_POLARITY    USART0_POLARITY
    #define USARTx_DOUBLE      USART0_DOUBLE
    #define USARTx_DATABITS    USART0_DATABITS
    #define USARTx_STOPBITS    USART0_STOPBITS
    #define USARTx_PARITY      USART0_PARITY

    #include "USARTx_Config.h"
