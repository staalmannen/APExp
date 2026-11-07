// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="class_or_enum.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CLASS_OR_ENUM_H
#define PSTL_CLASS_OR_ENUM_H
#include "../metaprogramming/logical_operator/disjunction.h"
#include "../metaprogramming/primary_type/is_class.h"
#include "../metaprogramming/primary_type/is_enum.h"
#include "../metaprogramming/primary_type/is_union.h"
namespace std {
/**
 * @brief Helper to check if t_type is a class or union or enum.
 * @tparam t_type Tested type.
 */
template<class t_type>
using class_or_enum = ::std::
  disjunction<::std::is_class<t_type>, ::std::is_union<t_type>, ::std::is_enum<t_type>>;

} // namespace std

#endif /* PSTL_CLASS_OR_ENUM_H */
