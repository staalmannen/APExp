// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="rbegin.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_RBEGIN_H
#define PSTL_RBEGIN_H

#include "../concepts/class_or_enum.h"
#include "../iterator/concepts/bidirectional_iterator.h"
#include "../iterator/concepts/input_or_output_iterator.h"
#include "../iterator/reverse_iterator.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/decay.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/is_detected.h"
#include "../metaprogramming/other_transformations/remove_cvref.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../utility/general/declval.h"
#include "begin.h"
#include "concepts/maybe_borrowed_range.h"
#include "end.h"

namespace std {
namespace ranges {
  namespace rbegin_impl_helper {
    /**
     * @brief Helper to check if t_type has rbegin() member function.
     * @tparam t_type Given type.
     */
    template<class t_type> class has_member_rbegin_impl final {
      /**
       * @brief Test function.
       *
       * @tparam T1
       * @param t_value
       * @return ::std::true_type
       */
      template<class T1>
      static auto test(T1 &&t_value) -> decltype(::std::forward<T1>(t_value).rbegin(),
                                                 ::std::true_type{});

      /**
       * @brief Test function.
       * @tparam T1
       * @return ::std::false_type
       */
      template<class T1> static auto test(...) -> ::std::false_type;

    public:
      /**
       * @brief Result type.
       */
      using type = decltype(test<t_type>(::std::declval<t_type>()));
    };

    /**
     * @brief Helper to check if t_type has rbegin() member function + input_or_output_iterator.
     * Primary template.
     */
    template<class t_type, class = typename has_member_rbegin_impl<t_type>::type> class member_rbegin_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::std::conjunction<
        ::std::ranges::maybe_borrowed_range<t_type>,
        ::std::input_or_output_iterator<decltype(::std::declval<t_type &>().rbegin())>>;
    };

    /**
     * @brief Helper to check if t_type has rbegin() member function + input_or_output_iterator.
     * Negative result.
     * @tparam t_type Tested type.
     */
    template<class t_type> class member_rbegin_impl<t_type, ::std::false_type> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::std::false_type;
    };

    /**
     * @brief Helper to check if t_type has rbegin() member function.
     * @tparam t_type Tested type.
     */
    template<class t_type>
    using member_rbegin = typename ::std::ranges::rbegin_impl_helper::member_rbegin_impl<t_type>::type;

    /**
     * @brief Poison pill: Do not search in this scope?
     */
    void                        rbegin();
    /**
     * @brief Poison pill: Do not search in this scope?
     */
    template<class t_type> void rbegin(t_type &);
    /**
     * @brief Poison pill: Do not search in this scope?
     */
    template<class t_type> void rbegin(t_type const &);

    /**
     * @brief Helper to check if t_type could be passed into rbegin() somehow.
     * @tparam t_type Given type.
     */
    template<class t_type> class has_adl_rbegin_impl final {
      /**
       * @brief Test function.
       *
       * @tparam T1
       * @param t_value
       * @return ::std::true_type
       */
      template<class T1>
      static auto test(T1 &&t_value) -> decltype(rbegin(::std::forward<T1>(t_value)),
                                                 ::std::true_type{});

      /**
       * @brief Test function.
       * @tparam T1
       * @return ::std::false_type
       */
      template<class T1> static auto test(...) -> ::std::false_type;

    public:
      /**
       * @brief Result type.
       */
      using type = decltype(test<t_type>(::std::declval<t_type>()));
    };

