import java.util.Arrays;
import java.util.Random;
import sort.*;

public class SortOperations {

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

  private static void operation(int[] arr) {
    int[] arr2 = Arrays.copyOf(arr, arr.length);
    System.out.println("Unsorted:\t" + Arrays.toString(arr));
    new BubbleSort().sort(arr);
    new SelectionSort().sort(arr2);
    System.out.println("Bubble sort:\t" + Arrays.toString(arr));
    System.out.println("Selection sort:\t" + Arrays.toString(arr2));
  }
}
