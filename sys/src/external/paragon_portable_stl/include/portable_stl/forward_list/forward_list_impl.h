// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="forward_list_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FORWARD_LIST_IMPL_H
#define PSTL_FORWARD_LIST_IMPL_H

#include "../error/portable_stl_error.h"
#include "../memory/addressof.h"
#include "../memory/allocate_noexcept.h"
#include "../memory/allocator_traits.h"
#include "../memory/compressed_pair.h"
#include "../memory/construct_at.h"
#include "../memory/destroy_at.h"
#include "../memory/pointer_traits.h"
#include "../memory/rebind_alloc.h"
#include "../memory/swap_allocator.h"
#include "../memory/unique_ptr.h"
#include "../metaprogramming/type_properties/is_nothrow_default_constructible.h"
#include "../metaprogramming/type_properties/is_nothrow_move_constructible.h"
#include "../utility/expected/expected.h"
#include "../utility/expected/unexpected.h"
#include "../utility/general/swap.h"
#include "forward_list_const_iterator.h"
#include "forward_list_iterator.h"
#include "forward_list_node.h"

namespace portable_stl {

/**
 * @brief Forward list implementation class.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 */
template<class t_type, class t_allocator> class forward_list_impl {
protected:
  /**
   * @brief Value type.
   *
   */
  using value_type          = t_type;
  /**
   * @brief Allocator type.
   *
   */
  using allocator_type      = t_allocator;
  /**
   * @brief Allocator traits type.
   *
   */
  using t_alloc_traits      = ::portable_stl::allocator_traits<allocator_type>;
  /**
   * @brief Void pointer type.
   *
   */
  using void_pointer        = typename t_alloc_traits::void_pointer;
  /**
   * @brief Node type.
   *
   */
  using t_node_type         = forward_list_node<value_type, void_pointer>;
  /**
   * @brief Base node type.
   *
   */
  using t_begin_node        = t_begin_node_of<value_type, void_pointer>;
  /**
   * @brief Node allocator.
   *
   */
  using t_node_allocator    = ::portable_stl::rebind_alloc<t_alloc_traits, t_node_type>;
  /**
   * @brief Node allocator traits type.
   *
   */
  using t_node_alloc_traits = ::portable_stl::allocator_traits<t_node_allocator>;
  /**
   * @brief Node pointer type.
   *
   */
  using t_node_pointer      = typename t_node_alloc_traits::pointer;

  /**
   * @brief List iterator type.
   *
   */
  using iterator       = ::portable_stl::forward_list_iterator<t_node_pointer>;
  /**
   * @brief List constant iterator type.
   *
   */
  using const_iterator = ::portable_stl::forward_list_const_iterator<t_node_pointer>;

  /**
   * @brief Base node allocator.
   *
   */
  using t_begin_node_allocator = ::portable_stl::rebind_alloc<t_alloc_traits, t_begin_node>;
  /**
   * @brief Base node pointer type.
   *
   */
  using t_begin_node_pointer   = typename ::portable_stl::allocator_traits<t_begin_node_allocator>::pointer;

  /**
   * @brief Pair to store begin base node (before begin) and node allocator.
   *
   */
  ::portable_stl::compressed_pair<t_begin_node, t_node_allocator> m_before_begin;

  /**
   * @brief Get the before begin base node pointer.
   *
   * @return t_begin_node_pointer
   */
  t_begin_node_pointer get_before_begin() noexcept {
    return ::portable_stl::pointer_traits<t_begin_node_pointer>::pointer_to(m_before_begin.get_first());
  }

  /**
   * @brief Get the before begin base node pointer.
   *
   * @return t_begin_node_pointer
   */
  t_begin_node_pointer get_before_begin() const noexcept {
    return ::portable_stl::pointer_traits<t_begin_node_pointer>::pointer_to(
      const_cast<t_begin_node &>(m_before_begin.get_first()));
  }

  /**
   * @brief Node allocator getter.
   *
   * @return t_node_allocator& Node allocator.
   */
  t_node_allocator &node_alloc() noexcept {
    return m_before_begin.get_second();
  }

  /**
   * @brief Node allocator getter.
   *
   * @return t_node_allocator& Node allocator.
   */
  t_node_allocator const &node_alloc() const noexcept {
    return m_before_begin.get_second();
  }

  /**
   * @brief Default constructor.
   *
   */
  forward_list_impl() noexcept(::portable_stl::is_nothrow_default_constructible<t_node_allocator>{}())
      : m_before_begin(t_begin_node(), t_node_allocator()) {
  }

  /**
   * @brief Constructor
   *
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  explicit forward_list_impl(allocator_type const &alloc) : m_before_begin(t_begin_node(), t_node_allocator(alloc)) {
  }

  /**
   * @brief Constructor
   *
   * @param node_alloc Node allocator.
   */
  explicit forward_list_impl(t_node_allocator const &node_alloc) : m_before_begin(t_begin_node(), node_alloc) {
  }

public:
  /**
   * @brief Move constructor.
   *
   * @param other Another container.
   */
  forward_list_impl(forward_list_impl &&other) noexcept(is_nothrow_move_constructible<t_node_allocator>{}());

  /**
   * @brief Move constructor.
   *
   * @param other Another container.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  forward_list_impl(forward_list_impl &&other, allocator_type const &alloc);

private:
  /**
   * @brief Copy constructor.
   *
   */
  forward_list_impl(forward_list_impl const &);

  /**
   * @brief Copy assignment.
   *
   * @return forward_list_impl& this*.
   */
  forward_list_impl &operator=(forward_list_impl const &);

public:
  /**
   * @brief Destroy the forward list impl object.
   *
   */
  ~forward_list_impl();

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
   * @brief Copy assignment implementation.
   *
   * @param other Another list implementation object.
   */
  void copy_assign_alloc(forward_list_impl const &other) {
    copy_assign_alloc(other, typename t_node_alloc_traits::propagate_on_container_copy_assignment{});
  }

  /**
   * @brief Move assignment implementation.
   *
   * @param other Another list implementation object.
   */
  void move_assign_alloc(forward_list_impl &other) noexcept(
    !typename t_node_alloc_traits::propagate_on_container_move_assignment{}()
    || ::portable_stl::is_nothrow_move_assignable<t_node_allocator>{}()) {
    move_assign_alloc(other, typename t_node_alloc_traits::propagate_on_container_move_assignment{});
  }

  /**
   * @brief Create a node object.
   *
   * @tparam t_args
   * @param next Pointer to the next node.
   * @param args Arguments to create node value with.
   * @return ::portable_stl::expected<t_node_pointer, ::portable_stl::portable_stl_error> Pointer to created node.
   */
  template<class... t_args>
  ::portable_stl::expected<t_node_pointer, ::portable_stl::portable_stl_error> create_node(t_node_pointer next,
                                                                                           t_args &&...args) {
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
      ::portable_stl::construct_at(::portable_stl::addressof(*new_node_mem), next);

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

    // For the same reason as in create_node(), we use the allocator's destroy() method for the value_type, but not for
    // the node itself.
    t_node_alloc_traits::destroy(alloc, ::portable_stl::addressof(node->get_value()));

    ::portable_stl::destroy_at(::portable_stl::addressof(*node));

    t_node_alloc_traits::deallocate(alloc, node, 1);
  }

public:
  /**
   * @brief Exchanges the contents of the container with those of other.
   *
   * @param other Another list implementation object.
   */
  void swap(forward_list_impl &other) noexcept;

protected:
  /**
   * @brief Erases all elements from the container.
   *
   */
  void clear() noexcept;

private:
  /**
   * @brief Copy assignment implementation.
   *
   */
  void copy_assign_alloc(forward_list_impl const &, ::portable_stl::false_type) {
  }

  /**
   * @brief Copy assignment implementation.
   *
   * @param other Another list implementation object.
   */
  void copy_assign_alloc(forward_list_impl const &other, ::portable_stl::true_type) {
    if (node_alloc() != other.node_alloc()) {
      clear();
    }
    node_alloc() = other.node_alloc();
  }

  /**
   * @brief Move assignment implementation.
   *
   */
  void move_assign_alloc(forward_list_impl &, ::portable_stl::false_type) noexcept {
  }

  /**
   * @brief Move assignment implementation.
   *
   * @param other Another list implementation object.
   */
  void move_assign_alloc(forward_list_impl &other, ::portable_stl::true_type) noexcept(
    ::portable_stl::is_nothrow_move_assignable<t_node_allocator>{}()) {
    node_alloc() = ::portable_stl::move(other.node_alloc());
  }
};

/**
 * @brief Move constructor.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param other Another list implementation object.
 */
template<class t_type, class t_allocator>
inline forward_list_impl<t_type, t_allocator>::forward_list_impl(forward_list_impl &&other) noexcept(
  is_nothrow_move_constructible<t_node_allocator>{}())
    : m_before_begin(::portable_stl::move(other.m_before_begin)) {
  other.get_before_begin()->m_next = nullptr;
}

/**
 * @brief Move constructor.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param other Another list implementation object.
 * @param alloc Allocator to use for all memory allocations of this container.
 */
template<class t_type, class t_allocator>
inline forward_list_impl<t_type, t_allocator>::forward_list_impl(forward_list_impl &&other, allocator_type const &alloc)
    : m_before_begin(t_begin_node(), t_node_allocator(alloc)) {
  if (node_alloc() == other.node_alloc()) {
    get_before_begin()->m_next       = other.get_before_begin()->m_next;
    other.get_before_begin()->m_next = nullptr;
  }
}

/**
 * @brief List implementation object destructor.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 */
template<class t_type, class t_allocator> forward_list_impl<t_type, t_allocator>::~forward_list_impl() {
  clear();
}

/**
 * @brief Exchanges the contents of the container with those of other.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param other Another list implementation object.
 */
template<class t_type, class t_allocator>
inline void forward_list_impl<t_type, t_allocator>::swap(forward_list_impl &other) noexcept {
  ::portable_stl::memory_helper::swap_allocator_impl(
    node_alloc(), other.node_alloc(), typename t_node_alloc_traits::propagate_on_container_swap{});
  using ::portable_stl::swap;
  swap(get_before_begin()->m_next, other.get_before_begin()->m_next);
}

/**
 * @brief Erases all elements from the container.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 */
template<class t_type, class t_allocator> void forward_list_impl<t_type, t_allocator>::clear() noexcept {
  for (t_node_pointer ptr{get_before_begin()->m_next}; ptr != nullptr;) {
    t_node_pointer next = ptr->m_next;
    delete_node(ptr);
    ptr = next;
  }
  get_before_begin()->m_next = nullptr;
}

} // namespace portable_stl

#endif // PSTL_FORWARD_LIST_IMPL_H
