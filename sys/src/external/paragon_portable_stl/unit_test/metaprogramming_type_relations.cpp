// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_type_relations.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <vector>

#include "portable_stl/metaprogramming/type_relations/is_base_of.h"
#include "portable_stl/metaprogramming/type_relations/is_convertible.h"
#include "portable_stl/metaprogramming/type_relations/is_invocable.h"
#include "portable_stl/metaprogramming/type_relations/is_invocable_r.h"
#include "portable_stl/metaprogramming/type_relations/is_same.h"
#include "portable_stl/utility/general/functional/reference_wrapper.h"
#include "portable_stl/containers/../utility/tuple/tuple.h"

#if defined(__cpp_inline_variables)
#  include "metaprogramming_type_relations_inline_variables.h"
#else
#  include "metaprogramming_type_relations.h"
#endif

#include "metaprogramming_type_relations_helper.h"

TEST(metaprogramming_type_relations, is_same) {
  static_cast<void>(test_info_);
  ASSERT_TRUE((::portable_stl::is_same<std::uint32_t, std::uint32_t>{}()));
  ASSERT_FALSE((::portable_stl::is_same<std::uint32_t, std::uint32_t const>{}()));
  ASSERT_FALSE((::portable_stl::is_same<std::uint32_t, std::uint32_t volatile>{}()));
  ASSERT_FALSE((::portable_stl::is_same<std::uint32_t, std::uint32_t const volatile>{}()));

  test_metaprogramming_type_relations::metaprogramming_type_relations_is_same_inline_variables();
}

TEST(metaprogramming_type_relations, is_convertible) {
  static_cast<void>(test_info_);

  /**
   * @brief Helper class for check impilicit conversion.
   *
   */
  class implicit_check final {
  public:
    /**
     * @brief Construct a new implicit check object = deleted.
     *
     */
    constexpr implicit_check() noexcept = delete;

    /**
     * @brief Construct a new implicit check object from void pointer.
     *
     */
    constexpr implicit_check(void *) noexcept {
    }

    /**
     * @brief Convert implicit check object to void pointer.
     *
     * @return void *
     */
    constexpr operator void *() const noexcept {
      return nullptr;
    }
  };

  /**
   * @brief Helper class for check explicit conversion.
   *
   */
  class explicit_check final {
  public:
    /**
     * @brief Construct a new explicit check object = deleted.
     *
     */
    constexpr explicit_check() noexcept = delete;

    /**
     * @brief Construct a new explicit check object from void pointer.
     *
     */
    constexpr explicit explicit_check(void *) noexcept {
    }

    /**
     * @brief Convert from explicit check object to void pointer.
     *
     * @return void *
     */
    constexpr explicit operator void *() const noexcept {
      return nullptr;
    }
  };

  {
    constexpr implicit_check checker{nullptr};
    ASSERT_EQ(nullptr, checker);
  }

  {
    constexpr explicit_check checker{nullptr};
    ASSERT_EQ(nullptr, static_cast<void *>(checker));
  }

  ASSERT_TRUE((::portable_stl::is_convertible<void, void>{}()));
  ASSERT_FALSE((::portable_stl::is_convertible<void, std::uint8_t>{}()));
  ASSERT_FALSE((::portable_stl::is_convertible<std::uint8_t, void>{}()));

  ASSERT_TRUE((::portable_stl::is_convertible<std::uint8_t, std::uint32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_convertible<std::uint32_t, std::uint8_t>{}()));
  ASSERT_FALSE((::portable_stl::is_convertible<void *, std::uint8_t *>{}()));
  ASSERT_TRUE((::portable_stl::is_convertible<std::uint8_t *, void *>{}()));
  ASSERT_TRUE((::portable_stl::is_convertible<std::uint8_t *, void const *>{}()));
  ASSERT_TRUE((::portable_stl::is_convertible<std::uint8_t const *, void const *>{}()));

  ASSERT_FALSE((::portable_stl::is_convertible<std::uint8_t const *, void *>{}()));
  ASSERT_FALSE((::portable_stl::is_convertible<void const *, explicit_check>{}()));
  ASSERT_FALSE((::portable_stl::is_convertible<void *, explicit_check>{}()));
  ASSERT_FALSE((::portable_stl::is_convertible<explicit_check, void const *>{}()));
  ASSERT_FALSE((::portable_stl::is_convertible<explicit_check, void *>{}()));

  ASSERT_FALSE((::portable_stl::is_convertible<void const *, implicit_check>{}()));
  ASSERT_TRUE((::portable_stl::is_convertible<void *, implicit_check>{}()));
  ASSERT_TRUE((::portable_stl::is_convertible<implicit_check, void const *>{}()));
  ASSERT_TRUE((::portable_stl::is_convertible<implicit_check, void *>{}()));

  {
    constexpr ::portable_stl::is_convertible<void, void> checker{};
    ASSERT_TRUE((checker()));
    static_cast<void>(checker);
  }
  {
    constexpr ::portable_stl::is_convertible<std::uint8_t *, void *> checker{};
    ASSERT_TRUE((checker()));
    static_cast<void>(checker);
  }
  {
    constexpr ::portable_stl::is_convertible<void *, std::uint8_t *> checker{};
    ASSERT_FALSE((checker()));
    static_cast<void>(checker);
  }
}

