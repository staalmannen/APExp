// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="expected_swap_helper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_EXPECTED_SWAP_HELPER_H
#define PSTL_EXPECTED_SWAP_HELPER_H

#include "../general/make_exception_guard.h"
#include "expected_value_replace.h"

namespace std {
namespace utility_expected_helper {
  /**
   * @brief Helper class for swap value and error ( without exceptions )
   * @tparam t_value_type the value type.
   * @tparam t_error_type the error type.
   * @tparam
   */
  template<class t_value_type,
           class t_error_type,
           class = ::std::conjunction<::std::is_nothrow_move_constructible<t_value_type>,
                                               ::std::is_nothrow_destructible<t_value_type>,
                                               ::std::is_nothrow_move_constructible<t_error_type>,
                                               ::std::is_nothrow_destructible<t_error_type>>>
  class expected_swap_helper final {
  public:
    /**
     * @brief Swap function.
     * @tparam t_storage_type the storage type.
     * @param storage_value the value storage.
     * @param storage_error the error storavge.
     */
    template<class t_storage_type>
    inline static void use(t_storage_type &storage_value, t_storage_type &storage_error) noexcept {
      // Move value to temprary storage.
      t_value_type temp{::std::move(::std::storage_for<t_value_type>(storage_value))};

      // Replace value with error.
      ::std::utility_expected_helper::expected_value_replace<t_value_type, t_error_type>::use(
        storage_value, ::std::move(::std::storage_for<t_error_type>(storage_error)));

      // Replace error with temprary value.
      ::std::utility_expected_helper::expected_value_replace<t_error_type, t_value_type>::use(
        storage_error, ::std::move(temp));
    }
  };

  /**
   * @brief Helper class for swap value and error ( with exceptions )
   * @tparam t_value_type the value type.
   * @tparam t_error_type the error type.
   */
  template<class t_value_type, class t_error_type>
  class expected_swap_helper<t_value_type, t_error_type, ::std::false_type> final {
  public:
    /**
     * @brief Swap function.
     * @tparam t_storage_type the storage type.
     * @param storage_value the value storage.
     * @param storage_error the error storavge.
     */
    template<class t_storage_type>
    inline static void use(t_storage_type &storage_value, t_storage_type &storage_error) noexcept(false) {
      // Move value to temprary storage.
      t_value_type temp{::std::move(::std::storage_for<t_value_type>(storage_value))};

      auto value_guard = ::std::make_exception_guard([&storage_value, &temp]() -> void {
        ::std::utility_expected_helper::expected_value_move<t_value_type>::use(storage_value,
                                                                                        ::std::move(temp));
      });

      // Replace value with error.
      ::std::utility_expected_helper::expected_value_replace<t_value_type, t_error_type>::use(
        storage_value, ::std::move(::std::storage_for<t_error_type>(storage_error)));

      auto error_guard = ::std::make_exception_guard([&storage_value, &storage_error]() -> void {
        ::std::utility_expected_helper::expected_value_move<t_error_type>::use(
          storage_error, ::std::move(::std::storage_for<t_error_type>(storage_value)));
      });

      // Replace error with temprary value.
      ::std::utility_expected_helper::expected_value_replace<t_error_type, t_value_type>::use(
        storage_error, ::std::move(temp));

      error_guard.commit();
      value_guard.commit();
    }
  };
} // namespace utility_expected_helper

} // namespace std

#endif // PSTL_EXPECTED_SWAP_HELPER_H
