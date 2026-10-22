// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="operation_traits.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_OPERATION_TRAITS_H
#define PSTL_OPERATION_TRAITS_H

#include "../helper/integral_constant.h"
namespace portable_stl {

/**
 * @brief Tag to represent the canonical operation.
 */
struct equal_tag {};
/**
 * @brief Tag to represent the canonical operation.
 */
struct plus_tag {};

/**
 * @brief This class template is used to determine whether an operation "desugars" (or boils down) to a given canonical
 * operation.
 *
 * For example, '::equal_to<>', our internal '::equal_to' helper and 'ranges::equal_to' are all just fancy ways
 * of representing a transparent equality operation, so they all desugar to 'equal_tag'.
 *
 * This is useful to optimize some functions in cases where we know e.g. the predicate being passed is actually going to
 * call a builtin operator, or has some specific semantics.
 * @tparam t_canonical_tag
 * @tparam t_operation
 * @tparam t_args
 */
template<class t_canonical_tag, class t_operation, class... t_args> class desugars_to final {
public:
  using type = portable_stl::false_type;
};

} // namespace portable_stl

#endif // PSTL_OPERATION_TRAITS_H
