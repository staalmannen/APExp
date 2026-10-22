// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="memory_pointer_traits.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/memory/pointer_traits.h"
#include "test_debug_helper.h"

TEST(memory_pointer_traits, pointer_to) {
  // from clang\test\std\utilities\memory\pointer.traits\ptr.pointer_to.pass.cpp
  static_cast<void>(test_info_);

  // pointer_traits<T*>
  {
    std::int32_t int_val{0};
    EXPECT_TRUE(
      (std::is_same<decltype(::portable_stl::pointer_traits<std::int32_t *>::pointer_to(int_val)), std::int32_t *>{}));
    EXPECT_TRUE(noexcept(::portable_stl::pointer_traits<std::int32_t *>::pointer_to(int_val)));
    EXPECT_EQ(&int_val, ::portable_stl::pointer_traits<std::int32_t *>::pointer_to(int_val));
  }

  // pointer_traits<const T*>
  {
    constexpr std::int32_t const int_val{0};
    EXPECT_TRUE((std::is_same<decltype(::portable_stl::pointer_traits<std::int32_t const *>::pointer_to(int_val)),
                              std::int32_t const *>{}));
    EXPECT_TRUE(noexcept(::portable_stl::pointer_traits<std::int32_t const *>::pointer_to(int_val)));
    EXPECT_EQ(&int_val, ::portable_stl::pointer_traits<std::int32_t const *>::pointer_to(int_val));
  }

  // pointer_traits<const T*> with a non-const argument
  {
    std::int32_t int_val{0};
    EXPECT_TRUE((std::is_same<decltype(::portable_stl::pointer_traits<std::int32_t const *>::pointer_to(int_val)),
                              std::int32_t const *>{}));
    EXPECT_TRUE(noexcept(::portable_stl::pointer_traits<std::int32_t const *>::pointer_to(int_val)));
    EXPECT_EQ(&int_val, ::portable_stl::pointer_traits<std::int32_t const *>::pointer_to(int_val));
  }
}

TEST(memory_pointer_traits, void_type) {
  // from clang\test\std\utilities\memory\pointer.traits\ptr.pointer_to.pass.cpp
  static_cast<void>(test_info_);

  // Check that pointer_traits<void*> is still well-formed, even though it has no pointer_to.
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<void *>::element_type, void>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<void const *>::element_type, void const>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<void volatile *>::element_type, void volatile>{}));
}

TEST(memory_pointer_traits, types) {
  // from clang\test\std\utilities\memory\pointer.traits\ptr.types.compile.pass.cpp
  static_cast<void>(test_info_);

  {
    /**
     * @brief Test ptr type.
     */
    using t_ptr = std::int32_t *;

    EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<t_ptr>::element_type, std::int32_t>{}));
    EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<t_ptr>::pointer, t_ptr>{}));
    EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<t_ptr>::difference_type, ::portable_stl::ptrdiff_t>{}));
    EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<t_ptr>::rebind<std::int64_t>, std::int64_t *>{}));
  }

  {
    /**
     * @brief Test ptr type.
     */
    using t_ptr = std::int32_t const *;

    EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<t_ptr>::element_type, std::int32_t const>{}));
    EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<t_ptr>::pointer, t_ptr>{}));
    EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<t_ptr>::difference_type, ::portable_stl::ptrdiff_t>{}));
    EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<t_ptr>::rebind<std::int64_t>, std::int64_t *>{}));
  }
}

namespace memory_tests_helper {

/**
 * @brief fancy pointer type.
 * @tparam t_type base type.
 */
template<class t_type> class fancy_pointer final {
  /**
   * @brief Empty type for void case.
   */
  struct nat {};

public:
  /**
   * @brief Element type.
   */
  using element_type = t_type;
  /**
   * @brief Internal pointer (data).
   */
  element_type *m_value;
  /**
   * @brief Ctor
   * @param value Pointer value.
   */
  fancy_pointer(element_type *value) : m_value{value} {
  }
  /**
   * @brief pointer_to implementation.
   * @param et
   * @return
   */
  static fancy_pointer pointer_to(
    typename std::conditional<std::is_void<element_type>::value, nat, element_type>::type &et) {
    return fancy_pointer(&et);
  }
};
} // namespace memory_tests_helper

