// LEETCODE 120
#include <bits/stdc++.h>
using namespace std;
int recursion(int i, int j, vector<vector<int>>& triangle, int n) {
    if (i == n - 1)
        return triangle[i][j];
    int down = recursion(i + 1, j, triangle, n);
    int diagnolDown = recursion(i + 1, j + 1, triangle, n);
    return triangle[i][j] + min(down, diagnolDown);
}
int memoisation(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp) {
    if (i == n - 1)
        return triangle[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = memoisation(i + 1, j, triangle, n, dp);
    int diagDown = memoisation(i + 1, j + 1, triangle, n, dp);
    return dp[i][j] = triangle[i][j] + min(down, diagDown);
}
int tabulation(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp(triangle.back());
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        }
    }
    return dp[0];
}
int main() {
    vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int n = triangle.size();
    cout << recursion(0, 0, triangle, n) << endl;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << memoisation(0, 0, triangle, n, dp) << endl;
    cout << tabulation(triangle) << endl;
}