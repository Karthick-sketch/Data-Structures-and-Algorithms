int linearSearch(int arr[], int size, int search) {
  for (int i = 0; i < size; i++) {
    if (search == arr[i]) {
      return i;
    }
  }
  return -1;
}
