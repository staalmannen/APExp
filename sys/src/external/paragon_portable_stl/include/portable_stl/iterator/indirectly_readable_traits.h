// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="indirectly_readable_traits.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INDIRECTLY_READABLE_TRAITS_H
#define PSTL_INDIRECTLY_READABLE_TRAITS_H

#include "../metaprogramming/array_modifications/remove_extent.h"
#include "../metaprogramming/composite_type/is_object.h"
#include "../metaprogramming/cv_modifications/remove_const.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../metaprogramming/pointer_modifications/remove_pointer.h"
#include "../metaprogramming/primary_type/is_array.h"
#include "../utility/general/declval.h"

namespace portable_stl {

namespace iterator_helper {
  /**
   * @brief Helper class to check if type has public typename value_type.
   */
  template<class, class = void> class is_type_has_member_value_type final {
  public:
    /**
     * @brief Result 'value' type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief Helper class to check if type has public typename value_type.
   *
   * @tparam t_type Tested type.
   */
  template<class t_type>
  class is_type_has_member_value_type<t_type, ::portable_stl::void_t<typename t_type::value_type>> final {
  public:
    /**
     * @brief Result 'value' type.
     */
    using type = ::portable_stl::true_type;
  };

  /**
   * @brief Helper class to check if type has public typename value_type.
   *
   * @tparam t_type Tested type.
   */
  template<class t_type> using is_type_has_member_value_type_t = typename is_type_has_member_value_type<t_type>::type;

  /**
   * @brief Helper class to check if type has public typename element_type.
   */
  template<class, class = void> class is_type_has_element_type final {
  public:
    /**
     * @brief Result 'value' type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief Helper class to check if type has public typename element_type.
   *
   * @tparam t_type Tested type.
   */
  template<class t_type>
  class is_type_has_element_type<t_type, ::portable_stl::void_t<typename t_type::element_type>> final {
  public:
    /**
     * @brief Result 'value' type.
     */
    using type = ::portable_stl::true_type;
  };

  /**
   * @brief Helper class to check if type has public typename element_type.
   *
   * @tparam t_type Tested type.
   */
  template<class t_type> using is_type_has_element_type_t = typename is_type_has_element_type<t_type>::type;
}; // namespace iterator_helper

/**
 * @brief Primary template has no member value_type.
 */
template<class, class = void> class indirectly_readable_traits final {};

/**
 * @brief Associated value type for object type.
 * @tparam t_type Given type.
 */
template<class t_type>
class indirectly_readable_traits<t_type,
                                 ::portable_stl::enable_if_bool_constant_t<::portable_stl::conjunction<
                                   ::portable_stl::is_pointer<t_type>,
                                   ::portable_stl::is_object<::portable_stl::remove_pointer<t_type>>>>>
  final {
public:
  /**
   * @brief Associated value type.
   */
  using value_type = ::portable_stl::remove_cv_t<::portable_stl::remove_pointer_t<t_type>>;
};

/**
 * @brief Associated value type for array.
 *
 * @tparam t_iterator Given type.
 */
template<class t_iterator>
class indirectly_readable_traits<t_iterator,
                                 ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_array<t_iterator>>>
  final {
public:
  /**
   * @brief Associated value type.
   */
  using value_type = ::portable_stl::remove_extent_t<::portable_stl::remove_cv_t<t_iterator>>;
};

/**
 * @brief Associated value type for type with public typename value_type, which is object type.
 *
 * @tparam t_type Given type.
 */
template<class t_type>
class indirectly_readable_traits<t_type,
                                 ::portable_stl::enable_if_bool_constant_t<
                                   ::portable_stl::conjunction<iterator_helper::is_type_has_member_value_type_t<t_type>,
                                                               ::portable_stl::is_object<typename t_type::value_type>>>>
  final {
public:
  /**
   * @brief Associated value type.
   */
  using value_type = typename t_type::value_type;
};

/**
 * @brief Associated value type for type with public typename element_type, which is object type.
 *
 * @tparam t_type Given type.
 */
template<class t_type>
class indirectly_readable_traits<t_type,
                                 ::portable_stl::enable_if_bool_constant_t<::portable_stl::conjunction<
                                   iterator_helper::is_type_has_element_type_t<t_type>,
                                   ::portable_stl::is_object<typename t_type::element_type>>>>
  final {
public:
  /**
   * @brief Associated value type.
   */
  using value_type = typename t_type::element_type;
};
} // namespace portable_stl

#endif // PSTL_INDIRECTLY_READABLE_TRAITS_H
