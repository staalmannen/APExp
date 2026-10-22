// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="move_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MOVE_ITERATOR_H
#define PSTL_MOVE_ITERATOR_H

#include "../concepts/assignable_from.h"
#include "../concepts/boolean_testable.h"
#include "../concepts/convertible_to.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/conditional_bool_constant.h"
#include "../metaprogramming/other_transformations/decay.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../metaprogramming/type_properties/is_constructible.h"
#include "../metaprogramming/type_properties/is_nothrow_move_constructible.h"
#include "../metaprogramming/type_relations/is_derived_from.h"
#include "../metaprogramming/type_relations/is_same.h"
#include "../utility/general/move.h"
#include "concepts/forward_iterator.h"
#include "concepts/indirectly_swappable.h"
#include "incrementable_traits.h"
#include "iter_move.h"
#include "iter_rvalue_reference_t.h"
#include "iter_swap.h"
#include "iter_value_t.h"
#include "iterator_traits.h"
#include "random_access_iterator_tag.h"

namespace portable_stl {
namespace iterator_helper {
  /**
   * @brief Base for move_iterator with/without iterator_category and iterator_concept.
   */
  template<class, class = void> class move_iterator_base {};

  /**
   * @brief Base for move_iterator with/without iterator_category and iterator_concept.
   *
   * @tparam t_iterator Base iterator type.
   */
  template<class t_iterator>
  class move_iterator_base<
    t_iterator,
    ::portable_stl::void_t<typename ::portable_stl::iterator_traits<t_iterator>::iterator_category>> {
  public:
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
  };

  /**
 * @brief Check operator ==
 * 
 * @tparam t_iter1 
 * @tparam t_iter2 
 */
template<class t_iter1, class t_iter2 = t_iter1>
using is_comparable
  = ::portable_stl::is_same<bool, decltype(::portable_stl::declval<t_iter1>() == ::portable_stl::declval<t_iter2>())>;

} // namespace iterator_helper

/**
 * @brief An iterator adaptor which behaves exactly like the underlying iterator (which must be at least a
 * LegacyInputIterator or model input_iterator(since C++20), or stronger iterator concept(since C++23)), except that
 * dereferencing converts the value returned by the underlying iterator into an rvalue. If this iterator is used as an
 * input iterator, the effect is that the values are moved from, rather than copied from.
 *
 * @tparam t_iterator Base iterator type.
 */
template<class t_iterator>
class move_iterator final : public ::portable_stl::iterator_helper::move_iterator_base<t_iterator> {
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
  using pointer = t_iterator;

  /**
   * @brief Associated reference types of an iterator.
   */
  using reference = ::portable_stl::iter_rvalue_reference_t<t_iterator>;

  /**
   * @brief Constructor.
   * requires is_constructible_v<t_iterator>
   */
  template<::portable_stl::enable_if_bool_constant_t<::portable_stl::is_constructible<t_iterator>, void *> = nullptr>
  constexpr move_iterator() : m_current{} {
  }

  // todo(plotitsyn): add exception test
  /**
   * @brief Constructor.
   * @param iter Given iterator.
   */
  constexpr explicit move_iterator(t_iterator iter) noexcept(
    ::portable_stl::is_nothrow_move_constructible<t_iterator>{}())
      : m_current(::portable_stl::move(iter)) {
  }

  /**
   * @brief Copy constructor from same adaptor.
   */
  constexpr move_iterator(move_iterator const &) = default;

  /**
   * @brief Copy constructor from another move iterator.
   * @tparam t_iterator2 Another adaptor underlying iterator type.
   * @param other Other move_iterator adaptor.
   */
  template<class t_iterator2,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_same<t_iterator2, t_iterator>>,
                                         ::portable_stl::convertible_to<t_iterator2 const &, t_iterator>>,
             void *>
           = nullptr>
  constexpr move_iterator(move_iterator<t_iterator2> const &other) : m_current{other.base()} {
  }

  /**
   * @brief Copy assignment (default).
   * @return move_iterator&
   */
  move_iterator &operator=(move_iterator const &) & = default;

