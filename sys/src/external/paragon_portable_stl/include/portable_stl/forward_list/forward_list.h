// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="forward_list.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FORWARD_LIST_H
#define PSTL_FORWARD_LIST_H

#include "../algorithm/lexicographical_compare.h"
#include "../algorithm/min.h"
#include "../common/numeric_limits.h"
#include "../error/portable_stl_error.h"
#include "../functional/equal_to.h"
#include "../functional/less.h"
#include "../iterator/move_iterator.h"
#include "../iterator/next.h"
#include "../iterator/prev.h"
#include "../iterator/reverse_iterator.h"
#include "../language_support/bad_alloc.h"
#include "../memory/allocator.h"
#include "../memory/allocator_traits.h"
#include "../memory/rebind_alloc.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/type_identity.h"
#include "../metaprogramming/primary_type/is_allocator.h"
#include "../metaprogramming/type_properties/is_nothrow_default_constructible.h"
#include "../metaprogramming/type_properties/is_nothrow_move_assignable.h"
#include "../metaprogramming/type_relations/is_same.h"
#include "../utility/expected/expected.h"
#include "../utility/expected/unexpected.h"
#include "../utility/general/functional/reference_wrapper.h"
#include "../utility/general/make_exception_guard.h"
#include "forward_list_impl.h"

#if defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  include "../language_support/exception/throw_on_true.h"
#else
#  include "../language_support/no_exception/throw_on_true.h"
#endif

namespace portable_stl {

/**
 * @brief forward_list is a container that supports fast insertion and removal of elements from anywhere in the
 * container. Fast random access is not supported. It is implemented as a singly-linked list. Compared to ::list this
 * container provides more space efficient storage when bidirectional iteration is not needed.
 * Adding, removing and moving the elements within the list, or across several lists, does not invalidate the iterators
 * currently referring to other elements in the list. However, an iterator or reference referring to an element is
 * invalidated when the corresponding element is removed (via erase_after) from the list.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 */
template<class t_type, class t_allocator = ::portable_stl::allocator<t_type>>
class forward_list : private forward_list_impl<t_type, t_allocator> {
  /**
   * @brief Base implementation type.
   *
   */
  using base                 = forward_list_impl<t_type, t_allocator>;
  /**
   * @brief Node allocator type.
   *
   */
  using t_node_allocator     = typename base::t_node_allocator;
  /**
   * @brief Node type.
   *
   */
  using t_node_type          = typename base::t_node_type;
  /**
   * @brief Node allocator traits type.
   *
   */
  using t_node_alloc_traits  = typename base::t_node_alloc_traits;
  /**
   * @brief Node pointer type.
   *
   */
  using t_node_pointer       = typename base::t_node_pointer;
  /**
   * @brief Base node pointer type.
   *
   */
  using t_begin_node_pointer = typename base::t_begin_node_pointer;

public:
  /**
   * @brief Value type.
   *
   */
  using value_type      = t_type;
  /**
   * @brief Allocator type.
   *
   */
  using allocator_type  = t_allocator;
  /**
   * @brief Reference type.
   *
   */
  using reference       = value_type &;
  /**
   * @brief Reference to constant type.
   *
   */
  using const_reference = value_type const &;
  /**
   * @brief Pointer type.
   *
   */
  using pointer         = typename allocator_traits<allocator_type>::pointer;
  /**
   * @brief Constant pointer type.
   *
   */
  using const_pointer   = typename allocator_traits<allocator_type>::const_pointer;
  /**
   * @brief Size type.
   *
   */
  using size_type       = typename allocator_traits<allocator_type>::size_type;
  /**
   * @brief Difference type.
   *
   */
  using difference_type = typename allocator_traits<allocator_type>::difference_type;

  /**
   * @brief Iterator type.
   *
   */
  using iterator       = typename base::iterator;
  /**
   * @brief Constant iterator type.
   *
   */
  using const_iterator = typename base::const_iterator;

  /**
   * @brief Return type of rempve/remove_if operations.
   *
   */
  using remove_return_type = size_type;

private:
  /**
   * @brief Reference wrapper to value_type. Used in expected return.
   */
  using reference_wrap       = ::portable_stl::reference_wrapper<value_type>;
  /**
   * @brief Reference wrapper to const value_type. Used in expected return.
   */
  using const_reference_wrap = ::portable_stl::reference_wrapper<value_type const>;

public:
  static_assert(::portable_stl::is_same<value_type, typename allocator_type::value_type>{}(),
                "Allocator::value_type must be same type as value_type");

  static_assert(::portable_stl::is_same<
                  allocator_type,
                  ::portable_stl::rebind_alloc<::portable_stl::allocator_traits<allocator_type>, value_type>>{}(),
                "[allocator.requirements] states that rebinding an allocator to the same type should result in the "
                "original allocator");

  static_assert(!::portable_stl::is_same<allocator_type, t_node_allocator>{}(),
                "internal allocator type must differ from user-specified "
                "type; otherwise overload resolution breaks");

  /**
   * @brief Default constructor. Constructs an empty container with a default-constructed allocator.
   *
   */
  forward_list() noexcept(::portable_stl::is_nothrow_default_constructible<t_node_allocator>{}()) {
  }

  /**
   * @brief Constructs an empty container with the given allocator alloc.
   *
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  explicit forward_list(allocator_type const &alloc);

  /**
   * @brief Constructs the container with num copies of elements with value 'value'.
   *
   * @param num The size of the container.
   * @param value The value to initialize elements of the container with.
   */
  forward_list(size_type num, value_type const &value);

  /**
   * @brief Makes the container with num copies of elements with value 'value'.
   *
   * @param num The size of the container.
   * @param value The value to initialize elements of the container with.
   * @return ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> Container.
   */
  static ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> make_forward_list(
    size_type num, value_type const &value);

  /**
   * @brief Constructs the container with num copies of elements with value 'value' using a user supplied allocator
   * alloc.
   *
   * @param num The size of the container.
   * @param value The value to initialize elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  template<class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_allocator<t_allocator>, void>>
  forward_list(size_type num, value_type const &value, allocator_type const &alloc) : base(alloc) {
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert_after(cbefore_begin(), num, value));
  }

  /**
   * @brief Makes the container with num copies of elements with value 'value' using a user supplied allocator
   * alloc.
   *
   * @param num The size of the container.
   * @param value The value to initialize elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this container.
   * @return ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> Container.
   */
  template<class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_allocator<t_allocator>, void>>
  static ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> make_forward_list(
    size_type num, value_type const &value, allocator_type const &alloc) {
    forward_list lst(alloc);
    return lst.insert_after(lst.cbefore_begin(), num, value).transform([&lst](iterator /*iter*/) {
      return ::portable_stl::move(lst);
    });
  }

  /**
   * @brief Constructs the container with num default-inserted instances of t_type. No copies are made.
   *
   * @param num The size of the container.
   */
  explicit forward_list(size_type num);

  /**
   * @brief Makes the container with num default-inserted instances of t_type. No copies are made.
   *
   * @param num The size of the container.
   * @return ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> Container.
   */
  static ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> make_forward_list(size_type num);

  /**
   * @brief Constructs the container with num default-inserted instances of t_type using a user supplied allocator
   * alloc. No copies are made.
   *
   * @param num The size of the container.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  explicit forward_list(size_type num, allocator_type const &alloc);

  /**
   * @brief Makes the container with num default-inserted instances of t_type using a user supplied allocator
   * alloc. No copies are made.
   *
   * @param num The size of the container.
   * @param alloc Allocator to use for all memory allocations of this container.
   * @return ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> Container.
   */
  static ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> make_forward_list(
    size_type num, allocator_type const &alloc);

  /**
   * @brief Constructs the container with the contents of the range [first, last). This overload participates in
   * overload resolution only if t_input_iterator satisfies LegacyInputIterator, to avoid ambiguity with the another
   * overload.
   *
   * @tparam t_input_iterator Satisfies LegacyInputIterator.
   * @param first The range [first, last) to copy the elements from.
   * @param last The range [first, last) to copy the elements from.
   */
  template<
    class t_input_iterator,
    ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>
    = nullptr>
  forward_list(t_input_iterator first, t_input_iterator last);

  /**
   * @brief Makes the container with the contents of the range [first, last). This overload participates in
   * overload resolution only if t_input_iterator satisfies LegacyInputIterator, to avoid ambiguity with the another
   * overload.
   *
   * @tparam t_input_iterator Satisfies LegacyInputIterator.
   * @param first The range [first, last) to copy the elements from.
   * @param last The range [first, last) to copy the elements from.
   * @return ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> Container.
   */
  template<
    class t_input_iterator,
    ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>
    = nullptr>
  static ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> make_forward_list(
    t_input_iterator first, t_input_iterator last);

  /**
   * @brief Constructs the container with the contents of the range [first, last) using a user supplied allocator
   * alloc. This overload participates in overload resolution only if t_input_iterator satisfies LegacyInputIterator, to
   * avoid ambiguity with the another overload.
   *
   * @tparam t_input_iterator Satisfies LegacyInputIterator.
   * @param first The range [first, last) to copy the elements from.
   * @param last The range [first, last) to copy the elements from.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  template<
    class t_input_iterator,
    ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>
    = nullptr>
  forward_list(t_input_iterator first, t_input_iterator last, allocator_type const &alloc);

  /**
   * @brief Makes the container with the contents of the range [first, last) using a user supplied allocator
   * alloc. This overload participates in overload resolution only if t_input_iterator satisfies LegacyInputIterator, to
   * avoid ambiguity with the another overload.
   *
   * @tparam t_input_iterator Satisfies LegacyInputIterator.
   * @param first The range [first, last) to copy the elements from.
   * @param last The range [first, last) to copy the elements from.
   * @param alloc Allocator to use for all memory allocations of this container.
   * @return ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> Container.
   */
  template<
    class t_input_iterator,
    ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>
    = nullptr>
  static ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> make_forward_list(
    t_input_iterator first, t_input_iterator last, allocator_type const &alloc);

