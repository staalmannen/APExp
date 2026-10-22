// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="allocator_traits.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ALLOCATOR_TRAITS_H
#define PSTL_ALLOCATOR_TRAITS_H

// #include "../limits/numeric_limits.h"
#include "../common/numeric_limits.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/type_properties/is_empty.h"
#include "../metaprogramming/type_properties/is_nothrow_constructible.h"
#include "../metaprogramming/type_properties/is_nothrow_destructible.h"
#include "../utility/general/declval.h"
#include "allocation_result.h"
#include "allocator_traits_rebind.h"
#include "construct_at.h"
#include "destroy_at.h"
#include "get_allocator_const_pointer.h"
#include "get_allocator_const_void_pointer.h"
#include "get_allocator_difference_type.h"
#include "get_allocator_pointer.h"
#include "get_allocator_propagate_on_container_copy_assignment.h"
#include "get_allocator_propagate_on_container_move_assignment.h"
#include "get_allocator_propagate_on_container_swap.h"
#include "get_allocator_size_type.h"
#include "get_allocator_void_pointer.h"

namespace portable_stl {

namespace allocator_traits_helper {

  // [has_allocate_hint]

  template<class t_allocator, class t_size_type, class t_const_void_ptr, class = void> class has_allocate_hint final {
  public:
    using type = ::portable_stl::false_type;
  };

  template<class t_allocator, class t_size_type, class t_const_void_ptr>
  struct has_allocate_hint<t_allocator,
                           t_size_type,
                           t_const_void_ptr,
                           decltype((void)::portable_stl::declval<t_allocator>().allocate(
                             ::portable_stl::declval<t_size_type>(), ::portable_stl::declval<t_const_void_ptr>()))>
    final {
  public:
    using type = ::portable_stl::true_type;
  };

  // [has_construct]

  template<class, class t_allocator, class... t_args> class has_construct_impl final {
  public:
    using type = ::portable_stl::false_type;
  };

  template<class t_allocator, class... t_args>
  class has_construct_impl<decltype((void)::portable_stl::declval<t_allocator>().construct(
                             ::portable_stl::declval<t_args>()...)),
                           t_allocator,
                           t_args...> {
  public:
    using type = ::portable_stl::true_type;
  };

  template<class t_allocator, class... t_args>
  using has_construct = typename has_construct_impl<void, t_allocator, t_args...>::type;

  // [has_destroy]

  template<class t_allocator, class t_pointer, class = void> class has_destroy final {
  public:
    using type = ::portable_stl::false_type;
  };

  template<class t_allocator, class t_pointer>
  class has_destroy<t_allocator,
                    t_pointer,
                    decltype((void)::portable_stl::declval<t_allocator>().destroy(
                      ::portable_stl::declval<t_pointer>()))>
    final {
  public:
    using type = ::portable_stl::true_type;
  };

  // [has_max_size]

  template<class t_allocator, class = void> class has_max_size final {
  public:
    using type = ::portable_stl::false_type;
  };

  template<class t_allocator>
  class has_max_size<t_allocator, decltype((void)::portable_stl::declval<t_allocator &>().max_size())> final {
  public:
    using type = ::portable_stl::true_type;
  };

  // [has_select_on_container_copy_construction]

  template<class t_allocator, class = void> class has_select_on_container_copy_construction final {
  public:
    using type = ::portable_stl::false_type;
  };

  template<class t_allocator>
  class has_select_on_container_copy_construction<
    t_allocator,
    decltype((void)::portable_stl::declval<t_allocator>().select_on_container_copy_construction())>
    final {
  public:
    using type = ::portable_stl::true_type;
  };

  // [is_always_equal]

  template<class t_type, class = void> class has_is_always_equal final {
  public:
    using type = ::portable_stl::false_type;
  };

  template<class t_type>
  class has_is_always_equal<t_type, ::portable_stl::void_t<typename t_type::is_always_equal>> final {
  public:
    using type = ::portable_stl::true_type;
  };

  template<class t_allocator, class = typename has_is_always_equal<t_allocator>::type> class is_always_equal_sel final {
  public:
    using type = ::portable_stl::is_empty<t_allocator>;
  };

