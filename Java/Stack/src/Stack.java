public class Stack<T> {
  private Node top;

  public void push(T value) {
    Node node = new Node(value);
    node.next = top; 
    top = node;
  }

  public T pop() {
    Node node = top;
    top = top.next;
    return node.getValue();
  }

  class Node<T> {

    private T value;
    private Node next;

    Node(T value) {
      this.value = value;
      this.next = null;
    }

    T getValue() {
      return value;
    }

    void setValue(T value) {
      this.value = value;
    }

    Node getNext() {
      return next;
    }

    void setNext(Node node) {
      this.next = node;
    }
  }
}
