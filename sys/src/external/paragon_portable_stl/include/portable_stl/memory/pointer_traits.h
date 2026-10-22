// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="pointer_traits.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_POINTER_TRAITS_H
#define PSTL_POINTER_TRAITS_H

#include "../common/ptrdiff_t.h"
#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/other_transformations/conditional_bool_constant.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../metaprogramming/primary_type/is_void.h"
#include "addressof.h"

namespace portable_stl {
namespace memory_helper {

  template<class _Newfirst, class _Ty> struct _Replace_first_parameter;

  template<class _Newfirst, template<class, class...> class _Ty, class _First, class... _Rest>
  struct _Replace_first_parameter<_Newfirst, _Ty<_First, _Rest...>> { // given _Ty<_First, _Rest...>, replace _First
    using type = _Ty<_Newfirst, _Rest...>;
  };

  /**
   * @brief Helper to check if given t_type has element_type typename.
   * Primary template.
   * @tparam t_type Given type.
   */
  template<class t_type, class = void> class has_element_type final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief Helper to check if given t_type has element_type typename.
   * @tparam t_type Given type.
   */
  template<class t_type> class has_element_type<t_type, ::portable_stl::void_t<typename t_type::element_type>> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::true_type;
  };

  /**
   * @brief Helper class to get element-type-of t_ptr (element_type or equivalent).
   * Primary template.
   * @tparam t_ptr Given type.
   */
  template<class t_ptr, class = typename has_element_type<t_ptr>::type> class pointer_traits_element_type final {};

