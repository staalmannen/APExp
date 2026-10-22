// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="vector_bool.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_VECTOR_BOOL_H
#define PSTL_VECTOR_BOOL_H

#include "../algorithm/copy.h"
#include "../iterator/reverse_iterator.h"
#include "../memory/allocator_traits.h"
#include "../memory/compressed_pair.h"
#include "../memory/rebind_alloc.h"
#include "../metaprogramming/type_traits/has_storage_type.h"
#include "bit_reference.h"
#include "vector.h"

namespace portable_stl {

// template<class, class> class vector;

// template<class t_allocator> class vector<bool, t_allocator>;

template<class t_allocator> class has_storage_type<vector<bool, t_allocator>> final {
public:
  using type = ::portable_stl::true_type;
};

template<class t_allocator> class vector<bool, t_allocator> {
  static_assert(::portable_stl::is_same<typename t_allocator::value_type, bool>{}(),
                "allocator in portable_stl::vector<bool> must have value_type = bool");

public:
  using t_self                 = vector;
  using value_type             = bool;
  using allocator_type         = t_allocator;
  using t_allocator_traits     = ::portable_stl::allocator_traits<allocator_type>;
  using size_type              = typename t_allocator_traits::size_type;
  using difference_type        = typename t_allocator_traits::difference_type;
  using t_storage_type         = size_type;
  using pointer                = ::portable_stl::bit_iterator<vector, false>;
  using const_pointer          = ::portable_stl::bit_iterator<vector, true>;
  using iterator               = pointer;
  using const_iterator         = const_pointer;
  using reverse_iterator       = ::portable_stl::reverse_iterator<iterator>;
  using const_reverse_iterator = ::portable_stl::reverse_iterator<const_iterator>;

  using reference       = ::portable_stl::bit_reference<vector>;
  using const_reference = ::portable_stl::bit_const_reference<vector>;

private:
  using t_storage_allocator     = ::portable_stl::rebind_alloc<t_allocator_traits, t_storage_type>;
  using t_storage_traits        = ::portable_stl::allocator_traits<t_storage_allocator>;
  using t_storage_pointer       = typename t_storage_traits::pointer;
  using t_const_storage_pointer = typename t_storage_traits::const_pointer;

  // /**
  //  * @brief Reference wrapper to value_type. Used in expected return.
  //  */
  // using reference_wrap       = ::portable_stl::reference_wrapper<value_type>;
  /**
   * @brief Reference wrapper to const value_type. Used in expected return.
   */
  using const_reference_wrap = ::portable_stl::reference_wrapper<value_type const>;

  t_storage_pointer                                               m_begin;
  size_type                                                       m_size;
  ::portable_stl::compressed_pair<size_type, t_storage_allocator> m_cap_alloc
    = ::portable_stl::compressed_pair<size_type, t_storage_allocator>(0U, t_storage_allocator());

  size_type &M_cap() noexcept {
    return m_cap_alloc.get_first();
  }
  size_type const &M_cap() const noexcept {
    return m_cap_alloc.get_first();
  }
  t_storage_allocator &M_alloc() noexcept {
    return m_cap_alloc.get_second();
  }
  t_storage_allocator const &M_alloc() const noexcept {
    return m_cap_alloc.get_second();
  }

  static unsigned const m_bits_per_word = static_cast<unsigned>(sizeof(t_storage_type) * 8); // __CHAR_BIT__/CHAR_BIT

  static size_type M_internal_cap_to_external(size_type num) noexcept {
    return num * m_bits_per_word;
  }

  static size_type M_external_cap_to_internal(size_type num) noexcept {
    return (num - 1) / m_bits_per_word + 1;
  }

public:
  vector() noexcept(noexcept(allocator_type()));

  explicit vector(allocator_type const &alloc) noexcept;

private:
  class M_destroy_vector {
  public:
    M_destroy_vector(vector &vec) : m_vec(vec) {
    }

    void operator()() {
      if (m_vec.m_begin != nullptr) {
        t_storage_traits::deallocate(m_vec.M_alloc(), m_vec.m_begin, m_vec.M_cap());
      }
    }

  private:
    vector &m_vec;
  };

public:
  ~vector() {
    M_destroy_vector (*this)();
  }

  explicit vector(size_type num);

  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(size_type num);

  vector(size_type num, allocator_type const &alloc);

  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(size_type             num,
                                                                                          allocator_type const &alloc);

  vector(size_type num, value_type const &value);

  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(size_type         num,
                                                                                          value_type const &value);

  vector(size_type num, value_type const &value, allocator_type const &alloc);

  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(
    size_type num, value_type const &value, allocator_type const &alloc);

  template<class t_input_iterator, vector_helper::enable_for_input_iter_bool<t_input_iterator> = nullptr>
  vector(t_input_iterator first, t_input_iterator last);

  template<class t_input_iterator, vector_helper::enable_for_input_iter_bool<t_input_iterator> = nullptr>
  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(t_input_iterator first,
                                                                                          t_input_iterator last);

  template<class t_input_iterator, vector_helper::enable_for_input_iter_bool<t_input_iterator> = nullptr>
  vector(t_input_iterator first, t_input_iterator last, allocator_type const &alloc);

  template<class t_input_iterator, vector_helper::enable_for_input_iter_bool<t_input_iterator> = nullptr>
  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(
    t_input_iterator first, t_input_iterator last, allocator_type const &alloc);

  template<class t_forward_iterator, vector_helper::enable_for_forward_iter_bool<t_forward_iterator> = nullptr>
  vector(t_forward_iterator first, t_forward_iterator last);

  template<class t_forward_iterator, vector_helper::enable_for_forward_iter_bool<t_forward_iterator> = nullptr>
  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(t_forward_iterator first,
                                                                                          t_forward_iterator last);

  template<class t_forward_iterator, vector_helper::enable_for_forward_iter_bool<t_forward_iterator> = nullptr>
  vector(t_forward_iterator first, t_forward_iterator last, allocator_type const &alloc);

  template<class t_forward_iterator, vector_helper::enable_for_forward_iter_bool<t_forward_iterator> = nullptr>
  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(
    t_forward_iterator first, t_forward_iterator last, allocator_type const &alloc);

  vector(std::initializer_list<value_type> init_list);

  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(
    std::initializer_list<value_type> init_list);

  vector(std::initializer_list<value_type> init_list, allocator_type const &alloc);

  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(
    std::initializer_list<value_type> init_list, allocator_type const &alloc);

  vector(vector const &other);

  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(vector const &other);

  vector(vector const &other, allocator_type const &alloc);

  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(vector const         &other,
                                                                                          allocator_type const &alloc);

  vector(vector &&other) noexcept;

  vector(vector &&other, ::portable_stl::type_identity_t<t_allocator> const &alloc);

  vector &operator=(vector const &other);

  vector &operator=(vector &&other) noexcept(::portable_stl::noexcept_move_assign_container<allocator_type>{}());

  template<class t_input_iterator, vector_helper::enable_for_input_iter_bool<t_input_iterator> = nullptr>
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> assign(t_input_iterator first,
                                                                            t_input_iterator last);

  template<class t_forward_iterator, vector_helper::enable_for_forward_iter_bool<t_forward_iterator> = nullptr>
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> assign(t_forward_iterator first,
                                                                            t_forward_iterator last);

  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> assign(size_type num, value_type const &value);

  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> assign(
    std::initializer_list<value_type> init_list) {
    return assign(init_list.begin(), init_list.end());
  }

  allocator_type get_allocator() const noexcept {
    return allocator_type(M_alloc());
  }

  iterator begin() noexcept {
    return M_make_iter(0);
  }
  const_iterator begin() const noexcept {
    return M_make_iter(0);
  }
  iterator end() noexcept {
    return M_make_iter(m_size);
  }
  const_iterator end() const noexcept {
    return M_make_iter(m_size);
  }

  reverse_iterator rbegin() noexcept {
    return reverse_iterator(end());
  }
  const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator(end());
  }
  reverse_iterator rend() noexcept {
    return reverse_iterator(begin());
  }
  const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator(begin());
  }

  const_iterator cbegin() const noexcept {
    return M_make_iter(0);
  }
  const_iterator cend() const noexcept {
    return M_make_iter(m_size);
  }
  const_reverse_iterator crbegin() const noexcept {
    return rbegin();
  }
  const_reverse_iterator crend() const noexcept {
    return rend();
  }

  bool empty() const noexcept {
    return 0 == m_size;
  }

  size_type size() const noexcept {
    return m_size;
  }

  size_type max_size() const noexcept;

  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> reserve(size_type num);

  size_type capacity() const noexcept {
    return M_internal_cap_to_external(M_cap());
  }

  bool shrink_to_fit() noexcept;

  ::portable_stl::expected<reference, ::portable_stl::portable_stl_error> at(size_type pos) noexcept;

  ::portable_stl::expected<const_reference, ::portable_stl::portable_stl_error> at(size_type pos) const noexcept;

  reference operator[](size_type num) {
    return M_make_ref(num);
  }

  const_reference operator[](size_type num) const {
    return M_make_ref(num);
  }

  reference front() {
    return M_make_ref(0);
  }
  const_reference front() const {
    return M_make_ref(0);
  }
  reference back() {
    return M_make_ref(m_size - 1);
  }
  const_reference back() const {
    return M_make_ref(m_size - 1);
  }

  void clear() noexcept {
    m_size = 0;
  }

  iterator erase(const_iterator position);

  iterator erase(const_iterator first, const_iterator last);

  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> resize(size_type  new_size,
                                                                            value_type value = false);

  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> push_back(value_type const &value);

  template<class... t_args>
  ::portable_stl::expected<reference, ::portable_stl::portable_stl_error> emplace_back(t_args &&...args) {
    return push_back(value_type(::portable_stl::forward<t_args>(args)...)).transform([this]() -> reference {
      return back();
    });
  }

  void pop_back() noexcept {
    --m_size;
  }

  template<class... t_args>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> emplace(const_iterator position,
                                                                                 t_args &&...args) {
    return insert(position, value_type(::portable_stl::forward<t_args>(args)...));
  }

  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(const_iterator    position,
                                                                                value_type const &value);

  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(
    const_iterator position, size_type num, value_type const &value);

  template<class t_input_iterator, vector_helper::enable_for_input_iter_bool<t_input_iterator> = nullptr>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(
    const_iterator position, t_input_iterator first, t_input_iterator last);

  template<class t_forward_iterator, vector_helper::enable_for_forward_iter_bool<t_forward_iterator> = nullptr>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(
    const_iterator position, t_forward_iterator first, t_forward_iterator last);

  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(
    const_iterator position, std::initializer_list<value_type> init_list) {
    return insert(position, init_list.begin(), init_list.end());
  }

  using swap_noexcept
    = ::portable_stl::true_type; //::portable_stl::disjunction<typename t_allocator_traits::propagate_on_container_swap,
                                 // typename t_allocator_traits::is_always_equal>;

  void swap(vector &) noexcept(swap_noexcept{}());

  static void swap(reference lhv, reference rhv) noexcept {
    ::portable_stl::swap(lhv, rhv);
  }

  void flip() noexcept;