  /**
   * @brief Copy constructor. Constructs the container with the copy of the contents of other.
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   */
  forward_list(forward_list const &other);

  /**
   * @brief Makes the container with the copy of the contents of other.
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   * @return ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> Container.
   */
  static ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> make_forward_list(
    forward_list const &other);

  /**
   * @brief Constructs the container with the copy of the contents of other, using alloc as the allocator.
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  forward_list(forward_list const &other, ::portable_stl::type_identity_t<allocator_type> const &alloc);

  /**
   * @brief Makes the container with the copy of the contents of other, using alloc as the allocator.
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this container.
   * @return ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> Container.
   */
  static ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> make_forward_list(
    forward_list const &other, ::portable_stl::type_identity_t<allocator_type> const &alloc);

  /**
   * @brief Move constructor. Constructs the container with the contents of other using move semantics. Allocator is
   * obtained by move-construction from the allocator belonging to other.
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   */
  forward_list(forward_list &&other) noexcept(is_nothrow_move_constructible<base>{}())
      : base(::portable_stl::move(other)) {
  }

  /**
   * @brief Allocator-extended move constructor. Using alloc as the allocator for the new container, moving the contents
   * from other; if alloc != other.get_allocator(), this results in an element-wise move.
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  forward_list(forward_list &&other, ::portable_stl::type_identity_t<allocator_type> const &alloc);

  /**
   * @brief Constructs the container with the contents of the initializer list init_list.
   *
   * @param init_list Initializer list to initialize the elements of the container with.
   */
  forward_list(std::initializer_list<value_type> init_list);

  /**
   * @brief Makes the container with the contents of the initializer list init_list.
   *
   * @param init_list Initializer list to initialize the elements of the container with.
   * @return ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> Container.
   */
  static ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> make_forward_list(
    std::initializer_list<value_type> init_list);

  /**
   * @brief Constructs the container with the contents of the initializer list init_list, using alloc as the allocator.
   *
   * @param init_list Initializer list to initialize the elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  forward_list(std::initializer_list<value_type> init_list, allocator_type const &alloc);

  /**
   * @brief Makes the container with the contents of the initializer list init_list, using alloc as the allocator.
   *
   * @param init_list Initializer list to initialize the elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this container.
   * @return ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> Container.
   */
  static ::portable_stl::expected<forward_list, ::portable_stl::portable_stl_error> make_forward_list(
    std::initializer_list<value_type> init_list, allocator_type const &alloc);

  // ~forward_list() = default;

  /**
   * @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
   *
   * @param other Another container to use as data source.
   * @return forward_list& *this.
   */
  forward_list &operator=(forward_list const &other);

  /**
   * @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in
   * other is moved from other into this container). other is in a valid but unspecified state afterwards.
   *
   * @param other Another container to use as data source.
   * @return forward_list& *this.
   */
  forward_list &operator=(forward_list &&other) noexcept(
    typename t_node_alloc_traits::propagate_on_container_move_assignment{}()
    && ::portable_stl::is_nothrow_move_assignable<allocator_type>{}());

  /**
   * @brief Replaces the contents with those identified by initializer list init_list.
   *
   * @param init_list Initializer list to use as data source.
   * @return forward_list& *this.
   */
  forward_list &operator=(std::initializer_list<value_type> init_list);

  /**
   * @brief Replaces the contents of the container with num copies of value 'value'.
   *
   * @param num The new size of the container.
   * @param value The value to initialize elements of the container with.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error> Result of operation.
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> assign(size_type num, value_type const &value);

  /**
   * @brief Replaces the contents of the container with copies of those in the range [first, last). The behavior is
   * undefined if either argument is an iterator into *this.
   *
   * @tparam t_input_iterator Satisfies LegacyInputIterator.
   * @param first The range [first, last) to copy the elements from.
   * @param last The range [first, last) to copy the elements from.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error> Result of operation.
   */
  template<
    class t_input_iterator,
    ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>
    = nullptr>
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> assign(t_input_iterator first,
                                                                            t_input_iterator last);

  /**
   * @brief Replaces the contents of the container with the elements from the initializer list init_list.
   *
   * @param init_list Initializer list to copy the values from.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error> Result of operation.
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> assign(
    std::initializer_list<value_type> init_list);

  /**
   * @brief Returns the allocator associated with the container.
   *
   * @return allocator_type The associated allocator.
   */
  allocator_type get_allocator() const noexcept {
    return allocator_type(base::node_alloc());
  }

  /**
   * @brief Returns an iterator to the first element of the forward_list.
   * If the forward_list is empty, the returned iterator will be equal to end().
   *
   * @return iterator Iterator to the first element.
   */
  iterator begin() noexcept {
    return iterator(base::get_before_begin()->m_next);
  }

  /**
   * @brief Returns a constant iterator to the first element of the forward_list.
   * If the forward_list is empty, the returned iterator will be equal to end().
   *
   * @return const_iterator Constant iterator to the first element.
   */
  const_iterator begin() const noexcept {
    return const_iterator(base::get_before_begin()->m_next);
  }

  /**
   * @brief Returns an iterator to the element following the last element of the forward_list.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   *
   * @return iterator Iterator to the element following the last element.
   */
  iterator end() noexcept {
    return iterator(nullptr);
  }

  /**
   * @brief Returns a constant iterator to the element following the last element of the forward_list.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   *
   * @return const_iterator Constant iterator to the element following the last element.
   */
  const_iterator end() const noexcept {
    return const_iterator(nullptr);
  }

  /**
   * @brief Returns a constant iterator to the first element of the forward_list.
   * If the forward_list is empty, the returned iterator will be equal to end().
   *
   * @return const_iterator Constant iterator to the first element.
   */
  const_iterator cbegin() const noexcept {
    return const_iterator(base::get_before_begin()->m_next);
  }

  /**
   * @brief Returns a constant iterator to the element following the last element of the forward_list.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   *
   * @return const_iterator Constant iterator to the element following the last element.
   */
  const_iterator cend() const noexcept {
    return const_iterator(nullptr);
  }

  /**
   * @brief Returns an iterator to the element before the first element of the container. This element acts as a
   * placeholder, attempting to access it results in undefined behavior. The only usage cases are in functions
   * insert_after(), emplace_after(), erase_after(), splice_after() and the increment operator: incrementing the
   * before-begin iterator gives exactly the same iterator as obtained from begin().
   *
   * @return iterator Iterator to the element before the first element.
   */
  iterator before_begin() noexcept {
    return iterator(base::get_before_begin());
  }

  /**
   * @brief Returns a constant iterator to the element before the first element of the container. This element acts as a
   * placeholder, attempting to access it results in undefined behavior. The only usage cases are in functions
   * insert_after(), emplace_after(), erase_after(), splice_after() and the increment operator: incrementing the
   * before-begin iterator gives exactly the same iterator as obtained from cbegin().
   *
   * @return const_iterator Constant iterator to the element before the first element.
   */
  const_iterator before_begin() const noexcept {
    return const_iterator(base::get_before_begin());
  }

  /**
   * @brief Returns a constant iterator to the element before the first element of the container. This element acts as a
   * placeholder, attempting to access it results in undefined behavior. The only usage cases are in functions
   * insert_after(), emplace_after(), erase_after(), splice_after() and the increment operator: incrementing the
   * before-begin iterator gives exactly the same iterator as obtained from cbegin().
   *
   * @return const_iterator Constant iterator to the element before the first element.
   */
  const_iterator cbefore_begin() const noexcept {
    return const_iterator(base::get_before_begin());
  }

  /**
   * @brief Checks if the container has no elements, i.e. whether begin() == end().
   *
   * @return true if the container is empty,
   * @return false otherwise.
   */
  bool empty() const noexcept {
    return nullptr == base::get_before_begin()->m_next;
  }

  /**
   * @brief Returns the maximum number of elements the container is able to hold due to system or library implementation
   * limitations, i.e. ::distance(begin(), end()) for the largest container.
   *
   * @return Maximum number of elements.
   */
  size_type max_size() const noexcept {
    return ::portable_stl::min<size_type>(t_node_alloc_traits::max_size(base::node_alloc()),
                                          ::portable_stl::numeric_limits<difference_type>::max());
  }

  /**
   * @brief Returns a reference to the first element in the container.
   * Calling front on an empty container causes undefined behavior.
   *
   * @return reference Reference to the first element.
   */
  reference front() {
    return base::get_before_begin()->m_next->get_value();
  }

  /**
   * @brief Returns a reference to the first element in the container.
   * Calling front on an empty container causes undefined behavior.
   *
   * @return const_reference Reference to the first element.
   */
  const_reference front() const {
    return base::get_before_begin()->m_next->get_value();
  }

  /**
   * @brief Inserts a new element to the beginning of the container. The element is constructed through
   * ::allocator_traits::construct, which typically uses placement-new to construct the element in-place at the
   * location provided by the container. The arguments args... are forwarded to the constructor as
   * ::forward<Args>(args)....
   *
   * @tparam t_args
   * @param args Arguments to forward to the constructor of the element.
   * @return ::portable_stl::expected<reference_wrap, ::portable_stl::portable_stl_error> A reference to the inserted
   * element.
   */
  template<class... t_args>
  ::portable_stl::expected<reference_wrap, ::portable_stl::portable_stl_error> emplace_front(t_args &&...args);

  /**
   * @brief Prepends the given element value to the beginning of the container.
   *
   * @param value The value of the element to prepend.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error> Result of operation.
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> push_front(value_type const &value);

  /**
   * @brief Prepends the given element value to the beginning of the container.
   *
   * @param value The value of the element to prepend.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error> Result of operation.
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> push_front(value_type &&value);

  /**
   * @brief Removes the first element of the container. If there are no elements in the container, the behavior is
   * undefined.
   *
   */
  void pop_front();

