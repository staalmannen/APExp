// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="datasizeof.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_DATASIZEOF_H
#define PSTL_DATASIZEOF_H

#include "../../common/size_t.h"
#include "../logical_operator/disjunction.h"
#include "../logical_operator/negation.h"
#include "../primary_type/is_class.h"
#include "../type_properties/is_final.h"

namespace portable_stl {

namespace type_traits_helper {
  template<class t_type, class = ::portable_stl::disjunction<::portable_stl::is_final<t_type>,
                                               ::portable_stl::negation<::portable_stl::is_class<t_type>>>>
  struct first_padding_byte : t_type {
    char m_first_padding_byte;
  };

  template<class t_type> struct first_padding_byte<t_type, ::portable_stl::true_type> {
    t_type m_value;
    char   m_first_padding_byte;
  };
} // namespace type_traits_helper

template<class t_type> class datasizeof final {
public:
  // #if __has_cpp_attribute(__no_unique_address__)
  //   template<class = char> struct first_padding_byte {
  //     [[__no_unique_address__]] t_type m_value;
  //     char                             m_first_padding_byte;
  //   };
  // #else
  // #endif

  // _FirstPaddingByte<> is sometimes non-standard layout. Using `offsetof` is UB in that case, but GCC and Clang allow
  // the use as an extension.
  //   _LIBCPP_DIAGNOSTIC_PUSH
  //   _LIBCPP_CLANG_DIAGNOSTIC_IGNORED("-Winvalid-offsetof")
  static ::portable_stl::size_t const value = offsetof(type_traits_helper::first_padding_byte<t_type>, m_first_padding_byte);
  //   _LIBCPP_DIAGNOSTIC_POP
};

} // namespace portable_stl

#endif // PSTL_DATASIZEOF_H
