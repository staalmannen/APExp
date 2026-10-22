// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="has_iterator_category_convertible_to.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_HAS_ITERATOR_CATEGORY_CONVERTIBLE_TO_H
#define PSTL_HAS_ITERATOR_CATEGORY_CONVERTIBLE_TO_H

#include "../../iterator/concepts/iter_concept.h"
#include "../../iterator/iterator_traits.h"
#include "../helper/integral_constant.h"
#include "../type_relations/is_convertible.h"

namespace portable_stl {
namespace type_traits_helper {
  template<class t_iter, class t_checked_tag, class = iterator_helper::has_iterator_category_type<t_iter>>
  class has_iterator_category_convertible_to final {
  public:
    using type = ::portable_stl::is_convertible<typename ::portable_stl::iterator_traits<t_iter>::iterator_category,
                                                t_checked_tag>;
  };

  template<class t_iter, class t_checked_tag>
  class has_iterator_category_convertible_to<t_iter, t_checked_tag, ::portable_stl::false_type> final {
  public:
    using type = ::portable_stl::false_type;
  };
} // namespace type_traits_helper
} // namespace portable_stl

#endif // PSTL_HAS_ITERATOR_CATEGORY_CONVERTIBLE_TO_H
