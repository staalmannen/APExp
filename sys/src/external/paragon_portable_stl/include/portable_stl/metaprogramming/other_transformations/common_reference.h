// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="common_reference.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COMMON_REFERENCE_H
#define PSTL_COMMON_REFERENCE_H

#include "../../utility/general/declval.h"
#include "../cv_modifications/copy_cv.h"
#include "../logical_operator/conjunction.h"
#include "../pointer_modifications/add_pointer.h"
#include "../primary_type/is_lvalue_reference.h"
#include "../primary_type/is_rvalue_reference.h"
#include "../reference_modifications/add_lvalue_reference.h"
#include "../reference_modifications/add_rvalue_reference.h"
#include "../reference_modifications/remove_reference.h"
#include "../type_relations/is_convertible.h"
#include "common_type.h"
#include "enable_if_bool_constant.h"
#include "remove_cvref.h"
#include "void_t.h"

namespace portable_stl {
namespace other_transformation_helper {
  /**
   * @brief Helper class COND-RES
   *
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2>
  using cond_res = decltype(false ? ::portable_stl::declval<T1 (&)()>()() : ::portable_stl::declval<T2 (&)()>()());

  /**
   * @brief xref<A>::template Apply is XREF(A) from N4950 [meta.trans.other]/2.2
   * @tparam T1 Given type.
   */
  template<class T1> class xref final {
  public:
    /**
     * @brief Modify operator.
     * @tparam T2 Given type.
     */
    template<class T2> using Apply = ::portable_stl::copy_cv_t<T1, T2>;
  };

  /**
   * @brief xref<A>::template Apply is XREF(A) from N4950 [meta.trans.other]/2.2
   * @tparam T1 Given type.
   */
  template<class T1> class xref<T1 &> final {
  public:
    /**
     * @brief Modify operator.
     * @tparam T2 Given type.
     */
    template<class T2> using Apply = ::portable_stl::copy_cv_t<T1, T2> &;
  };

  /**
   * @brief xref<A>::template Apply is XREF(A) from N4950 [meta.trans.other]/2.2
   * @tparam T1 Given type.
   */
  template<class T1> class xref<T1 &&> final {
  public:
    /**
     * @brief Modify operator.
     * @tparam T2 Given type.
     */
    template<class T2> using Apply = ::portable_stl::copy_cv_t<T1, T2> &&;
  };

  /**
   * @brief Helper to check if type if reference type.
   *
   * @tparam t_type Tested type.
   */
  template<class t_type>
  using is_reference = ::portable_stl::disjunction<::portable_stl::is_lvalue_reference<t_type>,
                                                   ::portable_stl::is_rvalue_reference<t_type>>;
} // namespace other_transformation_helper

/**
 * @brief Primary template.
 */
template<class, class, template<class> class, template<class> class> class basic_common_reference {};

/**
 * @brief Determines the common reference type of a group of types.
 */
template<class...> class common_reference {};

/**
 * @brief Determines the common reference type of a group of types.
 * @tparam t_types Given types.
 */
template<class... t_types> using common_reference_t = typename common_reference<t_types...>::type;

/**
 * @brief Determines the common reference type of a group of types.
 * N4950 [meta.trans.other]/5.1: "If sizeof...(T) is zero ..."
 * @tparam
 */
template<> class common_reference<> {};

/**
 * @brief Determines the common reference type of a group of types.
 * N4950 [meta.trans.other]/5.2: "...if sizeof...(T) is one ..."
 * @tparam t_type
 */
template<class t_type> class common_reference<t_type> {
public:
  /**
   * @brief Result type.
   */
  using type = t_type;
};

namespace other_transformation_helper {
  /**
   * @brief Helper.
   * N4950 [meta.trans.other]/5.3.2: "if basic_common_reference<[...]>::type is well-formed..."
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2>
  using Basic_specialization = typename ::portable_stl::basic_common_reference<::portable_stl::remove_cvref_t<T1>,
                                                                               ::portable_stl::remove_cvref_t<T2>,
                                                                               xref<T1>::template Apply,
                                                                               xref<T2>::template Apply>::type;

  /**
   * @brief COMMON-REF() impl.
   * Primary template.
   */
  template<class, class, class = void> class COMMON_REF_impl {};

