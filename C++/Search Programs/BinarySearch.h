int binarySearch(int arr[], int size, int value) {
  int mid = 0, low = 0, high = size-1;
  for (int i = 0; i < size; i++) {
    mid = (high-low)/2 + low;
    if (value == arr[mid]) {
      return mid;
    } else if (value > arr[mid]) {
      low = mid+1;
    } else {
      high = mid-1;
    }
  }
  return -1;
}
