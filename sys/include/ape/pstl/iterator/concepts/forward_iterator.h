// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="forward_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FORWARD_ITERATOR_H
#define PSTL_FORWARD_ITERATOR_H

#include "../../concepts/derived_from.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../forward_iterator_tag.h"
#include "incrementable.h"
#include "input_iterator.h"
#include "input_or_output_iterator.h"
#include "iter_concept.h"
#include "sentinel_for.h"

namespace portable_stl {

/**
 * @brief This 'concept' refines ::input_iterator by requiring that iterator_t also model incrementable (thereby
 * making it suitable for multi-pass algorithms), and guaranteeing that two iterators to the same range can be compared
 * against each other.
 *
 * @tparam iterator_t
 */
template<class iterator_t>
using forward_iterator = ::portable_stl::conjunction<
  ::portable_stl::input_iterator<iterator_t>,
  ::portable_stl::derived_from<iterator_helper::iter_concept<iterator_t>, ::portable_stl::forward_iterator_tag>,
  ::portable_stl::incrementable<iterator_t>,
  ::portable_stl::sentinel_for<iterator_t, iterator_t>>;
} // namespace portable_stl

#endif /* PSTL_FORWARD_ITERATOR_H */
