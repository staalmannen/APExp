// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="enable_view.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ENABLE_VIEW_H
#define PSTL_ENABLE_VIEW_H

#include "../../concepts/derived_from.h"
#include "../../concepts/same_as.h"
#include "../../iterator/concepts/contiguous_iterator.h"
#include "../../metaprogramming/cv_modifications/remove_cv.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/logical_operator/disjunction.h"
#include "../../metaprogramming/primary_type/is_class.h"
#include "../../metaprogramming/type_relations/is_convertible.h"
#include "../iterator_t.h"
#include "range.h"

namespace portable_stl {
namespace ranges {

  struct view_base {};

  /**
   * @brief Forward declaration
   */
  //   template<class derived_type>
  //   requires is_class_v<_Derived> &&same_as<_Derived, remove_cv_t<_Derived>> class view_interface;

  template<class derived_type,
           class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::conjunction<
             ::portable_stl::is_class<derived_type>,
             ::portable_stl::same_as<derived_type, ::portable_stl::remove_cv<derived_type>>>>>
  class view_interface;

  namespace ranges_helper {
    template<class t_type,
             class u_type,
             ::portable_stl::
               enable_if_bool_constant_t<::portable_stl::is_convertible<t_type *, view_interface<u_type> *>, void *>
             = nullptr>
    void is_derived_from_view_interface(t_type const *, view_interface<u_type> const *);

    template<class t_type> class is_derived_from_view_interface_impl final {
      template<class T1>::portable_stl::true_type  test(T1 const *, view_interface<T2> const *);
      template<class T1>::portable_stl::false_type test(...);

    public:
      using type = decltype(test<t_type>(static_cast<t_type *>(nullptr), static_cast<t_type *>(nullptr)));
    };

    template<class t_type>
    using enable_view_impl = ::portable_stl::disjunction<::portable_stl::derived_from<t_type, view_base>,
                                                         typename is_derived_from_view_interface_impl<t_type>::type>;
  } // namespace ranges_helper

  /**
   * @brief The alias is used to indicate whether a range is a view.
   * @tparam range_type
   */
  template<class range_type> using enable_view_bool_constant = ranges_helper::enable_view_impl<range_type>;

  /**
   * @brief The enable_view variable template is used to indicate whether a range is a view.
   * @tparam range_type
   */
  template<class range_type> constexpr inline bool enable_view = enable_view_bool_constant<range_type>{}();

} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_ENABLE_VIEW_H */
