// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="vector.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_VECTOR_H
#define PSTL_VECTOR_H

#include "../algorithm/equal.h"
#include "../algorithm/fill_n.h"
#include "../algorithm/lexicographical_compare.h"
#include "../algorithm/min.h"
#include "../algorithm/move_algo.h"
#include "../algorithm/move_backward.h"
#include "../algorithm/rotate.h"
#include "../common/size_t.h"
#include "../error/portable_stl_error.h"
#include "../iterator/distance.h"
#include "../iterator/iter_value_t.h"
#include "../iterator/move_iterator.h"
#include "../iterator/next.h"
#include "../iterator/niter_base.h"
#include "../iterator/random_access_iterator_tag.h"
#include "../iterator/reverse_iterator.h"
#include "../iterator/wrap_iter.h"
#include "../language_support/bad_alloc.h"
#include "../language_support/length_error.h"
#include "../language_support/out_of_range.h"
#include "../memory/addressof.h"
#include "../memory/allocate_at_least.h"
#include "../memory/allocate_noexcept.h"
#include "../memory/allocator.h"
#include "../memory/allocator_traits.h"
#include "../memory/compressed_pair.h"
#include "../memory/construct_at_noexcept.h"
#include "../memory/is_move_insertable.h"
#include "../memory/make_unique.h"
#include "../memory/pointer_traits.h"
#include "../memory/swap_allocator.h"
#include "../memory/temp_value.h"
#include "../memory/to_address.h"
#include "../metaprogramming/constant_evaluation/is_constant_evaluated.h"
#include "../metaprogramming/cv_modifications/remove_cv.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/conditional_bool_constant.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/type_identity.h"
#include "../metaprogramming/primary_type/is_allocator.h"
#include "../metaprogramming/type_properties/is_constructible.h"
#include "../metaprogramming/type_properties/is_copy_constructible.h"
#include "../metaprogramming/type_properties/is_nothrow_move_assignable.h"
#include "../metaprogramming/type_properties/is_nothrow_move_constructible.h"
#include "../metaprogramming/type_properties/is_trivial.h"
#include "../metaprogramming/type_relations/is_same.h"
#include "../metaprogramming/type_traits/noexcept_move_assign_container.h"
#include "../utility/expected/expected.h"
#include "../utility/expected/unexpected.h"
#include "../utility/general/declval.h"
#include "../utility/general/functional/reference_wrapper.h"
#include "../utility/general/make_exception_guard.h"
#include "split_buffer.h"
#include "vector_algo.h"
#include "vector_helper.h"

#if defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  include "../language_support/exception/throw_on_true.h"
#else
#  include "../language_support/no_exception/throw_on_true.h"
#endif

