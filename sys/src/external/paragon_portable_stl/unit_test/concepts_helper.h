// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="concepts_helper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CONCEPTS_HELPER_H
#define PSTL_CONCEPTS_HELPER_H

namespace test_concepts_helpers {
/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class postfix_increment_returns_void final {
public:
  /**
   * @brief Diff type.
   */
  using difference_type = std::int32_t;
  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  postfix_increment_returns_void &operator++();
  /**
   * @brief Post-inc op.
   */
  void                            operator++(std::int32_t);
};

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class postfix_increment_returns_copy final {
public:
  /**
   * @brief Diff type.
   */
  using difference_type = std::int32_t;
  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  postfix_increment_returns_copy &operator++();
  /**
   * @brief Post-inc op.
   * @return postfix_increment_returns_copy.
   */
  postfix_increment_returns_copy  operator++(std::int32_t);
};

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class has_integral_minus final {
public:
  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  has_integral_minus &operator++();
  /**
   * @brief Post-inc op.
   * @return has_integral_minus.
   */
  has_integral_minus  operator++(int);
  /**
   * @brief Minus op.
   * @return std::int64_t .
   */
  inline std::int64_t operator-(has_integral_minus) const;
};

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class has_distinct_difference_type_and_minus final {
public:
  /**
   * @brief Diff type.
   */
  using difference_type = std::int16_t;
  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  has_distinct_difference_type_and_minus &operator++();
  /**
   * @brief Post-inc op.
   * @return has_distinct_difference_type_and_minus.
   */
  has_distinct_difference_type_and_minus  operator++(int);
  /**
   * @brief Minus op.
   * @return std::int64_t .
   */
  inline std::int64_t                     operator-(has_distinct_difference_type_and_minus) const;
};

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class missing_difference_type final {
public:
  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  missing_difference_type &operator++();
  /**
   * @brief Post-inc op.
   */
  void                     operator++(std::int32_t);
};

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class floating_difference_type final {
public:
  /**
   * @brief Diff type.
   */
  using difference_type = float;
  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  floating_difference_type &operator++();
  /**
   * @brief Post-inc op.
   */
  void                      operator++(std::int32_t);
};

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class non_const_minus final {
public:
  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  non_const_minus    &operator++();
  /**
   * @brief Post-inc op.
   * @return non_const_minus.
   */
  non_const_minus     operator++(std::int32_t);
  /**
   * @brief Mon const minus op.
   * @return std::int64_t .
   */
  inline std::int64_t operator-(non_const_minus);
};

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class non_integral_minus final {
public:
  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  non_integral_minus &operator++();
  /**
   * @brief Post-inc op.
   * @return non_integral_minus.
   */
  non_integral_minus  operator++(std::int32_t);
  /**
   * @brief Minus op.
   */
  void                operator-(non_integral_minus);
};

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class bad_difference_type_good_minus final {
public:
  /**
   * @brief Diff type.
   */
  using difference_type = float;
  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  bad_difference_type_good_minus &operator++();
  /**
   * @brief Post-inc op.
   */
  void                            operator++(std::int32_t);
  /**
   * @brief Minus op.
   * @return int.
   */
  std::int32_t                    operator-(bad_difference_type_good_minus) const;
};

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class not_default_initializable final {
public:
  /**
   * @brief Diff type.
   */
  using difference_type       = std::int32_t;
  /**
   * @brief Construct a new not default initializable object.
   */
  not_default_initializable() = delete;
  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  not_default_initializable &operator++();
  /**
   * @brief Post-inc op.
   */
  void                       operator++(std::int32_t);
};

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class not_movable final {
public:
  /**
   * @brief Diff type.
   */
  using difference_type                         = std::int32_t;
  /**
   * @brief Construct a new not movable object.
   */
  not_movable()                                 = default;
  /**
   * @brief dtor.
   */
  ~not_movable()                                = default;
  /**
   * @brief Construct a new not movable object
   */
  not_movable(not_movable const &)              = default;
  /**
   * @brief Construct a new not movable object.
   */
  not_movable(not_movable &&)                   = delete;
  /**
   * @brief assignment
   */
  not_movable &operator=(not_movable const &) & = delete;
  /**
   * @brief assignment
   */
  not_movable &operator=(not_movable &&)      & = delete;

  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  not_movable &operator++();
  /**
   * @brief Post-inc op.
   */
  void         operator++(std::int32_t);
};

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class preinc_not_declared final {
public:
  /**
   * @brief Diff type.
   */
  using difference_type = std::int32_t;
  /**
   * @brief Post-inc op.
   */
  void operator++(std::int32_t);
};

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class postinc_not_declared final {
public:
  /**
   * @brief Diff type.
   */
  using difference_type = std::int32_t;
  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  postinc_not_declared &operator++();
};

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class incrementable_with_difference_type final {
public:
  /**
   * @brief Diff type.
   */
  using difference_type = std::int32_t;
  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  incrementable_with_difference_type &operator++();
  /**
   * @brief Post-inc op.
   * @return incrementable_with_difference_type
   */
  incrementable_with_difference_type  operator++(std::int32_t);
};

/**
 * @brief Comp op.
 * @return Result of op.
 */
bool operator==(incrementable_with_difference_type const &, incrementable_with_difference_type const &) noexcept;

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class incrementable_without_difference_type final {
public:
  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  incrementable_without_difference_type &operator++();
  /**
   * @brief Post-inc op.
   * @return incrementable_without_difference_type.
   */
  incrementable_without_difference_type  operator++(std::int32_t);
  /**
   * @brief Minus op.
   * @return std::int32_t.
   */
  std::int32_t                           operator-(incrementable_without_difference_type) const;
};
/**
 * @brief Comp op.
 * @return Result of op.
 */
bool operator==(incrementable_without_difference_type const &, incrementable_without_difference_type const &) noexcept;

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class difference_type_and_void_minus final {
public:
  /**
   * @brief Diff type.
   */
  using difference_type = std::int32_t;
  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  difference_type_and_void_minus &operator++();
  /**
   * @brief Post-inc op.
   * @return difference_type_and_void_minus.
   */
  difference_type_and_void_minus  operator++(std::int32_t);
  /**
   * @brief Minus op.
   */
  void                            operator-(difference_type_and_void_minus) const;
};
/**
 * @brief Comp op.
 * @return Result of op.
 */
bool operator==(difference_type_and_void_minus const &, difference_type_and_void_minus const &) noexcept;

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class noncopyable_with_difference_type final {
public:
  /**
   * @brief Diff type.
   */
  using difference_type                                                                 = std::int32_t;
  /**
   * @brief Construct a new noncopyable with difference type object.
   */
  noncopyable_with_difference_type()                                                    = default;
  /**
   * @brief Construct a new noncopyable with difference type object.
   */
  noncopyable_with_difference_type(noncopyable_with_difference_type &&)                 = default;
  /**
   * @brief Construct a new noncopyable with difference type object.
   */
  noncopyable_with_difference_type(noncopyable_with_difference_type const &)            = delete;
  /**
   * @brief Copy assignment operator.
   * @return noncopyable_with_difference_type&.
   */
  noncopyable_with_difference_type &operator=(noncopyable_with_difference_type &&)    & = default;
  /**
   * @brief Dtor.
   */
  ~noncopyable_with_difference_type()                                                   = default;
  /**
   * @brief Move assignment operator.
   * @return noncopyable_with_difference_type&.
   */
  noncopyable_with_difference_type &operator=(noncopyable_with_difference_type const &) = delete;
  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  noncopyable_with_difference_type &operator++();
  /**
   * @brief Post-inc op.
   * @return noncopyable_with_difference_type.
   */
  noncopyable_with_difference_type  operator++(std::int32_t);
};
/**
 * @brief Comp op.
 * @return Result of op.
 */
bool operator==(noncopyable_with_difference_type const &, noncopyable_with_difference_type const &) noexcept;

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class noncopyable_without_difference_type final {
public:
  /**
   * @brief Ctor.
   */
  noncopyable_without_difference_type()                                                       = default;
  /**
   * @brief Construct a new noncopyable without difference type object.
   */
  noncopyable_without_difference_type(noncopyable_without_difference_type &&)                 = default;
  /**
   * @brief Construct a new noncopyable without difference type object.
   */
  noncopyable_without_difference_type(noncopyable_without_difference_type const &)            = delete;
  /**
   * @brief Copy assignment operator.
   * @return noncopyable_without_difference_type&.
   */
  noncopyable_without_difference_type &operator=(noncopyable_without_difference_type &&)    & = default;
  /**
   * @brief Move assignment operator.
   * @return
   */
  noncopyable_without_difference_type &operator=(noncopyable_without_difference_type const &) = delete;
  /**
   * @brief Dtor.
   */
  ~noncopyable_without_difference_type()                                                      = default;
  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  noncopyable_without_difference_type &operator++();
  /**
   * @brief Post-inc op.
   * @return noncopyable_without_difference_type.
   */
  noncopyable_without_difference_type  operator++(std::int32_t);
  /**
   * @brief Minus op.
   * @return std::int32_t.
   */
  std::int32_t                         operator-(noncopyable_without_difference_type const &) const;
};
/**
 * @brief Comp op.
 * @return Result of op.
 */
bool operator==(noncopyable_without_difference_type const &, noncopyable_without_difference_type const &) noexcept;

/**
 * @brief Class to check weakly_incrementable 'concepts'.
 */
class noncopyable_with_difference_type_and_minus final {
public:
  /**
   * @brief Diff type.
   */
  using difference_type                                                                                  = std::int32_t;
  /**
   * @brief Construct a new noncopyable with difference type and minus object.
   */
  noncopyable_with_difference_type_and_minus()                                                           = default;
  /**
   * @brief Construct a new noncopyable with difference type and minus object.
   */
  noncopyable_with_difference_type_and_minus(noncopyable_with_difference_type_and_minus &&)              = default;
  /**
   * @brief Construct a new noncopyable with difference type and minus object.
   */
  noncopyable_with_difference_type_and_minus(noncopyable_with_difference_type_and_minus const &)         = delete;
  /**
   * @brief Move assignment operator.
   * @return noncopyable_with_difference_type_and_minus&.
   */
  noncopyable_with_difference_type_and_minus &operator=(noncopyable_with_difference_type_and_minus &&) & = default;
  /**
   * @brief Copy assignment op.
   * @return
   */
  noncopyable_with_difference_type_and_minus &operator=(noncopyable_with_difference_type_and_minus const &) = delete;
  /**
   * @brief Dtor.
   */
  ~noncopyable_with_difference_type_and_minus()                                                             = default;
  /**
   * @brief Pre-inc op.
   * @return ref type.
   */
  noncopyable_with_difference_type_and_minus &operator++();
  /**
   * @brief Post-inc op.
   * @return noncopyable_with_difference_type_and_minus.
   */
  noncopyable_with_difference_type_and_minus  operator++(std::int32_t);
  /**
   * @brief Minus op.
   * @return std::int32_t.
   */
  std::int32_t                                operator-(noncopyable_with_difference_type_and_minus const &) const;
};
/**
 * @brief Comp op.
 * @return Result of op.
 */
bool operator==(noncopyable_with_difference_type_and_minus const &,
                noncopyable_with_difference_type_and_minus const &) noexcept;

/**
 * @brief Special assignable class.
 */
class special_assignable final {
public:
  /**
   * @brief Ctor from std::int32_t
   */
  special_assignable(std::int32_t) noexcept {
  }
  /**
   * @brief Ctor.
   */
  special_assignable(special_assignable const &) = default;
  /**
   * @brief Ctor.
   */
  special_assignable(special_assignable &&)      = default;
  /**
   * @brief Dtor.
   */
  ~special_assignable()                          = default;
  /**
   * @brief Assignable operator (regular semantic).
   * @return
   */
  special_assignable &operator=(special_assignable const &) & noexcept {
    return *this;
  }
  /**
   * @brief Move assignment.
   */
  special_assignable &operator=(special_assignable &&) & noexcept = default;
  /**
   * @brief Assignable operator from std::int32_t.
   * @return
   */
  special_assignable &operator=(std::int32_t) & noexcept {
    return *this;
  }
  /**
   * @brief Assignable operator from void*.
   */
  void operator=(void *) & noexcept;
};

/**
 * @brief Union for checking.
 */
union EmptyUnion {};

/**
 * @brief Helper unscopped enum.
 *
 */
enum UnscoppedEnum : std::int32_t {
};

/**
 * @brief Helper scopped enum.
 */
enum class ScoppedEnum : std::int32_t {
};

/**
 * @brief Class to check regular 'concept'.
 */
class volatile_copy_assignment final {
public:
  /**
   * @brief Ctor.
   */
  volatile_copy_assignment() = default;

