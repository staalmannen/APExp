// ***************************************************************************
// * APExp addition to portable_stl -- `unordered_set'.
// *
// * Project="APExp C++ library" File="containers/unordered_set.h"
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
//
// ---- THE TWO DECISIONS THAT MATTER --------------------------------------
//
// **The bucket count is a PRIME and the index is a modulus**, not a power
// of two with a mask.  That is the other half of `functional/hash.h`
// hashing integers to THEMSELVES: identity plus a power-of-two mask puts
// every consecutive key in a different bucket only until the keys share
// low bits, and then they all collide.  *Neither choice is safe alone and
// together they are the ordinary one.*  A modulus costs a divide per
// lookup, which is the price of not needing a bit-mixing step.
//
// **It returns `expected` and `tuple`, which is the LIBRARY's shape, read
// out of `set/set.h` rather than chosen**: that file's own `insert` is
// `::std::expected<::std::tuple<iterator, bool>, ::std::std_error>`,
// because this library is exception-free and **has no `std::pair` at
// all**.  So this file matches `set` exactly rather than matching the
// standard, for the reason `containers/deque.h` gives in full.
//
// ---- WHAT IS DELIBERATELY ABSENT ----------------------------------------
//
// No `unordered_multiset`, no `unordered_map`, no `unordered_multimap`.
// Each is a real container and shipping an empty one is what EDG's
// `<stdexcept>` already did to this port.  No `local_iterator`,
// `bucket(k)` or `max_load_factor(z)` setter: `load_factor()`,
// `bucket_count()` and `rehash()` are there because they are how a caller
// measures the thing, and the rest is API nobody here has asked for.
//
// Storage is `malloc` with placement `new`, for the reason
// `containers/deque.h` gives: the library is exception-free, `operator
// new' is the one thing left that can throw, and every fallible
// operation here reports in its return value anyway.

#ifndef APEXP_STD_CONTAINERS_UNORDERED_SET_H
#define APEXP_STD_CONTAINERS_UNORDERED_SET_H

#include "../common/size_t.h"
#include "../common/ptrdiff_t.h"
#include "../error/portable_stl_error.h"
#include "../utility/expected/expected.h"
#include "../utility/expected/unexpected.h"
#include "../utility/general/move.h"
#include "../functional/hash.h"
#include "../functional/equal_to.h"
#include "../iterator/forward_iterator_tag.h"
#include "../tuple.stdh"
#include "../cstdlib.stdh"
#include "../new.stdh"

namespace std {

namespace uset_detail {
  // Primes roughly doubling.  A TABLE and not a computed next-prime,
  // because the search would be the only loop here whose cost is not
  // obvious, and twenty-eight numbers cover 3 to four thousand million.
  inline ::std::size_t next_prime(::std::size_t in_n) noexcept {
    static ::std::size_t const primes[] = {
        3U,        7U,        17U,       37U,        79U,        163U,
        331U,      673U,      1361U,     2729U,      5471U,      10949U,
        21911U,    43853U,    87719U,    175447U,    350899U,    701819U,
        1403641U,  2807303U,  5614657U,  11229331U,  22458671U,  44917381U,
        89834777U, 179669557U, 359339171U, 718678369U};
    constexpr ::std::size_t n{sizeof(primes) / sizeof(primes[0])};
    for (::std::size_t i{0U}; i < n; ++i) {
      if (primes[i] >= in_n) {
        return primes[i];
      }
    }
    return primes[n - 1U];
  }
} // namespace uset_detail

template<class t_key, class t_hash = ::std::hash<t_key>,
         class t_equal = ::std::equal_to<t_key>>
class unordered_set final {
  struct node {
    node  *m_next;
    ::std::size_t m_hash;
    t_key  m_value;
  };

public:
  using key_type        = t_key;
  using value_type      = t_key;
  using size_type       = ::std::size_t;
  using difference_type = ::std::ptrdiff_t;
  using hasher          = t_hash;
  using key_equal       = t_equal;
  using reference       = t_key &;
  using const_reference = t_key const &;

  // A forward iterator that walks the bucket array and the chain inside
  // each bucket.  `const` only: changing an element in place would
  // change its hash and strand it in the wrong bucket, which is why the
  // standard makes a set's iterators const too.
  class const_iterator final {
  public:
    using iterator_category = ::std::forward_iterator_tag;
    using value_type        = t_key;
    using difference_type   = ::std::ptrdiff_t;
    using pointer           = t_key const *;
    using reference         = t_key const &;

    const_iterator() noexcept : m_buckets{nullptr}, m_nbuckets{0U}, m_b{0U},
                                m_node{nullptr} {
    }
    const_iterator(node *const *in_buckets, ::std::size_t in_n, ::std::size_t in_b,
                   node *in_node) noexcept
        : m_buckets{in_buckets}, m_nbuckets{in_n}, m_b{in_b}, m_node{in_node} {
    }