namespace portable_stl {

/**
 * @brief A sequence container that encapsulates dynamic size arrays.
 *
 * @tparam t_type The type of the elements.
 * @tparam t_allocator An allocator that is used to acquire/release memory and to construct/destroy the elements in that
 * memory. The type must meet the requirements of Allocator. The program is ill-formed(since C++20) if
 * Allocator::value_type is not the same as t_type.
 */
template<class t_type, class t_allocator = ::portable_stl::allocator<t_type>> class vector {
  static_assert(::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, t_type>{}(),
                "portable_stl::vector must have a non-const, non-volatile value_type");
  static_assert(::portable_stl::is_same<typename t_allocator::value_type, t_type>{}(),
                "portable_stl::vector must have the same value_type as its allocator");

  // using t_default_allocator = ::portable_stl::allocator<t_type>;

public:
  /**
   * @brief Self type alias to use in bit_reference.
   */
  using t_self                 = vector;
  /**
   * @brief Value type.
   */
  using value_type             = t_type;
  /**
   * @brief Allocator type.
   */
  using allocator_type         = t_allocator;
  /**
   * @brief Allocator traits.
   */
  using t_allocator_traits     = ::portable_stl::allocator_traits<allocator_type>;
  /**
   * @brief Pointer type.
   */
  using pointer                = typename t_allocator_traits::pointer;
  /**
   * @brief Pointer to const type.
   */
  using const_pointer          = typename t_allocator_traits::const_pointer;
  /**
   * @brief Reference type.
   */
  using reference              = value_type &;
  /**
   * @brief Const reference type.
   */
  using const_reference        = value_type const &;
  /**
   * @brief Size type.
   */
  using size_type              = ::portable_stl::size_t;
  /**
   * @brief Difference type.
   */
  using difference_type        = ::portable_stl::ptrdiff_t;
  /**
   * @brief Iterator type.
   */
  using iterator               = ::portable_stl::wrap_iter<pointer>;
  /**
   * @brief Const iterator type.
   */
  using const_iterator         = ::portable_stl::wrap_iter<const_pointer>;
  /**
   * @brief Reverse iterator type.
   */
  using reverse_iterator       = ::portable_stl::reverse_iterator<iterator>;
  /**
   * @brief Reverse const iterator type.
   */
  using const_reverse_iterator = ::portable_stl::reverse_iterator<const_iterator>;

private:
  /**
   * @brief Reference wrapper to value_type. Used in expected return.
   */
  using reference_wrap       = ::portable_stl::reference_wrapper<value_type>;
  /**
   * @brief Reference wrapper to const value_type. Used in expected return.
   */
  using const_reference_wrap = ::portable_stl::reference_wrapper<value_type const>;

  /**
   * @brief Internal pointer to the begin of the storage.
   */
  pointer m_begin = nullptr;

  /**
   * @brief Internal pointer to the last element in the storage.
   */
  pointer m_end = nullptr;

  /**
   * @brief Pair to store pointer to the end of the allocated storage and allocator (state or stateless).
   */
  ::portable_stl::compressed_pair<pointer, allocator_type> m_end_cap
    = ::portable_stl::compressed_pair<pointer, allocator_type>(nullptr, allocator_type());

  /**
   * @brief Retrieving vector's allocator.
   * @return allocator_type&
   */
  allocator_type &M_alloc() noexcept {
    return m_end_cap.get_second();
  }

  /**
   * @brief Retrieving vector's allocator constant.
   * @return allocator_type const&
   */
  allocator_type const &M_alloc() const noexcept {
    return m_end_cap.get_second();
  }

  /**
   * @brief Retrieving pointer to the end of vector's allocated storage.
   * @return pointer&
   */
  pointer &M_end_cap() noexcept {
    return m_end_cap.get_first();
  }

  /**
   * @brief Retrieving const pointer to the end of vector's allocated storage.
   * @return pointer&
   */
  pointer const &M_end_cap() const noexcept {
    return m_end_cap.get_first();
  }

public:
  // static_assert(::portable_stl::is_same<allocator_type, __rebind_alloc<t_allocator_traits, value_type>>::value,
  //               "[allocator.requirements] states that rebinding an allocator to the same type should result in the "
  //               "original allocator");

  // [24.3.12.2, construct/copy/destroy]

  /**
   * @brief Default constructor. Constructs an empty container with a default-constructed allocator.
   * @throw allocator_type() may throw.
   */
  vector() noexcept(noexcept(allocator_type())) : m_end_cap(nullptr, allocator_type()) {
  }

  /**
   * @brief Constructs an empty container with the given allocator alloc.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  explicit constexpr vector(allocator_type const &alloc) noexcept : m_end_cap(nullptr, alloc) {
  }

  /**
   * @brief Creates a vector with default constructed elements.
   * This constructor fills the vector with num default constructed elements. No copies are made.
   * @throw value_type() may throw;
   *        length_error if num > max_size();
   *        bad_alloc if memory cannot be allocated.
   * @param num The number of elements to initially create.
   */
  explicit vector(size_type num);

  /**
   * @brief Creates a vector with default constructed elements.
   * Fills the vector with num default constructed elements. No copies are made.
   * @throw value_type() may throw;
   * @param num The number of elements to initially create.
   * @return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>
   */
  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(size_type num) noexcept(
    noexcept(t_type()));

  /**
   * @brief Creates a vector with default constructed elements and with the given allocator alloc.
   * This constructor fills the vector with num default constructed elements.
   * @throw value_type() may throw;
   *        length_error if num > max_size();
   *        bad_alloc if memory cannot be allocated.
   * @param num The number of elements to initially create.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  explicit vector(size_type num, allocator_type const &alloc);

  /**
   * @brief Creates a vector with default constructed elements and with the given allocator alloc.
   * Fills the vector with num default constructed elements.
   * @param num The number of elements to initially create.
   * @param alloc Allocator to use for all memory allocations of this container.
   * @return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>
   */
  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(
    size_type num, allocator_type const &alloc) noexcept(noexcept(t_type()));

  /**
   * @brief Constructs the container with num copies of elements with value value.
   * This constructor fills the vector with num copies of value.
   * @param num The number of elements to initially create.
   * @param value The value to initialize elements of the container with.
   */
  explicit vector(size_type num, value_type const &value);

  /**
   * @brief Constructs the container with num copies of elements with value value.
   * Fills the vector with num copies of value.
   * @param num The number of elements to initially create.
   * @param value The value to initialize elements of the container with.
   * @return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>
   */
  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(
    size_type num, value_type const &value) noexcept(noexcept(t_type(value)));

  /**
   * @brief Constructs the container with num copies of elements with value value and with the given allocator alloc.
   * This constructor fills the vector with num copies of value.
   * @param num The number of elements to initially create.
   * @param value The value to initialize elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  template<class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_allocator<allocator_type>>>
  vector(size_type num, value_type const &value, allocator_type const &alloc);

  /**
   * @brief Constructs the container with num copies of elements with value value and with the given allocator alloc.
   * Fills the vector with num copies of value.
   * @param num The number of elements to initially create.
   * @param value The value to initialize elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this container.
   * @return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>
   */
  template<class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_allocator<allocator_type>>>
  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(
    size_type num, value_type const &value, allocator_type const &alloc) noexcept(noexcept(t_type(value)));

  /**
   * @brief Builds a vector from a range.
   * Create a vector consisting of copies of the elements from [first,last).
   * If the iterators are forward, bidirectional, or random-access, then this will call the elements' copy constructor N
   * times (where N is distance(first,last)) and do no memory reallocation. But if only input iterators are used, then
   * this will do at most 2N calls to the copy constructor, and logN memory reallocations.
   *
   * @tparam t_input_iterator Satisfies LegacyInputIterator.
   * @param first The range [first, last) to copy the elements from.
   * @param last The range [first, last) to copy the elements from.
   */
  template<class t_input_iterator, vector_helper::enable_for_input_iter<t_input_iterator, value_type> = nullptr>
  vector(t_input_iterator first, t_input_iterator last);

  /**
   * @brief Builds a vector from a range.
   * Create a vector consisting of copies of the elements from [first,last).
   * If the iterators are forward, bidirectional, or random-access, then this will call the elements' copy constructor N
   * times (where N is distance(first,last)) and do no memory reallocation. But if only input iterators are used, then
   * this will do at most 2N calls to the copy constructor, and logN memory reallocations.
   *
   * @tparam t_input_iterator Satisfies LegacyInputIterator.
   * @param first The range [first, last) to copy the elements from.
   * @param last The range [first, last) to copy the elements from.
   * @return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>
   */
  template<class t_input_iterator, vector_helper::enable_for_input_iter<t_input_iterator, value_type> = nullptr>
  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(t_input_iterator first,
                                                                                          t_input_iterator last);

  /**
   * @brief Builds a vector from a range.
   * Create a vector consisting of copies of the elements from [first,last).
   * If the iterators are forward, bidirectional, or random-access, then this will call the elements' copy constructor N
   * times (where N is distance(first,last)) and do no memory reallocation. But if only input iterators are used, then
   * this will do at most 2N calls to the copy constructor, and logN memory reallocations.
   *
   * @tparam t_input_iterator Satisfies LegacyInputIterator.
   * @param first The range [first, last) to copy the elements from.
   * @param last The range [first, last) to copy the elements from.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  template<class t_input_iterator, vector_helper::enable_for_input_iter<t_input_iterator, value_type> = nullptr>
  vector(t_input_iterator first, t_input_iterator last, allocator_type const &alloc);

  /**
   * @brief Builds a vector from a range.
   * Create a vector consisting of copies of the elements from [first,last).
   * If the iterators are forward, bidirectional, or random-access, then this will call the elements' copy constructor N
   * times (where N is distance(first,last)) and do no memory reallocation. But if only input iterators are used, then
   * this will do at most 2N calls to the copy constructor, and logN memory reallocations.
   *
   * @tparam t_input_iterator Satisfies LegacyInputIterator.
   * @param first The range [first, last) to copy the elements from.
   * @param last The range [first, last) to copy the elements from.
   * @param alloc Allocator to use for all memory allocations of this container.
   * @return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>
   */
  template<class t_input_iterator, vector_helper::enable_for_input_iter<t_input_iterator, value_type> = nullptr>
  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(
    t_input_iterator first, t_input_iterator last, allocator_type const &alloc);

  /**
   * @brief Builds a vector from a range.
   * Create a vector consisting of copies of the elements from [first,last).
   * If the iterators are forward, bidirectional, or random-access, then this will call the elements' copy constructor N
   * times (where N is distance(first,last)) and do no memory reallocation. But if only input iterators are used, then
   * this will do at most 2N calls to the copy constructor, and logN memory reallocations.
   *
   * @tparam t_forward_iterator Satisfies LegacyForwardIterator.
   * @param first The range [first, last) to copy the elements from.
   * @param last The range [first, last) to copy the elements from.
   */
  template<class t_forward_iterator, vector_helper::enable_for_forward_iter<t_forward_iterator, value_type> = nullptr>
  vector(t_forward_iterator first, t_forward_iterator last);

  /**
   * @brief Builds a vector from a range.
   * Create a vector consisting of copies of the elements from [first,last).
   * If the iterators are forward, bidirectional, or random-access, then this will call the elements' copy constructor N
   * times (where N is distance(first,last)) and do no memory reallocation. But if only input iterators are used, then
   * this will do at most 2N calls to the copy constructor, and logN memory reallocations.
   *
   * @tparam t_forward_iterator Satisfies LegacyForwardIterator.
   * @param first The range [first, last) to copy the elements from.
   * @param last The range [first, last) to copy the elements from.
   * @return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>
   */
  template<class t_forward_iterator, vector_helper::enable_for_forward_iter<t_forward_iterator, value_type> = nullptr>
  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(t_forward_iterator first,
                                                                                          t_forward_iterator last);

  /**
   * @brief Builds a vector from a range.
   * Create a vector consisting of copies of the elements from [first,last).
   * If the iterators are forward, bidirectional, or random-access, then this will call the elements' copy constructor N
   * times (where N is distance(first,last)) and do no memory reallocation. But if only input iterators are used, then
   * this will do at most 2N calls to the copy constructor, and logN memory reallocations.
   *
   * @tparam t_forward_iterator Satisfies LegacyForwardIterator.
   * @param first The range [first, last) to copy the elements from.
   * @param last The range [first, last) to copy the elements from.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  template<class t_forward_iterator, vector_helper::enable_for_forward_iter<t_forward_iterator, value_type> = nullptr>
  vector(t_forward_iterator first, t_forward_iterator last, allocator_type const &alloc);

  /**
   * @brief Builds a vector from a range.
   * Create a vector consisting of copies of the elements from [first,last).
   * If the iterators are forward, bidirectional, or random-access, then this will call the elements' copy constructor N
   * times (where N is distance(first,last)) and do no memory reallocation. But if only input iterators are used, then
   * this will do at most 2N calls to the copy constructor, and logN memory reallocations.
   *
   * @tparam t_forward_iterator Satisfies LegacyForwardIterator.
   * @param first The range [first, last) to copy the elements from.
   * @param last The range [first, last) to copy the elements from.
   * @param alloc Allocator to use for all memory allocations of this container.
   * @return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>
   */
  template<class t_forward_iterator, vector_helper::enable_for_forward_iter<t_forward_iterator, value_type> = nullptr>
  static ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> make_vector(
    t_forward_iterator first, t_forward_iterator last, allocator_type const &alloc);

  /**
   * @brief Copy constructor. Constructs the container with the copy of the contents of other.
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   */
  vector(vector const &other);

  /**
   * @brief Constructs the container with the copy of the contents of other, using alloc as the allocator.
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  vector(vector const &other, ::portable_stl::type_identity_t<allocator_type> const &alloc);

  /**
   * @brief Move constructor. Constructs the container with the contents of other using move semantics. Allocator is
   * obtained by move-construction from the allocator belonging to other. After the move, other is guaranteed to be
   * empty().
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   */
  vector(vector &&other) noexcept;

  /**
   * @brief  Allocator-extended move constructor. Using alloc as the allocator for the new container, moving the
   * contents from other; if alloc != other.get_allocator(), this results in an element-wise move. (In that case, other
   * is not guaranteed to be empty after the move.)
   *
   * @param other Another container to be used as source to initialize the elements of the container with.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  vector(vector &&other, ::portable_stl::type_identity_t<allocator_type> const &alloc) noexcept(
    ::portable_stl::noexcept_move_assign_container<allocator_type>{}());

  /**
   * @brief Builds a vector from an initializer list.
   * Create a vector consisting of copies of the elements in the initializer_list init_list.
   * This will call the element type's copy constructor N times (where N is init_list.size()) and do no memory
   * reallocation.
   *
   * @param init_list An initializer_list.
   */
  vector(std::initializer_list<value_type> init_list);

  /**
   * @brief  Builds a vector from an initializer list.
   * Create a vector consisting of copies of the elements in the initializer_list init_list.
   * This will call the element type's copy constructor N times (where N is init_list.size()) and do no memory
   * reallocation.
   *
   * @param init_list An initializer_list.
   * @param alloc Allocator to use for all memory allocations of this container.
   */
  vector(std::initializer_list<value_type> init_list, allocator_type const &alloc);

  /**
   * A destructor. Destructs the vector. The destructors of the elements are called and the used storage is
   * deallocated. Note, that if the elements are pointers, the pointed-to objects are not destroyed.
   */
  ~vector() noexcept {
    M_destroy_vector (*this)();
  }

  /**
   * @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
   *
   * @param other Another container to use as data source.
   * @return vector&
   */
  vector &operator=(vector const &other);

  /**
   * @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in
   * other is moved from other into this container). other is in a valid but unspecified state afterwards.
   *
   * @param other Another container to use as data source.
   * @return vector&
   */
  vector &operator=(vector &&other) noexcept(::portable_stl::noexcept_move_assign_container<allocator_type>{}());

  /**
   * @brief Replaces the contents with those identified by initializer list init_list.
   *
   * @param init_list Initializer list to use as data source.
   * @return vector&
   */
  vector &operator=(std::initializer_list<value_type> init_list) {
    assign(init_list.begin(), init_list.end());
    return *this;
  }

  /**
   * @brief Replaces the contents with copies of those in the range [first, last). The behavior is undefined if either
   * argument is an iterator into *this. Basic guarantee: if an exception is thrown, the container is in a valid state
   * (maybe empty).
   * @tparam t_input_iterator Satisfies LegacyInputIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @return true if OK,
   * @return false otherwise.
   */
  template<class t_input_iterator, vector_helper::enable_for_input_iter<t_input_iterator, value_type> = nullptr>
  bool assign(t_input_iterator first, t_input_iterator last);

  /**
   * @brief Replaces the contents with copies of those in the range [first, last). The behavior is undefined if either
   * argument is an iterator into *this. Basic guarantee: if an exception is thrown, the container is in a valid state
   * (maybe empty).
   * @tparam t_forward_iterator Satisfies LegacyForwardIterator.
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @return true if OK,
   * @return false otherwise.
   */
  template<class t_forward_iterator, vector_helper::enable_for_forward_iter<t_forward_iterator, value_type> = nullptr>
  bool assign(t_forward_iterator first, t_forward_iterator last);

  /**
   * @brief Replaces the contents with count copies of value value.
   * Basic guarantee: if an exception is thrown, the container is in a valid state (maybe empty).
   * @param num The new size of the container.
   * @param value The value to initialize elements of the container with.
   * @return true if OK,
   * @return false otherwise.
   */
  bool assign(size_type num, const_reference value);

  /**
   * @brief Replaces the contents with the elements from the initializer list init_list.
   * Basic guarantee: if an exception is thrown, the container is in a valid state (maybe empty).
   * @param init_list Initializer list to copy the values from.
   * @return true if OK,
   * @return false otherwise.
   */
  bool assign(std::initializer_list<value_type> init_list) {
    return assign(init_list.begin(), init_list.end());
  }

  /**
   * @brief Returns the allocator associated with the container.
   * @return The associated allocator.
   */
  constexpr t_allocator get_allocator() const noexcept {
    return M_alloc();
  }

  // [iterators]

  /**
   * @brief Returns a read/write iterator that points to the first element in the vector. Iteration is done in ordinary
   * element order.
   *
   * @return Iterator to the first element.
   */
  iterator begin() noexcept {
    return iterator(m_begin);
  }

  /**
   * @brief Returns a read-only (constant) iterator that points to the first element in the vector. Iteration is done in
   * ordinary element order.
   *
   * @return Iterator to the first element.
   */
  const_iterator begin() const noexcept {
    return const_iterator(m_begin);
  }

  /**
   * @brief Returns a read-only (constant) iterator that points to the first element in the vector. Iteration is done in
   * ordinary element order.
   *
   * @return Iterator to the first element.
   */
  const_iterator cbegin() const noexcept {
    return const_iterator(m_begin);
  }

  /**
   * @brief Returns a read/write iterator that points one past the last element in the vector. Iteration is done in
   * ordinary element order. This element acts as a placeholder; attempting to access it results in undefined behavior.
   *
   * @return Iterator to the element following the last element.
   */
  iterator end() noexcept {
    return iterator(m_end);
  }

  /**
   * @brief Returns a read-only (constant) iterator that points one past the last element in the vector. Iteration is
   * done in ordinary element order. This element acts as a placeholder; attempting to access it results in undefined
   * behavior.
   *
   * @return Iterator to the element following the last element.
   */
  const_iterator end() const noexcept {
    return const_iterator(m_end);
  }

  /**
   * @brief Returns a read-only (constant) iterator that points one past the last element in the vector. Iteration is
   * done in ordinary element order. This element acts as a placeholder; attempting to access it results in undefined
   * behavior.
   *
   * @return Iterator to the element following the last element.
   */
  const_iterator cend() const noexcept {
    return const_iterator(m_end);
  }

  /**
   * @brief Returns a read/write reverse iterator to the first element of the reversed vector. It corresponds to the
   * last element of the non-reversed vector. If the vector is empty, the returned iterator is equal to rend().
   *
   * @return Reverse iterator to the first element.
   */
  reverse_iterator rbegin() noexcept {
    return reverse_iterator(end());
  }

  /**
   * @brief Returns a read-only (constant) reverse iterator to the first element of the reversed vector. It corresponds
   * to the last element of the non-reversed vector. If the vector is empty, the returned iterator is equal to rend().
   *
   * @return Reverse iterator to the first element.
   */
  const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator(end());
  }

