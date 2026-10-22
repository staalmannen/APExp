// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_comp.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_COMP_H
#define PSTL_TUPLE_COMP_H

#include "fwd_decl_tuple.h"

namespace portable_stl {
    
/**
 * @brief Lexicographically compares the values in the tuple
 *
 * @tparam t_types Left tuple types.
 * @tparam t_other_types Right tuple types.
 * @param lhv Left-hand value.
 * @param rhv Right-hand value.
 * @return true
 * @return false
 */
template<class... t_types, class... t_other_types>
constexpr bool operator==(tuple<t_types...> const &lhv, tuple<t_other_types...> const &rhv) {
  static_assert(sizeof...(t_types) == sizeof...(t_other_types),
                "Cannot compare tuples of different sizes (N4950 [tuple.rel]/2).");
  return lhv.equals(rhv);
}

/**
 * @brief Lexicographically compares the values in the tuple
 *
 * @tparam t_types Left tuple types.
 * @tparam t_other_types Right tuple types.
 * @param lhv Left-hand value.
 * @param rhv Right-hand value.
 * @return true
 * @return false
 */
template<class... t_types, class... t_other_types>
constexpr bool operator!=(tuple<t_types...> const &lhv, tuple<t_other_types...> const &rhv) {
  return !(lhv == rhv);
}

/**
 * @brief Lexicographically compares the values in the tuple
 *
 * @tparam t_types Left tuple types.
 * @tparam t_other_types Right tuple types.
 * @param lhv Left-hand value.
 * @param rhv Right-hand value.
 * @return true
 * @return false
 */
template<class... t_types, class... t_other_types>
constexpr bool operator<(tuple<t_types...> const &lhv, tuple<t_other_types...> const &rhv) {
  static_assert(sizeof...(t_types) == sizeof...(t_other_types), "Cannot compare tuples of different sizes.");
  return lhv.less(rhv);
}

/**
 * @brief Lexicographically compares the values in the tuple
 *
 * @tparam t_types Left tuple types.
 * @tparam t_other_types Right tuple types.
 * @param lhv Left-hand value.
 * @param rhv Right-hand value.
 * @return true
 * @return false
 */
template<class... t_types, class... t_other_types>
constexpr bool operator>=(tuple<t_types...> const &lhv, tuple<t_other_types...> const &rhv) {
  return !(lhv < rhv);
}

/**
 * @brief Lexicographically compares the values in the tuple
 *
 * @tparam t_types Left tuple types.
 * @tparam t_other_types Right tuple types.
 * @param lhv Left-hand value.
 * @param rhv Right-hand value.
 * @return true
 * @return false
 */
template<class... t_types, class... t_other_types>
constexpr bool operator>(tuple<t_types...> const &lhv, tuple<t_other_types...> const &rhv) {
  return rhv < lhv;
}

/**
 * @brief Lexicographically compares the values in the tuple
 *
 * @tparam ...t_types
 * @tparam ...t_other_types
 * @param lhv Left-hand value.
 * @param rhv Right-hand value.
 * @return
 */
template<class... t_types, class... t_other_types>
constexpr bool operator<=(tuple<t_types...> const &lhv, tuple<t_other_types...> const &rhv) {
  return !(rhv < lhv);
}
} // namespace portable_stl

#endif /* PSTL_TUPLE_COMP_H */
