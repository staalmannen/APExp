// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="functional.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>
#include "portable_stl/utility/general/functional/reference_wrapper.h"
#include "portable_stl/metaprogramming/other_transformations/invoke_result.h"
#include "portable_stl/metaprogramming/type_relations/is_invocable.h"
#include "portable_stl/utility/general/functional/invoke.h"

namespace test_functional_helper {

struct A {
  void foo(std::int32_t) {
  }
};

struct abstract {
  virtual ~abstract() = 0;
  void operator()() noexcept;
};

struct F {
  void         operator()() &;
  void         operator()()         &&noexcept;
  std::int32_t operator()(std::int32_t);
  double *operator()(std::int32_t, std::int32_t) noexcept;
};

struct NonCopyable {
  NonCopyable() {
  }

private:
  NonCopyable(NonCopyable const &)            = delete;
  NonCopyable &operator=(NonCopyable const &) = delete;
};

struct TestClass {
  explicit TestClass(std::int32_t x) : m_data(x) {
  }

  std::int32_t &operator()(NonCopyable &&) & {
    return m_data;
  }
  std::int32_t const &operator()(NonCopyable &&) const & {
    return m_data;
  }
  std::int32_t volatile &operator()(NonCopyable &&) volatile & {
    return m_data;
  }
  std::int32_t const volatile &operator()(NonCopyable &&) const volatile & {
    return m_data;
  }

  std::int32_t &&operator()(NonCopyable &&) && {
    return std::move(m_data);
  }
  std::int32_t const &&operator()(NonCopyable &&) const && {
    return std::move(m_data);
  }
  std::int32_t volatile &&operator()(NonCopyable &&) volatile && {
    return std::move(m_data);
  }
  std::int32_t const volatile &&operator()(NonCopyable &&) const volatile && {
    return std::move(m_data);
  }

  std::int32_t m_data;

private:
  TestClass(TestClass const &)            = delete;
  TestClass &operator=(TestClass const &) = delete;
};

struct DerivedFromTestClass : public TestClass {
  explicit DerivedFromTestClass(std::int32_t x) : TestClass(x) {
  }
};

static std::int32_t &foo(NonCopyable &&) {
  static std::int32_t data = 42;
  return data;
}

template<class Signature, class Expect, class Functor> void test_b123(Functor &&f) {
  // Create the callable object.
  typedef Signature TestClass::*ClassFunc;
  ClassFunc                     func_ptr = &TestClass::operator();

  // Create the dummy arg.
  NonCopyable arg;

  // Check that the deduced return type of invoke is what is expected.
  using DeducedReturnType = decltype(::portable_stl::invoke(func_ptr, std::forward<Functor>(f), std::move(arg)));
  EXPECT_TRUE((std::is_same<DeducedReturnType, Expect>{}));

  // Check that result_of_t/invoke_result_t matches Expect.
  // using ResultOfReturnType = std::result_of_t<ClassFunc && (Functor &&, NonCopyable &&)>;
  using ResultOfReturnType = ::portable_stl::invoke_result_t<ClassFunc &&, Functor &&, NonCopyable &&>;
  EXPECT_TRUE((std::is_same<ResultOfReturnType, Expect>{}));

  // Run invoke and check the return value.
  DeducedReturnType ret = ::portable_stl::invoke(func_ptr, std::forward<Functor>(f), std::move(arg));
  EXPECT_EQ(42, ret);
}

template<class Expect, class Functor> void test_b456(Functor &&f) {
  // Create the callable object.
  typedef std::int32_t TestClass::*ClassFunc;
  ClassFunc                        func_ptr = &TestClass::m_data;

  // Check that the deduced return type of invoke is what is expected.
  using DeducedReturnType = decltype(::portable_stl::invoke(func_ptr, std::forward<Functor>(f)));
  EXPECT_TRUE((std::is_same<DeducedReturnType, Expect>{}));

  // Check that result_of_t/invoke_result_t matches Expect.
  // using ResultOfReturnType  = std::result_of_t<ClassFunc && (Functor &&)>;
  using ResultOfReturnType = ::portable_stl::invoke_result_t<ClassFunc &&, Functor &&>;
  EXPECT_TRUE((std::is_same<ResultOfReturnType, Expect>{}));

  // Run invoke and check the return value.
  DeducedReturnType ret = ::portable_stl::invoke(func_ptr, std::forward<Functor>(f));
  EXPECT_EQ(42, ret);
}

template<class Expect, class Functor> void test_b7(Functor &&f) {
  NonCopyable arg;

  // Check that the deduced return type of invoke is what is expected.
  typedef decltype(::portable_stl::invoke(std::forward<Functor>(f), std::move(arg))) DeducedReturnType;
  EXPECT_TRUE((std::is_same<DeducedReturnType, Expect>{}));

  // Check that result_of_t/invoke_result_t matches Expect.
  // using ResultOfReturnType = std::result_of_t<Functor && (NonCopyable &&)>;
  using ResultOfReturnType = ::portable_stl::invoke_result_t<Functor &&, NonCopyable &&>;
  EXPECT_TRUE((std::is_same<ResultOfReturnType, Expect>{}));

  // Run invoke and check the return value.
  DeducedReturnType ret = ::portable_stl::invoke(std::forward<Functor>(f), std::move(arg));
  EXPECT_EQ(42, ret);
}

struct CopyThrows {
  CopyThrows() {
  }
  CopyThrows(CopyThrows const &) {
  }
  CopyThrows(CopyThrows &&) noexcept {
  }
};

struct NoThrowCallable {
  void operator()() noexcept {
  }
  void operator()(CopyThrows) noexcept {
  }
};

struct ThrowsCallable {
  void operator()() {
  }
};

struct MemberObj {
  std::int32_t x;
};

} // namespace test_functional_helper

