// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iterator_traits.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <portable_stl/iterator/iterator_traits.h>

/**
 * @brief Test class.
 */
class has_not_all_basic_members final {
public:
  /**
   * @brief
   */
  using value_type      = std::int32_t;
  /**
   * @brief
   */
  using reference       = std::int32_t;
  /**
   * @brief
   */
  using difference_type = std::int32_t;
};

/**
 * @brief Test class.
 */
class has_all_basic_members final {
public:
  /**
   * @brief
   */
  using iterator_category = std::int32_t;
  /**
   * @brief
   */
  using value_type        = std::int32_t;
  /**
   * @brief
   */
  using reference         = std::int64_t;
  /**
   * @brief
   */
  using difference_type   = std::int32_t;
};

/**
 * @brief Test class.
 */
class has_pointer_member final {
public:
  /**
   * @brief
   */
  using iterator_category = std::int32_t;
  /**
   * @brief
   */
  using pointer           = std::int32_t *;
};

/**
 * @brief Test class.
 */
class has_arrow_operator final {
public:
  /**
   * @brief
   */
  using iterator_category = std::int32_t;
  /**
   * @brief 
   * @return std::int16_t* 
   */
  std::int16_t *operator->();
};

TEST(iterator_traits, not_all_members) {
  static_cast<void>(test_info_);
  EXPECT_FALSE((::portable_stl::iterator_helper::specifies_members<has_not_all_basic_members>{}()));
  EXPECT_TRUE((::portable_stl::iterator_helper::specifies_members<has_all_basic_members>{}()));
}

TEST(iterator_traits, pointer_member) {
  static_cast<void>(test_info_);

  EXPECT_TRUE((std::is_same<void,
                            typename ::portable_stl::iterator_helper::iterator_traits_member_pointer_or_void<
                              has_all_basic_members>::type>{}));
  EXPECT_TRUE(
    (std::is_same<
      typename has_pointer_member::pointer,
      typename ::portable_stl::iterator_helper::iterator_traits_member_pointer_or_void<has_pointer_member>::type>{}));
}

TEST(iterator_traits, reference_member) {
  static_cast<void>(test_info_);

  // has member reference type
  EXPECT_TRUE(
    (std::is_same<
      typename has_all_basic_members::reference,
      typename ::portable_stl::iterator_helper::iterator_traits_member_reference<has_all_basic_members>::type>{}));

  // no member reference type
  EXPECT_TRUE(
    (std::is_same<std::int32_t &,
                  typename ::portable_stl::iterator_helper::iterator_traits_member_reference<std::int32_t *>::type>{}));
}

TEST(iterator_traits, iterator_traits_member_pointer_or_arrow_or_void) {
  static_cast<void>(test_info_);

  // has member pointer type
  EXPECT_TRUE((std::is_same<typename has_pointer_member::pointer,
                            typename ::portable_stl::iterator_helper::iterator_traits_member_pointer_or_arrow_or_void<
                              has_pointer_member>::type>{}));

  // no member pointer type ot .operator->()
  EXPECT_TRUE((std::is_same<void,
                            typename ::portable_stl::iterator_helper::iterator_traits_member_pointer_or_arrow_or_void<
                              has_all_basic_members>::type>{}));

  // has .operator->()
  EXPECT_TRUE((std::is_same<std::int16_t *,
                            typename ::portable_stl::iterator_helper::iterator_traits_member_pointer_or_arrow_or_void<
                              has_arrow_operator>::type>{}));
}

TEST(iterator_traits, cpp17_iterator_missing_members) {
  static_cast<void>(test_info_);

  EXPECT_FALSE((::portable_stl::iterator_helper::cpp17_iterator_missing_members<has_not_all_basic_members>{}()));
  EXPECT_FALSE((::portable_stl::iterator_helper::cpp17_iterator_missing_members<has_all_basic_members>{}()));
  EXPECT_FALSE((::portable_stl::iterator_helper::cpp17_iterator_missing_members<has_pointer_member>{}()));
  EXPECT_FALSE((::portable_stl::iterator_helper::cpp17_iterator_missing_members<std::int32_t *>{}()));
}

