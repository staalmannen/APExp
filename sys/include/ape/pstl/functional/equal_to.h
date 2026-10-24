// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="equal_to.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_EQUAL_TO_H
#define PSTL_EQUAL_TO_H

#include "../utility/general/forward.h"

namespace portable_stl {
/**
 * @brief Function object for performing comparisons.
 * Unless specialised, invokes operator== on type t_type.
 * @tparam t_type the type of the argument.
 */
template<class t_type = void> class equal_to final {
  public:
  // typedef bool   __result_type; // used by valarray

  /**
   * @brief Checks whether first is equal to second.
   *
   * @param left the first value for compare.
   * @param right the second value for compare.
   * @return reuslt of comparsion.
   * @retval true if the first == second,
   * @retval false otherwise.
   */
  constexpr bool operator()(t_type const &left, t_type const &right) const {
    return left == right;
  }
};

/**
 * @brief Function object for performing comparisons void.
 */
template<> class equal_to<void> final {
  public:
  template<class t_type1, class t_type2>
  constexpr auto operator()(t_type1 &&left, t_type2 &&right) const noexcept(noexcept(
    ::portable_stl::forward<t_type1>(left) == ::portable_stl::forward<t_type2>(right))) -> decltype(::portable_stl::forward<t_type1>(left) == ::portable_stl::forward<t_type2>(right)) {
    return ::portable_stl::forward<t_type1>(left) == ::portable_stl::forward<t_type2>(right);
  }
  using is_transparent = void;
};

} // namespace portable_stl

#endif /* PSTL_EQUAL_TO_H */
