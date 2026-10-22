// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_H
#define PSTL_TUPLE_H

#include "../../common/size_t.h"
#include "../../compare/strong_ordering.h"
#include "../../memory/allocator_arg.h"
#include "../../metaprogramming/integer_sequence/make_index_sequence.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/logical_operator/disjunction.h"
#include "../../metaprogramming/logical_operator/negation.h"
#include "../../metaprogramming/other_transformations/enable_if.h"
#include "../../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../../metaprogramming/other_transformations/remove_cvref.h"
#include "../../metaprogramming/other_transformations/type_identity.h"
#include "../../metaprogramming/other_transformations/void_t.h"
#include "../../metaprogramming/reference_modifications/remove_reference.h"
#include "../../metaprogramming/type_properties/is_assignable.h"
#include "../../metaprogramming/type_properties/is_copy_assignable.h"
#include "../../metaprogramming/type_properties/is_default_constructible.h"
#include "../../metaprogramming/type_properties/is_implicitly_default_constructible.h"
#include "../../metaprogramming/type_properties/is_move_assignable.h"
#include "../../metaprogramming/type_properties/is_nothrow_assignable.h"
#include "../../metaprogramming/type_properties/is_nothrow_copy_assignable.h"
#include "../../metaprogramming/type_properties/is_nothrow_copy_constructible.h"
#include "../../metaprogramming/type_properties/is_nothrow_default_constructible.h"
#include "../../metaprogramming/type_properties/is_nothrow_move_assignable.h"
#include "../../metaprogramming/type_properties/is_nothrow_swappable.h"
#include "../../metaprogramming/type_relations/is_convertible.h"
#include "../../metaprogramming/type_relations/is_same.h"
#include "../../utility/general/forward.h"
#include "../../utility/general/move.h"
#include "../../utility/general/swap.h"
#include "tuple_comp.h"
#include "tuple_element.h"
#include "tuple_empty_impl.h"
#include "tuple_forward_as.h"
#include "tuple_get.h"
#include "tuple_helper.h"
#include "tuple_like.h"
#include "tuple_make.h"
#include "tuple_operator_restriction.h"
#include "tuple_size.h"
#include "tuple_tie.h"
#include "tuple_val.h"
#include "../piecewise_construct.h"

