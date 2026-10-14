// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="add_volatile.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ADD_VOLATILE_H
#define PSTL_ADD_VOLATILE_H

namespace portable_stl {

/**
 * @brief Add top-level volatile-qualifier to t_value.
 *
 * @tparam t_value value for adding.
 */
template<class t_type> class add_volatile final {
public:
  /**
   * @brief Result type.
   */
  using type = t_type volatile;
};

/**
 * @brief Add top-level volatile-qualifier to t_value.
 *
 * @tparam t_value value for adding.
 */
template<class t_type> using add_volatile_t = typename ::portable_stl::add_volatile<t_type>::type;

} // namespace portable_stl

#endif // PSTL_ADD_VOLATILE_H
