// ***************************************************************************
// * APExp addition to portable_stl -- `deque'.
// *
// * Project="APExp C++ library" File="containers/deque.h"
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
//
// ---- WHY THIS EXISTS -----------------------------------------------------
//
// `stack' and `queue' default to `deque' and portable_stl has none, so the
// two adaptors could not be written without it.  Reaching re2c also wants
// it directly.
//
// ---- IT FOLLOWS THE LIBRARY'S CONVENTION AND NOT THE STANDARD'S ----------
//
// Where the two conflict this file follows portable_stl, and the shape was
// read out of `vector/vector.h' rather than chosen: a default constructor
// that CANNOT fail, **static `make_deque' factories returning
// `expected<deque, std_error>'**, and mutators that return
// `expected<void, std_error>' where the standard returns `void'.
//
// *A second convention inside one library is worse than one deviation.*
// Generic code written against `vector::push_back' -- which already
// answers `expected' -- would break on a `deque::push_back' that answered
// `void', and a `void' one could only report an allocation failure by
// discarding it, which is the silent-failure shape this library's whole
// convention exists to prevent.
//
// ---- THE STORAGE, AND THE ONE SIMPLIFICATION -----------------------------
//
// A map of fixed-size blocks, as every deque is.  **The iterator holds
// (container, index) rather than the classic four pointers**, which costs
// a divide per dereference and saves a great deal of code that would
// otherwise be the delicate part. *The invalidation rules are the same
// either way*: `push_front' shifts every index, so an iterator held across
// one names a different element -- which is exactly what the standard says
// about a four-pointer iterator too, by a different mechanism.
//
// **Raw storage is `malloc' with placement `new`, not the allocator.**
// The library is exception-free, `operator new' is the one thing left that
// can throw, and this file must report failure in a return value anyway --
// so going through an allocator that cannot say no would add a layer and
// subtract nothing.  `io/sstream.h' makes the same trade for the same
// reason.

#ifndef APEXP_STD_CONTAINERS_DEQUE_H
#define APEXP_STD_CONTAINERS_DEQUE_H

#include "../common/size_t.h"
#include "../common/ptrdiff_t.h"
#include "../error/portable_stl_error.h"
#include "../utility/expected/expected.h"
#include "../utility/expected/unexpected.h"
#include "../metaprogramming/other_transformations/conditional.h"
#include "../metaprogramming/other_transformations/enable_if.h"
#include "../iterator/random_access_iterator_tag.h"
#include "../iterator/reverse_iterator.h"
#include "../utility/general/move.h"
#include "../utility/general/functional/reference_wrapper.h"
#include "../cstdlib.stdh"
#include "../new.stdh"

