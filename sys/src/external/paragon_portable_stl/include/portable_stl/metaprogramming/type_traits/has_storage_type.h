// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="has_storage_type.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_HAS_STORAGE_TYPE_H
#define PSTL_HAS_STORAGE_TYPE_H

namespace portable_stl {

/**
 * @brief Used in reference_bit.
 *
 * @tparam t_type
 */
template<class t_type> class has_storage_type final {
public:
  /**
   * @brief Default result type.
   */
  using type = ::portable_stl::false_type;
};
} // namespace portable_stl

#endif // PSTL_HAS_STORAGE_TYPE_H
