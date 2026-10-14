// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="short_object_optimization.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SHORT_OBJECT_OPTIMIZATION_H
#define PSTL_SHORT_OBJECT_OPTIMIZATION_H

#include "../algorithm/max.h"
#include "../algorithm/min.h"
#include "../error/portable_stl_error.h"
#include "../language_support/bad_alloc.h"
#include "../memory/addressof.h"
#include "../memory/allocate_noexcept.h"
#include "../memory/allocator_traits.h"
#include "../memory/compressed_pair.h"
#include "../memory/memcpy.h"
#include "../memory/memmove.h"
#include "../memory/memset.h"
#include "../memory/to_address.h"
#include "../memory/unique_ptr.h"
#include "../utility/expected/exception_pack.h"
#include "../utility/general/move.h"
#include "../common/cstdint.h"

#if defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  include "../language_support/exception/throw_on_true.h"
#else
#  include "../language_support/no_exception/throw_on_true.h"
#endif

namespace portable_stl {

template<class t_allocator,
         bool = sizeof(typename ::portable_stl::allocator_traits<t_allocator>::value_type) == sizeof(unsigned char)>
class short_object_optimization {
public:
  using allocator_type = t_allocator;
  using pointer        = typename ::portable_stl::allocator_traits<allocator_type>::pointer;
  using const_pointer  = typename ::portable_stl::allocator_traits<allocator_type>::const_pointer;
  using size_type      = typename ::portable_stl::allocator_traits<allocator_type>::size_type;
  using value_type     = typename ::portable_stl::allocator_traits<allocator_type>::value_type;

private:
#ifndef PORTABLE_STL_BIG_ENDIAN // LITTLE
  constexpr static size_type m_short_mask() noexcept {
    return 0x80UL;
  }
  constexpr static size_type m_long_mask_set() noexcept {
    return ~(~(size_type{0U}) >> size_type{1UL});
  }
  constexpr static size_type m_long_mask_clean() noexcept {
    return m_long_mask_set() - 1U;
  }
#else // PORTABLE_STL_BIG_ENDIAN
  constexpr static size_type m_short_mask() noexcept {
    return 0x1UL;
  }
  constexpr static size_type m_long_mask_set() noexcept {
    return 0x1UL;
  }
  constexpr static size_type m_long_mask_clean() noexcept {
    return ~(m_long_mask_set);
  }
#endif

  /* 24 23 22 21 20 19 18 17 16|15 14 13 12 11 10  9  8| 7  6  5  4  3  2  1  0|                            */
  /*                                                                                                        */
  /*   |            m_capacity |                m_size |                m_data |  -- long_storage           */
  /*                                                                                                        */
  /*   |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  -- raw_storage            */
  /*                                                                                                        */
  /*   |  | c| c| c| c| c| c| c| c| c| c| c| c| c| c| c| c| c| c| c| c| c| c| c|  -- short_storage (char)   */
  /*     ^                                                                                                  */
  /*     '---- size:padding:: m_size                                                                        */
  /*                                                                                                        */
  /*   |  |  |   c |   c |   c |   c |   c |   c |   c |   c |   c |   c |   c |  -- short_storage (wchar)  */
  /*     ^  ^                                                                                      2 byte   */
  /*     '  '--------- size:padding:: m_padding[1]                                                          */
  /*     '---- size:padding:: m_size                                                                        */
  /*                                                                                                        */
  /*   |  |        |         c |         c |         c |         c |         c |  -- short_storage (wchar)  */
  /*     ^        ^                                                                                4 byte   */
  /*     '        '--- size:padding:: m_padding[3]                                                          */
  /*     '---- size:padding:: m_size                                                                        */

  struct long_storage {
    pointer   m_data;
    size_type m_size;
    size_type m_capacity;
  };

  constexpr static size_type const words_count = sizeof(long_storage) / sizeof(size_type);

  struct raw_storage {
    size_type m_words[words_count];
  };

public:
  constexpr static size_type short_data_max() noexcept {
    return (::portable_stl::max(sizeof(long_storage), sizeof(raw_storage)) - sizeof(value_type)) / sizeof(value_type);
  }

private:
  constexpr static size_type padding_size() noexcept {
    return sizeof(value_type) - sizeof(unsigned char);
  }

