// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="type_info.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TYPE_INFO_H
#define PSTL_TYPE_INFO_H

#include "../../common/char_t.h"
#include "../../common/size_t.h"

#if !(defined(_LIBCPP_TYPEINFO) || defined(__LIBCPP_TYPEINFO) || defined(_TYPEINFO) || defined(_TYPEINFO_) \
      || defined(SSDK_STL_TYPEINFO))
#  include "type_info_stl/type_info.h"
#endif

namespace portable_stl {

namespace type_info_helper {
  class type_info_impl final {
  public:
    using t_type_name = ::portable_stl::char_t const *;

    static ::portable_stl::char_t const *type_name_to_string(t_type_name name) noexcept {
      return name;
    }

    static t_type_name string_to_type_name(::portable_stl::char_t const *cstr) noexcept {
      return cstr;
    }

    static ::portable_stl::size_t hash(t_type_name value) noexcept {
      return reinterpret_cast<::portable_stl::size_t>(value);
    }

    constexpr static bool eq(t_type_name lhv, t_type_name rhv) noexcept {
      return lhv == rhv;
    }

    constexpr static bool lt(t_type_name lhv, t_type_name rhv) noexcept {
      return lhv < rhv;
    }
  };
} // namespace type_info_helper

class type_info {
protected:
  using t_impl = type_info_helper::type_info_impl;

  t_impl::t_type_name m_type_name;

  explicit type_info(::portable_stl::char_t const *value) : m_type_name(t_impl::string_to_type_name(value)) {
  }

public:
  type_info() = default; // not standard constructor

  virtual ~type_info() = default;

  type_info &operator=(type_info const &) = delete;
  type_info(type_info const &)            = delete;

  type_info(::std::type_info const &other) {
    m_type_name = other.name();
  }

  /**
   * @brief Checks if the objects refer to the same types.
   *
   * @param rhv Another type information object to compare to.
   * @return true if the comparison operation holds true,
   * @return false otherwise.
   */
  constexpr bool operator==(type_info const &rhv) const noexcept {
    // When evaluated in a constant expression, both type infos simply can't come
    // from different translation units, so it is sufficient to compare their addresses.
    // if (__libcpp_is_constant_evaluated()) {
    //   return this == &rhv;
    // }
    return t_impl::eq(m_type_name, rhv.m_type_name);
  }

  /**
   * @brief Checks whether the referred type precedes referred type of another type_info object in the implementation
   * defined order, i.e. orders the referred types.
   *
   * @param other Type information object to compare to.
   * @return true if the type of this type_info precedes the type of rhs in the implementation's collation order. No
   * guarantees are given; in particular, the collation order can change between the invocations of the same program.
   * @return false otherwise.
   */
  bool before(type_info const &other) const noexcept {
    return t_impl::lt(m_type_name, other.m_type_name);
  }

  /**
   * @brief Returns a value which is identical for the same types.
   * Returns an unspecified value (here denoted by hash code) such that for all type_info objects referring to the
   * same type, their hash code is the same.
   * No other guarantees are given: type_info objects referring to different types may have the same hash code
   * (although the standard recommends that implementations avoid this as much as possible), and hash code for the same
   * type can change between invocations of the same program.
   *
   * @return ::portable_stl::size_t A value that is identical for all type_info objects referring to the same type.
   */
  ::portable_stl::size_t hash_code() const noexcept {
    return t_impl::hash(m_type_name);
  }

  /**
   * @brief Implementation defined name of the type.
   * Returns an implementation defined null-terminated character string containing the name of the type. No guarantees
   * are given; in particular, the returned string can be identical for several types and change between invocations of
   * the same program.
   *
   * @return ::portable_stl::char_t const* Null-terminated character string containing the name of the type.
   */
  ::portable_stl::char_t const *name() const noexcept {
    return t_impl::type_name_to_string(m_type_name);
  }
};
} // namespace portable_stl

#endif // PSTL_TYPE_INFO_H
