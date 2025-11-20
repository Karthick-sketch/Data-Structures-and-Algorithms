int binarySearch(int arr[], int size, int value) {
  int mid = 0, low = 0, high = size - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (value == arr[mid]) {
      return mid;
    } else if (value < arr[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}
