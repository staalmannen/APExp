// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tree_algo.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TREE_ALGO_H
#define PSTL_TREE_ALGO_H

namespace portable_stl {

namespace tree_ns {
  /**
   * @brief t_node_ptr algorithms
   * The algorithms taking t_node_ptr are red black tree algorithms. Those algorithms taking a parameter named 'root'
   * should assume that 'root' points to a proper red black tree (unless otherwise specified).
   *
   * Each algorithm herein assumes that root->parent points to a non-null structure which has a member 'left' which
   * points back to 'root'. No other member is read or written to at root->parent.
   *
   * root->parent will be referred to below (in comments only) as end_node. end_node->left is an externably accessible
   * lvalue for 'root', and can be changed by node insertion and removal (without explicit reference to end_node).
   *
   * All nodes (with the exception of end_node), even the node referred to as 'root', have a non-null 'parent' field.
   */

  /**
   * @brief
   * Precondition: node != nullptr.
   *
   * @tparam t_node_ptr
   * @param node Given node.
   * @return true if node is a left child of its parent,
   *         false, otherwise.
   */
  template<class t_node_ptr> inline bool tree_is_left_child(t_node_ptr node) noexcept {
    return node == node->m_parent->m_left;
  }

  /**
   * @brief Determines if the subtree rooted at node is a proper red black subtree.
   *
   * @tparam t_node_ptr
   * @param node Given node.
   * @return the black height(null counts as 1) If node is a proper subtree,
   *         0 if node is an improper subtree.
   */
  template<class t_node_ptr> unsigned tree_sub_invariant(t_node_ptr node) {
    if (node == nullptr) {
      return 1;
    }

    // parent consistency checked by caller
    // check node->m_left consistency
    if ((node->m_left != nullptr) && (node->m_left->m_parent != node)) {
      return 0;
    }

    // check node->m_right consistency
    if ((node->m_right != nullptr) && (node->m_right->m_parent != node)) {
      return 0;
    }

    // check node->m_left != node->m_right unless both are nullptr
    if ((node->m_left == node->m_right) && (node->m_left != nullptr)) {
      return 0;
    }

    // If this is red, neither child can be red
    if (!node->m_is_black) {
      if (node->m_left && !node->m_left->m_is_black) {
        return 0;
      }
      if (node->m_right && !node->m_right->m_is_black) {
        return 0;
      }
    }

    unsigned const height{tree_sub_invariant(node->m_left)};
    if (0 == height) {
      return 0; // invalid left subtree
    }

    if (tree_sub_invariant(node->m_right) != height) {
      return 0; // invalid or different height right subtree
    }

    return height + node->m_is_black; // return black height of this node
  }

  /**
   * @brief Determines if the red black tree rooted at 'root' is a proper red black tree.
   * root_node == nullptr is a proper tree.
   *
   * @tparam t_node_ptr
   * @param root_node Given node.
   * @return true is root_node is a proper red black tree.
   *         false, otherwise.
   */
  template<class t_node_ptr> bool tree_invariant(t_node_ptr root_node) {
    if (nullptr == root_node) {
      return true;
    }

    // check node->m_parent consistency
    if (nullptr == root_node->m_parent) {
      return false;
    }

    if (!tree_is_left_child(root_node)) {
      return false;
    }

    // root must be black
    if (!root_node->m_is_black) {
      return false;
    }

    // do normal node checks
    return 0 != tree_sub_invariant(root_node);
  }

  /**
   * @brief Returns pointer to the left-most node under node.
   *
   * @tparam t_node_ptr
   * @param node Given node.
   * @return pointer to the left-most node under node.
   */
  template<class t_node_ptr> inline t_node_ptr tree_min(t_node_ptr node) noexcept {
    // static_assert(node != nullptr, "Root node shouldn't be null");
    while (nullptr != node->m_left) {
      node = node->m_left;
    }
    return node;
  }

  /**
   * @brief Returns pointer to the right-most node under node.
   *
   * @tparam t_node_ptr
   * @param node Given node.
   * @return pointer to the right-most node under node.
   */
  template<class t_node_ptr> inline t_node_ptr tree_max(t_node_ptr node) noexcept {
    // static_assert(node != nullptr, "Root node shouldn't be null");
    while (nullptr != node->m_right) {
      node = node->m_right;
    }
    return node;
  }

  /**
   * @brief Returns pointer to the next in-order node after node.
   *
   * @tparam t_node_ptr
   * @param node Given node.
   * @return pointer to the next in-order node after node.
   */
  template<class t_node_ptr> t_node_ptr tree_next(t_node_ptr node) noexcept {
    // static_assert(node != nullptr, "node shouldn't be null");
    if (node->m_right != nullptr) {
      return tree_min(node->m_right);
    }
    while (!tree_is_left_child(node)) {
      node = node->parent_unsafe();
    }
    return node->parent_unsafe();
  }

