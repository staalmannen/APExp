// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_detected.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_DETECTED_H
#define PSTL_IS_DETECTED_H

#include "../helper/integral_constant.h"
#include "../helper/nat.h"
#include "void_t.h"

namespace portable_stl {
namespace metaprogramming_helper {

  /**
   * @brief
   */
  class nonesuch final : private portable_stl::nat_class { // make nonesuch "not an aggregate"
  public:
    /**
     * @brief Deleteed.
     */
    ~nonesuch()                      = delete;
    /**
     * @brief Deleteed.
     */
    nonesuch(nonesuch const &)       = delete;
    /**
     * @brief Deleteed.
     */
    void operator=(nonesuch const &) = delete;
    /**
     * @brief Deleteed.
     */
    nonesuch(nonesuch &&)            = delete;
    /**
     * @brief Deleteed.
     */
    void operator=(nonesuch &&)      = delete;
  };

  /**
   * @brief is_detected implementation.
   * @tparam default_t
   * @tparam alwaysVoid
   * @tparam ...args_t
   */
  template<class default_t, class alwaysVoid, template<class...> class op_t, class... args_t> class detector final {
  public:
    /**
     * @brief Integral result type.
     */
    using value_t = ::portable_stl::false_type;
    /**
     * @brief Result type.
     */
    using type    = default_t;
  };

  /**
   * @brief is_detected implementation.
   * @tparam default_t
   * @tparam op_t
   * @tparam args_t
   */
  template<class default_t, template<class...> class op_t, class... args_t>
  class detector<default_t, ::portable_stl::void_t<op_t<args_t...>>, op_t, args_t...> final {
  public:
    /**
     * @brief Integral result type.
     */
    using value_t = ::portable_stl::true_type;
    /**
     * @brief Result type.
     */
    using type    = op_t<args_t...>;
  };
} // namespace metaprogramming_helper

/**
 * @brief
 * @tparam op_t
 * @tparam args_t
 */
template<template<class...> class op_t, class... args_t>
using is_detected =
  typename metaprogramming_helper::detector<metaprogramming_helper::nonesuch, void, op_t, args_t...>::value_t;

/**
 * @brief
 * @tparam op_t
 * @tparam args_t
 */
template<template<class...> class op_t, class... args_t>
using detected_t =
  typename metaprogramming_helper::detector<metaprogramming_helper::nonesuch, void, op_t, args_t...>::type;

/**
 * @brief
 * @tparam default_t
 * @tparam op_t
 * @tparam args_t
 */
template<class default_t, template<class...> class op_t, class... args_t>
using detected_or = metaprogramming_helper::detector<default_t, void, op_t, args_t...>;

} // namespace portable_stl

#endif /* PSTL_IS_DETECTED_H */
