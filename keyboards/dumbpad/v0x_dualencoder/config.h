#pragma once

/* Column/Row IO definitions - dualencoder version is true 4x4 */
#undef MATRIX_COLS
#undef MATRIX_COL_PINS
#define MATRIX_COLS 4
#define MATRIX_COL_PINS { D7, E6, B4, B5 }

/* Dual rotary encoders */
#undef ENCODERS_PAD_A
#undef ENCODERS_PAD_B
#define ENCODERS_PAD_A { C6, D0 }
#define ENCODERS_PAD_B { D4, D1 }
