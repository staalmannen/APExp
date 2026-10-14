// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="float_wrapper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FLOAT_WRAPPER_H
#define PSTL_FLOAT_WRAPPER_H

namespace portable_stl {
namespace numeric_limits_helper {

  /**
   * @brief the radix (integer base) used by the representation of all three floating-point types.
   */
  constexpr int const float_radix_constant{__FLT_RADIX__};

  /**
   * @brief minimum positive value of float.
   */
  constexpr float       float_true_min_constant{__FLT_MIN__};
  /**
   * @brief minimum positive value of double.
   */
  constexpr double      double_true_min_constant{__DBL_MIN__};
  /**
   * @brief minimum positive value of long double.
   */
  constexpr long double ldouble_true_min_constant{__LDBL_MIN__};

  /**
   * @brief maximum finite value of float.
   */
  constexpr float       float_true_max_constant{__FLT_MAX__};
  /**
   * @brief maximum finite value of double.
   */
  constexpr double      double_true_max_constant{__DBL_MAX__};
  /**
   * @brief maximum finite value of long double.
   */
  constexpr long double ldouble_true_max_constant{__LDBL_MAX__};

  /**
   * @brief difference between 1.0 and the next representable value for float.
   */
  constexpr float       float_epsilon_constant{__FLT_EPSILON__};
  /**
   * @brief difference between 1.0 and the next representable value for double.
   */
  constexpr double      double_epsilon_constant{__DBL_EPSILON__};
  /**
   * @brief difference between 1.0 and the next representable value for long double.
   */
  constexpr long double ldouble_epsilon_constant{__LDBL_EPSILON__};

  /**
   * @brief number of decimal digits that are guaranteed to be preserved in float roundtrip without change due to
   * rounding or overflow.
   */
  constexpr int const float_digits_constant{__FLT_DIG__};
  /**
   * @brief number of decimal digits that are guaranteed to be preserved in double roundtrip without change due to
   * rounding or overflow.
   */
  constexpr int const double_digits_constant{__DBL_DIG__};
  /**
   * @brief number of decimal digits that are guaranteed to be preserved in long double roundtrip without change due to
   * rounding or overflow.
   */
  constexpr int const ldouble_digits_constant{__LDBL_DIG__};


  /**
   * @brief number of base FLT_RADIX digits that can be represented without losing precision for float.
   */
  constexpr int const float_mant_digits_constant{__FLT_MANT_DIG__};
  /**
   * @brief number of base FLT_RADIX digits that can be represented without losing precision for double.
   */
  constexpr int const double_mant_digits_constant{__DBL_MANT_DIG__};
  /**
   * @brief number of base FLT_RADIX digits that can be represented without losing precision for long double.
   */
  constexpr int const ldouble_mant_digits_constant{__LDBL_MANT_DIG__};


  /**
   * @brief minimum negative integer such that FLT_RADIX raised by power one less than that integer is a normalized
   * float respectively.
   */
  constexpr int const float_min_exp_constant{__FLT_MIN_EXP__};
  /**
   * @brief minimum negative integer such that FLT_RADIX raised by power one less than that integer is a normalized
   * double respectively.
   */
  constexpr int const double_min_exp_constant{__DBL_MIN_EXP__};
  /**
   * @brief minimum negative integer such that FLT_RADIX raised by power one less than that integer is a normalized
   * long double respectively.
   */
  constexpr int const ldouble_min_exp_constant{__LDBL_MIN_EXP__};

  /**
   * @brief minimum negative integer such that 10 raised to that power is a normalized float.
   */
  constexpr int const float_min_10_exp_constant{__FLT_MIN_10_EXP__};
  /**
   * @brief minimum negative integer such that 10 raised to that power is a normalized double.
   */
  constexpr int const double_min_10_exp_constant{__DBL_MIN_10_EXP__};
  /**
   * @brief minimum negative integer such that 10 raised to that power is a normalized long double.
   */
  constexpr int const ldouble_min_10_exp_constant{__LDBL_MIN_10_EXP__};

  /**
   * @brief maximum positive integer such that FLT_RADIX raised by power one less than that integer is a representable
   * finite float.
   */
  constexpr int const float_max_exp_constant{__FLT_MAX_EXP__};
  /**
   * @brief maximum positive integer such that FLT_RADIX raised by power one less than that integer is a representable
   * finite double.
   */
  constexpr int const double_max_exp_constant{__DBL_MAX_EXP__};
  /**
   * @brief maximum positive integer such that FLT_RADIX raised by power one less than that integer is a representable
   * finite long double.
   */
  constexpr int const ldouble_max_exp_constant{__LDBL_MAX_EXP__};

  /**
   * @brief maximum positive integer such that 10 raised to that power is a representable finite float.
   */
  constexpr int const float_max_10_exp_constant{__FLT_MAX_10_EXP__};
  /**
   * @brief maximum positive integer such that 10 raised to that power is a representable finite double.
   */
  constexpr int const double_max_10_exp_constant{__DBL_MAX_10_EXP__};
  /**
   * @brief maximum positive integer such that 10 raised to that power is a representable finite long double.
   */
  constexpr int const ldouble_max_10_exp_constant{__LDBL_MAX_10_EXP__};

} // namespace numeric_limits_helper
} // namespace portable_stl

#endif // PSTL_FLOAT_WRAPPER_H
