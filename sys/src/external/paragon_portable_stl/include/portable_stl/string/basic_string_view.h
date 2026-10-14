// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string_view.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BASIC_STRING_VIEW_H
#define PSTL_BASIC_STRING_VIEW_H

#include "../algorithm/any_of.h"
#include "../algorithm/find_end.h"
#include "../algorithm/find_first_of.h"
#include "../algorithm/find_if_not.h"
#include "../algorithm/find_last_of.h"
#include "../algorithm/min.h"
#include "../algorithm/search.h"
#include "../common/numeric_limits.h"
#include "../common/ptrdiff_t.h"
#include "../common/size_t.h"
#include "../error/portable_stl_error.h"
#include "../iterator/concepts/contiguous_iterator.h"
#include "../iterator/concepts/sized_sentinel_for.h"
#include "../iterator/distance.h"
#include "../iterator/iter_value_t.h"
#include "../iterator/reverse_iterator.h"
#include "../language_support/out_of_range.h"
#include "../memory/to_address.h"
#include "../metaprogramming/cv_modifications/remove_const.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/pointer_modifications/remove_pointer.h"
#include "../metaprogramming/type_relations/is_convertible.h"
#include "../metaprogramming/type_relations/is_same.h"
#include "../utility/expected/expected.h"
#include "../utility/expected/unexpected.h"
#include "../utility/general/functional/reference_wrapper.h"
#include "char_traits.h"

#if defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  include "../language_support/exception/throw_on_true.h"
#else
#  include "../language_support/no_exception/throw_on_true.h"
#endif

namespace portable_stl {

/**
 * @brief String class forward declaration.
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits Class specifying the operations on the character type.
 * @tparam t_allocator Allocator type.
 */
template<class t_char_type, class t_char_traits, class t_allocator> class basic_string;

/**
 * @brief The class template basic_string_view describes an object that can refer to a constant contiguous sequence of
 * t_char_type with the first element of the sequence at position zero.
 * For a basic_string_view str, pointers, iterators, and references to elements of str are invalidated when an operation
 * invalidates a pointer in the range [str.data(), str.data() + str.size()).
 *
 * @tparam t_char_type Character type.
 * @tparam t_char_traits_type Class specifying the operations on the character type.
 */
template<class t_char_type, class t_char_traits_type = ::portable_stl::char_traits<t_char_type>>
class basic_string_view final {
public:
  /**
   * @brief Current class type.
   *
   */
  using type                   = basic_string_view;
  /**
   * @brief Class specifying the operations on the character type.
   *
   */
  using traits_type            = t_char_traits_type;
  /**
   * @brief Character type.
   *
   */
  using value_type             = t_char_type;
  /**
   * @brief Pointer to contiguous sequence of char-like objects.
   *
   */
  using pointer                = value_type *;
  /**
   * @brief Constant pointer to contiguous sequence of char-like objects.
   *
   */
  using const_pointer          = value_type const *;
  /**
   * @brief Reference to element of contiguous sequence of char-like objects.
   *
   */
  using reference              = value_type &;
  /**
   * @brief Constant reference to element of contiguous sequence of char-like objects.
   *
   */
  using const_reference        = value_type const &;
  /**
   * @brief Constant type for iterate element of contiguous sequence of char-like objects.
   *
   */
  using const_iterator         = value_type const *;
  /**
   * @brief Type for iterate element of contiguous sequence of char-like objects.
   *
   */
  using iterator               = const_iterator;
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
   * @brief Type for size of contiguous sequence of char-like objects.
   *
   */
  using size_type              = ::portable_stl::size_t;
  /**
   * @brief Type for distance between positions in contiguous sequence of char-like objects.
   *
   */
  using difference_type        = ::portable_stl::ptrdiff_t;
  /**
   * @brief Constant reference wrapper to element. Used in expected return.
   *
   */
  using const_reference_wrap   = ::portable_stl::reference_wrapper<value_type const>;

  /**
   * @brief This is a special value equal to the maximum value representable by the type size_type. The exact meaning
   * depends on context, but it is generally used either as end of view indicator by the functions that expect a view
   * index or as the error indicator by the functions that return a view index.
   */
  constexpr static size_type const npos = size_type(-1);

private:
  /**
   * @brief Pointer to contiguous sequence of char-like objects.
   */
  const_pointer m_data{nullptr};

  /**
   * @brief Size of contiguous sequence of char-like objects.
   */
  size_type m_size{0};

public:
  // [string.view.cons]

  /**
   * @brief Default constructor. Constructs an empty ::basic_string_view. After construction, data() is equal to
   * nullptr, and size() is equal to ​0​.
   */
  constexpr basic_string_view() noexcept = default;

  /**
   * @brief Copy constructor. Constructs a view of the same content as other. After construction, data() is equal to
   * other.data(), and size() is equal to other.size().
   */
  constexpr basic_string_view(basic_string_view const &) noexcept = default;

  /**
   * @brief Constructs a view of the first count characters of the character array starting with the element pointed by
   * data. data can contain null characters. The behavior is undefined if [data, data+size) is not a valid range (even
   * though the constructor may not access any of the elements of this range). After construction, data() is equal to
   * data, and size() is equal to size.
   *
   * @param data Pointer to a character array or a C string to initialize the view with.
   * @param size Number of characters to include in the view.
   */
  constexpr basic_string_view(const_pointer data, size_type size) noexcept : m_data(data), m_size(size) {
  }

  /**
   * @brief Constructs a view of the null-terminated character string pointed to by data, not including the terminating
   * null character. The length of the view is determined as if by traits_type::length(data). The behavior is undefined
   * if [data, data+traits_type::length(traits_type)) is not a valid range. After construction, data() is equal to data,
   * and size() is equal to traits_type::length(data).
   *
   * @param data C string to initialize the view with.
   */
  constexpr basic_string_view(const_pointer data) noexcept // NOLINT(google-explicit-constructor)
      : basic_string_view(data, t_char_traits_type::length(data)) {
  }