TEST(metaprogramming_type_relations, is_base_of) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief Helper type
     */
    using test_value_t = ::portable_stl::is_base_of<metaprogramming_type_relations_helper::Base1,
                                                    metaprogramming_type_relations_helper::Derived1>;

    ASSERT_TRUE((std::is_same<::portable_stl::true_type, test_value_t>{}()));
  }

  ASSERT_TRUE((::portable_stl::is_base_of<metaprogramming_type_relations_helper::Base1,
                                          metaprogramming_type_relations_helper::Derived1>{}()));
  ASSERT_TRUE((::portable_stl::is_base_of<metaprogramming_type_relations_helper::Derived1,
                                          metaprogramming_type_relations_helper::Derived2>{}()));
  ASSERT_TRUE((::portable_stl::is_base_of<metaprogramming_type_relations_helper::Base2,
                                          metaprogramming_type_relations_helper::Derived3>{}()));

  ASSERT_FALSE((::portable_stl::is_base_of<metaprogramming_type_relations_helper::Base2,
                                           metaprogramming_type_relations_helper::Derived1>{}()));
  ASSERT_FALSE((::portable_stl::is_base_of<metaprogramming_type_relations_helper::Base2,
                                           metaprogramming_type_relations_helper::Derived2>{}()));

  ASSERT_FALSE((::portable_stl::is_base_of<metaprogramming_type_relations_helper::Base1,
                                           metaprogramming_type_relations_helper::Derived3>{}()));

  ASSERT_FALSE((::portable_stl::is_base_of<std::uint32_t, std::uint32_t>{}()));

  // private base
  ASSERT_TRUE((::portable_stl::is_base_of<metaprogramming_type_relations_helper::Base1,
                                          metaprogramming_type_relations_helper::Derived2>{}()));
  // but still
  ASSERT_FALSE((::std::is_convertible<metaprogramming_type_relations_helper::Derived2 *,
                                      metaprogramming_type_relations_helper::Base1 *>{}()));

  test_metaprogramming_type_relations::metaprogramming_type_relations_is_base_of_inline_variables();
}

namespace test_metaprogramming_type_relations_helper {
struct Tag {};

struct DerFromTag : Tag {};

struct Implicit {
  Implicit(std::int32_t) {
  }
};

struct Explicit {
  explicit Explicit(std::int32_t) {
  }
};

struct NotCallableWithInt {
  std::int32_t operator()(std::int32_t) = delete;
  std::int32_t operator()(Tag) {
    return 42;
  }
};

class Sink final {
public:
  template<class... Args> void operator()(Args &&...) const {
  }
};

/**
 * @brief function with result type matches template type.
 *
 * @tparam t_type
 * @return t_type
 */
template<typename t_type> t_type Return();

} // namespace test_metaprogramming_type_relations_helper

