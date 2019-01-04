/* A DP solution for solving 0-1 Knapsack problem */

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<vector<int>> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(vector<int> wt, vector<int> val, int W) {
    int n = wt.size();
    vector<vector<int>> K(n+1, vector<int>(W+1));

    for (int i = 0; i < n+1; i++) {
        for (int w = 0; w < W+1; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            }
            else if (wt[i-1] <= w) {
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            }
            else {
                K[i][w] = K[i-1][w];
            }
        }
    }
    // printArray(K);
    return K[n][W];
}

int main() {
    vector<int> val {60, 100, 120};
    vector<int> wt  {10, 20, 30};
    int  W = 50;
    printf("%d", knapSack(wt, val, W));
    std::cin.ignore();
    return 0;
}