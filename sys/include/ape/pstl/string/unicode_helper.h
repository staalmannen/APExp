// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="unicode_helper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_UNICODE_HELPER_H
#define PSTL_UNICODE_HELPER_H

#include "../error/portable_stl_error.h"
#include "../utility/expected/expected.h"

namespace portable_stl {

template<typename t_char_type> class unicode_helper {
public:
  template<class t_iterator>
  static ::portable_stl::expected<char32_t, ::portable_stl::portable_stl_error> toUTF32(t_iterator       &it,
                                                                                        t_iterator const &it_end);

  template<class t_iterator> static bool fromUTF32(t_iterator &it, char32_t const source) noexcept;

  static ::portable_stl::size_t symbol_size(t_char_type const current) noexcept;

  static ::portable_stl::size_t sequence_size(char32_t const source) noexcept;
};

} // namespace portable_stl

#endif // PSTL_UNICODE_HELPER_H
