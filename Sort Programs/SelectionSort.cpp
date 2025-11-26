#include <iostream>

using namespace std;

void selectionSort(int arr[], int size) {
  for (int i = 0; i < size-1; i++) {
    int min = i;
    // 'j' copies the next value of 'i' because until 'i', the values are sorted
    for (int j = i + 1; j < size; j++) {
      // to find the smalest value in the unsorted region
      if (arr[min] > arr[j]) {
        min = j; // store the value's index number
      }
    }
    // swap the smallest value
    int temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
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

  selectionSort(arr, size);

  cout << "Sorted array: {";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << (i < size-1 ? ", " : "}\n");
  }

  return 0;
}
