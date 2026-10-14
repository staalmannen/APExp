// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="memory.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <array>
#include <functional>

#include "portable_stl/memory/addressof.h"
#include "portable_stl/memory/compressed_pair.h"
#include "portable_stl/memory/construct_at.h"
#include "portable_stl/memory/default_delete.h"
#include "portable_stl/memory/destroy_at.h"
#include "portable_stl/memory/file_descriptor_as_pointer.h"
#include "portable_stl/memory/make_unique.h"
#include "portable_stl/memory/storage_for.h"
#include "portable_stl/memory/unique_ptr.h"
#include "portable_stl/memory/voidify.h"
#include "portable_stl/ranges/construct_at.h"
#include "portable_stl/ranges/destroy_at.h"

TEST(memory, addressof) {
  static_cast<void>(test_info_);
  std::int32_t value{0};
  ASSERT_EQ(&value, ::portable_stl::addressof(value));
}

TEST(memory, voidify) {
  static_cast<void>(test_info_);
  std::int32_t value{0};
  ASSERT_TRUE((std::is_same<void *, decltype(::portable_stl::voidify(value))>{}));
  ASSERT_EQ(0, value);
}

TEST(memory, storage_for) {
  static_cast<void>(test_info_);
  std::int32_t value{0};
  ASSERT_TRUE((std::is_same<std::uint8_t *, decltype(&::portable_stl::storage_for<std::uint8_t>(value))>{}));
  ASSERT_EQ(0, value);
}

namespace memory_tests_helper {
/**
 * @brief Helper variable for check constructor calls.
 */
static std::uint32_t ctor_call{0U};
/**
 * @brief Helper variable for check destructor calls.
 *
 */
static std::uint32_t dtor_call{0U};

/**
 * @brief Helper class for checl call's constructor and destructor.
 *
 */
class construct_destruct_checker final {
public:
  /**
   * @brief Destructor call checker.
   *
   */
  ~construct_destruct_checker() noexcept {
    ++dtor_call;
  }
  /**
   * @brief Constructor call checker.
   *
   */
  construct_destruct_checker() noexcept {
    ++ctor_call;
  }

  /**
   * @brief Copy constructor
   */
  construct_destruct_checker(construct_destruct_checker const &) noexcept            = delete;
  /**
   * @brief Move constructor
   */
  construct_destruct_checker(construct_destruct_checker &&) noexcept                 = delete;
  /**
   * @brief Copy assignment operator.
   * @return reference to this.
   */
  construct_destruct_checker &operator=(construct_destruct_checker const &) noexcept = delete;
  /**
   * @brief Move assignment operator.
   * @return reference to this.
   */
  construct_destruct_checker &operator=(construct_destruct_checker &&) noexcept      = delete;
};
} // namespace memory_tests_helper

TEST(memory, construct_at) {
  static_cast<void>(test_info_);
  alignas(alignof(memory_tests_helper::construct_destruct_checker))
    std::array<std::uint8_t, sizeof(memory_tests_helper::construct_destruct_checker)>
      storage{0U};

  memory_tests_helper::ctor_call = 0U;
  static_cast<void>(::portable_stl::construct_at(&
    ::portable_stl::storage_for<memory_tests_helper::construct_destruct_checker>(*storage.data())));
  ASSERT_EQ(memory_tests_helper::ctor_call, 1U);

  memory_tests_helper::ctor_call = 0U;
  static_cast<void>(::portable_stl::ranges::construct_at(&
    ::portable_stl::storage_for<memory_tests_helper::construct_destruct_checker>(*storage.data())));

  ASSERT_EQ(memory_tests_helper::ctor_call, 1U);
}

TEST(memory, destroy_at) {
  static_cast<void>(test_info_);

  // std::reverse_iterator<std::int32_t *> a;

  alignas(alignof(memory_tests_helper::construct_destruct_checker))
    std::array<std::uint8_t, sizeof(memory_tests_helper::construct_destruct_checker)>
      storage{0U};

  memory_tests_helper::ctor_call = 0U;
  memory_tests_helper::dtor_call = 0U;
  static_cast<void>(::portable_stl::construct_at(&
    ::portable_stl::storage_for<memory_tests_helper::construct_destruct_checker>(*storage.data())));
  ASSERT_EQ(memory_tests_helper::ctor_call, 1U);
  ::portable_stl::destroy_at(&
    ::portable_stl::storage_for<memory_tests_helper::construct_destruct_checker>(*storage.data()));
  ASSERT_EQ(memory_tests_helper::dtor_call, 1U);

  memory_tests_helper::ctor_call = 0U;
  memory_tests_helper::dtor_call = 0U;

  static_cast<void>(::portable_stl::ranges::construct_at(&
    ::portable_stl::storage_for<memory_tests_helper::construct_destruct_checker>(*storage.data())));
  ASSERT_EQ(memory_tests_helper::ctor_call, 1U);
  ::portable_stl::ranges::destroy_at(&
    ::portable_stl::storage_for<memory_tests_helper::construct_destruct_checker>(*storage.data()));
  ASSERT_EQ(memory_tests_helper::dtor_call, 1U);
}

