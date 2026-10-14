// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="function.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FUNCTION_H
#define PSTL_FUNCTION_H

#include "../common/byte.h"
#include "../common/nullptr_t.h"
#include "../error/portable_stl_error.h"
#include "../language_support/bad_alloc.h"
#include "../language_support/bad_function_call.h"
#include "../language_support/typeinfo/type_info.h"
#include "../memory/addressof.h"
#include "../memory/allocate_noexcept.h"
#include "../memory/allocator.h"
#include "../memory/allocator_arg.h"
#include "../memory/allocator_destructor.h"
#include "../memory/allocator_traits.h"
#include "../memory/compressed_pair.h"
#include "../memory/rebind_alloc.h"
#include "../memory/unique_ptr.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/disjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/decay.h"
#include "../metaprogramming/other_transformations/enable_if.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/remove_cvref.h"
#include "../metaprogramming/primary_type/is_void.h"
#include "../metaprogramming/type_properties/is_nothrow_copy_constructible.h"
#include "../metaprogramming/type_relations/is_invocable.h"
#include "../metaprogramming/type_relations/is_same.h"
#include "../metaprogramming/type_traits/invoke_void_return_wrapper.h"
#include "../metaprogramming/type_traits/is_core_convertible.h"
#include "../utility/expected/expected.h"
#include "../utility/expected/unexpected.h"
#include "../utility/general/forward.h"
#include "../utility/general/functional/invoke_impl.h"
#include "../utility/general/move.h"
#include "../utility/general/swap.h"
#include "../utility/tuple/tuple_forward_as.h"
#include "binary_function.h"
#include "unary_function.h"

#if defined(__cpp_exceptions) || defined(_CPPUNWIND)
#  include "../language_support/exception/throw_on_true.h"
#else
#  include "../language_support/no_exception/throw_on_true.h"
#endif

#if !(defined(__cpp_rtti) || defined(_CPPRTTI))
#  include "no_rtti/typeid_wrap.h"
#else
#  include "rtti/typeid_wrap.h"
#endif

namespace portable_stl {

/**
 * @brief Forward declaration.
 *
 * @tparam t_func_type Callable type.
 */
template<class t_func_type> class function;

namespace function_helper {
  template<class t_return_type> class maybe_derive_from_unary_function {};

  template<class t_return_type, class t_arg1>
  class maybe_derive_from_unary_function<t_return_type(t_arg1)>
      : public portable_stl::unary_function_depr<t_arg1, t_return_type> {};

  template<class t_return_type> class maybe_derive_from_binary_function {};

  template<class t_return_type, class t_arg1, class t_arg2>
  class maybe_derive_from_binary_function<t_return_type(t_arg1, t_arg2)>
      : public ::portable_stl::binary_function_depr<t_arg1, t_arg2, t_return_type> {};

  template<class t_func_type> bool not_null(t_func_type const &) {
    return true;
  }

  template<class t_func_type> bool not_null(t_func_type *ptr) {
    return nullptr != ptr;
  }

  template<class _Ret, class _Class> bool not_null(_Ret _Class::*ptr) {
    return nullptr != ptr;
  }

  template<class t_func_type> bool not_null(function<t_func_type> const &func) {
    return !!func;
  }

  // #ifdef _LIBCPP_HAS_EXTENSION_BLOCKS
  //   template<class t_return_type, class... t_args> bool not_null(t_return_type (^__p)(t_args...)) {
  //     return __p;
  //   }
  // #endif

  // alloc_func holds a functor and an allocator.

  template<class t_func_type, class t_alloc_type, class _FB> class alloc_func;

  template<class t_func_type, class t_alloc_type, class t_return_type, class... t_arg_types>
  class alloc_func<t_func_type, t_alloc_type, t_return_type(t_arg_types...)> {
    ::portable_stl::compressed_pair<t_func_type, t_alloc_type> m_func_alloc;

  public:
    using t_target = t_func_type;
    using t_alloc  = t_alloc_type;

    t_target const &get_target() const {
      return m_func_alloc.get_first();
    }

    t_alloc const &get_allocator() const {
      return m_func_alloc.get_second();
    }

    explicit alloc_func(t_target &&func) : m_func_alloc(::portable_stl::move(func)) {
    }

