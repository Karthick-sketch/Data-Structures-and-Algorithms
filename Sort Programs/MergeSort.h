void MergeSort(int arr[], int beg, int mid, int end) {
	int left = mid - beg + 1;
	int right = end - mid;
	int i, j, k = beg;

	int leftArray[left];
	int rightArray[right];

	for (i = 0;i < left;i++)
		leftArray[i] = arr[beg + i];

	for (j = 0;j < right;j++)
		rightArray[j] = arr[mid + 1+ j];

	i = 0;  j = 0;

	while (i < left && j < right) {
		if (leftArray[i] <= rightArray[j]) {
			arr[k] = leftArray[i];
			i++;
		}
		else {
			arr[k] = rightArray[j];
			j++;
		}
		k++;
	}
	while (i < left) {
		arr[k] = leftArray[i];
		i++;	k++;
	}

	while (j < right) {
		arr[k] = rightArray[j];
		j++;	k++;
	}
}

void MergeSort(int arr[], int beg, int end) {
	if (beg < end) {
		int mid = (beg + end)/2;
		MergeSort(arr, beg, mid);
		MergeSort(arr, mid+1, end);
		MergeSort(arr, beg, mid, end);
	}
}
