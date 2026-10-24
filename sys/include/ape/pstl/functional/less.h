// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="less.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_LESS_H
#define PSTL_LESS_H

#include "../utility/general/forward.h"

namespace portable_stl {

/**
 * @brief Function object for performing comparisons.
 * The main template invokes operator< on type t_type.
 * @tparam t_type the type of arguments.
 */
template<class t_type = void> class less final {
public:
  /**
   * @brief The type of result value.
   */
  using result_type = bool;

  /**
   * @brief The type of first argument.
   */
  using first_argument_type = t_type;

  /**
   * @brief The type of second argument.
   */
  using second_argument_type = t_type;

  /**
   * @brief Checks whether the first argument is less than the second.
   * @param first the first value for compare.
   * @param second the second value for compare.
   * @return reuslt of comparsion.
   * @retval true if the first less than the second.
   * @retval true if the second less than the first.
   */
  constexpr inline result_type operator()(first_argument_type const &first, second_argument_type const &second) const
    noexcept(noexcept(first < second)) {
    return first < second;
  }
};

template<> class less<void> final {
public:
  template<class t_type1, class t_type2>
  auto operator()(t_type1 &&first, t_type2 &&second) const
    noexcept(noexcept(::portable_stl::forward<t_type1>(first) < ::portable_stl::forward<t_type2>(second)))
      -> decltype(::portable_stl::forward<t_type1>(first) < ::portable_stl::forward<t_type2>(second)) {
    return ::portable_stl::forward<t_type1>(first) < ::portable_stl::forward<t_type2>(second);
  }

  using is_transparent = void;
};
} // namespace portable_stl

#endif // PSTL_LESS_H
