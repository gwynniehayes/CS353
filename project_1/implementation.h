#ifndef IMPLEMENTATION
#define IMPLEMENTATION

inline void Sort(int arr[], int n) {
    int* group0 = new int[n];
    int* group1 = new int[n];
    int* group2 = new int[n];
    int* group3 = new int[n];
    int c0 = 0, c1 = 0, c2 = 0, c3 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) group0[c0++] = 0;
        else if (arr[i] == 1) group1[c1++] = 1;
        else if (arr[i] == 2) group2[c2++] = 2;
        else group3[c3++] = 3;
    }

    int index = 0;
    for (int i = 0; i < c0; i++) arr[index++] = group0[i];
    for (int i = 0; i < c1; i++) arr[index++] = group1[i];
    for (int i = 0; i < c2; i++) arr[index++] = group2[i];
    for (int i = 0; i < c3; i++) arr[index++] = group3[i];

    delete[] group0;
    delete[] group1;
    delete[] group2;
    delete[] group3;
}

#endif