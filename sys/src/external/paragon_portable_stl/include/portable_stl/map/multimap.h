// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="multimap.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MULTIMAP_H
#define PSTL_MULTIMAP_H

#include "../algorithm/equal.h"
#include "../algorithm/lexicographical_compare.h"
#include "../containers/insert_return_type.h"
#include "../containers/node_handle.h"
#include "../containers/tree.h"
#include "../containers/value_type_impl.h"
#include "../functional/binary_function.h"
#include "../functional/is_transparent.h"
#include "../functional/less.h"
#include "../iterator/reverse_iterator.h"
#include "../language_support/bad_alloc.h"
#include "../memory/allocator.h"
#include "../memory/rebind_alloc.h"
#include "../metaprogramming/cv_modifications/remove_const.h"
#include "../metaprogramming/other_transformations/type_identity.h"
#include "../metaprogramming/primary_type/is_allocator.h"
#include "../metaprogramming/type_properties/is_nothrow_copy_constructible.h"
#include "../metaprogramming/type_properties/is_nothrow_default_constructible.h"
#include "../metaprogramming/type_traits/has_input_iterator_category.h"
#include "../utility/tuple/tuple.h"
#include "../utility/tuple/tuple_forward_as.h"
#include "map.h"
#include "map_const_iterator.h"
#include "map_iterator.h"
#include "map_node_destructor.h"
#include "map_value_compare.h"
#if defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  include "../language_support/exception/throw_on_true.h"
#else
#  include "../language_support/no_exception/throw_on_true.h"
#endif

namespace portable_stl {

/**
 * @brief Forward declaration of the map.
 *
 */
template<class, class, class, class> class map;

/**
 * @brief multimap is an associative container that contains a sorted list of key-value pairs, while permitting
 * multiple entries with the same key. Sorting is done according to the comparison function Compare, applied to the
 * keys. Search, insertion, and removal operations have logarithmic complexity.
 *
 * @tparam t_key Keys type.
 * @tparam t_type Mapped type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 */
template<class t_key,
         class t_type,
         class t_compare   = ::portable_stl::less<t_key>,
         class t_allocator = ::portable_stl::allocator<::portable_stl::tuple<t_key const, t_type>>>
class multimap {
public:
  /**
   * @brief Key type.
   */
  using key_type        = t_key;
  /**
   * @brief Mapped value type.
   */
  using mapped_type     = t_type;
  /**
   * @brief Map value type.
   */
  using value_type      = ::portable_stl::tuple<key_type const, mapped_type>;
  /**
   * @brief Key compare type.
   */
  using key_compare     = ::portable_stl::type_identity_t<t_compare>;
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

  class value_compare : public ::portable_stl::binary_function_depr<value_type, value_type, bool> {
    friend class multimap;

  protected:
    key_compare m_comp;

    /**
     * @brief Construct a new value compare object.
     * @param comp
     */
    value_compare(key_compare comp) : m_comp(comp) {
    }

  public:
    bool operator()(value_type const &lhv, value_type const &rhv) const {
      return m_comp(::portable_stl::get<0>(lhv), ::portable_stl::get<0>(rhv));
    }
  };

private:
  /**
   * @brief
   */
  using t_value_type     = ::portable_stl::value_type_impl<key_type, mapped_type>;
  /**
   * @brief
   */
  using t_value_compare  = ::portable_stl::map_value_compare<key_type, t_value_type, key_compare>;
  /**
   * @brief
   */
  using t_allocator_type = ::portable_stl::rebind_alloc<::portable_stl::allocator_traits<allocator_type>, t_value_type>;
  /**
   * @brief
   */
  using t_base_tree_type = ::portable_stl::tree<t_value_type, t_value_compare, t_allocator_type>;
  /**
   * @brief
   */
  using t_node_traits    = typename t_base_tree_type::t_node_traits;
  /**
   * @brief
   */
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
   * @brief
   */
  using pointer                = typename t_allocator_traits::pointer;
  /**
   * @brief
   */
  using const_pointer          = typename t_allocator_traits::const_pointer;
  /**
   * @brief
   */
  using size_type              = typename t_allocator_traits::size_type;
  /**
   * @brief
   */
  using difference_type        = typename t_allocator_traits::difference_type;
  /**
   * @brief
   */
  using iterator               = ::portable_stl::map_iterator<typename t_base_tree_type::iterator>;
  /**
   * @brief
   */
  using const_iterator         = ::portable_stl::map_const_iterator<typename t_base_tree_type::const_iterator>;
  /**
   * @brief
   */
  using reverse_iterator       = ::portable_stl::reverse_iterator<iterator>;
  /**
   * @brief
   */
  using const_reverse_iterator = ::portable_stl::reverse_iterator<const_iterator>;
  /**
   * @brief
   */
  using node_type          = ::portable_stl::map_node_handle<typename t_base_tree_type::t_node_type, allocator_type>;
  /**
   * @brief
   */
  using insert_return_type = ::portable_stl::insert_return_type<iterator, node_type>;

  template<class t_key2, class t_value2, class t_comp2, class t_alloc2> friend class map;
  template<class t_key2, class t_value2, class t_comp2, class t_alloc2> friend class multimap;

  /**
   * @brief (1) Constructs new empty multimap.
   */
  multimap() noexcept(::portable_stl::is_nothrow_default_constructible<allocator_type>{}()
                      && ::portable_stl::is_nothrow_default_constructible<key_compare>{}()
                      && ::portable_stl::is_nothrow_copy_constructible<key_compare>{}())
      : m_tree(t_value_compare(key_compare())) {
  }

  /**
   * @brief (2) Constructs new empty multimap using comparison function object comp.
   *
   * @param comp Comparison function object to use for all comparisons of keys.
   */
  explicit multimap(key_compare const &comp) noexcept(
    ::portable_stl::is_nothrow_default_constructible<allocator_type>{}()
    && ::portable_stl::is_nothrow_copy_constructible<key_compare>{}())
      : m_tree(t_value_compare(comp)) {
  }

