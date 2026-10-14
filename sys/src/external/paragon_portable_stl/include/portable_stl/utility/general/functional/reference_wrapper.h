// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="reference_wrapper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_REFERENCE_WRAPPER_H
#define PSTL_REFERENCE_WRAPPER_H

#include "../../../memory/addressof.h"
#include "../../../metaprogramming/logical_operator/negation.h"
#include "../../../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../../../metaprogramming/other_transformations/remove_cvref.h"
#include "../../../metaprogramming/type_relations/is_same.h"
#include "../../../metaprogramming/type_relations/is_nothrow_invocable.h"
#include "../declval.h"
#include "../forward.h"
#include "invoke_impl.h"
#include "weak_result_type.h"

namespace portable_stl {

namespace utility_general_helpers {
  /**
   * @brief Exposition-only/internal function.
   *
   * @tparam t_type Arg type.
   * @param t lvalue reference to object.
   * @return
   */
  template<class t_type> constexpr t_type &FUN(t_type &t) noexcept {
    return t;
  }

  /**
   * @brief Exposition-only/internal function.
   *
   * @tparam t_type Arg type.
   * @return
   */
  template<class t_type> void FUN(t_type &&) = delete;
} // namespace utility_general_helpers

/**
 * @brief CopyConstructible and CopyAssignable reference wrapper.
 *
 * @tparam t_type The given type.
 */
template<class t_type> class reference_wrapper  {
  /**
   * @brief "Stores" reference as pointer.
   *
   */
  t_type *m_ptr;

public:
  /**
   * @brief The refference object/function type.
   */
  using type = t_type;

  /**
   * @brief Constructor.
   *
   * @tparam u_type The type of the ref.
   * @param u The object (or function) ref to wrap.
   */
  template<class u_type,
           class = decltype(utility_general_helpers::FUN<t_type>(::portable_stl::declval<u_type>()),
                            ::portable_stl::enable_if_bool_constant_t<::portable_stl::negation<
                              ::portable_stl::is_same<reference_wrapper, ::portable_stl::remove_cvref_t<u_type>>>>())>
  reference_wrapper(u_type &&u) noexcept(
    noexcept(utility_general_helpers::FUN<t_type>(::portable_stl::forward<u_type>(u))))
      : m_ptr(::portable_stl::addressof(utility_general_helpers::FUN<t_type>(::portable_stl::forward<u_type>(u)))) {
  }

  /**
   * @brief Copy constructor (default).
   *
   * @param rhs Another ref wrapper.
   */
  reference_wrapper(reference_wrapper const &) noexcept = default;

  /**
   * @brief Move constructor (default).
   *
   * @param rhs Another ref wrapper.
   */
  reference_wrapper(reference_wrapper &&) noexcept = default;

  /**
   * @brief Copy assignment operator (default). Drops the current reference and stores a reference to other.get().
   * was constexpr
   * @param other Reference wrapper to copy.
   * @return *this.
   */
  reference_wrapper &operator=(reference_wrapper const &other) noexcept = default;

  /**
   * @brief Move assignment operator (default).
   *
   * @param other Another ref wrapper.
   */
  reference_wrapper &operator=(reference_wrapper &&other) noexcept = default;

  /**
   * @brief Destructor (default).
   */
  ~reference_wrapper() = default;

  /**
   * @brief Implicit accessor.
   *
   * @return t_type & Value.
   */
  constexpr operator t_type &() const noexcept {
    return *m_ptr;
  }

  /**
   * @brief Explicit accessor.
   *
   * @return t_type & Value.
   */
  constexpr t_type &get() const noexcept {
    return *m_ptr;
  }

  template<class... t_args>
  typename ::portable_stl::invoke_of<t_type &, t_args...>::type operator()(t_args &&...args) const
      noexcept(::portable_stl::is_nothrow_invocable<t_type&, t_args...>{}())
  {
    return ::portable_stl::functional_helper::invoke_impl(get(), ::portable_stl::forward<t_args>(args)...);
  }
};

/**
 * @brief Creates a reference_wrapper with a type deduced from its argument.
 *
 * @tparam t_type The given type.
 * @param t lvalue reference to object that needs to be wrapped or an instance of reference_wrapper.
 * @return reference_wrapper
 */
template<class t_type> reference_wrapper<t_type> ref(t_type &t) {
  return reference_wrapper<t_type>(t);
}

/**
 * @brief Creates a reference_wrapper with a type deduced from its argument.
 *
 * @tparam t_type The given type.
 * @param t lvalue reference to object that needs to be wrapped or an instance of reference_wrapper.
 * @return reference_wrapper
 */
template<class t_type> reference_wrapper<t_type> ref(reference_wrapper<t_type> t) {
  return t;
}

/**
 * @brief Creates a reference_wrapper with a type deduced from its argument.
 *
 * @tparam t_type The given type.
 * @param t lvalue reference to object that needs to be wrapped or an instance of reference_wrapper.
 * @return reference_wrapper
 */
template<class t_type> reference_wrapper<t_type const> cref(t_type const &t) {
  return reference_wrapper<t_type const>(t);
}

/**
 * @brief Creates a reference_wrapper with a type deduced from its argument.
 *
 * @tparam t_type The given type.
 * @param t lvalue reference to object that needs to be wrapped or an instance of reference_wrapper.
 * @return reference_wrapper
 */
template<class t_type> reference_wrapper<t_type const> cref(reference_wrapper<t_type> t) {
  return t;
}

/**
 * @brief Rvalue reference wrapper is deleted.
 *
 * @tparam t_type The given type.
 */
template<class t_type> void ref(t_type const &&) = delete;

/**
 * @brief Rvalue reference wrapper is deleted.
 *
 * @tparam t_type The given type.
 */
template<class t_type> void cref(t_type &&) = delete;
} // namespace portable_stl

#endif // PSTL_REFERENCE_WRAPPER_H