TEST(memory_pointer_traits, aaa) {
  // from C:\dev\stl\clang\test\std\utilities\memory\pointer.traits\pointer.traits.functions\pointer_to.pass.cpp
  static_cast<void>(test_info_);

  {
    /**
     * @brief Test pointer type.
     */
    using test_ptr = memory_tests_helper::fancy_pointer<std::int32_t>;
    test_ptr::element_type obj;
    EXPECT_TRUE((std::is_same<test_ptr, decltype(::portable_stl::pointer_traits<test_ptr>::pointer_to(obj))>{}));

    test_ptr ptr{::portable_stl::pointer_traits<test_ptr>::pointer_to(obj)};
    EXPECT_EQ(&obj, ptr.m_value);
  }

  {
    /**
     * @brief Test pointer type.
     */
    using test_ptr = memory_tests_helper::fancy_pointer<std::int64_t>;
    test_ptr::element_type obj;
    EXPECT_TRUE((std::is_same<test_ptr, decltype(::portable_stl::pointer_traits<test_ptr>::pointer_to(obj))>{}));

    test_ptr ptr{::portable_stl::pointer_traits<test_ptr>::pointer_to(obj)};
    EXPECT_EQ(&obj, ptr.m_value);
  }
}

namespace memory_tests_helper {
/**
 * @brief Class with element_type typename.
 */
class has_element_type final {
public:
  /**
   * @brief Element type.
   */
  using element_type = std::int16_t;
};

/**
 * @brief Simple test class.
 * @tparam t_type Given type.
 */
template<class t_type> class has_element_type_tmp final {
public:
  /**
   * @brief Element type.
   */
  using element_type = std::int16_t;
};

/**
 * @brief Simple empty test class template.
 * @tparam t_type
 */
template<class t_type> class has_no_type_tmp final {};

/**
 * @brief Simple empty test class template.
 * @tparam t_type1
 * @tparam t_type2
 */
template<class t_type1, class t_type2> class has_no_type_tmp2 final {};

/**
 * @brief Simple test class.
 * @tparam t_type1
 * @tparam t_type2
 */
template<class t_type1, class t_type2> class has_element_tmp2 final {
public:
  /**
   * @brief Static member.
   */
  static std::int32_t element_type;
};

/**
 * @brief Simple test class template with private element_type.
 * @tparam t_type
 */
template<class t_type> class has_private_element_type_tmp final {
  /**
   * @brief Element type.
   */
  using element_type = std::int32_t;
};
} // namespace memory_tests_helper

TEST(memory_pointer_traits, pointer) {
  // from C:\dev\stl\clang\test\std\utilities\memory\pointer.traits\pointer.traits.types
  static_cast<void>(test_info_);

  EXPECT_TRUE((std::is_same<memory_tests_helper::has_element_type,
                            ::portable_stl::pointer_traits<memory_tests_helper::has_element_type>::pointer>{}));
}

TEST(memory_pointer_traits, element_type) {
  // from C:\dev\stl\clang\test\std\utilities\memory\pointer.traits\pointer.traits.types\element_type.compile.pass.cpp
  static_cast<void>(test_info_);

  // clang-format off
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::has_element_type>::element_type,                                std::int16_t>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::has_element_type_tmp<std::int32_t>>::element_type,              std::int16_t>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::has_no_type_tmp<std::int32_t>>::element_type,                   std::int32_t>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::has_no_type_tmp2<double, std::int32_t>>::element_type,          double>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::has_element_tmp2<double, std::int32_t>>::element_type,          double>{}));
  
  // // error in msvc 
  //EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::has_private_element_type_tmp<double>>::element_type,            double>{}));

  // clang-format on
}

namespace memory_tests_helper {
/**
 * @brief Class with element_type and difference_type typename.
 */
class has_both_type final {
public:
  /**
   * @brief Element type.
   */
  using element_type    = std::int16_t;
  /**
   * @brief Difference type.
   */
  using difference_type = std::int8_t;
};

/**
 * @brief Simple test class template difference_type.
 * @tparam t_type Given type.
 */
template<class t_type> class has_difference_type_tmp final {
public:
  /**
   * @brief Difference type.
   */
  using difference_type = std::int8_t;
};

/**
 * @brief Simple test class template static member.
 * @tparam t_type Given type.
 */
template<class t_type> class has_difference_member_tmp final {
public:
  /**
   * @brief Static member.
   */
  static std::int32_t difference_type;
};

/**
 * @brief Simple test class template with private difference_type.
 * @tparam t_type Given type.
 */
template<class t_type> class has_private_difference_type_tmp final {
  /**
   * @brief Difference type.
   */
  using difference_type = std::int32_t;
};
} // namespace memory_tests_helper

TEST(memory_pointer_traits, difference_type) {
  // from C:\dev\stl\clang\test\std\utilities\memory\pointer.traits\pointer.traits.types\element_type.compile.pass.cpp
  static_cast<void>(test_info_);

  // clang-format off
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::has_both_type>::difference_type,                                    std::int8_t>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::has_element_type>::difference_type,                                 ::portable_stl::ptrdiff_t>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::has_no_type_tmp<double>>::difference_type,                          ::portable_stl::ptrdiff_t>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::has_difference_type_tmp<std::int32_t>>::difference_type,            std::int8_t>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::has_difference_member_tmp<std::int32_t>>::difference_type,          ::portable_stl::ptrdiff_t>{}));
  
  // error in msvc 
  //EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::has_private_difference_type_tmp<std::int32_t>>::difference_type,    ::portable_stl::ptrdiff_t>{}));

  // clang-format on
}

