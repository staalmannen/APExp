// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="to_address.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TO_ADDRESS_H
#define PSTL_TO_ADDRESS_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/disjunction.h"
#include "../metaprogramming/other_transformations/decay.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/primary_type/is_class.h"
#include "../metaprogramming/primary_type/is_function.h"
#include "../utility/general/declval.h"
#include "pointer_traits.h"

namespace portable_stl {
namespace memory_helper {

  /**
   * @brief Helper to check if pointer_traits::to_address could be called for given type.
   * Primary template.
   * @tparam t_ptr Given type.
   */
  template<class t_ptr, class = void> class has_to_address final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief Helper to check if pointer_traits::to_address could be called for given type.
   * @tparam t_ptr Given type.
   */
  template<class t_ptr>
  class has_to_address<t_ptr,
                       ::portable_stl::void_t<decltype(static_cast<void>(
                         ::portable_stl::pointer_traits<t_ptr>::to_address(::portable_stl::declval<t_ptr const &>())))>>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::true_type;
  };

  /**
   * @brief Helper to check if -> could be called for given type.
   * Primary template.
   * @tparam t_ptr Given type.
   */
  template<class t_ptr, class = void> class has_arrow_op final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief Helper to check if -> could be called for given type.
   * @tparam t_ptr Given type.
   */
  template<class t_ptr>
  class has_arrow_op<t_ptr, decltype(static_cast<void>(::portable_stl::declval<t_ptr const &>().operator->()))> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::true_type;
  };

  /**
   * @brief Chech if type is 'fancy' pointer.
   * @tparam t_ptr Given type.
   */
  template<class t_ptr>
  using is_fancy_pointer
    = ::portable_stl::disjunction<typename has_to_address<t_ptr>::type, typename has_arrow_op<t_ptr>::type>;

  // forward declaration
  template<class t_ptr, class = void> class to_address_helper;

  /**
   * @brief raw pointer overload:
   * If t_type is a function type, the program is ill-formed. Otherwise, returns ptr unmodified.
   *
   * @tparam t_type Given type.
   * @param ptr Pointer.
   * @return same pointer.
   */
  template<class t_type> constexpr t_type *to_address_impl(t_type *ptr) noexcept {
    // static_assert(!::portable_stl::is_function<t_type>{}(), "t_type is a function type");
    return ptr;
  }

  /**
   * @brief Fancy pointer overload:
   * enable_if is needed here to avoid instantiating checks for fancy pointers on raw pointers
   * @tparam t_ptr Pointer-like type.
   * @param ptr Pointer.
   * @return
   */
  template<class t_ptr,
           class = ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::is_class<t_ptr>, is_fancy_pointer<t_ptr>>>>
  ::portable_stl::decay_t<decltype(to_address_helper<t_ptr>::call(::portable_stl::declval<t_ptr const &>()))>
    to_address_impl(t_ptr const &ptr) {
    return to_address_helper<t_ptr>::call(ptr);
  }

  /**
   * @brief Helper class with call() overload for types with avaliable ->.
   * @tparam t_ptr Given type.
   */
  template<class t_ptr, class> class to_address_helper final {
  public:
    /**
     * @brief
     * @param ptr
     * @return
     */
    constexpr static decltype(to_address_impl(::portable_stl::declval<t_ptr const &>().operator->())) call(
      t_ptr const &ptr) noexcept {
      return to_address_impl(ptr.operator->());
    }
  };

  /**
   * @brief Helper class with call() overload for types with avaliable pointer_traits::to_address.
   * @tparam t_ptr Given type.
   */
  template<class t_ptr>
  class to_address_helper<t_ptr,
                          decltype(static_cast<void>(::portable_stl::pointer_traits<t_ptr>::to_address(
                            ::portable_stl::declval<t_ptr const &>())))>
    final {
  public:
    /**
     * @brief
     * @param ptr
     * @return
     */
    constexpr static decltype(::portable_stl::pointer_traits<t_ptr>::to_address(
      ::portable_stl::declval<t_ptr const &>()))
      call(t_ptr const &ptr) noexcept {
      return ::portable_stl::pointer_traits<t_ptr>::to_address(ptr);
    }
  };
} // namespace memory_helper

/**
 * @brief Obtain the address represented by ptr without forming a reference to the object pointed to by ptr.
 * @tparam t_type Given pointer type.
 * @param ptr Given pointer.
 * @return
 */
template<class t_type> constexpr inline auto to_address(t_type *ptr) noexcept {
  return memory_helper::to_address_impl(ptr);
}

/**
 * @brief Obtain the address represented by ptr without forming a reference to the object pointed to by ptr.
 * @tparam t_ptr Pointer-like type of given ptr object.
 * @param ptr Given pointer object.
 * @return
 */
template<class t_ptr>
constexpr inline auto to_address(t_ptr const &ptr) noexcept -> decltype(memory_helper::to_address_impl(ptr)) {
  return memory_helper::to_address_impl(ptr);
}

} // namespace portable_stl

#endif /* PSTL_TO_ADDRESS_H */
