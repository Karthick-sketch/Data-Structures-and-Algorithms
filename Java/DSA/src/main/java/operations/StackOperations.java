package Java.DSA.src.main.operations;

import Java.DSA.src.main.datastructures.linear.Stack;

public class StackOperations {

  public static void main(String[] args) {
    Stack<String> stack = new Stack<>();
    stack.push("Hello");
    stack.push("World");
    System.out.println(stack.pop());
    System.out.println(stack.pop());
  }
}
