// ***************************************************************************
// * APExp addition to Paragon Portable STL.
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
//
// `std::to_wstring' -- SIX INTEGER OVERLOADS AND DELIBERATELY NO FLOAT.
//
// ***THE IMPLEMENTATION WAS ALREADY IN THE TREE AND HAD NEVER BEEN
// COMPILED.***  `string/to_string2.h' carries a generic
// `to_string2<t_string>' over `base_to_string_converter', which works
// for any `basic_string' whose `value_type' has a `unicode_helper' --
// and `wchar_t' has one.  Nothing included that file: a grep for
// `to_string2' over the whole library found the file and no user.  So
// this is six wrappers over upstream's own machinery rather than new
// code, which is why it is small.
//
// **And "already there" was too strong until it was compiled.**
// `to_string2.h' includes `convert.h', which uses `uint32_t'
// unqualified at three sites with nothing declaring it -- so it did
// not compile at all.  One missing include, found in one command, and
// recorded at the top of `convert.h'.  *This tree's own rule about a
// change that makes code reach code nothing reached before.*
//
// ---- WHY SIX AND NOT THE STANDARD'S NINE ---------------------------
//
// [string.conversions] gives `to_wstring' nine overloads: the six
// integer ones here plus `float', `double' and `long double', each
// specified as if by `swprintf(..., L"%f", val)'.  `base_to_string_
// converter' HAS a floating-point specialisation and it works -- it
// was run on the host before this file was written: `1.5' -> "1.5",
// `0.125' -> "0.125", `1e20' -> "100000000000000000000", `-1.5' ->
// "-1.5".
//
// **But `%f' on 100.0 is "100.000000" and that converter answers
// "100".**  Shipping it under the standard's name would hand every
// caller a different string from the one the standard promises, which
// is this tree's most common bug class -- a thing that answers rather
// than one that says it cannot.  The floating-point forms are
// therefore ABSENT, where a caller gets a compile error naming them,
// and `to_string' has no float overload either, so the two stay
// symmetric.  A conforming `%f' formatter is the separate piece of
// work; `to_string2<t_string>(double)' is reachable by name for
// anyone who wants shortest-form output on purpose.
//
// ---- THE SIX ARE SIX FOR AN ABI REASON, NOT FOR TIDINESS -----------
//
// kencc is LLP64: `long' is 4 bytes and `size_t' is 8, so a `size_t'
// argument binds `unsigned long long' here and `unsigned long' on an
// LP64 host.  A set that left either out would compile on one and not
// the other.

#ifndef APEXP_TO_WSTRING_H
#define APEXP_TO_WSTRING_H

#include "string.h"
#include "to_string2.h"

namespace std {

/**
 * @brief Converts a numeric value to ::std::wstring.
 */
inline ::std::wstring to_wstring(int value) noexcept {
  return ::std::to_string2<::std::wstring>(value);
}

/**
 * @brief Converts a numeric value to ::std::wstring.
 */
inline ::std::wstring to_wstring(unsigned int value) noexcept {
  return ::std::to_string2<::std::wstring>(value);
}

/**
 * @brief Converts a numeric value to ::std::wstring.
 */
inline ::std::wstring to_wstring(long value) noexcept {
  return ::std::to_string2<::std::wstring>(value);
}

/**
 * @brief Converts a numeric value to ::std::wstring.
 */
inline ::std::wstring to_wstring(unsigned long value) noexcept {
  return ::std::to_string2<::std::wstring>(value);
}

/**
 * @brief Converts a numeric value to ::std::wstring.
 */
inline ::std::wstring to_wstring(long long value) noexcept {
  return ::std::to_string2<::std::wstring>(value);
}

/**
 * @brief Converts a numeric value to ::std::wstring.
 */
inline ::std::wstring to_wstring(unsigned long long value) noexcept {
  return ::std::to_string2<::std::wstring>(value);
}

} // namespace std

#endif // APEXP_TO_WSTRING_H