    explicit alloc_func(t_target const &func, t_alloc const &alloc) : m_func_alloc(func, alloc) {
    }

    explicit alloc_func(t_target const &func, t_alloc &&alloc) : m_func_alloc(func, ::portable_stl::move(alloc)) {
    }

    explicit alloc_func(t_target &&func, t_alloc &&alloc)
        : m_func_alloc(::portable_stl::move(func), ::portable_stl::move(alloc)) {
    }

    t_return_type operator()(t_arg_types &&...args) {
      using t_invoker = ::portable_stl::invoke_void_return_wrapper<t_return_type>;
      return t_invoker::call(m_func_alloc.get_first(), ::portable_stl::forward<t_arg_types>(args)...);
    }

    /**
     * @brief
     *
     * @return alloc_func* pointer to copy of self or nullptr if no memory was allocated.
     */
    alloc_func *clone() const {
      using t_alloc_traits   = ::portable_stl::allocator_traits<t_alloc>;
      using t_func_allocator = ::portable_stl::rebind_alloc<t_alloc_traits, alloc_func>;
      t_func_allocator alloc(m_func_alloc.second());

      using t_deleter = ::portable_stl::allocator_destructor<t_func_allocator>;
      ::portable_stl::unique_ptr<alloc_func, t_deleter> holder(alloc.allocate(1), t_deleter(alloc, 1));
      if (holder.get()) {
        ::new (static_cast<void *>(holder.get())) alloc_func(m_func_alloc.first(), t_alloc(alloc));
        return holder.release();
      }
      return nullptr;
    }

    void destroy() noexcept {
      m_func_alloc.~compressed_pair<t_target, t_alloc>();
    }

    static void destroy_and_delete(alloc_func *func) {
      using t_alloc_traits   = ::portable_stl::allocator_traits<t_alloc>;
      using t_func_allocator = ::portable_stl::rebind_alloc<t_alloc_traits, alloc_func>;
      t_func_allocator alloc(func->get_allocator());
      func->destroy();
      alloc.deallocate(func, 1);
    }
  };

  // base provides an abstract interface for copyable functors.

  template<class t_func_type> class base;

  template<class t_return_type, class... t_arg_types> class base<t_return_type(t_arg_types...)> {
    base(base const &);
    base &operator=(base const &);

  public:
    base() {
    }

    virtual ~base() {
    }

    virtual base         *clone() const                                            = 0;
    virtual void          clone(base *) const                                      = 0;
    virtual void          destroy() noexcept                                       = 0;
    virtual void          destroy_deallocate() noexcept                            = 0;
    virtual t_return_type operator()(t_arg_types &&...)                            = 0;
    virtual void const   *target(::portable_stl::type_info const &) const noexcept = 0;
    // virtual ::portable_stl::type_info const &target_type() const noexcept                             = 0;
  };

  // func implements base for a given functor type.
  // derived class for specific implementation types that use allocators

  template<class _FD, class t_alloc, class _FB> class func;

  template<class t_func_type, class t_alloc, class t_return_type, class... t_arg_types>
  class func<t_func_type, t_alloc, t_return_type(t_arg_types...)> : public base<t_return_type(t_arg_types...)> {
    alloc_func<t_func_type, t_alloc, t_return_type(t_arg_types...)> m_f;

  public:
    explicit func(t_func_type &&fn) : m_f(::portable_stl::move(fn)) {
    }

    explicit func(t_func_type const &fn, t_alloc const &alloc) : m_f(fn, alloc) {
    }

    explicit func(t_func_type const &fn, t_alloc &&alloc) : m_f(fn, ::portable_stl::move(alloc)) {
    }

    explicit func(t_func_type &&fn, t_alloc &&alloc) : m_f(::portable_stl::move(fn), ::portable_stl::move(alloc)) {
    }

    base<t_return_type(t_arg_types...)> *clone() const override;
    void                                 clone(base<t_return_type(t_arg_types...)> *) const override;
    void                                 destroy() noexcept override;
    void                                 destroy_deallocate() noexcept override;
    t_return_type                        operator()(t_arg_types &&...args) override;
    void const                          *target(::portable_stl::type_info const &) const noexcept override;
    // virtual ::portable_stl::type_info const     &target_type() const noexcept;
  };

