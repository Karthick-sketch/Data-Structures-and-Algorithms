package binarytree.binarysearchtree;

import binarytree.BinaryTreeNode;

import java.util.ArrayList;
import java.util.List;

public class BinarySearchTree {
  protected BinaryTreeNode root;

  public BinarySearchTree(int[] values) {
    insert(values);
  }

  public void insert(int[] values) {
    for (int value : values) {
      insert(value);
    }
  }

  public void insert(int value) {
    if (root == null) {
      root = new BinaryTreeNode(value);
    } else {
      BinaryTreeNode node = root;
      while (true) {
        if (value < node.getValue()) {
          if (node.getLeft() == null) {
            node.setLeft(new BinaryTreeNode(value));
            break;
          }
          node = node.getLeft();
        } else if (value > node.getValue()) {
          if (node.getRight() == null) {
            node.setRight(new BinaryTreeNode(value));
            break;
          }
          node = node.getRight();
        } else {
          break;
        }
      }
    }
  }

  public boolean search(int value) {
    BinaryTreeNode node = root;
    while (node != null) {
      if (value == node.getValue()) {
        return true;
      } else if (value < node.getValue()) {
        node = node.getLeft();
      } else {
        node = node.getRight();
      }
    }
    return false;
  }

  public List<Integer> get() {
    List<Integer> list = new ArrayList<>();
    if (root != null) {
      inorder(root, list);
    }
    return list;
  }

  private void inorder(BinaryTreeNode node, List<Integer> list) {
    if (node.getLeft() != null) {
      inorder(node.getLeft(), list);
    }
    list.add(node.getValue());
    if (node.getRight() != null) {
      inorder(node.getRight(), list);
    }
  }
}
