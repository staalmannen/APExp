// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_const_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BASIC_CONST_ITERATOR_H
#define PSTL_BASIC_CONST_ITERATOR_H

#include "../concepts/convertible_to.h"
#include "../concepts/default_initializable.h"
#include "../concepts/same_as.h"
#include "../concepts/totally_ordered_with.h"
#include "../memory/addressof.h"
#include "../memory/to_address.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/conditional_bool_constant.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/remove_cvref.h"
#include "../metaprogramming/primary_type/is_lvalue_reference.h"
#include "../metaprogramming/type_properties/is_nothrow_constructible.h"
#include "../metaprogramming/type_properties/is_nothrow_copy_constructible.h"
#include "../metaprogramming/type_properties/is_nothrow_move_constructible.h"
#include "../metaprogramming/type_relations/is_nothrow_convertible.h"
#include "../utility/general/forward.h"
#include "../utility/general/move.h"
#include "concepts/bidirectional_iterator.h"
#include "concepts/contiguous_iterator.h"
#include "concepts/forward_iterator.h"
#include "concepts/input_iterator.h"
#include "concepts/random_access_iterator.h"
#include "concepts/sentinel_for.h"
#include "concepts/sized_sentinel_for.h"
#include "constant_iterator.h"
#include "contiguous_iterator_tag.h"
#include "iter_const_reference_t.h"
#include "iter_reference_t.h"
#include "iterator_traits.h"

namespace portable_stl {

/**
 * @brief basic_const_iterator forward declaration.
 */
template<class, class> class basic_const_iterator;

namespace iterator_helper {
  /**
   * @brief Helper to compares a basic_const_iterator with another types.
   * @tparam t_type1 Given type.
   * @tparam t_type2 Given type.
   */
  template<class t_type1, class t_type2>
  using different_from = ::portable_stl::negation<
    same_as<::portable_stl::remove_cvref_t<t_type1>, ::portable_stl::remove_cvref_t<t_type2>>>;

  /**
   * @brief not_a_const_iterator implementation.
   * @tparam t_type Given type.
   */
  template<typename t_type> class is_const_iterator_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief not_a_const_iterator implementation.
   * @tparam t_type Given type.
   */
  template<typename t_type>
  class is_const_iterator_impl<
    basic_const_iterator<t_type, ::portable_stl::enable_if_bool_constant_t<::portable_stl::input_iterator<t_type>>>>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::true_type;
  };

  /**
   * @brief t_type satisfies the exposition-only 'concept' not-a-const-iterator if and only if it's not a specialization
   * of basic_const_iterator.
   * @tparam t_type Given type.
   */
  template<typename t_type>
  using not_a_const_iterator = ::portable_stl::negation<typename is_const_iterator_impl<t_type>::type>;

  /**
   * @brief
   *  _Fake_copy_init<T>(E):
   * (1) has type T [decay_t<decltype((E))> if T is deduced],
   * (2) is well-formed if and only if E is implicitly convertible to T and T is destructible, and
   * (3) is non-throwing if and only if both conversion from decltype((E)) to T and destruction of T are non-throwing.
   *
   * @tparam t_type
   * @return t_type
   */
  template<class t_type> t_type _Fake_copy_init(t_type) noexcept;

} // namespace iterator_helper

/**
 * @brief basic_const_iterator base, if t_iterator models forward_iterator
 * Primary template.
 * @tparam t_iterator Given iterator type.
 */
template<class t_iterator, class = ::portable_stl::forward_iterator<t_iterator>> class basic_const_iterator_base {
public:
  /**
   * @brief The type of iterator adapter.
   */
  using iterator_category = typename ::portable_stl::iterator_traits<t_iterator>::iterator_category;
};

/**
 * @brief basic_const_iterator base with no iterator_category.
 * @tparam t_iterator Given iterator type.
 */
template<class t_iterator> class basic_const_iterator_base<t_iterator, ::portable_stl::false_type> {};

/**
 * @brief basic_const_iterator is an iterator adaptor which behaves exactly like the underlying iterator (which
 * must be at least an LegacyInputIterator or model input_iterator), except that dereferencing converts the value
 * returned by the underlying iterator as immutable.
 *
 * @tparam t_iterator Given base iterator type.
 */
template<class t_iterator,
         class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::input_iterator<t_iterator>>>