// Define INVOKE(f, t1, t2, ..., tN) as follows:
// (1) — (t1.*f)(t2, ..., tN) when f is a pointer to a member function of a class T and is_same_v<T,
//    remove_cvref_t<decltype(t1)>> || is_base_of_v<T, remove_cvref_t<decltype(t1)>> is true;
// (2) — (t1.get().*f)(t2, ..., tN) when f is a pointer to a member function of a class T and
//    remove_cvref_t<decltype(t1)> is a specialization of reference_wrapper;
// (3) — ((*t1).*f)(t2, ..., tN) when f is a pointer to a member function of a class T and t1 does not satisfy the
//    previous two items;
TEST(invoke, bullet1_2_3) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   *
   */
  using TestClass            = test_functional_helper::TestClass;
  /**
   * @brief Alias.
   *
   */
  using NonCopyable          = test_functional_helper::NonCopyable;
  /**
   * @brief Alias.
   *
   */
  using DerivedFromTestClass = test_functional_helper::DerivedFromTestClass;

  {
    TestClass cl(42);
    test_functional_helper::test_b123<std::int32_t &(NonCopyable &&)&, std::int32_t &>(cl);
    test_functional_helper::test_b123<std::int32_t const &(NonCopyable &&) const &, std::int32_t const &>(cl);
    test_functional_helper::test_b123<std::int32_t volatile &(NonCopyable &&) volatile &, std::int32_t volatile &>(cl);
    test_functional_helper::test_b123<std::int32_t const volatile &(NonCopyable &&) const volatile &,
                                      std::int32_t const volatile &>(cl);

    test_functional_helper::test_b123<std::int32_t && (NonCopyable &&) &&, std::int32_t &&>(std::move(cl));
    test_functional_helper::test_b123<std::int32_t const && (NonCopyable &&) const &&, std::int32_t const &&>(
      std::move(cl));
    test_functional_helper::test_b123<std::int32_t volatile && (NonCopyable &&) volatile &&, std::int32_t volatile &&>(
      std::move(cl));
    test_functional_helper::test_b123<std::int32_t const volatile && (NonCopyable &&) const volatile &&,
                                      std::int32_t const volatile &&>(std::move(cl));
  }
  {
    DerivedFromTestClass cl(42);
    test_functional_helper::test_b123<std::int32_t &(NonCopyable &&)&, std::int32_t &>(cl);
    test_functional_helper::test_b123<std::int32_t const &(NonCopyable &&) const &, std::int32_t const &>(cl);
    test_functional_helper::test_b123<std::int32_t volatile &(NonCopyable &&) volatile &, std::int32_t volatile &>(cl);
    test_functional_helper::test_b123<std::int32_t const volatile &(NonCopyable &&) const volatile &,
                                      std::int32_t const volatile &>(cl);

    // test_functional_helper::test_b123<std::int32_t && (NonCopyable &&) &&, std::int32_t &&>(std::move(cl));
    // test_functional_helper::test_b123<std::int32_t const && (NonCopyable &&) const &&, std::int32_t const
    // &&>(std::move(cl)); test_functional_helper::test_b123<std::int32_t volatile && (NonCopyable &&) volatile &&,
    // std::int32_t volatile &&>(std::move(cl)); test_functional_helper::test_b123<std::int32_t const volatile &&
    // (NonCopyable &&) const volatile &&, std::int32_t const volatile
    // &&>( std::move(cl));
  }
  {
    TestClass                                    cl_obj(42);
    ::portable_stl::reference_wrapper<TestClass> cl(cl_obj);
    test_functional_helper::test_b123<std::int32_t &(NonCopyable &&)&, std::int32_t &>(cl);
    test_functional_helper::test_b123<std::int32_t const &(NonCopyable &&) const &, std::int32_t const &>(cl);
    test_functional_helper::test_b123<std::int32_t volatile &(NonCopyable &&) volatile &, std::int32_t volatile &>(cl);
    test_functional_helper::test_b123<std::int32_t const volatile &(NonCopyable &&) const volatile &,
                                      std::int32_t const volatile &>(cl);

    test_functional_helper::test_b123<std::int32_t &(NonCopyable &&)&, std::int32_t &>(std::move(cl));
    test_functional_helper::test_b123<std::int32_t const &(NonCopyable &&) const &, std::int32_t const &>(
      std::move(cl));
    test_functional_helper::test_b123<std::int32_t volatile &(NonCopyable &&) volatile &, std::int32_t volatile &>(
      std::move(cl));
    test_functional_helper::test_b123<std::int32_t const volatile &(NonCopyable &&) const volatile &,
                                      std::int32_t const volatile &>(std::move(cl));
  }
  {
    DerivedFromTestClass                                    cl_obj(42);
    ::portable_stl::reference_wrapper<DerivedFromTestClass> cl(cl_obj);
    test_functional_helper::test_b123<std::int32_t &(NonCopyable &&)&, std::int32_t &>(cl);
    test_functional_helper::test_b123<std::int32_t const &(NonCopyable &&) const &, std::int32_t const &>(cl);
    test_functional_helper::test_b123<std::int32_t volatile &(NonCopyable &&) volatile &, std::int32_t volatile &>(cl);
    test_functional_helper::test_b123<std::int32_t const volatile &(NonCopyable &&) const volatile &,
                                      std::int32_t const volatile &>(cl);

    test_functional_helper::test_b123<std::int32_t &(NonCopyable &&)&, std::int32_t &>(std::move(cl));
    test_functional_helper::test_b123<std::int32_t const &(NonCopyable &&) const &, std::int32_t const &>(
      std::move(cl));
    test_functional_helper::test_b123<std::int32_t volatile &(NonCopyable &&) volatile &, std::int32_t volatile &>(
      std::move(cl));
    test_functional_helper::test_b123<std::int32_t const volatile &(NonCopyable &&) const volatile &,
                                      std::int32_t const volatile &>(std::move(cl));
  }
  {
    TestClass  cl_obj(42);
    TestClass *cl = &cl_obj;
    test_functional_helper::test_b123<std::int32_t &(NonCopyable &&)&, std::int32_t &>(cl);
    test_functional_helper::test_b123<std::int32_t const &(NonCopyable &&) const &, std::int32_t const &>(cl);
    test_functional_helper::test_b123<std::int32_t volatile &(NonCopyable &&) volatile &, std::int32_t volatile &>(cl);
    test_functional_helper::test_b123<std::int32_t const volatile &(NonCopyable &&) const volatile &,
                                      std::int32_t const volatile &>(cl);
  }
  {
    DerivedFromTestClass  cl_obj(42);
    DerivedFromTestClass *cl = &cl_obj;
    test_functional_helper::test_b123<std::int32_t &(NonCopyable &&)&, std::int32_t &>(cl);
    test_functional_helper::test_b123<std::int32_t const &(NonCopyable &&) const &, std::int32_t const &>(cl);
    test_functional_helper::test_b123<std::int32_t volatile &(NonCopyable &&) volatile &, std::int32_t volatile &>(cl);
    test_functional_helper::test_b123<std::int32_t const volatile &(NonCopyable &&) const volatile &,
                                      std::int32_t const volatile &>(cl);
  }
}

