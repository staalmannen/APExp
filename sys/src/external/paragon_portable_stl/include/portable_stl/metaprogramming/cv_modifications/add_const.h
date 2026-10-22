// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="add_const.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ADD_CONST_H
#define PSTL_ADD_CONST_H

namespace portable_stl {

/**
 * @brief Add top-level const-qualifier to t_value.
 *
 * @tparam t_value value for adding.
 */
template<class t_type> class add_const final {
public:
  /**
   * @brief Result type.
   */
  using type = t_type const;
};

/**
 * @brief Add top-level const-qualifier to t_value.
 *
 * @tparam t_value value for adding.
 */
template<class t_type> using add_const_t = typename ::portable_stl::add_const<t_type>::type;

} // namespace portable_stl

#endif // PSTL_ADD_CONST_H
