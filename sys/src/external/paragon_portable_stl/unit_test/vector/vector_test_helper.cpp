// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="vector_test_helper.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include "vector_test_helper.h"

std::int32_t test_vector_helper::ThrowSometime::m_throw_on_construct{100};
std::int32_t test_vector_helper::ThrowSometime::m_construct_count{0};
std::int32_t test_vector_helper::ThrowSometime::m_destruct_count{0};

bool test_vector_helper::ThrowCopyMove::m_throw_on_copy{false};
bool test_vector_helper::ThrowCopyMove::m_throw_on_move{false};

namespace test_vector_helper {
bool operator<(LessAndEqComp const &lhs, LessAndEqComp const &rhs) noexcept {
  return lhs.getValue() < rhs.getValue();
}

bool operator==(LessAndEqComp const &lhs, LessAndEqComp const &rhs) noexcept {
  return lhs.getValue() == rhs.getValue();
}
}
