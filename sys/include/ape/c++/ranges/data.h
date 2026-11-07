// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="data.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_DATA_H
#define PSTL_DATA_H

#include "../common/size_t.h"
#include "../concepts/class_or_enum.h"
#include "../concepts/integral.h"
#include "../concepts/same_as.h"
#include "../iterator/concepts/bidirectional_iterator.h"
#include "../iterator/concepts/contiguous_iterator.h"
#include "../iterator/concepts/forward_iterator.h"
#include "../iterator/concepts/sentinel_for.h"
#include "../iterator/concepts/sized_sentinel_for.h"
#include "../memory/to_address.h"
#include "../metaprogramming/composite_type/is_object.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/decay.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/remove_cvref.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../metaprogramming/pointer_modifications/remove_pointer.h"
#include "../metaprogramming/primary_type/is_lvalue_reference.h"
#include "../metaprogramming/primary_type/is_pointer.h"
#include "../metaprogramming/reference_modifications/remove_reference.h"
#include "../metaprogramming/sign_modifications/make_unsigned.h"
#include "../metaprogramming/type_properties/is_bounded_array.h"
#include "../metaprogramming/type_property_queries/extent.h"
#include "../utility/general/declval.h"
#include "concepts/maybe_borrowed_range.h"

namespace std {
namespace ranges {
  namespace data_impl_helper {
    /**
     * @brief Helper 'concept'
     * @tparam t_type Given type.
     */
    template<class t_type>
    using ptr_to_object
      = ::std::conjunction<::std::is_pointer<t_type>,
                                    ::std::is_object<::std::remove_pointer_t<t_type>>>;

    /**
     * @brief Helper to check if t_type has data() member function.
     * @tparam t_type Tested type.
     */
    template<class t_type> class has_member_data_impl final {
      /**
       * @brief Test function.
       *
       * @tparam T1
       * @param t_value
       * @return ::std::true_type
       */
      template<class T1>
      static auto test(T1 &&t_value) -> decltype((::std::forward<T1>(t_value).data()),
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
     * @brief member_data_impl impl.
     * @tparam t_type Tested type.
     */
    template<class t_type, class = typename has_member_data_impl<t_type>::type> class member_data_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::std::conjunction<::std::ranges::maybe_borrowed_range<t_type>,
                                               ptr_to_object<decltype(::std::declval<t_type>().data())>>;
    };

    /**
     * @brief member_size_impl impl.
     * @tparam t_type Tested type.
     */
    template<class t_type> class member_data_impl<t_type, ::std::false_type> final {
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
    using member_data = typename ::std::ranges::data_impl_helper::member_data_impl<t_type>::type;

    /*

    template <class _Tp>
    concept __ranges_begin_invocable = !__member_data<_Tp> && __can_borrow<_Tp> && requires(_Tp&& __t) {
      { ranges::begin(__t) } -> contiguous_iterator;
    };

    */

    /**
     * @brief Helper to check if ranges::begin can be invoked for t_type.
     * @tparam t_type Tested type.
     */
    template<class t_type> class has_ranges_begin final {
      /**
       * @brief Test function.
       *
       * @tparam T1
       * @param t_value
       * @return ::std::true_type
       */
      template<class T1>
      static auto test(T1 &&t_value) -> decltype(::std::ranges::begin(::std::forward<T1>(t_value)),
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
     * @brief member_data_impl impl.
     * @tparam t_type Tested type.
     */
    template<class t_type, class = typename has_ranges_begin<t_type>::type> class ranges_begin_invocable_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type
        = ::std::conjunction<::std::negation<member_data<t_type>>,
                                      ::std::ranges::maybe_borrowed_range<t_type>,
                                      ::std::contiguous_iterator<decltype(::std::ranges::begin(
                                        ::std::declval<t_type>()))>>;
    };

    /**
     * @brief member_size_impl impl.
     * @tparam t_type Tested type.
     */
    template<class t_type> class ranges_begin_invocable_impl<t_type, ::std::false_type> final {
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
    using ranges_begin_invocable =
      typename ::std::ranges::data_impl_helper::ranges_begin_invocable_impl<t_type>::type;

    /**
     * @brief Size functional object implemenation.
     */
    class data_fn final {
    public:
      /**
       * @brief data implementation.
       * Has ::data() member function.
       * @tparam t_type Given type.
       * @param value
       * @return constexpr auto
       */
      template<class t_type, ::std::enable_if_bool_constant_t<member_data<t_type>, void *> = nullptr>
      constexpr auto operator()(t_type &&value) const noexcept(noexcept(value.data())) {
        return value.data();
      }

      /**
       * @brief data implementation.
       * ::to_address could be evaluated.
       * @tparam t_type Given type.
       * @param value
       * @return constexpr auto
       */
      template<class t_type,
               ::std::enable_if_bool_constant_t<ranges_begin_invocable<t_type>, void *> = nullptr>
      constexpr auto operator()(t_type &&value) const
        noexcept(noexcept(::std::to_address(::std::ranges::begin(value)))) {
        return ::std::to_address(::std::ranges::begin(value));
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
  } // namespace data_impl_helper

  namespace {
    constexpr auto const &data = data_impl_helper::static_const_wrapper<data_impl_helper::data_fn>::value;
  } // namespace
} // namespace ranges
} // namespace std

#endif /* PSTL_DATA_H */
