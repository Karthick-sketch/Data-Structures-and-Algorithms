import binarytree.binarysearchtree.BinarySearchTree;

public class Tree {
  public static void main(String[] args) {
    int[] values = {8, 4, 2, 6, 1, 5, 3, 7, 10, 9, 11};
    BinarySearchTree bst = new BinarySearchTree(values);
    System.out.println(bst.get());
    System.out.println(bst.search(5));
    System.out.println(bst.delete(8));
    System.out.println(bst.get());
    System.out.println(bst.maximum());
    System.out.println(bst.minimum());
    bst.clear();
    System.out.println(bst.get());
  }
}
