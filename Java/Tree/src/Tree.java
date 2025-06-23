import binarytree.binarysearchtree.BinarySearchTree;

public class Tree {
  public static void main(String[] args) {
    int[] values = {4, 2, 1, 3, 6, 5, 7};
    BinarySearchTree bst = new BinarySearchTree(values);
    System.out.println(bst.get());
    System.out.println(bst.search(5));
  }
}
