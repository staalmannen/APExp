// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_element.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_ELEMENT_H
#define PSTL_TUPLE_ELEMENT_H

#include "../../common/size_t.h"
#include "../../metaprogramming/cv_modifications/add_const.h"
#include "../../metaprogramming/cv_modifications/add_cv.h"
#include "../../metaprogramming/cv_modifications/add_volatile.h"
#include "fwd_decl_array.h"
#include "fwd_decl_tuple.h"

namespace portable_stl {

/**
 * @brief Obtains the type of the specified element.
 * Forward declaration.
 * @tparam t_idx Index of the element in tuple.
 * @tparam t_tuple Given tuple type.
 */
template<::portable_stl::size_t t_idx, class t_tuple> class tuple_element;

/**
 * @brief Obtains the type of the specified element.
 * Implementation for const tuple.
 *
 * @tparam t_idx Index of the element in tuple.
 * @tparam t_tuple Given tuple type.
 */
template<::portable_stl::size_t t_idx, class t_tuple>
class tuple_element<t_idx, t_tuple const> : public tuple_element<t_idx, t_tuple> {
public:
  /**
   * @brief Element type itself without type qualifiers.
   */
  using t_base_type = tuple_element<t_idx, t_tuple>;
  /**
   * @brief The type of t_idx-th element of the tuple.
   */
  using type        = ::portable_stl::add_const_t<typename t_base_type::type>;
};

/**
 * @brief Obtains the type of the specified element.
 * Implementation for volatile tuple.
 *
 * @tparam t_idx Index of the element in tuple.
 * @tparam t_tuple Given tuple type.
 */
template<::portable_stl::size_t t_idx, class t_tuple>
class tuple_element<t_idx, t_tuple volatile> : public tuple_element<t_idx, t_tuple> {
public:
  /**
   * @brief Element type itself without type qualifiers.
   */
  using t_base_type = tuple_element<t_idx, t_tuple>;
  /**
   * @brief The type of t_idx-th element of the tuple.
   */
  using type        = ::portable_stl::add_volatile_t<typename t_base_type::type>;
};

/**
 * @brief Obtains the type of the specified element.
 * Implementation for const volatile tuple.
 *
 * @tparam t_idx Index of the element in tuple.
 * @tparam t_tuple Given tuple type.
 */
template<::portable_stl::size_t t_idx, class t_tuple>
class tuple_element<t_idx, t_tuple const volatile> : public tuple_element<t_idx, t_tuple> {
public:
  /**
   * @brief Element type itself without type qualifiers.
   */
  using t_base_type = tuple_element<t_idx, t_tuple>;
  /**
   * @brief The type of t_idx-th element of the tuple.
   */
  using type        = ::portable_stl::add_cv_t<typename t_base_type::type>;
};

/**
 * @brief TRANSITION, CWG-2518: false value attached to a dependent name (for static_assert).
 */
template<class> constexpr bool _Always_false = false;

/**
 * @brief Enforce bounds checking.
 * @tparam t_idx Index of the element in tuple.
 */
template<::portable_stl::size_t t_idx> class tuple_element<t_idx, ::portable_stl::tuple<>> {
  static_assert(_Always_false<::portable_stl::integral_constant<::portable_stl::size_t, t_idx>>,
                "tuple index out of bounds");
};

/**
 * @brief Case with first selected element.
 * Part of the recursive tuple_element definition.
 * @tparam t_this_type First type of the tuple.
 * @tparam t_rest Rest types of the tuple.
 */
template<class t_this_type, class... t_rest> class tuple_element<0, ::portable_stl::tuple<t_this_type, t_rest...>> {
public:
  /**
   * @brief The type of first element of the tuple.
   */
  using type   = t_this_type;
  /**
   * @brief MSVC assumes the meaning of _Ttype; remove or rename, but do not change semantics
   */
  using _Ttype = ::portable_stl::tuple<t_this_type, t_rest...>;
};

/**
 * @brief Recursive tuple_element definition.
 *
 * @tparam t_idx Index of the element in tuple.
 * @tparam t_this_type First type of the tuple.
 * @tparam t_rest Rest types of the tuple.
 */
template<::portable_stl::size_t t_idx, class t_this_type, class... t_rest>
class tuple_element<t_idx, ::portable_stl::tuple<t_this_type, t_rest...>>
    : public tuple_element<t_idx - 1, ::portable_stl::tuple<t_rest...>> {};

/**
 * @brief Obtains the type of the specified element.
 * Implementation for arrays.
 *
 * @tparam t_idx Index of the element in tuple.
 * @tparam t_type Array elements type.
 * @tparam t_size Array size.
 */
template<::portable_stl::size_t t_idx, class t_type, ::portable_stl::size_t t_size>
class tuple_element<t_idx, ::portable_stl::array<t_type, t_size>> {
public:
  static_assert(t_idx < t_size, "array index out of bounds");
  /**
   * @brief The type of t_idx-th element of the tuple.
   */
  using type = t_type;
};

/**
 * @brief Obtains pure type of the specified element in tuple-like type.
 *
 * @tparam t_idx Index of the element in tuple.
 * @tparam t_tuple Given tuple-like type.
 */
template<::portable_stl::size_t t_idx, class t_tuple>
using tuple_element_t = typename tuple_element<t_idx, t_tuple>::type;

} // namespace portable_stl

#endif /* PSTL_TUPLE_ELEMENT_H */