  /**
   * @brief
   *
   * @tparam t_func_type
   * @tparam t_alloc
   * @tparam t_return_type
   * @tparam t_arg_types
   * @return base<t_return_type(t_arg_types...)>* or nullptr if no memory was allocated.
   */
  template<class t_func_type, class t_alloc, class t_return_type, class... t_arg_types>
  base<t_return_type(t_arg_types...)> *func<t_func_type, t_alloc, t_return_type(t_arg_types...)>::clone() const {
    using t_alloc_traits   = allocator_traits<t_alloc>;
    using t_func_allocator = ::portable_stl::rebind_alloc<t_alloc_traits, func>;
    t_func_allocator alloc(m_f.get_allocator());

    using t_deleter = ::portable_stl::allocator_destructor<t_func_allocator>;
    ::portable_stl::unique_ptr<func, t_deleter> holder(alloc.allocate(1), t_deleter(alloc, 1));
    if (holder.get()) {
      ::new (static_cast<void *>(holder.get())) func(m_f.get_target(), t_alloc(alloc));
      return holder.release();
    }
    return nullptr;
  }

  template<class t_func_type, class t_alloc, class t_return_type, class... t_arg_types>
  void func<t_func_type, t_alloc, t_return_type(t_arg_types...)>::clone(
    base<t_return_type(t_arg_types...)> *ptr) const {
    ::new (static_cast<void *>(ptr)) func(m_f.get_target(), m_f.get_allocator());
  }

  template<class t_func_type, class t_alloc, class t_return_type, class... t_arg_types>
  void func<t_func_type, t_alloc, t_return_type(t_arg_types...)>::destroy() noexcept {
    m_f.destroy();
  }

  template<class t_func_type, class t_alloc, class t_return_type, class... t_arg_types>
  void func<t_func_type, t_alloc, t_return_type(t_arg_types...)>::destroy_deallocate() noexcept {
    using t_alloc_traits   = allocator_traits<t_alloc>;
    using t_func_allocator = ::portable_stl::rebind_alloc<t_alloc_traits, func>;
    t_func_allocator alloc(m_f.get_allocator());
    m_f.destroy();
    alloc.deallocate(this, 1);
  }

  template<class t_func_type, class t_alloc, class t_return_type, class... t_arg_types>
  t_return_type func<t_func_type, t_alloc, t_return_type(t_arg_types...)>::operator()(t_arg_types &&...args) {
    return m_f(::portable_stl::forward<t_arg_types>(args)...);
  }

  template<class t_func_type, class t_alloc, class t_return_type, class... t_arg_types>
  void const *func<t_func_type, t_alloc, t_return_type(t_arg_types...)>::target(
    ::portable_stl::type_info const &type_inf) const noexcept {
    if (type_inf == ::portable_stl::typeid_wrap<t_func_type>::value()) {
      return ::portable_stl::addressof(m_f.get_target());
    }
    return nullptr;
  }

  // template<class t_func_type, class t_alloc, class t_return_type, class... t_arg_types>
  // ::portable_stl::type_info const &
  //   func<t_func_type, t_alloc, t_return_type(t_arg_types...)>::target_type() const noexcept {
  //   return ::portable_stl::type_info(typeid(t_func_type));
  // }

  // value_func
  // creates a value-type from a func.
  // callcable storage entity
  // have storage optimization

  template<class t_func_type> class value_func;