  /**
   * @brief Returns a read-only (constant) reverse iterator to the first element of the reversed vector. It corresponds
   * to the last element of the non-reversed vector. If the vector is empty, the returned iterator is equal to rend().
   *
   * @return Reverse iterator to the first element.
   */
  const_reverse_iterator crbegin() const noexcept {
    return const_reverse_iterator(end());
  }

  /**
   * @brief Returns a read/write reverse iterator to the element following the last element of the reversed vector. It
   * corresponds to the element preceding the first element of the non-reversed vector. This element acts as a
   * placeholder, attempting to access it results in undefined behavior.
   *
   * @return Reverse iterator to the element following the last element.
   */
  reverse_iterator rend() noexcept {
    return reverse_iterator(begin());
  }

  /**
   * @brief Returns a read-only (constant) reverse iterator to the element following the last element of the reversed
   * vector. It corresponds to the element preceding the first element of the non-reversed vector. This element acts as
   * a placeholder, attempting to access it results in undefined behavior.
   *
   * @return Reverse iterator to the element following the last element.
   */
  const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator(begin());
  }

  /**
   * @brief Returns a read-only (constant) reverse iterator to the element following the last element of the reversed
   * vector. It corresponds to the element preceding the first element of the non-reversed vector. This element acts as
   * a placeholder, attempting to access it results in undefined behavior.
   *
   * @return Reverse iterator to the element following the last element.
   */
  const_reverse_iterator crend() const noexcept {
    return const_reverse_iterator(begin());
  }

  // [24.3.12.3, capacity]

  /**
   * @brief Checks if the container has no elements, i.e. whether begin() == end().
   *
   * @return true if the container is empty,
   * @return false otherwise.
   */
  bool empty() const noexcept {
    return m_begin == m_end;
  }

  /**
   * @brief Returns the number of elements in the container, i.e. distance(begin(), end()).
   *
   * @return The number of elements in the container.
   */
  constexpr size_type size() const noexcept {
    return static_cast<size_type>(m_end - m_begin);
  }

  /**
   * @brief Returns the maximum number of elements the container is able to hold due to system or library implementation
   * limitations, i.e. distance(begin(), end()) for the largest container.
   * This value typically reflects the theoretical limit on the size of the container, at most
   * numeric_limits<difference_type>::max(). At runtime, the size of the container may be limited to a value smaller
   * than max_size() by the amount of RAM available.
   *
   * @return Maximum number of elements.
   */
  constexpr size_type max_size() const noexcept;

  /**
   * @brief Returns the maximum number of elements the container is able to hold due to system or library implementation
   * limitations, i.e. distance(begin(), end()) for the largest container.
   *
   * @param vec Given vector.
   * @return Maximum number of elements.
   */
  constexpr static size_type max_size(vector const &vec) noexcept;

  /**
   * @brief Increase the capacity of the vector (the total number of elements that the vector can hold without requiring
   * reallocation) to a value that's greater or equal to new_cap. If new_cap is greater than the current capacity(), new
   * storage is allocated, otherwise the function does nothing. reserve() does not change the size of the vector.
   * Strong guarantee: If an exception is thrown, this function has no effect.
   *
   * @param new_cap New capacity of the vector, in number of elements.
   * @return portable_stl_error::length_error if new_cap > max_size(),
   * @return portable_stl_error::allocate_error if any exception thrown by t_allocator::allocate(),
   * @return void, otherwise.
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> reserve(size_type new_cap);

  /**
   * @brief Returns the number of elements that the container has currently allocated space for.
   *
   * @return Capacity of the currently allocated storage.
   */
  size_type capacity() const noexcept {
    return static_cast<size_type>(M_end_cap() - m_begin);
  }

  /**
   * @brief Requests the removal of unused capacity.
   *
   * @return true if OK,
   * @return false if any exception thrown by t_allocator::allocate().
   */
  bool shrink_to_fit();

  // [element access]

  /**
   * @brief Returns a reference to the element at specified location pos, with bounds checking.
   *
   * @param pos Position of the element to return.
   * @return Reference wrapper to the requested element,
   * @return portable_stl_error::length_error if pos >= size().
   */
  ::portable_stl::expected<reference_wrap, ::portable_stl::portable_stl_error> at(size_type pos) noexcept;

  /**
   * @brief Returns a reference to the element at specified location pos, with bounds checking.
   *
   * @param pos Position of the element to return.
   * @return Const reference wrapper to the requested element,
   * @return portable_stl_error::length_error if pos >= size().
   */
  portable_stl::expected<const_reference_wrap, ::portable_stl::portable_stl_error> at(size_type pos) const noexcept;

  /**
   * @brief Returns a reference to the element at specified location pos. No bounds checking is performed.
   * UB: Accessing a nonexistent element through this operator is undefined behavior.
   *
   * @param pos Position of the element to return.
   * @return Reference to the requested element.
   */
  reference operator[](size_type pos) noexcept;

  /**
   * @brief Returns a reference to the element at specified location pos. No bounds checking is performed.
   * UB: Accessing a nonexistent element through this operator is undefined behavior.
   *
   * @param pos Position of the element to return.
   * @return Reference to the requested element.
   */
  const_reference operator[](size_type pos) const noexcept;

  /**
   * @brief Returns a read/write reference to the first element in the container.
   * UB: Calling front on an empty container causes undefined behavior.
   *
   * @return Reference to the first element.
   */
  reference front() {
    return *m_begin;
  }

  /**
   * @brief Returns a read-only (constant) reference to the first element in the container.
   * UB: Calling front on an empty container causes undefined behavior.
   *
   * @return Const reference to the first element.
   */
  const_reference front() const {
    return *m_begin;
  }

  /**
   * @brief Returns a read/write reference to the data at the last element of the vector.
   * UB: Calling front on an empty container causes undefined behavior.
   *
   * @return Reference to the last element.
   */
  reference back() noexcept {
    return *(m_end - 1);
  }

  /**
   * @brief Returns a read-only (constant) reference to the data at the last element of the vector.
   * UB: Calling front on an empty container causes undefined behavior.
   *
   * @return Const reference to the last element.
   */
  const_reference back() const noexcept {
    return *(m_end - 1);
  }

  // [24.3.12.4, data access]

  /**
   * @brief Returns a pointer to the underlying array serving as element storage.
   * The pointer is such that range [data(), data() + size()) is always a valid range, even if the container is empty
   * (data() is not dereferenceable in that case). For a non-empty vector, data() == &front().
   *
   * @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to
   * the address of the first element.
   */
  value_type *data() noexcept {
    return ::portable_stl::to_address(m_begin);
  }

  /**
   * @brief Returns a pointer to the underlying array serving as element storage.
   * The pointer is such that range [data(), data() + size()) is always a valid range, even if the container is empty
   * (data() is not dereferenceable in that case). For a non-empty vector, data() == &front().
   *
   * @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to
   * the address of the first element.
   */
  value_type const *data() const noexcept {
    return ::portable_stl::to_address(m_begin);
  }

  // [24.3.12.5, modifiers]

  /**
   * @brief Erases all elements from the container. After this call, size() returns zero.
   * Leaves the capacity() of the vector unchanged.
   */
  void clear() noexcept {
    M_clear();
  }

  /**
   * @brief Erases the specified elements from the container. Removes the element at pos.
   *
   * @param pos Iterator to the element to remove.
   * @return Iterator following the last removed element. If pos refers to the last element, then the end() iterator is
   * returned.
   */
  iterator erase(const_iterator pos);

  /**
   * @brief Erases the specified elements from the container. Removes the elements in the range [first, last).
   *
   * @param first Range of elements to remove.
   * @param last Range of elements to remove.
   * @return Iterator following the last removed element. If last == end() prior to removal, then the updated end()
   * iterator is returned. If [first, last) is an empty range, then last is returned.
   */
  iterator erase(const_iterator first, const_iterator last);

  /**
   * @brief Resizes the container to contain count elements, does nothing if new_size == size().
   * If the current size is greater than new_size, the container is reduced to its first new_size elements. If the
   * current size is less than new_size, additional default-inserted elements are appended.
   * Strong guarantee: If an exception is thrown, this function has no effect.
   *
   * @param new_size New size of the container.
   * @return portable_stl_error::length_error if new_cap > max_size(),
   * @return portable_stl_error::allocate_error if any exception thrown by t_allocator::allocate(),
   * @return void, otherwise.
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> resize(size_type new_size);

  /**
   * @brief Resizes the container to contain count elements, does nothing if new_size == size().
   * If the current size is greater than new_size, the container is reduced to its first new_size elements. If the
   * current size is less than new_size, additional copies of value are appended.
   * Strong guarantee: If an exception is thrown, this function has no effect.
   *
   * @param new_size New size of the container.
   * @param value The value to initialize the new elements with.
   * @return portable_stl_error::length_error if new_cap > max_size(),
   * @return portable_stl_error::allocate_error if any exception thrown by t_allocator::allocate(),
   * @return void, otherwise.
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> resize(size_type new_size, const_reference value);

  /**
   * @brief Appends a new element to the end of the container. The element is constructed through
   * allocator_traits::construct, which typically uses placement-new to construct the element in-place at
   * the location provided by the container. The arguments args... are forwarded to the constructor as
   * forward<Args>(args)....
   * Strong guarantee: If an exception is thrown, this function has no effect.
   *
   * @tparam t_args
   * @param args Arguments to forward to the constructor of the element.
   * @return A reference wrapper to the inserted element,
   * @return portable_stl_error::length_error if new_cap > max_size(),
   * @return portable_stl_error::allocate_error if any exception thrown by t_allocator::allocate().
   */
  template<class... t_args>
  ::portable_stl::expected<reference_wrap, ::portable_stl::portable_stl_error> emplace_back(t_args &&...args);

  /**
   * @brief Appends the given element value to the end of the container.
   * The new element is initialized as a copy of value.
   *
   * @param value The value of the element to append
   * @return portable_stl_error::length_error if new_cap > max_size(),
   * @return portable_stl_error::allocate_error if any exception thrown by t_allocator::allocate(),
   * @return void, otherwise.
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> push_back(const_reference value);

  /**
   * @brief Appends the given element value to the end of the container.
   * value is moved into the new element.
   *
   * @param value The value of the element to append
   * @return portable_stl_error::length_error if new_cap > max_size(),
   * @return portable_stl_error::allocate_error if any exception thrown by t_allocator::allocate(),
   * @return void, otherwise.
   */
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> push_back(value_type &&value);

  /**
   * @brief Removes the last element of the container.
   * UB: Calling pop_back on an empty container results in undefined behavior.
   */
  void pop_back() noexcept {
    M_destruct_at_end(m_end - 1);
  }

  /**
   * @brief Inserts a new element into the container directly before pos.
   * The element is constructed through allocator_traits::construct, which typically uses placement-new to construct the
   * element in-place at a location provided by the container. However, if the required location has been occupied by an
   * existing element, the inserted element is constructed at another location at first, and then move assigned into the
   * required location.
   * The arguments args... are forwarded to the constructor as forward<Args>(args).... args... may directly or
   * indirectly refer to a value in the container.
   *
   * @param position A const_iterator into the %vector.
   * @param args Arguments.
   * @return An iterator that points to the inserted data,
   * @return portable_stl_error::length_error if new_cap > max_size(),
   * @return portable_stl_error::allocate_error if any exception thrown by t_allocator::allocate().
   */
  template<class... t_args>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> emplace(const_iterator position,
                                                                                 t_args &&...args);

  /**
   *  @brief  Inserts given value into %vector before specified iterator.
   *  @param  position  A const_iterator into the %vector.
   *  @param  value  Data to be inserted.
   *  @return  An iterator that points to the inserted data.
   *
   *  This function will insert a copy of the given value before
   *  the specified location.  Note that this kind of operation
   *  could be expensive for a %vector and if it is frequently
   *  used the user should consider using ::list.
   */

  /**
   * @brief Inserts elements at the specified location in the container.
   * Inserts a copy of value before position.
   *
   * @param position Iterator before which the content will be inserted (position may be the end() iterator).
   * @param value Element value to insert.
   * @return Iterator pointing to the inserted value,
   * @return portable_stl_error::length_error if new_cap > max_size(),
   * @return portable_stl_error::allocate_error if any exception thrown by t_allocator::allocate().
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(const_iterator  position,
                                                                                const_reference value);

  /**
   * @brief Inserts elements at the specified location in the container.
   * Inserts value before position, possibly using move semantics.
   *
   * @param position Iterator before which the content will be inserted (position may be the end() iterator).
   * @param value Element value to insert.
   * @return Iterator pointing to the inserted value,
   * @return portable_stl_error::length_error if new_cap > max_size(),
   * @return portable_stl_error::allocate_error if any exception thrown by t_allocator::allocate().
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(const_iterator position,
                                                                                value_type   &&value);

  /**
   * @brief Inserts elements at the specified location in the container.
   * Inserts num copies of the value before position.
   *
   * @param position Iterator before which the content will be inserted (position may be the end() iterator).
   * @param num Number of elements to insert.
   * @param value Element value to insert.
   * @return Iterator pointing to the first element inserted, or position if num == 0,
   * @return portable_stl_error::length_error if new_cap > max_size(),
   * @return portable_stl_error::allocate_error if any exception thrown by t_allocator::allocate().
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(
    const_iterator position, size_type num, const_reference value);

  /**
   * @brief Inserts elements at the specified location in the container.
   * Inserts elements from range [first, last) before position.
   *
   * @tparam t_input_iterator Satisfies LegacyInputIterator.
   * @param position Iterator before which the content will be inserted (position may be the end() iterator).
   * @param first The range of elements to insert, cannot be iterators into container for which insert is called.
   * @param last The range of elements to insert, cannot be iterators into container for which insert is called.
   * @return Iterator pointing to the first element inserted, or position if first == last,
   * @return portable_stl_error::length_error if new_cap > max_size(),
   * @return portable_stl_error::allocate_error if any exception thrown by t_allocator::allocate().
   */
  template<class t_input_iterator, vector_helper::enable_for_input_iter<t_input_iterator, value_type> = nullptr>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(
    const_iterator position, t_input_iterator first, t_input_iterator last);

  /**
   * @brief Inserts elements at the specified location in the container.
   * Inserts elements from range [first, last) before position.
   *
   * @tparam t_forward_iterator Satisfies LegacyForwardIterator.
   * @param position Iterator before which the content will be inserted (position may be the end() iterator).
   * @param first The range of elements to insert, cannot be iterators into container for which insert is called.
   * @param last The range of elements to insert, cannot be iterators into container for which insert is called.
   * @return Iterator pointing to the first element inserted, or position if first == last,
   * @return portable_stl_error::length_error if new_cap > max_size(),
   * @return portable_stl_error::allocate_error if any exception thrown by t_allocator::allocate().
   */
  template<class t_forward_iterator, vector_helper::enable_for_forward_iter<t_forward_iterator, value_type> = nullptr>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(
    const_iterator position, t_forward_iterator first, t_forward_iterator last);

  /**
   * @brief Inserts elements at the specified location in the container.
   * Inserts elements from initializer list init_list before position.
   *
   * @param position Iterator before which the content will be inserted (position may be the end() iterator).
   * @param init_list initializer_list to insert the values from.
   * @return Iterator pointing to the first element inserted, or position if init_list is empty,
   * @return portable_stl_error::length_error if new_cap > max_size(),
   * @return portable_stl_error::allocate_error if any exception thrown by t_allocator::allocate().
   */
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> insert(
    const_iterator position, initializer_list<value_type> init_list) {
    return insert(position, init_list.begin(), init_list.end());
  }

  /**
   * @brief Exchanges the contents and capacity of the container with those of other. Does not invoke any move, copy, or
   * swap operations on individual elements. All iterators and references remain valid. The end() iterator is
   * invalidated.
   */
  void swap(vector &) noexcept(typename t_allocator_traits::propagate_on_container_swap{}() ||
                               typename t_allocator_traits::is_always_equal{}());

