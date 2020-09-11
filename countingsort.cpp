void counting_sort(int* arr, int size) {
	//int size = sizeof(arr) / sizeof(arr[0]);

	int* arr = new int[size];
	int* arr1 = new int[size];
	int max_element = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i] > max_element) {
			max_element = arr[i];
		}
	}

	int count[max_element + 1];
	for (int i = 0; i <= max_element; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		count[arr[i]]++;
	}

	for (int i = 1; i <= max_element; i++) {
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--) {
		arr1[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	for (int i = 0; i < size; i++) {
		arr[i] = arr1[i];
	}
}