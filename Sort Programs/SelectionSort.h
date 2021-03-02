void SelectionSort(int arr[], int size) {
	bool sorted = true;
	for (int i = 0;i < size-1 && sorted;i++) // this for loop checks the arr is already sorted or not
		(arr[i] < arr[i+1]) ? sorted = true : sorted = false;

	if (!sorted) {
		for (int i = 0;i < size-1;i++) {
			int temp = arr[i], indx = i;
			for (int j = i;j < size;j++) {
			// i is assigned to j. because, i's previous position values are sorted
				if (temp > arr[j]) { // to find small value in the array
					temp = arr[j]; // then assign the value to temp
					indx = j; // and assign the position number of the value
				}
			}
			arr[indx] = arr[i]; // interchanging the values
			arr[i] = temp;
		}
	}
}