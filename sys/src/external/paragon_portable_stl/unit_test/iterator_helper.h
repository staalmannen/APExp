// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iterator_helper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ITERATOR_HELPER_H
#define PSTL_ITERATOR_HELPER_H

#include <portable_stl/iterator/random_access_iterator_tag.h>

#include "portable_stl/common/ptrdiff_t.h"
#include "portable_stl/common/size_t.h"
#include "portable_stl/iterator/iterator_traits.h"
#include "portable_stl/metaprogramming/cv_modifications/remove_cv.h"
#include "portable_stl/metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "portable_stl/metaprogramming/pointer_modifications/add_pointer.h"
#include "portable_stl/metaprogramming/primary_type/is_pointer.h"
#include "portable_stl/metaprogramming/reference_modifications/add_lvalue_reference.h"

namespace test_iterator_exception_helper {
/**
 * @brief Class to check execptions.
 * @tparam throw_exception
 */
template<bool throw_exception> class ClassCanThrow final {
  /**
   * @brief Data.
   */
  std::int32_t m_storage[5]{1, 2, 3, 4, 5};

public:
  /**
   * @brief
   */
  using iterator_type     = std::int32_t const *;
  /**
   * @brief
   */
  using difference_type   = ::portable_stl::ptrdiff_t;
  /**
   * @brief
   */
  using iterator_category = ::portable_stl::random_access_iterator_tag;
  /**
   * @brief
   */
  using pointer           = std::int32_t const *;
  /**
   * @brief
   */
  using reference         = std::int32_t const &;
  /**
   * @brief
   */
  using value_type        = std::int32_t const;
  /**
   * @brief Construct a new Class Can Throw object
   */
  ClassCanThrow()         = default;
  /**
   * @brief Construct a new Class Can Throw object
   */
  ClassCanThrow(ClassCanThrow const &) noexcept(!throw_exception) {
    if (throw_exception) {
      throw std::runtime_error("Exception on copy ClassCanThrow");
    }
  }
  /**
   * @brief Construct a new Class Can Throw object
   */
  ClassCanThrow(ClassCanThrow &&) noexcept(!throw_exception) {
    if (throw_exception) {
      throw std::runtime_error("Exception on move ClassCanThrow");
    }
  }
  /**
   * @brief Destroy the Class Can Throw object
   */
  ~ClassCanThrow() = default;
  // std::int32_t &operator*() noexcept {
  //   return *&m_storage[2];
  // }
  /**
   * @brief
   * @return value_type&
   */
  value_type &operator*() const noexcept {
    return m_storage[2];
  }
  /**
   * @brief
   * @return ClassCanThrow&
   */
  ClassCanThrow &operator--() noexcept {
    return *this;
  }
};

/**
 * @brief
 */
void iter_swap(ClassCanThrow<false> const &, ClassCanThrow<false> const &) noexcept(false);

/**
 * @brief
 */
void iter_swap(ClassCanThrow<true> const &, ClassCanThrow<true> const &) noexcept(false);

/**
 * @brief
 * @param iter
 * @return std::int32_t const&&
 */
inline std::int32_t const &&iter_move(ClassCanThrow<false> const &iter) noexcept {
  return std::move(*iter);
}

/**
 * @brief
 * @param iter
 * @return std::int32_t const&&
 */
inline std::int32_t const &&iter_move(ClassCanThrow<true> const &iter) noexcept(false) {
  return std::move(*iter);
}
} // namespace test_iterator_exception_helper

