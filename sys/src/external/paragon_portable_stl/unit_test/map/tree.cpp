// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tree.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <portable_stl/containers/tree.h>

TEST(tree, key_type) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief Type alias.
     */
    using t_type = std::int32_t;

    /**
     * @brief Traits alias.
     */
    using traits = ::portable_stl::tree_key_value_types<t_type>;

    ASSERT_TRUE((std::is_same<traits::key_type, t_type>{}));
    ASSERT_TRUE((std::is_same<traits::t_node_value_type, t_type>{}));
    ASSERT_TRUE((std::is_same<traits::t_container_value_type, t_type>{}));
    ASSERT_FALSE(traits::m_is_map);
  }
  {
    /**
     * @brief Type alias.
     */
    using t_type = std::pair<std::int32_t, std::int32_t>;

    /**
     * @brief Traits alias.
     */
    using traits = ::portable_stl::tree_key_value_types<t_type>;

    ASSERT_TRUE((std::is_same<traits::key_type, t_type>{}));
    ASSERT_TRUE((std::is_same<traits::t_node_value_type, t_type>{}));
    ASSERT_TRUE((std::is_same<traits::t_container_value_type, t_type>{}));
    ASSERT_FALSE(traits::m_is_map);
  }
  {
    /**
     * @brief Type alias.
     */
    using t_type = std::pair<std::int32_t const, std::int32_t>;

    /**
     * @brief Traits alias.
     */
    using traits = ::portable_stl::tree_key_value_types<t_type>;

    ASSERT_TRUE((std::is_same<traits::key_type, t_type>{}));
    ASSERT_TRUE((std::is_same<traits::t_node_value_type, t_type>{}));
    ASSERT_TRUE((std::is_same<traits::t_container_value_type, t_type>{}));
    ASSERT_FALSE(traits::m_is_map);
  }
  {
    /**
     * @brief Type alias.
     */
    using t_type = ::portable_stl::value_type_impl<std::int32_t, std::int32_t>;

    /**
     * @brief Traits alias.
     */
    using traits = ::portable_stl::tree_key_value_types<t_type>;

    ASSERT_TRUE((std::is_same<traits::key_type, std::int32_t>{}));
    ASSERT_TRUE((std::is_same<traits::mapped_type, std::int32_t>{}));
    ASSERT_TRUE((std::is_same<traits::t_node_value_type, t_type>{}));
    ASSERT_TRUE(
      (std::is_same<traits::t_container_value_type, ::portable_stl::tuple<std::int32_t const, std::int32_t>>{}));
    ASSERT_TRUE((std::is_same<traits::t_map_value_type, ::portable_stl::tuple<std::int32_t const, std::int32_t>>{}));
    // ASSERT_TRUE(traits::m_is_map);
  }
}

namespace test_tree_helper {
struct Node {
  Node *m_left;
  Node *m_right;
  Node *m_parent;
  bool  m_is_black;

  Node *parent_unsafe() const {
    return m_parent;
  }
  void set_parent(Node *x) {
    m_parent = x;
  }

  Node() : m_left(), m_right(), m_parent(), m_is_black() {
  }
};
} // namespace test_tree_helper

TEST(tree, left_rotate) {
  static_cast<void>(test_info_);

  {
    test_tree_helper::Node root;
    test_tree_helper::Node x;
    test_tree_helper::Node y;
    root.m_left = &x;
    x.m_left    = nullptr;
    x.m_right   = &y;
    x.m_parent  = &root;
    y.m_left    = nullptr;
    y.m_right   = nullptr;
    y.m_parent  = &x;

    ::portable_stl::tree_ns::tree_left_rotate(&x);

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &y);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(y.m_parent, &root);
    ASSERT_EQ(y.m_left, &x);
    ASSERT_EQ(y.m_right, nullptr);
    ASSERT_EQ(x.m_parent, &y);
    ASSERT_EQ(x.m_left, nullptr);
    ASSERT_EQ(x.m_right, nullptr);
  }

  {
    test_tree_helper::Node root;
    test_tree_helper::Node x;
    test_tree_helper::Node y;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    root.m_left = &x;
    x.m_left    = &a;
    x.m_right   = &y;
    x.m_parent  = &root;
    y.m_left    = &b;
    y.m_right   = &c;
    y.m_parent  = &x;
    a.m_parent  = &x;
    b.m_parent  = &y;
    c.m_parent  = &y;

    ::portable_stl::tree_ns::tree_left_rotate(&x);

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &y);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(y.m_parent, &root);
    ASSERT_EQ(y.m_left, &x);
    ASSERT_EQ(y.m_right, &c);
    ASSERT_EQ(x.m_parent, &y);
    ASSERT_EQ(x.m_left, &a);
    ASSERT_EQ(x.m_right, &b);
    ASSERT_EQ(a.m_parent, &x);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(b.m_parent, &x);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(c.m_parent, &y);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
  }
}

TEST(tree, right_rotate) {
  static_cast<void>(test_info_);

  {
    test_tree_helper::Node root;
    test_tree_helper::Node x;
    test_tree_helper::Node y;
    root.m_left = &x;
    x.m_left    = &y;
    x.m_right   = nullptr;
    x.m_parent  = &root;
    y.m_left    = nullptr;
    y.m_right   = nullptr;
    y.m_parent  = &x;

    ::portable_stl::tree_ns::tree_right_rotate(&x);

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &y);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(y.m_parent, &root);
    ASSERT_EQ(y.m_left, nullptr);
    ASSERT_EQ(y.m_right, &x);
    ASSERT_EQ(x.m_parent, &y);
    ASSERT_EQ(x.m_left, nullptr);
    ASSERT_EQ(x.m_right, nullptr);
  }

  {
    test_tree_helper::Node root;
    test_tree_helper::Node x;
    test_tree_helper::Node y;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    root.m_left = &x;
    x.m_left    = &y;
    x.m_right   = &c;
    x.m_parent  = &root;
    y.m_left    = &a;
    y.m_right   = &b;
    y.m_parent  = &x;
    a.m_parent  = &y;
    b.m_parent  = &y;
    c.m_parent  = &x;

    ::portable_stl::tree_ns::tree_right_rotate(&x);

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &y);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(y.m_parent, &root);
    ASSERT_EQ(y.m_left, &a);
    ASSERT_EQ(y.m_right, &x);
    ASSERT_EQ(x.m_parent, &y);
    ASSERT_EQ(x.m_left, &b);
    ASSERT_EQ(x.m_right, &c);
    ASSERT_EQ(a.m_parent, &y);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(b.m_parent, &x);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(c.m_parent, &x);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
  }
}

