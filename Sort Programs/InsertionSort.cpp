#include <iostream>

using namespace std;

void insertionSort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    int temp = arr[i];
    int j = i - 1;
    for (; j >= 0 && arr[j] > temp; j--) {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = temp;
  }
}

int main() {
  srand(time(0));

  cout << "1. Insert\n2. Insert random values" << endl;
  int ip; cin >> ip;

  cout << "Enter the number of values: ";
  int size; cin >> size;
  int arr[size];

  if (ip == 1) {
    for (int i = 0; i < size; i++) {
      cout << i+1 << ": ";
      cin >> arr[i];
    }
  } else {
    for (int i = 0; i < size; i++) {
      arr[i] = rand()%100;
    }
  }

  cout << "Unsorted array : {";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << (i < size-1 ? ", " : "}\n");
  }

  insertionSort(arr, size);

  cout << "Sorted array: {";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << (i < size-1 ? ", " : "}\n");
  }

  return 0;
}
