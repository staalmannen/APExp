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

namespace std {
/**
 * @brief Describe errors in portable_stl
 *
 */
enum class std_error {
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

/*
 * `portable_stl_error' WAS THE NAME AND `std_error' IS THE NAME, and
 * the alias is here because this file is the ONE definition against
 * twenty-one users.  Renaming the implementation namespace to `std'
 * rewrote every USE -- `::portable_stl::portable_stl_error' became
 * `::std::std_error' -- and left the definition alone, so every
 * container's error type named a member of `std' that did not exist.
 * cpfe said so twenty-one times and the host says so once; see
 * `docs/notes/cxx-library.md'.
 *
 * The alias costs nothing and keeps upstream's spelling compiling, so
 * a future re-import does not have to be rewritten to be read.
 */
using portable_stl_error = std_error;

} // namespace std

#endif // PSTL_PORTABLE_STL_ERROR_H