  /**
   * @brief Constructs a view of the null-terminated character string pointed to by data, not including the terminating
   * null character. The length of the view is determined as if by traits_type::length(data). The behavior is undefined
   * if [data, data+traits_type::length(traits_type)) is not a valid range. After construction, data() is equal to data,
   * and size() is equal to traits_type::length(data).
   * Only for case when data points to char[N] and value_type is ::portable_stl::pstl_char8_t = unsigned char.
   *
   * @param data C string to initialize the view with.
   */
  template<class ptr_type,
           class val_type = value_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::is_same<val_type, ::portable_stl::pstl_char8_t>,
                                         ::portable_stl::is_same<ptr_type, ::portable_stl::char_t>>,
             void *>
           = nullptr>
  constexpr basic_string_view(ptr_type const *data) noexcept // NOLINT(google-explicit-constructor)
      : basic_string_view(static_cast<const_pointer>(static_cast<void const *>(data)),
                          t_char_traits_type::length(static_cast<const_pointer>(static_cast<void const *>(data)))) {
  }

  /**
   * @brief Constructs a basic_string_view over the range [first, last). The behavior is undefined if [first, last) is
   * not a valid range, if t_iterator does not actually model iterator, or if t_iterator_end does not actually model
   * iterator, and if t_iterator_end does not convert to  size_type. After construction, data() is equal to
   * ::portable_stl::to_address(first), and size() is equal to ::portable_stl::distance(first, last).
   *
   * @tparam t_iterator Type for the iterator to the first character of the sequence.
   * @tparam t_iterator_end Type for the iterator past the last character of the sequence or another sentinel.
   * @param first Iterator to the first character of the sequence.
   * @param last Iterator past the last character of the sequence or another sentinel.
   */
  template<
    class t_iterator,
    class t_iterator_end,
    ::portable_stl::enable_if_bool_constant_t<
      ::portable_stl::conjunction<::portable_stl::contiguous_iterator<t_iterator>,
                                  ::portable_stl::sized_sentinel_for<t_iterator_end, t_iterator>,
                                  ::portable_stl::is_same<::portable_stl::iter_value_t<t_iterator>, t_char_type>,
                                  ::portable_stl::negation<::portable_stl::is_convertible<t_iterator_end, size_type>>>,
      void *>
    = nullptr>
  constexpr basic_string_view(t_iterator first, t_iterator_end last) noexcept
      : m_data(::portable_stl::to_address(first)), m_size(static_cast<size_type>(last - first)) {
  }

  /**
   * @brief basic_string_view cannot be constructed from nullptr.
   */
  constexpr basic_string_view(::portable_stl::nullptr_t) noexcept = delete;

  /**
   * @brief Replaces the view with that of view.
   *
   * @param view View to copy.
   * @return *this.
   */
  basic_string_view &operator=(basic_string_view const &view) noexcept = default;

  // [string.view.iterators]

  /**
   * @brief Returns an iterator to the first character of the view.
   *
   * @return const_iterator to the first character
   */
  constexpr iterator begin() const noexcept {
    return &operator[](0U);
  }

  /**
   * @brief Returns an iterator to the first character of the view.
   *
   * @return const_iterator to the first character
   */
  constexpr const_iterator cbegin() const noexcept {
    return begin();
  }

  /**
   * @brief Returns an iterator to the character following the last character of the view. This character acts as a
   * placeholder, attempting to access it results in undefined behavior.
   *
   * @return const_iterator to the character following the last character.
   */
  constexpr iterator end() const noexcept {
    return &operator[](size());
  }

  /**
   * @brief Returns an iterator to the character following the last character of the view. This character acts as a
   * placeholder, attempting to access it results in undefined behavior.
   *
   * @return const_iterator to the character following the last character.
   */
  constexpr const_iterator cend() const noexcept {
    return end();
  }

  /**
   * @brief Returns a reverse iterator to the first character of the reversed view. It corresponds to the last character
   * of the non-reversed view.
   *
   * @return const_reverse_iterator to the first character
   */
  constexpr reverse_iterator rbegin() const noexcept {
    return reverse_iterator{end()};
  }

  /**
   * @brief Returns a reverse iterator to the first character of the reversed view. It corresponds to the last character
   * of the non-reversed view.
   *
   * @return const_reverse_iterator to the first character
   */
  constexpr const_reverse_iterator crbegin() const noexcept {
    return const_reverse_iterator{cend()};
  }

  /**
   * @brief Returns a reverse iterator to the character following the last character of the reversed view. It
   * corresponds to the character preceding the first character of the non-reversed view. This character acts as a
   * placeholder, attempting to access it results in undefined behavior.
   *
   * @return const_reverse_iterator to the character following the last character.
   */
  constexpr reverse_iterator rend() const noexcept {
    return reverse_iterator{begin()};
  }

  /**
   * @brief Returns a reverse iterator to the character following the last character of the reversed view. It
   * corresponds to the character preceding the first character of the non-reversed view. This character acts as a
   * placeholder, attempting to access it results in undefined behavior.
   *
   * @return const_reverse_iterator to the character following the last character.
   */
  constexpr const_reverse_iterator crend() const noexcept {
    return const_reverse_iterator{cbegin()};
  }

  // [string.view.capacity]

  /**
   * @brief Returns the number of value_type elements in the view, i.e. portable_stl::distance(begin(), end()).
   *
   * @return The number of value_type elements in the view.
   */
  constexpr size_type size() const noexcept {
    return m_size;
  }

  /**
   * @brief Returns the number of value_type elements in the view, i.e. portable_stl::distance(begin(), end()).
   *
   * @return The number of value_type elements in the view.
   */
  constexpr size_type length() const noexcept {
    return size();
  }

  /**
   * @brief The largest possible number of value_type objects that can be referred to by a basic_string_view.
   *
   * @return Maximum number of value_type.
   */
  constexpr size_type max_size() const noexcept {
    return ::portable_stl::numeric_limits<size_type>::max() / sizeof(value_type);
  }

