// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="lru_cache_v1_instance.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef LRU_CACHE_V1_INSTANCE_H
#define LRU_CACHE_V1_INSTANCE_H

#include "portable_stl/common/size_t.h"
#include "portable_stl/error/portable_stl_error.h"
#include "portable_stl/memory/allocator_posix.h"
#include "portable_stl/memory/allocator_traits.h"
#include "portable_stl/memory/memcpy.h"
#include "portable_stl/string/string.h"
#include "portable_stl/utility/expected/expected.h"
#include "portable_stl/utility/general/in_place_t.h"
#include "portable_stl/vector/vector.h"

extern "C" {
#include "../include/lru_cache.h"
}

#include "lru_storage.h"

namespace lru_cache_v1 {
/**
 * @brief Version of current implementation.
 *
 */
constexpr unsigned int version{lru_version_calc(lru_version_major, lru_version_minor, lru_version_build)};

/**
 * @brief Implementation version 1 of lru_cache library.
 *
 */
class lru_cache_v1_instance final : public lru_cache {
  /**
   * @brief Convert portable stl status to lru_cache status.
   *
   * @param error the portable stl status.
   * @return lru_cache_status
   */
  static lru_cache_status error_convert(portable_stl::portable_stl_error const status) noexcept {
    switch (status) {
      case portable_stl::portable_stl_error::not_exists:
        return lcs_not_exist;
      case portable_stl::portable_stl_error::allocate_error:
        return lcs_not_memory;
      default:
        return lcs_not_memory;
    }
  }

  /**
   * @brief Destroy instance after work.
   *
   * @param instance the LRU Cache library instance.
   */
  static void public_destroy(struct lru_cache *const instance) {
    static_cast<lru_cache_v1_instance *>(instance)->destroy();
  }

  /**
   * @brief Get value from cache.
   *
   * @param options the function options.
   *
   * @return status of operation.
   *
   * @retval lcs_success the operations success.
   * @retval lcs_not_exist the value not exist. [*(options->value) == NULL]
   */
  static lru_cache_status public_get(struct lru_cache_get_options const *const options) {
    return static_cast<lru_cache_v1_instance *>(options->instance)->get(options->key, options->value);
  }

  /**
   * @brief Put value into cache.
   *
   * @param options the function options.
   *
   * @return status of operation.
   *
   * @retval lcs_success the operations success.
   * @retval lcs_not_memory can't allocate memory for store value.
   */
  static lru_cache_status public_put(struct lru_cache_put_options const *const options) {
    return static_cast<lru_cache_v1_instance *>(options->instance)->put(options->key, options->value);
  }

  /**
   * @brief Memory allocator for the key storage type.
   *
   */
  using t_key_allocator = portable_stl::allocator_posix<::portable_stl::char_t>;

  /**
   * @brief The key storage type.
   *
   */
  using t_key = portable_stl::
    basic_string<::portable_stl::char_t, ::portable_stl::char_traits<::portable_stl::char_t>, t_key_allocator>;

  using t_get_key = typename t_key::view_type;

  /**
   * @brief Memory allocator for the value storage type.
   *
   */
  using t_value_allocator = portable_stl::allocator_posix<unsigned char>;

  /**
   * @brief The value storage type.
   *
   */
  using t_value = portable_stl::vector<unsigned char, t_value_allocator>;

  /**
   * @brief Type for Cache storage object.
   *
   */
  using t_storage
    = lru_storage::lru_storage<t_key, t_value, portable_stl::allocator_posix<lru_cache_v1_instance>, t_get_key>;
  /**
   * @brief Cache storage object.
   *
   */
  t_storage m_storage;

  /**
   * @brief Size of value object.
   *
   */
  portable_stl::size_t m_value_size;

public:
  /**
   * @brief Construct a new lru cache v1 instance library object.
   *
   * @param capacity the maximum cache capacity.
   * @param value_size the size of value storage.
   * @param allocator the allocator for memory management.
   */
  constexpr lru_cache_v1_instance(portable_stl::size_t const                                  capacity,
                                  portable_stl::size_t const                                  value_size,
                                  portable_stl::allocator_posix<lru_cache_v1_instance> const &allocator)
      : lru_cache(
          {.version = lru_cache_v1::version, .destroy = &public_destroy, .get = &public_get, .put = &public_put})
      , m_storage(capacity, allocator)
      , m_value_size(value_size) {
  }

  /**
   * @brief Initialize lru cache v1 instance library object.
   *
   * @param capacity the maximum cache capacity.
   * @param value_size the size of value storage.
   * @param memory_operations the vector with pointers to functions for memory management.
   * @return pointer to lru cache v1 instance library object or error.
   */
  static portable_stl::expected<struct lru_cache *, lru_cache_status> initialize(
    portable_stl::size_t capacity, portable_stl::size_t value_size, struct memory_operations const *memory_operations) {
    using t_allocator = portable_stl::allocator_posix<lru_cache_v1_instance>;
    t_allocator allocator{
      {.malloc = memory_operations->malloc, .free = memory_operations->free}
    };
    lru_cache_v1_instance *memory_holder(portable_stl::allocator_traits<t_allocator>::allocate(allocator, 1U));
    if (nullptr == memory_holder) {
      return portable_stl::unexpected<lru_cache_status>{lcs_not_memory};
    }
    return {portable_stl::in_place_t{}, portable_stl::construct_at(memory_holder, capacity, value_size, allocator)};
  }

  /**
   * @brief Destroy instance after work.
   *
   * @param instance the LRU Cache library instance.
   */
  void destroy() noexcept {
    auto allocator(m_storage.get_allocator());
    portable_stl::destroy_at(this);
    portable_stl::allocator_traits<portable_stl::allocator_posix<lru_cache_v1_instance>>::deallocate(
      allocator, this, 1U);
  }

  /**
   * @brief Get value from cache.
   *
   * @param options the function options.
   *
   * @return status of operation.
   *
   * @retval lcs_success the operations success.
   * @retval lcs_not_exist the value not exist. [*(options->value) == NULL]
   */
  lru_cache_status get(char const *key, void const **value) {
    return m_storage.get(t_get_key{key})
      .and_then([value](auto result) -> portable_stl::expected<void, portable_stl::portable_stl_error> {
        *value = result.get().data();
        return {};
      })
      .transform_error(&error_convert)
      .error_or(lcs_success);
  }

  /**
   * @brief Put value into cache.
   *
   * @param options the function options.
   *
   * @return status of operation.
   *
   * @retval lcs_success the operations success.
   * @retval lcs_not_memory can't allocate memory for store value.
   */
  lru_cache_status put(char const *const key, void const *const value) {
    return t_key::make_string(key, {m_storage.get_allocator()})
      .and_then([this, value](t_key key) {
        return t_value::make_vector(m_value_size, {m_storage.get_allocator()})
          .and_then([this, value, key_value = ::portable_stl::move(key)](
                      t_value value_storage) -> portable_stl::expected<void, portable_stl::portable_stl_error> {
            portable_stl::memcpy(value_storage.data(), value, m_value_size);
            return m_storage.put(portable_stl::move(key_value), portable_stl::move(value_storage));
          });
      })
      .transform_error(&error_convert)
      .error_or(lcs_success);
  }
};

/**
 * @brief Current library instance for version 1.
 *
 */
using instance = lru_cache_v1_instance;
} // namespace lru_cache_v1

#endif // LRU_CACHE_V1_INSTANCE_H
