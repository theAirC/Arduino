#pragma once

#include "USART_Common.h"

/* Settings */
#ifndef USART1_Settings
#define USART1_Settings
    #define USART1_BAUD   9600           // Baudrate in bits per second

    #define USART1_RX_EN     1           // Receive pin state        Format: (0|1) -> {Disabled|Enabled}
    #define USART1_TX_EN     1           // Transmit pin state       Format: (0|1) -> {Disabled|Enabled}

    #define USART1_SYNC      0           // Synchronization          Format: (0|1) -> {Asynchronous|Synchronous}
    // Specify polarity when in Synchronous mode.
    #define USART1_POLARITY  0           // Polarity                 Format: (0|1) -> {Normal|Inverted}

    // Change the following under conditions, it doubles the speed and halves the sampling rate.
    // When used remember to halve the baudrate. See datasheet for details.
    #define USART1_DOUBLE    0           // double speed             Format: (0|1) -> {Normal|Double Speed}

    #define USART1_DATABITS  8           // number of Data Bits      Format: (5~9)
    #define USART1_STOPBITS  1           // number of Stop Bits      Format: (1|2)
    #define USART1_PARITY    0           // Parity                   Format: (0|1|2) -> {none|odd|even}
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

    #define USARTx_BAUD        USART1_BAUD
    #define USARTx_RX_EN       USART1_RX_EN
    #define USARTx_TX_EN       USART1_TX_EN
    #define USARTx_SYNC        USART1_SYNC
    #define USARTx_POLARITY    USART1_POLARITY
    #define USARTx_DOUBLE      USART1_DOUBLE
    #define USARTx_DATABITS    USART1_DATABITS
    #define USARTx_STOPBITS    USART1_STOPBITS
    #define USARTx_PARITY      USART1_PARITY

    #include "USARTx_Config.h"
