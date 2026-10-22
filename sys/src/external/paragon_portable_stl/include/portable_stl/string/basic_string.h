// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BASIC_STRING_H
#define PSTL_BASIC_STRING_H

#include "../algorithm/remove.h"
#include "../algorithm/remove_if.h"
#include "../common/char8_t.h"
#include "../common/cstdint.h"
#include "../error/portable_stl_error.h"
#include "../iterator/concepts/cpp17_input_iterator.h"
#include "../iterator/distance.h"
#include "../iterator/input_iterator_tag.h"
#include "../iterator/wrap_iter.h"
#include "../language_support/bad_alloc.h"
#include "../language_support/initializer_list.h"
#include "../memory/allocator.h"
#include "../memory/allocator_traits.h"
#include "../memory/to_address.h"
#include "../metaprogramming/cv_modifications/is_same_uncvref.h"
#include "../metaprogramming/type_properties/is_default_constructible.h"
#include "../metaprogramming/type_relations/is_convertible.h"
#include "../metaprogramming/type_relations/is_nothrow_convertible.h"
#include "../utility/expected/expected.h"
#include "../utility/expected/unexpected.h"
#include "../utility/general/functional/reference_wrapper.h"
#include "basic_string_view.h"
#include "char_traits.h"
#include "short_object_optimization.h"

#if defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  include "../language_support/exception/throw_on_true.h"
#else
#  include "../language_support/no_exception/throw_on_true.h"
#endif


namespace portable_stl {

namespace string_helper {
  template<class t_type> struct has_iterator_category {
  private:
    template<class t_type1> static ::portable_stl::false_type test(...);
    template<class t_type1> static ::portable_stl::true_type  test(typename t_type1::iterator_category  * = nullptr);

  public:
    /**
     * @brief Result type.
     */
    using type = decltype(test<t_type>(nullptr));
  };

  template<class t_type,
           class t_other_type,
           class = typename has_iterator_category<::portable_stl::iterator_traits<t_type>>::type>
  class has_iterator_category_convertible_to final {
  public:
    /**
     * @brief Result type.
     */
    using type = is_convertible<typename iterator_traits<t_type>::iterator_category, t_other_type>;
  };

  template<class t_type, class t_other_type>
  class has_iterator_category_convertible_to<t_type, t_other_type, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };
} // namespace string_helper

/**
 * @brief The class template basic_string stores and manipulates sequences of character-like objects, which are
 * non-array objects of TrivialType and StandardLayoutType. The class is dependent neither on the character type nor on
 * the nature of operations on that type. The definitions of the operations are supplied via the t_char_traits template
 * parameter - a specialization of portable_stl::char_traits or a compatible traits class.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 */
template<class t_char_type,
         class t_char_traits = ::portable_stl::char_traits<t_char_type>,
         class t_allocator   = ::portable_stl::allocator<t_char_type>>
class basic_string final {
public:
  /**
   * @brief Current class type.
   *
   */
  using type            = basic_string;
  /**
   * @brief Class specifying the operations on the character type.
   *
   */
  using traits_type     = t_char_traits;
  /**
   * @brief Character type.
   *
   */
  using value_type      = t_char_type;
  /**
   * @brief Allocator type.
   *
   */
  using allocator_type  = t_allocator;
  /**
   * @brief Type for size of contiguous sequence of char-like objects.
   *
   */
  using size_type       = typename ::portable_stl::allocator_traits<t_allocator>::size_type;
  /**
   * @brief Type for distance between positions in contiguous sequence of char-like objects.
   *
   */
  using difference_type = typename ::portable_stl::allocator_traits<t_allocator>::difference_type;
  /**
   * @brief Pointer to contiguous sequence of char-like objects.
   *
   */
  using pointer         = typename ::portable_stl::allocator_traits<t_allocator>::pointer;
  /**
   * @brief Constant pointer to contiguous sequence of char-like objects.
   *
   */
  using const_pointer   = typename ::portable_stl::allocator_traits<t_allocator>::const_pointer;
  /**
   * @brief Reference to element of contiguous sequence of char-like objects.
   *
   */
  using reference       = value_type &;
  /**
   * @brief Constant reference to element of contiguous sequence of char-like objects.
   *
   */
  using const_reference = value_type const &;

  /**
   * @brief Type for iterate element of contiguous sequence of char-like objects.
   *
   */
  using iterator               = ::portable_stl::wrap_iter<pointer>;
  /**
   * @brief Constant type for iterate element of contiguous sequence of char-like objects.
   *
   */
  using const_iterator         = ::portable_stl::wrap_iter<const_pointer>;
  /**
   * @brief Type for reverse iterate element of contiguous sequence of char-like objects.
   *
   */
  using reverse_iterator       = ::portable_stl::reverse_iterator<iterator>;
  /**
   * @brief Constant type for reverse iterate element of contiguous sequence of char-like objects.
   *
   */
  using const_reverse_iterator = ::portable_stl::reverse_iterator<const_iterator>;

  /**
   * @brief View type for current string type.
   *
   */
  using view_type = ::portable_stl::basic_string_view<value_type, traits_type>;

private:
  /**
   * @brief Type of optimized storage object.
   *
   */
  using storage_object        = ::portable_stl::short_object_optimization<allocator_type>;
  /**
   * @brief Reference wrapper to string. Used in expected return.
   */
  using string_reference_wrap = ::portable_stl::reference_wrapper<basic_string>;

  /**
   * @brief Helper to select funcion overloading.
   *
   * @tparam t_string_view_like
   */
  template<class t_string_view_like>
  using enable_if_can_be_converted_to_string_view = ::portable_stl::enable_if_bool_constant_t<
    ::portable_stl::conjunction<
      ::portable_stl::is_convertible<t_string_view_like const &, view_type>,
      ::portable_stl::negation<::portable_stl::is_same_uncvref<t_string_view_like, basic_string>>,
      ::portable_stl::negation<::portable_stl::is_convertible<t_string_view_like const &, value_type const *>>>,
    void *>;

public:
  /**
   * @brief Internal storage object.
   *
   */
  storage_object m_storage;

  /**
   * @brief This is a special value equal to the maximum value representable by the type size_type. The exact meaning
   * depends on context, but it is generally used either as end of view indicator by the functions that expect a view
   * index or as the error indicator by the functions that return a view index.
   */
  static size_type const npos = size_type(-1);

  // [for tests]

  /**
   * @brief Checks string invariants.
   *
   * @return int Result of checking.
   */
  int check_invariants() const;

public:
  // [string.cons]

  /**
   * @brief Default constructor. Constructs empty string (zero size and unspecified capacity).
   * Allocator is obtained from a default-constructed instance.
   */
  basic_string() noexcept(::portable_stl::is_default_constructible<allocator_type>{}())
      : basic_string(allocator_type()) {
  }

  /**
   * @brief Default constructor. Constructs empty string (zero size and unspecified capacity).
   *
   * @param allocator Allocator to use for all memory allocations of this string.
   */
  explicit basic_string(allocator_type const &allocator) : m_storage(allocator) {
  }

