#include <iostream>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Test 1: Empty array
    int arr1[] = {};
    int n1 = 0;
    bubbleSort(arr1, n1);
    std::cout << "Empty array: ";
    printArray(arr1, n1);

    // Test 2: One item
    int arr2[] = {5};
    int n2 = 1;
    bubbleSort(arr2, n2);
    std::cout << "Single element: ";
    printArray(arr2, n2);

    // Test 3: Reverse order
    int arr3[] = {9, 7, 5, 3, 1};
    int n3 = 5;
    bubbleSort(arr3, n3);
    std::cout << "Reverse order: ";
    printArray(arr3, n3);

    // Test 4: Long array (>10 items)
    int arr4[] = {12, 4, 7, 3, 15, 8, 2, 10, 6, 1, 9, 5, 11};
    int n4 = 13;
    bubbleSort(arr4, n4);
    std::cout << "Long array: ";
    printArray(arr4, n4);

    // Test 5: Already sorted array
    int arr5[] = {1, 2, 3, 4, 5};
    int n5 = 5;
    bubbleSort(arr5, n5);
    std::cout << "Already sorted: ";
    printArray(arr5, n5);

    return 0;
}