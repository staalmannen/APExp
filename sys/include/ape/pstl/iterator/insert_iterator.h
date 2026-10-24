// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="insert_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************

#ifndef PSTL_INSERT_ITERATOR_H
#define PSTL_INSERT_ITERATOR_H

#include "../common/ptrdiff_t.h"
#include "../memory/addressof.h"
#include "../ranges/iterator_t.h"
#include "../utility/general/move.h"
#include "output_iterator_tag.h"

namespace portable_stl {

/**
 * @brief Iterator adaptor for insertion into a container.
 * insert_iterator is a LegacyOutputIterator that inserts elements into a container for which it was constructed,
 * at the position pointed to by the supplied iterator. The container's insert() member function is called whenever the
 * iterator (whether dereferenced or not) is assigned to. Incrementing the insert_iterator is a no-op.
 *
 * @tparam container_t Container that supports a push_front operation.
 */
template<class container_t> class insert_iterator final {
  /**
   * @brief A pointer to container_type object.
   */
  container_t                                    *m_container;
  /**
   * @brief iterator inside container.
   */
  ::portable_stl::ranges::iterator_t<container_t> m_iter;

public:
  /**
   * @brief Iterator categoty.
   */
  using iterator_category = ::portable_stl::output_iterator_tag;
  /**
   * @brief Associated value types of an iterator.
   */
  using value_type        = void;
  /**
   * @brief Associated difference types of an iterator.
   */
  using difference_type   = ::portable_stl::ptrdiff_t;
  /**
   * @brief Associated pointer types of an iterator.
   */
  using pointer           = void;
  /**
   * @brief Associated reference types of an iterator.
   */
  using reference         = void;
  /**
   * @brief Associated container types of an iterator.
   */
  using container_type    = container_t;

  /**
   * @brief Ctor.
   *
   * @param cont Given container.
   * @param iterator Given iteraton inside container.
   */
  constexpr explicit insert_iterator(container_type &cont, ::portable_stl::ranges::iterator_t<container_t> iterator)
      : m_container(::portable_stl::addressof(cont)), m_iter(iterator) {
  }

  /**
   * @brief Copy constructor (default).
   */
  constexpr insert_iterator(insert_iterator const &) = default;

  /**
   * @brief Default assignment operator.
   * @return insert_iterator&
   */
  insert_iterator &operator=(insert_iterator const &) = default;

  /**
   * @brief Inserts the given value value to the container.
   * @param value
   * @return *this.
   */
  insert_iterator &operator=(typename container_type::value_type const &value) & {
    m_iter = m_container->insert(m_iter, value);
    ++m_iter;
    return *this;
  }

  /**
   * @brief Inserts the given value value to the container.
   * @param value
   * @return *this.
   */
  insert_iterator &operator=(typename container_type::value_type &&value) & {
    m_iter = m_container->insert(m_iter, ::portable_stl::move(value));
    ++m_iter;
    return *this;
  }

  /**
   * @brief Does nothing
   * This member function is provided to satisfy the requirements of LegacyOutputIterator.
   * It returns the iterator itself, which makes it possible to use code such as *iter = value to output (insert) the
   * value into the underlying container.
   * @return *this.
   */
  insert_iterator &operator*() {
    return *this;
  }

  /**
   * @brief Does nothing.
   * These operator overloads are provided to satisfy the requirements of LegacyOutputIterator.
   * They make it possible for the expressions *iter++=value and *++iter=value to be used to output (insert) a value
   * into the underlying container.
   *
   * @return *this.
   */
  insert_iterator &operator++() {
    return *this;
  }

  /**
   * @brief Does nothing.
   * These operator overloads are provided to satisfy the requirements of LegacyOutputIterator.
   * They make it possible for the expressions *iter++=value and *++iter=value to be used to output (insert) a value
   * into the underlying container.
   *
   * @return *this.
   */
  insert_iterator operator++(int) {
    return *this;
  }
};

/**
 * @brief A convenience function template that constructs a insert_iterator for the container c and its iterator i
 with
 * the type deduced from the type of the argument.
 *
 * @tparam container_t container that supports an insert operation
 * @param container Given container.
 * @param iter Given iterator in container.
 * @return
 */
template<class container_t>
constexpr insert_iterator<container_t> inserter(container_t                                    &container,
                                                ::portable_stl::ranges::iterator_t<container_t> iter) {
  return insert_iterator<container_t>(container, iter);
}
} // namespace portable_stl

#endif /* PSTL_INSERT_ITERATOR_H */