class basic_const_iterator final : public basic_const_iterator_base<t_iterator> {
  /**
   * @brief The underlying iterator from which base() copies or moves.
   */
  t_iterator m_current;

  /**
   * @brief
   * [const.iterators.types]
   * @tparam t_iterator
   */
  using iterator_concept_selection = ::portable_stl::conditional_bool_constant_t<
    ::portable_stl::contiguous_iterator<t_iterator>,
    ::portable_stl::contiguous_iterator_tag,
    ::portable_stl::conditional_bool_constant_t<
      ::portable_stl::random_access_iterator<t_iterator>,
      ::portable_stl::random_access_iterator_tag,
      ::portable_stl::conditional_bool_constant_t<
        ::portable_stl::bidirectional_iterator<t_iterator>,
        ::portable_stl::bidirectional_iterator_tag,
        ::portable_stl::conditional_bool_constant_t<::portable_stl::forward_iterator<t_iterator>,
                                                    ::portable_stl::forward_iterator_tag,
                                                    ::portable_stl::input_iterator_tag>>>>;

  /**
   * @brief Reference type.
   * in MSVC private typenames are visible in SFINAE constructions,
   * so rename reference type reference->t_reference_private
   */
  using t_reference_private = ::portable_stl::iter_const_reference_t<t_iterator>;

public:
  /**
   * @brief Adapter concept.
   */
  using iterator_concept = iterator_concept_selection;
  /**
   * @brief The type of iterating object.
   */
  using value_type       = ::portable_stl::iter_value_t<t_iterator>;
  /**
   * @brief The type for store difference between two iterators.
   */
  using difference_type  = ::portable_stl::iter_difference_t<t_iterator>;

  /**
   * @brief Default constructor.
   * The underlying iterator is value-initialized.
   */
  template<::portable_stl::enable_if_bool_constant_t<::portable_stl::default_initializable<t_iterator>, void *>
           = nullptr>
  basic_const_iterator() : m_current{} {
  }

  /**
   * @brief Constructor.
   * The underlying iterator is initialized with move(x).
   * @param iter Iterator to 'grab'.
   */
  constexpr basic_const_iterator(t_iterator iter) noexcept(
    ::portable_stl::is_nothrow_move_constructible<t_iterator>{}())
      : m_current{::portable_stl::move(iter)} {
  }

  // template<class t_other_iter,
  //          ::portable_stl::enable_if_bool_constant_t<
  //            ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_same<t_other_iter, t_iterator>>,
  //                                        ::portable_stl::convertible_to<t_other_iter, t_iterator>>,
  //            void *>
  //          = nullptr>

  /**
   * @brief Constructor.
   * @tparam t_other_iter Other convertible iterator type.
   * @param other Other iterator itself.
   */
  template<class t_other_iter,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::convertible_to<t_other_iter, t_iterator>, void *>
           = nullptr>
  constexpr basic_const_iterator(basic_const_iterator<t_other_iter> other) noexcept(
    ::portable_stl::is_nothrow_constructible<t_iterator, t_other_iter>{}())
      : m_current{::portable_stl::move(other.m_current)} {
  }

  /**
   * @brief Constructor.
   * @tparam t_other_iter Other type.
   * @param other Other object to construct from.
   */
  template<class t_other,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<iterator_helper::different_from<t_other, basic_const_iterator>,
                                         ::portable_stl::convertible_to<t_other, t_iterator>>,
             void *>
           = nullptr>
  constexpr basic_const_iterator(t_other &&other) noexcept(
    ::portable_stl::is_nothrow_constructible<t_iterator, t_other>{}())
      : m_current{::portable_stl::forward<t_other>(other)} {
  }

  /**
   * @brief Returns the underlying base iterator.
   * @return A reference to the underlying iterator.
   */
  constexpr t_iterator const &base() const & noexcept {
    return m_current;
  }

  /**
   * @brief Returns the underlying base iterator.
   * @return An iterator move constructed from the underlying iterator.
   */
  t_iterator base() && noexcept(::portable_stl::is_nothrow_move_constructible<t_iterator>{}()) {
    return ::portable_stl::move(m_current);
  }

  /**
   * @brief Accesses the pointed-to element.
   * @return Reference-to-const that refers to the current element.
   */
  constexpr t_reference_private operator*() const noexcept(noexcept(static_cast<t_reference_private>(*m_current))) {
    return static_cast<t_reference_private>(*m_current);
  }

