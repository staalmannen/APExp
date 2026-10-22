// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="map_value_compare.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MAP_VALUE_COMPARE_H
#define PSTL_MAP_VALUE_COMPARE_H

#include "../metaprogramming/type_properties/is_empty.h"
#include "../metaprogramming/type_properties/is_final.h"
#include "../metaprogramming/type_properties/is_nothrow_copy_constructible.h"
#include "../metaprogramming/type_properties/is_nothrow_default_constructible.h"
#include "../metaprogramming/type_properties/is_nothrow_swappable.h"
#include "../utility/general/swap.h"
#include "../utility/tuple/tuple.h"

namespace portable_stl {

/**
 * @brief Used as compare type in map.
 * t_compare is empty and not final so apply EBO (Empty Base Optimization).
 *
 * @tparam t_key Key type.
 * @tparam t_map_value_type Map value type.
 * @tparam t_compare Key compare type.
 */
template<class t_key,
         class t_map_value_type,
         class t_compare,
         bool = ::portable_stl::is_empty<t_compare>{}() && !::portable_stl::is_final<t_compare>{}()>
class map_value_compare : private t_compare {
public:
  /**
   * @brief Default constructor.
   *
   */
  map_value_compare() noexcept(::portable_stl::is_nothrow_default_constructible<t_compare>{}()) : t_compare() {
  }

  /**
   * @brief Constructor.
   *
   * @param comp Given comparison object.
   */
  map_value_compare(t_compare comp) noexcept(::portable_stl::is_nothrow_copy_constructible<t_compare>{}())
      : t_compare(comp) {
  }

  /**
   * @brief Returns key comparison.
   *
   * @return t_compare const&
   */
  t_compare const &key_comp() const noexcept {
    return *this;
  }

  /**
   * @brief Comparison function.
   *
   * @param lhv
   * @param rhv
   * @return true
   * @return false
   */
  bool operator()(t_map_value_type const &lhv, t_map_value_type const &rhv) const {
    return static_cast<t_compare const &>(*this)(::portable_stl::get<0>(lhv.get_value()),
                                                 ::portable_stl::get<0>(rhv.get_value()));
  }

  /**
   * @brief Comparison function.
   *
   * @param lhv
   * @param rhv
   * @return true
   * @return false
   */
  bool operator()(t_map_value_type const &lhv, t_key const &rhv) const {
    return static_cast<t_compare const &>(*this)(::portable_stl::get<0>(lhv.get_value()), rhv);
  }

  /**
   * @brief Comparison function.
   *
   * @param lhv
   * @param rhv
   * @return true
   * @return false
   */
  bool operator()(t_key const &lhv, t_map_value_type const &rhv) const {
    return static_cast<t_compare const &>(*this)(lhv, ::portable_stl::get<0>(rhv.get_value()));
  }

  /**
   * @brief Exchanges with other.
   *
   * @param other Another map_value_compare object.
   */
  void swap(map_value_compare &other) noexcept(::portable_stl::is_nothrow_swappable<t_compare>{}()) {
    using ::portable_stl::swap;
    swap(static_cast<t_compare &>(*this), static_cast<t_compare &>(other));
  }

  /**
   * @brief Comparison function.
   *
   * @tparam t_key_type2
   * @param lhv
   * @param rhv
   * @return true
   * @return false
   */
  template<typename t_key_type2> bool operator()(t_key_type2 const &lhv, t_map_value_type const &rhv) const {
    return static_cast<t_compare const &>(*this)(lhv, ::portable_stl::get<0>(rhv.get_value()));
  }

