// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="concepts.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "concepts_helper.h"
#include "metaprogramming_type_relations_helper.h"
#include "portable_stl/array/array.h"
#include "portable_stl/common/nullptr_t.h"
#include "portable_stl/concepts/assignable_from.h"
#include "portable_stl/concepts/boolean_testable.h"
#include "portable_stl/concepts/common_reference_with.h"
#include "portable_stl/concepts/common_with.h"
#include "portable_stl/concepts/copyable.h"
#include "portable_stl/concepts/default_initializable.h"
#include "portable_stl/concepts/dereferenceable.h"
#include "portable_stl/concepts/derived_from.h"
#include "portable_stl/concepts/destructible.h"
#include "portable_stl/concepts/equality_comparable.h"
#include "portable_stl/concepts/integral.h"
#include "portable_stl/concepts/move_constructible.h"
#include "portable_stl/concepts/regular.h"
#include "portable_stl/concepts/swappable.h"
#include "portable_stl/concepts/swappable_with.h"
#include "portable_stl/concepts/totally_ordered.h"
#include "test_debug_helper.h"

namespace test_concepts_helpers {

/**
 * @brief Char type alias.
 */
using charT = char;

/**
 * @brief Check function.
 *
 * @tparam T Given type.
 * @tparam U Given type.
 * @param c_name Test id.
 */
template<class T, class U> static void CheckCommonReferenceWith(charT const *c_name = "") noexcept {
  // clang-format off
  ASSERT_TRUE((::portable_stl::common_reference_with<T, U>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T, U &>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T, U const &>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T, U volatile &>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T, U const volatile &>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T, U &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T, U const &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T, U volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T, U const volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T &, U &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T &, U const &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T &, U volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T &, U const volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T const &, U &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T const &, U const &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T const &, U volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T const &, U const volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T volatile &, U &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T volatile &, U const &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T volatile &, U volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T volatile &, U const volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T const volatile &, U &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T const volatile &, U const &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T const volatile &, U volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_reference_with<T const volatile &, U const volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  // clang-format on
}

/**
 * @brief Check function.
 *
 * @tparam T Given type.
 * @tparam U Given type.
 * @param c_name Test id.
 */
template<class T, class U> static void CheckCommonWith(charT const *c_name = "") noexcept {
  // clang-format off
  ASSERT_TRUE((::portable_stl::common_with<T, U>{}()))<< " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T, U &>{}()))<< " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T, U const &>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T, U volatile &>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T, U const volatile &>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T, U &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T, U const &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T, U volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T, U const volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T &, U &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T &, U const &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T &, U volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T &, U const volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T const &, U &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T const &, U const &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T const &, U volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T const &, U const volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T volatile &, U &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T volatile &, U const &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T volatile &, U volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T volatile &, U const volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T const volatile &, U &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T const volatile &, U const &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T const volatile &, U volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  ASSERT_TRUE((::portable_stl::common_with<T const volatile &, U const volatile &&>{}())) << " " << c_name << " " << typeid(T).name() << " <-> "<< typeid(U).name();
  // clang-format on
}
} // namespace test_concepts_helpers

TEST(concepts, boolean_testable) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::concepts_helper::is_bool_type<bool>;
    EXPECT_TRUE((test_type{}()));
  }
  {
    ::portable_stl::concepts_helper::is_bool_type<void> checker{};
    EXPECT_FALSE((checker()));
  }
  {
    typename ::portable_stl::concepts_helper::boolean_testable_impl<void>::type checker{};
    EXPECT_FALSE((checker()));
  }
  EXPECT_TRUE((::portable_stl::boolean_testable<bool>{}()));
}

TEST(concepts, copyable) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::copyable<std::int32_t>;
    EXPECT_TRUE((test_type{}()));
  }
  EXPECT_FALSE((::portable_stl::copyable<std::int32_t const>{}()));
}

TEST(concepts, default_initializable) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::default_initializable<std::int32_t>;
    EXPECT_TRUE((test_type{}()));
  }
  {
    typename ::portable_stl::concepts_helper::default_initializable_impl<test_concepts_helpers::no_default_ctor>::type
      checker{};
    EXPECT_FALSE((checker()));
  }
}

TEST(concepts, derived_from) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::derived_from<metaprogramming_type_relations_helper::Derived1,
                                                   metaprogramming_type_relations_helper::Base1>;
    EXPECT_TRUE((test_type{}()));
  }
}

