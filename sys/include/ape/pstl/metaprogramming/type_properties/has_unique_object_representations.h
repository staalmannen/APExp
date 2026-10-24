// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="has_unique_object_representations.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_HAS_UNIQUE_OBJECT_REPRESENTATIONS_H
#define PSTL_HAS_UNIQUE_OBJECT_REPRESENTATIONS_H

#include "../helper/integral_constant.h"

namespace portable_stl {

namespace type_properties_helper {
  /**
   * @brief A wrapper over a build-in function to add indirectness. Necessary for msvc.
   *
   * @tparam t_type Processed type.
   */
  template<class t_type> class has_unique_object_representations_wrapper final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::bool_constant<__has_unique_object_representations(t_type)>;
  };
} // namespace type_properties_helper

/**
 * @brief Check if t_type is TriviallyCopyable and if any two objects of type t_type
 * with the same value have the same object representation.
 *
 * @tparam t_type type for check.
 */
template<class t_type>
using has_unique_object_representations =
  typename type_properties_helper::has_unique_object_representations_wrapper<t_type>::type;
} // namespace portable_stl

#endif // PSTL_HAS_UNIQUE_OBJECT_REPRESENTATIONS_H