  /**
   * @brief Inserts a new element into a position after the specified position in the container. The element is
   * constructed in-place, i.e. no copy or move operations are performed. The constructor of the element is called with
   * exactly the same arguments, as supplied to the function.
   * @tparam t_args
   * @param pos iterator after which the new element will be constructed.
   * @param args arguments to forward to the constructor of the element.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> Iterator to the new element.
   */
  template<class... t_args>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> emplace_after(const_iterator pos,
                                                                                       t_args &&...args);

  /**
   * @brief Inserts value after the element pointed to by pos in the container.
   *
   * @param pos Iterator after which the content will be inserted.
   * @param value Element value to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> Iterator to the inserted element.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert_after(const_iterator    pos,
                                                                                      value_type const &value);

  /**
   * @brief Inserts value after the element pointed to by pos in the container.
   *
   * @param pos Iterator after which the content will be inserted.
   * @param value Element value to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> Iterator to the inserted element.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert_after(const_iterator pos,
                                                                                      value_type   &&value);

  /**
   * @brief Inserts num copies of the value after the element pointed to by pos in the container.
   *
   * @param pos Iterator after which the content will be inserted.
   * @param num Number of copies to insert.
   * @param value Element value to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> Iterator to the last element
   * inserted, or pos if count == 0.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert_after(
    const_iterator pos, size_type num, value_type const &value);

  /**
   * @brief Inserts elements from range [first, last) after the element pointed to by pos in the container. The behavior
   * is undefined if first and last are iterators into *this.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param pos Iterator after which the content will be inserted.
   * @param first The range [first, last) to insert.
   * @param last The range [first, last) to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> Iterator to the last element
   * inserted, or pos if first == last.
   */
  template<
    class t_input_iterator,
    ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>
    = nullptr>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert_after(
    const_iterator pos, t_input_iterator first, t_input_iterator last);

  /**
   * @brief Inserts elements from initializer list init_list in the container.
   *
   * @param pos Iterator after which the content will be inserted.
   * @param init_list Initializer list to insert the values from.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> Iterator to the last element
   * inserted, or pos if init_list is empty.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert_after(
    const_iterator pos, std::initializer_list<value_type> init_list) {
    return insert_after(pos, init_list.begin(), init_list.end());
  }

  /**
   * @brief Removes the element following pos from the container.
   *
   * @param pos Iterator to the element preceding the element to remove.
   * @return iterator Iterator to the element following the erased one, or end() if no such element exists.
   */
  iterator erase_after(const_iterator pos);

  /**
   * @brief Removes the elements following first until last from the container.
   *
   * @param first The range [first, last) to remove.
   * @param last The range [first, last) to remove.
   * @return iterator last.
   */
  iterator erase_after(const_iterator first, const_iterator last);

  /**
   * @brief Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap
   * operations on individual elements.
   *
   * @param other Container to exchange the contents with.
   */
  void swap(forward_list &other) noexcept {
    base::swap(other);
  }

  /**
   * @brief Resizes the container to contain num elements, does nothing if num == ::distance(begin(), end())
   * (i.e. if num is equal to the current size).
   * If the current size is greater than num, the container is reduced to its first num elements.
   * If the current size is less than num, then additional default-inserted elements are appended.
   *
   * @param num New size of the container.
   * @return true if successful,
   * @return false otherwise.
   */
  bool resize(size_type num);

  /**
   * @brief Resizes the container to contain num elements, does nothing if num == ::distance(begin(), end())
   * (i.e. if num is equal to the current size).
   * If the current size is greater than num, the container is reduced to its first num elements.
   * If the current size is less than num, then additional copies of value are appended.
   *
   * @param num New size of the container
   * @param value The value to initialize the new elements with.
   * @return true if successful,
   * @return false otherwise.
   */
  bool resize(size_type num, value_type const &value);

  /**
   * @brief Erases all elements from the container.
   *
   */
  void clear() noexcept {
    base::clear();
  }

  /**
   * @brief Moves all elements from another forward_list other into *this. The elements are inserted after the element
   * pointed to by pos. The container other becomes empty after the operation.
   *
   * @param pos Element after which the content will be inserted.
   * @param other_list Another container to move the content from.
   */
  void splice_after(const_iterator pos, forward_list &other_list);

  /**
   * @brief Moves all elements from another forward_list other into *this. The elements are inserted after the element
   * pointed to by pos. The container other becomes empty after the operation.
   *
   * @param pos Element after which the content will be inserted.
   * @param other_list Another container to move the content from.
   */
  void splice_after(const_iterator pos, forward_list &&other_list);

  /**
   * @brief Moves the element pointed to by the iterator following iter from another forward_list other into *this. The
   * elements are inserted after the element pointed to by pos. Has no effect if pos == iter or if pos == ++iter.
   *
   * @param pos Element after which the content will be inserted.
   * @param other_list Another container to move the content from.
   * @param iter Iterator preceding the iterator to the element to move from other to *this.
   */
  void splice_after(const_iterator pos, forward_list &other_list, const_iterator iter);

  /**
   * @brief Moves the element pointed to by the iterator following iter from another forward_list other into *this. The
   * elements are inserted after the element pointed to by pos. Has no effect if pos == iter or if pos == ++iter.
   *
   * @param pos Element after which the content will be inserted.
   * @param other_list Another container to move the content from.
   * @param iter Iterator preceding the iterator to the element to move from other to *this.
   */
  void splice_after(const_iterator pos, forward_list &&other_list, const_iterator iter);

  /**
   * @brief Moves the elements in the range (first, last) from another forward_list other into *this. The elements are
   * inserted after the element pointed to by pos. The element pointed-to by first is not moved.
   *
   * @param pos Element after which the content will be inserted.
   * @param other_list Another container to move the content from.
   * @param first The range [first, last) to move from other to *this.
   * @param last The range [first, last) to move from other to *this.
   */
  void splice_after(const_iterator pos, forward_list &other_list, const_iterator first, const_iterator last);

  /**
   * @brief Moves the elements in the range (first, last) from another forward_list other into *this. The elements are
   * inserted after the element pointed to by pos. The element pointed-to by first is not moved.
   *
   * @param pos Element after which the content will be inserted.
   * @param other_list Another container to move the content from.
   * @param first The range [first, last) to move from other to *this.
   * @param last The range [first, last) to move from other to *this.
   */
  void splice_after(const_iterator pos, forward_list &&other_list, const_iterator first, const_iterator last);

  /**
   * @brief Removes all elements that are equal to value (using operator==). Invalidates only the iterators and
   * references to the removed elements.
   *
   * @param value Value of the elements to remove.
   * @return remove_return_type The number of elements removed.
   */
  remove_return_type remove(value_type const &value);

  /**
   * @brief Removes all elements which predicate pred returns true. Invalidates only the iterators and references to the
   * removed elements.
   *
   * @tparam t_pred Must meet the requirements of Predicate.
   * @param pred Unary predicate which returns ​true if the element should be removed.
   * @return remove_return_type The number of elements removed.
   */
  template<class t_pred> remove_return_type remove_if(t_pred pred);

  /**
   * @brief Removes all consecutive duplicate elements from the container. Only the first element in each group of equal
   * elements is left. Invalidates only the iterators and references to the removed elements. Uses operator== to compare
   * the elements.
   *
   * @return remove_return_type The number of elements removed.
   */
  remove_return_type unique() {
    return unique(::portable_stl::equal_to<value_type>());
  }

  /**
   * @brief Removes all consecutive duplicate elements from the container. Only the first element in each group of equal
   * elements is left. Invalidates only the iterators and references to the removed elements. Uses pred to compare the
   * elements.
   *
   * @tparam t_binary_pred Must meet the requirements of BinaryPredicate.
   * @param binary_pred Binary predicate which returns ​true if the elements should be treated as equal.
   * @return remove_return_type The number of elements removed.
   */
  template<class t_binary_pred> remove_return_type unique(t_binary_pred binary_pred);

  /**
   * @brief The function does nothing if other refers to the same object as *this.
   * Otherwise, merges other into *this. Both lists should be sorted. No elements are copied, and the container other
   * becomes empty after the merge. This operation is stable: for equivalent elements in the two lists, the elements
   * from *this always precede the elements from other, and the order of equivalent elements of *this and other does not
   * change.
   * Elements are compared using ::less<t_type>().
   *
   * @param other_list Another container to merge.
   */
  void merge(forward_list &other_list) {
    merge(other_list, ::portable_stl::less<>());
  }

  /**
   * @brief The function does nothing if other refers to the same object as *this.
   * Otherwise, merges other into *this. Both lists should be sorted. No elements are copied, and the container other
   * becomes empty after the merge. This operation is stable: for equivalent elements in the two lists, the elements
   * from *this always precede the elements from other, and the order of equivalent elements of *this and other does not
   * change.
   * Elements are compared using ::less<t_type>().
   *
   * @param other_list Another container to merge.
   */
  void merge(forward_list &&other_list) {
    merge(other_list, ::portable_stl::less<>());
  }

  /**
   * @brief The function does nothing if other refers to the same object as *this.
   * Otherwise, merges other into *this. Both lists should be sorted. No elements are copied, and the container other
   * becomes empty after the merge. This operation is stable: for equivalent elements in the two lists, the elements
   * from *this always precede the elements from other, and the order of equivalent elements of *this and other does not
   * change.
   * Elements are compared using comp.
   *
   * @tparam t_compare Must meet the requirements of Compare.
   * @param other_list Another container to merge.
   * @param comp Comparison function object (i.e. an object that satisfies the requirements of Compare) which returns
   * ​true if the first argument is less than (i.e. is ordered before) the second. The signature of the comparison
   * function should be equivalent to the following: bool cmp(const Type1& a, const Type2& b);
   */
  template<class t_compare> void merge(forward_list &other_list, t_compare comp);

