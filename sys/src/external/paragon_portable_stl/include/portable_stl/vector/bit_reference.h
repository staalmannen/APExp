// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="bit_reference.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BIT_REFERENCE_H
#define PSTL_BIT_REFERENCE_H

#include "../algorithm/ctz.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/type_traits/has_storage_type.h"
#include "bit_algo/bit_equal.h"
#include "bit_algo/bit_fill.h"
#include "bit_algo/bit_rotate.h"
#include "bit_algo/bit_swap_ranges.h"
#include "fwd_decl_bit.h"

namespace portable_stl {

template<class t_container_type> class bit_const_reference;

template<class t_container_type, class = typename ::portable_stl::has_storage_type<t_container_type>::type>
class bit_reference final {
  using t_storage_type    = typename t_container_type::t_storage_type;
  using t_storage_pointer = typename t_container_type::t_storage_pointer;

  t_storage_pointer m_seg;
  t_storage_type    m_mask;

  friend typename t_container_type::t_self;

  friend class bit_const_reference<t_container_type>;
  friend class bit_iterator<t_container_type, false>;

public:
  using t_container = typename t_container_type::t_self;

  bit_reference(bit_reference const &) = default;
  bit_reference(bit_reference &&)      = default;
  ~bit_reference() noexcept {
  }

  operator bool() const noexcept {
    return static_cast<bool>(*m_seg & m_mask);
  }

  bool operator~() const noexcept {
    return !static_cast<bool>(*this);
  }

  bit_reference &operator=(bool other) noexcept {
    if (other) {
      *m_seg |= m_mask;
    } else {
      *m_seg &= ~m_mask;
    }
    return *this;
  }

  bit_reference &operator=(bit_reference const &other) noexcept {
    return operator=(static_cast<bool>(other));
  }

  void flip() noexcept {
    *m_seg ^= m_mask;
  }

