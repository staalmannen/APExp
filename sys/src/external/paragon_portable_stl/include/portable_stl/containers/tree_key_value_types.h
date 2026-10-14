// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tree_key_value_types.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TREE_KEY_VALUE_TYPES_H
#define PSTL_TREE_KEY_VALUE_TYPES_H

#include "../metaprogramming/cv_modifications/is_same_uncvref.h"
#include "../metaprogramming/other_transformations/conditional_bool_constant.h"
#include "../utility/tuple/tuple.h"
#include "value_type_impl.h"

namespace portable_stl {

/**
 * @brief Helper to select appropriate types.
 * Primary template.
 *
 * @tparam t_type Given type.
 */
template<class t_type> class tree_key_value_types {
public:
  /**
   * @brief Key type.
   *
   */
  using key_type = t_type;

  /**
   * @brief Node value type.
   *
   */
  using t_node_value_type = t_type;

  /**
   * @brief Type used in contatiners.
   *
   */
  using t_container_value_type = t_type;

  /**
   * @brief Flag.
   *
   */
  static bool const m_is_map = false;

  /**
   * @brief Get the key object
   *
   * @param value
   * @return key_type const&
   */
  static key_type const &get_key(t_type const &value) {
    return value;
  }

  /**
   * @brief Get the value object
   *
   * @param value
   * @return t_container_value_type const&
   */
  static t_container_value_type const &get_value(t_node_value_type const &value) {
    return value;
  }

  /**
   * @brief Get the ptr object
   *
   * @param value
   * @return t_container_value_type*
   */
  static t_container_value_type *get_ptr(t_node_value_type &value) {
    return ::portable_stl::addressof(value);
  }

  /**
   * @brief
   *
   * @param value
   * @return t_container_value_type&&
   */
  static t_container_value_type &&make_move(t_node_value_type &value) {
    return ::portable_stl::move(value);
  }
};

/**
 * @brief Helper to select appropriate types.
 *
 * @tparam t_key_type
 * @tparam t_mapped_type
 */
template<class t_key_type, class t_mapped_type>
class tree_key_value_types<::portable_stl::value_type_impl<t_key_type, t_mapped_type>> {
public:
  /**
   * @brief Key type.
   *
   */
  using key_type = t_key_type;

  /**
   * @brief Mapped value type.
   *
   */
  using mapped_type = t_mapped_type;

  /**
   * @brief Node value type.
   *
   */
  using t_node_value_type = ::portable_stl::value_type_impl<t_key_type, t_mapped_type>;

  /**
   * @brief Type used in contatiners.
   *
   */
  using t_container_value_type = ::portable_stl::tuple<t_key_type const, t_mapped_type>;

  /**
   * @brief Type used in map like contatiner.
   *
   */
  using t_map_value_type = t_container_value_type;

  /**
   * @brief Flag.
   *
   */
  static bool const m_is_map = true;

  /**
   * @brief
   *
   * @param value
   * @return key_type const&
   */
  static key_type const &get_key(t_node_value_type const &value) {
    return ::portable_stl::get<0>(value.get_value());
  }

  /**
   * @brief
   *
   * @tparam t_other_type
   * @param value
   * @return key_type const&
   */
  template<class t_other_type,
           ::portable_stl::
             enable_if_bool_constant_t<::portable_stl::is_same_uncvref<t_other_type, t_container_value_type>, void *>
           = nullptr>
  static key_type const &get_key(t_other_type &value) {
    return ::portable_stl::get<0>(value);
  }

  /**
   * @brief
   *
   * @param value
   * @return t_container_value_type const&
   */
  static t_container_value_type const &get_value(t_node_value_type const &value) {
    return value.get_value();
  }

  /**
   * @brief
   *
   * @tparam t_other_type
   * @param value
   * @return t_container_value_type const &
   */
  template<class t_other_type>
  static ::portable_stl::enable_if_bool_constant_t<
    ::portable_stl::is_same_uncvref<t_other_type, t_container_value_type>,
    t_container_value_type const &>
    get_value(t_other_type &value) {
    return value;
  }

  /**
   * @brief
   *
   * @param value
   * @return t_container_value_type*
   */
  static t_container_value_type *get_ptr(t_node_value_type &value) {
    return ::portable_stl::addressof(value.get_value());
  }

  /**
   * @brief
   *
   * @param other
   * @return ::portable_stl::tuple<key_type &&, mapped_type &&>
   */
  static ::portable_stl::tuple<key_type &&, mapped_type &&> make_move(t_node_value_type &other) {
    return other.make_move();
  }
};

} // namespace portable_stl

#endif // PSTL_TREE_KEY_VALUE_TYPES_H