private:
  class M_destroy_vector final {
  public:
    constexpr M_destroy_vector(vector &vec) : m_vector(vec) {
    }

    void operator()() {
      if (m_vector.m_begin != nullptr) {
        m_vector.M_clear();
        // m_vector.__annotate_delete();
        t_allocator_traits::deallocate(m_vector.M_alloc(), m_vector.m_begin, m_vector.capacity());

        m_vector.m_begin     = nullptr;
        m_vector.m_end       = nullptr;
        m_vector.M_end_cap() = nullptr;
      }
    }

  private:
    vector &m_vector;
  };

  void M_clear() noexcept {
    M_base_destruct_at_end(m_begin);
  }

  void M_base_destruct_at_end(pointer new_last_ptr) noexcept {
    pointer soon_to_be_end_ptr{m_end};
    while (new_last_ptr != soon_to_be_end_ptr) {
      t_allocator_traits::destroy(M_alloc(), ::portable_stl::to_address(--soon_to_be_end_ptr));
    }
    m_end = new_last_ptr;
  }

  void M_copy_assign_alloc(vector const &other, ::portable_stl::true_type) {
    if (M_alloc() != other.M_alloc()) {
      M_clear();
      t_allocator_traits::deallocate(M_alloc(), m_begin, capacity());
      m_begin     = nullptr;
      m_end       = nullptr;
      M_end_cap() = nullptr;
    }
    M_alloc() = other.M_alloc();
  }

  void M_copy_assign_alloc(vector const &, ::portable_stl::false_type) {
  }

  void M_copy_assign_alloc(vector const &other) {
    M_copy_assign_alloc(other, typename t_allocator_traits::propagate_on_container_copy_assignment{});
  }

  void M_move_assign_alloc(vector &other) noexcept(
    !typename t_allocator_traits::propagate_on_container_move_assignment{}()
    || ::portable_stl::is_nothrow_move_assignable<allocator_type>{}()) {
    M_move_assign_alloc(other, typename t_allocator_traits::propagate_on_container_move_assignment{});
  }

  void M_move_assign_alloc(vector &other, ::portable_stl::true_type) noexcept(
    ::portable_stl::is_nothrow_move_assignable<allocator_type>{}()) {
    M_alloc() = ::portable_stl::move(other.M_alloc());
  }

  void M_move_assign_alloc(vector &, ::portable_stl::false_type) noexcept {
  }

  /**
   * @brief Allocate space for num objects.
   * @param num
   */
  pointer M_vallocate(size_type num) {
    m_begin = ::portable_stl::allocate_noexcept(M_alloc(), num); // exception free wrapper
    if (m_begin) {
      m_end       = m_begin;
      M_end_cap() = m_begin + num;
    }
    return m_begin;
  }

  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> M_append(size_type num);
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> M_append(size_type num, const_reference value);
  iterator                                                           M_make_iter(pointer ptr) noexcept {
    return iterator(ptr);
  }
  const_iterator M_make_iter(const_pointer ptr) const noexcept {
    return const_iterator(ptr);
  }
  void    M_swap_out_circular_buffer(::portable_stl::split_buffer<value_type, allocator_type &> &buf);
  pointer M_swap_out_circular_buffer(::portable_stl::split_buffer<value_type, allocator_type &> &value, pointer ptr);
  void    M_move_range(pointer from_start, pointer from_end, pointer dest);
  void    M_move_assign(vector &other, ::portable_stl::true_type) noexcept(
    ::portable_stl::is_nothrow_move_assignable<allocator_type>{}());
  void M_move_assign(vector &other,
                     ::portable_stl::false_type) noexcept(typename t_allocator_traits::is_always_equal{}());
  void M_destruct_at_end(pointer new_last_ptr) noexcept {
    M_base_destruct_at_end(new_last_ptr);
  }

  template<class... t_args> inline pointer M_emplace_back_slow_path(t_args &&...args);
  template<class t_other_type>
  inline ::portable_stl::expected<pointer, ::portable_stl::portable_stl_error> M_push_back_slow_path(
    t_other_type &&other);

  void        M_vdeallocate() noexcept;
  size_type   M_recommend(size_type new_size) const noexcept;
  void        M_construct_at_end(size_type num);
  void        M_construct_at_end(size_type num, const_reference value);
  static void M_construct_at_end(vector &vec, size_type num) noexcept(noexcept(t_type()));
  static void M_construct_at_end(vector &vec, size_type num, const_reference value) noexcept(noexcept(t_type(value)));

  template<class t_input_iterator, class t_sentinel>
  void M_construct_at_end(t_input_iterator first, t_sentinel last, size_type num);

  template<class t_input_iterator, class t_sentinel>
  void M_init_with_size(t_input_iterator first, t_sentinel last, size_type num);

  template<class t_input_iterator, class t_sentinel>
  ::portable_stl::expected<void, ::portable_stl::portable_stl_error> M_init_with_sentinel(t_input_iterator first,
                                                                                          t_sentinel       last);
  template<class t_input_iterator, class t_sentinel>
  static ::portable_stl::expected<void, ::portable_stl::portable_stl_error> M_init_with_size(
    vector &vec, t_input_iterator first, t_sentinel last, size_type num);

  template<class t_input_iterator, class t_sentinel>
  static ::portable_stl::expected<void, ::portable_stl::portable_stl_error> M_init_with_sentinel(
    vector &vec, t_input_iterator first, t_sentinel last);

  /**
   * @brief Replaces the contents with copies of those in the range [first, last)
   *
   * @tparam t_iterator
   * @tparam t_sentinel
   * @param first The range to copy the elements from.
   * @param last The range to copy the elements from.
   * @return true if OK,
   * @return false otherwise.
   */
  template<class t_iterator, class t_sentinel> bool M_assign_with_sentinel(t_iterator first, t_sentinel last);

  template<class t_forward_iterator, class t_sentinel>
  bool M_assign_with_size(t_forward_iterator first, t_sentinel last, difference_type num);

  template<class t_input_iterator, class t_sentinel>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> M_insert_with_sentinel(
    const_iterator position, t_input_iterator first, t_sentinel last);

  template<class t_iterator, class t_sentinel>
  ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error> M_insert_with_size(
    const_iterator position, t_iterator first, t_sentinel last, difference_type num);

  /**
   * @brief Helper class to recover m_vec.m_end = m_pos in case of exception.
   */
  class M_ConstructTransaction final {
  public:
    constexpr explicit M_ConstructTransaction(vector &vec, size_type num)
        : m_vec(vec), m_pos(vec.m_end), m_new_end(vec.m_end + num) {
    }

    ~M_ConstructTransaction() {
      m_vec.m_end = m_pos;
    }

    vector             &m_vec;
    pointer             m_pos;
    const_pointer const m_new_end;

    M_ConstructTransaction(M_ConstructTransaction const &)            = delete;
    M_ConstructTransaction &operator=(M_ConstructTransaction const &) = delete;
  };

  template<class... t_args> void M_construct_one_at_end(t_args &&...args) {
    M_ConstructTransaction trans(*this, 1);
    t_allocator_traits::construct(
      M_alloc(), ::portable_stl::to_address(trans.m_pos), ::portable_stl::forward<t_args>(args)...);
    ++trans.m_pos;
  }
};

