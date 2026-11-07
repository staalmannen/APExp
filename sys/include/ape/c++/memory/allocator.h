// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="allocator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ALLOCATOR_H
#define PSTL_ALLOCATOR_H
#include "../common/ptrdiff_t.h"
#include "../common/size_t.h"
#include "../error/portable_stl_error.h"
#include "../metaprogramming/helper/integral_constant.h"
#include "../utility/expected/exception_pack.h"
#include "../utility/expected/expected.h"
#include "allocation_result.h"

namespace std {
/**
 * @brief the std::allocator class template is the default Allocator used by all standard library containers if
 * no user-specified allocator is provided. The default allocator is stateless, that is, all instances of the given
 * allocator are interchangeable, compare equal and can deallocate memory allocated by any other instance of the same
 * allocator type.
 *
 * @tparam t_type the type for memory allocate.
 */
template<class t_type> class allocator {
public:
  /**
   * @brief The work value type.
   *
   */
  using value_type = t_type;

  /**
   * @brief Can use move assignment on allocator in containers.
   *
   */
  using propagate_on_container_move_assignment = ::std::true_type;

  /**
   * @brief Default constructor.
   *
   */
  allocator() noexcept = default;

  /**
   * @brief Default constructor.
   *
   */
  allocator(allocator const &) noexcept = default;

  /**
   * @brief Constructor for allocator from allocator with other type.
   *
   */
  template<class t_other_type> allocator(allocator<t_other_type> const &) noexcept {
  }

  /**
   * @brief Destroy the allocator object
   */
  ~allocator() noexcept = default;

  /**
   * @brief Default assignment.
   *
   */
  allocator &operator=(allocator const &) = default;

  /**
   * @brief Allocates uninitialized storage.
   *
   * @param size_value the number of objects to allocate storage for.
   * @return Pointer to the first element of an array of size_value objects of type value_type whose elements have not
   * been constructed yet.
   */
  value_type *allocate(::std::size_t const size_value) noexcept {
    return ::std::exception_pack<::std::std_error,
                                          ::std::std_error::allocate_error>{}(
             [](::std::size_t const size_val) -> value_type * {
               return {static_cast<value_type *>(::operator new(size_val * sizeof(value_type)))};
             },
             size_value)
      .value_or(nullptr);
  }

  /**
   * @brief Allocates uninitialized storage at least as large as requested size.
   *
   * @param size_value the lower bound of number of objects to allocate storage for.
   * @return std::allocation_result<T*>{pointer, size_value}, where pointer points to the first element of an array of
   * size_value objects of type value_type whose elements have not been constructed yet.
   */
  ::std::allocation_result<value_type *> allocate_at_least(::std::size_t const size_value) noexcept {
    return {allocate(size_value), size_value};
  }

  /**
   * @brief deallocates storage
   *
   * @param pointer_value pointer obtained from allocate() or allocate_at_least()
   * @param size_value number of objects earlier passed to allocate(), or a number between requested and actually
   * allocated number of objects via allocate_at_least() (may be equal to either bound)
   */
  void deallocate(value_type *pointer_value, ::std::size_t size_value) noexcept {
    static_cast<void>(::std::exception_pack<::std::std_error,
                                                     ::std::std_error::delete_error>{}(
      [](value_type *const pointer_val) -> void {
        ::operator delete(pointer_val);
      },
      pointer_value));
    static_cast<void>(size_value);
  }
};
/**
 * @brief compares two allocator instances.
 * @return compare status ( always true ).
 */
template<class t_left_value, class t_right_value>
inline static bool operator==(allocator<t_left_value> const &, allocator<t_right_value> const &) noexcept {
  return true;
}

/**
 * @brief compares two allocator instances.
 * @return compare status ( always false ).
 */
template<class t_left_value, class t_right_value>
inline static bool operator!=(allocator<t_left_value> const &, allocator<t_right_value> const &) noexcept {
  return false;
}

} // namespace std

#endif // PSTL_ALLOCATOR_H
