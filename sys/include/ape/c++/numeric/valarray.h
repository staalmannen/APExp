// ***************************************************************************
// * APExp addition to portable_stl -- `valarray'.
// *
// * Project="APExp C++ library" File="numeric/valarray.h"
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
//
// ---- WHAT ASKED FOR IT, AND WHAT IT ACTUALLY ASKED FOR -------------------
//
// re2c was the only caller, and **the demand was measured rather than
// guessed at**: `<valarray>' is included by five of its files and used in
// exactly ONE line --
//
//     std::valarray<bool> loops(skel.nodes_count);   // control_flow.cc:61
//
// a depth-first-search visited bitmap, read and written with `operator[]'
// and nothing else.  The other four includes use no name from the header.
//
// *That is what decided this file's shape.*  A `valarray' written from the
// standard's synopsis is slices, generalised slices, mask and indirect
// arrays, expression templates and twenty transcendental free functions;
// a `valarray' written from the measurement is a contiguous array with
// arithmetic.  **This is the second**, and every omission below is named
// with the substitute that replaces it, because an omission whose
// replacement is worse is a gap and an omission whose replacement is a
// line of caller code is a choice.
//
// ---- IT FOLLOWS THE LIBRARY'S CONVENTION AND NOT THE STANDARD'S ----------
//
// Read out of `vector/vector.h' and `containers/deque.h' rather than
// chosen: a default constructor that CANNOT fail, static factories
// returning `expected<valarray, std_error>', and every operation that
// ALLOCATES returning `expected' where the standard returns a value.
//
// *A second convention inside one library is worse than one deviation.*
//
// **So the standard's sizing constructor `valarray<T> v(n)' is spelled
// `valarray<T>::make_valarray(n)' here**, and re2c's one line needs a
// one-line change when it is ported -- which it needs anyway, its 63
// `std::vector' sites being on the same convention already.
//
// ---- WHAT IS ABSENT, AND WITH WHAT INSTEAD -------------------------------
//
// **The binary operators (`a + b', `a * b', ...) are ABSENT.**  They
// allocate, so under this library's convention they would have to answer
// `expected<valarray, std_error>' -- an operator whose result cannot be
// used as an operand, so `a + b + c' would not chain and every use site
// would need unwrapping anyway.  *The substitute is not worse*: clone the
// left operand and use the compound form,
//
//     auto r = a.clone();                 // says no if it cannot
//     if (r) { r.value() += b; }
//
// which is two lines, allocates once instead of once per operator, and
// reports the failure the operator form would have had to report too.
//
// **The compound operators are PRESENT and cannot fail**, because they
// write into storage that already exists.  They are what arithmetic in a
// loop uses in any case.
//
// **`slice', `gslice', `mask_array', `indirect_array' and the
// transcendental free functions (`sqrt', `sin', `pow', ...) are ABSENT.**
// Nothing in this tree has asked for one, the slice proxies are most of
// the standard's `valarray' by volume, and `apply' covers the elementwise
// function case in one call.  *Absent rather than stubbed*: a name that
// compiles and answers nonsense is this tree's single most common bug.
//
// ---- MISMATCHED SIZES ----------------------------------------------------
//
// The standard says a compound operation between two `valarray's of
// different size is undefined, so any behaviour here conforms.  **This
// file does NOTHING**, which is the one choice that cannot read or write
// past either object; `size()' is how a caller tells.

#ifndef APEXP_STD_NUMERIC_VALARRAY_H
#define APEXP_STD_NUMERIC_VALARRAY_H

#include "../common/size_t.h"
#include "../common/ptrdiff_t.h"
#include "../error/portable_stl_error.h"
#include "../utility/expected/expected.h"
#include "../utility/expected/unexpected.h"
#include "../utility/general/move.h"
#include "../cstdlib.stdh"
#include "../new.stdh"