  /**
   * @brief Returns a reference or pointer to the const version of the current element.
   * t_iterator models contiguous_iterator.
   * @return Pointer-to-const that points to the current element.
   */
  template<
    class t_type = t_iterator,
    ::portable_stl::enable_if_bool_constant_t<
      ::portable_stl::conjunction<
        ::portable_stl::is_lvalue_reference<::portable_stl::iter_reference_t<t_type>>,
        ::portable_stl::same_as<::portable_stl::remove_cvref_t<::portable_stl::iter_reference_t<t_type>>, value_type>,
        ::portable_stl::contiguous_iterator<t_type>>,
      void *>
    = nullptr>
  constexpr auto const *operator->() const noexcept(::portable_stl::contiguous_iterator<t_type>{}()) {
    return ::portable_stl::to_address(m_current);
  }

  /**
   * @brief Returns a reference or pointer to the const version of the current element.
   * t_iterator does not model contiguous_iterator.
   * @return Pointer-to-const that points to the current element.
   */
  template<
    class t_type = t_iterator,
    ::portable_stl::enable_if_bool_constant_t<
      ::portable_stl::conjunction<
        ::portable_stl::is_lvalue_reference<::portable_stl::iter_reference_t<t_type>>,
        ::portable_stl::same_as<::portable_stl::remove_cvref_t<::portable_stl::iter_reference_t<t_type>>, value_type>,
        ::portable_stl::negation<::portable_stl::contiguous_iterator<t_type>>>,
      void *>
    = nullptr>
  constexpr auto const *operator->() const noexcept(noexcept(*m_current)) {
    return ::portable_stl::addressof(*m_current);
  }

  /**
   * @brief Pre increments the iterator.
   * @return basic_const_iterator& *this.
   */
  basic_const_iterator &operator++() noexcept(noexcept(++m_current)) {
    ++m_current;
    return *this;
  }

  // todo(plotitsyn): keep track on
  // template<class t_iter = t_iterator,
  //          ::portable_stl::enable_if_bool_constant_t<::portable_stl::negation<::portable_stl::forward_iterator<t_iter>>,
  //                                                    void *>
  //          = nullptr>
  // void operator++(int) noexcept(noexcept(++m_current)) {
  //   ++m_current;
  // }

  /**
   * @brief Post increments the iterator.
   * @return basic_const_iterator A copy of *this that was made before the change.
   */
  basic_const_iterator operator++(int) noexcept(
    noexcept(++*this) && ::portable_stl::is_nothrow_copy_constructible<basic_const_iterator>{}()) {
    static_assert(::portable_stl::forward_iterator<t_iterator>{}(),
                  "t_iterator does not satisfied forward_iterator concest");
    auto tmp = *this;
    ++*this;
    return tmp;
  }

  /**
   * @brief Pre decrements the iterator.
   * @return basic_const_iterator& *this.
   */
  template<class t_iter = t_iterator,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::bidirectional_iterator<t_iter>, void *> = nullptr>
  basic_const_iterator &operator--() noexcept(noexcept(--m_current)) {
    --m_current;
    return *this;
  }

  /**
   * @brief Post decrements the iterator.
   * @return basic_const_iterator A copy of *this that was made before the change.
   */
  template<class t_iter = t_iterator,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::bidirectional_iterator<t_iter>, void *> = nullptr>
  basic_const_iterator operator--(int) noexcept(
    noexcept(--*this) && ::portable_stl::is_nothrow_copy_constructible<basic_const_iterator>{}()) {
    auto tmp = *this;
    --*this;
    return tmp;
  }

  /**
   * @brief Advances the iterator by off_value positions.
   * @param off_value
   * @return basic_const_iterator& *this.
   */
  template<class t_iter = t_iterator,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::random_access_iterator<t_iter>, void *> = nullptr>
  basic_const_iterator &operator+=(difference_type const off_value) & noexcept(noexcept(m_current += off_value)) {
    m_current += off_value;
    return *this;
  }

  /**
   * @brief Advances the iterator by -off_value positions.
   * @param off_value
   * @return basic_const_iterator& *this.
   */
  template<class t_iter = t_iterator,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::random_access_iterator<t_iter>, void *> = nullptr>
  basic_const_iterator &operator-=(difference_type const off_value) & noexcept(noexcept(m_current -= off_value)) {
    m_current -= off_value;
    return *this;
  }