  /**
   * @brief The function does nothing if other refers to the same object as *this.
   * Otherwise, merges other into *this. Both lists should be sorted. No elements are copied, and the container other
   * becomes empty after the merge. This operation is stable: for equivalent elements in the two lists, the elements
   * from *this always precede the elements from other, and the order of equivalent elements of *this and other does not
   * change.
   * Elements are compared using comp.
   *
   * @tparam t_compare Must meet the requirements of Compare.
   * @param other_list Another container to merge.
   * @param comp Comparison function object (i.e. an object that satisfies the requirements of Compare) which returns
   * ​true if the first argument is less than (i.e. is ordered before) the second. The signature of the comparison
   * function should be equivalent to the following: bool cmp(const Type1& a, const Type2& b);
   */
  template<class t_compare> void merge(forward_list &&other_list, t_compare comp) {
    merge(other_list, ::portable_stl::move(comp));
  }

  /**
   * @brief Sorts the elements and preserves the order of equivalent elements. No references or iterators become
   * invalidated.
   * Elements are compared using operator<.
   *
   */
  void sort() {
    sort(::portable_stl::less<>());
  }

  /**
   * @brief Sorts the elements and preserves the order of equivalent elements. No references or iterators become
   * invalidated.
   * Elements are compared using comp.
   *
   * @tparam t_compare Must meet the requirements of Compare.
   * @param comp Comparison function object (i.e. an object that satisfies the requirements of Compare) which returns
   * ​true if the first argument is less than (i.e. is ordered before) the second. The signature of the comparison
   * function should be equivalent to the following: bool cmp(const Type1& a, const Type2& b);
   */
  template<class t_compare> void sort(t_compare comp);

  /**
   * @brief Reverses the order of the elements in the container.
   * No references or iterators become invalidated.
   *
   */
  void reverse() noexcept;

private:
  void move_assign_impl(forward_list &other_list,
                        true_type) noexcept(::portable_stl::is_nothrow_move_assignable<allocator_type>{}());
  void move_assign_impl(forward_list &other_list, false_type);

  template<class t_iterator, class t_sentinel>
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> assign_with_sentinel(t_iterator first,
                                                                                          t_sentinel last);

  template<class t_input_iterator, class t_sentinel>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert_after_with_sentinel(
    const_iterator pos, t_input_iterator first, t_sentinel last);

  template<class t_compare>
  static t_node_pointer merge_impl(t_node_pointer first1, t_node_pointer first2, t_compare &comp);

  template<class t_compare> static t_node_pointer sort_impl(t_node_pointer first, size_type list_size, t_compare &comp);
};

// [constructors]

/**
 * @brief Constructs an empty container with the given allocator alloc.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param alloc Allocator to use for all memory allocations of this container.
 */
template<class t_type, class t_allocator>
inline forward_list<t_type, t_allocator>::forward_list(allocator_type const &alloc) : base(alloc) {
}

/**
 * @brief Constructs the container with num copies of elements with value 'value'.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param num The size of the container.
 * @param value The value to initialize elements of the container with.
 */
template<class t_type, class t_allocator>
forward_list<t_type, t_allocator>::forward_list(size_type num, value_type const &value) {
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert_after(cbefore_begin(), num, value));
}

/**
 * @brief Makes the container with num copies of elements with value 'value'.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param num The size of the container.
 * @param value The value to initialize elements of the container with.
 * @return ::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error> Container.
 */
template<class t_type, class t_allocator>
::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  forward_list<t_type, t_allocator>::make_forward_list(size_type num, value_type const &value) {
  forward_list lst;
  return lst.insert_after(lst.cbefore_begin(), num, value).transform([&lst](iterator /*iter*/) {
    return ::portable_stl::move(lst);
  });
}

/**
 * @brief Constructs the container with num default-inserted instances of t_type. No copies are made.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param num The size of the container.
 */
template<class t_type, class t_allocator> forward_list<t_type, t_allocator>::forward_list(size_type num) {
  if (num > 0) {
    for (t_begin_node_pointer ptr = base::get_before_begin(); num > 0; --num, ptr = ptr->next_as_begin()) {
      auto result = this->create_node(/* next = */ nullptr);
      ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!result);
      ptr->m_next = ::portable_stl::move(result.value());
    }
  }
}

/**
 * @brief Makes the container with num default-inserted instances of t_type. No copies are made.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param num The size of the container.
 * @return ::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error> Container.
 */
template<class t_type, class t_allocator>
::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  forward_list<t_type, t_allocator>::make_forward_list(size_type num) {
  forward_list lst;
  return lst.insert_after(lst.cbefore_begin(), num, value_type()).transform([&lst](iterator /*iter*/) {
    return ::portable_stl::move(lst);
  });
}

/**
 * @brief Constructs the container with num default-inserted instances of t_type using a user supplied allocator
 * alloc. No copies are made.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param num The size of the container.
 * @param alloc Allocator to use for all memory allocations of this container.
 */
template<class t_type, class t_allocator>
forward_list<t_type, t_allocator>::forward_list(size_type num, allocator_type const &alloc) : base(alloc) {
  if (num > 0) {
    for (t_begin_node_pointer ptr = base::get_before_begin(); num > 0; --num, ptr = ptr->next_as_begin()) {
      auto result = this->create_node(/* next = */ nullptr);
      ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!result);
      ptr->m_next = ::portable_stl::move(result.value());
    }
  }
}

/**
 * @brief Makes the container with num default-inserted instances of t_type using a user supplied allocator
 * alloc. No copies are made.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param num The size of the container.
 * @param alloc Allocator to use for all memory allocations of this container.
 * @return ::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error> Container.
 */
template<class t_type, class t_allocator>
::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  forward_list<t_type, t_allocator>::make_forward_list(size_type num, allocator_type const &alloc) {
  forward_list lst(alloc);
  return lst.insert_after(lst.cbefore_begin(), num, value_type()).transform([&lst](iterator /*iter*/) {
    return ::portable_stl::move(lst);
  });
}

/**
 * @brief Constructs the container with the contents of the range [first, last). This overload participates in
 * overload resolution only if t_input_iterator satisfies LegacyInputIterator, to avoid ambiguity with the another
 * overload.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @tparam t_input_iterator Satisfies LegacyInputIterator.
 * @param first The range [first, last) to copy the elements from.
 * @param last The range [first, last) to copy the elements from.
 */
template<class t_type, class t_allocator>
template<
  class t_input_iterator,
  ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>>
forward_list<t_type, t_allocator>::forward_list(t_input_iterator first, t_input_iterator last) {
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert_after(cbefore_begin(), first, last));
}

/**
 * @brief Makes the container with the contents of the range [first, last). This overload participates in
 * overload resolution only if t_input_iterator satisfies LegacyInputIterator, to avoid ambiguity with the another
 * overload.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @tparam t_input_iterator Satisfies LegacyInputIterator.
 * @param first The range [first, last) to copy the elements from.
 * @param last The range [first, last) to copy the elements from.
 * @return ::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error> Container.
 */
template<class t_type, class t_allocator>
template<
  class t_input_iterator,
  ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>>
::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  forward_list<t_type, t_allocator>::make_forward_list(t_input_iterator first, t_input_iterator last) {
  forward_list lst;
  return lst.insert_after(lst.cbefore_begin(), first, last).transform([&lst](iterator /*iter*/) {
    return ::portable_stl::move(lst);
  });
}

/**
 * @brief Constructs the container with the contents of the range [first, last) using a user supplied allocator
 * alloc. This overload participates in overload resolution only if t_input_iterator satisfies LegacyInputIterator, to
 * avoid ambiguity with the another overload.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @tparam t_input_iterator Satisfies LegacyInputIterator.
 * @param first The range [first, last) to copy the elements from.
 * @param last The range [first, last) to copy the elements from.
 * @param alloc Allocator to use for all memory allocations of this container.
 */
template<class t_type, class t_allocator>
template<
  class t_input_iterator,
  ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>>
forward_list<t_type, t_allocator>::forward_list(
  t_input_iterator first, t_input_iterator last, allocator_type const &alloc)
    : base(alloc) {
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert_after(cbefore_begin(), first, last));
}

/**
 * @brief Makes the container with the contents of the range [first, last) using a user supplied allocator
 * alloc. This overload participates in overload resolution only if t_input_iterator satisfies LegacyInputIterator, to
 * avoid ambiguity with the another overload.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @tparam t_input_iterator Satisfies LegacyInputIterator.
 * @param first The range [first, last) to copy the elements from.
 * @param last The range [first, last) to copy the elements from.
 * @param alloc Allocator to use for all memory allocations of this container.
 * @return ::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error> Container.
 */
template<class t_type, class t_allocator>
template<
  class t_input_iterator,
  ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>>
::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  forward_list<t_type, t_allocator>::make_forward_list(
    t_input_iterator first, t_input_iterator last, allocator_type const &alloc) {
  forward_list lst(alloc);
  return lst.insert_after(lst.cbefore_begin(), first, last).transform([&lst](iterator /*iter*/) {
    return ::portable_stl::move(lst);
  });
}

/**
 * @brief Copy constructor. Constructs the container with the copy of the contents of other.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param other Another container to be used as source to initialize the elements of the container with.
 */
template<class t_type, class t_allocator>
forward_list<t_type, t_allocator>::forward_list(forward_list const &other)
    : base(t_node_alloc_traits::select_on_container_copy_construction(other.node_alloc())) {
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(
    !insert_after(cbefore_begin(), other.begin(), other.end()));
}

/**
 * @brief Makes the container with the copy of the contents of other.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param other Another container to be used as source to initialize the elements of the container with.
 * @return ::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error> Container.
 */
