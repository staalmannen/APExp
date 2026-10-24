// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="string.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef STRING_H
#define STRING_H

#include "basic_string.h"
#include "../common/char_t.h"
#include "../common/char8_t.h"

namespace portable_stl {

// there are no explicit specializations of char_traits at now.
/**
 * @brief Explicit forward declaration of the specialization for char=char_t symbols.
 */
template<> class char_traits<::portable_stl::char_t>;

/**
 * @brief Explicit forward declaration of the specialization for wchar_t symbols.
 */
template<> class char_traits<wchar_t>;

// /**
//  * @brief Explicit forward declaration of the specialization for pstl_char8_t symbols.
//  */
// template<> class char_traits<pstl_char8_t>;

// /**
//  * @brief Explicit forward declaration of the specialization for char16_t symbols.
//  */
// template<> class char_traits<char16_t>;

// /**
//  * @brief Explicit forward declaration of the specialization for char32_t symbols.
//  */
// template<> class char_traits<char32_t>;

/**
 * @brief string specialization with char=char_t symbols.
 */
using string  = ::portable_stl::basic_string<::portable_stl::char_t, ::portable_stl::char_traits<::portable_stl::char_t>, allocator<::portable_stl::char_t>>;

/**
 * @brief string specialization with wchar_t symbols.
 */
using wstring = ::portable_stl::basic_string<wchar_t, ::portable_stl::char_traits<wchar_t>, allocator<wchar_t>>;

/**
 * @brief string specialization with pstl_char8_t symbols.
 */
using u8string = ::portable_stl::basic_string<::portable_stl::pstl_char8_t, ::portable_stl::char_traits<::portable_stl::pstl_char8_t>, allocator<::portable_stl::pstl_char8_t>>;

/**
 * @brief string specialization with char16_t symbols.
 */
using u16string = ::portable_stl::basic_string<char16_t, ::portable_stl::char_traits<char16_t>, allocator<char16_t>>;

/**
 * @brief string specialization with char32_t symbols.
 */
using u32string = ::portable_stl::basic_string<char32_t, ::portable_stl::char_traits<char32_t>, allocator<char32_t>>;

} // namespace portable_stl

#endif // STRING_H
