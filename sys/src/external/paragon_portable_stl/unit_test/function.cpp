// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="function.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "common/function_types.h"
#include "common/test_allocator.h"
#include "portable_stl/functional/function.h"
#include "portable_stl/metaprogramming/type_properties/is_constructible.h"

namespace test_function_helper {
struct F {
  void operator()() {
  }

  void operator&() const {
  }
};

class classA {
  std::int32_t m_data[10];

public:
  static std::int32_t count;

  explicit classA(std::int32_t value) {
    ++count;
    m_data[0] = value;
  }

  classA() noexcept {
    ++count;
    for (std::int32_t i = 0; i < 10; ++i) {
      m_data[i] = i;
    }
  }

  classA(classA const &other) noexcept {
    ++count;
    for (std::int32_t i{0}; i < 10; ++i) {
      m_data[i] = other.m_data[i];
    }
  }

  ~classA() {
    --count;
  }

  std::int32_t operator()(std::int32_t i) const noexcept {
    for (std::int32_t j{0}; j < 10; ++j) {
      i += m_data[j];
    }
    return i;
  }

  std::int32_t foo(std::int32_t) const noexcept {
    return 1;
  }

  std::int32_t id() const noexcept {
    return m_data[0];
  }
};

std::int32_t classA::count = 0;

static std::int32_t g(std::int32_t) {
  return 0;
}

static std::int32_t g0() {
  return 0;
}

static std::int32_t g2(std::int32_t, std::int32_t) {
  return 2;
}

static std::int32_t g3(std::int32_t, std::int32_t, std::int32_t) {
  return 3;
}

static std::int32_t h(std::int32_t) {
  return 1;
}

class RValueCallable final {
public:
  template<class... Args> void operator()(Args &&...) && {
  }
};

class LValueCallable final {
public:
  template<class... Args> void operator()(Args &&...) & {
  }
};

} // namespace test_function_helper

/**
 * @brief Alias.
 *
 */
using classA = test_function_helper::classA;

TEST(function, construction_basic) {
  static_cast<void>(test_info_);

  // default
  {
    ::portable_stl::function<std::int32_t(std::int32_t)> func;
    ASSERT_FALSE(func);
  }

  // nullptr
  {
    ::portable_stl::function<std::int32_t(std::int32_t)> func(nullptr);
    ASSERT_FALSE(func);
  }

  // with custom allocator
  {
    using t_allocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    ::portable_stl::function<std::int32_t(std::int32_t)> f(::portable_stl::allocator_arg, t_allocator{});
    ASSERT_FALSE(f);
  }

  // with custom allocator and nullptr
  {
    using t_allocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    ::portable_stl::function<std::int32_t(std::int32_t)> f(::portable_stl::allocator_arg, t_allocator{}, nullptr);
    ASSERT_FALSE(f);
  }
}

// function(F);
TEST(function, construction) {
  static_cast<void>(test_info_);
  {
    ASSERT_EQ(0, classA::count);
    classA                                               func_object{};
    ::portable_stl::function<std::int32_t(std::int32_t)> f = std::move(func_object);

    ASSERT_EQ(2, classA::count);
    ASSERT_TRUE(f.target<classA>());
    ASSERT_TRUE(0 == f.target<std::int32_t (*)(std::int32_t)>());
  }
  ASSERT_EQ(0, classA::count);
  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f = test_function_helper::g;

    ASSERT_TRUE(f.target<std::int32_t (*)(std::int32_t)>());
    ASSERT_TRUE(0 == f.target<classA>());
  }
  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f = (std::int32_t(*)(std::int32_t))0;

    ASSERT_FALSE(f);
    ASSERT_TRUE(0 == f.target<std::int32_t (*)(std::int32_t)>());
    ASSERT_TRUE(0 == f.target<classA>());
  }
  {
    ::portable_stl::function<std::int32_t(classA const *, std::int32_t)> f = &classA::foo;

    ASSERT_TRUE(f);
    ASSERT_TRUE(0 != f.target<std::int32_t (classA::*)(std::int32_t) const>());
  }
  {
    ::portable_stl::function<void(std::int32_t)> f(&test_function_helper::g);

    ASSERT_TRUE(f);
    ASSERT_TRUE(0 != f.target<std::int32_t (*)(std::int32_t)>());
    f(1);
  }
  {
    ::portable_stl::function<void()> f(static_cast<void (*)()>(0));

    ASSERT_FALSE(f);
  }
  {
    /**
     * @brief Alias.
     *
     */
    using RValueCallable = test_function_helper::RValueCallable;
    /**
     * @brief Alias.
     *
     */
    using LValueCallable = test_function_helper::LValueCallable;

    using Fn = ::portable_stl::function<void(std::int32_t, std::int32_t, std::int32_t)>;
    EXPECT_TRUE((::portable_stl::is_constructible<Fn, LValueCallable &>{}()));
    EXPECT_TRUE((::portable_stl::is_constructible<Fn, LValueCallable>{}()));
    EXPECT_FALSE((::portable_stl::is_constructible<Fn, RValueCallable &>{}()));
    EXPECT_FALSE((::portable_stl::is_constructible<Fn, RValueCallable>{}()));
  }
}

// make_function(F);
TEST(function, make_function) {
  static_cast<void>(test_info_);
  {
    ASSERT_EQ(0, classA::count);
    auto result = ::portable_stl::function<std::int32_t(std::int32_t)>::make_function(classA());
    ASSERT_TRUE(result);
    auto f = result.value();

    ASSERT_EQ(2, classA::count);
    ASSERT_TRUE(f.target<classA>());
    ASSERT_TRUE(nullptr == f.target<std::int32_t (*)(std::int32_t)>());
  }
  ASSERT_EQ(0, classA::count);
  {
    auto result = ::portable_stl::function<std::int32_t(std::int32_t)>::make_function(test_function_helper::g);
    ASSERT_TRUE(result);
    auto f = result.value();

    ASSERT_TRUE(f.target<std::int32_t (*)(std::int32_t)>());
    ASSERT_TRUE(0 == f.target<classA>());
  }
  {
    auto result = ::portable_stl::function<std::int32_t(std::int32_t)>::make_function((std::int32_t(*)(std::int32_t))0);
    ASSERT_TRUE(result);
    auto f = result.value();

    ASSERT_FALSE(f);
    ASSERT_TRUE(0 == f.target<std::int32_t (*)(std::int32_t)>());
    ASSERT_TRUE(0 == f.target<classA>());
  }
  {
    auto result = ::portable_stl::function<std::int32_t(classA const *, std::int32_t)>::make_function(&classA::foo);
    ASSERT_TRUE(result);
    auto f = result.value();

    ASSERT_TRUE(f);
    ASSERT_TRUE(0 != f.target<std::int32_t (classA::*)(std::int32_t) const>());
  }
  {
    auto result = ::portable_stl::function<void(std::int32_t)>::make_function(&test_function_helper::g);
    ASSERT_TRUE(result);
    auto f = result.value();

    ASSERT_TRUE(f);
    ASSERT_TRUE(0 != f.target<std::int32_t (*)(std::int32_t)>());
    f(1);
  }
  {
    auto result = ::portable_stl::function<void()>::make_function(static_cast<void (*)()>(0));
    ASSERT_TRUE(result);
    auto f = result.value();

    ASSERT_FALSE(f);
  }
}

