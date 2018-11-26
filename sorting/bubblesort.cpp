/* An implementation of Bubble sort */

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(vector<int>& arr) {
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i + 1] < arr[i]) {
                swap(&arr[i + 1], &arr[i]);
                isSorted = false;
            }
        }
    }
}

void printArray(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    vector<int> arr{ 7, 6, 1, 2, 5, 7, 8 };
    bubbleSort(arr);
    printArray(arr);
    std::cin.ignore();
    return 0;
}