// from
// https://github.com/llvm/llvm-project/blob/main/libcxx/test/std/concepts/concepts.lang/concept.commonref/common_reference.compile.pass.cpp
TEST(concepts, common_reference_with) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::common_reference_with<std::int32_t *, void *>;
    test_type checker{};
    ASSERT_TRUE((checker()));
  }

  // fundamental types
  EXPECT_TRUE((::portable_stl::common_reference_with<void, void>{}()));
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t, std::int32_t>("1");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t, std::int64_t>("2");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t, std::uint8_t>("3");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t, double>("4");

  // arrays
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t[5], std::int32_t[5]>("5");

  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t *, std::int32_t const *>("6");
  // test_concepts_helpers::CheckCommonReferenceWith<std::int32_t *, std::int32_t *>("6.1");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t *, std::int32_t volatile *>("7");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t *, std::int32_t const volatile *>("8");

  // pointers (common with void*)
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t *, void *>("5");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t *, void const *>("6");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t *, void volatile *>("7");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t *, void const volatile *>("8");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t const *, void *>("9");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t const *, void const *>("10");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t const *, void volatile *>("11");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t const *, void const volatile *>("12");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t volatile *, void *>("13");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t volatile *, void const *>("14");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t volatile *, void volatile *>("15");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t volatile *, void const volatile *>("16");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t const volatile *, void *>("17");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t const volatile *, void const *>("18");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t const volatile *, void volatile *>("19");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t const volatile *, void const volatile *>("20");

  // test_concepts_helpers::CheckCommonReferenceWith<std::int32_t (*)(), std::int32_t (*)()>("21");
  // test_concepts_helpers::CheckCommonReferenceWith<std::int32_t (*)(), std::int32_t (*)() noexcept>("22");

  /**
   * @brief Empty class.
   */
  using EmptyClass = metaprogramming_type_relations_helper::Base1;
  // test_concepts_helpers::CheckCommonReferenceWith<std::int32_t EmptyClass::*, std::int32_t EmptyClass::*>("23");
  test_concepts_helpers::CheckCommonReferenceWith<std::int32_t EmptyClass::*, std::int32_t const EmptyClass::*>("24");
  // test_concepts_helpers::CheckCommonReferenceWith<std::int32_t (EmptyClass::*)(), std::int32_t
  // (EmptyClass::*)()>("25"); test_concepts_helpers::CheckCommonReferenceWith<std::int32_t (EmptyClass::*)(),
  // std::int32_t (EmptyClass::*)() noexcept>("26"); test_concepts_helpers::CheckCommonReferenceWith<std::int32_t
  // (EmptyClass::*)() const, std::int32_t (EmptyClass::*)() const>("27");
  // test_concepts_helpers::CheckCommonReferenceWith<std::int32_t (EmptyClass::*)() const, std::int32_t
  // (EmptyClass::*)() const noexcept>("28"); test_concepts_helpers::CheckCommonReferenceWith<std::int32_t
  // (EmptyClass::*)() volatile, std::int32_t (EmptyClass::*)() volatile>("29");
  // test_concepts_helpers::CheckCommonReferenceWith<std::int32_t (EmptyClass::*)() volatile, std::int32_t
  // (EmptyClass::*)() volatile noexcept>("30"); test_concepts_helpers::CheckCommonReferenceWith<std::int32_t
  // (EmptyClass::*)() const volatile, std::int32_t (EmptyClass::*)() const volatile>("31");
  // test_concepts_helpers::CheckCommonReferenceWith<std::int32_t (EmptyClass::*)() const volatile, std::int32_t
  // (EmptyClass::*)() const volatile noexcept>(
  //   "32");

  // nonsense
  EXPECT_FALSE((::portable_stl::common_reference_with<double, float *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<std::int32_t, std::int32_t[1]>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<std::int32_t *, std::int64_t *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<std::int32_t *, std::uint32_t *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<std::int32_t (*)(), std::int32_t (*)(std::int32_t)>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<std::int32_t EmptyClass::*, float EmptyClass::*>{}()));
  EXPECT_FALSE(
    (::portable_stl::common_reference_with<std::int32_t (EmptyClass::*)(), std::int32_t (EmptyClass::*)() const>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<std::int32_t (EmptyClass::*)(),
                                                      std::int32_t (EmptyClass::*)() volatile>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<std::int32_t (EmptyClass::*)(),
                                                      std::int32_t (EmptyClass::*)() const volatile>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<std::int32_t (EmptyClass::*)() const,
                                                      std::int32_t (EmptyClass::*)() volatile>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<std::int32_t (EmptyClass::*)() const,
                                                      std::int32_t (EmptyClass::*)() const volatile>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<std::int32_t (EmptyClass::*)() volatile,
                                                      std::int32_t (EmptyClass::*)() const volatile>{}()));

  // no default common reference
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass, std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<std::int32_t, EmptyClass>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass, std::int32_t[1]>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass[1], std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass *, std::int32_t *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass *, std::int32_t const *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass *, std::int32_t volatile *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass *, std::int32_t const volatile *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const *, std::int32_t *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile *, std::int32_t *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile *, std::int32_t *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const *, std::int32_t const *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const *, std::int32_t volatile *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const *, std::int32_t const volatile *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const *, std::int32_t const *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile *, std::int32_t const *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile *, std::int32_t const *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile *, std::int32_t const *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile *, std::int32_t volatile *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile *, std::int32_t const volatile *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const *, std::int32_t volatile *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile *, std::int32_t volatile *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile *, std::int32_t volatile *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile *, std::int32_t const *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile *, std::int32_t volatile *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile *, std::int32_t const volatile *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const *, std::int32_t const volatile *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile *, std::int32_t const volatile *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile *, std::int32_t const volatile *>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass &, std::int32_t &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass &, std::int32_t const &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass &, std::int32_t volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass &, std::int32_t const volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &, std::int32_t &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &, std::int32_t &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &, std::int32_t &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &, std::int32_t const &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &, std::int32_t volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &, std::int32_t const volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &, std::int32_t const &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &, std::int32_t const &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &, std::int32_t const &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &, std::int32_t const &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &, std::int32_t volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &, std::int32_t const volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &, std::int32_t volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &, std::int32_t volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &, std::int32_t volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &, std::int32_t const &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &, std::int32_t volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &, std::int32_t const volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &, std::int32_t const volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &, std::int32_t const volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &, std::int32_t const volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass &, std::int32_t &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass &, std::int32_t const &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass &, std::int32_t volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass &, std::int32_t const volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &, std::int32_t &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &, std::int32_t &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &, std::int32_t &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &, std::int32_t const &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &, std::int32_t volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &, std::int32_t const volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &, std::int32_t const &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &, std::int32_t const &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &, std::int32_t const &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &, std::int32_t const &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &, std::int32_t volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &, std::int32_t const volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &, std::int32_t volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &, std::int32_t volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &, std::int32_t volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &, std::int32_t const &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &, std::int32_t volatile &&>{}()));
  EXPECT_FALSE(
    (::portable_stl::common_reference_with<EmptyClass const volatile &, std::int32_t const volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &, std::int32_t const volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &, std::int32_t const volatile &&>{}()));
  EXPECT_FALSE(
    (::portable_stl::common_reference_with<EmptyClass const volatile &, std::int32_t const volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass &&, std::int32_t &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass &&, std::int32_t const &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass &&, std::int32_t volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass &&, std::int32_t const volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &&, std::int32_t &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &&, std::int32_t &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &&, std::int32_t &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &&, std::int32_t const &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &&, std::int32_t volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &&, std::int32_t const volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &&, std::int32_t const &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &&, std::int32_t const &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &&, std::int32_t const &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &&, std::int32_t const &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &&, std::int32_t volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &&, std::int32_t const volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &&, std::int32_t volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &&, std::int32_t volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &&, std::int32_t volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &&, std::int32_t const &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &&, std::int32_t volatile &>{}()));
  EXPECT_FALSE(
    (::portable_stl::common_reference_with<EmptyClass const volatile &&, std::int32_t const volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &&, std::int32_t const volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &&, std::int32_t const volatile &>{}()));
  EXPECT_FALSE(
    (::portable_stl::common_reference_with<EmptyClass const volatile &&, std::int32_t const volatile &>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass &&, std::int32_t &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass &&, std::int32_t const &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass &&, std::int32_t volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass &&, std::int32_t const volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &&, std::int32_t &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &&, std::int32_t &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &&, std::int32_t &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &&, std::int32_t const &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &&, std::int32_t volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &&, std::int32_t const volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &&, std::int32_t const &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &&, std::int32_t const &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &&, std::int32_t const &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &&, std::int32_t const &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &&, std::int32_t volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &&, std::int32_t const volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &&, std::int32_t volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &&, std::int32_t volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &&, std::int32_t volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &&, std::int32_t const &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const volatile &&, std::int32_t volatile &&>{}()));
  EXPECT_FALSE(
    (::portable_stl::common_reference_with<EmptyClass const volatile &&, std::int32_t const volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass const &&, std::int32_t const volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::common_reference_with<EmptyClass volatile &&, std::int32_t const volatile &&>{}()));
  EXPECT_FALSE(
    (::portable_stl::common_reference_with<EmptyClass const volatile &&, std::int32_t const volatile &&>{}()));
}