// make_function(F);
TEST(function, make_function_bad_allocation) {
  static_cast<void>(test_info_);
  {
    // Functional object with guarantee memory allocation need.
    {
      /**
       * @brief Test allocator.
       *
       */
      using test_alloc = ::test_allocator_helper::test_allocator<classA>;

      // no limit, ok allocation
      {
        test_alloc alloc;

        ASSERT_EQ(0, classA::count);
        auto result = ::portable_stl::function<std::int32_t(std::int32_t)>::make_function(
          ::portable_stl::allocator_arg_t{}, alloc, classA());
        ASSERT_TRUE(result);
        auto f = result.value();

        ASSERT_EQ(2, classA::count);
        ASSERT_TRUE(f.target<classA>());
        ASSERT_TRUE(nullptr == f.target<std::int32_t (*)(std::int32_t)>());
      }
      ASSERT_EQ(0, classA::count);

      // limit, bad allocation
      {
        test_allocator_helper::test_allocator_statistics stat;
        test_alloc                                       alloc(42, &stat);

        stat.m_throw_after = 0;
        ASSERT_EQ(0, classA::count);
        auto result = ::portable_stl::function<std::int32_t(std::int32_t)>::make_function(
          ::portable_stl::allocator_arg_t{}, alloc, classA());

        ASSERT_FALSE(result);
        ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
      }
      ASSERT_EQ(0, classA::count);

      // limit, bad allocation, exception
      {
        test_allocator_helper::test_allocator_statistics stat;
        test_alloc                                       alloc(42, &stat);

        stat.m_throw_after = 0;
        ASSERT_EQ(0, classA::count);
        try {
          ::portable_stl::function<std::int32_t(std::int32_t)> f(::portable_stl::allocator_arg_t{}, alloc, classA());
          ASSERT_TRUE(false);
        } catch (::portable_stl::bad_alloc<> &) {
        }
      }
      ASSERT_EQ(0, classA::count);
    }

    // Member function pointer with guarantee NO memory allocation need.
    {
      /**
       * @brief Alias.
       *
       */
      using MemFunClass = test_common_helper::MemFunClass;

      /**
       * @brief Test allocator. Any type
       *
       */
      using test_alloc = ::test_allocator_helper::TestSimpleAllocator<std::int32_t>;

      /**
       * @brief Member function pointer type.
       *
       */
      using mem_fn_type = std::int32_t (MemFunClass::*)() const;

      /**
       * @brief Reference member function pointer to save in function.
       *
       */
      mem_fn_type target = &MemFunClass::foo;

      // no limit, ok allocation
      {
        test_alloc alloc;

        auto result = ::portable_stl::function<std::int32_t(MemFunClass &)>::make_function(
          ::portable_stl::allocator_arg_t{}, alloc, target);
        ASSERT_TRUE(result);
        auto f = result.value();

        auto get_target = f.template target<mem_fn_type>();
        ASSERT_TRUE(nullptr != get_target);
        ASSERT_EQ(target, *get_target);
      }
      ASSERT_EQ(0, classA::count);

      // limit, no allocation need
      {
        test_alloc alloc;

        test_alloc::m_counter_ok_allocation = 0;
        auto result                         = ::portable_stl::function<std::int32_t(MemFunClass &)>::make_function(
          ::portable_stl::allocator_arg_t{}, alloc, target);
        ASSERT_TRUE(result);
        auto f = result.value();

        auto get_target = f.template target<mem_fn_type>();
        ASSERT_TRUE(nullptr != get_target);
        ASSERT_EQ(target, *get_target);
      }
    }
  }
}

namespace test_function_helper {
/**
 * @brief To use in allocator.
 *
 */
class DummyClass {};

template<class t_func_type, class t_allocator>
void test_FunctionObject(t_allocator &alloc, test_allocator_helper::test_allocator_statistics &alloc_stats) {
  /**
   * @brief Alias.
   *
   */
  using FunctionObject = test_common_helper::FunctionObject;

  {
    FunctionObject target;
    ASSERT_EQ(1, FunctionObject::count);

    ASSERT_EQ(0, alloc_stats.m_alloc_count);
    ::portable_stl::function<t_func_type> func(::portable_stl::allocator_arg, alloc, target);

    ASSERT_EQ(2, FunctionObject::count);
    ASSERT_EQ(1, alloc_stats.m_alloc_count);
    ASSERT_TRUE(func.template target<FunctionObject>());
    ASSERT_FALSE(func.template target<t_func_type>());
    ASSERT_FALSE(func.template target<t_func_type *>());
  }
  ASSERT_EQ(0, FunctionObject::count);
  ASSERT_EQ(0, alloc_stats.m_alloc_count);
}

template<class t_func_type, class t_allocator>
void test_LambdaObject(t_allocator &alloc, test_allocator_helper::test_allocator_statistics &alloc_stats) {
  {
    ASSERT_EQ(0, alloc_stats.m_alloc_count);
    std::int32_t                          capture{1};
    ::portable_stl::function<t_func_type> func([capture](std::int32_t val) {
      return capture * val;
    });

    ASSERT_EQ(0, alloc_stats.m_alloc_count);
    ASSERT_FALSE(func.template target<t_func_type>());
    ASSERT_FALSE(func.template target<t_func_type *>());
  }
  ASSERT_EQ(0, alloc_stats.m_alloc_count);
}

template<class t_func_type, class t_allocator>
void test_FreeFunction(t_allocator &alloc, test_allocator_helper::test_allocator_statistics &alloc_stats) {
  {
    t_func_type *target = &test_common_helper::FreeFunction;

    ASSERT_EQ(0, alloc_stats.m_alloc_count);
    ::portable_stl::function<t_func_type> func(::portable_stl::allocator_arg, alloc, target);

    // The allocator may not fit in the small object buffer (on 32bit platform), if we allocated check it was done via
    // the allocator.
    ASSERT_EQ((4 == sizeof(void *)), alloc_stats.m_alloc_count);

    ASSERT_TRUE(func.template target<t_func_type *>());

    auto get_target = func.template target<t_func_type *>();
    ASSERT_TRUE(nullptr != get_target);
    ASSERT_EQ(target, *get_target);

    ASSERT_FALSE(func.template target<t_func_type>());
    ASSERT_FALSE(func.template target<DummyClass>());
  }
  ASSERT_EQ(0, alloc_stats.m_alloc_count);
}

template<class t_target_type, class t_func_type, class t_allocator>
void test_MemFunClass(t_allocator &alloc, test_allocator_helper::test_allocator_statistics &alloc_stats) {
  {
    t_target_type target = &test_common_helper::MemFunClass::foo;

    ASSERT_EQ(0, alloc_stats.m_alloc_count);
    ::portable_stl::function<t_func_type> func(::portable_stl::allocator_arg, alloc, target);

    ASSERT_EQ(1, alloc_stats.m_alloc_count);

    auto get_target = func.template target<t_target_type>();
    ASSERT_TRUE(nullptr != get_target);
    ASSERT_EQ(target, *get_target);

    ASSERT_FALSE(func.template target<t_func_type *>());
  }
  ASSERT_EQ(0, alloc_stats.m_alloc_count);
}
} // namespace test_function_helper

