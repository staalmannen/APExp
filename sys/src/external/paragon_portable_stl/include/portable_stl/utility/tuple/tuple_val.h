// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_val.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_VAL_H
#define PSTL_TUPLE_VAL_H

#include "../../memory/allocator_arg.h"
#include "../../memory/uses_allocator.h"
#include "../../metaprogramming/logical_operator/negation.h"
#include "../../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../../metaprogramming/type_properties/is_constructible.h"
#include "../../utility/general/forward.h"

namespace portable_stl {
/**
 * @brief Stores each value in a tuple.
 *
 * @tparam t_type Value type.
 */
template<class t_type> class tuple_val final {
public:
  /**
   * @brief Value itself.
   */
  t_type m_value;

  /**
   * @brief Default ctor.
   */
  constexpr tuple_val() : m_value() {
  }

  /**
   * @brief Move ctor.
   *
   * @tparam t_other_type Another value type.
   * @param other other tuple_val.
   */
  template<class t_other_type>
  constexpr tuple_val(t_other_type &&other) : m_value(::portable_stl::forward<t_other_type>(other)) {
  }

  /**
   * @brief Ctor with custom allocator.
   *
   * @tparam t_allocator_type Allocator type.
   * @tparam t_other_types other tuple_val.
   * @param args tuple_val construction arguments.
   */
  template<class t_allocator_type,
           class... t_other_types,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::negation<::portable_stl::uses_allocator<t_type, t_allocator_type>>,
             void *>
           = nullptr>
  constexpr tuple_val(t_allocator_type const &, allocator_arg_t, t_other_types &&...args)
      : m_value(::portable_stl::forward<t_other_types>(args)...) {
  }

  /**
   * @brief Ctor with custom allocator.
   *
   * @tparam t_allocator_type Allocator type.
   * @tparam t_other_types other tuple_val.
   * @param allocator Allocator.
   * @param args tuple_val construction arguments.
   */
  template<class t_allocator_type,
           class... t_other_types,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               ::portable_stl::uses_allocator<t_type, t_allocator_type>,
               ::portable_stl::
                 is_constructible<t_type, ::portable_stl::allocator_arg_t, t_allocator_type const &, t_other_types...>>,
             void *>
           = nullptr>
  constexpr tuple_val(t_allocator_type const &allocator, allocator_arg_t, t_other_types &&...args)
      : m_value(allocator_arg, allocator, ::portable_stl::forward<t_other_types>(args)...) {
  }

  /**
   * @brief Ctor with custom allocator.
   *
   * @tparam t_allocator_type Allocator type.
   * @tparam t_other_types other tuple_val.
   * @param allocator Allocator.
   * @param args tuple_val construction arguments.
   */
  template<
    class t_allocator_type,
    class... t_other_types,
    ::portable_stl::enable_if_bool_constant_t<
      ::portable_stl::conjunction<
        ::portable_stl::uses_allocator<t_type, t_allocator_type>,
        ::portable_stl::negation<
          ::portable_stl::
            is_constructible<t_type, ::portable_stl::allocator_arg_t, t_allocator_type const &, t_other_types...>>>,
      void *>
    = nullptr>
  constexpr tuple_val(t_allocator_type const &allocator, allocator_arg_t, t_other_types &&...args)
      : m_value(::portable_stl::forward<t_other_types>(args)..., allocator) {
  }
};
} // namespace portable_stl

#endif /* PSTL_TUPLE_VAL_H */
