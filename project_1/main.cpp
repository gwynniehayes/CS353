#include <iostream>
#include "implementation.h"

using namespace std;

int main() {
    int arr[] = {3, 1, 2, 0, 3, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    Sort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}