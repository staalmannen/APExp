// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iterator_traits.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************

#ifndef PSTL_ITERATOR_TRAITS_H
#define PSTL_ITERATOR_TRAITS_H

#include "../common/ptrdiff_t.h"
#include "../metaprogramming/cv_modifications/remove_cv.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/conditional_bool_constant.h"
#include "../metaprogramming/other_transformations/is_detected.h"
#include "../metaprogramming/pointer_modifications/add_pointer.h"
#include "../metaprogramming/reference_modifications/add_lvalue_reference.h"
#include "concepts/cpp17_random_access_iterator.h"
#include "contiguous_iterator_tag.h"
#include "incrementable_traits.h"
#include "indirectly_readable_traits.h"
#include "iter_reference_t.h"
#include "output_iterator_tag.h"

namespace portable_stl {
namespace iterator_helper {

  // clang-format off

  /**
   * @brief Predicate to check class member.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator> using has_member_iterator_category = typename t_iterator::iterator_category;
  /**
   * @brief Predicate to check class member.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator> using has_member_value_type        = typename t_iterator::value_type;
  /**
   * @brief Predicate to check class member.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator> using has_member_reference         = typename t_iterator::reference;
  /**
   * @brief Predicate to check class member.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator> using has_member_difference_type   = typename t_iterator::difference_type;
  /**
   * @brief Predicate to check class member.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator> using has_member_pointer           = typename t_iterator::pointer;
  // clang-format on
  /**
   * @brief Predicate to check diff type availability.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator> using has_inc_traits_diff = typename incrementable_traits<t_iterator>::difference_type;

  /**
   * @brief Helper to check availability of all base class members.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator>
  using specifies_members
    = ::portable_stl::conjunction<::portable_stl::is_detected<has_member_iterator_category, t_iterator>,
                                  ::portable_stl::is_detected<has_member_value_type, t_iterator>,
                                  ::portable_stl::is_detected<has_member_reference, t_iterator>,
                                  ::portable_stl::is_detected<has_member_difference_type, t_iterator>>;

  /**
   * @brief Helper to select right pointer type.
   * @tparam t_iterator Given iterator type.
   */
  template<class t_iterator, class = ::portable_stl::is_detected<has_member_pointer, t_iterator>>
  class iterator_traits_member_pointer_or_void final {
  public:
    /**
     * @brief Result pointer type.
     */
    using type = typename t_iterator::pointer;
  };

  /**
   * @brief Helper to select right pointer type.
   * @tparam t_iterator Given iterator type.
   */
  template<class t_iterator>
  class iterator_traits_member_pointer_or_void<t_iterator, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result pointer type.
     */
    using type = void;
  };

  /**
   * @brief Helper to select right ref type in case if t_iterator satisfies only the exposition-only concept
   * 'cpp17-input-iterator'
   * @tparam t_iterator Given iterator type.
   */
  template<class t_iterator, class = ::portable_stl::is_detected<has_member_reference, t_iterator>>
  class iterator_traits_member_reference final {
  public:
    /**
     * @brief Result reference type.
     */
    using type = typename t_iterator::reference;
  };

