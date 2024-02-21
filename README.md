# LinkedList Based Binary Tree

This repository contains a C++ implementation of a linkedlist binary tree, providing efficient operations for managing tree nodes and traversing the tree.

## Overview

- **Node Class**: Represents a node in the binary tree.
  - **Attributes**:
    - `info`: Stores the value of the node.
    - `left`: Pointer to the left child node.
    - `right`: Pointer to the right child node.
- **LinkBinaryTree Class**: Represents the linked binary tree structure.
  - **Attributes**:
    - `root`: Pointer to the root node.
  - **Methods**:
    - `setRoot`: Sets the root node.
    - `setLeftChild`: Sets the left child of a node.
    - `setRightChild`: Sets the right child of a node.
    - Traversal methods: `preOrder`, `postOrder`, `inOrder`.
    - `getParent`: Returns the parent node of a given node.
    - `remove`: Removes a node from the tree.
    - `findBalanceFactor`: Calculates the balance factor of a given node.
    - `LowestCommonAncestor`: Finds the lowest common ancestor of two nodes.
    - `getRoot`: Returns the root node.
- **Example Usage**:
  ```cpp
  int main() {
      LinkBinaryTree<int> t1(8);
      t1.setLeftChild(8, 5);
      t1.setRightChild(8, 6);
      t1.setRightChild(15, 9);
      t1.preOrder();
      return 0;
  }
