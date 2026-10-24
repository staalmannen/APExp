// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="insert_return_type.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INSERT_RETURN_TYPE_H
#define PSTL_INSERT_RETURN_TYPE_H

namespace portable_stl {
/**
 * @brief Type returned be insert operaion in associative containers with unique keys and the unordered containers with
 * unique keys have a member function insert.
 *
 * @tparam t_iterator Iterator type.
 * @tparam t_node_type Node type.
 */
template<class t_iterator, class t_node_type> struct insert_return_type {
  /**
   * @brief Position of the node in case of a successful insertion.
   *
   */
  t_iterator position;

  /**
   * @brief True in case of a successful insertion
   *
   */
  bool inserted;

  /**
   * @brief
   *
   */
  t_node_type node;
};
} // namespace portable_stl

#endif // PSTL_INSERT_RETURN_TYPE_H
