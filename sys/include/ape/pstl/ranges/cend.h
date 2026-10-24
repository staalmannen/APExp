// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="cend.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CEND_H
#define PSTL_CEND_H

#include "../iterator/basic_const_iterator.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../utility/general/declval.h"
#include "concepts/maybe_borrowed_range.h"
#include "end.h"
#include "possibly_const_range.h"

namespace portable_stl {
namespace ranges {

  namespace cend_impl_helper {
    /**
     * @brief end functional object implemenation.
     */
    class cend_fn final {
      /**
       * @brief Result type of applying end at constant variant of given range.
       * @tparam t_type Given range type.
       */
      template<class t_type>
      using end_on_const = decltype(::portable_stl::ranges::end(
        ::portable_stl::ranges::ranges_helper::possibly_const_range(::portable_stl::declval<t_type &>())));

    public:
      /**
       * @brief cend implementation.
       * @tparam t_type
       * @param value Given range.
       * @return
       */
      template<class t_type,
               ::portable_stl::enable_if_bool_constant_t<::portable_stl::ranges::maybe_borrowed_range<t_type>, void *>
               = nullptr,
               ::portable_stl::void_t<
                 end_on_const<t_type>,
                 ::portable_stl::const_sentinel<end_on_const<t_type>>,
                 decltype(::portable_stl::const_sentinel<end_on_const<t_type>>{::portable_stl::ranges::end(
                   ::portable_stl::ranges::ranges_helper::possibly_const_range(::portable_stl::declval<t_type &>()))})>
                 * = nullptr>
      constexpr auto operator()(t_type &&value) const
        noexcept(noexcept(::portable_stl::const_sentinel<end_on_const<t_type>>{
          ::portable_stl::ranges::end(::portable_stl::ranges::ranges_helper::possibly_const_range(value))})) {
        return ::portable_stl::const_sentinel<end_on_const<t_type>>{
          ::portable_stl::ranges::end(::portable_stl::ranges::ranges_helper::possibly_const_range(value))};
      }
    };

    /**
     * Customization Point Design in C++11 and Beyond from
     * https://ericniebler.com/2014/10/21/customization-point-design-in-c11-and-beyond/
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
  } // namespace cend_impl_helper

  namespace {
    /**
     * @brief Returns a sentinel for the constant iterator indicating the end of a range.
     *
     */
    constexpr auto const &cend = cend_impl_helper::static_const_wrapper<cend_impl_helper::cend_fn>::value;
  } // namespace

} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_CEND_H */
