void SelectionSort(int arr[], int size) {
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