TEST(concepts, DISABLED_common_with) {
  static_cast<void>(test_info_);
  // {
  //   using T = int *;
  //   using U = int const *;
  //   EXPECT_TRUE((typename ::portable_stl::concepts_helper::common_with_req<T, U>::type{}()));

  //   using com_type1 = ::portable_stl::common_type_t<T, U>;
  //   using com_type2 = ::portable_stl::common_type_t<U, T>;
  //   EXPECT_TRUE((::portable_stl::same_as<com_type1, com_type2>{}()));

  //   using clvT = ::portable_stl::add_lvalue_reference_t<T const>;
  //   using clvU = ::portable_stl::add_lvalue_reference_t<U const>;
  //   EXPECT_TRUE((::portable_stl::common_reference_with<clvT, clvU>{}()));

  //   using st1 = ::portable_stl::add_lvalue_reference_t<com_type1>;
  //   using st2 = ::portable_stl::common_reference_t<clvT, clvU>;

  //   using st3 = ::portable_stl::common_reference_t<T, U>;
  //   using st4 = ::portable_stl::common_reference_t<U, T>;
  //   print_type_info<st1>();
  //   print_type_info<st2>();
  //   print_type_info<st3>();
  //   print_type_info<st4>();

  //   EXPECT_TRUE((::portable_stl::convertible_to<st1, st3>{}()));
  //   EXPECT_TRUE((::portable_stl::convertible_to<st2, st3>{}()));
  //   EXPECT_TRUE((typename ::portable_stl::concepts_helper::common_reference_with_impl<st1, st2>::type{}()));
  //   EXPECT_TRUE((::portable_stl::common_reference_with<st1, st2>{}()));
  //   EXPECT_TRUE((::portable_stl::common_with<T, U>{}()));
  // }

  EXPECT_TRUE((::portable_stl::common_with<std::int32_t, std::int32_t>{}()));
  EXPECT_TRUE((::portable_stl::common_with<std::int32_t, std::int32_t const>{}()));
  EXPECT_TRUE((::portable_stl::common_with<std::int32_t &&, std::int32_t const &>{}()));
  EXPECT_TRUE((::portable_stl::common_with<std::int32_t &, std::int32_t const &&>{}()));
  EXPECT_TRUE((::portable_stl::common_with<void, void>{}()));

  EXPECT_TRUE((::portable_stl::common_with<std::int32_t, std::int16_t>{}()));
  EXPECT_TRUE((::portable_stl::common_with<std::int16_t, std::int32_t>{}()));
  EXPECT_TRUE((::portable_stl::common_with<void *, std::int32_t const *>{}()));

  // fundamental types
  test_concepts_helpers::CheckCommonWith<std::int32_t, std::int32_t>("1");
  test_concepts_helpers::CheckCommonWith<std::int32_t, std::int64_t>("2");
  test_concepts_helpers::CheckCommonWith<std::int32_t, std::uint8_t>("3");
  test_concepts_helpers::CheckCommonWith<std::int32_t, double>("4");

  // arrays
  test_concepts_helpers::CheckCommonWith<std::int32_t[5], std::int32_t[5]>("4.1");

  // // pointers
  test_concepts_helpers::CheckCommonWith<std::int32_t *, std::int32_t *>("5");
  test_concepts_helpers::CheckCommonWith<std::int32_t *, std::int32_t const *>("6");
  test_concepts_helpers::CheckCommonWith<std::int32_t *, std::int32_t volatile *>("7");
  test_concepts_helpers::CheckCommonWith<std::int32_t *, std::int32_t const volatile *>("8");

  test_concepts_helpers::CheckCommonWith<std::int32_t const *, std::int32_t const *>("9");
  test_concepts_helpers::CheckCommonWith<std::int32_t const *, std::int32_t *>("10");
  test_concepts_helpers::CheckCommonWith<std::int32_t const *, void volatile *>("11");
  test_concepts_helpers::CheckCommonWith<std::int32_t const *, std::int32_t const volatile *>("12");

  test_concepts_helpers::CheckCommonWith<std::int32_t volatile *, std::int32_t const *>("13");
  test_concepts_helpers::CheckCommonWith<std::int32_t volatile *, std::int32_t volatile *>("14");
  test_concepts_helpers::CheckCommonWith<std::int32_t volatile *, std::int32_t const volatile *>("15");

  test_concepts_helpers::CheckCommonWith<std::int32_t const volatile *, std::int32_t const *>("16");
  test_concepts_helpers::CheckCommonWith<std::int32_t const volatile *, std::int32_t volatile *>("17");
  test_concepts_helpers::CheckCommonWith<std::int32_t const volatile *, std::int32_t const volatile *>("18");

  test_concepts_helpers::CheckCommonWith<std::int32_t (*)(), std::int32_t (*)()>("19");
  test_concepts_helpers::CheckCommonWith<std::int32_t (*)(), std::int32_t (*)() noexcept>("20");
}

