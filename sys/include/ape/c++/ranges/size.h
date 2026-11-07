// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="size.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SIZE_H
#define PSTL_SIZE_H

#include "../common/size_t.h"
#include "../concepts/class_or_enum.h"
#include "../concepts/integral.h"
#include "../concepts/same_as.h"
#include "../iterator/concepts/forward_iterator.h"
#include "../iterator/concepts/sentinel_for.h"
#include "../iterator/concepts/sized_sentinel_for.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/decay.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/remove_cvref.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../metaprogramming/primary_type/is_lvalue_reference.h"
#include "../metaprogramming/reference_modifications/remove_reference.h"
#include "../metaprogramming/sign_modifications/make_unsigned.h"
#include "../metaprogramming/type_properties/is_bounded_array.h"
#include "../metaprogramming/type_property_queries/extent.h"
#include "../utility/general/declval.h"
#include "begin.h"
#include "concepts/disable_sized_range.h"
#include "concepts/range.h"
#include "end.h"
#include "iterator_t.h"

namespace std {
namespace ranges {
  namespace size_impl_helper {
    /**
     * @brief Helper to check if a size is available for a given t_type.
     * @tparam t_type Given type.
     */
    template<class t_type>
    using is_size_enabled = ::std::negation<
      ::std::ranges::ranges_helper::disable_sized_range_bool_constant<::std::remove_cvref_t<t_type>>>;

    /**
     * @brief Helper 'concept'.
     * @tparam t_type Given type.
     */
    template<class t_type>
    using integer_like = ::std::conjunction<::std::integral<t_type>,
                                                     ::std::negation<::std::same_as<t_type, bool>>>;

    /**
     * @brief Helper to check if t_type has size() member function.
     * @tparam t_type Tested type.
     */
    template<class t_type> class has_member_size_impl final {
      /**
       * @brief Test function.
       *
       * @tparam T1
       * @param t_value
       * @return ::std::true_type
       */
      template<class T1>
      static auto test(T1 &&t_value)
        -> decltype((::std::forward<T1>(t_value).size()), ::std::true_type{});

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
     * @brief member_size_impl impl.
     * @tparam t_type Tested type.
     */
    template<class t_type, class = typename has_member_size_impl<t_type>::type> class member_size_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::std::conjunction<is_size_enabled<t_type>,
                                               integer_like<decltype(::std::declval<t_type &>().size())>>;
    };

    /**
     * @brief member_size_impl impl.
     * @tparam t_type Tested type.
     */
    template<class t_type> class member_size_impl<t_type, ::std::false_type> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::std::false_type;
    };

    /**
     * @brief Helper to check if t_type has size() member function.
     * @tparam t_type Tested type.
     */
    template<class t_type>
    using member_size = typename ::std::ranges::size_impl_helper::member_size_impl<t_type>::type;

    // ifdef _msvc_
    /**
     * @brief Poison pill: Do not search in this scope?
     */
    void size();

    /**
     * @brief Helper to check if t_type could be passed into size() somehow.
     * @tparam t_type Tested type.
     */
    template<class t_type> class has_adl_size_impl final {
      /**
       * @brief Test function.
       *
       * @tparam T1
       * @param t_value
       * @return ::std::true_type
       */
      template<class T1>
      static auto test(T1 &&t_value)
        -> decltype(size(::std::forward<T1>(t_value)), ::std::true_type{});

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
     * @brief member_size_impl impl.
     * @tparam t_type Tested type.
     */
    template<class t_type, class = typename has_adl_size_impl<t_type>::type> class unqualified_size_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::std::conjunction<is_size_enabled<t_type>,
                                               ::std::negation<member_size<t_type>>,
                                               ::std::class_or_enum<::std::remove_cvref_t<t_type>>,
                                               integer_like<decltype(size(::std::declval<t_type>()))>>;
    };

    /**
     * @brief unqualified_size impl.
     * @tparam t_type Tested type.
     */
    template<class t_type> class unqualified_size_impl<t_type, ::std::false_type> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::std::false_type;
    };

    /**
     * @brief Helper to check if t_type could be passed into size() somehow. And its converted type models
     * integer_like<t_type>.
     *
     * @tparam t_type Tested type.
     */
    template<class t_type> using unqualified_size = typename unqualified_size_impl<t_type>::type;

