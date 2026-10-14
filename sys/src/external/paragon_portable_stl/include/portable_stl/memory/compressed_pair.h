// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="compressed_pair.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COMPRESSED_PAIR_H
#define PSTL_COMPRESSED_PAIR_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/type_properties/is_constructible.h"
#include "../metaprogramming/type_properties/is_default_constructible.h"
#include "../metaprogramming/type_properties/is_empty.h"
#include "../metaprogramming/type_properties/is_final.h"
#include "../metaprogramming/type_properties/is_nothrow_swappable.h"
#include "../utility/general/forward.h"
#include "../utility/general/in_place_t.h"
#include "../utility/general/second_tag.h"
#include "../utility/general/swap.h"

namespace portable_stl {
/**
 * @brief Class for optimized store empty class in memory.
 *
 * @tparam t_first the first type.
 * @tparam t_second the second type.
 */
template<class t_first,
         class t_second,
         class = ::portable_stl::conjunction<::portable_stl::is_empty<t_first>,
                                             ::portable_stl::negation<::portable_stl::is_final<t_first>>>,
         class = ::portable_stl::conjunction<::portable_stl::is_empty<t_second>,
                                             ::portable_stl::negation<::portable_stl::is_final<t_second>>>>
class compressed_pair {
  /**
   * @brief The first type value storage.
   *
   */
  t_first  m_first;
  /**
   * @brief The second type value storage.
   *
   */
  t_second m_second;

public:
  /**
   * @brief Construct a new compressed pair object
   *
   */
  compressed_pair()                                              = default;
  /**
   * @brief Destructor.
   */
  ~compressed_pair() noexcept                                    = default;
  /**
   * @brief Default constructor.
   *
   */
  compressed_pair(compressed_pair const &) noexcept              = default;
  /**
   * @brief Default constructor.
   *
   */
  compressed_pair(compressed_pair &&) noexcept                   = default;
  /**
   * @brief Default assignment.
   *
   */
  compressed_pair &operator=(compressed_pair const &) & noexcept = default;
  /**
   * @brief Default assignment.
   *
   */
  compressed_pair &operator=(compressed_pair &&) & noexcept      = default;

  /**
   * @brief Construct a new compressed pair object
   *
   * @tparam t_args_first the type of first value.
   * @param first_args the arguments for first value.
   */
  template<class t_args_first,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::is_constructible<t_first, t_args_first>,
                                         ::portable_stl::is_default_constructible<t_second>>,
             void *>
           = nullptr>
  explicit compressed_pair(t_args_first &&first_args) : m_first(::portable_stl::forward<t_args_first>(first_args)) {
  }

  /**
   * @brief Construct a new compressed pair object
   * @tparam t_args_second the type of second value.
   * @param second_args the arguments for second type.
   */
  template<class t_args_second,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::is_default_constructible<t_first>,
                                         ::portable_stl::is_constructible<t_second, t_args_second>>,
             void *>
           = nullptr>
  explicit compressed_pair(t_args_second &&second_args)
      : m_second(::portable_stl::forward<t_args_second>(second_args)) {
  }

  /**
   * @brief Construct a new compressed pair object
   *
   * @tparam t_args_first the type of first value.
   * @tparam t_args_second the type of second value.
   * @param first_args the arguments for first value.
   * @param second_args the arguments for second type.
   */
  template<class t_args_first,
           class t_args_second,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::is_constructible<t_first, t_args_first>,
                                         ::portable_stl::is_constructible<t_second, t_args_second>>,
             void *>
           = nullptr>
  compressed_pair(t_args_first &&first_args, t_args_second &&second_args)
      : m_first(::portable_stl::forward<t_args_first>(first_args))
      , m_second(::portable_stl::forward<t_args_second>(second_args)) {
  }

  /**
   * @brief Construct a new compressed pair object
   *
   * @tparam t_args_second the type of second value.
   * @param second_args the arguments for second type.
   */
  template<class t_args_second,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_constructible<t_second, t_args_second>, void *>
           = nullptr>
  compressed_pair(::portable_stl::second_tag_t, t_args_second &&second_args)
      : m_first(), m_second(::portable_stl::forward<t_args_second>(second_args)) {
  }

  /**
   * @brief Get first value.
   * @return first value.
   */
  t_first &get_first() noexcept {
    return m_first;
  }

  /**
   * @brief Get first value.
   * @return first value.
   */
  t_first const &get_first() const noexcept {
    return m_first;
  }