TEST(concepts, assignable_from) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::assignable_from<void *&, std::int32_t *>;
    test_type checker{};
    ASSERT_TRUE((checker()));
  }
  {
    typename ::portable_stl::concepts_helper::assignable_from_impl<void *&, std::int32_t *>::type checker{};
    ASSERT_TRUE((checker()));
  }

  EXPECT_FALSE((::portable_stl::assignable_from<void, std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<void, void>{}()));

  EXPECT_FALSE((::portable_stl::assignable_from<void *, std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<void *&, std::int32_t *>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<void *&, std::int32_t const *>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<void const *&, std::int32_t const *>{}()));

  EXPECT_FALSE((::portable_stl::assignable_from<test_concepts_helpers::charT, test_concepts_helpers::charT>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<test_concepts_helpers::charT &, test_concepts_helpers::charT>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<float, float>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<float &, double>{}()));

  EXPECT_TRUE((::portable_stl::assignable_from<std::int32_t *&, std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<std::int32_t &, std::int32_t &>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<std::int32_t &, std::int32_t &&>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<std::int32_t &&, std::int32_t>{}()));

  EXPECT_FALSE((::portable_stl::assignable_from<std::int32_t const &, std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<std::int32_t const &, std::int32_t &>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<std::int32_t const &, std::int32_t const>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<std::int32_t const &, std::int32_t const &>{}()));

  EXPECT_TRUE((::portable_stl::assignable_from<std::int32_t volatile &, std::int32_t>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<std::int32_t volatile &, std::int32_t &>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<std::int32_t volatile &, std::int32_t &&>{}()));

  EXPECT_FALSE((::portable_stl::assignable_from<std::int32_t(&)[], std::int32_t(&)[]>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<std::int32_t(&)[], std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<std::int32_t(&)[1], std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<std::int32_t(&)[1], std::int32_t(&)[1]>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<std::int32_t(), std::int32_t()>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<std::int32_t (*)(), std::int32_t (*)()>{}()));

  EXPECT_TRUE((::portable_stl::assignable_from<std::int32_t (*&)(), std::int32_t (*)()>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<std::int32_t (*&)(), ::portable_stl::nullptr_t>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<std::int32_t (*&)(), std::int32_t (*)() noexcept>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<std::int32_t (*&)(), std::int32_t (&)() noexcept>{}()));

  EXPECT_FALSE((::portable_stl::assignable_from<std::int32_t (&)(), std::int32_t (&)() noexcept>{}()));

  /**
   * @brief Unscopped enum.
   */
  using UnscopperEnum = test_concepts_helpers::UnscoppedEnum;
  EXPECT_FALSE((::portable_stl::assignable_from<UnscopperEnum, UnscopperEnum>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<UnscopperEnum &, UnscopperEnum>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<UnscopperEnum &, UnscopperEnum &>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<UnscopperEnum &, UnscopperEnum const &>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<UnscopperEnum const &, UnscopperEnum const &>{}()));

  /**
   * @brief Scopped enum.
   */
  using ScopperEnum = test_concepts_helpers::ScoppedEnum;
  EXPECT_FALSE((::portable_stl::assignable_from<ScopperEnum, ScopperEnum>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<ScopperEnum &, ScopperEnum &>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<ScopperEnum &, ScopperEnum const &>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<ScopperEnum const &, ScopperEnum const &>{}()));

  /**
   * @brief Trivial class.
   */
  using TrivialClass = metaprogramming_type_relations_helper::Base1;
  EXPECT_FALSE((::portable_stl::assignable_from<TrivialClass, TrivialClass>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<TrivialClass &, TrivialClass>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<TrivialClass, TrivialClass &>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<TrivialClass &, TrivialClass const &>{}()));

  /**
   * @brief Union for checking.
   */
  using EmptyUnion = ::test_concepts_helpers::EmptyUnion;
  EXPECT_FALSE((::portable_stl::assignable_from<EmptyUnion, EmptyUnion>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<EmptyUnion &, EmptyUnion>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<EmptyUnion, EmptyUnion &>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<EmptyUnion &, EmptyUnion const &>{}()));

  /**
   * @brief Special assignable class.
   */
  using SpecialAssignable = ::test_concepts_helpers::special_assignable;
  EXPECT_TRUE((::portable_stl::assignable_from<SpecialAssignable &, SpecialAssignable>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<SpecialAssignable &, SpecialAssignable const &>{}()));
  EXPECT_TRUE((::portable_stl::assignable_from<SpecialAssignable &, std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<SpecialAssignable &, void *>{}()));
  EXPECT_FALSE((::portable_stl::assignable_from<SpecialAssignable &, std::nullptr_t>{}()));

  // class F final {
  // public:
  //   /**
  //    * @brief Assignable op.
  //    *
  //    * @return std::int32_t straneg result.
  //    */
  //   std::int32_t operator=(F const &) & noexcept {
  //     return 5;
  //   }
  // };
}