TEST(iterator_traits, iterator_traits_iterator_category) {
  static_cast<void>(test_info_);

  // iterator type has same category as iterator
  EXPECT_TRUE(
    (std::is_same<
      typename has_all_basic_members::iterator_category,
      typename ::portable_stl::iterator_helper::iterator_traits_iterator_category<has_all_basic_members>::type>{}));

  // iterator type has no category member type, iterator type is not an cpp17 iterator type too
  EXPECT_TRUE(
    (std::is_same<
      ::portable_stl::input_iterator_tag,
      typename ::portable_stl::iterator_helper::iterator_traits_iterator_category<has_not_all_basic_members>::type>{}));

  // iterator type has no category member type, but iterator is like cpp17_random_access_iterator
  EXPECT_TRUE((
    std::is_same<::portable_stl::random_access_iterator_tag,
                 typename ::portable_stl::iterator_helper::iterator_traits_iterator_category<std::int32_t *>::type>{}));
}

TEST(iterator_traits, iterator_traits_difference_type) {
  static_cast<void>(test_info_);

  // iterator type has diff-like type
  EXPECT_TRUE(
    (std::is_same<::portable_stl::ptrdiff_t,
                  typename ::portable_stl::iterator_helper::iterator_traits_difference_type<std::int32_t *>::type>{}));

  // iterator has diff type (typename difference_type)
  EXPECT_TRUE(
    (std::is_same<
      typename has_not_all_basic_members::difference_type,
      typename ::portable_stl::iterator_helper::iterator_traits_difference_type<has_not_all_basic_members>::type>{}));

  // iterator has no diff-like type
  EXPECT_TRUE((std::is_same<
               void,
               typename ::portable_stl::iterator_helper::iterator_traits_difference_type<has_pointer_member>::type>{}));
}

TEST(iterator_traits, iterator_traits_impl) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief
     */
    using test_iter_traits = ::portable_stl::iterator_helper::iterator_traits_impl<has_not_all_basic_members>;
    EXPECT_FALSE(
      (::portable_stl::disjunction<
        ::portable_stl::is_detected<::portable_stl::iterator_helper::has_member_iterator_category, test_iter_traits>,
        ::portable_stl::is_detected<::portable_stl::iterator_helper::has_member_difference_type, test_iter_traits>,
        ::portable_stl::is_detected<::portable_stl::iterator_helper::has_member_pointer, test_iter_traits>,
        ::portable_stl::is_detected<::portable_stl::iterator_helper::has_member_reference, test_iter_traits>,
        ::portable_stl::is_detected<::portable_stl::iterator_helper::has_member_value_type, test_iter_traits>>{}()));
  }
  {
    /**
     * @brief Test iterator traits with no members
     */
    using test_iter_traits = ::portable_stl::iterator_helper::iterator_traits_impl<has_pointer_member>;
    EXPECT_FALSE(
      (::portable_stl::disjunction<
        ::portable_stl::is_detected<::portable_stl::iterator_helper::has_member_iterator_category, test_iter_traits>,
        ::portable_stl::is_detected<::portable_stl::iterator_helper::has_member_difference_type, test_iter_traits>,
        ::portable_stl::is_detected<::portable_stl::iterator_helper::has_member_pointer, test_iter_traits>,
        ::portable_stl::is_detected<::portable_stl::iterator_helper::has_member_reference, test_iter_traits>,
        ::portable_stl::is_detected<::portable_stl::iterator_helper::has_member_value_type, test_iter_traits>>{}()));
  }
  {
    /**
     * @brief Test iterator traits with members
     */
    using test_iter_traits = ::portable_stl::iterator_helper::iterator_traits_impl<has_all_basic_members>;

    EXPECT_TRUE((::portable_stl::is_detected<::portable_stl::iterator_helper::has_member_iterator_category,
                                             test_iter_traits>{}()));
    EXPECT_TRUE(
      (::portable_stl::is_detected<::portable_stl::iterator_helper::has_member_difference_type, test_iter_traits>{}()));
    EXPECT_TRUE(
      (::portable_stl::is_detected<::portable_stl::iterator_helper::has_member_reference, test_iter_traits>{}()));
    EXPECT_TRUE(
      (::portable_stl::is_detected<::portable_stl::iterator_helper::has_member_value_type, test_iter_traits>{}()));
    EXPECT_TRUE(
      (::portable_stl::is_detected<::portable_stl::iterator_helper::has_member_pointer, test_iter_traits>{}()));

    EXPECT_TRUE((std::is_same<void, typename test_iter_traits::pointer>{}));
  }
}