  /**
   * @brief Assignment operator from another move iterator.
   * @tparam u_type Another adaptor base iterator_type.
   * @param other Other move_iterator adaptor.
   * @return constexpr move_iterator&
   */
  template<class t_iterator2,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_same<t_iterator2, t_iterator>>,
                                         ::portable_stl::convertible_to<t_iterator2 const &, t_iterator>,
                                         ::portable_stl::assignable_from<t_iterator &, t_iterator2 const &>>,
             void *>
           = nullptr>
  move_iterator &operator=(move_iterator<t_iterator2> const &other) & {
    m_current = other.base();
    return *this;
  }

  /**
   * @brief Returns the underlying base iterator.
   * @return A reference to the underlying iterator.
   */
  constexpr iterator_type const &base() const & noexcept {
    return m_current;
  }

  /**
   * @brief Returns the underlying base iterator.
   * @return An iterator move constructed from the underlying iterator.
   */
  iterator_type base() && {
    return ::portable_stl::move(m_current);
  }

  /**
   * @brief Accesses the pointed-to element.
   * @return Rvalue-reference to the current element or its copy.
   */
  reference operator*() const {
    return ::portable_stl::ranges::iter_move(m_current);
  }

  /**
   * @brief Accesses an element by index.
   * @param n_value Position relative to current location.
   * @return An rvalue reference to the element at relative location.
   */
  constexpr reference operator[](difference_type n_value) const {
    return ::portable_stl::ranges::iter_move(m_current + n_value);
  }

  /**
   * @brief Pre-increments by one.
   * @return *this.
   */
  move_iterator &operator++() {
    ++m_current;
    return *this;
  }

  /**
   * @brief Post-increments by one.
   * A copy of *this that was made before the change
   * @tparam t_type
   * @return move_iterator
   */
  template<class t_type = t_iterator>
  enable_if_bool_constant_t<::portable_stl::forward_iterator<t_type>, move_iterator> operator++(int) {
    move_iterator tmp{*this};
    ++m_current;
    return tmp;
  }

  /**
   * @brief Post-increments by one.
   * If t_iterator does not model forward_iterator, the post-increment operator does not return such copy and the return
   * type is void.
   * @tparam t_type
   * @return void
   */
  template<class t_type = t_iterator>
  enable_if_bool_constant_t<::portable_stl::negation<::portable_stl::forward_iterator<t_type>>, void> operator++(int) {
    ++m_current;
  }

  /**
   * @brief Pre-decrements by one.
   * @return *this.
   */
  move_iterator &operator--() {
    --m_current;
    return *this;
  }

  /**
   * @brief Post-decrements by one.
   * @return *this.
   */
  move_iterator operator--(int) {
    move_iterator tmp{*this};
    --m_current;
    return tmp;
  }

  /**
   * @brief Returns an iterator which is advanced by n_value positions.
   * @param n_value Position relative to current location.
   * @return Iterator which is advanced by n_value positions.
   */
  move_iterator operator+(difference_type n_value) const {
    move_iterator tmp{m_current};
    return tmp += n_value;
  }

  /**
   * @brief Advances the iterator by n positions.
   * @param n_value Position relative to current location.
   * @return *this
   */
  move_iterator &operator+=(difference_type n_value) & {
    m_current += n_value;
    return *this;
  }

  /**
   * @brief Returns an iterator which is advanced by -n_value positions.
   * @param n_value Position relative to current location.
   * @return Iterator which is advanced by -n_value positions.
   */
  move_iterator operator-(difference_type n_value) const {
    move_iterator tmp{m_current};
    return tmp -= n_value;
  }

  /**
   * @brief Advances the iterator by -n positions.
   * @param n_value Position relative to current location.
   * @return *this
   */
  move_iterator &operator-=(difference_type n_value) & {
    m_current -= n_value;
    return *this;
  }

  // todo(plotitsyn):
  // template<sentinel_for<t_iterator> S>
  // friend constexpr bool operator==(move_iterator const &x, move_sentinel<S> const &y);
  // template<sized_sentinel_for<t_iterator> S>
  // friend constexpr iter_difference_t<t_iterator> operator-(move_sentinel<S> const &x, move_iterator const &y);
  // template<sized_sentinel_for<t_iterator> S>
  // friend constexpr iter_difference_t<t_iterator>       operator-(move_iterator const &x, move_sentinel<S> const &y);

