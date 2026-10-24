// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="string_view.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_STRING_VIEW_H
#define PSTL_STRING_VIEW_H

#include "basic_string_view.h"
#include "../common/char_t.h"
#include "../common/char8_t.h"

namespace portable_stl {
/**
 * @brief string_view specialization with char = char_t symbols.
 */
using string_view    = ::portable_stl::basic_string_view<::portable_stl::char_t>;

/**
 * @brief string_view specialization with wchar_t symbols.
 */
using wstring_view   = ::portable_stl::basic_string_view<wchar_t>;

/**
 * @brief string_view specialization with char8_t symbols.
 */
using u8string_view  = ::portable_stl::basic_string_view<::portable_stl::pstl_char8_t>;

/**
 * @brief string_view specialization with char16_t symbols.
 */
using u16string_view = ::portable_stl::basic_string_view<char16_t>;

/**
 * @brief string_view specialization with char32_t symbols.
 */
using u32string_view = ::portable_stl::basic_string_view<char32_t>;
} // namespace portable_stl

#endif // PSTL_STRING_VIEW_H
