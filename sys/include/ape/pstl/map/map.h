// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="map.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MAP_H
#define PSTL_MAP_H

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
#include "extract_key_value_types.h"
#include "map_const_iterator.h"
#include "map_iterator.h"
#include "map_node_destructor.h"
#include "map_value_compare.h"
#include "multimap.h"

#if defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  include "../language_support/exception/throw_on_true.h"
#else
#  include "../language_support/no_exception/throw_on_true.h"
#endif

namespace portable_stl {

/**
 * @brief Forward declaration of the multimap.
 *
 */
template<class, class, class, class> class multimap;

/**
 * @brief A sorted associative container that contains key-value pairs with unique keys. Keys are sorted by using the
 * comparison function Compare. Search, removal, and insertion operations have logarithmic complexity.
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
class map {
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

  /**
   * @brief Value compare type.
   *
   */
  class value_compare : public ::portable_stl::binary_function_depr<value_type, value_type, bool> {
    friend class map;

  protected:
    /**
     * @brief Key comparison object.
     *
     */
    key_compare m_comp;

    /**
     * @brief Construct a new value compare object.
     * @param comp
     */
    value_compare(key_compare comp) : m_comp(comp) {
    }

  public:
    /**
     * @brief Comparison function.
     *
     * @param lhv
     * @param rhv
     * @return true
     * @return false
     */
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
   * @brief Constructs new empty map.
   */
  map() noexcept(::portable_stl::is_nothrow_default_constructible<allocator_type>{}()
                 && ::portable_stl::is_nothrow_default_constructible<key_compare>{}()
                 && ::portable_stl::is_nothrow_copy_constructible<key_compare>{}())
      : m_tree(t_value_compare(key_compare())) {
  }

  /**
   * @brief Constructs new empty map using comparison function object comp.
   *
   * @param comp Comparison function object to use for all comparisons of keys.
   */
  explicit map(key_compare const &comp) noexcept(::portable_stl::is_nothrow_default_constructible<allocator_type>{}()
                                                 && ::portable_stl::is_nothrow_copy_constructible<key_compare>{}())
      : m_tree(t_value_compare(comp)) {
  }

  /**
   * @brief Constructs new empty map using user supplied allocator alloc and comparison function object comp.
   *
   * @param comp Comparison function object to use for all comparisons of keys.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  explicit map(key_compare const &comp, allocator_type const &alloc)
      : m_tree(t_value_compare(comp), typename t_base_tree_type::allocator_type(alloc)) {
  }

  /**
   * @brief Constructs new empty map using user supplied allocator alloc.
   *
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  explicit map(allocator_type const &alloc) : m_tree(typename t_base_tree_type::allocator_type(alloc)) {
  }

  /**
   * @brief Constructs the container with the contents of the range [first, last). If multiple elements in the range
   * have keys that compare equivalent, it is unspecified which element is inserted (pending LWG2844). If [first, last)
   * is not a valid range, the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param comp Comparison function object to use for all comparisons of keys.
   */
  template<class t_input_iterator>
  map(t_input_iterator first, t_input_iterator last, key_compare const &comp = key_compare())
      : m_tree(t_value_compare(comp)) {
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert(first, last));
  }

  /**
   * @brief Makes the container with the contents of the range [first, last). If multiple elements in the range
   * have keys that compare equivalent, it is unspecified which element is inserted (pending LWG2844). If [first, last)
   * is not a valid range, the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param comp Comparison function object to use for all comparisons of keys.
   * @return ::portable_stl::expected<map, ::portable_stl::portable_stl_error>.
   */
  template<class t_input_iterator>
  static ::portable_stl::expected<map, ::portable_stl::portable_stl_error> make_map(
    t_input_iterator first, t_input_iterator last, key_compare const &comp = key_compare()) {
    return make_map(first, last, comp, allocator_type());
  }

  /**
   * @brief Constructs the container with the contents of the range [first, last). If multiple elements in the range
   * have keys that compare equivalent, it is unspecified which element is inserted (pending LWG2844). If [first, last)
   * is not a valid range, the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param comp Comparison function object to use for all comparisons of keys.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  template<class t_input_iterator>
  map(t_input_iterator first, t_input_iterator last, key_compare const &comp, allocator_type const &alloc)
      : m_tree(t_value_compare(comp), typename t_base_tree_type::allocator_type(alloc)) {
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert(first, last));
  }

  /**
   * @brief Makes the container with the contents of the range [first, last). If multiple elements in the range
   * have keys that compare equivalent, it is unspecified which element is inserted (pending LWG2844). If [first, last)
   * is not a valid range, the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param comp Comparison function object to use for all comparisons of keys.
   * @param alloc Allocator to use for all memory allocations of this container.
   * @return ::portable_stl::expected<map, ::portable_stl::portable_stl_error>.
   */
  template<class t_input_iterator>
  static ::portable_stl::expected<map, ::portable_stl::portable_stl_error> make_map(
    t_input_iterator first, t_input_iterator last, key_compare const &comp, allocator_type const &alloc) {
    map ret(comp, alloc);
    return ret.insert(first, last)
      .and_then([&ret](void) -> ::portable_stl::expected<map, ::portable_stl::portable_stl_error> {
        return {::portable_stl::in_place_t{}, ::portable_stl::move(ret)};
      });
  }

  /**
   * @brief Constructs the container with the contents of the range [first, last). If multiple elements in the range
   * have keys that compare equivalent, it is unspecified which element is inserted (pending LWG2844). If [first, last)
   * is not a valid range, the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  template<class t_input_iterator>
  map(t_input_iterator first, t_input_iterator last, allocator_type const &alloc)
      : map(first, last, key_compare(), alloc) {
  }

  /**
   * @brief Makes the container with the contents of the range [first, last). If multiple elements in the range
   * have keys that compare equivalent, it is unspecified which element is inserted (pending LWG2844). If [first, last)
   * is not a valid range, the behavior is undefined.
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @param alloc Allocator to use for all memory allocations of this container.
   * @return ::portable_stl::expected<map, ::portable_stl::portable_stl_error>
   */
  template<class t_input_iterator>
  static ::portable_stl::expected<map, ::portable_stl::portable_stl_error> make_map(
    t_input_iterator first, t_input_iterator last, allocator_type const &alloc) {
    return make_map(first, last, key_compare(), alloc);
  }

