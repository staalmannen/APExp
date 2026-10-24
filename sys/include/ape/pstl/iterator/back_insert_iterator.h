// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="back_insert_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BACK_INSERT_ITERATOR_H
#define PSTL_BACK_INSERT_ITERATOR_H

#include "../common/ptrdiff_t.h"
#include "../memory/addressof.h"
#include "../utility/general/move.h"
#include "output_iterator_tag.h"

namespace portable_stl {

/**
 * @brief Iterator adaptor for insertion at the end of a container.
 * back_insert_iterator is a LegacyOutputIterator that appends elements to a container for which it was
 * constructed. The container's push_back() member function is called whenever the iterator (whether dereferenced or
 * not) is assigned to.
 *
 * @tparam container_t Container that supports a push_back operation.
 */
template<class container_t> class back_insert_iterator final {
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
  constexpr explicit back_insert_iterator(container_type &cont) : m_container(::portable_stl::addressof(cont)) {
  }

  /**
   * @brief Default ctor.
   */
  constexpr back_insert_iterator() noexcept : m_container(nullptr) {
  }

    /**
   * @brief Default copy ctor.
   */
  back_insert_iterator(back_insert_iterator const &) = default;

  /**
   * @brief Default copy assignment operator.
   * @return back_insert_iterator& 
   */
  back_insert_iterator &operator=(back_insert_iterator const &) & = default;


  /**
   * @brief Inserts the given value value to the container.
   * @param value
   * @return *this.
   */
  back_insert_iterator &operator=(typename container_type::value_type const &value) & {
    m_container->push_back(value);
    return *this;
  }

  /**
   * @brief Inserts the given value value to the container.
   * @param value
   * @return *this.
   */
  back_insert_iterator &operator=(typename container_type::value_type &&value) & {
    m_container->push_back(::portable_stl::move(value));
    return *this;
  }

  /**
   * @brief Does nothing
   * This member function is provided to satisfy the requirements of LegacyOutputIterator.
   * It returns the iterator itself, which makes it possible to use code such as *iter = value to output (insert) the
   * value into the underlying container.
   * @return *this.
   */
  back_insert_iterator &operator*() noexcept {
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
  back_insert_iterator &operator++() noexcept {
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
  back_insert_iterator operator++(int) noexcept {
    return *this;
  }
};

/**
 * @brief A convenience function template that constructs a back_insert_iterator for the container c with the type
 * deduced from the type of the argument.
 *
 * @tparam container_type Container type.
 * @param container Container that supports a push_back operation.
 * @return A back_insert_iterator which can be used to add elements to the end of the container container.
 */
template<class container_type> constexpr back_insert_iterator<container_type> back_inserter(container_type &container) {
  return back_insert_iterator<container_type>(container);
}
} // namespace portable_stl

#endif /* PSTL_BACK_INSERT_ITERATOR_H */