TEST(concepts, DISABLED_assignable_from_2) {
  static_cast<void>(test_info_);
  // EXPECT_FALSE((::portable_stl::assignable_from<std::int32_t (&)(), ::portable_stl::nullptr_t>{}()));
}

TEST(concepts, move_constructible) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::move_constructible<::test_concepts_helpers::not_movable>;
    test_type checker{};
    ASSERT_FALSE((checker()));
  }

  EXPECT_TRUE((::portable_stl::move_constructible<std::int32_t>{}()));
  EXPECT_TRUE((::portable_stl::move_constructible<std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::move_constructible<std::int32_t &>{}()));
  EXPECT_TRUE((::portable_stl::move_constructible<std::int32_t &&>{}()));
  EXPECT_TRUE((::portable_stl::move_constructible<std::int32_t const>{}()));
  EXPECT_TRUE((::portable_stl::move_constructible<std::int32_t const &>{}()));
  EXPECT_TRUE((::portable_stl::move_constructible<std::int32_t const &&>{}()));
  EXPECT_TRUE((::portable_stl::move_constructible<std::int32_t volatile>{}()));
  EXPECT_TRUE((::portable_stl::move_constructible<std::int32_t volatile &>{}()));
  EXPECT_TRUE((::portable_stl::move_constructible<std::int32_t volatile &&>{}()));
  EXPECT_TRUE((::portable_stl::move_constructible<std::int32_t (*)()>{}()));
  EXPECT_TRUE((::portable_stl::move_constructible<std::int32_t (&)()>{}()));

  EXPECT_FALSE((::portable_stl::move_constructible<void>{}()));
  EXPECT_FALSE((::portable_stl::move_constructible<std::int32_t[1]>{}()));
}

TEST(concepts, constructible_from) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::constructible_from<std::int32_t, std::int32_t>;
    test_type checker{};
    EXPECT_TRUE((checker()));
  }
}

TEST(concepts, convertible_to) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::convertible_to<std::int64_t, std::int16_t>;
    test_type checker{};
    EXPECT_TRUE((checker()));
  }
  {
    /**
     * @brief Test type.
     */
    using test_type        = ::portable_stl::concepts_helper::convertible_to_impl<std::int64_t, std::int16_t>;
    /**
     * @brief Test result type.
     */
    using test_type_result = typename test_type::type;
    EXPECT_TRUE((test_type_result{}()));
  }
  {
    /**
     * @brief Test type.
     */
    using test_type        = ::portable_stl::concepts_helper::convertible_to_impl<void, std::int16_t>;
    /**
     * @brief Test result type.
     */
    using test_type_result = typename test_type::type;
    EXPECT_FALSE((test_type_result{}()));
  }
  EXPECT_FALSE((::portable_stl::convertible_to<void, int64_t>{}()));
}

TEST(concepts, destructible) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::destructible<std::int32_t>;
    test_type checker{};
    EXPECT_TRUE((checker()));
  }
}

