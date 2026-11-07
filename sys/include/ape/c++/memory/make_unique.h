// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="make_unique.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MAKE_UNIQUE_H
#define PSTL_MAKE_UNIQUE_H

#include "../metaprogramming/array_modifications/remove_extent.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/primary_type/is_array.h"
#include "../metaprogramming/type_properties/is_bounded_array.h"
#include "unique_ptr.h"

namespace std {

/**
 * @brief Constructs a non-array type t_value. The arguments are passed to the constructor of t_value.
 *
 * @tparam t_value the type for unique pointer.
 * @tparam t_arguments the type of constructor arguments.
 * @param arguments the values for constructor arguments.
 * @return unique_ptr<t_value>.
 */
template<class t_value,
         class... t_arguments,
         ::std::enable_if_bool_constant_t<::std::negation<::std::is_array<t_value>>, void *>
         = nullptr>
inline static ::std::unique_ptr<t_value> make_unique(t_arguments &&...arguments) {
  return ::std::unique_ptr<t_value>(new t_value(::std::forward<t_arguments>(arguments)...));
}

/**
 * @brief Constructs a non-array type t_value. The arguments are passed to the constructor of t_value.
 *
 * @tparam t_value the type for unique pointer.
 * @tparam t_deleter The type of remover of the object pointed to by the stored pointer.
 * @tparam t_arguments the type of constructor arguments.
 * @param deleter_value the deleter value.
 * @param arguments the values for constructor arguments.
 * @return unique_ptr<t_value>.
 */
template<class t_value,
         class t_deleter,
         class... t_arguments,
         ::std::enable_if_bool_constant_t<::std::negation<::std::is_array<t_value>>, void *>
         = nullptr>
inline static ::std::unique_ptr<t_value, t_deleter> make_unique_with_deleter(t_deleter &&deleter_value,
                                                                           t_arguments &&...arguments) noexcept {
  return ::std::unique_ptr<t_value, t_deleter>(
         new t_value(::std::forward<t_arguments>(arguments)...), ::std::forward<t_deleter>(deleter_value));
}

/**
 * @brief Constructs a non-array type t_value. The object is default-initialized.
 *
 * @tparam t_value the type for unique pointer.
 * @return unique_ptr<t_value>
 */
template<class t_value,
         ::std::enable_if_bool_constant_t<::std::negation<::std::is_array<t_value>>, void *>
         = nullptr>
inline static ::std::unique_ptr<t_value> make_unique_for_overwrite() {
  return unique_ptr<t_value>(new t_value);
}

/**
 * @brief Constructs an array of the given dynamic size. The array elements are value-initialized.
 *
 * @tparam t_value the type for unique pointer.
 * @param array_size the size of new array.
 * @return unique_ptr<t_value>
 */
template<class t_value, ::std::enable_if_bool_constant_t<::std::is_array<t_value>, void *> = nullptr>
inline static ::std::unique_ptr<t_value> make_unique(size_t array_size) {
  return unique_ptr<t_value>(new ::std::remove_extent_t<t_value>[array_size]());
}

/**
 * @brief Constructs an array of the given dynamic size. The array elements are value-initialized.
 *
 * @tparam t_value the type for unique pointer.
 * @tparam t_deleter The type of remover of the object pointed to by the stored pointer.
 * @param deleter_value the deleter value.
 * @param array_size the size of new array.
 * @return unique_ptr<t_value>
 */
template<class t_value,
         class t_deleter,
         ::std::enable_if_bool_constant_t<::std::is_array<t_value>, void *> = nullptr>
inline static ::std::unique_ptr<t_value, t_deleter> make_unique_with_deleter(t_deleter &&deleter_value,
                                                                           size_t      array_size) noexcept {
  return unique_ptr<t_value, t_deleter>(
         new ::std::remove_extent_t<t_value>[array_size](), ::std::forward<t_deleter>(deleter_value));
}

/**
 * @brief Constructs an array of the given dynamic size. The array is default-initialized.
 *
 * @tparam t_value the type for unique pointer.
 * @param array_size the size of new array.
 * @return unique_ptr<t_value>
 */
template<class t_value, ::std::enable_if_bool_constant_t<::std::is_array<t_value>, void *> = nullptr>
inline static ::std::unique_ptr<t_value> make_unique_for_overwrite(size_t array_size) {
  return unique_ptr<t_value>(new ::std::remove_extent_t<t_value>[array_size]);
}

/**
 * @brief Construction of arrays of known bound is disallowed.
 *
 * @tparam t_value the type for unique pointer.
 */
template<class t_value,
         class... t_arguments,
         ::std::enable_if_bool_constant_t<::std::is_bounded_array<t_value>, void *> = nullptr>
void make_unique(t_arguments &&...) = delete;

/**
 * @brief Construction of arrays of known bound is disallowed.
 *
 * @tparam t_value the type for unique pointer.
 */
template<class t_value,
         class... t_arguments,
         ::std::enable_if_bool_constant_t<::std::is_bounded_array<t_value>, void *> = nullptr>
void make_unique_for_overwrite(t_arguments &&...) = delete;

} // namespace std

#endif // PSTL_MAKE_UNIQUE_H
