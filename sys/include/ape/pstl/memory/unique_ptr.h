// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="unique_ptr.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_UNIQUE_PTR_H
#define PSTL_UNIQUE_PTR_H

#include "../common/nullptr_t.h"
#include "../functional/less.h"
#include "../metaprogramming/composite_type/is_reference.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/common_type.h"
#include "../metaprogramming/other_transformations/conditional_bool_constant.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/get_pointer_type.h"
#include "../metaprogramming/other_transformations/type_identity.h"
#include "../metaprogramming/primary_type/is_array.h"
#include "../metaprogramming/reference_modifications/add_lvalue_reference.h"
#include "../metaprogramming/reference_modifications/remove_reference.h"
#include "../metaprogramming/type_properties/is_assignable.h"
#include "../metaprogramming/type_properties/is_copy_constructible.h"
#include "../metaprogramming/type_properties/is_default_constructible.h"
#include "../metaprogramming/type_properties/is_move_assignable.h"
#include "../metaprogramming/type_properties/is_move_constructible.h"
#include "../metaprogramming/type_relations/is_convertible.h"
#include "../metaprogramming/type_relations/is_same.h"
#include "../utility/general/declval.h"
#include "compressed_pair.h"
#include "default_delete.h"

namespace portable_stl {
/**
 * @brief A unique pointer is an object that owns another object and manages that other object through a pointer.
 *
 * @tparam t_type The type of object pointed to by the stored pointer.
 * @tparam t_deleter The type of remover of the object pointed to by the stored pointer.
 */
template<class t_type, class t_deleter = ::portable_stl::default_delete<t_type>> class unique_ptr final {
public:
  /**
   * @brief The type of object pointed to by the stored pointer.
   *
   */
  using element_type = t_type;
  /**
   * @brief The type of remover of the object pointed to by the stored pointer.
   *
   */
  using deleter_type = t_deleter;

  /**
   * @brief The type of stored pointer.
   */
  using pointer = ::portable_stl::get_pointer_type_t<element_type, ::portable_stl::remove_reference_t<deleter_type>>;

private:
  /**
   * @brief Saving a pointer and deleter the object pointed to by the pointer.
   *
   */
  ::portable_stl::compressed_pair<pointer, deleter_type> m_storage;

public:
  /**
   * @brief Copy constructor deleted.
   */
  unique_ptr(unique_ptr const &) noexcept            = delete;
  /**
   * @brief Copy assignment deleted.
   */
  unique_ptr &operator=(unique_ptr const &) noexcept = delete;

  /**
   * @brief Default constructor.
   * pointer == nullptr, deleter = deleter_type().
   */
  template<class t_other_deleter = deleter_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_pointer<t_other_deleter>>,
                                         ::portable_stl::is_default_constructible<t_other_deleter>>,
             void *>
           = nullptr>
  constexpr unique_ptr() noexcept : m_storage(pointer{}){}

  /**
   * @brief Construct object with pointer == nullptr.
   * pointer == nullptr, deleter = deleter_type().
   *
   */
  template<class t_other_deleter = deleter_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_pointer<t_other_deleter>>,
                                         ::portable_stl::is_default_constructible<t_other_deleter>>,
             void *>
           = nullptr>
  unique_ptr(::portable_stl::nullptr_t) noexcept : unique_ptr() {
  }

  /**
   * @brief Construct object with pointer_value.
   * pointer == pointer_value, deleter = deleter_type().
   *
   * @param pointer_value the pointer value.
   */
  template<class t_other_deleter = deleter_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_pointer<t_other_deleter>>,
                                         ::portable_stl::is_default_constructible<t_other_deleter>>,
             void *>
           = nullptr>
  unique_ptr(::portable_stl::type_identity_t<pointer> pointer_value) noexcept : m_storage(pointer_value) {
  }

  /**
   * @brief Construct object with pointer_value and deleter_value.
   * pointer == pointer_value, deleter = deleter_value.
   *
   * @param pointer_value the pointer value.
   * @param deleter_value the deleter value.
   */
  template<class t_other_deleter = deleter_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_pointer<t_other_deleter>>,
                                         ::portable_stl::is_copy_constructible<t_other_deleter>>,
             void *>
           = nullptr>
  unique_ptr(::portable_stl::type_identity_t<pointer> pointer_value, deleter_type const &deleter_value) noexcept
      : m_storage(pointer_value, deleter_value) {
  }

  /**
   * @brief Construct object with pointer_value and deleter_value.
   * pointer == pointer_value, deleter = deleter_value.
   *
   * @param pointer_value the pointer value.
   * @param deleter_value the deleter value.
   */
  template<class t_other_deleter = deleter_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_pointer<t_other_deleter>>,
                                         ::portable_stl::is_move_constructible<t_other_deleter>>,
             void *>
           = nullptr>
  unique_ptr(::portable_stl::type_identity_t<pointer>           pointer_value,
             ::portable_stl::remove_reference_t<deleter_type> &&deleter_value) noexcept
      : m_storage(pointer_value, ::portable_stl::move(deleter_value)) {
  }

  /**
   * @brief Construct from other unique pointer.
   * default.
   *
   * @param other the other unique pointer.
   */
  template<class t_other_deleter = deleter_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_pointer<t_other_deleter>>,
                                         ::portable_stl::is_move_constructible<t_other_deleter>>,
             void *>
           = nullptr>
  unique_ptr(unique_ptr &&other) noexcept : unique_ptr(other.release(), ::portable_stl::move(other.get_deleter())) {
  }

  /**
   * @brief Construct from other unique pointer.
   * default.
   *
   * @param other the other unique pointer.
   */
  template<
    class t_other_type,
    class t_other_deleter,
    ::portable_stl::enable_if_bool_constant_t<
      ::portable_stl::conjunction<
        ::portable_stl::negation<::portable_stl::is_array<t_other_type>>,
        ::portable_stl::is_convertible<typename unique_ptr<t_other_type, t_other_deleter>::pointer, pointer>,
        ::portable_stl::conditional_bool_constant_t<::portable_stl::is_reference<deleter_type>,
                                                    ::portable_stl::is_same<t_other_deleter, deleter_type>,
                                                    ::portable_stl::is_convertible<t_other_deleter, deleter_type>>>,
      void *>
    = nullptr>
  unique_ptr(unique_ptr<t_other_type, t_other_deleter> &&other) noexcept
      : m_storage(other.release(), ::portable_stl::move(other.get_deleter())) {
  }

  /**
   * @brief Destroy the unique pointer object.
   */
  ~unique_ptr() noexcept {
    static_cast<void>(clean());
  }

  /**
   * @brief Move assignment from other unique pointer.
   * @param other the other unique pointer.
   * @return current object reference.
   */
  template<class t_other_deleter = deleter_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_move_assignable<t_other_deleter>, void *>
           = nullptr>
  unique_ptr &operator=(unique_ptr &&other) & noexcept {
    unique_ptr tmp{::portable_stl::move(other)};
    local_swap(tmp);
    return *this;
  }

  /**
   * @brief Move assignment from other unique pointer.
   * @param other the other unique pointer.
   * @return current object reference.
   */
  template<class t_other_type,
           class t_other_deleter,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               ::portable_stl::negation<::portable_stl::is_array<t_other_type>>,
               ::portable_stl::is_assignable<::portable_stl::add_lvalue_reference_t<deleter_type>, t_other_deleter>,
               ::portable_stl::is_convertible<typename unique_ptr<t_other_type, t_other_deleter>::pointer, pointer>>,
             void *>
           = nullptr>
  unique_ptr &operator=(unique_ptr<t_other_type, t_other_deleter> &&other) & noexcept {
    unique_ptr tmp{::portable_stl::move(other)};
    local_swap(tmp);
    return *this;
  }

  /**
   * @brief Assignment nullptr.
   * pointer == nullptr
   * @return current object reference.
   */
  unique_ptr &operator=(::portable_stl::nullptr_t) & noexcept {
    static_cast<void>(reset());
    return *this;
  }

  /**
   * @brief Return reference to object.
   *
   * @return reference to object.
   */
  ::portable_stl::add_lvalue_reference_t<element_type> operator*() const
    noexcept(noexcept(*(::portable_stl::declval<pointer>()))) {
    return *(m_storage.get_first());
  }

  /**
   * @brief Return pointer to object.
   *
   * @return pointer to object.
   */
  pointer operator->() const noexcept {
    return m_storage.get_first();
  }

  /**
   * @brief Return pointer to object.
   *
   * @return pointer to object.
   */
  pointer get() const noexcept {
    return m_storage.get_first();
  }

  /**
   * @brief Deter getter.
   * @return reference to deleter.
   */
  deleter_type &get_deleter() noexcept {
    return m_storage.get_second();
  }

  /**
   * @brief Deter getter.
   * @return reference to deleter.
   */
  deleter_type const &get_deleter() const noexcept {
    return m_storage.get_second();
  }

  /**
   * @brief unique pointer contains valid pointer
   * @retval true if pointer is valid.
   * @retval false if pointer is invalid.
   */
  explicit operator bool() const noexcept {
    return !(get() == pointer{});
  }

  /**
   * @brief Release pointer and not remove object.
   *
   * @return released pointer.
   */
  pointer release() noexcept {
    pointer const tmp{m_storage.get_first()};
    m_storage.get_first() = pointer{};
    return tmp;
  }

  /**
   * @brief Clean unique pointer value. Destroy object.
   * @return status of destroing object.
   */
  auto clean() noexcept -> decltype(m_storage.get_second()(m_storage.get_first())) {
    if (operator bool()) {
      return m_storage.get_second()(m_storage.get_first());
    }
    return {};
  }

  /**
   * @brief Reset the object pointed to by the stored pointer and set new pointer value.
   * @param pointer_value the new pointer value.
   * @return Status of destroing object and reset operation.
   */
  auto reset(pointer pointer_value = pointer{}) noexcept -> decltype(m_storage.get_second()(m_storage.get_first())) {
    auto result(clean());
    if (result) {
      m_storage.get_first() = pointer_value;
    }
    return result;
  }

  /**
   * @brief Swap current object and other.
   * @param other the object for swap.
   */
  void local_swap(unique_ptr &other) noexcept {
    ::portable_stl::swap(m_storage.get_second(), other.m_storage.get_second());
    ::portable_stl::swap(m_storage.get_first(), other.m_storage.get_first());
  }
};

/**
 * @brief A unique pointer is an object that owns another object and manages that other object through a pointer.
 *
 * @tparam t_type The type of object pointed to by the stored pointer.
 * @tparam t_deleter The type of remover of the object pointed to by the stored pointer.
 */
template<class t_type, class t_deleter> class unique_ptr<t_type[], t_deleter> final {
public:
  /**
   * @brief The type of object pointed to by the stored pointer.
   *
   */
  using element_type = t_type;
  /**
   * @brief The type of remover of the object pointed to by the stored pointer.
   *
   */
  using deleter_type = t_deleter;

  /**
   * @brief The type of stored pointer.
   */
  using pointer = ::portable_stl::get_pointer_type_t<element_type, ::portable_stl::remove_reference_t<deleter_type>>;

private:
  /**
   * @brief Saving a pointer and deleter the object pointed to by the pointer.
   *
   */
  ::portable_stl::compressed_pair<pointer, deleter_type> m_storage;

public:
  /**
   * @brief Copy constructor deleted.
   */
  unique_ptr(unique_ptr const &) noexcept            = delete;
  /**
   * @brief Copy assignment deleted.
   */
  unique_ptr &operator=(unique_ptr const &) noexcept = delete;

  /**
   * @brief Default constructor.
   * pointer == nullptr, deleter = deleter_type().
   */
  template<class t_other_deleter = deleter_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_pointer<t_other_deleter>>,
                                         ::portable_stl::is_default_constructible<t_other_deleter>>,
             void *>
           = nullptr>
  constexpr unique_ptr() noexcept : m_storage(pointer{}){}

  /**
   * @brief Construct object with pointer == nullptr.
   * pointer == nullptr, deleter = deleter_type().
   *
   */
  template<class t_other_deleter = deleter_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_pointer<t_other_deleter>>,
                                         ::portable_stl::is_default_constructible<t_other_deleter>>,
             void *>
           = nullptr>
  unique_ptr(::portable_stl::nullptr_t) noexcept : unique_ptr() {
  }

  /**
   * @brief Construct object with pointer_value.
   * pointer == pointer_value, deleter = deleter_type().
   *
   * @param pointer_value the pointer value.
   */
  template<class t_other_deleter = deleter_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_pointer<t_other_deleter>>,
                                         ::portable_stl::is_default_constructible<t_other_deleter>>,
             void *>
           = nullptr>
  unique_ptr(::portable_stl::type_identity_t<pointer> pointer_value) noexcept : m_storage(pointer_value) {
  }

  /**
   * @brief Construct object with pointer_value and deleter_value.
   * pointer == pointer_value, deleter = deleter_value.
   *
   * @param pointer_value the pointer value.
   * @param deleter_value the deleter value.
   */
  template<class t_other_deleter = deleter_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_pointer<t_other_deleter>>,
                                         ::portable_stl::is_copy_constructible<t_other_deleter>>,
             void *>
           = nullptr>
  unique_ptr(::portable_stl::type_identity_t<pointer> pointer_value, deleter_type const &deleter_value) noexcept
      : m_storage(pointer_value, deleter_value) {
  }

  /**
   * @brief Construct object with pointer_value and deleter_value.
   * pointer == pointer_value, deleter = deleter_value.
   *
   * @param pointer_value the pointer value.
   * @param deleter_value the deleter value.
   */
  template<class t_other_deleter = deleter_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_pointer<t_other_deleter>>,
                                         ::portable_stl::is_move_constructible<t_other_deleter>>,
             void *>
           = nullptr>
  unique_ptr(::portable_stl::type_identity_t<pointer>           pointer_value,
             ::portable_stl::remove_reference_t<deleter_type> &&deleter_value) noexcept
      : m_storage(pointer_value, ::portable_stl::move(deleter_value)) {
  }

  /**
   * @brief Construct from other unique pointer.
   * default.
   *
   * @param other the other unique pointer.
   */
  template<class t_other_deleter = deleter_type,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<::portable_stl::negation<::portable_stl::is_pointer<t_other_deleter>>,
                                         ::portable_stl::is_move_constructible<t_other_deleter>>,
             void *>
           = nullptr>
  unique_ptr(unique_ptr &&other) noexcept : unique_ptr(other.release(), ::portable_stl::move(other.get_deleter())) {
  }

  /**
   * @brief Construct from other unique pointer.
   * default.
   *
   * @param other the other unique pointer.
   */
  template<
    class t_other_type,
    class t_other_deleter,
    ::portable_stl::enable_if_bool_constant_t<
      ::portable_stl::conjunction<
        ::portable_stl::is_array<t_other_type>,
        ::portable_stl::is_same<pointer, ::portable_stl::add_pointer_t<element_type>>,
        ::portable_stl::is_same<
          typename unique_ptr<t_other_type, t_other_deleter>::pointer,
          ::portable_stl::add_pointer_t<typename unique_ptr<t_other_type, t_other_deleter>::element_type>>,
        ::portable_stl::is_convertible<typename unique_ptr<t_other_type, t_other_deleter>::element_type (*)[],
                                       element_type (*)[]>,
        ::portable_stl::conditional_bool_constant_t<::portable_stl::is_reference<deleter_type>,
                                                    ::portable_stl::is_same<t_other_deleter, deleter_type>,
                                                    ::portable_stl::is_convertible<t_other_deleter, deleter_type>>>,
      void *>
    = nullptr>
  unique_ptr(unique_ptr<t_other_type, t_other_deleter> &&other) noexcept
      : m_storage(other.release(), ::portable_stl::move(other.get_deleter())) {
  }

  /**
   * @brief Destroy the unique pointer object.
   */
  ~unique_ptr() noexcept {
    static_cast<void>(clean());
  }

  /**
   * @brief Move assignment from other unique pointer.
   * @param other the other unique pointer.
   * @return current object reference.
   */
  template<class t_other_deleter = deleter_type,
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_move_assignable<t_other_deleter>, void *>
           = nullptr>
  unique_ptr &operator=(unique_ptr &&other) & noexcept {
    unique_ptr tmp{::portable_stl::move(other)};
    local_swap(tmp);
    return *this;
  }

  /**
   * @brief Move assignment from other unique pointer.
   * @param other the other unique pointer.
   * @return current object reference.
   */
  template<class t_other_type,
           class t_other_deleter,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               ::portable_stl::is_array<t_other_type>,
               ::portable_stl::is_same<pointer, ::portable_stl::add_pointer_t<element_type>>,
               ::portable_stl::is_same<
                 typename unique_ptr<t_other_type, t_other_deleter>::pointer,
                 ::portable_stl::add_pointer_t<typename unique_ptr<t_other_type, t_other_deleter>::element_type>>,
               ::portable_stl::is_assignable<::portable_stl::add_lvalue_reference_t<deleter_type>, t_other_deleter>,
               ::portable_stl::is_convertible<typename unique_ptr<t_other_type, t_other_deleter>::pointer, pointer>>,
             void *>
           = nullptr>
  unique_ptr &operator=(unique_ptr<t_other_type, t_other_deleter> &&other) & noexcept {
    unique_ptr tmp{::portable_stl::move(other)};
    local_swap(tmp);
    return *this;
  }

  /**
   * @brief Assignment nullptr.
   * pointer == nullptr
   * @return current object reference.
   */
  unique_ptr &operator=(::portable_stl::nullptr_t) & noexcept {
    static_cast<void>(reset());
    return *this;
  }

  /**
   * @brief Return reference to object.
   *
   * @return reference to object.
   */
  ::portable_stl::add_lvalue_reference_t<element_type> operator*() const
    noexcept(noexcept(*(::portable_stl::declval<pointer>()))) {
    return *(m_storage.get_first());
  }

  /**
   * @brief Return pointer to object.
   *
   * @return pointer to object.
   */
  pointer operator->() const noexcept {
    return m_storage.get_first();
  }

  /**
   * @brief Return pointer to object.
   *
   * @return pointer to object.
   */
  pointer get() const noexcept {
    return m_storage.get_first();
  }

  /**
   * @brief Deter getter.
   * @return reference to deleter.
   */
  deleter_type &get_deleter() noexcept {
    return m_storage.get_second();
  }

  /**
   * @brief Deter getter.
   * @return reference to deleter.
   */
  deleter_type const &get_deleter() const noexcept {
    return m_storage.get_second();
  }

  /**
   * @brief unique pointer contains valid pointer
   * @retval true if pointer is valid.
   * @retval false if pointer is invalid.
   */
  explicit operator bool() const noexcept {
    return !(get() == pointer{});
  }

  /**
   * @brief Release pointer and not remove object.
   *
   * @return released pointer.
   */
  pointer release() noexcept {
    pointer const tmp{m_storage.get_first()};
    m_storage.get_first() = pointer{};
    return tmp;
  }

  /**
   * @brief Clean unique pointer value. Destroy object.
   * @return status of destroing object.
   */
  auto clean() noexcept -> decltype(m_storage.get_second()(m_storage.get_first())) {
    if (operator bool()) {
      return m_storage.get_second()(m_storage.get_first());
    }
    return {};
  }

  /**
   * @brief Reset the object pointed to by the stored pointer and set new pointer value.
   * @param pointer_value the new pointer value.
   * @return Status of destroing object and reset operation.
   */
  auto reset(pointer pointer_value = pointer{}) noexcept -> decltype(m_storage.get_second()(m_storage.get_first())) {
    auto result(clean());
    if (result) {
      m_storage.get_first() = pointer_value;
    }
    return result;
  }

  /**
   * @brief Swap current object and other.
   * @param other the object for swap.
   */
  void local_swap(unique_ptr &other) noexcept {
    ::portable_stl::swap(m_storage.get_second(), other.m_storage.get_second());
    ::portable_stl::swap(m_storage.get_first(), other.m_storage.get_first());
  }
};

/**
 * @brief Swap current unique pointer and other.
 * @param left the value for swap.
 * @param right the value for swap.
 */
template<class t_value, class t_deleter>
inline static void swap(::portable_stl::unique_ptr<t_value, t_deleter> &left,
                        ::portable_stl::unique_ptr<t_value, t_deleter> &right) noexcept {
  left.local_swap(right);
}

/**
 * @brief Compare two unique pointers.
 *
 * @tparam t_type_left the type of value.
 * @tparam t_deleter_left the type of deleter.
 * @tparam t_type_right the type of value.
 * @tparam t_deleter_right the type of deleter.
 * @param left the unique pointer for compare.
 * @param right the unique pointer for compare.
 * @return result of compare.
 * @retval true pointers is equal.
 * @retval false pointers is not equal.
 */
template<class t_type_left, class t_deleter_left, class t_type_right, class t_deleter_right>
inline static bool operator==(::portable_stl::unique_ptr<t_type_left, t_deleter_left> const   &left,
                              ::portable_stl::unique_ptr<t_type_right, t_deleter_right> const &right) noexcept {
  return (left.get() == right.get());
}

/**
 * @brief Compare two unique pointers.
 *
 * @tparam t_type_left the type of value.
 * @tparam t_deleter_left the type of deleter.
 * @tparam t_type_right the type of value.
 * @tparam t_deleter_right the type of deleter.
 * @param left the unique pointer for compare.
 * @param right the unique pointer for compare.
 * @return result of compare.
 * @retval true pointers is not equal.
 * @retval false pointers is equal.
 */
template<class t_type_left, class t_deleter_left, class t_type_right, class t_deleter_right>
inline static bool operator!=(::portable_stl::unique_ptr<t_type_left, t_deleter_left> const   &left,
                              ::portable_stl::unique_ptr<t_type_right, t_deleter_right> const &right) noexcept {
  return !(left.get() == right.get());
}

/**
 * @brief Compare two unique pointers.
 *
 * @tparam t_type_left the type of value.
 * @tparam t_deleter_left the type of deleter.
 * @tparam t_type_right the type of value.
 * @tparam t_deleter_right the type of deleter.
 * @param left the unique pointer for compare.
 * @param right the unique pointer for compare.
 * @return result of compare.
 * @retval true left pointer less right pointer.
 * @retval false left pointer not less right pointer.
 */
template<class t_type_left, class t_deleter_left, class t_type_right, class t_deleter_right>
inline static bool operator<(::portable_stl::unique_ptr<t_type_left, t_deleter_left> const   &left,
                             ::portable_stl::unique_ptr<t_type_right, t_deleter_right> const &right) noexcept {
  return ::portable_stl::less<
    ::portable_stl::common_type_t<typename ::portable_stl::unique_ptr<t_type_left, t_deleter_left>::pointer,
                                  typename ::portable_stl::unique_ptr<t_type_right, t_deleter_right>::pointer>>()(
    left.get(), right.get());
}

/**
 * @brief Compare two unique pointers.
 *
 * @tparam t_type_left the type of value.
 * @tparam t_deleter_left the type of deleter.
 * @tparam t_type_right the type of value.
 * @tparam t_deleter_right the type of deleter.
 * @param left the unique pointer for compare.
 * @param right the unique pointer for compare.
 * @return result of compare.
 * @retval true left pointer greater right pointer.
 * @retval false left pointer not greater right pointer.
 */
template<class t_type_left, class t_deleter_left, class t_type_right, class t_deleter_right>
inline static bool operator>(::portable_stl::unique_ptr<t_type_left, t_deleter_left> const   &left,
                             ::portable_stl::unique_ptr<t_type_right, t_deleter_right> const &right) noexcept {
  return (right < left);
}

/**
 * @brief Compare two unique pointers.
 *
 * @tparam t_type_left the type of value.
 * @tparam t_deleter_left the type of deleter.
 * @tparam t_type_right the type of value.
 * @tparam t_deleter_right the type of deleter.
 * @param left the unique pointer for compare.
 * @param right the unique pointer for compare.
 * @return result of compare.
 * @retval true left pointer less or equal right pointer.
 * @retval false left pointer not (less or equal) right pointer.
 */
template<class t_type_left, class t_deleter_left, class t_type_right, class t_deleter_right>
inline static bool operator<=(::portable_stl::unique_ptr<t_type_left, t_deleter_left> const   &left,
                              ::portable_stl::unique_ptr<t_type_right, t_deleter_right> const &right) noexcept {
  return !(right < left);
}

/**
 * @brief Compare two unique pointers.
 *
 * @tparam t_type_left the type of value.
 * @tparam t_deleter_left the type of deleter.
 * @tparam t_type_right the type of value.
 * @tparam t_deleter_right the type of deleter.
 * @param left the unique pointer for compare.
 * @param right the unique pointer for compare.
 * @return result of compare.
 * @retval true left pointer greater or equal right pointer.
 * @retval false left pointer not (greater or equal) right pointer.
 */
template<class t_type_left, class t_deleter_left, class t_type_right, class t_deleter_right>
inline static bool operator>=(::portable_stl::unique_ptr<t_type_left, t_deleter_left> const   &left,
                              ::portable_stl::unique_ptr<t_type_right, t_deleter_right> const &right) noexcept {
  return !(left < right);
}

/**
 * @brief Compare unique pointers and nullptr.
 *
 * @tparam t_type_left the type of value.
 * @tparam t_deleter_left the type of deleter.
 * @param left the unique pointer for compare.
 * @return true pointer equal nullptr.
 * @return false pointer not equal nullptr
 */
template<class t_type_left, class t_deleter_left>
inline static bool operator==(::portable_stl::unique_ptr<t_type_left, t_deleter_left> const &left, nullptr_t) noexcept {
  return (left.get() == typename ::portable_stl::unique_ptr<t_type_left, t_deleter_left>::pointer());
}

/**
 * @brief Compare unique pointers and nullptr.
 *
 * @tparam t_type_left the type of value.
 * @tparam t_deleter_left the type of deleter.
 * @param left the unique pointer for compare.
 * @return true pointer not equal nullptr.
 * @return false pointer equal nullptr
 */
template<class t_type_left, class t_deleter_left>
inline static bool operator!=(::portable_stl::unique_ptr<t_type_left, t_deleter_left> const &left, nullptr_t) noexcept {
  return !(left.get() == typename ::portable_stl::unique_ptr<t_type_left, t_deleter_left>::pointer());
}

/**
 * @brief Compare unique pointers and nullptr.
 *
 * @tparam t_type_right the type of value.
 * @tparam t_deleter_right the type of deleter.
 * @param right the unique pointer for compare.
 * @return true pointer equal nullptr.
 * @return false pointer not equal nullptr
 */
template<class t_type_right, class t_deleter_right>
inline static bool operator==(nullptr_t,
                              ::portable_stl::unique_ptr<t_type_right, t_deleter_right> const &right) noexcept {
  return (right.get() == typename ::portable_stl::unique_ptr<t_type_right, t_deleter_right>::pointer());
}

/**
 * @brief Compare unique pointers and nullptr.
 *
 * @tparam t_type_right the type of value.
 * @tparam t_deleter_right the type of deleter.
 * @param right the unique pointer for compare.
 * @return true pointer not equal nullptr.
 * @return false pointer equal nullptr
 */
template<class t_type_right, class t_deleter_right>
inline static bool operator!=(nullptr_t,
                              ::portable_stl::unique_ptr<t_type_right, t_deleter_right> const &right) noexcept {
  return !(right.get() == typename ::portable_stl::unique_ptr<t_type_right, t_deleter_right>::pointer());
}

/**
 * @brief Compare unique pointers and nullptr.
 *
 * @tparam t_type_left the type of value.
 * @tparam t_deleter_left the type of deleter.
 * @param left the unique pointer for compare.
 * @return true pointer less nullptr.
 * @return false pointer not less nullptr
 */
template<class t_type_left, class t_deleter_left>
inline static bool operator<(::portable_stl::unique_ptr<t_type_left, t_deleter_left> const &left, nullptr_t) noexcept {
  return ::portable_stl::less<typename ::portable_stl::unique_ptr<t_type_left, t_deleter_left>::pointer>()(
    left.get(), typename ::portable_stl::unique_ptr<t_type_left, t_deleter_left>::pointer());
}

/**
 * @brief Compare unique pointers and nullptr.
 *
 * @tparam t_type_right the type of value.
 * @tparam t_deleter_right the type of deleter.
 * @param right the unique pointer for compare.
 * @return true nullptr less pointer.
 * @return false nullptr not less pointer.
 */
template<class t_type_right, class t_deleter_right>
inline static bool operator<(nullptr_t,
                             ::portable_stl::unique_ptr<t_type_right, t_deleter_right> const &right) noexcept {
  return ::portable_stl::less<typename ::portable_stl::unique_ptr<t_type_right, t_deleter_right>::pointer>()(
    typename ::portable_stl::unique_ptr<t_type_right, t_deleter_right>::pointer(), right.get());
}

/**
 * @brief Compare unique pointers and nullptr.
 *
 * @tparam t_type_left the type of value.
 * @tparam t_deleter_left the type of deleter.
 * @param left the unique pointer for compare.
 * @return true pointer greater nullptr.
 * @return false pointer not greater nullptr
 */
template<class t_type_left, class t_deleter_left>
inline static bool operator>(::portable_stl::unique_ptr<t_type_left, t_deleter_left> const &left, nullptr_t) noexcept {
  return (nullptr < left);
}

/**
 * @brief Compare unique pointers and nullptr.
 *
 * @tparam t_type_right the type of value.
 * @tparam t_deleter_right the type of deleter.
 * @param right the unique pointer for compare.
 * @return true nullptr greater pointer.
 * @return false nullptr not greater pointer.
 */
template<class t_type_right, class t_deleter_right>
inline static bool operator>(nullptr_t,
                             ::portable_stl::unique_ptr<t_type_right, t_deleter_right> const &right) noexcept {
  return (right < nullptr);
}

/**
 * @brief Compare unique pointers and nullptr.
 *
 * @tparam t_type_left the type of value.
 * @tparam t_deleter_left the type of deleter.
 * @param left the unique pointer for compare.
 * @return true pointer less or equal nullptr.
 * @return false pointer not (less or equal) nullptr
 */
template<class t_type_left, class t_deleter_left>
inline static bool operator<=(::portable_stl::unique_ptr<t_type_left, t_deleter_left> const &left, nullptr_t) noexcept {
  return !(nullptr < left);
}

/**
 * @brief Compare unique pointers and nullptr.
 *
 * @tparam t_type_right the type of value.
 * @tparam t_deleter_right the type of deleter.
 * @param right the unique pointer for compare.
 * @return true nullptr less or equal pointer.
 * @return false nullptr not (less or equal) pointer.
 */
template<class t_type_right, class t_deleter_right>
inline static bool operator<=(nullptr_t,
                              ::portable_stl::unique_ptr<t_type_right, t_deleter_right> const &right) noexcept {
  return !(right < nullptr);
}

/**
 * @brief Compare unique pointers and nullptr.
 *
 * @tparam t_type_left the type of value.
 * @tparam t_deleter_left the type of deleter.
 * @param left the unique pointer for compare.
 * @return true pointer less nullptr.
 * @return false pointer not less nullptr
 */
template<class t_type_left, class t_deleter_left>
inline static bool operator>=(::portable_stl::unique_ptr<t_type_left, t_deleter_left> const &left, nullptr_t) noexcept {
  return !(left < nullptr);
}

/**
 * @brief Compare unique pointers and nullptr.
 *
 * @tparam t_type_right the type of value.
 * @tparam t_deleter_right the type of deleter.
 * @param right the unique pointer for compare.
 * @return true nullptr greater or equal pointer.
 * @return false nullptr not (greater or equal) pointer.
 */
template<class t_type_right, class t_deleter_right>
inline static bool operator>=(nullptr_t,
                              ::portable_stl::unique_ptr<t_type_right, t_deleter_right> const &right) noexcept {
  return !(nullptr < right);
}

} // namespace portable_stl

#endif /* PSTL_UNIQUE_PTR_H */
