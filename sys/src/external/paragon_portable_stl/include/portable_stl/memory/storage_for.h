// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="storage_for.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_STORAGE_FOR_H
#define PSTL_STORAGE_FOR_H

#include "voidify.h"

namespace portable_stl {

/**
 * @brief Use the source storage for save the t_type_target object.
 * @tparam t_type_source the type of source storage.
 * @tparam t_type_target the type for saved object.
 * @param source the source storage.
 * @return reference to the place for save t_type_target object.
 */
template<class t_type_target, class t_type_source>
constexpr inline static t_type_target &storage_for(t_type_source &source) noexcept {
  return *(static_cast<t_type_target *>(::portable_stl::voidify(source)));
}

} // namespace portable_stl

#endif // PSTL_STORAGE_FOR_H
