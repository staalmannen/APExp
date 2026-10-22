// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="nat.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_NAT_H
#define PSTL_NAT_H

namespace portable_stl {
/**
 * @brief "Not-A-Type" is mainly used as a tag type for SFINAE.
 */
class nat_class {
public:
  /**
   * @brief Deleted.
   */
  nat_class()                             = delete;
  /**
   * @brief Deleted.
   * @param
   */
  nat_class(nat_class const &)            = delete;
  /**
   * @brief Deleted.
   * @return
   */
  nat_class &operator=(nat_class const &) = delete;
  /**
   * @brief Deleted.
   */
  ~nat_class()                            = delete;
};
} // namespace portable_stl

#endif /* PSTL_NAT_H */
