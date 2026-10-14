// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="make_unsigned_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MAKE_UNSIGNED_IMPL_H
#define PSTL_MAKE_UNSIGNED_IMPL_H

#include "../../../common/size_t.h"
#include "../../cv_modifications/copy_cv.h"
#include "../../logical_operator/disjunction.h"
#include "../../primary_type/is_enum.h"
#include "../../primary_type/is_integral.h"
#include "../../type_relations/is_same.h"
#include "../type_list.h"

namespace portable_stl {
namespace sign_modifications_helpers {
  /**
   * @brief Empty class.
   *
   */
  class nat_class2 final {};
  // clang-format off
  /**
   * @brief List of unsigned types in ascending order.
   * 
   */
  using unsinged_types =  ::portable_stl::sign_modifications_helpers::Type_list<unsigned char,
                        ::portable_stl::sign_modifications_helpers::Type_list<unsigned short,
                        ::portable_stl::sign_modifications_helpers::Type_list<unsigned int,
                        ::portable_stl::sign_modifications_helpers::Type_list<unsigned long,
                        ::portable_stl::sign_modifications_helpers::Type_list<unsigned long long,
                        nat_class2>>>>>;
  // clang-format on

  /**
   * @brief Makes the given integral type signed.
   * Ignor a non-integral (except bool) or non enumeration type.
   * @tparam t_type Type for conversion.
   */
  template<class t_type,
           class = ::portable_stl::disjunction<::portable_stl::is_integral<t_type>, ::portable_stl::is_enum<t_type>>>
  class make_unsigned_impl final {};

  /**
   * @brief Makes the given integral type unsigned.
   * If t_type is an enumeration type or char, wchar_t, char8_t(since C++20), char16_t, char32_t, the unsigned integer
   * type with the smallest rank having the same sizeof as t_type is provided.
   * @tparam t_type Type for conversion.
   */
  template<class t_type> class make_unsigned_impl<t_type, ::portable_stl::true_type> final {
  public:
    /**
     * @brief The result type.
     */
    using type = typename ::portable_stl::sign_modifications_helpers::find_first<unsinged_types, sizeof(t_type)>::type;
  };

  /**
   * @brief bool specialization.
   * No type.
   */
  template<> class make_unsigned_impl<bool, ::portable_stl::true_type>         final {};
  /**
   * @brief short specialization.
   */
  template<> class make_unsigned_impl<signed short, ::portable_stl::true_type> final {
  public:
    /**
     * @brief The result type.
     */
    using type = unsigned short;
  };
  /**
   * @brief short specialization.
   */
  template<> class make_unsigned_impl<unsigned short, ::portable_stl::true_type> final {
  public:
    /**
     * @brief The result type.
     */
    using type = unsigned short;
  };
  /**
   * @brief int specialization.
   */
  template<> class make_unsigned_impl<signed int, ::portable_stl::true_type> final {
  public:
    /**
     * @brief The result type.
     */
    using type = unsigned int;
  };
  /**
   * @brief int specialization.
   */
  template<> class make_unsigned_impl<unsigned int, ::portable_stl::true_type> final {
  public:
    /**
     * @brief The result type.
     */
    using type = unsigned int;
  };
  /**
   * @brief long specialization.
   */
  template<> class make_unsigned_impl<signed long, ::portable_stl::true_type> final {
  public:
    /**
     * @brief The result type.
     */
    using type = unsigned long;
  };
  /**
   * @brief long specialization.
   */
  template<> class make_unsigned_impl<unsigned long, ::portable_stl::true_type> final {
  public:
    /**
     * @brief The result type.
     */
    using type = unsigned long;
  };
  /**
   * @brief long long specialization.
   */
  template<> class make_unsigned_impl<signed long long, ::portable_stl::true_type> final {
  public:
    /**
     * @brief The result type.
     */
    using type = unsigned long long;
  };
  /**
   * @brief long long specialization.
   */
  template<> class make_unsigned_impl<unsigned long long, ::portable_stl::true_type> final {
  public:
    /**
     * @brief The result type.
     */
    using type = unsigned long long;
  };

  /**
   * @brief Makes the given integral type unsigned.
   *
   * @tparam t_type Type for conversion.
   */
  template<class t_type>
  using make_unsigned_t_impl
    = ::portable_stl::copy_cv_t<typename make_unsigned_impl<::portable_stl::remove_cv_t<t_type>>::type, t_type>;
} // namespace sign_modifications_helpers
} // namespace portable_stl
#endif // PSTL_MAKE_UNSIGNED_IMPL_H
