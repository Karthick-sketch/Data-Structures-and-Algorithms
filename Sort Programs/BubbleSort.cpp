#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size) {
  bool sorted = false;
  for (int i = 0; i < size && !sorted; i++) {
    sorted = true;
    for (int j = 0; j < size-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        sorted = false;
      }
    }
    // if the sorted variable is still true after the end of 2nd for loop, 1st for loop will terminate
    // because there is no value to swap. arr is sorted
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

  bubbleSort(arr, size);

  cout << "Sorted array: {";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << (i < size-1 ? ", " : "}\n");
  }

  return 0;
}