// template<class F, class A> function(allocator_arg_t, const A&, F);
TEST(function, construction_allocator) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief Alias.
     *
     */
    using MemFunClass = test_common_helper::MemFunClass;

    /**
     * @brief Test allocator.
     *
     */
    using t_allocator = test_allocator_helper::test_allocator<test_function_helper::DummyClass>;

    test_allocator_helper::test_allocator_statistics stats;
    t_allocator                                      alloc(42, &stats);

    test_function_helper::test_FunctionObject<std::int32_t()>(alloc, stats);
    test_function_helper::test_FunctionObject<std::int32_t(std::int32_t)>(alloc, stats);
    test_function_helper::test_FunctionObject<std::int32_t(std::int32_t, std::int32_t)>(alloc, stats);
    test_function_helper::test_FunctionObject<std::int32_t(std::int32_t, std::int32_t, std::int32_t)>(alloc, stats);

    test_function_helper::test_FreeFunction<std::int32_t()>(alloc, stats);
    test_function_helper::test_FreeFunction<std::int32_t(std::int32_t)>(alloc, stats);
    test_function_helper::test_FreeFunction<std::int32_t(std::int32_t, std::int32_t)>(alloc, stats);
    test_function_helper::test_FreeFunction<std::int32_t(std::int32_t, std::int32_t, std::int32_t)>(alloc, stats);

    test_function_helper::test_MemFunClass<std::int32_t (MemFunClass::*)() const, std::int32_t(MemFunClass &)>(alloc,
                                                                                                               stats);
    test_function_helper::test_MemFunClass<std::int32_t (MemFunClass::*)(std::int32_t) const,
                                           std::int32_t(MemFunClass &, std::int32_t)>(alloc, stats);
    test_function_helper::test_MemFunClass<std::int32_t (MemFunClass::*)(std::int32_t, std::int32_t) const,
                                           std::int32_t(MemFunClass &, std::int32_t, std::int32_t)>(alloc, stats);

    test_function_helper::test_LambdaObject<std::int32_t(std::int32_t)>(alloc, stats);
  }
  {
    /**
     * @brief Alias.
     *
     */
    using RValueCallable = test_function_helper::RValueCallable;
    /**
     * @brief Alias.
     *
     */
    using LValueCallable = test_function_helper::LValueCallable;

    using Fn = ::portable_stl::function<void(std::int32_t, std::int32_t, std::int32_t)>;
    EXPECT_TRUE((::portable_stl::is_constructible<Fn,
                                                  ::portable_stl::allocator_arg_t,
                                                  ::portable_stl::allocator<std::int32_t>,
                                                  LValueCallable &>{}()));
    EXPECT_TRUE((::portable_stl::is_constructible<Fn,
                                                  ::portable_stl::allocator_arg_t,
                                                  ::portable_stl::allocator<std::int32_t>,
                                                  LValueCallable>{}()));
    EXPECT_FALSE((::portable_stl::is_constructible<Fn,
                                                   ::portable_stl::allocator_arg_t,
                                                   ::portable_stl::allocator<std::int32_t>,
                                                   RValueCallable &>{}()));
    EXPECT_FALSE((::portable_stl::is_constructible<Fn,
                                                   ::portable_stl::allocator_arg_t,
                                                   ::portable_stl::allocator<std::int32_t>,
                                                   RValueCallable>{}()));
  }
}

namespace test_function_helper {
template<class t_func_type, class t_allocator>
void test_FunctionObject_copy(t_allocator &alloc, test_allocator_helper::test_allocator_statistics &alloc_stats) {
  /**
   * @brief Alias.
   *
   */
  using FunctionObject = test_common_helper::FunctionObject;

  {
    // Construct function from FunctionObject.
    ::portable_stl::function<t_func_type> f = FunctionObject();
    ASSERT_EQ(1, FunctionObject::count);

    // Copy function with allocator
    ::portable_stl::function<t_func_type> f2(::portable_stl::allocator_arg, alloc, f);
    ASSERT_EQ(2, FunctionObject::count);
  }
  ASSERT_EQ(0, FunctionObject::count);
}

template<class t_func_type, class t_allocator> void test_FreeFunction_copy(t_allocator &alloc) {
  {
    // Construct function from function pointer.
    t_func_type                          *target = &test_common_helper::FreeFunction;
    ::portable_stl::function<t_func_type> f      = target;

    // Copy function with allocator
    ::portable_stl::function<t_func_type> f2(::portable_stl::allocator_arg, alloc, f);
  }
}

template<class t_target_type, class t_func_type, class t_allocator> void test_MemFunClass_copy(t_allocator &alloc) {
  {
    // Construct function from function pointer.
    t_target_type                         target = &test_common_helper::MemFunClass::foo;
    ::portable_stl::function<t_func_type> f      = target;

    // Copy function with allocator
    ::portable_stl::function<t_func_type> f2(::portable_stl::allocator_arg, alloc, f);
  }
}
} // namespace test_function_helper

