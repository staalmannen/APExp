// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="vector_algo.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_VECTOR_ALGO_H
#define PSTL_VECTOR_ALGO_H

#include "../algorithm/copy.h"
#include "../algorithm/move_algo.h"
#include "../algorithm/unwrap_iter.h"
#include "../algorithm/unwrap_range.h"
#include "../iterator/reverse_iterator.h"
#include "../memory/allocator.h"
#include "../memory/allocator_traits.h"
#include "../memory/to_address.h"
#include "../metaprogramming/cv_modifications/remove_const.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/type_properties/is_trivially_copy_assignable.h"
#include "../metaprogramming/type_properties/is_trivially_copy_constructible.h"
#include "../metaprogramming/type_properties/is_trivially_move_assignable.h"
#include "../metaprogramming/type_properties/is_trivially_move_constructible.h"
#include "../metaprogramming/type_relations/is_same.h"
#include "../utility/general/make_exception_guard.h"
#include "../utility/tuple/tuple_get.h"
#include "../utility/general/move_if_noexcept.h"

namespace portable_stl {
namespace vector_algo {

  // Destroy all elements in [first, last) from left to right using allocator destruction.
  template<class t_allocator, class t_iter, class t_sentinel>
  void allocator_destroy(t_allocator &alloc, t_iter first, t_sentinel last) {
    for (; first != last; ++first) {
      ::portable_stl::allocator_traits<t_allocator>::destroy(alloc, ::portable_stl::to_address(first));
    }
  }

  template<class t_allocator, class t_iter> class AllocatorDestroyRangeReverse final {
  public:
    constexpr AllocatorDestroyRangeReverse(t_allocator &alloc, t_iter &first, t_iter &last)
        : m_alloc(alloc), m_first(first), m_last(last) {
    }

    void operator()() const {
      allocator_destroy(
        m_alloc, ::portable_stl::reverse_iterator<t_iter>(m_last), ::portable_stl::reverse_iterator<t_iter>(m_first));
    }

  private:
    t_allocator &m_alloc;
    t_iter      &m_first;
    t_iter      &m_last;
  };

  /**
   * @brief Copy-construct [first1, last1) in [first2, first2 + N), where N is distance(first1, last1).
   * The caller has to ensure that first2 can hold at least N uninitialized elements. If an exception is thrown the
   * already copied elements are destroyed in reverse order of their construction.
   * @tparam t_allocator
   * @tparam t_iter1
   * @tparam t_sentinel
   * @tparam t_iter2
   * @param alloc
   * @param first1
   * @param last1
   * @param first2
   * @return
   */
  template<class t_allocator, class t_iter1, class t_sentinel, class t_iter2>
  t_iter2 uninitialized_allocator_copy_impl(t_allocator &alloc, t_iter1 first1, t_sentinel last1, t_iter2 first2) {
    auto destruct_first = first2;
    auto guard          = ::portable_stl::make_exception_guard(
      AllocatorDestroyRangeReverse<t_allocator, t_iter2>(alloc, destruct_first, first2));
    while (first1 != last1) {
      ::portable_stl::allocator_traits<t_allocator>::construct(alloc, ::portable_stl::to_address(first2), *first1);
      ++first1;
      ++first2;
    }
    guard.commit();
    return first2;
  }

  template<class t_allocator, class t_type> class allocator_has_trivial_copy_construct final {
  public:
    using type = ::portable_stl::negation<
      typename allocator_traits_helper::has_construct<t_allocator, t_type *, t_type const &>::type>;
  };

  template<class t_type> class allocator_has_trivial_copy_construct<::portable_stl::allocator<t_type>, t_type> final {
  public:
    using type = ::portable_stl::true_type;
  };

  template<
    class t_allocator,
    class t_input_type,
    class t_raw_in_type = ::portable_stl::remove_const_t<t_input_type>,
    class t_output_type,
    ::portable_stl::enable_if_bool_constant_t<
      // using t_raw_in_type because of the allocator<T const> extension
      ::portable_stl::conjunction<::portable_stl::is_trivially_copy_assignable<t_raw_in_type>,
                                  ::portable_stl::is_trivially_copy_constructible<t_raw_in_type>,
                                  ::portable_stl::is_same<::portable_stl::remove_const_t<t_input_type>,
                                                          ::portable_stl::remove_const_t<t_output_type>>,
                                  typename allocator_has_trivial_copy_construct<t_allocator, t_raw_in_type>::type>,
      void *>
    = nullptr>
  t_output_type *uninitialized_allocator_copy_impl(
    t_allocator &, t_input_type *first1, t_input_type *last1, t_output_type *first2) {
    // TODO: Remove the const_cast once we drop support for ::portable_stl::allocator<T const>
    // if (__libcpp_is_constant_evaluated()) {
    //   while (first1 != last1) {
    //     ::portable_stl::construct_at(::portable_stl::to_address(first2), *first1);
    //     ++first1;
    //     ++first2;
    //   }
    //   return first2;
    // } else {
    return ::portable_stl::copy(first1, last1, const_cast<t_raw_in_type *>(first2));
    // }
  }

