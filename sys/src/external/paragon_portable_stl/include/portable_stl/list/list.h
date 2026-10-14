// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="list.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_LIST_H
#define PSTL_LIST_H

#include "../algorithm/equal.h"
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
#include "list_impl.h"

#if defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  include "../language_support/exception/throw_on_true.h"
#else
#  include "../language_support/no_exception/throw_on_true.h"
#endif

namespace portable_stl {

/**
 * @brief List is a list that supports constant time insertion and removal of elements from anywhere in the
 * list. Fast random access is not supported. It is usually implemented as a doubly-linked list. Compared to
 * forward_list this list provides bidirectional iteration capability while being less space efficient.

 * Adding, removing and moving the elements within the list or across several lists does not invalidate the iterators or
 * references. An iterator is invalidated only when the corresponding element is deleted.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory. The type must meet the requirements of Allocator. The program is ill-formed if Allocator::value_type is not
 * the same as t_type.
 */
template<class t_type, class t_allocator = ::portable_stl::allocator<t_type>>
class list : private list_impl<t_type, t_allocator> {
  /**
   * @brief Base list implementation type.
   */
  using base                = list_impl<t_type, t_allocator>;
  /**
   * @brief Node type.
   */
  using t_node_type         = typename base::t_node_type;
  /**
   * @brief Node allocator type.
   */
  using t_node_allocator    = typename base::t_node_allocator;
  /**
   * @brief Node pointer type.
   */
  using t_node_pointer      = typename base::t_node_pointer;
  /**
   * @brief Node allocator traits.
   */
  using t_node_alloc_traits = typename base::t_node_alloc_traits;
  /**
   * @brief Base node type.
   */
  using t_node_base         = typename base::t_node_base;
  /**
   * @brief Base node pointer type.
   */
  using t_node_base_pointer = typename base::t_node_base_pointer;
  /**
   * @brief Node link pointer type.
   */
  using t_link_pointer      = typename base::t_link_pointer;

public:
  /**
   * @brief List value type.
   */
  using value_type             = t_type;
  /**
   * @brief List allocator type.
   */
  using allocator_type         = t_allocator;
  /**
   * @brief Reference type.
   */
  using reference              = value_type &;
  /**
   * @brief Constatnt reference type.
   */
  using const_reference        = value_type const &;
  /**
   * @brief Pointer type.
   */
  using pointer                = typename base::pointer;
  /**
   * @brief Constant pointer type.
   */
  using const_pointer          = typename base::const_pointer;
  /**
   * @brief Size type.
   */
  using size_type              = typename base::size_type;
  /**
   * @brief Difference type.
   */
  using difference_type        = typename base::difference_type;
  /**
   * @brief Iterator type.
   */
  using iterator               = typename base::iterator;
  /**
   * @brief Constant iterator type.
   */
  using const_iterator         = typename base::const_iterator;
  /**
   * @brief Reverse iterator type.
   */
  using reverse_iterator       = ::portable_stl::reverse_iterator<iterator>;
  /**
   * @brief Constant reverse iterator type.
   */
  using const_reverse_iterator = ::portable_stl::reverse_iterator<const_iterator>;
  /**
   * @brief Return type after remove.
   */
  using remove_return_type     = size_type;

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

  /**
   * @brief Default constructor.
   * Constructs an empty list with a default-constructed allocator.
   *
   */
  list() noexcept(::portable_stl::is_nothrow_default_constructible<t_node_allocator>{}()) {
  }

  /**
   * @brief Constructs an empty list with the given allocator 'alloc'.
   *
   * @param alloc Allocator to use for all memory allocations of this list.
   */
  explicit list(allocator_type const &alloc) : base(alloc) {
  }

  /**
   * @brief Constructs the list with 'num' copies of elements with value 'value'.
   *
   * @param num The size of the list.
   * @param value The value to initialize elements of the list with.
   */
  list(size_type num, value_type const &value);

  /**
   * @brief Make the list with 'num' copies of elements with value 'value'.
   *
   * @param num The size of the list.
   * @param value The value to initialize elements of the list with.
   * @return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>
   */
  static ::portable_stl::expected<list, ::portable_stl::portable_stl_error> make_list(size_type         num,
                                                                                      value_type const &value);

  /**
   * @brief Constructs the list with 'num' copies of elements with value 'value' and given allocator 'alloc'.
   *
   * @param num The size of the list.
   * @param value The value to initialize elements of the list with.
   * @param alloc Allocator to use for all memory allocations of this list.
   */
  template<class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_allocator<t_allocator>, void>>
  list(size_type num, value_type const &value, allocator_type const &alloc);

  /**
   * @brief Make the list with 'num' copies of elements with value 'value' and given allocator 'alloc'.
   *
   * @param num The size of the list.
   * @param value The value to initialize elements of the list with.
   * @param alloc Allocator to use for all memory allocations of this list.
   * @return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>
   */
  template<class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_allocator<t_allocator>, void>>
  static ::portable_stl::expected<list, ::portable_stl::portable_stl_error> make_list(
    size_type num, value_type const &value, allocator_type const &alloc);

  /**
   * @brief Constructs the list with 'num' default-inserted instances of t_type.
   * No copies are made.
   *
   * @param num The size of the list.
   */
  explicit list(size_type num);

  /**
   * @brief Make the list with 'num' default-inserted instances of t_type.
   * No copies are made.
   *
   * @param num The size of the list.
   * @return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>
   */
  static ::portable_stl::expected<list, ::portable_stl::portable_stl_error> make_list(size_type num);

  /**
   * @brief Constructs the list with 'num' default-inserted instances of t_type and given allocator 'alloc'.
   * No copies are made.
   *
   * @param num The size of the list.
   * @param alloc Allocator to use for all memory allocations of this list.
   */
  list(size_type num, allocator_type const &alloc);

  /**
   * @brief Make the list with 'num' default-inserted instances of t_type and given allocator 'alloc'.
   * No copies are made.
   *
   * @param num The size of the list.
   * @param alloc Allocator to use for all memory allocations of this list.
   * @return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>
   */
  static ::portable_stl::expected<list, ::portable_stl::portable_stl_error> make_list(size_type             num,
                                                                                      allocator_type const &alloc);

  /**
   * @brief Constructs the list with the contents of the range [first, last).
   *
   * @tparam t_input_iterator Satisfies LegacyInputIterator.
   * @param first The range [first, last) to copy the elements from.
   * @param last The range [first, last) to copy the elements from.
   */
  template<class t_input_iterator>
  list(t_input_iterator first,
       t_input_iterator last,
       ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>
       = nullptr);

  /**
   * @brief Make the list with the contents of the range [first, last).
   *
   * @tparam t_input_iterator Satisfies LegacyInputIterator.
   * @param first The range [first, last) to copy the elements from.
   * @param last The range [first, last) to copy the elements from.
   * @return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>
   */
  template<class t_input_iterator>
  static ::portable_stl::expected<list, ::portable_stl::portable_stl_error> make_list(
    t_input_iterator first,
    t_input_iterator last,
    ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>
    = nullptr);

  /**
   * @brief Constructs the list with the contents of the range [first, last) and given allocator 'alloc'.
   *
   * @tparam t_input_iterator Satisfies LegacyInputIterator.
   * @param first The range [first, last) to copy the elements from.
   * @param last The range [first, last) to copy the elements from.
   * @param alloc Allocator to use for all memory allocations of this list.
   */
  template<class t_input_iterator>
  list(t_input_iterator      first,
       t_input_iterator      last,
       allocator_type const &alloc,
       ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>
       = nullptr);

  /**
   * @brief Make the list with the contents of the range [first, last) and given allocator 'alloc'.
   *
   * @tparam t_input_iterator Satisfies LegacyInputIterator.
   * @param first The range [first, last) to copy the elements from.
   * @param last The range [first, last) to copy the elements from.
   * @param alloc Allocator to use for all memory allocations of this list.
   * @return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>
   */
  template<class t_input_iterator>
  static ::portable_stl::expected<list, ::portable_stl::portable_stl_error> make_list(
    t_input_iterator      first,
    t_input_iterator      last,
    allocator_type const &alloc,
    ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>
    = nullptr);

  /**
   * @brief Copy constructor.
   * Constructs the list with the copy of the contents of other.
   *
   * @param other Another list to be used as source to initialize the elements of the list with.
   */
  list(list const &other);

  /**
   * @brief Make list from another.
   * Constructs the list with the copy of the contents of other.
   *
   * @param other Another list to be used as source to initialize the elements of the list with.
   * @return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>
   */
  static ::portable_stl::expected<list, ::portable_stl::portable_stl_error> make_list(list const &other);

  /**
   * @brief Constructs the list with the copy of the contents of other, using 'alloc' as the allocator.
   *
   * @param other Another list to be used as source to initialize the elements of the list with.
   * @param alloc Allocator to use for all memory allocations of this list.
   */
  list(list const &other, ::portable_stl::type_identity_t<allocator_type> const &alloc);

  /**
   * @brief Make the list with the copy of the contents of other, using 'alloc' as the allocator.
   *
   * @param other Another list to be used as source to initialize the elements of the list with.
   * @param alloc Allocator to use for all memory allocations of this list.
   * @return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>
   */
  static ::portable_stl::expected<list, ::portable_stl::portable_stl_error> make_list(
    list const &other, ::portable_stl::type_identity_t<allocator_type> const &alloc);