namespace test_concepts_helpers {
/**
 * @brief
 */
class NoAdlSwapExplicit final {
public:
  /**
   * @brief Ctor.
   */
  NoAdlSwapExplicit()                                     = default;
  /**
   * @brief Dtor.
   */
  ~NoAdlSwapExplicit()                                    = default;
  /**
   * @brief Ctor copy deleted.
   * Deleted.
   */
  NoAdlSwapExplicit(NoAdlSwapExplicit const &)            = delete;
  /**
   * @brief Ctor move deleted.
   * Deleted.
   */
  NoAdlSwapExplicit(NoAdlSwapExplicit &&)                 = delete;
  /**
   * @brief Assignment copy deleted.
   * @return NoAdlSwapExplicit&
   */
  NoAdlSwapExplicit &operator=(NoAdlSwapExplicit const &) = delete;
  /**
   * @brief Assignment move deleted.
   * @return NoAdlSwapExplicit&
   */
  NoAdlSwapExplicit &operator=(NoAdlSwapExplicit &&)      = delete;
};

/**
 * @brief Explicitly deleted swap.
 * @param left
 * @param right
 */
void swap(NoAdlSwapExplicit &left, NoAdlSwapExplicit &right) = delete;

/**
 * @brief
 */
class NoAdlSwap final {
public:
  /**
   * @brief Ctor.
   */
  NoAdlSwap()                             = default;
  /**
   * @brief Dtor.
   */
  ~NoAdlSwap()                            = default;
  /**
   * @brief Ctor copy deleted.
   * Deleted.
   */
  NoAdlSwap(NoAdlSwap const &)            = delete;
  /**
   * @brief Ctor move deleted.
   * Deleted.
   */
  NoAdlSwap(NoAdlSwap &&)                 = delete;
  /**
   * @brief Assignment copy deleted.
   * @return NoAdlSwap&
   */
  NoAdlSwap &operator=(NoAdlSwap const &) = delete;
  /**
   * @brief Assignment move deleted.
   * @return NoAdlSwap&
   */
  NoAdlSwap &operator=(NoAdlSwap &&)      = delete;
};
} // namespace test_concepts_helpers

TEST(concepts, swappable) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::swappable<std::int32_t>;
    test_type checker{};
    EXPECT_TRUE((checker()));
  }
  {
    typename ::portable_stl::ranges::swap_impl::has_adl_swap<std::int32_t, std::int32_t>::type checker{};
    EXPECT_FALSE((checker()));
  }
  {
    ::portable_stl::ranges::swap_impl::is_adl_swappable_with<std::int32_t, std::int32_t> checker{};
    EXPECT_FALSE((checker()));
  }
  {
    /**
     * @brief Test helper type.
     */
    using test_type = ::portable_stl::ranges::swap_impl::exchangeable<std::int32_t>;
    test_type checker{};
    EXPECT_TRUE((checker()));
  }

  // all steps for HasAdlSwap
  {
    /**
     * @brief Test type.
     */
    using test_type = test_concepts_helpers::HasAdlSwap;
    EXPECT_TRUE((::portable_stl::ranges::swap_impl::is_adl_swappable_with<test_type &, test_type &>{}()));
  }

  /**
   * @brief Test empty class.
   */
  using EmptyClass = metaprogramming_type_relations_helper::Base1;

  EXPECT_FALSE((::portable_stl::swappable<std::int32_t const &>{}()));
  EXPECT_TRUE((::portable_stl::swappable<std::int32_t &>{}()));

  EXPECT_FALSE((::portable_stl::swappable<void>{}()));
  EXPECT_FALSE((::portable_stl::swappable<std::int32_t const>{}()));
  EXPECT_FALSE((::portable_stl::swappable<std::int32_t const &>{}()));
  EXPECT_FALSE((::portable_stl::swappable<std::int32_t const &&>{}()));
  EXPECT_FALSE((::portable_stl::swappable<std::int32_t() const>{}()));
  EXPECT_FALSE((::portable_stl::swappable<std::int32_t() &>{}()));
  EXPECT_FALSE((::portable_stl::swappable<std::int32_t[]>{}()));
  EXPECT_FALSE((::portable_stl::swappable<std::int32_t[][1]>{}()));

  EXPECT_TRUE((::portable_stl::swappable<std::int32_t volatile &>{}()));
  EXPECT_TRUE((::portable_stl::swappable<std::int32_t &&>{}()));
  EXPECT_TRUE((::portable_stl::swappable<std::int32_t>{}()));
  EXPECT_TRUE((::portable_stl::swappable<std::int32_t[1]>{}()));
  EXPECT_TRUE((::portable_stl::swappable<std::int32_t[5]>{}()));
  EXPECT_TRUE((::portable_stl::swappable<std::int32_t[1][1][1][1]>{}()));
  EXPECT_TRUE((::portable_stl::swappable<EmptyClass>{}()));

  EXPECT_TRUE((::portable_stl::swappable<test_concepts_helpers::HasAdlSwap>{}()));
  EXPECT_FALSE((::portable_stl::swappable<test_concepts_helpers::NoAdlSwap>{}()));
  EXPECT_FALSE((::portable_stl::swappable<test_concepts_helpers::NoAdlSwapExplicit>{}()));
}

TEST(concepts, swappable_with) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::swappable_with<std::int32_t &, std::int32_t &>;
    test_type checker{};
    EXPECT_TRUE((checker()));
  }

  /**
   * @brief Test empty class.
   */
  using EmptyClass = metaprogramming_type_relations_helper::Base1;
  EXPECT_FALSE((::portable_stl::swappable_with<EmptyClass &, std::int32_t &>{}()));
  EXPECT_FALSE((::portable_stl::swappable_with<std::int32_t, std::int32_t>{}()));
  EXPECT_TRUE((::portable_stl::swappable_with<std::int32_t &, std::int32_t &>{}()));
}

TEST(concepts, integral) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::integral<std::int32_t>;
    test_type checker{};
    EXPECT_TRUE((checker()));
  }
}

TEST(concepts, movable) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::movable<::test_concepts_helpers::not_movable>;
    test_type checker{};
    EXPECT_FALSE((checker()));
  }
}

