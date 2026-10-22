// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="ranges_swap.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_RANGES_SWAP_H
#define PSTL_RANGES_SWAP_H

// // clang-format off
#include "../utility/general/swap_def.h"
// // clang-format on
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/disjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../metaprogramming/primary_type/is_lvalue_reference.h"
#include "../metaprogramming/reference_modifications/remove_reference.h"
#include "../metaprogramming/type_properties/is_nothrow_move_assignable.h"
#include "../metaprogramming/type_properties/is_nothrow_move_constructible.h"
#include "../metaprogramming/type_property_queries/extent.h"
#include "../metaprogramming/type_relations/is_same.h"
#include "../utility/general/declval.h"
#include "../utility/general/forward.h"
#include "../utility/general/move.h"
#include "assignable_from.h"
#include "class_or_enum.h"
#include "move_constructible.h"
#include "same_as.h"

namespace portable_stl {
namespace ranges {
  namespace swap_impl {
    /**
     * @brief Poison pill: Do not search in this scope?
     * template < class t_type > void swap ( t_type & , t_type &) = delete;
     * void swap ( ) ; - solution for parasoft
     */
    void swap();

    /**
     * @brief Helper class to check if adl swap function could be called.
     * @tparam t_type Given type.
     * @tparam u_type Given type.
     */
    template<class t_type, class u_type> class has_adl_swap final {
      /**
       * @brief Test function.
       *
       * @tparam T1
       * @tparam T2
       * @return ::portable_stl::true_type
       */
      template<class T1, class T2>
      static auto test(::portable_stl::size_t)
        -> decltype(swap(::portable_stl::declval<T1 &>(), ::portable_stl::declval<T2 &>()),
                    ::portable_stl::true_type{});

      /**
       * @brief Test function.
       *
       * @tparam T1
       * @tparam T2
       * @return ::portable_stl::false_type
       */
      template<class T1, class T2> static auto test(...) -> ::portable_stl::false_type;

    public:
      /**
       * @brief Result type.
       */
      using type = decltype(test<t_type, u_type>(0));
    };

    /**
     * @brief Helper to check if adl swap function could be called.
     *
     * @tparam t_type Given type.
     * @tparam u_type Given type.
     */
    template<class t_type, class u_type>
    using is_adl_swappable_with = ::portable_stl::conjunction<
      ::portable_stl::disjunction<::portable_stl::class_or_enum<::portable_stl::remove_cvref_t<t_type>>,
                                  ::portable_stl::class_or_enum<::portable_stl::remove_cvref_t<u_type>>>,
      typename has_adl_swap<t_type, u_type>::type>;

    /**
     * @brief Helper class to check is values could be exchanged with move.
     * @tparam t_type Tested type.
     */
    template<class t_type>
    using exchangeable
      = ::portable_stl::conjunction<::portable_stl::negation<is_adl_swappable_with<t_type &, t_type &>>,
                                    ::portable_stl::move_constructible<t_type>,
                                    ::portable_stl::assignable_from<t_type &, t_type>>;

    /**
     * @brief ranges::swap CPO class.
     */
    class swap_fn final {
    public:
      /**
       * @brief 'S' is '(void)swap(E1, E2)'* if 'E1' or 'E2' has class or enumeration type and...
       * *The name 'swap' is used here unqualified.
       * @tparam t_type Given type.
       * @tparam u_type Given type.
       * @param t_value Value of type t_type.
       * @param u_value Value of type u_type.
       */
      template<class t_type,
               class u_type,
               ::portable_stl::enable_if_bool_constant_t<is_adl_swappable_with<t_type, u_type>, void *> = nullptr>
      void operator()(t_type &&t_value, u_type &&u_value) const
        noexcept(noexcept(swap(::portable_stl::forward<t_type>(t_value), ::portable_stl::forward<u_type>(u_value)))) {
        swap(::portable_stl::forward<t_type>(t_value), ::portable_stl::forward<u_type>(u_value));
      }

      /**
       * @brief Otherwise, if 'E1' and 'E2' are lvalues of the same type 't_type' that models...
       * Equals to swap().
       * @tparam t_type Given type.
       * @param left Array of type t_type.
       * @param right Array of type t_type.
       */
      template<class t_type, ::portable_stl::enable_if_bool_constant_t<exchangeable<t_type>, void *> = nullptr>
      void operator()(t_type &left, t_type &right) const
        noexcept(::portable_stl::is_nothrow_move_constructible<t_type>{}()
                 && ::portable_stl::is_nothrow_move_assignable<t_type>{}()) {
        t_type tmp{::portable_stl::move(left)};
        left  = ::portable_stl::move(right);
        right = ::portable_stl::move(tmp);
      }

      /**
       * @brief Otherwise, if 'E1' and 'E2' are lvalues of array types with equal extent and...
       * @tparam t_type Given type.
       * @tparam u_type Given type.
       * @tparam arr_size Given arrays size.
       * @param t_value Array of type t_type.
       * @param u_value Array of type u_type.
       */
      template<class t_type, class u_type, ::portable_stl::size_t arr_size>
      void operator()(t_type (&t_value)[arr_size], u_type (&u_value)[arr_size]) const
        noexcept(noexcept((*this)(*t_value, *u_value))) {
        for (::portable_stl::size_t index{0U}; index < arr_size; ++index) {
          (*this)(t_value[index], u_value[index]);
        }
      }
    };

    /**
     * Customization Point Design in C++11 and Beyond from
     * https://ericniebler.com/2014/10/21/customization-point-design-in-c11-and-beyond/
     *
     */

    /**
     * @brief Helper wrapper with static member to brak ODR violation.
     * @tparam t_type Given type.
     */
    template<class t_type> struct static_const_wrapper {
      /**
       * @brief The only static member.
       */
      constexpr static t_type value{};
    };

    /**
     * @brief Static member initialization.
     * @tparam t_type Given type.
     */
    template<class t_type> constexpr t_type static_const_wrapper<t_type>::value;
  } // namespace swap_impl

  namespace {
    constexpr auto const &swap2 = swap_impl::static_const_wrapper<swap_impl::swap_fn>::value;
  } // namespace
} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_RANGES_SWAP_H */
