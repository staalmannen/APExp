// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iter_swap.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ITER_SWAP_H
#define PSTL_ITER_SWAP_H

#include "../concepts/class_or_enum.h"
#include "../concepts/swappable_with.h"
#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/remove_cvref.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../metaprogramming/primary_type/is_lvalue_reference.h"
#include "../utility/general/declval.h"
#include "../utility/general/forward.h"
#include "../utility/general/swap.h"
#include "concepts/indirectly_movable_storable.h"
#include "concepts/indirectly_readable.h"
#include "iter_reference_t.h"

namespace std {
namespace ranges {
  namespace iter_swap_impl {
    /**
     * @brief Poison pill: Do not search in this scope?
     */
    // template<class t_type, class u_type> void iter_swap(t_type, u_type) = delete;

    // template<class t_type, class u_type, class = void> class adl_iter_swap final {
    // public:
    //   using type = ::std::false_type;
    // };

    // template<class t_type, class u_type>
    // class adl_iter_swap<
    //   t_type,
    //   u_type,
    //   decltype(iter_swap(::std::declval<t_type&>(), ::std::declval<u_type&>()))>
    //   final {
    // public:
    //   using type = ::std::disjunction<::std::class_or_enum<::std::remove_cvref_t<t_type>>,
    //                                            ::std::class_or_enum<::std::remove_cvref_t<u_type>>>;
    // };

    /**
     * @brief Helper class to check if adl iter_swap function could be called.
     * @tparam t_type Given type.
     * @tparam u_type Given type.
     */
    template<class t_type, class u_type> class adl_iter_swap final {
      /**
       * @brief Test function.
       *
       * @tparam T1
       * @tparam T2
       * @param t_value
       * @param u_value
       * @return ::std::true_type
       */
      template<class T1, class T2>
      static auto test(T1 &&t_value, T2 &&u_value) -> decltype(iter_swap(::std::forward<T1>(t_value),
                                                                         ::std::forward<T2>(u_value)),
                                                               ::std::true_type{});

      /**
       * @brief Test function.
       *
       * @tparam T1
       * @tparam T2
       * @return ::std::false_type
       */
      template<class T1, class T2> static auto test(...) -> ::std::false_type;

    public:
      /**
       * @brief Result type.
       */
      using type = ::std::conjunction<
        decltype(test<t_type, u_type>(::std::declval<t_type>(), ::std::declval<u_type>())),
        ::std::disjunction<::std::class_or_enum<::std::remove_cvref_t<t_type>>,
                                    ::std::class_or_enum<::std::remove_cvref_t<u_type>>>>;
    };

    /**
     * @brief Helper to check if adl iter_swap function could be called.
     * @tparam t_type Given type.
     * @tparam u_type Given type.
     */
    template<class t_type, class u_type> using is_adl_iter_swap = typename adl_iter_swap<t_type, u_type>::type;

    /**
     * @brief Helper to check if indirect swap could be called for types.
     * @tparam t_type Given type.
     * @tparam u_type Given type.
     */
    template<class t_type, class u_type>
    using is_readable_swappable
      = ::std::conjunction<::std::indirectly_readable<t_type>,
                                    ::std::indirectly_readable<u_type>,
                                    ::std::swappable_with<::std::iter_reference_t<t_type>,
                                                                   ::std::iter_reference_t<u_type>>>;

    /**
     * @brief iter_swap functor implemenatation.
     */
    class iter_swap_fn final {
    public:
      /**
       * @brief Implementation for types with adl iter_swap function.
       * @tparam t_type Given type.
       * @tparam u_type Given type.
       * @param t_value Value of type t_type.
       * @param u_value Value of type u_type.
       */
      template<class t_type,
               class u_type,
               ::std::enable_if_bool_constant_t<is_adl_iter_swap<t_type, u_type>, void *> = nullptr>
      void operator()(t_type &&t_value, u_type &&u_value) const noexcept(
        noexcept(iter_swap(::std::forward<t_type>(t_value), ::std::forward<u_type>(u_value)))) {
        static_cast<void>(
          iter_swap(::std::forward<t_type>(t_value), ::std::forward<u_type>(u_value)));
      }

      /**
       * @brief One of the implementations.
       * @tparam t_type Given type.
       * @tparam u_type Given type.
       * @param t_value Value of type t_type.
       * @param u_value Value of type u_type.
       */
      template<class t_type,
               class u_type,
               ::std::enable_if_bool_constant_t<
                 ::std::conjunction<::std::negation<is_adl_iter_swap<t_type, u_type>>,
                                             is_readable_swappable<t_type, u_type>>,
                 void *>
               = nullptr>
      void operator()(t_type &&t_value, u_type &&u_value) const noexcept(noexcept(::std::ranges::swap2(
        *::std::forward<t_type>(t_value), *::std::forward<u_type>(u_value)))) {
        ::std::ranges::swap2(*::std::forward<t_type>(t_value),
                                      *::std::forward<u_type>(u_value));
      }

      /**
       * @brief One of implementations.
       * @tparam t_type Given type.
       * @tparam u_type Given type.
       * @param t_value Value of type t_type.
       * @param u_value Value of type u_type.
       */
      template<class t_type,
               class u_type,
               ::std::enable_if_bool_constant_t<
                 ::std::conjunction<::std::negation<is_adl_iter_swap<t_type, u_type>>,
                                             ::std::negation<is_readable_swappable<t_type, u_type>>,
                                             ::std::indirectly_movable_storable<t_type, u_type>,
                                             ::std::indirectly_movable_storable<u_type, t_type>>,
                 void *>
               = nullptr>
      void operator()(t_type &&t_value, u_type &&u_value) const
        noexcept(noexcept(::std::iter_value_t<u_type>(::std::ranges::iter_move(u_value))) && //
                 noexcept(*u_value = ::std::ranges::iter_move(t_value)) &&                            //
                 noexcept(*::std::forward<t_type>(t_value)
                          = ::std::declval<::std::iter_value_t<u_type>>())) {
        ::std::iter_value_t<u_type> tmp(::std::ranges::iter_move(u_value));
        *u_value                                  = ::std::ranges::iter_move(t_value);
        *::std::forward<t_type>(t_value) = ::std::move(tmp);
      }
    };
  } // namespace iter_swap_impl

  /**
   * Customization Point Design in C++11 and Beyond from
   * https://ericniebler.com/2014/10/21/customization-point-design-in-c11-and-beyond/
   *
   */

  /**
   * @brief Helper wrapper with static member to brak ODR violation.
   * @tparam t_type Given type.
   */
  template<class t_type> struct static_const_wrapper4 {
    /**
     * @brief The only static member.
     */
    constexpr static t_type value{};
  };

  /**
   * @brief Static member initialization.
   * @tparam t_type Given type.
   */
  template<class t_type> constexpr t_type static_const_wrapper4<t_type>::value;

  namespace {
    constexpr auto const &iter_swap2
      = static_const_wrapper4<::std::ranges::iter_swap_impl::iter_swap_fn>::value;
  } // namespace
} // namespace ranges
} // namespace std

#endif // PSTL_ITER_SWAP_H
