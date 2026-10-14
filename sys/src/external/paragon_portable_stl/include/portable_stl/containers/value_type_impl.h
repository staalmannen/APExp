// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="value_type_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_VALUE_TYPE_IMPL_H
#define PSTL_VALUE_TYPE_IMPL_H

#include "../memory/launder.h"
#include "../metaprogramming/cv_modifications/is_same_uncvref.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../utility/general/forward.h"
#include "../utility/general/move.h"
#include "../utility/tuple/tuple.h"

namespace portable_stl {

/**
 * @brief Helper type to represent "value_type" in map and multimap.
 *
 * @tparam t_key Key type.
 * @tparam t_type Value type.
 */
template<class t_key, class t_type> class value_type_impl final {
public:
  /**
   * @brief Key type.
   *
   */
  using key_type                   = t_key;
  /**
   * @brief Mapped type.
   *
   */
  using mapped_type                = t_type;
  /**
   * @brief Value type (pair).
   *
   */
  using value_type                 = ::portable_stl::tuple<key_type const, mapped_type>;
  /**
   * @brief Type represented pair of references.
   *
   */
  using t_non_const_ref_pair_type  = ::portable_stl::tuple<key_type &, mapped_type &>;
  /**
   * @brief Type represented pair of rvalue references.
   *
   */
  using t_non_const_rref_pair_type = ::portable_stl::tuple<key_type &&, mapped_type &&>;

private:
  /**
   * @brief Stored value.
   *
   */
  value_type m_value;

public:
  /**
   * @brief Access to stored value.
   *
   * @return value_type&
   */
  value_type &get_value() {
    return *::portable_stl::launder(::portable_stl::addressof(m_value));
  }

  /**
   * @brief Access to stored value.
   *
   * @return value_type const&
   */
  value_type const &get_value() const {
    return *::portable_stl::launder(::portable_stl::addressof(m_value));
  }

  /**
   * @brief Get pair of refs to stored value.
   *
   * @return t_non_const_ref_pair_type
   */
  t_non_const_ref_pair_type get_ref() {
    value_type &value_ref = get_value();
    return t_non_const_ref_pair_type(const_cast<key_type &>(::portable_stl::get<0>(value_ref)),
                                     ::portable_stl::get<1>(value_ref));
  }

  /**
   * @brief Move implementation.
   *
   * @return t_non_const_rref_pair_type
   */
  t_non_const_rref_pair_type make_move() {
    value_type &value_ref = get_value();
    return t_non_const_rref_pair_type(::portable_stl::move(const_cast<key_type &>(::portable_stl::get<0>(value_ref))),
                                      ::portable_stl::move(::portable_stl::get<1>(value_ref)));
  }

  /**
   * @brief Copy assignment operator.
   *
   * @param other Another value_type_impl object.
   * @return value_type_impl& *this.
   */
  value_type_impl &operator=(value_type_impl const &other) {
    get_ref() = other.get_value();
    return *this;
  }

  /**
   * @brief Move assignment operator.
   *
   * @param other Another value_type_impl object.
   * @return value_type_impl& *this.
   */
  value_type_impl &operator=(value_type_impl &&other) {
    get_ref() = other.make_move();
    return *this;
  }

  /**
   * @brief Assignment operator.
   *
   * @param other Another value_type like object.
   * @return value_type_impl& *this.
   */
  template<
    class t_other_value_type,
    class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_same_uncvref<t_other_value_type, value_type>>>
  value_type_impl &operator=(t_other_value_type &&other) {
    get_ref() = ::portable_stl::forward<t_other_value_type>(other);
    return *this;
  }

  /**
   * @brief Deleted constructor.
   *
   */
  value_type_impl() = delete;

  /**
   * @brief Deleted destructor.
   *
   */
  ~value_type_impl() = delete;

  /**
   * @brief Deleted copy constructor.
   *
   */
  value_type_impl(value_type_impl const &) = delete;

  /**
   * @brief Deleted move constructor.
   *
   */
  value_type_impl(value_type_impl &&) = delete;
};

} // namespace portable_stl

#endif // PSTL_VALUE_TYPE_IMPL_H
