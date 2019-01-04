/* A DP solution for solving Unbound Knapsack (with replacement allowed) problem */

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int UnboundknapSack(vector<int> wt, vector<int> val, int W) {
    int n = wt.size();
    vector<int> K(W + 1);

    for (int w = 0; w < W + 1; w++) {
        for (int i = 0; i < n; i++) {
            if (w == 0) {
                K[w] = 0;
            }
            else if (wt[i] <= w && !(w - wt[i] > 0 && K[w - wt[i]] == 0)) {
                if (K[w] == 0) {
                    K[w] = val[i] + K[w - wt[i]];
                }
                else {
                    K[w] = max(val[i] + K[w - wt[i]], K[w]);
                }
            }
        }
    }
    return K[W];
}

int main() {
    vector<int> val{ 10, 40, 50, 70 };
    vector<int> wt{ 1, 3, 4, 5 };
    int  W = 8;
    printf("%d", UnboundknapSack(wt, val, W));
    std::cin.ignore();
    return 0;
}