  template<class t_end_node_ptr, class t_node_ptr> inline t_end_node_ptr tree_next_iter(t_node_ptr node) noexcept {
    // static_assert(node != nullptr, "node shouldn't be null");
    if (node->m_right != nullptr) {
      return static_cast<t_end_node_ptr>(tree_min(node->m_right));
    }
    while (!tree_is_left_child(node)) {
      node = node->parent_unsafe();
    }
    return static_cast<t_end_node_ptr>(node->m_parent);
  }

  /**
   * @brief Return pointer to the previous in-order node before end_node.
   * end_node may be the end node.
   * @tparam t_node_ptr
   * @tparam t_end_node_ptr
   * @param end_node Given node.
   * @return pointer to the previous in-order node before end_node.
   */
  template<class t_node_ptr, class t_end_node_ptr> inline t_node_ptr tree_prev_iter(t_end_node_ptr end_node) noexcept {
    // static_assert(end_node != nullptr, "node shouldn't be null");
    if (end_node->m_left != nullptr) {
      return tree_max(end_node->m_left);
    }
    t_node_ptr node = static_cast<t_node_ptr>(end_node);
    while (tree_is_left_child(node)) {
      node = node->parent_unsafe();
    }
    return node->parent_unsafe();
  }

  /**
   * @brief Returns pointer to a node which has no children.
   *
   * @tparam t_node_ptr
   * @param node Given node.
   * @return pointer to a node which has no children.
   */
  template<class t_node_ptr> t_node_ptr tree_leaf(t_node_ptr node) noexcept {
    // static_assert(node != nullptr, "node shouldn't be null");
    while (true) {
      if (node->m_left != nullptr) {
        node = node->m_left;
        continue;
      }
      if (node->m_right != nullptr) {
        node = node->m_right;
        continue;
      }
      break;
    }
    return node;
  }

  /**
   * @brief Makes node->m_right the subtree root with node as its left child while preserving in-order order.
   *
   * @tparam t_node_ptr
   * @param node
   */
  template<class t_node_ptr> void tree_left_rotate(t_node_ptr node) noexcept {
    // static_assert(node != nullptr, "node shouldn't be null");
    // static_assert(node->m_right != nullptr, "node should have a right child");
    t_node_ptr old_right{node->m_right};
    node->m_right = old_right->m_left;
    if (node->m_right != nullptr) {
      node->m_right->set_parent(node);
    }
    old_right->m_parent = node->m_parent;
    if (tree_is_left_child(node)) {
      node->m_parent->m_left = old_right;
    } else {
      node->parent_unsafe()->m_right = old_right;
    }
    old_right->m_left = node;
    node->set_parent(old_right);
  }

  /**
   * @brief Makes node->m_left the subtree root with node as its right child while preserving in-order order.
   *
   * @tparam t_node_ptr
   * @param node
   */
  template<class t_node_ptr> void tree_right_rotate(t_node_ptr node) noexcept {
    // static_assert(node != nullptr, "node shouldn't be null");
    // static_assert(node->m_left != nullptr, "node should have a left child");
    t_node_ptr old_left{node->m_left};
    node->m_left = old_left->m_right;
    if (node->m_left != nullptr) {
      node->m_left->set_parent(node);
    }
    old_left->m_parent = node->m_parent;
    if (tree_is_left_child(node)) {
      node->m_parent->m_left = old_left;
    } else {
      node->parent_unsafe()->m_right = old_left;
    }
    old_left->m_right = node;
    node->set_parent(old_left);
  }