TEST(tree, balance_after_insert) {
  static_cast<void>(test_info_);

  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;

    root.m_left = &c;

    c.m_parent   = &root;
    c.m_left     = &b;
    c.m_right    = &d;
    c.m_is_black = true;

    b.m_parent   = &c;
    b.m_left     = &a;
    b.m_right    = nullptr;
    b.m_is_black = false;

    d.m_parent   = &c;
    d.m_left     = nullptr;
    d.m_right    = nullptr;
    d.m_is_black = false;

    a.m_parent   = &b;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = false;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &a);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_left, &c);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, &b);
    ASSERT_EQ(c.m_right, &d);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(b.m_parent, &c);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(d.m_parent, &c);
    ASSERT_EQ(d.m_left, nullptr);
    ASSERT_EQ(d.m_right, nullptr);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;

    root.m_left = &c;

    c.m_parent   = &root;
    c.m_left     = &b;
    c.m_right    = &d;
    c.m_is_black = true;

    b.m_parent   = &c;
    b.m_left     = nullptr;
    b.m_right    = &a;
    b.m_is_black = false;

    d.m_parent   = &c;
    d.m_left     = nullptr;
    d.m_right    = nullptr;
    d.m_is_black = false;

    a.m_parent   = &b;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = false;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &a);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_left, &c);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, &b);
    ASSERT_EQ(c.m_right, &d);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(b.m_parent, &c);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, &a);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(d.m_parent, &c);
    ASSERT_EQ(d.m_left, nullptr);
    ASSERT_EQ(d.m_right, nullptr);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;

    root.m_left = &c;

    c.m_parent   = &root;
    c.m_left     = &b;
    c.m_right    = &d;
    c.m_is_black = true;

    b.m_parent   = &c;
    b.m_left     = nullptr;
    b.m_right    = nullptr;
    b.m_is_black = false;

    d.m_parent   = &c;
    d.m_left     = &a;
    d.m_right    = nullptr;
    d.m_is_black = false;

    a.m_parent   = &d;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = false;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &a);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_left, &c);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, &b);
    ASSERT_EQ(c.m_right, &d);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(b.m_parent, &c);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(d.m_parent, &c);
    ASSERT_EQ(d.m_left, &a);
    ASSERT_EQ(d.m_right, nullptr);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(a.m_parent, &d);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;

    root.m_left = &c;

    c.m_parent   = &root;
    c.m_left     = &b;
    c.m_right    = &d;
    c.m_is_black = true;

    b.m_parent   = &c;
    b.m_left     = nullptr;
    b.m_right    = nullptr;
    b.m_is_black = false;

    d.m_parent   = &c;
    d.m_left     = nullptr;
    d.m_right    = &a;
    d.m_is_black = false;

    a.m_parent   = &d;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = false;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &a);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_left, &c);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, &b);
    ASSERT_EQ(c.m_right, &d);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(b.m_parent, &c);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(d.m_parent, &c);
    ASSERT_EQ(d.m_left, nullptr);
    ASSERT_EQ(d.m_right, &a);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(a.m_parent, &d);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;
    test_tree_helper::Node e;
    test_tree_helper::Node f;
    test_tree_helper::Node g;
    test_tree_helper::Node h;
    test_tree_helper::Node i;

    root.m_left = &c;

    c.m_parent   = &root;
    c.m_left     = &b;
    c.m_right    = &d;
    c.m_is_black = true;

    b.m_parent   = &c;
    b.m_left     = &a;
    b.m_right    = &g;
    b.m_is_black = false;

    d.m_parent   = &c;
    d.m_left     = &h;
    d.m_right    = &i;
    d.m_is_black = false;

    a.m_parent   = &b;
    a.m_left     = &e;
    a.m_right    = &f;
    a.m_is_black = false;

    e.m_parent   = &a;
    e.m_is_black = true;

    f.m_parent   = &a;
    f.m_is_black = true;

    g.m_parent   = &b;
    g.m_is_black = true;

    h.m_parent   = &d;
    h.m_is_black = true;

    i.m_parent   = &d;
    i.m_is_black = true;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &a);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_left, &c);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, &b);
    ASSERT_EQ(c.m_right, &d);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(b.m_parent, &c);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, &g);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(d.m_parent, &c);
    ASSERT_EQ(d.m_left, &h);
    ASSERT_EQ(d.m_right, &i);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, &e);
    ASSERT_EQ(a.m_right, &f);
    ASSERT_EQ(a.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;
    test_tree_helper::Node e;
    test_tree_helper::Node f;
    test_tree_helper::Node g;
    test_tree_helper::Node h;
    test_tree_helper::Node i;

    root.m_left = &c;

    c.m_parent   = &root;
    c.m_left     = &b;
    c.m_right    = &d;
    c.m_is_black = true;

    b.m_parent   = &c;
    b.m_left     = &g;
    b.m_right    = &a;
    b.m_is_black = false;

    d.m_parent   = &c;
    d.m_left     = &h;
    d.m_right    = &i;
    d.m_is_black = false;

    a.m_parent   = &b;
    a.m_left     = &e;
    a.m_right    = &f;
    a.m_is_black = false;

    e.m_parent   = &a;
    e.m_is_black = true;

    f.m_parent   = &a;
    f.m_is_black = true;

    g.m_parent   = &b;
    g.m_is_black = true;

    h.m_parent   = &d;
    h.m_is_black = true;

    i.m_parent   = &d;
    i.m_is_black = true;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &a);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_left, &c);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, &b);
    ASSERT_EQ(c.m_right, &d);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(b.m_parent, &c);
    ASSERT_EQ(b.m_left, &g);
    ASSERT_EQ(b.m_right, &a);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(d.m_parent, &c);
    ASSERT_EQ(d.m_left, &h);
    ASSERT_EQ(d.m_right, &i);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, &e);
    ASSERT_EQ(a.m_right, &f);
    ASSERT_EQ(a.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;
    test_tree_helper::Node e;
    test_tree_helper::Node f;
    test_tree_helper::Node g;
    test_tree_helper::Node h;
    test_tree_helper::Node i;

    root.m_left = &c;

    c.m_parent   = &root;
    c.m_left     = &b;
    c.m_right    = &d;
    c.m_is_black = true;

    b.m_parent   = &c;
    b.m_left     = &g;
    b.m_right    = &h;
    b.m_is_black = false;

    d.m_parent   = &c;
    d.m_left     = &a;
    d.m_right    = &i;
    d.m_is_black = false;

    a.m_parent   = &d;
    a.m_left     = &e;
    a.m_right    = &f;
    a.m_is_black = false;

    e.m_parent   = &a;
    e.m_is_black = true;

    f.m_parent   = &a;
    f.m_is_black = true;

    g.m_parent   = &b;
    g.m_is_black = true;

    h.m_parent   = &b;
    h.m_is_black = true;

    i.m_parent   = &d;
    i.m_is_black = true;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &a);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_left, &c);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, &b);
    ASSERT_EQ(c.m_right, &d);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(b.m_parent, &c);
    ASSERT_EQ(b.m_left, &g);
    ASSERT_EQ(b.m_right, &h);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(d.m_parent, &c);
    ASSERT_EQ(d.m_left, &a);
    ASSERT_EQ(d.m_right, &i);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(a.m_parent, &d);
    ASSERT_EQ(a.m_left, &e);
    ASSERT_EQ(a.m_right, &f);
    ASSERT_EQ(a.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;
    test_tree_helper::Node e;
    test_tree_helper::Node f;
    test_tree_helper::Node g;
    test_tree_helper::Node h;
    test_tree_helper::Node i;

    root.m_left = &c;

    c.m_parent   = &root;
    c.m_left     = &b;
    c.m_right    = &d;
    c.m_is_black = true;

    b.m_parent   = &c;
    b.m_left     = &g;
    b.m_right    = &h;
    b.m_is_black = false;

    d.m_parent   = &c;
    d.m_left     = &i;
    d.m_right    = &a;
    d.m_is_black = false;

    a.m_parent   = &d;
    a.m_left     = &e;
    a.m_right    = &f;
    a.m_is_black = false;

    e.m_parent   = &a;
    e.m_is_black = true;

    f.m_parent   = &a;
    f.m_is_black = true;

    g.m_parent   = &b;
    g.m_is_black = true;

    h.m_parent   = &b;
    h.m_is_black = true;

    i.m_parent   = &d;
    i.m_is_black = true;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &a);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_left, &c);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, &b);
    ASSERT_EQ(c.m_right, &d);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(b.m_parent, &c);
    ASSERT_EQ(b.m_left, &g);
    ASSERT_EQ(b.m_right, &h);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(d.m_parent, &c);
    ASSERT_EQ(d.m_left, &i);
    ASSERT_EQ(d.m_right, &a);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(a.m_parent, &d);
    ASSERT_EQ(a.m_left, &e);
    ASSERT_EQ(a.m_right, &f);
    ASSERT_EQ(a.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;

    root.m_left = &c;

    c.m_parent   = &root;
    c.m_left     = &a;
    c.m_right    = nullptr;
    c.m_is_black = true;

    a.m_parent   = &c;
    a.m_left     = nullptr;
    a.m_right    = &b;
    a.m_is_black = false;

    b.m_parent   = &a;
    b.m_left     = nullptr;
    b.m_right    = nullptr;
    b.m_is_black = false;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &b);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_left, &b);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, false);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, true);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;

    root.m_left = &a;

    a.m_parent   = &root;
    a.m_left     = nullptr;
    a.m_right    = &c;
    a.m_is_black = true;

    c.m_parent   = &a;
    c.m_left     = &b;
    c.m_right    = nullptr;
    c.m_is_black = false;

    b.m_parent   = &c;
    b.m_left     = nullptr;
    b.m_right    = nullptr;
    b.m_is_black = false;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &b);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_left, &b);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, true);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;
    test_tree_helper::Node e;
    test_tree_helper::Node f;
    test_tree_helper::Node g;

    root.m_left = &c;

    c.m_parent   = &root;
    c.m_left     = &a;
    c.m_right    = &g;
    c.m_is_black = true;

    a.m_parent   = &c;
    a.m_left     = &d;
    a.m_right    = &b;
    a.m_is_black = false;

    b.m_parent   = &a;
    b.m_left     = &e;
    b.m_right    = &f;
    b.m_is_black = false;

    d.m_parent   = &a;
    d.m_is_black = true;

    e.m_parent   = &b;
    e.m_is_black = true;

    f.m_parent   = &b;
    f.m_is_black = true;

    g.m_parent   = &c;
    g.m_is_black = true;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &b);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_left, &b);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, &f);
    ASSERT_EQ(c.m_right, &g);
    ASSERT_EQ(c.m_is_black, false);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, &d);
    ASSERT_EQ(a.m_right, &e);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(d.m_parent, &a);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(e.m_parent, &a);
    ASSERT_EQ(e.m_is_black, true);

    ASSERT_EQ(f.m_parent, &c);
    ASSERT_EQ(f.m_is_black, true);

    ASSERT_EQ(g.m_parent, &c);
    ASSERT_EQ(g.m_is_black, true);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;
    test_tree_helper::Node e;
    test_tree_helper::Node f;
    test_tree_helper::Node g;

    root.m_left = &a;

    a.m_parent   = &root;
    a.m_left     = &d;
    a.m_right    = &c;
    a.m_is_black = true;

    c.m_parent   = &a;
    c.m_left     = &b;
    c.m_right    = &g;
    c.m_is_black = false;

    b.m_parent   = &c;
    b.m_left     = &e;
    b.m_right    = &f;
    b.m_is_black = false;

    d.m_parent   = &a;
    d.m_is_black = true;

    e.m_parent   = &b;
    e.m_is_black = true;

    f.m_parent   = &b;
    f.m_is_black = true;

    g.m_parent   = &c;
    g.m_is_black = true;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &b);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_left, &b);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, &f);
    ASSERT_EQ(c.m_right, &g);
    ASSERT_EQ(c.m_is_black, false);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, &d);
    ASSERT_EQ(a.m_right, &e);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(d.m_parent, &a);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(e.m_parent, &a);
    ASSERT_EQ(e.m_is_black, true);

    ASSERT_EQ(f.m_parent, &c);
    ASSERT_EQ(f.m_is_black, true);

    ASSERT_EQ(g.m_parent, &c);
    ASSERT_EQ(g.m_is_black, true);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;

    root.m_left = &c;

    c.m_parent   = &root;
    c.m_left     = &b;
    c.m_right    = nullptr;
    c.m_is_black = true;

    b.m_parent   = &c;
    b.m_left     = &a;
    b.m_right    = nullptr;
    b.m_is_black = false;

    a.m_parent   = &b;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = false;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &a);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_left, &b);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, false);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, true);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;

    root.m_left = &a;

    a.m_parent   = &root;
    a.m_left     = nullptr;
    a.m_right    = &b;
    a.m_is_black = true;

    b.m_parent   = &a;
    b.m_left     = nullptr;
    b.m_right    = &c;
    b.m_is_black = false;

    c.m_parent   = &b;
    c.m_left     = nullptr;
    c.m_right    = nullptr;
    c.m_is_black = false;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &c);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_left, &b);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, true);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;
    test_tree_helper::Node e;
    test_tree_helper::Node f;
    test_tree_helper::Node g;

    root.m_left = &c;

    c.m_parent   = &root;
    c.m_left     = &b;
    c.m_right    = &g;
    c.m_is_black = true;

    b.m_parent   = &c;
    b.m_left     = &a;
    b.m_right    = &f;
    b.m_is_black = false;

    a.m_parent   = &b;
    a.m_left     = &d;
    a.m_right    = &e;
    a.m_is_black = false;

    d.m_parent   = &a;
    d.m_is_black = true;

    e.m_parent   = &a;
    e.m_is_black = true;

    f.m_parent   = &b;
    f.m_is_black = true;

    g.m_parent   = &c;
    g.m_is_black = true;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &a);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_left, &b);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, &f);
    ASSERT_EQ(c.m_right, &g);
    ASSERT_EQ(c.m_is_black, false);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, &d);
    ASSERT_EQ(a.m_right, &e);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(d.m_parent, &a);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(e.m_parent, &a);
    ASSERT_EQ(e.m_is_black, true);

    ASSERT_EQ(f.m_parent, &c);
    ASSERT_EQ(f.m_is_black, true);

    ASSERT_EQ(g.m_parent, &c);
    ASSERT_EQ(g.m_is_black, true);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;
    test_tree_helper::Node e;
    test_tree_helper::Node f;
    test_tree_helper::Node g;

    root.m_left = &a;

    a.m_parent   = &root;
    a.m_left     = &d;
    a.m_right    = &b;
    a.m_is_black = true;

    b.m_parent   = &a;
    b.m_left     = &e;
    b.m_right    = &c;
    b.m_is_black = false;

    c.m_parent   = &b;
    c.m_left     = &f;
    c.m_right    = &g;
    c.m_is_black = false;

    d.m_parent   = &a;
    d.m_is_black = true;

    e.m_parent   = &b;
    e.m_is_black = true;

    f.m_parent   = &c;
    f.m_is_black = true;

    g.m_parent   = &c;
    g.m_is_black = true;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &c);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_left, &b);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, &f);
    ASSERT_EQ(c.m_right, &g);
    ASSERT_EQ(c.m_is_black, false);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, &d);
    ASSERT_EQ(a.m_right, &e);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(d.m_parent, &a);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(e.m_parent, &a);
    ASSERT_EQ(e.m_is_black, true);

    ASSERT_EQ(f.m_parent, &c);
    ASSERT_EQ(f.m_is_black, true);

    ASSERT_EQ(g.m_parent, &c);
    ASSERT_EQ(g.m_is_black, true);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;
    test_tree_helper::Node e;
    test_tree_helper::Node f;
    test_tree_helper::Node g;
    test_tree_helper::Node h;

    root.m_left = &a;
    a.m_parent  = &root;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &a);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &a);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(a.m_parent, &root);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, true);

    a.m_right  = &b;
    b.m_parent = &a;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &b);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &a);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(a.m_parent, &root);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, &b);
    ASSERT_EQ(a.m_is_black, true);

    ASSERT_EQ(b.m_parent, &a);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, false);

    b.m_right  = &c;
    c.m_parent = &b;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &c);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, false);

    c.m_right  = &d;
    d.m_parent = &c;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &d);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, true);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, &d);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(d.m_parent, &c);
    ASSERT_EQ(d.m_left, nullptr);
    ASSERT_EQ(d.m_right, nullptr);
    ASSERT_EQ(d.m_is_black, false);

    d.m_right  = &e;
    e.m_parent = &d;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &e);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, &d);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, true);

    ASSERT_EQ(d.m_parent, &b);
    ASSERT_EQ(d.m_left, &c);
    ASSERT_EQ(d.m_right, &e);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(c.m_parent, &d);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, false);

    ASSERT_EQ(e.m_parent, &d);
    ASSERT_EQ(e.m_left, nullptr);
    ASSERT_EQ(e.m_right, nullptr);
    ASSERT_EQ(e.m_is_black, false);

    e.m_right  = &f;
    f.m_parent = &e;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &f);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, &d);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, true);

    ASSERT_EQ(d.m_parent, &b);
    ASSERT_EQ(d.m_left, &c);
    ASSERT_EQ(d.m_right, &e);
    ASSERT_EQ(d.m_is_black, false);

    ASSERT_EQ(c.m_parent, &d);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(e.m_parent, &d);
    ASSERT_EQ(e.m_left, nullptr);
    ASSERT_EQ(e.m_right, &f);
    ASSERT_EQ(e.m_is_black, true);

    ASSERT_EQ(f.m_parent, &e);
    ASSERT_EQ(f.m_left, nullptr);
    ASSERT_EQ(f.m_right, nullptr);
    ASSERT_EQ(f.m_is_black, false);

    f.m_right  = &g;
    g.m_parent = &f;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &g);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, &d);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, true);

    ASSERT_EQ(d.m_parent, &b);
    ASSERT_EQ(d.m_left, &c);
    ASSERT_EQ(d.m_right, &f);
    ASSERT_EQ(d.m_is_black, false);

    ASSERT_EQ(c.m_parent, &d);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(f.m_parent, &d);
    ASSERT_EQ(f.m_left, &e);
    ASSERT_EQ(f.m_right, &g);
    ASSERT_EQ(f.m_is_black, true);

    ASSERT_EQ(e.m_parent, &f);
    ASSERT_EQ(e.m_left, nullptr);
    ASSERT_EQ(e.m_right, nullptr);
    ASSERT_EQ(e.m_is_black, false);

    ASSERT_EQ(g.m_parent, &f);
    ASSERT_EQ(g.m_left, nullptr);
    ASSERT_EQ(g.m_right, nullptr);
    ASSERT_EQ(g.m_is_black, false);

    g.m_right  = &h;
    h.m_parent = &g;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &h);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &d);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(d.m_parent, &root);
    ASSERT_EQ(d.m_left, &b);
    ASSERT_EQ(d.m_right, &f);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(b.m_parent, &d);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, false);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, true);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(f.m_parent, &d);
    ASSERT_EQ(f.m_left, &e);
    ASSERT_EQ(f.m_right, &g);
    ASSERT_EQ(f.m_is_black, false);

    ASSERT_EQ(e.m_parent, &f);
    ASSERT_EQ(e.m_left, nullptr);
    ASSERT_EQ(e.m_right, nullptr);
    ASSERT_EQ(e.m_is_black, true);

    ASSERT_EQ(g.m_parent, &f);
    ASSERT_EQ(g.m_left, nullptr);
    ASSERT_EQ(g.m_right, &h);
    ASSERT_EQ(g.m_is_black, true);

    ASSERT_EQ(h.m_parent, &g);
    ASSERT_EQ(h.m_left, nullptr);
    ASSERT_EQ(h.m_right, nullptr);
    ASSERT_EQ(h.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;
    test_tree_helper::Node e;
    test_tree_helper::Node f;
    test_tree_helper::Node g;
    test_tree_helper::Node h;

    root.m_left = &h;
    h.m_parent  = &root;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &h);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &h);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(h.m_parent, &root);
    ASSERT_EQ(h.m_left, nullptr);
    ASSERT_EQ(h.m_right, nullptr);
    ASSERT_EQ(h.m_is_black, true);

    h.m_left   = &g;
    g.m_parent = &h;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &g);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &h);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(h.m_parent, &root);
    ASSERT_EQ(h.m_left, &g);
    ASSERT_EQ(h.m_right, nullptr);
    ASSERT_EQ(h.m_is_black, true);

    ASSERT_EQ(g.m_parent, &h);
    ASSERT_EQ(g.m_left, nullptr);
    ASSERT_EQ(g.m_right, nullptr);
    ASSERT_EQ(g.m_is_black, false);

    g.m_left   = &f;
    f.m_parent = &g;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &f);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &g);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(g.m_parent, &root);
    ASSERT_EQ(g.m_left, &f);
    ASSERT_EQ(g.m_right, &h);
    ASSERT_EQ(g.m_is_black, true);

    ASSERT_EQ(f.m_parent, &g);
    ASSERT_EQ(f.m_left, nullptr);
    ASSERT_EQ(f.m_right, nullptr);
    ASSERT_EQ(f.m_is_black, false);

    ASSERT_EQ(h.m_parent, &g);
    ASSERT_EQ(h.m_left, nullptr);
    ASSERT_EQ(h.m_right, nullptr);
    ASSERT_EQ(h.m_is_black, false);

    f.m_left   = &e;
    e.m_parent = &f;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &e);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &g);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(g.m_parent, &root);
    ASSERT_EQ(g.m_left, &f);
    ASSERT_EQ(g.m_right, &h);
    ASSERT_EQ(g.m_is_black, true);

    ASSERT_EQ(f.m_parent, &g);
    ASSERT_EQ(f.m_left, &e);
    ASSERT_EQ(f.m_right, nullptr);
    ASSERT_EQ(f.m_is_black, true);

    ASSERT_EQ(e.m_parent, &f);
    ASSERT_EQ(e.m_left, nullptr);
    ASSERT_EQ(e.m_right, nullptr);
    ASSERT_EQ(e.m_is_black, false);

    ASSERT_EQ(h.m_parent, &g);
    ASSERT_EQ(h.m_left, nullptr);
    ASSERT_EQ(h.m_right, nullptr);
    ASSERT_EQ(h.m_is_black, true);

    e.m_left   = &d;
    d.m_parent = &e;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &d);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &g);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(g.m_parent, &root);
    ASSERT_EQ(g.m_left, &e);
    ASSERT_EQ(g.m_right, &h);
    ASSERT_EQ(g.m_is_black, true);

    ASSERT_EQ(e.m_parent, &g);
    ASSERT_EQ(e.m_left, &d);
    ASSERT_EQ(e.m_right, &f);
    ASSERT_EQ(e.m_is_black, true);

    ASSERT_EQ(d.m_parent, &e);
    ASSERT_EQ(d.m_left, nullptr);
    ASSERT_EQ(d.m_right, nullptr);
    ASSERT_EQ(d.m_is_black, false);

    ASSERT_EQ(f.m_parent, &e);
    ASSERT_EQ(f.m_left, nullptr);
    ASSERT_EQ(f.m_right, nullptr);
    ASSERT_EQ(f.m_is_black, false);

    ASSERT_EQ(h.m_parent, &g);
    ASSERT_EQ(h.m_left, nullptr);
    ASSERT_EQ(h.m_right, nullptr);
    ASSERT_EQ(h.m_is_black, true);

    d.m_left   = &c;
    c.m_parent = &d;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &c);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &g);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(g.m_parent, &root);
    ASSERT_EQ(g.m_left, &e);
    ASSERT_EQ(g.m_right, &h);
    ASSERT_EQ(g.m_is_black, true);

    ASSERT_EQ(e.m_parent, &g);
    ASSERT_EQ(e.m_left, &d);
    ASSERT_EQ(e.m_right, &f);
    ASSERT_EQ(e.m_is_black, false);

    ASSERT_EQ(d.m_parent, &e);
    ASSERT_EQ(d.m_left, &c);
    ASSERT_EQ(d.m_right, nullptr);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(c.m_parent, &d);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, false);

    ASSERT_EQ(f.m_parent, &e);
    ASSERT_EQ(f.m_left, nullptr);
    ASSERT_EQ(f.m_right, nullptr);
    ASSERT_EQ(f.m_is_black, true);

    ASSERT_EQ(h.m_parent, &g);
    ASSERT_EQ(h.m_left, nullptr);
    ASSERT_EQ(h.m_right, nullptr);
    ASSERT_EQ(h.m_is_black, true);

    c.m_left   = &b;
    b.m_parent = &c;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &b);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &g);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(g.m_parent, &root);
    ASSERT_EQ(g.m_left, &e);
    ASSERT_EQ(g.m_right, &h);
    ASSERT_EQ(g.m_is_black, true);

    ASSERT_EQ(e.m_parent, &g);
    ASSERT_EQ(e.m_left, &c);
    ASSERT_EQ(e.m_right, &f);
    ASSERT_EQ(e.m_is_black, false);

    ASSERT_EQ(c.m_parent, &e);
    ASSERT_EQ(c.m_left, &b);
    ASSERT_EQ(c.m_right, &d);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(b.m_parent, &c);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, false);

    ASSERT_EQ(d.m_parent, &c);
    ASSERT_EQ(d.m_left, nullptr);
    ASSERT_EQ(d.m_right, nullptr);
    ASSERT_EQ(d.m_is_black, false);

    ASSERT_EQ(f.m_parent, &e);
    ASSERT_EQ(f.m_left, nullptr);
    ASSERT_EQ(f.m_right, nullptr);
    ASSERT_EQ(f.m_is_black, true);

    ASSERT_EQ(h.m_parent, &g);
    ASSERT_EQ(h.m_left, nullptr);
    ASSERT_EQ(h.m_right, nullptr);
    ASSERT_EQ(h.m_is_black, true);

    b.m_left   = &a;
    a.m_parent = &b;

    ::portable_stl::tree_ns::tree_balance_after_insert(root.m_left, &a);

    ASSERT_TRUE(portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &e);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(e.m_parent, &root);
    ASSERT_EQ(e.m_left, &c);
    ASSERT_EQ(e.m_right, &g);
    ASSERT_EQ(e.m_is_black, true);

    ASSERT_EQ(c.m_parent, &e);
    ASSERT_EQ(c.m_left, &b);
    ASSERT_EQ(c.m_right, &d);
    ASSERT_EQ(c.m_is_black, false);

    ASSERT_EQ(b.m_parent, &c);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(d.m_parent, &c);
    ASSERT_EQ(d.m_left, nullptr);
    ASSERT_EQ(d.m_right, nullptr);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(g.m_parent, &e);
    ASSERT_EQ(g.m_left, &f);
    ASSERT_EQ(g.m_right, &h);
    ASSERT_EQ(g.m_is_black, false);

    ASSERT_EQ(f.m_parent, &g);
    ASSERT_EQ(f.m_left, nullptr);
    ASSERT_EQ(f.m_right, nullptr);
    ASSERT_EQ(f.m_is_black, true);

    ASSERT_EQ(h.m_parent, &g);
    ASSERT_EQ(h.m_left, nullptr);
    ASSERT_EQ(h.m_right, nullptr);
    ASSERT_EQ(h.m_is_black, true);
  }
}

