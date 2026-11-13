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

/*
 * THE TOKEN TYPE IS `type_info const *' AND NOT `type_info const &',
 * so that this arm and `../no_rtti/typeid_wrap.h' present the SAME
 * interface to `function.h' and that file needs no `#if' of its own.
 * A reference cannot serve: the no-RTTI arm has no `type_info' to
 * refer to, because `<typeinfo>' deliberately gives the class no
 * accessible constructor.
 *
 * `typeid_token_equal' compares the OBJECTS through `type_info's own
 * `operator==' rather than comparing the pointers, which is the whole
 * reason the two arms get a function instead of a bare `=='.  One
 * type may have more than one `type_info' object in a program, so
 * pointer equality would answer `false' for two names of one type --
 * the exact mistake this indirection exists to make impossible to
 * write.
 */
using typeid_token = ::std::type_info const *;

template<class t_type> class typeid_wrap final {
public:
  inline static typeid_token value() noexcept {
    return &typeid(t_type);
  }
};

inline bool typeid_token_equal(typeid_token lhs, typeid_token rhs) noexcept {
  return (lhs == rhs) || ((nullptr != lhs) && (nullptr != rhs) && (*lhs == *rhs));
}

} // namespace std

#endif // PSTL_TYPEID_WRAP_H
