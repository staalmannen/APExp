// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="portable_stl_error.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_PORTABLE_STL_ERROR_H
#define PSTL_PORTABLE_STL_ERROR_H

namespace portable_stl {
/**
 * @brief Describe errors in portable_stl
 *
 */
enum class portable_stl_error {
  /**
   * @brief Catch exception in delete object proccess.
   *
   */
  delete_error,
  /**
   * @brief It reports errors that are consequence of attempt to access elements out of defined range.
   *
   */
  out_of_range,
  /**
   * @brief Reports failure to allocate to big storage.
   *
   */
  length_error,
  /**
   * @brief Can't allocate memory.
   *
   */
  allocate_error,
  /**
   * @brief Can't construct object.
   *
   */
  construct_error,
  /**
   * @brief Object not exist.
   *
   */
  not_exists,
};
} // namespace portable_stl

#endif // PSTL_PORTABLE_STL_ERROR_H
