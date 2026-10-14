// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="forward_list_operations.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <algorithm>
#include <random>

#include "../common/test_allocator.h"
#include "portable_stl/forward_list/forward_list.h"
#include "portable_stl/vector/vector.h"

// [merge]

namespace test_forward_list_helper {
/**
 * @brief Helper for testing a stable sort.
 */
struct value_for_sort {
  std::int32_t a;
  std::int32_t b;
};

static bool operator<(value_for_sort const &lhs, value_for_sort const &rhs) {
  return lhs.a < rhs.a;
}

static bool operator==(value_for_sort const &lhs, value_for_sort const &rhs) {
  return (lhs.a == rhs.a) && (lhs.b == rhs.b);
}
} // namespace test_forward_list_helper

// void merge(forward_list& x);
// void merge(forward_list&& x);
TEST(forward_list, merge) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::forward_list<std::int32_t> lst1{1, 3, 7, 9, 10};
    ::portable_stl::forward_list<std::int32_t> lst2{0, 2, 4, 5, 6, 8, 11};
    ::portable_stl::forward_list<std::int32_t> lst_ref{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    lst1.merge(lst2);

    ASSERT_EQ(lst_ref, lst1);
    ASSERT_TRUE(lst2.empty());
  }

  // rvalue
  {
    ::portable_stl::forward_list<std::int32_t> lst1{1, 3, 7, 9, 10};
    ::portable_stl::forward_list<std::int32_t> lst_ref{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    lst1.merge(::portable_stl::forward_list<std::int32_t>{0, 2, 4, 5, 6, 8, 11});

    ASSERT_EQ(lst_ref, lst1);
  }

  // self
  {
    ::portable_stl::forward_list<std::int32_t> lst1{1, 3, 7, 9, 10};
    ::portable_stl::forward_list<std::int32_t> lst_ref{1, 3, 7, 9, 10};
    lst1.merge(lst1);

    ASSERT_EQ(lst_ref, lst1);
  }

  // first empty
  {
    ::portable_stl::forward_list<std::int32_t> lst1;
    ::portable_stl::forward_list<std::int32_t> lst_ref{0, 2, 4, 5, 6, 8, 11};

    lst1.merge(::portable_stl::forward_list<std::int32_t>{0, 2, 4, 5, 6, 8, 11});

    ASSERT_EQ(lst_ref, lst1);
  }

  // second empty
  {
    ::portable_stl::forward_list<std::int32_t> lst1{0, 2, 4, 5, 6, 8, 11};
    ::portable_stl::forward_list<std::int32_t> lst_ref{0, 2, 4, 5, 6, 8, 11};

    lst1.merge(::portable_stl::forward_list<std::int32_t>());

    ASSERT_EQ(lst_ref, lst1);
  }

  // pointers, references, and iterators should remain valid after merging.
  {
    /**
     * @brief List alias.
     */
    using t_flist = ::portable_stl::forward_list<std::int32_t>;

    /**
     * @brief Pointer type.
     */
    using t_pointer = std::int32_t *;

    /**
     * @brief Iterator type.
     */
    using t_iterator = t_flist::iterator;

    std::int32_t const arr0[3] = {0, 1, 2};

    t_flist                                         lst0(std::begin(arr0), std::end(arr0));
    t_iterator                                      iter0[3] = {lst0.begin(), ++lst0.begin(), ++ ++lst0.begin()};
    ::portable_stl::reference_wrapper<std::int32_t> ref0[3]
      = {::portable_stl::ref(*iter0[0]), ::portable_stl::ref(*iter0[1]), ::portable_stl::ref(*iter0[2])};
    t_pointer ptr0[3] = {&*iter0[0], &*iter0[1], &*iter0[2]};

    t_flist lst;
    lst.merge(std::move(lst0));
    ASSERT_TRUE(lst0.empty());

    for (std::size_t i{0U}; i < 3U; ++i) {
      ASSERT_EQ(*iter0[i], arr0[i]);
      ASSERT_EQ(ref0[i].get(), arr0[i]);
      ASSERT_EQ(*ptr0[i], arr0[i]);
    }
  }

  // Sorting is stable.
  {
    /**
     * @brief Alias type.
     */
    using t_type = test_forward_list_helper::value_for_sort;

    /**
     * @brief List alias.
     */
    using t_flist = ::portable_stl::forward_list<t_type>;

    t_type const arr1[] = {
      {0, 0},
      {2, 0},
      {3, 0}
    };
    t_type const arr2[] = {
      {0, 1},
      {1, 1},
      {2, 1},
      {4, 1}
    };
    t_type const arr3[] = {
      {0, 0},
      {0, 1},
      {1, 1},
      {2, 0},
      {2, 1},
      {3, 0},
      {4, 1}
    };

    t_flist lst1(std::begin(arr1), std::end(arr1));
    t_flist lst2(std::begin(arr2), std::end(arr2));

    lst1.merge(std::move(lst2));

    ASSERT_TRUE(lst2.empty());

    t_flist lst3(std::begin(arr3), std::end(arr3));
    ASSERT_EQ(lst3, lst1);
  }
}