  /**
   * @brief Checks if the view has no characters, i.e. whether size() == 0U
   *
   * @return View has no characters or not.
   * @retval true if the view is empty.
   * @retval false otherwise if the view is not empty.
   */
  constexpr bool empty() const noexcept {
    return 0U == size();
  }

  // [string.view.access]

  /**
   * @brief Returns a const reference to the character at specified location pos.
   * No bounds checking is performed: the behavior is undefined if pos >= size()
   *
   * @param pos Position of the character to return
   * @return Const reference to the requested character.
   */
  constexpr const_reference operator[](size_type pos) const noexcept {
    return m_data[pos];
  }

  /**
   * @brief Returns a const reference wrapper to the character at specified location pos.
   * Bounds checking is performed, exception of type out_of_range will be thrown on invalid access.
   *
   * @param pos Position of the character to return.
   * @return Const reference wrapper to the requested character or out_of_range.
   */
  ::portable_stl::expected<const_reference_wrap, ::portable_stl::portable_stl_error> at(size_type pos) const noexcept {
    if (pos >= size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::out_of_range};
    }
    return ::portable_stl::expected<const_reference_wrap, ::portable_stl::portable_stl_error>{
      ::portable_stl::ref(operator[](pos))};
  }

  /**
   * @brief Returns reference to the first character in the view.
   * The behavior is undefined if empty() == true.
   *
   * @return Reference to the first character, equivalent to operator[](0U).
   */
  constexpr const_reference front() const noexcept {
    return operator[](0U);
  }

  /**
   * @brief Returns reference to the last character in the view.
   * The behavior is undefined if empty() == true.
   *
   * @return Reference to the last character, equivalent to operator[](size() - 1U).
   */
  constexpr const_reference back() const noexcept {
    return operator[](size() - 1U);
  }

  /**
   * @brief Returns a pointer to the underlying character array.
   * The pointer is such that the range [data(); data() + size()) is valid and the values in it correspond to the values
   * of the view.
   *
   * @return A pointer to the underlying character array.
   */
  constexpr const_pointer data() const noexcept {
    return begin();
  }

  // [string.view.modifiers]

  /**
   * @brief Moves the start of the view forward by n characters.
   * The behavior is undefined if n > size().
   *
   * @param n Number of characters to remove from the start of the view.
   */
  void remove_prefix(size_type n) noexcept {
    m_data = (begin() + n);
    m_size = (size() - n);
  }

  /**
   * @brief Moves the end of the view back by n characters.
   * The behavior is undefined if n > size().
   *
   * @param n Number of characters to remove from the end of the view
   */
  void remove_suffix(size_type n) noexcept {
    m_size = (size() - n);
  }

  /**
   * @brief Exchanges the view with other.
   * @param other Vview to swap with.
   */
  void swap(basic_string_view &other) noexcept {
    portable_stl::swap(m_data, other.m_data);
    portable_stl::swap(m_size, other.m_size);
  }

  // [string.view.ops]

