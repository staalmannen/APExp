// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="expected_value_replace.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_EXPECTED_VALUE_REPLACE_H
#define PSTL_EXPECTED_VALUE_REPLACE_H

#include "../../memory/destroy_at.h"
#include "../../memory/storage_for.h"
#include "../../metaprogramming/type_properties/is_nothrow_destructible.h"
#include "../../metaprogramming/type_properties/is_nothrow_move_constructible.h"
#include "../../metaprogramming/type_properties/is_trivially_destructible.h"
#include "expected_value_move.h"

namespace std {
namespace utility_expected_helper {
  /**
   * @brief Helper class for replace storage value.
   * @tparam t_target_type the current type in target storage.
   * @tparam t_source_type the current source type.
   */
  template<class t_target_type, class t_source_type, class = ::std::is_trivially_destructible<t_target_type>>
  class expected_value_replace final {
  public:
    /**
     * @brief Relpace value in storage ( Version for non trivial destructible target ).
     * @tparam t_storage_type the type of storage.
     * @param target_storage the target storage.
     * @param source_value the source storage.
     */
    template<class t_storage_type>
    inline static void use(t_storage_type &target_storage, t_source_type &&source_value) noexcept(
      ::std::is_nothrow_destructible<t_target_type>{}()
      && ::std::is_nothrow_move_constructible<t_source_type>{}()) {
      // Destroy old value in storage.
      ::std::destroy_at(&::std::storage_for<t_target_type>(target_storage));
      // Move value to storage.
      ::std::utility_expected_helper::expected_value_move<t_source_type>::use(
        target_storage, ::std::move(source_value));
    }
  };

  /**
   * @brief Helper class for replace storage value.
   * @tparam t_target_type the current type in target storage.
   * @tparam t_source_type the current source type.
   */
  template<class t_target_type, class t_source_type>
  class expected_value_replace<t_target_type, t_source_type, ::std::true_type> final {
  public:
    /**
     * @brief Relpace value in storage ( Version for trivial destructible target ).
     * @tparam t_storage_type the type of storage.
     * @param target_storage the target storage.
     * @param source_value the source storage.
     */
    template<class t_storage_type>
    inline static void use(t_storage_type &target_storage, t_source_type &&source_value) noexcept(
      ::std::is_nothrow_destructible<t_target_type>{}()
      && ::std::is_nothrow_move_constructible<t_source_type>{}()) {
      // Destroy old value in storage.
      // Not need for trivial type.
      // Move value to storage.
      ::std::utility_expected_helper::expected_value_move<t_source_type>::use(
        target_storage, ::std::move(source_value));
    }
  };
} // namespace utility_expected_helper
} // namespace std

#endif // PSTL_EXPECTED_VALUE_REPLACE_H