/**
 * @brief Default constructs num objects starting at 'end'.
 * @param num Number of objects.
 */
template<class t_type, class t_allocator> void vector<t_type, t_allocator>::M_construct_at_end(size_type num) {
  M_ConstructTransaction trans(*this, num);
  const_pointer          new_end = trans.m_new_end;
  for (pointer pos{trans.m_pos}; pos != new_end; trans.m_pos = ++pos) {
    t_allocator_traits::construct(M_alloc(), ::portable_stl::to_address(pos));
  }
}

template<class t_type, class t_allocator> vector<t_type, t_allocator>::vector(size_type num) {
  auto guard = ::portable_stl::make_exception_guard(M_destroy_vector(*this));
  if (num > 0) {
    bool const has_length_error{num > max_size()};
    ::portable_stl::throw_on_true<::portable_stl::length_error<>>(has_length_error);
    if (has_length_error) {
      return;
    }
    auto const ptr = M_vallocate(num);
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(nullptr == ptr);
    if (nullptr != ptr) {
      M_construct_at_end(num);
    } else {
      return;
    }
  }
  guard.commit();
}

// static
template<class t_type, class t_allocator>
void vector<t_type, t_allocator>::M_construct_at_end(vector &vec, size_type num) noexcept(noexcept(t_type())) {
  M_ConstructTransaction trans(vec, num);
  const_pointer          new_end{trans.m_new_end};
  for (pointer pos{trans.m_pos}; pos != new_end; trans.m_pos = ++pos) {
    ::portable_stl::construct_at(::portable_stl::to_address(pos));
  }
}

template<class t_type, class t_allocator>
::portable_stl::expected<vector<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::make_vector(size_type num) noexcept(noexcept(t_type())) {
  vector vec{};
  auto   guard = ::portable_stl::make_exception_guard(M_destroy_vector(vec));
  if (num > 0) {
    if (num > max_size(vec)) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    auto result = vec.M_vallocate(num);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
    M_construct_at_end(vec, num);
    // if construction throw, guard clean vector
    guard.commit();
  }
  return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>(::portable_stl::move(vec));
}

template<class t_type, class t_allocator>
vector<t_type, t_allocator>::vector(size_type num, allocator_type const &alloc) : m_end_cap(nullptr, alloc) {
  auto guard = ::portable_stl::make_exception_guard(M_destroy_vector(*this));
  if (num > 0) {
    bool const has_length_error{num > max_size()};
    ::portable_stl::throw_on_true<::portable_stl::length_error<>>(has_length_error);
    if (has_length_error) {
      return;
    }
    auto const ptr = M_vallocate(num);
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(nullptr == ptr);
    if (nullptr != ptr) {
      M_construct_at_end(num);
    } else {
      return;
    }
  }
  guard.commit();
}

// static
template<class t_type, class t_allocator>
::portable_stl::expected<vector<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::make_vector(size_type num, allocator_type const &alloc) noexcept(noexcept(t_type())) {
  vector vec{alloc};
  auto   guard = ::portable_stl::make_exception_guard(M_destroy_vector(vec));
  if (num > 0) {
    if (num > max_size(vec)) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    auto result = vec.M_vallocate(num);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
    M_construct_at_end(vec, num);
    // if construction throw, guard clean vector
    guard.commit();
  }
  return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>(::portable_stl::move(vec));
}

/**
 * @brief Copy constructs num objects starting at 'end' from value.
 * @param num
 * @param value
 */
template<class t_type, class t_allocator>
inline void vector<t_type, t_allocator>::M_construct_at_end(size_type num, const_reference value) {
  M_ConstructTransaction trans(*this, num);
  const_pointer          new_end{trans.m_new_end};
  for (pointer pos{trans.m_pos}; pos != new_end; trans.m_pos = ++pos) {
    t_allocator_traits::construct(M_alloc(), ::portable_stl::to_address(pos), value);
  }
}

template<class t_type, class t_allocator> vector<t_type, t_allocator>::vector(size_type num, value_type const &value) {
  auto guard = ::portable_stl::make_exception_guard(M_destroy_vector(*this));
  if (num > 0) {
    bool const has_length_error{num > max_size()};
    ::portable_stl::throw_on_true<::portable_stl::length_error<>>(has_length_error);
    if (has_length_error) {
      return;
    }
    auto const ptr(M_vallocate(num));
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(nullptr == ptr);
    if (nullptr != ptr) {
      M_construct_at_end(num, value);
    } else {
      return;
    }
  }
  guard.commit();
}

// static
template<class t_type, class t_allocator>
void vector<t_type, t_allocator>::M_construct_at_end(vector &vec, size_type num, const_reference value) noexcept(
  noexcept(t_type(value))) {
  M_ConstructTransaction trans(vec, num);
  const_pointer          new_end{trans.m_new_end};
  for (pointer pos{trans.m_pos}; pos != new_end; trans.m_pos = ++pos) {
    ::portable_stl::construct_at(::portable_stl::to_address(pos), value);
  }
}

template<class t_type, class t_allocator>
::portable_stl::expected<vector<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::make_vector(size_type num, value_type const &value) noexcept(noexcept(t_type(value))) {
  vector vec{};
  auto   guard = ::portable_stl::make_exception_guard(M_destroy_vector(vec));
  if (num > 0) {
    if (num > max_size(vec)) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    auto result = vec.M_vallocate(num);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
    M_construct_at_end(vec, num, value);
    // if construction throw, guard clean vector
    guard.commit();
  }
  return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>(::portable_stl::move(vec));
}

template<class t_type, class t_allocator>
template<class>
vector<t_type, t_allocator>::vector(size_type num, value_type const &value, allocator_type const &alloc)
    : m_end_cap(nullptr, alloc) {
  auto guard = ::portable_stl::make_exception_guard(M_destroy_vector(*this));
  if (num > 0) {
    bool const has_length_error{num > max_size()};
    ::portable_stl::throw_on_true<::portable_stl::length_error<>>(has_length_error);
    if (has_length_error) {
      return;
    }
    auto const ptr = M_vallocate(num);
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(nullptr == ptr);
    if (nullptr != ptr) {
      M_construct_at_end(num, value);
    } else {
      return;
    }
  }
  guard.commit();
}

// static
template<class t_type, class t_allocator>
template<class>
::portable_stl::expected<vector<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::make_vector(
    size_type num, value_type const &value, allocator_type const &alloc) noexcept(noexcept(t_type(value))) {
  vector vec{alloc};
  auto   guard = ::portable_stl::make_exception_guard(M_destroy_vector(vec));
  if (num > 0) {
    if (num > max_size(vec)) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    auto result = vec.M_vallocate(num);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
    M_construct_at_end(vec, num, value);
    // if construction throw, guard clean vector
    guard.commit();
  }
  return ::portable_stl::expected<vector, ::portable_stl::portable_stl_error>(::portable_stl::move(vec));
}

/**
 * @brief Init vector from pair of iterator and sentinal.
 *
 * @param first
 * @param last
 * @return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>
 */
template<class t_type, class t_allocator>
template<class t_input_iterator, class t_sentinel>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> vector<t_type, t_allocator>::M_init_with_sentinel(
  t_input_iterator first, t_sentinel last) {
  auto guard = ::portable_stl::make_exception_guard(M_destroy_vector(*this));

  for (; first != last; ++first) {
    auto result = emplace_back(*first);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
  }

  guard.commit();
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

template<class t_type, class t_allocator>
template<class t_input_iterator, vector_helper::enable_for_input_iter<t_input_iterator, t_type>>
vector<t_type, t_allocator>::vector(t_input_iterator first, t_input_iterator last) {
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!M_init_with_sentinel(first, last));
}

// static
template<class t_type, class t_allocator>
template<class t_input_iterator, class t_sentinel>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> vector<t_type, t_allocator>::M_init_with_sentinel(
  vector &vec, t_input_iterator first, t_sentinel last) {
  auto guard = ::portable_stl::make_exception_guard(M_destroy_vector(vec));
  for (; first != last; ++first) {
    auto result = vec.emplace_back(*first);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
  }

  guard.commit();
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

// static
template<class t_type, class t_allocator>
template<class t_input_iterator, vector_helper::enable_for_input_iter<t_input_iterator, t_type>>
::portable_stl::expected<vector<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::make_vector(t_input_iterator first, t_input_iterator last) {
  vector vec;
  return M_init_with_sentinel(vec, first, last)
    .and_then([&vec](void) -> ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> {
      return {::portable_stl::in_place_t{}, ::portable_stl::move(vec)};
    });
}

template<class t_type, class t_allocator>
template<class t_input_iterator, vector_helper::enable_for_input_iter<t_input_iterator, t_type>>
vector<t_type, t_allocator>::vector(t_input_iterator first, t_input_iterator last, allocator_type const &alloc)
    : m_end_cap(nullptr, alloc) {
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!M_init_with_sentinel(first, last));
}

// static
template<class t_type, class t_allocator>
template<class t_input_iterator, vector_helper::enable_for_input_iter<t_input_iterator, t_type>>
::portable_stl::expected<vector<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::make_vector(t_input_iterator first, t_input_iterator last, allocator_type const &alloc) {
  vector vec{alloc};
  return M_init_with_sentinel(vec, first, last)
    .and_then([&vec](void) -> ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> {
      return {::portable_stl::in_place_t{}, ::portable_stl::move(vec)};
    });
}

template<class t_type, class t_allocator>
template<class t_input_iterator, class t_sentinel>
void vector<t_type, t_allocator>::M_construct_at_end(t_input_iterator first, t_sentinel last, size_type num) {
  M_ConstructTransaction trans(*this, num);
  trans.m_pos = vector_algo::uninitialized_allocator_copy(M_alloc(), first, last, trans.m_pos);
}

template<class t_type, class t_allocator>
template<class t_input_iterator, class t_sentinel>
void vector<t_type, t_allocator>::M_init_with_size(t_input_iterator first, t_sentinel last, size_type num) {
  if (num > 0) {
    bool const has_length_error{num >= max_size()};
    ::portable_stl::throw_on_true<::portable_stl::length_error<>>(has_length_error);
    if (has_length_error) {
      return;
    }
    auto       guard = ::portable_stl::make_exception_guard(M_destroy_vector(*this));
    auto const ptr   = M_vallocate(num);
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(nullptr == ptr);
    if (nullptr != ptr) {
      M_construct_at_end(first, last, num);
    } else {
      return;
    }
    guard.commit();
  }
}

template<class t_type, class t_allocator>
template<class t_forward_iterator, vector_helper::enable_for_forward_iter<t_forward_iterator, t_type>>
vector<t_type, t_allocator>::vector(t_forward_iterator first, t_forward_iterator last) {
  auto num = static_cast<size_type>(::portable_stl::distance(first, last));
  M_init_with_size(first, last, num);
}