  /**
   * @brief Copies the substring [pos, pos + rcount) to the character array pointed to by dest, where rcount is the
   * smaller of count and size() - pos.
   * Equivalent to Traits::copy(dest, begin() + pos, rcount).
   *
   * @param dest Pointer to the destination character string.
   * @param count Requested substring length.
   * @param pos Position of the first character.
   * @return Number of characters copied or out_of_range if pos >= size().
   */
  ::portable_stl::expected<size_type, ::portable_stl::portable_stl_error> copy(
    pointer dest, size_type count, size_type pos = 0UL) const noexcept {
    if (pos > size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::out_of_range};
    }
    size_type const rcount{::portable_stl::min(count, (size() - pos))};
    traits_type::copy(dest, (begin() + pos), rcount);
    return ::portable_stl::expected<size_type, ::portable_stl::portable_stl_error>{rcount};
  }

  /**
   * @brief Returns a view of the substring [pos, pos + rcount), where rcount is the smaller of count and size() - pos
   *
   * @throw ::portable_stl::out_of_range if pos >= size().
   * @param pos position of the first character.
   * @param count requested length.
   * @return View of the substring [pos, pos + rcount) or ::out_of_range if pos >= size()
   */
  basic_string_view substr(size_type pos = 0UL, size_type count = npos) const {
    ::portable_stl::throw_on_true<::portable_stl::out_of_range<>>(pos > size());
    auto work_size = ::portable_stl::min(count, (size() - pos));
    return {(0U == work_size ? nullptr : (begin() + pos)), work_size};
  }

  /**
   * @brief Returns a view of the substring [pos, pos + rcount), where rcount is the smaller of count and size() - pos
   *
   *
   * @param pos position of the first character.
   * @param count requested length.
   * @return View of the substring [pos, pos + rcount) or portable_stl_error::out_of_range if pos >= size()
   */
  ::portable_stl::expected<basic_string_view, ::portable_stl::portable_stl_error> substr_safe(
    size_type pos = 0UL, size_type count = npos) const {
    if (pos > size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::out_of_range};
    }
    auto work_size(::portable_stl::min(count, (size() - pos)));
    return ::portable_stl::expected<basic_string_view, ::portable_stl::portable_stl_error>{
      basic_string_view{(0U == work_size ? nullptr : (begin() + pos)), work_size}
    };
  }

  /**
   * @brief Compares two character sequences.
   *
   * @param view View to compare.
   * @return Result of compare.
   * @retval negative if this view is less than the other character sequence.
   * @retval zero if the both character sequences are equal.
   * @retval positive if this view is greater than the other character sequence.
   */
  ::portable_stl::int32_t compare(basic_string_view const view) const noexcept {
    size_type const               work_size{::portable_stl::min(size(), view.size())};
    ::portable_stl::int32_t const result{(0U == work_size) ? 0 : traits_type::compare(data(), view.data(), work_size)};
    if (0 == result) {
      if (size() == view.size()) {
        return 0;
      }
      if (size() < view.size()) {
        return -1;
      }
      return 1;
    }
    return result;
  }

  /**
   * @brief + Compares two character sequences.
   *
   * @param pos1 Position of the first character in this view to compare.
   * @param count1 Number of characters of this view to compare.
   * @param view View to compare.
   * @return Result of compare or out_of_range.
   * @retval negative if this view is less than the other character sequence.
   * @retval zero if the both character sequences are equal.
   * @retval positive if this view is greater than the other character sequence.
   * @retval portable_stl_error if out of range.
   */
  ::portable_stl::expected<::portable_stl::int32_t, ::portable_stl::portable_stl_error> compare(
    size_type const pos1, size_type const count1, basic_string_view const view) const noexcept {
    // return substr(pos1, count1).compare(v);
    return substr_safe(pos1, count1).transform([&view](basic_string_view const &result) -> ::portable_stl::int32_t {
      return result.compare(view);
    });
  }

  /**
   * @brief Compares two character sequences.
   *
   * @param pos1 Position of the first character in this view to compare.
   * @param count1 Number of characters of this view to compare.
   * @param view View to compare.
   * @param pos2 Position of the first character of the given view to compare.
   * @param count2 Number of characters of the given view to compare.
   * @return Result of compare or out_of_range.
   * @retval negative if this view is less than the other character sequence.
   * @retval zero if the both character sequences are equal.
   * @retval positive if this view is greater than the other character sequence.
   * @retval portable_stl_error if out of range.
   */
  ::portable_stl::expected<::portable_stl::int32_t, ::portable_stl::portable_stl_error> compare(
    size_type const         pos1,
    size_type const         count1,
    basic_string_view const view,
    size_type const         pos2,
    size_type const         count2) const noexcept {
    // return substr2(pos1, count1).compare(view.substr1(pos2, count2));
    return substr_safe(pos1, count1).and_then([&view, pos2, count2](basic_string_view const &result1) {
      return view.substr_safe(pos2, count2)
        .transform([&result1](basic_string_view const &result2) -> ::portable_stl::int32_t {
          return result1.compare(result2);
        });
    });
  }

  /**
   * @brief Compares two character sequences.
   *
   * @param str_ptr Pointer to the character string to compare to.
   * @return Result of compare.
   * @retval negative if this view is less than the other character sequence.
   * @retval zero if the both character sequences are equal.
   * @retval positive if this view is greater than the other character sequence.
   */
  constexpr ::portable_stl::int32_t compare(const_pointer str_ptr) const noexcept {
    return compare(basic_string_view{str_ptr});
  }

  /**
   * @brief Compares two character sequences.
   *
   * @param pos1 Position of the first character in this view to compare.
   * @param count1 Number of characters of this view to compare.
   * @param str_ptr Pointer to the character string to compare to.
   * @return Result of compare or out_of_range.
   * @retval negative if this view is less than the other character sequence.
   * @retval zero if the both character sequences are equal.
   * @retval positive if this view is greater than the other character sequence.
   * @retval portable_stl_error if out of range.
   */
  ::portable_stl::expected<::portable_stl::int32_t, ::portable_stl::portable_stl_error> compare(
    size_type pos1, size_type count1, const_pointer str_ptr) const noexcept {
    // return substr(pos1, count1).compare(basic_string_view{str_ptr});
    return substr_safe(pos1, count1)
      .transform([&str_ptr](basic_string_view const &substr_res) -> ::portable_stl::int32_t {
        return substr_res.compare(basic_string_view{str_ptr});
      });
  }

  /**
   * @brief Compares two character sequences.
   *
   * @param pos1 Position of the first character in this view to compare.
   * @param count1 Number of characters of this view to compare.
   * @param str_ptr Pointer to the character string to compare to.
   * @param count2 Number of characters of the given string to compare.
   * @return Result of compare or out_of_range.
   * @retval negative if this view is less than the other character sequence.
   * @retval zero if the both character sequences are equal.
   * @retval positive if this view is greater than the other character sequence.
   * @retval portable_stl_error if out of range.
   */
  ::portable_stl::expected<::portable_stl::int32_t, ::portable_stl::portable_stl_error> compare(
    size_type pos1, size_type count1, const_pointer str_ptr, size_type count2) const noexcept {
    // return substr(pos1, count1).compare(basic_string_view{str_ptr, count2});
    return substr_safe(pos1, count1)
      .transform([&str_ptr, &count2](basic_string_view const &substr_res) -> ::portable_stl::int32_t {
        return substr_res.compare(basic_string_view{str_ptr, count2});
      });
  }

  /**
   * @brief Checks if the string view begins with the given prefix, where the prefix is a string view.
   *
   * @param view A string view which may be a result of implicit conversion from portable_stl::basic_string.
   * @return substr(0U, view.size()) == view.
   * @retval true if the string view begins with the provided prefix.
   * @retval false the string view not begins with the provided prefix.
   */
  constexpr bool starts_with(basic_string_view view) const noexcept {
    return ((size() >= view.size()) && (0 == compare(0, view.size(), view).value()));
  }

  /**
   * @brief Checks if the string view begins with the given prefix, where the prefix is a single character.
   *
   * @param chr A single character.
   * @return (!empty() && Traits::eq(front(), chr))
   * @retval true if the string view begins with the provided prefix.
   * @retval false the string view not begins with the provided prefix.
   */
  constexpr bool starts_with(const_reference chr) const noexcept {
    return ((!empty()) && (traits_type::eq(front(), chr)));
  }

  /**
   * @brief Checks if the string view begins with the given prefix, where the prefix is a null-terminated character
   * string.
   *
   * @param s A null-terminated character string.
   * @return starts_with(basic_string_view(s)).
   * @retval true if the string view begins with the provided prefix.
   * @retval false the string view not begins with the provided prefix.
   */
  constexpr bool starts_with(const_pointer s) const noexcept {
    return starts_with(basic_string_view{s});
  }

  /**
   * @brief Checks if the string view ends with the given suffix, where the suffix is a string view.
   *
   * @param view A string view which may be a result of implicit conversion from portable_stl::basic_string.
   * @return size() >= view.size() && compare(size() - view.size(), npos, view) == 0.
   * @retval true if the string view ends with the provided suffix.
   * @retval false if the string view not ends with the provided suffix.
   */
  constexpr bool ends_with(basic_string_view view) const noexcept {
    return ((size() >= view.size()) && (0 == compare((size() - view.size()), npos, view).value()));
  }

  /**
   * @brief Checks if the string view ends with the given suffix, where the suffix is a single character.
   *
   * @param chr A single character.
   * @return !empty() && Traits::eq(back(), chr).
   * @retval true if the string view ends with the provided suffix.
   * @retval false if the string view not ends with the provided suffix.
   */
  constexpr bool ends_with(const_reference chr) const noexcept {
    return ((!empty()) && traits_type::eq(back(), chr));
  }

  /**
   * @brief Checks if the string view ends with the given suffix, where the suffix is a null-terminated character
   * string.
   *
   * @param str A null-terminated character string.
   * @return ends_with(basic_string_view(s)).
   * @retval true if the string view ends with the provided suffix.
   * @retval false if the string view not ends with the provided suffix.
   */
  constexpr bool ends_with(const_pointer str) const noexcept {
    return ends_with(basic_string_view{str});
  }

  /**
   * @brief Checks if the string view contains the given substring, where the substring is a string view.
   *
   * @param view A string view which may be a result of implicit conversion from portable_stl::basic_string.
   * @return find(view) != npos.
   * @retval true if the string view contains the provided substring.
   * @retval false if the string view not contains the provided substring.
   */
  bool contains(basic_string_view view) const noexcept {
    return (find(view) != npos);
  }

  /**
   * @brief Checks if the string view contains the given substring, where the substring is a single character.
   *
   * @param chr A single character.
   * @return find(chr) != npos.
   * @retval true if the string view contains the provided substring.
   * @retval false if the string view not contains the provided substring.
   */
  bool contains(const_reference chr) const noexcept {
    return (find(chr) != npos);
  }

  /**
   * @brief Checks if the string view contains the given substring, where the substring is a null-terminated character
   * string.
   *
   * @param str Null-terminated character string.
   * @return contains(basic_string_view{s}).
   * @retval true if the string view contains the provided substring.
   * @retval false if the string view not contains the provided substring.
   */
  bool contains(const_pointer str) const noexcept {
    return contains(basic_string_view{str});
  }

  // [string.view.find]

  /**
   * @brief Finds the first substring equal to the given character sequence.
   * Finds the first occurrence of ch in this view, starting at position pos.
   *
   * @param chr character to search for.
   * @param pos position at which to start the search.
   * @return Position of the first character of the found substring, or npos if no such substring is found.
   */
  size_type find(const_reference chr, size_type pos = 0UL) const noexcept {
    const_pointer result{nullptr};
    if (pos < size()) {
      result = traits_type::find(begin() + pos, size() - pos, chr);
    }
    return ((nullptr == result) ? npos : static_cast<size_type>(::portable_stl::distance(begin(), result)));
  }

  /**
   * @brief Finds the first substring equal to the given character sequence.
   * Finds the first occurrence of viewin this view, starting at position pos.
   *
   * @param view view to search for.
   * @param pos position at which to start the search.
   * @return Position of the first character of the found substring, or npos if no such substring is found.
   */
  size_type find(basic_string_view view, size_type const pos = 0UL) const noexcept {
    if (pos < size()) {
      auto const result = ::portable_stl::search(begin() + pos, end(), view.begin(), view.end(), traits_type::eq);
      return ((end() != result) ? static_cast<size_type>(::portable_stl::distance(begin(), result)) : npos);
    }
    return ((view.empty() && pos == size()) ? pos : npos);
  }

  /**
   * @brief Finds the first substring equal to the given character sequence.
   * Finds the first occurrence of [str, str+count) in this view, starting at position pos.
   *
   * @param str pointer to a character string to search for.
   * @param pos position at which to start the search.
   * @param count length of substring to search for
   * @return Position of the first character of the found substring, or npos if no such substring is found.
   */
  constexpr size_type find(const_pointer str, size_type pos, size_type count) const noexcept {
    return find(basic_string_view{str, count}, pos);
  }

  /**
   * @brief Finds the first substring equal to the given character sequence.
   * Finds the first occurrence of s in this view, starting at position pos.
   *
   * @param str pointer to a character string to search for.
   * @param pos position at which to start the search.
   * @return Position of the first character of the found substring, or npos if no such substring is found.
   */
  constexpr size_type find(const_pointer str, size_type pos = 0UL) const noexcept {
    return find(basic_string_view{str}, pos);
  }

  /**
   * @brief Finds the last substring equal to the given character sequence.
   *
   * @param view to search for.
   * @param pos position at which to start the search.
   * @return Position of the first character of the found substring or npos if no such substring is found.
   */
  size_type rfind(basic_string_view view, size_type pos = npos) const noexcept {
    pos = ::portable_stl::min(pos, size());
    if (!view.empty()) {
      if (view.size() < (size() - pos)) {
        pos += view.size();
      } else {
        pos = size();
      }
      auto const work_end = begin() + pos;
      auto const result   = ::portable_stl::find_end(begin(), work_end, view.begin(), view.end(), traits_type::eq);
      return (result == work_end ? npos : static_cast<size_type>(::portable_stl::distance(begin(), result)));
    }
    return pos;
  }

  /**
   * @brief Finds the last substring equal to the given character sequence.
   *
   * @param chr character to search for.
   * @param pos position at which to start the search.
   * @return Position of the first character of the found substring or npos if no such substring is found.
   */
  constexpr size_type rfind(const_reference chr, size_type pos = npos) const noexcept {
    return rfind(basic_string_view{::portable_stl::addressof(chr), 1UL}, pos);
  }

  /**
   * @brief Finds the last substring equal to the given character sequence.
   *
   * @param str pointer to a character string to search for.
   * @param pos position at which to start the search.
   * @param count length of substring to search for.
   * @return Position of the first character of the found substring or npos if no such substring is found.
   */
  constexpr size_type rfind(const_pointer str, size_type pos, size_type count) const noexcept {
    return rfind(basic_string_view{str, count}, pos);
  }

  /**
   * @brief Finds the last substring equal to the given character sequence.
   *
   * @param str pointer to a character string to search for.
   * @param pos position at which to start the search
   * @return Position of the first character of the found substring or npos if no such substring is found.
   */
  constexpr size_type rfind(const_pointer str, size_type pos = npos) const noexcept {
    return rfind(basic_string_view{str}, pos);
  }

  /**
   * @brief Finds the first character equal to any of the characters in the given character sequence.
   * The behavior is undefined if viewcontains multi-element symbols (UTF-8, UTF-16).
   *
   * @param view View to search for.
   * @param pos position at which to start the search.
   * @return Position of the first occurrence of any character of the substring, or npos if no such character is
   found.
   */
  size_type find_first_of(basic_string_view view, size_type pos = 0UL) const noexcept {
    auto result = end();
    if ((pos < size()) && !view.empty()) {
      result = ::portable_stl::find_first_of((begin() + pos), end(), view.begin(), view.end(), traits_type::eq);
    }
    return ((end() == result) ? npos : static_cast<size_type>(::portable_stl::distance(begin(), result)));
  }

  /**
   * @brief Finds the first character equal to any of the characters in the given character sequence.
   * The behavior is undefined if chr contains multi-element symbols (UTF-8, UTF-16).
   *
   * @param chr character to search for.
   * @param pos position at which to start the search.
   * @return Position of the first occurrence of any character of the substring, or npos if no such character is
   found.
   */
  constexpr size_type find_first_of(const_reference chr, size_type pos = 0UL) const noexcept {
    return find_first_of(basic_string_view{::portable_stl::addressof(chr), 1UL}, pos);
  }

  /**
   * @brief Finds the first character equal to any of the characters in the given character sequence.
   * The behavior is undefined if s contains multi-element symbols (UTF-8, UTF-16).
   *
   * @param str pointer to a character string to search for.
   * @param pos position at which to start the search.
   * @param count length of substring to search for.
   * @return Position of the first occurrence of any character of the substring, or npos if no such character is
   found.
   */
  constexpr size_type find_first_of(const_pointer str, size_type pos, size_type count) const noexcept {
    return find_first_of(basic_string_view{str, count}, pos);
  }

  /**
   * @brief Finds the first character equal to any of the characters in the given character sequence.
   * The behavior is undefined if s contains multi-element symbols (UTF-8, UTF-16).
   *
   * @param str pointer to a character string to search for.
   * @param pos position at which to start the search.
   * @return Position of the first occurrence of any character of the substring, or npos if no such character is
   found.
   */
  constexpr size_type find_first_of(const_pointer str, size_type pos = 0UL) const noexcept {
    return find_first_of(basic_string_view{str}, pos);
  }

  /**
   * @brief Finds the last character equal to one of characters in the given character sequence. Exact search
   algorithm
   * is not specified. The search considers only the interval [0; pos]. If the character is not present in the
   interval,
   * npos will be returned. The behavior is undefined if viewcontains multi-element symbols (UTF-8, UTF-16).
   *
   * @param view View to search for.
   * @param pos position at which to start the search.
   * @return Position of the last occurrence of any character of the substring, or npos if no such character is
   found.
   */
  size_type find_last_of(basic_string_view view, size_type pos = npos) const noexcept {
    auto result = rend();
    pos         = ::portable_stl::min(pos, size());
    if (pos < size()) {
      ++pos;
    }
    if (!view.empty()) {
      result = ::portable_stl::find_first_of(reverse_iterator{begin() + pos},
                                             rend(),
                                             view.begin(),
                                             view.end(),
                                             [](value_type const left, value_type const right) -> bool {
                                               return traits_type::eq(left, right);
                                             });
    }
    return ((rend() == result) ? npos : static_cast<size_type>(::portable_stl::distance(result, rend())) - 1UL);
  }

  /**
   * @brief Finds the last character equal to one of characters in the given character sequence. Exact search
   algorithm
   * is not specified. The search considers only the interval [0; pos]. If the character is not present in the
   interval,
   * npos will be returned. The behavior is undefined if chr contains multi-element symbols (UTF-8, UTF-16).
   *
   * @param chr character to search for.
   * @param pos position at which to start the search.
   * @return Position of the last occurrence of any character of the substring, or npos if no such character is
   found.
   */
  constexpr size_type find_last_of(const_reference chr, size_type pos = npos) const noexcept {
    return find_last_of(basic_string_view{::portable_stl::addressof(chr), 1UL}, pos);
  }

  /**
   * @brief Finds the last character equal to one of characters in the given character sequence. Exact search
   algorithm
   * is not specified. The search considers only the interval [0; pos]. If the character is not present in the
   interval,
   * npos will be returned. The behavior is undefined if s contains multi-element symbols (UTF-8, UTF-16).
   *
   * @param str pointer to a character string to search for.
   * @param pos position at which to start the search.
   * @param count length of substring to search for.
   * @return Position of the last occurrence of any character of the substring, or npos if no such character is
   found.
   */
  constexpr size_type find_last_of(const_pointer str, size_type pos, size_type count) const noexcept {
    return find_last_of(basic_string_view{str, count}, pos);
  }

  /**
   * @brief Finds the last character equal to one of characters in the given character sequence. Exact search
   algorithm
   * is not specified. The search considers only the interval [0; pos]. If the character is not present in the
   interval,
   * npos will be returned. The behavior is undefined if s contains multi-element symbols (UTF-8, UTF-16).
   *
   * @param str pointer to a character string to search for.
   * @param pos position at which to start the search.
   * @return Position of the last occurrence of any character of the substring, or npos if no such character is
   found.
   */
  constexpr size_type find_last_of(const_pointer str, size_type pos = npos) const noexcept {
    return find_last_of(basic_string_view{str}, pos);
  }

  /**
   * @brief Finds the first character not equal to any of the characters in the given character sequence.
   * The behavior is undefined if viewcontains multi-element symbols (UTF-8, UTF-16).
   *
   * @param view View to search for.
   * @param pos position at which to start the search.
   * @return Position of the first character not equal to any of the characters in the given string, or npos if no
   such
   * character is found.
   */
  size_type find_first_not_of(basic_string_view view, size_type pos = 0UL) const noexcept {
    if (!view.empty() && (pos < size())) {
      auto const compare_start = view.begin();
      auto const compare_end   = view.end();
      auto const result        = ::portable_stl::find_if_not(
        (begin() + pos), end(), [&compare_start, &compare_end](const_reference source) -> bool {
          return ::portable_stl::any_of(compare_start, compare_end, [source](const_reference compare) -> bool {
            return traits_type::eq(source, compare);
          });
        });
      return ((end() == result) ? npos : static_cast<size_type>(::portable_stl::distance(begin(), result)));
    }
    return ((pos < size()) ? pos : npos);
  }

  /**
   * @brief Finds the first character not equal to any of the characters in the given character sequence.
   * The behavior is undefined if chr contains multi-element symbols (UTF-8, UTF-16).
   *
   * @param chr character to search for.
   * @param pos position at which to start the search.
   * @return Position of the first character not equal to any of the characters in the given string, or npos if no
   such
   * character is found.
   */
  constexpr size_type find_first_not_of(const_reference chr, size_type pos = 0UL) const noexcept {
    return find_first_not_of(basic_string_view{::portable_stl::addressof(chr), 1UL}, pos);
  }

  /**
   * @brief Finds the first character not equal to any of the characters in the given character sequence.
   * The behavior is undefined if s contains multi-element symbols (UTF-8, UTF-16).
   *
   * @param str pointer to a character string to search for.
   * @param pos position at which to start the search.
   * @param count length of substring to search for.
   * @return Position of the first character not equal to any of the characters in the given string, or npos if no
   such
   * character is found.
   */
  constexpr size_type find_first_not_of(const_pointer str, size_type pos, size_type count) const noexcept {
    return find_first_not_of(basic_string_view{str, count}, pos);
  }

  /**
   * @brief Finds the first character not equal to any of the characters in the given character sequence.
   * The behavior is undefined if s contains multi-element symbols (UTF-8, UTF-16).
   *
   * @param str pointer to a character string to search for.
   * @param pos position at which to start the search.
   * @return Position of the first character not equal to any of the characters in the given string, or npos if no
   such
   * character is found.
   */
  constexpr size_type find_first_not_of(const_pointer str, size_type pos = 0UL) const noexcept {
    return find_first_not_of(basic_string_view{str}, pos);
  }

  /**
   * @brief Finds the last character not equal to any of the characters in the given character sequence.
   * The behavior is undefined if viewcontains multi-element symbols (UTF-8, UTF-16).
   *
   * @param view View to search for.
   * @param pos position at which to start the search.
   * @return Position of the last character not equal to any of the characters in the given string, or npos if no
   such
   * character is found.
   */
  size_type find_last_not_of(basic_string_view view, size_type pos = npos) const noexcept {
    pos = ::portable_stl::min(pos, size());
    if (pos < size()) {
      ++pos;
    }
    reverse_iterator result{begin() + pos};
    if (!(view.empty())) {
      auto const compare_start = view.begin();
      auto const compare_end   = view.end();
      result
        = ::portable_stl::find_if_not(result, rend(), [&compare_start, &compare_end](const_reference source) -> bool {
            return ::portable_stl::any_of(compare_start, compare_end, [source](const_reference compare) -> bool {
              return traits_type::eq(source, compare);
            });
          });
    }
    return ((rend() == result) ? npos : static_cast<size_type>(::portable_stl::distance(result, rend())) - 1UL);
  }

  /**
   * @brief Finds the last character not equal to any of the characters in the given character sequence.
   * The behavior is undefined if chr contains multi-element symbols (UTF-8, UTF-16).
   *
   * @param chr character to search for.
   * @param pos position at which to start the search.
   * @return Position of the last character not equal to any of the characters in the given string, or npos if no
   such
   * character is found.
   */
  constexpr size_type find_last_not_of(const_reference chr, size_type pos = npos) const noexcept {
    return find_last_not_of(basic_string_view{::portable_stl::addressof(chr), 1UL}, pos);
  }

  /**
   * @brief Finds the last character not equal to any of the characters in the given character sequence.
   * The behavior is undefined if s contains multi-element symbols (UTF-8, UTF-16).
   *
   * @param str pointer to a character string to search for.
   * @param pos position at which to start the search.
   * @param count length of substring to search for.
   * @return Position of the last character not equal to any of the characters in the given string, or npos if no
   such
   * character is found.
   */
  constexpr size_type find_last_not_of(const_pointer str, size_type pos, size_type count) const noexcept {
    return find_last_not_of(basic_string_view{str, count}, pos);
  }

  /**
   * @brief Finds the last character not equal to any of the characters in the given character sequence.
   * The behavior is undefined if s contains multi-element symbols (UTF-8, UTF-16).
   *
   * @param str pointer to a character string to search for.
   * @param pos position at which to start the search.
   * @return Position of the last character not equal to any of the characters in the given string, or npos if no
   such
   * character is found.
   */
  constexpr size_type find_last_not_of(const_pointer str, size_type pos = npos) const noexcept {
    return find_last_not_of(basic_string_view{str}, pos);
  }
};

