int LinearSearch(int arr[], int size, int val) {
	bool isThere = false;
	int indx = 0;
		
	for (;indx < size && !isThere;indx++) {
		if (val == arr[indx])
			isThere = true;
	}

	return (isThere ? indx-1 : -1);
}
