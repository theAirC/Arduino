#pragma once

#if !defined(RXC)

#if defined(RXC0)

    #define RXC     RXC0
    #define TXC     TXC0
    #define UDRE    UDRE0
    #define U2X     U2X0
    #define RXCIE   RXCIE0
    #define TXCIE   TXCIE0
    #define UDRIE   UDRIE0
    #define RXEN    RXEN0
    #define TXEN    TXEN0
    #define UCSZ2   UCSZ02
    #define UMSEL   UMSEL00
    #define UPM1    UPM01
    #define UPM0    UPM00
    #define USBS    USBS0
    #define UCSZ1   UCSZ01
    #define UCSZ0   UCSZ00
    #define UCPOL   UCPOL0

#elif defined(RXC1)

    #define RXC     RXC1
    #define TXC     TXC1
    #define UDRE    UDRE1
    #define U2X     U2X1
    #define RXCIE   RXCIE1
    #define TXCIE   TXCIE1
    #define UDRIE   UDRIE1
    #define RXEN    RXEN1
    #define TXEN    TXEN1
    #define UCSZ2   UCSZ12
    #define UMSEL   UMSEL10
    #define UPM1    UPM11
    #define UPM0    UPM10
    #define USBS    USBS1
    #define UCSZ1   UCSZ11
    #define UCSZ0   UCSZ10
    #define UCPOL   UCPOL1

#else
#error "Cant get names for USART register bits, check if USART is supported."
#endif

#endif
