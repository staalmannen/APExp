// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="rebind_pointer.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_REBIND_POINTER_H
#define PSTL_REBIND_POINTER_H

#include "pointer_traits.h"

namespace portable_stl {

namespace pointer_traits_helper {
template<class t_type_from, class t_type_to> class rebind_pointer_impl final {
  /**
   * @brief Additional layer of indirection for msvc.
   */
  using t_pointer_traits = ::portable_stl::pointer_traits<t_type_from>;

public:
  using type = typename t_pointer_traits::template rebind<t_type_to>;
};
}

/**
 * @brief Convenience alias for rebinding pointers.
 *
 * @tparam t_type_from
 * @tparam t_type_to
 */
template<class t_type_from, class t_type_to>
using rebind_pointer_t = typename pointer_traits_helper::rebind_pointer_impl<t_type_from, t_type_to>::type;

} // namespace portable_stl

#endif // PSTL_REBIND_POINTER_H