TEST(memory, exception_pack) {
  static_cast<void>(test_info_);

  auto success_void = []() -> void {
    return;
  };
  auto fail_void = []() -> void {
    throw std::bad_exception{};
  };
  auto success_int = []() -> std::int32_t {
    return 0;
  };
  auto fail_int = []() -> std::int32_t {
    throw std::bad_exception{};
  };

  {
    ASSERT_NO_THROW((success_void()));
    ASSERT_THROW(fail_void(), std::bad_exception);
  }
  {
    ASSERT_NO_THROW((success_int()));
    ASSERT_EQ(0, success_int());
    ASSERT_THROW(fail_int(), std::bad_exception);
  }
  constexpr ::portable_stl::exception_pack<std::uint32_t, 0U> checker{};
  {
    ASSERT_TRUE(checker(success_void).has_value());
    ASSERT_FALSE(checker(fail_void).has_value());
    ASSERT_EQ(0U, checker(fail_void).error());
  }
  {
    ASSERT_TRUE(checker(success_int).has_value());
    ASSERT_EQ(0U, *checker(success_int));
    ASSERT_FALSE(checker(fail_int).has_value());
    ASSERT_EQ(0U, checker(fail_int).error());
  }
}

TEST(memory, default_delete) {
  static_cast<void>(test_info_);

  {
    memory_tests_helper::ctor_call = 0U;
    memory_tests_helper::dtor_call = 0U;

    auto const checker(std::make_unique<memory_tests_helper::construct_destruct_checker>().release());
    ASSERT_EQ(memory_tests_helper::ctor_call, 1U);
    ASSERT_EQ(memory_tests_helper::dtor_call, 0U);
    auto result(::portable_stl::default_delete<memory_tests_helper::construct_destruct_checker>{
      ::portable_stl::default_delete<std::uint32_t>{}}(checker));
    ASSERT_EQ(memory_tests_helper::ctor_call, 1U);
    ASSERT_EQ(memory_tests_helper::dtor_call, 1U);
    ASSERT_TRUE(result.has_value());
  }
  {
    constexpr std::uint32_t ctor_dtor_calls_count{2U};
    memory_tests_helper::ctor_call = 0U;
    memory_tests_helper::dtor_call = 0U;

    auto const checker(
      std::make_unique<memory_tests_helper::construct_destruct_checker[]>(ctor_dtor_calls_count).release());
    ASSERT_EQ(memory_tests_helper::ctor_call, ctor_dtor_calls_count);
    ASSERT_EQ(memory_tests_helper::dtor_call, 0U);
    auto result(::portable_stl::default_delete<memory_tests_helper::construct_destruct_checker[]>{
      ::portable_stl::default_delete<std::uint32_t[]>{}}(checker));
    ASSERT_EQ(memory_tests_helper::ctor_call, ctor_dtor_calls_count);
    ASSERT_EQ(memory_tests_helper::dtor_call, ctor_dtor_calls_count);
    ASSERT_TRUE(result.has_value());
  }
}

namespace memory_tests_helper {
/**
 * @brief Helper object for check compressed pair.
 *
 */
template<class t_value> class empty_class {
public:
  /**
   * @brief Destroy the empty class object.
   *
   */
  ~empty_class() noexcept                                = default;
  /**
   * @brief Construct the empty class object.
   *
   */
  constexpr empty_class() noexcept                       = default;
  /**
   * @brief Construct the empty class object.
   *
   */
  constexpr empty_class(empty_class const &) noexcept    = default;
  /**
   * @brief Construct the empty class object.
   *
   */
  constexpr empty_class(empty_class &&) noexcept         = default;
  /**
   * @brief Assign the empty class object.
   *
   */
  empty_class &operator=(empty_class const &) & noexcept = default;
  /**
   * @brief Assign the empty class object.
   *
   */
  empty_class &operator=(empty_class &&) & noexcept      = default;
};
/**
 * @brief Helper object for check compressed pair.
 *
 */
template<class t_value> class empty_class_final final {
public:
  /**
   * @brief Destroy the empty class object.
   *
   */
  ~empty_class_final() noexcept          = default;
  /**
   * @brief Construct the empty class object.
   *
   */
  constexpr empty_class_final() noexcept = default;

  /**
   * @brief Construct the empty class object.
   *
   */
  constexpr empty_class_final(std::int32_t, std::int32_t) noexcept {}

  /**
   * @brief Construct the empty class object.
   *
   */
  constexpr empty_class_final(empty_class_final const &) noexcept    = default;
  /**
   * @brief Construct the empty class object.
   *
   */
  constexpr empty_class_final(empty_class_final &&) noexcept         = default;
  /**
   * @brief Assign the empty class object.
   *
   */
  empty_class_final &operator=(empty_class_final const &) & noexcept = default;
  /**
   * @brief Assign the empty class object.
   *
   */
  empty_class_final &operator=(empty_class_final &&) & noexcept      = default;
};
} // namespace memory_tests_helper

