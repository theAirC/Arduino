
#ifdef UBRR1

#include "USART1.h"

void USART1_Set_UBRR(byte value) {
    #ifdef UBRR1
    UBRR1 = value;
    #else
    UBRR1L = value;
    #endif
}

void USART1_Init() {
    // Apply Baud Rate configuration
    USART1_Set_UBRR(_UBRR);

    // Apply the USART1 configuration to the registers
    #ifdef URSEL
    UCSR1C = (1 << URSEL) | _UMSEL | _UPM | _USBS | _UCSZ_C | _UCPOL;
    #else
    UCSR1C = _UMSEL | _UPM | _USBS | _UCSZ_C | _UCPOL;
    #endif

    // UDRIE: When we can write next frame
    // TXCIE: When a frame has been completely sent
    // RXCIE: When a frame has been completely received
    UCSR1B = (0 << RXCIE) | (0 << TXCIE) | (0 << UDRIE) | _RXEN | _TXEN | _UCSZ_B;

    #if _U2X != 0
    UCSR1A = _U2X;
    #endif
}

void USART1_TX_direct(byte data) {
    UDR1 = data;
}

byte USART1_TX_Ready() {
    return VAL(UCSR1A,UDRE);
}

byte USART1_RX_direct() {
    return UDR1;
}

byte USART1_RX_Available() {
    return VAL(UCSR1A,RXC);
}

void USART1_TX(byte data) {
    while (!USART1_TX_Ready());
    USART1_TX_direct(data);
}

byte USART1_RX() {
    while (!USART1_RX_Available());
    return USART1_RX_direct();
}

void USART1_setInterruptRXC(byte state) {
    if (state) SBI(UCSR1B, RXCIE);
    else CBI(UCSR1B, RXCIE);
}

void USART1_setInterruptTXC(byte state) {
    if (state) SBI(UCSR1B, TXCIE);
    else CBI(UCSR1B, TXCIE);
}

void USART1_setInterruptUDR(byte state) {
    if (state) SBI(UCSR1B, UDRIE);
    else CBI(UCSR1B, UDRIE);
}

#else
#warning No USART1 support
#endif