namespace std {

template<class t_type> class valarray final {
public:
  using value_type = t_type;
  using size_type  = ::std::size_t;

  // ---- construction ------------------------------------------------------

  // Empty, and cannot fail.  This is the only public constructor; the
  // sizing ones are the `make_valarray' factories below.
  valarray() noexcept : m_data{nullptr}, m_size{0U} {
  }

  ~valarray() {
    this->wipe();
  }

  valarray(valarray &&in_o) noexcept : m_data{in_o.m_data}, m_size{in_o.m_size} {
    in_o.m_data = nullptr;
    in_o.m_size = 0U;
  }

  valarray &operator=(valarray &&in_o) noexcept {
    if (this != &in_o) {
      this->wipe();
      m_data      = in_o.m_data;
      m_size      = in_o.m_size;
      in_o.m_data = nullptr;
      in_o.m_size = 0U;
    }
    return *this;
  }

  // Copying allocates, so it is `clone()' and not a constructor.
  valarray(valarray const &)            = delete;
  valarray &operator=(valarray const &) = delete;

  // `n' elements, each VALUE-INITIALISED -- which for every arithmetic
  // type is zero, and is what re2c's bitmap relies on.
  static ::std::expected<valarray, ::std::std_error> make_valarray(size_type in_n) {
    valarray v{};
    if (!v.allocate(in_n)) {
      return ::std::unexpected<::std::std_error>{::std::std_error::allocate_error};
    }
    for (size_type i{0U}; i < in_n; ++i) {
      ::new (static_cast<void *>(v.m_data + i)) t_type();
      ++v.m_size;
    }
    return ::std::expected<valarray, ::std::std_error>{::std::move(v)};
  }

  static ::std::expected<valarray, ::std::std_error> make_valarray(size_type     in_n,
                                                                   t_type const &in_v) {
    valarray v{};
    if (!v.allocate(in_n)) {
      return ::std::unexpected<::std::std_error>{::std::std_error::allocate_error};
    }
    for (size_type i{0U}; i < in_n; ++i) {
      ::new (static_cast<void *>(v.m_data + i)) t_type(in_v);
      ++v.m_size;
    }
    return ::std::expected<valarray, ::std::std_error>{::std::move(v)};
  }

  // A forward range.  Named apart from the two above because `(5, 7)'
  // otherwise resolves here by being a better match than a conversion --
  // the same trap `make_deque_range' exists for.
  template<class t_iter>
  static ::std::expected<valarray, ::std::std_error> make_valarray_range(t_iter in_first,
                                                                         t_iter in_last) {
    size_type n{0U};
    for (t_iter it{in_first}; it != in_last; ++it) {
      ++n;
    }
    valarray v{};
    if (!v.allocate(n)) {
      return ::std::unexpected<::std::std_error>{::std::std_error::allocate_error};
    }
    for (t_iter it{in_first}; it != in_last; ++it) {
      ::new (static_cast<void *>(v.m_data + v.m_size)) t_type(*it);
      ++v.m_size;
    }
    return ::std::expected<valarray, ::std::std_error>{::std::move(v)};
  }

  ::std::expected<valarray, ::std::std_error> clone() const {
    return make_valarray_range(m_data, m_data + m_size);
  }

  // ---- access ------------------------------------------------------------

  size_type size() const noexcept {
    return m_size;
  }

  bool empty() const noexcept {
    return 0U == m_size;
  }

  t_type       *data() noexcept {
    return m_data;
  }
  t_type const *data() const noexcept {
    return m_data;
  }

  // Unchecked, as the standard's is.  **`valarray<bool>' is NOT a
  // specialisation** -- unlike `vector<bool>' -- so this is a real
  // `bool &' and `v[i] = true' works, which is the whole of re2c's use.
  t_type &operator[](size_type in_i) noexcept {
    return m_data[in_i];
  }
  t_type const &operator[](size_type in_i) const noexcept {
    return m_data[in_i];
  }

  t_type       *begin() noexcept {
    return m_data;
  }
  t_type       *end() noexcept {
    return m_data + m_size;
  }
  t_type const *begin() const noexcept {
    return m_data;
  }
  t_type const *end() const noexcept {
    return m_data + m_size;
  }

  // ---- sizing ------------------------------------------------------------

  // The standard's `resize' VALUE-INITIALISES every element and not only
  // the new ones; a `valarray' is a numeric vector, not a container that
  // preserves its contents.  Kept, because code written against the
  // standard would otherwise read stale values.
  ::std::expected<void, ::std::std_error> resize(size_type in_n) {
    auto r = make_valarray(in_n);
    if (!r) {
      return ::std::unexpected<::std::std_error>{::std::move(r.error())};
    }
    *this = ::std::move(r.value());
    return ::std::expected<void, ::std::std_error>{};
  }

  ::std::expected<void, ::std::std_error> resize(size_type in_n, t_type const &in_v) {
    auto r = make_valarray(in_n, in_v);
    if (!r) {
      return ::std::unexpected<::std::std_error>{::std::move(r.error())};
    }
    *this = ::std::move(r.value());
    return ::std::expected<void, ::std::std_error>{};
  }

  // ---- compound assignment -----------------------------------------------
  //
  // These write into storage that exists, so none of them can fail and
  // none of them returns `expected'.  A size mismatch does nothing; see
  // the head of this file.

#define APEXP_VALARRAY_COMPOUND(OP)                                                      \
  valarray &operator OP(valarray const &in_o) noexcept {                                 \
    if (m_size == in_o.m_size) {                                                         \
      for (size_type i{0U}; i < m_size; ++i) {                                           \
        m_data[i] OP in_o.m_data[i];                                                     \
      }                                                                                  \
    }                                                                                    \
    return *this;                                                                        \
  }                                                                                      \
  valarray &operator OP(t_type const &in_v) noexcept {                                   \
    for (size_type i{0U}; i < m_size; ++i) {                                             \
      m_data[i] OP in_v;                                                                 \
    }                                                                                    \
    return *this;                                                                        \
  }

  APEXP_VALARRAY_COMPOUND(+=)
  APEXP_VALARRAY_COMPOUND(-=)
  APEXP_VALARRAY_COMPOUND(*=)
  APEXP_VALARRAY_COMPOUND(/=)
  APEXP_VALARRAY_COMPOUND(%=)
  APEXP_VALARRAY_COMPOUND(&=)
  APEXP_VALARRAY_COMPOUND(|=)
  APEXP_VALARRAY_COMPOUND(^=)
  APEXP_VALARRAY_COMPOUND(<<=)
  APEXP_VALARRAY_COMPOUND(>>=)

#undef APEXP_VALARRAY_COMPOUND

  // ---- reductions ----------------------------------------------------------
  //
  // The standard leaves these undefined for an empty `valarray' because
  // there is no value to return.  Here `sum()' answers a
  // value-initialised `t_type' (zero for every arithmetic type) and
  // `min()'/`max()' answer the same, which is a defined answer rather
  // than a read of `m_data[0]' through a null pointer.

  t_type sum() const {
    if (0U == m_size) {
      return t_type();
    }
    t_type acc{m_data[0]};
    for (size_type i{1U}; i < m_size; ++i) {
      acc += m_data[i];
    }
    return acc;
  }

  t_type min() const {
    if (0U == m_size) {
      return t_type();
    }
    t_type best{m_data[0]};
    for (size_type i{1U}; i < m_size; ++i) {
      if (m_data[i] < best) {
        best = m_data[i];
      }
    }
    return best;
  }

  t_type max() const {
    if (0U == m_size) {
      return t_type();
    }
    t_type best{m_data[0]};
    for (size_type i{1U}; i < m_size; ++i) {
      if (best < m_data[i]) {
        best = m_data[i];
      }
    }
    return best;
  }

  // ---- elementwise function ------------------------------------------------

  // In place, so it cannot fail.  This is the one to reach for; `apply'
  // below is the standard's shape and allocates.
  template<class t_fn> valarray &apply_inplace(t_fn in_fn) {
    for (size_type i{0U}; i < m_size; ++i) {
      m_data[i] = in_fn(m_data[i]);
    }
    return *this;
  }

  template<class t_fn> ::std::expected<valarray, ::std::std_error> apply(t_fn in_fn) const {
    auto r = this->clone();
    if (!r) {
      return ::std::unexpected<::std::std_error>{::std::move(r.error())};
    }
    r.value().apply_inplace(in_fn);
    return r;
  }

  // ---- shifts --------------------------------------------------------------
  //
  // Both allocate, so both answer `expected'.  A positive count moves
  // elements towards the FRONT, as the standard's do; `shift' fills with
  // a value-initialised `t_type' and `cshift' wraps.

  ::std::expected<valarray, ::std::std_error> shift(int in_n) const {
    auto r = make_valarray(m_size);
    if (!r) {
      return ::std::unexpected<::std::std_error>{::std::move(r.error())};
    }
    valarray &out = r.value();
    for (size_type i{0U}; i < m_size; ++i) {
      ::std::ptrdiff_t const src{static_cast<::std::ptrdiff_t>(i) + in_n};
      if ((src >= 0) && (src < static_cast<::std::ptrdiff_t>(m_size))) {
        out.m_data[i] = m_data[static_cast<size_type>(src)];
      }
    }
    return r;
  }

  ::std::expected<valarray, ::std::std_error> cshift(int in_n) const {
    auto r = make_valarray(m_size);
    if (!r) {
      return ::std::unexpected<::std::std_error>{::std::move(r.error())};
    }
    if (0U == m_size) {
      return r;
    }
    valarray              &out = r.value();
    ::std::ptrdiff_t const n   = static_cast<::std::ptrdiff_t>(m_size);
    for (size_type i{0U}; i < m_size; ++i) {
      // `%' on a negative left operand truncates towards zero in C++, so
      // the result is normalised into [0, n) by hand rather than relied on.
      ::std::ptrdiff_t src{(static_cast<::std::ptrdiff_t>(i) + in_n) % n};
      if (src < 0) {
        src += n;
      }
      out.m_data[i] = m_data[static_cast<size_type>(src)];
    }
    return r;
  }

private:
  bool allocate(size_type in_n) noexcept {
    if (0U == in_n) {
      m_data = nullptr;
      m_size = 0U;
      return true;
    }
    // The multiplication is checked, because `n * sizeof(T)' wrapping
    // gives a short block and a write past its end -- and on this
    // platform `size_t' is 64-bit while `long' is not, so a reviewer
    // cannot assume the product is computed in the wider type.
    if (in_n > (static_cast<size_type>(-1) / sizeof(t_type))) {
      return false;
    }
    void *p{::std::malloc(in_n * sizeof(t_type))};
    if (nullptr == p) {
      return false;
    }
    m_data = static_cast<t_type *>(p);
    m_size = 0U;
    return true;
  }

  void wipe() noexcept {
    for (size_type i{0U}; i < m_size; ++i) {
      m_data[i].~t_type();
    }
    if (nullptr != m_data) {
      ::std::free(m_data);
    }
    m_data = nullptr;
    m_size = 0U;
  }

  t_type   *m_data;
  size_type m_size;
};

} // namespace std

#endif // APEXP_STD_NUMERIC_VALARRAY_H