private:
  template<class t_iterator, class t_sentinel>
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> M_assign_with_sentinel(t_iterator first,
                                                                                            t_sentinel last);

  template<class t_forward_iterator, class t_sentinel>
  bool M_assign_with_size(t_forward_iterator first, t_sentinel last, difference_type num);

  template<class t_input_iterator, class t_sentinel>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> M_insert_with_sentinel(
    const_iterator position, t_input_iterator first, t_sentinel last);

  template<class t_iterator, class t_sentinel>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> M_insert_with_size(
    const_iterator position, t_iterator first, t_sentinel last, difference_type num_signed);

  t_storage_pointer M_vallocate(size_type num) {
    size_type const num_internal{M_external_cap_to_internal(num)};
    m_begin = ::portable_stl::allocate_noexcept(M_alloc(), num_internal); // exception free wrapper
    if (m_begin) {
      m_size  = 0;
      M_cap() = num_internal;
    }
    return m_begin;
  }

  // static t_storage_pointer M_vallocate(vector &vec, size_type num) {
  //   vec.m_begin
  //     = ::portable_stl::allocate_noexcept(vec.M_alloc(), M_external_cap_to_internal(num)); // exception free wrapper
  //   if (vec.m_begin) {
  //     vec.m_size  = 0;
  //     vec.M_cap() = num;
  //   }
  //   return vec.m_begin;
  // }

  void             M_vdeallocate() noexcept;
  static size_type M_align_it(size_type new_size) noexcept {
    return (new_size + (m_bits_per_word - 1)) & ~(static_cast<size_type>(m_bits_per_word) - 1);
  }
  size_type M_recommend(size_type new_size) const noexcept;

  void M_construct_at_end(size_type num);
  void M_construct_at_end(size_type num, bool value);
  template<class t_input_iterator, class t_sentinel>
  void M_construct_at_end(t_input_iterator first, t_sentinel last, size_type num);

  static void M_construct_at_end(vector &vec, size_type num) noexcept;
  static void M_construct_at_end(vector &vec, size_type num, bool value) noexcept;

  reference M_make_ref(size_type pos) noexcept {
    return reference(m_begin + pos / m_bits_per_word, t_storage_type(1) << pos % m_bits_per_word);
  }

  const_reference M_make_ref(size_type pos) const noexcept {
    return bit_const_reference<vector>(m_begin + pos / m_bits_per_word, t_storage_type(1) << pos % m_bits_per_word);
  }

  iterator M_make_iter(size_type pos) noexcept {
    return iterator(m_begin + pos / m_bits_per_word, static_cast<unsigned>(pos % m_bits_per_word));
  }

  const_iterator M_make_iter(size_type pos) const noexcept {
    return const_iterator(m_begin + pos / m_bits_per_word, static_cast<unsigned>(pos % m_bits_per_word));
  }

  iterator M_const_iterator_cast(const_iterator iter) noexcept {
    return begin() + (iter - cbegin());
  }

  template<class t_input_iterator, class t_sentinel>
  void M_init_with_size(t_input_iterator first, t_sentinel last, size_type num) {
    if (num > 0U) {
      if (M_vallocate(num)) {
        auto guard = ::portable_stl::make_exception_guard(M_destroy_vector(*this)); // for deallocation in constructors
        M_construct_at_end(::portable_stl::move(first), ::portable_stl::move(last), num);
        guard.commit();
      } else {
        throw ::portable_stl::bad_alloc<>{};
      }
    }
  }

  // static
  template<class t_input_iterator, class t_sentinel>
  static ::portable_stl::expected<void, ::portable_stl::portable_stl_error> M_init_with_size(
    vector &vec, t_input_iterator first, t_sentinel last, size_type num) {
    if (num > 0U) {
      if (vec.M_vallocate(num)) {
        vec.M_construct_at_end(::portable_stl::move(first), ::portable_stl::move(last), num);
      } else {
        return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
          ::portable_stl::portable_stl_error::allocate_error};
      }
    }
    return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
  }

  template<class t_input_iterator, class t_sentinel>
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> M_init_with_sentinel(t_input_iterator first,
                                                                                          t_sentinel       last) {
    auto guard = ::portable_stl::make_exception_guard(M_destroy_vector(*this));

    for (; first != last; ++first) {
      auto result = push_back(*first);
      if (!result) {
        return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
      }
    }

    guard.commit();
    return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
  }

  // static
  template<class t_input_iterator, class t_sentinel>
  static ::portable_stl::expected<void, ::portable_stl::portable_stl_error> M_init_with_sentinel(
    vector &vec, t_input_iterator first, t_sentinel last) {
    for (; first != last; ++first) {
      auto result = vec.push_back(*first);
      if (!result) {
        return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
      }
    }
    return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
  }

  void M_copy_assign_alloc(vector const &other) {
    M_copy_assign_alloc(other, typename t_storage_traits::propagate_on_container_copy_assignment{});
  }

  void M_copy_assign_alloc(vector const &other, ::portable_stl::true_type) {
    if (M_alloc() != other.M_alloc()) {
      M_vdeallocate();
    }
    M_alloc() = other.M_alloc();
  }

  void M_copy_assign_alloc(vector const &, ::portable_stl::false_type) {
  }

  void M_move_assign(vector &other, ::portable_stl::true_type) noexcept(
    ::portable_stl::is_nothrow_move_assignable<allocator_type>{}());

  void M_move_assign(vector &other, ::portable_stl::false_type);

  void M_move_assign_alloc(vector &other) noexcept(
    !typename t_allocator_traits::propagate_on_container_move_assignment{}()
    || ::portable_stl::is_nothrow_move_assignable<allocator_type>{}()) {
    M_move_assign_alloc(other, typename t_allocator_traits::propagate_on_container_move_assignment{});
  }
  void M_move_assign_alloc(vector &other, ::portable_stl::true_type) noexcept(
    ::portable_stl::is_nothrow_move_assignable<allocator_type>{}()) {
    M_alloc() = ::portable_stl::move(other.M_alloc());
  }

  void M_move_assign_alloc(vector &, ::portable_stl::false_type) noexcept {
  }

  friend class bit_reference<vector>;
  friend class bit_const_reference<vector>;
  friend class bit_iterator<vector, false>;
  friend class bit_iterator<vector, true>;
  friend struct bit_algo::bit_array<vector>;
};