// static
template<class t_type, class t_allocator>
template<class t_input_iterator, class t_sentinel>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> vector<t_type, t_allocator>::M_init_with_size(
  vector &vec, t_input_iterator first, t_sentinel last, size_type num) {
  if (num > 0) {
    auto guard = ::portable_stl::make_exception_guard(M_destroy_vector(vec));

    auto result = vec.M_vallocate(num);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
    vec.M_construct_at_end(first, last, num);
    guard.commit();
  }
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

// static
template<class t_type, class t_allocator>
template<class t_forward_iterator, vector_helper::enable_for_forward_iter<t_forward_iterator, t_type>>
::portable_stl::expected<vector<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::make_vector(t_forward_iterator first, t_forward_iterator last) {
  vector vec;
  auto   num = static_cast<size_type>(::portable_stl::distance(first, last));
  if (num > max_size(vec)) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
      ::portable_stl::portable_stl_error::length_error};
  }
  return M_init_with_size(vec, first, last, num)
    .and_then([&vec](void) -> ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> {
      return {::portable_stl::in_place_t{}, ::portable_stl::move(vec)};
    });
}

template<class t_type, class t_allocator>
template<class t_forward_iterator, vector_helper::enable_for_forward_iter<t_forward_iterator, t_type>>
vector<t_type, t_allocator>::vector(t_forward_iterator first, t_forward_iterator last, allocator_type const &alloc)
    : m_end_cap(nullptr, alloc) {
  auto num = static_cast<size_type>(::portable_stl::distance(first, last));
  M_init_with_size(first, last, num);
}

// static
template<class t_type, class t_allocator>
template<class t_forward_iterator, vector_helper::enable_for_forward_iter<t_forward_iterator, t_type>>
::portable_stl::expected<vector<t_type, t_allocator>, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::make_vector(
    t_forward_iterator first, t_forward_iterator last, allocator_type const &alloc) {
  vector vec{alloc};
  auto   num = static_cast<size_type>(::portable_stl::distance(first, last));
  if (num > max_size(vec)) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
      ::portable_stl::portable_stl_error::length_error};
  }
  return M_init_with_size(vec, first, last, num)
    .and_then([&vec](void) -> ::portable_stl::expected<vector, ::portable_stl::portable_stl_error> {
      return {::portable_stl::in_place_t{}, ::portable_stl::move(vec)};
    });
}

template<class t_type, class t_allocator>
inline vector<t_type, t_allocator>::vector(std::initializer_list<value_type> init_list) {
  auto      guard = ::portable_stl::make_exception_guard(M_destroy_vector(*this));
  size_type num{init_list.size()};
  if (num > 0) {
    bool const has_length_error{num > max_size()};
    ::portable_stl::throw_on_true<::portable_stl::length_error<>>(has_length_error);
    if (has_length_error) {
      return;
    }
    auto const ptr = M_vallocate(num);
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(nullptr == ptr);
    if (nullptr != ptr) {
      M_construct_at_end(init_list.begin(), init_list.end(), num);
    } else {
      return;
    }
  }
  guard.commit();
}

template<class t_type, class t_allocator>
inline vector<t_type, t_allocator>::vector(std::initializer_list<value_type> init_list, allocator_type const &alloc)
    : m_end_cap(nullptr, alloc) {
  auto      guard = ::portable_stl::make_exception_guard(M_destroy_vector(*this));
  size_type num{init_list.size()};
  if (num > 0) {
    bool const has_length_error{num > max_size()};
    ::portable_stl::throw_on_true<::portable_stl::length_error<>>(has_length_error);
    if (has_length_error) {
      return;
    }
    auto const ptr = M_vallocate(num);
    ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(nullptr == ptr);
    if (nullptr != ptr) {
      M_construct_at_end(init_list.begin(), init_list.end(), num);
    } else {
      return;
    }
  }
  guard.commit();
}

template<class t_type, class t_allocator>
vector<t_type, t_allocator>::vector(vector const &other)
    : m_end_cap(nullptr, t_allocator_traits::select_on_container_copy_construction(other.M_alloc())) {
  M_init_with_size(other.m_begin, other.m_end, other.size());
}

template<class t_type, class t_allocator>
vector<t_type, t_allocator>::vector(vector const &other, ::portable_stl::type_identity_t<allocator_type> const &alloc)
    : m_end_cap(nullptr, alloc) {
  M_init_with_size(other.m_begin, other.m_end, other.size());
}

template<class t_type, class t_allocator>
vector<t_type, t_allocator>::vector(vector &&other) noexcept
    : m_end_cap(nullptr, ::portable_stl::move(other.M_alloc())) {
  m_begin     = other.m_begin;
  m_end       = other.m_end;
  M_end_cap() = other.M_end_cap();

  other.m_begin     = nullptr;
  other.m_end       = nullptr;
  other.M_end_cap() = nullptr;
}

template<class t_type, class t_allocator>
vector<t_type, t_allocator>::vector(
  vector &&other,
  ::portable_stl::type_identity_t<allocator_type> const
    &alloc) noexcept(::portable_stl::noexcept_move_assign_container<allocator_type>{}())
    : m_end_cap(nullptr, alloc) {
  if (alloc == other.M_alloc()) {
    m_begin     = other.m_begin;
    m_end       = other.m_end;
    M_end_cap() = other.M_end_cap();

    other.m_begin     = nullptr;
    other.m_end       = nullptr;
    other.M_end_cap() = nullptr;
  } else {
    using t_move_iter = ::portable_stl::move_iterator<iterator>;
    auto guard        = ::portable_stl::make_exception_guard(M_destroy_vector(*this));
    assign(t_move_iter(other.begin()), t_move_iter(other.end()));
    guard.commit();
  }
}

template<typename t_type, typename t_allocator>
template<class t_iterator, class t_sentinel>
bool vector<t_type, t_allocator>::M_assign_with_sentinel(t_iterator first, t_sentinel last) {
  clear();
  for (; first != last; ++first) {
    if (!emplace_back(*first)) {
      return false;
    }
  }
  return true;
}

template<typename t_type, typename t_allocator>
template<class t_input_iterator, vector_helper::enable_for_input_iter<t_input_iterator, t_type>>
bool vector<t_type, t_allocator>::assign(t_input_iterator first, t_input_iterator last) {
  return M_assign_with_sentinel(first, last);
}

template<typename t_type, typename t_allocator>
template<class t_forward_iterator, class t_sentinel>
bool vector<t_type, t_allocator>::M_assign_with_size(t_forward_iterator first, t_sentinel last, difference_type num) {
  auto new_size = static_cast<size_type>(num);
  if (new_size <= capacity()) {
    if (new_size > size()) {
      t_forward_iterator mid = ::portable_stl::next(first, static_cast<difference_type>(size()));
      ::portable_stl::copy(first, mid, m_begin);
      M_construct_at_end(mid, last, new_size - size());
    } else {
      pointer m
        = ::portable_stl::get<1>(::portable_stl::copy_impl<::portable_stl::classic_alg_policy>(first, last, m_begin));
      M_destruct_at_end(m);
    }
  } else {
    M_vdeallocate();
    if (!M_vallocate(M_recommend(new_size))) {
      return false;
    }
    M_construct_at_end(first, last, new_size);
  }
  return true;
}

template<typename t_type, typename t_allocator>
template<class t_forward_iterator, vector_helper::enable_for_forward_iter<t_forward_iterator, t_type>>
bool vector<t_type, t_allocator>::assign(t_forward_iterator first, t_forward_iterator last) {
  return M_assign_with_size(first, last, ::portable_stl::distance(first, last));
}

template<typename t_type, typename t_allocator>
bool vector<t_type, t_allocator>::assign(size_type num, const_reference value) {
  if (num <= capacity()) {
    size_type old_size{size()};
    ::portable_stl::fill_n(m_begin, ::portable_stl::min(num, old_size), value);
    if (num > old_size) {
      M_construct_at_end(num - old_size, value);
    } else {
      M_destruct_at_end(m_begin + num);
    }
  } else {
    M_vdeallocate();
    if (!M_vallocate(M_recommend(num))) {
      return false;
    }
    M_construct_at_end(num, value);
  }
  return true;
}

template<typename t_type, typename t_allocator>
inline vector<t_type, t_allocator> &vector<t_type, t_allocator>::operator=(vector const &other) {
  if (this != ::portable_stl::addressof(other)) {
    // clear this vector with this allocator.
    M_copy_assign_alloc(other);
    assign(other.m_begin, other.m_end);
  }
  return *this;
}

template<typename t_type, typename t_allocator>
void vector<t_type, t_allocator>::M_move_assign(vector &other, ::portable_stl::false_type) noexcept(
  typename t_allocator_traits::is_always_equal{}()) {
  if (M_alloc() != other.M_alloc()) {
    using t_move_iter = ::portable_stl::move_iterator<iterator>;
    assign(t_move_iter(other.begin()), t_move_iter(other.end()));
  } else {
    M_move_assign(other, ::portable_stl::true_type{});
  }
}

template<typename t_type, typename t_allocator>
void vector<t_type, t_allocator>::M_move_assign(vector &other, ::portable_stl::true_type) noexcept(
  ::portable_stl::is_nothrow_move_assignable<allocator_type>{}()) {
  M_vdeallocate();
  M_move_assign_alloc(other); // this can throw
  m_begin     = other.m_begin;
  m_end       = other.m_end;
  M_end_cap() = other.M_end_cap();

  other.m_begin     = nullptr;
  other.m_end       = nullptr;
  other.M_end_cap() = nullptr;
}

template<typename t_type, typename t_allocator>
inline typename vector<t_type, t_allocator>::reference vector<t_type, t_allocator>::operator[](size_type num) noexcept {
  return m_begin[num];
}

template<typename t_type, typename t_allocator>
inline typename vector<t_type, t_allocator>::const_reference vector<t_type, t_allocator>::operator[](
  size_type num) const noexcept {
  return m_begin[num];
}

template<typename t_type, typename t_allocator>
::portable_stl::expected<typename vector<t_type, t_allocator>::reference_wrap, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::at(size_type pos) noexcept {
  if (pos >= size()) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
      ::portable_stl::portable_stl_error::out_of_range};
  }
  return ::portable_stl::expected<reference_wrap, ::portable_stl::portable_stl_error>(ref<value_type>(m_begin[pos]));
}

template<typename t_type, typename t_allocator>
::portable_stl::expected<typename vector<t_type, t_allocator>::const_reference_wrap, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::at(size_type pos) const noexcept {
  if (pos >= size()) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
      ::portable_stl::portable_stl_error::out_of_range};
  }
  return ::portable_stl::expected<const_reference_wrap, ::portable_stl::portable_stl_error>(
    cref<value_type const>(m_begin[pos]));
}

template<class t_type, class t_allocator>
void vector<t_type, t_allocator>::M_swap_out_circular_buffer(
  ::portable_stl::split_buffer<value_type, allocator_type &> &buf) {
  using t_rev_iter = ::portable_stl::reverse_iterator<pointer>;
  buf.m_begin      = vector_algo::uninitialized_allocator_move_if_noexcept(
                  M_alloc(), t_rev_iter(m_end), t_rev_iter(m_begin), t_rev_iter(buf.m_begin))
                  .base();
  ::portable_stl::swap(m_begin, buf.m_begin);
  ::portable_stl::swap(m_end, buf.m_end);
  ::portable_stl::swap(M_end_cap(), buf.end_cap());
  buf.m_first = buf.m_begin;
}

