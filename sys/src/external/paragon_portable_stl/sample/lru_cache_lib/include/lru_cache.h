// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="lru_cache.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef LRU_CACHE_H
#define LRU_CACHE_H

enum {
  /**
   * @brief LRU Cache operation success.
   *
   */
  lcs_success,
  /**
   * @brief Needed version of library not supported.
   *
   */
  lcs_unknown_version,
  /**
   * @brief The value for the given key is missing.
   *
   */
  lcs_not_exist,
  /**
   * @brief Not enough memory to execute the function.
   *
   */
  lcs_not_memory
};

/**
 * @brief Status of LRU Cache operations
 *
 */
typedef unsigned char lru_cache_status;

/**
 * @brief LRU Library version type.
 *
 */
typedef unsigned int lru_version;

/**
 * @brief LRU Library Major version.
 *
 */
#define lru_version_major                     1

/**
 * @brief LRU Library Minor version.
 *
 */
#define lru_version_minor                     1

/**
 * @brief LRU Library build version.
 *
 */
#define lru_version_build                     1

/**
 * @brief Helper macros for calculate library version.
 *
 */
#define lru_version_calc(major, minor, build) ((((major)) << 8U) | (((minor)) << 8) + ((build)))

/**
 * @brief Options for lru_cache_get function.
 *
 */
struct lru_cache_get_options {
  /**
   * @brief LRU Cache library object [not null].
   *
   */
  struct lru_cache *instance;
  /**
   * @brief Key for get value ['C' String] [not null].
   *
   */
  char const       *key;
  /**
   * @brief Function result.
   * Pointer to storage for store value pointer [not null].
   * @warning Pointer valid only before put operation.
   */
  void const      **value;
};

/**
 * @brief Options for lru_cache_put function.
 *
 */
struct lru_cache_put_options {
  /**
   * @brief LRU Cache library object [not null].
   *
   */
  struct lru_cache *instance;
  /**
   * @brief Key for put value ['C' String] [not null].
   *
   */
  char const       *key;
  /**
   * @brief Value for put into cache [not null].
   * Will be copied when added.
   */
  void const       *value;
};

/**
 * @brief LRU Cache library instance.
 *
 */
struct lru_cache {
  /**
   * @brief Current library version.
   *
   */
  lru_version version;
  /**
   * @brief Destroy instance after work.
   *
   * @param instance the LRU Cache library instance.
   */
  void (*destroy)(struct lru_cache *instance);
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
  lru_cache_status (*get)(struct lru_cache_get_options const *options);
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
  lru_cache_status (*put)(struct lru_cache_put_options const *options);
};

/**
 * @brief Type for store size of memory block;
 *
 */
typedef unsigned long lru_size_t;

/**
 * @brief Memory management operations.
 *
 */
struct memory_operations {
  /**
   * @brief Allocate memory block.
   *
   * @param size the size of the new memory block [in bytes].
   *
   * @return pointer to the new memory block.
   */
  void *(*malloc)(lru_size_t size);
  /**
   * @brief Deallocate memory block.
   *
   * @param pointer the pointer to the memory block for deallocation.
   */
  void (*free)(void *pointer);
};

/**
 * @brief The type for store capacity value.
 *
 */
typedef unsigned int lru_capacity_type;

/**
 * @brief The type for store value object size.
 *
 */
typedef lru_size_t lru_value_size_type;

/**
 * @brief Options for Initialize LRU Cache library.
 *
 */
struct lru_initialize_options {
  /**
   * @brief Wanted library version.
   *
   */
  lru_version                     need_version;
  /**
   * @brief LRU Cache elements capacity.
   *
   */
  lru_capacity_type               capacity;
  /**
   * @brief Result LRU Cache library object [not null].
   *
   */
  struct lru_cache              **result_instance;
  /**
   * @brief the pointer to memory manager.
   *
   */
  struct memory_operations const *mm_instance;
  /**
   * @brief LRU Value object size;
   *
   */
  lru_value_size_type             value_size;
};

/**
 * @brief Initialize LRU Cache library.
 *
 * @param options options for initialization.
 *
 * @return lru_cache_status the status of operation.
 *
 * @retval lcs_success the operations success.
 * @retval lcs_not_memory can't allocate memory for initialize library.
 */
lru_cache_status lru_initialize_function(struct lru_initialize_options const *options);

/*
 * Helper functions.
 */

/**
 * @brief Initialize LRU Cache library (Helper function).
 *
 * @param result the value for store the pointer to the LRU Cache instance [not null].
 * @param capacity LRU Cache elements capacity.
 * @param mm_instance the pointer to memory manager.
 *
 * @return lru_cache_status the status of operation.
 *
 * @retval lcs_success the operations success.
 * @retval lcs_not_memory can't allocate memory for initialize library.
 */
inline static lru_cache_status lru_initialize(struct lru_cache **const        result,
                                              lru_capacity_type const         capacity,
                                              lru_value_size_type const       value_size,
                                              struct memory_operations const *mm_instance) {
  struct lru_initialize_options const options = {
    .need_version    = lru_version_calc(lru_version_major, lru_version_minor, lru_version_build),
    .capacity        = capacity,
    .result_instance = result,
    .mm_instance     = mm_instance,
    .value_size      = value_size,
  };
  return lru_initialize_function(&options);
}

/**
 * @brief Get value from cache.
 *
 * @param instance the LRU Cache library object [not null].
 * @param key the key for get value ['C' String] [not null].
 * @param value Function result. Pointer to storage for store value pointer [not null].
 * @warning the value pointer valid only before put operation.
 *
 * @return status of operation.
 *
 * @retval lcs_success the operations success.
 * @retval lcs_not_exist the value not exist. [*(options->value) == NULL]
 */
inline static lru_cache_status lru_get(
  struct lru_cache *const instance, char const *const key, void const **const value) {
  struct lru_cache_get_options const options = {.instance = instance, .key = key, .value = value};
  return instance->get(&options);
}

/**
 * @brief Put value into cache.
 *
 * @param instance the LRU Cache library object [not null].
 * @param key the key for put value ['C' String] [not null].
 * @param value Value for put into cache [not null]. Will be copied when added.
 *
 * @return status of operation.
 *
 * @retval lcs_success the operations success.
 * @retval lcs_not_memory can't allocate memory for store value.
 */
inline static lru_cache_status lru_put(
  struct lru_cache *const instance, char const *const key, void const *const value) {
  struct lru_cache_put_options const options = {.instance = instance, .key = key, .value = value};
  return instance->put(&options);
}

/**
 * @brief Destroy instance after work.
 *
 * @param instance the LRU Cache library instance.
 */
inline static void lru_destroy(struct lru_cache *const instance) {
  instance->destroy(instance);
}

#endif // LRU_CACHE_H
