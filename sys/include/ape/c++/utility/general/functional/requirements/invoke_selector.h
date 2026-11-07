// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="invoke_selector.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INVOKE_SELECTOR_H
#define PSTL_INVOKE_SELECTOR_H

#include "../../../../metaprogramming/composite_type/is_member_pointer.h"
#include "../../../../metaprogramming/helper/integral_constant.h"
#include "../../../../metaprogramming/logical_operator/disjunction.h"
#include "../../../../metaprogramming/other_transformations/decay.h"
#include "../../../../metaprogramming/other_transformations/remove_cvref.h"
#include "../../../../metaprogramming/type_properties/is_reference_wrapper.h"
#include "../../../../metaprogramming/type_relations/is_base_of.h"
#include "../../../../metaprogramming/type_relations/is_same.h"
#include "../../../../utility/general/declval.h"
#include "../../../../utility/general/forward.h"

namespace std {
namespace functional_helper {

  namespace function_getter {
    /**
     * @brief Helper class for work with member function.
     * Specification for t_object is pointer like object.
     */
    template<class, class> class invoke_selector final {
    public:
      /**
       * @brief Result getter.
       * @tparam t_function the type of function.
       * @tparam t_class the type of function class.
       * @tparam t_object_pointer the type of object with function.
       * @tparam t_arguments the type of arguments for calling.
       * @param function the function.
       * @param object_pointer the object pointer with function.
       * @param arguments the arguments.
       * @return the result of calling function.
       */
      template<class t_function, class t_class, class t_object_pointer, class... t_arguments>
      constexpr inline static auto
        get(t_function t_class::*function, t_object_pointer &&object_pointer, t_arguments &&...arguments) noexcept(
          noexcept((*(::std::forward<t_object_pointer>(object_pointer)).*function)(
            ::std::forward<t_arguments>(arguments)...)))
          -> decltype((*(::std::forward<t_object_pointer>(object_pointer)).*function)(
            ::std::forward<t_arguments>(arguments)...)) {
        return (*(::std::forward<t_object_pointer>(object_pointer)).*function)(
          ::std::forward<t_arguments>(arguments)...);
      }
    };

    /**
     * @brief Helper class for work with member function.
     * Specification for t_object is function pointer object.
     */
    template<> class invoke_selector<::std::true_type, ::std::false_type> final {
    public:
      /**
       * @brief Result getter.
       * @tparam t_function the type of function.
       * @tparam t_class the type of function class.
       * @tparam t_object the type of object with function.
       * @tparam t_arguments the type of arguments for calling.
       * @param function the function.
       * @param object the object with function.
       * @param arguments the arguments.
       * @return the result of calling function.
       */
      template<class t_function, class t_class, class t_object, class... t_arguments>
      constexpr inline static auto
        get(t_function t_class::*function, t_object &&object, t_arguments &&...arguments) noexcept(noexcept(
          (::std::forward<t_object>(object).*function)(::std::forward<t_arguments>(arguments)...)))
          -> decltype((::std::forward<t_object>(object).*function)(
            ::std::forward<t_arguments>(arguments)...)) {
        return (::std::forward<t_object>(object).*function)(
          ::std::forward<t_arguments>(arguments)...);
      }
    };

    /**
     * @brief Helper class for work with member function.
     * Specification for t_object is reference wrapper object.
     */
    template<> class invoke_selector<::std::false_type, ::std::true_type> final {
    public:
      /**
       * @brief Result getter.
       * @tparam t_function the type of function.
       * @tparam t_class the type of function class.
       * @tparam t_wrapped_object the type of wrapped_object with function.
       * @tparam t_args the type of arguments for calling.
       * @param function the function.
       * @param wrapped_object the wrapped_object with function.
       * @param arguments the arguments.
       * @return the result of calling function.
       */
      template<class t_function, class t_class, class t_wrapped_object, class... t_arguments>
      constexpr inline static auto
        get(t_function t_class::*function, t_wrapped_object &&wrapped_object, t_arguments &&...arguments) noexcept(
          noexcept((wrapped_object.get().*function)(::std::forward<t_arguments>(arguments)...)))
          -> decltype((wrapped_object.get().*function)(::std::forward<t_arguments>(arguments)...)) {
        return (wrapped_object.get().*function)(::std::forward<t_arguments>(arguments)...);
      }
    };

  } // namespace function_getter

