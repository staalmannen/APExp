// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tree.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TREE_H
#define PSTL_TREE_H

#include "../algorithm/min.h"
#include "../common/numeric_limits.h"
#include "../error/portable_stl_error.h"
#include "../memory/addressof.h"
#include "../memory/allocate_noexcept.h"
#include "../memory/allocator_traits.h"
#include "../memory/compressed_pair.h"
#include "../memory/pointer_traits.h"
#include "../memory/rebind_alloc.h"
#include "../memory/rebind_pointer.h"
#include "../memory/swap_allocator.h"
#include "../memory/unique_ptr.h"
#include "../metaprogramming/cv_modifications/is_same_uncvref.h"
#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/conditional_bool_constant.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/remove_cref.h"
#include "../metaprogramming/primary_type/is_pointer.h"
#include "../metaprogramming/type_properties/is_const.h"
#include "../metaprogramming/type_properties/is_nothrow_copy_constructible.h"
#include "../metaprogramming/type_properties/is_nothrow_default_constructible.h"
#include "../metaprogramming/type_properties/is_nothrow_move_assignable.h"
#include "../metaprogramming/type_properties/is_nothrow_move_constructible.h"
#include "../metaprogramming/type_properties/is_nothrow_swappable.h"
#include "../metaprogramming/type_relations/is_same.h"
#include "../metaprogramming/type_traits/can_extract_map_key.h"
#include "../metaprogramming/type_traits/has_forward_iterator_category.h"
#include "../utility/expected/expected.h"
#include "../utility/expected/unexpected.h"
#include "../utility/general/forward.h"
#include "../utility/general/move.h"
#include "../utility/general/swap.h"
#include "../utility/tuple/tuple.h"
#include "node_handle.h"
#include "tree_algo.h"
#include "tree_const_iterator.h"
#include "tree_helpers.h"
#include "tree_iterator.h"
#include "tree_node.h"
#include "tree_node_destructor.h"