  /**
   * @brief (3) Constructs new empty multimap using user supplied allocator alloc and comparison function object comp.
   *
   * @param comp Comparison function object to use for all comparisons of keys.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  explicit multimap(key_compare const &comp, allocator_type const &alloc)
      : m_tree(t_value_compare(comp), typename t_base_tree_type::allocator_type(alloc)) {
  }

  /**
   * @brief (3) Constructs new empty multimap using user supplied allocator alloc.
   *
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  explicit multimap(allocator_type const &alloc) : m_tree(typename t_base_tree_type::allocator_type(alloc)) {
  }

  /**
   * @brief (4) Constructs the container with the contents of the range [first, last). If [first, last) is not a valid
   * range, the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param comp Comparison function object to use for all comparisons of keys.
   */
  template<class t_input_iterator>
  multimap(t_input_iterator first, t_input_iterator last, key_compare const &comp = key_compare())
      : m_tree(t_value_compare(comp)) {
    auto insert_result = insert(first, last);
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert_result);
  }

  /**
   * @brief (4) Makes the container with the contents of the range [first, last). If [first, last) is not a valid range,
   * the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param comp Comparison function object to use for all comparisons of keys.
   */
  template<class t_input_iterator>
  static ::portable_stl::expected<multimap, ::portable_stl::portable_stl_error> make_multimap(
    t_input_iterator first, t_input_iterator last, key_compare const &comp = key_compare()) {
    return make_multimap(first, last, comp, allocator_type());
  }

