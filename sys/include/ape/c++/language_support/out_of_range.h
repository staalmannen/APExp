// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="out_of_range.h"
// *
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************

#ifndef PSTL_OUT_OF_RANGE_H
#define PSTL_OUT_OF_RANGE_H

#include "logic_error.h"

namespace std {

/**
 * @brief Defines a type of object to be thrown as exception.  It reports errors that are consequence of attempt to access elements out of defined range.
 */
template<class = void> class out_of_range_impl : public ::std::logic_error {
public:
  /**
   * @brief Default destructor.
   */
  ~out_of_range_impl() noexcept override = default;
  /**
   * @brief Default constructor.
   */
  out_of_range_impl() noexcept = default;
  /**
   * @brief Default copy constructor.
   */
  out_of_range_impl(out_of_range_impl const &) noexcept = default;
  /**
   * @brief Default move constructor.
   */
  out_of_range_impl(out_of_range_impl &&) noexcept = default;
  /**
   * @brief Default copy assignment.
   */
  out_of_range_impl &operator=(out_of_range_impl const &) noexcept = default;
  /**
   * @brief Default move assignment.
   */
  out_of_range_impl &operator=(out_of_range_impl &&) noexcept = default;
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
template<class t_object> inline char const * out_of_range_impl<t_object>::what() const noexcept {
  return "out of range error from portable_stl.";
}

/*
 * ***THE CLASS IS A TEMPLATE AND THE NAME IS AN ALIAS, WHICH IS NOT
 * HOW UPSTREAM LEFT IT.***  Upstream wrote
 * `template<class = void> class out_of_range', and every one of
 * `<stdexcept>'s classes the same way, so
 *
 *     catch (::std::out_of_range &)
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
 * The cost is that `::std::out_of_range<>' is no longer valid; the
 * library's own call sites spelled it that way and were updated with
 * it.
 *
 * **What is still missing is the standard's CONSTRUCTORS.**  There is
 * no `out_of_range(char const *)' and no
 * `out_of_range(string const &)', so `throw ::std::out_of_range("...")'
 * does not compile and `what()' returns a fixed string.  Not added
 * here, for two reasons worth writing down: a `string' overload in
 * this header would be a circular include (`basic_string' throws
 * `length_error'), and storing a `char const *' is only safe for an
 * argument with static storage duration -- *a silent dangle for
 * anything else, which is worse than the compile error a caller gets
 * now.*
 */

using out_of_range = out_of_range_impl<>;

} // namespace std

#endif // PSTL_OUT_OF_RANGE_H
