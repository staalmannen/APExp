// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="expected_value_move.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_EXPECTED_VALUE_MOVE_H
#define PSTL_EXPECTED_VALUE_MOVE_H

#include "../../memory/destroy_at.h"
#include "../../memory/memcpy.h"
#include "../../memory/storage_for.h"
#include "../../metaprogramming/type_properties/is_nothrow_destructible.h"
#include "../../metaprogramming/type_properties/is_nothrow_move_constructible.h"
#include "../../metaprogramming/type_properties/is_trivially_copyable.h"

namespace std {
namespace utility_expected_helper {
  /**
   * @brief Helper class for move storage value.
   * @tparam t_source_type the current source type.
   */
  template<class t_source_type, class = ::std::is_trivially_copyable<t_source_type>>
  class expected_value_move final {
  public:
    /**
     * @brief Move value in storage ( Version for non trivial copyable source ).
     * @tparam t_storage_type the type of storage.
     * @param target_storage the target storage.
     * @param source_value the source storage.
     */
    template<class t_storage_type>
    inline static void use(t_storage_type &target_storage, t_source_type &&source_value) noexcept(
      ::std::is_nothrow_move_constructible<t_source_type>{}()) {
      // Move value to storage.
      static_cast<void>(::std::construct_at(&::std::storage_for<t_source_type>(target_storage),
                                                     ::std::move(source_value)));
    }
  };

  /**
   * @brief Helper class for replace storage value.
   * @tparam t_source_type the current source type.
   */
  template<class t_source_type> class expected_value_move<t_source_type, ::std::true_type> final {
  public:
    /**
     * @brief Move value in storage ( Version for trivial copyable source ).
     * @tparam t_storage_type the type of storage.
     * @param target_storage the target storage.
     * @param source_value the source storage.
     */
    template<class t_storage_type>
    inline static void use(t_storage_type &target_storage, t_source_type &&source_value) noexcept(
      ::std::is_nothrow_move_constructible<t_source_type>{}()) {
      // Move value to storage.
      static_cast<void>(::std::memcpy(
        ::std::voidify(target_storage), ::std::voidify(source_value), sizeof(source_value)));
    }
  };
} // namespace utility_expected_helper
} // namespace std

#endif // PSTL_EXPECTED_VALUE_MOVE_H
