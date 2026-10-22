// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_cat.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_CAT_H
#define PSTL_TUPLE_CAT_H
#include "../../array/array_get.h"
#include "tuple.h"
#include "tuple_size.h"

namespace portable_stl {
namespace tuple_helper {

  /**
   * @brief make_tuple for concatenation implementation.
   * Primary template.
   */
  template<::portable_stl::size_t, class, class, ::portable_stl::size_t> class make_tuple_impl;

  /**
   * @brief make_tuple for concatenation implementation.
   *
   * @tparam t_idx Index.
   * @tparam t_tuple Tuple type.
   * @tparam t_types Tuple element types.
   * @tparam t_num
   */
  template<::portable_stl::size_t t_idx, class t_tuple, class... t_types, ::portable_stl::size_t t_num>
  class make_tuple_impl<t_idx, tuple<t_types...>, t_tuple, t_num>
      : public make_tuple_impl<t_idx + 1, tuple<t_types..., tuple_element_t<t_idx, t_tuple>>, t_tuple, t_num> {};

  /**
   * @brief make_tuple for concatenation implementation.
   *
   * @tparam t_num
   * @tparam t_tuple Tuple type.
   * @tparam t_types Tuple element types.
   */
  template<::portable_stl::size_t t_num, class t_tuple, class... t_types>
  class make_tuple_impl<t_num, tuple<t_types...>, t_tuple, t_num> {
  public:
    /**
     * @brief Result type.
     */
    using type = tuple<t_types...>;
  };

  /**
   * @brief Init point for make_tuple_impl.
   * @tparam t_tuple Given tuple type.
   */
  template<class t_tuple, ::portable_stl::size_t tpl_size = tuple_size<t_tuple>{}()>
  class do_make_tuple : public make_tuple_impl<0, tuple<>, t_tuple, tpl_size> {};

  /**
   * @brief Helper to remove cvref qualifiers.
   * @tparam t_tuple Given tuple type.
   */
  template<class t_tuple> class make_tuple_for_cat final : public do_make_tuple<remove_cvref_t<t_tuple>> {};

  /**
   * @brief Combines several tuple's into a single one.
   * Primary template.
   */
  template<class...> class combine_tuples;

  /**
   * @brief Combines several tuple's into a single one.
   * Empty tuple case.
   */
  template<> class combine_tuples<> final {
  public:
    /**
     * @brief Result tuple type.
     */
    using type = tuple<>;
  };

  /**
   * @brief Combines several tuple's into a single one.
   * One tuple case.
   */
  template<class... t_types> class combine_tuples<tuple<t_types...>> final {
  public:
    /**
     * @brief Result tuple type.
     */
    using type = tuple<t_types...>;
  };

  /**
   * @brief Combines several tuple's into a single one.
   *
   * @tparam t_types1 First tuple types.
   * @tparam t_types2 Second tuple types.
   * @tparam t_remain Remain tuples types.
   */
  template<class... t_types1, class... t_types2, class... t_remain>
  class combine_tuples<tuple<t_types1...>, tuple<t_types2...>, t_remain...> final {
  public:
    /**
     * @brief Result tuple type.
     */
    using type = typename combine_tuples<tuple<t_types1..., t_types2...>, t_remain...>::type;
  };

  /**
   * @brief Computes the result type of tuple_cat given a set of tuple-like types.
   * @tparam t_types Given tuple-like types.
   */
  template<class... t_types> class tuple_cat_result final {
  public:
    /**
     * @brief Result tuple type.
     */
    using type = typename combine_tuples<typename make_tuple_for_cat<t_types>::type...>::type;
  };

  /**
   * @brief Helper to determine the index set for the first tuple-like type of a given set.
   * Primary tempalte.
   */
  template<class...> class make_1st_indices;

  /**
   * @brief Helper to determine the index set for the first tuple-like type of a given set.
   * Empty tuple case.
   */
  template<> class make_1st_indices<> final {
  public:
    /**
     * @brief Result index set.
     */
    using type = index_sequence<>;
  };

