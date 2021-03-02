void InsertionSort(int arr[], int size) {
	int temp = 0, cnt = 0;

	bool swap = false,  run = true;
	bool sorted = true;

	for (int i = 0;i < size-1 && sorted;i++) // this for loop checks the arr is already sorted or not
		(arr[i] < arr[i+1]) ? sorted = true : sorted = false;

	if (!sorted) {
		for (int i = 1;i < size;i++) {
			cnt = i;
			temp = arr[i];
			for (int j = i-1;j >= 0 && run;j--) { // this loop find out the number for insert the current value into the array
				if (temp < arr[j]) {
					cnt--;
					swap = true;
				}
				else
					run = false;
			}
			if (swap) { // below code rearrange the array values and insert the current value
				for (int k = i;k > cnt;k--)
					arr[k] = arr[k-1];
				arr[cnt] = temp;
			}
			swap = false;
			run = true;
		}
	}
}