  template<class t_return_type, class... t_arg_types> class value_func<t_return_type(t_arg_types...)> {
    // typename aligned_storage<3 * sizeof(void *)>::type m_buf;
    alignas(4 * sizeof(void *))::portable_stl::byte m_buf[4 * sizeof(void *)];

    using t_callable = base<t_return_type(t_arg_types...)>;

    t_callable *m_f;

    static t_callable *as_base(void *ptr) {
      return reinterpret_cast<t_callable *>(ptr);
    }

  public:
    value_func() noexcept : m_f(nullptr) {
    }

    template<class t_func_type, class t_alloc> class place_in_buf final {
      using t_alloc_traits   = ::portable_stl::allocator_traits<t_alloc>;
      using t_func           = function_helper::func<t_func_type, t_alloc, t_return_type(t_arg_types...)>;
      using t_func_allocator = ::portable_stl::rebind_alloc<t_alloc_traits, t_func>;

    public:
      using type = ::portable_stl::conjunction<::portable_stl::bool_constant<sizeof(t_func) <= (4 * sizeof(void *))>,
                                               is_nothrow_copy_constructible<t_func_type>,
                                               is_nothrow_copy_constructible<t_func_allocator>>;
    };

    template<class t_func_type,
             class t_alloc,
             ::portable_stl::enable_if_bool_constant_t<typename place_in_buf<t_func_type, t_alloc>::type, void *>
             = nullptr>
    value_func(t_func_type &&func, t_alloc const &alloc) : m_f(nullptr) {
      using t_alloc_traits   = ::portable_stl::allocator_traits<t_alloc>;
      using t_func           = function_helper::func<t_func_type, t_alloc, t_return_type(t_arg_types...)>;
      using t_func_allocator = ::portable_stl::rebind_alloc<t_alloc_traits, t_func>;

      if (function_helper::not_null(func)) {
        t_func_allocator func_alloc(alloc);

        m_f = ::new (static_cast<void *>(&m_buf)) t_func(::portable_stl::move(func), t_alloc(func_alloc));
      }
    }

    template<class t_func_type,
             class t_alloc,
             ::portable_stl::enable_if_bool_constant_t<
               ::portable_stl::negation<typename place_in_buf<t_func_type, t_alloc>::type>,
               void *>
             = nullptr>
    value_func(t_func_type &&func, t_alloc const &alloc) : m_f(nullptr) {
      using t_alloc_traits   = ::portable_stl::allocator_traits<t_alloc>;
      using t_func           = function_helper::func<t_func_type, t_alloc, t_return_type(t_arg_types...)>;
      using t_func_allocator = ::portable_stl::rebind_alloc<t_alloc_traits, t_func>;

      if (function_helper::not_null(func)) {
        t_func_allocator func_alloc(alloc);

        // place callable in heap
        auto func_mem = ::portable_stl::allocate_noexcept(func_alloc, 1U);
        if (func_mem) {
          /**
           * @brief func deleter.
           *
           */
          using t_deleter = ::portable_stl::allocator_destructor<t_func_allocator>;

          // holder-guard
          ::portable_stl::unique_ptr<t_callable, t_deleter> holder(func_mem, t_deleter(func_alloc, 1));

          // construct func in allocated mempry
          ::new (static_cast<void *>(holder.get())) t_func(::portable_stl::move(func), t_alloc(alloc));

          // commit guard
          m_f = holder.release();
        }
      }
    }

    template<class t_func_type,
             ::portable_stl::enable_if_bool_constant_t<
               ::portable_stl::negation<::portable_stl::is_same<::portable_stl::decay_t<t_func_type>, value_func>>,
               void *>
             = nullptr>
    explicit value_func(t_func_type &&func)
        : value_func(::portable_stl::forward<t_func_type>(func), ::portable_stl::allocator<t_func_type>()) {
    }

    value_func(value_func const &func) {
      if (nullptr == func.m_f) {
        m_f = nullptr;
      } else if ((void *)func.m_f == &func.m_buf) {
        m_f = as_base(&m_buf);
        func.m_f->clone(m_f);
      } else {
        m_f = func.m_f->clone();
        ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(!m_f);
      }
    }

    value_func(value_func &&func) noexcept {
      if (nullptr == func.m_f) {
        m_f = nullptr;
      } else if ((void *)func.m_f == &func.m_buf) {
        m_f = as_base(&m_buf);
        func.m_f->clone(m_f);
      } else {
        m_f      = func.m_f;
        func.m_f = nullptr;
      }
    }

    ~value_func() {
      if ((void *)m_f == &m_buf) {
        m_f->destroy();
      } else if (m_f) {
        m_f->destroy_deallocate();
      }
    }

    value_func &operator=(value_func &&func) {
      *this = nullptr;
      if (nullptr == func.m_f) {
        m_f = nullptr;
      } else if ((void *)func.m_f == &func.m_buf) {
        m_f = as_base(&m_buf);
        func.m_f->clone(m_f);
      } else {
        m_f      = func.m_f;
        func.m_f = nullptr;
      }
      return *this;
    }

    value_func &operator=(::portable_stl::nullptr_t) {
      t_callable *func = m_f;
      m_f              = nullptr;
      if ((void *)func == &m_buf) {
        func->destroy();
      } else if (func) {
        func->destroy_deallocate();
      }
      return *this;
    }

    t_return_type operator()(t_arg_types &&...args) const {
      ::portable_stl::throw_on_true<::portable_stl::bad_function_call<>>(nullptr == m_f);
      return (*m_f)(::portable_stl::forward<t_arg_types>(args)...);
    }

    void swap(value_func &func) noexcept {
      if (this == &func) {
        return;
      }

      if (((void *)m_f == &m_buf) && ((void *)func.m_f == &func.m_buf)) {
        // typename aligned_storage<sizeof(m_buf)>::type tmp_buf;
        alignas(sizeof(m_buf))::portable_stl::byte tmp_buf[sizeof(m_buf)];

        t_callable *tmp = as_base(&tmp_buf);
        m_f->clone(tmp);
        m_f->destroy();
        m_f = nullptr;
        func.m_f->clone(as_base(&m_buf));
        func.m_f->destroy();
        func.m_f = nullptr;
        m_f      = as_base(&m_buf);
        tmp->clone(as_base(&func.m_buf));
        tmp->destroy();
        func.m_f = as_base(&func.m_buf);
      } else if ((void *)m_f == &m_buf) {
        m_f->clone(as_base(&func.m_buf));
        m_f->destroy();
        m_f      = func.m_f;
        func.m_f = as_base(&func.m_buf);
      } else if ((void *)func.m_f == &func.m_buf) {
        func.m_f->clone(as_base(&m_buf));
        func.m_f->destroy();
        func.m_f = m_f;
        m_f      = as_base(&m_buf);
      } else {
        ::portable_stl::swap(m_f, func.m_f);
      }
    }

    explicit operator bool() const noexcept {
      return m_f != nullptr;
    }

    // ::portable_stl::type_info const &target_type() const noexcept {
    //   if (nullptr == m_f) {
    //     return ::portable_stl::type_info(typeid(void));
    //   }
    //   return m_f->target_type();
    // }

    template<typename t_type> t_type const *target() const noexcept {
      if (nullptr == m_f) {
        return nullptr;
      }
      return (t_type const *)m_f->target(::portable_stl::typeid_wrap<t_type>::value());
    }
  };

} // namespace function_helper

template<class t_return_type, class... t_arg_types>
class function<t_return_type(t_arg_types...)>
    : public function_helper::maybe_derive_from_unary_function<t_return_type(t_arg_types...)>
    , public function_helper::maybe_derive_from_binary_function<t_return_type(t_arg_types...)> {
// #ifndef _LIBCPP_ABI_OPTIMIZED_FUNCTION
  using t_func = function_helper::value_func<t_return_type(t_arg_types...)>;
// #else
//   using t_func = function_helper::__policy_func<t_return_type(t_arg_types...)>;
// #endif

  t_func m_f;

  template<class t_func_type,
           class = ::portable_stl::conjunction<
             ::portable_stl::negation<::portable_stl::is_same<::portable_stl::remove_cvref_t<t_func_type>, function>>,
             is_invocable<t_func_type, t_arg_types...>>>
  class callable final {
  public:
    using type = ::portable_stl::false_type;
  };

  template<class t_func_type> class callable<t_func_type, ::portable_stl::true_type> final {
  public:
    using type = ::portable_stl::disjunction<
      ::portable_stl::is_void<t_return_type>,
      ::portable_stl::is_core_convertible<::portable_stl::invoke_result_t<t_func_type, t_arg_types...>, t_return_type>>;
  };

  template<class t_func_type>
  using enable_if_lvalue_callable = ::portable_stl::enable_if_bool_constant_t<typename callable<t_func_type &>::type>;

public:
  using result_type = t_return_type;

  // construct/copy/destroy:
  function() noexcept {
  }

  function(::portable_stl::nullptr_t) noexcept {
  }

  function(function const &);

  function(function &&) noexcept;

  /**
   * @brief Initializes the target with forward<t_func_type>(func). The target is of type decay_t<t_func_type>.
   *
   * @tparam t_func_type
   * @tparam class
   * @param func
   */
  template<class t_func_type, class = enable_if_lvalue_callable<t_func_type>> function(t_func_type func);

  template<class t_func_type, class = enable_if_lvalue_callable<t_func_type>>
  static ::portable_stl::expected<function, ::portable_stl::portable_stl_error> make_function(t_func_type func);

  // allocator support was removed in C++17
  template<class t_func_type, class t_alloc, class = enable_if_lvalue_callable<t_func_type>>
  function(::portable_stl::allocator_arg_t, t_alloc const &alloc, t_func_type func);

  template<class t_func_type, class t_alloc, class = enable_if_lvalue_callable<t_func_type>>
  static ::portable_stl::expected<function, ::portable_stl::portable_stl_error> make_function(
    ::portable_stl::allocator_arg_t, t_alloc const &alloc, t_func_type func);

  // allocator support was removed in C++17
  template<class t_alloc> function(::portable_stl::allocator_arg_t, t_alloc const &) noexcept {
  }

  // allocator support was removed in C++17
  template<class t_alloc>
  function(::portable_stl::allocator_arg_t, t_alloc const &, ::portable_stl::nullptr_t) noexcept {
  }

  // allocator support was removed in C++17
  template<class t_alloc> function(::portable_stl::allocator_arg_t, t_alloc const &, function const &);

  // allocator support was removed in C++17
  template<class t_alloc> function(::portable_stl::allocator_arg_t, t_alloc const &, function &&);

  function &operator=(function const &);
  function &operator=(function &&) noexcept;
  function &operator=(::portable_stl::nullptr_t) noexcept;

  template<class t_func_type, class = enable_if_lvalue_callable<::portable_stl::decay_t<t_func_type>>>
  function &operator=(t_func_type &&);

  ~function();

  // function modifiers:
  void swap(function &) noexcept;

  template<class t_func_type, class t_alloc> void assign(t_func_type &&func, t_alloc const &alloc) {
    function(::portable_stl::allocator_arg, alloc, ::portable_stl::forward<t_func_type>(func)).swap(*this);
  }

  // function capacity:
  explicit operator bool() const noexcept {
    return static_cast<bool>(m_f);
  }

  // deleted overloads close possible hole in the type system
  template<class t_return_type2, class... t_arg_types2>
  bool operator==(function<t_return_type2(t_arg_types2...)> const &) const = delete;

public:
  // function invocation:
  t_return_type operator()(t_arg_types...) const;

  // function target access:
  // std::type_info const             &target_type() const noexcept;
  template<typename t_type> t_type       *target() noexcept;
  template<typename t_type> t_type const *target() const noexcept;
};

template<class t_return_type, class... t_arg_types>
template<class t_func_type, class>
function<t_return_type(t_arg_types...)>::function(t_func_type func) : m_f(::portable_stl::move(func)) {
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(function_helper::not_null(func) && !m_f);
}

template<class t_return_type, class... t_arg_types>
template<class t_func_type, class>
::portable_stl::expected<function<t_return_type(t_arg_types...)>, ::portable_stl::portable_stl_error>
  function<t_return_type(t_arg_types...)>::make_function(t_func_type func) {
  t_func result_func(::portable_stl::move(func));
  if (function_helper::not_null(func) && !result_func) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
      ::portable_stl::portable_stl_error::allocate_error};
  } else {
    function ret;
    ret.m_f = ::portable_stl::move(result_func);
    return ::portable_stl::expected<function, ::portable_stl::portable_stl_error>(::portable_stl::move(ret));
  }
}

