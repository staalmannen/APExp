// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="remove_volatile.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_REMOVE_VOLATILE_H
#define PSTL_REMOVE_VOLATILE_H

namespace portable_stl {

/**
 * @brief Removing any top-level volatile-qualifier from t_value.
 *
 * @tparam t_value value for cleaning.
 */
template<class t_value> class remove_volatile final {
public:
  /**
   * @brief The type formed by removing any top-level volatile-qualifier from t_value.
   */
  using type = t_value;
};

/**
 * @brief Removing any top-level volatile-qualifier from t_value.
 *
 * @tparam t_value value for cleaning.
 */
template<class t_value> class remove_volatile<t_value volatile> final {
public:
  /**
   * @brief The type formed by removing any top-level volatile-qualifier from t_value.
   */
  using type = t_value;
};

/**
 * @brief Removing any top-level volatile-qualifier from t_value.
 *
 * @tparam t_value value for cleaning.
 */
template<class t_value> using remove_volatile_t = typename remove_volatile<t_value>::type;

} // namespace portable_stl

#endif // PSTL_REMOVE_VOLATILE_H