namespace test_iterator_helper {

/**
 * @brief Test input iterator.
 * @tparam t_type given value type.
 */
template<class iterator_t> class tst_input_iterator final {
  /**
   * @brief Base iterator.
   */
  iterator_t m_iterator{};

public:
  /**
   * @brief The type of iterator.
   */
  using iterator_category = ::portable_stl::input_iterator_tag;
  /**
   * @brief The type of iterating object.
   */
  using value_type        = typename ::portable_stl::iterator_traits<iterator_t>::value_type;
  /**
   * @brief The type for store difference between two iterators.
   */
  using difference_type   = typename ::portable_stl::iterator_traits<iterator_t>::difference_type;
  /**
   * @brief
   */
  using pointer           = iterator_t;
  /**
   * @brief The type of reference to iterating object.
   */
  using reference         = typename ::portable_stl::iterator_traits<iterator_t>::reference;

public:
  /**
   * @brief Construct a new Test Input Iterator object
   */
  tst_input_iterator() = default;

  /**
   * @brief Copy Construct a new tst input iterator object
   * @param other
   */
  tst_input_iterator(tst_input_iterator const &other) = default;

  /**
   * @brief Construct a new Test Input Iterator object.
   * @param iterator Given iterator.
   */
  tst_input_iterator(iterator_t iterator) : m_iterator{iterator} {
  }

  /**
   * @brief Dereference operator.
   * @return reference
   */
  reference operator*() const {
    return *m_iterator;
  }

  /**
   * @brief pre
   * @return
   */
  tst_input_iterator &operator++() {
    ++m_iterator;
    return *this;
  }

  /**
   * @brief post
   * @return
   */
  tst_input_iterator operator++(int) {
    return tst_input_iterator(m_iterator++);
  }

  /**
   * @brief
   * @return iterator_t const
   */
  iterator_t const base() const noexcept {
    return m_iterator;
  }
};

/**
 * @brief
 * @tparam iterator_t
 * @param left
 * @param right
 * @return true
 * @return false
 */
template<class iterator_t>
bool operator==(tst_input_iterator<iterator_t> const &left, tst_input_iterator<iterator_t> const &right) noexcept {
  return left.base() == right.base();
}

/**
 * @brief
 * @tparam iterator_t
 * @param left
 * @param right
 * @return true
 * @return false
 */
template<class iterator_t>
bool operator!=(tst_input_iterator<iterator_t> const &left, tst_input_iterator<iterator_t> const &right) noexcept {
  return left.base() != right.base();
}

/**
 * @brief Test Forward iterator.
 * @tparam t_type given value type.
 */
template<class iterator_t> class tst_forward_iterator final {
  /**
   * @brief Base iterator.
   */
  iterator_t m_iterator{};

public:
  /**
   * @brief The type of iterator.
   */
  using iterator_category = ::portable_stl::forward_iterator_tag;
  /**
   * @brief The type of iterating object.
   */
  using value_type        = typename ::portable_stl::iterator_traits<iterator_t>::value_type;
  /**
   * @brief The type for store difference between two iterators.
   */
  using difference_type   = typename ::portable_stl::iterator_traits<iterator_t>::difference_type;
  /**
   * @brief
   */
  using pointer           = iterator_t;
  /**
   * @brief The type of reference to iterating object.
   */
  using reference         = typename ::portable_stl::iterator_traits<iterator_t>::reference;

  /**
   * @brief Construct a new Test Forward Iterator object
   */
  tst_forward_iterator() = default;
  /**
   * @brief Construct a new Test Forward Iterator object.
   * @param iterator Given iterator.
   */
  tst_forward_iterator(iterator_t iterator) : m_iterator{iterator} {
  }
  /**
   * @brief Dereference operator.
   * @return reference&
   */
  reference operator*() const {
    return *m_iterator;
  }
  /**
   * @brief pre
   * @return
   */
  tst_forward_iterator &operator++() {
    ++m_iterator;
    return *this;
  }
  /**
   * @brief post
   * @return
   */
  tst_forward_iterator operator++(int) {
    return tst_forward_iterator(m_iterator++);
  }
  /**
   * @brief
   * @return iterator_t const
   */
  iterator_t const base() const noexcept {
    return m_iterator;
  }
};

/**
 * @brief
 * @tparam iterator_t
 * @param left
 * @param right
 * @return true
 * @return false
 */
template<class iterator_t>
bool operator==(tst_forward_iterator<iterator_t> const &left, tst_forward_iterator<iterator_t> const &right) noexcept {
  return left.base() == right.base();
}

/**
 * @brief
 * @tparam iterator_t
 * @param left
 * @param right
 * @return true
 * @return false
 */
template<class iterator_t>
bool operator!=(tst_forward_iterator<iterator_t> const &left, tst_forward_iterator<iterator_t> const &right) noexcept {
  return !(left == right);
}

/**
 * @brief Test Bidirectional iterator.
 * @tparam t_type given value type.
 */
template<class iterator_t> class tst_bidirectional_iterator final {
  /**
   * @brief Base iterator.
   */
  iterator_t m_iterator{};

public:
  /**
   * @brief The type of iterator.
   */
  using iterator_category = ::portable_stl::bidirectional_iterator_tag;
  /**
   * @brief The type of iterating object.
   */
  using value_type        = typename ::portable_stl::iterator_traits<iterator_t>::value_type;
  /**
   * @brief The type for store difference between two iterators.
   */
  using difference_type   = typename ::portable_stl::iterator_traits<iterator_t>::difference_type;
  /**
   * @brief
   */
  using pointer           = iterator_t;
  /**
   * @brief The type of reference to iterating object.
   */
  using reference         = typename ::portable_stl::iterator_traits<iterator_t>::reference;

  /**
   * @brief Construct a new Test Bidirectional Iterator object
   */
  tst_bidirectional_iterator() = default;
  /**
   * @brief Construct a new Test Input Iterator object.
   * @param iterator Given iterator.
   */
  tst_bidirectional_iterator(iterator_t iterator) : m_iterator{iterator} {
  }
  /**
   * @brief Dereference operator.
   * @return reference&
   */
  reference operator*() const {
    return *m_iterator;
  }
  /**
   * @brief pre
   * @return
   */
  tst_bidirectional_iterator &operator++() {
    ++m_iterator;
    return *this;
  }
  /**
   * @brief pre
   * @return
   */
  tst_bidirectional_iterator &operator--() {
    --m_iterator;
    return *this;
  }
  /**
   * @brief post
   * @return
   */
  tst_bidirectional_iterator operator++(int) {
    return tst_bidirectional_iterator(m_iterator++);
  }

  /**
   * @brief post
   * @return tst_bidirectional_iterator
   */
  tst_bidirectional_iterator operator--(int) {
    return tst_bidirectional_iterator(m_iterator--);
  }

  /**
   * @brief
   * @return iterator_t const
   */
  iterator_t const base() const noexcept {
    return m_iterator;
  }
};

/**
 * @brief
 * @tparam iterator_t
 * @param left
 * @param right
 * @return true
 * @return false
 */
template<class iterator_t>
bool operator==(tst_bidirectional_iterator<iterator_t> const &left,
                tst_bidirectional_iterator<iterator_t> const &right) noexcept {
  return left.base() == right.base();
}

/**
 * @brief
 * @tparam iterator_t
 * @param left
 * @param right
 * @return true
 * @return false
 */
template<class iterator_t>
bool operator!=(tst_bidirectional_iterator<iterator_t> const &left,
                tst_bidirectional_iterator<iterator_t> const &right) noexcept {
  return !(left == right);
}

/**
 * @brief Test random access iterator.
 *
 * @tparam iterator_t Base iterator type.
 */
template<class iterator_t> class tst_random_access_iterator final {
  /**
   * @brief Base iterator.
   */
  iterator_t m_iterator{};

public:
  /**
   * @brief The type of iterator.
   */
  using iterator_category = ::portable_stl::random_access_iterator_tag;
  /**
   * @brief The type of iterating object.
   */
  using value_type        = typename ::portable_stl::iterator_traits<iterator_t>::value_type;
  /**
   * @brief The type for store difference between two iterators.
   */
  using difference_type   = typename ::portable_stl::iterator_traits<iterator_t>::difference_type;
  /**
   * @brief
   */
  using pointer           = iterator_t;
  /**
   * @brief The type of reference to iterating object.
   */
  using reference         = typename ::portable_stl::iterator_traits<iterator_t>::reference;

  /**
   * @brief Construct a new Test Random Access Iterator object
   */
  tst_random_access_iterator() = default;
  /**
   * @brief
   * @param iterator
   */
  tst_random_access_iterator(iterator_t iterator) : m_iterator(iterator) {
  }

  /**
   * @brief Dereference operator.
   * @return reference
   */
  reference operator*() const {
    return *m_iterator;
  }

  /**
   * @brief
   * @param n_value
   * @return reference
   */
  reference operator[](difference_type n_value) const {
    return m_iterator[n_value];
  }

  /**
   * @brief pre
   * @return
   */
  tst_random_access_iterator &operator++() {
    ++m_iterator;
    return *this;
  }
  /**
   * @brief pre
   * @return
   */
  tst_random_access_iterator &operator--() {
    --m_iterator;
    return *this;
  }
  /**
   * @brief post
   * @return
   */
  tst_random_access_iterator operator++(int) {
    return tst_random_access_iterator(m_iterator++);
  }
  /**
   * @brief post
   * @return tst_random_access_iterator
   */
  tst_random_access_iterator operator--(int) {
    return tst_random_access_iterator(m_iterator--);
  }
  /**
   * @brief
   * @param n_value
   * @return tst_random_access_iterator&
   */
  tst_random_access_iterator &operator+=(difference_type n_value) & {
    m_iterator += n_value;
    return *this;
  }
  /**
   * @brief
   * @param n_value
   * @return tst_random_access_iterator&
   */
  tst_random_access_iterator &operator-=(difference_type n_value) & {
    m_iterator -= n_value;
    return *this;
  }
  /**
   * @brief
   * @param n_value
   * @return
   */
  tst_random_access_iterator operator+(difference_type n_value) const {
    return tst_random_access_iterator(m_iterator + n_value);
  }
  /**
   * @brief
   * @param n_value
   * @return
   */
  tst_random_access_iterator operator-(difference_type n_value) const {
    return tst_random_access_iterator(m_iterator - n_value);
  }

  /**
   * @brief
   * @return iterator_t const
   */
  iterator_t const base() const noexcept {
    return m_iterator;
  }
};

/**
 * @brief
 * @tparam iterator_t
 * @param n_value
 * @param iter
 * @return tst_random_access_iterator<iterator_t>
 */
template<class iterator_t>
tst_random_access_iterator<iterator_t> operator+(
  typename tst_random_access_iterator<iterator_t>::difference_type n_value,
  tst_random_access_iterator<iterator_t>                           iter) {
  iter += n_value;
  return iter;
}

/**
 * @brief
 * @tparam iterator_t
 * @param left
 * @param right
 * @return tst_random_access_iterator<iterator_t>::difference_type
 */
template<class iterator_t>
typename tst_random_access_iterator<iterator_t>::difference_type operator-(
  tst_random_access_iterator<iterator_t> const &left, tst_random_access_iterator<iterator_t> const &right) {
  return left.base() - right.base();
}

/**
 * @brief
 * @tparam iterator_t
 * @param left
 * @param right
 * @return true
 * @return false
 */
template<class iterator_t>
bool operator==(tst_random_access_iterator<iterator_t> const &left,
                tst_random_access_iterator<iterator_t> const &right) noexcept {
  return left.base() == right.base();
}

/**
 * @brief
 * @tparam iterator_t
 * @param left
 * @param right
 * @return true
 * @return false
 */
template<class iterator_t>
bool operator!=(tst_random_access_iterator<iterator_t> const &left,
                tst_random_access_iterator<iterator_t> const &right) noexcept {
  return left.base() != right.base();
}

/**
 * @brief Comparison operator.
 *
 * @tparam t_type Given type.
 * @return true
 * @return false
 */
template<class t_type>
bool operator<(tst_random_access_iterator<t_type> const &, tst_random_access_iterator<t_type> const &) noexcept;

/**
 * @brief Comparison operator.
 *
 * @tparam t_type Given type.
 * @return true
 * @return false
 */
template<class t_type>
bool operator<=(tst_random_access_iterator<t_type> const &, tst_random_access_iterator<t_type> const &) noexcept;

/**
 * @brief Comparison operator.
 *
 * @tparam t_type Given type.
 * @return true
 * @return false
 */
template<class t_type>
bool operator>(tst_random_access_iterator<t_type> const &, tst_random_access_iterator<t_type> const &) noexcept;

/**
 * @brief Comparison operator.
 *
 * @tparam t_type Given type.
 * @return true
 * @return false
 */
template<class t_type>
bool operator>=(tst_random_access_iterator<t_type> const &, tst_random_access_iterator<t_type> const &) noexcept;

/**
 * @brief Helper class.
 */
class missing_dereference final {
public:
  /**
   * @brief Difference type.
   */
  using difference_type = std::ptrdiff_t;

