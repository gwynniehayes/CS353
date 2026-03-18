#ifndef MERGE_SORT
#define MERGE_SORT

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* Left = new int[n1];
    int* Right = new int[n2];

    for (int i = 0; i < n1; i++)
        Left[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            arr[k++] = Left[i++];
        } else {
            arr[k++] = Right[j++];
        }
    }

    while (i < n1) {
        arr[k++] = Left[i++];
    }

    while (j < n2) {
        arr[k++] = Right[j++];
    }

    delete[] Left;
    delete[] Right;
}

void merge_sort_helper(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    merge_sort_helper(arr, left, mid);
    merge_sort_helper(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void merge_sort(int arr[], int size) {
    if (size <= 1)
        return;

    merge_sort_helper(arr, 0, size - 1);
}

#endif