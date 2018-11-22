/*
An implementation of Quicksort
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

/* utility function for swapping ints in array */
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/*
Purpose:
    This function takes the last int in arr as pivot, and returns an array
    with all ints smaller than pivot to the left, and all ints larger than
    pivot to the right.
    Note that the function only performs operation on arr[low] to arr[high]
*/
int partition(int arr[], int low, int high) {
    // choose the last int as pivot
    int pivot = arr[high];

    // keep track of the index i which satisfies arr[x] < pivot for all x <= i
    int i = low - 1;

    // move all ints smaller than pivot to the left
    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // place pivot at index i+1 s.t. all ints to the left are smaller and
    // all ints to the right are larger
    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 7, 6, 1, 2, 5, 7, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    printArray(arr, n);
    std::cin.ignore();
    return 0;
}
