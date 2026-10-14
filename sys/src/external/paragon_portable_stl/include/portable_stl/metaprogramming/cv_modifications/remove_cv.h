// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="remove_cv.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_REMOVE_CV_H
#define PSTL_REMOVE_CV_H

#include "remove_const.h"
#include "remove_volatile.h"

namespace portable_stl {

/**
 * @brief Removing any top-level const-qualifier and volatile-qualifier from t_value.
 *
 * @tparam t_value value for cleaning.
 */
template<class t_value> class remove_cv final {
public:
  /**
   * @brief The type formed by removing any top-level const-qualifier and volatile-qualifier from t_value.
   */
  using type = ::portable_stl::remove_const_t<::portable_stl::remove_volatile_t<t_value>>;
};

/**
 * @brief Removing any top-level const-qualifier and volatile-qualifier from t_value.
 *
 * @tparam t_value value for cleaning.
 */
template<class t_value> using remove_cv_t = typename remove_cv<t_value>::type;

} // namespace portable_stl

#endif // PSTL_REMOVE_CV_H