template<class t_allocator> void vector<bool, t_allocator>::M_vdeallocate() noexcept {
  if (m_begin != nullptr) {
    t_storage_traits::deallocate(M_alloc(), m_begin, M_cap());
    m_begin = nullptr;
    m_size  = 0;
    M_cap() = 0;
  }
}

template<class t_allocator>
typename vector<bool, t_allocator>::size_type vector<bool, t_allocator>::max_size() const noexcept {
  size_type alloc_max   = t_storage_traits::max_size(M_alloc());
  size_type num_lim_max = ::portable_stl::numeric_limits<size_type>::max() / 2; // end() >= begin(), always
  if (num_lim_max / m_bits_per_word <= alloc_max) {
    return num_lim_max;
  }
  return M_internal_cap_to_external(alloc_max);
}

template<class t_allocator>
inline typename vector<bool, t_allocator>::size_type vector<bool, t_allocator>::M_recommend(
  size_type new_size) const noexcept {
  size_type const max_sz{max_size()};
  size_type const old_cap{capacity()};
  if (old_cap >= max_sz / 2) {
    return max_sz;
  }
  return ::portable_stl::max(2 * old_cap, M_align_it(new_size));
}

template<class t_allocator>
inline vector<bool, t_allocator>::vector() noexcept(noexcept(allocator_type())) : m_begin(nullptr), m_size(0U) {
}