template<class t_return_type, class... t_arg_types>
template<class t_func_type, class t_alloc, class>
function<t_return_type(t_arg_types...)>::function(
  ::portable_stl::allocator_arg_t, t_alloc const &alloc, t_func_type func)
    : m_f(::portable_stl::move(func), alloc) {
  ::portable_stl::throw_on_true<::portable_stl::bad_alloc<>>(function_helper::not_null(func) && !m_f);
}

template<class t_return_type, class... t_arg_types>
template<class t_func_type, class t_alloc, class>
::portable_stl::expected<function<t_return_type(t_arg_types...)>, ::portable_stl::portable_stl_error>
  function<t_return_type(t_arg_types...)>::make_function(
    ::portable_stl::allocator_arg_t, t_alloc const &alloc, t_func_type func) {
  t_func result_func(::portable_stl::move(func), alloc);
  if (function_helper::not_null(func) && !result_func) {
    return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
      ::portable_stl::portable_stl_error::allocate_error};
  } else {
    function ret;
    ret.m_f = ::portable_stl::move(result_func);
    return ::portable_stl::expected<function, ::portable_stl::portable_stl_error>(::portable_stl::move(ret));
  }
}

template<class t_return_type, class... t_arg_types>
function<t_return_type(t_arg_types...)>::function(function const &func) : m_f(func.m_f) {
}

