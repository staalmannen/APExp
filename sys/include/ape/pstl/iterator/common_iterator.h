// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="common_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COMMON_ITERATOR_H
#define PSTL_COMMON_ITERATOR_H

#include "../concepts/copyable.h"
#include "../concepts/same_as.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "concepts/input_or_output_iterator.h"
#include "concepts/sentinel_for.h"

namespace portable_stl {

/**
 * @brief Class template common_iterator is an iterator/sentinel adaptor that is capable of representing a non-common
 * range of elements (where the types of the iterator and sentinel differ) as a common range (where they are the same).
 * It does this by holding either an iterator or a sentinel, and implementing the equality comparison operators
 * appropriately.
 * The common_iterator type is useful for interfacing with legacy code that expects the begin and end of a range to have
 * the same type.
 *
 * @tparam iterator_t Iterator type.
 * @tparam sentinel_t Sentinel type.
 */
template<class iterator_t,
         class sentinel_t,
         class = ::portable_stl::enable_if_bool_constant_t<
           ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::same_as<iterator_t, sentinel_t>>,
                                       ::portable_stl::copyable<iterator_t>>>>
class common_iterator {
public:
};

} // namespace portable_stl

#endif /* PSTL_COMMON_ITERATOR_H */