  /**
   * @brief Accesses an element by index.
   * @param index Position relative to current location.
   * @return t_reference_private A reference to the element at specified relative location.
   */
  template<class t_iter = t_iterator,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::random_access_iterator<t_iter>, void *> = nullptr>
  constexpr t_reference_private operator[](difference_type const index) const
    noexcept(noexcept(static_cast<t_reference_private>(m_current[index]))) {
    return static_cast<t_reference_private>(m_current[index]);
  }

  /* Equality comparison */

  /**
   * @brief Compares a basic_const_iterator with another value.
   * Can be used to compare two basic_const_iterator<t_iterator> values if Iter models sentinel_for<t_iterator>.
   * @tparam t_sentinel Sentinel type.
   * @tparam t_iter t_iterator.
   * @param sentinel_value A sentinel for t_iterator.
   * @return true
   * @return false
   */
  template<class t_sentinel,
           class t_iter = t_iterator,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::sentinel_for<t_sentinel, t_iter>, void *>
           = nullptr>
  constexpr bool operator==(t_sentinel const &sentinel_value) const
    noexcept(noexcept(iterator_helper::_Fake_copy_init<bool>(m_current == sentinel_value))) {
    return m_current == sentinel_value;
  }

  /**
   * @brief Compares a basic_const_iterator with another value.
   * (The != operator is synthesized from operator==)
   * @tparam t_sentinel Sentinel type.
   * @tparam t_iter t_iterator.
   * @param sentinel_value A sentinel for t_iterator.
   * @return true
   * @return false
   */
  template<class t_sentinel,
           class t_iter = t_iterator,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::sentinel_for<t_sentinel, t_iter>, void *>
           = nullptr>
  constexpr bool operator!=(t_sentinel const &sentinel_value) const
    noexcept(noexcept(iterator_helper::_Fake_copy_init<bool>(m_current != sentinel_value))) {
    return m_current != sentinel_value;
  }

  // /**
  //  * @brief Converts into any constant iterator to which an underlying iterator can be convertible.
  //  *
  //  * @tparam t_other Satisfies the exposition-only concept 'not-a-const-iterator' if and only if it's not a
  //  * specialization of basic_const_iterator.
  //  * @return t_other The converted constant iterator to which an underlying iterator current can be explicitly or
  //  * implicitly convertible.
  //  */
  // template<class t_other,
  //          ::portable_stl::enable_if_bool_constant_t<
  //            ::portable_stl::conjunction<iterator_helper::not_a_const_iterator<t_other>,
  //                                        ::portable_stl::iterator_helper::is_constant_iterator<t_other>,
  //                                        ::portable_stl::convertible_to<t_iterator const &, t_other>>,
  //            void *>
  //          = nullptr>
  // operator t_other() const & /*noexcept(::portable_stl::is_nothrow_convertible<t_iterator const &, t_other>)*/ {
  //   return m_current;
  // }

  // /**
  //  * @brief Converts into any constant iterator to which an underlying iterator can be convertible.
  //  *
  //  * @tparam t_other Satisfies the exposition-only concept 'not-a-const-iterator' if and only if it's not a
  //  * specialization of basic_const_iterator.
  //  * @return t_other The converted constant iterator to which an underlying iterator current can be explicitly or
  //  * implicitly convertible.
  //  */
  // template<class t_other,
  //          ::portable_stl::enable_if_bool_constant_t<
  //            ::portable_stl::conjunction<iterator_helper::not_a_const_iterator<t_other>,
  //                                        ::portable_stl::iterator_helper::is_constant_iterator<t_other>,
  //                                        ::portable_stl::convertible_to<t_iterator, t_other>>,
  //            void *>
  //          = nullptr>
  // operator t_other() && /*noexcept(::portable_stl::is_nothrow_convertible<t_iterator, t_other>)*/ {
  //   return ::portable_stl::move(m_current);
  // }

  /* Relational comparisons between two basic_const_iterators */

  // // from <=> operator
  // template<class t_iter = t_iterator,
  //          ::portable_stl::enable_if_bool_constant_t<::portable_stl::random_access_iterator<t_iter>, void *> =
  //          nullptr>
  // constexpr bool operator==(basic_const_iterator const &other) const noexcept(noexcept(m_current == other.m_current))
  // {
  //   return m_current == other.m_current;
  // }

