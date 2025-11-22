public class StackOperations {

  public static void main(String[] args) {
    Stack<String> stack = new Stack<>();
    stack.push("Hello");
    stack.push("World");
    System.out.println(stack.pop());
    System.out.println(stack.pop());
  }
}
