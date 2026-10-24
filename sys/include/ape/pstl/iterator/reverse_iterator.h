// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="reverse_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_REVERSE_ITERATOR_H
#define PSTL_REVERSE_ITERATOR_H

#include "../concepts/assignable_from.h"
// #include "../concepts/convertible_to.h"
#include "../memory/addressof.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/conditional_bool_constant.h"
#include "../metaprogramming/type_properties/is_assignable.h"
#include "../metaprogramming/type_properties/is_constructible.h"
#include "../metaprogramming/type_properties/is_nothrow_copy_constructible.h"
#include "../metaprogramming/type_relations/is_convertible.h"
#include "../metaprogramming/type_relations/is_derived_from.h"
#include "../metaprogramming/type_relations/is_same.h"
#include "concepts/indirectly_swappable.h"
#include "incrementable_traits.h"
#include "iter_move.h"
#include "iter_reference_t.h"
#include "iter_rvalue_reference_t.h"
#include "iter_swap.h"
#include "iter_value_t.h"
#include "iterator_traits.h"

namespace portable_stl {
/**
 * @brief Iterator adaptor that reverses the direction of a given iterator.
 * @tparam t_iterator the given iterator type.
 */
template<class t_iterator> class reverse_iterator final {
  /**
   * @brief The underlying iterator of which base() returns a copy.
   */
  t_iterator m_current;

public:
  /**
   * @brief Base itareator type.
   */
  using iterator_type = t_iterator;

  /**
   * @brief Iterator categoty.
   */
  using iterator_category = typename ::portable_stl::conditional_bool_constant_t<
    ::portable_stl::is_derived_from<typename ::portable_stl::iterator_traits<t_iterator>::iterator_category,
                                    ::portable_stl::random_access_iterator_tag>,
    ::portable_stl::random_access_iterator_tag,
    typename ::portable_stl::iterator_traits<t_iterator>::iterator_category>;

  /**
   * @brief Iterator concept.
   */
  using iterator_concept = iterator_category;

  /**
   * @brief Associated value types of an iterator.
   */
  using value_type = ::portable_stl::iter_value_t<t_iterator>;

  /**
   * @brief Associated difference types of an iterator.
   */
  using difference_type = ::portable_stl::iter_difference_t<t_iterator>;

  /**
   * @brief Associated pointer types of an iterator.
   */
  using pointer = typename ::portable_stl::iterator_traits<t_iterator>::pointer;

  /**
   * @brief Associated reference types of an iterator.
   */
  using reference = ::portable_stl::iter_reference_t<t_iterator>;

  /**
   * @brief Constructor.
   * requires is_constructible_v<t_iterator>
   */
  template<::portable_stl::enable_if_bool_constant_t<::portable_stl::is_constructible<t_iterator>, void *> = nullptr>
  constexpr reverse_iterator() : m_current{} {
  }

  /**
   * @brief Constructor.
   * @param iter Iterator to make from.
   */
  constexpr explicit reverse_iterator(t_iterator iter) noexcept(
    ::portable_stl::is_nothrow_copy_constructible<t_iterator>{}())
      : m_current{iter} {
  }

  /**
   * @brief Copy constructor from same adaptor.
   * @param other Iterator adaptor to copy from.
   */
  constexpr reverse_iterator(reverse_iterator const &other) = default;

  /**
   * @brief Copy constructor from another reverse iterator.
   * t_iterator_other should be convertible to t_iterator.
   * @tparam t_iterator2 Another adaptor underlying iterator type.
   * @param other Iterator adaptor to copy from.
   */
  template<class t_iterator2,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_same<t_iterator2, t_iterator>>,
                                         ::portable_stl::is_convertible<t_iterator2 const &, t_iterator>>,
             void *>
           = nullptr>
  constexpr reverse_iterator(reverse_iterator<t_iterator2> const &other) : m_current{other.base()} {
  }

  /**
   * @brief Assignment from another reverse iterator (default).
   * @return reverse_iterator&
   */
  reverse_iterator &operator=(reverse_iterator const &) & = default;

  /**
   * @brief Assignment from another reverse iterator.
   * t_iterator_other should be convertible to t_iterator and t_iterator should be assignable from t_iterator_other.
   * @tparam t_iterator2 Another adaptor underlying iterator type.
   * @param other Iterator adaptor to copy from.
   */
  template<class t_iterator2,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_same<t_iterator2, t_iterator>>,
                                         ::portable_stl::is_convertible<t_iterator2 const &, t_iterator>,
                                         ::portable_stl::is_assignable<t_iterator &, t_iterator2 const &>>,
             void *>
           = nullptr>
  reverse_iterator &operator=(reverse_iterator<t_iterator2> const &other) & {
    m_current = other.base();
    return *this;
  }

  /**
   * @brief The underlying iterator.
   * @return constexpr t_iterator.
   */
  constexpr t_iterator base() const {
    return m_current;
  }

  /**
   * @brief Returns a reference or pointer to the element previous to current.
   * @return constexpr reference Reference or pointer to the element previous to current.
   */
  reference operator*() const {
    t_iterator tmp{m_current};
    return *--tmp;
  }

  /**
   * @brief Returns a reference or pointer to the element previous to current.
   *
   * TODO see https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator*
   * @return constexpr reference Reference or pointer to the element previous to current.
   */
  template<class...> constexpr pointer operator->() const {
    return ::portable_stl::addressof(operator*());
  }

  /**
   * @brief Pre-increments by one.
   *
   * @return constexpr reverse_iterator&
   */
  reverse_iterator &operator++() {
    --m_current;
    return *this;
  }

  /**
   * @brief Post-increments by one.
   *
   * @return constexpr reverse_iterator&
   */
  reverse_iterator operator++(int) {
    reverse_iterator tmp{*this};
    --m_current;
    return tmp;
  }

  /**
   * @brief Pre-decrements by one.
   *
   * @return constexpr reverse_iterator&
   */
  reverse_iterator &operator--() {
    ++m_current;
    return *this;
  }

  /**
   * @brief Post-decrements by one.
   *
   * @return constexpr reverse_iterator&
   */
  reverse_iterator operator--(int) {
    reverse_iterator tmp{*this};
    ++m_current;
    return tmp;
  }

  /**
   * @brief Returns an iterator which is advanced by n_value positions.
   * @param n_value Position relative to current location.
   * @return
   */
  reverse_iterator operator+(difference_type n_value) const {
    reverse_iterator tmp{m_current};
    return tmp += n_value;
  }

  /**
   * @brief Advances the iterator by n_value positions.
   * @param n_value Position relative to current location.
   * @return
   */
  reverse_iterator &operator+=(difference_type n_value) & {
    m_current -= n_value;
    return *this;
  }

  /**
   * @brief Returns an iterator which is advanced by -n_value positions.
   * @param n_value Position relative to current location.
   * @return
   */
  reverse_iterator operator-(difference_type n_value) const {
    reverse_iterator tmp{m_current};
    return tmp -= n_value;
  }

  /**
   * @brief Advances the iterator by -n_value positions.
   * @param n_value Position relative to current location.
   * @return
   */
  reverse_iterator &operator-=(difference_type n_value) & {
    m_current += n_value;
    return *this;
  }

  /**
   * @brief Returns a reference to the element at specified relative location.
   * @param n_value Position relative to current location.
   */
  constexpr reference operator[](difference_type n_value) const {
    return *(*this + n_value);
  }

  /**
   * @brief Casts the result of dereferencing the adjusted underlying iterator to its associated rvalue reference type.
   *
   * @param iter A source reverse iterator.
   * @return An rvalue reference or a prvalue temporary.
   */
  friend iter_rvalue_reference_t<t_iterator> iter_move(reverse_iterator const &iter) noexcept(
    ::portable_stl::is_nothrow_copy_constructible<t_iterator>{}() && //
    noexcept(::portable_stl::ranges::iter_move(--::portable_stl::declval<t_iterator &>()))) {
    auto tmp = iter.base();
    return ::portable_stl::ranges::iter_move(--tmp);
  }

  /**
   * @brief Swaps the objects pointed to by two adjusted underlying iterators.
   *
   * @tparam t_iterator2
   * @param iter1 Reverse iterator to the elements to swap.
   * @param iter2 Reverse iterator to the elements to swap.
   * @return void
   */
  template<class t_iterator2>
  friend auto iter_swap(
    reverse_iterator const &iter1,
    ::portable_stl::reverse_iterator<t_iterator2> const
      &iter2) noexcept(::portable_stl::is_nothrow_copy_constructible<t_iterator>{}() &&  //
                       ::portable_stl::is_nothrow_copy_constructible<t_iterator2>{}() && //
                       noexcept(::portable_stl::ranges::iter_swap2(--::portable_stl::declval<t_iterator &>(),
                                                                   --::portable_stl::declval<t_iterator2 &>())))
    -> ::portable_stl::enable_if_bool_constant_t<::portable_stl::indirectly_swappable<t_iterator, t_iterator2>, void> {
    auto tmp_1 = iter1.base();
    auto tmp_2 = iter2.base();
    ::portable_stl::ranges::iter_swap2(--tmp_1, --tmp_2);
  }
};

/**
 * @brief Compares the underlying iterators.
 * Only participate in overload resolution if their underlying comparison expressions ==,!=,>,>=,... are well-formed and
 * convertible to bool.
 *
 * @tparam t_iterator1 The type of the iterator.
 * @tparam t_iterator2 The type of the iterator.
 * @tparam t_iter_base1 The underlying type of the t_iterator1.
 * @tparam t_iter_base2 The underlying type of the t_iterator2.
 * @param lhs The iterator adaptor to compare.
 * @param rhs The iterator adaptor to compare.
 * @return true - underlying iterators are equal.
 * @return false - underlying iterators are not equal.
 */
template<class t_iterator1,
         class t_iterator2>
        //  class t_iter_base1 = decltype(::portable_stl::declval<reverse_iterator<t_iterator1>>().base()),
        //  class t_iter_base2 = decltype(::portable_stl::declval<reverse_iterator<t_iterator2>>().base()),
        //  class              = ::portable_stl::enable_if_bool_constant_t<::portable_stl::convertible_to<
        //                 decltype(::portable_stl::declval<t_iter_base1&>() == ::portable_stl::declval<t_iter_base1&>()),
        //                 bool>>>
constexpr bool operator==(reverse_iterator<t_iterator1> const &lhs, reverse_iterator<t_iterator2> const &rhs) noexcept {
  return lhs.base() == rhs.base();
}

/**
 * @brief Compares the underlying iterators.
 * Only participate in overload resolution if their underlying comparison expressions ==,!=,>,>=,... are well-formed and
 * convertible to bool.
 *
 * @tparam t_iterator1 The type of the iterator.
 * @tparam t_iterator2 The type of the iterator.
 * @param lhs The iterator adaptor to compare.
 * @param rhs The iterator adaptor to compare.
 * @return true - underlying iterators are equal.
 * @return false - underlying iterators are not equal.
 */
template<class t_iterator1,
         class t_iterator2>
        //  class t_iter_base1 = decltype(::portable_stl::declval<reverse_iterator<t_iterator1>>().base()),
        //  class t_iter_base2 = decltype(::portable_stl::declval<reverse_iterator<t_iterator2>>().base()),
        //  class              = ::portable_stl::enable_if_bool_constant_t<::portable_stl::convertible_to<
        //                 decltype(::portable_stl::declval<t_iter_base1&>() == ::portable_stl::declval<t_iter_base2&>()),
        //                 bool>>>
constexpr bool operator!=(reverse_iterator<t_iterator1> const &lhs, reverse_iterator<t_iterator2> const &rhs) noexcept {
  return !(lhs == rhs);
}

/**
 * @brief Compares the underlying iterators.
 * Only participate in overload resolution if their underlying comparison expressions ==,!=,>,>=,... are well-formed and
 * convertible to bool.
 *
 * @tparam t_iterator1 The type of the iterator.
 * @tparam t_iterator2 The type of the iterator.
 * @tparam t_iter_base1 The underlying type of the t_iterator1.
 * @tparam t_iter_base2 The underlying type of the t_iterator2.
 * @param lhs The iterator adaptor to compare.
 * @param rhs The iterator adaptor to compare.
 * @return true - underlying iterators are equal.
 * @return false - underlying iterators are not equal.
 */
template<class t_iterator1,
         class t_iterator2>
        //  class t_iter_base1 = decltype(::portable_stl::declval<reverse_iterator<t_iterator1>>().base()),
        //  class t_iter_base2 = decltype(::portable_stl::declval<reverse_iterator<t_iterator2>>().base()),
        //  class              = ::portable_stl::enable_if_bool_constant_t<::portable_stl::convertible_to<
        //                 decltype(::portable_stl::declval<t_iter_base1>() > ::portable_stl::declval<t_iter_base2>()),
        //                 bool>>>
constexpr bool operator>(reverse_iterator<t_iterator1> const &lhs, reverse_iterator<t_iterator2> const &rhs) noexcept {
  return lhs.base() > rhs.base();
}

/**
 * @brief Compares the underlying iterators.
 * Only participate in overload resolution if their underlying comparison expressions ==,!=,>,>=,... are well-formed and
 * convertible to bool.
 *
 * @tparam t_iterator1 The type of the iterator.
 * @tparam t_iterator2 The type of the iterator.
 * @tparam t_iter_base1 The underlying type of the t_iterator1.
 * @tparam t_iter_base2 The underlying type of the t_iterator2.
 * @param lhs The iterator adaptor to compare.
 * @param rhs The iterator adaptor to compare.
 * @return true - underlying iterators are equal.
 * @return false - underlying iterators are not equal.
 */
template<class t_iterator1,
         class t_iterator2>
        //  class t_iter_base1 = decltype(::portable_stl::declval<reverse_iterator<t_iterator1>>().base()),
        //  class t_iter_base2 = decltype(::portable_stl::declval<reverse_iterator<t_iterator2>>().base()),
        //  class              = ::portable_stl::enable_if_bool_constant_t<::portable_stl::convertible_to<
        //                 decltype(::portable_stl::declval<t_iter_base1>() < ::portable_stl::declval<t_iter_base2>()),
        //                 bool>>>
constexpr bool operator<(reverse_iterator<t_iterator1> const &lhs, reverse_iterator<t_iterator2> const &rhs) noexcept {
  return lhs.base() < rhs.base();
}

/**
 * @brief Compares the underlying iterators.
 * Only participate in overload resolution if their underlying comparison expressions ==,!=,>,>=,... are well-formed and
 * convertible to bool.
 *
 * @tparam t_iterator1 The type of the iterator.
 * @tparam t_iterator2 The type of the iterator.
 * @tparam t_iter_base1 The underlying type of the t_iterator1.
 * @tparam t_iter_base2 The underlying type of the t_iterator2.
 * @param lhs The iterator adaptor to compare.
 * @param rhs The iterator adaptor to compare.
 * @return true - underlying iterators are equal.
 * @return false - underlying iterators are not equal.
 */
template<class t_iterator1,
         class t_iterator2>
        //  class t_iter_base1 = decltype(::portable_stl::declval<reverse_iterator<t_iterator1>>().base()),
        //  class t_iter_base2 = decltype(::portable_stl::declval<reverse_iterator<t_iterator2>>().base()),
        //  class              = ::portable_stl::enable_if_bool_constant_t<::portable_stl::convertible_to<
        //                 decltype(::portable_stl::declval<t_iter_base1>() >= ::portable_stl::declval<t_iter_base2>()),
        //                 bool>>>
constexpr bool operator>=(reverse_iterator<t_iterator1> const &lhs, reverse_iterator<t_iterator2> const &rhs) noexcept {
  return lhs.base() >= rhs.base();
}

/**
 * @brief Compares the underlying iterators.
 * Only participate in overload resolution if their underlying comparison expressions ==,!=,>,>=,... are well-formed and
 * convertible to bool.
 *
 * @tparam t_iterator1 The type of the iterator.
 * @tparam t_iterator2 The type of the iterator.
 * @tparam t_iter_base1 The underlying type of the t_iterator1.
 * @tparam t_iter_base2 The underlying type of the t_iterator2.
 * @param lhs The iterator adaptor to compare.
 * @param rhs The iterator adaptor to compare.
 * @return true - underlying iterators are equal.
 * @return false - underlying iterators are not equal.
 */
template<class t_iterator1,
         class t_iterator2>
        //  class t_iter_base1 = decltype(::portable_stl::declval<reverse_iterator<t_iterator1>>().base()),
        //  class t_iter_base2 = decltype(::portable_stl::declval<reverse_iterator<t_iterator2>>().base()),
        //  class              = ::portable_stl::enable_if_bool_constant_t<::portable_stl::convertible_to<
        //                 decltype(::portable_stl::declval<t_iter_base1>() <= ::portable_stl::declval<t_iter_base2>()),
        //                 bool>>>
constexpr bool operator<=(reverse_iterator<t_iterator1> const &lhs, reverse_iterator<t_iterator2> const &rhs) noexcept {
  return lhs.base() <= rhs.base();
}

/**
 * @brief Returns the iterator iter incremented by n_value.
 *
 * @tparam t_iterator Underlying iterator type.
 * @param n_value The number of positions to increment the iterator.
 * @param iter The iterator adaptor to increment.
 * @return The incremented iterator.
 */
template<class t_iterator>
reverse_iterator<t_iterator> operator+(typename reverse_iterator<t_iterator>::difference_type n_value,
                                       reverse_iterator<t_iterator> const                    &iter) {
  return reverse_iterator<t_iterator>(iter.base() - n_value);
}

/**
 * @brief Returns the distance between two iterator adaptors.
 *
 * @tparam t_iterator2 The base iterator type.
 * @tparam t_iterator1 The base iterator type.
 * @param lhs Iterator adaptor to compute the difference of.
 * @param rhs Iterator adaptor to compute the difference of.
 * @return The distance between two iterator adaptors.
 */
template<class t_iterator1, class t_iterator2>
constexpr auto operator-(reverse_iterator<t_iterator1> const &lhs,
                         reverse_iterator<t_iterator2> const &rhs) -> decltype(rhs.base() - lhs.base()) {
  return rhs.base() - lhs.base();
}

/**
 * @brief Convenience function template that constructs a reverse_iterator for the given iterator iter (which must be a
 * LegacyBidirectionalIterator) with the type deduced from the type of the argument.
 *
 * @tparam t_iterator The implicit type of the given iterator.
 * @param iter Iterator to be converted to reverse iterator
 * @return A reverse_iterator constructed from iter.
 */
template<class t_iterator> constexpr reverse_iterator<t_iterator> make_reverse_iterator(t_iterator iter) {
  return reverse_iterator<t_iterator>(iter);
}

} // namespace portable_stl

#endif // PSTL_REVERSE_ITERATOR_H
