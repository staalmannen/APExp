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

namespace std {

/*
 * ***THIS FILE USED TO CALL `typeid' AND IT IS THE NO-RTTI ARM.***  Its
 * own comment said "RTTI is disabled so, lval is empty" and its body
 * was `return typeid(void);', which `-fno-rtti' refuses outright --
 * and `func::target' is a PURE VIRTUAL (`function.h:199'), so the call
 * is instantiated for every `std::function' that exists rather than
 * only for one that asks for its target.  `<functional>' therefore
 * could not compile at all without RTTI, which is `rc/bin/ape/eccp''s
 * default and the only configuration this port has exercised.
 *
 * `std::type_info' cannot be manufactured here -- `<typeinfo>' gives
 * it no accessible constructor, by design -- so the ARM CANNOT RETURN
 * ONE, and the fix is to stop asking it to.  The only thing
 * `function.h' ever does with the result is compare it for equality,
 * so what it needs is a TOKEN that is distinct per type, not a
 * `type_info'.
 *
 * The address of a per-instantiation object is that token, and it
 * works where RTTI does not.  `--instantiate local' gives each
 * translation unit its own copy of a template's statics (see
 * `rc/bin/ape/eccp' note 5), so **a token minted in one translation
 * unit does not compare equal to the same type's token in another**.
 * That is a real limit and it is the same one `--instantiate local'
 * already imposes on every other template static in this port; within
 * one translation unit, which is what `function::target<T>()' is for,
 * it is exact.
 */
using typeid_token = void const *;

template<class t_type> class typeid_wrap final {
  static char const m_tag;

public:
  static inline typeid_token value() noexcept {
    return static_cast<typeid_token>(&m_tag);
  }
};

template<class t_type> char const typeid_wrap<t_type>::m_tag = 0;

inline bool typeid_token_equal(typeid_token lhs, typeid_token rhs) noexcept {
  return lhs == rhs;
}

} // namespace std

#endif // PSTL_TYPEID_WRAP_H