  /**
   * @brief Move constructor.
   * Constructs the list with the contents of other using move semantics.
   * Allocator is obtained by move-construction from the allocator belonging to other.
   *
   * @param other Another list to be used as source to initialize the elements of the list with.
   */
  list(list &&other) noexcept(::portable_stl::is_nothrow_move_constructible<t_node_allocator>{}());

  /**
   * @brief Allocator-extended move constructor.
   * Using 'alloc' as the allocator for the new list, moving the contents from other; if 'alloc' !=
   * other.get_allocator(), this results in an element-wise move.
   *
   * @param other Another list to be used as source to initialize the elements of the list with.
   * @param alloc Allocator to use for all memory allocations of this list.
   */
  list(list &&other, ::portable_stl::type_identity_t<allocator_type> const &alloc);

  /**
   * @brief Make list by moving elements from another (allocator-extended).
   * Using 'alloc' as the allocator for the new list, moving the contents from other; if 'alloc' !=
   * other.get_allocator(), this results in an element-wise move.
   *
   * @param other Another list to be used as source to initialize the elements of the list with.
   * @param alloc Allocator to use for all memory allocations of this list.
   * @return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>
   */
  static ::portable_stl::expected<list, ::portable_stl::portable_stl_error> make_list(
    list &&other, ::portable_stl::type_identity_t<allocator_type> const &alloc);

  /**
   * @brief Constructs the list with the contents of the initializer list init.
   *
   * @param init_list Initializer list to initialize the elements of the list with.
   */
  list(std::initializer_list<value_type> init_list);

  /**
   * @brief Make the list with the contents of the initializer list init.
   *
   * @param init_list Initializer list to initialize the elements of the list with.
   * @return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>
   */
  static ::portable_stl::expected<list, ::portable_stl::portable_stl_error> make_list(
    std::initializer_list<value_type> init_list);

  /**
   * @brief Constructs the list with the contents of the initializer list init and given allocator 'alloc'.
   *
   * @param init_list Initializer list to initialize the elements of the list with.
   * @param alloc Allocator to use for all memory allocations of this list.
   */
  list(std::initializer_list<value_type> init_list, allocator_type const &alloc);

  /**
   * @brief Make the list with the contents of the initializer list init and given allocator 'alloc'.
   *
   * @param init_list Initializer list to initialize the elements of the list with.
   * @param alloc Allocator to use for all memory allocations of this list.
   * @return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>
   */
  static ::portable_stl::expected<list, ::portable_stl::portable_stl_error> make_list(
    std::initializer_list<value_type> init_list, allocator_type const &alloc);

  /**
   * @brief Replaces the contents of the list with count copies of value value.
   *
   * @param num The new size of the list.
   * @param value The value to initialize elements of the list with.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> assign(size_type num, value_type const &value);

  /**
   * @brief Replaces the contents of the list with copies of those in the range [first, last).
   * The behavior is undefined if either argument is an iterator into *this.
   *
   * @tparam t_input_iterator Satisfies LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>
   */
  template<class t_input_iterator>
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> assign(
    t_input_iterator first,
    t_input_iterator last,
    ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>
    = nullptr);

  /**
   * @brief Replaces the contents of the list with the elements from the initializer list 'init_list'.
   *
   * @param init_list Initializer List to copy the values from.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> assign(
    std::initializer_list<value_type> init_list) {
    return assign(init_list.begin(), init_list.end());
  }

  /**
   * @brief Copy assignment operator. Replaces the contents with a copy of the contents of 'other'.
   *
   * @param other Another list to use as data source.
   * @return list&
   */
  list &operator=(list const &other);

  /**
   * @brief Move assignment operator. Replaces the contents with those of 'other' using move semantics (i.e. the data in
   * 'other' is moved from 'other' into this list). 'other' is in a valid but unspecified state afterwards.
   *
   * @param other Another list to use as data source.
   * @return list&
   */
  list &operator=(list &&other) noexcept(typename t_node_alloc_traits::propagate_on_container_move_assignment{}()
                                         && ::portable_stl::is_nothrow_move_assignable<t_node_allocator>{}());

  /**
   * @brief Replaces the contents of the list with those identified by initializer list 'init_list'.
   *
   * @param init_list Initializer list to use as data source.
   * @return list&
   */
  list &operator=(std::initializer_list<value_type> init_list) {
    assign(init_list.begin(), init_list.end());
    return *this;
  }

  /**
   * @brief Returns the allocator associated with the list.
   *
   * @return allocator_type The associated allocator.
   */
  allocator_type get_allocator() const noexcept;

  /**
   * @brief Returns the number of elements in the list.
   *
   * @return size_type The number of elements in the list.
   */
  size_type size() const noexcept {
    return base::size_val();
  }

  /**
   * @brief Checks if the list has no elements, i.e. whether begin() == end().
   *
   * @return true If the list is empty,
   * @return false otherwise.
   */
  bool empty() const noexcept {
    return base::empty();
  }

  /**
   * @brief Returns the maximum number of elements the list is able to hold due to system or library implementation
   * limitations, i.e. ::distance(begin(), end()) for the largest list.
   *
   * @return size_type Maximum number of elements.
   */
  size_type max_size() const noexcept {
    return ::portable_stl::min<size_type>(base::get_node_alloc_max_size(),
                                          ::portable_stl::numeric_limits<difference_type>::max());
  }

  /**
   * @brief Returns an iterator to the first element of the list.
   * If the list is empty, the returned iterator will be equal to end().
   *
   * @return iterator Iterator to the first element.
   */
  iterator begin() noexcept {
    return base::begin();
  }

  /**
   * @brief Returns a constant iterator to the first element of the list.
   * If the list is empty, the returned iterator will be equal to end().
   *
   * @return const_iterator Constant iterator to the first element.
   */
  const_iterator begin() const noexcept {
    return base::begin();
  }

  /**
   * @brief Returns an iterator to the element following the last element of the list.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   *
   * @return iterator Iterator to the element following the last element.
   */
  iterator end() noexcept {
    return base::end();
  }

  /**
   * @brief Returns a constant iterator to the element following the last element of the list.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   *
   * @return const_iterator Constant iterator to the element following the last element.
   */
  const_iterator end() const noexcept {
    return base::end();
  }

  /**
   * @brief Returns a constant iterator to the first element of the list.
   * If the list is empty, the returned iterator will be equal to end().
   *
   * @return const_iterator Constant iterator to the first element.
   */
  const_iterator cbegin() const noexcept {
    return base::begin();
  }

  /**
   * @brief Returns a constant iterator to the element following the last element of the list.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   *
   * @return const_iterator Constant iterator to the element following the last element.
   */
  const_iterator cend() const noexcept {
    return base::end();
  }

  /**
   * @brief Returns a reverse iterator to the first element of the reversed list. It corresponds to the last element of
   * the non-reversed list. If the list is empty, the returned iterator is equal to rend().
   *
   * @return reverse_iterator Reverse iterator to the first element.
   */
  reverse_iterator rbegin() noexcept {
    return reverse_iterator(end());
  }

  /**
   * @brief Returns a constant reverse iterator to the first element of the reversed list. It corresponds to the last
   * element of the non-reversed list. If the list is empty, the returned iterator is equal to rend().
   *
   * @return const_reverse_iterator Constant reverse iterator to the first element.
   */
  const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator(end());
  }

  /**
   * @brief Returns a reverse iterator to the element following the last element of the reversed list. It corresponds to
   * the element preceding the first element of the non-reversed list. This element acts as a placeholder, attempting to
   * access it results in undefined behavior.
   *
   * @return reverse_iterator Reverse iterator to the element following the last element.
   */
  reverse_iterator rend() noexcept {
    return reverse_iterator(begin());
  }

