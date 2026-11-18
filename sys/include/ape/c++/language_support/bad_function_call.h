// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="bad_function_call.h"
// *
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************

#ifndef PSTL_BAD_FUNCTION_CALL_H
#define PSTL_BAD_FUNCTION_CALL_H

#include "exception.h"

namespace std {

/**
 * @brief Defines a type of object to be thrown as exception.  It reports errors that arise because an attempt is made to call a std::function which has no target.
 */
template<class = void> class bad_function_call_impl : public ::std::exception {
public:
  /**
   * @brief Default destructor.
   */
  ~bad_function_call_impl() noexcept override = default;
  /**
   * @brief Default constructor.
   */
  bad_function_call_impl() noexcept = default;
  /**
   * @brief Default copy constructor.
   */
  bad_function_call_impl(bad_function_call_impl const &) noexcept = default;
  /**
   * @brief Default move constructor.
   */
  bad_function_call_impl(bad_function_call_impl &&) noexcept = default;
  /**
   * @brief Default copy assignment.
   */
  bad_function_call_impl &operator=(bad_function_call_impl const &) noexcept = default;
  /**
   * @brief Default move assignment.
   */
  bad_function_call_impl &operator=(bad_function_call_impl &&) noexcept = default;
  /**
   * @brief Get exception message.
   *
   * @return const char pointer to ntbs message.
   */
  char const * what() const noexcept override;
};

/**
 * @brief Get exception message.
 *
 * @return const char pointer to ntbs message.
 */
template<class t_object> inline char const * bad_function_call_impl<t_object>::what() const noexcept {
  return "bad_function_call error from portable_stl.";
}

/*
 * ***THE CLASS IS A TEMPLATE AND THE NAME IS AN ALIAS, WHICH IS NOT
 * HOW UPSTREAM LEFT IT.***  Upstream wrote
 * `template<class = void> class bad_function_call', and every one of
 * `<stdexcept>'s classes the same way, so
 *
 *     catch (::std::bad_function_call &)
 *
 * -- what every real program writes -- answered `invalid use of
 * template-name without an argument list', with g++ helpfully
 * offering C++17 class template argument deduction as the
 * explanation.  unrar's `rar.cpp:95' and `dll.cpp:174' are that line.
 *
 * **Upstream's reason is good and is kept.**  A template member
 * `what()' can be defined in a header with no `.cpp' and no COMDAT
 * question, which is what lets this library stay header-only -- and
 * it is why the fix is a RENAME AND AN ALIAS rather than a real
 * class.  Making these ordinary classes with inline virtuals would
 * put the vtable and the typeinfo in COMDAT, which is a question
 * about the LINK MODEL (`cmd/edg/mkfile' already passes `-C', and
 * `--instantiate local' does not touch typeinfo) and deserves its own
 * round.  *An alias costs nothing and answers the whole complaint.*
 *
 * The cost is that `::std::bad_function_call<>' is no longer valid; the
 * library's own call sites spelled it that way and were updated with
 * it.
 *
 * **What is still missing is the standard's CONSTRUCTORS.**  There is
 * no `bad_function_call(char const *)' and no
 * `bad_function_call(string const &)', so `throw ::std::bad_function_call("...")'
 * does not compile and `what()' returns a fixed string.  Not added
 * here, for two reasons worth writing down: a `string' overload in
 * this header would be a circular include (`basic_string' throws
 * `length_error'), and storing a `char const *' is only safe for an
 * argument with static storage duration -- *a silent dangle for
 * anything else, which is worse than the compile error a caller gets
 * now.*
 */

using bad_function_call = bad_function_call_impl<>;

} // namespace std

#endif // PSTL_BAD_FUNCTION_CALL_H
