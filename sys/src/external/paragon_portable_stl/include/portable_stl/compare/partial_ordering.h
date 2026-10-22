// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="partial_ordering.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_PARTIAL_ORDERING_H
#define PSTL_PARTIAL_ORDERING_H

#include "compare_t.h"
#include "not_ordered.h"
#include "ordered.h"
#include "unspecified.h"
namespace portable_stl {

/**
 * @brief The result type of 3-way comparison that supports all 6 operators, is not substitutable, and allows
 * incomparable values
 *
 */
class partial_ordering final {
  /**
   * @brief The comparsion result value.
   *
   */
  ::portable_stl::compare_helper::compare_t m_value;

  /**
   * @brief Helper constructor for ordered result.
   * @param value the result value.
   */
  constexpr partial_ordering(::portable_stl::compare_helper::ordered const value) noexcept
      : m_value(static_cast<decltype(m_value)>(value)) {
  }

  /**
   * @brief Helper constructor for non ordered result.
   * @param value the result value.
   */
  constexpr partial_ordering(::portable_stl::compare_helper::not_ordered const value) noexcept
      : m_value(static_cast<decltype(m_value)>(value)) {
  }

public:
  /**
   * @brief a valid value of the type partial_ordering indicating less-than (ordered before) relationship.
   * @return compare result.
   */
  constexpr inline static partial_ordering less() noexcept {
    return {::portable_stl::compare_helper::ordered::less};
  }

  /**
   * @brief a valid value of the type partial_ordering indicating equivalence (neither ordered before nor ordered
   * after).
   * @return compare result.
   */
  constexpr inline static partial_ordering equivalent() noexcept {
    return {::portable_stl::compare_helper::ordered::equivalent};
  }

  /**
   * @brief a valid value of the type partial_ordering indicating greater-than (ordered after) relationship.
   * @return compare result.
   */
  constexpr inline static partial_ordering greater() noexcept {
    return {::portable_stl::compare_helper::ordered::greater};
  }

  /**
   * @brief a valid value of the type ::partial_ordering indicating relationship with an incomparable value.
   * @return compare result.
   */
  constexpr inline static partial_ordering unordered() noexcept {
    return {::portable_stl::compare_helper::not_ordered::unordered};
  }
  /**
   * @brief Comparison operators are defined between values of this.
   * @param other the value for compare.
   * @return compare result.
   * @retval true if current and other is equal.
   * @retval false if current and other is not equal.
   */
  constexpr inline bool operator==(::portable_stl::partial_ordering const other) const noexcept {
    return m_value == other.m_value;
  }

  /**
   * @brief Comparison operators are defined between values of this.
   * @param other the value for compare.
   * @return compare result.
   * @retval true if current and other is not equal.
   * @retval false if current and other is equal.
   */
  constexpr inline bool operator!=(::portable_stl::partial_ordering const other) const noexcept {
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
    return (m_value
            == static_cast<::portable_stl::compare_helper::compare_t>(::portable_stl::compare_helper::ordered::equal));
  }

  /**
   * @brief Comparison operators are defined between values of this type and literal 0.
   *
   * @param v value for comparsion.
   *
   * @return result of comparesion.
   *
   * @retval true if this value is not equivalent.
   * @retval false if this value is equivalent.
   */
  constexpr inline bool operator!=(::portable_stl::compare_helper::unspecified const v) const noexcept {
    return !(this->operator==(v));
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
    return (m_value
            == static_cast<::portable_stl::compare_helper::compare_t>(::portable_stl::compare_helper::ordered::less));
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
    return (
      m_value
      == static_cast<::portable_stl::compare_helper::compare_t>(::portable_stl::compare_helper::ordered::greater));
  }

  /**
   * @brief Comparison operators are defined between values of this type and literal 0.
   *
   * @return result of comparesion.
   *
   * @retval true if this value is less or equal.
   * @retval false if this value is greater or unordered.
   */
  constexpr inline bool operator<=(::portable_stl::compare_helper::unspecified const) const noexcept {
    return (
      (m_value
       != static_cast<::portable_stl::compare_helper::compare_t>(
         ::portable_stl::compare_helper::not_ordered::unordered))
      && (m_value
          != static_cast<::portable_stl::compare_helper::compare_t>(::portable_stl::compare_helper::ordered::greater)));
  }

  /**
   * @brief Comparison operators are defined between values of this type and literal 0.
   *
   * @return result of comparesion.
   *
   * @retval true if this value is greater or equal.
   * @retval false if this value is less or unordered.
   */
  constexpr inline bool operator>=(::portable_stl::compare_helper::unspecified const) const noexcept {
    return (m_value
            >= static_cast<::portable_stl::compare_helper::compare_t>(::portable_stl::compare_helper::ordered::equal));
  }
};

/**
 * @brief Comparison operators are defined between values of literal 0 and partial_ordering type.
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
                                        partial_ordering const                            v) noexcept {
  return (v.operator==(w));
}

/**
 * @brief Comparison operators are defined between values of literal 0 and partial_ordering type.
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
                                        partial_ordering const                            v) noexcept {
  return (v.operator!=(w));
}

/**
 * @brief Comparison operators are defined between values of literal 0 and partial_ordering type.
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
                                       partial_ordering const                            v) noexcept {
  return (v.operator>(w));
}

/**
 * @brief Comparison operators are defined between values of literal 0 and partial_ordering type.
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
                                       partial_ordering const                            v) noexcept {
  return (v.operator<(w));
}

/**
 * @brief Comparison operators are defined between values of literal 0 and partial_ordering type.
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
                                        partial_ordering const                            v) noexcept {
  return (v.operator>=(w));
}

/**
 * @brief Comparison operators are defined between values of literal 0 and partial_ordering type.
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
                                        partial_ordering const                            v) noexcept {
  return (v.operator<=(w));
}

} // namespace portable_stl

#endif /* PSTL_PARTIAL_ORDERING_H */