namespace portable_stl {

template<size_t t_index, class... t_types> auto &&_Tuple_get(tuple<t_types...> &&given_tuple) noexcept {
    // used by pair's piecewise constructor
    using t_type      = tuple_element_t<t_index, tuple<t_types...>>;
    using t_elem_type = typename tuple_element<t_index, tuple<t_types...>>::_Ttype;
    return static_cast<t_type &&>(static_cast<t_elem_type &>(given_tuple).m_first_value.m_value);
  }

/**
 * @brief Recursive tuple definition.
 *
 * @tparam t_this
 * @tparam t_rest
 */
template<class t_this, class... t_rest> class tuple<t_this, t_rest...> : private tuple<t_rest...> {
public:
  /**
   * @brief Type of the value stored in this part of tuple.
   */
  using t_this_type = t_this;

  /**
   * @brief Type of the remain part of the tuple.
   */
  using t_my_base = tuple<t_rest...>;

  /**
   * @brief The stored element.
   */
  tuple_val<t_this> m_first_value;

  /**
   * @brief Constructor.
   *
   * @tparam t_tag Should be exact_args_t.
   * @tparam t_other_type
   * @tparam t_other_rest
   * @param other
   * @param other_rest
   */
  template<class t_tag,
           class t_other_type,
           class... t_other_rest,
           tuple_helper::enable_if_tag_t<tuple_helper::exact_args_t, t_tag> = nullptr>
  tuple(t_tag, t_other_type &&other, t_other_rest &&...other_rest)
      : t_my_base(tuple_helper::exact_args_t{}, ::portable_stl::forward<t_other_rest>(other_rest)...)
      , m_first_value(::portable_stl::forward<t_other_type>(other)) {
  }

  /**
   * @brief Constructor.
   *
   * @tparam t_tag Should be unpack_tuple_t.
   * @tparam t_tuple
   * @tparam t_indices
   * @param other
   */
  template<class t_tag,
           class t_tuple,
           size_t... t_indices,
           tuple_helper::enable_if_tag_t<tuple_helper::unpack_tuple_t, t_tag> = nullptr>
  tuple(t_tag, t_tuple &&other, ::portable_stl::index_sequence<t_indices...>);

  /**
   * @brief Constructor.
   *
   * @tparam t_tag Should be unpack_tuple_t.
   * @tparam t_tuple
   * @param other
   */
  template<class t_tag, class t_tuple, tuple_helper::enable_if_tag_t<tuple_helper::unpack_tuple_t, t_tag> = nullptr>
  tuple(t_tag, t_tuple &&other)
      : tuple(tuple_helper::unpack_tuple_t{},
              ::portable_stl::forward<t_tuple>(other),
              ::portable_stl::make_index_sequence<
                ::portable_stl::tuple_size<::portable_stl::remove_reference_t<t_tuple>>{}()>{}) {
  }

  template<class... t_first_types1, class... t_first_types2>
  tuple(::portable_stl::piecewise_construct_t, tuple<t_first_types1...> tpl1, tuple<t_first_types2...> tpl2)
      : tuple(tpl1,
              tpl2,
              ::portable_stl::index_sequence_for<t_first_types1...>{},
              ::portable_stl::index_sequence_for<t_first_types2...>{}) {
  }

  template<class t_tuple_first,
           class t_tuple_second,
           portable_stl::size_t... t_indices1,
           ::portable_stl::size_t... t_indices2>
  constexpr tuple(t_tuple_first  &tpl1,
                  t_tuple_second &tpl2,
                  ::portable_stl::index_sequence<t_indices1...>,
                  ::portable_stl::index_sequence<t_indices2...>)
      : t_my_base(_Tuple_get<t_indices2>(::portable_stl::move(tpl2))...)
      , m_first_value(_Tuple_get<t_indices1>(::portable_stl::move(tpl1))...) {
  }

  /**
   * @brief Constructor.
   *
   * @tparam t_tag Should be alloc_exact_args_t.
   * @tparam t_allocator
   * @tparam t_other_type
   * @tparam t_other_rest
   * @param allocator
   * @param other
   * @param other_rest
   */
  template<class t_tag,
           class t_allocator,
           class t_other_type,
           class... t_other_rest,
           tuple_helper::enable_if_tag_t<tuple_helper::alloc_exact_args_t, t_tag> = nullptr>
  tuple(t_tag, t_allocator const &allocator, t_other_type &&other, t_other_rest &&...other_rest)
      : t_my_base(tuple_helper::alloc_exact_args_t{}, allocator, ::portable_stl::forward<t_other_rest>(other_rest)...)
      , m_first_value(allocator, allocator_arg, ::portable_stl::forward<t_other_type>(other)) {
  }

  /**
   * @brief Constructor.
   *
   * @tparam t_tag Should be alloc_unpack_tuple_t.
   * @tparam t_allocator
   * @tparam t_tuple
   * @tparam t_indices
   * @param allocator
   * @param other
   */
  template<class t_tag,
           class t_allocator,
           class t_tuple,
           size_t... t_indices,
           tuple_helper::enable_if_tag_t<tuple_helper::alloc_unpack_tuple_t, t_tag> = nullptr>
  tuple(t_tag, t_allocator const &allocator, t_tuple &&other, ::portable_stl::index_sequence<t_indices...>);

  /**
   * @brief Constructor.
   *
   * @tparam t_tag Should be alloc_unpack_tuple_t.
   * @tparam t_allocator
   * @tparam t_tuple
   * @param allocator
   * @param other
   */
  template<class t_tag,
           class t_allocator,
           class t_tuple,
           tuple_helper::enable_if_tag_t<tuple_helper::alloc_unpack_tuple_t, t_tag> = nullptr>
  tuple(t_tag, t_allocator const &allocator, t_tuple &&other)
      : tuple(tuple_helper::alloc_unpack_tuple_t{},
              allocator,
              ::portable_stl::forward<t_tuple>(other),
              ::portable_stl::make_index_sequence<
                ::portable_stl::tuple_size<::portable_stl::remove_reference_t<t_tuple>>{}()>{}) {
  }

  /**
   * @brief Constructor.
   * explicit
   * @tparam t_other_type
   */
  template<class t_other_type = t_this_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::conjunction<
                                           ::portable_stl::is_implicitly_default_constructible<t_other_type>,
                                           ::portable_stl::is_implicitly_default_constructible<t_rest>...>>,
                                         ::portable_stl::is_default_constructible<t_other_type>,
                                         ::portable_stl::is_default_constructible<t_rest>...>,
             void *>
           = nullptr>
  explicit tuple() noexcept(
    ::portable_stl::conjunction<::portable_stl::is_nothrow_default_constructible<t_other_type>,
                                ::portable_stl::is_nothrow_default_constructible<t_rest>...>{}()) // strengthened
      : t_my_base(), m_first_value() {
  }

  /**
   * @brief Constructor.
   * implicit
   * @tparam t_other_type
   */
  template<class t_other_type = t_this_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::is_implicitly_default_constructible<t_other_type>,
                                         ::portable_stl::is_implicitly_default_constructible<t_rest>...,
                                         ::portable_stl::is_default_constructible<t_other_type>,
                                         ::portable_stl::is_default_constructible<t_rest>...>,
             void *>
           = nullptr>
  tuple() noexcept(
    ::portable_stl::conjunction<::portable_stl::is_nothrow_default_constructible<t_other_type>,
                                ::portable_stl::is_nothrow_default_constructible<t_rest>...>{}()) // strengthened
      : t_my_base(), m_first_value() {
  }

  /**
   * @brief Constructor.
   * explicit
   * @tparam t_other_type
   * @param other
   * @param other_rest
   */
  template<class t_other_type = t_this_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               tuple_helper::tuple_conditional_explicit<tuple, t_other_type const &, t_rest const &...>,
               tuple_helper::tuple_constructible<tuple, t_other_type const &, t_rest const &...>>,
             void *>
           = nullptr>
  explicit tuple(t_other_type const &other, t_rest const &...other_rest) noexcept(
    ::portable_stl::conjunction<::portable_stl::is_nothrow_copy_constructible<t_other_type>,
                                ::portable_stl::is_nothrow_copy_constructible<t_rest>...>{}()) // strengthened
      : tuple(tuple_helper::exact_args_t{}, other, other_rest...) {
  }

  /**
   * @brief Constructor.
   * implicit
   * @tparam t_other_type
   * @param other
   * @param other_rest
   */
  template<class t_other_type = t_this_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               ::portable_stl::negation<
                 tuple_helper::tuple_conditional_explicit<tuple, t_other_type const &, t_rest const &...>>,
               tuple_helper::tuple_constructible<tuple, t_other_type const &, t_rest const &...>>,
             void *>
           = nullptr>
  tuple(t_other_type const &other, t_rest const &...other_rest) noexcept(
    ::portable_stl::conjunction<::portable_stl::is_nothrow_copy_constructible<t_other_type>,
                                ::portable_stl::is_nothrow_copy_constructible<t_rest>...>{}()) // strengthened
      : tuple(tuple_helper::exact_args_t{}, other, other_rest...) {
  }

  /**
   * @brief Constructor.
   * explicit
   * @tparam t_other_type
   * @tparam t_other_rest
   * @param other
   * @param other_rest
   */
  template<class t_other_type,
           class... t_other_rest,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<tuple_helper::tuple_conditional_explicit<tuple, t_other_type, t_other_rest...>,
                                         tuple_helper::tuple_constructible<tuple, t_other_type, t_other_rest...>,
                                         tuple_helper::tuple_perfect_val<tuple, t_other_type, t_other_rest...>>,
             void *>
           = nullptr>
  explicit tuple(t_other_type &&other, t_other_rest &&...other_rest) noexcept(
    tuple_helper::tuple_nothrow_constructible<tuple, t_other_type, t_other_rest...>{}()) // strengthened
      : tuple(tuple_helper::exact_args_t{},
              ::portable_stl::forward<t_other_type>(other),
              ::portable_stl::forward<t_other_rest>(other_rest)...) {
  }

  /**
   * @brief Constructor.
   * implicit
   * was noexcept(tuple_helper::tuple_nothrow_constructible<tuple, t_other_type, t_other_rest...>{}())
   * @tparam t_other_type
   * @tparam t_other_rest
   * @param other
   * @param other_rest
   */
  template<class t_other_type,
           class... t_other_rest,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               ::portable_stl::negation<tuple_helper::tuple_conditional_explicit<tuple, t_other_type, t_other_rest...>>,
               tuple_helper::tuple_constructible<tuple, t_other_type, t_other_rest...>,
               tuple_helper::tuple_perfect_val<tuple, t_other_type, t_other_rest...>>,
             void *>
           = nullptr>
  tuple(t_other_type &&other, t_other_rest &&...other_rest) noexcept(noexcept(tuple(tuple_helper::exact_args_t{},
              ::portable_stl::forward<t_other_type>(other),
              ::portable_stl::forward<t_other_rest>(other_rest)...)))
      : tuple(tuple_helper::exact_args_t{},
              ::portable_stl::forward<t_other_type>(other),
              ::portable_stl::forward<t_other_rest>(other_rest)...) {
  }

  /**
   * @brief Default copy ctor.
   */
  tuple(tuple const &) = default;

  /**
   * @brief Default move ctor.
   */
  tuple(tuple &&) = default;

  /**
   * @brief Constructor.
   * explicit
   * @tparam t_other_types
   * @param other
   */
  template<class... t_other_types,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               tuple_helper::tuple_conditional_explicit<tuple, t_other_types const &...>,
               tuple_helper::tuple_constructible<tuple, t_other_types const &...>,
               tuple_helper::tuple_convert_val<tuple, tuple<t_other_types...> const &, t_other_types...>>,
             void *>
           = nullptr>
  explicit tuple(tuple<t_other_types...> const &other) noexcept(
    tuple_helper::tuple_nothrow_constructible<tuple, t_other_types const &...>{}()) // strengthened
      : tuple(tuple_helper::unpack_tuple_t{}, other) {
  }

  /**
   * @brief Constructor.
   * implicit
   * @tparam t_other_types
   * @param other
   */
  template<class... t_other_types,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               ::portable_stl::negation<tuple_helper::tuple_conditional_explicit<tuple, t_other_types const &...>>,
               tuple_helper::tuple_constructible<tuple, t_other_types const &...>,
               tuple_helper::tuple_convert_val<tuple, tuple<t_other_types...> const &, t_other_types...>>,
             void *>
           = nullptr>
  tuple(tuple<t_other_types...> const &other) noexcept(
    tuple_helper::tuple_nothrow_constructible<tuple, t_other_types const &...>{}()) // strengthened
      : tuple(tuple_helper::unpack_tuple_t{}, other) {
  }

  /**
   * @brief Constructor.
   * explicit
   * @tparam t_other_types
   * @param other
   */
  template<
    class... t_other_types,
    ::portable_stl::enable_if_bool_constant_t<
      ::portable_stl::conjunction<tuple_helper::tuple_conditional_explicit<tuple, t_other_types...>,
                                  tuple_helper::tuple_constructible<tuple, t_other_types...>,
                                  tuple_helper::tuple_convert_val<tuple, tuple<t_other_types...>, t_other_types...>>,
      void *>
    = nullptr>
  explicit tuple(tuple<t_other_types...> &&other) noexcept(
    tuple_helper::tuple_nothrow_constructible<tuple, t_other_types...>{}()) // strengthened
      : tuple(tuple_helper::unpack_tuple_t{}, ::portable_stl::move(other)) {
  }

  /**
   * @brief Constructor.
   * implicit
   * @tparam t_other_types
   * @param other
   */
  template<class... t_other_types,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               ::portable_stl::negation<tuple_helper::tuple_conditional_explicit<tuple, t_other_types...>>,
               tuple_helper::tuple_constructible<tuple, t_other_types...>,
               tuple_helper::tuple_convert_val<tuple, tuple<t_other_types...>, t_other_types...>>,
             void *>
           = nullptr>
  tuple(tuple<t_other_types...> &&other) noexcept(
    tuple_helper::tuple_nothrow_constructible<tuple, t_other_types...>{}()) // strengthened
      : tuple(tuple_helper::unpack_tuple_t{}, ::portable_stl::move(other)) {
  }

  /**
   * @brief Constructor.
   * explicit
   * @tparam t_allocator
   * @tparam t_other_type
   * @param allocator
   */
  template<class t_allocator,
           class t_other_type = t_this_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::conjunction<
                                           ::portable_stl::is_implicitly_default_constructible<t_other_type>,
                                           ::portable_stl::is_implicitly_default_constructible<t_rest>...>>,
                                         ::portable_stl::is_default_constructible<t_other_type>,
                                         ::portable_stl::is_default_constructible<t_rest>...>,
             void *>
           = nullptr>
  explicit tuple(::portable_stl::allocator_arg_t, t_allocator const &allocator)
      : t_my_base(::portable_stl::allocator_arg, allocator), m_first_value(allocator, ::portable_stl::allocator_arg) {
  }

  /**
   * @brief Constructor.
   * implicit
   * @tparam t_allocator
   * @tparam t_other_type
   * @param allocator
   */
  template<class t_allocator,
           class t_other_type = t_this_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::is_implicitly_default_constructible<t_other_type>,
                                         ::portable_stl::is_implicitly_default_constructible<t_rest>...,
                                         ::portable_stl::is_default_constructible<t_other_type>,
                                         ::portable_stl::is_default_constructible<t_rest>...>,
             void *>
           = nullptr>
  tuple(::portable_stl::allocator_arg_t, t_allocator const &allocator)
      : t_my_base(::portable_stl::allocator_arg, allocator), m_first_value(allocator, ::portable_stl::allocator_arg) {
  }

  /**
   * @brief Constructor.
   * explicit
   * @tparam t_allocator
   * @tparam t_other_type
   * @param allocator
   * @param other_value
   * @param other_values
   */
  template<
    class t_allocator,
    class t_other_type = t_this_type,
    ::portable_stl::enable_if_bool_constant_t<
      ::portable_stl::conjunction<tuple_helper::tuple_conditional_explicit<tuple, t_other_type, t_rest...>,
                                  tuple_helper::tuple_constructible<tuple, t_other_type const &, t_rest const &...>>,
      void *>
    = nullptr>
  explicit tuple(::portable_stl::allocator_arg_t,
                 t_allocator const &allocator,
                 t_this_type const &other_value,
                 t_rest const &...other_values)
      : tuple(tuple_helper::alloc_exact_args_t{}, allocator, other_value, other_values...) {
  }

  /**
   * @brief Constructor.
   * implicit
   * @tparam t_allocator
   * @tparam t_other_type
   * @param allocator
   * @param other_value
   * @param other_values
   */
  template<class t_allocator,
           class t_other_type = t_this_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               ::portable_stl::negation<tuple_helper::tuple_conditional_explicit<tuple, t_other_type, t_rest...>>,
               tuple_helper::tuple_constructible<tuple, t_other_type const &, t_rest const &...>>,
             void *>
           = nullptr>
  tuple(::portable_stl::allocator_arg_t,
        t_allocator const &allocator,
        t_this_type const &other_value,
        t_rest const &...other_values)
      : tuple(tuple_helper::alloc_exact_args_t{}, allocator, other_value, other_values...) {
  }

  /**
   * @brief Constructor.
   * explicit
   * @tparam t_allocator
   * @tparam t_other_type
   * @tparam t_other_rest
   * @param allocator
   * @param other_value
   * @param other_values
   */
  template<class t_allocator,
           class t_other_type,
           class... t_other_rest,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<tuple_helper::tuple_conditional_explicit<tuple, t_other_type, t_other_rest...>,
                                         tuple_helper::tuple_perfect_val<tuple, t_other_type, t_other_rest...>,
                                         tuple_helper::tuple_constructible<tuple, t_other_type, t_other_rest...>>,
             void *>
           = nullptr>
  explicit tuple(::portable_stl::allocator_arg_t,
                 t_allocator const &allocator,
                 t_other_type     &&other_value,
                 t_other_rest &&...other_values)
      : tuple(tuple_helper::alloc_exact_args_t{},
              allocator,
              ::portable_stl::forward<t_other_type>(other_value),
              ::portable_stl::forward<t_other_rest>(other_values)...) {
  }

  /**
   * @brief Constructor.
   * implicit
   * @tparam t_allocator
   * @tparam t_other_type
   * @tparam t_other_rest
   * @param allocator
   * @param other_value
   * @param other_values
   */
  template<class t_allocator,
           class t_other_type,
           class... t_other_rest,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               ::portable_stl::negation<tuple_helper::tuple_conditional_explicit<tuple, t_other_type, t_other_rest...>>,
               tuple_helper::tuple_perfect_val<tuple, t_other_type, t_other_rest...>,
               tuple_helper::tuple_constructible<tuple, t_other_type, t_other_rest...>>,
             void *>
           = nullptr>
  tuple(::portable_stl::allocator_arg_t,
        t_allocator const &allocator,
        t_other_type     &&other_value,
        t_other_rest &&...other_values)
      : tuple(tuple_helper::alloc_exact_args_t{},
              allocator,
              ::portable_stl::forward<t_other_type>(other_value),
              ::portable_stl::forward<t_other_rest>(other_values)...) {
  }

  /**
   * @brief Constructor.
   *
   * @tparam t_allocator
   * @tparam t_other_type
   * @param allocator
   * @param other
   */
  template<class t_allocator,
           class t_other_type = t_this_type,
           ::portable_stl::enable_if_bool_constant_t<
             tuple_helper::tuple_constructible<tuple, t_other_type const &, t_rest const &...>,
             void *>
           = nullptr>
  tuple(::portable_stl::allocator_arg_t, t_allocator const &allocator, tuple const &other)
      : tuple(tuple_helper::alloc_unpack_tuple_t{}, allocator, other) {
  }

  /**
   * @brief Constructor.
   *
   * @tparam t_allocator
   * @tparam t_other_type
   * @param allocator
   * @param other
   */
  template<
    class t_allocator,
    class t_other_type = t_this_type,
    ::portable_stl::enable_if_bool_constant_t<tuple_helper::tuple_constructible<tuple, t_other_type, t_rest...>, void *>
    = nullptr>
  tuple(::portable_stl::allocator_arg_t, t_allocator const &allocator, tuple &&other)
      : tuple(tuple_helper::alloc_unpack_tuple_t{}, allocator, ::portable_stl::move(other)) {
  }

  /**
   * @brief Constructor.
   * explicit
   * @tparam t_allocator
   * @tparam t_other_types
   * @param allocator
   * @param other
   */
  template<class t_allocator,
           class... t_other_types,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               tuple_helper::tuple_conditional_explicit<tuple, t_other_types const &...>,
               tuple_helper::tuple_constructible<tuple, t_other_types const &...>,
               tuple_helper::tuple_convert_val<tuple, tuple<t_other_types...> const &, t_other_types...>>,
             void *>
           = nullptr>
  explicit tuple(::portable_stl::allocator_arg_t, t_allocator const &allocator, tuple<t_other_types...> const &other)
      : tuple(tuple_helper::alloc_unpack_tuple_t{}, allocator, other) {
  }

  /**
   * @brief Constructor.
   * implicit
   * @tparam t_allocator
   * @tparam t_other_types
   * @param allocator
   * @param other
   */
  template<class t_allocator,
           class... t_other_types,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               ::portable_stl::negation<tuple_helper::tuple_conditional_explicit<tuple, t_other_types const &...>>,
               tuple_helper::tuple_constructible<tuple, t_other_types const &...>,
               tuple_helper::tuple_convert_val<tuple, tuple<t_other_types...> const &, t_other_types...>>,
             void *>
           = nullptr>
  tuple(::portable_stl::allocator_arg_t, t_allocator const &allocator, tuple<t_other_types...> const &other)
      : tuple(tuple_helper::alloc_unpack_tuple_t{}, allocator, other) {
  }

  /**
   * @brief Constructor.
   * explicit
   * @tparam t_allocator
   * @tparam t_other_types
   * @param allocator
   * @param other
   */
  template<
    class t_allocator,
    class... t_other_types,
    ::portable_stl::enable_if_bool_constant_t<
      ::portable_stl::conjunction<tuple_helper::tuple_conditional_explicit<tuple, t_other_types...>,
                                  tuple_helper::tuple_constructible<tuple, t_other_types...>,
                                  tuple_helper::tuple_convert_val<tuple, tuple<t_other_types...>, t_other_types...>>,
      void *>
    = nullptr>
  explicit tuple(::portable_stl::allocator_arg_t, t_allocator const &allocator, tuple<t_other_types...> &&other)
      : tuple(tuple_helper::alloc_unpack_tuple_t{}, allocator, ::portable_stl::move(other)) {
  }

  /**
   * @brief Constructor.
   * implicit
   * @tparam t_allocator
   * @tparam t_other_types
   * @param allocator
   * @param other
   */
  template<class t_allocator,
           class... t_other_types,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               ::portable_stl::negation<tuple_helper::tuple_conditional_explicit<tuple, t_other_types...>>,
               tuple_helper::tuple_constructible<tuple, t_other_types...>,
               tuple_helper::tuple_convert_val<tuple, tuple<t_other_types...>, t_other_types...>>,
             void *>
           = nullptr>
  tuple(::portable_stl::allocator_arg_t, t_allocator const &allocator, tuple<t_other_types...> &&other)
      : tuple(tuple_helper::alloc_unpack_tuple_t{}, allocator, ::portable_stl::move(other)) {
  }

  /**
   * @brief Removed copy assignment for const volatile.
   *
   * @param volatile
   * @return tuple&
   */
  tuple &operator=(tuple const volatile &) & = delete;

  /**
   * @brief
   *
   * @tparam t_myself_type
   * @tparam t_this_type
   * @param other
   * @return tuple&
   */
  template<class t_myself_type = tuple,
           class t_this_type   = t_this,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::is_copy_assignable<t_this_type>,
                                         ::portable_stl::is_copy_assignable<t_rest>...>,
             void *>
           = nullptr>
  tuple &operator=(::portable_stl::type_identity_t<t_myself_type const &> other) & noexcept(
    ::portable_stl::conjunction<::portable_stl::is_nothrow_copy_assignable<t_this_type>,
                                ::portable_stl::is_nothrow_copy_assignable<t_rest>...>{}()) /* strengthened */ {
    m_first_value.m_value = other.m_first_value.m_value;
    this->get_rest()      = other.get_rest();
    return *this;
  }

  /**
   * @brief
   *
   * @tparam t_myself_type
   * @tparam t_this_type
   * @param other
   * @return tuple const&
   */
  template<class t_myself_type = tuple,
           class t_this_type   = t_this,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::is_copy_assignable<t_this_type const>,
                                         ::portable_stl::is_copy_assignable<t_rest const>...>,
             void *>
           = nullptr>
  tuple const &operator=(::portable_stl::type_identity_t<t_myself_type const &> other) const & noexcept(
    ::portable_stl::conjunction<::portable_stl::is_nothrow_copy_assignable<t_this_type const>,
                                ::portable_stl::is_nothrow_copy_assignable<t_rest const>...>{}()) /* strengthened */ {
    m_first_value.m_value = other.m_first_value.m_value;
    this->get_rest()      = other.get_rest();
    return *this;
  }

  /**
   * @brief
   *
   * @tparam t_myself_type
   * @tparam t_this_type
   * @param other
   * @return tuple&
   */
  template<class t_myself_type = tuple,
           class t_this_type   = t_this,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::is_move_assignable<t_this_type>,
                                         ::portable_stl::is_move_assignable<t_rest>...>,
             void *>
           = nullptr>
  tuple &operator=(::portable_stl::type_identity_t<t_myself_type &&> other) & noexcept(
    ::portable_stl::conjunction<::portable_stl::is_nothrow_move_assignable<t_this_type>,
                                ::portable_stl::is_nothrow_move_assignable<t_rest>...>{}()) {
    m_first_value.m_value = ::portable_stl::forward<t_this>(other.m_first_value.m_value);
    this->get_rest()      = ::portable_stl::forward<t_my_base>(other.get_rest());
    return *this;
  }

  /**
   * @brief
   *
   * @tparam t_myself_type
   * @tparam t_this_type
   * @param other
   * @return tuple const&
   */
  template<class t_myself_type = tuple,
           class t_this_type   = t_this,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::is_assignable<t_this_type const &, t_this_type>,
                                         ::portable_stl::is_assignable<t_rest const &, t_rest>...>,
             void *>
           = nullptr>
  tuple const &operator=(::portable_stl::type_identity_t<t_myself_type &&> other) const & noexcept(
    ::portable_stl::conjunction<
      ::portable_stl::is_nothrow_assignable<t_this_type const &, t_this_type>,
      ::portable_stl::is_nothrow_assignable<t_rest const &, t_rest>...>{}()) /* strengthened */ {
    m_first_value.m_value = ::portable_stl::forward<t_this>(other.m_first_value.m_value);
    this->get_rest()      = ::portable_stl::forward<t_my_base>(other.get_rest());
    return *this;
  }

  /**
   * @brief
   *
   * @tparam t_other_types
   * @param other
   * @return tuple&
   */
  template<class... t_other_types,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               ::portable_stl::negation<::portable_stl::is_same<tuple, ::portable_stl::tuple<t_other_types...>>>,
               tuple_helper::tuple_assignable<tuple, t_other_types const &...>>,
             void *>
           = nullptr>
  tuple &operator=(tuple<t_other_types...> const &other) & noexcept(
    tuple_helper::tuple_nothrow_assignable<tuple, t_other_types const &...>{}()) /* strengthened */ {
    m_first_value.m_value = other.m_first_value.m_value;
    this->get_rest()      = other.get_rest();
    return *this;
  }

  /**
   * @brief
   *
   * @tparam t_other_types
   * @param other
   * @return tuple const&
   */
  template<class... t_other_types,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               ::portable_stl::negation<::portable_stl::is_same<tuple, ::portable_stl::tuple<t_other_types...>>>,
               tuple_helper::tuple_assignable<tuple const, t_other_types const &...>>,
             void *>
           = nullptr>
  tuple const &operator=(tuple<t_other_types...> const &other) const & noexcept(
    tuple_helper::tuple_nothrow_assignable<tuple const, t_other_types const &...>{}()) /* strengthened */ {
    m_first_value.m_value = other.m_first_value.m_value;
    this->get_rest()      = other.get_rest();
    return *this;
  }

  /**
   * @brief
   *
   * @tparam t_other_types
   * @param other
   * @return tuple&
   */
  template<class... t_other_types,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               ::portable_stl::negation<::portable_stl::is_same<tuple, ::portable_stl::tuple<t_other_types...>>>,
               tuple_helper::tuple_assignable<tuple, t_other_types...>>,
             void *>
           = nullptr>
  tuple &operator=(tuple<t_other_types...> &&other) & noexcept(
    tuple_helper::tuple_nothrow_assignable<tuple, t_other_types...>{}()) /* strengthened */ {
    m_first_value.m_value
      = ::portable_stl::forward<typename tuple<t_other_types...>::t_this_type>(other.m_first_value.m_value);
    this->get_rest() = ::portable_stl::forward<typename tuple<t_other_types...>::t_my_base>(other.get_rest());
    return *this;
  }

  /**
   * @brief
   *
   * @tparam t_other_types
   * @param other
   * @return tuple const&
   */
  template<class... t_other_types,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               ::portable_stl::negation<::portable_stl::is_same<tuple, ::portable_stl::tuple<t_other_types...>>>,
               tuple_helper::tuple_assignable<tuple const, t_other_types...>>,
             void *>
           = nullptr>
  tuple const &operator=(tuple<t_other_types...> &&other) const & noexcept(
    tuple_helper::tuple_nothrow_assignable<tuple const, t_other_types...>{}()) /* strengthened */ {
    m_first_value.m_value
      = ::portable_stl::forward<typename tuple<t_other_types...>::t_this_type>(other.m_first_value.m_value);
    this->get_rest() = ::portable_stl::forward<typename tuple<t_other_types...>::t_my_base>(other.get_rest());
    return *this;
  }

  /**
   * @brief swap implementation for ADL.
   * may be problems in msvc and gcc 11.4.0
   * constexpr expression was:
   * 1) noexcept(::portable_stl::conjunction<::portable_stl::is_nothrow_swappable<t_this const>,
   * ::portable_stl::is_nothrow_swappable<t_rest const>...>{}())
   *
   * 2) noexcept(::portable_stl::is_nothrow_swappable<t_this>{}()
   *                                && noexcept(t_my_base::swap(other.get_rest())))
   * @param other Other tuple
   */
  void swap(tuple &other) noexcept(::portable_stl::is_nothrow_swappable<t_this>{}()
                                   && ::portable_stl::is_nothrow_swappable<decltype(other.get_rest())>{}()) {
    using ::portable_stl::swap;
    swap(m_first_value.m_value, other.m_first_value.m_value); // intentional ADL
    t_my_base::swap(other.get_rest());
  }

  /**
   * @brief swap implementation for ADL.
   * was constexpr
   * used noexcept(::portable_stl::conjunction<::portable_stl::is_nothrow_swappable<t_this const>,
   * ::portable_stl::is_nothrow_swappable<t_rest const>...>{}())
   * @param other Other tuple
   */
  template<void * = nullptr> // see GH-3013
  void swap(tuple const &other) const
    noexcept(::portable_stl::is_nothrow_swappable<t_this>{}() && noexcept(t_my_base::swap(other.get_rest()))) {
    using ::portable_stl::swap;
    swap(m_first_value.m_value, other.m_first_value.m_value); // intentional ADL
    t_my_base::swap(other.get_rest());
  }

  /**
   * @brief Get reference to rest of elements
   * was constexpr
   * @return t_my_base&
   */
  t_my_base &get_rest() noexcept {
    return *this;
  }

  /**
   * @brief Get const reference to rest of elements
   * was constexpr
   * @return t_my_base const&
   */
  t_my_base const &get_rest() const noexcept {
    return *this;
  }

  /**
   * @brief Used in all comparison operators.
   *
   * @tparam t_other_types
   * @param other_tuple
   * @return true
   * @return false
   */
  template<class... t_other_types> constexpr bool equals(tuple<t_other_types...> const &other_tuple) const {
    return (m_first_value.m_value == other_tuple.m_first_value.m_value) && t_my_base::equals(other_tuple.get_rest());
  }

  /**
   * @brief Used in all comparison operators.
   *
   * @tparam t_other_types
   * @param other_tuple
   * @return true
   * @return false
   */
  template<class... t_other_types> constexpr bool less(tuple<t_other_types...> const &other_tuple) const {
    return (m_first_value.m_value < other_tuple.m_first_value.m_value)
        || (!(other_tuple.m_first_value.m_value < m_first_value.m_value) && t_my_base::less(other_tuple.get_rest()));
  }

  /* TRANSITION, VSO-1538698 */
  template<size_t t_index, class... t_types> friend auto &&_Tuple_get(tuple<t_types...> &&given_tuple) noexcept;

  /**
   * @brief
   *
   * @tparam t_index
   * @tparam t_types
   * @param other_tuple
   * @return constexpr tuple_element_t<t_index, tuple<t_types...>>&
   */
  template<size_t t_index, class... t_types>
  friend constexpr tuple_element_t<t_index, tuple<t_types...>> &get(tuple<t_types...> &other_tuple) noexcept;

  /**
   * @brief
   *
   * @tparam t_index
   * @tparam t_types
   * @param other_tuple
   * @return constexpr tuple_element_t<t_index, tuple<t_types...>> const&
   */
  template<size_t t_index, class... t_types>
  friend constexpr tuple_element_t<t_index, tuple<t_types...>> const &get(
    tuple<t_types...> const &other_tuple) noexcept;

  /**
   * @brief
   *
   * @tparam t_index
   * @tparam t_types
   * @param other_tuple
   * @return constexpr tuple_element_t<t_index, tuple<t_types...>>&&
   */
  template<size_t t_index, class... t_types>
  friend constexpr tuple_element_t<t_index, tuple<t_types...>> &&get(tuple<t_types...> &&other_tuple) noexcept;

  /**
   * @brief
   *
   * @tparam t_index
   * @tparam t_types
   * @param other_tuple
   * @return constexpr tuple_element_t<t_index, tuple<t_types...>> const&&
   */
  template<size_t t_index, class... t_types>
  friend constexpr tuple_element_t<t_index, tuple<t_types...>> const &&get(
    tuple<t_types...> const &&other_tuple) noexcept;

  /**
   * @brief
   *
   * @tparam t_type
   * @tparam t_types
   * @param other_tuple
   * @return constexpr t_type&
   */
  template<class t_type, class... t_types> friend constexpr t_type &get(tuple<t_types...> &other_tuple) noexcept;

  /**
   * @brief
   *
   * @tparam t_type
   * @tparam t_types
   * @param other_tuple
   * @return constexpr t_type const&
   */
  template<class t_type, class... t_types>
  friend constexpr t_type const &get(tuple<t_types...> const &other_tuple) noexcept;

  /**
   * @brief
   *
   * @tparam t_type
   * @tparam t_types
   * @param other_tuple
   * @return constexpr t_type&&
   */
  template<class t_type, class... t_types> friend constexpr t_type &&get(tuple<t_types...> &&other_tuple) noexcept;

  /**
   * @brief
   *
   * @tparam t_type
   * @tparam t_types
   * @param other_tuple
   * @return constexpr t_type const&&
   */
  template<class t_type, class... t_types>
  friend constexpr t_type const &&get(tuple<t_types...> const &&other_tuple) noexcept;
};

/**
 * @brief Construct a new tuple.
 * using tag unpack_tuple_t.
 *
 * @tparam t_this_type
 * @tparam t_rest
 * @tparam t_tag
 * @tparam t_other_type
 * @tparam t_indices
 * @param other Other tuple.
 */
template<class t_this_type, class... t_rest>
template<class t_tag,
         class t_other_type,
         ::portable_stl::size_t... t_indices,
         tuple_helper::enable_if_tag_t<tuple_helper::unpack_tuple_t, t_tag> /* = nullptr */>
tuple<t_this_type, t_rest...>::tuple(t_tag, t_other_type &&other, index_sequence<t_indices...>)
    : tuple(tuple_helper::exact_args_t{},
            ::portable_stl::get<t_indices>(::portable_stl::forward<t_other_type>(other))...) {
}

/**
 * @brief Construct a new tuple.
 * using tag alloc_unpack_tuple_t.
 *
 * @tparam t_this_type
 * @tparam t_rest
 * @tparam t_tag
 * @tparam t_allocator
 * @tparam t_tuple
 * @tparam t_indices
 * @param allocator Given allocator.
 * @param other Other tuple.
 */
template<class t_this_type, class... t_rest>
template<class t_tag,
         class t_allocator,
         class t_tuple,
         size_t... t_indices,
         tuple_helper::enable_if_tag_t<tuple_helper::alloc_unpack_tuple_t, t_tag> /* = nullptr */>
tuple<t_this_type, t_rest...>::tuple(
  t_tag, t_allocator const &allocator, t_tuple &&other, ::portable_stl::index_sequence<t_indices...>)
    : tuple(tuple_helper::alloc_exact_args_t{},
            allocator,
            ::portable_stl::get<t_indices>(::portable_stl::forward<t_tuple>(other))...) {
}

} // namespace portable_stl

#endif // PSTL_TUPLE_H
