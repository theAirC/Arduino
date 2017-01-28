// Extension of "Naming.h"

#pragma once

#define PORT(p)      (PORT ## p)
#define PIN(p)       ( PIN ## p)
#define DDR(p)       ( DDR ## p)
#define _ON(p,b)     SBI(PORT(p), b)
#define _OFF(p,b)    CBI(PORT(p), b)
#define _OUT(p,b)    SBI( DDR(p), b)
#define _IN(p,b)     CBI( DDR(p), b)
#define _R(p,b)      VAL( PIN(p), b)
#define ON(io)       _ON(io)
#define OFF(io)      _OFF(io)
#define OUT(io)      _OUT(io)
#define IN(io)       _IN(io)
#define R(io)        _R(io)
#define W(io, x)     if(x) _ON(io);  else _OFF(io);
#define M(io, x)     if(x) _OUT(io); else _IN (io);

#include "Ports.h"
#include "Pins_Special.h"
