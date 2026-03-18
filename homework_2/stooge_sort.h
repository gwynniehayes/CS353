#ifndef STOOGE_SORT
#define STOOGE_SORT

#include <algorithm>  

static void stooge_sort_helper(int arr[], int start, int stop) {
    if (stop <= start) {
        return;
    }

    if (arr[start] > arr[stop]) {
        std::swap(arr[start], arr[stop]);
    }

    if (stop - start == 1) {
        return;
    }

    int one_third = (int)(start + (stop - start + 1) / 3);
    int two_thirds = (int)(stop - (stop - start + 1) / 3);

    stooge_sort_helper(arr, start, two_thirds);
    stooge_sort_helper(arr, one_third, stop);
    stooge_sort_helper(arr, start, two_thirds);
}


void stooge_sort(int arr[], int n) {
    if (n > 0) {
        stooge_sort_helper(arr, 0, n - 1);
    }
}

#endif