// template <class Compare> void merge(forward_list& x, Compare comp);
// template <class Compare> void merge(forward_list&& x, Compare comp);
TEST(forward_list, merge_comp) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::forward_list<std::int32_t> lst1{10, 9, 7, 3, 1};
    ::portable_stl::forward_list<std::int32_t> lst2{11, 8, 6, 5, 4, 2, 0};
    ::portable_stl::forward_list<std::int32_t> lst_ref{11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    lst1.merge(lst2, std::greater<std::int32_t>());

    ASSERT_EQ(lst_ref, lst1);
    ASSERT_TRUE(lst2.empty());
  }

  // rvalue
  {
    ::portable_stl::forward_list<std::int32_t> lst1{10, 9, 7, 3, 1};
    ::portable_stl::forward_list<std::int32_t> lst_ref{11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    lst1.merge(::portable_stl::forward_list<std::int32_t>{11, 8, 6, 5, 4, 2, 0}, std::greater<std::int32_t>());

    ASSERT_EQ(lst_ref, lst1);
  }

  // self
  {
    ::portable_stl::forward_list<std::int32_t> lst1{10, 9, 7, 3, 1};
    ::portable_stl::forward_list<std::int32_t> lst_ref{10, 9, 7, 3, 1};
    lst1.merge(lst1, std::greater<std::int32_t>());

    ASSERT_EQ(lst_ref, lst1);
  }
}

// [splice]

