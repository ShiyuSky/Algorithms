/* An implementation of counting sort */

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> countingSort(vector<int>& arr) {
    typedef vector<int>::iterator Iterator;
    // final sorted array
    vector<int> res(arr.size());

    // construct counting array
    Iterator k = max_element(arr.begin(), arr.end());
    vector<int> carr(*k + 1);
    for (int i = 0; i < arr.size(); i++) {
        carr[arr[i]]++;
    }
    
    // transform carr s.t. carr[i] refers to i's exact index in the sorted array
    for (int i = 1; i < carr.size(); i++) {
        carr[i] += carr[i - 1];
    }

    // iterate through arr backwards to achieve stableness
    for (int i = arr.size() - 1; i >= 0; i--) {
        res[--carr[arr[i]]] = arr[i];
    }
    return res;
}

void printArray(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    vector<int> arr{ 7, 6, 1, 2, 5, 7, 8 };
    vector<int> sortedArr = countingSort(arr);
    printArray(sortedArr);
    std::cin.ignore();
    return 0;
}
