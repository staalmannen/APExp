// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_array_modifications.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/metaprogramming/array_modifications/remove_all_extents.h"
#include "portable_stl/metaprogramming/array_modifications/remove_extent.h"
#include "test_debug_helper.h"

TEST(metaprogramming_array_modifications, remove_all_extents) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Helper type
     */
    using helper = typename ::portable_stl::remove_all_extents<std::int32_t>::type;
    ASSERT_TRUE((std::is_same<helper, std::int32_t>{}));
  }
  {
    /**
     * @brief Helper type
     */
    using helper = typename ::portable_stl::remove_all_extents<std::int32_t[1]>::type;
    ASSERT_TRUE((std::is_same<helper, std::int32_t>{}));
  }
  {
    /**
     * @brief Helper type
     */
    using helper = typename ::portable_stl::remove_all_extents<std::int32_t[][1]>::type;
    ASSERT_TRUE((std::is_same<helper, std::int32_t>{}));
  }

  {
    /**
     * @brief Helper type
     */
    using helper = ::portable_stl::remove_all_extents_t<std::int32_t>;
    ASSERT_TRUE((std::is_same<helper, std::int32_t>{}));
  }
  {
    /**
     * @brief Helper type
     */
    using helper = ::portable_stl::remove_all_extents_t<std::int32_t[1]>;
    ASSERT_TRUE((std::is_same<helper, std::int32_t>{}));
  }
  {
    /**
     * @brief Helper type
     */
    using helper = ::portable_stl::remove_all_extents_t<std::int32_t[][1]>;
    ASSERT_TRUE((std::is_same<helper, std::int32_t>{}));
  }

  ASSERT_TRUE((std::is_same<::portable_stl::remove_all_extents_t<std::int32_t>, std::int32_t>{}));
  ASSERT_TRUE((std::is_same<::portable_stl::remove_all_extents_t<std::int32_t[1]>, std::int32_t>{}));
  ASSERT_TRUE((std::is_same<::portable_stl::remove_all_extents_t<std::int32_t[1][1]>, std::int32_t>{}));
  ASSERT_TRUE((std::is_same<::portable_stl::remove_all_extents_t<std::int32_t[][1]>, std::int32_t>{}));
}

TEST(metaprogramming_array_modifications, remove_extent) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Helper type
     */
    using helper = typename ::portable_stl::remove_extent<std::uint32_t[4]>::type;
    ASSERT_TRUE((::std::is_same<helper, std::uint32_t>{}));
  }
  {
    /**
     * @brief Helper type
     */
    using helper = typename ::portable_stl::remove_extent<std::uint32_t[]>::type;
    ASSERT_TRUE((::std::is_same<helper, std::uint32_t>{}));
  }
  {
    using helper = typename ::portable_stl::remove_extent<std::uint32_t[]>::type;
    ASSERT_TRUE((::std::is_same<helper, std::uint32_t>{}));
  }

  ASSERT_TRUE((::std::is_same<std::uint32_t, ::portable_stl::remove_extent_t<std::uint32_t[]>>{}));
  ASSERT_TRUE((::std::is_same<std::uint32_t, ::portable_stl::remove_extent_t<std::uint32_t[1]>>{}));
  ASSERT_TRUE((::std::is_same<std::uint32_t[1], ::portable_stl::remove_extent_t<std::uint32_t[2][1]>>{})); // ?
  ASSERT_TRUE((::std::is_same<std::uint32_t[1], ::portable_stl::remove_extent_t<std::uint32_t[][1]>>{}));  // ?
}