// (4) — t1.*f when N = 1 and f is a pointer to data member of a class T and is_same_v<T, remove_cvref_t<decltype(t1)>>
//    || is_base_of_v<T, remove_cvref_t<decltype(t1)>> is true;
// (5) — t1.get().*f when N = 1 and f is a pointer to data member of a class T and remove_cvref_t<decltype(t1)> is a
//    specialization of reference_wrapper;
// (6) — (*t1).*f when N = 1 and f is a pointer to data member of a class T and t1 does not satisfy the previous two
//    items;
TEST(invoke, bullet4_5_6) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   *
   */
  using TestClass            = test_functional_helper::TestClass;
  /**
   * @brief Alias.
   *
   */
  using DerivedFromTestClass = test_functional_helper::DerivedFromTestClass;

  {
    typedef TestClass Fn;
    Fn                cl(42);
    test_functional_helper::test_b456<std::int32_t &>(cl);
    test_functional_helper::test_b456<std::int32_t const &>(static_cast<Fn const &>(cl));
    test_functional_helper::test_b456<std::int32_t volatile &>(static_cast<Fn volatile &>(cl));
    test_functional_helper::test_b456<std::int32_t const volatile &>(static_cast<Fn const volatile &>(cl));

    test_functional_helper::test_b456<std::int32_t &&>(static_cast<Fn &&>(cl));
    test_functional_helper::test_b456<std::int32_t const &&>(static_cast<Fn const &&>(cl));
    test_functional_helper::test_b456<std::int32_t volatile &&>(static_cast<Fn volatile &&>(cl));
    test_functional_helper::test_b456<std::int32_t const volatile &&>(static_cast<Fn const volatile &&>(cl));
  }
  {
    typedef DerivedFromTestClass Fn;
    Fn                           cl(42);
    test_functional_helper::test_b456<std::int32_t &>(cl);
    test_functional_helper::test_b456<std::int32_t const &>(static_cast<Fn const &>(cl));
    test_functional_helper::test_b456<std::int32_t volatile &>(static_cast<Fn volatile &>(cl));
    test_functional_helper::test_b456<std::int32_t const volatile &>(static_cast<Fn const volatile &>(cl));

    test_functional_helper::test_b456<std::int32_t &&>(static_cast<Fn &&>(cl));
    test_functional_helper::test_b456<std::int32_t const &&>(static_cast<Fn const &&>(cl));
    test_functional_helper::test_b456<std::int32_t volatile &&>(static_cast<Fn volatile &&>(cl));
    test_functional_helper::test_b456<std::int32_t const volatile &&>(static_cast<Fn const volatile &&>(cl));
  }
  {
    typedef TestClass Fn;
    Fn                cl(42);
    test_functional_helper::test_b456<std::int32_t &>(::portable_stl::reference_wrapper<Fn>(cl));
    test_functional_helper::test_b456<std::int32_t const &>(::portable_stl::reference_wrapper<Fn const>(cl));
    test_functional_helper::test_b456<std::int32_t volatile &>(::portable_stl::reference_wrapper<Fn volatile>(cl));
    test_functional_helper::test_b456<std::int32_t const volatile &>(
      ::portable_stl::reference_wrapper<Fn const volatile>(cl));
  }
  {
    typedef DerivedFromTestClass Fn;
    Fn                           cl(42);
    test_functional_helper::test_b456<std::int32_t &>(::portable_stl::reference_wrapper<Fn>(cl));
    test_functional_helper::test_b456<std::int32_t const &>(::portable_stl::reference_wrapper<Fn const>(cl));
    test_functional_helper::test_b456<std::int32_t volatile &>(::portable_stl::reference_wrapper<Fn volatile>(cl));
    test_functional_helper::test_b456<std::int32_t const volatile &>(
      ::portable_stl::reference_wrapper<Fn const volatile>(cl));
  }
  {
    typedef TestClass Fn;
    Fn                cl_obj(42);
    Fn               *cl = &cl_obj;
    test_functional_helper::test_b456<std::int32_t &>(cl);
    test_functional_helper::test_b456<std::int32_t const &>(static_cast<Fn const *>(cl));
    test_functional_helper::test_b456<std::int32_t volatile &>(static_cast<Fn volatile *>(cl));
    test_functional_helper::test_b456<std::int32_t const volatile &>(static_cast<Fn const volatile *>(cl));
  }
  {
    typedef DerivedFromTestClass Fn;
    Fn                           cl_obj(42);
    Fn                          *cl = &cl_obj;
    test_functional_helper::test_b456<std::int32_t &>(cl);
    test_functional_helper::test_b456<std::int32_t const &>(static_cast<Fn const *>(cl));
    test_functional_helper::test_b456<std::int32_t volatile &>(static_cast<Fn volatile *>(cl));
    test_functional_helper::test_b456<std::int32_t const volatile &>(static_cast<Fn const volatile *>(cl));
  }
}

