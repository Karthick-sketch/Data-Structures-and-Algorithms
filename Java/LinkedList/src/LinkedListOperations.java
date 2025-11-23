package Java.LinkedList.src;

public class LinkedListOperations {

  public static void main(String[] args) {
    LinkedList<Integer> linkedList = new SinglyLinkedList<>();
    linkedList.add(5);
    System.out.println(linkedList.get(0));
    linkedList.add(10);
    System.out.println(linkedList);
    linkedList.insert(7, 1);
    linkedList.insert(8, 2);
    System.out.println(linkedList);
    linkedList.update(6, 1);
    System.out.println(linkedList);
    linkedList.delete(2);
    System.out.println(linkedList);
    System.out.println(linkedList.size());
  }
}
