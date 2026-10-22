// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_equality_comparable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_EQUALITY_COMPARABLE_H
#define PSTL_IS_EQUALITY_COMPARABLE_H

#include "../metaprogramming/cv_modifications/remove_cv.h"
#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/disjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../metaprogramming/primary_type/is_integral.h"
#include "../metaprogramming/primary_type/is_void.h"
#include "../metaprogramming/type_properties/is_signed.h"
#include "../metaprogramming/type_relations/is_same.h"
#include "../utility/general/declval.h"

namespace portable_stl {
namespace concept_helper {
  template<class t_type, class t_other_type, class = void> class is_equality_comparable final {
  public:
    using type = ::portable_stl::false_type;
  };

  template<class t_type, class t_other_type>
  class is_equality_comparable<
    t_type,
    t_other_type,
    ::portable_stl::void_t<decltype(::portable_stl::declval<t_type>() == ::portable_stl::declval<t_other_type>())>>
    final {
  public:
    using type = ::portable_stl::true_type;
  };

  // A type is_trivially_equality_comparable if the expression `a == b` is equivalent to `::memcmp(&a, &b, sizeof(T))`
  // (with `a` and `b` being of type `T`). For the case where we compare two object of the same type, we can use
  // __is_trivially_equality_comparable. We have special-casing for pointers which point to the same type ignoring
  // cv-qualifications and comparing to void-pointers.
  //
  // The following types are not trivially equality comparable:
  // floating-point types: different bit-patterns can compare equal. (e.g 0.0 and -0.0)
  // enums: The user is allowed to specialize operator== for enums
  // pointers that don't have the same type (ignoring cv-qualifiers): pointers to virtual bases are equality comparable,
  // but don't have the same bit-pattern. An exception to this is comparing to a void-pointer. There the bit-pattern is
  // always compared.

  template<class t_type, class t_other_type, class = void>
  class is_trivially_equality_comparable_impl final {
  public:
    using type = ::portable_stl::false_type;
  };

  template<class t_type> class is_trivially_equality_comparable_impl<t_type, t_type> final {
  public:
    using type = ::portable_stl::is_integral<t_type>;
  };

  template<class t_type, class t_other_type>
  class is_trivially_equality_comparable_impl<t_type,
                                              t_other_type,
                                              ::portable_stl::enable_if_bool_constant_t<::portable_stl::conjunction<
                                                ::portable_stl::is_integral<t_type>,
                                                ::portable_stl::is_integral<t_other_type>,
                                                ::portable_stl::negation<::portable_stl::is_same<t_type, t_other_type>>,
                                                ::portable_stl::is_same<is_signed<t_type>, is_signed<t_other_type>>,
                                                ::portable_stl::bool_constant<sizeof(t_type) == sizeof(t_other_type)>>>>
    final {
  public:
    using type = ::portable_stl::true_type;
  };

  template<class t_type> class is_trivially_equality_comparable_impl<t_type *, t_type *> final {
  public:
    using type = ::portable_stl::true_type;
  };

  template<class t_type, class t_other_type>
  class is_trivially_equality_comparable_impl<t_type *, t_other_type *> final {
  public:
    using type = ::portable_stl::conjunction<
      is_equality_comparable<t_type *, t_other_type *>,
      ::portable_stl::disjunction<
        ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, ::portable_stl::remove_cv_t<t_other_type>>,
        ::portable_stl::is_void<t_type>,
        ::portable_stl::is_void<t_other_type>>>;
  };
} // namespace concept_helper

template<class t_type, class t_other_type>
using is_trivially_equality_comparable =
  typename concept_helper::is_trivially_equality_comparable_impl<::portable_stl::remove_cv_t<t_type>,
                                                 ::portable_stl::remove_cv_t<t_other_type>>::type;

} // namespace portable_stl

#endif // PSTL_IS_EQUALITY_COMPARABLE_H