namespace std {

namespace deque_detail {
  // 512 bytes a block, libstdc++'s number, and at least one element so a
  // very large value_type still works.
  template<class t_type> struct block_size final {
    static constexpr ::std::size_t value
        = (sizeof(t_type) < 512U) ? (512U / sizeof(t_type)) : 1U;
  };
} // namespace deque_detail

template<class t_type> class deque;

// ---- the iterator -------------------------------------------------------

template<class t_type, bool t_const> class deque_iterator final {
  using deque_ptr = typename ::std::conditional<t_const, deque<t_type> const *,
                                                deque<t_type> *>::type;

public:
  using iterator_category = ::std::random_access_iterator_tag;
  using value_type        = t_type;
  using difference_type   = ::std::ptrdiff_t;
  using pointer = typename ::std::conditional<t_const, t_type const *, t_type *>::type;
  using reference = typename ::std::conditional<t_const, t_type const &, t_type &>::type;

  deque_iterator() noexcept : m_dq{nullptr}, m_idx{0} {
  }
  deque_iterator(deque_ptr in_dq, ::std::size_t in_idx) noexcept
      : m_dq{in_dq}, m_idx{in_idx} {
  }
  // non-const to const, and never the other way
  template<bool t_other, class = typename ::std::enable_if<t_const && !t_other>::type>
  deque_iterator(deque_iterator<t_type, t_other> const &other) noexcept
      : m_dq{other.container()}, m_idx{other.index()} {
  }

  deque_ptr     container() const noexcept { return m_dq; }
  ::std::size_t index() const noexcept { return m_idx; }

  reference operator*() const { return (*m_dq)[m_idx]; }
  pointer   operator->() const { return &(*m_dq)[m_idx]; }
  reference operator[](difference_type n) const {
    return (*m_dq)[m_idx + static_cast<::std::size_t>(n)];
  }

  deque_iterator &operator++() noexcept { ++m_idx; return *this; }
  deque_iterator  operator++(int) noexcept { deque_iterator t{*this}; ++m_idx; return t; }
  deque_iterator &operator--() noexcept { --m_idx; return *this; }
  deque_iterator  operator--(int) noexcept { deque_iterator t{*this}; --m_idx; return t; }

  deque_iterator &operator+=(difference_type n) noexcept {
    m_idx = static_cast<::std::size_t>(static_cast<difference_type>(m_idx) + n);
    return *this;
  }
  deque_iterator &operator-=(difference_type n) noexcept { return *this += -n; }
  deque_iterator  operator+(difference_type n) const noexcept {
    deque_iterator t{*this};
    t += n;
    return t;
  }
  deque_iterator operator-(difference_type n) const noexcept {
    deque_iterator t{*this};
    t -= n;
    return t;
  }
  difference_type operator-(deque_iterator const &o) const noexcept {
    return static_cast<difference_type>(m_idx) - static_cast<difference_type>(o.m_idx);
  }

  bool operator==(deque_iterator const &o) const noexcept { return m_idx == o.m_idx; }
  bool operator!=(deque_iterator const &o) const noexcept { return m_idx != o.m_idx; }
  bool operator<(deque_iterator const &o) const noexcept { return m_idx < o.m_idx; }
  bool operator>(deque_iterator const &o) const noexcept { return m_idx > o.m_idx; }
  bool operator<=(deque_iterator const &o) const noexcept { return m_idx <= o.m_idx; }
  bool operator>=(deque_iterator const &o) const noexcept { return m_idx >= o.m_idx; }

private:
  deque_ptr     m_dq;
  ::std::size_t m_idx;
};

template<class t_type, bool t_const>
inline deque_iterator<t_type, t_const> operator+(::std::ptrdiff_t n,
                                                 deque_iterator<t_type, t_const> const &i) {
  return i + n;
}

// ---- the container ------------------------------------------------------

template<class t_type> class deque final {
public:
  using value_type      = t_type;
  using size_type       = ::std::size_t;
  using difference_type = ::std::ptrdiff_t;
  using reference       = t_type &;
  using const_reference = t_type const &;
  using pointer         = t_type *;
  using const_pointer   = t_type const *;
  using iterator        = deque_iterator<t_type, false>;
  using const_iterator  = deque_iterator<t_type, true>;
  using reverse_iterator       = ::std::reverse_iterator<iterator>;
  using const_reverse_iterator = ::std::reverse_iterator<const_iterator>;

  static constexpr size_type block_size = deque_detail::block_size<t_type>::value;

  deque() noexcept : m_map{nullptr}, m_map_cap{0U}, m_start{0U}, m_size{0U} {
  }

  deque(deque &&other) noexcept
      : m_map{other.m_map}, m_map_cap{other.m_map_cap}, m_start{other.m_start},
        m_size{other.m_size} {
    other.m_map     = nullptr;
    other.m_map_cap = 0U;
    other.m_start   = 0U;
    other.m_size    = 0U;
  }

  deque &operator=(deque &&other) noexcept {
    if (this != &other) {
      this->tidy();
      m_map           = other.m_map;
      m_map_cap       = other.m_map_cap;
      m_start         = other.m_start;
      m_size          = other.m_size;
      other.m_map     = nullptr;
      other.m_map_cap = 0U;
      other.m_start   = 0U;
      other.m_size    = 0U;
    }
    return *this;
  }

  // ***NO COPY CONSTRUCTOR, DELIBERATELY.***  A copy allocates and this
  // library has no way for a constructor to say it could not -- so the
  // copy is `clone()', which returns `expected' like every other
  // fallible operation here.  *A copy constructor that silently yields
  // an empty container is the exact failure the convention exists to
  // prevent*, and one that aborts would make the library non
  // exception-free by another route.
  deque(deque const &)            = delete;
  deque &operator=(deque const &) = delete;

  ~deque() {
    this->tidy();
  }

  ::std::expected<deque, ::std::std_error> clone() const {
    deque out;
    for (size_type i{0U}; i < m_size; ++i) {
      auto r = out.push_back((*this)[i]);
      if (!r) {
        return ::std::unexpected<::std::std_error>{::std::move(r.error())};
      }
    }
    return ::std::expected<deque, ::std::std_error>{::std::move(out)};
  }

  static ::std::expected<deque, ::std::std_error> make_deque(size_type n,
                                                             t_type const &v) {
    deque out;
    for (size_type i{0U}; i < n; ++i) {
      auto r = out.push_back(v);
      if (!r) {
        return ::std::unexpected<::std::std_error>{::std::move(r.error())};
      }
    }
    return ::std::expected<deque, ::std::std_error>{::std::move(out)};
  }

  // ***NAMED, NOT OVERLOADED, AND THAT IS DELIBERATE.***
  // `make_deque(5, 7)' with both arguments `int' is ambiguous against
  // an iterator pair, and the standard only escapes it for
  // `deque(n, v)' by a special rule written for exactly this wart.
  // A library that can simply give the two things two names should.
  // *The first build picked the iterator overload and tried to
  // dereference an `int'.*
  template<class t_iter>
  static ::std::expected<deque, ::std::std_error> make_deque_range(t_iter first,
                                                                   t_iter last) {
    deque out;
    for (; first != last; ++first) {
      auto r = out.push_back(*first);
      if (!r) {
        return ::std::unexpected<::std::std_error>{::std::move(r.error())};
      }
    }
    return ::std::expected<deque, ::std::std_error>{::std::move(out)};
  }

  // ---- capacity -------------------------------------------------------

  bool      empty() const noexcept { return 0U == m_size; }
  size_type size() const noexcept { return m_size; }
  size_type max_size() const noexcept { return static_cast<size_type>(-1) / sizeof(t_type); }

  // ---- element access -------------------------------------------------

  reference       operator[](size_type i) { return this->raw(i); }
  const_reference operator[](size_type i) const { return this->raw(i); }

  ::std::expected<::std::reference_wrapper<t_type>, ::std::std_error> at(size_type i) {
    if (i >= m_size) {
      return ::std::unexpected<::std::std_error>{::std::std_error::out_of_range};
    }
    return ::std::expected<::std::reference_wrapper<t_type>, ::std::std_error>{
        ::std::reference_wrapper<t_type>{this->raw(i)}};
  }

  reference       front() { return this->raw(0U); }
  const_reference front() const { return this->raw(0U); }
  reference       back() { return this->raw(m_size - 1U); }
  const_reference back() const { return this->raw(m_size - 1U); }

  // ---- iterators ------------------------------------------------------

  iterator       begin() noexcept { return iterator{this, 0U}; }
  iterator       end() noexcept { return iterator{this, m_size}; }
  const_iterator begin() const noexcept { return const_iterator{this, 0U}; }
  const_iterator end() const noexcept { return const_iterator{this, m_size}; }
  const_iterator cbegin() const noexcept { return const_iterator{this, 0U}; }
  const_iterator cend() const noexcept { return const_iterator{this, m_size}; }
  reverse_iterator       rbegin() noexcept { return reverse_iterator{this->end()}; }
  reverse_iterator       rend() noexcept { return reverse_iterator{this->begin()}; }
  const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator{this->end()}; }
  const_reverse_iterator rend() const noexcept { return const_reverse_iterator{this->begin()}; }

