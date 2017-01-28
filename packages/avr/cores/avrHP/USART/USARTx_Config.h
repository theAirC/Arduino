#undef _UBRR
#undef _RXEN
#undef _TXEN
#undef _UCPOL
#undef _U2X
#undef _UMSEL
#undef _UPM
#undef _USBS
#undef _UCSZ_B
#undef _UCSZ_C

/* Register Composition */

	#define _UBRR   USART_Baud_to_UBRR((USARTx_BAUD) >> (USARTx_DOUBLE))

    #define _RXEN   (USARTx_RX_EN << RXEN)
    #define _TXEN   (USARTx_TX_EN << TXEN)
    #define _UCPOL  (USARTx_POLARITY << UCPOL)
    #define _U2X    (USARTx_DOUBLE << U2X)

    #if     USARTx_SYNC == 1
        #define _UMSEL  (1 << UMSEL)    // Synchronous mode
        #if USARTx_DOUBLE == 1
            #undef  _U2X
            #define _U2X    0
            #warning "Double Speed USART disabled in Synchronous mode"
        #endif
    #elif   USARTx_SYNC == 0
        #define _UMSEL  (0 << UMSEL)    // Asynchronous mode    [Default]
        #if USARTx_POLARITY == 1
            #undef  _UCPOL
            #define _UCPOL  0
            #warning "USART Polarity disabled in Asynchronous mode"
        #endif
    #endif

    #if     USARTx_PARITY == 0
        #define _UPM    ((0 << UPM0) | (0 << UPM1))      // No Parity    [Default]
    #elif   USARTx_PARITY == 1
        #define _UPM    ((1 << UPM0) | (1 << UPM1))      // Odd Parity
    #elif   USARTx_PARITY == 2
        #define _UPM    ((1 << UPM0) | (0 << UPM1))      // Even Parity
    #endif

    #if     USARTx_STOPBITS == 2
        #define _USBS   (1 << USBS)                      // 2 Stop Bits
    #elif   USARTx_STOPBITS == 1
        #define _USBS   (0 << USBS)                      // 1 Stop Bit   [Default]
    #endif

    #if     USARTx_DATABITS == 5
        #define _UCSZ_C ((0 << UCSZ1) | (0 << UCSZ0))    // 5 Data Bits
        #define _UCSZ_B (0 << UCSZ2)
    #elif   USARTx_DATABITS == 6
        #define _UCSZ_C ((0 << UCSZ1) | (1 << UCSZ0))    // 6 Data Bits
        #define _UCSZ_B (0 << UCSZ2)
    #elif   USARTx_DATABITS == 7
        #define _UCSZ_C ((1 << UCSZ1) | (0 << UCSZ0))    // 7 Data Bits
        #define _UCSZ_B (0 << UCSZ2)
    #elif   USARTx_DATABITS == 8
        #define _UCSZ_C ((1 << UCSZ1) | (1 << UCSZ0))    // 8 Data Bits  [Default]
        #define _UCSZ_B (0 << UCSZ2)
    #elif   USARTx_DATABITS == 9
        #define _UCSZ_C ((1 << UCSZ1) | (1 << UCSZ0))    // 9 Data Bits
        #define _UCSZ_B (1 << UCSZ2)
    #endif

/* Configuration Check */

    #if !(USARTx_RX_EN == 0 || USARTx_RX_EN == 1)
    #error "USARTx_RX_EN out of bounds"
    #endif
    #if !(USARTx_TX_EN == 0 || USARTx_TX_EN == 1)
    #error "USARTx_TX_EN out of bounds"
    #endif
    #if !(USARTx_POLARITY == 0 || USARTx_POLARITY == 1)
    #error "USARTx_POLARITY out of bounds"
    #endif
    #if !(USARTx_DOUBLE == 0 || USARTx_DOUBLE == 1)
    #error "USARTx_DOUBLE out of bounds"
    #endif

    #ifndef _UMSEL
    #error "USARTx_SYNC out of bounds"
    #endif
    #ifndef _UPM
    #error "USARTx_PARITY out of bounds"
    #endif
    #ifndef _USBS
    #error "USARTx_STOPBITS out of bounds"
    #endif
    #ifndef _UCSZ_C
    #error "USARTx_DATABITS out of bounds"
    #endif
    #ifndef _UCSZ_B
    #error "USARTx_DATABITS out of bounds"
    #endif