  // // from <=> operator
  // template<class t_iter = t_iterator,
  //          ::portable_stl::enable_if_bool_constant_t<::portable_stl::random_access_iterator<t_iter>, void *> =
  //          nullptr>
  // constexpr bool operator!=(basic_const_iterator const &other) const noexcept(noexcept(m_current != other.m_current))
  // {
  //   return m_current != other.m_current;
  // }

  /**
   * @brief Compares a basic_const_iterator with another value.
   *
   * @tparam t_iter t_iterator
   * @param other A value to compare with.
   * @return true
   * @return false
   */
  template<class t_iter = t_iterator,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::random_access_iterator<t_iter>, void *> = nullptr>
  constexpr bool operator<(basic_const_iterator const &other) const noexcept(noexcept(m_current < other.m_current)) {
    return m_current < other.m_current;
  }

  /**
   * @brief Compares a basic_const_iterator with another value.
   *
   * @tparam t_iter t_iterator
   * @param other A value to compare with.
   * @return true
   * @return false
   */
  template<class t_iter = t_iterator,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::random_access_iterator<t_iter>, void *> = nullptr>
  constexpr bool operator>(basic_const_iterator const &other) const noexcept(noexcept(m_current < other.m_current)) {
    return m_current > other.m_current;
  }

  /**
   * @brief Compares a basic_const_iterator with another value.
   *
   * @tparam t_iter t_iterator
   * @param other A value to compare with.
   * @return true
   * @return false
   */
  template<class t_iter = t_iterator,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::random_access_iterator<t_iter>, void *> = nullptr>
  constexpr bool operator<=(basic_const_iterator const &other) const noexcept(noexcept(m_current < other.m_current)) {
    return m_current <= other.m_current;
  }

  /**
   * @brief Compares a basic_const_iterator with another value.
   *
   * @tparam t_iter t_iterator
   * @param other A value to compare with.
   * @return true
   * @return false
   */
  template<class t_iter = t_iterator,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::random_access_iterator<t_iter>, void *> = nullptr>
  constexpr bool operator>=(basic_const_iterator const &other) const noexcept(noexcept(m_current < other.m_current)) {
    return m_current >= other.m_current;
  }

  /* Relational comparisons between basic_const_iterator and another type */

  /**
   * @brief Compares a basic_const_iterator with another value.
   *
   * @tparam t_other_iter Satisfies 'different-from'<basic_const_iterator>.
   * @param other A value to compare with.
   * @return true
   * @return false
   */
  template<class t_other_iter,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<iterator_helper::different_from<t_other_iter, basic_const_iterator>,
                                         ::portable_stl::random_access_iterator<t_iterator>,
                                         ::portable_stl::totally_ordered_with<t_iterator, t_other_iter>>,
             void *>
           = nullptr>
  constexpr bool operator<(t_other_iter const &other) const noexcept(noexcept(m_current < other)) {
    return m_current < other;
  }

  /**
   * @brief Compares a basic_const_iterator with another value.
   *
   * @tparam t_other_iter Satisfies 'different-from'<basic_const_iterator>.
   * @param other A value to compare with.
   * @return true
   * @return false
   */
  template<class t_other_iter,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<iterator_helper::different_from<t_other_iter, basic_const_iterator>,
                                         ::portable_stl::random_access_iterator<t_iterator>,
                                         ::portable_stl::totally_ordered_with<t_iterator, t_other_iter>>,
             void *>
           = nullptr>
  constexpr bool operator>(t_other_iter const &other) const noexcept(noexcept(m_current > other)) {
    return m_current > other;
  }

  /**
   * @brief Compares a basic_const_iterator with another value.
   *
   * @tparam t_other_iter Satisfies 'different-from'<basic_const_iterator>.
   * @param other A value to compare with.
   * @return true
   * @return false
   */
  template<class t_other_iter,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<iterator_helper::different_from<t_other_iter, basic_const_iterator>,
                                         ::portable_stl::random_access_iterator<t_iterator>,
                                         ::portable_stl::totally_ordered_with<t_iterator, t_other_iter>>,
             void *>
           = nullptr>
  constexpr bool operator<=(t_other_iter const &other) const noexcept(noexcept(m_current <= other)) {
    return m_current <= other;
  }