  /**
   * @brief Copy constructor. Constructs the container with the copy of the contents of other.
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   */
  map(map const &other) : m_tree(other.m_tree) {
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert(other.begin(), other.end()));
  }

  /**
   * @brief Copy constructor. Constructs the container with the copy of the contents of other.
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  map(map const &other, allocator_type const &alloc)
      : m_tree(other.m_tree.value_comp(), typename t_base_tree_type::allocator_type(alloc)) {
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert(other.begin(), other.end()));
  }

  /**
   * @brief Move constructor. Constructs the container with the contents of other using move semantics. If alloc is
   * not provided, allocator is obtained by move-construction from the allocator belonging to other.
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   */
  map(map &&other) noexcept(::portable_stl::is_nothrow_move_constructible<t_base_tree_type>{}())
      : m_tree(::portable_stl::move(other.m_tree)) {
  }

  /**
   * @brief Move constructor. Constructs the container with the contents of other using move semantics. If alloc is
   * not provided, allocator is obtained by move-construction from the allocator belonging to other.
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  map(map &&other, allocator_type const &alloc);

  /**
   * @brief (10) Initializer-list constructor. Constructs the container with the contents of the initializer list init.
   * If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted
   * (pending LWG2844).
   *
   * @param init_list Initializer list to initialize the elements of the container with.
   * @param comp Comparison function object to use for all comparisons of keys.
   */
  map(std::initializer_list<value_type> init_list, key_compare const &comp = key_compare())
      : m_tree(t_value_compare(comp)) {
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert(init_list.begin(), init_list.end()));
  }

  /**
   * @brief Initializer-list constructor. Constructs the container with the contents of the initializer list init.
   * If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted
   * (pending LWG2844).
   *
   * @param init_list Initializer list to initialize the elements of the container with.
   * @param comp Comparison function object to use for all comparisons of keys.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  map(std::initializer_list<value_type> init_list, key_compare const &comp, allocator_type const &alloc)
      : m_tree(t_value_compare(comp), typename t_base_tree_type::allocator_type(alloc)) {
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!insert(init_list.begin(), init_list.end()));
  }

  /**
   * @brief Initializer-list constructor. Constructs the container with the contents of the initializer list init.
   * If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted
   * (pending LWG2844).
   *
   * @param init_list Initializer list to initialize the elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  map(std::initializer_list<value_type> init_list, allocator_type const &alloc) : map(init_list, key_compare(), alloc) {
  }

  /**
   * @brief A destructor. Destructs the map. The destructors of the elements are called and the used storage is
   * deallocated. Note, that if the elements are pointers, the pointed-to objects are not destroyed.
   */
  ~map() {
  }

  /**
   * @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
   *
   * @param other Another container to use as data source.
   * @return map& *this.
   */
  map &operator=(map const &other) {
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
  map &operator=(map &&other) noexcept(::portable_stl::is_nothrow_move_assignable<t_base_tree_type>{}()) {
    m_tree = ::portable_stl::move(other.m_tree);
    return *this;
  }

  /**
   * @brief Replaces the contents with those identified by initializer list init_list.
   *
   * @param init_list Initializer list to use as data source.
   * @return map& *this.
   */
  map &operator=(std::initializer_list<value_type> init_list) {
    m_tree.assign_unique(init_list.begin(), init_list.end());
    return *this;
  }

  /**
   * @brief Returns an iterator to the first element of the map.
   * If the map is empty, the returned iterator will be equal to end().
   * @return iterator Iterator to the first element.
   */
  iterator begin() noexcept {
    return m_tree.begin();
  }

  /**
   * @brief Returns a constant iterator to the first element of the map.
   * If the map is empty, the returned iterator will be equal to end().
   * @return const_iterator Constant iterator to the first element.
   */
  const_iterator begin() const noexcept {
    return m_tree.begin();
  }

  /**
   * @brief Returns an iterator to the element following the last element of the map.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   * @return iterator Iterator to the element following the last element.
   */
  iterator end() noexcept {
    return m_tree.end();
  }

  /**
   * @brief Returns a constant iterator to the element following the last element of the map.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   * @return const_iterator Constant iterator to the element following the last element.
   */
  const_iterator end() const noexcept {
    return m_tree.end();
  }

  /**
   * @brief Returns a reverse iterator to the first element of the reversed map. It corresponds to the last element of
   * the non-reversed map. If the map is empty, the returned iterator is equal to rend().
   *
   * @return reverse_iterator Reverse iterator to the first element.
   */
  reverse_iterator rbegin() noexcept {
    return reverse_iterator(end());
  }

  /**
   * @brief Returns a constant reverse iterator to the first element of the reversed map. It corresponds to the last
   * element of the non-reversed map. If the map is empty, the returned iterator is equal to rend().
   *
   * @return const_reverse_iterator Reverse iterator to the first element.
   */
  const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator(end());
  }

  /**
   * @brief Returns a reverse iterator to the element following the last element of the reversed map. It corresponds to
   * the element preceding the first element of the non-reversed map. This element acts as a placeholder, attempting to
   * access it results in undefined behavior.
   *
   * @return reverse_iterator Reverse iterator to the element following the last element.
   */
  reverse_iterator rend() noexcept {
    return reverse_iterator(begin());
  }

  /**
   * @brief Returns a constant reverse iterator to the element following the last element of the reversed map. It
   * corresponds to the element preceding the first element of the non-reversed map. This element acts as a placeholder,
   * attempting to access it results in undefined behavior.
   *
   * @return const_reverse_iterator Reverse iterator to the element following the last element.
   */
  const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator(begin());
  }

  /**
   * @brief Returns an constant iterator to the first element of the map.
   * If the map is empty, the returned iterator will be equal to end().
   * @return const_iterator Iterator to the first element.
   */
  const_iterator cbegin() const noexcept {
    return begin();
  }

  /**
   * @brief Returns an constant iterator to the element following the last element of the map.
   * This element acts as a placeholder; attempting to access it results in undefined behavior.
   * @return const_iterator Iterator to the element following the last element.
   */
  const_iterator cend() const noexcept {
    return end();
  }

  /**
   * @brief Returns a constant reverse iterator to the first element of the reversed map. It corresponds to the last
   * element of the non-reversed map. If the map is empty, the returned iterator is equal to rend().
   *
   * @return const_reverse_iterator Reverse iterator to the first element.
   */
  const_reverse_iterator crbegin() const noexcept {
    return rbegin();
  }

  /**
   * @brief Returns a constant reverse iterator to the element following the last element of the reversed map. It
   * corresponds to the element preceding the first element of the non-reversed map. This element acts as a placeholder,
   * attempting to access it results in undefined behavior.
   *
   * @return const_reverse_iterator Reverse iterator to the element following the last element.
   */
  const_reverse_iterator crend() const noexcept {
    return rend();
  }

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

  /**
   * @brief Returns the allocator associated with the container.
   *
   * @return allocator_type The associated allocator.
   */
  allocator_type get_allocator() const noexcept {
    return allocator_type(m_tree.get_alloc());
  }

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
   * @brief Returns a function object that compares objects of type ::map::value_type (key-value pairs) by using
   * key_comp to compare the first components of the pairs.
   *
   * @return value_compare The value comparison function object.
   */
  value_compare value_comp() const {
    return value_compare(m_tree.value_comp().key_comp());
  }

  /**
   * @brief Returns a reference to the value that is mapped to a key equivalent to key or x respectively, performing an
   * insertion if such key does not already exist.
   *
   * @param key The key of the element to find.
   * @return mapped_type& A reference to the mapped value of the new element if no element with key key existed.
   * Otherwise, a reference to the mapped value of the existing element whose key is equivalent to key.
   */
  mapped_type &operator[](key_type const &key);

  /**
   * @brief Returns a reference to the value that is mapped to a key equivalent to key or x respectively, performing an
   * insertion if such key does not already exist.
   *
   * @param key The key of the element to find.
   * @return mapped_type& A reference to the mapped value of the new element if no element with key key existed.
   * Otherwise, a reference to the mapped value of the existing element whose key is equivalent to key.
   */
  mapped_type &operator[](key_type &&key);

  /**
   * @brief Returns a reference to the mapped value of the element with specified key. If no such element exists, an
   * exception of type ::out_of_range is thrown.
   *
   * @param key The key of the element to find.
   * @return mapped_type& A reference to the mapped value of the requested element.
   */
  mapped_type &at(key_type const &key);

  /**
   * @brief Returns a reference to the mapped value of the element with specified key. If no such element exists, an
   * exception of type ::out_of_range is thrown.
   *
   * @param key The key of the element to find.
   * @return mapped_type const& A reference to the mapped value of the requested element.
   */
  mapped_type const &at(key_type const &key) const;

  /**
   * @brief Inserts a new element into the container constructed in-place with the given args, if there is no element
   * with the key in the container.
   * The constructor of the new element (i.e. tuple<const Key, t_type>) is called with exactly the same arguments as
   * supplied to emplace, forwarded via ::forward<Args>(args).... The element may be constructed even if there already
   * is an element with the key in the container, in which case the newly constructed element will be destroyed
   * immediately. Careful use of emplace allows the new element to be constructed while avoiding unnecessary copy or
   * move operations. No iterators or references are invalidated.
   *
   * @tparam t_args
   * @param args Arguments to forward to the constructor of the element.
   * @return ::expected<::tuple<iterator, bool>, ::portable_stl_error> A pair
   * consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool value
   * set to true if and only if the insertion took place.
   */
  template<class... t_args>
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> emplace(
    t_args &&...args) {
    return m_tree.emplace_unique(::portable_stl::forward<t_args>(args)...);
  }

  /**
   * @brief Inserts a new element into the container as close as possible to the position just before hint_pos.
   * The constructor of the element type (value_type, that is, tuple<const Key, t_type>) is called with exactly the same
   * arguments as supplied to the function, forwarded with ::forward<Args>(args)... .
   * No iterators or references are invalidated.
   *
   * @tparam t_args
   * @param hint_pos Iterator to the position before which the new element will be inserted.
   * @param args Arguments to forward to the constructor of the element.
   * @return ::expected<iterator, ::portable_stl_error> An iterator to the inserted element, or to the element that
   * prevented the insertion.
   */
  template<class... t_args>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> emplace_hint(const_iterator hint_pos,
                                                                                      t_args &&...args) {
    return m_tree.emplace_hint_unique(hint_pos.m_iter, ::portable_stl::forward<t_args>(args)...);
  }

  /**
   * @brief Inserts value into the container, if the container doesn't already contain an element with an equivalent
   * key.
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
   * @brief Inserts value into the container, if the container doesn't already contain an element with an equivalent
   * key.
   * Is equivalent to emplace(::forward<t_like_value>(value)).
   * @tparam t_like_value
   * @param value Element value to insert.
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
   */
  template<
    class t_like_value,
    class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_constructible<value_type, t_like_value>>>
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> insert(
    t_like_value &&value) {
    return m_tree.insert_unique(::portable_stl::forward<t_like_value>(value));
  }

  /**
   * @brief Inserts value into the container, if the container doesn't already contain an element with an equivalent
   * key.
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
   * @brief Inserts value in the position as close as possible to the position just prior to pos into the container,
   * if the container doesn't already contain an element with an equivalent key.
   *
   * @param pos Iterator to the position before which the new element will be inserted.
   * @param value Element value to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> An iterator to the inserted element,
   * or to the element that prevented the insertion.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(const_iterator    pos,
                                                                                value_type const &value) {
    return m_tree.insert_unique(pos.m_iter, value);
  }

  /**
   * @brief Inserts value in the position as close as possible to the position just prior to pos into the container,
   * if the container doesn't already contain an element with an equivalent key.
   *
   * @param pos Iterator to the position before which the new element will be inserted.
   * @param value Element value to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> An iterator to the inserted element,
   * or to the element that prevented the insertion.
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(const_iterator pos,
                                                                                value_type   &&value) {
    return m_tree.insert_unique(pos.m_iter, ::portable_stl::move(value));
  }

  /**
   * @brief Inserts value in the position as close as possible to the position just prior to pos into the container,
   * if the container doesn't already contain an element with an equivalent key. is equivalent to emplace_hint(pos,
   * ::forward<t_like_value>(value)).
   * @tparam t_like_value
   * @param pos Iterator to the position before which the new element will be inserted.
   * @param value Element value to insert.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> An iterator to the inserted element,
   * or to the element that prevented the insertion.
   */
  template<
    class t_like_value,
    class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_constructible<value_type, t_like_value>>>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(const_iterator pos,
                                                                                t_like_value &&value) {
    return m_tree.insert_unique(pos.m_iter, ::portable_stl::forward<t_like_value>(value));
  }

  /**
   * @brief Inserts elements from range [first, last) into the container, if the container doesn't already contain
   * an element with an equivalent key. If multiple elements in the range have keys that compare equivalent, it is
   * unspecified which element is inserted (pending LWG2844).
   *
   * @tparam t_input_iterator Must meet the requirements of LegacyInputIterator.
   * @param first Range of elements to insert.
   * @param last Range of elements to insert.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>.
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
   * @brief Inserts elements from initializer list init_list into the container, if the container doesn't already
   * contain an element with an equivalent key. If multiple elements in the range have keys that compare equivalent, it
   * is unspecified which element is inserted (pending LWG2844).
   *
   * @param init_list Initializer list to insert the values from.
   * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> insert(initializer_list<value_type> init_list) {
    return insert(init_list.begin(), init_list.end());
  }

  /**
   * @brief If node_hdl is an empty node handle, does nothing. Otherwise, inserts the element owned by node_hdl into
   * the container, if the container doesn't already contain an element with a key equivalent to node_hdl.key(). The
   * behavior is undefined if node_hdl is not empty and get_allocator() != node_hdl.get_allocator().
   *
   * @param node_hdl A compatible node handle.
   * @return insert_return_type An object of insert_return_type with the members initialized as follows:
   * If node_hdl is empty, inserted is false, position is end(), and node is empty.
   * Otherwise if the insertion took place, inserted is true, position points to the inserted element, and node is
   * empty. If the insertion failed, inserted is false, node has the previous value of node_hdl, and position points to
   * an element with a key equivalent to node_hdl.key().
   */
  insert_return_type insert(node_type &&node_hdl) {
    return m_tree.template node_handle_insert_unique<node_type, insert_return_type>(::portable_stl::move(node_hdl));
  }

  /**
   * @brief If node_hdl is an empty node handle, does nothing and returns the end iterator. Otherwise, inserts the
   * element owned by node_hdl into the container, if the container doesn't already contain an element with a key
   * equivalent to node_hdl.key(), and returns the iterator pointing to the element with key equivalent to
   * node_hdl.key()(regardless of whether the insert succeeded or failed). If the insertion succeeds, node_hdl is moved
   * from, otherwise it retains ownership of the element. The element is inserted as close as possible to the position
   * just prior to pos. The behavior is undefined if node_hdl is not empty and get_allocator() !=
   * node_hdl.get_allocator().
   *
   * @param hint_pos Iterator to the position before which the new element will be inserted.
   * @param node_hdl A compatible node handle.
   * @return iterator End iterator if node_hdl was empty, iterator pointing to the inserted element if insertion took
   * place, and iterator pointing to an element with a key equivalent to nh.key() if it failed.
   */
  iterator insert(const_iterator hint_pos, node_type &&node_hdl) {
    return m_tree.template node_handle_insert_unique<node_type>(hint_pos.m_iter, ::portable_stl::move(node_hdl));
  }

  /**
   * @brief If a key equivalent to 'key' already exists in the container, does nothing. Otherwise, inserts a new element
   * into the container with key 'key' and value constructed with args.
   *
   * @tparam t_args
   * @param key The key used both to look up and to insert if not found.
   * @param args arguments to forward to the constructor of the element.
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> A pair
   * consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool value
   * set to true if and only if the insertion took place.
   */
  template<class... t_args>
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> try_emplace(
    key_type const &key, t_args &&...args) {
    return m_tree.emplace_unique_key_args(key,
                                          ::portable_stl::piecewise_construct_t{},
                                          ::portable_stl::forward_as_tuple(key),
                                          ::portable_stl::forward_as_tuple(::portable_stl::forward<t_args>(args)...));
  }

  /**
   * @brief If a key equivalent to 'key' already exists in the container, does nothing. Otherwise, inserts a new element
   * into the container with key 'key' and value constructed with args.
   *
   * @tparam t_args
   * @param key The key used both to look up and to insert if not found.
   * @param args arguments to forward to the constructor of the element.
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> A pair
   * consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool value
   * set to true if and only if the insertion took place.
   */
  template<class... t_args>
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> try_emplace(
    key_type &&key, t_args &&...args) {
    return m_tree.emplace_unique_key_args(key,
                                          ::portable_stl::piecewise_construct_t{},
                                          ::portable_stl::forward_as_tuple(::portable_stl::move(key)),
                                          ::portable_stl::forward_as_tuple(::portable_stl::forward<t_args>(args)...));
  }

  /**
   * @brief If a key equivalent to 'key' already exists in the container, does nothing. Otherwise, inserts a new element
   * into the container with key 'key' and value constructed with args.
   *
   * @tparam t_args
   * @param hint_pos Iterator to the position before which the new element will be inserted.
   * @param key The key used both to look up and to insert if not found.
   * @param args arguments to forward to the constructor of the element.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  template<class... t_args>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> try_emplace(
    const_iterator hint_pos, key_type const &key, t_args &&...args) {
    return m_tree
      .emplace_hint_unique_key_args(hint_pos.m_iter,
                                    key,
                                    ::portable_stl::piecewise_construct_t{},
                                    ::portable_stl::forward_as_tuple(key),
                                    ::portable_stl::forward_as_tuple(::portable_stl::forward<t_args>(args)...))
      .transform([](::portable_stl::tuple<iterator, bool> &&tmp) -> iterator {
        return ::portable_stl::get<0>(::portable_stl::move(tmp));
      });
  }

  /**
   * @brief If a key equivalent to 'key' already exists in the container, does nothing. Otherwise, inserts a new element
   * into the container with key 'key' and value constructed with args.
   *
   * @tparam t_args
   * @param hint_pos Iterator to the position before which the new element will be inserted.
   * @param key The key used both to look up and to insert if not found.
   * @param args arguments to forward to the constructor of the element.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  template<class... t_args>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> try_emplace(
    const_iterator hint_pos, key_type &&key, t_args &&...args) {
    return m_tree
      .emplace_hint_unique_key_args(hint_pos.m_iter,
                                    key,
                                    ::portable_stl::piecewise_construct_t{},
                                    ::portable_stl::forward_as_tuple(::portable_stl::move(key)),
                                    ::portable_stl::forward_as_tuple(::portable_stl::forward<t_args>(args)...))
      .transform([](::portable_stl::tuple<iterator, bool> &&tmp) -> iterator {
        return ::portable_stl::get<0>(::portable_stl::move(tmp));
      });
  }

  /**
   * @brief If a key equivalent to 'key' already exists in the container, assigns ::forward<t_value>(value) to the
   * mapped_type corresponding to the key 'key'. If the key does not exist, inserts the new value as if by insert,
   * constructing it from value_type(key, ::forward<t_value>(value)).
   *
   * @tparam t_value
   * @param key The key used both to look up and to insert if not found.
   * @param value The value to insert or assign.
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> The
   * bool component is true if the insertion took place and false if the assignment took place. The iterator component
   * is pointing at the element that was inserted or updated.
   */
  template<class t_value>
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> insert_or_assign(
    key_type const &key, t_value &&value) {
    iterator ptr = lower_bound(key);
    if ((ptr != end()) && !key_comp()(key, ::portable_stl::get<0>(*ptr))) {
      ::portable_stl::get<1>(*ptr) = ::portable_stl::forward<t_value>(value);
      return {::portable_stl::in_place_t{}, ::portable_stl::make_tuple(ptr, false)};
    }

    return emplace_hint(ptr, key, ::portable_stl::forward<t_value>(value))
      .transform([](iterator &&tmp_iter) -> ::portable_stl::tuple<iterator, bool> {
        return ::portable_stl::make_tuple(portable_stl::move(tmp_iter), true);
      });
  }

  /**
   * @brief If a key equivalent to 'key' already exists in the container, assigns ::forward<t_value>(value) to the
   * mapped_type corresponding to the key 'key'. If the key does not exist, inserts the new value as if by insert,
   * constructing it from value_type(portable_stl::move(key), ::forward<t_value>(value)).
   *
   * @tparam t_value
   * @param key The key used both to look up and to insert if not found.
   * @param value The value to insert or assign.
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> The
   * bool component is true if the insertion took place and false if the assignment took place. The iterator component
   * is pointing at the element that was inserted or updated.
   */
  template<class t_value>
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> insert_or_assign(
    key_type &&key, t_value &&value) {
    iterator ptr = lower_bound(key);
    if ((ptr != end()) && !key_comp()(key, ::portable_stl::get<0>(*ptr))) {
      ::portable_stl::get<1>(*ptr) = ::portable_stl::forward<t_value>(value);

      return {::portable_stl::in_place_t{}, ::portable_stl::make_tuple(ptr, false)};
    }

    return emplace_hint(ptr, ::portable_stl::move(key), ::portable_stl::forward<t_value>(value))
      .transform([](iterator &&tmp_iter) -> ::portable_stl::tuple<iterator, bool> {
        return ::portable_stl::make_tuple(portable_stl::move(tmp_iter), true);
      });
  }

  /**
   * @brief If a key equivalent to 'key' already exists in the container, assigns ::forward<t_value>(value) to the
   * mapped_type corresponding to the key 'key'. If the key does not exist, constructs an object 'u' of value_type with
   * ::forward<K>(key), ::forward<t_value>(value)), then inserts 'u' into *this. If equal_range(u.first) ==
   * equal_range(key) is false, the behavior is undefined. The value_type must be EmplaceConstructible into map from
   * ::forward<K>(key), ::forward<t_value>(value). This overload participates in overload resolution only if the
   * qualified-id Compare::is_transparent is valid and denotes a type. It allows calling this function without
   * constructing an instance of Key.
   *
   * @tparam t_value
   * @param hint_pos Iterator to the position before which the new element will be inserted.
   * @param key The key used both to look up and to insert if not found.
   * @param value The value to insert or assign.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> Iterator pointing at the element
   * that was inserted or updated.
   */
  template<class t_value>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert_or_assign(
    const_iterator hint_pos, key_type const &key, t_value &&value) {
    return m_tree.emplace_hint_unique_key_args(hint_pos.m_iter, key, key, ::portable_stl::forward<t_value>(value))
      .transform(
        [&value](::portable_stl::tuple<typename t_base_tree_type::iterator, bool> tmp_empl_result) -> iterator {
          auto iter     = ::portable_stl::get<0>(tmp_empl_result);
          bool inserted = ::portable_stl::get<1>(tmp_empl_result);

          if (!inserted) {
            ::portable_stl::get<1>(iter->get_value()) = ::portable_stl::forward<t_value>(value);
          }

          return iter;
        });
  }

  /**
   * @brief If a key equivalent to 'key' already exists in the container, assigns ::forward<t_value>(value) to the
   * mapped_type corresponding to the key 'key'. If the key does not exist, constructs an object 'u' of value_type with
   * ::forward<K>(key), ::forward<t_value>(value)), then inserts 'u' into *this. If equal_range(u.first) ==
   * equal_range(key) is false, the behavior is undefined. The value_type must be EmplaceConstructible into map from
   * ::forward<K>(key), ::forward<t_value>(value). This overload participates in overload resolution only if the
   * qualified-id Compare::is_transparent is valid and denotes a type. It allows calling this function without
   * constructing an instance of Key.
   *
   * @tparam t_value
   * @param hint_pos Iterator to the position before which the new element will be inserted.
   * @param key The key used both to look up and to insert if not found.
   * @param value The value to insert or assign.
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> Iterator pointing at the element
   * that was inserted or updated.
   */
  template<class t_value>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert_or_assign(
    const_iterator hint_pos, key_type &&key, t_value &&value) {
    return m_tree.emplace_hint_unique_key_args(hint_pos.m_iter, key, ::portable_stl::move(key), ::portable_stl::forward<t_value>(value))
      .transform(
        [&value](::portable_stl::tuple<typename t_base_tree_type::iterator, bool> tmp_empl_result) -> iterator {
          auto iter     = ::portable_stl::get<0>(tmp_empl_result);
          bool inserted = ::portable_stl::get<1>(tmp_empl_result);

          if (!inserted) {
            ::portable_stl::get<1>(iter->get_value()) = ::portable_stl::forward<t_value>(value);
          }

          return iter;
        });
  }

  /**
   * @brief Removes the element at pos from the container.
   *
   * @param pos Iterator to the element to remove.
   * @return iterator Iterator following the last removed element..
   */
  iterator erase(const_iterator pos) {
    return m_tree.erase(pos.m_iter);
  }

  /**
   * @brief Removes the element at pos from the container.
   *
   * @param pos Iterator to the element to remove.
   * @return iterator Iterator following the last removed element..
   */
  iterator erase(iterator pos) {
    return m_tree.erase(pos.m_iter);
  }

  /**
   * @brief Removes the elements in the range [first, last), which must be a valid range in *this, from the container.
   *
   * @param first Range of elements to remove.
   * @param last Range of elements to remove.
   * @return iterator Iterator following the last removed element.
   */
  iterator erase(const_iterator first, const_iterator last) {
    return m_tree.erase(first.m_iter, last.m_iter);
  }

  /**
   * @brief Removes the element (if one exists) with the key equivalent to 'key' from the container.
   *
   * @param key Key value of the elements to remove.
   * @return size_type Number of elements removed (0 or 1).
   */
  size_type erase(key_type const &key) {
    return m_tree.erase_unique(key);
  }

  /**
   * @brief Erases all elements from the container. After this call, size() returns zero.
   * Invalidates any references, pointers, and iterators referring to contained elements. Any past-the-end iterator
   * remains valid.
   */
  void clear() noexcept {
    m_tree.clear();
  }

  /**
   * @brief Unlinks the node that contains the element pointed to by position and returns a node handle that owns it.
   *
   * @param pos A valid iterator into this container.
   * @return node_type A node handle that owns the extracted element.
   */
  node_type extract(const_iterator pos) noexcept {
    return m_tree.template node_handle_extract<node_type>(pos.m_iter);
  }

  /**
   * @brief If the container has an element with key equivalent to 'key', unlinks the node that contains that element
   * from the container and returns a node handle that owns it. Otherwise, returns an empty node handle.
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
   * of *this. If there is an element in *this with key equivalent to the key of an element from source, then that
   * element is not extracted from source. No elements are copied or moved, only the internal pointers of the container
   * nodes are repointed. All pointers and references to the transferred elements remain valid, but now refer into
   * *this, not into source.
   * The behavior is undefined if get_allocator() != source.get_allocator().
   *
   * @tparam t_compare2
   * @param source Compatible container to transfer the nodes from.
   */
  template<class t_compare2> void merge(map<key_type, mapped_type, t_compare2, allocator_type> &source) {
    // _LIBCPP_ASSERT_COMPATIBLE_ALLOCATOR(source.get_allocator() == get_allocator(),
    //                                     "merging container with incompatible allocator");
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
  template<class t_compare2> void merge(map<key_type, mapped_type, t_compare2, allocator_type> &&source) {
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
  template<class t_compare2>
  void merge(::portable_stl::multimap<key_type, mapped_type, t_compare2, allocator_type> &source) {
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
  template<class t_compare2>
  void merge(::portable_stl::multimap<key_type, mapped_type, t_compare2, allocator_type> &&source) {
    m_tree.node_handle_merge_unique(source.m_tree);
  }

  /**
   * @brief Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap
   * operations on individual elements.
   * All iterators and references remain valid. The end() iterator is invalidated. The Compare objects must be
   * Swappable, and they are exchanged using unqualified call to non-member swap.
   *
   * @param other Map to exchange the contents with.
   */
  void swap(map &other) noexcept(::portable_stl::is_nothrow_swappable<t_base_tree_type>{}()) {
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
   * @return iterator An iterator to the requested element. If no such element is found, past-the-end (see end())
   * iterator is returned.
   */
  const_iterator find(key_type const &key) const {
    return m_tree.find(key);
  }

  /**
   * @brief Finds an element with key that compares equivalent to the value 'value'. This overload participates in
   * overload resolution only if the qualified-id Compare::is_transparent is valid and denotes a type. It allows calling
   * this function without constructing an instance of Key.
   *
   * @tparam t_val_type
   * @param value A value of any type that can be transparently compared with a key.
   * @return iterator An iterator to the requested element. If no such element is found, past-the-end (see end())
   * iterator is returned.
   */
  template<typename t_val_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_val_type>, void *>
           = nullptr>
  iterator find(t_val_type const &value) {
    return m_tree.find(value);
  }

  /**
   * @brief Finds an element with key that compares equivalent to the value 'value'. This overload participates in
   * overload resolution only if the qualified-id Compare::is_transparent is valid and denotes a type. It allows calling
   * this function without constructing an instance of Key.
   *
   * @tparam t_val_type
   * @param value A value of any type that can be transparently compared with a key.
   * @return iterator An iterator to the requested element. If no such element is found, past-the-end (see end())
   * iterator is returned.
   */
  template<typename t_val_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_val_type>, void *>
           = nullptr>
  const_iterator find(t_val_type const &value) const {
    return m_tree.find(value);
  }

  /**
   * @brief Returns the number of elements with key 'key'. This is either 1 or 0 since this container does not allow
   * duplicates.
   *
   * @param key Key value of the elements to count.
   * @return size_type Number of elements with key that compares equivalent to 'key', which is either 1 or 0.
   */
  size_type count(key_type const &key) const {
    return m_tree.count_unique(key);
  }

  /**
   * @brief Returns the number of elements with key that compares equivalent to the value 'value'. This overload
   * participates in overload resolution only if the qualified-id Compare::is_transparent is valid and denotes a type.
   * It allows calling this function without constructing an instance of Key.
   *
   * @tparam t_val_type
   * @param value Alternative value to compare to the keys.
   * @return size_type size_type Number of elements with key that compares equivalent to 'value'.
   */
  template<typename t_val_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_val_type>, void *>
           = nullptr>
  size_type count(t_val_type const &value) const {
    return m_tree.count_multi(value);
  }

  /**
   * @brief Checks if there is an element with key equivalent to 'key' in the container.
   *
   * @param key Key value of the element to search for.
   * @return true if there is such an element,
   * @return false, otherwise.
   */
  bool contains(key_type const &key) const {
    return find(key) != end();
  }

  /**
   * @brief Checks if there is an element with key that compares equivalent to the value 'value'. This overload
   * participates in overload resolution only if the qualified-id Compare::is_transparent is valid and denotes a type.
   * It allows calling this function without constructing an instance of Key.
   *
   * @tparam t_val_type
   * @param value A value of any type that can be transparently compared with a key.
   * @return true if there is such an element,
   * @return false, otherwise.
   */
  template<typename t_val_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_val_type>, void *>
           = nullptr>
  bool contains(t_val_type const &value) const {
    return find(value) != end();
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
   * value 'value'. This overload participates in overload resolution only if the qualified-id Compare::is_transparent
   * is valid and denotes a type. It allows calling this function without constructing an instance of Key.
   *
   * @tparam t_val_type
   * @param value Alternative value that can be compared to Key.
   * @return iterator Iterator pointing to the first element that is not less than key. If no such element is found, a
   * past-the-end iterator (see end()) is returned.
   */
  template<typename t_val_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_val_type>, void *>
           = nullptr>
  iterator lower_bound(t_val_type const &value) {
    return m_tree.lower_bound(value);
  }

  /**
   * @brief Returns a constant iterator pointing to the first element that compares not less (i.e. greater or equal) to
   * the value 'value'. This overload participates in overload resolution only if the qualified-id
   * Compare::is_transparent is valid and denotes a type. It allows calling this function without constructing an
   * instance of Key.
   *
   * @tparam t_val_type
   * @param value Alternative value that can be compared to Key.
   * @return const_iterator Iterator pointing to the first element that is not less than key. If no such element is
   * found, a past-the-end iterator (see end()) is returned.
   */
  template<typename t_val_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_val_type>, void *>
           = nullptr>
  const_iterator lower_bound(t_val_type const &value) const {
    return m_tree.lower_bound(value);
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
   * @brief Returns an iterator pointing to the first element that compares greater to the value 'value'. This overload
   * participates in overload resolution only if the qualified-id Compare::is_transparent is valid and denotes a type.
   * It allows calling this function without constructing an instance of Key.
   *
   * @tparam t_val_type
   * @param value Alternative value that can be compared to Key.
   * @return iterator Iterator pointing to the first element that is greater than key. If no such element is found,
   * past-the-end (see end()) iterator is returned.
   */
  template<typename t_val_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_val_type>, void *>
           = nullptr>
  iterator upper_bound(t_val_type const &value) {
    return m_tree.upper_bound(value);
  }

  /**
   * @brief Returns a constant iterator pointing to the first element that compares greater to the value 'value'. This
   * overload participates in overload resolution only if the qualified-id Compare::is_transparent is valid and denotes
   * a type. It allows calling this function without constructing an instance of Key.
   *
   * @tparam t_val_type
   * @param value Alternative value that can be compared to Key.
   * @return const_iterator Iterator pointing to the first element that is greater than key. If no such element is
   * found, past-the-end (see end()) iterator is returned.
   */
  template<typename t_val_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_val_type>, void *>
           = nullptr>
  const_iterator upper_bound(t_val_type const &value) const {
    return m_tree.upper_bound(value);
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
    return m_tree.equal_range_unique(key);
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
    return m_tree.equal_range_unique(key);
  }

  /**
   * @brief Returns a range containing all elements with the given key in the container. The range is defined by two
   * iterators, one pointing to the first element that is not less than key and another pointing to the first element
   * greater than key. Alternatively, the first iterator may be obtained with lower_bound(), and the second with
   * upper_bound().
   * Compares the keys to the value 'value'. This overload participates in overload resolution only if the qualified-id
   * Compare::is_transparent is valid and denotes a type. It allows calling this function without constructing an
   * instance of Key.
   *
   * @tparam t_val_type
   * @param value Alternative value that can be compared to Key.
   * @return ::portable_stl::tuple<iterator, iterator> ::tuple<> containing a pair of iterators defining the wanted
   * range: the first pointing to the first element that is not less than 'key' and the second pointing to the first
   * element greater than 'key'. If there are no elements not less than 'key', past-the-end (see end()) iterator is
   * returned as the first element. Similarly if there are no elements greater than 'key', past-the-end iterator is
   * returned as the second element.
   */
  template<typename t_val_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_val_type>, void *>
           = nullptr>
  ::portable_stl::tuple<iterator, iterator> equal_range(t_val_type const &value) {
    return m_tree.equal_range_multi(value);
  }

  /**
   * @brief Returns a constant range containing all elements with the given key in the container. The range is defined
   * by two iterators, one pointing to the first element that is not less than key and another pointing to the first
   * element greater than key. Alternatively, the first iterator may be obtained with lower_bound(), and the second with
   * upper_bound().
   * Compares the keys to the value 'value'. This overload participates in overload resolution only if the qualified-id
   * Compare::is_transparent is valid and denotes a type. It allows calling this function without constructing an
   * instance of Key.
   *
   * @tparam t_val_type
   * @param value Alternative value that can be compared to Key.
   * @return ::portable_stl::tuple<iterator, iterator> ::tuple<> containing a pair of constant iterators defining the
   * wanted range: the first pointing to the first element that is not less than 'key' and the second pointing to the
   * first element greater than 'key'. If there are no elements not less than 'key', past-the-end (see end()) iterator
   * is returned as the first element. Similarly if there are no elements greater than 'key', past-the-end iterator is
   * returned as the second element.
   */
  template<typename t_val_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_transparent<t_compare, t_val_type>, void *>
           = nullptr>
  ::portable_stl::tuple<const_iterator, const_iterator> equal_range(t_val_type const &value) const {
    return m_tree.equal_range_multi(value);
  }

private:
  /**
   * @brief
   */
  using t_node              = typename t_base_tree_type::t_node_type;
  /**
   * @brief
   */
  using t_node_allocator    = typename t_base_tree_type::t_node_allocator;
  /**
   * @brief
   */
  using t_node_pointer      = typename t_base_tree_type::t_node_pointer;
  /**
   * @brief
   */
  using t_node_base_pointer = typename t_base_tree_type::t_node_base_pointer;
  /**
   * @brief
   */
  using t_parent_pointer    = typename t_base_tree_type::t_parent_pointer;

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
map<t_key, t_type, t_compare, t_allocator>::map(map &&other, allocator_type const &alloc)
    : m_tree(::portable_stl::move(other.m_tree), typename t_base_tree_type::allocator_type(alloc)) {
  if (alloc != other.get_allocator()) {
    const_iterator c_end = cend();
    while (!other.empty()) {
      auto result = m_tree.insert_unique(c_end.m_iter, other.m_tree.remove(other.begin().m_iter)->m_value.make_move());
      ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!result);
    }
  }
}

/**
 * @brief Returns a reference to the value that is mapped to a key equivalent to key or x respectively, performing an
 * insertion if such key does not already exist.
 *
 * @tparam t_key Keys type.
 * @tparam t_type Mapped type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param key The key of the element to find.
 * @return t_type& A reference to the mapped value of the new element if no element with key key existed.
 * Otherwise, a reference to the mapped value of the existing element whose key is equivalent to key.
 */
template<class t_key, class t_type, class t_compare, class t_allocator>
t_type &map<t_key, t_type, t_compare, t_allocator>::operator[](key_type const &key) {
  return ::portable_stl::get<1>(
    ::portable_stl::get<0>(::portable_stl::move(m_tree.emplace_unique_key_args(key,
                                                                               ::portable_stl::piecewise_construct_t{},
                                                                               ::portable_stl::forward_as_tuple(key),
                                                                               ::portable_stl::forward_as_tuple()))
                             .value())
      ->get_value());
}

/**
 * @brief Returns a reference to the value that is mapped to a key equivalent to key or x respectively, performing an
 * insertion if such key does not already exist.
 *
 * @tparam t_key Keys type.
 * @tparam t_type Mapped type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param key The key of the element to find.
 * @return t_type& A reference to the mapped value of the new element if no element with key key existed.
 * Otherwise, a reference to the mapped value of the existing element whose key is equivalent to key.
 */
template<class t_key, class t_type, class t_compare, class t_allocator>
t_type &map<t_key, t_type, t_compare, t_allocator>::operator[](key_type &&key) {
  // TODO investigate this clang-tidy warning.
  // NOLINTBEGIN(bugprone-use-after-move)
  return ::portable_stl::get<1>(
    ::portable_stl::get<0>(
      ::portable_stl::move(m_tree.emplace_unique_key_args(key,
                                                          ::portable_stl::piecewise_construct_t{},
                                                          ::portable_stl::forward_as_tuple(::portable_stl::move(key)),
                                                          ::portable_stl::forward_as_tuple()))
        .value())
      ->get_value());
  // NOLINTEND(bugprone-use-after-move)
}

/**
 * @brief Returns a reference to the mapped value of the element with specified key. If no such element exists, an
 * exception of type ::out_of_range is thrown.
 *
 * @tparam t_key Keys type.
 * @tparam t_type Mapped type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param key The key of the element to find.
 * @return t_type& A reference to the mapped value of the requested element.
 */
template<class t_key, class t_type, class t_compare, class t_allocator>
t_type &map<t_key, t_type, t_compare, t_allocator>::at(key_type const &key) {
  t_parent_pointer     parent;
  t_node_base_pointer &child = m_tree.find_equal(parent, key);
  ::portable_stl::throw_on_true<::portable_stl::out_of_range<>>(nullptr == child); // "map::at:  key not found"
  return ::portable_stl::get<1>(static_cast<t_node_pointer>(child)->m_value.get_value());
}

/**
 * @brief Returns a reference to the mapped value of the element with specified key. If no such element exists, an
 * exception of type ::out_of_range is thrown.
 *
 * @tparam t_key Keys type.
 * @tparam t_type Mapped type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param key The key of the element to find.
 * @return t_type const& A reference to the mapped value of the requested element.
 */
template<class t_key, class t_type, class t_compare, class t_allocator>
t_type const &map<t_key, t_type, t_compare, t_allocator>::at(key_type const &key) const {
  t_parent_pointer    parent;
  t_node_base_pointer child = m_tree.find_equal(parent, key);
  ::portable_stl::throw_on_true<::portable_stl::out_of_range<>>(nullptr == child); // "map::at:  key not found"
  return ::portable_stl::get<1>(static_cast<t_node_pointer>(child)->m_value.get_value());
}

/**
 * @brief Compares the contents of two maps.
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
inline bool operator==(map<t_key, t_type, t_compare, t_allocator> const &lhv,
                       map<t_key, t_type, t_compare, t_allocator> const &rhv) {
  return lhv.size() == rhv.size() && ::portable_stl::equal(lhv.begin(), lhv.end(), rhv.begin());
}

/**
 * @brief Compares the contents of two maps.
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
inline bool operator!=(map<t_key, t_type, t_compare, t_allocator> const &lhv,
                       map<t_key, t_type, t_compare, t_allocator> const &rhv) {
  return !(lhv == rhv);
}

/**
 * @brief Compares the contents of two maps.
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
inline bool operator<(map<t_key, t_type, t_compare, t_allocator> const &lhv,
                      map<t_key, t_type, t_compare, t_allocator> const &rhv) {
  return ::portable_stl::lexicographical_compare(lhv.begin(), lhv.end(), rhv.begin(), rhv.end());
}

/**
 * @brief Compares the contents of two maps.
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
inline bool operator<=(map<t_key, t_type, t_compare, t_allocator> const &lhv,
                       map<t_key, t_type, t_compare, t_allocator> const &rhv) {
  return !(rhv < lhv);
}

/**
 * @brief Compares the contents of two maps.
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
inline bool operator>(map<t_key, t_type, t_compare, t_allocator> const &lhv,
                      map<t_key, t_type, t_compare, t_allocator> const &rhv) {
  return rhv < lhv;
}

/**
 * @brief Compares the contents of two maps.
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
inline bool operator>=(map<t_key, t_type, t_compare, t_allocator> const &lhv,
                       map<t_key, t_type, t_compare, t_allocator> const &rhv) {
  return !(lhv < rhv);
}

/**
 * @brief Specializes the ::swap algorithm for ::map. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
 *
 * @tparam t_key Keys type.
 * @tparam t_type Mapped type.
 * @tparam t_compare Key compare type.
 * @tparam t_allocator Allocator type.
 * @param lhv Map to swap.
 * @param rhv Map to swap.
 */
template<class t_key, class t_type, class t_compare, class t_allocator>
inline void swap(map<t_key, t_type, t_compare, t_allocator> &lhv,
                 map<t_key, t_type, t_compare, t_allocator> &rhv) noexcept(noexcept(lhv.swap(rhv))) {
  lhv.swap(rhv);
}

} // namespace portable_stl

#endif // PSTL_MAP_H