// template<class A> function(allocator_arg_t, const A&, const function&);
TEST(function, construction_copy_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   *
   */
  using MemFunClass = test_common_helper::MemFunClass;

  /**
   * @brief Test allocator.
   *
   */
  using t_allocator = test_allocator_helper::test_allocator<test_function_helper::DummyClass>;

  test_allocator_helper::test_allocator_statistics stats;
  t_allocator                                      alloc(42, &stats);

  // Large FunctionObject -- Allocation should occur
  test_function_helper::test_FunctionObject_copy<std::int32_t()>(alloc, stats);
  test_function_helper::test_FunctionObject_copy<std::int32_t(std::int32_t)>(alloc, stats);
  test_function_helper::test_FunctionObject_copy<std::int32_t(std::int32_t, std::int32_t)>(alloc, stats);
  test_function_helper::test_FunctionObject_copy<std::int32_t(std::int32_t, std::int32_t, std::int32_t)>(alloc, stats);

  // Free function -- No allocation should occur
  test_function_helper::test_FreeFunction_copy<std::int32_t()>(alloc);
  test_function_helper::test_FreeFunction_copy<std::int32_t(std::int32_t)>(alloc);
  test_function_helper::test_FreeFunction_copy<std::int32_t(std::int32_t, std::int32_t)>(alloc);
  test_function_helper::test_FreeFunction_copy<std::int32_t(std::int32_t, std::int32_t, std::int32_t)>(alloc);

  // Member function -- No allocation should occur.
  test_function_helper::test_MemFunClass_copy<std::int32_t (MemFunClass::*)() const, std::int32_t(MemFunClass &)>(
    alloc);
  test_function_helper::test_MemFunClass_copy<std::int32_t (MemFunClass::*)(std::int32_t) const,
                                              std::int32_t(MemFunClass &, std::int32_t)>(alloc);
  test_function_helper::test_MemFunClass_copy<std::int32_t (MemFunClass::*)(std::int32_t, std::int32_t) const,
                                              std::int32_t(MemFunClass &, std::int32_t, std::int32_t)>(alloc);
}

// template<class A> function(allocator_arg_t, const A&, function&&);
TEST(function, construction_rfunction_allocator) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f = classA();
    ASSERT_EQ(1, classA::count);
    ASSERT_TRUE(f.target<classA>());
    ASSERT_TRUE(f.target<std::int32_t (*)(std::int32_t)>() == 0);

    ::portable_stl::function<std::int32_t(std::int32_t)> f2(
      ::portable_stl::allocator_arg, ::test_allocator_helper::test_allocator<classA>(), std::move(f));
    ASSERT_EQ(1, classA::count);
    ASSERT_TRUE(f2.target<classA>());
    ASSERT_TRUE(0 == f2.target<std::int32_t (*)(std::int32_t)>());
    ASSERT_TRUE(0 == f.target<classA>());
    ASSERT_TRUE(0 == f.target<std::int32_t (*)(std::int32_t)>());
  }
}

TEST(function, empty) {
  static_cast<void>(test_info_);

  {
    using F                       = void();
    F                          *f = nullptr;
    ::portable_stl::function<F> x(f);
    EXPECT_FALSE(static_cast<bool>(x)); // libstdc++/57465
  }

  {
    test_function_helper::F          f;
    ::portable_stl::function<void()> f1 = f;
    ::portable_stl::function<void()> f2 = ::portable_stl::ref(f);
  }
}

// function& operator=(const function& f);
TEST(function, copy_assignment) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f = classA();
    ASSERT_EQ(1, classA::count);
    ASSERT_TRUE(f.target<classA>());
    ASSERT_TRUE(0 == f.target<std::int32_t (*)(std::int32_t)>());

    ::portable_stl::function<std::int32_t(std::int32_t)> f2;
    f2 = f;
    ASSERT_EQ(2, classA::count);
    ASSERT_TRUE(f2.target<classA>());
    ASSERT_TRUE(0 == f2.target<std::int32_t (*)(std::int32_t)>());
  }
  ASSERT_EQ(0, classA::count);
  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f = test_function_helper::g;
    ASSERT_TRUE(f.target<std::int32_t (*)(std::int32_t)>());
    ASSERT_TRUE(0 == f.target<classA>());

    ::portable_stl::function<std::int32_t(std::int32_t)> f2;
    f2 = f;
    ASSERT_TRUE(f2.target<std::int32_t (*)(std::int32_t)>());
    ASSERT_TRUE(0 == f2.target<classA>());
  }
  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f;
    ASSERT_TRUE(0 == f.target<std::int32_t (*)(std::int32_t)>());
    ASSERT_TRUE(0 == f.target<classA>());

    ::portable_stl::function<std::int32_t(std::int32_t)> f2;
    f2 = f;
    ASSERT_TRUE(0 == f2.target<std::int32_t (*)(std::int32_t)>());
    ASSERT_TRUE(0 == f2.target<classA>());
  }
  {
    /**
     * @brief Alias.
     *
     */
    using Func = ::portable_stl::function<std::int32_t()>;
    Func  f    = test_function_helper::g0;
    Func &fr   = (f = (Func &)f);
    ASSERT_EQ(&fr, &f);

    auto get_target = f.template target<std::int32_t (*)()>();
    ASSERT_TRUE(nullptr != get_target);
    ASSERT_EQ(test_function_helper::g0, *get_target);
  }
  {
    /**
     * @brief Alias.
     *
     */
    using Func = ::portable_stl::function<std::int32_t(std::int32_t)>;
    Func  f    = test_function_helper::g;
    Func &fr   = (f = (Func &)f);
    ASSERT_EQ(&fr, &f);
    ASSERT_EQ(*f.target<std::int32_t (*)(std::int32_t)>(), test_function_helper::g);
  }
  {
    /**
     * @brief Alias.
     *
     */
    using Func = ::portable_stl::function<std::int32_t(std::int32_t, std::int32_t)>;
    Func  f    = test_function_helper::g2;
    Func &fr   = (f = (Func &)f);
    ASSERT_EQ(&fr, &f);
    ASSERT_EQ(*f.target<std::int32_t (*)(std::int32_t, std::int32_t)>(), test_function_helper::g2);
  }
  {
    /**
     * @brief Alias.
     *
     */
    using Func = ::portable_stl::function<std::int32_t(std::int32_t, std::int32_t, std::int32_t)>;
    Func  f    = test_function_helper::g3;
    Func &fr   = (f = (Func &)f);
    ASSERT_EQ(&fr, &f);
    ASSERT_EQ(*f.target<std::int32_t (*)(std::int32_t, std::int32_t, std::int32_t)>(), test_function_helper::g3);
  }

  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f = classA();
    ASSERT_EQ(1, classA::count);
    ASSERT_TRUE(f.target<classA>());
    ASSERT_TRUE(0 == f.target<std::int32_t (*)(std::int32_t)>());

    ::portable_stl::function<std::int32_t(std::int32_t)> f2;
    f2 = std::move(f);
    ASSERT_EQ(1, classA::count);
    ASSERT_TRUE(f2.target<classA>());
    ASSERT_TRUE(0 == f2.target<std::int32_t (*)(std::int32_t)>());
    ASSERT_TRUE(0 == f.target<classA>());
    ASSERT_TRUE(0 == f.target<std::int32_t (*)(std::int32_t)>());
  }
}