namespace test_forward_list {

std::int32_t const   arr1[]    = {0, 1, 2, 3, 4, 5, 6, 7};
std::int32_t const   arr2[]    = {10, 11, 12, 13, 14, 15};
std::ptrdiff_t const size_arr1 = std::end(arr1) - std::begin(arr1);
std::ptrdiff_t const size_arr2 = std::end(arr2) - std::begin(arr2);

template<class t_list> void test_splice_after_diff1(t_list const &lst, std::int32_t pos, std::int32_t len) {
  typename t_list::const_iterator iter{lst.begin()};
  std::int32_t                    n1{0};

  for (; n1 < pos; ++n1, ++iter) {
    ASSERT_EQ(arr1[n1], *iter);
  }

  for (std::int32_t n2{0}; n2 < len; ++n2, ++iter) {
    ASSERT_EQ(arr2[n2], *iter);
  }

  for (; n1 < size_arr1; ++n1, ++iter) {
    ASSERT_EQ(arr1[n1], *iter);
  }

  ASSERT_EQ(::portable_stl::distance(lst.begin(), lst.end()), size_arr1 + len);
}

template<class t_list> void test_splice_after_diff2(t_list const &lst, std::int32_t pos, std::int32_t f) {
  typename t_list::const_iterator iter{lst.begin()};
  std::int32_t                    n1{0};

  for (; n1 < pos; ++n1, ++iter) {
    ASSERT_EQ(arr1[n1], *iter);
  }

  ASSERT_EQ(arr2[f], *iter);
  ++iter;

  for (; n1 < size_arr1; ++n1, ++iter) {
    ASSERT_EQ(arr1[n1], *iter);
  }

  ASSERT_EQ(::portable_stl::distance(lst.begin(), lst.end()), size_arr1 + 1);
}

template<class t_list> void test_splice_after_same1(t_list const &lst, std::int32_t pos, std::int32_t f) {
  typename t_list::const_iterator iter = lst.begin();
  if ((pos == f) || (pos == (f + 1))) {
    for (std::int32_t n{0}; n < size_arr1; ++n) {
      ASSERT_EQ(*iter, arr1[n]);
      ++iter;
    }
  } else if (pos < f) {
    for (std::int32_t n{0}; n < pos; ++n) {
      ASSERT_EQ(*iter, arr1[n]);
      ++iter;
    }
    {
      ASSERT_EQ(*iter, arr1[f]);
      ++iter;
    }
    for (std::int32_t n{pos}; n < f; ++n) {
      ASSERT_EQ(*iter, arr1[n]);
      ++iter;
    }
    for (std::int32_t n{f}; n < (size_arr1 - 1); ++n) {
      ASSERT_EQ(*iter, arr1[n + 1]);
      ++iter;
    }
  } else { // pos > f+1
    for (std::int32_t n{0}; n < f; ++n) {
      ASSERT_EQ(*iter, arr1[n]);
      ++iter;
    }
    for (std::int32_t n{f + 1}; n < pos; ++n) {
      ASSERT_EQ(*iter, arr1[n]);
      ++iter;
    }
    {
      ASSERT_EQ(*iter, arr1[f]);
      ++iter;
    }
    for (std::int32_t n{pos}; n < size_arr1; ++n) {
      ASSERT_EQ(*iter, arr1[n]);
      ++iter;
    }
  }
  ASSERT_EQ(size_arr1, ::portable_stl::distance(lst.begin(), lst.end()));
}

template<class t_list>
void test_splice_after_diff3(t_list const &lst, std::ptrdiff_t pos, std::ptrdiff_t first, std::ptrdiff_t last) {
  typename t_list::const_iterator iter{lst.begin()};
  std::ptrdiff_t                  n1{0};

  for (; n1 < pos; ++n1, ++iter) {
    ASSERT_EQ(arr1[n1], *iter);
  }

  for (std::ptrdiff_t n2{first}; n2 < last - 1; ++n2, ++iter) {
    ASSERT_EQ(arr2[n2], *iter);
  }

  for (; n1 < size_arr1; ++n1, ++iter) {
    ASSERT_EQ(arr1[n1], *iter);
  }

  ASSERT_EQ(::portable_stl::distance(lst.begin(), lst.end()),
            size_arr1 + (last > (first + 1) ? (last - 1) - first : 0));
}

template<class t_list>
void test_splice_after_same2(t_list const &lst, std::ptrdiff_t pos, std::ptrdiff_t first, std::ptrdiff_t last) {
  typename t_list::const_iterator iter = lst.begin();
  std::ptrdiff_t                  n{0};
  std::ptrdiff_t                  d{first < (last - 1) ? (last - 1) - first : 0};

  if ((d == 0) || (pos == first)) {
    for (n = 0; n < size_arr1; ++n) {
      ASSERT_EQ(*iter, arr1[n]);
      ++iter;
    }
  } else if (pos < first) {
    for (n = 0; n < pos; ++n) {
      ASSERT_EQ(*iter, arr1[n]);
      ++iter;
    }
    for (n = first; n < (last - 1); ++n) {
      ASSERT_EQ(*iter, arr1[n]);
      ++iter;
    }
    for (n = pos; n < first; ++n) {
      ASSERT_EQ(*iter, arr1[n]);
      ++iter;
    }
    for (n = last; n < (size_arr1 - 1); ++n) {
      ASSERT_EQ(*iter, arr1[n - 1]);
      ++iter;
    }
  } else { // pos > first
    for (n = 0; n < first; ++n) {
      ASSERT_EQ(*iter, arr1[n]);
      ++iter;
    }
    for (n = last - 1; n < pos; ++n) {
      ASSERT_EQ(*iter, arr1[n]);
      ++iter;
    }
    for (n = first; n < (last - 1); ++n) {
      ASSERT_EQ(*iter, arr1[n]);
      ++iter;
    }
    for (n = pos; n < size_arr1; ++n) {
      ASSERT_EQ(*iter, arr1[n]);
      ++iter;
    }
  }
  ASSERT_EQ(size_arr1, ::portable_stl::distance(lst.begin(), lst.end()));
}

} // namespace test_forward_list

TEST(forward_list, splice_after_whole_list) {
  static_cast<void>(test_info_);

  // splicing different containers
  for (std::int32_t len{0}; len <= test_forward_list::size_arr2; ++len) {
    for (std::int32_t pos{0}; pos <= test_forward_list::size_arr1; ++pos) {
      ::portable_stl::forward_list<std::int32_t> lst1(std::begin(test_forward_list::arr1),
                                                      std::end(test_forward_list::arr1));

      ::portable_stl::forward_list<std::int32_t> lst2(std::begin(test_forward_list::arr2),
                                                      ::portable_stl::next(std::begin(test_forward_list::arr2), len));

      lst1.splice_after(::portable_stl::next(lst1.cbefore_begin(), pos), std::move(lst2));
      test_forward_list::test_splice_after_diff1(lst1, pos, len);
    }
  }
}

