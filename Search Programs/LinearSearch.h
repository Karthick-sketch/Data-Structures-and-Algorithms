int LinearSearch(int arr[], int size, int val) {
	bool isThere = false;
	int indx = 0;
		
	for (;indx < size && !isThere;indx++) {
		if (val == arr[indx])
			isThere = true;
	}
	if (isThere)
		return indx-1;
	else
		return -1;
}