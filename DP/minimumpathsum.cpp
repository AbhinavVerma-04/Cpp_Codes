#include <bits/stdc++.h>
using namespace std;
int recursion(int i, int j, vector<vector<int>>& nums) {
    if (i == 0 && j == 0) {
        return nums[0][0];
    }
    if (i < 0 || j < 0)
        return INT_MAX;
    int up = recursion(i - 1, j, nums);
    int left = recursion(i, j - 1, nums);
    return nums[i][j] + min(up, left);
}
int memoisation(int i, int j, vector<vector<int>>& nums, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) {
        return nums[0][0];
    }
    if (i < 0 || j < 0)
        return INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = recursion(i - 1, j, nums);
    int left = recursion(i, j - 1, nums);
    return dp[i][j] = nums[i][j] + min(up, left);
}
int tabulation(int n, int m, vector<vector<int>>& grid) {
    vector<vector<int>> tab(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                tab[i][j] = grid[i][j];
            else {
                int up = INT_MAX;
                int left = INT_MAX;
                if (i > 0)
                    up = tab[i - 1][j];
                if (j > 0)
                    left = tab[i][j - 1];
                tab[i][j] = grid[i][j] + min(up, left);
            }
        }
    }
    return tab[n - 1][m - 1];
}
int main() {
    vector<vector<int>> nums{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int n = nums.size();
    int m = nums[0].size();
    cout << recursion(n - 1, m - 1, nums) << endl;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << memoisation(n - 1, m - 1, nums, dp) << endl;
    cout << tabulation(n, m, nums) << endl;
}