    reference operator*() const { return m_node->m_value; }
    pointer   operator->() const { return &m_node->m_value; }

    const_iterator &operator++() {
      if (nullptr != m_node) {
        m_node = m_node->m_next;
      }
      while ((nullptr == m_node) && ((m_b + 1U) < m_nbuckets)) {
        ++m_b;
        m_node = m_buckets[m_b];
      }
      if (nullptr == m_node) {
        m_b = m_nbuckets;
      }
      return *this;
    }
    const_iterator operator++(int) {
      const_iterator t{*this};
      ++(*this);
      return t;
    }
    bool operator==(const_iterator const &o) const noexcept { return m_node == o.m_node; }
    bool operator!=(const_iterator const &o) const noexcept { return m_node != o.m_node; }

  private:
    node *const  *m_buckets;
    ::std::size_t m_nbuckets;
    ::std::size_t m_b;
    node         *m_node;
  };

  using iterator = const_iterator;

  unordered_set() noexcept
      : m_buckets{nullptr}, m_nbuckets{0U}, m_size{0U}, m_hash{}, m_eq{} {
  }

  unordered_set(unordered_set &&other) noexcept
      : m_buckets{other.m_buckets}, m_nbuckets{other.m_nbuckets},
        m_size{other.m_size}, m_hash{other.m_hash}, m_eq{other.m_eq} {
    other.m_buckets  = nullptr;
    other.m_nbuckets = 0U;
    other.m_size     = 0U;
  }
  unordered_set &operator=(unordered_set &&other) noexcept {
    if (this != &other) {
      this->tidy();
      m_buckets        = other.m_buckets;
      m_nbuckets       = other.m_nbuckets;
      m_size           = other.m_size;
      other.m_buckets  = nullptr;
      other.m_nbuckets = 0U;
      other.m_size     = 0U;
    }
    return *this;
  }

  // No copy constructor, for `deque`'s reason: a copy allocates and a
  // constructor here cannot say it failed.  `clone()' can.
  unordered_set(unordered_set const &)            = delete;
  unordered_set &operator=(unordered_set const &) = delete;

  ~unordered_set() {
    this->tidy();
  }

  ::std::expected<unordered_set, ::std::std_error> clone() const {
    unordered_set out;
    for (const_iterator it{this->begin()}; it != this->end(); ++it) {
      auto r = out.insert(*it);
      if (!r) {
        return ::std::unexpected<::std::std_error>{::std::move(r.error())};
      }
    }
    return ::std::expected<unordered_set, ::std::std_error>{::std::move(out)};
  }

  template<class t_iter>
  static ::std::expected<unordered_set, ::std::std_error> make_unordered_set_range(
      t_iter first, t_iter last) {
    unordered_set out;
    for (; first != last; ++first) {
      auto r = out.insert(*first);
      if (!r) {
        return ::std::unexpected<::std::std_error>{::std::move(r.error())};
      }
    }
    return ::std::expected<unordered_set, ::std::std_error>{::std::move(out)};
  }

  bool      empty() const noexcept { return 0U == m_size; }
  size_type size() const noexcept { return m_size; }
  size_type bucket_count() const noexcept { return m_nbuckets; }
  float     load_factor() const noexcept {
    return (0U == m_nbuckets)
               ? 0.0F
               : (static_cast<float>(m_size) / static_cast<float>(m_nbuckets));
  }
  float max_load_factor() const noexcept { return 1.0F; }

  const_iterator begin() const noexcept {
    for (::std::size_t b{0U}; b < m_nbuckets; ++b) {
      if (nullptr != m_buckets[b]) {
        return const_iterator{m_buckets, m_nbuckets, b, m_buckets[b]};
      }
    }
    return this->end();
  }
  const_iterator end() const noexcept {
    return const_iterator{m_buckets, m_nbuckets, m_nbuckets, nullptr};
  }
  const_iterator cbegin() const noexcept { return this->begin(); }
  const_iterator cend() const noexcept { return this->end(); }

  const_iterator find(t_key const &in_k) const {
    if (0U == m_nbuckets) {
      return this->end();
    }
    ::std::size_t const h{m_hash(in_k)};
    ::std::size_t const b{h % m_nbuckets};
    for (node *n{m_buckets[b]}; nullptr != n; n = n->m_next) {
      // The stored hash is compared FIRST, so a bucket full of long
      // strings costs one word compare each rather than one `strcmp'.
      if ((n->m_hash == h) && m_eq(n->m_value, in_k)) {
        return const_iterator{m_buckets, m_nbuckets, b, n};
      }
    }
    return this->end();
  }

  size_type count(t_key const &in_k) const {
    return (this->find(in_k) == this->end()) ? 0U : 1U;
  }

