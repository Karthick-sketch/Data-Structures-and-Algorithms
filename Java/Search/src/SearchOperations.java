import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.Scanner;
import java.util.stream.Collectors;

public class SearchOperations {

  public static void main(String[] args) {
    operation(randomize(10));
  }

  private static int[] randomize(int length) {
    Random random = new Random();
    int[] arr = new int[length];
    for (int i = 0; i < length; i++) {
      arr[i] = random.nextInt(100);
    }
    return arr;
  }

  private static void operation(int[] arr1) {
    Scanner scanner = new Scanner(System.in);
    int index;
    System.out.print("1. Linear Search\n2. Binary Search\n> ");
    switch (scanner.nextInt()) {
      case 1:
        System.out.print("Elements: " + Arrays.toString(arr1) + "\n> ");
        index = Search.linearSearch(arr1, scanner.nextInt());
        System.out.println(index == -1 ? "Not found" : "Index: " + index);
        break;
      case 2:
        List<Integer> list = Arrays.stream(arr1)
          .boxed()
          .collect(Collectors.toList());
        Collections.sort(list);
        int[] arr2 = list.stream().mapToInt(Integer::intValue).toArray();
        System.out.print("Elements: " + Arrays.toString(arr2) + "\n> ");
        index = Search.binarySearch(arr2, scanner.nextInt());
        System.out.println(index == -1 ? "Not found" : "Index: " + index);
        break;
      default:
        operation(arr1);
    }
    scanner.close();
  }
}
