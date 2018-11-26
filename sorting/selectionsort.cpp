/* An implementation of Selection sort */

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int min_i = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min_i]) {
                min_i = j;
            }
        }
        // swap
        int tmp = arr[i];
        arr[i] = arr[min_i];
        arr[min_i] = tmp;
    }
}

void printArray(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    vector<int> arr{ 7, 6, 1, 2, 5, 7, 8 };
    selectionSort(arr);
    printArray(arr);
    std::cin.ignore();
    return 0;
}