  /**
   * @brief Constructs the string with count copies of character.
   *
   * @throw ::portable_stl::bad_alloc or ::portable_stl::length_error if resize unsuccessful.
   * @param count Size of the resulting string.
   * @param character value to initialize the string with.
   * @param allocator Allocator to use for all memory allocations of this string.
   */
  basic_string(size_type count, value_type character, allocator_type const &allocator = allocator_type{})
      : m_storage(allocator) {
    if ((count + 1) > m_storage.capacity()) {
      ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!m_storage.reserve(count + 1));
    }
    m_storage.set_size(count);
    static_cast<void>(traits_type::assign(::portable_stl::to_address(m_storage.data()), count, character));
    traits_type::assign(data()[count], value_type());
  }

  /**
   * @brief Constructs the string with count copies of character.
   *
   * @throw ::portable_stl::bad_alloc or ::portable_stl::length_error if resize unsuccessful.
   * @param count Size of the resulting string.
   * @param character value to initialize the string with.
   * @param allocator Allocator to use for all memory allocations of this string.
   */
  template<class ptr_type,
           class val_type = value_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::is_same<val_type, ::portable_stl::pstl_char8_t>,
                                         ::portable_stl::is_same<ptr_type, ::portable_stl::char_t>>,
             void *>
           = nullptr>
  basic_string(size_type count, ptr_type const &character, allocator_type const &allocator = allocator_type{})
      : m_storage(allocator) {
    if ((count + 1) > m_storage.capacity()) {
      ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!m_storage.reserve(count + 1));
    }
    m_storage.set_size(count);
    static_cast<void>(
      traits_type::assign(::portable_stl::to_address(m_storage.data()), count, static_cast<value_type>(character)));
    traits_type::assign(data()[count], value_type());
  }

  /**
   * @brief Makes the string with count copies of character.
   *
   * @param count Size of the resulting string.
   * @param character value to initialize the string with.
   * @param allocator Allocator to use for all memory allocations of this string.
   * @return basic_string or ::portable_stl::portable_stl_error>.
   */
  static ::portable_stl::expected<basic_string, ::portable_stl::portable_stl_error> make_string(
    size_type count, value_type character, allocator_type const &allocator = allocator_type{}) noexcept {
    basic_string ret_string{allocator};
    if ((count + 1) > ret_string.m_storage.capacity()) {
      if (!ret_string.m_storage.reserve(count + 1)) {
        return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
          ::portable_stl::portable_stl_error::allocate_error};
      }
    }
    ret_string.m_storage.set_size(count);
    static_cast<void>(traits_type::assign(::portable_stl::to_address(ret_string.data()), count, character));
    traits_type::assign(ret_string.data()[count], value_type());
    return ::portable_stl::expected<basic_string, ::portable_stl::portable_stl_error>(::portable_stl::move(ret_string));
  }

  /**
   * @brief Constructs the string with a substring [pos, other.size()) of other.
   *
   * @throw ::portable_stl::bad_alloc if resize unsuccessful or ::portable_stl::out_of_range.
   * @param other Another string to use as source to initialize the string with.
   * @param pos position of the first character to include.
   * @param allocator Allocator to use for all memory allocations of this string.
   */
  basic_string(basic_string const &other, size_type pos, allocator_type const &allocator = allocator_type{}) noexcept(
    noexcept(basic_string(other, pos, npos, allocator)))
      : basic_string(other, pos, npos, allocator) {
  }

  /**
   * @brief Makes the string with a substring [pos, other.size()) of other.
   *
   * @param other Another string to use as source to initialize the string with.
   * @param pos position of the first character to include.
   * @param allocator Allocator to use for all memory allocations of this string.
   * @return basic_string or ::portable_stl::portable_stl_error>.
   */
  static ::portable_stl::expected<basic_string, ::portable_stl::portable_stl_error> make_string(
    basic_string const &other, size_type pos, allocator_type const &allocator = allocator_type{}) noexcept {
    return other.substr_safe(pos).and_then([&allocator](basic_string const &result) {
      return make_string(result, allocator);
    });
  }

  /**
   * @brief Constructs the string with a substring [pos, other.size()) of other.
   * cpp23
   *
   * @throw ::portable_stl::bad_alloc if resize unsuccessful or ::portable_stl::out_of_range.
   * @param other Another string to use as source to initialize the string with.
   * @param pos position of the first character to include.
   * @param allocator Allocator to use for all memory allocations of this string.
   */
  basic_string(basic_string &&other, size_type pos, allocator_type const &allocator = allocator_type{}) noexcept(
    noexcept(basic_string(::portable_stl::move(other), pos, npos, allocator)))
      : basic_string(::portable_stl::move(other), pos, npos, allocator) {
  }

  /**
   * @brief Constructs the string with a substring [pos, pos+count) of other. If count == npos, or if the
   * requested substring lasts past the end of the string, the resulting substring is [pos, other.size()).
   *
   * @throw ::portable_stl::bad_alloc if resize unsuccessful or ::portable_stl::out_of_range.
   * @param other Another string to use as source to initialize the string with.
   * @param pos position of the first character to include.
   * @param count Size of the resulting string.
   * @param allocator Allocator to use for all memory allocations of this string.
   */
  basic_string(basic_string const   &other,
               size_type             pos,
               size_type             count,
               allocator_type const &allocator
               = allocator_type{}) noexcept(noexcept(basic_string(other.substr(pos, count), allocator)))
      : basic_string(other.substr(pos, count), allocator) {
  }

  /**
   * @brief Makes the string with a substring [pos, pos+count) of other. If count == npos, or if the
   * requested substring lasts past the end of the string, the resulting substring is [pos, other.size()).
   *
   * @param other Another string to use as source to initialize the string with.
   * @param pos position of the first character to include.
   * @param count Size of the resulting string.
   * @param allocator Allocator to use for all memory allocations of this string.
   * @return basic_string or ::portable_stl::portable_stl_error>.
   */
  static ::portable_stl::expected<basic_string, ::portable_stl::portable_stl_error> make_string(
    basic_string const   &other,
    size_type             pos,
    size_type             count,
    allocator_type const &allocator = allocator_type{}) noexcept {
    return other.substr_safe(pos, count).and_then([&allocator](basic_string const &result) {
      return make_string(result, allocator);
    });
  }

  /**
   * @brief Constructs the string with a substring [pos, pos+count) of other. If count == npos, or if the
   * requested substring lasts past the end of the string, the resulting substring is [pos, other.size()).
   * cpp23
   * Should use adventure of rvalue ref!!!
   *
   * @throw ::portable_stl::bad_alloc if resize unsuccessful or ::portable_stl::out_of_range.
   * @param other Another string to use as source to initialize the string with.
   * @param pos position of the first character to include.
   * @param count Size of the resulting string.
   * @param allocator Allocator to use for all memory allocations of this string.
   */
  basic_string(basic_string &&other, size_type pos, size_type count, allocator_type const &allocator = allocator_type{})
      : basic_string(other, pos, count, allocator) {
  }

  /**
   * @brief Constructs the string with the first count characters of character string pointed to by str. str can
   * contain null characters. The length of the string is count. The behavior is undefined if [str, str + count) is not
   * a valid range.
   *
   * @throw ::portable_stl::bad_alloc if resize unsuccessful.
   * @param str Pointer to an array of characters to use as source to initialize the string with.
   * @param count Size of the resulting string.
   * @param allocator Allocator to use for all memory allocations of this string.
   */
  basic_string(const_pointer str, size_type count, allocator_type const &allocator = allocator_type{})
      : m_storage(allocator) {
    if ((count + 1) > m_storage.capacity()) {
      ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!m_storage.reserve(count + 1));
    }
    m_storage.set_size(count);
    ::portable_stl::memcpy(::portable_stl::to_address(m_storage.data()), str, count * sizeof(value_type));
    traits_type::assign(data()[count], value_type());
  }

  /**
   * @brief Constructs the string with the first count characters of character string pointed to by str. str can
   * contain null characters. The length of the string is count. The behavior is undefined if [str, str + count) is not
   * a valid range.
   *
   * @throw ::portable_stl::bad_alloc if resize unsuccessful.
   * @param str Pointer to an array of characters to use as source to initialize the string with.
   * @param count Size of the resulting string.
   * @param allocator Allocator to use for all memory allocations of this string.
   */
  template<class ptr_type,
           class val_type = value_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::is_same<val_type, ::portable_stl::pstl_char8_t>,
                                         ::portable_stl::is_same<ptr_type, ::portable_stl::char_t>>,
             void *>
           = nullptr>
  basic_string(ptr_type const *str, size_type count, allocator_type const &allocator = allocator_type{})
      : m_storage(allocator) {
    if ((count + 1) > m_storage.capacity()) {
      ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!m_storage.reserve(count + 1));
    }
    m_storage.set_size(count);
    ::portable_stl::memcpy(::portable_stl::to_address(m_storage.data()), str, count * sizeof(value_type));
    traits_type::assign(data()[count], value_type());
  }

  /**
   * @brief Makes the string with the first count characters of character string pointed to by str. str can
   * contain null characters. The length of the string is count. The behavior is undefined if [str, str + count) is
   * not a valid range.
   *
   * @param str Pointer to an array of characters to use as source to initialize the string with.
   * @param count Size of the resulting string.
   * @param allocator Allocator to use for all memory allocations of this string.
   * @return ::portable_stl::expected<basic_string, ::portable_stl::portable_stl_error> Result string.
   */
  static ::portable_stl::expected<basic_string, ::portable_stl::portable_stl_error> make_string(
    const_pointer str, size_type count, allocator_type const &allocator = allocator_type{}) noexcept {
    basic_string ret_string{allocator};
    if ((count + 1) > ret_string.m_storage.capacity()) {
      if (!ret_string.m_storage.reserve(count + 1)) {
        return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
          ::portable_stl::portable_stl_error::allocate_error};
      }
    }
    ret_string.m_storage.set_size(count);
    ::portable_stl::memcpy(::portable_stl::to_address(ret_string.data()), str, count * sizeof(value_type));
    traits_type::assign(ret_string.data()[count], value_type());
    return ::portable_stl::expected<basic_string, ::portable_stl::portable_stl_error>{::portable_stl::move(ret_string)};
  }

  /**
   * @brief Constructs the string with the contents initialized with a copy of the null-terminated character
   * string pointed to by cstr. The length of the string is determined by the first null character. The behavior is
   * undefined if [cstr, cstr + t_char_traits::length(cstr)) is not a valid range (for example, if cstr is a null
   * pointer).
   *
   * @throw ::portable_stl::bad_alloc if resize unsuccessful.
   * @param cstr Pointer to an array of characters to use as source to initialize the string with.
   * @param allocator Allocator to use for all memory allocations of this string.
   */
  basic_string(const_pointer cstr, allocator_type const &allocator = allocator_type{})
      : basic_string(cstr, traits_type::length(cstr), allocator) {
  }

  /**
   * @brief Constructs the string with the contents initialized with a copy of the null-terminated character string
   * pointed to by cstr. Only for case when u8-string is a const char[N] (until C++20) and value_type is
   * ::portable_stl::pstl_char8_t = unsigned char.
   *
   * @throw ::portable_stl::bad_alloc if resize unsuccessful.
   * @param cstr Pointer to an array of characters to use as source to initialize the string with.
   * @param allocator Allocator to use for all memory allocations of this string.
   */
  template<class ptr_type,
           class val_type = value_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::is_same<val_type, ::portable_stl::pstl_char8_t>,
                                         ::portable_stl::is_same<ptr_type, ::portable_stl::char_t>>,
             void *>
           = nullptr>
  basic_string(ptr_type const *cstr, allocator_type const &allocator = allocator_type{})
      : basic_string(
          cstr, traits_type::length(static_cast<const_pointer>(static_cast<void const *>(cstr))), allocator) {
  }

  /**
   * @brief Makes the string with the contents initialized with a copy of the null-terminated character
   * string pointed to by cstr. The length of the string is determined by the first null character. The behavior is
   * undefined if [cstr, cstr + t_char_traits::length(cstr)) is not a valid range (for example, if cstr is a null
   * pointer).
   *
   * @param cstr Pointer to an array of characters to use as source to initialize the string with.
   * @param allocator Allocator to use for all memory allocations of this string.
   * @return basic_string or ::portable_stl::portable_stl_error>.
   */
  static ::portable_stl::expected<basic_string, ::portable_stl::portable_stl_error> make_string(
    const_pointer cstr, allocator_type const &allocator = allocator_type{}) noexcept {
    return make_string(cstr, traits_type::length(cstr), allocator);
  }

  /**
   * @brief Constructs the string with the contents of the range [first, last).
   * @tparam t_input_iterator Iterator like as const_interator.
   * @throw ::portable_stl::bad_alloc if resize unsuccessful.
   *
   * @param first Range to copy the characters from.
   * @param last Range to copy the characters from.
   * @param allocator Allocator to use for all memory allocations of this string.
   */
  template<class t_input_iterator,
           ::portable_stl::enable_if_bool_constant_t<
             typename string_helper::has_iterator_category_convertible_to<t_input_iterator,
                                                                          ::portable_stl::input_iterator_tag>::type,
             void *>
           = nullptr>
  basic_string(t_input_iterator first, t_input_iterator last, allocator_type const &allocator = allocator_type{})
      : basic_string(
          ::portable_stl::to_address(first), static_cast<size_type>(::portable_stl::distance(first, last)), allocator) {
  }

  /**
   * @brief Makes the string with the contents of the range [first, last).
   * @tparam t_input_iterator Iterator like as const_interator.
   * @param first Range to copy the characters from.
   * @param last Range to copy the characters from.
   * @param allocator Allocator to use for all memory allocations of this string.
   * @return basic_string or ::portable_stl::portable_stl_error>.
   */
  template<class t_input_iterator,
           ::portable_stl::enable_if_bool_constant_t<
             typename string_helper::has_iterator_category_convertible_to<t_input_iterator,
                                                                          ::portable_stl::input_iterator_tag>::type,
             void *>
           = nullptr>
  static ::portable_stl::expected<basic_string, ::portable_stl::portable_stl_error> make_string(
    t_input_iterator first, t_input_iterator last, allocator_type const &allocator = allocator_type{}) noexcept {
    return make_string(
      ::portable_stl::to_address(first), static_cast<size_type>(::portable_stl::distance(first, last)), allocator);
  }

  /**
   * @brief Copy constructor. Constructs the string with a copy of the contents of other.
   * @throw ::portable_stl::bad_alloc if allocation for copy unsuccessful.
   * @param other Another string to use as source to initialize the string with.
   */
  basic_string(basic_string const &other) noexcept(
    noexcept(storage_object(::portable_stl::declval<storage_object &>())))
      : m_storage(other.m_storage) {
  }

  /**
   * @brief Makes the string with a copy of the contents of other.
   * @param other Another string to use as source to initialize the string with.
   * @return basic_string or ::portable_stl::portable_stl_error>.
   */
  static ::portable_stl::expected<basic_string, ::portable_stl::portable_stl_error> make_string(
    basic_string const &other) noexcept {
    return make_string(other, allocator_type{});
  }

  /**
   * @brief Copy constructor. Constructs the string with a copy of the contents of other.
   * @throw ::portable_stl::bad_alloc if allocation for copy unsuccessful.
   * @param other Another string to use as source to initialize the string with.
   * @param allocator Allocator to use for all memory allocations of this string.
   */
  basic_string(basic_string const &other, allocator_type const &allocator) noexcept(
    noexcept(storage_object(::portable_stl::declval<storage_object &>(), ::portable_stl::declval<allocator_type &>())))
      : m_storage(other.m_storage, allocator) {
  }

  /**
   * @brief Makes the string with a copy of the contents of other.
   * @param other Another string to use as source to initialize the string with.
   * @param allocator Allocator to use for all memory allocations of this string.
   * @return basic_string or ::portable_stl::portable_stl_error>.
   */
  static ::portable_stl::expected<basic_string, ::portable_stl::portable_stl_error> make_string(
    basic_string const &other, allocator_type const &allocator) noexcept {
    return make_string(static_cast<view_type>(other), allocator);
  }

  /**
   * @brief Move constructor. Constructs the string with the contents of other using move semantics.
   * other is left in valid, but unspecified state.
   * @param other Another string to use as source to initialize the string with.
   */
  basic_string(basic_string &&other) noexcept : m_storage(::portable_stl::move(other.m_storage)) {
  }

  /**
   * @brief Move constructor. Constructs the string with the contents of other using move semantics.
   * other is left in valid, but unspecified state.
   * @param other Another string to use as source to initialize the string with.
   * @param allocator Allocator to use for all memory allocations of this string.
   */
  basic_string(basic_string &&other, allocator_type const &allocator) noexcept(
    noexcept(storage_object(::portable_stl::move(storage_object{}), ::portable_stl::declval<allocator_type &>())))
      : m_storage(::portable_stl::move(other.m_storage), allocator) {
  }

  /**
   * @brief Constructs the string with the contents of the initializer list init_list.
   * @throw ::portable_stl::bad_alloc if allocation for copy unsuccessful.
   * @param init_list std::initializer_list to initialize the string with
   * @param allocator Allocator to use for all memory allocations of this string.
   */
  basic_string(std::initializer_list<value_type> init_list,
               allocator_type const             &allocator
               = allocator_type{}) noexcept(noexcept(basic_string(init_list.begin(), init_list.end(), allocator)))
      : basic_string(init_list.begin(), init_list.end(), allocator) {
  }

  /**
   * @brief Makes the string with the contents of the initializer list init_list.
   * @param init_list std::initializer_list to initialize the string with
   * @param allocator Allocator to use for all memory allocations of this string.
   * @return basic_string or ::portable_stl::portable_stl_error>.
   */
  static ::portable_stl::expected<basic_string, ::portable_stl::portable_stl_error> make_string(
    std::initializer_list<value_type> init_list, allocator_type const &allocator = allocator_type{}) noexcept {
    return make_string(init_list.begin(), init_list.end(), allocator);
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by view_type sv = sv_like, then
   * initializes the string with the contents of sv_like.
   * @tparam t_string_view_like Type like view_type
   * @throw ::portable_stl::bad_alloc if allocation for copy unsuccessful.
   * @param sv_like Object (convertible to view_type) to initialize the string with.
   * @param allocator Allocator to use for all memory allocations of this string.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  explicit basic_string(t_string_view_like const &sv_like, allocator_type const &allocator = allocator_type{}) noexcept(
    noexcept(basic_string(view_type(sv_like).data(), view_type(sv_like).size(), allocator)))
      : basic_string(
          (view_type(sv_like).empty() ? nullptr : view_type(sv_like).data()), view_type(sv_like).size(), allocator) {
  }

  /**
   * @brief Makes the string by implicitly converts sv_like to a string view sv as if by view_type sv = sv_like, then
   * initializes the string with the contents of sv_like.
   * @tparam t_string_view_like Type like view_type
   * @param sv_like Object (convertible to view_type) to initialize the string with.
   * @param allocator Allocator to use for all memory allocations of this string.
   * @return basic_string or ::portable_stl::portable_stl_error>.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  static ::portable_stl::expected<basic_string, ::portable_stl::portable_stl_error> make_string(
    t_string_view_like const &sv_like, allocator_type const &allocator = allocator_type{}) noexcept {
    view_type sv = sv_like;
    return make_string((sv.empty() ? nullptr : sv.data()), sv.size(), allocator);
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by view_type sv = sv_like, then
   * initializes the string with the contents of sv_like.
   * @tparam t_string_view_like Type like view_type
   * @throw ::portable_stl::bad_alloc if allocation for copy unsuccessful.
   * @param sv_like Object (convertible to view_type) to initialize the string with.
   * @param pos position of the first character to include.
   * @param count Size of the resulting string.
   * @param allocator Allocator to use for all memory allocations of this string.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  basic_string(t_string_view_like const &sv_like,
               size_type                 pos,
               size_type                 count,
               allocator_type const     &allocator
               = allocator_type{}) noexcept(noexcept(basic_string(view_type(sv_like).substr(pos, count), allocator)))
      : basic_string(view_type(sv_like).substr(pos, count), allocator) {
  }

  /**
   * @brief Makes the string by implicitly converts sv_like to a string view sv as if by view_type sv = sv_like, then
   * initializes the string with the contents of sv_like.
   *
   * @tparam t_string_view_like Type like view_type
   * @param sv_like Object (convertible to view_type) to initialize the string with.
   * @param pos Position of the first character to include.
   * @param count Size of the resulting string.
   * @param allocator Allocator to use for all memory allocations of this string.
   * @return ::portable_stl::expected<basic_string, ::portable_stl::portable_stl_error>
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  static ::portable_stl::expected<basic_string, ::portable_stl::portable_stl_error> make_string(
    t_string_view_like const &sv_like,
    size_type                 pos,
    size_type                 count,
    allocator_type const     &allocator = allocator_type{}) {
    view_type sv = sv_like;
    return sv.substr_safe(pos, count).and_then([&allocator](view_type const &result) {
      return make_string(result, allocator);
    });
  }

  /**
   * @brief basic_string cannot be constructed from nullptr.
   *
   */
  constexpr basic_string(::portable_stl::nullptr_t) = delete;

  // ~basic_string() noexcept = default;

  // [operator=]

  /**
   * @brief Replaces the contents with a copy of str.
   * If *this and str are the same object, this function has no effect.
   *
   * @param str String to be used as source to initialize the string with.
   * @return basic_string & *this.
   */
  basic_string &operator=(basic_string const &str) noexcept(noexcept(basic_string{str})) {
    basic_string tmp{str};
    swap(tmp);
    return *this;
  }

  /**
   * @brief Replaces the contents with those of str using move semantics.
   * str is in a valid but unspecified state afterwards.
   *
   * @param str String to be used as source to initialize the string with.
   * @return basic_string & *this.
   */
  basic_string &operator=(basic_string &&str) noexcept(
    typename ::portable_stl::allocator_traits<allocator_type>::propagate_on_container_move_assignment{}() ||
    typename ::portable_stl::allocator_traits<allocator_type>::is_always_equal{}()) {
    basic_string tmp{::portable_stl::move(str)};
    swap(tmp);
    return *this;
  }

  /**
   * @brief Replaces the contents with those of null-terminated character string pointed to by cstr.
   *
   * @param cstr Pointer to a null-terminated character string to use as source to initialize the string with.
   * @return basic_string & *this.
   */
  basic_string &operator=(const_pointer cstr) noexcept(noexcept(basic_string{cstr})) {
    basic_string tmp{cstr};
    swap(tmp);
    return *this;
  }

  /**
   * @brief Replaces the contents with character ch.
   *
   * @param ch Value to initialize characters of the string with
   * @return basic_string & *this.
   */
  basic_string &operator=(t_char_type ch) noexcept(noexcept(basic_string(1U, ch))) {
    basic_string tmp(1U, ch);
    swap(tmp);
    return *this;
  }

  /**
   * @brief Replaces the contents with those of the initializer list init_list.
   *
   * @param init_list initializer_list to initialize the string with.
   * @return basic_string & *this.
   */
  basic_string &operator=(std::initializer_list<value_type> init_list) noexcept(noexcept(basic_string(init_list))) {
    basic_string tmp{init_list};
    swap(tmp);
    return *this;
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by ::basic_string_view<t_char_type, t_char_traits> sv
   * = sv_like
   *
   * @tparam t_string_view_like Type like view_type
   * @param sv_like Object convertible to ::basic_string_view to initialize the string with.
   * @return basic_string & *this.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  basic_string &operator=(t_string_view_like const &sv_like) noexcept(noexcept(basic_string{sv_like})) {
    basic_string tmp{sv_like};
    swap(tmp);
    return *this;
  }

  /**
   * @brief basic_string cannot be assigned from nullptr.
   *
   * @return *this.
   */
  basic_string &operator=(::portable_stl::nullptr_t) = delete;

  // [assign]

  /**
   * @brief Replaces the contents with count copies of character ch.
   *
   * @param count Size of the resulting string
   * @param ch Value to initialize characters of the string with
   * @return basic_string & *this.
   */

  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> assign(size_type  count,
                                                                                             value_type ch) noexcept {
    return make_string(count, ch).transform([this](basic_string tmp) -> string_reference_wrap {
      swap(tmp);
      return ::portable_stl::ref(*this);
    });
  }

  /**
   * @brief Replaces the contents with a copy of str.
   *
   * @param str String to be used as source to initialize the characters with.
   * @return basic_string & *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> assign(
    basic_string const &str) noexcept {
    return make_string(str).transform([this](basic_string tmp) -> string_reference_wrap {
      swap(tmp);
      return ::portable_stl::ref(*this);
    });
  }

  /**
   * @brief Replaces the contents with a substring [pos, pos+count) of str. If the requested substring lasts past the
   * end of the string, or if count == npos, the resulting substring is [pos, str.size()).
   * The behavior is undefined if pos > str.size() and exceptions is disabled.
   *
   * @param str String to be used as source to initialize the characters with.
   * @param pos Index of the first character to take
   * @param count Size of the resulting string
   * @return basic_string & *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> assign(
    basic_string const &str, size_type pos, size_type count = npos) noexcept {
    return make_string(str, pos, count).transform([this](basic_string tmp) -> string_reference_wrap {
      swap(tmp);
      return ::portable_stl::ref(*this);
    });
  }

  /**
   * @brief Replaces the contents with those of str using move semantics.
   *
   * @param str String to be used as source to initialize the characters with.
   * @return basic_string & *this.
   */
  basic_string &assign(basic_string &&str) noexcept(
    typename ::portable_stl::allocator_traits<allocator_type>::propagate_on_container_move_assignment{}() ||
    typename ::portable_stl::allocator_traits<allocator_type>::is_always_equal{}()) {
    basic_string tmp{::portable_stl::move(str)};
    swap(tmp);
    return *this;
  }

  /**
   * @brief Replaces the contents with copies of the characters in the range [s, s+count).
   * This range can contain null characters.
   *
   * @param cstr Pointer to a character string to use as source to initialize the string with.
   * @param count Size of the resulting string
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> assign(const_pointer cstr,
                                                                                             size_type count) noexcept {
    return make_string(cstr, count).transform([this](basic_string tmp) -> string_reference_wrap {
      swap(tmp);
      return ::portable_stl::ref(*this);
    });
  }

  /**
   * @brief Replaces the contents with those of null-terminated character string pointed to by s.
   * The length of the string is determined by the first null character using t_char_traits::length(s).
   *
   * @param cstr Pointer to a character string to use as source to initialize the string with.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> assign(
    const_pointer cstr) noexcept {
    return make_string(cstr).transform([this](basic_string tmp) -> string_reference_wrap {
      swap(tmp);
      return ::portable_stl::ref(*this);
    });
  }

  /**
   * @brief Replaces the contents with copies of the characters in the range [first, last).
   *
   * @tparam t_input_iterator Type like const_iterator.
   * @param first Begin range to copy the characters from.
   * @param last End range to copy the characters from.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  template<class t_input_iterator,
           class t_iter_category = typename ::portable_stl::iterator_traits<t_input_iterator>::iterator_category,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::is_convertible<t_iter_category, ::portable_stl::input_iterator_tag>,
             void *>
           = nullptr>
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> assign(
    t_input_iterator first, t_input_iterator last) noexcept {
    return make_string(first, last).transform([this](basic_string tmp) -> string_reference_wrap {
      swap(tmp);
      return ::portable_stl::ref(*this);
    });
  }

  /**
   * @brief Replaces the contents with those of the initializer list init_list.
   *
   * @param init_list initializer_list to initialize the characters of the string with.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> assign(
    std::initializer_list<value_type> init_list) noexcept {
    return make_string(init_list).transform([this](basic_string tmp) -> string_reference_wrap {
      swap(tmp);
      return ::portable_stl::ref(*this);
    });
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by view_type sv = sv_like, then replaces the contents
   * with those of sv.
   *
   * @tparam t_string_view_like Type like view_type
   * @param sv_like Object (convertible to basic_string_view) to initialize the characters of the string with.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> assign(
    t_string_view_like const &sv_like) noexcept {
    return make_string(sv_like).transform([this](basic_string tmp) -> string_reference_wrap {
      swap(tmp);
      return ::portable_stl::ref(*this);
    });
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by view_type sv = sv_like, then replaces the contents
   * with the characters from the subview [pos, pos+count) of sv. The behavior is undefined if pos > str.size() and
   * exceptions is disabled.
   *
   * @tparam t_string_view_like Type like view_type
   * @param sv_like Object (convertible to basic_string_view) to initialize the characters of the string with.
   * @param pos index of the first character to take
   * @param count Size of the resulting string
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> assign(
    t_string_view_like const &sv_like, size_type pos, size_type count = npos) noexcept {
    return make_string(sv_like, pos, count).transform([this](basic_string tmp) -> string_reference_wrap {
      swap(tmp);
      return ::portable_stl::ref(*this);
    });
  }

  /**
   * @brief Returns the allocator associated with the string.
   *
   * @return allocator_type The associated allocator.
   */
  constexpr allocator_type get_allocator() const noexcept {
    return m_storage.get_allocator();
  }

  // [ element access ]

  /**
   * @brief Returns a reference to the character at specified location pos.
   * The behavior is undefined if pos > str.size() and exceptions is disabled.
   *
   * @throw ::portable_stl::out_of_range if pos > str.size().
   * @param pos position of the character to return.
   * @return reference Reference to the requested character.
   */
  reference at(size_type pos) {
    ::portable_stl::throw_on_true<::portable_stl::out_of_range<>>(pos > size());
    return *(begin() + static_cast<difference_type>(pos));
  }

  /**
   * @brief Returns a reference to the character at specified location pos.
   * The behavior is undefined if pos > str.size() and exceptions is disabled.
   *
   * @throw ::portable_stl::out_of_range if pos > str.size().
   * @param pos position of the character to return.
   * @return const_reference Reference to the requested character.
   */
  const_reference at(size_type pos) const {
    ::portable_stl::throw_on_true<::portable_stl::out_of_range<>>(pos > size());
    return *(cbegin() + static_cast<difference_type>(pos));
  }

  /**
   * @brief Returns a reference to the character at specified location pos.
   * No bounds checking is performed.
   * If pos > size(), the behavior is undefined.
   *
   * @param pos position of the character to return.
   * @return reference Reference to the requested character.
   */
  reference operator[](size_type pos) noexcept {
    return *(begin() + static_cast<difference_type>(pos));
  }

  /**
   * @brief Returns a reference to the character at specified location pos.
   * No bounds checking is performed.
   * If pos > size(), the behavior is undefined.
   *
   * @param pos position of the character to return.
   * @return const_reference Reference to the requested character.
   */
  const_reference operator[](size_type pos) const noexcept {
    return *(cbegin() + static_cast<difference_type>(pos));
  }

  /**
   * @brief Returns reference to the first character in the string.
   * The behavior is undefined if empty() == true.
   *
   * @return reference Reference to the first character.
   */
  reference front() noexcept {
    return *begin();
  }

  /**
   * @brief Returns reference to the first character in the string.
   * The behavior is undefined if empty() == true.
   *
   * @return const_reference Reference to the first character.
   */
  const_reference front() const noexcept {
    return *cbegin();
  }

  /**
   * @brief Returns reference to the last character in the string.
   * The behavior is undefined if empty() == true.
   *
   * @return reference Reference to the last character.
   */
  reference back() noexcept {
    return *(end() - 1U);
  }

  /**
   * @brief Returns reference to the last character in the string.
   * The behavior is undefined if empty() == true.
   *
   * @return const_reference Reference to the last character.
   */
  const_reference back() const noexcept {
    return *(cend() - 1U);
  }

  /**
   * @brief Returns a pointer to the underlying array serving as character storage.
   * The returned array is null-terminated.
   *
   * @return pointer A pointer to the underlying character storage.
   */
  pointer data() noexcept {
    return &(*begin());
  }

  /**
   * @brief Returns a pointer to the underlying array serving as character storage.
   * The returned array is null-terminated.
   *
   * @return const_pointer A pointer to the underlying character storage.
   */
  const_pointer data() const noexcept {
    return &(*cbegin());
  }

  /**
   * @brief Returns a pointer to a null-terminated character array with data equivalent to those stored in the string.
   *
   * @return const_pointer Pointer to the underlying character storage.
   */
  const_pointer c_str() const noexcept {
    return data();
  }

  /**
   * @brief Returns a string view like view_type.
   *
   * @return view_type A string view representing the entire contents of the string.
   */
  operator view_type() const noexcept {
    return view_type{::portable_stl::to_address(m_storage.data()), m_storage.size()};
  }

  // [iterators]

  /**
   * @brief Returns an iterator to the first character of the string.
   *
   * @return iterator Iterator to the first character.
   */
  iterator begin() noexcept {
    return iterator{::portable_stl::to_address(m_storage.data())};
  }

  /**
   * @brief Returns an iterator to the first character of the string.
   *
   * @return const_iterator Iterator to the first character.
   */
  const_iterator begin() const noexcept {
    return const_iterator{::portable_stl::to_address(m_storage.data())};
  }

  /**
   * @brief Returns an iterator to the first character of the string.
   *
   * @return const_iterator Iterator to the first character.
   */
  const_iterator cbegin() const noexcept {
    return const_iterator{::portable_stl::to_address(m_storage.data())};
  }

  /**
   * @brief Returns an iterator to the character following the last character of the string.
   * This character acts as a placeholder, attempting to access it results in undefined behavior.
   *
   * @return iterator Iterator to the character following the last character
   */
  iterator end() noexcept {
    return iterator{::portable_stl::to_address(m_storage.data()) + size()};
  }

  /**
   * @brief Returns an iterator to the character following the last character of the string.
   * This character acts as a placeholder, attempting to access it results in undefined behavior.
   *
   * @return const_iterator Iterator to the character following the last character
   */
  const_iterator end() const noexcept {
    return const_iterator{::portable_stl::to_address(m_storage.data()) + size()};
  }

  /**
   * @brief Returns an iterator to the character following the last character of the string.
   * This character acts as a placeholder, attempting to access it results in undefined behavior.
   *
   * @return const_iterator Iterator to the character following the last character
   */
  const_iterator cend() const noexcept {
    return const_iterator{::portable_stl::to_address(m_storage.data()) + size()};
  }

  /**
   * @brief Returns a reverse iterator to the first character of the reversed string.
   * It corresponds to the last character of the non-reversed string.
   *
   * @return reverse_iterator Reverse iterator to the first character.
   */
  reverse_iterator rbegin() noexcept {
    return reverse_iterator{end()};
  }

  /**
   * @brief Returns a reverse iterator to the first character of the reversed string.
   * It corresponds to the last character of the non-reversed string.
   *
   * @return const_reverse_iterator Reverse iterator to the first character.
   */
  const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator{end()};
  }

  /**
   * @brief Returns a reverse iterator to the first character of the reversed string.
   * It corresponds to the last character of the non-reversed string.
   *
   * @return const_reverse_iterator Reverse iterator to the first character.
   */
  const_reverse_iterator crbegin() const noexcept {
    return const_reverse_iterator{cend()};
  }

  /**
   * @brief Returns a reverse iterator to the character following the last character of the reversed string.
   * It corresponds to the character preceding the first character of the non-reversed string.
   * This character acts as a placeholder, attempting to access it results in undefined behavior.
   *
   * @return reverse_iterator Reverse iterator to the character following the last character
   */
  reverse_iterator rend() noexcept {
    return reverse_iterator{begin()};
  }

  /**
   * @brief Returns a reverse iterator to the character following the last character of the reversed string.
   * It corresponds to the character preceding the first character of the non-reversed string.
   * This character acts as a placeholder, attempting to access it results in undefined behavior.
   *
   * @return const_reverse_iterator Reverse iterator to the character following the last character
   */
  const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator{begin()};
  }

  /**
   * @brief Returns a reverse iterator to the character following the last character of the reversed string.
   * It corresponds to the character preceding the first character of the non-reversed string.
   * This character acts as a placeholder, attempting to access it results in undefined behavior.
   *
   * @return const_reverse_iterator Reverse iterator to the character following the last character
   */
  const_reverse_iterator crend() const noexcept {
    return const_reverse_iterator{cbegin()};
  }

  // [capacity]

  /**
   * @brief Checks if the string has no characters, i.e. whether.
   *
   * @return empty check result.
   * @retval true if the string is empty.
   * @retval false if the string not empty.
   */
  constexpr bool empty() const noexcept {
    return 0 == size();
  }

  /**
   * @brief Returns the number of value_type elements in the string.
   *
   * @return size_type The number of value_type elements in the string.
   */
  size_type size() const noexcept {
    return m_storage.size();
  }

  /**
   * @brief Returns the number of value_type elements in the string.
   *
   * @return size_type The number of value_type elements in the string.
   */
  constexpr size_type length() const noexcept {
    return size();
  }

  /**
   * @brief Returns the maximum number of elements the string is able to hold due to system.
   *
   * @return size_type Maximum number of characters.
   */
  constexpr size_type max_size() const noexcept {
    return ::portable_stl::numeric_limits<::portable_stl::size_t>::max() / 2 * sizeof(value_type);
  }

  /**
   * @brief Informs a ::portable_stl::basic_string object of a planned change in size, so that it can manage the
   * storage allocation appropriately.
   * If new_cap is less than or equal to the current capacity(), there is no effect. (since C++20)
   *
   * @param new_cap New capacity of the string.
   * @return true if ok,
   * @return false if (re)allocation fails.
   */
  bool reserve(size_type new_cap) noexcept {
    if (new_cap > m_storage.capacity()) {
      return m_storage.reserve(new_cap);
    }
    return true;
  }

  /**
   * @brief Returns the number of characters that the string has currently allocated space for.
   *
   * @return size_type Capacity of the currently allocated storage, i.e. the storage available for storing elements.
   */
  constexpr size_type capacity() const noexcept {
    return m_storage.capacity();
  }

  /**
   * @brief Requests the removal of unused capacity.
   * It is a non-binding request to reduce capacity() to size().
   * If (and only if) reallocation takes place, all pointers, references, and iterators are invalidated.
   *
   * @return true
   * @return false if reallocation fails.
   */
  bool shrink_to_fit() noexcept {
    return m_storage.reserve(m_storage.size() + 1, true);
  }

  // [modifiers]

  /**
   * @brief Removes all characters from the string.
   * All pointers, references, and iterators are invalidated.
   * This implementation do not release the allocated memory (see also #shrink_to_fit).
   *
   */
  void clear() noexcept {
    // always release allocated memory.
    static_cast<void>(m_storage.reserve(0));
    traits_type::assign(data()[0], value_type());
    m_storage.set_size(0);
  }