TEST(metaprogramming_type_relations, is_invocable) {
  static_cast<void>(test_info_);

  /**
   * @brief Test type.
   *
   */
  using AbominableFunc = void(...) const;

  /**
   * @brief Alias.
   *
   */
  using char_t = char;

  /**
   * @brief Alias.
   *
   */
  using Tag = test_metaprogramming_type_relations_helper::Tag;

  /**
   * @brief Alias.
   *
   */
  using DerFromTag = test_metaprogramming_type_relations_helper::DerFromTag;

  /**
   * @brief Alias.
   *
   */
  using Implicit = test_metaprogramming_type_relations_helper::Implicit;

  /**
   * @brief Alias.
   *
   */
  using Explicit = test_metaprogramming_type_relations_helper::Explicit;

  /**
   * @brief Alias.
   *
   */
  using NotCallableWithInt = test_metaprogramming_type_relations_helper::NotCallableWithInt;

  /**
   * @brief Alias.
   *
   */
  using Sink = test_metaprogramming_type_relations_helper::Sink;

  //  Non-callable things
  {
    EXPECT_FALSE((::portable_stl::is_invocable<void>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<void const>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<void volatile>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<void const volatile>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<std::nullptr_t>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<std::int32_t>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<double>{}()));

    EXPECT_FALSE((::portable_stl::is_invocable<std::int32_t[]>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<std::int32_t[3]>{}()));

    EXPECT_FALSE((::portable_stl::is_invocable<std::int32_t const *>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<std::int32_t *>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<std::int32_t const *>{}()));

    EXPECT_FALSE((::portable_stl::is_invocable<std::int32_t &>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<std::int32_t const &>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<std::int32_t &&>{}()));

    EXPECT_FALSE((::portable_stl::is_invocable<std::vector<std::int32_t>>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<std::vector<std::int32_t *>>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<std::vector<std::int32_t **>>{}()));

    EXPECT_FALSE((::portable_stl::is_invocable<AbominableFunc>{}()));

    //  with parameters
    EXPECT_FALSE((::portable_stl::is_invocable<std::int32_t, std::int32_t>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<std::int32_t, double, float>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<std::int32_t, char_t, float, double>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<Sink, AbominableFunc>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<Sink, void>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable<Sink, void const volatile>{}()));

    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, void>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, void const>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, void volatile>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, void const volatile>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, std::nullptr_t>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, std::int32_t>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, double>{}()));

    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, std::int32_t[]>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, std::int32_t[3]>{}()));

    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, std::int32_t *>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, std::int32_t const *>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, std::int32_t const *>{}()));

    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, std::int32_t &>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, std::int32_t const &>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, std::int32_t &&>{}()));

    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, std::vector<std::int32_t>>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, std::vector<std::int32_t *>>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, std::vector<std::int32_t **>>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<void, AbominableFunc>{}()));

    //  with parameters
    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, std::int32_t, std::int32_t>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, std::int32_t, double, float>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<std::int32_t, std::int32_t, char_t, float, double>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<void, Sink, AbominableFunc>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<void, Sink, void>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<void, Sink, void const volatile>{}()));
  }

  // INVOKE bullet 1, 2 and 3
  {
    /**
     * @brief Alias.
     *
     */
    using Fn  = std::int32_t (Tag::*)(std::int32_t);
    /**
     * @brief Alias.
     *
     */
    using RFn = std::int32_t (Tag::*)(std::int32_t) &&;

    // Bullet 1
    {
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, Tag &, std::int32_t>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, DerFromTag &, std::int32_t>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<RFn, Tag &&, std::int32_t>{}()));
      EXPECT_FALSE((::portable_stl::is_invocable<RFn, Tag &, std::int32_t>{}()));
      EXPECT_FALSE((::portable_stl::is_invocable<Fn, Tag &>{}()));
      EXPECT_FALSE((::portable_stl::is_invocable<Fn, Tag const &, std::int32_t>{}()));
    }

    // Bullet 2
    {
      /**
       * @brief Alias.
       *
       */
      using T  = ::portable_stl::reference_wrapper<Tag>;
      /**
       * @brief Alias.
       *
       */
      using DT = ::portable_stl::reference_wrapper<DerFromTag>;
      /**
       * @brief Alias.
       *
       */
      using CT = ::portable_stl::reference_wrapper<Tag const>;

      EXPECT_TRUE((::portable_stl::is_invocable<Fn, T &, std::int32_t>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, DT &, std::int32_t>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, T const &, std::int32_t>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, T &&, std::int32_t>{}()));
      EXPECT_FALSE((::portable_stl::is_invocable<Fn, CT &, std::int32_t>{}()));
      EXPECT_FALSE((::portable_stl::is_invocable<RFn, T, std::int32_t>{}()));
    }

    // Bullet 3
    {
      /**
       * @brief Alias.
       *
       */
      using T  = Tag *;
      /**
       * @brief Alias.
       *
       */
      using DT = DerFromTag *;
      /**
       * @brief Alias.
       *
       */
      using CT = Tag const *;
      /**
       * @brief Alias.
       *
       */
      using ST = std::unique_ptr<Tag>;

      EXPECT_TRUE((::portable_stl::is_invocable<Fn, T &, std::int32_t>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, DT &, std::int32_t>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, T const &, std::int32_t>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, T &&, std::int32_t>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, ST, std::int32_t>{}()));
      EXPECT_FALSE((::portable_stl::is_invocable<Fn, CT &, std::int32_t>{}()));
      EXPECT_FALSE((::portable_stl::is_invocable<RFn, T, std::int32_t>{}()));
    }
  }

  // Bullets 4, 5 and 6
  {
    /**
     * @brief Alias.
     *
     */
    using Fn = std::int32_t(Tag::*);

    EXPECT_FALSE((::portable_stl::is_invocable<Fn>{}()));

    // Bullet 4
    {
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, Tag &>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, DerFromTag &>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, Tag &&>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, Tag const &>{}()));
    }

    // Bullet 5
    {
      /**
       * @brief Alias.
       *
       */
      using T  = ::portable_stl::reference_wrapper<Tag>;
      /**
       * @brief Alias.
       *
       */
      using DT = ::portable_stl::reference_wrapper<DerFromTag>;
      /**
       * @brief Alias.
       *
       */
      using CT = ::portable_stl::reference_wrapper<Tag const>;

      EXPECT_TRUE((::portable_stl::is_invocable<Fn, T &>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, DT &>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, T const &>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, T &&>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, CT &>{}()));
    }

    // Bullet 6
    {
      /**
       * @brief Alias.
       *
       */
      using T  = Tag *;
      /**
       * @brief Alias.
       *
       */
      using DT = DerFromTag *;
      /**
       * @brief Alias.
       *
       */
      using CT = Tag const *;
      /**
       * @brief Alias.
       *
       */
      using ST = std::unique_ptr<Tag>;

      EXPECT_TRUE((::portable_stl::is_invocable<Fn, T &>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, DT &>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, T const &>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, T &&>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, ST>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fn, CT &>{}()));
    }
  }

  // INVOKE bullet 7
  {
    // Function pointer
    {
      /**
       * @brief Alias.
       *
       */
      using Fp = void (*)(Tag &, std::int32_t);

      EXPECT_TRUE((::portable_stl::is_invocable<Fp, Tag &, std::int32_t>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fp, DerFromTag &, std::int32_t>{}()));
      EXPECT_FALSE((::portable_stl::is_invocable<Fp, Tag const &, std::int32_t>{}()));
      EXPECT_FALSE((::portable_stl::is_invocable<Fp>{}()));
      EXPECT_FALSE((::portable_stl::is_invocable<Fp, Tag &>{}()));
    }

    // Function reference
    {
      /**
       * @brief Alias.
       *
       */
      using Fp = void (&)(Tag &, std::int32_t);

      EXPECT_TRUE((::portable_stl::is_invocable<Fp, Tag &, std::int32_t>{}()));
      EXPECT_TRUE((::portable_stl::is_invocable<Fp, DerFromTag &, std::int32_t>{}()));
      EXPECT_FALSE((::portable_stl::is_invocable<Fp, Tag const &, std::int32_t>{}()));
      EXPECT_FALSE((::portable_stl::is_invocable<Fp>{}()));
      EXPECT_FALSE((::portable_stl::is_invocable<Fp, Tag &>{}()));
    }

    // Function object
    {
      /**
       * @brief Alias.
       *
       */
      using Fn = NotCallableWithInt;

      EXPECT_TRUE((::portable_stl::is_invocable<Fn, Tag>{}()));
      EXPECT_FALSE((::portable_stl::is_invocable<Fn, std::int32_t>{}()));
    }
  }

  // Check that the conversion to the return type is properly checked
  {
    /**
     * @brief Alias.
     *
     */
    using Fn = std::int32_t (*)();

    EXPECT_TRUE((::portable_stl::is_invocable_r<Implicit, Fn>{}()));
    EXPECT_TRUE((::portable_stl::is_invocable_r<double, Fn>{}()));
    EXPECT_TRUE((::portable_stl::is_invocable_r<void const volatile, Fn>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<Explicit, Fn>{}()));
  }

  test_metaprogramming_type_relations::metaprogramming_type_relations_is_invocable_inline_variables();
}

