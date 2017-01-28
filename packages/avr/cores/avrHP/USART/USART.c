
#ifdef UBRR

#include "USART.h"

void USART_Set_UBRR(byte value) {
    #ifdef UBRR
    UBRR = value;
    #else
    UBRRL = value;
    #endif
}

void USART_Init() {
    // Apply Baud Rate configuration
    USART_Set_UBRR(_UBRR);

    // Apply the USART configuration to the registers
    #ifdef URSEL
    UCSRC = (1 << URSEL) | _UMSEL | _UPM | _USBS | _UCSZ_C | _UCPOL;
    #else
    UCSRC = _UMSEL | _UPM | _USBS | _UCSZ_C | _UCPOL;
    #endif

    // UDRIE: When we can write next frame
    // TXCIE: When a frame has been completely sent
    // RXCIE: When a frame has been completely received
    UCSRB = (0 << RXCIE) | (0 << TXCIE) | (0 << UDRIE) | _RXEN | _TXEN | _UCSZ_B;

    #if _U2X != 0
    UCSRA = _U2X;
    #endif
}

void USART_TX_direct(byte data) {
    UDR = data;
}

byte USART_TX_Ready() {
    return VAL(UCSRA,UDRE);
}

byte USART_RX_direct() {
    return UDR;
}

byte USART_RX_Available() {
    return VAL(UCSRA,RXC);
}

void USART_TX(byte data) {
    while (!USART_TX_Ready());
    USART_TX_direct(data);
}

byte USART_RX() {
    while (!USART_RX_Available());
    return USART_RX_direct();
}

void USART_setInterruptRXC(byte state) {
    if (state) SBI(UCSRB, RXCIE);
    else CBI(UCSRB, RXCIE);
}

void USART_setInterruptTXC(byte state) {
    if (state) SBI(UCSRB, TXCIE);
    else CBI(UCSRB, TXCIE);
}

void USART_setInterruptUDR(byte state) {
    if (state) SBI(UCSRB, UDRIE);
    else CBI(UCSRB, UDRIE);
}

#else
#warning No USART support
#endif
