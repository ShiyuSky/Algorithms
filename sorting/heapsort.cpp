/* An implementation of heap sort */

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;


void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(vector<int>& arr, int n, int root) {
    int largest = root;
    int l = 2 * (root + 1) - 1;
    int r = 2 * (root + 1);

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    // recursively heapify on sub-tree
    if (largest != root) {
        swap(&arr[root], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    // build heap O(n)
    for (int i = n/2-1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // extract max O(nlogn)
    for (int i = n-1; i >= 0; i--) {
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
    }
}

void printArray(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    vector<int> arr{ 7, 6, 1, 2, 5, 7, 8 };
    heapSort(arr);
    printArray(arr);
    std::cin.ignore();
    return 0;
}