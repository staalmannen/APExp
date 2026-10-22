// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_get.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_GET_H
#define PSTL_TUPLE_GET_H

#include "../../common/size_t.h"
#include "../../metaprogramming/logical_operator/negation.h"
#include "../../metaprogramming/type_relations/is_any_of.h"
#include "fwd_decl_tuple.h"
#include "tuple_element.h"

namespace portable_stl {
namespace tuple_helper {
  /**
   * @brief Getting tuple type started with element with t_type type = searching first t_type element.
   * backstop definition.
   * @tparam t_type Searched type.
   * @tparam t_tuple Given tuple type.
   */
  template<class t_type, class t_tuple> class first_tuple_element final {};

  /**
   * @brief Getting tuple type started with element with t_type type = searching first t_type element.
   * Select first element.
   * @tparam t_this_type Searched type.
   * @tparam t_rest Remain types.
   */
  template<class t_this_type, class... t_rest>
  class first_tuple_element<t_this_type, tuple<t_this_type, t_rest...>> final {
  public:
    static_assert(::portable_stl::negation<::portable_stl::is_any_of<t_this_type, t_rest...>>{}(),
                  "duplicate type T in get<T>(tuple)");
    /**
     * @brief Result type.
     */
    using _Ttype = tuple<t_this_type, t_rest...>;
  };

