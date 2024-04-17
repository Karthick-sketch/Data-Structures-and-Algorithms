#include <iostream>

using namespace std;

void mergeSort(int arr[], int beg, int mid, int end) {
	int left = mid-beg+1;
	int right = end-mid;
	int i = 0, j = 0, k = beg;

	int leftArray[left], rightArray[right];

	for (; i < left; i++) {
		leftArray[i] = arr[beg+i];
	}

	for (; j < right; j++) {
		rightArray[j] = arr[mid+1+j];
	}

	i = j = 0;
	while (i < left && j < right) {
		arr[k++] = (leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++]);
	}

	while (i < left) {
		arr[k++] = leftArray[i++];
	}

	while (j < right) {
		arr[k++] = rightArray[j++];
	}
}

void mergeSort(int arr[], int beg, int end) {
	if (beg < end) {
		int mid = (beg + end) / 2;
		mergeSort(arr, beg, mid);
		mergeSort(arr, mid+1, end);
		mergeSort(arr, beg, mid, end);
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

	mergeSort(arr, 0, size-1);

	cout << "Sorted array: {";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << (i < size-1 ? ", " : "}\n");
	}

	return 0;
}