  /**
   * @brief pre.
   * @return missing_dereference&
   */
  missing_dereference &operator++();
  /**
   * @brief post
   * @return missing_dereference&
   */
  missing_dereference &operator++(int);
};

/**
 * @brief Helper class.
 */
class void_dereference final {
public:
  /**
   * @brief Difference type.
   */
  using difference_type = std::ptrdiff_t;

  /**
   * @brief Deref.
   */
  void              operator*() noexcept;
  /**
   * @brief pre.
   * @return void_dereference&
   */
  void_dereference &operator++() noexcept {
    return *this;
  }
  /**
   * @brief post
   * @return void_dereference&
   */
  void_dereference &operator++(int) noexcept {
    return *this;
  }
};

/**
 * @brief Helper class.
 */
class not_weakly_incrementable final {
public:
  /**
   * @brief Deref.
   * @return int
   */
  std::int32_t operator*() const;
};

/**
 * @brief Helper class.
 */
class container_with_insert final {
  /**
   * @brief Simple iterator for test container.
   * @tparam t_type Given value type.
   */
  template<class t_type> class simple_iterator final {
  public:
    /**
     * @brief diff type for weakly incrementable
     */
    using difference_type = std::ptrdiff_t;

    /**
     * @brief Ctor.
     */
    simple_iterator(t_type &) {
    }
    /**
     * @brief Construct a new simple iterator object
     */
    simple_iterator(simple_iterator const &) = default;
    // clang-format off
    /**
     * @brief Copy ctor.
     * @return simple_iterator& 
     */
    simple_iterator &operator=(simple_iterator const &) & = default;
    // clang-format on
    /**
     * @brief Pre inc.
     * @return simple_iterator&
     */
    simple_iterator &operator++() {
      return *this;
    }
    /**
     * @brief Post inc.
     * @return simple_iterator
     */
    simple_iterator operator++(int) {
      return *this;
    }
    /**
     * @brief Deref.
     * @return t_type
     */
    t_type operator*() const {
      return 1;
    }
  };

public:
  /**
   * @brief Value type.
   */
  using value_type = std::int32_t;
  /**
   * @brief Iter type.
   */
  using iterator   = simple_iterator<value_type>;