TEST(tree, tree_remove) {
  static_cast<void>(test_info_);

  {
    // Left
    // Case 1 -> Case 2 -> x is red turned to black
    test_tree_helper::Node root;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;
    test_tree_helper::Node e;
    test_tree_helper::Node y;

    root.m_left = &b;

    b.m_parent   = &root;
    b.m_left     = &y;
    b.m_right    = &d;
    b.m_is_black = true;

    y.m_parent   = &b;
    y.m_left     = nullptr;
    y.m_right    = nullptr;
    y.m_is_black = true;

    d.m_parent   = &b;
    d.m_left     = &c;
    d.m_right    = &e;
    d.m_is_black = false;

    c.m_parent   = &d;
    c.m_left     = nullptr;
    c.m_right    = nullptr;
    c.m_is_black = true;

    e.m_parent   = &d;
    e.m_left     = nullptr;
    e.m_right    = nullptr;
    e.m_is_black = true;

    ::portable_stl::tree_ns::tree_remove(root.m_left, &y);
    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &d);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(d.m_parent, &root);
    ASSERT_EQ(d.m_left, &b);
    ASSERT_EQ(d.m_right, &e);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(b.m_parent, &d);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, false);

    ASSERT_EQ(e.m_parent, &d);
    ASSERT_EQ(e.m_left, nullptr);
    ASSERT_EQ(e.m_right, nullptr);
    ASSERT_EQ(e.m_is_black, true);
  }
  {
    // Right
    // Case 1 -> Case 2 -> x is red turned to black
    test_tree_helper::Node root;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;
    test_tree_helper::Node e;
    test_tree_helper::Node y;

    root.m_left = &b;

    b.m_parent   = &root;
    b.m_right    = &y;
    b.m_left     = &d;
    b.m_is_black = true;

    y.m_parent   = &b;
    y.m_right    = nullptr;
    y.m_left     = nullptr;
    y.m_is_black = true;

    d.m_parent   = &b;
    d.m_right    = &c;
    d.m_left     = &e;
    d.m_is_black = false;

    c.m_parent   = &d;
    c.m_right    = nullptr;
    c.m_left     = nullptr;
    c.m_is_black = true;

    e.m_parent   = &d;
    e.m_right    = nullptr;
    e.m_left     = nullptr;
    e.m_is_black = true;

    ::portable_stl::tree_ns::tree_remove(root.m_left, &y);
    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &d);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(d.m_parent, &root);
    ASSERT_EQ(d.m_right, &b);
    ASSERT_EQ(d.m_left, &e);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(b.m_parent, &d);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_left, &c);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_is_black, false);

    ASSERT_EQ(e.m_parent, &d);
    ASSERT_EQ(e.m_right, nullptr);
    ASSERT_EQ(e.m_left, nullptr);
    ASSERT_EQ(e.m_is_black, true);
  }
  {
    // Left
    // Case 1 -> Case 3 -> Case 4
    test_tree_helper::Node root;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;
    test_tree_helper::Node e;
    test_tree_helper::Node f;
    test_tree_helper::Node y;

    root.m_left = &b;

    b.m_parent   = &root;
    b.m_left     = &y;
    b.m_right    = &d;
    b.m_is_black = true;

    y.m_parent   = &b;
    y.m_left     = nullptr;
    y.m_right    = nullptr;
    y.m_is_black = true;

    d.m_parent   = &b;
    d.m_left     = &c;
    d.m_right    = &e;
    d.m_is_black = false;

    c.m_parent   = &d;
    c.m_left     = &f;
    c.m_right    = nullptr;
    c.m_is_black = true;

    e.m_parent   = &d;
    e.m_left     = nullptr;
    e.m_right    = nullptr;
    e.m_is_black = true;

    f.m_parent   = &c;
    f.m_left     = nullptr;
    f.m_right    = nullptr;
    f.m_is_black = false;

    ::portable_stl::tree_ns::tree_remove(root.m_left, &y);
    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &d);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(d.m_parent, &root);
    ASSERT_EQ(d.m_left, &f);
    ASSERT_EQ(d.m_right, &e);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(f.m_parent, &d);
    ASSERT_EQ(f.m_left, &b);
    ASSERT_EQ(f.m_right, &c);
    ASSERT_EQ(f.m_is_black, false);

    ASSERT_EQ(b.m_parent, &f);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(c.m_parent, &f);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(e.m_parent, &d);
    ASSERT_EQ(e.m_left, nullptr);
    ASSERT_EQ(e.m_right, nullptr);
    ASSERT_EQ(e.m_is_black, true);
  }
  {
    // Right
    // Case 1 -> Case 3 -> Case 4
    test_tree_helper::Node root;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;
    test_tree_helper::Node e;
    test_tree_helper::Node f;
    test_tree_helper::Node y;

    root.m_left = &b;

    b.m_parent   = &root;
    b.m_right    = &y;
    b.m_left     = &d;
    b.m_is_black = true;

    y.m_parent   = &b;
    y.m_right    = nullptr;
    y.m_left     = nullptr;
    y.m_is_black = true;

    d.m_parent   = &b;
    d.m_right    = &c;
    d.m_left     = &e;
    d.m_is_black = false;

    c.m_parent   = &d;
    c.m_right    = &f;
    c.m_left     = nullptr;
    c.m_is_black = true;

    e.m_parent   = &d;
    e.m_right    = nullptr;
    e.m_left     = nullptr;
    e.m_is_black = true;

    f.m_parent   = &c;
    f.m_right    = nullptr;
    f.m_left     = nullptr;
    f.m_is_black = false;

    ::portable_stl::tree_ns::tree_remove(root.m_left, &y);
    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &d);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(d.m_parent, &root);
    ASSERT_EQ(d.m_right, &f);
    ASSERT_EQ(d.m_left, &e);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(f.m_parent, &d);
    ASSERT_EQ(f.m_right, &b);
    ASSERT_EQ(f.m_left, &c);
    ASSERT_EQ(f.m_is_black, false);

    ASSERT_EQ(b.m_parent, &f);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(c.m_parent, &f);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(e.m_parent, &d);
    ASSERT_EQ(e.m_right, nullptr);
    ASSERT_EQ(e.m_left, nullptr);
    ASSERT_EQ(e.m_is_black, true);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;

    root.m_left = &b;

    b.m_parent   = &root;
    b.m_left     = &a;
    b.m_right    = &c;
    b.m_is_black = true;

    a.m_parent   = &b;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = true;

    c.m_parent   = &b;
    c.m_left     = nullptr;
    c.m_right    = nullptr;
    c.m_is_black = true;

    ::portable_stl::tree_ns::tree_remove(root.m_left, &a);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, false);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &b);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &c);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &c);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, nullptr);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;

    root.m_left = &b;

    b.m_parent   = &root;
    b.m_left     = &a;
    b.m_right    = &c;
    b.m_is_black = true;

    a.m_parent   = &b;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = false;

    c.m_parent   = &b;
    c.m_left     = nullptr;
    c.m_right    = nullptr;
    c.m_is_black = false;

    ::portable_stl::tree_ns::tree_remove(root.m_left, &a);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, false);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &b);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &c);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &c);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, nullptr);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;

    root.m_left = &b;

    b.m_parent   = &root;
    b.m_left     = &a;
    b.m_right    = &c;
    b.m_is_black = true;

    a.m_parent   = &b;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = true;

    c.m_parent   = &b;
    c.m_left     = nullptr;
    c.m_right    = nullptr;
    c.m_is_black = true;

    ::portable_stl::tree_ns::tree_remove(root.m_left, &a);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, false);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &c);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &b);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, nullptr);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;

    root.m_left = &b;

    b.m_parent   = &root;
    b.m_left     = &a;
    b.m_right    = &c;
    b.m_is_black = true;

    a.m_parent   = &b;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = false;

    c.m_parent   = &b;
    c.m_left     = nullptr;
    c.m_right    = nullptr;
    c.m_is_black = false;

    ::portable_stl::tree_ns::tree_remove(root.m_left, &a);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, false);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &c);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &b);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, nullptr);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;

    root.m_left = &b;

    b.m_parent   = &root;
    b.m_left     = &a;
    b.m_right    = &c;
    b.m_is_black = true;

    a.m_parent   = &b;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = true;

    c.m_parent   = &b;
    c.m_left     = nullptr;
    c.m_right    = nullptr;
    c.m_is_black = true;

    ::portable_stl::tree_ns::tree_remove(root.m_left, &b);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &c);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(a.m_parent, &c);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, &a);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &a);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &c);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &c);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, nullptr);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;

    root.m_left = &b;

    b.m_parent   = &root;
    b.m_left     = &a;
    b.m_right    = &c;
    b.m_is_black = true;

    a.m_parent   = &b;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = false;

    c.m_parent   = &b;
    c.m_left     = nullptr;
    c.m_right    = nullptr;
    c.m_is_black = false;

    ::portable_stl::tree_ns::tree_remove(root.m_left, &b);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &c);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(a.m_parent, &c);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, &a);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &a);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &c);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &c);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, nullptr);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;

    root.m_left = &b;

    b.m_parent   = &root;
    b.m_left     = &a;
    b.m_right    = &c;
    b.m_is_black = true;

    a.m_parent   = &b;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = true;

    c.m_parent   = &b;
    c.m_left     = nullptr;
    c.m_right    = nullptr;
    c.m_is_black = true;

    ::portable_stl::tree_ns::tree_remove(root.m_left, &b);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &c);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(a.m_parent, &c);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, &a);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &c);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &a);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(a.m_parent, &root);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &a);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, nullptr);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;

    root.m_left = &b;

    b.m_parent   = &root;
    b.m_left     = &a;
    b.m_right    = &c;
    b.m_is_black = true;

    a.m_parent   = &b;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = false;

    c.m_parent   = &b;
    c.m_left     = nullptr;
    c.m_right    = nullptr;
    c.m_is_black = false;

    ::portable_stl::tree_ns::tree_remove(root.m_left, &b);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &c);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(a.m_parent, &c);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, &a);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &c);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &a);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(a.m_parent, &root);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &a);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, nullptr);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;

    root.m_left = &b;

    b.m_parent   = &root;
    b.m_left     = &a;
    b.m_right    = &c;
    b.m_is_black = true;

    a.m_parent   = &b;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = true;

    c.m_parent   = &b;
    c.m_left     = nullptr;
    c.m_right    = nullptr;
    c.m_is_black = true;

    ::portable_stl::tree_ns::tree_remove(root.m_left, &c);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &b);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &a);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(a.m_parent, &root);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &a);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, nullptr);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;

    root.m_left = &b;

    b.m_parent   = &root;
    b.m_left     = &a;
    b.m_right    = &c;
    b.m_is_black = true;

    a.m_parent   = &b;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = false;

    c.m_parent   = &b;
    c.m_left     = nullptr;
    c.m_right    = nullptr;
    c.m_is_black = false;

    ::portable_stl::tree_ns::tree_remove(root.m_left, &c);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &b);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &a);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(a.m_parent, &root);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &a);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, nullptr);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;

    root.m_left = &b;

    b.m_parent   = &root;
    b.m_left     = &a;
    b.m_right    = &c;
    b.m_is_black = true;

    a.m_parent   = &b;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = true;

    c.m_parent   = &b;
    c.m_left     = nullptr;
    c.m_right    = nullptr;
    c.m_is_black = true;

    ::portable_stl::tree_ns::tree_remove(root.m_left, &c);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &a);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &b);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, nullptr);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;

    root.m_left = &b;

    b.m_parent   = &root;
    b.m_left     = &a;
    b.m_right    = &c;
    b.m_is_black = true;

    a.m_parent   = &b;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = false;

    c.m_parent   = &b;
    c.m_left     = nullptr;
    c.m_right    = nullptr;
    c.m_is_black = false;

    ::portable_stl::tree_ns::tree_remove(root.m_left, &c);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &a);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &b);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, nullptr);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;
    test_tree_helper::Node e;
    test_tree_helper::Node f;
    test_tree_helper::Node g;
    test_tree_helper::Node h;

    root.m_left = &e;

    e.m_parent   = &root;
    e.m_left     = &c;
    e.m_right    = &g;
    e.m_is_black = true;

    c.m_parent   = &e;
    c.m_left     = &b;
    c.m_right    = &d;
    c.m_is_black = false;

    g.m_parent   = &e;
    g.m_left     = &f;
    g.m_right    = &h;
    g.m_is_black = false;

    b.m_parent   = &c;
    b.m_left     = &a;
    b.m_right    = nullptr;
    b.m_is_black = true;

    d.m_parent   = &c;
    d.m_left     = nullptr;
    d.m_right    = nullptr;
    d.m_is_black = true;

    f.m_parent   = &g;
    f.m_left     = nullptr;
    f.m_right    = nullptr;
    f.m_is_black = true;

    h.m_parent   = &g;
    h.m_left     = nullptr;
    h.m_right    = nullptr;
    h.m_is_black = true;

    a.m_parent   = &b;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = false;

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ::portable_stl::tree_ns::tree_remove(root.m_left, &h);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &e);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(e.m_parent, &root);
    ASSERT_EQ(e.m_left, &c);
    ASSERT_EQ(e.m_right, &g);
    ASSERT_EQ(e.m_is_black, true);

    ASSERT_EQ(c.m_parent, &e);
    ASSERT_EQ(c.m_left, &b);
    ASSERT_EQ(c.m_right, &d);
    ASSERT_EQ(c.m_is_black, false);

    ASSERT_EQ(g.m_parent, &e);
    ASSERT_EQ(g.m_left, &f);
    ASSERT_EQ(g.m_right, nullptr);
    ASSERT_EQ(g.m_is_black, true);

    ASSERT_EQ(b.m_parent, &c);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(d.m_parent, &c);
    ASSERT_EQ(d.m_left, nullptr);
    ASSERT_EQ(d.m_right, nullptr);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(f.m_parent, &g);
    ASSERT_EQ(f.m_left, nullptr);
    ASSERT_EQ(f.m_right, nullptr);
    ASSERT_EQ(f.m_is_black, false);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &g);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &e);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(e.m_parent, &root);
    ASSERT_EQ(e.m_left, &c);
    ASSERT_EQ(e.m_right, &f);
    ASSERT_EQ(e.m_is_black, true);

    ASSERT_EQ(c.m_parent, &e);
    ASSERT_EQ(c.m_left, &b);
    ASSERT_EQ(c.m_right, &d);
    ASSERT_EQ(c.m_is_black, false);

    ASSERT_EQ(b.m_parent, &c);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(d.m_parent, &c);
    ASSERT_EQ(d.m_left, nullptr);
    ASSERT_EQ(d.m_right, nullptr);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(f.m_parent, &e);
    ASSERT_EQ(f.m_left, nullptr);
    ASSERT_EQ(f.m_right, nullptr);
    ASSERT_EQ(f.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &f);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &c);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, &b);
    ASSERT_EQ(c.m_right, &e);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(b.m_parent, &c);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(e.m_parent, &c);
    ASSERT_EQ(e.m_left, &d);
    ASSERT_EQ(e.m_right, nullptr);
    ASSERT_EQ(e.m_is_black, true);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(d.m_parent, &e);
    ASSERT_EQ(d.m_left, nullptr);
    ASSERT_EQ(d.m_right, nullptr);
    ASSERT_EQ(d.m_is_black, false);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &e);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &c);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(c.m_parent, &root);
    ASSERT_EQ(c.m_left, &b);
    ASSERT_EQ(c.m_right, &d);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(b.m_parent, &c);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ASSERT_EQ(d.m_parent, &c);
    ASSERT_EQ(d.m_left, nullptr);
    ASSERT_EQ(d.m_right, nullptr);
    ASSERT_EQ(d.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &d);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, true);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &c);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &b);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(b.m_parent, &root);
    ASSERT_EQ(b.m_left, &a);
    ASSERT_EQ(b.m_right, nullptr);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(a.m_parent, &b);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, false);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &b);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &a);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(a.m_parent, &root);
    ASSERT_EQ(a.m_left, nullptr);
    ASSERT_EQ(a.m_right, nullptr);
    ASSERT_EQ(a.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &a);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, nullptr);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);
  }
  {
    test_tree_helper::Node root;
    test_tree_helper::Node a;
    test_tree_helper::Node b;
    test_tree_helper::Node c;
    test_tree_helper::Node d;
    test_tree_helper::Node e;
    test_tree_helper::Node f;
    test_tree_helper::Node g;
    test_tree_helper::Node h;

    root.m_left = &d;

    d.m_parent   = &root;
    d.m_left     = &b;
    d.m_right    = &f;
    d.m_is_black = true;

    b.m_parent   = &d;
    b.m_left     = &a;
    b.m_right    = &c;
    b.m_is_black = false;

    f.m_parent   = &d;
    f.m_left     = &e;
    f.m_right    = &g;
    f.m_is_black = false;

    a.m_parent   = &b;
    a.m_left     = nullptr;
    a.m_right    = nullptr;
    a.m_is_black = true;

    c.m_parent   = &b;
    c.m_left     = nullptr;
    c.m_right    = nullptr;
    c.m_is_black = true;

    e.m_parent   = &f;
    e.m_left     = nullptr;
    e.m_right    = nullptr;
    e.m_is_black = true;

    g.m_parent   = &f;
    g.m_left     = nullptr;
    g.m_right    = &h;
    g.m_is_black = true;

    h.m_parent   = &g;
    h.m_left     = nullptr;
    h.m_right    = nullptr;
    h.m_is_black = false;

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ::portable_stl::tree_ns::tree_remove(root.m_left, &a);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &d);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(d.m_parent, &root);
    ASSERT_EQ(d.m_left, &b);
    ASSERT_EQ(d.m_right, &f);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(b.m_parent, &d);
    ASSERT_EQ(b.m_left, nullptr);
    ASSERT_EQ(b.m_right, &c);
    ASSERT_EQ(b.m_is_black, true);

    ASSERT_EQ(f.m_parent, &d);
    ASSERT_EQ(f.m_left, &e);
    ASSERT_EQ(f.m_right, &g);
    ASSERT_EQ(f.m_is_black, false);

    ASSERT_EQ(c.m_parent, &b);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, false);

    ASSERT_EQ(e.m_parent, &f);
    ASSERT_EQ(e.m_left, nullptr);
    ASSERT_EQ(e.m_right, nullptr);
    ASSERT_EQ(e.m_is_black, true);

    ASSERT_EQ(g.m_parent, &f);
    ASSERT_EQ(g.m_left, nullptr);
    ASSERT_EQ(g.m_right, &h);
    ASSERT_EQ(g.m_is_black, true);

    ASSERT_EQ(h.m_parent, &g);
    ASSERT_EQ(h.m_left, nullptr);
    ASSERT_EQ(h.m_right, nullptr);
    ASSERT_EQ(h.m_is_black, false);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &b);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &d);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(d.m_parent, &root);
    ASSERT_EQ(d.m_left, &c);
    ASSERT_EQ(d.m_right, &f);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(c.m_parent, &d);
    ASSERT_EQ(c.m_left, nullptr);
    ASSERT_EQ(c.m_right, nullptr);
    ASSERT_EQ(c.m_is_black, true);

    ASSERT_EQ(f.m_parent, &d);
    ASSERT_EQ(f.m_left, &e);
    ASSERT_EQ(f.m_right, &g);
    ASSERT_EQ(f.m_is_black, false);

    ASSERT_EQ(e.m_parent, &f);
    ASSERT_EQ(e.m_left, nullptr);
    ASSERT_EQ(e.m_right, nullptr);
    ASSERT_EQ(e.m_is_black, true);

    ASSERT_EQ(g.m_parent, &f);
    ASSERT_EQ(g.m_left, nullptr);
    ASSERT_EQ(g.m_right, &h);
    ASSERT_EQ(g.m_is_black, true);

    ASSERT_EQ(h.m_parent, &g);
    ASSERT_EQ(h.m_left, nullptr);
    ASSERT_EQ(h.m_right, nullptr);
    ASSERT_EQ(h.m_is_black, false);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &c);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &f);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(f.m_parent, &root);
    ASSERT_EQ(f.m_left, &d);
    ASSERT_EQ(f.m_right, &g);
    ASSERT_EQ(f.m_is_black, true);

    ASSERT_EQ(d.m_parent, &f);
    ASSERT_EQ(d.m_left, nullptr);
    ASSERT_EQ(d.m_right, &e);
    ASSERT_EQ(d.m_is_black, true);

    ASSERT_EQ(g.m_parent, &f);
    ASSERT_EQ(g.m_left, nullptr);
    ASSERT_EQ(g.m_right, &h);
    ASSERT_EQ(g.m_is_black, true);

    ASSERT_EQ(e.m_parent, &d);
    ASSERT_EQ(e.m_left, nullptr);
    ASSERT_EQ(e.m_right, nullptr);
    ASSERT_EQ(e.m_is_black, false);

    ASSERT_EQ(h.m_parent, &g);
    ASSERT_EQ(h.m_left, nullptr);
    ASSERT_EQ(h.m_right, nullptr);
    ASSERT_EQ(h.m_is_black, false);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &d);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &f);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(f.m_parent, &root);
    ASSERT_EQ(f.m_left, &e);
    ASSERT_EQ(f.m_right, &g);
    ASSERT_EQ(f.m_is_black, true);

    ASSERT_EQ(e.m_parent, &f);
    ASSERT_EQ(e.m_left, nullptr);
    ASSERT_EQ(e.m_right, nullptr);
    ASSERT_EQ(e.m_is_black, true);

    ASSERT_EQ(g.m_parent, &f);
    ASSERT_EQ(g.m_left, nullptr);
    ASSERT_EQ(g.m_right, &h);
    ASSERT_EQ(g.m_is_black, true);

    ASSERT_EQ(h.m_parent, &g);
    ASSERT_EQ(h.m_left, nullptr);
    ASSERT_EQ(h.m_right, nullptr);
    ASSERT_EQ(h.m_is_black, false);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &e);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &g);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(g.m_parent, &root);
    ASSERT_EQ(g.m_left, &f);
    ASSERT_EQ(g.m_right, &h);
    ASSERT_EQ(g.m_is_black, true);

    ASSERT_EQ(f.m_parent, &g);
    ASSERT_EQ(f.m_left, nullptr);
    ASSERT_EQ(f.m_right, nullptr);
    ASSERT_EQ(f.m_is_black, true);

    ASSERT_EQ(h.m_parent, &g);
    ASSERT_EQ(h.m_left, nullptr);
    ASSERT_EQ(h.m_right, nullptr);
    ASSERT_EQ(h.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &f);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &g);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(g.m_parent, &root);
    ASSERT_EQ(g.m_left, nullptr);
    ASSERT_EQ(g.m_right, &h);
    ASSERT_EQ(g.m_is_black, true);

    ASSERT_EQ(h.m_parent, &g);
    ASSERT_EQ(h.m_left, nullptr);
    ASSERT_EQ(h.m_right, nullptr);
    ASSERT_EQ(h.m_is_black, false);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &g);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, &h);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);

    ASSERT_EQ(h.m_parent, &root);
    ASSERT_EQ(h.m_left, nullptr);
    ASSERT_EQ(h.m_right, nullptr);
    ASSERT_EQ(h.m_is_black, true);

    ::portable_stl::tree_ns::tree_remove(root.m_left, &h);

    ASSERT_TRUE(::portable_stl::tree_ns::tree_invariant(root.m_left));

    ASSERT_EQ(root.m_parent, nullptr);
    ASSERT_EQ(root.m_left, nullptr);
    ASSERT_EQ(root.m_right, nullptr);
    ASSERT_EQ(root.m_is_black, false);
  }
}