TEST(concepts, dereferenceable) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::dereferenceable<void>;
    test_type checker{};
    EXPECT_FALSE((checker()));
  }
  EXPECT_TRUE((::portable_stl::dereferenceable<std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::dereferenceable<std::int32_t[]>{}()));
  EXPECT_TRUE((::portable_stl::dereferenceable<std::int32_t[1]>{}()));
  EXPECT_TRUE((::portable_stl::dereferenceable<std::int32_t()>{}()));

  EXPECT_FALSE((::portable_stl::dereferenceable<std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::dereferenceable<std::int32_t &>{}()));
  EXPECT_FALSE((::portable_stl::dereferenceable<std::int32_t const &>{}()));
  EXPECT_FALSE((::portable_stl::dereferenceable<std::int32_t &&>{}()));
  EXPECT_FALSE((::portable_stl::dereferenceable<decltype(std::move(1))>{}()));
}

TEST(concepts, equality_comparable) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::equality_comparable<std::int32_t>;
    test_type checker{};
    EXPECT_TRUE((checker()));
  }

  // It is true for the double type, but variables of this type cannot be compared using the == and != operators.

  EXPECT_TRUE((::portable_stl::equality_comparable<std::int32_t>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<void *>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<test_concepts_helpers::charT *>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<test_concepts_helpers::charT const *>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<test_concepts_helpers::charT volatile *>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<test_concepts_helpers::charT const volatile *>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<std::uint8_t &&>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<std::uint16_t const &&>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<std::uint32_t volatile &&>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<std::uint64_t const volatile &&>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<std::int32_t[5]>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<std::int32_t (*)(std::int32_t)>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<std::int32_t (&)(std::int32_t)>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<std::int32_t (*)(std::int32_t) noexcept>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<std::int32_t (&)(std::int32_t) noexcept>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<std::nullptr_t>{}()));

  EXPECT_FALSE((::portable_stl::equality_comparable<void>{}()));

  EXPECT_FALSE((::portable_stl::equality_comparable<::test_concepts_helpers::no_eq>{}()));
  EXPECT_FALSE((::portable_stl::equality_comparable<::test_concepts_helpers::no_neq>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<::test_concepts_helpers::no_lt>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<::test_concepts_helpers::no_gt>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<::test_concepts_helpers::no_le>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<::test_concepts_helpers::no_ge>{}()));

  EXPECT_FALSE((::portable_stl::equality_comparable<::test_concepts_helpers::wrong_return_type_eq>{}()));
  EXPECT_FALSE((::portable_stl::equality_comparable<::test_concepts_helpers::wrong_return_type_ne>{}()));
  EXPECT_FALSE((::portable_stl::equality_comparable<::test_concepts_helpers::wrong_return_type>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<::test_concepts_helpers::wrong_return_type_lt>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<::test_concepts_helpers::wrong_return_type_gt>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<::test_concepts_helpers::wrong_return_type_le>{}()));
  EXPECT_TRUE((::portable_stl::equality_comparable<::test_concepts_helpers::wrong_return_type_ge>{}()));
}

TEST(concepts, totally_ordered) {
  static_cast<void>(test_info_);

  // same as equality_comparable
  EXPECT_TRUE((::portable_stl::totally_ordered<std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::totally_ordered<void>{}()));

  // but
  EXPECT_FALSE((::portable_stl::totally_ordered<::test_concepts_helpers::no_lt>{}()));
  EXPECT_FALSE((::portable_stl::totally_ordered<::test_concepts_helpers::no_gt>{}()));
  EXPECT_FALSE((::portable_stl::totally_ordered<::test_concepts_helpers::no_le>{}()));
  EXPECT_FALSE((::portable_stl::totally_ordered<::test_concepts_helpers::no_ge>{}()));

  EXPECT_FALSE((::portable_stl::totally_ordered<::test_concepts_helpers::wrong_return_type_lt>{}()));
  EXPECT_FALSE((::portable_stl::totally_ordered<::test_concepts_helpers::wrong_return_type_gt>{}()));
  EXPECT_FALSE((::portable_stl::totally_ordered<::test_concepts_helpers::wrong_return_type_le>{}()));
  EXPECT_FALSE((::portable_stl::totally_ordered<::test_concepts_helpers::wrong_return_type_ge>{}()));

  // gcc & msvc - totally_ordered, clang - NOT totally_ordered.
  // EXPECT_FALSE((::portable_stl::totally_ordered<std::nullptr_t>{}()));
}

namespace test_concepts_helpers {
/**
 * @brief Class to check regular 'concept'.
 */
class has_cv_member final {
  /**
   * @brief Data.
   */
  std::int32_t const volatile m_value;

public:
  /**
   * @brief Ctor.
   * @param value
   */
  explicit has_cv_member(std::int32_t value) noexcept : m_value(value) {
  }
  /**
   * @brief Get m_value
   * @return std::int32_t const
   */
  std::int32_t getValue() const noexcept {
    return m_value;
  }
};

/**
 * @brief Class to check regular 'concept'.
 */
class has_const_member final {
  /**
   * @brief Data.
   */
  std::int32_t const m_value;

public:
  /**
   * @brief Ctor.
   * @param value
   */
  explicit has_const_member(std::int32_t value) noexcept : m_value(value) {
  }
  /**
   * @brief Get m_value.
   * @return std::int32_t const
   */
  std::int32_t getValue() const noexcept {
    return m_value;
  }
};

/**
 * @brief Class to check regular 'concept'.
 */
class has_lvalue_reference_member final {
  /**
   * @brief Data.
   */
  std::int32_t &m_value_ref;

public:
  /**
   * @brief Ctor.
   * @param value_ref
   */
  explicit has_lvalue_reference_member(std::int32_t &value_ref) noexcept : m_value_ref(value_ref) {
  }
  /**
   * @brief Get m_value_ref.
   * @return std::int32_t&
   */
  std::int32_t &getValue() const {
    return m_value_ref;
  }
};

/**
 * @brief  Class to check regular 'concept'.
 */
class has_rvalue_reference_member final {
  /**
   * @brief Data.
   */
  std::int32_t &&m_value_rref;

public:
  /**
   * @brief Ctor.
   * @param value_ref
   */
  explicit has_rvalue_reference_member(std::int32_t &&value_ref) noexcept : m_value_rref(std::move(value_ref)) {
  }