template<class t_allocator>
inline vector<bool, t_allocator>::vector(allocator_type const &alloc) noexcept
    : m_begin(nullptr), m_size(0U), m_cap_alloc(0U, static_cast<t_storage_allocator>(alloc)) {
}

template<class t_allocator> inline void vector<bool, t_allocator>::M_construct_at_end(size_type num, bool value) {
  size_type old_size = m_size;
  m_size += num;
  if ((old_size == 0U) || ((old_size - 1) / m_bits_per_word) != ((m_size - 1) / m_bits_per_word)) {
    if (m_size <= m_bits_per_word) {
      m_begin[0] = t_storage_type(0);
    } else {
      m_begin[(m_size - 1) / m_bits_per_word] = t_storage_type(0);
    }
  }
  ::portable_stl::fill_n_bit(M_make_iter(old_size), num, value);
}

template<class t_allocator>
template<class t_input_iterator, class t_sentinel>
void vector<bool, t_allocator>::M_construct_at_end(t_input_iterator first, t_sentinel last, size_type num) {
  size_type old_size = m_size;
  m_size += num;
  if ((old_size == 0U) || ((old_size - 1) / m_bits_per_word) != ((m_size - 1) / m_bits_per_word)) {
    if (m_size <= m_bits_per_word) {
      m_begin[0] = t_storage_type(0);
    } else {
      m_begin[(m_size - 1) / m_bits_per_word] = t_storage_type(0);
    }
  }
  ::portable_stl::copy_impl<::portable_stl::classic_alg_policy>(first, last, M_make_iter(old_size));
}

template<class t_allocator> inline vector<bool, t_allocator>::vector(size_type num) : m_begin(nullptr), m_size(0U) {
  if (num > 0U) {
    if (num > max_size()) {
      throw ::portable_stl::length_error<>{};
    }
    if (M_vallocate(num)) {
      M_construct_at_end(num, false);
    } else {
      throw ::portable_stl::bad_alloc<>{};
    }
  }
}

