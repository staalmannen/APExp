// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="remove_pointer.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_REMOVE_POINTER_H
#define PSTL_REMOVE_POINTER_H
namespace portable_stl {
/**
 * @brief Removes a pointer from the given type.
 * Pointer can not be delete from t_type.
 * @tparam t_type The given type.
 */
template<class t_type> class remove_pointer final {
public:
  /**
   * @brief The type pointed to by t_type or t_type if it's not a pointer.
   *
   */
  using type = t_type;
};

/**
 * @brief Removes a pointer from the given type.
 * Pointer can be delete from t_type.
 * @tparam t_type The given type.
 */
template<class t_type> class remove_pointer<t_type *> final {
public:
  /**
   * @brief The type pointed to by t_type or t_type if it's not a pointer.
   *
   */
  using type = t_type;
};

/**
 * @brief Removes a pointer from the given type.
 *
 * @tparam t_type The given type.
 */
template<class t_type> using remove_pointer_t = typename remove_pointer<t_type>::type;
} // namespace portable_stl
#endif // PSTL_REMOVE_POINTER_H