  /**
   * @brief Returns a constant reverse iterator to the element following the last element of the reversed list. It
   * corresponds to the element preceding the first element of the non-reversed list. This element acts as a
   * placeholder, attempting to access it results in undefined behavior.
   *
   * @return const_reverse_iterator Constant reverse iterator to the element following the last element.
   */
  const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator(begin());
  }

  /**
   * @brief Returns a constant reverse iterator to the first element of the reversed list. It corresponds to the last
   * element of the non-reversed list. If the list is empty, the returned iterator is equal to rend().
   *
   * @return const_reverse_iterator Constant reverse iterator to the first element.
   */
  const_reverse_iterator crbegin() const noexcept {
    return const_reverse_iterator(end());
  }

  /**
   * @brief Returns a constant reverse iterator to the element following the last element of the reversed list. It
   * corresponds to the element preceding the first element of the non-reversed list. This element acts as a
   * placeholder, attempting to access it results in undefined behavior.
   *
   * @return const_reverse_iterator Constant reverse iterator to the element following the last element.
   */
  const_reverse_iterator crend() const noexcept {
    return const_reverse_iterator(begin());
  }

  /**
   * @brief Returns a reference to the first element in the list.
   * Calling front on an empty list causes undefined behavior.
   *
   * @return reference Reference to the first element.
   */
  reference front() {
    // _LIBCPP_ASSERT_VALID_ELEMENT_ACCESS(!empty(), "list::front called on empty list");
    return base::m_end.m_next->as_node()->get_value();
  }

  /**
   * @brief Returns a constant reference to the first element in the list.
   *
   * @return const_reference Constant reference to the first element.
   */
  const_reference front() const {
    // _LIBCPP_ASSERT_VALID_ELEMENT_ACCESS(!empty(), "list::front called on empty list");
    return base::m_end.m_next->as_node()->get_value();
  }

  /**
   * @brief Returns a reference to the last element in the list.
   *
   * @return reference Reference to the last element.
   */
  reference back() {
    // _LIBCPP_ASSERT_VALID_ELEMENT_ACCESS(!empty(), "list::back called on empty list");
    return base::m_end.m_prev->as_node()->get_value();
  }

  /**
   * @brief Returns a constant reference to the last element in the list.
   *
   * @return const_reference Constant reference to the last element.
   */
  const_reference back() const {
    // _LIBCPP_ASSERT_VALID_ELEMENT_ACCESS(!empty(), "list::back called on empty list");
    return base::m_end.m_prev->as_node()->get_value();
  }

  /**
   * @brief Prepends the given element 'value' to the beginning of the list.
   * No iterators or references are invalidated. Strong exception safety guarantee.
   *
   * @param value The value of the element to prepend.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> push_front(value_type const &value);

  /**
   * @brief Prepends the given element 'value' to the beginning of the list.
   * No iterators or references are invalidated. Strong exception safety guarantee.
   *
   * @param value The value of the element to prepend.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> push_front(value_type &&value);

  /**
   * @brief Appends the given element 'value' to the end of the list.
   * The new element is initialized as a copy of 'value'.
   * No iterators or references are invalidated. Strong exception safety guarantee.
   *
   * @param value The value of the element to append.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> push_back(value_type const &value);

  /**
   * @brief Appends the given element value to the end of the list.
   * 'value' is moved into the new element.
   * No iterators or references are invalidated. Strong exception safety guarantee.
   * @param value The value of the element to append.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> push_back(value_type &&value);

  /**
   * @brief Inserts a new element to the beginning of the list. The element is constructed through
   * ::allocator_traits::construct, which typically uses placement-new to construct the element in-place at the
   * location provided by the list. The arguments args... are forwarded to the constructor as
   * ::forward<Args>(args)....
   * No iterators or references are invalidated. Strong exception safety guarantee.
   *
   * @tparam t_args
   * @param args Arguments to forward to the constructor of the element.
   * @return ::portable_stl::expected<reference_wrap, ::portable_stl::portable_stl_error> A reference wrapper to the
   * inserted element.
   */
  template<class... t_args>
  ::portable_stl::expected<reference_wrap, ::portable_stl::portable_stl_error> emplace_front(t_args &&...args);

  /**
   * @brief Appends a new element to the end of the list. The element is constructed through
   * ::allocator_traits::construct, which typically uses placement-new to construct the element in-place at the
   * location provided by the list. The arguments args... are forwarded to the constructor as
   * ::forward<Args>(args)....
   * No iterators or references are invalidated. Strong exception safety guarantee.
   *
   * @tparam t_args
   * @param args Arguments to forward to the constructor of the element.
   * @return ::portable_stl::expected<reference_wrap, ::portable_stl::portable_stl_error> A reference wrapper to the
   * inserted element.
   */
  template<class... t_args>
  ::portable_stl::expected<reference_wrap, ::portable_stl::portable_stl_error> emplace_back(t_args &&...args);

  /**
   * @brief Inserts a new element into the list directly before pos. The element is constructed through
   * ::allocator_traits::construct, which uses placement-new to construct the element in-place at a location provided
   * by the list. The arguments args... are forwarded to the constructor as ::forward<Args>(args).... args...
   * may directly or indirectly refer to a value in the list.
   * No iterators or references are invalidated. Strong exception safety guarantee.
   *
   * @tparam t_args
   * @param pos Iterator before which the new element will be constructed.
   * @param args Arguments to forward to the constructor of the element.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> Iterator pointing to the emplaced
   * element.
   */
  template<class... t_args>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> emplace(const_iterator pos, t_args &&...args);

  /**
   * @brief Inserts a copy of value before pos in the list.
   * No iterators or references are invalidated. Strong exception safety guarantee.
   *
   * @param pos Iterator before which the content will be inserted (pos may be the end() iterator).
   * @param valus element value to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> Iterator pointing to the inserted
   * value.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(const_iterator    pos,
                                                                                value_type const &valus);

  /**
   * @brief Inserts 'value' before pos in the list, possibly using move semantics.
   * No iterators or references are invalidated. Strong exception safety guarantee.
   *
   * @param pos Iterator before which the content will be inserted (pos may be the end() iterator).
   * @param value Element value to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> Iterator pointing to the inserted
   * value.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(const_iterator pos, value_type &&value);

  /**
   * @brief Inserts count copies of the value before pos in the list.
   * No iterators or references are invalidated. Strong exception safety guarantee.
   *
   * @param pos Iterator before which the content will be inserted (pos may be the end() iterator).
   * @param num Number of elements to insert.
   * @param value Element value to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> Iterator pointing to the first
   * element inserted, or pos if 'num' == 0.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(
    const_iterator pos, size_type num, value_type const &value);

  /**
   * @brief Inserts elements from range [first, last) before pos in the list.
   * No iterators or references are invalidated. Strong exception safety guarantee.
   *
   * @tparam t_input_iterator Qualifies as LegacyInputIterator.
   * @param pos Iterator before which the content will be inserted (pos may be the end() iterator).
   * @param first The range of elements to insert, cannot be iterators into list for which insert is called.
   * @param last The range of elements to insert, cannot be iterators into list for which insert is called.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> Iterator pointing to the first
   * element inserted, or pos if 'first' == 'last'.
   */
  template<class t_input_iterator>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(
    const_iterator   pos,
    t_input_iterator first,
    t_input_iterator last,
    ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>
    = nullptr);

  /**
   * @brief Inserts elements from initializer list 'init_list' before pos in the list.
   * No iterators or references are invalidated. Strong exception safety guarantee.
   *
   * @param pos iterator before which the content will be inserted (pos may be the end() iterator).
   * @param init_list Initializer list to insert the values from.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> Iterator pointing to the first
   * element inserted, or pos if 'init_list' is empty.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(
    const_iterator pos, std::initializer_list<value_type> init_list) {
    return insert(pos, init_list.begin(), init_list.end());
  }

  /**
   * @brief Exchanges the contents of the list with those of other. Does not invoke any move, copy, or swap
   * operations on individual elements.
   * All iterators and references remain valid. It is unspecified whether an iterator holding the end() value in this
   * list will refer to this or the other list after the operation.
   *
   * @param other List to exchange the contents with.
   */
  void swap(list &other) noexcept {
    base::swap(other);
  }

  /**
   * @brief Erases all elements from the list. After this call, size() returns zero.
   * Invalidates any references, pointers, and iterators referring to contained elements. Any past-the-end iterator
   * remains valid.
   *
   */
  void clear() noexcept {
    base::clear();
  }

  /**
   * @brief Removes the first element of the list.
   * If there are no elements in the list, the behavior is undefined.
   *
   */
  void pop_front();

  /**
   * @brief Removes the last element of the list.
   * Calling pop_back on an empty list results in undefined behavior.
   *
   */
  void pop_back();

  /**
   * @brief Removes the element at pos from the list.
   *
   * @param pos Iterator to the element to remove.
   * @return iterator If 'pos' refers to the last element, then the end() iterator is returned.
   */
  iterator erase(const_iterator pos);

  /**
   * @brief Removes the elements in the range [first, last) from the list.
   *
   * @param first Range of elements to remove.
   * @param last Range of elements to remove.
   * @return iterator If 'last' == end() prior to removal, then the updated end() iterator is returned. If [first, last)
   * is an empty range, then 'last' is returned.
   */
  iterator erase(const_iterator first, const_iterator last);

  /**
   * @brief Resizes the list to contain 'num' elements, does nothing if 'num' == size().
   * If the current size is greater than 'num', the list is reduced to its first count elements. If the current
   * size is less than num, additional default-inserted elements are appended.
   *
   * @param num New size of the list.
   * @return true If success,
   * @return false otherwise.
   */
  bool resize(size_type num);

  /**
   * @brief Resizes the list to contain 'num' elements, does nothing if 'num' == size().
   * If the current size is greater than 'num', the list is reduced to its first count elements. If the current
   * size is less than num, additional copies of 'value' are appended.
   *
   * @param num New size of the list.
   * @param value The value to initialize the new elements with.
   * @return true If success,
   * @return false otherwise.
   */
  bool resize(size_type num, value_type const &value);

  /**
   * @brief Transfers all elements from 'other_list' into *this. The elements are inserted before the element pointed to
   * by 'pos'. The list 'other_list' becomes empty after the operation.
   *
   * @param pos Element before which the content will be inserted.
   * @param other_list Another list to transfer the content from.
   */
  void splice(const_iterator pos, list &other_list);

  /**
   * @brief Transfers all elements from 'other_list' into *this. The elements are inserted before the element pointed to
   * by 'pos'. The list 'other_list' becomes empty after the operation.
   *
   * @param pos Element before which the content will be inserted.
   * @param other_list Another list to transfer the content from.
   */
  void splice(const_iterator pos, list &&other_list) {
    splice(pos, other_list);
  }

  /**
   * @brief Transfers the element pointed to by 'iter' from 'other_list' into *this. The element is inserted before the
   * element pointed to by 'pos'.
   *
   * @param pos Element before which the content will be inserted.
   * @param other_list Another list to transfer the content from.
   * @param iter The element to transfer from other to *this.
   */
  void splice(const_iterator pos, list &other_list, const_iterator iter);

  /**
   * @brief Transfers the element pointed to by 'iter' from 'other_list' into *this. The element is inserted before the
   * element pointed to by 'pos'.
   *
   * @param pos Element before which the content will be inserted.
   * @param other_list Another list to transfer the content from.
   * @param iter The element to transfer from other to *this.
   */
  void splice(const_iterator pos, list &&other_list, const_iterator iter) {
    splice(pos, other_list, iter);
  }

  /**
   * @brief Transfers the elements in the range [first, last) from 'other_list' into *this. The elements are inserted
   * before the element pointed to by 'pos'.
   *
   * @param pos Element before which the content will be inserted.
   * @param other_list Another list to transfer the content from.
   * @param first The range of elements to transfer from 'other_list' to *this.
   * @param last The range of elements to transfer from 'other_list' to *this.
   */
  void splice(const_iterator pos, list &other_list, const_iterator first, const_iterator last);

  /**
   * @brief Transfers the elements in the range [first, last) from 'other_list' into *this. The elements are inserted
   * before the element pointed to by 'pos'.
   *
   * @param pos Element before which the content will be inserted.
   * @param other_list Another list to transfer the content from.
   * @param first The range of elements to transfer from 'other_list' to *this.
   * @param last The range of elements to transfer from 'other_list' to *this.
   */
  void splice(const_iterator pos, list &&other_list, const_iterator first, const_iterator last) {
    splice(pos, other_list, first, last);
  }

  /**
   * @brief Removes all elements that are equal to 'value' (using operator==).
   *
   * @param value Value of the elements to remove.
   * @return remove_return_type The number of elements removed.
   */
  remove_return_type remove(value_type const &value);

  /**
   * @brief Removes all elements for which predicate 'pred' returns true.
   *
   * @tparam t_pred The expression t_pred(v) must be convertible to bool for every argument v of type (possibly const)
   * t_type.
   * @param pred Unary predicate which returns ​true if the element should be removed.
   * @return remove_return_type The number of elements removed.
   */
  template<class t_pred> remove_return_type remove_if(t_pred pred);

  /**
   * @brief Removes all consecutive duplicate elements from the list. Only the first element in each group of equal
   * elements is left. Invalidates only the iterators and references to the removed elements.
   * Uses operator== to compare the elements.
   *
   * @return remove_return_type The number of elements removed.
   */
  remove_return_type unique() {
    return unique(::portable_stl::equal_to<value_type>());
  }

  /**
   * @brief Removes all consecutive duplicate elements from the list. Only the first element in each group of equal
   * elements is left. Invalidates only the iterators and references to the removed elements.
   * Uses 'binary_pred' to compare the elements.
   *
   * @tparam t_binary_pred The signature of the predicate function should be equivalent to the following: bool
   * pred(const Type1 &a, const Type2 &b);
   * @param binary_pred Binary predicate which returns ​true if the elements should be treated as equal.
   * @return remove_return_type The number of elements removed.
   */
  template<class t_binary_pred> remove_return_type unique(t_binary_pred binary_pred);

  /**
   * @brief Merges 'other_list' into *this. Both lists should be sorted. No elements are copied, and the list
   * 'other_list' becomes empty after the merge. This operation is stable: for equivalent elements in the two lists, the
   * elements from *this always precede the elements from 'other_list', and the order of equivalent elements of *this
   * and other does not change.
   * No iterators or references become invalidated. The pointers and references to the elements moved from *this, as
   * well as the iterators referring to these elements, will refer to the same elements of *this, instead of
   * 'other_list'.
   * Elements are compared using ::less<t_type>();
   *
   * @param other_list Another list to merge.
   */
  void merge(list &other_list);

  /**
   * @brief Merges 'other_list' into *this. Both lists should be sorted. No elements are copied, and the list
   * 'other_list' becomes empty after the merge. This operation is stable: for equivalent elements in the two lists, the
   * elements from *this always precede the elements from 'other_list', and the order of equivalent elements of *this
   * and other does not change.
   * No iterators or references become invalidated. The pointers and references to the elements moved from *this, as
   * well as the iterators referring to these elements, will refer to the same elements of *this, instead of
   * 'other_list'.
   * Elements are compared using ::less<t_type>();
   *
   * @param other_list Another list to merge.
   */
  void merge(list &&other_list) {
    merge(other_list);
  }

  /**
   * @brief Merges 'other_list' into *this. Both lists should be sorted. No elements are copied, and the list
   * 'other_list' becomes empty after the merge. This operation is stable: for equivalent elements in the two lists, the
   * elements from *this always precede the elements from 'other_list', and the order of equivalent elements of *this
   * and other does not change.
   * No iterators or references become invalidated. The pointers and references to the elements moved from *this, as
   * well as the iterators referring to these elements, will refer to the same elements of *this, instead of
   * 'other_list'.
   * Elements are compared using 'comp'.
   *
   * @tparam t_comp The signature of the comparison function should be equivalent to the following: bool cmp(const
   * Type1& a, const Type2& b);
   * @param other_list Another list to merge.
   * @param comp Comparison function object (i.e. an object that satisfies the requirements of Compare) which returns
   * ​true if the first argument is less than (i.e. is ordered before) the second.
   */
  template<class t_comp> void merge(list &&other_list, t_comp comp) {
    merge(other_list, comp);
  }

  /**
   * @brief Merges 'other_list' into *this. Both lists should be sorted. No elements are copied, and the list
   * 'other_list' becomes empty after the merge. This operation is stable: for equivalent elements in the two lists, the
   * elements from *this always precede the elements from 'other_list', and the order of equivalent elements of *this
   * and other does not change.
   * No iterators or references become invalidated. The pointers and references to the elements moved from *this, as
   * well as the iterators referring to these elements, will refer to the same elements of *this, instead of
   * 'other_list'.
   * Elements are compared using 'comp'.
   *
   * @tparam t_comp The signature of the comparison function should be equivalent to the following: bool cmp(const
   * Type1& a, const Type2& b);
   * @param other_list Another list to merge.
   * @param comp Comparison function object (i.e. an object that satisfies the requirements of Compare) which returns
   * ​true if the first argument is less than (i.e. is ordered before) the second.
   */
  template<class t_comp> void merge(list &other_list, t_comp comp);

  /**
   * @brief Sorts the elements and preserves the order of equivalent elements. No references or iterators become
   * invalidated.
   * Elements are compared using operator<.
   * If an exception is thrown, the order of elements in *this is unspecified.
   */
  void sort();

  /**
   * @brief Sorts the elements and preserves the order of equivalent elements. No references or iterators become
   * invalidated.
   * Elements are compared using comp.
   * If an exception is thrown, the order of elements in *this is unspecified.
   *
   * @tparam t_comp The signature of the comparison function should be equivalent to the following: bool cmp(const
   * Type1& a, const Type2& b);
   * @param comp Comparison function object (i.e. an object that satisfies the requirements of Compare) which returns
   * ​true if the first argument is less than (i.e. is ordered before) the second.
   */
  template<class t_comp> void sort(t_comp comp);

  /**
   * @brief Reverses the order of the elements in the list. No references or iterators become invalidated.
   *
   */
  void reverse() noexcept;