// (7) — f(t1, t2, . . . , tN) in all other cases.
TEST(invoke, bullet7) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   *
   */
  using TestClass   = test_functional_helper::TestClass;
  /**
   * @brief Alias.
   *
   */
  using NonCopyable = test_functional_helper::NonCopyable;
  /**
   * @brief Alias.
   *
   */
  using FooType     = std::int32_t &(NonCopyable &&);

  {
    FooType &fn = test_functional_helper::foo;
    test_functional_helper::test_b7<std::int32_t &>(fn);
  }
  {
    FooType *fn = test_functional_helper::foo;
    test_functional_helper::test_b7<std::int32_t &>(fn);
  }
  {
    typedef TestClass Fn;
    Fn                cl(42);
    test_functional_helper::test_b7<std::int32_t &>(cl);
    test_functional_helper::test_b7<std::int32_t const &>(static_cast<Fn const &>(cl));
    test_functional_helper::test_b7<std::int32_t volatile &>(static_cast<Fn volatile &>(cl));
    test_functional_helper::test_b7<std::int32_t const volatile &>(static_cast<Fn const volatile &>(cl));

    test_functional_helper::test_b7<std::int32_t &&>(static_cast<Fn &&>(cl));
    test_functional_helper::test_b7<std::int32_t const &&>(static_cast<Fn const &&>(cl));
    test_functional_helper::test_b7<std::int32_t volatile &&>(static_cast<Fn volatile &&>(cl));
    test_functional_helper::test_b7<std::int32_t const volatile &&>(static_cast<Fn const volatile &&>(cl));
  }
}

