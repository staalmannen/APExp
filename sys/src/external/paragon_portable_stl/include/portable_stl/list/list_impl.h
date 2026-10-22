// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="list_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_LIST_IMPL_H
#define PSTL_LIST_IMPL_H

#include "../error/portable_stl_error.h"
#include "../memory/addressof.h"
#include "../memory/allocate_noexcept.h"
#include "../memory/allocator_traits.h"
#include "../memory/compressed_pair.h"
#include "../memory/construct_at.h"
#include "../memory/destroy_at.h"
#include "../memory/rebind_alloc.h"
#include "../memory/swap_allocator.h"
#include "../memory/unique_ptr.h"
#include "../metaprogramming/type_properties/is_nothrow_default_constructible.h"
#include "../metaprogramming/type_properties/is_nothrow_move_assignable.h"
#include "../metaprogramming/type_relations/is_same.h"
#include "../utility/expected/expected.h"
#include "../utility/expected/unexpected.h"
#include "../utility/general/swap.h"
#include "list_const_iterator.h"
#include "list_iterator.h"
#include "list_node.h"
#include "list_node_base.h"

namespace portable_stl {

/**
 * @brief List implementation class.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 */
template<class t_type, class t_allocator> class list_impl {
  /**
   * @brief Copy constructor (private).
   *
   */
  list_impl(list_impl const &);
  /**
   * @brief Copy assignment (private).
   *
   * @return list_impl& *this.
   */
  list_impl &operator=(list_impl const &);

public:
  /**
   * @brief Allocator type.
   *
   */
  using allocator_type = t_allocator;
  /**
   * @brief Allocator traits.
   *
   */
  using t_alloc_traits = ::portable_stl::allocator_traits<allocator_type>;
  /**
   * @brief Size type.
   *
   */
  using size_type      = typename t_alloc_traits::size_type;

protected:
  /**
   * @brief Value type.
   *
   */
  using value_type            = t_type;
  /**
   * @brief
   *
   */
  using t_void_pointer        = typename t_alloc_traits::void_pointer;
  /**
   * @brief List iterator type.
   *
   */
  using iterator              = list_iterator<value_type, t_void_pointer>;
  /**
   * @brief List constant iterator type.
   *
   */
  using const_iterator        = list_const_iterator<value_type, t_void_pointer>;
  /**
   * @brief Type of the node base.
   *
   */
  using t_node_base           = list_node_base<value_type, t_void_pointer>;
  /**
   * @brief Node type.
   *
   */
  using t_node_type           = list_node<value_type, t_void_pointer>;
  /**
   * @brief Node allocator type.
   *
   */
  using t_node_allocator      = ::portable_stl::rebind_alloc<t_alloc_traits, t_node_type>;
  /**
   * @brief Node allocator traits.
   *
   */
  using t_node_alloc_traits   = ::portable_stl::allocator_traits<t_node_allocator>;
  /**
   * @brief
   *
   */
  using t_node_pointer        = typename t_node_alloc_traits::pointer;
  /**
   * @brief
   *
   */
  using t_node_const_pointer  = typename t_node_alloc_traits::pointer;
  /**
   * @brief
   *
   */
  using t_node_pointer_traits = list_node_pointer_traits<value_type, t_void_pointer>;
  /**
   * @brief
   *
   */
  using t_link_pointer        = typename t_node_pointer_traits::t_link_pointer;
  /**
   * @brief
   *
   */
  using t_link_const_pointer  = t_link_pointer;
  /**
   * @brief
   *
   */
  using pointer               = typename t_alloc_traits::pointer;
  /**
   * @brief
   *
   */
  using const_pointer         = typename t_alloc_traits::const_pointer;
  /**
   * @brief
   *
   */
  using difference_type       = typename t_alloc_traits::difference_type;
  /**
   * @brief
   *
   */
  using t_node_base_allocator = ::portable_stl::rebind_alloc<t_alloc_traits, t_node_base>;
  /**
   * @brief
   *
   */
  using t_node_base_pointer   = typename ::portable_stl::allocator_traits<t_node_base_allocator>::pointer;
  static_assert((!::portable_stl::is_same<allocator_type, t_node_allocator>{}()),
                "internal allocator type must differ from user-specified "
                "type; otherwise overload resolution breaks");

  /**
   * @brief Base node represented element following the last element of the list last element to the end of the list.
   * (m_end.m_next points to the begin of the list)
   *
   */
  t_node_base m_end;

  /**
   * @brief Pair to store size of the container and node allocator.
   *
   */
  ::portable_stl::compressed_pair<size_type, t_node_allocator> m_size_alloc_pair;

  /**
   * @brief Returns link pointer to the end.
   *
   * @return t_link_pointer
   */
  t_link_pointer end_as_link() const noexcept {
    return t_node_pointer_traits::unsafe_link_pointer_cast(const_cast<t_node_base &>(m_end).M_self());
  }

  /**
   * @brief Access to size of the conatainer.
   *
   * @return size_type Size of the conatainer.
   */
  size_type &size_val() noexcept {
    return m_size_alloc_pair.get_first();
  }

  /**
   * @brief Access to size of the conatainer.
   *
   * @return size_type const& Size of the conatainer.
   */
  size_type const &size_val() const noexcept {
    return m_size_alloc_pair.get_first();
  }

  /**
   * @brief Access to the node allocator.
   *
   * @return t_node_allocator& Node allocator.
   */
  t_node_allocator &node_alloc() noexcept {
    return m_size_alloc_pair.get_second();
  }

  /**
   * @brief Access to the node allocator.
   *
   * @return t_node_allocator const& Node allocator.
   */
  t_node_allocator const &node_alloc() const noexcept {
    return m_size_alloc_pair.get_second();
  }

private:
  /**
   * @brief Helper class to deallocate node in memory guard.
   *
   */
  class NodeDeleter {
    /**
     * @brief Reference to node allocator.
     *
     */
    t_node_allocator &m_node_alloc;

  public:
    /**
     * @brief Constructor.
     *
     * @param node_alloc Actual node allocator to use.
     */
    explicit NodeDeleter(t_node_allocator &node_alloc) : m_node_alloc(node_alloc) {
    }

    /**
     * @brief Functional call operator.
     *
     * @param ptr Node pointer to deallocate.
     * @return ::portable_stl::expected<void, ::portable_stl::int32_t>
     */
    ::portable_stl::expected<void, ::portable_stl::int32_t> operator()(t_node_pointer ptr) noexcept {
      if (ptr) {
        t_node_alloc_traits::deallocate(m_node_alloc, ptr, 1);
      }
      return {};
    }
  };

  /**
   * @brief Use as guard.
   */
  using t_node_holder = ::portable_stl::unique_ptr<t_node_type, NodeDeleter>;

protected:
  /**
   * @brief Returns the maximum number of elements the list_impl is able to hold.
   *
   * @return size_type Maximum number of elements.
   */
  size_type get_node_alloc_max_size() const noexcept {
    return t_node_alloc_traits::max_size(node_alloc());
  }

  /**
   * @brief Unlink nodes from other.
   *
   * @param first Link pointer to the first node in range.
   * @param last Link pointer to the last node in range.
   */
  static void unlink_nodes(t_link_pointer first, t_link_pointer last) noexcept;

  /**
   * @brief Default constructor.
   *
   */
  list_impl() noexcept(::portable_stl::is_nothrow_default_constructible<t_node_allocator>{}());

  /**
   * @brief Constructor.
   *
   * @param alloc Given allocator.
   */
  list_impl(allocator_type const &alloc);

  /**
   * @brief Constructor.
   *
   * @param node_alloc Given node allocator.
   */
  list_impl(t_node_allocator const &node_alloc);

  /**
   * @brief Constructor.
   *
   * @param node_alloc Given node allocator.
   */
  list_impl(t_node_allocator &&node_alloc) noexcept;

  /**
   * @brief Destructor.
   *
   */
  ~list_impl();

  /**
   * @brief Erases all elements from the list_impl.
   *
   */
  void clear() noexcept;

  /**
   * @brief Checks if the list_impl has no elements.
   *
   * @return true If the list_impl is empty,
   * @return false otherwise.
   */
  bool empty() const noexcept {
    return size_val() == 0;
  }

  /**
   * @brief Returns an iterator to the first element of the list_impl.
   *
   * @return iterator Iterator to the first element.
   */
  iterator begin() noexcept {
    return iterator(m_end.m_next);
  }

  /**
   * @brief Returns a constant iterator to the first element of the list_impl.
   *
   * @return const_iterator Constant iterator to the first element.
   */
  const_iterator begin() const noexcept {
    return const_iterator(m_end.m_next);
  }

  /**
   * @brief Returns an iterator to the element following the last element of the list_impl.
   *
   * @return iterator Iterator to the element following the last element.
   */
  iterator end() noexcept {
    return iterator(end_as_link());
  }

  /**
   * @brief Returns a constant iterator to the element following the last element of the list_impl.
   *
   * @return const_iterator Constant iterator to the element following the last element.
   */
  const_iterator end() const noexcept {
    return const_iterator(end_as_link());
  }

  /**
   * @brief Exchanges the contents of the list_impl with those of other.
   *
   * @param other list_impl to exchange the contents with.
   */
  void swap(list_impl &other) noexcept;

  /**
   * @brief Copy assignment implementation.
   *
   * @param other Another list_impl object.
   */
  void copy_assign_alloc(list_impl const &other) {
    copy_assign_alloc(other, typename t_node_alloc_traits::propagate_on_container_copy_assignment{});
  }

  /**
   * @brief Move assignment implementation.
   *
   * @param other Another list_impl object.
   */
  void move_assign_alloc(list_impl &other) noexcept(
    !typename t_node_alloc_traits::propagate_on_container_move_assignment{}()
    || ::portable_stl::is_nothrow_move_assignable<t_node_allocator>{}()) {
    move_assign_alloc(other, typename t_node_alloc_traits::propagate_on_container_move_assignment{});
  }

  /**
   * @brief Create a node object.
   *
   * @tparam t_args
   * @param prev Pointer to the prev node.
   * @param next Pointer to the next node.
   * @param args Arguments to create node value with.
   * @return ::portable_stl::expected<t_node_pointer, ::portable_stl::portable_stl_error> Pointer to created node.
   */
  template<class... t_args>
  ::portable_stl::expected<t_node_pointer, ::portable_stl::portable_stl_error> create_node(
    t_link_pointer prev, t_link_pointer next, t_args &&...args) {
    t_node_allocator &node_allocator = node_alloc();
    auto             *new_node_mem   = ::portable_stl::allocate_noexcept(node_allocator, 1U); // exception free wrapper

    if (new_node_mem) {
      t_node_holder node_holder(new_node_mem, NodeDeleter(node_allocator));

      // Begin the lifetime of the node itself. Note that this doesn't begin the lifetime of the value
      // held inside the node, since we need to use the allocator's construct() method for that.
      //
      // We don't use the allocator's construct() method to construct the node itself since the
      // Cpp17FooInsertable named requirements don't require the allocator's construct() method
      // to work on anything other than the value_type.
      ::portable_stl::construct_at(::portable_stl::addressof(*new_node_mem), prev, next);

      // Now construct the value_type using the allocator's construct() method.
      t_node_alloc_traits::construct(
        node_allocator, ::portable_stl::addressof(new_node_mem->get_value()), ::portable_stl::forward<t_args>(args)...);

      return ::portable_stl::expected<t_node_pointer, ::portable_stl::portable_stl_error>(node_holder.release());
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
  }

  /**
   * @brief Delete node.
   * Destroy node's value and node itself. Then deallocate node's momory.
   *
   * @tparam t_args
   * @param node Node to destroy.
   */
  template<class... t_args> void delete_node(t_node_pointer node) {
    t_node_allocator &alloc = node_alloc();

    // For the same reason as above, we use the allocator's destroy() method for the value_type,
    // but not for the node itself.
    t_node_alloc_traits::destroy(alloc, ::portable_stl::addressof(node->get_value()));

    ::portable_stl::destroy_at(::portable_stl::addressof(*node));

    t_node_alloc_traits::deallocate(alloc, node, 1);
  }

private:
  /**
   * @brief Copy assignment implementation.
   *
   * @param other Another list_impl object.
   */
  void copy_assign_alloc(list_impl const &other, ::portable_stl::true_type) {
    if (node_alloc() != other.node_alloc()) {
      clear();
    }
    node_alloc() = other.node_alloc();
  }

  /**
   * @brief Copy assignment implementation.
   *
   * @param other Another list_impl object.
   */
  void copy_assign_alloc(list_impl const & /* other */, ::portable_stl::false_type) {
  }

  /**
   * @brief Move assignment implementation.
   *
   * @param other Another list_impl object.
   */
  void move_assign_alloc(list_impl &other, ::portable_stl::true_type) noexcept(
    ::portable_stl::is_nothrow_move_assignable<t_node_allocator>{}()) {
    node_alloc() = ::portable_stl::move(other.node_alloc());
  }

  /**
   * @brief Move assignment implementation.
   *
   * @param other Another list_impl object.
   */
  void move_assign_alloc(list_impl & /* other */, ::portable_stl::false_type) noexcept {
  }
};

/**
 * @brief Unlink nodes from other.
 *
 * @tparam t_type
 * @tparam t_allocator
 * @param first Link pointer to the first node in range.
 * @param last Link pointer to the last node in range.
 */
template<class t_type, class t_allocator>
inline void list_impl<t_type, t_allocator>::unlink_nodes(t_link_pointer first, t_link_pointer last) noexcept {
  first->m_prev->m_next = last->m_next;
  last->m_next->m_prev  = first->m_prev;
}

/**
 * @brief Default constructor.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 */
template<class t_type, class t_allocator>
inline list_impl<t_type, t_allocator>::list_impl() noexcept(
  ::portable_stl::is_nothrow_default_constructible<t_node_allocator>{}())
    : m_size_alloc_pair(0U, t_node_allocator{}) {
}

/**
 * @brief Constructor.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param alloc Given allocator.
 */
template<class t_type, class t_allocator>
inline list_impl<t_type, t_allocator>::list_impl(allocator_type const &alloc)
    : m_size_alloc_pair(0U, t_node_allocator(alloc)) {
}

/**
 * @brief Constructor.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param alloc Given node allocator.
 */
template<class t_type, class t_allocator>
inline list_impl<t_type, t_allocator>::list_impl(t_node_allocator const &alloc) : m_size_alloc_pair(0U, alloc) {
}

/**
 * @brief Constructor.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param alloc Given node allocator.
 */
template<class t_type, class t_allocator>
inline list_impl<t_type, t_allocator>::list_impl(t_node_allocator &&alloc) noexcept
    : m_size_alloc_pair(0U, ::portable_stl::move(alloc)) {
}

/**
 * @brief Destructor.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 */
template<class t_type, class t_allocator> list_impl<t_type, t_allocator>::~list_impl() {
  clear();
}

/**
 * @brief Erases all elements from the list_impl.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 */
template<class t_type, class t_allocator> void list_impl<t_type, t_allocator>::clear() noexcept {
  if (!empty()) {
    t_link_pointer first{m_end.m_next};
    t_link_pointer last{end_as_link()};
    unlink_nodes(first, last->m_prev);
    size_val() = 0;
    while (first != last) {
      t_node_pointer node_ptr{first->as_node()};
      first = first->m_next;
      delete_node(node_ptr);
    }
  }
}

/**
 * @brief Exchanges the contents of the list_impl with those of other.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param other list_impl to exchange the contents with.
 */
template<class t_type, class t_allocator> void list_impl<t_type, t_allocator>::swap(list_impl &other) noexcept {
  using ::portable_stl::swap;
  ::portable_stl::swap_allocator(node_alloc(), other.node_alloc());
  swap(size_val(), other.size_val());
  swap(m_end, other.m_end);

  if (0 == size_val()) {
    m_end.m_next = m_end.m_prev = end_as_link();
  } else {
    m_end.m_prev->m_next = m_end.m_next->m_prev = end_as_link();
  }

  if (0 == other.size_val()) {
    other.m_end.m_next = other.m_end.m_prev = other.end_as_link();
  } else {
    other.m_end.m_prev->m_next = other.m_end.m_next->m_prev = other.end_as_link();
  }
}
} // namespace portable_stl

#endif // PSTL_LIST_IMPL_H