  /**
   * @brief Helper to select right ref type in case if t_iterator satisfies only the exposition-only concept
   * 'cpp17-input-iterator'
   * @tparam t_iterator Given iterator type.
   */
  template<class t_iterator> class iterator_traits_member_reference<t_iterator, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result reference type.
     */
    using type = ::portable_stl::iter_reference_t<t_iterator>;
  };

  /**
   * @brief Helper to select right diff type in case if t_iterator satisfies only the exposition-only concept
   * 'cpp17-iterator'
   * @tparam t_iterator Given iterator type.
   */
  template<class t_iterator, class = ::portable_stl::is_detected<has_inc_traits_diff, t_iterator>>
  class iterator_traits_difference_type final {
  public:
    /**
     * @brief Result difference type.
     */
    using type = typename ::portable_stl::incrementable_traits<t_iterator>::difference_type;
  };

  /**
   * @brief Helper to select right diff type in case if t_iterator satisfies only the exposition-only concept
   * 'cpp17-iterator'
   * @tparam t_iterator Given iterator type.
   */
  template<class t_iterator> class iterator_traits_difference_type<t_iterator, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result difference type.
     */
    using type = void;
  };

  /**
   * @brief Helper to check if type has .operator->()
   * @tparam t_iterator
   */
  template<class t_iterator> class iterator_traits_has_arrow final {
    /**
     * @brief Test function.
     * @tparam T1
     * @return ::portable_stl::true_type
     */
    template<class T1>
    static auto test(::portable_stl::size_t) -> decltype(::portable_stl::declval<T1 &>().operator->(),
                                                         ::portable_stl::true_type{});

    /**
     * @brief Test function.
     * @return ::portable_stl::false_type
     */
    template<class> static auto test(...) -> ::portable_stl::false_type;

  public:
    /**
     * @brief Result type.
     */
    using type = decltype(test<t_iterator>(0));
  };

  /**
   * @brief [iterator.traits]/3.2.1
   * Otherwise, if 'decltype(declval<I&>().operator->())' is well-formed, then 'pointer' names that type.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator, class = typename iterator_traits_has_arrow<t_iterator>::type>
  class iterator_traits_member_pointer_or_arrow_or_void_impl final {
  public:
    /**
     * @brief Result pointer type.
     */
    using type = decltype(::portable_stl::declval<t_iterator &>().operator->());
  };

  /**
   * @brief [iterator.traits]/3.2.1
   * Otherwise, 'pointer' names 'void'.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator>
  class iterator_traits_member_pointer_or_arrow_or_void_impl<t_iterator, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result pointer type.
     */
    using type = void;
  };

  /**
   * @brief [iterator.traits]/3.2.1
   * If the qualified-id 'I::pointer' is valid and denotes a type, 'pointer' names that type.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator, class = ::portable_stl::is_detected<has_member_pointer, t_iterator>>
  class iterator_traits_member_pointer_or_arrow_or_void final {
  public:
    /**
     * @brief Result pointer type.
     */
    using type = typename t_iterator::pointer;
  };

  /**
   * @brief [iterator.traits]/3.2.1
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator>
  class iterator_traits_member_pointer_or_arrow_or_void<t_iterator, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result pointer type.
     */
    using type = typename iterator_traits_member_pointer_or_arrow_or_void_impl<t_iterator>::type;
  };

  /**
   * @brief 'Concept' of legacy-like iterator without base member types.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator>
  using cpp17_iterator_missing_members
    = ::portable_stl::conjunction<::portable_stl::negation<specifies_members<t_iterator>>,
                                  ::portable_stl::negation<cpp17_input_iterator<t_iterator>>,
                                  ::portable_stl::cpp17_iterator<t_iterator>>;

  /**
   * @brief 'Concept' of legacy-like input iterator without base member types.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator>
  using cpp17_input_iterator_missing_members
    = ::portable_stl::conjunction<::portable_stl::negation<specifies_members<t_iterator>>,
                                  ::portable_stl::cpp17_input_iterator<t_iterator>>;

  /**
   * @brief Helper to deduce missed iterator category.
   * Primary template.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator, class = void> class deduce_iterator_category final {
  public:
    /**
     * @brief Result iterator category.
     */
    using type = ::portable_stl::input_iterator_tag;
  };

  /**
   * @brief Helper to deduce missed iterator category.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator>
  class deduce_iterator_category<
    t_iterator,
    ::portable_stl::enable_if_bool_constant_t<::portable_stl::cpp17_random_access_iterator<t_iterator>>>
    final {
  public:
    /**
     * @brief Result iterator category.
     */
    using type = ::portable_stl::random_access_iterator_tag;
  };

  /**
   * @brief Helper to deduce missed iterator category.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator>
  class deduce_iterator_category<t_iterator,
                                 ::portable_stl::enable_if_bool_constant_t<::portable_stl::conjunction<
                                   ::portable_stl::negation<::portable_stl::cpp17_random_access_iterator<t_iterator>>,
                                   ::portable_stl::cpp17_bidirectional_iterator<t_iterator>>>>
    final {
  public:
    /**
     * @brief Result iterator category.
     */
    using type = ::portable_stl::bidirectional_iterator_tag;
  };

  /**
   * @brief Helper to deduce missed iterator category.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator>
  class deduce_iterator_category<t_iterator,
                                 ::portable_stl::enable_if_bool_constant_t<::portable_stl::conjunction<
                                   ::portable_stl::negation<::portable_stl::cpp17_random_access_iterator<t_iterator>>,
                                   ::portable_stl::negation<::portable_stl::cpp17_bidirectional_iterator<t_iterator>>,
                                   ::portable_stl::cpp17_forward_iterator<t_iterator>>>>
    final {
  public:
    /**
     * @brief Result iterator category.
     */
    using type = ::portable_stl::forward_iterator_tag;
  };

  /**
   * @brief [iterator.traits]/3.2.3
   * If the qualified-id 'I::iterator-category' is valid and denotes a type, 'iterator-category' names that type.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator, class = ::portable_stl::is_detected<has_member_iterator_category, t_iterator>>
  class iterator_traits_iterator_category final {
  public:
    /**
     * @brief Result iterator category.
     */
    using type = typename t_iterator::iterator_category;
  };

  /**
   * @brief Helper to deduce missed iterator category.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator> class iterator_traits_iterator_category<t_iterator, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result iterator category.
     */
    using type = typename deduce_iterator_category<t_iterator>::type;
  };

  /**
   * @brief [iterator.traits]/3.4
   * Otherwise, 'iterator_traits<I>' has no members by any of the above names.
   * Primary template.
   * @tparam t_iterator Iterator type.
   */
  template<class t_iterator, class = void> class iterator_traits_impl {};

  /**
   * @brief [iterator.traits]/3.1
   * If 'I' has valid ([temp.deduct]) member types 'difference-type', 'value-type', 'reference', and
   * 'iterator-category', then 'iterator-traits<I>' has the following publicly accessible members:
   * @tparam t_iterator Iterator type.
   */
  template<class t_iterator>
  class iterator_traits_impl<t_iterator, ::portable_stl::enable_if_bool_constant_t<specifies_members<t_iterator>>> {
  public:
    /**
     * @brief The type of iterating object.
     */
    using value_type        = typename t_iterator::value_type;
    /**
     * @brief The type for store difference between two iterators.
     */
    using difference_type   = typename t_iterator::difference_type;
    /**
     * @brief The type of pointer to iterating object.
     */
    using pointer           = typename iterator_traits_member_pointer_or_void<t_iterator>::type;
    /**
     * @brief The type of reference to iterating object.
     */
    using reference         = typename t_iterator::reference;
    /**
     * @brief The type of iterator.
     */
    using iterator_category = typename t_iterator::iterator_category;
  };

  /**
   * @brief [iterator.traits]/3.2
   * Otherwise, if 'I' satisfies the exposition-only concept 'cpp17-input-iterator',
   * 'iterator-traits<I>' has the following publicly accessible members:
   * @tparam t_iterator Iterator type.
   */
  template<class t_iterator>
  class iterator_traits_impl<
    t_iterator,
    ::portable_stl::enable_if_bool_constant_t<cpp17_input_iterator_missing_members<t_iterator>>> {
  public:
    /**
     * @brief The type of iterating object.
     */
    using value_type        = typename ::portable_stl::indirectly_readable_traits<t_iterator>::value_type;
    /**
     * @brief The type for store difference between two iterators.
     */
    using difference_type   = typename ::portable_stl::incrementable_traits<t_iterator>::difference_type;
    /**
     * @brief The type of pointer to iterating object.
     */
    using pointer           = typename iterator_traits_member_pointer_or_arrow_or_void<t_iterator>::type;
    /**
     * @brief The type of reference to iterating object.
     */
    using reference         = typename iterator_traits_member_reference<t_iterator>::type;
    /**
     * @brief The type of iterator.
     */
    using iterator_category = typename iterator_traits_iterator_category<t_iterator>::type;
  };

  /**
   * @brief [iterator.traits]/3.3
   * Otherwise, if 'I' satisfies the exposition-only concept 'cpp17-iterator', then
   * 'iterator_traits<I>' has the following publicly accessible members:
   * @tparam t_iterator Iterator type.
   */
  template<class t_iterator>
  class iterator_traits_impl<t_iterator,
                             ::portable_stl::enable_if_bool_constant_t<cpp17_iterator_missing_members<t_iterator>>> {
  public:
    /**
     * @brief The type of iterating object.
     */
    using value_type        = void;
    /**
     * @brief The type for store difference between two iterators.
     */
    using difference_type   = typename iterator_traits_difference_type<t_iterator>::type;
    /**
     * @brief The type of pointer to iterating object.
     */
    using pointer           = void;
    /**
     * @brief The type of reference to iterating object.
     */
    using reference         = void;
    /**
     * @brief The type of iterator.
     */
    using iterator_category = ::portable_stl::output_iterator_tag;
  };
} // namespace iterator_helper