  /**
   * @brief Compares a basic_const_iterator with another value.
   *
   * @tparam t_other_iter Satisfies 'different-from'<basic_const_iterator>.
   * @param other A value to compare with.
   * @return true
   * @return false
   */
  template<class t_other_iter,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<iterator_helper::different_from<t_other_iter, basic_const_iterator>,
                                         ::portable_stl::random_access_iterator<t_iterator>,
                                         ::portable_stl::totally_ordered_with<t_iterator, t_other_iter>>,
             void *>
           = nullptr>
  constexpr bool operator>=(t_other_iter const &other) const noexcept(noexcept(m_current >= other)) {
    return m_current >= other;
  }

  /**
   * @brief Computes the distance between two iterator adaptors.
   *
   * @tparam t_sentinel Satisfies the exposition-only concept 'not-a-const-iterator'.
   * @param other Sentinel to compute the difference of.
   * @return difference_type Returns the distance between basic_const_iterator and its sentinel.
   */
  template<class t_sentinel,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::sized_sentinel_for<t_sentinel, t_iterator>, void *>
           = nullptr>
  constexpr difference_type operator-(t_sentinel const &other) const noexcept(noexcept(m_current - other)) {
    return m_current - other;
  }
};

/* Non-member functions */

/**
 * @brief Compares basic_const_iterator with non-basic_const_iterator.
 *
 * @tparam t_iterator
 * @tparam t_other_iter Satisfies the exposition-only concept 'not-a-const-iterator'.
 * @param iter1 iterator to compare.
 * @param iter2 iterator to compare.
 * @return true
 * @return false
 */
template<class t_iterator,
         class t_other_iter,
         ::portable_stl::enable_if_bool_constant_t<
           ::portable_stl::conjunction<iterator_helper::not_a_const_iterator<t_other_iter>,
                                       ::portable_stl::random_access_iterator<t_iterator>,
                                       ::portable_stl::totally_ordered_with<t_iterator, t_other_iter>>,
           void *>
         = nullptr>
constexpr bool operator<(t_other_iter const                     &iter1,
                         basic_const_iterator<t_iterator> const &iter2) noexcept(noexcept(iter1 < iter2.base())) {
  return iter1 < iter2.base();
}

/**
 * @brief Compares basic_const_iterator with non-basic_const_iterator.
 *
 * @tparam t_iterator
 * @tparam t_other_iter Satisfies the exposition-only concept 'not-a-const-iterator'.
 * @param iter1 iterator to compare.
 * @param iter2 iterator to compare.
 * @return true
 * @return false
 */
template<class t_iterator,
         class t_other_iter,
         ::portable_stl::enable_if_bool_constant_t<
           ::portable_stl::conjunction<iterator_helper::not_a_const_iterator<t_other_iter>,
                                       ::portable_stl::random_access_iterator<t_iterator>,
                                       ::portable_stl::totally_ordered_with<t_iterator, t_other_iter>>,
           void *>
         = nullptr>
constexpr bool operator>(t_other_iter const                     &iter1,
                         basic_const_iterator<t_iterator> const &iter2) noexcept(noexcept(iter1 > iter2.base())) {
  return iter1 > iter2.base();
}

/**
 * @brief Compares basic_const_iterator with non-basic_const_iterator.
 *
 * @tparam t_iterator
 * @tparam t_other_iter Satisfies the exposition-only concept 'not-a-const-iterator'.
 * @param iter1 iterator to compare.
 * @param iter2 iterator to compare.
 * @return true
 * @return false
 */
template<class t_iterator,
         class t_other_iter,
         ::portable_stl::enable_if_bool_constant_t<
           ::portable_stl::conjunction<iterator_helper::not_a_const_iterator<t_other_iter>,
                                       ::portable_stl::random_access_iterator<t_iterator>,
                                       ::portable_stl::totally_ordered_with<t_iterator, t_other_iter>>,
           void *>
         = nullptr>
constexpr bool operator<=(t_other_iter const                     &iter1,
                          basic_const_iterator<t_iterator> const &iter2) noexcept(noexcept(iter1 <= iter2.base())) {
  return iter1 <= iter2.base();
}

/**
 * @brief Compares basic_const_iterator with non-basic_const_iterator.
 *
 * @tparam t_iterator
 * @tparam t_other_iter Satisfies the exposition-only concept 'not-a-const-iterator'.
 * @param iter1 iterator to compare.
 * @param iter2 iterator to compare.
 * @return true
 * @return false
 */