TEST(invoke, noexcept_test) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   *
   */
  using NoThrowCallable = test_functional_helper::NoThrowCallable;
  /**
   * @brief Alias.
   *
   */
  using CopyThrows      = test_functional_helper::CopyThrows;
  /**
   * @brief Alias.
   *
   */
  using ThrowsCallable  = test_functional_helper::ThrowsCallable;
  /**
   * @brief Alias.
   *
   */
  using MemberObj       = test_functional_helper::MemberObj;

  {
    NoThrowCallable obj;
    ((void)obj); // suppress unused warning

    CopyThrows arg;
    ((void)arg); // suppress unused warning

    static_assert(noexcept(::portable_stl::invoke(obj)), "");
    static_assert(!noexcept(::portable_stl::invoke(obj, arg)), "");
    static_assert(noexcept(::portable_stl::invoke(obj, std::move(arg))), "");
  }
  {
    ThrowsCallable obj;
    ((void)obj); // suppress unused warning

    static_assert(!noexcept(::portable_stl::invoke(obj)), "");
  }
  {
    MemberObj obj{42};
    ((void)obj); // suppress unused warning.

    static_assert(noexcept(::portable_stl::invoke(&MemberObj::x, obj)), "");
  }
}

// LWG3655: The INVOKE operation and union types
TEST(invoke, union) {
  static_cast<void>(test_info_);

  union Union {
    std::int32_t x;
    std::int32_t f() {
      return 42;
    }
    std::int32_t g() const {
      return 52;
    }
  };

  // With a data member
  {
    auto get = []() -> Union {
      Union ret;
      ret.x = 3;
      return ret;
    };
    std::int32_t result = ::portable_stl::invoke(&Union::x, get());
    ASSERT_EQ(3, result);
  }
  {
    auto get = []() -> Union const {
      Union ret;
      ret.x = 3;
      return ret;
    };
    std::int32_t result = ::portable_stl::invoke(&Union::x, get());
    ASSERT_EQ(3, result);
  }
  {
    Union         u{3};
    std::int32_t &result = ::portable_stl::invoke(&Union::x, u);
    ASSERT_EQ(&result , &u.x);
  }
  {
    Union const         u{3};
    std::int32_t const &result = ::portable_stl::invoke(&Union::x, u);
    ASSERT_EQ(&result , &u.x);
  }

  // With a pointer to a member function
  {
    auto get = []() -> Union {
      Union ret;
      ret.x = 3;
      return ret;
    };
    std::int32_t result = ::portable_stl::invoke(&Union::f, get());
    ASSERT_EQ(42, result);
  }
  {
    Union        u{3};
    std::int32_t result = ::portable_stl::invoke(&Union::f, u);
    ASSERT_EQ(42, result);
  }
  {
    // constness mismatch
    EXPECT_FALSE((::portable_stl::is_invocable<std::int32_t (Union::*)(), Union const>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<std::int32_t (Union::*)(), Union const &>{}()));
  }

  {
    auto get = []() -> Union {
      Union ret;
      ret.x = 3;
      return ret;
    };
    std::int32_t result = ::portable_stl::invoke(&Union::g, get());
    ASSERT_EQ(52, result);
  }
  {
    auto get = []() -> Union const {
      Union ret;
      ret.x = 3;
      return ret;
    };
    std::int32_t result = ::portable_stl::invoke(&Union::g, get());
    ASSERT_EQ(52, result);
  }
  {
    Union        u{3};
    std::int32_t result = ::portable_stl::invoke(&Union::g, u);
    ASSERT_EQ(52, result);
  }
  {
    Union const  u{3};
    std::int32_t result = ::portable_stl::invoke(&Union::g, u);
    ASSERT_EQ(52, result);
  }
}

TEST(invoke, abstract) {
  static_cast<void>(test_info_);

  static_assert(noexcept(::portable_stl::invoke(std::declval<test_functional_helper::abstract>())),
                "It should be possible to use abstract types with INVOKE");

  static_assert(!noexcept(::portable_stl::invoke(std::declval<test_functional_helper::F &>())), "");
  static_assert(noexcept(::portable_stl::invoke(std::declval<test_functional_helper::F>())), "");
  static_assert(!noexcept(::portable_stl::invoke(std::declval<test_functional_helper::F>(), 1)), "");
  static_assert(noexcept(::portable_stl::invoke(std::declval<test_functional_helper::F>(), 1, 2)), "");
}
