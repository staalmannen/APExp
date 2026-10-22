// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_empty_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_EMPTY_IMPL_H
#define PSTL_TUPLE_EMPTY_IMPL_H

#include "../../memory/allocator_arg.h"
#include "../../metaprogramming/other_transformations/remove_cvref.h"
#include "../../utility/general/swap.h"
#include "fwd_decl_tuple.h"
#include "tuple_helper.h"
#include "tuple_like.h"
#include "tuple_size.h"

namespace portable_stl {

/**
 * @brief Empty tuple specialization
 */
template<> class tuple<> {
public:
  /**
   * @brief Default ctor.
   */
  constexpr tuple() noexcept = default; /* strengthened */

  /**
   * @brief Copy ctor.
   */
  constexpr tuple(tuple const &) noexcept /* strengthened */ {
  }

  // There are no other tuple-like object with zero size.
  // /**
  //  * @brief Ctor from other tuple-like object.
  //  *
  //  * @tparam t_other_type Other object type.
  //  */
  // template<
  //   class t_other_type,
  //   ::portable_stl::enable_if_bool_constant_t<::portable_stl::different_from<tuple, t_other_type>, void *> = nullptr,
  //   ::portable_stl::enable_if_bool_constant_t<
  //     ::portable_stl::conjunction<::portable_stl::tuple_helper::tuple_like<t_other_type>,
  //                                 ::portable_stl::bool_constant<
  //                                   ::portable_stl::tuple_size<::portable_stl::remove_cvref_t<t_other_type>>{}() ==
  //                                   0>>,
  //     void *>
  //   = nullptr>
  // constexpr tuple(t_other_type &&) noexcept /* strengthened */ {
  // }

  /**
   * @brief Ctor with allocator.
   *
   * @tparam t_allocator_type Allocator type.
   */
  template<class t_allocator_type>
  constexpr tuple(::portable_stl::allocator_arg_t, t_allocator_type const &) noexcept /* strengthened */ {
  }

  /**
   * @brief Copy ctor with allocator.
   *
   * @tparam t_allocator_type Allocator type.
   */
  template<class t_allocator_type>
  constexpr tuple(::portable_stl::allocator_arg_t, t_allocator_type const &, tuple const &) noexcept // strengthened
  {
  }

  // There are no other tuple-like object with zero size.
  // /**
  //  * @brief Copy ctor from other tuple-like object with allocator.
  //  *
  //  * @tparam t_allocator_type Allocator type.
  //  * @tparam t_other_type Other object type.
  //  */
  // template<class t_allocator_type,
  //          class t_other_type,
  //          ::portable_stl::enable_if_bool_constant_t<::portable_stl::different_from<tuple, t_other_type>, void *>
  //          = nullptr,
  //          ::portable_stl::enable_if_bool_constant_t<
  //            ::portable_stl::conjunction<
  //              ::portable_stl::tuple_helper::tuple_like<t_other_type>,
  //              ::portable_stl::bool_constant<tuple_size<::portable_stl::remove_cvref_t<t_other_type>>{}() == 0>>,
  //            void *>
  //          = nullptr>
  // constexpr tuple(::portable_stl::allocator_arg_t, t_allocator_type const &, t_other_type &&) noexcept //
  // strengthened
  // {
  // }

  /**
   * @brief Ctor with tag.
   *
   * @tparam t_tag
   */
  template<class t_tag, tuple_helper::enable_if_tag_t<tuple_helper::exact_args_t, t_tag> = nullptr>
  constexpr tuple(t_tag) noexcept /* strengthened */ {
  }

  /**
   * @brief Ctor with tag and allocator.
   *
   * @tparam t_tag
   * @tparam t_allocator_type
   */
  template<class t_tag,
           class t_allocator_type,
           tuple_helper::enable_if_tag_t<tuple_helper::alloc_exact_args_t, t_tag> = nullptr>
  constexpr tuple(t_tag, t_allocator_type const &) noexcept /* strengthened */ {
  }

  // was constexpr and default

  /**
   * @brief Assignment operator.
   *
   * @return tuple&
   */
  tuple &operator=(tuple const &) & noexcept {
    return *this;
  }

  /**
   * @brief Copy assignement from other tuple-like object.
   *
   * @return tuple const&
   */
  tuple const &operator=(tuple const &) const & noexcept /* strengthened */ {
    return *this;
  }

// There are no other tuple-like object with zero size.
  // /**
  //  * @brief Copy assignement from other tuple-like object.
  //  *
  //  * @tparam t_other_type Other tuple-like object.
  //  */
  // template<
  //   class t_other_type,
  //   ::portable_stl::enable_if_bool_constant_t<::portable_stl::different_from<tuple, t_other_type>, void *> = nullptr,
  //   ::portable_stl::enable_if_bool_constant_t<
  //     ::portable_stl::conjunction<::portable_stl::tuple_helper::tuple_like<t_other_type>,
  //                                 ::portable_stl::bool_constant<
  //                                   ::portable_stl::tuple_size<::portable_stl::remove_cvref_t<t_other_type>>{}() == 0>>,
  //     void *>
  //   = nullptr>
  // constexpr tuple &operator=(t_other_type &&) & noexcept /* strengthened */ {
  //   return *this;
  // }
  // /**
  //  * @brief Copy assignement from other tuple-like object.
  //  *
  //  * @tparam t_other_type Other tuple-like object.
  //  */
  // template<
  //   class t_other_type,
  //   ::portable_stl::enable_if_bool_constant_t<::portable_stl::different_from<tuple, t_other_type>, void *> = nullptr,
  //   ::portable_stl::enable_if_bool_constant_t<
  //     ::portable_stl::conjunction<::portable_stl::tuple_helper::tuple_like<t_other_type>,
  //                                 ::portable_stl::bool_constant<
  //                                   ::portable_stl::tuple_size<::portable_stl::remove_cvref_t<t_other_type>>{}() == 0>>,
  //     void *>
  //   = nullptr>
  // constexpr tuple const &operator=(t_other_type &&) const & noexcept /* strengthened */ {
  //   return *this;
  // }

  /**
   * @brief swap implementation for ADL.
   * @param other
   */
  constexpr static void swap(tuple &) noexcept {
  }

  /**
   * @brief swap implementationfor ADL.
   * @param other
   */
  constexpr static void swap(tuple const &) noexcept {
  }

  /**
   * @brief Used in all comparison operators.
   *
   * @return true
   * @return false
   */
  constexpr static bool equals(tuple const &) noexcept {
    return true;
  }

  /**
   * @brief Used in all comparison operators.
   *
   * @return true
   * @return false
   */
  constexpr static bool less(tuple const &) noexcept {
    return false;
  }
};
} // namespace portable_stl

#endif /* PSTL_TUPLE_EMPTY_IMPL_H */
