void SelectionSort(int arr[], int size) {
	bool sorted = true;
	// this for loop checks if the array is already sorted or not
	for (int i = 0;i < size-1 && sorted;i++) {
		if (arr[i] < arr[i+1]) {
			sorted = false;
		}
	}

	if (!sorted) {
		for (int i = 0;i < size-1;i++) {
			int temp = arr[i], indx = i;
			// j copy the value of i, because, i's previous position values are sorted
			for (int j = i;j < size;j++) {
				// to find small value in the array
				if (temp > arr[j]) {
					temp = arr[j]; // store the value to temp
					indx = j; // store the position number of the value
				}
			}
			arr[indx] = arr[i]; // interchange the values
			arr[i] = temp;
		}
	}
}