namespace portable_stl {

// used in node_handle
template<class t_node_type, class t_allocator> struct generic_container_node_destructor;

template<class t_type, class t_void_ptr, class t_allocator>
struct generic_container_node_destructor<::portable_stl::tree_node<t_type, t_void_ptr>, t_allocator>
    : ::portable_stl::tree_node_destructor<t_allocator> {
  using ::portable_stl::tree_node_destructor<t_allocator>::tree_node_destructor;
};

/**
 * @brief RB tree.
 *
 * @tparam t_type Type of the value stored in tree's nodes.
 * @tparam t_compare Compare type for tree's nodes.
 * @tparam t_allocator Allocator type.
 */
template<class t_type, class t_compare, class t_allocator> class tree {
public:
  /**
   * @brief Value type.
   *
   */
  using value_type     = t_type;
  /**
   * @brief Value compare type.
   *
   */
  using value_compare  = t_compare;
  /**
   * @brief Allocator type.
   *
   */
  using allocator_type = t_allocator;

private:
  /**
   * @brief Allocator traits type.
   *
   */
  using t_alloc_traits = ::portable_stl::allocator_traits<allocator_type>;
  
  /**
   * @brief Node traits type.
   *
   */
  using t_node_types =
    typename ::portable_stl::tree_helper::make_tree_node_types<value_type, typename t_alloc_traits::void_pointer>::type;

  /**
   * @brief Key type.
   *
   */
  using key_type = typename t_node_types::key_type;

public:
  /**
   * @brief
   *
   */
  using t_node_value_type      = typename t_node_types::t_node_value_type;
  /**
   * @brief
   *
   */
  using t_container_value_type = typename t_node_types::t_container_value_type;

  /**
   * @brief
   *
   */
  using pointer         = typename t_alloc_traits::pointer;
  /**
   * @brief
   *
   */
  using const_pointer   = typename t_alloc_traits::const_pointer;
  /**
   * @brief
   *
   */
  using size_type       = typename t_alloc_traits::size_type;
  /**
   * @brief
   *
   */
  using difference_type = typename t_alloc_traits::difference_type;

  /**
   * @brief
   *
   */
  using t_void_pointer = typename t_node_types::t_void_pointer;

  /**
   * @brief
   *
   */
  using t_node_type    = typename t_node_types::t_node_type;
  /**
   * @brief
   *
   */
  using t_node_pointer = typename t_node_types::t_node_pointer;

  /**
   * @brief
   *
   */
  using t_node_base_type    = typename t_node_types::t_node_base_type;
  /**
   * @brief
   *
   */
  using t_node_base_pointer = typename t_node_types::t_node_base_pointer;

  /**
   * @brief
   *
   */
  using t_end_node     = typename t_node_types::t_end_node_type;
  /**
   * @brief
   *
   */
  using t_end_node_ptr = typename t_node_types::t_end_node_pointer;

  /**
   * @brief
   *
   */
  using t_parent_pointer = typename t_node_types::t_parent_pointer;
  /**
   * @brief
   *
   */
  using t_iter_pointer   = typename t_node_types::t_iter_pointer;

  /**
   * @brief
   *
   */
  using t_node_allocator = ::portable_stl::rebind_alloc<t_alloc_traits, t_node_type>;
  /**
   * @brief
   *
   */
  using t_node_traits    = allocator_traits<t_node_allocator>;

private:
  // check for sane allocator pointer rebinding semantics. Rebinding the
  // allocator for a new pointer type should be exactly the same as rebinding
  // the pointer using '::portable_stl::pointer_traits'.
  static_assert(::portable_stl::is_same<t_node_pointer, typename t_node_traits::pointer>{}(),
                "Allocator does not rebind pointers in a sane manner.");

  /**
   * @brief
   *
   */
  using t_node_base_allocator = ::portable_stl::rebind_alloc<t_node_traits, t_node_base_type>;
  /**
   * @brief
   *
   */
  using t_node_base_traits    = allocator_traits<t_node_base_allocator>;
  static_assert(::portable_stl::is_same<t_node_base_pointer, typename t_node_base_traits::pointer>{}(),
                "Allocator does not rebind pointers in a sane manner.");

private:
  /**
   * @brief Pointer to begin node.
   *
   */
  t_iter_pointer m_begin_node;

  /**
   * @brief Pair to store end node and allocator object.
   *
   */
  ::portable_stl::compressed_pair<t_end_node, t_node_allocator> m_pair1
    = ::portable_stl::compressed_pair<t_end_node, t_node_allocator>(t_end_node(), t_node_allocator());

  /**
   * @brief Pair to store size node and compare object.
   *
   */
  ::portable_stl::compressed_pair<size_type, value_compare> m_pair3
    = ::portable_stl::compressed_pair<size_type, value_compare>(0, value_compare());

public:
  /**
   * @brief Access to end node.
   *
   * @return t_iter_pointer
   */
  t_iter_pointer get_end_node() noexcept {
    return static_cast<t_iter_pointer>(::portable_stl::pointer_traits<t_end_node_ptr>::pointer_to(m_pair1.get_first()));
  }

  /**
   * @brief Access to end node.
   *
   * @return t_iter_pointer
   */
  t_iter_pointer get_end_node() const noexcept {
    return static_cast<t_iter_pointer>(
      ::portable_stl::pointer_traits<t_end_node_ptr>::pointer_to(const_cast<t_end_node &>(m_pair1.get_first())));
  }

  /**
   * @brief Access to node allocator.
   *
   * @return t_node_allocator&
   */
  t_node_allocator &get_node_allocator() noexcept {
    return m_pair1.get_second();
  }

private:
  /**
   * @brief Access to node allocator.
   *
   * @return t_node_allocator const&
   */
  t_node_allocator const &get_node_allocator() const noexcept {
    return m_pair1.get_second();
  }

  /**
   * @brief Access to begin node.
   *
   * @return t_iter_pointer&
   */
  t_iter_pointer &get_begin_node() noexcept {
    return m_begin_node;
  }

  /**
   * @brief Access to begin node.
   *
   * @return t_iter_pointer const&
   */
  t_iter_pointer const &get_begin_node() const noexcept {
    return m_begin_node;
  }

public:
  /**
   * @brief Casts node allocator to tree allocator type.
   *
   * @return allocator_type
   */
  allocator_type get_alloc() const noexcept {
    return allocator_type(get_node_allocator());
  }

private:
  /**
   * @brief Access to size of the tree.
   *
   * @return size_type&
   */
  size_type &size() noexcept {
    return m_pair3.get_first();
  }

public:
  /**
   * @brief Returns size of the tree.
   *
   * @return size_type const&
   */
  size_type const &size() const noexcept {
    return m_pair3.get_first();
  }

  /**
   * @brief Access to value compare object.
   *
   * @return value_compare&
   */
  value_compare &value_comp() noexcept {
    return m_pair3.get_second();
  }

  /**
   * @brief Access to value compare object.
   *
   * @return value_compare const&
   */
  value_compare const &value_comp() const noexcept {
    return m_pair3.get_second();
  }

  /**
   * @brief Returns root node pointer.
   *
   * @return t_node_pointer
   */
  t_node_pointer get_root() const noexcept {
    return static_cast<t_node_pointer>(get_end_node()->m_left);
  }

  /**
   * @brief Returns root node base pointer.
   *
   * @return t_node_base_pointer*
   */
  t_node_base_pointer *get_root_ptr() const noexcept {
    return ::portable_stl::addressof(get_end_node()->m_left);
  }

  /**
   * @brief Tree iterator type.
   *
   */
  using iterator = ::portable_stl::tree_iterator<value_type, t_node_pointer, difference_type>;

  /**
   * @brief Tree constant iterator type.
   *
   */
  using const_iterator = ::portable_stl::tree_const_iterator<value_type, t_node_pointer, difference_type>;

  /**
   * @brief Constructs empty tree.
   *
   * @param comp Given value compare.
   *
   */
  explicit tree(value_compare const &comp) noexcept(
    ::portable_stl::is_nothrow_default_constructible<t_node_allocator>{}()
    && ::portable_stl::is_nothrow_copy_constructible<value_compare>{}());

  /**
   * @brief Constructs empty tree.
   *
   * @param alloc Given allocator.
   */
  explicit tree(allocator_type const &alloc);

  /**
   * @brief Constructs empty tree.
   *
   * @param comp Given value compare.
   * @param alloc Given allocator.
   */
  tree(value_compare const &comp, allocator_type const &alloc);

  /**
   * @brief Copy constructor from other tree.
   *
   * @param other Another tree.
   */
  tree(tree const &other);

  /**
   * @brief Move constructor from other tree.
   *
   * @param other Another tree.
   */
  tree(tree &&other) noexcept(::portable_stl::is_nothrow_move_constructible<t_node_allocator>{}()
                              && ::portable_stl::is_nothrow_move_constructible<value_compare>{}());

  /**
   * @brief Move constructor from other tree.
   *
   * @param other Another tree.
   * @param alloc Given allocator.
   */
  tree(tree &&other, allocator_type const &alloc);

  /**
   * @brief Copy assignment operator.
   *
   * @param other Another tree.
   * @return tree& *this.
   */
  tree &operator=(tree const &other);

  /**
   * @brief Move assignment operator.
   *
   * @param other Another tree.
   * @return tree& *this.
   */
  tree &operator=(tree &&other) noexcept(typename t_node_traits::propagate_on_container_move_assignment{}()
                                         && ::portable_stl::is_nothrow_move_assignable<value_compare>{}()
                                         && ::portable_stl::is_nothrow_move_assignable<t_node_allocator>{}());

  /**
   * @brief Assing reange of unique values.
   *
   * @tparam t_forward_iterator
   * @param first
   * @param last
   */
  template<class t_forward_iterator> void assign_unique(t_forward_iterator first, t_forward_iterator last);

  /**
   * @brief Assing reange of non-unique values.
   *
   * @tparam t_input_iterator
   * @param first
   * @param last
   */
  template<class t_input_iterator> void assign_multi(t_input_iterator first, t_input_iterator last);

  /**
   * @brief Destructor.
   *
   */
  ~tree();

  /**
   * @brief Returns an iterator to the first element of the tree.
   *
   * @return iterator Iterator to the first element.
   */
  iterator begin() noexcept {
    return iterator(get_begin_node());
  }

  /**
   * @brief Returns an constant iterator to the first element of the tree.
   *
   * @return const_iterator Constant iterator to the first element.
   */
  const_iterator begin() const noexcept {
    return const_iterator(get_begin_node());
  }

  /**
   * @brief Returns an iterator to the element following the last element of the tree.
   *
   * @return iterator Iterator to the element following the last element.
   */
  iterator end() noexcept {
    return iterator(get_end_node());
  }

  /**
   * @brief Returns a constant iterator to the element following the last element of the tree.
   *
   * @return const_iterator Constant iterator to the element following the last element.
   */
  const_iterator end() const noexcept {
    return const_iterator(get_end_node());
  }

  /**
   * @brief Returns the maximum number of elements the tree is able to hold.
   *
   * @return size_type Maximum number of elements.
   */
  size_type max_size() const noexcept {
    return ::portable_stl::min<size_type>(t_node_traits::max_size(get_node_allocator()),
                                          ::portable_stl::numeric_limits<difference_type>::max());
  }

  /**
   * @brief Erases all elements from the tree.
   *
   */
  void clear() noexcept;

  /**
   * @brief Exchanges the contents of the tree with those of other.
   *
   * @param other tree to exchange the contents with.
   */
  void swap(tree &other) noexcept(::portable_stl::is_nothrow_swappable<value_compare>{}());

  /**
   * @brief Try to inserts a new unique element into the tree with key key_value and value constructed with args.
   *
   * @tparam t_key_type
   * @tparam t_args
   * @param key_value
   * @param args
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
   */
  template<class t_key_type, class... t_args>
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
    emplace_unique_key_args(t_key_type const &key_value, t_args &&...args);

  /**
   * @brief Try to inserts a new unique element into the tree with key key_value and value constructed with args.
   *
   * @tparam t_key_type
   * @tparam t_args
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
   */
  template<class t_key_type, class... t_args>
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
    emplace_hint_unique_key_args(const_iterator, t_key_type const &, t_args &&...);

  /**
   * @brief Try to inserts a new unique element constructed with args into the tree.
   *
   * @tparam t_args
   * @param args
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
   */
  template<class... t_args>
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
    emplace_unique_impl(t_args &&...args);

  /**
   * @brief Try to inserts a new unique element constructed with args into the tree.
   *
   * @tparam t_args
   * @param hint_pos
   * @param args
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  template<class... t_args>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> emplace_hint_unique_impl(
    const_iterator hint_pos, t_args &&...args);

  /**
   * @brief Try to inserts a new non unique element constructed with args into the tree.
   *
   * @tparam t_args
   * @param args
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  template<class... t_args>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> emplace_multi(t_args &&...args);

  /**
   * @brief Try to inserts a new non unique element constructed with args into the tree.
   *
   * @tparam t_args
   * @param hint_pos
   * @param args
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  template<class... t_args>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> emplace_hint_multi(const_iterator hint_pos,
                                                                                            t_args &&...args);

  /**
   * @brief Try to inserts a new unique element constructed with value into the tree.
   *
   * @tparam t_pair_type
   * @param value
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
   */
  template<class t_pair_type>
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> emplace_unique(
    t_pair_type &&value) {
    return emplace_unique_extract_key(::portable_stl::forward<t_pair_type>(value),
                                      typename ::portable_stl::can_extract_key<t_pair_type, key_type>::type{});
  }

  /**
   * @brief Try to inserts a new unique element constructed with first and second into the tree.
   *
   * @tparam t_first_type
   * @tparam t_second_type
   * @param first
   * @param second
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
   */
  template<class t_first_type,
           class t_second_type,
           ::portable_stl::enable_if_bool_constant_t<
             typename ::portable_stl::can_extract_map_key<t_first_type, key_type, t_container_value_type>::type,
             void *>
           = nullptr>
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> emplace_unique(
    t_first_type &&first, t_second_type &&second) {
    return emplace_unique_key_args(
      first, ::portable_stl::forward<t_first_type>(first), ::portable_stl::forward<t_second_type>(second));
  }

  /**
   * @brief Try to inserts a new unique element constructed with args into the tree.
   *
   * @tparam t_args
   * @param args
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
   */
  template<class... t_args>
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> emplace_unique(
    t_args &&...args) {
    return emplace_unique_impl(::portable_stl::forward<t_args>(args)...);
  }

  /**
   * @brief Try to inserts a new unique element constructed in place into the tree.
   *
   * @tparam t_pair_type
   * @param value
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
   */
  template<class t_pair_type>
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
    emplace_unique_extract_key(t_pair_type &&value, ::portable_stl::extract_key_fail_tag) {
    return emplace_unique_impl(::portable_stl::forward<t_pair_type>(value));
  }

  /**
   * @brief Try to inserts a new unique element constructed in place into the tree.
   *
   * @tparam t_pair_type
   * @param value
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
   */
  template<class t_pair_type>
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
    emplace_unique_extract_key(t_pair_type &&value, ::portable_stl::extract_key_self_tag) {
    return emplace_unique_key_args(value, ::portable_stl::forward<t_pair_type>(value));
  }

  /**
   * @brief Try to inserts a new unique element constructed in place into the tree.
   *
   * @tparam t_pair_type
   * @param value
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
   */
  template<class t_pair_type>
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
    emplace_unique_extract_key(t_pair_type &&value, ::portable_stl::extract_key_first_tag) {
    return emplace_unique_key_args(::portable_stl::get<0>(value), ::portable_stl::forward<t_pair_type>(value));
  }

  /**
   * @brief Try to inserts a new unique element constructed with value into the tree.
   *
   * @tparam t_pair_type
   * @param hint_pos
   * @param value
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  template<class t_pair_type>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> emplace_hint_unique(const_iterator hint_pos,
                                                                                             t_pair_type  &&value) {
    return emplace_hint_unique_extract_key(hint_pos,
                                           ::portable_stl::forward<t_pair_type>(value),
                                           typename ::portable_stl::can_extract_key<t_pair_type, key_type>::type());
  }

  /**
   * @brief Try to inserts a new unique element constructed with first and second into the tree.
   *
   * @tparam t_first_type
   * @tparam t_second_type
   * @param hint_pos
   * @param first
   * @param second
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  template<class t_first_type,
           class t_second_type,
           ::portable_stl::enable_if_bool_constant_t<
             typename ::portable_stl::can_extract_map_key<t_first_type, key_type, t_container_value_type>::type,
             void *>
           = nullptr>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> emplace_hint_unique(
    const_iterator hint_pos, t_first_type &&first, t_second_type &&second) {
    return emplace_hint_unique_key_args(hint_pos,
                                        first,
                                        ::portable_stl::forward<t_first_type>(first),
                                        ::portable_stl::forward<t_second_type>(second))
      .transform([](::portable_stl::tuple<iterator, bool> &&tmp) -> iterator {
        return ::portable_stl::get<0>(::portable_stl::move(tmp));
      });
  }

  /**
   * @brief Try to inserts a new unique element constructed with args into the tree.
   *
   * @tparam t_args
   * @param hint_pos
   * @param args
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  template<class... t_args>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> emplace_hint_unique(const_iterator hint_pos,
                                                                                             t_args &&...args) {
    return emplace_hint_unique_impl(hint_pos, ::portable_stl::forward<t_args>(args)...);
  }

  /**
   * @brief Try to inserts a new unique element constructed with value into the tree.
   *
   * @tparam t_pair_type
   * @param hint_pos
   * @param value
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  template<class t_pair_type>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> emplace_hint_unique_extract_key(
    const_iterator hint_pos, t_pair_type &&value, ::portable_stl::extract_key_fail_tag) {
    return emplace_hint_unique_impl(hint_pos, ::portable_stl::forward<t_pair_type>(value));
  }

  /**
   * @brief Try to inserts a new unique element constructed with value into the tree.
   *
   * @tparam t_pair_type
   * @param hint_pos
   * @param value
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  template<class t_pair_type>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> emplace_hint_unique_extract_key(
    const_iterator hint_pos, t_pair_type &&value, ::portable_stl::extract_key_self_tag) {
    return ::portable_stl::get<0>(
      emplace_hint_unique_key_args(hint_pos, value, ::portable_stl::forward<t_pair_type>(value)));
  }

  /**
   * @brief Try to inserts a new unique element constructed with value into the tree.
   *
   * @tparam t_pair_type
   * @param hint_pos
   * @param value
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  template<class t_pair_type>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> emplace_hint_unique_extract_key(
    const_iterator hint_pos, t_pair_type &&value, ::portable_stl::extract_key_first_tag) {
    return emplace_hint_unique_key_args(
             hint_pos, ::portable_stl::get<0>(value), ::portable_stl::forward<t_pair_type>(value))
      .transform([](::portable_stl::tuple<iterator, bool> &&tmp) -> iterator {
        return ::portable_stl::get<0>(::portable_stl::move(tmp));
      });
  }

  /**
   * @brief Try to inserts a new unique element into the tree.
   *
   * @param value_pair
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
   */
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> insert_unique(
    t_container_value_type const &value_pair) {
    return emplace_unique_key_args(t_node_types::get_key(value_pair), value_pair);
  }

  /**
   * @brief Try to inserts a new unique element into the tree.
   *
   * @param pos
   * @param value_pair
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert_unique(
    const_iterator pos, t_container_value_type const &value_pair) {
    return emplace_hint_unique_key_args(pos, t_node_types::get_key(value_pair), value_pair)
      .transform([](::portable_stl::tuple<iterator, bool> &&tmp) -> iterator {
        return ::portable_stl::get<0>(::portable_stl::move(tmp));
      });
  }

  /**
   * @brief Try to inserts a new unique element into the tree.
   *
   * @param value_pair
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
   */
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> insert_unique(
    t_container_value_type &&value_pair) {
    return emplace_unique_key_args(t_node_types::get_key(value_pair), ::portable_stl::move(value_pair));
  }

  /**
   * @brief Try to inserts a new unique element into the tree.
   *
   * @param pos
   * @param value_pair
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert_unique(
    const_iterator pos, t_container_value_type &&value_pair) {
    return emplace_hint_unique_key_args(pos, t_node_types::get_key(value_pair), ::portable_stl::move(value_pair))
      .transform([](::portable_stl::tuple<iterator, bool> &&tmp) -> iterator {
        return ::portable_stl::get<0>(::portable_stl::move(tmp));
      });
  }

  /**
   * @brief Try to inserts a new unique element into the tree.
   *
   * @tparam t_val_type
   * @param value
   * @return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>
   */
  template<class t_val_type,
           class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::negation<
             ::portable_stl::is_same<::portable_stl::remove_cref_t<t_val_type>, t_container_value_type>>>>
  ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error> insert_unique(
    t_val_type &&value) {
    return emplace_unique(::portable_stl::forward<t_val_type>(value));
  }

  /**
   * @brief Try to inserts a new unique element into the tree.
   *
   * @tparam t_val_type
   * @param pos
   * @param value
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  template<class t_val_type,
           class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::negation<
             ::portable_stl::is_same<::portable_stl::remove_cref_t<t_val_type>, t_container_value_type>>>>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert_unique(const_iterator pos,
                                                                                       t_val_type   &&value) {
    return emplace_hint_unique(pos, ::portable_stl::forward<t_val_type>(value));
  }

  /**
   * @brief Try to inserts a new non unique element into the tree.
   *
   * @param value
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert_multi(t_container_value_type &&value) {
    return emplace_multi(::portable_stl::move(value));
  }

  /**
   * @brief Try to inserts a new non unique element into the tree.
   *
   * @param pos
   * @param value
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert_multi(const_iterator           pos,
                                                                                      t_container_value_type &&value) {
    return emplace_hint_multi(pos, ::portable_stl::move(value));
  }

  /**
   * @brief Try to inserts a new non unique element into the tree.
   *
   * @tparam t_val_type
   * @param value
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  template<class t_val_type>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert_multi(t_val_type &&value) {
    return emplace_multi(::portable_stl::forward<t_val_type>(value));
  }

  /**
   * @brief Try to inserts a new non unique element into the tree.
   *
   * @tparam t_val_type
   * @param pos
   * @param value
   * @return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>
   */
  template<class t_val_type>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert_multi(const_iterator pos,
                                                                                      t_val_type   &&value) {
    return emplace_hint_multi(pos, ::portable_stl::forward<t_val_type>(value));
  }

  /**
   * @brief
   *
   * @param value
   * @param dest_node_ptr
   * @return ::portable_stl::tuple<iterator, bool>
   */
  ::portable_stl::tuple<iterator, bool> node_assign_unique(t_container_value_type const &value,
                                                           t_node_pointer                dest_node_ptr);

  /**
   * @brief
   *
   * @param node_ptr
   * @return iterator
   */
  iterator node_insert_multi(t_node_pointer node_ptr);

  /**
   * @brief
   *
   * @param pos
   * @param node_ptr
   * @return iterator
   */
  iterator node_insert_multi(const_iterator pos, t_node_pointer node_ptr);

  /**
   * @brief
   *
   * @return iterator
   */
  iterator remove_node_pointer(t_node_pointer) noexcept;

  /**
   * @brief
   *
   * @tparam t_node_handle
   * @tparam t_insert_return_type
   * @return t_insert_return_type
   */
  template<class t_node_handle, class t_insert_return_type>

  /**
   * @brief
   *
   * @return t_insert_return_type
   */
  t_insert_return_type node_handle_insert_unique(t_node_handle &&);

  /**
   * @brief
   *
   * @tparam t_node_handle
   * @return iterator
   */
  template<class t_node_handle> iterator node_handle_insert_unique(const_iterator, t_node_handle &&);

  /**
   * @brief
   *
   * @tparam t_tree
   * @param src_tree
   */
  template<class t_tree> void node_handle_merge_unique(t_tree &src_tree);

  /**
   * @brief
   *
   * @tparam t_node_handle
   * @return iterator
   */
  template<class t_node_handle> iterator node_handle_insert_multi(t_node_handle &&);

  /**
   * @brief
   *
   * @tparam t_node_handle
   * @return iterator
   */
  template<class t_node_handle> iterator node_handle_insert_multi(const_iterator, t_node_handle &&);

  /**
   * @brief
   *
   * @tparam t_tree
   * @param src_tree
   */
  template<class t_tree> void node_handle_merge_multi(t_tree &src_tree);

  /**
   * @brief
   *
   * @tparam t_node_handle
   * @return t_node_handle
   */
  template<class t_node_handle> t_node_handle node_handle_extract(key_type const &);

  /**
   * @brief
   *
   * @tparam t_node_handle
   * @return t_node_handle
   */
  template<class t_node_handle> t_node_handle node_handle_extract(const_iterator);

  /**
   * @brief
   *
   * @param pos
   * @return iterator
   */
  iterator erase(const_iterator pos);

  /**
   * @brief
   *
   * @param first
   * @param last
   * @return iterator
   */
  iterator erase(const_iterator first, const_iterator last);

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key_value
   * @return size_type
   */
  template<class t_key_type> size_type erase_unique(t_key_type const &key_value);

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key_value
   * @return size_type
   */
  template<class t_key_type> size_type erase_multi(t_key_type const &key_value);

  /**
   * @brief
   *
   * @param parent
   * @param child
   * @param inserted_node
   */
  void insert_node_at(t_parent_pointer parent, t_node_base_pointer &child, t_node_base_pointer inserted_node) noexcept;

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key_value
   * @return iterator
   */
  template<class t_key_type> iterator find(t_key_type const &key_value);

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key_value
   * @return const_iterator
   */
  template<class t_key_type> const_iterator find(t_key_type const &key_value) const;

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key
   * @return size_type
   */
  template<class t_key_type> size_type count_unique(t_key_type const &key) const;

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key
   * @return size_type
   */
  template<class t_key_type> size_type count_multi(t_key_type const &key) const;

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key_value
   * @return iterator
   */
  template<class t_key_type> iterator lower_bound(t_key_type const &key_value) {
    return lower_bound(key_value, get_root(), get_end_node());
  }

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key_value
   * @param root
   * @param result
   * @return iterator
   */
  template<class t_key_type>
  iterator lower_bound(t_key_type const &key_value, t_node_pointer root, t_iter_pointer result);

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key_value
   * @return const_iterator
   */
  template<class t_key_type> const_iterator lower_bound(t_key_type const &key_value) const {
    return lower_bound(key_value, get_root(), get_end_node());
  }

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key_value
   * @param root
   * @param result
   * @return const_iterator
   */
  template<class t_key_type>
  const_iterator lower_bound(t_key_type const &key_value, t_node_pointer root, t_iter_pointer result) const;

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key_value
   * @return iterator
   */
  template<class t_key_type> iterator upper_bound(t_key_type const &key_value) {
    return upper_bound(key_value, get_root(), get_end_node());
  }

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key_value
   * @param root
   * @param result
   * @return iterator
   */
  template<class t_key_type>
  iterator upper_bound(t_key_type const &key_value, t_node_pointer root, t_iter_pointer result);

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key_value
   * @return const_iterator
   */
  template<class t_key_type> const_iterator upper_bound(t_key_type const &key_value) const {
    return upper_bound(key_value, get_root(), get_end_node());
  }

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key_value
   * @param root
   * @param result
   * @return const_iterator
   */
  template<class t_key_type>
  const_iterator upper_bound(t_key_type const &key_value, t_node_pointer root, t_iter_pointer result) const;

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key_value
   * @return ::portable_stl::tuple<iterator, iterator>
   */
  template<class t_key_type>::portable_stl::tuple<iterator, iterator> equal_range_unique(t_key_type const &key_value);

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key_value
   * @return ::portable_stl::tuple<const_iterator, const_iterator>
   */
  template<class t_key_type>
  ::portable_stl::tuple<const_iterator, const_iterator> equal_range_unique(t_key_type const &key_value) const;

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key_value
   * @return ::portable_stl::tuple<iterator, iterator>
   */
  template<class t_key_type>::portable_stl::tuple<iterator, iterator> equal_range_multi(t_key_type const &key_value);

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param key_value
   * @return ::portable_stl::tuple<const_iterator, const_iterator>
   */
  template<class t_key_type>
  ::portable_stl::tuple<const_iterator, const_iterator> equal_range_multi(t_key_type const &key_value) const;

  /**
   * @brief
   *
   */
  using t_tree_node_deleter = tree_node_destructor<t_node_allocator>;

  /**
   * @brief
   *
   */
  using t_node_holder = ::portable_stl::unique_ptr<t_node_type, t_tree_node_deleter>;

  /**
   * @brief
   *
   * @param pos
   * @return t_node_holder
   */
  t_node_holder remove(const_iterator pos) noexcept;

private:
  /**
   * @brief
   *
   * @param parent
   * @param key_value
   * @return t_node_base_pointer&
   */
  t_node_base_pointer &find_leaf_low(t_parent_pointer &parent, key_type const &key_value);

  /**
   * @brief
   *
   * @param parent
   * @param key_value
   * @return t_node_base_pointer&
   */
  t_node_base_pointer &find_leaf_high(t_parent_pointer &parent, key_type const &key_value);

  /**
   * @brief
   *
   * @param hint_pos
   * @param parent
   * @param key_value
   * @return t_node_base_pointer&
   */
  t_node_base_pointer &find_leaf(const_iterator hint_pos, t_parent_pointer &parent, key_type const &key_value);

  /**
   * @brief
   * FIXME: Make this function const qualified. Unfortunately doing so breaks existing code which uses non-const
   * callable comparators.
   *
   * @tparam t_key_type
   * @param parent
   * @param key_value
   * @return t_node_base_pointer&
   */
  template<class t_key_type> t_node_base_pointer &find_equal(t_parent_pointer &parent, t_key_type const &key_value);

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param parent
   * @param key_value
   * @return t_node_base_pointer&
   */
  template<class t_key_type>
  t_node_base_pointer &find_equal(t_parent_pointer &parent, t_key_type const &key_value) const {
    return const_cast<tree *>(this)->find_equal(parent, key_value);
  }

  /**
   * @brief
   *
   * @tparam t_key_type
   * @param hint_pos
   * @param parent
   * @param dummy
   * @param key_value
   * @return t_node_base_pointer&
   */
  template<class t_key_type>
  t_node_base_pointer &find_equal(
    const_iterator hint_pos, t_parent_pointer &parent, t_node_base_pointer &dummy, t_key_type const &key_value);

  /**
   * @brief
   *
   * @tparam t_args
   * @param args
   * @return ::portable_stl::expected<t_node_holder, ::portable_stl::portable_stl_error>
   */
  template<class... t_args>
  ::portable_stl::expected<t_node_holder, ::portable_stl::portable_stl_error> create_node(t_args &&...args);

  /**
   * @brief
   *
   * @param node_ptr
   */
  void destroy(t_node_pointer node_ptr) noexcept;

  /**
   * @brief
   *
   * @param other
   */
  void copy_assign_alloc(tree const &other) {
    copy_assign_alloc(other, typename t_node_traits::propagate_on_container_copy_assignment{});
  }

  /**
   * @brief
   *
   * @param other
   */
  void copy_assign_alloc(tree const &other, ::portable_stl::true_type) {
    if (get_node_allocator() != other.get_node_allocator()) {
      clear();
    }
    get_node_allocator() = other.get_node_allocator();
  }

  /**
   * @brief
   *
   */
  void copy_assign_alloc(tree const &, ::portable_stl::false_type) {
  }

  /**
   * @brief
   *
   * @param other
   */
  void move_assign(tree &other, ::portable_stl::false_type);

  /**
   * @brief
   *
   * @param other
   */
  void move_assign(tree &other, ::portable_stl::true_type) noexcept(
    ::portable_stl::is_nothrow_move_assignable<value_compare>{}()
    && ::portable_stl::is_nothrow_move_assignable<t_node_allocator>{}());

  /**
   * @brief
   *
   * @param other
   */
  void move_assign_alloc(tree &other) noexcept(!typename t_node_traits::propagate_on_container_move_assignment{}()
                                               || ::portable_stl::is_nothrow_move_assignable<t_node_allocator>{}()) {
    move_assign_alloc(other, typename t_node_traits::propagate_on_container_move_assignment{});
  }

  /**
   * @brief
   *
   * @param other
   */
  void move_assign_alloc(tree &other, ::portable_stl::true_type) noexcept(
    ::portable_stl::is_nothrow_move_assignable<t_node_allocator>{}()) {
    get_node_allocator() = ::portable_stl::move(other.get_node_allocator());
  }

  /**
   * @brief
   *
   */
  void move_assign_alloc(tree &, ::portable_stl::false_type) noexcept {
  }

  /**
   * @brief
   *
   */
  class detached_tree_cache final {
  public:
    /**
     * @brief Construct a new m detachedtreecache object
     *
     * @param other
     */
    explicit detached_tree_cache(tree *other) noexcept : m_tree(other), m_cache_root(detach_from_tree(other)) {
      M_advance();
    }

    /**
     * @brief Get the cache elem object
     *
     * @return t_node_pointer
     */
    t_node_pointer get_cache_elem() const noexcept {
      return m_cache_elem;
    }

    /**
     * @brief
     *
     */
    void M_advance() noexcept {
      m_cache_elem = m_cache_root;
      if (m_cache_root) {
        m_cache_root = M_detach_next(m_cache_root);
      }
    }

    /**
     * @brief Destructor.
     *
     */
    ~detached_tree_cache() {
      m_tree->destroy(m_cache_elem);
      if (m_cache_root) {
        while (m_cache_root->m_parent != nullptr) {
          m_cache_root = static_cast<t_node_pointer>(m_cache_root->m_parent);
        }
        m_tree->destroy(m_cache_root);
      }
    }

    /**
     * @brief Construct a new m detachedtreecache object
     *
     */
    detached_tree_cache(detached_tree_cache const &) = delete;

    /**
     * @brief
     *
     * @return detached_tree_cache&
     */
    detached_tree_cache &operator=(detached_tree_cache const &) = delete;

  private:
    /**
     * @brief
     *
     * @param tree
     * @return t_node_pointer
     */
    static t_node_pointer detach_from_tree(tree *tree) noexcept;

    /**
     * @brief
     *
     * @return t_node_pointer
     */
    static t_node_pointer M_detach_next(t_node_pointer) noexcept;

    /**
     * @brief
     *
     */
    tree *m_tree;

    /**
     * @brief
     *
     */
    t_node_pointer m_cache_root;

    /**
     * @brief
     *
     */
    t_node_pointer m_cache_elem;
  };

  template<class, class, class, class> friend class map;
  template<class, class, class, class> friend class multimap;
};

/**
 * @brief Constructs empty tree.
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param comp
 */
template<class t_type, class t_compare, class t_allocator>
tree<t_type, t_compare, t_allocator>::tree(value_compare const &comp) noexcept(
  ::portable_stl::is_nothrow_default_constructible<t_node_allocator>{}()
  && ::portable_stl::is_nothrow_copy_constructible<value_compare>{}())
    : m_pair3(0U, comp) {
  get_begin_node() = get_end_node();
}

/**
 * @brief Constructs empty tree.
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param alloc
 */
template<class t_type, class t_compare, class t_allocator>
tree<t_type, t_compare, t_allocator>::tree(allocator_type const &alloc)
    : m_begin_node(t_iter_pointer())
    , m_pair1(::portable_stl::second_tag_t{}, t_node_allocator(alloc))
    , m_pair3(0U, value_compare()) {
  get_begin_node() = get_end_node();
}

/**
 * @brief Constructs empty tree.
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param comp
 * @param alloc
 */
template<class t_type, class t_compare, class t_allocator>
tree<t_type, t_compare, t_allocator>::tree(value_compare const &comp, allocator_type const &alloc)
    : m_begin_node(t_iter_pointer())
    , m_pair1(::portable_stl::second_tag_t{}, t_node_allocator(alloc))
    , m_pair3(0U, comp) {
  get_begin_node() = get_end_node();
}

/**
 * @brief
 * Precondition: size() != 0
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param tree
 * @return tree<t_type, t_compare, t_allocator>::t_node_pointer
 */
template<class t_type, class t_compare, class t_allocator>
typename tree<t_type, t_compare, t_allocator>::t_node_pointer
  tree<t_type, t_compare, t_allocator>::detached_tree_cache::detach_from_tree(tree *tree) noexcept {
  t_node_pointer cache                   = static_cast<t_node_pointer>(tree->get_begin_node());
  tree->get_begin_node()                 = tree->get_end_node();
  tree->get_end_node()->m_left->m_parent = nullptr;
  tree->get_end_node()->m_left           = nullptr;
  tree->size()                           = 0;
  // cache->m_left == nullptr
  if (cache->m_right != nullptr) {
    cache = static_cast<t_node_pointer>(cache->m_right);
  }
  // cache->m_left == nullptr
  // cache->m_right == nullptr
  return cache;
}

/**
 * @brief
 * Precondition: cache != nullptr
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param cache
 * @return tree<t_type, t_compare, t_allocator>::t_node_pointer
 */
template<class t_type, class t_compare, class t_allocator>
typename tree<t_type, t_compare, t_allocator>::t_node_pointer
  tree<t_type, t_compare, t_allocator>::detached_tree_cache::M_detach_next(t_node_pointer cache) noexcept {
  if (nullptr == cache->m_parent) {
    return nullptr;
  }
  if (tree_ns::tree_is_left_child(static_cast<t_node_base_pointer>(cache))) {
    cache->m_parent->m_left = nullptr;
    cache                   = static_cast<t_node_pointer>(cache->m_parent);
    if (nullptr == cache->m_right) {
      return cache;
    }
    return static_cast<t_node_pointer>(tree_ns::tree_leaf(cache->m_right));
  }
  // cache is right child
  cache->parent_unsafe()->m_right = nullptr;
  cache                           = static_cast<t_node_pointer>(cache->m_parent);
  if (nullptr == cache->m_left) {
    return cache;
  }
  return static_cast<t_node_pointer>(tree_ns::tree_leaf(cache->m_left));
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param other
 * @return tree<t_type, t_compare, t_allocator>&
 */
template<class t_type, class t_compare, class t_allocator>
tree<t_type, t_compare, t_allocator> &tree<t_type, t_compare, t_allocator>::operator=(tree const &other) {
  if (this != ::portable_stl::addressof(other)) {
    value_comp() = other.value_comp();
    copy_assign_alloc(other);
    assign_multi(other.begin(), other.end());
  }
  return *this;
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_forward_iterator
 * @param first
 * @param last
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_forward_iterator>
void tree<t_type, t_compare, t_allocator>::assign_unique(t_forward_iterator first, t_forward_iterator last) {
  using _ITraits     = iterator_traits<t_forward_iterator>;
  using _ItValueType = typename _ITraits::value_type;
  static_assert(::portable_stl::is_same<_ItValueType, t_container_value_type>{}(),
                "assign_unique may only be called with the containers value type");
  static_assert(::portable_stl::has_forward_iterator_category<t_forward_iterator>{}(),
                "assign_unique requires a forward iterator");
  if (size() != 0) {
    detached_tree_cache cache(this);
    for (; cache.get_cache_elem() != nullptr && first != last; ++first) {
      if (::portable_stl::get<1>(node_assign_unique(*first, cache.get_cache_elem()))) {
        cache.M_advance();
      }
    }
  }
  for (; first != last; ++first) {
    insert_unique(*first);
  }
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_input_iterator
 * @param first
 * @param last
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_input_iterator>
void tree<t_type, t_compare, t_allocator>::assign_multi(t_input_iterator first, t_input_iterator last) {
  using _ITraits     = iterator_traits<t_input_iterator>;
  using _ItValueType = typename _ITraits::value_type;
  static_assert((::portable_stl::is_same<_ItValueType, t_container_value_type>{}()
                 || ::portable_stl::is_same<_ItValueType, t_node_value_type>{}()),
                "assign_multi may only be called with the containers value type or the nodes value type");
  if (size() != 0) {
    detached_tree_cache cache(this);
    for (; cache.get_cache_elem() && first != last; ++first) {
      cache.get_cache_elem()->m_value = *first;
      node_insert_multi(cache.get_cache_elem());
      cache.M_advance();
    }
  }
  for (; first != last; ++first) {
    insert_multi(t_node_types::get_value(*first));
  }
}

/**
 * @brief Construct a new tree<t type, t compare, t allocator>::tree object
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param other
 */
template<class t_type, class t_compare, class t_allocator>
tree<t_type, t_compare, t_allocator>::tree(tree const &other)
    : m_begin_node(t_iter_pointer())
    , m_pair1(::portable_stl::second_tag_t{},
              t_node_traits::select_on_container_copy_construction(other.get_node_allocator()))
    , m_pair3(0U, other.value_comp()) {
  get_begin_node() = get_end_node();
}

/**
 * @brief Construct a new tree<t type, t compare, t allocator>::tree object
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param other
 */
template<class t_type, class t_compare, class t_allocator>
tree<t_type, t_compare, t_allocator>::tree(tree &&other) noexcept(
  ::portable_stl::is_nothrow_move_constructible<t_node_allocator>{}()
  && ::portable_stl::is_nothrow_move_constructible<value_compare>{}())
    : m_begin_node(::portable_stl::move(other.m_begin_node))
    , m_pair1(::portable_stl::move(other.m_pair1))
    , m_pair3(::portable_stl::move(other.m_pair3)) {
  if (0 == size()) {
    get_begin_node() = get_end_node();
  } else {
    get_end_node()->m_left->m_parent = static_cast<t_parent_pointer>(get_end_node());
    other.get_begin_node()           = other.get_end_node();
    other.get_end_node()->m_left     = nullptr;
    other.size()                     = 0;
  }
}

/**
 * @brief Construct a new tree<t type, t compare, t allocator>::tree object
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param other
 * @param alloc
 */
template<class t_type, class t_compare, class t_allocator>
tree<t_type, t_compare, t_allocator>::tree(tree &&other, allocator_type const &alloc)
    : m_pair1(::portable_stl::second_tag_t{}, t_node_allocator(alloc))
    , m_pair3(0U, ::portable_stl::move(other.value_comp())) {
  if (alloc == other.get_alloc()) {
    if (0 == other.size()) {
      get_begin_node() = get_end_node();
    } else {
      get_begin_node()                 = other.get_begin_node();
      get_end_node()->m_left           = other.get_end_node()->m_left;
      get_end_node()->m_left->m_parent = static_cast<t_parent_pointer>(get_end_node());
      size()                           = other.size();
      other.get_begin_node()           = other.get_end_node();
      other.get_end_node()->m_left     = nullptr;
      other.size()                     = 0;
    }
  } else {
    get_begin_node() = get_end_node();
  }
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param other
 */
template<class t_type, class t_compare, class t_allocator>
void tree<t_type, t_compare, t_allocator>::move_assign(tree &other, true_type) noexcept(
  ::portable_stl::is_nothrow_move_assignable<value_compare>{}()
  && ::portable_stl::is_nothrow_move_assignable<t_node_allocator>{}()) {
  destroy(static_cast<t_node_pointer>(get_end_node()->m_left));
  m_begin_node        = other.m_begin_node;
  m_pair1.get_first() = other.m_pair1.get_first();
  move_assign_alloc(other);
  m_pair3 = ::portable_stl::move(other.m_pair3);
  if (0 == size()) {
    get_begin_node() = get_end_node();
  } else {
    get_end_node()->m_left->m_parent = static_cast<t_parent_pointer>(get_end_node());
    other.get_begin_node()           = other.get_end_node();
    other.get_end_node()->m_left     = nullptr;
    other.size()                     = 0;
  }
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param other
 */
template<class t_type, class t_compare, class t_allocator>
void tree<t_type, t_compare, t_allocator>::move_assign(tree &other, false_type) {
  if (get_node_allocator() == other.get_node_allocator()) {
    move_assign(other, true_type());
  } else {
    value_comp() = ::portable_stl::move(other.value_comp());
    const_iterator end_pos{end()};
    if (size() != 0) {
      detached_tree_cache cache(this);
      while (cache.get_cache_elem() != nullptr && other.size() != 0) {
        cache.get_cache_elem()->m_value = ::portable_stl::move(other.remove(other.begin())->m_value);
        node_insert_multi(cache.get_cache_elem());
        cache.M_advance();
      }
    }
    while (other.size() != 0) {
      insert_multi(end_pos, t_node_types::make_move(other.remove(other.begin())->m_value));
    }
  }
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param other
 * @return tree<t_type, t_compare, t_allocator>&
 */
template<class t_type, class t_compare, class t_allocator>
tree<t_type, t_compare, t_allocator> &tree<t_type, t_compare, t_allocator>::operator=(tree &&other) noexcept(
  typename t_node_traits::propagate_on_container_move_assignment{}()
  && ::portable_stl::is_nothrow_move_assignable<value_compare>{}()
  && ::portable_stl::is_nothrow_move_assignable<t_node_allocator>{}()) {
  move_assign(other, typename t_node_traits::propagate_on_container_move_assignment{});
  return *this;
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param node_ptr
 */
template<class t_type, class t_compare, class t_allocator>
void tree<t_type, t_compare, t_allocator>::destroy(t_node_pointer node_ptr) noexcept {
  if (node_ptr != nullptr) {
    destroy(static_cast<t_node_pointer>(node_ptr->m_left));
    destroy(static_cast<t_node_pointer>(node_ptr->m_right));
    t_node_allocator &node_alloc = get_node_allocator();
    t_node_traits::destroy(node_alloc, t_node_types::get_ptr(node_ptr->m_value));
    t_node_traits::deallocate(node_alloc, node_ptr, 1);
  }
}

/**
 * @brief Destructor.
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 */
template<class t_type, class t_compare, class t_allocator> tree<t_type, t_compare, t_allocator>::~tree() {
  static_assert(::portable_stl::is_copy_constructible<value_compare>{}(), "Comparator must be copy-constructible.");
  destroy(get_root());
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param other
 */
template<class t_type, class t_compare, class t_allocator>
void tree<t_type, t_compare, t_allocator>::swap(tree &other) noexcept(
  ::portable_stl::is_nothrow_swappable<value_compare>{}()) {
  using ::portable_stl::swap;
  swap(m_begin_node, other.m_begin_node);
  swap(m_pair1.get_first(), other.m_pair1.get_first());
  ::portable_stl::swap_allocator(get_node_allocator(), other.get_node_allocator());
  m_pair3.swap(other.m_pair3);
  if (0 == size()) {
    get_begin_node() = get_end_node();
  } else {
    get_end_node()->m_left->m_parent = static_cast<t_parent_pointer>(get_end_node());
  }
  if (0 == other.size()) {
    other.get_begin_node() = other.get_end_node();
  } else {
    other.get_end_node()->m_left->m_parent = static_cast<t_parent_pointer>(other.get_end_node());
  }
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 */
template<class t_type, class t_compare, class t_allocator> void tree<t_type, t_compare, t_allocator>::clear() noexcept {
  destroy(get_root());
  size()                 = 0;
  get_begin_node()       = get_end_node();
  get_end_node()->m_left = nullptr;
}

/**
 * @brief Find lower_bound place to insert.
 * Set parent to parent of null leaf.
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param parent
 * @param key_value
 * @return tree<t_type, t_compare, t_allocator>::t_node_base_pointer& Reference to null leaf.
 */
template<class t_type, class t_compare, class t_allocator>
typename tree<t_type, t_compare, t_allocator>::t_node_base_pointer &tree<t_type, t_compare, t_allocator>::find_leaf_low(
  t_parent_pointer &parent, key_type const &key_value) {
  t_node_pointer node_ptr{get_root()};
  if (node_ptr != nullptr) {
    while (true) {
      if (value_comp()(node_ptr->m_value, key_value)) {
        if (node_ptr->m_right != nullptr) {
          node_ptr = static_cast<t_node_pointer>(node_ptr->m_right);
        } else {
          parent = static_cast<t_parent_pointer>(node_ptr);
          return node_ptr->m_right;
        }
      } else {
        if (node_ptr->m_left != nullptr) {
          node_ptr = static_cast<t_node_pointer>(node_ptr->m_left);
        } else {
          parent = static_cast<t_parent_pointer>(node_ptr);
          return parent->m_left;
        }
      }
    }
  }
  parent = static_cast<t_parent_pointer>(get_end_node());
  return parent->m_left;
}

/**
 * @brief Find upper_bound place to insert.
 * Set parent to parent of null leaf.
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param parent
 * @param key_value
 * @return tree<t_type, t_compare, t_allocator>::t_node_base_pointer& Reference to null leaf.
 */
template<class t_type, class t_compare, class t_allocator>
typename tree<t_type, t_compare, t_allocator>::t_node_base_pointer &
  tree<t_type, t_compare, t_allocator>::find_leaf_high(t_parent_pointer &parent, key_type const &key_value) {
  t_node_pointer node_ptr{get_root()};
  if (node_ptr != nullptr) {
    while (true) {
      if (value_comp()(key_value, node_ptr->m_value)) {
        if (node_ptr->m_left != nullptr) {
          node_ptr = static_cast<t_node_pointer>(node_ptr->m_left);
        } else {
          parent = static_cast<t_parent_pointer>(node_ptr);
          return parent->m_left;
        }
      } else {
        if (node_ptr->m_right != nullptr) {
          node_ptr = static_cast<t_node_pointer>(node_ptr->m_right);
        } else {
          parent = static_cast<t_parent_pointer>(node_ptr);
          return node_ptr->m_right;
        }
      }
    }
  }
  parent = static_cast<t_parent_pointer>(get_end_node());
  return parent->m_left;
}

/**
 * @brief Find leaf place to insert closest to hint_pos.
 * First check prior to hint_pos. Next check after hint_pos. Next do O(log N) search.
 * Set parent to parent of null leaf
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param hint_pos
 * @param parent
 * @param key_value
 * @return tree<t_type, t_compare, t_allocator>::t_node_base_pointer& Reference to null leaf
 */
template<class t_type, class t_compare, class t_allocator>
typename tree<t_type, t_compare, t_allocator>::t_node_base_pointer &tree<t_type, t_compare, t_allocator>::find_leaf(
  const_iterator hint_pos, t_parent_pointer &parent, key_type const &key_value) {
  if ((end() == hint_pos) || !value_comp()(*hint_pos, key_value)) // check before
  {
    // key_value <= *hint_pos
    const_iterator prior = hint_pos;
    if ((begin() == prior) || !value_comp()(key_value, *--prior)) {
      // *prev(hint_pos) <= key_value <= *hint_pos
      if (hint_pos.m_ptr->m_left == nullptr) {
        parent = static_cast<t_parent_pointer>(hint_pos.m_ptr);
        return parent->m_left;
      } else {
        parent = static_cast<t_parent_pointer>(prior.m_ptr);
        return static_cast<t_node_base_pointer>(prior.m_ptr)->m_right;
      }
    }
    // key_value < *prev(hint_pos)
    return find_leaf_high(parent, key_value);
  }
  // else key_value > *hint_pos
  return find_leaf_low(parent, key_value);
}

/**
 * @brief Find place to insert if key_value doesn't exist.
 * If key_value exists, set parent to node of key_value, otherwise set parent to parent of null leaf.
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @param parent
 * @param key_value
 * @return tree<t_type, t_compare, t_allocator>::t_node_base_pointer& If key_value exists, return reference to node of
 * key_value, otherwise reference to null leaf.
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type>
typename tree<t_type, t_compare, t_allocator>::t_node_base_pointer &tree<t_type, t_compare, t_allocator>::find_equal(
  t_parent_pointer &parent, t_key_type const &key_value) {
  t_node_pointer       nd{get_root()};
  t_node_base_pointer *nd_ptr{get_root_ptr()};
  if (nd != nullptr) {
    while (true) {
      if (value_comp()(key_value, nd->m_value)) {
        if (nd->m_left != nullptr) {
          nd_ptr = ::portable_stl::addressof(nd->m_left);
          nd     = static_cast<t_node_pointer>(nd->m_left);
        } else {
          parent = static_cast<t_parent_pointer>(nd);
          return parent->m_left;
        }
      } else if (value_comp()(nd->m_value, key_value)) {
        if (nd->m_right != nullptr) {
          nd_ptr = ::portable_stl::addressof(nd->m_right);
          nd     = static_cast<t_node_pointer>(nd->m_right);
        } else {
          parent = static_cast<t_parent_pointer>(nd);
          return nd->m_right;
        }
      } else {
        parent = static_cast<t_parent_pointer>(nd);
        return *nd_ptr;
      }
    }
  }
  parent = static_cast<t_parent_pointer>(get_end_node());
  return parent->m_left;
}

/**
 * @brief Find place to insert if key_value doesn't exist.
 * First check prior to hint_pos. Next check after hint_pos.
 * Next do O(log N) search.
 * If key_value exists, set parent to node of key_value, otherwise set 'parent' to parent of null leaf.
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @param hint_pos
 * @param parent
 * @param dummy
 * @param key_value
 * @return tree<t_type, t_compare, t_allocator>::t_node_base_pointer& If key_value exists, return reference to node of
 * key_value, otherwise reference to null leaf.
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type>
typename tree<t_type, t_compare, t_allocator>::t_node_base_pointer &tree<t_type, t_compare, t_allocator>::find_equal(
  const_iterator hint_pos, t_parent_pointer &parent, t_node_base_pointer &dummy, t_key_type const &key_value) {
  if ((end() == hint_pos) || value_comp()(key_value, *hint_pos)) // check before
  {
    // key_value < *hint_pos
    const_iterator prior{hint_pos};
    if ((begin() == prior) || value_comp()(*--prior, key_value)) {
      // *prev(hint_pos) < key_value < *hint_pos
      if (nullptr == hint_pos.m_ptr->m_left) {
        parent = static_cast<t_parent_pointer>(hint_pos.m_ptr);
        return parent->m_left;
      } else {
        parent = static_cast<t_parent_pointer>(prior.m_ptr);
        return static_cast<t_node_base_pointer>(prior.m_ptr)->m_right;
      }
    }
    // key_value <= *prev(hint_pos)
    return find_equal(parent, key_value);
  } else if (value_comp()(*hint_pos, key_value)) // check after
  {
    // *hint_pos < key_value
    const_iterator iter_next{::portable_stl::next(hint_pos)};
    if ((end() == iter_next) || value_comp()(key_value, *iter_next)) {
      // *hint_pos < key_value < *::portable_stl::next(hint_pos)
      if (nullptr == hint_pos.get_node_pointer()->m_right) {
        parent = static_cast<t_parent_pointer>(hint_pos.m_ptr);
        return static_cast<t_node_base_pointer>(hint_pos.m_ptr)->m_right;
      } else {
        parent = static_cast<t_parent_pointer>(iter_next.m_ptr);
        return parent->m_left;
      }
    }
    // *next(hint_pos) <= key_value
    return find_equal(parent, key_value);
  }
  // else key_value == *hint_pos
  parent = static_cast<t_parent_pointer>(hint_pos.m_ptr);
  dummy  = static_cast<t_node_base_pointer>(hint_pos.m_ptr);
  return dummy;
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param parent
 * @param child
 * @param inserted_node
 */
template<class t_type, class t_compare, class t_allocator>
void tree<t_type, t_compare, t_allocator>::insert_node_at(
  t_parent_pointer parent, t_node_base_pointer &child, t_node_base_pointer inserted_node) noexcept {
  inserted_node->m_left   = nullptr;
  inserted_node->m_right  = nullptr;
  inserted_node->m_parent = parent;
  // inserted_node->m_is_black is initialized in __tree_balance_after_insert
  child                   = inserted_node;
  if (get_begin_node()->m_left != nullptr) {
    get_begin_node() = static_cast<t_iter_pointer>(get_begin_node()->m_left);
  }
  tree_ns::tree_balance_after_insert(get_end_node()->m_left, child);
  ++size();
}

/**
 * @brief Create a node object.
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_args
 * @param args Arguments to create node value with.
 * @return ::portable_stl::expected<typename tree<t_type, t_compare, t_allocator>::t_node_holder,
 * ::portable_stl::portable_stl_error>
 */
template<class t_type, class t_compare, class t_allocator>
template<class... t_args>
::portable_stl::expected<typename tree<t_type, t_compare, t_allocator>::t_node_holder,
                         ::portable_stl::portable_stl_error>
  tree<t_type, t_compare, t_allocator>::create_node(t_args &&...args) {
  static_assert(!typename ::portable_stl::tree_helper::is_tree_value_type<t_args...>::type{}(),
                "Cannot construct from value_type_impl");

  t_node_allocator &node_alloc   = get_node_allocator();
  auto             *new_node_mem = ::portable_stl::allocate_noexcept(node_alloc, 1U); // exception free wrapper
  if (new_node_mem) {
    t_node_holder node_holder(new_node_mem, t_tree_node_deleter(node_alloc));
    t_node_traits::construct(
      node_alloc, t_node_types::get_ptr(node_holder->m_value), ::portable_stl::forward<t_args>(args)...);

    node_holder.get_deleter().m_value_constructed = true; // commit deleter-guard

    return ::portable_stl::expected<t_node_holder, ::portable_stl::portable_stl_error>(
      ::portable_stl::move(node_holder));
  } else {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
      ::portable_stl::portable_stl_error::allocate_error};
  }
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @tparam t_args
 * @param key_value
 * @param args
 * @return ::portable_stl::expected<::portable_stl::tuple<typename tree<t_type, t_compare, t_allocator>::iterator,
 * bool>,
 * ::portable_stl::portable_stl_error>
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type, class... t_args>
::portable_stl::expected<::portable_stl::tuple<typename tree<t_type, t_compare, t_allocator>::iterator, bool>,
                         ::portable_stl::portable_stl_error>
  tree<t_type, t_compare, t_allocator>::emplace_unique_key_args(t_key_type const &key_value, t_args &&...args) {
  t_parent_pointer     parent;
  t_node_base_pointer &child    = find_equal(parent, key_value);
  t_node_pointer       ret      = static_cast<t_node_pointer>(child);
  bool                 inserted = false;
  if (nullptr == child) {
    auto result = create_node(::portable_stl::forward<t_args>(args)...);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
    t_node_holder node_holder{::portable_stl::move(result.value())};
    insert_node_at(parent, child, static_cast<t_node_base_pointer>(node_holder.get()));
    ret      = node_holder.release();
    inserted = true;
  }

  return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>(
    {iterator(ret), inserted});
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @tparam t_args
 * @param hint_pos
 * @param key_value
 * @param args
 * @return ::portable_stl::expected<::portable_stl::tuple<typename tree<t_type, t_compare, t_allocator>::iterator,
 * bool>,
 * ::portable_stl::portable_stl_error>
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type, class... t_args>
::portable_stl::expected<::portable_stl::tuple<typename tree<t_type, t_compare, t_allocator>::iterator, bool>,
                         ::portable_stl::portable_stl_error>
  tree<t_type, t_compare, t_allocator>::emplace_hint_unique_key_args(
    const_iterator hint_pos, t_key_type const &key_value, t_args &&...args) {
  t_parent_pointer     parent;
  t_node_base_pointer  dummy;
  t_node_base_pointer &child    = find_equal(hint_pos, parent, dummy, key_value);
  t_node_pointer       ret      = static_cast<t_node_pointer>(child);
  bool                 inserted = false;
  if (nullptr == child) {
    auto result = create_node(::portable_stl::forward<t_args>(args)...);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
    t_node_holder node_holder{::portable_stl::move(result.value())};
    insert_node_at(parent, child, static_cast<t_node_base_pointer>(node_holder.get()));
    ret      = node_holder.release();
    inserted = true;
  }
  return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>(
    {iterator(ret), inserted});
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_args
 * @param args
 * @return ::portable_stl::expected<::portable_stl::tuple<typename tree<t_type, t_compare, t_allocator>::iterator,
 * bool>,
 * ::portable_stl::portable_stl_error>
 */
template<class t_type, class t_compare, class t_allocator>
template<class... t_args>
::portable_stl::expected<::portable_stl::tuple<typename tree<t_type, t_compare, t_allocator>::iterator, bool>,
                         ::portable_stl::portable_stl_error>
  tree<t_type, t_compare, t_allocator>::emplace_unique_impl(t_args &&...args) {
  auto result = create_node(::portable_stl::forward<t_args>(args)...);
  if (!result) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
  }
  t_node_holder        node_holder{::portable_stl::move(result.value())};
  t_parent_pointer     parent;
  t_node_base_pointer &child    = find_equal(parent, node_holder->m_value);
  t_node_pointer       ret      = static_cast<t_node_pointer>(child);
  bool                 inserted = false;
  if (nullptr == child) {
    insert_node_at(parent, child, static_cast<t_node_base_pointer>(node_holder.get()));
    ret      = node_holder.release();
    inserted = true;
  }
  return ::portable_stl::expected<::portable_stl::tuple<iterator, bool>, ::portable_stl::portable_stl_error>(
    {iterator(ret), inserted});
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_args
 * @param hint_pos
 * @param args
 * @return ::portable_stl::expected<typename tree<t_type, t_compare, t_allocator>::iterator,
 * ::portable_stl::portable_stl_error>
 */
template<class t_type, class t_compare, class t_allocator>
template<class... t_args>
::portable_stl::expected<typename tree<t_type, t_compare, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  tree<t_type, t_compare, t_allocator>::emplace_hint_unique_impl(const_iterator hint_pos, t_args &&...args) {
  auto result = create_node(::portable_stl::forward<t_args>(args)...);
  if (!result) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
  }
  t_node_holder        node_holder{::portable_stl::move(result.value())};
  t_parent_pointer     parent;
  t_node_base_pointer  dummy;
  t_node_base_pointer &child = find_equal(hint_pos, parent, dummy, node_holder->m_value);
  t_node_pointer       ret   = static_cast<t_node_pointer>(child);
  if (nullptr == child) {
    insert_node_at(parent, child, static_cast<t_node_base_pointer>(node_holder.get()));
    ret = node_holder.release();
  }
  return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>(iterator(ret));
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_args
 * @param args
 * @return ::portable_stl::expected<typename tree<t_type, t_compare, t_allocator>::iterator,
 * ::portable_stl::portable_stl_error>
 */
template<class t_type, class t_compare, class t_allocator>
template<class... t_args>
::portable_stl::expected<typename tree<t_type, t_compare, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  tree<t_type, t_compare, t_allocator>::emplace_multi(t_args &&...args) {
  auto result = create_node(::portable_stl::forward<t_args>(args)...);
  if (!result) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
  }
  t_node_holder        node_holder{::portable_stl::move(result.value())};
  t_parent_pointer     parent;
  t_node_base_pointer &child = find_leaf_high(parent, t_node_types::get_key(node_holder->m_value));
  insert_node_at(parent, child, static_cast<t_node_base_pointer>(node_holder.get()));

  return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>(
    iterator(static_cast<t_node_pointer>(node_holder.release())));
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_args
 * @param hint_pos
 * @param args
 * @return ::portable_stl::expected<typename tree<t_type, t_compare, t_allocator>::iterator,
 * ::portable_stl::portable_stl_error>
 */
template<class t_type, class t_compare, class t_allocator>
template<class... t_args>
::portable_stl::expected<typename tree<t_type, t_compare, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  tree<t_type, t_compare, t_allocator>::emplace_hint_multi(const_iterator hint_pos, t_args &&...args) {
  auto result = create_node(::portable_stl::forward<t_args>(args)...);
  if (!result) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
  }
  t_node_holder        node_holder{::portable_stl::move(result.value())};
  t_parent_pointer     parent;
  t_node_base_pointer &child = find_leaf(hint_pos, parent, t_node_types::get_key(node_holder->m_value));
  insert_node_at(parent, child, static_cast<t_node_base_pointer>(node_holder.get()));

  return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>(
    iterator(static_cast<t_node_pointer>(node_holder.release())));
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param value
 * @param dest_node_ptr
 * @return ::portable_stl::tuple<typename tree<t_type, t_compare, t_allocator>::iterator, bool>
 */
template<class t_type, class t_compare, class t_allocator>
::portable_stl::tuple<typename tree<t_type, t_compare, t_allocator>::iterator, bool>
  tree<t_type, t_compare, t_allocator>::node_assign_unique(t_container_value_type const &value,
                                                           t_node_pointer                dest_node_ptr) {
  t_parent_pointer     parent;
  t_node_base_pointer &child{find_equal(parent, t_node_types::get_key(value))};
  auto                 ret = static_cast<t_node_pointer>(child);
  bool                 inserted{false};
  if (nullptr == child) {
    dest_node_ptr->m_value = value;
    insert_node_at(parent, child, static_cast<t_node_base_pointer>(dest_node_ptr));
    ret      = dest_node_ptr;
    inserted = true;
  }
  return ::portable_stl::tuple<iterator, bool>(iterator(ret), inserted);
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param node_ptr
 * @return tree<t_type, t_compare, t_allocator>::iterator
 */
template<class t_type, class t_compare, class t_allocator>
typename tree<t_type, t_compare, t_allocator>::iterator tree<t_type, t_compare, t_allocator>::node_insert_multi(
  t_node_pointer node_ptr) {
  t_parent_pointer     parent;
  t_node_base_pointer &child = find_leaf_high(parent, t_node_types::get_key(node_ptr->m_value));
  insert_node_at(parent, child, static_cast<t_node_base_pointer>(node_ptr));
  return iterator(node_ptr);
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param pos
 * @param node_ptr
 * @return tree<t_type, t_compare, t_allocator>::iterator
 */
template<class t_type, class t_compare, class t_allocator>
typename tree<t_type, t_compare, t_allocator>::iterator tree<t_type, t_compare, t_allocator>::node_insert_multi(
  const_iterator pos, t_node_pointer node_ptr) {
  t_parent_pointer     parent;
  t_node_base_pointer &child = find_leaf(pos, parent, t_node_types::get_key(node_ptr->m_value));
  insert_node_at(parent, child, static_cast<t_node_base_pointer>(node_ptr));
  return iterator(node_ptr);
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param node_ptr
 * @return tree<t_type, t_compare, t_allocator>::iterator
 */
template<class t_type, class t_compare, class t_allocator>
typename tree<t_type, t_compare, t_allocator>::iterator tree<t_type, t_compare, t_allocator>::remove_node_pointer(
  t_node_pointer node_ptr) noexcept {
  iterator ret(node_ptr);
  ++ret;
  if (get_begin_node() == node_ptr) {
    get_begin_node() = ret.m_ptr;
  }
  --size();
  tree_ns::tree_remove(get_end_node()->m_left, static_cast<t_node_base_pointer>(node_ptr));
  return ret;
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_node_handle
 * @tparam t_insert_return_type
 * @param node_hdl
 * @return t_insert_return_type
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_node_handle, class t_insert_return_type>
t_insert_return_type tree<t_type, t_compare, t_allocator>::node_handle_insert_unique(t_node_handle &&node_hdl) {
  if (node_hdl.empty()) {
    return t_insert_return_type{end(), false, t_node_handle()};
  }

  t_node_pointer       node_ptr = node_hdl.m_ptr;
  t_parent_pointer     parent;
  t_node_base_pointer &child = find_equal(parent, node_ptr->m_value);
  if (child != nullptr) {
    return t_insert_return_type{iterator(static_cast<t_node_pointer>(child)), false, ::portable_stl::move(node_hdl)};
  }

  insert_node_at(parent, child, static_cast<t_node_base_pointer>(node_ptr));
  node_hdl.release_ptr();
  return t_insert_return_type{iterator(node_ptr), true, t_node_handle()};
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_node_handle
 * @param hint_pos
 * @param node_hdl
 * @return tree<t_type, t_compare, t_allocator>::iterator
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_node_handle>
typename tree<t_type, t_compare, t_allocator>::iterator tree<t_type, t_compare, t_allocator>::node_handle_insert_unique(
  const_iterator hint_pos, t_node_handle &&node_hdl) {
  if (node_hdl.empty()) {
    return end();
  }

  t_node_pointer       node_ptr = node_hdl.m_ptr;
  t_parent_pointer     parent;
  t_node_base_pointer  dummy;
  t_node_base_pointer &child = find_equal(hint_pos, parent, dummy, node_ptr->m_value);
  t_node_pointer       ret   = static_cast<t_node_pointer>(child);
  if (nullptr == child) {
    insert_node_at(parent, child, static_cast<t_node_base_pointer>(node_ptr));
    ret = node_ptr;
    node_hdl.release_ptr();
  }
  return iterator(ret);
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_node_handle
 * @param key
 * @return t_node_handle
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_node_handle>
t_node_handle tree<t_type, t_compare, t_allocator>::node_handle_extract(key_type const &key) {
  iterator iter = find(key);
  if (iter == end()) {
    return t_node_handle();
  }
  return node_handle_extract<t_node_handle>(iter);
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_node_handle
 * @param pos
 * @return t_node_handle
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_node_handle>
t_node_handle tree<t_type, t_compare, t_allocator>::node_handle_extract(const_iterator pos) {
  t_node_pointer node_ptr = pos.get_node_pointer();
  remove_node_pointer(node_ptr);
  return t_node_handle(node_ptr, get_alloc());
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_tree
 * @param src_tree
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_tree>
void tree<t_type, t_compare, t_allocator>::node_handle_merge_unique(t_tree &src_tree) {
  static_assert(::portable_stl::is_same<typename t_tree::t_node_pointer, t_node_pointer>{}(), "");

  for (typename t_tree::iterator iter{src_tree.begin()}; iter != src_tree.end();) {
    t_node_pointer       src_ptr = iter.get_node_pointer();
    t_parent_pointer     parent;
    t_node_base_pointer &child = find_equal(parent, t_node_types::get_key(src_ptr->m_value));
    ++iter;
    if (child != nullptr) {
      continue;
    }
    src_tree.remove_node_pointer(src_ptr);
    insert_node_at(parent, child, static_cast<t_node_base_pointer>(src_ptr));
  }
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_node_handle
 * @param node_hdl
 * @return tree<t_type, t_compare, t_allocator>::iterator
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_node_handle>
typename tree<t_type, t_compare, t_allocator>::iterator tree<t_type, t_compare, t_allocator>::node_handle_insert_multi(
  t_node_handle &&node_hdl) {
  if (node_hdl.empty()) {
    return end();
  }
  t_node_pointer       node_ptr = node_hdl.m_ptr;
  t_parent_pointer     parent;
  t_node_base_pointer &child = find_leaf_high(parent, t_node_types::get_key(node_ptr->m_value));
  insert_node_at(parent, child, static_cast<t_node_base_pointer>(node_ptr));
  node_hdl.release_ptr();
  return iterator(node_ptr);
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_node_handle
 * @param hint_pos
 * @param node_hdl
 * @return tree<t_type, t_compare, t_allocator>::iterator
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_node_handle>
typename tree<t_type, t_compare, t_allocator>::iterator tree<t_type, t_compare, t_allocator>::node_handle_insert_multi(
  const_iterator hint_pos, t_node_handle &&node_hdl) {
  if (node_hdl.empty()) {
    return end();
  }

  t_node_pointer       node_ptr = node_hdl.m_ptr;
  t_parent_pointer     parent;
  t_node_base_pointer &child = find_leaf(hint_pos, parent, t_node_types::get_key(node_ptr->m_value));
  insert_node_at(parent, child, static_cast<t_node_base_pointer>(node_ptr));
  node_hdl.release_ptr();
  return iterator(node_ptr);
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_tree
 * @param src_tree
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_tree>
void tree<t_type, t_compare, t_allocator>::node_handle_merge_multi(t_tree &src_tree) {
  static_assert(::portable_stl::is_same<typename t_tree::t_node_pointer, t_node_pointer>{}(), "");

  for (typename t_tree::iterator iter{src_tree.begin()}; iter != src_tree.end();) {
    t_node_pointer       src_node_ptr = iter.get_node_pointer();
    t_parent_pointer     parent;
    t_node_base_pointer &child = find_leaf_high(parent, t_node_types::get_key(src_node_ptr->m_value));
    ++iter;
    src_tree.remove_node_pointer(src_node_ptr);
    insert_node_at(parent, child, static_cast<t_node_base_pointer>(src_node_ptr));
  }
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param pos
 * @return tree<t_type, t_compare, t_allocator>::iterator
 */
template<class t_type, class t_compare, class t_allocator>
typename tree<t_type, t_compare, t_allocator>::iterator tree<t_type, t_compare, t_allocator>::erase(
  const_iterator pos) {
  t_node_pointer    node_ptr{pos.get_node_pointer()};
  iterator          ret{remove_node_pointer(node_ptr)};
  t_node_allocator &node_alloc{get_node_allocator()};
  t_node_traits::destroy(node_alloc, t_node_types::get_ptr(const_cast<t_node_value_type &>(*pos)));
  t_node_traits::deallocate(node_alloc, node_ptr, 1);
  return ret;
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param first_pos
 * @param last_pos
 * @return tree<t_type, t_compare, t_allocator>::iterator
 */
template<class t_type, class t_compare, class t_allocator>
typename tree<t_type, t_compare, t_allocator>::iterator tree<t_type, t_compare, t_allocator>::erase(
  const_iterator first_pos, const_iterator last_pos) {
  while (first_pos != last_pos) {
    first_pos = erase(first_pos);
  }
  return iterator(last_pos.m_ptr);
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @param key
 * @return tree<t_type, t_compare, t_allocator>::size_type
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type>
typename tree<t_type, t_compare, t_allocator>::size_type tree<t_type, t_compare, t_allocator>::erase_unique(
  t_key_type const &key) {
  iterator iter = find(key);
  if (iter == end()) {
    return 0;
  }
  erase(iter);
  return 1;
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @param key
 * @return tree<t_type, t_compare, t_allocator>::size_type
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type>
typename tree<t_type, t_compare, t_allocator>::size_type tree<t_type, t_compare, t_allocator>::erase_multi(
  t_key_type const &key) {
  ::portable_stl::tuple<iterator, iterator> range_pair = equal_range_multi(key);
  size_type                                 ret        = 0;
  for (; ::portable_stl::get<0>(range_pair) != ::portable_stl::get<1>(range_pair); ++ret) {
    ::portable_stl::get<0>(range_pair) = erase(::portable_stl::get<0>(range_pair));
  }
  return ret;
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @param key_value
 * @return tree<t_type, t_compare, t_allocator>::iterator
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type>
typename tree<t_type, t_compare, t_allocator>::iterator tree<t_type, t_compare, t_allocator>::find(
  t_key_type const &key_value) {
  iterator pos = lower_bound(key_value, get_root(), get_end_node());
  if (pos != end() && !value_comp()(key_value, *pos)) {
    return pos;
  }
  return end();
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @param key_value
 * @return tree<t_type, t_compare, t_allocator>::const_iterator
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type>
typename tree<t_type, t_compare, t_allocator>::const_iterator tree<t_type, t_compare, t_allocator>::find(
  t_key_type const &key_value) const {
  const_iterator pos = lower_bound(key_value, get_root(), get_end_node());
  if (pos != end() && !value_comp()(key_value, *pos)) {
    return pos;
  }
  return end();
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @param key_value
 * @return tree<t_type, t_compare, t_allocator>::size_type
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type>
typename tree<t_type, t_compare, t_allocator>::size_type tree<t_type, t_compare, t_allocator>::count_unique(
  t_key_type const &key_value) const {
  t_node_pointer cur_root = get_root();
  while (cur_root != nullptr) {
    if (value_comp()(key_value, cur_root->m_value)) {
      cur_root = static_cast<t_node_pointer>(cur_root->m_left);
    } else if (value_comp()(cur_root->m_value, key_value)) {
      cur_root = static_cast<t_node_pointer>(cur_root->m_right);
    } else {
      return 1;
    }
  }
  return 0;
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @param key_value
 * @return tree<t_type, t_compare, t_allocator>::size_type
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type>
typename tree<t_type, t_compare, t_allocator>::size_type tree<t_type, t_compare, t_allocator>::count_multi(
  t_key_type const &key_value) const {
  t_iter_pointer result   = get_end_node();
  t_node_pointer cur_root = get_root();
  while (cur_root != nullptr) {
    if (value_comp()(key_value, cur_root->m_value)) {
      result   = static_cast<t_iter_pointer>(cur_root);
      cur_root = static_cast<t_node_pointer>(cur_root->m_left);
    } else if (value_comp()(cur_root->m_value, key_value)) {
      cur_root = static_cast<t_node_pointer>(cur_root->m_right);
    } else {
      return static_cast<size_type>(::portable_stl::distance(
        lower_bound(key_value, static_cast<t_node_pointer>(cur_root->m_left), static_cast<t_iter_pointer>(cur_root)),
        upper_bound(key_value, static_cast<t_node_pointer>(cur_root->m_right), result)));
    }
  }
  return 0;
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @param key_value
 * @param node_ptr
 * @param result
 * @return tree<t_type, t_compare, t_allocator>::iterator
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type>
typename tree<t_type, t_compare, t_allocator>::iterator tree<t_type, t_compare, t_allocator>::lower_bound(
  t_key_type const &key_value, t_node_pointer node_ptr, t_iter_pointer result) {
  while (node_ptr != nullptr) {
    if (!value_comp()(node_ptr->m_value, key_value)) {
      result   = static_cast<t_iter_pointer>(node_ptr);
      node_ptr = static_cast<t_node_pointer>(node_ptr->m_left);
    } else {
      node_ptr = static_cast<t_node_pointer>(node_ptr->m_right);
    }
  }
  return iterator(result);
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @param key_value
 * @param node_ptr
 * @param result
 * @return tree<t_type, t_compare, t_allocator>::const_iterator
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type>
typename tree<t_type, t_compare, t_allocator>::const_iterator tree<t_type, t_compare, t_allocator>::lower_bound(
  t_key_type const &key_value, t_node_pointer node_ptr, t_iter_pointer result) const {
  while (node_ptr != nullptr) {
    if (!value_comp()(node_ptr->m_value, key_value)) {
      result   = static_cast<t_iter_pointer>(node_ptr);
      node_ptr = static_cast<t_node_pointer>(node_ptr->m_left);
    } else {
      node_ptr = static_cast<t_node_pointer>(node_ptr->m_right);
    }
  }
  return const_iterator(result);
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @param key_value
 * @param node_ptr
 * @param result
 * @return tree<t_type, t_compare, t_allocator>::iterator
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type>
typename tree<t_type, t_compare, t_allocator>::iterator tree<t_type, t_compare, t_allocator>::upper_bound(
  t_key_type const &key_value, t_node_pointer node_ptr, t_iter_pointer result) {
  while (node_ptr != nullptr) {
    if (value_comp()(key_value, node_ptr->m_value)) {
      result   = static_cast<t_iter_pointer>(node_ptr);
      node_ptr = static_cast<t_node_pointer>(node_ptr->m_left);
    } else {
      node_ptr = static_cast<t_node_pointer>(node_ptr->m_right);
    }
  }
  return iterator(result);
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @param key_value
 * @param node_ptr
 * @param result
 * @return tree<t_type, t_compare, t_allocator>::const_iterator
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type>
typename tree<t_type, t_compare, t_allocator>::const_iterator tree<t_type, t_compare, t_allocator>::upper_bound(
  t_key_type const &key_value, t_node_pointer node_ptr, t_iter_pointer result) const {
  while (node_ptr != nullptr) {
    if (value_comp()(key_value, node_ptr->m_value)) {
      result   = static_cast<t_iter_pointer>(node_ptr);
      node_ptr = static_cast<t_node_pointer>(node_ptr->m_left);
    } else {
      node_ptr = static_cast<t_node_pointer>(node_ptr->m_right);
    }
  }
  return const_iterator(result);
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @param key_value
 * @return ::portable_stl::tuple<typename tree<t_type, t_compare, t_allocator>::iterator,
 * typename tree<t_type, t_compare, t_allocator>::iterator>
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type>
::portable_stl::tuple<typename tree<t_type, t_compare, t_allocator>::iterator,
                      typename tree<t_type, t_compare, t_allocator>::iterator>
  tree<t_type, t_compare, t_allocator>::equal_range_unique(t_key_type const &key_value) {
  using t_return_range    = ::portable_stl::tuple<iterator, iterator>;
  t_iter_pointer result   = get_end_node();
  t_node_pointer cur_root = get_root();
  while (cur_root != nullptr) {
    if (value_comp()(key_value, cur_root->m_value)) {
      result   = static_cast<t_iter_pointer>(cur_root);
      cur_root = static_cast<t_node_pointer>(cur_root->m_left);
    } else if (value_comp()(cur_root->m_value, key_value)) {
      cur_root = static_cast<t_node_pointer>(cur_root->m_right);
    } else {
      return t_return_range(iterator(cur_root),
                            iterator(cur_root->m_right != nullptr
                                       ? static_cast<t_iter_pointer>(tree_ns::tree_min(cur_root->m_right))
                                       : result));
    }
  }
  return t_return_range(iterator(result), iterator(result));
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @param key_value
 * @return ::portable_stl::tuple<typename tree<t_type, t_compare, t_allocator>::const_iterator,
 * typename tree<t_type, t_compare, t_allocator>::const_iterator>
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type>
::portable_stl::tuple<typename tree<t_type, t_compare, t_allocator>::const_iterator,
                      typename tree<t_type, t_compare, t_allocator>::const_iterator>
  tree<t_type, t_compare, t_allocator>::equal_range_unique(t_key_type const &key_value) const {
  using t_return_range    = ::portable_stl::tuple<const_iterator, const_iterator>;
  t_iter_pointer result   = get_end_node();
  t_node_pointer cur_root = get_root();
  while (cur_root != nullptr) {
    if (value_comp()(key_value, cur_root->m_value)) {
      result   = static_cast<t_iter_pointer>(cur_root);
      cur_root = static_cast<t_node_pointer>(cur_root->m_left);
    } else if (value_comp()(cur_root->m_value, key_value)) {
      cur_root = static_cast<t_node_pointer>(cur_root->m_right);
    } else {
      return t_return_range(const_iterator(cur_root),
                            const_iterator(cur_root->m_right != nullptr
                                             ? static_cast<t_iter_pointer>(tree_ns::tree_min(cur_root->m_right))
                                             : result));
    }
  }
  return t_return_range(const_iterator(result), const_iterator(result));
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @param key_value
 * @return ::portable_stl::tuple<typename tree<t_type, t_compare, t_allocator>::iterator,
 * typename tree<t_type, t_compare, t_allocator>::iterator>
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type>
::portable_stl::tuple<typename tree<t_type, t_compare, t_allocator>::iterator,
                      typename tree<t_type, t_compare, t_allocator>::iterator>
  tree<t_type, t_compare, t_allocator>::equal_range_multi(t_key_type const &key_value) {
  using t_return_range    = ::portable_stl::tuple<iterator, iterator>;
  t_iter_pointer result   = get_end_node();
  t_node_pointer cur_root = get_root();
  while (cur_root != nullptr) {
    if (value_comp()(key_value, cur_root->m_value)) {
      result   = static_cast<t_iter_pointer>(cur_root);
      cur_root = static_cast<t_node_pointer>(cur_root->m_left);
    } else if (value_comp()(cur_root->m_value, key_value)) {
      cur_root = static_cast<t_node_pointer>(cur_root->m_right);
    } else {
      return t_return_range(
        lower_bound(key_value, static_cast<t_node_pointer>(cur_root->m_left), static_cast<t_iter_pointer>(cur_root)),
        upper_bound(key_value, static_cast<t_node_pointer>(cur_root->m_right), result));
    }
  }
  return t_return_range(iterator(result), iterator(result));
}

/**
 * @brief
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @tparam t_key_type
 * @param key_value
 * @return ::portable_stl::tuple<typename tree<t_type, t_compare, t_allocator>::const_iterator,
 * typename tree<t_type, t_compare, t_allocator>::const_iterator>
 */
template<class t_type, class t_compare, class t_allocator>
template<class t_key_type>
::portable_stl::tuple<typename tree<t_type, t_compare, t_allocator>::const_iterator,
                      typename tree<t_type, t_compare, t_allocator>::const_iterator>
  tree<t_type, t_compare, t_allocator>::equal_range_multi(t_key_type const &key_value) const {
  using t_return_range    = ::portable_stl::tuple<const_iterator, const_iterator>;
  t_iter_pointer result   = get_end_node();
  t_node_pointer cur_root = get_root();
  while (cur_root != nullptr) {
    if (value_comp()(key_value, cur_root->m_value)) {
      result   = static_cast<t_iter_pointer>(cur_root);
      cur_root = static_cast<t_node_pointer>(cur_root->m_left);
    } else if (value_comp()(cur_root->m_value, key_value)) {
      cur_root = static_cast<t_node_pointer>(cur_root->m_right);
    } else {
      return t_return_range(
        lower_bound(key_value, static_cast<t_node_pointer>(cur_root->m_left), static_cast<t_iter_pointer>(cur_root)),
        upper_bound(key_value, static_cast<t_node_pointer>(cur_root->m_right), result));
    }
  }
  return t_return_range(const_iterator(result), const_iterator(result));
}

/**
 * @brief Remove element at pos.
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param pos
 * @return tree<t_type, t_compare, t_allocator>::t_node_holder
 */
template<class t_type, class t_compare, class t_allocator>
typename tree<t_type, t_compare, t_allocator>::t_node_holder tree<t_type, t_compare, t_allocator>::remove(
  const_iterator pos) noexcept {
  t_node_pointer node_ptr = pos.get_node_pointer();
  if (get_begin_node() == pos.m_ptr) {
    if (node_ptr->m_right != nullptr) {
      get_begin_node() = static_cast<t_iter_pointer>(node_ptr->m_right);
    } else {
      get_begin_node() = static_cast<t_iter_pointer>(node_ptr->m_parent);
    }
  }
  --size();
  tree_ns::tree_remove(get_end_node()->m_left, static_cast<t_node_base_pointer>(node_ptr));
  return t_node_holder(node_ptr, t_tree_node_deleter(get_node_allocator(), true));
}

/**
 * @brief Specializes the ::swap algorithm for ::tree. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
 *
 * @tparam t_type
 * @tparam t_compare
 * @tparam t_allocator
 * @param lhv tree whose contents to swap.
 * @param rhv tree whose contents to swap.
 */
template<class t_type, class t_compare, class t_allocator>
inline void swap(tree<t_type, t_compare, t_allocator> &lhv,
                 tree<t_type, t_compare, t_allocator> &rhv) noexcept(noexcept(lhv.swap(rhv))) {
  lhv.swap(rhv);
}

} // namespace portable_stl

#endif // PSTL_TREE_H
