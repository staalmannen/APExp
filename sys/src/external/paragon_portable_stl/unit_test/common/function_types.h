// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="function_types.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FUNCTION_TYPES_H
#define PSTL_FUNCTION_TYPES_H

#include <cstdint>

namespace test_common_helper {

class FunctionObject {
  std::int32_t m_data[10]; // dummy variable to prevent small object optimization in ::function

public:
  static std::int32_t count;

  FunctionObject() {
    ++count;
    for (std::int32_t i{0}; i < 10; ++i) {
      m_data[i] = i;
    }
  }

  FunctionObject(FunctionObject const &) {
    ++count;
  }
  ~FunctionObject() {
    --count;
    (static_cast<void>(m_data));
  }

  std::int32_t operator()() const {
    return 42;
  }
  std::int32_t operator()(std::int32_t i) const {
    return i;
  }
  std::int32_t operator()(std::int32_t i, std::int32_t) const {
    return i;
  }
  std::int32_t operator()(std::int32_t i, std::int32_t, std::int32_t) const {
    return i;
  }
};

std::int32_t FunctionObject::count = 0;

class MemFunClass {
  std::int32_t m_data[10]; // dummy variable to prevent small object optimization in ::function

public:
  static std::int32_t count;

  MemFunClass() {
    ++count;
    for (std::int32_t i{0}; i < 10; ++i) {
      m_data[i] = 0;
    }
  }

  MemFunClass(MemFunClass const &) {
    ++count;
    (static_cast<void>(m_data));
  }

  ~MemFunClass() {
    --count;
  }

  std::int32_t foo() const {
    return 42;
  }
  std::int32_t foo(std::int32_t i) const {
    return i;
  }
  std::int32_t foo(std::int32_t i, std::int32_t) const {
    return i;
  }
  std::int32_t foo(std::int32_t i, std::int32_t, std::int32_t) const {
    return i;
  }
};

std::int32_t MemFunClass::count = 0;

static std::int32_t FreeFunction() {
  return 42;
}
static std::int32_t FreeFunction(std::int32_t i) {
  return i;
}
static std::int32_t FreeFunction(std::int32_t i, std::int32_t) {
  return i;
}
static std::int32_t FreeFunction(std::int32_t i, std::int32_t, std::int32_t) {
  return i;
}
} // namespace test_common_helper

#endif // PSTL_FUNCTION_TYPES_H
