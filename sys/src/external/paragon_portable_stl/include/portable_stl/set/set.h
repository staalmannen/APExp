// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="set.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef SET_H
#define SET_H

#include "../algorithm/equal.h"
#include "../algorithm/lexicographical_compare.h"
#include "../containers/insert_return_type.h"
#include "../containers/node_handle.h"
#include "../containers/tree.h"
#include "../functional/is_transparent.h"
#include "../functional/less.h"
#include "../iterator/reverse_iterator.h"
#include "../language_support/bad_alloc.h"

#include "../memory/allocator.h"
#include "../memory/allocator_traits.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/type_properties/is_nothrow_copy_constructible.h"
#include "../metaprogramming/type_properties/is_nothrow_default_constructible.h"
#include "../utility/general/forward.h"
#include "../utility/general/move.h"
#include "../utility/general/swap.h"
#include "../utility/tuple/tuple.h"

#if defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  include "../language_support/exception/throw_on_true.h"
#else
#  include "../language_support/no_exception/throw_on_true.h"
#endif

namespace portable_stl {

/**
 * @brief set is an associative container that contains a sorted set of unique objects of type Key. Sorting is done
 * using the key comparison function Compare. Search, removal, and insertion operations have logarithmic complexity.
 * Sets are usually implemented as Red–black trees.
 *
 * @tparam t_key Keys type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 */
template<class t_key,
         class t_compare   = ::portable_stl::less<t_key>,
         class t_allocator = ::portable_stl::allocator<t_key>>
class set {
public:
  /**
   * @brief Key type.
   */
  using key_type        = t_key;
  /**
   * @brief Value type.
   */
  using value_type      = key_type;
  /**
   * @brief Key compare type.
   */
  using key_compare     = ::portable_stl::type_identity_t<t_compare>;
  /**
   * @brief Same type as key compare type.
   */
  using value_compare   = key_compare;
  /**
   * @brief Allocator type.
   */
  using allocator_type  = ::portable_stl::type_identity_t<t_allocator>;
  /**
   * @brief Reference type.
   */
  using reference       = value_type &;
  /**
   * @brief Reference to const type.
   */
  using const_reference = value_type const &;

  static_assert(::portable_stl::is_same<typename allocator_type::value_type, value_type>{}(),
                "Allocator::value_type must be same type as value_type");

private:
  using t_base_tree_type   = ::portable_stl::tree<value_type, value_compare, allocator_type>;
  using t_allocator_traits = ::portable_stl::allocator_traits<allocator_type>;

  static_assert(
    ::portable_stl::is_same<allocator_type, ::portable_stl::rebind_alloc<t_allocator_traits, value_type>>{}(),
    "[allocator.requirements] states that rebinding an allocator to the same type should result in the "
    "original allocator");

  /**
   * @brief Stored tree implementation.
   *
   */
  t_base_tree_type m_tree;

public:
  /**
   * @brief Pointer type.
   */
  using pointer                = typename t_allocator_traits::pointer;
  /**
   * @brief Constant pointer type.
   */
  using const_pointer          = typename t_allocator_traits::const_pointer;
  /**
   * @brief Size type.
   */
  using size_type              = typename t_allocator_traits::size_type;
  /**
   * @brief Difference type.
   */
  using difference_type        = typename t_allocator_traits::difference_type;
  /**
   * @brief Iterator type.
   */
  using iterator               = typename t_base_tree_type::const_iterator;
  /**
   * @brief Constant iterator type.
   */
  using const_iterator         = typename t_base_tree_type::const_iterator;
  /**
   * @brief Reverse iterator type.
   */
  using reverse_iterator       = ::portable_stl::reverse_iterator<iterator>;
  /**
   * @brief Constant reverse iterator type.
   */
  using const_reverse_iterator = ::portable_stl::reverse_iterator<const_iterator>;
  /**
   * @brief
   */
  using node_type          = ::portable_stl::set_node_handle<typename t_base_tree_type::t_node_type, allocator_type>;
  /**
   * @brief
   */
  using insert_return_type = ::portable_stl::insert_return_type<iterator, node_type>;

  template<class t_key2, class t_comp2, class t_alloc2> friend class set;
  template<class t_key2, class t_comp2, class t_alloc2> friend class multiset;

  /**
   * @brief Constructs an empty set.
   *
   */
  set() noexcept(::portable_stl::is_nothrow_default_constructible<allocator_type>{}()
                 && ::portable_stl::is_nothrow_default_constructible<key_compare>{}()
                 && ::portable_stl::is_nothrow_copy_constructible<key_compare>{}())
      : m_tree(value_compare()) {
  }

  /**
   * @brief Constructs an empty set.
   *
   * @param comp Comparison function object to use for all comparisons of keys.
   */
  explicit set(value_compare const &comp) noexcept(::portable_stl::is_nothrow_default_constructible<allocator_type>{}()
                                                   && ::portable_stl::is_nothrow_copy_constructible<key_compare>{}())
      : m_tree(comp) {
  }

  /**
   * @brief Constructs an empty set.
   *
   * @param comp Comparison function object to use for all comparisons of keys.
   * @param alloc Allocator to use for all memory allocations of this set.
   */
  explicit set(value_compare const &comp, allocator_type const &alloc) : m_tree(comp, alloc) {
  }

  /**
   * @brief Constructs an empty set.
   *
   * @param alloc Allocator to use for all memory allocations of this set.
   */
  explicit set(allocator_type const &alloc) : m_tree(alloc) {
  }