  /**
   * @brief Get m_value_rref.
   * @return std::int32_t
   */
  std::int32_t getValue() const noexcept {
    return m_value_rref;
  }
};

/**
 * @brief  Class to check regular 'concept'.
 */
class has_function_ref_member final {
  using fn_type = std::int32_t (&)();
  /**
   * @brief Data.
   */
  fn_type m_func;

public:
  /**
   * @brief Ctor.
   * @param func
   */
  explicit has_function_ref_member(fn_type func) noexcept : m_func(func) {
  }

  /**
   * @brief Get the Value object
   *
   * @return fn_type
   */
  fn_type getValue() const noexcept {
    return m_func;
  }
};

} // namespace test_concepts_helpers

TEST(concepts, regular) {
  static_cast<void>(test_info_);
  // to mute AUTOSAR warnings
  {
    std::int32_t                                  val{1};
    test_concepts_helpers::has_const_member const item1{val};
    EXPECT_EQ(1, item1.getValue());
    static_cast<void>(item1);

    test_concepts_helpers::has_cv_member const item2{1};
    EXPECT_EQ(1, item2.getValue());
    static_cast<void>(item2);

    test_concepts_helpers::has_lvalue_reference_member const item3{val};
    EXPECT_EQ(1, item3.getValue());
    static_cast<void>(item3);

    test_concepts_helpers::has_rvalue_reference_member item4{std::move(val)};
    EXPECT_EQ(1, item4.getValue());
    static_cast<void>(item4);

    test_concepts_helpers::has_function_ref_member item5{test_concepts_helpers::free_function};
    EXPECT_EQ(test_concepts_helpers::free_function, item5.getValue());
    static_cast<void>(item5);
  }

  EXPECT_TRUE((::portable_stl::regular<std::int32_t>{}()));
  // It is true for the float type,  but variables of this type cannot be compared using the == and != operators.
  // It is true for the double type, but variables of this type cannot be compared using the == and != operators.
  EXPECT_TRUE((::portable_stl::regular<std::int32_t volatile>{}()));
  EXPECT_TRUE((::portable_stl::regular<void *>{}()));
  EXPECT_TRUE((::portable_stl::regular<std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::regular<std::int32_t const *>{}()));
  EXPECT_TRUE((::portable_stl::regular<std::int32_t volatile *>{}()));
  EXPECT_TRUE((::portable_stl::regular<std::int32_t const volatile *>{}()));
  EXPECT_TRUE((::portable_stl::regular<std::int32_t (*)()>{}()));

  // Not objects
  // EXPECT_FALSE((::portable_stl::regular<void>{}()));
  EXPECT_FALSE((::portable_stl::regular<std::int32_t &>{}()));
  EXPECT_FALSE((::portable_stl::regular<std::int32_t const &>{}()));
  EXPECT_FALSE((::portable_stl::regular<std::int32_t volatile &>{}()));
  EXPECT_FALSE((::portable_stl::regular<std::int32_t const volatile &>{}()));
  EXPECT_FALSE((::portable_stl::regular<std::int32_t &&>{}()));
  EXPECT_FALSE((::portable_stl::regular<std::int32_t const &&>{}()));
  EXPECT_FALSE((::portable_stl::regular<std::int32_t volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::regular<std::int32_t const volatile &&>{}()));
  EXPECT_FALSE((::portable_stl::regular<std::int32_t()>{}()));
  EXPECT_FALSE((::portable_stl::regular<std::int32_t (&)()>{}()));
  EXPECT_FALSE((::portable_stl::regular<std::int32_t[1]>{}()));

  // not copyable
  EXPECT_FALSE((::portable_stl::regular<std::unique_ptr<std::int32_t>>{}()));
  EXPECT_FALSE((::portable_stl::regular<std::int32_t const>{}()));
  EXPECT_FALSE((::portable_stl::regular<std::int32_t const volatile>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::volatile_copy_assignment volatile>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::no_copy_constructor>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::no_copy_assignment>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::derived_from_noncopyable>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::has_noncopyable>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::has_const_member>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::has_cv_member>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::has_lvalue_reference_member>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::has_rvalue_reference_member>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::has_function_ref_member>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::deleted_assignment_from_const_rvalue>{}()));

  // not default_initializable
  EXPECT_FALSE((::portable_stl::regular<std::runtime_error>{}()));
  EXPECT_FALSE((::portable_stl::regular<std::tuple<std::runtime_error, std::overflow_error>>{}()));
  // EXPECT_FALSE((::portable_stl::regular<std::nullopt_t>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::no_copy_constructor>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::no_copy_assignment>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::derived_from_noncopyable>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::has_noncopyable>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::derived_from_non_default_initializable>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::has_non_default_initializable>{}()));

  // not equality_comparable
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::const_copy_assignment const>{}()));
  EXPECT_FALSE((::portable_stl::regular<test_concepts_helpers::cv_copy_assignment const volatile>{}()));
}
