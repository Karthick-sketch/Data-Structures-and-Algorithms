package sort;

public class BubbleSort implements Sort {

  @Override
  public void sort(int[] arr) {
    for (int i = 1; i < arr.length; i++) {
      for (int j = 0; j < arr.length - i; j++) {
        if (arr[j] > arr[j + 1]) {
          int v = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = v;
        }
      }
    }
  }
}
