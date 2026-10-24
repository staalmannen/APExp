// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="conditional.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CONDITIONAL_H
#define PSTL_CONDITIONAL_H

#include "../helper/integral_constant.h"

namespace portable_stl {
/**
 * @brief If t_conditional is true, the member typedef type denotes t_true. If t_conditional is false, the member
 * typedef type denotes t_false.
 * @tparam t_conditional The conditional.
 * @tparam t_true the type on true t_conditional.
 * @tparam t_false the type on false t_conditional.
 */
template<bool t_conditional, class t_true, class t_false> class conditional final {
public:
  /**
   * @brief The result type.
   */
  using type = t_true;
};

/**
 * @brief If t_conditional is true, the member typedef type denotes t_true. If t_conditional is false, the member
 * typedef type denotes t_false.
 * @tparam t_true the type on true t_conditional.
 * @tparam t_false the type on false t_conditional.
 */
template<class t_true, class t_false> class conditional<false, t_true, t_false> final {
public:
  /**
   * @brief The result type.
   */
  using type = t_false;
};

/**
 * @brief If t_conditional is true, the member typedef type denotes t_true. If t_conditional is false, the member
 * typedef type denotes t_false.
 * @tparam t_conditional The conditional.
 * @tparam t_true the type on true t_conditional.
 * @tparam t_false the type on false t_conditional.
 */
template<bool t_conditional, class t_true, class t_false>
using conditional_t = typename conditional<t_conditional, t_true, t_false>::type;

} // namespace portable_stl

#endif // PSTL_CONDITIONAL_H
