#ifndef SELECTION_SORT
#define SELECTION_SORT

int min_index(int arr[], int size) {
	// helper function for sort
	// arguments: (nonempty) array of integers (arr), number of items in array (size)
	// returns: the index of the minimum value in the array

	int i = 0;
	for (int j = 1; j < size; j++){
		if (arr[j] < arr[i])
			i = j;
	}
	return i;
}

void remove_by_index(int arr[], int i, int size) {
	// helper function for sort
	// arguments: array of integers (arr), index (i), and the number of items in array (size)
	// state change: removes the index i item from the array;
	//	index i of the array is replaced with the value from index i+1,
	//	index i+1 of the array is replaced with the value from index i+2,
	//	and so on until we get to the end of the array.
	// returns: none

	for (int index = i+1; index < size; index++)
		arr[index - 1] = arr[index];
	return;
}

void selection_sort(int arr[], int size) {
	// sort function
	// arguments: array of integers (arr), number of items in the array (size)
	// state change: values in arr are sorted to be in ascending order
	// returns: none

	int *temp_arr = new int[size];		//allocate space for temporary array with same size as arr
	int num_left = size;
	int i = 0;
	int index;
	int next_val;
	while (num_left > 0){						//while there are still items in arr to sort
		index = min_index(arr, num_left);		//find the index of the minimum value
		next_val = arr[index];					//store the minimum value
		remove_by_index(arr, index, num_left);	//remove the minimum value
		temp_arr[i] = next_val;					//copy minimum value into next position in temporary array
		i++;
		num_left--;
	}
	for (int j = 0; j < size; j++){		//copy all items from the temporary array back into arr, this time in order.
		arr[j] = temp_arr[j];
	}
	delete [] temp_arr;					//release memory allocated for temporary array
}


#endif