TEST(memory, compressed_pair) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::compressed_pair<std::int32_t, std::uint32_t> checker{0, 0U};
    ASSERT_EQ(sizeof(std::int32_t) + sizeof(std::uint32_t), sizeof(checker));
    ASSERT_EQ(0, checker.get_first());
  }
  {
    ::portable_stl::compressed_pair<std::int32_t, memory_tests_helper::empty_class<std::int32_t>> checker{0};
    ASSERT_EQ(sizeof(std::int32_t), sizeof(checker));
    ASSERT_EQ(0, checker.get_first());
  }
  {
    ::portable_stl::compressed_pair<memory_tests_helper::empty_class<std::int32_t>, std::int32_t> checker{0};
    ASSERT_EQ(sizeof(std::int32_t), sizeof(checker));
    ASSERT_EQ(0, checker.get_second());
  }
  {
    ::portable_stl::compressed_pair<memory_tests_helper::empty_class<std::int32_t>,
                                    memory_tests_helper::empty_class<std::uint32_t>>
      checker{};
    static_cast<void>(checker);
    ASSERT_EQ(1U, sizeof(checker));
  }
  {
    memory_tests_helper::empty_class_final<std::int32_t> check{};
    static_cast<void>(check);
    check = memory_tests_helper::empty_class_final<std::int32_t>{};
    static_cast<void>(check);
    check = memory_tests_helper::empty_class_final<std::int32_t>{0, 0};
    static_cast<void>(check);
  }
  {
    ::portable_stl::compressed_pair<std::int32_t, memory_tests_helper::empty_class_final<std::int32_t>> checker{0};
    ASSERT_EQ((sizeof(std::int32_t)
               + std::max(alignof(std::int32_t), sizeof(memory_tests_helper::empty_class_final<std::int32_t>))),
              sizeof(checker));
    ASSERT_EQ(0, checker.get_first());
  }
  {
    ::portable_stl::compressed_pair<memory_tests_helper::empty_class_final<std::int32_t>, std::int32_t> checker{0};
    ASSERT_EQ((sizeof(std::int32_t)
               + std::max(alignof(std::int32_t), sizeof(memory_tests_helper::empty_class_final<std::int32_t>))),
              sizeof(checker));
    ASSERT_EQ(0, checker.get_second());
  }
  {
    ::portable_stl::compressed_pair<memory_tests_helper::empty_class_final<std::int32_t>,
                                    memory_tests_helper::empty_class_final<std::uint32_t>>
      checker{};
    static_cast<void>(checker);
    ASSERT_EQ(sizeof(memory_tests_helper::empty_class_final<std::int32_t>)
                + sizeof(memory_tests_helper::empty_class_final<std::uint32_t>),
              sizeof(checker));
  }
}

namespace memory_tests_helper {
/**
 * @brief Helper structure for check smart pointer.
 *
 */
class simple_structure final {
  /**
   * @brief Inner value.
   *
   */
  std::int32_t m_value;

public:
  /**
   * @brief Constructor.
   */
  constexpr explicit simple_structure() noexcept : simple_structure(0) {
  }
  /**
   * @brief Constructor.
   * @param value the value for initialize.
   */
  constexpr explicit simple_structure(std::int32_t const value) noexcept : m_value(value) {
  }
  /**
   * @brief Value getter.
   *
   * @return
   */
  constexpr std::int32_t get() const noexcept {
    return m_value;
  }
};
} // namespace memory_tests_helper

