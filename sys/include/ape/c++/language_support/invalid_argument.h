// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="invalid_argument.h"
// *
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************

#ifndef PSTL_INVALID_ARGUMENT_H
#define PSTL_INVALID_ARGUMENT_H

#include "logic_error.h"

namespace std {

/**
 * @brief Defines a type of object to be thrown as exception.  It reports errors that arise because an argument value has not been accepted.
 */
template<class = void> class invalid_argument_impl : public ::std::logic_error {
public:
  /**
   * @brief Default destructor.
   */
  ~invalid_argument_impl() noexcept override = default;
  /**
   * @brief Default constructor.
   */
  invalid_argument_impl() noexcept = default;
  /**
   * @brief Default copy constructor.
   */
  invalid_argument_impl(invalid_argument_impl const &) noexcept = default;
  /**
   * @brief Default move constructor.
   */
  invalid_argument_impl(invalid_argument_impl &&) noexcept = default;
  /**
   * @brief Default copy assignment.
   */
  invalid_argument_impl &operator=(invalid_argument_impl const &) noexcept = default;
  /**
   * @brief Default move assignment.
   */
  invalid_argument_impl &operator=(invalid_argument_impl &&) noexcept = default;
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
template<class t_object> inline char const * invalid_argument_impl<t_object>::what() const noexcept {
  return "invalid argument from portable_stl.";
}

/*
 * ***THE CLASS IS A TEMPLATE AND THE NAME IS AN ALIAS, WHICH IS NOT
 * HOW UPSTREAM LEFT IT.***  Upstream wrote
 * `template<class = void> class invalid_argument', and every one of
 * `<stdexcept>'s classes the same way, so
 *
 *     catch (::std::invalid_argument &)
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
 * The cost is that `::std::invalid_argument<>' is no longer valid; the
 * library's own call sites spelled it that way and were updated with
 * it.
 *
 * **What is still missing is the standard's CONSTRUCTORS.**  There is
 * no `invalid_argument(char const *)' and no
 * `invalid_argument(string const &)', so `throw ::std::invalid_argument("...")'
 * does not compile and `what()' returns a fixed string.  Not added
 * here, for two reasons worth writing down: a `string' overload in
 * this header would be a circular include (`basic_string' throws
 * `length_error'), and storing a `char const *' is only safe for an
 * argument with static storage duration -- *a silent dangle for
 * anything else, which is worse than the compile error a caller gets
 * now.*
 */

using invalid_argument = invalid_argument_impl<>;

} // namespace std

#endif // PSTL_INVALID_ARGUMENT_H
