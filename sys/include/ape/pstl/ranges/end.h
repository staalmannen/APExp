// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="end.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_END_H
#define PSTL_END_H

#include "../concepts/class_or_enum.h"
#include "../iterator/concepts/sentinel_for.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/decay.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/remove_cvref.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../metaprogramming/primary_type/is_lvalue_reference.h"
#include "../utility/general/declval.h"
#include "concepts/maybe_borrowed_range.h"
#include "iterator_t.h"

namespace portable_stl {
namespace ranges {
  namespace end_impl_helper {
    /**
     * @brief Helper to check if t_type has end() member function.
     * Primary template.
     */
    template<class, class = void> class member_end_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };

    /**
     * @brief Helper to check if t_type has end() member function.
     * @tparam t_type Tested type.
     */
    template<class t_type>
    class member_end_impl<t_type,
                          ::portable_stl::void_t<::portable_stl::ranges::iterator_t<t_type>,
                                                 decltype(::portable_stl::declval<t_type>().end())>>
      final {
    public:
      /**
       * @brief Result type.
       */
      using type
        = ::portable_stl::conjunction<::portable_stl::ranges::maybe_borrowed_range<t_type>,
                                      ::portable_stl::sentinel_for<decltype(::portable_stl::declval<t_type>().end()),
                                                                   ::portable_stl::ranges::iterator_t<t_type>>>;
    };

    /**
     * @brief Helper to check if t_type has end() member function.
     * @tparam t_type Tested type.
     */
    template<class t_type>
    using member_end = typename ::portable_stl::ranges::end_impl_helper::member_end_impl<t_type>::type;

    // ifdef _msvc_
    /**
     * @brief Poison pill: Do not search in this scope?
     */
    void end();

    /**
     * @brief Helper to check if end(t) models sentinel_for<iterator_t<t_type>>.
     * @tparam t_type Tested type.
     */
    template<class t_type, class = typename ranges_helper::has_iterator_t<t_type>::type> class is_sentinel_for final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::sentinel_for<decltype(end(::portable_stl::declval<t_type>())),
                                                ::portable_stl::ranges::iterator_t<t_type>>;
    };

    /**
     * @brief Helper to check if end(t) models sentinel_for<iterator_t<t_type>>.
     * @tparam t_type Tested type.
     */
    template<class t_type> class is_sentinel_for<t_type, ::portable_stl::false_type> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };

    /**
     * @brief Helper to check if t_type could be passed into end() somehow.
     * @tparam t_type Tested type.
     */
    template<class t_type> class has_adl_end_impl final {
      /**
       * @brief Test function.
       *
       * @tparam T1
       * @param t_value
       * @return ::portable_stl::true_type
       */
      template<class T1>
      static auto test(T1 &&t_value)
        -> decltype(end(::portable_stl::forward<T1>(t_value)), ::portable_stl::true_type{});

      /**
       * @brief Test function.
       * @tparam T1
       * @return ::portable_stl::false_type
       */
      template<class T1> static auto test(...) -> ::portable_stl::false_type;

    public:
      /**
       * @brief Result type.
       */
      using type = decltype(test<t_type>(::portable_stl::declval<t_type>()));
    };

    /**
     * @brief Check other properties to call begin() for given t_type.
     * @tparam t_type Given type.
     */
    template<class t_type, class = typename has_adl_end_impl<t_type>::type> class unqualified_end_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::conjunction<::portable_stl::negation<member_end<t_type>>,
                                               ::portable_stl::ranges::maybe_borrowed_range<t_type>,
                                               ::portable_stl::class_or_enum<::portable_stl::remove_cvref_t<t_type>>,
                                               typename is_sentinel_for<t_type>::type>;
    };

    /**
     * @brief Check other properties to call end() for given t_type.
     * @tparam t_type Given type.
     */
    template<class t_type> class unqualified_end_impl<t_type, ::portable_stl::false_type> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };

    /**
     * @brief Helper to check if t_type could be passed into end() somehow. And its converted type models
     * sentinel_for<ranges::iterator_t<t_type>>.
     * @tparam t_type Tested type.
     */
    template<class t_type> using unqualified_end = typename unqualified_end_impl<t_type>::type;

    /**
     * @brief End functional object implemenation.
     */
    class end_fn final {
    public:
      /**
       * @brief Returns a sentinel indicating the end of a range.
       * Array with known size.
       * @tparam t_type Type of range.
       * @param array Given array.
       * @return A sentinel indicating the end of a range.
       */
      template<class t_type, size_t arr_size> constexpr auto operator()(t_type (&array)[arr_size]) const noexcept {
        return array + arr_size;
      }

      /**
       * @brief Returns a sentinel indicating the end of a range.
       * t_type has .end() member function.
       * @tparam t_type Type of range.
       * @param value Given range/container.
       * @return constexpr auto A sentinel indicating the end of a range.
       */
      template<class t_type, ::portable_stl::enable_if_bool_constant_t<member_end<t_type>, void *> = nullptr>
      constexpr auto operator()(t_type &&value) const
        noexcept(noexcept(static_cast<::portable_stl::decay_t<decltype((value.end()))>>(value.end()))) {
        return static_cast<::portable_stl::decay_t<decltype((value.end()))>>(value.end());
      }

      /**
       * @brief Returns a sentinel indicating the end of a range.
       * Value could be passed into end() function.
       * @tparam t_type Type of range.
       * @param value Given range/container.
       * @return A sentinel indicating the end of a range.
       */
      template<class t_type,
               ::portable_stl::
                 enable_if_bool_constant_t<::portable_stl::ranges::end_impl_helper::unqualified_end<t_type>, void *>
               = nullptr>
      constexpr auto operator()(t_type &&value) const
        noexcept(noexcept(static_cast<::portable_stl::decay_t<decltype((end(value)))>>(end(value)))) {
        return static_cast<::portable_stl::decay_t<decltype((end(value)))>>(end(value));
      }
    };

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
  } // namespace end_impl_helper

  namespace {
    constexpr auto const &end = end_impl_helper::static_const_wrapper<end_impl_helper::end_fn>::value;
  } // namespace
} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_END_H */
