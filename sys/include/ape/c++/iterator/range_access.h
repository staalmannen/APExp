// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="range_access.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_RANGE_ACCESS_H
#define PSTL_RANGE_ACCESS_H

#include "../common/size_t.h"
#include "../language_support/initializer_list.h"
#include "../metaprogramming/other_transformations/common_type.h"
#include "../metaprogramming/sign_modifications/make_signed.h"
#include "reverse_iterator.h"

namespace std {
/**
 * @brief Returns an iterator to the beginning of a container.
 *
 * @tparam container_type A container type or view type with a begin() member function.
 * @param container A container or view with a begin member function.
 * @return An iterator to the beginning of the range.
 */
template<class container_type> constexpr inline auto begin(container_type &container) -> decltype(container.begin()) {
  return container.begin();
}

/**
 * @brief Returns an iterator to the beginning of a container.
 *
 * @tparam container_type A container type or view type with a begin() member function.
 * @param container A container or view with a begin member function.
 * @return An iterator to the beginning of the range.
 */
template<class container_type>
constexpr inline auto begin(container_type const &container) -> decltype(container.begin()) {
  return container.begin();
}

/**
 * @brief Returns an iterator to the beginning of an array.
 *
 * @tparam t_type Elements type.
 * @tparam arr_size Array size.
 * @param array Given array.
 * @return An iterator to the beginning of the array.
 */
template<class t_type, ::std::size_t arr_size>
constexpr inline t_type *begin(t_type (&array)[arr_size]) noexcept {
  return array;
}

/**
 * @brief Returns an const iterator to the beginning of a container.
 *
 * @tparam container_type A container type or view type with a begin() member function.
 * @param container A container or view with a begin member function.
 * @return An iterator to the beginning of the range.
 */
template<class container_type>
constexpr inline auto cbegin(container_type const &container) noexcept(noexcept(::std::begin(container)))
  -> decltype(::std::begin(container)) {
  return ::std::begin(container);
}

/**
 * @brief Returns an const iterator to the end of a container.
 *
 * @tparam container_type A container type or view type with a end() member function.
 * @param container A container or view with a end member function.
 * @return An iterator to the end of the range. Note that the end of a range is defined as the element following the
 * last valid element.
 */
template<class container_type> constexpr inline auto end(container_type &container) -> decltype(container.end()) {
  return container.end();
}

/**
 * @brief Returns an const iterator to the end of a container.
 *
 * @tparam container_type A container type or view type with a end() member function.
 * @param container A container or view with a end member function.
 * @return An iterator to the end of the range. Note that the end of a range is defined as the element following the
 * last valid element.
 */
template<class container_type> constexpr inline auto end(container_type const &container) -> decltype(container.end()) {
  return container.end();
}

/**
 * @brief Returns an iterator to the end of an array.
 *
 * @tparam t_type Elements type.
 * @tparam arr_size Array size.
 * @param array Given array.
 * @return An iterator to the end of the range. Note that the end of a range is defined as the element following the
 * last valid element.
 */
template<class t_type, ::std::size_t arr_size>
constexpr inline t_type *end(t_type (&array)[arr_size]) noexcept {
  return array + arr_size;
}

/**
 * @brief Returns an const iterator to the end of a container.
 *
 * @tparam container_type A container type or view type with a end() member function.
 * @param container A container or view with a end member function.
 * @return An iterator to the end of the range. Note that the end of a range is defined as the element following the
 * last valid element.
 */
template<class container_type>
constexpr inline auto cend(container_type const &container) noexcept(noexcept(::std::end(container)))
  -> decltype(::std::end(container)) {
  return ::std::end(container);
}

/**
 * @brief Returns an iterator(reverse) to the reverse-beginning of the container or view.
 *
 * @tparam container_type A container type or view type with a rbegin() member function.
 * @param container A container or view with a rbegin member function.
 * @return An iterator to the reverse-beginning of the range.
 */
template<class container_type> constexpr inline auto rbegin(container_type &container) -> decltype(container.rbegin()) {
  return container.rbegin();
}

/**
 * @brief Returns an iterator(reverse) to the reverse-beginning of the const-qualified container or view.
 *
 * @tparam container_type A container type or view type with a rbegin() member function.
 * @param container A container or view with a rbegin member function.
 * @return An iterator to the reverse-beginning of the range.
 */
template<class container_type>
constexpr inline auto rbegin(container_type const &container) -> decltype(container.rbegin()) {
  return container.rbegin();
}

/**
 * @brief Returns an iterator(reverse) to the reverse-beginning of the array.
 *
 * @tparam t_type Elements type.
 * @tparam arr_size Array size.
 * @param array Given array.
 * @return An iterator to the reverse-beginning of the array.
 */
template<class t_type, ::std::size_t arr_size>
constexpr inline ::std::reverse_iterator<t_type *> rbegin(t_type (&array)[arr_size]) noexcept {
  return ::std::reverse_iterator<t_type *>(array + arr_size);
}

/**
 * @brief Returns an iterator(reverse) to the reverse-beginning of the std::initializer_list.
 *
 * @tparam t_type Elements type.
 * @param init_list Given Initializer list.
 * @return An iterator to the reverse-beginning of the list.
 */
template<class t_type>
constexpr inline ::std::reverse_iterator<t_type const *> rbegin(
  ::std::initializer_list<t_type> init_list) noexcept {
  return ::std::reverse_iterator<t_type const *>(init_list.end());
}

/**
 * @brief Returns an iterator(reverse) to the reverse-beginning of the container or view.
 *
 * @tparam container_type A container type or view type with a rbegin() member function.
 * @param container A container or view with a rbegin member function.
 * @return An iterator to the reverse-beginning of the range.
 */
template<class container_type>
constexpr inline auto crbegin(container_type const &container) noexcept(noexcept(::std::rbegin(container)))
  -> decltype(::std::rbegin(container)) {
  return ::std::rbegin(container);
}

/**
 * @brief Returns an iterator(reverse) to the reverse-end of the container or view.
 *
 * @tparam container_type A container type or view type with a rend() member function.
 * @param container A container or view with a rend member function.
 * @return An iterator to the reverse-end of the range.
 */
template<class container_type> constexpr inline auto rend(container_type &container) -> decltype(container.rend()) {
  return container.rend();
}

/**
 * @brief Returns an iterator(reverse) to the reverse-end of the const-qualified container or view.
 *
 * @tparam container_type A container type or view type with a rend() member function.
 * @param container A container or view with a rend member function.
 * @return An iterator to the reverse-end of the range.
 */
template<class container_type>
constexpr inline auto rend(container_type const &container) -> decltype(container.rend()) {
  return container.rend();
}

/**
 * @brief Returns an iterator(reverse) to the reverse-end of the array.
 *
 * @tparam t_type Elements type.
 * @tparam arr_size Array size.
 * @param array Given array.
 * @return An iterator to the reverse-end of the array.
 */
template<class t_type, ::std::size_t arr_size>
constexpr inline ::std::reverse_iterator<t_type *> rend(t_type (&array)[arr_size]) noexcept {
  return ::std::reverse_iterator<t_type *>(array);
}

/**
 * @brief Returns an iterator(reverse) to the reverse-end of the std::initializer_list.
 *
 * @tparam t_type Elements type.
 * @param init_list Given Initializer list.
 * @return An iterator to the reverse-end of the list.
 */
template<class t_type>
constexpr inline ::std::reverse_iterator<t_type const *> rend(
  ::std::initializer_list<t_type> init_list) noexcept {
  return ::std::reverse_iterator<t_type const *>(init_list.begin());
}

/**
 * @brief Returns an iterator(reverse) to the reverse-end of the container or view.
 *
 * @tparam container_type A container type or view type with a rend() member function.
 * @param container A container or view with a rend member function.
 * @return An iterator to the reverse-end of the range.
 */
template<class container_type>
constexpr inline auto crend(container_type const &container) noexcept(noexcept(::std::rend(container)))
  -> decltype(::std::rend(container)) {
  return ::std::rend(container);
}

/**
 * @brief Returns the size of the given range.
 *
 * @tparam container_type A container type or view type with a size() member function.
 * @param container A container or view with a size member function.
 * @return The size of container.
 */
template<class container_type> constexpr auto size(container_type const &container) -> decltype(container.size()) {
  return container.size();
}

/**
 * @brief Returns the size of the given range.
 *
 * @tparam container_type A container type or view type with a size() member function.
 * @param container A container or view with a size member function.
 * @return The size of container.
 */
template<class container_type>
constexpr auto ssize(container_type const &container)
  -> ::std::common_type_t<::std::make_signed_t<decltype(container.size())>,
                                   ::std::ptrdiff_t> {
  using return_type = ::std::common_type_t<::std::make_signed_t<decltype(container.size())>,
                                                    ::std::ptrdiff_t>;
  return static_cast<return_type>(container.size());
}

/**
 * @brief Returns the size of the given range.
 *
 * @tparam t_type Elements type
 * @tparam arr_size Array size.
 * @return The size of array.
 */
template<class t_type, ::std::size_t arr_size>
constexpr ::std::size_t size(t_type const (&)[arr_size]) noexcept {
  return arr_size;
}

/**
 * @brief Returns the size of the given range.
 *
 * @tparam t_type Elements type.
 * @tparam arr_size Array size.
 * @return The size of array.
 */
template<class t_type, ::std::size_t arr_size>
constexpr ::std::ptrdiff_t ssize(t_type const (&)[arr_size]) noexcept {
  return static_cast<::std::ptrdiff_t>(arr_size);
}

/**
 * @brief Checks whether the container is empty.
 *
 * @tparam container_type
 * @param container A container or view with a empty() member function.
 * @return true if container is empty.
 */
template<class container_type>
constexpr inline auto empty(container_type const &container) -> decltype(container.empty()) {
  return container.empty();
}

/**
 * @brief Checks whether the array is empty.
 *
 * @tparam t_type Elements type.
 * @tparam arr_size Array size.
 * @return false
 */
template<class t_type, ::std::size_t arr_size> constexpr inline bool empty(t_type const (&)[arr_size]) noexcept {
  return false;
}

/**
 * @brief Checks whether the initializer list is empty.
 *
 * @tparam t_type Elements type.
 * @param init_list Given initializer list.
 * @return true if init_list is empty.
 * @return false if init_list is not empty.
 */
template<class t_type> constexpr inline bool empty(::std::initializer_list<t_type> init_list) noexcept {
  return init_list.size() == 0U;
}

/**
 * @brief Returns a pointer to the block of memory containing the elements of the range.
 *
 * @tparam container_type A container or view with a data() member function.
 * @param container Given container.
 * @return A pointer to the block of memory containing the elements of the range.
 */
template<class container_type> constexpr inline auto data(container_type &container) -> decltype(container.data()) {
  return container.data();
}

/**
 * @brief Returns a pointer to the block of memory containing the elements of the range.
 *
 * @tparam container_type A container or view with a data() member function.
 * @param container Given container.
 * @return A pointer to the block of memory containing the elements of the range.
 */
template<class container_type>
constexpr inline auto data(container_type const &container) -> decltype(container.data()) {
  return container.data();
}

/**
 * @brief Returns a pointer to the block of memory containing the elements of the range.
 *
 * @tparam t_type Elements type.
 * @tparam arr_size Array size.
 * @param array Given array.
 * @return A pointer to the block of memory containing the elements of the range.
 */
template<class t_type, ::std::size_t arr_size> constexpr inline t_type *data(t_type (&array)[arr_size]) noexcept {
  return array;
}

/**
 * @brief Returns a pointer to the block of memory containing the elements of the range.
 *
 * @tparam t_type Elements type.
 * @param init_list Given initializer list.
 * @return A pointer to the block of memory containing the elements of the range.
 */
template<class t_type>
constexpr inline t_type const *data(::std::initializer_list<t_type> init_list) noexcept {
  return init_list.begin();
}

} // namespace std

#endif // PSTL_RANGE_ACCESS_H