/**
 * @brief The type trait class that provides uniform interface to the properties of LegacyIterator types.
 * This makes it possible to implement algorithms only in terms of iterators.
 *
 * @tparam t_iterator The iterator type to retrieve properties for.
 */
template<class t_iterator> class iterator_traits final : public iterator_helper::iterator_traits_impl<t_iterator> {
public:
  /**
   * @brief Traits to ckeck if type is a primary template.
   * Used in iter_value_t and iter_difference_t.
   */
  using primary_template_ = iterator_traits;
};

/**
 * @brief The type trait class that provides uniform interface to the properties of LegacyIterator types.
 * This makes it possible to implement algorithms only in terms of iterators.
 * Specification for iterator from pointer.
 *
 * @tparam t_iterator the iterator type to retrieve properties for
 */
template<class t_type>
class iterator_traits<t_type * /*,::portable_stl::enable_if_bool_constant_t<::portable_stl::is_object<t_type>>*/>
  final {
public:
  /**
   * @brief The type of iterating object.
   */
  using value_type        = ::portable_stl::remove_cv_t<t_type>;
  /**
   * @brief The type for store difference between two iterators.
   */
  using difference_type   = ::portable_stl::ptrdiff_t;
  /**
   * @brief The type of reference to iterating object.
   */
  using pointer           = ::portable_stl::add_pointer_t<t_type>;
  /**
   * @brief The type of reference to iterating object.
   */
  using reference         = ::portable_stl::add_lvalue_reference_t<t_type>;
  /**
   * @brief The type of iterator is random_access_iterator.
   */
  using iterator_category = ::portable_stl::random_access_iterator_tag;
  /**
   * @brief (since C++20)
   */
  using iterator_concept  = ::portable_stl::contiguous_iterator_tag;
};

} // namespace portable_stl

#endif /* PSTL_ITERATOR_TRAITS_H */
