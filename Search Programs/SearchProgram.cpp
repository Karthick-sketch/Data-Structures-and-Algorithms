#include <iostream>
#include <ctime>
#include "BubbleSort.h"
#include "LinearSearch.h"
#include "JumpSearch.h"
#include "BinarySearch.h"

using namespace std;

int main() {
	srand(time(0));
	int ip, num, size;
	cout << "1. Insert\n2. Insert random numbers" << endl;
	cin >> ip;
	cout << "Enter the number of values: ";
	cin >> size;
	int arr[size];
	if (ip == 1) {
		for (int i = 0;i < size;i++) {
			cout << i+1 << ": ";
			cin >> arr[i];
		}
	}
	else {
		for (int i = 0;i < size;i++)
			arr[i] = rand()%100;
	}

	BubbleSort(arr, size);

	cout << "[";
	for (int i = 0;i < size;i++) {
		cout << arr[i];
		(i < size-1) ? cout << ", " : cout << "]\n";
	}

	cout << "Select the number to search: " << endl;
	cin >> num;
	cout << "1. Linear Search\n2. Jump Search\n3. Binary Search" << endl;
	cin >> ip;  int n = -1;
	if (ip == 1)
		n = LinearSearch(arr, size, num);
	else if (ip == 2)
		n = JumpSearch(arr, size, num);
	else if (ip == 3)
		n = BinarySearch(arr, size, num);
  
	if (n != -1)
		cout << "Index number: " << n << endl;
	else
		cout << num << " is not in the array" << endl;
}
