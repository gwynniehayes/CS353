#include <iostream>

void bubbleSort(int arr[], int n) {
    // input: array of integers, arr, and its size (int) n
    // state change: sorts array to be in increasing order
    
    int num_swaps = 1;
    int temp;
    while (num_swaps > 0) {
        // repeat until there were no swaps in previous iteration, which means array is in order
        num_swaps = 0;
        for (int i = 0; i < n-1; i++) {
            if (arr[i+1] < arr[i]) {
                // if consecutive items are out of order, swap them
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                num_swaps++;
            }
        }
    }
    return;
}

void printArray(const int arr[], int n) {
    // use this function to print an array
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // TO DO: test your implementation of bubbleSort here
    
    // bad instructions - can't have an empty C-style array, which is what we are using here
    
    int arr1[] = {5};
    printArray(arr1, 1);
    bubbleSort(arr1, 1);
    printArray(arr1, 1);
    
    int arr2[] = {50, 40, 30, 20, 10, 0};
    printArray(arr2, 5);
    bubbleSort(arr2, 5);
    printArray(arr2, 5);
    
    int arr3[] = {7, 2, 9, 1, 5, 10, 3, 8, 4, 6};
    printArray(arr3, 10);
    bubbleSort(arr3, 10);
    printArray(arr3, 10);
    
    int arr4[] = {58, 12, 91, 3, 44, 76, 21, 88, 35, 62, 9, 70, 19, 53, 81, 28, 47, 95, 30, 66};
    printArray(arr4, 20);
    bubbleSort(arr4, 20);
    printArray(arr4, 20);

    int arr5[] = {53, 12, 88, 5, 91, 34, 76, 21, 67, 42, 9, 83, 17, 55, 99, 30, 61, 8, 47, 72};
    printArray(arr5, 20);
    bubbleSort(arr5, 20);
    printArray(arr5, 20);

    return 0;
}








