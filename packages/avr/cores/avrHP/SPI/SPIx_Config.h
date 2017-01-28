#undef _SPE
#undef _MSTR
#undef _DORD
#undef _CPOL
#undef _CPHA
#undef _SPIE
#undef _SPR
#undef _SPI2X

/* Register Composition */

    #define _SPE    (1 << SPE)

    // Bound checks are done later below
    
    #define _MSTR   (SPIx_MASTER << MSTR)
    #define _DORD   (SPIx_ORDER << DORD)
    #define _CPOL   (SPIx_POLARITY << CPOL)
    #define _CPHA   (SPIx_PHASE << CPHA)
    #define _SPIE   (0 << SPIE)

    #if     SPIx_DIVIDER == 2
        #define _SPR    ((0 << SPR1) | (0 << SPR0))
        #define _SPI2X  (1 << SPI2X)
        #if _MSTR == 0
        #warning "SPI Speed unstably high for slave mode, consider using SPIx_DIVIDER >= 4."
        #endif
    #elif   SPIx_DIVIDER == 4
        #define _SPR    ((0 << SPR1) | (0 << SPR0))
        #define _SPI2X  (0 << SPI2X)
    #elif   SPIx_DIVIDER == 8
        #define _SPR    ((0 << SPR1) | (1 << SPR0))
        #define _SPI2X  (1 << SPI2X)
    #elif   SPIx_DIVIDER == 16
        #define _SPR    ((0 << SPR1) | (1 << SPR0))
        #define _SPI2X  (0 << SPI2X)
    #elif   SPIx_DIVIDER == 32
        #define _SPR    ((1 << SPR1) | (0 << SPR0))
        #define _SPI2X  (1 << SPI2X)
    #elif   SPIx_DIVIDER == 64
        #define _SPR    ((1 << SPR1) | (0 << SPR0))
        #define _SPI2X  (0 << SPI2X)
    #elif   SPIx_DIVIDER == 128
        #define _SPR    ((1 << SPR1) | (1 << SPR0))
        #define _SPI2X  (0 << SPI2X)
    #endif
    
/* Configuration Check */

    #if !(SPIx_MASTER == 0 || SPIx_MASTER == 1)
        #error "SPIx_MASTER out of bounds"
    #endif
    #if !(SPIx_ORDER == 0 || SPIx_ORDER == 1)
        #error "SPIx_ORDER out of bounds"
    #endif
    #if !(SPIx_POLARITY == 0 || SPIx_POLARITY == 1)
        #error "SPIx_POLARITY out of bounds"
    #endif
    #if !(SPIx_PHASE == 0 || SPIx_PHASE == 1)
        #error "SPIx_PHASE out of bounds"
    #endif

    #ifndef _SPR
        #error "SPIx_DIVIDER out of bounds"
    #endif
    #ifndef _SPI2X
        #error "SPIx_DIVIDER out of bounds"
    #endif
