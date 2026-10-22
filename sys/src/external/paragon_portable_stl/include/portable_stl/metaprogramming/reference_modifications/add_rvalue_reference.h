// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="add_rvalue_reference.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ADD_RVALUE_REFERENCE_H
#define PSTL_ADD_RVALUE_REFERENCE_H

#include "../type_properties/is_rvalue_referenceable.h"

namespace portable_stl {
/**
 * @brief If t_type is a referenceable type then the member typedef type denotes t_type&&; otherwise, type denotes
 * t_type.
 *
 * @tparam t_type The type for add reference.
 */
template<class t_type, class = ::portable_stl::is_rvalue_referenceable<t_type>> class add_rvalue_reference final {
public:
  /**
   * @brief The result.
   */
  using type = t_type;
};

/**
 * @brief If t_type is a referenceable type then the member typedef type denotes t_type&&; otherwise, type denotes
 * t_type.
 *
 * @tparam t_type The type for add reference.
 */
template<class t_type> class add_rvalue_reference<t_type, ::portable_stl::true_type> final {
public:
  /**
   * @brief The result.
   */
  using type = t_type &&;
};

/**
 * @brief If t_type is a referenceable type then the member typedef type denotes t_type&&; otherwise, type denotes
 * t_type.
 *
 * @tparam t_type The type for add reference.
 */
template<class t_type> using add_rvalue_reference_t = typename add_rvalue_reference<t_type>::type;

} // namespace portable_stl

#endif /* PSTL_ADD_RVALUE_REFERENCE_H */
