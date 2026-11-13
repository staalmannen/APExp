// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="max_align_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MAX_ALIGN_T_H
#define PSTL_MAX_ALIGN_T_H
namespace std {

/**
 * @brief The type is a trivial standard-layout type whose alignment requirement
 * is at least as great as that of every scalar type, and whose alignment
 * requirement is supported in every context.
 *
 */
/*
 * ***THIS LINE WAS `using max_align_t = ;'*** -- an alias to nothing,
 * which no compiler can read, so `<cstddef>' and `<cwchar>' did not
 * compile at all.  Upstream leaves it for the platform to fill in and
 * nothing filled it in.
 *
 * A union of the widest scalar types IS the definition the standard
 * asks for ("alignment at least as great as that of every scalar
 * type"), and it is written out rather than taken from a builtin
 * because the three compilers in play spell the builtin three
 * different ways and EDG in this mode has none of them.  `long long'
 * and `long double' are the widest integer and floating types kencc
 * has; the pointer members cover the LLP64 case, where a pointer is
 * wider than `long'.
 */
union max_align_t {
  long long     m_ll;
  long double   m_ld;
  void         *m_p;
  void (*m_pf)();
};

} // namespace std

#endif // PSTL_MAX_ALIGN_T_H