TEST(memory, unique_ptr) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::unique_ptr<std::int32_t> checker{};
    ASSERT_FALSE((checker));
    ASSERT_EQ(nullptr, checker.get());
  }

  {
    ::portable_stl::unique_ptr<std::int32_t> checker{nullptr};
    ASSERT_FALSE((checker));
    ASSERT_EQ(nullptr, checker.get());
  }

  {
    auto *const ptr(std::make_unique<std::int32_t>().release());

    ::portable_stl::unique_ptr<std::int32_t> checker{ptr};
    ASSERT_TRUE((checker));
    ASSERT_EQ(ptr, checker.get());
    ASSERT_EQ(0, (*checker));

    ASSERT_TRUE((checker.reset()));

    ASSERT_FALSE((checker));
    ASSERT_EQ(nullptr, checker.get());
  }

  {
    auto *const ptr(std::make_unique<memory_tests_helper::simple_structure>(0).release());

    ::portable_stl::unique_ptr<memory_tests_helper::simple_structure> checker{ptr};
    ASSERT_TRUE((checker));
    ASSERT_EQ(0, (checker->get()));
  }

  {
    auto *const ptr(std::make_unique<std::int32_t>().release());

    ::portable_stl::unique_ptr<std::int32_t> checker{ptr};
    ASSERT_TRUE((checker));
    ASSERT_EQ(ptr, checker.get());
    ASSERT_EQ(0, (*checker));

    std::unique_ptr<std::int32_t> std_checker{checker.release()};
    ASSERT_TRUE((std_checker));

    ASSERT_FALSE((checker));
    ASSERT_EQ(nullptr, checker.get());
  }
  {
    auto *const ptr(std::make_unique<std::int32_t>().release());

    ::portable_stl::unique_ptr<std::int32_t> checker{ptr};
    ASSERT_TRUE((checker));
    ASSERT_EQ(ptr, checker.get());
    ASSERT_EQ(0, (*checker));

    checker = ::portable_stl::unique_ptr<std::int32_t>{std::make_unique<std::int32_t>(1).release()};

    ASSERT_TRUE((checker));
    ASSERT_EQ(1, (*checker));
  }
  {
    auto *const ptr(std::make_unique<std::int32_t>().release());

    ::portable_stl::unique_ptr<std::int32_t const> checker{ptr};
    ASSERT_TRUE((checker));
    ASSERT_EQ(ptr, checker.get());
    ASSERT_EQ(0, (*checker));

    checker = ::portable_stl::unique_ptr<std::int32_t>{std::make_unique<std::int32_t>(1).release()};

    ASSERT_TRUE((checker));
    ASSERT_EQ(1, (*checker));
  }
  {
    auto *const ptr(std::make_unique<std::int32_t>().release());

    ::portable_stl::unique_ptr<std::int32_t> checker{ptr};
    ASSERT_TRUE((checker));
    ASSERT_EQ(ptr, checker.get());
    ASSERT_EQ(0, (*checker));

    checker = nullptr;

    ASSERT_FALSE((checker));
    ASSERT_EQ(nullptr, checker.get());
  }
  {
    auto *const ptr(std::make_unique<std::int32_t>().release());

    ::portable_stl::unique_ptr<std::int32_t> checker{ptr, ::portable_stl::default_delete<std::int32_t>{}};
    ASSERT_TRUE((checker));
    ASSERT_EQ(ptr, checker.get());
    ASSERT_EQ(0, (*checker));

    checker = nullptr;

    ASSERT_FALSE((checker));
    ASSERT_EQ(nullptr, checker.get());

    static_cast<void>(checker.get_deleter());
    static_cast<void>(const_cast<::portable_stl::unique_ptr<std::int32_t> const &>(checker).get_deleter());
  }
  {
    ::portable_stl::default_delete<std::int32_t> const deleter{};

    auto *const ptr(std::make_unique<std::int32_t>().release());

    ::portable_stl::unique_ptr<std::int32_t> checker{ptr, deleter};
    ASSERT_TRUE((checker));
    ASSERT_EQ(ptr, checker.get());
    ASSERT_EQ(0, (*checker));

    checker = nullptr;

    ASSERT_FALSE((checker));
    ASSERT_EQ(nullptr, checker.get());
  }
  {
    auto *const ptr(std::make_unique<std::int32_t>().release());

    ::portable_stl::unique_ptr<std::int32_t> checker_a{ptr};
    ::portable_stl::unique_ptr<std::int32_t> checker_b{nullptr};

    ASSERT_TRUE((checker_a));
    ASSERT_EQ(ptr, checker_a.get());
    ASSERT_EQ(0, (*checker_a));

    ASSERT_FALSE((checker_b));
    ASSERT_EQ(nullptr, checker_b.get());

    checker_a.local_swap(checker_b);

    ASSERT_FALSE((checker_a));
    ASSERT_EQ(nullptr, checker_a.get());

    ASSERT_TRUE((checker_b));
    ASSERT_EQ(ptr, checker_b.get());
    ASSERT_EQ(0, (*checker_b));
  }

  {
    auto *const ptr(std::make_unique<std::int32_t>().release());

    ::portable_stl::unique_ptr<std::int32_t> checker_a{ptr};
    ::portable_stl::unique_ptr<std::int32_t> checker_b{nullptr};

    ASSERT_TRUE((checker_a));
    ASSERT_EQ(ptr, checker_a.get());
    ASSERT_EQ(0, (*checker_a));

    ASSERT_FALSE((checker_b));
    ASSERT_EQ(nullptr, checker_b.get());

    ::portable_stl::swap(checker_a, checker_b);

    ASSERT_FALSE((checker_a));
    ASSERT_EQ(nullptr, checker_a.get());

    ASSERT_TRUE((checker_b));
    ASSERT_EQ(ptr, checker_b.get());
    ASSERT_EQ(0, (*checker_b));
  }
}

