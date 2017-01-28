#pragma once

/* Consult the Datasheet before using. */

#define Timer_Ticks(Microseconds, ClockDiv) rounddiv((u64)Microseconds * (u64)F_CPU, (u64)ClockDiv * 1000000ULL)

typedef enum {
    Timer_OutCompMatch_None   = 0,
    Timer_OutCompMatch_Toggle = 1,
    Timer_OutCompMatch_Clear  = 2,
    Timer_OutCompMatch_Set    = 3,

    Timer_OutCompMatch_Normal = 2,
    Timer_OutCompMatch_Invert = 3,
} Timer_OutCompMatch;

typedef enum {
    Timer_Mode_Normal    = 0,
    Timer_Mode_PWM_Phase = 1,
    Timer_Mode_CTC       = 2,
    Timer_Mode_PWM_Fast  = 3,

	Timer16_Mode_Normal           = 0,
	Timer16_Mode_PWM_Phase8       = 1,
    Timer16_Mode_PWM_Phase9       = 2,
    Timer16_Mode_PWM_Phase10      = 3,
	Timer16_Mode_CTC_OCR          = 4,
    Timer16_Mode_PWM_Fast8        = 5,
    Timer16_Mode_PWM_Fast9        = 6,
    Timer16_Mode_PWM_Fast10       = 7,
    Timer16_Mode_PWM_PhaseFreqICR = 8,
    Timer16_Mode_PWM_PhaseFreqOCR = 9,
    Timer16_Mode_PWM_PhaseICR     = 10,
    Timer16_Mode_PWM_PhaseOCR     = 11,
    Timer16_Mode_CTC_ICR          = 12,
    // Reserved = 13
    Timer16_Mode_PWM_FastICR      = 14,
    Timer16_Mode_PWM_FastOCR      = 15,
} Timer_Mode;

typedef enum {
    Timer_Clock_None       = 0,
    Timer_Clock_Direct     = 1,
    Timer_Clock_Div8       = 2,
    Timer_Clock_Div64      = 3,
    Timer_Clock_Div256     = 4,
    Timer_Clock_Div1024    = 5,
    Timer_Clock_ExtFalling = 6,
    Timer_Clock_ExtRising  = 7,

    Timer_2_Clock_None    = 0,
    Timer_2_Clock_Direct  = 1,
    Timer_2_Clock_Div8    = 2,
    Timer_2_Clock_Div32   = 3,
    Timer_2_Clock_Div64   = 4,
    Timer_2_Clock_Div128  = 4,
    Timer_2_Clock_Div256  = 6,
    Timer_2_Clock_Div1024 = 7,
} Timer_Clock;
