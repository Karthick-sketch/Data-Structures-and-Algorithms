#include <iostream>

using namespace std;

void selectionSort(int arr[], int size) {
	for (int i = 0; i < size-1; i++) {
		int temp = arr[i], index = i;
		// j copy the value of i, because, i's previous position values are sorted
		for (int j = i; j < size; j++) {
			// to find small value in the array
			if (temp > arr[j]) {
				temp = arr[j]; // store the value to temp
				index = j; // store the position number of the value
			}
		}
		arr[index] = arr[i]; // interchange the values
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
