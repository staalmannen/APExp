// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="make_integer_seq_generic.h"
// *
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MAKE_INTEGER_SEQ_GENERIC_H
#define PSTL_MAKE_INTEGER_SEQ_GENERIC_H

#include "../../common/size_t.h"
#include "integer_sequence.h"

namespace std {

/*
 * `make_integer_sequence' IN PLAIN C++14 -- an APExp addition,
 * because upstream had TWO implementations and BOTH are compiler
 * builtins: `__make_integer_seq' (clang, MSVC) and `__integer_pack'
 * (gcc 8+).  A compiler with neither -- EDG's `cpfe', which is what
 * `rc/bin/ape/eccp' runs -- had no third arm to fall into, and
 * `<array>', `<tuple>', `<utility>' and everything reaching them
 * stopped at `identifier "__integer_pack" is undefined'.
 *
 * The doubling recursion below is the standard construction and is
 * LOGARITHMIC in the count: `gen<N>' is two `gen<N/2>'s concatenated,
 * so a sequence of 1024 costs about ten levels of instantiation
 * rather than 1024.  That matters because the naive one-at-a-time
 * recursion is the reason the builtins were added in the first place,
 * and a fallback that is correct but quadratic would be swapped out
 * again by whoever next compiles a large `tuple'.
 *
 * It is NOT selected when a builtin is available: `make_index_sequence.h'
 * prefers the compiler's, which is still faster than any amount of
 * template arithmetic.
 */
namespace integer_sequence_helper {

  /*
   * THE COUNT IS ALWAYS `::std::size_t' HERE AND IS CAST AT THE END,
   * which is forced rather than chosen.  The obvious shape --
   * recursing on `t_num' of type `t_type' and terminating with
   * `gen_sequence<t_type, static_cast<t_type>(0)>' -- is ILL-FORMED:
   * a partial specialisation may not have a non-type argument whose
   * TYPE depends on a parameter of that same specialisation
   * ([temp.class.spec]), and g++ says so in exactly those words.
   * Fixing the count to `size_t' makes the two base cases FULL
   * specialisations, which have no such rule, and the cast to
   * `t_type' happens once at the end instead of inside the recursion.
   */
  template<class t_left, class t_right> class concat_sequence;

  template<::std::size_t... t_lhs, ::std::size_t... t_rhs>
  class concat_sequence<integer_sequence<::std::size_t, t_lhs...>,
                        integer_sequence<::std::size_t, t_rhs...>>
      final {
  public:
    /* The right half is SHIFTED by the left half's length, which is
       what makes the halves composable: the recursion always counts
       from zero and so both halves are the same computation. */
    using type = integer_sequence<::std::size_t, t_lhs..., (sizeof...(t_lhs) + t_rhs)...>;
  };

  template<::std::size_t t_num> class gen_sequence final {
  public:
    using type = typename concat_sequence<typename gen_sequence<t_num / 2U>::type,
                                          typename gen_sequence<t_num - (t_num / 2U)>::type>::type;
  };

  template<> class gen_sequence<0U> final {
  public:
    using type = integer_sequence<::std::size_t>;
  };

  template<> class gen_sequence<1U> final {
  public:
    using type = integer_sequence<::std::size_t, 0U>;
  };

  template<class t_type, class t_seq> class cast_sequence;

  template<class t_type, ::std::size_t... t_values>
  class cast_sequence<t_type, integer_sequence<::std::size_t, t_values...>> final {
  public:
    using type = integer_sequence<t_type, static_cast<t_type>(t_values)...>;
  };

} // namespace integer_sequence_helper

/**
 * @brief Alias template make_integer_sequence
 *
 * @tparam t_type Elements type.
 * @tparam t_num Number of elements.
 */
template<typename t_type, t_type t_num>
using make_integer_sequence = typename integer_sequence_helper::cast_sequence<
  t_type,
  typename integer_sequence_helper::gen_sequence<static_cast<::std::size_t>(t_num)>::type>::type;

} // namespace std

#endif /* PSTL_MAKE_INTEGER_SEQ_GENERIC_H */