template<class t_return_type, class... t_arg_types>
template<class t_alloc>
function<t_return_type(t_arg_types...)>::function(
  ::portable_stl::allocator_arg_t, t_alloc const &, function const &func)
    : m_f(func.m_f) {
}

template<class t_return_type, class... t_arg_types>
function<t_return_type(t_arg_types...)>::function(function &&func) noexcept : m_f(::portable_stl::move(func.m_f)) {
}

template<class t_return_type, class... t_arg_types>
template<class t_alloc>
function<t_return_type(t_arg_types...)>::function(::portable_stl::allocator_arg_t, t_alloc const &, function &&func)
    : m_f(::portable_stl::move(func.m_f)) {
}

template<class t_return_type, class... t_arg_types>
function<t_return_type(t_arg_types...)> &function<t_return_type(t_arg_types...)>::operator=(function const &func) {
  function(func).swap(*this);
  return *this;
}

template<class t_return_type, class... t_arg_types>
function<t_return_type(t_arg_types...)> &function<t_return_type(t_arg_types...)>::operator=(function &&func) noexcept {
  m_f = ::portable_stl::move(func.m_f);
  return *this;
}

template<class t_return_type, class... t_arg_types>
function<t_return_type(t_arg_types...)> &function<t_return_type(t_arg_types...)>::operator=(
  ::portable_stl::nullptr_t) noexcept {
  m_f = nullptr;
  return *this;
}

