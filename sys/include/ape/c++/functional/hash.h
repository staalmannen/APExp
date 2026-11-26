// ***************************************************************************
// * APExp addition to portable_stl -- `std::hash'.
// *
// * Project="APExp C++ library" File="functional/hash.h"
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
//
// **There was no `std::hash` anywhere in this library**, measured rather
// than assumed, which is why `unordered_set' was a bigger job than "a
// self-contained container": the whole unordered half of the standard
// library rests on this one template.
//
// ---- THE ALGORITHM, AND WHY THESE CHOICES -------------------------------
//
// **Integers hash to themselves**, which the standard permits and every
// real implementation does.  *It is not a weak choice here* because the
// bucket index is taken modulo a PRIME rather than a power of two (see
// `containers/unordered_set.h'), so consecutive keys spread rather than
// collide -- the two decisions are a pair and neither is safe alone.
//
// **Everything else is FNV-1a over the object's bytes.**  It is eight
// lines, has no table, and is good enough for a container that chains;
// *this is not a cryptographic hash and nothing here pretends otherwise.*
//
// ---- THE TWO THAT ARE NOT JUST BYTES -------------------------------------
//
// ***FLOATING POINT MUST MAP -0.0 ONTO +0.0 FIRST.***  The two compare
// EQUAL and have different bit patterns, so hashing the bytes gives two
// different buckets for one key -- a lookup that stores `-0.0' and asks
// for `0.0' then misses, which is a silent wrong answer rather than a
// crash.  *The sign bit is the whole bug and `v == 0' is the whole fix.*
//
// **`bool` is hashed as 0 or 1 and not as its byte**, because a `bool`
// holding any nonzero byte is a valid `true' that must hash with every
// other `true'.
//
// NaN is left alone deliberately: it compares equal to nothing, including
// itself, so no container can find it again whatever it hashes to.

#ifndef APEXP_STD_FUNCTIONAL_HASH_H
#define APEXP_STD_FUNCTIONAL_HASH_H

#include "../common/size_t.h"
#include "../cstdint.stdh"
#include "../string/basic_string.h"
#include "../string/char_traits.h"

namespace std {

namespace hash_detail {

  constexpr ::std::size_t fnv_offset = 14695981039346656037ULL;
  constexpr ::std::size_t fnv_prime  = 1099511628211ULL;

  inline ::std::size_t fnv1a(void const *in_p, ::std::size_t in_n) noexcept {
    unsigned char const *b{static_cast<unsigned char const *>(in_p)};
    ::std::size_t        h{fnv_offset};
    for (::std::size_t i{0U}; i < in_n; ++i) {
      h ^= static_cast<::std::size_t>(b[i]);
      h *= fnv_prime;
    }
    return h;
  }

  // The float case, with the negative-zero rule applied once for all
  // three widths.
  template<class t_float> inline ::std::size_t hash_float(t_float in_v) noexcept {
    if (in_v == static_cast<t_float>(0)) {
      return 0U; // +0.0 and -0.0 are one key
    }
    return fnv1a(&in_v, sizeof(in_v));
  }

} // namespace hash_detail

// The primary template is DECLARED and not defined, so a type with no
// specialisation is a compile error naming the type rather than a
// silently useless hash.
template<class t_type> struct hash;

#define APEXP_STD_HASH_INTEGRAL(T)                                                       \
  template<> struct hash<T> final {                                                      \
    using argument_type = T;                                                             \
    using result_type   = ::std::size_t;                                                 \
    ::std::size_t operator()(T in_v) const noexcept {                                    \
      return static_cast<::std::size_t>(in_v);                                           \
    }                                                                                    \
  };

APEXP_STD_HASH_INTEGRAL(char)
APEXP_STD_HASH_INTEGRAL(signed char)
APEXP_STD_HASH_INTEGRAL(unsigned char)
APEXP_STD_HASH_INTEGRAL(wchar_t)
APEXP_STD_HASH_INTEGRAL(char16_t)
APEXP_STD_HASH_INTEGRAL(char32_t)
APEXP_STD_HASH_INTEGRAL(short)
APEXP_STD_HASH_INTEGRAL(unsigned short)
APEXP_STD_HASH_INTEGRAL(int)
APEXP_STD_HASH_INTEGRAL(unsigned int)
APEXP_STD_HASH_INTEGRAL(long)
APEXP_STD_HASH_INTEGRAL(unsigned long)
APEXP_STD_HASH_INTEGRAL(long long)
APEXP_STD_HASH_INTEGRAL(unsigned long long)

#undef APEXP_STD_HASH_INTEGRAL

template<> struct hash<bool> final {
  using argument_type = bool;
  using result_type   = ::std::size_t;
  ::std::size_t operator()(bool in_v) const noexcept {
    // Not the byte: any nonzero byte is a valid `true'.
    return in_v ? 1U : 0U;
  }
};

template<> struct hash<float> final {
  using argument_type = float;
  using result_type   = ::std::size_t;
  ::std::size_t operator()(float in_v) const noexcept {
    return hash_detail::hash_float(in_v);
  }
};
template<> struct hash<double> final {
  using argument_type = double;
  using result_type   = ::std::size_t;
  ::std::size_t operator()(double in_v) const noexcept {
    return hash_detail::hash_float(in_v);
  }
};
template<> struct hash<long double> final {
  using argument_type = long double;
  using result_type   = ::std::size_t;
  ::std::size_t operator()(long double in_v) const noexcept {
    return hash_detail::hash_float(in_v);
  }
};

// A pointer hashes by its VALUE and not by what it points at, which is
// what the standard says and what `unordered_set<T *>' needs.
template<class t_type> struct hash<t_type *> final {
  using argument_type = t_type *;
  using result_type   = ::std::size_t;
  ::std::size_t operator()(t_type *in_v) const noexcept {
    return reinterpret_cast<::std::size_t>(in_v);
  }
};

template<> struct hash<::std::nullptr_t> final {
  using argument_type = ::std::nullptr_t;
  using result_type   = ::std::size_t;
  ::std::size_t operator()(::std::nullptr_t) const noexcept {
    return 0U;
  }
};

// Strings hash their CONTENTS, and two strings that compare equal must
// hash equal whatever their capacity or short-buffer state -- which is
// why this goes through `data()' and `size()' and never through the
// object's own bytes.
template<class t_char, class t_traits>
struct hash<::std::basic_string<t_char, t_traits>> final {
  using argument_type = ::std::basic_string<t_char, t_traits>;
  using result_type   = ::std::size_t;
  ::std::size_t operator()(::std::basic_string<t_char, t_traits> const &in_s) const
      noexcept {
    return hash_detail::fnv1a(in_s.data(), in_s.size() * sizeof(t_char));
  }
};

} // namespace std

#endif // APEXP_STD_FUNCTIONAL_HASH_H
