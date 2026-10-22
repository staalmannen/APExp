// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_always_bitcastable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_ALWAYS_BITCASTABLE_H
#define PSTL_IS_ALWAYS_BITCASTABLE_H

#include "../cv_modifications/remove_cv.h"
#include "../logical_operator/conjunction.h"
#include "../logical_operator/disjunction.h"
#include "../logical_operator/negation.h"
#include "../primary_type/is_integral.h"
#include "../type_properties/is_trivially_copyable.h"
#include "../type_relations/is_same.h"

namespace portable_stl {

template<class t_type_from, class t_type_to> class is_always_bitcastable final {
  using t_unqual_from = ::portable_stl::remove_cv_t<t_type_from>;
  using t_unqual_to   = ::portable_stl::remove_cv_t<t_type_to>;

public:
  using type = ::portable_stl::disjunction<
    // First, the simple case -- `From` and `To` are the same object type.
    ::portable_stl::conjunction<::portable_stl::is_same<t_unqual_from, t_unqual_to>,
                                ::portable_stl::is_trivially_copyable<t_unqual_from>>,
    // Beyond the simple case, we say that one type is "always bit-castable" to another if:
    // - (1) `From` and `To` have the same value representation, and in addition every possible value of `From` has
    //   a corresponding value in the `To` type (in other words, the set of values of `To` is a superset of the set of
    //   values of `From`);
    // - (2) When the corresponding values are not the same value (as, for example, between an unsigned and a signed
    //   integer, where a large positive value of the unsigned integer corresponds to a negative value in the signed
    //   integer type), the value of `To` that results from a bitwise copy of `From` is the same what would be
    //   produced by the built-in assignment (if it were defined for the two types, to which there are minor
    //   exceptions, e.g. built-in arrays).
    //
    // In practice, that means:
    // - all integral types (except `bool`, see below) -- that is, character types and `int` types, both signed and
    //   unsigned...
    // - as well as arrays of such types...
    // - ...that have the same size.
    //
    // Other trivially-copyable types can't be validly bit-cast outside of their own type:
    // - floating-point types normally have different sizes and thus aren't bit-castable between each other (fails
    // #1);
    // - integral types and floating-point types use different representations, so for example bit-casting an integral
    //   `1` to `float` results in a very small less-than-one value, unlike built-in assignment that produces `1.0`
    //   (fails #2);
    // - booleans normally use only a single bit of their object representation; bit-casting an integer to a boolean
    //   will result in a boolean object with an incorrect representation, which is undefined behavior (fails #2).
    //   Bit-casting from a boolean into an integer, however, is valid;
    // - enumeration types may have different ranges of possible values (fails #1);
    // - for pointers, it is not guaranteed that pointers to different types use the same set of values to represent
    //   addresses, and the conversion results are explicitly unspecified for types with different alignments
    //   (fails #1);
    // - for structs and unions it is impossible to determine whether the set of values of one of them is a subset of
    //   the other (fails #1);
    // - there is no need to consider `nullptr_t` for practical purposes.
    ::portable_stl::conjunction<::portable_stl::bool_constant<sizeof(t_type_from) == sizeof(t_type_to)>,
                                ::portable_stl::is_integral<t_type_from>,
                                ::portable_stl::is_integral<t_type_to>,
                                ::portable_stl::negation<::portable_stl::is_same<t_unqual_to, bool>>>>;
};

} // namespace portable_stl

#endif // PSTL_IS_ALWAYS_BITCASTABLE_H