  /**
   * @brief Helper to determine the index set for the first tuple-like type of a given set.
   *
   * @tparam t_type first type.
   * @tparam t_types Remain types.
   */
  template<class t_type, class... t_types> class make_1st_indices<t_type, t_types...> final {
  public:
    /**
     * @brief Result index set.
     */
    using type = make_index_sequence<tuple_size<remove_reference_t<t_type>>{}()>;
  };

  /**
   * @brief Performs the actual concatenation by step-wise expanding tuple-like objects into the elements, which are
   * finally forwarded into the result tuple.
   * Primary template.
   *
   * @tparam t_return_type
   * @tparam t_indices
   * @tparam t_types
   */
  template<class t_return_type, class t_indices, class... t_types> class tuple_concater;

  /**
   * @brief Performs the actual concatenation by step-wise expanding tuple-like objects into the elements, which are
   * finally forwarded into the result tuple.
   *
   * @tparam t_return_type
   * @tparam t_indices
   * @tparam t_type
   * @tparam t_types
   */
  template<class t_return_type, ::portable_stl::size_t... t_indices, class t_type, class... t_types>
  class tuple_concater<t_return_type, index_sequence<t_indices...>, t_type, t_types...> final {
  public:
    /**
     * @brief Concatenation action.
     * 
     * @tparam t_other_types 
     * @param value 
     * @param values 
     * @param others 
     * @return constexpr t_return_type 
     */
    template<class... t_other_types>
    constexpr static t_return_type do_cat(t_type &&value, t_types &&...values, t_other_types &&...others) {
      /**
       * Index set from first type in types.
       */
      using t_first_idx = typename make_1st_indices<t_types...>::type;
      /**
       * @brief Type of helper 'concater'.
       */
      using t_next      = tuple_concater<t_return_type, t_first_idx, t_types...>;
      return t_next::do_cat(::portable_stl::forward<t_types>(values)...,
                            ::portable_stl::forward<t_other_types>(others)...,
                            ::portable_stl::get<t_indices>(::portable_stl::forward<t_type>(value))...);
    }
  };

  /**
   * @brief Performs the actual concatenation by step-wise expanding tuple-like objects into the elements, which are
   * finally forwarded into the result tuple.
   *
   * @tparam t_return_type
   */
  template<class t_return_type> class tuple_concater<t_return_type, index_sequence<>> final {
  public:
  /**
   * @brief Concatenation action.
   * 
   * @tparam t_other_types 
   * @param others 
   * @return constexpr t_return_type 
   */
    template<class... t_other_types> constexpr static t_return_type do_cat(t_other_types &&...others) {
      return t_return_type(::portable_stl::forward<t_other_types>(others)...);
    }
  };
} // namespace tuple_helper

/**
 * @brief Create a tuple containing all elements from multiple tuple-like objects
 *
 * @tparam t_types Given tuple-like types.
 * @param others Given tuple-like objects.
 * @return A tuple object composed of all elements of all argument tuples constructed from get<j>(forward<Ti>(arg)) for
 * each individual element.
 */
template<class... t_types>
constexpr auto tuple_cat(t_types &&...others) -> typename tuple_helper::tuple_cat_result<t_types...>::type {
  /**
   * @brief Testuren type.
   */
  using t_return_type = typename tuple_helper::tuple_cat_result<t_types...>::type;
  /**
   * @brief Index set from first type in types.
   */
  using t_first_idx   = typename tuple_helper::make_1st_indices<t_types...>::type;
  /**
   * @brief Type of helper 'concater'.
   */
  using t_concater    = tuple_helper::tuple_concater<t_return_type, t_first_idx, t_types...>;
  return t_concater::do_cat(::portable_stl::forward<t_types>(others)...);
}

} // namespace portable_stl

#endif /* PSTL_TUPLE_CAT_H */