template<class t_type, class t_allocator>
typename vector<t_type, t_allocator>::pointer vector<t_type, t_allocator>::M_swap_out_circular_buffer(
  ::portable_stl::split_buffer<value_type, allocator_type &> &buf, pointer ptr) {
  pointer ret      = buf.m_begin;
  using t_rev_iter = ::portable_stl::reverse_iterator<pointer>;
  buf.m_begin      = vector_algo::uninitialized_allocator_move_if_noexcept(
                  M_alloc(), t_rev_iter(ptr), t_rev_iter(m_begin), t_rev_iter(buf.m_begin))
                  .base();
  buf.m_end = vector_algo::uninitialized_allocator_move_if_noexcept(M_alloc(), ptr, m_end, buf.m_end);
  ::portable_stl::swap(m_begin, buf.m_begin);
  ::portable_stl::swap(m_end, buf.m_end);
  ::portable_stl::swap(M_end_cap(), buf.end_cap());
  buf.m_first = buf.m_begin;
  return ret;
}

template<class t_type, class t_allocator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> vector<t_type, t_allocator>::reserve(size_type num) {
  if (num > capacity()) {
    if (num > max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    allocator_type &alloc = M_alloc();
    auto buf = ::portable_stl::split_buffer<value_type, allocator_type &>::make_split_buffer(num, size(), alloc);
    if (buf.m_first) {
      M_swap_out_circular_buffer(buf);
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
  }
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

template<typename t_type, typename t_allocator>
template<class t_other_type>
::portable_stl::expected<typename vector<t_type, t_allocator>::pointer, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::M_push_back_slow_path(t_other_type &&other) {
  allocator_type &alloc{M_alloc()};
  if (size() >= max_size()) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
      ::portable_stl::portable_stl_error::length_error};
  }
  auto buf = ::portable_stl::split_buffer<value_type, allocator_type &>::make_split_buffer(
    M_recommend(size() + 1), size(), alloc);
  if (buf.m_first) {
    // buf.push_back(::portable_stl::forward<t_other_type>(value));
    t_allocator_traits::construct(
      alloc, ::portable_stl::to_address(buf.m_end), ::portable_stl::forward<t_other_type>(other));
    buf.m_end++;
    M_swap_out_circular_buffer(buf);
    return ::portable_stl::expected<pointer, ::portable_stl::portable_stl_error>(m_end);
  }
  return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
    ::portable_stl::portable_stl_error::allocate_error};
}

