// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="front_insert_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FRONT_INSERT_ITERATOR_H
#define PSTL_FRONT_INSERT_ITERATOR_H

#include "../common/ptrdiff_t.h"
#include "../memory/addressof.h"
#include "../utility/general/move.h"
#include "output_iterator_tag.h"

namespace portable_stl {

/**
 * @brief Iterator adaptor for insertion at the front of a container.
 * front_insert_iterator is a LegacyOutputIterator that prepends elements to a container for which it was
 * constructed. The container's push_front() member function is called whenever the iterator (whether dereferenced or
 * not) is assigned to. Incrementing the front_insert_iterator is a no-op.
 *
 * @tparam container_t Container that supports a push_front operation.
 */
template<class container_t> class front_insert_iterator final {
  /**
   * @brief A pointer of type container_type*
   */
  container_t *m_container;

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
   * @param cont Given container.
   */
  constexpr explicit front_insert_iterator(container_type &cont) : m_container(::portable_stl::addressof(cont)) {
  }

  /**
   * @brief Default ctor.
   */
  constexpr front_insert_iterator() noexcept : m_container(nullptr) {
  }

  /**
   * @brief Default copy ctor.
   */
  front_insert_iterator(front_insert_iterator const &) = default;

  /**
   * @brief Default copy assignment operator.
   * @return front_insert_iterator& 
   */
  front_insert_iterator &operator=(front_insert_iterator const &) & = default;

  /**
   * @brief Inserts the given value value to the container.
   * @param value
   * @return *this.
   */
  front_insert_iterator &operator=(typename container_type::value_type const &value) & {
    m_container->push_front(value);
    return *this;
  }

  /**
   * @brief Inserts the given value value to the container.
   * @param value
   * @return *this.
   */
  front_insert_iterator &operator=(typename container_type::value_type &&value) & {
    m_container->push_front(::portable_stl::move(value));
    return *this;
  }

  /**
   * @brief Does nothing
   * This member function is provided to satisfy the requirements of LegacyOutputIterator.
   * It returns the iterator itself, which makes it possible to use code such as *iter = value to output (insert) the
   * value into the underlying container.
   * @return *this.
   */
  front_insert_iterator &operator*() noexcept {
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
  front_insert_iterator &operator++() noexcept {
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
  front_insert_iterator operator++(int) noexcept {
    return *this;
  }
};

/**
 * @brief A convenience function template that constructs a front_insert_iterator for the container c with the type
 * deduced from the type of the argument.
 *
 * @tparam container_type Container type.
 * @param container Container that supports a push_front operation.
 * @return A front_insert_iterator which can be used to add elements to the beginning of the container container.
 */
template<class container_type>
constexpr front_insert_iterator<container_type> front_inserter(container_type &container) {
  return front_insert_iterator<container_type>(container);
}
} // namespace portable_stl

#endif /* PSTL_FRONT_INSERT_ITERATOR_H */