  /**
   * @brief Rebalances 'root' after attaching node to a leaf.
   * Precondition:  node has no children.
   *                node == 'root' or node ia a direct or indirect child of 'root'.
   *                If node were to be unlinked from 'root' (setting 'root' to
   *                  nullptr if 'root' == node), tree_invariant('root') == true.
   * Postcondition: tree_invariant(end_node->m_left) == true.  end_node->m_left
   *                may be different than the value passed in as 'root'.
   *
   * @tparam t_node_ptr
   * @param root
   * @param node
   */
  template<class t_node_ptr> void tree_balance_after_insert(t_node_ptr root, t_node_ptr node) noexcept {
    // static_assert(root != nullptr, "Root of the tree shouldn't be null");
    // static_assert(node != nullptr, "Can't attach null node to a leaf");
    node->m_is_black = (node == root);
    while ((node != root) && (!node->parent_unsafe()->m_is_black)) {
      // node->m_parent != root because node->m_parent->__is_black == false
      if (tree_is_left_child(node->parent_unsafe())) {
        t_node_ptr up_right = node->parent_unsafe()->parent_unsafe()->m_right;
        if ((up_right != nullptr) && !up_right->m_is_black) {
          node                 = node->parent_unsafe();
          node->m_is_black     = true;
          node                 = node->parent_unsafe();
          node->m_is_black     = (node == root);
          up_right->m_is_black = true;
        } else {
          if (!tree_is_left_child(node)) {
            node = node->parent_unsafe();
            tree_left_rotate(node);
          }
          node             = node->parent_unsafe();
          node->m_is_black = true;
          node             = node->parent_unsafe();
          node->m_is_black = false;
          tree_right_rotate(node);
          break;
        }
      } else {
        t_node_ptr up_left = node->parent_unsafe()->m_parent->m_left;
        if ((up_left != nullptr) && !up_left->m_is_black) {
          node                = node->parent_unsafe();
          node->m_is_black    = true;
          node                = node->parent_unsafe();
          node->m_is_black    = node == root;
          up_left->m_is_black = true;
        } else {
          if (tree_is_left_child(node)) {
            node = node->parent_unsafe();
            tree_right_rotate(node);
          }
          node             = node->parent_unsafe();
          node->m_is_black = true;
          node             = node->parent_unsafe();
          node->m_is_black = false;
          tree_left_rotate(node);
          break;
        }
      }
    }
  }