  struct short_storage {
    value_type m_data[short_data_max()];
    struct {
      unsigned char m_padding[padding_size()];
      unsigned char m_size;
    } size;
  };

  struct storage_object {
    union {
      long_storage  m_long;
      short_storage m_short;
      raw_storage   m_raw;
    };
  };

  class deleter : private allocator_type {
  public:
    using pointer = typename short_object_optimization::pointer;

    explicit deleter(allocator_type const &alloc) noexcept : allocator_type(alloc) {
    }

    // no exceptions here: deallocate() 'catch' possible exceptions inside.
    ::portable_stl::expected<void, ::portable_stl::int32_t> operator()(pointer ptr) noexcept {
      this->deallocate(ptr, sizeof(value_type));
      return {};
    }
  };

  using storage = ::portable_stl::compressed_pair<storage_object, allocator_type>;

  storage m_storage;

  bool is_long() const noexcept {
    return 0 != (m_storage.get_first().m_short.size.m_size & m_short_mask());
  }

  void zero() noexcept {
    ::portable_stl::memset(
      ::portable_stl::addressof(m_storage.get_first().m_raw), 0U, sizeof(m_storage.get_first().m_raw));
  }

public:
  explicit short_object_optimization(allocator_type allocator = allocator_type{}) noexcept
      : m_storage(::portable_stl::second_tag_t{}, ::portable_stl::move(allocator)) {
  }

  short_object_optimization(short_object_optimization const &other) noexcept(
    noexcept(short_object_optimization(other, other.get_allocator())))
      : short_object_optimization(other, other.get_allocator()) {
  }

  size_type capacity() const noexcept {
    return is_long() ? (m_storage.get_first().m_long.m_capacity & m_long_mask_clean())
                     : sizeof(m_storage.get_first().m_short.m_data) / sizeof(value_type);
  }

  short_object_optimization(short_object_optimization const &other, allocator_type const &allocator)
      : m_storage(other.m_storage.get_first(), allocator) {
    if (is_long()) {
      ::portable_stl::unique_ptr<value_type, deleter> temp{
        ::portable_stl::allocate_noexcept(m_storage.get_second(), capacity()), deleter{m_storage.get_second()}};
      if (temp) {
        ::portable_stl::memcpy(
          ::portable_stl::to_address(temp.get()), ::portable_stl::to_address(data()), size() * sizeof(value_type));
        // do not miss '\0' terminator
        temp.get()[size()] = value_type{};
        m_storage.get_first().m_long.m_data = temp.release();
      } else {
        ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(true);
      }
    }
  }

  short_object_optimization(short_object_optimization &&other) noexcept
      : m_storage(::portable_stl::move(other.m_storage)) {
    other.zero();
  }

  short_object_optimization(short_object_optimization &&other, allocator_type const &allocator) noexcept(
    noexcept(storage{::portable_stl::move(other.m_storage.get_first()), allocator}))
      : m_storage(::portable_stl::move(other.m_storage.get_first()), allocator) {
    other.zero();
  }

  ~short_object_optimization() noexcept(
    noexcept(deleter(m_storage.get_second())(m_storage.get_first().m_long.m_data))) {
    if (is_long()) {
      deleter(m_storage.get_second())(m_storage.get_first().m_long.m_data);
    }
  }

  short_object_optimization &operator=(short_object_optimization const &other) noexcept(
    noexcept(short_object_optimization{other})) {
    short_object_optimization temp{other};
    swap(temp);
    return *this;
  }

  short_object_optimization &operator=(short_object_optimization &&other) noexcept {
    short_object_optimization temp{::portable_stl::move(other)};
    swap(temp);
    return *this;
  }

  void swap(short_object_optimization &other) noexcept {
    ::portable_stl::swap(m_storage, other.m_storage);
  }

  size_type size() const noexcept {
    return is_long() ? m_storage.get_first().m_long.m_size : m_storage.get_first().m_short.size.m_size;
  }