TEST(memory, unique_ptr_array) {
  static_cast<void>(test_info_);
  constexpr std::size_t array_size{5U};
  {
    ::portable_stl::unique_ptr<std::int32_t[]> checker{};
    ASSERT_FALSE((checker));
    ASSERT_EQ(nullptr, checker.get());
  }

  {
    ::portable_stl::unique_ptr<std::int32_t[]> checker{nullptr};
    ASSERT_FALSE((checker));
    ASSERT_EQ(nullptr, checker.get());
  }

  {
    auto *const ptr(std::make_unique<std::int32_t[]>(array_size).release());

    ::portable_stl::unique_ptr<std::int32_t[]> checker{ptr};
    ASSERT_TRUE((checker));
    ASSERT_EQ(ptr, checker.get());
    ASSERT_EQ(0, (*checker));

    ASSERT_TRUE((checker.reset()));

    ASSERT_FALSE((checker));
    ASSERT_EQ(nullptr, checker.get());
  }

  {
    auto *const ptr(std::make_unique<memory_tests_helper::simple_structure[]>(1U).release());

    ::portable_stl::unique_ptr<memory_tests_helper::simple_structure[]> checker{ptr};
    ASSERT_TRUE((checker));
    ASSERT_EQ(0, (checker->get()));
  }

  {
    auto *const ptr(std::make_unique<std::int32_t[]>(array_size).release());

    ::portable_stl::unique_ptr<std::int32_t[]> checker{ptr};
    ASSERT_TRUE((checker));
    ASSERT_EQ(ptr, checker.get());
    ASSERT_EQ(0, (*checker));

    std::unique_ptr<std::int32_t[]> std_checker{checker.release()};
    ASSERT_TRUE((std_checker));

    ASSERT_FALSE((checker));
    ASSERT_EQ(nullptr, checker.get());
  }
  {
    auto *const ptr(std::make_unique<std::int32_t[]>(array_size).release());

    ::portable_stl::unique_ptr<std::int32_t[]> checker{ptr};
    ASSERT_TRUE((checker));
    ASSERT_EQ(ptr, checker.get());
    ASSERT_EQ(0, (*checker));

    checker = ::portable_stl::unique_ptr<std::int32_t[]>{std::make_unique<std::int32_t[]>(1U).release()};

    ASSERT_TRUE((checker));
    ASSERT_EQ(0, (*checker));
  }
  {
    auto *const ptr(std::make_unique<std::int32_t[]>(array_size).release());

    ::portable_stl::unique_ptr<std::int32_t const[]> checker{ptr};
    ASSERT_TRUE((checker));
    ASSERT_EQ(ptr, checker.get());
    ASSERT_EQ(0, (*checker));

    checker = ::portable_stl::unique_ptr<std::int32_t[]>{std::make_unique<std::int32_t[]>(1U).release()};

    ASSERT_TRUE((checker));
    ASSERT_EQ(0, (*checker));
  }
  {
    auto *const ptr(std::make_unique<std::int32_t[]>(array_size).release());

    ::portable_stl::unique_ptr<std::int32_t[]> checker{ptr};
    ASSERT_TRUE((checker));
    ASSERT_EQ(ptr, checker.get());
    ASSERT_EQ(0, (*checker));

    checker = nullptr;

    ASSERT_FALSE((checker));
    ASSERT_EQ(nullptr, checker.get());
  }
  {
    auto *const ptr(std::make_unique<std::int32_t[]>(array_size).release());

    ::portable_stl::unique_ptr<std::int32_t[]> checker{ptr, ::portable_stl::default_delete<std::int32_t[]>{}};
    ASSERT_TRUE((checker));
    ASSERT_EQ(ptr, checker.get());
    ASSERT_EQ(0, (*checker));

    checker = nullptr;

    ASSERT_FALSE((checker));
    ASSERT_EQ(nullptr, checker.get());

    static_cast<void>(checker.get_deleter());
    static_cast<void>(const_cast<::portable_stl::unique_ptr<std::int32_t[]> const &>(checker).get_deleter());
  }
  {
    ::portable_stl::default_delete<std::int32_t[]> const deleter{};

    auto *const ptr(std::make_unique<std::int32_t[]>(array_size).release());

    ::portable_stl::unique_ptr<std::int32_t[]> checker{ptr, deleter};
    ASSERT_TRUE((checker));
    ASSERT_EQ(ptr, checker.get());
    ASSERT_EQ(0, (*checker));

    checker = nullptr;

    ASSERT_FALSE((checker));
    ASSERT_EQ(nullptr, checker.get());
  }
  {
    auto *const ptr(std::make_unique<std::int32_t[]>(array_size).release());

    ::portable_stl::unique_ptr<std::int32_t[]> checker_a{ptr};
    ::portable_stl::unique_ptr<std::int32_t[]> checker_b{nullptr};

    ASSERT_TRUE((checker_a));
    ASSERT_EQ(ptr, checker_a.get());
    ASSERT_EQ(0, (*checker_a));

    ASSERT_FALSE((checker_b));
    ASSERT_EQ(nullptr, checker_b.get());

    checker_a.local_swap(checker_b);

    ASSERT_FALSE((checker_a));
    ASSERT_EQ(nullptr, checker_a.get());

    ASSERT_TRUE((checker_b));
    ASSERT_EQ(ptr, checker_b.get());
    ASSERT_EQ(0, (*checker_b));
  }

  {
    auto *const ptr(std::make_unique<std::int32_t[]>(array_size).release());

    ::portable_stl::unique_ptr<std::int32_t[]> checker_a{ptr};
    ::portable_stl::unique_ptr<std::int32_t[]> checker_b{nullptr};

    ASSERT_TRUE((checker_a));
    ASSERT_EQ(ptr, checker_a.get());
    ASSERT_EQ(0, (*checker_a));

    ASSERT_FALSE((checker_b));
    ASSERT_EQ(nullptr, checker_b.get());

    ::portable_stl::swap(checker_a, checker_b);

    ASSERT_FALSE((checker_a));
    ASSERT_EQ(nullptr, checker_a.get());

    ASSERT_TRUE((checker_b));
    ASSERT_EQ(ptr, checker_b.get());
    ASSERT_EQ(0, (*checker_b));
  }
}

