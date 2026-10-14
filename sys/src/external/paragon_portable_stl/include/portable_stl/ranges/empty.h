// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="empty.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_EMPTY_H
#define PSTL_EMPTY_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../utility/general/declval.h"
#include "concepts/range.h"
#include "size.h"

namespace portable_stl {
namespace ranges {
  namespace empty_impl_helper {
    /**
     * @brief Helper to check if t_type has size() member function.
     * @tparam t_type Tested type.
     */
    template<class t_type> class member_empty_impl final {
      /**
       * @brief Test function.
       *
       * @tparam test_t
       * @param arg
       * @return ::portable_stl::true_type
       */
      template<class test_t>
      static auto test(::portable_stl::size_t arg)
        -> decltype(static_cast<void>(::portable_stl::declval<test_t>().empty()), ::portable_stl::true_type{});

      /**
       * @brief Test function.
       * @tparam test_t
       * @return ::portable_stl::false_type
       */
      template<class test_t> static auto test(...) -> ::portable_stl::false_type;

    public:
      /**
       * @brief Result type.
       */
      using type = decltype(test<t_type>(0));
    };

    /**
     * @brief Helper to check if t_type has empty() member function.
     * @tparam t_type Tested type.
     */
    template<class t_type>
    using member_empty = typename ::portable_stl::ranges::empty_impl_helper::member_empty_impl<t_type>::type;

    /**
     * @brief Helper to check if ranges::size for t_type could be invoked.
     * @tparam t_type Tested type.
     */
    template<class t_type> class can_invoke_size_impl final {
      /**
       * @brief Test function.
       *
       * @tparam test_t
       * @param arg
       * @return ::portable_stl::true_type
       */
      template<class test_t>
      static auto test(::portable_stl::size_t arg)
        -> decltype(::portable_stl::ranges::size(::portable_stl::declval<test_t>()), ::portable_stl::true_type{});

      /**
       * @brief Test function.
       * @tparam test_t
       * @return ::portable_stl::false_type
       */
      template<class test_t> static auto test(...) -> ::portable_stl::false_type;

    public:
      /**
       * @brief Result type.
       */
      using type = decltype(test<t_type>(0));
    };

    /**
     * @brief has_size implementation.
     * Primary template.
     * @tparam t_type Tested type.
     */
    template<class t_type, class = typename can_invoke_size_impl<t_type>::type> class has_size_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::negation<member_empty<t_type>>;
    };

    /**
     * @brief has_size implementation.
     * @tparam t_type Tested type.
     */
    template<class t_type> class has_size_impl<t_type, ::portable_stl::false_type> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };

    /**
     * @brief Helper to check if ranges::size for t_type could be invoked.
     * @tparam t_type Tested type.
     */
    template<class t_type>
    using has_size = typename ::portable_stl::ranges::empty_impl_helper::has_size_impl<t_type>::type;

    /**
     * @brief has_size implementation.
     * Primary template.
     * note: used ::portable_stl::ranges::size_impl_helper::has_begin_end
     * @tparam t_type Tested type.
     */
    template<class t_type, class = ::portable_stl::ranges::range<t_type>> class can_compare_begin_end_impl final {
      /**
       * @brief Test function.
       *
       * @tparam test_t
       * @param arg
       * @return ::portable_stl::true_type
       */
      template<class test_t>
      static auto test(::portable_stl::size_t arg)
        -> decltype(static_cast<void>(::portable_stl::ranges::begin(::portable_stl::declval<test_t>())
                                      == ::portable_stl::ranges::end(::portable_stl::declval<test_t>())),
                    ::portable_stl::true_type{});

      /**
       * @brief Test function.
       * @tparam test_t
       * @return ::portable_stl::false_type
       */
      template<class test_t> static auto test(...) -> ::portable_stl::false_type;

    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::conjunction<
        ::portable_stl::negation<member_empty<t_type>>,
        ::portable_stl::negation<has_size<t_type>>,
        decltype(test<t_type>(0)),
        ::portable_stl::forward_iterator<decltype(::portable_stl::ranges::begin(::portable_stl::declval<t_type &>()))>>;
    };

    /**
     * @brief has_size implementation.
     * @tparam t_type Tested type.
     */
    template<class t_type> class can_compare_begin_end_impl<t_type, ::portable_stl::false_type> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };

    /**
     * @brief Helper to check if ranges::begin and ranges::end for t_type could be compared.
     * @tparam t_type Tested type.
     */
    template<class t_type>
    using can_compare_begin_end =
      typename ::portable_stl::ranges::empty_impl_helper::can_compare_begin_end_impl<t_type>::type;

    /**
     * @brief Empty functional object implemenation.
     */
    class empty_fn final {
    public:
      /**
       * @brief Implementation for t_type with .empty() member function.
       *
       * @tparam t_type Given type.
       * @param value Given value.
       * @return true if range is empty.
       */
      template<class t_type,
               ::portable_stl::
                 enable_if_bool_constant_t<::portable_stl::ranges::empty_impl_helper::member_empty<t_type>, void *>
               = nullptr>
      constexpr bool operator()(t_type &&value) const noexcept(noexcept(static_cast<bool>(value.empty()))) {
        return static_cast<bool>(value.empty());
      }

      /**
       * @brief Implementation if ranges::size for t_type could be invoked.
       *
       * @tparam t_type Given type.
       * @param value Given value.
       * @return true if range is empty.
       */
      template<
        class t_type,
        ::portable_stl::enable_if_bool_constant_t<::portable_stl::ranges::empty_impl_helper::has_size<t_type>, void *>
        = nullptr>
      constexpr bool operator()(t_type &&value) const noexcept(noexcept(::portable_stl::ranges::size(value))) {
        return 0U == ::portable_stl::ranges::size(value);
      }

      /**
       * @brief Implementation if ranges::begin and ranges::end for t_type could be compared.
       *
       * @tparam t_type Given type.
       * @param value Given value.
       * @return true if range is empty.
       */
      template<class t_type,
               ::portable_stl::enable_if_bool_constant_t<
                 ::portable_stl::ranges::empty_impl_helper::can_compare_begin_end<t_type>,
                 void *>
               = nullptr>
      constexpr bool operator()(t_type &&value) const noexcept(
        noexcept(static_cast<bool>(::portable_stl::ranges::begin(value) == ::portable_stl::ranges::end(value)))) {
        return ::portable_stl::ranges::begin(value) == ::portable_stl::ranges::end(value);
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
  } // namespace empty_impl_helper

  namespace {
    constexpr auto const &empty = empty_impl_helper::static_const_wrapper<empty_impl_helper::empty_fn>::value;
  } // namespace
} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_EMPTY_H */
