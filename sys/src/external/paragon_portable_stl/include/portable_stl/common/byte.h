// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="byte.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BYTE_H
#define PSTL_BYTE_H

#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/primary_type/is_integral.h"

namespace portable_stl {

enum class byte : unsigned char {
};

constexpr inline byte operator|(byte lhv, byte rhv) noexcept {
  return static_cast<byte>(static_cast<unsigned char>(static_cast<unsigned int>(lhv) | static_cast<unsigned int>(rhv)));
}

constexpr inline byte &operator|=(byte &lhv, byte rhv) noexcept {
  return lhv = lhv | rhv;
}

constexpr inline byte operator&(byte lhv, byte rhv) noexcept {
  return static_cast<byte>(static_cast<unsigned char>(static_cast<unsigned int>(lhv) & static_cast<unsigned int>(rhv)));
}

constexpr inline byte &operator&=(byte &lhv, byte rhv) noexcept {
  return lhv = lhv & rhv;
}

constexpr inline byte operator^(byte lhv, byte rhv) noexcept {
  return static_cast<byte>(static_cast<unsigned char>(static_cast<unsigned int>(lhv) ^ static_cast<unsigned int>(rhv)));
}

constexpr inline byte &operator^=(byte &lhv, byte rhv) noexcept {
  return lhv = lhv ^ rhv;
}

constexpr inline byte operator~(byte value) noexcept {
  return static_cast<byte>(static_cast<unsigned char>(~static_cast<unsigned int>(value)));
}

template<class t_intergal_type,
         ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_integral<t_intergal_type>, void *> = nullptr>
constexpr byte &operator<<=(byte &lhv, t_intergal_type shift) noexcept {
  return lhv = lhv << shift;
}

template<class t_intergal_type,
         ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_integral<t_intergal_type>, void *> = nullptr>
constexpr byte operator<<(byte lhv, t_intergal_type shift) noexcept {
  return static_cast<byte>(static_cast<unsigned char>(static_cast<unsigned int>(lhv) << shift));
}

template<class t_intergal_type,
         ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_integral<t_intergal_type>, void *> = nullptr>
constexpr byte &operator>>=(byte &lhv, t_intergal_type shift) noexcept {
  return lhv = lhv >> shift;
}

template<class t_intergal_type,
         ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_integral<t_intergal_type>, void *> = nullptr>
constexpr byte operator>>(byte lhv, t_intergal_type shift) noexcept {
  return static_cast<byte>(static_cast<unsigned char>(static_cast<unsigned int>(lhv) >> shift));
}

template<class t_intergal_type,
         ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_integral<t_intergal_type>, void *> = nullptr>
constexpr t_intergal_type to_integer(byte value) noexcept {
  return static_cast<t_intergal_type>(value);
}
} // namespace portable_stl

#endif // PSTL_BYTE_H
