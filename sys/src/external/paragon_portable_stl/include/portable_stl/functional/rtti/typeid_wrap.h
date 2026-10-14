// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="typeid_wrap.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TYPEID_WRAP_H
#define PSTL_TYPEID_WRAP_H

#include "../../language_support/typeinfo/type_info.h"

namespace portable_stl {

template<class t_type> class typeid_wrap final {
public:
  inline static ::portable_stl::type_info const &value() {
    static ::portable_stl::type_info ref(typeid(t_type));
    return ref;
  }
};
} // namespace portable_stl

#endif // PSTL_TYPEID_WRAP_H
