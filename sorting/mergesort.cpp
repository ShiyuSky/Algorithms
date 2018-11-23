/* An implementation of mergesort */

#include "stdafx.h"
#include <iostream>

using namespace std;

void merge(int arr[], int l, int mid, int r) {
    // create copies of two sub-arrays
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + j + 1];
    }

    // merge two sorted sub-arrays into arr
    int i = 0, j = 0;
    for (int k = 0; k < n1 + n2; k++) {
        if (i != n1 && (j == n2 || L[i] < R[j])) {
            arr[l + k] = L[i++];
        }
        else {
            arr[l + k] = R[j++];
        }
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 7, 6, 1, 2, 5, 7, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
    std::cin.ignore();
    return 0;
}
