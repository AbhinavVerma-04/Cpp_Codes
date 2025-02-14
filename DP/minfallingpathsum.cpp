// LEETCODE 931
#include <bits/stdc++.h>
using namespace std;
int recursion(int i, int j, vector<vector<int>>& matrix, int n, int m) {
    if (j < 0 || j >= m)
        return INT_MAX;
    if (i == 0)
        return matrix[i][j];
    int up = recursion(i - 1, j, matrix, n, m);
    int upLeft = recursion(i - 1, j - 1, matrix, n, m);
    int upRight = recursion(i - 1, j + 1, matrix, n, m);
    return matrix[i][j] + min(up, min(upLeft, upRight));
}
int memoisation(int i, int j, vector<vector<int>>& matrix, int m, vector<vector<int>>& dp) {
    if (j < 0 || j >= m)
        return INT_MAX;
    if (i == 0)
        return matrix[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = memoisation(i - 1, j, matrix, m, dp);
    int upLeft = memoisation(i - 1, j - 1, matrix, m, dp);
    int upRight = memoisation(i - 1, j + 1, matrix, m, dp);
    return dp[i][j] = matrix[i][j] + min(up, min(upLeft, upRight));
}
int tabulation(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++) {
        dp[0][j] = matrix[0][j];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = dp[i - 1][j];
            int upLeft = INT_MAX;
            if (j > 0)
                upLeft = dp[i - 1][j - 1];
            int upRight = INT_MAX;
            if (j < m - 1)
                upRight = dp[i - 1][j + 1];
            dp[i][j] = matrix[i][j] + min(up, min(upLeft, upRight));
        }
    }
    int minSum = INT_MAX;
    for (int j = 0; j < m; j++) {
        minSum = min(dp[n - 1][j], minSum);
    }
    return minSum;
}
int main() {
    vector<vector<int>> matrix{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    int n = matrix.size();
    int m = matrix[0].size();
    int minSum = INT_MAX;
    for (int j = 0; j < m; j++) {
        minSum = min(minSum, recursion(n - 1, j, matrix, n, m));
    }
    cout << minSum << endl;
    minSum = INT_MAX;
    for (int j = 0; j < m; j++) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        minSum = min(minSum, memoisation(n - 1, j, matrix, m, dp));
    }
    cout << minSum << endl;
    cout << tabulation(matrix) << endl;
}