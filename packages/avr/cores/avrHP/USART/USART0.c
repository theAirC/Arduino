
#ifdef UBRR0

#include "USART0.h"

void USART0_Set_UBRR(byte value) {
    #ifdef UBRR0
    UBRR0 = value;
    #else
    UBRR0L = value;
    #endif
}

void USART0_Init() {
    // Apply Baud Rate configuration
    USART0_Set_UBRR(_UBRR);

    // Apply the USART0 configuration to the registers
    #ifdef URSEL
    UCSR0C = (1 << URSEL) | _UMSEL | _UPM | _USBS | _UCSZ_C | _UCPOL;
    #else
    UCSR0C = _UMSEL | _UPM | _USBS | _UCSZ_C | _UCPOL;
    #endif

    // UDRIE: When we can write next frame
    // TXCIE: When a frame has been completely sent
    // RXCIE: When a frame has been completely received
    UCSR0B = (0 << RXCIE) | (0 << TXCIE) | (0 << UDRIE) | _RXEN | _TXEN | _UCSZ_B;

    #if _U2X != 0
    UCSR0A = _U2X;
    #endif
}

void USART0_TX_direct(byte data) {
    UDR0 = data;
}

byte USART0_TX_Ready() {
    return VAL(UCSR0A,UDRE);
}

byte USART0_RX_direct() {
    return UDR0;
}

byte USART0_RX_Available() {
    return VAL(UCSR0A,RXC);
}

void USART0_TX(byte data) {
    while (!USART0_TX_Ready());
    USART0_TX_direct(data);
}

byte USART0_RX() {
    while (!USART0_RX_Available());
    return USART0_RX_direct();
}

void USART0_setInterruptRXC(byte state) {
    if (state) SBI(UCSR0B, RXCIE);
    else CBI(UCSR0B, RXCIE);
}

void USART0_setInterruptTXC(byte state) {
    if (state) SBI(UCSR0B, TXCIE);
    else CBI(UCSR0B, TXCIE);
}

void USART0_setInterruptUDR(byte state) {
    if (state) SBI(UCSR0B, UDRIE);
    else CBI(UCSR0B, UDRIE);
}

#else
#warning No USART0 support
#endif