  // ---- modifiers ------------------------------------------------------

  ::std::expected<void, ::std::std_error> push_back(t_type const &v) {
    if (!this->reserve_back()) {
      return ::std::unexpected<::std::std_error>{::std::std_error::allocate_error};
    }
    ::new (static_cast<void *>(&this->slot(m_start + m_size))) t_type(v);
    ++m_size;
    return ::std::expected<void, ::std::std_error>{};
  }

  ::std::expected<void, ::std::std_error> push_back(t_type &&v) {
    if (!this->reserve_back()) {
      return ::std::unexpected<::std::std_error>{::std::std_error::allocate_error};
    }
    ::new (static_cast<void *>(&this->slot(m_start + m_size))) t_type(::std::move(v));
    ++m_size;
    return ::std::expected<void, ::std::std_error>{};
  }

  ::std::expected<void, ::std::std_error> push_front(t_type const &v) {
    if (!this->reserve_front()) {
      return ::std::unexpected<::std::std_error>{::std::std_error::allocate_error};
    }
    --m_start;
    ::new (static_cast<void *>(&this->slot(m_start))) t_type(v);
    ++m_size;
    return ::std::expected<void, ::std::std_error>{};
  }

  ::std::expected<void, ::std::std_error> push_front(t_type &&v) {
    if (!this->reserve_front()) {
      return ::std::unexpected<::std::std_error>{::std::std_error::allocate_error};
    }
    --m_start;
    ::new (static_cast<void *>(&this->slot(m_start))) t_type(::std::move(v));
    ++m_size;
    return ::std::expected<void, ::std::std_error>{};
  }

  void pop_back() {
    if (0U != m_size) {
      --m_size;
      this->slot(m_start + m_size).~t_type();
    }
  }

  void pop_front() {
    if (0U != m_size) {
      this->slot(m_start).~t_type();
      ++m_start;
      --m_size;
    }
  }

  void clear() noexcept {
    for (size_type i{0U}; i < m_size; ++i) {
      this->slot(m_start + i).~t_type();
    }
    m_size = 0U;
    // Keep the blocks: `clear' then refill is the common pattern and
    // freeing here would make it quadratic in allocations.
  }

