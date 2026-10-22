/*
Part of the EDG Compiler Project, under the Apache License v2.0 with LLVM
Exceptions.
See https://edgcpp.org/LICENSE.txt for license information.
SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
*/

/*
cxxabi.h -- Include file for IA-64 ABI entry points.
*/

#ifndef __CXXABI_H
#define __CXXABI_H

#ifndef __STDDEF_H
#include <stddef.h>
#endif  /* ifndef __STDDEF_H */
#include <typeinfo>

#ifdef __EDG_RUNTIME_USES_NAMESPACES
namespace __cxxabiv1 {
  using namespace std;
#endif /* ifdef __EDG_RUNTIME_USES_NAMESPACES */

  /* type_info implementation classes */

#pragma define_type_info
  class __fundamental_type_info : public type_info {
  public:
    virtual ~__fundamental_type_info();
  };

#pragma define_type_info
  class __array_type_info : public type_info {
  public:
    virtual ~__array_type_info();
  };

#pragma define_type_info
  class __function_type_info : public type_info {
  public:
    virtual ~__function_type_info();
  };

#pragma define_type_info
  class __enum_type_info : public type_info {
  public:
    virtual ~__enum_type_info();
  };

#pragma define_type_info
  class __class_type_info : public type_info {
  public:
    virtual ~__class_type_info();
  };

#pragma define_type_info
  class __si_class_type_info : public __class_type_info {
  public:
    virtual ~__si_class_type_info();
    const __class_type_info *__base_type;
  };

  struct __base_class_type_info {
    const __class_type_info *__base_type;
    long __offset_flags;

    enum __offset_flags_masks {
      __virtual_mask = 0x1,
      __public_mask = 0x2,
      __offset_shift = 8
    };
  };

#pragma define_type_info
  class __vmi_class_type_info : public __class_type_info {
  public:
    virtual ~__vmi_class_type_info();
    unsigned int __flags;
    unsigned int __base_count;
    __base_class_type_info __base_info[1];

    enum __flags_masks {
      __non_diamond_repeat_mask = 0x1,
      __diamond_shaped_mask = 0x2
    };
  };

#pragma define_type_info
  class __pbase_type_info : public type_info {
  public:
    virtual ~__pbase_type_info();
    unsigned int __flags;
    const type_info *__pointee;
    
    enum __masks {
      __const_mask = 0x1,
      __volatile_mask = 0x2,
      __restrict_mask = 0x4,
      __incomplete_mask = 0x8,
      __incomplete_class_mask = 0x10
    };
  }; 

#pragma define_type_info
  class __pointer_type_info : public __pbase_type_info {
    virtual ~__pointer_type_info();
  };

#pragma define_type_info
  class __pointer_to_member_type_info : public __pbase_type_info {
    virtual ~__pointer_to_member_type_info();
    const __class_type_info *__context;
  };

  extern "C" {
    /* Pure virtual function calls. */
    void __cxa_pure_virtual();

    /* Deleted virtual function calls. */
    void __cxa_deleted_virtual();

    /* Constructors return void in the IA-64 ABI.  But in the ARM EABI
       variant, they return void*. */
#ifdef __EDG_IA64_ABI_VARIANT_CTORS_AND_DTORS_RETURN_THIS
    typedef void* __ctor_dtor_return_type;
#else /* ifndef __EDG_IA64_ABI_VARIANT_CTORS_AND_DTORS_RETURN_THIS */
    typedef void __ctor_dtor_return_type;
#endif /* ifdef __EDG_IA64_ABI_VARIANT_CTORS_AND_DTORS_RETURN_THIS */

    /* Guard variables are 64 bits in the IA-64 ABI but only 32 bits in
       the ARM EABI. */
#ifdef __EDG_IA64_ABI_USE_INT_STATIC_INIT_GUARD
    typedef int __guard_variable_type;
#else /* ifndef __EDG_IA64_ABI_USE_INT_STATIC_INIT_GUARD */
    typedef unsigned long long __guard_variable_type;
#endif /* ifdef __EDG_IA64_ABI_USE_INT_STATIC_INIT_GUARD */
  
    /* Guard variables for the initialization of variables with static storage
       duration. */
    int __cxa_guard_acquire(__guard_variable_type *);
    void __cxa_guard_release(__guard_variable_type *);
    void __cxa_guard_abort(__guard_variable_type *);

    /* Construction and destruction of arrays. */
    void *__cxa_vec_new(size_t, size_t, size_t,
                        __ctor_dtor_return_type (*)(void *),
                        __ctor_dtor_return_type (*)(void *));
    void *__cxa_vec_new2(size_t, size_t, size_t,
                         __ctor_dtor_return_type (*)(void *),
                         __ctor_dtor_return_type (*)(void *),
                         void *(*)(size_t),
                         void (*)(void *));
    void *__cxa_vec_new3(size_t, size_t, size_t,
                         __ctor_dtor_return_type (*)(void *),
                         __ctor_dtor_return_type (*)(void *),
                         void *(*)(size_t),
                         void (*)(void *, size_t));
    void __cxa_vec_ctor(void *, size_t, size_t,
                        __ctor_dtor_return_type (*)(void *),
                        __ctor_dtor_return_type (*)(void *));
    void __cxa_vec_dtor(void *, size_t, size_t,
                        __ctor_dtor_return_type (*)(void *));
    void __cxa_vec_cleanup(void *, size_t, size_t,
                           __ctor_dtor_return_type (*)(void *));
    void __cxa_vec_delete(void *, size_t, size_t,
                          __ctor_dtor_return_type (*)(void *));
    void __cxa_vec_delete2(void *, size_t, size_t,
                           __ctor_dtor_return_type (*)(void *),
                           void (*)(void *));
    void __cxa_vec_delete3(void *, size_t, size_t,
                           __ctor_dtor_return_type (*)(void *),
                           void (*)(void *, size_t));
    void __cxa_vec_cctor(void *, void *, size_t, size_t, 
                         __ctor_dtor_return_type (*)(void *, void *),
                         __ctor_dtor_return_type (*)(void *));
#if ABI_COMPATIBILITY_VERSION >= 406
    void __cxa_throw_bad_array_new_length(void);
#endif /* ABI_COMPATIBILITY_VERSION >= 406 */

    /* Finalization. */
    int __cxa_atexit(void (*)(void *), void *, void *);
    int __cxa_thread_atexit(void (*)(void *), void *, void *);
    void __cxa_finalize(void *);

    /* Exception-handling support. */
    void __cxa_bad_cast();
    void __cxa_bad_typeid();

    /* Demangling interface. */
    char *__cxa_demangle(const char* __mangled_name,
                         char        *__buf,
                         size_t      *__n,
                         int         *__status);

  }  /* extern "C" */
#ifdef __EDG_RUNTIME_USES_NAMESPACES
}  /* namespace __cxxabiv1 */

/* Create the "abi" namespace alias. */
namespace abi = __cxxabiv1;
#endif /* ifdef __EDG_RUNTIME_USES_NAMESPACES */

#endif /* ifndef __CXXABI_H */

