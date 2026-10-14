// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="strong_ordering.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_STRONG_ORDERING_H
#define PSTL_STRONG_ORDERING_H
#include "compare_t.h"
#include "not_ordered.h"
#include "ordered.h"
#include "partial_ordering.h"
#include "unspecified.h"
#include "weak_ordering.h"
namespace portable_stl {
/**
 * @brief The result type of 3-way comparison that supports all 6 operators and is substitutable.
 *
 */
class strong_ordering final {
  /**
   * @brief The comparsion result value.
   *
   */
  ::portable_stl::compare_helper::compare_t m_value;

  /**
   * @brief Helper constructor for ordered result.
   * @param value the result value.
   */
  constexpr inline strong_ordering(::portable_stl::compare_helper::ordered const value) noexcept
      : m_value(static_cast<decltype(m_value)>(value)) {
  }

public:
  /**
   * @brief A valid value of the type strong_ordering indicating less-than (ordered before) relationship.
   * @return compare result.
   */
  constexpr inline static strong_ordering less() noexcept {
    return {::portable_stl::compare_helper::ordered::less};
  }

  /**
   * @brief A valid value of the type strong_ordering indicating equivalence (neither ordered before nor ordered after),
   * the same as equal.
   *
   * @return compare result.
   */
  constexpr inline static strong_ordering equivalent() noexcept {
    return {::portable_stl::compare_helper::ordered::equivalent};
  }

  /**
   * @brief A valid value of the type strong_ordering indicating equivalence (neither ordered before nor ordered after),
   * the same as equivalent.
   *
   * @return compare result.
   */
  constexpr inline static strong_ordering equal() noexcept {
    return {::portable_stl::compare_helper::ordered::equal};
  }

  /**
   * @brief A valid value of the type strong_ordering indicating greater-than (ordered after) relationship.
   *
   * @return compare result.
   */
  constexpr inline static strong_ordering greater() noexcept {
    return {::portable_stl::compare_helper::ordered::greater};
  }

  /**
   * @brief strong_ordering is implicitly-convertible to partial_ordering.
   */
  constexpr operator partial_ordering() const noexcept {
    return ((m_value == static_cast<decltype(m_value)>(::portable_stl::compare_helper::ordered::equivalent))
              ? (::portable_stl::partial_ordering::equivalent())
              : ((m_value == static_cast<decltype(m_value)>(::portable_stl::compare_helper::ordered::less))
                   ? (::portable_stl::partial_ordering::less())
                   : (::portable_stl::partial_ordering::greater())));
  }

  /**
   * @brief strong_ordering is implicitly-convertible to weak_ordering.
   */
  constexpr operator weak_ordering() const noexcept {
    return ((m_value == static_cast<decltype(m_value)>(::portable_stl::compare_helper::ordered::equivalent))
              ? (::portable_stl::weak_ordering::equivalent())
              : ((m_value == static_cast<decltype(m_value)>(::portable_stl::compare_helper::ordered::less))
                   ? (::portable_stl::weak_ordering::less())
                   : (::portable_stl::weak_ordering::greater())));
  }

  /**
   * @brief Comparison operators are defined between values of this.
   * @param other the value for compare.
   * @return compare result.
   * @retval true if current and other is equal.
   * @retval false if current and other is not equal.
   */
  constexpr inline bool operator==(::portable_stl::strong_ordering const other) const noexcept {
    return m_value == other.m_value;
  }

  /**
   * @brief Comparison operators are defined between values of this.
   * @param other the value for compare.
   * @return compare result.
   * @retval true if current and other is not equal.
   * @retval false if current and other is equal.
   */
  constexpr inline bool operator!=(::portable_stl::strong_ordering const other) const noexcept {
    return !(this->operator==(other));
  }

  /**
   * @brief Comparison operators are defined between values of this type and literal 0.
   *
   * @return result of comparesion.
   *
   * @retval true if this value is equivalent.
   * @retval false if this value is not equivalent.
   */
  constexpr inline bool operator==(::portable_stl::compare_helper::unspecified const) const noexcept {
    return m_value
        == static_cast<::portable_stl::compare_helper::compare_t>(::portable_stl::compare_helper::ordered::equal);
  }

  /**
   * @brief Comparison operators are defined between values of this type and literal 0.
   *
   * @param value value for comparsion.
   *
   * @return result of comparesion.
   *
   * @retval true if this value is not equivalent.
   * @retval false if this value is equivalent.
   */
  constexpr inline bool operator!=(::portable_stl::compare_helper::unspecified const value) const noexcept {
    return !(this->operator==(value));
  }

