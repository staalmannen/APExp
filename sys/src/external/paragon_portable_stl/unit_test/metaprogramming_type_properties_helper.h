// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_type_properties_helper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_METAPROGRAMMING_TYPE_PROPERTIES_HELPER_H
#define PSTL_METAPROGRAMMING_TYPE_PROPERTIES_HELPER_H

#include <cstdint>
#include <stdexcept>

namespace metaprogramming_type_properties_helper {

/**
 * @brief Helper non trivial class.
 *
 */
class metaprogramming_type_properties_helper final {
public:
  /**
   * @brief Helper unscopped enum
   *
   */
  enum unscopped_enum : std::int32_t {
  };
  /**
   * @brief Helper scopped enum
   *
   */
  enum class scopped_enum : std::int32_t {
  };
  /**
   * @brief Non trivial constructed value.
   */
  std::int32_t value{0};

  /**
   * @brief Helper aggregate class.
   *
   */
  class aggregate_class final {
  public:
    /**
     * @brief Helper value
     */
    std::int32_t value_a{0};
    /**
     * @brief Helper value
     */
    std::int32_t value_b{0};
  };
  /**
   * @brief Helper trivial class.
   *
   */
  class trivial_class final {
  public:
    /**
     * @brief Trivial destructor.
     */
    ~trivial_class() noexcept = default;

    /**
     * @brief Trivial constructor.
     */
    trivial_class() noexcept = default;

    /**
     * @brief Trivial copy constructor.
     */
    trivial_class(trivial_class const &) noexcept = default;

    /**
     * @brief Trivial move constructor.
     */
    trivial_class(trivial_class &&) noexcept = default;

    /**
     * @brief Trivial copy assignment operator.
     */
    trivial_class &operator=(trivial_class const &) & noexcept = default;

    /**
     * @brief Trivial move assignment operator.
     */
    trivial_class &operator=(trivial_class &&) & noexcept = default;

    /**
     * @brief Non trivial constructor.
     */
    constexpr explicit trivial_class(std::int32_t) noexcept {
    }
    /**
     * @brief Helper function.
     * @return 0.
     */
    trivial_class *function() noexcept {
      return this;
    }
  } cls;

  /**
   * @brief Helper non trivial virtual class.
   */
  class virtual_class {
  public:
    /**
     * @brief Destroy the metaprogramming type properties non trivial object
     *
     */
    virtual ~virtual_class() noexcept = default;

    /**
     * @brief Default constructor.
     */
    virtual_class() noexcept = default;

    /**
     * @brief Copy constructor.
     */
    virtual_class(virtual_class const &) noexcept = default;

    /**
     * @brief Move constructor.
     *
     */
    virtual_class(virtual_class &&) noexcept = default;

    /**
     * @brief Copy assignment operator.
     */
    virtual_class &operator=(virtual_class const &) & noexcept = default;

    /**
     * @brief Move assignment operator.
     */
    virtual_class &operator=(virtual_class &&) & noexcept = default;

    /**
     * @brief Helper virtual function.
     * @return 0.
     */
    virtual std::int32_t function() const noexcept {
      return 0;
    }
  };

  /**
   * @brief Helper non trivial virtual class.
   */
  class pure_virtual_class {
  public:
    /**
     * @brief Destroy the metaprogramming type properties non trivial object
     *
     */
    virtual ~pure_virtual_class() noexcept = default;

    /**
     * @brief Default constructor.
     */
    pure_virtual_class() noexcept = default;

  protected:
    /**
     * @brief Copy constructor.
     */
    pure_virtual_class(pure_virtual_class const &) noexcept = default;

    /**
     * @brief Move constructor.
     *
     */
    pure_virtual_class(pure_virtual_class &&) noexcept = default;

    /**
     * @brief Copy assignment operator.
     */
    pure_virtual_class &operator=(pure_virtual_class const &) & noexcept = default;

    /**
     * @brief Move assignment operator.
     *
     */
    pure_virtual_class &operator=(pure_virtual_class &&) & noexcept = default;

  public:
    /**
     * @brief Helper virtual function.
     * @return 0.
     */
    virtual std::int32_t function() const noexcept = 0;
  };

  /**
   * @brief Helper class inheritor from pure_virtual_class
   *
   */
  class inheritor_virtual_class final : public pure_virtual_class {
  public:
    /**
     * @brief Helper virtual function.
     * @return 0.
     */
    std::int32_t function() const noexcept final {
      return 0;
    }
  };