  /**
   * @brief (5) Constructs the container with the contents of the range [first, last). If [first, last) is not a valid
   * range, the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param comp Comparison function object to use for all comparisons of keys.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  template<class t_input_iterator>
  multimap(t_input_iterator first, t_input_iterator last, key_compare const &comp, allocator_type const &alloc)
      : m_tree(t_value_compare(comp), typename t_base_tree_type::allocator_type(alloc)) {
    auto insert_result = insert(first, last);
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert_result);
  }

  /**
   * @brief (5) Makes the container with the contents of the range [first, last). If [first, last) is not a valid
   * range, the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param comp Comparison function object to use for all comparisons of keys.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  template<class t_input_iterator>
  static ::portable_stl::expected<multimap, ::portable_stl::portable_stl_error> make_multimap(
    t_input_iterator first, t_input_iterator last, key_compare const &comp, allocator_type const &alloc) {
    multimap ret(comp, alloc);
    return ret.insert(first, last).and_then([&ret](void) -> ::portable_stl::expected<multimap, ::portable_stl::portable_stl_error> {
      return {::portable_stl::in_place_t{}, ::portable_stl::move(ret)};
    });
  }

  /**
   * @brief (5) Constructs the container with the contents of the range [first, last). If [first, last) is not a valid
   * range, the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  template<class t_input_iterator>
  multimap(t_input_iterator first, t_input_iterator last, allocator_type const &alloc)
      : multimap(first, last, key_compare(), alloc) {
  }

  /**
   * @brief (5) Makes the container with the contents of the range [first, last). If [first, last) is not a valid
   * range, the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  template<class t_input_iterator>
  static ::portable_stl::expected<multimap, ::portable_stl::portable_stl_error> make_multimap(
    t_input_iterator first, t_input_iterator last, allocator_type const &alloc) {
    return make_multimap(first, last, key_compare(), alloc);
  }

  /**
   * @brief (6) Copy constructor. Constructs the container with the copy of the contents of other.
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   */
  multimap(multimap const &other)
      : m_tree(other.m_tree.value_comp(),
               t_allocator_traits::select_on_container_copy_construction(other.m_tree.get_alloc())) {
    auto insert_result = insert(other.begin(), other.end());
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert_result);
  }

  /**
   * @brief (7) Copy constructor. Constructs the container with the copy of the contents of other.
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  multimap(multimap const &other, allocator_type const &alloc)
      : m_tree(other.m_tree.value_comp(), typename t_base_tree_type::allocator_type(alloc)) {
    auto insert_result = insert(other.begin(), other.end());
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert_result);
  }

  /**
   * @brief Move constructor. Constructs the container with the contents of other using move semantics. If alloc is
   * not provided, allocator is obtained by move-construction from the allocator belonging to other.
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   */
  multimap(multimap &&other) noexcept(::portable_stl::is_nothrow_move_constructible<t_base_tree_type>{}())
      : m_tree(::portable_stl::move(other.m_tree)) {
  }

  /**
   * @brief Move constructor. Constructs the container with the contents of other using move semantics. If alloc is
   * not provided, allocator is obtained by move-construction from the allocator belonging to other.
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  multimap(multimap &&other, allocator_type const &alloc);

  /**
   * @brief Initializer-list constructor. Constructs the container with the contents of the initializer list init.
   *
   * @param init_list Initializer list to initialize the elements of the container with.
   * @param comp Comparison function object to use for all comparisons of keys.
   */
  multimap(std::initializer_list<value_type> init_list, key_compare const &comp = key_compare())
      : m_tree(t_value_compare(comp)) {
    auto insert_result = insert(init_list.begin(), init_list.end());
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert_result);
  }

  /**
   * @brief Initializer-list constructor. Constructs the container with the contents of the initializer list init.
   *
   * @param init_list Initializer list to initialize the elements of the container with.
   * @param comp Comparison function object to use for all comparisons of keys.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  multimap(std::initializer_list<value_type> init_list, key_compare const &comp, allocator_type const &alloc)
      : m_tree(t_value_compare(comp), typename t_base_tree_type::allocator_type(alloc)) {
    auto insert_result = insert(init_list.begin(), init_list.end());
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert_result);
  }

  /**
   * @brief (11) Initializer-list constructor. Constructs the container with the contents of the initializer list init.
   *
   * @param init_list Initializer list to initialize the elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  multimap(std::initializer_list<value_type> init_list, allocator_type const &alloc)
      : multimap(init_list, key_compare(), alloc) {
  }

  /**
   * @brief A destructor. Destructs the multimap. The destructors of the elements are called and the used storage is
   * deallocated. Note, that if the elements are pointers, the pointed-to objects are not destroyed.
   */
  ~multimap() {
  }

  /**
   * @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
   *
   * @param other Another container to use as data source.
   * @return map& *this.
   */
  multimap &operator=(multimap const &other) {
    m_tree = other.m_tree;
    return *this;
  }

  /**
   * @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in
   * other is moved from other into this container). other is in a valid but unspecified state afterwards.
   *
   * @param other Another container to use as data source.
   * @return map& *this.
   */
  multimap &operator=(multimap &&other) noexcept(::portable_stl::is_nothrow_move_assignable<t_base_tree_type>{}()) {
    m_tree = ::portable_stl::move(other.m_tree);
    return *this;
  }

  /**
   * @brief Replaces the contents with those identified by initializer list init_list.
   *
   * @param init_list Initializer list to use as data source.
   * @return map& *this.
   */
  multimap &operator=(std::initializer_list<value_type> init_list) {
    m_tree.assign_multi(init_list.begin(), init_list.end());
    return *this;
  }

  /**
   * @brief Returns the allocator associated with the container.
   *
   * @return allocator_type The associated allocator.
   */
  allocator_type get_allocator() const noexcept {
    return allocator_type(m_tree.get_alloc());
  }

  // [iterators]

  /**
   * @brief Returns an iterator to the first element of the multimap.
   * If the multimap is empty, the returned iterator will be equal to end().
   * @return iterator Iterator to the first element.
   */
  iterator begin() noexcept {
    return m_tree.begin();
  }

  /**
   * @brief Returns an constant iterator to the first element of the multimap.
   * If the multimap is empty, the returned iterator will be equal to end().
   * @return const_iterator Iterator to the first element.
   */
  const_iterator begin() const noexcept {
    return m_tree.begin();
  }

  /**
   * @brief Returns an iterator to the element following the last element of the multimap.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   * @return iterator Iterator to the element following the last element.
   */
  iterator end() noexcept {
    return m_tree.end();
  }

  /**
   * @brief Returns an constant iterator to the element following the last element of the multimap.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   * @return const_iterator Iterator to the element following the last element.
   */
  const_iterator end() const noexcept {
    return m_tree.end();
  }

  /**
   * @brief Returns a reverse iterator to the first element of the reversed multimap. It corresponds to the last element
   * of the non-reversed multimap. If the multimap is empty, the returned iterator is equal to rend().
   *
   * @return reverse_iterator Reverse iterator to the first element.
   */
  reverse_iterator rbegin() noexcept {
    return reverse_iterator(end());
  }

  /**
   * @brief Returns a constant reverse iterator to the first element of the reversed multimap. It corresponds to the
   * last element of the non-reversed multimap. If the multimap is empty, the returned iterator is equal to rend().
   *
   * @return const_reverse_iterator Reverse iterator to the first element.
   */
  const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator(end());
  }

  /**
   * @brief Returns a reverse iterator to the element following the last element of the reversed multimap. It
   * corresponds to the element preceding the first element of the non-reversed multimap. This element acts as a
   * placeholder, attempting to access it results in undefined behavior.
   *
   * @return reverse_iterator Reverse iterator to the element following the last element.
   */
  reverse_iterator rend() noexcept {
    return reverse_iterator(begin());
  }

  /**
   * @brief Returns a constant reverse iterator to the element following the last element of the reversed multimap. It
   * corresponds to the element preceding the first element of the non-reversed multimap. This element acts as a
   * placeholder, attempting to access it results in undefined behavior.
   *
   * @return const_reverse_iterator Reverse iterator to the element following the last element.
   */
  const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator(begin());
  }

  /**
   * @brief Returns an constant iterator to the first element of the multimap.
   * If the multimap is empty, the returned iterator will be equal to end().
   * @return const_iterator Iterator to the first element.
   */
  const_iterator cbegin() const noexcept {
    return begin();
  }

  /**
   * @brief Returns an constant iterator to the element following the last element of the multimap.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   * @return const_iterator Iterator to the element following the last element.
   */
  const_iterator cend() const noexcept {
    return end();
  }

  /**
   * @brief Returns a constant reverse iterator to the first element of the reversed multimap. It corresponds to the
   * last element of the non-reversed multimap. If the multimap is empty, the returned iterator is equal to rend().
   *
   * @return const_reverse_iterator Reverse iterator to the first element.
   */
  const_reverse_iterator crbegin() const noexcept {
    return rbegin();
  }

  /**
   * @brief Returns a constant reverse iterator to the element following the last element of the reversed multimap. It
   * corresponds to the element preceding the first element of the non-reversed multimap. This element acts as a
   * placeholder, attempting to access it results in undefined behavior.
   *
   * @return const_reverse_iterator Reverse iterator to the element following the last element.
   */
  const_reverse_iterator crend() const noexcept {
    return rend();
  }

  // [capacity]

  /**
   * @brief Checks if the container has no elements, i.e. whether begin() == end().
   *
   * @return true if the container is empty,
   * @return false otherwise.
   */
  bool empty() const noexcept {
    return m_tree.size() == 0;
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

  // [observers]

  /**
   * @brief Returns the function object that compares the keys, which is a copy of this container's constructor argument
   * comp.
   *
   * @return key_compare The key comparison function object.
   */
  key_compare key_comp() const {
    return m_tree.value_comp().key_comp();
  }

  /**
   * @brief Returns a function object that compares objects of type ::multimap::value_type (key-value pairs) by using
   * key_comp to compare the first components of the pairs.
   *
   * @return value_compare The value comparison function object.
   */
  value_compare value_comp() const {
    return value_compare(m_tree.value_comp().key_comp());
  }

  // [modifiers]

  /**
   * @brief Inserts a new element into the multimap constructed in-place with the given args. The constructor of the
   * new element (i.e. ::tuple<const Key, T>) is called with exactly the same arguments as supplied to emplace,
   * forwarded via ::forward<Args>(args).... Careful use of emplace allows the new element to be constructed while
   * avoiding unnecessary copy or move operations. No iterators or references are invalidated.
   *
   * @tparam t_args
   * @param args Arguments to forward to the constructor of the element.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> An iterator to the inserted element.
   */
  template<class... t_args>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> emplace(t_args &&...args) {
    return m_tree.emplace_multi(::portable_stl::forward<t_args>(args)...);
  }

  /**
   * @brief Inserts a new element into the multimap as close as possible to the position just before hint. The
   * constructor of the element type (value_type, that is, ::tuple<const Key, T>) is called with exactly the same
   * arguments as supplied to the function, forwarded with ::forward<Args>(args).... No iterators or references are
   * invalidated.
   *
   * @tparam t_args
   * @param hint_pos Iterator to the position before which the new element will be inserted.
   * @param args Arguments to forward to the constructor of the element.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> An iterator to the inserted element.
   */
  template<class... t_args>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> emplace_hint(const_iterator hint_pos,
                                                                                      t_args &&...args) {
    return m_tree.emplace_hint_multi(hint_pos.m_iter, ::portable_stl::forward<t_args>(args)...);
  }

  /**
   * @brief Erases all elements from the container. After this call, size() returns zero.
   * Invalidates any references, pointers, and iterators referring to contained elements. Any past-the-end iterator
   * remains valid.
   *
   */
  void clear() noexcept {
    m_tree.clear();
  }

  /**
   * @brief (1) Inserts value. If the container has elements with equivalent key, inserts at the upper bound of that
   * range.
   *
   * @param value Element value to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> An iterator to the inserted element.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(value_type const &value) {
    return m_tree.insert_multi(value);
  }

  /**
   * @brief (2) Inserts value. If the container has elements with equivalent key, inserts at the upper bound of that
   * range.
   *
   * @param value Element value to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> An iterator to the inserted element.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(value_type &&value) {
    return m_tree.insert_multi(::portable_stl::move(value));
  }

  /**
   * @brief (3) Inserts value. If the container has elements with equivalent key, inserts at the upper bound of that
   * range.
   *
   * @tparam t_like_value
   * @param value Element value to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> An iterator to the inserted element.
   */
  template<
    class t_like_value,
    class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_constructible<value_type, t_like_value>>>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(t_like_value &&value) {
    return m_tree.insert_multi(::portable_stl::forward<t_like_value>(value));
  }

  /**
   * @brief Inserts value in the position as close as possible to the position just prior to pos.
   *
   * @param pos Iterator to the position before which the new element will be inserted.
   * @param value Element value to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> An iterator to the inserted element.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(const_iterator    pos,
                                                                                value_type const &value) {
    return m_tree.insert_multi(pos.m_iter, value);
  }

  /**
   * @brief Inserts value in the position as close as possible to the position just prior to pos.
   *
   * @param pos Iterator to the position before which the new element will be inserted.
   * @param value Element value to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> An iterator to the inserted element.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(const_iterator pos,
                                                                                value_type   &&value) {
    return m_tree.insert_multi(pos.m_iter, ::portable_stl::move(value));
  }

  /**
   * @brief Inserts value in the position as close as possible to the position just prior to pos.
   *
   * @tparam t_like_value
   * @param pos Iterator to the position before which the new element will be inserted.
   * @param value Element value to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> An iterator to the inserted element.
   */
  template<
    class t_like_value,
    class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_constructible<value_type, t_like_value>>>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(const_iterator pos,
                                                                                t_like_value &&value) {
    return m_tree.insert_multi(pos.m_iter, ::portable_stl::forward<t_like_value>(value));
  }

  /**
   * @brief Inserts elements from range [first, last).
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first Range of elements to insert.
   * @param last Range of elements to insert.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>
   */
  template<class t_input_iterator>
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> insert(t_input_iterator first,
                                                                            t_input_iterator last) {
    for (const_iterator end_pos = cend(); first != last; ++first) {
      auto result = insert(end_pos.m_iter, *first);
      if (!result) {
        return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
      }
    }
    return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
  }

  /**
   * @brief Inserts elements from initializer list init_list.
   *
   * @param init_list Initializer list to insert the values from.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> insert(initializer_list<value_type> init_list) {
    return insert(init_list.begin(), init_list.end());
  }

  /**
   * @brief If node_hdl is an empty node handle, does nothing. Otherwise, inserts the element owned by node_hdl into the
   * container and returns an iterator pointing at the inserted element. If a range containing elements with keys
   * equivalent to node_hdl.key() exists in the container, the element is inserted at the end of that range. The
   * behavior is undefined if node_hdl is not empty and get_allocator() != node_hdl.get_allocator().
   *
   * @param node_hdl A compatible node handle.
   * @return iterator End iterator if node_hdl was empty, iterator pointing to the inserted element otherwise.
   */
  iterator insert(node_type &&node_hdl) {
    return m_tree.template node_handle_insert_multi<node_type>(::portable_stl::move(node_hdl));
  }

  /**
   * @brief If node_hdl is an empty node handle, does nothing and returns the end iterator. Otherwise, inserts the
   * element owned by node_hdl into the container, and returns the iterator pointing to the element with key equivalent
   * to node_hdl.key(). The element is inserted as close as possible to the position just prior to pos. The behavior is
   * undefined if node_hdl is not empty and get_allocator() != node_hdl.get_allocator().
   *
   * @param hint_pos Aterator to the position before which the new element will be inserted.
   * @param node_hdl A compatible node handle.
   * @return iterator End iterator if node_hdl was empty, iterator pointing to the inserted element otherwise.
   */
  iterator insert(const_iterator hint_pos, node_type &&node_hdl) {
    return m_tree.template node_handle_insert_multi<node_type>(hint_pos.m_iter, ::portable_stl::move(node_hdl));
  }

  /**
   * @brief Removes the element at pos from the container. The order of the remaining equivalent elements is preserved.
   *
   * @param pos Iterator to the element to remove.
   * @return iterator Iterator following the last removed element.
   */
  iterator erase(const_iterator pos) {
    return m_tree.erase(pos.m_iter);
  }

  /**
   * @brief Removes the element at pos from the container. The order of the remaining equivalent elements is preserved.
   *
   * @param pos Iterator to the element to remove.
   * @return iterator Iterator following the last removed element.
   */
  iterator erase(iterator pos) {
    return m_tree.erase(pos.m_iter);
  }

  /**
   * @brief Removes the elements in the range [first, last), which must be a valid range in *this, from the container.
   * The order of the remaining equivalent elements is preserved.
   *
   * @param first Range of elements to remove.
   * @param last Range of elements to remove.
   * @return iterator Iterator following the last removed element.
   */
  iterator erase(const_iterator first, const_iterator last) {
    return m_tree.erase(first.m_iter, last.m_iter);
  }

  /**
   * @brief Removes all elements with the key equivalent to key from the container.
   *
   * @param key Key value of the elements to remove.
   * @return size_type Number of elements removed.
   */
  size_type erase(key_type const &key) {
    return m_tree.erase_multi(key);
  }

  /**
   * @brief Unlinks the node that contains the element pointed to by position and returns a node handle that owns it.
   *
   * @param pos A valid iterator into this container.
   * @return node_type A node handle that owns the extracted element.
   */
  node_type extract(const_iterator pos) {
    return m_tree.template node_handle_extract<node_type>(pos.m_iter);
  }

  /**
   * @brief If the container has an element with key equivalent to 'key', unlinks the node that contains the first such
   * element from the container and returns a node handle that owns it. Otherwise, returns an empty node handle.
   *
   * @param key A key to identify the node to be extracted.
   * @return node_type A node handle that owns the extracted element, or empty node handle in case the element is not
   * found.
   */
  node_type extract(key_type const &key) {
    return m_tree.template node_handle_extract<node_type>(key);
  }

  /**
   * @brief Attempts to extract ("splice") each element in source and insert it into *this using the comparison object
   * of *this.
   * No elements are copied or moved, only the internal pointers of the container nodes are repointed. All pointers and
   * references to the transferred elements remain valid, but now refer into *this, not into source.
   * The behavior is undefined if get_allocator() != source.get_allocator().
   *
   * @tparam t_compare2
   * @param source Compatible container to transfer the nodes from.
   */
  template<class t_compare2>
  void merge(::portable_stl::map<key_type, mapped_type, t_compare2, allocator_type> &source) {
    return m_tree.node_handle_merge_multi(source.m_tree);
  }

  /**
   * @brief Attempts to extract ("splice") each element in source and insert it into *this using the comparison object
   * of *this.
   * No elements are copied or moved, only the internal pointers of the container nodes are repointed. All pointers and
   * references to the transferred elements remain valid, but now refer into *this, not into source.
   * The behavior is undefined if get_allocator() != source.get_allocator().
   *
   * @tparam t_compare2
   * @param source Compatible container to transfer the nodes from.
   */
  template<class t_compare2>
  void merge(::portable_stl::map<key_type, mapped_type, t_compare2, allocator_type> &&source) {
    return m_tree.node_handle_merge_multi(source.m_tree);
  }

  /**
   * @brief Attempts to extract ("splice") each element in source and insert it into *this using the comparison object
   * of *this.
   * No elements are copied or moved, only the internal pointers of the container nodes are repointed. All pointers and
   * references to the transferred elements remain valid, but now refer into *this, not into source.
   * The behavior is undefined if get_allocator() != source.get_allocator().
   *
   * @tparam t_compare2
   * @param source Compatible container to transfer the nodes from.
   */
  template<class t_compare2> void merge(multimap<key_type, mapped_type, t_compare2, allocator_type> &source) {
    return m_tree.node_handle_merge_multi(source.m_tree);
  }

  /**
   * @brief Attempts to extract ("splice") each element in source and insert it into *this using the comparison object
   * of *this.
   * No elements are copied or moved, only the internal pointers of the container nodes are repointed. All pointers and
   * references to the transferred elements remain valid, but now refer into *this, not into source.
   * The behavior is undefined if get_allocator() != source.get_allocator().
   *
   * @tparam t_compare2
   * @param source Compatible container to transfer the nodes from.
   */
  template<class t_compare2> void merge(multimap<key_type, mapped_type, t_compare2, allocator_type> &&source) {
    return m_tree.node_handle_merge_multi(source.m_tree);
  }

  /**
   * @brief Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap
   * operations on individual elements.
   *
   * @param other Container to exchange the contents with.
   */
  void swap(multimap &other) noexcept(::portable_stl::is_nothrow_swappable<t_base_tree_type>{}()) {
    m_tree.swap(other.m_tree);
  }

  // [lookup]

  /**
   * @brief Finds an element with key equivalent to 'key'. If there are several elements with the requested key in the
   * container, any of them may be returned.
   *
   * @param key Key value of the element to search for.
   * @return iterator An iterator to the requested element. If no such element is found, past-the-end (see end())
   * iterator is returned.
   */
  iterator find(key_type const &key) {
    return m_tree.find(key);
  }

  /**
   * @brief Finds an element with key equivalent to 'key'. If there are several elements with the requested key in the
   * container, any of them may be returned.
   *
   * @param key Key value of the element to search for.
   * @return const_iterator Constant iterator to the requested element. If no such element is found, past-the-end (see
   * end()) iterator is returned.
   */
  const_iterator find(key_type const &key) const {
    return m_tree.find(key);
  }

  /**
   * @brief Finds an element with key that compares equivalent to the value key_like. This overload participates in
   * overload resolution only if the qualified-id Compare::is_transparent is valid and denotes a type. It allows calling
   * this function without constructing an instance of Key.
   *
   * @tparam t_key_like_type
   * @param key_like A value of any type that can be transparently compared with a key.
   * @return iterator An iterator to the requested element. If no such element is found, past-the-end (see end())
   * iterator is returned.
   */
  template<typename t_key_like_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_like_type>, void *>
           = nullptr>
  iterator find(t_key_like_type const &key_like) {
    return m_tree.find(key_like);
  }

  /**
   * @brief Finds an element with key that compares equivalent to the value key_like. This overload participates in
   * overload resolution only if the qualified-id Compare::is_transparent is valid and denotes a type. It allows calling
   * this function without constructing an instance of Key.
   *
   * @tparam t_key_like_type
   * @param key_like A value of any type that can be transparently compared with a key.
   * @return const_iterator Constant iterator to the requested element. If no such element is found, past-the-end (see
   * end()) iterator is returned.
   */
  template<typename t_key_like_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_like_type>, void *>
           = nullptr>
  const_iterator find(t_key_like_type const &key_like) const {
    return m_tree.find(key_like);
  }

  /**
   * @brief Returns the number of elements with key 'key'.
   *
   * @param key	Key value of the elements to count
   * @return size_type Number of elements with key that compares equivalent to key.
   */
  size_type count(key_type const &key) const {
    return m_tree.count_multi(key);
  }

  /**
   * @brief Returns the number of elements with key that compares equivalent to the value t_key_like_type. This overload
   * participates in overload resolution only if the qualified-id Compare::is_transparent is valid and denotes a type.
   * It allows calling this function without constructing an instance of Key.
   *
   * @tparam t_key_like_type
   * @param key_like Alternative value to compare to the keys.
   * @return Number of elements with key that compares equivalent to key_like.
   */
  template<typename t_key_like_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_like_type>, void *>
           = nullptr>
  size_type count(t_key_like_type const &key_like) const {
    return m_tree.count_multi(key_like);
  }

  /**
   * @brief Checks if there is an element with key equivalent to 'key' in the container.
   *
   * @param key Key value of the element to search for.
   * @return true if there is such an element,
   * @return false otherwise.
   */
  bool contains(key_type const &key) const {
    return find(key) != end();
  }

  /**
   * @brief Checks if there is an element with key that compares equivalent to the value 'key_like'. This overload
   * participates in overload resolution only if the qualified-id Compare::is_transparent is valid and denotes a type.
   * It allows calling this function without constructing an instance of Key.
   *
   * @tparam t_key_like_type
   * @param key_like A value of any type that can be transparently compared with a key.
   * @return true if there is such an element,
   * @return false otherwise.
   */
  template<typename t_key_like_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_like_type>, void *>
           = nullptr>
  bool contains(t_key_like_type const &key_like) const {
    return find(key_like) != end();
  }

  /**
   * @brief Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) 'key'.
   *
   * @param key Key value to compare the elements to.
   * @return iterator Iterator pointing to the first element that is not less than key. If no such element is found, a
   * past-the-end iterator (see end()) is returned.
   */
  iterator lower_bound(key_type const &key) {
    return m_tree.lower_bound(key);
  }

  /**
   * @brief Returns a constant iterator pointing to the first element that is not less than (i.e. greater or equal to)
   * 'key'.
   *
   * @param key Key value to compare the elements to.
   * @return const_iterator Iterator pointing to the first element that is not less than key. If no such element is
   * found, a past-the-end iterator (see end()) is returned.
   */
  const_iterator lower_bound(key_type const &key) const {
    return m_tree.lower_bound(key);
  }

  /**
   * @brief Returns an iterator pointing to the first element that compares not less (i.e. greater or equal) to the
   * value 'key_like'. This overload participates in overload resolution only if the qualified-id
   * Compare::is_transparent is valid and denotes a type. It allows calling this function without constructing an
   * instance of Key.
   *
   * @tparam t_key_like_type
   * @param key_like Alternative value that can be compared to Key.
   * @return iterator Iterator pointing to the first element that is not less than key. If no such element is found, a
   * past-the-end iterator (see end()) is returned.
   */
  template<typename t_key_like_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_like_type>, void *>
           = nullptr>
  iterator lower_bound(t_key_like_type const &key_like) {
    return m_tree.lower_bound(key_like);
  }

  /**
   * @brief Returns a constant iterator pointing to the first element that compares not less (i.e. greater or equal) to
   * the value 'key_like'. This overload participates in overload resolution only if the qualified-id
   * Compare::is_transparent is valid and denotes a type. It allows calling this function without constructing an
   * instance of Key.
   *
   * @tparam t_key_like_type
   * @param key_like Alternative value that can be compared to Key.
   * @return const_iterator Iterator pointing to the first element that is not less than key. If no such element is
   * found, a past-the-end iterator (see end()) is returned.
   */
  template<typename t_key_like_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_like_type>, void *>
           = nullptr>
  const_iterator lower_bound(t_key_like_type const &key_like) const {
    return m_tree.lower_bound(key_like);
  }

  /**
   * @brief Returns an iterator pointing to the first element that is greater than 'key'.
   *
   * @param key Key value to compare the elements to.
   * @return iterator Iterator pointing to the first element that is greater than key. If no such element is found,
   * past-the-end (see end()) iterator is returned.
   */
  iterator upper_bound(key_type const &key) {
    return m_tree.upper_bound(key);
  }

  /**
   * @brief Returns a constant iterator pointing to the first element that is greater than 'key'.
   *
   * @param key Key value to compare the elements to.
   * @return const_iterator Iterator pointing to the first element that is greater than key. If no such element is
   * found, past-the-end (see end()) iterator is returned.
   */
  const_iterator upper_bound(key_type const &key) const {
    return m_tree.upper_bound(key);
  }

  /**
   * @brief Returns an iterator pointing to the first element that compares greater to the value 'key_like'. This
   * overload participates in overload resolution only if the qualified-id Compare::is_transparent is valid and denotes
   * a type. It allows calling this function without constructing an instance of Key.
   *
   * @tparam t_key_like_type
   * @param key_like Alternative value that can be compared to Key.
   * @return iterator Iterator pointing to the first element that is greater than key. If no such element is found,
   * past-the-end (see end()) iterator is returned.
   */
  template<typename t_key_like_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_like_type>, void *>
           = nullptr>
  iterator upper_bound(t_key_like_type const &key_like) {
    return m_tree.upper_bound(key_like);
  }

  /**
   * @brief Returns a constant iterator pointing to the first element that compares greater to the value 'key_like'.
   * This overload participates in overload resolution only if the qualified-id Compare::is_transparent is valid and
   * denotes a type. It allows calling this function without constructing an instance of Key.
   *
   * @tparam t_key_like_type
   * @param key_like Alternative value that can be compared to Key.
   * @return const_iterator Iterator pointing to the first element that is greater than key. If no such element is
   * found, past-the-end (see end()) iterator is returned.
   */
  template<typename t_key_like_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_like_type>, void *>
           = nullptr>
  const_iterator upper_bound(t_key_like_type const &key_like) const {
    return m_tree.upper_bound(key_like);
  }

  /**
   * @brief Returns a range containing all elements with the given key in the container. The range is defined by two
   * iterators, one pointing to the first element that is not less than key and another pointing to the first element
   * greater than key. Alternatively, the first iterator may be obtained with lower_bound(), and the second with
   * upper_bound().
   * Compares the keys to 'key'.
   *
   * @param key Key value to compare the elements to.
   * @return ::portable_stl::tuple<iterator, iterator> ::tuple<> containing a pair of iterators defining the wanted
   * range: the first pointing to the first element that is not less than 'key' and the second pointing to the first
   * element greater than 'key'. If there are no elements not less than 'key', past-the-end (see end()) iterator is
   * returned as the first element. Similarly if there are no elements greater than 'key', past-the-end iterator is
   * returned as the second element.
   */
  ::portable_stl::tuple<iterator, iterator> equal_range(key_type const &key) {
    return m_tree.equal_range_multi(key);
  }

  /**
   * @brief Returns a constant range containing all elements with the given key in the container. The range is defined
   * by two iterators, one pointing to the first element that is not less than key and another pointing to the first
   * element greater than key. Alternatively, the first iterator may be obtained with lower_bound(), and the second with
   * upper_bound().
   * Compares the keys to 'key'.
   *
   * @param key Key value to compare the elements to.
   * @return ::portable_stl::tuple<iterator, iterator> ::tuple<> containing a pair of constant iterators defining the
   * wanted range: the first pointing to the first element that is not less than 'key' and the second pointing to the
   * first element greater than 'key'. If there are no elements not less than 'key', past-the-end (see end()) iterator
   * is returned as the first element. Similarly if there are no elements greater than 'key', past-the-end iterator is
   * returned as the second element.
   */
  ::portable_stl::tuple<const_iterator, const_iterator> equal_range(key_type const &key) const {
    return m_tree.equal_range_multi(key);
  }

  /**
   * @brief Returns a range containing all elements with the given key in the container. The range is defined by two
   * iterators, one pointing to the first element that is not less than key and another pointing to the first element
   * greater than key. Alternatively, the first iterator may be obtained with lower_bound(), and the second with
   * upper_bound().
   * Compares the keys to the value 'key_like'. This overload participates in overload resolution only if the
   * qualified-id Compare::is_transparent is valid and denotes a type. It allows calling this function without
   * constructing an instance of Key.
   *
   * @tparam t_key_like_type
   * @param key_like Alternative value that can be compared to Key.
   * @return ::portable_stl::tuple<iterator, iterator> ::tuple<> containing a pair of iterators defining the wanted
   * range: the first pointing to the first element that is not less than 'key' and the second pointing to the first
   * element greater than 'key'. If there are no elements not less than 'key', past-the-end (see end()) iterator is
   * returned as the first element. Similarly if there are no elements greater than 'key', past-the-end iterator is
   * returned as the second element.
   */
  template<typename t_key_like_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_like_type>, void *>
           = nullptr>
  ::portable_stl::tuple<iterator, iterator> equal_range(t_key_like_type const &key_like) {
    return m_tree.equal_range_multi(key_like);
  }

  /**
   * @brief Returns a constant range containing all elements with the given key in the container. The range is defined
   * by two iterators, one pointing to the first element that is not less than key and another pointing to the first
   * element greater than key. Alternatively, the first iterator may be obtained with lower_bound(), and the second with
   * upper_bound().
   * Compares the keys to the value 'key_like'. This overload participates in overload resolution only if the
   * qualified-id Compare::is_transparent is valid and denotes a type. It allows calling this function without
   * constructing an instance of Key.
   *
   * @tparam t_key_like_type
   * @param key_like Alternative value that can be compared to Key.
   * @return ::portable_stl::tuple<iterator, iterator> ::tuple<> containing a pair of constant iterators defining the
   * wanted range: the first pointing to the first element that is not less than 'key' and the second pointing to the
   * first element greater than 'key'. If there are no elements not less than 'key', past-the-end (see end()) iterator
   * is returned as the first element. Similarly if there are no elements greater than 'key', past-the-end iterator is
   * returned as the second element.
   */
  template<typename t_key_like_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_key_like_type>, void *>
           = nullptr>
  ::portable_stl::tuple<const_iterator, const_iterator> equal_range(t_key_like_type const &key_like) const {
    return m_tree.equal_range_multi(key_like);
  }

private:
  /**
   * @brief
   */
  using t_node           = typename t_base_tree_type::t_node_type;
  /**
   * @brief
   */
  using t_node_allocator = typename t_base_tree_type::t_node_allocator;
  /**
   * @brief
   */
  using t_node_pointer   = typename t_base_tree_type::t_node_pointer;

  /**
   * @brief
   */
  using t_node_deleter = ::portable_stl::map_node_destructor<t_node_allocator>;
  /**
   * @brief
   */
  using t_node_holder  = ::portable_stl::unique_ptr<t_node, t_node_deleter>;
};