private:
  template<class t_arg>::portable_stl::expected<void, ::portable_stl::portable_stl_error> M_emplace_back(t_arg &&arg) {
    return emplace_back(::portable_stl::forward<t_arg>(arg)).transform_void();
  }

  template<class t_iterator, class t_sentinel>
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> M_assign_with_sentinel(t_iterator first,
                                                                                            t_sentinel last);

  template<class t_iterator, class t_sentinel>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> M_insert_with_sentinel(
    const_iterator pos, t_iterator first, t_sentinel last);

  static void M_link_nodes(t_link_pointer ptr, t_link_pointer first, t_link_pointer last);
  void        M_link_nodes_at_front(t_link_pointer first, t_link_pointer last);
  void        M_link_nodes_at_back(t_link_pointer first, t_link_pointer last);
  iterator    M_iterator(size_type num);

  template<class t_comp> static iterator M_sort(iterator first1, iterator end2, size_type num, t_comp &comp);

  void move_assign(list &other_transformations_helper,
                   true_type) noexcept(::portable_stl::is_nothrow_move_assignable<t_node_allocator>{}());
  void move_assign(list &other, false_type);
};

// Link in nodes [first, last] just prior to ptr
template<class t_type, class t_allocator>
inline void list<t_type, t_allocator>::M_link_nodes(t_link_pointer ptr, t_link_pointer first, t_link_pointer last) {
  ptr->m_prev->m_next = first;
  first->m_prev       = ptr->m_prev;
  ptr->m_prev         = last;
  last->m_next        = ptr;
}

// Link in nodes [first, last] at the front of the list
template<class t_type, class t_allocator>
inline void list<t_type, t_allocator>::M_link_nodes_at_front(t_link_pointer first, t_link_pointer last) {
  first->m_prev        = base::end_as_link();
  last->m_next         = base::m_end.m_next;
  last->m_next->m_prev = last;
  base::m_end.m_next   = first;
}

