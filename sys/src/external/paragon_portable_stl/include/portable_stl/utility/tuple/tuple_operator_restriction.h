// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_operator_restriction.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_OPERATOR_RESTRICTION_H
#define PSTL_TUPLE_OPERATOR_RESTRICTION_H

#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/logical_operator/disjunction.h"
#include "../../metaprogramming/logical_operator/negation.h"
#include "../../metaprogramming/type_properties/is_assignable.h"
#include "../../metaprogramming/type_properties/is_constructible.h"
#include "../../metaprogramming/type_properties/is_nothrow_assignable.h"
#include "../../metaprogramming/type_relations/is_convertible.h"
#include "../../metaprogramming/type_relations/is_same.h"
#include "fwd_decl_tuple.h"
#include "tuple_helper.h"

namespace portable_stl {
namespace tuple_helper {

  /**
   * @brief Check if t_type is tuple_like but no tuple.
   * @tparam t_type Checked type.
   */
  template<class t_type>
  using tuple_like_non_tuple = ::portable_stl::conjunction<
    ::portable_stl::negation<tuple_helper::is_specialization<t_type, ::portable_stl::tuple>>,
    ::portable_stl::tuple_helper::tuple_like<t_type>>;

  namespace operator_restriction_impl {
    /**
     * @brief tuple_convert_val implementation.
     *
     * @tparam t_self_tuple_type
     * @tparam t_other_tuple
     * @tparam t_other_types
     */
    template<class t_self_tuple_type, class t_other_tuple, class... t_other_types> class tuple_convert_val_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::true_type;
    };

    /**
     * @brief tuple_convert_val implementation.
     *
     * @tparam t_single_type
     * @tparam t_other_tuple
     * @tparam t_other_type
     */
    template<class t_single_type, class t_other_tuple, class t_other_type>
    class tuple_convert_val_impl<tuple<t_single_type>, t_other_tuple, t_other_type> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::negation<
        ::portable_stl::disjunction<::portable_stl::is_same<t_single_type, t_other_type>,
                                    ::portable_stl::is_constructible<t_single_type, t_other_tuple>,
                                    ::portable_stl::is_convertible<t_other_tuple, t_single_type>>>;
    };