  /**
   * @brief Constructs the set with the contents of the range [first, last). If multiple elements in the range have keys
   * that compare equivalent, it is unspecified which element is inserted (pending LWG2844).
   * If [first, last) is not a valid range, the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param comp Comparison function object to use for all comparisons of keys.
   */
  template<class t_input_iterator>
  set(t_input_iterator first, t_input_iterator last, value_compare const &comp = value_compare()) : m_tree(comp) {
    auto insert_result = insert(first, last);
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert_result);
  }

  /**
   * @brief Make the set with the contents of the range [first, last). If multiple elements in the range have keys
   * that compare equivalent, it is unspecified which element is inserted (pending LWG2844).
   * If [first, last) is not a valid range, the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param comp Comparison function object to use for all comparisons of keys.
   */
  template<class t_input_iterator>
  static ::portable_stl::expected<set, ::portable_stl::portable_stl_error> make_set(
    t_input_iterator first, t_input_iterator last, value_compare const &comp = value_compare()) {
    return make_set(first, last, comp, allocator_type());
  }

  /**
   * @brief Constructs the set with the contents of the range [first, last). If multiple elements in the range have keys
   * that compare equivalent, it is unspecified which element is inserted (pending LWG2844).
   * If [first, last) is not a valid range, the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param comp Comparison function object to use for all comparisons of keys.
   * @param alloc Allocator to use for all memory allocations of this set.
   */
  template<class t_input_iterator>
  set(t_input_iterator first, t_input_iterator last, value_compare const &comp, allocator_type const &alloc)
      : m_tree(comp, alloc) {
    auto insert_result = insert(first, last);
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert_result);
  }

  /**
   * @brief Make the set with the contents of the range [first, last). If multiple elements in the range have keys
   * that compare equivalent, it is unspecified which element is inserted (pending LWG2844).
   * If [first, last) is not a valid range, the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param comp Comparison function object to use for all comparisons of keys.
   * @param alloc Allocator to use for all memory allocations of this set.
   * @return ::portable_stl::expected<set, ::portable_stl::portable_stl_error>
   */
  template<class t_input_iterator>
  static ::portable_stl::expected<set, ::portable_stl::portable_stl_error> make_set(
    t_input_iterator first, t_input_iterator last, value_compare const &comp, allocator_type const &alloc) {
    set ret(comp, alloc);
    return ret.insert(first, last).and_then([&ret](void) -> ::portable_stl::expected<set, ::portable_stl::portable_stl_error> {
      return {::portable_stl::in_place_t{}, ::portable_stl::move(ret)};
    });
  }

  /**
   * @brief Constructs the set with the contents of the range [first, last). If multiple elements in the range have keys
   * that compare equivalent, it is unspecified which element is inserted (pending LWG2844).
   * If [first, last) is not a valid range, the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param alloc Allocator to use for all memory allocations of this set.
   */
  template<class t_input_iterator>
  set(t_input_iterator first, t_input_iterator last, allocator_type const &alloc)
      : set(first, last, key_compare(), alloc) {
  }

  /**
   * @brief Make the set with the contents of the range [first, last). If multiple elements in the range have keys
   * that compare equivalent, it is unspecified which element is inserted (pending LWG2844).
   * If [first, last) is not a valid range, the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param alloc Allocator to use for all memory allocations of this set.
   * @return ::portable_stl::expected<set, ::portable_stl::portable_stl_error>
   */
  template<class t_input_iterator>
  static ::portable_stl::expected<set, ::portable_stl::portable_stl_error> make_set(
    t_input_iterator first, t_input_iterator last, allocator_type const &alloc) {
    return make_set(first, last, value_compare(), alloc);
  }

  /**
   * @brief Copy constructor.
   * Constructs the set with the copy of the contents of other.
   *
   * @param other Another set to be used as source to initialize the elements of the container with.
   */
  set(set const &other) : m_tree(other.m_tree) {
    auto insert_result = insert(other.begin(), other.end());
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert_result);
  }

  /**
   * @brief Copy constructor.
   * Constructs the set with the copy of the contents of other.
   *
   * @param other Another set to be used as source to initialize the elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this set.
   */
  set(set const &other, allocator_type const &alloc) : m_tree(other.m_tree.value_comp(), alloc) {
    auto insert_result = insert(other.begin(), other.end());
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert_result);
  }

  /**
   * @brief Move constructor.
   * Constructs the set with the contents of other using move semantics. If alloc is not provided, allocator is obtained
   * by move-construction from the allocator belonging to other.
   *
   * @param other Another set to be used as source to initialize the elements of the container with.
   */
  set(set &&other) noexcept(::portable_stl::is_nothrow_move_constructible<t_base_tree_type>{}())
      : m_tree(::portable_stl::move(other.m_tree)) {
  }

  /**
   * @brief Move constructor.
   * Constructs the set with the contents of other using move semantics. If alloc is not provided, allocator is obtained
   * by move-construction from the allocator belonging to other.
   *
   * @param other Another set to be used as source to initialize the elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this set.
   */
  set(set &&other, allocator_type const &alloc);

  /**
   * @brief Initializer-list constructor.
   * Constructs the set with the contents of the initializer list init_list. If multiple elements in the range have keys
   * that compare equivalent, it is unspecified which element is inserted (pending LWG2844).
   *
   * @param init_list Initializer list to initialize the elements of the container with.
   * @param comp Comparison function object to use for all comparisons of keys.
   */
  set(std::initializer_list<value_type> init_list, value_compare const &comp = value_compare()) : m_tree(comp) {
    auto insert_result = insert(init_list.begin(), init_list.end());
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert_result);
  }

  /**
   * @brief Initializer-list constructor.
   * Constructs the set with the contents of the initializer list init_list. If multiple elements in the range have keys
   * that compare equivalent, it is unspecified which element is inserted (pending LWG2844).
   *
   * @param init_list Initializer list to initialize the elements of the container with.
   * @param comp Comparison function object to use for all comparisons of keys.
   * @param alloc Allocator to use for all memory allocations of this set.
   */
  set(std::initializer_list<value_type> init_list, value_compare const &comp, allocator_type const &alloc)
      : m_tree(comp, alloc) {
    auto insert_result = insert(init_list.begin(), init_list.end());
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert_result);
  }

  /**
   * @brief Initializer-list constructor.
   * Constructs the set with the contents of the initializer list init_list. If multiple elements in the range have keys
   * that compare equivalent, it is unspecified which element is inserted (pending LWG2844).
   *
   * @param init_list Initializer list to initialize the elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this set.
   */
  set(std::initializer_list<value_type> init_list, allocator_type const &alloc) : set(init_list, key_compare(), alloc) {
  }

  /**
   * @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
   *
   * @param other Another set to use as data source.
   * @return set&
   */
  set &operator=(set const &other) {
    m_tree = other.m_tree;
    return *this;
  }

  /**
   * @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in
   * other is moved from other into this set). other is in a valid but unspecified state afterwards.
   *
   * @param other Another set to use as data source.
   * @return set&
   */
  set &operator=(set &&other) noexcept(::portable_stl::is_nothrow_move_assignable<t_base_tree_type>{}()) {
    m_tree = ::portable_stl::move(other.m_tree);
    return *this;
  }

  /**
   * @brief Replaces the contents with those identified by initializer list init_list.
   *
   * @param init_list Initializer list to use as data source.
   * @return set&
   */
  set &operator=(std::initializer_list<value_type> init_list) {
    m_tree.assign_unique(init_list.begin(), init_list.end());
    return *this;
  }

  // ~set() {}

  /**
   * @brief Returns the allocator associated with the set.
   *
   * @return allocator_type The associated allocator.
   */
  allocator_type get_allocator() const noexcept {
    return m_tree.get_alloc();
  }

  /**
   * @brief Returns the function object that compares the keys, which is a copy of this set's constructor argument comp.
   * It is the same as value_comp.
   *
   * @return key_compare The key comparison function object.
   */
  key_compare key_comp() const {
    return m_tree.value_comp();
  }

  /**
   * @brief Returns the function object that compares the values. It is the same as key_comp.
   *
   * @return value_compare The value comparison function object.
   */
  value_compare value_comp() const {
    return m_tree.value_comp();
  }

  /**
   * @brief Returns an iterator to the first element of the set.
   * If the set is empty, the returned iterator will be equal to end().
   *
   * @return iterator Iterator to the first element.
   */
  iterator begin() noexcept {
    return m_tree.begin();
  }

  /**
   * @brief Returns a constant iterator to the first element of the set.
   * If the set is empty, the returned iterator will be equal to end().
   *
   * @return const_iterator Constant iterator to the first element.
   */
  const_iterator begin() const noexcept {
    return m_tree.begin();
  }

  /**
   * @brief Returns an iterator to the element following the last element of the set.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   *
   * @return iterator Iterator to the element following the last element.
   */
  iterator end() noexcept {
    return m_tree.end();
  }

  /**
   * @brief Returns a constant iterator to the element following the last element of the set.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   *
   * @return const_iterator Constant iterator to the element following the last element.
   */
  const_iterator end() const noexcept {
    return m_tree.end();
  }

  /**
   * @brief Returns a reverse iterator to the first element of the reversed set. It corresponds to the last element of
   * the non-reversed set.
   * If the set is empty, the returned iterator is equal to rend().
   *
   * @return reverse_iterator Reverse iterator to the first element.
   */
  reverse_iterator rbegin() noexcept {
    return reverse_iterator(end());
  }

  /**
   * @brief Returns a constant reverse iterator to the first element of the reversed set. It corresponds to the last
   * element of the non-reversed set. If the set is empty, the returned iterator is equal to rend().
   *
   * @return const_reverse_iterator Constant reverse iterator to the first element.
   */
  const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator(end());
  }

  /**
   * @brief Returns a reverse iterator to the element following the last element of the reversed set. It corresponds to
   * the element preceding the first element of the non-reversed set. This element acts as a placeholder, attempting to
   * access it results in undefined behavior.
   *
   * @return reverse_iterator Reverse iterator to the element following the last element.
   */
  reverse_iterator rend() noexcept {
    return reverse_iterator(begin());
  }

  /**
   * @brief Returns a constant reverse iterator to the element following the last element of the reversed set. It
   * corresponds to the element preceding the first element of the non-reversed set. This element acts as a placeholder,
   * attempting to access it results in undefined behavior.
   *
   * @return const_reverse_iterator Constant reverse iterator to the element following the last element.
   */
  const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator(begin());
  }

  /**
   * @brief Returns a constant iterator to the first element of the set.
   * If the set is empty, the returned iterator will be equal to end().
   *
   * @return const_iterator Constant iterator to the first element.
   */
  const_iterator cbegin() const noexcept {
    return begin();
  }

  /**
   * @brief Returns a constant iterator to the element following the last element of the set.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   *
   * @return const_iterator Constant iterator to the element following the last element.
   */
  const_iterator cend() const noexcept {
    return end();
  }

  /**
   * @brief Returns a constant reverse iterator to the first element of the reversed set. It corresponds to the last
   * element of the non-reversed set. If the set is empty, the returned iterator is equal to rend().
   *
   * @return const_reverse_iterator Constant reverse iterator to the first element.
   */
  const_reverse_iterator crbegin() const noexcept {
    return rbegin();
  }

  /**
   * @brief Returns a constant reverse iterator to the element following the last element of the reversed set. It
   * corresponds to the element preceding the first element of the non-reversed set. This element acts as a placeholder,
   * attempting to access it results in undefined behavior.
   *
   * @return const_reverse_iterator Constant reverse iterator to the element following the last element.
   */
  const_reverse_iterator crend() const noexcept {
    return rend();
  }

  /**
   * @brief Checks if the container has no elements, i.e. whether begin() == end().
   *
   * @return true If the container is empty,
   * @return false otherwise.
   */
  bool empty() const noexcept {
    return 0 == m_tree.size();
  }

  /**
   * @brief Returns the number of elements in the container, i.e. ::distance(begin(), end()).
   *
   * @return size_type The number of elements in the container.
   */
  size_type size() const noexcept {
    return m_tree.size();
  }

  /**
   * @brief Returns the maximum number of elements the container is able to hold due to system or library implementation
   * limitations, i.e. ::distance(begin(), end()) for the largest container.
   *
   * @return size_type Maximum number of elements.
   */
  size_type max_size() const noexcept {
    return m_tree.max_size();
  }

  // modifiers:
  template<class... t_args>
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> emplace(
    t_args &&...args) {
    return m_tree.emplace_unique(::portable_stl::forward<t_args>(args)...);
  }

  template<class... t_args>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> emplace_hint(const_iterator hint_pos,
                                                                                      t_args &&...args) {
    return m_tree.emplace_hint_unique(hint_pos, ::portable_stl::forward<t_args>(args)...);
  }

  /**
   * @brief Inserts value into the set, if the set doesn't already contain an element with an equivalent key.
   *
   * @param value Element value to insert.
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> A pair
   * consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool value
   * set to true if and only if the insertion took place.
   */
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> insert(
    value_type const &value) {
    return m_tree.insert_unique(value);
  }

  /**
   * @brief Inserts value into the set, if the set doesn't already contain an element with an equivalent key.
   *
   * @param value Element value to insert.
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> A pair
   * consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool value
   * set to true if and only if the insertion took place.
   */
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> insert(
    value_type &&value) {
    return m_tree.insert_unique(::portable_stl::move(value));
  }

  /**
   * @brief Inserts value in the position into the set as close as possible to the position just prior to pos.
   *
   * @param pos Iterator to the position before which the new element will be inserted.
   * @param value Element value to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> An iterator to the inserted element,
   * or to the element that prevented the insertion.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(const_iterator    pos,
                                                                                value_type const &value) {
    return m_tree.insert_unique(pos, value);
  }

  /**
   * @brief Inserts value in the position into the set as close as possible to the position just prior to pos.
   *
   * @param pos Iterator to the position before which the new element will be inserted.
   * @param value Element value to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> An iterator to the inserted element,
   * or to the element that prevented the insertion.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(const_iterator pos,
                                                                                value_type   &&value) {
    return m_tree.insert_unique(pos, ::portable_stl::move(value));
  }

  /**
   * @brief Inserts elements from range [first, last) into the set. If multiple elements in the range have keys that
   * compare equivalent, it is unspecified which element is inserted (pending LWG2844).
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first Range of elements to insert.
   * @param last Range of elements to insert.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>
   */
  template<class t_input_iterator>
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> insert(t_input_iterator first,
                                                                            t_input_iterator last) {
    for (const_iterator end_iter = cend(); first != last; ++first) {
      auto result = m_tree.insert_unique(end_iter, *first);
      if (!result) {
        return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
      }
    }
    return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
  }

  /**
   * @brief Inserts elements from initializer list init_list into the set. If multiple elements in the range have keys
   * that compare equivalent, it is unspecified which element is inserted (pending LWG2844).
   *
   * @param init_list Initializer list to insert the values from.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> insert(
    std::initializer_list<value_type> init_list) {
    return insert(init_list.begin(), init_list.end());
  }

  /**
   * @brief If 'node_hdl' is an empty node handle, does nothing. Otherwise, inserts the element owned by 'node_hdl' into
   * the container , if the container doesn't already contain an element with a key equivalent to node_hdl.key(). The
   * behavior is undefined if 'node_hdl' is not empty and get_allocator() != node_hdl.get_allocator().
   *
   * @param node_hdl A compatible node handle.
   * @return insert_return_type An object of insert_return_type
   */
  insert_return_type insert(node_type &&node_hdl) {
    return m_tree.template node_handle_insert_unique<node_type, insert_return_type>(::portable_stl::move(node_hdl));
  }

  /**
   * @brief If 'node_hdl' is an empty node handle, does nothing and returns the end iterator. Otherwise, inserts the
   * element owned by 'node_hdl' into the container, if the container doesn't already contain an element with a key
   * equivalent to node_hdl.key(), and returns the iterator pointing to the element with key equivalent to
   * node_hdl.key()(regardless of whether the insert succeeded or failed). If the insertion succeeds, 'node_hdl' is
   * moved from, otherwise it retains ownership of the element. The element is inserted as close as possible to the
   * position just prior to pos. The behavior is undefined if 'node_hdl' is not empty and get_allocator() !=
   * node_hdl.get_allocator().
   *
   * @param hint_pos Iterator to the position before which the new element will be inserted.
   * @param node_hdl A compatible node handle.
   * @return iterator End iterator if 'node_hdl' was empty, iterator pointing to the inserted element if insertion took
   * place, and iterator pointing to an element with a key equivalent to node_hdl.key() if it failed.
   */
  iterator insert(const_iterator hint_pos, node_type &&node_hdl) {
    return m_tree.template node_handle_insert_unique<node_type>(hint_pos, ::portable_stl::move(node_hdl));
  }

  /**
   * @brief Removes the element at pos from the set.
   *
   * @param pos Iterator to the element to remove.
   * @return iterator Iterator following the last removed element.
   */
  iterator erase(const_iterator pos) {
    return m_tree.erase(pos);
  }

  /**
   * @brief Removes the element (if one exists) with the key equivalent to key from the set.
   *
   * @param key Key value of the elements to remove.
   * @return size_type Number of elements removed (0 or 1).
   */
  size_type erase(key_type const &key) {
    return m_tree.erase_unique(key);
  }

  /**
   * @brief Removes the elements in the range [first, last) from the set, which must be a valid range in *this.
   *
   * @param first Range of elements to remove.
   * @param last Range of elements to remove.
   * @return iterator Iterator following the last removed element.
   */
  iterator erase(const_iterator first, const_iterator last) {
    return m_tree.erase(first, last);
  }

  /**
   * @brief Erases all elements from the set. After this call, size() returns zero.
   * Invalidates any references, pointers, and iterators referring to contained elements. Any past-the-end iterator
   * remains valid.
   *
   */
  void clear() noexcept {
    m_tree.clear();
  }

  /**
   * @brief If the set has an element with key equivalent to 'key', unlinks the node that contains that element from the
   * set and returns a node handle that owns it. Otherwise, returns an empty node handle.
   *
   * @param key A key to identify the node to be extracted.
   * @return node_type A node handle that owns the extracted element or empty node handle.
   */
  node_type extract(key_type const &key) {
    return m_tree.template node_handle_extract<node_type>(key);
  }

  /**
   * @brief Unlinks the node that contains the element pointed to by position and returns a node handle that owns it.
   *
   * @param pos A valid iterator into this container.
   * @return node_type A node handle that owns the extracted element.
   */
  node_type extract(const_iterator pos) {
    return m_tree.template node_handle_extract<node_type>(pos);
  }

  /**
   * @brief Attempts to extract ("splice") each element in source and insert it into *this using the comparison object
   * of *this. If there is an element in *this with key equivalent to the key of an element from source, then that
   * element is not extracted from source. No elements are copied or moved, only the internal pointers of the container
   * nodes are repointed. All pointers and references to the transferred elements remain valid, but now refer into
   * *this, not into source.
   * The behavior is undefined if get_allocator() != source.get_allocator().
   *
   * @tparam t_compare2
   * @param source Compatible container to transfer the nodes from.
   */
  template<class t_compare2> void merge(set<key_type, t_compare2, allocator_type> &source) {
    m_tree.node_handle_merge_unique(source.m_tree);
  }

  /**
   * @brief Attempts to extract ("splice") each element in source and insert it into *this using the comparison object
   * of *this. If there is an element in *this with key equivalent to the key of an element from source, then that
   * element is not extracted from source. No elements are copied or moved, only the internal pointers of the container
   * nodes are repointed. All pointers and references to the transferred elements remain valid, but now refer into
   * *this, not into source.
   * The behavior is undefined if get_allocator() != source.get_allocator().
   *
   * @tparam t_compare2
   * @param source Compatible container to transfer the nodes from.
   */
  template<class t_compare2> void merge(set<key_type, t_compare2, allocator_type> &&source) {
    m_tree.node_handle_merge_unique(source.m_tree);
  }

  /**
   * @brief Exchanges the contents of the set with those of other. Does not invoke any move, copy, or swap operations on
   * individual elements.
   *
   * @param other Set to exchange the contents with.
   */
  void swap(set &other) noexcept(::portable_stl::is_nothrow_swappable<t_base_tree_type>{}()) {
    m_tree.swap(other.m_tree);
  }

  /**
   * @brief Finds an element with key equivalent to key.
   *
   * @param key Key value of the element to search for.
   * @return iterator An iterator to the requested element. If no such element is found, past-the-end (see end())
   * iterator is returned.
   */
  iterator find(key_type const &key) {
    return m_tree.find(key);
  }

  /**
   * @brief Finds an element with key equivalent to key.
   *
   * @param key Key value of the element to search for.
   * @return const_iterator A constant iterator to the requested element. If no such element is found, past-the-end (see
   * end()) iterator is returned.
   */
  const_iterator find(key_type const &key) const {
    return m_tree.find(key);
  }

  /**
   * @brief Finds an element with key that compares equivalent to the value 'key_value'. This overload participates in
   * overload resolution only if the qualified-id Compare::is_transparent is valid and denotes a type. It allows calling
   * this function without constructing an instance of Key.
   *
   * @tparam t_key_type
   * @param key_value A value of any type that can be transparently compared with a key
   * @return iterator An iterator to the requested element. If no such element is found, past-the-end (see end())
   * iterator is returned.
   */
  template<typename t_key_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_type>, void *>
           = nullptr>
  iterator find(t_key_type const &key_value) {
    return m_tree.find(key_value);
  }

  /**
   * @brief Finds an element with key that compares equivalent to the value 'key_value'. This overload participates in
   * overload resolution only if the qualified-id Compare::is_transparent is valid and denotes a type. It allows calling
   * this function without constructing an instance of Key.
   *
   * @tparam t_key_type
   * @param key_value A value of any type that can be transparently compared with a key
   * @return const_iterator A constant iterator to the requested element. If no such element is found, past-the-end (see
   * end()) iterator is returned.
   */
  template<typename t_key_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_type>, void *>
           = nullptr>
  const_iterator find(t_key_type const &key_value) const {
    return m_tree.find(key_value);
  }

  /**
   * @brief Returns the number of elements with key key. This is either 1 or 0 since this container does not allow
   * duplicates.
   *
   * @param key Key value of the elements to count.
   * @return size_type Number of elements with key that compares equivalent to key (1 or 0).
   */
  size_type count(key_type const &key) const {
    return m_tree.count_unique(key);
  }

  /**
   * @brief Returns the number of elements with key that compares equivalent to the value 'key_value'. This overload
   * participates in overload resolution only if the qualified-id Compare::is_transparent is valid and denotes a type.
   * It allows calling this function without constructing an instance of Key.
   *
   * @tparam t_key_type
   * @param key_value Alternative value to compare to the keys.
   * @return size_type Number of elements with key that compares equivalent to 'key_value'.
   */
  template<typename t_key_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_type>, void *>
           = nullptr>
  size_type count(t_key_type const &key_value) const {
    return m_tree.count_multi(key_value);
  }

  /**
   * @brief Checks if there is an element with key equivalent to key in the set.
   *
   * @param key	Key value of the element to search for.
   * @return true If there is such an element,
   * @return false otherwise.
   */
  bool contains(key_type const &key) const {
    return find(key) != end();
  }

  /**
   * @brief Checks if there is an element with key that compares equivalent to the value 'key_value'. This overload
   * participates in overload resolution only if the qualified-id Compare::is_transparent is valid and denotes a type.
   * It allows calling this function without constructing an instance of Key.
   *
   * @tparam t_key_type
   * @param key_value A value of any type that can be transparently compared with a key.
   * @return true If there is such an element,
   * @return false otherwise.
   */
  template<typename t_key_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_type>, void *>
           = nullptr>
  bool contains(t_key_type const &key_value) const {
    return find(key_value) != end();
  }

  /**
   * @brief Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
   *
   * @param key Key value to compare the elements to.
   * @return iterator Iterator pointing to the first element that is not less than key. If no such element is found, a
   * past-the-end iterator (see end()) is returned.
   */
  iterator lower_bound(key_type const &key) {
    return m_tree.lower_bound(key);
  }

  /**
   * @brief Returns an constant iterator pointing to the first element that is not less than (i.e. greater or equal to)
   * key.
   *
   * @param key Key value to compare the elements to.
   * @return const_iterator Constant iterator pointing to the first element that is not less than key. If no such
   * element is found, a past-the-end iterator (see end()) is returned.
   */
  const_iterator lower_bound(key_type const &key) const {
    return m_tree.lower_bound(key);
  }

  /**
   * @brief Returns an iterator pointing to the first element that compares not less (i.e. greater or equal) to the
   * value 't_key_type'. This overload participates in overload resolution only if the qualified-id
   * Compare::is_transparent is valid and denotes a type. It allows calling this function without constructing an
   * instance of Key.
   *
   * @tparam t_key_type
   * @param key_value Alternative value that can be compared to Key.
   * @return iterator Iterator pointing to the first element that is not less than key. If no such element is found, a
   * past-the-end iterator (see end()) is returned.
   */
  template<typename t_key_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_type>, void *>
           = nullptr>
  iterator lower_bound(t_key_type const &key_value) {
    return m_tree.lower_bound(key_value);
  }

  /**
   * @brief Returns a constant iterator pointing to the first element that compares not less (i.e. greater or equal) to
   * the value 't_key_type'. This overload participates in overload resolution only if the qualified-id
   * Compare::is_transparent is valid and denotes a type. It allows calling this function without constructing an
   * instance of Key.
   *
   * @tparam t_key_type
   * @param key_value Alternative value that can be compared to Key.
   * @return const_iterator Constant iterator pointing to the first element that is not less than key. If no such
   * element is found, a past-the-end iterator (see end()) is returned.
   */

  template<typename t_key_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_type>, void *>
           = nullptr>
  const_iterator lower_bound(t_key_type const &key_value) const {
    return m_tree.lower_bound(key_value);
  }

  /**
   * @brief Returns an iterator pointing to the first element that is greater than key.
   *
   * @param key Key value to compare the elements to.
   * @return iterator Iterator pointing to the first element that is greater than key. If no such element is found,
   * past-the-end (see end()) iterator is returned.
   */
  iterator upper_bound(key_type const &key) {
    return m_tree.upper_bound(key);
  }

  /**
   * @brief Returns a constant iterator pointing to the first element that is greater than key.
   *
   * @param key Key value to compare the elements to.
   * @return iterator Constant iterator pointing to the first element that is greater than key. If no such element is
   * found, past-the-end (see end()) iterator is returned.
   */
  const_iterator upper_bound(key_type const &key) const {
    return m_tree.upper_bound(key);
  }

  /**
   * @brief Returns an iterator pointing to the first element that compares greater to the value 'key_value'. This
   * overload participates in overload resolution only if the qualified-id Compare::is_transparent is valid and denotes
   * a type. It allows calling this function without constructing an instance of Key.
   *
   * @tparam t_key_type
   * @param key_value Alternative value that can be compared to Key.
   * @return iterator Iterator pointing to the first element that is greater than key. If no such element is found,
   * past-the-end (see end()) iterator is returned.
   */
  template<typename t_key_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_type>, void *>
           = nullptr>
  iterator upper_bound(t_key_type const &key_value) {
    return m_tree.upper_bound(key_value);
  }

  /**
   * @brief Returns a constant iterator pointing to the first element that compares greater to the value 'key_value'.
   * This overload participates in overload resolution only if the qualified-id Compare::is_transparent is valid and
   * denotes a type. It allows calling this function without constructing an instance of Key.
   *
   * @tparam t_key_type
   * @param key_value Alternative value that can be compared to Key.
   * @return const_iterator Constant iterator pointing to the first element that is greater than key. If no such element
   * is found, past-the-end (see end()) iterator is returned.
   */
  template<typename t_key_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_type>, void *>
           = nullptr>
  const_iterator upper_bound(t_key_type const &key_value) const {
    return m_tree.upper_bound(key_value);
  }

  /**
   * @brief Returns a range containing all elements with the given key in the set. The range is defined by two
   * iterators, one pointing to the first element that is not less than key and another pointing to the first element
   * greater than key. Alternatively, the first iterator may be obtained with lower_bound(), and the second with
   * upper_bound().
   * Compares the keys to 'key'.
   *
   * @param key Key value to compare the elements to.
   * @return ::portable_stl::tuple<iterator, iterator> ::tuple containing a pair of iterators defining the wanted
   * range: the first pointing to the first element that is not less than key and the second pointing to the first
   * element greater than key.
   * If there are no elements not less than key, past-the-end (see end()) iterator is returned as the first element.
   * Similarly if there are no elements greater than key, past-the-end iterator is returned as the second element.
   */
  ::portable_stl::tuple<iterator, iterator> equal_range(key_type const &key) {
    return m_tree.equal_range_unique(key);
  }

  /**
   * @brief Returns a range containing all elements with the given key in the set. The range is defined by two
   * iterators, one pointing to the first element that is not less than key and another pointing to the first element
   * greater than key. Alternatively, the first iterator may be obtained with lower_bound(), and the second with
   * upper_bound().
   * Compares the keys to 'key'.
   *
   * @param key Key value to compare the elements to.
   * @return ::portable_stl::tuple<iterator, iterator> ::tuple containing a pair of iterators defining the wanted
   * range: the first pointing to the first element that is not less than key and the second pointing to the first
   * element greater than key.
   * If there are no elements not less than key, past-the-end (see end()) iterator is returned as the first element.
   * Similarly if there are no elements greater than key, past-the-end iterator is returned as the second element.
   */
  ::portable_stl::tuple<const_iterator, const_iterator> equal_range(key_type const &key) const {
    return m_tree.equal_range_unique(key);
  }

  /**
   * @brief Returns a range containing all elements with the given key in the set. The range is defined by two
   * iterators, one pointing to the first element that is not less than key and another pointing to the first element
   * greater than key. Alternatively, the first iterator may be obtained with lower_bound(), and the second with
   * upper_bound().
   * Compares the keys to the value 'key_value'. This overload participates in overload resolution only if the
   * qualified-id Compare::is_transparent is valid and denotes a type. It allows calling this function without
   * constructing an instance of Key.
   *
   * @param key Key value to compare the elements to.
   * @return ::portable_stl::tuple<iterator, iterator> ::tuple containing a pair of iterators defining the wanted
   * range: the first pointing to the first element that is not less than key and the second pointing to the first
   * element greater than key.
   * If there are no elements not less than key, past-the-end (see end()) iterator is returned as the first element.
   * Similarly if there are no elements greater than key, past-the-end iterator is returned as the second element.
   */
  template<typename key_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, key_type>, void *>
           = nullptr>
  ::portable_stl::tuple<iterator, iterator> equal_range(key_type const &key_value) {
    return m_tree.equal_range_multi(key_value);
  }

  /**
   * @brief Returns a range containing all elements with the given key in the set. The range is defined by two
   * iterators, one pointing to the first element that is not less than key and another pointing to the first element
   * greater than key. Alternatively, the first iterator may be obtained with lower_bound(), and the second with
   * upper_bound().
   * Compares the keys to the value 'key_value'. This overload participates in overload resolution only if the
   * qualified-id Compare::is_transparent is valid and denotes a type. It allows calling this function without
   * constructing an instance of Key.
   *
   * @param key Key value to compare the elements to.
   * @return ::portable_stl::tuple<iterator, iterator> ::tuple containing a pair of iterators defining the wanted
   * range: the first pointing to the first element that is not less than key and the second pointing to the first
   * element greater than key.
   * If there are no elements not less than key, past-the-end (see end()) iterator is returned as the first element.
   * Similarly if there are no elements greater than key, past-the-end iterator is returned as the second element.
   */
  template<typename key_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, key_type>, void *>
           = nullptr>
  ::portable_stl::tuple<const_iterator, const_iterator> equal_range(key_type const &key_value) const {
    return m_tree.equal_range_multi(key_value);
  }
};