template<class t_iterator,
         class t_other_iter,
         ::portable_stl::enable_if_bool_constant_t<
           ::portable_stl::conjunction<iterator_helper::not_a_const_iterator<t_other_iter>,
                                       ::portable_stl::random_access_iterator<t_iterator>,
                                       ::portable_stl::totally_ordered_with<t_iterator, t_other_iter>>,
           void *>
         = nullptr>
constexpr bool operator>=(t_other_iter const                     &iter1,
                          basic_const_iterator<t_iterator> const &iter2) noexcept(noexcept(iter1 >= iter2.base())) {
  return iter1 >= iter2.base();
}

// there is no operator<=> for ::not_a_const_iterator

/**
 * @brief Advances the iterator.
 *
 * @tparam t_iterator Base type of basic_const_iterator adaptor.
 * @param iter Given iterator.
 * @param n_value Number of positinos.
 * @return basic_const_iterator<t_iterator> An iterator which is advanced by n_value positions.
 */
template<class t_iterator,
         ::portable_stl::enable_if_bool_constant_t<::portable_stl::random_access_iterator<t_iterator>, void *>
         = nullptr>
basic_const_iterator<t_iterator> operator+(
  basic_const_iterator<t_iterator> const &iter,
  typename basic_const_iterator<t_iterator>::difference_type
    n_value) noexcept(noexcept(basic_const_iterator<t_iterator>(iter.base() + n_value))) {
  return basic_const_iterator<t_iterator>(iter.base() + n_value);
}

/**
 * @brief Advances the iterator.
 *
 * @tparam t_iterator Base type of basic_const_iterator adaptor.
 * @param n_value Number of positinos.
 * @param iter Given iterator.
 * @return basic_const_iterator<t_iterator> An iterator which is advanced by n_value positions.
 */
template<class t_iterator,
         ::portable_stl::enable_if_bool_constant_t<::portable_stl::random_access_iterator<t_iterator>, void *>
         = nullptr>
basic_const_iterator<t_iterator> operator+(
  typename basic_const_iterator<t_iterator>::difference_type n_value,
  basic_const_iterator<t_iterator> const &iter) noexcept(noexcept(basic_const_iterator<t_iterator>(iter.base()
                                                                                                   + n_value))) {
  return basic_const_iterator<t_iterator>(iter.base() + n_value);
}

/**
 * @brief Decrements the iterator.
 *
 * @tparam t_iterator Base type of basic_const_iterator adaptor.
 * @param iter Given iterator.
 * @param n_value Number of positinos.
 * @return basic_const_iterator<t_iterator> An iterator which is decremented by n_value positions.
 */
template<class t_iterator,
         ::portable_stl::enable_if_bool_constant_t<::portable_stl::random_access_iterator<t_iterator>, void *>
         = nullptr>
basic_const_iterator<t_iterator> operator-(
  basic_const_iterator<t_iterator> const &iter,
  typename basic_const_iterator<t_iterator>::difference_type
    n_value) noexcept(noexcept(basic_const_iterator<t_iterator>(iter.base() - n_value))) {
  return basic_const_iterator<t_iterator>(iter.base() - n_value);
}

/**
 * @brief Computes the distance between two iterator adaptors.
 *
 * @tparam t_iterator Base type of basic_const_iterator adaptor.
 * @tparam t_sentinel Satisfies the exposition-only concept 'not-a-const-iterator'.
 * @param sent Sentinel to compute the difference of.
 * @param iter Iterator to compute the difference of.
 * @return basic_const_iterator<t_iterator>::difference_type The distance between basic_const_iterator and its sentinel.
 */
template<class t_iterator,
         class t_sentinel,
         ::portable_stl::enable_if_bool_constant_t<
           ::portable_stl::conjunction<iterator_helper::not_a_const_iterator<t_sentinel>,
                                       ::portable_stl::sized_sentinel_for<t_sentinel, t_iterator>>,
           void *>
         = nullptr>
constexpr typename basic_const_iterator<t_iterator>::difference_type operator-(
  t_sentinel const &sent, basic_const_iterator<t_iterator> const &iter) noexcept(noexcept(sent - iter.base())) {
  return sent - iter.base();
}

/**
 * @brief Casts the result of dereferencing the underlying iterator to its associated rvalue reference type.
 *
 * @tparam t_iterator Base type of basic_const_iterator adaptor.
 * @tparam t_ref = typename basic_const_iterator<t_iterator>::reference
 * @param iter A basic_const_iterator.
 * @return An rvalue reference to const, or a prvalue.
 */
