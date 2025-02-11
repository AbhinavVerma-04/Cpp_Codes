#include <bits/stdc++.h>
using namespace std;
int recursion(int i, int j, vector<vector<int>>& nums) {
    if (i >= 0 && j >= 0 && nums[i][j] == 1)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    int up = recursion(i - 1, j, nums);
    int left = recursion(i, j - 1, nums);
    return up + left;
}
int memoisation(int i, int j, vector<vector<int>>& nums, vector<vector<int>>& dp) {
    if (i >= 0 && j >= 0 && nums[i][j] == 1)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = memoisation(i - 1, j, nums, dp);
    int left = memoisation(i, j - 1, nums, dp);
    return dp[i][j] = up + left;
}
int tabulation(int n, int m, vector<vector<int>>& nums) {
    vector<vector<int>> tab(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (nums[i][j] == 1)
                tab[i][j] = 0;
            else if (i == 0 && j == 0)
                tab[i][j] = 1;
            else {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = tab[i - 1][j];
                if (j > 0)
                    left = tab[i][j - 1];
                tab[i][j] = up + left;
            }
        }
    }
    return tab[n - 1][m - 1];
}
int main() {
    vector<vector<int>> nums{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int n = nums.size();
    int m = nums[0].size();
    cout << recursion(n - 1, m - 1, nums) << endl;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << memoisation(n - 1, m - 1, nums, dp) << endl;
    cout << tabulation(n, m, nums);
}