namespace memory_tests_helper {
/**
 * @brief Simple class to test pointer_traits<>::rebind.
 * @tparam t_type Given type.
 */
template<class t_type> class no_rebind1 final {};

/**
 * @brief Simple class to test pointer_traits<>::rebind.
 * @tparam t_type Given type.
 */
template<class t_type> class no_rebind2 final {};

/**
 * @brief Simple class to test pointer_traits<>::rebind.
 * @tparam t_type1 Given type.
 */
template<class t_type1> class has_rebind_tmp final {
public:
  /**
   * @brief alias.
   * @tparam t_type2 Given type.
   */
  template<class t_type2> using rebind = no_rebind2<t_type2>;
};

/**
 * @brief Simple class to test pointer_traits<>::rebind.
 * @tparam t_type1 Given type.
 * @tparam t_type2 Given type.
 */
template<class t_type1, class t_type2> class no_rebind_tmp2 final {};

/**
 * @brief Simple class to test pointer_traits<>::rebind.
 * @tparam t_type1 Given type.
 * @tparam t_type2 Given type.
 */
template<class t_type1, class t_type2> class no_rebind2_tmp2 final {};

/**
 * @brief Simple class to test pointer_traits<>::rebind.
 * @tparam t_type1 Given type.
 * @tparam t_type2 Given type.
 */
template<class t_type1, class t_type2> class has_rebind_tmp2 final {
public:
  /**
   * @brief alias.
   * @tparam t_type3 Given type.
   */
  template<class t_type3> using rebind = no_rebind2_tmp2<t_type3, t_type2>;
};

/**
 * @brief Simple class to test pointer_traits<>::rebind.
 * @tparam t_type1 Given type.
 * @tparam t_type2 Given type.
 */
template<class t_type1, class t_type2> class has_member_fn_rebind final {
public:
  /**
   * @brief fn.
   */
  template<class> void rebind();
};

/**
 * @brief Simple class to test pointer_traits<>::rebind.
 * @tparam t_type1 Given type.
 * @tparam t_type2 Given type.
 */
template<class t_type1, class t_type2> class has_private_rebind_tmp final {
private:
  /**
   * @brief alias.
   */
  template<class> using rebind = void;
};

/**
 * @brief Simple class to test pointer_traits<>::rebind.
 * @tparam t_type1 Given type.
 * @tparam t_type2 Given type.
 */
template<class t_type1, class t_type2> class has_member_rebind final {
public:
  /**
   * @brief static member.
   */
  template<class> constexpr static std::int32_t rebind = 42;
};
} // namespace memory_tests_helper

TEST(memory_pointer_traits, rebind) {
  // from C:\dev\stl\clang\test\std\utilities\memory\pointer.traits\pointer.traits.types\element_type.compile.pass.cpp
  static_cast<void>(test_info_);

  // clang-format off
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::no_rebind1<std::int32_t *>>::rebind<double *>,
                                                           memory_tests_helper::no_rebind1<double *>>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::has_rebind_tmp<std::int32_t>>::rebind<double>,
                                                           memory_tests_helper::no_rebind2<double>>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::no_rebind_tmp2<std::uint8_t, std::int32_t>>::rebind<double>,
                                                           memory_tests_helper::no_rebind_tmp2<double, std::int32_t>>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::has_rebind_tmp2<std::uint8_t, std::int32_t>>::rebind<double>,
                                                           memory_tests_helper::no_rebind2_tmp2<double, std::int32_t>>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::has_member_fn_rebind<std::uint8_t, std::int32_t>>::rebind<double>,
                                                           memory_tests_helper::has_member_fn_rebind<double, std::int32_t>>{}));
  // todo(plotitsyn): error in msvc (but with std::pointer_traits - ok)
  // EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::has_private_rebind_tmp<std::uint8_t, std::int32_t>>::rebind<double>,
  //                                               memory_tests_helper::has_private_rebind_tmp<double, std::int32_t>>{}));

  print_type_info<std::pointer_traits<memory_tests_helper::has_private_rebind_tmp<std::uint8_t, std::int32_t>>::rebind<double>>();

  EXPECT_TRUE((std::is_same<::portable_stl::pointer_traits<memory_tests_helper::has_member_rebind<std::uint8_t, std::int32_t>>::rebind<double>,
                                                           memory_tests_helper::has_member_rebind<double, std::int32_t>>{}));
  // clang-format on
}
