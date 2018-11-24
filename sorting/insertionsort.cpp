/* An implementation of insertion sort */

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int saved_i = i;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] > arr[j]) {
                break;
            }
            else {
                int t = arr[j];
                arr[j] = arr[i];
                arr[i] = t;
                i--;
            }
        }
        i = saved_i;
    }
}

void printArray(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    vector<int> arr{ 7, 6, 1, 2, 5, 7, 8 };
    insertionSort(arr);
    printArray(arr);
    std::cin.ignore();
    return 0;
}
