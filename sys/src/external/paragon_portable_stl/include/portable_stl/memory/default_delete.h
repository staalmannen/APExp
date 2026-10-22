// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="default_delete.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_DEFAULT_DELETE_H
#define PSTL_DEFAULT_DELETE_H

#include "../error/portable_stl_error.h"
#include "../utility/expected/exception_pack.h"

namespace portable_stl {
/**
 * @brief Default destruction policy for the class template unique_ptr.
 * @tparam t_type the type of object for delete.
 * The template parameter t_type of may be an incomplete type.
 */
template<class t_type> class default_delete {
public:
  /**
   * @brief Construct deleter object.
   */
  constexpr default_delete() noexcept = default;
  /**
   * @brief Construct deleter object from other deleter object.
   *
   * @tparam t_other_type the type of other deleter object.
   */
  template<class t_other_type> constexpr default_delete(default_delete<t_other_type> const &) noexcept {
  }
  /**
   * @brief Delete function.
   *
   * @param object the object for delete.
   */
  inline expected<void, ::portable_stl::portable_stl_error> operator()(t_type *const object) const noexcept {
    return exception_pack<::portable_stl::portable_stl_error, ::portable_stl::portable_stl_error::delete_error>{}(
      [](t_type *const obj) -> void {
        ::delete obj;
      },
      object);
  }
};

/**
 * @brief Default destruction policy for the class template unique_ptr.
 * @tparam t_type the type of object for delete.
 * The template parameter t_type of may be an incomplete type.
 */
template<class t_type> class default_delete<t_type[]> {
public:
  /**
   * @brief Construct deleter object.
   */
  constexpr default_delete() noexcept = default;
  /**
   * @brief Construct deleter object from other deleter object.
   *
   * @tparam t_other_type the type of other deleter object.
   */
  template<class t_other_type> constexpr default_delete(default_delete<t_other_type[]> const &) noexcept {
  }
  /**
   * @brief Delete function.
   *
   * @param object the object for delete.
   */
  template<class t_other_type>
  inline expected<void, ::portable_stl::portable_stl_error> operator()(t_other_type *const object) const noexcept {
    return exception_pack<::portable_stl::portable_stl_error, ::portable_stl::portable_stl_error::delete_error>{}(
      [](t_type *const obj) -> void {
        ::delete[] obj;
      },
      object);
  }
};

/**
 * @brief Swap two default deleter object.
 *
 * @tparam t_value the type of default deleter.
 */
template<class t_value>
constexpr inline static void swap(default_delete<t_value> &, default_delete<t_value> &) noexcept {
}

} // namespace portable_stl

#endif /* PSTL_DEFAULT_DELETE_H */
