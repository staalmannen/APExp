// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="addressof.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ADDRESSOF_H
#define PSTL_ADDRESSOF_H

#include "../common/compiler_builtins.h"
namespace std {

/**
 * @brief The actual address of the object or function referenced by value, even in the presence of an overloaded
 * operator&.
 *
 * @tparam t_type the type of value.
 * @param value value for get address.
 * @return actual address of the object.
 */
#if PSTL_HAS_BUILTIN(__builtin_addressof) || PSTL_HAS_GNU_BUILTINS

template<class t_type> constexpr t_type *addressof(t_type &value) noexcept {
  static_cast<void>(value);
  return __builtin_addressof(value);
}

#else

/*
 * ***THE PORTABLE `addressof' AND WHY IT IS NOT A SELECTOR FILE.***
 * Every other builtin in this library sits behind a `builtin/' vs
 * `generic/' pair; this one had NO guard and no sibling at all, so
 * cpfe answered `identifier "__builtin_addressof" is undefined' and
 * took `<functional>', `<memory>', `<string>' and `<vector>' with it.
 *
 * The three casts are the pre-C++17 idiom and are what the builtin
 * exists to replace: `reinterpret_cast' to `const volatile char &'
 * defeats any overloaded `operator&', `const_cast' takes the
 * qualifiers back off, and the last cast restores the type.
 *
 * `constexpr' IS KEPT and that is deliberate rather than careless.
 * `reinterpret_cast' can never appear in a core constant expression,
 * so by [dcl.constexpr]/5 no invocation of this can be constant and
 * the program is ill-formed NO DIAGNOSTIC REQUIRED -- which is what
 * every standard library did before the builtin existed, and neither
 * g++ nor cpfe diagnoses it.  **Dropping `constexpr' would be worse,
 * not better**: it would make every `constexpr' CALLER of `addressof'
 * ill-formed in turn, a cascade through `function.h' and the
 * iterators, where the present shape costs nothing until somebody
 * actually asks for a constant.
 */
template<class t_type> constexpr t_type *addressof(t_type &value) noexcept {
  return reinterpret_cast<t_type *>(
    &const_cast<char &>(reinterpret_cast<char const volatile &>(value)));
}

#endif

} // namespace std

#endif // PSTL_ADDRESSOF_H