  /**
   * @brief Deref.
   * @return
   */
  constexpr value_type operator*() const noexcept {
    return m_only_one_value;
  }
  /**
   * @brief Get begin
   * @return iterator
   */
  iterator begin() {
    return iterator(m_only_one_value);
  }
  /**
   * @brief Insert operator.
   * @return iterator
   */
  iterator insert(iterator &, value_type const &) {
    ++dummy_size_;
    return iterator(m_only_one_value);
  }
  /**
   * @brief Get size operator.
   * @return std::size_t
   */
  constexpr std::size_t size() const noexcept {
    return dummy_size_;
  }

private:
  /**
   * @brief value.
   */
  value_type  m_only_one_value{0};
  /**
   * @brief Summy size.
   */
  std::size_t dummy_size_{0U};
};

/**
 * @brief Class to check move_iterator accessors.
 *
 */
class Eater final {
public:
  /**
   * @brief Test function.
   * @tparam t_type
   * @return true
   * @return false
   */
  template<class t_type> constexpr static bool test_fn(t_type &&) {
    return true;
  }
};

/**
 * @brief Test type.
 */
class indirection_mismatch final {
public:
  /**
   * @brief Value type.
   */
  using value_type = std::int32_t;
  /**
   * @brief Dereference operator.
   * @return float&
   */
  float &operator*() const;
};

/**
 * @brief Test type.
 */
class iter_move_mismatch final {
public:
  /**
   * @brief Value type.
   */
  using value_type = std::int32_t;
  /**
   * @brief Dereference operator.
   * @return value_type&
   */
  value_type &operator*() const;
};
/**
 * @brief Custom iter_move declaration.
 * @return float&
 */
float &iter_move(iter_move_mismatch &);

/**
 * @brief Test type.
 */
class indirection_and_iter_move_mismatch final {
public:
  /**
   * @brief Value type.
   */
  using value_type = std::int32_t;
  /**
   * @brief Dereference operator.
   * @return float&
   */
  float &operator*() const;
};
/**
 * @brief Custom iter_move declaration.
 * @return std::uint64_t&
 */
std::uint64_t &iter_move(indirection_and_iter_move_mismatch &);

/**
 * @brief Test type.
 */
class missing_iter_value_t final {
public:
  /**
   * @brief
   * @return int
   */
  int operator*() const;
};

/**
 * @brief Test type.
 */
class value_type_indirection final {
public:
  /**
   * @brief Value type.
   */
  using value_type = std::int32_t;
  /**
   * @brief Dereference operator.
   * @return value_type&
   */
  value_type &operator*() const;
};

/**
 * @brief Test type.
 */
class element_type_indirection final {
public:
  /**
   * @brief Element type.
   */
  using element_type = long;
  /**
   * @brief Dereference operator.
   * @return element_type&
   */
  element_type &operator*() const;
};

/**
 * @brief Test type.
 */
class proxy_indirection final {
public:
  /**
   * @brief Value type.
   */
  using value_type = std::int32_t;
  /**
   * @brief Dereference operator.
   * @return value_type
   */
  value_type operator*() const;
};

/**
 * @brief Test type.
 */
class read_only_indirection final {
public:
  /**
   * @brief Value type.
   */
  using value_type = std::int32_t const;
  /**
   * @brief Dereference operator.
   * @return value_type&
   */
  value_type &operator*() const;
};

/**
 * @brief Test type.
 */
class missing_dereference2 final {
public:
  /**
   * @brief Value type.
   */
  using value_type = int;
};

/**
 * @brief Test wrapper type.
 * @tparam t_type Given type.
 * @tparam value_t
 */
template<class t_type, class value_t = t_type> class PointerTo final {
public:
  /**
   * @brief Value type.
   */
  using value_type = value_t;
  /**
   * @brief Deref operator.
   * @return t_type&
   */
  t_type &operator*() const;
};

/**
 * @brief Test type.
 */
class ClassAWithIterSwapSelf final {};
/**
 * @brief Custom iter_swap declaration.
 */
inline void iter_swap(PointerTo<ClassAWithIterSwapSelf> const &, PointerTo<ClassAWithIterSwapSelf> const &);

/**
 * @brief Test indirectly swappable type.
 */
class ClassBWithIterSwapA final {};
/**
 * @brief Custom iter_swap declaration.
 */
inline void               iter_swap(PointerTo<ClassBWithIterSwapA> const &, PointerTo<ClassBWithIterSwapA> const &);
/**
 * @brief Custom iter_swap declaration.
 */
inline void               iter_swap(PointerTo<ClassAWithIterSwapSelf> const &, PointerTo<ClassBWithIterSwapA> const &);
/**
 * @brief Custom iter_swap declaration.
 */
inline void               iter_swap(PointerTo<ClassBWithIterSwapA> const &, PointerTo<ClassAWithIterSwapSelf> const &);

/**
 * @brief Test indirectly non-swappable type.
 */
class ClassCWithSemiIterSwapA final {};
/**
 * @brief Custom iter_swap declaration.
 */
inline void iter_swap(PointerTo<ClassCWithSemiIterSwapA> const &, PointerTo<ClassCWithSemiIterSwapA> const &);
/**
 * @brief Custom iter_swap declaration.
 */
inline void iter_swap(PointerTo<ClassAWithIterSwapSelf> const &, PointerTo<ClassCWithSemiIterSwapA> const &);
/**
 * @brief Removed iter declaration.
 */
inline void iter_swap(PointerTo<ClassCWithSemiIterSwapA> const &, PointerTo<ClassAWithIterSwapSelf> const &) = delete;

} // namespace test_iterator_helper

#endif // PSTL_ITERATOR_HELPER_H
