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
#ifndef PSTL_TYPE_INFO_STL_H
#define PSTL_TYPE_INFO_STL_H

#include "../../../common/char_t.h"
#include "../../../common/size_t.h"

namespace std {

/**
 * @brief A stub for the type_info class; it will effectively not be used if std::type_info has not been declared (in
 * the case when RTTI is disabled).
 *
 */
class type_info {
public:
  type_info &operator=(type_info const &) = delete;
  type_info(type_info const &)            = delete;

  virtual ~type_info();

  /**
   * @brief Checks if the objects refer to the same types.
   *
   * @param rhv Another type information object to compare to.
   * @return true if the comparison operation holds true,
   * @return false otherwise.
   */
  constexpr bool operator==(type_info const &rhv) const noexcept {
    return false;
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
    return false;
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
    return 0;
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
    return nullptr;
  }
};
} // namespace std

#endif // PSTL_TYPE_INFO_STL_H