// function(const function& f);
// function(function&& f) noexcept;
TEST(function, copy_move) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f = classA();
    ASSERT_EQ(1, classA::count);
    ASSERT_TRUE(f.target<classA>());
    ASSERT_TRUE(0 == f.target<std::int32_t (*)(std::int32_t)>());

    ::portable_stl::function<std::int32_t(std::int32_t)> f2 = f;
    assert(classA::count == 2);
    ASSERT_TRUE(f2.target<classA>());
    ASSERT_TRUE(0 == f2.target<std::int32_t (*)(std::int32_t)>());
  }
  ASSERT_EQ(0, classA::count);
  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f = test_function_helper::g;
    ASSERT_TRUE(f.target<std::int32_t (*)(std::int32_t)>());
    ASSERT_TRUE(0 == f.target<classA>());

    ::portable_stl::function<std::int32_t(std::int32_t)> f2 = f;
    ASSERT_TRUE(f2.target<std::int32_t (*)(std::int32_t)>());
    ASSERT_TRUE(0 == f2.target<classA>());
  }
  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f;
    ASSERT_TRUE(0 == f.target<std::int32_t (*)(std::int32_t)>());
    ASSERT_TRUE(0 == f.target<classA>());

    ::portable_stl::function<std::int32_t(std::int32_t)> f2 = f;
    ASSERT_TRUE(0 == f2.target<std::int32_t (*)(std::int32_t)>());
    ASSERT_TRUE(0 == f2.target<classA>());
  }
  // ambiguous overload resolution in msvc
  // {
  //   ::portable_stl::function<std::int32_t(std::int32_t)> f;
  //   ASSERT_TRUE(0 == f.target<std::int32_t (*)(std::int32_t)>());
  //   ASSERT_TRUE(0 == f.target<classA>());
  //   ASSERT_FALSE(f);

  //   ::portable_stl::function<std::int64_t(std::int32_t)> g = f;
  //   ASSERT_TRUE(0 == g.target<std::int64_t (*)(std::int32_t)>());
  //   ASSERT_TRUE(0 == g.target<classA>());
  //   ASSERT_FALSE(g);
  // }

  // Test rvalue references
  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f = classA();
    ASSERT_EQ(1, classA::count);
    ASSERT_TRUE(f.target<classA>());
    ASSERT_TRUE(0 == f.target<std::int32_t (*)(std::int32_t)>());
    ASSERT_TRUE(noexcept(::portable_stl::function<std::int32_t(std::int32_t)>(std::move(f))));

    ::portable_stl::function<std::int32_t(std::int32_t)> f2 = std::move(f);
    ASSERT_EQ(1, classA::count);
    ASSERT_TRUE(f2.target<classA>());
    ASSERT_TRUE(0 == f2.target<std::int32_t (*)(std::int32_t)>());
    ASSERT_TRUE(0 == f.target<classA>());
    ASSERT_TRUE(0 == f.target<std::int32_t (*)(std::int32_t)>());
  }
}

// function& operator=(nullptr_t);
TEST(function, assign_nullptr) {
  static_cast<void>(test_info_);

  // assert(globalMemCounter.checkOutstandingNewEq(0));
  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f = classA();
    ASSERT_EQ(1, classA::count);
    ASSERT_TRUE(f.target<classA>());

    f = nullptr;
    ASSERT_EQ(0, classA::count);
    ASSERT_TRUE(0 == f.target<classA>());
  }
  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f = test_function_helper::g;
    ASSERT_TRUE(f.target<std::int32_t (*)(std::int32_t)>());
    ASSERT_TRUE(0 == f.target<classA>());

    f = nullptr;
    ASSERT_TRUE(0 == f.target<std::int32_t (*)(std::int32_t)>());
  }
}

TEST(function, assign) {
  static_cast<void>(test_info_);

  ASSERT_EQ(0, classA::count);
  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f;
    f = classA();
    ASSERT_EQ(1, classA::count);
  }
  ASSERT_EQ(0, classA::count);
  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f;
    f = test_function_helper::g;
  }
  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f;
    f = (std::int32_t(*)(std::int32_t))0;
    ASSERT_FALSE(f);
  }
  {
    ::portable_stl::function<std::int32_t(classA const *, std::int32_t)> f;
    f = &classA::foo;
    ASSERT_TRUE(f);
  }
  {
    ::portable_stl::function<void(std::int32_t)> f;
    f = &test_function_helper::g;
    ASSERT_TRUE(f);
    f(1);
  }
  {
    /**
     * @brief Alias.
     *
     */
    using RValueCallable = test_function_helper::RValueCallable;
    /**
     * @brief Alias.
     *
     */
    using LValueCallable = test_function_helper::LValueCallable;

    /**
     * @brief Alias.
     *
     */
    using Fn = ::portable_stl::function<void(std::int32_t, std::int32_t, std::int32_t)>;
    ASSERT_TRUE((std::is_assignable<Fn &, LValueCallable &>{}));
    ASSERT_TRUE((std::is_assignable<Fn &, LValueCallable>{}));
    ASSERT_FALSE((std::is_assignable<Fn &, RValueCallable &>{}));
    ASSERT_FALSE((std::is_assignable<Fn &, RValueCallable>{}));
  }
  {
    /**
     * @brief Alias.
     *
     */
    using Fn = ::portable_stl::function<void(std::int32_t, std::int32_t, std::int32_t)>;
    ASSERT_TRUE((std::is_assignable<Fn &, Fn &&>{}));
  }
  {
    /**
     * @brief Alias.
     *
     */
    using F1 = ::portable_stl::function<void(std::int32_t, std::int32_t)>;
    /**
     * @brief Alias.
     *
     */
    using F2 = ::portable_stl::function<void(std::int32_t, std::int32_t, std::int32_t)>;
    ASSERT_FALSE((std::is_assignable<F1 &, F2 &&>{}));
  }
  {
    /**
     * @brief Alias.
     *
     */
    using F1 = ::portable_stl::function<std::int32_t(std::int32_t, std::int32_t)>;
    /**
     * @brief Alias.
     *
     */
    using F2 = ::portable_stl::function<classA(std::int32_t, std::int32_t)>;
    ASSERT_FALSE((std::is_assignable<F1 &, F2 &&>{}));
    ASSERT_FALSE((std::is_assignable<F2 &, F1 &&>{}));
  }
}

