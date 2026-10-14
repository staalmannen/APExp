// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="wrap_iter.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_WRAP_ITER_H
#define PSTL_WRAP_ITER_H

#include "../memory/to_address.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/type_relations/is_convertible.h"
#include "contiguous_iterator_tag.h"
#include "iterator_traits.h"

namespace portable_stl {

/**
 * @brief A type that meets the forward iterator requirements (25.3.5.5) with value type T.
 * Used in contatiner clases.
 *
 * from gcc:
 * This iterator adapter is normal in the sense that it does not change the semantics of any of the operators of its
 * iterator parameter. Its primary purpose is to convert an iterator that is not a class, e.g. a pointer, into an
 * iterator that is a class.
 * @tparam t_iterator
 */
template<class t_iterator> class wrap_iter final {
public:
  using iterator_type     = t_iterator;
  using value_type        = typename ::portable_stl::iterator_traits<iterator_type>::value_type;
  using difference_type   = typename ::portable_stl::iterator_traits<iterator_type>::difference_type;
  using pointer           = typename ::portable_stl::iterator_traits<iterator_type>::pointer;
  using reference         = typename ::portable_stl::iterator_traits<iterator_type>::reference;
  using iterator_category = typename ::portable_stl::iterator_traits<iterator_type>::iterator_category;
  using iterator_concept  = ::portable_stl::contiguous_iterator_tag;

private:
  iterator_type m_iter;

public:
  constexpr wrap_iter() noexcept : m_iter() {
  }

  template<class t_other_type,
           ::portable_stl::enable_if_bool_constant_t<is_convertible<t_other_type, iterator_type>, void *> = nullptr>
  constexpr wrap_iter(wrap_iter<t_other_type> const &other) noexcept : m_iter(other.base()) {
  }

  constexpr reference operator*() const noexcept {
    return *m_iter;
  }

  constexpr pointer operator->() const noexcept {
    return ::portable_stl::to_address(m_iter);
  }

  wrap_iter &operator++() noexcept {
    ++m_iter;
    return *this;
  }

  wrap_iter operator++(int) noexcept {
    wrap_iter tmp(*this);
    ++(*this);
    return tmp;
  }

  wrap_iter &operator--() noexcept {
    --m_iter;
    return *this;
  }

  wrap_iter operator--(int) noexcept {
    wrap_iter tmp(*this);
    --(*this);
    return tmp;
  }

  wrap_iter operator+(difference_type num) const noexcept {
    wrap_iter ret(*this);
    ret += num;
    return ret;
  }

  wrap_iter &operator+=(difference_type num) noexcept {
    m_iter += num;
    return *this;
  }

  constexpr wrap_iter operator-(difference_type num) const noexcept {
    return *this + (-num);
  }

  wrap_iter &operator-=(difference_type num) noexcept {
    *this += -num;
    return *this;
  }

  constexpr reference operator[](difference_type num) const noexcept {
    return m_iter[num];
  }

  constexpr iterator_type base() const noexcept {
    return m_iter;
  }

  /**
   * @brief Check if internal pointer is valid.
   * @retval true if pointer is valid.
   * @retval false if pointer is invalid.
   */
  explicit operator bool() const noexcept {
    return !(pointer() == m_iter);
  }

// private:
  constexpr explicit wrap_iter(iterator_type iter) noexcept : m_iter(iter) {
  }

  template<class t_other_type> friend class wrap_iter;
  template<class t_char_type, class t_char_traits, class t_allocator> friend class basic_string;
  template<class t_type, class t_allocator> friend class vector;
  //   template<class _Tp, size_t> friend class span;
};

template<class t_iterator_type>
constexpr bool operator==(wrap_iter<t_iterator_type> const &lhv, wrap_iter<t_iterator_type> const &rhv) noexcept {
  return lhv.base() == rhv.base();
}

template<class t_iterator_type1, class t_iterator_type2>
constexpr bool operator==(wrap_iter<t_iterator_type1> const &lhv, wrap_iter<t_iterator_type2> const &rhv) noexcept {
  return lhv.base() == rhv.base();
}

template<class t_iterator_type>
constexpr bool operator<(wrap_iter<t_iterator_type> const &lhv, wrap_iter<t_iterator_type> const &rhv) noexcept {
  return lhv.base() < rhv.base();
}

template<class t_iterator_type1, class t_iterator_type2>
constexpr bool operator<(wrap_iter<t_iterator_type1> const &lhv, wrap_iter<t_iterator_type2> const &rhv) noexcept {
  return lhv.base() < rhv.base();
}

template<class t_iterator_type>
constexpr bool operator!=(wrap_iter<t_iterator_type> const &lhv, wrap_iter<t_iterator_type> const &rhv) noexcept {
  return !(lhv == rhv);
}

template<class t_iterator_type1, class t_iterator_type2>
constexpr bool operator!=(wrap_iter<t_iterator_type1> const &lhv, wrap_iter<t_iterator_type2> const &rhv) noexcept {
  return !(lhv == rhv);
}

template<class t_iterator_type>
constexpr bool operator>(wrap_iter<t_iterator_type> const &lhv, wrap_iter<t_iterator_type> const &rhv) noexcept {
  return rhv < lhv;
}

template<class t_iterator_type1, class t_iterator_type2>
constexpr bool operator>(wrap_iter<t_iterator_type1> const &lhv, wrap_iter<t_iterator_type2> const &rhv) noexcept {
  return rhv < lhv;
}

template<class t_iterator_type>
constexpr bool operator>=(wrap_iter<t_iterator_type> const &lhv, wrap_iter<t_iterator_type> const &rhv) noexcept {
  return !(lhv < rhv);
}

template<class t_iterator_type1, class t_iterator_type2>
constexpr bool operator>=(wrap_iter<t_iterator_type1> const &lhv, wrap_iter<t_iterator_type2> const &rhv) noexcept {
  return !(lhv < rhv);
}

template<class t_iterator_type>
constexpr bool operator<=(wrap_iter<t_iterator_type> const &lhv, wrap_iter<t_iterator_type> const &rhv) noexcept {
  return !(rhv < lhv);
}

template<class t_iterator_type1, class t_iterator_type2>
constexpr bool operator<=(wrap_iter<t_iterator_type1> const &lhv, wrap_iter<t_iterator_type2> const &rhv) noexcept {
  return !(rhv < lhv);
}

template<class t_iterator_type1, class t_iterator_type2>
constexpr auto operator-(wrap_iter<t_iterator_type1> const &lhv,
                         wrap_iter<t_iterator_type2> const &rhv) noexcept -> decltype(lhv.base() - rhv.base()) {
  return lhv.base() - rhv.base();
}

template<class t_iterator_type>
constexpr wrap_iter<t_iterator_type> operator+(typename wrap_iter<t_iterator_type>::difference_type num,
                                               wrap_iter<t_iterator_type>                           other) noexcept {
  other += num;
  return other;
}

template<class t_iterator> struct pointer_traits<wrap_iter<t_iterator>> {
  typedef wrap_iter<t_iterator>                                pointer;
  typedef typename pointer_traits<t_iterator>::element_type    element_type;
  typedef typename pointer_traits<t_iterator>::difference_type difference_type;

  constexpr static element_type *to_address(pointer iter_wrap) noexcept {
    return ::portable_stl::to_address(iter_wrap.base());
  }
};
} // namespace portable_stl

#endif // PSTL_WRAP_ITER_H