  /**
   * @brief Result type of COMMON-REF(T1, T2).
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2> using COMMON_REF = typename COMMON_REF_impl<T1, T2>::type;

  /**
   * @brief Helper.
   * N4950 [meta.trans.other]/2.5:
   * COND-RES(COPYCV(X, Y) &, COPYCV(Y, X) &)
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2>
  using cond_res_cvref = cond_res<::portable_stl::copy_cv_t<T1, T2> &, ::portable_stl::copy_cv_t<T2, T1> &>;

  /**
   * @brief Helper.
   * Primary template.
   */
  template<class, class, class = ::portable_stl::false_type> class COMMON_REF_impl_sub1 {};

  /**
   * @brief Helper.
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2> class COMMON_REF_impl_sub1<T1, T2, ::portable_stl::true_type> {
  public:
    /**
     * @brief Result type.
     */
    using type = cond_res_cvref<T1, T2>;
  };

  /**
   * @brief COMMON-REF() impl.
   * "both lvalues" case from N4950 [meta.trans.other]/2.5
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2>
  class COMMON_REF_impl<T1 &, T2 &, ::portable_stl::void_t<cond_res_cvref<T1, T2>>>
      : public COMMON_REF_impl_sub1<T1, T2, is_reference<cond_res_cvref<T1, T2>>> {};

  /**
   * @brief Helper.
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2> using common_ref_C = ::portable_stl::remove_reference_t<COMMON_REF<T1 &, T2 &>> &&;

  /**
   * @brief Helper.
   * Primary template.
   */
  template<class, class, class = ::portable_stl::false_type> class COMMON_REF_impl_sub2 {};