TEST(forward_list, splice_after_list_iter) {
  static_cast<void>(test_info_);

  // splicing different containers
  for (std::int32_t f{0}; f <= (test_forward_list::size_arr2 - 1); ++f) {
    for (std::int32_t pos{0}; pos <= test_forward_list::size_arr1; ++pos) {
      ::portable_stl::forward_list<std::int32_t> lst1(std::begin(test_forward_list::arr1),
                                                      std::end(test_forward_list::arr1));
      ::portable_stl::forward_list<std::int32_t> lst2(std::begin(test_forward_list::arr2),
                                                      std::end(test_forward_list::arr2));

      lst1.splice_after(::portable_stl::next(lst1.cbefore_begin(), pos),
                        std::move(lst2),
                        ::portable_stl::next(lst2.cbefore_begin(), f));
      test_forward_list::test_splice_after_diff2(lst1, pos, f);
    }
  }

  // splicing within same container
  for (std::int32_t f{0}; f <= (test_forward_list::size_arr1 - 1); ++f) {
    for (std::int32_t pos{0}; pos <= test_forward_list::size_arr1; ++pos) {
      ::portable_stl::forward_list<std::int32_t> lst1(std::begin(test_forward_list::arr1),
                                                      std::end(test_forward_list::arr1));

      lst1.splice_after(::portable_stl::next(lst1.cbefore_begin(), pos),
                        std::move(lst1),
                        ::portable_stl::next(lst1.cbefore_begin(), f));
      test_forward_list::test_splice_after_same1(lst1, pos, f);
    }
  }
}

TEST(forward_list, splice_after_list_iter_iter) {
  static_cast<void>(test_info_);

  // splicing different containers
  for (std::ptrdiff_t first{0}; first <= (test_forward_list::size_arr2 + 1); ++first) {
    for (std::ptrdiff_t last{first}; last <= (test_forward_list::size_arr2 + 1); ++last) {
      for (std::ptrdiff_t pos{0}; pos <= test_forward_list::size_arr1; ++pos) {
        ::portable_stl::forward_list<std::int32_t> lst1(std::begin(test_forward_list::arr1),
                                                        std::end(test_forward_list::arr1));
        ::portable_stl::forward_list<std::int32_t> lst2(std::begin(test_forward_list::arr2),
                                                        std::end(test_forward_list::arr2));

        lst1.splice_after(::portable_stl::next(lst1.cbefore_begin(), pos),
                          std::move(lst2),
                          ::portable_stl::next(lst2.cbefore_begin(), first),
                          ::portable_stl::next(lst2.cbefore_begin(), last));
        test_forward_list::test_splice_after_diff3(lst1, pos, first, last);
      }
    }
  }

  // splicing within same container
  for (std::ptrdiff_t first{0}; first <= (test_forward_list::size_arr1 + 1); ++first) {
    for (std::ptrdiff_t last{first}; last <= (test_forward_list::size_arr1); ++last) {
      for (std::ptrdiff_t pos{0}; pos <= first; ++pos) {
        ::portable_stl::forward_list<std::int32_t> lst1(std::begin(test_forward_list::arr1),
                                                        std::end(test_forward_list::arr1));

        lst1.splice_after(::portable_stl::next(lst1.cbefore_begin(), pos),
                          std::move(lst1),
                          ::portable_stl::next(lst1.cbefore_begin(), first),
                          ::portable_stl::next(lst1.cbefore_begin(), last));
        test_forward_list::test_splice_after_same2(lst1, pos, first, last);
      }
      for (std::ptrdiff_t pos{last}; pos <= test_forward_list::size_arr1; ++pos) {
        ::portable_stl::forward_list<std::int32_t> lst1(std::begin(test_forward_list::arr1),
                                                        std::end(test_forward_list::arr1));

        lst1.splice_after(::portable_stl::next(lst1.cbefore_begin(), pos),
                          std::move(lst1),
                          ::portable_stl::next(lst1.cbefore_begin(), first),
                          ::portable_stl::next(lst1.cbefore_begin(), last));
        test_forward_list::test_splice_after_same2(lst1, pos, first, last);
      }
    }
  }
}
// [remove]

namespace test_forward_list_helper {
class class_for_remove final {
  std::int32_t *m_int;

public:
  class_for_remove(std::int32_t i) : m_int(std::make_unique<std::int32_t>(i).release()) {
  }