    /**
     * @brief Check other properties to call rbegin() for given t_type.
     * @tparam t_type Given type.
     */
    template<class t_type, class = typename has_adl_rbegin_impl<t_type>::type> class unqualified_rbegin_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::std::conjunction<
        ::std::negation<member_rbegin<t_type>>,
        ::std::ranges::maybe_borrowed_range<t_type>,
        ::std::class_or_enum<::std::remove_cvref<t_type>>,
        ::std::input_or_output_iterator<decltype(rbegin(::std::declval<t_type &>()))>>;
    };

    /**
     * @brief Check other properties to call rbegin() for given t_type.
     * @tparam t_type Given type.
     */
    template<class t_type> class unqualified_rbegin_impl<t_type, ::std::false_type> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::std::false_type;
    };

    /**
     * @brief Helper to check if t_type could be passed into rbegin() somehow. And its result is an
     * input_or_output_iterator.
     * @tparam t_type Tested type.
     */
    template<class t_type>
    using unqualified_rbegin =
      typename ::std::ranges::rbegin_impl_helper::unqualified_rbegin_impl<t_type>::type;

    /**
     * @brief Helper to check if range of the given type could be revesed.
     * @tparam t_type Range type.
     */
    template<class t_type, class = void> class is_reversable_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::std::false_type;
    };

    /**
     * @brief Helper to check if range of the given type could be revesed.
     * @tparam t_type Range type.
     */
    template<class t_type>
    class is_reversable_impl<
      t_type,
      ::std::void_t<decltype(::std::ranges::begin(::std::declval<t_type &>())),
                             decltype(::std::ranges::end(::std::declval<t_type &>()))>>
      final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::std::conjunction<
        ::std::ranges::maybe_borrowed_range<t_type>,
        ::std::negation<member_rbegin<t_type>>,
        ::std::negation<unqualified_rbegin<t_type>>,
        ::std::bidirectional_iterator<decltype(::std::ranges::begin(
          ::std::declval<t_type &>()))>,
        ::std::same_as<decltype(::std::ranges::end(::std::declval<t_type &>())),
                                decltype(::std::ranges::begin(::std::declval<t_type &>()))>>;
    };

    /**
     * @brief Helper to check if range of the given type could be revesed.
     * @tparam t_type Range type.
     */
    template<class t_type> using is_reversable = typename is_reversable_impl<t_type>::type;

    /**
     * @brief Rbegin functional object implemenation.
     */
    class rbegin_fn final {
    public:
      /**
       * @brief Returns an iterator to the reverse-beginning of the given range.
       * Value has rbegin() member function.
       * @tparam t_type Type of range.
       * @param value Given range/container.
       * @return an iterator to the reverse-beginning.
       */
      template<class t_type, ::std::enable_if_bool_constant_t<member_rbegin<t_type>, void *> = nullptr>
      constexpr auto operator()(t_type &&value) const
        noexcept(noexcept(static_cast<::std::decay_t<decltype((value.rbegin()))>>(value.rbegin()))) {
        return static_cast<::std::decay_t<decltype((value.rbegin()))>>(value.rbegin());
      }

      /**
       * @brief Returns an iterator to the reverse-beginning of the given range.
       * Value could be passed into rbegin() function.
       * @tparam t_type Type of range.
       * @param value Given range/container.
       * @return an iterator to the reverse-beginning.
       */
      template<class t_type, ::std::enable_if_bool_constant_t<unqualified_rbegin<t_type>, void *> = nullptr>
      constexpr auto operator()(t_type &&value) const
        noexcept(noexcept(static_cast<::std::decay_t<decltype((rbegin(value)))>>(rbegin(value)))) {
        return static_cast<::std::decay_t<decltype((rbegin(value)))>>(rbegin(value));
      }

      /**
       * @brief Returns an iterator to the reverse-beginning of the given range.
       * Range could be reversed.
       * @tparam t_type Type of range.
       * @param value Given range/container.
       * @return an iterator to the reverse-beginning.
       */
      template<class t_type, ::std::enable_if_bool_constant_t<is_reversable<t_type>, void *> = nullptr>
      constexpr auto operator()(t_type &&value) const noexcept(noexcept(::std::ranges::end(value))) {
        return ::std::make_reverse_iterator(::std::ranges::end(value));
      }
    };

    /**
     * Modern approach with inline variable with external linkage
     *
     * inline namespace cpo {
     *     constexpr begin_impl_helper::begin_fn const begin{};
     * } // namespace cpo
     *
     **/

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
  } // namespace rbegin_impl_helper

  namespace {
    /**
     * @brief Returns an iterator to the reverse-beginning of the given range.
     */
    constexpr auto const &rbegin = rbegin_impl_helper::static_const_wrapper<rbegin_impl_helper::rbegin_fn>::value;
  } // namespace

} // namespace ranges
} // namespace std

#endif /* PSTL_RBEGIN_H */