template<class t_type, class t_allocator>
::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  forward_list<t_type, t_allocator>::make_forward_list(forward_list const &other) {
  forward_list lst(t_node_alloc_traits::select_on_container_copy_construction(other.node_alloc()));
  return lst.insert_after(lst.cbefore_begin(), other.begin(), other.end()).transform([&lst](iterator /*iter*/) {
    return ::portable_stl::move(lst);
  });
}

/**
 * @brief Constructs the container with the copy of the contents of other, using alloc as the allocator.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param other Another container to be used as source to initialize the elements of the container with.
 * @param alloc Allocator to use for all memory allocations of this container.
 */
template<class t_type, class t_allocator>
forward_list<t_type, t_allocator>::forward_list(forward_list const                                    &other,
                                                ::portable_stl::type_identity_t<allocator_type> const &alloc)
    : base(alloc) {
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(
    !insert_after(cbefore_begin(), other.begin(), other.end()));
}

/**
 * @brief Makes the container with the copy of the contents of other, using alloc as the allocator.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param other Another container to be used as source to initialize the elements of the container with.
 * @param alloc Allocator to use for all memory allocations of this container.
 * @return ::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error> Container.
 */
template<class t_type, class t_allocator>
::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  forward_list<t_type, t_allocator>::make_forward_list(forward_list const                                    &other,
                                                       ::portable_stl::type_identity_t<allocator_type> const &alloc) {
  forward_list lst(alloc);
  return lst.insert_after(lst.cbefore_begin(), other.begin(), other.end()).transform([&lst](iterator /*iter*/) {
    return ::portable_stl::move(lst);
  });
}

/**
 * @brief Allocator-extended move constructor. Using alloc as the allocator for the new container, moving the contents
 * from other; if alloc != other.get_allocator(), this results in an element-wise move.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param other Another container to be used as source to initialize the elements of the container with.
 * @param alloc Allocator to use for all memory allocations of this container.
 */
template<class t_type, class t_allocator>
forward_list<t_type, t_allocator>::forward_list(forward_list                                         &&other,
                                                ::portable_stl::type_identity_t<allocator_type> const &alloc)
    : base(::portable_stl::move(other), alloc) {
  if (base::node_alloc() != other.node_alloc()) {
    using move_iter = ::portable_stl::move_iterator<iterator>;
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(
      !insert_after(cbefore_begin(), move_iter(other.begin()), move_iter(other.end())));
  }
}

/**
 * @brief Constructs the container with the contents of the initializer list init_list.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param init_list Initializer list to initialize the elements of the container with.
 */
template<class t_type, class t_allocator>
forward_list<t_type, t_allocator>::forward_list(std::initializer_list<value_type> init_list) {
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(
    !insert_after(cbefore_begin(), init_list.begin(), init_list.end()));
}

/**
 * @brief Makes the container with the contents of the initializer list init_list.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param init_list Initializer list to initialize the elements of the container with.
 * @return ::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error> Container.
 */
template<class t_type, class t_allocator>
::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  forward_list<t_type, t_allocator>::make_forward_list(std::initializer_list<value_type> init_list) {
  forward_list lst;
  return lst.insert_after(lst.cbefore_begin(), init_list.begin(), init_list.end()).transform([&lst](iterator /*iter*/) {
    return ::portable_stl::move(lst);
  });
}

/**
 * @brief Constructs the container with the contents of the initializer list init_list, using alloc as the allocator.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param init_list Initializer list to initialize the elements of the container with.
 * @param alloc Allocator to use for all memory allocations of this container.
 */
template<class t_type, class t_allocator>
forward_list<t_type, t_allocator>::forward_list(std::initializer_list<value_type> init_list,
                                                allocator_type const             &alloc)
    : base(alloc) {
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(
    !insert_after(cbefore_begin(), init_list.begin(), init_list.end()));
}

/**
 * @brief Makes the container with the contents of the initializer list init_list, using alloc as the allocator.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param init_list Initializer list to initialize the elements of the container with.
 * @param alloc Allocator to use for all memory allocations of this container.
 * @return ::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error> Container.
 */
template<class t_type, class t_allocator>
::portable_stl::expected<forward_list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  forward_list<t_type, t_allocator>::make_forward_list(std::initializer_list<value_type> init_list,
                                                       allocator_type const             &alloc) {
  forward_list lst(alloc);
  return lst.insert_after(lst.cbefore_begin(), init_list.begin(), init_list.end()).transform([&lst](iterator /*iter*/) {
    return ::portable_stl::move(lst);
  });
}

// [assign]

/**
 * @brief Replaces the contents of the container with num copies of value 'value'.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param num The new size of the container.
 * @param value The value to initialize elements of the container with.
 * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error> Result of operation.
 */