namespace memory_tests_helper {
/**
 * @brief Counter of call function close_check.
 *
 */
static std::int32_t        close_counter{0};
/**
 * @brief Counter of call function close_check.
 *
 */
static std::int32_t        close_counter2{0};
/**
 * @brief Helper function for check close descriptor.
 *
 * @return std::int32_t current status 0.
 */
inline static std::int32_t close_check(std::int32_t const) noexcept {
  ++close_counter;
  return 0;
}

/**
 * @brief Helper function for check close descriptor.
 */
inline static void close_check_2(std::int32_t const) noexcept {
  ++close_counter;
}

/**
 * @brief Helper function for check close descriptor.
 */
inline static void close_check_3(std::int32_t const) noexcept {
  ++close_counter2;
}

/**
 * @brief Helper deleter class for work with file_descriptor_as_pointer.
 *
 */
class file_descriptor_delete {
public:
  /**
   * @brief Set pointer type for use descriptor.
   *
   */
  using pointer                               = ::portable_stl::file_descriptor_as_pointer<std::int32_t, -1>;
  /**
   * @brief Construct deleter object.
   */
  constexpr file_descriptor_delete() noexcept = default;
  /**
   * @brief Destructor deleter object.
   */
  ~file_descriptor_delete() noexcept          = default;
  /**
   * @brief Construct deleter object.
   */
  constexpr file_descriptor_delete(file_descriptor_delete const &) noexcept    = default;
  /**
   * @brief Assign deleter object.
   */
  file_descriptor_delete &operator=(file_descriptor_delete const &) & noexcept = default;
  /**
   * @brief Construct deleter object.
   */
  constexpr file_descriptor_delete(file_descriptor_delete &&) noexcept         = default;
  /**
   * @brief Assign deleter object.
   */
  file_descriptor_delete &operator=(file_descriptor_delete &&) & noexcept      = default;

  /**
   * @brief Delete function.
   *
   * @param object the object for delete.
   */
  inline ::portable_stl::expected<void, std::int32_t> operator()(pointer const object) const noexcept {
    static_cast<void>(close_check(*object));
    return {};
  }
};

/**
 * @brief Helper deleter class for work with file_descriptor_as_pointer with runtime select closer function.
 *
 */
class file_descriptor_delete_dynamic {
  /**
   * @brief Helper type for function.
   *
   */
  using t_function = void (*)(std::int32_t);

  /**
   * @brief Pointer to the closer function.
   *
   */
  t_function m_function;

public:
  /**
   * @brief Set pointer type for use descriptor.
   *
   */
  using pointer = ::portable_stl::file_descriptor_as_pointer<std::int32_t, -1>;

  /**
   * @brief Construct a new file descriptor delete dynamic object
   *
   * @param function the function for clean.
   */
  file_descriptor_delete_dynamic(t_function function) noexcept : m_function(function) {
  }

  /**
   * @brief Delete function.
   *
   * @param object the object for delete.
   */
  inline ::portable_stl::expected<void, std::int32_t> operator()(pointer const object) const noexcept {
    m_function(*object);
    return {};
  }
};
} // namespace memory_tests_helper

