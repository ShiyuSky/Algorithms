/* An implementation of radix sort */

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void countingSort(vector<int>& arr, int e) {
    // final sorted array
    vector<int> res(arr.size());

    // construct counting array
    vector<int> carr(10);
    for (int i = 0; i < arr.size(); i++) {
        carr[(arr[i] / e) % 10]++;
    }

    // transform carr s.t. carr[i] refers to i's exact index in the sorted array
    for (int i = 1; i < carr.size(); i++) {
        carr[i] += carr[i - 1];
    }

    // iterate through arr backwards to achieve stableness
    for (int i = arr.size() - 1; i >= 0; i--) {
        res[--carr[(arr[i] / e) % 10]] = arr[i];
    }
    arr = res;
}

void radixSort(vector<int>& arr) {
    typedef vector<int>::iterator Iterator;
    Iterator k = max_element(arr.begin(), arr.end());
    int m = *k;

    for (int e = 1; m / e > 0; e *= 10) {
        countingSort(arr, e);
    }
}

int main() {
    vector<int> arr{ 7, 6, 1,  31, 102, 2, 5, 7, 8, 10, 20};
    radixSort(arr);
    printArray(arr);
    std::cin.ignore();
    return 0;
}
