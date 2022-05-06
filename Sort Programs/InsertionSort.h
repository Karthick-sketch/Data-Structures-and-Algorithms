void InsertionSort(int arr[], int size) {
	int temp = 0, cnt = 0;
	bool swap = false, run = true, sorted = true;

	// this for loop checks if the array is already sorted or not
	for (int i = 0;i < size-1 && sorted;i++) {
		if (arr[i] < arr[i+1]) {
			sorted = false;
		}
	}

	if (!sorted) {
		for (int i = 1;i < size;i++) {
			cnt = i; temp = arr[i];
			// this loop find the number for insert the current value into the array
			for (int j = i-1;j >= 0 && run;j--) {
				if (temp < arr[j]) {
					cnt--; swap = true;
				} else run = false;
			}

			// below code rearrange the array values and insert the current value
			if (swap) {
				for (int j = i;j > cnt;j--)
					arr[j] = arr[j-1];
				arr[cnt] = temp;
			}
			swap = false; run = true;
		}
	}
}
