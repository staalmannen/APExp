// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="add_cv.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ADD_CV_H
#define PSTL_ADD_CV_H

#include "add_const.h"
#include "add_volatile.h"

namespace std {

/**
 * @brief Add any top-level const-qualifier and volatile-qualifier to t_value.
 *
 * @tparam t_value value for adding.
 */
template<class t_type> class add_cv final {
public:
  /**
   * @brief Result type.
   */
  using type = ::std::add_volatile_t<::std::add_const_t<t_type>>;
};

/**
 * @brief Add any top-level const-qualifier and volatile-qualifier to t_value.
 *
 * @tparam t_value value for adding.
 */
template<class t_type> using add_cv_t = typename ::std::add_cv<t_type>::type;

} // namespace std

#endif // PSTL_ADD_CV_H