  /**
   * @brief Comparison function.
   *
   * @tparam t_key_type2
   * @param lhv
   * @param rhv
   * @return true
   * @return false
   */
  template<typename t_key_type2> bool operator()(t_map_value_type const &lhv, t_key_type2 const &rhv) const {
    return static_cast<t_compare const &>(*this)(::portable_stl::get<0>(lhv.get_value()), rhv);
  }
};

/**
 * @brief Used as compare type in map.
 * t_compare is not empty of final.
 *
 * @tparam t_key Key type.
 * @tparam t_map_value_type Map value type.
 * @tparam t_compare Key compare type.
 */
template<class t_key, class t_map_value_type, class t_compare>
class map_value_compare<t_key, t_map_value_type, t_compare, false> {
  /**
   * @brief Stored key comparison object.
   *
   */
  t_compare m_comp;

public:
  /**
   * @brief Constructor.
   *
   */
  map_value_compare() noexcept(::portable_stl::is_nothrow_default_constructible<t_compare>{}()) : m_comp() {
  }

  /**
   * @brief Constructor.
   *
   * @param comp Given key comparison object.
   */
  map_value_compare(t_compare comp) noexcept(::portable_stl::is_nothrow_copy_constructible<t_compare>{}())
      : m_comp(comp) {
  }

  /**
   * @brief Returns key comparison.
   *
   * @return t_compare const&
   */
  t_compare const &key_comp() const noexcept {
    return m_comp;
  }

  /**
   * @brief Comparison function.
   *
   * @param lhv
   * @param rhv
   * @return true
   * @return false
   */
  bool operator()(t_map_value_type const &lhv, t_map_value_type const &rhv) const {
    return m_comp(::portable_stl::get<0>(lhv.get_value()), ::portable_stl::get<0>(rhv.get_value()));
  }

  /**
   * @brief Comparison function.
   *
   * @param lhv
   * @param rhv
   * @return true
   * @return false
   */
  bool operator()(t_map_value_type const &lhv, t_key const &rhv) const {
    return m_comp(::portable_stl::get<0>(lhv.get_value()), rhv);
  }

  /**
   * @brief Comparison function.
   *
   * @param lhv
   * @param rhv
   * @return true
   * @return false
   */
  bool operator()(t_key const &lhv, t_map_value_type const &rhv) const {
    return m_comp(lhv, ::portable_stl::get<0>(rhv.get_value()));
  }

  /**
   * @brief Exchanges with other.
   *
   * @param other Another map_value_compare object.
   */
  void swap(map_value_compare &other) noexcept(::portable_stl::is_nothrow_swappable<t_compare>{}()) {
    using ::portable_stl::swap;
    swap(m_comp, other.m_comp);
  }

  /**
   * @brief Comparison function.
   *
   * @tparam t_key_type2
   * @param lhv
   * @param rhv
   * @return true
   * @return false
   */
  template<typename t_key_type2> bool operator()(t_key_type2 const &lhv, t_map_value_type const &rhv) const {
    return m_comp(lhv, ::portable_stl::get<0>(rhv.get_value()));
  }

  /**
   * @brief Comparison function.
   *
   * @tparam t_key_type2
   * @param lhv
   * @param rhv
   * @return true
   * @return false
   */
  template<typename t_key_type2> bool operator()(t_map_value_type const &lhv, t_key_type2 const &rhv) const {
    return m_comp(::portable_stl::get<0>(lhv.get_value()), rhv);
  }
};

/**
 * @brief Specializes the ::swap for ::t_map_value_type. Swaps the contents of lhs and rhs. Calls
 * lhs.swap(rhs).
 *
 * @tparam t_key
 * @tparam t_map_value_type
 * @tparam t_compare
 * @tparam t_have_ebo
 * @param lhv
 * @param rhv
 */
template<class t_key, class t_map_value_type, class t_compare, bool t_have_ebo>
inline void swap(
  map_value_compare<t_key, t_map_value_type, t_compare, t_have_ebo> &lhv,
  map_value_compare<t_key, t_map_value_type, t_compare, t_have_ebo> &rhv) noexcept(noexcept(lhv.swap(rhv))) {
  lhv.swap(rhv);
}

} // namespace portable_stl

#endif // PSTL_MAP_VALUE_COMPARE_H
