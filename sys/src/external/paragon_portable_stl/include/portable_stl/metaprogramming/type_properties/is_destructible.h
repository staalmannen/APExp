// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_destructible.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_DESTRUCTIBLE_H
#define PSTL_IS_DESTRUCTIBLE_H

#include "../../utility/general/declval.h"
#include "../array_modifications/remove_all_extents.h"
#include "../composite_type/is_reference.h"
#include "../helper/integral_constant.h"
#include "../primary_type/is_function.h"

namespace portable_stl {
namespace type_properties_helpers {

  namespace is_reference_or_object {
    /**
     * @brief t_type can be destroyed.
     * Version for object.
     * @tparam t_type type for check.
     */
    template<class t_type, class> class is_destructible final {
      /**
       * @brief Detect destructor.
       * Version with destructor.
       * @tparam t_work_type type for check.
       * @param first helper arguments
       * @param second helper arguments
       * @return true;
       */
      template<class t_work_type, class = decltype(::portable_stl::declval<t_work_type &>().~t_work_type())>
      inline static ::portable_stl::true_type destructor_check(::portable_stl::size_t first, bool second) noexcept;

      /**
       * @brief Detect destructor.
       * @tparam t_work_type type for check.
       * @param first helper arguments
       * @param second helper arguments
       * @return false
       */
      template<class t_work_type>
      inline static ::portable_stl::false_type destructor_check(::portable_stl::size_t first,
                                                                ::portable_stl::size_t second) noexcept;

    public:
      /**
       * @brief Result type.
       */
      using type = decltype(destructor_check<::portable_stl::remove_all_extents_t<t_type>>(0U, true));
    };

    /**
     * @brief t_type can be destroyed.
     * Version for reference.
     * @tparam t_type type for check.
     */
    template<class t_type> class is_destructible<t_type, ::portable_stl::true_type> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::true_type;
    };

  } // namespace is_reference_or_object

  namespace is_function {
    /**
     * @brief t_type can be destroyed.
     *
     * @tparam t_type type for check.
     */
    template<class t_type, class> class is_destructible final {
    public:
      /**
       * @brief Result type.
       */
      using type = typename is_reference_or_object::is_destructible<t_type, ::portable_stl::is_reference<t_type>>::type;
    };

    /**
     * @brief t_type can be destroyed.
     * Version for function.
     * @tparam t_type type for check.
     */
    template<class t_type> class is_destructible<t_type, ::portable_stl::true_type> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };
  } // namespace is_function

  /**
   * @brief t_type can be destroyed.
   *
   * @tparam t_type type for check.
   */
  template<class t_type> class is_destructible final {
  public:
    /**
     * @brief Result type.
     */
    using type = typename is_function::is_destructible<t_type, ::portable_stl::is_function<t_type>>::type;
  };
  /**
   * @brief t_type can be destroyed.
   * Version for array.
   * @tparam t_type type for check.
   */
  template<class t_type> class is_destructible<t_type[]> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };
  /**
   * @brief t_type can be destroyed.
   * Version for void.
   */
  template<> class is_destructible<void> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };
} // namespace type_properties_helpers

/**
 * @brief t_type can be destroyed.
 *
 * @tparam t_type type for check.
 */
template<class t_type> using is_destructible = typename type_properties_helpers::is_destructible<t_type>::type;
} // namespace portable_stl

#endif // PSTL_IS_DESTRUCTIBLE_H