  namespace object_getter {
    /**
     * @brief Helper class for work with member value.
     * Specification for t_object is pointer like object.
     */
    template<class, class> class invoke_selector final {
    public:
      /**
       * @brief Result getter.
       * @tparam t_value the type of value.
       * @tparam t_class the type of value class.
       * @tparam t_object the type of object with value.
       * @param value the value.
       * @param object_pointer the pointer to object with value.
       * @return the value.
       */
      template<class t_value, class t_class, class t_object>
      constexpr inline static t_value get(t_value t_class::*value, t_object &&object_pointer) noexcept(
        noexcept(*(::std::forward<t_object>(object_pointer)).*value)) {
        return *(::std::forward<t_object>(object_pointer)).*value;
      }
    };

    /**
     * @brief Helper class for work with member value.
     * Specification for t_object is member pointer object.
     */
    template<> class invoke_selector<::std::true_type, ::std::false_type> final {
    public:
      /**
       * @brief Result getter.
       * @tparam t_value the type of value.
       * @tparam t_class the type of value class.
       * @tparam t_object the type of object with value.
       * @param value the value.
       * @param object the object with value.
       * @return the result of calling value.
       */
      template<class t_value, class t_class, class t_object>
      constexpr inline static t_value get(t_value t_class::*value, t_object &&object) noexcept(
        noexcept(::std::forward<t_object>(object).*value)) {
        return ::std::forward<t_object>(object).*value;
      }
    };

    /**
     * @brief Helper class for work with member value.
     * Specification for t_object is reference wrapper object.
     */
    template<> class invoke_selector<::std::false_type, ::std::true_type> final {
    public:
      /**
       * @brief Result getter.
       * @tparam t_value the type of value.
       * @tparam t_class the type of value class.
       * @tparam t_wrapped_object the type of reference wrapper object with value.
       * @param value the value.
       * @param wrapped_object the reference wrapper object with value.
       * @return the result of calling value.
       */
      template<class t_value, class t_class, class t_wrapped_object>
      constexpr inline static t_value get(t_value t_class::*value, t_wrapped_object &&wrapped_object) noexcept(
        noexcept(wrapped_object.get().*value)) {
        return wrapped_object.get().*value;
      }
    };

  } // namespace object_getter

  namespace member_getter {
    /**
     * @brief Helper for select valid result getter.
     * Version for member value.
     */
    template<class> class invoke_selector final {
      /**
       * @brief Helper for select valid result getter.
       *
       * @tparam t_class the type class with value member.
       * @tparam t_object the type object with value member.
       */
      template<class t_class, class t_object>
      using getter_type = object_getter::invoke_selector<
        ::std::disjunction<::std::is_same<t_class, ::std::remove_cvref_t<t_object>>,
                                    ::std::is_base_of<t_class, ::std::remove_cvref_t<t_object>>>,
        ::std::is_reference_wrapper<::std::decay_t<t_object>>>;

    public:
      /**
       * @brief Get value.
       *
       * @tparam t_value the type of value member.
       * @tparam t_class the type class with value member.
       * @tparam t_object the type object with value member.
       * @param value the value member.
       * @param object  the object with value member.
       * @return the value.
       */
      template<class t_value, class t_class, class t_object>
      constexpr inline static t_value get(t_value t_class::*value, t_object &&object) noexcept(
        noexcept(getter_type<t_class, t_object>::get(value, ::std::forward<t_object>(object)))) {
        return getter_type<t_class, t_object>::get(value, ::std::forward<t_object>(object));
      }
    };