// static
template<class t_allocator>
::portable_stl::expected<vector<bool, t_allocator>, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::make_vector(size_type num) {
  vector vec;
  if (num > 0U) {
    if (num > vec.max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    if (vec.M_vallocate(num)) {
      vec.M_construct_at_end(num, false);
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
  }
  return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>(::portable_stl::move(vec));
}

template<class t_allocator>
vector<bool, t_allocator>::vector(size_type num, allocator_type const &alloc)
    : m_begin(nullptr), m_size(0U), m_cap_alloc(0U, static_cast<t_storage_allocator>(alloc)) {
  if (num > 0U) {
    if (num > max_size()) {
      throw ::portable_stl::length_error<>{};
    }
    if (M_vallocate(num)) {
      M_construct_at_end(num, false);
    } else {
      throw ::portable_stl::bad_alloc<>{};
    }
  }
}

// static
template<class t_allocator>
::portable_stl::expected<vector<bool, t_allocator>, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::make_vector(size_type num, allocator_type const &alloc) {
  vector vec(alloc);
  if (num > 0U) {
    if (num > vec.max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    if (vec.M_vallocate(num)) {
      vec.M_construct_at_end(num, false);
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
  }
  return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>(::portable_stl::move(vec));
}

template<class t_allocator>
vector<bool, t_allocator>::vector(size_type num, value_type const &value) : m_begin(nullptr), m_size(0U) {
  if (num > 0U) {
    if (num > max_size()) {
      throw ::portable_stl::length_error<>{};
    }
    if (M_vallocate(num)) {
      M_construct_at_end(num, value);
    } else {
      throw ::portable_stl::bad_alloc<>{};
    }
  }
}

// static
template<class t_allocator>
::portable_stl::expected<vector<bool, t_allocator>, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::make_vector(size_type num, value_type const &value) {
  vector vec;
  if (num > 0U) {
    if (num > vec.max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    if (vec.M_vallocate(num)) {
      vec.M_construct_at_end(num, value);
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
  }
  return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>(::portable_stl::move(vec));
}

template<class t_allocator>
vector<bool, t_allocator>::vector(size_type num, value_type const &value, allocator_type const &alloc)
    : m_begin(nullptr), m_size(0U), m_cap_alloc(0U, static_cast<t_storage_allocator>(alloc)) {
  if (num > 0U) {
    if (num > max_size()) {
      throw ::portable_stl::length_error<>{};
    }
    if (M_vallocate(num)) {
      M_construct_at_end(num, value);
    } else {
      throw ::portable_stl::bad_alloc<>{};
    }
  }
}

// static
template<class t_allocator>
::portable_stl::expected<vector<bool, t_allocator>, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::make_vector(size_type num, value_type const &value, allocator_type const &alloc) {
  vector vec(alloc);
  if (num > 0U) {
    if (num > vec.max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    if (vec.M_vallocate(num)) {
      vec.M_construct_at_end(num, value);
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
  }
  return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>(::portable_stl::move(vec));
}

template<class t_allocator>
template<class t_input_iterator, vector_helper::enable_for_input_iter_bool<t_input_iterator>>
vector<bool, t_allocator>::vector(t_input_iterator first, t_input_iterator last) : m_begin(nullptr), m_size(0U) {
  auto result = M_init_with_sentinel(first, last);
  if (!result) {
    if (::portable_stl::portable_stl_error::allocate_error == result.error()) {
      throw ::portable_stl::bad_alloc<>{};
    } else {
      throw ::portable_stl::length_error<>{};
    }
  }
}

// static
template<class t_allocator>
template<class t_input_iterator, vector_helper::enable_for_input_iter_bool<t_input_iterator>>
::portable_stl::expected<vector<bool, t_allocator>, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::make_vector(t_input_iterator first, t_input_iterator last) {
  vector vec;
  return M_init_with_sentinel(vec, first, last).transform([&vec](void) -> vector {
    return ::portable_stl::move(vec);
  });
}

template<class t_allocator>
template<class t_input_iterator, vector_helper::enable_for_input_iter_bool<t_input_iterator>>
vector<bool, t_allocator>::vector(t_input_iterator first, t_input_iterator last, allocator_type const &alloc)
    : m_begin(nullptr), m_size(0U), m_cap_alloc(0U, static_cast<t_storage_allocator>(alloc)) {
  auto result = M_init_with_sentinel(first, last);
  if (!result) {
    if (::portable_stl::portable_stl_error::allocate_error == result.error()) {
      throw ::portable_stl::bad_alloc<>{};
    } else {
      throw ::portable_stl::length_error<>{};
    }
  }
}

// static
template<class t_allocator>
template<class t_input_iterator, vector_helper::enable_for_input_iter_bool<t_input_iterator>>
::portable_stl::expected<vector<bool, t_allocator>, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::make_vector(t_input_iterator first, t_input_iterator last, allocator_type const &alloc) {
  vector vec(alloc);
  return M_init_with_sentinel(vec, first, last).transform([&vec](void) -> vector {
    return ::portable_stl::move(vec);
  });
}

template<class t_allocator>
template<class t_forward_iterator, vector_helper::enable_for_forward_iter_bool<t_forward_iterator>>
vector<bool, t_allocator>::vector(t_forward_iterator first, t_forward_iterator last) : m_begin(nullptr), m_size(0U) {
  auto num = static_cast<size_type>(::portable_stl::distance(first, last));
  if (num > max_size()) {
    throw ::portable_stl::length_error<>{};
  }
  M_init_with_size(first, last, num);
}

// static
template<class t_allocator>
template<class t_forward_iterator, vector_helper::enable_for_forward_iter_bool<t_forward_iterator>>
::portable_stl::expected<vector<bool, t_allocator>, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::make_vector(t_forward_iterator first, t_forward_iterator last) {
  vector vec;
  auto   num = static_cast<size_type>(::portable_stl::distance(first, last));
  if (num > vec.max_size()) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
      ::portable_stl::portable_stl_error::length_error};
  }
  return M_init_with_size(vec, first, last, num).transform([&vec](void) -> vector {
    return ::portable_stl::move(vec);
  });
}

template<class t_allocator>
template<class t_forward_iterator, vector_helper::enable_for_forward_iter_bool<t_forward_iterator>>
vector<bool, t_allocator>::vector(t_forward_iterator first, t_forward_iterator last, allocator_type const &alloc)
    : m_begin(nullptr), m_size(0U), m_cap_alloc(0U, static_cast<t_storage_allocator>(alloc)) {
  auto num = static_cast<size_type>(::portable_stl::distance(first, last));
  if (num > max_size()) {
    throw ::portable_stl::length_error<>{};
  }
  M_init_with_size(first, last, num);
}

// static
template<class t_allocator>
template<class t_forward_iterator, vector_helper::enable_for_forward_iter_bool<t_forward_iterator>>
::portable_stl::expected<vector<bool, t_allocator>, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::make_vector(
    t_forward_iterator first, t_forward_iterator last, allocator_type const &alloc) {
  vector vec(alloc);
  auto   num = static_cast<size_type>(::portable_stl::distance(first, last));
  if (num > vec.max_size()) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
      ::portable_stl::portable_stl_error::length_error};
  }
  return M_init_with_size(vec, first, last, num).transform([&vec](void) -> vector {
    return ::portable_stl::move(vec);
  });
}

template<class t_allocator>
vector<bool, t_allocator>::vector(std::initializer_list<value_type> init_list) : m_begin(nullptr), m_size(0U) {
  size_type num = static_cast<size_type>(init_list.size());
  if (num > 0U) {
    if (num > max_size()) {
      throw ::portable_stl::length_error<>{};
    }
    if (M_vallocate(num)) {
      M_construct_at_end(init_list.begin(), init_list.end(), num);
    } else {
      throw ::portable_stl::bad_alloc<>{};
    }
  }
}

// static
template<class t_allocator>
::portable_stl::expected<vector<bool, t_allocator>, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::make_vector(std::initializer_list<value_type> init_list) {
  vector    vec;
  size_type num = static_cast<size_type>(init_list.size());
  if (num > 0U) {
    if (num > vec.max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    if (vec.M_vallocate(num)) {
      vec.M_construct_at_end(init_list.begin(), init_list.end(), num);
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
  }
  return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>(::portable_stl::move(vec));
}

template<class t_allocator>
vector<bool, t_allocator>::vector(std::initializer_list<value_type> init_list, allocator_type const &alloc)
    : m_begin(nullptr), m_size(0U), m_cap_alloc(0U, static_cast<t_storage_allocator>(alloc)) {
  size_type num = static_cast<size_type>(init_list.size());
  if (num > 0U) {
    if (num > max_size()) {
      throw ::portable_stl::length_error<>{};
    }
    if (M_vallocate(num)) {
      M_construct_at_end(init_list.begin(), init_list.end(), num);
    } else {
      throw ::portable_stl::bad_alloc<>{};
    }
  }
}

// static
template<class t_allocator>
::portable_stl::expected<vector<bool, t_allocator>, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::make_vector(std::initializer_list<value_type> init_list, allocator_type const &alloc) {
  vector    vec(alloc);
  size_type num = static_cast<size_type>(init_list.size());
  if (num > 0U) {
    if (num > vec.max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    if (vec.M_vallocate(num)) {
      vec.M_construct_at_end(init_list.begin(), init_list.end(), num);
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
  }
  return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>(::portable_stl::move(vec));
}

template<class t_allocator>
vector<bool, t_allocator>::vector(vector const &other)
    : m_begin(nullptr)
    , m_size(0U)
    , m_cap_alloc(0U, t_storage_traits::select_on_container_copy_construction(other.M_alloc())) {
  if (other.size() > 0U) {
    if (M_vallocate(other.size())) {
      M_construct_at_end(other.begin(), other.end(), other.size());
    } else {
      throw ::portable_stl::bad_alloc<>{};
    }
  }
}

// static
template<class t_allocator>
::portable_stl::expected<vector<bool, t_allocator>, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::make_vector(vector const &other) {
  vector    vec;
  size_type num = static_cast<size_type>(other.size());
  if (num > 0U) {
    if (num > vec.max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    if (vec.M_vallocate(num)) {
      vec.M_construct_at_end(other.begin(), other.end(), num);
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
  }
  return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>(::portable_stl::move(vec));
}

template<class t_allocator>
vector<bool, t_allocator>::vector(vector const &other, allocator_type const &alloc)
    : m_begin(nullptr), m_size(0U), m_cap_alloc(0U, alloc) {
  if (other.size() > 0U) {
    if (M_vallocate(other.size())) {
      M_construct_at_end(other.begin(), other.end(), other.size());
    } else {
      throw ::portable_stl::bad_alloc<>{};
    }
  }
}

// static
template<class t_allocator>
::portable_stl::expected<vector<bool, t_allocator>, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::make_vector(vector const &other, allocator_type const &alloc) {
  vector    vec(alloc);
  size_type num = static_cast<size_type>(other.size());
  if (num > 0U) {
    if (num > vec.max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    if (vec.M_vallocate(num)) {
      vec.M_construct_at_end(other.begin(), other.end(), num);
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
  }
  return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>(::portable_stl::move(vec));
}

template<class t_allocator>
inline vector<bool, t_allocator>::vector(vector &&other) noexcept
    : m_begin(other.m_begin), m_size(other.m_size), m_cap_alloc(::portable_stl::move(other.m_cap_alloc)) {
  other.m_begin = nullptr;
  other.m_size  = 0U;
  other.M_cap() = 0U;
}

template<class t_allocator>
vector<bool, t_allocator>::vector(vector &&other, ::portable_stl::type_identity_t<t_allocator> const &alloc)
    : m_begin(nullptr), m_size(0U), m_cap_alloc(0U, alloc) {
  if (alloc == allocator_type(other.M_alloc())) {
    m_begin       = other.m_begin;
    m_size        = other.m_size;
    M_cap()       = other.M_cap();
    other.m_begin = nullptr;
    other.M_cap() = 0U;
    other.m_size  = 0U;
  } else if (other.size() > 0U) {
    if (M_vallocate(other.size())) {
      M_construct_at_end(other.begin(), other.end(), other.size());
    } else {
      throw ::portable_stl::bad_alloc<>{};
    }
  }
}

template<class t_allocator> vector<bool, t_allocator> &vector<bool, t_allocator>::operator=(vector const &other) {
  if (this != ::portable_stl::addressof(other)) {
    M_copy_assign_alloc(other);
    if (other.m_size) {
      if (other.m_size > capacity()) {
        M_vdeallocate();
        M_vallocate(other.m_size);
      }
      // storage copy
      ::portable_stl::copy(other.m_begin, other.m_begin + M_external_cap_to_internal(other.m_size), m_begin);
    }
    m_size = other.m_size;
  }
  return *this;
}

template<class t_allocator>
inline vector<bool, t_allocator> &vector<bool, t_allocator>::operator=(vector &&other) noexcept(
  ::portable_stl::noexcept_move_assign_container<allocator_type>{}()) {
  M_move_assign(other, typename t_storage_traits::propagate_on_container_move_assignment{});
  return *this;
}

template<class t_allocator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> vector<bool, t_allocator>::assign(
  size_type num, value_type const &value) {
  m_size = 0U;
  if (num > 0U) {
    if (num <= capacity()) {
      m_size = num;
    } else {
      if (num > max_size()) {
        return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
          ::portable_stl::portable_stl_error::length_error};
      }
      vector tmp_vec(get_allocator());
      auto   result = tmp_vec.reserve(M_recommend(num));
      if (!result) {
        return result;
      }
      tmp_vec.m_size = num;
      swap(tmp_vec);
    }
    ::portable_stl::fill_n_bit(begin(), num, value);
  }
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

template<class t_allocator>
template<class t_iterator, class t_sentinel>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> vector<bool, t_allocator>::M_assign_with_sentinel(
  t_iterator first, t_sentinel last) {
  clear();
  for (; first != last; ++first) {
    auto result = push_back(*first);
    if (!result) {
      return result;
    }
  }
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

template<class t_allocator>
template<class t_input_iterator, vector_helper::enable_for_input_iter_bool<t_input_iterator>>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> vector<bool, t_allocator>::assign(
  t_input_iterator first, t_input_iterator last) {
  return M_assign_with_sentinel(first, last);
}

template<class t_allocator>
template<class t_forward_iterator, class t_sentinel>
bool vector<bool, t_allocator>::M_assign_with_size(t_forward_iterator first, t_sentinel last, difference_type num) {
  clear();
  if (num) {
    if (static_cast<size_type>(num) > capacity()) {
      M_vdeallocate();
      if (!M_vallocate(static_cast<size_type>(num))) {
        return false;
      }
    }
    M_construct_at_end(first, last, static_cast<size_type>(num));
  }
  return true;
}

template<class t_allocator>
template<class t_forward_iterator, vector_helper::enable_for_forward_iter_bool<t_forward_iterator>>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> vector<bool, t_allocator>::assign(
  t_forward_iterator first, t_forward_iterator last) {
  auto const new_size = ::portable_stl::distance(first, last);
  if (static_cast<size_type>(new_size) > max_size()) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
      ::portable_stl::portable_stl_error::length_error};
  }
  if (!M_assign_with_size(first, last, new_size)) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
      ::portable_stl::portable_stl_error::allocate_error};
  }
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

template<class t_allocator>
void vector<bool, t_allocator>::M_move_assign(vector &other, ::portable_stl::true_type) noexcept(
  ::portable_stl::is_nothrow_move_assignable<allocator_type>{}()) {
  M_vdeallocate();
  M_move_assign_alloc(other);
  m_begin       = other.m_begin;
  m_size        = other.m_size;
  M_cap()       = other.M_cap();
  other.m_begin = nullptr;
  other.M_cap() = other.m_size = 0;
}

template<class t_allocator> void vector<bool, t_allocator>::M_move_assign(vector &other, ::portable_stl::false_type) {
  if (M_alloc() != other.M_alloc()) {
    assign(other.begin(), other.end());
  } else {
    M_move_assign(other, true_type());
  }
}

template<class t_allocator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> vector<bool, t_allocator>::reserve(size_type num) {
  if (num > capacity()) {
    if (num > max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    vector tmp_vec(get_allocator());
    if (tmp_vec.M_vallocate(num)) {
      tmp_vec.M_construct_at_end(begin(), end(), size());
      swap(tmp_vec);
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
  }
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

template<class t_allocator> bool vector<bool, t_allocator>::shrink_to_fit() noexcept {
  // if (M_external_cap_to_internal(size()) > M_cap()) {
  //   auto tmp_vec = make_vector(*this, allocator_type(M_alloc()));
  //   if (tmp_vec) {
  //     tmp_vec.value().swap(*this);
  //   } else {
  //     return false;
  //   }
  // }
  return true;
}

template<class t_allocator>
::portable_stl::expected<typename vector<bool, t_allocator>::reference, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::at(size_type pos) noexcept {
  if (pos >= size()) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
      ::portable_stl::portable_stl_error::out_of_range};
  }
  return ::portable_stl::expected<reference, ::portable_stl::portable_stl_error>(
    ::portable_stl::in_place_t{}, operator[](pos));
}

template<class t_allocator>
::portable_stl::expected<typename vector<bool, t_allocator>::const_reference, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::at(size_type pos) const noexcept {
  if (pos >= size()) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
      ::portable_stl::portable_stl_error::out_of_range};
  }
  return ::portable_stl::expected<const_reference, ::portable_stl::portable_stl_error>(
    ::portable_stl::in_place_t{}, operator[](pos));
}

template<class t_allocator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> vector<bool, t_allocator>::push_back(
  value_type const &value) {
  if (capacity() == m_size) {
    size_type new_size{m_size + 1};
    if (new_size > max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    auto result = reserve(M_recommend(new_size));
    if (!result) {
      return result;
    }
  }
  ++m_size;
  back() = value;
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

template<class t_allocator>
::portable_stl::expected<typename vector<bool, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::insert(const_iterator position, value_type const &value) {
  iterator ret_iter;
  if (size() < capacity()) {
    const_iterator old_end{end()};
    ++m_size;
    ::portable_stl::copy_backward(position, old_end, end());
    ret_iter = M_const_iterator_cast(position);
  } else {
    size_type new_size{m_size + 1};
    if (new_size > max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    vector tmp_vec(get_allocator());
    auto   result = tmp_vec.reserve(M_recommend(new_size));
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
    tmp_vec.m_size = m_size + 1;
    ret_iter       = ::portable_stl::copy_bit(cbegin(), position, tmp_vec.begin());
    ::portable_stl::copy_backward(position, cend(), tmp_vec.end());
    swap(tmp_vec);
  }
  *ret_iter = value;
  return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>(ret_iter);
}

template<class t_allocator>
::portable_stl::expected<typename vector<bool, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::insert(const_iterator position, size_type num, value_type const &value) {
  iterator  ret_iter;
  size_type old_cap = capacity();
  if ((num <= old_cap) && (size() <= (old_cap - num))) {
    const_iterator old_end{end()};
    m_size += num;
    ::portable_stl::copy_backward(position, old_end, end());
    ret_iter = M_const_iterator_cast(position);
  } else {
    size_type new_size{m_size + num};
    if (new_size > max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    vector tmp_vec(get_allocator());
    auto   result = tmp_vec.reserve(M_recommend(new_size));
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
    tmp_vec.m_size = new_size;
    ret_iter       = ::portable_stl::copy_bit(cbegin(), position, tmp_vec.begin());
    ::portable_stl::copy_backward(position, cend(), tmp_vec.end());
    swap(tmp_vec);
  }
  ::portable_stl::fill_n_bit(ret_iter, num, value);
  return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>(ret_iter);
}

template<class t_allocator>
template<class t_input_iterator, class t_sentinel>
::portable_stl::expected<typename vector<bool, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::M_insert_with_sentinel(const_iterator position, t_input_iterator first, t_sentinel last) {
  difference_type offset = position - begin();
  iterator        pos    = M_const_iterator_cast(position);
  iterator        old_end{end()};

  auto guard = ::portable_stl::make_exception_guard([this, &old_end]() {
    erase(old_end, end());
  });

  for (; size() != capacity() && first != last; ++first) {
    ++m_size;
    back() = *first;
  }
  vector tmp_vec(get_allocator());
  if (first != last) {
    auto result = tmp_vec.M_assign_with_sentinel(::portable_stl::move(first), ::portable_stl::move(last));
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
    difference_type old_size{old_end - begin()};
    difference_type old_p{pos - begin()};
    auto            result2 = reserve(M_recommend(size() + tmp_vec.size()));
    if (!result2) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result2.error()};
    }
    pos     = begin() + old_p;
    old_end = begin() + old_size;
  }
  guard.commit();

  pos          = ::portable_stl::rotate(pos, old_end, end());
  auto result3 = insert(pos, tmp_vec.begin(), tmp_vec.end());
  if (!result3) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result3.error()};
  }
  return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>(begin() + offset);
}

template<class t_allocator>
template<class t_input_iterator, vector_helper::enable_for_input_iter_bool<t_input_iterator>>
::portable_stl::expected<typename vector<bool, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::insert(const_iterator position, t_input_iterator first, t_input_iterator last) {
  return M_insert_with_sentinel(position, first, last);
}

template<class t_allocator>
template<class t_forward_iterator, class t_sentinel>
::portable_stl::expected<typename vector<bool, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::M_insert_with_size(
    const_iterator position, t_forward_iterator first, t_sentinel last, difference_type num_signed) {
  auto const num = static_cast<size_type>(num_signed);
  iterator   ret_iter;
  size_type  old_cap = capacity();
  if ((num <= old_cap) && (size() <= (old_cap - num))) {
    const_iterator old_end{end()};
    m_size += num;
    ::portable_stl::copy_backward(position, old_end, end());
    ret_iter = M_const_iterator_cast(position);
  } else {
    size_type new_size{m_size + num};
    if (new_size > max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    vector tmp_vec(get_allocator());
    auto   result = tmp_vec.reserve(M_recommend(new_size));
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
    tmp_vec.m_size = new_size;
    ret_iter       = ::portable_stl::copy_bit(cbegin(), position, tmp_vec.begin());
    ::portable_stl::copy_backward(position, cend(), tmp_vec.end());
    swap(tmp_vec);
  }
  static_cast<void>(::portable_stl::copy_impl<::portable_stl::classic_alg_policy>(first, last, ret_iter));
  return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>(ret_iter);
}

template<class t_allocator>
template<class t_forward_iterator, vector_helper::enable_for_forward_iter_bool<t_forward_iterator>>
::portable_stl::expected<typename vector<bool, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  vector<bool, t_allocator>::insert(const_iterator position, t_forward_iterator first, t_forward_iterator last) {
  return M_insert_with_size(position, first, last, ::portable_stl::distance(first, last));
}

template<class t_allocator>
inline typename vector<bool, t_allocator>::iterator vector<bool, t_allocator>::erase(const_iterator position) {
  iterator ret_iter{M_const_iterator_cast(position)};
  ::portable_stl::copy_bit(position + 1, cend(), ret_iter);
  --m_size;
  return ret_iter;
}

template<class t_allocator>
typename vector<bool, t_allocator>::iterator vector<bool, t_allocator>::erase(const_iterator first,
                                                                              const_iterator last) {
  iterator ret_iter   = M_const_iterator_cast(first);
  auto     erase_size = static_cast<size_type>(last - first); // [first, last) !!
  ::portable_stl::copy_bit(last, cend(), ret_iter);
  m_size -= erase_size;
  return ret_iter;
}

template<class t_allocator> void vector<bool, t_allocator>::swap(vector &other) noexcept(swap_noexcept{}()) {
  ::portable_stl::swap(m_begin, other.m_begin);
  ::portable_stl::swap(m_size, other.m_size);
  ::portable_stl::swap(M_cap(), other.M_cap());
  ::portable_stl::memory_helper::swap_allocator_impl(
    M_alloc(), other.M_alloc(), typename t_allocator_traits::propagate_on_container_swap{});
}

template<class t_allocator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> vector<bool, t_allocator>::resize(size_type new_size,
                                                                                                     value_type value) {
  size_type old_size{m_size};
  if (old_size < new_size) {
    iterator        ret_iter;
    size_type const old_cap{capacity()};
    size_type       num{new_size - old_size};
    if ((num <= old_cap) && (old_size <= (old_cap - num))) {
      ret_iter = end();
      m_size += num;
    } else {
      size_type new_sz{m_size + num};
      if (new_sz > max_size()) {
        return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
          ::portable_stl::portable_stl_error::length_error};
      }
      vector tmp_vec(get_allocator());
      auto   result = tmp_vec.reserve(M_recommend(new_sz));
      if (!result) {
        return result; // err_bad_alloc/err_length
      }
      tmp_vec.m_size = new_sz;
      ret_iter       = ::portable_stl::copy_bit(cbegin(), cend(), tmp_vec.begin());
      swap(tmp_vec);
    }
    ::portable_stl::fill_n_bit(ret_iter, num, value);
  } else {
    m_size = new_size;
  }
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

template<class t_allocator> void vector<bool, t_allocator>::flip() noexcept {
  // do middle whole words
  size_type         num{m_size};
  t_storage_pointer pos_storage{m_begin};
  for (; num >= m_bits_per_word; ++pos_storage, num -= m_bits_per_word) {
    *pos_storage = ~*pos_storage;
  }
  // do last partial word
  if (num > 0U) {
    t_storage_type m = ~t_storage_type(0) >> (m_bits_per_word - num);
    t_storage_type b = *pos_storage & m;
    *pos_storage &= ~m;
    *pos_storage |= ~b & m;
  }
}

template<typename t_allocator>
inline bool operator==(vector<bool, t_allocator> const &left, vector<bool, t_allocator> const &right) {
  typename vector<bool, t_allocator>::size_type const left_size{left.size()};
  return (left_size == right.size()) && ::portable_stl::equal(left.begin(), left.end(), right.begin());
}

} // namespace portable_stl

#endif // PSTL_VECTOR_BOOL_H
