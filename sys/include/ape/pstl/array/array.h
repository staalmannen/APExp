// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="array.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ARRAY_H
#define PSTL_ARRAY_H

#include "../algorithm/fill_n.h"
#include "../common/ptrdiff_t.h"
#include "../common/size_t.h"
#include "../iterator/reverse_iterator.h"
#include "../language_support/out_of_range.h"
#include "../metaprogramming/cv_modifications/add_const.h"
#include "../metaprogramming/pointer_modifications/add_pointer.h"
#include "../metaprogramming/reference_modifications/add_lvalue_reference.h"
#include "../metaprogramming/type_properties/is_nothrow_swappable.h"
#include "../algorithm/swap_ranges.h"


#if defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  include "../language_support/exception/throw_on_true.h"
#else
#  include "../language_support/no_exception/throw_on_true.h"
#endif

namespace portable_stl {
/**
 * @brief Container that encapsulates fixed size arrays.
 *
 * @tparam t_type Element type.
 * @tparam t_size The number of elements in the array or 0.
 */
template<class t_type, size_t t_size> class array final {
public:
  /**
   * @brief Value type.
   */
  using value_type = t_type;

  /**
   * @brief Size type.
   */
  using size_type = ::portable_stl::size_t;

  /**
   * @brief Difference type.
   *
   */
  using difference_type = ::portable_stl::ptrdiff_t;

  /**
   * @brief Reference type.
   *
   */
  using reference = ::portable_stl::add_lvalue_reference_t<value_type>;

  /**
   * @brief Reference to const type.
   *
   */
  using const_reference = ::portable_stl::add_lvalue_reference_t<::portable_stl::add_const_t<value_type>>;

  /**
   * @brief Pointer type.
   *
   */
  using pointer = ::portable_stl::add_pointer_t<value_type>;

  /**
   * @brief Const pointer type.
   *
   */
  using const_pointer = ::portable_stl::add_const_t<value_type> *;

  /**
   * @brief Iterator type.
   *
   */
  using iterator = pointer;

  /**
   * @brief Const iterator type.
   *
   */
  using const_iterator = const_pointer;

  /**
   * @brief Reverse iterator type.
   *
   */
  using reverse_iterator = ::portable_stl::reverse_iterator<iterator>;

  /**
   * @brief Const reverse iterator type.
   *
   */
  using const_reverse_iterator = ::portable_stl::reverse_iterator<const_iterator>;

  /**
   * @brief Storage for array elements.
   * Public for aggregate initialization.
   */
  t_type m_elements[t_size];

  /**
   * @brief Access specified element with bounds checking.
   * If position is not within the range of the container, an exception of type out_of_range is thrown.
   * @param position The position of the element to return.
   *
   * @return Reference to the requested element.
   */
  reference at(size_type position);

  /**
   * @brief Access (const) specified element with bounds checking.
   * If position is not within the range of the container, an exception of type out_of_range is thrown.
   * @param position The position of the element to return.
   *
   * @return Const reference to the requested element.
   */
  constexpr const_reference at(size_type position) const;

  /**
   * @brief Access specified element.
   * No bounds checking is performed.
   * @param position The psition of the element to return.
   *
   * @return Reference to the requested element.
   */
  reference operator[](size_type position) noexcept {
    return m_elements[position];
  }

  /**
   * @brief Access (const) specified element.
   * No bounds checking is performed.
   * @param position The psition of the element to return.
   *
   * @return Const reference to the requested element.
   */
  constexpr const_reference operator[](size_type position) const noexcept {
    return m_elements[position];
  }

  /**
   * @brief Access the first element.
   * Calling front on an empty container causes undefined behavior.
   *
   * @return Reference to the first element.
   */
  reference front() noexcept {
    return m_elements[0];
  }

  /**
   * @brief Access (const) the first element.
   * Calling front on an empty container causes undefined behavior.
   *
   * @return Const reference to the first element.
   */
  constexpr const_reference front() const noexcept {
    return m_elements[0];
  }

  /**
   * @brief Access the last element.
   * Calling back on an empty container causes undefined behavior.
   *
   * @return Reference to the last element.
   */
  reference back() noexcept {
    return m_elements[t_size - 1U];
  }

  /**
   * @brief Access (const) the last element.
   * Calling back on an empty container causes undefined behavior.
   *
   * @return Const reference to the last element.
   */
  constexpr const_reference back() const noexcept {
    return m_elements[t_size - 1U];
  }

  /**
   * @brief Direct access to the underlying contiguous storage.
   *
   * @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to
   * the address of the first element.
   */
  pointer data() noexcept {
    return &m_elements[0];
  }

  /**
   * @brief Direct access (const) to the underlying contiguous storage.
   *
   * @return Const pointer to the underlying element storage. For non-empty containers, the returned pointer compares
   * equal to the address of the first element.
   */
  constexpr const_pointer data() const noexcept {
    return &m_elements[0];
  }

  /**
   * @brief Returns an iterator to the beginning.
   *
   * @return Iterator to the first element.
   */
  iterator begin() noexcept {
    return &m_elements[0];
  }

  /**
   * @brief Returns an const iterator to the beginning.
   *
   * @return Const iterator to the first element.
   */
  constexpr const_iterator begin() const noexcept {
    return &m_elements[0];
  }

  /**
   * @brief Returns an const iterator to the beginning.
   *
   * @return Const iterator to the first element.
   */
  constexpr const_iterator cbegin() const noexcept {
    return &m_elements[0];
  }

  /**
   * @brief Returns an iterator to the end.
   * Returns an iterator to the element following the last element of the array.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   *
   * @return Iterator to the element following the last element.
   */
  iterator end() noexcept {
    return &m_elements[t_size];
  }

  /**
   * @brief Returns an const iterator to the end.
   * Returns an iterator to the element following the last element of the array.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   *
   * @return Const iterator to the element following the last element.
   */
  constexpr const_iterator end() const noexcept {
    return &m_elements[t_size];
  }

  /**
   * @brief Returns an const iterator to the end.
   * Returns an iterator to the element following the last element of the array.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   *
   * @return Const iterator to the element following the last element.
   */
  constexpr const_iterator cend() const noexcept {
    return &m_elements[t_size];
  }

  /**
   * @brief Returns a reverse iterator to the beginning.
   * Returns a reverse iterator to the first element of the reversed array. It corresponds to the last element of the
   * non-reversed array. If the array is empty, the returned iterator is equal to rend().
   *
   * @return Reverse iterator to the first element.
   */
  reverse_iterator rbegin() noexcept {
    return reverse_iterator(end());
  }

  /**
   * @brief Returns a const reverse iterator to the beginning.
   * Returns a reverse iterator to the first element of the reversed array. It corresponds to the last element of the
   * non-reversed array. If the array is empty, the returned iterator is equal to rend().
   *
   * @return Const reverse iterator to the first element.
   */
  constexpr const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator(cend());
  }