  /**
   * @brief Ctor copy.
   */
  volatile_copy_assignment(volatile_copy_assignment volatile &);
  /**
   * @brief Ctor move.
   */
  volatile_copy_assignment(volatile_copy_assignment volatile &&) noexcept;

  /**
   * @brief Assignment copy.
   * @return volatile_copy_assignment volatile &
   */
  volatile_copy_assignment volatile &operator=(volatile_copy_assignment const &) volatile;
  /**
   * @brief Assignment move.
   * @return volatile_copy_assignment&
   */
  volatile_copy_assignment          &operator=(volatile_copy_assignment &&) noexcept;
};

/**
 * @brief Class to check regular 'concept'.
 */
class no_copy_constructor final {
public:
  /**
   * @brief Ctor.
   */
  no_copy_constructor() = default;

  /**
   * @brief Ctor copy deleted.
   */
  no_copy_constructor(no_copy_constructor const &) = delete;
  /**
   * @brief Ctor move.
   */
  no_copy_constructor(no_copy_constructor &&)      = default;
};

/**
 * @brief Class to check regular 'concept'.
 */
class no_copy_assignment final {
public:
  /**
   * @brief Ctor.
   */
  no_copy_assignment()                           = default;
  /**
   * @brief Dtor.
   */
  ~no_copy_assignment()                          = default;
  /**
   * @brief Ctor copy.
   */
  no_copy_assignment(no_copy_assignment const &) = default;
  /**
   * @brief Ctor move.
   */
  no_copy_assignment(no_copy_assignment &&)      = default;

