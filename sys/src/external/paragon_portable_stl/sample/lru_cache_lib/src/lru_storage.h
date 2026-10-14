// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="lru_storage.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef LRU_STORAGE_H
#define LRU_STORAGE_H

#include "portable_stl/error/portable_stl_error.h"
#include "portable_stl/functional/less.h"
#include "portable_stl/list/list.h"
#include "portable_stl/map/map.h"
#include "portable_stl/memory/allocator_traits.h"
#include "portable_stl/utility/expected/expected.h"
#include "portable_stl/utility/expected/unexpected.h"
#include "portable_stl/utility/general/functional/reference_wrapper.h"
#include "portable_stl/utility/tuple/fwd_decl_tuple.h"

namespace lru_storage {
/**
 * @brief LRU Cache implementation.
 *
 * @tparam t_key the type for the key.
 * @tparam t_value the type for the value.
 * @tparam t_error the type for the error.
 * @tparam t_not_exist the value of error then value not exist.
 * @tparam t_allocator the memory allocator.
 */
template<typename t_key, typename t_value, class t_allocator, typename t_get_key = t_key> class lru_storage final {
  /**
   * @brief Storage for cache values.
   *
   */
  template<class t_other_key> using t_storage = portable_stl::tuple<t_other_key, t_value>;

  /**
   * @brief Allocator type for list storage.
   *
   */
  using t_list_allocator =
    typename portable_stl::allocator_traits<t_allocator>::template rebind_alloc<t_storage<t_key>>;

  /**
   * @brief List for implement LRU cache.
   *
   */
  using t_list = portable_stl::list<t_storage<t_key>, t_list_allocator>;

  /**
   * @brief Allocator type for tree storage.
   *
   */
  using t_map_allocator = typename portable_stl::allocator_traits<t_allocator>::template rebind_alloc<
    ::portable_stl::tuple<t_get_key const, typename t_list::iterator>>;

  /**
   * @brief Tree for implement LRU cache.
   *
   */
  using t_map = portable_stl::map<t_get_key, typename t_list::iterator, portable_stl::less<t_get_key>, t_map_allocator>;

  /**
   * @brief The type for storage cache size.
   *
   */
  using cache_size_t = portable_stl::size_t;

  /**
   * @brief The type for storage value size.
   *
   */
  using value_size_t = portable_stl::size_t;

  /**
   * @brief List part of LRU cache.
   *
   */
  t_list m_list;

  /**
   * @brief Tree part of LRU cache.
   *
   */
  t_map m_map;

  /**
   * @brief Cache size in items.
   *
   */
  cache_size_t m_cache_size;

  /**
   * @brief Move current recort to top of cache.
   *
   * @param it iterator with current record.
   */
  void move_front(typename t_map::iterator &it) {
    auto temp(portable_stl::move(*portable_stl::get<1>(*it)));
    m_list.erase(portable_stl::get<1>(*it));
    m_list.push_front(temp);
    portable_stl::get<1>(*it) = m_list.begin();
  }

public:
  /**
   * @brief Get the allocator object.
   *
   * @return t_allocator
   */
  t_allocator get_allocator() const noexcept {
    return {m_list.get_allocator()};
  }

  /**
   * @brief Construct LRU cache storage.
   *
   */
  constexpr lru_storage(cache_size_t cache_size, t_allocator const &allocator)
      : m_list(t_list_allocator{allocator}), m_map(t_map_allocator{allocator}), m_cache_size(cache_size) {
  }

  /**
   * @brief Get element from cache.
   *
   * @param key the key for search element.
   * @return value or error if element not exist.
   */
  portable_stl::expected<portable_stl::reference_wrapper<t_value const>, portable_stl::portable_stl_error> get(
    t_get_key key) {
    auto it(m_map.find(key));
    if (it == m_map.end()) {
      return portable_stl::unexpected<portable_stl::portable_stl_error>{portable_stl::portable_stl_error::not_exists};
    }
    move_front(it);
    return {portable_stl::in_place_t{},
            portable_stl::get<1>(*portable_stl::get<1>(*(typename t_map::const_iterator{it})))};
  }

  /**
   * @brief Put element into cache.
   *
   * @param key the key for search element.
   * @param value the value for put into cache.
   * @return Status of operation.
   */
  portable_stl::expected<void, portable_stl::portable_stl_error> put(t_key key, t_value value) {
    auto it(m_map.find(t_get_key{key}));
    if (it == m_map.end()) {
      if (m_list.size() == m_cache_size) {
        m_map.erase(portable_stl::get<0>(m_list.back()));
        m_list.pop_back();
      }
      return m_list.emplace_front(portable_stl::move(key), portable_stl::move(value)).and_then([this](auto element) {
        return m_map.emplace(portable_stl::get<0>(element.get()), m_list.begin())
          .or_else([this](portable_stl::portable_stl_error error)
                     -> ::portable_stl::expected<::portable_stl::tuple<typename t_map::iterator, bool>,
                                                 ::portable_stl::portable_stl_error> {
            m_list.pop_front();
            return portable_stl::unexpected<portable_stl::portable_stl_error>{error};
          })
          .transform_void();
      });
    } else {
      portable_stl::get<1>(*(portable_stl::get<1>(*it))) = portable_stl::move(value);
    }
    move_front(it);
    return {};
  }
};
} // namespace lru_storage

#endif // LRU_STORAGE_H
