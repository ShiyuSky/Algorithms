/* A DP solution for solving LPS problem */

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lps(string s) {
    int n = s.length();
    vector<vector<int>> M(n, vector<int>(n));

    // string with only 1 character is also palindromic
    for (int i = 0; i < n; i++) {
        M[i][i] = 1;
    }

    // solve lps in a bottom-up manner
    for (int j = 1; j < n; j++) {
        for (int i = j - 1; i >= 0; i--) {
            if (s[i] == s[j]) {
                M[i][j] = 2 + M[i + 1][j - 1];
            }
            else {
                M[i][j] = max(M[i + 1][j], M[i][j - 1]);
            }
        }
    }
    return M[0][n-1];
}

int main() {
    string seq("GEEKSFORGEEKS");
    cout << "The length of the LPS is " << lps(seq);
    std::cin.ignore();
    return 0;
}