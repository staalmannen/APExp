/*
 * Copyright (c) 2017-2018, Arm Limited.
 * SPDX-License-Identifier: MIT
 */
#ifndef _LOG2F_DATA_H
#define _LOG2F_DATA_H

#include <features.h>

#define LOG2F_TABLE_BITS 4
#define LOG2F_POLY_ORDER 4
/* `hidden' is musl's internal visibility marker. It used to come
 * from the PUBLIC <features.h>, which also erased sqlite3.h's own
 * `unsigned char hidden[48];' member wherever that header came
 * second. Supplied here instead, the way `include/libm.h' and
 * `multibyte/internal.c' already did. */
#ifndef hidden
#define hidden
#endif
extern hidden const struct log2f_data {
	struct {
		double invc, logc;
	} tab[1 << LOG2F_TABLE_BITS];
	double poly[LOG2F_POLY_ORDER];
} __log2f_data;

#endif