template<class t_return_type, class... t_arg_types>
template<class t_func_type, class>
function<t_return_type(t_arg_types...)> &function<t_return_type(t_arg_types...)>::operator=(t_func_type &&func) {
  function(::portable_stl::forward<t_func_type>(func)).swap(*this);
  return *this;
}

template<class t_return_type, class... t_arg_types> function<t_return_type(t_arg_types...)>::~function() {
}

template<class t_return_type, class... t_arg_types>
void function<t_return_type(t_arg_types...)>::swap(function &func) noexcept {
  m_f.swap(func.m_f);
}

template<class t_return_type, class... t_arg_types>
t_return_type function<t_return_type(t_arg_types...)>::operator()(t_arg_types... args) const {
  return m_f(::portable_stl::forward<t_arg_types>(args)...);
}

// template<class t_return_type, class... t_arg_types>
// std::type_info const &function<t_return_type(t_arg_types...)>::target_type() const noexcept {
// return m_f.target_type();
// }

template<class t_return_type, class... t_arg_types>
template<typename t_type>
t_type *function<t_return_type(t_arg_types...)>::target() noexcept {
  return (t_type *)(m_f.template target<t_type>());
}

template<class t_return_type, class... t_arg_types>
template<typename t_type>
t_type const *function<t_return_type(t_arg_types...)>::target() const noexcept {
  return m_f.template target<t_type>();
}

template<class t_return_type, class... t_arg_types>
inline bool operator==(function<t_return_type(t_arg_types...)> const &func, ::portable_stl::nullptr_t) noexcept {
  return !func;
}

template<class t_return_type, class... t_arg_types>
inline void swap(function<t_return_type(t_arg_types...)> &lhv, function<t_return_type(t_arg_types...)> &rhv) noexcept {
  return lhv.swap(rhv);
}
} // namespace portable_stl

#endif // PSTL_FUNCTION_H