// [string.view.comparison]

/**
 * @brief Compares two views.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs view to compare.
 * @param rhs view to compare.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator==(::portable_stl::basic_string_view<t_char_type, t_char_traits_type> const &lhs,
                          ::portable_stl::basic_string_view<t_char_type, t_char_traits_type> const &rhs) noexcept {
  return lhs.compare(rhs) == 0;
}

/**
 * @brief Compares two views.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs view to compare.
 * @param rhs view to compare.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator!=(::portable_stl::basic_string_view<t_char_type, t_char_traits_type> lhs,
                          ::portable_stl::basic_string_view<t_char_type, t_char_traits_type> rhs) noexcept {
  return lhs.compare(rhs) != 0;
}

/**
 * @brief Compares two views.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs view to compare.
 * @param rhs view to compare.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator<(::portable_stl::basic_string_view<t_char_type, t_char_traits_type> lhs,
                         ::portable_stl::basic_string_view<t_char_type, t_char_traits_type> rhs) noexcept {
  return lhs.compare(rhs) < 0;
}

/**
 * @brief Compares two views.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs view to compare.
 * @param rhs view to compare.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator<=(::portable_stl::basic_string_view<t_char_type, t_char_traits_type> lhs,
                          ::portable_stl::basic_string_view<t_char_type, t_char_traits_type> rhs) noexcept {
  return lhs.compare(rhs) <= 0;
}
/**
 * @brief Compares two views.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs view to compare.
 * @param rhs view to compare.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator>(::portable_stl::basic_string_view<t_char_type, t_char_traits_type> lhs,
                         ::portable_stl::basic_string_view<t_char_type, t_char_traits_type> rhs) noexcept {
  return lhs.compare(rhs) > 0;
}

/**
 * @brief Compares two views.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs view to compare.
 * @param rhs view to compare.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator>=(::portable_stl::basic_string_view<t_char_type, t_char_traits_type> lhs,
                          ::portable_stl::basic_string_view<t_char_type, t_char_traits_type> rhs) noexcept {
  return lhs.compare(rhs) >= 0;
}

/**
 * @brief Compares view and null terminated character string.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs pointer to a character string to compare for.
 * @param rhs view to compare.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator==(
  typename ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>::const_pointer lhs,
  ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>                         rhs) noexcept {
  return ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>{lhs}.compare(rhs) == 0;
}

/**
 * @brief Compares view and null terminated character string.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs pointer to a character string to compare for.
 * @param rhs view to compare.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator!=(
  typename ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>::const_pointer lhs,
  ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>                         rhs) noexcept {
  return ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>{lhs}.compare(rhs) != 0;
}

/**
 * @brief Compares view and null terminated character string.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs pointer to a character string to compare for.
 * @param rhs view to compare.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator<(typename ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>::const_pointer lhs,
                         ::portable_stl::basic_string_view<t_char_type, t_char_traits_type> rhs) noexcept {
  return ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>{lhs}.compare(rhs) < 0;
}

/**
 * @brief Compares view and null terminated character string.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs pointer to a character string to compare for.
 * @param rhs view to compare.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator<=(
  typename ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>::const_pointer lhs,
  ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>                         rhs) noexcept {
  return ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>{lhs}.compare(rhs) <= 0;
}

/**
 * @brief Compares view and null terminated character string.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs pointer to a character string to compare for.
 * @param rhs view to compare.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator>(typename ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>::const_pointer lhs,
                         ::portable_stl::basic_string_view<t_char_type, t_char_traits_type> rhs) noexcept {
  return ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>{lhs}.compare(rhs) > 0;
}

/**
 * @brief Compares view and null terminated character string.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs pointer to a character string to compare for.
 * @param rhs view to compare.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator>=(
  typename ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>::const_pointer lhs,
  ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>                         rhs) noexcept {
  return ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>{lhs}.compare(rhs) >= 0;
}

/**
 * @brief Compares view and null terminated character string.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs view to compare.
 * @param rhs pointer to a character string to compare for.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator==(
  ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>                         lhs,
  typename ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>::const_pointer rhs) noexcept {
  return lhs.compare(rhs) == 0;
}

/**
 * @brief Compares view and null terminated character string.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs view to compare.
 * @param rhs pointer to a character string to compare for.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator!=(
  ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>                         lhs,
  typename ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>::const_pointer rhs) noexcept {
  return lhs.compare(rhs) != 0;
}

/**
 * @brief Compares view and null terminated character string.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs view to compare.
 * @param rhs pointer to a character string to compare for.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator<(
  ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>                         lhs,
  typename ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>::const_pointer rhs) noexcept {
  return lhs.compare(rhs) < 0;
}

/**
 * @brief Compares view and null terminated character string.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs view to compare.
 * @param rhs pointer to a character string to compare for.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator<=(
  ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>                         lhs,
  typename ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>::const_pointer rhs) noexcept {
  return lhs.compare(rhs) <= 0;
}

/**
 * @brief Compares view and null terminated character string.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs view to compare.
 * @param rhs pointer to a character string to compare for.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator>(
  ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>                         lhs,
  typename ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>::const_pointer rhs) noexcept {
  return lhs.compare(rhs) > 0;
}

/**
 * @brief Compares view and null terminated character string.
 * @tparam t_char_type view character type.
 * @tparam t_char_traits_type view character traits type.
 * @param lhs view to compare.
 * @param rhs pointer to a character string to compare for.
 * @return result of compare.
 */
template<class t_char_type, class t_char_traits_type>
constexpr bool operator>=(
  ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>                         lhs,
  typename ::portable_stl::basic_string_view<t_char_type, t_char_traits_type>::const_pointer rhs) noexcept {
  return lhs.compare(rhs) >= 0;
}
} // namespace portable_stl

#endif // PSTL_BASIC_STRING_VIEW_H