/**
 * @brief Move constructor. Constructs the container with the contents of other using move semantics. If alloc is
 * not provided, allocator is obtained by move-construction from the allocator belonging to other.
 *
 * @tparam t_key Keys type.
 * @tparam t_type Mapped type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param other Another container to be used as source to initialize the elements of the container with.
 * @param alloc Allocator to use for all memory allocations of this container.
 */
template<class t_key, class t_type, class t_compare, class t_allocator>
multimap<t_key, t_type, t_compare, t_allocator>::multimap(multimap &&other, allocator_type const &alloc)
    : m_tree(::portable_stl::move(other.m_tree), typename t_base_tree_type::allocator_type(alloc)) {
  if (alloc != other.get_allocator()) {
    const_iterator c_end = cend();
    while (!other.empty()) {
      auto result = m_tree.insert_multi(
        c_end.m_iter, ::portable_stl::move(other.m_tree.remove(other.begin().m_iter)->m_value.make_move()));
      ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!result);
    }
  }
}

/**
 * @brief Compares the contents of two multimaps.
 *
 * @tparam t_key Keys type.
 * @tparam t_type Mapped type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param lhv Map to compare.
 * @param rhv Map to compare.
 * @return true if the contents of the maps are equal,
 * @return false otherwise.
 */
template<class t_key, class t_type, class t_compare, class t_allocator>
inline bool operator==(multimap<t_key, t_type, t_compare, t_allocator> const &lhv,
                       multimap<t_key, t_type, t_compare, t_allocator> const &rhv) {
  return lhv.size() == rhv.size() && ::portable_stl::equal(lhv.begin(), lhv.end(), rhv.begin());
}

