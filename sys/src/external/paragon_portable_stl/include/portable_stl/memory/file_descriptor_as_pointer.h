// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="file_descriptor_as_pointer.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FILE_DESCRIPTOR_AS_POINTER_H
#define PSTL_FILE_DESCRIPTOR_AS_POINTER_H

#include "../metaprogramming/other_transformations/common_type.h"

namespace portable_stl {
/**
 * @brief Helper class for use uniue_ptr as holder for unix file descriptor.
 *
 * @tparam t_value the type of file descriptor.
 * @tparam t_invalid_value the value of invalid file descriptor.
 */
template<class t_value, t_value t_invalid_value> class file_descriptor_as_pointer final {
  /**
   * @brief Storage for file descriptor.
   */
  t_value m_file_descriptor_value;

public:
  /**
   * @brief Destroy object.
   *
   */
  ~file_descriptor_as_pointer() noexcept                                               = default;
  /**
   * @brief Default constructor copy.
   */
  file_descriptor_as_pointer(file_descriptor_as_pointer const &) noexcept              = default;
  /**
   * @brief Default constructor move.
   */
  file_descriptor_as_pointer(file_descriptor_as_pointer &&) noexcept                   = default;
  /**
   * @brief Default assignment copy.
   */
  file_descriptor_as_pointer &operator=(file_descriptor_as_pointer const &) & noexcept = default;
  /**
   * @brief Default assignment move.
   */
  file_descriptor_as_pointer &operator=(file_descriptor_as_pointer &&) & noexcept      = default;
  /**
   * @brief Default constructor with value.
   * @param pointer_value the value for assignment.
   */
  constexpr file_descriptor_as_pointer(t_value pointer_value) noexcept : m_file_descriptor_value(pointer_value) {
  }
  /**
   * @brief Default constructor.
   */
  constexpr file_descriptor_as_pointer() noexcept : file_descriptor_as_pointer(t_invalid_value) {
  }
  /**
   * @brief Swap with other.
   *
   * @param other the value for swap.
   */
  void local_swap(file_descriptor_as_pointer &other) noexcept {
    ::portable_stl::swap(m_file_descriptor_value, other.m_file_descriptor_value);
  }
  /**
   * @brief Value getter.
   *
   * @return value.
   */
  t_value &operator*() const noexcept {
    return const_cast<t_value &>(m_file_descriptor_value);
  }
};
/**
 * @brief Swap with other.
 *
 * @param left the value for swap.
 * @param right the value for swap.
 */
template<class t_value, t_value t_invalid_value>
inline static void swap(portable_stl::file_descriptor_as_pointer<t_value, t_invalid_value> &left,
                        portable_stl::file_descriptor_as_pointer<t_value, t_invalid_value> &right) noexcept {
  left.local_swap(right);
}
/**
 * @brief Compare with other descriptor.
 * @param left the value for compare.
 * @param right the value for compare.
 * @return result of compare.
 * @retval true if left descriptor equal right descriptor.
 * @retval false if left descriptor not equal right descriptor.
 */
template<class t_value_left,
         t_value_left t_invalid_value_left,
         class t_value_right,
         t_value_right t_invalid_value_right>
inline static bool operator==(
  portable_stl::file_descriptor_as_pointer<t_value_left, t_invalid_value_left> const   &left,
  portable_stl::file_descriptor_as_pointer<t_value_right, t_invalid_value_right> const &right) noexcept {
  return ((*left) == (*right));
}
/**
 * @brief Compare with other descriptor.
 * @param left the value for compare.
 * @param right the value for compare.
 * @return result of compare.
 * @retval true if left descriptor less right descriptor.
 * @retval false if left descriptor not less right descriptor.
 */
template<class t_value_left,
         t_value_left t_invalid_value_left,
         class t_value_right,
         t_value_right t_invalid_value_right>
inline static bool operator<(
  portable_stl::file_descriptor_as_pointer<t_value_left, t_invalid_value_left> const   &left,
  portable_stl::file_descriptor_as_pointer<t_value_right, t_invalid_value_right> const &right) noexcept {
  return ::portable_stl::less<::portable_stl::common_type_t<t_value_left, t_value_right>>()((*left), (*right));
}

} // namespace portable_stl

#endif // PSTL_FILE_DESCRIPTOR_AS_POINTER_H