  /**
   * @brief Helper class to get element-type-of t_ptr (element_type or equivalent).
   * @tparam t_ptr Given type.
   */
  template<class t_ptr> class pointer_traits_element_type<t_ptr, ::portable_stl::true_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = typename t_ptr::element_type;
  };

  /**
   * @brief Helper class to get element-type-of t_ptr (element_type or equivalent).
   * @tparam Sp
   * @tparam t_type
   * @tparam t_args
   */
  template<template<class, class...> class Sp, class t_type, class... t_args>
  class pointer_traits_element_type<Sp<t_type, t_args...>, ::portable_stl::true_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = typename Sp<t_type, t_args...>::element_type;
  };

  /**
   * @brief Helper class to get element-type-of t_ptr (element_type or equivalent).
   * @tparam Sp
   * @tparam t_type
   * @tparam t_args
   */
  template<template<class, class...> class Sp, class t_type, class... t_args>
  class pointer_traits_element_type<Sp<t_type, t_args...>, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = t_type;
  };

  /**
   * @brief Helper to check if given t_type has difference_type typename.
   * Primary template.
   * @tparam t_type Given type.
   */
  template<class t_type, class = void> class has_difference_type final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief Helper to check if given t_type has difference_type typename.
   * @tparam t_type Given type.
   */
  template<class t_type>
  class has_difference_type<t_type, ::portable_stl::void_t<typename t_type::difference_type>> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::true_type;
  };

  /**
   * @brief Helper class to get difference-like type for t_ptr (t_ptr::difference_type if present, otherwise ptrdiff_t).
   * @tparam t_ptr Given type.
   */
  template<class t_ptr, class = typename has_difference_type<t_ptr>::type> class pointer_traits_difference_type final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::ptrdiff_t;
  };

  /**
   * @brief Helper class to get difference-like type for t_ptr (t_ptr::difference_type if present, otherwise ptrdiff_t).
   * @tparam t_ptr Given type.
   */
  template<class t_ptr> class pointer_traits_difference_type<t_ptr, ::portable_stl::true_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = typename t_ptr::difference_type;
  };

  /**
   * @brief Helper to check if given t_type1 has ::rebind<t_type2>.
   * @tparam t_type1 Given type.
   * @tparam t_type2 Given type.
   */
  template<class t_type1, class t_type2> class has_rebind final {
    /**
     * @brief Test function.
     * @return ::portable_stl::false_type
     */
    template<class, class> static ::portable_stl::false_type test(...);

    /**
     * @brief Test function.
     * @tparam T1
     * @tparam T2
     * @return ::portable_stl::true_type
     */
    template<class T1, class T2> static ::portable_stl::true_type test(typename T1::template rebind<T2> * = 0);

  public:
    /**
     * @brief Result type.
     */
    using type = decltype(test<t_type1, t_type2>(0));
  };

  /**
   * @brief Helper to select rebind alias for given types.
   * @tparam t_type1 Given type.
   * @tparam t_type2 Given type.
   */
  template<class t_type1, class t_type2, class = typename has_rebind<t_type1, t_type2>::type>
  class pointer_traits_rebind final {
  public:
    /**
     * @brief Result type.
     */
    using type = typename t_type1::template rebind<t_type2>;
  };

  /**
   * @brief Helper to select rebind alias for given types.
   * @tparam Sp
   * @tparam t_type1
   * @tparam t_args
   * @tparam t_type2
   */
  template<template<class, class...> class Sp, class t_type1, class... t_args, class t_type2>
  class pointer_traits_rebind<Sp<t_type1, t_args...>, t_type2, ::portable_stl::true_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = typename Sp<t_type1, t_args...>::template rebind<t_type2>;
  };

  /**
   * @brief Helper to select rebind alias for given types.
   * @tparam Sp
   * @tparam t_type1
   * @tparam t_args
   * @tparam t_type2
   */
  template<template<class, class...> class Sp, class t_type1, class... t_args, class t_type2>
  class pointer_traits_rebind<Sp<t_type1, t_args...>, t_type2, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = Sp<t_type2, t_args...>;
  };

  // msvc approach 
  // template<class new_first_t, class t_type> class replase_first_parameter final {};
  // template<class new_first_t, template<class, class...> class t_type, class first_t, class... rest_t>
  // class replase_first_parameter<new_first_t, t_type<first_t, rest_t...>> final {
  // public:
  //   using type = t_type<new_first_t, rest_t...>;
  // };
  // template<class t_type, class t_other, class = void> class get_rebind_alias final {
  // public:
  //   using type = typename replase_first_parameter<t_other, t_type>::type;
  // };
  // template<class t_type, class t_other>
  // class get_rebind_alias<t_type, t_other, ::portable_stl::void_t<typename t_type::template rebind<t_other>>> final {
  // public:
  //   using type = typename t_type::template rebind<t_other>;
  // };

  /**
   * @brief pointer_traits base with no element-type-of t_ptr type typename.
   * @tparam t_ptr Given ptr-like type.
   */
  template<class t_ptr, class = void> class pointer_traits_base {};

  /**
   * @brief pointer_traits base with element-type-of t_ptr type typename.
   * @tparam t_ptr  Given ptr-like type.
   */
  template<class t_ptr>
  class pointer_traits_base<t_ptr, ::portable_stl::void_t<typename pointer_traits_element_type<t_ptr>::type>> {
    /**
     * @brief Empty struct for void case.
     */
    struct t_nat {};

  public:
    /**
     * @brief Pointer type.
     */
    using pointer                        = t_ptr;
    /**
     * @brief element-type-of t_ptr type.
     */
    using element_type                   = typename pointer_traits_element_type<t_ptr>::type;
    /**
     * @brief Difference type.
     */
    using difference_type                = typename pointer_traits_difference_type<t_ptr>::type;
    /**
     * @brief rebind alias.
     * @tparam t_other Other type.
     */
    template<class t_other> using rebind = typename pointer_traits_rebind<pointer, t_other>::type;

    /**
     * @brief Obtains a dereferenceable pointer to its argument.
     * @param r_value
     * @return
     */
    constexpr static pointer pointer_to(
      ::portable_stl::conditional_bool_constant_t<::portable_stl::is_void<element_type>, t_nat, element_type>
        &r_value) noexcept {
      return pointer::pointer_to(r_value);
    }
  };
} // namespace memory_helper

/**
 * @brief The pointer_traits class template provides the standardized way to access certain properties of pointer-like
 * types (fancy pointers, such as boost::interprocess::offset_ptr).
 *
 * @tparam t_ptr Given pre-like type.
 */
template<class t_ptr> class pointer_traits final : public memory_helper::pointer_traits_base<t_ptr> {};

/**
 * @brief A specialization is provided for pointer types, t_type*
 * @tparam t_type Given type.
 */
template<class t_type> class pointer_traits<t_type *> final {
  /**
   * @brief Empty struct for void case.
   */
  struct t_nat {};

public:
  /**
   * @brief Pointer type.
   */
  using pointer                        = t_type *;
  /**
   * @brief element-type-of t_ptr type.
   */
  using element_type                   = t_type;
  /**
   * @brief Difference type.
   */
  using difference_type                = ::portable_stl::ptrdiff_t;
  /**
   * @brief rebind alias.
   * @tparam t_other Other type.
   */
  template<class t_other> using rebind = t_other *;

  /**
   * @brief Obtains a dereferenceable pointer to its argument.
   * @param r_value
   * @return
   */
  constexpr static pointer pointer_to(
    ::portable_stl::conditional_bool_constant_t<::portable_stl::is_void<element_type>, t_nat, element_type>
      &r_value) noexcept {
    return ::portable_stl::addressof(r_value);
  }
};
} // namespace portable_stl

#endif /* PSTL_POINTER_TRAITS_H */
