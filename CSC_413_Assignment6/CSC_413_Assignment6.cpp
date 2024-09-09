// CSC 413/513
// Camron Hansen
// Assignment #6: Implementation of the Longest Common Subsequence (LCS) Algorithm

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to find the Longest Common Subsequence (LCS) of two sequences
string findLCS(const string& X, const string& Y) {
    // Lengths of sequences X and Y
    int m = X.length();
    int n = Y.length();

    // Create a 2D vector to store the lengths of LCS of subproblems
    vector<vector<int>> LCS_lengths(m + 1, vector<int>(n + 1, 0));

    // Building the LCS_lengths table using dynamic programming
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                LCS_lengths[i][j] = LCS_lengths[i - 1][j - 1] + 1;
            }
            else {
                LCS_lengths[i][j] = max(LCS_lengths[i - 1][j], LCS_lengths[i][j - 1]);
            }
        }
    }

    // Reconstructing the LCS using LCS_lengths table
    string LCS;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            // If current characters in X and Y are equal, it belongs to LCS
            LCS = X[i - 1] + LCS;
            i--;
            j--;
        }
        else if (LCS_lengths[i - 1][j] > LCS_lengths[i][j - 1]) {
            // Move to the cell with greater LCS length
            i--;
        }
        else {
            j--;
        }
    }

    return LCS;
}

int main() {
    // Test Case 1
    string X1 = "ABCBDAB";
    string Y1 = "BDCABA";

    cout << "Test Case 1:" << endl;
    cout << "Sequence X: " << X1 << endl;
    cout << "Sequence Y: " << Y1 << endl;
    cout << "Longest Common Subsequence: " << findLCS(X1, Y1) << endl;
    cout << endl;

    // Test Case 2
    string X2 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    string Y2 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";

    cout << "Test Case 2:" << endl;
    cout << "Sequence X: " << X2 << endl;
    cout << "Sequence Y: " << Y2 << endl;
    cout << "Longest Common Subsequence: " << findLCS(X2, Y2) << endl;

    return 0;
}