    /**
     * @brief tuple_perfect_val implementation.
     *
     * @tparam t_self_type
     * @tparam t_other_type
     * @tparam t_other_rest
     */
    template<class t_self_type, class t_other_type, class... t_other_rest> class tuple_perfect_val_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::true_type;
    };

    /**
     * @brief tuple_perfect_val implementation.
     *
     * @tparam t_self_type
     * @tparam t_other_type
     */
    template<class t_self_type, class t_other_type> class tuple_perfect_val_impl<t_self_type, t_other_type> final {
    public:
      /**
       * @brief Result type.
       */
      using type
        = ::portable_stl::negation<::portable_stl::is_same<t_self_type, ::portable_stl::remove_cvref_t<t_other_type>>>;
    };

    /**
     * @brief tuple_perfect_val implementation.
     *
     * @tparam t_type0
     * @tparam t_type1
     * @tparam t_other_type0
     * @tparam t_other_type1
     */
    template<class t_type0, class t_type1, class t_other_type0, class t_other_type1>
    class tuple_perfect_val_impl<tuple<t_type0, t_type1>, t_other_type0, t_other_type1> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::disjunction<
        ::portable_stl::negation<
          ::portable_stl::is_same<::portable_stl::remove_cvref_t<t_other_type0>, allocator_arg_t>>,
        ::portable_stl::is_same<::portable_stl::remove_cvref_t<t_type0>, allocator_arg_t>>;
    };

    /**
     * @brief tuple_perfect_val implementation.
     *
     * @tparam t_type0
     * @tparam t_type1
     * @tparam t_type2
     * @tparam t_other_type0
     * @tparam t_other_type1
     * @tparam t_other_type2
     */
    template<class t_type0, class t_type1, class t_type2, class t_other_type0, class t_other_type1, class t_other_type2>
    class tuple_perfect_val_impl<tuple<t_type0, t_type1, t_type2>, t_other_type0, t_other_type1, t_other_type2> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::disjunction<
        ::portable_stl::negation<
          ::portable_stl::is_same<::portable_stl::remove_cvref_t<t_other_type0>, allocator_arg_t>>,
        ::portable_stl::is_same<::portable_stl::remove_cvref_t<t_type0>, allocator_arg_t>>;
    };

    /**
     * @brief tuple_conditional_explicit implementation.
     *
     * @tparam is_same
     * @tparam t_dest_type
     * @tparam t_src_types
     */
    template<bool is_same, class t_dest_type, class... t_src_types> class tuple_conditional_explicit_impl0 final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };

    /**
     * @brief tuple_conditional_explicit implementation.
     *
     * @tparam t_dest_types
     * @tparam t_src_types
     */
    template<class... t_dest_types, class... t_src_types>
    class tuple_conditional_explicit_impl0<true, tuple<t_dest_types...>, t_src_types...> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::negation<
        ::portable_stl::conjunction<::portable_stl::is_convertible<t_src_types, t_dest_types>...>>;
    };

    /**
     * @brief tuple_conditional_explicit implementation.
     *
     * @tparam t_dest_type
     * @tparam t_src_types
     */
    template<class t_dest_type, class... t_src_types> class tuple_conditional_explicit_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = typename tuple_conditional_explicit_impl0<tuple_size<t_dest_type>{}() == sizeof...(t_src_types),
                                                             t_dest_type,
                                                             t_src_types...>::type;
    };

    /**
     * @brief tuple_constructible implementation.
     *
     * @tparam is_same
     * @tparam t_dest_type
     * @tparam t_src_types
     */
    template<bool is_same, class t_dest_type, class... t_src_types> class tuple_constructible_impl0 final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };

    /**
     * @brief tuple_constructible implementation.
     *
     * @tparam t_dest_types
     * @tparam t_src_types
     */
    template<class... t_dest_types, class... t_src_types>
    class tuple_constructible_impl0<true, tuple<t_dest_types...>, t_src_types...> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::conjunction<::portable_stl::is_constructible<t_dest_types, t_src_types>...>;
    };

    /**
     * @brief tuple_constructible implementation.
     *
     * @tparam t_dest_type
     * @tparam t_src_types
     */
    template<class t_dest_type, class... t_src_types> class tuple_constructible_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = typename tuple_constructible_impl0<tuple_size<t_dest_type>{}() == sizeof...(t_src_types),
                                                      t_dest_type,
                                                      t_src_types...>::type;
    };

    /**
     * @brief tuple_nothrow_constructible implementation.
     *
     * @tparam is_same
     * @tparam t_dest_type
     * @tparam t_src_types
     */
    template<bool is_same, class t_dest_type, class... t_src_types> class tuple_nothrow_constructible_impl0 final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };

    /**
     * @brief tuple_nothrow_constructible implementation.
     *
     * @tparam t_dest_types
     * @tparam t_src_types
     */
    template<class... t_dest_types, class... t_src_types>
    class tuple_nothrow_constructible_impl0<true, tuple<t_dest_types...>, t_src_types...> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::conjunction<::portable_stl::is_nothrow_constructible<t_dest_types, t_src_types>...>;
    };

    /**
     * @brief tuple_nothrow_constructible implementation.
     *
     * @tparam t_dest_type
     * @tparam t_src_types
     */
    template<class t_dest_type, class... t_src_types> class tuple_nothrow_constructible_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = typename tuple_nothrow_constructible_impl0<tuple_size<t_dest_type>{}() == sizeof...(t_src_types),
                                                              t_dest_type,
                                                              t_src_types...>::type;
    };

    /**
     * @brief tuple_assignable implementation.
     *
     * @tparam is_same
     * @tparam class
     * @tparam
     */
    template<bool is_same, class, class...> class tuple_assignable_impl0 final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };

    /**
     * @brief tuple_assignable implementation.
     *
     * @tparam t_dest_types
     * @tparam t_src_types
     */
    template<class... t_dest_types, class... t_src_types>
    class tuple_assignable_impl0<true, tuple<t_dest_types...>, t_src_types...> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::conjunction<
        ::portable_stl::is_assignable<t_dest_types &, t_src_types>...>; // note t_dest_types&
                                                                        // instead of t_dest_types
    };

    /**
     * @brief tuple_assignable implementation.
     *
     * @tparam t_dest_types
     * @tparam t_src_types
     */
    template<class... t_dest_types, class... t_src_types>
    class tuple_assignable_impl0<true, tuple<t_dest_types...> const, t_src_types...> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::conjunction<::portable_stl::is_assignable<t_dest_types const &, t_src_types>...>;
    };

    /**
     * @brief tuple_assignable implementation.
     *
     * @tparam t_dest_type
     * @tparam t_src_types
     */
    template<class t_dest_type, class... t_src_types> class tuple_assignable_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = typename tuple_assignable_impl0<tuple_size<t_dest_type>{}() == sizeof...(t_src_types),
                                                   t_dest_type,
                                                   t_src_types...>::type;
    };

    /**
     * @brief tuple_nothrow_assignable implementation.
     *
     * @tparam is_same
     * @tparam class
     * @tparam
     */
    template<bool is_same, class, class...> class tuple_nothrow_assignable_impl0 final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };

    /**
     * @brief tuple_nothrow_assignable implementation.
     *
     * @tparam t_dest_types
     * @tparam t_src_types
     */
    template<class... t_dest_types, class... t_src_types>
    class tuple_nothrow_assignable_impl0<true, tuple<t_dest_types...>, t_src_types...> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::conjunction<
        ::portable_stl::is_nothrow_assignable<t_dest_types &, t_src_types>...>; // note t_dest_types&
                                                                                // instead of t_dest_types
    };

    /**
     * @brief tuple_nothrow_assignable implementation.
     *
     * @tparam t_dest_types
     * @tparam t_src_types
     */
    template<class... t_dest_types, class... t_src_types>
    class tuple_nothrow_assignable_impl0<true, tuple<t_dest_types...> const, t_src_types...> final {
    public:
      /**
       * @brief Result type.
       */
      using type
        = ::portable_stl::conjunction<::portable_stl::is_nothrow_assignable<t_dest_types const &, t_src_types>...>;
    };

    /**
     * @brief tuple_nothrow_assignable implementation.
     *
     * @tparam t_dest_type
     * @tparam t_src_types
     */
    template<class t_dest_type, class... t_src_types> class tuple_nothrow_assignable_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = typename tuple_nothrow_assignable_impl0<tuple_size<t_dest_type>{}() == sizeof...(t_src_types),
                                                           t_dest_type,
                                                           t_src_types...>::type;
    };
  } // namespace operator_restriction_impl

  /**
   * @brief Check if t_dest_tuple could be assigned be t_src_types.
   *
   * @tparam t_dest_tuple Given tuple type.
   * @tparam t_src_types Other tuple type.
   */
  template<class t_dest_tuple, class... t_src_types>
  using tuple_assignable =
    typename operator_restriction_impl::tuple_assignable_impl<t_dest_tuple, t_src_types...>::type;

  /**
   * @brief Check if t_dest_tuple could be assigned be t_src_types without exceptions.
   *
   * @tparam t_dest_tuple Given tuple type.
   * @tparam t_src_types Other tuple type.
   */
  template<class t_dest_tuple, class... t_src_types>
  using tuple_nothrow_assignable =
    typename operator_restriction_impl::tuple_nothrow_assignable_impl<t_dest_tuple, t_src_types...>::type;

  /**
   * @brief Check if t_other_tuple<t_other_types...> could be converted into t_dest_tuple
   *
   * @tparam t_dest_tuple Given tuple type.
   * @tparam t_other_tuple Other tuple type.
   * @tparam t_other_types Other tuple's types.
   */
  template<class t_dest_tuple, class t_other_tuple, class... t_other_types>
  using tuple_convert_val =
    typename operator_restriction_impl::tuple_convert_val_impl<t_dest_tuple, t_other_tuple, t_other_types...>::type;

  /**
   * @brief Constrain tuple's perfect forwarding constructor (LWG-3121)
   *
   * @tparam t_dest_tuple Given tuple type.
   * @tparam t_other_type First value type.
   * @tparam t_other_rest Other types.
   */
  template<class t_dest_tuple, class t_other_type, class... t_other_rest>
  using tuple_perfect_val =
    typename operator_restriction_impl::tuple_perfect_val_impl<t_dest_tuple, t_other_type, t_other_rest...>::type;

  /**
   * @brief Check if t_dest_tuple could be UNexplicitly constructed from t_src_types.
   *
   * @tparam t_dest_tuple Given tuple type.
   * @tparam t_src_types Given types.
   */
  template<class t_dest_tuple, class... t_src_types>
  using tuple_conditional_explicit =
    typename operator_restriction_impl::tuple_conditional_explicit_impl<t_dest_tuple, t_src_types...>::type;

  /**
   * @brief Check if t_dest_tuple could be constructed from t_src_types.
   *
   * @tparam t_dest_tuple Given tuple type.
   * @tparam t_src_types Given types.
   */
  template<class t_dest_tuple, class... t_src_types>
  using tuple_constructible =
    typename operator_restriction_impl::tuple_constructible_impl<t_dest_tuple, t_src_types...>::type;

  /**
   * @brief Check if t_dest_tuple could be nothrow constructed from t_src_types.
   *
   * @tparam t_dest_tuple Given tuple type.
   * @tparam t_src_types Given types.
   */
  template<class t_dest_tuple, class... t_src_types>
  using tuple_nothrow_constructible =
    typename operator_restriction_impl::tuple_nothrow_constructible_impl<t_dest_tuple, t_src_types...>::type;
} // namespace tuple_helper
} // namespace portable_stl
#endif /* PSTL_TUPLE_OPERATOR_RESTRICTION_H */