TEST(metaprogramming_type_relations, is_invocabl_r) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   *
   */
  using char_t = char;

  // Non-invocable types
  {
    EXPECT_FALSE((::portable_stl::is_invocable_r<void, void>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<void, std::int32_t>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<void, std::int32_t *>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<void, std::int32_t &>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<void, std::int32_t &&>{}()));
  }

  // Result type matches
  {
    EXPECT_TRUE(
      (::portable_stl::is_invocable_r<std::int32_t,
                                      decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t>)>{}()));
    EXPECT_TRUE(
      (::portable_stl::is_invocable_r<char_t,
                                      decltype(test_metaprogramming_type_relations_helper::Return<char_t>)>{}()));
    EXPECT_TRUE((::portable_stl::is_invocable_r<
                 std::int32_t *,
                 decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t *>)>{}()));
    EXPECT_TRUE((::portable_stl::is_invocable_r<
                 std::int32_t &,
                 decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t &>)>{}()));
    EXPECT_TRUE((::portable_stl::is_invocable_r<
                 std::int32_t &&,
                 decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t &&>)>{}()));
  }

  // void result type
  {
    // Any actual return type should be useable with a result type of void.
    EXPECT_TRUE(
      (::portable_stl::is_invocable_r<void, decltype(test_metaprogramming_type_relations_helper::Return<void>)>{}()));
    EXPECT_TRUE(
      (::portable_stl::is_invocable_r<void,
                                      decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t>)>{}()));
    EXPECT_TRUE(
      (::portable_stl::
         is_invocable_r<void, decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t *>)>{}()));
    EXPECT_TRUE(
      (::portable_stl::
         is_invocable_r<void, decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t &>)>{}()));
    EXPECT_TRUE(
      (::portable_stl::
         is_invocable_r<void, decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t &&>)>{}()));

    // const- and volatile-qualified void should work too.
    EXPECT_TRUE(
      (::portable_stl::is_invocable_r<void const,
                                      decltype(test_metaprogramming_type_relations_helper::Return<void>)>{}()));
    EXPECT_TRUE(
      (::portable_stl::is_invocable_r<void const,
                                      decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t>)>{}()));
    EXPECT_TRUE(
      (::portable_stl::is_invocable_r<void volatile,
                                      decltype(test_metaprogramming_type_relations_helper::Return<void>)>{}()));
    EXPECT_TRUE(
      (::portable_stl::is_invocable_r<void volatile,
                                      decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t>)>{}()));
    EXPECT_TRUE(
      (::portable_stl::is_invocable_r<void const volatile,
                                      decltype(test_metaprogramming_type_relations_helper::Return<void>)>{}()));
    EXPECT_TRUE(
      (::portable_stl::is_invocable_r<void const volatile,
                                      decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t>)>{}()));
  }

  // Conversion of result type
  {
    // It should be possible to use a result type to which the actual return type can be converted.
    EXPECT_TRUE(
      (::portable_stl::is_invocable_r<char,
                                      decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t>)>{}()));
    EXPECT_TRUE((::portable_stl::is_invocable_r<
                 std::int32_t const *,
                 decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t *>)>{}()));
    EXPECT_TRUE(
      (::portable_stl::
         is_invocable_r<void *, decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t *>)>{}()));
    EXPECT_TRUE(
      (::portable_stl::is_invocable_r<std::int32_t const &,
                                      decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t>)>{}()));
    EXPECT_TRUE((::portable_stl::is_invocable_r<
                 std::int32_t const &,
                 decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t &>)>{}()));
    EXPECT_TRUE((::portable_stl::is_invocable_r<
                 std::int32_t const &,
                 decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t &&>)>{}()));
    EXPECT_TRUE(
      (::portable_stl::is_invocable_r<char const &,
                                      decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t>)>{}()));

    // But not a result type where the conversion doesn't work.
    EXPECT_FALSE(
      (::portable_stl::is_invocable_r<std::int32_t,
                                      decltype(test_metaprogramming_type_relations_helper::Return<void>)>{}()));
    EXPECT_FALSE((::portable_stl::is_invocable_r<
                  std::int32_t,
                  decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t *>)>{}()));
  }

  // The struct form should be available too, not just the _v variant.
  {
    EXPECT_TRUE(
      (::portable_stl::is_invocable_r<std::int32_t,
                                      decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t>)>{}()));
    EXPECT_FALSE(
      (::portable_stl::is_invocable_r<std::int32_t *,
                                      decltype(test_metaprogramming_type_relations_helper::Return<std::int32_t>)>{}()));
  }

  test_metaprogramming_type_relations::metaprogramming_type_relations_is_invocable_r_inline_variables();
}
