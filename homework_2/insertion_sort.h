#ifndef INSERTION_SORT
#define INSERTION_SORT

void insertion_sort(int arr[], int size) {
    int i, x, j;
    for (i = 1; i < size; i++) {
        x = arr[i];
        j = i -1;
        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = x;
    }
    return;
}

#endif