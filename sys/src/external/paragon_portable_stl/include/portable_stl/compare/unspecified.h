// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="unspecified.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_UNSPECIFIED_H
#define PSTL_UNSPECIFIED_H
#include "../metaprogramming/logical_operator/disjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/type_relations/is_same.h"
namespace portable_stl {

/**
 * @brief The result type of 3-way comparison that supports all 6 operators, is not substitutable, and allows
 * incomparable values
 *
 */
class partial_ordering;

/**
 * @brief The result type of 3-way comparison that supports all 6 operators and is substitutable.
 *
 */
class weak_ordering;

/**
 * @brief The result type of 3-way comparison that supports all 6 operators and is not substitutable.
 *
 */
class strong_ordering;

namespace compare_helper {

  /**
   * @brief The helper class for enable compare only with literal 0.
   */
  class unspecified final {
  public:
    /**
     * @brief Destructor.
     */
    ~unspecified() noexcept                                = default;
    /**
     * @brief Copy constructor.
     */
    constexpr unspecified(unspecified const &) noexcept    = default;
    /**
     * @brief Move constructor.
     */
    constexpr unspecified(unspecified &&) noexcept         = default;
    /**
     * @brief Assignment copy operator.
     * @return reference to object.
     */
    unspecified &operator=(unspecified const &) & noexcept = default;
    /**
     * @brief Assignment move operator.
     * @return reference to object.
     */
    unspecified &operator=(unspecified &&) & noexcept      = default;
    /**
     * @brief The constructor enable only for literal 0.
     */
    constexpr unspecified(decltype(0) unspecified::*) noexcept {
    }

    /**
     * @brief The constructor enable only for literal 0.
     */
    template<class t_type,
             class = ::portable_stl::enable_if_bool_constant_t<
               ::portable_stl::negation<::portable_stl::disjunction<::portable_stl::is_same<t_type, decltype(1)>,
                                                                    ::portable_stl::is_same<t_type, partial_ordering>,
                                                                    ::portable_stl::is_same<t_type, weak_ordering>,
                                                                    ::portable_stl::is_same<t_type, strong_ordering>>>>>
    constexpr unspecified(t_type const) = delete;
  };
} // namespace compare_helper

} // namespace portable_stl

#endif // PSTL_UNSPECIFIED_H
