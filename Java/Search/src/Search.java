public class Search {

  public static int linearSearch(int[] array, int search) {
    for (int i = 0; i < array.length; i++) {
      if (array[i] == search) {
        return i;
      }
    }
    return -1;
  }

  public static int binarySearch(int[] array, int search) {
    int l = 0, r = array.length - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (search == array[m]) {
        return m;
      } else if (search < array[m]) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return -1;
  }
}