/**
 * @brief Move constructor.
 * Constructs the set with the contents of other using move semantics. If alloc is not provided, allocator is obtained
 * by move-construction from the allocator belonging to other.
 *
 * @tparam t_key Keys type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param other Another set to be used as source to initialize the elements of the container with.
 * @param alloc Allocator to use for all memory allocations of this set.
 */
template<class t_key, class t_compare, class t_allocator>
set<t_key, t_compare, t_allocator>::set(set &&other, allocator_type const &alloc)
    : m_tree(::portable_stl::move(other.m_tree), typename t_base_tree_type::allocator_type(alloc)) {
  if (alloc != other.get_allocator()) {
    const_iterator end_iter = cend();
    while (!other.empty()) {
      auto result = insert(end_iter, ::portable_stl::move(other.m_tree.remove(other.begin())->m_value));
      ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!result);
    }
  }
}

/**
 * @brief Compares the contents of two sets.
 * Checks if the contents of lhs and rhs are equal, that is, they have the same number of elements and each element in
 * lhs compares equal with the element in rhs at the same position.
 *
 * @tparam t_key Keys type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param lhv Set whose contents to compare.
 * @param rhv Set whose contents to compare.
 * @return true if the contents of the sets are equal
 * @return false otherwise.
 */
template<class t_key, class t_compare, class t_allocator>
inline bool operator==(set<t_key, t_compare, t_allocator> const &lhv, set<t_key, t_compare, t_allocator> const &rhv) {
  return lhv.size() == rhv.size() && ::portable_stl::equal(lhv.begin(), lhv.end(), rhv.begin());
}