// Link in nodes [first, last] at the back of the list
template<class t_type, class t_allocator>
inline void list<t_type, t_allocator>::M_link_nodes_at_back(t_link_pointer first, t_link_pointer last) {
  last->m_next          = base::end_as_link();
  first->m_prev         = base::m_end.m_prev;
  first->m_prev->m_next = first;
  base::m_end.m_prev    = last;
}

template<class t_type, class t_allocator>
inline typename list<t_type, t_allocator>::iterator list<t_type, t_allocator>::M_iterator(size_type num) {
  return num <= (base::size_val() / 2)
         ? ::portable_stl::next(begin(),
                                static_cast<typename ::portable_stl::iterator_traits<iterator>::difference_type>(num))
         : ::portable_stl::prev(
             end(),
             static_cast<typename ::portable_stl::iterator_traits<iterator>::difference_type>(base::size_val() - num));
}

// (3a)
template<class t_type, class t_allocator> list<t_type, t_allocator>::list(size_type num, value_type const &value) {
  for (; num > 0; --num) {
    auto result = push_back(value);
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!result);
  }
}

// static
template<class t_type, class t_allocator>
::portable_stl::expected<list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::make_list(size_type num, value_type const &value) {
  list lst;
  for (; num > 0; --num) {
    auto result = lst.push_back(value);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
  }
  return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>(::portable_stl::move(lst));
}

// (3b)
template<class t_type, class t_allocator>
template<class>
list<t_type, t_allocator>::list(size_type num, value_type const &value, allocator_type const &alloc) : base(alloc) {
  for (; num > 0; --num) {
    auto result = push_back(value);
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!result);
  }
}

// static
template<class t_type, class t_allocator>
template<class>
::portable_stl::expected<list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::make_list(size_type num, value_type const &value, allocator_type const &alloc) {
  list lst(alloc);
  for (; num > 0; --num) {
    auto result = lst.push_back(value);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
  }
  return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>(::portable_stl::move(lst));
}

// (4a)
template<class t_type, class t_allocator> list<t_type, t_allocator>::list(size_type num) {
  for (; num > 0; --num) {
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!emplace_back());
  }
}

template<class t_type, class t_allocator>
::portable_stl::expected<list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::make_list(size_type num) {
  list lst;
  for (; num > 0; --num) {
    auto result = lst.emplace_back();
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
  }
  return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>(::portable_stl::move(lst));
}

// (4b)
template<class t_type, class t_allocator>
list<t_type, t_allocator>::list(size_type num, allocator_type const &alloc) : base(alloc) {
  for (; num > 0; --num) {
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!emplace_back());
  }
}

template<class t_type, class t_allocator>
::portable_stl::expected<list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::make_list(size_type num, allocator_type const &alloc) {
  list lst(alloc);
  for (; num > 0; --num) {
    auto result = lst.emplace_back();
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
  }
  return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>(::portable_stl::move(lst));
}

// (5a)
template<class t_type, class t_allocator>
template<class t_input_iterator>
list<t_type, t_allocator>::list(
  t_input_iterator first,
  t_input_iterator last,
  ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>) {
  for (; first != last; ++first) {
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!M_emplace_back(*first));
  }
}

// static
template<class t_type, class t_allocator>
template<class t_input_iterator>
::portable_stl::expected<list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::make_list(
    t_input_iterator first,
    t_input_iterator last,
    ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>) {
  list lst;
  for (; first != last; ++first) {
    auto result = lst.M_emplace_back(*first);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
  }
  return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>(::portable_stl::move(lst));
}

// (5b)
template<class t_type, class t_allocator>
template<class t_input_iterator>
list<t_type, t_allocator>::list(
  t_input_iterator      first,
  t_input_iterator      last,
  allocator_type const &alloc,
  ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>)
    : base(alloc) {
  for (; first != last; ++first) {
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!M_emplace_back(*first));
  }
}

// static
template<class t_type, class t_allocator>
template<class t_input_iterator>
::portable_stl::expected<list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::make_list(
    t_input_iterator      first,
    t_input_iterator      last,
    allocator_type const &alloc,
    ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>) {
  list lst(alloc);
  for (; first != last; ++first) {
    auto result = lst.M_emplace_back(*first);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
  }
  return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>(::portable_stl::move(lst));
}

// (6)
template<class t_type, class t_allocator>
list<t_type, t_allocator>::list(list const &other)
    : base(t_node_alloc_traits::select_on_container_copy_construction(other.node_alloc())) {
  for (const_iterator iter = other.begin(), end_iter = other.end(); iter != end_iter; ++iter) {
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!push_back(*iter));
  }
}

// static
template<class t_type, class t_allocator>
::portable_stl::expected<list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::make_list(list const &other) {
  list lst(t_node_alloc_traits::select_on_container_copy_construction(other.node_alloc()));
  for (const_iterator iter = other.begin(), end_iter = other.end(); iter != end_iter; ++iter) {
    auto result = lst.push_back(*iter);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
  }
  return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>(::portable_stl::move(lst));
}

// (7)
template<class t_type, class t_allocator>
list<t_type, t_allocator>::list(list const &other, ::portable_stl::type_identity_t<allocator_type> const &alloc)
    : base(alloc) {
  for (const_iterator iter = other.begin(), end_iter = other.end(); iter != end_iter; ++iter) {
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!push_back(*iter));
  }
}

// static
template<class t_type, class t_allocator>
::portable_stl::expected<list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::make_list(list const                                            &other,
                                       ::portable_stl::type_identity_t<allocator_type> const &alloc) {
  list lst(alloc);
  for (const_iterator iter = other.begin(), end_iter = other.end(); iter != end_iter; ++iter) {
    auto result = lst.push_back(*iter);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
  }
  return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>(::portable_stl::move(lst));
}

// (8)
template<class t_type, class t_allocator>
inline list<t_type, t_allocator>::list(list &&other) noexcept(
  ::portable_stl::is_nothrow_move_constructible<t_node_allocator>{}())
    : base(::portable_stl::move(other.node_alloc())) {
  splice(end(), other);
}

// (9)
template<class t_type, class t_allocator>
inline list<t_type, t_allocator>::list(list &&other, ::portable_stl::type_identity_t<allocator_type> const &alloc)
    : base(alloc) {
  if (alloc == other.get_allocator()) {
    splice(end(), other);
  } else {
    using move_iter = ::portable_stl::move_iterator<iterator>;
    auto result     = assign(move_iter(other.begin()), move_iter(other.end()));
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!result);
  }
}

// static
template<class t_type, class t_allocator>
::portable_stl::expected<list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::make_list(list &&other, ::portable_stl::type_identity_t<allocator_type> const &alloc) {
  list lst(alloc);
  if (alloc == other.get_allocator()) {
    lst.splice(lst.end(), other);
  } else {
    using move_iter = ::portable_stl::move_iterator<iterator>;
    auto result     = lst.assign(move_iter(other.begin()), move_iter(other.end()));
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
  }
  return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>(::portable_stl::move(lst));
}

// (10a)
template<class t_type, class t_allocator> list<t_type, t_allocator>::list(std::initializer_list<value_type> init_list) {
  for (typename initializer_list<value_type>::const_iterator iter = init_list.begin(), end_iter = init_list.end();
       iter != end_iter;
       ++iter) {
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!push_back(*iter));
  }
}

// static
template<class t_type, class t_allocator>
::portable_stl::expected<list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::make_list(std::initializer_list<value_type> init_list) {
  list lst;
  for (typename initializer_list<value_type>::const_iterator iter = init_list.begin(), end_iter = init_list.end();
       iter != end_iter;
       ++iter) {
    auto result = lst.push_back(*iter);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
  }
  return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>(::portable_stl::move(lst));
}

// (10b)
template<class t_type, class t_allocator>
list<t_type, t_allocator>::list(std::initializer_list<value_type> init_list, allocator_type const &alloc)
    : base(alloc) {
  for (typename initializer_list<value_type>::const_iterator iter = init_list.begin(), end_iter = init_list.end();
       iter != end_iter;
       ++iter) {
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!push_back(*iter));
  }
}

// static
template<class t_type, class t_allocator>
::portable_stl::expected<list<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::make_list(std::initializer_list<value_type> init_list, allocator_type const &alloc) {
  list lst(alloc);
  for (typename initializer_list<value_type>::const_iterator iter = init_list.begin(), end_iter = init_list.end();
       iter != end_iter;
       ++iter) {
    auto result = lst.push_back(*iter);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
  }
  return ::portable_stl::expected<list, ::portable_stl::portable_stl_error>(::portable_stl::move(lst));
}

template<class t_type, class t_allocator>
inline list<t_type, t_allocator> &list<t_type, t_allocator>::operator=(list &&other) noexcept(
  typename t_node_alloc_traits::propagate_on_container_move_assignment{}()
  && ::portable_stl::is_nothrow_move_assignable<t_node_allocator>{}()) {
  move_assign(other, typename t_node_alloc_traits::propagate_on_container_move_assignment{});
  return *this;
}

template<class t_type, class t_allocator>
void list<t_type, t_allocator>::move_assign(list &other, ::portable_stl::false_type) {
  if (base::node_alloc() != other.node_alloc()) {
    using move_iter = ::portable_stl::move_iterator<iterator>;
    assign(move_iter(other.begin()), move_iter(other.end()));
  } else {
    move_assign(other, ::portable_stl::true_type{});
  }
}