  class_for_remove(class_for_remove const &rhs) : m_int(std::make_unique<std::int32_t>(*rhs.m_int).release()) {
  }

  class_for_remove &operator=(class_for_remove const &rhs) & noexcept {
    *m_int = *rhs.m_int;
    return *this;
  }

  ~class_for_remove() {
    delete m_int;
    m_int = NULL;
  }

  bool operator==(class_for_remove const &rhs) const noexcept {
    return *m_int == *rhs.m_int;
  }

  std::int32_t get() const noexcept {
    return *m_int;
  }
};

template<class t_list>
void do_remove(
  t_list &lst, typename t_list::value_type const &value, typename t_list::value_type const &expected_removed) {
  auto old_size = ::portable_stl::distance(lst.begin(), lst.end());

  ASSERT_TRUE((std::is_same<decltype(lst.remove(value)), typename t_list::size_type>{}));

  auto result = lst.remove(value);
  ASSERT_EQ(expected_removed, result);

  ASSERT_EQ(expected_removed, old_size - ::portable_stl::distance(lst.begin(), lst.end()));
}
} // namespace test_forward_list_helper

// size_type remove(const value_type& value);
TEST(forward_list, remove) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   */
  using t_forward_list = ::portable_stl::forward_list<std::int32_t>;

  {
    std::int32_t a1[] = {0, 5, 5, 0, 0, 0, 5};
    std::int32_t a2[] = {5, 5, 5};

    t_forward_list lst(std::begin(a1), std::end(a1));
    t_forward_list lst_ref(std::begin(a2), std::end(a2));

    ::test_forward_list_helper::do_remove(lst, 0, 4);
    ASSERT_EQ(lst_ref, lst);
  }
  {
    std::int32_t a1[] = {0, 0, 0, 0};

    t_forward_list lst(std::begin(a1), std::end(a1));
    t_forward_list lst_ref;

    ::test_forward_list_helper::do_remove(lst, 0, 4);
    ASSERT_EQ(lst_ref, lst);
  }
  {
    std::int32_t a1[] = {5, 5, 5};
    std::int32_t a2[] = {5, 5, 5};

    t_forward_list lst(std::begin(a1), std::end(a1));
    t_forward_list lst_ref(std::begin(a2), std::end(a2));

    ::test_forward_list_helper::do_remove(lst, 0, 0);
    ASSERT_EQ(lst_ref, lst);
  }
  {
    t_forward_list lst;
    t_forward_list lst_ref;

    ::test_forward_list_helper::do_remove(lst, 0, 0);
    ASSERT_EQ(lst_ref, lst);
  }
  {
    std::int32_t a1[] = {5, 5, 5, 0};
    std::int32_t a2[] = {5, 5, 5};

    t_forward_list lst(std::begin(a1), std::end(a1));
    t_forward_list lst_ref(std::begin(a2), std::end(a2));

    ::test_forward_list_helper::do_remove(lst, 0, 1);
    ASSERT_EQ(lst_ref, lst);
  }
  {
    // clang-format off
    std::int32_t a1[] = {1, 2, 1, 3, 5, 8, 11};
    std::int32_t a2[] = {   2,    3, 5, 8, 11};
    // clang-format on

    t_forward_list lst(std::begin(a1), std::end(a1));
    t_forward_list lst_ref(std::begin(a2), std::end(a2));

    ::test_forward_list_helper::do_remove(lst, lst.front(), 2);
    ASSERT_EQ(lst_ref, lst);
  }

  /**
   * @brief Alias.
   */
  using t_type = test_forward_list_helper::class_for_remove;

  /**
   * @brief Alias.
   */
  using t_forward_list2 = ::portable_stl::forward_list<t_type>;
  {
    // clang-format off
    std::int32_t a1[] = {1, 2, 1, 3, 5, 8, 11, 1};
    std::int32_t a2[] = {   2,    3, 5, 8, 11   };
    // clang-format on

    t_forward_list2 lst;

    for (std::int32_t *ip{std::end(a1)}; ip != std::begin(a1);) {
      lst.push_front(t_type(*--ip));
    }

    do_remove(lst, lst.front(), 3);

    t_forward_list2::const_iterator iter{lst.begin()};

    for (std::int32_t *ip{std::begin(a2)}; ip != std::end(a2); ++ip, ++iter) {
      ASSERT_NE(iter, lst.end());
      ASSERT_EQ(*ip, iter->get());
    }
    ASSERT_EQ(iter, lst.end());
  }
}