  /**
   * @brief Get second value.
   * @return second value.
   */
  t_second &get_second() noexcept {
    return m_second;
  }
  /**
   * @brief Get second value.
   * @return second value.
   */
  t_second const &get_second() const noexcept {
    return m_second;
  }

  void swap(compressed_pair &other) noexcept(::portable_stl::is_nothrow_swappable<t_first>{}()
                                             && ::portable_stl::is_nothrow_swappable<t_second>{}()) {
    using ::portable_stl::swap;
    swap(get_first(), other.get_first());
    swap(get_second(), other.get_second());
  }
};

template<class t_first, class t_second>
inline void swap(compressed_pair<t_first, t_second> &lhv, compressed_pair<t_first, t_second> &rhv) noexcept(
  ::portable_stl::is_nothrow_swappable<t_first>{}() && ::portable_stl::is_nothrow_swappable<t_second>{}()) {
  lhv.swap(rhv);
}

/**
 * @brief Class for optimized store empty class in memory.
 *
 * @tparam t_first the first type.
 * @tparam t_second the second type.
 */
template<class t_first, class t_second>
class compressed_pair<t_first, t_second, ::portable_stl::true_type, ::portable_stl::false_type> : private t_first {
  /**
   * @brief The second type value storage.
   *
   */
  t_second m_second;

public:
  /**
   * @brief Destructor.
   */
  ~compressed_pair() noexcept                                    = default;
  /**
   * @brief Default constructor.
   *
   */
  compressed_pair(compressed_pair const &) noexcept              = default;
  /**
   * @brief Default constructor.
   *
   */
  compressed_pair(compressed_pair &&) noexcept                   = default;
  /**
   * @brief Default assignment.
   *
   */
  compressed_pair &operator=(compressed_pair const &) & noexcept = default;
  /**
   * @brief Default assignment.
   *
   */
  compressed_pair &operator=(compressed_pair &&) & noexcept      = default;
  /**
   * @brief Construct a new compressed pair object
   * @tparam t_args_second the type of second value.
   * @param second_args the arguments for second type.
   */
  template<class t_args_second>
  compressed_pair(t_args_second &&second_args) : m_second(::portable_stl::forward<t_args_second>(second_args)) {
  }

  /**
   * @brief Construct a new compressed pair object
   *
   * @tparam t_args_first the type of first value.
   * @tparam t_args_second the type of second value.
   * @param first_args the arguments for first value.
   * @param second_args the arguments for second type.
   */
  template<class t_args_first,
           class t_args_second,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::is_constructible<t_first, t_args_first>,
                                         ::portable_stl::is_constructible<t_second, t_args_second>>,
             void *>
           = nullptr>
  compressed_pair(t_args_first &&first_args, t_args_second &&second_args)
      : t_first(::portable_stl::forward<t_args_first>(first_args))
      , m_second(::portable_stl::forward<t_args_second>(second_args)) {
  }

  /**
   * @brief Get first value.
   * @return first value.
   */
  t_first &get_first() noexcept {
    return *this;
  }
  /**
   * @brief Get first value.
   * @return first value.
   */
  t_first const &get_first() const noexcept {
    return *this;
  }

  /**
   * @brief Get second value.
   * @return second value.
   */
  t_second &get_second() noexcept {
    return m_second;
  }
  /**
   * @brief Get second value.
   * @return second value.
   */
  t_second const &get_second() const noexcept {
    return m_second;
  }

  void swap(compressed_pair &other) noexcept(::portable_stl::is_nothrow_swappable<t_second>{}()) {
    using ::portable_stl::swap;
    swap(get_second(), other.get_second());
  }
};

template<class t_first, class t_second>
inline void swap(compressed_pair<t_first, t_second, ::portable_stl::true_type, ::portable_stl::false_type> &lhv,
                 compressed_pair<t_first, t_second, ::portable_stl::true_type, ::portable_stl::false_type>
                   &rhv) noexcept(::portable_stl::is_nothrow_swappable<t_second>{}()) {
  lhv.swap(rhv);
}

/**
 * @brief Class for optimized store empty class in memory.
 *
 * @tparam t_first the first type.
 * @tparam t_second the second type.
 */
template<class t_first, class t_second>
class compressed_pair<t_first, t_second, ::portable_stl::false_type, ::portable_stl::true_type> : private t_second {
  /**
   * @brief The first type value storage.
   *
   */
  t_first m_first;

public:
  /**
   * @brief Destructor.
   */
  ~compressed_pair() noexcept                                    = default;
  /**
   * @brief Default constructor.
   *
   */
  compressed_pair(compressed_pair const &) noexcept              = default;
  /**
   * @brief Default constructor.
   *
   */
  compressed_pair(compressed_pair &&) noexcept                   = default;
  /**
   * @brief Default assignment.
   *
   */
  compressed_pair &operator=(compressed_pair const &) & noexcept = default;
  /**
   * @brief Default assignment.
   *
   */
  compressed_pair &operator=(compressed_pair &&) & noexcept      = default;
  /**
   * @brief Construct a new compressed pair object
   *
   * @tparam t_args_first the type of first value.
   * @param first_args the arguments for first value.
   */
  template<class t_args_first>
  compressed_pair(t_args_first &&first_args) : t_second(), m_first(::portable_stl::forward<t_args_first>(first_args)) {
  }