TEST(memory, unique_ptr_as_unix_file_descriptor_holder) {
  static_cast<void>(test_info_);
  std::int32_t valid_descriptor{1};

  { ASSERT_EQ(0, memory_tests_helper::close_check(valid_descriptor)); }
  valid_descriptor = 0;
  {
    ::portable_stl::file_descriptor_as_pointer<std::int32_t, -1> checker{};
    ASSERT_EQ(-1, checker.operator*());
  }

  {
    ::portable_stl::file_descriptor_as_pointer<std::int32_t, -1> checker{valid_descriptor};
    ASSERT_EQ(valid_descriptor, checker.operator*());
  }

  {
    ::portable_stl::file_descriptor_as_pointer<std::int32_t, -1> checker{};
    ASSERT_EQ(-1, checker.operator*());
    checker = valid_descriptor;
    ASSERT_EQ(valid_descriptor, checker.operator*());
  }
  {
    ::portable_stl::file_descriptor_as_pointer<std::int32_t, -1> checker{valid_descriptor};
    ASSERT_EQ(valid_descriptor, checker.operator*());
    checker = ::portable_stl::file_descriptor_as_pointer<std::int32_t, -1>{};
    ASSERT_EQ(-1, checker.operator*());
  }
  {
    ::portable_stl::file_descriptor_as_pointer<std::int32_t, -1> checker_a{};
    ::portable_stl::file_descriptor_as_pointer<std::int32_t, -1> checker_b{valid_descriptor};
    ASSERT_EQ(-1, checker_a.operator*());
    ASSERT_EQ(valid_descriptor, checker_b.operator*());

    checker_a.local_swap(checker_b);

    ASSERT_EQ(-1, checker_b.operator*());
    ASSERT_EQ(valid_descriptor, checker_a.operator*());
  }
  {
    ::portable_stl::file_descriptor_as_pointer<std::int32_t, -1> checker_a{};
    ::portable_stl::file_descriptor_as_pointer<std::int32_t, -1> checker_b{valid_descriptor};
    ASSERT_EQ(-1, checker_a.operator*());
    ASSERT_EQ(valid_descriptor, checker_b.operator*());

    ::portable_stl::swap(checker_a, checker_b);

    ASSERT_EQ(-1, checker_b.operator*());
    ASSERT_EQ(valid_descriptor, checker_a.operator*());
  }
  /**
   * @brief Smart pointer for store unix file descriptor.
   *
   */
  using unix_file_descriptor_holder
    = ::portable_stl::unique_ptr<std::int32_t, memory_tests_helper::file_descriptor_delete>;

  /**
   * @brief Smart pointer for store unix file descriptor.
   *
   */
  using unix_file_descriptor_holder2
    = ::portable_stl::unique_ptr<std::int32_t, memory_tests_helper::file_descriptor_delete_dynamic>;

  {
    memory_tests_helper::close_counter = 0;
    unix_file_descriptor_holder checker{};
    ASSERT_FALSE((checker));
    ASSERT_EQ(0, memory_tests_helper::close_counter);
  }

  {
    memory_tests_helper::close_counter = 0;
    unix_file_descriptor_holder checker{nullptr};
    ASSERT_FALSE((checker));
    ASSERT_EQ(0, memory_tests_helper::close_counter);
  }
  {
    memory_tests_helper::close_counter = 0;
    unix_file_descriptor_holder checker{valid_descriptor};
    ASSERT_TRUE((checker));
    ASSERT_EQ(memory_tests_helper::file_descriptor_delete::pointer{valid_descriptor}, checker.get());
    ASSERT_EQ(valid_descriptor, (*checker));
    ASSERT_EQ(0, memory_tests_helper::close_counter);

    ASSERT_TRUE((checker.reset()));
    ASSERT_EQ(1, memory_tests_helper::close_counter);

    ASSERT_FALSE((checker));
    ASSERT_EQ(1, memory_tests_helper::close_counter);
  }

  {
    memory_tests_helper::close_counter = 0;
    unix_file_descriptor_holder2 checker{
      valid_descriptor, memory_tests_helper::file_descriptor_delete_dynamic{&memory_tests_helper::close_check_2}};
    ASSERT_TRUE((checker));
    ASSERT_EQ(memory_tests_helper::file_descriptor_delete::pointer{valid_descriptor}, checker.get());
    ASSERT_EQ(valid_descriptor, (*checker));
    ASSERT_EQ(0, memory_tests_helper::close_counter);

    ASSERT_TRUE((checker.reset()));
    ASSERT_EQ(1, memory_tests_helper::close_counter);

    ASSERT_FALSE((checker));
    ASSERT_EQ(1, memory_tests_helper::close_counter);
  }
  {
    memory_tests_helper::close_counter2 = 0;
    memory_tests_helper::file_descriptor_delete_dynamic const deleter{&memory_tests_helper::close_check_3};
    unix_file_descriptor_holder2                              checker{valid_descriptor, deleter};
    ASSERT_TRUE((checker));
    ASSERT_EQ(memory_tests_helper::file_descriptor_delete::pointer{valid_descriptor}, checker.get());
    ASSERT_EQ(valid_descriptor, (*checker));
    ASSERT_EQ(0, memory_tests_helper::close_counter2);

    ASSERT_TRUE((checker.reset()));
    ASSERT_EQ(1, memory_tests_helper::close_counter2);

    ASSERT_FALSE((checker));
    ASSERT_EQ(1, memory_tests_helper::close_counter2);
  }
  {
    memory_tests_helper::close_counter2 = 0;
    unix_file_descriptor_holder2 checker{
      valid_descriptor,
      unix_file_descriptor_holder2{valid_descriptor, &memory_tests_helper::close_check_3}
      .get_deleter()
    };
    ASSERT_TRUE((checker));
    ASSERT_EQ(memory_tests_helper::file_descriptor_delete::pointer{valid_descriptor}, checker.get());
    ASSERT_EQ(valid_descriptor, (*checker));
    ASSERT_EQ(1, memory_tests_helper::close_counter2);
    memory_tests_helper::close_counter2 = 0;

    ASSERT_TRUE((checker.reset()));
    ASSERT_EQ(1, memory_tests_helper::close_counter2);

    ASSERT_FALSE((checker));
    ASSERT_EQ(1, memory_tests_helper::close_counter2);
  }
  {
    memory_tests_helper::close_counter = 0;
    unix_file_descriptor_holder2 checker{
      valid_descriptor, memory_tests_helper::file_descriptor_delete_dynamic{&memory_tests_helper::close_check_2}};
    ASSERT_TRUE((checker));
    ASSERT_EQ(memory_tests_helper::file_descriptor_delete::pointer{valid_descriptor}, checker.get());
    ASSERT_EQ(valid_descriptor, (*checker));
    ASSERT_EQ(0, memory_tests_helper::close_counter);

    ASSERT_TRUE((checker.reset()));
    ASSERT_EQ(1, memory_tests_helper::close_counter);

    memory_tests_helper::close_counter = 0;

    ASSERT_FALSE((checker));
    ASSERT_EQ(0, memory_tests_helper::close_counter);

    unix_file_descriptor_holder2 checker2{valid_descriptor,
                                          static_cast<unix_file_descriptor_holder2 const &>(checker).get_deleter()};
    ASSERT_TRUE((checker2));
    ASSERT_EQ(memory_tests_helper::file_descriptor_delete::pointer{valid_descriptor}, checker2.get());
    ASSERT_EQ(valid_descriptor, (*checker2));
    ASSERT_EQ(0, memory_tests_helper::close_counter);
    ASSERT_TRUE((checker2.reset()));
    ASSERT_EQ(1, memory_tests_helper::close_counter);

    ASSERT_FALSE((checker2));
    ASSERT_EQ(1, memory_tests_helper::close_counter);
  }
}