  /**
   * @brief Unlinks 'z_node' from the tree rooted at 'root', rebalancing as needed.
   * Precondition:  'z_node' == 'root' or == a direct or indirect child of 'root'.
   * Postcondition: __tree_invariant(end_node->m_left) == true && end_node->m_left
   *                nor any of its children refer to 'z_node'.  end_node->m_left
   *                may be different than the value passed in as 'root'.
   *
   * @tparam t_node_ptr
   * @param root
   * @param z_node
   */
  template<class t_node_ptr> void tree_remove(t_node_ptr root, t_node_ptr z_node) noexcept {
    // static_assert(root != nullptr, "Root node should not be null");
    // static_assert(z_node != nullptr, "The node to remove should not be null");
    // static_assert(std::__tree_invariant(root), "The tree invariants should hold");

    // 'z_node' will be removed from the tree. Client still needs to destruct/deallocate it
    // y_node is either 'z_node', or if 'z_node' has two children, tree_next(z_node).
    // y_node will have at most one child.
    // y_node will be the initial hole in the tree (make the hole at a leaf)
    t_node_ptr y_node = ((z_node->m_left == nullptr) || (z_node->m_right == nullptr)) ? z_node : tree_next(z_node);
    // node is y_node's possibly null single child
    t_node_ptr node   = y_node->m_left != nullptr ? y_node->m_left : y_node->m_right;
    // w_node is node's possibly null uncle (will become node's sibling)
    t_node_ptr w_node = nullptr;
    // link node to y_node's parent, and find w_node
    if (node != nullptr) {
      node->m_parent = y_node->m_parent;
    }
    if (tree_is_left_child(y_node)) {
      y_node->m_parent->m_left = node;
      if (y_node != root) {
        w_node = y_node->parent_unsafe()->m_right;
      } else {
        root = node; // w_node == nullptr
      }
    } else {
      y_node->parent_unsafe()->m_right = node;
      // y_node can't be root if it is a right child
      w_node                            = y_node->m_parent->m_left;
    }
    bool removed_black{y_node->m_is_black};
    // If we didn't remove 'z_node', do so now by splicing in y_node for 'z_node',
    //    but copy z_node's color.  This does not impact node or w_node.
    if (y_node != z_node) {
      // z_node->m_left != nulptr but z_node->m_right might == node == nullptr
      y_node->m_parent = z_node->m_parent;
      if (tree_is_left_child(z_node)) {
        y_node->m_parent->m_left = y_node;
      } else {
        y_node->parent_unsafe()->m_right = y_node;
      }
      y_node->m_left = z_node->m_left;
      y_node->m_left->set_parent(y_node);
      y_node->m_right = z_node->m_right;
      if (y_node->m_right != nullptr) {
        y_node->m_right->set_parent(y_node);
      }
      y_node->m_is_black = z_node->m_is_black;
      if (root == z_node) {
        root = y_node;
      }
    }
    // There is no need to rebalance if we removed a red, or if we removed
    //     the last node.
    if (removed_black && (root != nullptr)) {
      // Rebalance:
      // node has an implicit black color (transferred from the removed y_node)
      //    associated with it, no matter what its color is.
      // If node is root (in which case it can't be null), it is supposed
      //    to be black anyway, and if it is doubly black, then the double
      //    can just be ignored.
      // If node is red (in which case it can't be null), then it can absorb
      //    the implicit black just by setting its color to black.
      // Since y_node was black and only had one child (which node points to), node
      //   is either red with no children, else null, otherwise y_node would have
      //   different black heights under left and right pointers.
      // if (node == root || node != nullptr && !node->m_is_black)
      if (node != nullptr) {
        node->m_is_black = true;
      } else {
        //  Else node isn't root, and is "doubly black", even though it may
        //     be null.  w_node can not be null here, else the parent would
        //     see a black height >= 2 on the node side and a black height
        //     of 1 on the w_node side (w_node must be a non-null black or a red
        //     with a non-null black child).
        while (true) {
          if (!tree_is_left_child(w_node)) // if x is left child
          {
            if (!w_node->m_is_black) {
              w_node->m_is_black                   = true;
              w_node->parent_unsafe()->m_is_black = false;
              tree_left_rotate(w_node->parent_unsafe());
              // node is still valid
              // reset root only if necessary
              if (root == w_node->m_left) {
                root = w_node;
              }
              // reset sibling, and it still can't be null
              w_node = w_node->m_left->m_right;
            }
            // w_node->m_is_black is now true, w_node may have null children
            if (((nullptr == w_node->m_left) || w_node->m_left->m_is_black)
                && ((nullptr == w_node->m_right) || w_node->m_right->m_is_black)) {
              w_node->m_is_black = false;
              node               = w_node->parent_unsafe();
              // node can no longer be null
              if ((node == root) || !node->m_is_black) {
                node->m_is_black = true;
                break;
              }
              // reset sibling, and it still can't be null
              w_node = tree_is_left_child(node) ? node->parent_unsafe()->m_right : node->m_parent->m_left;
              // continue;
            } else // w_node has a red child
            {
              if ((nullptr == w_node->m_right) || w_node->m_right->m_is_black) {
                // w_node left child is non-null and red
                w_node->m_left->m_is_black = true;
                w_node->m_is_black         = false;
                tree_right_rotate(w_node);
                // w_node is known not to be root, so root hasn't changed
                // reset sibling, and it still can't be null
                w_node = w_node->parent_unsafe();
              }
              // w_node has a right red child, left child may be null
              w_node->m_is_black                   = w_node->parent_unsafe()->m_is_black;
              w_node->parent_unsafe()->m_is_black = true;
              w_node->m_right->m_is_black          = true;
              tree_left_rotate(w_node->parent_unsafe());
              break;
            }
          } else {
            if (!w_node->m_is_black) {
              w_node->m_is_black                   = true;
              w_node->parent_unsafe()->m_is_black = false;
              tree_right_rotate(w_node->parent_unsafe());
              // node is still valid
              // reset root only if necessary
              if (root == w_node->m_right) {
                root = w_node;
              }
              // reset sibling, and it still can't be null
              w_node = w_node->m_right->m_left;
            }
            // w_node->m_is_black is now true, w_node may have null children
            if (((nullptr == w_node->m_left) || w_node->m_left->m_is_black)
                && ((nullptr == w_node->m_right) || w_node->m_right->m_is_black)) {
              w_node->m_is_black = false;
              node               = w_node->parent_unsafe();
              // node can no longer be null
              if (!node->m_is_black || (node == root)) {
                node->m_is_black = true;
                break;
              }
              // reset sibling, and it still can't be null
              w_node = tree_is_left_child(node) ? node->parent_unsafe()->m_right : node->m_parent->m_left;
              // continue;
            } else // w_node has a red child
            {
              if ((nullptr == w_node->m_left) || w_node->m_left->m_is_black) {
                // w_node right child is non-null and red
                w_node->m_right->m_is_black = true;
                w_node->m_is_black          = false;
                tree_left_rotate(w_node);
                // w_node is known not to be root, so root hasn't changed
                // reset sibling, and it still can't be null
                w_node = w_node->parent_unsafe();
              }
              // w_node has a left red child, right child may be null
              w_node->m_is_black                   = w_node->parent_unsafe()->m_is_black;
              w_node->parent_unsafe()->m_is_black = true;
              w_node->m_left->m_is_black           = true;
              tree_right_rotate(w_node->parent_unsafe());
              break;
            }
          }
        }
      }
    }
  }
} // namespace tree_ns

} // namespace portable_stl

#endif // PSTL_TREE_ALGO_H