  /**
   * @brief Assignment copy deleted.
   * @return no_copy_assignment&
   */
  no_copy_assignment &operator=(no_copy_assignment const &) = delete;
  /**
   * @brief Assignment move.
   * @return no_copy_assignment&
   */
  no_copy_assignment &operator=(no_copy_assignment &&)      = default;
};

/**
 * @brief Class to check regular 'concept'.
 */
class derived_from_noncopyable final : public std::unique_ptr<std::int32_t> {};

/**
 * @brief Class to check regular 'concept'.
 */
class has_noncopyable final {
  /**
   * @brief Data.
   */
  std::unique_ptr<std::int32_t> x;
};

/**
 * @brief Function for has_function_ref_member
 * @return std::int32_t
 */
inline static std::int32_t free_function() noexcept {
  return 1;
}

/**
 * @brief Class to check regular 'concept'.
 */
class deleted_assignment_from_const_rvalue final {
public:
  /**
   * @brief Dtor.
   */
  ~deleted_assignment_from_const_rvalue() = default;
  /**
   * @brief Construct a new deleted assignment from const rvalue object
   */
  deleted_assignment_from_const_rvalue(deleted_assignment_from_const_rvalue const &);
  /**
   * @brief Construct a new deleted assignment from const rvalue object
   */
  deleted_assignment_from_const_rvalue(deleted_assignment_from_const_rvalue &&) noexcept;

