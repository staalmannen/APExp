// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="sentinel_for.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SENTINEL_FOR_H
#define PSTL_SENTINEL_FOR_H

#include "../../concepts/semiregular.h"
#include "../../concepts/weakly_equality_comparable_with.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "input_or_output_iterator.h"

namespace portable_stl {
/**
 * @brief The sentinel_for 'concept' specifies the relationship between an input_or_output_iterator type and a
 * semiregular type whose values denote a range.
 *
 * Let s and i be values of type sentinel_t and iterator_t, respectively, such that [i, s) denotes a range.
 * sentinel_for<sentinel_t, iterator_t> is modeled only if:
 *
 * i == s is well-defined.
 * If bool(i != s) then i is dereferenceable and [++i, s) denotes a range.
 * assignable_from<iterator_t&, sentinel_t> is either modeled or not satisfied.
 * The domain of == can change over time. Given an iterator i and sentinel s such that [i, s) denotes a range and i !=
 * s, [i, s) is not required to continue to denote a range after incrementing any iterator equal to i (and so i == s is
 * no longer required to be well-defined after such an increment).
 *
 * @tparam sentinel_t Given type.
 * @tparam iterator_t Given iterator type.
 */
template<class sentinel_t, class iterator_t>
using sentinel_for = ::portable_stl::conjunction<::portable_stl::semiregular<sentinel_t>,
                                                 ::portable_stl::input_or_output_iterator<iterator_t>,
                                                 ::portable_stl::weakly_equality_comparable_with<sentinel_t, iterator_t>>;
} // namespace portable_stl

#endif /* PSTL_SENTINEL_FOR_H */
