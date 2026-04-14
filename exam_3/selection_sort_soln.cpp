#include <iostream>

void selectionSort(int arr[], int n) {
    int min_index;
    int temp;
    for (int i = 0; i < n; i++) {
        min_index = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
    return;
    
}

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {    
    int* arr0 = nullptr;
    printArray(arr0, 0);
    selectionSort(arr0, 0);
    printArray(arr0, 0);
    
    int arr1[] = {5};
    printArray(arr1, 1);
    selectionSort(arr1, 1);
    printArray(arr1, 1);
    
    int arr2[] = {50, 40, 30, 20, 10, 0};
    printArray(arr2, 5);
    selectionSort(arr2, 5);
    printArray(arr2, 5);
    
    int arr3[] = {7, 2, 9, 1, 5, 10, 3, 8, 4, 6};
    printArray(arr3, 10);
    selectionSort(arr3, 10);
    printArray(arr3, 10);
    
    int arr4[] = {58, 12, 91, 3, 44, 76, 21, 88, 35, 62, 9, 70, 19, 53, 81, 28, 47, 95, 30, 66};
    printArray(arr4, 20);
    selectionSort(arr4, 20);
    printArray(arr4, 20);

    int arr5[] = {53, 12, 88, 5, 91, 34, 76, 21, 67, 42, 9, 83, 17, 55, 99, 30, 61, 8, 47, 72};
    printArray(arr5, 20);
    selectionSort(arr5, 20);
    printArray(arr5, 20);

    return 0;
}








