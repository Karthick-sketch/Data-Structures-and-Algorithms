void BubbleSort(int arr[], int size) {
	bool sorted = false;
	for (int i = 0;i < size && !sorted;i++) {
		sorted = true;
		for (int j = 0;j < size-i-1;j++) {
			if (arr[j]>arr[j+1]) { // if this condition is true, arr[j] and arr[j+1] both are swap together
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				sorted = false;
			}
		}
		// if sorted variable is till true after the 2nd for loop, 1st for loop will terminate
		// because there is no value to swap. arr is sorted
	}
}