template<typename t_type, typename t_allocator>
inline ::portable_stl::expected<void, ::portable_stl::portable_stl_error> vector<t_type, t_allocator>::push_back(
  const_reference other) {
  pointer end_ptr{m_end};
  if (end_ptr < M_end_cap()) {
    M_construct_one_at_end(other);
    ++end_ptr;
  } else {
    auto result = M_push_back_slow_path(other);
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
    end_ptr = result.value();
  }
  m_end = end_ptr;
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

template<typename t_type, typename t_allocator>
inline ::portable_stl::expected<void, ::portable_stl::portable_stl_error> vector<t_type, t_allocator>::push_back(
  value_type &&other) {
  pointer end_ptr{m_end};
  if (end_ptr < M_end_cap()) {
    M_construct_one_at_end(::portable_stl::move(other));
    ++end_ptr;
  } else {
    auto result = M_push_back_slow_path(::portable_stl::move(other));
    if (!result) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{result.error()};
    }
    end_ptr = result.value();
  }
  m_end = end_ptr;
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

template<typename t_type, typename t_allocator>
inline vector<t_type, t_allocator> &vector<t_type, t_allocator>::operator=(vector &&other) noexcept(
  ::portable_stl::noexcept_move_assign_container<allocator_type>{}()) {
  M_move_assign(other, typename t_allocator_traits::propagate_on_container_move_assignment{});
  return *this;
}

template<class t_type, class t_allocator> void vector<t_type, t_allocator>::M_vdeallocate() noexcept {
  if (nullptr != m_begin) {
    clear();
    t_allocator_traits::deallocate(M_alloc(), m_begin, capacity());
    m_begin     = nullptr;
    m_end       = nullptr;
    M_end_cap() = nullptr;
  }
}

template<class t_type, class t_allocator>
constexpr typename vector<t_type, t_allocator>::size_type vector<t_type, t_allocator>::max_size() const noexcept {
  return ::portable_stl::min<size_type>(t_allocator_traits::max_size(M_alloc()),
                                        ::portable_stl::numeric_limits<difference_type>::max());
}

template<class t_type, class t_allocator>
constexpr typename vector<t_type, t_allocator>::size_type vector<t_type, t_allocator>::max_size(
  vector<t_type, t_allocator> const &vec) noexcept {
  return ::portable_stl::min<size_type>(t_allocator_traits::max_size(vec.M_alloc()),
                                        ::portable_stl::numeric_limits<difference_type>::max());
}

// Precondition:  new_size > capacity()
template<class t_type, class t_allocator>
inline typename vector<t_type, t_allocator>::size_type vector<t_type, t_allocator>::M_recommend(
  size_type new_size) const noexcept {
  size_type const max_sz{max_size()};
  size_type const old_cap{capacity()};
  if (old_cap >= max_sz / 2) {
    return max_sz;
  }
  return ::portable_stl::max<size_type>(2 * old_cap, new_size);
}

template<class t_type, class t_allocator>
template<class... t_args>
typename vector<t_type, t_allocator>::pointer vector<t_type, t_allocator>::M_emplace_back_slow_path(t_args &&...args) {
  allocator_type &alloc{M_alloc()};

  if (size() >= max_size()) {
    return nullptr;
  }

  auto buf = ::portable_stl::split_buffer<value_type, allocator_type &>::make_split_buffer(
    M_recommend(size() + 1), size(), alloc);
  if (buf.m_first) {
    // same as buf.emplace_back(forward<t_args>(args)...);
    t_allocator_traits::construct(
      alloc, ::portable_stl::to_address(buf.m_end), ::portable_stl::forward<t_args>(args)...);
    // vvv change buffer state vvv
    buf.m_end++;
    // vvv change state vvv
    M_swap_out_circular_buffer(buf); // roll-back protected
    return m_end;
  }
  return nullptr;
}

template<typename t_type, typename t_allocator>
template<typename... t_args>
::portable_stl::expected<typename vector<t_type, t_allocator>::reference_wrap, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::emplace_back(t_args &&...args) {
  pointer end{m_end};
  if (end < M_end_cap()) {
    M_construct_one_at_end(::portable_stl::forward<t_args>(args)...);
    ++end;
  } else {
    end = M_emplace_back_slow_path(::portable_stl::forward<t_args>(args)...);
    if (!end) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
  }
  // update state
  m_end = end;
  return ::portable_stl::expected<reference_wrap, ::portable_stl::portable_stl_error>(::portable_stl::ref(*(end - 1)));
}

template<typename t_type, typename t_allocator>
inline typename vector<t_type, t_allocator>::iterator vector<t_type, t_allocator>::erase(const_iterator pos) {
  difference_type const diff{pos - cbegin()};
  pointer               ptr{m_begin + diff};
  auto                  last_moved = ::portable_stl::move(ptr + 1, m_end, ptr);
  M_destruct_at_end(last_moved);
  return M_make_iter(ptr);
}

template<typename t_type, typename t_allocator>
typename vector<t_type, t_allocator>::iterator vector<t_type, t_allocator>::erase(const_iterator first,
                                                                                  const_iterator last) {
  pointer ptr{m_begin + (first - begin())};
  if (first != last) {
    auto last_moved = ::portable_stl::move(ptr + (last - first), m_end, ptr);
    M_destruct_at_end(last_moved);
  }
  return M_make_iter(ptr);
}

/**
 * @brief
 * Strong guarantee.
 * @tparam t_type
 * @tparam t_allocator
 * @param from_start
 * @param from_end
 * @param dest
 */
template<typename t_type, typename t_allocator>
void vector<t_type, t_allocator>::M_move_range(pointer from_start, pointer from_end, pointer dest) {
  pointer         old_last{m_end};
  difference_type num{old_last - dest};
  {
    pointer                ptr = from_start + num;
    M_ConstructTransaction trans(*this, static_cast<size_type>(from_end - ptr));
    for (pointer pos{trans.m_pos}; ptr < from_end; ++ptr, (void)++pos, trans.m_pos = pos) {
      t_allocator_traits::construct(M_alloc(), ::portable_stl::to_address(pos), ::portable_stl::move(*ptr));
    }
  }
  ::portable_stl::move_backward(from_start, from_start + num, old_last);
}

/**
 * @brief
 * Strong guarantee.
 * @tparam t_type
 * @tparam t_allocator
 * @param position
 * @param value
 * @return vector<t_type, t_allocator>::iterator
 */
template<typename t_type, typename t_allocator>
::portable_stl::expected<typename vector<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::insert(const_iterator position, const_reference value) {
  pointer ptr{m_begin + (position - begin())};
  // We can't compare unrelated pointers inside constant expressions
  // No need additional memory
  if (!is_constant_evaluated() && m_end < M_end_cap()) {
    if (ptr == m_end) {
      M_construct_one_at_end(value); // roll-back m_end if unsuccessful
    } else {
      M_move_range(ptr, m_end, ptr + 1);

      // check if the value (ref) was already in vector
      const_pointer value_ptr{::portable_stl::pointer_traits<const_pointer>::pointer_to(value)};
      if ((ptr <= value_ptr) && (value_ptr < m_end)) {
        ++value_ptr;
      }
      *ptr = *value_ptr;
    }
  } else {
    allocator_type &alloc = M_alloc();
    if (size() >= max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    auto buf = ::portable_stl::split_buffer<value_type, allocator_type &>::make_split_buffer(
      M_recommend(size() + 1), ::portable_stl::size_t(ptr - m_begin), alloc);
    if (buf.m_first) {
      buf.push_back(value);
      ptr = M_swap_out_circular_buffer(buf, ptr);
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
  }
  return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>(M_make_iter(ptr));
}

template<typename t_type, typename t_allocator>
::portable_stl::expected<typename vector<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::insert(const_iterator position, value_type &&value) {
  pointer ptr = m_begin + (position - begin());
  // No need additional memory
  if (m_end < M_end_cap()) {
    if (ptr == m_end) {
      M_construct_one_at_end(::portable_stl::move(value));
    } else {
      M_move_range(ptr, m_end, ptr + 1);
      *ptr = ::portable_stl::move(value);
    }
  } else {
    allocator_type &alloc = M_alloc();
    if (size() >= max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    auto buf = ::portable_stl::split_buffer<value_type, allocator_type &>::make_split_buffer(
      M_recommend(size() + 1), static_cast<size_type>(ptr - m_begin), alloc);
    if (buf.m_first) {
      buf.push_back(::portable_stl::move(value));
      ptr = M_swap_out_circular_buffer(buf, ptr);
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
  }
  return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>(M_make_iter(ptr));
}

/**
 * @brief
 * Basic guarantee.
 * @tparam t_type
 * @tparam t_allocator
 * @param position
 * @param num
 * @param value
 * @return vector<t_type, t_allocator>::iterator
 */
template<typename t_type, typename t_allocator>
::portable_stl::expected<typename vector<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::insert(const_iterator position, size_type num, const_reference value) {
  pointer ptr = m_begin + (position - begin());
  if (num > 0) {
    // We can't compare unrelated pointers inside constant expressions
    if (!is_constant_evaluated() && (num <= static_cast<size_type>(M_end_cap() - m_end))) {
      size_type old_num{num};
      pointer   old_last{m_end};
      if (num > static_cast<size_type>(m_end - ptr)) {
        size_type cx = num - static_cast<size_type>(m_end - ptr);
        M_construct_at_end(cx, value);
        num -= cx;
      }
      if (num > 0) {
        M_move_range(ptr, old_last, ptr + old_num);
        const_pointer value_ptr = ::portable_stl::pointer_traits<const_pointer>::pointer_to(value);
        if ((ptr <= value_ptr) && (value_ptr < m_end)) {
          value_ptr += old_num;
        }
        ::portable_stl::fill_n(ptr, num, *value_ptr);
      }
    } else {
      allocator_type &alloc = M_alloc();
      size_type       new_size{size() + num};
      if (new_size > max_size()) {
        return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
          ::portable_stl::portable_stl_error::length_error};
      }
      auto buf = ::portable_stl::split_buffer<value_type, allocator_type &>::make_split_buffer(
        M_recommend(new_size), static_cast<size_type>(ptr - m_begin), alloc);
      if (buf.m_first) {
        buf.M_construct_at_end(num, value);
        ptr = M_swap_out_circular_buffer(buf, ptr);
      } else {
        return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
          ::portable_stl::portable_stl_error::allocate_error};
      }
    }
  }
  return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>(M_make_iter(ptr));
}

template<typename t_type, typename t_allocator>
template<class t_input_iterator, class t_sentinel>
::portable_stl::expected<typename vector<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::M_insert_with_sentinel(
    const_iterator position, t_input_iterator first, t_sentinel last) {
  difference_type const offset{position - begin()};
  pointer               ptr{m_begin + offset};
  allocator_type       &alloc{M_alloc()};
  pointer               old_last{m_end};

  auto guard = ::portable_stl::make_exception_guard([this, &old_last]() {
    erase(M_make_iter(old_last), end());
  });

  // fill available capacity
  for (; (m_end != M_end_cap()) && (first != last); ++first) {
    M_construct_one_at_end(*first);
  }
  split_buffer<value_type, allocator_type &> buf(alloc);
  if (first != last) {
    auto res0 = buf.M_construct_at_end_with_sentinel(::portable_stl::move(first), ::portable_stl::move(last));
    if (!res0) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
    difference_type const old_size{old_last - m_begin};
    difference_type const old_p{ptr - m_begin};
    auto                  res1 = reserve(M_recommend(size() + buf.size()));
    if (!res1) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
    ptr      = m_begin + old_p;
    old_last = m_begin + old_size;
  }
  guard.commit();

  ptr       = ::portable_stl::rotate(ptr, old_last, m_end);
  auto res2 = insert(
    M_make_iter(ptr), ::portable_stl::make_move_iterator(buf.begin()), ::portable_stl::make_move_iterator(buf.end()));
  if (!res2) {
    return res2;
  }
  return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>(begin() + offset);
}

template<typename t_type, typename t_allocator>
template<class t_input_iterator, vector_helper::enable_for_input_iter<t_input_iterator, t_type>>
::portable_stl::expected<typename vector<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::insert(const_iterator position, t_input_iterator first, t_input_iterator last) {
  return M_insert_with_sentinel(position, first, last);
}

template<typename t_type, typename t_allocator>
template<class t_iterator, class t_sentinel>
::portable_stl::expected<typename vector<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::M_insert_with_size(
    const_iterator position, t_iterator first, t_sentinel last, difference_type num) {
  auto    insertion_size = static_cast<size_type>(num);
  pointer ptr{m_begin + (position - begin())};
  if (num > 0) {
    if (num <= (M_end_cap() - m_end)) {
      difference_type old_n{num};
      pointer         old_last{m_end};
      t_iterator      m{::portable_stl::next(first, num)};
      difference_type dx{m_end - ptr};
      if (num > dx) {
        m = first;
        difference_type const diff{m_end - ptr};
        ::portable_stl::advance(m, diff);
        M_construct_at_end(m, last, static_cast<size_type>(num - diff));
        num = dx;
      }
      if (num > 0) {
        M_move_range(ptr, old_last, ptr + old_n);
        ::portable_stl::copy(first, m, ptr);
      }
    } else {
      allocator_type &alloc    = M_alloc();
      size_type       new_size = {size() + static_cast<size_type>(num)};
      if (new_size > max_size()) {
        return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
          ::portable_stl::portable_stl_error::length_error};
      }
      auto buf = split_buffer<value_type, allocator_type &>::make_split_buffer(
        M_recommend(new_size), static_cast<size_type>(ptr - m_begin), alloc);
      if (buf.m_first) {
        buf.M_construct_at_end_with_size(first, insertion_size);
        ptr = M_swap_out_circular_buffer(buf, ptr);
      } else {
        return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
          ::portable_stl::portable_stl_error::allocate_error};
      }
    }
  }
  return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>(M_make_iter(ptr));
}

template<typename t_type, typename t_allocator>
template<class t_forward_iterator, vector_helper::enable_for_forward_iter<t_forward_iterator, t_type>>
::portable_stl::expected<typename vector<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::insert(const_iterator position, t_forward_iterator first, t_forward_iterator last) {
  return M_insert_with_size(position, first, last, ::portable_stl::distance(first, last));
}

template<typename t_type, typename t_allocator>
template<class... t_args>
::portable_stl::expected<typename vector<t_type, t_allocator>::iterator, ::portable_stl::portable_stl_error>
  vector<t_type, t_allocator>::emplace(const_iterator position, t_args &&...args) {
  pointer ptr{m_begin + (position - begin())};
  if (m_end < M_end_cap()) {
    if (ptr == m_end) {
      M_construct_one_at_end(::portable_stl::forward<t_args>(args)...);
    } else {
      ::portable_stl::temp_value<value_type, t_allocator> tmp(M_alloc(), ::portable_stl::forward<t_args>(args)...);
      M_move_range(ptr, m_end, ptr + 1);
      *ptr = ::portable_stl::move(tmp.get());
    }
  } else {
    allocator_type &alloc = M_alloc();
    size_type       new_size{size() + 1};
    if (new_size > max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    auto buf = ::portable_stl::split_buffer<value_type, allocator_type &>::make_split_buffer(
      M_recommend(new_size), static_cast<size_type>(ptr - m_begin), alloc);
    if (buf.m_first) {
      buf.emplace_back(::portable_stl::forward<t_args>(args)...);
      ptr = M_swap_out_circular_buffer(buf, ptr);
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
  }
  return ::portable_stl::expected<iterator, ::portable_stl::portable_stl_error>(M_make_iter(ptr));
}

/**
 * @brief Default constructs num objects starting at m_end.
 * Postcondition:  size() == size() + num
 * Exception safety: strong.
 * @throws if construction throws.
 * @tparam t_type
 * @tparam t_allocator
 * @param num
 * @return true if OK,
 * @return false otherwise.
 */
template<class t_type, class t_allocator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> vector<t_type, t_allocator>::M_append(
  size_type num) {
  if (static_cast<size_type>(M_end_cap() - m_end) >= num) {
    M_construct_at_end(num);
  } else {
    allocator_type &alloc    = M_alloc();
    auto            new_size = (size() + num);
    if (new_size > max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    auto buf = ::portable_stl::split_buffer<value_type, allocator_type &>::make_split_buffer(
      M_recommend(new_size), size(), alloc);
    if (buf.m_first) {
      buf.M_construct_at_end(num);
      M_swap_out_circular_buffer(buf);
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
  }
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

template<typename t_type, typename t_allocator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> vector<t_type, t_allocator>::resize(
  size_type new_size) {
  size_type const old_size{size()};
  if (old_size < new_size) {
    auto result = M_append(new_size - old_size);
    if (!result) {
      return result;
    }
  } else if (old_size > new_size) {
    M_destruct_at_end(m_begin + new_size);
  }
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

/**
 * @brief Default constructs num objects (==value) starting at m_end.
 * Postcondition:  size() == size() + num
 * Exception safety: strong.
 * @throws if construction throws.
 * @tparam t_type
 * @tparam t_allocator
 * @param num
 * @param value
 * @return true if OK,
 * @return false otherwise.
 */
template<class t_type, class t_allocator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> vector<t_type, t_allocator>::M_append(
  size_type num, const_reference value) {
  if (static_cast<size_type>(M_end_cap() - m_end) >= num) {
    M_construct_at_end(num, value);
  } else {
    allocator_type &alloc    = M_alloc();
    auto            new_size = (size() + num);
    if (new_size > max_size()) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    auto buf = ::portable_stl::split_buffer<value_type, allocator_type &>::make_split_buffer(
      M_recommend(new_size), size(), alloc);
    if (buf.m_first) {
      buf.M_construct_at_end(num, value);
      M_swap_out_circular_buffer(buf);
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::allocate_error};
    }
  }
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

template<typename t_type, typename t_allocator>
::portable_stl::expected<void, ::portable_stl::portable_stl_error> vector<t_type, t_allocator>::resize(
  size_type new_size, const_reference value) {
  size_type const old_size{size()};
  if (old_size < new_size) {
    auto result = M_append(new_size - old_size, value);
    if (!result) {
      return result;
    }
  } else if (old_size > new_size) {
    M_destruct_at_end(m_begin + new_size);
  }
  return ::portable_stl::expected<void, ::portable_stl::portable_stl_error>();
}

template<typename t_type, typename t_allocator> bool vector<t_type, t_allocator>::shrink_to_fit() {
  if (capacity() > size()) {
    allocator_type &alloc = M_alloc();
    auto buf = ::portable_stl::split_buffer<value_type, allocator_type &>::make_split_buffer(size(), size(), alloc);
    if (buf.m_first) {
      M_swap_out_circular_buffer(buf);
    } else {
      return false;
    }
  }
  return true;
}

template<typename t_type, typename t_allocator>
void vector<t_type, t_allocator>::swap(vector &other) noexcept(
  typename t_allocator_traits::propagate_on_container_swap{}() || typename t_allocator_traits::is_always_equal{}()) {
  ::portable_stl::swap(m_begin, other.m_begin);
  ::portable_stl::swap(m_end, other.m_end);
  ::portable_stl::swap(M_end_cap(), other.M_end_cap());
  ::portable_stl::memory_helper::swap_allocator_impl(
    M_alloc(), other.M_alloc(), typename t_allocator_traits::propagate_on_container_swap{});
}

template<typename t_type, typename t_allocator>
inline bool operator==(vector<t_type, t_allocator> const &left, vector<t_type, t_allocator> const &right) {
  typename vector<t_type, t_allocator>::size_type const left_size{left.size()};
  return (left_size == right.size()) && ::portable_stl::equal(left.begin(), left.end(), right.begin());
}

template<typename t_type, typename t_allocator>
inline bool operator!=(vector<t_type, t_allocator> const &left, vector<t_type, t_allocator> const &right) {
  return !(left == right);
}

template<typename t_type, typename t_allocator>
inline bool operator<(vector<t_type, t_allocator> const &left, vector<t_type, t_allocator> const &right) {
  return ::portable_stl::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

template<typename t_type, typename t_allocator>
inline bool operator>(vector<t_type, t_allocator> const &left, vector<t_type, t_allocator> const &right) {
  return right < left;
}

template<typename t_type, typename t_allocator>
inline bool operator>=(vector<t_type, t_allocator> const &left, vector<t_type, t_allocator> const &right) {
  return !(left < right);
}

template<typename t_type, typename t_allocator>
inline bool operator<=(vector<t_type, t_allocator> const &left, vector<t_type, t_allocator> const &right) {
  return !(right < left);
}

template<typename t_type, typename t_allocator>
constexpr inline void swap(vector<t_type, t_allocator> &left,
                           vector<t_type, t_allocator> &right) noexcept(noexcept(left.swap(right))) {
  left.swap(right);
}
} // namespace portable_stl

#endif // PSTL_VECTOR_H