  /**
   * @brief Comparison operators are defined between values of this type and literal 0.
   *
   * @return result of comparesion.
   *
   * @retval true if this value is less.
   * @retval false if this value is not less.
   */
  constexpr inline bool operator<(::portable_stl::compare_helper::unspecified const) const noexcept {
    return m_value
        == static_cast<::portable_stl::compare_helper::compare_t>(::portable_stl::compare_helper::ordered::less);
  }

  /**
   * @brief Comparison operators are defined between values of this type and literal 0.
   *
   * @return result of comparesion.
   *
   * @retval true if this value is greater.
   * @retval false if this value is not greater.
   */
  constexpr inline bool operator>(::portable_stl::compare_helper::unspecified const) const noexcept {
    return m_value
        == static_cast<::portable_stl::compare_helper::compare_t>(::portable_stl::compare_helper::ordered::greater);
  }

  /**
   * @brief Comparison operators are defined between values of this type and literal 0.
   *
   * @return result of comparesion.
   *
   * @retval true if this value is less or equal.
   * @retval false if this value is greater.
   */
  constexpr inline bool operator<=(::portable_stl::compare_helper::unspecified const) const noexcept {
    return (
      m_value
      != static_cast<::portable_stl::compare_helper::compare_t>(::portable_stl::compare_helper::ordered::greater));
  }

  /**
   * @brief Comparison operators are defined between values of this type and literal 0.
   *
   * @return result of comparesion.
   *
   * @retval true if this value is greater or equal.
   * @retval false if this value is less.
   */
  constexpr inline bool operator>=(::portable_stl::compare_helper::unspecified const) const noexcept {
    return (m_value
            != static_cast<::portable_stl::compare_helper::compare_t>(::portable_stl::compare_helper::ordered::less));
  }
};

/**
 * @brief Comparison operators are defined between values of literal 0 and strong_ordering type.
 *
 * @param w - literal 0 parameter.
 * @param v - weak_ordering parametr.
 *
 * @return result of comparesion.
 *
 * @retval true if this value is equivalent.
 * @retval false if this value is not equivalent.
 */
constexpr inline static bool operator==(::portable_stl::compare_helper::unspecified const w,
                                        strong_ordering const                             v) noexcept {
  return (v.operator==(w));
}

/**
 * @brief Comparison operators are defined between values of literal 0 and strong_ordering type.
 *
 * @param w - literal 0 parameter.
 * @param v - weak_ordering parametr.
 *
 * @return result of comparesion.
 *
 * @retval true if this value is not equivalent.
 * @retval false if this value is equivalent.
 */
constexpr inline static bool operator!=(::portable_stl::compare_helper::unspecified const w,
                                        strong_ordering const                             v) noexcept {
  return (v.operator!=(w));
}

/**
 * @brief Comparison operators are defined between values of literal 0 and strong_ordering type.
 *
 * @param w - literal 0 parameter.
 * @param v - weak_ordering parametr.
 *
 * @return result of comparesion.
 *
 * @retval true if this value is greater.
 * @retval false if this value is not greater.
 */
constexpr inline static bool operator<(::portable_stl::compare_helper::unspecified const w,
                                       strong_ordering const                             v) noexcept {
  return (v.operator>(w));
}

/**
 * @brief Comparison operators are defined between values of literal 0 and strong_ordering type.
 *
 * @param w - literal 0 parameter.
 * @param v - weak_ordering parametr.
 *
 * @return result of comparesion.
 *
 * @retval true if this value is less.
 * @retval false if this value is not less.
 */
constexpr inline static bool operator>(::portable_stl::compare_helper::unspecified const w,
                                       strong_ordering const                             v) noexcept {
  return (v.operator<(w));
}

/**
 * @brief Comparison operators are defined between values of literal 0 and strong_ordering type.
 *
 * @param w - literal 0 parameter.
 * @param v - weak_ordering parametr.
 *
 * @return result of comparesion.
 *
 * @retval true if this value is greater or equal.
 * @retval false if this value is less or unordered.
 */
constexpr inline static bool operator<=(::portable_stl::compare_helper::unspecified const w,
                                        strong_ordering const                             v) noexcept {
  return (v.operator>=(w));
}

/**
 * @brief Comparison operators are defined between values of literal 0 and strong_ordering type.
 *
 * @param w - literal 0 parameter.
 * @param v - weak_ordering parametr.
 *
 * @return result of comparesion.
 *
 * @retval true if this value is less or equal.
 * @retval false if this value is greater or unordered.
 */
constexpr inline static bool operator>=(::portable_stl::compare_helper::unspecified const w,
                                        strong_ordering const                             v) noexcept {
  return (v.operator<=(w));
}
} // namespace portable_stl

#endif // PSTL_STRONG_ORDERING_H
