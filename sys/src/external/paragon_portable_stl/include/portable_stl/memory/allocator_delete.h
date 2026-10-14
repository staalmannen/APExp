// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="allocator_delete.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ALLOCATOR_DELETE_H
#define PSTL_ALLOCATOR_DELETE_H

#include "../error/portable_stl_error.h"
#include "../utility/expected/exception_pack.h"
#include "allocator.h"
#include "portable_stl/memory/allocator_traits.h"
#include "portable_stl/memory/destroy_at.h"

namespace portable_stl {
/**
 * @brief Allocator destruction policy for the class template unique_ptr.
 * @tparam t_type the type of object for delete.
 * The template parameter t_type of may be an incomplete type.
 */
template<class t_type, class t_allocator = ::portable_stl::allocator<t_type>>
class allocator_delete : private t_allocator {
public:
  /**
   * @brief Construct deleter object.
   */
  constexpr allocator_delete(t_allocator allocator) noexcept : t_allocator(allocator) {
  }
  /**
   * @brief Destroy the allocator delete object
   *
   */
  ~allocator_delete() noexcept                                             = default;
  /**
   * @brief Copy construct deleter object.
   */
  constexpr allocator_delete(allocator_delete const &) noexcept            = default;
  /**
   * @brief Copy assign deleter object.
   */
  constexpr allocator_delete &operator=(allocator_delete const &) noexcept = default;

  /**
   * @brief Construct deleter object from other deleter object.
   *
   * @tparam t_other_type the type of other deleter object.
   */
  template<class t_other_type>
  constexpr allocator_delete(allocator_delete<t_other_type, t_allocator> const &other) noexcept : t_allocator(other) {
  }
  /**
   * @brief Delete function.
   *
   * @param object the object for delete.
   */
  inline expected<void, ::portable_stl::portable_stl_error> operator()(t_type *const object) noexcept {
    return exception_pack<::portable_stl::portable_stl_error, ::portable_stl::portable_stl_error::delete_error>{}(
      [this](t_type *const obj) -> void {
        ::portable_stl::destroy_at(obj);
        ::portable_stl::allocator_traits<t_allocator>::deallocate(*this, obj, 1U);
      },
      object);
  }
};

/**
 * @brief Allocator destruction policy for the class template unique_ptr.
 * @tparam t_type the type of object for delete.
 * The template parameter t_type of may be an incomplete type.
 */
template<class t_type, class t_allocator> class allocator_delete<t_type[], t_allocator> : private t_allocator {
public:
  /**
   * @brief Construct deleter object.
   */
  constexpr allocator_delete(t_allocator allocator) noexcept : t_allocator(allocator) {
  }
  /**
   * @brief Destroy the allocator delete object
   *
   */
  ~allocator_delete() noexcept                                        = default;
  /**
   * @brief Copy construct deleter object.
   */
  constexpr allocator_delete(allocator_delete const &) noexcept            = default;
  /**
   * @brief Copy assign deleter object.
   */
  constexpr allocator_delete &operator=(allocator_delete const &) noexcept = default;

  /**
   * @brief Construct deleter object from other deleter object.
   *
   * @tparam t_other_type the type of other deleter object.
   */
  template<class t_other_type>
  constexpr allocator_delete(allocator_delete<t_other_type[], t_allocator> const &other) noexcept : t_allocator(other) {
  }
  /**
   * @brief Delete function.
   *
   * @param object the object for delete.
   */
  template<class t_other_type>
  inline expected<void, ::portable_stl::portable_stl_error> operator()(t_other_type *const object) noexcept {
    return exception_pack<::portable_stl::portable_stl_error, ::portable_stl::portable_stl_error::delete_error>{}(
      [this](t_type *const obj) -> void {
        // ::portable_stl::destroy_at(obj);
        ::portable_stl::allocator_traits<t_allocator>::deallocate(*this, obj, 1U);
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
constexpr inline static void swap(allocator_delete<t_value> &, allocator_delete<t_value> &) noexcept {
}

} // namespace portable_stl

#endif // PSTL_ALLOCATOR_DELETE_H
