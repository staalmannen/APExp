// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="begin.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BEGIN_H
#define PSTL_BEGIN_H

#include "../concepts/class_or_enum.h"
#include "../iterator/concepts/input_or_output_iterator.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/decay.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/remove_cvref.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../metaprogramming/primary_type/is_lvalue_reference.h"
#include "../utility/general/declval.h"
#include "concepts/maybe_borrowed_range.h"

namespace portable_stl {
namespace ranges {

  namespace begin_impl_helper {
    /**
     * @brief Helper to check if t_type has begin() member function.
     * Primary template.
     */
    template<class, class = void> class member_begin_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };

    /**
     * @brief Helper to check if t_type has begin() member function.
     * @tparam t_type Tested type.
     */
    template<class t_type>
    class member_begin_impl<t_type, ::portable_stl::void_t<decltype(::portable_stl::declval<t_type>().begin())>> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::conjunction<
        ::portable_stl::ranges::maybe_borrowed_range<t_type>,
        ::portable_stl::input_or_output_iterator<decltype(::portable_stl::declval<t_type>().begin())>>;
    };

    /**
     * @brief Helper to check if t_type has begin() member function.
     * @tparam t_type Tested type.
     */
    template<class t_type>
    using member_begin = typename ::portable_stl::ranges::begin_impl_helper::member_begin_impl<t_type>::type;

    /**
     * @brief Poison pill: Do not search in this scope?
     */

    // ifdef _clang_
    //  void                        begin()               = delete;
    //  template<class t_type> void begin(t_type &)       = delete;
    //  template<class t_type> void begin(t_type const &) = delete;

    // ifdef _msvc_
    /**
     * @brief Poison pill: Do not search in this scope?
     */
    void                        begin();
    /**
     * @brief Poison pill: Do not search in this scope?
     */
    template<class t_type> void begin(t_type &);
    /**
     * @brief Poison pill: Do not search in this scope?
     */
    template<class t_type> void begin(t_type const &);

    /**
     * @brief Helper to check if t_type could be passed into begin() somehow.
     * @tparam t_type Given type.
     */
    template<class t_type> class has_adl_begin_impl final {
      /**
       * @brief Test function.
       *
       * @tparam T1
       * @param t_value
       * @return ::portable_stl::true_type
       */
      template<class T1>
      static auto test(T1 &&t_value)
        -> decltype(begin(::portable_stl::forward<T1>(t_value)), ::portable_stl::true_type{});

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
    template<class t_type, class = typename has_adl_begin_impl<t_type>::type> class unqualified_begin_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::conjunction<
        ::portable_stl::negation<member_begin<t_type>>,
        ::portable_stl::ranges::maybe_borrowed_range<t_type>,
        ::portable_stl::class_or_enum<::portable_stl::remove_cvref_t<t_type>>,
        ::portable_stl::input_or_output_iterator<decltype(begin(::portable_stl::declval<t_type>()))>>;
    };

    /**
     * @brief Check other properties to call begin() for given t_type.
     * @tparam t_type Given type.
     */
    template<class t_type> class unqualified_begin_impl<t_type, ::portable_stl::false_type> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };

    /**
     * @brief Helper to check if t_type could be passed into begin() somehow. And its result is an
     * input_or_output_iterator.
     * @tparam t_type Tested type.
     */
    template<class t_type>
    using unqualified_begin = typename ::portable_stl::ranges::begin_impl_helper::unqualified_begin_impl<t_type>::type;

    /**
     * @brief Begin functional object implemenation.
     */
    class begin_fn final {
    public:
      /**
       * @brief Returns an iterator to the beginning of a range.
       * Array with unknown size.
       * @tparam t_type Type of range.
       * @param array Given array.
       * @return an iterator to the beginning.
       */
      template<class t_type> constexpr auto operator()(t_type (&array)[]) const noexcept {
        // static _ assert ( sizeof ( array ) >= 0 , " Disallow incomplete element types " );
        return array + 0;
      }

      /**
       * @brief Returns an iterator to the beginning of a range.
       * Array with known size.
       * @tparam t_type Type of range.
       * @param array Given array.
       * @return an iterator to the beginning.
       */
      template<class t_type, size_t arr_size> constexpr auto operator()(t_type (&array)[arr_size]) const noexcept {
        // static _ assert ( sizeof ( array ) >= 0 , " Disallow incomplete element types " );
        return array + 0;
      }

      /**
       * @brief Returns an iterator to the beginning of a range.
       * Value has begin() member function.
       * @tparam t_type Type of range.
       * @param value Given range/container.
       * @return an iterator to the beginning.
       */
      template<class t_type,
               ::portable_stl::
                 enable_if_bool_constant_t<::portable_stl::ranges::begin_impl_helper::member_begin<t_type>, void *>
               = nullptr>
      constexpr auto operator()(t_type &&value) const
        noexcept(noexcept(static_cast<::portable_stl::decay_t<decltype((value.begin()))>>(value.begin()))) {
        return static_cast<::portable_stl::decay_t<decltype((value.begin()))>>(value.begin());
      }

      /**
       * @brief Returns an iterator to the beginning of a range.
       * Value could be passed into begin() function.
       * @tparam t_type Type of range.
       * @param value Given range/container.
       * @return an iterator to the beginning.
       */
      template<class t_type,
               ::portable_stl::
                 enable_if_bool_constant_t<::portable_stl::ranges::begin_impl_helper::unqualified_begin<t_type>, void *>
               = nullptr>
      constexpr auto operator()(t_type &&value) const
        noexcept(noexcept(static_cast<::portable_stl::decay_t<decltype((begin(value)))>>(begin(value)))) {
        return static_cast<::portable_stl::decay_t<decltype((begin(value)))>>(begin(value));
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
  } // namespace begin_impl_helper

  namespace {
    constexpr auto const &begin = begin_impl_helper::static_const_wrapper<begin_impl_helper::begin_fn>::value;
  } // namespace

} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_BEGIN_H */
