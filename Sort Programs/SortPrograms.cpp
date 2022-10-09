#include <iostream>
#include <time.h>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

bool verifySorted(int arr[]) {
	int size = sizeof(arr)/sizeof(int);
	for (int i = 0;i < size-1;i++) {
		if (arr[i] < arr[i+1]) {
			return false;
		}
	}

	return true;
}

int main() {
	srand(time(0));

	cout << "1. Insert\n2. Insert random values" << endl;
	int ip, size; cin >> ip;
	cout << "Enter the number of values: ";
	cin >> size; int arr[size];

	if (ip == 1) {
		for (int i = 0;i < size;i++) {
			cout << i+1 << ": ";
			cin >> arr[i];
		}
	} else {
		for (int i = 0;i < size;i++) {
			arr[i] = rand()%100;
		}
	}

	cout << "[";
	for (int i = 0;i < size;i++) {
		cout << arr[i] << (i < size-1 ? ", " : "]\n\n");
	}

	cout << "1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort" << endl;
	cout << "4. Merge Sort\n5. Quick Sort" << endl;
	cout << "Select the type to sort the array: ";

	cin >> ip;
	if (!verifySorted(arr)) {
		switch(ip) {
			case 1: BubbleSort(arr, size); break;
			case 2: SelectionSort(arr, size); break;
			case 3: InsertionSort(arr, size); break;
			case 4: MergeSort(arr, 0, size-1); break;
			case 5: QuickSort(arr, 0, size); break;
		}
	}

	cout << "Sorted List: [";
	for (int i = 0;i < size;i++) {
		cout << arr[i] << (i < size-1 ? ", " : "]\n");
	}
}
