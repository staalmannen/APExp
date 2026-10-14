// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="decay.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_DECAY_H
#define PSTL_DECAY_H

#include "../array_modifications/remove_extent.h"
#include "../cv_modifications/remove_cv.h"
#include "../pointer_modifications/add_pointer.h"
#include "../primary_type/is_array.h"
#include "../primary_type/is_function.h"
#include "../reference_modifications/remove_reference.h"
#include "conditional_bool_constant.h"

namespace portable_stl {
/**
 * @brief Applies type transformations as when passing a function argument by value.
 *
 * @tparam t_type The given type.
 */
template<class t_type> class decay final {
  /**
   * @brief The medium type.
   *
   */
  using remove_ref_type_t = ::portable_stl::remove_reference_t<t_type>;

public:
  /**
   * @brief The result of applying the decay type conversions to t_type.
   *
   */
  using type = ::portable_stl::conditional_bool_constant_t<
    ::portable_stl::is_array<remove_ref_type_t>,
    ::portable_stl::add_pointer_t<::portable_stl::remove_extent_t<remove_ref_type_t>>,
    ::portable_stl::conditional_bool_constant_t<::portable_stl::is_function<remove_ref_type_t>,
                                                ::portable_stl::add_pointer_t<remove_ref_type_t>,
                                                ::portable_stl::remove_cv_t<remove_ref_type_t>>>;
};

/**
 * @brief Applies type transformations as when passing a function argument by value.
 *
 * @tparam t_type The given type.
 */
template<class t_type> using decay_t = typename decay<t_type>::type;
} // namespace portable_stl

#endif // PSTL_DECAY_H
