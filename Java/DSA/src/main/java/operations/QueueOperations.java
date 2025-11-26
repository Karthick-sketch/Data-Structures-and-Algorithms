package Java.DSA.src.main.operations;

import Java.DSA.src.main.datastructures.linear.Queue;

public class QueueOperations {

  public static void main(String[] args) {
    Queue<String> queue = new Queue<>();
    queue.enqueue("Hello");
    queue.enqueue("World");
    System.out.println(queue.dequeue());
    System.out.println(queue.dequeue());
  }
}