  /**
   * @brief Helper class without destructor.
   *
   */
  class not_destructor_class final {
  public:
    /**
     * @brief Deleted destructor.
     */
    ~not_destructor_class() noexcept = delete;

    /**
     * @brief Deleted copy constructor.
     */
    not_destructor_class(not_destructor_class const &) noexcept            = delete;
    /**
     * @brief Deleted move constructor.
     */
    not_destructor_class(not_destructor_class &&) noexcept                 = delete;
    /**
     * @brief Deleted assignment operator.
     */
    not_destructor_class &operator=(not_destructor_class const &) noexcept = delete;
    /**
     * @brief Deleted assignment operator.
     */
    not_destructor_class &operator=(not_destructor_class &&) noexcept      = delete;
  };

  /**
   * @brief Helper throw class.
   */
  class throw_class final {
    /**
     * @brief Helper flag for throw exception.
     *
     */
    bool &m_need_throw;

    /**
     * @brief Helper value.
     */
    std::int32_t m_helper_value;

    /**
     * @brief Get inner helper flag reference.
     * @return reference to helper flag.
     */
    inline static bool &get_need_throw() noexcept {
      static bool throw_value{false};
      return throw_value;
    }

  public:
    /**
     * @brief Default constructor with exception.
     */
    throw_class() : throw_class(get_need_throw(), false) {
    }
    /**
     * @brief Special constructor with exception.
     *
     * @param need_throw external flag for throw.
     * @param current_throw local flag for throw.
     */
    throw_class(bool &need_throw, bool const current_throw) : m_need_throw(need_throw), m_helper_value(0) {
      if (m_need_throw || current_throw) {
        throw std::runtime_error("throw_class");
      }
    }

    /**
     * @brief Copy constructor with exception.
     * @param source object.
     */
    throw_class(throw_class const &source) : m_need_throw(source.m_need_throw), m_helper_value(source.m_helper_value) {
      if (m_need_throw) {
        throw std::runtime_error("throw_class");
      }
    }

    /**
     * @brief Move constructor with exception.
     * @param source object.
     */
    throw_class(throw_class &&source) : m_need_throw(source.m_need_throw), m_helper_value(source.m_helper_value) {
      if (m_need_throw) {
        throw std::runtime_error("throw_class");
      }
    }

    /**
     * @brief Assign operator with exception.
     * @param source object.
     */
    throw_class &operator=(std::int32_t const source) &;

    /**
     * @brief Copy assign operator with exception.
     * @param source object.
     */
    throw_class &operator=(throw_class const &source) &;

    /**
     * @brief Move assign operator with exception.
     * @param source object.
     */
    throw_class &operator=(throw_class &&source) &;

    /**
     * @brief Destructor with exception.
     */
    ~throw_class() noexcept(false) {
      m_helper_value = 0;
    }

    /**
     * @brief Helepr function.
     * @return 0
     */
    std::int32_t check() const noexcept {
      return m_helper_value;
    }

    /**
     * @brief Helper swap function.
     * @param source
     */
    void local_swap(throw_class &source);
  };

  /**
   * @brief Helper struct with no padded members.
   *
   */
  struct unpadded {
    /**
     * @brief Member a with no padding bits.
     *
     */
    std::uint32_t a;

    /**
     * @brief Member b with no padding bits.
     *
     */
    std::uint32_t b;
  };

  /**
   * @brief Helper struct with padded members (most likely).
   *
   */
  struct likely_padded {
    /**
     * @brief Member c with padding bits after (to align the next member to 16 bits)
     *
     */
    std::uint8_t c;

    /**
     * @brief Member st with no padding bits.
     *
     */
    std::uint16_t st;

    /**
     * @brief Member i with no padding bits.
     *
     */
    std::uint32_t i;
  };

  /**
   * @brief Destructor.
   *
   */
  ~metaprogramming_type_properties_helper() noexcept = default;

  /**
   * @brief Ctor for non trivial class ( member variable has non trivial constructor ).
   */
  metaprogramming_type_properties_helper() noexcept = default;

  /**
   * @brief Trivial copy ctor for non trivial class.
   */
  metaprogramming_type_properties_helper(metaprogramming_type_properties_helper const &) noexcept = default;

  /**
   * @brief Trivial move ctor for non trivial class.
   */
  metaprogramming_type_properties_helper(metaprogramming_type_properties_helper &&) noexcept = default;

