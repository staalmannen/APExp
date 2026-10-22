// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="type_list.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TYPE_LIST_H
#define PSTL_TYPE_LIST_H

#include "../../common/size_t.h"

namespace portable_stl {
namespace sign_modifications_helpers {
  /**
   * @brief Helper class for list.
   * @tparam HeadType The type of the head element of the list.
   * @tparam TailType The type of the rest of the list.
   */
  template<class HeadType, class TailType> class Type_list final {
  public:
    /**
     * @brief The type of the head element of the list.
     */
    using Head = HeadType;
    /**
     * @brief The type of the rest of the list.
     */
    using Tail = TailType;
  };

  /**
   * @brief Helper class to get the head of the list.
   * @tparam TypeList The list type.
   * @tparam Size
   */
  template<class TypeList, ::portable_stl::size_t Size, bool = Size <= sizeof(typename TypeList::Head)>
  class find_first final {};

  /**
   * @brief Helper class to get the head of the list.
   * @tparam HeadType The type of the head element of the list.
   * @tparam TailType The type of the rest of the list.
   * @tparam Size
   */
  template<class HeadType, class TailType, ::portable_stl::size_t Size>
  class find_first<Type_list<HeadType, TailType>, Size, true> final {
  public:
    /**
     * @brief The result type.
     */
    using type = HeadType;
  };

  /**
   * @brief Helper class to get the head of the list.
   * @tparam HeadType The type of the head element of the list.
   * @tparam TailType The type of the rest of the list.
   * @tparam Size
   */
  template<class HeadType, class TailType, ::portable_stl::size_t Size>
  class find_first<Type_list<HeadType, TailType>, Size, false> final {
  public:
    /**
     * @brief The result type.
     */
    using type = typename find_first<TailType, Size>::type;
  };
} // namespace sign_modifications_helpers
} // namespace portable_stl

#endif /* PSTL_TYPE_LIST_H */