  void swap(deque &other) noexcept {
    t_type **const  m{m_map};
    size_type const c{m_map_cap};
    size_type const s{m_start};
    size_type const n{m_size};
    m_map           = other.m_map;
    m_map_cap       = other.m_map_cap;
    m_start         = other.m_start;
    m_size          = other.m_size;
    other.m_map     = m;
    other.m_map_cap = c;
    other.m_start   = s;
    other.m_size    = n;
  }

  // `erase' and `insert' move elements by ASSIGNMENT, which is what the
  // standard's complexity guarantee allows and what keeps this file
  // short.  Both take and return an index-based iterator.
  iterator erase(const_iterator pos) {
    size_type const at{pos.index()};
    if (at >= m_size) {
      return this->end();
    }
    for (size_type i{at}; (i + 1U) < m_size; ++i) {
      this->raw(i) = ::std::move(this->raw(i + 1U));
    }
    this->pop_back();
    return iterator{this, at};
  }

  ::std::expected<iterator, ::std::std_error> insert(const_iterator pos,
                                                     t_type const  &v) {
    size_type const at{pos.index()};
    if (at > m_size) {
      return ::std::unexpected<::std::std_error>{::std::std_error::out_of_range};
    }
    // Grow by one at the back, then rotate the tail up.  The value is
    // COPIED FIRST, because `v' may name an element of this deque and
    // the rotation would otherwise overwrite it before it is read.
    t_type tmp{v};
    auto   r = this->push_back(tmp);
    if (!r) {
      return ::std::unexpected<::std::std_error>{::std::move(r.error())};
    }
    for (size_type i{m_size - 1U}; i > at; --i) {
      this->raw(i) = ::std::move(this->raw(i - 1U));
    }
    this->raw(at) = ::std::move(tmp);
    return ::std::expected<iterator, ::std::std_error>{iterator{this, at}};
  }

private:
  t_type &slot(size_type global) const {
    return m_map[global / block_size][global % block_size];
  }
  t_type &raw(size_type i) const {
    return this->slot(m_start + i);
  }

  void tidy() noexcept {
    this->clear();
    if (nullptr != m_map) {
      for (size_type b{0U}; b < m_map_cap; ++b) {
        ::std::free(m_map[b]);
      }
      ::std::free(m_map);
      m_map = nullptr;
    }
    m_map_cap = 0U;
    m_start   = 0U;
  }

  bool ensure_block(size_type b) {
    if (nullptr == m_map[b]) {
      void *const p{::std::malloc(block_size * sizeof(t_type))};
      if (nullptr == p) {
        return false;
      }
      m_map[b] = static_cast<t_type *>(p);
    }
    return true;
  }

  bool grow_map(size_type front_blocks, size_type back_blocks) {
    size_type const newcap{m_map_cap + front_blocks + back_blocks
                           + ((0U == m_map_cap) ? 8U : 0U)};
    void *const     p{::std::malloc(newcap * sizeof(t_type *))};
    if (nullptr == p) {
      return false;
    }
    t_type **const nm{static_cast<t_type **>(p)};
    for (size_type i{0U}; i < newcap; ++i) {
      nm[i] = nullptr;
    }
    for (size_type i{0U}; i < m_map_cap; ++i) {
      nm[front_blocks + i] = m_map[i];
    }
    ::std::free(m_map);
    m_map     = nm;
    m_map_cap = newcap;
    m_start += front_blocks * block_size;
    return true;
  }

  bool reserve_back() {
    size_type const g{m_start + m_size};
    size_type const b{g / block_size};
    if (b >= m_map_cap) {
      if (!this->grow_map(0U, (0U == m_map_cap) ? 0U : (m_map_cap + 1U))) {
        return false;
      }
    }
    return this->ensure_block((m_start + m_size) / block_size);
  }

  bool reserve_front() {
    if (0U == m_start) {
      // Room must be made BELOW block 0, and `grow_map' is what moves
      // `m_start' with the pointers.
      if (!this->grow_map((0U == m_map_cap) ? 4U : (m_map_cap + 1U), 0U)) {
        return false;
      }
    }
    return this->ensure_block((m_start - 1U) / block_size);
  }

  t_type  **m_map;
  size_type m_map_cap;
  size_type m_start;
  size_type m_size;
};

template<class t_type>
inline bool operator==(deque<t_type> const &a, deque<t_type> const &b) {
  if (a.size() != b.size()) {
    return false;
  }
  for (::std::size_t i{0U}; i < a.size(); ++i) {
    if (!(a[i] == b[i])) {
      return false;
    }
  }
  return true;
}

template<class t_type>
inline bool operator!=(deque<t_type> const &a, deque<t_type> const &b) {
  return !(a == b);
}

template<class t_type> inline void swap(deque<t_type> &a, deque<t_type> &b) noexcept {
  a.swap(b);
}

} // namespace std

#endif // APEXP_STD_CONTAINERS_DEQUE_H
