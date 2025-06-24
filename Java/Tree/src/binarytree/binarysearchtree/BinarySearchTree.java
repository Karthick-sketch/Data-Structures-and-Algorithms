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
    BinaryTreeNode node = new BinaryTreeNode(value);
    if (root == null) {
      root = node;
    } else {
      BinaryTreeNode current = root;
      while (true) {
        if (value < current.getValue()) {
          if (current.getLeft() == null) {
            current.setLeft(node);
            break;
          }
          current = current.getLeft();
        } else if (value > current.getValue()) {
          if (current.getRight() == null) {
            current.setRight(node);
            break;
          }
          current = current.getRight();
        } else {
          break;
        }
      }
    }
  }

  public boolean search(int value) {
    BinaryTreeNode current = root;
    while (current != null) {
      if (value == current.getValue()) {
        return true;
      } else if (value < current.getValue()) {
        current = current.getLeft();
      } else {
        current = current.getRight();
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

  private void inorder(BinaryTreeNode current, List<Integer> list) {
    if (current.getLeft() != null) {
      inorder(current.getLeft(), list);
    }
    list.add(current.getValue());
    if (current.getRight() != null) {
      inorder(current.getRight(), list);
    }
  }

  public boolean delete(int value) {
    BinaryTreeNode child = root, parent = root;
    while (child != null) {
      if (value == child.getValue()) {
        if (child.getLeft() != null && child.getRight() != null) {
          BinaryTreeNode current = child.getLeft(), previous = null;
          while (current.getRight() != null) {
            previous = current;
            current = current.getRight();
          }
          child.setValue(current.getValue());
          if (previous == null) {
            child.setLeft(null);
          } else {
            previous.setRight(null);
          }
        } else {
          BinaryTreeNode current = null;
          if (child.getLeft() != null) {
            current = child.getLeft();
          } else if (child.getRight() != null) {
            current = child.getRight();
          }
          if (child == root) {
            root = current;
          } else if (child == parent.getLeft()) {
            parent.setLeft(current);
          } else {
            parent.setRight(current);
          }
        }
        return true;
      } else {
        parent = child;
        child = value < child.getValue() ? child.getLeft() : child.getRight();
      }
    }
    return false;
  }

  public int maximum() {
    BinaryTreeNode current = root;
    while (current.getRight() != null) {
      current = current.getRight();
    }
    return current.getValue();
  }

  public int minimum() {
    BinaryTreeNode current = root;
    while (current.getLeft() != null) {
      current = current.getLeft();
    }
    return current.getValue();
  }

  public void clear() {
    root = null;
  }
}
