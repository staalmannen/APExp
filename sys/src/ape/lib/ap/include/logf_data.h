/*
 * Copyright (c) 2017-2018, Arm Limited.
 * SPDX-License-Identifier: MIT
 */
#ifndef _LOGF_DATA_H
#define _LOGF_DATA_H

#include <features.h>

#define LOGF_TABLE_BITS 4
#define LOGF_POLY_ORDER 4
/* `hidden' is musl's internal visibility marker. It used to come
 * from the PUBLIC <features.h>, which also erased sqlite3.h's own
 * `unsigned char hidden[48];' member wherever that header came
 * second. Supplied here instead, the way `include/libm.h' and
 * `multibyte/internal.c' already did. */
#ifndef hidden
#define hidden
#endif
extern hidden const struct logf_data {
	struct {
		double invc, logc;
	} tab[1 << LOGF_TABLE_BITS];
	double ln2;
	double poly[LOGF_POLY_ORDER - 1]; /* First order coefficient is 1.  */
} __logf_data;

#endif