  bit_iterator<t_container_type, false> get_pointer() const noexcept {
    return bit_iterator<t_container_type, false>(m_seg, static_cast<unsigned>(::portable_stl::ctz(m_mask)));
  }

private:
  explicit bit_reference(t_storage_pointer segment, t_storage_type mask) noexcept : m_seg(segment), m_mask(mask) {
  }
};

template<class t_container_type> class bit_reference<t_container_type, ::portable_stl::false_type> final {};

template<class t_container_type>
inline void swap(bit_reference<t_container_type> rhv, bit_reference<t_container_type> lhv) noexcept {
  bool tmp = rhv;
  rhv      = lhv;
  lhv      = tmp;
}

template<class t_container_type, class _Dp>
inline void swap(bit_reference<t_container_type> rhv, bit_reference<_Dp> lhv) noexcept {
  bool tmp = rhv;
  rhv      = lhv;
  lhv      = tmp;
}

template<class t_container_type> inline void swap(bit_reference<t_container_type> rhv, bool &lhv) noexcept {
  bool tmp = rhv;
  rhv      = lhv;
  lhv      = tmp;
}

template<class t_container_type> inline void swap(bool &rhv, bit_reference<t_container_type> lhv) noexcept {
  bool tmp = rhv;
  rhv      = lhv;
  lhv      = tmp;
}

template<class t_container_type> class bit_const_reference {
  using t_storage_type    = typename t_container_type::t_storage_type;
  using t_storage_pointer = typename t_container_type::t_const_storage_pointer;

  t_storage_pointer m_seg;
  t_storage_type    m_mask;

  friend typename t_container_type::t_self;
  friend class bit_iterator<t_container_type, true>;

public:
  using t_container = typename t_container_type::t_self;

  bit_const_reference(bit_const_reference const &) = default;

  bit_const_reference(bit_reference<t_container_type> const &other) noexcept
      : m_seg(other.m_seg), m_mask(other.m_mask) {
  }

  operator bool() const noexcept {
    return static_cast<bool>(*m_seg & m_mask);
  }

  bit_iterator<t_container_type, true> get_pointer() const noexcept {
    return bit_iterator<t_container_type, true>(m_seg, static_cast<unsigned>(::portable_stl::ctz(m_mask)));
  }

private:
  explicit bit_const_reference(t_storage_pointer segment, t_storage_type mask) noexcept : m_seg(segment), m_mask(mask) {
  }

  bit_const_reference &operator=(bit_const_reference const &) = delete;
};

template<class t_container_type, bool t_is_const> class bit_iterator {
public:
  using difference_type = typename t_container_type::difference_type;
  using value_type      = bool;
  using pointer         = bit_iterator;
  using reference
    = ::portable_stl::conditional_t<t_is_const, bit_const_reference<t_container_type>, bit_reference<t_container_type>>;
  using iterator_category = ::portable_stl::random_access_iterator_tag;

private:
  using t_storage_type    = typename t_container_type::t_storage_type;
  using t_storage_pointer = ::portable_stl::conditional_t<t_is_const,
                                                          typename t_container_type::t_const_storage_pointer,
                                                          typename t_container_type::t_storage_pointer>;

  static unsigned int const m_bits_per_word = t_container_type::m_bits_per_word;

  t_storage_pointer m_seg;
  unsigned int      m_ctz;

public:
  bit_iterator() noexcept : m_seg(nullptr), m_ctz(0U) {
  }

  // When t_is_const=false, this is the copy constructor.
  // It is non-trivial. Making it trivial would break ABI.
  // When t_is_const=true, this is a converting constructor;
  // the copy and move constructors are implicitly generated
  // and trivial.
  bit_iterator(bit_iterator<t_container_type, false> const &other) noexcept : m_seg(other.m_seg), m_ctz(other.m_ctz) {
  }

  // When t_is_const=false, we have a user-provided copy constructor,
  // so we must also provide a copy assignment operator because
  // the implicit generation of a defaulted one is deprecated.
  // When t_is_const=true, the assignment operators are
  // implicitly generated and trivial.
  bit_iterator &operator=(::portable_stl::conditional_t<t_is_const, struct __private_nat, bit_iterator> const &other) {
    m_seg = other.m_seg;
    m_ctz = other.m_ctz;
    return *this;
  }

  reference operator*() const noexcept {
    return ::portable_stl::conditional_t<t_is_const,
                                         bit_const_reference<t_container_type>,
                                         bit_reference<t_container_type>>(m_seg, t_storage_type(1) << m_ctz);
  }

  bit_iterator &operator++() {
    if (m_ctz != m_bits_per_word - 1U) {
      ++m_ctz;
    } else {
      m_ctz = 0U;
      ++m_seg;
    }
    return *this;
  }

  bit_iterator operator++(int) {
    bit_iterator tmp{*this};
    ++(*this);
    return tmp;
  }

  bit_iterator &operator--() {
    if (m_ctz != 0) {
      --m_ctz;
    } else {
      m_ctz = m_bits_per_word - 1U;
      --m_seg;
    }
    return *this;
  }

  bit_iterator operator--(int) {
    bit_iterator tmp{*this};
    --(*this);
    return tmp;
  }

  bit_iterator &operator+=(difference_type num) {
    if (num >= 0) {
      m_seg += (num + static_cast<difference_type>(m_ctz)) / static_cast<difference_type>(m_bits_per_word);
    } else {
      m_seg += (num - static_cast<difference_type>(m_bits_per_word) + static_cast<difference_type>(m_ctz) + 1)
             / static_cast<difference_type>(m_bits_per_word);
    }
    num &= static_cast<difference_type>(m_bits_per_word - 1U);
    m_ctz = static_cast<unsigned int>(num + static_cast<difference_type>(m_ctz)) % m_bits_per_word;
    return *this;
  }

  bit_iterator &operator-=(difference_type num) {
    return *this += -num;
  }

  bit_iterator operator+(difference_type num) const {
    bit_iterator tmp{*this};
    tmp += num;
    return tmp;
  }

  bit_iterator operator-(difference_type num) const {
    bit_iterator tmp{*this};
    tmp -= num;
    return tmp;
  }

  friend bit_iterator operator+(difference_type num, bit_iterator const &iter) {
    return iter + num;
  }

  friend difference_type operator-(bit_iterator const &lhv, bit_iterator const &rhv) {
    return (::portable_stl::distance(rhv.m_seg , lhv.m_seg) * static_cast<difference_type>(m_bits_per_word)
            + static_cast<difference_type>(lhv.m_ctz) - static_cast<difference_type>(rhv.m_ctz));
  }

  reference operator[](difference_type num) const {
    return *(*this + num);
  }

  friend bool operator==(bit_iterator const &lhv, bit_iterator const &rhv) {
    return (lhv.m_seg == rhv.m_seg) && (lhv.m_ctz == rhv.m_ctz);
  }

  friend bool operator!=(bit_iterator const &lhv, bit_iterator const &rhv) {
    return !(lhv == rhv);
  }

  friend bool operator<(bit_iterator const &lhv, bit_iterator const &rhv) {
    return (lhv.m_seg < rhv.m_seg) || ((lhv.m_seg == rhv.m_seg) && (lhv.m_ctz < rhv.m_ctz));
  }

  friend bool operator>(bit_iterator const &lhv, bit_iterator const &rhv) {
    return rhv < lhv;
  }

  friend bool operator<=(bit_iterator const &lhv, bit_iterator const &rhv) {
    return !(rhv < lhv);
  }

  friend bool operator>=(bit_iterator const &lhv, bit_iterator const &rhv) {
    return !(lhv < rhv);
  }

private:
  explicit bit_iterator(t_storage_pointer segment, unsigned ctz) noexcept : m_seg(segment), m_ctz(ctz) {
  }

  friend typename t_container_type::t_self;

  friend class bit_reference<t_container_type>;
  friend class bit_const_reference<t_container_type>;
  friend class bit_iterator<t_container_type, true>;
  template<class _Dp> friend struct bit_algo::bit_array;
  template<bool _FillValue, class _Dp>
  friend void bit_algo::fill_n(bit_iterator<_Dp, false> first, typename _Dp::size_type num);

  template<class _Dp, bool _IC>
  friend bit_iterator<_Dp, false> bit_algo::copy_aligned(
    bit_iterator<_Dp, _IC> first, bit_iterator<_Dp, _IC> last, bit_iterator<_Dp, false> result);

  template<class _Dp, bool _IC>
  friend bit_iterator<_Dp, false> bit_algo::copy_unaligned(
    bit_iterator<_Dp, _IC> first, bit_iterator<_Dp, _IC> last, bit_iterator<_Dp, false> result);

  template<class _Dp, bool _IC>
  friend bit_iterator<_Dp, false> copy_bit(
    bit_iterator<_Dp, _IC> first, bit_iterator<_Dp, _IC> last, bit_iterator<_Dp, false> result);

  template<class _Dp, bool _IC>
  friend bit_iterator<_Dp, false> bit_algo::copy_backward_aligned(
    bit_iterator<_Dp, _IC> first, bit_iterator<_Dp, _IC> last, bit_iterator<_Dp, false> result);

  template<class _Dp, bool _IC>
  friend bit_iterator<_Dp, false> bit_algo::copy_backward_unaligned(
    bit_iterator<_Dp, _IC> first, bit_iterator<_Dp, _IC> last, bit_iterator<_Dp, false> result);

  template<class _Dp, bool _IC>
  friend bit_iterator<_Dp, false> copy_backward(
    bit_iterator<_Dp, _IC> first, bit_iterator<_Dp, _IC> last, bit_iterator<_Dp, false> result);

  template<class _Cl, class _Cr>
  friend bit_iterator<_Cr, false> bit_algo::swap_ranges_aligned(
    bit_iterator<_Cl, false>, bit_iterator<_Cl, false>, bit_iterator<_Cr, false>);

  template<class _Cl, class _Cr>
  friend bit_iterator<_Cr, false> bit_algo::swap_ranges_unaligned(
    bit_iterator<_Cl, false>, bit_iterator<_Cl, false>, bit_iterator<_Cr, false>);

  template<class _Cl, class _Cr>
  friend bit_iterator<_Cr, false> swap_ranges(
    bit_iterator<_Cl, false>, bit_iterator<_Cl, false>, bit_iterator<_Cr, false>);

  template<class _Dp>
  friend bit_iterator<_Dp, false> rotate(bit_iterator<_Dp, false>, bit_iterator<_Dp, false>, bit_iterator<_Dp, false>);

  template<class _Dp, bool _IC1, bool _IC2>
  friend bool bit_algo::equal_aligned(bit_iterator<_Dp, _IC1>, bit_iterator<_Dp, _IC1>, bit_iterator<_Dp, _IC2>);

  template<class _Dp, bool _IC1, bool _IC2>
  friend bool bit_algo::equal_unaligned(bit_iterator<_Dp, _IC1>, bit_iterator<_Dp, _IC1>, bit_iterator<_Dp, _IC2>);

  template<class _Dp, bool _IC1, bool _IC2>
  friend bool equal(bit_iterator<_Dp, _IC1>, bit_iterator<_Dp, _IC1>, bit_iterator<_Dp, _IC2>);

  template<bool _ToFind, class _Dp, bool _IC>
  friend bit_iterator<_Dp, _IC> __find_bool(bit_iterator<_Dp, _IC>, typename _Dp::size_type);

  template<bool _ToCount, class _Dp, bool _IC>
  friend typename bit_iterator<_Dp, _IC>::difference_type __count_bool(bit_iterator<_Dp, _IC>, typename _Dp::size_type);
};

} // namespace portable_stl

#endif // PSTL_BIT_REFERENCE_H
