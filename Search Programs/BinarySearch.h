int BinarySearch(int arr[], int size, int val) {
	bool gotIt = false;
	int mid = 0, low = 0, high = size-1;

	for (int i = 0;i < size && !gotIt;i++) {
		mid = (high-low)/2+low;
		if (val == arr[mid]) gotIt = true;
		else if (val > arr[mid]) low = mid+1;
		else high = mid-1;
	}

	return (gotIt ? mid : -1);
}
