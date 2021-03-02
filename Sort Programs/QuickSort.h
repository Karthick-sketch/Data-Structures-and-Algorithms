void QuickSort(int arr[], int start, int end) {
	int left = start, right = end - 1;
	if (end-start > 1) {
		int pivot = arr[((rand()%(end-start+1))+start)];
		while (left < right) {
			while (arr[left] < pivot && left <= right)
				left++;
			while (arr[right] > pivot && right > left)
				right--;
			if (left < right) {
				int temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;
				left++;
			}
		}
		QuickSort(arr, start, left);
		QuickSort(arr, right, end);
	}
}
