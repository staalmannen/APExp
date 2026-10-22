// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iter_move.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ITER_MOVE_H
#define PSTL_ITER_MOVE_H

#include "../concepts/class_or_enum.h"
#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/remove_cvref.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../metaprogramming/primary_type/is_lvalue_reference.h"
#include "../utility/general/declval.h"
#include "../utility/general/forward.h"
#include "../utility/general/move.h"

namespace portable_stl {
namespace ranges {
  namespace iter_move_impl {
    /**
     * @brief Poison pill: Do not search in this scope?
     */
    void iter_move();

    /**
     * @brief Helper class to check if t_type has adl iter_move function.
     * @tparam t_type Given type.
     */
    template<class, class = void> class adl_iter_move final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };
    /**
     * @brief Helper class to check if t_type has adl iter_move function.
     * @tparam t_type Given type.
     */
    template<class t_type>
    class adl_iter_move<t_type, ::portable_stl::void_t<decltype(iter_move(::portable_stl::declval<t_type>()))>> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::class_or_enum<::portable_stl::remove_cvref_t<t_type>>;
    };

    /**
     * @brief Helper class to check if *t_type is well-formed is an lvalue.
     * @tparam t_type Given type.
     */
    template<class, class = void> class move_deref_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };

    /**
     * @brief Helper class to check if *t_type is well-formed is an lvalue.
     * @tparam t_type Given type.
     */
    template<class t_type>
    class move_deref_impl<t_type, ::portable_stl::void_t<decltype(*::portable_stl::declval<t_type (&)()>()())>> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::is_lvalue_reference<decltype(*::portable_stl::declval<t_type (&)()>()())>;
    };

    /**
     * @brief Helper class to check if *t_type is well-formed is an lvalue.
     * @tparam t_type Given type.
     */
    template<class, class = void> class move_deref final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };

    /**
     * @brief Helper class to check if *t_type is well-formed is an lvalue.
     * @tparam t_type Given type.
     */
    template<class t_type>
    class move_deref<
      t_type,
      ::portable_stl::enable_if_bool_constant_t<::portable_stl::negation<typename adl_iter_move<t_type>::type>>>
      final {
    public:
      /**
       * @brief Result type.
       */
      using type = typename move_deref_impl<t_type>::type;
    };

    /**
     * @brief Helper class to check if *t_type is well-formed.
     * @tparam t_type Given type.
     */
    template<class, class = void> class just_deref_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };

    /**
     * @brief Helper class to check if *t_type is well-formed.
     * @tparam t_type Given type.
     */
    template<class t_type>
    class just_deref_impl<t_type, ::portable_stl::void_t<decltype(*::portable_stl::declval<t_type (&)()>()())>> final {
    public:
      // using type = ::portable_stl::true_type;
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::negation<
        ::portable_stl::is_lvalue_reference<decltype(*::portable_stl::declval<t_type (&)()>()())>>;
    };

    /**
     * @brief Helper class to check if *t_type is well-formed.
     * @tparam t_type Given type.
     */
    template<class, class = void> class just_deref final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };

    /**
     * @brief Helper class to check if *t_type is well-formed.
     * @tparam t_type Given type.
     */
    template<class t_type>
    class just_deref<t_type,
                     ::portable_stl::enable_if_bool_constant_t<
                       ::portable_stl::conjunction<::portable_stl::negation<typename adl_iter_move<t_type>::type>,
                                                   ::portable_stl::negation<typename move_deref<t_type>::type>>>>
      final {
    public:
      /**
       * @brief Result type.
       */
      using type = typename just_deref_impl<t_type>::type;
    };

    /**
     * @brief iter_move functor implemenatation.
     */
    class iter_move_fn final {
    public:
      /**
       * @brief Implementation for iterator types with adl iter_move function.
       *
       * @tparam iterator_t Given iterator.
       * @param iter Iterator type.
       * @return result of iter_move() invoke.
       */
      template<class iterator_t,
               ::portable_stl::enable_if_bool_constant_t<typename adl_iter_move<iterator_t>::type, void *> = nullptr>
      constexpr decltype(auto) operator()(iterator_t &&iter) const
        noexcept(noexcept(iter_move(::portable_stl::forward<iterator_t>(iter)))) {
        return iter_move(::portable_stl::forward<iterator_t>(iter));
      }

      /**
       * @brief Implementation for iterator types for which *iter is well-formed and is an lvalue.
       *
       * @tparam iterator_t Given iterator.
       * @param iter Iterator type.
       * @return move(*iter).
       */
      template<class iterator_t,
               ::portable_stl::enable_if_bool_constant_t<typename move_deref<iterator_t>::type, void *> = nullptr>
      constexpr auto operator()(iterator_t &&iter) const
        noexcept(noexcept(::portable_stl::move(*::portable_stl::forward<iterator_t>(iter))))
          -> decltype(::portable_stl::move(*::portable_stl::forward<iterator_t>(iter))) {
        return ::portable_stl::move(*::portable_stl::forward<iterator_t>(iter));
      }

      /**
       * @brief Implementation for other iterator types for which *iter is well-formed.
       *
       * @tparam iterator_t Given iterator.
       * @param iter Iterator type.
       * @return *iter.
       */
      template<class iterator_t,
               ::portable_stl::enable_if_bool_constant_t<typename just_deref<iterator_t>::type, void *> = nullptr>
      constexpr auto operator()(iterator_t &&iter) const noexcept(noexcept(*::portable_stl::forward<iterator_t>(iter)))
        -> decltype(*::portable_stl::forward<iterator_t>(iter)) {
        return *::portable_stl::forward<iterator_t>(iter);
      }
    };
  } // namespace iter_move_impl

  /**
   * Customization Point Design in C++11 and Beyond from
   * https://ericniebler.com/2014/10/21/customization-point-design-in-c11-and-beyond/
   *
   */

  /**
   * @brief Helper wrapper with static member to brak ODR violation.
   * @tparam t_type Given type.
   */
  template<class t_type> struct static_const_wrapper3 {
    /**
     * @brief The only static member.
     */
    constexpr static t_type value{};
  };

  /**
   * @brief Static member initialization.
   * @tparam t_type Given type.
   */
  template<class t_type> constexpr t_type static_const_wrapper3<t_type>::value;

  namespace {
    constexpr auto const &iter_move = static_const_wrapper3<iter_move_impl::iter_move_fn>::value;
  } // namespace
} // namespace ranges

} // namespace portable_stl

#endif /* PSTL_ITER_MOVE_H */