namespace test_forward_list_helper {

static bool g(std::int32_t i) {
  return i < 3;
}

static bool g2(std::int32_t lhv, std::int32_t rhv) {
  return lhv == rhv;
}

class PredLWG526 final {
  std::int32_t m_int;

public:
  PredLWG526(std::int32_t i) : m_int(i) {
  }

  PredLWG526(PredLWG526 const &other) = default;

  ~PredLWG526() {
    m_int = -32767;
  }

  bool operator()(PredLWG526 const &p) const noexcept {
    return p.m_int == m_int;
  }

  bool operator()(PredLWG526 const &lhs, PredLWG526 const &rhs) const {
    return lhs.m_int == rhs.m_int;
  }

  bool operator==(std::int32_t i) const noexcept {
    return i == m_int;
  }
};

template<typename t_pred, typename t_arg> class unary_counting_predicate final {
  t_pred              m_pred;
  mutable std::size_t m_count;

public:
  typedef t_arg argument_type;
  typedef bool  result_type;

  unary_counting_predicate(t_pred p) : m_pred(p), m_count(0) {
  }
  unary_counting_predicate(unary_counting_predicate const &)            = default;
  unary_counting_predicate &operator=(unary_counting_predicate const &) = default;
  ~unary_counting_predicate() {
  }

  bool operator()(t_arg const &a) const {
    ++m_count;
    return m_pred(a);
  }
  std::size_t count() const {
    return m_count;
  }
  void reset() {
    m_count = 0;
  }
};

using Predicate = unary_counting_predicate<bool (*)(std::int32_t), std::int32_t>;

template<class t_list, class t_pred>
void do_remove_if(t_list &lst, t_pred pred, typename t_list::value_type const &expected_removed) {
  auto old_size = ::portable_stl::distance(lst.begin(), lst.end());

  ASSERT_TRUE((std::is_same<decltype(lst.remove_if(pred)), typename t_list::size_type>{}));

  auto result = lst.remove_if(pred);
  ASSERT_EQ(expected_removed, result);

  ASSERT_EQ(expected_removed, old_size - ::portable_stl::distance(lst.begin(), lst.end()));
}
} // namespace test_forward_list_helper

// size_type remove_if(Pred pred);
TEST(forward_list, remove_pred) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   */
  using t_forward_list = ::portable_stl::forward_list<std::int32_t>;

  {
    std::int32_t a1[] = {0, 5, 5, 0, 0, 0, 5};
    std::int32_t a2[] = {5, 5, 5};

    t_forward_list                      lst(std::begin(a1), std::end(a1));
    t_forward_list                      lst_ref(std::begin(a2), std::end(a2));
    test_forward_list_helper::Predicate cout_pred(test_forward_list_helper::g);

    ::test_forward_list_helper::do_remove_if(lst, std::ref(cout_pred), 4);
    ASSERT_EQ(lst_ref, lst);
  }
  {
    std::int32_t a1[] = {0, 0, 0, 0};

    t_forward_list                      lst(std::begin(a1), std::end(a1));
    t_forward_list                      lst_ref;
    test_forward_list_helper::Predicate cout_pred(test_forward_list_helper::g);

    ::test_forward_list_helper::do_remove_if(lst, std::ref(cout_pred), 4);
    ASSERT_EQ(lst_ref, lst);
  }
  {
    std::int32_t a1[] = {5, 5, 5};
    std::int32_t a2[] = {5, 5, 5};

    t_forward_list                      lst(std::begin(a1), std::end(a1));
    t_forward_list                      lst_ref(std::begin(a2), std::end(a2));
    test_forward_list_helper::Predicate cout_pred(test_forward_list_helper::g);

    ::test_forward_list_helper::do_remove_if(lst, std::ref(cout_pred), 0);
    ASSERT_EQ(lst_ref, lst);
  }
  {
    t_forward_list                      lst;
    t_forward_list                      lst_ref;
    test_forward_list_helper::Predicate cout_pred(test_forward_list_helper::g);

    ::test_forward_list_helper::do_remove_if(lst, std::ref(cout_pred), 0);
    ASSERT_EQ(lst_ref, lst);
  }
  {
    std::int32_t a1[] = {5, 5, 5, 0};
    std::int32_t a2[] = {5, 5, 5};

    t_forward_list                      lst(std::begin(a1), std::end(a1));
    t_forward_list                      lst_ref(std::begin(a2), std::end(a2));
    test_forward_list_helper::Predicate cout_pred(test_forward_list_helper::g);

    ::test_forward_list_helper::do_remove_if(lst, std::ref(cout_pred), 1);
    ASSERT_EQ(lst_ref, lst);
  }

  // LWG issue #526
  {
    // clang-format off
    std::int32_t a1[] = {1, 2, 1, 3, 5, 8, 11};
    std::int32_t a2[] = {   2,    3, 5, 8, 11};
    // clang-format on

    ::portable_stl::forward_list<test_forward_list_helper::PredLWG526> lst(a1, a1 + 7);

    ::test_forward_list_helper::do_remove_if(lst, std::ref(lst.front()), 2);
    for (std::int32_t i{0}; i < 5; ++i) {
      ASSERT_FALSE(lst.empty());
      ASSERT_EQ(lst.front(), a2[i]); // do not swap position
      lst.pop_front();
    }
    ASSERT_TRUE(lst.empty());
  }
}

