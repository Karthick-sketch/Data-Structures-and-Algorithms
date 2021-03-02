#include <math.h>

int JumpSearch(int arr[], int size, int val) {
	int jump = int(sqrt(size)), num = 0;
	bool run = true;

	while (run) {
		if (val == arr[num])
			run = false;
		else if (val < arr[num]) {
			int index = num-jump;
			while (index < num && run) {
				if (val == arr[index]) {
					num = index;
					run = false;
				}
				index += 1;
			}
			if (run) {
				num = -1;
				run = false;
			}
		}
		else if (val > arr[num] && num < size-1) {
			num += jump;
			if (num >= size)
				num = size-1;
		}
		else {
			if (val > arr[-1])
				num = -1;
			run = false;
		}
	}

	return num;
}
