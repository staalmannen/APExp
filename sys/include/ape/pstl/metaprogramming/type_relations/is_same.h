// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_same.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_SAME_H
#define PSTL_IS_SAME_H

#include "../helper/integral_constant.h"

namespace portable_stl {
namespace type_relations_helper {
  /**
   * @brief t_type and t_other_type name the same with the same cv-qualifications.
   *
   * @tparam t_type The type for compare.
   * @tparam t_other_type The other type for compare.
   */
  template<class t_type, class t_other_type> class is_same final {
  public:
    /**
     * @brief Value getter.
     *
     * @return The current constant value.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief t_type and t_other_type name the same with the same cv-qualifications.
   *
   * @tparam t_type The type for compare.
   */
  template<class t_type> class is_same<t_type, t_type> final {
  public:
    /**
     * @brief Value getter.
     *
     * @return The current constant value.
     */
    using type = ::portable_stl::true_type;
  };
} // namespace type_relations_helper

/**
 * @brief t_type and t_other_type name the same with the same cv-qualifications.
 *
 * @tparam t_type The type for compare.
 * @tparam t_other_type The other type for compare.
 */
template<class t_type, class t_other_type>
using is_same = typename ::portable_stl::type_relations_helper::is_same<t_type, t_other_type>::type;
} // namespace portable_stl

#endif // PSTL_IS_SAME_H
