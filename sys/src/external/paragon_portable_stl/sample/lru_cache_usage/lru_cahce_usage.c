// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="lru_cahce_usage.c"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "lru_cache.h"

/**
 * @brief Current capacity for LRU cache.
 *
 */
#define LRU_WORK_CAPACIRY 3

/**
 * @brief Helper function for get value from cache and show it.
 *
 * @param instance the LRU Cache library object.
 * @param key the key for value get.
 */
inline static void get_value(struct lru_cache *const instance, char const *const key) {
  void const *result_value = NULL;
  if (lcs_success == lru_get(instance, key, &result_value)) {
    printf("key: '%s', value: %u\n", key, *((unsigned int const *)result_value));
  }
}

/**
 * @brief Work with cache.
 * Add values ​​in the amount of LRU_WORK_CAPACIRY + 1 and try to get each value.
 * Add another value and try to get a long-unused value and the last used one.
 *
 * @param instance the LRU Cache library object.
 */
inline static void work_with_cache(struct lru_cache *const instance) {
  unsigned int value = 1U;
  if (lcs_success != lru_put(instance, "one", &value)) {
    return;
  }

  ++value;
  if (lcs_success != lru_put(instance, "two", &value)) {
    return;
  }

  ++value;
  if (lcs_success != lru_put(instance, "three", &value)) {
    return;
  }

  ++value;
  if (lcs_success != lru_put(instance, "four", &value)) {
    return;
  }

  get_value(instance, "one");
  get_value(instance, "two");
  get_value(instance, "three");
  get_value(instance, "four");

  ++value;
  if (lcs_success != lru_put(instance, "five", &value)) {
    return;
  }

  get_value(instance, "two");
  get_value(instance, "four");
}

/**
 * @brief Main sample function.
 * Initialize cache library, execute work with cache, and clean after work.
 *
 * @return status.
 */
int main() {
  struct memory_operations const mm_instance = {.malloc = malloc, .free = free};
  struct lru_cache              *instance    = NULL;
  if (lcs_success == lru_initialize(&instance, LRU_WORK_CAPACIRY, sizeof(unsigned int), &mm_instance)) {
    work_with_cache(instance);
    lru_destroy(instance);
  }

  return 0;
}