  // `tuple<iterator, bool>' and not `pair', because this library has no
  // `pair' and `set::insert' already answers a tuple.
  ::std::expected<::std::tuple<const_iterator, bool>, ::std::std_error> insert(
      t_key const &in_k) {
    const_iterator const found{this->find(in_k)};
    if (found != this->end()) {
      return ::std::expected<::std::tuple<const_iterator, bool>, ::std::std_error>{
          ::std::tuple<const_iterator, bool>{found, false}};
    }
    if (!this->reserve_one()) {
      return ::std::unexpected<::std::std_error>{::std::std_error::allocate_error};
    }
    ::std::size_t const h{m_hash(in_k)};
    ::std::size_t const b{h % m_nbuckets};
    void *const         p{::std::malloc(sizeof(node))};
    if (nullptr == p) {
      return ::std::unexpected<::std::std_error>{::std::std_error::allocate_error};
    }
    node *const n{static_cast<node *>(p)};
    n->m_next = m_buckets[b];
    n->m_hash = h;
    ::new (static_cast<void *>(&n->m_value)) t_key(in_k);
    m_buckets[b] = n;
    ++m_size;
    return ::std::expected<::std::tuple<const_iterator, bool>, ::std::std_error>{
        ::std::tuple<const_iterator, bool>{
            const_iterator{m_buckets, m_nbuckets, b, n}, true}};
  }

  size_type erase(t_key const &in_k) {
    if (0U == m_nbuckets) {
      return 0U;
    }
    ::std::size_t const h{m_hash(in_k)};
    ::std::size_t const b{h % m_nbuckets};
    node              **link{&m_buckets[b]};
    while (nullptr != *link) {
      node *const n{*link};
      if ((n->m_hash == h) && m_eq(n->m_value, in_k)) {
        *link = n->m_next;
        n->m_value.~t_key();
        ::std::free(n);
        --m_size;
        return 1U;
      }
      link = &n->m_next;
    }
    return 0U;
  }

  void clear() noexcept {
    for (::std::size_t b{0U}; b < m_nbuckets; ++b) {
      node *n{m_buckets[b]};
      while (nullptr != n) {
        node *const next{n->m_next};
        n->m_value.~t_key();
        ::std::free(n);
        n = next;
      }
      m_buckets[b] = nullptr;
    }
    m_size = 0U;
  }

  void swap(unordered_set &other) noexcept {
    node **const  bk{m_buckets};
    ::std::size_t nb{m_nbuckets};
    ::std::size_t sz{m_size};
    m_buckets        = other.m_buckets;
    m_nbuckets       = other.m_nbuckets;
    m_size           = other.m_size;
    other.m_buckets  = bk;
    other.m_nbuckets = nb;
    other.m_size     = sz;
  }

  ::std::expected<void, ::std::std_error> rehash(size_type in_want) {
    ::std::size_t const want{uset_detail::next_prime(
        (in_want > m_size) ? in_want : (m_size + 1U))};
    if (want == m_nbuckets) {
      return ::std::expected<void, ::std::std_error>{};
    }
    void *const p{::std::malloc(want * sizeof(node *))};
    if (nullptr == p) {
      return ::std::unexpected<::std::std_error>{::std::std_error::allocate_error};
    }
    node **const nb{static_cast<node **>(p)};
    for (::std::size_t i{0U}; i < want; ++i) {
      nb[i] = nullptr;
    }
    // ***THE NODES MOVE, THE ELEMENTS DO NOT.***  Relinking by pointer
    // means no `t_key' is copied, constructed or destroyed by a rehash
    // -- which is what makes a rehash safe for a type whose copy can
    // fail, and this library has no other kind.
    for (::std::size_t b{0U}; b < m_nbuckets; ++b) {
      node *n{m_buckets[b]};
      while (nullptr != n) {
        node *const   next{n->m_next};
        ::std::size_t const nbi{n->m_hash % want};
        n->m_next = nb[nbi];
        nb[nbi]   = n;
        n         = next;
      }
    }
    ::std::free(m_buckets);
    m_buckets  = nb;
    m_nbuckets = want;
    return ::std::expected<void, ::std::std_error>{};
  }

private:
  void tidy() noexcept {
    this->clear();
    ::std::free(m_buckets);
    m_buckets  = nullptr;
    m_nbuckets = 0U;
  }

  bool reserve_one() {
    if ((0U == m_nbuckets) || ((m_size + 1U) > m_nbuckets)) {
      return static_cast<bool>(this->rehash((m_size + 1U) * 2U));
    }
    return true;
  }

  node        **m_buckets;
  ::std::size_t m_nbuckets;
  ::std::size_t m_size;
  t_hash        m_hash;
  t_equal       m_eq;
};

template<class t_key, class t_hash, class t_equal>
inline void swap(unordered_set<t_key, t_hash, t_equal> &a,
                 unordered_set<t_key, t_hash, t_equal> &b) noexcept {
  a.swap(b);
}

} // namespace std

#endif // APEXP_STD_CONTAINERS_UNORDERED_SET_H