TEST(function, swap) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f1 = classA(1);
    ::portable_stl::function<std::int32_t(std::int32_t)> f2 = classA(2);

    ASSERT_TRUE(noexcept(swap(f1, f2)));
    ASSERT_EQ(2, classA::count);
    {
      auto get_target1 = f1.template target<classA>();
      ASSERT_TRUE(nullptr != get_target1);
      ASSERT_EQ(1, get_target1->id());

      auto get_target2 = f2.template target<classA>();
      ASSERT_TRUE(nullptr != get_target2);
      ASSERT_EQ(2, get_target2->id());
    }

    swap(f1, f2);
    ASSERT_EQ(2, classA::count);
    {
      auto get_target1 = f1.template target<classA>();
      ASSERT_TRUE(nullptr != get_target1);
      ASSERT_EQ(2, get_target1->id());

      auto get_target2 = f2.template target<classA>();
      ASSERT_TRUE(nullptr != get_target2);
      ASSERT_EQ(1, get_target2->id());
    }
  }
  ASSERT_EQ(0, classA::count);
  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f1 = classA(1);
    ::portable_stl::function<std::int32_t(std::int32_t)> f2 = test_function_helper::g;

    ASSERT_TRUE(noexcept(swap(f1, f2)));
    ASSERT_EQ(1, classA::count);
    {
      auto get_target1 = f1.template target<classA>();
      ASSERT_TRUE(nullptr != get_target1);
      ASSERT_EQ(1, get_target1->id());

      auto get_target2 = f2.template target<std::int32_t (*)(std::int32_t)>();
      ASSERT_TRUE(nullptr != get_target2);
      ASSERT_EQ(test_function_helper::g, *get_target2);
    }

    swap(f1, f2);
    ASSERT_EQ(1, classA::count);
    {
      auto get_target1 = f1.template target<std::int32_t (*)(std::int32_t)>();
      ASSERT_TRUE(nullptr != get_target1);
      ASSERT_EQ(test_function_helper::g, *get_target1);

      auto get_target2 = f2.template target<classA>();
      ASSERT_TRUE(nullptr != get_target2);
      ASSERT_EQ(1, get_target2->id());
    }
  }
  ASSERT_EQ(0, classA::count);
  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f1 = test_function_helper::g;
    ::portable_stl::function<std::int32_t(std::int32_t)> f2 = classA(1);

    ASSERT_TRUE(noexcept(swap(f1, f2)));
    ASSERT_EQ(1, classA::count);

    {
      auto get_target1 = f1.template target<std::int32_t (*)(std::int32_t)>();
      ASSERT_TRUE(nullptr != get_target1);
      ASSERT_EQ(test_function_helper::g, *get_target1);

      auto get_target2 = f2.template target<classA>();
      ASSERT_TRUE(nullptr != get_target2);
      ASSERT_EQ(1, get_target2->id());
    }

    swap(f1, f2);
    ASSERT_EQ(1, classA::count);

    {
      auto get_target1 = f1.template target<classA>();
      ASSERT_TRUE(nullptr != get_target1);
      ASSERT_EQ(1, get_target1->id());

      auto get_target2 = f2.template target<std::int32_t (*)(std::int32_t)>();
      ASSERT_TRUE(nullptr != get_target2);
      ASSERT_EQ(test_function_helper::g, *get_target2);
    }
  }
  ASSERT_EQ(0, classA::count);
  {
    ::portable_stl::function<std::int32_t(std::int32_t)> f1 = test_function_helper::g;
    ::portable_stl::function<std::int32_t(std::int32_t)> f2 = test_function_helper::h;

    ASSERT_TRUE(noexcept(swap(f1, f2)));
    ASSERT_EQ(0, classA::count);

    {
      auto get_target1 = f1.template target<std::int32_t (*)(std::int32_t)>();
      ASSERT_TRUE(nullptr != get_target1);
      ASSERT_EQ(test_function_helper::g, *get_target1);

      auto get_target2 = f2.template target<std::int32_t (*)(std::int32_t)>();
      ASSERT_TRUE(nullptr != get_target2);
      ASSERT_EQ(test_function_helper::h, *get_target2);
    }

    swap(f1, f2);
    ASSERT_EQ(0, classA::count);

    {
      auto get_target1 = f1.template target<std::int32_t (*)(std::int32_t)>();
      ASSERT_TRUE(nullptr != get_target1);
      ASSERT_EQ(test_function_helper::h, *get_target1);

      auto get_target2 = f2.template target<std::int32_t (*)(std::int32_t)>();
      ASSERT_TRUE(nullptr != get_target2);
      ASSERT_EQ(test_function_helper::g, *get_target2);
    }
  }
  ASSERT_EQ(0, classA::count);
}

TEST(function, operator_bool) {
  static_cast<void>(test_info_);

  ASSERT_TRUE((std::is_constructible<bool, ::portable_stl::function<void()>>{}));
  ASSERT_FALSE((std::is_convertible<::portable_stl::function<void()>, bool>{}));

  ::portable_stl::function<std::int32_t(std::int32_t)> f;
  ASSERT_FALSE(f);

  f = test_function_helper::g;
  ASSERT_TRUE(f);
}

namespace test_function_helper {

static std::int32_t count{0};

// 0 args, return int

static std::int32_t f_int_0() {
  return 3;
}

class A_int_0 final {
public:
  std::int32_t operator()() {
    return 4;
  }
};

// 0 args, return void

static void f_void_0() {
  ++count;
}

class A_void_0 final {
public:
  void operator()() {
    ++count;
  }
};

// 1 arg, return void

static void f_void_1(std::int32_t i) {
  count += i;
}

class A_void_1 final {
public:
  void operator()(std::int32_t i) {
    count += i;
  }

  void mem1() {
    ++count;
  }
  void mem2() const {
    ++count;
  }
};

// 1 arg, return int

static std::int32_t f_int_1(std::int32_t i) {
  return i + 1;
}

class A_int_1 final {
public:
  A_int_1() : m_data(5) {
  }
  std::int32_t operator()(std::int32_t i) {
    return i - 1;
  }

  std::int32_t mem1() {
    return 3;
  }
  std::int32_t mem2() const {
    return 4;
  }
  std::int32_t m_data;
};

// 2 arg, return void

static void f_void_2(std::int32_t i, std::int32_t j) {
  count += i + j;
}

class A_void_2 final {
public:
  void operator()(std::int32_t i, std::int32_t j) {
    count += i + j;
  }

