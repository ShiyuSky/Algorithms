/* A DP solution for solving LCS problem */

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(vector<vector<int>> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int findLCS(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> L(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = (s1[i] == s2[j]) ? 1 : 0;
            }
            else if (s1[i] == s2[j]) {
                L[i][j] = 1 + L[i - 1][j - 1];
            }
            else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
        //cout << "L" << endl;
        //printArray(L);
    }
    // return last element in L
    return L[m - 1][n - 1];
}

int main() {
    string s1("AGGTAB");
    string s2("GXTXAYB");
    int ans = findLCS(s1, s2);
    cout << ans << endl;
    std::cin.ignore();
    return 0;
}