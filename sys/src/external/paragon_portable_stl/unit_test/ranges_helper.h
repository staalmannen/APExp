// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="ranges_helper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_RANGES_HELPER_H
#define PSTL_RANGES_HELPER_H

namespace test_ranges_helper {
/**
 * @brief Helper non empty class.
 */
class non_empty_class final {
public:
  /**
   * @brief Helper value
   */
  std::int32_t value_a{0};
};

/**
 * @brief Class to check ranges::begin.
 * @tparam throw_exception
 */
template<bool throw_exception> class has_begin_member_can_throw final {
  /**
   * @brief Data.
   */
  std::int32_t m_value{1};

public:
  /**
   * @brief Member function.
   * @return std::int32_t const*
   */
  std::int32_t const *begin() noexcept(!throw_exception) {
    return &m_value;
  }
};

/**
 * @brief Class to check ranges::begin.
 * @tparam throw_exception
 */
template<bool throw_exception> class has_begin_func_can_throw final {
  /**
   * @brief Data.
   */
  std::int32_t m_value{0};

public:
  /**
   * @brief
   * @return std::int32_t const*
   */
  std::int32_t *base() {
    return &m_value;
  }
};

/**
 * @brief Begin customization.
 *
 * @param item
 * @return std::int32_t const*
 */
inline static std::int32_t *begin(has_begin_func_can_throw<false> &item) noexcept {
  return item.base();
}

/**
 * @brief Begin customization.
 *
 * @param item
 * @return std::int32_t const*
 */
inline static std::int32_t *begin(has_begin_func_can_throw<true> &item) noexcept(false) {
  return item.base();
}

/**
 * @brief Class to check ranges::iter_move.
 * Has custom iter_move.
 * @tparam throw_exception
 */
template<bool throw_exception> class has_adl_iter_move_can_throw final {};

/**
 * @brief iter_move customization.
 * @return std::int32_t
 */
inline static std::int64_t iter_move(has_adl_iter_move_can_throw<false> const &) noexcept {
  return 1;
}

/**
 * @brief iter_move customization.
 * @return std::int32_t
 */
inline static std::int64_t iter_move(has_adl_iter_move_can_throw<true> const &) noexcept(false) {
  return 1;
}

/**
 * @brief Class to check ranges::iter_move.
 * lvalue dereferenceable.
 * @tparam throw_exception
 */
template<bool throw_exception> class lvalue_deref_can_throw final {
  /**
   * @brief Data.
   */
  std::int32_t m_value{0};

public:
  /**
   * @brief Deref.
   * @return
   */
  std::int32_t &operator*() noexcept(!throw_exception) {
    return m_value;
  }
};

/**
 * @brief Class to check ranges::iter_move.
 * non lvalue dereferenceable.
 * @tparam throw_exception
 */
template<bool throw_exception> class rvalue_deref_can_throw final {
public:
  /**
   * @brief non lvalue deref operator.
   * @return std::int32_t
   */
  std::int16_t operator*() noexcept(!throw_exception) {
    return 1;
  }
};

/**
 * @brief Class to check ranges::iter_swap.
 * Has custom iter_move.
 * @tparam throw_exception
 */
template<bool throw_exception> class has_adl_iter_swap_can_throw final {
  /**
   * @brief Data.
   */
  std::int32_t &m_value;

public:
  /**
   * @brief Ctor.
   * @param value init value.
   */
  has_adl_iter_swap_can_throw(std::int32_t &value) : m_value(value) {
  }
  /**
   * @brief Test setter for swap.
   * @param set_value
   */
  void test_setter(std::int32_t set_value) const {
    m_value = set_value;
  }

  /**
   * @brief Test getter
   * @return std::int32_t data value.
   */
  std::int32_t test_getter() const {
    return m_value;
  }
};

/**
 * @brief iter_swap customization.
 * @param left
 * @param right
 */
inline static void iter_swap(has_adl_iter_swap_can_throw<false> const left,
                             has_adl_iter_swap_can_throw<false> const right) noexcept {
  left.test_setter(1);
  right.test_setter(0);
}

/**
 * @brief iter_swap customization.
 * @param left
 * @param right
 */
inline static void iter_swap(has_adl_iter_swap_can_throw<true> const left,
                             has_adl_iter_swap_can_throw<true> const right) noexcept(false) {
  left.test_setter(1);
  right.test_setter(0);
}

/**
 * @brief indirectly_deref_swappable_can_throw internal data
 */
class has_adl_swap final {
  /**
   * @brief Data.
   */
  mutable std::int32_t m_value{0};

public:
  /**
   * @brief
   */
  void test_set() const noexcept {
    m_value = 1;
  }
};

/**
 * @brief Custom swap.
 *
 * @param left
 * @param right
 */
inline static void swap(has_adl_swap const &left, has_adl_swap const &right) noexcept {
  left.test_set();
  right.test_set();
}

/**
 * @brief Class to check ranges::iter_swap.
 * Has custom iter_move.
 * @tparam throw_exception
 */
template<bool throw_exception> class indirectly_deref_swappable_can_throw final {
public:
  /**
   * @brief Value type.
   */
  using value_type = has_adl_swap;

// private:
  /**
   * @brief Data.
   */
  value_type m_value;

public:
  /**
   * @brief Dereference operator.
   * @return value_type&
   */
  value_type const &operator*() const noexcept(!throw_exception) {
    return m_value;
  }
};

/**
 * @brief Class to check ranges::end.
 * @tparam throw_exception
 */
template<bool throw_exception> class has_end_member_can_throw final {
  /**
   * @brief Data.
   */
  std::int32_t m_value{1};

public:
  /**
   * @brief Member function.
   * @return std::int32_t *
   */
  std::int32_t *begin() noexcept(!throw_exception) {
    return &m_value;
  }

  /**
   * @brief Member function.
   * @return std::int32_t*
   */
  std::int32_t *end() noexcept(!throw_exception) {
    return &m_value;
  }
};

/**
 * @brief Class to check ranges::end.
 * @tparam throw_exception
 */
template<bool throw_exception> class has_end_func_can_throw final {
  /**
   * @brief Data.
   */
  std::int32_t m_value{0};

public:
  /**
   * @brief
   * @return std::int32_t*
   */
  std::int32_t *base() noexcept {
    return &m_value;
  }
  /**
   * @brief Member function.
   * Require to calculate ranges::iterator_t<T> and sentinel_for<ranges::iterator_t<T>> durin end(t_type) call.
   * @return std::int32_t const*
   */
  std::int32_t const *begin() noexcept {
    return &m_value;
  }
};

/**
 * @brief End customization.
 *
 * @param item
 * @return std::int32_t*
 */
inline static std::int32_t *end(has_end_func_can_throw<false> &item) noexcept {
  return item.base();
}

/**
 * @brief End customization.
 *
 * @param item
 * @return std::int32_t*
 */
inline static std::int32_t *end(has_end_func_can_throw<true> &item) noexcept(false) {
  return item.base();
}

/**
 * @brief Class to check ranges::size.
 * @tparam throw_exception_size
 */
template<bool throw_exception_size> class has_size_member_can_throw final {
public:
  /**
   * @brief Member function.
   * @return std::int32_t const*
   */
  static std::size_t size() noexcept(!throw_exception_size) {
    return 1U;
  }
};

/**
 * @brief Class to check ranges::size.
 * @tparam throw_exception
 */
template<bool throw_exception> class has_size_func_can_throw final {
public:
  /**
   * @brief accessor.
   * @return std::size_t
   */
  std::size_t size_internal() const noexcept {
    return 0U;
  }
};

/**
 * @brief Size customization.
 *
 * @param item
 * @return std::size_t const
 */
inline static std::size_t size(has_size_func_can_throw<false> const &item) noexcept {
  return item.size_internal();
}

/**
 * @brief Size customization.
 *
 * @param item
 * @return std::size_t const
 */
inline static std::size_t size(has_size_func_can_throw<true> const &item) noexcept(false) {
  return item.size_internal();
}

/**
 * @brief Class to check ranges::size.
 * @tparam throw_exception_begin false by default.
 * @tparam throw_exception_end false by default.
 */
template<bool throw_exception_begin, bool throw_exception_end> class has_begin_end_member_can_throw final {
  /**
   * @brief Data.
   */
  std::int32_t *m_begin;
  /**
   * @brief Data.
   */
  std::int32_t *m_end;

public:
  /**
   * @brief Construct a new has begin end member can throw object
   *
   * @param ptr1
   * @param ptr2
   */
  has_begin_end_member_can_throw(std::int32_t *ptr1, std::int32_t *ptr2) : m_begin(ptr1), m_end(ptr2) {
  }
  /**
   * @brief Construct a new has begin end member can throw object
   * @param ptr
   */
  explicit has_begin_end_member_can_throw(std::int32_t *ptr) : has_begin_end_member_can_throw(ptr, ptr) {
  }
  /**
   * @brief Member function.
   * @return std::int32_t const*
   */
  std::int32_t const *begin() noexcept(!throw_exception_begin) {
    return m_begin;
  }
  /**
   * @brief Member function.
   * @return std::int32_t const*
   */
  std::int32_t const *end() noexcept(!throw_exception_end) {
    return m_end;
  }
};

/**
 * @brief Class to check ranges::empty.
 * @tparam throw_exception
 */
template<bool throw_exception, bool result> class has_empty_member_can_throw final {
public:
  /**
   * @brief Member function.
   * @return true if empty.
   */
  static bool empty() noexcept(!throw_exception) {
    return result;
  }
};

/**
 * @brief Class to check ranges::data.
 * @tparam throw_exception
 */
template<bool throw_exception> class has_data_member_can_throw final {
  /**
   * @brief Data.
   */
  std::int32_t m_data{1};

public:
  /**
   * @brief Member function.
   * @return true if empty.
   */
  std::int32_t const *data() noexcept(!throw_exception) {
    return &m_data;
  }
};

/**
 * @brief Class to check ranges::rbegin.
 * @tparam throw_exception
 */
template<bool throw_exception> class has_rbegin_member_can_throw final {
  /**
   * @brief Data.
   */
  std::int32_t m_value{1};

public:
  /**
   * @brief Member function.
   * @return std::int32_t const*
   */
  std::int32_t const *rbegin() noexcept(!throw_exception) {
    return &m_value;
  }
};

/**
 * @brief Class to check ranges::rbegin.
 * @tparam throw_exception
 */
template<bool throw_exception> class has_rbegin_func_can_throw final {
  /**
   * @brief Data.
   */
  std::int32_t m_value{0};

public:
  /**
   * @brief
   * @return std::int32_t const*
   */
  std::int32_t *base() {
    return &m_value;
  }
};

/**
 * @brief RBegin customization.
 *
 * @param item
 * @return std::int32_t const*
 */
inline static std::int32_t *rbegin(has_rbegin_func_can_throw<false> &item) noexcept {
  return item.base();
}

/**
 * @brief RBegin customization.
 *
 * @param item
 * @return std::int32_t const*
 */
inline static std::int32_t *rbegin(has_rbegin_func_can_throw<true> &item) noexcept(false) {
  return item.base();
}

/**
 * @brief Class to check ranges::rend.
 * @tparam throw_exception
 */
template<bool throw_exception> class has_rend_member_can_throw final {
  /**
   * @brief Data.
   */
  std::int32_t m_value{1};

public:
  /**
   * @brief Member function.
   * @return std::int32_t const*
   */
  std::int32_t const *rend() noexcept(!throw_exception) {
    return &m_value;
  }
  /**
   * @brief Member function.
   * Requested by rend call.
   * @return std::int32_t const*
   */
  std::int32_t const *rbegin() noexcept(!throw_exception) {
    return &m_value;
  }
};

/**
 * @brief Class to check ranges::rend.
 * @tparam throw_exception
 */
template<bool throw_exception> class has_rend_func_can_throw final {
  /**
   * @brief Data.
   */
  std::int32_t m_value{0};

public:
  /**
   * @brief
   * @return std::int32_t *
   */
  std::int32_t *base() {
    return &m_value;
  }
  /**
   * @brief Member function.
   * Requested by rend call.
   * @return std::int32_t *
   */
  std::int32_t *rbegin() noexcept(!throw_exception) {
    return &m_value;
  }
};

/**
 * @brief REnd customization.
 *
 * @param item
 * @return std::int32_t *
 */
inline static std::int32_t *rend(has_rend_func_can_throw<false> &item) noexcept {
  return item.base();
}

/**
 * @brief REnd customization.
 *
 * @param item
 * @return std::int32_t *
 */
inline static std::int32_t *rend(has_rend_func_can_throw<true> &item) noexcept(false) {
  return item.base();
}
} // namespace test_ranges_helper

#endif /* PSTL_RANGES_HELPER_H */