  template<class t_allocator, class t_iter1, class t_sentinel1, class t_iter2>
  t_iter2 uninitialized_allocator_copy(t_allocator &alloc, t_iter1 first1, t_sentinel1 last1, t_iter2 first2) {
    auto unwrapped_range = ::portable_stl::unwrap_range(first1, last1);
    auto result          = uninitialized_allocator_copy_impl(alloc,
                                                    ::portable_stl::get<0>(unwrapped_range),
                                                    ::portable_stl::get<1>(unwrapped_range),
                                                    ::portable_stl::unwrap_iter(first2));
    return ::portable_stl::rewrap_iter(first2, result);
  }

  // is_default_allocator
  template<class t_type> class is_default_allocator_impl final {
  public:
    using type = ::portable_stl::false_type;
  };

  template<class t_type> class is_default_allocator_impl<::portable_stl::allocator<t_type>> final {
  public:
    using type = ::portable_stl::true_type;
  };

  template<class t_type> using is_default_allocator = typename is_default_allocator_impl<t_type>::type;

  // is_cpp17_move_insertable
  template<class t_allocator, class = void> class is_cpp17_move_insertable_impl final {
  public:
    using type = is_move_constructible<typename t_allocator::value_type>;
  };

  template<class t_allocator>
  class is_cpp17_move_insertable_impl<
    t_allocator,
    ::portable_stl::enable_if_bool_constant_t<::portable_stl::conjunction<
      ::portable_stl::negation<is_default_allocator<t_allocator>>,
      typename allocator_traits_helper::
        has_construct<t_allocator, typename t_allocator::value_type *, typename t_allocator::value_type &&>::type>>> final{
  public:
    using type = ::portable_stl::true_type;
  };

    template<class t_allocator>
  using is_cpp17_move_insertable = typename is_cpp17_move_insertable_impl<t_allocator>::type;

  // Move-construct the elements [first1, last1) into [first2, first2 + N)
  // if the move constructor is noexcept, where N is distance(first1, last1).
  //
  // Otherwise try to copy all elements. If an exception is thrown the already copied
  // elements are destroyed in reverse order of their construction.
  template<class t_allocator, class t_iter1, class t_sentinel1, class t_iter2>
  t_iter2 uninitialized_allocator_move_if_noexcept(
    t_allocator &alloc, t_iter1 first1, t_sentinel1 last1, t_iter2 first2) {
    static_assert(is_cpp17_move_insertable<t_allocator>{}(),
                  "The specified type does not meet the requirements of Cpp17MoveInsertable");
    auto destruct_first = first2;
    auto guard          = ::portable_stl::make_exception_guard(
      AllocatorDestroyRangeReverse<t_allocator, t_iter2>(alloc, destruct_first, first2));
    while (first1 != last1) {
      allocator_traits<t_allocator>::construct(
        alloc, ::portable_stl::to_address(first2), ::portable_stl::move_if_noexcept(*first1));
      ++first1;
      ++first2;
    }
    guard.commit();
    return first2;
  }

  /**
   * @brief allocator_has_trivial_move_construct implementation.
   * @tparam t_type
   */
  template<class t_allocator, class t_type> class allocator_has_trivial_move_construct_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::negation<
      typename allocator_traits_helper::has_construct<t_allocator, t_type *, t_type &&>::type>;
  };

  /**
   * @brief allocator_has_trivial_move_construct implementation.
   * @tparam t_type
   */
  template<class t_type>
  struct allocator_has_trivial_move_construct_impl<::portable_stl::allocator<t_type>, t_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::true_type;
  };

  template<class t_allocator, class t_type>
  using allocator_has_trivial_move_construct =
    typename allocator_has_trivial_move_construct_impl<t_allocator, t_type>::type;

  template<class t_allocator,
           class t_iter1,
           class t_iter2,
           class t_value_type = typename ::portable_stl::iterator_traits<t_iter1>::value_type,
           class              = ::portable_stl::enable_if_bool_constant_t<
                          ::portable_stl::conjunction<::portable_stl::is_trivially_move_constructible<t_value_type>,
                                                      ::portable_stl::is_trivially_move_assignable<t_value_type>,
                                                      allocator_has_trivial_move_construct<t_allocator, t_value_type>>>>
  t_iter2 uninitialized_allocator_move_if_noexcept(t_allocator &, t_iter1 first1, t_iter1 last1, t_iter2 first2) {
    // if (__libcpp_is_constant_evaluated()) {
    //   while (first1 != last1) {
    //     ::portable_stl::construct_at(::portable_stl::to_address(first2), ::portable_stl::move(*first1));
    //     ++first1;
    //     ++first2;
    //   }
    //   return first2;
    // } else {
    return ::portable_stl::move(first1, last1, first2);
    // }
  }

} // namespace vector_algo
} // namespace portable_stl

#endif // PSTL_VECTOR_ALGO_H