  /**
   * @brief Helper.
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2> class COMMON_REF_impl_sub2<T1, T2, ::portable_stl::true_type> {
  public:
    /**
     * @brief Result type.
     */
    using type = common_ref_C<T1, T2>;
  };

  /**
   * @brief COMMON-REF() impl.
   * "both rvalues" case from N4950 [meta.trans.other]/2.6
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2>
  class COMMON_REF_impl<T1 &&, T2 &&, ::portable_stl::void_t<common_ref_C<T1, T2>>>
      : public COMMON_REF_impl_sub2<
          T1,
          T2,
          ::portable_stl::conjunction<::portable_stl::is_convertible<T1 &&, common_ref_C<T1, T2>>,
                                      ::portable_stl::is_convertible<T2 &&, common_ref_C<T1, T2>>>> {};

  /**
   * @brief Helper.
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2> using common_ref_D = COMMON_REF<T1 const &, T2 &>;

  /**
   * @brief Helper.
   * Primary template.
   */
  template<class, class, class = ::portable_stl::false_type> class COMMON_REF_impl_sub3 {};

  /**
   * @brief Helper.
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2> class COMMON_REF_impl_sub3<T1, T2, ::portable_stl::true_type> {
  public:
    /**
     * @brief Result type.
     */
    using type = common_ref_D<T1, T2>;
  };

  /**
   * @brief COMMON-REF() impl.
   * "rvalue and lvalue" case from N4950 [meta.trans.other]/2.7
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2>
  class COMMON_REF_impl<T1 &&, T2 &, ::portable_stl::void_t<common_ref_C<T1, T2>>>
      : public COMMON_REF_impl_sub3<T1, T2, ::portable_stl::is_convertible<T1 &&, common_ref_D<T1, T2>>> {};

  /**
   * @brief COMMON-REF() impl.
   * "lvalue and rvalue" case from N4950 [meta.trans.other]/2.8
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2> class COMMON_REF_impl<T1 &, T2 &&> : public COMMON_REF_impl<T2 &&, T1 &> {};

  /**
   * @brief common_reference implementation.
   *
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   * @tparam _Bullet
   */
  template<class T1, class T2, int _Bullet = 1, class = void>
  class common_reference_impl : public common_reference_impl<T1, T2, _Bullet + 1> {};

  /**
   * @brief common_reference implementation.
   * If T1 and T2 are reference types and COMMON-REF(T1, T2) is well-formed, ...
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2>
  class common_reference_impl<T1 &, T2 &, 1, ::portable_stl::void_t<COMMON_REF<T1 &, T2 &>>> {
  public:
    /**
     * @brief Result type.
     */
    using type = COMMON_REF<T1 &, T2 &>;
  };

  /**
   * @brief common_reference implementation.
   * If T1 and T2 are rvalue reference types and COMMON-REF(T1, T2) is well-formed, ...
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2>
  class common_reference_impl<T1 &&, T2 &&, 1, ::portable_stl::void_t<COMMON_REF<T1 &&, T2 &&>>> {
  public:
    /**
     * @brief Result type.
     */
    using type = COMMON_REF<T1 &&, T2 &&>;
  };

  /**
   * @brief common_reference implementation.
   * If T1 is a reference and T2 is a rvalue reference types and COMMON-REF(T1, T2) is well-formed, ...
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2>
  class common_reference_impl<T1 &, T2 &&, 1, ::portable_stl::void_t<COMMON_REF<T1 &, T2 &&>>> {
  public:
    /**
     * @brief Result type.
     */
    using type = COMMON_REF<T1 &, T2 &&>;
  };

  /**
   * @brief common_reference implementation.
   * If T2 is a reference and T1 is a rvalue reference types and COMMON-REF(T1, T2) is well-formed, ...
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2>
  class common_reference_impl<T1 &&, T2 &, 1, ::portable_stl::void_t<COMMON_REF<T1 &&, T2 &>>> {
  public:
    /**
     * @brief Result type.
     */
    using type = COMMON_REF<T1 &&, T2 &>;
  };

  /**
   * @brief common_reference implementation.
   * Otherwise, if basic_common_reference<...>::type is well-formed, ...
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2>
  class common_reference_impl<T1, T2, 2, ::portable_stl::void_t<Basic_specialization<T1, T2>>> {
  public:
    /**
     * @brief Result type.
     */
    using type = Basic_specialization<T1, T2>;
  };

  /**
   * @brief common_reference implementation.
   * Otherwise, if COND-RES(T1, T2) is well-formed, ...
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2>
  class common_reference_impl<T1,
                              T2,
                              3,
                              ::portable_stl::void_t<decltype(::portable_stl::declval<T1 (&)()>()()),
                                                     decltype(::portable_stl::declval<T2 (&)()>()()),
                                                     cond_res<T1, T2>>> {
  public:
    /**
     * @brief Result type.
     */
    using type = cond_res<T1, T2>;
  };

  /**
   * @brief common_reference implementation.
   * Otherwise, if common_type_t<T1, T2> is well-formed, ...
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2>
  class common_reference_impl<T1, T2, 4, ::portable_stl::void_t<::portable_stl::common_type_t<T1, T2>>> {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::common_type_t<T1, T2>;
  };

  /**
   * @brief common_reference implementation.
   * Otherwise, there shall be no member type.
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   */
  template<class T1, class T2> class common_reference_impl<T1, T2, 5, void> {};

  /**
   * @brief common_reference implementation.
   * Primary template.
   * @tparam AlwaysVoid
   * @tparam T1
   * @tparam T2
   * @tparam Rest
   */
  template<class AlwaysVoid, class T1, class T2, class... Rest> class common_reference_multi_impl {};

  /**
   * @brief common_reference implementation.
   *
   * @tparam T1 Given type.
   * @tparam T2 Given type.
   * @tparam Rest Given types.
   */
  template<class T1, class T2, class... Rest>
  class common_reference_multi_impl<::portable_stl::void_t<typename common_reference<T1, T2>::type>, T1, T2, Rest...>
      : public common_reference<typename common_reference<T1, T2>::type, Rest...> {};
} // namespace other_transformation_helper

/**
 * @brief Determines the common reference type of the types T1, T2.
 * If sizeof...(T) is two ...
 * @tparam T1 Given type.
 * @tparam T2 Given type.
 */
template<class T1, class T2>
class common_reference<T1, T2> : public other_transformation_helper::common_reference_impl<T1, T2> {};

/**
 * @brief Determines the common reference type of the types T1, T2, Rest... .
 *
 * @tparam T1 Given type.
 * @tparam T2 Given type.
 * @tparam Rest Given types.
 */
template<class T1, class T2, class... Rest>
class common_reference<T1, T2, Rest...>
    : public other_transformation_helper::common_reference_multi_impl<void, T1, T2, Rest...> {};

}; // namespace portable_stl

#endif /* PSTL_COMMON_REFERENCE_H */
