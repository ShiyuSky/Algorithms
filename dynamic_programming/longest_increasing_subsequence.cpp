/* A DP solution for solving LIS problem */

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

int findLIS(vector<int> arr) {
    int n = arr.size();
    vector<int> L(n);

    for (int i = 0; i < n; i++) {
        bool exist = false;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                L[i] = max(1 + L[j], L[i]);
                exist = true;
            }
        }
        if (!exist) {
            L[i] = 1;
        }
        //printArray(L);
    }
    // return last element in L
    return L.back();
}

int main() {
    vector<int> arr{ 7, 6, 1, 31, 102, 2, 5, 7, 8, 10, 20 };
    int ans = findLIS(arr);
    cout << ans << endl;
    std::cin.ignore();
    return 0;
}