  pointer data() noexcept {
    return is_long() ? m_storage.get_first().m_long.m_data
                     : pointer_traits<pointer>::pointer_to(*m_storage.get_first().m_short.m_data);
  }

  const_pointer data() const noexcept {
    return is_long() ? m_storage.get_first().m_long.m_data
                     : pointer_traits<const_pointer>::pointer_to(*m_storage.get_first().m_short.m_data);
  }

  void set_allocator(allocator_type const &allocator) noexcept {
    m_storage.get_second() = allocator;
  }

  allocator_type const &get_allocator() const noexcept {
    return m_storage.get_second();
  }

  /**
   * @brief Insert range into stored objects.
   * Can call reserve only if need increase space for storage object.
   * Move objects from end of source range to position after inserted range.
   * Source range split by index:
   *
   * [ begin, end ) -> [ begin, index ) + [ 0, ins_size ) + [ index, end )
   *    'old data'      'begin of old'      'inserted'      'end old data'
   *   initialized  |     initialized   |  uninitialized  |  initialized
   *
   * @param index position for insert range.
   * @param insert_size count of objects to insert.
   */
  bool insert(size_type index, size_type insert_size) noexcept {
    auto const old_size = size();
    if (reserve(old_size + 1 + insert_size)) {
      // copy-move of 'end old data': this part ALWAYS contains '\0', so add +1
      static_cast<void>(::portable_stl::memmove(::portable_stl::to_address(data() + index + insert_size),
                                                ::portable_stl::to_address(data() + index),
                                                (old_size - index + 1) * sizeof(value_type)));
      set_size(size() + insert_size);
      return true;
    }
    return false;
  }

  /**
   * @brief Replace range from stored objects with another range.
   * Can call reserve only if need increase space for storage object.
   * Move objects from end of source range to position after inserted range.
   * Source range split by index with cut to replacement_size:
   *
   * [ begin, end ) -> [ begin, index ) + [ 0, what_size ) + [ replacement_size, end )
   *    'old data'      'begin of old'       'inserted'           'end old data'
   *   initialized  |     initialized   |  uninitialized   |        initialized
   *
   * @param index of replacement range begin.
   * @param replacement_size replacement range size.
   * @param what_size new range size.
   */
  bool replace(size_type index, size_type replacement_size, size_type what_size) noexcept {
    auto const old_size = size();
    bool       no_error{true};
    if (what_size > replacement_size) {
      no_error = reserve(old_size + what_size - replacement_size + 1);
    }
    if (no_error) {
      static_cast<void>(::portable_stl::memmove(::portable_stl::to_address(data() + index + what_size),
                                                ::portable_stl::to_address(data() + index + replacement_size),
                                                old_size - (index + replacement_size) + 1));

      if (replacement_size > what_size) {
        // always change size down: may move data to short string but not reallocate!
        static_cast<void>(reserve(old_size + what_size - replacement_size));
      }
      set_size(old_size + what_size - replacement_size);
      return true;
    }
    return false;
  }

  bool reserve(size_type requested_capacity, bool shrink_to_fit = false) noexcept {
    auto       new_capacity = requested_capacity;
    auto const cap          = capacity();
    // do not shrink allocated chunk implicitly
    if ((requested_capacity < cap) && (!shrink_to_fit)) {
      new_capacity = cap;
    }
    // SSO case
    if (requested_capacity <= short_data_max()) {
      new_capacity = short_data_max();
    }
    if (cap == new_capacity) {
      return true;
    }

    auto const old_size = size();
    auto const old_data = data();
    if (short_data_max() == new_capacity) {
      // copy old data + '\0' into newly allocated buffer.
      ::portable_stl::memcpy(::portable_stl::addressof(m_storage.get_first().m_short.m_data),
                             ::portable_stl::to_address(old_data),
                             sizeof(value_type) * ::portable_stl::min(old_size + 1, short_data_max()));
      m_storage.get_first().m_short.size.m_size
        = static_cast<unsigned char>(::portable_stl::min(old_size, short_data_max()));
      deleter(m_storage.get_second())(old_data);
      return true;
    }

    // no exceptions here: allocate() returns valid pointer or nullptr.
    ::portable_stl::unique_ptr<value_type, deleter> temp{
      ::portable_stl::allocate_noexcept(m_storage.get_second(), new_capacity), deleter{m_storage.get_second()}};
    if (temp) {
      // copy old data + '\0' into newly allocated buffer.
      ::portable_stl::memcpy(::portable_stl::to_address(temp.get()),
                             ::portable_stl::to_address(old_data),
                             (old_size + 1) * sizeof(value_type));
      auto const last_long                    = is_long();
      m_storage.get_first().m_long.m_data     = temp.release();
      m_storage.get_first().m_long.m_capacity = (new_capacity | m_long_mask_set());
      if (last_long) {
        // no exceptions here: deallocate() 'catchs' possible exceptions inside.
        deleter(m_storage.get_second())(old_data);
      } else {
        m_storage.get_first().m_long.m_size = old_size;
      }
      return true;
    }
    return false;
  }

