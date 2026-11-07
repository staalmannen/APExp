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

namespace std {

template<class t_type> class typeid_wrap final {
public:
  inline static ::std::type_info const &value() {
    return typeid(t_type);
  }
};
} // namespace std

#endif // PSTL_TYPEID_WRAP_H
