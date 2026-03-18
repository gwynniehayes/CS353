#ifndef BUBBLE_SORT
#define BUBBLE_SORT

void bubble_sort(int arr[], int size) {
    for (int step = 0; step < size -1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
}
}

#endif