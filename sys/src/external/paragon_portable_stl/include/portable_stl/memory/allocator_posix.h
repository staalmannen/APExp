// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="allocator_posix.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ALLOCATOR_POSIX_H
#define PSTL_ALLOCATOR_POSIX_H
#include "../common/ptrdiff_t.h"
#include "../common/size_t.h"
#include "allocation_result.h"

namespace portable_stl {
/**
 * @brief Vector with memory manager functions.
 */
extern "C" struct posix_memory_manager {
  /**
   * @brief Allocate memory block.
   *
   * @param size the size of the new memory block [in bytes].
   *
   * @return pointer to the new memory block.
   */
  void *(*malloc)(::portable_stl::size_t size);

  /**
   * @brief Deallocate memory block.
   *
   * @param pointer the pointer to the memory block for deallocation.
   */
  void (*free)(void *pointer);
};

/**
 * @brief Class for allocate objects with external memory manager.
 *
 * @tparam t_type the type for memory allocate.
 */
template<class t_type> class allocator_posix {
  /**
   * @brief Memory manager.
   */
  posix_memory_manager m_memory_manager;

public:
  /**
   * @brief Get the manager object
   *
   * @return posix_memory_manager
   */
  constexpr posix_memory_manager get_manager() const noexcept {
    return m_memory_manager;
  }
  /**
   * @brief The work value type.
   *
   */
  using value_type = t_type;

  /**
   * @brief Can use move assignment on allocator in containers.
   *
   */
  using propagate_on_container_move_assignment = ::portable_stl::true_type;

  /**
   * @brief Default constructor.
   *
   */
  constexpr allocator_posix() noexcept : m_memory_manager({.malloc = nullptr, .free = nullptr}) {
  }

  /**
   * @brief Constructor.
   *
   */
  constexpr allocator_posix(posix_memory_manager const &memory_manager) noexcept : m_memory_manager(memory_manager) {
  }

  /**
   * @brief Default constructor.
   *
   */
  constexpr allocator_posix(allocator_posix const &) noexcept = default;

  /**
   * @brief Constructor for allocator from allocator with other type.
   *
   */
  template<class t_other_type>
  allocator_posix(allocator_posix<t_other_type> const &other) noexcept : m_memory_manager(other.get_manager()) {
  }

  /**
   * @brief Destroy the allocator object
   */
  ~allocator_posix() = default;

  /**
   * @brief Default assignment.
   *
   */
  allocator_posix &operator=(allocator_posix const &) = default;

  /**
   * @brief Allocates uninitialized storage.
   *
   * @param size_value the number of objects to allocate storage for.
   * @return Pointer to the first element of an array of size_value objects of type value_type whose elements have not
   * been constructed yet.
   */
  [[nodiscard]] value_type *allocate(size_t const size_value) noexcept {
    return static_cast<value_type *>(m_memory_manager.malloc(sizeof(value_type) * size_value));
  }

  /**
   * @brief Allocates uninitialized storage at least as large as requested size.
   *
   * @param size_value the lower bound of number of objects to allocate storage for.
   * @return std::allocation_result<T*>{pointer, size_value}, where pointer points to the first element of an array of
   * size_value objects of type value_type whose elements have not been constructed yet.
   */
  [[nodiscard]] ::portable_stl::allocation_result<value_type *> allocate_at_least(size_t const size_value) noexcept {
    return {allocate(size_value), size_value};
  }

  /**
   * @brief deallocates storage
   *
   * @param pointer_value pointer obtained from allocate() or allocate_at_least()
   * @param size_value number of objects earlier passed to allocate(), or a number between requested and actually
   * allocated number of objects via allocate_at_least() (may be equal to either bound)
   */
  void deallocate(value_type *pointer_value, size_t size_value) noexcept {
    m_memory_manager.free(pointer_value);
  }

  /**
   * @brief compares two allocator instances.
   * @tparam t_other the type for allocating.
   * @param other the other allocator.
   * @return compare status.
   */
  template<class t_other> bool is_equal(allocator_posix<t_other> const &other) const noexcept {
    return ((m_memory_manager.malloc == other.m_memory_manager.malloc)
            && (m_memory_manager.free == other.m_memory_manager.free));
  }
};
/**
 * @brief compares two allocator instances.
 * @return compare status.
 */
template<class t_left_value, class t_right_value>
inline static bool operator==(allocator_posix<t_left_value> const  &left,
                              allocator_posix<t_right_value> const &right) noexcept {
  return left.is_equal(right);
}

} // namespace portable_stl

#endif // PSTL_ALLOCATOR_POSIX_H