template<class t_iterator,
         class t_ref = common_reference_t<::portable_stl::iter_value_t<t_iterator> const &&,
                                          ::portable_stl::iter_rvalue_reference_t<t_iterator>>>
constexpr t_ref iter_move(basic_const_iterator<t_iterator> const &iter) noexcept(
  noexcept(static_cast<t_ref>(::portable_stl::ranges::iter_move(iter.base())))) {
  return static_cast<t_ref>(::portable_stl::ranges::iter_move(iter.base()));
}

// As soon as common_type is a variadic class template common_type<class...>
// it is problematic to add requirements to class template parameters
//
// template<typename t_type1, ::portable_stl::common_with<t_type1> t_type2>
// requires input_iterator<common_type_t<t_type1, t_type2>> struct common_type<basic_const_iterator<t_type1>, t_type2> {
//   using type = basic_const_iterator<common_type_t<t_type1, t_type2>>;
// };
// template<typename t_type1, ::portable_stl::common_with<t_type1> t_type2>
// requires input_iterator<common_type_t<t_type1, t_type2>> struct common_type<t_type2, basic_const_iterator<t_type1>> {
//   using type = basic_const_iterator<common_type_t<t_type1, t_type2>>;
// };
// template<typename t_type1, ::portable_stl::common_with<t_type1> t_type2>
// requires input_iterator<common_type_t<t_type1, t_type2>> struct common_type<basic_const_iterator<t_type1>,
//                                                                             basic_const_iterator<t_type2>> {
//   using type = basic_const_iterator<common_type_t<t_type1, t_type2>>;
// };

/**
 * @brief If t_iterator models is_constant_iterator (an exposition-only concept), then const_iterator<t_iterator>
 * denotes a type t_iterator. Otherwise, basic_const_iterator<t_iterator>.
 * @tparam t_iterator Given iterator type.
 */
template<class t_iterator,
         class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::input_iterator<t_iterator>>>
using const_iterator
  = ::portable_stl::conditional_bool_constant_t<::portable_stl::iterator_helper::is_constant_iterator<t_iterator>,
                                                t_iterator,
                                                basic_const_iterator<t_iterator>>;

/**
 * @brief const_sentinel implementation.
 * @tparam t_sentinel Non const sentinel type.
 */
template<class t_sentinel, class = ::portable_stl::input_iterator<t_sentinel>> class const_sentinel_impl final {
public:
  /**
   * @brief Result sentinel type.
   */
  using type = const_iterator<t_sentinel>;
};

/**
 * @brief const_sentinel implementation.
 * @tparam t_sentinel Non const sentinel type.
 */
template<class t_sentinel> class const_sentinel_impl<t_sentinel, ::portable_stl::false_type> final {
public:
  /**
   * @brief Result sentinel type.
   */
  using type = t_sentinel;
};

/**
 * @brief Helper alias templates to get const sentinel type.
 * @tparam t_sentinel Non const sentinel type.
 */
template<class t_sentinel, class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::semiregular<t_sentinel>>>
using const_sentinel = typename const_sentinel_impl<t_sentinel>::type;

/**
 * @brief Helper to make const_iterator from iter.
 *
 * @tparam t_iterator
 * @param iter Given iterator.
 * @return const_iterator<t_iterator>
 */
template<class t_iterator,
         ::portable_stl::enable_if_bool_constant_t<::portable_stl::input_iterator<t_iterator>, void *> = nullptr>
constexpr const_iterator<t_iterator> make_const_iterator(t_iterator iter) noexcept(
  ::portable_stl::is_nothrow_constructible<const_iterator<t_iterator>, t_iterator &>{}()) // strengthened
{
  return iter;
}

/**
 * @brief Helper to make const_sentinel from iter.
 *
 * @tparam t_sentinel
 * @param sentinel Given sentinel.
 * @return const_sentinel<t_sentinel>
 */
template<class t_sentinel,
         ::portable_stl::enable_if_bool_constant_t<::portable_stl::semiregular<t_sentinel>, void *> = nullptr>
constexpr const_sentinel<t_sentinel> make_const_sentinel(t_sentinel sentinel) noexcept(
  ::portable_stl::is_nothrow_constructible<const_sentinel<t_sentinel>, t_sentinel &>{}()) // strengthened
{
  return sentinel;
}

} // namespace portable_stl

#endif /* PSTL_BASIC_CONST_ITERATOR_H */