  /**
   * @brief Trivial copy assignment operator.
   */
  metaprogramming_type_properties_helper &operator=(metaprogramming_type_properties_helper const &) & noexcept
    = default;

  /**
   * @brief Trivial move assignment operator.
   */
  metaprogramming_type_properties_helper &operator=(metaprogramming_type_properties_helper &&) & noexcept = default;
};

/**
 * @brief Help swap function.
 *
 * @param left one object.
 * @param right other object.
 */
inline static void swap(metaprogramming_type_properties_helper::throw_class &left,
                        metaprogramming_type_properties_helper::throw_class &right) {
  try {
    left.local_swap(right);
  } catch (std::runtime_error &) {
    throw;
  }
}

/**
 * @brief Helper swap function.
 * @param source
 */
inline void metaprogramming_type_properties_helper::throw_class::local_swap(throw_class &source) {
  std::int32_t const tmp{source.m_helper_value};
  source.m_helper_value = m_helper_value;
  m_helper_value        = tmp;

  if (m_need_throw) {
    throw std::runtime_error("throw_class");
  }
}

/**
 * @brief Assign operator with exception.
 * @param source object.
 */
inline metaprogramming_type_properties_helper::throw_class &
  metaprogramming_type_properties_helper::throw_class::operator=(std::int32_t const source) & {
  m_helper_value = source;
  if (m_need_throw) {
    throw std::runtime_error("throw_class");
  }
  return *this;
}

/**
 * @brief Copy assign operator with exception.
 * @param source object.
 */
inline metaprogramming_type_properties_helper::throw_class &
  metaprogramming_type_properties_helper::throw_class::operator=(throw_class const &source) & {
  if (this != &source) {
    try {
      throw_class tmp{source};
      swap(*this, tmp);
    } catch (std::runtime_error &) {
      throw;
    }
  }
  return *this;
}

/**
 * @brief Move assign operator with exception.
 * @param source object.
 */
inline metaprogramming_type_properties_helper::throw_class &
  metaprogramming_type_properties_helper::throw_class::operator=(throw_class &&source) & {
  try {
    throw_class tmp{std::move(source)};
    swap(*this, tmp);
  } catch (std::runtime_error &) {
    throw;
  }
  return *this;
}

/**
 * @brief Help swap function.
 *
 * @param left one object.
 * @param right other object.
 */
inline static void swap(metaprogramming_type_properties_helper::throw_class &left, std::int32_t &right) {
  std::int32_t const tmp{left.check()};
  try {
    left = right;
  } catch (std::runtime_error &) {
    throw;
  }
  right = tmp;
}

/**
 * @brief Help swap function.
 *
 * @param left one object.
 * @param right other object.
 */
inline static void swap(std::int32_t &left, metaprogramming_type_properties_helper::throw_class &right) {
  try {
    std::int32_t const tmp{left};
    left  = right.check();
    right = tmp;
  } catch (std::runtime_error &) {
    throw;
  }
}
/**
 * @brief Disable swap function for metaprogramming_type_properties_helper::aggregate_class.
 *
 * @param left one object.
 * @param right other object.
 */
inline static void swap(metaprogramming_type_properties_helper::aggregate_class &left,
                        metaprogramming_type_properties_helper::aggregate_class &right) noexcept
  = delete;

/**
 * @brief Help swap function.
 *
 * @param left one object.
 * @param right other object.
 */
inline static void swap(metaprogramming_type_properties_helper &left,
                        metaprogramming_type_properties_helper &right) noexcept {
  auto temp(std::move(left));
  left  = std::move(right);
  right = std::move(temp);
}

/**
 * @brief Help swap function.
 *
 * @param left one object.
 * @param right other object.
 */
inline static void swap(metaprogramming_type_properties_helper::aggregate_class &left,
                        metaprogramming_type_properties_helper                  &right) noexcept {
  auto temp(std::move(left.value_a));
  left.value_a = std::move(right.value);
  right.value  = std::move(temp);
}

/**
 * @brief Help swap function.
 *
 * @param left one object.
 * @param right other object.
 */
inline static void swap(metaprogramming_type_properties_helper                  &left,
                        metaprogramming_type_properties_helper::aggregate_class &right) noexcept {
  auto temp(std::move(right.value_a));
  right.value_a = std::move(left.value);
  left.value    = std::move(temp);
}

} // namespace metaprogramming_type_properties_helper

#endif // PSTL_METAPROGRAMMING_TYPE_PROPERTIES_HELPER_H