template<class t_type, class t_allocator>
void list<t_type, t_allocator>::move_assign(list &other, ::portable_stl::true_type) noexcept(
  ::portable_stl::is_nothrow_move_assignable<t_node_allocator>{}()) {
  clear();
  base::move_assign_alloc(other);
  splice(end(), other);
}

template<class t_type, class t_allocator>
inline list<t_type, t_allocator> &list<t_type, t_allocator>::operator=(list const &other) {
  if (this != ::portable_stl::addressof(other)) {
    base::copy_assign_alloc(other);
    assign(other.begin(), other.end());
  }
  return *this;
}

template<class t_type, class t_allocator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> list<t_type, t_allocator>::assign(
  size_type num, value_type const &value) {
  iterator iter{begin()};
  iterator end_iter{end()};
  for (; (num > 0) && (iter != end_iter); --num, (void)++iter) {
    *iter = value;
  }

  if (iter == end_iter) {
    auto result = insert(end_iter, num, value);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
  } else {
    erase(iter, end_iter);
  }
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

template<class t_type, class t_allocator>
template<class t_iterator, class t_sentinel>
::portable_stl::expected<typename list<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::M_insert_with_sentinel(const_iterator pos, t_iterator first, t_sentinel last) {
  iterator ret(pos.m_ptr);
  if (first != last) {
    size_type count_created_node{0U};
    auto      result = this->create_node(/* prev = */ nullptr, /* next = */ nullptr, *first);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
    auto new_node = portable_stl::move(result.value());
    ++count_created_node;
    ret                       = iterator(new_node->as_link());
    iterator iter_to_last_new = ret;

    auto guard = ::portable_stl::make_exception_guard([this, &iter_to_last_new]() {
      while (true) {
        t_link_pointer prev_link = iter_to_last_new.m_ptr->m_prev;

        // delete value of the node
        t_node_pointer node_current = iter_to_last_new.m_ptr->as_node();
        this->delete_node(node_current);

        if (0 == prev_link) {
          break;
        }
        iter_to_last_new = iterator(prev_link);
      }
    });

    for (++first; first != last; ++first, (void)++iter_to_last_new, ++count_created_node) {
      result = this->create_node(/* prev = */ iter_to_last_new.m_ptr, /* next = */ nullptr, *first);
      if (!result) {
        return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
      }
      iter_to_last_new.m_ptr->m_next = ::portable_stl::move(result.value())->as_link();
    }

    guard.commit();

    M_link_nodes(pos.m_ptr, ret.m_ptr, iter_to_last_new.m_ptr);
    base::size_val() += count_created_node;
  }
  return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>(::portable_stl::move(ret));
}

template<class t_type, class t_allocator>
template<class t_iterator, class t_sentinel>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> list<t_type, t_allocator>::M_assign_with_sentinel(
  t_iterator first, t_sentinel last) {
  iterator iter{begin()};
  iterator end_iter{end()};
  for (; (first != last) && (iter != end_iter); ++first, (void)++iter) {
    *iter = *first;
  }

  if (iter == end_iter) {
    auto result = M_insert_with_sentinel(end_iter, ::portable_stl::move(first), ::portable_stl::move(last));
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
  } else {
    erase(iter, end_iter);
  }
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

template<class t_type, class t_allocator>
template<class t_input_iterator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> list<t_type, t_allocator>::assign(
  t_input_iterator first,
  t_input_iterator last,
  ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>) {
  return M_assign_with_sentinel(first, last).transform_void();
}

template<class t_type, class t_allocator> inline t_allocator list<t_type, t_allocator>::get_allocator() const noexcept {
  return allocator_type(base::node_alloc());
}

// (1)
template<class t_type, class t_allocator>
::portable_stl::expected<typename list<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::insert(const_iterator pos, value_type const &value) {
  return this->create_node(/* prev = */ nullptr, /* next = */ nullptr, value)
    .and_then([this, &pos](t_node_pointer const &tmp_node_pointer)
                -> ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> {
      t_link_pointer node_link{tmp_node_pointer->as_link()};
      M_link_nodes(pos.m_ptr, node_link, node_link);
      ++base::size_val();
      return {::portable_stl::in_place_t{}, iterator(node_link)};
    });
}

// (2)
template<class t_type, class t_allocator>
::portable_stl::expected<typename list<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::insert(const_iterator pos, value_type &&value) {
  return this->create_node(/* prev = */ nullptr, /* next = */ nullptr, ::portable_stl::move(value))
    .and_then([this, &pos](t_node_pointer const &tmp_node_pointer)
                -> ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> {
      t_link_pointer node_link{tmp_node_pointer->as_link()};
      M_link_nodes(pos.m_ptr, node_link, node_link);
      ++base::size_val();
      return {::portable_stl::in_place_t{}, iterator(node_link)};
    });
}

// (3)
template<class t_type, class t_allocator>
::portable_stl::expected<typename list<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::insert(const_iterator pos, size_type num, value_type const &value) {
  iterator ret(pos.m_ptr);
  if (num > 0) {
    size_type count_created_node{0U};
    auto      result = this->create_node(/* prev = */ nullptr, /* next = */ nullptr, value);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
    auto new_node = portable_stl::move(result.value());
    ++count_created_node;
    ret                       = iterator(new_node->as_link());
    iterator iter_to_last_new = ret;

    auto guard = ::portable_stl::make_exception_guard([this, &iter_to_last_new]() {
      while (true) {
        t_link_pointer prev_link = iter_to_last_new.m_ptr->m_prev;

        // delete value of the node
        t_node_pointer node_current = iter_to_last_new.m_ptr->as_node();
        this->delete_node(node_current);

        if (0 == prev_link) {
          break;
        }
        iter_to_last_new = iterator(prev_link);
      }
    });

    for (--num; num != 0U; --num, (void)++iter_to_last_new, ++count_created_node) {
      result = this->create_node(/* prev = */ iter_to_last_new.m_ptr, /* next = */ nullptr, value);
      if (!result) {
        return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
      }
      iter_to_last_new.m_ptr->m_next = ::portable_stl::move(result.value())->as_link();
    }

    guard.commit();

    M_link_nodes(pos.m_ptr, ret.m_ptr, iter_to_last_new.m_ptr);
    base::size_val() += count_created_node;
  }
  return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>(::portable_stl::move(ret));
}

// (4)
template<class t_type, class t_allocator>
template<class t_input_iterator>
::portable_stl::expected<typename list<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::insert(
    const_iterator   pos,
    t_input_iterator first,
    t_input_iterator last,
    ::portable_stl::enable_if_bool_constant_t<::portable_stl::has_input_iterator_category<t_input_iterator>, void *>) {
  return M_insert_with_sentinel(pos, first, last);
}

template<class t_type, class t_allocator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> list<t_type, t_allocator>::push_front(
  value_type const &value) {
  return this->create_node(/* prev = */ nullptr, /* next = */ nullptr, value)
    .and_then(
      [this](
        t_node_pointer const &tmp_node_pointer) -> ::portable_stl::expected<void, ::portable_stl::portable_stl_error> {
        t_link_pointer node_link{tmp_node_pointer->as_link()};
        M_link_nodes_at_front(node_link, node_link);
        ++base::size_val();
        return {};
      })
    .transform_void();
}

template<class t_type, class t_allocator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> list<t_type, t_allocator>::push_front(
  value_type &&value) {
  return this->create_node(/* prev = */ nullptr, /* next = */ nullptr, ::portable_stl::move(value))
    .and_then(
      [this](
        t_node_pointer const &tmp_node_pointer) -> ::portable_stl::expected<void, ::portable_stl::portable_stl_error> {
        t_link_pointer node_link{tmp_node_pointer->as_link()};
        M_link_nodes_at_front(node_link, node_link);
        ++base::size_val();
        return {};
      })
    .transform_void();
}

template<class t_type, class t_allocator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> list<t_type, t_allocator>::push_back(
  value_type const &value) {
  return this->create_node(/* prev = */ nullptr, /* next = */ nullptr, value)
    .and_then(
      [this](
        t_node_pointer const &tmp_node_pointer) -> ::portable_stl::expected<void, ::portable_stl::portable_stl_error> {
        t_link_pointer node_link{tmp_node_pointer->as_link()};
        M_link_nodes_at_back(node_link, node_link);
        ++base::size_val();
        return {};
      })
    .transform_void();
}

template<class t_type, class t_allocator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> list<t_type, t_allocator>::push_back(
  value_type &&value) {
  return this->create_node(/* prev = */ nullptr, /* next = */ nullptr, ::portable_stl::move(value))
    .and_then(
      [this](
        t_node_pointer const &tmp_node_pointer) -> ::portable_stl::expected<void, ::portable_stl::portable_stl_error> {
        t_link_pointer node_link{tmp_node_pointer->as_link()};
        M_link_nodes_at_back(node_link, node_link);
        ++base::size_val();
        return {};
      })
    .transform_void();
}

template<class t_type, class t_allocator>
template<class... t_args>
::portable_stl::expected<typename list<t_type, t_allocator>::reference_wrap, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::emplace_front(t_args &&...args) {
  return this->create_node(/* prev = */ nullptr, /* next = */ nullptr, ::portable_stl::forward<t_args>(args)...)
    .transform([this](t_node_pointer const &tmp_node_pointer) -> reference_wrap {
      t_link_pointer node_link{tmp_node_pointer->as_link()};
      M_link_nodes_at_front(node_link, node_link);
      ++base::size_val();
      return ::portable_stl::ref<value_type>(tmp_node_pointer->get_value());
    });
}

template<class t_type, class t_allocator>
template<class... t_args>
::portable_stl::expected<typename list<t_type, t_allocator>::reference_wrap, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::emplace_back(t_args &&...args) {
  return this->create_node(/* prev = */ nullptr, /* next = */ nullptr, ::portable_stl::forward<t_args>(args)...)
    .transform([this](t_node_pointer const &tmp_node_pointer) -> reference_wrap {
      t_link_pointer node_link{tmp_node_pointer->as_link()};
      M_link_nodes_at_back(node_link, node_link);
      ++base::size_val();
      return ::portable_stl::ref<value_type>(tmp_node_pointer->get_value());
    });
}

template<class t_type, class t_allocator>
template<class... t_args>
::portable_stl::expected<typename list<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  list<t_type, t_allocator>::emplace(const_iterator pos, t_args &&...args) {
  return this->create_node(/* prev = */ nullptr, /* next = */ nullptr, ::portable_stl::forward<t_args>(args)...)
    .transform([this, &pos](t_node_pointer const &tmp_node_pointer) -> iterator {
      t_link_pointer node_link{tmp_node_pointer->as_link()};
      M_link_nodes(pos.m_ptr, node_link, node_link);
      ++base::size_val();
      return iterator(node_link);
    });
}

template<class t_type, class t_allocator> void list<t_type, t_allocator>::pop_front() {
  t_link_pointer node_link = base::m_end.m_next;
  base::unlink_nodes(node_link, node_link);
  --base::size_val();
  this->delete_node(node_link->as_node());
}

template<class t_type, class t_allocator> void list<t_type, t_allocator>::pop_back() {
  t_link_pointer node_link = base::m_end.m_prev;
  base::unlink_nodes(node_link, node_link);
  --base::size_val();
  this->delete_node(node_link->as_node());
}

template<class t_type, class t_allocator>
typename list<t_type, t_allocator>::iterator list<t_type, t_allocator>::erase(const_iterator pos) {
  t_link_pointer node_link_to_delete = pos.m_ptr;
  t_link_pointer ret                 = node_link_to_delete->m_next;

  base::unlink_nodes(node_link_to_delete, node_link_to_delete);
  --base::size_val();
  this->delete_node(node_link_to_delete->as_node());

  return iterator(ret);
}

template<class t_type, class t_allocator>
typename list<t_type, t_allocator>::iterator list<t_type, t_allocator>::erase(const_iterator first,
                                                                              const_iterator last) {
  if (first != last) {
    base::unlink_nodes(first.m_ptr, last.m_ptr->m_prev);
    while (first != last) {
      t_link_pointer node_link_to_delete = first.m_ptr;
      ++first;
      --base::size_val();
      this->delete_node(node_link_to_delete->as_node());
    }
  }
  return iterator(last.m_ptr);
}

template<class t_type, class t_allocator> bool list<t_type, t_allocator>::resize(size_type new_size) {
  if (new_size < base::size_val()) {
    erase(M_iterator(new_size), end());
  } else if (new_size > base::size_val()) {
    new_size -= base::size_val();
    size_type count_created_node{0U};
    auto      result = this->create_node(/* prev = */ nullptr, /* next = */ nullptr);
    if (!result) {
      return false;
    }
    auto new_node = portable_stl::move(result.value());
    ++count_created_node;
    auto ret              = iterator(new_node->as_link());
    auto iter_to_last_new = ret;

    auto guard = ::portable_stl::make_exception_guard([this, &iter_to_last_new]() {
      while (true) {
        t_link_pointer prev_link = iter_to_last_new.m_ptr->m_prev;

        // delete value of the node
        t_node_pointer node_current = iter_to_last_new.m_ptr->as_node();
        this->delete_node(node_current);

        if (0 == prev_link) {
          break;
        }
        iter_to_last_new = iterator(prev_link);
      }
    });

    for (--new_size; new_size != 0U; --new_size, (void)++iter_to_last_new, ++count_created_node) {
      result = this->create_node(/* prev = */ iter_to_last_new.m_ptr, /* next = */ nullptr);
      if (!result) {
        return false;
      }

      iter_to_last_new.m_ptr->m_next = ::portable_stl::move(result.value())->as_link();
    }

    guard.commit();

    M_link_nodes_at_back(ret.m_ptr, iter_to_last_new.m_ptr);
    base::size_val() += count_created_node;
  }
  return true;
}

template<class t_type, class t_allocator>
bool list<t_type, t_allocator>::resize(size_type new_size, value_type const &value) {
  if (new_size < base::size_val()) {
    erase(M_iterator(new_size), end());
  } else if (new_size > base::size_val()) {
    new_size -= base::size_val();
    size_type count_created_node{0U};
    auto      result = this->create_node(/* prev = */ nullptr, /* next = */ nullptr, value);
    if (!result) {
      return false;
    }
    auto new_node = portable_stl::move(result.value());
    ++count_created_node;
    auto ret              = iterator(new_node->as_link());
    auto iter_to_last_new = ret;

    auto guard = ::portable_stl::make_exception_guard([this, &iter_to_last_new]() {
      while (true) {
        t_link_pointer prev_link = iter_to_last_new.m_ptr->m_prev;

        // delete value of the node
        t_node_pointer node_current = iter_to_last_new.m_ptr->as_node();
        this->delete_node(node_current);

        if (0 == prev_link) {
          break;
        }
        iter_to_last_new = iterator(prev_link);
      }
    });

    for (--new_size; new_size != 0U; --new_size, (void)++iter_to_last_new, ++count_created_node) {
      result = this->create_node(/* prev = */ iter_to_last_new.m_ptr, /* next = */ nullptr, value);
      if (!result) {
        return false;
      }

      iter_to_last_new.m_ptr->m_next = ::portable_stl::move(result.value())->as_link();
    }

    guard.commit();

    M_link_nodes_at_back(ret.m_ptr, iter_to_last_new.m_ptr);
    base::size_val() += count_created_node;
  }
  return true;
}

template<class t_type, class t_allocator> void list<t_type, t_allocator>::splice(const_iterator pos, list &other_list) {
  if (!other_list.empty()) {
    t_link_pointer first = other_list.m_end.m_next;
    t_link_pointer last  = other_list.m_end.m_prev;
    base::unlink_nodes(first, last);
    M_link_nodes(pos.m_ptr, first, last);
    base::size_val() += other_list.size_val();
    other_list.size_val() = 0;
  }
}

template<class t_type, class t_allocator>
void list<t_type, t_allocator>::splice(const_iterator pos, list &other_list, const_iterator iter) {
  if (pos.m_ptr != iter.m_ptr && pos.m_ptr != iter.m_ptr->m_next) {
    t_link_pointer first = iter.m_ptr;
    base::unlink_nodes(first, first);
    M_link_nodes(pos.m_ptr, first, first);
    --other_list.size_val();
    ++base::size_val();
  }
}

template<class t_type, class t_allocator>
void list<t_type, t_allocator>::splice(
  const_iterator pos, list &other_list, const_iterator iter_first, const_iterator iter_last) {
  if (iter_first != iter_last) {
    t_link_pointer first_node_link = iter_first.m_ptr;
    --iter_last;
    t_link_pointer last_node_link = iter_last.m_ptr;
    if (this != ::portable_stl::addressof(other_list)) {
      auto const count = static_cast<size_type>(::portable_stl::distance(iter_first, iter_last) + 1);
      other_list.size_val() -= count;
      base::size_val() += count;
    }
    base::unlink_nodes(first_node_link, last_node_link);
    M_link_nodes(pos.m_ptr, first_node_link, last_node_link);
  }
}

template<class t_type, class t_allocator>
typename list<t_type, t_allocator>::remove_return_type list<t_type, t_allocator>::remove(value_type const &value) {
  list<t_type, t_allocator> deleted_nodes(get_allocator()); // collect the nodes we're removing
  for (const_iterator iter = begin(), end_iter = end(); iter != end_iter;) {
    if (*iter == value) {
      const_iterator iter_next = ::portable_stl::next(iter);
      for (; iter_next != end_iter && *iter_next == value; ++iter_next)
        ;
      deleted_nodes.splice(deleted_nodes.end(), *this, iter, iter_next);
      iter = iter_next;
      if (iter != end_iter) {
        ++iter;
      }
    } else {
      ++iter;
    }
  }

  return (remove_return_type)deleted_nodes.size();
}

template<class t_type, class t_allocator>
template<class t_pred>
typename list<t_type, t_allocator>::remove_return_type list<t_type, t_allocator>::remove_if(t_pred pred) {
  list<t_type, t_allocator> deleted_nodes(get_allocator()); // collect the nodes we're removing
  for (iterator iter = begin(), end_iter = end(); iter != end_iter;) {
    if (pred(*iter)) {
      iterator iter_next = ::portable_stl::next(iter);
      for (; iter_next != end_iter && pred(*iter_next); ++iter_next)
        ;
      deleted_nodes.splice(deleted_nodes.end(), *this, iter, iter_next);
      iter = iter_next;
      if (iter != end_iter) {
        ++iter;
      }
    } else {
      ++iter;
    }
  }

  return static_cast<remove_return_type>(deleted_nodes.size());
}

template<class t_type, class t_allocator>
template<class t_binary_pred>
typename list<t_type, t_allocator>::remove_return_type list<t_type, t_allocator>::unique(t_binary_pred pred) {
  list<t_type, t_allocator> deleted_nodes(get_allocator()); // collect the nodes we're removing
  for (iterator iter = begin(), end_iter = end(); iter != end_iter;) {
    iterator iter_next = ::portable_stl::next(iter);
    for (; (iter_next != end_iter) && pred(*iter, *iter_next); ++iter_next)
      ;
    if (++iter != iter_next) {
      deleted_nodes.splice(deleted_nodes.end(), *this, iter, iter_next);
      iter = iter_next;
    }
  }

  return static_cast<remove_return_type>(deleted_nodes.size());
}

template<class t_type, class t_allocator> inline void list<t_type, t_allocator>::merge(list &other_list) {
  merge(other_list, ::portable_stl::less<>());
}

template<class t_type, class t_allocator>
template<class t_comp>
void list<t_type, t_allocator>::merge(list &other_list, t_comp comp) {
  if (this != ::portable_stl::addressof(other_list)) {
    iterator first1{begin()};
    iterator end1{end()};
    iterator first2{other_list.begin()};
    iterator end2{other_list.end()};

    while (first1 != end1 && first2 != end2) {
      if (comp(*first2, *first1)) {
        size_type count_added_node = 1;
        iterator  tmp_node2        = ::portable_stl::next(first2);
        for (; tmp_node2 != end2 && comp(*tmp_node2, *first1); ++tmp_node2, (void)++count_added_node)
          ;
        base::size_val() += count_added_node;
        other_list.size_val() -= count_added_node;
        t_link_pointer first_node_link = first2.m_ptr;
        t_link_pointer last_node_link  = tmp_node2.m_ptr->m_prev;
        first2                         = tmp_node2;
        base::unlink_nodes(first_node_link, last_node_link);
        tmp_node2 = ::portable_stl::next(first1);
        M_link_nodes(first1.m_ptr, first_node_link, last_node_link);
        first1 = tmp_node2;
      } else {
        ++first1;
      }
    }
    splice(end1, other_list);
  }
}

template<class t_type, class t_allocator> inline void list<t_type, t_allocator>::sort() {
  sort(::portable_stl::less<>());
}

template<class t_type, class t_allocator>
template<class t_comp>
inline void list<t_type, t_allocator>::sort(t_comp comp) {
  M_sort(begin(), end(), base::size_val(), comp);
}

template<class t_type, class t_allocator>
template<class t_comp>
typename list<t_type, t_allocator>::iterator list<t_type, t_allocator>::M_sort(
  iterator first1, iterator end2, size_type num, t_comp &comp) {
  switch (num) {
    case 0:
    case 1:
      return first1;
    case 2:
      if (comp(*--end2, *first1)) {
        t_link_pointer first_node_link = end2.m_ptr;
        base::unlink_nodes(first_node_link, first_node_link);
        M_link_nodes(first1.m_ptr, first_node_link, first_node_link);
        return end2;
      }
      return first1;
    default:
      break; // do nothing
  }
  size_type num_div_2 = num / 2;
  iterator  end1      = ::portable_stl::next(
    first1, static_cast<typename ::portable_stl::iterator_traits<iterator>::difference_type>(num_div_2));
  iterator ret = first1 = M_sort(first1, end1, num_div_2, comp);
  iterator first2 = end1 = M_sort(end1, end2, num - num_div_2, comp);
  if (comp(*first2, *first1)) {
    iterator next_node2 = ::portable_stl::next(first2);
    for (; (next_node2 != end2) && comp(*next_node2, *first1); ++next_node2)
      ;
    t_link_pointer first_node_link = first2.m_ptr;
    t_link_pointer last_node_link  = next_node2.m_ptr->m_prev;
    ret                            = first2;
    end1 = first2 = next_node2;
    base::unlink_nodes(first_node_link, last_node_link);
    next_node2 = ::portable_stl::next(first1);
    M_link_nodes(first1.m_ptr, first_node_link, last_node_link);
    first1 = next_node2;
  } else {
    ++first1;
  }
  while (first1 != end1 && first2 != end2) {
    if (comp(*first2, *first1)) {
      iterator next_node2 = ::portable_stl::next(first2);
      for (; (next_node2 != end2) && comp(*next_node2, *first1); ++next_node2)
        ;
      t_link_pointer first_node_link = first2.m_ptr;
      t_link_pointer last_node_link  = next_node2.m_ptr->m_prev;
      if (end1 == first2) {
        end1 = next_node2;
      }
      first2 = next_node2;
      base::unlink_nodes(first_node_link, last_node_link);
      next_node2 = ::portable_stl::next(first1);
      M_link_nodes(first1.m_ptr, first_node_link, last_node_link);
      first1 = next_node2;
    } else {
      ++first1;
    }
  }
  return ret;
}

template<class t_type, class t_allocator> void list<t_type, t_allocator>::reverse() noexcept {
  if (base::size_val() > 1U) {
    iterator iter_end = end();
    for (iterator iter = begin(); iter.m_ptr != iter_end.m_ptr;) {
      ::portable_stl::swap(iter.m_ptr->m_prev, iter.m_ptr->m_next);
      iter.m_ptr = iter.m_ptr->m_prev;
    }
    ::portable_stl::swap(iter_end.m_ptr->m_prev, iter_end.m_ptr->m_next);
  }
}

/**
 * @brief Compares the contents of two lists.
 *
 * @tparam t_type
 * @tparam t_allocator
 * @param lhv lists whose contents to compare.
 * @param rhv lists whose contents to compare.
 * @return true if the contents of the lists are equal,
 * @return false otherwise.
 */
template<class t_type, class t_allocator>
inline bool operator==(list<t_type, t_allocator> const &lhv, list<t_type, t_allocator> const &rhv) {
  return (lhv.size() == rhv.size()) && ::portable_stl::equal(lhv.begin(), lhv.end(), rhv.begin());
}

/**
 * @brief Compares the contents of two lists.
 *
 * @tparam t_type
 * @tparam t_allocator
 * @param lhv lists whose contents to compare.
 * @param rhv lists whose contents to compare.
 * @return true if the contents of the lists are not equal,
 * @return false otherwise.
 */
template<class t_type, class t_allocator>
inline bool operator!=(list<t_type, t_allocator> const &lhv, list<t_type, t_allocator> const &rhv) {
  return !(lhv == rhv);
}

/**
 * @brief Compares the contents of two lists.
 *
 * @tparam t_type
 * @tparam t_allocator
 * @param lhv lists whose contents to compare.
 * @param rhv lists whose contents to compare.
 * @return true if the contents of the 'lhs' are lexicographically less than the contents of 'rhs',
 * @return false otherwise.
 */
template<class t_type, class t_allocator>
inline bool operator<(list<t_type, t_allocator> const &lhv, list<t_type, t_allocator> const &rhv) {
  return ::portable_stl::lexicographical_compare(lhv.begin(), lhv.end(), rhv.begin(), rhv.end());
}

/**
 * @brief Compares the contents of two lists.
 *
 * @tparam t_type
 * @tparam t_allocator
 * @param lhv lists whose contents to compare.
 * @param rhv lists whose contents to compare.
 * @return true if the contents of the 'lhs' are lexicographically less than or equal to the contents of 'rhs',
 * @return false otherwise.
 */
template<class t_type, class t_allocator>
inline bool operator<=(list<t_type, t_allocator> const &lhv, list<t_type, t_allocator> const &rhv) {
  return !(rhv < lhv);
}

/**
 * @brief Compares the contents of two lists.
 *
 * @tparam t_type
 * @tparam t_allocator
 * @param lhv lists whose contents to compare.
 * @param rhv lists whose contents to compare.
 * @return true if the contents of the 'lhs' are lexicographically greater than the contents of 'rhs',
 * @return false otherwise.
 */
template<class t_type, class t_allocator>
inline bool operator>(list<t_type, t_allocator> const &lhv, list<t_type, t_allocator> const &rhv) {
  return rhv < lhv;
}

/**
 * @brief Compares the contents of two lists.
 *
 * @tparam t_type
 * @tparam t_allocator
 * @param lhv lists whose contents to compare.
 * @param rhv lists whose contents to compare.
 * @return true if the contents of the 'lhs' are lexicographically greater than or equal to the contents of 'rhs',
 * @return false otherwise.
 */
template<class t_type, class t_allocator>
inline bool operator>=(list<t_type, t_allocator> const &lhv, list<t_type, t_allocator> const &rhv) {
  return !(lhv < rhv);
}

/**
 * @brief Specializes the ::swap algorithm for ::list. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory.
 * @param lhv Containers whose contents to swap.
 * @param rhv Containers whose contents to swap.
 */
template<class t_type, class t_allocator>
inline void swap(list<t_type, t_allocator> &lhv, list<t_type, t_allocator> &rhv) noexcept(noexcept(lhv.swap(rhv))) {
  lhv.swap(rhv);
}
} // namespace portable_stl

#endif // PSTL_LIST_H
