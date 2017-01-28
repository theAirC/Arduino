#pragma once

#include "USART_BitNames.h"

#define USART_Baud_to_UBRR(BAUD)    (rounddiv(F_CPU, (BAUD)*16UL) - 1)
