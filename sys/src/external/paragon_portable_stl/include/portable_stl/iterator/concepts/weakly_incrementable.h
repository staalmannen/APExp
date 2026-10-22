// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="weakly_incrementable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_WEAKLY_INCREMENTABLE_H
#define PSTL_WEAKLY_INCREMENTABLE_H

#include "../../concepts/movable.h"
#include "../../concepts/signed_integral.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/logical_operator/negation.h"
#include "../../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../../metaprogramming/other_transformations/void_t.h"
#include "../../metaprogramming/type_relations/is_same.h"
#include "../../utility/general/declval.h"
#include "../incrementable_traits.h"

namespace portable_stl {

namespace concepts_helper {
  /**
   * @brief Signed-integer-like types.
   *
   * @tparam t_type Tested type.
   */
  template<class t_type> using signed_integer_like = ::portable_stl::signed_integral<t_type>;

  /**
   * @brief Helper class to check 'concept' semantic.
   * @tparam t_type Tested type.
   */
  template<class t_type, class = void> class weakly_incrementable_implC final {
  public:
    /**
     * @brief Result.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief Helper class to check 'concept' semantic.
   * @tparam t_type
   */
  template<class t_type>
  class weakly_incrementable_implC<t_type,
                                   ::portable_stl::void_t<decltype(::portable_stl::declval<t_type &>()++),
                                                          decltype(++::portable_stl::declval<t_type &>())>>
    final {
  public:
    /**
     * @brief Result.
     */
    using type
      = ::portable_stl::conjunction<signed_integer_like<::portable_stl::iter_difference_t<t_type>>,
                                    ::portable_stl::is_same<t_type &, decltype(++::portable_stl::declval<t_type &>())>>;
  };

  /**
   * @brief Helper class to check if iter_difference_t<t_type> exists.
   * @tparam t_type Tested type.
   */
  template<class t_type, class = void> class weakly_incrementable_check_iter_diff final {
  public:
    /**
     * @brief Result.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief Helper class to check if iter_difference_t<t_type> exists.
   * @tparam t_type Tested type.
   */
  template<class t_type>
  class weakly_incrementable_check_iter_diff<t_type, ::portable_stl::void_t<::portable_stl::iter_difference_t<t_type>>>
    final {
  public:
    /**
     * @brief Result.
     */
    using type = typename weakly_incrementable_implC<t_type>::type;
  };

  /**
   * @brief Helper class to check if t_type is movable and not bool.
   * @tparam t_type Tested type.
   */
  template<class t_type, class = void> class weakly_incrementable_check_movable final {
  public:
    /**
     * @brief Result.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief Helper class to check if t_type is movable and not bool.
   * @tparam t_type Tested type.
   */
  template<class t_type>
  class weakly_incrementable_check_movable<t_type,
                                           ::portable_stl::enable_if_bool_constant_t<::portable_stl::conjunction<
                                             ::portable_stl::negation<::portable_stl::is_same<bool, t_type>>,
                                             ::portable_stl::movable<t_type>>>>
    final {
  public:
    /**
     * @brief Result.
     */
    using type = typename weakly_incrementable_check_iter_diff<t_type>::type;
  };
} // namespace concepts_helper

/**
 * @brief This concept specifies requirements on types that can be incremented with the pre- and post-increment
 * operators, but those increment operations are not necessarily equality-preserving, and the type itself is not
 * required to be ::equality_comparable.
 *
 * @tparam t_type
 */
template<class t_type>
using weakly_incrementable = typename concepts_helper::weakly_incrementable_check_movable<t_type>::type;
} // namespace portable_stl

#endif /* PSTL_WEAKLY_INCREMENTABLE_H */