  /**
   * @brief Getting tuple type started with element with t_type type = searching first t_type element.
   * Recursive definition.
   * @tparam t_type Mismatched type.
   * @tparam t_other_type Second type.
   * @tparam t_rest Remain types.
   */
  template<class t_type, class t_other_type, class... t_rest>
  class first_tuple_element<t_type, tuple<t_other_type, t_rest...>> final {
  public:
    /**
     * @brief Result type.
     */
    using _Ttype = typename first_tuple_element<t_type, tuple<t_rest...>>::_Ttype;
  };
} // namespace tuple_helper
/**
 * @brief Tuple accesses specified element. Extracts the t_index-th element from the tuple.
 *
 * @tparam t_index Requested index.
 * @tparam t_types Tuple types.
 * @param some_tuple Given tuple whose contents to extract.
 * @return A reference to the selected element of some_tuple.
 */
template<::portable_stl::size_t t_index, class... t_types>
constexpr tuple_element_t<t_index, tuple<t_types...>> &get(tuple<t_types...> &some_tuple) noexcept {
  /**
   * @brief Extracted element type.
   */
  using t_element_type = typename tuple_element<t_index, tuple<t_types...>>::_Ttype;
  return static_cast<t_element_type &>(some_tuple).m_first_value.m_value;
}

/**
 * @brief Tuple accesses specified element. Extracts the t_index-th element from the tuple.
 *
 * @tparam t_index Requested index.
 * @tparam t_types Tuple types.
 * @param some_tuple Given tuple whose contents to extract.
 * @return A reference to the selected element of some_tuple.
 */
template<::portable_stl::size_t t_index, class... t_types>
constexpr tuple_element_t<t_index, tuple<t_types...>> const &get(tuple<t_types...> const &some_tuple) noexcept {
  /**
   * @brief Extracted element type.
   */
  using t_element_type = typename tuple_element<t_index, tuple<t_types...>>::_Ttype;
  return static_cast<t_element_type const &>(some_tuple).m_first_value.m_value;
}

/**
 * @brief Tuple accesses specified element. Extracts the t_index-th element from the tuple.
 *
 * @tparam t_index Requested index.
 * @tparam t_types Tuple types.
 * @param some_tuple Given tuple whose contents to extract.
 * @return A reference to the selected element of some_tuple.
 */
template<::portable_stl::size_t t_index, class... t_types>
constexpr tuple_element_t<t_index, tuple<t_types...>> &&get(tuple<t_types...> &&some_tuple) noexcept {
  /**
   * @brief Extracted element type.
   */
  using t_type         = tuple_element_t<t_index, tuple<t_types...>>;
  /**
   * @brief
   */
  using t_element_type = typename tuple_element<t_index, tuple<t_types...>>::_Ttype;
  return static_cast<t_type &&>(static_cast<t_element_type &>(some_tuple).m_first_value.m_value);
}

/**
 * @brief Tuple accesses specified element. Extracts the t_index-th element from the tuple.
 *
 * @tparam t_index Requested index.
 * @tparam t_types Tuple types.
 * @param some_tuple Given tuple whose contents to extract.
 * @return A reference to the selected element of some_tuple.
 */
template<::portable_stl::size_t t_index, class... t_types>
constexpr tuple_element_t<t_index, tuple<t_types...>> const &&get(tuple<t_types...> const &&some_tuple) noexcept {
  /**
   * @brief extracted element type.
   */
  using t_type         = tuple_element_t<t_index, tuple<t_types...>>;
  /**
   * @brief
   */
  using t_element_type = typename tuple_element<t_index, tuple<t_types...>>::_Ttype;
  return static_cast<t_type const &&>(static_cast<t_element_type const &>(some_tuple).m_first_value.m_value);
}

/**
 * @brief Tuple accesses specified element. Extracts the element of the tuple t whose type is t_type. Fails to compile
 * unless the tuple has exactly one element of that type.
 *
 * @tparam t_type Requested type.
 * @tparam t_types Tuple types.
 * @param some_tuple Given tuple whose contents to extract.
 * @return A reference to the selected element of some_tuple.
 */
template<class t_type, class... t_types> constexpr t_type &get(tuple<t_types...> &some_tuple) noexcept {
  /**
   * @brief extracted element type.
   */
  using t_element_type = typename tuple_helper::first_tuple_element<t_type, tuple<t_types...>>::_Ttype;
  return static_cast<t_element_type &>(some_tuple).m_first_value.m_value;
}

/**
 * @brief Tuple accesses specified element. Extracts the element of the tuple t whose type is t_type. Fails to compile
 * unless the tuple has exactly one element of that type.
 *
 * @tparam t_type Requested type.
 * @tparam t_types Tuple types.
 * @param some_tuple Given tuple whose contents to extract.
 * @return A reference to the selected element of some_tuple.
 */
template<class t_type, class... t_types> constexpr t_type const &get(tuple<t_types...> const &some_tuple) noexcept {
  /**
   * @brief extracted element type.
   */
  using t_element_type = typename tuple_helper::first_tuple_element<t_type, tuple<t_types...>>::_Ttype;
  return static_cast<t_element_type const &>(some_tuple).m_first_value.m_value;
}

/**
 * @brief Tuple accesses specified element. Extracts the element of the tuple t whose type is t_type. Fails to compile
 * unless the tuple has exactly one element of that type.
 *
 * @tparam t_type Requested type.
 * @tparam t_types Tuple types.
 * @param some_tuple Given tuple whose contents to extract.
 * @return A reference to the selected element of some_tuple.
 */
template<class t_type, class... t_types> constexpr t_type &&get(tuple<t_types...> &&some_tuple) noexcept {
  /**
   * @brief extracted element type.
   */
  using t_element_type = typename tuple_helper::first_tuple_element<t_type, tuple<t_types...>>::_Ttype;
  return static_cast<t_type &&>(static_cast<t_element_type &>(some_tuple).m_first_value.m_value);
}

/**
 * @brief Tuple accesses specified element. Extracts the element of the tuple t whose type is t_type. Fails to compile
 * unless the tuple has exactly one element of that type.
 *
 * @tparam t_type Requested type.
 * @tparam t_types Tuple types.
 * @param some_tuple Given tuple whose contents to extract.
 * @return A reference to the selected element of some_tuple.
 */
template<class t_type, class... t_types> constexpr t_type const &&get(tuple<t_types...> const &&some_tuple) noexcept {
  /**
   * @brief
   */
  using t_element_type = typename tuple_helper::first_tuple_element<t_type, tuple<t_types...>>::_Ttype;
  return static_cast<t_type const &&>(static_cast<t_element_type const &>(some_tuple).m_first_value.m_value);
}
} // namespace portable_stl

#endif /* PSTL_TUPLE_GET_H */