  template<class t_allocator> class is_always_equal_sel<t_allocator, ::portable_stl::true_type> final {
  public:
    using type = typename t_allocator::is_always_equal;
  };

} // namespace allocator_traits_helper

template<class t_allocator> class allocator_traits final {
public:
  using allocator_type = t_allocator;
  using value_type     = typename allocator_type::value_type;
  using pointer        = typename ::portable_stl::get_allocator_pointer<value_type, allocator_type>::type;
  using const_pointer = typename ::portable_stl::get_allocator_const_pointer<value_type, pointer, allocator_type>::type;
  using void_pointer  = typename ::portable_stl::get_allocator_void_pointer<pointer, allocator_type>::type;
  using const_void_pointer = typename ::portable_stl::get_allocator_const_void_pointer<pointer, allocator_type>::type;
  using difference_type    = typename ::portable_stl::get_allocator_difference_type<pointer, allocator_type>::type;
  using size_type          = typename ::portable_stl::get_allocator_size_type<pointer, allocator_type>::type;

  using propagate_on_container_copy_assignment =
    typename ::portable_stl::get_allocator_propagate_on_container_copy_assignment<allocator_type>::type;

  using propagate_on_container_move_assignment =
    typename ::portable_stl::get_allocator_propagate_on_container_move_assignment<allocator_type>::type;

  using propagate_on_container_swap =
    typename ::portable_stl::get_allocator_propagate_on_container_swap<allocator_type>::type;

  using is_always_equal = typename allocator_traits_helper::is_always_equal_sel<allocator_type>::type;

  template<class t_type>
  using rebind_alloc = typename ::portable_stl::allocator_traits_rebind<allocator_type, t_type>::type;

  template<class t_type> using rebind_traits = allocator_traits<rebind_alloc<t_type>>;

  /**
   * @brief Allocates uninitialized storage using the allocator.
   *
   * @param allocator Allocator to use.
   * @param num The number of objects to allocate storage for.
   * @return The pointer returned by the call to a.allocate(n).
   */
  constexpr static pointer allocate(allocator_type &allocator, size_type num) {
    return allocator.allocate(num);
  }

  /**
   * @brief Allocates uninitialized storage using the allocator.
   *
   * @tparam t_alloc
   * @param allocator Allocator to use.
   * @param num The number of objects to allocate storage for.
   * @param ptr_hint Pointer to a nearby memory location
   * @return The pointer returned by the call to a.allocate(n).
   */
  template<class t_alloc = t_allocator,
           class         = ::portable_stl::enable_if_bool_constant_t<
                     typename allocator_traits_helper::has_allocate_hint<t_alloc, size_type, const_void_pointer>::type>>
  constexpr static pointer allocate(allocator_type &allocator, size_type num, const_void_pointer ptr_hint) {
    return allocator.allocate(num, ptr_hint);
  }

  /**
   * @brief Allocates uninitialized storage using the allocator.
   * allocator has no two-argument member function allocate.
   * @tparam t_alloc
   * @param allocator Allocator to use.
   * @param num The number of objects to allocate storage for.
   * @return The pointer returned by the call to a.allocate(n).
   */
  template<class t_alloc = t_allocator,
           class         = void,
           class         = ::portable_stl::enable_if_bool_constant_t<::portable_stl::negation<
                     typename allocator_traits_helper::has_allocate_hint<t_alloc, size_type, const_void_pointer>::type>>>
  constexpr static pointer allocate(allocator_type &allocator, size_type num, const_void_pointer) {
    return allocator.allocate(num);
  }

  constexpr static allocation_result<pointer, size_type> allocate_at_least(allocator_type &allocator,
                                                                           size_type       count) noexcept {
    return allocator.allocate_at_least(count);
  }

  /**
   * @brief Deallocates storage using the allocator.
   *
   * @param allocator Allocator to use.
   * @param ptr Pointer to the previously allocated storage.
   * @param num The number of objects the storage was allocated for.
   */
  constexpr static void deallocate(allocator_type &allocator, pointer ptr, size_type num) noexcept {
    allocator.deallocate(ptr, num);
  }

  /**
   * @brief Constructs an object in the allocated storage.
   *
   * @tparam t_type
   * @tparam t_args
   * @param allocator Allocator to use for construction.
   * @param ptr Pointer to the uninitialized storage on which a T object will be constructed.
   * @param args The constructor arguments to pass to a.construct().
   */
  template<class t_type,
           class... t_args,
           class = ::portable_stl::enable_if_bool_constant_t<
             typename allocator_traits_helper::has_construct<allocator_type, t_type *, t_args...>::type>>
  constexpr static void construct(allocator_type &allocator, t_type *ptr, t_args &&...args) {
    allocator.construct(ptr, ::portable_stl::forward<t_args>(args)...);
  }

  /**
   * @brief Constructs an object in the allocated storage.
   *
   * @tparam t_type
   * @tparam t_args
   * @param ptr Pointer to the uninitialized storage on which a T object will be constructed.
   * @param args The constructor arguments to pass to construct_at() (since C++20).
   */
  template<class t_type,
           class... t_args,
           class = void,
           class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::negation<
             typename allocator_traits_helper::has_construct<allocator_type, t_type *, t_args...>::type>>>
  constexpr static void construct(allocator_type &, t_type *ptr, t_args &&...args) {
    ::portable_stl::construct_at(ptr, ::portable_stl::forward<t_args>(args)...);
  }

  /**
   * @brief Destructs an object stored in the allocated storage.
   * Calls the destructor of the object pointed to by ptr.
   * @tparam t_type
   * @param allocator Allocator to use for destruction.
   * @param ptr Pointer to the object being destroyed.
   */
  template<class t_type,
           class = ::portable_stl::enable_if_bool_constant_t<
             typename allocator_traits_helper::has_destroy<allocator_type, t_type *>::type>>
  constexpr static void destroy(allocator_type &allocator, t_type *ptr) {
    allocator.destroy(ptr);
  }

  /**
   * @brief Destructs an object stored in the allocated storage.
   * If allocator_type does not have the member function destroy()), then calls the destructor of *p directly, as
   * destroy_at(p)(since C++20).
   * @tparam t_type
   * @param ptr Pointer to the object being destroyed.
   */
  template<class t_type,
           class = void,
           class = ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::negation<typename allocator_traits_helper::has_destroy<allocator_type, t_type *>::type>>>
  constexpr static void destroy(allocator_type &, t_type *ptr) {
    ::portable_stl::destroy_at(ptr);
  }

  /**
   * @brief Returns the maximum object size supported by the allocator.
   *
   * @tparam t_alloc
   * @param allocator Allocator to detect.
   * @return Theoretical maximum allocation size.
   */
  template<class t_alloc = t_allocator,
           class         = ::portable_stl::enable_if_bool_constant_t<
                     typename allocator_traits_helper::has_max_size<t_alloc const>::type>>
  constexpr static size_type max_size(allocator_type const &allocator) noexcept {
    return allocator.max_size();
  }

  /**
   * @brief Returns the maximum object size supported by the allocator.
   *
   * @tparam t_alloc
   * @return Theoretical maximum allocation size.
   */
  template<class t_alloc = t_allocator,
           class         = void,
           class         = ::portable_stl::enable_if_bool_constant_t<
                     ::portable_stl::negation<typename allocator_traits_helper::has_max_size<t_alloc const>::type>>>
  constexpr static size_type max_size(allocator_type const &) noexcept {
    return ::portable_stl::numeric_limits<size_type>::max() / sizeof(value_type);
  }

  /**
   * @brief Obtains the allocator to use after copying a standard container.
   * @tparam t_alloc
   * @param allocator Allocator used by a standard container passed as an argument to a container copy constructor.
   * @return The allocator to use by the copy-constructed standard containers.
   */
  template<class t_alloc = t_allocator,
           class         = ::portable_stl::enable_if_bool_constant_t<
                     typename allocator_traits_helper::has_select_on_container_copy_construction<t_alloc const>::type>>
  constexpr static allocator_type select_on_container_copy_construction(allocator_type const &allocator) {
    return allocator.select_on_container_copy_construction();
  }

  /**
   * @brief Obtains the allocator to use after copying a standard container.
   *
   * @tparam t_alloc
   * @param allocator Allocator used by a standard container passed as an argument to a container copy constructor.
   * @return The allocator to use by the copy-constructed standard containers.
   */
  template<class t_alloc = t_allocator,
           class         = void,
           class         = ::portable_stl::enable_if_bool_constant_t<::portable_stl::negation<
                     typename allocator_traits_helper::has_select_on_container_copy_construction<t_alloc const>::type>>>
  constexpr static allocator_type select_on_container_copy_construction(allocator_type const &allocator) {
    return allocator;
  }
};
} // namespace portable_stl

#endif // PSTL_ALLOCATOR_TRAITS_H
