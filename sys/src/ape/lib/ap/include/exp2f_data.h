/*
 * Copyright (c) 2017-2018, Arm Limited.
 * SPDX-License-Identifier: MIT
 */
#ifndef _EXP2F_DATA_H
#define _EXP2F_DATA_H

#include <features.h>
#include <stdint.h>

/* Shared between expf, exp2f and powf.  */
#define EXP2F_TABLE_BITS 5
#define EXP2F_POLY_ORDER 3
/* `hidden' is musl's internal visibility marker. It used to come
 * from the PUBLIC <features.h>, which also erased sqlite3.h's own
 * `unsigned char hidden[48];' member wherever that header came
 * second. Supplied here instead, the way `include/libm.h' and
 * `multibyte/internal.c' already did. */
#ifndef hidden
#define hidden
#endif
extern hidden const struct exp2f_data {
	uint64_t tab[1 << EXP2F_TABLE_BITS];
	double shift_scaled;
	double poly[EXP2F_POLY_ORDER];
	double shift;
	double invln2_scaled;
	double poly_scaled[EXP2F_POLY_ORDER];
} __exp2f_data;

#endif