template<class t_type, class t_allocator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> forward_list<t_type, t_allocator>::assign(
  size_type num, value_type const &value) {
  iterator iter{before_begin()};
  iterator iter_next{::portable_stl::next(iter)};
  iterator iter_end{end()};
  for (; iter_next != iter_end && num > 0; --num, ++iter, ++iter_next) {
    *iter_next = value;
  }
  if (iter_next == iter_end) {
    auto result = insert_after(iter, num, value);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
  } else {
    erase_after(iter, iter_end);
  }

  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

/**
 * @brief Replaces the contents of the container with copies of those in the range [first, last). The behavior is
 * undefined if either argument is an iterator into *this.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @tparam t_iterator
 * @tparam t_sentinel
 * @param first The range [first, last) to copy the elements from.
 * @param last The range [first, last) to copy the elements from.
 * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>
 */
template<class t_type, class t_allocator>
template<class t_iterator, class t_sentinel>
::portable_stl::expected<void, ::portable_stl::portable_stl_error>
  forward_list<t_type, t_allocator>::assign_with_sentinel(t_iterator first, t_sentinel last) {
  iterator       iter{before_begin()};
  iterator       iter_next{::portable_stl::next(iter)};
  iterator const iter_end{end()};

  while ((iter_next != iter_end) && (first != last)) {
    *iter_next = *first;
    ++iter;
    ++iter_next;
    ++first;
  }
  if (iter_end == iter_next) {
    auto result = insert_after_with_sentinel(iter, ::portable_stl::move(first), ::portable_stl::move(last));
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
  } else {
    erase_after(iter, iter_end);
  }

  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

/**
 * @brief Replaces the contents of the container with copies of those in the range [first, last). The behavior is
 * undefined if either argument is an iterator into *this.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @tparam t_input_iterator Satisfies LegacyInputIterator.
 * @param first The range [first, last) to copy the elements from.
 * @param last The range [first, last) to copy the elements from.
 * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error> Result of operation.
 */
template<class t_type, class t_allocator>
template<
  class t_input_iterator,
  ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> forward_list<t_type, t_allocator>::assign(
  t_input_iterator first, t_input_iterator last) {
  return assign_with_sentinel(first, last);
}

/**
 * @brief Replaces the contents of the container with the elements from the initializer list init_list.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param init_list Initializer list to copy the values from.
 * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error> Result of operation.
 */
template<class t_type, class t_allocator>
inline ::portable_stl::expected<void, ::portable_stl::portable_stl_error> forward_list<t_type, t_allocator>::assign(
  std::initializer_list<value_type> init_list) {
  return assign(init_list.begin(), init_list.end());
}

// [operator=]

/**
 * @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param other Another container to use as data source.
 * @return forward_list<t_type, t_allocator>& *this.
 */
template<class t_type, class t_allocator>
forward_list<t_type, t_allocator> &forward_list<t_type, t_allocator>::operator=(forward_list const &other) {
  if (this != ::portable_stl::addressof(other)) {
    base::copy_assign_alloc(other);
    assign(other.begin(), other.end());
  }
  return *this;
}

template<class t_type, class t_allocator>
void forward_list<t_type, t_allocator>::move_assign_impl(forward_list &other_list, true_type) noexcept(
  ::portable_stl::is_nothrow_move_assignable<allocator_type>{}()) {
  clear();
  base::move_assign_alloc(other_list);
  base::get_before_begin()->m_next      = other_list.get_before_begin()->m_next;
  other_list.get_before_begin()->m_next = nullptr;
}

template<class t_type, class t_allocator>
void forward_list<t_type, t_allocator>::move_assign_impl(forward_list &other_list, false_type) {
  if (base::node_alloc() == other_list.node_alloc()) {
    move_assign_impl(other_list, true_type());
  } else {
    using t_move_iterator = ::portable_stl::move_iterator<iterator>;
    assign(t_move_iterator(other_list.begin()), t_move_iterator(other_list.end()));
  }
}

/**
 * @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in
 * other is moved from other into this container). other is in a valid but unspecified state afterwards.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param other Another container to use as data source.
 * @return forward_list<t_type, t_allocator>& *this.
 */
template<class t_type, class t_allocator>
inline forward_list<t_type, t_allocator> &forward_list<t_type, t_allocator>::operator=(forward_list &&other) noexcept(
  typename t_node_alloc_traits::propagate_on_container_move_assignment{}()
  && ::portable_stl::is_nothrow_move_assignable<allocator_type>{}()) {
  move_assign_impl(other, typename t_node_alloc_traits::propagate_on_container_move_assignment{});
  return *this;
}

/**
 * @brief Replaces the contents with those identified by initializer list init_list.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param init_list Initializer list to use as data source.
 * @return forward_list<t_type, t_allocator>& *this.
 */
template<class t_type, class t_allocator>
inline forward_list<t_type, t_allocator> &forward_list<t_type, t_allocator>::operator=(
  std::initializer_list<value_type> init_list) {
  assign(init_list.begin(), init_list.end());
  return *this;
}

/**
 * @brief Inserts a new element to the beginning of the container.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @tparam t_args
 * @param args Arguments to forward to the constructor of the element.
 * @return ::portable_stl::expected<typename forward_list<t_type, t_allocator>::reference_wrap,
 * ::portable_stl::portable_stl_error> A reference to the inserted element.
 */
template<class t_type, class t_allocator>
template<class... t_args>
::portable_stl::expected<typename forward_list<t_type, t_allocator>::reference_wrap, ::portable_stl::portable_stl_error>
  forward_list<t_type, t_allocator>::emplace_front(t_args &&...args) {
  return this->create_node(/* next = */ base::get_before_begin()->m_next, ::portable_stl::forward<t_args>(args)...)
    .transform([this](t_node_pointer const &tmp_node_pointer) {
      base::get_before_begin()->m_next = tmp_node_pointer;
      return ::portable_stl::ref<value_type>(base::get_before_begin()->m_next->get_value());
    });
}

/**
 * @brief Prepends the given element value to the beginning of the container.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param value The value of the element to prepend.
 * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error> Result of operation.
 */
template<class t_type, class t_allocator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> forward_list<t_type, t_allocator>::push_front(
  value_type const &value) {
  return this->create_node(/* next = */ base::get_before_begin()->m_next, value)
    .and_then(
      [this](t_node_pointer tmp_node_pointer) -> ::portable_stl::expected<void, portable_stl::portable_stl_error> {
        base::get_before_begin()->m_next = tmp_node_pointer;
        return {};
      })
    .transform_void();
}

/**
 * @brief Prepends the given element value to the beginning of the container.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param value The value of the element to prepend.
 * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error> Result of operation.
 */
template<class t_type, class t_allocator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> forward_list<t_type, t_allocator>::push_front(
  value_type &&value) {
  return this->create_node(/* next = */ base::get_before_begin()->m_next, ::portable_stl::move(value))
    .and_then(
      [this](
        t_node_pointer const &tmp_node_pointer) -> ::portable_stl::expected<void, portable_stl::portable_stl_error> {
        base::get_before_begin()->m_next = tmp_node_pointer;
        return {};
      })
    .transform_void();
}

/**
 * @brief Removes the first element of the container. If there are no elements in the container, the behavior is
 * undefined.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 */
template<class t_type, class t_allocator> void forward_list<t_type, t_allocator>::pop_front() {
  t_node_pointer ptr               = base::get_before_begin()->m_next;
  base::get_before_begin()->m_next = ptr->m_next;
  this->delete_node(ptr);
}

/**
 * @brief Inserts a new element into a position after the specified position in the container.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @tparam t_args
 * @param pos iterator after which the new element will be constructed.
 * @param args arguments to forward to the constructor of the element.
 * @return ::portable_stl::expected<typename forward_list<t_type, t_allocator>::iterator,
 * ::portable_stl::portable_stl_error> Iterator to the new element.
 */
template<class t_type, class t_allocator>
template<class... t_args>
::portable_stl::expected<typename forward_list<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  forward_list<t_type, t_allocator>::emplace_after(const_iterator pos, t_args &&...args) {
  t_begin_node_pointer const ptr = pos.get_begin();
  return this->create_node(/* next = */ ptr->m_next, ::portable_stl::forward<t_args>(args)...)
    .transform([&ptr](t_node_pointer const &tmp_node_pointer) {
      ptr->m_next = tmp_node_pointer;
      return iterator(ptr->m_next);
    });
}

/**
 * @brief Inserts value after the element pointed to by pos in the container.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param pos Iterator after which the content will be inserted.
 * @param value Element value to insert.
 * @return ::portable_stl::expected<typename forward_list<t_type, t_allocator>::iterator,
 * ::portable_stl::portable_stl_error> Iterator to the inserted element.
 */
template<class t_type, class t_allocator>
::portable_stl::expected<typename forward_list<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  forward_list<t_type, t_allocator>::insert_after(const_iterator pos, value_type const &value) {
  t_begin_node_pointer const ptr = pos.get_begin();
  return this->create_node(/* next = */ ptr->m_next, value).transform([&ptr](t_node_pointer const &tmp_node_pointer) {
    ptr->m_next = tmp_node_pointer;
    return iterator(ptr->m_next);
  });
}

/**
 * @brief Inserts value after the element pointed to by pos in the container.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param pos Iterator after which the content will be inserted.
 * @param value Element value to insert.
 * @return ::portable_stl::expected<typename forward_list<t_type, t_allocator>::iterator,
 * ::portable_stl::portable_stl_error> Iterator to the inserted element.
 */
template<class t_type, class t_allocator>
::portable_stl::expected<typename forward_list<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  forward_list<t_type, t_allocator>::insert_after(const_iterator pos, value_type &&value) {
  t_begin_node_pointer const ptr = pos.get_begin();
  return this->create_node(/* next = */ ptr->m_next, ::portable_stl::move(value))
    .transform([&ptr](t_node_pointer const &tmp_node_pointer) {
      ptr->m_next = tmp_node_pointer;
      return iterator(ptr->m_next);
    });
}

/**
 * @brief Inserts num copies of the value after the element pointed to by pos in the container.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param pos Iterator after which the content will be inserted.
 * @param num Number of copies to insert.
 * @param value Element value to insert.
 * @return ::portable_stl::expected<typename forward_list<t_type, t_allocator>::iterator,
 * ::portable_stl::portable_stl_error> Iterator to the last element inserted, or pos if count == 0.
 */
template<class t_type, class t_allocator>
::portable_stl::expected<typename forward_list<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  forward_list<t_type, t_allocator>::insert_after(const_iterator pos, size_type num, value_type const &value) {
  t_begin_node_pointer ret = pos.get_begin();

  if (num > 0) {
    auto result = this->create_node(/* next = */ nullptr, value);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
    --num;

    t_node_pointer first_inserted = portable_stl::move(result.value());
    t_node_pointer last_inserted  = first_inserted;

    auto guard = ::portable_stl::make_exception_guard([this, &first_inserted]() {
      while (first_inserted != nullptr) {
        t_node_pointer next = first_inserted->m_next;
        this->delete_node(first_inserted);
        first_inserted = next;
      }
    });

    for (; num > 0; --num) {
      result = this->create_node(/* next = */ nullptr, value);
      if (!result) {
        return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
      }
      last_inserted->m_next = ::portable_stl::move(result.value());
      last_inserted         = last_inserted->m_next;
    }

    guard.commit();

    last_inserted->m_next = ret->m_next;
    ret->m_next           = first_inserted;
    ret                   = static_cast<t_begin_node_pointer>(last_inserted);
  }
  return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>(iterator(ret));
}

/**
 * @brief Inserts elements from range [first, last) after the element pointed to by pos in the container.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @tparam t_input_iterator
 * @tparam t_sentinel
 * @param pos Iterator after which the content will be inserted.
 * @param first The range [first, last) to insert.
 * @param last The range [first, last) to insert.
 * @return ::portable_stl::expected<typename forward_list<t_type, t_allocator>::iterator,
 * ::portable_stl::portable_stl_error> Iterator to the last element inserted, or pos if first == last.
 */
template<class t_type, class t_allocator>
template<class t_input_iterator, class t_sentinel>
::portable_stl::expected<typename forward_list<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  forward_list<t_type, t_allocator>::insert_after_with_sentinel(
    const_iterator pos, t_input_iterator first, t_sentinel last) {
  t_begin_node_pointer ret = pos.get_begin();

  if (first != last) {
    auto result = this->create_node(/* next = */ nullptr, *first);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
    t_node_pointer first_inserted = portable_stl::move(result.value());
    t_node_pointer last_inserted  = first_inserted;
    ++first;

    auto guard = ::portable_stl::make_exception_guard([this, &first_inserted]() {
      while (first_inserted != nullptr) {
        t_node_pointer next{first_inserted->m_next};
        this->delete_node(first_inserted);
        first_inserted = next;
      }
    });

    for (; first != last; ++first) {
      result = this->create_node(/* next = */ nullptr, *first);
      if (!result) {
        return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
      }
      last_inserted->m_next = ::portable_stl::move(result.value());
      last_inserted         = last_inserted->m_next;
    }

    guard.commit();

    last_inserted->m_next = ret->m_next;
    ret->m_next           = first_inserted;
    ret                   = static_cast<t_begin_node_pointer>(last_inserted);
  }

  return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>(iterator(ret));
}

/**
 * @brief Inserts elements from range [first, last) after the element pointed to by pos in the container.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
 * @param pos Iterator after which the content will be inserted.
 * @param first The range [first, last) to insert.
 * @param last The range [first, last) to insert.
 * @return ::portable_stl::expected<typename forward_list<t_type, t_allocator>::iterator,
 * ::portable_stl::portable_stl_error> Iterator to the last element inserted, or pos if first == last.
 */
template<class t_type, class t_allocator>
template<
  class t_input_iterator,
  ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>>
::portable_stl::expected<typename forward_list<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  forward_list<t_type, t_allocator>::insert_after(const_iterator pos, t_input_iterator first, t_input_iterator last) {
  return insert_after_with_sentinel(pos, ::portable_stl::move(first), ::portable_stl::move(last));
}

/**
 * @brief Removes the element following pos from the container.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param pos Iterator to the element preceding the element to remove.
 * @return forward_list<t_type, t_allocator>::iterator Iterator to the element following the erased one, or end() if no
 * such element exists.
 */
template<class t_type, class t_allocator>
typename forward_list<t_type, t_allocator>::iterator forward_list<t_type, t_allocator>::erase_after(
  const_iterator pos) {
  t_begin_node_pointer ptr{pos.get_begin()};
  t_node_pointer       ptr_next{ptr->m_next};
  ptr->m_next = ptr_next->m_next;
  this->delete_node(ptr_next);
  return iterator(ptr->m_next);
}

/**
 * @brief Removes the elements following first until last from the container.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param first The range [first, last) to remove.
 * @param last The range [first, last) to remove.
 * @return forward_list<t_type, t_allocator>::iterator last.
 */
template<class t_type, class t_allocator>
typename forward_list<t_type, t_allocator>::iterator forward_list<t_type, t_allocator>::erase_after(
  const_iterator first, const_iterator last) {
  t_node_pointer ptr_end{last.get_unsafe_node_pointer()};
  if (first != last) {
    t_begin_node_pointer ptr{first.get_begin()};

    t_node_pointer ptr_next{ptr->m_next};
    if (ptr_next != ptr_end) {
      ptr->m_next = ptr_end;
      do {
        t_node_pointer tmp{ptr_next->m_next};
        this->delete_node(ptr_next);
        ptr_next = tmp;
      } while (ptr_next != ptr_end);
    }
  }
  return iterator(ptr_end);
}

/**
 * @brief Resizes the container to contain num elements.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param num New size of the container.
 * @return true if successful,
 * @return false otherwise.
 */
template<class t_type, class t_allocator> bool forward_list<t_type, t_allocator>::resize(size_type num) {
  size_type count = 0;
  iterator  iter_prev{before_begin()};
  iterator  iter{begin()};
  iterator  iter_end{end()};
  for (; (iter != iter_end) && (count < num); ++iter) {
    ++iter_prev;
    ++count;
  }
  if (iter_end != iter) {
    erase_after(iter_prev, iter_end);
  } else {
    num -= count;
    // add num lacking items
    if (num > 0) {
      t_begin_node_pointer ptr{iter_prev.get_begin()};
      while (num > 0) {
        auto result = this->create_node(/* next = */ nullptr);
        if (!result) {
          return false;
        }
        ptr->m_next = ::portable_stl::move(result.value());
        ptr         = ptr->next_as_begin();
        --num;
      }
    }
  }
  return true;
}

/**
 * @brief Resizes the container to contain num elements.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param num New size of the container
 * @param value The value to initialize the new elements with.
 * @return true if successful,
 * @return false otherwise.
 */
template<class t_type, class t_allocator>
bool forward_list<t_type, t_allocator>::resize(size_type num, value_type const &value) {
  size_type count = 0;
  iterator  iter_prev{before_begin()};
  iterator  iter{begin()};
  iterator  iter_end{end()};
  for (; (iter != iter_end) && (count < num); ++iter) {
    ++iter_prev;
    ++count;
  }
  if (iter_end != iter) {
    erase_after(iter_prev, iter_end);
  } else {
    num -= count;
    // add num lacking items
    if (num > 0) {
      for (t_begin_node_pointer ptr{iter_prev.get_begin()}; num > 0; --num, ptr = ptr->next_as_begin()) {
        auto result = this->create_node(/* next = */ nullptr, value);
        if (!result) {
          return false;
        }
        ptr->m_next = ::portable_stl::move(result.value());
      }
    }
  }
  return true;
}

/**
 * @brief Moves all elements from another forward_list other into *this.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param pos Element after which the content will be inserted.
 * @param other_list Another container to move the content from.
 */
template<class t_type, class t_allocator>
void forward_list<t_type, t_allocator>::splice_after(const_iterator pos, forward_list &other_list) {
  if (!other_list.empty()) {
    if (pos.get_begin()->m_next != nullptr) {
      const_iterator last_in_merged{other_list.before_begin()};
      while (last_in_merged.get_begin()->m_next != nullptr) {
        ++last_in_merged;
      }
      last_in_merged.get_begin()->m_next = pos.get_begin()->m_next;
    }
    pos.get_begin()->m_next               = other_list.get_before_begin()->m_next;
    other_list.get_before_begin()->m_next = nullptr;
  }
}

/**
 * @brief Moves all elements from another forward_list other into *this.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param pos Element after which the content will be inserted.
 * @param other_list Another container to move the content from.
 */
template<class t_type, class t_allocator>
inline void forward_list<t_type, t_allocator>::splice_after(const_iterator pos, forward_list &&other_list) {
  splice_after(pos, other_list);
}

/**
 * @brief Moves the element pointed to by the iterator following iter from another forward_list other into *this.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param pos Element after which the content will be inserted.
 * @param other_list Another container to move the content from.
 * @param iter Iterator preceding the iterator to the element to move from other to *this.
 */
template<class t_type, class t_allocator>
void forward_list<t_type, t_allocator>::splice_after(
  const_iterator pos, forward_list & /*other_list*/, const_iterator iter) {
  const_iterator iter_next = ::portable_stl::next(iter);
  if ((pos != iter) && (pos != iter_next)) {
    iter.get_begin()->m_next      = iter_next.get_begin()->m_next;
    iter_next.get_begin()->m_next = pos.get_begin()->m_next;
    pos.get_begin()->m_next       = iter_next.get_unsafe_node_pointer();
  }
}

/**
 * @brief Moves the element pointed to by the iterator following iter from another forward_list other into *this.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param pos Element after which the content will be inserted.
 * @param other_list Another container to move the content from.
 * @param iter Iterator preceding the iterator to the element to move from other to *this.
 */
template<class t_type, class t_allocator>
inline void forward_list<t_type, t_allocator>::splice_after(
  const_iterator pos, forward_list &&other_list, const_iterator iter) {
  splice_after(pos, other_list, iter);
}

/**
 * @brief Moves the elements in the range (first, last) from another forward_list other into *this.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param pos Element after which the content will be inserted.
 * @param other_list Another container to move the content from.
 * @param first The range [first, last) to move from other to *this.
 * @param last The range [first, last) to move from other to *this.
 */
template<class t_type, class t_allocator>
void forward_list<t_type, t_allocator>::splice_after(
  const_iterator pos, forward_list & /*other_list*/, const_iterator first, const_iterator last) {
  if (first != last && pos != first) {
    const_iterator lm1 = first;
    while (lm1.get_begin()->m_next != last.get_begin()) {
      ++lm1;
    }
    if (first != lm1) {
      lm1.get_begin()->m_next   = pos.get_begin()->m_next;
      pos.get_begin()->m_next   = first.get_begin()->m_next;
      first.get_begin()->m_next = last.get_unsafe_node_pointer();
    }
  }
}

/**
 * @brief Moves the elements in the range (first, last) from another forward_list other into *this.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param pos Element after which the content will be inserted.
 * @param other_list Another container to move the content from.
 * @param first The range [first, last) to move from other to *this.
 * @param last The range [first, last) to move from other to *this.
 */
template<class t_type, class t_allocator>
inline void forward_list<t_type, t_allocator>::splice_after(
  const_iterator pos, forward_list &&other_list, const_iterator first, const_iterator last) {
  splice_after(pos, other_list, first, last);
}

/**
 * @brief Removes all elements that are equal to value (using operator==).
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param value Value of the elements to remove.
 * @return forward_list<t_type, t_allocator>::remove_return_type The number of elements removed.
 */
template<class t_type, class t_allocator>
typename forward_list<t_type, t_allocator>::remove_return_type forward_list<t_type, t_allocator>::remove(
  value_type const &value) {
  forward_list<t_type, t_allocator> deleted_nodes(get_allocator()); // collect the nodes we're removing
  typename forward_list<t_type, t_allocator>::size_type count_removed = 0;
  iterator const                                        iter_end{end()};
  for (iterator iter{before_begin()}; nullptr != iter.get_begin()->m_next;) {
    if (value == iter.get_begin()->m_next->get_value()) {
      ++count_removed;
      iterator iter_after_next{::portable_stl::next(iter, 2)};
      for (; iter_after_next != iter_end && *iter_after_next == value; ++iter_after_next) {
        ++count_removed;
      }
      deleted_nodes.splice_after(deleted_nodes.before_begin(), *this, iter, iter_after_next);
      if (iter_end == iter_after_next) {
        break;
      }
      iter = iter_after_next;
    } else {
      ++iter;
    }
  }

  return static_cast<remove_return_type>(count_removed);
}

/**
 * @brief Removes all elements which predicate pred returns true.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @tparam t_pred Must meet the requirements of Predicate.
 * @param pred Unary predicate which returns ​true if the element should be removed.
 * @return forward_list<t_type, t_allocator>::remove_return_type The number of elements removed.
 */
template<class t_type, class t_allocator>
template<class t_pred>
typename forward_list<t_type, t_allocator>::remove_return_type forward_list<t_type, t_allocator>::remove_if(
  t_pred pred) {
  forward_list<t_type, t_allocator> deleted_nodes(get_allocator()); // collect the nodes we're removing
  typename forward_list<t_type, t_allocator>::size_type count_removed = 0;
  iterator const                                        iter_end{end()};
  for (iterator iter{before_begin()}; nullptr != iter.get_begin()->m_next;) {
    if (pred(iter.get_begin()->m_next->get_value())) {
      ++count_removed;
      iterator iter_after_next{::portable_stl::next(iter, 2)};
      for (; iter_after_next != iter_end && pred(*iter_after_next); ++iter_after_next) {
        ++count_removed;
      }
      deleted_nodes.splice_after(deleted_nodes.before_begin(), *this, iter, iter_after_next);
      if (iter_end == iter_after_next) {
        break;
      }
      iter = iter_after_next;
    } else {
      ++iter;
    }
  }

  return static_cast<remove_return_type>(count_removed);
}

/**
 * @brief Removes all consecutive duplicate elements from the container.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @tparam t_binary_pred Must meet the requirements of BinaryPredicate.
 * @param binary_pred Binary predicate which returns ​true if the elements should be treated as equal.
 * @return forward_list<t_type, t_allocator>::remove_return_type The number of elements removed.
 */
template<class t_type, class t_allocator>
template<class t_binary_predicate>
typename forward_list<t_type, t_allocator>::remove_return_type forward_list<t_type, t_allocator>::unique(
  t_binary_predicate binary_pred) {
  forward_list<t_type, t_allocator> deleted_nodes(get_allocator()); // collect the nodes we're removing
  typename forward_list<t_type, t_allocator>::size_type count_removed = 0;
  for (iterator iter{begin()}, iter_end = end(); iter != iter_end;) {
    iterator iter_next{::portable_stl::next(iter)};
    for (; (iter_end != iter_next) && binary_pred(*iter, *iter_next); ++iter_next) {
      ++count_removed;
    }
    if (iter.get_begin()->m_next != iter_next.get_unsafe_node_pointer()) {
      deleted_nodes.splice_after(deleted_nodes.before_begin(), *this, iter, iter_next);
    }
    iter = iter_next;
  }

  return static_cast<remove_return_type>(count_removed);
}

/**
 * @brief Merge implementation.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @tparam t_compare Must meet the requirements of Compare.
 * @param first1 Node in first list.
 * @param first2 Node in second list.
 * @param comp Comparison function object
 * @return forward_list<t_type, t_allocator>::t_node_pointer
 */
template<class t_type, class t_allocator>
template<class t_compare>
typename forward_list<t_type, t_allocator>::t_node_pointer forward_list<t_type, t_allocator>::merge_impl(
  t_node_pointer first1, t_node_pointer first2, t_compare &comp) {
  if (nullptr == first1) {
    return first2;
  }
  if (nullptr == first2) {
    return first1;
  }
  t_node_pointer ret;
  if (comp(first2->get_value(), first1->get_value())) {
    t_node_pointer tmp{first2};
    while ((tmp->m_next != nullptr) && comp(tmp->m_next->get_value(), first1->get_value())) {
      tmp = tmp->m_next;
    }
    ret         = first2;
    first2      = tmp->m_next;
    tmp->m_next = first1;
  } else {
    ret = first1;
  }
  t_node_pointer ptr = first1;
  first1             = first1->m_next;
  while ((nullptr != first1) && (nullptr != first2)) {
    if (comp(first2->get_value(), first1->get_value())) {
      t_node_pointer tmp{first2};
      while ((nullptr != tmp->m_next) && comp(tmp->m_next->get_value(), first1->get_value())) {
        tmp = tmp->m_next;
      }
      ptr->m_next = first2;
      first2      = tmp->m_next;
      tmp->m_next = first1;
    }
    ptr    = first1;
    first1 = first1->m_next;
  }
  if (nullptr != first2) {
    ptr->m_next = first2;
  }
  return ret;
}

/**
 * @brief Merges other into *this.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @tparam t_compare Must meet the requirements of Compare.
 * @param other_list Another container to merge.
 * @param comp Comparison function object.
 */
template<class t_type, class t_allocator>
template<class t_compare>
void forward_list<t_type, t_allocator>::merge(forward_list &other_list, t_compare comp) {
  if (this != ::portable_stl::addressof(other_list)) {
    base::get_before_begin()->m_next
      = merge_impl(base::get_before_begin()->m_next, other_list.get_before_begin()->m_next, comp);
    other_list.get_before_begin()->m_next = nullptr;
  }
}

/**
 * @brief Sorts the elements and preserves the order of equivalent elements.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @tparam t_compare Must meet the requirements of Compare.
 * @param comp Comparison function object.
 */
template<class t_type, class t_allocator>
template<class t_compare>
inline void forward_list<t_type, t_allocator>::sort(t_compare comp) {
  base::get_before_begin()->m_next = sort_impl(
    base::get_before_begin()->m_next, static_cast<size_type>(::portable_stl::distance(begin(), end())), comp);
}

/**
 * @brief Sort implementation.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @tparam t_compare Must meet the requirements of Compare.
 * @param first1 Pointer to the first node.
 * @param list_size Size of the list.
 * @param comp Comparison function object.
 * @return forward_list<t_type, t_allocator>::t_node_pointer
 */
template<class t_type, class t_allocator>
template<class t_compare>
typename forward_list<t_type, t_allocator>::t_node_pointer forward_list<t_type, t_allocator>::sort_impl(
  t_node_pointer first, size_type list_size, t_compare &comp) {
  switch (list_size) {
    case 0:
    case 1:
      return first;
    case 2:
      if (comp(first->m_next->get_value(), first->get_value())) {
        // swap first and second nodes
        t_node_pointer tmp{first->m_next};
        tmp->m_next   = first;
        first->m_next = nullptr;
        first         = tmp;
      }
      return first;
    default:
      size_type const size_left{list_size / 2};                                    // >= 1
      size_type const size_right{list_size - size_left};                           // >= 0
      auto const      left_end_dist = static_cast<difference_type>(size_left - 1); // >= 0
      t_node_pointer  tmp2{::portable_stl::next(iterator(first), left_end_dist).get_unsafe_node_pointer()};
      t_node_pointer  first2{tmp2->m_next};
      tmp2->m_next = nullptr;
      return merge_impl(sort_impl(first, size_left, comp), sort_impl(first2, size_right, comp), comp);
  }
}

/**
 * @brief Reverses the order of the elements in the container.
 * No references or iterators become invalidated.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 */
template<class t_type, class t_allocator> void forward_list<t_type, t_allocator>::reverse() noexcept {
  t_node_pointer ptr = base::get_before_begin()->m_next;
  if (nullptr != ptr) {
    t_node_pointer first{ptr->m_next};
    ptr->m_next = nullptr;
    while (first != nullptr) {
      t_node_pointer tmp{first->m_next};
      first->m_next = ptr;
      ptr           = first;
      first         = tmp;
    }
    base::get_before_begin()->m_next = ptr;
  }
}

/**
 * @brief Compares the contents of two forward_lists.
 * Checks if the contents of lhs and rhs are equal, that is, they have the same number of elements and each element in
 * lhs compares equal with the element in rhs at the same position.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param lhv forward_lists whose contents to compare.
 * @param rhv forward_lists whose contents to compare.
 * @return true if the contents of the forward_lists are equal,
 * @return false otherwise.
 */
template<class t_type, class t_allocator>
bool operator==(forward_list<t_type, t_allocator> const &lhv, forward_list<t_type, t_allocator> const &rhv) {
  using t_iter = typename forward_list<t_type, t_allocator>::const_iterator;
  t_iter iter_left{lhv.begin()};
  t_iter iter_end_left{lhv.end()};
  t_iter iter_right{rhv.begin()};
  t_iter iter_end_right{rhv.end()};

  for (; (iter_left != iter_end_left) && (iter_right != iter_end_right); ++iter_left, ++iter_right) {
    if (!(*iter_left == *iter_right)) {
      return false;
    }
  }
  return (iter_left == iter_end_left) == (iter_right == iter_end_right);
}

/**
 * @brief Compares the contents of two forward_lists.
 * Checks if the contents of lhs and rhs are equal, that is, they have the same number of elements and each element in
 * lhs compares equal with the element in rhs at the same position.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param lhv forward_lists whose contents to compare.
 * @param rhv forward_lists whose contents to compare.
 * @return true if the contents of the forward_lists are not equal,
 * @return false otherwise.
 */
template<class t_type, class t_allocator>
inline bool operator!=(forward_list<t_type, t_allocator> const &lhv, forward_list<t_type, t_allocator> const &rhv) {
  return !(lhv == rhv);
}

/**
 * @brief Compares the contents of two forward_lists.
 * Checks if the contents of lhs and rhs are equal, that is, they have the same number of elements and each element in
 * lhs compares equal with the element in rhs at the same position.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param lhv forward_lists whose contents to compare.
 * @param rhv forward_lists whose contents to compare.
 * @return true if the contents of the lhs are lexicographically less than the contents of rhs,
 * @return false otherwise.
 */
template<class t_type, class t_allocator>
inline bool operator<(forward_list<t_type, t_allocator> const &lhv, forward_list<t_type, t_allocator> const &rhv) {
  return ::portable_stl::lexicographical_compare(lhv.begin(), lhv.end(), rhv.begin(), rhv.end());
}

/**
 * @brief Compares the contents of two forward_lists.
 * Compares the contents of lhs and rhs lexicographically. The comparison is performed by a function equivalent to
 * ::lexicographical_compare.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param lhv forward_lists whose contents to compare.
 * @param rhv forward_lists whose contents to compare.
 * @return true if the contents of the lhs are lexicographically less than or equal to the contents of rhs,
 * @return false otherwise.
 */
template<class t_type, class t_allocator>
inline bool operator<=(forward_list<t_type, t_allocator> const &lhv, forward_list<t_type, t_allocator> const &rhv) {
  return !(rhv < lhv);
}

/**
 * @brief Compares the contents of two forward_lists.
 * Compares the contents of lhs and rhs lexicographically. The comparison is performed by a function equivalent to
 * ::lexicographical_compare.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param lhv forward_lists whose contents to compare.
 * @param rhv forward_lists whose contents to compare.
 * @return true if the contents of the lhs are lexicographically greater than the contents of rhs,
 * @return false otherwise.
 */
template<class t_type, class t_allocator>
inline bool operator>(forward_list<t_type, t_allocator> const &lhv, forward_list<t_type, t_allocator> const &rhv) {
  return rhv < lhv;
}

/**
 * @brief Compares the contents of two forward_lists.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param lhv forward_lists whose contents to compare.
 * @param rhv forward_lists whose contents to compare.
 * @return true  if the contents of the lhs are lexicographically greater than or equal to the contents of rhs,
 * @return false otherwise.
 */
template<class t_type, class t_allocator>
inline bool operator>=(forward_list<t_type, t_allocator> const &lhv, forward_list<t_type, t_allocator> const &rhv) {
  return !(lhv < rhv);
}

/**
 * @brief Specializes the ::swap algorithm for ::forward_list. Swaps the contents of lhs and rhs. Calls
 * lhs.swap(rhs).
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param lhv Containers whose contents to swap.
 * @param rhv Containers whose contents to swap.
 */
template<class t_type, class t_allocator>
inline void swap(forward_list<t_type, t_allocator> &lhv,
                 forward_list<t_type, t_allocator> &rhv) noexcept(noexcept(lhv.swap(rhv))) {
  lhv.swap(rhv);
}

} // namespace portable_stl

#endif // PSTL_FORWARD_LIST_H
