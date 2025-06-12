#include <iostream>
#include <ctime>
#include "BubbleSort.h"
#include "LinearSearch.h"
#include "JumpSearch.h"
#include "BinarySearch.h"

using namespace std;

int main() {
  srand(time(0));

  cout << "1. Insert\n2. Insert random numbers" << endl;
  int ip; cin >> ip;

  cout << "Enter the number of values: ";
  int size; cin >> size;
  int arr[size];
  if (ip == 1) {
    for (int i = 0;i < size;i++) {
      cout << i+1 << ": ";
      cin >> arr[i];
    }
  } else {
    for (int i = 0;i < size;i++)
      arr[i] = rand()%100;
  }

  bubbleSort(arr, size);

  cout << "[";
  for (int i = 0;i < size;i++) {
    cout << arr[i] << (i < size-1 ? ", " : "]\n");
  }

  cout << "Select the number to search: ";
  int num; cin >> num;

  cout << "1. Linear Search\n2. Jump Search\n3. Binary Search" << endl;
  cin >> ip;  int n = -1;
  switch (ip) {
    case 1: n = linearSearch(arr, size, num); break;
    case 2: n = jumpSearch(arr, size, num); break;
    case 3: n = binarySearch(arr, size, num); break;
  }

  cout << (n != -1 ? "Index number: " + to_string(n) : to_string(num) + " is not in the array") << endl;
}