  void set_size(size_type new_size) noexcept {
    // update size field
    if (is_long()) {
      m_storage.get_first().m_long.m_size = new_size;
    } else {
      m_storage.get_first().m_short.size.m_size = static_cast<unsigned char>(new_size);
    }
  }
};

// -----------------------------------

template<class t_allocator> class short_object_optimization<t_allocator, true> {
public:
  using allocator_type = t_allocator;
  using pointer        = typename ::portable_stl::allocator_traits<allocator_type>::pointer;
  using const_pointer  = typename ::portable_stl::allocator_traits<allocator_type>::const_pointer;
  using size_type      = typename ::portable_stl::allocator_traits<allocator_type>::size_type;
  using value_type     = typename ::portable_stl::allocator_traits<allocator_type>::value_type;

private:
#ifndef PORTABLE_STL_BIG_ENDIAN // LITTLE
  constexpr static size_type m_short_mask() noexcept {
    return 0x80UL;
  }
  constexpr static size_type m_long_mask_set() noexcept {
    return ~(~(size_type{0U}) >> size_type{1UL});
  }
  constexpr static size_type m_long_mask_clean() noexcept {
    return m_long_mask_set() - 1U;
  }
#else // PORTABLE_STL_BIG_ENDIAN
  constexpr static size_type m_short_mask() noexcept {
    return 0x1UL;
  }
  constexpr static size_type m_long_mask_set() noexcept {
    return 0x1UL;
  }
  constexpr static size_type m_long_mask_clean() noexcept {
    return ~(m_long_mask_set);
  }
#endif

  struct long_storage {
    pointer   m_data;
    size_type m_size;
    size_type m_capacity;
  };

  constexpr static size_type const words_count = sizeof(long_storage) / sizeof(size_type);

  struct raw_storage {
    size_type m_words[words_count];
  };

public:
  constexpr static size_type short_data_max() noexcept {
    return (::portable_stl::max(sizeof(long_storage), sizeof(raw_storage)) - sizeof(value_type)) / sizeof(value_type);
  }

private:
  struct short_storage {
    value_type m_data[short_data_max()];
    struct {
      unsigned char m_size;
    } size;
  };

  struct storage_object {
    union {
      long_storage  m_long;
      short_storage m_short;
      raw_storage   m_raw;
    };
  };

  class deleter : private allocator_type {
  public:
    using pointer = typename short_object_optimization::pointer;

    explicit deleter(allocator_type const &alloc) noexcept : allocator_type(alloc) {
    }

    // no exceptions here: deallocate() 'catch' possible exceptions inside.
    ::portable_stl::expected<void, ::portable_stl::int32_t> operator()(pointer ptr) noexcept {
      this->deallocate(ptr, sizeof(value_type));
      return {};
    }
  };

  using storage = ::portable_stl::compressed_pair<storage_object, allocator_type>;

  storage m_storage;

  bool is_long() const noexcept {
    return 0 != (m_storage.get_first().m_short.size.m_size & m_short_mask());
  }

  void zero() noexcept {
    ::portable_stl::memset(
      ::portable_stl::addressof(m_storage.get_first().m_raw), 0U, sizeof(m_storage.get_first().m_raw));
  }

public:
  explicit short_object_optimization(allocator_type allocator = allocator_type{}) noexcept
      : m_storage(::portable_stl::second_tag_t{}, ::portable_stl::move(allocator)) {
  }

  short_object_optimization(short_object_optimization const &other) noexcept(
    noexcept(short_object_optimization(other, other.get_allocator())))
      : short_object_optimization(other, other.get_allocator()) {
  }

  size_type capacity() const noexcept {
    return is_long() ? (m_storage.get_first().m_long.m_capacity & m_long_mask_clean())
                     : sizeof(m_storage.get_first().m_short.m_data) / sizeof(value_type);
  }

  short_object_optimization(short_object_optimization const &other, allocator_type const &allocator)
      : m_storage(other.m_storage.get_first(), allocator) {
    if (is_long()) {
      ::portable_stl::unique_ptr<value_type, deleter> temp{
        ::portable_stl::allocate_noexcept(m_storage.get_second(), capacity()), deleter{m_storage.get_second()}};
      if (temp) {
        ::portable_stl::memcpy(
          ::portable_stl::to_address(temp.get()), ::portable_stl::to_address(data()), size() * sizeof(value_type));
        // do not miss '\0' terminator
        ::portable_stl::memset(::portable_stl::to_address(&temp.get()[size() * sizeof(value_type)]), 0, 1);
        m_storage.get_first().m_long.m_data = temp.release();
      } else {
        ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(true);
      }
    }
  }

  short_object_optimization(short_object_optimization &&other) noexcept
      : m_storage(::portable_stl::move(other.m_storage)) {
    other.zero();
  }

  short_object_optimization(short_object_optimization &&other, allocator_type const &allocator) noexcept(
    noexcept(storage{::portable_stl::move(other.m_storage.get_first()), allocator}))
      : m_storage(::portable_stl::move(other.m_storage.get_first()), allocator) {
    other.zero();
  }

  ~short_object_optimization() noexcept(
    noexcept(deleter(m_storage.get_second())(m_storage.get_first().m_long.m_data))) {
    if (is_long()) {
      deleter(m_storage.get_second())(m_storage.get_first().m_long.m_data);
    }
  }

  short_object_optimization &operator=(short_object_optimization const &other) noexcept(
    noexcept(short_object_optimization{other})) {
    short_object_optimization temp{other};
    swap(temp);
    return *this;
  }

  short_object_optimization &operator=(short_object_optimization &&other) noexcept {
    short_object_optimization temp{::portable_stl::move(other)};
    swap(temp);
    return *this;
  }

  void swap(short_object_optimization &other) noexcept {
    ::portable_stl::swap(m_storage, other.m_storage);
  }

  size_type size() const noexcept {
    return is_long() ? m_storage.get_first().m_long.m_size : m_storage.get_first().m_short.size.m_size;
  }

  pointer data() noexcept {
    return is_long() ? m_storage.get_first().m_long.m_data
                     : pointer_traits<pointer>::pointer_to(*m_storage.get_first().m_short.m_data);
  }

  const_pointer data() const noexcept {
    return is_long() ? m_storage.get_first().m_long.m_data
                     : pointer_traits<const_pointer>::pointer_to(*m_storage.get_first().m_short.m_data);
  }

  void set_allocator(allocator_type const &allocator) noexcept {
    m_storage.get_second() = allocator;
  }

  allocator_type const &get_allocator() const noexcept {
    return m_storage.get_second();
  }

  /**
   * @brief Insert range into stored objects.
   * Can call reserve only if need increase space for storage object.
   * Move objects from end of source range to position after inserted range.
   * Source range split by index:
   *
   * [ begin, end ) -> [ begin, index ) + [ 0, ins_size ) + [ index, end )
   *    'old data'      'begin of old'      'inserted'      'end old data'
   *   initialized  |     initialized   |  uninitialized  |  initialized
   *
   * @param index position for insert range.
   * @param insert_size count of objects to insert.
   */
  bool insert(size_type index, size_type insert_size) noexcept {
    auto const old_size = size();
    if (reserve(old_size + 1 + insert_size)) {
      // copy-move of 'end old data': this part ALWAYS contains '\0', so add +1
      static_cast<void>(::portable_stl::memmove(::portable_stl::to_address(data() + index + insert_size),
                                                ::portable_stl::to_address(data() + index),
                                                (old_size - index + 1) * sizeof(value_type)));
      set_size(size() + insert_size);
      return true;
    }
    return false;
  }

  /**
   * @brief Replace range from stored objects with another range.
   * Can call reserve only if need increase space for storage object.
   * Move objects from end of source range to position after inserted range.
   * Source range split by index with cut to replacement_size:
   *
   * [ begin, end ) -> [ begin, index ) + [ 0, what_size ) + [ replacement_size, end )
   *    'old data'      'begin of old'       'inserted'           'end old data'
   *   initialized  |     initialized   |  uninitialized   |        initialized
   *
   * @param index of replacement range begin.
   * @param replacement_size replacement range size.
   * @param what_size new range size.
   */
  bool replace(size_type index, size_type replacement_size, size_type what_size) noexcept {
    auto const old_size = size();
    bool       no_error{true};
    if (what_size > replacement_size) {
      no_error = reserve(old_size + what_size - replacement_size + 1);
    }
    if (no_error) {
      static_cast<void>(::portable_stl::memmove(::portable_stl::to_address(data() + index + what_size),
                                                ::portable_stl::to_address(data() + index + replacement_size),
                                                old_size - (index + replacement_size) + 1));

      if (replacement_size > what_size) {
        // always change size down: may move data to short string but not reallocate!
        static_cast<void>(reserve(old_size + what_size - replacement_size));
      }
      set_size(old_size + what_size - replacement_size);
      return true;
    }
    return false;
  }

  bool reserve(size_type requested_capacity, bool shrink_to_fit = false) noexcept {
    auto       new_capacity = requested_capacity;
    auto const cap          = capacity();
    // do not shrink allocated chunk implicitly
    if ((requested_capacity < cap) && (!shrink_to_fit)) {
      new_capacity = cap;
    }
    // SSO case
    if (requested_capacity <= short_data_max()) {
      new_capacity = short_data_max();
    }
    if (cap == new_capacity) {
      return true;
    }

    auto const old_size = size();
    auto const old_data = data();
    if (short_data_max() == new_capacity) {
      // copy old data + '\0' into newly allocated buffer.
      ::portable_stl::memcpy(::portable_stl::addressof(m_storage.get_first().m_short.m_data),
                             ::portable_stl::to_address(old_data),
                             sizeof(value_type) * ::portable_stl::min(old_size + 1, short_data_max()));
      m_storage.get_first().m_short.size.m_size
        = static_cast<unsigned char>(::portable_stl::min(old_size, short_data_max()));
      deleter(m_storage.get_second())(old_data);
      return true;
    }

    // no exceptions here: allocate() returns valid pointer or nullptr.
    ::portable_stl::unique_ptr<value_type, deleter> temp{
      ::portable_stl::allocate_noexcept(m_storage.get_second(), new_capacity), deleter{m_storage.get_second()}};
    if (temp) {
      // copy old data + '\0' into newly allocated buffer.
      ::portable_stl::memcpy(::portable_stl::to_address(temp.get()),
                             ::portable_stl::to_address(old_data),
                             (old_size + 1) * sizeof(value_type));
      auto const last_long                    = is_long();
      m_storage.get_first().m_long.m_data     = temp.release();
      m_storage.get_first().m_long.m_capacity = (new_capacity | m_long_mask_set());
      if (last_long) {
        // no exceptions here: deallocate() 'catchs' possible exceptions inside.
        deleter(m_storage.get_second())(old_data);
      } else {
        m_storage.get_first().m_long.m_size = old_size;
      }
      return true;
    }
    return false;
  }

  void set_size(size_type new_size) noexcept {
    // update size field
    if (is_long()) {
      m_storage.get_first().m_long.m_size = new_size;
    } else {
      m_storage.get_first().m_short.size.m_size = static_cast<unsigned char>(new_size);
    }
  }
};

} // namespace portable_stl

#endif // PSTL_SHORT_OBJECT_OPTIMIZATION_H
