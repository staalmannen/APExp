// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_scoped_enum.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_SCOPED_ENUM_H
#define PSTL_IS_SCOPED_ENUM_H

#include "../cv_modifications/remove_cv.h"
#include "../logical_operator/conjunction.h"
#include "../logical_operator/negation.h"
#include "../other_transformations/underlying_type.h"
#include "../primary_type/is_enum.h"
#include "../type_relations/is_convertible.h"

namespace portable_stl {
namespace type_properties_helpers {
  /**
   * @brief t_type is a scoped enumeration
   * Not enum version.
   * @tparam t_type type for check.
   */
  template<class t_type, class = ::portable_stl::is_enum<::portable_stl::remove_cv_t<t_type>>>
  class is_scoped_enum final {
  public:
    /**
     * @brief Result getter.
     *
     * @return false.
     */
    using type = ::portable_stl::false_type;
  };
  /**
   * @brief t_type is a scoped enumeration
   * Enum version.
   * @tparam t_type type for check.
   */
  template<class t_type> class is_scoped_enum<t_type, ::portable_stl::true_type> final {
  public:
    /**
     * @brief Result getter.
     *
     * @return false.
     */
    using type = ::portable_stl::negation<
      ::portable_stl::is_convertible<::portable_stl::remove_cv_t<t_type>,
                                     ::portable_stl::underlying_type_t<::portable_stl::remove_cv_t<t_type>>>>;
  };
} // namespace type_properties_helpers
/**
 * @brief t_type is a scoped enumeration
 * @tparam t_type type for check.
 */
template<class t_type> using is_scoped_enum = typename type_properties_helpers::is_scoped_enum<t_type>::type;
} // namespace portable_stl

#endif // PSTL_IS_SCOPED_ENUM_H
