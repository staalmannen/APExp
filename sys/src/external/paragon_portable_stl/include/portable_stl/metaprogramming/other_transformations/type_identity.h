// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="type_identity.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TYPE_IDENTITY_H
#define PSTL_TYPE_IDENTITY_H

namespace portable_stl {

/**
 * @brief The member typedef type denotes t_type. Can be used to establish non-deduced contexts in template argument
 * deduction.
 *
 * @tparam t_type the type for deduct.
 */
template<class t_type> class type_identity final {
public:
  /**
   * @brief Result type.
   */
  using type = t_type;
};

/**
 * @brief The member typedef type denotes t_type. Can be used to establish non-deduced contexts in template argument
 * deduction.
 *
 * @tparam t_type the type for deduct.
 */
template<class t_type> using type_identity_t = typename type_identity<t_type>::type;

} // namespace portable_stl

#endif // PSTL_TYPE_IDENTITY_H
