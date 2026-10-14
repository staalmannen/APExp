// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="lru_cache.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
extern "C" {
#include "lru_cache.h"
}

#include "lru_cache_v1_instance.h"

/**
 * @brief Initialize LRU Cache library.
 *
 * @param options options for initialization.
 *
 * @return lru_cache_status the status of operation.
 *
 * @retval lcs_success the operations success.
 * @retval lcs_not_memory can't allocate memory for initialize library.
 * @retval lcs_unknown_version the need version not supported by current library.
 */
lru_cache_status lru_initialize_function(struct lru_initialize_options const *options) {
  constexpr unsigned int version_mask{0xFFU << 16U};
  // Select library instance for needed version.
  if ((options->need_version & version_mask) == (lru_cache_v1::version & version_mask)) {
    return lru_cache_v1::instance::initialize(options->capacity, options->value_size, options->mm_instance)
      .and_then([&options](struct lru_cache *const value) -> portable_stl::expected<void, lru_cache_status> {
        *(options->result_instance) = value;
        return {};
      })
      .error_or(lcs_success);
  } else {
    return lcs_unknown_version;
  }
  return lcs_unknown_version;
}