    /**
     * @brief Check if size could be calculated only indirectly.
     * ranges::begin and ranges::end can be calculated.
     * @tparam t_type Given type.
     */
    template<class t_type, class = ::std::ranges::range<t_type>> class can_difference_impl final {
      /**
       * @brief Begin type of range.
       */
      using begin_t = decltype(::std::ranges::begin(::std::declval<t_type &>()));
      /**
       * @brief End type of range.
       */
      using end_t   = decltype(::std::ranges::end(::std::declval<t_type &>()));

    public:
      /**
       * @brief Result type.
       */
      using type = ::std::conjunction<::std::negation<member_size<t_type>>,
                                               ::std::negation<unqualified_size<t_type>>,
                                               ::std::class_or_enum<::std::remove_cvref_t<t_type>>,
                                               ::std::forward_iterator<begin_t>,
                                               ::std::sized_sentinel_for<end_t, begin_t>>;
    };

    /**
     * @brief Check if size could be calculated only indirectly.
     * ranges::begin and ranges::end can NOT be calculated.
     * @tparam t_type Given type.
     */
    template<class t_type> class can_difference_impl<t_type, ::std::false_type> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::std::false_type;
    };

    /**
     * @brief Check if size could be calculated only indirectly.
     * @tparam t_type Given type.
     */
    template<class t_type> using can_difference = typename can_difference_impl<t_type>::type;

    /**
     * @brief Size functional object implemenation.
     */
    class size_fn final {
    public:
      /**
       * @brief Implementation for bounded array.
       *
       * @tparam t_type Given type.
       * @return Size of the given range.
       */

      template<class t_type,
               ::std::enable_if_bool_constant_t<
                 ::std::is_bounded_array<::std::remove_reference_t<t_type>>,
                 void *>
               = nullptr>
      constexpr auto operator()(t_type &&) const noexcept {
        return ::std::extent<::std::remove_reference_t<t_type>>{}();
      }

      /**
       * @brief Implementation for t_type with .size() member function.
       *
       * @tparam t_type Given type.
       * @param value Given value.
       * @return Size of the given range.
       */
      template<
        class t_type,
        ::std::enable_if_bool_constant_t<::std::ranges::size_impl_helper::member_size<t_type>, void *>
        = nullptr>
      constexpr auto operator()(t_type &&value) const
        noexcept(noexcept(static_cast<::std::decay_t<decltype((value.size()))>>(value.size()))) {
        return static_cast<::std::decay_t<decltype((value.size()))>>(value.size());
      }

      /**
       * @brief Implementation for type with adl size() function.
       *
       * @tparam t_type Given type.
       * @param value Given value.
       * @return Size of the given range.
       */
      template<class t_type,
               ::std::
                 enable_if_bool_constant_t<::std::ranges::size_impl_helper::unqualified_size<t_type>, void *>
               = nullptr>
      constexpr auto operator()(t_type &&value) const
        noexcept(noexcept(static_cast<::std::decay_t<decltype((size(value)))>>(size(value)))) {
        return static_cast<::std::decay_t<decltype((size(value)))>>(size(value));
      }

      /**
       * @brief Implementation for type with deduced begin and end.
       *
       * @tparam t_type Given type.
       * @param value Given value.
       * @return Size of the given range.
       */
      template<class t_type,
               ::std::
                 enable_if_bool_constant_t<::std::ranges::size_impl_helper::can_difference<t_type>, void *>
               = nullptr>
      constexpr auto operator()(t_type &&value) const
        noexcept(noexcept(::std::sign_modifications_helpers::to_unsigned_like(
          ::std::ranges::end(value) - ::std::ranges::begin(value))))
          -> decltype(::std::sign_modifications_helpers::to_unsigned_like(
            ::std::ranges::end(value) - ::std::ranges::begin(value))) {
        return ::std::sign_modifications_helpers::to_unsigned_like(
          ::std::ranges::end(value) - ::std::ranges::begin(value));
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
  } // namespace size_impl_helper

  namespace {
    constexpr auto const &size = size_impl_helper::static_const_wrapper<size_impl_helper::size_fn>::value;
  } // namespace
} // namespace ranges
} // namespace std

#endif /* PSTL_SIZE_H */