  /**
   * @brief
   * @return deleted_assignment_from_const_rvalue&
   */
  deleted_assignment_from_const_rvalue &operator=(deleted_assignment_from_const_rvalue const &);
  /**
   * @brief
   * @return deleted_assignment_from_const_rvalue&
   */
  deleted_assignment_from_const_rvalue &operator=(deleted_assignment_from_const_rvalue &&) noexcept;
  /**
   * @brief
   * @return deleted_assignment_from_const_rvalue&
   */
  deleted_assignment_from_const_rvalue &operator=(deleted_assignment_from_const_rvalue const &&) = delete;
};

/**
 * @brief  Class to check default_initializable 'concept'.
 */
class no_default_ctor {
public:
  /**
   * @brief Construct a new no default ctor object
   */
  no_default_ctor(std::int32_t);
};

/**
 * @brief Class to check regular 'concept'.
 */
class derived_from_non_default_initializable final : public no_default_ctor {};

/**
 * @brief Class to check regular 'concept'.
 */
class has_non_default_initializable final {
  /**
   * @brief Data.
   */
  no_default_ctor m_value;
};

// /**
//  * @brief Class to check ???
//  */
// class deleted_default_ctor {
// public:
//   /**
//    * @brief Ctor deleted.
//    */
//   deleted_default_ctor() = delete;
// };

// /**
//  * @brief Class to check ???
//  */
// class derived_from_deleted_default_ctor final : public deleted_default_ctor {};

// /**
//  * @brief Class to check ???
//  */
// class has_deleted_default_ctor final {
//   /**
//    * @brief Data.
//    */
//   deleted_default_ctor m_value;
// };

/**
 * @brief Class to check regular 'concept'.
 */
class const_copy_assignment final {
public:
  /**
   * @brief Ctor.
   */
  const_copy_assignment()  = default;
  /**
   * @brief Dtor.
   */
  ~const_copy_assignment() = default;