public:
  /**
   * @brief Inserts count copies of character ch at the position index into the string.
   *
   * @param index position at which the content will be inserted.
   * @param count Number of characters to insert.
   * @param ch Character to insert.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> insert(
    size_type index, size_type count, const_reference ch) noexcept {
    if (index > size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::out_of_range};
    }
    if (m_storage.insert(index, count)) {
      static_cast<void>(traits_type::assign(&(*begin()) + index, count, ch));
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
    return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error>{
      ::portable_stl::ref(*this)};
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by view_type sv = sv_like;
   * then inserts the elements from sv before the element (if any) pointed by pos into the string.
   *
   * @tparam t_string_view_like Type like view_type
   * @param pos iterator before which the characters will be inserted.
   * @param sv_like Object (convertible to view_type) to insert the characters from.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> insert(
    size_type index, t_string_view_like const &sv_like) noexcept {
    if (index > size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::out_of_range};
    }
    view_type sv = sv_like;
    if (m_storage.insert(index, sv.size())) {
      ::portable_stl::memcpy((begin() + static_cast<difference_type>(index)).operator->(), sv.begin(), sv.size());
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
    return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error>{
      ::portable_stl::ref(*this)};
  }

  /**
   * @brief Inserts null-terminated character string pointed to by cstr at the position index into the string.
   * The length of the string is determined by the first null character using traits_type::length(s).
   *
   * @param index position at which the content will be inserted.
   * @param cstr Pointer to the character string to insert.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> insert(
    size_type index, const_pointer cstr) noexcept {
    return insert(index, view_type{cstr});
  }

  /**
   * @brief Inserts the characters in the range [s, s+count) at the position index into the string.
   * The range can contain null characters.
   *
   * @param index position at which the content will be inserted.
   * @param cstr Pointer to the character string to insert.
   * @param count Number of characters to insert.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> insert(
    size_type index, const_pointer cstr, size_type count) noexcept {
    return insert(index, view_type{cstr, count});
  }

  /**
   * @brief Inserts string str at the position index into the string.
   *
   * @param index position at which the content will be inserted.
   * @param str string to insert.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> insert(
    size_type index, basic_string const &str) noexcept {
    return insert(index, view_type{str});
  }

  /**
   * @brief Inserts a string, obtained by str.substr(index_str, count) at the position index into the string.
   *
   * @param index position at which the content will be inserted.
   * @param str string to insert.
   * @param index_str position of the first character in the string str to insert.
   * @param count Number of characters to insert.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> insert(
    size_type index, basic_string const &str, size_type index_str, size_type count = npos) noexcept {
    return view_type{str}.substr_safe(index_str, count).and_then([this, index](view_type sv) {
      return insert(index, sv);
    });
  }

  /**
   * @brief Inserts character ch before the character pointed by pos into the string.
   *
   * @param pos iterator before which the characters will be inserted.
   * @param ch Character to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> An iterator which refers to the copy
   * of the first inserted character.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(const_iterator  pos,
                                                                                const_reference ch) noexcept {
    auto const index = pos - begin();
    return insert(static_cast<size_type>(index), 1, ch).transform([this, index](string_reference_wrap) -> iterator {
      return begin() + index;
    });
  }

  /**
   * @brief Inserts count copies of character ch before the element (if any) pointed by pos into the string.
   *
   * @param pos iterator before which the characters will be inserted.
   * @param count Number of characters to insert.
   * @param ch Character to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> An iterator which refers to the copy
   * of the first inserted character or pos if no characters were inserted ( count == 0U ).
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(
    const_iterator pos, size_type count, const_reference ch) noexcept {
    auto const index = pos - begin();
    return insert(static_cast<size_type>(index), count, ch).transform([this, index](string_reference_wrap) -> iterator {
      return begin() + index;
    });
  }

  /**
   * @brief Inserts characters from the range [first, last) before the element (if any) pointed by pos into the string.
   * @tparam t_input_iterator Type like const_iterator.
   *
   * @param pos iterator before which the characters will be inserted.
   * @param first Begin range defining characters to insert.
   * @param last End range defining characters to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> An iterator which refers to the copy
   * of the first inserted character or pos if no characters were inserted ( first == last ).
   */
  template<class t_input_iterator,
           class t_iter_category = typename ::portable_stl::iterator_traits<t_input_iterator>::iterator_category,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::is_convertible<t_iter_category, ::portable_stl::input_iterator_tag>,
             void *>
           = nullptr>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(
    const_iterator pos, t_input_iterator first, t_input_iterator last) noexcept {
    auto const index = ::portable_stl::distance(cbegin(), pos);
    return insert(static_cast<size_type>(index), basic_string(first, last, get_allocator()))
      .transform([this, index](string_reference_wrap) -> iterator {
        return begin() + index;
      });
  }

  /**
   * @brief Inserts elements from initializer list ilist before the element (if any) pointed by pos into the string.
   *
   * @param pos iterator before which the characters will be inserted.
   * @param init_list initializer_list to insert the characters from.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> An iterator which refers to the copy
   * of the first inserted character or pos if no characters were inserted ( init_list.size() == 0 )
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(
    const_iterator pos, std::initializer_list<value_type> init_list) noexcept {
    return insert(pos, const_iterator(init_list.begin()), const_iterator(init_list.end()));
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by view_type sv = sv_like; then inserts, before the
   * element (if any) pointed by pos, the characters from the subview [index_str, index_str+count) of sv into the string
   * If the requested subview lasts past the end of sv, or if count == npos, the resulting subview is [index_str,
   * sv.size()). The behavior is undefined if index_str > sv.size(), or if index > size(), and exceptions is disabled.
   *
   * @tparam t_string_view_like Type like view_type
   * @param index position at which the content will be inserted.
   * @param sv_like Object (convertible to view_type) to insert the characters from.
   * @param index_str position of the first character in the string str to insert.
   * @param count Number of characters to insert.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> insert(
    size_type index, t_string_view_like const &sv_like, size_type index_str, size_type count = npos) noexcept {
    view_type sv = sv_like;
    return sv.substr_safe(index_str, count).and_then([this, index](view_type sv_sub) {
      return insert(index, sv_sub);
    });
  }

  /**
   * @brief Removes specified characters from the string.
   * Removes min(count, size() - index) characters starting at index.
   * The behavior is undefined if index > size(), and exceptions is disabled.
   *
   * @throw portable_stl::out_of_range if index > size().
   * @param index first character to remove.
   * @param count Number of characters to remove.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> erase(
    size_type index = 0U, size_type count = npos) noexcept {
    if (index > size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::out_of_range};
    } else {
      auto const storage_size = m_storage.size();
      auto const erase_size   = ::portable_stl::min(storage_size - index, count);
      if (storage_size != erase_size) {
        ::portable_stl::memmove((begin() + static_cast<difference_type>(index)).operator->(),
                                (cbegin() + static_cast<difference_type>(index + erase_size)).operator->(),
                                storage_size - index - erase_size + 1);
      } else {
        // null-terminated character '\0'
        traits_type::assign(data()[index], value_type());
      }
      // always change size down: may move data to short string but not reallocate!
      static_cast<void>(m_storage.reserve(storage_size - erase_size + 1));
      m_storage.set_size(storage_size - erase_size);

      return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error>{
        ::portable_stl::ref(*this)};
    }
  }

  /**
   * @brief Removes specified characters from the string.
   * Removes the character at position.
   *
   * @param position iterator to the character to remove.
   * @return const_iterator Iterator pointing to the character immediately following the character erased,
   * or end() if no such character exists.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> erase(
    const_iterator const &position) noexcept {
    auto const index = static_cast<size_type>(::portable_stl::distance(cbegin(), position));
    return erase(index, 1).transform([this, index](string_reference_wrap) -> iterator {
      return begin() + index;
    });
  }

  /**
   * @brief Removes specified characters from the string.
   * Removes the characters in the range [first, last).
   *
   * @param first Begin range of the characters to remove.
   * @param last End range of the characters to remove.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> Iterator pointing to the character
   * last pointed to before the erase, or end() if no such character exists.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> erase(const_iterator const &first,
                                                                               const_iterator const &last) noexcept {
    auto const index = static_cast<size_type>(::portable_stl::distance(cbegin(), first));
    return erase(index, ::portable_stl::distance(first, last))
      .transform([this, index](string_reference_wrap) -> iterator {
        return begin() + index;
      });
  }

  /**
   * @brief Appends the given character ch to the end of the string.
   * The behavior is undefined if size() > max_size(), and exceptions is disabled.
   *
   * @throw ::portable_stl::length_error size() > max_size().
   * @param ch the character to append.
   * @return true if ok.
   * @return false
   */
  bool push_back(const_reference ch) noexcept {
    return static_cast<bool>(append(1, ch));
  }

  /**
   * @brief Removes the last character from the string.
   * The behavior is undefined if the string is empty.
   *
   * @return true if ok.
   * @return false
   */
  bool pop_back() noexcept {
    return static_cast<bool>(erase(::portable_stl::distance(begin(), end() - 1U), 1U));
  }

  /**
   * @brief Appends count copies of character ch to the string.
   * The behavior is undefined if size() > max_size(), and exceptions is disabled.
   *
   * @throw portable_stl::length_error size() > max_size().
   * @param count Number of characters to append.
   * @param ch Character value to append.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */

  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> append(
    size_type count, const_reference ch) noexcept {
    auto index = size();
    if (m_storage.reserve(index + count + 1)) {
      m_storage.set_size(index + count);
      traits_type::assign(::portable_stl::to_address(&(*(begin() + static_cast<difference_type>(index)))), count, ch);
      if (count > 0) {
        traits_type::assign(data()[index + count], value_type());
      }
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
    return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error>{
      ::portable_stl::ref(*this)};
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by view_type sv = sv_like,
   * then appends all characters from sv to the string.
   * The behavior is undefined if size() > max_size(), and exceptions is disabled.
   *
   * @throw portable_stl::length_error size() > max_size().
   * @tparam t_string_view_like Type like view_type.
   * @param sv_like Object convertible to basic_string_view with the characters to append.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> append(
    t_string_view_like const &sv_like) noexcept {
    view_type sv    = sv_like;
    auto      index = size();
    auto      count = sv.size();
    if (m_storage.reserve(index + count + 1)) {
      m_storage.set_size(index + count);
      if (!sv.empty()) {
        ::portable_stl::memcpy((begin() + static_cast<difference_type>(index)).operator->(), sv.begin(), count);
        traits_type::assign(data()[index + count], value_type());
      }
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
    return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error>{
      ::portable_stl::ref(*this)};
  }

  /**
   * @brief Appends string str to the string.
   * The behavior is undefined if size() > max_size(), and exceptions is disabled.
   *
   * @throw portable_stl::length_error size() > max_size().
   * @param str String to append.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> append(basic_string const &str) {
    return append(view_type{str});
  }

  /**
   * @brief Appends a substring [pos, pos+count) of str to the string.
   * If the requested substring lasts past the end of the string, or if count == npos, the appended substring is [pos,
   * size()).
   * The behavior is undefined if pos > size(), or size() > max_size() with exceptions is disabled.
   *
   * @throw portable_stl::out_of_range if pos > size().
   * @throw portable_stl::length_error size() > max_size().
   * @param str String to append.
   * @param pos The index of the first character to append.
   * @param count Number of characters to append.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> append(
    basic_string const &str, size_type pos, size_type count = npos) {
    return view_type{str}.substr_safe(pos, count).and_then([this](view_type sv_sub) {
      return append(sv_sub);
    });
  }

  /**
   * @brief Appends characters in the range [cstr, cstr + count) to the string. This range can contain null characters.
   * The behavior is undefined if size() > max_size(), and exceptions is disabled.
   *
   * @throw portable_stl::length_error size() > max_size().
   * @param cstr Pointer to the character string to append.
   * @param count Number of characters to append.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> append(const_pointer cstr,
                                                                                             size_type     count) {
    return append(view_type{cstr, count});
  }

  /**
   * @brief Appends the null-terminated character string pointed to by cstr to the string.
   * The length of the string is determined by the first null character using traits_type::length(cstr).
   * The behavior is undefined if size() > max_size(), and exceptions is disabled.
   *
   * @param cstr Pointer to the character string to append.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   * @throw portable_stl::length_error size() > max_size().
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> append(const_pointer cstr) {
    return append(view_type{cstr});
  }

  /**
   * @brief Appends characters in the range [first, last) to the string.
   * The behavior is undefined if size() > max_size(), and exceptions is disabled.
   *
   * @tparam t_input_iterator Type like const_iterator.
   * @param first Begin range of the characters to append.
   * @param last End range of the characters to append.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   * @throw portable_stl::length_error size() > max_size().
   */
  template<class t_input_iterator,
           class t_iter_category = typename ::portable_stl::iterator_traits<t_input_iterator>::iterator_category,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::is_convertible<t_iter_category, ::portable_stl::input_iterator_tag>,
             void *>
           = nullptr>
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> append(t_input_iterator first,
                                                                                             t_input_iterator last) {
    return append(portable_stl::to_address(first), static_cast<size_type>(portable_stl::distance(first, last)));
  }

  /**
   * @brief Appends characters from the initializer list init_list to the string.
   * The behavior is undefined if size() > max_size(), and exceptions is disabled.
   *
   * @param init_list with the characters to append.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   * @throw portable_stl::length_error size() > max_size().
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> append(
    std::initializer_list<value_type> init_list) {
    return append(init_list.begin(), init_list.end());
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by view_type sv = sv_like,
   * then appends the characters from the subview [pos, pos+count) of sv to the string.
   * If the requested subview extends past the end of sv, or if count == npos, the appended subview is [pos, sv.size()).
   * The behavior is undefined if pos > size(), or size() > max_size(), with exceptions is disabled.
   *
   * @tparam t_string_view_like Type like view_type.
   * @param sv_like Object convertible to basic_string_view with the characters to append.
   * @param pos The index of the first character to append.
   * @param count Number of characters to append.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   * @throw portable_stl::out_of_range if pos > size().
   * @throw portable_stl::length_error size() > max_size().
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> append(
    t_string_view_like const &sv_like, size_type pos, size_type count = npos) {
    view_type sv = sv_like;
    return sv.substr_safe(pos, count).and_then([this](view_type sv_sub) {
      return append(sv_sub);
    });
  }

  /**
   * @brief Appends string str to the string.
   * The behavior is undefined if size() > max_size(), and exceptions is disabled.
   *
   * @param str String to append.
   * @return basic_string & *this.
   * @throw portable_stl::length_error size() > max_size().
   */
  basic_string &operator+=(basic_string const &str) {
    return append(str).value().get();
  }

  /**
   * @brief Appends character ch to the string.
   * The behavior is undefined if size() > max_size(), and exceptions is disabled.
   *
   * @param ch Character value to append.
   * @return basic_string & *this.
   * @throw portable_stl::length_error size() > max_size().
   */
  basic_string &operator+=(const_reference ch) {
    return append(1, ch).value().get();
  }

  /**
   * @brief Appends the null-terminated character string pointed to by cstr to the string.
   * The behavior is undefined if size() > max_size(), and exceptions is disabled.
   *
   * @param cstr Pointer to a null-terminated character string to append.
   * @return basic_string & *this.
   * @throw portable_stl::length_error size() > max_size().
   */
  basic_string &operator+=(const_pointer cstr) {
    return append(cstr).value().get();
  }

  /**
   * @brief Appends characters in the initializer list init_list to the string.
   * The behavior is undefined if size() > max_size(), and exceptions is disabled.
   *
   * @param init_list initializer_list with the characters to append.
   * @return basic_string & *this.
   * @throw portable_stl::length_error size() > max_size().
   */
  basic_string &operator+=(std::initializer_list<value_type> init_list) {
    return append(portable_stl::move(init_list)).value().get();
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by view_type sv = sv_like,
   * then appends characters in the string view sv to the string.
   * The behavior is undefined if size() > max_size(), and exceptions is disabled.
   *
   * @tparam t_string_view_like Type like view_type.
   * @param sv_like Object (convertible to view_type) with the characters to append.
   * @return basic_string & *this.
   * @throw portable_stl::length_error size() > max_size().
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  basic_string &operator+=(t_string_view_like const &sv_like) {
    return append(sv_like).value().get();
  }

  /**
   * @brief Replaces the part of the string indicated by either [pos, pos + count) or [first, last) with a new
   * string. The new string can be characters of a string view sv, converted from sv_like as if by view_type sv =
   * sv_like.
   *
   * @tparam t_string_view_like Type like view_type.
   * @param pos Start of the substring that is going to be replaced.
   * @param count Length of the substring that is going to be replaced.
   * @param sv_like Object (convertible to view_type) with the characters to use for replacement.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> replace(
    size_type pos, size_type count, t_string_view_like const &sv_like) noexcept {
    if (pos > size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::out_of_range};
    }
    view_type sv = sv_like;
    if (m_storage.replace(pos, ::portable_stl::min(count, size() - pos), sv.size())) {
      ::portable_stl::memcpy((begin() + static_cast<difference_type>(pos)).operator->(), sv.begin(), sv.size());
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
    return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error>{
      ::portable_stl::ref(*this)};
  }

  /**
   * @brief Replaces the part of the string indicated by either [pos, pos + count) or [first, last) with a new
   * string. The new string can be count2 copies of character ch.
   *
   * @param pos Start of the substring that is going to be replaced.
   * @param count Length of the substring that is going to be replaced.
   * @param count2 Number of characters to replace with.
   * @param ch Character value to use for replacement.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> replace(
    size_type pos, size_type count, size_type count2, const_reference ch) noexcept {
    if (pos > size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::out_of_range};
    }
    if (m_storage.replace(pos, ::portable_stl::min(count, size() - pos), count2)) {
      ::portable_stl::memset((begin() + static_cast<difference_type>(pos)).operator->(), ch, count2);
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
    return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error>{
      ::portable_stl::ref(*this)};
  }

  /**
   * @brief Replaces the part of the string indicated by either [pos, pos + count) or [first, last) with a new
   * string. The new string can be string str.
   *
   * @param pos Start of the substring that is going to be replaced.
   * @param count Length of the substring that is going to be replaced.
   * @param str String to use for replacement.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> replace(
    size_type pos, size_type count, basic_string const &str) noexcept {
    return replace(pos, count, view_type{str});
  }

  /**
   * @brief Replaces the part of the string indicated by either [pos, pos + count) or [first, last) with a new
   * string. The new string can be string str.
   *
   * @param first Begin range of characters that is going to be replaced.
   * @param last End range of characters that is going to be replaced.
   * @param str String to use for replacement.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> replace(
    const_iterator first, const_iterator last, basic_string const &str) noexcept {
    return replace(static_cast<size_type>(::portable_stl::distance(cbegin(), first)),
                   static_cast<size_type>(::portable_stl::distance(first, last)),
                   str);
  }

  /**
   * @brief Replaces the part of the string indicated by either [pos, pos + count) or [first, last) with a new
   * string. The new string can be substring [pos2, pos2 + count2) of str, except if count2==npos or if would extend
   * past str.size(), [pos2, str.size()) is used.
   *
   * @param pos Start of the substring that is going to be replaced.
   * @param count Length of the substring that is going to be replaced.
   * @param str String to use for replacement.
   * @param pos2 Start of the substring to replace with.
   * @param count2 Number of characters to replace with.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> replace(
    size_type pos, size_type count, basic_string const &str, size_type pos2, size_type count2 = npos) noexcept {
    return view_type{str}.substr_safe(pos2, count2).and_then([this, pos, count](view_type sv_sub) {
      return replace(pos, count, sv_sub);
    });
  }

  /**
   * @brief Replaces the part of the string indicated by either [pos, pos + count) or [first, last) with a new
   * string. The new string can be characters in the range [cstr, cstr + count2).
   *
   * @param pos Start of the substring that is going to be replaced.
   * @param count Length of the substring that is going to be replaced.
   * @param cstr Pointer to the character string to use for replacement.
   * @param count2 Number of characters to replace with.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> replace(
    size_type pos, size_type count, const_pointer cstr, size_type count2) noexcept {
    return replace(pos, count, view_type{cstr, count2});
  }

  /**
   * @brief Replaces the part of the string indicated by either [pos, pos + count) or [first, last) with a new
   * string. The new string can be characters in the range [cstr, cstr + count2).
   *
   * @param first Begin range of characters that is going to be replaced.
   * @param last End range of characters that is going to be replaced.
   * @param cstr Pointer to the character string to use for replacement.
   * @param count2 Number of characters to replace with.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> replace(
    const_iterator first, const_iterator last, const_pointer cstr, size_type count2) noexcept {
    return replace(static_cast<size_type>(::portable_stl::distance(cbegin(), first)),
                   static_cast<size_type>(::portable_stl::distance(first, last)),
                   view_type{cstr, count2});
  }

  /**
   * @brief Replaces the part of the string indicated by either [pos, pos + count) or [first, last) with a new
   * string. The new string can be characters in the range [cstr, cstr + traits_type::length(cstr)).
   *
   * @param pos Start of the substring that is going to be replaced.
   * @param count Length of the substring that is going to be replaced.
   * @param cstr Pointer to the character string to use for replacement.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> replace(
    size_type pos, size_type count, const_pointer cstr) noexcept {
    return replace(pos, count, view_type{cstr});
  }

  /**
   * @brief Replaces the part of the string indicated by either [pos, pos + count) or [first, last) with a new
   * string. The new string can be characters in the range [cstr, cstr + traits_type::length(cstr)).
   *
   * @param first Begin range of characters that is going to be replaced.
   * @param last End range of characters that is going to be replaced.
   * @param cstr Pointer to the character string to use for replacement.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> replace(
    const_iterator first, const_iterator last, const_pointer cstr) noexcept {
    return replace(static_cast<size_type>(::portable_stl::distance(cbegin(), first)),
                   static_cast<size_type>(::portable_stl::distance(first, last)),
                   view_type{cstr});
  }

  /**
   * @brief Replaces the part of the string indicated by either [pos, pos + count) or [first, last) with a new
   * string. The new string can be count2 copies of character ch.
   *
   * @param first Begin range of characters that is going to be replaced.
   * @param last End range of characters that is going to be replaced.
   * @param count2 Number of characters to replace with.
   * @param ch Character value to use for replacement.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> replace(
    const_iterator first, const_iterator last, size_type count2, const_reference ch) noexcept {
    return replace(static_cast<size_type>(::portable_stl::distance(cbegin(), first)),
                   static_cast<size_type>(::portable_stl::distance(first, last)),
                   count2,
                   ch);
  }

  /**
   * @brief Replaces the part of the string indicated by either [pos, pos + count) or [first, last) with a new
   * string. The new string can be characters in the range [first2, last2).
   *
   * @tparam t_input_iterator Type like const_iterator.
   * @param first Begin range of characters that is going to be replaced.
   * @param last End range of characters that is going to be replaced.
   * @param first2 Begin range of characters to use for replacement.
   * @param last2 End range of characters to use for replacement.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  template<class t_input_iterator,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::cpp17_input_iterator<t_input_iterator>, void *>
           = nullptr>
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> replace(
    const_iterator first, const_iterator last, t_input_iterator first2, t_input_iterator last2) noexcept {
    return replace(static_cast<size_type>(::portable_stl::distance(cbegin(), first)),
                   static_cast<size_type>(::portable_stl::distance(first, last)),
                   view_type{first2, last2});
  }

  /**
   * @brief Replaces the part of the string indicated by either [pos, pos + count) or [first, last) with a new
   * string. The new string can be characters in the initializer list init_list.
   *
   * @param first Begin range of characters that is going to be replaced.
   * @param last End range of characters that is going to be replaced.
   * @param init_list initializer list with the characters to use for replacement.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> replace(
    const_iterator first, const_iterator last, std::initializer_list<value_type> init_list) noexcept {
    return replace(static_cast<size_type>(::portable_stl::distance(cbegin(), first)),
                   static_cast<size_type>(::portable_stl::distance(first, last)),
                   view_type{init_list.begin(), init_list.end()});
  }

  /**
   * @brief Replaces the part of the string indicated by either [pos, pos + count) or [first, last) with a new
   * string. The new string can be characters of a string view sv, converted from sv_like as if by view_type sv =
   * sv_like.
   *
   * @tparam t_string_view_like Type like view_type.
   * @param first Begin range of characters that is going to be replaced.
   * @param last End range of characters that is going to be replaced.
   * @param sv_like Object (convertible to view_type) with the characters to use for replacement.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> replace(
    const_iterator first, const_iterator last, t_string_view_like const &sv_like) noexcept {
    return replace(static_cast<size_type>(::portable_stl::distance(cbegin(), first)),
                   static_cast<size_type>(::portable_stl::distance(first, last)),
                   sv_like);
  }

  /**
   * @brief Replaces the part of the string indicated by either [pos, pos + count) or [first, last) with a new
   * string. The new string can be subview [pos2, pos2 + count2) of a string view sv, converted from sv_like as if by
   * view_type sv = sv_like, except if count2==npos or if it would extend past sv.size(), [pos2, sv.size()) is used.
   *
   * @tparam t_string_view_like Type like view_type.
   * @param pos Start of the substring that is going to be replaced.
   * @param count Length of the substring that is going to be replaced.
   * @param sv_like Object (convertible to view_type) with the characters to use for replacement.
   * @param pos2 Start of the substring to replace with.
   * @param count2 Number of characters to replace with.
   * @return ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> *this.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  ::portable_stl::expected<string_reference_wrap, ::portable_stl::portable_stl_error> replace(
    size_type                 pos,
    size_type                 count,
    t_string_view_like const &sv_like,
    size_type                 pos2,
    size_type                 count2 = npos) noexcept {
    view_type sv = sv_like;
    return sv.substr_safe(pos2, count2).and_then([this, pos, count](view_type sv_sub) {
      return replace(pos, count, sv_sub);
    });
  }

  /**
   * @brief Copies a substring [pos, pos+count) to character string pointed to by dest.
   * If the requested substring lasts past the end of the string, or if count == npos,
   * the copied substring is [pos, size()).
   * The resulting character string is not null-terminated.
   * The behavior is undefined if pos > size(), and exceptions is disabled.
   *
   * @param dest Pointer to the destination character string.
   * @param count Requested substring length.
   * @param pos Position of the first character.
   * @return ::portable_stl::expected<size_type, ::portable_stl::portable_stl_error> Number of characters copied.
   */
  ::portable_stl::expected<size_type, ::portable_stl::portable_stl_error> copy(
    pointer dest, size_type count, size_type pos = 0) const {
    return view_type{*this}.copy(dest, count, pos);
  }

  /**
   * @brief Resizes the string to contain count characters.
   * If the current size is less than count, additional characters are appended value_type{}.
   * If the current size is greater than count, the string is reduced to its first count elements.
   *
   * @param count New size of the string.
   * @return true if successful,
   * @return false otherwise.
   */
  bool resize(size_type count) {
    auto const old_size = m_storage.size();
    // we need space for 'count' symbols + '\0'
    if (m_storage.reserve(count + 1)) {
      m_storage.set_size(count);
      if (count > old_size) {
        static_cast<void>(traits_type::assign(
          ::portable_stl::to_address(m_storage.data() + old_size), count - old_size + 1, value_type{}));
      } else if (count < old_size) {
        // if reduce size, insert terminated '\0'
        static_cast<void>(traits_type::assign(::portable_stl::to_address(m_storage.data() + count), 1, value_type{}));
      }
      return true;
    }
    return false;
  }

  /**
   * @brief Resizes the string to contain count characters.
   * If the current size is less than count, additional characters are appended ch{}.
   * If the current size is greater than count, the string is reduced to its first count elements.
   *
   * @param count New size of the string.
   * @param ch Character to initialize the new characters with.
   * @return true if successful,
   * @return false otherwise.
   */
  bool resize(size_type count, const_reference ch) {
    auto const old_size = m_storage.size();
    // we need space for 'count' symbols + '\0'
    if (m_storage.reserve(count + 1)) {
      m_storage.set_size(count);
      if (count > old_size) {
        static_cast<void>(
          traits_type::assign(::portable_stl::to_address(m_storage.data() + old_size), count - old_size, ch));
      }
      if (count != old_size) {
        // insert terminated '\0'
        static_cast<void>(traits_type::assign(::portable_stl::to_address(m_storage.data() + count), 1, value_type{}));
      }
      return true;
    }
    return false;
  }

  /**
   * @brief Resizes the string to contain at most count characters,
   * using the user-provided operation op to modify the possibly indeterminate
   * contents and set the length.
   * This avoids the cost of initializing a suitably-sized ::portable_stl::basic_string
   * when it is intended to be used as a char array to be populated by, e.g., a C API call.
   *
   * @tparam t_operation Type of function.
   * @param count The maximal possible new size of the string.
   * @param op The function object used for setting the new contents of the string.
   * @return true if successful,
   * @return false otherwise.
   */
  template<class t_operation> bool resize_and_overwrite(size_type count, t_operation op) {
    auto old_size = m_storage.size();
    bool result{false};
    if (m_storage.reserve(count + 1)) {
      m_storage.set_size(count);
      result = true;
      if (count > old_size) {
        count  = op(begin() + static_cast<difference_type>(old_size), count - old_size);
        result = m_storage.reserve(count + 1);
        if (result) {
          m_storage.set_size(count);
        }
      }
      if (result) {
        static_cast<void>(traits_type::assign(::portable_stl::to_address(m_storage.data() + count), 1, value_type{}));
      }
      return result;
    }
    return false;
  }

  /**
   * @brief Exchanges the contents of the string with those of other.
   * All iterators and references may be invalidated.
   *
   * @param other String to exchange the contents with.
   */
  void swap(basic_string &other) noexcept(
    typename ::portable_stl::allocator_traits<allocator_type>::propagate_on_container_swap{}() ||
    typename ::portable_stl::allocator_traits<allocator_type>::is_always_equal{}()) {
    m_storage.swap(other.m_storage);
  }

  // [search]

  /**
   * @brief Finds the first substring equal to the given character sequence.
   * Search begins at pos, i.e. the found substring must not begin in a position preceding pos.
   * Finds the first substring equal to str.
   *
   * @param str String to search for.
   * @param pos Position at which to start the search.
   * @return size_type Position of the first character of the found substring or npos if no such substring is found.
   */
  constexpr size_type find(basic_string const &str, size_type pos = 0) const noexcept {
    return view_type{*this}.find(str, pos);
  }

  /**
   * @brief Finds the first substring equal to the given character sequence.
   * Search begins at pos, i.e. the found substring must not begin in a position preceding pos.
   * Finds the first substring equal to the range [cstr, cstr+count). This range may contain null characters.
   *
   * @param cstr Pointer to a character string to search for.
   * @param pos Position at which to start the search.
   * @param count Length of substring to search for.
   * @return size_type Position of the first character of the found substring or npos if no such substring is found.
   */
  constexpr size_type find(const_pointer cstr, size_type pos, size_type count) const {
    return view_type{*this}.find(cstr, pos, count);
  }

  /**
   * @brief Finds the first substring equal to the given character sequence.
   * Search begins at pos, i.e. the found substring must not begin in a position preceding pos.
   * Finds the first substring equal to the character string pointed to by cstr.
   * The length of the string is determined by the first null character using traits_type::length(s).
   *
   * @param cstr Pointer to a character string to search for.
   * @param pos Position at which to start the search.
   * @return size_type Position of the first character of the found substring or npos if no such substring is found.
   */
  constexpr size_type find(const_pointer cstr, size_type pos = 0) const {
    return view_type{*this}.find(cstr, pos);
  }

  /**
   * @brief Finds the first substring equal to the given character sequence.
   * Search begins at pos, i.e. the found substring must not begin in a position preceding pos.
   * Finds the first character ch (treated as a single-character substring by the formal rules below).
   *
   * @param ch Character to search for.
   * @param pos Position at which to start the search.
   * @return size_type Position of the first character of the found substring or npos if no such substring is found.
   */
  constexpr size_type find(const_reference ch, size_type pos = 0) const noexcept {
    return view_type{*this}.find(ch, pos);
  }

  /**
   * @brief Finds the first substring equal to the given character sequence.
   * Search begins at pos, i.e. the found substring must not begin in a position preceding pos.
   * Implicitly converts sv_like to a string view sv as if by view_type sv = sv_like, then finds the first substring
   * equal to sv.
   *
   * @param sv_like Object (convertible to view_type) to search for.
   * @param pos Position at which to start the search.
   * @return size_type Position of the first character of the found substring or npos if no such substring is found.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  constexpr size_type find(t_string_view_like const &sv_like, size_type pos = 0) const
    noexcept(::portable_stl::is_nothrow_convertible<t_string_view_like const &, view_type>{}()) {
    return view_type{*this}.find(sv_like, pos);
  }

  /**
   * @brief Finds the last substring equal to str. The search begins at pos and proceeds from right to left (thus, the
   * found substring, if any, cannot begin in a position following pos). If npos or any value not smaller than size() -
   * 1 is passed as pos, the whole string will be searched.
   *
   * @param str String to search for.
   * @param pos Position at which to begin searching.
   * @return size_type Position of the first character of the found substring or npos if no such substring is
   * found.
   */
  constexpr size_type rfind(basic_string const &str, size_type pos = npos) const noexcept {
    return view_type{*this}.rfind(str, pos);
  }

  /**
   * @brief Finds the last substring equal to the range [cstr, cstr + count). This range can include null characters. If
   * [s, s
   * + count) is not a valid range, the behavior is undefined. The search begins at pos and proceeds from right to left
   * (thus, the found substring, if any, cannot begin in a position following pos). If npos or any value not smaller
   * than size() - 1 is passed as pos, the whole string will be searched.
   *
   * @param cstr Pointer to a character string to search for.
   * @param pos Position at which to begin searching.
   * @param count Length of substring to search for.
   * @return size_type Position of the first character of the found substring or npos if no such substring is
   * found.
   */
  constexpr size_type rfind(const_pointer cstr, size_type pos, size_type count) const {
    return view_type{*this}.rfind(cstr, pos, count);
  }

  /**
   * @brief Finds the last substring equal to the character string pointed to by s. The length of the string is
   * determined by the first null character using t_char_traits::length(s). The search begins at pos and proceeds from
   * right to left (thus, the found substring, if any, cannot begin in a position following pos). If npos or any value
   * not smaller than size() - 1 is passed as pos, the whole string will be searched.
   *
   * @param cstr Pointer to a character string to search for.
   * @param pos Position at which to begin searching.
   * @return size_type Position of the first character of the found substring or npos if no such substring is
   * found.
   */
  constexpr size_type rfind(const_pointer cstr, size_type pos = npos) const {
    return view_type{*this}.rfind(cstr, pos);
  }

  /**
   * @brief Finds the last character equal to ch. The search begins at pos and proceeds from right to left (thus, the
   * found substring, if any, cannot begin in a position following pos). If npos or any value not smaller than size() -
   * 1 is passed as pos, the whole string will be searched.
   *
   * @param ch Character to search for.
   * @param pos Position at which to begin searching.
   * @return size_type Position of the first character of the found substring or npos if no such substring is
   * found.
   */
  constexpr size_type rfind(const_reference ch, size_type pos = npos) const noexcept {
    return view_type{*this}.rfind(ch, pos);
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by ::basic_string_view<t_char_type, t_char_traits> sv
   * = sv_like, then finds the last substring equal to the contents of sv. The search begins at pos and proceeds from
   * right to left (thus, the found substring, if any, cannot begin in a position following pos). If npos or any value
   * not smaller than size() - 1 is passed as pos, the whole string will be searched.
   *
   * @tparam t_string_view_like Type like view_type.
   * @param sv_like Object (convertible to view_type) to search for.
   * @param pos Position at which to begin searching.
   * @return size_type Position of the first character of the found substring or npos if no such substring is
   * found.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  constexpr size_type rfind(t_string_view_like const &sv_like, size_type pos = npos) const
    noexcept(::portable_stl::is_nothrow_convertible<t_string_view_like const &, view_type>{}()) {
    return view_type{*this}.rfind(sv_like, pos);
  }

  /**
   * @brief Finds the first character equal to one of the characters in str. The search considers only the range [pos,
   * size()). If none of the characters in the given character sequence is present in the range, npos will be returned.
   *
   * @param cstr Pointer to a character string to search for.
   * @param pos Position at which to begin searching.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  constexpr size_type find_first_of(basic_string const &str, size_type pos = 0U) const noexcept {
    return view_type{*this}.find_first_of(str, pos);
  }

  /**
   * @brief Finds the first character equal to one of the characters in the range [cstr, cstr + count). This range can
   * include null characters. The search considers only the range [pos, size()). If none of the characters in the given
   * character sequence is present in the range, npos will be returned.
   *
   * @param cstr Pointer to a character string to search for.
   * @param pos Position at which to begin searching.
   * @param count Length of substring to search for.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  constexpr size_type find_first_of(const_pointer cstr, size_type pos, size_type count) const {
    return view_type{*this}.find_first_of(cstr, pos, count);
  }

  /**
   * @brief Finds the first character equal to one of the characters in character string pointed to by s. The length of
   * the string is determined by the first null character using t_char_traits::length(s). The search considers only the
   * range [pos, size()). If none of the characters in the given character sequence is present in the range, npos will
   * be returned.
   *
   * @param cstr Pointer to a character string to search for.
   * @param pos Position at which to begin searching.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  constexpr size_type find_first_of(const_pointer cstr, size_type pos = 0U) const {
    return view_type{*this}.find_first_of(cstr, pos);
  }

  /**
   * @brief Finds the first character equal to ch. The search considers only the range [pos, size()). If none of the
   * characters in the given character sequence is present in the range, npos will be returned.
   *
   * @param ch Character to search for.
   * @param pos Position at which to begin searching.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  constexpr size_type find_first_of(const_reference ch, size_type pos = 0U) const noexcept {
    return view_type{*this}.find_first_of(ch, pos);
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by basic_string_view<t_char_type, t_char_traits>
   * sv = sv_like, then finds the first character equal to one of the characters in sv. The search considers only the
   * range [pos, size()). If none of the characters in the given character sequence is present in the range, npos will
   * be returned.
   *
   * @tparam t_string_view_like Type like view_type.
   * @param sv_like Object (convertible to view_type) to search for.
   * @param pos Position at which to begin searching.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  constexpr size_type find_first_of(t_string_view_like const &sv_like, size_type pos = 0U) const
    noexcept(::portable_stl::is_nothrow_convertible<t_string_view_like const &, view_type>{}()) {
    return view_type{*this}.find_first_of(sv_like, pos);
  }

  /**
   * @brief Finds the first character equal to none of characters in str. The search considers only the range [pos,
   * size()). If all characters in the range can be found in the given character sequence, npos will be returned.
   *
   * @param cstr Pointer to a character string to search for.
   * @param pos Position at which to begin searching.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  constexpr size_type find_first_not_of(basic_string const &str, size_type pos = 0U) const noexcept {
    return view_type{*this}.find_first_not_of(str, pos);
  }

  /**
   * @brief Finds the first character equal to none of characters in range [cstr, cstr + count). This range can include
   * null characters. The search considers only the range [pos, size()). If all characters in the range can be found in
   * the given character sequence, npos will be returned.
   *
   * @param cstr Pointer to a character string to search for.
   * @param pos Position at which to begin searching.
   * @param count Length of substring to search for.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  constexpr size_type find_first_not_of(const_pointer cstr, size_type pos, size_type count) const {
    return view_type{*this}.find_first_not_of(cstr, pos, count);
  }

  /**
   * @brief Finds the first character equal to none of characters in character string pointed to by s. The length of the
   * string is determined by the first null character using t_char_traits::length(s). The search considers only the
   * range [pos, size()). If all characters in the range can be found in the given character sequence, npos will be
   * returned.
   *
   * @param cstr Pointer to a character string to search for.
   * @param pos Position at which to begin searching.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  constexpr size_type find_first_not_of(const_pointer cstr, size_type pos = 0U) const {
    return view_type{*this}.find_first_not_of(cstr, pos);
  }

  /**
   * @brief Finds the first character not equal to ch. The search considers only the range [pos, size()). If all
   * characters in the range can be found in the given character sequence, npos will be returned.
   *
   * @param ch Character to search for.
   * @param pos Position at which to begin searching.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  constexpr size_type find_first_not_of(const_reference ch, size_type pos = 0U) const noexcept {
    return view_type{*this}.find_first_not_of(ch, pos);
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by basic_string_view<t_char_type, t_char_traits>
   * sv = sv_like, then finds the first character equal to none of characters in sv. The search considers only the range
   * [pos, size()). If all characters in the range can be found in the given character sequence, npos will be returned.
   *
   * @tparam t_string_view_like Type like view_type.
   * @param sv_like Object (convertible to view_type) to search for.
   * @param pos Position at which to begin searching.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  constexpr size_type find_first_not_of(t_string_view_like const &sv_like, size_type pos = 0U) const
    noexcept(::portable_stl::is_nothrow_convertible<t_string_view_like const &, view_type>{}()) {
    return view_type{*this}.find_first_not_of(sv_like, pos);
  }

  /**
   * @brief Finds the last character equal to one of characters in str. The exact search algorithm is not specified. The
   * search considers only the range [​0​, pos]. If none of the characters in the given character sequence is
   * present in the range, npos will be returned.
   *
   * @param cstr Pointer to a character string to search for.
   * @param pos Position at which the search is to finish.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  constexpr size_type find_last_of(basic_string const &str, size_type pos = npos) const noexcept {
    return view_type{*this}.find_last_of(str, pos);
  }

  /**
   * @brief Finds the last character equal to one of characters in range [cstr, cstr + count). This range can include
   * null characters. The exact search algorithm is not specified. The search considers only the range [​0​, pos].
   * If none of the characters in the given character sequence is present in the range, npos will be returned.
   *
   * @param cstr Pointer to a character string to search for.
   * @param pos Position at which the search is to finish.
   * @param count Length of substring to search for.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  constexpr size_type find_last_of(const_pointer cstr, size_type pos, size_type count) const {
    return view_type{*this}.find_last_of(cstr, pos, count);
  }

  /**
   * @brief Finds the last character equal to one of characters in character string pointed to by s. The length of the
   * string is determined by the first null character using t_char_traits::length(s). The exact search algorithm is not
   * specified. The search considers only the range [​0​, pos]. If none of the characters in the given character
   * sequence is present in the range, npos will be returned.
   *
   * @param cstr Pointer to a character string to search for.
   * @param pos Position at which the search is to finish.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  constexpr size_type find_last_of(const_pointer cstr, size_type pos = npos) const {
    return view_type{*this}.find_last_of(cstr, pos);
  }

  /**
   * @brief Finds the last character equal to ch. The exact search algorithm is not specified. The search considers only
   * the range [​0​, pos]. If none of the characters in the given character sequence is present in the range, npos
   * will be returned.
   *
   * @param ch Character to search for.
   * @param pos Position at which the search is to finish.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  constexpr size_type find_last_of(const_reference ch, size_type pos = npos) const noexcept {
    return view_type{*this}.find_last_of(ch, pos);
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by basic_string_view<t_char_type, t_char_traits>
   sv = sv_like, then finds the last character equal to one of characters in sv. The exact search algorithm is not
   specified. The search considers only the range [​0​, pos]. If none of the characters in the given character
   sequence is present in the range, npos will be returned.

   *
   * @tparam t_string_view_like Type like view_type.
   * @param sv_like Object (convertible to view_type) to search for.
   * @param pos Position at which the search is to finish.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  constexpr size_type find_last_of(t_string_view_like const &sv_like, size_type pos = npos) const
    noexcept(::portable_stl::is_nothrow_convertible<t_string_view_like const &, view_type>{}()) {
    return view_type{*this}.find_last_of(sv_like, pos);
  }

  /**
   * @brief Finds the last character equal to none of characters in str. The search considers only the range [​0​,
   * pos]. If all characters in the range can be found in the given character sequence, npos will be returned.
   *
   * @param cstr Pointer to a character string to search for.
   * @param pos Position at which the search is to finish.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  constexpr size_type find_last_not_of(basic_string const &str, size_type pos = npos) const noexcept {
    return view_type{*this}.find_last_not_of(str, pos);
  }

  /**
   * @brief Finds the last character equal to none of characters in the range [cstr, cstr + count). This range can
   * include null characters. The search considers only the range [​0​, pos]. If all characters in the range can be
   * found in the given character sequence, npos will be returned.
   *
   * @param cstr Pointer to a character string to search for.
   * @param pos Position at which the search is to finish.
   * @param count Length of substring to search for.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  constexpr size_type find_last_not_of(const_pointer cstr, size_type pos, size_type count) const {
    return view_type{*this}.find_last_not_of(cstr, pos, count);
  }

  /**
   * @brief Finds the last character equal to none of characters in character string pointed to by s. The length of the
   * string is determined by the first null character using t_char_traits::length(s). The search considers only the
   * range [​0​, pos]. If all characters in the range can be found in the given character sequence, npos will be
   * returned.
   *
   * @param cstr Pointer to a character string to search for.
   * @param pos Position at which the search is to finish.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  constexpr size_type find_last_not_of(const_pointer cstr, size_type pos = npos) const {
    return view_type{*this}.find_last_not_of(cstr, pos);
  }

  /**
   * @brief Finds the last character not equal to ch. The search considers only the range [​0​, pos]. If all
   * characters in the range can be found in the given character sequence, npos will be returned.
   *
   * @param ch Character to search for.
   * @param pos Position at which the search is to finish.
   * @return size_type Position of the found character or npos if no such character is found.
   */
  constexpr size_type find_last_not_of(const_reference ch, size_type pos = npos) const noexcept {
    return view_type{*this}.find_last_not_of(ch, pos);
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by basic_string_view<t_char_type, t_char_traits>
   * sv = sv_like, then finds the last character equal to none of characters in sv. The search considers only the range
   * [​0​, pos]. If all characters in the range can be found in the given character sequence, npos will be returned.
   *
   * @tparam t_string_view_like Type like view_type.
   * @param sv_like Object (convertible to view_type) to search for.
   * @param pos Position at which the search is to finish.
   * @return size_type
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  constexpr size_type find_last_not_of(t_string_view_like const &sv_like, size_type pos = npos) const
    noexcept(::portable_stl::is_nothrow_convertible<t_string_view_like const &, view_type>{}()) {
    return view_type{*this}.find_last_not_of(sv_like, pos);
  }

  // [operations]

  /**
   * @brief Compares this string to other string str.
   *
   * @param str Other string to compare to.
   * @return ::portable_stl::int32_t Status of compare.
   * @retval Negative value if *this appears before the character sequence
   * specified by the arguments, in lexicographical order.
   * @retval Zero if both character sequences compare equivalent.
   * @retval Positive value if *this appears after the character sequence
   * specified by the arguments, in lexicographical order.
   */
  ::portable_stl::int32_t compare(basic_string const &str) const noexcept {
    return view_type{*this}.compare(view_type{str});
  }

  /**
   * @brief Compares a [pos1, pos1+count1) substring of this string to str.
   * If count1 > size() - pos1 the substring is [pos1, size()).
   *
   * @param pos1 Position of the first character in this string to compare.
   * @param count1 Number of characters of this string to compare.
   * @param str Other string to compare to.
   * @return ::portable_stl::expected<::portable_stl::int32_t, ::portable_stl::portable_stl_error> Status of compare.
   * @retval Negative value if *this appears before the character sequence specified by the arguments, in
   * lexicographical order.
   * @retval Zero if both character sequences compare equivalent.
   * @retval Positive value if *this appears after the character sequence specified by the arguments, in lexicographical
   * order.
   * @retval portable_stl_error, if out of range.
   */
  ::portable_stl::expected<::portable_stl::int32_t, ::portable_stl::portable_stl_error> compare(
    size_type pos1, size_type count1, basic_string const &str) const {
    return view_type{*this}.compare(pos1, count1, view_type{str});
  }

  /**
   * @brief Compares a [pos1, pos1+count1) substring of this string to a substring [pos2, pos2+count2) of str.
   * If count1 > size() - pos1 the first substring is [pos1, size()).
   * Likewise, count2 > str.size() - pos2 the second substring is [pos2, str.size()).
   *
   * @param pos1 Position of the first character in this string to compare.
   * @param count1 Number of characters of this string to compare.
   * @param str Other string to compare to.
   * @param pos2 Position of the first character of the given string to compare.
   * @param count2 Number of characters of the given string to compare.
   * @return ::portable_stl::expected<::portable_stl::int32_t, ::portable_stl::portable_stl_error> Status of compare.
   * @retval Negative value if *this appears before the character sequence specified by the arguments, in
   * lexicographical order.
   * @retval Zero if both character sequences compare equivalent.
   * @retval Positive value if *this appears after the character sequence specified by the arguments, in lexicographical
   * order.
   * @retval portable_stl_error, if out of range.
   */
  ::portable_stl::expected<::portable_stl::int32_t, ::portable_stl::portable_stl_error> compare(
    size_type pos1, size_type count1, basic_string const &str, size_type pos2, size_type count2 = npos) const {
    return view_type{*this}.compare(pos1, count1, view_type{str}, pos2, count2);
  }

  /**
   * @brief Compares two character sequences.
   * Compares this string to the null-terminated character sequence beginning at the character pointed to by cstr with
   * length traits_type::length(cstr).
   *
   * @param cstr Pointer to the character string to compare to.
   * @return ::portable_stl::int32_t Status of compare.
   * @retval Negative value if *this appears before the character sequence specified by the arguments, in
   * lexicographical order.
   * @retval Zero if both character sequences compare equivalent.
   * @retval Positive value if *this appears after the character sequence specified by the arguments, in lexicographical
   * order.
   */
  ::portable_stl::int32_t compare(const_pointer cstr) const {
    return view_type{*this}.compare(cstr);
  }

  /**
   * @brief Compares a [pos1, pos1+count1) substring of this string to the null-terminated character sequence beginning
   * at the character pointed to by cstr with length traits_type::length(cstr). If count1 > size() - pos1 the substring
   * is [pos1, size()).
   *
   * @param pos1 Position of the first character in this string to compare.
   * @param count1 Number of characters of this string to compare.
   * @param cstr Pointer to the character string to compare to.
   * @return Status of compare.
   * @retval Negative value if *this appears before the character sequence specified by the arguments, in
   * lexicographical order.
   * @retval Zero if both character sequences compare equivalent.
   * @retval Positive value if *this appears after the character sequence specified by the arguments, in lexicographical
   * order.
   * @retval Portable_stl_error, if out of range.
   */
  ::portable_stl::expected<::portable_stl::int32_t, ::portable_stl::portable_stl_error> compare(
    size_type pos1, size_type count1, const_pointer cstr) const {
    return view_type{*this}.compare(pos1, count1, cstr);
  }

  /**
   * @brief Compares a [pos1, pos1+count1) substring of this string to the characters in the range [cstr, cstr +
   * count2). If count1 > size() - pos1 the substring is [pos1, size()). (Note: the characters in the range [cstr, cstr
   * + count2) may include null characters.)
   *
   * @param pos1 Position of the first character in this string to compare.
   * @param count1 Number of characters of this string to compare.
   * @param cstr Pointer to the character string to compare to.
   * @param count2 Number of characters of the given string to compare.
   * @return Status of compare.
   * @retval Negative value if *this appears before the character sequence specified by the arguments, in
   * lexicographical order.
   * @retval Zero if both character sequences compare equivalent
   * @retval Positive value if *this appears after the character sequence specified by the arguments, in lexicographical
   * order.
   * @retval portable_stl_error, if out of range.
   */
  ::portable_stl::expected<::portable_stl::int32_t, ::portable_stl::portable_stl_error> compare(
    size_type pos1, size_type count1, const_pointer s, size_type count2) const {
    return view_type{*this}.compare(pos1, count1, s, count2);
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by view_type sv = sv_like, then compares this string
   * to sv.
   *
   * @tparam t_string_view_like Type like view_type.
   * @param sv_like Object (convertible to view_type) to compare to.
   * @return ::portable_stl::int32_t Status of compare.
   * @retval Negative value if *this appears before the character sequence specified by the arguments, in
   * lexicographical order.
   * @retval Zero if both character sequences compare equivalent.
   * @retval Positive value if *this appears after the character sequence specified by the arguments, in lexicographical
   * order.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  ::portable_stl::int32_t compare(t_string_view_like const &sv_like) const
    noexcept(::portable_stl::is_nothrow_convertible<t_string_view_like const &, view_type>{}()) {
    return view_type{*this}.compare(sv_like);
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by view_type sv = sv_like, then compares a [pos1,
   * pos1+count1) substring of this string to sv.
   *
   * @tparam t_string_view_like Type like view_type.
   * @param pos1 Position of the first character in this string to compare.
   * @param count1 Number of characters of this string to compare.
   * @param sv_like Object (convertible to view_type) to compare to.
   * @return ::portable_stl::expected<::portable_stl::int32_t, ::portable_stl::portable_stl_error> Status of compare.
   * @retval Negative value if *this appears before the character sequence specified by the arguments, in
   * lexicographical order.
   * @retval Zero if both character sequences compare equivalent.
   * @retval Positive value if *this appears after the character sequence specified by the arguments, in lexicographical
   * order.
   * @retval portable_stl_error, if out of range.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  ::portable_stl::expected<::portable_stl::int32_t, ::portable_stl::portable_stl_error> compare(
    size_type pos1, size_type count1, t_string_view_like const &sv_like) const {
    return view_type{*this}.compare(pos1, count1, sv_like);
  }

  /**
   * @brief Implicitly converts sv_like to a string view sv as if by view_type sv = sv_like, then compares a [pos1,
   * pos1+count1) substring of this string to a substring [pos2, pos2+count2) of sv.
   *
   * @tparam t_string_view_like Type like view_type.
   * @param pos1 Position of the first character in this string to compare.
   * @param count1 Number of characters of this string to compare.
   * @param sv_like Object (convertible to view_type) to compare to.
   * @param pos2 Position of the first character of the given string to compare.
   * @param count2 Number of characters of the given string to compare.
   * @return ::portable_stl::expected<::portable_stl::int32_t, ::portable_stl::portable_stl_error> Status of compare.
   * @retval Negative value if *this appears before the character sequence specified by the arguments, in
   * lexicographical order.
   * @retval Zero if both character sequences compare equivalent.
   * @retval Positive value if *this appears after the character sequence specified by the arguments, in lexicographical
   * order.
   * @retval portable_stl_error, if out of range.
   */
  template<class t_string_view_like, enable_if_can_be_converted_to_string_view<t_string_view_like> = nullptr>
  ::portable_stl::expected<::portable_stl::int32_t, ::portable_stl::portable_stl_error> compare(
    size_type pos1, size_type count1, t_string_view_like const &sv_like, size_type pos2, size_type count2 = npos)
    const {
    return view_type{*this}.compare(pos1, count1, sv_like, pos2, count2);
  }

  /**
   * @brief Checks if the string begins with the given prefix a string view sv
   * (which may be a result of implicit conversion from another ::portable_stl::basic_string).
   *
   * @param sv A string view which may be a result of implicit conversion from another ::portable_stl::basic_string.
   * @retval true if the string begins with the provided prefix,
   * @retval false if the string not begins with the provided prefix.
   */
  constexpr bool starts_with(view_type const &sv) const noexcept {
    return view_type{*this}.starts_with(sv);
  }

  /**
   * @brief Checks if the string begins with the given prefix a single character ch.
   *
   * @param ch A single character.
   * @retval true if the string begins with the provided prefix,
   * @retval false if the string not begins with the provided prefix.
   */
  constexpr bool starts_with(const_reference ch) const noexcept {
    return view_type{*this}.starts_with(ch);
  }

  /**
   * @brief Checks if the string begins with the given prefix a null-terminated character string cstr.
   *
   * @param cstr A null-terminated character string.
   * @retval true if the string begins with the provided prefix,
   * @retval false if the string not begins with the provided prefix.
   */
  constexpr bool starts_with(const_pointer cstr) const {
    return view_type{*this}.starts_with(cstr);
  }

  /**
   * @brief Checks if the string ends with the given suffix a string view sv
   * (which may be a result of implicit conversion from another ::portable_stl::basic_string).
   *
   * @param sv A string view which may be a result of implicit conversion from another ::portable_stl::basic_string.
   * @retval true if the string ends with the provided suffix,
   * @retval false if the string not ends with the provided suffix.
   */
  constexpr bool ends_with(view_type sv) const noexcept {
    return view_type{*this}.ends_with(sv);
  }

  /**
   * @brief Checks if the string ends with the given suffix a single character ch.
   *
   * @param ch a single character.
   * @retval true if the string ends with the provided suffix,
   * @retval false if the string not ends with the provided suffix.
   */
  constexpr bool ends_with(const_reference ch) const noexcept {
    return view_type{*this}.ends_with(ch);
  }

  /**
   * @brief Checks if the string ends with the given suffix a null-terminated character string cstr.
   *
   * @param cstr a null-terminated character string.
   * @retval true if the string ends with the provided suffix,
   * @retval false if the string not ends with the provided suffix.
   */
  constexpr bool ends_with(const_pointer cstr) const {
    return view_type{*this}.ends_with(cstr);
  }

  /**
   * @brief Checks if the string contains the given substring a string view sv
   * (which may be a result of implicit conversion from another ::portable_stl::basic_string).
   *
   * @param sv A string view which may be a result of implicit conversion from another ::portable_stl::basic_string.
   * @retval true if the string contains the provided substring,
   * @retval false if the string not contains the provided substring.
   */
  constexpr bool contains(view_type sv) const noexcept {
    return view_type{*this}.contains(sv);
  }

  /**
   * @brief Checks if the string contains the given substring a single character ch.
   *
   * @param ch a single character.
   * @retval true if the string contains the provided substring,
   * @retval false if the string not contains the provided substring.
   */
  constexpr bool contains(const_reference ch) const noexcept {
    return view_type{*this}.contains(ch);
  }

  /**
   * @brief Checks if the string contains the given substring a null-terminated character string cstr.
   *
   * @param cstr a null-terminated character string.
   * @retval true if the string contains the provided substring,
   * @retval false if the string not contains the provided substring.
   */
  constexpr bool contains(const_pointer cstr) const {
    return view_type{*this}.contains(cstr);
  }

  /**
   * @brief Returns a substring [pos, pos+count).
   * If the requested substring extends past the end of the string, i.e.
   * the count is greater than size() - pos (e.g. if count == npos),
   * the returned substring is [pos, size()).
   * The behavior is undefined if pos > size(), and exceptions is disabled.
   *
   * @throw ::portable_stl::bad_alloc if allocation for copy unsuccessful.
   * @param pos Position of the first character to include.
   * @param count Length of the substring.
   * @return basic_string String containing the substring [pos, pos+count) or [pos, size()).
   */
  constexpr basic_string substr(size_type pos = 0, size_type count = npos) const & {
    return basic_string{view_type{*this}.substr(pos, count)};
  }

  /**
   * @brief Returns a substring [pos, pos+count).
   * If the requested substring extends past the end of the string, i.e.
   * the count is greater than size() - pos (e.g. if count == npos),
   * the returned substring is [pos, size()).
   * The behavior is undefined if pos > size(), and exceptions is disabled.
   *
   * @throw ::portable_stl::bad_alloc if allocation for copy unsuccessful.
   * @param pos Position of the first character to include.
   * @param count Length of the substring.
   * @return basic_string String containing the substring [pos, pos+count) or [pos, size()).
   */
  constexpr basic_string substr(size_type pos = 0, size_type count = npos) && {
    return basic_string{view_type{::portable_stl::move(*this)}.substr(pos, count)};
  }

  /**
   * @brief Returns a substring [pos, pos+count).
   * If the requested substring extends past the end of the string, i.e.
   * the count is greater than size() - pos (e.g. if count == npos),
   * the returned substring is [pos, size()).
   * The behavior is undefined if pos > size(), and exceptions is disabled.
   *
   * @param pos position of the first character to include.
   * @param count length of the substring.
   * @return ::portable_stl::expected<basic_string, ::portable_stl::portable_stl_error> String containing the substring
   * [pos, pos+count) or [pos, size()).
   */
  ::portable_stl::expected<basic_string, ::portable_stl::portable_stl_error> substr_safe(
    size_type pos = 0, size_type count = npos) const noexcept {
    return view_type{*this}.substr_safe(pos, count).and_then([](view_type const &result) {
      return make_string(result);
    });
  }
};

/**
 * @brief This is a special value equal to the maximum value representable by the type size_type. The exact meaning
 * depends on context, but it is generally used either as end of view indicator by the functions that expect a view
 * index or as the error indicator by the functions that return a view index.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
typename basic_string<t_char_type, t_char_traits, t_allocator>::size_type const
  basic_string<t_char_type, t_char_traits, t_allocator>::npos;

// [for tests]

/**
 * @brief Checks string invariants.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @return int Result of checking.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
inline int basic_string<t_char_type, t_char_traits, t_allocator>::check_invariants() const {
  if (size() > capacity()) {
    return 1;
  }
  if (capacity() < m_storage.short_data_max() - 1) {
    return 2;
  }
  if (data() == nullptr) {
    return 3;
  }
  if (!t_char_traits::eq(data()[size()], value_type())) {
    return 4;
  }
  return 0;
}

// [non-member functions]

/**
 * @brief Concatenates two strings, a string and a char, or a string.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String, character, or pointer to the first character in a null-terminated array.
 * @param rhs String, character, or pointer to the first character in a null-terminated array.
 * @return t_string A string containing characters from lhs followed by the characters from rhs, using the allocator
 * determined as above.A string containing characters from lhs followed by the characters from rhs, using the
 * allocator determined as above.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> operator+(
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &lhs,
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &rhs) {
  using t_string = ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>;

  auto     new_size(lhs.size() + rhs.size());
  t_string work{};
  auto     result = work.resize_and_overwrite(
    new_size,
    [&lhs, &rhs, &new_size](typename t_string::iterator buffer, typename t_string::size_type buffer_size) ->
    typename t_string::size_type {
      lhs.copy(buffer.operator->(), buffer_size, 0U);
      rhs.copy((buffer + static_cast<::portable_stl::int32_t>(lhs.size())).operator->(), buffer_size - lhs.size(), 0U);
      return new_size;
    });
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!result);

  return ::portable_stl::move(work);
}

/**
 * @brief Concatenates string and cstring.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String, character, or pointer to the first character in a null-terminated array.
 * @param rhs String, character, or pointer to the first character in a null-terminated array.
 * @return t_string A string containing characters from lhs followed by the characters from rhs, using the allocator
 * determined as above.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> operator+(
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const                  &lhs,
  typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_pointer rhs) {
  using t_string = ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>;

  typename t_string::view_type rhs_view{rhs};
  auto const                   new_size = lhs.size() + rhs_view.size();
  t_string                     work{};
  auto                         result = work.resize_and_overwrite(
    new_size,
    [&lhs, &rhs_view, &new_size](typename t_string::iterator buffer, typename t_string::size_type buffer_size) ->
    typename t_string::size_type {
      lhs.copy(buffer.operator->(), buffer_size, 0U);
      rhs_view.copy(
        (buffer + static_cast<::portable_stl::int32_t>(lhs.size())).operator->(), buffer_size - lhs.size(), 0U);
      return new_size;
    });
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!result);

  return ::portable_stl::move(work);
}

/**
 * @brief Concatenates string and char.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String, character, or pointer to the first character in a null-terminated array.
 * @param rhs String, character, or pointer to the first character in a null-terminated array.
 * @return t_string A string containing characters from lhs followed by the characters from rhs, using the allocator
 * determined as above.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> operator+(
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const               &lhs,
  typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::value_type rhs) {
  using t_string = ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>;

  typename t_string::view_type rhs_view{::portable_stl::addressof(rhs), 1UL};
  auto                         new_size(lhs.size() + rhs_view.size());
  t_string                     work{};
  auto                         result = work.resize_and_overwrite(
    new_size,
    [&lhs, &rhs_view, &new_size](typename t_string::iterator buffer, typename t_string::size_type buffer_size) ->
    typename t_string::size_type {
      lhs.copy(buffer.operator->(), buffer_size, 0U);
      rhs_view.copy(
        (buffer + static_cast<::portable_stl::int32_t>(lhs.size())).operator->(), buffer_size - lhs.size(), 0U);
      return new_size;
    });
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!result);

  return ::portable_stl::move(work);
}

/**
 * @brief Concatenates cstring and string.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String, character, or pointer to the first character in a null-terminated array.
 * @param rhs String, character, or pointer to the first character in a null-terminated array.
 * @return t_string A string containing characters from lhs followed by the characters from rhs, using the allocator
 * determined as above.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> operator+(
  typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_pointer lhs,
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const                  &rhs) {
  using t_string = ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>;

  typename t_string::view_type lhs_view{lhs};
  auto                         new_size(lhs_view.size() + rhs.size());
  t_string                     work{};
  auto                         result = work.resize_and_overwrite(
    new_size,
    [&lhs_view, &rhs, &new_size](typename t_string::iterator buffer, typename t_string::size_type buffer_size) ->
    typename t_string::size_type {
      lhs_view.copy(buffer.operator->(), buffer_size, 0U);
      rhs.copy((buffer + static_cast<::portable_stl::int32_t>(lhs_view.size())).operator->(),
               buffer_size - lhs_view.size(),
               0U);
      return new_size;
    });
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!result);

  return ::portable_stl::move(work);
}

/**
 * @brief Concatenates char and string.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String, character, or pointer to the first character in a null-terminated array.
 * @param rhs String, character, or pointer to the first character in a null-terminated array.
 * @return t_string A string containing characters from lhs followed by the characters from rhs, using the allocator
 * determined as above.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> operator+(
  typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_reference lhs,
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const                    &rhs) {
  using t_string = ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>;

  typename t_string::view_type lhs_view{::portable_stl::addressof(lhs), 1UL};
  auto                         new_size(lhs_view.size() + rhs.size());
  t_string                     work{};
  auto                         result = work.resize_and_overwrite(
    new_size,
    [&lhs_view, &rhs, &new_size](typename t_string::iterator buffer, typename t_string::size_type buffer_size) ->
    typename t_string::size_type {
      lhs_view.copy(buffer.operator->(), buffer_size, 0U);
      rhs.copy((buffer + static_cast<::portable_stl::int32_t>(lhs_view.size())).operator->(),
               buffer_size - lhs_view.size(),
               0U);
      return new_size;
    });
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!result);

  return ::portable_stl::move(work);
}

/**
 * @brief Concatenates two rvalue strings.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String, character, or pointer to the first character in a null-terminated array.
 * @param rhs String, character, or pointer to the first character in a null-terminated array.
 * @return t_string A string containing characters from lhs followed by the characters from rhs, using the allocator
 * determined as above.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> operator+(
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> &&lhs,
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> &&rhs) {
  auto result = lhs.append(::portable_stl::move(rhs));
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!result);

  return ::portable_stl::move(lhs);
}

/**
 * @brief Concatenates rvalue string and const string.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String, character, or pointer to the first character in a null-terminated array.
 * @param rhs String, character, or pointer to the first character in a null-terminated array.
 * @return t_string A string containing characters from lhs followed by the characters from rhs, using the allocator
 * determined as above.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> operator+(
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>      &&lhs,
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &rhs) {
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!lhs.append(rhs));
  return ::portable_stl::move(lhs);
}

/**
 * @brief Concatenates rvalue string and const cstring.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String, character, or pointer to the first character in a null-terminated array.
 * @param rhs String, character, or pointer to the first character in a null-terminated array.
 * @return t_string A string containing characters from lhs followed by the characters from rhs, using the allocator
 * determined as above.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> operator+(
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>                       &&lhs,
  typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_pointer rhs) {
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!lhs.append(rhs));
  return ::portable_stl::move(lhs);
}

/**
 * @brief Concatenates rvalue string and char.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String, character, or pointer to the first character in a null-terminated array.
 * @param rhs String, character, or pointer to the first character in a null-terminated array.
 * @return t_string A string containing characters from lhs followed by the characters from rhs, using the allocator
 * determined as above.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> operator+(
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>                    &&lhs,
  typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::value_type rhs) {
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!lhs.append(1U, rhs));
  return ::portable_stl::move(lhs);
}

/**
 * @brief Concatenates const string and rvalue string.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String, character, or pointer to the first character in a null-terminated array.
 * @param rhs String, character, or pointer to the first character in a null-terminated array.
 * @return t_string A string containing characters from lhs followed by the characters from rhs, using the allocator
 * determined as above.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> operator+(
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &lhs,
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>      &&rhs) {
  auto result = rhs.insert(
    0U, static_cast<typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::view_type>(lhs));
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!result);

  return ::portable_stl::move(rhs);
}

/**
 * @brief Concatenates cstring and rvalue string.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String, character, or pointer to the first character in a null-terminated array.
 * @param rhs String, character, or pointer to the first character in a null-terminated array.
 * @return t_string A string containing characters from lhs followed by the characters from rhs, using the allocator
 * determined as above.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> operator+(
  typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_pointer lhs,
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>                       &&rhs) {
  auto result
    = rhs.insert(0U, typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::view_type{lhs});
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!result);

  return ::portable_stl::move(rhs);
}

/**
 * @brief Concatenates char and rvalue string.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String, character, or pointer to the first character in a null-terminated array.
 * @param rhs String, character, or pointer to the first character in a null-terminated array.
 * @return t_string A string containing characters from lhs followed by the characters from rhs, using the allocator
 * determined as above.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> operator+(
  typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_reference lhs,
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>                         &&rhs) {
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!rhs.insert(rhs.cbegin(), lhs));
  return ::portable_stl::move(rhs);
}

/**
 * @brief Compares two basic_string objects.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String whose contents to compare.
 * @param rhs String whose contents to compare.
 * @return Result of coparison.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
constexpr bool operator==(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &lhs,
                          ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &rhs) noexcept {
  return lhs.compare(rhs) == 0;
}

/**
 * @brief Compares two basic_string objects.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String whose contents to compare.
 * @param rhs String whose contents to compare.
 * @return Result of coparison.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator!=(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &lhs,
                ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &rhs) noexcept {
  return lhs.compare(rhs) != 0;
}

/**
 * @brief Compares two basic_string objects.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String whose contents to compare.
 * @param rhs String whose contents to compare.
 * @return Result of coparison.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator<(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &lhs,
               ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &rhs) noexcept {
  return lhs.compare(rhs) < 0;
}

/**
 * @brief Compares two basic_string objects.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String whose contents to compare.
 * @param rhs String whose contents to compare.
 * @return Result of coparison.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator<=(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &lhs,
                ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &rhs) noexcept {
  return lhs.compare(rhs) <= 0;
}

/**
 * @brief Compares two basic_string objects.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String whose contents to compare.
 * @param rhs String whose contents to compare.
 * @return Result of coparison.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator>(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &lhs,
               ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &rhs) noexcept {
  return lhs.compare(rhs) > 0;
}

/**
 * @brief Compares two basic_string objects.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String whose contents to compare.
 * @param rhs String whose contents to compare.
 * @return Result of coparison.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator>=(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &lhs,
                ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &rhs) noexcept {
  return lhs.compare(rhs) >= 0;
}

/**
 * @brief Compares a basic_string object and a basic_string_view.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String view to compare.
 * @param rhs String whose contents to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
constexpr bool operator==(::portable_stl::basic_string_view<t_char_type, t_char_traits>                lhs,
                          ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &rhs) noexcept {
  return lhs.compare(static_cast<::portable_stl::basic_string_view<t_char_type, t_char_traits>>(rhs)) == 0;
}

/**
 * @brief Compares a basic_string object and a basic_string_view.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String view to compare.
 * @param rhs String whose contents to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator!=(::portable_stl::basic_string_view<t_char_type, t_char_traits>                lhs,
                ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &rhs) noexcept {
  return lhs.compare(static_cast<::portable_stl::basic_string_view<t_char_type, t_char_traits>>(rhs)) != 0;
}

/**
 * @brief Compares a basic_string object and a basic_string_view.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String view to compare.
 * @param rhs String whose contents to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator<(::portable_stl::basic_string_view<t_char_type, t_char_traits>                lhs,
               ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &rhs) noexcept {
  return lhs.compare(static_cast<::portable_stl::basic_string_view<t_char_type, t_char_traits>>(rhs)) < 0;
}

/**
 * @brief Compares a basic_string object and a basic_string_view.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String view to compare.
 * @param rhs String whose contents to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator<=(::portable_stl::basic_string_view<t_char_type, t_char_traits>                lhs,
                ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &rhs) noexcept {
  return lhs.compare(static_cast<::portable_stl::basic_string_view<t_char_type, t_char_traits>>(rhs)) <= 0;
}

/**
 * @brief Compares a basic_string object and a basic_string_view.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String view to compare.
 * @param rhs String whose contents to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator>(::portable_stl::basic_string_view<t_char_type, t_char_traits>                lhs,
               ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &rhs) noexcept {
  return lhs.compare(static_cast<::portable_stl::basic_string_view<t_char_type, t_char_traits>>(rhs)) > 0;
}

/**
 * @brief Compares a basic_string object and a basic_string_view.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String view to compare.
 * @param rhs String whose contents to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator>=(::portable_stl::basic_string_view<t_char_type, t_char_traits>                lhs,
                ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &rhs) noexcept {
  return lhs.compare(static_cast<::portable_stl::basic_string_view<t_char_type, t_char_traits>>(rhs)) >= 0;
}

/**
 * @brief Compares a basic_string object and a basic_string_view.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String view to compare.
 * @param rhs String whose contents to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
constexpr bool operator==(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &lhs,
                          ::portable_stl::basic_string_view<t_char_type, t_char_traits>                rhs) noexcept {
  return lhs.compare(static_cast<::portable_stl::basic_string_view<t_char_type, t_char_traits>>(rhs)) == 0;
}

/**
 * @brief Compares a basic_string object and a basic_string_view.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String view to compare.
 * @param rhs String whose contents to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator!=(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &lhs,
                ::portable_stl::basic_string_view<t_char_type, t_char_traits>                rhs) noexcept {
  return lhs.compare(static_cast<::portable_stl::basic_string_view<t_char_type, t_char_traits>>(rhs)) != 0;
}

/**
 * @brief Compares a basic_string object and a basic_string_view.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String whose contents to compare.
 * @param rhs String view to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator<(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &lhs,
               ::portable_stl::basic_string_view<t_char_type, t_char_traits>                rhs) noexcept {
  return lhs.compare(static_cast<::portable_stl::basic_string_view<t_char_type, t_char_traits>>(rhs)) < 0;
}

/**
 * @brief Compares a basic_string object and a basic_string_view.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String whose contents to compare.
 * @param rhs String view to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator<=(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &lhs,
                ::portable_stl::basic_string_view<t_char_type, t_char_traits>                rhs) noexcept {
  return lhs.compare(static_cast<::portable_stl::basic_string_view<t_char_type, t_char_traits>>(rhs)) <= 0;
}

/**
 * @brief Compares a basic_string object and a basic_string_view.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String whose contents to compare.
 * @param rhs String view to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator>(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &lhs,
               ::portable_stl::basic_string_view<t_char_type, t_char_traits>                rhs) noexcept {
  return lhs.compare(static_cast<::portable_stl::basic_string_view<t_char_type, t_char_traits>>(rhs)) > 0;
}

/**
 * @brief Compares a basic_string object and a basic_string_view.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String whose contents to compare.
 * @param rhs String view to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator>=(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const &lhs,
                ::portable_stl::basic_string_view<t_char_type, t_char_traits>                rhs) noexcept {
  return lhs.compare(static_cast<::portable_stl::basic_string_view<t_char_type, t_char_traits>>(rhs)) >= 0;
}

/**
 * @brief Compares a basic_string object and a null-terminated array of t_char_type.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String whose contents to compare.
 * @param rhs Null-terminated array of t_char_type.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator==(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const                  &lhs,
                typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_pointer rhs) {
  return lhs.compare(rhs) == 0;
}

/**
 * @brief Compares a basic_string object and a null-terminated array of t_char_type.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs Null-terminated array of t_char_type.
 * @param rhs String whose contents to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator==(typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_pointer lhs,
                ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const                  &rhs) {
  return
    typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::view_type{lhs}.compare(rhs) == 0;
}

/**
 * @brief Compares a basic_string object and a null-terminated array of t_char_type.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String whose contents to compare.
 * @param rhs Null-terminated array of t_char_type.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator!=(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const                  &lhs,
                typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_pointer rhs) {
  return lhs.compare(rhs) != 0;
}

/**
 * @brief Compares a basic_string object and a null-terminated array of t_char_type.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs Null-terminated array of t_char_type.
 * @param rhs String whose contents to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator!=(typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_pointer lhs,
                ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const                  &rhs) {
  return
    typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::view_type{lhs}.compare(rhs) != 0;
}

/**
 * @brief Compares a basic_string object and a null-terminated array of t_char_type.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String whose contents to compare.
 * @param rhs Null-terminated array of t_char_type.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator<(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const                  &lhs,
               typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_pointer rhs) {
  return lhs.compare(rhs) < 0;
}

/**
 * @brief Compares a basic_string object and a null-terminated array of t_char_type.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs Null-terminated array of t_char_type.
 * @param rhs String whose contents to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator<(typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_pointer lhs,
               ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const                  &rhs) {
  return
    typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::view_type{lhs}.compare(rhs) < 0;
}

/**
 * @brief Compares a basic_string object and a null-terminated array of t_char_type.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String whose contents to compare.
 * @param rhs Null-terminated array of t_char_type.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator<=(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const                  &lhs,
                typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_pointer rhs) {
  return lhs.compare(rhs) <= 0;
}

/**
 * @brief Compares a basic_string object and a null-terminated array of t_char_type.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs Null-terminated array of t_char_type.
 * @param rhs String whose contents to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator<=(typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_pointer lhs,
                ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const                  &rhs) {
  return
    typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::view_type{lhs}.compare(rhs) <= 0;
}

/**
 * @brief Compares a basic_string object and a null-terminated array of t_char_type.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String whose contents to compare.
 * @param rhs Null-terminated array of t_char_type.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator>(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const                  &lhs,
               typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_pointer rhs) {
  return lhs.compare(rhs) > 0;
}

/**
 * @brief Compares a basic_string object and a null-terminated array of t_char_type.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs Null-terminated array of t_char_type.
 * @param rhs String whose contents to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator>(typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_pointer lhs,
               ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const                  &rhs) {
  return
    typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::view_type{lhs}.compare(rhs) > 0;
}

/**
 * @brief Compares a basic_string object and a null-terminated array of t_char_type.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs String whose contents to compare.
 * @param rhs Null-terminated array of t_char_type.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator>=(::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const                  &lhs,
                typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_pointer rhs) {
  return lhs.compare(rhs) >= 0;
}

/**
 * @brief Compares a basic_string object and a null-terminated array of t_char_type.
 *
 * @tparam t_char_type
 * @tparam t_char_traits
 * @tparam t_allocator
 * @param lhs Null-terminated array of t_char_type.
 * @param rhs String whose contents to compare.
 * @return true
 * @return false
 */
template<class t_char_type, class t_char_traits, class t_allocator>
bool operator>=(typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_pointer lhs,
                ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> const                  &rhs) {
  return
    typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::view_type{lhs}.compare(rhs) >= 0;
}

/**
 * @brief Specializes the ::swap algorithm for basic_string. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param lhs String to swap.
 * @param rhs String to swap.
 */
template<class t_char_type, class t_char_traits, class t_allocator>
void swap(
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> &lhs,
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> &rhs) noexcept(noexcept(lhs.swap(rhs))) {
  lhs.swap(rhs);
}

/**
 * @brief Erases all elements that compare equal to value from the container.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @param str Container from which to erase.
 * @param value Value to be removed.
 * @return ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::size_type
 */
template<class t_char_type, class t_char_traits, class t_allocator>
typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::size_type erase(
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>                          &str,
  typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::const_reference value) {
  auto it     = ::portable_stl::remove(str.begin(), str.end(), value);
  auto result = ::portable_stl::distance(it, str.end());
  str.erase(it, str.end());
  return result;
}

/**
 * @brief Erases all elements that satisfy the predicate pred from the container.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Traits class specifying the operations on the character type.
 * @tparam t_allocator Allocator type used to allocate internal storage.
 * @tparam t_pred
 * @param str Container from which to erase.
 * @param pred Nnary predicate which returns ​true if the element should be erased.
 * @return ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::size_type
 */
template<class t_char_type, class t_char_traits, class t_allocator, class t_pred>
typename ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator>::size_type erase_if(
  ::portable_stl::basic_string<t_char_type, t_char_traits, t_allocator> &str, t_pred pred) {
  auto it = ::portable_stl::remove_if(str.begin(), str.end(), pred);
  auto r  = ::portable_stl::distance(it, str.end());
  str.erase(it, str.end());
  return r;
}

} // namespace portable_stl

#endif // PSTL_BASIC_STRING_H