/**
 * @brief Compares the contents of two multimaps.
 *
 * @tparam t_key Keys type.
 * @tparam t_type Mapped type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param lhv Map to compare.
 * @param rhv Map to compare.
 * @return true if if the contents of the maps are not equal,
 * @return false otherwise.
 */
template<class t_key, class t_type, class t_compare, class t_allocator>
inline bool operator!=(multimap<t_key, t_type, t_compare, t_allocator> const &lhv,
                       multimap<t_key, t_type, t_compare, t_allocator> const &rhv) {
  return !(lhv == rhv);
}

/**
 * @brief Compares the contents of two multimaps.
 *
 * @tparam t_key Keys type.
 * @tparam t_type Mapped type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param lhv Map to compare.
 * @param rhv Map to compare.
 * @return true if the contents of the lhs are lexicographically less than the contents of rhs,
 * @return false otherwise.
 */
template<class t_key, class t_type, class t_compare, class t_allocator>
inline bool operator<(multimap<t_key, t_type, t_compare, t_allocator> const &lhv,
                      multimap<t_key, t_type, t_compare, t_allocator> const &rhv) {
  return ::portable_stl::lexicographical_compare(lhv.begin(), lhv.end(), rhv.begin(), rhv.end());
}

/**
 * @brief Compares the contents of two multimaps.
 *
 * @tparam t_key Keys type.
 * @tparam t_type Mapped type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param lhv Map to compare.
 * @param rhv Map to compare.
 * @return true if the contents of the lhs are lexicographically less than or equal to the contents of rhs,
 * @return false otherwise.
 */