// [reverse]

// void reverse() noexcept;
TEST(forward_list, reverse) {
  static_cast<void>(test_info_);

  // one element
  {
    ::portable_stl::forward_list<std::int32_t> lst{9};

    lst.reverse();

    ASSERT_EQ((::portable_stl::forward_list<std::int32_t>{9}), lst);
  }

  {
    ::portable_stl::forward_list<std::int32_t> lst{11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    lst.reverse();
    ASSERT_EQ((::portable_stl::forward_list<std::int32_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}), lst);
  }
}

// [unique]

// size_type unique();
TEST(forward_list, unique) {
  static_cast<void>(test_info_);

  std::int32_t a1[]    = {2, 1, 1, 4, 4, 4, 4, 3, 3};
  std::int32_t a2[]    = {2, 1, 4, 3};
  using t_forward_list = ::portable_stl::forward_list<std::int32_t>;

  t_forward_list lst(a1, a1 + sizeof(a1) / sizeof(a1[0]));

  ASSERT_TRUE((std::is_same<t_forward_list::size_type, decltype(lst.unique())>{}));
  ASSERT_EQ(5, lst.unique());

  ASSERT_EQ(t_forward_list(a2, a2 + 4), lst);
}

// template <class BinaryPred> size_type unique(BinaryPred pred);
TEST(forward_list, unique_pred) {
  static_cast<void>(test_info_);

  {
    std::int32_t a1[]    = {2, 1, 1, 4, 4, 4, 4, 3, 3};
    std::int32_t a2[]    = {2, 1, 4, 3};
    using t_forward_list = ::portable_stl::forward_list<std::int32_t>;
    t_forward_list lst(a1, a1 + sizeof(a1) / sizeof(a1[0]));
    ASSERT_TRUE((std::is_same<t_forward_list::size_type, decltype(lst.unique(test_forward_list_helper::g2))>{}));
    ASSERT_EQ(5, lst.unique(test_forward_list_helper::g2));
    ASSERT_EQ(::portable_stl::forward_list<std::int32_t>(a2, a2 + 4), lst);
  }

  { // LWG issue #526
    std::int32_t                                                         a1[] = {1, 1, 1, 2, 3, 5, 5, 2, 11};
    std::int32_t                                                         a2[] = {1, 2, 3, 5, 2, 11};
    ::portable_stl::forward_list<::test_forward_list_helper::PredLWG526> lst(a1, a1 + 9);
    ASSERT_EQ(3, lst.unique(std::ref(lst.front())));

    ASSERT_EQ(6, ::portable_stl::distance(lst.begin(), lst.end()));

    std::size_t i{0U};
    while (!lst.empty()) {
      ASSERT_EQ(lst.front(), a2[i]); // do not change order
      lst.pop_front();
      ++i;
    }
  }
}

// [sort]

namespace test_forward_list_helper {
class SortPayload final {
  std::int32_t m_val;

public:
  SortPayload(std::int32_t v) : m_val(v), m_side(0) {
  }

  SortPayload(std::int32_t v, std::int32_t s) : m_val(v), m_side(s) {
  }

  bool operator<(SortPayload const &rhs) const {
    return m_val < rhs.m_val;
  }

  std::int32_t getVal() const noexcept {
    return m_val;
  }