TEST(memory, unique_ptr_compare) {
  static_cast<void>(test_info_);
  /**
   * @brief Smart pointer for compare check.
   *
   */
  using compare_unique_ptr = ::portable_stl::unique_ptr<std::int32_t, memory_tests_helper::file_descriptor_delete>;

  constexpr std::int32_t value_c{-1};
  constexpr std::int32_t value_a{24};
  constexpr std::int32_t value_b{42};

  {
    auto check_eq(compare_unique_ptr{value_a} == compare_unique_ptr{value_a});
    ASSERT_TRUE(check_eq);
  }
  {
    auto check_ne(compare_unique_ptr{value_a} != compare_unique_ptr{value_b});
    ASSERT_TRUE(check_ne);
  }
  {
    auto check_lt(compare_unique_ptr{value_a} < compare_unique_ptr{value_b});
    ASSERT_TRUE(check_lt);
  }
  {
    auto check_gt(compare_unique_ptr{value_b} > compare_unique_ptr{value_a});
    ASSERT_TRUE(check_gt);
  }
  {
    auto check_le(compare_unique_ptr{value_a} <= compare_unique_ptr{value_b});
    ASSERT_TRUE(check_le);
  }
  {
    auto check_ge(compare_unique_ptr{value_b} >= compare_unique_ptr{value_a});
    ASSERT_TRUE(check_ge);
  }
  {
    auto check_eq(compare_unique_ptr{value_c} == nullptr);
    ASSERT_TRUE(check_eq);
  }
  {
    auto check_ne(compare_unique_ptr{value_a} != nullptr);
    ASSERT_TRUE(check_ne);
  }
  {
    auto check_lt(compare_unique_ptr{value_a} < nullptr);
    ASSERT_FALSE(check_lt);
  }
  {
    auto check_gt(compare_unique_ptr{value_a} > nullptr);
    ASSERT_TRUE(check_gt);
  }
  {
    auto check_le(compare_unique_ptr{value_c} <= nullptr);
    ASSERT_TRUE(check_le);
  }
  {
    auto check_ge(compare_unique_ptr{value_c} >= nullptr);
    ASSERT_TRUE(check_ge);
  }
  {
    auto check_eq(nullptr == compare_unique_ptr{value_c});
    ASSERT_TRUE(check_eq);
  }
  {
    auto check_ne(nullptr != compare_unique_ptr{value_a});
    ASSERT_TRUE(check_ne);
  }
  {
    auto check_lt(nullptr < compare_unique_ptr{value_a});
    ASSERT_TRUE(check_lt);
  }
  {
    auto check_gt(nullptr > compare_unique_ptr{value_a});
    ASSERT_FALSE(check_gt);
  }
  {
    auto check_le(nullptr <= compare_unique_ptr{value_c});
    ASSERT_TRUE(check_le);
  }
  {
    auto check_ge(nullptr >= compare_unique_ptr{value_c});
    ASSERT_TRUE(check_ge);
  }
}

TEST(memory, unique_ptr_make) {
  static_cast<void>(test_info_);
  {
    auto pointer(::portable_stl::make_unique<std::int32_t>(1));
    ASSERT_TRUE((pointer.operator bool()));
    ASSERT_EQ(1, *pointer);
  }

  {
    auto pointer(::portable_stl::make_unique<std::int32_t[]>(1U));
    ASSERT_TRUE((pointer.operator bool()));
  }

  {
    // Value not initialized.
    auto pointer(::portable_stl::make_unique_for_overwrite<std::int32_t>());
    ASSERT_TRUE((pointer.operator bool()));
  }

  {
    // Values in array not initialized.
    auto pointer(::portable_stl::make_unique_for_overwrite<std::int32_t[]>(1U));
    ASSERT_TRUE((pointer.operator bool()));
  }
}
