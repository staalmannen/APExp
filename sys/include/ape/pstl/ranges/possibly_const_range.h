// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="possibly_const_range.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_POSSIBLY_CONST_RANGE_H
#define PSTL_POSSIBLY_CONST_RANGE_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "concepts/constant_range.h"
#include "concepts/input_range.h"

namespace portable_stl {
namespace ranges {
  namespace ranges_helper {

    /**
     * @brief possibly_const_range condition.
     * @tparam t_type Given range type.
     */
    template<class t_type>
    using possibly_const_range_cond
      = ::portable_stl::conjunction<::portable_stl::ranges::constant_range<t_type const>,
                                    ::portable_stl::negation<::portable_stl::ranges::constant_range<t_type>>>;

/**
 * @brief possibly_const_range inplementation.
 * @tparam t_type Type of given range.
 * @param value Given range.
 * @return const range.
 */
    template<class t_type>
    constexpr auto &possibly_const_range(
      t_type &value,
      ::portable_stl::enable_if_bool_constant_t<
        ::portable_stl::conjunction<::portable_stl::ranges::input_range<t_type>, possibly_const_range_cond<t_type>>,
        void *>
      = nullptr) noexcept {
      return const_cast<t_type const &>(value);
    }

/**
 * @brief possibly_const_range inplementation.
 * 
 * @tparam t_type Type of given range.
 * @param value Given range.
 * @return range as is.
 */
    template<class t_type>
    constexpr auto &possibly_const_range(
      t_type &value,
      ::portable_stl::enable_if_bool_constant_t<
        ::portable_stl::conjunction<::portable_stl::ranges::input_range<t_type>,
                                    ::portable_stl::negation<possibly_const_range_cond<t_type>>>,
        void *>
      = nullptr) noexcept {
      return value;
    }
  } // namespace ranges_helper
} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_POSSIBLY_CONST_RANGE_H */