    /**
     * @brief Helper for select valid result getter.
     * Version for member function.
     */
    template<> class invoke_selector<::std::true_type> final {
      /**
       * @brief Helper for select valid result getter(function call).
       *
       * @tparam t_class the type class with value member.
       * @tparam t_object the type object with value member.
       */
      template<class t_class, class t_object>
      using caller_type = function_getter::invoke_selector<
        ::std::disjunction<::std::is_same<t_class, ::std::remove_cvref_t<t_object>>,
                                    ::std::is_base_of<t_class, ::std::remove_cvref_t<t_object>>>,
        ::std::is_reference_wrapper<::std::decay_t<t_object>>>;

    public:
      /**
       * @brief Call function with arguments.
       * @tparam t_function the type of function.
       * @tparam t_arguments the types of arguments for function call.
       * @param function the function.
       * @param object the object with function.
       * @param arguments the arguments.
       * @return result of function call.
       */
      template<class t_function, class t_class, class t_object, class... t_arguments>
      constexpr inline static auto
        get(t_function t_class::*function, t_object &&object, t_arguments &&...arguments) noexcept(
          noexcept(caller_type<t_class, t_object>::get(
            function, ::std::forward<t_object>(object), ::std::forward<t_arguments>(arguments)...)))
          -> decltype(caller_type<t_class, t_object>::get(
            function, ::std::forward<t_object>(object), ::std::forward<t_arguments>(arguments)...)) {
        return caller_type<t_class, t_object>::get(
          function, ::std::forward<t_object>(object), ::std::forward<t_arguments>(arguments)...);
      }
    };
  } // namespace member_getter

  /**
   * @brief Helper for select valid result getter.
   * Version for pointer to function.
   */
  template<class> class invoke_selector final {
  public:
    /**
     * @brief Call function with arguments.
     * @tparam t_function the type of function.
     * @tparam t_arguments the types of arguments for function call.
     * @param function the function.
     * @param arguments the arguments.
     * @return result of function call.
     */
    template<class t_function, class... t_arguments>
    constexpr inline static auto get(t_function &&function, t_arguments &&...arguments) noexcept(
      noexcept(::std::forward<t_function>(function)(::std::forward<t_arguments>(arguments)...)))
      -> decltype(::std::forward<t_function>(function)(::std::forward<t_arguments>(arguments)...)) {
      return ::std::forward<t_function>(function)(::std::forward<t_arguments>(arguments)...);
    }
  };

  /**
   * @brief Helper for select valid result getter.
   * Version for member object.
   */
  template<> class invoke_selector<::std::true_type> final {
  public:
    /**
     * @brief Get result of member(value or function call).
     * @tparam t_member the type of member(value or function).
     * @tparam t_arguments the types of arguments for function call.
     * @param member the member(value or function).
     * @param arguments the arguments.
     * @return result of member(value or function call).
     */
    template<class t_member, class t_class, class... t_arguments>
    constexpr inline static auto get(t_member t_class::*member, t_arguments &&...arguments) noexcept(
      noexcept(member_getter::invoke_selector<::std::is_function<t_member>>::get(
        member, ::std::forward<t_arguments>(arguments)...)))
      -> decltype(member_getter::invoke_selector<::std::is_function<t_member>>::get(
        member, ::std::forward<t_arguments>(arguments)...)) {
      return member_getter::invoke_selector<::std::is_function<t_member>>::get(
        member, ::std::forward<t_arguments>(arguments)...);
    }
  };
  /**
   * @brief Helper for select valid result getter.
   * @tparam t_callable_type the type result holder(function or class member value).
   * @tparam t_args the types of arguments for function call.
   */
  template<class t_callable_type, class... t_args>
  using invoke_selector_helper = invoke_selector<::std::is_member_pointer<t_callable_type>>;

} // namespace functional_helper
} // namespace std

#endif // PSTL_INVOKE_SELECTOR_H
