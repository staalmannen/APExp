// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="can_extract_map_key.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CAN_EXTRACT_MAP_KEY_H
#define PSTL_CAN_EXTRACT_MAP_KEY_H

#include "../../utility/tuple/tuple.h"
#include "../cv_modifications/remove_const.h"
#include "../other_transformations/conditional_bool_constant.h"
#include "../other_transformations/remove_cref.h"
#include "../type_relations/is_same.h"

namespace portable_stl {

// These traits are used in rbtree and __hash_table
class extract_key_fail_tag  final {};
class extract_key_self_tag  final {};
class extract_key_first_tag final {};

template<class t_value_type, class t_key, class t_raw_value_type = ::portable_stl::remove_cref_t<t_value_type>>
struct can_extract_key {
public:
  using type = ::portable_stl::conditional_bool_constant_t<::portable_stl::is_same<t_raw_value_type, t_key>,
                                                           extract_key_self_tag,
                                                           extract_key_fail_tag>;
};

template<class t_pair, class t_key, class t_first, class t_second>
struct can_extract_key<t_pair, t_key, ::portable_stl::tuple<t_first, t_second>> {
public:
  using type = ::portable_stl::conditional_bool_constant_t<
    ::portable_stl::is_same<::portable_stl::remove_const_t<t_first>, t_key>,
    extract_key_first_tag,
    extract_key_fail_tag>;
};

// can_extract_map_key uses true_type/false_type instead of the tags.
// It returns true if t_key != t_container_value_type (the container is a map not a set)
// and t_value_type == t_key.
template<class t_value_type,
         class t_key,
         class t_container_value_type,
         class t_raw_value_type = ::portable_stl::remove_cref_t<t_value_type>>
struct can_extract_map_key final {
public:
  using type = ::portable_stl::is_same<t_raw_value_type, t_key>;
};

// This specialization returns extract_key_fail_tag for non-map containers
// because t_key == t_container_value_type
template<class t_value_type, class t_key, class t_raw_value_type>
struct can_extract_map_key<t_value_type, t_key, t_key, t_raw_value_type> {
public:
  using type = ::portable_stl::false_type;
};

} // namespace portable_stl

#endif // PSTL_CAN_EXTRACT_MAP_KEY_H