  std::int32_t m_side;
  //     bool operator==(const SortPayload &rhs) const { return val == rhs.val;}
};

static bool greater(SortPayload const &lhs, SortPayload const &rhs) {
  return lhs.getVal() > rhs.getVal();
}

static void test_stable(std::int32_t num) {
  std::mt19937 randomness;

  using t_type         = SortPayload;
  using t_forward_list = ::portable_stl::forward_list<t_type>;
  using t_vector       = ::portable_stl::vector<t_type>;
  using t_vector_std   = std::vector<t_type>;

  t_vector_std vec_std;
  for (std::int32_t i{0}; i < num; ++i) {
    vec_std.push_back(SortPayload(i / 2));
  }

  std::shuffle(vec_std.begin(), vec_std.end(), randomness);
  t_vector vec;
  for (auto &i : vec_std) {
    vec.push_back(i);
  }

  for (std::int32_t i{0}; i < num; ++i) {
    vec[static_cast<::portable_stl::size_t>(i)].m_side = i;
  }

  t_forward_list lst(vec.begin(), vec.end());
  lst.sort();
  ASSERT_EQ(num, ::portable_stl::distance(lst.begin(), lst.end()));

  //  Are we sorted?
  t_forward_list::const_iterator j = lst.begin();
  for (std::int32_t i{0}; i < num; ++i, ++j) {
    ASSERT_EQ((i / 2), j->getVal());
  }

  //  Are we stable?
  for (t_forward_list::const_iterator it = lst.begin(); it != lst.end(); ++it) {
    t_forward_list::const_iterator next = ::portable_stl::next(it);
    if ((next != lst.end()) && (it->getVal() == next->getVal())) {
      ASSERT_TRUE(it->m_side < next->m_side);
    }
  }
}

static void test_stable2(std::int32_t num) {
  std::mt19937 randomness;

  using t_type         = SortPayload;
  using t_forward_list = ::portable_stl::forward_list<t_type>;
  using t_vector       = ::portable_stl::vector<t_type>;
  using t_vector_std   = std::vector<t_type>;

  t_vector_std vec_std;
  for (std::int32_t i{0}; i < num; ++i) {
    vec_std.push_back(SortPayload(i / 2));
  }

  std::shuffle(vec_std.begin(), vec_std.end(), randomness);
  t_vector vec;
  for (auto &i : vec_std) {
    vec.push_back(i);
  }

  for (std::int32_t i{0}; i < num; ++i) {
    vec[static_cast<::portable_stl::size_t>(i)].m_side = i;
  }

  t_forward_list lst(vec.begin(), vec.end());
  lst.sort(greater);
  ASSERT_EQ(num, ::portable_stl::distance(lst.begin(), lst.end()));

  //  Are we sorted?
  t_forward_list::const_iterator j = lst.begin();
  for (std::int32_t i{0}; i < num; ++i, ++j) {
    ASSERT_EQ(j->getVal(), (num - 1 - i) / 2);
  }

  //  Are we stable?
  for (t_forward_list::const_iterator it = lst.begin(); it != lst.end(); ++it) {
    t_forward_list::const_iterator next = ::portable_stl::next(it);
    if ((next != lst.end()) && (it->getVal() == next->getVal())) {
      ASSERT_TRUE(it->m_side < next->m_side);
    }
  }
}
} // namespace test_forward_list_helper

// void sort();
TEST(forward_list, sort) {
  static_cast<void>(test_info_);

  {
    std::int32_t a1[] = {4, 8, 1, 0, 5, 7, 2, 3, 6, 11, 10, 9};
    std::int32_t a2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    ::portable_stl::forward_list<std::int32_t> lst(a1, a1 + sizeof(a1) / sizeof(a1[0]));
    lst.sort();
    ASSERT_EQ(::portable_stl::forward_list<std::int32_t>(a2, a2 + sizeof(a2) / sizeof(a2[0])), lst);
  }

  {
    for (int i{0}; i < 40; ++i) {
      test_forward_list_helper::test_stable(i);
    }
  }
}

// template <class Compare> sort(Compare comp);
TEST(forward_list, sort_comp) {
  static_cast<void>(test_info_);

  {
    std::int32_t a1[] = {4, 8, 1, 0, 5, 7, 2, 3, 6, 11, 10, 9};
    std::int32_t a2[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    ::portable_stl::forward_list<std::int32_t> lst(a1, a1 + sizeof(a1) / sizeof(a1[0]));
    lst.sort(std::greater<int>());
    ASSERT_EQ(::portable_stl::forward_list<std::int32_t>(a2, a2 + sizeof(a2) / sizeof(a2[0])), lst);
  }

  {
    for (int i{0}; i < 40; ++i) {
      test_forward_list_helper::test_stable2(i);
    }
  }
}
