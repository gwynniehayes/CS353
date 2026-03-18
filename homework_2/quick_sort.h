#ifndef QUICK_SORT
#define QUICK_SORT

#include <algorithm> 

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort_helper(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);

        quick_sort_helper(arr, low, pivot_index - 1);
        quick_sort_helper(arr, pivot_index + 1, high);
    }
}

void quick_sort(int arr[], int size) {
    if (size > 1) {
        quick_sort_helper(arr, 0, size - 1);
    }
}

#endif 