/**
 * @brief Compares the contents of two sets.
 * Checks if the contents of lhs and rhs are equal, that is, they have the same number of elements and each element in
 * lhs compares equal with the element in rhs at the same position.
 *
 * @tparam t_key Keys type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param lhv Set whose contents to compare.
 * @param rhv Set whose contents to compare.
 * @return true if the contents of the sets are not equal
 * @return false otherwise.
 */
template<class t_key, class t_compare, class t_allocator>
inline bool operator!=(set<t_key, t_compare, t_allocator> const &lhv, set<t_key, t_compare, t_allocator> const &rhv) {
  return !(lhv == rhv);
}

/**
 * @brief Compares the contents of two sets.
 * Compares the contents of lhs and rhs lexicographically. The comparison is performed by a function equivalent to
 * ::lexicographical_compare. This comparison ignores the set's ordering Compare.
 *
 * @tparam t_key Keys type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param lhv Set whose contents to compare.
 * @param rhv Set whose contents to compare.
 * @return true if the contents of the lhs are lexicographically less than the contents of rhs
 * @return false otherwise.
 */
template<class t_key, class t_compare, class t_allocator>
inline bool operator<(set<t_key, t_compare, t_allocator> const &lhv, set<t_key, t_compare, t_allocator> const &rhv) {
  return ::portable_stl::lexicographical_compare(lhv.begin(), lhv.end(), rhv.begin(), rhv.end());
}