  /**
   * @brief Ctor copy.
   */
  const_copy_assignment(const_copy_assignment const &);
  /**
   * @brief Ctor move.
   */
  const_copy_assignment(const_copy_assignment &&) noexcept;

  /**
   * @brief Assignment copy.
   * @return const_copy_assignment const&
   */
  const_copy_assignment const &operator=(const_copy_assignment const &) const noexcept;
  /**
   * @brief Assignment move.
   * @return const_copy_assignment&
   */
  const_copy_assignment       &operator=(const_copy_assignment &&) noexcept;
};

/**
 * @brief Class to check regular 'concept'.
 */
class cv_copy_assignment final {
public:
  /**
   * @brief Ctor.
   */
  cv_copy_assignment()  = default;
  /**
   * @brief Dtor.
   */
  ~cv_copy_assignment() = default;
  /**
   * @brief Ctor copy.
   */
  cv_copy_assignment(cv_copy_assignment const volatile &);
  /**
   * @brief Ctor move.
   */
  cv_copy_assignment(cv_copy_assignment const volatile &&) noexcept;

  /**
   * @brief Assignment copy.
   * @return cv_copy_assignment const volatile&
   */
  cv_copy_assignment const volatile &operator=(cv_copy_assignment const volatile &) const volatile;
  /**
   * @brief Assignment move.
   * @return cv_copy_assignment const volatile&
   */
  cv_copy_assignment const volatile &operator=(cv_copy_assignment const volatile &&) const volatile noexcept;
};

/**
 * @brief Class to test equality_comparable.
 */
class no_eq final {};
/**
 * @brief Comparison operator explicitly deleted.
 * @return result of comparison.
 */
bool        operator==(no_eq, no_eq) = delete;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator!=(no_eq, no_eq) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator<(no_eq, no_eq) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator>(no_eq, no_eq) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator>=(no_eq, no_eq) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator<=(no_eq, no_eq) noexcept;

/**
 * @brief Class to test equality_comparable.
 */
class no_neq final {};
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool         operator==(no_neq, no_neq) noexcept;
/**
 * @brief Comparison operator explicitly deleted.
 * @return result of comparison.
 */
bool         operator!=(no_neq, no_neq) = delete;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool         operator<(no_neq, no_neq) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool         operator>(no_neq, no_neq) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool         operator>=(no_neq, no_neq) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool         operator<=(no_neq, no_neq) noexcept;
/**
 * @brief Class to test equality_comparable.
 */
class no_lt  final {};
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool         operator==(no_lt, no_lt) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool         operator!=(no_lt, no_lt) noexcept;
/**
 * @brief Comparison operator explicitly deleted.
 * @return result of comparison.
 */
bool         operator<(no_lt, no_lt) = delete;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool         operator>(no_lt, no_lt) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool         operator>=(no_lt, no_lt) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool         operator<=(no_lt, no_lt) noexcept;

/**
 * @brief Class to test equality_comparable.
 */
class no_gt final {};
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator==(no_gt, no_gt) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator!=(no_gt, no_gt) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator<(no_gt, no_gt) noexcept;
/**
 * @brief Comparison operator explicitly deleted.
 * @return result of comparison.
 */
bool        operator>(no_gt, no_gt) = delete;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator>=(no_gt, no_gt) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator<=(no_gt, no_gt) noexcept;

/**
 * @brief Class to test equality_comparable.
 */
class no_le final {};
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator==(no_le, no_le) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator!=(no_le, no_le) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator<(no_le, no_le) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator>(no_le, no_le) noexcept;
/**
 * @brief Comparison operator explicitly deleted.
 * @return result of comparison.
 */
bool        operator>=(no_le, no_le) = delete;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator<=(no_le, no_le) noexcept;

/**
 * @brief Class to test equality_comparable.
 */
class no_ge final {};
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator==(no_ge, no_ge) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator!=(no_ge, no_ge) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator<(no_ge, no_ge) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator>(no_ge, no_ge) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool        operator>=(no_ge, no_ge) noexcept;
/**
 * @brief Comparison operator explicitly deleted.
 * @return result of comparison.
 */
bool        operator<=(no_ge, no_ge) = delete;

/**
 * @brief Class to test equality_comparable.
 */
class wrong_return_type_eq final {};
/**
 * @brief Comparison operator.
 */
void                       operator==(wrong_return_type_eq, wrong_return_type_eq) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator!=(wrong_return_type_eq, wrong_return_type_eq) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator<(wrong_return_type_eq, wrong_return_type_eq) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator>(wrong_return_type_eq, wrong_return_type_eq) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator>=(wrong_return_type_eq, wrong_return_type_eq) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator<=(wrong_return_type_eq, wrong_return_type_eq) noexcept;

/**
 * @brief Class to test equality_comparable.
 */
class wrong_return_type_ne final {};
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator==(wrong_return_type_ne, wrong_return_type_ne) noexcept;
/**
 * @brief Comparison operator.
 */
void                       operator!=(wrong_return_type_ne, wrong_return_type_ne) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator<(wrong_return_type_ne, wrong_return_type_ne) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator>(wrong_return_type_ne, wrong_return_type_ne) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator>=(wrong_return_type_ne, wrong_return_type_ne) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator<=(wrong_return_type_ne, wrong_return_type_ne) noexcept;

/**
 * @brief Class to test equality_comparable.
 */
class wrong_return_type_lt final {};
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator==(wrong_return_type_lt, wrong_return_type_lt) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator!=(wrong_return_type_lt, wrong_return_type_lt) noexcept;
/**
 * @brief Comparison operator.
 */
void                       operator<(wrong_return_type_lt, wrong_return_type_lt) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator>(wrong_return_type_lt, wrong_return_type_lt) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator>=(wrong_return_type_lt, wrong_return_type_lt) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator<=(wrong_return_type_lt, wrong_return_type_lt) noexcept;

/**
 * @brief Class to test equality_comparable.
 */
class wrong_return_type_gt final {};
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator==(wrong_return_type_gt, wrong_return_type_gt) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator!=(wrong_return_type_gt, wrong_return_type_gt) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator<(wrong_return_type_gt, wrong_return_type_gt) noexcept;
/**
 * @brief Comparison operator.
 */
void                       operator>(wrong_return_type_gt, wrong_return_type_gt) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator>=(wrong_return_type_gt, wrong_return_type_gt) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator<=(wrong_return_type_gt, wrong_return_type_gt) noexcept;

/**
 * @brief Class to test equality_comparable.
 */
class wrong_return_type_le final {};
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator==(wrong_return_type_le, wrong_return_type_le) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator!=(wrong_return_type_le, wrong_return_type_le) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator<(wrong_return_type_le, wrong_return_type_le) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator>(wrong_return_type_le, wrong_return_type_le) noexcept;
/**
 * @brief Comparison operator.
 */
void                       operator>=(wrong_return_type_le, wrong_return_type_le) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator<=(wrong_return_type_le, wrong_return_type_le) noexcept;

/**
 * @brief Class to test equality_comparable.
 */
class wrong_return_type_ge final {};
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator==(wrong_return_type_ge, wrong_return_type_ge) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator!=(wrong_return_type_ge, wrong_return_type_ge) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator<(wrong_return_type_ge, wrong_return_type_ge) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator>(wrong_return_type_ge, wrong_return_type_ge) noexcept;
/**
 * @brief Comparison operator.
 * @return result of comparison.
 */
bool                       operator>=(wrong_return_type_ge, wrong_return_type_ge) noexcept;
/**
 * @brief Comparison operator.
 */
void                       operator<=(wrong_return_type_ge, wrong_return_type_ge) noexcept;

/**
 * @brief Class to test equality_comparable.
 */
class wrong_return_type final {};
/**
 * @brief Comparison operator.
 */
void                    operator==(wrong_return_type, wrong_return_type) noexcept;
/**
 * @brief Comparison operator.
 */
void                    operator!=(wrong_return_type, wrong_return_type) noexcept;
/**
 * @brief Comparison operator.
 */
void                    operator<(wrong_return_type, wrong_return_type) noexcept;
/**
 * @brief Comparison operator.
 */
void                    operator>(wrong_return_type, wrong_return_type) noexcept;
/**
 * @brief Comparison operator.
 */
void                    operator>=(wrong_return_type, wrong_return_type) noexcept;
/**
 * @brief Comparison operator.
 */
void                    operator<=(wrong_return_type, wrong_return_type) noexcept;

/**
 * @brief
 */
class HasAdlSwap final {
private:
  /**
   * @brief Value.
   */
  std::int32_t m_value{0};

public:
  /**
   * @brief Ctor.
   */
  HasAdlSwap()                              = default;
  /**
   * @brief Dtor.
   */
  ~HasAdlSwap()                             = default;
  /**
   * @brief Ctor copy deleted.
   * Deleted.
   */
  HasAdlSwap(HasAdlSwap const &)            = delete;
  /**
   * @brief Ctor move deleted.
   * Deleted.
   */
  HasAdlSwap(HasAdlSwap &&)                 = delete;
  /**
   * @brief Assignment copy deleted.
   * @return HasAdlSwap&
   */
  HasAdlSwap &operator=(HasAdlSwap const &) = delete;
  /**
   * @brief Assignment move deleted.
   * @return HasAdlSwap&
   */
  HasAdlSwap &operator=(HasAdlSwap &&)      = delete;
  /**
   * @brief Swap.
   * @param other
   */
  void        localSwap(HasAdlSwap &other) noexcept {
    std::int32_t const tmp{m_value};
    m_value       = other.m_value;
    other.m_value = tmp;
  }
};

/**
 * @brief Swap.
 * @param left
 * @param right
 */
inline static void swap(HasAdlSwap &left, HasAdlSwap &right) noexcept {
  left.localSwap(right);
}

} // namespace test_concepts_helpers
#endif /* PSTL_CONCEPTS_HELPER_H */
