#include <iostream>

using namespace std;

void quickSort(int arr[], int start, int end) {
	int left = start, right = end-1;
	if (end-start > 1) {
		int pivot = arr[((rand()%(end-start+1))+start)];
		while (left < right) {
			for (;arr[left] < pivot && left <= right; left++);
			for (;arr[right] > pivot && right > left; right--);
			if (left < right) {
				int temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;
				left++;
			}
		}
		quickSort(arr, start, left);
		quickSort(arr, right, end);
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

	quickSort(arr, 0, size);

	cout << "Sorted array: {";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << (i < size-1 ? ", " : "}\n");
	}

	return 0;
}