  void mem1(std::int32_t i) {
    count += i;
  }
  void mem2(std::int32_t i) const {
    count += i;
  }
};

// 2 arg, return int

static std::int32_t f_int_2(std::int32_t i, std::int32_t j) {
  return i + j;
}

class A_int_2 final {
public:
  std::int32_t operator()(std::int32_t i, std::int32_t j) {
    return i + j;
  }

  std::int32_t mem1(std::int32_t i) {
    return i + 1;
  }
  std::int32_t mem2(std::int32_t i) const {
    return i + 2;
  }
};

} // namespace test_function_helper

TEST(function, invoke) {
  static_cast<void>(test_info_);

  test_function_helper::count = 0;

  // 0 args, return int
  {
    // function
    {
      ::portable_stl::function<std::int32_t()> r1(test_function_helper::f_int_0);
      ASSERT_EQ(3, r1());
    }

    // function pointer
    {
      std::int32_t (*fp)() = test_function_helper::f_int_0;
      ::portable_stl::function<std::int32_t()> r1(fp);
      ASSERT_EQ(3, r1());
    }

    // functor
    {
      test_function_helper::A_int_0            a0;
      ::portable_stl::function<std::int32_t()> r1(a0);
      ASSERT_EQ(4, r1());
    }
  }

  // 0 args, return void
  {
    std::int32_t save_count{test_function_helper::count};

    // function
    {
      ::portable_stl::function<void()> r1(test_function_helper::f_void_0);

      r1();
      ASSERT_EQ(test_function_helper::count, save_count + 1);
      save_count = test_function_helper::count;
    }
    // function pointer
    {
      void (*fp)() = test_function_helper::f_void_0;
      ::portable_stl::function<void()> r1(fp);

      r1();
      ASSERT_EQ(test_function_helper::count, save_count + 1);
      save_count = test_function_helper::count;
    }
    // functor
    {
      test_function_helper::A_void_0   a0;
      ::portable_stl::function<void()> r1(a0);

      r1();
      ASSERT_EQ(test_function_helper::count, save_count + 1);
      save_count = test_function_helper::count;
    }
  }

  // 1 arg, return void
  {
    std::int32_t save_count{test_function_helper::count};

    // function
    {
      ::portable_stl::function<void(std::int32_t)> r1(test_function_helper::f_void_1);
      std::int32_t                                 i{2};

      r1(i);
      ASSERT_EQ(test_function_helper::count, save_count + 2);
      save_count = test_function_helper::count;
    }

    // function pointer
    {
      void (*fp)(std::int32_t) = test_function_helper::f_void_1;
      ::portable_stl::function<void(std::int32_t)> r1(fp);
      std::int32_t                                 i{3};

      r1(i);
      ASSERT_EQ(test_function_helper::count, save_count + 3);
      save_count = test_function_helper::count;
    }

    // functor
    {
      test_function_helper::A_void_1               a0;
      ::portable_stl::function<void(std::int32_t)> r1(a0);
      std::int32_t                                 i{4};

      r1(i);
      ASSERT_EQ(test_function_helper::count, save_count + 4);
      save_count = test_function_helper::count;
    }

    // member function pointer
    {
      void (test_function_helper::A_void_1::*fp)() = &test_function_helper::A_void_1::mem1;
      ::portable_stl::function<void(test_function_helper::A_void_1)> r1(fp);
      test_function_helper::A_void_1                                 a;

      r1(a);
      ASSERT_EQ(test_function_helper::count, save_count + 1);
      save_count                                                          = test_function_helper::count;
      test_function_helper::A_void_1                                  *ap = &a;
      ::portable_stl::function<void(test_function_helper::A_void_1 *)> r2 = fp;

      r2(ap);
      ASSERT_EQ(test_function_helper::count, save_count + 1);
      save_count = test_function_helper::count;
    }

    // const member function pointer
    {
      void (test_function_helper::A_void_1::*fp)() const = &test_function_helper::A_void_1::mem2;
      ::portable_stl::function<void(test_function_helper::A_void_1)> r1(fp);
      test_function_helper::A_void_1                                 a;

      r1(a);
      ASSERT_EQ(test_function_helper::count, save_count + 1);
      save_count = test_function_helper::count;
      ::portable_stl::function<void(test_function_helper::A_void_1 *)> r2(fp);
      test_function_helper::A_void_1                                  *ap = &a;

      r2(ap);
      ASSERT_EQ(test_function_helper::count, save_count + 1);
      save_count = test_function_helper::count;
    }
  }

  // 1 arg, return int
  {
    // function
    {
      ::portable_stl::function<std::int32_t(std::int32_t)> r1(test_function_helper::f_int_1);
      std::int32_t                                         i{2};
      ASSERT_EQ(r1(i), 3);
    }

    // function pointer
    {
      std::int32_t (*fp)(std::int32_t) = test_function_helper::f_int_1;
      ::portable_stl::function<std::int32_t(std::int32_t)> r1(fp);
      std::int32_t                                         i{3};
      ASSERT_EQ(r1(i), 4);
    }

    // functor
    {
      test_function_helper::A_int_1                        a0;
      ::portable_stl::function<std::int32_t(std::int32_t)> r1(a0);
      std::int32_t                                         i{4};
      ASSERT_EQ(r1(i), 3);
    }

    // member function pointer
    {
      std::int32_t (test_function_helper::A_int_1::*fp)() = &test_function_helper::A_int_1::mem1;
      ::portable_stl::function<std::int32_t(test_function_helper::A_int_1)> r1(fp);
      test_function_helper::A_int_1                                         a;
      ASSERT_EQ(r1(a), 3);

      ::portable_stl::function<std::int32_t(test_function_helper::A_int_1 *)> r2(fp);
      test_function_helper::A_int_1                                          *ap = &a;
      ASSERT_EQ(r2(ap), 3);
    }

    // const member function pointer
    {
      std::int32_t (test_function_helper::A_int_1::*fp)() const = &test_function_helper::A_int_1::mem2;
      ::portable_stl::function<std::int32_t(test_function_helper::A_int_1)> r1(fp);
      test_function_helper::A_int_1                                         a;
      ASSERT_EQ(r1(a), 4);

      ::portable_stl::function<std::int32_t(test_function_helper::A_int_1 *)> r2(fp);
      test_function_helper::A_int_1                                          *ap = &a;
      ASSERT_EQ(r2(ap), 4);
    }

    // member data pointer
    {
      std::int32_t test_function_helper::A_int_1::*fp = &test_function_helper::A_int_1::m_data;
      ::portable_stl::function<std::int32_t &(test_function_helper::A_int_1 &)> r1(fp);
      test_function_helper::A_int_1                                             a;
      ASSERT_EQ(r1(a), 5);

      r1(a) = 6;
      ASSERT_EQ(r1(a), 6);

      ::portable_stl::function<std::int32_t &(test_function_helper::A_int_1 *)> r2(fp);
      test_function_helper::A_int_1                                            *ap = &a;
      ASSERT_EQ(r2(ap), 6);

      r2(ap) = 7;
      ASSERT_EQ(r2(ap), 7);
    }
  }

  // 2 arg, return void
  {
    std::int32_t save_count{test_function_helper::count};

    // function
    {
      ::portable_stl::function<void(std::int32_t, std::int32_t)> r1(test_function_helper::f_void_2);
      std::int32_t                                               i = 2;
      std::int32_t                                               j = 3;

      r1(i, j);
      ASSERT_EQ(test_function_helper::count, save_count + 5);
      save_count = test_function_helper::count;
    }

    // function pointer
    {
      void (*fp)(std::int32_t, std::int32_t) = test_function_helper::f_void_2;
      ::portable_stl::function<void(std::int32_t, std::int32_t)> r1(fp);
      std::int32_t                                               i = 3;
      std::int32_t                                               j = 4;

      r1(i, j);
      ASSERT_EQ(test_function_helper::count, save_count + 7);
      save_count = test_function_helper::count;
    }

    // functor
    {
      test_function_helper::A_void_2                             a0;
      ::portable_stl::function<void(std::int32_t, std::int32_t)> r1(a0);
      std::int32_t                                               i = 4;
      std::int32_t                                               j = 5;

      r1(i, j);
      ASSERT_EQ(test_function_helper::count, save_count + 9);
      save_count = test_function_helper::count;
    }

    // member function pointer
    {
      void (test_function_helper::A_void_2::*fp)(std::int32_t) = &test_function_helper::A_void_2::mem1;
      ::portable_stl::function<void(test_function_helper::A_void_2, std::int32_t)> r1(fp);
      test_function_helper::A_void_2                                               a;
      std::int32_t                                                                 i = 3;

      r1(a, i);
      ASSERT_EQ(test_function_helper::count, save_count + 3);
      save_count = test_function_helper::count;
      ::portable_stl::function<void(test_function_helper::A_void_2 *, std::int32_t)> r2(fp);
      test_function_helper::A_void_2                                                *ap = &a;

      r2(ap, i);
      ASSERT_EQ(test_function_helper::count, save_count + 3);
      save_count = test_function_helper::count;
    }

    // const member function pointer
    {
      void (test_function_helper::A_void_2::*fp)(std::int32_t) const = &test_function_helper::A_void_2::mem2;
      ::portable_stl::function<void(test_function_helper::A_void_2, std::int32_t)> r1(fp);
      test_function_helper::A_void_2                                               a;
      std::int32_t                                                                 i = 4;

      r1(a, i);
      ASSERT_EQ(test_function_helper::count, save_count + 4);
      save_count = test_function_helper::count;
      ::portable_stl::function<void(test_function_helper::A_void_2 *, std::int32_t)> r2(fp);
      test_function_helper::A_void_2                                                *ap = &a;

      r2(ap, i);
      ASSERT_EQ(test_function_helper::count, save_count + 4);
      save_count = test_function_helper::count;
    }
  }

  // 2 arg, return int
  {
    // function
    {
      ::portable_stl::function<std::int32_t(std::int32_t, std::int32_t)> r1(test_function_helper::f_int_2);
      std::int32_t const                                                 i{2};
      std::int32_t const                                                 j{3};

      ASSERT_EQ(r1(i, j), i + j);
    }

    // function pointer
    {
      std::int32_t (*fp)(std::int32_t, std::int32_t) = test_function_helper::f_int_2;
      ::portable_stl::function<std::int32_t(std::int32_t, std::int32_t)> r1(fp);
      std::int32_t const                                                 i{3};
      std::int32_t const                                                 j{4};

      ASSERT_EQ(r1(i, j), i + j);
    }

    // functor
    {
      test_function_helper::A_int_2                                      a0;
      ::portable_stl::function<std::int32_t(std::int32_t, std::int32_t)> r1(a0);
      std::int32_t const                                                 i{4};
      std::int32_t const                                                 j{5};

      ASSERT_EQ(r1(i, j), i + j);
    }

    // member function pointer
    {
      std::int32_t (test_function_helper::A_int_2::*fp)(std::int32_t) = &test_function_helper::A_int_2::mem1;
      ::portable_stl::function<std::int32_t(test_function_helper::A_int_2, std::int32_t)> r1(fp);
      test_function_helper::A_int_2                                                       a;
      std::int32_t const                                                                  i{3};

      ASSERT_EQ(r1(a, i), i + 1);
      ::portable_stl::function<std::int32_t(test_function_helper::A_int_2 *, std::int32_t)> r2(fp);

      test_function_helper::A_int_2 *ap = &a;
      ASSERT_EQ(r2(ap, i), i + 1);
    }

    // const member function pointer
    {
      std::int32_t (test_function_helper::A_int_2::*fp)(std::int32_t) const = &test_function_helper::A_int_2::mem2;
      ::portable_stl::function<std::int32_t(test_function_helper::A_int_2, std::int32_t)> r1(fp);
      test_function_helper::A_int_2                                                       a;
      std::int32_t                                                                        i = 4;
      ASSERT_EQ(r1(a, i), i + 2);
      ::portable_stl::function<std::int32_t(test_function_helper::A_int_2 *, std::int32_t)> r2(fp);
      test_function_helper::A_int_2                                                        *ap = &a;
      ASSERT_EQ(r2(ap, i), i + 2);
    }
  }
}

TEST(function, comp_nullptr) {
  static_cast<void>(test_info_);

  ::portable_stl::function<std::int32_t(std::int32_t)> f;
  ASSERT_TRUE(f == nullptr);
  // ASSERT_FALSE(f != nullptr); // (until C++20)
  // ASSERT_TRUE(nullptr == f); // (until C++20)
  // ASSERT_TRUE(f == nullptr); // (until C++20)

  f = test_function_helper::g;
  ASSERT_FALSE(f == nullptr);
  // ASSERT_TRUE(f != nullptr); // (until C++20)
  // ASSERT_TRUE(nullptr != f); // (until C++20)
  // ASSERT_FALSE(nullptr == f); // (until C++20)
}
