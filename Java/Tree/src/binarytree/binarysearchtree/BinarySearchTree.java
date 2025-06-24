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
      BinaryTreeNode temp = root;
      while (true) {
        if (value < temp.getValue()) {
          if (temp.getLeft() == null) {
            temp.setLeft(node);
            break;
          }
          temp = temp.getLeft();
        } else if (value > temp.getValue()) {
          if (temp.getRight() == null) {
            temp.setRight(node);
            break;
          }
          temp = temp.getRight();
        } else {
          break;
        }
      }
    }
  }

  public boolean search(int value) {
    BinaryTreeNode temp = root;
    while (temp != null) {
      if (value == temp.getValue()) {
        return true;
      } else if (value < temp.getValue()) {
        temp = temp.getLeft();
      } else {
        temp = temp.getRight();
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

  private void inorder(BinaryTreeNode temp, List<Integer> list) {
    if (temp.getLeft() != null) {
      inorder(temp.getLeft(), list);
    }
    list.add(temp.getValue());
    if (temp.getRight() != null) {
      inorder(temp.getRight(), list);
    }
  }

  public boolean delete(int value) {
    BinaryTreeNode current = root, previous = root;
    while (current != null) {
      if (value < current.getValue()) {
        previous = current;
        current = current.getLeft();
      } else if (value > current.getValue()) {
        previous = current;
        current = current.getRight();
      } else {
        if (current.getLeft() != null && current.getRight() != null) {
          BinaryTreeNode temp1 = current.getLeft(), temp2 = null;
          while (temp1.getRight() != null) {
            temp2 = temp1;
            temp1 = temp1.getRight();
          }
          current.setValue(temp1.getValue());
          if (temp2 == null) {
            current.setLeft(null);
          } else {
            temp2.setRight(null);
          }
        } else {
          BinaryTreeNode temp = null;
          if (current.getLeft() != null) {
            temp = current.getLeft();
          } else if (current.getRight() != null) {
            temp = current.getRight();
          }
          if (current == root) {
            root = temp;
          } else if (current == previous.getLeft()) {
            previous.setLeft(temp);
          } else {
            previous.setRight(temp);
          }
        }
        return true;
      }
    }
    return false;
  }
}
