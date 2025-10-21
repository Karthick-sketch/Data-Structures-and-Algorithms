public class Sort {

  public static void bubbleSort(int[] arr) {
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

  public static void selectionSort(int[] arr) {
    for (int i = 0; i < arr.length - 1; i++) {
      int min = i;
      for (int j = i + 1; j < arr.length; j++) {
        if (arr[j] < arr[min]) {
          min = j;
        }
      }
      int temp = arr[min];
      arr[min] = arr[i];
      arr[i] = temp;
    }
  }

  public static void insertionSort(int[] arr) {
    for (int i = 1; i < arr.length; i++) {
      int temp = arr[i];
      int j = i - 1;
      for (; j >= 0 && arr[j] > temp; j--) {
        arr[j + 1] = arr[j];
      }
      arr[j + 1] = temp;
    }
  }
}