  /**
   * @brief Casts the result of dereferencing the underlying iterator to its associated rvalue reference type.
   *
   * This function template is not visible to ordinary unqualified or qualified lookup, and can only be found by
   * argument-dependent lookup when move_iterator<t_iterator> is an associated class of the arguments.
   * @param iter A source move iterator.
   * @return An rvalue reference or a prvalue temporary.
   */
  friend constexpr iter_rvalue_reference_t<t_iterator> iter_move(move_iterator const &iter) noexcept(
    noexcept(::portable_stl::ranges::iter_move(iter.m_current))) {
    return ::portable_stl::ranges::iter_move(iter.m_current);
  }

  /**
   * @brief Swaps the objects pointed to by two underlying iterators. The function body is equivalent to
   * ranges::iter_swap(x.base(), y.base());.
   *
   * This function template is not visible to ordinary unqualified or qualified lookup, and can only be found by
   * argument-dependent lookup when move_iterator<t_iterator> is an associated class of the arguments.
   * @tparam t_iterator2
   * @param iter1 Move iterator to the elements to swap.
   * @param iter2 Move iterator to the elements to swap.
   * @return void
   */
  template<class t_iterator2>
  friend constexpr auto iter_swap(move_iterator const &iter1, move_iterator<t_iterator2> const &iter2) noexcept(
    noexcept(::portable_stl::ranges::iter_swap2(iter1.m_current, iter2.m_current)))
    -> ::portable_stl::enable_if_bool_constant_t<::portable_stl::indirectly_swappable<t_iterator, t_iterator2>, void> {
    return ::portable_stl::ranges::iter_swap2(iter1.m_current, iter2.m_current);
  }
};

// todo(plotitsyn):
// template<sentinel_for<t_iterator> S> friend constexpr bool operator==(move_iterator const &x, move_sentinel<S> const
// &y);

/**
 * @brief brief Compares the underlying iterators.
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
         class t_iterator2,
         class = ::portable_stl::enable_if_bool_constant<iterator_helper::is_comparable<t_iterator1, t_iterator2>>>
constexpr bool operator==(move_iterator<t_iterator1> const &lhs, move_iterator<t_iterator2> const &rhs) {
  return lhs.base() == rhs.base();
};

/**
 * @brief Compares the underlying iterators.
 * Only participate in overload resolution if their underlying comparison expressions ==,!=,>,>=,... are well-formed and
 * convertible to bool.
 *
 * @tparam t_iterator1 The type of the iterator.
 * @tparam t_iterator2 The type of the iterator.
 * @param lhs The iterator adaptor to compare.
 * @param rhs The iterator adaptor to compare.
 * @return true - underlying iterators are not equal.
 * @return false - underlying iterators are equal.
 */
template<class t_iterator1,
         class t_iterator2,
         class = ::portable_stl::enable_if_bool_constant<iterator_helper::is_comparable<t_iterator1, t_iterator2>>>
constexpr bool operator!=(move_iterator<t_iterator1> const &lhs, move_iterator<t_iterator2> const &rhs) {
  return !(lhs == rhs);
};

// todo(plotitsyn): maybe <,<=,>,>= should be rewritten as == and != (msvc)

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
 * @return true - lhs.base() < rhs.base().
 * @return false - !(lhs.base() < rhs.base()).
 */
template<class t_iterator1,
         class t_iterator2,
         class t_iter_base1 = decltype(::portable_stl::declval<move_iterator<t_iterator1>>().base()),
         class t_iter_base2 = decltype(::portable_stl::declval<move_iterator<t_iterator2>>().base()),
         class              = ::portable_stl::enable_if_bool_constant_t<::portable_stl::convertible_to<
                        decltype(::portable_stl::declval<t_iter_base1>() < ::portable_stl::declval<t_iter_base1>()),
                        bool>>>
constexpr bool operator<(move_iterator<t_iterator1> const &lhs, move_iterator<t_iterator2> const &rhs) {
  return lhs.base() < rhs.base();
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
 * @return true - lhs.base() > rhs.base().
 * @return false - !(lhs.base() > rhs.base()).
 */
template<class t_iterator1,
         class t_iterator2,
         class t_iter_base1 = decltype(::portable_stl::declval<move_iterator<t_iterator1>>().base()),
         class t_iter_base2 = decltype(::portable_stl::declval<move_iterator<t_iterator2>>().base()),
         class              = ::portable_stl::enable_if_bool_constant_t<::portable_stl::convertible_to<
                        decltype(::portable_stl::declval<t_iter_base1>() > ::portable_stl::declval<t_iter_base1>()),
                        bool>>>
constexpr bool operator>(move_iterator<t_iterator1> const &lhs, move_iterator<t_iterator2> const &rhs) {
  return lhs.base() > rhs.base();
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
 * @return true - lhs.base() <= rhs.base().
 * @return false - !(lhs.base() <= rhs.base()).
 */
template<class t_iterator1,
         class t_iterator2,
         class t_iter_base1 = decltype(::portable_stl::declval<move_iterator<t_iterator1>>().base()),
         class t_iter_base2 = decltype(::portable_stl::declval<move_iterator<t_iterator2>>().base()),
         class              = ::portable_stl::enable_if_bool_constant_t<::portable_stl::convertible_to<
                        decltype(::portable_stl::declval<t_iter_base1>() <= ::portable_stl::declval<t_iter_base1>()),
                        bool>>>
constexpr bool operator<=(move_iterator<t_iterator1> const &lhs, move_iterator<t_iterator2> const &rhs) {
  return lhs.base() <= rhs.base();
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
 * @return true - lhs.base() >= rhs.base().
 * @return false - !(lhs.base() >= rhs.base()).
 */
template<class t_iterator1,
         class t_iterator2,
         class t_iter_base1 = decltype(::portable_stl::declval<move_iterator<t_iterator1>>().base()),
         class t_iter_base2 = decltype(::portable_stl::declval<move_iterator<t_iterator2>>().base()),
         class              = ::portable_stl::enable_if_bool_constant_t<::portable_stl::convertible_to<
                        decltype(::portable_stl::declval<t_iter_base1>() >= ::portable_stl::declval<t_iter_base1>()),
                        bool>>>
constexpr bool operator>=(move_iterator<t_iterator1> const &lhs, move_iterator<t_iterator2> const &rhs) {
  return lhs.base() >= rhs.base();
};

/**
 * @brief Returns the iterator it incremented by n.
 * This overload participates in overload resolution only if iter.base() + n_value is well-formed and has type
 * t_iterator.
 * @tparam t_iterator Underlying iterator type.
 * @param n_value the number of positions to increment the iterator.
 * @param iter The iterator adaptor to increment.
 * @return The incremented iterator.
 */
template<class t_iterator,
         ::portable_stl::enable_if_bool_constant_t<
           ::portable_stl::is_same<t_iterator,
                                   decltype(declval<::portable_stl::move_iterator<t_iterator> &>().base() +
                                            typename ::portable_stl::move_iterator<t_iterator>::difference_type{})>,
           void *>
         = nullptr>
constexpr inline move_iterator<t_iterator> operator+(typename move_iterator<t_iterator>::difference_type n_value,
                                                     move_iterator<t_iterator> const                    &iter) {
  return move_iterator<t_iterator>(iter.base() + n_value);
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
constexpr inline auto operator-(move_iterator<t_iterator1> const &lhs,
                                move_iterator<t_iterator2> const &rhs) -> decltype(lhs.base() - rhs.base()) {
  return lhs.base() - rhs.base();
}

/**
 * @brief A convenience function template that constructs a move_iterator for the given iterator iter with the type
 * deduced from the type of the argument.
 *
 * @tparam t_iterator Given iterator type.
 * @param iter Given iterator to be converted to move iterator.
 * @return A move_iterator which can be used to move from the elements accessed through iter.
 */
template<class t_iterator> constexpr inline move_iterator<t_iterator> make_move_iterator(t_iterator iter) {
  return move_iterator<t_iterator>(::portable_stl::move(iter));
}

} // namespace portable_stl

#endif // PSTL_MOVE_ITERATOR_H
