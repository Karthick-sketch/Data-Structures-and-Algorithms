void MergeSort(int arr[], int beg, int mid, int end) {
	int left = mid-beg+1;
	int right = end-mid;
	int i, j, k = beg;

	int leftArray[left], rightArray[right];

	for (i = 0;i < left;i++) {
		leftArray[i] = arr[beg+i];
	}

	for (j = 0;j < right;j++) {
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

void MergeSort(int arr[], int beg, int end) {
	if (beg < end) {
		int mid = (beg + end)/2;
		MergeSort(arr, beg, mid);
		MergeSort(arr, mid+1, end);
		MergeSort(arr, beg, mid, end);
	}
}
