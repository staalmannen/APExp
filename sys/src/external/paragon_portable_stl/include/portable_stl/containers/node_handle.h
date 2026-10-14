// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="node_handle.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_NODE_HANDLE_H
#define PSTL_NODE_HANDLE_H

#include "../memory/addressof.h"
#include "../memory/allocator_traits.h"
#include "../memory/allocator_traits_rebind.h"
#include "../memory/pointer_traits.h"
#include "../memory/rebind_pointer.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../utility/general/move.h"
#include "../utility/general/swap.h"
#include "../utility/tuple/tuple.h"

namespace portable_stl {

// Specialized in rbtree & __hash_table for their t_node_type.
template<class t_node_type, class t_allocator> struct generic_container_node_destructor;

/**
 * @brief A node handle is an object that accepts ownership of a single element from an associative container or an
 * unordered associative container.
 *
 * If a node handle is not empty, then it contains an allocator that is equal to the allocator of the container when the
 * element was extracted. If a node handle is empty, it contains no allocator.
 *
 * @tparam t_node_type Node type.
 * @tparam t_allocator Allocator type.
 * @tparam t_map_or_set_specifics template type specific for set and map
 */
template<class t_node_type, class t_allocator, template<class, class> class t_map_or_set_specifics>
class basic_node_handle
    : public t_map_or_set_specifics<t_node_type, basic_node_handle<t_node_type, t_allocator, t_map_or_set_specifics>> {
  //
  template<class t_type, class t_compare, class t_allocator_typ> friend class tree;

  friend class t_map_or_set_specifics<t_node_type, basic_node_handle<t_node_type, t_allocator, t_map_or_set_specifics>>;

  /**
   * @brief Allocator traits.
   *
   */
  using t_allocator_traits = ::portable_stl::allocator_traits<t_allocator>;

  /**
   * @brief Node pointer type.
   *
   */
  using t_node_pointer_type = ::portable_stl::rebind_pointer_t<typename t_allocator_traits::void_pointer, t_node_type>;

public:
  /**
   * @brief Allocator type alias.
   *
   */
  using allocator_type = t_allocator;

private:
  /**
   * @brief Internally stored pointer to node.
   *
   */
  t_node_pointer_type m_ptr = nullptr;

  /**
   * @brief A simplified, non-copyable ::optional<allocator_type>.
   * Call release() before destruction if the allocator member is active.
   *
   */
  union Optional_alloc {
    /**
     * @brief Default constructor.
     *
     */
    Optional_alloc() {
    }

    /**
     * @brief Deleted move constructor.
     *
     */
    Optional_alloc(Optional_alloc &&) = delete;

    /**
     * @brief Deleted move assignmnet.
     *
     * @return Optional_alloc&
     */
    Optional_alloc &operator=(Optional_alloc &&) = delete;

    /**
     * @brief Constructor.
     *
     * @param alloc Given allocator.
     */
    Optional_alloc(allocator_type const &alloc) noexcept : m_opt_alloc(alloc) {
    }

    /**
     * @brief Destructor.
     *
     */
    ~Optional_alloc() {
    }

    /**
     * @brief Move assignment.
     * Precondition: m_opt_alloc is the active member of the union.
     *
     * @tparam t_alloc_traits
     * @param alloc Another allocator.
     */
    template<
      class t_alloc_traits = t_allocator_traits,
      ::portable_stl::enable_if_bool_constant_t<typename t_alloc_traits::propagate_on_container_move_assignment, void *>
      = nullptr>
    void operator=(allocator_type &&alloc) noexcept {
      m_opt_alloc = ::portable_stl::move(alloc);
    }

    /**
     * @brief Move assignment.
     *
     * @tparam t_alloc_traits
     * @param alloc Another allocator.
     */
    template<class t_alloc_traits = t_allocator_traits,
             ::portable_stl::enable_if_bool_constant_t<
               ::portable_stl::conjunction<
                 ::portable_stl::negation<typename t_alloc_traits::propagate_on_container_move_assignment>,
                 ::portable_stl::negation<typename t_alloc_traits::is_always_equal>>,
               void *>
             = nullptr>
    void operator=(allocator_type &&alloc) noexcept {
    }

    /**
     * @brief Exchanges allocators.
     * Precondition: m_opt_alloc is the active member of both unions.
     *
     * @tparam t_alloc_traits
     * @param other Another Optional_alloc object.
     */
    template<class t_alloc_traits = t_allocator_traits,
             ::portable_stl::enable_if_bool_constant_t<typename t_alloc_traits::propagate_on_container_swap, void *>
             = nullptr>
    void swap(Optional_alloc &other) noexcept {
      using ::portable_stl::swap;
      swap(m_opt_alloc, other.m_opt_alloc);
    }

    /**
     * @brief Exchanges allocators.
     *
     * @tparam t_alloc_traits
     * @param other Another Optional_alloc object.
     */
    template<
      class t_alloc_traits = t_allocator_traits,
      ::portable_stl::enable_if_bool_constant_t<
        ::portable_stl::conjunction<::portable_stl::negation<typename t_alloc_traits::propagate_on_container_swap>,
                                    ::portable_stl::negation<typename t_alloc_traits::is_always_equal>>,
        void *>
      = nullptr>
    void swap(Optional_alloc &other) noexcept {
    }

    /**
     * @brief Dereference operator.
     * Precondition: m_opt_alloc is the active member of the union.
     *
     * @return allocator_type& Allocator.
     */
    allocator_type &operator*() noexcept {
      return m_opt_alloc;
    }

    /**
     * @brief Release allocator.
     * Precondition: m_opt_alloc is the active member of the union.
     *
     * @return allocator_type
     */
    allocator_type release() noexcept {
      allocator_type tmp = ::portable_stl::move(m_opt_alloc);
      m_opt_alloc.~allocator_type();
      return tmp;
    }

    /**
     * @brief Type to represents empty allocator.
     *
     */
    struct Opt_empty {};

    /**
     * @brief Represents empty allocator.
     *
     */
    /* [[__no_unique_address__]] */ Opt_empty      m_empty;
    /**
     * @brief Optional allocator.
     *
     */
    /* [[__no_unique_address__]] */ allocator_type m_opt_alloc;
  };

  /**
   * @brief Optional allocator.
   *
   */
  Optional_alloc m_alloc;

  /**
   * @brief Destroys node stored in node handle.
   *
   */
  void destroy_node_pointer() {
    if (m_ptr != nullptr) {
      using t_node_alloc_type = typename ::portable_stl::allocator_traits_rebind<allocator_type, t_node_type>::type;
      t_node_alloc_type node_alloc(*m_alloc);
      ::portable_stl::generic_container_node_destructor<t_node_type, t_node_alloc_type>(node_alloc, true)(m_ptr);
      m_ptr = nullptr;
    }
  }

  /**
   * @brief Constructor.
   *
   * @param node_ptr Node pointer.
   * @param alloc Given allocator.
   */
  basic_node_handle(t_node_pointer_type node_ptr, allocator_type const &alloc) : m_ptr(node_ptr), m_alloc(alloc) {
  }

  /**
   * @brief Implementation of moving from other.
   *
   * @param other Another node handle.
   */
  void move_impl(basic_node_handle &&other) noexcept {
    ::new (::portable_stl::addressof(m_alloc)) allocator_type(other.m_alloc.release());
    m_ptr       = other.m_ptr;
    other.m_ptr = nullptr;
  }

  /**
   * @brief Implementation of exchanging with other.
   *
   * @param other Another node handle.
   */
  void swap_impl(basic_node_handle other) noexcept {
    if (empty()) {
      if (!other.empty()) {
        move_impl(::portable_stl::move(other));
      }
    } else if (other.empty()) {
      other.move_impl(::portable_stl::move(*this));
    } else {
      using ::portable_stl::swap;
      swap(m_ptr, other.m_ptr);
      m_alloc.swap(other.m_alloc); // swaps if POCS
    }
  }

public:
  /**
   * @brief Default constructor.
   *
   */
  basic_node_handle() = default;

  /**
   * @brief Move constructor.
   *
   * @param other Node handle to move from.
   */
  basic_node_handle(basic_node_handle &&other) noexcept : m_ptr(other.m_ptr) {
    if (m_ptr) {
      move_impl(::portable_stl::move(other));
    }
  }

  /**
   * @brief Move assignmemnt.
   *
   * @param other Another node handle to move from.
   * @return basic_node_handle& *this.
   */
  basic_node_handle &operator=(basic_node_handle &&other) {
    destroy_node_pointer();
    m_ptr = other.m_ptr;

    if (typename t_allocator_traits::propagate_on_container_move_assignment{}()) {
      m_alloc = ::portable_stl::move(other.m_alloc);
    }
    other.m_ptr = nullptr;
    return *this;
  }

  /**
   * @brief Returns the allocator associated with the node handle.
   *
   * @return allocator_type The associated allocator.
   */
  allocator_type get_allocator() const noexcept {
    return allocator_type(m_alloc.m_opt_alloc);
  }

  /**
   * @brief Bool type conversion = checks if node handle is empty.
   *
   * @return true if empty,
   * @return false otherwise.
   */
  explicit operator bool() const {
    return !empty();
  }

  /**
   * @brief Checks if node handle is empty.
   *
   * @return true if empty,
   * @return false otherwise.
   */
  bool empty() const {
    return m_ptr == nullptr;
  }

  /**
   * @brief Releases node pointer.
   * Used in ::tree.
   */
  void release_ptr() {
    m_ptr = nullptr;
  }

  /**
   * @brief Excahnges with other.
   *
   * @param other Another node handle.
   */
  void swap(basic_node_handle &other) noexcept(typename t_allocator_traits::propagate_on_container_swap{}() ||
                                               typename t_allocator_traits::is_always_equal{}()) {
    swap_impl(other);
  }

  /**
   * @brief Specializes the ::swap algorithm for basic_node_handle. Swaps the contents of lhs and rhs. Calls
   * lhs.swap(rhs).
   *
   * @param lhv Node handle whose contents to swap.
   * @param rhv Node handle whose contents to swap.
   */
  friend void swap(basic_node_handle &lhv, basic_node_handle &rhv) noexcept(noexcept(lhv.swap(rhv))) {
    lhv.swap(rhv);
  }

  /**
   * @brief Destructor.
   *
   */
  ~basic_node_handle() {
    destroy_node_pointer();
  }
};

/**
 * @brief Node handle specialization class for set.
 *
 * @tparam t_node_type Node type.
 * @tparam t_derived
 */
template<class t_node_type, class t_derived> class set_node_handle_specifics {
public:
  /**
   * @brief Value type stored in node of the container.
   *
   */
  using value_type = typename t_node_type::t_node_value_type;

  /**
   * @brief Returns reference to value in node.
   *
   * @return value_type& A reference to the value_type subobject in the container_node_type.
   */
  value_type &value() const {
    return static_cast<t_derived const *>(this)->m_ptr->get_value();
  }
};

/**
 * @brief Node handle specialization class for map.
 *
 * @tparam t_node_type
 * @tparam t_derived
 */
template<class t_node_type, class t_derived> class map_node_handle_specifics {
public:
  /**
   * @brief
   *
   */
  using key_type    = typename t_node_type::t_node_value_type::key_type;
  /**
   * @brief
   *
   */
  using mapped_type = typename t_node_type::t_node_value_type::mapped_type;

  /**
   * @brief
   *
   * @return key_type&
   */
  key_type &key() const {
    return ::portable_stl::get<0>(static_cast<t_derived const *>(this)->m_ptr->get_value().get_ref());
  }

  /**
   * @brief
   *
   * @return mapped_type&
   */
  mapped_type &mapped() const {
    return ::portable_stl::get<1>(static_cast<t_derived const *>(this)->m_ptr->get_value().get_ref());
  }
};

/**
 * @brief Alias for node handle in the set.
 *
 * @tparam t_node_type Node type.
 * @tparam t_allocator Allocator type.
 */
template<class t_node_type, class t_allocator>
using set_node_handle = basic_node_handle<t_node_type, t_allocator, set_node_handle_specifics>;

/**
 * @brief Alias for node handle in the map.
 *
 * @tparam t_node_type Node type.
 * @tparam t_allocator Allocator type.
 */
template<class t_node_type, class t_allocator>
using map_node_handle = basic_node_handle<t_node_type, t_allocator, map_node_handle_specifics>;

} // namespace portable_stl

#endif // PSTL_NODE_HANDLE_H