/**
 * @brief Compares the contents of two sets.
 * Compares the contents of lhs and rhs lexicographically. The comparison is performed by a function equivalent to
 * ::lexicographical_compare. This comparison ignores the set's ordering Compare.
 *
 * @tparam t_key Keys type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param lhv Set whose contents to compare.
 * @param rhv Set whose contents to compare.
 * @return true if the contents of the lhs are lexicographically less than or equal to the contents of rhs
 * @return false otherwise.
 */
template<class t_key, class t_compare, class t_allocator>
inline bool operator<=(set<t_key, t_compare, t_allocator> const &lhv, set<t_key, t_compare, t_allocator> const &rhv) {
  return !(rhv < lhv);
}

/**
 * @brief Compares the contents of two sets.
 * Compares the contents of lhs and rhs lexicographically. The comparison is performed by a function equivalent to
 * ::lexicographical_compare. This comparison ignores the set's ordering Compare.
 *
 * @tparam t_key Keys type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param lhv Set whose contents to compare.
 * @param rhv Set whose contents to compare.
 * @return true if the contents of the lhs are lexicographically greater than the contents of rhs
 * @return false otherwise.
 */
template<class t_key, class t_compare, class t_allocator>
inline bool operator>(set<t_key, t_compare, t_allocator> const &lhv, set<t_key, t_compare, t_allocator> const &rhv) {
  return rhv < lhv;
}

/**
 * @brief Compares the contents of two sets.
 * Compares the contents of lhs and rhs lexicographically. The comparison is performed by a function equivalent to
 * ::lexicographical_compare. This comparison ignores the set's ordering Compare.
 *
 * @tparam t_key Keys type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param lhv Set whose contents to compare.
 * @param rhv Set whose contents to compare.
 * @return true if the contents of the lhs are lexicographically greater than or equal to the contents of rhs
 * @return false otherwise.
 */
template<class t_key, class t_compare, class t_allocator>
inline bool operator>=(set<t_key, t_compare, t_allocator> const &lhv, set<t_key, t_compare, t_allocator> const &rhv) {
  return !(lhv < rhv);
}

/**
 * @brief Specializes the ::swap algorithm for ::set. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
 *
 * @tparam t_key Keys type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param lhv Containers whose contents to swap.
 * @param rhv Containers whose contents to swap.
 */
template<class t_key, class t_compare, class t_allocator>
inline void swap(set<t_key, t_compare, t_allocator> &lhv,
                 set<t_key, t_compare, t_allocator> &rhv) noexcept(noexcept(lhv.swap(rhv))) {
  lhv.swap(rhv);
}

} // namespace portable_stl

#endif // SET_H
