#include <iostream>
#include "implementation.h"

using namespace std;

void runTest(int arr[], int n, const string& testName) {
    cout << testName << " - Original: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    
    Sort(arr, n);
    
    cout << " | Sorted: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int test1[] = {3, 1, 2, 0, 3, 2, 1, 0};
    runTest(test1, 8, "Test 1: Mixed");

    int test2[] = {0, 0, 1, 1, 2, 2, 3, 3};
    runTest(test2, 8, "Test 2: Already sorted");

    int test3[] = {3, 3, 2, 2, 1, 1, 0, 0};
    runTest(test3, 8, "Test 3: Reverse sorted");

    int test4[] = {0, 0, 0, 0};
    runTest(test4, 4, "Test 4: All zeros");

    int test5[] = {3, 3, 3, 3};
    runTest(test5, 4, "Test 5: All threes");

    int test6[] = {2};
    runTest(test6, 1, "Test 6: Single element");

    int test7[] = {1, 0};
    runTest(test7, 2, "Test 7: Two elements");

    int test8[] = {0, 1, 1, 0, 0, 1};
    runTest(test8, 6, "Test 8: Zeros and ones");

    int test9[] = {3, 2, 3, 2, 2, 3};
    runTest(test9, 6, "Test 9: Twos and threes");

    int test10[] = {};
    runTest(test10, 0, "Test 10: Empty array");

    int test11[] = {3, 0, 2, 1, 3, 1, 0, 2, 0, 1, 3, 2, 0};
    runTest(test11, 13, "Test 11: Random large");

    return 0;
}