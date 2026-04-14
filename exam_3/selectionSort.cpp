#include <iostream>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void printArray(const int arr[], int n) {
    if (n == 0) {
        std::cout << "(empty)";
    } else {
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    // Test 1: Empty array
    int arr1[] = {};
    int n1 = 0;
    std::cout << "Test 1 (Empty array): ";
    printArray(arr1, n1);
    selectionSort(arr1, n1);
    printArray(arr1, n1);

    // Test 2: One element
    int arr2[] = {42};
    int n2 = 1;
    std::cout << "\nTest 2 (Single element): ";
    printArray(arr2, n2);
    selectionSort(arr2, n2);
    printArray(arr2, n2);

    // Test 3: Reverse order
    int arr3[] = {9, 7, 5, 3, 1};
    int n3 = 5;
    std::cout << "\nTest 3 (Reverse order): ";
    printArray(arr3, n3);
    selectionSort(arr3, n3);
    printArray(arr3, n3);

    // Test 4: Already sorted
    int arr4[] = {1, 2, 3, 4, 5};
    int n4 = 5;
    std::cout << "\nTest 4 (Already sorted): ";
    printArray(arr4, n4);
    selectionSort(arr4, n4);
    printArray(arr4, n4);

    // Test 5: Long array (>10 items)
    int arr5[] = {12, 4, 55, 23, 8, 16, 42, 3, 19, 27, 1, 10};
    int n5 = 12;
    std::cout << "\nTest 5 (Long array): ";
    printArray(arr5, n5);
    selectionSort(arr5, n5);
    printArray(arr5, n5);

    return 0;
}