// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="allocation_result.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ALLOCATION_RESULT_H
#define PSTL_ALLOCATION_RESULT_H

#include "../common/size_t.h"

namespace portable_stl {

/**
 * @brief Records the address and the actual size of storage allocated by allocate_at_least.
 *
 * @tparam t_pointer_type
 * @tparam t_size_type
 */
template<class t_pointer_type, class t_size_type = ::portable_stl::size_t> struct allocation_result final {
  /**
   * @brief a pointer of type t_pointer_type which is typically used for the address of the first element in the storage
   * allocated by allocate_at_least.
   */
  t_pointer_type ptr;
  /**
   * @brief a value of type t_size_type which is typically used for the actual number of elements in the storage
   * allocated by allocate_at_least.
   *
   */
  t_size_type    count;
};

} // namespace portable_stl

#endif // PSTL_ALLOCATION_RESULT_H