template<class t_key, class t_type, class t_compare, class t_allocator>
inline bool operator<=(multimap<t_key, t_type, t_compare, t_allocator> const &lhv,
                       multimap<t_key, t_type, t_compare, t_allocator> const &rhv) {
  return !(rhv < lhv);
}

/**
 * @brief Compares the contents of two multimaps.
 *
 * @tparam t_key Keys type.
 * @tparam t_type Mapped type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param lhv Map to compare.
 * @param rhv Map to compare.
 * @return true if the contents of the lhs are lexicographically greater than the contents of rhs,
 * @return false otherwise.
 */
template<class t_key, class t_type, class t_compare, class t_allocator>
inline bool operator>(multimap<t_key, t_type, t_compare, t_allocator> const &lhv,
                      multimap<t_key, t_type, t_compare, t_allocator> const &rhv) {
  return rhv < lhv;
}

/**
 * @brief Compares the contents of two multimaps.
 *
 * @tparam t_key Keys type.
 * @tparam t_type Mapped type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param lhv Map to compare.
 * @param rhv Map to compare.
 * @return true if the contents of the lhs are lexicographically greater than or equal to the contents of rhs,
 * @return false otherwise.
 */
template<class t_key, class t_type, class t_compare, class t_allocator>
inline bool operator>=(multimap<t_key, t_type, t_compare, t_allocator> const &lhv,
                       multimap<t_key, t_type, t_compare, t_allocator> const &rhv) {
  return !(lhv < rhv);
}

/**
 * @brief Specializes the ::swap algorithm for multimap. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
 *
 * @tparam t_key Keys type.
 * @tparam t_type Mapped type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param lhv Map to swap.
 * @param rhv Map to swap.
 */
template<class t_key, class t_type, class t_compare, class t_allocator>
inline void swap(multimap<t_key, t_type, t_compare, t_allocator> &lhv,
                 multimap<t_key, t_type, t_compare, t_allocator> &rhv) noexcept(noexcept(lhv.swap(rhv))) {
  lhv.swap(rhv);
}

} // namespace portable_stl

#endif // PSTL_MULTIMAP_H