  /**
   * @brief Returns a const reverse iterator to the beginning.
   * Returns a reverse iterator to the first element of the reversed array. It corresponds to the last element of the
   * non-reversed array. If the array is empty, the returned iterator is equal to rend().
   *
   * @return Const reverse iterator to the first element.
   */
  constexpr const_reverse_iterator crbegin() const noexcept {
    return const_reverse_iterator(cend());
  }

  /**
   * @brief Returns a reverse iterator to the end.
   * Returns a reverse iterator to the element following the last element of the reversed array. It corresponds to the
   * element preceding the first element of the non-reversed array. This element acts as a placeholder, attempting to
   * access it results in undefined behavior.
   *
   * @return Reverse iterator to the element following the last element.
   */
  reverse_iterator rend() noexcept {
    return reverse_iterator(begin());
  }

  /**
   * @brief Returns a const reverse iterator to the end.
   * Returns a reverse iterator to the element following the last element of the reversed array. It corresponds to the
   * element preceding the first element of the non-reversed array. This element acts as a placeholder, attempting to
   * access it results in undefined behavior.
   *
   * @return Const reverse iterator to the element following the last element.
   */
  constexpr const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator(begin());
  }

  /**
   * @brief Returns a const reverse iterator to the end.
   * Returns a reverse iterator to the element following the last element of the reversed array. It corresponds to the
   * element preceding the first element of the non-reversed array. This element acts as a placeholder, attempting to
   * access it results in undefined behavior.
   *
   * @return Const reverse iterator to the element following the last element.
   */
  constexpr const_reverse_iterator crend() const noexcept {
    return const_reverse_iterator(cbegin());
  }

  /**
   * @brief Checks whether the container is empty.
   *
   * @return true if the container is empty,
   * @return false otherwise.
   */
  constexpr static bool empty() noexcept {
    return 0U == t_size;
  }

  /**
   * @brief Returns the number of elements.
   *
   * @return The number of elements in the container.
   */
  constexpr static size_type size() noexcept {
    return t_size;
  }

  /**
   * @brief Returns the maximum possible number of elements.
   * @return Maximum number of elements.
   */
  constexpr static size_type max_size() noexcept {
    return size();
  }

  /**
   * @brief Fill the container with specified value.
   *
   * @param value The value to assign to the elements.
   */
  void fill(const_reference value) noexcept(noexcept(fill_n(begin(), t_size, value))) {
    static_cast<void>(::portable_stl::fill_n(begin(), t_size, value));
  }

  /**
   * @brief Swaps the contents.
   * Exchanges the contents of the container with those of other. Does not cause iterators and references to associate
   * with the other container.
   *
   * @param other Container to exchange the contents with.
   */
  void swap(array &other) noexcept(::portable_stl::is_nothrow_swappable<value_type>{}()) {
    static_cast<void>(::portable_stl::swap_ranges(begin(), end(), other.begin()));
  }
};

/**
 * @brief Access specified element with bounds checking.
 * If position is not within the range of the container, an exception of type out_of_range is thrown.
 *
 * @tparam t_type Array values type.
 * @tparam t_size Array size.
 * @param position The position of the element to return.
 * @return Reference to the requested element.
 */
template<class t_type, size_t t_size> inline auto array<t_type, t_size>::at(size_type const position) -> reference {
  ::portable_stl::throw_on_true<::portable_stl::out_of_range<>>((position > t_size));
  return m_elements[position];
}

/**
 * @brief Access (const) specified element with bounds checking.
 * If position is not within the range of the container, an exception of type out_of_range is thrown.
 *
 * @tparam t_type Array values type.
 * @tparam t_size Array size.
 * @param position The position of the element to return.
 * @return Const reference to the requested element.
 */
template<class t_type, size_t t_size>
constexpr inline auto array<t_type, t_size>::at(size_type const position) const -> const_reference {
  ::portable_stl::throw_on_true<::portable_stl::out_of_range<>>((position > t_size));
  return m_elements[position];
}

} // namespace portable_stl

#endif // PSTL_ARRAY_H
