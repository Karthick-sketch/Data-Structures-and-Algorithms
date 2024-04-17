#include <iostream>

using namespace std;

void insertionSort(int arr[], int size) {
	int current = 0, temp = 0;
	bool swap = false;
	for (int i = 1; i < size; i++) {
		current = i;
		temp = arr[i];
		// this loop find the eligible number for inserting the current value into the array
		for (int j = i-1; j >= 0; j--) {
			if (temp < arr[j]) {
				current--;
				swap = true;
			} else {
				break;
			}
		}

		// below code rearrange the array and insert the current value to it
		if (swap) {
			for (int j = i; j > current; j--) {
				arr[j] = arr[j-1];
			}
			arr[current] = temp;
		}
		swap = false;
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
