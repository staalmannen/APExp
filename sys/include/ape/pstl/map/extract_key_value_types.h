// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="extract_key_value_types.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_EXTRACT_KEY_VALUE_TYPES_H
#define PSTL_EXTRACT_KEY_VALUE_TYPES_H

#include "../containers/value_type_impl.h"

namespace portable_stl {

template<class t_type> class extract_key_value_types;

template<class t_key, class t_type> class extract_key_value_types<::portable_stl::value_type_impl<t_key, t_type>> final {
public:
  using t_key_type    = t_key const;
  using t_mapped_type = t_type;
};

} // namespace portable_stl

#endif // PSTL_EXTRACT_KEY_VALUE_TYPES_H