  /**
   * @brief Construct a new compressed pair object
   *
   * @tparam t_args_first the type of first value.
   * @tparam t_args_second the type of second value.
   * @param first_args the arguments for first value.
   * @param second_args the arguments for second type.
   */
  template<class t_args_first,
           class t_args_second,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::is_constructible<t_first, t_args_first>,
                                         ::portable_stl::is_constructible<t_second, t_args_second>>,
             void *>
           = nullptr>
  compressed_pair(t_args_first &&first_args, t_args_second &&second_args)
      : t_second(::portable_stl::forward<t_args_second>(second_args))
      , m_first(::portable_stl::forward<t_args_first>(first_args)) {
  }

  /**
   * @brief Construct a new compressed pair object
   *
   * @tparam t_args_second the type of second value.
   * @param second_args the arguments for second type.
   */
  template<class t_args_second,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_constructible<t_second, t_args_second>, void *>
           = nullptr>
  compressed_pair(::portable_stl::second_tag_t, t_args_second &&second_args)
      : t_second(::portable_stl::forward<t_args_second>(second_args)), m_first() {
  }

  /**
   * @brief Get first value.
   * @return first value.
   */
  t_first &get_first() noexcept {
    return m_first;
  }
  /**
   * @brief Get first value.
   * @return first value.
   */
  t_first const &get_first() const noexcept {
    return m_first;
  }

  /**
   * @brief Get second value.
   * @return second value.
   */
  t_second &get_second() noexcept {
    return *this;
  }
  /**
   * @brief Get second value.
   * @return second value.
   */
  t_second const &get_second() const noexcept {
    return *this;
  }

  void swap(compressed_pair &other) noexcept(::portable_stl::is_nothrow_swappable<t_first>{}()) {
    using ::portable_stl::swap;
    swap(get_first(), other.get_first());
  }
};

template<class t_first, class t_second>
inline void swap(compressed_pair<t_first, t_second, ::portable_stl::false_type, ::portable_stl::true_type> &lhv,
                 compressed_pair<t_first, t_second, ::portable_stl::false_type, ::portable_stl::true_type>
                   &rhv) noexcept(::portable_stl::is_nothrow_swappable<t_first>{}()) {
  lhv.swap(rhv);
}

/**
 * @brief Class for optimized store empty class in memory.
 *
 * @tparam t_first the first type.
 * @tparam t_second the second type.
 */
template<class t_first, class t_second>
class compressed_pair<t_first, t_second, ::portable_stl::true_type, ::portable_stl::true_type>
    : private t_first
    , private t_second {
public:
  /**
   * @brief Construct a new compressed pair object
   *
   */
  compressed_pair() noexcept = default;

  /**
   * @brief Construct a new compressed pair object
   * t_args_first and t_args_second are not actually used, as they are empty.
   * 
   * @tparam t_args_first
   * @tparam t_args_second
   * @param first_args
   * @param second_args
   */
  template<class t_args_first, class t_args_second>
  compressed_pair(t_args_first first_args, t_args_second second_args) : t_first(first_args), t_second(second_args) {
  }

  /**
   * @brief Get first value.
   * @return first value.
   */
  t_first &get_first() noexcept {
    return *this;
  }
  /**
   * @brief Get first value.
   * @return first value.
   */
  t_first const &get_first() const noexcept {
    return *this;
  }

  /**
   * @brief Get second value.
   * @return second value.
   */
  t_second &get_second() noexcept {
    return *this;
  }
  /**
   * @brief Get second value.
   * @return second value.
   */
  t_second const &get_second() const noexcept {
    return *this;
  }
};

} // namespace portable_stl

#endif // PSTL_COMPRESSED_PAIR_H
