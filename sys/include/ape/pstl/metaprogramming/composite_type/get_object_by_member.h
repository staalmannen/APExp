// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="get_object_by_member.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_DBBCA7FA_6D1E_460A_A122_9013826FE31D
#define PSTL_DBBCA7FA_6D1E_460A_A122_9013826FE31D

namespace portable_stl {
namespace composite_type_helper {
  template<class t_member_type, class = void> class get_object final {};

  template<class t_member_type, class t_object_type> class get_object<t_member_type t_object_type::*> final {
  public:
    using type = t_object_type;
  };
} // namespace composite_type_helper

template<class t_type> using get_object_by_member_t = typename composite_type_helper::get_object<t_type>::type;
} // namespace portable_stl

#endif /* PSTL_DBBCA7FA_6D1E_460A_A122_9013826FE31D */
